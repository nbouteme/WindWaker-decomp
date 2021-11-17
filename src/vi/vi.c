#include <vi/vi.h>
#include <os/OSContext.h>
#include <vi/vi.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <si/SISamplingRate.h>
#include <os/OSThread.h>
#include <os/OSInterrupt.h>
#include <os/OS.h>
#include <os/OSRtc.h>
#include <m_Do_printf.h>


namespace vi {
undefined2 regs;
undefined shdwRegs;
undefined2 HorVer;
undefined4 IsInitialized;
undefined4 retraceCount;
undefined4 flushFlag;
undefined retraceQueue;
undefined4 PreCB;
undefined4 PostCB;
undefined4 encoderType;
undefined2 displayOffsetH;
undefined2 displayOffsetV;
undefined4 changeMode;
undefined4 changed;
undefined4 shdwChangeMode;
undefined4 shdwChanged;
undefined4 CurrTiming;
undefined4 CurrTvMode;
undefined4 NextBufAddr;
undefined4 CurrBufAddr;
undefined4 FBSet;
undefined4 message$341;

void __VIRetraceHandler(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r4;
  bool bVar4;
  undefined8 uVar5;
  undefined auStack736 [716];
  
  if ((DAT_cc002030 & 0x8000) != 0) {
    DAT_cc002030 = DAT_cc002030 & 0x7fff;
  }
  if ((DAT_cc002034 & 0x8000) != 0) {
    DAT_cc002034 = DAT_cc002034 & 0x7fff;
  }
  bVar4 = (DAT_cc002038 & 0x8000) != 0;
  if (bVar4) {
    DAT_cc002038 = DAT_cc002038 & 0x7fff;
  }
  bVar1 = (DAT_cc00203c & 0x8000) != 0;
  if (bVar1) {
    DAT_cc00203c = DAT_cc00203c & 0x7fff;
  }
  if ((bVar4) || (bVar1)) {
    os::OSSetCurrentContext(param_2);
  }
  else {
    retraceCount = retraceCount + 1;
    os::OSClearContext(auStack736);
    os::OSSetCurrentContext(auStack736);
    if (PreCB != (code *)0x0) {
      (*PreCB)(retraceCount);
    }
    if (flushFlag != 0) {
      if ((shdwChangeMode == 1) && (iVar3 = getCurrentFieldEvenOdd(), iVar3 == 0)) {
        bVar4 = false;
      }
      else {
        for (; uVar2 = DAT_803f7b74, (DAT_803f7b74 | shdwChanged) != 0;
            DAT_803f7b74 = DAT_803f7b74 & ~(uint)uVar5) {
          Runtime.PPCEABI.H::__shr2u(shdwChanged,DAT_803f7b74,0x20);
          iVar3 = countLeadingZeros(extraout_r4);
          if (0x1f < iVar3) {
            iVar3 = countLeadingZeros(uVar2);
            iVar3 = iVar3 + 0x20;
          }
          (&DAT_cc002000)[iVar3] = *(undefined2 *)(&shdwRegs + iVar3 * 2);
          uVar5 = Runtime.PPCEABI.H::__shl2i(0,1,0x3f - iVar3);
          shdwChanged = shdwChanged & ~(uint)((ulonglong)uVar5 >> 0x20);
        }
        shdwChangeMode = 0;
        bVar4 = true;
        CurrTiming = DAT_803f12ac;
        CurrTvMode = DAT_803f1280;
        CurrBufAddr = NextBufAddr;
      }
      if (bVar4) {
        flushFlag = 0;
        si::SIRefreshSamplingRate();
      }
    }
    if (PostCB != (code *)0x0) {
      os::OSClearContext(auStack736);
      (*PostCB)(retraceCount);
    }
    os::OSWakeupThread(&retraceQueue);
    os::OSClearContext(auStack736);
    os::OSSetCurrentContext(param_2);
  }
  return;
}


undefined4 VISetPreRetraceCallback(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = PreCB;
  os::OSDisableInterrupts();
  PreCB = param_1;
  os::OSRestoreInterrupts();
  return uVar1;
}


undefined4 VISetPostRetraceCallback(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = PostCB;
  os::OSDisableInterrupts();
  PostCB = param_1;
  os::OSRestoreInterrupts();
  return uVar1;
}


undefined * getTiming(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    return &timing;
  case 1:
    return &DAT_803a0f82;
  case 2:
    return &DAT_803a1040;
  case 3:
    return &DAT_803a1066;
  case 4:
    return &DAT_803a0fa8;
  case 5:
    return &DAT_803a0fce;
  default:
    return (undefined *)0x0;
  case 8:
    return &DAT_803a0ff4;
  case 9:
    return &DAT_803a101a;
  case 0x10:
    return &DAT_803a0fa8;
  case 0x11:
    return &DAT_803a0fce;
  case 0x14:
    return &timing;
  case 0x15:
    return &DAT_803a0f82;
  case 0x18:
    return &DAT_803a108c;
  case 0x1a:
    return &DAT_803a10b2;
  }
}


