#include <SComponent/c_lib.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <SComponent/c_math.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <mtx/mtx.h>
#include <mtx/mtxvec.h>


namespace SComponent {
undefined4 mtx;

/* __stdcall cLib_memCpy(void *,
                         void const *,
                         unsigned long) */

void cLib_memCpy(byte *param_1,byte *param_2,int param_3)

{
  copy_bytes(param_1,param_2,param_3);
  return;
}


/* __stdcall cLib_memSet(void *,
                         int,
                         unsigned long) */

void cLib_memSet(int param_1,uint param_2,uint param_3)

{
  FUN_800033a8(param_1,param_2,param_3);
  return;
}


/* __stdcall cLib_addCalc(float *,
                          float,
                          float,
                          float,
                          float)
   
   Move the `src` value towards `target` by `speed` multiplied by their delta. I.e. if `speed` is
   1.0, `src` will be set to `target`. If it's 0.5, `src` will move half way to `target` each time
   this is called. `min/maxVel` limit the amount of stepping that can occur on each call. Returns
   the remaining difference between `src` and `target` */

double cLib_addCalc(float *pSrc,float target,float speed,float maxVel,float minVel)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = *pSrc;
  if (fVar1 != target) {
    fVar3 = speed * (target - fVar1);
    if ((minVel <= fVar3) || (fVar2 = -minVel, fVar3 <= fVar2)) {
      if (maxVel < fVar3) {
        fVar3 = maxVel;
      }
      if (fVar3 < -maxVel) {
        fVar3 = -maxVel;
      }
      *pSrc = *pSrc + fVar3;
    }
    else {
      if (fVar3 <= 0_0) {
        if ((fVar2 < fVar3) && (*pSrc = fVar1 + fVar2, *pSrc < target)) {
          *pSrc = target;
        }
      }
      else {
        if ((fVar3 < minVel) && (*pSrc = fVar1 + minVel, target < *pSrc)) {
          *pSrc = target;
        }
      }
    }
  }
  return (double)ABS(target - *pSrc);
}


/* __stdcall cLib_addCalc2(float *,
                           float,
                           float,
                           float) */

void cLib_addCalc2(float *pDst,float target,float speedRatio,float maxSpeed)

{
  float fVar1;
  float fVar2;
  
  if (*pDst != target) {
    fVar1 = speedRatio * (target - *pDst);
    if ((fVar1 <= maxSpeed) && (fVar2 = -maxSpeed, maxSpeed = fVar1, fVar1 < fVar2)) {
      maxSpeed = fVar2;
    }
    *pDst = *pDst + maxSpeed;
    return;
  }
  return;
}


/* __stdcall cLib_addCalc0(float *,
                           float,
                           float) */

void cLib_addCalc0(float *param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *param_1 * param_2;
  if ((fVar1 <= param_3) && (fVar2 = -param_3, param_3 = fVar1, fVar1 < fVar2)) {
    param_3 = fVar2;
  }
  *param_1 = *param_1 - param_3;
  return;
}


/* WARNING: Removing unreachable block (ram,0x80252c34) */
/* WARNING: Removing unreachable block (ram,0x80252c24) */
/* WARNING: Removing unreachable block (ram,0x80252c2c) */
/* WARNING: Removing unreachable block (ram,0x80252c3c) */
/* __stdcall cLib_addCalcPos(cXyz *,
                             cXyz const &,
                             float,
                             float,
                             float) */

double cLib_addCalcPos
                 (double param_1,double param_2,double param_3,cXyz *param_4,cXyz *param_5)

