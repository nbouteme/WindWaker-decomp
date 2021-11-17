#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRDisposer.h>
#include <JSupport/JSUList.h>
#include <os/OSMutex.h>
#include <JKernel/JKRHeap.h>
#include <os/OSArena.h>
#include <os/OSAlloc.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKRHeap.h>

struct JKRHeap * JKRHeap;
struct JKRHeap * JKRHeap;
struct JKRHeap * JKRHeap;
pointer JKRHeap;
void * JKRHeap;
void * JKRHeap;
int JKRHeap;
void * JKRHeap;
int JKRHeap;

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall JKRHeap::JKRHeap(void *,
                               unsigned long,
                               JKRHeap *,
                               bool) */

void __thiscall
JKRHeap::JKRHeap(JKRHeap *this,void *pData,ulong size,JKRHeap *pParent,bool pReportErrors)

{
  JSUPtrLink *pLink;
  
  JKRDisposer::JKRDisposer((JKRDisposer *)this);
  this->vtbl = (JKRHeap__vtbl *)&__vt;
  JSUPtrList::initiate(&this->mChildHeap);
  JSUPtrLink::JSUPtrLink(&this->mChildHeapLink,this);
  JSUPtrList::initiate(&this->mList);
  os::OSInitMutex(&this->mMutex);
  this->mSize = size;
  this->mpDataBegin = pData;
  this->mpDataEnd = (void *)((int)pData + size);
  if (pParent == (JKRHeap *)0x0) {
    becomeSystemHeap(this);
    becomeCurrentHeap(this);
  }
  else {
    pLink = (JSUPtrLink *)&this->mChildHeap;
    if (pLink != (JSUPtrLink *)0x0) {
      pLink = &this->mChildHeapLink;
    }
    JSUPtrList::append(&pParent->mChildHeap,pLink);
    if (sSystemHeap == sRootHeap) {
      becomeSystemHeap(this);
    }
    if (sCurrentHeap == sRootHeap) {
      becomeCurrentHeap(this);
    }
  }
  this->mbReportErrors = pReportErrors;
  if ((this->mbReportErrors == true) && (mErrorHandler == (undefined *)0x0)) {
    mErrorHandler = JKernel::JKRDefaultMemoryErrorRoutine;
  }
  this->mFillFlag = sDefaultFillFlag;
  this->mbReportWarnings = false;
  return;
}


/* __thiscall JKRHeap::~JKRHeap(void) */

void __thiscall JKRHeap::_JKRHeap(JKRHeap *this)

{
  JSUPtrLink *pJVar1;
  short in_r4;
  
  if (this != (JKRHeap *)0x0) {
    this->vtbl = (JKRHeap__vtbl *)&__vt;
    pJVar1 = (JSUPtrLink *)&this->mChildHeap;
    if (pJVar1 != (JSUPtrLink *)0x0) {
      pJVar1 = &this->mChildHeapLink;
    }
    JSUPtrList::remove((this->mChildHeapLink).mpList,pJVar1);
    pJVar1 = (sRootHeap->mChildHeap).mpHead;
    if (pJVar1 != (JSUPtrLink *)0x0) {
      pJVar1 = (JSUPtrLink *)&pJVar1[-1].mpList;
    }
    if ((sCurrentHeap == this) && (sCurrentHeap = sRootHeap, pJVar1 != (JSUPtrLink *)0x0)) {
      sCurrentHeap = (JKRHeap *)pJVar1->mpNext;
    }
    if ((sSystemHeap == this) && (sSystemHeap = sRootHeap, pJVar1 != (JSUPtrLink *)0x0)) {
      sSystemHeap = (JKRHeap *)pJVar1->mpNext;
    }
    if (this != (JKRHeap *)0xffffffa4) {
      JSUPtrList::_JSUPtrList(&this->mList);
    }
    if (this != (JKRHeap *)0xffffffc0) {
      if (this != (JKRHeap *)0xffffffb4) {
        JSUPtrLink::_JSUPtrLink(&this->mChildHeapLink);
      }
      if (this != (JKRHeap *)0xffffffc0) {
        JSUPtrList::_JSUPtrList(&this->mChildHeap);
      }
    }
    JKRDisposer::_JKRDisposer((JKRDisposer *)this);
    if (0 < in_r4) {
      JKernel::operator_delete(this);
    }
  }
  return;
}


