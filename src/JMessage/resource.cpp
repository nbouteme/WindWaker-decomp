#include <JMessage/resource.h>
#include <JMessage/resource.h>
#include <JKernel/JKRHeap.h>
#include <JGadget/binary.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <MSL_C.PPCEABI.bare.H/mem.h>
#include <JGadget/linklist.h>
#include <Demangler/JMessage/TParse.h>
#include <JUTFont.h>
#include <JMessage/TResourceContainer.h>


namespace JMessage {

namespace TParse {
}

/* __thiscall TResourceContainer::TResourceContainer(void) */

void __thiscall TResourceContainer::TResourceContainer(TResourceContainer *this)

{
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)this = 0;
  *(TResourceContainer **)(this + 4) = this + 4;
  *(TResourceContainer **)(this + 8) = this + 4;
  *(undefined1 **)(this + 0xc) = &JGadget::TLinkList_factory<TResource,0>::__vt;
  *(undefined1 **)(this + 0xc) = &__vt;
  this[0x10] = (TResourceContainer)0x0;
  *(undefined4 *)(this + 0x14) = 0;
  return;
}


/* __thiscall TResourceContainer::Get_groupID(unsigned short) */

undefined4 * __thiscall
TResourceContainer::Get_groupID(TResourceContainer *this,ushort param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *local_8;
  
  puVar1 = *(undefined4 **)(this + 4);
  do {
    local_8 = puVar1;
    uVar2 = countLeadingZeros(this + (4 - (int)local_8));
    if ((uVar2 >> 5 & 0xff) != 0) {
      return (undefined4 *)0x0;
    }
    puVar1 = (undefined4 *)*local_8;
  } while (param_1 != *(ushort *)(local_8[3] + 0xc));
  return local_8;
}


/* __thiscall TResourceContainer::SetEncoding(unsigned char) */

void __thiscall TResourceContainer::SetEncoding(TResourceContainer *this,uchar param_1)

{
  if (param_1 == '\0') {
    this[0x10] = (TResourceContainer)0x0;
    *(undefined4 *)(this + 0x14) = 0;
  }
  else {
    SetEncoding_(this,param_1);
  }
  return;
}


/* __thiscall TResourceContainer::Do_create(void) */

void __thiscall TResourceContainer::Do_create(TResourceContainer *this)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)JKernel::operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
  }
  return;
}


/* __thiscall TResourceContainer::Do_destroy(TResource *) */

void __thiscall
TResourceContainer::Do_destroy(TResourceContainer *this,TResource *param_1)

{
  JKernel::operator_delete((JKRHeap *)param_1);
  return;
}


/* __thiscall TResourceContainer::SetEncoding_(unsigned char) */

void __thiscall TResourceContainer::SetEncoding_(TResourceContainer *this,uchar param_1)

{
  this[0x10] = (TResourceContainer)param_1;
  *(undefined4 *)(this + 0x14) = 0;
  if (3 < param_1) {
    return;
  }
  *(undefined4 *)(this + 0x14) =
       *(undefined4 *)(&@unnamed@resource_cpp@::gapfnIsLeadByte_ + (uint)param_1 * 4);
  return;
}


/* __thiscall TParse::TParse(TResourceContainer *) */

void __thiscall TParse::TParse(TParse *this,TResourceContainer *param_1)

{
  *(undefined1 **)this = &JGadget::binary::TParse_header_block::__vt;
  *(undefined1 **)this = &__vt;
  *(TResourceContainer **)(this + 4) = param_1;
  *(undefined4 *)(this + 8) = 0;
  return;
}


/* __thiscall TParse::~TParse(void) */

void __thiscall TParse::_TParse(TParse *this)

