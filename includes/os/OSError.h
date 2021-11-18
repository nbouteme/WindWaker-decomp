#pragma once
#include <ctypes.h>



namespace os {
//[Data] Expected size is 0x000004
extern undefined4 __OSFpscrEnableBits;

//[BSS] Expected size is 0x000044
extern undefined __OSErrorTable;
int OSSetErrorHandler(ushort param_1,int param_2);
void __OSUnhandledException(byte param_1,int param_2,undefined4 param_3,undefined4 param_4);
}
