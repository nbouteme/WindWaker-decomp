#include <dvd/dvd.h>
#include <os/OS.h>
#include <dvd/dvdfs.h>
#include <dvd/dvdqueue.h>
#include <dvd/dvdlow.h>
#include <os/OSInterrupt.h>
#include <os/OSThread.h>
#include <m_Do_printf.h>
#include <dvd/fstload.h>
#include <dvd/dvd.h>
#include <dvd/dvdFatal.h>
#include <dvd/dvderror.h>
#include <dvd/dvdidutils.h>
#include <os/OSCache.h>
#include <MSL_C.PPCEABI.bare.H/mem.h>
#include <os/OSAlarm.h>


namespace dvd {
undefined BB2;
undefined CurrDiskID;
undefined DummyCommandBlock;
undefined ResetAlarm;
undefined4 executing;
undefined4 IDShouldBe;
undefined4 bootInfo;
undefined4 PauseFlag;
undefined4 PausingFlag;
undefined4 AutoFinishing;
undefined4 FatalErrorFlag;
undefined4 CurrCommand;
undefined4 Canceling;
undefined4 CancelCallback;
undefined4 ResumeFromHere;
undefined4 CancelLastError;
undefined4 LastError;
undefined4 NumInternalRetry;
undefined4 ResetRequired;
undefined4 FirstTimeInBootrom;
undefined4 DVDInitialized;
undefined4 LastState;

void defaultOptionalCommandChecker(void)

{
  return;
}


void DVDInit(void)

{
  if (DVDInitialized == 0) {
    os::OSRegisterVersion(__DVDVersion);
    DVDInitialized = 1;
    __DVDFSInit();
    __DVDClearWaitingQueue();
    __DVDInitWA();
    bootInfo = -0x80000000;
    IDShouldBe = 0x80000000;
    os::__OSSetInterruptHandler(0x15,__DVDInterruptHandler);
    os::__OSUnmaskInterrupts(0x400);
    os::OSInitThreadQueue(&__DVDThreadQueue);
    DAT_cc006000 = 0x2a;
    DAT_cc006004 = 0;
    if (*(int *)(bootInfo + 0x20) == -0x1adf83de) {
      m_Do_printf::OSReport(_18);
      __fstLoad();
    }
    else {
      if (*(int *)(bootInfo + 0x20) != 0xd15ea5e) {
        FirstTimeInBootrom = 1;
      }
    }
  }
  return;
}


void stateReadingFST(void)

{
  LastState = stateReadingFST;
  if (*(uint *)(bootInfo + 0x3c) < DAT_803f1048) {
    m_Do_printf::OSPanic(&_23,0x276,_24);
  }
  DVDLowRead(*(undefined4 *)(bootInfo + 0x38),DAT_803f1048 + 0x1f & 0xffffffe0,DAT_803f1044,
             cbForStateReadingFST);
  return;
}


void cbForStateReadingFST(uint param_1)

{
  undefined *puVar1;
  code *pcVar2;
  
  if (param_1 == 0x10) {
    *(undefined4 *)(executing + 0xc) = 0xffffffff;
    stateTimeout();
  }
  else {
    if ((param_1 & 1) == 0) {
      stateGettingError();
    }
    else {
      NumInternalRetry = 0;
      __DVDFSInit();
      puVar1 = executing;
      executing = &DummyCommandBlock;
      *(undefined4 *)(puVar1 + 0xc) = 0;
      pcVar2 = *(code **)(puVar1 + 0x28);
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(0);
      }
      stateReady();
    }
  }
  return;
}


void cbForStateError(int param_1)

{
  undefined *puVar1;
  
  if (param_1 == 0x10) {
    *(undefined4 *)(executing + 0xc) = 0xffffffff;
    stateTimeout();
  }
  else {
    __DVDPrintFatalMessage();
    puVar1 = executing;
    executing = &DummyCommandBlock;
    FatalErrorFlag = 1;
    if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
      (**(code **)(puVar1 + 0x28))(0xffffffff,puVar1);
    }
    if (Canceling != 0) {
      Canceling = 0;
      if (CancelCallback != (code *)0x0) {
        (*CancelCallback)(0,puVar1);
      }
    }
    stateReady();
  }
  return;
}


void stateTimeout(void)

{
  __DVDStoreErrorCode(0x1234568);
  DVDReset();
  cbForStateError(0);
  return;
}


void stateGettingError(void)

{
  DVDLowRequestError(cbForStateGettingError);
  return;
}


undefined4 CategorizeError(uint param_1)

{
  if (param_1 == 0x20400) {
    LastError = param_1;
    return 1;
  }
  param_1 = param_1 & 0xffffff;
  if (((param_1 == 0x62800) || (param_1 == 0x23a00)) || (param_1 == 0xb5a01)) {
    return 0;
  }
  NumInternalRetry = NumInternalRetry + 1;
  if (NumInternalRetry == 2) {
    if (param_1 == LastError) {
      LastError = param_1;
      return 1;
    }
    LastError = param_1;
    return 2;
  }
  if ((param_1 != 0x31100) && (*(int *)(executing + 8) != 5)) {
    LastError = param_1;
    return 3;
  }
  LastError = param_1;
  return 2;
}


void cbForStateGettingError(uint param_1)

