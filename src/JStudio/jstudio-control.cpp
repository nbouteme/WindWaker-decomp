#include <JStudio/jstudio-control.h>
#include <JStudio/stb.h>
#include <JStudio/fvb.h>
#include <JStudio/jstudio-control.h>
#include <JKernel/JKRHeap.h>
#include <JStudio/jstudio-math.h>
#include <mtx/mtx.h>
#include <JGadget/linklist.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <MSL_C.PPCEABI.bare.H/mem.h>
#include <JGadget/binary.h>
#include <JStudio/TParse.h>
#include <Demangler/JStudio/TControl.h>
#include <JStudio/TFactory.h>
#include <JStudio/TCreateObject.h>


namespace JStudio {

namespace TControl {
}

/* __thiscall TControl::TControl(void) */

void __thiscall TControl::TControl(TControl *this)

{
  cXyz local_18;
  
  stb::TControl::TControl((TControl *)this);
  *(undefined1 **)this = &__vt;
  fvb::TControl::TControl(&this->mControlFVB);
  *(undefined *)&this->field_0x74 = 0;
  *(undefined *)&this->field_0x75 = 0;
  local_18.x = _733;
  local_18.y = DAT_80366b2c;
  local_18.z = DAT_80366b30;
  transformOnSet_setOrigin(this,&local_18,0_0);
  transformOnGet_setOrigin(this,&local_18,0_0);
  return;
}


/* __thiscall TControl::~TControl(void) */

void __thiscall TControl::_TControl(TControl *this)

{
  short in_r4;
  
  if (this != (TControl *)0x0) {
    *(undefined1 **)this = &__vt;
    fvb::TControl::_TControl(&this->mControlFVB);
    stb::TControl::_TControl((TControl *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TControl::transformOnSet_setOrigin(Vec const &,
                                                          float) */

void __thiscall
TControl::transformOnSet_setOrigin(TControl *this,cXyz *param_1,float param_2)

{
  (this->field_0x78).x = param_1->x;
  (this->field_0x78).y = param_1->y;
  (this->field_0x78).z = param_1->z;
  this->field_0x90 = param_2;
  math::getTransformation_RyT((float *)&this->field_0x98,param_2,(Vec *)param_1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8026e22c) */
/* __thiscall TControl::transformOnGet_setOrigin(Vec const &,
                                                          float) */

void __thiscall
TControl::transformOnGet_setOrigin(TControl *this,cXyz *param_1,float param_2)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  MTX34 MStack72;
  undefined auStack8 [8];
  
  dVar2 = (double)param_2;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  (this->mOrigin).x = param_1->x;
  (this->mOrigin).y = param_1->y;
  (this->mOrigin).z = param_1->z;
  this->mOffsetAngY = param_2;
  mtx::PSMTXTrans(-(double)param_1->x,-(double)param_1->y,-(double)param_1->z,&MStack72);
  math::rotate_y(&this->mMtx,&MStack72,(float)-dVar2);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* __thiscall TCreateObject::~TCreateObject(void) */

void __thiscall TCreateObject::_TCreateObject(TCreateObject *this)

{
  short in_r4;
  
  if ((this != (TCreateObject *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall TFactory::~TFactory(void) */

void __thiscall TFactory::_TFactory(TFactory *this)

{
  short in_r4;
  
  if (this != (TFactory *)0x0) {
    *(undefined1 **)this = &__vt;
    fvb::TFactory::_TFactory((TFactory *)(this + 0x10));
    if (this != (TFactory *)0xfffffffc) {
      ::JGadget::TNodeLinkList::_TNodeLinkList((TNodeLinkList *)(this + 4));
    }
    stb::TFactory::_TFactory((TFactory *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TFactory::appendCreateObject(TCreateObject *) */

void __thiscall TFactory::appendCreateObject(TFactory *this,TCreateObject *param_1)

{
  TNodeLinkList aTStack16 [4];
  TFactory *local_c;
  TFactory *local_8;
  TFactory *local_4;
  
  local_c = this + 8;
  local_8 = local_c;
  local_4 = local_c;
  ::JGadget::TNodeLinkList::Insert(aTStack16,(iterator)(this + 4),(TLinkListNode *)&local_c);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TFactory::create(stb::data::TParse_TBlock_object const &) */

undefined4 __thiscall TFactory::create(TFactory *this,TParse_TBlock_object *param_1)

{
  uint uVar1;
  int *piVar2;
  char cVar4;
  undefined4 uVar3;
  undefined4 local_28;
  undefined4 *local_24;
  TFactory *local_20;
  
  local_24 = *(undefined4 **)(this + 8);
  local_20 = this + 8;
  do {
    uVar1 = countLeadingZeros((int)(this + 8) - (int)local_24);
    if ((uVar1 >> 5 & 0xff) != 0) {
      uVar3 = stb::TFactory::create((TFactory *)this,param_1);
      return uVar3;
    }
    piVar2 = local_24 + -1;
    local_24 = (undefined4 *)*local_24;
    local_28 = 0;
    cVar4 = (**(code **)(*piVar2 + 0xc))(piVar2,&local_28,param_1);
  } while (cVar4 == '\0');
  return local_28;
}


/* __thiscall TParse::TParse(TControl *) */

void __thiscall TParse::TParse(TParse *this,TControl *pControl)

{
  stb::TParse::TParse(&this->mParseSTB,(TControl *)pControl);
  (this->mParseSTB).vtbl = (undefined *)&__vt;
  fvb::TParse::TParse(&this->mParseFVB,&pControl->mControlFVB);
  return;
}


/* __thiscall TParse::~TParse(void) */

void __thiscall TParse::_TParse(TParse *this)

{
  short in_r4;
  
  if (this != (TParse *)0x0) {
    (this->mParseSTB).vtbl = (undefined *)&__vt;
    fvb::TParse::_TParse(&this->mParseFVB);
    stb::TParse::_TParse(&this->mParseSTB);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TParse::parseHeader(stb::data::TParse_THeader const &,
                                           unsigned long) */

int __thiscall TParse::parseHeader(TParse *this,TParse_THeader *pHeader,ulong size)

{
  ushort uVar1;
  char **pData;
  int iVar2;
  
  pData = pHeader->mpData;
  iVar2 = MSL_C.PPCEABI.bare.H::memcmp(pData + 4,"jstudio",8);
  if (iVar2 == 0) {
    uVar1 = *(ushort *)((int)pData + 0x1e);
    if (uVar1 < 2) {
      iVar2 = 0;
    }
    else {
      iVar2 = -((3 < uVar1) - 1);
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


/* __thiscall TParse::parseBlock_block(stb::data::TParse_TBlock const &,
                                                unsigned long) */

void __thiscall TParse::parseBlock_block(TParse *this,TParse_TBlock *param_1,ulong param_2)

{
  if (*(int *)(*(int *)param_1 + 4) == 0x4a465642) {
    parseBlock_block_fvb_(this,param_1,param_2);
  }
  else {
    stb::TParse::parseBlock_block(&this->mParseSTB,param_1,param_2);
  }
  return;
}


/* __thiscall TParse::parseBlock_block_fvb_(stb::data::TParse_TBlock const &,
                                                     unsigned long) */

void __thiscall
TParse::parseBlock_block_fvb_(TParse *this,TParse_TBlock *param_1,ulong param_2)

{
  uint mode;
  void *local_8 [2];
  
  local_8[0] = (void *)(*(int *)param_1 + 8);
  mode = param_2 & 0xf;
  if ((param_2 & 0x10) != 0) {
    mode = mode | 0x10;
  }
  if ((param_2 & 0x20) != 0) {
    mode = mode | 0x20;
  }
  if ((param_2 & 0x40) != 0) {
    mode = mode | 0x40;
  }
  ::JGadget::binary::TParse_header_block::parse_next
            ((TParse_header_block *)&this->mParseFVB,local_8,mode);
  return;
}

