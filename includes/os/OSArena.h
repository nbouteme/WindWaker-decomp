#pragma once
#include <ctypes.h>



namespace os {
//[Data] Expected size is 0x000004
extern undefined4 __OSArenaLo;

//[BSS] Expected size is 0x000004
extern undefined4 __OSArenaHi;
undefined4 OSGetArenaHi(void);
undefined4 OSGetArenaLo(void);
void OSSetArenaHi(undefined4 param_1);
void OSSetArenaLo(undefined4 param_1);
uint OSAllocFromArenaLo(int param_1,int param_2);
}
