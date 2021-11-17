#pragma once
#include <ctypes.h>



namespace os {
//Expected size is 0x000004
extern undefined4 ResetCallback;

//Expected size is 0x000004
extern undefined4 Down;

//Expected size is 0x000004
extern undefined4 LastState;

//Expected size is 0x000008
extern undefined4 HoldUp;

//Expected size is 0x000008
extern undefined4 HoldDown;

void __OSResetSWInterruptHandler(void);
uint OSGetResetButtonState(void);
void OSGetResetSwitchState(void);
}
