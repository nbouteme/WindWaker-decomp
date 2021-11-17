#include <os/OS.h>
#include <os/OSReset.h>
#include <os/OSArena.h>
#include <os/OSTime.h>
#include <os/OSInterrupt.h>
#include <base/PPCArch.h>
#include <os/OS.h>
#include <os/OSSync.h>
#include <os/OSAlarm.h>
#include <os/OSLink.h>
#include <os/OSResetSW.h>
#include <os/OSContext.h>
#include <os/OSCache.h>
#include <exi/EXIBios.h>
#include <si/SIBios.h>
#include <os/OSRtc.h>
#include <os/OSThread.h>
#include <os/OSAudioSystem.h>
#include <os/OSMemory.h>
#include <m_Do_printf.h>
#include <TRK_MINNOW_DOLPHIN/dolphin_trk.h>
#include <dvd/dvd.h>
#include <db/db.h>
#include <os/OSError.h>


namespace os {
undefined DriveInfo;
undefined DriveBlock;
undefined4 BootInfo;
undefined4 BI2DebugFlag;
undefined4 BI2DebugFlagHolder;
undefined4 __OSIsGcam;
undefined4 AreWeInitialized;
undefined4 OSExceptionTable;
undefined4 __OSSavedRegionEnd;
undefined4 __OSSavedRegionStart;
undefined4 __OSInIPL;
undefined4 __OSStartTime;

int OSGetConsoleType(void)

{
  int iVar1;
  
  if ((BootInfo == 0) || (iVar1 = *(int *)(BootInfo + 0x2c), iVar1 == 0)) {
    iVar1 = 0x10000002;
  }
  return iVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ClearArena(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = OSGetResetCode();
  if (iVar1 == -0x80000000) {
    __OSSavedRegionStart = _DAT_812fdff0;
    __OSSavedRegionEnd = _DAT_812fdfec;
    if (_DAT_812fdff0 == 0) {
      iVar1 = OSGetArenaHi();
      iVar2 = OSGetArenaLo();
      iVar3 = OSGetArenaLo();
      FUN_800033a8(iVar3,0,iVar1 - iVar2);
    }
    else {
      uVar4 = OSGetArenaLo();
      if (uVar4 < __OSSavedRegionStart) {
        uVar4 = OSGetArenaHi();
        if (__OSSavedRegionStart < uVar4) {
          iVar1 = OSGetArenaLo();
          uVar4 = __OSSavedRegionStart - iVar1;
          iVar1 = OSGetArenaLo();
          FUN_800033a8(iVar1,0,uVar4);
          uVar5 = OSGetArenaHi();
          uVar4 = __OSSavedRegionEnd;
          if (__OSSavedRegionEnd < uVar5) {
            iVar1 = OSGetArenaHi();
            FUN_800033a8(uVar4,0,iVar1 - uVar4);
          }
        }
        else {
          iVar1 = OSGetArenaHi();
          iVar2 = OSGetArenaLo();
          iVar3 = OSGetArenaLo();
          FUN_800033a8(iVar3,0,iVar1 - iVar2);
        }
      }
    }
  }
  else {
    __OSSavedRegionStart = 0;
    __OSSavedRegionEnd = 0;
    iVar1 = OSGetArenaHi();
    iVar2 = OSGetArenaLo();
    iVar3 = OSGetArenaLo();
    FUN_800033a8(iVar3,0,iVar1 - iVar2);
  }
  return;
}


void InquiryCallback(undefined4 param_1,int param_2)

{
  if (*(int *)(param_2 + 0xc) == 0) {
    DAT_800030e6 = DAT_803f01a2 | 0x8000;
  }
  else {
    DAT_800030e6 = 1;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void OSInit(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (AreWeInitialized != 0) goto LAB_80301a98;
  AreWeInitialized = 1;
  ___OSStartTime = __OSGetSystemTime();
  OSDisableInterrupts();
  base::PPCDisableSpeculation();
  base::PPCSetFpNonIEEEMode();
  BI2DebugFlag = (uint *)0x0;
  BootInfo = -0x80000000;
  if (DAT_800000f4 == 0) {
    if (DAT_80000034 != 0) {
      BI2DebugFlagHolder = (uint)DAT_800030e8._0_1_;
      BI2DebugFlag = &BI2DebugFlagHolder;
      pad::__PADSpec = (uint)DAT_800030e8._1_1_;
    }
  }
  else {
    BI2DebugFlag = (uint *)(DAT_800000f4 + 0xc);
    pad::__PADSpec = *(uint *)(DAT_800000f4 + 0x24);
    DAT_800030e8._0_1_ = (byte)*BI2DebugFlag;
    DAT_800030e8._1_1_ = (byte)pad::__PADSpec;
  }
  dvd::__DVDLongFileNameFlag = 1;
  iVar2 = _DAT_80000030;
  if (_DAT_80000030 == 0) {
    iVar2 = -0x7fbf1040;
  }
  OSSetArenaLo(iVar2);
  if (((*(int *)(BootInfo + 0x30) == 0) && (BI2DebugFlag != (uint *)0x0)) && (*BI2DebugFlag < 2)) {
    OSSetArenaLo(0x8040cfc0);
  }
  iVar2 = *(int *)(BootInfo + 0x34);
  if (iVar2 == 0) {
    iVar2 = -0x7e900000;
  }
  OSSetArenaHi(iVar2);
  OSExceptionInit();
  __OSInitSystemCall();
  OSInitAlarm();
  __OSModuleInit();
  __OSInterruptInit();
  __OSSetInterruptHandler(0x16,__OSResetSWInterruptHandler);
  __OSContextInit();
  __OSCacheInit();
  exi::EXIInit();
  si::SIInit();
  __OSInitSram();
  __OSThreadInit();
  __OSInitAudioSystem();
  uVar3 = base::PPCMfhid2();
  base::PPCMthid2(uVar3 & 0xbfffffff);
  if (__OSInIPL == 0) {
    __OSInitMemoryProtection();
  }
  m_Do_printf::OSReport(_83);
  m_Do_printf::OSReport(_84,_85,_86);
  m_Do_printf::OSReport(_87);
  if ((BootInfo == 0) || (uVar3 = *(uint *)(BootInfo + 0x2c), uVar3 == 0)) {
    uVar3 = 0x10000002;
  }
  if ((uVar3 & 0xffff0000) == 0) {
    m_Do_printf::OSReport(_88);
  }
  else {
    uVar1 = uVar3 & 0xffff;
    if (uVar1 == 0x10000002) {
      m_Do_printf::OSReport(_91);
    }
    else {
      if (uVar1 < 0x10000002) {
        if (uVar1 == 0x10000000) {
          m_Do_printf::OSReport(_89);
        }
        else {
          if (uVar1 < 0x10000000) goto LAB_803019cc;
          m_Do_printf::OSReport(_90);
        }
      }
      else {
        if (uVar1 < 0x10000004) {
          m_Do_printf::OSReport(_92);
        }
        else {
LAB_803019cc:
          m_Do_printf::OSReport(_93,(uVar3 & 0xffff) - 3,uVar3);
        }
      }
    }
  }
  m_Do_printf::OSReport(_94,*(uint *)(BootInfo + 0x28) >> 0x14);
  uVar4 = OSGetArenaHi();
  uVar5 = OSGetArenaLo();
  m_Do_printf::OSReport(_95,uVar5,uVar4);
  OSRegisterVersion(__OSVersion);
  if ((BI2DebugFlag != (uint *)0x0) && (1 < *BI2DebugFlag)) {
    TRK_MINNOW_DOLPHIN::EnableMetroTRKInterrupts();
  }
  ClearArena();
  OSEnableInterrupts();
  if (__OSInIPL == 0) {
    dvd::DVDInit();
    if (__OSIsGcam == 0) {
      DCInvalidateRange(&DriveInfo,0x20);
      dvd::DVDInquiryAsync(&DriveBlock,&DriveInfo,InquiryCallback);
    }
    else {
      DAT_800030e6 = 0x9000;
    }
  }
LAB_80301a98:
  __OSStartTime = (undefined4)((ulonglong)___OSStartTime >> 0x20);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80301c24) */
/* WARNING: Removing unreachable block (ram,0x80301c28) */
/* WARNING: Removing unreachable block (ram,0x80301c6c) */

void OSExceptionInit(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  byte *dst;
  uint uVar4;
  int *piVar5;
  
  uVar1 = uRam80301df4;
  if (DAT_80000060 == 0) {
    db::DBPrintf(_129);
    copy_bytes((byte *)&DAT_80000060,(byte *)__OSDBIntegrator,0x24);
    DCFlushRangeNoSync(&DAT_80000060,0x24);
    sync(0);
    ICInvalidateRange(&DAT_80000060,0x24);
  }
  piVar5 = &__OSExceptionLocations;
  for (uVar4 = 0; (uVar4 & 0xff) < 0xf; uVar4 = uVar4 + 1) {
    if (((BI2DebugFlag == (uint *)0x0) || (*BI2DebugFlag < 2)) ||
       (iVar2 = db::__DBIsExceptionMarked(uVar4), iVar2 == 0)) {
      uRam80301df4 = uVar1 | uVar4 & 0xff;
      iVar2 = db::__DBIsExceptionMarked(uVar4);
      if (iVar2 == 0) {
        puVar3 = (undefined4 *)0x80301de4;
        iVar2 = 1;
        do {
          *puVar3 = 0x60000000;
          puVar3 = puVar3 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      else {
        db::DBPrintf(_131,uVar4 & 0xff);
        copy_bytes((byte *)0x80301de4,(byte *)__OSDBJump,4);
      }
      dst = (byte *)(*piVar5 + -0x80000000);
      copy_bytes(dst,(byte *)0x80301d8c,0x98);
      DCFlushRangeNoSync(dst,0x98);
      sync(0);
      ICInvalidateRange(dst,0x98);
    }
    else {
      db::DBPrintf(_130,uVar4 & 0xff);
    }
    piVar5 = piVar5 + 1;
  }
  OSExceptionTable = &DAT_80003000;
  for (uVar4 = 0; (uVar4 & 0xff) < 0xf; uVar4 = uVar4 + 1) {
    __OSSetExceptionHandler(uVar4,OSDefaultExceptionHandler);
  }
  uRam80301df4 = uVar1;
  db::DBPrintf(_132);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __OSDBIntegrator(void)

{
  undefined4 in_LR;
  
  _DAT_0000004c = in_LR;
  return 0x30;
}


undefined4 __OSDBJump(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  uVar3 = func_0x00000060();
  puVar2 = (undefined4 *)(OSExceptionTable + ((uint)((ulonglong)uVar3 >> 0x20) & 0xff) * 4);
  uVar1 = *puVar2;
  *puVar2 = (int)uVar3;
  return uVar1;
}


undefined4 __OSSetExceptionHandler(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(OSExceptionTable + (param_1 & 0xff) * 4);
  uVar1 = *puVar2;
  *puVar2 = param_2;
  return uVar1;
}


undefined4 __OSGetExceptionHandler(uint param_1)

{
  return *(undefined4 *)(OSExceptionTable + (param_1 & 0xff) * 4);
}


void OSExceptionVector(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint in_MSR;
  byte in_cr0;
  byte in_cr1;
  byte in_cr2;
  byte in_cr3;
  byte unaff_cr4;
  byte in_cr5;
  byte in_cr6;
  byte in_cr7;
  undefined4 in_XER;
  undefined4 in_LR;
  undefined4 in_CTR;
  undefined4 in_SRR0;
  uint in_SRR1;
  
  iVar1 = iRam000000c0;
  *(undefined4 *)(iRam000000c0 + 0xc) = param_1;
  *(undefined4 *)(iVar1 + 0x10) = param_2;
  *(undefined4 *)(iVar1 + 0x14) = param_3;
  *(ushort *)(iVar1 + 0x1a2) = *(ushort *)(iVar1 + 0x1a2) | 2;
  *(uint *)(iVar1 + 0x80) =
       (uint)(in_cr0 & 0xf) << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 | (uint)(in_cr2 & 0xf) << 0x14 |
       (uint)(in_cr3 & 0xf) << 0x10 | (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
       (uint)(in_cr6 & 0xf) << 4 | (uint)(in_cr7 & 0xf);
  *(undefined4 *)(iVar1 + 0x84) = in_LR;
  *(undefined4 *)(iVar1 + 0x88) = in_CTR;
  *(undefined4 *)(iVar1 + 0x8c) = in_XER;
  *(undefined4 *)(iVar1 + 0x198) = in_SRR0;
  *(uint *)(iVar1 + 0x19c) = in_SRR1;
  if ((in_SRR1 & 2) == 0) {
    returnFromInterrupt(in_MSR,in_MSR | 0x30);
    return;
  }
  returnFromInterrupt(in_MSR,in_MSR | 0x30);
  return;
}


void OSDefaultExceptionHandler
               (undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 in_r0;
  undefined4 in_r11;
  undefined4 in_r12;
  undefined4 unaff_r14;
  undefined4 unaff_r15;
  undefined4 unaff_r16;
  undefined4 unaff_r17;
  undefined4 unaff_r18;
  undefined4 unaff_r19;
  undefined4 unaff_r20;
  undefined4 unaff_r21;
  undefined4 unaff_r22;
  undefined4 unaff_r23;
  undefined4 unaff_r24;
  undefined4 unaff_r25;
  undefined4 unaff_r26;
  undefined4 unaff_r27;
  undefined4 unaff_r28;
  undefined4 unaff_r29;
  undefined4 unaff_r30;
  undefined4 unaff_r31;
  undefined4 in_GQR1;
  undefined4 in_GQR7;
  
  *param_2 = in_r0;
  param_2[1] = register0x00000004;
  param_2[2] = 0x803ffd00;
  param_2[6] = param_4;
  param_2[7] = param_5;
  param_2[8] = param_6;
  param_2[9] = param_7;
  param_2[10] = param_8;
  param_2[0xb] = in_r11;
  param_2[0xc] = in_r12;
  param_2[0xd] = 0x803fe0e0;
  param_2[0xe] = unaff_r14;
  param_2[0xf] = unaff_r15;
  param_2[0x10] = unaff_r16;
  param_2[0x11] = unaff_r17;
  param_2[0x12] = unaff_r18;
  param_2[0x13] = unaff_r19;
  param_2[0x14] = unaff_r20;
  param_2[0x15] = unaff_r21;
  param_2[0x16] = unaff_r22;
  param_2[0x17] = unaff_r23;
  param_2[0x18] = unaff_r24;
  param_2[0x19] = unaff_r25;
  param_2[0x1a] = unaff_r26;
  param_2[0x1b] = unaff_r27;
  param_2[0x1c] = unaff_r28;
  param_2[0x1d] = unaff_r29;
  param_2[0x1e] = unaff_r30;
  param_2[0x1f] = unaff_r31;
  param_2[0x6a] = in_GQR1;
  param_2[0x6b] = 0x40004;
  param_2[0x6c] = 0x50005;
  param_2[0x6d] = 0x60006;
  param_2[0x6e] = 0x70007;
  param_2[0x6f] = 0x3d043d04;
  param_2[0x70] = in_GQR7;
  __OSUnhandledException();
  return;
}


undefined4 __OSPSInit(void)

{
  uint uVar1;
  
  uVar1 = base::PPCMfhid2();
  base::PPCMthid2(uVar1 | 0xa0000000);
  ICFlashInvalidate();
  sync(0);
  return 0;
}


uint __OSGetDIConfig(void)

{
  return DAT_cc006024 & 0xff;
}


void OSRegisterVersion(undefined4 param_1)

{
  m_Do_printf::OSReport(_140,param_1);
  return;
}

