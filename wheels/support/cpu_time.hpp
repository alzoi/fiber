#pragma once

#pragma once

#include <ctime>
#include <cstdlib>
#include <chrono>

namespace wheels {

class ProcessCPUTimer {
 public:
  ProcessCPUTimer() {
    Reset();
  }

  std::chrono::microseconds Elapsed() const {
    return std::chrono::microseconds(ElapsedMicros());
  }

  void Reset() {
    start_ts_ = std::clock();
  }

 private:
  size_t ElapsedMicros() const {
    const size_t clocks = std::clock() - start_ts_;
    return ClocksToMicros(clocks);
  }

  static size_t ClocksToMicros(const size_t clocks) {
    return (clocks * 1'000'000) / CLOCKS_PER_SEC;
  }

 private:
  std::clock_t start_ts_;
};

}  // namespace wheels

namespace wheels {

class ThreadCPUTimer {
 public:
  ThreadCPUTimer() {
    Reset();
  }

  std::chrono::nanoseconds Elapsed() const {
    return std::chrono::nanoseconds(ElapsedNanos());
  }

  void Reset() {
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &start_);
  }

 private:
  uint64_t ElapsedNanos() const {
    struct timespec now;
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &now);

    return ToNanos(now) - ToNanos(start_);
  }

  static uint64_t ToNanos(const struct timespec& tp) {
    return tp.tv_sec * 1'000'000'000 + tp.tv_nsec;
  }

 private:
  struct timespec start_;
};

}  // namespace wheels
