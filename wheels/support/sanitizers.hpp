#pragma once

#include <sanitizer/lsan_interface.h>

namespace wheels {

////////////////////////////////////////////////////////////////////////////////

// >= 1, 1 means no slowdown
int GetSanitizerSlowdown();

////////////////////////////////////////////////////////////////////////////////

// Leaks

#if __has_feature(address_sanitizer)

// Mark intentional memory leak
// The heap object referenced by pointer 'ptr' will be annotated as a leak.

inline void MarkLeakingObjectPtr(void* ptr) {
  __lsan_ignore_object(ptr);
}

using LeaksScope = __lsan::ScopedDisabler;

#else

inline void MarkLeakingObjectPtr(void*) {
}

struct LeaksScope {
  LeaksScope() {
  }
  ~LeaksScope() {
  }
};

#endif

}  // namespace wheels
