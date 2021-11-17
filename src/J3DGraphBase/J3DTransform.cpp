#include <J3DGraphBase/J3DTransform.h>
#include <J3DGraphBase/J3DTransform.h>
#include <mtx/vec.h>


namespace J3DGraphBase {

/* __stdcall __MTGQR7(unsigned long) */

void __MTGQR7(void)

{
  return;
}


/* __stdcall J3DGQRSetup7(unsigned long,
                          unsigned long,
                          unsigned long,
                          unsigned long) */

void J3DGQRSetup7(int param_1,int param_2,int param_3,int param_4)

{
  __MTGQR7((param_1 * 0x100 + param_2) * 0x10000 | param_3 * 0x100 + param_4);
  return;
}


/* __stdcall J3DCalcZValue(float *[][][][],
                           Vec) */

double J3DCalcZValue(MTX34 *pMtx,cXyz *pPos)

{
  return (double)(pMtx->m[2][3] +
                 pMtx->m[2][2] * pPos->z + pMtx->m[2][0] * pPos->x + pMtx->m[2][1] * pPos->y);
}


/* __stdcall J3DCalcBBoardMtx(float *[][][][]) */

void J3DCalcBBoardMtx(float *param_1)

{
  float fVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  
  dVar2 = (double)(param_1[8] * param_1[8] + *param_1 * *param_1 + param_1[4] * param_1[4]);
  if ((double)_1404 < dVar2) {
    dVar3 = 1.0 / SQRT(dVar2);
    dVar3 = _1405 * dVar3 * (_1406 - dVar2 * dVar3 * dVar3);
    dVar3 = _1405 * dVar3 * (_1406 - dVar2 * dVar3 * dVar3);
    dVar2 = (double)(float)(dVar2 * _1405 * dVar3 * (_1406 - dVar2 * dVar3 * dVar3));
  }
  dVar3 = (double)(param_1[9] * param_1[9] + param_1[1] * param_1[1] + param_1[5] * param_1[5]);
  if ((double)_1404 < dVar3) {
    dVar4 = 1.0 / SQRT(dVar3);
    dVar4 = _1405 * dVar4 * (_1406 - dVar3 * dVar4 * dVar4);
    dVar4 = _1405 * dVar4 * (_1406 - dVar3 * dVar4 * dVar4);
    dVar3 = (double)(float)(dVar3 * _1405 * dVar4 * (_1406 - dVar3 * dVar4 * dVar4));
  }
  dVar4 = (double)(param_1[10] * param_1[10] + param_1[2] * param_1[2] + param_1[6] * param_1[6]);
  if ((double)_1404 < dVar4) {
    dVar5 = 1.0 / SQRT(dVar4);
    dVar5 = _1405 * dVar5 * (_1406 - dVar4 * dVar5 * dVar5);
    dVar5 = _1405 * dVar5 * (_1406 - dVar4 * dVar5 * dVar5);
    dVar4 = (double)(float)(dVar4 * _1405 * dVar5 * (_1406 - dVar4 * dVar5 * dVar5));
  }
  *param_1 = (float)dVar2;
  fVar1 = _1404;
  param_1[1] = _1404;
  param_1[2] = fVar1;
  param_1[4] = fVar1;
  param_1[5] = (float)dVar3;
  param_1[6] = fVar1;
  param_1[8] = fVar1;
  param_1[9] = fVar1;
  param_1[10] = (float)dVar4;
  return;
}


/* WARNING: Removing unreachable block (ram,0x802da560) */
/* WARNING: Removing unreachable block (ram,0x802da558) */
/* WARNING: Removing unreachable block (ram,0x802da568) */
/* __stdcall J3DCalcYBBoardMtx(float *[][][][]) */

void J3DCalcYBBoardMtx(float *param_1)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar5;
  TVec3_float_ local_5c;
  TVec3_float_ local_50;
  TVec3_float_ local_44;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  dVar5 = (double)(param_1[8] * param_1[8] + *param_1 * *param_1 + param_1[4] * param_1[4]);
  if ((double)_1404 < dVar5) {
    dVar2 = 1.0 / SQRT(dVar5);
    dVar2 = _1405 * dVar2 * (_1406 - dVar5 * dVar2 * dVar2);
    dVar2 = _1405 * dVar2 * (_1406 - dVar5 * dVar2 * dVar2);
    dVar5 = (double)(float)(dVar5 * _1405 * dVar2 * (_1406 - dVar5 * dVar2 * dVar2));
  }
  dVar2 = (double)(param_1[9] * param_1[9] + param_1[1] * param_1[1] + param_1[5] * param_1[5]);
  if ((double)_1404 < dVar2) {
    dVar3 = 1.0 / SQRT(dVar2);
    dVar3 = _1405 * dVar3 * (_1406 - dVar2 * dVar3 * dVar3);
    dVar3 = _1405 * dVar3 * (_1406 - dVar2 * dVar3 * dVar3);
    dVar2 = (double)(float)(dVar2 * _1405 * dVar3 * (_1406 - dVar2 * dVar3 * dVar3));
  }
  dVar3 = (double)(param_1[10] * param_1[10] + param_1[2] * param_1[2] + param_1[6] * param_1[6]);
  if ((double)_1404 < dVar3) {
    dVar4 = 1.0 / SQRT(dVar3);
    dVar4 = _1405 * dVar4 * (_1406 - dVar3 * dVar4 * dVar4);
    dVar4 = _1405 * dVar4 * (_1406 - dVar3 * dVar4 * dVar4);
    dVar3 = (double)(float)(dVar3 * _1405 * dVar4 * (_1406 - dVar3 * dVar4 * dVar4));
  }
  local_44.x = _1451;
  local_44.y = _1404;
  local_44.z = _1404;
  local_50.x = param_1[1];
  local_50.y = param_1[5];
  local_50.z = param_1[9];
  mtx::PSVECCrossProduct(&local_44,&local_50,&local_5c);
  mtx::PSVECNormalize(&local_50,&local_50);
  mtx::PSVECNormalize(&local_5c,&local_5c);
  *param_1 = (float)((double)local_44.x * dVar5);
  param_1[1] = (float)((double)local_50.x * dVar2);
  param_1[2] = (float)((double)local_5c.x * dVar3);
  param_1[4] = (float)((double)local_44.y * dVar5);
  param_1[5] = (float)((double)local_50.y * dVar2);
  param_1[6] = (float)((double)local_5c.y * dVar3);
  param_1[8] = (float)((double)local_44.z * dVar5);
  param_1[9] = (float)((double)local_50.z * dVar2);
  param_1[10] = (float)((double)local_5c.z * dVar3);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  __psq_l0(auStack40,uVar1);
  __psq_l1(auStack40,uVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x802da63c) */
/* WARNING: Removing unreachable block (ram,0x802da5a0) */
/* WARNING: Removing unreachable block (ram,0x802da598) */
/* WARNING: Removing unreachable block (ram,0x802da58c) */
/* WARNING: Removing unreachable block (ram,0x802da584) */
/* WARNING: Removing unreachable block (ram,0x802da588) */
/* WARNING: Removing unreachable block (ram,0x802da594) */
/* WARNING: Removing unreachable block (ram,0x802da634) */
/* WARNING: Removing unreachable block (ram,0x802da644) */
/* __stdcall J3DPSCalcInverseTranspose(float *[][][][],
                                       float *[][][]) */

undefined4 J3DPSCalcInverseTranspose(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  
  fVar1 = (float)__psq_l0(param_1,0);
  fVar3 = (float)__psq_l0(param_1 + 4,0);
  fVar4 = (float)__psq_l1(param_1 + 4,0);
  fVar5 = (float)__psq_l0(param_1 + 0x10,0);
  fVar6 = (float)__psq_l0(param_1 + 0x14,0);
  fVar7 = (float)__psq_l1(param_1 + 0x14,0);
  fVar8 = (float)__psq_l0(param_1 + 0x20,0);
  fVar9 = (float)__psq_l0(param_1 + 0x24,0);
  fVar10 = (float)__psq_l1(param_1 + 0x24,0);
  fVar12 = fVar3 * fVar7 - fVar6 * fVar4;
  fVar14 = fVar6 * fVar10 - fVar9 * fVar7;
  fVar13 = fVar9 * fVar4 - fVar3 * fVar10;
  fVar11 = fVar8 * fVar12 + fVar5 * fVar13 + fVar1 * fVar14;
  if (fVar11 != fVar3 - fVar3) {
    fVar2 = (float)(float)(1.0 / fVar11);
    fVar2 = -(fVar11 * fVar2 * fVar2 - (fVar2 + fVar2));
    fVar11 = -(fVar11 * fVar2 * fVar2 - (fVar2 + fVar2));
    __psq_st0(param_2,fVar14 * fVar11,0);
    __psq_st1(param_2,(fVar7 * fVar8 - fVar10 * fVar5) * fVar11,0);
    __psq_st0(param_2 + 0xc,fVar13 * fVar11,0);
    __psq_st1(param_2 + 0xc,(fVar10 * fVar1 - fVar4 * fVar8) * fVar11,0);
    __psq_st0(param_2 + 0x18,fVar12 * fVar11,0);
    __psq_st1(param_2 + 0x18,(fVar4 * fVar5 - fVar7 * fVar1) * fVar11,0);
    __psq_st0(param_2 + 8,(fVar5 * fVar9 - fVar6 * fVar8) * fVar11,0);
    __psq_st0(param_2 + 0x14,(fVar3 * fVar8 - fVar1 * fVar9) * fVar11,0);
    __psq_st0(param_2 + 0x20,(fVar1 * fVar6 - fVar3 * fVar5) * fVar11,0);
    return 1;
  }
  return 0;
}


/* __stdcall J3DGetTranslateRotateMtx(J3DTransformInfo const &,
                                      float *[][][][]) */

void J3DGetTranslateRotateMtx(int param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  
  iVar7 = (int)((int)*(short *)(param_1 + 0xc) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar1 = JKernel::JMath::jmaSinTable[iVar7];
  fVar2 = JKernel::JMath::jmaCosTable[iVar7];
  iVar7 = (int)((int)*(short *)(param_1 + 0xe) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar3 = JKernel::JMath::jmaSinTable[iVar7];
  fVar4 = JKernel::JMath::jmaCosTable[iVar7];
  iVar7 = (int)((int)*(short *)(param_1 + 0x10) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar5 = JKernel::JMath::jmaSinTable[iVar7];
  fVar6 = JKernel::JMath::jmaCosTable[iVar7];
  param_2[8] = -fVar3;
  *param_2 = fVar6 * fVar4;
  param_2[4] = fVar5 * fVar4;
  param_2[9] = fVar4 * fVar1;
  param_2[10] = fVar4 * fVar2;
  param_2[1] = fVar1 * fVar6 * fVar3 - fVar2 * fVar5;
  param_2[6] = fVar2 * fVar5 * fVar3 - fVar1 * fVar6;
  param_2[2] = fVar1 * fVar5 + fVar2 * fVar6 * fVar3;
  param_2[5] = fVar2 * fVar6 + fVar1 * fVar5 * fVar3;
  param_2[3] = *(float *)(param_1 + 0x14);
  param_2[7] = *(float *)(param_1 + 0x18);
  param_2[0xb] = *(float *)(param_1 + 0x1c);
  return;
}


/* __stdcall J3DGetTranslateRotateMtx(short,
                                      short,
                                      short,
                                      float,
                                      float,
                                      float,
                                      float *[][][][]) */

void J3DGetTranslateRotateMtx
               (double param_1,double param_2,double param_3,uint param_4,uint param_5,uint param_6,
               float *param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  
  iVar7 = (int)(param_4 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar1 = JKernel::JMath::jmaSinTable[iVar7];
  fVar2 = JKernel::JMath::jmaCosTable[iVar7];
  iVar7 = (int)(param_5 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar3 = JKernel::JMath::jmaSinTable[iVar7];
  fVar4 = JKernel::JMath::jmaCosTable[iVar7];
  iVar7 = (int)(param_6 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar5 = JKernel::JMath::jmaSinTable[iVar7];
  fVar6 = JKernel::JMath::jmaCosTable[iVar7];
  param_7[8] = -fVar3;
  *param_7 = fVar6 * fVar4;
  param_7[4] = fVar5 * fVar4;
  param_7[9] = fVar4 * fVar1;
  param_7[10] = fVar4 * fVar2;
  param_7[1] = fVar1 * fVar6 * fVar3 - fVar2 * fVar5;
  param_7[6] = fVar2 * fVar5 * fVar3 - fVar1 * fVar6;
  param_7[2] = fVar1 * fVar5 + fVar2 * fVar6 * fVar3;
  param_7[5] = fVar2 * fVar6 + fVar1 * fVar5 * fVar3;
  param_7[3] = (float)param_1;
  param_7[7] = (float)param_2;
  param_7[0xb] = (float)param_3;
  return;
}


/* __stdcall J3DGetTextureMtx(J3DTextureSRTInfo const &,
                              Vec,
                              float *[][][][]) */

void J3DGetTextureMtx(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  iVar5 = (int)((int)*(short *)(param_1 + 2) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar4 = *param_1 * JKernel::JMath::jmaCosTable[iVar5];
  fVar1 = *param_1 * JKernel::JMath::jmaSinTable[iVar5];
  fVar2 = param_1[1] * JKernel::JMath::jmaSinTable[iVar5];
  fVar3 = param_1[1] * JKernel::JMath::jmaCosTable[iVar5];
  *param_3 = fVar4;
  param_3[1] = -fVar1;
  param_3[2] = param_1[3] + *param_2 + -fVar4 * *param_2 + fVar1 * param_2[1];
  param_3[4] = fVar2;
  param_3[5] = fVar3;
  param_3[6] = param_1[4] + param_2[1] + (-fVar2 * *param_2 - fVar3 * param_2[1]);
  fVar1 = _1404;
  param_3[0xb] = _1404;
  param_3[9] = fVar1;
  param_3[8] = fVar1;
  param_3[7] = fVar1;
  param_3[3] = fVar1;
  param_3[10] = _1451;
  return;
}


/* __stdcall J3DGetTextureMtxOld(J3DTextureSRTInfo const &,
                                 Vec,
                                 float *[][][][]) */

void J3DGetTextureMtxOld(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  iVar5 = (int)((int)*(short *)(param_1 + 2) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar4 = *param_1 * JKernel::JMath::jmaCosTable[iVar5];
  fVar1 = *param_1 * JKernel::JMath::jmaSinTable[iVar5];
  fVar2 = param_1[1] * JKernel::JMath::jmaSinTable[iVar5];
  fVar3 = param_1[1] * JKernel::JMath::jmaCosTable[iVar5];
  *param_3 = fVar4;
  param_3[1] = -fVar1;
  param_3[3] = param_1[3] + *param_2 + -fVar4 * *param_2 + fVar1 * param_2[1];
  param_3[4] = fVar2;
  param_3[5] = fVar3;
  param_3[7] = param_1[4] + param_2[1] + (-fVar2 * *param_2 - fVar3 * param_2[1]);
  fVar1 = _1404;
  param_3[0xb] = _1404;
  param_3[9] = fVar1;
  param_3[8] = fVar1;
  param_3[6] = fVar1;
  param_3[2] = fVar1;
  param_3[10] = _1451;
  return;
}


/* __stdcall J3DGetTextureMtxMaya(J3DTextureSRTInfo const &,
                                  float *[][][][]) */

void J3DGetTextureMtxMaya(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  fVar5 = _1547;
  iVar6 = (int)((int)*(short *)(param_1 + 2) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar1 = JKernel::JMath::jmaSinTable[iVar6];
  fVar2 = JKernel::JMath::jmaCosTable[iVar6];
  fVar3 = param_1[3] - _1547;
  fVar4 = param_1[4] - _1547;
  *param_2 = *param_1 * fVar2;
  param_2[1] = param_1[1] * fVar1;
  param_2[2] = fVar5 + (fVar3 * fVar2 - fVar1 * (fVar4 + param_1[1]));
  param_2[4] = -*param_1 * fVar1;
  param_2[5] = param_1[1] * fVar2;
  param_2[6] = fVar5 + (-fVar3 * fVar1 - fVar2 * (fVar4 + param_1[1]));
  fVar1 = _1404;
  param_2[0xb] = _1404;
  param_2[9] = fVar1;
  param_2[8] = fVar1;
  param_2[7] = fVar1;
  param_2[3] = fVar1;
  param_2[10] = _1451;
  return;
}


/* __stdcall J3DGetTextureMtxMayaOld(J3DTextureSRTInfo const &,
                                     float *[][][][]) */

void J3DGetTextureMtxMayaOld(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  
  fVar5 = _1547;
  iVar6 = (int)((int)*(short *)(param_1 + 2) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar1 = JKernel::JMath::jmaSinTable[iVar6];
  fVar2 = JKernel::JMath::jmaCosTable[iVar6];
  fVar3 = param_1[3] - _1547;
  fVar4 = param_1[4] - _1547;
  *param_2 = *param_1 * fVar2;
  param_2[1] = param_1[1] * fVar1;
  param_2[3] = fVar5 + (fVar3 * fVar2 - fVar1 * (fVar4 + param_1[1]));
  param_2[4] = -*param_1 * fVar1;
  param_2[5] = param_1[1] * fVar2;
  param_2[7] = fVar5 + (-fVar3 * fVar1 - fVar2 * (fVar4 + param_1[1]));
  fVar1 = _1404;
  param_2[0xb] = _1404;
  param_2[9] = fVar1;
  param_2[8] = fVar1;
  param_2[6] = fVar1;
  param_2[2] = fVar1;
  param_2[10] = _1451;
  return;
}


/* WARNING: Removing unreachable block (ram,0x802dab28) */
/* WARNING: Removing unreachable block (ram,0x802dab24) */
/* WARNING: Removing unreachable block (ram,0x802dab04) */
/* WARNING: Removing unreachable block (ram,0x802dab08) */
/* WARNING: Removing unreachable block (ram,0x802dab44) */
/* WARNING: Removing unreachable block (ram,0x802dab48) */
/* __stdcall J3DScaleNrmMtx(float *[][][][],
                            Vec const &) */

void J3DScaleNrmMtx(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar3 = (float)__psq_l0(param_2,0);
  fVar4 = (float)__psq_l1(param_2,0);
  fVar1 = (float)__psq_l0(param_1,0);
  fVar2 = (float)__psq_l1(param_1,0);
  __psq_st0(param_1,fVar1 * fVar3,0);
  __psq_st1(param_1,fVar2 * fVar4,0);
  *(float *)(param_1 + 8) = *(float *)(param_1 + 8) * *(float *)(param_2 + 8);
  fVar3 = (float)__psq_l0(param_2,0);
  fVar4 = (float)__psq_l1(param_2,0);
  fVar1 = (float)__psq_l0(param_1 + 0x10,0);
  fVar2 = (float)__psq_l1(param_1 + 0x10,0);
  __psq_st0(param_1 + 0x10,fVar1 * fVar3,0);
  __psq_st1(param_1 + 0x10,fVar2 * fVar4,0);
  *(float *)(param_1 + 0x18) = *(float *)(param_1 + 0x18) * *(float *)(param_2 + 8);
  fVar3 = (float)__psq_l0(param_2,0);
  fVar4 = (float)__psq_l1(param_2,0);
  fVar1 = (float)__psq_l0(param_1 + 0x20,0);
  fVar2 = (float)__psq_l1(param_1 + 0x20,0);
  __psq_st0(param_1 + 0x20,fVar1 * fVar3,0);
  __psq_st1(param_1 + 0x20,fVar2 * fVar4,0);
  *(float *)(param_1 + 0x28) = *(float *)(param_1 + 0x28) * *(float *)(param_2 + 8);
  return;
}


/* WARNING: Removing unreachable block (ram,0x802dab6c) */
/* WARNING: Removing unreachable block (ram,0x802dab68) */
/* WARNING: Removing unreachable block (ram,0x802dab7c) */
/* WARNING: Removing unreachable block (ram,0x802dab8c) */
/* __stdcall J3DScaleNrmMtx33(float *[][][],
                              Vec const &) */

void J3DScaleNrmMtx33(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  fVar2 = (float)__psq_l0(param_1,0);
  fVar3 = (float)__psq_l1(param_1,0);
  fVar8 = (float)__psq_l0(param_2,0);
  fVar9 = (float)__psq_l1(param_2,0);
  fVar1 = *(float *)(param_2 + 8);
  fVar4 = (float)__psq_l0(param_1 + 0xc,0);
  fVar5 = (float)__psq_l1(param_1 + 0xc,0);
  fVar6 = (float)__psq_l0(param_1 + 0x18,0);
  fVar7 = (float)__psq_l1(param_1 + 0x18,0);
  __psq_st0(param_1,fVar2 * fVar8,0);
  __psq_st1(param_1,fVar3 * fVar9,0);
  *(float *)(param_1 + 8) = *(float *)(param_1 + 8) * fVar1;
  __psq_st0(param_1 + 0xc,fVar4 * fVar8,0);
  __psq_st1(param_1 + 0xc,fVar5 * fVar9,0);
  *(float *)(param_1 + 0x14) = *(float *)(param_1 + 0x14) * fVar1;
  __psq_st0(param_1 + 0x18,fVar6 * fVar8,0);
  __psq_st1(param_1 + 0x18,fVar7 * fVar9,0);
  *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x20) * fVar1;
  return;
}


/* WARNING: Removing unreachable block (ram,0x802dacbc) */
/* WARNING: Removing unreachable block (ram,0x802daca0) */
/* WARNING: Removing unreachable block (ram,0x802dac9c) */
/* WARNING: Removing unreachable block (ram,0x802dac94) */
/* WARNING: Removing unreachable block (ram,0x802dac7c) */
/* WARNING: Removing unreachable block (ram,0x802dac5c) */
/* WARNING: Removing unreachable block (ram,0x802dac40) */
/* WARNING: Removing unreachable block (ram,0x802dac3c) */
/* WARNING: Removing unreachable block (ram,0x802dac34) */
/* WARNING: Removing unreachable block (ram,0x802dac1c) */
/* WARNING: Removing unreachable block (ram,0x802dabfc) */
/* WARNING: Removing unreachable block (ram,0x802dabe0) */
/* WARNING: Removing unreachable block (ram,0x802dabdc) */
/* WARNING: Removing unreachable block (ram,0x802dabd4) */
/* WARNING: Removing unreachable block (ram,0x802dabbc) */
/* WARNING: Removing unreachable block (ram,0x802dabc0) */
/* WARNING: Removing unreachable block (ram,0x802dabd8) */
/* WARNING: Removing unreachable block (ram,0x802dabf8) */
/* WARNING: Removing unreachable block (ram,0x802dac00) */
/* WARNING: Removing unreachable block (ram,0x802dac04) */
/* WARNING: Removing unreachable block (ram,0x802dac20) */
/* WARNING: Removing unreachable block (ram,0x802dac38) */
/* WARNING: Removing unreachable block (ram,0x802dac58) */
/* WARNING: Removing unreachable block (ram,0x802dac60) */
/* WARNING: Removing unreachable block (ram,0x802dac64) */
/* WARNING: Removing unreachable block (ram,0x802dac80) */
/* WARNING: Removing unreachable block (ram,0x802dac98) */
/* WARNING: Removing unreachable block (ram,0x802dacb8) */
/* WARNING: Removing unreachable block (ram,0x802dacc0) */
/* WARNING: Removing unreachable block (ram,0x802dacc4) */
/* __stdcall J3DMtxProjConcat(float *[][][][],
                              float *[][][][],
                              float *[][][][]) */

void J3DMtxProjConcat(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  fVar1 = (float)__psq_l0(param_1,0);
  fVar2 = (float)__psq_l1(param_1,0);
  fVar3 = (float)__psq_l0(param_1 + 8,0);
  fVar4 = (float)__psq_l1(param_1 + 8,0);
  fVar5 = (float)__psq_l0(param_2,0);
  fVar6 = (float)__psq_l1(param_2,0);
  fVar7 = (float)__psq_l0(param_2 + 0x10,0);
  fVar8 = (float)__psq_l1(param_2 + 0x10,0);
  fVar9 = (float)__psq_l0(param_2 + 0x20,0);
  fVar10 = (float)__psq_l1(param_2 + 0x20,0);
  fVar11 = (float)__psq_l0(param_2 + 0x30,0);
  fVar12 = (float)__psq_l1(param_2 + 0x30,0);
  __psq_st0(param_3,fVar4 * fVar11 + fVar3 * fVar9 + fVar2 * fVar7 + fVar1 * fVar5,0);
  __psq_st1(param_3,fVar4 * fVar12 + fVar3 * fVar10 + fVar2 * fVar8 + fVar1 * fVar6,0);
  fVar5 = (float)__psq_l0(param_2 + 8,0);
  fVar6 = (float)__psq_l1(param_2 + 8,0);
  fVar7 = (float)__psq_l0(param_2 + 0x18,0);
  fVar8 = (float)__psq_l1(param_2 + 0x18,0);
  fVar9 = (float)__psq_l0(param_2 + 0x28,0);
  fVar10 = (float)__psq_l1(param_2 + 0x28,0);
  fVar11 = (float)__psq_l0(param_2 + 0x38,0);
  fVar12 = (float)__psq_l1(param_2 + 0x38,0);
  __psq_st0(param_3 + 8,fVar4 * fVar11 + fVar3 * fVar9 + fVar2 * fVar7 + fVar1 * fVar5,0);
  __psq_st1(param_3 + 8,fVar4 * fVar12 + fVar3 * fVar10 + fVar2 * fVar8 + fVar1 * fVar6,0);
  fVar1 = (float)__psq_l0(param_1 + 0x10,0);
  fVar2 = (float)__psq_l1(param_1 + 0x10,0);
  fVar3 = (float)__psq_l0(param_1 + 0x18,0);
  fVar4 = (float)__psq_l1(param_1 + 0x18,0);
  fVar5 = (float)__psq_l0(param_2,0);
  fVar6 = (float)__psq_l1(param_2,0);
  fVar7 = (float)__psq_l0(param_2 + 0x10,0);
  fVar8 = (float)__psq_l1(param_2 + 0x10,0);
  fVar9 = (float)__psq_l0(param_2 + 0x20,0);
  fVar10 = (float)__psq_l1(param_2 + 0x20,0);
  fVar11 = (float)__psq_l0(param_2 + 0x30,0);
  fVar12 = (float)__psq_l1(param_2 + 0x30,0);
  __psq_st0(param_3 + 0x10,fVar4 * fVar11 + fVar3 * fVar9 + fVar2 * fVar7 + fVar1 * fVar5,0);
  __psq_st1(param_3 + 0x10,fVar4 * fVar12 + fVar3 * fVar10 + fVar2 * fVar8 + fVar1 * fVar6,0);
  fVar5 = (float)__psq_l0(param_2 + 8,0);
  fVar6 = (float)__psq_l1(param_2 + 8,0);
  fVar7 = (float)__psq_l0(param_2 + 0x18,0);
  fVar8 = (float)__psq_l1(param_2 + 0x18,0);
  fVar9 = (float)__psq_l0(param_2 + 0x28,0);
  fVar10 = (float)__psq_l1(param_2 + 0x28,0);
  fVar11 = (float)__psq_l0(param_2 + 0x38,0);
  fVar12 = (float)__psq_l1(param_2 + 0x38,0);
  __psq_st0(param_3 + 0x18,fVar4 * fVar11 + fVar3 * fVar9 + fVar2 * fVar7 + fVar1 * fVar5,0);
  __psq_st1(param_3 + 0x18,fVar4 * fVar12 + fVar3 * fVar10 + fVar2 * fVar8 + fVar1 * fVar6,0);
  fVar1 = (float)__psq_l0(param_1 + 0x20,0);
  fVar2 = (float)__psq_l1(param_1 + 0x20,0);
  fVar3 = (float)__psq_l0(param_1 + 0x28,0);
  fVar4 = (float)__psq_l1(param_1 + 0x28,0);
  fVar5 = (float)__psq_l0(param_2,0);
  fVar6 = (float)__psq_l1(param_2,0);
  fVar7 = (float)__psq_l0(param_2 + 0x10,0);
  fVar8 = (float)__psq_l1(param_2 + 0x10,0);
  fVar9 = (float)__psq_l0(param_2 + 0x20,0);
  fVar10 = (float)__psq_l1(param_2 + 0x20,0);
  fVar11 = (float)__psq_l0(param_2 + 0x30,0);
  fVar12 = (float)__psq_l1(param_2 + 0x30,0);
  __psq_st0(param_3 + 0x20,fVar4 * fVar11 + fVar3 * fVar9 + fVar2 * fVar7 + fVar1 * fVar5,0);
  __psq_st1(param_3 + 0x20,fVar4 * fVar12 + fVar3 * fVar10 + fVar2 * fVar8 + fVar1 * fVar6,0);
  fVar5 = (float)__psq_l0(param_2 + 8,0);
  fVar6 = (float)__psq_l1(param_2 + 8,0);
  fVar7 = (float)__psq_l0(param_2 + 0x18,0);
  fVar8 = (float)__psq_l1(param_2 + 0x18,0);
  fVar9 = (float)__psq_l0(param_2 + 0x28,0);
  fVar10 = (float)__psq_l1(param_2 + 0x28,0);
  fVar11 = (float)__psq_l0(param_2 + 0x38,0);
  fVar12 = (float)__psq_l1(param_2 + 0x38,0);
  __psq_st0(param_3 + 0x28,fVar4 * fVar11 + fVar3 * fVar9 + fVar2 * fVar7 + fVar1 * fVar5,0);
  __psq_st1(param_3 + 0x28,fVar4 * fVar12 + fVar3 * fVar10 + fVar2 * fVar8 + fVar1 * fVar6,0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x802dace8) */
/* WARNING: Removing unreachable block (ram,0x802dace0) */
/* WARNING: Removing unreachable block (ram,0x802dace4) */
/* WARNING: Removing unreachable block (ram,0x802dacec) */
/* __stdcall J3DPSMtx33Copy(float *[][][],
                            float *[][][]) */

undefined8 J3DPSMtx33Copy(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  uVar1 = __psq_l0(param_1,0);
  uVar2 = __psq_l1(param_1,0);
  uVar3 = __psq_l0(param_1 + 8,0);
  uVar4 = __psq_l1(param_1 + 8,0);
  uVar5 = __psq_l0(param_1 + 0x10,0);
  uVar6 = __psq_l1(param_1 + 0x10,0);
  uVar7 = __psq_l0(param_1 + 0x18,0);
  uVar8 = __psq_l1(param_1 + 0x18,0);
  __psq_st0(param_2,uVar1,0);
  __psq_st1(param_2,uVar2,0);
  __psq_st0(param_2 + 8,uVar3,0);
  __psq_st1(param_2 + 8,uVar4,0);
  __psq_st0(param_2 + 0x10,uVar5,0);
  __psq_st1(param_2 + 0x10,uVar6,0);
  __psq_st0(param_2 + 0x18,uVar7,0);
  __psq_st1(param_2 + 0x18,uVar8,0);
  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_1 + 0x20);
  return CONCAT44(uVar3,uVar4);
}


/* WARNING: Removing unreachable block (ram,0x802dad0c) */
/* WARNING: Removing unreachable block (ram,0x802dad1c) */
/* WARNING: Removing unreachable block (ram,0x802dad2c) */
/* __stdcall J3DPSMtx33CopyFrom34(float *[][][][],
                                  float *[][][]) */

void J3DPSMtx33CopyFrom34(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = __psq_l0(param_1,0);
  uVar2 = __psq_l1(param_1,0);
  __psq_st0(param_2,uVar1,0);
  __psq_st1(param_2,uVar2,0);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 8);
  uVar1 = __psq_l0(param_1 + 0x10,0);
  uVar2 = __psq_l1(param_1 + 0x10,0);
  __psq_st0(param_2 + 0xc,uVar1,0);
  __psq_st1(param_2 + 0xc,uVar2,0);
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0x18);
  uVar1 = __psq_l0(param_1 + 0x20,0);
  uVar2 = __psq_l1(param_1 + 0x20,0);
  __psq_st0(param_2 + 0x18,uVar1,0);
  __psq_st1(param_2 + 0x18,uVar2,0);
  *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(param_1 + 0x28);
  return;
}


/* WARNING: Removing unreachable block (ram,0x802dadb4) */
/* WARNING: Removing unreachable block (ram,0x802dadb0) */
/* WARNING: Removing unreachable block (ram,0x802dada0) */
/* WARNING: Removing unreachable block (ram,0x802dad90) */
/* WARNING: Removing unreachable block (ram,0x802dad80) */
/* WARNING: Removing unreachable block (ram,0x802dad70) */
/* WARNING: Removing unreachable block (ram,0x802dad68) */
/* WARNING: Removing unreachable block (ram,0x802dad64) */
/* WARNING: Removing unreachable block (ram,0x802dad6c) */
/* WARNING: Removing unreachable block (ram,0x802dad78) */
/* WARNING: Removing unreachable block (ram,0x802dad88) */
/* WARNING: Removing unreachable block (ram,0x802dad98) */
/* WARNING: Removing unreachable block (ram,0x802dada8) */
/* WARNING: Removing unreachable block (ram,0x802dae00) */
/* __stdcall J3DPSMtxArrayConcat(float *[][][][],
                                 float *[][][][],
                                 float *[][][][],
                                 unsigned long) */

undefined8 J3DPSMtxArrayConcat(int param_1,int param_2,int param_3,int param_4)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  
  pfVar1 = (float *)(param_2 + -8);
  pfVar2 = (float *)(param_3 + -8);
  do {
    fVar3 = (float)__psq_l0(param_1,0);
    fVar4 = (float)__psq_l1(param_1,0);
    fVar15 = (float)__psq_l0(pfVar1 + 2,0);
    fVar16 = (float)__psq_l1(pfVar1 + 2,0);
    fVar17 = (float)__psq_l0(pfVar1 + 4,0);
    fVar18 = (float)__psq_l1(pfVar1 + 4,0);
    fVar19 = (float)__psq_l0(pfVar1 + 6,0);
    fVar20 = (float)__psq_l1(pfVar1 + 6,0);
    fVar7 = (float)__psq_l0(param_1 + 0x10,0);
    fVar8 = (float)__psq_l1(param_1 + 0x10,0);
    fVar27 = (float)__psq_l0(0x803f6688,0);
    fVar28 = (float)__psq_l1(0x803f6688,0);
    fVar21 = (float)__psq_l0(pfVar1 + 8,0);
    fVar22 = (float)__psq_l1(pfVar1 + 8,0);
    fVar5 = (float)__psq_l0(param_1 + 8,0);
    fVar6 = (float)__psq_l1(param_1 + 8,0);
    fVar9 = (float)__psq_l0(param_1 + 0x18,0);
    fVar10 = (float)__psq_l1(param_1 + 0x18,0);
    fVar23 = (float)__psq_l0(pfVar1 + 10,0);
    fVar24 = (float)__psq_l1(pfVar1 + 10,0);
    fVar25 = pfVar1[0xc];
    fVar26 = pfVar1[0xd];
    fVar11 = (float)__psq_l0(param_1 + 0x20,0);
    fVar12 = (float)__psq_l1(param_1 + 0x20,0);
    fVar13 = (float)__psq_l0(param_1 + 0x28,0);
    fVar14 = (float)__psq_l1(param_1 + 0x28,0);
    __psq_st0(pfVar2 + 2,fVar23 * fVar5 + fVar19 * fVar4 + fVar15 * fVar3,0);
    __psq_st1(pfVar2 + 2,fVar24 * fVar5 + fVar20 * fVar4 + fVar16 * fVar3,0);
    __psq_st0(pfVar2 + 6,fVar23 * fVar9 + fVar19 * fVar8 + fVar15 * fVar7,0);
    __psq_st1(pfVar2 + 6,fVar24 * fVar9 + fVar20 * fVar8 + fVar16 * fVar7,0);
    __psq_st0(pfVar2 + 4,fVar27 * fVar6 + fVar25 * fVar5 + fVar21 * fVar4 + fVar17 * fVar3,0);
    __psq_st1(pfVar2 + 4,fVar28 * fVar6 + fVar26 * fVar5 + fVar22 * fVar4 + fVar18 * fVar3,0);
    __psq_st0(pfVar2 + 8,fVar27 * fVar10 + fVar25 * fVar9 + fVar21 * fVar8 + fVar17 * fVar7,0);
    __psq_st1(pfVar2 + 8,fVar28 * fVar10 + fVar26 * fVar9 + fVar22 * fVar8 + fVar18 * fVar7,0);
    __psq_st0(pfVar2 + 10,fVar23 * fVar13 + fVar19 * fVar12 + fVar15 * fVar11,0);
    __psq_st1(pfVar2 + 10,fVar24 * fVar13 + fVar20 * fVar12 + fVar16 * fVar11,0);
    pfVar2[0xc] = fVar27 * fVar14 + fVar25 * fVar13 + fVar21 * fVar12 + fVar17 * fVar11;
    pfVar2[0xd] = fVar28 * fVar14 + fVar26 * fVar13 + fVar22 * fVar12 + fVar18 * fVar11;
    param_4 = param_4 + -1;
    pfVar1 = pfVar1 + 0xc;
    pfVar2 = pfVar2 + 0xc;
  } while (param_4 != 0);
  return CONCAT44(fVar5,fVar6);
}

