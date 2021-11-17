#include <TRK_MINNOW_DOLPHIN/dispatch.h>
#include <TRK_MINNOW_DOLPHIN/msgbuf.h>


namespace TRK_MINNOW_DOLPHIN {
undefined4 gTRKDispatchTableSize;

undefined4 TRKDispatchMessage(undefined4 param_1)

{
  undefined4 uVar1;
  byte local_18 [16];
  
  uVar1 = 0x500;
  TRKSetBufferPosition(param_1,0);
  TRKReadBuffer1_ui8(param_1,local_18);
  if (local_18[0] < gTRKDispatchTableSize) {
    uVar1 = (*(code *)(&gTRKDispatchTable)[local_18[0]])(param_1);
  }
  return uVar1;
}


undefined4 TRKInitializeDispatcher(void)

{
  gTRKDispatchTableSize = 0x20;
  return 0;
}

