#pragma once

// Meyers singleton
// Thread-safe since C++11

template <class T>
T* Singleton() {
  static T instance;
  return &instance;
}
