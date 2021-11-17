#include <os/OSMessage.h>
#include <os/OSThread.h>
#include <os/OSInterrupt.h>


namespace os {

void OSInitMessageQueue(OSMessageQueue *param_1,OSMessage *param_2,int param_3)

{
  OSInitThreadQueue();
  OSInitThreadQueue(&param_1->queueReceive);
  param_1->msgArray = param_2;
  param_1->msgCount = param_3;
  param_1->firstIndex = 0;
  param_1->usedCount = 0;
  return;
}


undefined4 OSSendMessage(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = OSDisableInterrupts();
  while( true ) {
    iVar3 = *(int *)(param_1 + 0x14);
    if (*(int *)(param_1 + 0x1c) < iVar3) {
      iVar2 = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x1c);
      *(undefined4 *)(*(int *)(param_1 + 0x10) + (iVar2 - (iVar2 / iVar3) * iVar3) * 4) = param_2;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      OSWakeupThread(param_1 + 8);
      OSRestoreInterrupts(uVar1);
      return 1;
    }
    if ((param_3 & 1) == 0) break;
    OSSleepThread(param_1);
  }
  OSRestoreInterrupts(uVar1);
  return 0;
}


undefined4 OSReceiveMessage(int param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = OSDisableInterrupts();
  while( true ) {
    if (*(int *)(param_1 + 0x1c) != 0) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *(undefined4 *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18) * 4);
      }
      iVar2 = *(int *)(param_1 + 0x18) + 1;
      *(int *)(param_1 + 0x18) =
           iVar2 - (iVar2 / *(int *)(param_1 + 0x14)) * *(int *)(param_1 + 0x14);
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
      OSWakeupThread(param_1);
      OSRestoreInterrupts(uVar1);
      return 1;
    }
    if ((param_3 & 1) == 0) break;
    OSSleepThread(param_1 + 8);
  }
  OSRestoreInterrupts(uVar1);
  return 0;
}

