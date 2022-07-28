#include <wheels/support/sanitizers.hpp>

namespace wheels {

int GetSanitizerSlowdown() {
#if __has_feature(address_sanitizer)
  // https://clang.llvm.org/docs/AddressSanitizer.html
  // Typical slowdown introduced by AddressSanitizer is 2x.
  return 2;
#elif __has_feature(thread_sanitizer)
  // https://clang.llvm.org/docs/ThreadSanitizer.html
  // Typical slowdown introduced by ThreadSanitizer is about 5x-15x.
  return 10;
#else
  return 1;
#endif
}

}  // namespace wheels
