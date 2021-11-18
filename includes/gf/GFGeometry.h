#pragma once
#include <ctypes.h>



namespace gf {
//[Data] Expected size is 0x000004
extern undefined cm2hw$488;

void GFSetVtxDescv(undefined4 *param_1);
void GFSetVtxAttrFmtv(char param_1,int *param_2);
void GFSetArray(GXAttr param_1,int param_2,uint param_3);
void GFSetCullMode(int param_1);
}
