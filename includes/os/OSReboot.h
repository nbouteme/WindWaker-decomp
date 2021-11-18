#pragma once
#include <ctypes.h>



namespace os {
//[BSS] Expected size is 0x000020
extern undefined Header;
//[BSS] Expected size is 0x000004
extern undefined4 SaveStart;
//[BSS] Expected size is 0x000004
extern undefined4 SaveEnd;
//[BSS] Expected size is 0x000004
extern undefined4 Prepared;
void Run(void);
void Callback(void);
void __OSReboot(void);
void OSSetSaveRegion(undefined4 param_1,undefined4 param_2);
}
