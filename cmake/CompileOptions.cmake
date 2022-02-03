# Compile options

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# https://clang.llvm.org/docs/DiagnosticsReference.html
add_compile_options(-Wall -Wextra -Wpedantic -g -fno-omit-frame-pointer)

if(TINY_FIBERS_DEVELOPER)
    message(STATUS "Turn warnings into errors")
    add_compile_options(-Werror)
endif()
