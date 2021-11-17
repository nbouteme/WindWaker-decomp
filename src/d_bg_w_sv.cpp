#include <d_bg_w_sv.h>
#include <SComponent/c_bg_w.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_bg_w_sv.h>
#include <dBgWSv.h>


/* __thiscall dBgWSv::Set(cBgD_t *,
                          unsigned long) */

uint __thiscall dBgWSv::Set(dBgWSv *this,cBgD_t *param_1,ulong param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = cBgW::Set((cBgW *)this,param_1,99,(MTX34 *)0x0);
  if ((uVar1 & 0xff) == 0) {
    *(ulong *)&this->field_0xbc = param_2;
    if ((*(uint *)&this->field_0xbc & 1) == 0) {
      uVar2 = JKernel::operator_new__(((this->parent).parent.mpBgDt)->mVtxCount * 0xc);
      *(undefined4 *)&this->field_0xc0 = uVar2;
      uVar1 = countLeadingZeros(*(undefined4 *)&this->field_0xc0);
      uVar1 = uVar1 >> 5 & 0xff;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall dBgWSv::CopyBackVtx(void) */

void __thiscall dBgWSv::CopyBackVtx(dBgWSv *this)

{
  int iVar1;
  cXyz *pDst;
  cXyz *pSrc;
  int iVar2;
  
  if (*(int *)&this->field_0xc0 == 0) {
    return;
  }
  if ((this->parent).parent.mpVtxTbl == (cXyz *)0x0) {
    return;
  }
  iVar1 = 0;
  for (iVar2 = 0; iVar2 < ((this->parent).parent.mpBgDt)->mVtxCount; iVar2 = iVar2 + 1) {
    pSrc = (cXyz *)((int)&((this->parent).parent.mpVtxTbl)->x + iVar1);
    pDst = (cXyz *)(*(int *)&this->field_0xc0 + iVar1);
    pDst->x = pSrc->x;
    pDst->y = pSrc->y;
    pDst->z = pSrc->z;
    iVar1 = iVar1 + 0xc;
  }
  return;
}


/* __thiscall dBgWSv::CrrPosWork(cXyz *,
                                 int,
                                 int,
                                 int) */

undefined4 __thiscall
dBgWSv::CrrPosWork(dBgWSv *this,cXyz *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  cXyz *pcVar9;
  int iVar10;
  int iVar11;
  float *pfVar12;
  int iVar13;
  
  iVar11 = *(int *)&this->field_0xc0;
  iVar10 = param_2 * 0xc;
  fVar1 = *(float *)(iVar11 + iVar10);
  fVar2 = *(float *)(iVar11 + param_3 * 0xc) - fVar1;
  iVar13 = iVar11 + 8;
  fVar3 = *(float *)(iVar13 + param_3 * 0xc) - *(float *)(iVar13 + iVar10);
  fVar4 = *(float *)(iVar11 + param_4 * 0xc) - fVar1;
  fVar7 = *(float *)(iVar13 + param_4 * 0xc) - *(float *)(iVar13 + iVar10);
  if ((ABS(fVar3) < SComponent::G_CM3D_F_ABS_MIN) || (ABS(fVar7) < SComponent::G_CM3D_F_ABS_MIN)) {
    uVar8 = 1;
  }
  else {
    fVar6 = fVar4 / fVar7;
    fVar5 = fVar2 - fVar3 * fVar6;
    fVar2 = fVar2 / fVar3;
    fVar4 = fVar4 - fVar7 * fVar2;
    if ((ABS(fVar5) < SComponent::G_CM3D_F_ABS_MIN) || (ABS(fVar4) < SComponent::G_CM3D_F_ABS_MIN))
    {
      uVar8 = 1;
    }
    else {
      param_1->x = param_1->x - fVar1;
      param_1->z = param_1->z - *(float *)(*(int *)&this->field_0xc0 + iVar10 + 8);
      fVar5 = (param_1->x - param_1->z * fVar6) / fVar5;
      fVar4 = (param_1->x - param_1->z * fVar2) / fVar4;
      pcVar9 = (this->parent).parent.mpVtxTbl;
      pfVar12 = &pcVar9->z;
      fVar1 = pfVar12[param_3 * 3];
      fVar2 = pfVar12[param_2 * 3];
      fVar3 = pfVar12[param_4 * 3];
      param_1->x = fVar5 * (pcVar9[param_3].x - pcVar9[param_2].x) +
                   fVar4 * (pcVar9[param_4].x - pcVar9[param_2].x);
      param_1->z = fVar5 * (fVar1 - fVar2) + fVar4 * (fVar3 - fVar2);
      param_1->x = param_1->x + (this->parent).parent.mpVtxTbl[param_2].x;
      param_1->z = param_1->z + (this->parent).parent.mpVtxTbl[param_2].z;
      uVar8 = 0;
    }
  }
  return uVar8;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dBgWSv::CrrPos(cBgS_PolyInfo &,
                             void *,
                             bool,
                             cXyz *,
                             csXyz *,
                             csXyz *) */

void __thiscall
dBgWSv::CrrPos(dBgWSv *this,cBgS_PolyInfo *param_1,void *param_2,bool param_3,cXyz *param_4,
              csXyz *param_5,csXyz *param_6)

{
  char cVar1;
  cBgD__Tri_t *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (((*(uint *)&this->field_0xbc & 1) == 0) && (param_3 != false)) {
    pcVar2 = ((this->parent).parent.mpBgDt)->mpTriTbl;
    uVar5 = (uint)(ushort)pcVar2[(ushort)param_1->mTriIdx].mVtxIdx0;
    pcVar2 = pcVar2 + (ushort)param_1->mTriIdx;
    uVar4 = (uint)(ushort)pcVar2->mVtxIdx1;
    uVar3 = (uint)(ushort)pcVar2->mVtxIdx2;
    cVar1 = CrrPosWork(this,param_4,uVar5,uVar4,uVar3);
    if ((cVar1 != '\0') && (cVar1 = CrrPosWork(this,param_4,uVar4,uVar3,uVar5), cVar1 != '\0')) {
      CrrPosWork(this,param_4,uVar3,uVar5,uVar4);
    }
  }
  return;
}


/* __thiscall dBgWSv::TransPosWork(cXyz *,
                                   int,
                                   int,
                                   int) */

undefined4 __thiscall
dBgWSv::TransPosWork(dBgWSv *this,cXyz *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  cXyz *pcVar10;
  int iVar11;
  int iVar12;
  float *pfVar13;
  int iVar14;
  float *pfVar15;
  
  iVar12 = *(int *)&this->field_0xc0;
  iVar11 = param_2 * 0xc;
  fVar1 = *(float *)(iVar12 + iVar11);
  fVar2 = *(float *)(iVar12 + param_3 * 0xc) - fVar1;
  iVar14 = iVar12 + 8;
  fVar3 = *(float *)(iVar14 + param_3 * 0xc) - *(float *)(iVar14 + iVar11);
  fVar7 = *(float *)(iVar12 + param_4 * 0xc) - fVar1;
  fVar4 = *(float *)(iVar14 + param_4 * 0xc) - *(float *)(iVar14 + iVar11);
  if ((ABS(fVar3) < SComponent::G_CM3D_F_ABS_MIN) || (ABS(fVar4) < SComponent::G_CM3D_F_ABS_MIN)) {
    uVar9 = 1;
  }
  else {
    fVar5 = fVar7 / fVar4;
    fVar8 = fVar2 - fVar3 * fVar5;
    fVar2 = fVar2 / fVar3;
    fVar7 = fVar7 - fVar4 * fVar2;
    if ((ABS(fVar8) < SComponent::G_CM3D_F_ABS_MIN) || (ABS(fVar7) < SComponent::G_CM3D_F_ABS_MIN))
    {
      uVar9 = 1;
    }
    else {
      fVar1 = param_1->x - fVar1;
      fVar3 = param_1->z - *(float *)(iVar12 + iVar11 + 8);
      fVar8 = (fVar1 - fVar3 * fVar5) / fVar8;
      fVar7 = (fVar1 - fVar3 * fVar2) / fVar7;
      if ((((fVar8 < d_bg_w_sv::_2891) || (d_bg_w_sv::_2892 < fVar8)) || (fVar7 < d_bg_w_sv::_2891))
         || (d_bg_w_sv::_2892 < fVar7)) {
        uVar9 = 1;
      }
      else {
        pcVar10 = (this->parent).parent.mpVtxTbl;
        pfVar13 = &pcVar10->y;
        fVar1 = pfVar13[param_3 * 3];
        fVar2 = pfVar13[param_2 * 3];
        pfVar15 = &pcVar10->z;
        fVar3 = pfVar15[param_3 * 3];
        fVar4 = pfVar15[param_2 * 3];
        fVar5 = pfVar13[param_4 * 3];
        fVar6 = pfVar15[param_4 * 3];
        param_1->x = fVar8 * (pcVar10[param_3].x - pcVar10[param_2].x) +
                     fVar7 * (pcVar10[param_4].x - pcVar10[param_2].x);
        param_1->y = fVar8 * (fVar1 - fVar2) + fVar7 * (fVar5 - fVar2);
        param_1->z = fVar8 * (fVar3 - fVar4) + fVar7 * (fVar6 - fVar4);
        param_1->x = param_1->x + (this->parent).parent.mpVtxTbl[param_2].x;
        param_1->y = param_1->y + (this->parent).parent.mpVtxTbl[param_2].y;
        param_1->z = param_1->z + (this->parent).parent.mpVtxTbl[param_2].z;
        uVar9 = 0;
      }
    }
  }
  return uVar9;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dBgWSv::TransPos(cBgS_PolyInfo &,
                               void *,
                               bool,
                               cXyz *,
                               csXyz *,
                               csXyz *) */

void __thiscall
dBgWSv::TransPos(dBgWSv *this,cBgS_PolyInfo *param_1,void *param_2,bool param_3,cXyz *param_4,
                csXyz *param_5,csXyz *param_6)

{
  char cVar1;
  cBgD__Tri_t *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (((*(uint *)&this->field_0xbc & 1) == 0) && (param_3 != false)) {
    pcVar2 = ((this->parent).parent.mpBgDt)->mpTriTbl;
    uVar5 = (uint)(ushort)pcVar2[(ushort)param_1->mTriIdx].mVtxIdx0;
    pcVar2 = pcVar2 + (ushort)param_1->mTriIdx;
    uVar4 = (uint)(ushort)pcVar2->mVtxIdx1;
    uVar3 = (uint)(ushort)pcVar2->mVtxIdx2;
    cVar1 = TransPosWork(this,param_4,uVar5,uVar4,uVar3);
    if ((cVar1 != '\0') && (cVar1 = TransPosWork(this,param_4,uVar4,uVar3,uVar5), cVar1 != '\0')) {
      TransPosWork(this,param_4,uVar3,uVar5,uVar4);
    }
  }
  return;
}


/* __thiscall dBgWSv::~dBgWSv(void) */

void __thiscall dBgWSv::_dBgWSv(dBgWSv *this)

{
  short in_r4;
  
  if (this != (dBgWSv *)0x0) {
    (this->parent).parent.vtbl = &__vt;
    if (this != (dBgWSv *)0x0) {
      (this->parent).parent.vtbl = (undefined *)&dBgW::__vt;
      cBgW::_cBgW((cBgW *)this);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

