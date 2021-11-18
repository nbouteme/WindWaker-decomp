#pragma once
#include <ctypes.h>



namespace MSL_C.PPCEABI.bare.H {
//[Data] Expected size is 0x000140
extern undefined __files;

//[BSS] Expected size is 0x000100
extern undefined stderr_buff;
//[BSS] Expected size is 0x000100
extern undefined stdout_buff;
//[BSS] Expected size is 0x000100
extern undefined stdin_buff;
undefined4 __flush_all(void);
void __close_all(void);
}