void __VIInit(uint param_1)

{
  uint uVar1;
  byte *pbVar2;
  uint local_14;
  
  uVar1 = param_1 >> 2;
  DAT_800000cc = uVar1;
  pbVar2 = (byte *)getTiming(param_1);
  for (local_14 = 0; local_14 < 1000; local_14 = local_14 + 8) {
  }
  if (((param_1 == 2) || (param_1 == 3)) || (param_1 == 0x1a)) {
    DAT_cc002002 = (ushort)(uVar1 << 8) | 5;
    DAT_cc00206c = 1;
  }
  else {
    DAT_cc002002 = (ushort)((param_1 & 2) << 2) | 1 | (ushort)(uVar1 << 8);
    DAT_cc00206c = 0;
  }
  DAT_cc002000 = (ushort)*pbVar2;
  DAT_cc002004 = *(undefined2 *)(pbVar2 + 0x1d);
  DAT_cc002006 = *(undefined2 *)(pbVar2 + 0x1a);
  DAT_cc002008 = *(short *)(pbVar2 + 0x20) << 1;
  DAT_cc00200a = (ushort)pbVar2[0x1c] | (ushort)pbVar2[0x1f] << 7;
  DAT_cc00200c = *(short *)(pbVar2 + 8) + 2;
  DAT_cc00200e = *(short *)(pbVar2 + 4) + *(short *)(pbVar2 + 2) * 2 + -2;
  DAT_cc002010 = *(short *)(pbVar2 + 10) + 2;
  DAT_cc002012 = *(short *)(pbVar2 + 6) + *(short *)(pbVar2 + 2) * 2 + -2;
  DAT_cc002014 = (ushort)pbVar2[0xe] | *(short *)(pbVar2 + 0x14) << 5;
  DAT_cc002016 = (ushort)pbVar2[0xc] | *(short *)(pbVar2 + 0x10) << 5;
  DAT_cc002018 = (ushort)pbVar2[0xf] | *(short *)(pbVar2 + 0x16) << 5;
  DAT_cc00201a = (ushort)pbVar2[0xd] | *(short *)(pbVar2 + 0x12) << 5;
  DAT_cc002030 = (short)((int)(uint)*(ushort *)(pbVar2 + 0x18) >> 1) + 1U | 0x1000;
  DAT_cc002032 = *(short *)(pbVar2 + 0x1a) + 1;
  DAT_cc002034 = 0x1001;
  DAT_cc002036 = 1;
  DAT_cc002048 = 0x2828;
  return;
}


