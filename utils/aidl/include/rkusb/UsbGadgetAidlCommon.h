/*
 * Copyright (C) 2023 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <aidl/android/hardware/usb/gadget/IUsbGadget.h>
#include <rkusb/CommonUtils.h>
#include <rkusb/MonitorFfs.h>

namespace aidl {
namespace android {
namespace hardware {
namespace usb {
namespace gadget {
using ::aidl::android::hardware::usb::gadget::Status;

//**************** Helper functions ************************//
// Sets the USB VID and PID.
Status setVidPid(const char *vid, const char *pid);
// Adds Adb to the usb configuration.
Status addAdb(MonitorFfs *monitorFfs, int *functionCount);
// Adds all applicable generic android usb functions other than ADB.
Status addGenericAndroidFunctions(MonitorFfs *monitorFfs, uint64_t functions, bool *ffsEnabled,
                                  int *functionCount);
// Pulls down USB gadget.
Status resetGadget();

}  // namespace aidl
}  // namespace android
}  // namespace hardware
}  // namespace usb
}  // namespace gadget
