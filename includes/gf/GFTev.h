#pragma once
#include <ctypes.h>



namespace gf {
void GFSetTevColor(GXTevRegID param_1,_GXColor *param_2);
void GFSetTevColorS10(GXTevRegID param_1,_GXColorS10 *param_2);
void GFSetAlphaCompare(int param_1,uint param_2,int param_3,int param_4,uint param_5);
}
