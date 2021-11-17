#include <dsp/dsp_task.h>
#include <dsp/dsp.h>
#include <dsp/dsp_debug.h>


namespace dsp {
undefined4 __DSP_tmp_task;
undefined4 __DSP_last_task;
undefined4 __DSP_first_task;
undefined4 __DSP_curr_task;

void __DSP_exec_task(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    DSPSendMailToDSP(0);
    do {
      iVar1 = DSPCheckMailToDSP();
    } while (iVar1 != 0);
    DSPSendMailToDSP(0);
    do {
      iVar1 = DSPCheckMailToDSP();
    } while (iVar1 != 0);
    DSPSendMailToDSP(0);
    do {
      iVar1 = DSPCheckMailToDSP();
    } while (iVar1 != 0);
  }
  else {
    DSPSendMailToDSP(*(undefined4 *)(param_1 + 0x18));
    do {
      iVar1 = DSPCheckMailToDSP();
    } while (iVar1 != 0);
    DSPSendMailToDSP(*(undefined4 *)(param_1 + 0x1c));
    do {
      iVar1 = DSPCheckMailToDSP();
    } while (iVar1 != 0);
    DSPSendMailToDSP(*(undefined4 *)(param_1 + 0x20));
    do {
      iVar1 = DSPCheckMailToDSP();
    } while (iVar1 != 0);
  }
  DSPSendMailToDSP(param_2[3]);
  do {
    iVar1 = DSPCheckMailToDSP();
  } while (iVar1 != 0);
  DSPSendMailToDSP(param_2[4]);
  do {
    iVar1 = DSPCheckMailToDSP();
  } while (iVar1 != 0);
  DSPSendMailToDSP(param_2[5]);
  do {
    iVar1 = DSPCheckMailToDSP();
  } while (iVar1 != 0);
  if (*param_2 == 0) {
    DSPSendMailToDSP(*(undefined2 *)(param_2 + 9));
    do {
      iVar1 = DSPCheckMailToDSP();
    } while (iVar1 != 0);
    DSPSendMailToDSP(0);
    do {
      iVar1 = DSPCheckMailToDSP();
    } while (iVar1 != 0);
    DSPSendMailToDSP(0);
    do {
      iVar1 = DSPCheckMailToDSP();
    } while (iVar1 != 0);
    DSPSendMailToDSP(0);
    do {
      iVar1 = DSPCheckMailToDSP();
    } while (iVar1 != 0);
  }
  else {
    DSPSendMailToDSP(*(undefined2 *)((int)param_2 + 0x26));
    do {
      iVar1 = DSPCheckMailToDSP();
    } while (iVar1 != 0);
    DSPSendMailToDSP(param_2[6]);
    do {
      iVar1 = DSPCheckMailToDSP();
    } while (iVar1 != 0);
    DSPSendMailToDSP(param_2[7]);
    do {
      iVar1 = DSPCheckMailToDSP();
    } while (iVar1 != 0);
    DSPSendMailToDSP(param_2[8]);
    do {
      iVar1 = DSPCheckMailToDSP();
    } while (iVar1 != 0);
  }
  return;
}


void __DSP_boot_task(int param_1)

