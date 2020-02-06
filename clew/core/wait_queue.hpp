#pragma once

#include <memory>

namespace twist {
namespace fiber {

class WaitQueue {
 public:
  WaitQueue();
  ~WaitQueue();

  void Park();

  void WakeOne();
  void WakeAll();
  bool IsEmpty() const;

 private:
  class Impl;
  std::unique_ptr<Impl> pimpl_;
};

}  // namespace fiber
}  // namespace twist
