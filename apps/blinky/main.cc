// Copyright 2024 The Pigweed Authors
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not
// use this file except in compliance with the License. You may obtain a copy of
// the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
// License for the specific language governing permissions and limitations under
// the License.
#define PW_LOG_MODULE_NAME "MAIN"

#include "pw_assert/check.h"
#include "pw_board_led/led.h"
#include "pw_chrono/system_clock.h"
#include "pw_chrono/system_timer.h"
#include "pw_log/log.h"
#include "pw_system/work_queue.h"

namespace {

using namespace ::std::chrono_literals;

void ToggleLedCallback(pw::chrono::SystemClock::time_point);

pw::chrono::SystemTimer blink_timer(ToggleLedCallback);

void ScheduleLedToggle() { blink_timer.InvokeAfter(1s); }

void ToggleLedCallback(pw::chrono::SystemClock::time_point) {
  PW_LOG_INFO("Toggling LED");
  pw::board_led::Toggle();
  // Scheduling the timer again might not be safe from this context, so instead
  // just defer to the work queue.
  PW_CHECK_OK(pw::system::GetWorkQueue().PushWork(ScheduleLedToggle));
}

}  // namespace

namespace pw::system {

// This will run once after pw::system::Init() completes. This callback must
// return or it will block the work queue.
void UserAppInit() {
  pw::board_led::Init();
  // Start the blink cycle.
  PW_CHECK_OK(pw::system::GetWorkQueue().PushWork(ScheduleLedToggle));
}

}  // namespace pw::system
