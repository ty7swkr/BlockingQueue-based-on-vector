#include "MThread.h"
#include <iostream>

void
MThread::executor(MThread *thread)
{
  thread->run_signal_.notify_one([&]() { thread->run_ = true; } );
  thread->run();
  thread->run_signal_.notify_one([&]() { thread->run_ = false; } );
}

bool
MThread::join()
{
  std::lock_guard<std::mutex> guard(lock_);
  if (start_ == false)
    return false;

  run_signal_.wait([&]() { return run_ == false; });

  thread_->join();
  start_ = false;
  return true;
}

bool
MThread::start()
{
  std::lock_guard<std::mutex> guard(lock_);
  if (start_ == true)
    return false;

  try
  {
    err_str_.clear();
    thread_ = std::make_shared<std::thread>(MThread::executor, this);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    err_str_ = e.what();
    return false;
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Invalid argument exception: " << e.what() << std::endl;
    err_str_ = e.what();
    return false;
  }
  catch (const std::exception& e)
  {
    std::cerr << "Exception occurred: " << e.what() << std::endl;
    err_str_ = e.what();
    return false;
  }

  if (thread_ == nullptr)
  {
    err_str_ = "Unknown error: thread_ is nullptr";
    return false;
  }

  // 리턴값이 true면 wait에서 빠져나온다.
  // 리턴값이 false면 락을 풀고 wait 상태로 진입
  start_ = true;
  run_signal_.wait([&]() { return run_; });

  return true;
}

