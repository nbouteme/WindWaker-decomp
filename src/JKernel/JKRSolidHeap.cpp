#include <JKernel/JKRSolidHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRSolidHeap.h>
#include <os/OSMutex.h>
#include <JUtility/JUTConsole.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <Demangler/JKRSolidHeap.h>


namespace JKRSolidHeap {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall create(unsigned long,
                                   JKRHeap *,
                                   bool) */

JKRSolidHeap * create(ulong maxSize,JKRHeap *pParent,bool bReportErrors)

{
  uint size;
  JKRSolidHeap *this;
  
  if (pParent == (JKRHeap *)0x0) {
    pParent = JKRHeap::sRootHeap;
  }
  if (maxSize == 0xffffffff) {
    maxSize = JKRHeap::getMaxAllocatableSize(pParent,0x10);
  }
  size = maxSize & 0xfffffff0;
  if (size < 0x80) {
    this = (JKRSolidHeap *)0x0;
  }
  else {
    this = (JKRSolidHeap *)JKRHeap::alloc(size,0x10,pParent);
    if (this != (JKRSolidHeap *)0x0) {
      if (this != (JKRSolidHeap *)0x0) {
        JKRSolidHeap(this,(void *)&this[1].parent.field_0x4,size - 0x80,pParent,bReportErrors);
      }
    }
    else {
      this = (JKRSolidHeap *)0x0;
    }
  }
  return this;
}

}

/* __thiscall JKRSolidHeap::do_destroy(void) */

void __thiscall JKRSolidHeap::do_destroy(JKRSolidHeap *this)

{
  JKRHeap *pJVar1;
  
  pJVar1 = (JKRHeap *)(this->parent).mChildHeapLink.mpList[1].mpHead;
  if (pJVar1 != (JKRHeap *)0x0) {
    (*(code *)((this->parent).vtbl)->_)(this,0xffffffff);
    JKRHeap::free(this,pJVar1);
  }
  return;
}


/* __thiscall JKRSolidHeap::JKRSolidHeap(void *,
                                         unsigned long,
                                         JKRHeap *,
                                         bool) */

void __thiscall
JKRSolidHeap::JKRSolidHeap
          (JKRSolidHeap *this,void *param_1,ulong param_2,JKRHeap *param_3,bool param_4)

{
  JKRHeap::JKRHeap(&this->parent,param_1,param_2,param_3,param_4);
  (this->parent).vtbl = (JKRHeap__vtbl *)&__vt;
  this->mRemainingSize = (this->parent).mSize;
  this->mpHead = (undefined *)(this->parent).mpDataBegin;
  this->mpTail = (undefined *)(this->parent).mpDataEnd;
  this->field_0x78 = (undefined *)0x0;
  return;
}


/* __thiscall JKRSolidHeap::~JKRSolidHeap(void) */

void __thiscall JKRSolidHeap::_JKRSolidHeap(JKRSolidHeap *this)

