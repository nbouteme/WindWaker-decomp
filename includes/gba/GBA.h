#pragma once
#include <ctypes.h>



namespace gba {
//Expected size is 0x000100
extern undefined SecParams;

//Expected size is 0x000400
extern undefined __GBA;

//Expected size is 0x000004
extern undefined4 __GBAReset;

void ShortCommandProc(int param_1);
void GBAInit(void);
undefined4 GBAGetStatusAsync(int param_1,undefined4 param_2,undefined4 param_3);
void GBAGetStatus(int param_1,undefined4 param_2);
undefined4 GBAResetAsync(int param_1,undefined4 param_2,undefined4 param_3);
void GBAReset(int param_1,undefined4 param_2);
undefined4 OnReset(void);
}
