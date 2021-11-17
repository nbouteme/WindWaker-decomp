#pragma once
#include <ctypes.h>



namespace gx {
void GXSetTevOp(int param_1,int param_2);
void GXSetTevColorIn(GXTevStageID param_1,GXTevColorArg param_2,GXTevColorArg param_3,GXTevColorArg param_4,GXTevColorArg param_5);
void GXSetTevAlphaIn(GXTevStageID param_1,GXTevAlphaArg param_2,GXTevAlphaArg param_3,GXTevAlphaArg param_4,GXTevAlphaArg param_5);
void GXSetTevColorOp(GXTevStageID param_1,GXTevOp param_2,GXTevBias param_3,GXTevScale param_4,bool param_5,GXTevRegID param_6);
void GXSetTevAlphaOp(GXTevStageID param_1,GXTevOp param_2,GXTevBias param_3,GXTevScale param_4,bool param_5,GXTevRegID param_6);
void GXSetTevColor(GXTevRegID param_1,_GXColor *param_2);
void GXSetTevColorS10(GXTevRegID param_1,_GXColorS10 *param_2);
void GXSetTevKColor(int param_1,byte *param_2);
void GXSetTevKColorSel(uint param_1,int param_2);
void GXSetTevKAlphaSel(uint param_1,int param_2);
void GXSetTevSwapMode(int param_1,uint param_2,int param_3);
void GXSetTevSwapModeTable(int param_1,uint param_2,int param_3,uint param_4,int param_5);
void GXSetAlphaCompare(GXCompare param_1,byte param_2,GXAlphaOp param_3,GXCompare param_4,byte param_5);
void GXSetZTexture(uint param_1,int param_2,uint param_3);
void GXSetTevOrder(GXTevStageID param_1,GXTexCoordID param_2,GXTexMapID param_3,GXChannelID param_4);
void GXSetNumTevStages(uint param_1);
}
