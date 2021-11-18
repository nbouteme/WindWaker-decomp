#pragma once
#include <ctypes.h>



namespace os {
//[BSS] Expected size is 0x000008
extern undefined4 ResetFunctionQueue;
void OSRegisterResetFunction(int param_1);
void Reset(void);
void __OSDoHotReset(int param_1);
void OSResetSystem(int param_1,int param_2,int param_3);
uint OSGetResetCode(void);
}
