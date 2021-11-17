#pragma once
#include <ctypes.h>



namespace dvd {
//Expected size is 0x00003f
extern undefined bb2Buf;

//Expected size is 0x000030
extern undefined block$18;

//Expected size is 0x000004
extern undefined4 status;

//Expected size is 0x000004
extern undefined4 bb2;

//Expected size is 0x000004
extern undefined4 idTmp;

void cb(int param_1,undefined4 param_2);
void __fstLoad(void);
}
