#include <gba/GBA.h>
#include <os/OSThread.h>
#include <os/OSAlarm.h>
#include <os/OSReset.h>
#include <gba/GBA.h>
#include <gba/GBAXfer.h>


namespace gba {
undefined SecParams;
undefined __GBA;
undefined4 __GBAReset;

void ShortCommandProc(int param_1)

{
  param_1 = param_1 * 0x100;
  if (*(int *)(&DAT_803ed300 + param_1) != 0) {
    return;
  }
  if (((&DAT_803ed2e5)[param_1] == '\0') && ((&DAT_803ed2e6)[param_1] == '\x04')) {
    **(byte **)(&DAT_803ed2f4 + param_1) = (&DAT_803ed2e7)[param_1] & 0x3a;
    return;
  }
  *(undefined4 *)(&DAT_803ed300 + param_1) = 1;
  return;
}


void GBAInit(void)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  puVar4 = &__GBA;
  iVar2 = 0;
  uVar1 = DAT_800000f8 >> 2;
  puVar3 = &SecParams;
  do {
    *(uint *)(puVar4 + 0x34) = (uVar1 / 0x1e848) * 0x3c >> 3;
    *(undefined4 *)(puVar4 + 0x30) = 0;
    os::OSInitThreadQueue(puVar4 + 0x24);
    iVar2 = iVar2 + 1;
    *(undefined **)(puVar4 + 0xf8) = puVar3;
    puVar4 = puVar4 + 0x100;
    puVar3 = puVar3 + 0x40;
  } while (iVar2 < 4);
  os::OSInitAlarm();
  __GBAReset = 0;
  os::OSRegisterResetFunction(&ResetFunctionInfo);
  return;
}


undefined4 GBAGetStatusAsync(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1 * 0x100;
  if (*(int *)(&DAT_803ed2fc + iVar1) == 0) {
    (&__GBA)[iVar1] = 0;
    *(undefined4 *)(&DAT_803ed2f4 + iVar1) = param_2;
    *(undefined4 *)(&DAT_803ed2fc + iVar1) = param_3;
    uVar2 = __GBATransfer(param_1,1,3,ShortCommandProc);
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}


void GBAGetStatus(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = param_1 * 0x100;
  if (*(int *)(&DAT_803ed2fc + iVar1) == 0) {
    (&__GBA)[iVar1] = 0;
    *(undefined4 *)(&DAT_803ed2f4 + iVar1) = param_2;
    *(code **)(&DAT_803ed2fc + iVar1) = __GBASyncCallback;
    iVar1 = __GBATransfer(param_1,1,3,ShortCommandProc);
  }
  else {
    iVar1 = 2;
  }
  if (iVar1 == 0) {
    __GBASync(param_1);
  }
  return;
}


undefined4 GBAResetAsync(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1 * 0x100;
  if (*(int *)(&DAT_803ed2fc + iVar1) == 0) {
    (&__GBA)[iVar1] = 0xff;
    *(undefined4 *)(&DAT_803ed2f4 + iVar1) = param_2;
    *(undefined4 *)(&DAT_803ed2fc + iVar1) = param_3;
    uVar2 = __GBATransfer(param_1,1,3,ShortCommandProc);
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}


void GBAReset(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = param_1 * 0x100;
  if (*(int *)(&DAT_803ed2fc + iVar1) == 0) {
    (&__GBA)[iVar1] = 0xff;
    *(undefined4 *)(&DAT_803ed2f4 + iVar1) = param_2;
    *(code **)(&DAT_803ed2fc + iVar1) = __GBASyncCallback;
    iVar1 = __GBATransfer(param_1,1,3,ShortCommandProc);
  }
  else {
    iVar1 = 2;
  }
  if (iVar1 == 0) {
    __GBASync(param_1);
  }
  return;
}


undefined4 OnReset(void)

{
  __GBAReset = 1;
  return 1;
}

