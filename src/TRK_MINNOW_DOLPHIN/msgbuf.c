#include <TRK_MINNOW_DOLPHIN/msgbuf.h>
#include <TRK_MINNOW_DOLPHIN/msgbuf.h>
#include <TRK_MINNOW_DOLPHIN/mutex_TRK.h>
#include <TRK_MINNOW_DOLPHIN/usr_put.h>


namespace TRK_MINNOW_DOLPHIN {
undefined gTRKMsgBufs;

void TRKReadBuffer_ui32(int param_1,undefined *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  undefined auStack40 [8];
  
  iVar2 = 0;
  for (iVar5 = 0; (iVar2 == 0 && (iVar5 < param_3)); iVar5 = iVar5 + 1) {
    puVar4 = param_2;
    if (gTRKBigEndian == 0) {
      puVar4 = auStack40;
    }
    iVar2 = 0;
    uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc);
    uVar3 = 4;
    if (uVar1 < 4) {
      iVar2 = 0x302;
      uVar3 = uVar1;
    }
    FUN_80003510(puVar4,param_1 + *(int *)(param_1 + 0xc) + 0x10,uVar3);
    *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + uVar3;
    if ((gTRKBigEndian == 0) && (iVar2 == 0)) {
      *param_2 = puVar4[3];
      param_2[1] = puVar4[2];
      param_2[2] = puVar4[1];
      param_2[3] = *puVar4;
    }
    param_2 = param_2 + 4;
  }
  return;
}


void TRKReadBuffer_ui8(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  for (iVar3 = 0; (iVar2 == 0 && (iVar3 < param_3)); iVar3 = iVar3 + 1) {
    iVar2 = 0;
    iVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc);
    iVar4 = 1;
    if (iVar1 == 0) {
      iVar2 = 0x302;
      iVar4 = iVar1;
    }
    FUN_80003510(param_2 + iVar3,param_1 + *(int *)(param_1 + 0xc) + 0x10,iVar4);
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + iVar4;
  }
  return;
}


int TRKReadBuffer1_ui64(int param_1,undefined *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  undefined auStack40 [20];
  
  puVar4 = param_2;
  if (gTRKBigEndian == 0) {
    puVar4 = auStack40;
  }
  iVar3 = 0;
  uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc);
  uVar2 = 8;
  if (uVar1 < 8) {
    iVar3 = 0x302;
    uVar2 = uVar1;
  }
  FUN_80003510(puVar4,param_1 + *(int *)(param_1 + 0xc) + 0x10,uVar2);
  *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + uVar2;
  if ((gTRKBigEndian == 0) && (iVar3 == 0)) {
    *param_2 = puVar4[7];
    param_2[1] = puVar4[6];
    param_2[2] = puVar4[5];
    param_2[3] = puVar4[4];
    param_2[4] = puVar4[3];
    param_2[5] = puVar4[2];
    param_2[6] = puVar4[1];
    param_2[7] = *puVar4;
  }
  return iVar3;
}


int TRKReadBuffer1_ui32(int param_1,undefined *param_2)

{
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined auStack40 [20];
  
  puVar2 = param_2;
  if (gTRKBigEndian == 0) {
    puVar2 = auStack40;
  }
  iVar4 = 0;
  uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc);
  uVar3 = 4;
  if (uVar1 < 4) {
    iVar4 = 0x302;
    uVar3 = uVar1;
  }
  FUN_80003510(puVar2,param_1 + *(int *)(param_1 + 0xc) + 0x10,uVar3);
  *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + uVar3;
  if ((gTRKBigEndian == 0) && (iVar4 == 0)) {
    *param_2 = puVar2[3];
    param_2[1] = puVar2[2];
    param_2[2] = puVar2[1];
    param_2[3] = *puVar2;
  }
  return iVar4;
}


int TRKReadBuffer1_ui16(int param_1,undefined *param_2)

{
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined auStack40 [20];
  
  puVar2 = param_2;
  if (gTRKBigEndian == 0) {
    puVar2 = auStack40;
  }
  iVar4 = 0;
  uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc);
  uVar3 = 2;
  if (uVar1 < 2) {
    iVar4 = 0x302;
    uVar3 = uVar1;
  }
  FUN_80003510(puVar2,param_1 + *(int *)(param_1 + 0xc) + 0x10,uVar3);
  *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + uVar3;
  if ((gTRKBigEndian == 0) && (iVar4 == 0)) {
    *param_2 = puVar2[1];
    param_2[1] = *puVar2;
  }
  return iVar4;
}


