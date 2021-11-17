#pragma once
#include <ctypes.h>



namespace gba {
void __GBAHandler(int param_1,uint param_2,undefined4 param_3);
void __GBASyncCallback(int param_1);
undefined4 __GBASync(int param_1);
void TypeAndStatusCallback(int param_1,uint param_2);
undefined4 __GBATransfer(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
undefined8 __GBASetDelay(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
}
