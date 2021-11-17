#include <SComponent/c_m3d.h>
#include <mtx/vec.h>
#include <SComponent/c_m3d.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <SComponent/c_m3d_g_sph.h>
#include <SComponent/c_math.h>
#include <mtx/mtx.h>
#include <MSL_C.PPCEABI.bare.H/w_acos.h>


namespace SComponent {

/* __stdcall cM3d_InDivPos1(Vec const *,
                            Vec const *,
                            float,
                            Vec *) */

void cM3d_InDivPos1(double param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4)

{
  cXyz cStack24;
  
  ::mtx::PSVECScale(param_3,&cStack24,(float)param_1);
  ::mtx::PSVECAdd(&cStack24,param_2,param_4);
  return;
}


/* __stdcall cM3d_InDivPos2(Vec const *,
                            Vec const *,
                            float,
                            Vec *) */

void cM3d_InDivPos2(undefined8 param_1,cXyz *param_2,cXyz *param_3,undefined4 param_4)

{
  cXyz acStack40 [2];
  
  ::mtx::PSVECSubtract(param_3,param_2,acStack40);
  cM3d_InDivPos1(param_1,param_2,acStack40,param_4);
  return;
}


/* __stdcall cM3d_Len2dSqPntAndSegLine(float,
                                       float,
                                       float,
                                       float,
                                       float,
                                       float,
                                       float *,
                                       float *,
                                       float *) */

int cM3d_Len2dSqPntAndSegLine
              (float param_1,float param_2,float x2,float y2,float x1,float y1,float *pDstX,
              float *pDstY,float *pDstLen)

{
  int iVar1;
  float dx;
  float dy;
  float mag;
  
  iVar1 = 0;
  dx = x1 - x2;
  dy = y1 - y2;
  mag = dx * dx + dy * dy;
  if (ABS(mag) < G_CM3D_F_ABS_MIN) {
    *pDstLen = 0_0;
    return 0;
  }
  mag = (dx * (param_1 - x2) + dy * (param_2 - y2)) / mag;
  if ((0_0 <= mag) && (mag <= _2261)) {
    iVar1 = 1;
  }
  *pDstX = x2 + dx * mag;
  *pDstY = y2 + dy * mag;
  *pDstLen = (*pDstX - param_1) * (*pDstX - param_1) + (*pDstY - param_2) * (*pDstY - param_2);
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8024a650) */
/* __stdcall cM3d_Len3dSqPntAndSegLine(cM3dGLin const *,
                                       Vec const *,
                                       Vec *,
                                       float *) */

undefined4
cM3d_Len3dSqPntAndSegLine(cXyz *param_1,cXyz *param_2,cXyz *param_3,float *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f31;
  float fVar5;
  cXyz cStack72;
  cXyz acStack60 [2];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::mtx::PSVECSubtract(param_1 + 1,param_1,acStack60);
  dVar3 = (double)::mtx::PSVECDotProduct(acStack60,acStack60);
  if (G_CM3D_F_ABS_MIN <= (float)ABS(dVar3)) {
    ::mtx::PSVECSubtract(param_2,param_1,&cStack72);
    dVar4 = (double)::mtx::PSVECDotProduct(&cStack72,acStack60);
    fVar5 = (float)(dVar4 / dVar3);
    if ((fVar5 < 0_0) || (_2261 < fVar5)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
    ::mtx::PSVECScale(acStack60,acStack60,fVar5);
    ::mtx::PSVECAdd(acStack60,param_1,param_3);
    fVar5 = ::mtx::PSVECSquareDistance(param_3,param_2);
    *param_4 = fVar5;
  }
  else {
    *param_4 = 0_0;
    uVar1 = 0;
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x8024a6d0) */
/* __stdcall cM3d_SignedLenPlaAndPos(cM3dGPla const *,
                                     Vec const *) */

double cM3d_SignedLenPlaAndPos(cM3dGPla *param_1,cXyz *param_2)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f31;
  float fVar4;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar4 = ::mtx::PSVECMag((cXyz *)param_1);
  dVar2 = (double)fVar4;
  fVar4 = 0_0;
  if (G_CM3D_F_ABS_MIN <= (float)ABS(dVar2)) {
    dVar3 = (double)::mtx::PSVECDotProduct(param_1,param_2);
    fVar4 = (float)((double)(float)((double)param_1->mDist + dVar3) / dVar2);
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return (double)fVar4;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall cM3d_CalcPla(Vec const *,
                          Vec const *,
                          Vec const *,
                          Vec *,
                          float *) */

void cM3d_CalcPla
               (TVec3_float_ *pV0,TVec3_float_ *pV1,TVec3_float_ *pV2,TVec3_float_ *pNorm,
               float *pDist)

{
  float fVar1;
  double dVar2;
  float fVar3;
  TVec3_float_ V0V1;
  TVec3_float_ V2V0;
  
  ::mtx::PSVECSubtract((cXyz *)pV1,(cXyz *)pV0,(cXyz *)&V0V1);
  ::mtx::PSVECSubtract((cXyz *)pV2,(cXyz *)pV0,(cXyz *)&V2V0);
  ::mtx::PSVECCrossProduct(&V0V1,&V2V0,pNorm);
  fVar3 = ::mtx::PSVECMag((cXyz *)pNorm);
  fVar1 = 0_0;
  if (ABS(fVar3) < 0_02) {
    pNorm->y = 0_0;
    *pDist = fVar1;
    pNorm->z = fVar1;
    pNorm->x = fVar1;
  }
  else {
    ::mtx::PSVECScale((cXyz *)pNorm,(cXyz *)pNorm,_2261 / fVar3);
    dVar2 = (double)::mtx::PSVECDotProduct(pNorm,pV0);
    *pDist = (float)-dVar2;
  }
  return;
}


/* __stdcall cM3d_Cross_AabAab(cM3dGAab const *,
                               cM3dGAab const *) */

undefined4 cM3d_Cross_AabAab(float *param_1,float *param_2)

{
  bool bVar1;
  
  if (*param_1 <= param_2[3]) {
    if (*param_2 <= param_1[3]) {
      if (*param_2 <= param_1[3]) {
        if (*param_1 <= param_2[3]) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (param_1[1] <= param_2[4]) {
      if (param_2[1] <= param_1[4]) {
        if (param_2[1] <= param_1[4]) {
          if (param_1[1] <= param_2[4]) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
        }
        else {
          bVar1 = false;
        }
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      if (param_1[2] <= param_2[5]) {
        if (param_2[2] <= param_1[5]) {
          if (param_2[2] <= param_1[5]) {
            if (param_1[2] <= param_2[5]) {
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
          }
          else {
            bVar1 = false;
          }
        }
        else {
          bVar1 = false;
        }
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        return 1;
      }
    }
  }
  return 0;
}


/* __stdcall cM3d_Cross_AabCyl(cM3dGAab const *,
                               cM3dGCyl const *) */

uint cM3d_Cross_AabCyl(float *param_1,float *param_2)

{
  float fVar1;
  uint uVar2;
  
  fVar1 = param_2[3];
  if (*param_2 + fVar1 < *param_1) {
    return 0;
  }
  if (param_1[3] < *param_2 - fVar1) {
    return 0;
  }
  if (param_2[2] + fVar1 < param_1[2]) {
    return 0;
  }
  if (param_1[5] < param_2[2] - fVar1) {
    return 0;
  }
  if (param_2[1] + param_2[4] < param_1[1]) {
    return 0;
  }
  uVar2 = countLeadingZeros(((uint)(byte)((param_1[4] < param_2[1]) << 3) << 0x1c) >> 0x1f);
  return uVar2 >> 5;
}


/* __stdcall cM3d_Cross_AabSph(cM3dGAab const *,
                               cM3dGSph const *) */

uint cM3d_Cross_AabSph(float *param_1,float *param_2)

{
  float fVar1;
  uint uVar2;
  
  fVar1 = param_2[3];
  if (*param_2 + fVar1 < *param_1) {
    return 0;
  }
  if (param_1[3] < *param_2 - fVar1) {
    return 0;
  }
  if (param_2[2] + fVar1 < param_1[2]) {
    return 0;
  }
  if (param_1[5] < param_2[2] - fVar1) {
    return 0;
  }
  if (param_2[1] + fVar1 < param_1[1]) {
    return 0;
  }
  uVar2 = countLeadingZeros(((uint)(byte)((param_1[4] < param_2[1] - fVar1) << 3) << 0x1c) >> 0x1f);
  return uVar2 >> 5;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8024ac80) */
/* WARNING: Removing unreachable block (ram,0x8024ac70) */
/* WARNING: Removing unreachable block (ram,0x8024ac60) */
/* WARNING: Removing unreachable block (ram,0x8024ac50) */
/* WARNING: Removing unreachable block (ram,0x8024ac58) */
/* WARNING: Removing unreachable block (ram,0x8024ac68) */
/* WARNING: Removing unreachable block (ram,0x8024ac78) */
/* WARNING: Removing unreachable block (ram,0x8024ac88) */
/* __stdcall cM3d_Check_LinLin(cM3dGLin const *,
                               cM3dGLin const *,
                               float *,
                               float *) */

undefined4 cM3d_Check_LinLin(cXyz *param_1,cXyz *param_2,float *param_3,float *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f24;
  double dVar7;
  undefined8 in_f25;
  double dVar8;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  double dVar9;
  undefined8 in_f29;
  double dVar10;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar11;
  cXyz cStack184;
  cXyz cStack172;
  cXyz cStack160;
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  ::mtx::PSVECSubtract(param_1 + 1,param_1,&cStack160);
  ::mtx::PSVECSubtract(param_2 + 1,param_2,&cStack172);
  fVar11 = ::mtx::PSVECMag(&cStack160);
  dVar3 = (double)fVar11;
  fVar11 = ::mtx::PSVECMag(&cStack172);
  dVar6 = (double)fVar11;
  if (((float)ABS(dVar3) < G_CM3D_F_ABS_MIN) || ((float)ABS(dVar6) < G_CM3D_F_ABS_MIN)) {
    uVar1 = 1;
  }
  else {
    fVar11 = (float)((double)_2261 / dVar3);
    dVar10 = (double)fVar11;
    dVar9 = (double)(float)((double)_2261 / dVar6);
    ::mtx::PSVECScale(&cStack160,&cStack160,fVar11);
    ::mtx::PSVECScale(&cStack172,&cStack172,(float)dVar9);
    ::mtx::PSVECSubtract(param_1,param_2,&cStack184);
    dVar4 = (double)::mtx::PSVECDotProduct(&cStack160,&cStack172);
    dVar4 = -dVar4;
    dVar5 = (double)::mtx::PSVECDotProduct(&cStack184,&cStack160);
    ::mtx::PSVECSquareMag(&cStack184);
    dVar8 = (double)ABS(_2261 - (float)(dVar4 * dVar4));
    if ((float)ABS(dVar8) < G_CM3D_F_ABS_MIN) {
      dVar8 = -dVar5;
      if ((dVar8 < (double)0_0) || (dVar7 = (double)0_0, dVar3 < dVar8)) {
        dVar8 = (double)(float)((double)(float)(dVar6 * dVar4) - dVar5);
        dVar7 = dVar6;
      }
      dVar5 = (double)::mtx::PSVECDotProduct(&cStack184,&cStack172);
      if ((dVar8 < (double)0_0) || (dVar3 < dVar8)) {
        dVar8 = (double)0_0;
        dVar7 = dVar5;
      }
      if ((dVar7 < (double)0_0) || (dVar6 < dVar7)) {
        dVar7 = (double)(float)(dVar5 + (double)(float)(-dVar3 * dVar4));
        dVar8 = dVar3;
      }
      *param_3 = (float)(dVar8 * dVar10);
      *param_4 = (float)(dVar7 * dVar9);
      uVar1 = 2;
    }
    else {
      dVar6 = (double)::mtx::PSVECDotProduct(&cStack184,&cStack172);
      dVar3 = (double)_2261;
      *param_3 = (float)((double)((float)(dVar3 / dVar8) *
                                 (float)((double)(float)(dVar4 * -dVar6) - dVar5)) * dVar10);
      *param_4 = (float)((double)((float)(dVar3 / dVar8) *
                                 (float)((double)(float)(dVar4 * dVar5) - -dVar6)) * dVar9);
      uVar1 = 3;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  __psq_l0(auStack56,uVar2);
  __psq_l1(auStack56,uVar2);
  __psq_l0(auStack72,uVar2);
  __psq_l1(auStack72,uVar2);
  __psq_l0(auStack88,uVar2);
  __psq_l1(auStack88,uVar2);
  __psq_l0(auStack104,uVar2);
  __psq_l1(auStack104,uVar2);
  __psq_l0(auStack120,uVar2);
  __psq_l1(auStack120,uVar2);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8024ae1c) */
/* __stdcall cM3d_Cross_LinPla(cM3dGLin const *,
                               cM3dGPla const *,
                               Vec *,
                               bool,
                               bool) */

undefined4
cM3d_Cross_LinPla(int param_1,int param_2,undefined4 *param_3,char param_4,char param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar3 = (double)::mtx::PSVECDotProduct(param_2,param_1);
  dVar5 = (double)(float)((double)*(float *)(param_2 + 0xc) + dVar3);
  dVar3 = (double)::mtx::PSVECDotProduct(param_2,param_1 + 0xc);
  dVar4 = (double)(float)((double)*(float *)(param_2 + 0xc) + dVar3);
  dVar3 = (double)0_0;
  if (dVar3 < (double)(float)(dVar5 * dVar4)) {
    *param_3 = *(undefined4 *)(param_1 + 0xc);
    param_3[1] = *(undefined4 *)(param_1 + 0x10);
    param_3[2] = *(undefined4 *)(param_1 + 0x14);
    uVar1 = 0;
  }
  else {
    if ((dVar5 < dVar3) || (dVar3 < dVar4)) {
      if (param_5 != '\0') {
        if (G_CM3D_F_ABS_MIN <= (float)ABS((double)(float)(dVar5 - dVar4))) {
          cM3d_InDivPos2((double)(float)(dVar5 / (double)(float)(dVar5 - dVar4)),param_1,
                         (undefined4 *)(param_1 + 0xc),param_3);
          uVar1 = 1;
        }
        else {
          *param_3 = *(undefined4 *)(param_1 + 0xc);
          param_3[1] = *(undefined4 *)(param_1 + 0x10);
          param_3[2] = *(undefined4 *)(param_1 + 0x14);
          uVar1 = 0;
        }
        goto LAB_8024ae1c;
      }
    }
    else {
      if (param_4 != '\0') {
        if (G_CM3D_F_ABS_MIN <= (float)ABS((double)(float)(dVar5 - dVar4))) {
          cM3d_InDivPos2((double)(float)(dVar5 / (double)(float)(dVar5 - dVar4)),param_1,
                         (undefined4 *)(param_1 + 0xc),param_3);
          uVar1 = 1;
        }
        else {
          *param_3 = *(undefined4 *)(param_1 + 0xc);
          param_3[1] = *(undefined4 *)(param_1 + 0x10);
          param_3[2] = *(undefined4 *)(param_1 + 0x14);
          uVar1 = 0;
        }
        goto LAB_8024ae1c;
      }
    }
    *param_3 = *(undefined4 *)(param_1 + 0xc);
    param_3[1] = *(undefined4 *)(param_1 + 0x10);
    param_3[2] = *(undefined4 *)(param_1 + 0x14);
    uVar1 = 0;
  }
LAB_8024ae1c:
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8024b9f0) */
/* WARNING: Removing unreachable block (ram,0x8024b9e0) */
/* WARNING: Removing unreachable block (ram,0x8024b9d0) */
/* WARNING: Removing unreachable block (ram,0x8024b9c0) */
/* WARNING: Removing unreachable block (ram,0x8024b9b0) */
/* WARNING: Removing unreachable block (ram,0x8024b9a0) */
/* WARNING: Removing unreachable block (ram,0x8024b990) */
/* WARNING: Removing unreachable block (ram,0x8024b988) */
/* WARNING: Removing unreachable block (ram,0x8024b998) */
/* WARNING: Removing unreachable block (ram,0x8024b9a8) */
/* WARNING: Removing unreachable block (ram,0x8024b9b8) */
/* WARNING: Removing unreachable block (ram,0x8024b9c8) */
/* WARNING: Removing unreachable block (ram,0x8024b9d8) */
/* WARNING: Removing unreachable block (ram,0x8024b9e8) */
/* WARNING: Removing unreachable block (ram,0x8024b9f8) */
/* __stdcall cM3d_Cross_MinMaxBoxLine(Vec const *,
                                      Vec const *,
                                      Vec const *,
                                      Vec const *) */

int cM3d_Cross_MinMaxBoxLine(cXyz *param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4)

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
  float fVar15;
  float fVar16;
  float fVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  char cVar21;
  uint uVar22;
  undefined4 uVar23;
  undefined8 in_f17;
  undefined8 in_f18;
  undefined8 in_f19;
  undefined8 in_f20;
  undefined8 in_f21;
  undefined8 in_f22;
  undefined8 in_f23;
  undefined8 in_f24;
  undefined8 in_f25;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  float local_1e0;
  float local_1dc;
  float local_1d4;
  float local_1d0;
  float local_1c8 [2];
  float local_1c0;
  float local_1bc [2];
  float local_1b4;
  undefined auStack432 [4];
  float local_1ac;
  float local_1a8;
  undefined auStack420 [4];
  float local_1a0;
  float local_19c;
  float local_198;
  float local_194;
  float local_190;
  float local_18c;
  undefined **local_188;
  float local_184;
  float local_180;
  float local_17c;
  float local_178;
  undefined **local_174;
  float local_170;
  float local_16c;
  float local_168;
  float local_164;
  undefined **local_160;
  float local_15c;
  float local_158;
  float local_154;
  float local_150;
  undefined **local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  undefined **local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  undefined **local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  undefined **local_108;
  undefined auStack232 [16];
  undefined auStack216 [16];
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar23 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  __psq_st0(auStack216,(int)((ulonglong)in_f18 >> 0x20),0);
  __psq_st1(auStack216,(int)in_f18,0);
  __psq_st0(auStack232,(int)((ulonglong)in_f17 >> 0x20),0);
  __psq_st1(auStack232,(int)in_f17,0);
  uVar19 = 0;
  local_120 = param_3->x;
  fVar1 = param_2->x;
  if (local_120 <= fVar1) {
    uVar18 = 0;
    if (fVar1 < param_4->x) {
      uVar19 = BPCP_OUTCODE0;
    }
  }
  else {
    uVar18 = BPCP_OUTCODE0;
    if (fVar1 < param_4->x) {
      iVar20 = 0;
      goto LAB_8024b988;
    }
  }
  if (((uVar18 & 1) != 0) || (param_1->x <= local_120)) {
    if (((uVar19 & 1) == 0) && (param_4->x < param_1->x)) {
      uVar19 = uVar19 | BPCP_OUTCODE1;
    }
  }
  else {
    if (((uVar19 & 1) == 0) && (param_4->x < param_1->x)) {
      iVar20 = 0;
      goto LAB_8024b988;
    }
    uVar18 = uVar18 | BPCP_OUTCODE1;
  }
  local_118 = param_3->z;
  fVar2 = param_2->z;
  if (local_118 <= fVar2) {
    if (fVar2 < param_4->z) {
      uVar19 = uVar19 | BPCP_OUTCODE4;
    }
  }
  else {
    if (fVar2 < param_4->z) {
      iVar20 = 0;
      goto LAB_8024b988;
    }
    uVar18 = uVar18 | BPCP_OUTCODE4;
  }
  if (((uVar18 & 0x10) != 0) || (param_1->z <= local_118)) {
    if (((uVar19 & 0x10) == 0) && (param_4->z < param_1->z)) {
      uVar19 = uVar19 | BPCP_OUTCODE5;
    }
  }
  else {
    if (((uVar19 & 0x10) == 0) && (param_4->z < param_1->z)) {
      iVar20 = 0;
      goto LAB_8024b988;
    }
    uVar18 = uVar18 | BPCP_OUTCODE5;
  }
  local_11c = param_3->y;
  fVar3 = param_2->y;
  if (local_11c <= fVar3) {
    if (fVar3 < param_4->y) {
      uVar19 = uVar19 | BPCP_OUTCODE2;
    }
  }
  else {
    if (fVar3 < param_4->y) {
      iVar20 = 0;
      goto LAB_8024b988;
    }
    uVar18 = uVar18 | BPCP_OUTCODE2;
  }
  if (((uVar18 & 4) != 0) || (param_1->y <= local_11c)) {
    if (((uVar19 & 4) == 0) && (param_4->y < param_1->y)) {
      uVar19 = uVar19 | BPCP_OUTCODE3;
    }
  }
  else {
    if (((uVar19 & 4) == 0) && (param_4->y < param_1->y)) {
      iVar20 = 0;
      goto LAB_8024b988;
    }
    uVar18 = uVar18 | BPCP_OUTCODE3;
  }
  if (uVar18 == 0) {
    iVar20 = 1;
  }
  else {
    if (uVar19 == 0) {
      iVar20 = 1;
    }
    else {
      fVar9 = -local_120 + local_11c;
      fVar4 = param_1->x;
      fVar12 = -fVar4 + fVar3;
      uVar22 = 0;
      if (fVar12 < fVar9) {
        uVar22 = BEVEL2D_OUTCODE0;
      }
      fVar5 = param_1->y;
      if (fVar9 < -fVar1 + fVar5) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE1;
      }
      fVar7 = local_120 + local_11c;
      fVar17 = fVar1 + fVar3;
      if (fVar17 < fVar7) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE2;
      }
      if (fVar7 < fVar4 + fVar5) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE3;
      }
      fVar8 = -local_118 + local_11c;
      fVar6 = param_1->z;
      fVar13 = -fVar6 + fVar3;
      if (fVar13 < fVar8) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE4;
      }
      fVar11 = -fVar2 + fVar5;
      if (fVar8 < fVar11) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE5;
      }
      if (fVar2 + fVar3 < local_118 + local_11c) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE6;
      }
      if (local_118 + local_11c < fVar6 + fVar5) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE7;
      }
      fVar8 = -local_118 + local_120;
      fVar14 = -fVar6 + fVar1;
      if (fVar14 < fVar8) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE8;
      }
      fVar10 = -fVar2 + fVar4;
      if (fVar8 < fVar10) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE9;
      }
      if (fVar2 + fVar1 < local_118 + local_120) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE10;
      }
      if (local_118 + local_120 < fVar6 + fVar4) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE11;
      }
      uVar18 = uVar18 | uVar22 << 8;
      local_114 = param_4->x;
      local_110 = param_4->y;
      fVar8 = -local_114 + local_110;
      uVar22 = 0;
      if (fVar12 < fVar8) {
        uVar22 = BEVEL2D_OUTCODE0;
      }
      if (fVar8 < -fVar1 + fVar5) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE1;
      }
      fVar15 = local_114 + local_110;
      if (fVar17 < fVar15) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE2;
      }
      if (fVar15 < fVar4 + fVar5) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE3;
      }
      local_10c = param_4->z;
      fVar16 = -local_10c + local_110;
      if (fVar13 < fVar16) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE4;
      }
      if (fVar16 < fVar11) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE5;
      }
      if (fVar2 + fVar3 < local_10c + local_110) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE6;
      }
      if (local_10c + local_110 < fVar6 + fVar5) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE7;
      }
      fVar3 = -local_10c + local_114;
      if (fVar14 < fVar3) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE8;
      }
      if (fVar3 < fVar10) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE9;
      }
      if (fVar2 + fVar1 < local_10c + local_114) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE10;
      }
      if (local_10c + local_114 < fVar6 + fVar4) {
        uVar22 = uVar22 | BEVEL2D_OUTCODE11;
      }
      uVar19 = uVar19 | uVar22 << 8;
      if ((uVar18 & uVar19) == 0) {
        uVar22 = 0;
        if (fVar2 + fVar17 < local_118 + fVar7) {
          uVar22 = BEVEL3D_OUTCODE0;
        }
        if (fVar2 + fVar12 < local_118 + fVar9) {
          uVar22 = uVar22 | BEVEL3D_OUTCODE1;
        }
        if (fVar12 - fVar6 < fVar9 - local_118) {
          uVar22 = uVar22 | BEVEL3D_OUTCODE2;
        }
        if (fVar17 - fVar6 < fVar7 - local_118) {
          uVar22 = uVar22 | BEVEL3D_OUTCODE3;
        }
        fVar1 = fVar2 + (fVar1 - fVar5);
        if (fVar1 < local_118 + (local_120 - local_11c)) {
          uVar22 = uVar22 | BEVEL3D_OUTCODE4;
        }
        fVar3 = -local_120 - local_11c;
        fVar5 = -fVar4 - fVar5;
        fVar4 = fVar2 + fVar5;
        if (fVar4 < local_118 + fVar3) {
          uVar22 = uVar22 | BEVEL3D_OUTCODE5 | BEVEL3D_OUTCODE6;
        }
        fVar5 = fVar5 - fVar6;
        if (fVar5 < fVar3 - local_118) {
          uVar22 = uVar22 | BEVEL3D_OUTCODE7;
        }
        uVar18 = uVar18 | uVar22 << 0x18;
        uVar22 = 0;
        if (fVar2 + fVar17 < local_10c + fVar15) {
          uVar22 = BEVEL3D_OUTCODE0;
        }
        if (fVar2 + fVar12 < local_10c + fVar8) {
          uVar22 = uVar22 | BEVEL3D_OUTCODE1;
        }
        if (fVar12 - fVar6 < fVar8 - local_10c) {
          uVar22 = uVar22 | BEVEL3D_OUTCODE2;
        }
        if (fVar17 - fVar6 < fVar15 - local_10c) {
          uVar22 = uVar22 | BEVEL3D_OUTCODE3;
        }
        if (fVar1 < local_10c + (local_114 - local_110)) {
          uVar22 = uVar22 | BEVEL3D_OUTCODE4;
        }
        fVar1 = -local_114 - local_110;
        if (fVar4 < local_10c + fVar1) {
          uVar22 = uVar22 | BEVEL3D_OUTCODE5 | BEVEL3D_OUTCODE6;
        }
        if (fVar5 < fVar1 - local_10c) {
          uVar22 = uVar22 | BEVEL3D_OUTCODE7;
        }
        uVar19 = uVar19 | uVar22 << 0x18;
        if ((uVar18 & uVar19) == 0) {
          local_108 = &::cM3dGLin::__vt;
          uVar18 = uVar18 ^ uVar19;
          if ((uVar18 & 1) != 0) {
            local_124 = &::cM3dGPla::__vt;
            local_134 = _2261;
            local_130 = 0_0;
            local_12c = 0_0;
            local_128 = -param_2->x;
            cVar21 = cM3d_Cross_LinPla(&local_120,&local_134,auStack420,1,1);
            if ((((cVar21 != '\0') && (param_1->y <= local_1a0)) && (local_1a0 <= param_2->y)) &&
               ((param_1->z <= local_19c && (local_19c <= param_2->z)))) {
              iVar20 = 1;
              goto LAB_8024b988;
            }
            local_124 = &::cM3dGPla::__vt;
          }
          if ((uVar18 & 2) != 0) {
            local_138 = &::cM3dGPla::__vt;
            local_148 = _3088;
            local_144 = 0_0;
            local_140 = 0_0;
            local_13c = param_1->x;
            cVar21 = cM3d_Cross_LinPla(&local_120,&local_148,auStack432,1,1);
            if (((cVar21 != '\0') && (param_1->y <= local_1ac)) &&
               ((local_1ac <= param_2->y && ((param_1->z <= local_1a8 && (local_1a8 <= param_2->z)))
                ))) {
              iVar20 = 1;
              goto LAB_8024b988;
            }
            local_138 = &::cM3dGPla::__vt;
          }
          if ((uVar18 & 4) != 0) {
            local_14c = &::cM3dGPla::__vt;
            local_15c = 0_0;
            local_158 = _2261;
            local_154 = 0_0;
            local_150 = -param_2->y;
            cVar21 = cM3d_Cross_LinPla(&local_120,&local_15c,local_1bc,1,1);
            if ((((cVar21 != '\0') && (param_1->x <= local_1bc[0])) && (local_1bc[0] <= param_2->x))
               && ((param_1->z <= local_1b4 && (local_1b4 <= param_2->z)))) {
              iVar20 = 1;
              goto LAB_8024b988;
            }
            local_14c = &::cM3dGPla::__vt;
          }
          if ((uVar18 & 8) != 0) {
            local_160 = &::cM3dGPla::__vt;
            local_170 = 0_0;
            local_16c = _3088;
            local_168 = 0_0;
            local_164 = param_1->y;
            cVar21 = cM3d_Cross_LinPla(&local_120,&local_170,local_1c8,1,1);
            if (((cVar21 != '\0') && (param_1->x <= local_1c8[0])) &&
               ((local_1c8[0] <= param_2->x &&
                ((param_1->z <= local_1c0 && (local_1c0 <= param_2->z)))))) {
              iVar20 = 1;
              goto LAB_8024b988;
            }
            local_160 = &::cM3dGPla::__vt;
          }
          if ((uVar18 & 0x10) != 0) {
            local_174 = &::cM3dGPla::__vt;
            local_184 = 0_0;
            local_180 = 0_0;
            local_17c = _2261;
            local_178 = -param_2->z;
            cVar21 = cM3d_Cross_LinPla(&local_120,&local_184,&local_1d4,1,1);
            if ((((cVar21 != '\0') && (param_1->x <= local_1d4)) && (local_1d4 <= param_2->x)) &&
               ((param_1->y <= local_1d0 && (local_1d0 <= param_2->y)))) {
              iVar20 = 1;
              goto LAB_8024b988;
            }
            local_174 = &::cM3dGPla::__vt;
          }
          if ((uVar18 & 0x20) != 0) {
            local_188 = &::cM3dGPla::__vt;
            local_198 = 0_0;
            local_194 = 0_0;
            local_190 = _3088;
            local_18c = param_1->z;
            cVar21 = cM3d_Cross_LinPla(&local_120,&local_198,&local_1e0,1,1);
            if (((cVar21 != '\0') && (param_1->x <= local_1e0)) &&
               ((local_1e0 <= param_2->x && ((param_1->y <= local_1dc && (local_1dc <= param_2->y)))
                ))) {
              iVar20 = 1;
              goto LAB_8024b988;
            }
          }
          iVar20 = 0;
        }
        else {
          iVar20 = 0;
        }
      }
      else {
        iVar20 = 0;
      }
    }
  }
