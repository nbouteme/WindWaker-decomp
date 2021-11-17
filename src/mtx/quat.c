#include <mtx/quat.h>
#include <mtx/vec.h>
#include <MSL_C.PPCEABI.bare.H/math_ppc.h>


namespace mtx {

/* WARNING: Removing unreachable block (ram,0x8030e138) */
/* WARNING: Removing unreachable block (ram,0x8030e130) */
/* WARNING: Removing unreachable block (ram,0x8030e134) */
/* WARNING: Removing unreachable block (ram,0x8030e140) */

undefined8 PSQUATMultiply(int param_1,int param_2,int param_3)

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
  
  fVar1 = (float)__psq_l0(param_1,0);
  fVar2 = (float)__psq_l1(param_1,0);
  fVar3 = (float)__psq_l0(param_1 + 8,0);
  fVar4 = (float)__psq_l1(param_1 + 8,0);
  fVar5 = (float)__psq_l0(param_2,0);
  fVar6 = (float)__psq_l1(param_2,0);
  fVar7 = (float)__psq_l0(param_2 + 8,0);
  fVar8 = (float)__psq_l1(param_2 + 8,0);
  fVar3 = -fVar3;
  fVar9 = fVar2 * fVar7 + fVar4 * fVar5;
  fVar5 = fVar4 * fVar7 + -fVar2 * fVar5;
  __psq_st0(param_3,fVar9 + fVar1 * fVar8 + fVar3 * fVar6,0);
  __psq_st1(param_3,fVar9 + fVar2 * fVar8 + fVar4 * fVar6,0);
  __psq_st0(param_3 + 8,fVar5 - (fVar3 * fVar8 + -fVar1 * fVar6),0);
  __psq_st1(param_3 + 8,fVar5 - (-fVar4 * fVar8 + fVar2 * fVar6),0);
  return CONCAT44(fVar3,fVar4);
}


/* WARNING: Removing unreachable block (ram,0x8030e198) */
/* WARNING: Removing unreachable block (ram,0x8030e1a0) */

undefined8 PSQUATNormalize(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  float fVar8;
  
  fVar1 = (float)__psq_l0(param_1,0);
  fVar2 = (float)__psq_l1(param_1,0);
  fVar3 = (float)__psq_l0(param_1 + 8,0);
  fVar4 = (float)__psq_l1(param_1 + 8,0);
  fVar8 = (float)((ulonglong)(double)_129 >> 0x20);
  fVar6 = fVar4 * fVar4 + fVar2 * fVar2;
  fVar5 = fVar3 * fVar3 + fVar1 * fVar1 + fVar6;
  dVar7 = 1.0 / SQRT((double)CONCAT44(fVar5,fVar6));
  fVar6 = (float)((ulonglong)
                  (-(dVar7 * dVar7 * (double)CONCAT44(fVar5,fVar6) - (double)_136) *
                  dVar7 * (double)_135) >> 0x20);
  if (fVar5 - fVar8 < 0.0) {
    fVar6 = fVar8 - fVar8;
  }
  __psq_st0(param_2,fVar1 * fVar6,0);
  __psq_st1(param_2,fVar2 * fVar6,0);
  __psq_st0(param_2 + 8,fVar3 * fVar6,0);
  __psq_st1(param_2 + 8,fVar4 * fVar6,0);
  return CONCAT44(fVar3 * fVar6,fVar4 * fVar6);
}


/* WARNING: Removing unreachable block (ram,0x8030e224) */
/* WARNING: Removing unreachable block (ram,0x8030e1f0) */
/* WARNING: Removing unreachable block (ram,0x8030e1e4) */
/* WARNING: Removing unreachable block (ram,0x8030e230) */

