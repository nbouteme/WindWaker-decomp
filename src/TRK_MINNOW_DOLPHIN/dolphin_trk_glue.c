#include <TRK_MINNOW_DOLPHIN/dolphin_trk_glue.h>
#include <TRK_MINNOW_DOLPHIN/targimpl.h>
#include <m_Do_printf.h>
#include <odenotstub/odenotstub.h>
#include <OdemuExi2/DebuggerDriver.h>
#include <amcstubs/AmcExi2Stubs.h>
#include <os/OSThread.h>
#include <TRK_MINNOW_DOLPHIN/dolphin_trk_glue.h>


namespace TRK_MINNOW_DOLPHIN {
undefined4 gWritePos;
undefined4 gReadPos;
undefined4 gReadCount;
undefined _MetroTRK_Has_Framing;
undefined1 gReadBuf;
undefined gWriteBuf;

void TRKLoadContext
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(ushort *)(param_1 + 0x1a2);
  uVar2 = (uint)uVar1;
  uVar3 = uVar1 & 2;
  if ((uVar1 & 2) != 0) {
    *(ushort *)(param_1 + 0x1a2) = uVar1 & 0xfffd;
    uVar2 = *(uint *)(param_1 + 0x14);
    uVar3 = *(uint *)(param_1 + 0x18);
    param_5 = *(undefined4 *)(param_1 + 0x1c);
    param_6 = *(undefined4 *)(param_1 + 0x20);
    param_7 = *(undefined4 *)(param_1 + 0x24);
    param_8 = *(undefined4 *)(param_1 + 0x28);
  }
  TRKInterruptHandler(param_2,*(undefined4 *)(param_1 + 0x19c),uVar2,uVar3,param_5,param_6,param_7,
                      param_8);
  return;
}


void TRKUARTInterruptHandler(void)

{
  return;
}


void TRK_board_display(void)

{
  m_Do_printf::OSReport();
  return;
}


void UnreserveEXI2Port(void)

{
  (*DAT_803a2948)();
  return;
}


void ReserveEXI2Port(void)

{
  (*DAT_803a2944)();
  return;
}


int TRKReadUARTPoll(undefined *param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 4;
  if (gReadCount <= gReadPos) {
    gReadPos = 0;
    gReadCount = (*DAT_803a2938)();
    if (0 < gReadCount) {
      if (0x110a < gReadCount) {
        gReadCount = 0x110a;
      }
      uVar2 = (*DAT_803a293c)(&gReadBuf,gReadCount);
      iVar3 = (int)(-uVar2 | uVar2) >> 0x1f;
      if ((int)(-uVar2 | uVar2) < 0) {
        gReadCount = 0;
      }
    }
  }
  if (gReadPos < gReadCount) {
    iVar3 = 0;
    puVar1 = &gReadBuf + gReadPos;
    gReadPos = gReadPos + 1;
    *param_1 = *puVar1;
  }
  return iVar3;
}


undefined4 WriteUART1(undefined param_1)

{
  (&gWriteBuf)[gWritePos] = param_1;
  gWritePos = gWritePos + 1;
  return 0;
}


int WriteUARTFlush(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  
  iVar1 = 0;
  puVar4 = &gWriteBuf + gWritePos;
  uVar2 = 0x800 - gWritePos;
  if (gWritePos < 0x800) {
    uVar5 = uVar2 >> 3;
    uVar3 = uVar2;
    if (uVar5 == 0) goto LAB_803377e0;
    do {
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      puVar4[5] = 0;
      puVar4[6] = 0;
      puVar4[7] = 0;
      puVar4 = puVar4 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
    for (uVar3 = uVar2 & 7; uVar3 != 0; uVar3 = uVar3 - 1) {
LAB_803377e0:
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    gWritePos = gWritePos + uVar2;
  }
  if (gWritePos != 0) {
    uVar2 = (*DAT_803a2940)(&gWriteBuf);
    gWritePos = 0;
    iVar1 = (int)(-uVar2 | uVar2) >> 0x1f;
  }
  return iVar1;
}


void EnableEXI2Interrupts(void)

{
  (*DAT_803a2934)();
  return;
}


undefined4 TRKInitializeIntDrivenUART(void)

{
  undefined4 in_r6;
  
  (*gDBCommTable)(in_r6,TRKEXICallBack);
  return 0;
}


void InitMetroTRKCommTable(int param_1)

{
  if (param_1 == 1) {
    m_Do_printf::OSReport("MetroTRK : Set to GDEV hardware\n");
    odenotstub::Hu_IsStub();
    gDBCommTable = OdemuExi2::DBInitComm;
    DAT_803a2934 = OdemuExi2::DBInitInterrupts;
    DAT_803a2938 = OdemuExi2::DBQueryData;
    DAT_803a293c = OdemuExi2::DBRead;
    DAT_803a2940 = OdemuExi2::DBWrite;
    DAT_803a2944 = OdemuExi2::DBOpen;
    DAT_803a2948 = OdemuExi2::DBClose;
  }
  else {
    m_Do_printf::OSReport("MetroTRK : Set to AMC DDH hardware\n");
    amcstubs::AMC_IsStub();
    gDBCommTable = amcstubs::EXI2_Init;
    DAT_803a2934 = amcstubs::EXI2_EnableInterrupts;
    DAT_803a2938 = amcstubs::EXI2_Poll;
    DAT_803a293c = amcstubs::EXI2_ReadN;
    DAT_803a2940 = amcstubs::EXI2_WriteN;
    DAT_803a2944 = amcstubs::EXI2_Reserve;
    DAT_803a2948 = amcstubs::EXI2_Unreserve;
  }
  return;
}


void TRKEXICallBack(undefined4 param_1,undefined4 param_2)

{
  os::OSEnableScheduler();
  TRKLoadContext(param_2,0x500);
  return;
}

