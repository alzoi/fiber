#pragma once

// Examples:
// #define LINE 17
// _TO_STRING_EXPANDED(LINE) -> "LINE"
// TO_STRING(LINE) -> _TO_STRING_EXPANDED(17) -> "17"

#define _TO_STRING_EXPANDED(x) #x
#define TO_STRING(x) _TO_STRING_EXPANDED(x)

#define _CONCAT_EXPANDED(x, y) x##y
#define CONCAT(x, y) _CONCAT_EXPANDED(x, y)

#define UNIQUE_NAME(name) CONCAT(name, __COUNTER__)

#include <wheels/support/map.hpp>
