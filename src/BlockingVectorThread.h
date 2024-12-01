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
  BlockingVectorThread(const size_t &reserve_size = 10000);
  virtual ~BlockingVectorThread() {}

          bool start() override;
  virtual bool stop ();

  void    reserve(const size_t &size) { waiter_.reserve(size); }

protected:
  BlockingVector<T> waiter_;
};

template<typename T>
BlockingVectorThread<T>::BlockingVectorThread(const size_t &reserve_size)
: waiter_(reserve_size, false)
{
}

template<typename T> bool
BlockingVectorThread<T>::start()
{
  if (waiter_.is_open() == true)
    return true;

  waiter_.open();
  return MThread::start();
}

template<typename T> bool
BlockingVectorThread<T>::stop()
{
  if (waiter_.is_open() == false)
    return true;

  waiter_.close();
  return MThread::join();
}
