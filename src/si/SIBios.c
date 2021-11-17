#include <si/SIBios.h>
#include <os/OSTime.h>
#include <si/SIBios.h>
#include <os/OSAlarm.h>
#include <vi/vi.h>
#include <os/OSInterrupt.h>
#include <os/OS.h>
#include <si/SISamplingRate.h>
#include <os/OSRtc.h>


namespace si {
undefined4 Packet;
undefined Alarm;
undefined TypeTime;
undefined XferTime;
undefined TypeCallback;
undefined4 RDSTHandler;
undefined InputBufferValid;
undefined InputBuffer;
undefined4 InputBufferVcount;
undefined cmdFixDevice$327;
undefined cmdTypeAndStatus$78;
undefined cmdTypeAndStatus$372;
undefined4 __PADFixBits;

undefined4 SIBusy(void)

{
  if (Si != -1) {
    return 1;
  }
  return 0;
}


undefined4 SIIsChanBusy(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (((&Packet)[param_1 * 8] == -1) && (Si != param_1)) {
    uVar1 = 0;
  }
  return uVar1;
}


uint CompleteTransfer(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  uint uVar8;
  uint uVar9;
  undefined8 uVar10;
  
  uVar5 = DAT_cc006438;
  puVar7 = &DAT_cc006400;
  DAT_cc006434 = DAT_cc006434 & 0xfffffffe | 0x80000000;
  uVar6 = DAT_cc006438;
  if (Si != -1) {
    uVar10 = os::__OSGetSystemTime();
    iVar2 = Si * 8;
    *(int *)(&DAT_803f0eb4 + iVar2) = (int)uVar10;
    uVar3 = 0;
    *(int *)(&XferTime + iVar2) = (int)((ulonglong)uVar10 >> 0x20);
    uVar6 = DAT_803a0774 >> 2;
    puVar4 = DAT_803a0778;
    if (uVar6 != 0) {
      if ((8 < uVar6) && (uVar8 = uVar6 - 1 >> 3, uVar6 != 8)) {
        do {
          uVar3 = uVar3 + 8;
          *puVar4 = *(undefined4 *)(puVar7 + 0x80);
          puVar4[1] = *(undefined4 *)(puVar7 + 0x84);
          puVar4[2] = *(undefined4 *)(puVar7 + 0x88);
          puVar4[3] = *(undefined4 *)(puVar7 + 0x8c);
          puVar4[4] = *(undefined4 *)(puVar7 + 0x90);
          puVar4[5] = *(undefined4 *)(puVar7 + 0x94);
          puVar4[6] = *(undefined4 *)(puVar7 + 0x98);
          puVar1 = (undefined4 *)(puVar7 + 0x9c);
          puVar7 = puVar7 + 0x20;
          puVar4[7] = *puVar1;
          puVar4 = puVar4 + 8;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      puVar7 = &DAT_cc006400 + uVar3 * 4;
      iVar2 = uVar6 - uVar3;
      if (uVar3 < uVar6) {
        do {
          puVar1 = (undefined4 *)(puVar7 + 0x80);
          puVar7 = puVar7 + 4;
          uVar3 = uVar3 + 1;
          *puVar4 = *puVar1;
          puVar4 = puVar4 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
    }
    uVar6 = DAT_803a0774 & 3;
    if (uVar6 != 0) {
      uVar8 = (&DAT_cc006480)[uVar3];
      uVar3 = 0;
      if (uVar6 != 0) {
        if ((8 < uVar6) && (uVar9 = uVar6 - 1 >> 3, uVar6 != 8)) {
          do {
            *(char *)puVar4 = (char)(uVar8 >> (3 - uVar3) * 8);
            *(char *)((int)puVar4 + 1) = (char)(uVar8 >> (3 - (uVar3 + 1)) * 8);
            *(char *)((int)puVar4 + 2) = (char)(uVar8 >> (3 - (uVar3 + 2)) * 8);
            *(char *)((int)puVar4 + 3) = (char)(uVar8 >> uVar3 * -8);
            *(char *)(puVar4 + 1) = (char)(uVar8 >> (3 - (uVar3 + 4)) * 8);
            *(char *)((int)puVar4 + 5) = (char)(uVar8 >> (3 - (uVar3 + 5)) * 8);
            *(char *)((int)puVar4 + 6) = (char)(uVar8 >> (3 - (uVar3 + 6)) * 8);
            *(char *)((int)puVar4 + 7) = (char)(uVar8 >> (3 - (uVar3 + 7)) * 8);
            puVar4 = puVar4 + 2;
            uVar3 = uVar3 + 8;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        iVar2 = uVar6 - uVar3;
        if (uVar3 < uVar6) {
          do {
            *(char *)puVar4 = (char)(uVar8 >> (3 - uVar3) * 8);
            puVar4 = (undefined4 *)((int)puVar4 + 1);
            uVar3 = uVar3 + 1;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
      }
    }
    if ((DAT_cc006434 & 0x20000000) == 0) {
      uVar10 = os::__OSGetSystemTime();
      *(int *)(&DAT_803f0e94 + Si * 8) = (int)uVar10;
      uVar6 = 0;
      *(int *)(&TypeTime + Si * 8) = (int)((ulonglong)uVar10 >> 0x20);
    }
    else {
      uVar5 = uVar5 >> (3 - Si) * 8;
      uVar6 = uVar5 & 0xf;
      if (((uVar5 & 8) != 0) && ((*(uint *)(&Type + Si * 4) & 0x80) == 0)) {
        *(uint *)(&Type + Si * 4) = 8;
      }
      if (uVar6 == 0) {
        uVar6 = 4;
      }
    }
    Si = -1;
  }
  return uVar6;
}


void SIInterruptHandler(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  bool bVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  code **ppcVar7;
  uint *puVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  undefined8 uVar12;
  
  uVar6 = DAT_cc006434;
  uVar1 = Si;
  if ((DAT_cc006434 & 0xc0000000) == 0xc0000000) {
    uVar4 = CompleteTransfer();
    pcVar3 = DAT_803a077c;
    iVar11 = 0;
    DAT_803a077c = (code *)0x0;
    uVar10 = uVar1;
    do {
      uVar10 = uVar10 + 1;
      uVar10 = uVar10 + (((int)uVar10 >> 2) + (uint)((int)uVar10 < 0 && (uVar10 & 3) != 0)) * -4;
      piVar9 = &Packet + uVar10 * 8;
      if ((*piVar9 != -1) &&
         (uVar12 = os::__OSGetSystemTime(),
         (uint)((uint)uVar12 < (uint)(&DAT_803f0d8c)[uVar10 * 8]) +
         ((&DAT_803f0d88)[uVar10 * 8] ^ 0x80000000) <=
         ((uint)((ulonglong)uVar12 >> 0x20) ^ 0x80000000))) {
        iVar11 = __SITransfer(*piVar9,(&DAT_803f0d74)[uVar10 * 8],(&DAT_803f0d78)[uVar10 * 8],
                              (&DAT_803f0d7c)[uVar10 * 8],(&DAT_803f0d80)[uVar10 * 8],
                              (&DAT_803f0d84)[uVar10 * 8]);
        if (iVar11 != 0) {
          os::OSCancelAlarm(&Alarm + uVar10 * 0x28);
          *piVar9 = -1;
        }
        break;
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < 4);
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)(uVar1,uVar4,param_2);
    }
    DAT_cc006438 = DAT_cc006438 & 0xf000000 >> ((uVar1 & 7) << 3);
    if (*(int *)(&Type + uVar1 * 4) == 0x80) {
      bVar2 = true;
      if (((&Packet)[uVar1 * 8] == -1) && (Si != uVar1)) {
        bVar2 = false;
      }
      if (!bVar2) {
        SITransfer(uVar1,&cmdTypeAndStatus_78,1,&Type + uVar1 * 4,3,GetTypeCallback,0,
                   ((DAT_800000f8 >> 2) / 0x1e848) * 0x41 >> 3);
      }
    }
  }
  if ((uVar6 & 0x18000000) == 0x18000000) {
    iVar11 = vi::VIGetCurrentLine();
    puVar8 = (uint *)&InputBufferVcount;
    uVar6 = iVar11 + 1;
    uVar1 = DAT_803a0770 >> 0x10;
    iVar11 = 0;
    do {
      iVar5 = SIGetResponseRaw(iVar11);
      if (iVar5 != 0) {
        *puVar8 = uVar6;
      }
      iVar11 = iVar11 + 1;
      puVar8 = puVar8 + 1;
    } while (iVar11 < 4);
    uVar1 = (uVar1 & 0x3ff) >> 1;
    if ((((((DAT_803a0770 & 0x80) == 0) ||
          ((InputBufferVcount != 0 && (uVar6 <= uVar1 + InputBufferVcount)))) &&
         (((DAT_803a0770 & 0x40) == 0 || ((DAT_803f0f54 != 0 && (uVar6 <= uVar1 + DAT_803f0f54))))))
        && (((DAT_803a0770 & 0x20) == 0 || ((DAT_803f0f58 != 0 && (uVar6 <= uVar1 + DAT_803f0f58))))
           )) && (((DAT_803a0770 & 0x10) == 0 ||
                  ((DAT_803f0f5c != 0 && (uVar6 <= uVar1 + DAT_803f0f5c)))))) {
      iVar11 = 0;
      InputBufferVcount = 0;
      ppcVar7 = (code **)&RDSTHandler;
      DAT_803f0f54 = 0;
      DAT_803f0f58 = 0;
      DAT_803f0f5c = 0;
      do {
        if (*ppcVar7 != (code *)0x0) {
          (**ppcVar7)(param_1,param_2);
        }
        iVar11 = iVar11 + 1;
        ppcVar7 = ppcVar7 + 1;
      } while (iVar11 < 4);
    }
  }
  return;
}


bool SIEnablePollingInterrupt(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  os::OSDisableInterrupts();
  uVar1 = DAT_cc006434 & 0x8000000;
  if (param_1 == 0) {
    uVar2 = DAT_cc006434 & 0xf7ffffff;
  }
  else {
    InputBufferVcount = 0;
    uVar2 = DAT_cc006434 | 0x8000000;
    DAT_803f0f54 = 0;
    DAT_803f0f58 = 0;
    DAT_803f0f5c = 0;
  }
  DAT_cc006434 = uVar2 & 0x7ffffffe;
  os::OSRestoreInterrupts();
  return uVar1 != 0;
}


undefined4 SIRegisterPollingHandler(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = os::OSDisableInterrupts();
  piVar3 = &RDSTHandler;
  iVar4 = 4;
  piVar2 = piVar3;
  do {
    if (*piVar2 == param_1) {
      os::OSRestoreInterrupts(uVar1);
      return 1;
    }
    piVar2 = piVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar5 = 4;
  iVar4 = 0;
  do {
    if (*piVar3 == 0) {
      (&RDSTHandler)[iVar4] = param_1;
      SIEnablePollingInterrupt(1);
      os::OSRestoreInterrupts(uVar1);
      return 1;
    }
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  os::OSRestoreInterrupts(uVar1);
  return 0;
}


undefined4 SIUnregisterPollingHandler(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  uVar1 = os::OSDisableInterrupts();
  piVar3 = &RDSTHandler;
  iVar4 = 4;
  iVar2 = 0;
  do {
    if (*piVar3 == param_1) {
      (&RDSTHandler)[iVar2] = 0;
      iVar2 = 0;
      if ((((RDSTHandler == 0) && (iVar2 = 1, DAT_803f0f14 == 0)) && (iVar2 = 2, DAT_803f0f18 == 0))
         && (iVar2 = 3, DAT_803f0f1c == 0)) {
        iVar2 = 4;
      }
      if (iVar2 == 4) {
        SIEnablePollingInterrupt(0);
      }
      os::OSRestoreInterrupts(uVar1);
      return 1;
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  os::OSRestoreInterrupts(uVar1);
  return 0;
}


void SIInit(void)

{
  os::OSRegisterVersion(__SIVersion);
  DAT_803f0dd0 = 0xffffffff;
  DAT_803f0db0 = 0xffffffff;
  DAT_803f0d90 = 0xffffffff;
  Packet = 0xffffffff;
  DAT_803a0770 = 0;
  SISetSamplingRate(0);
  do {
  } while ((DAT_cc006434 & 1) != 0);
  DAT_cc006434 = 0x80000000;
  os::__OSSetInterruptHandler(0x14,SIInterruptHandler);
  os::__OSUnmaskInterrupts(0x800);
  SIGetType(0);
  SIGetType(1);
  SIGetType(2);
  SIGetType(3);
  return;
}


/* WARNING: Could not reconcile some variable overlaps */

undefined4
__SITransfer(uint param_1,undefined4 *param_2,int param_3,undefined4 param_4,int param_5,
                int param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 local_24;
  
  os::OSDisableInterrupts();
  if (Si == 0xffffffff) {
    DAT_cc006438 = DAT_cc006438 & 0xf000000 >> ((param_1 & 7) << 3);
    uVar2 = param_3 + 3U >> 2;
    uVar5 = 0;
    Si = param_1;
    DAT_803a0774 = param_5;
    DAT_803a0778 = param_4;
    DAT_803a077c = param_6;
    if (uVar2 != 0) {
      if (8 < uVar2) {
        uVar8 = uVar2 - 1 >> 3;
        puVar6 = &DAT_cc006400;
        puVar7 = param_2;
        if (uVar2 != 8) {
          do {
            uVar5 = uVar5 + 8;
            *(undefined4 *)(puVar6 + 0x80) = *puVar7;
            *(undefined4 *)(puVar6 + 0x84) = puVar7[1];
            *(undefined4 *)(puVar6 + 0x88) = puVar7[2];
            *(undefined4 *)(puVar6 + 0x8c) = puVar7[3];
            *(undefined4 *)(puVar6 + 0x90) = puVar7[4];
            *(undefined4 *)(puVar6 + 0x94) = puVar7[5];
            *(undefined4 *)(puVar6 + 0x98) = puVar7[6];
            puVar1 = puVar7 + 7;
            puVar7 = puVar7 + 8;
            *(undefined4 *)(puVar6 + 0x9c) = *puVar1;
            puVar6 = puVar6 + 0x20;
            uVar8 = uVar8 - 1;
          } while (uVar8 != 0);
        }
      }
      param_2 = param_2 + uVar5;
      puVar6 = &DAT_cc006400 + uVar5 * 4;
      iVar3 = uVar2 - uVar5;
      if (uVar5 < uVar2) {
        do {
          uVar4 = *param_2;
          param_2 = param_2 + 1;
          *(undefined4 *)(puVar6 + 0x80) = uVar4;
          puVar6 = puVar6 + 4;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
    }
    uVar2 = DAT_cc006434 & 0xffffff;
    if (param_3 == 0x80) {
      param_3 = 0;
    }
    local_24._1_1_ = (byte)(uVar2 >> 0x10);
    local_24._1_3_ = CONCAT12((byte)param_3 & 0x7f | local_24._1_1_ & 0x80,(short)uVar2);
    if (param_5 == 0x80) {
      param_5 = 0;
    }
    local_24._2_1_ = (byte)((uint)local_24._1_3_ >> 8);
    local_24 = (uint)(byte)((param_6 != 0) << 6 | (byte)(DAT_cc006434 >> 0x18) & 0x3f | 0x80) <<
               0x18 | local_24._1_3_ & 0xffff0000 |
               (uint)((byte)param_5 & 0x7f | local_24._2_1_ & 0x80) << 8 |
               ((byte)(param_1 << 1) & 6 | (byte)uVar2 & 0xf9) & 0xfffffffe | 1;
    DAT_cc006434 = local_24;
    os::OSRestoreInterrupts();
    uVar4 = 1;
  }
  else {
    os::OSRestoreInterrupts();
    uVar4 = 0;
  }
  return uVar4;
}


uint SIGetStatus(int param_1)

{
  uint uVar1;
  
  os::OSDisableInterrupts();
  uVar1 = DAT_cc006438 >> (3 - param_1) * 8;
  if (((uVar1 & 8) != 0) && ((*(uint *)(&Type + param_1 * 4) & 0x80) == 0)) {
    *(uint *)(&Type + param_1 * 4) = 8;
  }
  os::OSRestoreInterrupts();
  return uVar1;
}


void SISetCommand(int param_1,undefined4 param_2)

{
  *(undefined4 *)(&DAT_cc006400 + param_1 * 0xc) = param_2;
  return;
}


void SITransferCommands(void)

{
  DAT_cc006438 = 0x80000000;
  return;
}


uint SISetXY(int param_1,int param_2)

{
  uint uVar1;
  
  os::OSDisableInterrupts();
  uVar1 = DAT_803a0770 & 0xfc0000ff | param_1 << 0x10 | param_2 << 8;
  DAT_803a0770 = uVar1;
  DAT_cc006430 = uVar1;
  os::OSRestoreInterrupts();
  return uVar1;
}


uint SIEnablePolling(uint param_1)

{
  uint uVar1;
  
  uVar1 = DAT_803a0770;
  if (param_1 != 0) {
    os::OSDisableInterrupts();
    uVar1 = DAT_803a0770 & ~(param_1 >> 0x1c) | param_1 >> 0x18 & (param_1 >> 0x1c | 0x3fffff0);
    DAT_cc006438 = 0x80000000;
    DAT_803a0770 = uVar1;
    DAT_cc006430 = uVar1;
    os::OSRestoreInterrupts();
  }
  return uVar1;
}


uint SIDisablePolling(uint param_1)

{
  uint uVar1;
  
  uVar1 = DAT_803a0770;
  if (param_1 != 0) {
    os::OSDisableInterrupts();
    uVar1 = DAT_803a0770 & ~(param_1 >> 0x18 & 0xf0);
    DAT_803a0770 = uVar1;
    DAT_cc006430 = uVar1;
    os::OSRestoreInterrupts();
  }
  return uVar1;
}


bool SIGetResponseRaw(int param_1)

{
  bool bVar1;
  uint uVar2;
  
  os::OSDisableInterrupts();
  uVar2 = DAT_cc006438 >> (3 - param_1) * 8;
  if (((uVar2 & 8) != 0) && ((*(uint *)(&Type + param_1 * 4) & 0x80) == 0)) {
    *(uint *)(&Type + param_1 * 4) = 8;
  }
  os::OSRestoreInterrupts();
  bVar1 = (uVar2 & 0x20) != 0;
  if (bVar1) {
    *(undefined4 *)(&InputBuffer + param_1 * 8) = *(undefined4 *)(&DAT_cc006404 + param_1 * 0xc);
    *(undefined4 *)(&DAT_803f0f34 + param_1 * 8) = *(undefined4 *)(&DAT_cc006408 + param_1 * 0xc);
    *(undefined4 *)(&InputBufferValid + param_1 * 4) = 1;
  }
  return bVar1;
}


int SIGetResponse(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = os::OSDisableInterrupts();
  uVar2 = SIGetStatus(param_1);
  if ((uVar2 & 0x20) != 0) {
    *(undefined4 *)(&InputBuffer + param_1 * 8) = *(undefined4 *)(&DAT_cc006404 + param_1 * 0xc);
    *(undefined4 *)(&DAT_803f0f34 + param_1 * 8) = *(undefined4 *)(&DAT_cc006408 + param_1 * 0xc);
    *(undefined4 *)(&InputBufferValid + param_1 * 4) = 1;
  }
  iVar3 = *(int *)(&InputBufferValid + param_1 * 4);
  *(undefined4 *)(&InputBufferValid + param_1 * 4) = 0;
  if (iVar3 != 0) {
    *param_2 = *(undefined4 *)(&InputBuffer + param_1 * 8);
    param_2[1] = *(undefined4 *)(&DAT_803f0f34 + param_1 * 8);
  }
  os::OSRestoreInterrupts(uVar1);
  return iVar3;
}


void AlarmHandler(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (param_1 + 0x7fc0f210) / 0x28 + (param_1 + 0x7fc0f210 >> 0x1f);
  iVar1 = iVar1 - (iVar1 >> 0x1f);
  iVar2 = (&Packet)[iVar1 * 8];
  if ((iVar2 != -1) &&
     (iVar2 = __SITransfer(iVar2,(&DAT_803f0d74)[iVar1 * 8],(&DAT_803f0d78)[iVar1 * 8],
                           (&DAT_803f0d7c)[iVar1 * 8],(&DAT_803f0d80)[iVar1 * 8],
                           (&DAT_803f0d84)[iVar1 * 8]), iVar2 != 0)) {
    (&Packet)[iVar1 * 8] = -1;
  }
  return;
}


undefined4
SITransfer(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,uint param_7,uint param_8)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  uVar1 = os::OSDisableInterrupts();
  if (((&Packet)[param_1 * 8] == -1) && (Si != param_1)) {
    uVar7 = os::__OSGetSystemTime();
    uVar2 = (uint)((ulonglong)uVar7 >> 0x20);
    uVar4 = (uint)uVar7;
    if ((param_8 | param_7) != 0) {
      uVar7 = CONCAT44(param_7 + *(int *)(&XferTime + param_1 * 8) +
                                 (uint)CARRY4(param_8,*(uint *)(&DAT_803f0eb4 + param_1 * 8)),
                       param_8 + *(uint *)(&DAT_803f0eb4 + param_1 * 8));
    }
    uVar6 = (uint)((ulonglong)uVar7 >> 0x20);
    uVar5 = (uint)uVar7;
    if ((uVar2 ^ 0x80000000) < (uint)(uVar4 < uVar5) + (uVar6 ^ 0x80000000)) {
      os::OSSetAlarm(&Alarm + param_1 * 0x28,0x80310000,uVar6 - ((uVar5 < uVar4) + uVar2),
                     uVar5 - uVar4,AlarmHandler);
    }
    else {
      iVar3 = __SITransfer(param_1,param_2,param_3,param_4,param_5,param_6);
      if (iVar3 != 0) {
        os::OSRestoreInterrupts(uVar1);
        return 1;
      }
    }
    (&Packet)[param_1 * 8] = param_1;
    (&DAT_803f0d74)[param_1 * 8] = param_2;
    (&DAT_803f0d78)[param_1 * 8] = param_3;
    (&DAT_803f0d7c)[param_1 * 8] = param_4;
    (&DAT_803f0d80)[param_1 * 8] = param_5;
    (&DAT_803f0d84)[param_1 * 8] = param_6;
    (&DAT_803f0d8c)[param_1 * 8] = uVar5;
    (&DAT_803f0d88)[param_1 * 8] = uVar6;
    os::OSRestoreInterrupts(uVar1);
    uVar1 = 1;
  }
  else {
    os::OSRestoreInterrupts(uVar1);
    uVar1 = 0;
  }
  return uVar1;
}


void GetTypeCallback(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  code **ppcVar9;
  undefined8 uVar10;
  
  iVar7 = param_1 * 4;
  puVar8 = (uint *)(&Type + iVar7);
  *puVar8 = *puVar8 & 0xffffff7f;
  *puVar8 = *puVar8 | param_2;
  uVar10 = os::__OSGetSystemTime();
  *(int *)(&DAT_803f0e94 + param_1 * 8) = (int)uVar10;
  *(int *)(&TypeTime + param_1 * 8) = (int)((ulonglong)uVar10 >> 0x20);
  uVar6 = *puVar8;
  uVar1 = __PADFixBits & ~(0x80000000U >> param_1);
  uVar4 = __PADFixBits & 0x80000000U >> param_1;
  __PADFixBits = uVar1;
  if (((((param_2 & 0xf) == 0) && ((uVar6 & 0x18000000) == 0x8000000)) &&
      ((uVar6 & 0x80000000) != 0)) && ((uVar6 & 0x4000000) == 0)) {
    iVar2 = os::OSGetWirelessID(param_1);
    uVar1 = iVar2 << 8;
    uVar5 = uVar1 & 0xffff00;
    if ((uVar4 == 0) || ((uVar1 & 0x100000) == 0)) {
      if ((uVar6 & 0x100000) == 0) {
        if ((uVar6 & 0x40000000) != 0) {
          os::OSSetWirelessID(param_1,(uVar6 & 0xcfff00 | 0x100000) >> 8);
          *(uint *)(&cmdFixDevice_327 + iVar7) = uVar6 & 0xcfff00 | 0x4e100000;
          *puVar8 = 0x80;
          SITransfer(param_1,&cmdFixDevice_327 + iVar7,3,puVar8,3,GetTypeCallback,0,0);
          return;
        }
        os::OSSetWirelessID(param_1,0);
      }
      else {
        if ((uVar1 & 0xcfff00) != (uVar6 & 0xcfff00)) {
          if ((uVar1 & 0x100000) == 0) {
            uVar5 = uVar6 & 0xcfff00 | 0x100000;
            os::OSSetWirelessID(param_1,(uVar6 & 0xcfff00 | 0x100000) >> 8);
          }
          *(uint *)(&cmdFixDevice_327 + iVar7) = uVar5 | 0x4e000000;
          *puVar8 = 0x80;
          SITransfer(param_1,&cmdFixDevice_327 + iVar7,3,puVar8,3,GetTypeCallback,0,0);
          return;
        }
      }
      uVar1 = *puVar8;
      iVar7 = 0;
      ppcVar9 = (code **)(&TypeCallback + param_1 * 0x10);
      do {
        pcVar3 = *ppcVar9;
        if (pcVar3 != (code *)0x0) {
          *ppcVar9 = (code *)0x0;
          (*pcVar3)(param_1,uVar1);
        }
        iVar7 = iVar7 + 1;
        ppcVar9 = ppcVar9 + 1;
      } while (iVar7 < 4);
    }
    else {
      *(uint *)(&cmdFixDevice_327 + iVar7) = uVar1 & 0xcfff00 | 0x4e100000;
      *puVar8 = 0x80;
      SITransfer(param_1,&cmdFixDevice_327 + iVar7,3,puVar8,3,GetTypeCallback,0,0);
    }
  }
  else {
    os::OSSetWirelessID(param_1,0);
    uVar1 = *puVar8;
    iVar7 = 0;
    ppcVar9 = (code **)(&TypeCallback + param_1 * 0x10);
    do {
      pcVar3 = *ppcVar9;
      if (pcVar3 != (code *)0x0) {
        *ppcVar9 = (code *)0x0;
        (*pcVar3)(param_1,uVar1);
      }
      iVar7 = iVar7 + 1;
      ppcVar9 = ppcVar9 + 1;
    } while (iVar7 < 4);
  }
  return;
}


int SIGetType(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined8 uVar8;
  
  uVar3 = os::OSDisableInterrupts();
  piVar6 = (int *)(&Type + param_1 * 4);
  iVar5 = *piVar6;
  uVar8 = os::__OSGetSystemTime();
  iVar1 = param_1 * 8;
  piVar7 = (int *)(&TypeTime + iVar1);
  uVar4 = (uint)uVar8 - *(uint *)(&DAT_803f0e94 + iVar1);
  uVar2 = (int)((ulonglong)uVar8 >> 0x20) -
          ((uint)((uint)uVar8 < *(uint *)(&DAT_803f0e94 + iVar1)) + *piVar7);
  if ((DAT_803a0770 & 0x80 >> (param_1 & 0x3f)) == 0) {
    if (((uint)(((DAT_800000f8 >> 2) / 1000) * 0x32 < uVar4) + (uVar2 ^ 0x80000000) < 0x80000001) &&
       (iVar5 != 8)) {
      os::OSRestoreInterrupts(uVar3);
      return iVar5;
    }
    if ((uint)(((DAT_800000f8 >> 2) / 1000) * 0x4b < uVar4) + (uVar2 ^ 0x80000000) < 0x80000001) {
      *piVar6 = 0x80;
    }
    else {
      *piVar6 = 0x80;
      iVar5 = 0x80;
    }
  }
  else {
    if (iVar5 != 8) {
      uVar8 = os::__OSGetSystemTime();
      *(int *)(&DAT_803f0e94 + iVar1) = (int)uVar8;
      *piVar7 = (int)((ulonglong)uVar8 >> 0x20);
      os::OSRestoreInterrupts(uVar3);
      return iVar5;
    }
    *piVar6 = 0x80;
    iVar5 = 0x80;
  }
  uVar8 = os::__OSGetSystemTime();
  *(int *)(&DAT_803f0e94 + iVar1) = (int)uVar8;
  *piVar7 = (int)((ulonglong)uVar8 >> 0x20);
  SITransfer(param_1,&cmdTypeAndStatus_372,1,piVar6,3,GetTypeCallback,0,
             ((DAT_800000f8 >> 2) / 0x1e848) * 0x41 >> 3);
  os::OSRestoreInterrupts(uVar3);
  return iVar5;
}


undefined4 SIGetTypeAsync(int param_1,code *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = os::OSDisableInterrupts();
  uVar3 = SIGetType(param_1);
  if ((*(uint *)(&Type + param_1 * 4) & 0x80) == 0) {
    (*param_2)(param_1,uVar3);
  }
  else {
    param_1 = param_1 * 0x10;
    pcVar1 = *(code **)(&TypeCallback + param_1);
    if (pcVar1 != param_2) {
      if (pcVar1 == (code *)0x0) {
        *(code **)(&TypeCallback + param_1) = param_2;
      }
      else {
        if (*(code **)(&DAT_803f0ed4 + param_1) != param_2) {
          if (*(code **)(&DAT_803f0ed4 + param_1) == (code *)0x0) {
            *(code **)(&DAT_803f0ed4 + param_1) = param_2;
          }
          else {
            if (*(code **)(&DAT_803f0ed8 + param_1) != param_2) {
              if (*(code **)(&DAT_803f0ed8 + param_1) == (code *)0x0) {
                *(code **)(&DAT_803f0ed8 + param_1) = param_2;
              }
              else {
                if ((*(code **)(&DAT_803f0edc + param_1) != param_2) &&
                   (*(code **)(&DAT_803f0edc + param_1) == (code *)0x0)) {
                  *(code **)(&DAT_803f0edc + param_1) = param_2;
                }
              }
            }
          }
        }
      }
    }
  }
  os::OSRestoreInterrupts(uVar2);
  return uVar3;
}


uint SIDecodeType(uint param_1)

{
  uint uVar1;
  
  if ((param_1 & 8) != 0) {
    return 8;
  }
  if ((param_1 & 0x47) != 0) {
    return 0x40;
  }
  if ((param_1 & 0xff) != 0) {
    return 0x80;
  }
  if ((param_1 & 0x18000000) != 0) {
    if ((param_1 & 0x18000000) != 0x8000000) {
      return 0x40;
    }
    uVar1 = param_1 & 0xffff0000;
    if (uVar1 == 0x9000000) {
      return uVar1;
    }
    if (((int)uVar1 < 0x9000000) && (uVar1 == 0x8000000)) {
      return uVar1;
    }
    if ((param_1 & 0xffe00000) == 0x8200000) {
      return 0x8200000;
    }
    if (((param_1 & 0x80000000) != 0) && ((param_1 & 0x4000000) == 0)) {
      if ((param_1 & 0x8b100000) == 0x8b100000) {
        return 0x8b100000;
      }
      if ((param_1 & 0x2000000) == 0) {
        return 0x88000000;
      }
    }
    if ((param_1 & 0x9000000) != 0x9000000) {
      return 0x40;
    }
    return 0x9000000;
  }
  param_1 = param_1 & 0xffff0000;
  if (param_1 == 0x40000) {
    return param_1;
  }
  if ((int)param_1 < 0x40000) {
    if (param_1 == 0x20000) {
      return param_1;
    }
    if (((int)param_1 < 0x20000) && (param_1 == 0x10000)) {
      return param_1;
    }
  }
  else {
    if (param_1 == 0x5000000) {
      return param_1;
    }
    if (((int)param_1 < 0x5000000) && (param_1 == 0x2000000)) {
      return param_1;
    }
  }
  return 0x40;
}


void SIProbe(void)

{
  SIGetType();
  SIDecodeType();
  return;
}

