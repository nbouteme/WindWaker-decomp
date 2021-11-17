#pragma once
#include <ctypes.h>



namespace os {
undefined4 OSGetConsoleSimulatedMemSize(void);
undefined4 OnReset(int param_1);
void MEMIntrruptHandler(undefined4 param_1,undefined4 param_2);
void OSProtectRange(uint param_1,uint param_2,int param_3,uint param_4);
void Config24MB(void);
void Config48MB(void);
uint RealMode(void);
void __OSInitMemoryProtection(void);
}
