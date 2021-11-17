#include <ar/ar.h>
#include <os/OSInterrupt.h>
#include <os/OS.h>
#include <ar/ar.h>
#include <os/OSContext.h>
#include <os/OSCache.h>
#include <base/PPCArch.h>


namespace ar {
undefined4 __AR_Callback;
undefined4 __AR_Size;
undefined4 __AR_InternalSize;
undefined4 __AR_ExpansionSize;
undefined4 __AR_StackPointer;
undefined4 __AR_FreeBlocks;
undefined4 __AR_BlockLength;
undefined4 __AR_init_flag;

undefined4 ARRegisterDMACallback(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = __AR_Callback;
  os::OSDisableInterrupts();
  __AR_Callback = param_1;
  os::OSRestoreInterrupts();
  return uVar1;
}


void ARStartDMA(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  os::OSDisableInterrupts();
  DAT_cc005020._0_2_ = DAT_cc005020._0_2_ & 0xfc00 | (ushort)((uint)param_2 >> 0x10);
  DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)param_2;
  DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | (ushort)((uint)param_3 >> 0x10);
  DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f | (ushort)param_3;
  DAT_cc005028._0_2_ =
       (ushort)(param_1 << 0xf) | DAT_cc005028._0_2_ & 0x7c00 | (ushort)((uint)param_4 >> 0x10);
  DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | (ushort)param_4;
  os::OSRestoreInterrupts();
  return;
}


int ARAlloc(int param_1)

{
  int iVar1;
  
  os::OSDisableInterrupts();
  iVar1 = __AR_StackPointer;
  __AR_StackPointer = __AR_StackPointer + param_1;
  *__AR_BlockLength = param_1;
  __AR_BlockLength = __AR_BlockLength + 1;
  __AR_FreeBlocks = __AR_FreeBlocks + -1;
  os::OSRestoreInterrupts();
  return iVar1;
}


undefined4 ARInit(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (__AR_init_flag == 1) {
    uVar1 = 0x4000;
  }
  else {
    os::OSRegisterVersion(__ARVersion);
    uVar1 = os::OSDisableInterrupts();
    __AR_Callback = 0;
    os::__OSSetInterruptHandler(6,__ARHandler);
    os::__OSUnmaskInterrupts(0x2000000);
    __AR_StackPointer = 0x4000;
    __AR_FreeBlocks = param_2;
    __AR_BlockLength = param_1;
    __ARChecksize();
    __AR_init_flag = 1;
    os::OSRestoreInterrupts(uVar1);
    uVar1 = __AR_StackPointer;
  }
  return uVar1;
}


undefined4 ARGetBaseAddress(void)

{
  return 0x4000;
}


undefined4 ARGetSize(void)

{
  return __AR_Size;
}


void __ARHandler(undefined4 param_1,undefined4 param_2)

