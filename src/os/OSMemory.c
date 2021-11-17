#include <os/OSMemory.h>
#include <os/OSInterrupt.h>
#include <os/OSError.h>
#include <os/OSCache.h>
#include <os/OSMemory.h>
#include <os/OSReset.h>


namespace os {

undefined4 OSGetConsoleSimulatedMemSize(void)

{
  return DAT_800000f0;
}


undefined4 OnReset(int param_1)

{
  if (param_1 != 0) {
    DAT_cc004010 = 0xff;
    __OSMaskInterrupts(0xf0000000);
  }
  return 1;
}


void MEMIntrruptHandler(undefined4 param_1,undefined4 param_2)

{
  DAT_cc004020 = 0;
  if (DAT_803f022c == (code *)0x0) {
    __OSUnhandledException
              (0xf,param_2,DAT_cc00401e,(DAT_cc004024 & 0x3ff) << 0x10 | (uint)DAT_cc004022);
  }
  else {
    (*DAT_803f022c)(0xf);
  }
  return;
}


void OSProtectRange(uint param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (param_1 < 4) {
    uVar1 = param_2 + param_3 + 0x3ff;
    DCFlushRange(param_2 & 0xfffffc00,(uVar1 & 0xfffffc00) - (param_2 & 0xfffffc00));
    uVar2 = OSDisableInterrupts();
    __OSMaskInterrupts(0x80000000U >> param_1);
    *(short *)(&DAT_cc004000 + param_1 * 4) = (short)(param_2 >> 10);
    *(short *)(&DAT_cc004002 + param_1 * 4) = (short)(uVar1 >> 10);
    DAT_cc004010 = DAT_cc004010 & ~(ushort)(3 << (param_1 << 1)) |
                   (ushort)((param_4 & 3) << (param_1 << 1));
    if ((param_4 & 3) != 3) {
      __OSUnmaskInterrupts(0x80000000U >> param_1);
    }
    OSRestoreInterrupts(uVar2);
  }
  return;
}


void Config24MB(void)

{
  uint in_MSR;
  
  instructionSynchronize();
  instructionSynchronize();
  instructionSynchronize();
  instructionSynchronize();
  instructionSynchronize();
  returnFromInterrupt(in_MSR,in_MSR | 0x30);
  return;
}


void Config48MB(void)

{
  uint in_MSR;
  
  instructionSynchronize();
  instructionSynchronize();
  instructionSynchronize();
  instructionSynchronize();
  instructionSynchronize();
  returnFromInterrupt(in_MSR,in_MSR | 0x30);
  return;
}


uint RealMode(void)

{
  uint in_MSR;
  
  returnFromInterrupt(in_MSR,in_MSR & 0xffffffcf);
  return in_MSR & 0xffffffcf;
}


void __OSInitMemoryProtection(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_800000f0;
  uVar2 = OSDisableInterrupts();
  if (uVar1 < 0x1800001) {
    RealMode(Config24MB);
  }
  else {
    if (uVar1 < 0x3000001) {
      RealMode(Config48MB);
    }
  }
  DAT_cc004020 = 0;
  DAT_cc004010 = 0xff;
  __OSMaskInterrupts(0xf0000000);
  __OSSetInterruptHandler(0,MEMIntrruptHandler);
  __OSSetInterruptHandler(1,MEMIntrruptHandler);
  __OSSetInterruptHandler(2,MEMIntrruptHandler);
  __OSSetInterruptHandler(3,MEMIntrruptHandler);
  __OSSetInterruptHandler(4,MEMIntrruptHandler);
  OSRegisterResetFunction(&ResetFunctionInfo);
  if ((DAT_800000f0 < DAT_80000028) && (DAT_800000f0 == 0x1800000)) {
    DAT_cc004028 = 2;
  }
  __OSUnmaskInterrupts(0x8000000);
  OSRestoreInterrupts(uVar2);
  return;
}

