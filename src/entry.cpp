#include <entry.h>
#include <os/OSReset.h>
#include <TRK_MINNOW_DOLPHIN/dolphin_trk.h>
#include <db/db.h>
#include <os/OS.h>
#include <os/__ppc_eabi_init.h>
#include <m_Do_main.h>
#include <MSL_C.PPCEABI.bare.H/abort_exit.h>
#include <os/OSCache.h>
#include <TRK_MINNOW_DOLPHIN/mem_TRK.h>
#include <TRK_MINNOW_DOLPHIN/flush_cache.h>


void FUN_80003100(void)

{
  if ((DAT_800030e4 & 0xeef) == 0xeef) {
    os::OSResetSystem(0,0,0);
  }
  return;
}


void FUN_80003140(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined8 uVar7;
  
  FUN_80003278();
  FUN_80003354();
  uVar7 = FUN_80003294();
  DAT_80000044 = 0;
  if (DAT_800000f4 == 0) {
    iVar1 = DAT_800030e8;
    if (DAT_80000034 != 0) goto LAB_800031a8;
  }
  else {
    iVar1 = *(int *)(DAT_800000f4 + 0xc);
LAB_800031a8:
    uVar2 = 0;
    if (iVar1 != 2) {
      if (iVar1 != 3) goto LAB_800031d0;
      uVar2 = 1;
    }
    TRK_MINNOW_DOLPHIN::InitMetroTRK((int)((ulonglong)uVar7 >> 0x20),(int)uVar7,uVar2);
  }
LAB_800031d0:
  iVar1 = DAT_800000f4;
  if ((DAT_800000f4 != 0) && (*(int *)(DAT_800000f4 + 8) != 0)) {
    piVar3 = (int *)(DAT_800000f4 + *(int *)(DAT_800000f4 + 8));
    iVar4 = *piVar3;
    if (iVar4 != 0) {
      piVar5 = piVar3 + 1;
      iVar6 = iVar4;
      do {
        piVar3 = piVar3 + 1;
        *piVar3 = *piVar3 + iVar1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      DAT_80000034 = (uint)piVar5 & 0xffffffe0;
      goto LAB_80003238;
    }
  }
  iVar4 = 0;
  piVar5 = (int *)0x0;
LAB_80003238:
  db::DBInit();
  os::OSInit();
  if (((DAT_800030e6 & 0x8000) == 0) || ((DAT_800030e6 & 0x7fff) == 1)) {
    FUN_80003100();
  }
  os::__init_user();
  iVar1 = m_Do_main::main(iVar4,piVar5);
  MSL_C.PPCEABI.bare.H::exit(iVar1);
  return;
}


void FUN_80003278(void)

{
  return;
}


void FUN_80003294(void)

{
  undefined **ppuVar1;
  undefined *puVar2;
  byte *length;
  byte *dst;
  
  ppuVar1 = &PTR_FUN_8000556c;
  while( true ) {
    length = ppuVar1[2];
    if (length == (byte *)0x0) break;
    dst = ppuVar1[1];
    if ((length != (byte *)0x0) && (dst != *ppuVar1)) {
      copy_bytes(dst,*ppuVar1,(int)length);
      FUN_80003374(dst,length);
    }
    ppuVar1 = ppuVar1 + 3;
  }
  ppuVar1 = &PTR_mainThread_800055f0;
  while( true ) {
    puVar2 = ppuVar1[1];
    if (puVar2 == (undefined *)0x0) break;
    if (puVar2 != (undefined *)0x0) {
      FUN_800033a8((int)*ppuVar1,0,(uint)puVar2);
    }
    ppuVar1 = ppuVar1 + 2;
  }
  return;
}


void FUN_80003354(void)

{
  os::__OSPSInit();
  os::__OSCacheInit();
  return;
}


void FUN_80003374(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xfffffff1;
  param_2 = param_2 + (param_1 - uVar1);
  do {
    dataCacheBlockStore(uVar1);
    sync(0);
    instructionCacheBlockInvalidate(uVar1);
    uVar1 = uVar1 + 8;
    param_2 = param_2 + -8;
  } while (-1 < param_2);
  instructionSynchronize();
  return;
}


int FUN_800033a8(int param_1,uint param_2,uint param_3)

{
  FUN_800033d8(param_1,param_2,param_3);
  return param_1;
}


void FUN_800033d8(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  undefined *puVar3;
  uint uVar4;
  
  uVar4 = param_2 & 0xff;
  puVar3 = (undefined *)(param_1 - 1);
  if (0x1f < param_3) {
    uVar1 = ~(uint)puVar3 & 3;
    if (uVar1 != 0) {
      param_3 = param_3 - uVar1;
      do {
        uVar1 = uVar1 - 1;
        puVar3 = puVar3 + 1;
        *puVar3 = (char)uVar4;
      } while (uVar1 != 0);
    }
    if (uVar4 != 0) {
      uVar4 = uVar4 | uVar4 << 8 | uVar4 << 0x18 | uVar4 << 0x10;
    }
    puVar2 = (uint *)(puVar3 + -3);
    for (uVar1 = param_3 >> 5; uVar1 != 0; uVar1 = uVar1 - 1) {
      puVar2[1] = uVar4;
      puVar2[2] = uVar4;
      puVar2[3] = uVar4;
      puVar2[4] = uVar4;
      puVar2[5] = uVar4;
      puVar2[6] = uVar4;
      puVar2[7] = uVar4;
      puVar2 = puVar2 + 8;
      *puVar2 = uVar4;
    }
    for (uVar1 = param_3 >> 2 & 7; uVar1 != 0; uVar1 = uVar1 - 1) {
      puVar2 = puVar2 + 1;
      *puVar2 = uVar4;
    }
    puVar3 = (undefined *)((int)puVar2 + 3);
    param_3 = param_3 & 3;
  }
  if (param_3 != 0) {
    do {
      param_3 = param_3 - 1;
      puVar3 = puVar3 + 1;
      *puVar3 = (char)uVar4;
    } while (param_3 != 0);
    return;
  }
  return;
}


void copy_bytes(byte *dst,byte *src,int length)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  
  if (dst <= src) {
    pbVar1 = src + -1;
    pbVar3 = dst + -1;
    iVar2 = length + 1;
    while( true ) {
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) break;
      pbVar1 = pbVar1 + 1;
      pbVar3 = pbVar3 + 1;
      *pbVar3 = *pbVar1;
    }
    return;
  }
  pbVar1 = src + length;
  pbVar3 = dst + length;
  iVar2 = length + 1;
  while( true ) {
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) break;
    pbVar1 = pbVar1 + -1;
    pbVar3 = pbVar3 + -1;
    *pbVar3 = *pbVar1;
  }
  return;
}


