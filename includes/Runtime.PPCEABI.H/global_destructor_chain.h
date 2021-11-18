#pragma once
#include <ctypes.h>



namespace Runtime.PPCEABI.H {
//[BSS] Expected size is 0x000004
extern undefined4 __global_destructor_chain;
void __destroy_global_chain(void);
void __register_global_object(undefined4 param_1,undefined4 param_2,undefined4 *param_3);
}
