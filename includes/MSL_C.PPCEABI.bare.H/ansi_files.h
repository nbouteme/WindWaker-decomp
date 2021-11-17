#pragma once
#include <ctypes.h>



namespace MSL_C.PPCEABI.bare.H {
//Expected size is 0x000100
extern undefined stderr_buff;

//Expected size is 0x000100
extern undefined stdout_buff;

//Expected size is 0x000100
extern undefined stdin_buff;

undefined4 __flush_all(void);
void __close_all(void);
}
