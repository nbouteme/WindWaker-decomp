#include <JPABase/JPAMath.h>
#include <JPABase/JPAMath.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <mtx/mtx.h>
#include <JMath/JMath.h>


namespace JPABase {

/* __stdcall JPAGetYZRotateMtx(short,
                               short,
                               float *[][][][]) */

void JPAGetYZRotateMtx(uint param_1,uint param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = (int)(param_1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar1 = JKernel::JMath::jmaCosTable[iVar5];
  iVar6 = (int)(param_2 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar2 = JKernel::JMath::jmaCosTable[iVar6];
  fVar3 = JKernel::JMath::jmaSinTable[iVar5];
  fVar4 = JKernel::JMath::jmaSinTable[iVar6];
  *param_3 = fVar1 * fVar2;
  param_3[1] = -fVar4;
  param_3[2] = fVar3 * fVar2;
  param_3[4] = fVar1 * fVar4;
  param_3[5] = fVar2;
  param_3[6] = fVar3 * fVar4;
  param_3[8] = -fVar3;
  param_3[10] = fVar1;
  fVar1 = _2176;
  param_3[0xb] = _2176;
  param_3[9] = fVar1;
  param_3[7] = fVar1;
  param_3[3] = fVar1;
  return;
}


/* __stdcall JPAGetXYZRotateMtx(short,
                                short,
                                short,
                                float *[][][][]) */

void JPAGetXYZRotateMtx(uint param_1,uint param_2,uint param_3,MTX34 *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar7 = (int)(param_1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar1 = JKernel::JMath::jmaCosTable[iVar7];
  iVar8 = (int)(param_2 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar2 = JKernel::JMath::jmaCosTable[iVar8];
  iVar9 = (int)(param_3 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar3 = JKernel::JMath::jmaCosTable[iVar9];
  fVar4 = JKernel::JMath::jmaSinTable[iVar7];
  fVar5 = JKernel::JMath::jmaSinTable[iVar8];
  fVar6 = JKernel::JMath::jmaSinTable[iVar9];
  param_4->m[0] = fVar2 * fVar3;
  param_4->m[1][0] = fVar2 * fVar6;
  param_4->m[2][0] = -fVar5;
  param_4->m[2][1] = fVar4 * fVar2;
  param_4->m[2][2] = fVar1 * fVar2;
  param_4->m[1] = fVar4 * fVar3 * fVar5 - fVar1 * fVar6;
  param_4->m[1][2] = fVar1 * fVar6 * fVar5 - fVar4 * fVar3;
  param_4->m[2] = fVar4 * fVar6 + fVar1 * fVar3 * fVar5;
  param_4->m[1][1] = fVar1 * fVar3 + fVar4 * fVar6 * fVar5;
  fVar1 = _2176;
  param_4->m[2][3] = _2176;
  param_4->m[1][3] = fVar1;
  param_4->m[3] = fVar1;
  return;
}


/* __stdcall JPAGetDirMtx(JGeometry::TVec3<float><float> const &,
                          float *[][][][]) */

void JPAGetDirMtx(cXyz *param_1,MTX34 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar7 = _2155;
  fVar1 = param_1->y;
  fVar3 = -param_1->x;
  fVar2 = param_1->z;
  fVar4 = _2176 + fVar1 * fVar1 + fVar3 * fVar3;
  if (_2176 < fVar4) {
    fVar5 = 1.0 / SQRT(fVar4);
    fVar4 = fVar4 * _2230 * fVar5 * (_2231 - fVar4 * fVar5 * fVar5);
  }
  fVar5 = _2176;
  fVar6 = _2176;
  if (_2232 < fVar4) {
    fVar5 = fVar1 * (_2155 / fVar4);
    fVar6 = fVar3 * (_2155 / fVar4);
  }
  param_2->m[0] = fVar5 * fVar5 + fVar2 * (_2155 - fVar5 * fVar5);
  fVar1 = fVar5 * fVar6 * (fVar7 - fVar2);
  param_2->m[1] = fVar1;
  param_2->m[2] = -fVar6 * fVar4;
  fVar3 = _2176;
  param_2->m[3] = _2176;
  param_2->m[1][0] = fVar1;
  param_2->m[1][1] = fVar6 * fVar6 + fVar2 * (fVar7 - fVar6 * fVar6);
  param_2->m[1][2] = fVar5 * fVar4;
  param_2->m[1][3] = fVar3;
  param_2->m[2][0] = fVar6 * fVar4;
  param_2->m[2][1] = -fVar5 * fVar4;
  param_2->m[2][2] = fVar2;
  param_2->m[2][3] = fVar3;
  return;
}


/* __stdcall JPASetSVecfromMtx(float *[][][][],
                               JGeometry::TVec3<float><float>&) */

void JPASetSVecfromMtx(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = param_1[8] * param_1[8] + *param_1 * *param_1 + param_1[4] * param_1[4];
  if (_2176 < fVar1) {
    fVar2 = 1.0 / SQRT(fVar1);
    fVar1 = fVar1 * _2230 * fVar2 * (_2231 - fVar1 * fVar2 * fVar2);
  }
  *param_2 = fVar1;
  fVar1 = param_1[9] * param_1[9] + param_1[1] * param_1[1] + param_1[5] * param_1[5];
  if (_2176 < fVar1) {
    fVar2 = 1.0 / SQRT(fVar1);
    fVar1 = fVar1 * _2230 * fVar2 * (_2231 - fVar1 * fVar2 * fVar2);
  }
  param_2[1] = fVar1;
  fVar1 = param_1[10] * param_1[10] + param_1[2] * param_1[2] + param_1[6] * param_1[6];
  if (_2176 < fVar1) {
    fVar2 = 1.0 / SQRT(fVar1);
    fVar1 = fVar1 * _2230 * fVar2 * (_2231 - fVar1 * fVar2 * fVar2);
  }
  param_2[2] = fVar1;
  return;
}


/* __stdcall JPASetRMtxTVecfromMtx(float *[][][][],
                                   float *[][][][],
                                   JGeometry::TVec3<float><float>&) */

void JPASetRMtxTVecfromMtx(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined auStack24 [24];
  
  JPASetRMtxSTVecfromMtx(param_1,param_2,auStack24,param_3);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall JPASetRMtxSTVecfromMtx(float *[][][][],
                                    float *[][][][],
                                    JGeometry::TVec3<float><float>&,
                                    JGeometry::TVec3<float><float>&) */

void JPASetRMtxSTVecfromMtx(float *param_1,MTX34 *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  
  JPASetSVecfromMtx(param_1,param_3);
  mtx::PSMTXIdentity(param_2);
  if (_2176 != *param_3) {
    fVar1 = _2155 / *param_3;
    param_2->m[0] = *param_1 * fVar1;
    param_2->m[1][0] = param_1[4] * fVar1;
    param_2->m[2][0] = param_1[8] * fVar1;
  }
  if (_2176 != param_3[1]) {
    fVar1 = _2155 / param_3[1];
    param_2->m[1] = param_1[1] * fVar1;
    param_2->m[1][1] = param_1[5] * fVar1;
    param_2->m[2][1] = param_1[9] * fVar1;
  }
  if (_2176 != param_3[2]) {
    fVar1 = _2155 / param_3[2];
    param_2->m[2] = param_1[2] * fVar1;
    param_2->m[1][2] = param_1[6] * fVar1;
    param_2->m[2][2] = param_1[10] * fVar1;
  }
  fVar1 = param_1[0xb];
  fVar2 = param_1[7];
  *param_4 = param_1[3];
  param_4[1] = fVar2;
  param_4[2] = fVar1;
  return;
}


/* __stdcall JPAGetKeyFrameValue(float,
                                 unsigned short,
                                 float const *) */

double JPAGetKeyFrameValue(double param_1,uint param_2,float *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  double dVar4;
  
  if ((double)*param_3 <= param_1) {
    iVar1 = (param_2 & 0xffff) - 1;
    uVar3 = param_2 & 0xffff;
    if (param_1 < (double)param_3[iVar1 * 4]) {
      while (uVar2 = uVar3, 1 < (int)uVar2) {
        uVar3 = ((int)uVar2 >> 1) + (uint)((int)uVar2 < 0 && (uVar2 & 1) != 0);
        if ((double)param_3[uVar3 * 4] <= param_1) {
          param_3 = param_3 + uVar3 * 4;
          uVar3 = uVar2 - uVar3;
        }
      }
      dVar4 = (double)JKernel::JMath::JMAHermiteInterpolation
                                (param_1,(double)*param_3,(double)param_3[1],(double)param_3[3],
                                 (double)param_3[4],(double)param_3[5],(double)param_3[6]);
    }
    else {
      dVar4 = (double)param_3[iVar1 * 4 + 1];
    }
  }
  else {
    dVar4 = (double)param_3[1];
  }
  return dVar4;
}


/* __stdcall JPAGetUnitVec(short,
                           short,
                           JGeometry::TVec3<float><float>&) */

void JPAGetUnitVec(uint param_1,uint param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = JKernel::JMath::jmaSinTable
          [(int)(param_1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
  *param_3 = fVar1 * JKernel::JMath::jmaCosTable
                     [(int)(param_2 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
  param_3[1] = fVar1 * JKernel::JMath::jmaSinTable
                       [(int)(param_2 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
  param_3[2] = JKernel::JMath::jmaCosTable
               [(int)(param_1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
  return;
}

