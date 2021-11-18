#pragma once
#include <ctypes.h>



namespace os {
//[BSS] Expected size is 0x000008
extern undefined4 AlarmQueue;
void OSInitAlarm(void);
void OSCreateAlarm(undefined4 *param_1);
void InsertAlarm(undefined4 *param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5);
void OSSetAlarm(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5);
void OSSetPeriodicAlarm(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7);
void OSCancelAlarm(int *param_1);
void DecrementerExceptionCallback(undefined4 param_1,undefined4 param_2);
void DecrementerExceptionHandler(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8);
}
