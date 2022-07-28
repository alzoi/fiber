#pragma once

#include <wheels/support/function2.hpp>

// https://github.com/Naios/function2
// Commit: 3a0746bf5f601dfed05330aefcb6854354fce07d

namespace wheels {

template <typename Signature>
using UniqueFunction = fu2::unique_function<Signature>;

}  // namespace wheels
