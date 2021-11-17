#include <JKernel/JKRStdHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRStdHeap.h>
#include <os/OSAlloc.h>
#include <JUtility/JUTConsole.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKRStdHeap.h>


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRStdHeap::create(unsigned long,
                                 JKRHeap *,
                                 bool) */

JKRStdHeap * __thiscall
JKRStdHeap::create(JKRStdHeap *this,ulong param_1,JKRHeap *param_2,bool param_3)

{
  uint size;
  JKRStdHeap *this_00;
  
  if (param_1 == 0) {
    param_1 = (ulong)JKRHeap::sRootHeap;
  }
  if (this == (JKRStdHeap *)&DAT_ffffffff) {
    this = (JKRStdHeap *)JKRHeap::getMaxAllocatableSize((JKRHeap *)param_1,0x20);
  }
  size = (uint)this & 0xffffffe0;
  if (size < 0xc0) {
    this_00 = (JKRStdHeap *)0x0;
  }
  else {
    this_00 = (JKRStdHeap *)JKRHeap::alloc(size,0x20,(JKRHeap *)param_1);
    if (this_00 != (JKRStdHeap *)0x0) {
      if (this_00 != (JKRStdHeap *)0x0) {
        JKRStdHeap(this_00,this_00 + 0x80,size - 0x80,(JKRHeap *)param_1,SUB41(param_2,0));
      }
    }
    else {
      this_00 = (JKRStdHeap *)0x0;
    }
  }
  return this_00;
}


/* __thiscall JKRStdHeap::do_destroy(void) */

void __thiscall JKRStdHeap::do_destroy(JKRStdHeap *this)

{
  JKRHeap *pJVar1;
  
  pJVar1 = *(JKRHeap **)(*(int *)(this + 0x50) + 0xc);
  if (pJVar1 != (JKRHeap *)0x0) {
    (**(code **)(*(int *)this + 8))(this,0xffffffff);
    JKRHeap::free(this,pJVar1);
  }
  return;
}


/* __thiscall JKRStdHeap::JKRStdHeap(void *,
                                     unsigned long,
                                     JKRHeap *,
                                     bool) */

void __thiscall
JKRStdHeap::JKRStdHeap(JKRStdHeap *this,void *param_1,ulong param_2,JKRHeap *param_3,bool param_4)

{
  undefined4 uVar1;
  
  JKRHeap::JKRHeap((JKRHeap *)this,param_1,param_2,param_3,param_4);
  *(undefined1 **)this = &__vt;
  uVar1 = os::OSCreateHeap(*(undefined4 *)(this + 0x30),*(undefined4 *)(this + 0x34));
  *(undefined4 *)(this + 0x6c) = uVar1;
  return;
}


/* __thiscall JKRStdHeap::~JKRStdHeap(void) */

void __thiscall JKRStdHeap::_JKRStdHeap(JKRStdHeap *this)