{
  int iVar1;
  
  do {
    iVar1 = DSPCheckMailFromDSP();
  } while (iVar1 == 0);
  DSPReadMailFromDSP();
  DSPSendMailToDSP(0x80f3a001);
  do {
    iVar1 = DSPCheckMailToDSP();
  } while (iVar1 != 0);
  DSPSendMailToDSP(*(undefined4 *)(param_1 + 0xc));
  do {
    iVar1 = DSPCheckMailToDSP();
  } while (iVar1 != 0);
  DSPSendMailToDSP(0x80f3c002);
  do {
    iVar1 = DSPCheckMailToDSP();
  } while (iVar1 != 0);
  DSPSendMailToDSP(*(uint *)(param_1 + 0x14) & 0xffff);
  do {
    iVar1 = DSPCheckMailToDSP();
  } while (iVar1 != 0);
  DSPSendMailToDSP(0x80f3a002);
  do {
    iVar1 = DSPCheckMailToDSP();
  } while (iVar1 != 0);
  DSPSendMailToDSP(*(undefined4 *)(param_1 + 0x10));
  do {
    iVar1 = DSPCheckMailToDSP();
  } while (iVar1 != 0);
  DSPSendMailToDSP(0x80f3b002);
  do {
    iVar1 = DSPCheckMailToDSP();
  } while (iVar1 != 0);
  DSPSendMailToDSP(0);
  do {
    iVar1 = DSPCheckMailToDSP();
  } while (iVar1 != 0);
  DSPSendMailToDSP(0x80f3d001);
  do {
    iVar1 = DSPCheckMailToDSP();
  } while (iVar1 != 0);
  DSPSendMailToDSP(*(undefined2 *)(param_1 + 0x24));
  do {
    iVar1 = DSPCheckMailToDSP();
  } while (iVar1 != 0);
  __DSP_debug_printf(_266,param_1);
  __DSP_debug_printf(_267,*(undefined4 *)(param_1 + 0xc));
  __DSP_debug_printf(_268,*(undefined4 *)(param_1 + 0x14));
  __DSP_debug_printf(_269,*(undefined4 *)(param_1 + 0x10));
  __DSP_debug_printf(_270,*(undefined4 *)(param_1 + 0x1c));
  __DSP_debug_printf(_271,*(undefined2 *)(param_1 + 0x24));
  return;
}


void __DSP_insert_task(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = __DSP_first_task;
  if (__DSP_first_task == 0) {
    __DSP_last_task = param_1;
    __DSP_first_task = param_1;
    __DSP_curr_task = param_1;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    return;
  }
  do {
    iVar1 = __DSP_first_task;
    if (iVar2 == 0) {
LAB_803195b0:
      __DSP_first_task = iVar1;
      if (iVar2 == 0) {
        *(int *)(__DSP_last_task + 0x38) = param_1;
        *(undefined4 *)(param_1 + 0x38) = 0;
        *(int *)(param_1 + 0x3c) = __DSP_last_task;
        __DSP_last_task = param_1;
        return;
      }
      return;
    }
    if (*(uint *)(param_1 + 4) < *(uint *)(iVar2 + 4)) {
      *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(iVar2 + 0x3c);
      *(int *)(iVar2 + 0x3c) = param_1;
      *(int *)(param_1 + 0x38) = iVar2;
      iVar1 = param_1;
      if (*(int *)(param_1 + 0x3c) != 0) {
        *(int *)(*(int *)(param_1 + 0x3c) + 0x38) = param_1;
        iVar1 = __DSP_first_task;
      }
      goto LAB_803195b0;
    }
    iVar2 = *(int *)(iVar2 + 0x38);
  } while( true );
}


void __DSP_remove_task(undefined4 *param_1)

{
  param_1[2] = 0;
  *param_1 = 3;
  if (__DSP_first_task != param_1) {
    if (__DSP_last_task == param_1) {
      __DSP_last_task = (undefined4 *)param_1[0xf];
      *(undefined4 *)(param_1[0xf] + 0x38) = 0;
      __DSP_curr_task = __DSP_first_task;
      return;
    }
    __DSP_curr_task = (undefined4 *)param_1[0xe];
    *(undefined4 *)(param_1[0xf] + 0x38) = param_1[0xe];
    *(undefined4 *)(param_1[0xe] + 0x3c) = param_1[0xf];
    return;
  }
  __DSP_first_task = (undefined4 *)param_1[0xe];
  if (__DSP_first_task != (undefined4 *)0x0) {
    *(undefined4 *)(param_1[0xe] + 0x3c) = 0;
    return;
  }
  __DSP_last_task = (undefined4 *)0x0;
  __DSP_first_task = (undefined4 *)0x0;
  __DSP_curr_task = (undefined4 *)0x0;
  return;
}

