
include($ENV{PW_ROOT}/pw_build/pigweed.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/backend.cmake)

pw_add_facade(pw_board_led.impl INTERFACE
  BACKEND
    pw_board_led.impl_BACKEND
  HEADERS
    public/pw_board_led/led.h
  PUBLIC_INCLUDES
    public
)
