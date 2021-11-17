#include <SComponent/c_math.h>
#include <MSL_C.PPCEABI.bare.H/w_fmod.h>
#include <SComponent/c_math.h>


namespace SComponent {
undefined4 r0;
undefined4 r1;
undefined4 r2;
undefined4 r02;
undefined4 r12;
undefined4 r22;

/* __stdcall cM_rad2s(float) */

int cM_rad2s(double param_1)

{
  int iVar1;
  double dVar2;
  
  dVar2 = MSL_C.PPCEABI.bare.H::fmod(param_1,_2164);
  iVar1 = (int)(_2177 * dVar2);
  if (iVar1 < -0x8000) {
    iVar1 = iVar1 + 0x10000;
  }
  else {
    if (0x7fff < iVar1) {
      iVar1 = iVar1 + -0x10000;
    }
  }
  return (int)(short)iVar1;
}


/* __stdcall U_GetAtanTable(float,
                            float) */

undefined2 U_GetAtanTable(double param_1,double param_2)

{
  return *(undefined2 *)(&atntable + (int)(_2193 * (float)(param_1 / param_2)) * 2);
}


/* __stdcall cM_atan2s(float,
                       float) */

int cM_atan2s(float param_1,float param_2)

{
  short sVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar4 = (double)param_2;
  dVar3 = (double)param_1;
  if (G_CM3D_F_ABS_MIN <= (float)ABS(dVar3)) {
    if (G_CM3D_F_ABS_MIN <= (float)ABS(dVar4)) {
      dVar2 = (double)_2238;
      if (dVar3 < dVar2) {
        if (dVar2 <= dVar4) {
          dVar3 = -dVar3;
          if (dVar3 <= dVar4) {
            sVar1 = U_GetAtanTable(dVar3);
            sVar1 = -sVar1;
          }
          else {
            sVar1 = U_GetAtanTable(dVar4,dVar3);
            sVar1 = sVar1 + -0x4000;
          }
        }
        else {
          if (dVar3 < dVar4) {
            sVar1 = U_GetAtanTable(-dVar4,-dVar3);
            sVar1 = -0x4000 - sVar1;
          }
          else {
            sVar1 = U_GetAtanTable(-dVar3,-dVar4);
            sVar1 = sVar1 + -0x8000;
          }
        }
      }
      else {
        if (dVar4 < dVar2) {
          if (dVar3 <= -dVar4) {
            sVar1 = U_GetAtanTable();
            sVar1 = -0x8000 - sVar1;
          }
          else {
            sVar1 = U_GetAtanTable(-dVar4,dVar3);
            sVar1 = sVar1 + 0x4000;
          }
        }
        else {
          if (dVar4 < dVar3) {
            sVar1 = U_GetAtanTable(dVar4,dVar3);
            sVar1 = 0x4000 - sVar1;
          }
          else {
            sVar1 = U_GetAtanTable();
          }
        }
      }
    }
    else {
      if (dVar3 < (double)_2238) {
        sVar1 = -0x4000;
      }
      else {
        sVar1 = 0x4000;
      }
    }
  }
  else {
    if (dVar4 < (double)_2238) {
      sVar1 = -0x8000;
    }
    else {
      sVar1 = 0;
    }
  }
  return (int)sVar1;
}


/* __stdcall cM_atan2f(float,
                       float) */

double cM_atan2f(double param_1,double param_2)

{
  int iVar1;
  
  iVar1 = cM_atan2s((float)param_1,(float)param_2);
  return (double)(_2243 * (float)((double)CONCAT44(0x43300000,(int)(short)iVar1 ^ 0x80000000) -
                                 _2245));
}


/* __stdcall cM_initRnd(int,
                        int,
                        int) */

void cM_initRnd(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  r0 = param_1;
  r1 = param_2;
  r2 = param_3;
  return;
}


/* __stdcall cM_rnd(void) */

float cM_rnd(float param_1)

{
  double dVar1;
  
  r0 = (int)(r0 * 0xab) % 0x763d;
  r1 = (int)(r1 * 0xac) % 0x7663;
  r2 = (int)(r2 * 0xaa) % 0x7673;
  dVar1 = MSL_C.PPCEABI.bare.H::fmod
                    ((double)((float)((double)CONCAT44(0x43300000,r2 ^ 0x80000000) - _2245) / _2257
                             + (float)((double)CONCAT44(0x43300000,r0 ^ 0x80000000) - _2245) / _2258
                               + (float)((double)CONCAT44(0x43300000,r1 ^ 0x80000000) - _2245) /
                                 _2259),_2260);
  return ABS((float)dVar1);
}


/* WARNING: Removing unreachable block (ram,0x802463d0) */
/* __stdcall cM_rndF(float) */

float cM_rndF(float param_1)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  float fVar3;
  undefined auStack8 [8];
  
  dVar2 = (double)param_1;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar3 = cM_rnd(param_1);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return (float)(dVar2 * (double)fVar3);
}


/* WARNING: Removing unreachable block (ram,0x80246418) */
/* __stdcall cM_rndFX(float) */

float cM_rndFX(float param_1)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  float fVar3;
  undefined auStack8 [8];
  
  dVar2 = (double)param_1;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar3 = cM_rnd(param_1);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return _2272 * (float)(dVar2 * (double)(fVar3 - _2273));
}


/* __stdcall cM_initRnd2(int,
                         int,
                         int) */

void cM_initRnd2(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  r02 = param_1;
  r12 = param_2;
  r22 = param_3;
  return;
}

