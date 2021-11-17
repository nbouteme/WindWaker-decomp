#include <gba/GBAGetProcessStatus.h>
#include <os/OSTime.h>
#include <Runtime.PPCEABI.H/runtime.h>


namespace gba {

undefined4 GBAGetProcessStatus(int param_1,undefined *param_2)

{
  int iVar1;
  uint uVar2;
  uint extraout_r4;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  param_1 = param_1 * 0x100;
  if ((*(int *)(&DAT_803ed2fc + param_1) == 0) && (*(int *)(&DAT_803ed334 + param_1) == 0)) {
    uVar5 = 0;
  }
  else {
    uVar5 = 2;
    if (*(int *)(&DAT_803ed334 + param_1) != 0) {
      uVar2 = (*(int *)(&DAT_803ed354 + param_1) * 100) / *(int *)(&DAT_803ed384 + param_1);
      uVar4 = uVar2 & 0xff;
      if ((*(uint *)(&DAT_803ed34c + param_1) | *(uint *)(&DAT_803ed348 + param_1)) != 0) {
        iVar1 = os::OSGetTime();
        uVar3 = uVar2 - *(uint *)(&DAT_803ed34c + param_1);
        iVar1 = iVar1 - ((uint)(uVar2 < *(uint *)(&DAT_803ed34c + param_1)) +
                        *(int *)(&DAT_803ed348 + param_1));
        uVar6 = Runtime.PPCEABI.H::__div2i(iVar1,uVar3,0,(DAT_800000f8 >> 2) / 1000);
        if (((uint)((ulonglong)uVar6 >> 0x20) ^ 0x80000000) < ((uint)uVar6 < 0x157c) + 0x80000000) {
          uVar2 = (DAT_800000f8 >> 2) / 1000;
          Runtime.PPCEABI.H::__div2i
                    ((int)((ulonglong)uVar4 * (ulonglong)uVar3 >> 0x20) + uVar4 * iVar1,
                     uVar4 * uVar3,(int)((ulonglong)uVar2 * 0x157c >> 0x20),uVar2 * 0x157c);
          uVar4 = extraout_r4;
        }
        if (99 < (uVar4 & 0xff)) {
          uVar4 = 100;
        }
      }
      if (param_2 != (undefined *)0x0) {
        *param_2 = (char)uVar4;
      }
    }
  }
  return uVar5;
}

