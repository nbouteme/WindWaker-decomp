#include <OdemuExi2/DebuggerDriver.h>
#include <os/OSInterrupt.h>
#include <OdemuExi2/DebuggerDriver.h>


namespace OdemuExi2 {
undefined4 MTRCallback;
undefined4 DBGCallback;
undefined4 SendMailData;
undefined4 RecvDataLeng;
undefined4 pEXIInputFlag;
undefined1 EXIInputFlag;

void DBClose(void)

{
  return;
}


void DBOpen(void)

{
  return;
}


undefined4 DBWrite(undefined4 param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_3c [2];
  uint local_34 [2];
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  
  uVar2 = os::OSDisableInterrupts();
  do {
    DAT_cc006828 = DAT_cc006828 & 0x405 | 0xc0;
    local_28 = 0x40000000;
    uVar3 = DBGEXIImm(&local_28,2,1);
    countLeadingZeros(uVar3);
    do {
    } while ((DAT_cc006834 & 1) != 0);
    DBGEXIImm(&local_24,4,0);
    do {
    } while ((DAT_cc006834 & 1) != 0);
    DAT_cc006828 = DAT_cc006828 & 0x405;
  } while ((local_24 & 2) != 0);
  SendCount = SendCount + 1;
  if ((SendCount & 1) == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x1000;
  }
  do {
    iVar5 = DBGWrite(uVar4 | 0x1c000,param_1,param_2 + 3 & 0xfffffffc);
  } while (iVar5 == 0);
  do {
    DAT_cc006828 = DAT_cc006828 & 0x405 | 0xc0;
    local_2c = 0x40000000;
    uVar3 = DBGEXIImm(&local_2c,2,1);
    countLeadingZeros(uVar3);
    do {
    } while ((DAT_cc006834 & 1) != 0);
    DBGEXIImm(&local_24,4,0);
    do {
    } while ((DAT_cc006834 & 1) != 0);
    DAT_cc006828 = DAT_cc006828 & 0x405;
  } while ((local_24 & 2) != 0);
  uVar4 = (uint)SendCount;
  do {
    DAT_cc006828 = DAT_cc006828 | 0xc0;
    local_34[0] = uVar4 << 0x10 | 0x1f000000 | param_2 & 0x1fffffff | 0xc0000000;
    uVar3 = DBGEXIImm(local_34,4,1);
    uVar1 = countLeadingZeros(uVar3);
    do {
    } while ((DAT_cc006834 & 1) != 0);
    DAT_cc006828 = DAT_cc006828 & 0x405;
  } while (uVar1 >> 5 != 0);
  do {
    DAT_cc006828 = DAT_cc006828 | 0xc0;
    local_3c[0] = 0x40000000;
    uVar3 = DBGEXIImm(local_3c,2,1);
    uVar4 = countLeadingZeros(uVar3);
    do {
    } while ((DAT_cc006834 & 1) != 0);
    uVar3 = DBGEXIImm(&local_24,4,0);
    uVar1 = countLeadingZeros(uVar3);
    do {
    } while ((DAT_cc006834 & 1) != 0);
    DAT_cc006828 = DAT_cc006828 & 0x405;
  } while (((uVar4 | uVar1) >> 5 != 0) || ((local_24 & 2) != 0));
  os::OSRestoreInterrupts(uVar2);
  return 0;
}


undefined4 DBRead(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = os::OSDisableInterrupts();
  if ((SendMailData & 0x10000) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0x1000;
  }
  DBGRead(iVar2 + 0x1e000,param_1,param_2 + 3U & 0xfffffffc);
  RecvDataLeng = 0;
  EXIInputFlag = 0;
  os::OSRestoreInterrupts(uVar1);
  return 0;
}


uint DBQueryData(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint local_10 [3];
  
  EXIInputFlag = 0;
  if (RecvDataLeng == 0) {
    uVar2 = os::OSDisableInterrupts();
    DBGReadStatus(local_10);
    uVar1 = local_10[0];
    if ((local_10[0] & 1) != 0) {
      DBGReadMailbox(local_10);
      uVar1 = local_10[0] & 0x1fffffff;
      if ((local_10[0] & 0x1f000000) == 0x1f000000) {
        RecvDataLeng = local_10[0] & 0x7fff;
        EXIInputFlag = 1;
        SendMailData = uVar1;
      }
    }
    local_10[0] = uVar1;
    os::OSRestoreInterrupts(uVar2);
  }
  return RecvDataLeng;
}


void DBInitInterrupts(void)

{
  os::__OSMaskInterrupts(0x18000);
  os::__OSMaskInterrupts(0x40);
  DBGCallback = MWCallback;
  os::__OSSetInterruptHandler(0x19,DBGHandler);
  os::__OSUnmaskInterrupts(0x40);
  return;
}


void DBInitComm(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = os::OSDisableInterrupts();
  pEXIInputFlag = &EXIInputFlag;
  *param_1 = &EXIInputFlag;
  MTRCallback = param_2;
  os::__OSMaskInterrupts(0x18000);
  DAT_cc006828 = 0;
  os::OSRestoreInterrupts(uVar1);
  return;
}


void DBGHandler(short param_1)

{
  DAT_cc003000 = 0x1000;
  if (DBGCallback != (code *)0x0) {
    (*DBGCallback)((int)param_1);
  }
  return;
}


void MWCallback(void)

{
  EXIInputFlag = 1;
  if (MTRCallback != (code *)0x0) {
    (*MTRCallback)(0);
  }
  return;
}


uint DBGReadStatus(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_20 [3];
  
  DAT_cc006828 = DAT_cc006828 & 0x405 | 0xc0;
  local_20[0] = 0x40000000;
  uVar3 = DBGEXIImm(local_20,2,1);
  uVar1 = countLeadingZeros(uVar3);
  do {
  } while ((DAT_cc006834 & 1) != 0);
  uVar3 = DBGEXIImm(param_1,4,0);
  uVar2 = countLeadingZeros(uVar3);
  do {
  } while ((DAT_cc006834 & 1) != 0);
  uVar1 = countLeadingZeros((uVar1 | uVar2) >> 5);
  DAT_cc006828 = DAT_cc006828 & 0x405;
  return uVar1 >> 5;
}


uint DBGWrite(uint param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_20;
  uint local_1c;
  
  local_1c = (param_1 & 0x1fffc) << 8 | 0xa0000000;
  DAT_cc006828 = DAT_cc006828 & 0x405 | 0xc0;
  uVar3 = DBGEXIImm(&local_1c,4,1);
  uVar1 = countLeadingZeros(uVar3);
  uVar1 = uVar1 >> 5;
  do {
  } while ((DAT_cc006834 & 1) != 0);
  while (param_3 != 0) {
    local_20 = *param_2;
    param_2 = param_2 + 1;
    uVar3 = DBGEXIImm(&local_20,4,1);
    uVar2 = countLeadingZeros(uVar3);
    uVar1 = uVar1 | uVar2 >> 5;
    do {
    } while ((DAT_cc006834 & 1) != 0);
    param_3 = param_3 + -4;
    if (param_3 < 0) {
      param_3 = 0;
    }
  }
  uVar1 = countLeadingZeros(uVar1);
  DAT_cc006828 = DAT_cc006828 & 0x405;
  return uVar1 >> 5;
}


uint DBGRead(uint param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_20;
  uint local_1c;
  
  local_1c = (param_1 & 0x1fffc) << 8 | 0x20000000;
  DAT_cc006828 = DAT_cc006828 & 0x405 | 0xc0;
  uVar3 = DBGEXIImm(&local_1c,4,1);
  uVar1 = countLeadingZeros(uVar3);
  uVar1 = uVar1 >> 5;
  do {
  } while ((DAT_cc006834 & 1) != 0);
  while (param_3 != 0) {
    uVar3 = DBGEXIImm(&local_20,4,0);
    uVar2 = countLeadingZeros(uVar3);
    uVar1 = uVar1 | uVar2 >> 5;
    do {
    } while ((DAT_cc006834 & 1) != 0);
    param_3 = param_3 + -4;
    *param_2 = local_20;
    param_2 = param_2 + 1;
    if (param_3 < 0) {
      param_3 = 0;
    }
  }
  uVar1 = countLeadingZeros(uVar1);
  DAT_cc006828 = DAT_cc006828 & 0x405;
  return uVar1 >> 5;
}


uint DBGReadMailbox(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_20 [3];
  
  DAT_cc006828 = DAT_cc006828 & 0x405 | 0xc0;
  local_20[0] = 0x60000000;
  uVar3 = DBGEXIImm(local_20,2,1);
  uVar1 = countLeadingZeros(uVar3);
  do {
  } while ((DAT_cc006834 & 1) != 0);
  uVar3 = DBGEXIImm(param_1,4,0);
  uVar2 = countLeadingZeros(uVar3);
  do {
  } while ((DAT_cc006834 & 1) != 0);
  uVar1 = countLeadingZeros((uVar1 | uVar2) >> 5);
  DAT_cc006828 = DAT_cc006828 & 0x405;
  return uVar1 >> 5;
}


/* WARNING: Removing unreachable block (ram,0x80338538) */
/* WARNING: Removing unreachable block (ram,0x80338540) */
/* WARNING: Removing unreachable block (ram,0x80338554) */
/* WARNING: Removing unreachable block (ram,0x80338560) */
/* WARNING: Removing unreachable block (ram,0x80338574) */
/* WARNING: Removing unreachable block (ram,0x80338618) */
/* WARNING: Removing unreachable block (ram,0x80338628) */
/* WARNING: Removing unreachable block (ram,0x80338644) */

void DBGEXIImm(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_3 != 0) && (iVar2 = 0, 0 < param_2)) {
    if ((8 < param_2) && (uVar3 = param_2 - 1U >> 3, 0 < param_2 + -8)) {
      do {
        iVar2 = iVar2 + 8;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    iVar1 = param_2 - iVar2;
    if (iVar2 < param_2) {
      do {
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  do {
  } while( true );
}

