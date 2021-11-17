#pragma once
#include <ctypes.h>



namespace mtx {
void PSVECAdd(cXyz *param_1,cXyz *param_2,cXyz *param_3);
void PSVECSubtract(cXyz *param_1,cXyz *param_2,cXyz *param_3);
void PSVECScale(cXyz *param_1_00,cXyz *param_2,float param_3);
void C_VECNormalize(float *param_1,float *param_2);
double PSVECNormalize(int param_1,int param_2);
float PSVECSquareMag(cXyz *param_1);
float PSVECMag(cXyz *param_1);
undefined8 PSVECDotProduct(int param_1,int param_2);
void PSVECCrossProduct(TVec3<float> *param_1,TVec3<float> *param_2,TVec3<float> *param_3);
void C_VECHalfAngle(cXyz *param_1,cXyz *param_2,cXyz *param_3);
void C_VECReflect(float *param_1,undefined4 param_2,float *param_3);
float PSVECSquareDistance(cXyz *param_1,cXyz *param_2);
float PSVECDistance(cXyz *param_1,cXyz *param_2);
}
