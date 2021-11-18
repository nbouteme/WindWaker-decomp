#pragma once
#include <ctypes.h>



namespace gx {
//[Data] Expected size is 0x0000d0
extern undefined GXDefaultVATList;

//[Data] Expected size is 0x00001c
extern undefined GXDefaultProjData;

//[Data] Expected size is 0x000004
extern undefined4 __GXVersion;

//[BSS] Expected size is 0x0004f8
extern undefined gxData;
//[BSS] Expected size is 0x000080
extern undefined FifoObj;
//[BSS] Expected size is 0x000004
extern undefined4 __piReg;
//[BSS] Expected size is 0x000004
extern undefined4 __cpReg;
//[BSS] Expected size is 0x000004
extern undefined4 __peReg;
//[BSS] Expected size is 0x000004
extern undefined4 __memReg;
int __GXDefaultTexRegionCallback(void);
int __GXDefaultTlutRegionCallback(uint param_1);
undefined * GXInit(undefined4 param_1,undefined4 param_2);
void __GXInitGX(void);
}
