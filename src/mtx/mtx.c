#include <mtx/mtx.h>
#include <MSL_C.PPCEABI.bare.H/math_ppc.h>
#include <mtx/mtx.h>
#include <mtx/vec.h>


namespace mtx {

void PSMTXIdentity(MTX34 *param_1)

{
  float *pfVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  pfVar1 = param_1->m + 2;
  uVar2 = (undefined4)((ulonglong)(double)_97 >> 0x20);
  __psq_st0(pfVar1,uVar2,0);
  uVar3 = SUB84((double)_97,0);
  __psq_st1(pfVar1,uVar3,0);
  uVar4 = SUB84((double)_96,0);
  pfVar1 = param_1->m[1] + 2;
  __psq_st0(pfVar1,uVar2,0);
  __psq_st1(pfVar1,uVar3,0);
  __psq_st0(param_1->m[2],uVar2,0);
  __psq_st1(param_1->m[2],uVar3,0);
  __psq_st0(param_1->m[1],uVar2,0);
  __psq_st1(param_1->m[1],uVar4,0);
  __psq_st0(param_1,uVar4,0);
  __psq_st1(param_1,uVar2,0);
  pfVar1 = param_1->m[2] + 2;
  __psq_st0(pfVar1,uVar4,0);
  __psq_st1(pfVar1,uVar2,0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8030d0c8) */
/* WARNING: Removing unreachable block (ram,0x8030d0d0) */
/* WARNING: Removing unreachable block (ram,0x8030d0d8) */
/* WARNING: Removing unreachable block (ram,0x8030d0e0) */
/* WARNING: Removing unreachable block (ram,0x8030d0e8) */
/* WARNING: Removing unreachable block (ram,0x8030d0f0) */

void PSMTXCopy(MTX34 *param_1,MTX34 *param_2)

{
  float *pfVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = __psq_l0(param_1,0);
  uVar3 = __psq_l1(param_1,0);
  __psq_st0(param_2,uVar2,0);
  __psq_st1(param_2,uVar3,0);
  pfVar1 = param_1->m + 2;
  uVar2 = __psq_l0(pfVar1,0);
  uVar3 = __psq_l1(pfVar1,0);
  pfVar1 = param_2->m + 2;
  __psq_st0(pfVar1,uVar2,0);
  __psq_st1(pfVar1,uVar3,0);
  uVar2 = __psq_l0(param_1->m[1],0);
  uVar3 = __psq_l1(param_1->m[1],0);
  __psq_st0(param_2->m[1],uVar2,0);
  __psq_st1(param_2->m[1],uVar3,0);
  pfVar1 = param_1->m[1] + 2;
  uVar2 = __psq_l0(pfVar1,0);
  uVar3 = __psq_l1(pfVar1,0);
  pfVar1 = param_2->m[1] + 2;
  __psq_st0(pfVar1,uVar2,0);
  __psq_st1(pfVar1,uVar3,0);
  uVar2 = __psq_l0(param_1->m[2],0);
  uVar3 = __psq_l1(param_1->m[2],0);
  __psq_st0(param_2->m[2],uVar2,0);
  __psq_st1(param_2->m[2],uVar3,0);
  pfVar1 = param_1->m[2] + 2;
  uVar2 = __psq_l0(pfVar1,0);
  uVar3 = __psq_l1(pfVar1,0);
  pfVar1 = param_2->m[2] + 2;
  __psq_st0(pfVar1,uVar2,0);
  __psq_st1(pfVar1,uVar3,0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8030d160) */
/* WARNING: Removing unreachable block (ram,0x8030d150) */
/* WARNING: Removing unreachable block (ram,0x8030d140) */
/* WARNING: Removing unreachable block (ram,0x8030d130) */
/* WARNING: Removing unreachable block (ram,0x8030d120) */
/* WARNING: Removing unreachable block (ram,0x8030d108) */
/* WARNING: Removing unreachable block (ram,0x8030d100) */
/* WARNING: Removing unreachable block (ram,0x8030d110) */
/* WARNING: Removing unreachable block (ram,0x8030d128) */
/* WARNING: Removing unreachable block (ram,0x8030d138) */
/* WARNING: Removing unreachable block (ram,0x8030d148) */
/* WARNING: Removing unreachable block (ram,0x8030d158) */
/* WARNING: Removing unreachable block (ram,0x8030d164) */

void PSMTXConcat(MTX34 *param_1,MTX34 *param_2,MTX34 *param_3)

{
  float *pfVar1;
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
  
  fVar2 = (float)__psq_l0(param_1,0);
  fVar3 = (float)__psq_l1(param_1,0);
  fVar14 = (float)__psq_l0(param_2,0);
  fVar15 = (float)__psq_l1(param_2,0);
  pfVar1 = param_2->m + 2;
  fVar16 = (float)__psq_l0(pfVar1,0);
  fVar17 = (float)__psq_l1(pfVar1,0);
  fVar18 = (float)__psq_l0(param_2->m[1],0);
  fVar19 = (float)__psq_l1(param_2->m[1],0);
  fVar6 = (float)__psq_l0(param_1->m[1],0);
  fVar7 = (float)__psq_l1(param_1->m[1],0);
  fVar26 = (float)__psq_l0(0x803f66f0,0);
  fVar27 = (float)__psq_l1(0x803f66f0,0);
  pfVar1 = param_2->m[1] + 2;
  fVar20 = (float)__psq_l0(pfVar1,0);
  fVar21 = (float)__psq_l1(pfVar1,0);
  pfVar1 = param_1->m + 2;
  fVar4 = (float)__psq_l0(pfVar1,0);
  fVar5 = (float)__psq_l1(pfVar1,0);
  pfVar1 = param_1->m[1] + 2;
  fVar8 = (float)__psq_l0(pfVar1,0);
  fVar9 = (float)__psq_l1(pfVar1,0);
  fVar22 = (float)__psq_l0(param_2->m[2],0);
  fVar23 = (float)__psq_l1(param_2->m[2],0);
  pfVar1 = param_2->m[2] + 2;
  fVar24 = (float)__psq_l0(pfVar1,0);
  fVar25 = (float)__psq_l1(pfVar1,0);
  fVar10 = (float)__psq_l0(param_1->m[2],0);
  fVar11 = (float)__psq_l1(param_1->m[2],0);
  pfVar1 = param_1->m[2] + 2;
  fVar12 = (float)__psq_l0(pfVar1,0);
  fVar13 = (float)__psq_l1(pfVar1,0);
  __psq_st0(param_3,fVar22 * fVar4 + fVar18 * fVar3 + fVar14 * fVar2,0);
  __psq_st1(param_3,fVar23 * fVar4 + fVar19 * fVar3 + fVar15 * fVar2,0);
  __psq_st0(param_3->m[1],fVar22 * fVar8 + fVar18 * fVar7 + fVar14 * fVar6,0);
  __psq_st1(param_3->m[1],fVar23 * fVar8 + fVar19 * fVar7 + fVar15 * fVar6,0);
  pfVar1 = param_3->m + 2;
  __psq_st0(pfVar1,fVar26 * fVar5 + fVar24 * fVar4 + fVar20 * fVar3 + fVar16 * fVar2,0);
  __psq_st1(pfVar1,fVar27 * fVar5 + fVar25 * fVar4 + fVar21 * fVar3 + fVar17 * fVar2,0);
  pfVar1 = param_3->m[1] + 2;
  __psq_st0(pfVar1,fVar26 * fVar9 + fVar24 * fVar8 + fVar20 * fVar7 + fVar16 * fVar6,0);
  __psq_st1(pfVar1,fVar27 * fVar9 + fVar25 * fVar8 + fVar21 * fVar7 + fVar17 * fVar6,0);
  __psq_st0(param_3->m[2],fVar22 * fVar12 + fVar18 * fVar11 + fVar14 * fVar10,0);
  __psq_st1(param_3->m[2],fVar23 * fVar12 + fVar19 * fVar11 + fVar15 * fVar10,0);
  pfVar1 = param_3->m[2] + 2;
  __psq_st0(pfVar1,fVar26 * fVar13 + fVar24 * fVar12 + fVar20 * fVar11 + fVar16 * fVar10,0);
  __psq_st1(pfVar1,fVar27 * fVar13 + fVar25 * fVar12 + fVar21 * fVar11 + fVar17 * fVar10,0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8030d29c) */
/* WARNING: Removing unreachable block (ram,0x8030d288) */
/* WARNING: Removing unreachable block (ram,0x8030d1dc) */
/* WARNING: Removing unreachable block (ram,0x8030d1d0) */
/* WARNING: Removing unreachable block (ram,0x8030d1c8) */
/* WARNING: Removing unreachable block (ram,0x8030d1cc) */
/* WARNING: Removing unreachable block (ram,0x8030d1d8) */
/* WARNING: Removing unreachable block (ram,0x8030d1e4) */
/* WARNING: Removing unreachable block (ram,0x8030d290) */
/* WARNING: Removing unreachable block (ram,0x8030d2b8) */

undefined4 PSMTXInverse(int param_1,int param_2)

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
  
  fVar1 = (float)__psq_l0(param_1,0);
  fVar2 = (float)__psq_l0(param_1 + 4,0);
  fVar3 = (float)__psq_l1(param_1 + 4,0);
  fVar4 = (float)__psq_l0(param_1 + 0x10,0);
  fVar5 = (float)__psq_l0(param_1 + 0x14,0);
  fVar6 = (float)__psq_l1(param_1 + 0x14,0);
  fVar7 = (float)__psq_l0(param_1 + 0x20,0);
  fVar8 = (float)__psq_l0(param_1 + 0x24,0);
  fVar9 = (float)__psq_l1(param_1 + 0x24,0);
  fVar11 = fVar2 * fVar6 - fVar5 * fVar3;
  fVar12 = fVar3 * fVar4 - fVar6 * fVar1;
  fVar14 = fVar5 * fVar9 - fVar8 * fVar6;
  fVar15 = fVar6 * fVar7 - fVar9 * fVar4;
  fVar13 = fVar8 * fVar3 - fVar2 * fVar9;
  fVar9 = fVar9 * fVar1 - fVar3 * fVar7;
  fVar6 = fVar7 * fVar11 + fVar4 * fVar13 + fVar1 * fVar14;
  if (fVar6 != fVar3 - fVar3) {
    fVar3 = (float)((ulonglong)
                    (double)(float)(1.0 / (double)CONCAT44(fVar6,fVar12 * 1.0 +
                                                                 fVar9 * 1.0 + fVar15 * 1.0)) >>
                   0x20);
    fVar3 = -(fVar6 * fVar3 * fVar3 - (fVar3 + fVar3));
    fVar14 = fVar14 * fVar3;
    fVar15 = fVar15 * fVar3;
    fVar13 = fVar13 * fVar3;
    fVar9 = fVar9 * fVar3;
    fVar11 = fVar11 * fVar3;
    fVar12 = fVar12 * fVar3;
    fVar10 = (fVar4 * fVar8 - fVar5 * fVar7) * fVar3;
    fVar7 = (fVar2 * fVar7 - fVar1 * fVar8) * fVar3;
    __psq_st0(param_2,fVar14,0);
    __psq_st1(param_2,fVar13,0);
    fVar6 = (float)((ulonglong)(double)*(float *)(param_1 + 0xc) >> 0x20);
    __psq_st0(param_2 + 0x10,fVar15,0);
    __psq_st1(param_2 + 0x10,fVar9,0);
    fVar3 = (fVar1 * fVar5 - fVar2 * fVar4) * fVar3;
    fVar1 = (float)((ulonglong)(double)*(float *)(param_1 + 0x1c) >> 0x20);
    __psq_st0(param_2 + 0x20,fVar10,0);
    fVar2 = (float)((ulonglong)(double)*(float *)(param_1 + 0x2c) >> 0x20);
    __psq_st0(param_2 + 0x24,fVar7,0);
    __psq_st0(param_2 + 0x28,fVar3,0);
    __psq_st0(param_2 + 8,fVar11,0);
    __psq_st1(param_2 + 8,-(fVar11 * fVar2 + fVar13 * fVar1 + fVar14 * fVar6),0);
    __psq_st0(param_2 + 0x18,fVar12,0);
    __psq_st1(param_2 + 0x18,
              -(fVar12 * SUB84((double)*(float *)(param_1 + 0x2c),0) +
               fVar9 * SUB84((double)*(float *)(param_1 + 0x1c),0) +
               fVar15 * SUB84((double)*(float *)(param_1 + 0xc),0)),0);
    __psq_st0(param_2 + 0x2c,-(fVar3 * fVar2 + fVar7 * fVar1 + fVar10 * fVar6),0);
    return 1;
  }
  return 0;
}


void PSMTXRotRad(MTX34 *param_1,char param_2,float param_3)

{
  undefined3 in_register_00000010;
  double dVar1;
  double dVar2;
  float fVar3;
  
  dVar1 = (double)param_3;
  fVar3 = MSL_C.PPCEABI.bare.H::sinf(param_3);
  dVar2 = (double)fVar3;
  fVar3 = MSL_C.PPCEABI.bare.H::cosf((float)dVar1);
  PSMTXRotTrig(dVar2,(double)fVar3,param_1,CONCAT31(in_register_00000010,param_2));
  return;
}


/* WARNING: Removing unreachable block (ram,0x8030d364) */
/* WARNING: Removing unreachable block (ram,0x8030d37c) */

double PSMTXRotTrig(double param_1,double param_2,int param_3,uint param_4)

{
  uint uVar1;
  double dVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  double dVar5;
  float fVar6;
  undefined4 uVar7;
  float fVar8;
  
  dVar2 = (double)_97;
  dVar5 = (double)_96;
  param_4 = param_4 | 0x20;
  fVar8 = (float)((ulonglong)(double)(float)param_1 >> 0x20);
  fVar6 = -fVar8;
  uVar4 = (undefined4)((ulonglong)dVar5 >> 0x20);
  uVar3 = SUB84(dVar2,0);
  uVar1 = (uint)((ulonglong)dVar2 >> 0x20);
  uVar7 = (undefined4)((ulonglong)(double)(float)param_2 >> 0x20);
  if (param_4 == 0x78) {
    __psq_st0(param_3,uVar4,0);
    __psq_st0(param_3 + 4,uVar1,0);
    __psq_st1(param_3 + 4,uVar3,0);
    __psq_st0(param_3 + 0xc,uVar1,0);
    __psq_st1(param_3 + 0xc,uVar3,0);
    dVar5 = (double)((ulonglong)(double)(float)param_2 & 0xffffffff00000000 | (ulonglong)(uint)fVar6
                    );
    __psq_st0(param_3 + 0x1c,uVar1,0);
    __psq_st1(param_3 + 0x1c,uVar3,0);
    __psq_st0(param_3 + 0x2c,uVar1,0);
    __psq_st0(param_3 + 0x24,fVar8,0);
    __psq_st1(param_3 + 0x24,uVar7,0);
    __psq_st0(param_3 + 0x14,uVar7,0);
    __psq_st1(param_3 + 0x14,fVar6,0);
  }
  else {
    if (param_4 == 0x79) {
      dVar5 = (double)((ulonglong)dVar2 & 0xffffffff00000000 | (ulonglong)uVar1);
      __psq_st0(param_3 + 0x18,uVar1,0);
      __psq_st1(param_3 + 0x18,uVar3,0);
      __psq_st0(param_3,uVar7,0);
      __psq_st1(param_3,uVar1,0);
      __psq_st0(param_3 + 0x28,uVar7,0);
      __psq_st1(param_3 + 0x28,uVar1,0);
      __psq_st0(param_3 + 0x10,(int)(((ulonglong)dVar2 & 0xffffffff00000000) >> 0x20),0);
      __psq_st1(param_3 + 0x10,uVar1,0);
      __psq_st0(param_3 + 8,fVar8,0);
      __psq_st1(param_3 + 8,fVar8,0);
      __psq_st0(param_3 + 0x20,fVar6,0);
      __psq_st1(param_3 + 0x20,uVar1,0);
    }
    else {
      if (param_4 == 0x7a) {
        __psq_st0(param_3 + 8,uVar1,0);
        __psq_st1(param_3 + 8,uVar3,0);
        __psq_st0(param_3 + 0x18,uVar1,0);
        __psq_st1(param_3 + 0x18,uVar3,0);
        __psq_st0(param_3 + 0x20,uVar1,0);
        __psq_st1(param_3 + 0x20,uVar3,0);
        dVar5 = (double)((ulonglong)dVar5 & 0xffffffff00000000 | (ulonglong)uVar1);
        __psq_st0(param_3 + 0x10,fVar8,0);
        __psq_st1(param_3 + 0x10,uVar7,0);
        __psq_st0(param_3,uVar7,0);
        __psq_st1(param_3,uVar7,0);
        __psq_st0(param_3 + 0x28,uVar4,0);
        __psq_st1(param_3 + 0x28,uVar1,0);
      }
    }
  }
  return dVar5;
}


void C_MTXRotAxisRad(double param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  float fVar10;
  float local_30;
  float local_2c;
  float local_28;
  
  fVar10 = MSL_C.PPCEABI.bare.H::sinf((float)param_1);
  dVar4 = (double)fVar10;
  fVar10 = MSL_C.PPCEABI.bare.H::cosf((float)param_1);
  dVar5 = (double)fVar10;
  dVar9 = (double)(float)((double)_96 - dVar5);
  C_VECNormalize(param_3,&local_30);
  dVar7 = (double)local_30;
  dVar6 = (double)local_2c;
  dVar8 = (double)local_28;
  fVar10 = (float)(dVar6 * (double)(float)(dVar9 * dVar7));
  fVar1 = (float)(dVar8 * (double)(float)(dVar9 * dVar7));
  *param_2 = (float)(dVar5 + (double)(float)(dVar9 * (double)(float)(dVar7 * dVar7)));
  param_2[1] = fVar10 - (float)(dVar4 * dVar8);
  param_2[2] = fVar1 + (float)(dVar4 * dVar6);
  fVar3 = _97;
  fVar2 = (float)(dVar8 * (double)(float)(dVar9 * dVar6));
  param_2[3] = _97;
  param_2[4] = fVar10 + (float)(dVar4 * dVar8);
  param_2[5] = (float)(dVar5 + (double)(float)(dVar9 * (double)(float)(dVar6 * dVar6)));
  param_2[6] = fVar2 - (float)(dVar4 * dVar7);
  param_2[7] = fVar3;
  param_2[8] = fVar1 - (float)(dVar4 * dVar6);
  param_2[9] = fVar2 + (float)(dVar4 * dVar7);
  param_2[10] = (float)(dVar5 + (double)(float)(dVar9 * (double)(float)(dVar8 * dVar8)));
  param_2[0xb] = fVar3;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8030d504) */

double __PSMTXRotAxisRadInternal(double param_1,double param_2,int param_3,int param_4)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  double dVar10;
  float fVar11;
  double dVar12;
  float fVar13;
  double dVar14;
  
  dVar12 = (double)_190;
  fVar3 = (float)__psq_l0(param_4,0);
  fVar4 = (float)__psq_l1(param_4,0);
  dVar14 = (double)(float)param_1;
  dVar6 = (double)*(float *)(param_4 + 8);
  fVar5 = (float)((ulonglong)dVar6 >> 0x20);
  fVar8 = fVar5 * fVar5 + fVar3 * fVar3 + fVar4 * fVar4;
  dVar10 = 1.0 / SQRT((double)((ulonglong)dVar6 & 0xffffffff | (ulonglong)(uint)fVar8 << 0x20));
  fVar1 = (float)((ulonglong)(double)(float)param_2 >> 0x20);
  fVar8 = (float)((ulonglong)
                  (double)(-(float)((double)(float)(dVar10 * dVar10) *
                                    (double)((ulonglong)dVar6 & 0xffffffff |
                                            (ulonglong)(uint)fVar8 << 0x20) - (double)_191) *
                          (float)(dVar10 * dVar12)) >> 0x20);
  fVar3 = fVar3 * fVar8;
  fVar4 = fVar4 * fVar8;
  fVar5 = fVar5 * fVar8;
  dVar6 = (double)CONCAT44(fVar5,SUB84(dVar6,0) * fVar8);
  fVar8 = (float)((ulonglong)
                  (double)(float)((double)(float)(dVar12 + dVar12) - (double)(float)param_2) >> 0x20
                 );
  fVar9 = fVar3 * fVar8;
  fVar13 = (float)((ulonglong)dVar14 >> 0x20);
  fVar11 = fVar3 * fVar13;
  fVar13 = fVar4 * fVar13;
  fVar7 = fVar4 * fVar8 * fVar4;
  dVar10 = (double)CONCAT44(fVar9 * fVar4,fVar7);
  fVar4 = fVar4 * fVar8 * fVar5;
  uVar2 = SUB84((double)(float)(dVar12 - dVar12),0);
  __psq_st0(param_3 + 8,fVar9 * fVar5 + fVar13,0);
  __psq_st1(param_3 + 8,uVar2,0);
  __psq_st0(param_3,fVar9 * fVar3 + fVar1,0);
  __psq_st1(param_3,SUB84(-(double)(float)(dVar6 * dVar14 - dVar10),0),0);
  __psq_st0(param_3 + 0x10,(int)((ulonglong)(double)(float)(dVar6 * dVar14 + dVar10) >> 0x20),0);
  __psq_st1(param_3 + 0x10,fVar1 + fVar7,0);
  __psq_st0(param_3 + 0x18,-fVar11 + fVar4,0);
  __psq_st1(param_3 + 0x18,uVar2,0);
  __psq_st0(param_3 + 0x20,fVar9 * fVar5 + -fVar13,0);
  __psq_st1(param_3 + 0x20,fVar11 + fVar4,0);
  __psq_st0(param_3 + 0x28,fVar5 * fVar8 * fVar5 + fVar1,0);
  __psq_st1(param_3 + 0x28,uVar2,0);
  return (double)(float)(dVar12 - dVar12);
}


void PSMTXRotAxisRad(double param_1,undefined4 param_2,undefined4 param_3)

{
  double dVar1;
  float fVar2;
  
  fVar2 = MSL_C.PPCEABI.bare.H::sinf((float)param_1);
  dVar1 = (double)fVar2;
  fVar2 = MSL_C.PPCEABI.bare.H::cosf((float)param_1);
  __PSMTXRotAxisRadInternal(dVar1,(double)fVar2,param_2,param_3);
  return;
}


void PSMTXTrans(double param_1,double param_2,double param_3,MTX34 *param_4)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  double dVar5;
  undefined4 uVar6;
  
  fVar3 = _97;
  fVar2 = _96;
  dVar5 = (double)_97;
  param_4->m[3] = (float)param_1;
  param_4->m[1][3] = (float)param_2;
  pfVar1 = param_4->m + 1;
  uVar4 = (undefined4)((ulonglong)dVar5 >> 0x20);
  __psq_st0(pfVar1,uVar4,0);
  uVar6 = SUB84(dVar5,0);
  __psq_st1(pfVar1,uVar6,0);
  __psq_st0(param_4->m[2],uVar4,0);
  __psq_st1(param_4->m[2],uVar6,0);
  param_4->m[1][0] = fVar3;
  param_4->m[1][1] = fVar2;
  param_4->m[1][2] = fVar3;
  param_4->m[2][2] = fVar2;
  param_4->m[2][3] = (float)param_3;
  param_4->m[0] = fVar2;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8030d670) */
/* WARNING: Removing unreachable block (ram,0x8030d664) */
/* WARNING: Removing unreachable block (ram,0x8030d65c) */
/* WARNING: Removing unreachable block (ram,0x8030d64c) */
/* WARNING: Removing unreachable block (ram,0x8030d654) */
/* WARNING: Removing unreachable block (ram,0x8030d67c) */

double PSMTXTransApply(double param_1,double param_2,double param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  undefined4 uVar7;
  float fVar8;
  undefined4 uVar9;
  
  uVar1 = __psq_l0(param_4,0);
  uVar2 = __psq_l1(param_4,0);
  uVar3 = __psq_l0(param_4 + 8,0);
  fVar4 = (float)__psq_l1(param_4 + 8,0);
  uVar5 = __psq_l0(param_4 + 0x18,0);
  fVar6 = (float)__psq_l1(param_4 + 0x18,0);
  uVar7 = __psq_l0(param_4 + 0x28,0);
  fVar8 = (float)__psq_l1(param_4 + 0x28,0);
  __psq_st0(param_5,uVar1,0);
  __psq_st1(param_5,uVar2,0);
  uVar1 = __psq_l0(param_4 + 0x10,0);
  uVar2 = __psq_l1(param_4 + 0x10,0);
  __psq_st0(param_5 + 8,uVar3,0);
  __psq_st1(param_5 + 8,(float)((ulonglong)(double)(float)param_1 >> 0x20) + fVar4,0);
  uVar3 = __psq_l0(param_4 + 0x20,0);
  uVar9 = __psq_l1(param_4 + 0x20,0);
  __psq_st0(param_5 + 0x10,uVar1,0);
  __psq_st1(param_5 + 0x10,uVar2,0);
  __psq_st0(param_5 + 0x18,uVar5,0);
  __psq_st1(param_5 + 0x18,(float)((ulonglong)(double)(float)param_2 >> 0x20) + fVar6,0);
  __psq_st0(param_5 + 0x20,uVar3,0);
  __psq_st1(param_5 + 0x20,uVar9,0);
  __psq_st0(param_5 + 0x28,uVar7,0);
  __psq_st1(param_5 + 0x28,(float)((ulonglong)(double)(float)param_3 >> 0x20) + fVar8,0);
  return (double)(float)param_1;
}


void PSMTXScale(double param_1,double param_2,double param_3,MTX34 *param_4)

{
  float *pfVar1;
  float fVar2;
  undefined4 uVar3;
  double dVar4;
  undefined4 uVar5;
  
  fVar2 = _97;
  dVar4 = (double)_97;
  param_4->m[0] = (float)param_1;
  pfVar1 = param_4->m + 1;
  uVar3 = (undefined4)((ulonglong)dVar4 >> 0x20);
  __psq_st0(pfVar1,uVar3,0);
  uVar5 = SUB84(dVar4,0);
  __psq_st1(pfVar1,uVar5,0);
  pfVar1 = param_4->m + 3;
  __psq_st0(pfVar1,uVar3,0);
  __psq_st1(pfVar1,uVar5,0);
  param_4->m[1][1] = (float)param_2;
  pfVar1 = param_4->m[1] + 2;
  __psq_st0(pfVar1,uVar3,0);
  __psq_st1(pfVar1,uVar5,0);
  __psq_st0(param_4->m[2],uVar3,0);
  __psq_st1(param_4->m[2],uVar5,0);
  param_4->m[2][2] = (float)param_3;
  param_4->m[2][3] = fVar2;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8030d728) */
/* WARNING: Removing unreachable block (ram,0x8030d710) */
/* WARNING: Removing unreachable block (ram,0x8030d6c4) */
/* WARNING: Removing unreachable block (ram,0x8030d6c8) */
/* WARNING: Removing unreachable block (ram,0x8030d71c) */
/* WARNING: Removing unreachable block (ram,0x8030d74c) */

double PSMTXQuat(int param_1,int param_2)

{
  undefined4 uVar1;
  double dVar2;
  float fVar3;
  double dVar4;
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
  double dVar16;
  
  dVar2 = (double)_96;
  fVar7 = (float)__psq_l0(param_2,0);
  fVar8 = (float)__psq_l1(param_2,0);
  fVar9 = (float)__psq_l0(param_2 + 8,0);
  fVar10 = (float)__psq_l1(param_2 + 8,0);
  dVar4 = (double)(float)(dVar2 + dVar2);
  fVar11 = fVar8 * fVar8;
  fVar12 = fVar9 * fVar9 + fVar7 * fVar7;
  fVar13 = fVar10 * fVar10 + fVar11;
  fVar5 = fVar12 + fVar13;
  dVar16 = (double)(float)(1.0 / (double)CONCAT44(fVar5,fVar13));
  fVar6 = (float)((ulonglong)dVar16 >> 0x20);
  fVar3 = (float)((ulonglong)dVar4 >> 0x20);
  fVar14 = SUB84(dVar16,0);
  dVar16 = (double)(float)((double)CONCAT44(fVar6 * -(fVar5 * fVar6 - fVar3),
                                            fVar14 * -(fVar13 * fVar14 - SUB84(dVar4,0))) * dVar4);
  uVar1 = (undefined4)((ulonglong)(double)(float)(dVar2 - dVar2) >> 0x20);
  __psq_st0(param_1 + 0xc,uVar1,0);
  fVar13 = (float)((ulonglong)dVar16 >> 0x20);
  fVar5 = (float)((ulonglong)dVar2 >> 0x20);
  fVar6 = SUB84(dVar16,0);
  __psq_st0(param_1 + 0x2c,uVar1,0);
  __psq_st0(param_1 + 0x28,-((fVar7 * fVar7 + fVar11) * fVar13 - fVar5),0);
  fVar14 = fVar7 * fVar9 + fVar8 * fVar10;
  fVar15 = fVar8 * fVar9 + fVar7 * fVar10;
  __psq_st0(param_1 + 0x10,(fVar7 * fVar8 + fVar9 * fVar10) * fVar13,0);
  __psq_st1(param_1 + 0x10,-(fVar12 * fVar13 - fVar5),0);
  __psq_st0(param_1,-((fVar9 * fVar9 + fVar11) * fVar6 - SUB84(dVar2,0)),0);
  __psq_st1(param_1,(fVar7 * fVar8 - fVar9 * fVar10) * fVar13,0);
  __psq_st0(param_1 + 8,fVar14 * fVar13,0);
  __psq_st0(param_1 + 0x18,-(fVar7 * fVar10 * SUB84(dVar4,0) - fVar15) * fVar6,0);
  __psq_st1(param_1 + 0x18,uVar1,0);
  __psq_st0(param_1 + 0x20,-(fVar8 * fVar10 * fVar3 - fVar14) * fVar13,0);
  __psq_st1(param_1 + 0x20,fVar15 * fVar6,0);
  return dVar2;
}


void C_MTXLookAt(float *param_1,float *param_2,TVec3_float_ *param_3,float *param_4)

{
  TVec3_float_ local_38;
  TVec3_float_ local_2c;
  TVec3_float_ local_20;
  
  local_20.x = *param_2 - *param_4;
  local_20.y = param_2[1] - param_4[1];
  local_20.z = param_2[2] - param_4[2];
  PSVECNormalize(&local_20,&local_20);
  PSVECCrossProduct(param_3,&local_20,&local_2c);
  PSVECNormalize(&local_2c,&local_2c);
  PSVECCrossProduct(&local_20,&local_2c,&local_38);
  *param_1 = local_2c.x;
  param_1[1] = local_2c.y;
  param_1[2] = local_2c.z;
  param_1[3] = -(param_2[2] * local_2c.z + *param_2 * local_2c.x + param_2[1] * local_2c.y);
  param_1[4] = local_38.x;
  param_1[5] = local_38.y;
  param_1[6] = local_38.z;
  param_1[7] = -(param_2[2] * local_38.z + *param_2 * local_38.x + param_2[1] * local_38.y);
  param_1[8] = local_20.x;
  param_1[9] = local_20.y;
  param_1[10] = local_20.z;
  param_1[0xb] = -(param_2[2] * local_20.z + *param_2 * local_20.x + param_2[1] * local_20.y);
  return;
}


void C_MTXLightPerspective
               (double param_1,double param_2,double param_3,double param_4,double param_5,
               double param_6,float *param_7)

{
  float fVar1;
  float fVar2;
  
  fVar2 = MSL_C.PPCEABI.bare.H::tanf(_230 * (float)((double)_190 * param_1));
  fVar2 = _96 / fVar2;
  *param_7 = (float)(param_3 * (double)(float)((double)fVar2 / param_2));
  fVar1 = _97;
  param_7[1] = _97;
  param_7[2] = (float)-param_5;
  param_7[3] = fVar1;
  param_7[4] = fVar1;
  param_7[5] = (float)((double)fVar2 * param_4);
  param_7[6] = (float)-param_6;
  param_7[7] = fVar1;
  param_7[8] = fVar1;
  param_7[9] = fVar1;
  param_7[10] = _227;
  param_7[0xb] = fVar1;
  return;
}


void C_MTXLightOrtho
               (float param_1,float param_2,float param_3,float param_4,float param_5,float param_6,
               float param_7,float param_8,MTX34 *param_9)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar5 = _206;
  fVar3 = _96;
  fVar1 = _96 / (param_4 - param_3);
  fVar2 = _96 / (param_1 - param_2);
  param_9->m[0] = _206 * fVar1 * param_5;
  fVar4 = _97;
  param_9->m[1] = _97;
  param_9->m[2] = fVar4;
  param_9->m[3] = param_7 + param_5 * fVar1 * -(param_4 + param_3);
  param_9->m[1][0] = fVar4;
  param_9->m[1][1] = fVar5 * fVar2 * param_6;
  param_9->m[1][2] = fVar4;
  param_9->m[1][3] = param_8 + param_6 * fVar2 * -(param_1 + param_2);
  param_9->m[2][0] = fVar4;
  param_9->m[2][1] = fVar4;
  param_9->m[2][2] = fVar4;
  param_9->m[2][3] = fVar3;
  return;
}

