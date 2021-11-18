#pragma once
#include <ctypes.h>



namespace J3DDrawBuffer {
//[Data] Expected size is 0x000048
extern undefined1 sortFuncTable;

//[Data] Expected size is 0x000018
extern undefined1 drawFuncTable;

//[BSS] Expected size is 0x000004
extern undefined1 entryNum;
}

namespace J3DGraphBase {
void __sinit_J3DDrawBuffer_cpp(void);
}
