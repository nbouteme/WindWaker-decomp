#include <mtx/vec.h>
#include <mtx/vec.h>


namespace mtx {

/* WARNING: Removing unreachable block (ram,0x8030dcf4) */
/* WARNING: Removing unreachable block (ram,0x8030dce4) */
/* WARNING: Removing unreachable block (ram,0x8030dce0) */
/* WARNING: Removing unreachable block (ram,0x8030dcf0) */
/* WARNING: Removing unreachable block (ram,0x8030dcfc) */

void PSVECAdd(cXyz *param_1,cXyz *param_2,cXyz *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = (float)__psq_l0(param_1,0);
  fVar2 = (float)__psq_l1(param_1,0);
  fVar3 = (float)__psq_l0(param_2,0);
  fVar4 = (float)__psq_l1(param_2,0);
  __psq_st0(param_3,fVar1 + fVar3,0);
  __psq_st1(param_3,fVar2 + fVar4,0);
  fVar1 = (float)__psq_l0(&param_1->z,0);
  fVar2 = (float)__psq_l0(&param_2->z,0);
  __psq_st0(&param_3->z,fVar1 + fVar2,0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8030dd18) */
/* WARNING: Removing unreachable block (ram,0x8030dd08) */
/* WARNING: Removing unreachable block (ram,0x8030dd04) */
/* WARNING: Removing unreachable block (ram,0x8030dd14) */
/* WARNING: Removing unreachable block (ram,0x8030dd20) */

void PSVECSubtract(cXyz *param_1,cXyz *param_2,cXyz *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = (float)__psq_l0(param_1,0);
  fVar2 = (float)__psq_l1(param_1,0);
  fVar3 = (float)__psq_l0(param_2,0);
  fVar4 = (float)__psq_l1(param_2,0);
  __psq_st0(param_3,fVar1 - fVar3,0);
  __psq_st1(param_3,fVar2 - fVar4,0);
  fVar1 = (float)__psq_l0(&param_1->z,0);
  fVar2 = (float)__psq_l0(&param_2->z,0);
  __psq_st0(&param_3->z,fVar1 - fVar2,0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8030dd2c) */
/* WARNING: Removing unreachable block (ram,0x8030dd28) */
/* WARNING: Removing unreachable block (ram,0x8030dd3c) */

void PSVECScale(cXyz *param_1_00,cXyz *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = (float)__psq_l0(param_1_00,0);
  fVar2 = (float)__psq_l1(param_1_00,0);
  fVar4 = (float)__psq_l0(&param_1_00->z,0);
  fVar3 = (float)((ulonglong)(double)param_3 >> 0x20);
  __psq_st0(param_2,fVar1 * fVar3,0);
  __psq_st1(param_2,fVar2 * fVar3,0);
  __psq_st0(&param_2->z,fVar4 * fVar3,0);
  return;
}


void C_VECNormalize(float *param_1,float *param_2)

{
  float fVar1;
  double dVar2;
  double dVar3;
  
  dVar2 = (double)(param_1[2] * param_1[2] + *param_1 * *param_1 + param_1[1] * param_1[1]);
  if ((double)_113 < dVar2) {
    dVar3 = 1.0 / SQRT(dVar2);
    dVar3 = _114 * dVar3 * (_115 - dVar2 * dVar3 * dVar3);
    dVar3 = _114 * dVar3 * (_115 - dVar2 * dVar3 * dVar3);
    dVar2 = (double)(float)(dVar2 * _114 * dVar3 * (_115 - dVar2 * dVar3 * dVar3));
  }
  fVar1 = (float)((double)_116 / dVar2);
  *param_2 = *param_1 * fVar1;
  param_2[1] = param_1[1] * fVar1;
  param_2[2] = param_1[2] * fVar1;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8030de1c) */
/* WARNING: Removing unreachable block (ram,0x8030de14) */
/* WARNING: Removing unreachable block (ram,0x8030de48) */

double PSVECNormalize(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  
  fVar1 = (float)__psq_l0(param_1,0);
  fVar2 = (float)__psq_l1(param_1,0);
  fVar3 = (float)__psq_l0(param_1 + 8,0);
  fVar4 = fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2;
  dVar5 = 1.0 / SQRT((double)CONCAT44(fVar4,0x3f800000));
  fVar4 = (float)((ulonglong)
                  (double)(-(float)((double)(float)(dVar5 * dVar5) *
                                    (double)CONCAT44(fVar4,0x3f800000) - (double)_119) *
                          (float)(dVar5 * (double)_118)) >> 0x20);
  __psq_st0(param_2,fVar1 * fVar4,0);
  __psq_st1(param_2,fVar2 * fVar4,0);
  __psq_st0(param_2 + 8,fVar3 * fVar4,0);
  return (double)_119;
}


/* WARNING: Removing unreachable block (ram,0x8030de50) */

float PSVECSquareMag(cXyz *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar1 = (float)__psq_l0(param_1,0);
  fVar2 = (float)__psq_l1(param_1,0);
  fVar3 = (float)((ulonglong)(double)param_1->z >> 0x20);
  return (float)(double)CONCAT44(fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2,fVar2 * fVar2);
}


/* WARNING: Removing unreachable block (ram,0x8030de6c) */

float PSVECMag(cXyz *param_1)

{
  float fVar1;
  float fVar3;
  double dVar2;
  float fVar4;
  double dVar5;
  double dVar6;
  
  dVar6 = (double)_118;
  fVar1 = (float)__psq_l0(param_1,0);
  fVar3 = (float)__psq_l1(param_1,0);
  fVar4 = (float)((ulonglong)(double)param_1->z >> 0x20);
  dVar5 = (double)CONCAT44(fVar4 * fVar4 + fVar1 * fVar1 + fVar3 * fVar3,fVar3 * fVar3);
  if (dVar5 != (double)(float)(dVar6 - dVar6)) {
    dVar2 = 1.0 / SQRT(dVar5);
    dVar5 = (double)(float)(dVar5 * (double)(-(float)((double)(float)(dVar2 * dVar2) * dVar5 -
                                                     (double)_119) * (float)(dVar2 * dVar6)));
  }
  return (float)dVar5;
}


/* WARNING: Removing unreachable block (ram,0x8030deb8) */
/* WARNING: Removing unreachable block (ram,0x8030deac) */
/* WARNING: Removing unreachable block (ram,0x8030deb0) */
/* WARNING: Removing unreachable block (ram,0x8030debc) */

undefined8 PSVECDotProduct(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = (float)__psq_l0(param_1 + 4,0);
  fVar2 = (float)__psq_l1(param_1 + 4,0);
  fVar3 = (float)__psq_l0(param_2 + 4,0);
  fVar4 = (float)__psq_l1(param_2 + 4,0);
  fVar6 = (float)__psq_l0(param_1,0);
  __psq_l1(param_1,0);
  fVar5 = (float)__psq_l0(param_2,0);
  __psq_l1(param_2,0);
  return CONCAT44(fVar6 * fVar5 + fVar1 * fVar3 + fVar2 * fVar4,fVar2 * fVar4);
}


/* WARNING: Removing unreachable block (ram,0x8030decc) */
/* WARNING: Removing unreachable block (ram,0x8030ded4) */
/* WARNING: Removing unreachable block (ram,0x8030def8) */

void PSVECCrossProduct(TVec3_float_ *param_1,TVec3_float_ *param_2,TVec3_float_ *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar3 = (float)__psq_l0(param_2,0);
  fVar4 = (float)__psq_l1(param_2,0);
  fVar1 = (float)__psq_l0(param_1,0);
  fVar2 = (float)__psq_l1(param_1,0);
  __psq_st0(param_3,fVar2 * SUB84((double)param_2->z,0) - fVar4 * SUB84((double)param_1->z,0),0);
  __psq_st0(&param_3->y,
            -(fVar1 * (float)((ulonglong)(double)param_2->z >> 0x20) -
             fVar3 * (float)((ulonglong)(double)param_1->z >> 0x20)),0);
  __psq_st1(&param_3->y,-(fVar2 * fVar3 - fVar4 * fVar1),0);
  return;
}


void C_VECHalfAngle(cXyz *param_1,cXyz *param_2,cXyz *param_3)

{
  double dVar1;
  cXyz local_2c;
  cXyz local_20;
  cXyz local_14;
  
  local_14.x = -param_1->x;
  local_14.y = -param_1->y;
  local_14.z = -param_1->z;
  local_20.x = -param_2->x;
  local_20.y = -param_2->y;
  local_20.z = -param_2->z;
  PSVECNormalize(&local_14,&local_14);
  PSVECNormalize(&local_20,&local_20);
  PSVECAdd(&local_14,&local_20,&local_2c);
  dVar1 = (double)PSVECDotProduct(&local_2c,&local_2c);
  if (dVar1 <= (double)_113) {
    param_3->x = local_2c.x;
    param_3->y = local_2c.y;
    param_3->z = local_2c.z;
  }
  else {
    PSVECNormalize(&local_2c,param_3);
  }
  return;
}


void C_VECReflect(float *param_1,undefined4 param_2,float *param_3)

{
  float fVar1;
  double dVar2;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  local_18 = -*param_1;
  local_14 = -param_1[1];
  local_10 = -param_1[2];
  PSVECNormalize(&local_18,&local_18);
  PSVECNormalize(param_2,&local_24);
  dVar2 = (double)PSVECDotProduct(&local_18,&local_24);
  fVar1 = _161;
  *param_3 = (float)((double)(_161 * local_24) * dVar2) - local_18;
  param_3[1] = (float)((double)(fVar1 * local_20) * dVar2) - local_14;
  param_3[2] = (float)((double)(fVar1 * local_1c) * dVar2) - local_10;
  PSVECNormalize(param_3,param_3);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8030e0c0) */
/* WARNING: Removing unreachable block (ram,0x8030e0b4) */
/* WARNING: Removing unreachable block (ram,0x8030e0b8) */
/* WARNING: Removing unreachable block (ram,0x8030e0c4) */

float PSVECSquareDistance(cXyz *param_1,cXyz *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = (float)__psq_l0(&param_1->y,0);
  fVar3 = (float)__psq_l1(&param_1->y,0);
  fVar4 = (float)__psq_l0(&param_2->y,0);
  fVar6 = (float)__psq_l1(&param_2->y,0);
  fVar2 = (float)__psq_l0(param_1,0);
  __psq_l1(param_1,0);
  fVar5 = (float)__psq_l0(param_2,0);
  __psq_l1(param_2,0);
  fVar3 = (fVar3 - fVar6) * (fVar3 - fVar6);
  return (float)(double)CONCAT44((fVar2 - fVar5) * (fVar2 - fVar5) +
                                 (fVar1 - fVar4) * (fVar1 - fVar4) + fVar3,fVar3);
}


/* WARNING: Removing unreachable block (ram,0x8030e0e8) */
/* WARNING: Removing unreachable block (ram,0x8030e0dc) */
/* WARNING: Removing unreachable block (ram,0x8030e0e0) */
/* WARNING: Removing unreachable block (ram,0x8030e0ec) */

float PSVECDistance(cXyz *param_1,cXyz *param_2)

{
  float fVar1;
  float fVar2;
  float fVar4;
  double dVar3;
  float fVar5;
  float fVar6;
  float fVar8;
  double dVar7;
  double dVar9;
  
  fVar1 = (float)__psq_l0(&param_1->y,0);
  fVar4 = (float)__psq_l1(&param_1->y,0);
  fVar5 = (float)__psq_l0(&param_2->y,0);
  fVar8 = (float)__psq_l1(&param_2->y,0);
  fVar2 = (float)__psq_l0(param_1,0);
  __psq_l1(param_1,0);
  fVar6 = (float)__psq_l0(param_2,0);
  __psq_l1(param_2,0);
  fVar4 = (fVar4 - fVar8) * (fVar4 - fVar8);
  dVar9 = (double)_118;
  dVar7 = (double)CONCAT44((fVar2 - fVar6) * (fVar2 - fVar6) + (fVar1 - fVar5) * (fVar1 - fVar5) +
                           fVar4,fVar4);
  if ((double)(float)(dVar9 - dVar9) != dVar7) {
    dVar3 = 1.0 / SQRT(dVar7);
    dVar7 = (double)(float)(dVar7 * (double)(-(float)((double)(float)(dVar3 * dVar3) * dVar7 -
                                                     (double)_119) * (float)(dVar3 * dVar9)));
  }
  return (float)dVar7;
}