namespace JKRHeap {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall initArena(char * *,
                                 unsigned long *,
                                 int) */

bool initArena(char **param_1,ulong *param_2,int param_3)

{
  char *pcVar1;
  void *pvVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = os::OSGetArenaLo();
  uVar4 = os::OSGetArenaHi();
  if (uVar3 != uVar4) {
    iVar5 = os::OSInitAlloc(uVar3,uVar4,param_3);
    pcVar1 = (char *)(iVar5 + 0x1fU & 0xffffffe0);
    pvVar2 = (void *)(uVar4 & 0xffffffe0);
    mCodeStart = &DAT_80000000;
    mMemorySize = DAT_80000028;
    mCodeEnd = pcVar1;
    mUserRamStart = (int)pcVar1;
    mUserRamEnd = pvVar2;
    os::OSSetArenaLo(pvVar2);
    os::OSSetArenaHi(pvVar2);
    *param_1 = pcVar1;
    *param_2 = (int)pvVar2 - (int)pcVar1;
  }
  return uVar3 != uVar4;
}

}

/* __thiscall JKRHeap::becomeSystemHeap(void) */

JKRHeap * __thiscall JKRHeap::becomeSystemHeap(JKRHeap *this)

{
  JKRHeap *pJVar1;
  
  pJVar1 = sSystemHeap;
  sSystemHeap = this;
  return pJVar1;
}


/* __thiscall JKRHeap::becomeCurrentHeap(void) */

JKRHeap * __thiscall JKRHeap::becomeCurrentHeap(JKRHeap *this)

{
  JKRHeap *pJVar1;
  
  pJVar1 = sCurrentHeap;
  sCurrentHeap = this;
  return pJVar1;
}


/* __thiscall JKRHeap::destroy(void) */

void __thiscall JKRHeap::destroy(JKRHeap *this)

{
  (*(code *)this->vtbl->do_destroy)();
  return;
}


namespace JKRHeap {

/* __thiscall alloc(unsigned long,
                             int,
                             JKRHeap *) */

void * alloc(ulong size,int param_2,JKRHeap *pHeap)

{
  void *pvVar1;
  
  if (pHeap == (JKRHeap *)0x0) {
    if (sCurrentHeap == (JKRHeap *)0x0) {
      pvVar1 = (void *)0x0;
    }
    else {
      pvVar1 = alloc(sCurrentHeap,size,param_2);
    }
  }
  else {
    pvVar1 = alloc(pHeap,size,param_2);
  }
  return pvVar1;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRHeap::alloc(unsigned long,
                             int) */

void * __thiscall JKRHeap::alloc(JKRHeap *this,ulong size,int param_2)

{
  ulong uVar1;
  void *pvVar2;
  
  if (this->mbReportWarnings != false) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f(uVar1,"JKRHeap.cpp",0x134,"alloc %x byte in heap %x",size);
  }
  pvVar2 = (void *)(*(code *)this->vtbl->do_alloc)(this,size,param_2);
  return pvVar2;
}


namespace JKRHeap {

/* __thiscall free(void *,
                            JKRHeap *) */

void free(void *__ptr,JKRHeap *param_2)

{
  if ((param_2 != (JKRHeap *)0x0) || (param_2 = findFromRoot(__ptr), param_2 != (JKRHeap *)0x0)) {
    free(param_2,__ptr);
  }
  return;
}

}

/* __thiscall JKRHeap::free(void *) */

void __thiscall JKRHeap::free(JKRHeap *this,void *__ptr)

{
  ulong uVar1;
  
  if (this->mbReportWarnings != false) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f(uVar1,"JKRHeap.cpp",0x164,"free %x in heap %x",(___)__ptr);
  }
  (*(code *)this->vtbl->do_free)(this,__ptr);
  return;
}


/* __thiscall JKRHeap::callAllDisposer(void) */

void __thiscall JKRHeap::callAllDisposer(JKRHeap *this)

{
  JSUPtrLink *pJVar1;
  int *piVar2;
  
  while (pJVar1 = (this->mList).mpHead, pJVar1 != (JSUPtrLink *)0x0) {
    piVar2 = (int *)pJVar1->mpData;
    (**(code **)(*piVar2 + 8))(piVar2,0xffffffff);
  }
  return;
}


/* __thiscall JKRHeap::freeAll(void) */

void __thiscall JKRHeap::freeAll(JKRHeap *this)

{
  ulong uVar1;
  
  if (this->mbReportWarnings != false) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f(uVar1,"JKRHeap.cpp",0x198,"freeAll in heap %x",(___)this);
  }
  (*(code *)this->vtbl->do_freeAll)(this);
  return;
}


/* __thiscall JKRHeap::freeTail(void) */

void __thiscall JKRHeap::freeTail(JKRHeap *this)

