#include <JStudio/jstudio-math.h>
#include <MSL_C.PPCEABI.bare.H/s_cos.h>
#include <MSL_C.PPCEABI.bare.H/s_sin.h>
#include <JStudio/jstudio-math.h>
#include <mtx/mtx.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JStudio/math.h>


namespace JStudio {

/* WARNING: Removing unreachable block (ram,0x8026e754) */
/* WARNING: Removing unreachable block (ram,0x8026e744) */
/* WARNING: Removing unreachable block (ram,0x8026e734) */
/* WARNING: Removing unreachable block (ram,0x8026e73c) */
/* WARNING: Removing unreachable block (ram,0x8026e74c) */
/* WARNING: Removing unreachable block (ram,0x8026e75c) */
/* __thiscall math::getRotation_xyz(float *[][][][],
                                             float,
                                             float,
                                             float) */

void __thiscall
math::getRotation_xyz(math *this,float *param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f26;
  undefined8 in_f27;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_4;
  dVar5 = (double)param_3;
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
  dVar4 = (double)(_299 * param_2);
  dVar3 = MSL_C.PPCEABI.bare.H::cos(dVar4);
  dVar9 = (double)(float)dVar3;
  dVar3 = MSL_C.PPCEABI.bare.H::sin(dVar4);
  dVar8 = (double)(float)dVar3;
  dVar5 = (double)(float)((double)_299 * dVar5);
  dVar3 = MSL_C.PPCEABI.bare.H::cos(dVar5);
  dVar7 = (double)(float)dVar3;
  dVar3 = MSL_C.PPCEABI.bare.H::sin(dVar5);
  dVar4 = (double)(float)dVar3;
  dVar5 = (double)(float)((double)_299 * dVar6);
  dVar3 = MSL_C.PPCEABI.bare.H::cos(dVar5);
  dVar6 = (double)(float)dVar3;
  dVar3 = MSL_C.PPCEABI.bare.H::sin(dVar5);
  dVar3 = (double)(float)dVar3;
  *(float *)this = (float)(dVar7 * dVar6);
  *(float *)(this + 0x10) = (float)(dVar7 * dVar3);
  *(float *)(this + 0x20) = (float)-dVar4;
  *(float *)(this + 0x24) = (float)(dVar8 * dVar7);
  *(float *)(this + 0x28) = (float)(dVar9 * dVar7);
  *(float *)(this + 4) =
       (float)((double)(float)((double)(float)(dVar8 * dVar6) * dVar4) -
              (double)(float)(dVar9 * dVar3));
  *(float *)(this + 8) =
       (float)((double)(float)(dVar8 * dVar3) +
              (double)(float)((double)(float)(dVar9 * dVar6) * dVar4));
  *(float *)(this + 0x14) =
       (float)((double)(float)(dVar9 * dVar6) +
              (double)(float)((double)(float)(dVar8 * dVar3) * dVar4));
  *(float *)(this + 0x18) =
       (float)((double)(float)((double)(float)(dVar9 * dVar3) * dVar4) -
              (double)(float)(dVar8 * dVar6));
  fVar1 = _300;
  *(float *)(this + 0xc) = _300;
  *(float *)(this + 0x1c) = fVar1;
  *(float *)(this + 0x2c) = fVar1;
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
  return;
}


/* __thiscall math::rotate_xyz(float *[][][][],
                                        float const *[][][][],
                                        float,
                                        float,
                                        float) */

void __thiscall
math::rotate_xyz
          (math *this,float *param_1,float *param_2,float param_3,float param_4,float param_5)

{
  MTX34 MStack56;
  
  getRotation_xyz((math *)&MStack56,param_1,param_3,param_4,param_5);
  mtx::PSMTXConcat(&MStack56,(MTX34 *)param_1,(MTX34 *)this);
  return;
}


namespace math {

/* __thiscall rotate_y(float *[][][][],
                                      float const *[][][][],
                                      float) */

void rotate_y(MTX34 *param_1,MTX34 *param_2,float param_3)

{
  MTX34 MStack56;
  
  mtx::PSMTXRotRad(&MStack56,'y',_299 * param_3);
  mtx::PSMTXConcat(&MStack56,param_2,param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall math::getTransformation_SRxyzT(float *[][][][],
                                                      Vec const &,
                                                      Vec const &,
                                                      Vec const &) */

void __thiscall
math::getTransformation_SRxyzT
          (math *this,float *param_1,Vec *param_2,Vec *param_3,Vec *param_4)

{
  float *pfVar1;
  math amStack120 [48];
  MTX34 MStack72;
  
  pfVar1 = (float *)param_2;
  mtx::PSMTXScale((double)*param_1,(double)param_1[1],(double)param_1[2],&MStack72);
  rotate_xyz(amStack120,(float *)&MStack72,pfVar1,*(float *)param_2,*(float *)(param_2 + 4),
             *(float *)(param_2 + 8));
  mtx::PSMTXTransApply
            ((double)*(float *)param_3,(double)*(float *)(param_3 + 4),
             (double)*(float *)(param_3 + 8),amStack120,this);
  return;
}


namespace math {

/* __thiscall getTransformation_RyT(float *[][][][],
                                                   float,
                                                   Vec const &) */

void getTransformation_RyT(float *param_1,float param_2,Vec *param_3)

{
  MTX34 MStack56;
  
  mtx::PSMTXRotRad(&MStack56,'y',_299 * param_2);
  mtx::PSMTXTransApply
            ((double)*(float *)param_3,(double)*(float *)(param_3 + 4),
             (double)*(float *)(param_3 + 8),&MStack56,param_1);
  return;
}

