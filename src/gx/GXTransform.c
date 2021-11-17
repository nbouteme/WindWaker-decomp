#include <gx/GXTransform.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <gx/GXTransform.h>
#include <gx/GXStubs.h>


namespace gx {

void GXProject(double param_1,double param_2,double param_3,float *param_4,float *param_5,
                  float *param_6,float *param_7,float *param_8,float *param_9)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar6 = _28;
  fVar1 = param_4[3] +
          (float)((double)param_4[2] * param_3) +
          (float)((double)*param_4 * param_1) + (float)((double)param_4[1] * param_2);
  fVar2 = param_4[7] +
          (float)((double)param_4[6] * param_3) +
          (float)((double)param_4[4] * param_1) + (float)((double)param_4[5] * param_2);
  fVar3 = param_4[0xb] +
          (float)((double)param_4[10] * param_3) +
          (float)((double)param_4[8] * param_1) + (float)((double)param_4[9] * param_2);
  if (_26 == *param_5) {
    fVar5 = fVar1 * param_5[1] + fVar3 * param_5[2];
    fVar4 = param_5[6] + fVar3 * param_5[5];
    fVar2 = fVar2 * param_5[3] + fVar3 * param_5[4];
    fVar1 = _27 / -fVar3;
  }
  else {
    fVar5 = param_5[2] + fVar1 * param_5[1];
    fVar2 = param_5[4] + fVar2 * param_5[3];
    fVar4 = param_5[6] + fVar3 * param_5[5];
    fVar1 = _27;
  }
  *param_7 = param_6[2] * _28 + *param_6 + fVar1 * fVar5 * param_6[2] * _28;
  *param_8 = param_6[3] * fVar6 + param_6[1] + fVar1 * -fVar2 * param_6[3] * fVar6;
  *param_9 = param_6[5] + fVar1 * fVar4 * (param_6[5] - param_6[4]);
  return;
}


void GXSetProjection(MTX44 *param_1,GXProjectionType param_2)

{
  int iVar1;
  
  iVar1 = gx;
  *(GXProjectionType *)(gx + 0x420) = param_2;
  *(float *)(iVar1 + 0x424) = param_1->m[0];
  *(float *)(iVar1 + 0x42c) = param_1->m[1][1];
  *(float *)(iVar1 + 0x434) = param_1->m[2][2];
  *(float *)(iVar1 + 0x438) = param_1->m[2][3];
  if (param_2 == GX_ORTHOGRAPHIC) {
    *(float *)(iVar1 + 0x428) = param_1->m[3];
    *(float *)(iVar1 + 0x430) = param_1->m[1][3];
  }
  else {
    *(float *)(iVar1 + 0x428) = param_1->m[2];
    *(float *)(iVar1 + 0x430) = param_1->m[1][2];
  }
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,0x61020);
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x424));
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x428));
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x42c));
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x430));
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x434));
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x438));
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x420));
  *(undefined2 *)(gx + 2) = 1;
  return;
}


void GXSetProjectionv(float *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)*param_1);
  iVar1 = gx;
  *(undefined4 *)(gx + 0x420) = uVar2;
  *(float *)(iVar1 + 0x424) = param_1[1];
  *(float *)(iVar1 + 0x428) = param_1[2];
  *(float *)(iVar1 + 0x42c) = param_1[3];
  *(float *)(iVar1 + 0x430) = param_1[4];
  *(float *)(iVar1 + 0x434) = param_1[5];
  *(float *)(iVar1 + 0x438) = param_1[6];
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,0x61020);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x424));
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x428));
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x42c));
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x430));
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x434));
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x438));
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x420));
  *(undefined2 *)(iVar1 + 2) = 1;
  return;
}


void GXGetProjectionv(float *param_1)

{
  int iVar1;
  
  iVar1 = gx;
  *param_1 = (float)((double)CONCAT44(0x43300000,*(undefined4 *)(gx + 0x420)) - _36);
  param_1[1] = *(float *)(iVar1 + 0x424);
  param_1[2] = *(float *)(iVar1 + 0x428);
  param_1[3] = *(float *)(iVar1 + 0x42c);
  param_1[4] = *(float *)(iVar1 + 0x430);
  param_1[5] = *(float *)(iVar1 + 0x434);
  param_1[6] = *(float *)(iVar1 + 0x438);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80326f64) */