{
  bool bVar1;
  uint uVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar4 = DAT_cc006020;
  if (param_1 == 0x10) {
    *(undefined4 *)(executing + 0xc) = 0xffffffff;
    __DVDStoreErrorCode(0x1234568);
    DVDReset();
    cbForStateError(0);
  }
  else {
    if ((param_1 & 2) == 0) {
      uVar2 = DAT_cc006020 & 0xff000000;
      iVar5 = CategorizeError(DAT_cc006020);
      puVar3 = executing;
      if (iVar5 == 1) {
        *(undefined4 *)(executing + 0xc) = 0xffffffff;
        __DVDStoreErrorCode(uVar4);
        DVDLowStopMotor(cbForStateError);
      }
      else {
        if (iVar5 - 2U < 2) {
          uVar6 = 0;
        }
        else {
          if (uVar2 == 0x1000000) {
            uVar6 = 4;
          }
          else {
            if (uVar2 == 0x2000000) {
              uVar6 = 6;
            }
            else {
              if (uVar2 == 0x3000000) {
                uVar6 = 3;
              }
              else {
                uVar6 = 5;
              }
            }
          }
        }
        if (Canceling == 0) {
          bVar1 = false;
        }
        else {
          Canceling = 0;
          executing = &DummyCommandBlock;
          ResumeFromHere = uVar6;
          *(undefined4 *)(puVar3 + 0xc) = 10;
          if (*(code **)(puVar3 + 0x28) != (code *)0x0) {
            (**(code **)(puVar3 + 0x28))(0xfffffffd,puVar3);
          }
          if (CancelCallback != (code *)0x0) {
            (*CancelCallback)(0,puVar3);
          }
          stateReady();
          bVar1 = true;
        }
        if (!bVar1) {
          if (iVar5 == 2) {
            __DVDStoreErrorCode(uVar4);
            stateGoToRetry();
          }
          else {
            if (iVar5 == 3) {
              if ((uVar4 & 0xffffff) == 0x31100) {
                DVDLowSeek(*(undefined4 *)(executing + 0x10),cbForUnrecoveredError);
              }
              else {
                (*LastState)(executing);
              }
            }
            else {
              if (uVar2 == 0x1000000) {
                *(undefined4 *)(executing + 0xc) = 5;
                stateMotorStopped();
              }
              else {
                if (uVar2 == 0x2000000) {
                  *(undefined4 *)(executing + 0xc) = 3;
                  stateCoverClosed();
                }
                else {
                  if (uVar2 == 0x3000000) {
                    *(undefined4 *)(executing + 0xc) = 4;
                    stateMotorStopped();
                  }
                  else {
                    *(undefined4 *)(executing + 0xc) = 0xffffffff;
                    __DVDStoreErrorCode(&DAT_01234567);
                    DVDLowStopMotor(cbForStateError);
                  }
                }
              }
            }
          }
        }
      }
    }
    else {
      *(undefined4 *)(executing + 0xc) = 0xffffffff;
      __DVDStoreErrorCode(&DAT_01234567);
      DVDLowStopMotor(cbForStateError);
    }
  }
  return;
}


void cbForUnrecoveredError(uint param_1)

{
  if (param_1 == 0x10) {
    *(undefined4 *)(executing + 0xc) = 0xffffffff;
    __DVDStoreErrorCode(0x1234568);
    DVDReset();
    cbForStateError(0);
  }
  else {
    if ((param_1 & 1) == 0) {
      DVDLowRequestError(cbForUnrecoveredErrorRetry);
    }
    else {
      stateGoToRetry();
    }
  }
  return;
}


void cbForUnrecoveredErrorRetry(uint param_1)

{
  if (param_1 == 0x10) {
    *(undefined4 *)(executing + 0xc) = 0xffffffff;
    __DVDStoreErrorCode(0x1234568);
    DVDReset();
    cbForStateError(0);
  }
  else {
    *(undefined4 *)(executing + 0xc) = 0xffffffff;
    if ((param_1 & 2) == 0) {
      __DVDStoreErrorCode(DAT_cc006020);
      DVDLowStopMotor(cbForStateError);
    }
    else {
      __DVDStoreErrorCode(&DAT_01234567);
      DVDLowStopMotor(cbForStateError);
    }
  }
  return;
}


void stateGoToRetry(void)

{
  DVDLowStopMotor(cbForStateGoToRetry);
  return;
}


void cbForStateGoToRetry(uint param_1)

{
  bool bVar1;
  undefined *puVar2;
  
  puVar2 = executing;
  if (param_1 == 0x10) {
    *(undefined4 *)(executing + 0xc) = 0xffffffff;
    __DVDStoreErrorCode(0x1234568);
    DVDReset();
    cbForStateError(0);
  }
  else {
    if ((param_1 & 2) == 0) {
      NumInternalRetry = 0;
      if ((((CurrCommand == 4) || (CurrCommand == 5)) || (CurrCommand == 0xd)) ||
         (CurrCommand == 0xf)) {
        ResetRequired = 1;
      }
      if (Canceling == 0) {
        bVar1 = false;
      }
      else {
        ResumeFromHere = 2;
        executing = &DummyCommandBlock;
        Canceling = 0;
        *(undefined4 *)(puVar2 + 0xc) = 10;
        if (*(code **)(puVar2 + 0x28) != (code *)0x0) {
          (**(code **)(puVar2 + 0x28))(0xfffffffd,puVar2);
        }
        if (CancelCallback != (code *)0x0) {
          (*CancelCallback)(0,puVar2);
        }
        stateReady();
        bVar1 = true;
      }
      if (!bVar1) {
        *(undefined4 *)(executing + 0xc) = 0xb;
        stateMotorStopped();
      }
    }
    else {
      *(undefined4 *)(executing + 0xc) = 0xffffffff;
      __DVDStoreErrorCode(&DAT_01234567);
      DVDLowStopMotor(cbForStateError);
    }
  }
  return;
}


void stateCheckID(void)

{
  int iVar1;
  
  if (CurrCommand == 3) {
    iVar1 = DVDCompareDiskID(&CurrDiskID,*(undefined4 *)(executing + 0x24));
    if (iVar1 == 0) {
      DVDLowStopMotor(cbForStateCheckID1);
    }
    else {
      copy_bytes(IDShouldBe,&CurrDiskID,0x20);
      *(undefined4 *)(executing + 0xc) = 1;
      os::DCInvalidateRange(&BB2,0x20);
      LastState = stateCheckID2a;
      stateCheckID2a(executing);
    }
  }
  else {
    iVar1 = MSL_C.PPCEABI.bare.H::memcmp(&CurrDiskID,IDShouldBe,0x20);
    if (iVar1 == 0) {
      LastState = stateCheckID3;
      stateCheckID3(executing);
    }
    else {
      DVDLowStopMotor(cbForStateCheckID1);
    }
  }
  return;
}