{
  ulong uVar1;
  
  if (this->mbReportWarnings != false) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f(uVar1,"JKRHeap.cpp",0x1a6,"freeTail in heap %x",(___)this);
  }
  (*(code *)this->vtbl->do_freeTail)(this);
  return;
}


/* __thiscall JKRHeap::resize(void *,
                              unsigned long,
                              JKRHeap *) */

undefined4 __thiscall JKRHeap::resize(JKRHeap *this,void *param_1,ulong param_2,JKRHeap *param_3)

{
  undefined4 uVar1;
  
  if ((param_2 == 0) && (param_2 = (ulong)findFromRoot(this), (JKRHeap *)param_2 == (JKRHeap *)0x0))
  {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = resize((JKRHeap *)param_2,this,(ulong)param_1);
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRHeap::resize(void *,
                              unsigned long) */

void __thiscall JKRHeap::resize(JKRHeap *this,void *param_1,ulong param_2)

{
  ulong uVar1;
  
  if (this->mbReportWarnings != false) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f
              (uVar1,"JKRHeap.cpp",0x1d2,"resize block %x into %x in heap %x",(___)param_1);
  }
  (*(code *)this->vtbl->do_resize)(this,param_1,param_2);
  return;
}


/* __thiscall JKRHeap::getSize(void *,
                               JKRHeap *) */

int __thiscall JKRHeap::getSize(JKRHeap *this,void *param_1,JKRHeap *param_2)

{
  int iVar1;
  
  if ((param_1 == (void *)0x0) &&
     (param_1 = findFromRoot(this), (JKRHeap *)param_1 == (JKRHeap *)0x0)) {
    iVar1 = -1;
  }
  else {
    iVar1 = getSize((JKRHeap *)param_1,(JKRArchive__Header *)this);
  }
  return iVar1;
}


/* __thiscall JKRHeap::getSize(void *) */

int __thiscall JKRHeap::getSize(JKRHeap *this,JKRArchive__Header *param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)this->vtbl->do_getSize)();
  return iVar1;
}


/* __thiscall JKRHeap::getFreeSize(void) */

void __thiscall JKRHeap::getFreeSize(JKRHeap *this)

{
  (*(code *)this->vtbl->do_getFreeSize)();
  return;
}


/* __thiscall JKRHeap::getMaxFreeBlock(void) */

void __thiscall JKRHeap::getMaxFreeBlock(JKRHeap *this)

{
  (*(code *)this->vtbl->getMaxFreeBlock)();
  return;
}


/* __thiscall JKRHeap::getTotalFreeSize(void) */

void __thiscall JKRHeap::getTotalFreeSize(JKRHeap *this)

{
  (*(code *)this->vtbl->getTotalFreeSize)();
  return;
}


/* __thiscall JKRHeap::getCurrentGroupId(void) */

int __thiscall JKRHeap::getCurrentGroupId(JKRHeap *this)

