#pragma once
#include <ctypes.h>



namespace J3DGraphBase {
//[Data] Expected size is 0x000008
extern undefined PSMulUnit01;

//[Data] Expected size is 0x000008
extern undefined Unit01;

void __MTGQR7(void);
void J3DGQRSetup7(int param_1,int param_2,int param_3,int param_4);
double J3DCalcZValue(MTX34 *pMtx,cXyz *pPos);
void J3DCalcBBoardMtx(float *param_1);
void J3DCalcYBBoardMtx(float *param_1);
undefined4 J3DPSCalcInverseTranspose(int param_1,int param_2);
void J3DGetTranslateRotateMtx(int param_1,float *param_2);
void J3DGetTranslateRotateMtx(double param_1,double param_2,double param_3,uint param_4,uint param_5,uint param_6,float *param_7);
void J3DGetTextureMtx(float *param_1,float *param_2,float *param_3);
void J3DGetTextureMtxOld(float *param_1,float *param_2,float *param_3);
void J3DGetTextureMtxMaya(float *param_1,float *param_2);
void J3DGetTextureMtxMayaOld(float *param_1,float *param_2);
void J3DScaleNrmMtx(int param_1,int param_2);
void J3DScaleNrmMtx33(int param_1,int param_2);
void J3DMtxProjConcat(int param_1,int param_2,int param_3);
undefined8 J3DPSMtx33Copy(int param_1,int param_2);
void J3DPSMtx33CopyFrom34(int param_1,int param_2);
undefined8 J3DPSMtxArrayConcat(int param_1,int param_2,int param_3,int param_4);
}
