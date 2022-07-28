#pragma once

#include <wheels/support/source_location.hpp>
#include <wheels/support/string_builder.hpp>

namespace wheels {

namespace detail {
[[noreturn]] void Panic(SourceLocation where, const std::string& error);
}  // namespace detail

}  // namespace wheels

// Usage: WHEELS_PANIC("Internal error: " << e.what());

#define WHEELS_PANIC(error)                                                   \
  do {                                                                        \
    ::wheels::detail::Panic(WHEELS_HERE, ::wheels::StringBuilder() << error); \
  } while (false)
