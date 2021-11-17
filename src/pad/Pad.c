#include <pad/Pad.h>
#include <si/SIBios.h>
#include <pad/Pad.h>
#include <os/OSInterrupt.h>
#include <os/OSRtc.h>
#include <os/OS.h>
#include <os/OSTime.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <si/SISamplingRate.h>
#include <os/OSReset.h>
#include <os/OSContext.h>


namespace pad {
undefined Type;
undefined Origin;
undefined4 CmdProbeDevice;
undefined4 Initialized;
undefined4 EnabledBits;
undefined4 ResettingBits;
undefined4 RecalibrateBits;
undefined4 WaitingBits;
undefined4 CheckingBits;
undefined4 PendingBits;
undefined4 SamplingCallback;
undefined4 recalibrated$397;
undefined4 __PADSpec;

void UpdateOrigin(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = param_1 * 0xc;
  uVar1 = AnalogMode & 0x700;
  if (uVar1 == 0x400) goto LAB_80314ecc;
  if (uVar1 < 0x400) {
    if (uVar1 == 0x200) {
      (&DAT_803f12c4)[iVar2] = (&DAT_803f12c4)[iVar2] & 0xf0;
      (&DAT_803f12c5)[iVar2] = (&DAT_803f12c5)[iVar2] & 0xf0;
      (&DAT_803f12c6)[iVar2] = (&DAT_803f12c6)[iVar2] & 0xf0;
      (&DAT_803f12c7)[iVar2] = (&DAT_803f12c7)[iVar2] & 0xf0;
      goto LAB_80314ecc;
    }
    if (0x1ff < uVar1) goto LAB_80314ecc;
    if (uVar1 == 0x100) {
      (&DAT_803f12c4)[iVar2] = (&DAT_803f12c4)[iVar2] & 0xf0;
      (&DAT_803f12c5)[iVar2] = (&DAT_803f12c5)[iVar2] & 0xf0;
      (&DAT_803f12c8)[iVar2] = (&DAT_803f12c8)[iVar2] & 0xf0;
      (&DAT_803f12c9)[iVar2] = (&DAT_803f12c9)[iVar2] & 0xf0;
      goto LAB_80314ecc;
    }
    if ((0xff < uVar1) || (uVar1 != 0)) goto LAB_80314ecc;
  }
  else {
    if (uVar1 != 0x600) {
      if (uVar1 < 0x600) {
        if (uVar1 != 0x500) goto LAB_80314ecc;
      }
      else {
        if (uVar1 != 0x700) goto LAB_80314ecc;
      }
    }
  }
  (&DAT_803f12c6)[iVar2] = (&DAT_803f12c6)[iVar2] & 0xf0;
  (&DAT_803f12c7)[iVar2] = (&DAT_803f12c7)[iVar2] & 0xf0;
  (&DAT_803f12c8)[iVar2] = (&DAT_803f12c8)[iVar2] & 0xf0;
  (&DAT_803f12c9)[iVar2] = (&DAT_803f12c9)[iVar2] & 0xf0;
LAB_80314ecc:
  (&DAT_803f12c2)[iVar2] = (&DAT_803f12c2)[iVar2] + -0x80;
  (&DAT_803f12c3)[iVar2] = (&DAT_803f12c3)[iVar2] + -0x80;
  (&DAT_803f12c4)[iVar2] = (&DAT_803f12c4)[iVar2] + -0x80;
  (&DAT_803f12c5)[iVar2] = (&DAT_803f12c5)[iVar2] + -0x80;
  if ((((XPatchBits & 0x80000000U >> param_1) != 0) && ('@' < (char)(&DAT_803f12c2)[iVar2])) &&
     (uVar1 = si::SIGetType(), (uVar1 & 0xffff0000) == 0x9000000)) {
    (&DAT_803f12c2)[iVar2] = 0;
  }
  return;
}


void PADOriginCallback(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined auStack20 [16];
  
  if ((param_2 & 0xf) == 0) {
    UpdateOrigin(ResettingChan);
    iVar1 = ResettingChan;
    EnabledBits = EnabledBits | 0x80000000U >> ResettingChan;
    si::SIGetResponse(ResettingChan,auStack20);
    si::SISetCommand(iVar1,AnalogMode | 0x400000);
    si::SIEnablePolling(EnabledBits);
  }
  ResettingChan = countLeadingZeros(ResettingBits);
  if (ResettingChan != 0x20) {
    ResettingBits = ResettingBits & ~(0x80000000U >> ResettingChan);
    FUN_800033a8((int)(&Origin + ResettingChan * 0xc),0,0xc);
    si::SIGetTypeAsync(ResettingChan,PADTypeAndStatusCallback);
  }
  return;
}


void PADOriginUpdateCallback(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0x80000000 >> param_1;
  if ((EnabledBits & uVar2) != 0) {
    if ((param_2 & 0xf) == 0) {
      UpdateOrigin(param_1);
    }
    if ((param_2 & 8) != 0) {
      uVar1 = os::OSDisableInterrupts();
      si::SIDisablePolling(uVar2);
      uVar2 = ~uVar2;
      EnabledBits = EnabledBits & uVar2;
      WaitingBits = WaitingBits & uVar2;
      CheckingBits = CheckingBits & uVar2;
      PendingBits = PendingBits & uVar2;
      os::OSSetWirelessID(param_1,0);
      os::OSRestoreInterrupts(uVar1);
    }
  }
  return;
}


void PADProbeCallback(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined auStack20 [12];
  
  iVar1 = ResettingChan;
  if ((param_2 & 0xf) == 0) {
    EnabledBits = EnabledBits | 0x80000000U >> ResettingChan;
    si::SIGetResponse(ResettingChan,auStack20);
    si::SISetCommand(iVar1,AnalogMode | 0x400000);
    si::SIEnablePolling(EnabledBits);
    WaitingBits = WaitingBits | 0x80000000U >> ResettingChan;
  }
  ResettingChan = countLeadingZeros(ResettingBits);
  if (ResettingChan != 0x20) {
    ResettingBits = ResettingBits & ~(0x80000000U >> ResettingChan);
    FUN_800033a8((int)(&Origin + ResettingChan * 0xc),0,0xc);
    si::SIGetTypeAsync(ResettingChan,PADTypeAndStatusCallback);
  }
  return;
}


void PADTypeAndStatusCallback(undefined4 param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined auStack36 [20];
  
  iVar1 = ResettingChan;
  uVar5 = 0x80000000 >> ResettingChan;
  uVar2 = RecalibrateBits & ~uVar5;
  uVar4 = RecalibrateBits & uVar5;
  iVar3 = 1;
  RecalibrateBits = uVar2;
  if ((param_2 & 0xf) != 0) {
    ResettingChan = countLeadingZeros(ResettingBits);
    if (ResettingChan == 0x20) {
      return;
    }
    ResettingBits = ResettingBits & ~(0x80000000U >> ResettingChan);
    FUN_800033a8((int)(&Origin + ResettingChan * 0xc),0,0xc);
    si::SIGetTypeAsync(ResettingChan,PADTypeAndStatusCallback);
    return;
  }
  *(uint *)(&Type + ResettingChan * 4) = param_2 & 0xffffff00;
  if (((param_2 & 0x18000000) != 0x8000000) || ((param_2 & 0x1000000) == 0)) {
    ResettingChan = countLeadingZeros(ResettingBits);
    if (ResettingChan == 0x20) {
      return;
    }
    ResettingBits = ResettingBits & ~(0x80000000U >> ResettingChan);
    FUN_800033a8((int)(&Origin + ResettingChan * 0xc),0,0xc);
    si::SIGetTypeAsync(ResettingChan,PADTypeAndStatusCallback);
    return;
  }
  if (1 < Spec) {
    if (((param_2 & 0x80000000) == 0) || ((param_2 & 0x4000000) != 0)) {
      if (uVar4 == 0) {
        iVar3 = si::SITransfer(iVar1,&CmdReadOrigin,1,&Origin + iVar1 * 0xc,10,PADOriginCallback,0,0
                              );
      }
      else {
        iVar3 = si::SITransfer(iVar1,&CmdCalibrate,3,&Origin + iVar1 * 0xc,10,PADOriginCallback,0,0)
        ;
      }
    }
    else {
      if ((((param_2 & 0x100000) != 0) && ((param_2 & 0x80000) == 0)) && ((param_2 & 0x40000) == 0))
      {
        if ((param_2 & 0x40000000) == 0) {
          iVar3 = si::SITransfer(iVar1,&CmdProbeDevice + iVar1,3,&Origin + iVar1 * 0xc,8,
                                 PADProbeCallback,0,0);
        }
        else {
          iVar3 = si::SITransfer(iVar1,&CmdReadOrigin,1,&Origin + iVar1 * 0xc,10,PADOriginCallback,0
                                 ,0);
        }
      }
    }
    if (iVar3 == 0) {
      ResettingChan = countLeadingZeros(ResettingBits);
      PendingBits = PendingBits | uVar5;
      if (ResettingChan != 0x20) {
        ResettingBits = ResettingBits & ~(0x80000000U >> ResettingChan);
        FUN_800033a8((int)(&Origin + ResettingChan * 0xc),0,0xc);
        si::SIGetTypeAsync(ResettingChan,PADTypeAndStatusCallback);
      }
    }
    return;
  }
  EnabledBits = EnabledBits | uVar5;
  si::SIGetResponse(iVar1,auStack36);
  si::SISetCommand(iVar1,AnalogMode | 0x400000);
  si::SIEnablePolling(EnabledBits);
  ResettingChan = countLeadingZeros(ResettingBits);
  if (ResettingChan == 0x20) {
    return;
  }
  ResettingBits = ResettingBits & ~(0x80000000U >> ResettingChan);
  FUN_800033a8((int)(&Origin + ResettingChan * 0xc),0,0xc);
  si::SIGetTypeAsync(ResettingChan,PADTypeAndStatusCallback);
  return;
}


void PADReceiveCheckCallback(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0x80000000 >> param_1;
  if ((EnabledBits & uVar2) != 0) {
    WaitingBits = WaitingBits & ~uVar2;
    CheckingBits = CheckingBits & ~uVar2;
    if (((((param_2 & 0xf) == 0) && ((param_2 & 0x80000000) != 0)) && ((param_2 & 0x100000) != 0))
       && ((((param_2 & 0x40000000) != 0 && ((param_2 & 0x4000000) == 0)) &&
           (((param_2 & 0x80000) == 0 && ((param_2 & 0x40000) == 0)))))) {
      si::SITransfer(param_1,&CmdReadOrigin,1,&Origin + param_1 * 0xc,10,PADOriginUpdateCallback,0,0
                    );
      return;
    }
    uVar1 = os::OSDisableInterrupts();
    si::SIDisablePolling(uVar2);
    uVar2 = ~uVar2;
    EnabledBits = EnabledBits & uVar2;
    WaitingBits = WaitingBits & uVar2;
    CheckingBits = CheckingBits & uVar2;
    PendingBits = PendingBits & uVar2;
    os::OSSetWirelessID(param_1,0);
    os::OSRestoreInterrupts(uVar1);
  }
  return;
}


undefined4 PADReset(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = os::OSDisableInterrupts();
  uVar3 = (param_1 | PendingBits) & ~(WaitingBits | CheckingBits);
  ResettingBits = ResettingBits | uVar3;
  PendingBits = 0;
  uVar2 = ResettingBits & EnabledBits;
  if (Spec == 4) {
    RecalibrateBits = RecalibrateBits | uVar3;
  }
  EnabledBits = EnabledBits & ~uVar3;
  si::SIDisablePolling(uVar2);
  if (ResettingChan == 0x20) {
    ResettingChan = countLeadingZeros(ResettingBits);
    if (ResettingChan != 0x20) {
      ResettingBits = ResettingBits & ~(0x80000000U >> ResettingChan);
      FUN_800033a8((int)(&Origin + ResettingChan * 0xc),0,0xc);
      si::SIGetTypeAsync(ResettingChan,PADTypeAndStatusCallback);
    }
  }
  os::OSRestoreInterrupts(uVar1);
  return 1;
}


undefined4 PADRecalibrate(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = os::OSDisableInterrupts();
  uVar3 = (param_1 | PendingBits) & ~(WaitingBits | CheckingBits);
  ResettingBits = ResettingBits | uVar3;
  PendingBits = 0;
  uVar2 = ResettingBits & EnabledBits;
  if ((DAT_800030e3 & 0x40) == 0) {
    RecalibrateBits = RecalibrateBits | uVar3;
  }
  EnabledBits = EnabledBits & ~uVar3;
  si::SIDisablePolling(uVar2);
  if (ResettingChan == 0x20) {
    ResettingChan = countLeadingZeros(ResettingBits);
    if (ResettingChan != 0x20) {
      ResettingBits = ResettingBits & ~(0x80000000U >> ResettingChan);
      FUN_800033a8((int)(&Origin + ResettingChan * 0xc),0,0xc);
      si::SIGetTypeAsync(ResettingChan,PADTypeAndStatusCallback);
    }
  }
  os::OSRestoreInterrupts(uVar1);
  return 1;
}


undefined4 PADInit(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  short extraout_r4_01;
  short extraout_r4_02;
  short extraout_r4_03;
  uint uVar4;
  
  if (Initialized == 0) {
    os::OSRegisterVersion(__PADVersion);
    uVar2 = extraout_r4;
    if (__PADSpec != 0) {
      PADSetSpec();
      uVar2 = extraout_r4_00;
    }
    Initialized = 1;
    if (si::__PADFixBits != 0) {
      iVar1 = os::OSGetTime();
      Runtime.PPCEABI.H::__shr2i();
      Runtime.PPCEABI.H::__shr2i(iVar1,uVar2,0x20);
      Runtime.PPCEABI.H::__shr2i(iVar1,uVar2,0x30);
      RecalibrateBits = 0xf0000000;
      DAT_800030e0 = extraout_r4_03 + extraout_r4_02 + (short)uVar2 + extraout_r4_01 & 0x3fff;
    }
    CmdProbeDevice = (DAT_800030e0 & 0x3fff) << 8 | 0x4d000000;
    DAT_803f12f4 = (DAT_800030e0 & 0x3fff) << 8 | 0x4d400000;
    DAT_803f12f8 = (DAT_800030e0 & 0x3fff) << 8 | 0x4d800000;
    DAT_803f12fc = (DAT_800030e0 & 0x3fff) << 8 | 0x4dc00000;
    si::SIRefreshSamplingRate();
    os::OSRegisterResetFunction(&ResetFunctionInfo);
    uVar2 = os::OSDisableInterrupts();
    uVar4 = (PendingBits | 0xf0000000) & ~(WaitingBits | CheckingBits);
    ResettingBits = ResettingBits | uVar4;
    PendingBits = 0;
    uVar3 = ResettingBits & EnabledBits;
    if (Spec == 4) {
      RecalibrateBits = RecalibrateBits | uVar4;
    }
    EnabledBits = EnabledBits & ~uVar4;
    si::SIDisablePolling(uVar3);
    if ((ResettingChan == 0x20) &&
       (ResettingChan = countLeadingZeros(ResettingBits), ResettingChan != 0x20)) {
      ResettingBits = ResettingBits & ~(0x80000000U >> ResettingChan);
      FUN_800033a8((int)(&Origin + ResettingChan * 0xc),0,0xc);
      si::SIGetTypeAsync(ResettingChan,PADTypeAndStatusCallback);
    }
    os::OSRestoreInterrupts(uVar2);
  }
  return 1;
}


uint PADRead(ushort *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined *puVar8;
  uint local_3c [3];
  
  uVar1 = os::OSDisableInterrupts();
  iVar6 = 0;
  puVar8 = &Origin;
  uVar5 = 0;
  do {
    uVar7 = 0x80000000 >> iVar6;
    if ((PendingBits & uVar7) == 0) {
      if ((ResettingBits & uVar7) == 0) {
        if (ResettingChan != iVar6) {
          if ((EnabledBits & uVar7) == 0) {
            *(undefined *)(param_1 + 5) = 0xff;
            FUN_800033a8((int)param_1,0,10);
          }
          else {
            iVar3 = si::SIIsChanBusy(iVar6);
            if (iVar3 == 0) {
              uVar4 = si::SIGetStatus(iVar6);
              if ((uVar4 & 8) == 0) {
                uVar4 = si::SIGetType(iVar6);
                if ((uVar4 & 0x20000000) == 0) {
                  uVar5 = uVar5 | uVar7;
                }
                iVar3 = si::SIGetResponse(iVar6,local_3c);
                if (iVar3 == 0) {
                  *(undefined *)(param_1 + 5) = 0xfd;
                  FUN_800033a8((int)param_1,0,10);
                }
                else {
                  if ((local_3c[0] & 0x80000000) == 0) {
                    (*MakeStatus)(iVar6,param_1,local_3c);
                    if ((*param_1 & 0x2000) == 0) {
                      *(undefined *)(param_1 + 5) = 0;
                      *param_1 = *param_1 & 0xff7f;
                    }
                    else {
                      *(undefined *)(param_1 + 5) = 0xfd;
                      FUN_800033a8((int)param_1,0,10);
                      si::SITransfer(iVar6,&CmdReadOrigin,1,puVar8,10,PADOriginUpdateCallback,0,0);
                    }
                  }
                  else {
                    *(undefined *)(param_1 + 5) = 0xfd;
                    FUN_800033a8((int)param_1,0,10);
                  }
                }
              }
              else {
                si::SIGetResponse(iVar6,local_3c);
                if ((WaitingBits & uVar7) == 0) {
                  uVar2 = os::OSDisableInterrupts();
                  si::SIDisablePolling(uVar7);
                  uVar7 = ~uVar7;
                  EnabledBits = EnabledBits & uVar7;
                  WaitingBits = WaitingBits & uVar7;
                  CheckingBits = CheckingBits & uVar7;
                  PendingBits = PendingBits & uVar7;
                  os::OSSetWirelessID(iVar6,0);
                  os::OSRestoreInterrupts(uVar2);
                  *(undefined *)(param_1 + 5) = 0xff;
                  FUN_800033a8((int)param_1,0,10);
                }
                else {
                  *(undefined *)(param_1 + 5) = 0;
                  FUN_800033a8((int)param_1,0,10);
                  if ((CheckingBits & uVar7) == 0) {
                    CheckingBits = CheckingBits | uVar7;
                    si::SIGetTypeAsync(iVar6,PADReceiveCheckCallback);
                  }
                }
              }
            }
            else {
              *(undefined *)(param_1 + 5) = 0xfd;
              FUN_800033a8((int)param_1,0,10);
            }
          }
          goto LAB_80315d98;
        }
      }
      *(undefined *)(param_1 + 5) = 0xfe;
      FUN_800033a8((int)param_1,0,10);
    }
    else {
      uVar2 = os::OSDisableInterrupts();
      uVar4 = PendingBits & ~(WaitingBits | CheckingBits);
      ResettingBits = ResettingBits | uVar4;
      PendingBits = 0;
      uVar7 = ResettingBits & EnabledBits;
      if (Spec == 4) {
        RecalibrateBits = RecalibrateBits | uVar4;
      }
      EnabledBits = EnabledBits & ~uVar4;
      si::SIDisablePolling(uVar7);
      if (ResettingChan == 0x20) {
        ResettingChan = countLeadingZeros(ResettingBits);
        if (ResettingChan != 0x20) {
          ResettingBits = ResettingBits & ~(0x80000000U >> ResettingChan);
          FUN_800033a8((int)(&Origin + ResettingChan * 0xc),0,0xc);
          si::SIGetTypeAsync(ResettingChan,PADTypeAndStatusCallback);
        }
      }
      os::OSRestoreInterrupts(uVar2);
      *(undefined *)(param_1 + 5) = 0xfe;
      FUN_800033a8((int)param_1,0,10);
    }
LAB_80315d98:
    iVar6 = iVar6 + 1;
    puVar8 = puVar8 + 0xc;
    param_1 = param_1 + 6;
    if (3 < iVar6) {
      os::OSRestoreInterrupts(uVar1);
      return uVar5;
    }
  } while( true );
}


void PADControlMotor(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = os::OSDisableInterrupts();
  if (((EnabledBits & 0x80000000U >> param_1) != 0) &&
     (uVar2 = si::SIGetType(param_1), (uVar2 & 0x20000000) == 0)) {
    if ((Spec < 2) && (param_2 == 2)) {
      param_2 = 0;
    }
    si::SISetCommand(param_1,AnalogMode | 0x400000 | param_2 & 3);
    si::SITransferCommands();
  }
  os::OSRestoreInterrupts(uVar1);
  return;
}


void PADSetSpec(int param_1)

{
  if (param_1 == 1) {
    MakeStatus = SPEC1_MakeStatus;
  }
  else {
    if (param_1 < 1) {
      if (-1 < param_1) {
        MakeStatus = SPEC0_MakeStatus;
      }
    }
    else {
      if (param_1 < 6) {
        MakeStatus = SPEC2_MakeStatus;
      }
    }
  }
  Spec = param_1;
  __PADSpec = 0;
  return;
}


void SPEC0_MakeStatus(undefined4 param_1,ushort *param_2,uint *param_3)

{
  ushort uVar1;
  
  uVar1 = 0;
  *param_2 = 0;
  if ((*param_3 >> 0x10 & 8) != 0) {
    uVar1 = 0x100;
  }
  *param_2 = *param_2 | uVar1;
  if ((*param_3 >> 0x10 & 0x20) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x200;
  }
  *param_2 = *param_2 | uVar1;
  if ((*param_3 >> 0x10 & 0x100) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x400;
  }
  *param_2 = *param_2 | uVar1;
  if ((*param_3 >> 0x10 & 1) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x800;
  }
  *param_2 = *param_2 | uVar1;
  if ((*param_3 >> 0x10 & 0x10) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x1000;
  }
  *param_2 = *param_2 | uVar1;
  *(char *)(param_2 + 1) = (char)(param_3[1] >> 0x10);
  *(char *)((int)param_2 + 3) = (char)(param_3[1] >> 0x18);
  *(char *)(param_2 + 2) = (char)param_3[1];
  *(char *)((int)param_2 + 5) = (char)(param_3[1] >> 8);
  *(char *)(param_2 + 3) = (char)(*param_3 >> 8);
  *(char *)((int)param_2 + 7) = (char)*param_3;
  *(undefined *)(param_2 + 4) = 0;
  *(undefined *)((int)param_2 + 9) = 0;
  if (0xa9 < *(byte *)(param_2 + 3)) {
    *param_2 = *param_2 | 0x40;
  }
  if (0xa9 < *(byte *)((int)param_2 + 7)) {
    *param_2 = *param_2 | 0x20;
  }
  *(char *)(param_2 + 1) = *(char *)(param_2 + 1) + -0x80;
  *(char *)((int)param_2 + 3) = *(char *)((int)param_2 + 3) + -0x80;
  *(char *)(param_2 + 2) = *(char *)(param_2 + 2) + -0x80;
  *(char *)((int)param_2 + 5) = *(char *)((int)param_2 + 5) + -0x80;
  return;
}


void SPEC1_MakeStatus(undefined4 param_1,ushort *param_2,uint *param_3)

{
  ushort uVar1;
  
  uVar1 = 0;
  *param_2 = 0;
  if ((*param_3 >> 0x10 & 0x80) != 0) {
    uVar1 = 0x100;
  }
  *param_2 = *param_2 | uVar1;
  if ((*param_3 >> 0x10 & 0x100) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x200;
  }
  *param_2 = *param_2 | uVar1;
  if ((*param_3 >> 0x10 & 0x20) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x400;
  }
  *param_2 = *param_2 | uVar1;
  if ((*param_3 >> 0x10 & 0x10) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x800;
  }
  *param_2 = *param_2 | uVar1;
  if ((*param_3 >> 0x10 & 0x200) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x1000;
  }
  *param_2 = *param_2 | uVar1;
  *(char *)(param_2 + 1) = (char)(param_3[1] >> 0x10);
  *(char *)((int)param_2 + 3) = (char)(param_3[1] >> 0x18);
  *(char *)(param_2 + 2) = (char)param_3[1];
  *(char *)((int)param_2 + 5) = (char)(param_3[1] >> 8);
  *(char *)(param_2 + 3) = (char)(*param_3 >> 8);
  *(char *)((int)param_2 + 7) = (char)*param_3;
  *(undefined *)(param_2 + 4) = 0;
  *(undefined *)((int)param_2 + 9) = 0;
  if (0xa9 < *(byte *)(param_2 + 3)) {
    *param_2 = *param_2 | 0x40;
  }
  if (0xa9 < *(byte *)((int)param_2 + 7)) {
    *param_2 = *param_2 | 0x20;
  }
  *(char *)(param_2 + 1) = *(char *)(param_2 + 1) + -0x80;
  *(char *)((int)param_2 + 3) = *(char *)((int)param_2 + 3) + -0x80;
  *(char *)(param_2 + 2) = *(char *)(param_2 + 2) + -0x80;
  *(char *)((int)param_2 + 5) = *(char *)((int)param_2 + 5) + -0x80;
  return;
}


void SPEC2_MakeStatus(int param_1,ushort *param_2,undefined4 *param_3)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  char cVar5;
  
