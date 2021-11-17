#pragma once
#include <ctypes.h>



namespace MSL_C.PPCEABI.bare.H {
//Expected size is 0x000100
extern undefined __atexit_funcs;

//Expected size is 0x000004
extern undefined4 __aborting;

//Expected size is 0x000004
extern undefined4 __atexit_curr_func;

//Expected size is 0x000004
extern undefined4 __stdio_exit;

//Expected size is 0x000004
extern undefined4 __console_exit;

void exit(int __status);
}