void VIInit(void)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  short sVar8;
  int iVar7;
  short sVar9;
  
  if (IsInitialized == 0) {
    os::OSRegisterVersion(__VIVersion);
    IsInitialized = 1;
    encoderType = 1;
    if ((DAT_cc002002 & 1) == 0) {
      __VIInit(0);
    }
    retraceCount = 0;
    DAT_803f7b64 = 0;
    changed = 0;
    DAT_803f7b74 = 0;
    shdwChanged = 0;
    changeMode = 0;
    shdwChangeMode = 0;
    flushFlag = 0;
    DAT_cc00204e = taps | DAT_803a10da << 10;
    DAT_cc00204c = (ushort)((int)(uint)DAT_803a10da >> 6) | DAT_803a10dc << 4;
    DAT_cc002052 = DAT_803a10de | DAT_803a10e0 << 10;
    DAT_cc002050 = (ushort)((int)(uint)DAT_803a10e0 >> 6) | DAT_803a10e2 << 4;
    DAT_cc002056 = DAT_803a10e4 | DAT_803a10e6 << 10;
    DAT_cc002054 = (ushort)((int)(uint)DAT_803a10e6 >> 6) | DAT_803a10e8 << 4;
    DAT_cc00205a = DAT_803a10ea | DAT_803a10ec << 8;
    DAT_cc002058 = DAT_803a10ee | DAT_803a10f0 << 8;
    DAT_cc00205e = DAT_803a10f2 | DAT_803a10f4 << 8;
    DAT_cc00205c = DAT_803a10f6 | DAT_803a10f8 << 8;
    DAT_cc002062 = DAT_803a10fa | DAT_803a10fc << 8;
    DAT_cc002060 = DAT_803a10fe | DAT_803a1100 << 8;
    DAT_cc002066 = DAT_803a1102 | DAT_803a1104 << 8;
    DAT_cc002064 = DAT_803a1106 | DAT_803a1108 << 8;
    DAT_cc002070 = 0x280;
    iVar3 = os::__OSLockSram();
    displayOffsetV = 0;
    displayOffsetH = (short)*(char *)(iVar3 + 0x10);
    os::__OSUnlockSram(0);
    uVar2 = DAT_cc002002;
    DAT_803f127c = DAT_cc002002 >> 2 & 1;
    DAT_803f1280 = DAT_cc002002 >> 8 & 3;
    if ((DAT_800000cc == 1) && ((DAT_cc002002 >> 8 & 3) == 0)) {
      DAT_803f1280 = 5;
    }
    uVar4 = DAT_803f1280;
    if (DAT_803f1280 == 3) {
      uVar4 = 0;
    }
    DAT_803f12ac = getTiming(uVar4 * 4 + DAT_803f127c);
    DAT_803f116a = uVar2;
    CurrTvMode = DAT_803f1280;
    DAT_803f125c = 0x280;
    puVar1 = (ushort *)(DAT_803f12ac + 2);
    DAT_803f125e = *puVar1 * 2;
    HorVer = 0x28;
    DAT_803f125a = 0;
    DAT_803f1260 = 0x50;
    iVar3 = displayOffsetH + 0x28;
    if (iVar3 < 0x51) {
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      DAT_803f1260 = (undefined2)iVar3;
    }
    if (DAT_803f1278 == 0) {
      iVar3 = 2;
    }
    else {
      iVar3 = 1;
    }
    iVar5 = (int)displayOffsetV;
    DAT_803f1262 = 0;
    if (0 < iVar5) {
      DAT_803f1262 = displayOffsetV;
    }
    iVar6 = (int)(short)*puVar1;
    if (DAT_803f125e + iVar5 + iVar6 * -2 < 1) {
      sVar9 = 0;
    }
    else {
      sVar9 = (short)(DAT_803f125e + iVar5) + *puVar1 * -2;
    }
    sVar8 = displayOffsetV;
    if (-1 < iVar5) {
      sVar8 = 0;
    }
    DAT_803f1264 = (DAT_803f125e + sVar8) - sVar9;
    iVar7 = iVar5;
    if (-1 < iVar5) {
      iVar7 = 0;
    }
    DAT_803f1266 = DAT_803f1270 - (short)(iVar7 / iVar3);
    if (DAT_803f125e + iVar5 + iVar6 * -2 < 1) {
      iVar6 = 0;
    }
    else {
      iVar6 = DAT_803f125e + iVar5 + iVar6 * -2;
    }
    if (-1 < iVar5) {
      iVar5 = 0;
    }
    DAT_803f1268 = (DAT_803f1274 + (short)(iVar5 / iVar3)) - (short)(iVar6 / iVar3);
    DAT_803f126a = 0x280;
    DAT_803f126c = (undefined2)((*puVar1 & 0x7fff) << 1);
    DAT_803f126e = 0;
    DAT_803f1270 = 0;
    DAT_803f1272 = 0x280;
    DAT_803f1274 = (short)((*puVar1 & 0x7fff) << 1);
    DAT_803f1278 = 0;
    DAT_803f1284 = 0x28;
    DAT_803f1285 = 0x28;
    DAT_803f1286 = 0x28;
    DAT_803f1294 = 0;
    DAT_803f1298 = 1;
    DAT_803f129c = 0;
    CurrTiming = DAT_803f12ac;
    os::OSInitThreadQueue(&retraceQueue);
    DAT_cc002030 = DAT_cc002030 & 0x7fff;
    DAT_cc002034 = DAT_cc002034 & 0x7fff;
    PreCB = 0;
    PostCB = 0;
    os::__OSSetInterruptHandler(0x18,__VIRetraceHandler);
    os::__OSUnmaskInterrupts(0x80);
  }
  return;
}


