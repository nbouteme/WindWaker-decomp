#include <os/OSError.h>
#include <os/OSInterrupt.h>
#include <base/PPCArch.h>
#include <os/OSTime.h>
#include <m_Do_printf.h>
#include <os/OSContext.h>
#include <os/OSThread.h>


namespace os {
undefined __OSErrorTable;

int OSSetErrorHandler(ushort param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  uVar1 = OSDisableInterrupts();
  iVar6 = *(int *)(&__OSErrorTable + (uint)param_1 * 4);
  *(int *)(&__OSErrorTable + (uint)param_1 * 4) = param_2;
  if (param_1 == 0x10) {
    uVar2 = base::PPCMfmsr();
    base::PPCMtmsr(uVar2 | 0x2000);
    uVar3 = base::PPCMffpscr();
    iVar5 = DAT_800000dc;
    if (param_2 == 0) {
      for (; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x2fc)) {
        *(uint *)(iVar5 + 0x19c) = *(uint *)(iVar5 + 0x19c) & 0xfffff6ff;
        *(uint *)(iVar5 + 0x194) = *(uint *)(iVar5 + 0x194) & 0xffffff07;
        *(uint *)(iVar5 + 0x194) = *(uint *)(iVar5 + 0x194) & 0x6005f8ff;
      }
      uVar3 = uVar3 & 0xffffff07;
      uVar2 = uVar2 & 0xfffff6ff;
    }
    else {
      for (; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x2fc)) {
        *(uint *)(iVar5 + 0x19c) = *(uint *)(iVar5 + 0x19c) | 0x900;
        if ((*(ushort *)(iVar5 + 0x1a2) & 1) == 0) {
          *(ushort *)(iVar5 + 0x1a2) = *(ushort *)(iVar5 + 0x1a2) | 1;
          iVar7 = 4;
          iVar4 = iVar5;
          do {
            *(undefined4 *)(iVar4 + 0x94) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x90) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x1cc) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x1c8) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x9c) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x98) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x1d4) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x1d0) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0xa4) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0xa0) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x1dc) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x1d8) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0xac) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0xa8) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x1e4) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x1e0) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0xb4) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0xb0) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x1ec) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x1e8) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0xbc) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0xb8) = 0xffffffff;
            *(undefined4 *)(iVar4 + 500) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x1f0) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0xc4) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0xc0) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x1fc) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x1f8) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0xcc) = 0xffffffff;
            *(undefined4 *)(iVar4 + 200) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x204) = 0xffffffff;
            *(undefined4 *)(iVar4 + 0x200) = 0xffffffff;
            iVar4 = iVar4 + 0x40;
            iVar7 = iVar7 + -1;
          } while (iVar7 != 0);
          *(undefined4 *)(iVar5 + 0x194) = 4;
        }
        *(uint *)(iVar5 + 0x194) = *(uint *)(iVar5 + 0x194) | __OSFpscrEnableBits & 0xf8;
        *(uint *)(iVar5 + 0x194) = *(uint *)(iVar5 + 0x194) & 0x6005f8ff;
      }
      uVar2 = uVar2 | 0x900;
      uVar3 = uVar3 | __OSFpscrEnableBits & 0xf8;
    }
    base::PPCMtfpscr(uVar3 & 0x6005f8ff);
    base::PPCMtmsr(uVar2);
  }
  OSRestoreInterrupts(uVar1);
  return iVar6;
}


void __OSUnhandledException(byte param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_r4;
  
  iVar4 = param_2;
  iVar1 = OSGetTime();
  if ((*(uint *)(param_2 + 0x19c) & 2) == 0) {
    m_Do_printf::OSReport(_74,param_1);
  }
  else {
    if (((param_1 == 6) && ((*(uint *)(param_2 + 0x19c) & 0x100000) != 0)) &&
       (DAT_803f0230 != (code *)0x0)) {
      param_1 = 0x10;
      uVar2 = base::PPCMfmsr();
      base::PPCMtmsr(uVar2 | 0x2000);
      if (DAT_800000d8 != 0) {
        OSSaveFPUContext();
      }
      uVar3 = base::PPCMffpscr();
      base::PPCMtfpscr(uVar3 & 0x6005f8ff);
      base::PPCMtmsr(uVar2);
      if (DAT_800000d8 == param_2) {
        OSDisableScheduler();
        (*DAT_803f0230)(0x10,param_2,param_3,param_4);
        *(uint *)(param_2 + 0x19c) = *(uint *)(param_2 + 0x19c) & 0xffffdfff;
        DAT_800000d8 = 0;
        *(uint *)(param_2 + 0x194) = *(uint *)(param_2 + 0x194) & 0x6005f8ff;
        OSEnableScheduler();
        __OSReschedule();
      }
      else {
        *(uint *)(param_2 + 0x19c) = *(uint *)(param_2 + 0x19c) & 0xffffdfff;
        DAT_800000d8 = 0;
      }
      OSLoadContext(param_2);
    }
    if (*(code **)(&__OSErrorTable + (uint)param_1 * 4) != (code *)0x0) {
      OSDisableScheduler();
      (**(code **)(&__OSErrorTable + (uint)param_1 * 4))(param_1,param_2,param_3,param_4);
      OSEnableScheduler();
      __OSReschedule();
      OSLoadContext(param_2);
    }
    if (param_1 == 8) {
      OSLoadContext(param_2);
    }
    m_Do_printf::OSReport(_75,param_1);
  }
  m_Do_printf::OSReport(&_76);
  OSDumpContext(param_2);
  m_Do_printf::OSReport(_77,param_3,param_4);
  m_Do_printf::OSReport(_78,extraout_r4,iVar1,iVar4);
  switch(param_1) {
  case 2:
    m_Do_printf::OSReport(_79,*(undefined4 *)(param_2 + 0x198),param_4);
    break;
  case 3:
    m_Do_printf::OSReport(_80,*(undefined4 *)(param_2 + 0x198));
    break;
  case 5:
    m_Do_printf::OSReport(_81,*(undefined4 *)(param_2 + 0x198),param_4);
    break;
  case 6:
    m_Do_printf::OSReport(_82,*(undefined4 *)(param_2 + 0x198),param_4);
    break;
  case 0xf:
    m_Do_printf::OSReport(&_76);
    m_Do_printf::OSReport(_83,DAT_cc005030,DAT_cc005032);
    m_Do_printf::OSReport(_84,DAT_cc005020._0_2_,DAT_cc005020._2_2_);
    m_Do_printf::OSReport(_85,DAT_cc006014);
  }
  m_Do_printf::OSReport(_86,(int)__OSLastInterrupt,__OSLastInterruptSrr0);
  base::PPCHalt();
  return;
}

