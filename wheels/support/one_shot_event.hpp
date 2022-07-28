#pragma once

#include <condition_variable>
#include <mutex>

namespace wheels {

class OneShotEvent {
 public:
  void Set() {
    std::lock_guard<std::mutex> lock(mutex_);
    set_ = true;
    set_cond_.notify_all();
  }

  void Await() {
    std::unique_lock<std::mutex> lock(mutex_);
    while (!set_) {
      set_cond_.wait(lock);
    }
  }

  bool TimedWait(std::chrono::duration<double> timeout) {
    std::unique_lock<std::mutex> lock(mutex_);
    // use wait_until instead of wait_for to prevent early wakeup
    return set_cond_.wait_until(lock,
                                std::chrono::steady_clock::now() + timeout,
                                [this]() { return set_; });
  }

 private:
  bool set_{false};
  std::mutex mutex_;
  std::condition_variable set_cond_;
};

}  // namespace wheels
