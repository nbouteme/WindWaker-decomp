#include <m_Do_printf.h>
#include <os/OSContext.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <os/OSInterrupt.h>
#include <m_Do_printf.h>
#include <os/OSThread.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <base/PPCArch.h>


namespace m_Do_printf {
undefined1 __OSReport_disable;
undefined1 __OSReport_Error_disable;
undefined1 __OSReport_Warning_disable;
undefined1 __OSReport_enable;
undefined4 __OSReport_MonopolyThread;
undefined1 print_threadID;
undefined1 print_callerPC;
undefined4 print_counts;
undefined4 print_errors;
undefined4 print_warings;
undefined1 print_initialized;

undefined4 OSGetCallerPC(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)os::OSGetStackPointer();
  param_1 = param_1 + 1;
  while ((piVar1 = (int *)*piVar1, piVar1 != (int *)0x0 && (piVar1 != (int *)0xffffffff))) {
    param_1 = param_1 + -1;
    if (param_1 == 0) {
      return piVar1[1];
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */

int OSGetActiveThreadID(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = -1;
  os::OSDisableInterrupts();
  for (iVar3 = DAT_800000dc; (iVar3 != 0 && (iVar3 != param_1)); iVar3 = *(int *)(iVar3 + 0x2fc)) {
    iVar2 = iVar2 + 1;
  }
  os::OSRestoreInterrupts();
  iVar1 = -1;
  if (iVar3 != 0) {
    iVar1 = iVar2;
  }
  return iVar1;
}


undefined4
search_partial_address
          (uint param_1,undefined4 *param_2,int *param_3,int *param_4,undefined4 *param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint *puVar5;
  
  puVar3 = DAT_800030c8;
  if (param_1 == 0) {
    return 0xffffffff;
  }
  do {
    if (puVar3 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    puVar5 = (uint *)puVar3[4];
    iVar4 = 0;
    for (iVar2 = puVar3[3]; iVar2 != 0; iVar2 = iVar2 + -1) {
      if (((puVar5[1] != 0) && (uVar1 = *puVar5 & 0xfffffffe, uVar1 <= param_1)) &&
         (param_1 < uVar1 + puVar5[1])) {
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = *puVar3;
        }
        if (param_3 != (int *)0x0) {
          *param_3 = iVar4;
        }
        if (param_4 != (int *)0x0) {
          *param_4 = param_1 - uVar1;
        }
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = puVar3[5];
        }
        return 0;
      }
      puVar5 = puVar5 + 2;
      iVar4 = iVar4 + 1;
    }
    puVar3 = (undefined4 *)puVar3[1];
  } while( true );
}


int convert_partial_address(int param_1)

{
  int iVar1;
  uint local_18;
  int local_14;
  undefined auStack16 [12];
  
  iVar1 = search_partial_address(param_1,auStack16,&local_14,&local_18,0);
  if (iVar1 == 0) {
    param_1 = local_14 * 0x10000000 + (local_18 & 0x1ffffff);
  }
  return param_1;
}


void OSReportDisable(void)

{
  __OSReport_disable = 1;
  return;
}


void OSReportEnable(void)

{
  __OSReport_disable = 0;
  return;
}


void OSReportForceEnableOn(void)

{
  __OSReport_enable = 1;
  return;
}


void OSReportForceEnableOff(void)

{
  __OSReport_enable = 0;
  return;
}


/* __stdcall OSReportInit(void) */

void OSReportInit(void)

{
  if (print_initialized != '\0') {
    return;
  }
  print_initialized = 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */

void OSVReport(char *param_1,__gnuc_va_list param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (print_initialized == '\0') {
    OSReportInit();
  }
  if ((__OSReport_enable != '\0') || (__OSReport_disable == '\0')) {
    iVar1 = os::OSGetCurrentThread();
    if ((iVar1 != 0) && (*(short *)(iVar1 + 0x2c8) != 2)) {
      iVar1 = 0;
    }
    if ((__OSReport_MonopolyThread == 0) || (__OSReport_MonopolyThread == iVar1)) {
      if (print_threadID != '\0') {
        uVar2 = OSGetActiveThreadID();
        MSL_C.PPCEABI.bare.H::printf("[%x]",uVar2);
      }
      if (print_callerPC != '\0') {
        MSL_C.PPCEABI.bare.H::printf("[PC:");
        for (uVar3 = 3; uVar3 <= print_callerPCLevel; uVar3 = uVar3 + 1) {
          OSGetCallerPC(uVar3);
          uVar2 = convert_partial_address();
          MSL_C.PPCEABI.bare.H::printf(" %08x",uVar2);
        }
        MSL_C.PPCEABI.bare.H::printf("]");
      }
      MSL_C.PPCEABI.bare.H::vprintf(param_1,param_2);
      print_counts = print_counts + 1;
    }
  }
  return;
}


void OSReport
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
               undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16)

{
  byte in_cr1;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  undefined *local_14;
  undefined4 *local_10;
  
  if ((bool)(in_cr1 >> 1 & 1)) {
    local_58 = param_1;
    local_50 = param_2;
    local_48 = param_3;
    local_40 = param_4;
    local_38 = param_5;
    local_30 = param_6;
    local_28 = param_7;
    local_20 = param_8;
  }
  local_18 = 0x1000000;
  local_14 = &stack0x00000008;
  local_10 = &local_78;
  local_78 = param_9;
  local_74 = param_10;
  local_70 = param_11;
  local_6c = param_12;
  local_68 = param_13;
  local_64 = param_14;
  local_60 = param_15;
  local_5c = param_16;
  OSVReport(param_9,&local_18);
  return;
}


void OSReport_FatalError
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
               undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16)

{
  byte in_cr1;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  undefined *local_14;
  undefined4 *local_10;
  
  if ((bool)(in_cr1 >> 1 & 1)) {
    local_58 = param_1;
    local_50 = param_2;
    local_48 = param_3;
    local_40 = param_4;
    local_38 = param_5;
    local_30 = param_6;
    local_28 = param_7;
    local_20 = param_8;
  }
  local_18 = 0x1000000;
  local_14 = &stack0x00000008;
  local_10 = &local_78;
  local_78 = param_9;
  local_74 = param_10;
  local_70 = param_11;
  local_6c = param_12;
  local_68 = param_13;
  local_64 = param_14;
  local_60 = param_15;
  local_5c = param_16;
  OSReportForceEnableOn();
  OSReport("\x1b[41;37m***** FATAL ERROR *****\n");
  OSVReport(param_9,&local_18);
  OSReport("***** FATAL ERROR *****\n\x1b[m");
  OSReportForceEnableOff();
  print_errors = print_errors + 1;
  return;
}


void OSReport_Error
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
               undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16)