undefined4 TRKReadBuffer1_ui8(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc);
  iVar2 = 1;
  if (iVar1 == 0) {
    uVar3 = 0x302;
    iVar2 = iVar1;
  }
  FUN_80003510(param_2,param_1 + *(int *)(param_1 + 0xc) + 0x10,iVar2);
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + iVar2;
  return uVar3;
}


/* WARNING: Could not reconcile some variable overlaps */

void TRKAppendBuffer_ui32(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_28;
  undefined local_24;
  undefined local_23;
  undefined local_22;
  undefined local_21;
  
  iVar1 = 0;
  for (iVar3 = 0; (iVar1 == 0 && (iVar3 < param_3)); iVar3 = iVar3 + 1) {
    local_28 = *param_2;
    if (gTRKBigEndian == 0) {
      puVar2 = (undefined4 *)&local_24;
      local_28._2_1_ = (undefined)((uint)local_28 >> 8);
      local_28._1_1_ = (undefined)((uint)local_28 >> 0x10);
      local_28._0_1_ = (undefined)((uint)local_28 >> 0x18);
      local_24 = (undefined)local_28;
      local_23 = local_28._2_1_;
      local_22 = local_28._1_1_;
      local_21 = local_28._0_1_;
    }
    else {
      puVar2 = &local_28;
    }
    iVar1 = TRKAppendBuffer(param_1,puVar2,4);
    param_2 = param_2 + 1;
  }
  return;
}


int TRKAppendBuffer_ui8(int param_1,undefined *param_2,int param_3)

{
  undefined uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = 0;
  for (iVar4 = 0; (iVar2 == 0 && (iVar4 < param_3)); iVar4 = iVar4 + 1) {
    uVar3 = *(uint *)(param_1 + 0xc);
    uVar1 = *param_2;
    if (uVar3 < 0x880) {
      *(uint *)(param_1 + 0xc) = uVar3 + 1;
      iVar2 = 0;
      *(undefined *)(param_1 + uVar3 + 0x10) = uVar1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    else {
      iVar2 = 0x301;
    }
    param_2 = param_2 + 1;
  }
  return iVar2;
}


/* WARNING: Could not reconcile some variable overlaps */

void TRKAppendBuffer1_ui64
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined local_10;
  undefined local_f;
  undefined local_e;
  undefined local_d;
  undefined local_c;
  undefined local_b;
  undefined local_a;
  undefined local_9;
  
  if (gTRKBigEndian == 0) {
    local_14._3_1_ = (undefined)param_4;
    puVar1 = (undefined4 *)&local_10;
    local_14._2_1_ = (undefined)((uint)param_4 >> 8);
    local_14._1_1_ = (undefined)((uint)param_4 >> 0x10);
    local_14._0_1_ = (undefined)((uint)param_4 >> 0x18);
    local_18._3_1_ = (undefined)param_3;
    local_18._2_1_ = (undefined)((uint)param_3 >> 8);
    local_18._1_1_ = (undefined)((uint)param_3 >> 0x10);
    local_18._0_1_ = (undefined)((uint)param_3 >> 0x18);
    local_10 = (undefined)local_14;
    local_f = local_14._2_1_;
    local_e = local_14._1_1_;
    local_d = local_14._0_1_;
    local_c = (undefined)local_18;
    local_b = local_18._2_1_;
    local_a = local_18._1_1_;
    local_9 = local_18._0_1_;
  }
  else {
    puVar1 = &local_18;
  }
  local_18 = param_3;
  local_14 = param_4;
  TRKAppendBuffer(param_1,puVar1,8);
  return;
}


/* WARNING: Could not reconcile some variable overlaps */

void TRKAppendBuffer1_ui32(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 local_8;
  undefined local_4;
  undefined local_3;
  undefined local_2;
  undefined local_1;
  
  if (gTRKBigEndian == 0) {
    local_8._3_1_ = (undefined)param_2;
    puVar1 = (undefined4 *)&local_4;
    local_8._2_1_ = (undefined)((uint)param_2 >> 8);
    local_8._1_1_ = (undefined)((uint)param_2 >> 0x10);
    local_8._0_1_ = (undefined)((uint)param_2 >> 0x18);
    local_4 = (undefined)local_8;
    local_3 = local_8._2_1_;
    local_2 = local_8._1_1_;
    local_1 = local_8._0_1_;
  }
  else {
    puVar1 = &local_8;
  }
  local_8 = param_2;
  TRKAppendBuffer(param_1,puVar1,4);
  return;
}


