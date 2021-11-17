#include <dvd/dvdlow.h>
#include <dvd/dvdlow.h>
#include <os/OSAlarm.h>
#include <os/OSTime.h>
#include <os/OSContext.h>
#include <os/OSInterrupt.h>
#include <dvd/dvd.h>


namespace dvd {
undefined4 CommandList;
undefined AlarmForWA;
undefined AlarmForTimeout;
undefined AlarmForBreak;
undefined4 Prev;
undefined4 Curr;
undefined4 StopAtNextInt;
undefined4 LastLength;
undefined4 Callback;
undefined4 ResetCoverCallback;
undefined4 LastResetEnd;
undefined4 ResetOccurred;
undefined4 WaitingCoverClose;
undefined4 Breaking;
undefined4 WorkAroundType;
undefined4 WorkAroundSeekLocation;
undefined4 LastReadFinished;
undefined4 LastReadIssued;
undefined4 LastCommandWasRead;
undefined4 NextCommandNumber;

void __DVDInitWA(void)

{
  NextCommandNumber = 0;
  CommandList = 0xffffffff;
  __DVDLowSetWAType(0,0);
  os::OSInitAlarm();
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __DVDInterruptHandler(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined auStack736 [716];
  
  uVar8 = 0;
  if (LastCommandWasRead != 0) {
    _LastReadFinished = os::__OSGetSystemTime();
    FirstRead = 0;
    Prev = Curr;
    DAT_803f102c = DAT_803f1038;
    DAT_803f1030 = DAT_803f103c;
    if (StopAtNextInt == 1) {
      uVar8 = 8;
    }
  }
  LastCommandWasRead = 0;
  StopAtNextInt = 0;
  uVar9 = DAT_cc006000 & 0x2a;
  uVar2 = uVar9 << 1 & DAT_cc006000 & 0x54;
  if ((uVar2 & 0x40) != 0) {
    uVar8 = 8;
  }
  if ((uVar2 & 0x10) != 0) {
    uVar8 = uVar8 | 1;
  }
  if ((uVar2 & 4) != 0) {
    uVar8 = uVar8 | 2;
  }
  if (uVar8 != 0) {
    ResetOccurred = 0;
    os::OSCancelAlarm(&AlarmForTimeout);
  }
  DAT_cc006000 = uVar2 | uVar9;
  if (ResetOccurred == 0) {
LAB_8030e5f4:
    if (WaitingCoverClose == 0) {
      DAT_cc006004 = 0;
    }
    else {
      uVar2 = DAT_cc006004 & 4 & (DAT_cc006004 & 2) << 1;
      if (uVar2 != 0) {
        uVar8 = uVar8 | 4;
      }
      DAT_cc006004 = uVar2 | DAT_cc006004 & 2;
      WaitingCoverClose = 0;
    }
  }
  else {
    uVar10 = os::__OSGetSystemTime();
    if (((uint)uVar10 - DAT_803f7a84 < ((DAT_800000f8 >> 2) / 1000) * 200) + 0x80000000 <=
        ((int)((ulonglong)uVar10 >> 0x20) - ((uint)((uint)uVar10 < DAT_803f7a84) + LastResetEnd) ^
        0x80000000)) goto LAB_8030e5f4;
    if ((DAT_cc006004 & 4 & (DAT_cc006004 & 2) << 1) != 0) {
      if (ResetCoverCallback != (code *)0x0) {
        (*ResetCoverCallback)(4);
      }
      ResetCoverCallback = (code *)0x0;
    }
  }
  if (((uVar8 & 8) != 0) && (Breaking == 0)) {
    uVar8 = uVar8 & 0xfffffff7;
  }
  if ((uVar8 & 1) == 0) {
    CommandList = 0xffffffff;
    NextCommandNumber = 0;
  }
  else {
    if ((&CommandList)[NextCommandNumber * 5] == 1) {
      iVar3 = NextCommandNumber * 5;
      iVar4 = NextCommandNumber * 5;
      iVar5 = NextCommandNumber * 5;
      iVar6 = NextCommandNumber * 5;
      NextCommandNumber = NextCommandNumber + 1;
      Read((&DAT_803f0f74)[iVar3],(&DAT_803f0f78)[iVar4],(&DAT_803f0f7c)[iVar5],
           (&DAT_803f0f80)[iVar6]);
      bVar1 = true;
    }
    else {
      if ((&CommandList)[NextCommandNumber * 5] == 2) {
        iVar3 = NextCommandNumber * 5;
        iVar4 = NextCommandNumber * 5;
        NextCommandNumber = NextCommandNumber + 1;
        DVDLowSeek((&DAT_803f0f7c)[iVar3],(&DAT_803f0f80)[iVar4]);
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    if (bVar1) goto LAB_8030e744;
  }
  os::OSClearContext(auStack736);
  os::OSSetCurrentContext(auStack736);
  pcVar7 = Callback;
  if (uVar8 != 0) {
    bVar1 = Callback != (code *)0x0;
    Callback = (code *)0x0;
    if (bVar1) {
      (*pcVar7)(uVar8);
    }
    Breaking = 0;
  }
  os::OSClearContext(auStack736);
  os::OSSetCurrentContext(param_2);
LAB_8030e744:
  LastReadFinished = (undefined4)((ulonglong)_LastReadFinished >> 0x20);
  return;
}


void AlarmHandler(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((&CommandList)[NextCommandNumber * 5] == 1) {
    iVar1 = NextCommandNumber * 5;
    iVar2 = NextCommandNumber * 5;
    iVar3 = NextCommandNumber * 5;
    iVar4 = NextCommandNumber * 5;
    NextCommandNumber = NextCommandNumber + 1;
    Read((&DAT_803f0f74)[iVar1],(&DAT_803f0f78)[iVar2],(&DAT_803f0f7c)[iVar3],(&DAT_803f0f80)[iVar4]
        );
  }
  else {
    if ((&CommandList)[NextCommandNumber * 5] == 2) {
      iVar1 = NextCommandNumber * 5;
      iVar2 = NextCommandNumber * 5;
      NextCommandNumber = NextCommandNumber + 1;
      DVDLowSeek((&DAT_803f0f7c)[iVar1],(&DAT_803f0f80)[iVar2]);
    }
  }
  return;
}


void AlarmHandlerForTimeout(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  code *pcVar2;
  undefined auStack720 [716];
  
  os::__OSMaskInterrupts(0x400);
  os::OSClearContext(auStack720);
  os::OSSetCurrentContext(auStack720);
  pcVar2 = Callback;
  bVar1 = Callback != (code *)0x0;
  Callback = (code *)0x0;
  if (bVar1) {
    (*pcVar2)(0x10);
  }
  os::OSClearContext(auStack720);
  os::OSSetCurrentContext(param_2);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Read(undefined4 param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  
  StopAtNextInt = 0;
  LastCommandWasRead = 1;
  Callback = param_4;
  _LastReadIssued = os::__OSGetSystemTime();
  DAT_cc006008 = 0xa8000000;
  DAT_cc00600c = param_3 >> 2;
  DAT_cc00601c = 3;
  LastLength = param_2;
  DAT_cc006010 = param_2;
  DAT_cc006014 = param_1;
  DAT_cc006018 = param_2;
  if (param_2 < 0xa00001) {
    uVar1 = DAT_800000f8 >> 2;
    os::OSCreateAlarm(&AlarmForTimeout);
    os::OSSetAlarm(&AlarmForTimeout,extraout_r4_00,0,uVar1 * 10,AlarmHandlerForTimeout);
  }
  else {
    uVar1 = DAT_800000f8 >> 2;
    os::OSCreateAlarm(&AlarmForTimeout);
    os::OSSetAlarm(&AlarmForTimeout,extraout_r4,0,uVar1 * 0x14,AlarmHandlerForTimeout);
  }
  LastReadIssued = (undefined4)((ulonglong)_LastReadIssued >> 0x20);
  return;
}


void SeekTwiceBeforeRead(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  if ((param_3 & 0xffff8000) == 0) {
    DAT_803f0f7c = 0;
  }
  else {
    DAT_803f0f7c = (param_3 & 0xffff8000) + WorkAroundSeekLocation;
  }
  CommandList = 2;
  DAT_803f0f84 = 1;
  DAT_803f0f98 = 0xffffffff;
  NextCommandNumber = 0;
  DAT_803f0f80 = param_4;
  DAT_803f0f88 = param_1;
  DAT_803f0f8c = param_2;
  DAT_803f0f90 = param_3;
  DAT_803f0f94 = param_4;
  DVDLowSeek(DAT_803f0f7c,param_4);
  return;
}


undefined4 DVDLowRead(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  undefined4 extraout_r4;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  Curr = param_1;
  DAT_803f1038 = param_2;
  DAT_803f103c = param_3;
  DAT_cc006018 = param_2;
  if (WorkAroundType == 0) {
    CommandList = 0xffffffff;
    NextCommandNumber = 0;
    Read(param_1,param_2,param_3,param_4);
  }
  else {
    if (WorkAroundType == 1) {
      if (FirstRead == 0) {
        uVar4 = (uint)(DAT_803f1030 + DAT_803f102c + -1) >> 0xf;
        iVar3 = DVDGetCurrentDiskID();
        if (*(char *)(iVar3 + 8) == '\0') {
          iVar3 = 0xf;
        }
        else {
          iVar3 = 5;
        }
        if ((uVar4 - 2 < param_3 >> 0xf) || (param_3 >> 0xf < uVar4 + iVar3 + 3)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          uVar4 = (uint)(DAT_803f1030 + DAT_803f102c + -1) >> 0xf;
          if ((uVar4 == DAT_803f103c >> 0xf) || (uVar4 + 1 == DAT_803f103c >> 0xf)) {
            uVar7 = os::__OSGetSystemTime();
            uVar6 = (uint)uVar7 - DAT_803f7aa4;
            uVar5 = (int)((ulonglong)uVar7 >> 0x20) -
                    ((uint)((uint)uVar7 < DAT_803f7aa4) + LastReadFinished);
            uVar4 = ((DAT_800000f8 >> 2) / 1000) * 5;
            if ((uint)(uVar4 < uVar6) + (uVar5 ^ 0x80000000) < 0x80000001) {
              CommandList = 1;
              DAT_803f0f84 = 0xffffffff;
              uVar1 = ((DAT_800000f8 >> 2) / 0x1e848) * 500 >> 3;
              NextCommandNumber = 0;
              DAT_803f0f74 = param_1;
              DAT_803f0f78 = param_2;
              DAT_803f0f7c = param_3;
              DAT_803f0f80 = param_4;
              os::OSCreateAlarm(&AlarmForWA);
              os::OSSetAlarm(&AlarmForWA,extraout_r4,
                             (uint)CARRY4(uVar4 - uVar6,uVar1) - ((uVar4 < uVar6) + uVar5),
                             (uVar4 - uVar6) + uVar1,AlarmHandler);
            }
            else {
              CommandList = 0xffffffff;
              NextCommandNumber = 0;
              Read(param_1,param_2,param_3,param_4);
            }
          }
          else {
            SeekTwiceBeforeRead(param_1,param_2,param_3,param_4);
          }
        }
        else {
          CommandList = 0xffffffff;
          NextCommandNumber = 0;
          Read(param_1,param_2,param_3,param_4);
        }
      }
      else {
        SeekTwiceBeforeRead(param_1,param_2,param_3,param_4);
      }
    }
  }
  return 1;
}


undefined4 DVDLowSeek(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 extraout_r4;
  
  StopAtNextInt = 0;
  DAT_cc006008 = 0xab000000;
  DAT_cc00600c = param_1 >> 2;
  DAT_cc00601c = 1;
  uVar1 = DAT_800000f8 >> 2;
  Callback = param_2;
  os::OSCreateAlarm(&AlarmForTimeout);
  os::OSSetAlarm(&AlarmForTimeout,extraout_r4,0,uVar1 * 10,AlarmHandlerForTimeout);
  return 1;
}


undefined4 DVDLowWaitCoverClose(undefined4 param_1)

{
  StopAtNextInt = 0;
  Callback = param_1;
  WaitingCoverClose = 1;
  DAT_cc006004 = 2;
  return 1;
}


undefined4 DVDLowReadDiskID(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 extraout_r4;
  
  StopAtNextInt = 0;
  DAT_cc006008 = 0xa8000040;
  DAT_cc00600c = 0;
  DAT_cc006010 = 0x20;
  DAT_cc006018 = 0x20;
  DAT_cc00601c = 3;
  uVar1 = DAT_800000f8 >> 2;
  Callback = param_2;
  DAT_cc006014 = param_1;
  os::OSCreateAlarm(&AlarmForTimeout);
  os::OSSetAlarm(&AlarmForTimeout,extraout_r4,0,uVar1 * 10,AlarmHandlerForTimeout);
  return 1;
}


undefined4 DVDLowStopMotor(undefined4 param_1)

{
  uint uVar1;
  undefined4 extraout_r4;
  
  StopAtNextInt = 0;
  DAT_cc006008 = 0xe3000000;
  DAT_cc00601c = 1;
  uVar1 = DAT_800000f8 >> 2;
  Callback = param_1;
  os::OSCreateAlarm(&AlarmForTimeout);
  os::OSSetAlarm(&AlarmForTimeout,extraout_r4,0,uVar1 * 10,AlarmHandlerForTimeout);
  return 1;
}


undefined4 DVDLowRequestError(undefined4 param_1)

{
  uint uVar1;
  undefined4 extraout_r4;
  
  StopAtNextInt = 0;
  DAT_cc006008 = 0xe0000000;
  DAT_cc00601c = 1;
  uVar1 = DAT_800000f8 >> 2;
  Callback = param_1;
  os::OSCreateAlarm(&AlarmForTimeout);
  os::OSSetAlarm(&AlarmForTimeout,extraout_r4,0,uVar1 * 10,AlarmHandlerForTimeout);
  return 1;
}


undefined4 DVDLowInquiry(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 extraout_r4;
  
  StopAtNextInt = 0;
  DAT_cc006008 = 0x12000000;
  DAT_cc006010 = 0x20;
  DAT_cc006018 = 0x20;
  DAT_cc00601c = 3;
  uVar1 = DAT_800000f8 >> 2;
  Callback = param_2;
  DAT_cc006014 = param_1;
  os::OSCreateAlarm(&AlarmForTimeout);
  os::OSSetAlarm(&AlarmForTimeout,extraout_r4,0,uVar1 * 10,AlarmHandlerForTimeout);
  return 1;
}


undefined4 DVDLowAudioStream(uint param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 extraout_r4;
  
  StopAtNextInt = 0;
  DAT_cc006008 = param_1 | 0xe1000000;
  DAT_cc00600c = param_3 >> 2;
  DAT_cc00601c = 1;
  uVar1 = DAT_800000f8 >> 2;
  Callback = param_4;
  DAT_cc006010 = param_2;
  os::OSCreateAlarm(&AlarmForTimeout);
  os::OSSetAlarm(&AlarmForTimeout,extraout_r4,0,uVar1 * 10,AlarmHandlerForTimeout);
  return 1;
}


undefined4 DVDLowRequestAudioStatus(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 extraout_r4;
  
  StopAtNextInt = 0;
  DAT_cc006008 = param_1 | 0xe2000000;
  DAT_cc00601c = 1;
  uVar1 = DAT_800000f8 >> 2;
  Callback = param_2;
  os::OSCreateAlarm(&AlarmForTimeout);
  os::OSSetAlarm(&AlarmForTimeout,extraout_r4,0,uVar1 * 10,AlarmHandlerForTimeout);
  return 1;
}


undefined4 DVDLowAudioBufferConfig(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 extraout_r4;
  
  uVar1 = 0;
  StopAtNextInt = 0;
  if (param_1 != 0) {
    uVar1 = 0x10000;
  }
  DAT_cc006008 = param_2 | uVar1 | 0xe4000000;
  DAT_cc00601c = 1;
  uVar1 = DAT_800000f8 >> 2;
  Callback = param_3;
  os::OSCreateAlarm(&AlarmForTimeout);
  os::OSSetAlarm(&AlarmForTimeout,extraout_r4,0,uVar1 * 10,AlarmHandlerForTimeout);
  return 1;
}


void DVDLowReset(void)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  uVar2 = DAT_cc003024;
  DAT_cc006004 = 2;
  DAT_cc003024 = DAT_cc003024 & 0xfffffffb | 1;
  uVar3 = os::__OSGetSystemTime();
  uVar1 = DAT_800000f8 >> 2;
  do {
    uVar4 = os::__OSGetSystemTime();
  } while (((int)((ulonglong)uVar4 >> 0x20) -
            ((uint)((uint)uVar4 < (uint)uVar3) + (int)((ulonglong)uVar3 >> 0x20)) ^ 0x80000000) <
           ((uint)uVar4 - (uint)uVar3 < (uVar1 / 0x1e848) * 0xc >> 3) + 0x80000000);
  DAT_cc003024 = uVar2 | 5;
  ResetOccurred = 1;
  uVar3 = os::__OSGetSystemTime();
  LastResetEnd = (int)((ulonglong)uVar3 >> 0x20);
  DAT_803f7a84 = (int)uVar3;
  return;
}


undefined4 DVDLowBreak(void)

{
  StopAtNextInt = 1;
  Breaking = 1;
  return 1;
}


undefined4 DVDLowClearCallback(void)

{
  undefined4 uVar1;
  
  uVar1 = Callback;
  Callback = 0;
  DAT_cc006004 = 0;
  return uVar1;
}


void __DVDLowSetWAType(undefined4 param_1,undefined4 param_2)

{
  os::OSDisableInterrupts();
  WorkAroundType = param_1;
  WorkAroundSeekLocation = param_2;
  os::OSRestoreInterrupts();
  return;
}

