#include <J3DGraphBase/J3DDrawBuffer.h>
#include <JKernel/JKRHeap.h>
#include <J3DGraphBase/J3DDrawBuffer.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DGraphBase/J3DPacket.h>
#include <J3DGraphBase/J3DTransform.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <Demangler/J3DDrawBuffer.h>


namespace J3DDrawBuffer {
undefined1 entryNum;
}

/* __thiscall J3DDrawBuffer::initialize(void) */

void __thiscall J3DDrawBuffer::initialize(J3DDrawBuffer *this)

{
  this->mDrawType = 0;
  this->mSortType = 0;
  this->field_0x10 = J3DGraphBase::_1367;
  this->field_0x14 = J3DGraphBase::_1368;
  this->mpNodeMtx = (MTX34 *)0x0;
  this->mpFirstPacket = (J3DCallBackPacket *)0x0;
  this->mPacketBufSize = 0x20;
  this->field_0x18 =
       (this->field_0x14 - this->field_0x10) /
       (float)((double)CONCAT44(0x43300000,this->mPacketBufSize) - J3DGraphBase::_1370);
  return;
}


/* __thiscall J3DDrawBuffer::allocBuffer(unsigned long) */

undefined4 __thiscall J3DDrawBuffer::allocBuffer(J3DDrawBuffer *this,ulong param_1)

{
  J3DPacket **ppJVar1;
  undefined4 uVar2;
  
  ppJVar1 = (J3DPacket **)JKernel::operator_new__(param_1 << 2,0x20);
  this->mpPacketBuf = ppJVar1;
  if (this->mpPacketBuf == (J3DPacket **)0x0) {
    uVar2 = 4;
  }
  else {
    this->mPacketBufSize = param_1;
    frameInit(this);
    this->field_0x18 =
         (this->field_0x14 - this->field_0x10) /
         (float)((double)CONCAT44(0x43300000,this->mPacketBufSize) - J3DGraphBase::_1370);
    uVar2 = 0;
  }
  return uVar2;
}


/* __thiscall J3DDrawBuffer::~J3DDrawBuffer(void) */

void __thiscall J3DDrawBuffer::_J3DDrawBuffer(J3DDrawBuffer *this)

