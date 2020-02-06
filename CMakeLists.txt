cmake_minimum_required(VERSION 3.9)
project(clewlib)

include(cmake/ClangFormat.cmake)
include(cmake/ClangTidy.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#add_subdirectory(third_party)

add_compile_options(-Wall -Wextra -Wpedantic -g -fno-omit-frame-pointer)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

add_subdirectory(clew)

option(TWIST_TESTS "Enable clew library tests" OFF)
option(TWIST_BENCHMARKS "Enable clew library benchmarks" OFF)

if(${CLEW_TESTS})
    add_subdirectory(tests)
endif()

if(${CLEW_BENCHMARKS})
    add_subdirectory(benchmarks)
endif()
