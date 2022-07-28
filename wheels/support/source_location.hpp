#pragma once

#include <iostream>
#include <string_view>

namespace wheels {

// Represents location in source code: file name, function name, line number

struct SourceLocation {
  std::string_view file_;
  std::string_view function_;
  int line_;

  SourceLocation(std::string_view file, std::string_view function, int line)
      : file_(file), function_(function), line_(line) {
  }

  SourceLocation() : line_(0) {
  }

  static SourceLocation Current(const char* file = __builtin_FILE(),
                                const char* function = __builtin_FUNCTION(),
                                const int line = __builtin_LINE()) {
    return {file, function, line};
  }
};

std::ostream& operator<<(std::ostream& out, const SourceLocation& where);

}  // namespace wheels

// Use WHEELS_HERE in macros to capture current location

#define WHEELS_HERE \
  ::wheels::SourceLocation(__FILE__, __PRETTY_FUNCTION__, __LINE__)
