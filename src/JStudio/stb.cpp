#include <JStudio/stb.h>
#include <JKernel/JKRHeap.h>
#include <JStudio/stb.h>
#include <JStudio/stb-data-parse.h>
#include <JGadget/linklist.h>
#include <JGadget/binary.h>
#include <MSL_C.PPCEABI.bare.H/mem.h>
#include <JStudio/object-id.h>
#include <JStudio/stb/TObject_control.h>
#include <std.h>
#include <Demangler/JStudio/stb/TParse.h>
#include <Demangler/JStudio/stb/TObject.h>
#include <Demangler/JStudio/stb/TFactory.h>
#include <Demangler/JStudio/stb/TControl.h>


namespace JStudio {

namespace stb {

/* __thiscall TObject::TObject(unsigned long,
                                             void const *,
                                             unsigned long) */

void __thiscall
TObject::TObject(TObject *this,ulong param_1,void *param_2,ulong param_3)

{
  this->vtbl = (undefined *)param_2;
  this[1].vtbl = (undefined *)param_3;
  this[2].vtbl = &__vt;
  this[3].vtbl = (undefined *)0x0;
  this[4].vtbl = (undefined *)0x0;
  this[5].vtbl = (undefined *)0x0;
  this[6].vtbl = (undefined *)param_1;
  *(undefined2 *)&this[7].vtbl = 0;
  *(undefined *)((int)&this[7].vtbl + 2) = 0;
  this[8].vtbl = (undefined *)0x0;
  this[9].vtbl = (undefined *)0x0;
  this[10].vtbl = (undefined *)0x0;
  this[0xb].vtbl = (undefined *)0x0;
  this[0xc].vtbl = (undefined *)0x0;
  return;
}


/* __thiscall TObject::TObject(data::TParse_TBlock_object const &) */

void __thiscall TObject::TObject(TObject *this,TParse_TBlock_object *param_1)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(*(int *)param_1 + 10);
  this->vtbl = (undefined *)(*(int *)param_1 + 0xc);
  this[1].vtbl = (undefined *)(uint)uVar1;
  this[2].vtbl = &__vt;
  this[3].vtbl = (undefined *)0x0;
  this[4].vtbl = (undefined *)0x0;
  this[5].vtbl = (undefined *)0x0;
  this[6].vtbl = *(undefined **)(*(int *)param_1 + 4);
  *(undefined2 *)&this[7].vtbl = *(undefined2 *)(*(int *)param_1 + 8);
  *(undefined *)((int)&this[7].vtbl + 2) = 0;
  this[8].vtbl = (undefined *)0x0;
  this[9].vtbl = (undefined *)0x0;
  this[10].vtbl =
       (undefined *)(*(int *)param_1 + (*(ushort *)(*(int *)param_1 + 10) + 3 & 0xfffffffc) + 0xc);
  this[0xb].vtbl = (undefined *)0x0;
  this[0xc].vtbl = (undefined *)0x0;
  return;
}


/* __thiscall TObject::~TObject(void) */

void __thiscall TObject::_TObject(TObject *this)

{
  short in_r4;
  
  if ((this != (TObject *)0x0) && (this[2].vtbl = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall TObject::setFlag_operation(unsigned char,
                                                       int) */

void __thiscall TObject::setFlag_operation(TObject *this,uchar param_1,int param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)param_2;
  if (param_1 == '\x02') {
    *(ushort *)&this[7].vtbl = *(ushort *)&this[7].vtbl & uVar1;
    return;
  }
  if (param_1 < 2) {
    if (param_1 == '\0') {
      return;
    }
    *(ushort *)&this[7].vtbl = *(ushort *)&this[7].vtbl | uVar1;
    return;
  }
  if (3 < param_1) {
    return;
  }
  *(ushort *)&this[7].vtbl = *(ushort *)&this[7].vtbl ^ uVar1;
  return;
}


/* __thiscall TObject::reset(void const *) */

void __thiscall TObject::reset(TObject *this,void *param_1)

{
  *(undefined *)((int)&this[7].vtbl + 2) = 0;
  this[0xc].vtbl = (undefined *)0x0;
  this[10].vtbl = (undefined *)param_1;
  this[0xb].vtbl = (undefined *)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TObject::forward(unsigned long) */

undefined4 __thiscall TObject::forward(TObject *this,ulong param_1)

{
  bool bVar1;
  undefined *puVar2;
  
  bVar1 = false;
  while( true ) {
    if ((*(ushort *)&this[7].vtbl & 0x8000) != 0) {
      if ((this[0xc].vtbl != (undefined *)0x8) &&
         (this[0xc].vtbl = (undefined *)0x8, *(char *)((int)&this[7].vtbl + 2) != '\0')) {
        (**(code **)(this[2].vtbl + 0x10))(this);
      }
      return 1;
    }
    if (this[0xc].vtbl == (undefined *)0x8) {
      (**(code **)(this[2].vtbl + 0xc))(this);
      this[0xc].vtbl = (undefined *)0x2;
    }
    if (((this[5].vtbl != (undefined *)0x0) && (0 < *(int *)(this[5].vtbl + 0x54))) ||
       (0 < (int)this[8].vtbl)) break;
    while( true ) {
      this[9].vtbl = this[10].vtbl;
      if (this[10].vtbl == (undefined *)0x0) {
        if (*(char *)((int)&this[7].vtbl + 2) != '\0') {
          if (!bVar1) {
            (**(code **)(this[2].vtbl + 0x18))(this,0);
          }
          *(undefined *)((int)&this[7].vtbl + 2) = 0;
          this[0xc].vtbl = (undefined *)0x1;
          (**(code **)(this[2].vtbl + 0x10))(this);
        }
        return 0;
      }
      if (*(char *)((int)&this[7].vtbl + 2) == '\0') {
        *(undefined *)((int)&this[7].vtbl + 2) = 1;
        (**(code **)(this[2].vtbl + 0xc))(this);
      }
      this[0xc].vtbl = (undefined *)0x2;
      if ((this[0xb].vtbl == (undefined *)0x0) &&
         (process_sequence_(this), this[0xb].vtbl == (undefined *)0x0)) break;
      bVar1 = true;
      puVar2 = this[0xb].vtbl;
      if (param_1 < puVar2) {
        this[0xb].vtbl = puVar2 + -param_1;
        (**(code **)(this[2].vtbl + 0x18))(this,param_1);
        return 1;
      }
      param_1 = param_1 + -(int)puVar2;
      this[0xb].vtbl = (undefined *)0x0;
      (**(code **)(this[2].vtbl + 0x18))(this);
    }
  }
  if (*(char *)((int)&this[7].vtbl + 2) == '\0') {
    return 1;
  }
  this[0xc].vtbl = (undefined *)0x4;
  (**(code **)(this[2].vtbl + 0x18))(this,param_1);
  return 1;
}


/* __thiscall TObject::do_begin(void) */

void __thiscall TObject::do_begin(TObject *this)

{
  return;
}


/* __thiscall TObject::do_end(void) */

void __thiscall TObject::do_end(TObject *this)

{
  return;
}


/* __thiscall TObject::do_paragraph(unsigned long,
                                                  void const *,
                                                  unsigned long) */

void __thiscall
TObject::do_paragraph(TObject *this,ulong param_1,void *param_2,ulong param_3)

{
  return;
}


/* __thiscall TObject::do_wait(unsigned long) */

void __thiscall TObject::do_wait(TObject *this,ulong param_1)

{
  return;
}


/* __thiscall TObject::do_data(void const *,
                                             unsigned long,
                                             void const *,
                                             unsigned long) */

void __thiscall
TObject::do_data
          (TObject *this,void *param_1,ulong param_2,void *param_3,ulong param_4)

{
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TObject::process_sequence_(void) */

void __thiscall TObject::process_sequence_(TObject *this)

{
  TParse_TParagraph local_38 [4];
  TObject local_34;
  uint local_30;
  ulong local_2c;
  void *local_28;
  undefined *local_24;
  TData local_20 [4];
  undefined *local_1c;
  undefined *local_18;
  undefined *local_14;
  
  local_34 = this[9].vtbl;
  data::TParse_TSequence::getData((TParse_TSequence *)&local_34,local_20);
  this[10].vtbl = local_14;
  if (local_20[0] == (TData)0x3) {
    if (((uint)local_1c & 0x800000) != 0) {
      local_1c = (undefined *)((uint)local_1c | _gu32Mask_TSequence_value_signExpansion);
    }
    this[10].vtbl = this[9].vtbl + (int)local_1c;
  }
  else {
    if ((byte)local_20[0] < 3) {
      if (local_20[0] == (TData)0x1) {
        setFlag_operation(this,(uchar)((uint)local_1c >> 0x10),(uint)local_1c & 0xffff);
      }
      else {
        if (local_20[0] != (TData)0x0) {
          this[0xb].vtbl = local_1c;
        }
      }
    }
    else {
      if (local_20[0] == (TData)0x80) {
        while (local_18 < local_14) {
          data::TParse_TParagraph::getData(local_38,(TData *)&local_30);
          if (local_30 < 0x100) {
            process_paragraph_reserved_(this,local_30,local_28,local_2c);
            local_18 = local_24;
          }
          else {
            (**(code **)(this[2].vtbl + 0x14))(this,local_30,local_28,local_2c);
            local_18 = local_24;
          }
        }
      }
      else {
        if (((byte)local_20[0] < 0x80) && ((byte)local_20[0] < 5)) {
          if (((uint)local_1c & 0x800000) != 0) {
            local_1c = (undefined *)((uint)local_1c | _gu32Mask_TSequence_value_signExpansion);
          }
          this[8].vtbl = this[8].vtbl + (int)local_1c;
        }
      }
    }
  }
  return;
}


/* __thiscall TObject::process_paragraph_reserved_(unsigned long,
                                                                 void const *,
                                                                 unsigned long) */

void __thiscall
TObject::process_paragraph_reserved_
          (TObject *this,ulong param_1,void *param_2,ulong param_3)

{
  int iVar1;
  
  if (param_1 == 0x80) {
    (**(code **)(this[2].vtbl + 0x1c))(this,0,0,param_2);
  }
  else {
    if ((int)param_1 < 0x80) {
      if (param_1 == 2) {
                    /* WARNING: Load size is inaccurate */
        this[0xb].vtbl = *param_2;
      }
      else {
        if ((int)param_1 < 2) {
          if (0 < (int)param_1) {
                    /* WARNING: Load size is inaccurate */
            setFlag_operation(this,(uchar)(*param_2 >> 0x10),*param_2 & 0xffff);
          }
        }
        else {
          if ((int)param_1 < 4) {
                    /* WARNING: Load size is inaccurate */
            this[10].vtbl = this[9].vtbl + *param_2;
          }
        }
      }
    }
    else {
      if ((param_1 != 0x82) && ((int)param_1 < 0x82)) {
        iVar1 = (int)param_2 + (*(ushort *)((int)param_2 + 2) + 3 & 0xfffffffc) + 4;
        (**(code **)(this[2].vtbl + 0x1c))
                  (this,(int)param_2 + 4,(uint)*(ushort *)((int)param_2 + 2),iVar1,
                   param_3 - (iVar1 - (int)param_2));
      }
    }
  }
  return;
}


/* __thiscall TObject_control::TObject_control(void const *,
                                                             unsigned long) */

void __thiscall
TObject_control::TObject_control(TObject_control *this,void *param_1,ulong param_2)

{
  TObject::TObject((TObject *)this,0xffffffff,param_1,param_2);
  *(undefined1 **)(this + 8) = &__vt;
  return;
}


/* __thiscall TControl::TControl(void) */

void __thiscall TControl::TControl(TControl *this)

{
  *(undefined1 **)this = &__vt;
  *(undefined4 *)&this->field_0x4 = 0;
  *(undefined4 *)&this->field_0x8 = 0;
  *(undefined4 *)&this->field_0xc = 0;
  *(undefined4 *)&this->field_0x14 = 0;
  *(undefined4 *)&this->field_0x18 = 0;
  *(undefined4 *)&this->field_0x10 = 0;
  *(int *)&this->field_0x14 = &this->field_0x14;
  *(int *)&this->field_0x18 = &this->field_0x14;
  TObject_control::TObject_control((TObject_control *)&this->mObject,(void *)0x0,0);
  this->field_0x54 = 0;
  *(undefined4 *)&this->field_0x1c = 0;
  *(TControl **)&this->field_0x34 = this;
  return;
}


/* __thiscall TObject_control::~TObject_control(void) */

void __thiscall TObject_control::_TObject_control(TObject_control *this)

{
  short in_r4;
  
  if (this != (TObject_control *)0x0) {
    *(undefined1 **)(this + 8) = &__vt;
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TControl::~TControl(void) */

void __thiscall TControl::_TControl(TControl *this)

{
  short in_r4;
  
  if (this != (TControl *)0x0) {
    *(undefined1 **)this = &__vt;
    *(undefined4 *)&this->field_0x34 = 0;
    if (this != (TControl *)0xffffffe0) {
      *(undefined1 **)&this->field_0x28 = &TObject_control::__vt;
      TObject::_TObject(&this->mObject);
    }
    if (this != (TControl *)0xfffffff0) {
      ::JGadget::TNodeLinkList::_TNodeLinkList((TNodeLinkList *)&this->field_0x10);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TControl::appendObject(TObject *) */

void __thiscall TControl::appendObject(TControl *this,TObject *param_1)

{
  TNodeLinkList aTStack16 [4];
  int local_c;
  int local_8;
  int local_4;
  
  param_1[5].vtbl = (undefined *)this;
  local_c = &this->field_0x14;
  local_8 = local_c;
  local_4 = local_c;
  ::JGadget::TNodeLinkList::Insert(aTStack16,&this->field_0x10,(TLinkListNode *)&local_c);
  return;
}


/* __thiscall TControl::removeObject(TObject *) */

void __thiscall TControl::removeObject(TControl *this,TObject *param_1)

{
  TNodeLinkList aTStack8 [8];
  
  param_1[5].vtbl = (undefined *)0x0;
  ::JGadget::TNodeLinkList::Erase(aTStack8,(TLinkListNode *)&this->field_0x10);
  return;
}


/* __thiscall TControl::destroyObject(TObject *) */

void __thiscall TControl::destroyObject(TControl *this,TObject *param_1)

{
  removeObject(this,param_1);
  (**(code **)(**(int **)&this->field_0xc + 0x10))(*(int **)&this->field_0xc,param_1);
  return;
}


/* __thiscall TControl::destroyObject_all(void) */

void __thiscall TControl::destroyObject_all(TControl *this)

{
  while (*(int *)&this->field_0x10 != 0) {
    destroyObject(this,(TObject *)(*(int *)&this->field_0x18 + -0xc));
  }
  return;
}


/* __thiscall TControl::getObject(void const *,
                                                unsigned long) */

int __thiscall TControl::getObject(TControl *this,void *param_1,ulong param_2)

{
  uint uVar1;
  int local_28;
  undefined4 local_24;
  int local_20 [2];
  int local_18;
  undefined4 local_14;
  void *local_10;
  ulong local_c;
  
  local_24 = *(undefined4 *)&this->field_0x14;
  local_28 = &this->field_0x14;
  local_18 = local_28;
  local_14 = local_24;
  local_10 = param_1;
  local_c = param_2;
  ::std::find_if((std *)local_20,(iterator)&local_24,(iterator)&local_28,
                 (TPRObject_ID_equal)&local_10);
  uVar1 = countLeadingZeros(local_18 - local_20[0]);
  uVar1 = countLeadingZeros(uVar1 >> 5 & 0xff);
  if ((uVar1 >> 5 & 0xff) == 0) {
    local_20[0] = 0;
  }
  else {
    local_20[0] = local_20[0] + -0xc;
  }
  return local_20[0];
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall TControl::forward(unsigned long) */

uint __thiscall TControl::forward(TControl *this,ulong param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *local_28;
  
  this->field_0x54 = *(int *)&this->field_0x40;
  uVar3 = TObject::forward(&this->mObject,param_1);
  uVar6 = 0xf;
  uVar5 = 0;
  local_28 = *(undefined4 **)&this->field_0x14;
  while( true ) {
    uVar2 = countLeadingZeros((int)this + (0x14 - (int)local_28));
    if ((uVar2 >> 5 & 0xff) != 0) break;
    puVar1 = (undefined4 *)*local_28;
    cVar4 = TObject::forward((TObject *)(local_28 + -3),param_1);
    if ((cVar4 != '\0') || (uVar2 = uVar3 & 0xff, uVar3 = 0, uVar2 != 0)) {
      uVar3 = 1;
    }
    uVar6 = uVar6 & local_28[9];
    uVar5 = uVar5 | local_28[9];
    local_28 = puVar1;
  }
  *(uint *)&this->field_0x1c = uVar6 | uVar5 << 0x10;
  return uVar3;
}


/* __thiscall TFactory::~TFactory(void) */

void __thiscall TFactory::_TFactory(TFactory *this)

{
  short in_r4;
  
  if ((this != (TFactory *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall TFactory::create(data::TParse_TBlock_object const &) */

undefined4 __thiscall TFactory::create(TFactory *this,TParse_TBlock_object *param_1)

{
  return 0;
}


/* __thiscall TFactory::destroy(TObject *) */

TFactory * __thiscall TFactory::destroy(TFactory *this,TObject *param_1)

{
  if (param_1 != (TObject *)0x0) {
    this = (TFactory *)(**(code **)(param_1[2].vtbl + 8))(param_1,1);
  }
  return this;
}


/* __thiscall TParse::TParse(TControl *) */

void __thiscall TParse::TParse(TParse *this,TControl *param_1)

{
  this->vtbl = &::JGadget::binary::TParse_header_block::__vt;
  this->vtbl = &__vt;
  this->mpControl = param_1;
  return;
}


/* __thiscall TParse::~TParse(void) */

void __thiscall TParse::_TParse(TParse *this)

{
  short in_r4;
  
  if (this != (TParse *)0x0) {
    this->vtbl = &__vt;
    ::JGadget::binary::TParse_header_block::_TParse_header_block((TParse_header_block *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TParse::parseHeader_next(void const * *,
                                                     unsigned long *,
                                                     unsigned long) */

undefined4 __thiscall
TParse::parseHeader_next(TParse *this,void **ppData,ulong *param_2,ulong size)

{
  int iVar1;
  undefined4 uVar2;
  char *pData;
  
  pData = (char *)*ppData;
  *ppData = pData + 0x20;
  *param_2 = *(ulong *)(pData + 0xc);
  iVar1 = MSL_C.PPCEABI.bare.H::memcmp(pData,"STB",4);
  if (iVar1 == 0) {
    if (*(short *)(pData + 4) == -0x101) {
      if (*(ushort *)(pData + 6) == 0) {
        uVar2 = 0;
      }
      else {
        if (*(ushort *)(pData + 6) < 4) {
          uVar2 = (**(code **)(this->vtbl + 0x14))(this,&pData,size);
        }
        else {
          uVar2 = 0;
        }
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __thiscall TParse::parseBlock_next(void const * *,
                                                    unsigned long *,
                                                    unsigned long) */

void __thiscall
TParse::parseBlock_next(TParse *this,void **param_1,ulong *param_2,ulong param_3)

{
  ulong *local_8 [2];
  
  local_8[0] = (ulong *)*param_1;
  *param_1 = (void *)((int)local_8[0] + *local_8[0]);
  *param_2 = *local_8[0];
  (**(code **)(this->vtbl + 0x18))(this,local_8,param_3);
  return;
}


/* __thiscall TParse::parseHeader(data::TParse_THeader const &,
                                                unsigned long) */

undefined4 __thiscall
TParse::parseHeader(TParse *this,TParse_THeader *param_1,ulong param_2)

{
  return 1;
}


/* __thiscall TParse::parseBlock_block(data::TParse_TBlock const &,
                                                     unsigned long) */

void __thiscall
TParse::parseBlock_block(TParse *this,TParse_TBlock *param_1,ulong param_2)

{
  undefined4 local_8 [2];
  
  local_8[0] = *(undefined4 *)param_1;
  (**(code **)(this->vtbl + 0x1c))(this,local_8);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TParse::parseBlock_object(data::TParse_TBlock_object const
   &,
                                                      unsigned long) */

uint __thiscall
TParse::parseBlock_object(TParse *this,TParse_TBlock_object *param_1,ulong param_2)

{
  uint uVar1;
  TObject *pTVar2;
  int *piVar3;
  int iVar4;
  TControl *this_00;
  
  this_00 = this->mpControl;
  iVar4 = *(int *)param_1;
  if (*(int *)(iVar4 + 4) == -1) {
    TObject::reset(&this_00->mObject,
                   (void *)(iVar4 + (*(ushort *)(iVar4 + 10) + 3 & 0xfffffffc) + 0xc));
    uVar1 = 1;
  }
  else {
    if (((param_2 & 0x10) != 0) &&
       (pTVar2 = (TObject *)
                 TControl::getObject(this_00,(void *)(iVar4 + 0xc),(uint)*(ushort *)(iVar4 + 10)),
       pTVar2 != (TObject *)0x0)) {
      TObject::reset(pTVar2,(void *)(*(int *)param_1 +
                                    (*(ushort *)(*(int *)param_1 + 10) + 3 & 0xfffffffc) + 0xc));
      return 1;
    }
    if ((param_2 & 0x20) == 0) {
      piVar3 = *(int **)&this_00->field_0xc;
      if (piVar3 == (int *)0x0) {
        uVar1 = 0;
      }
      else {
        pTVar2 = (TObject *)(**(code **)(*piVar3 + 0xc))(piVar3,param_1);
        if (pTVar2 == (TObject *)0x0) {
          uVar1 = param_2 >> 6 & 1;
        }
        else {
          TControl::appendObject(this_00,pTVar2);
          uVar1 = 1;
        }
      }
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

}
}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall
   std::find_if<JGadget::TLinkList<Q37JStudio3stb7TObject,-12>::iterator,JStudio::object::TPRObject_ID_equal>(JGadget::TLinkList<Q37JStudio3stb7TObject,-12>::iterator,
   
   JGadget::TLinkList<Q37JStudio3stb7TObject,-12>::iterator,
   
   JStudio::object::TPRObject_ID_equal) */

void __thiscall std::find_if(std *this,iterator param_1,iterator param_2,TPRObject_ID_equal param_3)

{
  uint uVar1;
  char cVar2;
  TIDData *pTVar3;
  
  pTVar3 = (TIDData *)param_2;
  while( true ) {
    uVar1 = countLeadingZeros(*(int *)param_2 - *(int *)param_1);
    if ((uVar1 >> 5 & 0xff) != 0) break;
    cVar2 = JStudio::object::TIDData::isEqual
                      ((TIDData *)(*(int *)param_1 + -0xc),(TIDData *)param_3,pTVar3);
    if (cVar2 != '\0') break;
    *(undefined4 *)param_1 = **(undefined4 **)param_1;
  }
  *(undefined4 *)this = *(undefined4 *)param_1;
  return;
}