LAB_8024b988:
  __psq_l0(auStack8,uVar23);
  __psq_l1(auStack8,uVar23);
  __psq_l0(auStack24,uVar23);
  __psq_l1(auStack24,uVar23);
  __psq_l0(auStack40,uVar23);
  __psq_l1(auStack40,uVar23);
  __psq_l0(auStack56,uVar23);
  __psq_l1(auStack56,uVar23);
  __psq_l0(auStack72,uVar23);
  __psq_l1(auStack72,uVar23);
  __psq_l0(auStack88,uVar23);
  __psq_l1(auStack88,uVar23);
  __psq_l0(auStack104,uVar23);
  __psq_l1(auStack104,uVar23);
  __psq_l0(auStack120,uVar23);
  __psq_l1(auStack120,uVar23);
  __psq_l0(auStack136,uVar23);
  __psq_l1(auStack136,uVar23);
  __psq_l0(auStack152,uVar23);
  __psq_l1(auStack152,uVar23);
  __psq_l0(auStack168,uVar23);
  __psq_l1(auStack168,uVar23);
  __psq_l0(auStack184,uVar23);
  __psq_l1(auStack184,uVar23);
  __psq_l0(auStack200,uVar23);
  __psq_l1(auStack200,uVar23);
  __psq_l0(auStack216,uVar23);
  __psq_l1(auStack216,uVar23);
  __psq_l0(auStack232,uVar23);
  __psq_l1(auStack232,uVar23);
  return iVar20;
}


/* __stdcall cM3d_InclusionCheckPosIn3PosBox3d(Vec const *,
                                               Vec const *,
                                               Vec const *,
                                               Vec const *,
                                               float) */

undefined4
cM3d_InclusionCheckPosIn3PosBox3d
          (double param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar1 = (double)*param_2;
  dVar3 = (double)*param_3;
  dVar4 = dVar3;
  if (dVar1 < dVar3) {
    dVar4 = dVar1;
    dVar1 = dVar3;
  }
  dVar2 = (double)*param_4;
  dVar3 = dVar2;
  if ((dVar4 <= dVar2) && (dVar3 = dVar4, dVar1 < dVar2)) {
    dVar1 = dVar2;
  }
  if ((*param_5 < (float)(dVar3 - param_1)) || ((float)(dVar1 + param_1) < *param_5)) {
    return 0;
  }
  dVar1 = (double)param_2[2];
  dVar3 = (double)param_3[2];
  dVar4 = dVar3;
  if (dVar1 < dVar3) {
    dVar4 = dVar1;
    dVar1 = dVar3;
  }
  dVar2 = (double)param_4[2];
  dVar3 = dVar2;
  if ((dVar4 <= dVar2) && (dVar3 = dVar4, dVar1 < dVar2)) {
    dVar1 = dVar2;
  }
  if (((float)(dVar3 - param_1) <= param_5[2]) && (param_5[2] <= (float)(dVar1 + param_1))) {
    dVar1 = (double)param_2[1];
    dVar3 = (double)param_3[1];
    dVar4 = dVar3;
    if (dVar1 < dVar3) {
      dVar4 = dVar1;
      dVar1 = dVar3;
    }
    dVar2 = (double)param_4[1];
    dVar3 = dVar2;
    if ((dVar4 <= dVar2) && (dVar3 = dVar4, dVar1 < dVar2)) {
      dVar1 = dVar2;
    }
    if (((float)(dVar3 - param_1) <= param_5[1]) && (param_5[1] <= (float)(dVar1 + param_1))) {
      return 1;
    }
    return 0;
  }
  return 0;
}


/* __stdcall cM3d_CrossX_Tri(cM3dGTri const *,
                             Vec const *,
                             float) */

undefined4 cM3d_CrossX_Tri(double param_1,float *param_2,int param_3)

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
  bool bVar12;
  double dVar13;
  
  if (ABS(*param_2) < G_CM3D_F_ABS_MIN) {
    return 0;
  }
  fVar1 = *(float *)(param_3 + 8);
  fVar2 = *(float *)(param_3 + 4);
  fVar3 = param_2[0xd];
  fVar4 = param_2[0xc];
  fVar5 = param_2[10];
  fVar6 = param_2[9];
  fVar7 = param_2[7];
  fVar8 = param_2[6];
  fVar9 = fVar8;
  fVar10 = fVar6;
  if (fVar8 < fVar6) {
    fVar9 = fVar6;
    fVar10 = fVar8;
  }
  fVar11 = fVar4;
  if ((fVar10 <= fVar4) && (fVar11 = fVar10, fVar9 < fVar4)) {
    fVar9 = fVar4;
  }
  if ((fVar2 < fVar11) || (fVar9 < fVar2)) {
    bVar12 = false;
  }
  else {
    fVar9 = fVar7;
    fVar10 = fVar5;
    if (fVar7 < fVar5) {
      fVar9 = fVar5;
      fVar10 = fVar7;
    }
    fVar11 = fVar3;
    if ((fVar10 <= fVar3) && (fVar11 = fVar10, fVar9 < fVar3)) {
      fVar9 = fVar3;
    }
    if ((fVar1 < fVar11) || (fVar9 < fVar1)) {
      bVar12 = false;
    }
    else {
      bVar12 = true;
    }
  }
  if (!bVar12) {
    return 0;
  }
  dVar13 = (double)((fVar6 - fVar8) * (fVar1 - fVar7) - (fVar5 - fVar7) * (fVar2 - fVar8));
  if (((dVar13 <= param_1) &&
      ((double)((fVar4 - fVar6) * (fVar1 - fVar5) - (fVar3 - fVar5) * (fVar2 - fVar6)) <= param_1))
     && ((double)((fVar8 - fVar4) * (fVar1 - fVar3) - (fVar7 - fVar3) * (fVar2 - fVar4)) <= param_1)
     ) {
    return 1;
  }
  param_1 = -param_1;
  if (((param_1 <= dVar13) &&
      (param_1 <= (double)((fVar4 - fVar6) * (fVar1 - fVar5) - (fVar3 - fVar5) * (fVar2 - fVar6))))
     && (param_1 <= (double)((fVar8 - fVar4) * (fVar1 - fVar3) - (fVar7 - fVar3) * (fVar2 - fVar4)))
     ) {
    return 1;
  }
  return 0;
}


/* __stdcall cM3d_CrossX_Tri(cM3dGTri const *,
                             Vec const *) */

