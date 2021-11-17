#pragma once
#include <ctypes.h>



namespace os {
//Expected size is 0x000054
extern undefined2 Scb;

void WriteSramCallback(void);
uint WriteSram(undefined4 param_1,int param_2,undefined4 param_3);
void __OSInitSram(void);
undefined2 * __OSLockSram(void);
undefined2 * __OSLockSramEx(void);
uint UnlockSram(int param_1,uint param_2);
void __OSUnlockSram(undefined4 param_1);
void __OSUnlockSramEx(undefined4 param_1);
undefined4 __OSSyncSram(void);
bool OSGetSoundMode(void);
void OSSetSoundMode(uint param_1);
byte OSGetProgressiveMode(void);
void OSSetProgressiveMode(uint param_1);
undefined2 OSGetWirelessID(int param_1);
void OSSetWirelessID(int param_1,short param_2);
}
