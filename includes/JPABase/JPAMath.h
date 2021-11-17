#pragma once
#include <ctypes.h>



namespace JPABase {
void JPAGetYZRotateMtx(uint param_1,uint param_2,float *param_3);
void JPAGetXYZRotateMtx(uint param_1,uint param_2,uint param_3,MTX34 *param_4);
void JPAGetDirMtx(cXyz *param_1,MTX34 *param_2);
void JPASetSVecfromMtx(float *param_1,float *param_2);
void JPASetRMtxTVecfromMtx(undefined4 param_1,undefined4 param_2,undefined4 param_3);
void JPASetRMtxSTVecfromMtx(float *param_1,MTX34 *param_2,float *param_3,float *param_4);
double JPAGetKeyFrameValue(double param_1,uint param_2,float *param_3);
void JPAGetUnitVec(uint param_1,uint param_2,float *param_3);
}
