#include <TRK_MINNOW_DOLPHIN/targimpl.h>
#include <TRK_MINNOW_DOLPHIN/dolphin_trk_glue.h>
#include <TRK_MINNOW_DOLPHIN/targimpl.h>
#include <TRK_MINNOW_DOLPHIN/mpc_7xx_603e.h>
#include <TRK_MINNOW_DOLPHIN/flush_cache.h>
#include <TRK_MINNOW_DOLPHIN/nubevent.h>
#include <TRK_MINNOW_DOLPHIN/support.h>
#include <TRK_MINNOW_DOLPHIN/msgbuf.h>
#include <TRK_MINNOW_DOLPHIN/notify.h>
#include <TRK_MINNOW_DOLPHIN/dolphin_trk.h>


namespace TRK_MINNOW_DOLPHIN {
undefined2 TRK_saved_exceptionID;
undefined4 gTRKState;
undefined4 gTRKCPUState;
undefined gTRKSaveState;
undefined TRKvalue128_temp;

void __TRK_get_MSR(void)

{
  return;
}


void __TRK_set_MSR(void)

{
  return;
}


void TRK_ppc_memcpy(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 != param_3; iVar1 = iVar1 + 1) {
    sync(0);
    sync(0);
    *(undefined *)(iVar1 + param_1) = *(undefined *)(iVar1 + param_2);
  }
  sync(0);
  return;
}


undefined4
TRKInterruptHandler
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 in_r0;
  uint uVar1;
  undefined4 extraout_r4;
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
  uint in_MSR;
  uint uVar2;
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
  undefined4 uVar3;
  undefined4 in_SPRG1;
  undefined4 in_SPRG2;
  undefined4 in_SPRG3;
  
  uVar3 = 0x803ffd00;
  uVar1 = (uint)(in_cr0 & 0xf) << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 | (uint)(in_cr2 & 0xf) << 0x14
          | (uint)(in_cr3 & 0xf) << 0x10 | (uint)(unaff_cr4 & 0xf) << 0xc |
          (uint)(in_cr5 & 0xf) << 8 | (uint)(in_cr6 & 0xf) << 4 | (uint)(in_cr7 & 0xf);
  sync(0);
  uVar2 = in_MSR & 0x9000;
  sync(0);
  TRK_saved_exceptionID = (undefined2)param_1;
  if (param_1 == 0x500) {
    DAT_803f3ddc = in_LR;
    TRKUARTInterruptHandler();
    if ((*DAT_803f39ac == '\0') || (DAT_803a28d8._0_1_ == '\x01')) {
      returnFromInterrupt(uVar2,param_2);
      return DAT_803f3dec;
    }
    DAT_803f39a8._0_1_ = 1;
    in_SPRG3 = extraout_r4;
    in_LR = DAT_803f3ddc;
  }
  if (DAT_803a28d8._0_1_ != '\0') {
    returnFromInterrupt(uVar2,param_2);
    gTRKExceptionStatus = uVar3;
    DAT_803a28d4._0_2_ = TRK_saved_exceptionID;
    DAT_803a28d8._1_1_ = 1;
    return in_SPRG2;
  }
  DAT_803f3ca8._0_2_ = TRK_saved_exceptionID;
  DAT_803f3ca8._2_2_ = TRK_saved_exceptionID;
  DAT_803f39e4 = 0x803fe0e0;
  gTRKCPUState = in_r0;
  DAT_803f39b4 = (undefined *)register0x00000004;
  DAT_803f39b8 = in_SPRG1;
  DAT_803f39bc = in_SPRG2;
  DAT_803f39c0 = in_SPRG3;
  DAT_803f39c4 = param_3;
  DAT_803f39c8 = param_4;
  DAT_803f39cc = param_5;
  DAT_803f39d0 = param_6;
  DAT_803f39d4 = param_7;
  DAT_803f39d8 = param_8;
  DAT_803f39dc = in_r11;
  DAT_803f39e0 = in_r12;
  DAT_803f39e8 = unaff_r14;
  DAT_803f39ec = unaff_r15;
  DAT_803f39f0 = unaff_r16;
  DAT_803f39f4 = unaff_r17;
  DAT_803f39f8 = unaff_r18;
  DAT_803f39fc = unaff_r19;
  DAT_803f3a00 = unaff_r20;
  DAT_803f3a04 = unaff_r21;
  DAT_803f3a08 = unaff_r22;
  DAT_803f3a0c = unaff_r23;
  DAT_803f3a10 = unaff_r24;
  DAT_803f3a14 = unaff_r25;
  DAT_803f3a18 = unaff_r26;
  DAT_803f3a1c = unaff_r27;
  DAT_803f3a20 = unaff_r28;
  DAT_803f3a24 = unaff_r29;
  DAT_803f3a28 = unaff_r30;
  DAT_803f3a2c = unaff_r31;
  DAT_803f3a30 = uVar3;
  DAT_803f3a34 = in_LR;
  DAT_803f3a38 = uVar1;
  DAT_803f3a3c = in_CTR;
  DAT_803f3a40 = in_XER;
  TRKSaveExtended1Block();
  DAT_803a28d8._0_1_ = 1;
  sync(0);
  sync(0);
  uVar3 = TRKPostInterruptEvent
                    (DAT_803f3918,DAT_803f391c,DAT_803f3920,DAT_803f3924,DAT_803f3928,DAT_803f392c,
                     DAT_803f3930,DAT_803f3934);
  return uVar3;
}