undefined4 cM3d_CrossX_Tri(float *param_1,int param_2)

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
  bool bVar12;
  
  if (ABS(*param_1) < G_CM3D_F_ABS_MIN) {
    return 0;
  }
  fVar1 = *(float *)(param_2 + 8);
  fVar2 = *(float *)(param_2 + 4);
  fVar3 = param_1[0xd];
  fVar4 = param_1[0xc];
  fVar5 = param_1[10];
  fVar6 = param_1[9];
  fVar7 = param_1[7];
  fVar8 = param_1[6];
  fVar9 = fVar8;
  fVar10 = fVar6;
  if (fVar8 < fVar6) {
    fVar9 = fVar6;
    fVar10 = fVar8;
  }
  fVar11 = fVar4;
  if ((fVar10 <= fVar4) && (fVar11 = fVar10, fVar9 < fVar4)) {
    fVar9 = fVar4;
  }
  if ((fVar2 < fVar11) || (fVar9 < fVar2)) {
    bVar12 = false;
  }
  else {
    fVar9 = fVar7;
    fVar10 = fVar5;
    if (fVar7 < fVar5) {
      fVar9 = fVar5;
      fVar10 = fVar7;
    }
    fVar11 = fVar3;
    if ((fVar10 <= fVar3) && (fVar11 = fVar10, fVar9 < fVar3)) {
      fVar9 = fVar3;
    }
    if ((fVar1 < fVar11) || (fVar9 < fVar1)) {
      bVar12 = false;
    }
    else {
      bVar12 = true;
    }
  }
  if (!bVar12) {
    return 0;
  }
  fVar9 = (fVar6 - fVar8) * (fVar1 - fVar7) - (fVar5 - fVar7) * (fVar2 - fVar8);
  if (((fVar9 <= _3420) &&
      ((fVar4 - fVar6) * (fVar1 - fVar5) - (fVar3 - fVar5) * (fVar2 - fVar6) <= _3420)) &&
     ((fVar8 - fVar4) * (fVar1 - fVar3) - (fVar7 - fVar3) * (fVar2 - fVar4) <= _3420)) {
    return 1;
  }
  if (((_20_0 <= fVar9) &&
      (_20_0 <= (fVar4 - fVar6) * (fVar1 - fVar5) - (fVar3 - fVar5) * (fVar2 - fVar6))) &&
     (_20_0 <= (fVar8 - fVar4) * (fVar1 - fVar3) - (fVar7 - fVar3) * (fVar2 - fVar4))) {
    return 1;
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall cM3d_CrossX_Tri(cM3dGTri const *,
                             Vec const *,
                             float *) */

bool cM3d_CrossX_Tri(float *param_1,int param_2,float *param_3)

{
  char cVar1;
  
  cVar1 = cM3d_CrossX_Tri();
  if (cVar1 != '\0') {
    *param_3 = ((*(float *)(param_2 + 4) * -param_1[1] - *(float *)(param_2 + 8) * param_1[2]) -
               param_1[3]) / *param_1;
  }
  return cVar1 != '\0';
}


/* __stdcall cM3d_CrossY_Tri(cM3dGTri const *,
                             Vec const *) */

undefined4 cM3d_CrossY_Tri(int param_1,float *param_2)

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
  bool bVar12;
  
  if (ABS(*(float *)(param_1 + 4)) < G_CM3D_F_ABS_MIN) {
    return 0;
  }
  fVar1 = *param_2;
  fVar2 = param_2[2];
  fVar3 = *(float *)(param_1 + 0x2c);
  fVar4 = *(float *)(param_1 + 0x34);
  fVar5 = *(float *)(param_1 + 0x20);
  fVar6 = *(float *)(param_1 + 0x28);
  fVar7 = *(float *)(param_1 + 0x14);
  fVar8 = *(float *)(param_1 + 0x1c);
  fVar9 = fVar8;
  fVar10 = fVar6;
  if (fVar8 < fVar6) {
    fVar9 = fVar6;
    fVar10 = fVar8;
  }
  fVar11 = fVar4;
  if ((fVar10 <= fVar4) && (fVar11 = fVar10, fVar9 < fVar4)) {
    fVar9 = fVar4;
  }
  if ((fVar2 < fVar11) || (fVar9 < fVar2)) {
    bVar12 = false;
  }
  else {
    fVar9 = fVar7;
    fVar10 = fVar5;
    if (fVar7 < fVar5) {
      fVar9 = fVar5;
      fVar10 = fVar7;
    }
    fVar11 = fVar3;
    if ((fVar10 <= fVar3) && (fVar11 = fVar10, fVar9 < fVar3)) {
      fVar9 = fVar3;
    }
    if ((fVar1 < fVar11) || (fVar9 < fVar1)) {
      bVar12 = false;
    }
    else {
      bVar12 = true;
    }
  }
  if (!bVar12) {
    return 0;
  }
  fVar9 = (fVar6 - fVar8) * (fVar1 - fVar7) - (fVar5 - fVar7) * (fVar2 - fVar8);
  if (((fVar9 <= _3420) &&
      ((fVar4 - fVar6) * (fVar1 - fVar5) - (fVar3 - fVar5) * (fVar2 - fVar6) <= _3420)) &&
     ((fVar8 - fVar4) * (fVar1 - fVar3) - (fVar7 - fVar3) * (fVar2 - fVar4) <= _3420)) {
    return 1;
  }
  if (((_20_0 <= fVar9) &&
      (_20_0 <= (fVar4 - fVar6) * (fVar1 - fVar5) - (fVar3 - fVar5) * (fVar2 - fVar6))) &&
     (_20_0 <= (fVar8 - fVar4) * (fVar1 - fVar3) - (fVar7 - fVar3) * (fVar2 - fVar4))) {
    return 1;
  }
  return 0;
}


/* __stdcall cM3d_CrossY_Tri(Vec const &,
                             Vec const &,
                             Vec const &,
                             cM3dGPla const &,
                             Vec const *) */

undefined4
cM3d_CrossY_Tri(float *param_1,float *param_2,float *param_3,int param_4,float *param_5)

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
  bool bVar12;
  
  if (ABS(*(float *)(param_4 + 4)) < G_CM3D_F_ABS_MIN) {
    return 0;
  }
  fVar1 = *param_5;
  fVar2 = param_5[2];
  fVar3 = *param_3;
  fVar4 = param_3[2];
  fVar5 = *param_2;
  fVar6 = param_2[2];
  fVar7 = *param_1;
  fVar8 = param_1[2];
  fVar9 = fVar8;
  fVar10 = fVar6;
  if (fVar8 < fVar6) {
    fVar9 = fVar6;
    fVar10 = fVar8;
  }
  fVar11 = fVar4;
  if ((fVar10 <= fVar4) && (fVar11 = fVar10, fVar9 < fVar4)) {
    fVar9 = fVar4;
  }
  if ((fVar2 < fVar11) || (fVar9 < fVar2)) {
    bVar12 = false;
  }
  else {
    fVar9 = fVar7;
    fVar10 = fVar5;
    if (fVar7 < fVar5) {
      fVar9 = fVar5;
      fVar10 = fVar7;
    }
    fVar11 = fVar3;
    if ((fVar10 <= fVar3) && (fVar11 = fVar10, fVar9 < fVar3)) {
      fVar9 = fVar3;
    }
    if ((fVar1 < fVar11) || (fVar9 < fVar1)) {
      bVar12 = false;
    }
    else {
      bVar12 = true;
    }
  }
  if (!bVar12) {
    return 0;
  }
  fVar9 = (fVar6 - fVar8) * (fVar1 - fVar7) - (fVar5 - fVar7) * (fVar2 - fVar8);
  if (((fVar9 <= _3420) &&
      ((fVar4 - fVar6) * (fVar1 - fVar5) - (fVar3 - fVar5) * (fVar2 - fVar6) <= _3420)) &&
     ((fVar8 - fVar4) * (fVar1 - fVar3) - (fVar7 - fVar3) * (fVar2 - fVar4) <= _3420)) {
    return 1;
  }
  if (((_20_0 <= fVar9) &&
      (_20_0 <= (fVar4 - fVar6) * (fVar1 - fVar5) - (fVar3 - fVar5) * (fVar2 - fVar6))) &&
     (_20_0 <= (fVar8 - fVar4) * (fVar1 - fVar3) - (fVar7 - fVar3) * (fVar2 - fVar4))) {
    return 1;
  }
  return 0;
}


/* __stdcall cM3d_CrossY_Tri_Front(Vec const &,
                                   Vec const &,
                                   Vec const &,
                                   Vec const *) */

undefined4 cM3d_CrossY_Tri_Front(cXyz *param_1,cXyz *param_2,cXyz *param_3,cXyz *pPos)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  float p1X;
  float p1Z;
  float p2X;
  float p2Z;
  float p3X;
  float p3Z;
  float posX;
  float posZ;
  
  posX = pPos->x;
  posZ = pPos->z;
  p3X = param_3->x;
  p3Z = param_3->z;
  p2X = param_2->x;
  p2Z = param_2->z;
  p1X = param_1->x;
  p1Z = param_1->z;
  fVar1 = p1Z;
  fVar2 = p2Z;
  if (p1Z < p2Z) {
    fVar1 = p2Z;
    fVar2 = p1Z;
  }
  fVar3 = p3Z;
  if ((fVar2 <= p3Z) && (fVar3 = fVar2, fVar1 < p3Z)) {
    fVar1 = p3Z;
  }
  if ((posZ < fVar3) || (fVar1 < posZ)) {
    bVar4 = false;
  }
  else {
    fVar1 = p1X;
    fVar2 = p2X;
    if (p1X < p2X) {
      fVar1 = p2X;
      fVar2 = p1X;
    }
    fVar3 = p3X;
    if ((fVar2 <= p3X) && (fVar3 = fVar2, fVar1 < p3X)) {
      fVar1 = p3X;
    }
    if ((posX < fVar3) || (fVar1 < posX)) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
  }
  if (bVar4) {
    if (((_20_0 <= (p2Z - p1Z) * (posX - p1X) - (p2X - p1X) * (posZ - p1Z)) &&
        (_20_0 <= (p3Z - p2Z) * (posX - p2X) - (p3X - p2X) * (posZ - p2Z))) &&
       (_20_0 <= (p1Z - p3Z) * (posX - p3X) - (p1X - p3X) * (posZ - p3Z))) {
      return 1;
    }
    return 0;
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall cM3d_CrossY_Tri(cM3dGTri const *,
                             Vec const *,
                             float *) */

bool cM3d_CrossY_Tri(float *param_1,float *param_2,float *param_3)

{
  char cVar1;
  
  cVar1 = cM3d_CrossY_Tri();
  if (cVar1 != '\0') {
    *param_3 = ((*param_2 * -*param_1 - param_2[2] * param_1[2]) - param_1[3]) / param_1[1];
  }
  return cVar1 != '\0';
}


/* __stdcall cM3d_CrossY_Tri(cM3dGTri const *,
                             Vec const *,
                             float) */

undefined4 cM3d_CrossY_Tri(double param_1,int param_2,float *param_3)

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
  bool bVar12;
  double dVar13;
  
  if (ABS(*(float *)(param_2 + 4)) < G_CM3D_F_ABS_MIN) {
    return 0;
  }
  fVar1 = *param_3;
  fVar2 = param_3[2];
  fVar3 = *(float *)(param_2 + 0x2c);
  fVar4 = *(float *)(param_2 + 0x34);
  fVar5 = *(float *)(param_2 + 0x20);
  fVar6 = *(float *)(param_2 + 0x28);
  fVar7 = *(float *)(param_2 + 0x14);
  fVar8 = *(float *)(param_2 + 0x1c);
  fVar9 = fVar8;
  fVar10 = fVar6;
  if (fVar8 < fVar6) {
    fVar9 = fVar6;
    fVar10 = fVar8;
  }
  fVar11 = fVar4;
  if ((fVar10 <= fVar4) && (fVar11 = fVar10, fVar9 < fVar4)) {
    fVar9 = fVar4;
  }
  if ((fVar2 < fVar11) || (fVar9 < fVar2)) {
    bVar12 = false;
  }
  else {
    fVar9 = fVar7;
    fVar10 = fVar5;
    if (fVar7 < fVar5) {
      fVar9 = fVar5;
      fVar10 = fVar7;
    }
    fVar11 = fVar3;
    if ((fVar10 <= fVar3) && (fVar11 = fVar10, fVar9 < fVar3)) {
      fVar9 = fVar3;
    }
    if ((fVar1 < fVar11) || (fVar9 < fVar1)) {
      bVar12 = false;
    }
    else {
      bVar12 = true;
    }
  }
  if (!bVar12) {
    return 0;
  }
  dVar13 = (double)((fVar6 - fVar8) * (fVar1 - fVar7) - (fVar5 - fVar7) * (fVar2 - fVar8));
  if (((dVar13 <= param_1) &&
      ((double)((fVar4 - fVar6) * (fVar1 - fVar5) - (fVar3 - fVar5) * (fVar2 - fVar6)) <= param_1))
     && ((double)((fVar8 - fVar4) * (fVar1 - fVar3) - (fVar7 - fVar3) * (fVar2 - fVar4)) <= param_1)
     ) {
    return 1;
  }
  param_1 = -param_1;
  if (((param_1 <= dVar13) &&
      (param_1 <= (double)((fVar4 - fVar6) * (fVar1 - fVar5) - (fVar3 - fVar5) * (fVar2 - fVar6))))
     && (param_1 <= (double)((fVar8 - fVar4) * (fVar1 - fVar3) - (fVar7 - fVar3) * (fVar2 - fVar4)))
     ) {
    return 1;
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8024c808) */
/* __stdcall cM3d_CrossY_Tri(cM3dGTri const *,
                             Vec const *,
                             cM3d_Range const *,
                             float *) */

undefined4
cM3d_CrossY_Tri(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  double dVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (G_CM3D_F_ABS_MIN <= ABS(*(float *)(param_1 + 4))) {
    local_38 = *param_2;
    local_34 = *param_3;
    local_30 = param_2[2];
    dVar3 = (double)::mtx::PSVECDotProduct(param_1,&local_38);
    dVar4 = (double)(float)((double)*(float *)(param_1 + 0xc) + dVar3);
    local_34 = param_3[1];
    dVar3 = (double)::mtx::PSVECDotProduct(param_1,&local_38);
    dVar3 = (double)(float)((double)*(float *)(param_1 + 0xc) + dVar3);
    if ((((double)0_0 < dVar4) && ((double)0_0 < dVar3)) ||
       ((dVar4 < (double)0_0 && (dVar3 < (double)0_0)))) {
      uVar1 = 0;
    }
    else {
      uVar1 = cM3d_CrossY_Tri(param_1,param_2,param_4);
    }
  }
  else {
    uVar1 = 0;
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar1;
}


/* __stdcall cM3d_CrossZ_Tri(cM3dGTri const *,
                             Vec const *,
                             float) */

undefined4 cM3d_CrossZ_Tri(double param_1,int param_2,float *param_3)

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
  bool bVar12;
  double dVar13;
  
  if (ABS(*(float *)(param_2 + 8)) < G_CM3D_F_ABS_MIN) {
    return 0;
  }
  fVar1 = param_3[1];
  fVar2 = *param_3;
  fVar3 = *(float *)(param_2 + 0x30);
  fVar4 = *(float *)(param_2 + 0x2c);
  fVar5 = *(float *)(param_2 + 0x24);
  fVar6 = *(float *)(param_2 + 0x20);
  fVar7 = *(float *)(param_2 + 0x18);
  fVar8 = *(float *)(param_2 + 0x14);
  fVar9 = fVar8;
  fVar10 = fVar6;
  if (fVar8 < fVar6) {
    fVar9 = fVar6;
    fVar10 = fVar8;
  }
  fVar11 = fVar4;
  if ((fVar10 <= fVar4) && (fVar11 = fVar10, fVar9 < fVar4)) {
    fVar9 = fVar4;
  }
  if ((fVar2 < fVar11) || (fVar9 < fVar2)) {
    bVar12 = false;
  }
  else {
    fVar9 = fVar7;
    fVar10 = fVar5;
    if (fVar7 < fVar5) {
      fVar9 = fVar5;
      fVar10 = fVar7;
    }
    fVar11 = fVar3;
    if ((fVar10 <= fVar3) && (fVar11 = fVar10, fVar9 < fVar3)) {
      fVar9 = fVar3;
    }
    if ((fVar1 < fVar11) || (fVar9 < fVar1)) {
      bVar12 = false;
    }
    else {
      bVar12 = true;
    }
  }
  if (!bVar12) {
    return 0;
  }
  dVar13 = (double)((fVar6 - fVar8) * (fVar1 - fVar7) - (fVar5 - fVar7) * (fVar2 - fVar8));
  if (((dVar13 <= param_1) &&
      ((double)((fVar4 - fVar6) * (fVar1 - fVar5) - (fVar3 - fVar5) * (fVar2 - fVar6)) <= param_1))
     && ((double)((fVar8 - fVar4) * (fVar1 - fVar3) - (fVar7 - fVar3) * (fVar2 - fVar4)) <= param_1)
     ) {
    return 1;
  }
  param_1 = -param_1;
  if (((param_1 <= dVar13) &&
      (param_1 <= (double)((fVar4 - fVar6) * (fVar1 - fVar5) - (fVar3 - fVar5) * (fVar2 - fVar6))))
     && (param_1 <= (double)((fVar8 - fVar4) * (fVar1 - fVar3) - (fVar7 - fVar3) * (fVar2 - fVar4)))
     ) {
    return 1;
  }
  return 0;
}


/* __stdcall cM3d_CrossZ_Tri(cM3dGTri const *,
                             Vec const *) */

undefined4 cM3d_CrossZ_Tri(int param_1,float *param_2)

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
  bool bVar12;
  
  if (ABS(*(float *)(param_1 + 8)) < G_CM3D_F_ABS_MIN) {
    return 0;
  }
  fVar1 = param_2[1];
  fVar2 = *param_2;
  fVar3 = *(float *)(param_1 + 0x30);
  fVar4 = *(float *)(param_1 + 0x2c);
  fVar5 = *(float *)(param_1 + 0x24);
  fVar6 = *(float *)(param_1 + 0x20);
  fVar7 = *(float *)(param_1 + 0x18);
  fVar8 = *(float *)(param_1 + 0x14);
  fVar9 = fVar8;
  fVar10 = fVar6;
  if (fVar8 < fVar6) {
    fVar9 = fVar6;
    fVar10 = fVar8;
  }
  fVar11 = fVar4;
  if ((fVar10 <= fVar4) && (fVar11 = fVar10, fVar9 < fVar4)) {
    fVar9 = fVar4;
  }
  if ((fVar2 < fVar11) || (fVar9 < fVar2)) {
    bVar12 = false;
  }
  else {
    fVar9 = fVar7;
    fVar10 = fVar5;
    if (fVar7 < fVar5) {
      fVar9 = fVar5;
      fVar10 = fVar7;
    }
    fVar11 = fVar3;
    if ((fVar10 <= fVar3) && (fVar11 = fVar10, fVar9 < fVar3)) {
      fVar9 = fVar3;
    }
    if ((fVar1 < fVar11) || (fVar9 < fVar1)) {
      bVar12 = false;
    }
    else {
      bVar12 = true;
    }
  }
  if (!bVar12) {
    return 0;
  }
  fVar9 = (fVar6 - fVar8) * (fVar1 - fVar7) - (fVar5 - fVar7) * (fVar2 - fVar8);
  if (((fVar9 <= _3420) &&
      ((fVar4 - fVar6) * (fVar1 - fVar5) - (fVar3 - fVar5) * (fVar2 - fVar6) <= _3420)) &&
     ((fVar8 - fVar4) * (fVar1 - fVar3) - (fVar7 - fVar3) * (fVar2 - fVar4) <= _3420)) {
    return 1;
  }
  if (((_20_0 <= fVar9) &&
      (_20_0 <= (fVar4 - fVar6) * (fVar1 - fVar5) - (fVar3 - fVar5) * (fVar2 - fVar6))) &&
     (_20_0 <= (fVar8 - fVar4) * (fVar1 - fVar3) - (fVar7 - fVar3) * (fVar2 - fVar4))) {
    return 1;
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall cM3d_CrossZ_Tri(cM3dGTri const *,
                             Vec const *,
                             float *) */

bool cM3d_CrossZ_Tri(float *param_1,float *param_2,float *param_3)

{
  char cVar1;
  
  cVar1 = cM3d_CrossZ_Tri();
  if (cVar1 != '\0') {
    *param_3 = ((*param_2 * -*param_1 - param_2[1] * param_1[1]) - param_1[3]) / param_1[2];
  }
  return cVar1 != '\0';
}


/* __stdcall cM3d_Cross_LinTri(cM3dGLin const *,
                               cM3dGTri const *,
                               Vec *,
                               bool,
                               bool) */

undefined4 cM3d_Cross_LinTri(undefined4 param_1,float *param_2,undefined4 param_3)

{
  char cVar1;
  
  cVar1 = cM3d_Cross_LinPla();
  if ((((cVar1 != '\0') &&
       ((ABS(*param_2) < _4190 || (cVar1 = cM3d_CrossX_Tri(param_2,param_3), cVar1 != '\0')))) &&
      ((ABS(param_2[1]) < _4190 || (cVar1 = cM3d_CrossY_Tri(param_2,param_3), cVar1 != '\0')))) &&
     ((ABS(param_2[2]) < _4190 || (cVar1 = cM3d_CrossZ_Tri(param_2,param_3), cVar1 != '\0')))) {
    return 1;
  }
  return 0;
}


/* __stdcall cM3d_Cross_LinTri_Easy(cM3dGTri const *,
                                    Vec const *) */

undefined4 cM3d_Cross_LinTri_Easy(float *param_1,undefined4 param_2)

{
  char cVar1;
  
  if ((((ABS(*param_1) < G_CM3D_F_ABS_MIN) || (cVar1 = cM3d_CrossX_Tri(), cVar1 != '\0')) &&
      ((ABS(param_1[1]) < G_CM3D_F_ABS_MIN ||
       (cVar1 = cM3d_CrossY_Tri(param_1,param_2), cVar1 != '\0')))) &&
     ((ABS(param_1[2]) < G_CM3D_F_ABS_MIN ||
      (cVar1 = cM3d_CrossZ_Tri(param_1,param_2), cVar1 != '\0')))) {
    return 1;
  }
  return 0;
}


/* WARNING: Removing unreachable block (ram,0x8024ce3c) */
/* __stdcall cM3d_Cross_SphPnt(cM3dGSph const *,
                               Vec const *) */

uint cM3d_Cross_SphPnt(cXyz *param_1,cXyz *param_2)

{
  undefined4 uVar1;
  undefined8 in_f31;
  double dVar2;
  float fVar3;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar2 = (double)param_1[1].x;
  fVar3 = ::mtx::PSVECSquareDistance(param_1,param_2);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return ((uint)(byte)((fVar3 <= (float)(dVar2 * dVar2)) << 1) << 0x1c) >> 0x1d;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8024d09c) */
/* __stdcall cM3d_Cross_LinSph(cM3dGLin const *,
                               cM3dGSph const *,
                               Vec *) */

uint cM3d_Cross_LinSph(cXyz *param_1,cXyz *param_2,cXyz *param_3)

{
  float fVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  float fVar7;
  cXyz cStack72;
  cXyz cStack60;
  cXyz cStack48;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar7 = param_2[1].x;
  fVar1 = param_2->x + fVar7;
  if ((param_1->x <= fVar1) || (param_1[1].x <= fVar1)) {
    fVar1 = param_2->x - fVar7;
    if ((fVar1 <= param_1->x) || (fVar1 <= param_1[1].x)) {
      fVar1 = param_2->y + fVar7;
      if ((param_1->y <= fVar1) || (param_1[1].y <= fVar1)) {
        fVar1 = param_2->y - fVar7;
        if ((fVar1 <= param_1->y) || (fVar1 <= param_1[1].y)) {
          fVar1 = param_2->z + fVar7;
          if ((param_1->z <= fVar1) || (param_1[1].z <= fVar1)) {
            fVar7 = param_2->z - fVar7;
            if ((fVar7 <= param_1->z) || (fVar7 <= param_1[1].z)) {
              ::mtx::PSVECSubtract(param_1 + 1,param_1,&cStack48);
              fVar7 = ::mtx::PSVECSquareMag(&cStack48);
              dVar6 = (double)fVar7;
              if (G_CM3D_F_ABS_MIN <= (float)ABS(dVar6)) {
                ::mtx::PSVECSubtract(param_2,param_1,&cStack60);
                dVar5 = (double)::mtx::PSVECDotProduct(&cStack60,&cStack48);
                fVar7 = (float)(dVar5 / dVar6);
                if ((fVar7 < 0_0) || (_2261 < fVar7)) {
                  fVar7 = ::mtx::PSVECSquareDistance(param_1 + 1,param_2);
                  dVar6 = (double)fVar7;
                  fVar7 = ::mtx::PSVECSquareDistance(param_1,param_2);
                  if (dVar6 <= (double)fVar7) {
                    cVar3 = cM3d_Cross_SphPnt(param_2,param_1 + 1);
                    if (cVar3 != '\0') {
                      param_3->x = param_1[1].x;
                      param_3->y = param_1[1].y;
                      param_3->z = param_1[1].z;
                      uVar2 = 1;
                      goto LAB_8024d09c;
                    }
                  }
                  else {
                    cVar3 = cM3d_Cross_SphPnt(param_2,param_1);
                    if (cVar3 != '\0') {
                      param_3->x = param_1->x;
                      param_3->y = param_1->y;
                      param_3->z = param_1->z;
                      uVar2 = 1;
                      goto LAB_8024d09c;
                    }
                  }
                  uVar2 = 0;
                }
                else {
                  ::mtx::PSVECScale(&cStack48,&cStack72,fVar7);
                  ::mtx::PSVECAdd(&cStack72,param_1,param_3);
                  dVar6 = (double)param_2[1].x;
                  fVar7 = ::mtx::PSVECSquareDistance(param_3,param_2);
                  uVar2 = ((uint)(byte)((fVar7 <= (float)(dVar6 * dVar6)) << 1) << 0x1c) >> 0x1d;
                }
              }
              else {
                uVar2 = 0;
              }
            }
            else {
              uVar2 = 0;
            }
          }
          else {
            uVar2 = 0;
          }
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
LAB_8024d09c:
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8024d350) */
/* WARNING: Removing unreachable block (ram,0x8024d348) */
/* WARNING: Removing unreachable block (ram,0x8024d358) */
/* __stdcall cM3d_Cross_LinSph_CrossPos(cM3dGSph const &,
                                        cM3dGLin const &,
                                        Vec *,
                                        Vec *) */

undefined4
cM3d_Cross_LinSph_CrossPos(cXyz *param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  cXyz cStack128;
  cXyz cStack116;
  cXyz cStack104;
  cXyz cStack92;
  cXyz cStack80;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  ::mtx::PSVECSubtract(param_2 + 1,param_2,&cStack80);
  ::mtx::PSVECSubtract(param_2,param_1,&cStack92);
  dVar3 = (double)::mtx::PSVECDotProduct(&cStack80,&cStack80);
  dVar4 = (double)::mtx::PSVECDotProduct(&cStack80,&cStack92);
  dVar7 = (double)(float)((double)_4410 * dVar4);
  dVar4 = (double)::mtx::PSVECDotProduct(&cStack92,&cStack92);
  dVar4 = (double)(float)(dVar4 - (double)(param_1[1].x * param_1[1].x));
  if (G_CM3D_F_ABS_MIN <= (float)ABS(dVar3)) {
    dVar4 = (double)((float)(dVar7 * dVar7) -
                    (float)((double)(float)((double)_4411 * dVar3) * dVar4));
    if (G_CM3D_F_ABS_MIN <= (float)ABS(dVar4)) {
      if ((double)0_0 <= dVar4) {
        uVar1 = 2;
        dVar6 = (double)(_2261 / (float)((double)_4410 * dVar3));
        dVar3 = dVar4;
        if ((double)0_0 < dVar4) {
          dVar3 = 1.0 / SQRT(dVar4);
          dVar3 = _2240 * dVar3 * (_2241 - dVar4 * dVar3 * dVar3);
          dVar3 = _2240 * dVar3 * (_2241 - dVar4 * dVar3 * dVar3);
          dVar3 = (double)(float)(dVar4 * _2240 * dVar3 * (_2241 - dVar4 * dVar3 * dVar3));
        }
        dVar7 = -dVar7;
        if ((double)0_0 < dVar4) {
          dVar5 = 1.0 / SQRT(dVar4);
          dVar5 = _2240 * dVar5 * (_2241 - dVar4 * dVar5 * dVar5);
          dVar5 = _2240 * dVar5 * (_2241 - dVar4 * dVar5 * dVar5);
          dVar4 = (double)(float)(dVar4 * _2240 * dVar5 * (_2241 - dVar4 * dVar5 * dVar5));
        }
        ::mtx::PSVECScale(&cStack80,&cStack128,(float)(dVar6 * (double)(float)(dVar7 + dVar3)));
        ::mtx::PSVECAdd(&cStack128,param_2,param_3);
        ::mtx::PSVECScale(&cStack80,&cStack128,(float)(dVar6 * (double)(float)(dVar7 - dVar4)));
        ::mtx::PSVECAdd(&cStack128,param_2,param_4);
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 1;
      ::mtx::PSVECScale(&cStack80,&cStack116,
                        (float)(-dVar7 / (double)(float)((double)_4410 * dVar3)));
      ::mtx::PSVECAdd(&cStack116,param_2,param_3);
    }
  }
  else {
    if ((float)ABS(dVar7) < G_CM3D_F_ABS_MIN) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
      ::mtx::PSVECScale(&cStack80,&cStack104,(float)(-dVar4 / dVar7));
      ::mtx::PSVECAdd(&cStack104,param_2,param_3);
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8024db14) */
/* __stdcall cM3d_Cross_CylSph(cM3dGCyl const *,
                               cM3dGSph const *,
                               Vec *,
                               float *) */

undefined4 cM3d_Cross_CylSph(cXyz *param_1,cXyz *param_2,cXyz *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  undefined8 in_f31;
  cXyz cStack44;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar1 = param_2->x;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0x9c2,
               "!(((sizeof(pnow_sph_center->x) == sizeof(float)) ? __fpclassifyf((float)(pnow_sph_center->x)) : __fpclassifyd((double)(pnow_sph_center->x)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0x9c2,&DAT_80364f1e);
  }
  fVar1 = param_2->y;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0x9c3,
               "!(((sizeof(pnow_sph_center->y) == sizeof(float)) ? __fpclassifyf((float)(pnow_sph_center->y)) : __fpclassifyd((double)(pnow_sph_center->y)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0x9c3,&DAT_80364f1e);
  }
  fVar1 = param_2->z;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0x9c4,
               "!(((sizeof(pnow_sph_center->z) == sizeof(float)) ? __fpclassifyf((float)(pnow_sph_center->z)) : __fpclassifyd((double)(pnow_sph_center->z)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0x9c4,&DAT_80364f1e);
  }
  fVar1 = param_2[1].x;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0x9c5,
               "!(((sizeof(psph->GetR()) == sizeof(float)) ? __fpclassifyf((float)(psph->GetR())) : __fpclassifyd((double)(psph->GetR())) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0x9c5,&DAT_80364f1e);
  }
  fVar1 = param_1->x;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0x9c7,
               "!(((sizeof(pnow_cyl_center->x) == sizeof(float)) ? __fpclassifyf((float)(pnow_cyl_center->x)) : __fpclassifyd((double)(pnow_cyl_center->x)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0x9c7,&DAT_80364f1e);
  }
  fVar1 = param_1->y;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0x9c8,
               "!(((sizeof(pnow_cyl_center->y) == sizeof(float)) ? __fpclassifyf((float)(pnow_cyl_center->y)) : __fpclassifyd((double)(pnow_cyl_center->y)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0x9c8,&DAT_80364f1e);
  }
  fVar1 = param_1->z;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0x9c9,
               "!(((sizeof(pnow_cyl_center->z) == sizeof(float)) ? __fpclassifyf((float)(pnow_cyl_center->z)) : __fpclassifyd((double)(pnow_cyl_center->z)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0x9c9,&DAT_80364f1e);
  }
  fVar1 = param_1[1].y;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0x9ca,
               "!(((sizeof(pcyl->GetH()) == sizeof(float)) ? __fpclassifyf((float)(pcyl->GetH())) : __fpclassifyd((double)(pcyl->GetH())) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0x9ca,&DAT_80364f1e);
  }
  fVar1 = param_1[1].x;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0x9cb,
               "!(((sizeof(pcyl->GetR()) == sizeof(float)) ? __fpclassifyf((float)(pcyl->GetR())) : __fpclassifyd((double)(pcyl->GetR())) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0x9cb,&DAT_80364f1e);
  }
  dVar8 = (double)(param_1[1].x + param_2[1].x);
  fVar1 = param_2->x - param_1->x;
  fVar2 = param_2->z - param_1->z;
  dVar10 = (double)(fVar1 * fVar1 + fVar2 * fVar2);
  if ((double)0_0 < dVar10) {
    dVar9 = 1.0 / SQRT(dVar10);
    dVar9 = _2240 * dVar9 * (_2241 - dVar10 * dVar9 * dVar9);
    dVar9 = _2240 * dVar9 * (_2241 - dVar10 * dVar9 * dVar9);
    dVar10 = (double)(float)(dVar10 * _2240 * dVar9 * (_2241 - dVar10 * dVar9 * dVar9));
  }
  if (dVar8 < dVar10) {
    uVar6 = 0;
  }
  else {
    if ((param_2->y + param_2[1].x < param_1->y) ||
       (param_1->y + param_1[1].y < param_2->y - param_2[1].x)) {
      uVar6 = 0;
    }
    else {
      *param_4 = (float)(dVar8 - dVar10);
      if ((float)ABS(dVar10) < G_CM3D_F_ABS_MIN) {
        param_3->x = param_2->x;
        param_3->y = param_2->y;
        param_3->z = param_2->z;
      }
      else {
        dVar8 = (double)(float)((double)param_1[1].x / dVar10);
        if ((double)_2261 < dVar8) {
          param_3->x = param_2->x;
          param_3->y = param_2->y;
          param_3->z = param_2->z;
        }
        else {
          ::mtx::PSVECSubtract(param_2,param_1,&cStack44);
          ::mtx::PSVECScale(&cStack44,&cStack44,(float)dVar8);
          ::mtx::PSVECAdd(&cStack44,param_1,param_3);
        }
      }
      fVar1 = *param_4;
      uVar3 = (uint)fVar1 & 0x7f800000;
      if (uVar3 == 0x7f800000) {
        if (((uint)fVar1 & 0x7fffff) == 0) {
          iVar4 = 2;
        }
        else {
          iVar4 = 1;
        }
      }
      else {
        if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
          if (((uint)fVar1 & 0x7fffff) == 0) {
            iVar4 = 3;
          }
          else {
            iVar4 = 5;
          }
        }
        else {
          iVar4 = 4;
        }
      }
      if (iVar4 == 1) {
        uVar5 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar5,"c_m3d.cpp",0x9eb,
                   "!(((sizeof(*pcross_len) == sizeof(float)) ? __fpclassifyf((float)(*pcross_len)) : __fpclassifyd((double)(*pcross_len)) ) == 1)"
                  );
        m_Do_printf::OSPanic("c_m3d.cpp",0x9eb,&DAT_80364f1e);
      }
      uVar6 = 1;
    }
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return uVar6;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall cM3d_Cross_SphSph(cM3dGSph const *,
                               cM3dGSph const *,
                               float *,
                               float *) */

