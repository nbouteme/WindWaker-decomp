#pragma once
#include <ctypes.h>



namespace MSL_C.PPCEABI.bare.H {
//[BSS] Expected size is 0x000100
extern undefined __atexit_funcs;
//[BSS] Expected size is 0x000004
extern undefined4 __aborting;
//[BSS] Expected size is 0x000004
extern undefined4 __atexit_curr_func;
//[BSS] Expected size is 0x000004
extern undefined4 __stdio_exit;
//[BSS] Expected size is 0x000004
extern undefined4 __console_exit;
void exit(int __status);
}
