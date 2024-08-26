

pw_add_library(pw_board_led_host.impl STATIC
  SOURCES
    led.cc
  PRIVATE_DEPS
    pw_board_led.impl.facade
    pw_log
)
