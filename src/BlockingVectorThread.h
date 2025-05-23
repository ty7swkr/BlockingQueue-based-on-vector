/*
 * BlockingVectorThread.h
 *
 *  Created on: 2024. 8. 19.
 *      Author: tys
 */

#pragma once

#include "MThread.h"
#include "BlockingVector.h"

template<typename T = int>
class BlockingVectorThread : public MThread
{
public:
/**
 * @brief BlockingVectorThread 생성자
 * @param reserve_size 벡터의 초기 예약 크기 (기본값: 10000)
 */
  BlockingVectorThread(size_t reserve_size = 10000);
  virtual ~BlockingVectorThread() {}

  /**
   * @brief 스레드 시작
   * @return 성공시 true, 실패시 false
   */
  bool start() override;

  /**
   * @brief 스레드 종료
   * @return 성공시 true, 실패시 false
   */
  virtual bool stop ();

  /**
   * @brief 벡터의 예약 크기 설정
   * @param size 예약할 크기
   */
  void reserve(size_t size) { waiter_.reserve(size); }

protected:
  BlockingVector<T> waiter_;
};

template<typename T>
BlockingVectorThread<T>::BlockingVectorThread(size_t reserve_size)
: waiter_(reserve_size, false)
{
}

template<typename T> bool
BlockingVectorThread<T>::start()
{
  if (MThread::is_run() == true)
    return true;

  waiter_.open();
  return MThread::start();
}

template<typename T> bool
BlockingVectorThread<T>::stop()
{
  if (MThread::is_run() == false)
    return true;

  waiter_.close();
  return MThread::join();
}