void stateCheckID3(void)

{
  DVDLowAudioBufferConfig(*(undefined *)(IDShouldBe + 8),10,cbForStateCheckID3);
  return;
}


void stateCheckID2a(void)

{
  DVDLowAudioBufferConfig(*(undefined *)(IDShouldBe + 8),10,cbForStateCheckID2a);
  return;
}


void cbForStateCheckID2a(uint param_1)

{
  if (param_1 == 0x10) {
    *(undefined4 *)(executing + 0xc) = 0xffffffff;
    __DVDStoreErrorCode(0x1234568);
    DVDReset();
    cbForStateError(0);
  }
  else {
    if ((param_1 & 1) == 0) {
      DVDLowRequestError(cbForStateGettingError);
    }
    else {
      NumInternalRetry = 0;
      stateCheckID2(executing);
    }
  }
  return;
}


void stateCheckID2(void)

{
  DVDLowRead(&BB2,0x20,0x420,cbForStateCheckID2);
  return;
}


void cbForStateCheckID1(uint param_1)

{
  undefined *puVar1;
  bool bVar2;
  
  puVar1 = executing;
  if (param_1 == 0x10) {
    *(undefined4 *)(executing + 0xc) = 0xffffffff;
    __DVDStoreErrorCode(0x1234568);
    DVDReset();
    cbForStateError(0);
  }
  else {
    if ((param_1 & 2) == 0) {
      bVar2 = false;
      NumInternalRetry = 0;
      if (Canceling != 0) {
        ResumeFromHere = 1;
        Canceling = 0;
        executing = &DummyCommandBlock;
        *(undefined4 *)(puVar1 + 0xc) = 10;
        if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
          (**(code **)(puVar1 + 0x28))(0xfffffffd,puVar1);
        }
        if (CancelCallback != (code *)0x0) {
          (*CancelCallback)(0,puVar1);
        }
        stateReady();
        bVar2 = true;
      }
      if (!bVar2) {
        *(undefined4 *)(executing + 0xc) = 6;
        stateMotorStopped();
      }
    }
    else {
      *(undefined4 *)(executing + 0xc) = 0xffffffff;
      __DVDStoreErrorCode(&DAT_01234567);
      DVDLowStopMotor(cbForStateError);
    }
  }
  return;
}


void cbForStateCheckID2(uint param_1)

{
  if (param_1 == 0x10) {
    *(undefined4 *)(executing + 0xc) = 0xffffffff;
    __DVDStoreErrorCode(0x1234568);
    DVDReset();
    cbForStateError(0);
  }
  else {
    if ((param_1 & 1) == 0) {
      DVDLowRequestError(cbForStateGettingError);
    }
    else {
      LastState = stateReadingFST;
      NumInternalRetry = 0;
      if (*(uint *)(bootInfo + 0x3c) < DAT_803f1048) {
        m_Do_printf::OSPanic(&_23,0x276,_24);
      }
      DVDLowRead(*(undefined4 *)(bootInfo + 0x38),DAT_803f1048 + 0x1f & 0xffffffe0,DAT_803f1044,
                 cbForStateReadingFST);
    }
  }
  return;
}


void cbForStateCheckID3(uint param_1)

{
  undefined *puVar1;
  bool bVar2;
  
  puVar1 = executing;
  if (param_1 == 0x10) {
    *(undefined4 *)(executing + 0xc) = 0xffffffff;
    __DVDStoreErrorCode(0x1234568);
    DVDReset();
    cbForStateError(0);
  }
  else {
    if ((param_1 & 1) == 0) {
      DVDLowRequestError(cbForStateGettingError);
    }
    else {
      bVar2 = false;
      NumInternalRetry = 0;
      if (Canceling != 0) {
        ResumeFromHere = 0;
        Canceling = 0;
        executing = &DummyCommandBlock;
        *(undefined4 *)(puVar1 + 0xc) = 10;
        if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
          (**(code **)(puVar1 + 0x28))(0xfffffffd,puVar1);
        }
        if (CancelCallback != (code *)0x0) {
          (*CancelCallback)(0,puVar1);
        }
        stateReady();
        bVar2 = true;
      }
      if (!bVar2) {
        *(undefined4 *)(executing + 0xc) = 1;
        stateBusy(executing);
      }
    }
  }
  return;
}


void AlarmHandler(void)

{
  DVDReset();
  os::DCInvalidateRange(&CurrDiskID,0x20);
  LastState = stateCoverClosed_CMD;
  stateCoverClosed_CMD(executing);
  return;
}


void stateCoverClosed(void)

{
  undefined *puVar1;
  
  if (CurrCommand == 0xd) {
LAB_80310dc4:
    __DVDClearWaitingQueue();
    puVar1 = executing;
    executing = &DummyCommandBlock;
    if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
      (**(code **)(puVar1 + 0x28))(0xfffffffc);
    }
    stateReady();
  }
  else {
    if (CurrCommand < 0xd) {
      if ((CurrCommand < 6) && (3 < CurrCommand)) goto LAB_80310dc4;
    }
    else {
      if (CurrCommand == 0xf) goto LAB_80310dc4;
    }
    DVDReset();
    os::OSCreateAlarm(&ResetAlarm);
    os::OSSetAlarm(&ResetAlarm,0x10624dd3,0,((DAT_800000f8 >> 2) / 1000) * 0x47e,AlarmHandler);
  }
  return;
}


void stateCoverClosed_CMD(void)

{
  DVDLowReadDiskID(&CurrDiskID,cbForStateCoverClosed);
  return;
}


