#pragma once
#include <ctypes.h>


//Expected size is 0x000004
extern char * J2DPrint;

//Expected size is 0x000001
extern undefined1 J2DPrint;

//Expected size is 0x000004
extern int J2DPrint;

//Expected size is 0x000001
extern undefined1 J2DPrint;


namespace J2DPrint {
char * setBuffer(ulong param_1);
}