undefined8 PSQUATInverse(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  double dVar8;
  
  dVar8 = (double)_133;
  fVar1 = (float)__psq_l0(param_1,0);
  fVar2 = (float)__psq_l1(param_1,0);
  fVar7 = (float)((ulonglong)dVar8 >> 0x20);
  fVar3 = (float)__psq_l0(param_1 + 8,0);
  fVar4 = (float)__psq_l1(param_1 + 8,0);
  fVar6 = fVar4 * fVar4 + fVar2 * fVar2;
  fVar5 = fVar3 * fVar3 + fVar1 * fVar1 + fVar6;
  if ((double)CONCAT44(fVar5,fVar6) !=
      (double)CONCAT44(fVar7 - fVar7,SUB84(dVar8,0) - SUB84(dVar8,0))) {
    fVar6 = (float)((ulonglong)(double)(float)(1.0 / (double)CONCAT44(fVar5,fVar6)) >> 0x20);
    dVar8 = (double)((ulonglong)(uint)(fVar6 * -(fVar5 * fVar6 - (fVar7 + fVar7))) << 0x20);
  }
  fVar6 = (float)((ulonglong)dVar8 >> 0x20);
  fVar5 = -fVar6;
  __psq_st0(param_2 + 0xc,fVar6 * fVar4,0);
  __psq_st0(param_2,fVar1 * fVar5,0);
  __psq_st1(param_2,fVar2 * fVar5,0);
  __psq_st0(param_2 + 8,fVar3 * fVar5,0);
  return CONCAT44(fVar3 * fVar5,fVar4 * fVar5);
}


void C_QUATRotAxisRad(double param_1,float *param_2,undefined4 param_3)

{
  double dVar1;
  double dVar2;
  float fVar3;
  float local_24;
  float local_20;
  float local_1c;
  
  PSVECNormalize(param_3,&local_24);
  dVar2 = (double)(float)((double)_135 * param_1);
  fVar3 = MSL_C.PPCEABI.bare.H::sinf((float)((double)_135 * param_1));
  dVar1 = (double)fVar3;
  fVar3 = MSL_C.PPCEABI.bare.H::cosf((float)dVar2);
  *param_2 = (float)(dVar1 * (double)local_24);
  param_2[1] = (float)(dVar1 * (double)local_20);
  param_2[2] = (float)(dVar1 * (double)local_1c);
  param_2[3] = fVar3;
  return;
}


void C_QUATSlerp(double param_1,Quaternion *param_2,Quaternion *param_3,Quaternion *param_4)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  float fVar5;
  
  dVar3 = (double)_133;
  fVar5 = param_2->w * param_3->w +
          param_2->z * param_3->z + param_2->x * param_3->x + param_2->y * param_3->y;
  if (fVar5 < _130) {
    fVar5 = -fVar5;
    dVar3 = -dVar3;
  }
  if (_261 < fVar5) {
    dVar3 = dVar3 * param_1;
    dVar4 = (double)(float)((double)_133 - param_1);
  }
  else {
    fVar5 = MSL_C.PPCEABI.bare.H::acosf(fVar5);
    dVar1 = (double)fVar5;
    fVar5 = MSL_C.PPCEABI.bare.H::sinf(fVar5);
    dVar2 = (double)fVar5;
    fVar5 = MSL_C.PPCEABI.bare.H::sinf((float)((double)(float)((double)_133 - param_1) * dVar1));
    dVar4 = (double)(float)((double)fVar5 / dVar2);
    fVar5 = MSL_C.PPCEABI.bare.H::sinf((float)(param_1 * dVar1));
    dVar3 = dVar3 * (double)(float)((double)fVar5 / dVar2);
  }
  fVar5 = (float)dVar3;
  param_4->x = (float)(dVar4 * (double)param_2->x) + fVar5 * param_3->x;
  param_4->y = (float)(dVar4 * (double)param_2->y) + fVar5 * param_3->y;
  param_4->z = (float)(dVar4 * (double)param_2->z) + fVar5 * param_3->z;
  param_4->w = (float)(dVar4 * (double)param_2->w) + fVar5 * param_3->w;
  return;
}

