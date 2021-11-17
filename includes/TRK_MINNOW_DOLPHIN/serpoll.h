#pragma once
#include <ctypes.h>



namespace TRK_MINNOW_DOLPHIN {
//Expected size is 0x000004
extern undefined4 gTRKInputPendingPtr;

//Expected size is 0x000014
extern undefined4 gTRKFramingState;

undefined4 TRKTerminateSerialHandler(void);
undefined4 TRKInitializeSerialHandler(void);
void TRKProcessInput(undefined4 param_1);
void TRKGetInput(void);
int TRKTestForPacket(void);
}
