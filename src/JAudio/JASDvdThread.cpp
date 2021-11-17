#include <JAudio/JASDvdThread.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAudio/JASDvdThread.h>
#include <JAudio/JASCalc.h>
#include <os/OSMessage.h>
#include <os/OSThread.h>
#include <JKernel/JKRThread.h>
#include <dvd/dvdfs.h>
#include <JASTaskThread/TCallStack.h>
#include <JASystem/Dvd.h>
#include <JASTaskThread.h>


namespace JASystem {
undefined1 Dvd;
}

namespace JASTaskThread {

/* __thiscall TCallStack::TCallStack(unsigned long) */

void __thiscall TCallStack::TCallStack(TCallStack *this,ulong param_1)

{
  undefined4 uVar1;
  ulong uVar2;
  
  *(undefined4 *)this = 0;
  uVar1 = JKernel::operator_new__(param_1,JKRHeap::sSystemHeap,0xfffffffc);
  *(undefined4 *)(this + 4) = uVar1;
  if (*(int *)(this + 4) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASDvdThread.cpp",0x27,"argspace");
    m_Do_printf::OSPanic("JASDvdThread.cpp",0x27,&DAT_80366d9a);
  }
  return;
}


/* __thiscall TCallStack::~TCallStack(void) */

void __thiscall TCallStack::_TCallStack(TCallStack *this)

{
  short in_r4;
  
  if (this != (TCallStack *)0x0) {
    JKernel::operator_delete__(*(undefined4 *)(this + 4));
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JASTaskThread::sendCmdMsg(long *(void *),
                                        void *,
                                        unsigned long) */

undefined4 __thiscall
JASTaskThread::sendCmdMsg(JASTaskThread *this,FuncDef567 *param_1,void *param_2,ulong param_3)

{
  FuncDef567 **this_00;
  undefined4 uVar1;
  ulong __n;
  
  __n = param_3;
  this_00 = (FuncDef567 **)JKernel::operator_new(8,JKRHeap::sSystemHeap,0xfffffffc);
  if (this_00 != (FuncDef567 **)0x0) {
    TCallStack::TCallStack((TCallStack *)this_00,param_3);
  }
  if (this_00 == (FuncDef567 **)0x0) {
    uVar1 = 0;
  }
  else {
    JASystem::Calc::bcopy((Calc *)param_2,this_00[1],(void *)param_3,__n);
    *this_00 = param_1;
    uVar1 = os::OSSendMessage(this + 0x30,this_00,1);
  }
  return uVar1;
}


/* __thiscall JASTaskThread::run(void) */

void __thiscall JASTaskThread::run(JASTaskThread *this)

{
  code **this_00;
  code **local_18 [4];
  
  do {
    do {
      os::OSReceiveMessage(this + 0x30,local_18,1);
      this_00 = local_18[0];
      if (this[0x70] != (JASTaskThread)0x0) {
        os::OSSleepThread(this + 0x68);
      }
    } while (this_00 == (code **)0x0);
    (**this_00)(this_00[1]);
    TCallStack::_TCallStack((TCallStack *)this_00);
  } while( true );
}


/* __thiscall JASTaskThread::pause(bool) */

int __thiscall JASTaskThread::pause(JASTaskThread *this)

{
  JASTaskThread *pJVar1;
  char in_r4;
  
  pJVar1 = this;
  if (in_r4 == '\0') {
    if (this[0x70] != (JASTaskThread)0x0) {
      pJVar1 = (JASTaskThread *)os::OSWakeupThread(this + 0x68);
    }
    this[0x70] = (JASTaskThread)0x0;
  }
  else {
    this[0x70] = (JASTaskThread)0x1;
  }
  return (int)pJVar1;
}


namespace JASystem {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Dvd::createThread(int,
                                          int,
                                          unsigned long) */

undefined4 __thiscall Dvd::createThread(Dvd *this,int param_1,int param_2,ulong param_3)

{
  JKRThread *this_00;
  ulong uVar1;
  
  this_00 = (JKRThread *)JKernel::operator_new(0x74,JAudio::JASDram,0);
  if (this_00 == (JKRThread *)0x0) {
    _sThread = this_00;
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASDvdThread.cpp",0x88,"sThread");
    m_Do_printf::OSPanic("JASDvdThread.cpp",0x88,&DAT_80366d9a);
  }
  else {
    JKRThread::JKRThread(this_00,param_2,param_1,(int)this);
    (this_00->parent).vtbl = (JKRArchive__vtbl *)&JASTaskThread::__vt;
    *(undefined *)&this_00[1].parent.mHeapLink.mpData = 0;
    os::OSInitThreadQueue(this_00 + 1);
    _sThread = this_00;
  }
  return 1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Dvd::resumeThread(void) */

void __thiscall Dvd::resumeThread(Dvd *this)

{
  ulong uVar1;
  
  if (_sThread == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASDvdThread.cpp",0x8f,"sThread");
    m_Do_printf::OSPanic("JASDvdThread.cpp",0x8f,&DAT_80366d9a);
  }
  os::OSResumeThread(*(OSThread **)(_sThread + 0x2c));
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Dvd::sendCmdMsg(long *(void *),
                                        void *,
                                        unsigned long) */

void __thiscall Dvd::sendCmdMsg(Dvd *this,FuncDef568 *param_1,void *param_2,ulong param_3)

{
  ulong uVar1;
  
  if (_sThread == (JASTaskThread *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASDvdThread.cpp",0x98,"sThread");
    m_Do_printf::OSPanic("JASDvdThread.cpp",0x98,&DAT_80366d9a);
  }
  JASTaskThread::sendCmdMsg(_sThread,(FuncDef567 *)this,param_1,(ulong)param_2);
  return;
}


/* __thiscall Dvd::checkPassDvdT(unsigned long,
                                           unsigned long *,
                                           void *(unsigned long)) */

undefined4 __thiscall
Dvd::checkPassDvdT(Dvd *this,ulong param_1,ulong *param_2,FuncDef569 *param_3)

{
  Dvd *local_18;
  ulong local_14;
  ulong *local_10;
  
  local_18 = this;
  local_14 = param_1;
  local_10 = param_2;
  sendCmdMsg((Dvd *)dvdThreadCheckBack,(FuncDef568 *)&local_18,&DAT_0000000c,(ulong)param_3);
  return 0;
}


/* __thiscall Dvd::checkFile(char *) */

undefined4 __thiscall Dvd::checkFile(Dvd *this,char *param_1)

{
  bool bVar1;
  undefined auStack72 [52];
  undefined4 local_14;
  
  bVar1 = dvd::DVDOpen((char *)this,(int)auStack72);
  if (bVar1 == false) {
    local_14 = 0;
  }
  else {
    dvd::DVDClose(auStack72);
  }
  return local_14;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Dvd::unpauseDvdT(void) */

void __thiscall Dvd::unpauseDvdT(Dvd *this)

{
  ulong uVar1;
  
  if (_sThread == (JASTaskThread *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASDvdThread.cpp",0xe7,"sThread");
    m_Do_printf::OSPanic("JASDvdThread.cpp",0xe7,&DAT_80366d9a);
  }
  JASTaskThread::pause(_sThread);
  return;
}


/* __thiscall Dvd::dvdThreadCheckBack(void *) */

undefined4 __thiscall Dvd::dvdThreadCheckBack(Dvd *this,void *param_1)

{
  if (*(undefined4 **)(this + 4) != (undefined4 *)0x0) {
    **(undefined4 **)(this + 4) = *(undefined4 *)this;
  }
  if (*(code **)(this + 8) != (code *)0x0) {
    (**(code **)(this + 8))(*(undefined4 *)this);
  }
  return 0;
}

}

/* __thiscall JASTaskThread::~JASTaskThread(void) */

void __thiscall JASTaskThread::_JASTaskThread(JASTaskThread *this)

{
  short in_r4;
  
  if (this != (JASTaskThread *)0x0) {
    *(undefined1 **)this = &__vt;
    JKRThread::_JKRThread((JKRThread *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