void cbForStateCoverClosed(uint param_1)

{
  if (param_1 == 0x10) {
    *(undefined4 *)(executing + 0xc) = 0xffffffff;
    __DVDStoreErrorCode(0x1234568);
    DVDReset();
    cbForStateError(0);
  }
  else {
    if ((param_1 & 1) == 0) {
      DVDLowRequestError(cbForStateGettingError);
    }
    else {
      NumInternalRetry = 0;
      stateCheckID();
    }
  }
  return;
}


void stateMotorStopped(void)

{
  DVDLowWaitCoverClose(cbForStateMotorStopped);
  return;
}


void cbForStateMotorStopped(void)

{
  undefined *puVar1;
  
  DAT_cc006004 = 0;
  *(undefined4 *)(executing + 0xc) = 3;
  if (CurrCommand == 0xd) {
LAB_80310f70:
    __DVDClearWaitingQueue();
    puVar1 = executing;
    executing = &DummyCommandBlock;
    if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
      (**(code **)(puVar1 + 0x28))(0xfffffffc);
    }
    stateReady();
  }
  else {
    if (CurrCommand < 0xd) {
      if ((CurrCommand < 6) && (3 < CurrCommand)) goto LAB_80310f70;
    }
    else {
      if (CurrCommand == 0xf) goto LAB_80310f70;
    }
    DVDReset();
    os::OSCreateAlarm(&ResetAlarm);
    os::OSSetAlarm(&ResetAlarm,0x10624dd3,0,((DAT_800000f8 >> 2) / 1000) * 0x47e,AlarmHandler);
  }
  return;
}


void stateReady(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = __DVDCheckWaitingQueue();
  if (iVar2 == 0) {
    executing = (undefined *)0x0;
    return;
  }
  if (PauseFlag != 0) {
    executing = (undefined *)0x0;
    PausingFlag = 1;
    return;
  }
  executing = (undefined *)__DVDPopWaitingQueue();
  if (FatalErrorFlag != 0) {
    *(undefined4 *)(executing + 0xc) = 0xffffffff;
    puVar1 = executing;
    executing = &DummyCommandBlock;
    if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
      (**(code **)(puVar1 + 0x28))(0xffffffff);
    }
    stateReady();
    return;
  }
  CurrCommand = *(int *)(executing + 8);
  if (ResumeFromHere == 0) {
    *(undefined4 *)(executing + 0xc) = 1;
    stateBusy(executing);
    return;
  }
  if (ResumeFromHere == 4) {
    *(undefined4 *)(executing + 0xc) = 5;
    DVDLowWaitCoverClose(cbForStateMotorStopped);
    ResumeFromHere = 0;
    return;
  }
  if (ResumeFromHere < 4) {
    if (ResumeFromHere == 2) {
      *(undefined4 *)(executing + 0xc) = 0xb;
      DVDLowWaitCoverClose(cbForStateMotorStopped);
      ResumeFromHere = 0;
      return;
    }
    if (1 < ResumeFromHere) {
      *(undefined4 *)(executing + 0xc) = 4;
      DVDLowWaitCoverClose(cbForStateMotorStopped);
      ResumeFromHere = 0;
      return;
    }
    if (ResumeFromHere < 1) {
      ResumeFromHere = 0;
      return;
    }
    *(undefined4 *)(executing + 0xc) = 1;
    if (CurrCommand != 0xd) {
      if (CurrCommand < 0xd) {
        if ((CurrCommand < 6) && (3 < CurrCommand)) goto LAB_8031111c;
      }
      else {
        if (CurrCommand == 0xf) goto LAB_8031111c;
      }
      DVDReset();
      os::OSCreateAlarm(&ResetAlarm);
      os::OSSetAlarm(&ResetAlarm,0x10624dd3,0,((DAT_800000f8 >> 2) / 1000) * 0x47e,AlarmHandler);
      ResumeFromHere = 0;
      return;
    }
LAB_8031111c:
    __DVDClearWaitingQueue();
    puVar1 = executing;
    executing = &DummyCommandBlock;
    if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
      (**(code **)(puVar1 + 0x28))(0xfffffffc);
    }
    stateReady();
    ResumeFromHere = 0;
    return;
  }
  if (7 < ResumeFromHere) {
    ResumeFromHere = 0;
    return;
  }
  if (ResumeFromHere < 6) {
    *(undefined4 *)(executing + 0xc) = 0xffffffff;
    __DVDStoreErrorCode(CancelLastError);
    DVDLowStopMotor(cbForStateError);
    ResumeFromHere = 0;
    return;
  }
  *(undefined4 *)(executing + 0xc) = 3;
  if (CurrCommand == 0xd) {
LAB_80311210:
    __DVDClearWaitingQueue();
    puVar1 = executing;
    executing = &DummyCommandBlock;
    if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
      (**(code **)(puVar1 + 0x28))(0xfffffffc);
    }
    stateReady();
  }
  else {
    if (CurrCommand < 0xd) {
      if ((CurrCommand < 6) && (3 < CurrCommand)) goto LAB_80311210;
    }
    else {
      if (CurrCommand == 0xf) goto LAB_80311210;
    }
    DVDReset();
    os::OSCreateAlarm(&ResetAlarm);
    os::OSSetAlarm(&ResetAlarm,0x10624dd3,0,((DAT_800000f8 >> 2) / 1000) * 0x47e,AlarmHandler);
  }
  ResumeFromHere = 0;
  return;
}


void stateBusy(int param_1)

