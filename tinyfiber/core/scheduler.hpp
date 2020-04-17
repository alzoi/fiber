#pragma once

#include <tinyfiber/core/api.hpp>
#include <tinyfiber/core/fiber.hpp>

#include <tinysupport/time.hpp>

namespace tiny::fiber {

using FiberQueue = support::IntrusiveList<Fiber>;

class Scheduler {
 public:
  Scheduler();

  void Run(FiberRoutine init);

  // From fiber context

  void Spawn(FiberRoutine routine);
  void Yield();
  void SleepFor(Duration duration);
  void Suspend();
  void Resume(Fiber* that);
  void Terminate();

  Fiber* GetCurrentFiber();

 private:
  void RunLoop();

  // Context switch: current fiber -> scheduler
  void SwitchToScheduler();
  // Context switch: scheduler -> fiber
  void SwitchTo(Fiber* fiber);

  void Reschedule(Fiber* fiber);
  void Schedule(Fiber* fiber);

  Fiber* CreateFiber(FiberRoutine routine);
  void Destroy(Fiber* fiber);

  void SetCurrentFiber(Fiber* fiber);
  Fiber* GetAndResetCurrentFiber();

 private:
  ExecutionContext loop_context_;
  FiberQueue run_queue_;
  Fiber* running_{nullptr};
};

//////////////////////////////////////////////////////////////////////

Fiber* GetCurrentFiber();
Scheduler* GetCurrentScheduler();

}  // namespace tiny::fiber
