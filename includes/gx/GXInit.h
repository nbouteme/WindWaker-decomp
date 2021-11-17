#pragma once
#include <ctypes.h>



namespace gx {
//Expected size is 0x0004f8
extern undefined gxData;

//Expected size is 0x000080
extern undefined FifoObj;

//Expected size is 0x000004
extern undefined4 __piReg;

//Expected size is 0x000004
extern undefined4 __cpReg;

//Expected size is 0x000004
extern undefined4 __peReg;

//Expected size is 0x000004
extern undefined4 __memReg;

int __GXDefaultTexRegionCallback(void);
int __GXDefaultTlutRegionCallback(uint param_1);
undefined * GXInit(undefined4 param_1,undefined4 param_2);
void __GXInitGX(void);
}
