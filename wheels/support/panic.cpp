#include <wheels/support/panic.hpp>

#include <mutex>

namespace wheels {
namespace detail {

static std::mutex mutex;

void Panic(SourceLocation where, const std::string& error) {
  {
    std::lock_guard guard(mutex);
    std::cerr << "Panicked at " << where << ": " << error << std::endl;
  }

  std::abort();
}

}  // namespace detail
}  // namespace wheels
