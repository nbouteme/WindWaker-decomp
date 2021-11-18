#include <JKernel/JKRExpHeap.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRExpHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <os/OSMutex.h>
#include <JUtility/JUTConsole.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <Demangler/JKRExpHeap/CMemBlock.h>
#include <Demangler/JKRExpHeap.h>


namespace JKRExpHeap {
}

namespace JKernel {
undefined4 DBfoundSize;
undefined4 DBfoundOffset;
undefined4 DBfoundBlock;
undefined4 DBnewFreeBlock;
undefined4 DBnewUsedBlock;
}

/* __thiscall JKRExpHeap::createRoot(int,
                                     bool) */

void __thiscall JKRExpHeap::createRoot(JKRExpHeap *this,int param_1,bool param_2)

{
  JKRExpHeap *pJVar1;
  JKRExpHeap *pJVar2;
  ulong local_18;
  JKRExpHeap *local_14 [4];
  
  pJVar2 = (JKRExpHeap *)0x0;
  pJVar1 = (JKRExpHeap *)JKRHeap::sRootHeap;
  if (JKRHeap::sRootHeap == (JKRHeap *)0x0) {
    JKRHeap::initArena((char **)local_14,&local_18,(int)this);
    pJVar2 = local_14[0];
    pJVar1 = local_14[0];
    if (local_14[0] != (JKRExpHeap *)0x0) {
      JKRExpHeap(local_14[0],local_14[0] + 1,local_18 - 0x90,(JKRHeap *)0x0,SUB41(param_1,0));
      pJVar2 = local_14[0];
      pJVar1 = local_14[0];
    }
  }
  JKRHeap::sRootHeap = &pJVar1->parent;
  pJVar2->field_0x6e = 1;
  return;
}


namespace JKRExpHeap {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall create(unsigned long,
                                 JKRHeap *,
                                 bool) */

JKRExpHeap * create(ulong param_1,JKRHeap *param_2,bool param_3)

{
  uint size;
  JKRExpHeap *pJVar1;
  JKRExpHeap *this;
  
  if (param_2 == (JKRHeap *)0x0) {
    param_2 = JKRHeap::sRootHeap;
  }
  if (param_1 == 0xffffffff) {
    param_1 = JKRHeap::getMaxAllocatableSize(param_2,0x10);
  }
  size = param_1 & 0xfffffff0;
  if (size < 0xa0) {
    pJVar1 = (JKRExpHeap *)0x0;
  }
  else {
    this = (JKRExpHeap *)JKRHeap::alloc(size,0x10,param_2);
    if (this != (JKRExpHeap *)0x0) {
      pJVar1 = this;
      if (this != (JKRExpHeap *)0x0) {
        JKRExpHeap(this,this + 1,size - 0x90,param_2,param_3);
      }
      if (pJVar1 == (JKRExpHeap *)0x0) {
        JKRHeap::free(this,(JKRHeap *)0x0);
        pJVar1 = (JKRExpHeap *)0x0;
      }
      else {
        pJVar1->field_0x6e = 0;
      }
    }
    else {
      pJVar1 = (JKRExpHeap *)0x0;
    }
  }
  return pJVar1;
}

}

/* __thiscall JKRExpHeap::do_destroy(void) */

void __thiscall JKRExpHeap::do_destroy(JKRExpHeap *this)