void VIWaitForRetrace(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = os::OSDisableInterrupts();
  iVar1 = retraceCount;
  do {
    os::OSSleepThread(&retraceQueue);
  } while (iVar1 == retraceCount);
  os::OSRestoreInterrupts(uVar2);
  return;
}


void setFbbRegs(int param_1,uint *param_2,uint *param_3,uint *param_4,uint *param_5)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (uint)*(byte *)(param_1 + 0x2c) * 0x20;
  iVar4 = *(int *)(param_1 + 0x20);
  uVar1 = *(ushort *)(param_1 + 10);
  *param_2 = *(int *)(param_1 + 0x30) +
             (*(ushort *)(param_1 + 0x16) & 0x7ffffff0) * 2 +
             iVar3 * (uint)*(ushort *)(param_1 + 0xe);
  if (iVar4 == 0) {
    uVar2 = *param_2;
  }
  else {
    uVar2 = *param_2 + iVar3;
  }
  *param_3 = uVar2;
  if ((uint)uVar1 + ((int)(uint)uVar1 >> 1) * -2 == 1) {
    uVar2 = *param_2;
    *param_2 = *param_3;
    *param_3 = uVar2;
  }
  *param_2 = *param_2 & 0x3fffffff;
  *param_3 = *param_3 & 0x3fffffff;
  if (*(int *)(param_1 + 0x44) != 0) {
    iVar3 = (uint)*(byte *)(param_1 + 0x2c) * 0x20;
    iVar4 = *(int *)(param_1 + 0x20);
    uVar1 = *(ushort *)(param_1 + 10);
    *param_4 = *(int *)(param_1 + 0x48) +
               (*(ushort *)(param_1 + 0x16) & 0x7ffffff0) * 2 +
               iVar3 * (uint)*(ushort *)(param_1 + 0xe);
    if (iVar4 == 0) {
      uVar2 = *param_4;
    }
    else {
      uVar2 = *param_4 + iVar3;
    }
    *param_5 = uVar2;
    if ((uint)uVar1 + ((int)(uint)uVar1 >> 1) * -2 == 1) {
      uVar2 = *param_4;
      *param_4 = *param_5;
      *param_5 = uVar2;
    }
    *param_4 = *param_4 & 0x3fffffff;
    *param_5 = *param_5 & 0x3fffffff;
  }
  if ((((*param_2 < 0x1000000) && (*param_3 < 0x1000000)) && (*param_4 < 0x1000000)) &&
     (*param_5 < 0x1000000)) {
    iVar3 = 0;
  }
  else {
    iVar3 = 1;
  }
  if (iVar3 != 0) {
    *param_2 = *param_2 >> 5;
    *param_3 = *param_3 >> 5;
    *param_4 = *param_4 >> 5;
    *param_5 = *param_5 >> 5;
  }
  uVar2 = changed | 0x33000;
  if (*(int *)(param_1 + 0x44) != 0) {
    DAT_803f118a = (undefined2)*param_4;
    DAT_803f1188 = (undefined2)(*param_4 >> 0x10);
    DAT_803f1192 = (undefined2)*param_5;
    DAT_803f1190 = (undefined2)(*param_5 >> 0x10);
    uVar2 = changed | 0x3fc00;
  }
  changed = uVar2;
  DAT_803f1184 = (ushort)(iVar3 << 0xc) |
                 (ushort)(*param_2 >> 0x10) | (ushort)*(byte *)(param_1 + 0x3c) << 8;
  DAT_803f1186 = (short)*param_2;
  DAT_803f118c = (short)(*param_3 >> 0x10);
  DAT_803f118e = (short)*param_3;
  return;
}


