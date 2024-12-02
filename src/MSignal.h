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

  // 기본 케이스 - 인자가 없는 람다, non-void 리턴
  template<typename F,
           typename = typename std::enable_if<!std::is_void<decltype(std::declval<F>()())>::value>::type>
  auto notify_one(F&& func) -> decltype(std::declval<F>()())
  {
      std::lock_guard<std::mutex> lock(lock_);
      auto result = std::forward<F>(func)();
      notify_one_nolock();
      return result;
  }

  // void 리턴 특수화 - 인자가 없는 람다
  template<typename F,
           typename = typename std::enable_if<std::is_void<decltype(std::declval<F>()())>::value>::type,
           typename = void>
  void notify_one(F&& func)
  {
      std::lock_guard<std::mutex> lock(lock_);
      std::forward<F>(func)();
      notify_one_nolock();
  }

  // unique_lock을 인자로 받는 람다 특수화, non-void 리턴
  template<typename F,
           typename = typename std::enable_if<!std::is_void<decltype(std::declval<F>()(std::declval<std::unique_lock<std::mutex>&>()))>::value>::type,
           typename = void,
           typename = void>
  auto notify_one(F&& func) -> decltype(std::declval<F>()(std::declval<std::unique_lock<std::mutex>&>()))
  {
      std::unique_lock<std::mutex> lock(lock_);
      auto result = std::forward<F>(func)(lock);
      notify_one_nolock();
      return result;
  }

  // void 리턴 특수화 - unique_lock을 인자로 받는 람다
  template<typename F,
           typename = typename std::enable_if<std::is_void<decltype(std::declval<F>()(std::declval<std::unique_lock<std::mutex>&>()))>::value>::type,
           typename = void, // 더미파라미터
           typename = void,
           typename = void>
  void notify_one(F&& func)
  {
      std::unique_lock<std::mutex> lock(lock_);
      std::forward<F>(func)(lock);
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
  // 1:N 사용에서는 시그널을 놓지는 문제로
  // notify_all은 사용하지 않음.
  // void notify_all() { cond_.notify_all(); }
  //
  // 시그널을 놓지는 문제는 std::condition_variable의 특성으로
  // wait가 아닐때 signal을 보내면 wait를 받지 못함.
  //
  // N:N 혹은 1:N 모델로 사용하고자 한다면
  // MSignal을 그룹핑하여 사용하는 방법이 있음.

  // false : timeout, true : wakeup
  bool wait(const uint32_t &msec = 0);

  // func가 true를 리턴하면 wait가 즉시 깨어남
  // 대기전 락을 걸고 func호출 false이면 대기->깨어났을때 다시 func호출->이때 fale이면 다시 대기...
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






