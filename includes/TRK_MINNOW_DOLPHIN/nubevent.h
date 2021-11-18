#pragma once
#include <ctypes.h>



namespace TRK_MINNOW_DOLPHIN {
//[BSS] Expected size is 0x000028
extern undefined gTRKEventQueue;
void TRKDestructEvent(int param_1);
void TRKConstructEvent(undefined *param_1,undefined param_2);
undefined4 TRKPostEvent(undefined4 param_1);
undefined4 TRKGetNextEvent(undefined4 param_1);
undefined4 TRKInitializeEventQueue(void);
}
