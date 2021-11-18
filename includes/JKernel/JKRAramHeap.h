#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x00000c
extern undefined1 JKRAramHeap;

//[BSS] Expected size is 0x00000c
extern undefined1 JKRAramHeap;

namespace JKernel {
void __sinit_JKRAramHeap_cpp(void);
}
