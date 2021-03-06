#pragma once
#include <ctypes.h>

#include <Demangler/JGeometry/TVec3<float>.h>
#include <J3DSys.h>
#include <MTX34.h>


namespace J3DGraphBase {
//[Data] Expected size is 0x000010
extern undefined NullTexData;

//[Data] Expected size is 0x000030
extern undefined j3dIdentityMtx;

//[Data] Expected size is 0x000018
extern undefined IndMtx;

//[Data] Expected size is 0x000004
extern undefined4 ColorBlack;

//[Data] Expected size is 0x000004
extern undefined4 ColorWhite;

//[BSS] Expected size is 0x000128
extern struct J3DSys j3dSys;
}
//[BSS] Expected size is 0x000030
extern struct MTX34 J3DSys;
//[BSS] Expected size is 0x00000c
extern struct TVec3<float> J3DSys;
//[BSS] Expected size is 0x00000c
extern struct TVec3<float> J3DSys;
//[BSS] Expected size is 0x000040
extern undefined1 J3DSys;

namespace J3DGraphBase {
//[BSS] Expected size is 0x000004
extern undefined j3dDefaultViewNo;
}

namespace J3DGraphBase {
void J3DFifoLoadPosMtxImm(undefined4 *param_1,int param_2);
void J3DFifoLoadNrmMtxImm(undefined4 *param_1,short param_2);
void J3DFifoLoadNrmMtxImm3x3(undefined4 *param_1,short param_2);
}

namespace J3DGraphBase {
void __sinit_J3DSys_cpp(void);
}