void TRKExceptionHandler(undefined2 param_1)

{
  undefined4 in_MSR;
  undefined4 in_SRR0;
  undefined4 in_SRR1;
  
  returnFromInterrupt(in_MSR,in_SRR1);
  gTRKExceptionStatus = in_SRR0;
  DAT_803a28d4._0_2_ = param_1;
  DAT_803a28d8._1_1_ = 1;
  return;
}


/* WARNING: This function may have set the stack pointer */

undefined4
TRKSwapAndGo
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 in_r0;
  undefined4 uVar1;
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
  uint in_MSR;
  uint uVar2;
  undefined4 in_XER;
  undefined4 in_LR;
  undefined4 in_CTR;
  undefined4 in_DSISR;
  undefined4 in_DAR;
  undefined4 in_SRR1;
  
  DAT_803f3914 = 0x803ffd00;
  DAT_803f3918 = &gTRKState;
  DAT_803f3940 = 0x803fe0e0;
  uVar2 = in_MSR & 0x9000;
  gTRKState = in_r0;
  DAT_803f3910 = (undefined *)register0x00000004;
  DAT_803f391c = param_2;
  DAT_803f3920 = param_3;
  DAT_803f3924 = param_4;
  DAT_803f3928 = param_5;
  DAT_803f392c = param_6;
  DAT_803f3930 = param_7;
  DAT_803f3934 = param_8;
  DAT_803f3938 = in_r11;
  DAT_803f393c = in_r12;
  DAT_803f3944 = unaff_r14;
  DAT_803f3948 = unaff_r15;
  DAT_803f394c = unaff_r16;
  DAT_803f3950 = unaff_r17;
  DAT_803f3954 = unaff_r18;
  DAT_803f3958 = unaff_r19;
  DAT_803f395c = unaff_r20;
  DAT_803f3960 = unaff_r21;
  DAT_803f3964 = unaff_r22;
  DAT_803f3968 = unaff_r23;
  DAT_803f396c = unaff_r24;
  DAT_803f3970 = unaff_r25;
  DAT_803f3974 = unaff_r26;
  DAT_803f3978 = unaff_r27;
  DAT_803f397c = unaff_r28;
  DAT_803f3980 = unaff_r29;
  DAT_803f3984 = unaff_r30;
  DAT_803f3988 = unaff_r31;
  DAT_803f398c = in_LR;
  DAT_803f3990 = in_CTR;
  DAT_803f3994 = in_XER;
  DAT_803f3998 = in_MSR;
  DAT_803f399c = in_DAR;
  DAT_803f39a0 = in_DSISR;
  if (*DAT_803f39ac != '\0') {
    DAT_803f39a8._0_1_ = 1;
    uVar1 = TRKInterruptHandlerEnableInterrupts();
    return uVar1;
  }
  DAT_803a28d8._0_1_ = 0;
  TRKRestoreExtended1Block();
  returnFromInterrupt(uVar2,in_SRR1);
  return DAT_803f39bc;
}