{
  byte in_cr1;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  undefined *local_14;
  undefined4 *local_10;
  
  if ((bool)(in_cr1 >> 1 & 1)) {
    local_58 = param_1;
    local_50 = param_2;
    local_48 = param_3;
    local_40 = param_4;
    local_38 = param_5;
    local_30 = param_6;
    local_28 = param_7;
    local_20 = param_8;
  }
  print_errors = print_errors + 1;
  if (__OSReport_Error_disable == '\0') {
    local_18 = 0x1000000;
    local_14 = &stack0x00000008;
    local_10 = &local_78;
    local_78 = param_9;
    local_74 = param_10;
    local_70 = param_11;
    local_6c = param_12;
    local_68 = param_13;
    local_64 = param_14;
    local_60 = param_15;
    local_5c = param_16;
    OSReportForceEnableOn();
    MSL_C.PPCEABI.bare.H::printf("\x1b[41;37m");
    OSVReport(param_9,&local_18);
    MSL_C.PPCEABI.bare.H::printf("\x1b[m");
    OSReportForceEnableOff();
  }
  return;
}


void OSReport_Warning
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
               undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16)

{
  byte in_cr1;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  undefined *local_14;
  undefined4 *local_10;
  
  if ((bool)(in_cr1 >> 1 & 1)) {
    local_58 = param_1;
    local_50 = param_2;
    local_48 = param_3;
    local_40 = param_4;
    local_38 = param_5;
    local_30 = param_6;
    local_28 = param_7;
    local_20 = param_8;
  }
  print_warings = print_warings + 1;
  if (__OSReport_Warning_disable == '\0') {
    local_18 = 0x1000000;
    local_14 = &stack0x00000008;
    local_10 = &local_78;
    local_78 = param_9;
    local_74 = param_10;
    local_70 = param_11;
    local_6c = param_12;
    local_68 = param_13;
    local_64 = param_14;
    local_60 = param_15;
    local_5c = param_16;
    OSReportForceEnableOn();
    OSReport("\x1b[43;30m");
    OSVReport(param_9,&local_18);
    OSReport("\x1b[m");
    OSReportForceEnableOff();
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void OSPanic
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
               undefined4 param_9,undefined4 param_10,char *param_11,undefined4 param_12,
               undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  byte in_cr1;
  undefined4 local_88;
  undefined4 local_84;
  char *local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined4 local_28;
  undefined *local_24;
  undefined4 *local_20;
  
  if ((bool)(in_cr1 >> 1 & 1)) {
    local_68 = param_1;
    local_60 = param_2;
    local_58 = param_3;
    local_50 = param_4;
    local_48 = param_5;
    local_40 = param_6;
    local_38 = param_7;
    local_30 = param_8;
  }
  local_88 = param_9;
  local_84 = param_10;
  local_80 = param_11;
  local_7c = param_12;
  local_78 = param_13;
  local_74 = param_14;
  local_70 = param_15;
  local_6c = param_16;
  os::OSDisableInterrupts();
  local_28 = 0x3000000;
  local_24 = &stack0x00000008;
  local_20 = &local_88;
  MSL_C.PPCEABI.bare.H::vprintf(param_11,&local_28);
  OSReport(" in \"%s\" on line %d.\n",param_9,param_10);
  OSReport("\nAddress:      Back Chain    LR Save\n");
  uVar3 = 0;
  puVar2 = (undefined4 *)os::OSGetStackPointer();
  while (((puVar2 != (undefined4 *)0x0 && (puVar2 != (undefined4 *)&DAT_ffffffff)) &&
         (bVar1 = uVar3 < 0x10, uVar3 = uVar3 + 1, bVar1))) {
    OSReport("0x%08x:   0x%08x    0x%08x\n",puVar2,*puVar2,puVar2[1]);
    puVar2 = (undefined4 *)*puVar2;
  }
  _DAT_01234567 = &DAT_01234567;
  base::PPCHalt();
  return;
}

