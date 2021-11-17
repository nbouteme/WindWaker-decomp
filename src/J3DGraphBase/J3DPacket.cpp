#include <J3DGraphBase/J3DPacket.h>
#include <JKernel/JKRHeap.h>
#include <os/OSCache.h>
#include <gx/GXDisplayList.h>
#include <J3DGraphBase/J3DPacket.h>
#include <os/OSInterrupt.h>
#include <gd/GDBase.h>
#include <J3DGraphBase/J3DShape.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DGraphBase/J3DVertex.h>
#include <J3DMatPacket.h>
#include <J3DPacket.h>
#include <J3DDisplayListObj.h>
#include <J3DDrawPacket.h>
#include <J3DCallBackPacket.h>
#include <Demangler/J3DShapePacket.h>

undefined1 J3DDisplayListObj;
undefined1 J3DDisplayListObj;

/* __thiscall J3DDisplayListObj::newDisplayList(unsigned long) */

undefined4 __thiscall J3DDisplayListObj::newDisplayList(J3DDisplayListObj *this,ulong param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  this->mCapacity = param_1 + 0x1f & 0xffffffe0;
  pvVar1 = (void *)JKernel::operator_new__(this->mCapacity,0x20);
  this->mpData[0] = pvVar1;
  pvVar1 = (void *)JKernel::operator_new__(this->mCapacity,0x20);
  this->mpData[1] = pvVar1;
  this->mSize = 0;
  if ((this->mpData[0] == (void *)0x0) || (this->mpData[1] == (void *)0x0)) {
    uVar2 = 4;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __thiscall J3DDisplayListObj::newSingleDisplayList(unsigned long) */

undefined4 __thiscall J3DDisplayListObj::newSingleDisplayList(J3DDisplayListObj *this,ulong param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  this->mCapacity = param_1 + 0x1f & 0xffffffe0;
  pvVar1 = (void *)JKernel::operator_new__(this->mCapacity,0x20);
  this->mpData[0] = pvVar1;
  this->mpData[1] = this->mpData[0];
  uVar2 = 0;
  this->mSize = 0;
  if (this->mpData[0] == (void *)0x0) {
    uVar2 = 4;
  }
  return uVar2;
}


/* __thiscall J3DDisplayListObj::single_To_Double(void) */

undefined4 __thiscall J3DDisplayListObj::single_To_Double(J3DDisplayListObj *this)

{
  void *pvVar1;
  
  if (this->mpData[0] == this->mpData[1]) {
    pvVar1 = (void *)JKernel::operator_new__(this->mCapacity,0x20);
    this->mpData[1] = pvVar1;
    if ((byte *)this->mpData[1] == (byte *)0x0) {
      return 4;
    }
    copy_bytes((byte *)this->mpData[1],(byte *)this->mpData[0],this->mCapacity);
    os::DCStoreRange(this->mpData[1],this->mCapacity);
  }
  return 0;
}


/* __thiscall J3DDisplayListObj::setSingleDisplayList(void *,
                                                      unsigned long) */

void __thiscall
J3DDisplayListObj::setSingleDisplayList(J3DDisplayListObj *this,void *pData,ulong size)

{
  this->mCapacity = size + 0x1f & 0xffffffe0;
  this->mpData[0] = pData;
  this->mpData[1] = this->mpData[0];
  this->mSize = size;
  return;
}


/* __thiscall J3DDisplayListObj::swapBuffer(void) */

void __thiscall J3DDisplayListObj::swapBuffer(J3DDisplayListObj *this)

{
  void *pvVar1;
  
  pvVar1 = this->mpData[0];
  this->mpData[0] = this->mpData[1];
  this->mpData[1] = pvVar1;
  return;
}


/* __thiscall J3DDisplayListObj::callDL(void) const */

void __thiscall J3DDisplayListObj::callDL(J3DDisplayListObj *this)

{
  gx::GXCallDisplayList(this->mpData[0],this->mSize);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DDisplayListObj::beginDL(void) */

void __thiscall J3DDisplayListObj::beginDL(J3DDisplayListObj *this)

{
  swapBuffer(this);
  _sInterruptFlag = os::OSDisableInterrupts();
  gd::GDInitGDLObj(&sGDLObj,this->mpData[0],this->mCapacity);
  gd::__GDCurrentDL = &sGDLObj;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DDisplayListObj::endDL(void) */

int __thiscall J3DDisplayListObj::endDL(J3DDisplayListObj *this)

{
  gd::GDPadCurr32();
  os::OSRestoreInterrupts(_sInterruptFlag);
  this->mSize = DAT_803edc10 - _sGDLObj;
  gd::GDFlushCurrToMem();
  gd::__GDCurrentDL = 0;
  return this->mSize;
}


/* __thiscall J3DDisplayListObj::beginPatch(void) */

void __thiscall J3DDisplayListObj::beginPatch(J3DDisplayListObj *this)

{
  beginDL(this);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DDisplayListObj::endPatch(void) */

int __thiscall J3DDisplayListObj::endPatch(J3DDisplayListObj *this)

{
  os::OSRestoreInterrupts(_sInterruptFlag);
  gd::__GDCurrentDL = 0;
  return this->mSize;
}


/* __thiscall J3DPacket::isSame(J3DMatPacket *) const */

undefined4 __thiscall J3DPacket::isSame(J3DPacket *this,J3DMatPacket *param_1)

{
  return 0;
}


/* __thiscall J3DPacket::entry(J3DDrawBuffer *) */

undefined4 __thiscall J3DPacket::entry(J3DPacket *this,J3DDrawBuffer *param_1)

{
  return 1;
}


/* __thiscall J3DPacket::addChildPacket(J3DPacket *) */

void __thiscall J3DPacket::addChildPacket(J3DPacket *this,J3DPacket *param_1)

{
  if (this->mpFirstChild == (J3DPacket *)0x0) {
    this->mpFirstChild = param_1;
    return;
  }
  param_1->mpNextSibling = this->mpFirstChild;
  this->mpFirstChild = param_1;
  return;
}


/* __thiscall J3DCallBackPacket::draw(void) */

void __thiscall J3DCallBackPacket::draw(J3DCallBackPacket *this)

{
  J3DPacket *pJVar1;
  
  if ((code *)this->mCallBack != (code *)0x0) {
    (*(code *)this->mCallBack)(this,0);
  }
  for (pJVar1 = (this->parent).mpFirstChild; pJVar1 != (J3DPacket *)0x0;
      pJVar1 = pJVar1->mpNextSibling) {
    (**(code **)(pJVar1->vtbl + 0x10))(pJVar1);
  }
  if ((code *)this->mCallBack != (code *)0x0) {
    (*(code *)this->mCallBack)(this,1);
  }
  return;
}


/* __thiscall J3DDrawPacket::J3DDrawPacket(void) */

void __thiscall J3DDrawPacket::J3DDrawPacket(J3DDrawPacket *this)

{
  (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
  (this->parent).mpNextSibling = (J3DPacket *)0x0;
  (this->parent).mpFirstChild = (J3DPacket *)0x0;
  (this->parent).field_0xc = (undefined *)0x0;
  (this->parent).vtbl = &__vt;
  this->mFlags = 0;
  this->mpDLObj = (J3DDisplayListObj *)0x0;
  return;
}


/* __thiscall J3DDrawPacket::~J3DDrawPacket(void) */

void __thiscall J3DDrawPacket::_J3DDrawPacket(J3DDrawPacket *this)

{
  short in_r4;
  
  if (this != (J3DDrawPacket *)0x0) {
    (this->parent).vtbl = &__vt;
    if (this != (J3DDrawPacket *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DDrawPacket::newDisplayList(unsigned long) */

int __thiscall J3DDrawPacket::newDisplayList(J3DDrawPacket *this,ulong param_1)

{
  J3DDisplayListObj *pJVar1;
  int iVar2;
  int iVar3;
  
  pJVar1 = (J3DDisplayListObj *)JKernel::operator_new(0x10);
  if (pJVar1 != (J3DDisplayListObj *)0x0) {
    pJVar1->mpData[0] = (void *)0x0;
    pJVar1->mpData[1] = (void *)0x0;
    pJVar1->mSize = 0;
    pJVar1->mCapacity = 0;
  }
  this->mpDLObj = pJVar1;
  if (this->mpDLObj == (J3DDisplayListObj *)0x0) {
    iVar3 = 4;
  }
  else {
    iVar2 = J3DDisplayListObj::newDisplayList(this->mpDLObj,param_1);
    iVar3 = 0;
    if (iVar2 != 0) {
      iVar3 = iVar2;
    }
  }
  return iVar3;
}


/* __thiscall J3DDrawPacket::newSingleDisplayList(unsigned long) */

int __thiscall J3DDrawPacket::newSingleDisplayList(J3DDrawPacket *this,ulong param_1)

{
  J3DDisplayListObj *pJVar1;
  int iVar2;
  int iVar3;
  
  pJVar1 = (J3DDisplayListObj *)JKernel::operator_new(0x10);
  if (pJVar1 != (J3DDisplayListObj *)0x0) {
    pJVar1->mpData[0] = (void *)0x0;
    pJVar1->mpData[1] = (void *)0x0;
    pJVar1->mSize = 0;
    pJVar1->mCapacity = 0;
  }
  this->mpDLObj = pJVar1;
  if (this->mpDLObj == (J3DDisplayListObj *)0x0) {
    iVar3 = 4;
  }
  else {
    iVar2 = J3DDisplayListObj::newSingleDisplayList(this->mpDLObj,param_1);
    iVar3 = 0;
    if (iVar2 != 0) {
      iVar3 = iVar2;
    }
  }
  return iVar3;
}


/* __thiscall J3DDrawPacket::draw(void) */

void __thiscall J3DDrawPacket::draw(J3DDrawPacket *this)

{
  J3DDisplayListObj::callDL(this->mpDLObj);
  return;
}


/* __thiscall J3DMatPacket::J3DMatPacket(void) */

void __thiscall J3DMatPacket::J3DMatPacket(J3DMatPacket *this)

{
  J3DDrawPacket::J3DDrawPacket(&this->parent);
  (this->parent).parent.vtbl = &__vt;
  this->mpShapePacket = (J3DShapePacket *)0x0;
  this->mpMaterial = (J3DMaterial *)0x0;
  this->mSortFlags = -1;
  this->mpTexture = (J3DTexture *)0x0;
  this->mpMaterialAnm = (J3DMaterialAnm *)0x0;
  return;
}


/* __thiscall J3DMatPacket::~J3DMatPacket(void) */

void __thiscall J3DMatPacket::_J3DMatPacket(J3DMatPacket *this)

{
  short in_r4;
  
  if (this != (J3DMatPacket *)0x0) {
    (this->parent).parent.vtbl = &__vt;
    J3DDrawPacket::_J3DDrawPacket(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DMatPacket::addShapePacket(J3DShapePacket *) */

void __thiscall J3DMatPacket::addShapePacket(J3DMatPacket *this,J3DShapePacket *param_1)

{
  if (this->mpFirstShapePacket == (J3DShapePacket *)0x0) {
    this->mpFirstShapePacket = param_1;
    return;
  }
  (param_1->parent).parent.mpNextSibling = (J3DPacket *)this->mpFirstShapePacket;
  this->mpFirstShapePacket = param_1;
  return;
}


/* __thiscall J3DMatPacket::beginDiff(void) */

void __thiscall J3DMatPacket::beginDiff(J3DMatPacket *this)

{
  J3DDisplayListObj::beginDL((this->mpShapePacket->parent).mpDLObj);
  return;
}


/* __thiscall J3DMatPacket::endDiff(void) */

void __thiscall J3DMatPacket::endDiff(J3DMatPacket *this)

{
  J3DDisplayListObj::endDL((this->mpShapePacket->parent).mpDLObj);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DMatPacket::draw(void) */

void __thiscall J3DMatPacket::draw(J3DMatPacket *this)

{
  J3DShapePacket *this_00;
  J3DDisplayListObj *this_01;
  
  J3DGraphBase::j3dSys.mpCurTex = this->mpTexture;
  J3DGraphBase::j3dSys.mpCurMatPacket = this;
  (**(code **)(this->mpMaterial->vtbl + 0x14))();
  this_00 = this->mpFirstShapePacket;
  J3DShape::loadPreDrawSetting(this_00->mpShape);
  for (; this_00 != (J3DShapePacket *)0x0;
      this_00 = (J3DShapePacket *)(this_00->parent).parent.mpNextSibling) {
    this_01 = (this_00->parent).mpDLObj;
    if (this_01 != (J3DDisplayListObj *)0x0) {
      J3DDisplayListObj::callDL(this_01);
    }
    J3DShapePacket::drawFast(this_00);
  }
  _sOldVcdVatCmd = 0;
  return;
}


/* __thiscall J3DShapePacket::J3DShapePacket(void) */

void __thiscall J3DShapePacket::J3DShapePacket(J3DShapePacket *this)

{
  J3DDrawPacket::J3DDrawPacket(&this->parent);
  (this->parent).parent.vtbl = &__vt;
  this->mpShape = (J3DShape *)0x0;
  *(undefined4 *)&this->mpMtxBuffer = 0;
  *(undefined4 *)&this->field_0x2c = 0;
  this->mpViewMtx = (MTX34 *)0x0;
  this->mpDrawIdxStart = (int *)&J3DGraphBase::j3dDefaultViewNo;
  this->field_0x3c = (byte *)0x0;
  this->mpModel = (J3DModel *)0x0;
  return;
}


/* __thiscall J3DShapePacket::~J3DShapePacket(void) */

void __thiscall J3DShapePacket::_J3DShapePacket(J3DShapePacket *this)

{
  short in_r4;
  
  if (this != (J3DShapePacket *)0x0) {
    (this->parent).parent.vtbl = &__vt;
    J3DDrawPacket::_J3DDrawPacket(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DShapePacket::calcDifferedBufferSize(unsigned long) */

uint __thiscall J3DShapePacket::calcDifferedBufferSize(J3DShapePacket *this,ulong param_1)

{
  int iVar1;
  uint uVar2;
  byte bVar4;
  uint uVar3;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = 0;
  iVar1 = 0;
  iVar7 = 7;
  do {
    if ((param_1 & *(uint *)((int)&J3DGraphBase::sDifferedRegister + iVar1)) != 0) {
      iVar6 = iVar6 + *(int *)((int)&J3DGraphBase::sSizeOfDiffered + iVar1);
    }
    iVar1 = iVar1 + 4;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar6 = iVar6 + (param_1 >> 4 & 0xf) * 0x48;
  uVar5 = param_1 >> 8 & 0xf;
  if (uVar5 != 0) {
    uVar2 = (*(code *)this->mpShape->mpMaterial->mpTexGenBlock->vtbl->getTexGenNum)();
    if (uVar2 < uVar5) {
      uVar2 = uVar5;
    }
    if ((param_1 & 0x1000) == 0) {
      iVar6 = iVar6 + uVar2 * 0x35;
    }
    else {
      iVar6 = uVar2 * 0x39 + iVar6 + 5;
    }
  }
  uVar5 = param_1 >> 0x10 & 0xf;
  if (uVar5 != 0) {
    bVar4 = (*(code *)this->mpShape->mpMaterial->mpTevBlock->vtbl->getTevStageNum)();
    if (bVar4 < 9) {
      uVar2 = (*(code *)this->mpShape->mpMaterial->mpTevBlock->vtbl->getTevStageNum)();
    }
    else {
      uVar2 = 8;
    }
    uVar3 = uVar2 & 0xff;
    if ((uVar2 & 0xff) < uVar5) {
      uVar3 = uVar5;
    }
    if ((param_1 & 0x4000000) == 0) {
      iVar6 = iVar6 + uVar3 * 0x37;
    }
    else {
      iVar6 = iVar6 + uVar3 * 0x37 + (uVar3 + 1 >> 1) * 0x37;
    }
  }
  uVar5 = param_1 >> 0x14 & 0xf;
  if (uVar5 != 0) {
    bVar4 = (*(code *)this->mpShape->mpMaterial->mpTevBlock->vtbl->getTevStageNum)();
    if (bVar4 < 9) {
      uVar2 = (*(code *)this->mpShape->mpMaterial->mpTevBlock->vtbl->getTevStageNum)();
    }
    else {
      uVar2 = 8;
    }
    uVar3 = uVar2 & 0xff;
    if ((uVar2 & 0xff) < uVar5) {
      uVar3 = uVar5;
    }
    iVar6 = iVar6 + uVar3 * 10;
    if ((param_1 & 0x8000000) != 0) {
      iVar6 = iVar6 + uVar3 * 5;
    }
  }
  return iVar6 + 0x1fU & 0xffffffe0;
}


/* __thiscall J3DShapePacket::newDifferedDisplayList(unsigned long) */

int __thiscall J3DShapePacket::newDifferedDisplayList(J3DShapePacket *this,ulong param_1)

{
  ulong uVar1;
  int iVar2;
  
  this->mDiffFlag = param_1;
  uVar1 = calcDifferedBufferSize(this,param_1);
  iVar2 = J3DDrawPacket::newDisplayList(&this->parent,uVar1);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  return iVar2;
}


/* __thiscall J3DShapePacket::prepareDraw(void) const */

void __thiscall J3DShapePacket::prepareDraw(J3DShapePacket *this)

{
  J3DVertexBuffer::setArray(&this->mpModel->mVertexBuffer);
  J3DGraphBase::j3dSys.mpCurModel = this->mpModel;
  J3DGraphBase::j3dSys.mpCurShapePacket = this;
  this->mpShape->field_0x54 = this->field_0x3c;
  this->mpShape->field_0x58 = *(undefined **)&this->mpMtxBuffer;
  this->mpShape->field_0x5c = *(undefined **)&this->field_0x2c;
  this->mpShape->field_0x60 = (undefined *)this->mpDrawIdxStart;
  return;
}


/* __thiscall J3DShapePacket::draw(void) */

void __thiscall J3DShapePacket::draw(J3DShapePacket *this)

{
  J3DDisplayListObj *pDLObj;
  
  if ((((this->parent).mFlags & 0x10U) == 0) && (this->mpShape != (J3DShape *)0x0)) {
    prepareDraw(this);
    pDLObj = (this->parent).mpDLObj;
    if (pDLObj != (J3DDisplayListObj *)0x0) {
      J3DDisplayListObj::callDL(pDLObj);
    }
    (**(code **)(this->mpShape->vtbl + 8))();
  }
  return;
}


/* __thiscall J3DShapePacket::drawFast(void) */

void __thiscall J3DShapePacket::drawFast(J3DShapePacket *this)

{
  if ((((this->parent).mFlags & 0x10U) == 0) && (this->mpShape != (J3DShape *)0x0)) {
    prepareDraw(this);
    (**(code **)(this->mpShape->vtbl + 0xc))();
  }
  return;
}


/* __thiscall J3DMatPacket::isSame(J3DMatPacket *) const */

undefined4 __thiscall J3DMatPacket::isSame(J3DMatPacket *this,J3DMatPacket *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((this->mSortFlags == param_1->mSortFlags) && (-1 < this->mSortFlags)) {
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall J3DPacket::draw(void) */

void __thiscall J3DPacket::draw(J3DPacket *this)

{
  return;
}


/* __thiscall J3DCallBackPacket::~J3DCallBackPacket(void) */

void __thiscall J3DCallBackPacket::_J3DCallBackPacket(J3DCallBackPacket *this)

{
  short in_r4;
  
  if (this != (J3DCallBackPacket *)0x0) {
    (this->parent).vtbl = &__vt;
    if (this != (J3DCallBackPacket *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