{
  char cVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar5;
  cXyz local_60;
  cXyz local_54;
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
  cVar1 = ::cXyz::operator___(param_4,param_5);
  if (cVar1 != '\0') {
    ::cXyz::operator__(&local_60,param_4,param_5);
    local_54.x = local_60.x;
    local_54.y = local_60.y;
    local_54.z = local_60.z;
    fVar5 = ::mtx::PSVECSquareMag(&local_54);
    dVar4 = (double)fVar5;
    if ((double)0_0 < dVar4) {
      dVar3 = 1.0 / SQRT(dVar4);
      dVar3 = _2320 * dVar3 * (_2321 - dVar4 * dVar3 * dVar3);
      dVar3 = _2320 * dVar3 * (_2321 - dVar4 * dVar3 * dVar3);
      dVar4 = (double)(float)(dVar4 * _2320 * dVar3 * (_2321 - dVar4 * dVar3 * dVar3));
    }
    if (param_3 <= dVar4) {
      dVar4 = (double)(float)(dVar4 * param_1);
      ::mtx::PSVECScale(&local_54,&local_54,(float)param_1);
      if ((float)ABS(dVar4) < _2322) {
        param_4->x = param_5->x;
        param_4->y = param_5->y;
        param_4->z = param_5->z;
      }
      else {
        if (dVar4 <= param_2) {
          if (dVar4 < param_3) {
            ::mtx::PSVECScale(&local_54,&local_54,(float)(param_3 / dVar4));
          }
        }
        else {
          ::mtx::PSVECScale(&local_54,&local_54,(float)(param_2 / dVar4));
        }
        ::mtx::PSVECSubtract(param_4,&local_54,param_4);
      }
    }
    else {
      param_4->x = param_5->x;
      param_4->y = param_5->y;
      param_4->z = param_5->z;
    }
  }
  fVar5 = ::mtx::PSVECSquareDistance(param_4,param_5);
  dVar4 = (double)fVar5;
  if ((double)0_0 < dVar4) {
    dVar3 = 1.0 / SQRT(dVar4);
    dVar3 = _2320 * dVar3 * (_2321 - dVar4 * dVar3 * dVar3);
    dVar3 = _2320 * dVar3 * (_2321 - dVar4 * dVar3 * dVar3);
    dVar4 = (double)(float)(dVar4 * _2320 * dVar3 * (_2321 - dVar4 * dVar3 * dVar3));
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  __psq_l0(auStack56,uVar2);
  __psq_l1(auStack56,uVar2);
  return dVar4;
}


/* WARNING: Removing unreachable block (ram,0x80252eb8) */
/* WARNING: Removing unreachable block (ram,0x80252ea8) */
/* WARNING: Removing unreachable block (ram,0x80252eb0) */
/* WARNING: Removing unreachable block (ram,0x80252ec0) */
/* __stdcall cLib_addCalcPosXZ(cXyz *,
                               cXyz const &,
                               float,
                               float,
                               float) */

double cLib_addCalcPosXZ
                 (double param_1,double param_2,double param_3,cXyz *param_4,cXyz *param_5)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar4;
  cXyz local_90;
  cXyz local_84;
  cXyz local_78;
  cXyz local_6c;
  cXyz local_60 [2];
  undefined auStack56 [16];
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
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  if ((param_4->x != param_5->x) || (param_4->z != param_5->z)) {
    ::cXyz::operator__(&local_6c,param_4,param_5);
    local_60[0].x = local_6c.x;
    local_60[0].y = local_6c.y;
    local_60[0].z = local_6c.z;
    local_84.x = local_6c.x;
    local_84.y = 0_0;
    local_84.z = local_6c.z;
    fVar4 = ::mtx::PSVECSquareMag(&local_84);
    dVar3 = (double)fVar4;
    if ((double)0_0 < dVar3) {
      dVar2 = 1.0 / SQRT(dVar3);
      dVar2 = _2320 * dVar2 * (_2321 - dVar3 * dVar2 * dVar2);
      dVar2 = _2320 * dVar2 * (_2321 - dVar3 * dVar2 * dVar2);
      dVar3 = (double)(float)(dVar3 * _2320 * dVar2 * (_2321 - dVar3 * dVar2 * dVar2));
    }
    if (param_3 <= dVar3) {
      dVar3 = (double)(float)(dVar3 * param_1);
      ::mtx::PSVECScale(local_60,local_60,(float)param_1);
      if ((float)ABS(dVar3) < _2322) {
        param_4->x = param_5->x;
        param_4->z = param_5->z;
      }
      else {
        if (dVar3 <= param_2) {
          if (dVar3 < param_3) {
            ::mtx::PSVECScale(local_60,local_60,(float)(param_3 / dVar3));
          }
        }
        else {
          ::mtx::PSVECScale(local_60,local_60,(float)(param_2 / dVar3));
        }
        param_4->x = param_4->x - local_60[0].x;
        param_4->z = param_4->z - local_60[0].z;
      }
    }
    else {
      param_4->x = param_5->x;
      param_4->z = param_5->z;
    }
  }
  ::cXyz::operator__(&local_78,param_4,param_5);
  local_90.x = local_78.x;
  local_90.y = 0_0;
  local_90.z = local_78.z;
  fVar4 = ::mtx::PSVECSquareMag(&local_90);
  dVar3 = (double)fVar4;
  if ((double)0_0 < dVar3) {
    dVar2 = 1.0 / SQRT(dVar3);
    dVar2 = _2320 * dVar2 * (_2321 - dVar3 * dVar2 * dVar2);
    dVar2 = _2320 * dVar2 * (_2321 - dVar3 * dVar2 * dVar2);
    dVar3 = (double)(float)(dVar3 * _2320 * dVar2 * (_2321 - dVar3 * dVar2 * dVar2));
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  __psq_l0(auStack40,uVar1);
  __psq_l1(auStack40,uVar1);
  __psq_l0(auStack56,uVar1);
  __psq_l1(auStack56,uVar1);
  return dVar3;
}


/* WARNING: Removing unreachable block (ram,0x80253010) */
/* WARNING: Removing unreachable block (ram,0x80253018) */
/* __stdcall cLib_addCalcPos2(cXyz *,
                              cXyz const &,
                              float,
                              float) */

void cLib_addCalcPos2(cXyz *param_1,cXyz *param_2,float param_3,float param_4)

{
  char cVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar6;
  cXyz local_64;
  cXyz local_58;
  cXyz cStack76;
  cXyz local_40;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar4 = (double)param_3;
  dVar5 = (double)param_4;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  cVar1 = ::cXyz::operator___(param_1,param_2);
  if (cVar1 != '\0') {
    ::cXyz::operator__(&cStack76,param_1,param_2);
    ::cXyz::operator_(&local_58,&cStack76,(float)dVar4);
    local_40.x = local_58.x;
    local_40.y = local_58.y;
    local_40.z = local_58.z;
    fVar6 = ::mtx::PSVECSquareMag(&local_40);
    dVar4 = (double)fVar6;
    if ((double)0_0 < dVar4) {
      dVar3 = 1.0 / SQRT(dVar4);
      dVar3 = _2320 * dVar3 * (_2321 - dVar4 * dVar3 * dVar3);
      dVar3 = _2320 * dVar3 * (_2321 - dVar4 * dVar3 * dVar3);
      dVar4 = (double)(float)(dVar4 * _2320 * dVar3 * (_2321 - dVar4 * dVar3 * dVar3));
    }
    if (dVar5 < dVar4) {
      ::cXyz::normZP(&local_64,&local_40);
      local_40.x = local_64.x;
      local_40.y = local_64.y;
      local_40.z = local_64.z;
      ::mtx::PSVECScale(&local_40,&local_40,(float)dVar5);
    }
    ::mtx::PSVECSubtract(param_1,&local_40,param_1);
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80253184) */
/* WARNING: Removing unreachable block (ram,0x8025318c) */
/* __stdcall cLib_addCalcPosXZ2(cXyz *,
                                cXyz const &,
                                float,
                                float) */

void cLib_addCalcPosXZ2(cXyz *pDst,cXyz *pTarget,float speed,float maxVel)

{
  undefined4 uVar1;
  double dVar2;
  double vel;
  double dVar3;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar4;
  cXyz local_64;
  cXyz local_58;
  cXyz cStack76;
  cXyz local_40;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  vel = (double)speed;
  dVar3 = (double)maxVel;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if ((pDst->x != pTarget->x) || (pDst->z != pTarget->z)) {
    ::cXyz::operator__(&cStack76,pDst,pTarget);
    ::cXyz::operator_(&local_58,&cStack76,(float)vel);
    local_40.x = local_58.x;
    local_40.y = local_58.y;
    local_40.z = local_58.z;
    local_64.x = local_58.x;
    local_64.y = 0_0;
    local_64.z = local_58.z;
    fVar4 = ::mtx::PSVECSquareMag(&local_64);
    vel = (double)fVar4;
    if ((double)0_0 < vel) {
      dVar2 = 1.0 / SQRT(vel);
      dVar2 = _2320 * dVar2 * (_2321 - vel * dVar2 * dVar2);
      dVar2 = _2320 * dVar2 * (_2321 - vel * dVar2 * dVar2);
      vel = (double)(float)(vel * _2320 * dVar2 * (_2321 - vel * dVar2 * dVar2));
    }
    if (_2322 <= (float)ABS(vel)) {
      if (dVar3 < vel) {
        ::mtx::PSVECScale(&local_40,&local_40,(float)(dVar3 / vel));
      }
      pDst->x = pDst->x - local_40.x;
      pDst->z = pDst->z - local_40.z;
    }
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* __stdcall cLib_addCalcAngleS(short *,
                                short,
                                short,
                                short,
                                short) */

int cLib_addCalcAngleS(short *pDst,short target,short speed,short maxVel,short param_5)

{
  short sVar1;
  int iVar2;
  short dst;
  
  dst = *pDst;
  if (dst != target) {
    sVar1 = (short)(target - dst) / speed;
    iVar2 = (int)sVar1;
    if (iVar2 <= param_5) {
      if (-(int)param_5 <= iVar2) {
        if ((short)(target - dst) < 0) {
          *pDst = dst - param_5;
          if (-1 < (short)(target - *pDst)) {
            *pDst = target;
          }
        }
        else {
          *pDst = dst + param_5;
          if ((short)(target - *pDst) < 1) {
            *pDst = target;
          }
        }
        goto LAB_80253260;
      }
    }
    if (maxVel < iVar2) {
      sVar1 = maxVel;
    }
    if ((int)sVar1 < -(int)maxVel) {
      sVar1 = (short)-(int)maxVel;
    }
    *pDst = *pDst + sVar1;
  }
LAB_80253260:
  return (int)(short)(target - *pDst);
}


/* __stdcall cLib_addCalcAngleS2(short *,
                                 short,
                                 short,
                                 short) */

void cLib_addCalcAngleS2(short *pDst,short target,short speedRatio,short maxSpeed)

{
  short sVar1;
  short sVar2;
  
  sVar1 = *pDst;
  sVar2 = (short)(target - sVar1) / speedRatio;
  if ((int)maxSpeed < (int)sVar2) {
    *pDst = sVar1 + maxSpeed;
    return;
  }
  if ((int)sVar2 < -(int)maxSpeed) {
    *pDst = sVar1 - maxSpeed;
    return;
  }
  *pDst = sVar1 + sVar2;
  return;
}


/* __stdcall cLib_addCalcAngleL(long *,
                                long,
                                long,
                                long,
                                long) */

int cLib_addCalcAngleL(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = param_2 - iVar1;
  if (iVar1 != param_2) {
    param_3 = iVar2 / param_3;
    if ((param_5 < param_3) || (param_3 < -param_5)) {
      if (param_4 < param_3) {
        param_3 = param_4;
      }
      if (param_3 < -param_4) {
        param_3 = -param_4;
      }
      *param_1 = *param_1 + param_3;
    }
    else {
      if (iVar2 < 0) {
        *param_1 = iVar1 - param_5;
        if (-1 < param_2 - *param_1) {
          *param_1 = param_2;
        }
      }
      else {
        *param_1 = iVar1 + param_5;
        if (param_2 - *param_1 < 1) {
          *param_1 = param_2;
        }
      }
    }
  }
  return iVar2;
}


/* __stdcall cLib_chaseUC(unsigned char *,
                          unsigned char,
                          unsigned char) */

undefined4 cLib_chaseUC(byte *param_1,byte param_2,ushort param_3)

{
  short sVar1;
  
  param_3 = param_3 & 0xff;
  if (param_3 == 0) {
    if (*param_1 == param_2) {
      return 1;
    }
  }
  else {
    if ((ushort)param_2 < (ushort)*param_1) {
      param_3 = -param_3;
    }
    sVar1 = *param_1 + param_3;
    if (-1 < (int)(short)param_3 * ((int)sVar1 - (int)(short)(ushort)param_2)) {
      *param_1 = param_2;
      return 1;
    }
    *param_1 = (byte)sVar1;
  }
  return 0;
}


/* __stdcall cLib_chaseS(short *,
                         short,
                         short) */

undefined4 cLib_chaseS(short *param_1,short param_2,short param_3)

{
  if (param_3 == 0) {
    if (*param_1 == param_2) {
      return 1;
    }
  }
  else {
    if (param_2 < *param_1) {
      param_3 = -param_3;
    }
    *param_1 = *param_1 + param_3;
    if (-1 < (int)param_3 * ((int)*param_1 - (int)param_2)) {
      *param_1 = param_2;
      return 1;
    }
  }
  return 0;
}


/* __stdcall cLib_chaseF(float *,
                         float,
                         float) */

undefined4 cLib_chaseF(float *pDst,float target,float speed)

{
  if (speed == 0_0) {
    if (*pDst == target) {
      return 1;
    }
  }
  else {
    if (target < *pDst) {
      speed = -speed;
    }
    *pDst = *pDst + speed;
    if (0_0 <= speed * (*pDst - target)) {
      *pDst = target;
      return 1;
    }
  }
  return 0;
}


/* WARNING: Removing unreachable block (ram,0x802535f0) */
/* __stdcall cLib_chasePos(cXyz *,
                           cXyz const &,
                           float) */

undefined4 cLib_chasePos(double param_1,cXyz *param_2,cXyz *param_3)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  float fVar6;
  cXyz cStack68;
  cXyz local_38;
  cXyz local_2c;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 == (double)0_0) {
    cVar2 = ::cXyz::operator___(param_2,(Vec *)param_3);
    if (cVar2 != '\0') {
      uVar1 = 1;
      goto LAB_802535f0;
    }
  }
  else {
    ::cXyz::operator__(&local_38,param_2,param_3);
    local_2c.x = local_38.x;
    local_2c.y = local_38.y;
    local_2c.z = local_38.z;
    fVar6 = ::mtx::PSVECSquareMag(&local_2c);
    dVar5 = (double)fVar6;
    if ((double)0_0 < dVar5) {
      dVar4 = 1.0 / SQRT(dVar5);
      dVar4 = _2320 * dVar4 * (_2321 - dVar5 * dVar4 * dVar4);
      dVar4 = _2320 * dVar4 * (_2321 - dVar5 * dVar4 * dVar4);
      dVar5 = (double)(float)(dVar5 * _2320 * dVar4 * (_2321 - dVar5 * dVar4 * dVar4));
    }
    if (((float)ABS(dVar5) < _2322) || (dVar5 <= param_1)) {
      param_2->x = param_3->x;
      param_2->y = param_3->y;
      param_2->z = param_3->z;
      uVar1 = 1;
      goto LAB_802535f0;
    }
    ::cXyz::operator_(&cStack68,&local_2c,(float)(param_1 / dVar5));
    ::mtx::PSVECSubtract(param_2,&cStack68,param_2);
  }
  uVar1 = 0;
LAB_802535f0:
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x80253770) */
/* __stdcall cLib_chasePosXZ(cXyz *,
                             cXyz const &,
                             float) */

undefined4 cLib_chasePosXZ(cXyz *param_1,cXyz *param_2,double param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f31;
  float fVar5;
  cXyz local_54;
  cXyz cStack72;
  cXyz local_3c;
  cXyz local_30;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::cXyz::operator__(&local_3c,param_1,param_2);
  local_30.x = local_3c.x;
  local_30.z = local_3c.z;
  local_30.y = 0_0;
  local_54.x = local_3c.x;
  local_54.y = 0_0;
  local_54.z = local_3c.z;
  fVar5 = ::mtx::PSVECSquareMag(&local_54);
  dVar4 = (double)fVar5;
  if ((double)0_0 < dVar4) {
    dVar3 = 1.0 / SQRT(dVar4);
    dVar3 = _2320 * dVar3 * (_2321 - dVar4 * dVar3 * dVar3);
    dVar3 = _2320 * dVar3 * (_2321 - dVar4 * dVar3 * dVar3);
    dVar4 = (double)(float)(dVar4 * _2320 * dVar3 * (_2321 - dVar4 * dVar3 * dVar3));
  }
  if (param_3 == (double)0_0) {
    if ((float)ABS(dVar4) < _2322) {
      uVar1 = 1;
      goto LAB_80253770;
    }
  }
  else {
    if (((float)ABS(dVar4) < _2322) || (dVar4 <= param_3)) {
      param_1->x = param_2->x;
      param_1->y = param_2->y;
      param_1->z = param_2->z;
      uVar1 = 1;
      goto LAB_80253770;
    }
    ::cXyz::operator_(&cStack72,&local_30,(float)(param_3 / dVar4));
    ::mtx::PSVECSubtract(param_1,&cStack72,param_1);
  }
  uVar1 = 0;
LAB_80253770:
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return uVar1;
}


/* __stdcall cLib_chaseAngleS(short *,
                              short,
                              short) */

undefined4 cLib_chaseAngleS(short *param_1,short param_2,short param_3)

{
  if (param_3 == 0) {
    if (*param_1 == param_2) {
      return 1;
    }
  }
  else {
    if (0 < (short)(*param_1 - param_2)) {
      param_3 = -param_3;
    }
    *param_1 = *param_1 + param_3;
    if (-1 < (int)param_3 * (int)(short)(*param_1 - param_2)) {
      *param_1 = param_2;
      return 1;
    }
  }
  return 0;
}


/* __stdcall cLib_targetAngleY(cXyz *,
                               cXyz *) */

short cLib_targetAngleY(cXyz *param_1,cXyz *param_2)

{
  int iVar1;
  
  iVar1 = cM_atan2s(param_2->x - param_1->x,param_2->z - param_1->z);
  return (short)iVar1;
}


/* __stdcall cLib_targetAngleX(cXyz *,
                               cXyz *) */

void cLib_targetAngleX(cXyz *param_1,cXyz *param_2)

{
  double dVar1;
  double dVar2;
  float fVar3;
  cXyz local_24;
  cXyz local_18;
  float local_c;
  float local_8;
  float local_4;
  
  ::cXyz::operator__(&local_18,param_2,param_1);
  local_c = local_18.x;
  local_8 = local_18.y;
  local_4 = local_18.z;
  local_24.x = local_18.x;
  local_24.y = 0_0;
  local_24.z = local_18.z;
  fVar3 = ::mtx::PSVECSquareMag(&local_24);
  dVar2 = (double)fVar3;
  if ((double)0_0 < dVar2) {
    dVar1 = 1.0 / SQRT(dVar2);
    dVar1 = _2320 * dVar1 * (_2321 - dVar2 * dVar1 * dVar1);
    dVar1 = _2320 * dVar1 * (_2321 - dVar2 * dVar1 * dVar1);
    dVar2 = (double)(float)(dVar2 * _2320 * dVar1 * (_2321 - dVar2 * dVar1 * dVar1));
  }
  cM_atan2s(local_8,(float)dVar2);
  return;
}


/* __stdcall cLib_offsetPos(cXyz *,
                            cXyz *,
                            short,
                            cXyz *) */

void cLib_offsetPos(cXyz *param_1,cXyz *param_2,short param_3,cXyz *param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = (int)(uint)(ushort)param_3 >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar1 = JKernel::JMath::jmaCosTable[iVar3];
  fVar2 = JKernel::JMath::jmaSinTable[iVar3];
  param_1->x = param_2->x + param_4->x * fVar1 + param_4->z * fVar2;
  param_1->y = param_2->y + param_4->y;
  param_1->z = param_2->z + (param_4->z * fVar1 - param_4->x * fVar2);
  return;
}


/* __stdcall cLib_distanceAngleS(short,
                                 short) */

short cLib_distanceAngleS(short param_1,short param_2)

{
  int iVar1;
  
  iVar1 = MSL_C.PPCEABI.bare.H::abs((int)(short)(param_1 - param_2));
  return (short)iVar1;
}


/* __stdcall MtxInit(void) */

void MtxInit(void)

{
  calc_mtx = (MTX34 *)&mtx;
  return;
}


/* __stdcall MtxTrans(float,
                      float,
                      float,
                      unsigned char) */

void MtxTrans(double param_1,double param_2,double param_3,bool param_4)

{
  MTX34 MStack56;
  
  if (param_4 == false) {
    ::mtx::PSMTXTrans(param_1,param_2,param_3,calc_mtx);
  }
  else {
    ::mtx::PSMTXTrans(param_1,param_2,param_3,&MStack56);
    ::mtx::PSMTXConcat(calc_mtx,&MStack56,calc_mtx);
  }
  return;
}


/* __stdcall MtxRotX(float,
                     unsigned char) */

void MtxRotX(double param_1,char param_2)

{
  MTX34 MStack56;
  
  if (param_2 == '\0') {
    ::mtx::PSMTXRotRad(calc_mtx,'X',(float)param_1);
  }
  else {
    ::mtx::PSMTXRotRad(&MStack56,'X',(float)param_1);
    ::mtx::PSMTXConcat(calc_mtx,&MStack56,calc_mtx);
  }
  return;
}


/* __stdcall MtxRotY(float,
                     unsigned char) */

void MtxRotY(double param_1,char param_2)

{
  MTX34 MStack56;
  
  if (param_2 == '\0') {
    ::mtx::PSMTXRotRad(calc_mtx,'Y',(float)param_1);
  }
  else {
    ::mtx::PSMTXRotRad(&MStack56,'Y',(float)param_1);
    ::mtx::PSMTXConcat(calc_mtx,&MStack56,calc_mtx);
  }
  return;
}


/* __stdcall MtxRotZ(float,
                     unsigned char) */

void MtxRotZ(double param_1,char param_2)

{
  MTX34 MStack56;
  
  if (param_2 == '\0') {
    ::mtx::PSMTXRotRad(calc_mtx,'Z',(float)param_1);
  }
  else {
    ::mtx::PSMTXRotRad(&MStack56,'Z',(float)param_1);
    ::mtx::PSMTXConcat(calc_mtx,&MStack56,calc_mtx);
  }
  return;
}


/* __stdcall MtxScale(float,
                      float,
                      float,
                      unsigned char) */

void MtxScale(double param_1,double param_2,double param_3,char param_4)

{
  MTX34 MStack56;
  
  if (param_4 == '\0') {
    ::mtx::PSMTXScale(param_1,param_2,param_3,calc_mtx);
  }
  else {
    ::mtx::PSMTXScale(param_1,param_2,param_3,&MStack56);
    ::mtx::PSMTXConcat(calc_mtx,&MStack56,calc_mtx);
  }
  return;
}


/* __stdcall MtxPosition(cXyz *,
                         cXyz *) */

void MtxPosition(cXyz *pSrc,cXyz *pDst)

{
  ::mtx::PSMTXMultVec(calc_mtx,pSrc,pDst);
  return;
}


/* __stdcall MtxPush(void) */

void MtxPush(void)

{
  MTX34 MStack56;
  
  ::mtx::PSMTXCopy(calc_mtx,&MStack56);
  calc_mtx = calc_mtx + 1;
  ::mtx::PSMTXCopy(&MStack56,calc_mtx);
  return;
}


/* __stdcall MtxPull(void) */

void MtxPull(void)

{
  calc_mtx = calc_mtx + -1;
  return;
}