{
  undefined *puVar1;
  uint uVar2;
  code *pcVar3;
  
  puVar1 = executing;
  LastState = stateBusy;
  switch(*(undefined4 *)(param_1 + 8)) {
  default:
    (*checkOptionalCommand)(param_1,cbForStateBusy);
    break;
  case 1:
  case 4:
    if (*(int *)(param_1 + 0x14) == 0) {
      executing = &DummyCommandBlock;
      *(undefined4 *)(puVar1 + 0xc) = 0;
      pcVar3 = *(code **)(puVar1 + 0x28);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(0);
      }
      stateReady();
    }
    else {
      uVar2 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x20);
      if (0x80000 < uVar2) {
        uVar2 = 0x80000;
      }
      *(uint *)(param_1 + 0x1c) = uVar2;
      DVDLowRead(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x1c)
                 ,*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x20),cbForStateBusy);
    }
    break;
  case 2:
    DVDLowSeek(*(undefined4 *)(param_1 + 0x10),cbForStateBusy);
    break;
  case 3:
    DVDLowStopMotor(cbForStateBusy);
    break;
  case 5:
    *(undefined4 *)(param_1 + 0x1c) = 0x20;
    DVDLowReadDiskID(*(undefined4 *)(param_1 + 0x18),cbForStateBusy);
    break;
  case 6:
    if (AutoFinishing == 0) {
      *(undefined4 *)(executing + 0x1c) = 1;
      DVDLowAudioStream(0,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x10),
                        cbForStateBusy);
    }
    else {
      *(undefined4 *)(executing + 0x1c) = 0;
      DVDLowRequestAudioStatus(0,cbForStateBusy);
    }
    break;
  case 7:
    DVDLowAudioStream(0x10000,0,0,cbForStateBusy);
    break;
  case 8:
    AutoFinishing = 1;
    DVDLowAudioStream(0,0,0,cbForStateBusy);
    break;
  case 9:
    DVDLowRequestAudioStatus(0,cbForStateBusy);
    break;
  case 10:
    DVDLowRequestAudioStatus(0x10000,cbForStateBusy);
    break;
  case 0xb:
    DVDLowRequestAudioStatus(0x20000,cbForStateBusy);
    break;
  case 0xc:
    DVDLowRequestAudioStatus(0x30000,cbForStateBusy);
    break;
  case 0xd:
    DVDLowAudioBufferConfig
              (*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),cbForStateBusy);
    break;
  case 0xe:
    *(undefined4 *)(param_1 + 0x1c) = 0x20;
    DVDLowInquiry(*(undefined4 *)(param_1 + 0x18),cbForStateBusy);
    break;
  case 0xf:
    DVDLowStopMotor(cbForStateBusy);
  }
  return;
}


void cbForStateBusy(uint param_1)