void setVerticalRegs(uint param_1,ushort param_2,ushort param_3,short param_4,short param_5,
                        short param_6,short param_7,short param_8,int param_9)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  short sVar4;
  
  if ((DAT_803f11d4 & 1) == 0) {
    uVar3 = 2;
    sVar4 = 1;
  }
  else {
    uVar3 = 1;
    sVar4 = 2;
  }
  param_1 = param_1 & 0xffff;
  sVar2 = (short)param_1;
  if (param_1 == ((int)param_1 >> 1) * 2) {
    sVar1 = sVar4 * (((short)uVar3 * param_4 - param_2) - sVar2);
    DAT_803f1176 = param_5 + sVar4 * sVar2;
    DAT_803f1174 = param_7 + sVar1;
    DAT_803f117a = param_6 + sVar4 * sVar2;
    DAT_803f1178 = param_8 + sVar1;
  }
  else {
    sVar1 = sVar4 * (((short)uVar3 * param_4 - param_2) - sVar2);
    DAT_803f1176 = param_6 + sVar4 * sVar2;
    DAT_803f1174 = param_8 + sVar1;
    DAT_803f117a = param_5 + sVar4 * sVar2;
    DAT_803f1178 = param_7 + sVar1;
  }
  uVar3 = param_2 / uVar3;
  if (param_9 != 0) {
    sVar4 = (short)uVar3 * 2 + -2;
    DAT_803f1176 = DAT_803f1176 + sVar4;
    DAT_803f117a = DAT_803f117a + sVar4;
    uVar3 = 0;
    DAT_803f1174 = DAT_803f1174 + 2;
    DAT_803f1178 = DAT_803f1178 + 2;
  }
  regs = param_3 & 0xff | (ushort)(uVar3 << 4);
  changed = changed | 0x83c00000;
  return;
}