/* WARNING: Removing unreachable block (ram,0x80326f5c) */
/* WARNING: Removing unreachable block (ram,0x80326f54) */
/* WARNING: Removing unreachable block (ram,0x80326f58) */
/* WARNING: Removing unreachable block (ram,0x80326f60) */
/* WARNING: Removing unreachable block (ram,0x80326f68) */

void GXLoadPosMtxImm(MTX34 *param_1,int param_2)

{
  float *pfVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,param_2 << 2 | 0xb0000);
  uVar12 = __psq_l0(param_1,0);
  uVar13 = __psq_l1(param_1,0);
  pfVar1 = param_1->m + 2;
  uVar10 = __psq_l0(pfVar1,0);
  uVar11 = __psq_l1(pfVar1,0);
  uVar8 = __psq_l0(param_1->m[1],0);
  uVar9 = __psq_l1(param_1->m[1],0);
  pfVar1 = param_1->m[1] + 2;
  uVar6 = __psq_l0(pfVar1,0);
  uVar7 = __psq_l1(pfVar1,0);
  uVar4 = __psq_l0(param_1->m[2],0);
  uVar5 = __psq_l1(param_1->m[2],0);
  pfVar1 = param_1->m[2] + 2;
  uVar2 = __psq_l0(pfVar1,0);
  uVar3 = __psq_l1(pfVar1,0);
  __psq_st0(0xcc008000,uVar12,0);
  __psq_st1(0xcc008000,uVar13,0);
  __psq_st0(0xcc008000,uVar10,0);
  __psq_st1(0xcc008000,uVar11,0);
  __psq_st0(0xcc008000,uVar8,0);
  __psq_st1(0xcc008000,uVar9,0);
  __psq_st0(0xcc008000,uVar6,0);
  __psq_st1(0xcc008000,uVar7,0);
  __psq_st0(0xcc008000,uVar4,0);
  __psq_st1(0xcc008000,uVar5,0);
  __psq_st0(0xcc008000,uVar2,0);
  __psq_st1(0xcc008000,uVar3,0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80326fa4) */
/* WARNING: Removing unreachable block (ram,0x80326fac) */
/* WARNING: Removing unreachable block (ram,0x80326fb4) */

undefined8 GXLoadNrmMtxImm(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,param_2 * 3 + 0x400U | 0x80000);
  uVar5 = __psq_l0(param_1,0);
  uVar6 = __psq_l1(param_1,0);
  uVar3 = __psq_l0(param_1 + 0x10,0);
  uVar4 = __psq_l1(param_1 + 0x10,0);
  uVar1 = __psq_l0(param_1 + 0x20,0);
  uVar2 = __psq_l1(param_1 + 0x20,0);
  __psq_st0(0xcc008000,uVar5,0);
  __psq_st1(0xcc008000,uVar6,0);
  write_volatile_4(0xcc008000,*(undefined4 *)(param_1 + 8));
  __psq_st0(0xcc008000,uVar3,0);
  __psq_st1(0xcc008000,uVar4,0);
  write_volatile_4(0xcc008000,*(undefined4 *)(param_1 + 0x18));
  __psq_st0(0xcc008000,uVar1,0);
  __psq_st1(0xcc008000,uVar2,0);
  write_volatile_4(0xcc008000,*(undefined4 *)(param_1 + 0x28));
  return CONCAT44(uVar1,uVar2);
}


void GXSetCurrentMtx(uint param_1)

