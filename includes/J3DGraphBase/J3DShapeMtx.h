#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x000030
extern undefined1 J3DShapeMtx;

//[Data] Expected size is 0x000030
extern undefined1 J3DShapeMtxImm;

//[Data] Expected size is 0x000030
extern undefined1 J3DShapeMtxConcatView;

//[Data] Expected size is 0x00000c
extern undefined1 J3DShapeDraw;

//[Data] Expected size is 0x000024
extern undefined1 J3DShapeMtxYBBoardConcatView;

//[Data] Expected size is 0x000024
extern undefined1 J3DShapeMtxYBBoardImm;

//[Data] Expected size is 0x000024
extern undefined1 J3DShapeMtxBBoardConcatView;

//[Data] Expected size is 0x000024
extern undefined1 J3DShapeMtxBBoardImm;

//[Data] Expected size is 0x000028
extern undefined1 J3DShapeMtxMultiConcatView;

//[Data] Expected size is 0x000024
extern undefined1 J3DShapeMtxMultiImm;

//[Data] Expected size is 0x000020
extern undefined1 J3DShapeMtxMulti;

//[Data] Expected size is 0x000028
extern undefined1 J3DShapeMtxConcatView;

//[Data] Expected size is 0x000024
extern undefined1 J3DShapeMtxImm;

//[Data] Expected size is 0x000020
extern undefined1 J3DShapeMtx;

//[BSS] Expected size is 0x000004
extern undefined1 J3DShapeMtx;
//[BSS] Expected size is 0x000004
extern uint J3DShapeMtx;
//[BSS] Expected size is 0x000001
extern undefined1 J3DShapeMtx;
//[BSS] Expected size is 0x000008
extern struct MTX34 * J3DShapeMtxConcatView[3];

namespace J3DGraphBase {
void __sinit_J3DShapeMtx_cpp(void);
}
