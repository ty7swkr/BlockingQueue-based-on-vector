#pragma once

#include "MSignal.h"
#include <boost/lockfree/queue.hpp>
#include <thread>


// SIGNALED
// true  : c++ signal기반 대기
// false : lock free queue의 spin기반 대기
// 시그널 기반 : 대기시 cpu 점유을 0, 처리속도 느림.
// 스핀 기반 : 대기시 cpu 점유율 ~10%(?), 처리속도 빠름.
template<typename T, bool SIGNALED = false>
class BlockingLockFreeQueue
{
public:
  BlockingLockFreeQueue(const size_t &capacity = 10000)
  : queue_(capacity), open_(true) {}

  ~BlockingLockFreeQueue() {}

  bool is_signaled() const { return SIGNALED; }

  void close()
  {
    open_ = false;
    if (SIGNALED == true)
      signal_.notify_one();
  }

  // 0 : 성공
  // -1 : 큐닫힘
  // 양수 큐 꽉참. EAGAIN
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

  // 0 : 정상수신
  // -1 : 큐 닫힘
  // 양수 : 타임아웃(ETIMEDOUT = 110) <- 확장 예정.
  // condition variable의 특성상 발생할 수 있는 "lost wakeup" 또는 "missed notification" 문제
  // 는 MSignal 클래스에서 처리되므로 상관이 없다.
  int pop(T &item)
  {
    if (SIGNALED == true)
      return signaled_pop(item);

    // ADAPTIVE SPIN처리
    return adaptive_pop(item);
  }

  bool empty() const
  {
    return queue_.empty();
  }

  size_t size() const
  {
    return queue_.size();
  }

  size_t capacity() const
  {
    return queue_.capacity();
  }

  bool is_open() const
  {
    return open_.load();
  }

protected:
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

  // 0 : 정상수신
  // -1 : 큐 닫힘
  int adaptive_pop(T & item)
  {
    int fails = 0;
    // 큐가 비어있다면 계속 루프
    while (queue_.pop(item) == false)
    {
      // 블럭킹을 멈추기위한, 즉, 큐를 닫으면 종료되도록 하기위한 장치.
      if (open_.load() == false)
        return -1;

      // 큐가 비어있으면 계속 실패
      if (fails < 1000)
        fails++;  // 초반엔 그냥 spin
      else
        std::this_thread::sleep_for(std::chrono::microseconds(1));  // 오래 걸리면 sleep
    }

    return 0;
  }

private:
  boost::lockfree::queue<T> queue_;
  MSignal signal_;
  std::atomic<bool> open_;
};