{
  undefined *puVar1;
  uint uVar2;
  bool bVar3;
  
  puVar1 = executing;
  if (param_1 == 0x10) {
    *(undefined4 *)(executing + 0xc) = 0xffffffff;
    __DVDStoreErrorCode(0x1234568);
    DVDReset();
    cbForStateError(0);
  }
  else {
    if ((CurrCommand == 3) || (CurrCommand == 0xf)) {
      if ((param_1 & 2) == 0) {
        NumInternalRetry = 0;
        if (CurrCommand == 0xf) {
          ResetRequired = 1;
        }
        if (Canceling == 0) {
          bVar3 = false;
        }
        else {
          ResumeFromHere = 7;
          Canceling = 0;
          executing = &DummyCommandBlock;
          *(undefined4 *)(puVar1 + 0xc) = 10;
          if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
            (**(code **)(puVar1 + 0x28))(0xfffffffd,puVar1);
          }
          if (CancelCallback != (code *)0x0) {
            (*CancelCallback)(0,puVar1);
          }
          stateReady();
          bVar3 = true;
        }
        if (!bVar3) {
          *(undefined4 *)(executing + 0xc) = 7;
          DVDLowWaitCoverClose(cbForStateMotorStopped);
        }
      }
      else {
        *(undefined4 *)(executing + 0xc) = 0xffffffff;
        __DVDStoreErrorCode(&DAT_01234567);
        DVDLowStopMotor(cbForStateError);
      }
    }
    else {
      if ((CurrCommand == 1) || ((CurrCommand - 4U < 2 || (CurrCommand == 0xe)))) {
        bVar3 = true;
      }
      else {
        if (CurrCommand == DmaCommand) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
      }
      if (bVar3) {
        *(int *)(executing + 0x20) =
             *(int *)(executing + 0x20) + (*(int *)(executing + 0x1c) - DAT_cc006018);
      }
      puVar1 = executing;
      if ((param_1 & 8) == 0) {
        if ((param_1 & 1) == 0) {
          if (CurrCommand == 0xe) {
            *(undefined4 *)(executing + 0xc) = 0xffffffff;
            __DVDStoreErrorCode(&DAT_01234567);
            DVDLowStopMotor(cbForStateError);
          }
          else {
            if (((((CurrCommand == 1) || (CurrCommand == 4)) || (CurrCommand == 5)) ||
                (CurrCommand == 0xe)) && (*(int *)(executing + 0x20) == *(int *)(executing + 0x14)))
            {
              if (Canceling == 0) {
                bVar3 = false;
              }
              else {
                ResumeFromHere = 0;
                Canceling = 0;
                executing = &DummyCommandBlock;
                *(undefined4 *)(puVar1 + 0xc) = 10;
                if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
                  (**(code **)(puVar1 + 0x28))(0xfffffffd,puVar1);
                }
                if (CancelCallback != (code *)0x0) {
                  (*CancelCallback)(0,puVar1);
                }
                stateReady();
                bVar3 = true;
              }
              puVar1 = executing;
              if (!bVar3) {
                executing = &DummyCommandBlock;
                *(undefined4 *)(puVar1 + 0xc) = 0;
                if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
                  (**(code **)(puVar1 + 0x28))(*(undefined4 *)(puVar1 + 0x20));
                }
                stateReady();
              }
            }
            else {
              DVDLowRequestError(cbForStateGettingError);
            }
          }
        }
        else {
          bVar3 = false;
          NumInternalRetry = 0;
          if (Canceling != 0) {
            ResumeFromHere = 0;
            Canceling = 0;
            executing = &DummyCommandBlock;
            *(undefined4 *)(puVar1 + 0xc) = 10;
            if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
              (**(code **)(puVar1 + 0x28))(0xfffffffd,puVar1);
            }
            if (CancelCallback != (code *)0x0) {
              (*CancelCallback)(0,puVar1);
            }
            stateReady();
            bVar3 = true;
          }
          puVar1 = executing;
          if (!bVar3) {
            if (((CurrCommand == 1) || (CurrCommand - 4U < 2)) || (CurrCommand == 0xe)) {
              bVar3 = true;
            }
            else {
              if (CurrCommand == DmaCommand) {
                bVar3 = true;
              }
              else {
                bVar3 = false;
              }
            }
            if (bVar3) {
              if (*(int *)(executing + 0x20) == *(int *)(executing + 0x14)) {
                executing = &DummyCommandBlock;
                *(undefined4 *)(puVar1 + 0xc) = 0;
                if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
                  (**(code **)(puVar1 + 0x28))(*(undefined4 *)(puVar1 + 0x20));
                }
                stateReady();
              }
              else {
                stateBusy();
              }
            }
            else {
              if (CurrCommand - 9U < 4) {
                bVar3 = true;
              }
              else {
                if (CurrCommand == ImmCommand) {
                  bVar3 = true;
                }
                else {
                  if (CurrCommand == DAT_803a0dac) {
                    bVar3 = true;
                  }
                  else {
                    if (CurrCommand == DAT_803a0db0) {
                      bVar3 = true;
                    }
                    else {
                      bVar3 = false;
                    }
                  }
                }
              }
              if (bVar3) {
                if ((CurrCommand == 0xb) || (uVar2 = DAT_cc006020, CurrCommand == 10)) {
                  uVar2 = DAT_cc006020 << 2;
                }
                executing = &DummyCommandBlock;
                *(undefined4 *)(puVar1 + 0xc) = 0;
                if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
                  (**(code **)(puVar1 + 0x28))(uVar2);
                }
                stateReady();
              }
              else {
                if (CurrCommand == 6) {
                  if (*(int *)(executing + 0x1c) == 0) {
                    if ((DAT_cc006020 & 1) == 0) {
                      AutoFinishing = 0;
                      *(undefined4 *)(executing + 0x1c) = 1;
                      DVDLowAudioStream(0,*(undefined4 *)(executing + 0x14),
                                        *(undefined4 *)(executing + 0x10),cbForStateBusy);
                    }
                    else {
                      executing = &DummyCommandBlock;
                      *(undefined4 *)(puVar1 + 0xc) = 9;
                      if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
                        (**(code **)(puVar1 + 0x28))(0xfffffffe);
                      }
                      stateReady();
                    }
                  }
                  else {
                    executing = &DummyCommandBlock;
                    *(undefined4 *)(puVar1 + 0xc) = 0;
                    if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
                      (**(code **)(puVar1 + 0x28))(0);
                    }
                    stateReady();
                  }
                }
                else {
                  executing = &DummyCommandBlock;
                  *(undefined4 *)(puVar1 + 0xc) = 0;
                  if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
                    (**(code **)(puVar1 + 0x28))(0);
                  }
                  stateReady();
                }
              }
            }
          }
        }
      }
      else {
        Canceling = 0;
        executing = &DummyCommandBlock;
        *(undefined4 *)(puVar1 + 0xc) = 10;
        if (*(code **)(puVar1 + 0x28) != (code *)0x0) {
          (**(code **)(puVar1 + 0x28))(0xfffffffd,puVar1);
        }
        if (CancelCallback != (code *)0x0) {
          (*CancelCallback)(0,puVar1);
        }
        stateReady();
      }
    }
  }
  return;
}


undefined4
DVDReadAbsAsyncPrio
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(param_1 + 8) = 1;
  *(undefined4 *)(param_1 + 0x18) = param_2;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x10) = param_4;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x28) = param_5;
  if ((autoInvalidation != 0) &&
     (((iVar1 = *(int *)(param_1 + 8), iVar1 == 1 || (iVar1 - 4U < 2)) || (iVar1 == 0xe)))) {
    os::DCInvalidateRange(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x14));
  }
  uVar2 = os::OSDisableInterrupts();
  *(undefined4 *)(param_1 + 0xc) = 2;
  uVar3 = __DVDPushWaitingQueue(param_6,param_1);
  if ((executing == 0) && (PauseFlag == 0)) {
    stateReady();
  }
  os::OSRestoreInterrupts(uVar2);
  return uVar3;
}


undefined4
DVDReadAbsAsyncForBS
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(param_1 + 8) = 4;
  *(undefined4 *)(param_1 + 0x18) = param_2;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  *(undefined4 *)(param_1 + 0x10) = param_4;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x28) = param_5;
  if ((autoInvalidation != 0) &&
     (((iVar1 = *(int *)(param_1 + 8), iVar1 == 1 || (iVar1 - 4U < 2)) || (iVar1 == 0xe)))) {
    os::DCInvalidateRange(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x14));
  }
  uVar2 = os::OSDisableInterrupts();
  *(undefined4 *)(param_1 + 0xc) = 2;
  uVar3 = __DVDPushWaitingQueue(2,param_1);
  if ((executing == 0) && (PauseFlag == 0)) {
    stateReady();
  }
  os::OSRestoreInterrupts(uVar2);
  return uVar3;
}


undefined4 DVDReadDiskID(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(param_1 + 8) = 5;
  *(undefined4 *)(param_1 + 0x18) = param_2;
  *(undefined4 *)(param_1 + 0x14) = 0x20;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x28) = param_3;
  if ((autoInvalidation != 0) &&
     (((iVar1 = *(int *)(param_1 + 8), iVar1 == 1 || (iVar1 - 4U < 2)) || (iVar1 == 0xe)))) {
    os::DCInvalidateRange(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x14));
  }
  uVar2 = os::OSDisableInterrupts();
  *(undefined4 *)(param_1 + 0xc) = 2;
  uVar3 = __DVDPushWaitingQueue(2,param_1);
  if ((executing == 0) && (PauseFlag == 0)) {
    stateReady();
  }
  os::OSRestoreInterrupts(uVar2);
  return uVar3;
}


