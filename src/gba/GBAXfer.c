#include <gba/GBAXfer.h>
#include <os/OSContext.h>
#include <os/OSThread.h>
#include <os/OSInterrupt.h>
#include <gba/GBAXfer.h>
#include <si/SIBios.h>


namespace gba {

void __GBAHandler(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  code *pcVar2;
  undefined auStack736 [724];
  
  iVar1 = param_1 * 0x100;
  if (__GBAReset == 0) {
    if ((param_2 & 0xf) == 0) {
      *(undefined4 *)(&DAT_803ed300 + iVar1) = 0;
    }
    else {
      *(undefined4 *)(&DAT_803ed300 + iVar1) = 1;
    }
    pcVar2 = *(code **)(&DAT_803ed318 + iVar1);
    if (pcVar2 != (code *)0x0) {
      *(undefined4 *)(&DAT_803ed318 + iVar1) = 0;
      (*pcVar2)(param_1);
    }
    if (*(int *)(&DAT_803ed2fc + iVar1) != 0) {
      os::OSClearContext(auStack736);
      os::OSSetCurrentContext(auStack736);
      pcVar2 = *(code **)(&DAT_803ed2fc + iVar1);
      *(undefined4 *)(&DAT_803ed2fc + iVar1) = 0;
      (*pcVar2)(param_1,*(undefined4 *)(&DAT_803ed300 + iVar1));
      os::OSClearContext(auStack736);
      os::OSSetCurrentContext(param_3);
    }
  }
  return;
}


void __GBASyncCallback(int param_1)

{
  os::OSWakeupThread(&DAT_803ed304 + param_1 * 0x100);
  return;
}


undefined4 __GBASync(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  param_1 = param_1 * 0x100;
  uVar1 = os::OSDisableInterrupts();
  while (*(int *)(&DAT_803ed2fc + param_1) != 0) {
    os::OSSleepThread(&DAT_803ed304 + param_1);
  }
  uVar2 = *(undefined4 *)(&DAT_803ed300 + param_1);
  os::OSRestoreInterrupts(uVar1);
  return uVar2;
}


void TypeAndStatusCallback(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined auStack736 [724];
  
  iVar1 = param_1 * 0x100;
  if (((param_2 & 0xff) == 0) && ((param_2 & 0xffff0000) == 0x40000)) {
    iVar2 = si::SITransfer(param_1,&__GBA + iVar1,*(undefined4 *)(&DAT_803ed2ec + iVar1),
                           &DAT_803ed2e5 + iVar1,*(undefined4 *)(&DAT_803ed2f0 + iVar1),__GBAHandler
                           ,(&DAT_803ed310)[param_1 * 0x40],(&DAT_803ed314)[param_1 * 0x40]);
    if (iVar2 != 0) {
      return;
    }
    *(undefined4 *)(&DAT_803ed300 + iVar1) = 2;
  }
  else {
    *(undefined4 *)(&DAT_803ed300 + iVar1) = 1;
  }
  pcVar4 = *(code **)(&DAT_803ed318 + iVar1);
  if (pcVar4 != (code *)0x0) {
    *(undefined4 *)(&DAT_803ed318 + iVar1) = 0;
    (*pcVar4)(param_1);
  }
  if (*(int *)(&DAT_803ed2fc + iVar1) != 0) {
    uVar3 = os::OSGetCurrentContext();
    os::OSClearContext(auStack736);
    os::OSSetCurrentContext(auStack736);
    pcVar4 = *(code **)(&DAT_803ed2fc + iVar1);
    *(undefined4 *)(&DAT_803ed2fc + iVar1) = 0;
    (*pcVar4)(param_1,*(undefined4 *)(&DAT_803ed300 + iVar1));
    os::OSClearContext(auStack736);
    os::OSSetCurrentContext(uVar3);
    os::__OSReschedule();
  }
  return;
}


undefined4 __GBATransfer(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1 * 0x100;
  uVar2 = os::OSDisableInterrupts();
  *(undefined4 *)(&DAT_803ed318 + iVar1) = param_4;
  *(undefined4 *)(&DAT_803ed2ec + iVar1) = param_2;
  *(undefined4 *)(&DAT_803ed2f0 + iVar1) = param_3;
  si::SIGetTypeAsync(param_1,TypeAndStatusCallback);
  os::OSRestoreInterrupts(uVar2);
  return 0;
}


undefined8 __GBASetDelay(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(&DAT_803ed310 + param_1 * 0x40);
  (&DAT_803ed314)[param_1 * 0x40] = param_4;
  (&DAT_803ed310)[param_1 * 0x40] = param_3;
  return uVar1;
}

