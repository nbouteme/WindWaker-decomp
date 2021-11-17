#pragma once
#include <ctypes.h>



namespace J3DGraphBase {
void J3DGDSetGenMode(uint param_1,uint param_2,uint param_3,byte param_4,int param_5);
void J3DGDSetGenMode_3Param(undefined param_1,uint param_2,byte param_3);
void J3DGDSetIndTexStageNum(undefined4 param_1);
void J3DGDSetLightAttn(double param_1,double param_2,double param_3,double param_4,double param_5,double param_6,undefined4 param_7);
void J3DGDSetLightColor(undefined4 param_1,undefined *param_2);
void J3DGDSetLightPos(double param_1,double param_2,double param_3,undefined4 param_4);
void J3DGDSetLightDir(double param_1,double param_2,double param_3,undefined4 param_4);
void J3DGDSetVtxAttrFmtv(char param_1,int *param_2,char param_3);
void J3DGDSetTexCoordGen(int param_1,int param_2);
void J3DGDSetTexCoordScale2(char param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,uint param_7);
void J3DGDSetTexLookupMode(double param_1,double param_2,double param_3,int param_4,uint param_5,int param_6,int param_7,int param_8,uint param_9,uint param_10,int param_11);
void J3DGDSetTexImgAttr(int param_1,uint param_2,uint param_3,int param_4);
void J3DGDSetTexImgPtr(int param_1,int param_2);
void J3DGDSetTexImgPtrRaw(int param_1,undefined4 param_2);
void J3DGDSetTexTlut(int param_1,int param_2,int param_3);
void J3DGDLoadTlut(int param_1,int param_2,int param_3);
void J3DGDSetIndTexMtx(int param_1,float *param_2,char param_3);
void J3DGDSetIndTexCoordScale(int param_1,uint param_2,int param_3,int param_4,int param_5);
void J3DGDSetIndTexOrder(int param_1,int param_2,uint param_3,int param_4,uint param_5,uint param_6,uint param_7,int param_8,uint param_9);
void J3DGDSetTevOrder(uint param_1,int param_2,uint param_3,uint param_4,int param_5,uint param_6,uint param_7);
void J3DGDSetTevKColor(char param_1,undefined *param_2);
void J3DGDSetTevColorS10(char param_1,short *param_2);
void J3DGDSetFog(double param_1,double param_2,double param_3,double param_4,int param_5,undefined *param_6);
void J3DGDSetFogRangeAdj(byte param_1,uint param_2,int param_3);
}
