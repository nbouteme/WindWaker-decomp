#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x00000c
extern pointer J2DPrint;

//[BSS] Expected size is 0x000004
extern char * J2DPrint;
//[BSS] Expected size is 0x000001
extern undefined1 J2DPrint;
//[BSS] Expected size is 0x000004
extern int J2DPrint;
//[BSS] Expected size is 0x000001
extern undefined1 J2DPrint;

namespace J2DPrint {
char * setBuffer(ulong param_1);
}
