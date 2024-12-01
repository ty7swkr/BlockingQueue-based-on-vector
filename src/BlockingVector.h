// BlockingVector.h
#pragma once

#include "MSignal.h"
#include <vector>

template<typename T>
class BlockingVector
{
public:
  /**
   * @brief 생성자
   * @param open 초기 열림 상태
   */
  explicit BlockingVector(const size_t &reserve_size = 10000, const bool& open = true);

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
  void reserve(const size_t& size);

  /**
   * @brief 벡터의 예약된 용량 확인
   * @param size 예약된 용량
   */
  size_t capacity() const { return container_.capacity(); }

  /**
   * @brief 아이템을 벡터에 추가
   * @param item 추가할 아이템
   * @return 성공시 0, 닫혔으면 -1
   */
  int push(const T& item);

  /**
   * @brief 아이템을 벡터에 추가
   * @param item 추가할 아이템
   * @return 성공시 0, 닫혔으면 -1
   */
  int push(const T& item, size_t &remain_size);

  /**
   * @brief 벡터에서 아이템들을 꺼냄
   * @param[out] items 아이템을 받을 벡터
   * @param msec 타임아웃 (밀리초)
   * @return 성공시 0, 닫혔으면 -1, 타임아웃시 ETIMEDOUT
   */
  int pop(std::vector<T>& items, const uint32_t& msec = 0);

  /**
   * @brief 제공된 벡터와 내용을 교체
   * @param items 교체할 벡터
   */
  void swap(std::vector<T>& items);

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
  bool open_ = true;
  mutable MSignal signal_;
  std::vector<T> container_;
  size_t reserve_size_ = 10000;
};

template<typename T>
BlockingVector<T>::BlockingVector(const size_t &reserve_size, const bool& open)
: open_(open) { this->reserve(reserve_size); }

template<typename T> void
BlockingVector<T>::open()
{
  signal_.notify_one([&]()
  {
    open_ = true;
  });
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
  auto locked_lock = signal_.scoped_acquire_lock();
  return open_;
}

template<typename T> void
BlockingVector<T>::reserve(const size_t& size)
{
  reserve_size_ = size;
  container_.reserve(size);
}

template<typename T> int
BlockingVector<T>::push(const T& item)
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
BlockingVector<T>::push(const T& item, size_t &remain_size)
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

template<typename T> int
BlockingVector<T>::pop(std::vector<T>& items, const uint32_t& msec)
{
  items.clear();
  if (items.capacity() < reserve_size_)
    items.reserve(reserve_size_);

  while (true)
  {
    auto locked_lock = signal_.scoped_acquire_lock();
    if (container_.size() > 0)
    {
      container_.swap(items);
      return 0;
    }

    if (open_ == false)
      return -1;

    if (signal_.wait(locked_lock, msec) == false)
      return ETIMEDOUT;
  }
}

template<typename T> void
BlockingVector<T>::swap(std::vector<T>& items)
{
  container_.swap(items);
}

template<typename T> size_t
BlockingVector<T>::size() const
{
  auto locked_lock = signal_.scoped_acquire_lock();
  return container_.size();
}

template<typename T> std::vector<T>
BlockingVector<T>::container() const
{
  auto locked_lock = signal_.scoped_acquire_lock();
  return container_;
}

