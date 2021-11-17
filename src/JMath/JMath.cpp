#include <JMath/JMath.h>
#include <JKernel/JKRHeap.h>
#include <MSL_C.PPCEABI.bare.H/s_sin.h>


namespace JKernel {

namespace JMath {
undefined2 jmaSinTableSize;
undefined4 jmaSinShift;
float * jmaSinTable;
float * jmaCosTable;

/* WARNING: Removing unreachable block (ram,0x80301128) */
/* WARNING: Removing unreachable block (ram,0x80301130) */
/* __stdcall JMANewSinTable(unsigned char) */

undefined4 JMANewSinTable(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  jmaSinShift = 0x10 - (param_1 & 0xff);
  uVar2 = 1;
  for (uVar3 = 0; (uVar3 & 0xff) < (param_1 & 0xff); uVar3 = uVar3 + 1) {
    uVar2 = (uVar2 & 0x7fff) << 1;
  }
  jmaSinTableSize = (ushort)uVar2;
  jmaSinTable = (float *)operator_new__((uVar2 + (uVar2 >> 2)) * 4);
  if (jmaSinTable == (float *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar2 = 0;
    dVar6 = (double)_327;
    dVar7 = _329;
    while( true ) {
      if ((uint)jmaSinTableSize + (uint)(jmaSinTableSize >> 2) <= (uVar2 & 0xffff)) break;
      dVar5 = MSL_C.PPCEABI.bare.H::sin
                        ((double)((float)(dVar6 / (double)(float)((double)CONCAT44(0x43300000,
                                                                                   (uint)
                                                  jmaSinTableSize) - dVar7)) *
                                 (float)((double)CONCAT44(0x43300000,uVar2 & 0xffff) - dVar7)));
      jmaSinTable[uVar2 & 0xffff] = (float)dVar5;
      uVar2 = uVar2 + 1;
    }
    jmaCosTable = jmaSinTable + (jmaSinTableSize >> 2);
    uVar1 = 1;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return uVar1;
}


/* __stdcall JMAEulerToQuat(short,
                            short,
                            short,
                            Quaternion *) */

void JMAEulerToQuat(int param_1,int param_2,int param_3,Quaternion *pDst)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  uVar7 = SEXT24((short)param_1);
  iVar8 = (int)(((int)uVar7 >> 1) + (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0) & 0xffff) >>
          (jmaSinShift & 0x3f);
  fVar1 = jmaCosTable[iVar8];
  uVar7 = SEXT24((short)param_2);
  iVar9 = (int)(((int)uVar7 >> 1) + (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0) & 0xffff) >>
          (jmaSinShift & 0x3f);
  fVar2 = jmaCosTable[iVar9];
  uVar7 = SEXT24((short)param_3);
  iVar10 = (int)(((int)uVar7 >> 1) + (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0) & 0xffff) >>
           (jmaSinShift & 0x3f);
  fVar3 = jmaCosTable[iVar10];
  fVar4 = jmaSinTable[iVar8];
  fVar5 = jmaSinTable[iVar9];
  fVar6 = jmaSinTable[iVar10];
  pDst->w = fVar1 * fVar2 * fVar3 + fVar4 * fVar5 * fVar6;
  pDst->x = fVar4 * fVar2 * fVar3 - fVar1 * fVar5 * fVar6;
  pDst->y = fVar3 * fVar1 * fVar5 + fVar6 * fVar4 * fVar2;
  pDst->z = fVar6 * fVar1 * fVar2 - fVar3 * fVar4 * fVar5;
  return;
}


/* __stdcall JMAQuatLerp(Quaternion *,
                         Quaternion *,
                         float,
                         Quaternion *) */

void JMAQuatLerp(double param_1,float *param_2,float *param_3,float *param_4)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  
  dVar1 = (double)param_3[3];
  dVar5 = (double)param_3[2];
  dVar3 = (double)*param_3;
  dVar4 = (double)param_3[1];
  if ((double)((float)((double)param_2[3] * dVar1) +
              (float)((double)param_2[2] * dVar5) +
              (float)((double)*param_2 * dVar3) + (float)((double)param_2[1] * dVar4)) < _367) {
    dVar3 = -dVar3;
    dVar4 = -dVar4;
    dVar5 = -dVar5;
    dVar1 = -dVar1;
  }
  dVar2 = _368 - param_1;
  *param_4 = (float)(dVar2 * (double)*param_2 + param_1 * dVar3);
  param_4[1] = (float)(dVar2 * (double)param_2[1] + param_1 * dVar4);
  param_4[2] = (float)(dVar2 * (double)param_2[2] + param_1 * dVar5);
  param_4[3] = (float)(dVar2 * (double)param_2[3] + param_1 * dVar1);
  return;
}


/* __stdcall JMAHermiteInterpolation(float,
                                     float,
                                     float,
                                     float,
                                     float,
                                     float,
                                     float) */

double JMAHermiteInterpolation
                 (double param_1,double param_2,double param_3,double param_4,double param_5,
                 double param_6,double param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = (float)(param_1 - param_2);
  fVar4 = _374 / (float)(param_5 - param_2);
  fVar5 = fVar4 * fVar1 * fVar1;
  fVar2 = fVar1 * fVar5 * fVar4;
  fVar3 = _376 * fVar5 * fVar4;
  return (double)((float)(param_7 * (double)(fVar2 - fVar5)) +
                 (float)(param_4 * (double)(fVar1 + (fVar2 - _375 * fVar5))) +
                 (float)(param_3 * (double)(_374 + (_375 * fVar2 * fVar4 - fVar3))) +
                 (float)(param_6 * (double)(_377 * fVar2 * fVar4 + fVar3)));
}