{
  short in_r4;
  
  if (this != (JKRStdHeap *)0x0) {
    *(undefined1 **)this = &__vt;
    JKRHeap::dispose((JKRHeap *)this);
    if (*(int *)(this + 0x6c) != -1) {
      os::OSDestroyHeap();
    }
    JKRHeap::_JKRHeap((JKRHeap *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRStdHeap::do_alloc(unsigned long,
                                   int) */

int __thiscall JKRStdHeap::do_alloc(JKRStdHeap *this,ulong param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(this + 0x6c) == -1) {
    iVar1 = 0;
  }
  else {
    iVar1 = os::OSAllocFromHeap();
    if (((iVar1 == 0) &&
        (JUtility::JUTWarningConsole_f("alloc: cannot alloc memory (0x%x byte).\n",param_1),
        this[0x68] == (JKRStdHeap)0x1)) && (JKRHeap::mErrorHandler != (undefined *)0x0)) {
      (*(code *)JKRHeap::mErrorHandler)(this,param_1,param_2);
    }
  }
  return iVar1;
}


/* __thiscall JKRStdHeap::do_free(void *) */

void __thiscall JKRStdHeap::do_free(JKRStdHeap *this,void *param_1)

{
  ulong uVar1;
  
  if (*(int *)(this + 0x6c) != -1) {
    if ((param_1 < *(void **)(this + 0x30)) || (*(void **)(this + 0x34) < param_1)) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::setWarningMessage_f
                (uVar1,"JKRStdHeap.cpp",0x117,"free: memblock %x not in heap %x",(___)param_1);
    }
    else {
      os::OSFreeToHeap();
    }
  }
  return;
}


/* __thiscall JKRStdHeap::do_freeAll(void) */

void __thiscall JKRStdHeap::do_freeAll(JKRStdHeap *this)

{
  undefined4 uVar1;
  
  if (*(int *)(this + 0x6c) != -1) {
    JKRHeap::callAllDisposer((JKRHeap *)this);
    os::OSDestroyHeap(*(undefined4 *)(this + 0x6c));
    uVar1 = os::OSCreateHeap(*(undefined4 *)(this + 0x30),*(undefined4 *)(this + 0x34));
    *(undefined4 *)(this + 0x6c) = uVar1;
  }
  return;
}


/* __thiscall JKRStdHeap::do_freeTail(void) */

void __thiscall JKRStdHeap::do_freeTail(JKRStdHeap *this)

{
  JUtility::JUTWarningConsole("freeTail: freeTail() is not work\n");
  return;
}


/* __thiscall JKRStdHeap::do_resize(void *,
                                    unsigned long) */

undefined4 __thiscall JKRStdHeap::do_resize(JKRStdHeap *this,void *param_1,ulong param_2)

{
  JUtility::JUTWarningConsole_f("resize: cannot resize memory block (%08x: %d)\n");
  return 0xffffffff;
}


/* __thiscall JKRStdHeap::do_getFreeSize(void) */

undefined4 __thiscall JKRStdHeap::do_getFreeSize(JKRStdHeap *this)

{
  JUtility::JUTWarningConsole("getFreeSize: cannot get free size\n");
  return 0xffffffff;
}


/* __thiscall JKRStdHeap::do_getMaxFreeBlock(void) */

undefined4 __thiscall JKRStdHeap::do_getMaxFreeBlock(JKRStdHeap *this)

{
  JUtility::JUTWarningConsole("getFreeSize: cannot get free block");
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRStdHeap::state_register(JKRHeap::TState *,
                                         unsigned long) const */

void __thiscall JKRStdHeap::state_register(JKRStdHeap *this,TState *param_1,ulong param_2)

{
  ulong uVar1;
  
  if (param_1 == (TState *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRStdHeap.cpp",0x172,"p != 0");
    m_Do_printf::OSPanic("JKRStdHeap.cpp",0x172,&DAT_8036b025);
  }
  if (*(JKRStdHeap **)(param_1 + 0x10) != this) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRStdHeap.cpp",0x173,"p->getHeap() == this");
    m_Do_printf::OSPanic("JKRStdHeap.cpp",0x173,&DAT_8036b025);
  }
  *(ulong *)(param_1 + 0x14) = param_2;
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}


/* __thiscall JKRStdHeap::state_compare(JKRHeap::TState const &,
                                        JKRHeap::TState const &) const */

bool __thiscall JKRStdHeap::state_compare(JKRStdHeap *this,TState *param_1,TState *param_2)

{
  ulong uVar1;
  
  if (*(int *)(param_1 + 0x10) != *(int *)(param_2 + 0x10)) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRStdHeap.cpp",0x18a,"r1.getHeap() == r2.getHeap()");
    m_Do_printf::OSPanic("JKRStdHeap.cpp",0x18a,&DAT_8036b025);
  }
  return *(int *)param_1 == *(int *)param_2 && *(int *)(param_1 + 4) == *(int *)(param_2 + 4);
}


/* __thiscall JKRStdHeap::do_freeFill(void) */

void __thiscall JKRStdHeap::do_freeFill(JKRStdHeap *this)

{
  return;
}


/* __thiscall JKRStdHeap::getHeapType(void) */

undefined4 __thiscall JKRStdHeap::getHeapType(JKRStdHeap *this)

{
  return 0x53544448;
}


/* __thiscall JKRStdHeap::check(void) */

int __thiscall JKRStdHeap::check(JKRStdHeap *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = os::OSCheckHeap(*(undefined4 *)(this + 0x6c));
  iVar2 = -iVar1 + -1;
  return iVar2 - ((uint)(iVar2 == 0) + -iVar1 + -2);
}


/* __thiscall JKRStdHeap::dump(void) */

int __thiscall JKRStdHeap::dump(JKRStdHeap *this)

{
  int iVar1;
  int iVar2;
  
  os::OSDumpHeap(*(undefined4 *)(this + 0x6c));
  iVar1 = os::OSCheckHeap(*(undefined4 *)(this + 0x6c));
  iVar2 = -iVar1 + -1;
  return iVar2 - ((uint)(iVar2 == 0) + -iVar1 + -2);
}


/* __thiscall JKRStdHeap::do_getSize(void *) */

void __thiscall JKRStdHeap::do_getSize(JKRStdHeap *this,void *param_1)

{
  os::OSReferentSize(param_1);
  return;
}


/* __thiscall JKRStdHeap::do_getTotalFreeSize(void) */

void __thiscall JKRStdHeap::do_getTotalFreeSize(JKRStdHeap *this)

{
  JKRHeap::getFreeSize((JKRHeap *)this);
  return;
}

