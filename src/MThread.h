#pragma once

#include "MSignal.h"
#include <thread>
#include <mutex>
#include <memory>
#include <sstream>
#include <iomanip>

/**
 * @brief 쓰레드 클래스<br>
 * detach
 */
class MThread
{
public:
  /// @brief 생성자
  MThread();

  /// @brief 소멸자
  virtual ~MThread();

  /// @brief 쓰레드를 시작 시킨다. 에러는 errno로 반환됨.
  virtual bool        start();

  /// @brief 쓰레드로 실행되고 있는지 알려줌
  virtual bool        is_run() const;

  /// @brief 쓰레드가 join될때까지 블럭된다.
  virtual bool        join();

  /// @brief 쓰레드의 id를 리턴받는다.
  virtual uint64_t    thread_id() const;
  virtual std::string thread_id_hex(bool uppercase = true) const;

  virtual std::string error() const;

protected:
  /// @brief 상속받아 구현하여야할 가상함수. 쓰레드가 시작되면 최초로 불려지는 함수
  virtual void run() = 0;

protected:
  static  void executor(MThread *thread);

protected:
  std::shared_ptr<std::thread> thread_;
  mutable uint64_t    thread_id_ = 0;
  mutable std::string thread_hex_;

private:
  std::mutex  lock_;
  bool        start_  = false;
  bool        run_    = false;
  MSignal     run_signal_;
  std::string err_str_;
};

inline
MThread::MThread()
: run_(false)
{
}

inline
MThread::~MThread()
{
}

/**
 * @return 쓰레드 실행 여부
 */
inline bool
MThread::is_run() const
{
  auto lock = run_signal_.scoped_acquire_lock();
  return run_;
}

inline uint64_t
MThread::thread_id() const
{
//  static_assert(sizeof(std::size_t) <= sizeof(uint64_t),
//                "std::size_t is larger than uint64_t on this system");
  if (thread_id_ > 0)
    return thread_id_;

  if (sizeof(std::size_t) > sizeof(uint64_t))
    return 0;

  if (thread_ == nullptr)
    return 0;

#ifdef __linux__
  thread_id_ = static_cast<uint64_t>(thread_->native_handle());
#else
  // 다른 플랫폼에 대한 처리
  thread_id_ = static_cast<uint64_t>(std::hash<std::thread::id>{}(thread_->get_id()));
#endif
  return thread_id_;
}

inline std::string
MThread::thread_id_hex(bool uppercase) const
{
  if (thread_hex_.size() > 0)
    return thread_hex_;

  auto thread_id = this->thread_id();

  std::stringstream stream;
  stream << std::setfill('0') << std::setw(16);
  if (uppercase == true)
    stream << std::uppercase << std::hex << thread_id;
  else
    stream << std::hex << thread_id;

  thread_hex_ = stream.str();
  return thread_hex_;
}

inline std::string
MThread::error() const
{
  return err_str_;
}
