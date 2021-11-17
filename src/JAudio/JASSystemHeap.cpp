#include <JAudio/JASSystemHeap.h>
#include <m_Do_printf.h>
#include <JKernel/JKRStdHeap.h>
#include <JKernel/JKRSolidHeap.h>
#include <os/OSInterrupt.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <ar/ar.h>
#include <JAudio/JASHeapCtrl.h>
#include <JAudio/JASSystemHeap.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JASystem/Kernel.h>
#include <JASystem/Kernel/TSolidHeap.h>


namespace JASystem {
undefined1 Kernel;
}

namespace JAudio {
undefined4 JASDram;
}

namespace JASystem {
undefined1 Kernel;
undefined1 Kernel;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Kernel::sysDramSetup(JKRSolidHeap *) */

void __thiscall Kernel::sysDramSetup(Kernel *this,JKRSolidHeap *param_1)

{
  JKRHeap *pParent;
  JKRSolidHeap *pJVar1;
  undefined in_r6;
  
  pJVar1 = (JKRSolidHeap *)this;
  if (this == (Kernel *)0x0) {
    m_Do_printf::OSReport
              (
              "[JASKernel::sysDramSetup] メモリ指定がありませんので、システムからオーディオヒープを取得します。\n"
              );
    pParent = (JKRHeap *)
              JKRStdHeap::create((JKRStdHeap *)(_audioDramSize + 0x100),0,(JKRHeap *)0x0,(bool)in_r6
                                );
    pJVar1 = JKRSolidHeap::create(_audioDramSize,pParent,false);
  }
  JAudio::JASDram = pJVar1;
  return;
}


/* __thiscall Kernel::allocFromSysDram(unsigned long) */

int __thiscall Kernel::allocFromSysDram(Kernel *this,ulong param_1)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  
  uVar1 = os::OSDisableInterrupts();
  iVar2 = JKernel::operator_new__(this,JAudio::JASDram,0x20);
  if (iVar2 == 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"JASSystemHeap.cpp",0x4f,"ptr != 0");
    m_Do_printf::OSPanic("JASSystemHeap.cpp",0x4f,&DAT_8036740d);
  }
  os::OSRestoreInterrupts(uVar1);
  return iVar2;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Kernel::sysAramSetup(unsigned long) */

void __thiscall Kernel::sysAramSetup(Kernel *this,ulong param_1)

{
  _audioAramTop = (EVP_PKEY_CTX *)ar::ARGetBaseAddress();
  _CARD_SECURITY_BUFFER = 0x40;
  TSolidHeap::init((TSolidHeap *)&audioAramHeap,_audioAramTop);
  return;
}


/* __thiscall Kernel::allocFromSysAramFull(unsigned long *) */

void __thiscall Kernel::allocFromSysAramFull(Kernel *this,ulong *param_1)

{
  int iVar1;
  
  iVar1 = TSolidHeap::getRemain((TSolidHeap *)&audioAramHeap);
  TSolidHeap::alloc((TSolidHeap *)&audioAramHeap,iVar1 + -0x20);
  *(int *)this = iVar1 + -0x20;
  return;
}

}

namespace JAudio {

void __sinit_JASSystemHeap_cpp(void)

{
  ::JASystem::Kernel::TSolidHeap::TSolidHeap((TSolidHeap *)&::JASystem::Kernel::audioAramHeap);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}


namespace Kernel {

/* __thiscall TSolidHeap::~TSolidHeap(void) */

void __thiscall TSolidHeap::_TSolidHeap(TSolidHeap *this)

{
  short in_r4;
  
  if ((this != (TSolidHeap *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

