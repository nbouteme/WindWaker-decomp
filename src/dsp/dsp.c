#include <dsp/dsp.h>
#include <os/OSInterrupt.h>
#include <dsp/dsp_debug.h>
#include <os/OS.h>
#include <JAudio/osdsp_task.h>


namespace dsp {
undefined4 __DSP_init_flag;

ushort DSPCheckMailToDSP(void)

{
  return DAT_cc005000 >> 0xf;
}


ushort DSPCheckMailFromDSP(void)

{
  return DAT_cc005004 >> 0xf;
}


undefined4 DSPReadMailFromDSP(void)

{
  return CONCAT22(DAT_cc005004,DAT_cc005006);
}


void DSPSendMailToDSP(undefined4 param_1)

{
  DAT_cc005000 = (short)((uint)param_1 >> 0x10);
  DAT_cc005002 = (short)param_1;
  return;
}


void DSPAssertInt(void)

{
  os::OSDisableInterrupts();
  DAT_cc00500a = DAT_cc00500a & 0xff57 | 2;
  os::OSRestoreInterrupts();
  return;
}


void DSPInit(void)

{
  undefined4 uVar1;
  
  __DSP_debug_printf(_19,_20,_21);
  if (__DSP_init_flag != 1) {
    os::OSRegisterVersion(__DSPVersion);
    uVar1 = os::OSDisableInterrupts();
    os::__OSSetInterruptHandler(7,JAudio::__DSPHandler);
    os::__OSUnmaskInterrupts(0x1000000);
    DAT_cc00500a = DAT_cc00500a & 0xff53 | 0x800;
    __DSP_tmp_task = 0;
    __DSP_curr_task = 0;
    __DSP_last_task = 0;
    __DSP_first_task = 0;
    __DSP_init_flag = 1;
    os::OSRestoreInterrupts(uVar1);
  }
  return;
}

