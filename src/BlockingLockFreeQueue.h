#pragma once

#include "MSignal.h"
#include <boost/lockfree/queue.hpp>
#include <thread>

/**
 * @brief 블로킹 락프리 큐 클래스
 * 
 * 두 가지 대기 방식을 지원하는 스레드 안전한 락프리 큐입니다:
 * - SIGNALED = true  : C++ 시그널 기반 대기 (대기 시 CPU 점유율 0, 처리속도 느림)
 * - SIGNALED = false : 락프리 큐의 스핀 기반 대기 (대기 시 CPU 점유율 ~10%, 처리속도 빠름)
 * 
 * @tparam SIGNALED 시그널 기반 대기 사용 여부
 * @tparam T 저장할 데이터 타입
 * @tparam Options boost::lockfree::queue에 전달할 추가 옵션들
 */
template<bool SIGNALED, typename T, typename... Options>
class BlockingLockFreeQueue
{
public:
  /**
   * @brief 생성자
   * @param capacity 큐의 최대 용량 (기본값: 10000)
   * @param open 초기 열림 상태 (기본값: true)
   */
  BlockingLockFreeQueue(const size_t &capacity = 10000, const bool &open = true)
  : queue_(capacity), open_(open) {}

  /**
   * @brief 소멸자
   */
  ~BlockingLockFreeQueue() {}

  /**
   * @brief 시그널 기반 대기 모드 사용 여부 확인
   * @return 시그널 기반이면 true, 스핀 기반이면 false
   */
  bool is_signaled() const { return SIGNALED; }

  /**
   * @brief 큐를 열어서 작업 가능하게 함
   */
  void open()
  {
    open_ = true;
  }

  /**
   * @brief 큐를 닫아서 더 이상의 작업을 차단
   * 
   * 시그널 기반 모드에서는 대기 중인 스레드에게 알림을 보냅니다.
   */
  void close()
  {
    open_ = false;
    if (SIGNALED == true)
      signal_.notify_one();
  }

  /**
   * @brief 아이템을 큐에 추가
   * 
   * @param item 추가할 아이템
   * @return 성공시 0, 큐가 닫혔으면 -1, 큐가 가득 찼으면 EAGAIN
   */
  int push(const T &item)
  {
    if (open_.load() == false)
      return -1;

    if (queue_.push(item) == false)
      return EAGAIN;

    if (SIGNALED == true)
      if (queue_.empty() == false)
        signal_.notify_one();

    return 0;
  }

  /**
   * @brief 백오프 전략을 사용하여 아이템을 큐에 추가
   * 
   * 큐가 가득 찼을 경우 지정된 시간만큼 대기한 후 재시도합니다.
   * 최대 재시도 횟수를 초과하면 EAGAIN을 반환합니다.
   * 
   * @tparam DURATION_TYPE 대기 시간의 타입 (기본값: std::chrono::nanoseconds)
   * @param item 추가할 아이템
   * @param sleep 재시도 간 대기 시간 (기본값: 10 나노초)
   * @param max_retries 최대 재시도 횟수 (0은 무제한 재시도)
   * @return 성공시 0, 큐가 닫혔으면 -1, 최대 재시도 초과시 EAGAIN
   */
  template<typename DURATION_TYPE = std::chrono::nanoseconds>
  int backoff_push(const T              &item,
                   const DURATION_TYPE  &sleep        = std::chrono::nanoseconds(10),
                   const size_t         &max_retries  = 0)
  {
    if (open_.load() == false)
      return -1;

    size_t retry_count = 0;
    while (queue_.push(item) == false)
    {
      if (max_retries > 0)
        if (retry_count++ >= max_retries)
          return EAGAIN;  // 최대 재시도 횟수 초과

      std::this_thread::sleep_for(sleep);
    }

    return 0;
  }

  /**
   * @brief 큐에서 아이템을 꺼냄
   * 
   * SIGNALED 템플릿 파라미터에 따라 signaled_pop 또는 adaptive_pop을 호출합니다.
   * condition variable의 특성상 발생할 수 있는 "lost wakeup" 또는 "missed notification" 문제는
   * MSignal 클래스에서 처리되므로 상관이 없습니다.
   * 
   * @param[out] item 꺼낸 아이템을 저장할 변수
   * @return 성공시 0, 큐가 닫혔으면 -1
   */
  int pop(T &item)
  {
    if (SIGNALED == true)
      return signaled_pop(item);

    // ADAPTIVE SPIN처리
    return adaptive_pop(item);
  }

  /**
   * @brief 큐가 비어있는지 확인
   * @return 비어있으면 true, 아니면 false
   */
  bool empty() const
  {
    return queue_.empty();
  }

  /**
   * @brief 현재 큐의 크기 반환
   * @return 큐 내 아이템 개수
   */
  size_t size() const
  {
    return queue_.size();
  }

  /**
   * @brief 큐의 최대 용량 반환
   * @return 큐의 최대 용량
   */
  size_t capacity() const
  {
    return queue_.capacity();
  }

  /**
   * @brief 큐가 열려있는지 확인
   * @return 열려있으면 true, 닫혔으면 false
   */
  bool is_open() const
  {
    return open_.load();
  }

protected:
  /**
   * @brief 시그널 기반 대기를 사용하여 아이템을 꺼냄
   * 
   * 큐가 비어있을 경우 시그널을 기다립니다.
   * 
   * @param[out] item 꺼낸 아이템을 저장할 변수
   * @return 성공시 0, 큐가 닫혔으면 -1
   */
  int signaled_pop(T &item)
  {
    while (true)
    {
      if (queue_.pop(item) == true)
        return 0;

      if (queue_.empty() == true && open_ == false)
        return -1;

      signal_.wait();
    }

    return 0;
  }

  /**
   * @brief 적응형 스핀 대기를 사용하여 아이템을 꺼냄
   * 
   * 초기에는 스핀 대기를 사용하고, 일정 시간 후에는 sleep을 사용하여
   * CPU 사용량과 응답성 사이의 균형을 맞춥니다.
   * 
   * @param[out] item 꺼낸 아이템을 저장할 변수
   * @return 성공시 0, 큐가 닫혔으면 -1
   */
  int adaptive_pop(T &item)
  {
    int fails = 0;
    // 큐가 비어있다면 계속 루프
    while (queue_.pop(item) == false)
    {
      // 큐가 비어있으면 계속 실패, // 초반엔 그냥 spin
      if (fails++ < 1000)
      {
        fails++;
        continue;
      }

      std::this_thread::sleep_for(std::chrono::nanoseconds(10));  // 오래 걸리면 sleep

      // 블럭킹을 멈추기위한, 즉, 큐를 닫으면 종료되도록 하기위한 장치.
      if (queue_.empty() == true && open_.load() == false)
        return -1;

      fails = 0;
    }

    // 블럭킹을 멈추기위한, 즉, 큐를 닫으면 종료되도록 하기위한 장치.
    if (queue_.empty() == true && open_.load() == false)
      return -1;

    return 0;
  }

private:
  /**
   * @brief 내부 락프리 큐 컨테이너
   */
  boost::lockfree::queue<T, Options...> queue_;
  
  /**
   * @brief 동기화를 위한 신호 객체
   */
  MSignal signal_;
  
  /**
   * @brief 큐의 열림/닫힘 상태
   * true: 열림 상태, false: 닫힘 상태
   */
  std::atomic<bool> open_;
};
