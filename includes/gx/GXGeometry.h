#pragma once
#include <ctypes.h>



namespace gx {
void __GXSetDirtyState(void);
void GXBegin(byte param_1,byte param_2,undefined2 param_3);
void __GXSendFlushPrim(void);
void GXSetLineWidth(uint param_1,int param_2);
void GXSetPointSize(uint param_1,int param_2);
void GXEnableTexOffsets(int param_1,uint param_2,uint param_3);
void GXSetCullMode(int param_1);
void GXSetCoPlanar(uint param_1);
void __GXSetGenMode(void);
}