undefined4 cM3d_Cross_SphSph(cXyz *param_1,cXyz *param_2,float *param_3,float *param_4)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined4 uVar4;
  float fVar5;
  cXyz cStack32;
  
  fVar5 = param_1->x;
  uVar1 = (uint)fVar5 & 0x7f800000;
  if (uVar1 == 0x7f800000) {
    if (((uint)fVar5 & 0x7fffff) == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = 1;
    }
  }
  else {
    if ((uVar1 < 0x7f800000) && (uVar1 == 0)) {
      if (((uint)fVar5 & 0x7fffff) == 0) {
        iVar2 = 3;
      }
      else {
        iVar2 = 5;
      }
    }
    else {
      iVar2 = 4;
    }
  }
  if (iVar2 == 1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar3,"c_m3d.cpp",0xa05,
               "!(((sizeof(i_a->GetCP()->x) == sizeof(float)) ? __fpclassifyf((float)(i_a->GetCP()->x)) : __fpclassifyd((double)(i_a->GetCP()->x)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xa05,&DAT_80364f1e);
  }
  fVar5 = param_1->y;
  uVar1 = (uint)fVar5 & 0x7f800000;
  if (uVar1 == 0x7f800000) {
    if (((uint)fVar5 & 0x7fffff) == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = 1;
    }
  }
  else {
    if ((uVar1 < 0x7f800000) && (uVar1 == 0)) {
      if (((uint)fVar5 & 0x7fffff) == 0) {
        iVar2 = 3;
      }
      else {
        iVar2 = 5;
      }
    }
    else {
      iVar2 = 4;
    }
  }
  if (iVar2 == 1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar3,"c_m3d.cpp",0xa06,
               "!(((sizeof(i_a->GetCP()->y) == sizeof(float)) ? __fpclassifyf((float)(i_a->GetCP()->y)) : __fpclassifyd((double)(i_a->GetCP()->y)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xa06,&DAT_80364f1e);
  }
  fVar5 = param_1->z;
  uVar1 = (uint)fVar5 & 0x7f800000;
  if (uVar1 == 0x7f800000) {
    if (((uint)fVar5 & 0x7fffff) == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = 1;
    }
  }
  else {
    if ((uVar1 < 0x7f800000) && (uVar1 == 0)) {
      if (((uint)fVar5 & 0x7fffff) == 0) {
        iVar2 = 3;
      }
      else {
        iVar2 = 5;
      }
    }
    else {
      iVar2 = 4;
    }
  }
  if (iVar2 == 1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar3,"c_m3d.cpp",0xa07,
               "!(((sizeof(i_a->GetCP()->z) == sizeof(float)) ? __fpclassifyf((float)(i_a->GetCP()->z)) : __fpclassifyd((double)(i_a->GetCP()->z)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xa07,&DAT_80364f1e);
  }
  fVar5 = param_1[1].x;
  uVar1 = (uint)fVar5 & 0x7f800000;
  if (uVar1 == 0x7f800000) {
    if (((uint)fVar5 & 0x7fffff) == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = 1;
    }
  }
  else {
    if ((uVar1 < 0x7f800000) && (uVar1 == 0)) {
      if (((uint)fVar5 & 0x7fffff) == 0) {
        iVar2 = 3;
      }
      else {
        iVar2 = 5;
      }
    }
    else {
      iVar2 = 4;
    }
  }
  if (iVar2 == 1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar3,"c_m3d.cpp",0xa08,
               "!(((sizeof(i_a->GetR()) == sizeof(float)) ? __fpclassifyf((float)(i_a->GetR())) : __fpclassifyd((double)(i_a->GetR())) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xa08,&DAT_80364f1e);
  }
  fVar5 = param_2->x;
  uVar1 = (uint)fVar5 & 0x7f800000;
  if (uVar1 == 0x7f800000) {
    if (((uint)fVar5 & 0x7fffff) == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = 1;
    }
  }
  else {
    if ((uVar1 < 0x7f800000) && (uVar1 == 0)) {
      if (((uint)fVar5 & 0x7fffff) == 0) {
        iVar2 = 3;
      }
      else {
        iVar2 = 5;
      }
    }
    else {
      iVar2 = 4;
    }
  }
  if (iVar2 == 1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar3,"c_m3d.cpp",0xa09,
               "!(((sizeof(i_b->GetCP()->x) == sizeof(float)) ? __fpclassifyf((float)(i_b->GetCP()->x)) : __fpclassifyd((double)(i_b->GetCP()->x)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xa09,&DAT_80364f1e);
  }
  fVar5 = param_2->y;
  uVar1 = (uint)fVar5 & 0x7f800000;
  if (uVar1 == 0x7f800000) {
    if (((uint)fVar5 & 0x7fffff) == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = 1;
    }
  }
  else {
    if ((uVar1 < 0x7f800000) && (uVar1 == 0)) {
      if (((uint)fVar5 & 0x7fffff) == 0) {
        iVar2 = 3;
      }
      else {
        iVar2 = 5;
      }
    }
    else {
      iVar2 = 4;
    }
  }
  if (iVar2 == 1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar3,"c_m3d.cpp",0xa0a,
               "!(((sizeof(i_b->GetCP()->y) == sizeof(float)) ? __fpclassifyf((float)(i_b->GetCP()->y)) : __fpclassifyd((double)(i_b->GetCP()->y)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xa0a,&DAT_80364f1e);
  }
  fVar5 = param_2->z;
  uVar1 = (uint)fVar5 & 0x7f800000;
  if (uVar1 == 0x7f800000) {
    if (((uint)fVar5 & 0x7fffff) == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = 1;
    }
  }
  else {
    if ((uVar1 < 0x7f800000) && (uVar1 == 0)) {
      if (((uint)fVar5 & 0x7fffff) == 0) {
        iVar2 = 3;
      }
      else {
        iVar2 = 5;
      }
    }
    else {
      iVar2 = 4;
    }
  }
  if (iVar2 == 1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar3,"c_m3d.cpp",0xa0b,
               "!(((sizeof(i_b->GetCP()->z) == sizeof(float)) ? __fpclassifyf((float)(i_b->GetCP()->z)) : __fpclassifyd((double)(i_b->GetCP()->z)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xa0b,&DAT_80364f1e);
  }
  fVar5 = param_2[1].x;
  uVar1 = (uint)fVar5 & 0x7f800000;
  if (uVar1 == 0x7f800000) {
    if (((uint)fVar5 & 0x7fffff) == 0) {
      iVar2 = 2;
    }
    else {
      iVar2 = 1;
    }
  }
  else {
    if ((uVar1 < 0x7f800000) && (uVar1 == 0)) {
      if (((uint)fVar5 & 0x7fffff) == 0) {
        iVar2 = 3;
      }
      else {
        iVar2 = 5;
      }
    }
    else {
      iVar2 = 4;
    }
  }
  if (iVar2 == 1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar3,"c_m3d.cpp",0xa0c,
               "!(((sizeof(i_b->GetR()) == sizeof(float)) ? __fpclassifyf((float)(i_b->GetR())) : __fpclassifyd((double)(i_b->GetR())) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xa0c,&DAT_80364f1e);
  }
  ::mtx::PSVECSubtract(param_1,param_2,&cStack32);
  fVar5 = ::mtx::PSVECMag(&cStack32);
  *param_3 = fVar5;
  *param_4 = (param_1[1].x + param_2[1].x) - *param_3;
  fVar5 = *param_4;
  if (fVar5 <= _4703) {
    *param_4 = 0_0;
    fVar5 = *param_4;
    uVar1 = (uint)fVar5 & 0x7f800000;
    if (uVar1 == 0x7f800000) {
      if (((uint)fVar5 & 0x7fffff) == 0) {
        iVar2 = 2;
      }
      else {
        iVar2 = 1;
      }
    }
    else {
      if ((uVar1 < 0x7f800000) && (uVar1 == 0)) {
        if (((uint)fVar5 & 0x7fffff) == 0) {
          iVar2 = 3;
        }
        else {
          iVar2 = 5;
        }
      }
      else {
        iVar2 = 4;
      }
    }
    if (iVar2 == 1) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar3,"c_m3d.cpp",0xa1b,
                 "!(((sizeof(*i_pcc_crosslen) == sizeof(float)) ? __fpclassifyf((float)(*i_pcc_crosslen)) : __fpclassifyd((double)(*i_pcc_crosslen)) ) == 1)"
                );
      m_Do_printf::OSPanic("c_m3d.cpp",0xa1b,&DAT_80364f1e);
    }
    uVar4 = 0;
  }
  else {
    uVar1 = (uint)fVar5 & 0x7f800000;
    if (uVar1 == 0x7f800000) {
      if (((uint)fVar5 & 0x7fffff) == 0) {
        iVar2 = 2;
      }
      else {
        iVar2 = 1;
      }
    }
    else {
      if ((uVar1 < 0x7f800000) && (uVar1 == 0)) {
        if (((uint)fVar5 & 0x7fffff) == 0) {
          iVar2 = 3;
        }
        else {
          iVar2 = 5;
        }
      }
      else {
        iVar2 = 4;
      }
    }
    if (iVar2 == 1) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar3,"c_m3d.cpp",0xa16,
                 "!(((sizeof(*i_pcc_crosslen) == sizeof(float)) ? __fpclassifyf((float)(*i_pcc_crosslen)) : __fpclassifyd((double)(*i_pcc_crosslen)) ) == 1)"
                );
      m_Do_printf::OSPanic("c_m3d.cpp",0xa16,&DAT_80364f1e);
    }
    uVar4 = 1;
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8024e268) */
/* __stdcall cM3d_Cross_SphSph(cM3dGSph const *,
                               cM3dGSph const *,
                               Vec *) */

