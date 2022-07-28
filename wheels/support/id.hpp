#pragma once

#include <cstddef>
#include <atomic>

namespace wheels {

// Monotonic integer ids

//////////////////////////////////////////////////////////////////////

using Id = std::size_t;

extern const Id kInvalidId;

//////////////////////////////////////////////////////////////////////

class IdGenerator {
 public:
  Id NextId() {
    return next_.fetch_add(1) + 1;
  }

  // ?
  void Reset() {
    next_ = 0;
  }

 private:
  std::atomic<Id> next_{0};
};

}  // namespace wheels