{
  short in_r4;
  
  if (this != (JKRSolidHeap *)0x0) {
    (this->parent).vtbl = (JKRHeap__vtbl *)&__vt;
    JKRHeap::dispose(&this->parent);
    JKRHeap::_JKRHeap(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete(&this->parent);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRSolidHeap::adjustSize(void) */

ulong __thiscall JKRSolidHeap::adjustSize(JKRSolidHeap *this)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  JKRHeap *this_00;
  ulong uVar4;
  
  this_00 = (JKRHeap *)(this->parent).mChildHeapLink.mpList[1].mpHead;
  if (this_00 == (JKRHeap *)0x0) {
    uVar4 = 0xffffffff;
  }
  else {
    os::OSLockMutex(&(this->parent).mMutex);
    pvVar2 = (this->parent).mpDataBegin;
    uVar1 = (uint)(this->mpHead + (0x1f - (int)pvVar2)) & 0xffffffe0;
    uVar4 = (int)pvVar2 + (uVar1 - (int)this);
    iVar3 = JKRHeap::resize(this_00,this,uVar4);
    if (iVar3 != -1) {
      this->mRemainingSize = 0;
      (this->parent).mSize = uVar1;
      (this->parent).mpDataEnd = (void *)((int)(this->parent).mpDataBegin + (this->parent).mSize);
      this->mpHead = (undefined *)(this->parent).mpDataEnd;
      this->mpTail = (undefined *)(this->parent).mpDataEnd;
    }
    os::OSUnlockMutex(&(this->parent).mMutex);
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRSolidHeap::do_alloc(unsigned long,
                                     int) */

undefined4 __thiscall JKRSolidHeap::do_alloc(JKRSolidHeap *this,ulong param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  os::OSLockMutex(&(this->parent).mMutex);
  if (param_1 < 4) {
    param_1 = 4;
  }
  if (param_2 < 0) {
    iVar2 = 4;
    if (3 < -param_2) {
      iVar2 = -param_2;
    }
    uVar1 = allocFromTail(this,param_1,iVar2);
  }
  else {
    iVar2 = 4;
    if (3 < param_2) {
      iVar2 = param_2;
    }
    uVar1 = allocFromHead(this,param_1,iVar2);
  }
  os::OSUnlockMutex(&(this->parent).mMutex);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRSolidHeap::allocFromHead(unsigned long,
                                          int) */

void * __thiscall JKRSolidHeap::allocFromHead(JKRSolidHeap *this,ulong size,int align)

{
  void *pPtr;
  uint actualSize;
  undefined *pHead;
  void *pRetPtr;
  uint size4;
  
  size4 = size + 3 & 0xfffffffc;
  pRetPtr = (void *)0x0;
  pHead = this->mpHead;
  pPtr = (void *)(~(align - 1U) & (uint)(pHead + align + -1));
  actualSize = (int)pPtr + (size4 - (int)pHead);
  if ((uint)this->mRemainingSize < actualSize) {
    JUtility::JUTWarningConsole_f("allocFromHead: cannot alloc memory (0x%x byte).\n");
    if (((this->parent).mbReportErrors == true) && (JKRHeap::mErrorHandler != (undefined *)0x0)) {
      (*(code *)JKRHeap::mErrorHandler)(this,size4,align);
    }
  }
  else {
    this->mpHead = pHead + actualSize;
    this->mRemainingSize = this->mRemainingSize - actualSize;
    pRetPtr = pPtr;
  }
  return pRetPtr;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRSolidHeap::allocFromTail(unsigned long,
                                          int) */

uint __thiscall JKRSolidHeap::allocFromTail(JKRSolidHeap *this,ulong size,int align)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  
  uVar1 = size + 3 & 0xfffffffc;
  uVar5 = 0;
  puVar4 = this->mpTail;
  uVar2 = ~(align - 1U) & (int)puVar4 - uVar1;
  uVar3 = (int)puVar4 - uVar2;
  if ((uint)this->mRemainingSize < uVar3) {
    JUtility::JUTWarningConsole_f("allocFromTail: cannot alloc memory (0x%x byte).\n");
    if (((this->parent).mbReportErrors == true) && (JKRHeap::mErrorHandler != (undefined *)0x0)) {
      (*(code *)JKRHeap::mErrorHandler)(this,uVar1,align);
    }
  }
  else {
    this->mpTail = puVar4 + -uVar3;
    this->mRemainingSize = this->mRemainingSize - uVar3;
    uVar5 = uVar2;
  }
  return uVar5;
}


/* __thiscall JKRSolidHeap::do_free(void *) */

void __thiscall JKRSolidHeap::do_free(JKRSolidHeap *this,void *param_1)

{
  JUtility::JUTWarningConsole_f("free: cannot free memory block (%08x)\n");
  return;
}


/* __thiscall JKRSolidHeap::do_freeAll(void) */

void __thiscall JKRSolidHeap::do_freeAll(JKRSolidHeap *this)

{
  os::OSLockMutex(&(this->parent).mMutex);
  JKRHeap::callAllDisposer(&this->parent);
  this->mRemainingSize = (this->parent).mSize;
  this->mpHead = (undefined *)(this->parent).mpDataBegin;
  this->mpTail = (undefined *)(this->parent).mpDataEnd;
  this->field_0x78 = (undefined *)0x0;
  os::OSUnlockMutex(&(this->parent).mMutex);
  return;
}


/* __thiscall JKRSolidHeap::do_freeTail(void) */

void __thiscall JKRSolidHeap::do_freeTail(JKRSolidHeap *this)

{
  undefined *puVar1;
  
  os::OSLockMutex(&(this->parent).mMutex);
  puVar1 = (undefined *)(this->parent).mpDataEnd;
  if (this->mpTail != puVar1) {
    JKRHeap::dispose(&this->parent,this->mpTail,puVar1);
  }
  this->mRemainingSize = (int)(this->parent).mpDataEnd + (this->mRemainingSize - (int)this->mpTail);
  this->mpTail = (undefined *)(this->parent).mpDataEnd;
  for (puVar1 = this->field_0x78; puVar1 != (undefined *)0x0;
      puVar1 = *(undefined **)(puVar1 + 0x10)) {
    *(void **)(puVar1 + 0xc) = (this->parent).mpDataEnd;
  }
  os::OSUnlockMutex(&(this->parent).mMutex);
  return;
}


/* __thiscall JKRSolidHeap::do_resize(void *,
                                      unsigned long) */

undefined4 __thiscall JKRSolidHeap::do_resize(JKRSolidHeap *this,void *param_1,ulong param_2)

{
  JUtility::JUTWarningConsole_f("resize: cannot resize memory block (%08x: %d)\n");
  return 0xffffffff;
}


/* __thiscall JKRSolidHeap::do_getSize(void *) */

int __thiscall JKRSolidHeap::do_getSize(JKRSolidHeap *this,void *param_1)

{
  JUtility::JUTWarningConsole_f("getSize: cannot get memory block size (%08x)\n");
  return -1;
}


/* __thiscall JKRSolidHeap::check(void) */

bool __thiscall JKRSolidHeap::check(JKRSolidHeap *this)

{
  bool bVar1;
  
  os::OSLockMutex(&(this->parent).mMutex);
  bVar1 = this->mpHead +
          (int)(this->parent).mpDataEnd +
          this->mRemainingSize + (-(int)this->mpTail - (int)(this->parent).mpDataBegin) ==
          (undefined *)(this->parent).mSize;
  if (!bVar1) {
    JUtility::JUTWarningConsole_f("check: bad total memory block size (%08X, %08X)\n");
  }
  os::OSUnlockMutex(&(this->parent).mMutex);
  return bVar1;
}


/* __thiscall JKRSolidHeap::do_freeFill(void) */

void __thiscall JKRSolidHeap::do_freeFill(JKRSolidHeap *this)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRSolidHeap::dump(void) */

undefined4 __thiscall JKRSolidHeap::dump(JKRSolidHeap *this)

{
  undefined *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined *puVar4;
  void *pvVar5;
  
  uVar3 = (*(code *)((this->parent).vtbl)->check)();
  os::OSLockMutex(&(this->parent).mMutex);
  pvVar5 = (this->parent).mpDataBegin;
  puVar1 = this->mpHead;
  puVar4 = this->mpTail;
  pvVar2 = (this->parent).mpDataEnd;
  JUtility::JUTReportConsole_f("head %08x: %08x\n");
  JUtility::JUTReportConsole_f
            ("tail %08x: %08x\n",this->mpTail,(int)(this->parent).mpDataEnd - (int)this->mpTail);
  JUtility::JUTReportConsole_f
            ((double)(JKernel::_665 *
                     ((float)((double)CONCAT44(0x43300000,
                                               (uint)(puVar1 + (int)pvVar2 +
                                                               (-(int)puVar4 - (int)pvVar5)) ^
                                               0x80000000) - JKernel::_667) /
                     (float)((double)CONCAT44(0x43300000,(this->parent).mSize) - JKernel::_669))),
             "%d / %d bytes (%6.2f%%) used\n",puVar1 + (int)pvVar2 + (-(int)puVar4 - (int)pvVar5));
  os::OSUnlockMutex(&(this->parent).mMutex);
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRSolidHeap::state_register(JKRHeap::TState *,
                                           unsigned long) const */

void __thiscall JKRSolidHeap::state_register(JKRSolidHeap *this,TState *param_1,ulong param_2)

{
  ulong uVar1;
  int iVar2;
  
  if (param_1 == (TState *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRSolidHeap.cpp",0x25f,"p != 0");
    m_Do_printf::OSPanic("JKRSolidHeap.cpp",0x25f,&DAT_8036b5ff);
  }
  if (*(JKRSolidHeap **)(param_1 + 0x10) != this) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRSolidHeap.cpp",0x260,"p->getHeap() == this");
    m_Do_printf::OSPanic("JKRSolidHeap.cpp",0x260,&DAT_8036b5ff);
  }
  *(ulong *)(param_1 + 0x14) = param_2;
  iVar2 = JKRHeap::getTotalFreeSize(&this->parent);
  *(int *)param_1 = (this->parent).mSize - iVar2;
  *(undefined **)(param_1 + 4) = this->mpHead + (int)this->mpTail * 3;
  return;
}


/* __thiscall JKRSolidHeap::state_compare(JKRHeap::TState const &,
                                          JKRHeap::TState const &) const */

bool __thiscall JKRSolidHeap::state_compare(JKRSolidHeap *this,TState *param_1,TState *param_2)

{
  ulong uVar1;
  
  if (*(int *)(param_1 + 0x10) != *(int *)(param_2 + 0x10)) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRSolidHeap.cpp",0x27b,"r1.getHeap() == r2.getHeap()");
    m_Do_printf::OSPanic("JKRSolidHeap.cpp",0x27b,&DAT_8036b5ff);
  }
  return *(int *)param_1 == *(int *)param_2 && *(int *)(param_1 + 4) == *(int *)(param_2 + 4);
}


/* __thiscall JKRSolidHeap::getHeapType(void) */

undefined4 __thiscall JKRSolidHeap::getHeapType(JKRSolidHeap *this)

{
  return 0x534c4944;
}


/* __thiscall JKRSolidHeap::do_getFreeSize(void) */

int __thiscall JKRSolidHeap::do_getFreeSize(JKRSolidHeap *this)

{
  return this->mRemainingSize;
}


/* __thiscall JKRSolidHeap::do_getMaxFreeBlock(void) */

undefined * __thiscall JKRSolidHeap::do_getMaxFreeBlock(JKRSolidHeap *this)

{
  return this->mpHead;
}


/* __thiscall JKRSolidHeap::do_getTotalFreeSize(void) */

void __thiscall JKRSolidHeap::do_getTotalFreeSize(JKRSolidHeap *this)

{
  JKRHeap::getFreeSize(&this->parent);
  return;
}

