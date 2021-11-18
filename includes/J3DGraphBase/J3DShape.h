#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x000018
extern undefined1 J3DShape;

//[BSS] Expected size is 0x000004
extern byte J3DShape;
//[BSS] Expected size is 0x000001
extern byte J3DShape;

namespace J3DGraphBase {
void J3DLoadCPCmd(undefined param_1,undefined4 param_2);
void J3DLoadArrayBasePtr(int param_1,uint param_2);
}