undefined4 cM3d_Cross_SphSph(cXyz *param_1,cXyz *param_2,cXyz *param_3)

{
  char cVar2;
  undefined4 uVar1;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack56 [4];
  float local_34;
  cXyz cStack48;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  cVar2 = cM3d_Cross_SphSph(param_1,param_2,&local_34,auStack56);
  if (cVar2 == '\0') {
    uVar1 = 0;
  }
  else {
    if (ABS(local_34) < G_CM3D_F_ABS_MIN) {
      param_3->x = param_1->x;
      param_3->y = param_1->y;
      param_3->z = param_1->z;
    }
    else {
      dVar4 = (double)(param_2[1].x / local_34);
      ::mtx::PSVECSubtract(param_1,param_2,&cStack48);
      ::mtx::PSVECScale(&cStack48,&cStack48,(float)dVar4);
      ::mtx::PSVECAdd(&cStack48,param_2,param_3);
    }
    uVar1 = 1;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return uVar1;
}


/* __stdcall cM3d_CalcSphVsTriCrossPoint(cM3dGSph const *,
                                         cM3dGTri const *,
                                         Vec *) */

void cM3d_CalcSphVsTriCrossPoint(cXyz *param_1,int param_2,float *param_3)

{
  float fVar1;
  cXyz cStack40;
  cXyz cStack28;
  
  ::mtx::PSVECAdd((cXyz *)(param_2 + 0x14),(cXyz *)(param_2 + 0x20),&cStack40);
  ::mtx::PSVECScale(&cStack40,&cStack28,_4738);
  fVar1 = ::mtx::PSVECSquareDistance(&cStack28,param_1);
  if (G_CM3D_F_ABS_MIN <= ABS(fVar1)) {
    cM3d_InDivPos2((double)(param_1[1].x / fVar1),param_1,&cStack28,param_3);
  }
  else {
    *param_3 = param_1->x;
    param_3[1] = param_1->y;
    param_3[2] = param_1->z;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall cM3d_Cross_SphTri(cM3dGSph const *,
                               cM3dGTri const *,
                               Vec *) */

undefined4 cM3d_Cross_SphTri(cXyz *param_1,cM3dGPla *param_2,int param_3)

{
  char cVar2;
  undefined4 uVar1;
  double dVar3;
  undefined auStack232 [12];
  undefined auStack220 [12];
  undefined auStack208 [12];
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  undefined *local_9c;
  float local_98;
  float local_94;
  undefined *local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  cXyz cStack124;
  cXyz cStack112;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  undefined **local_4c;
  float local_48;
  undefined *local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined **local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined *local_1c;
  float local_18;
  undefined **local_14;
  
  cVar2 = cM3d_InclusionCheckPosIn3PosBox3d
                    ((double)param_1[1].x,param_2 + 1,&param_2[1].mDist,&param_2[2].mNorm.y,param_1)
  ;
  if (cVar2 == '\0') {
    uVar1 = 0;
  }
  else {
    dVar3 = (double)cM3d_SignedLenPlaAndPos(param_2,param_1);
    if ((float)ABS(dVar3) <= param_1[1].x) {
      ::mtx::PSVECScale((cXyz *)param_2,&cStack124,(float)dVar3);
      ::mtx::PSVECSubtract(param_1,&cStack124,&cStack112);
      if (ABS((param_2->mNorm).y) <= _4738) {
        if (ABS((param_2->mNorm).x) <= _4738) {
          cVar2 = cM3d_CrossZ_Tri((double)0_0,param_2,&cStack112);
          if (cVar2 != '\0') {
            if (param_3 != 0) {
              cM3d_CalcSphVsTriCrossPoint(param_1,param_2,param_3);
            }
            return 1;
          }
        }
        else {
          cVar2 = cM3d_CrossX_Tri((double)0_0,param_2,&cStack112);
          if (cVar2 != '\0') {
            if (param_3 != 0) {
              cM3d_CalcSphVsTriCrossPoint(param_1,param_2,param_3);
            }
            return 1;
          }
        }
      }
      else {
        cVar2 = cM3d_CrossY_Tri((double)0_0,param_2,&cStack112);
        if (cVar2 != '\0') {
          if (param_3 != 0) {
            cM3d_CalcSphVsTriCrossPoint(param_1,param_2,param_3);
          }
          return 1;
        }
      }
      local_88 = param_2[1].mNorm.x;
      local_84 = param_2[1].mNorm.y;
      local_80 = param_2[1].mNorm.z;
      local_94 = param_2[1].mDist;
      local_90 = param_2[1].vtbl;
      local_8c = param_2[2].mNorm.x;
      local_14 = &::cM3dGLin::__vt;
      local_2c = local_88;
      local_28 = local_84;
      local_24 = local_80;
      local_20 = local_94;
      local_1c = local_90;
      local_18 = local_8c;
      cVar2 = cM3d_Cross_LinSph(&local_2c,param_1,auStack208);
      if (cVar2 == '\0') {
        local_a0 = param_2[1].mDist;
        local_9c = param_2[1].vtbl;
        local_98 = param_2[2].mNorm.x;
        local_ac = param_2[2].mNorm.y;
        local_a8 = param_2[2].mNorm.z;
        local_a4 = param_2[2].mDist;
        local_30 = &::cM3dGLin::__vt;
        local_48 = local_a0;
        local_44 = local_9c;
        local_40 = local_98;
        local_3c = local_ac;
        local_38 = local_a8;
        local_34 = local_a4;
        cVar2 = cM3d_Cross_LinSph(&local_48,param_1,auStack220);
        if (cVar2 == '\0') {
          local_b8 = param_2[2].mNorm.y;
          local_b4 = param_2[2].mNorm.z;
          local_b0 = param_2[2].mDist;
          local_c4 = param_2[1].mNorm.x;
          local_c0 = param_2[1].mNorm.y;
          local_bc = param_2[1].mNorm.z;
          local_4c = &::cM3dGLin::__vt;
          local_64 = local_b8;
          local_60 = local_b4;
          local_5c = local_b0;
          local_58 = local_c4;
          local_54 = local_c0;
          local_50 = local_bc;
          cVar2 = cM3d_Cross_LinSph(&local_64,param_1,auStack232);
          if (cVar2 == '\0') {
            uVar1 = 0;
          }
          else {
            if (param_3 != 0) {
              cM3d_CalcSphVsTriCrossPoint(param_1,param_2,param_3);
            }
            uVar1 = 1;
          }
        }
        else {
          if (param_3 != 0) {
            cM3d_CalcSphVsTriCrossPoint(param_1,param_2,param_3);
          }
          uVar1 = 1;
        }
      }
      else {
        if (param_3 != 0) {
          cM3d_CalcSphVsTriCrossPoint(param_1,param_2,param_3);
        }
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall cM3d_Cross_CylCyl(cM3dGCyl const *,
                               cM3dGCyl const *,
                               float *) */

int cM3d_Cross_CylCyl(cM3dGCyl *param_1,cM3dGCyl *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  fVar1 = (param_1->mCenter).x;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0xb0a,
               "!(((sizeof(c1.x) == sizeof(float)) ? __fpclassifyf((float)(c1.x)) : __fpclassifyd((double)(c1.x)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xb0a,&DAT_80364f1e);
  }
  fVar1 = (param_1->mCenter).y;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0xb0b,
               "!(((sizeof(c1.y) == sizeof(float)) ? __fpclassifyf((float)(c1.y)) : __fpclassifyd((double)(c1.y)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xb0b,&DAT_80364f1e);
  }
  fVar1 = (param_1->mCenter).z;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0xb0c,
               "!(((sizeof(c1.z) == sizeof(float)) ? __fpclassifyf((float)(c1.z)) : __fpclassifyd((double)(c1.z)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xb0c,&DAT_80364f1e);
  }
  fVar1 = param_1->mRadius;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0xb0d,
               "!(((sizeof(i_cyl1->GetR()) == sizeof(float)) ? __fpclassifyf((float)(i_cyl1->GetR())) : __fpclassifyd((double)(i_cyl1->GetR())) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xb0d,&DAT_80364f1e);
  }
  fVar1 = param_1->mHeight;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0xb0e,
               "!(((sizeof(i_cyl1->GetH()) == sizeof(float)) ? __fpclassifyf((float)(i_cyl1->GetH())) : __fpclassifyd((double)(i_cyl1->GetH())) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xb0e,&DAT_80364f1e);
  }
  fVar1 = (param_2->mCenter).x;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0xb10,
               "!(((sizeof(c2.x) == sizeof(float)) ? __fpclassifyf((float)(c2.x)) : __fpclassifyd((double)(c2.x)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xb10,&DAT_80364f1e);
  }
  fVar1 = (param_2->mCenter).y;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0xb11,
               "!(((sizeof(c2.y) == sizeof(float)) ? __fpclassifyf((float)(c2.y)) : __fpclassifyd((double)(c2.y)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xb11,&DAT_80364f1e);
  }
  fVar1 = (param_2->mCenter).z;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0xb12,
               "!(((sizeof(c2.z) == sizeof(float)) ? __fpclassifyf((float)(c2.z)) : __fpclassifyd((double)(c2.z)) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xb12,&DAT_80364f1e);
  }
  fVar1 = param_2->mRadius;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0xb13,
               "!(((sizeof(i_cyl2->GetR()) == sizeof(float)) ? __fpclassifyf((float)(i_cyl2->GetR())) : __fpclassifyd((double)(i_cyl2->GetR())) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xb13,&DAT_80364f1e);
  }
  fVar1 = param_2->mHeight;
  uVar3 = (uint)fVar1 & 0x7f800000;
  if (uVar3 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"c_m3d.cpp",0xb14,
               "!(((sizeof(i_cyl2->GetH()) == sizeof(float)) ? __fpclassifyf((float)(i_cyl2->GetH())) : __fpclassifyd((double)(i_cyl2->GetH())) ) == 1)"
              );
    m_Do_printf::OSPanic("c_m3d.cpp",0xb14,&DAT_80364f1e);
  }
  fVar1 = (param_1->mCenter).x - (param_2->mCenter).x;
  fVar2 = (param_1->mCenter).z - (param_2->mCenter).z;
  dVar7 = (double)(fVar1 * fVar1 + fVar2 * fVar2);
  dVar8 = (double)(param_1->mRadius + param_2->mRadius);
  if (dVar7 <= (double)(float)(dVar8 * dVar8)) {
    fVar1 = (param_1->mCenter).y;
    fVar2 = (param_2->mCenter).y;
    if ((fVar1 + param_1->mHeight < fVar2) || (fVar2 + param_2->mHeight < fVar1)) {
      *param_3 = 0_0;
      fVar1 = *param_3;
      uVar3 = (uint)fVar1 & 0x7f800000;
      if (uVar3 == 0x7f800000) {
        if (((uint)fVar1 & 0x7fffff) == 0) {
          iVar4 = 2;
        }
        else {
          iVar4 = 1;
        }
      }
      else {
        if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
          if (((uint)fVar1 & 0x7fffff) == 0) {
            iVar4 = 3;
          }
          else {
            iVar4 = 5;
          }
        }
        else {
          iVar4 = 4;
        }
      }
      if (iVar4 == 1) {
        uVar5 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar5,"c_m3d.cpp",0xb29,
                   "!(((sizeof(*i_pcross_len) == sizeof(float)) ? __fpclassifyf((float)(*i_pcross_len)) : __fpclassifyd((double)(*i_pcross_len)) ) == 1)"
                  );
        m_Do_printf::OSPanic("c_m3d.cpp",0xb29,&DAT_80364f1e);
      }
      iVar4 = 0;
    }
    else {
      if ((double)0_0 < dVar7) {
        dVar6 = 1.0 / SQRT(dVar7);
        dVar6 = _2240 * dVar6 * (_2241 - dVar7 * dVar6 * dVar6);
        dVar6 = _2240 * dVar6 * (_2241 - dVar7 * dVar6 * dVar6);
        dVar7 = (double)(float)(dVar7 * _2240 * dVar6 * (_2241 - dVar7 * dVar6 * dVar6));
      }
      *param_3 = (float)(dVar8 - dVar7);
      fVar1 = *param_3;
      uVar3 = (uint)fVar1 & 0x7f800000;
      if (uVar3 == 0x7f800000) {
        if (((uint)fVar1 & 0x7fffff) == 0) {
          iVar4 = 2;
        }
        else {
          iVar4 = 1;
        }
      }
      else {
        if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
          if (((uint)fVar1 & 0x7fffff) == 0) {
            iVar4 = 3;
          }
          else {
            iVar4 = 5;
          }
        }
        else {
          iVar4 = 4;
        }
      }
      if (iVar4 == 1) {
        uVar5 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar5,"c_m3d.cpp",0xb30,
                   "!(((sizeof(*i_pcross_len) == sizeof(float)) ? __fpclassifyf((float)(*i_pcross_len)) : __fpclassifyd((double)(*i_pcross_len)) ) == 1)"
                  );
        m_Do_printf::OSPanic("c_m3d.cpp",0xb30,&DAT_80364f1e);
      }
      iVar4 = 1;
    }
  }
  else {
    *param_3 = 0_0;
    fVar1 = *param_3;
    uVar3 = (uint)fVar1 & 0x7f800000;
    if (uVar3 == 0x7f800000) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 2;
      }
      else {
        iVar4 = 1;
      }
    }
    else {
      if ((uVar3 < 0x7f800000) && (uVar3 == 0)) {
        if (((uint)fVar1 & 0x7fffff) == 0) {
          iVar4 = 3;
        }
        else {
          iVar4 = 5;
        }
      }
      else {
        iVar4 = 4;
      }
    }
    if (iVar4 == 1) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar5,"c_m3d.cpp",0xb21,
                 "!(((sizeof(*i_pcross_len) == sizeof(float)) ? __fpclassifyf((float)(*i_pcross_len)) : __fpclassifyd((double)(*i_pcross_len)) ) == 1)"
                );
      m_Do_printf::OSPanic("c_m3d.cpp",0xb21,&DAT_80364f1e);
    }
    iVar4 = 0;
  }
  return iVar4;
}


/* __stdcall cM3d_Cross_CylCyl(cM3dGCyl const *,
                               cM3dGCyl const *,
                               Vec *) */

