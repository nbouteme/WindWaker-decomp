#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x000078
extern undefined1 J3DPEBlockFull;

//[Data] Expected size is 0x000078
extern undefined1 J3DPEBlockFogOff;

//[Data] Expected size is 0x0000dc
extern undefined1 J3DTevBlock16;

//[Data] Expected size is 0x0000dc
extern undefined1 J3DTevBlock4;

//[Data] Expected size is 0x0000dc
extern undefined1 J3DTevBlock2;

//[Data] Expected size is 0x0000dc
extern undefined1 J3DTevBlock1;

//[Data] Expected size is 0x0000dc
extern pointer J3DTevBlockPatched;

//[Data] Expected size is 0x000060
extern undefined1 J3DTexGenBlockBasic;

//[Data] Expected size is 0x000060
extern pointer J3DTexGenBlock4;

//[Data] Expected size is 0x000060
extern pointer J3DTexGenBlockPatched;

//[Data] Expected size is 0x000088
extern undefined1 J3DColorBlockLightOn;

//[Data] Expected size is 0x000088
extern undefined1 J3DColorBlockAmbientOn;

//[Data] Expected size is 0x000078
extern undefined1 J3DPEBlockXlu;

//[Data] Expected size is 0x000078
extern undefined1 J3DPEBlockTexEdge;

//[Data] Expected size is 0x000078
extern undefined1 J3DPEBlockOpa;

//[Data] Expected size is 0x00004c
extern undefined1 J3DIndBlockFull;

//[Data] Expected size is 0x0000dc
extern pointer J3DTevBlock;

//[Data] Expected size is 0x000088
extern undefined1 J3DColorBlockLightOff;


namespace J3DGraphBase {
//[Data] Expected size is 0x000004
extern undefined4 SizeOfLoadMatColors;

//[Data] Expected size is 0x000004
extern undefined4 SizeOfLoadAmbColors;

//[Data] Expected size is 0x000004
extern undefined4 SizeOfLoadColorChans;

//[BSS] Expected size is 0x000004
extern undefined4 SizeOfJ3DColorBlockLightOffLoad;
//[BSS] Expected size is 0x000004
extern undefined4 SizeOfJ3DColorBlockAmbientOnLoad;
}

namespace J3DGraphBase {
void J3DGDLoadTexMtxImm(undefined4 *param_1,uint param_2,int param_3);
}

namespace J3DGraphBase {
void __sinit_J3DMatBlock_cpp(void);
}
