#pragma once
#include <ctypes.h>



namespace gba {
void ReadProc(int param_1);
undefined4 GBAReadAsync(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void GBARead(int param_1,undefined4 param_2,undefined4 param_3);
}