{
  short in_r4;
  
  if (this != (TParse *)0x0) {
    *(undefined1 **)this = &__vt;
    JGadget::binary::TParse_header_block::_TParse_header_block((TParse_header_block *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TParse::parseHeader_next(void const * *,
                                                 unsigned long *,
                                                 unsigned long) */

uint __thiscall
TParse::parseHeader_next(TParse *this,void **param_1,ulong *param_2,ulong param_3)

{
  TResourceContainer TVar1;
  TResourceContainer TVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  void *__s1;
  TNodeLinkList aTStack32 [4];
  int local_1c;
  int local_18;
  int local_14;
  
  __s1 = *param_1;
  *param_1 = (void *)((int)__s1 + 0x20);
  *param_2 = *(ulong *)((int)__s1 + 0xc);
  iVar4 = MSL_C.PPCEABI.bare.H::memcmp(__s1,&data::ga4cSignature,4);
  if (iVar4 == 0) {
    if (*(int *)((int)__s1 + 4) == 0x626d6731) {
      TVar1 = *(TResourceContainer *)((int)__s1 + 0x10);
      if (TVar1 != (TResourceContainer)0x0) {
        bVar3 = false;
        TVar2 = (*(TResourceContainer **)(this + 4))[0x10];
        if ((TVar2 == TVar1) || (TVar2 == (TResourceContainer)0x0)) {
          bVar3 = true;
        }
        if (!bVar3) {
          return 0;
        }
        TResourceContainer::SetEncoding(*(TResourceContainer **)(this + 4),(uchar)TVar1);
      }
      if ((param_3 & 0x10) == 0) {
        uVar6 = (**(code **)(*(int *)(*(int *)(this + 4) + 0xc) + 0xc))();
        *(undefined4 *)(this + 8) = uVar6;
        if (*(int *)(this + 8) == 0) {
          uVar5 = param_3 >> 5 & 1;
        }
        else {
          *(void **)(*(int *)(this + 8) + 8) = __s1;
          local_1c = *(iterator *)(this + 4) + 4;
          local_18 = local_1c;
          local_14 = local_1c;
          JGadget::TNodeLinkList::Insert
                    (aTStack32,*(iterator *)(this + 4),(TLinkListNode *)&local_1c);
          uVar5 = 1;
        }
      }
      else {
        uVar5 = 1;
      }
    }
    else {
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TParse::parseBlock_next(void const * *,
                                                unsigned long *,
                                                unsigned long) */

undefined4 __thiscall
TParse::parseBlock_next(TParse *this,void **param_1,ulong *param_2,ulong param_3)

{
  int iVar1;
  TLinkListNode *pTVar2;
  TNodeLinkList aTStack40 [8];
  int *local_20;
  
  local_20 = (int *)*param_1;
  *param_1 = (void *)((int)local_20 + local_20[1]);
  *param_2 = local_20[1];
  iVar1 = *local_20;
  if (iVar1 == 0x4d494431) {
    *(int **)(*(int *)(this + 8) + 0x18) = local_20;
    return 1;
  }
  if (iVar1 < 0x4d494431) {
    if (iVar1 == 0x494e4631) {
      *(int **)(*(int *)(this + 8) + 0xc) = local_20;
      return 1;
    }
    if ((iVar1 < 0x494e4631) && (iVar1 == 0x44415431)) {
      *(int **)(*(int *)(this + 8) + 0x10) = local_20 + 2;
      iVar1 = TResourceContainer::Get_groupID
                        (*(TResourceContainer **)(this + 4),
                         *(ushort *)(*(int *)(*(int *)(this + 8) + 0xc) + 0xc));
      if (iVar1 == *(int *)(this + 8)) {
        return 1;
      }
      if ((param_3 & 0x80) == 0) {
        return 1;
      }
      pTVar2 = *(TLinkListNode **)(this + 4);
      JGadget::TNodeLinkList::Erase(aTStack40,pTVar2);
      (**(code **)(*(int *)(pTVar2 + 0xc) + 0x10))(pTVar2,iVar1);
      return 1;
    }
  }
  else {
    if (iVar1 == 0x53545231) {
      *(int **)(*(int *)(this + 8) + 0x14) = local_20 + 2;
      return 1;
    }
  }
  if ((param_3 & 0x40) != 0) {
    return 1;
  }
  return 0;
}

}

/* __thiscall JUTFont::isLeadByte_1Byte(int) */

undefined4 __thiscall JUTFont::isLeadByte_1Byte(JUTFont *this,int param_1)

{
  return 0;
}


/* __thiscall JUTFont::isLeadByte_2Byte(int) */

undefined4 __thiscall JUTFont::isLeadByte_2Byte(JUTFont *this,int param_1)

{
  return 1;
}


/* __thiscall JUTFont::isLeadByte_ShiftJIS(int) */

undefined4 __thiscall JUTFont::isLeadByte_ShiftJIS(JUTFont *this,int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((0x80 < (int)this) && ((int)this < 0xa0)) || ((0xdf < (int)this && ((int)this < 0xfd)))) {
    uVar1 = 1;
  }
  return uVar1;
}

