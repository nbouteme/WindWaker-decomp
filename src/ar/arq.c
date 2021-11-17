#include <ar/arq.h>
#include <ar/ar.h>
#include <ar/arq.h>
#include <os/OS.h>
#include <os/OSInterrupt.h>


namespace ar {
undefined4 __ARQRequestQueueHi;
undefined4 __ARQRequestTailHi;
undefined4 __ARQRequestQueueLo;
undefined4 __ARQRequestTailLo;
undefined4 __ARQRequestPendingHi;
undefined4 __ARQRequestPendingLo;
undefined4 __ARQCallbackHi;
undefined4 __ARQCallbackLo;
undefined4 __ARQChunkSize;
undefined4 __ARQ_init_flag;

void __ARQServiceQueueLo(void)

{
  if ((__ARQRequestPendingLo == (int **)0x0) && (__ARQRequestQueueLo != (int **)0x0)) {
    __ARQRequestPendingLo = __ARQRequestQueueLo;
    __ARQRequestQueueLo = (int **)*__ARQRequestQueueLo;
  }
  if (__ARQRequestPendingLo != (int **)0x0) {
    if (__ARQChunkSize < __ARQRequestPendingLo[6]) {
      if (__ARQRequestPendingLo[2] == (int *)0x0) {
        ARStartDMA(0,__ARQRequestPendingLo[4],__ARQRequestPendingLo[5],__ARQChunkSize);
      }
      else {
        ARStartDMA(__ARQRequestPendingLo[2],__ARQRequestPendingLo[5],__ARQRequestPendingLo[4],
                   __ARQChunkSize);
      }
    }
    else {
      if (__ARQRequestPendingLo[2] == (int *)0x0) {
        ARStartDMA(0,__ARQRequestPendingLo[4],__ARQRequestPendingLo[5]);
      }
      else {
        ARStartDMA(__ARQRequestPendingLo[2],__ARQRequestPendingLo[5],__ARQRequestPendingLo[4]);
      }
      __ARQCallbackLo = __ARQRequestPendingLo[7];
    }
    __ARQRequestPendingLo[6] = (int *)((int)__ARQRequestPendingLo[6] - (int)__ARQChunkSize);
    __ARQRequestPendingLo[4] = (int *)((int)__ARQRequestPendingLo[4] + (int)__ARQChunkSize);
    __ARQRequestPendingLo[5] = (int *)((int)__ARQRequestPendingLo[5] + (int)__ARQChunkSize);
  }
  return;
}


void __ARQCallbackHack(void)

{
  return;
}


void __ARQInterruptServiceRoutine(void)

{
  if (__ARQCallbackHi == (code *)0x0) {
    if (__ARQCallbackLo != (code *)0x0) {
      (*__ARQCallbackLo)(__ARQRequestPendingLo);
      __ARQRequestPendingLo = 0;
      __ARQCallbackLo = (code *)0x0;
    }
  }
  else {
    (*__ARQCallbackHi)(__ARQRequestPendingHi);
    __ARQRequestPendingHi = (int *)0x0;
    __ARQCallbackHi = (code *)0x0;
  }
  if (__ARQRequestQueueHi != (int *)0x0) {
    if (__ARQRequestQueueHi[2] == 0) {
      ARStartDMA(0,__ARQRequestQueueHi[4],__ARQRequestQueueHi[5],__ARQRequestQueueHi[6]);
    }
    else {
      ARStartDMA(__ARQRequestQueueHi[2],__ARQRequestQueueHi[5],__ARQRequestQueueHi[4],
                 __ARQRequestQueueHi[6]);
    }
    __ARQCallbackHi = (code *)__ARQRequestQueueHi[7];
    __ARQRequestPendingHi = __ARQRequestQueueHi;
    __ARQRequestQueueHi = (int *)*__ARQRequestQueueHi;
  }
  if (__ARQRequestPendingHi == (int *)0x0) {
    __ARQServiceQueueLo();
  }
  return;
}


void ARQInit(void)

{
  if (__ARQ_init_flag != 1) {
    os::OSRegisterVersion(__ARQVersion);
    __ARQRequestQueueLo = 0;
    __ARQRequestQueueHi = 0;
    __ARQChunkSize = 0x1000;
    ARRegisterDMACallback(__ARQInterruptServiceRoutine);
    __ARQRequestPendingHi = 0;
    __ARQRequestPendingLo = 0;
    __ARQCallbackHi = 0;
    __ARQCallbackLo = 0;
    __ARQ_init_flag = 1;
  }
  return;
}


void ARQPostRequest(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  *param_1 = 0;
  param_1[1] = param_2;
  param_1[2] = param_3;
  param_1[4] = param_5;
  param_1[5] = param_6;
  param_1[6] = param_7;
  if (param_8 == 0) {
    param_1[7] = __ARQCallbackHack;
  }
  else {
    param_1[7] = param_8;
  }
  uVar5 = os::OSDisableInterrupts();
  puVar3 = __ARQRequestQueueLo;
  puVar4 = __ARQRequestTailLo;
  if (param_4 == 1) {
    puVar1 = param_1;
    puVar2 = param_1;
    if (__ARQRequestQueueHi != (undefined4 *)0x0) {
      *__ARQRequestTailHi = param_1;
      puVar1 = __ARQRequestQueueHi;
      puVar2 = param_1;
      puVar3 = __ARQRequestQueueLo;
      puVar4 = __ARQRequestTailLo;
    }
  }
  else {
    puVar1 = __ARQRequestQueueHi;
    puVar2 = __ARQRequestTailHi;
    if (((param_4 < 1) && (-1 < param_4)) &&
       (puVar3 = param_1, puVar4 = param_1, __ARQRequestQueueLo != (undefined4 *)0x0)) {
      *__ARQRequestTailLo = param_1;
      puVar1 = __ARQRequestQueueHi;
      puVar2 = __ARQRequestTailHi;
      puVar3 = __ARQRequestQueueLo;
      puVar4 = param_1;
    }
  }
  __ARQRequestTailLo = puVar4;
  __ARQRequestQueueLo = puVar3;
  __ARQRequestTailHi = puVar2;
  __ARQRequestQueueHi = puVar1;
  if ((__ARQRequestPendingHi == (undefined4 *)0x0) && (__ARQRequestPendingLo == 0)) {
    if (__ARQRequestQueueHi != (undefined4 *)0x0) {
      if (__ARQRequestQueueHi[2] == 0) {
        ARStartDMA(0,__ARQRequestQueueHi[4],__ARQRequestQueueHi[5],__ARQRequestQueueHi[6]);
      }
      else {
        ARStartDMA(__ARQRequestQueueHi[2],__ARQRequestQueueHi[5],__ARQRequestQueueHi[4],
                   __ARQRequestQueueHi[6]);
      }
      __ARQCallbackHi = __ARQRequestQueueHi[7];
      __ARQRequestPendingHi = __ARQRequestQueueHi;
      __ARQRequestQueueHi = (undefined4 *)*__ARQRequestQueueHi;
    }
    if (__ARQRequestPendingHi == (undefined4 *)0x0) {
      __ARQServiceQueueLo();
    }
  }
  os::OSRestoreInterrupts(uVar5);
  return;
}

