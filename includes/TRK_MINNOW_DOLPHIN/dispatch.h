#pragma once
#include <ctypes.h>



namespace TRK_MINNOW_DOLPHIN {
//Expected size is 0x000004
extern undefined4 gTRKDispatchTableSize;

undefined4 TRKDispatchMessage(undefined4 param_1);
undefined4 TRKInitializeDispatcher(void);
}