  *param_2 = (ushort)((uint)*param_3 >> 0x10) & 0x3fff;
  *(char *)(param_2 + 1) = (char)((uint)*param_3 >> 8);
  *(char *)((int)param_2 + 3) = (char)*param_3;
  uVar3 = AnalogMode & 0x700;
  if (uVar3 == 0x400) {
    *(char *)(param_2 + 2) = (char)((uint)param_3[1] >> 0x18);
    *(char *)((int)param_2 + 5) = (char)((uint)param_3[1] >> 0x10);
    *(undefined *)(param_2 + 3) = 0;
    *(undefined *)((int)param_2 + 7) = 0;
    *(char *)(param_2 + 4) = (char)((uint)param_3[1] >> 8);
    *(char *)((int)param_2 + 9) = (char)param_3[1];
    goto LAB_803163c4;
  }
  if (uVar3 < 0x400) {
    if (uVar3 == 0x200) {
      *(byte *)(param_2 + 2) = (byte)((uint)param_3[1] >> 0x18) & 0xf0;
      *(byte *)((int)param_2 + 5) = (byte)((uint)param_3[1] >> 0x14) & 0xf0;
      *(byte *)(param_2 + 3) = (byte)((uint)param_3[1] >> 0x10) & 0xf0;
      *(byte *)((int)param_2 + 7) = (byte)((uint)param_3[1] >> 0xc) & 0xf0;
      *(char *)(param_2 + 4) = (char)((uint)param_3[1] >> 8);
      *(char *)((int)param_2 + 9) = (char)param_3[1];
      goto LAB_803163c4;
    }
    if (0x1ff < uVar3) {
      if (uVar3 == 0x300) {
        *(char *)(param_2 + 2) = (char)((uint)param_3[1] >> 0x18);
        *(char *)((int)param_2 + 5) = (char)((uint)param_3[1] >> 0x10);
        *(char *)(param_2 + 3) = (char)((uint)param_3[1] >> 8);
        *(char *)((int)param_2 + 7) = (char)param_3[1];
        *(undefined *)(param_2 + 4) = 0;
        *(undefined *)((int)param_2 + 9) = 0;
      }
      goto LAB_803163c4;
    }
    if (uVar3 == 0x100) {
      *(byte *)(param_2 + 2) = (byte)((uint)param_3[1] >> 0x18) & 0xf0;
      *(byte *)((int)param_2 + 5) = (byte)((uint)param_3[1] >> 0x14) & 0xf0;
      *(char *)(param_2 + 3) = (char)((uint)param_3[1] >> 0x10);
      *(char *)((int)param_2 + 7) = (char)((uint)param_3[1] >> 8);
      *(byte *)(param_2 + 4) = (byte)param_3[1] & 0xf0;
      *(char *)((int)param_2 + 9) = (char)(param_3[1] << 4);
      goto LAB_803163c4;
    }
    if ((0xff < uVar3) || (uVar3 != 0)) goto LAB_803163c4;
  }
  else {
    if (uVar3 != 0x600) {
      if (uVar3 < 0x600) {
        if (uVar3 != 0x500) goto LAB_803163c4;
      }
      else {
        if (uVar3 != 0x700) goto LAB_803163c4;
      }
    }
  }
  *(char *)(param_2 + 2) = (char)((uint)param_3[1] >> 0x18);
  *(char *)((int)param_2 + 5) = (char)((uint)param_3[1] >> 0x10);
  *(byte *)(param_2 + 3) = (byte)((uint)param_3[1] >> 8) & 0xf0;
  *(byte *)((int)param_2 + 7) = (byte)((uint)param_3[1] >> 4) & 0xf0;
  *(byte *)(param_2 + 4) = (byte)param_3[1] & 0xf0;
  *(char *)((int)param_2 + 9) = (char)(param_3[1] << 4);
LAB_803163c4:
  param_1 = param_1 * 0xc;
  *(char *)(param_2 + 1) = *(char *)(param_2 + 1) + -0x80;
  *(char *)((int)param_2 + 3) = *(char *)((int)param_2 + 3) + -0x80;
  *(char *)(param_2 + 2) = *(char *)(param_2 + 2) + -0x80;
  *(char *)((int)param_2 + 5) = *(char *)((int)param_2 + 5) + -0x80;
  cVar1 = (&DAT_803f12c2)[param_1];
  cVar5 = *(char *)(param_2 + 1);
  if (cVar1 < '\x01') {
    if ((cVar1 < '\0') && ((char)(cVar1 + '\x7f') < cVar5)) {
      cVar5 = cVar1 + '\x7f';
    }
  }
  else {
    if (cVar5 < (char)(cVar1 + -0x80)) {
      cVar5 = cVar1 + -0x80;
    }
  }
  *(char *)(param_2 + 1) = cVar5 - cVar1;
  cVar1 = (&DAT_803f12c3)[param_1];
  cVar5 = *(char *)((int)param_2 + 3);
  if (cVar1 < '\x01') {
    if ((cVar1 < '\0') && ((char)(cVar1 + '\x7f') < cVar5)) {
      cVar5 = cVar1 + '\x7f';
    }
  }
  else {
    if (cVar5 < (char)(cVar1 + -0x80)) {
      cVar5 = cVar1 + -0x80;
    }
  }
  *(char *)((int)param_2 + 3) = cVar5 - cVar1;
  cVar1 = (&DAT_803f12c4)[param_1];
  cVar5 = *(char *)(param_2 + 2);
  if (cVar1 < '\x01') {
    if ((cVar1 < '\0') && ((char)(cVar1 + '\x7f') < cVar5)) {
      cVar5 = cVar1 + '\x7f';
    }
  }
  else {
    if (cVar5 < (char)(cVar1 + -0x80)) {
      cVar5 = cVar1 + -0x80;
    }
  }
  *(char *)(param_2 + 2) = cVar5 - cVar1;
  cVar1 = (&DAT_803f12c5)[param_1];
  cVar5 = *(char *)((int)param_2 + 5);
  if (cVar1 < '\x01') {
    if ((cVar1 < '\0') && ((char)(cVar1 + '\x7f') < cVar5)) {
      cVar5 = cVar1 + '\x7f';
    }
  }
  else {
    if (cVar5 < (char)(cVar1 + -0x80)) {
      cVar5 = cVar1 + -0x80;
    }
  }
  *(char *)((int)param_2 + 5) = cVar5 - cVar1;
  bVar2 = (&DAT_803f12c6)[param_1];
  bVar4 = *(byte *)(param_2 + 3);
  if (*(byte *)(param_2 + 3) < bVar2) {
    bVar4 = bVar2;
  }
  *(byte *)(param_2 + 3) = bVar4 - bVar2;
  bVar2 = (&DAT_803f12c7)[param_1];
  bVar4 = *(byte *)((int)param_2 + 7);
  if (*(byte *)((int)param_2 + 7) < bVar2) {
    bVar4 = bVar2;
  }
  *(byte *)((int)param_2 + 7) = bVar4 - bVar2;
  return;
}