/* WARNING: Could not reconcile some variable overlaps */

void TRKAppendBuffer1_ui16(undefined4 param_1,undefined2 param_2)

{
  undefined2 *puVar1;
  undefined2 local_8;
  undefined local_4;
  undefined local_3;
  
  if (gTRKBigEndian == 0) {
    local_8._1_1_ = (undefined)param_2;
    puVar1 = (undefined2 *)&local_4;
    local_8._0_1_ = (undefined)((ushort)param_2 >> 8);
    local_4 = (undefined)local_8;
    local_3 = local_8._0_1_;
  }
  else {
    puVar1 = &local_8;
  }
  local_8 = param_2;
  TRKAppendBuffer(param_1,puVar1,2);
  return;
}


undefined4 TRKReadBuffer(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc);
    if (uVar1 < param_3) {
      uVar2 = 0x302;
      param_3 = uVar1;
    }
    FUN_80003510(param_2,param_1 + *(int *)(param_1 + 0xc) + 0x10,param_3);
    *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
  }
  return uVar2;
}


undefined4 TRKAppendBuffer(int param_1,undefined *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc);
    if (0x880U - iVar1 < param_3) {
      uVar2 = 0x301;
      param_3 = 0x880U - iVar1;
    }
    if (param_3 == 1) {
      *(undefined *)(param_1 + iVar1 + 0x10) = *param_2;
    }
    else {
      FUN_80003510(param_1 + iVar1 + 0x10,param_2,param_3);
    }
    *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0xc);
  }
  return uVar2;
}


undefined4 TRKSetBufferPosition(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 < 0x881) {
    *(uint *)(param_1 + 0xc) = param_2;
    if (*(uint *)(param_1 + 8) < param_2) {
      *(uint *)(param_1 + 8) = param_2;
    }
  }
  else {
    uVar1 = 0x301;
  }
  return uVar1;
}


void TRKResetBuffer(int param_1,char param_2)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (param_2 == '\0') {
    FUN_800034e0(param_1 + 0x10,0,0x880);
  }
  return;
}


void TRKReleaseBuffer(int param_1)

{
  if (((param_1 != -1) && (-1 < param_1)) && (param_1 < 3)) {
    TRKAcquireMutex(&gTRKMsgBufs + param_1 * 0x890);
    (&DAT_803f1f34)[param_1 * 0x224] = 0;
    TRKReleaseMutex(&gTRKMsgBufs + param_1 * 0x890);
  }
  return;
}


undefined * TRKGetBuffer(int param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  if ((-1 < param_1) && (param_1 < 3)) {
    puVar1 = &gTRKMsgBufs + param_1 * 0x890;
  }
  return puVar1;
}


int TRKGetFreeBuffer(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = 0x300;
  *param_2 = 0;
  for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
    puVar3 = (undefined *)0x0;
    if ((-1 < iVar1) && (iVar1 < 3)) {
      puVar3 = &gTRKMsgBufs + iVar1 * 0x890;
    }
    TRKAcquireMutex(puVar3);
    if (*(int *)(puVar3 + 4) == 0) {
      *(undefined4 *)(puVar3 + 8) = 0;
      iVar2 = 0;
      *(undefined4 *)(puVar3 + 0xc) = 0;
      *(undefined4 *)(puVar3 + 4) = 1;
      *param_2 = puVar3;
      *param_1 = iVar1;
      iVar1 = 3;
    }
    TRKReleaseMutex(puVar3);
  }
  if (iVar2 == 0x300) {
    usr_puts_serial("ERROR : No buffer available\n");
  }
  return iVar2;
}


undefined4 TRKInitializeMessageBuffers(void)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = &gTRKMsgBufs;
  iVar1 = 0;
  do {
    TRKInitializeMutex(puVar2);
    TRKAcquireMutex(puVar2);
    *(undefined4 *)(puVar2 + 4) = 0;
    TRKReleaseMutex(puVar2);
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 0x890;
  } while (iVar1 < 3);
  return 0;
}