void VIConfigure(uint *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ushort uVar9;
  uint uVar8;
  int iVar10;
  short sVar11;
  short sVar12;
  int iVar13;
  
  uVar2 = os::OSDisableInterrupts();
  uVar6 = DAT_800000cc;
  if (DAT_803f127c != (*param_1 & 3)) {
    changeMode = 1;
    DAT_803f127c = *param_1 & 3;
  }
  uVar4 = *param_1 >> 2;
  if ((uVar4 == 4) && (message_341 == 0)) {
    message_341 = 1;
    m_Do_printf::OSReport(_345);
    m_Do_printf::OSReport(_346);
    m_Do_printf::OSReport(_347);
    m_Do_printf::OSReport(_348);
    m_Do_printf::OSReport(_349);
    m_Do_printf::OSReport(_350);
    m_Do_printf::OSReport(_345);
  }
  if (uVar6 == 2) {
LAB_80313fd4:
    if (((uVar4 == 0) || (uVar4 == 2)) || (uVar4 == 6)) goto LAB_8031401c;
  }
  else {
    if ((int)uVar6 < 2) {
      if (uVar6 == 0) goto LAB_80313fd4;
      if (-1 < (int)uVar6) {
LAB_80313ff0:
        if ((uVar4 == 1) || (uVar4 == 5)) goto LAB_8031401c;
      }
    }
    else {
      if (uVar6 == 6) goto LAB_80313fd4;
      if (((int)uVar6 < 6) && (4 < (int)uVar6)) goto LAB_80313ff0;
    }
  }
  m_Do_printf::OSPanic(&_532,0x75c,_533,uVar6,uVar4);
LAB_8031401c:
  if ((uVar4 == 0) || (DAT_803f1280 = uVar4, uVar4 == 2)) {
    DAT_803f1280 = uVar6;
  }
  HorVer = *(short *)((int)param_1 + 10);
  if (DAT_803f127c == 1) {
    DAT_803f125a = *(short *)(param_1 + 3) << 1;
  }
  else {
    DAT_803f125a = *(ushort *)(param_1 + 3);
  }
  DAT_803f125c = *(ushort *)((int)param_1 + 0xe);
  DAT_803f126a = *(ushort *)(param_1 + 1);
  DAT_803f126c = *(short *)(param_1 + 2);
  DAT_803f1278 = param_1[5];
  DAT_803f126e = 0;
  DAT_803f1270 = 0;
  DAT_803f125e = DAT_803f126c;
  if (((DAT_803f127c != 2) && (DAT_803f127c != 3)) && (DAT_803f1278 == 0)) {
    DAT_803f125e = DAT_803f126c << 1;
  }
  DAT_803f129c = (uint)(DAT_803f127c == 3);
  DAT_803f1272 = DAT_803f126a;
  DAT_803f1274 = DAT_803f126c;
  puVar3 = (undefined *)getTiming(DAT_803f1280 * 4 + DAT_803f127c);
  uVar6 = 0x2d0 - DAT_803f125c;
  uVar4 = (int)HorVer + (int)displayOffsetH;
  if (((int)uVar4 <= (int)uVar6) && (uVar6 = uVar4, (int)uVar4 < 0)) {
    uVar6 = 0;
  }
  DAT_803f1260 = (undefined2)uVar6;
  if (DAT_803f1278 == 0) {
    iVar5 = 2;
  }
  else {
    iVar5 = 1;
  }
  iVar10 = (int)displayOffsetV;
  uVar7 = DAT_803f125a & 1;
  uVar4 = uVar7;
  if ((int)uVar7 < (short)DAT_803f125a + iVar10) {
    uVar4 = (short)DAT_803f125a + iVar10;
  }
  DAT_803f1262 = (undefined2)uVar4;
  iVar1 = *(short *)(puVar3 + 2) * 2 - uVar7;
  iVar13 = (int)(short)DAT_803f125a + DAT_803f125e + iVar10;
  if (iVar13 - iVar1 < 1) {
    sVar12 = 0;
  }
  else {
    sVar12 = (short)iVar13 - (short)iVar1;
  }
  iVar13 = (short)DAT_803f125a + iVar10;
  if ((int)(iVar13 - uVar7) < 0) {
    sVar11 = (short)iVar13 - (short)uVar7;
  }
  else {
    sVar11 = 0;
  }
  DAT_803f1264 = (DAT_803f125e + sVar11) - sVar12;
  if ((int)(((short)DAT_803f125a + iVar10) - uVar7) < 0) {
    iVar13 = ((short)DAT_803f125a + iVar10) - uVar7;
  }
  else {
    iVar13 = 0;
  }
  DAT_803f1266 = DAT_803f1270 - (short)(iVar13 / iVar5);
  iVar13 = (int)(short)DAT_803f125a + DAT_803f125e + iVar10;
  if (iVar13 - iVar1 < 1) {
    iVar13 = 0;
  }
  else {
    iVar13 = iVar13 - iVar1;
  }
  iVar10 = (short)DAT_803f125a + iVar10;
  if ((int)(iVar10 - uVar7) < 0) {
    iVar10 = iVar10 - uVar7;
  }
  else {
    iVar10 = 0;
  }
  DAT_803f1268 = (DAT_803f1274 + (short)(iVar10 / iVar5)) - (short)(iVar13 / iVar5);
  if (encoderType == 0) {
    DAT_803f1280 = 3;
  }
  iVar5 = (int)(uint)*(ushort *)(puVar3 + 0x18) >> 1;
  if (((uint)*(ushort *)(puVar3 + 0x18) + iVar5 * -2 & 0xffff) == 0) {
    sVar12 = 0;
  }
  else {
    sVar12 = *(short *)(puVar3 + 0x1a);
  }
  DAT_803f119a = sVar12 + 1;
  DAT_803f1198 = (short)iVar5 + 1U | 0x1000;
  if ((DAT_803f127c == 2) || (DAT_803f127c == 3)) {
    uVar9 = DAT_803f116a & 0xfffb | 4;
  }
  else {
    uVar9 = (ushort)((DAT_803f127c & 1) << 2) | DAT_803f116a & 0xfffb;
  }
  uVar9 = uVar9 & 0xfff7 | (ushort)(DAT_803f129c << 3);
  if ((DAT_803f1280 == 4) || (DAT_803f1280 - 5 < 2)) {
    DAT_803f116a = uVar9 & 0xfcff;
  }
  else {
    DAT_803f116a = uVar9 & 0xfcff | (ushort)(DAT_803f1280 << 8);
  }
  uVar4 = *param_1;
  if (((uVar4 == 2) || (uVar4 == 3)) || (uVar4 == 0x1a)) {
    DAT_803f11d4 = DAT_803f11d4 & 0xfffe | 1;
  }
  else {
    DAT_803f11d4 = DAT_803f11d4 & 0xfffe;
  }
  uVar7 = (uint)DAT_803f125c;
  uVar8 = (uint)DAT_803f1272;
  uVar4 = uVar8;
  if (DAT_803f129c != 0) {
    uVar4 = uVar8 << 1;
  }
  uVar4 = uVar4 & 0xffff;
  if (uVar4 < uVar7) {
    DAT_803f11b2 = (ushort)((uVar7 + uVar4 * 0x100 + -1) / uVar7) | 0x1000;
    DAT_803f11d8 = (undefined2)uVar4;
    DAT_803f7b64 = DAT_803f7b64 | 0x4000280;
  }
  else {
    DAT_803f11b2 = 0x100;
    DAT_803f7b64 = DAT_803f7b64 | 0x4000200;
  }
  DAT_803f116e = *(undefined2 *)(puVar3 + 0x1a);
  DAT_803f116c = *(undefined2 *)(puVar3 + 0x1d);
  uVar4 = ((uint)(byte)puVar3[0x1f] + (uVar6 & 0xffff)) - 0x28;
  DAT_803f1172 = (ushort)(byte)puVar3[0x1c] | (short)uVar4 * 0x80;
  DAT_803f1170 = (ushort)(uVar4 >> 9) |
                 ((*(short *)(puVar3 + 0x20) + (short)(uVar6 & 0xffff) + 0x28) -
                 (0x2d0 - DAT_803f125c)) * 2;
  DAT_803f117e = (ushort)(byte)puVar3[0xc] | *(short *)(puVar3 + 0x10) << 5;
  DAT_803f117c = (ushort)(byte)puVar3[0xe] | *(short *)(puVar3 + 0x14) << 5;
  DAT_803f1182 = (ushort)(byte)puVar3[0xd] | *(short *)(puVar3 + 0x12) << 5;
  DAT_803f1180 = (ushort)(byte)puVar3[0xf] | *(short *)(puVar3 + 0x16) << 5;
  changed = changed | 0x7c3c00c0;
  DAT_803f1284 = (char)((int)(DAT_803f126a + 0xf) >> 4);
  DAT_803f1285 = DAT_803f1284;
  if (DAT_803f1278 != 0) {
    DAT_803f1285 = DAT_803f1284 << 1;
  }
  DAT_803f1294 = (char)DAT_803f126e + (char)((int)(uint)DAT_803f126e >> 4) * -0x10;
  DAT_803f1286 = (undefined)((int)((uint)DAT_803f1294 + uVar8 + 0xf) >> 4);
  DAT_803f11b0 = CONCAT11(DAT_803f1286,DAT_803f1285);
  DAT_803f7b64 = DAT_803f7b64 | 0x8000000;
  DAT_803f12ac = puVar3;
  if (FBSet != 0) {
    setFbbRegs(&HorVer,&DAT_803f128c,&DAT_803f1290,&DAT_803f12a4,&DAT_803f12a8);
  }
  setVerticalRegs(DAT_803f1262,DAT_803f1264,*puVar3,*(undefined2 *)(puVar3 + 2),
                  *(undefined2 *)(puVar3 + 4),*(undefined2 *)(puVar3 + 6),
                  *(undefined2 *)(puVar3 + 8),*(undefined2 *)(puVar3 + 10),DAT_803f1298);
  os::OSRestoreInterrupts(uVar2);
  return;
}


