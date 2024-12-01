#pragma once

#include <mutex>
#include <condition_variable>
#include <chrono>
#include <functional>

class MSignal
{
public:
  MSignal () = default;
  ~MSignal() = default;


  void notify_one()
  {
    std::lock_guard<std::mutex> lock(lock_);
    notify_one_nolock();
  }

  // notify_one은
  // 시그널 중복 또는 시그널 놓짐을 없애기 위해.
  // 락이 걸린 상태에서 시그널을 보낸다.
  // 니가 시그널을 보내기 전까지 락을 걸고 무언가 하고 싶을때
  // 람다함수(F func)를 사용할 수 있다.

  // 1. non-void 리턴 타입용
  template<typename F,
           typename R = decltype(std::declval<F>()()),
           typename   = typename std::enable_if<!std::is_void<R>::value>::type>
  R notify_one(F&& func)
  {
    std::lock_guard<std::mutex> lock(lock_);
    auto result = std::forward<F>(func)();
    notify_one_nolock();
    return result;
  }

  // 2. void 리턴 타입용
  // void 버전은 템플릿 파라미터가 4개가 됨
  //  template<typename F, typename R, typename = /*void 체크*/, typename = void>
  template<typename F,
           typename R = decltype(std::declval<F>()()),
           typename   = typename std::enable_if<std::is_void<R>::value>::type,
           typename   = void>  // 추가 더미 파라미터로 시그니처 구분(컴파일러가 구분할 수 있게.)
  void notify_one(F&& func)
  {
    std::lock_guard<std::mutex> lock(lock_);
    std::forward<F>(func)();
    notify_one_nolock();
  }

  std::unique_lock<std::mutex>
       scoped_acquire_lock() const
  {
    return std::move(std::unique_lock<std::mutex>(this->lock_));
  }

  void notify_one(std::unique_lock<std::mutex> &locked_lock)
  {
    notify_one_nolock();
    locked_lock.unlock();
  }

  // 1:1 에서는 시그널을 놓치지 않도록 구현되어 있음.
  //
  // 1:N 사용에서는 시그널을 놓지는 문제로 안전상
  // notify_all은 사용하지 않음.
  // void notify_all() { cond_.notify_all(); }
  //
  // 시그널을 놓지는 문제는 std::condition_variable의 특성으로
  // wait가 아닐때 signal을 보내면 wait를 받지 못함.
  //
  // MSignal에서는 1:1 사용에 있어서 이 문제는 해결하여 구현되어 있음.
  //
  // N:N 혹은 1:N 모델로 사용하고자 한다면
  // MSignal을 그룹핑하여 사용하는 방법이 있음.

  // false : timeout, true : wakeup
  bool wait(const uint32_t &msec = 0);

  // func가 true를 리턴하면 wait가 즉시 깨어남->false이면 대기->깨어났을때 다시 func호출->이때 fale이면 다시 대기...
  void wait(std::function<bool()> func);

  // false : timeout, true : wakeup
  bool wait(const uint32_t &msec, std::function<bool()> func);

  // lock은 자동 언락됨. 이때 lock는 scoped_acquire_lock의 락을 사용해야함.
  // false : timeout, true : wakeup
  bool wait(std::unique_lock<std::mutex> &lock, const uint32_t &msec = 0);

protected:
  void notify_one_nolock()
  {
    if (signaled_ == true)
      return;

    signaled_ = true;
    cond_.notify_one();
  }

private:
  mutable std::mutex      lock_;
  std::condition_variable cond_;
  bool                    signaled_ = false;
};

inline bool
MSignal::wait(const uint32_t &msec)
{
  std::function<bool()> pred = [&]()
  {
    if (signaled_ == true)
    {
      signaled_ = false;
      return true;
    }
    return false;
  };

  std::unique_lock<std::mutex> lock(lock_);
  if (msec == 0)
  {
    cond_.wait(lock, pred);
    return true;
  }

  std::chrono::milliseconds timeout(msec);
  return cond_.wait_for(lock, timeout, pred);
}

inline bool
MSignal::wait(const uint32_t &msec, std::function<bool()> func)
{
  std::function<bool()> pred = [&]()
  {
    decltype(signaled_) signaled = signaled_;

    if (signaled_ == true)
      signaled_ = false;

    if (func != nullptr) if (func() == true)
        return true;

    if (signaled == true)
      return true;

    return false;
  };

  std::unique_lock<std::mutex> lock(lock_);
  if (msec == 0)
  {
    cond_.wait(lock, pred);
    return true;
  }

  std::chrono::milliseconds timeout(msec);
  return cond_.wait_for(lock, timeout, pred);
}

inline void
MSignal::wait(std::function<bool()> func)
{
  std::function<bool()> pred = [&]()
  {
    decltype(signaled_) signaled = signaled_;

    if (signaled_ == true)
      signaled_ = false;

    if (func != nullptr) if (func() == true)
        return true;

    if (signaled == true)
      return true;

    return false;
  };

  std::unique_lock<std::mutex> lock(lock_);
  cond_.wait(lock, pred);
}

inline bool
MSignal::wait(std::unique_lock<std::mutex> &lock, const uint32_t &msec)
{
  std::function<bool()> pred = [&]()
  {
    if (signaled_ == true)
    {
      signaled_ = false;
      return true;
    }
    return false;
  };

  if (msec == 0)
  {
    cond_.wait(lock, pred);
    return true;
  }

  std::chrono::milliseconds timeout(msec);
  return cond_.wait_for(lock, timeout, pred);
}






