#include <gba/GBARead.h>
#include <gba/GBARead.h>
#include <gba/GBAXfer.h>


namespace gba {

void ReadProc(int param_1)

{
  param_1 = param_1 * 0x100;
  if (*(int *)(&DAT_803ed300 + param_1) == 0) {
    copy_bytes(*(byte **)(&DAT_803ed2f8 + param_1),&DAT_803ed2e5 + param_1,4);
    **(byte **)(&DAT_803ed2f4 + param_1) = (&DAT_803ed2e9)[param_1] & 0x3a;
  }
  return;
}


undefined4 GBAReadAsync(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1 * 0x100;
  if (*(int *)(&DAT_803ed2fc + iVar1) == 0) {
    (&__GBA)[iVar1] = 0x14;
    *(undefined4 *)(&DAT_803ed2f8 + iVar1) = param_2;
    *(undefined4 *)(&DAT_803ed2f4 + iVar1) = param_3;
    *(undefined4 *)(&DAT_803ed2fc + iVar1) = param_4;
    uVar2 = __GBATransfer(param_1,1,5,ReadProc);
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}


void GBARead(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = param_1 * 0x100;
  if (*(int *)(&DAT_803ed2fc + iVar1) == 0) {
    (&__GBA)[iVar1] = 0x14;
    *(undefined4 *)(&DAT_803ed2f8 + iVar1) = param_2;
    *(undefined4 *)(&DAT_803ed2f4 + iVar1) = param_3;
    *(code **)(&DAT_803ed2fc + iVar1) = __GBASyncCallback;
    iVar1 = __GBATransfer(param_1,1,5,ReadProc);
  }
  else {
    iVar1 = 2;
  }
  if (iVar1 == 0) {
    __GBASync(param_1);
  }
  return;
}