void TRKInterruptHandlerEnableInterrupts(void)

{
  sync(0);
  sync(0);
  TRKPostInterruptEvent
            (DAT_803f3918,DAT_803f391c,DAT_803f3920,DAT_803f3924,DAT_803f3928,DAT_803f392c,
             DAT_803f3930,DAT_803f3934);
  return;
}


void TRKTargetSetInputPendingPtr(undefined4 param_1)

{
  DAT_803f39ac = param_1;
  return;
}


undefined4 TRKPPCAccessFPRegister(undefined4 *param_1,uint param_2,int param_3)

{
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_40 = _314;
  local_3c = DAT_80371504;
  local_38 = DAT_80371508;
  local_34 = DAT_8037150c;
  local_30 = DAT_80371510;
  local_2c = DAT_80371514;
  local_28 = DAT_80371518;
  local_24 = DAT_8037151c;
  local_20 = DAT_80371520;
  local_1c = DAT_80371524;
  if (param_2 < 0x20) {
    local_40 = param_2 << 0x15 | 0xc8030000;
    if (param_3 != 0) {
      local_40 = param_2 << 0x15 | 0xd8030000;
    }
    local_1c = 0x4e800020;
    TRK_flush_cache(&local_40,0x28);
    (*(code *)&local_40)(param_1,&TRKvalue128_temp);
  }
  else {
    if (param_2 == 0x20) {
      param_1[1] = param_1[1];
      *param_1 = 0;
    }
    else {
      if (param_2 == 0x21) {
        if (param_3 == 0) {
          *param_1 = param_1[1];
        }
        local_60 = DAT_803714b8;
        local_5c = DAT_803714bc;
        local_58 = DAT_803714c0;
        local_54 = DAT_803714c4;
        local_50 = DAT_803714c8;
        local_4c = DAT_803714cc;
        local_48 = DAT_803714d0;
        if (param_3 == 0) {
          local_68 = 0x80830000;
          local_64 = 0x7c9efba6;
        }
        else {
          local_64 = 0x90830000;
          local_68 = 0x7c9efaa6;
        }
        local_44 = 0x4e800020;
        TRK_flush_cache(&local_68,0x28);
        (*(code *)&local_68)(param_1,&TRKvalue128_temp);
        if (param_3 != 0) {
          param_1[1] = *param_1;
          *param_1 = 0;
        }
      }
    }
  }
  return 0;
}


undefined4 TRKTargetStop(void)

{
  DAT_803f39a4 = 1;
  return 0;
}


void TRKTargetSetStopped(undefined4 param_1)

{
  DAT_803f39a4 = param_1;
  return;
}


undefined4 TRKTargetStopped(void)

{
  return DAT_803f39a4;
}


undefined4 TRKTargetFlushCache(undefined4 param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (param_2 < param_3) {
    TRK_flush_cache(param_2,param_3 - param_2);
    uVar1 = 0;
  }
  else {
    uVar1 = 0x700;
  }
  return uVar1;
}