void VIFlush(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 extraout_r4;
  int iVar3;
  undefined8 uVar4;
  
  uVar2 = os::OSDisableInterrupts();
  shdwChangeMode = shdwChangeMode | changeMode;
  changeMode = 0;
  shdwChanged = shdwChanged | changed;
  DAT_803f7b74 = DAT_803f7b74 | DAT_803f7b64;
  for (; uVar1 = DAT_803f7b64, (DAT_803f7b64 | changed) != 0;
      DAT_803f7b64 = DAT_803f7b64 & ~(uint)uVar4) {
    Runtime.PPCEABI.H::__shr2u(changed,DAT_803f7b64,0x20);
    iVar3 = countLeadingZeros(extraout_r4);
    if (0x1f < iVar3) {
      iVar3 = countLeadingZeros(uVar1);
      iVar3 = iVar3 + 0x20;
    }
    *(undefined2 *)(&shdwRegs + iVar3 * 2) = (&regs)[iVar3];
    uVar4 = Runtime.PPCEABI.H::__shl2i(0,1,0x3f - iVar3);
    changed = changed & ~(uint)((ulonglong)uVar4 >> 0x20);
  }
  flushFlag = 1;
  NextBufAddr = DAT_803f1288;
  os::OSRestoreInterrupts(uVar2);
  return;
}