{
  int iVar1;
  
  iVar1 = (*(code *)this->vtbl->do_getCurrentGroupId)();
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRHeap::getMaxAllocatableSize(int) */

uint __thiscall JKRHeap::getMaxAllocatableSize(JKRHeap *this,int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = getMaxFreeBlock(this);
  iVar2 = getFreeSize(this);
  return ~(param_1 - 1U) & iVar2 - (param_1 - 1U & param_1 - (uVar1 & 0xf));
}


namespace JKRHeap {

/* __thiscall findFromRoot(void *) */

JKRHeap * findFromRoot(void *param_1)

{
  JKRHeap *pJVar1;
  
  if (sRootHeap == (JKRHeap *)0x0) {
    pJVar1 = (JKRHeap *)0x0;
  }
  else {
    pJVar1 = (JKRHeap *)find(sRootHeap,param_1);
  }
  return pJVar1;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRHeap::find(void *) const */

JKRHeap * __thiscall JKRHeap::find(JKRHeap *this,void *pPtr)

{
  JKRHeap *pJVar1;
  JSUPtrLink *pJVar2;
  
  if ((pPtr < this->mpDataBegin) || (this->mpDataEnd <= pPtr)) {
    pJVar1 = (JKRHeap *)0x0;
  }
  else {
    pJVar1 = this;
    if ((this->mChildHeap).mCount != 0) {
      pJVar2 = (this->mChildHeap).mpHead;
      if (pJVar2 != (JSUPtrLink *)0x0) {
        pJVar2 = (JSUPtrLink *)&pJVar2[-1].mpList;
      }
      while ((pJVar1 = this, pJVar2 != (JSUPtrLink *)0x0 &&
             (pJVar1 = (JKRHeap *)find((JKRHeap *)pJVar2->mpNext,pPtr), pJVar1 == (JKRHeap *)0x0)))
      {
        pJVar2 = pJVar2[1].mpPrev;
        if (pJVar2 != (JSUPtrLink *)0x0) {
          pJVar2 = (JSUPtrLink *)&pJVar2[-1].mpList;
        }
      }
    }
  }
  return pJVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRHeap::dispose_subroutine(unsigned long,
                                          unsigned long) */

void __thiscall JKRHeap::dispose_subroutine(JKRHeap *this,ulong param_1,ulong param_2)

{
  JSUPtrLink *pJVar1;
  int *piVar2;
  JSUPtrLink *pJVar3;
  JSUPtrLink *pJVar4;
  
  pJVar1 = (this->mList).mpHead;
  pJVar4 = (JSUPtrLink *)0x0;
  while (pJVar3 = pJVar1, pJVar3 != (JSUPtrLink *)0x0) {
    piVar2 = (int *)pJVar3->mpData;
    if ((piVar2 < param_1) || (param_2 <= piVar2)) {
      pJVar1 = pJVar3->mpNext;
      pJVar4 = pJVar3;
    }
    else {
      (**(code **)(*piVar2 + 8))(piVar2,0xffffffff);
      if (pJVar4 == (JSUPtrLink *)0x0) {
        pJVar1 = (this->mList).mpHead;
      }
      else {
        pJVar1 = pJVar4->mpNext;
      }
    }
  }
  return;
}


/* __thiscall JKRHeap::dispose(void *,
                               unsigned long) */

undefined4 __thiscall JKRHeap::dispose(JKRHeap *this,void *param_1,ulong param_2)

{
  dispose_subroutine(this,(ulong)param_1,(int)param_1 + param_2);
  return 0;
}


/* __thiscall JKRHeap::dispose(void *,
                               void *) */

void __thiscall JKRHeap::dispose(JKRHeap *this,void *param_1,void *param_2)

{
  dispose_subroutine(this,(ulong)param_1,(ulong)param_2);
  return;
}


/* __thiscall JKRHeap::dispose(void) */

void __thiscall JKRHeap::dispose(JKRHeap *this)

{
  JSUPtrLink *pJVar1;
  int *piVar2;
  
  while (pJVar1 = (this->mList).mpHead, pJVar1 != (JSUPtrLink *)0x0) {
    piVar2 = (int *)pJVar1->mpData;
    (**(code **)(*piVar2 + 8))(piVar2,0xffffffff);
  }
  return;
}


/* __thiscall JKRHeap::copyMemory(void *,
                                  void *,
                                  unsigned long) */

void __thiscall JKRHeap::copyMemory(JKRHeap *this,void *param_1,void *param_2,ulong param_3)

{
  uint uVar1;
  
  uVar1 = (int)param_2 + 3U >> 2;
  if (uVar1 == 0) {
    return;
  }
  do {
                    /* WARNING: Load size is inaccurate */
    this->vtbl = *param_1;
    this = (JKRHeap *)&this->field_0x4;
    param_1 = (void *)((int)param_1 + 4);
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}


namespace JKernel {

/* __stdcall JKRDefaultMemoryErrorRoutine(void *,
                                          unsigned long,
                                          int) */

void JKRDefaultMemoryErrorRoutine(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  m_Do_printf::OSReport
            ("Error: Cannot allocate memory %d(0x%x)byte in %d byte alignment from %08x\n",param_2,
             param_2,param_3,param_1);
  m_Do_printf::OSPanic("JKRHeap.cpp",0x2ff,"abort\n");
  return;
}

}

/* __thiscall JKRHeap::setErrorFlag(bool) */

undefined __thiscall JKRHeap::setErrorFlag(JKRHeap *this,bool param_1)

{
  bool bVar1;
  
  bVar1 = this->mbReportErrors;
  this->mbReportErrors = param_1;
  return bVar1;
}


namespace JKRHeap {

/* __thiscall setErrorHandler(void *(void *,unsigned long,int)) */

undefined * setErrorHandler(FuncDef584 *param_1)

{
  undefined *puVar1;
  
  if (param_1 == (FuncDef584 *)0x0) {
    param_1 = JKernel::JKRDefaultMemoryErrorRoutine;
  }
  puVar1 = mErrorHandler;
  mErrorHandler = param_1;
  return puVar1;
}

}

namespace JKernel {

/* __stdcall operator new(unsigned long) */

void * operator_new(ulong size)

{
  void *pvVar1;
  
  pvVar1 = (void *)::JKRHeap::alloc(size,4,(JKRHeap *)0x0);
  return pvVar1;
}


/* __stdcall operator new(unsigned long,
                          int) */

void * operator_new(ulong size,int param_2)

{
  void *pvVar1;
  
  pvVar1 = (void *)::JKRHeap::alloc(size,param_2,(JKRHeap *)0x0);
  return pvVar1;
}


/* __stdcall operator new(unsigned long,
                          JKRHeap *,
                          int) */

void * operator_new(ulong size,JKRHeap *heap,int align)

{
  void *pvVar1;
  
  pvVar1 = (void *)::JKRHeap::alloc(size,align,heap);
  return pvVar1;
}


/* __stdcall operator new[](unsigned long) */

void operator_new__(ulong param_1)

{
  ::JKRHeap::alloc(param_1,4,(JKRHeap *)0x0);
  return;
}


/* __stdcall operator new[](unsigned long,
                            int) */

void operator_new__(ulong param_1,int param_2)

{
  ::JKRHeap::alloc(param_1,param_2,(JKRHeap *)0x0);
  return;
}


/* __stdcall operator new[](unsigned long,
                            JKRHeap *,
                            int) */

void operator_new__(ulong param_1,JKRHeap *param_2,int param_3)

{
  ::JKRHeap::alloc(param_1,param_3,param_2);
  return;
}


/* __stdcall operator delete(void *) */

void operator_delete(JKRHeap *param_1)

{
  ::JKRHeap::free(param_1,(JKRHeap *)0x0);
  return;
}


/* __stdcall operator delete[](void *) */

void operator_delete__(void *param_1)

{
  ::JKRHeap::free(param_1,(JKRHeap *)0x0);
  return;
}

}

/* __thiscall JKRHeap::state_register(JKRHeap::TState *,
                                      unsigned long) const */

void __thiscall JKRHeap::state_register(JKRHeap *this,TState *param_1,ulong param_2)

{
  ulong uVar1;
  
  if (param_1 == (TState *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRHeap.cpp",0x442,"p != 0");
    m_Do_printf::OSPanic("JKRHeap.cpp",0x442,&DAT_8036ac46);
  }
  if (*(JKRHeap **)(param_1 + 0x10) != this) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRHeap.cpp",0x443,"p->getHeap() == this");
    m_Do_printf::OSPanic("JKRHeap.cpp",0x443,&DAT_8036ac46);
  }
  return;
}


/* __thiscall JKRHeap::state_compare(JKRHeap::TState const &,
                                     JKRHeap::TState const &) const */

uint __thiscall JKRHeap::state_compare(JKRHeap *this,TState *param_1,TState *param_2)

{
  uint uVar1;
  ulong uVar2;
  
  if (*(int *)(param_1 + 0x10) != *(int *)(param_2 + 0x10)) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JKRHeap.cpp",1099,"r1.getHeap() == r2.getHeap()");
    m_Do_printf::OSPanic("JKRHeap.cpp",1099,&DAT_8036ac46);
  }
  uVar1 = countLeadingZeros(*(int *)(param_2 + 4) - *(int *)(param_1 + 4));
  return uVar1 >> 5;
}


/* __thiscall JKRHeap::state_dump(JKRHeap::TState const &) const */

void __thiscall JKRHeap::state_dump(JKRHeap *this,TState *param_1)

{
  JUTAssertion *pJVar1;
  ___ in_r8;
  
  pJVar1 = (JUTAssertion *)JUTAssertion::getSDevice();
  JUTAssertion::setLogMessage_f
            (pJVar1,(ulong)"JKRHeap.cpp",(char *)0x463,(int)"check-code : 0x%08x",
             *(char **)(param_1 + 4),in_r8);
  pJVar1 = (JUTAssertion *)JUTAssertion::getSDevice();
  JUTAssertion::setLogMessage_f
            (pJVar1,(ulong)"JKRHeap.cpp",(char *)0x464,(int)"id         : 0x%08x",
             *(char **)(param_1 + 0x14),in_r8);
  pJVar1 = (JUTAssertion *)JUTAssertion::getSDevice();
  JUTAssertion::setLogMessage_f
            (pJVar1,(ulong)"JKRHeap.cpp",(char *)0x465,(int)"used size  : %u",*(char **)param_1,
             in_r8);
  return;
}


/* __thiscall JKRHeap::do_changeGroupID(unsigned char) */

undefined4 __thiscall JKRHeap::do_changeGroupID(JKRHeap *this,uchar param_1)

{
  return 0;
}


/* __thiscall JKRHeap::do_getCurrentGroupId(void) */

undefined4 __thiscall JKRHeap::do_getCurrentGroupId(JKRHeap *this)

{
  return 0;
}

