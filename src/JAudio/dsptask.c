#include <JAudio/dsptask.h>
#include <dsp/dsp.h>
#include <JAudio/osdsp_task.h>
#include <JAudio/dsptask.h>
#include <JAudio/osdsp.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <os/OSInterrupt.h>


namespace JAudio {
undefined audio_task;
undefined AUDIO_YIELD_BUFFER;
undefined taskwork;
undefined4 taskreadp;
undefined4 taskwritep;

/* __stdcall DspHandShake(void *) */

void DspHandShake(void)

{
  int iVar1;
  
  do {
    iVar1 = dsp::DSPCheckMailFromDSP();
  } while (iVar1 == 0);
  dsp::DSPReadMailFromDSP();
  dsp::DSPCheckMailFromDSP();
  Dsp_Running_Start();
  return;
}


/* __stdcall DspBoot(void *(void *)) */

void DspBoot(undefined4 param_1)

{
  DspInitWork();
  DAT_803eaf64 = 0xf0;
  DAT_803eaf6c = 0x399420;
  DAT_803eaf70 = 0x1d20;
  DAT_803eaf74 = 0;
  DAT_803eaf78 = 0x3eafc0;
  DAT_803eaf7c = 0x2000;
  DAT_803eaf80 = 0;
  DAT_803eaf84 = 0;
  DAT_803eaf86 = 0x10;
  DAT_803eaf88 = DspHandShake;
  DAT_803eaf8c = 0;
  DAT_803eaf90 = 0;
  DAT_803eaf94 = param_1;
  dsp::DSPInit();
  DSPAddPriorTask(&audio_task);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall DSPSendCommands2(unsigned long *,
                              unsigned long,
                              void *(unsigned short)) */

undefined4 DSPSendCommands2(undefined4 *param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_r28;
  uint uVar4;
  
  do {
    iVar1 = Dsp_Running_Check();
  } while (iVar1 == 0);
  uVar2 = os::OSDisableInterrupts();
  iVar1 = dsp::DSPCheckMailToDSP();
  if (iVar1 == 0) {
    dsp::DSPSendMailToDSP(param_2);
    dsp::DSPAssertInt();
    do {
      iVar1 = dsp::DSPCheckMailToDSP();
    } while (iVar1 != 0);
    if (param_2 == 0) {
      param_2 = 1;
    }
    if (param_3 != 0) {
      unaff_r28 = DspStartWork(*param_1,param_3);
    }
    iVar1 = 0;
    for (uVar4 = 0; uVar4 < param_2; uVar4 = uVar4 + 1) {
      dsp::DSPSendMailToDSP(*(undefined4 *)((int)param_1 + iVar1));
      do {
        iVar3 = dsp::DSPCheckMailToDSP();
      } while (iVar3 != 0);
      iVar1 = iVar1 + 4;
    }
    os::OSRestoreInterrupts(uVar2);
  }
  else {
    os::OSRestoreInterrupts(uVar2);
    unaff_r28 = 0xffffffff;
  }
  return unaff_r28;
}


/* __stdcall DspInitWork(void) */

void DspInitWork(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x10;
  iVar1 = 0;
  do {
    *(undefined4 *)((int)&DAT_803ecfc4 + iVar1) = 0;
    iVar2 = iVar2 + -1;
    iVar1 = iVar1 + 8;
  } while (iVar2 != 0);
  return;
}


/* __stdcall DspStartWork(unsigned long,
                          void *(unsigned short)) */

uint DspStartWork(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = taskwritep;
  uVar4 = taskwritep + 1;
  uVar2 = uVar4 & 0xf;
  if (uVar2 == taskreadp) {
    return 0;
  }
  iVar1 = taskwritep * 8;
  taskwritep = uVar2;
  *(short *)(&taskwork + iVar1) = (short)((uint)param_1 >> 0x10);
  (&DAT_803ecfc4)[iVar3 * 2] = param_2;
  return uVar4;
}


/* __stdcall DspFinishWork(unsigned short) */

void DspFinishWork(short param_1)

{
  if (param_1 == *(short *)(&taskwork + taskreadp * 8)) {
    if ((code *)(&DAT_803ecfc4)[taskreadp * 2] != (code *)0x0) {
      (*(code *)(&DAT_803ecfc4)[taskreadp * 2])(taskreadp & 0xffff);
    }
    taskreadp = taskreadp + 1 & 0xf;
  }
  return;
}

