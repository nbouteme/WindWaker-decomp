#pragma once
#include <ctypes.h>



namespace TRK_MINNOW_DOLPHIN {
//Expected size is 0x000004
extern undefined4 gTRKBigEndian;

void TRKNubWelcome(void);
undefined4 TRKTerminateNub(void);
int TRKInitializeNub(void);
}