undefined4 FUN_800034e0(undefined4 param_1)

{
  TRK_MINNOW_DOLPHIN::TRK_fill_mem();
  return param_1;
}


void FUN_80003510(int param_1,int param_2,int param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = (undefined *)(param_2 + -1);
  puVar2 = (undefined *)(param_1 + -1);
  param_3 = param_3 + 1;
  while( true ) {
    param_3 = param_3 + -1;
    if (param_3 == 0) break;
    puVar1 = puVar1 + 1;
    puVar2 = puVar2 + 1;
    *puVar2 = *puVar1;
  }
  return;
}


void FUN_80005468(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  if (((TRK_MINNOW_DOLPHIN::lc_base < 0x45) && (0x44 < TRK_MINNOW_DOLPHIN::lc_base + 0x4000)) &&
     ((DAT_803f3be8 & 3) != 0)) {
    puVar1 = (uint *)&DAT_00000044;
  }
  else {
    puVar1 = &DAT_80000044;
  }
  uVar5 = *puVar1;
  puVar1 = &TRK_MINNOW_DOLPHIN::TRK_ISR_OFFSETS;
  iVar4 = 0;
  do {
    if ((uVar5 & 1 << iVar4) != 0) {
      uVar2 = *puVar1;
      if (((uVar2 < TRK_MINNOW_DOLPHIN::lc_base) || (TRK_MINNOW_DOLPHIN::lc_base + 0x4000 <= uVar2))
         || (uVar3 = uVar2, (DAT_803f3be8 & 3) == 0)) {
        uVar3 = uVar2 & 0x3fffffff | 0x80000000;
      }
      FUN_80003510(uVar3,uVar2 + 0x80003534,0x100);
      TRK_MINNOW_DOLPHIN::TRK_flush_cache(uVar3,0x100);
    }
    iVar4 = iVar4 + 1;
    puVar1 = puVar1 + 1;
  } while (iVar4 < 0xf);
  return;
}