{
  short in_r4;
  
  if (this != (J3DDrawBuffer *)0x0) {
    frameInit(this);
    JKernel::operator_delete__(this->mpPacketBuf);
    this->mpPacketBuf = (J3DPacket **)0x0;
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DDrawBuffer::frameInit(void) */

void __thiscall J3DDrawBuffer::frameInit(J3DDrawBuffer *this)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  for (uVar2 = 0; uVar2 < this->mPacketBufSize; uVar2 = uVar2 + 1) {
    *(undefined4 *)((int)this->mpPacketBuf + iVar1) = 0;
    iVar1 = iVar1 + 4;
  }
  this->mpFirstPacket = (J3DCallBackPacket *)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall J3DDrawBuffer::entryMatSort(J3DMatPacket *) */

undefined4 __thiscall J3DDrawBuffer::entryMatSort(J3DDrawBuffer *this,J3DMatPacket *param_1)

{
  J3DMatPacket *this_00;
  J3DShapePacket *pJVar1;
  J3DTevBlock *pJVar2;
  ushort uVar3;
  char cVar4;
  uint uVar5;
  J3DTexture *pTex;
  
  (param_1->parent).parent.mpNextSibling = (J3DPacket *)0x0;
  (param_1->parent).parent.mpFirstChild = (J3DPacket *)0x0;
  pJVar1 = param_1->mpFirstShapePacket;
  (pJVar1->parent).parent.mpNextSibling = (J3DPacket *)0x0;
  (pJVar1->parent).parent.mpFirstChild = (J3DPacket *)0x0;
  pTex = J3DGraphBase::j3dSys.mpCurTex;
  if ((param_1->mSortFlags & 0x80000000U) == 0) {
    pJVar2 = param_1->mpMaterial->mpTevBlock;
    uVar3 = (*(code *)pJVar2->vtbl->getTexNo)(pJVar2,0);
    if (uVar3 == 0xffff) {
      uVar5 = 0;
    }
    else {
      uVar5 = (uint)(&pTex->mpTexData[uVar3].mTexFmt + pTex->mpTexData[uVar3].mTexDataOffs) >> 5;
    }
    uVar5 = uVar5 & this->mPacketBufSize - 1;
    this_00 = (J3DMatPacket *)this->mpPacketBuf[uVar5];
    if (this_00 == (J3DMatPacket *)0x0) {
      this->mpPacketBuf[uVar5] = (J3DPacket *)param_1;
    }
    else {
      for (; this_00 != (J3DMatPacket *)0x0;
          this_00 = (J3DMatPacket *)(this_00->parent).parent.mpNextSibling) {
        cVar4 = (**(code **)((this_00->parent).parent.vtbl + 8))(this_00,param_1);
        if (cVar4 != '\0') {
          J3DMatPacket::addShapePacket(this_00,param_1->mpFirstShapePacket);
          return 0;
        }
      }
      (param_1->parent).parent.mpNextSibling = this->mpPacketBuf[uVar5];
      this->mpPacketBuf[uVar5] = (J3DPacket *)param_1;
    }
  }
  else {
    (param_1->parent).parent.mpNextSibling = *this->mpPacketBuf;
    *this->mpPacketBuf = (J3DPacket *)param_1;
  }
  return 1;
}


/* __thiscall J3DDrawBuffer::entryMatAnmSort(J3DMatPacket *) */

undefined4 __thiscall J3DDrawBuffer::entryMatAnmSort(J3DDrawBuffer *this,J3DMatPacket *param_1)

{
  undefined4 uVar1;
  J3DShapePacket *pJVar2;
  J3DMatPacket *this_00;
  uint uVar3;
  J3DMatPacket *pJVar4;
  J3DMaterialAnm *pJVar5;
  
  pJVar5 = param_1->mpMaterialAnm;
  uVar3 = (uint)pJVar5 & this->mPacketBufSize - 1;
  if (pJVar5 == (J3DMaterialAnm *)0x0) {
    uVar1 = entryMatSort(this,param_1);
  }
  else {
    (param_1->parent).parent.mpNextSibling = (J3DPacket *)0x0;
    (param_1->parent).parent.mpFirstChild = (J3DPacket *)0x0;
    pJVar2 = param_1->mpFirstShapePacket;
    (pJVar2->parent).parent.mpNextSibling = (J3DPacket *)0x0;
    (pJVar2->parent).parent.mpFirstChild = (J3DPacket *)0x0;
    pJVar4 = (J3DMatPacket *)this->mpPacketBuf[uVar3];
    this_00 = pJVar4;
    if (pJVar4 == (J3DMatPacket *)0x0) {
      this->mpPacketBuf[uVar3] = (J3DPacket *)param_1;
      uVar1 = 1;
    }
    else {
      for (; this_00 != (J3DMatPacket *)0x0;
          this_00 = (J3DMatPacket *)(this_00->parent).parent.mpNextSibling) {
        if (this_00->mpMaterialAnm == pJVar5) {
          J3DMatPacket::addShapePacket(this_00,param_1->mpFirstShapePacket);
          return 0;
        }
      }
      (param_1->parent).parent.mpNextSibling = (J3DPacket *)pJVar4;
      this->mpPacketBuf[uVar3] = (J3DPacket *)param_1;
      uVar1 = 1;
    }
  }
  return uVar1;
}


/* __thiscall J3DDrawBuffer::entryZSort(J3DMatPacket *) */

undefined4 __thiscall J3DDrawBuffer::entryZSort(J3DDrawBuffer *this,J3DMatPacket *param_1)

{
  J3DShapePacket *pJVar1;
  MTX34 *pMVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  cXyz local_28;
  float local_1c;
  float local_18;
  float local_14;
  
  (param_1->parent).parent.mpNextSibling = (J3DPacket *)0x0;
  (param_1->parent).parent.mpFirstChild = (J3DPacket *)0x0;
  pJVar1 = param_1->mpFirstShapePacket;
  (pJVar1->parent).parent.mpNextSibling = (J3DPacket *)0x0;
  (pJVar1->parent).parent.mpFirstChild = (J3DPacket *)0x0;
  pMVar2 = this->mpNodeMtx;
  local_28.x = pMVar2->m[3];
  local_28.y = pMVar2->m[1][3];
  local_28.z = pMVar2->m[2][3];
  local_1c = local_28.x;
  local_18 = local_28.y;
  local_14 = local_28.z;
  dVar4 = J3DGraphBase::J3DCalcZValue(&J3DGraphBase::j3dSys.mCurViewMtx,&local_28);
  dVar4 = -dVar4;
  dVar5 = (double)this->field_0x18;
  if (dVar4 <= (double)(float)((double)this->field_0x10 + dVar5)) {
    iVar3 = 0;
  }
  else {
    if ((double)(float)((double)this->field_0x14 - dVar5) <= dVar4) {
      iVar3 = this->mPacketBufSize - 1;
    }
    else {
      iVar3 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)(float)(dVar4 / dVar5));
    }
  }
  iVar3 = (this->mPacketBufSize - 1) - iVar3;
  (param_1->parent).parent.mpNextSibling = this->mpPacketBuf[iVar3];
  this->mpPacketBuf[iVar3] = (J3DPacket *)param_1;
  return 1;
}


