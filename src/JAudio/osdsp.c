#include <JAudio/osdsp.h>
#include <m_Do_printf.h>
#include <os/OSInterrupt.h>
#include <dsp/dsp_task.h>


namespace JAudio {

undefined4 * DSPAddTask(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (DSP_prior_task == 0) {
    m_Do_printf::OSReport("Prior Task is not inited\n");
    param_1 = (undefined4 *)0x0;
  }
  else {
    uVar1 = os::OSDisableInterrupts();
    dsp::__DSP_insert_task(param_1);
    *param_1 = 0;
    param_1[2] = 1;
    os::OSRestoreInterrupts(uVar1);
  }
  return param_1;
}


/* __stdcall DSPAddPriorTask(STRUCT_DSP_TASK *) */

void DSPAddPriorTask(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (DSP_prior_task == (undefined4 *)0x0) {
    uVar1 = os::OSDisableInterrupts();
    DSP_prior_task = param_1;
    *param_1 = 0;
    param_1[2] = 1;
    dsp::__DSP_boot_task(param_1);
    os::OSRestoreInterrupts(uVar1);
  }
  else {
    m_Do_printf::OSReport("Already inited prior DSP task\n");
  }
  return;
}