int TRKTargetSupportRequest(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  byte local_38 [4];
  undefined4 local_34;
  undefined auStack48 [28];
  
  puVar2 = DAT_803f39c4;
  uVar1 = DAT_803f39bc & 0xff;
  if ((((uVar1 == 0xd1) || (uVar1 == 0xd0)) || (uVar1 == 0xd2)) ||
     ((uVar1 == 0xd3 || (uVar1 == 0xd4)))) {
    if (uVar1 == 0xd2) {
      iVar4 = HandleOpenFileSupportRequest
                        (DAT_803f39c0,(uint)DAT_803f39c4 & 0xff,DAT_803f39c8,local_38);
      if ((local_38[0] == 0) && (iVar4 != 0)) {
        local_38[0] = 1;
      }
      DAT_803f39bc = (uint)local_38[0];
    }
    else {
      if (uVar1 == 0xd3) {
        iVar4 = HandleCloseFileSupportRequest(DAT_803f39c0,local_38);
        if ((local_38[0] == 0) && (iVar4 != 0)) {
          local_38[0] = 1;
        }
        DAT_803f39bc = (uint)local_38[0];
      }
      else {
        if (uVar1 == 0xd4) {
          local_34 = *DAT_803f39c4;
          iVar4 = HandlePositionFileSupportRequest
                            (DAT_803f39c0,&local_34,DAT_803f39c8 & 0xff,local_38);
          if ((local_38[0] == 0) && (iVar4 != 0)) {
            local_38[0] = 1;
          }
          DAT_803f39bc = (uint)local_38[0];
          *DAT_803f39c4 = local_34;
        }
        else {
          uVar3 = countLeadingZeros(0xd1 - uVar1);
          iVar4 = TRKSuppAccessFile(DAT_803f39c0 & 0xff,DAT_803f39c8,DAT_803f39c4,local_38,1,
                                    uVar3 >> 5);
          if ((local_38[0] == 0) && (iVar4 != 0)) {
            local_38[0] = 1;
          }
          DAT_803f39bc = (uint)local_38[0];
          if (uVar1 == 0xd1) {
            TRK_flush_cache(DAT_803f39c8,*puVar2);
          }
        }
      }
    }
    DAT_803f3a30 = DAT_803f3a30 + 4;
  }
  else {
    TRKConstructEvent(auStack48,4);
    TRKPostEvent(auStack48);
    iVar4 = 0;
  }
  return iVar4;
}


undefined4 TRKTargetGetPC(void)

{
  return DAT_803f3a30;
}


/* WARNING: Removing unreachable block (ram,0x80336020) */

undefined4
TRKTargetStepOutOfRange(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    gTRKStepStatus = 1;
    DAT_803a28e0 = 1;
    DAT_803a28e8 = param_1;
    DAT_803a28ec = param_2;
    DAT_803f39a4 = 0;
    DAT_803f3ba8 = DAT_803f3ba8 | 0x400;
    return 0;
  }
  return 0x703;
}


undefined4 TRKTargetSingleStep(int param_1,int param_2)

{
  if (param_2 != 0) {
    return 0x703;
  }
  gTRKStepStatus = 1;
  DAT_803a28e0 = 0;
  DAT_803a28e4 = param_1 + -1;
  DAT_803f39a4 = 0;
  DAT_803f3ba8 = DAT_803f3ba8 | 0x400;
  return 0;
}


void TRKTargetAddExceptionInfo(undefined4 param_1)

{
  int iVar1;
  int local_18;
  undefined4 local_14 [4];
  
  iVar1 = TRKAppendBuffer1_ui32(param_1,gTRKExceptionStatus);
  if (iVar1 == 0) {
    local_18 = 4;
    iVar1 = TRKTargetAccessMemory(local_14,gTRKExceptionStatus,&local_18,0,1);
    if ((iVar1 == 0) && (local_18 != 4)) {
      iVar1 = 0x700;
    }
  }
  if (iVar1 == 0) {
    iVar1 = TRKAppendBuffer1_ui32(param_1,local_14[0]);
  }
  if (iVar1 == 0) {
    TRKAppendBuffer1_ui16(param_1,DAT_803a28d4._0_2_);
  }
  return;
}


void TRKTargetAddStopInfo(undefined4 param_1)

