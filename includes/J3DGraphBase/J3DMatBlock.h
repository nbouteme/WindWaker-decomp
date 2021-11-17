#pragma once
#include <ctypes.h>



namespace J3DGraphBase {
//Expected size is 0x000004
extern undefined4 SizeOfJ3DColorBlockLightOffLoad;

//Expected size is 0x000004
extern undefined4 SizeOfJ3DColorBlockAmbientOnLoad;

}

namespace J3DGraphBase {
void J3DGDLoadTexMtxImm(undefined4 *param_1,uint param_2,int param_3);
}

namespace J3DGraphBase {
void __sinit_J3DMatBlock_cpp(void);
}