void PADSetAnalogMode(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = os::OSDisableInterrupts();
  uVar1 = EnabledBits;
  AnalogMode = param_1 << 8;
  WaitingBits = WaitingBits & ~EnabledBits;
  CheckingBits = CheckingBits & ~EnabledBits;
  EnabledBits = 0;
  si::SIDisablePolling(uVar1);
  os::OSRestoreInterrupts(uVar2);
  return;
}


int OnReset(int param_1)

{
  bool bVar4;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar5;
  uint uVar6;
  
  if (SamplingCallback != 0) {
    PADSetSamplingCallback(0);
  }
  if (param_1 == 0) {
    iVar5 = 0;
    bVar4 = false;
    if ((ResettingBits == 0) && (ResettingChan == 0x20)) {
      bVar4 = true;
    }
    if ((bVar4) && (iVar1 = si::SIBusy(), iVar1 == 0)) {
      iVar5 = 1;
    }
    if ((recalibrated_397 == 0) && (iVar5 != 0)) {
      uVar2 = os::OSDisableInterrupts();
      uVar6 = (PendingBits | 0xf0000000) & ~(WaitingBits | CheckingBits);
      ResettingBits = ResettingBits | uVar6;
      PendingBits = 0;
      uVar3 = ResettingBits & EnabledBits;
      if ((DAT_800030e3 & 0x40) == 0) {
        RecalibrateBits = RecalibrateBits | uVar6;
      }
      EnabledBits = EnabledBits & ~uVar6;
      si::SIDisablePolling(uVar3);
      if ((ResettingChan == 0x20) &&
         (ResettingChan = countLeadingZeros(ResettingBits), ResettingChan != 0x20)) {
        ResettingBits = ResettingBits & ~(0x80000000U >> ResettingChan);
        FUN_800033a8((int)(&Origin + ResettingChan * 0xc),0,0xc);
        si::SIGetTypeAsync(ResettingChan,PADTypeAndStatusCallback);
      }
      os::OSRestoreInterrupts(uVar2);
      recalibrated_397 = 1;
      iVar5 = 0;
    }
  }
  else {
    recalibrated_397 = 0;
    iVar5 = 1;
  }
  return iVar5;
}


void SamplingHandler(undefined4 param_1,undefined4 param_2)

{
  undefined auStack720 [716];
  
  if (SamplingCallback != (code *)0x0) {
    os::OSClearContext(auStack720);
    os::OSSetCurrentContext(auStack720);
    (*SamplingCallback)();
    os::OSClearContext(auStack720);
    os::OSSetCurrentContext(param_2);
  }
  return;
}


undefined4 PADSetSamplingCallback(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = SamplingCallback;
  SamplingCallback = param_1;
  if (param_1 == 0) {
    si::SIUnregisterPollingHandler(SamplingHandler);
  }
  else {
    si::SIRegisterPollingHandler(SamplingHandler);
  }
  return uVar1;
}


bool __PADDisableRecalibration(int param_1)

{
  byte bVar1;
  
  os::OSDisableInterrupts();
  bVar1 = DAT_800030e3 & 0x40;
  DAT_800030e3 = DAT_800030e3 & 0xbf;
  if (param_1 != 0) {
    DAT_800030e3 = DAT_800030e3 | 0x40;
  }
  os::OSRestoreInterrupts();
  return bVar1 != 0;
}

