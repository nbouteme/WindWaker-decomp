#pragma once
#include <ctypes.h>



namespace gba {
void WriteProc(int param_1);
undefined4 GBAWriteAsync(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4);
void GBAWrite(int param_1,byte *param_2,undefined4 param_3);
}
