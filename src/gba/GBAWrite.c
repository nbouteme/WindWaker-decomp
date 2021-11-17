#include <gba/GBAWrite.h>
#include <gba/GBAWrite.h>
#include <gba/GBAXfer.h>


namespace gba {

void WriteProc(int param_1)

{
  param_1 = param_1 * 0x100;
  if (*(int *)(&DAT_803ed300 + param_1) != 0) {
    return;
  }
  **(byte **)(&DAT_803ed2f4 + param_1) = (&DAT_803ed2e5)[param_1] & 0x3a;
  return;
}


undefined4 GBAWriteAsync(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1 * 0x100;
  if (*(int *)(&DAT_803ed2fc + iVar1) == 0) {
    (&__GBA)[iVar1] = 0x15;
    copy_bytes((byte *)(iVar1 + -0x7fc12d1f),param_2,4);
    *(byte **)(&DAT_803ed2f8 + iVar1) = param_2;
    *(undefined4 *)(&DAT_803ed2f4 + iVar1) = param_3;
    *(undefined4 *)(&DAT_803ed2fc + iVar1) = param_4;
    uVar2 = __GBATransfer(param_1,5,1,WriteProc);
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}


void GBAWrite(int param_1,byte *param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = param_1 * 0x100;
  if (*(int *)(&DAT_803ed2fc + iVar1) == 0) {
    (&__GBA)[iVar1] = 0x15;
    copy_bytes((byte *)(iVar1 + -0x7fc12d1f),param_2,4);
    *(byte **)(&DAT_803ed2f8 + iVar1) = param_2;
    *(undefined4 *)(&DAT_803ed2f4 + iVar1) = param_3;
    *(code **)(&DAT_803ed2fc + iVar1) = __GBASyncCallback;
    iVar1 = __GBATransfer(param_1,5,1,WriteProc);
  }
  else {
    iVar1 = 2;
  }
  if (iVar1 == 0) {
    __GBASync(param_1);
  }
  return;
}

