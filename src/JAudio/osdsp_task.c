#include <JAudio/osdsp_task.h>
#include <os/OSContext.h>
#include <dsp/dsp.h>
#include <JAudio/osdsp_task.h>
#include <dsp/dsp_task.h>
#include <JAudio/dspproc.h>


namespace JAudio {
undefined4 sync_stack;
undefined1 DSP_prior_yield;
undefined4 AUDIO_UPDATE_REQUEST;
undefined4 DSP_prior_task;

void __DSPHandler(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined auStack728 [724];
  
  DAT_cc00500a = DAT_cc00500a & 0xffd7 | 0x80;
  os::OSClearContext(auStack728);
  os::OSSetCurrentContext(auStack728);
  if ((DSP_prior_yield == '\x01') || (DSP_prior_yield == '\0')) {
    dsp::__DSP_curr_task = DSP_prior_task;
  }
  do {
    iVar1 = dsp::DSPCheckMailFromDSP();
  } while (iVar1 == 0);
  iVar1 = dsp::DSPReadMailFromDSP();
  if (((dsp::__DSP_curr_task[2] & 2) != 0) && (iVar1 == -0x232efffe)) {
    iVar1 = -0x232efffd;
  }
  if (iVar1 == -0x232efffd) {
    if ((code *)dsp::__DSP_curr_task[0xc] != (code *)0x0) {
      (*(code *)dsp::__DSP_curr_task[0xc])(dsp::__DSP_curr_task);
    }
    dsp::DSPSendMailToDSP(0xcdd10001);
    do {
      iVar1 = dsp::DSPCheckMailToDSP();
    } while (iVar1 != 0);
    *dsp::__DSP_curr_task = 3;
    if (dsp::__DSP_curr_task[0xe] == 0) {
      dsp::__DSP_exec_task(0,DSP_prior_task);
      dsp::__DSP_remove_task(dsp::__DSP_curr_task);
      dsp::__DSP_curr_task = DSP_prior_task;
    }
    else {
      dsp::__DSP_exec_task(0);
      dsp::__DSP_curr_task = (undefined4 *)dsp::__DSP_curr_task[0xe];
      dsp::__DSP_remove_task(dsp::__DSP_curr_task[0xf]);
    }
  }
  else {
    if (iVar1 < -0x232efffd) {
      if (iVar1 == -0x232effff) {
        *dsp::__DSP_curr_task = 1;
        if (dsp::__DSP_curr_task == DSP_prior_task) {
          DSP_prior_yield = '\x01';
          Dsp_Update_Request();
        }
        if ((code *)dsp::__DSP_curr_task[0xb] != (code *)0x0) {
          (*(code *)dsp::__DSP_curr_task[0xb])();
        }
      }
      else {
        if (iVar1 < -0x232effff) {
          if (-0x232f0001 < iVar1) {
            *dsp::__DSP_curr_task = 1;
            if (dsp::__DSP_curr_task == DSP_prior_task) {
              DSP_prior_yield = '\x01';
            }
            if ((code *)dsp::__DSP_curr_task[10] != (code *)0x0) {
              (*(code *)dsp::__DSP_curr_task[10])();
            }
          }
        }
        else {
          dsp::DSPSendMailToDSP(0xcdd10001);
          do {
            iVar1 = dsp::DSPCheckMailToDSP();
          } while (iVar1 != 0);
          *dsp::__DSP_curr_task = 2;
          if ((dsp::__DSP_curr_task[0xe] == 0) && (AUDIO_UPDATE_REQUEST != 0)) {
            dsp::__DSP_exec_task(dsp::__DSP_curr_task,DSP_prior_task);
            AUDIO_UPDATE_REQUEST = 0;
            dsp::__DSP_curr_task = DSP_prior_task;
          }
          else {
            dsp::__DSP_exec_task();
            dsp::__DSP_curr_task = (undefined4 *)dsp::__DSP_curr_task[0xe];
          }
        }
      }
    }
    else {
      if (iVar1 == -0x232efffb) {
        if ((dsp::__DSP_first_task == (undefined4 *)0x0) || (AUDIO_UPDATE_REQUEST != 0)) {
          dsp::DSPSendMailToDSP(0xcdd10003);
          do {
            iVar1 = dsp::DSPCheckMailToDSP();
          } while (iVar1 != 0);
          AUDIO_UPDATE_REQUEST = 0;
          dsp::__DSP_curr_task = DSP_prior_task;
          Dsp_Update_Request();
        }
        else {
          DSP_prior_yield = '\x03';
          dsp::DSPSendMailToDSP(0xcdd10001);
          do {
            iVar1 = dsp::DSPCheckMailToDSP();
          } while (iVar1 != 0);
          dsp::__DSP_exec_task(DSP_prior_task,dsp::__DSP_first_task);
          dsp::__DSP_curr_task = dsp::__DSP_first_task;
        }
      }
      else {
        if ((iVar1 < -0x232efffb) && ((code *)dsp::__DSP_curr_task[0xd] != (code *)0x0)) {
          (*(code *)dsp::__DSP_curr_task[0xd])(dsp::__DSP_curr_task);
        }
      }
    }
  }
  os::OSClearContext(auStack728);
  os::OSSetCurrentContext(param_2);
  return;
}


/* __stdcall DsyncFrame2(unsigned long,
                         unsigned long,
                         unsigned long) */

void DsyncFrame2(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  bVar1 = DSP_prior_yield == '\x01';
  uVar2 = param_1;
  uVar3 = param_2;
  uVar4 = param_3;
  if (bVar1) {
    DsyncFrame();
    uVar2 = sync_stack;
    uVar3 = DAT_803ed044;
    uVar4 = DAT_803ed048;
  }
  DAT_803ed048 = uVar4;
  DAT_803ed044 = uVar3;
  sync_stack = uVar2;
  AUDIO_UPDATE_REQUEST = (uint)!bVar1;
  return;
}


/* __stdcall Dsp_Update_Request(void) */

void Dsp_Update_Request(void)

{
  if (AUDIO_UPDATE_REQUEST != 0) {
    DsyncFrame2(sync_stack,DAT_803ed044,DAT_803ed048);
  }
  return;
}


/* __stdcall Dsp_Running_Check(void) */

uint Dsp_Running_Check(void)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(1 - (uint)DSP_prior_yield);
  return uVar1 >> 5;
}


/* __stdcall Dsp_Running_Start(void) */

void Dsp_Running_Start(void)

{
  DSP_prior_yield = 1;
  return;
}