undefined4
DVDPrepareStreamAbsAsync(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(param_1 + 8) = 6;
  *(undefined4 *)(param_1 + 0x14) = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_3;
  *(undefined4 *)(param_1 + 0x28) = param_4;
  if ((autoInvalidation != 0) &&
     (((iVar1 = *(int *)(param_1 + 8), iVar1 == 1 || (iVar1 - 4U < 2)) || (iVar1 == 0xe)))) {
    os::DCInvalidateRange(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x14));
  }
  uVar2 = os::OSDisableInterrupts();
  *(undefined4 *)(param_1 + 0xc) = 2;
  uVar3 = __DVDPushWaitingQueue(1,param_1);
  if ((executing == 0) && (PauseFlag == 0)) {
    stateReady();
  }
  os::OSRestoreInterrupts(uVar2);
  return uVar3;
}


undefined4 DVDCancelStreamAsync(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(param_1 + 8) = 7;
  *(undefined4 *)(param_1 + 0x28) = param_2;
  if ((autoInvalidation != 0) &&
     (((iVar1 = *(int *)(param_1 + 8), iVar1 == 1 || (iVar1 - 4U < 2)) || (iVar1 == 0xe)))) {
    os::DCInvalidateRange(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x14));
  }
  uVar2 = os::OSDisableInterrupts();
  *(undefined4 *)(param_1 + 0xc) = 2;
  uVar3 = __DVDPushWaitingQueue(1,param_1);
  if ((executing == 0) && (PauseFlag == 0)) {
    stateReady();
  }
  os::OSRestoreInterrupts(uVar2);
  return uVar3;
}


undefined4 DVDStopStreamAtEndAsync(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(param_1 + 8) = 8;
  *(undefined4 *)(param_1 + 0x28) = param_2;
  if ((autoInvalidation != 0) &&
     (((iVar1 = *(int *)(param_1 + 8), iVar1 == 1 || (iVar1 - 4U < 2)) || (iVar1 == 0xe)))) {
    os::DCInvalidateRange(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x14));
  }
  uVar2 = os::OSDisableInterrupts();
  *(undefined4 *)(param_1 + 0xc) = 2;
  uVar3 = __DVDPushWaitingQueue(1,param_1);
  if ((executing == 0) && (PauseFlag == 0)) {
    stateReady();
  }
  os::OSRestoreInterrupts(uVar2);
  return uVar3;
}


undefined4 DVDGetStreamPlayAddrAsync(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(param_1 + 8) = 10;
  *(undefined4 *)(param_1 + 0x28) = param_2;
  if ((autoInvalidation != 0) &&
     (((iVar1 = *(int *)(param_1 + 8), iVar1 == 1 || (iVar1 - 4U < 2)) || (iVar1 == 0xe)))) {
    os::DCInvalidateRange(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x14));
  }
  uVar2 = os::OSDisableInterrupts();
  *(undefined4 *)(param_1 + 0xc) = 2;
  uVar3 = __DVDPushWaitingQueue(1,param_1);
  if ((executing == 0) && (PauseFlag == 0)) {
    stateReady();
  }
  os::OSRestoreInterrupts(uVar2);
  return uVar3;
}


undefined4 DVDInquiryAsync(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *(undefined4 *)(param_1 + 8) = 0xe;
  *(undefined4 *)(param_1 + 0x18) = param_2;
  *(undefined4 *)(param_1 + 0x14) = 0x20;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x28) = param_3;
  if ((autoInvalidation != 0) &&
     (((iVar1 = *(int *)(param_1 + 8), iVar1 == 1 || (iVar1 - 4U < 2)) || (iVar1 == 0xe)))) {
    os::DCInvalidateRange(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x14));
  }
  uVar2 = os::OSDisableInterrupts();
  *(undefined4 *)(param_1 + 0xc) = 2;
  uVar3 = __DVDPushWaitingQueue(2,param_1);
  if ((executing == 0) && (PauseFlag == 0)) {
    stateReady();
  }
  os::OSRestoreInterrupts(uVar2);
  return uVar3;
}


void DVDReset(void)

{
  DVDLowReset();
  ResumeFromHere = 0;
  ResetRequired = 0;
  DAT_cc006000 = 0x2a;
  return;
}


int DVDGetCommandBlockStatus(int param_1)

{
  int iVar1;
  
  os::OSDisableInterrupts();
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 3) {
    iVar1 = 1;
  }
  os::OSRestoreInterrupts();
  return iVar1;
}


int DVDGetDriveStatus(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = os::OSDisableInterrupts();
  puVar1 = executing;
  if (FatalErrorFlag == 0) {
    if (PausingFlag == 0) {
      if (executing == (undefined *)0x0) {
        iVar3 = 0;
      }
      else {
        if (executing == &DummyCommandBlock) {
          iVar3 = 0;
        }
        else {
          os::OSDisableInterrupts();
          iVar3 = *(int *)(puVar1 + 0xc);
          if (iVar3 == 3) {
            iVar3 = 1;
          }
          os::OSRestoreInterrupts();
        }
      }
    }
    else {
      iVar3 = 8;
    }
  }
  else {
    iVar3 = -1;
  }
  os::OSRestoreInterrupts(uVar2);
  return iVar3;
}


undefined4 DVDSetAutoInvalidation(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = autoInvalidation;
  autoInvalidation = param_1;
  return uVar1;
}