undefined4 cM3d_Cross_CylCyl(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  
  dVar5 = (double)((*param_1 - *param_2) * (*param_1 - *param_2) +
                  (param_1[2] - param_2[2]) * (param_1[2] - param_2[2]));
  if (dVar5 <= (double)((param_1[3] + param_2[3]) * (param_1[3] + param_2[3]))) {
    if ((param_1[1] + param_1[4] < param_2[1]) || (param_2[1] + param_2[4] < param_1[1])) {
      uVar3 = 0;
    }
    else {
      if ((double)0_0 < dVar5) {
        dVar4 = 1.0 / SQRT(dVar5);
        dVar4 = _2240 * dVar4 * (_2241 - dVar5 * dVar4 * dVar4);
        dVar4 = _2240 * dVar4 * (_2241 - dVar5 * dVar4 * dVar4);
        dVar5 = (double)(float)(dVar5 * _2240 * dVar4 * (_2241 - dVar5 * dVar4 * dVar4));
      }
      if ((float)ABS(dVar5) < G_CM3D_F_ABS_MIN) {
        *param_3 = *param_2;
        param_3[1] = param_2[1];
        param_3[2] = param_2[2];
      }
      else {
        fVar1 = param_2[3];
        param_3[1] = param_2[1] + _4738 * param_2[4];
        fVar2 = param_1[1];
        if (fVar2 <= param_3[1]) {
          if (fVar2 + param_1[4] < param_3[1]) {
            param_3[1] = fVar2 + param_1[4];
          }
        }
        else {
          param_3[1] = fVar2;
        }
        *param_3 = *param_2 + (float)((double)fVar1 / dVar5) * (*param_1 - *param_2);
        param_3[2] = param_2[2] + (float)((double)fVar1 / dVar5) * (param_1[2] - param_2[2]);
      }
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8024f3e8) */
/* WARNING: Removing unreachable block (ram,0x8024f3f0) */
/* __stdcall cM3d_Cross_CylTri(cM3dGCyl const *,
                               cM3dGTri const *,
                               Vec *) */

undefined4 cM3d_Cross_CylTri(float *param_1,int param_2,float *param_3)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar6;
  float fVar7;
  float local_84;
  float local_80;
  float local_7c;
  cXyz cStack120;
  cXyz local_6c;
  cXyz local_60;
  cXyz local_54;
  undefined auStack72 [12];
  cXyz local_3c;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar5 = (double)param_1[1];
  dVar6 = (double)(float)(dVar5 + (double)param_1[4]);
  if (((((double)*(float *)(param_2 + 0x18) < dVar5) && ((double)*(float *)(param_2 + 0x24) < dVar5)
       ) && ((double)*(float *)(param_2 + 0x30) < dVar5)) ||
     (((dVar6 < (double)*(float *)(param_2 + 0x18) && (dVar6 < (double)*(float *)(param_2 + 0x24)))
      && (dVar6 < (double)*(float *)(param_2 + 0x30))))) {
    uVar1 = 0;
  }
  else {
    dVar5 = (double)_5243;
    iVar2 = cM3d_Cross_CylPntPnt(param_1,param_2 + 0x14,param_2 + 0x20,&local_3c,auStack72);
    if (iVar2 != 0) {
      fVar7 = ::mtx::PSVECSquareDistance(&local_3c,(cXyz *)(param_2 + 0x14));
      dVar5 = (double)fVar7;
      *param_3 = local_3c.x;
      param_3[1] = local_3c.y;
      param_3[2] = local_3c.z;
    }
    iVar2 = cM3d_Cross_CylPntPnt(param_1,param_2 + 0x2c,param_2 + 0x20,&local_3c,auStack72);
    if (iVar2 != 0) {
      fVar7 = ::mtx::PSVECSquareDistance(&local_3c,(cXyz *)(param_2 + 0x2c));
      if ((double)fVar7 < dVar5) {
        *param_3 = local_3c.x;
        param_3[1] = local_3c.y;
        param_3[2] = local_3c.z;
        dVar5 = (double)fVar7;
      }
    }
    iVar2 = cM3d_Cross_CylPntPnt(param_1,param_2 + 0x14,param_2 + 0x2c,&local_3c,auStack72);
    if (iVar2 != 0) {
      fVar7 = ::mtx::PSVECSquareDistance(&local_3c,(cXyz *)(param_2 + 0x14));
      if ((double)fVar7 < dVar5) {
        *param_3 = local_3c.x;
        param_3[1] = local_3c.y;
        param_3[2] = local_3c.z;
        dVar5 = (double)fVar7;
      }
    }
    if ((double)_5243 == dVar5) {
      local_80 = param_1[1];
      local_7c = (float)dVar6;
      cVar3 = cM3d_CrossY_Tri(param_2,param_1,&local_80,&local_84);
      if (cVar3 == '\0') {
        uVar1 = 0;
      }
      else {
        local_54.x = *param_1;
        local_54.z = param_1[2];
        local_54.y = local_84;
        ::mtx::PSVECAdd((cXyz *)(param_2 + 0x14),(cXyz *)(param_2 + 0x20),&cStack120);
        ::mtx::PSVECScale(&cStack120,&local_60,_4738);
        ::mtx::PSVECSubtract(&local_60,&local_54,&local_6c);
        dVar5 = (double)(local_6c.x * local_6c.x + local_6c.z * local_6c.z);
        if ((double)0_0 < dVar5) {
          dVar6 = 1.0 / SQRT(dVar5);
          dVar6 = _2240 * dVar6 * (_2241 - dVar5 * dVar6 * dVar6);
          dVar6 = _2240 * dVar6 * (_2241 - dVar5 * dVar6 * dVar6);
          dVar5 = (double)(float)(dVar5 * _2240 * dVar6 * (_2241 - dVar5 * dVar6 * dVar6));
        }
        if (G_CM3D_F_ABS_MIN <= (float)ABS(dVar5)) {
          cM3d_InDivPos1((double)(float)((double)param_1[3] / dVar5),&local_54,&local_6c,param_3);
        }
        else {
          *param_3 = local_60.x;
          param_3[1] = local_60.y;
          param_3[2] = local_60.z;
        }
        uVar1 = 1;
      }
    }
    else {
      uVar1 = 1;
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8024fa68) */
/* WARNING: Removing unreachable block (ram,0x8024fa70) */
/* __stdcall cM3d_Cross_CylLin(cM3dGCyl const *,
                               cM3dGLin const *,
                               Vec *,
                               Vec *) */

int cM3d_Cross_CylLin(cXyz *param_1,cXyz *param_2,cXyz *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  char cVar7;
  int iVar5;
  int iVar6;
  int iVar8;
  cXyz *pcVar9;
  uint uVar10;
  bool bVar11;
  int iVar12;
  undefined4 uVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar17;
  float fVar18;
  cXyz cStack212;
  cXyz cStack200;
  cXyz cStack188;
  cXyz cStack176;
  cXyz cStack164;
  cXyz cStack152;
  cXyz local_8c;
  cXyz cStack128;
  cXyz local_74;
  cXyz local_68;
  float local_5c;
  float local_58;
  float local_54;
  cXyz cStack80;
  cXyz cStack68;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar13 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar17 = (double)0_0;
  uVar10 = 0;
  cVar7 = cM3d_Cross_CylPnt();
  if ((cVar7 == '\0') || (cVar7 = cM3d_Cross_CylPnt(param_1,param_2 + 1), cVar7 == '\0')) {
    ::mtx::PSVECSubtract(param_2,param_1,&local_74);
    ::mtx::PSVECSubtract(param_2 + 1,param_1,&cStack128);
    ::mtx::PSVECSubtract(&cStack128,&local_74,&local_8c);
    fVar18 = param_1[1].x * param_1[1].x;
    if (G_CM3D_F_ABS_MIN <= ABS(local_8c.y)) {
      fVar1 = -local_74.y / local_8c.y;
      if ((0_0 <= fVar1) && (fVar1 <= _2261)) {
        fVar2 = local_74.x + local_8c.x * fVar1;
        fVar1 = local_74.z + local_8c.z * fVar1;
        if (fVar2 * fVar2 + fVar1 * fVar1 < fVar18) {
          uVar10 = 1;
          local_68.x = fVar2 + param_1->x;
          local_68.y = param_1->y;
          local_68.z = fVar1 + param_1->z;
        }
      }
      fVar1 = (param_1[1].y - local_74.y) / local_8c.y;
      if ((0_0 <= fVar1) && (fVar1 <= _2261)) {
        fVar2 = local_74.x + local_8c.x * fVar1;
        fVar1 = local_74.z + local_8c.z * fVar1;
        if (fVar2 * fVar2 + fVar1 * fVar1 < fVar18) {
          uVar10 = uVar10 | 2;
          local_5c = fVar2 + param_1->x;
          local_58 = param_1->y + param_1[1].y;
          local_54 = fVar1 + param_1->z;
        }
      }
    }
    fVar1 = local_8c.x * local_8c.x + local_8c.z * local_8c.z;
    dVar14 = (double)(_4410 * (local_8c.x * local_74.x + local_8c.z * local_74.z));
    dVar15 = (double)((local_74.x * local_74.x + local_74.z * local_74.z) - fVar18);
    fVar18 = _4410 * fVar1;
    if (ABS(fVar18) < G_CM3D_F_ABS_MIN) {
      if ((float)ABS(dVar14) < G_CM3D_F_ABS_MIN) {
        iVar5 = 0;
        goto LAB_8024fa68;
      }
      bVar11 = false;
      dVar15 = (double)(float)(-dVar15 / dVar14);
    }
    else {
      dVar16 = (double)((float)(dVar14 * dVar14) - (float)((double)(_4411 * fVar1) * dVar15));
      bVar11 = (double)0_0 < dVar16;
      if (dVar16 < (double)0_0) {
        iVar5 = 0;
        goto LAB_8024fa68;
      }
      if ((double)0_0 < dVar16) {
        dVar15 = 1.0 / SQRT(dVar16);
        dVar15 = _2240 * dVar15 * (_2241 - dVar16 * dVar15 * dVar15);
        dVar15 = _2240 * dVar15 * (_2241 - dVar16 * dVar15 * dVar15);
        dVar16 = (double)(float)(dVar16 * _2240 * dVar15 * (_2241 - dVar16 * dVar15 * dVar15));
      }
      dVar15 = (double)((float)(-dVar14 + dVar16) / fVar18);
      if (bVar11) {
        dVar17 = (double)((float)(-dVar14 - dVar16) / fVar18);
      }
    }
    bVar3 = true;
    if (bVar11) {
      bVar3 = false;
      if ((dVar15 < (double)0_0) || ((double)_2261 < dVar15)) {
        bVar3 = true;
      }
      bVar4 = false;
      if ((dVar17 < (double)0_0) || ((double)_2261 < dVar17)) {
        bVar4 = true;
      }
      if ((bVar3) && (bVar4)) {
        iVar5 = 0;
        goto LAB_8024fa68;
      }
      bVar3 = !bVar3;
      if (bVar4) {
        bVar11 = false;
      }
    }
    else {
      if ((dVar15 < (double)0_0) || ((double)_2261 < dVar15)) {
        iVar5 = 0;
        goto LAB_8024fa68;
      }
    }
    if ((bVar3) &&
       ((fVar18 = local_74.y + (float)(dVar15 * (double)local_8c.y), fVar18 < 0_0 ||
        (param_1[1].y < fVar18)))) {
      bVar3 = false;
    }
    if ((bVar11) &&
       ((local_74.y = local_74.y + (float)(dVar17 * (double)local_8c.y), local_74.y < 0_0 ||
        (param_1[1].y < local_74.y)))) {
      bVar11 = false;
    }
    if ((bVar3) || (bVar11)) {
      if ((bVar3) && (bVar11)) {
        ::mtx::PSVECAdd(&local_74,param_1,&cStack152);
        ::mtx::PSVECScale(&local_8c,&cStack164,(float)dVar15);
        ::mtx::PSVECAdd(&cStack164,&cStack152,&cStack80);
        uVar10 = uVar10 | 0xc;
        ::mtx::PSVECScale(&local_8c,&cStack164,(float)dVar17);
        ::mtx::PSVECAdd(&cStack164,&cStack152,&cStack68);
      }
      else {
        if (bVar3) {
          uVar10 = uVar10 | 4;
          ::mtx::PSVECScale(&local_8c,&cStack176,(float)dVar15);
          ::mtx::PSVECAdd(&cStack176,&local_74,&cStack188);
          ::mtx::PSVECAdd(&cStack188,param_1,&cStack80);
        }
        else {
          if (bVar11) {
            uVar10 = uVar10 | 4;
            ::mtx::PSVECScale(&local_8c,&cStack200,(float)dVar17);
            ::mtx::PSVECAdd(&cStack200,&local_74,&cStack212);
            ::mtx::PSVECAdd(&cStack212,param_1,&cStack80);
          }
        }
      }
      iVar5 = 0;
      iVar8 = 0;
      iVar6 = 0;
      iVar12 = 4;
      do {
        if ((uVar10 & 1 << iVar8) != 0) {
          if (iVar5 == 0) {
            param_3->x = *(float *)((int)&local_68.x + iVar6);
            param_3->y = *(float *)((int)&local_68.y + iVar6);
            param_3->z = *(float *)((int)&local_68.z + iVar6);
          }
          else {
            if (iVar5 == 1) {
              fVar18 = ::mtx::PSVECSquareDistance(param_3,param_2);
              dVar17 = (double)fVar18;
              pcVar9 = &local_68 + iVar8;
              fVar18 = ::mtx::PSVECSquareDistance(param_3,pcVar9);
              if ((double)fVar18 <= dVar17) {
                *param_4 = param_3->x;
                param_4[1] = param_3->y;
                param_4[2] = param_3->z;
                param_3->x = pcVar9->x;
                param_3->y = (&local_68)[iVar8].y;
                param_3->z = (&local_68)[iVar8].z;
              }
              else {
                *param_4 = pcVar9->x;
                param_4[1] = (&local_68)[iVar8].y;
                param_4[2] = (&local_68)[iVar8].z;
              }
              break;
            }
          }
          iVar5 = iVar5 + 1;
        }
        iVar8 = iVar8 + 1;
        iVar6 = iVar6 + 0xc;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
    }
    else {
      iVar5 = 0;
    }
  }
  else {
    param_3->x = param_2->x;
    param_3->y = param_2->y;
    param_3->z = param_2->z;
    *param_4 = param_2[1].x;
    param_4[1] = param_2[1].y;
    param_4[2] = param_2[1].z;
    iVar5 = 2;
  }
LAB_8024fa68:
  __psq_l0(auStack8,uVar13);
  __psq_l1(auStack8,uVar13);
  __psq_l0(auStack24,uVar13);
  __psq_l1(auStack24,uVar13);
  return iVar5;
}


/* __stdcall cM3d_Cross_CylPntPnt(cM3dGCyl const *,
                                  Vec const *,
                                  Vec const *,
                                  Vec *,
                                  Vec *) */

void cM3d_Cross_CylPntPnt
               (undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined **local_10;
  
  local_10 = &::cM3dGLin::__vt;
  local_28 = *param_2;
  local_24 = param_2[1];
  local_20 = param_2[2];
  local_1c = *param_3;
  local_18 = param_3[1];
  local_14 = param_3[2];
  cM3d_Cross_CylLin(param_1,&local_28,param_4,param_5);
  return;
}


/* __stdcall cM3d_Cross_CylPnt(cM3dGCyl const *,
                               Vec const *) */

undefined4 cM3d_Cross_CylPnt(float *param_1,float *param_2)

{
  if ((((*param_1 - *param_2) * (*param_1 - *param_2) +
        (param_1[2] - param_2[2]) * (param_1[2] - param_2[2]) < param_1[3] * param_1[3]) &&
      (param_1[1] < param_2[1])) && (param_2[1] < param_1[1] + param_1[4])) {
    return 1;
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8024fef0) */
/* __stdcall cM3d_Cross_CpsCps(cM3dGCps const &,
                               cM3dGCps const &,
                               Vec *) */

undefined4 cM3d_Cross_CpsCps(cXyz *param_1,cXyz *param_2,cXyz *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  double dVar5;
  float fVar6;
  float local_a8;
  float local_a4;
  cXyz cStack160;
  cXyz cStack148;
  cXyz cStack136;
  cXyz cStack124;
  cXyz cStack112;
  cXyz cStack100;
  cXyz local_58;
  cXyz local_4c;
  cXyz cStack64;
  cXyz acStack52 [2];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar1 = cM3d_Check_LinLin(param_1,param_2,&local_a4,&local_a8);
  if (iVar1 == 1) {
    uVar2 = 0;
  }
  else {
    if (iVar1 == 2) {
      dVar4 = (double)local_a4;
      if (((((double)0_0 < dVar4) && (dVar4 < (double)_2261)) && ((double)0_0 < (double)local_a8))
         && ((double)local_a8 < (double)_2261)) {
        ::mtx::PSVECSubtract(param_1 + 1,param_1,&cStack100);
        ::mtx::PSVECScale(&cStack100,&cStack100,(float)dVar4);
        ::mtx::PSVECAdd(&cStack100,param_1,acStack52);
        dVar4 = (double)local_a8;
        ::mtx::PSVECSubtract(param_2 + 1,param_2,&cStack112);
        ::mtx::PSVECScale(&cStack112,&cStack112,(float)dVar4);
        ::mtx::PSVECAdd(&cStack112,param_2,&cStack64);
        fVar6 = ::mtx::PSVECDistance(acStack52,&cStack64);
        if (fVar6 < param_1[2].y + param_2[2].y) {
          ::mtx::PSVECAdd(acStack52,&cStack64,param_3);
          ::mtx::PSVECScale(param_3,param_3,_4738);
          uVar2 = 1;
          goto LAB_8024fef0;
        }
      }
    }
    else {
      if (iVar1 == 3) {
        dVar5 = (double)local_a4;
        dVar4 = (double)0_0;
        if (dVar4 <= dVar5) {
          if (dVar5 <= (double)_2261) {
            ::mtx::PSVECSubtract(param_1 + 1,param_1,&cStack148);
            ::mtx::PSVECScale(&cStack148,&cStack148,(float)dVar5);
            ::mtx::PSVECAdd(&cStack148,param_1,&local_4c);
            dVar4 = (double)local_a8;
            if ((double)0_0 <= dVar4) {
              if (dVar4 <= (double)_2261) {
                ::mtx::PSVECSubtract(param_2 + 1,param_2,&cStack160);
                ::mtx::PSVECScale(&cStack160,&cStack160,(float)dVar4);
                ::mtx::PSVECAdd(&cStack160,param_2,&local_58);
              }
              else {
                local_58.x = param_2[1].x;
                local_58.y = param_2[1].y;
                local_58.z = param_2[1].z;
              }
            }
            else {
              local_58.x = param_2->x;
              local_58.y = param_2->y;
              local_58.z = param_2->z;
            }
          }
          else {
            local_4c.x = param_1[1].x;
            local_4c.y = param_1[1].y;
            local_4c.z = param_1[1].z;
            dVar5 = (double)local_a8;
            if (dVar4 <= dVar5) {
              if (dVar5 <= (double)_2261) {
                ::mtx::PSVECSubtract(param_2 + 1,param_2,&cStack136);
                ::mtx::PSVECScale(&cStack136,&cStack136,(float)dVar5);
                ::mtx::PSVECAdd(&cStack136,param_2,&local_58);
              }
              else {
                local_58.x = param_2[1].x;
                local_58.y = param_2[1].y;
                local_58.z = param_2[1].z;
              }
            }
            else {
              local_58.x = param_2->x;
              local_58.y = param_2->y;
              local_58.z = param_2->z;
            }
          }
        }
        else {
          local_4c.x = param_1->x;
          local_4c.y = param_1->y;
          local_4c.z = param_1->z;
          dVar5 = (double)local_a8;
          if (dVar4 <= dVar5) {
            if (dVar5 <= (double)_2261) {
              ::mtx::PSVECSubtract(param_2 + 1,param_2,&cStack124);
              ::mtx::PSVECScale(&cStack124,&cStack124,(float)dVar5);
              ::mtx::PSVECAdd(&cStack124,param_2,&local_58);
            }
            else {
              local_58.x = param_2[1].x;
              local_58.y = param_2[1].y;
              local_58.z = param_2[1].z;
            }
          }
          else {
            local_58.x = param_2->x;
            local_58.y = param_2->y;
            local_58.z = param_2->z;
          }
        }
        fVar6 = ::mtx::PSVECDistance(&local_4c,&local_58);
        if (param_1[2].y + param_2[2].y <= fVar6) {
          uVar2 = 0;
        }
        else {
          ::mtx::PSVECAdd(&local_4c,&local_58,param_3);
          ::mtx::PSVECScale(param_3,param_3,_4738);
          uVar2 = 1;
        }
        goto LAB_8024fef0;
      }
    }
    uVar2 = 0;
  }
LAB_8024fef0:
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x802506b4) */
/* __stdcall cM3d_Cross_CpsCyl(cM3dGCps const &,
                               cM3dGCyl const &,
                               Vec *) */

uint cM3d_Cross_CpsCyl(cXyz *param_1,float *param_2,cXyz *param_3)

{
  char cVar3;
  uint uVar1;
  int iVar2;
  bool bVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  double dVar7;
  float fVar8;
  undefined auStack232 [4];
  float local_e4;
  float local_e0;
  undefined auStack220 [4];
  cXyz cStack216;
  cXyz cStack204;
  cXyz cStack192;
  cXyz cStack180;
  cXyz cStack168;
  cXyz cStack156;
  cXyz local_90;
  cXyz local_84;
  cXyz cStack120;
  cXyz cStack108;
  cXyz cStack96;
  cM3dGSph cStack84;
  cXyz local_40;
  cXyz local_34;
  undefined **local_28;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_28 = &::cM3dGLin::__vt;
  cVar3 = cM3d_Cross_CylPnt(param_2,param_1 + 1);
  if (cVar3 == '\0') {
    cVar3 = cM3d_Cross_CylPnt(param_2,param_1);
    if (cVar3 == '\0') {
      local_40.x = *param_2;
      local_40.y = param_2[1];
      local_40.z = param_2[2];
      local_34.y = local_40.y + param_2[4];
      local_34.x = local_40.x;
      local_34.z = local_40.z;
      cVar3 = cM3d_Len3dSqPntAndSegLine(param_1,&local_34,&cStack96,auStack220);
      if ((cVar3 == '\0') ||
         (fVar8 = ::mtx::PSVECDistance(&local_34,&cStack96), param_1[2].y <= fVar8)) {
        cVar3 = cM3d_Len3dSqPntAndSegLine(param_1,&local_40,&cStack96,auStack220);
        if ((cVar3 == '\0') ||
           (fVar8 = ::mtx::PSVECDistance(&local_40,&cStack96), param_1[2].y <= fVar8)) {
          iVar2 = cM3d_Check_LinLin(param_1,&local_40,&local_e0,&local_e4);
          if (iVar2 == 1) {
            cStack84.vtbl = (undefined *)&::cM3dGSph::__vt;
            ::cM3dGSph::SetR(&cStack84,param_1[2].y);
            ::cM3dGSph::SetC(&cStack84,param_1);
            uVar1 = cM3d_Cross_CylSph(param_2,&cStack84,param_3,auStack232);
          }
          else {
            if (iVar2 == 2) {
              dVar6 = (double)local_e0;
              if (((((double)0_0 <= dVar6) && (dVar6 <= (double)_2261)) &&
                  ((double)0_0 <= (double)local_e4)) && ((double)local_e4 <= (double)_2261)) {
                ::mtx::PSVECSubtract(param_1 + 1,param_1,&cStack156);
                ::mtx::PSVECScale(&cStack156,&cStack156,(float)dVar6);
                ::mtx::PSVECAdd(&cStack156,param_1,&cStack108);
                dVar6 = (double)local_e4;
                ::mtx::PSVECSubtract(&local_34,&local_40,&cStack168);
                ::mtx::PSVECScale(&cStack168,&cStack168,(float)dVar6);
                ::mtx::PSVECAdd(&cStack168,&local_40,&cStack120);
                fVar8 = ::mtx::PSVECDistance(&cStack108,&cStack120);
                if (fVar8 < param_1[2].y + param_2[3]) {
                  ::mtx::PSVECAdd(&cStack108,&cStack120,param_3);
                  ::mtx::PSVECScale(param_3,param_3,_4738);
                  uVar1 = 1;
                  goto LAB_802506b4;
                }
              }
            }
            else {
              if (iVar2 == 3) {
                dVar7 = (double)local_e0;
                dVar6 = (double)0_0;
                if (dVar6 <= dVar7) {
                  if (dVar7 <= (double)_2261) {
                    ::mtx::PSVECSubtract(param_1 + 1,param_1,&cStack204);
                    ::mtx::PSVECScale(&cStack204,&cStack204,(float)dVar7);
                    ::mtx::PSVECAdd(&cStack204,param_1,&local_84);
                    dVar6 = (double)local_e4;
                    if (dVar6 < (double)0_0) {
                      local_90.x = local_40.x;
                      local_90.y = local_40.y;
                      local_90.z = local_40.z;
                      fVar8 = ::mtx::PSVECDistance(&local_84,&local_90);
                      bVar4 = fVar8 < param_1[2].y;
                      if (bVar4) {
                        ::mtx::PSVECAdd(&local_84,&local_90,param_3);
                        ::mtx::PSVECScale(param_3,param_3,_4738);
                      }
                      uVar1 = (uint)bVar4;
                      goto LAB_802506b4;
                    }
                    if ((double)_2261 < dVar6) {
                      local_90.x = local_34.x;
                      local_90.y = local_34.y;
                      local_90.z = local_34.z;
                      fVar8 = ::mtx::PSVECDistance(&local_84,&local_90);
                      bVar4 = fVar8 < param_1[2].y;
                      if (bVar4) {
                        ::mtx::PSVECAdd(&local_84,&local_90,param_3);
                        ::mtx::PSVECScale(param_3,param_3,_4738);
                      }
                      uVar1 = (uint)bVar4;
                      goto LAB_802506b4;
                    }
                    ::mtx::PSVECSubtract(&local_34,&local_40,&cStack216);
                    ::mtx::PSVECScale(&cStack216,&cStack216,(float)dVar6);
                    ::mtx::PSVECAdd(&cStack216,&local_40,&local_90);
                  }
                  else {
                    local_84.x = param_1[1].x;
                    local_84.y = param_1[1].y;
                    local_84.z = param_1[1].z;
                    dVar7 = (double)local_e4;
                    if (dVar7 < dVar6) {
                      local_90.x = local_40.x;
                      local_90.y = local_40.y;
                      local_90.z = local_40.z;
                      fVar8 = ::mtx::PSVECDistance(&local_84,&local_90);
                      bVar4 = fVar8 < param_1[2].y;
                      if (bVar4) {
                        ::mtx::PSVECAdd(&local_84,&local_90,param_3);
                        ::mtx::PSVECScale(param_3,param_3,_4738);
                      }
                      uVar1 = (uint)bVar4;
                      goto LAB_802506b4;
                    }
                    if ((double)_2261 < dVar7) {
                      local_90.x = local_34.x;
                      local_90.y = local_34.y;
                      local_90.z = local_34.z;
                      fVar8 = ::mtx::PSVECDistance(&local_84,&local_90);
                      bVar4 = fVar8 < param_1[2].y;
                      if (bVar4) {
                        ::mtx::PSVECAdd(&local_84,&local_90,param_3);
                        ::mtx::PSVECScale(param_3,param_3,_4738);
                      }
                      uVar1 = (uint)bVar4;
                      goto LAB_802506b4;
                    }
                    ::mtx::PSVECSubtract(&local_34,&local_40,&cStack192);
                    ::mtx::PSVECScale(&cStack192,&cStack192,(float)dVar7);
                    ::mtx::PSVECAdd(&cStack192,&local_40,&local_90);
                  }
                }
                else {
                  local_84.x = param_1->x;
                  local_84.y = param_1->y;
                  local_84.z = param_1->z;
                  dVar7 = (double)local_e4;
                  if (dVar7 < dVar6) {
                    local_90.x = local_40.x;
                    local_90.y = local_40.y;
                    local_90.z = local_40.z;
                    fVar8 = ::mtx::PSVECDistance(&local_84,&local_90);
                    bVar4 = fVar8 < param_1[2].y;
                    if (bVar4) {
                      ::mtx::PSVECAdd(&local_84,&local_90,param_3);
                      ::mtx::PSVECScale(param_3,param_3,_4738);
                    }
                    uVar1 = (uint)bVar4;
                    goto LAB_802506b4;
                  }
                  if ((double)_2261 < dVar7) {
                    local_90.x = local_34.x;
                    local_90.y = local_34.y;
                    local_90.z = local_34.z;
                    fVar8 = ::mtx::PSVECDistance(&local_84,&local_90);
                    bVar4 = fVar8 < param_1[2].y;
                    if (bVar4) {
                      ::mtx::PSVECAdd(&local_84,&local_90,param_3);
                      ::mtx::PSVECScale(param_3,param_3,_4738);
                    }
                    uVar1 = (uint)bVar4;
                    goto LAB_802506b4;
                  }
                  ::mtx::PSVECSubtract(&local_34,&local_40,&cStack180);
                  ::mtx::PSVECScale(&cStack180,&cStack180,(float)dVar7);
                  ::mtx::PSVECAdd(&cStack180,&local_40,&local_90);
                }
                fVar8 = ::mtx::PSVECDistance(&local_84,&local_90);
                if (param_1[2].y + param_2[3] <= fVar8) {
                  uVar1 = 0;
                }
                else {
                  ::mtx::PSVECAdd(&local_84,&local_90,param_3);
                  ::mtx::PSVECScale(param_3,param_3,_4738);
                  uVar1 = 1;
                }
                goto LAB_802506b4;
              }
            }
            uVar1 = 0;
          }
        }
        else {
          ::mtx::PSVECAdd(&local_40,&cStack96,param_3);
          ::mtx::PSVECScale(param_3,param_3,_4738);
          uVar1 = 1;
        }
      }
      else {
        ::mtx::PSVECAdd(&local_34,&cStack96,param_3);
        ::mtx::PSVECScale(param_3,param_3,_4738);
        param_3->x = local_34.x;
        param_3->y = local_34.y;
        param_3->z = local_34.z;
        uVar1 = 1;
      }
    }
    else {
      param_3->x = param_1->x;
      param_3->y = param_1->y;
      param_3->z = param_1->z;
      uVar1 = 1;
    }
  }
  else {
    param_3->x = param_1[1].x;
    param_3->y = param_1[1].y;
    param_3->z = param_1[1].z;
    uVar1 = 1;
  }
LAB_802506b4:
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80250820) */
/* __stdcall cM3d_Cross_CpsSph_CrossPos(cM3dGCps const &,
                                        cM3dGSph const &,
                                        Vec const &,
                                        Vec *) */

void cM3d_Cross_CpsSph_CrossPos(cXyz *param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 in_f31;
  double dVar3;
  float fVar4;
  cXyz cStack72;
  cXyz local_3c;
  cXyz local_30;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar1 = cM3d_Cross_LinSph_CrossPos(param_2,param_1,&local_30,&local_3c);
  if (iVar1 == 1) {
    param_4->x = local_30.x;
    param_4->y = local_30.y;
    param_4->z = local_30.z;
  }
  else {
    if (iVar1 == 2) {
      fVar4 = ::mtx::PSVECSquareDistance(&local_30,param_1);
      dVar3 = (double)fVar4;
      fVar4 = ::mtx::PSVECSquareDistance(&local_3c,param_1);
      if ((double)fVar4 <= dVar3) {
        param_4->x = local_3c.x;
        param_4->y = local_3c.y;
        param_4->z = local_3c.z;
      }
      else {
        param_4->x = local_30.x;
        param_4->y = local_30.y;
        param_4->z = local_30.z;
      }
    }
    else {
      dVar3 = (double)(param_1[2].y + param_2[1].x);
      param_4->x = param_3->x;
      param_4->y = param_3->y;
      param_4->z = param_3->z;
      if ((float)ABS(dVar3) < G_CM3D_F_ABS_MIN) {
        param_4->x = param_3->x;
        param_4->y = param_3->y;
        param_4->z = param_3->z;
      }
      ::mtx::PSVECSubtract(param_3,param_2,&cStack72);
      ::mtx::PSVECScale(&cStack72,&cStack72,(float)((double)param_1[2].y / dVar3));
      ::mtx::PSVECAdd(param_4,&cStack72,param_4);
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall cM3d_Cross_CpsSph(cM3dGCps const &,
                               cM3dGSph const &,
                               Vec *) */

undefined4 cM3d_Cross_CpsSph(cM3dGCps *param_1,cM3dGSph *param_2,cXyz *param_3)

{
  undefined4 uVar1;
  char cVar2;
  double dVar3;
  double dVar4;
  float local_24;
  undefined auStack32 [20];
  
  local_24 = ::mtx::PSVECDistance((cXyz *)param_1,&param_2->mCenter);
  if (param_1->mRadius + param_2->mRadius <= local_24) {
    local_24 = ::mtx::PSVECDistance(&(param_1->parent).mP1,&param_2->mCenter);
    if (param_1->mRadius + param_2->mRadius <= local_24) {
      cVar2 = cM3d_Len3dSqPntAndSegLine(param_1,param_2,auStack32,&local_24);
      if (cVar2 != '\0') {
        dVar4 = (double)local_24;
        if ((double)0_0 < dVar4) {
          dVar3 = 1.0 / SQRT(dVar4);
          dVar3 = _2240 * dVar3 * (_2241 - dVar4 * dVar3 * dVar3);
          dVar3 = _2240 * dVar3 * (_2241 - dVar4 * dVar3 * dVar3);
          dVar4 = (double)(float)(dVar4 * _2240 * dVar3 * (_2241 - dVar4 * dVar3 * dVar3));
        }
        if (dVar4 < (double)(param_1->mRadius + param_2->mRadius)) {
          cM3d_Cross_CpsSph_CrossPos(param_1,param_2,auStack32,param_3);
          return 1;
        }
      }
      uVar1 = 0;
    }
    else {
      cM3d_Cross_CpsSph_CrossPos(param_1,param_2,&(param_1->parent).mP1,param_3);
      uVar1 = 1;
    }
  }
  else {
    cM3d_Cross_CpsSph_CrossPos(param_1,param_2,param_1,param_3);
    uVar1 = 1;
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80250d48) */
/* WARNING: Removing unreachable block (ram,0x80250d50) */
/* __stdcall cM3d_Cross_TriTri(cM3dGTri const &,
                               cM3dGTri const &,
                               Vec *) */

undefined4 cM3d_Cross_TriTri(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined **local_40;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar4 = (double)::mtx::PSVECDotProduct(param_1,param_2 + 0x14);
  dVar7 = (double)(float)((double)*(float *)(param_1 + 0xc) + dVar4);
  dVar4 = (double)::mtx::PSVECDotProduct(param_1,param_2 + 0x20);
  dVar6 = (double)(float)((double)*(float *)(param_1 + 0xc) + dVar4);
  dVar4 = (double)::mtx::PSVECDotProduct(param_1,param_2 + 0x2c);
  dVar5 = (double)(float)((double)*(float *)(param_1 + 0xc) + dVar4);
  dVar4 = (double)0_0;
  if ((((dVar4 < dVar7) && (dVar4 < dVar6)) && (dVar4 < dVar5)) ||
     (((dVar4 = (double)0_0, dVar7 < dVar4 && (dVar6 < dVar4)) && (dVar5 < dVar4)))) {
    uVar1 = 0;
  }
  else {
    dVar4 = (double)::mtx::PSVECDotProduct(param_2,param_1 + 0x14);
    dVar6 = (double)(float)((double)*(float *)(param_2 + 0xc) + dVar4);
    dVar4 = (double)::mtx::PSVECDotProduct(param_2,param_1 + 0x20);
    dVar7 = (double)(float)((double)*(float *)(param_2 + 0xc) + dVar4);
    dVar4 = (double)::mtx::PSVECDotProduct(param_2,param_1 + 0x2c);
    dVar5 = (double)(float)((double)*(float *)(param_2 + 0xc) + dVar4);
    dVar4 = (double)0_0;
    if ((((dVar4 < dVar6) && (dVar4 < dVar7)) && (dVar4 < dVar5)) ||
       (((dVar4 = (double)0_0, dVar6 < dVar4 && (dVar7 < dVar4)) && (dVar5 < dVar4)))) {
      uVar1 = 0;
    }
    else {
      local_40 = &::cM3dGLin::__vt;
      local_58 = *(undefined4 *)(param_2 + 0x14);
      local_54 = *(undefined4 *)(param_2 + 0x18);
      local_50 = *(undefined4 *)(param_2 + 0x1c);
      local_4c = *(undefined4 *)(param_2 + 0x20);
      local_48 = *(undefined4 *)(param_2 + 0x24);
      local_44 = *(undefined4 *)(param_2 + 0x28);
      cVar2 = cM3d_Cross_LinTri(&local_58,param_1,param_3,0,0);
      if (cVar2 == '\0') {
        local_58 = *(undefined4 *)(param_2 + 0x20);
        local_54 = *(undefined4 *)(param_2 + 0x24);
        local_50 = *(undefined4 *)(param_2 + 0x28);
        local_4c = *(undefined4 *)(param_2 + 0x2c);
        local_48 = *(undefined4 *)(param_2 + 0x30);
        local_44 = *(undefined4 *)(param_2 + 0x34);
        cVar2 = cM3d_Cross_LinTri(&local_58,param_1,param_3,0,0);
        if (cVar2 == '\0') {
          local_58 = *(undefined4 *)(param_2 + 0x14);
          local_54 = *(undefined4 *)(param_2 + 0x18);
          local_50 = *(undefined4 *)(param_2 + 0x1c);
          local_4c = *(undefined4 *)(param_2 + 0x20);
          local_48 = *(undefined4 *)(param_2 + 0x24);
          local_44 = *(undefined4 *)(param_2 + 0x28);
          cVar2 = cM3d_Cross_LinTri(&local_58,param_1,param_3,0,0);
          if (cVar2 == '\0') {
            local_58 = *(undefined4 *)(param_1 + 0x14);
            local_54 = *(undefined4 *)(param_1 + 0x18);
            local_50 = *(undefined4 *)(param_1 + 0x1c);
            local_4c = *(undefined4 *)(param_1 + 0x20);
            local_48 = *(undefined4 *)(param_1 + 0x24);
            local_44 = *(undefined4 *)(param_1 + 0x28);
            cVar2 = cM3d_Cross_LinTri(&local_58,param_2,param_3,0,0);
            if (cVar2 == '\0') {
              local_58 = *(undefined4 *)(param_1 + 0x20);
              local_54 = *(undefined4 *)(param_1 + 0x24);
              local_50 = *(undefined4 *)(param_1 + 0x28);
              local_4c = *(undefined4 *)(param_1 + 0x2c);
              local_48 = *(undefined4 *)(param_1 + 0x30);
              local_44 = *(undefined4 *)(param_1 + 0x34);
              cVar2 = cM3d_Cross_LinTri(&local_58,param_2,param_3,0,0);
              if (cVar2 == '\0') {
                local_58 = *(undefined4 *)(param_1 + 0x14);
                local_54 = *(undefined4 *)(param_1 + 0x18);
                local_50 = *(undefined4 *)(param_1 + 0x1c);
                local_4c = *(undefined4 *)(param_1 + 0x20);
                local_48 = *(undefined4 *)(param_1 + 0x24);
                local_44 = *(undefined4 *)(param_1 + 0x28);
                cVar2 = cM3d_Cross_LinTri(&local_58,param_2,param_3,0,0);
                if (cVar2 == '\0') {
                  uVar1 = 0;
                }
                else {
                  uVar1 = 1;
                }
              }
              else {
                uVar1 = 1;
              }
            }
            else {
              uVar1 = 1;
            }
          }
          else {
            uVar1 = 1;
          }
        }
        else {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = 1;
      }
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80251258) */
/* WARNING: Removing unreachable block (ram,0x80251260) */
/* __stdcall cM3d_Cross_CpsTri(cM3dGCps const &,
                               cM3dGTri,
                               Vec *) */

undefined4 cM3d_Cross_CpsTri(cXyz *param_1,int param_2,cXyz *param_3)

{
  char cVar3;
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar4;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  float fVar7;
  float local_f8;
  float local_f4;
  cXyz cStack240;
  cXyz cStack228;
  cXyz cStack216;
  cXyz cStack204;
  cXyz cStack192;
  cXyz cStack180;
  cXyz cStack168;
  cXyz cStack156;
  cXyz cStack144;
  cXyz cStack132;
  cXyz cStack120;
  cXyz cStack108;
  cXyz local_60;
  cXyz local_54;
  undefined **local_48;
  cM3dGSph cStack68;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  cStack68.vtbl = (undefined *)&::cM3dGSph::__vt;
  ::cM3dGSph::SetC(&cStack68,param_1);
  ::cM3dGSph::SetR(&cStack68,param_1[2].y);
  cVar3 = cM3d_Cross_SphTri(&cStack68,param_2,param_3);
  if (cVar3 == '\0') {
    ::cM3dGSph::SetC(&cStack68,param_1 + 1);
    ::cM3dGSph::SetR(&cStack68,param_1[2].y);
    cVar3 = cM3d_Cross_SphTri(&cStack68,param_2,param_3);
    if (cVar3 == '\0') {
      cVar3 = cM3d_Cross_LinPla(param_1,param_2,param_3,1,1);
      if (cVar3 == '\0') {
        uVar1 = 0;
      }
      else {
        cVar3 = cM3d_Cross_LinTri_Easy(param_2,param_3);
        if (cVar3 == '\0') {
          local_48 = &::cM3dGLin::__vt;
          local_60.x = *(float *)(param_2 + 0x14);
          local_60.y = *(float *)(param_2 + 0x18);
          local_60.z = *(float *)(param_2 + 0x1c);
          local_54.x = *(float *)(param_2 + 0x20);
          local_54.y = *(float *)(param_2 + 0x24);
          local_54.z = *(float *)(param_2 + 0x28);
          iVar2 = cM3d_Check_LinLin(param_1,&local_60,&local_f4,&local_f8);
          if (1 < iVar2) {
            dVar6 = (double)local_f4;
            if (((((double)0_0 < dVar6) && (dVar6 < (double)_2261)) &&
                (dVar5 = (double)local_f8, (double)0_0 < dVar5)) && (dVar5 < (double)_2261)) {
              ::mtx::PSVECSubtract(param_1 + 1,param_1,&cStack180);
              ::mtx::PSVECScale(&cStack180,&cStack180,(float)dVar6);
              ::mtx::PSVECAdd(&cStack180,param_1,&cStack120);
              ::mtx::PSVECSubtract(&local_54,&local_60,&cStack192);
              ::mtx::PSVECScale(&cStack192,&cStack192,(float)dVar5);
              ::mtx::PSVECAdd(&cStack192,&local_60,&cStack108);
              ::mtx::PSVECAdd(&cStack120,&cStack108,param_3);
              ::mtx::PSVECScale(param_3,param_3,_4738);
              fVar7 = ::mtx::PSVECDistance(&cStack120,&cStack108);
              if (fVar7 < param_1[2].y) {
                uVar1 = 1;
                goto LAB_80251258;
              }
            }
          }
          local_60.x = *(float *)(param_2 + 0x20);
          local_60.y = *(float *)(param_2 + 0x24);
          local_60.z = *(float *)(param_2 + 0x28);
          local_54.x = *(float *)(param_2 + 0x2c);
          local_54.y = *(float *)(param_2 + 0x30);
          local_54.z = *(float *)(param_2 + 0x34);
          iVar2 = cM3d_Check_LinLin(param_1,&local_60,&local_f4,&local_f8);
          if (1 < iVar2) {
            dVar6 = (double)local_f4;
            if ((((double)0_0 < dVar6) && (dVar6 < (double)_2261)) &&
               ((dVar5 = (double)local_f8, (double)0_0 < dVar5 && (dVar5 < (double)_2261)))) {
              ::mtx::PSVECSubtract(param_1 + 1,param_1,&cStack204);
              ::mtx::PSVECScale(&cStack204,&cStack204,(float)dVar6);
              ::mtx::PSVECAdd(&cStack204,param_1,&cStack144);
              ::mtx::PSVECSubtract(&local_54,&local_60,&cStack216);
              ::mtx::PSVECScale(&cStack216,&cStack216,(float)dVar5);
              ::mtx::PSVECAdd(&cStack216,&local_60,&cStack132);
              ::mtx::PSVECAdd(&cStack144,&cStack132,param_3);
              ::mtx::PSVECScale(param_3,param_3,_4738);
              fVar7 = ::mtx::PSVECDistance(&cStack144,&cStack132);
              if (fVar7 < param_1[2].y) {
                uVar1 = 1;
                goto LAB_80251258;
              }
            }
          }
          local_60.x = *(float *)(param_2 + 0x2c);
          local_60.y = *(float *)(param_2 + 0x30);
          local_60.z = *(float *)(param_2 + 0x34);
          local_54.x = *(float *)(param_2 + 0x14);
          local_54.y = *(float *)(param_2 + 0x18);
          local_54.z = *(float *)(param_2 + 0x1c);
          iVar2 = cM3d_Check_LinLin(param_1,&local_60,&local_f4,&local_f8);
          if (1 < iVar2) {
            dVar6 = (double)local_f4;
            if ((((double)0_0 < dVar6) && (dVar6 < (double)_2261)) &&
               ((dVar5 = (double)local_f8, (double)0_0 < dVar5 && (dVar5 < (double)_2261)))) {
              ::mtx::PSVECSubtract(param_1 + 1,param_1,&cStack228);
              ::mtx::PSVECScale(&cStack228,&cStack228,(float)dVar6);
              ::mtx::PSVECAdd(&cStack228,param_1,&cStack168);
              ::mtx::PSVECSubtract(&local_54,&local_60,&cStack240);
              ::mtx::PSVECScale(&cStack240,&cStack240,(float)dVar5);
              ::mtx::PSVECAdd(&cStack240,&local_60,&cStack156);
              ::mtx::PSVECAdd(&cStack168,&cStack156,param_3);
              ::mtx::PSVECScale(param_3,param_3,_4738);
              fVar7 = ::mtx::PSVECDistance(&cStack168,&cStack156);
              if (fVar7 < param_1[2].y) {
                uVar1 = 1;
                goto LAB_80251258;
              }
            }
          }
          uVar1 = 0;
        }
        else {
          uVar1 = 1;
        }
      }
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 1;
  }
LAB_80251258:
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802514cc) */
/* __stdcall cM3d_NearPos_Cps(cM3dGCps const &,
                              Vec const &,
                              Vec *) */

undefined4 cM3d_NearPos_Cps(cXyz *param_1,cXyz *param_2,cXyz *param_3)

{
  char cVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f31;
  float fVar5;
  float local_5c;
  cXyz cStack88;
  cXyz cStack76;
  cXyz cStack64;
  cXyz acStack52 [2];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  cVar1 = cM3d_Len3dSqPntAndSegLine(param_1,param_2,acStack52,&local_5c);
  if (cVar1 == '\0') {
    fVar5 = ::mtx::PSVECSquareDistance(param_1,param_2);
    dVar4 = (double)fVar5;
    fVar5 = ::mtx::PSVECSquareDistance(param_1 + 1,param_2);
    dVar3 = (double)fVar5;
    if (dVar3 <= dVar4) {
      if ((double)0_0 < dVar3) {
        dVar4 = 1.0 / SQRT(dVar3);
        dVar4 = _2240 * dVar4 * (_2241 - dVar3 * dVar4 * dVar4);
        dVar4 = _2240 * dVar4 * (_2241 - dVar3 * dVar4 * dVar4);
        dVar3 = (double)(float)(dVar3 * _2240 * dVar4 * (_2241 - dVar3 * dVar4 * dVar4));
      }
      ::mtx::PSVECSubtract(param_1 + 1,param_2,&cStack88);
      ::mtx::PSVECScale(&cStack88,&cStack88,(float)((double)param_1[2].y / dVar3));
      ::mtx::PSVECAdd(param_1 + 1,&cStack88,param_3);
    }
    else {
      if ((double)0_0 < dVar4) {
        dVar3 = 1.0 / SQRT(dVar4);
        dVar3 = _2240 * dVar3 * (_2241 - dVar4 * dVar3 * dVar3);
        dVar3 = _2240 * dVar3 * (_2241 - dVar4 * dVar3 * dVar3);
        dVar4 = (double)(float)(dVar4 * _2240 * dVar3 * (_2241 - dVar4 * dVar3 * dVar3));
      }
      ::mtx::PSVECSubtract(param_1,param_2,&cStack76);
      ::mtx::PSVECScale(&cStack76,&cStack76,(float)((double)param_1[2].y / dVar4));
      ::mtx::PSVECAdd(param_1,&cStack76,param_3);
    }
  }
  else {
    dVar4 = (double)local_5c;
    if ((double)0_0 < dVar4) {
      dVar3 = 1.0 / SQRT(dVar4);
      dVar3 = _2240 * dVar3 * (_2241 - dVar4 * dVar3 * dVar3);
      dVar3 = _2240 * dVar3 * (_2241 - dVar4 * dVar3 * dVar3);
      dVar4 = (double)(float)(dVar4 * _2240 * dVar3 * (_2241 - dVar4 * dVar3 * dVar3));
    }
    local_5c = (float)dVar4;
    ::mtx::PSVECSubtract(param_2,acStack52,&cStack64);
    ::mtx::PSVECScale(&cStack64,&cStack64,param_1[2].y / local_5c);
    ::mtx::PSVECAdd(acStack52,&cStack64,param_3);
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall cM3d_CalcVecAngle(Vec const &,
                               short *,
                               short *) */

void cM3d_CalcVecAngle(cXyz *param_1,short *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = cM_atan2s(-param_1->z * param_1->y,_2261);
  *param_2 = -(short)iVar1;
  iVar1 = cM_atan2s(-param_1->x * param_1->y,_2261);
  *param_3 = (short)iVar1;
  return;
}


/* __stdcall cM3d_CalcVecZAngle(Vec const &,
                                csXyz *) */

void cM3d_CalcVecZAngle(float *param_1,short *param_2)

{
  int iVar1;
  double dVar2;
  double dVar3;
  
  dVar3 = (double)(*param_1 * *param_1 + param_1[2] * param_1[2]);
  if ((double)0_0 < dVar3) {
    dVar2 = 1.0 / SQRT(dVar3);
    dVar2 = _2240 * dVar2 * (_2241 - dVar3 * dVar2 * dVar2);
    dVar2 = _2240 * dVar2 * (_2241 - dVar3 * dVar2 * dVar2);
    dVar3 = (double)(float)(dVar3 * _2240 * dVar2 * (_2241 - dVar3 * dVar2 * dVar2));
  }
  iVar1 = cM_atan2s(param_1[1],(float)dVar3);
  *param_2 = -(short)iVar1;
  iVar1 = cM_atan2s(*param_1,param_1[2]);
  param_2[1] = (short)iVar1;
  param_2[2] = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall cM3d_UpMtx_Base(Vec const &,
                             Vec const &,
                             float *[][][][]) */

undefined4 cM3d_UpMtx_Base(TVec3_float_ *param_1,cXyz *param_2,MTX34 *param_3)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  float fVar4;
  TVec3_float_ TStack40;
  TVec3_float_ local_1c;
  
  fVar4 = ::mtx::PSVECMag(param_2);
  if (G_CM3D_F_ABS_MIN <= ABS(fVar4)) {
    ::mtx::PSVECNormalize(param_2,&TStack40);
    ::mtx::PSVECCrossProduct(param_1,&TStack40,&local_1c);
    fVar4 = ::mtx::PSVECMag((cXyz *)&local_1c);
    if (ABS(fVar4) < G_CM3D_F_ABS_MIN) {
      local_1c.x = _2261;
      local_1c.y = 0_0;
      local_1c.z = 0_0;
    }
    dVar3 = (double)::mtx::PSVECDotProduct(param_1,&TStack40);
    dVar2 = (double)_2261;
    if ((dVar3 <= dVar2) && (dVar2 = dVar3, dVar3 < (double)_3088)) {
      dVar2 = (double)_3088;
    }
    dVar2 = MSL_C.PPCEABI.bare.H::acos(dVar2);
    ::mtx::C_MTXRotAxisRad((double)(float)dVar2,param_3,&local_1c);
    uVar1 = 1;
  }
  else {
    ::mtx::PSMTXIdentity(param_3);
    uVar1 = 0;
  }
  return uVar1;
}


/* __stdcall cM3d_PlaneCrossLineProcWork(float,
                                         float,
                                         float,
                                         float,
                                         float,
                                         float,
                                         float,
                                         float *,
                                         float *) */

void cM3d_PlaneCrossLineProcWork
               (double param_1,double param_2,double param_3,double param_4,double param_5,
               double param_6,double param_7,float *param_8,float *param_9)

{
  *param_8 = (float)((double)((float)(param_2 * param_7) - (float)(param_4 * param_6)) / param_5);
  *param_9 = (float)((double)((float)(param_3 * param_6) - (float)(param_1 * param_7)) / param_5);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall cM3d_2PlaneCrossLine(cM3dGPla const &,
                                  cM3dGPla const &,
                                  cM3dGLin *) */

undefined4 cM3d_2PlaneCrossLine(cM3dGPla *param_1,cM3dGPla *param_2,cM3dGLin *param_3)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  TVec3_float_ local_28 [2];
  
  ::mtx::PSVECCrossProduct(&param_1->mNorm,&param_2->mNorm,local_28);
  if (((G_CM3D_F_ABS_MIN <= ABS(local_28[0].x)) || (G_CM3D_F_ABS_MIN <= ABS(local_28[0].y))) ||
     (G_CM3D_F_ABS_MIN <= ABS(local_28[0].z))) {
    fVar3 = (float)ABS((double)local_28[0].x);
    fVar1 = ABS(local_28[0].y);
    if ((fVar3 < fVar1) || (fVar3 < ABS(local_28[0].z))) {
      if ((fVar1 < fVar3) || (fVar1 < ABS(local_28[0].z))) {
        cM3d_PlaneCrossLineProcWork
                  ((double)(param_1->mNorm).x,(double)(param_1->mNorm).y,(double)(param_2->mNorm).x,
                   (double)(param_2->mNorm).y,(double)local_28[0].z,(double)param_1->mDist,
                   (double)param_2->mDist,param_3,&(param_3->mP0).y);
        (param_3->mP0).z = 0_0;
      }
      else {
        cM3d_PlaneCrossLineProcWork
                  ((double)(param_1->mNorm).z,(double)(param_1->mNorm).x,(double)(param_2->mNorm).z,
                   (double)(param_2->mNorm).x,(double)local_28[0].y,(double)param_1->mDist,
                   (double)param_2->mDist,&(param_3->mP0).z,param_3);
        (param_3->mP0).y = 0_0;
      }
    }
    else {
      cM3d_PlaneCrossLineProcWork
                ((double)(param_1->mNorm).y,(double)(param_1->mNorm).z,(double)(param_2->mNorm).y,
                 (double)(param_2->mNorm).z,(double)local_28[0].x,(double)param_1->mDist,
                 (double)param_2->mDist,&(param_3->mP0).y,&(param_3->mP0).z);
      (param_3->mP0).x = 0_0;
    }
    fVar3 = ::mtx::PSVECMag((cXyz *)param_3);
    ::mtx::PSVECScale((cXyz *)local_28,(cXyz *)local_28,fVar3);
    ::mtx::PSVECAdd((cXyz *)param_3,(cXyz *)local_28,&param_3->mP1);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x802519f0) */
/* __stdcall cM3d_3PlaneCrossPos(cM3dGPla const &,
                                 cM3dGPla const &,
                                 cM3dGPla const &,
                                 Vec *) */

undefined4
cM3d_3PlaneCrossPos(cM3dGPla *param_1,cM3dGPla *param_2,cM3dGPla *param_3,cXyz *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack72 [12];
  float local_3c;
  float local_38;
  float local_34;
  undefined **local_30;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_30 = &::cM3dGLin::__vt;
  iVar1 = cM3d_2PlaneCrossLine(param_1,param_2,(cM3dGLin *)auStack72);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    dVar4 = (double)::mtx::PSVECDotProduct(param_3,auStack72);
    dVar5 = (double)(float)((double)param_3->mDist + dVar4);
    dVar4 = (double)::mtx::PSVECDotProduct(param_3,auStack72 + 0xc);
    dVar4 = (double)(float)(dVar5 - (double)(float)((double)param_3->mDist + dVar4));
    if (G_CM3D_F_ABS_MIN <= (float)ABS(dVar4)) {
      cM3d_InDivPos2((double)(float)(dVar5 / dVar4),auStack72,auStack72 + 0xc,param_4);
      uVar2 = 1;
    }
    else {
      param_4->x = local_3c;
      param_4->y = local_38;
      param_4->z = local_34;
      uVar2 = 0;
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80251ac4) */
/* __stdcall cM3d_lineVsPosSuisenCross(cM3dGLin const *,
                                       Vec const *,
                                       Vec *) */

double cM3d_lineVsPosSuisenCross(cXyz *param_1,cXyz *param_2,cXyz *param_3)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f31;
  double dVar4;
  float fVar5;
  cXyz cStack72;
  cXyz cStack60;
  cXyz cStack48;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::mtx::PSVECSubtract(param_1 + 1,param_1,&cStack48);
  fVar5 = ::mtx::PSVECSquareMag(&cStack48);
  dVar2 = (double)fVar5;
  if ((float)ABS(dVar2) < G_CM3D_F_ABS_MIN) {
    param_3->x = param_2->x;
    param_3->y = param_2->y;
    param_3->z = param_2->z;
  }
  ::mtx::PSVECSubtract(param_2,param_1,&cStack60);
  dVar3 = (double)::mtx::PSVECDotProduct(&cStack60,&cStack48);
  dVar4 = (double)(float)(dVar3 / dVar2);
  ::mtx::PSVECScale(&cStack48,&cStack72,(float)(dVar3 / dVar2));
  ::mtx::PSVECAdd(&cStack72,param_1,param_3);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return dVar4;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80251ba0) */
/* __stdcall cM3d_lineVsPosSuisenCross(Vec const &,
                                       Vec const &,
                                       Vec const &,
                                       Vec *) */

double cM3d_lineVsPosSuisenCross
                 (cXyz *param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f31;
  float fVar5;
  cXyz cStack72;
  cXyz cStack60;
  cXyz cStack48;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::mtx::PSVECSubtract(param_2,param_1,&cStack48);
  fVar5 = ::mtx::PSVECSquareMag(&cStack48);
  dVar2 = (double)fVar5;
  if (G_CM3D_F_ABS_MIN <= (float)ABS(dVar2)) {
    ::mtx::PSVECSubtract(param_3,param_1,&cStack60);
    dVar4 = (double)::mtx::PSVECDotProduct(&cStack60,&cStack48);
    dVar3 = (double)(float)(dVar4 / dVar2);
    ::mtx::PSVECScale(&cStack48,&cStack72,(float)(dVar4 / dVar2));
    ::mtx::PSVECAdd(&cStack72,param_1,param_4);
  }
  else {
    param_4->x = param_3->x;
    param_4->y = param_3->y;
    param_4->z = param_3->z;
    dVar3 = (double)0_0;
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return dVar3;
}


/* __stdcall cM3d_2PlaneLinePosNearPos(cM3dGPla const &,
                                       cM3dGPla const &,
                                       Vec const *,
                                       Vec *) */

bool cM3d_2PlaneLinePosNearPos
               (cM3dGPla *param_1,cM3dGPla *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  cM3dGLin cStack40;
  
  cStack40.vtbl = (undefined *)&::cM3dGLin::__vt;
  iVar1 = cM3d_2PlaneCrossLine(param_1,param_2,&cStack40);
  if (iVar1 != 0) {
    cM3d_lineVsPosSuisenCross(&cStack40,param_3,param_4);
  }
  return iVar1 != 0;
}


/* __stdcall cM3d_CrawVec(Vec const &,
                          Vec const &,
                          Vec *) */

void cM3d_CrawVec(cXyz *param_1,cXyz *param_2,cXyz *param_3)

{
  cXyz cStack24;
  
  ::mtx::PSVECScale(param_1,&cStack24,
                    ABS(param_2->z * param_1->z + param_2->x * param_1->x + param_2->y * param_1->y)
                   );
  ::mtx::PSVECAdd(&cStack24,param_2,param_3);
  return;
}

