#pragma once

#include <vector>

namespace wheels {

namespace detail {

template <typename T>
void ToVectorImpl(std::vector<T>& v, T&& value) {
  v.emplace_back(std::forward<T>(value));
}

template <typename T, typename... Ts>
void ToVectorImpl(std::vector<T>& v, T&& first, Ts&&... rest) {
  v.emplace_back(std::forward<T>(first));
  ToVectorImpl(v, std::forward<Ts>(rest)...);
}

}  // namespace detail

// Support move-only types
template <typename T, typename... Ts>
std::vector<T> ToVector(T&& first, Ts&&... rest) {
  std::vector<T> v;
  detail::ToVectorImpl(v, std::forward<T>(first), std::forward<Ts>(rest)...);
  return v;
}

}  // namespace wheels