/* __thiscall J3DDrawBuffer::entryModelSort(J3DMatPacket *) */

bool __thiscall J3DDrawBuffer::entryModelSort(J3DDrawBuffer *this,J3DMatPacket *param_1)

{
  J3DCallBackPacket *this_00;
  J3DShapePacket *pJVar1;
  
  (param_1->parent).parent.mpNextSibling = (J3DPacket *)0x0;
  (param_1->parent).parent.mpFirstChild = (J3DPacket *)0x0;
  pJVar1 = param_1->mpFirstShapePacket;
  (pJVar1->parent).parent.mpNextSibling = (J3DPacket *)0x0;
  (pJVar1->parent).parent.mpFirstChild = (J3DPacket *)0x0;
  this_00 = this->mpFirstPacket;
  if (this_00 != (J3DCallBackPacket *)0x0) {
    J3DPacket::addChildPacket(&this_00->parent,(J3DPacket *)param_1);
  }
  return this_00 != (J3DCallBackPacket *)0x0;
}


/* __thiscall J3DDrawBuffer::entryInvalidSort(J3DMatPacket *) */

bool __thiscall J3DDrawBuffer::entryInvalidSort(J3DDrawBuffer *this,J3DMatPacket *param_1)

{
  J3DCallBackPacket *this_00;
  J3DShapePacket *pJVar1;
  
  (param_1->parent).parent.mpNextSibling = (J3DPacket *)0x0;
  (param_1->parent).parent.mpFirstChild = (J3DPacket *)0x0;
  pJVar1 = param_1->mpFirstShapePacket;
  (pJVar1->parent).parent.mpNextSibling = (J3DPacket *)0x0;
  (pJVar1->parent).parent.mpFirstChild = (J3DPacket *)0x0;
  this_00 = this->mpFirstPacket;
  if (this_00 != (J3DCallBackPacket *)0x0) {
    J3DPacket::addChildPacket(&this_00->parent,(J3DPacket *)param_1->mpFirstShapePacket);
  }
  return this_00 != (J3DCallBackPacket *)0x0;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall J3DDrawBuffer::entryNonSort(J3DMatPacket *) */

undefined4 __thiscall J3DDrawBuffer::entryNonSort(J3DDrawBuffer *this,J3DMatPacket *param_1)

{
  J3DShapePacket *pJVar1;
  
  (param_1->parent).parent.mpNextSibling = (J3DPacket *)0x0;
  (param_1->parent).parent.mpFirstChild = (J3DPacket *)0x0;
  pJVar1 = param_1->mpFirstShapePacket;
  (pJVar1->parent).parent.mpNextSibling = (J3DPacket *)0x0;
  (pJVar1->parent).parent.mpFirstChild = (J3DPacket *)0x0;
  (param_1->parent).parent.mpNextSibling = *this->mpPacketBuf;
  *this->mpPacketBuf = (J3DPacket *)param_1;
  return 1;
}


/* __thiscall J3DDrawBuffer::entryImm(J3DPacket *,
                                      unsigned short) */

undefined4 __thiscall J3DDrawBuffer::entryImm(J3DDrawBuffer *this,J3DPacket *pPacket,ushort index)

{
  pPacket->mpNextSibling = this->mpPacketBuf[index];
  this->mpPacketBuf[index] = pPacket;
  return 1;
}


/* __thiscall J3DDrawBuffer::draw(void) const */

void __thiscall J3DDrawBuffer::draw(J3DDrawBuffer *this)

{
  int iVar1;
  PTMF local_18 [2];
  
  iVar1 = this->mDrawType;
  local_18[0].this_delta = *(int *)(&drawFuncTable + iVar1 * 0xc);
  local_18[0].vtbl_offset = (&DAT_8039e9d4)[iVar1 * 3];
  local_18[0].func = (undefined *)(&DAT_8039e9d8)[iVar1 * 3];
  Runtime.PPCEABI.H::__ptmf_scall(local_18,this,(void *)local_18[0].this_delta);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DDrawBuffer::drawHead(void) const */

void __thiscall J3DDrawBuffer::drawHead(J3DDrawBuffer *this)

{
  int *piVar1;
  uint uVar2;
  J3DPacket **ppJVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = this->mPacketBufSize;
  ppJVar3 = this->mpPacketBuf;
  iVar5 = 0;
  for (uVar2 = 0; uVar2 < uVar4; uVar2 = uVar2 + 1) {
    for (piVar1 = *(int **)((int)ppJVar3 + iVar5); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1])
    {
      (**(code **)(*piVar1 + 0x10))(piVar1);
    }
    iVar5 = iVar5 + 4;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DDrawBuffer::drawTail(void) const */

void __thiscall J3DDrawBuffer::drawTail(J3DDrawBuffer *this)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = this->mPacketBufSize - 1;
  iVar3 = iVar2 * 4;
  for (; -1 < iVar2; iVar2 = iVar2 + -1) {
    for (piVar1 = *(int **)((int)this->mpPacketBuf + iVar3); piVar1 != (int *)0x0;
        piVar1 = (int *)piVar1[1]) {
      (**(code **)(*piVar1 + 0x10))(piVar1);
    }
    iVar3 = iVar3 + -4;
  }
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall J3DDrawBuffer::setCallBackPacket(J3DCallBackPacket *) */

void __thiscall J3DDrawBuffer::setCallBackPacket(J3DDrawBuffer *this,J3DCallBackPacket *param_1)

{
  this->mpFirstPacket = param_1;
  if (param_1 == (J3DCallBackPacket *)0x0) {
    return;
  }
  (param_1->parent).mpNextSibling = (J3DPacket *)0x0;
  (param_1->parent).mpFirstChild = (J3DPacket *)0x0;
  (param_1->parent).mpNextSibling = *this->mpPacketBuf;
  *this->mpPacketBuf = &param_1->parent;
  return;
}


namespace J3DGraphBase {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_J3DDrawBuffer_cpp(void)

{
  _sortFuncTable = _1354;
  DAT_8039e974 = DAT_8039e92c;
  DAT_8039e978 = PTR_entryMatSort_8039e930;
  DAT_8039e97c = _1355;
  DAT_8039e980 = DAT_8039e938;
  DAT_8039e984 = PTR_entryMatAnmSort_8039e93c;
  DAT_8039e988 = _1356;
  DAT_8039e98c = DAT_8039e944;
  DAT_8039e990 = PTR_entryZSort_8039e948;
  DAT_8039e994 = _1357;
  DAT_8039e998 = DAT_8039e950;
  DAT_8039e99c = PTR_entryModelSort_8039e954;
  DAT_8039e9a0 = _1358;
  DAT_8039e9a4 = DAT_8039e95c;
  DAT_8039e9a8 = PTR_entryInvalidSort_8039e960;
  DAT_8039e9ac = _1359;
  DAT_8039e9b0 = DAT_8039e968;
  DAT_8039e9b4 = PTR_entryNonSort_8039e96c;
  _drawFuncTable = _1360;
  DAT_8039e9d4 = DAT_8039e9bc;
  DAT_8039e9d8 = PTR_drawHead_8039e9c0;
  DAT_8039e9dc = _1361;
  DAT_8039e9e0 = DAT_8039e9c8;
  DAT_8039e9e4 = PTR_drawTail_8039e9cc;
  return;
}

