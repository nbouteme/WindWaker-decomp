#pragma once
#include <ctypes.h>

#include <JSUPtrList.h>

//[Data] Expected size is 0x000024
extern undefined1 JKRDvdFile;

//[BSS] Expected size is 0x00000c
extern struct JSUPtrList JKRDvdFile;

namespace JKernel {
void __sinit_JKRDvdFile_cpp(void);
}
