#pragma once
#include <ctypes.h>



namespace gx {
void GXSetTevIndirect(int param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,int param_7,uint param_8,byte param_9,int param_10);
void GXSetIndTexMtx(GXIndTexMtxID param_1,float (*param_2) [6],int param_3);
void GXSetIndTexCoordScale(int param_1,uint param_2,int param_3);
void GXSetIndTexOrder(int param_1,int param_2,uint param_3);
void GXSetNumIndStages(int param_1);
void GXSetTevDirect(undefined4 param_1);
void GXSetTevIndWarp(undefined4 param_1,undefined4 param_2,char param_3,char param_4,undefined4 param_5);
void __GXUpdateBPMask(undefined4 param_1,undefined4 param_2,uint param_3);
void __GXFlushTextureState(void);
}
