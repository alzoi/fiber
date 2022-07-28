#pragma once

#include <functional>
#include <tuple>
#include <type_traits>

namespace whirl {

template <typename T>
struct FunctionTraits : FunctionTraits<decltype(&T::operator())> {};

template <typename C, typename R, typename... Args>
struct FunctionTraits<R (C::*)(Args...)> : FunctionTraits<R (*)(Args...)> {};

template <typename C, typename R, typename... Args>
struct FunctionTraits<R (C::*)(Args...) const>
    : FunctionTraits<R (*)(Args...)> {};

template <typename R, typename... Args>
struct FunctionTraits<R (*)(Args...)> {
  using ResultType = R;
  using ArgumentsTuple = std::tuple<typename std::decay<Args>::type...>;
};
}  // namespace whirl