{
  undefined auStack720 [716];
  
  DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
  os::OSClearContext(auStack720);
  os::OSSetCurrentContext(auStack720);
  if (__AR_Callback != (code *)0x0) {
    (*__AR_Callback)();
  }
  os::OSClearContext(auStack720);
  os::OSSetCurrentContext(param_2);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __ARChecksize(void)

{
  undefined *puVar1;
  undefined auStack672 [64];
  undefined auStack608 [64];
  undefined auStack544 [64];
  undefined auStack480 [64];
  undefined auStack416 [64];
  int aiStack352 [16];
  undefined4 uStack288;
  undefined4 uStack284;
  undefined4 uStack280;
  undefined4 uStack276;
  undefined4 uStack272;
  undefined4 uStack268;
  undefined4 uStack264;
  undefined4 uStack260;
  int iStack224;
  undefined4 uStack220;
  undefined4 uStack216;
  undefined4 uStack212;
  undefined4 uStack208;
  undefined4 uStack204;
  undefined4 uStack200;
  undefined4 uStack196;
  undefined *local_ac;
  undefined *local_a8;
  undefined *local_a4;
  uint local_a0;
  uint local_9c;
  undefined4 local_98;
  uint local_94;
  undefined4 local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  ushort *local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  undefined4 local_5c;
  uint local_58;
  undefined4 local_54;
  ushort local_50;
  
  do {
  } while ((DAT_cc005016 & 1) == 0);
  __AR_InternalSize = 0x1000000;
  local_a4 = auStack544;
  DAT_cc005012 = DAT_cc005012 & 0xffc0 | 0x23;
  iStack224 = -0x21524111;
  uStack288 = 0xbad0bad0;
  uStack220 = 0xdeadbeef;
  local_ac = auStack672;
  local_a8 = auStack608;
  uStack284 = 0xbad0bad0;
  uStack216 = 0xdeadbeef;
  puVar1 = (undefined *)0x1000000;
  uStack280 = 0xbad0bad0;
  uStack212 = 0xdeadbeef;
  uStack276 = 0xbad0bad0;
  uStack208 = 0xdeadbeef;
  uStack272 = 0xbad0bad0;
  uStack204 = 0xdeadbeef;
  uStack268 = 0xbad0bad0;
  uStack200 = 0xdeadbeef;
  uStack264 = 0xbad0bad0;
  uStack196 = 0xdeadbeef;
  local_78 = &DAT_cc005012;
  local_50 = 3;
  uStack260 = 0xbad0bad0;
  os::DCFlushRange(&iStack224,0x20);
  os::DCFlushRange(&uStack288,0x20);
  __AR_ExpansionSize = 0;
  os::DCInvalidateRange(auStack416,0x20);
  local_84 = (uint)auStack416 >> 0x10;
  DAT_cc005020._0_2_ = DAT_cc005020._0_2_ & 0xfc00 | (ushort)((uint)auStack416 >> 0x10);
  local_74 = (uint)auStack416 & 0xffff;
  DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_74;
  DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | 0x100;
  DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f;
  DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0xfc00 | 0x8000;
  DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
  do {
  } while ((DAT_cc00500a & 0x200) != 0);
  DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
  base::PPCSync();
  local_7c = (uint)&iStack224 >> 0x10;
  DAT_cc005020._0_2_ = DAT_cc005020._0_2_ & 0xfc00 | (ushort)((uint)&iStack224 >> 0x10);
  local_70 = (uint)&iStack224 & 0xffff;
  DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_70;
  DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | 0x100;
  DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f;
  DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0x7c00;
  DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
  do {
  } while ((DAT_cc00500a & 0x200) != 0);
  DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
  FUN_800033a8((int)aiStack352,0,0x20);
  os::DCFlushRange(aiStack352,0x20);
  local_80 = (uint)aiStack352 >> 0x10;
  DAT_cc005020._0_2_ = DAT_cc005020._0_2_ & 0xfc00 | (ushort)((uint)aiStack352 >> 0x10);
  local_6c = (uint)aiStack352 & 0xffff;
  DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_6c;
  DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | 0x100;
  DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f;
  DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0xfc00 | 0x8000;
  DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
  do {
  } while ((DAT_cc00500a & 0x200) != 0);
  DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
  base::PPCSync();
  if (aiStack352[0] == iStack224) {
    os::DCInvalidateRange(auStack480,0x20);
    local_8c = (uint)auStack480 >> 0x10;
    DAT_cc005020._0_2_ = DAT_cc005020._0_2_ & 0xfc00 | (ushort)((uint)auStack480 >> 0x10);
    local_68 = (uint)auStack480 & 0xffff;
    DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_68;
    DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | 0x120;
    DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f;
    DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0xfc00 | 0x8000;
    DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
    do {
    } while ((DAT_cc00500a & 0x200) != 0);
    DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
    base::PPCSync();
    os::DCInvalidateRange(local_a4,0x20);
    local_94 = (uint)local_a4 >> 0x10;
    DAT_cc005020._0_2_ = DAT_cc005020._0_2_ & 0xfc00 | (ushort)((uint)local_a4 >> 0x10);
    local_64 = (uint)local_a4 & 0xffff;
    DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_64;
    DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | 0x200;
    DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f;
    DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0xfc00 | 0x8000;
    DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
    do {
    } while ((DAT_cc00500a & 0x200) != 0);
    DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
    base::PPCSync();
    os::DCInvalidateRange(local_a8,0x20);
    local_9c = (uint)local_a8 >> 0x10;
    DAT_cc005020._0_2_ = DAT_cc005020._0_2_ & 0xfc00 | (ushort)((uint)local_a8 >> 0x10);
    local_90 = 0x100;
    local_5c = 0x200;
    local_60 = (uint)local_a8 & 0xffff;
    DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_60;
    DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | 0x100;
    DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f | 0x200;
    DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0xfc00 | 0x8000;
    DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
    do {
    } while ((DAT_cc00500a & 0x200) != 0);
    DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
    base::PPCSync();
    os::DCInvalidateRange(local_ac,0x20);
    local_a0 = (uint)local_ac >> 0x10;
    DAT_cc005020._0_2_ = DAT_cc005020._0_2_ & 0xfc00 | (ushort)((uint)local_ac >> 0x10);
    local_98 = 0x140;
    local_54 = 0;
    local_58 = (uint)local_ac & 0xffff;
    DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_58;
    DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | 0x140;
    DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f;
    DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0xfc00 | 0x8000;
    DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
    do {
    } while ((DAT_cc00500a & 0x200) != 0);
    DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
    base::PPCSync();
    local_88 = (uint)&uStack288 >> 0x10;
    DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f;
    DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0x7c00;
    do {
    } while ((DAT_cc00500a & 0x200) != 0);
    DAT_cc005020._0_2_ =
         DAT_cc005020._0_2_ & 0xfc00 | (ushort)((uint)&uStack288 >> 0x10) & 0xfc00 |
         (ushort)local_7c;
    DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_70;
    DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | 0x100;
    DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
    do {
    } while ((DAT_cc00500a & 0x200) != 0);
    DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
    FUN_800033a8((int)aiStack352,0,0x20);
    os::DCFlushRange(aiStack352,0x20);
    DAT_cc005020._0_2_ = DAT_cc005020._0_2_ & 0xfc00 | (ushort)local_80;
    DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_6c;
    DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | 0x120;
    DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f;
    DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0xfc00 | 0x8000;
    DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
    do {
    } while ((DAT_cc00500a & 0x200) != 0);
    DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
    base::PPCSync();
    if (aiStack352[0] == iStack224) {
      DAT_cc005020._0_2_ = DAT_cc005020._0_2_ & 0xfc00 | (ushort)local_84;
      DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_74;
      DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | 0x100;
      DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f;
      DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0x7c00;
      DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
      do {
      } while ((DAT_cc00500a & 0x200) != 0);
      DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
      puVar1 = &DAT_01200000;
      __AR_ExpansionSize = 0x200000;
    }
    else {
      DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f;
      DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0x7c00;
      do {
      } while ((DAT_cc00500a & 0x200) != 0);
      DAT_cc005020._0_2_ =
           DAT_cc005020._0_2_ & 0xfc00 | (ushort)local_88 & 0xfc00 | (ushort)local_7c;
      DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_70;
      DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | 0x100;
      DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
      do {
      } while ((DAT_cc00500a & 0x200) != 0);
      DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
      FUN_800033a8((int)aiStack352,0,0x20);
      os::DCFlushRange(aiStack352,0x20);
      DAT_cc005020._0_2_ = DAT_cc005020._0_2_ & 0xfc00 | (ushort)local_80;
      DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_6c;
      DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | 0x200;
      DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f;
      DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0xfc00 | 0x8000;
      DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
      do {
      } while ((DAT_cc00500a & 0x200) != 0);
      DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
      base::PPCSync();
      if (aiStack352[0] == iStack224) {
        DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f;
        DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0x7c00;
        do {
        } while ((DAT_cc00500a & 0x200) != 0);
        DAT_cc005020._0_2_ =
             DAT_cc005020._0_2_ & 0xfc00 | (ushort)local_84 & 0xfc00 | (ushort)local_8c;
        DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_74 & 0x1f | (ushort)local_68;
        DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | 0x120;
        DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
        do {
        } while ((DAT_cc00500a & 0x200) != 0);
        DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
        puVar1 = (undefined *)0x1400000;
        __AR_ExpansionSize = 0x400000;
        local_50 = local_50 | 8;
      }
      else {
        DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0x7c00;
        do {
        } while ((DAT_cc00500a & 0x200) != 0);
        DAT_cc005020._0_2_ =
             DAT_cc005020._0_2_ & 0xfc00 | (ushort)local_88 & 0xfc00 | (ushort)local_7c;
        DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_70;
        DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | (ushort)local_90 & 0xfc00 | 0x100;
        DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f | (ushort)local_5c & 0x1f;
        DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
        do {
        } while ((DAT_cc00500a & 0x200) != 0);
        DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
        FUN_800033a8((int)aiStack352,0,0x20);
        os::DCFlushRange(aiStack352,0x20);
        DAT_cc005020._0_2_ = DAT_cc005020._0_2_ & 0xfc00 | (ushort)local_80;
        DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_6c;
        DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | (ushort)local_90;
        DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f | (ushort)local_5c;
        DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0xfc00 | 0x8000;
        DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
        do {
        } while ((DAT_cc00500a & 0x200) != 0);
        DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
        base::PPCSync();
        if (aiStack352[0] == iStack224) {
          DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f;
          DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0x7c00;
          do {
          } while ((DAT_cc00500a & 0x200) != 0);
          do {
          } while ((DAT_cc00500a & 0x200) != 0);
          DAT_cc005020._0_2_ =
               DAT_cc005020._0_2_ & 0xfc00 | (ushort)local_84 & 0xfc00 | (ushort)local_8c & 0xfc00 |
               (ushort)local_94;
          DAT_cc005020._2_2_ =
               DAT_cc005020._2_2_ & 0x1f | (ushort)local_74 & 0x1f | (ushort)local_68 & 0x1f |
               (ushort)local_64;
          DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | 0x200;
          DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
          do {
          } while ((DAT_cc00500a & 0x200) != 0);
          DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
          puVar1 = (undefined *)0x1800000;
          __AR_ExpansionSize = 0x800000;
          local_50 = local_50 | 0x10;
        }
        else {
          DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0x7c00;
          do {
          } while ((DAT_cc00500a & 0x200) != 0);
          DAT_cc005020._0_2_ =
               DAT_cc005020._0_2_ & 0xfc00 | (ushort)local_88 & 0xfc00 | (ushort)local_7c;
          DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_70;
          DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | (ushort)local_98 & 0xfc00 | 0x100;
          DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f | (ushort)local_54 & 0x1f;
          DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
          do {
          } while ((DAT_cc00500a & 0x200) != 0);
          DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
          FUN_800033a8((int)aiStack352,0,0x20);
          os::DCFlushRange(aiStack352,0x20);
          DAT_cc005020._0_2_ = DAT_cc005020._0_2_ & 0xfc00 | (ushort)local_80;
          DAT_cc005020._2_2_ = DAT_cc005020._2_2_ & 0x1f | (ushort)local_6c;
          DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | (ushort)local_98;
          DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f | (ushort)local_54;
          DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0xfc00 | 0x8000;
          DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
          do {
          } while ((DAT_cc00500a & 0x200) != 0);
          DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
          base::PPCSync();
          if (aiStack352[0] == iStack224) {
            DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0x7c00;
            do {
            } while ((DAT_cc00500a & 0x200) != 0);
            do {
            } while ((DAT_cc00500a & 0x200) != 0);
            do {
            } while ((DAT_cc00500a & 0x200) != 0);
            DAT_cc005020._0_2_ =
                 DAT_cc005020._0_2_ & 0xfc00 | (ushort)local_84 & 0xfc00 | (ushort)local_8c & 0xfc00
                 | (ushort)local_94 & 0xfc00 | (ushort)local_9c;
            DAT_cc005020._2_2_ =
                 DAT_cc005020._2_2_ & 0x1f | (ushort)local_74 & 0x1f | (ushort)local_68 & 0x1f |
                 (ushort)local_64 & 0x1f | (ushort)local_60;
            DAT_cc005024._0_2_ = DAT_cc005024._0_2_ & 0xfc00 | (ushort)local_90;
            DAT_cc005024._2_2_ = DAT_cc005024._2_2_ & 0x1f | (ushort)local_5c;
            DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
            do {
            } while ((DAT_cc00500a & 0x200) != 0);
            DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
            puVar1 = (undefined *)0x2000000;
            __AR_ExpansionSize = 0x1000000;
            local_50 = local_50 | 0x18;
          }
          else {
            DAT_cc005028._0_2_ = DAT_cc005028._0_2_ & 0x7c00;
            do {
            } while ((DAT_cc00500a & 0x200) != 0);
            do {
            } while ((DAT_cc00500a & 0x200) != 0);
            do {
            } while ((DAT_cc00500a & 0x200) != 0);
            do {
            } while ((DAT_cc00500a & 0x200) != 0);
            DAT_cc005020._0_2_ =
                 DAT_cc005020._0_2_ & 0xfc00 | (ushort)local_84 & 0xfc00 | (ushort)local_8c & 0xfc00
                 | (ushort)local_94 & 0xfc00 | (ushort)local_9c & 0xfc00 | (ushort)local_a0;
            DAT_cc005020._2_2_ =
                 DAT_cc005020._2_2_ & 0x1f | (ushort)local_74 & 0x1f | (ushort)local_68 & 0x1f |
                 (ushort)local_64 & 0x1f | (ushort)local_60 & 0x1f | (ushort)local_58;
            DAT_cc005024._0_2_ =
                 DAT_cc005024._0_2_ & 0xfc00 | (ushort)local_90 & 0xfc00 | (ushort)local_98;
            DAT_cc005024._2_2_ =
                 DAT_cc005024._2_2_ & 0x1f | (ushort)local_5c & 0x1f | (ushort)local_54;
            DAT_cc005028._2_2_ = DAT_cc005028._2_2_ & 0x1f | 0x20;
            do {
            } while ((DAT_cc00500a & 0x200) != 0);
            DAT_cc00500a = DAT_cc00500a & 0xff77 | 0x20;
            puVar1 = (undefined *)0x3000000;
            __AR_ExpansionSize = 0x2000000;
            local_50 = local_50 | 0x20;
          }
        }
      }
    }
    *local_78 = *local_78 & 0xffc0 | local_50;
  }
  __AR_Size = puVar1;
  _DAT_c00000d0 = puVar1;
  return;
}