{
  int iVar1;
  undefined4 extraout_r4;
  undefined4 uVar2;
  undefined4 extraout_r4_00;
  uint *puVar3;
  uint *puVar4;
  int local_18;
  undefined4 local_14;
  
  iVar1 = TRKAppendBuffer1_ui32(param_1,DAT_803f3a30);
  if (iVar1 == 0) {
    local_18 = 4;
    iVar1 = TRKTargetAccessMemory(&local_14,DAT_803f3a30,&local_18,0,1);
    if ((iVar1 == 0) && (local_18 != 4)) {
      iVar1 = 0x700;
    }
  }
  if (iVar1 == 0) {
    iVar1 = TRKAppendBuffer1_ui32(param_1,local_14);
  }
  if (iVar1 == 0) {
    iVar1 = TRKAppendBuffer1_ui16(param_1,DAT_803f3ca8 & 0xffff);
  }
  if (iVar1 == 0) {
    iVar1 = 0;
    puVar3 = &gTRKCPUState;
    puVar4 = puVar3;
    do {
      TRKAppendBuffer1_ui32(param_1,*puVar4 & 0xffff);
      iVar1 = iVar1 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar1 < 0x20);
    iVar1 = 0;
    uVar2 = extraout_r4;
    do {
      TRKAppendBuffer1_ui64(param_1,uVar2,0,puVar3[0x27] & 0xffff);
      iVar1 = iVar1 + 1;
      puVar3 = puVar3 + 2;
      uVar2 = extraout_r4_00;
    } while (iVar1 < 0x20);
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x80336308) */

undefined4 TRKTargetInterrupt(byte *param_1)

{
  undefined4 uVar1;
  bool bVar2;
  
  uVar1 = 0;
  if ((*param_1 < 5) && (2 < *param_1)) {
    if (gTRKStepStatus != 0) {
      bVar2 = true;
      DAT_803f3ba8 = DAT_803f3ba8 & 0xfffffbff;
      if ((gTRKStepStatus != 0) && ((DAT_803f3ca8 & 0xffff) == 0xd00)) {
        if (DAT_803a28e0 == '\x01') {
          if ((DAT_803a28e8 <= DAT_803f3a30) && (DAT_803f3a30 <= DAT_803a28ec)) {
            bVar2 = false;
          }
        }
        else {
          if ((DAT_803a28e0 == '\0') && (DAT_803a28e4 != 0)) {
            bVar2 = false;
          }
        }
      }
      if (bVar2) {
        gTRKStepStatus = 0;
      }
      else {
        DAT_803f3ba8 = DAT_803f3ba8 | 0x400;
        gTRKStepStatus = 1;
        if ((DAT_803a28e0 == '\0') || (DAT_803a28e0 == '\x10')) {
          DAT_803a28e4 = DAT_803a28e4 + -1;
        }
        DAT_803f39a4 = 0;
      }
    }
    if (gTRKStepStatus == 0) {
      DAT_803f39a4 = 1;
      uVar1 = TRKDoNotifyStopped(0x90);
    }
  }
  return uVar1;
}


void TRKPostInterruptEvent(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 local_18;
  int local_14;
  undefined auStack16 [16];
  
  if (DAT_803f39a8 == 0) {
    uVar1 = DAT_803f3ca8 & 0xffff;
    if ((uVar1 == 0xd00) || ((uVar1 < 0xd00 && (uVar1 == 0x700)))) {
      local_18 = 4;
      TRKTargetAccessMemory(&local_14,DAT_803f3a30,&local_18,0,1);
      if (local_14 == 0xfe00000) {
        uVar2 = 5;
      }
      else {
        uVar2 = 3;
      }
    }
    else {
      uVar2 = 4;
    }
    TRKConstructEvent(auStack16,uVar2);
    TRKPostEvent(auStack16);
  }
  else {
    DAT_803f39a8 = 0;
  }
  return;
}


undefined4 TRKTargetCPUType(undefined *param_1)

{
  undefined uVar1;
  
  *param_1 = 0;
  uVar1 = TRKTargetCPUMinorType();
  param_1[1] = uVar1;
  param_1[2] = (char)gTRKBigEndian;
  param_1[3] = 4;
  param_1[4] = 8;
  param_1[5] = 4;
  param_1[6] = 8;
  return 0;
}


undefined4 TRKTargetSupportMask(undefined *param_1)

{
  *param_1 = 0x7a;
  param_1[1] = 0;
  param_1[2] = 0x4f;
  param_1[3] = 7;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 1;
  param_1[0x11] = 0;
  param_1[0x12] = 3;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 3;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0x80;
  return 0;
}


undefined4 TRKTargetVersions(undefined *param_1)

{
  *param_1 = 0;
  param_1[1] = 10;
  param_1[2] = 1;
  param_1[3] = 10;
  return 0;
}


/* WARNING: Removing unreachable block (ram,0x80336950) */

int TRKTargetAccessExtended2
              (uint param_1,uint param_2,undefined4 param_3,int *param_4,int param_5)

{
  int iVar1;
  undefined4 extraout_r4;
  uint uVar2;
  uint local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  uint local_110;
  uint local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  uint local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  
  if (param_2 < 0x20) {
    local_11c = gTRKExceptionStatus;
    local_118 = DAT_803a28d0;
    local_114 = DAT_803a28d4;
    local_110 = DAT_803a28d8;
    DAT_803a28d8 = DAT_803a28d8 & 0xff00ffff;
    local_64 = DAT_803714b8;
    local_60 = DAT_803714bc;
    local_5c = DAT_803714c0;
    local_58 = DAT_803714c4;
    local_54 = DAT_803714c8;
    local_50 = DAT_803714cc;
    local_4c = DAT_803714d0;
    local_6c = 0x7c98e2a6;
    local_68 = 0x90830000;
    local_48 = 0x4e800020;
    TRK_flush_cache(&local_6c,0x28);
    (*(code *)&local_6c)(&local_128,&TRKvalue128_temp);
    local_128 = local_128 | 0xa0000000;
    local_8c = DAT_803714b8;
    local_88 = DAT_803714bc;
    local_84 = DAT_803714c0;
    local_80 = DAT_803714c4;
    local_7c = DAT_803714c8;
    local_78 = DAT_803714cc;
    local_74 = DAT_803714d0;
    local_94 = 0x80830000;
    local_90 = 0x7c98e3a6;
    local_70 = 0x4e800020;
    TRK_flush_cache(&local_94,0x28);
    (*(code *)&local_94)(&local_128,&TRKvalue128_temp);
    local_128 = 0;
    local_b4 = DAT_803714b8;
    local_b0 = DAT_803714bc;
    local_ac = DAT_803714c0;
    local_a8 = DAT_803714c4;
    local_a4 = DAT_803714c8;
    local_a0 = DAT_803714cc;
    local_9c = DAT_803714d0;
    local_bc = 0x80830000;
    local_b8 = 0x7c90e3a6;
    local_98 = 0x4e800020;
    TRK_flush_cache(&local_bc,0x28);
    (*(code *)&local_bc)(&local_128,&TRKvalue128_temp);
    uVar2 = param_1 << 0x15;
    *param_4 = 0;
    iVar1 = 0;
    while ((param_1 <= param_2 && (iVar1 == 0))) {
      if (param_5 == 0) {
        TRKReadBuffer1_ui64(param_3,&local_124);
        local_10c = uVar2 | 0xe0030000;
        local_108 = DAT_803714dc;
        local_104 = DAT_803714e0;
        local_100 = DAT_803714e4;
        local_fc = DAT_803714e8;
        local_f8 = DAT_803714ec;
        local_f4 = DAT_803714f0;
        local_f0 = DAT_803714f4;
        local_ec = DAT_803714f8;
        local_e8 = 0x4e800020;
        TRK_flush_cache(&local_10c,0x28);
        (*(code *)&local_10c)(&local_124,&TRKvalue128_temp);
        iVar1 = 0;
      }
      else {
        local_e4 = uVar2 | 0xe0030000;
        local_e0 = DAT_803714dc;
        local_dc = DAT_803714e0;
        local_d8 = DAT_803714e4;
        local_d4 = DAT_803714e8;
        local_d0 = DAT_803714ec;
        local_cc = DAT_803714f0;
        local_c8 = DAT_803714f4;
        local_c4 = DAT_803714f8;
        if (param_5 != 0) {
          local_e4 = uVar2 | 0xf0030000;
        }
        local_c0 = 0x4e800020;
        TRK_flush_cache(&local_e4,0x28);
        (*(code *)&local_e4)(&local_124,&TRKvalue128_temp);
        iVar1 = TRKAppendBuffer1_ui64(param_3,extraout_r4,local_124,local_120);
      }
      uVar2 = uVar2 + 0x200000;
      param_1 = param_1 + 1;
      *param_4 = *param_4 + 8;
    }
    if (DAT_803a28d8._1_1_ != '\0') {
      iVar1 = 0x702;
      *param_4 = 0;
    }
    gTRKExceptionStatus = local_11c;
    DAT_803a28d0 = local_118;
    DAT_803a28d4 = local_114;
    DAT_803a28d8 = local_110;
  }
  else {
    iVar1 = 0x701;
  }
  return iVar1;
}


uint TRKTargetAccessExtended1
               (uint param_1,uint param_2,undefined4 param_3,int *param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  
  uVar4 = DAT_803a28d8;
  uVar3 = DAT_803a28d4;
  uVar2 = DAT_803a28d0;
  uVar1 = gTRKExceptionStatus;
  if (param_2 < 0x61) {
    DAT_803a28d8 = DAT_803a28d8 & 0xff00ffff;
    *param_4 = 0;
    if (param_1 <= param_2) {
      iVar6 = param_2 - param_1;
      iVar5 = iVar6 + 1;
      *param_4 = *param_4 + iVar5 * 4;
      puVar7 = &DAT_803f3b58 + param_1;
      if (param_5 == 0) {
        if ((puVar7 < (undefined4 *)0x803f3b9d) && ((undefined4 *)0x803f3b97 < puVar7 + iVar6)) {
          gTRKRestoreFlags = 1;
        }
        if ((puVar7 < (undefined4 *)0x803f3c29) && ((undefined4 *)0x803f3c27 < puVar7 + iVar6)) {
          DAT_803a28c1 = 1;
        }
        param_1 = TRKReadBuffer_ui32(param_3,puVar7,iVar5);
      }
      else {
        param_1 = TRKAppendBuffer_ui32(param_3,puVar7,iVar5);
      }
    }
    if (DAT_803a28d8._1_1_ != '\0') {
      param_1 = 0x702;
      *param_4 = 0;
    }
  }
  else {
    param_1 = 0x701;
  }
  gTRKExceptionStatus = uVar1;
  DAT_803a28d0 = uVar2;
  DAT_803a28d4 = uVar3;
  DAT_803a28d8 = uVar4;
  return param_1;
}


int TRKTargetAccessFP
              (uint param_1,uint param_2,undefined4 param_3,int *param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 extraout_r4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  
  if (param_2 < 0x22) {
    local_30 = gTRKExceptionStatus;
    local_2c = DAT_803a28d0;
    local_28 = DAT_803a28d4;
    local_24 = DAT_803a28d8;
    DAT_803a28d8 = DAT_803a28d8 & 0xff00ffff;
    uVar2 = __TRK_get_MSR();
    __TRK_set_MSR(uVar2 | 0x2000);
    iVar1 = 0;
    *param_4 = 0;
    while ((param_1 <= param_2 && (iVar1 == 0))) {
      if (param_5 == 0) {
        TRKReadBuffer1_ui64(param_3,&local_38);
        iVar1 = TRKPPCAccessFPRegister(&local_38,param_1,0);
      }
      else {
        TRKPPCAccessFPRegister(&local_38,param_1,param_5);
        iVar1 = TRKAppendBuffer1_ui64(param_3,extraout_r4,local_38,local_34);
      }
      param_1 = param_1 + 1;
      *param_4 = *param_4 + 8;
    }
    if (DAT_803a28d8._1_1_ != '\0') {
      iVar1 = 0x702;
      *param_4 = 0;
    }
    gTRKExceptionStatus = local_30;
    DAT_803a28d0 = local_2c;
    DAT_803a28d4 = local_28;
    DAT_803a28d8 = local_24;
  }
  else {
    iVar1 = 0x701;
  }
  return iVar1;
}


undefined4
TRKTargetAccessDefault
          (int param_1,uint param_2,undefined4 param_3,int *param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar4 = DAT_803a28d8;
  uVar3 = DAT_803a28d4;
  uVar2 = DAT_803a28d0;
  uVar1 = gTRKExceptionStatus;
  if (param_2 < 0x25) {
    iVar6 = (param_2 - param_1) + 1;
    DAT_803a28d8 = DAT_803a28d8 & 0xff00ffff;
    *param_4 = iVar6 * 4;
    if (param_5 == 0) {
      uVar5 = TRKReadBuffer_ui32(param_3,&gTRKCPUState + param_1,iVar6);
    }
    else {
      uVar5 = TRKAppendBuffer_ui32(param_3,&gTRKCPUState + param_1,iVar6);
    }
    if (DAT_803a28d8._1_1_ != '\0') {
      uVar5 = 0x702;
      *param_4 = 0;
    }
  }
  else {
    uVar5 = 0x701;
  }
  gTRKExceptionStatus = uVar1;
  DAT_803a28d0 = uVar2;
  DAT_803a28d4 = uVar3;
  DAT_803a28d8 = uVar4;
  return uVar5;
}


int TRKTargetAccessMemory
              (undefined4 param_1,int param_2,undefined4 *param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar4 = DAT_803a28d8;
  uVar3 = DAT_803a28d4;
  uVar2 = DAT_803a28d0;
  uVar1 = gTRKExceptionStatus;
  DAT_803a28d8 = DAT_803a28d8 & 0xff00ffff;
  iVar6 = TRKTargetTranslate(param_2);
  uVar5 = countLeadingZeros(param_5);
  iVar7 = TRKValidMemory32(iVar6,*param_3,uVar5 >> 5);
  if (iVar7 == 0) {
    uVar5 = __TRK_get_MSR();
    if (param_5 == 0) {
      TRK_ppc_memcpy(iVar6,param_1,*param_3,uVar5 | DAT_803f3ba8 & 0x10,uVar5);
      TRK_flush_cache(iVar6,*param_3);
      if (param_2 != iVar6) {
        TRK_flush_cache(param_2,*param_3);
      }
    }
    else {
      TRK_ppc_memcpy(param_1,iVar6,*param_3,uVar5);
    }
  }
  else {
    *param_3 = 0;
  }
  if (DAT_803a28d8._1_1_ != '\0') {
    iVar7 = 0x702;
    *param_3 = 0;
  }
  gTRKExceptionStatus = uVar1;
  DAT_803a28d0 = uVar2;
  DAT_803a28d4 = uVar3;
  DAT_803a28d8 = uVar4;
  return iVar7;
}


int TRKValidMemory32(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (param_2 + param_1) - 1;
  iVar1 = 0x700;
  if (uVar2 < param_1) {
    iVar1 = 0x700;
  }
  else {
    if ((param_1 <= DAT_803714a4) && (gTRKMemMap <= uVar2)) {
      if ((((param_3 & 0xff) == 0) && (DAT_803714a8 == 0)) ||
         (((param_3 & 0xff) == 1 && (DAT_803714ac == 0)))) {
        iVar1 = 0x700;
      }
      else {
        iVar1 = 0;
        if (param_1 < gTRKMemMap) {
          iVar1 = TRKValidMemory32(param_1,gTRKMemMap - param_1,param_3);
        }
        if ((iVar1 == 0) && (DAT_803714a4 < uVar2)) {
          iVar1 = TRKValidMemory32(DAT_803714a4,uVar2 - DAT_803714a4,param_3);
        }
      }
    }
  }
  return iVar1;
}

