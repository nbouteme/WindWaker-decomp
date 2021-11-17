#include <JAudio/JASCallback.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <os/OSInterrupt.h>
#include <JAudio/JASCallback.h>
#include <JASystem/Kernel.h>


namespace JASystem {
undefined1 Kernel;
undefined1 Kernel;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Kernel::resetCallback(void) */

Kernel * __thiscall Kernel::resetCallback(Kernel *this)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  
  if (callbackInit != '\x01') {
    _callList = JKernel::operator_new__(_maxCallbacksUser * 0xc,JAudio::JASDram,0);
    if (_callList == 0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"JASCallback.cpp",0x3a,"callList != 0");
      m_Do_printf::OSPanic("JASCallback.cpp",0x3a,&DAT_80366dc6);
    }
    os::OSDisableInterrupts();
    iVar2 = 0;
    for (uVar3 = 0; uVar3 < _maxCallbacksUser; uVar3 = uVar3 + 1) {
      *(undefined4 *)(_callList + iVar2) = 0;
      iVar2 = iVar2 + 0xc;
    }
    callbackInit = '\x01';
    this = (Kernel *)os::OSRestoreInterrupts();
  }
  return this;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Kernel::checkCallback(long *(void *),
                                              void *) */

int __thiscall Kernel::checkCallback(Kernel *this,FuncDef570 *param_1,void *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (callbackInit == '\0') {
    return -1;
  }
  iVar2 = 0;
  iVar1 = 0;
  iVar3 = _maxCallbacksUser;
  if (_maxCallbacksUser != 0) {
    do {
      if ((*(Kernel **)(_callList + iVar1) == this) &&
         (((Kernel **)(_callList + iVar1))[1] == (Kernel *)param_1)) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0xc;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return -1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Kernel::registerDspCallback(long *(void *),
                                                    void *) */

int __thiscall Kernel::registerDspCallback(Kernel *this,FuncDef571 *param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (callbackInit == '\0') {
    iVar1 = -1;
  }
  else {
    uVar2 = os::OSDisableInterrupts();
    iVar1 = registerSubFrameCallback(this,(FuncDef572 *)param_1,param_2);
    if (iVar1 == -1) {
      os::OSRestoreInterrupts(uVar2);
      iVar1 = -1;
    }
    else {
      *(undefined4 *)(_callList + iVar1 * 0xc + 8) = 1;
      os::OSRestoreInterrupts(uVar2);
    }
  }
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Kernel::registerSubFrameCallback(long *(void *),
                                                         void *) */

undefined * __thiscall
Kernel::registerSubFrameCallback(Kernel *this,FuncDef572 *param_1,void *param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  
  if (callbackInit == '\0') {
    puVar1 = &DAT_ffffffff;
  }
  else {
    puVar1 = (undefined *)0x0;
    iVar2 = 0;
    puVar3 = _maxCallbacksUser;
    if (_maxCallbacksUser != (undefined *)0x0) {
      do {
        if (*(int *)(_callList + iVar2) == 0) break;
        puVar1 = puVar1 + 1;
        iVar2 = iVar2 + 0xc;
        puVar3 = puVar3 + -1;
      } while (puVar3 != (undefined *)0x0);
    }
    if (puVar1 == _maxCallbacksUser) {
      m_Do_printf::OSReport
                (
                "[JASKernel::registerAiCallbak] コールバック登録バッファが一杯です。\n"
                );
      puVar1 = &DAT_ffffffff;
    }
    else {
      iVar2 = checkCallback(this,(FuncDef570 *)param_1,_maxCallbacksUser);
      if (iVar2 == -1) {
        os::OSDisableInterrupts();
        iVar2 = (int)puVar1 * 0xc;
        *(Kernel **)(_callList + iVar2) = this;
        *(FuncDef572 **)(_callList + iVar2 + 4) = param_1;
        *(undefined4 *)(_callList + iVar2 + 8) = 0;
        os::OSRestoreInterrupts();
      }
      else {
        puVar1 = &DAT_ffffffff;
      }
    }
  }
  return puVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Kernel::aiCallback(void) */

Kernel * __thiscall Kernel::aiCallback(Kernel *this)

{
  code **ppcVar1;
  uint uVar2;
  int iVar3;
  
  if (callbackInit != '\0') {
    iVar3 = 0;
    for (uVar2 = 0; uVar2 < _maxCallbacksUser; uVar2 = uVar2 + 1) {
      this = (Kernel *)((int)_callList + iVar3);
      if (((*(code **)this != (code *)0x0) && (*(code **)((int)this + 8) == (code *)0x0)) &&
         (this = (Kernel *)(**(code **)this)(*(code **)((int)this + 4)), ppcVar1 = _callList,
         this == (Kernel *)&DAT_ffffffff)) {
        *(undefined4 *)((int)_callList + iVar3) = 0;
        this = (Kernel *)ppcVar1;
      }
      iVar3 = iVar3 + 0xc;
    }
  }
  return this;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Kernel::subframeCallback(void) */

Kernel * __thiscall Kernel::subframeCallback(Kernel *this)

{
  code **ppcVar1;
  uint uVar2;
  int iVar3;
  
  if (callbackInit != '\0') {
    iVar3 = 0;
    for (uVar2 = 0; uVar2 < _maxCallbacksUser; uVar2 = uVar2 + 1) {
      this = (Kernel *)((int)_callList + iVar3);
      if (((*(code **)this != (code *)0x0) && (*(code **)((int)this + 8) == (code *)&DAT_00000001))
         && (this = (Kernel *)(**(code **)this)(*(code **)((int)this + 4)), ppcVar1 = _callList,
            this == (Kernel *)&DAT_ffffffff)) {
        *(undefined4 *)((int)_callList + iVar3) = 0;
        this = (Kernel *)ppcVar1;
      }
      iVar3 = iVar3 + 0xc;
    }
  }
  return this;
}

