#include <wheels/support/random.hpp>

#include <random>
#include <stdexcept>

namespace wheels {

size_t RandomUInteger(size_t max) {
  static thread_local std::mt19937 generator(std::random_device{}());

  std::uniform_int_distribution<size_t> distribution(0, max);
  return distribution(generator);
}

size_t RandomUInteger(size_t lo, size_t hi) {
  if (lo > hi) {
    throw std::invalid_argument("lo > hi");
  }
  return lo + RandomUInteger(hi - lo);
}

bool TossFairCoin() {
  return RandomUInteger(1) == 0;
}

}  // namespace wheels
