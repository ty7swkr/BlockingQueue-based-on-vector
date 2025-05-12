// BlockingVector.h
#pragma once

#include "MSignal.h"
#include <vector>
#include <thread>

using microsecs = std::chrono::microseconds;
using millisecs = std::chrono::milliseconds;
using seconds   = std::chrono::seconds;

template<typename T>
class BlockingVector
{
public:
  /**
   * @brief 생성자
   * @param open 초기 열림 상태
   */
  explicit BlockingVector(size_t reserve_size = 10000, bool open = true);

  ~BlockingVector() = default;

  /**
   * @brief 벡터를 열어서 작업 가능하게 함
   */
  void open();

  /**
   * @brief 벡터를 닫아서 더 이상의 작업을 차단
   */
  void close();

  /**
   * @brief 벡터가 열려있는지 확인
   * @return 열려있으면 true, 닫혔으면 false
   */
  bool is_open() const;

  /**
   * @brief 벡터의 용량 예약
   * @param size 예약할 용량
   */
  void reserve(size_t size);

  /**
   * @brief 벡터의 용량 확인
   * @return size 현재 용량
   */
  size_t capacity() const;

  /**
   * @brief 벡터의 예약된 용량 확인
   * @return size 예약된 용량
   */
  size_t reserve_size() const;

  /**
   * @brief 아이템을 벡터에 추가
   * @param item 추가할 아이템
   * @return 성공시 0, 닫혔으면 -1
   */
  int push(const T &item);

  /**
   * @brief 아이템을 벡터에 추가
   * @param item 추가할 아이템
   * @return 성공시 0, 닫혔으면 -1
   */
  int push(const T &item, size_t &remain_size);

  /**
   * @brief push시 capacity에 도달하면 sleep만큼 대기하고 시도.
   * @param item 추가할 아이템
   * @param max_retries 최대 시도회수. 0이면 무한.
   * @param sleep 대기시간.
   * @return 성공시 0, 닫혔으면 -1, max_tries도달시 EAGAIN
   */
  int backoff_push(const T    &item,
                   size_t     max_retries = 0,
                   microsecs  sleep = microsecs(1)) { return backoff_push<size_t, std::micro>(item, max_retries, sleep); }
  int backoff_push(const T &item, size_t    max_retries, millisecs  sleep) { return backoff_push<size_t, std::micro>  (item, max_retries, sleep); }
  int backoff_push(const T &item, size_t    max_retries, seconds    sleep) { return backoff_push<size_t, seconds>     (item, max_retries, sleep); }

  int backoff_push(const T &item, microsecs sleep, size_t max_retries = 0) { return backoff_push<size_t, microsecs>   (item, max_retries, sleep); }
  int backoff_push(const T &item, millisecs sleep, size_t max_retries = 0) { return backoff_push<size_t, millisecs>   (item, max_retries, sleep); }
  int backoff_push(const T &item, seconds   sleep, size_t max_retries = 0) { return backoff_push<size_t, seconds>     (item, max_retries, sleep); }

  /**
   * @brief 벡터에서 아이템들을 꺼냄
   * @param[out] items 아이템을 받을 벡터
   * @param tmout_msec 타임아웃 (밀리초)
   * @return 성공시 0, 닫혔으면 -1, 타임아웃시 ETIMEDOUT
   */
  int pop(std::vector<T> &items, uint32_t tmout_msec = 0);

  /**
   * @brief 제공된 벡터와 내용을 교체
   * @param items 교체할 벡터
   */
  void swap(std::vector<T> &items);

  /**
   * @brief 현재 크기 반환
   * @return 벡터 내 아이템 개수
   */
  size_t size() const;

  /**
   * @brief 컨테이너 복사본 반환
   * @return 내부 벡터의 복사본
   */
  std::vector<T> container() const;

protected:
  /**
   * @brief 아이템을 벡터에 추가
   * @param item 추가할 아이템
   * @return 성공시 0, 닫혔으면 -1, EAGAIN
   */
  template<typename Rep, typename Period>
  int backoff_push(const T  &item,
                   size_t   max_retries,
                   std::chrono::duration<Rep, Period> sleep);

protected:
  bool            open_ = true;
  mutable MSignal signal_;
  std::vector<T>  container_;
  size_t          reserve_size_ = 10000;
};

template<typename T>
BlockingVector<T>::BlockingVector(size_t reserve_size, bool open)
: open_(open) { this->reserve(reserve_size); }

template<typename T> void
BlockingVector<T>::open()
{
  auto lock = signal_.scoped_acquire_lock();
  open_ = true;
}

template<typename T> void
BlockingVector<T>::close()
{
  signal_.notify_one([&]()
  {
    open_ = false;
  });
}

template<typename T> bool
BlockingVector<T>::is_open() const
{
  auto lock_guard = signal_.scoped_acquire_lock();
  return open_;
}

template<typename T> void
BlockingVector<T>::reserve(size_t size)
{
  auto lock_guard = signal_.scoped_acquire_lock();
  reserve_size_ = size;
  container_.reserve(size);
}

template<typename T> size_t
BlockingVector<T>::capacity() const
{
  auto lock_guard = signal_.scoped_acquire_lock();
  return container_.capacity();
}

template<typename T> size_t
BlockingVector<T>::reserve_size() const
{
  auto lock_guard = signal_.scoped_acquire_lock();
  return reserve_size_;
}

template<typename T> int
BlockingVector<T>::push(const T &item)
{
  return signal_.notify_one([&]()
  {
    if (open_ == false)
      return -1;

    container_.push_back(item);
    return 0;
  });
}

template<typename T> int
BlockingVector<T>::push(const T &item, size_t &remain_size)
{
  return signal_.notify_one([&]()
  {
    if (open_ == false)
      return -1;

    container_.push_back(item);
    remain_size = container_.size();
    return 0;
  });
}

template<typename T>
template<typename Rep, typename Period> int
BlockingVector<T>::backoff_push(const T &item,
                                size_t  max_retries,
                                std::chrono::duration<Rep, Period> sleep)
{
  size_t retry_count = 0;
  return signal_.notify_one([&](std::unique_lock<std::mutex> &lock)
  {
    while (container_.size() >= this->container_.capacity())
    {
      if (open_ == false)
        return -1;

      if (max_retries > 0)
        if (retry_count++ >= max_retries)
          return EAGAIN;  // 최대 재시도 횟수 초과

      lock.unlock();
      std::this_thread::sleep_for(sleep);
      lock.lock();
    }

    container_.push_back(item);

    return 0;
  });
}

template<typename T> int
BlockingVector<T>::pop(std::vector<T> &items, uint32_t tmout_msec)
{
  items.clear();
  if (items.capacity() < reserve_size_)
    items.reserve(reserve_size_);

  while (true)
  {
    auto lock_guard = signal_.scoped_acquire_lock();
    if (container_.size() > 0)
    {
      container_.swap(items);
      return 0;
    }

    if (open_ == false)
      return -1;

    if (signal_.wait(lock_guard, tmout_msec) == false)
      return ETIMEDOUT;
  }
}

template<typename T> void
BlockingVector<T>::swap(std::vector<T> &items)
{
  auto lock_guard = signal_.scoped_acquire_lock();
  container_.swap(items);
}

template<typename T> size_t
BlockingVector<T>::size() const
{
  auto lock_guard = signal_.scoped_acquire_lock();
  return container_.size();
}

template<typename T> std::vector<T>
BlockingVector<T>::container() const
{
  auto lock_guard = signal_.scoped_acquire_lock();
  return container_;
}
