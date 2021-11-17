#include <JKernel/JKRThread.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRDisposer.h>
#include <JSupport/JSUList.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRThread.h>
#include <os/OSThread.h>
#include <os/OSMessage.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JSUList<JKRThread>.h>
#include <JKRThread.h>
#include <JKRThreadSwitch.h>

undefined1 JKRThread;
struct JKRThreadSwitch * JKRThreadSwitch;

namespace JKernel {
undefined4 preEnd;
}
undefined1 JKRThreadSwitch;
undefined1 JKRThreadSwitch;

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRThread::JKRThread(unsigned long,
                                   int,
                                   int) */

void __thiscall JKRThread::JKRThread(JKRThread *this,ulong param_1,int param_2,int param_3)

{
  JKRHeap *pJVar1;
  undefined4 uVar2;
  OSThread *pOVar3;
  OSMessage *ppvVar4;
  
  JKRDisposer::JKRDisposer(&this->parent);
  (this->parent).vtbl = (JKRArchive__vtbl *)&__vt;
  JSUPtrLink::JSUPtrLink((JSUPtrLink *)&this->field_0x18,this);
  pJVar1 = JKRHeap::findFromRoot(this);
  this->field_0x28 = pJVar1;
  if (this->field_0x28 == 0) {
    this->field_0x28 = JKRHeap::sSystemHeap;
  }
  this->field_0x5c = param_1 & 0xffffffe0;
  uVar2 = JKRHeap::alloc(this->field_0x5c,0x20,(JKRHeap *)this->field_0x28);
  this->field_0x58 = uVar2;
  pOVar3 = (OSThread *)JKRHeap::alloc(0x318,0x20,(JKRHeap *)this->field_0x28);
  this->field_0x2c = pOVar3;
  os::OSCreateThread(this->field_0x2c,start,this,this->field_0x58 + this->field_0x5c,
                     this->field_0x5c,param_3,1);
  this->field_0x54 = param_2;
  ppvVar4 = (OSMessage *)JKRHeap::alloc(this->field_0x54 << 2,0,(JKRHeap *)this->field_0x28);
  this->field_0x50 = ppvVar4;
  os::OSInitMessageQueue((OSMessageQueue *)&this->field_0x30,this->field_0x50,this->field_0x54);
  JSUPtrList::append((JSUPtrList *)&sThreadList,(JSUPtrLink *)&this->field_0x18);
  this->field_0x60 = 0;
  this->field_0x64 = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRThread::JKRThread(OSThread *,
                                   int) */

void __thiscall JKRThread::JKRThread(JKRThread *this,OSThread *param_1,int param_2)

{
  OSMessage *ppvVar1;
  
  JKRDisposer::JKRDisposer(&this->parent);
  (this->parent).vtbl = (JKRArchive__vtbl *)&__vt;
  JSUPtrLink::JSUPtrLink((JSUPtrLink *)&this->field_0x18,this);
  this->field_0x28 = 0;
  this->field_0x2c = param_1;
  this->field_0x5c = param_1->field_0x308 - param_1->field_0x304;
  this->field_0x58 = param_1->field_0x304;
  this->field_0x54 = param_2;
  ppvVar1 = (OSMessage *)JKRHeap::alloc(JKRHeap::sSystemHeap,this->field_0x54 << 2,4);
  this->field_0x50 = ppvVar1;
  os::OSInitMessageQueue((OSMessageQueue *)&this->field_0x30,this->field_0x50,this->field_0x54);
  JSUPtrList::append((JSUPtrList *)&sThreadList,(JSUPtrLink *)&this->field_0x18);
  this->field_0x60 = 0;
  this->field_0x64 = 0;
  return;
}


/* __thiscall JKRThread::~JKRThread(void) */

void __thiscall JKRThread::_JKRThread(JKRThread *this)

{
  int iVar1;
  short in_r4;
  
  if (this != (JKRThread *)0x0) {
    (this->parent).vtbl = (JKRArchive__vtbl *)&__vt;
    JSUPtrList::remove((JSUPtrList *)&sThreadList,(JSUPtrLink *)&this->field_0x18);
    if (this->field_0x28 != 0) {
      iVar1 = os::OSIsThreadTerminated(this->field_0x2c);
      if (iVar1 == 0) {
        os::OSDetachThread(this->field_0x2c);
        os::OSCancelThread(this->field_0x2c);
      }
      JKRHeap::free((void *)this->field_0x58,(JKRHeap *)this->field_0x28);
      JKRHeap::free(this->field_0x2c,(JKRHeap *)this->field_0x28);
    }
    JKRHeap::free(this->field_0x50,(JKRHeap *)0x0);
    if (this != (JKRThread *)0xffffffe8) {
      JSUPtrLink::_JSUPtrLink((JSUPtrLink *)&this->field_0x18);
    }
    JKRDisposer::_JKRDisposer(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JKRThread::start(void *) */

void __thiscall JKRThread::start(JKRThread *this,void *param_1)

{
  (*(code *)((this->parent).vtbl)->unmount)();
  return;
}


/* __thiscall JKRThreadSwitch::JKRThreadSwitch(JKRHeap *) */

void __thiscall JKRThreadSwitch::JKRThreadSwitch(JKRThreadSwitch *this,JKRHeap *param_1)

{
  *(undefined1 **)(this + 8) = &__vt;
  *(JKRHeap **)this = param_1;
  os::OSSetSwitchThreadCallback(callback);
  this[4] = (JKRThreadSwitch)0x1;
  return;
}


namespace JKRThreadSwitch {

/* __thiscall createManager(JKRHeap *) */

JKRThreadSwitch * createManager(JKRHeap *param_1)

{
  ulong uVar1;
  JKRThreadSwitch *this;
  
  if (sManager != (JKRThreadSwitch *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRThread.cpp",0xb8,"sManager == 0");
    m_Do_printf::OSPanic("JKRThread.cpp",0xb8,&DAT_8036b654);
  }
  if (param_1 == (JKRHeap *)0x0) {
    param_1 = JKRHeap::sCurrentHeap;
  }
  this = (JKRThreadSwitch *)JKernel::operator_new(0xc,param_1,0);
  if (this != (JKRThreadSwitch *)0x0) {
    JKRThreadSwitch(this,param_1);
  }
  sManager = this;
  return this;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRThreadSwitch::callback(OSThread *,
                                        OSThread *) */

void __thiscall JKRThreadSwitch::callback(JKRThreadSwitch *this,OSThread *param_1,OSThread *param_2)

{
  JKRThreadSwitch *pJVar1;
  int iVar2;
  JKRThreadSwitch *pJVar3;
  int *piVar4;
  
  if (_mUserPreCallback != (code *)0x0) {
    (*_mUserPreCallback)();
  }
  pJVar3 = this;
  if ((this == (JKRThreadSwitch *)0x0) && (param_1 == (OSThread *)0x0)) {
    pJVar3 = (JKRThreadSwitch *)0x0;
    JKernel::preEnd = this;
  }
  pJVar1 = JKernel::preEnd;
  piVar4 = _sThreadList;
  if ((pJVar3 == (JKRThreadSwitch *)0x0) && (param_1 == (OSThread *)0x0)) {
    JKernel::preEnd = (JKRThreadSwitch *)0x0;
    pJVar3 = pJVar1;
  }
  for (; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[3]) {
    iVar2 = *piVar4;
    if (*(JKRThreadSwitch **)(iVar2 + 0x2c) == pJVar3) {
      *(JKRHeap **)(iVar2 + 0x60) = JKRHeap::sCurrentHeap;
    }
    if ((*(OSThread **)(iVar2 + 0x2c) == param_1) && (sManager[4] != (JKRThreadSwitch)0x0)) {
      JKRHeap::becomeCurrentHeap(*(JKRHeap **)(iVar2 + 0x60));
    }
  }
  if (_mUserPostCallback != (code *)0x0) {
    (*_mUserPostCallback)(pJVar3,param_1);
  }
  return;
}


/* __thiscall JKRThread::run(void) */

undefined4 __thiscall JKRThread::run(JKRThread *this)

{
  return 0;
}


/* __thiscall JKRThreadSwitch::~JKRThreadSwitch(void) */

void __thiscall JKRThreadSwitch::_JKRThreadSwitch(JKRThreadSwitch *this)

{
  short in_r4;
  
  if ((this != (JKRThreadSwitch *)0x0) && (*(undefined1 **)(this + 8) = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace JKernel {

void __sinit_JKRThread_cpp(void)

{
  JSUPtrList::initiate((JSUPtrList *)&::JKRThread::sThreadList);
  Runtime.PPCEABI.H::__register_global_object
            (&::JKRThread::sThreadList,::JSUList<JKRThread>::_JSUList,&_454);
  return;
}

}

/* __thiscall JSUList<JKRThread>::~JSUList(void) */

JSUList_JKRThread_ * __thiscall JSUList<JKRThread>::_JSUList(JSUList_JKRThread_ *this)

{
  short in_r4;
  
  if ((this != (JSUList_JKRThread_ *)0x0) &&
     (JSUPtrList::_JSUPtrList((JSUPtrList *)this), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return this;
}

