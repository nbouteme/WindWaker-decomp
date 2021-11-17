#include <JAudio/JASCmdStack.h>
#include <JAudio/JASCmdStack.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <os/OSInterrupt.h>
#include <JAudio/JASCallback.h>
#include <JASystem/Kernel/TPortCmd.h>
#include <JASystem/Kernel.h>


namespace JAudio {
undefined cmd_once;
undefined cmd_stay;

namespace Kernel {

/* __thiscall TPortCmd::TPortCmd(void) */

void __thiscall TPortCmd::TPortCmd(TPortCmd *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  return;
}


/* __thiscall TPortCmd::addPortCmdOnce(void) */

void __thiscall TPortCmd::addPortCmdOnce(TPortCmd *this)

{
  addPortCmd(this,(TPortHead *)&JAudio::cmd_once);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TPortCmd::setPortCmd(void *(TPortArgs *),
                                                     TPortArgs *) */

undefined4 __thiscall
TPortCmd::setPortCmd(TPortCmd *this,FuncDef574 *param_1,TPortArgs *param_2)

{
  ulong uVar1;
  
  if (param_1 == (FuncDef574 *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASCmdStack.cpp",0x53,"func != 0");
    m_Do_printf::OSPanic("JASCmdStack.cpp",0x53,&DAT_8036733a);
  }
  if (param_2 == (TPortArgs *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASCmdStack.cpp",0x54,"pargs != 0");
    m_Do_printf::OSPanic("JASCmdStack.cpp",0x54,&DAT_8036733a);
  }
  *(FuncDef574 **)(this + 8) = param_1;
  *(TPortArgs **)(this + 0xc) = param_2;
  *(undefined4 *)this = 0;
  return 1;
}


/* __thiscall TPortCmd::addPortCmd(TPortHead *) */

undefined4 __thiscall TPortCmd::addPortCmd(TPortCmd *this,TPortHead *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  
  if (param_1 == (TPortHead *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASCmdStack.cpp",0x69,"phead != 0");
    m_Do_printf::OSPanic("JASCmdStack.cpp",0x69,&DAT_8036733a);
  }
  uVar2 = os::OSDisableInterrupts();
  if (*(int *)this == 0) {
    if (*(int *)(param_1 + 4) == 0) {
      *(TPortCmd **)param_1 = this;
    }
    else {
      *(TPortCmd **)(*(int *)(param_1 + 4) + 4) = this;
    }
    *(TPortCmd **)(param_1 + 4) = this;
    *(undefined4 *)(this + 4) = 0;
    *(TPortHead **)this = param_1;
    os::OSRestoreInterrupts(uVar2);
    uVar2 = 1;
  }
  else {
    os::OSRestoreInterrupts();
    uVar2 = 0;
  }
  return uVar2;
}

}

/* __thiscall Kernel::portCmdProcOnce(Kernel::TPortHead *) */

void __thiscall Kernel::portCmdProcOnce(Kernel *this,TPortHead *param_1)

{
  ulong uVar1;
  int iVar2;
  TPortHead *extraout_r4;
  TPortHead *extraout_r4_00;
  
  if (this == (Kernel *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASCmdStack.cpp",0xdf,"phead != 0");
    m_Do_printf::OSPanic("JASCmdStack.cpp",0xdf,&DAT_8036733a);
    param_1 = extraout_r4;
  }
  while( true ) {
    iVar2 = getPortCmd(this,param_1);
    if (iVar2 == 0) break;
    (**(code **)(iVar2 + 8))(*(undefined4 *)(iVar2 + 0xc));
    param_1 = extraout_r4_00;
  }
  return;
}


/* __thiscall Kernel::portCmdProcStay(Kernel::TPortHead *) */

void __thiscall Kernel::portCmdProcStay(Kernel *this,TPortHead *param_1)

{
  ulong uVar1;
  TPortHead *extraout_r4;
  TPortHead *extraout_r4_00;
  int iVar2;
  
  if (this == (Kernel *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASCmdStack.cpp",0xf5,"phead != 0");
    m_Do_printf::OSPanic("JASCmdStack.cpp",0xf5,&DAT_8036733a);
    param_1 = extraout_r4;
  }
  for (iVar2 = *(int *)this; iVar2 != 0; iVar2 = *(int *)(iVar2 + 4)) {
    (**(code **)(iVar2 + 8))(*(undefined4 *)(iVar2 + 0xc),param_1);
    param_1 = extraout_r4_00;
  }
  return;
}


/* __thiscall Kernel::portHeadInit(Kernel::TPortHead *) */

void __thiscall Kernel::portHeadInit(Kernel *this,TPortHead *param_1)

{
  ulong uVar1;
  
  if (this == (Kernel *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASCmdStack.cpp",0x10b,"phead != 0");
    m_Do_printf::OSPanic("JASCmdStack.cpp",0x10b,&DAT_8036733a);
  }
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  return;
}


/* __thiscall Kernel::portCmdInit(void) */

void __thiscall Kernel::portCmdInit(Kernel *this)

{
  TPortHead *in_r4;
  TPortHead *extraout_r4;
  void *in_r5;
  
  portHeadInit((Kernel *)&JAudio::cmd_once,in_r4);
  portHeadInit((Kernel *)&JAudio::cmd_stay,extraout_r4);
  registerDspCallback((Kernel *)portCmdMain,(FuncDef571 *)0x0,in_r5);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall Kernel::getPortCmd(Kernel::TPortHead *) */

Kernel ** __thiscall Kernel::getPortCmd(Kernel *this,TPortHead *param_1)

{
  ulong uVar1;
  TPortHead *extraout_r4;
  Kernel **ppKVar2;
  Kernel **ppKVar3;
  
  if (this == (Kernel *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASCmdStack.cpp",0x137,"phead != 0");
    m_Do_printf::OSPanic("JASCmdStack.cpp",0x137,&DAT_8036733a);
    param_1 = extraout_r4;
  }
  ppKVar3 = *(Kernel ***)this;
  ppKVar2 = (Kernel **)0x0;
  if (ppKVar3 != (Kernel **)0x0) {
    *(Kernel **)this = ppKVar3[1];
    if (*(int *)this == 0) {
      *(undefined4 *)(this + 4) = 0;
    }
    if (this != *ppKVar3) {
      m_Do_printf::OSReport
                ("[JASKernel::getPortCmd] 不正な登録データブロックです。\n",param_1);
    }
    *ppKVar3 = (Kernel *)0x0;
    ppKVar2 = ppKVar3;
  }
  return ppKVar2;
}


/* __thiscall Kernel::portCmdMain(void *) */

undefined4 __thiscall Kernel::portCmdMain(Kernel *this,void *param_1)

{
  TPortHead *extraout_r4;
  
  portCmdProcOnce((Kernel *)&JAudio::cmd_once,(TPortHead *)param_1);
  portCmdProcStay((Kernel *)&JAudio::cmd_stay,extraout_r4);
  return 0;
}