undefined4 DVDCancelAsync(int param_1,code *param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  uVar2 = os::OSDisableInterrupts();
  switch(*(undefined4 *)(param_1 + 0xc)) {
  case 1:
    if (Canceling != 0) {
      os::OSRestoreInterrupts(uVar2);
      return 0;
    }
    Canceling = 1;
    if ((*(int *)(param_1 + 8) == 4) || (CancelCallback = param_2, *(int *)(param_1 + 8) == 1)) {
      CancelCallback = param_2;
      DVDLowBreak();
    }
    break;
  case 2:
    __DVDDequeueWaitingQueue(param_1);
    *(undefined4 *)(param_1 + 0xc) = 10;
    if (*(code **)(param_1 + 0x28) != (code *)0x0) {
      (**(code **)(param_1 + 0x28))(0xfffffffd,param_1);
    }
    if (param_2 != (code *)0x0) {
      (*param_2)(0,param_1);
    }
    break;
  case 3:
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == 0xd) {
LAB_803124ec:
      if (param_2 != (code *)0x0) {
        (*param_2)(0,param_1);
      }
    }
    else {
      if (iVar1 < 0xd) {
        if ((iVar1 < 6) && (3 < iVar1)) goto LAB_803124ec;
      }
      else {
        if (iVar1 == 0xf) goto LAB_803124ec;
      }
      if (Canceling != 0) {
        os::OSRestoreInterrupts(uVar2);
        return 0;
      }
      Canceling = 1;
      CancelCallback = param_2;
    }
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  case 0xb:
    pcVar3 = (code *)DVDLowClearCallback();
    if (pcVar3 != cbForStateMotorStopped) {
      os::OSRestoreInterrupts(uVar2);
      return 0;
    }
    if (*(int *)(param_1 + 0xc) == 4) {
      ResumeFromHere = 3;
    }
    if (*(int *)(param_1 + 0xc) == 5) {
      ResumeFromHere = 4;
    }
    if (*(int *)(param_1 + 0xc) == 6) {
      ResumeFromHere = 1;
    }
    if (*(int *)(param_1 + 0xc) == 0xb) {
      ResumeFromHere = 2;
    }
    if (*(int *)(param_1 + 0xc) == 7) {
      ResumeFromHere = 7;
    }
    *(undefined4 *)(param_1 + 0xc) = 10;
    if (*(code **)(param_1 + 0x28) != (code *)0x0) {
      (**(code **)(param_1 + 0x28))(0xfffffffd,param_1);
    }
    if (param_2 != (code *)0x0) {
      (*param_2)(0,param_1);
    }
    stateReady();
    break;
  case 0xffffffff:
  case 0:
  case 10:
    if (param_2 != (code *)0x0) {
      (*param_2)(0,param_1);
    }
  }
  os::OSRestoreInterrupts(uVar2);
  return 1;
}


undefined4 DVDCancel(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DVDCancelAsync(param_1,cbForCancelSync);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = os::OSDisableInterrupts();
    while (((iVar1 = *(int *)(param_1 + 0xc), 1 < iVar1 + 1U && (iVar1 != 10)) &&
           ((iVar1 != 3 ||
            (((iVar1 = *(int *)(param_1 + 8), 1 < iVar1 - 4U && (iVar1 != 0xd)) && (iVar1 != 0xf))))
           ))) {
      os::OSSleepThread(&__DVDThreadQueue);
    }
    os::OSRestoreInterrupts(uVar2);
    uVar2 = 0;
  }
  return uVar2;
}


void cbForCancelSync(void)

{
  os::OSWakeupThread(&__DVDThreadQueue);
  return;
}


undefined4 DVDGetCurrentDiskID(void)

{
  return 0x80000000;
}


undefined4 DVDCheckDisk(void)

{
  undefined4 uVar1;
  undefined4 unaff_r31;
  
  os::OSDisableInterrupts();
  if (FatalErrorFlag == 0) {
    if (PausingFlag == 0) {
      if (executing == (undefined *)0x0) {
        uVar1 = 0;
      }
      else {
        if (executing == &DummyCommandBlock) {
          uVar1 = 0;
        }
        else {
          uVar1 = *(undefined4 *)(executing + 0xc);
        }
      }
    }
    else {
      uVar1 = 8;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  switch(uVar1) {
  case 0:
  case 8:
    if (((DAT_cc006004 >> 2 & 1) == 0) && ((DAT_cc006004 & 1) == 0)) {
      unaff_r31 = 1;
    }
    else {
      unaff_r31 = 0;
    }
    break;
  case 1:
  case 2:
  case 9:
  case 10:
    unaff_r31 = 1;
    break;
  case 0xffffffff:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 0xb:
    unaff_r31 = 0;
  }
  os::OSRestoreInterrupts();
  return unaff_r31;
}


void __DVDPrepareResetAsync(code *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar2 = os::OSDisableInterrupts();
  __DVDClearWaitingQueue();
  pcVar1 = param_1;
  if (Canceling == 0) {
    if (executing != 0) {
      *(undefined4 *)(executing + 0x28) = 0;
    }
    uVar3 = os::OSDisableInterrupts();
    os::OSDisableInterrupts();
    PauseFlag = 1;
    if (executing == 0) {
      PausingFlag = 1;
    }
    os::OSRestoreInterrupts();
    while (iVar4 = __DVDPopWaitingQueue(), iVar4 != 0) {
      DVDCancelAsync(iVar4,0);
    }
    if (executing == 0) {
      if (param_1 != (code *)0x0) {
        (*param_1)(0,0);
      }
    }
    else {
      DVDCancelAsync(executing,param_1);
    }
    uVar5 = os::OSDisableInterrupts();
    PauseFlag = 0;
    if (PausingFlag != 0) {
      PausingFlag = 0;
      stateReady();
    }
    os::OSRestoreInterrupts(uVar5);
    os::OSRestoreInterrupts(uVar3);
    pcVar1 = CancelCallback;
  }
  CancelCallback = pcVar1;
  os::OSRestoreInterrupts(uVar2);
  return;
}

