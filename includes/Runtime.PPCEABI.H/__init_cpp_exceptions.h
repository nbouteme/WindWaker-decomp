#pragma once
#include <ctypes.h>



namespace Runtime.PPCEABI.H {
//[Data] Expected size is 0x000004
extern undefined4 fragmentID;

undefined4 GetR2(void);
void __fini_cpp_exceptions(void);
void __init_cpp_exceptions(void);
}
