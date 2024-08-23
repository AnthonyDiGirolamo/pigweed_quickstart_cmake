:<<"::WINDOWS_ONLY"
@echo off
:: Copyright 2024 The Pigweed Authors
::
:: Licensed under the Apache License, Version 2.0 (the "License"); you may not
:: use this file except in compliance with the License. You may obtain a copy of
:: the License at
::
::     https://www.apache.org/licenses/LICENSE-2.0
::
:: Unless required by applicable law or agreed to in writing, software
:: distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
:: WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
:: License for the specific language governing permissions and limitations under
:: the License.
::WINDOWS_ONLY
:; echo "ERROR: Attempting to run Windows .bat from a Unix/POSIX shell!"
:; echo "Instead, run the following command."
:; echo ""
:; echo "    source ./activate.sh"
:; echo ""
:<<"::WINDOWS_ONLY"

:: First, activate the development environment.
set PW_SKIP_BOOTSTRAP=1
call "%~dp0\bootstrap.bat"
set PW_SKIP_BOOTSTRAP=

:: Add user-defined environment configuration here.

::WINDOWS_ONLY
