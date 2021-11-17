#include <gx/GXPerf.h>


namespace gx {

void GXSetGPMetric(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = gx;
  iVar2 = *(int *)(gx + 0x4e4);
  if (iVar2 == 0x22) {
LAB_80327420:
    write_volatile_1(DAT_cc008000,0x10);
    write_volatile_4(0xcc008000,0x1006);
    write_volatile_4(0xcc008000,0);
  }
  else {
    if (iVar2 < 0x22) {
      if (iVar2 < 0xb) {
        if (-1 < iVar2) goto LAB_80327420;
      }
      else {
        if (iVar2 < 0x1b) {
          write_volatile_1(DAT_cc008000,0x61);
          write_volatile_4(0xcc008000,0x23000000);
        }
        else {
          write_volatile_1(DAT_cc008000,0x61);
          write_volatile_4(0xcc008000,0x24000000);
        }
      }
    }
  }
  iVar2 = *(int *)(gx + 0x4e8);
  if (iVar2 != 0x15) {
    if (0x14 < iVar2) goto LAB_803274f4;
    if (8 < iVar2) {
      if (iVar2 < 0x11) {
        *(uint *)(gx + 0x4ec) = *(uint *)(gx + 0x4ec) & 0xffffff0f;
        write_volatile_1(DAT_cc008000,8);
        write_volatile_1(DAT_cc008000,0x20);
        write_volatile_4(0xcc008000,*(undefined4 *)(iVar1 + 0x4ec));
      }
      else {
        *(undefined2 *)(__cpReg + 6) = 0;
      }
      goto LAB_803274f4;
    }
    if (iVar2 < 0) goto LAB_803274f4;
  }
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,0x67000000);
LAB_803274f4:
  iVar1 = gx;
  *(undefined4 *)(gx + 0x4e4) = param_1;
  iVar2 = gx;
  if (*(uint *)(iVar1 + 0x4e4) < 0x24) {
                    /* WARNING: Could not recover jumptable at 0x8032751c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&_253)[*(uint *)(iVar1 + 0x4e4)])();
    return;
  }
  *(undefined4 *)(gx + 0x4e8) = param_2;
  if (0x16 < *(uint *)(iVar2 + 0x4e8)) {
    *(undefined2 *)(gx + 2) = 0;
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x80327948. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&_254)[*(uint *)(iVar2 + 0x4e8)])();
  return;
}


void GXClearGPMetric(void)

{
  *(undefined2 *)(__cpReg + 4) = 4;
  return;
}


void GXReadXfRasMetric
               (undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  
  sVar3 = *(short *)(__cpReg + 0x42);
  do {
    sVar2 = *(short *)(__cpReg + 0x42);
    bVar1 = sVar2 != sVar3;
    sVar3 = sVar2;
  } while (bVar1);
  *param_3 = CONCAT22(sVar2,*(undefined2 *)(__cpReg + 0x40));
  sVar3 = *(short *)(__cpReg + 0x46);
  do {
    sVar2 = *(short *)(__cpReg + 0x46);
    bVar1 = sVar2 != sVar3;
    sVar3 = sVar2;
  } while (bVar1);
  *param_4 = CONCAT22(sVar2,*(undefined2 *)(__cpReg + 0x44));
  sVar3 = *(short *)(__cpReg + 0x4a);
  do {
    sVar2 = *(short *)(__cpReg + 0x4a);
    bVar1 = sVar2 != sVar3;
    sVar3 = sVar2;
  } while (bVar1);
  *param_1 = CONCAT22(sVar2,*(undefined2 *)(__cpReg + 0x48));
  sVar3 = *(short *)(__cpReg + 0x4e);
  do {
    sVar2 = *(short *)(__cpReg + 0x4e);
    bVar1 = sVar2 != sVar3;
    sVar3 = sVar2;
  } while (bVar1);
  *param_2 = CONCAT22(sVar2,*(undefined2 *)(__cpReg + 0x4c));
  return;
}