{
  *(uint *)(gx + 0x80) = *(uint *)(gx + 0x80) & 0xffffffc0 | param_1;
  __GXSetMatrixIndex(0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x803270a8) */
/* WARNING: Removing unreachable block (ram,0x803270a0) */
/* WARNING: Removing unreachable block (ram,0x80327078) */
/* WARNING: Removing unreachable block (ram,0x80327070) */
/* WARNING: Removing unreachable block (ram,0x8032706c) */
/* WARNING: Removing unreachable block (ram,0x80327074) */
/* WARNING: Removing unreachable block (ram,0x8032707c) */
/* WARNING: Removing unreachable block (ram,0x803270a4) */
/* WARNING: Removing unreachable block (ram,0x803270ac) */
/* WARNING: Removing unreachable block (ram,0x80327068) */

undefined8 GXLoadTexMtxImm(int param_1,GXTexMtx param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  
  if (param_2 < 0x40) {
    uVar2 = param_2 << 2;
  }
  else {
    uVar2 = (param_2 + 0xffffffc0) * 4 + 0x500;
  }
  if (param_3 == 1) {
    iVar1 = 8;
  }
  else {
    iVar1 = 0xc;
  }
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,uVar2 | (iVar1 + -1) * 0x10000);
  if (param_3 == 0) {
    uVar13 = __psq_l0(param_1,0);
    uVar14 = __psq_l1(param_1,0);
    uVar11 = __psq_l0(param_1 + 8,0);
    uVar12 = __psq_l1(param_1 + 8,0);
    uVar9 = __psq_l0(param_1 + 0x10,0);
    uVar10 = __psq_l1(param_1 + 0x10,0);
    uVar7 = __psq_l0(param_1 + 0x18,0);
    uVar8 = __psq_l1(param_1 + 0x18,0);
    uVar5 = __psq_l0(param_1 + 0x20,0);
    uVar6 = __psq_l1(param_1 + 0x20,0);
    uVar3 = __psq_l0(param_1 + 0x28,0);
    uVar4 = __psq_l1(param_1 + 0x28,0);
    __psq_st0(0xcc008000,uVar13,0);
    __psq_st1(0xcc008000,uVar14,0);
    __psq_st0(0xcc008000,uVar11,0);
    __psq_st1(0xcc008000,uVar12,0);
    __psq_st0(0xcc008000,uVar9,0);
    __psq_st1(0xcc008000,uVar10,0);
    __psq_st0(0xcc008000,uVar7,0);
    __psq_st1(0xcc008000,uVar8,0);
    __psq_st0(0xcc008000,uVar5,0);
    __psq_st1(0xcc008000,uVar6,0);
    __psq_st0(0xcc008000,uVar3,0);
    __psq_st1(0xcc008000,uVar4,0);
    return CONCAT44(uVar5,uVar6);
  }
  uVar9 = __psq_l0(param_1,0);
  uVar10 = __psq_l1(param_1,0);
  uVar7 = __psq_l0(param_1 + 8,0);
  uVar8 = __psq_l1(param_1 + 8,0);
  uVar5 = __psq_l0(param_1 + 0x10,0);
  uVar6 = __psq_l1(param_1 + 0x10,0);
  uVar3 = __psq_l0(param_1 + 0x18,0);
  uVar4 = __psq_l1(param_1 + 0x18,0);
  __psq_st0(0xcc008000,uVar9,0);
  __psq_st1(0xcc008000,uVar10,0);
  __psq_st0(0xcc008000,uVar7,0);
  __psq_st1(0xcc008000,uVar8,0);
  __psq_st0(0xcc008000,uVar5,0);
  __psq_st1(0xcc008000,uVar6,0);
  __psq_st0(0xcc008000,uVar3,0);
  __psq_st1(0xcc008000,uVar4,0);
  return CONCAT44(uVar5,uVar6);
}


void GXSetViewportJitter
               (double param_1,double param_2,double param_3,double param_4,double param_5,
               double param_6,int param_7)