void VISetNextFrameBuffer(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = os::OSDisableInterrupts();
  FBSet = 1;
  DAT_803f1288 = param_1;
  setFbbRegs(&HorVer,&DAT_803f128c,&DAT_803f1290,&DAT_803f12a4,&DAT_803f12a8);
  os::OSRestoreInterrupts(uVar1);
  return;
}


void VISetBlack(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = os::OSDisableInterrupts();
  DAT_803f1298 = param_1;
  setVerticalRegs(DAT_803f1262,DAT_803f125e,*DAT_803f12ac,*(undefined2 *)(DAT_803f12ac + 2),
                  *(undefined2 *)(DAT_803f12ac + 4),*(undefined2 *)(DAT_803f12ac + 6),
                  *(undefined2 *)(DAT_803f12ac + 8),*(undefined2 *)(DAT_803f12ac + 10),param_1);
  os::OSRestoreInterrupts(uVar1);
  return;
}


undefined4 VIGetRetraceCount(void)

{
  return retraceCount;
}


undefined4 getCurrentFieldEvenOdd(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = DAT_cc00202c & 0x7ff;
  do {
    uVar3 = DAT_cc00202c & 0x7ff;
    bVar1 = uVar2 != uVar3;
    uVar2 = uVar3;
  } while (bVar1);
  if ((uVar3 - 1) * 2 + ((DAT_cc00202e & 0x7ff) - 1) / (uint)*(ushort *)(CurrTiming + 0x1a) <
      (uint)*(ushort *)(CurrTiming + 0x18)) {
    return 1;
  }
  return 0;
}


ushort VIGetNextField(void)

{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  os::OSDisableInterrupts();
  uVar5 = DAT_cc00202c & 0x7ff;
  do {
    uVar6 = DAT_cc00202c & 0x7ff;
    bVar1 = uVar5 != uVar6;
    uVar4 = (uint)DAT_cc00202e;
    uVar5 = uVar6;
  } while (bVar1);
  uVar2 = *(ushort *)(CurrTiming + 0x1a);
  uVar3 = *(ushort *)(CurrTiming + 0x18);
  os::OSRestoreInterrupts();
  return (uVar6 - 1) * 2 + ((uVar4 & 0x7ff) - 1) / (uint)uVar2 < (uint)uVar3 ^ 1 ^ DAT_803f1262 & 1;
}


uint VIGetCurrentLine(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = CurrTiming;
  os::OSDisableInterrupts();
  uVar4 = DAT_cc00202c & 0x7ff;
  do {
    uVar3 = DAT_cc00202c & 0x7ff;
    bVar1 = uVar4 != uVar3;
    uVar4 = uVar3;
  } while (bVar1);
  uVar4 = (uVar3 - 1) * 2 + ((DAT_cc00202e & 0x7ff) - 1) / (uint)*(ushort *)(CurrTiming + 0x1a);
  os::OSRestoreInterrupts();
  if (*(ushort *)(iVar2 + 0x18) <= uVar4) {
    uVar4 = uVar4 - *(ushort *)(iVar2 + 0x18);
  }
  return uVar4 >> 1;
}


undefined4 VIGetTvFormat(void)

{
  undefined4 unaff_r31;
  
  os::OSDisableInterrupts();
  switch(CurrTvMode) {
  case 0:
  case 3:
  case 6:
    unaff_r31 = 0;
    break;
  case 1:
  case 4:
    unaff_r31 = 1;
    break;
  case 2:
  case 5:
    unaff_r31 = CurrTvMode;
  }
  os::OSRestoreInterrupts();
  return unaff_r31;
}


ushort VIGetDTVStatus(void)

{
  ushort uVar1;
  
  os::OSDisableInterrupts();
  uVar1 = DAT_cc00206e;
  os::OSRestoreInterrupts();
  return uVar1 & 1;
}

