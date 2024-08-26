add_executable(blinky
  main.cc
)

target_link_libraries(blinky
  pw_chrono.system_clock
  pw_chrono.system_timer
  pw_system.work_queue
  pw_system.io
  pw_system.log
  pw_system.rpc_server
  pw_system.init
  pw_log
  pw_board_led.impl
)