{
  int iVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  fVar2 = _121;
  iVar1 = gx;
  if (param_7 == 0) {
    param_2 = (double)(float)(param_2 - (double)_28);
  }
  dVar4 = (double)_28;
  dVar3 = (double)_122;
  dVar8 = (double)(float)(param_3 * dVar4);
  *(float *)(gx + 0x43c) = (float)param_1;
  dVar7 = (double)(float)(dVar3 * param_6);
  *(float *)(iVar1 + 0x440) = (float)param_2;
  *(float *)(iVar1 + 0x444) = (float)param_3;
  dVar6 = (double)(float)(-param_4 * dVar4);
  *(float *)(iVar1 + 0x448) = (float)param_4;
  dVar5 = (double)(fVar2 + (float)(param_1 + dVar8));
  *(float *)(iVar1 + 0x44c) = (float)param_5;
  dVar4 = (double)(fVar2 + (float)(param_2 + (double)(float)(param_4 * dVar4)));
  dVar3 = (double)(float)(dVar7 - (double)(float)(dVar3 * param_5));
  *(float *)(iVar1 + 0x450) = (float)param_6;
  if (*(char *)(iVar1 + 0x454) != '\0') {
    __GXSetRange(param_5,(double)*(float *)(iVar1 + 0x458));
  }
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,0x5101a);
  write_volatile_4(0xcc008000,(float)dVar8);
  write_volatile_4(0xcc008000,(float)dVar6);
  write_volatile_4(0xcc008000,(float)dVar3);
  write_volatile_4(0xcc008000,(float)dVar5);
  write_volatile_4(0xcc008000,(float)dVar4);
  write_volatile_4(0xcc008000,(float)dVar7);
  *(undefined2 *)(gx + 2) = 1;
  return;
}


void GXSetViewport(void)

{
  GXSetViewportJitter(1);
  return;
}


void GXGetViewportv(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = gx;
  *param_1 = *(undefined4 *)(gx + 0x43c);
  param_1[1] = *(undefined4 *)(iVar1 + 0x440);
  param_1[2] = *(undefined4 *)(iVar1 + 0x444);
  param_1[3] = *(undefined4 *)(iVar1 + 0x448);
  param_1[4] = *(undefined4 *)(iVar1 + 0x44c);
  param_1[5] = *(undefined4 *)(iVar1 + 0x450);
  return;
}


void GXSetScissor(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 0xf8) = *(uint *)(gx + 0xf8) & 0xfffff800 | param_2 + 0x156U;
  *(uint *)(iVar1 + 0xf8) = *(uint *)(iVar1 + 0xf8) & 0xff800fff | (param_1 + 0x156) * 0x1000;
  *(uint *)(iVar1 + 0xfc) = *(uint *)(iVar1 + 0xfc) & 0xfffff800 | param_2 + 0x156U + param_4 + -1;
  *(uint *)(iVar1 + 0xfc) =
       *(uint *)(iVar1 + 0xfc) & 0xff800fff | (param_1 + 0x156 + param_3 + -1) * 0x1000;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0xf8));
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0xfc));
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXGetScissor(int *param_1,int *param_2,int *param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(gx + 0xf8);
  uVar2 = *(uint *)(gx + 0xfc);
  uVar3 = uVar1 >> 0xc & 0x7ff;
  *param_1 = uVar3 - 0x156;
  uVar1 = uVar1 & 0x7ff;
  *param_2 = uVar1 - 0x156;
  *param_3 = ((uVar2 >> 0xc & 0x7ff) - uVar3) + 1;
  *param_4 = ((uVar2 & 0x7ff) - uVar1) + 1;
  return;
}


void GXSetScissorBoxOffset(int param_1,int param_2)

{
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   (param_1 + 0x156U >> 1 & 0x7ff003ff | (param_2 + 0x156) * 0x200 & 0xfffffc00U) &
                   0xffffff | 0x59000000);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetClipMode(bool param_1)

{
  undefined3 in_register_0000000c;
  
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,0x1005);
  write_volatile_4(0xcc008000,CONCAT31(in_register_0000000c,param_1));
  *(undefined2 *)(gx + 2) = 1;
  return;
}


void __GXSetMatrixIndex(int param_1)

{
  if (param_1 < 5) {
    write_volatile_1(DAT_cc008000,8);
    write_volatile_1(DAT_cc008000,0x30);
    write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x80));
    write_volatile_1(DAT_cc008000,0x10);
    write_volatile_4(0xcc008000,0x1018);
    write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x80));
  }
  else {
    write_volatile_1(DAT_cc008000,8);
    write_volatile_1(DAT_cc008000,0x40);
    write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x84));
    write_volatile_1(DAT_cc008000,0x10);
    write_volatile_4(0xcc008000,0x1019);
    write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x84));
  }
  *(undefined2 *)(gx + 2) = 1;
  return;
}

