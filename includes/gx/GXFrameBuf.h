#pragma once
#include <ctypes.h>



namespace gx {
void GXSetDispCopySrc(uint param_1,uint param_2,uint param_3,uint param_4);
void GXSetTexCopySrc(uint param_1,uint param_2,uint param_3,uint param_4);
void GXSetDispCopyDst(uint param_1);
void GXSetTexCopyDst(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4);
void GXSetDispCopyFrame2Field(int param_1);
void GXSetCopyClamp(uint param_1);
uint GXGetNumXfbLines(double param_1,uint param_2);
double GXGetYScaleFactor(uint param_1,uint param_2);
uint GXSetDispCopyYScale(double param_1);
void GXSetCopyClear(undefined *param_1,uint param_2);
void GXSetCopyFilter(char param_1,byte *param_2,char param_3,byte *param_4);
void GXSetDispCopyGamma(int param_1);
void GXCopyDisp(uint param_1,byte param_2);
void GXCopyTex(uint param_1,byte param_2);
void GXClearBoundingBox(void);
}
