cmake_minimum_required(VERSION 3.19)

# Include pigweed cmake functions. This ensures $ENV{PW_ROOT} is set.
include(third_party/pigweed/pw_build/pigweed.cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE $ENV{PW_ROOT}/pw_toolchain/host_clang/toolchain.cmake)

project(Quickstart)
# Add Pigweed libraries.
add_subdirectory($ENV{PW_ROOT} pigweed)

include(modules/pw_board_led/backend.cmake)
pw_set_backend(pw_board_led.impl pw_board_led_host.impl)

add_subdirectory(modules/pw_board_led)
add_subdirectory(modules/pw_board_led_host)

add_subdirectory(apps/blinky)
