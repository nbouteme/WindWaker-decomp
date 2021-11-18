#pragma once
#include <ctypes.h>



namespace gd {
//[BSS] Expected size is 0x000004
extern undefined4 __GDCurrentDL;
//[BSS] Expected size is 0x000004
extern undefined4 overflowcb;
void GDInitGDLObj(int *param_1,int param_2,int param_3);
void GDFlushCurrToMem(void);
void GDPadCurr32(void);
void GDOverflowed(void);
}