{
  JKRHeap *pJVar1;
  
  if (this->field_0x6e == 0) {
    pJVar1 = (JKRHeap *)(this->parent).mChildHeapLink.mpList[1].mpHead;
    if (pJVar1 != (JKRHeap *)0x0) {
      (*(code *)((this->parent).vtbl)->_)(this,0xffffffff);
      JKRHeap::free(this,pJVar1);
    }
  }
  else {
    (*(code *)((this->parent).vtbl)->_)(this,0xffffffff);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRExpHeap::JKRExpHeap(void *,
                                     unsigned long,
                                     JKRHeap *,
                                     bool) */

void __thiscall
JKRExpHeap::JKRExpHeap(JKRExpHeap *this,void *param_1,ulong param_2,JKRHeap *param_3,bool param_4)

{
  JKRHeap::JKRHeap(&this->parent,param_1,param_2,param_3,param_4);
  (this->parent).vtbl = (JKRHeap__vtbl *)&__vt;
  this->field_0x6c = 0;
  *(undefined *)&this->field_0x6d = 0xff;
  this->field_0x78 = (undefined *)param_1;
  this->field_0x7c = this->field_0x78;
  CMemBlock::initiate((CMemBlock *)this->field_0x78,(CMemBlock *)0x0,(CMemBlock *)0x0,param_2 - 0x10
                      ,'\0','\0');
  this->field_0x80 = (undefined *)0x0;
  this->field_0x84 = (undefined *)0x0;
  return;
}


/* __thiscall JKRExpHeap::~JKRExpHeap(void) */

void __thiscall JKRExpHeap::_JKRExpHeap(JKRExpHeap *this)

{
  short in_r4;
  
  if (this != (JKRExpHeap *)0x0) {
    (this->parent).vtbl = (JKRHeap__vtbl *)&__vt;
    JKRHeap::dispose(&this->parent);
    JKRHeap::_JKRHeap(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete(&this->parent);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRExpHeap::do_alloc(unsigned long,
                                   int) */

int __thiscall JKRExpHeap::do_alloc(JKRExpHeap *this,ulong param_1,int param_2)

{
  int iVar1;
  
  os::OSLockMutex(&(this->parent).mMutex);
  if (param_1 < 4) {
    param_1 = 4;
  }
  if (param_2 < 0) {
    if (-param_2 < 5) {
      iVar1 = allocFromTail(this,param_1);
    }
    else {
      iVar1 = allocFromTail(this,param_1,-param_2);
    }
  }
  else {
    if (param_2 < 5) {
      iVar1 = allocFromHead(this,param_1);
    }
    else {
      iVar1 = allocFromHead(this,param_1,param_2);
    }
  }
  if (((iVar1 == 0) &&
      (JUtility::JUTWarningConsole_f(":::cannot alloc memory (0x%x byte).\n",param_1),
      (this->parent).mbReportErrors == true)) && (JKRHeap::mErrorHandler != (undefined *)0x0)) {
    (*(code *)JKRHeap::mErrorHandler)(this,param_1,param_2);
  }
  os::OSUnlockMutex(&(this->parent).mMutex);
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall JKRExpHeap::allocFromHead(unsigned long,
                                        int) */

CMemBlock * __thiscall JKRExpHeap::allocFromHead(JKRExpHeap *this,ulong param_1,int param_2)

{
  uint uVar1;
  CMemBlock *pCVar2;
  CMemBlock *pCVar3;
  uint uVar4;
  CMemBlock *pCVar5;
  uint uVar6;
  CMemBlock *pCVar7;
  uint uVar8;
  CMemBlock *pCVar9;
  
  uVar1 = param_1 + 3 & 0xfffffffc;
  uVar4 = 0xffffffff;
  uVar8 = 0;
  pCVar9 = (CMemBlock *)0x0;
  for (pCVar5 = (CMemBlock *)this->field_0x78; JKernel::DBfoundSize = uVar4, uVar6 = uVar8,
      pCVar5 != (CMemBlock *)0x0; pCVar5 = *(CMemBlock **)(pCVar5 + 0xc)) {
    uVar6 = (~(param_2 - 1U) & (uint)(pCVar5 + 0x10 + (param_2 - 1U))) - (int)(pCVar5 + 0x10);
    JKernel::DBfoundSize = *(uint *)(pCVar5 + 4);
    if (((uVar1 + uVar6 <= JKernel::DBfoundSize) && (JKernel::DBfoundSize < uVar4)) &&
       ((pCVar9 = pCVar5, this->field_0x6c != 0 ||
        (uVar4 = JKernel::DBfoundSize, uVar8 = uVar6, JKernel::DBfoundSize == uVar1)))) break;
  }
  JKernel::DBfoundOffset = uVar6;
  JKernel::DBfoundBlock = pCVar9;
  if (pCVar9 == (CMemBlock *)0x0) {
    pCVar5 = (CMemBlock *)0x0;
  }
  else {
    if (uVar6 < 0x10) {
      if (uVar6 == 0) {
        pCVar2 = *(CMemBlock **)(pCVar9 + 8);
        pCVar7 = *(CMemBlock **)(pCVar9 + 0xc);
        pCVar5 = (CMemBlock *)
                 CMemBlock::allocFore(pCVar9,uVar1,*(uchar *)&this->field_0x6d,'\0','\0','\0');
        removeFreeBlock(this,pCVar9);
        if (pCVar5 != (CMemBlock *)0x0) {
          setFreeBlock(this,pCVar5,pCVar2,pCVar7);
        }
        appendUsedList(this,pCVar9);
        pCVar5 = pCVar9 + 0x10;
      }
      else {
        pCVar2 = *(CMemBlock **)(pCVar9 + 8);
        pCVar7 = *(CMemBlock **)(pCVar9 + 0xc);
        removeFreeBlock(this,pCVar9);
        pCVar5 = pCVar9 + uVar6;
        *(uint *)(pCVar5 + 4) = *(int *)(pCVar9 + 4) - uVar6;
        pCVar9 = (CMemBlock *)
                 CMemBlock::allocFore
                           (pCVar5,uVar1,*(uchar *)&this->field_0x6d,(uchar)uVar6,'\0','\0');
        if (pCVar9 != (CMemBlock *)0x0) {
          setFreeBlock(this,pCVar9,pCVar2,pCVar7);
        }
        appendUsedList(this,pCVar5);
        pCVar5 = pCVar5 + 0x10;
      }
    }
    else {
      pCVar7 = *(CMemBlock **)(pCVar9 + 8);
      pCVar5 = *(CMemBlock **)(pCVar9 + 0xc);
      pCVar2 = (CMemBlock *)CMemBlock::allocFore(pCVar9,uVar6 - 0x10,'\0','\0','\0','\0');
      if (pCVar2 == (CMemBlock *)0x0) {
        pCVar3 = (CMemBlock *)0x0;
      }
      else {
        pCVar3 = (CMemBlock *)
                 CMemBlock::allocFore(pCVar2,uVar1,*(uchar *)&this->field_0x6d,'\0','\0','\0');
      }
      if (pCVar3 == (CMemBlock *)0x0) {
        setFreeBlock(this,pCVar9,pCVar7,pCVar5);
      }
      else {
        setFreeBlock(this,pCVar9,pCVar7,pCVar3);
        setFreeBlock(this,pCVar3,pCVar9,pCVar5);
      }
      appendUsedList(this,pCVar2);
      pCVar5 = pCVar2 + 0x10;
      JKernel::DBnewFreeBlock = pCVar3;
      JKernel::DBnewUsedBlock = pCVar2;
    }
  }
  return pCVar5;
}


/* __thiscall JKRExpHeap::allocFromHead(unsigned long) */

CMemBlock * __thiscall JKRExpHeap::allocFromHead(JKRExpHeap *this,ulong param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  CMemBlock *pCVar4;
  CMemBlock *pCVar5;
  
  uVar1 = param_1 + 3 & 0xfffffffc;
  uVar3 = 0xffffffff;
  pCVar5 = (CMemBlock *)0x0;
  for (pCVar4 = (CMemBlock *)this->field_0x78;
      (pCVar4 != (CMemBlock *)0x0 &&
      (((uVar2 = *(uint *)(pCVar4 + 4), uVar2 < uVar1 || (uVar3 <= uVar2)) ||
       ((pCVar5 = pCVar4, this->field_0x6c == 0 && (uVar3 = uVar2, uVar2 != uVar1))))));
      pCVar4 = *(CMemBlock **)(pCVar4 + 0xc)) {
  }
  if (pCVar5 == (CMemBlock *)0x0) {
    pCVar5 = (CMemBlock *)0x0;
  }
  else {
    pCVar4 = (CMemBlock *)
             CMemBlock::allocFore(pCVar5,uVar1,*(uchar *)&this->field_0x6d,'\0','\0','\0');
    if (pCVar4 == (CMemBlock *)0x0) {
      removeFreeBlock(this,pCVar5);
    }
    else {
      setFreeBlock(this,pCVar4,*(CMemBlock **)(pCVar5 + 8),*(CMemBlock **)(pCVar5 + 0xc));
    }
    appendUsedList(this,pCVar5);
    pCVar5 = pCVar5 + 0x10;
  }
  return pCVar5;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRExpHeap::allocFromTail(unsigned long,
                                        int) */

CMemBlock * __thiscall JKRExpHeap::allocFromTail(JKRExpHeap *this,ulong param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  CMemBlock *pCVar3;
  ulong unaff_r28;
  CMemBlock *pCVar4;
  CMemBlock *pCVar5;
  uint uVar6;
  
  uVar6 = 0;
  pCVar4 = (CMemBlock *)0x0;
  pCVar3 = (CMemBlock *)this->field_0x7c;
  do {
    pCVar5 = (CMemBlock *)0x0;
    if (pCVar3 == (CMemBlock *)0x0) {
LAB_802b1cdc:
      if (pCVar5 == (CMemBlock *)0x0) {
        pCVar4 = (CMemBlock *)0x0;
      }
      else {
        if (uVar6 < 0x10) {
          if (uVar6 == 0) {
            removeFreeBlock(this,pCVar5);
            CMemBlock::initiate(pCVar4,(CMemBlock *)0x0,(CMemBlock *)0x0,unaff_r28,
                                *(uchar *)&this->field_0x6d,0x80);
            appendUsedList(this,pCVar4);
            pCVar4 = pCVar4 + 0x10;
          }
          else {
            removeFreeBlock(this,pCVar5);
            CMemBlock::initiate(pCVar4,(CMemBlock *)0x0,(CMemBlock *)0x0,unaff_r28,
                                *(uchar *)&this->field_0x6d,(byte)uVar6 | 0x80);
            appendUsedList(this,pCVar4);
            pCVar4 = pCVar4 + 0x10;
          }
        }
        else {
          CMemBlock::initiate(pCVar4,(CMemBlock *)0x0,(CMemBlock *)0x0,unaff_r28,
                              *(uchar *)&this->field_0x6d,0x80);
          *(ulong *)(pCVar5 + 4) = (*(int *)(pCVar5 + 4) - unaff_r28) + -0x10;
          appendUsedList(this,pCVar4);
          pCVar4 = pCVar4 + 0x10;
        }
      }
      return pCVar4;
    }
    uVar1 = *(uint *)(pCVar3 + 4);
    uVar2 = ~(param_2 - 1U) & (int)(pCVar3 + uVar1 + 0x10) - param_1;
    unaff_r28 = (int)(pCVar3 + uVar1 + 0x10) - uVar2;
    if (unaff_r28 <= uVar1) {
      uVar6 = uVar1 - unaff_r28;
      pCVar4 = (CMemBlock *)(uVar2 - 0x10);
      pCVar5 = pCVar3;
      goto LAB_802b1cdc;
    }
    pCVar3 = *(CMemBlock **)(pCVar3 + 8);
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRExpHeap::allocFromTail(unsigned long) */

CMemBlock * __thiscall JKRExpHeap::allocFromTail(JKRExpHeap *this,ulong param_1)

{
  uint uVar1;
  CMemBlock *pCVar2;
  CMemBlock *pCVar3;
  CMemBlock *this_00;
  
  uVar1 = param_1 + 3 & 0xfffffffc;
  for (pCVar2 = (CMemBlock *)this->field_0x7c;
      (this_00 = (CMemBlock *)0x0, pCVar2 != (CMemBlock *)0x0 &&
      (this_00 = pCVar2, *(uint *)(pCVar2 + 4) < uVar1)); pCVar2 = *(CMemBlock **)(pCVar2 + 8)) {
  }
  if (this_00 == (CMemBlock *)0x0) {
    pCVar2 = (CMemBlock *)0x0;
  }
  else {
    pCVar2 = (CMemBlock *)
             CMemBlock::allocBack(this_00,uVar1,'\0','\0',*(uchar *)&this->field_0x6d,'\0');
    pCVar3 = this_00;
    if (pCVar2 == (CMemBlock *)0x0) {
      removeFreeBlock(this,this_00);
      pCVar3 = (CMemBlock *)0x0;
      pCVar2 = this_00;
    }
    if (pCVar3 != (CMemBlock *)0x0) {
      setFreeBlock(this,pCVar3,*(CMemBlock **)(this_00 + 8),*(CMemBlock **)(this_00 + 0xc));
    }
    appendUsedList(this,pCVar2);
    pCVar2 = pCVar2 + 0x10;
  }
  return pCVar2;
}


/* __thiscall JKRExpHeap::do_free(void *) */

void __thiscall JKRExpHeap::do_free(JKRExpHeap *this,void *param_1)

{
  CMemBlock *this_00;
  ulong uVar1;
  void *extraout_r4;
  
  os::OSLockMutex(&(this->parent).mMutex);
  if ((param_1 < (this->parent).mpDataBegin) || ((this->parent).mpDataEnd < param_1)) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f
              (uVar1,"JKRExpHeap.cpp",0x378,"free: memblock %x not in heap %x",(___)param_1);
  }
  else {
    this_00 = (CMemBlock *)CMemBlock::getHeapBlock((CMemBlock *)param_1,extraout_r4);
    if (this_00 != (CMemBlock *)0x0) {
      CMemBlock::free(this_00,this);
    }
  }
  os::OSUnlockMutex(&(this->parent).mMutex);
  return;
}


/* __thiscall JKRExpHeap::do_freeAll(void) */

void __thiscall JKRExpHeap::do_freeAll(JKRExpHeap *this)

{
  os::OSLockMutex(&(this->parent).mMutex);
  JKRHeap::callAllDisposer(&this->parent);
  this->field_0x78 = (undefined *)(this->parent).mpDataBegin;
  this->field_0x7c = this->field_0x78;
  CMemBlock::initiate((CMemBlock *)this->field_0x78,(CMemBlock *)0x0,(CMemBlock *)0x0,
                      (this->parent).mSize - 0x10,'\0','\0');
  this->field_0x80 = (undefined *)0x0;
  this->field_0x84 = (undefined *)0x0;
  os::OSUnlockMutex(&(this->parent).mMutex);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRExpHeap::do_freeTail(void) */

void __thiscall JKRExpHeap::do_freeTail(JKRExpHeap *this)

{
  CMemBlock *pCVar1;
  CMemBlock *this_00;
  
  os::OSLockMutex(&(this->parent).mMutex);
  this_00 = (CMemBlock *)this->field_0x80;
  while( true ) {
    if (this_00 == (CMemBlock *)0x0) break;
    if (((byte)this_00[2] & 0x80) == 0) {
      this_00 = *(CMemBlock **)(this_00 + 0xc);
    }
    else {
      JKRHeap::dispose(&this->parent,this_00 + 0x10,*(ulong *)(this_00 + 4));
      pCVar1 = *(CMemBlock **)(this_00 + 0xc);
      CMemBlock::free(this_00,this);
      this_00 = pCVar1;
    }
  }
  os::OSUnlockMutex(&(this->parent).mMutex);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRExpHeap::do_changeGroupID(unsigned char) */

undefined __thiscall JKRExpHeap::do_changeGroupID(JKRExpHeap *this,uchar param_1)

{
  undefined uVar1;
  
  os::OSLockMutex(&(this->parent).mMutex);
  uVar1 = *(undefined *)&this->field_0x6d;
  *(uchar *)&this->field_0x6d = param_1;
  os::OSUnlockMutex(&(this->parent).mMutex);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRExpHeap::do_resize(void *,
                                    unsigned long) */

uint __thiscall JKRExpHeap::do_resize(JKRExpHeap *this,void *param_1,ulong param_2)

{
  CMemBlock *this_00;
  uint uVar1;
  CMemBlock *pCVar2;
  void *extraout_r4;
  uint uVar3;
  CMemBlock *pCVar4;
  
  os::OSLockMutex(&(this->parent).mMutex);
  this_00 = (CMemBlock *)CMemBlock::getHeapBlock((CMemBlock *)param_1,extraout_r4);
  if (((this_00 == (CMemBlock *)0x0) || (param_1 < (this->parent).mpDataBegin)) ||
     ((this->parent).mpDataEnd < param_1)) {
    os::OSUnlockMutex(&(this->parent).mMutex);
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = param_2 + 3 & 0xfffffffc;
    uVar3 = *(uint *)(this_00 + 4);
    if (uVar1 == uVar3) {
      os::OSUnlockMutex(&(this->parent).mMutex);
    }
    else {
      if (uVar3 < uVar1) {
        for (pCVar2 = (CMemBlock *)this->field_0x78;
            (pCVar4 = (CMemBlock *)0x0, pCVar2 != (CMemBlock *)0x0 &&
            (pCVar4 = pCVar2, pCVar2 != this_00 + uVar3 + 0x10));
            pCVar2 = *(CMemBlock **)(pCVar2 + 0xc)) {
        }
        if (pCVar4 == (CMemBlock *)0x0) {
          os::OSUnlockMutex(&(this->parent).mMutex);
          return 0xffffffff;
        }
        if (uVar3 + *(int *)(pCVar4 + 4) + 0x10 < uVar1) {
          os::OSUnlockMutex(&(this->parent).mMutex);
          return 0xffffffff;
        }
        removeFreeBlock(this,pCVar4);
        *(int *)(this_00 + 4) = *(int *)(pCVar4 + 4) + *(int *)(this_00 + 4) + 0x10;
        if ((0x10 < *(int *)(this_00 + 4) - uVar1) &&
           (pCVar2 = (CMemBlock *)
                     CMemBlock::allocFore
                               (this_00,uVar1,(uchar)this_00[3],(uchar)this_00[2],'\0','\0'),
           pCVar2 != (CMemBlock *)0x0)) {
          recycleFreeBlock(this,pCVar2);
        }
      }
      else {
        if ((0x10 < uVar3 - uVar1) &&
           (pCVar2 = (CMemBlock *)
                     CMemBlock::allocFore
                               (this_00,uVar1,(uchar)this_00[3],(uchar)this_00[2],'\0','\0'),
           pCVar2 != (CMemBlock *)0x0)) {
          recycleFreeBlock(this,pCVar2);
        }
      }
      os::OSUnlockMutex(&(this->parent).mMutex);
      uVar1 = *(uint *)(this_00 + 4);
    }
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRExpHeap::do_getSize(void *) */

int __thiscall JKRExpHeap::do_getSize(JKRExpHeap *this,void *param_1)

{
  int iVar1;
  void *extraout_r4;
  
  os::OSLockMutex(&(this->parent).mMutex);
  iVar1 = CMemBlock::getHeapBlock((CMemBlock *)param_1,extraout_r4);
  if (((iVar1 == 0) || (param_1 < (this->parent).mpDataBegin)) ||
     ((this->parent).mpDataEnd < param_1)) {
    os::OSUnlockMutex(&(this->parent).mMutex);
    iVar1 = -1;
  }
  else {
    os::OSUnlockMutex(&(this->parent).mMutex);
    iVar1 = *(int *)(iVar1 + 4);
  }
  return iVar1;
}


/* __thiscall JKRExpHeap::do_getFreeSize(void) */

int __thiscall JKRExpHeap::do_getFreeSize(JKRExpHeap *this)

{
  undefined *puVar1;
  int iVar2;
  
  os::OSLockMutex(&(this->parent).mMutex);
  iVar2 = 0;
  for (puVar1 = this->field_0x78; puVar1 != (undefined *)0x0; puVar1 = *(undefined **)(puVar1 + 0xc)
      ) {
    if (iVar2 < *(int *)(puVar1 + 4)) {
      iVar2 = *(int *)(puVar1 + 4);
    }
  }
  os::OSUnlockMutex(&(this->parent).mMutex);
  return iVar2;
}


/* __thiscall JKRExpHeap::do_getMaxFreeBlock(void) */

undefined * __thiscall JKRExpHeap::do_getMaxFreeBlock(JKRExpHeap *this)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  os::OSLockMutex(&(this->parent).mMutex);
  iVar1 = 0;
  puVar3 = (undefined *)0x0;
  for (puVar2 = this->field_0x78; puVar2 != (undefined *)0x0; puVar2 = *(undefined **)(puVar2 + 0xc)
      ) {
    if (iVar1 < *(int *)(puVar2 + 4)) {
      iVar1 = *(int *)(puVar2 + 4);
      puVar3 = puVar2;
    }
  }
  os::OSUnlockMutex(&(this->parent).mMutex);
  return puVar3;
}


/* __thiscall JKRExpHeap::do_getTotalFreeSize(void) */

int __thiscall JKRExpHeap::do_getTotalFreeSize(JKRExpHeap *this)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = 0;
  os::OSLockMutex(&(this->parent).mMutex);
  for (puVar1 = this->field_0x78; puVar1 != (undefined *)0x0; puVar1 = *(undefined **)(puVar1 + 0xc)
      ) {
    iVar2 = iVar2 + *(int *)(puVar1 + 4);
  }
  os::OSUnlockMutex(&(this->parent).mMutex);
  return iVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRExpHeap::getUsedSize(unsigned char) const */

int __thiscall JKRExpHeap::getUsedSize(JKRExpHeap *this,uchar param_1)

{
  undefined *puVar1;
  int iVar2;
  
  os::OSLockMutex(&(this->parent).mMutex);
  iVar2 = 0;
  for (puVar1 = this->field_0x80; puVar1 != (undefined *)0x0; puVar1 = *(undefined **)(puVar1 + 0xc)
      ) {
    if (puVar1[3] == param_1) {
      iVar2 = *(int *)(puVar1 + 4) + iVar2 + 0x10;
    }
  }
  os::OSUnlockMutex(&(this->parent).mMutex);
  return iVar2;
}


/* __thiscall JKRExpHeap::getTotalUsedSize(void) const */

int __thiscall JKRExpHeap::getTotalUsedSize(JKRExpHeap *this)

{
  undefined *puVar1;
  int iVar2;
  
  os::OSLockMutex(&(this->parent).mMutex);
  iVar2 = 0;
  for (puVar1 = this->field_0x80; puVar1 != (undefined *)0x0; puVar1 = *(undefined **)(puVar1 + 0xc)
      ) {
    iVar2 = *(int *)(puVar1 + 4) + iVar2 + 0x10;
  }
  os::OSUnlockMutex(&(this->parent).mMutex);
  return iVar2;
}


/* __thiscall JKRExpHeap::appendUsedList(JKRExpHeap::CMemBlock *) */

void __thiscall JKRExpHeap::appendUsedList(JKRExpHeap *this,CMemBlock *param_1)

{
  undefined *puVar1;
  
  if (param_1 == (CMemBlock *)0x0) {
    m_Do_printf::OSPanic("JKRExpHeap.cpp",0x5ba,":::ERROR! appendUsedList\n");
  }
  puVar1 = this->field_0x84;
  *(undefined2 *)param_1 = 0x484d;
  if (puVar1 == (undefined *)0x0) {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else {
    *(CMemBlock **)(puVar1 + 0xc) = param_1;
    *(undefined **)(param_1 + 8) = puVar1;
  }
  this->field_0x84 = param_1;
  if (this->field_0x80 == (undefined *)0x0) {
    this->field_0x80 = param_1;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}


/* __thiscall JKRExpHeap::setFreeBlock(JKRExpHeap::CMemBlock *,
                                       JKRExpHeap::CMemBlock *,
                                       JKRExpHeap::CMemBlock *) */

void __thiscall
JKRExpHeap::setFreeBlock(JKRExpHeap *this,CMemBlock *param_1,CMemBlock *param_2,CMemBlock *param_3)

{
  if (param_2 == (CMemBlock *)0x0) {
    this->field_0x78 = param_1;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else {
    *(CMemBlock **)(param_2 + 0xc) = param_1;
    *(CMemBlock **)(param_1 + 8) = param_2;
  }
  if (param_3 == (CMemBlock *)0x0) {
    this->field_0x7c = param_1;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  else {
    *(CMemBlock **)(param_3 + 8) = param_1;
    *(CMemBlock **)(param_1 + 0xc) = param_3;
  }
  *(undefined2 *)param_1 = 0;
  return;
}


/* __thiscall JKRExpHeap::removeFreeBlock(JKRExpHeap::CMemBlock *) */

void __thiscall JKRExpHeap::removeFreeBlock(JKRExpHeap *this,CMemBlock *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = *(undefined **)(param_1 + 8);
  puVar1 = *(undefined **)(param_1 + 0xc);
  if (puVar2 == (undefined *)0x0) {
    this->field_0x78 = puVar1;
  }
  else {
    *(undefined **)(puVar2 + 0xc) = puVar1;
  }
  if (puVar1 == (undefined *)0x0) {
    this->field_0x7c = puVar2;
    return;
  }
  *(undefined **)(puVar1 + 8) = puVar2;
  return;
}


/* __thiscall JKRExpHeap::removeUsedBlock(JKRExpHeap::CMemBlock *) */

void __thiscall JKRExpHeap::removeUsedBlock(JKRExpHeap *this,CMemBlock *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = *(undefined **)(param_1 + 8);
  puVar1 = *(undefined **)(param_1 + 0xc);
  if (puVar2 == (undefined *)0x0) {
    this->field_0x80 = puVar1;
  }
  else {
    *(undefined **)(puVar2 + 0xc) = puVar1;
  }
  if (puVar1 == (undefined *)0x0) {
    this->field_0x84 = puVar2;
    return;
  }
  *(undefined **)(puVar1 + 8) = puVar2;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRExpHeap::recycleFreeBlock(JKRExpHeap::CMemBlock *) */

void __thiscall JKRExpHeap::recycleFreeBlock(JKRExpHeap *this,CMemBlock *param_1)

{
  uint uVar1;
  CMemBlock *pCVar2;
  CMemBlock *pCVar3;
  ulong uVar4;
  
  uVar4 = *(ulong *)(param_1 + 4);
  pCVar3 = param_1 + uVar4;
  *(undefined2 *)param_1 = 0;
  uVar1 = (byte)param_1[2] & 0x7f;
  if (((byte)param_1[2] & 0x7f) != 0) {
    param_1 = param_1 + -uVar1;
    uVar4 = uVar4 + uVar1;
    pCVar3 = param_1 + uVar4;
    param_1[3] = (CMemBlock)0x0;
    param_1[2] = (CMemBlock)0x0;
    *(ulong *)(param_1 + 4) = uVar4;
  }
  pCVar2 = (CMemBlock *)this->field_0x78;
  if (pCVar2 == (CMemBlock *)0x0) {
    CMemBlock::initiate(param_1,(CMemBlock *)0x0,(CMemBlock *)0x0,uVar4,'\0','\0');
    this->field_0x78 = param_1;
    this->field_0x7c = param_1;
    setFreeBlock(this,param_1,(CMemBlock *)0x0,(CMemBlock *)0x0);
  }
  else {
    if (pCVar2 < pCVar3) {
      if (param_1 < (CMemBlock *)this->field_0x7c) {
        for (; pCVar2 != (CMemBlock *)0x0; pCVar2 = *(CMemBlock **)(pCVar2 + 0xc)) {
          if ((pCVar2 < param_1) && (param_1 < *(CMemBlock **)(pCVar2 + 0xc))) {
            *(CMemBlock **)(param_1 + 0xc) = *(CMemBlock **)(pCVar2 + 0xc);
            *(CMemBlock **)(param_1 + 8) = pCVar2;
            *(CMemBlock **)(pCVar2 + 0xc) = param_1;
            *(CMemBlock **)(*(int *)(param_1 + 0xc) + 8) = param_1;
            param_1[3] = (CMemBlock)0x0;
            joinTwoBlocks(this,param_1);
            joinTwoBlocks(this,pCVar2);
            return;
          }
        }
      }
      else {
        CMemBlock::initiate(param_1,(CMemBlock *)0x0,(CMemBlock *)0x0,uVar4,'\0','\0');
        setFreeBlock(this,param_1,(CMemBlock *)this->field_0x7c,(CMemBlock *)0x0);
        joinTwoBlocks(this,*(CMemBlock **)(param_1 + 8));
      }
    }
    else {
      CMemBlock::initiate(param_1,(CMemBlock *)0x0,(CMemBlock *)0x0,uVar4,'\0','\0');
      setFreeBlock(this,param_1,(CMemBlock *)0x0,(CMemBlock *)this->field_0x78);
      joinTwoBlocks(this,param_1);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRExpHeap::joinTwoBlocks(JKRExpHeap::CMemBlock *) */

void __thiscall JKRExpHeap::joinTwoBlocks(JKRExpHeap *this,CMemBlock *param_1)

{
  int iVar1;
  CMemBlock *pCVar2;
  int iVar3;
  CMemBlock *pCVar4;
  
  iVar3 = *(int *)(param_1 + 0xc);
  pCVar2 = (CMemBlock *)(iVar3 - (*(byte *)(iVar3 + 2) & 0x7f));
  pCVar4 = param_1 + *(int *)(param_1 + 4) + 0x10;
  if (pCVar2 < pCVar4) {
    JUtility::JUTWarningConsole_f(":::Heap may be broken. (block = %x)");
    m_Do_printf::OSReport(":::block = %x\n",param_1);
    iVar1 = *(int *)(param_1 + 0xc);
    m_Do_printf::OSReport
              (":::joinTwoBlocks [%x %x %x][%x %x %x]\n",param_1,param_1[2],
               *(undefined4 *)(param_1 + 4),iVar1,*(undefined *)(iVar1 + 2),
               *(undefined4 *)(iVar1 + 4));
    m_Do_printf::OSReport(":::: endAddr = %x\n",pCVar4);
    m_Do_printf::OSReport(":::: nextAddr = %x\n",pCVar2);
    (*(code *)JKRHeap::sCurrentHeap->vtbl->dump)();
    m_Do_printf::OSPanic("JKRExpHeap.cpp",0x6b6,":::: Bad Block\n");
  }
  if (pCVar4 == pCVar2) {
    *(uint *)(param_1 + 4) =
         *(int *)(iVar3 + 4) + (*(byte *)(iVar3 + 2) & 0x7f) + *(int *)(param_1 + 4) + 0x10;
    setFreeBlock(this,param_1,*(CMemBlock **)(param_1 + 8),*(CMemBlock **)(iVar3 + 0xc));
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRExpHeap::check(void) */

int __thiscall JKRExpHeap::check(JKRExpHeap *this)

{
  int *piVar1;
  ushort *puVar2;
  ushort uVar3;
  int iVar4;
  short *psVar5;
  ushort *puVar6;
  undefined *puVar7;
  int iVar8;
  int iVar9;
  
  os::OSLockMutex(&(this->parent).mMutex);
  iVar9 = 0;
  iVar8 = 1;
  puVar6 = (ushort *)this->field_0x80;
  do {
    if (puVar6 == (ushort *)0x0) {
LAB_802b2a30:
      for (puVar7 = this->field_0x78; puVar7 != (undefined *)0x0;
          puVar7 = *(undefined **)(puVar7 + 0xc)) {
        iVar9 = *(int *)(puVar7 + 4) + iVar9 + 0x10;
        if (*(int *)(puVar7 + 0xc) == 0) {
          if (this->field_0x7c != puVar7) {
            iVar8 = 0;
            JUtility::JUTWarningConsole_f(":::addr %08x: bad used list(REV) (%08x)\n",puVar7);
          }
        }
        else {
          if (*(undefined **)(*(int *)(puVar7 + 0xc) + 8) != puVar7) {
            iVar8 = 0;
            JUtility::JUTWarningConsole_f(":::addr %08x: bad previous pointer (%08x)\n");
          }
          if (*(undefined **)(puVar7 + 0xc) < puVar7 + *(int *)(puVar7 + 4) + 0x10) {
            iVar8 = 0;
            JUtility::JUTWarningConsole_f(":::addr %08x: bad block size (%08x)\n",puVar7);
          }
        }
      }
      iVar4 = (this->parent).mSize;
      if (iVar9 != iVar4) {
        iVar8 = 0;
        JUtility::JUTWarningConsole_f(":::bad total memory block size (%08X, %08X)\n",iVar4,iVar9);
      }
      if (iVar8 == 0) {
        JUtility::JUTWarningConsole(":::there is some error in this heap!\n");
      }
      os::OSUnlockMutex(&(this->parent).mMutex);
      return iVar8;
    }
    uVar3 = *puVar6;
    if (uVar3 != 0x484d) {
      iVar8 = 0;
      JUtility::JUTWarningConsole_f
                (":::addr %08x: bad heap signature. (%c%c)\n",puVar6,uVar3 >> 8,uVar3 & 0xff);
    }
    psVar5 = *(short **)(puVar6 + 6);
    if (psVar5 == (short *)0x0) {
      if ((ushort *)this->field_0x84 != puVar6) {
        iVar8 = 0;
        JUtility::JUTWarningConsole_f(":::addr %08x: bad used list(REV) (%08x)\n",puVar6);
      }
    }
    else {
      if (*psVar5 != 0x484d) {
        iVar8 = 0;
        JUtility::JUTWarningConsole_f(":::addr %08x: bad next pointer (%08x)\nabort\n",puVar6);
        goto LAB_802b2a30;
      }
      if (*(ushort **)(psVar5 + 4) != puVar6) {
        iVar8 = 0;
        JUtility::JUTWarningConsole_f
                  (":::addr %08x: bad previous pointer (%08x)\n",psVar5,*(ushort **)(psVar5 + 4));
      }
    }
    piVar1 = (int *)(puVar6 + 2);
    puVar2 = puVar6 + 1;
    puVar6 = *(ushort **)(puVar6 + 6);
    iVar9 = *piVar1 + (*(byte *)puVar2 & 0x7f) + iVar9 + 0x10;
  } while( true );
}


/* __thiscall JKRExpHeap::do_freeFill(void) */

void __thiscall JKRExpHeap::do_freeFill(JKRExpHeap *this)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall JKRExpHeap::dump(void) */

undefined4 __thiscall JKRExpHeap::dump(JKRExpHeap *this)

{
  int *piVar1;
  short *psVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  undefined *puVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  os::OSLockMutex(&(this->parent).mMutex);
  uVar3 = (*(code *)((this->parent).vtbl)->check)(this);
  iVar10 = 0;
  iVar9 = 0;
  iVar8 = 0;
  JUtility::JUTReportConsole(" attr  address:   size    gid aln   prev_ptr next_ptr\n");
  JUtility::JUTReportConsole("(Used Blocks)\n");
  if (this->field_0x80 == (undefined *)0x0) {
    JUtility::JUTReportConsole(" NONE\n");
  }
  psVar7 = (short *)this->field_0x80;
  do {
    if (psVar7 == (short *)0x0) {
LAB_802b2c68:
      JUtility::JUTReportConsole("(Free Blocks)\n");
      if (this->field_0x78 == (undefined *)0x0) {
        JUtility::JUTReportConsole(" NONE\n");
      }
      for (puVar6 = this->field_0x78; puVar6 != (undefined *)0x0;
          puVar6 = *(undefined **)(puVar6 + 0xc)) {
        JUtility::JUTReportConsole_f
                  ("%s %08x: %08x  %3d %3d  (%08x %08x)\n"," free",puVar6 + 0x10,
                   *(undefined4 *)(puVar6 + 4),puVar6[3],puVar6[2] & 0x7f,
                   *(undefined4 *)(puVar6 + 8),*(undefined4 *)(puVar6 + 0xc));
        iVar8 = iVar8 + 1;
      }
      iVar5 = (this->parent).mSize;
      JUtility::JUTReportConsole_f
                ((double)(JKernel::_1087 *
                         ((float)((double)CONCAT44(0x43300000,iVar10) - JKernel::_1089) /
                         (float)((double)CONCAT44(0x43300000,iVar5) - JKernel::_1089))),
                 "%d / %d bytes (%6.2f%%) used (U:%d F:%d)\n",iVar10,iVar5,iVar9,iVar8);
      os::OSUnlockMutex(&(this->parent).mMutex);
      return uVar3;
    }
    if (*psVar7 != 0x484d) {
      JUtility::JUTReportConsole_f
                ("xxxxx %08x: --------  --- ---  (-------- --------)\nabort\n",psVar7);
      goto LAB_802b2c68;
    }
    pcVar4 = "alloc";
    if ((*(byte *)(psVar7 + 1) & 0x80) != 0) {
      pcVar4 = " temp";
    }
    JUtility::JUTReportConsole_f
              ("%s %08x: %08x  %3d %3d  (%08x %08x)\n",pcVar4,psVar7 + 8,*(undefined4 *)(psVar7 + 2)
               ,*(undefined *)((int)psVar7 + 3),*(byte *)(psVar7 + 1) & 0x7f,
               *(undefined4 *)(psVar7 + 4),*(undefined4 *)(psVar7 + 6));
    piVar1 = (int *)(psVar7 + 2);
    psVar2 = psVar7 + 1;
    psVar7 = *(short **)(psVar7 + 6);
    iVar10 = *piVar1 + (*(byte *)psVar2 & 0x7f) + iVar10 + 0x10;
    iVar9 = iVar9 + 1;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall JKRExpHeap::dump_sort_by_address(void) */

undefined4 __thiscall JKRExpHeap::dump_sort_by_address(JKRExpHeap *this)

{
  undefined4 uVar1;
  short *psVar2;
  short *psVar3;
  char *pcVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  os::OSLockMutex(&(this->parent).mMutex);
  uVar1 = (*(code *)((this->parent).vtbl)->check)(this);
  iVar9 = 0;
  iVar8 = 0;
  iVar7 = 0;
  JUtility::JUTReportConsole(" attr  address:   size    gid aln   prev_ptr next_ptr\n");
  psVar3 = (short *)0x0;
  while( true ) {
    while( true ) {
      psVar6 = (short *)&DAT_ffffffff;
      for (psVar2 = (short *)this->field_0x78; psVar2 != (short *)0x0;
          psVar2 = *(short **)(psVar2 + 6)) {
        if ((psVar3 < psVar2) && (psVar2 < psVar6)) {
          psVar6 = psVar2;
        }
      }
      for (psVar2 = (short *)this->field_0x80; psVar2 != (short *)0x0;
          psVar2 = *(short **)(psVar2 + 6)) {
        if ((psVar3 < psVar2) && (psVar2 < psVar6)) {
          psVar6 = psVar2;
        }
      }
      if (psVar6 == (short *)&DAT_ffffffff) goto LAB_802b2ee0;
      psVar3 = psVar6;
      if (*psVar6 != 0) break;
      JUtility::JUTReportConsole_f
                ("%s %08x: %08x  %3d %3d  (%08x %08x)\n"," free",psVar6 + 8,
                 *(undefined4 *)(psVar6 + 2),*(undefined *)((int)psVar6 + 3),
                 *(byte *)(psVar6 + 1) & 0x7f,*(undefined4 *)(psVar6 + 4),
                 *(undefined4 *)(psVar6 + 6));
      iVar7 = iVar7 + 1;
    }
    if (*psVar6 != 0x484d) break;
    pcVar4 = "alloc";
    if ((*(byte *)(psVar6 + 1) & 0x80) != 0) {
      pcVar4 = " temp";
    }
    JUtility::JUTReportConsole_f
              ("%s %08x: %08x  %3d %3d  (%08x %08x)\n",pcVar4,psVar6 + 8,*(undefined4 *)(psVar6 + 2)
               ,*(undefined *)((int)psVar6 + 3),*(byte *)(psVar6 + 1) & 0x7f,
               *(undefined4 *)(psVar6 + 4),*(undefined4 *)(psVar6 + 6));
    iVar9 = *(int *)(psVar6 + 2) + (*(byte *)(psVar6 + 1) & 0x7f) + iVar9 + 0x10;
    iVar8 = iVar8 + 1;
  }
  JUtility::JUTReportConsole_f("xxxxx %08x: --------  --- ---  (-------- --------)\nabort\n");
LAB_802b2ee0:
  iVar5 = (this->parent).mSize;
  JUtility::JUTReportConsole_f
            ((double)(JKernel::_1087 *
                     ((float)((double)CONCAT44(0x43300000,iVar9) - JKernel::_1089) /
                     (float)((double)CONCAT44(0x43300000,iVar5) - JKernel::_1089))),
             "%d / %d bytes (%6.2f%%) used (U:%d F:%d)\n",iVar9,iVar5,iVar8,iVar7);
  os::OSUnlockMutex(&(this->parent).mMutex);
  return uVar1;
}


/* __thiscall JKRExpHeap::dump_sort(void) */

void __thiscall JKRExpHeap::dump_sort(JKRExpHeap *this)

{
  dump_sort_by_address(this);
  return;
}


namespace JKRExpHeap {

/* __thiscall CMemBlock::initiate(CMemBlock *,
                                              CMemBlock *,
                                              unsigned long,
                                              unsigned char,
                                              unsigned char) */

void __thiscall
CMemBlock::initiate
          (CMemBlock *this,CMemBlock *param_1,CMemBlock *param_2,ulong param_3,uchar param_4,
          uchar param_5)

{
  *(undefined2 *)this = 0x484d;
  this[2] = (CMemBlock)param_5;
  this[3] = (CMemBlock)param_4;
  *(ulong *)(this + 4) = param_3;
  *(CMemBlock **)(this + 8) = param_1;
  *(CMemBlock **)(this + 0xc) = param_2;
  return;
}


/* __thiscall CMemBlock::allocFore(unsigned long,
                                               unsigned char,
                                               unsigned char,
                                               unsigned char,
                                               unsigned char) */

CMemBlock * __thiscall
CMemBlock::allocFore
          (CMemBlock *this,ulong param_1,uchar param_2,uchar param_3,uchar param_4,uchar param_5)

{
  CMemBlock *pCVar1;
  
  pCVar1 = (CMemBlock *)0x0;
  this[3] = (CMemBlock)param_2;
  this[2] = (CMemBlock)param_3;
  if (param_1 + 0x10 <= *(uint *)(this + 4)) {
    pCVar1 = this + param_1;
    pCVar1[0x13] = (CMemBlock)param_4;
    pCVar1[0x12] = (CMemBlock)param_5;
    *(ulong *)(pCVar1 + 0x14) = *(int *)(this + 4) - (param_1 + 0x10);
    *(ulong *)(this + 4) = param_1;
    pCVar1 = pCVar1 + 0x10;
  }
  return pCVar1;
}


/* __thiscall CMemBlock::allocBack(unsigned long,
                                               unsigned char,
                                               unsigned char,
                                               unsigned char,
                                               unsigned char) */

CMemBlock * __thiscall
CMemBlock::allocBack
          (CMemBlock *this,ulong param_1,uchar param_2,uchar param_3,uchar param_4,uchar param_5)

{
  CMemBlock *pCVar1;
  
  pCVar1 = (CMemBlock *)0x0;
  if (*(uint *)(this + 4) < param_1 + 0x10) {
    this[3] = (CMemBlock)param_4;
    this[2] = (CMemBlock)0x80;
  }
  else {
    pCVar1 = this + (*(uint *)(this + 4) - param_1);
    pCVar1[3] = (CMemBlock)param_4;
    pCVar1[2] = (CMemBlock)(param_5 | 0x80);
    *(ulong *)(pCVar1 + 4) = param_1;
    this[3] = (CMemBlock)param_2;
    this[2] = (CMemBlock)param_3;
    *(ulong *)(this + 4) = *(int *)(this + 4) - (param_1 + 0x10);
  }
  return pCVar1;
}


/* __thiscall CMemBlock::free(JKRExpHeap *) */

void __thiscall CMemBlock::free(CMemBlock *this,void *__ptr)

{
  removeUsedBlock((JKRExpHeap *)__ptr,this);
  recycleFreeBlock((JKRExpHeap *)__ptr,this);
  return;
}


/* __thiscall CMemBlock::getHeapBlock(void *) */

short * __thiscall CMemBlock::getHeapBlock(CMemBlock *this,void *param_1)

{
  if ((this != (CMemBlock *)0x0) && (*(short *)(this + -0x10) == 0x484d)) {
    return (short *)(this + -0x10);
  }
  return (short *)0x0;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRExpHeap::state_register(JKRHeap::TState *,
                                         unsigned long) const */

void __thiscall JKRExpHeap::state_register(JKRExpHeap *this,TState *param_1,ulong param_2)

{
  ulong uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  if (param_1 == (TState *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRExpHeap.cpp",0x977,"p != 0");
    m_Do_printf::OSPanic("JKRExpHeap.cpp",0x977,&DAT_8036b0c1);
  }
  if (*(JKRExpHeap **)(param_1 + 0x10) != this) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRExpHeap.cpp",0x978,"p->getHeap() == this");
    m_Do_printf::OSPanic("JKRExpHeap.cpp",0x978,&DAT_8036b0c1);
  }
  *(ulong *)(param_1 + 0x14) = param_2;
  if (param_2 < 0x100) {
    uVar2 = getUsedSize(this,(uchar)param_2);
    *(undefined4 *)param_1 = uVar2;
  }
  else {
    iVar3 = JKRHeap::getTotalFreeSize(&this->parent);
    *(int *)param_1 = (this->parent).mSize - iVar3;
  }
  iVar3 = 0;
  for (puVar4 = this->field_0x80; puVar4 != (undefined *)0x0; puVar4 = *(undefined **)(puVar4 + 0xc)
      ) {
    if (param_2 < 0x100) {
      if ((byte)puVar4[3] == param_2) {
        iVar3 = iVar3 + (int)puVar4 * 3;
      }
    }
    else {
      iVar3 = iVar3 + (int)puVar4 * 3;
    }
  }
  *(int *)(param_1 + 4) = iVar3;
  return;
}


/* __thiscall JKRExpHeap::state_compare(JKRHeap::TState const &,
                                        JKRHeap::TState const &) const */

bool __thiscall JKRExpHeap::state_compare(JKRExpHeap *this,TState *param_1,TState *param_2)

{
  ulong uVar1;
  
  if (*(int *)(param_1 + 0x10) != *(int *)(param_2 + 0x10)) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRExpHeap.cpp",0x9a7,"r1.getHeap() == r2.getHeap()");
    m_Do_printf::OSPanic("JKRExpHeap.cpp",0x9a7,&DAT_8036b0c1);
  }
  return *(int *)param_1 == *(int *)param_2 && *(int *)(param_1 + 4) == *(int *)(param_2 + 4);
}


/* __thiscall JKRExpHeap::getHeapType(void) */

undefined4 __thiscall JKRExpHeap::getHeapType(JKRExpHeap *this)

{
  return 0x45585048;
}


/* __thiscall JKRExpHeap::do_getCurrentGroupId(void) */

undefined __thiscall JKRExpHeap::do_getCurrentGroupId(JKRExpHeap *this)

{
  return *(undefined *)&this->field_0x6d;
}

