cmake_minimum_required(VERSION 3.19)

# Include pigweed cmake functions. This ensures $ENV{PW_ROOT} is set.
include(third_party/pigweed/pw_build/pigweed.cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE toolchains/host_clang.cmake)

project(Quickstart)
# Add Pigweed libraries.
add_subdirectory($ENV{PW_ROOT} pigweed)

add_subdirectory(apps/blinky)
