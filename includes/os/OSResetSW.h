#pragma once
#include <ctypes.h>



namespace os {
//[BSS] Expected size is 0x000004
extern undefined4 ResetCallback;
//[BSS] Expected size is 0x000004
extern undefined4 Down;
//[BSS] Expected size is 0x000004
extern undefined4 LastState;
//[BSS] Expected size is 0x000008
extern undefined4 HoldUp;
//[BSS] Expected size is 0x000008
extern undefined4 HoldDown;
void __OSResetSWInterruptHandler(void);
uint OSGetResetButtonState(void);
void OSGetResetSwitchState(void);
}
