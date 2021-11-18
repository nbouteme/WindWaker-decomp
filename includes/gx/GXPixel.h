#pragma once
#include <ctypes.h>



namespace gx {
//[Data] Expected size is 0x000020
extern undefined p2f$247;

void GXSetFog(_GXFogType param_1,float param_2,float param_3,float param_4,float param_5,_GXColor *param_6);
void GXSetFogRangeAdj(bool param_1,u16 param_2,_GXFogAdjTable *param_3);
void GXSetBlendMode(GXBlendMode param_1,GXBlendFactor param_2,GXBlendFactor param_3,GXLogicOp param_4);
void GXSetColorUpdate(bool param_1);
void GXSetAlphaUpdate(uint param_1);
void GXSetZMode(bool param_1,GXCompare param_2,bool param_3);
void GXSetZCompLoc(uint param_1);
void GXSetPixelFmt(int param_1,int param_2);
void GXSetDither(uint param_1);
void GXSetDstAlpha(uint param_1,uint param_2);
void GXSetFieldMask(uint param_1,uint param_2);
void GXSetFieldMode(uint param_1,uint param_2);
}
