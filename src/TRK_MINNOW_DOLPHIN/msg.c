#include <TRK_MINNOW_DOLPHIN/msg.h>
#include <TRK_MINNOW_DOLPHIN/dolphin_trk_glue.h>


namespace TRK_MINNOW_DOLPHIN {

void TRKMessageSend(int param_1)

{
  byte bVar2;
  int iVar1;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  byte bVar8;
  uint uVar9;
  
  bVar2 = 0;
  uVar5 = *(uint *)(param_1 + 8);
  uVar4 = 0;
  if (uVar5 != 0) {
    if ((8 < uVar5) && (uVar9 = uVar5 - 1 >> 3, uVar5 != 8)) {
      do {
        iVar6 = uVar4 + 0x10;
        uVar4 = uVar4 + 8;
        pcVar7 = (char *)(param_1 + iVar6);
        bVar2 = bVar2 + *pcVar7 + pcVar7[1] + pcVar7[2] + pcVar7[3] + pcVar7[4] + pcVar7[5] +
                pcVar7[6] + pcVar7[7];
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
    }
    iVar6 = uVar5 - uVar4;
    if (uVar4 < uVar5) {
      do {
        iVar1 = uVar4 + 0x10;
        uVar4 = uVar4 + 1;
        bVar2 = bVar2 + *(char *)(param_1 + iVar1);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  bVar3 = bVar2 ^ 0xff;
  iVar6 = WriteUART1(0x7e);
  if (iVar6 == 0) {
    for (uVar4 = 0; uVar4 < *(uint *)(param_1 + 8); uVar4 = uVar4 + 1) {
      bVar8 = *(byte *)(param_1 + uVar4 + 0x10);
      if ((bVar8 == 0x7e) || (bVar8 == 0x7d)) {
        iVar6 = WriteUART1(0x7d);
        bVar8 = bVar8 ^ 0x20;
        if (iVar6 != 0) break;
      }
      iVar6 = WriteUART1((int)(char)bVar8);
      if (iVar6 != 0) break;
    }
  }
  if (iVar6 == 0) {
    if ((bVar3 == 0x7e) || (bVar3 == 0x7d)) {
      iVar6 = WriteUART1(0x7d);
      bVar3 = bVar2 ^ 0xdf;
      if (iVar6 != 0) goto LAB_80331524;
    }
    iVar6 = WriteUART1((int)(char)bVar3);
  }
LAB_80331524:
  if (iVar6 == 0) {
    iVar6 = WriteUART1(0x7e);
  }
  if (iVar6 == 0) {
    WriteUARTFlush();
  }
  return;
}

