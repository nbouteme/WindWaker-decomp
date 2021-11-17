#include <TRK_MINNOW_DOLPHIN/nubinit.h>
#include <TRK_MINNOW_DOLPHIN/dolphin_trk_glue.h>
#include <TRK_MINNOW_DOLPHIN/serpoll.h>
#include <TRK_MINNOW_DOLPHIN/usr_put.h>
#include <TRK_MINNOW_DOLPHIN/nubevent.h>
#include <TRK_MINNOW_DOLPHIN/msgbuf.h>
#include <TRK_MINNOW_DOLPHIN/dispatch.h>
#include <TRK_MINNOW_DOLPHIN/targimpl.h>
#include <TRK_MINNOW_DOLPHIN/dolphin_trk.h>


namespace TRK_MINNOW_DOLPHIN {
undefined4 gTRKBigEndian;

void TRKNubWelcome(void)

{
  TRK_board_display("MetroTRK for GAMECUBE v0.10");
  return;
}


undefined4 TRKTerminateNub(void)

{
  TRKTerminateSerialHandler();
  return 0;
}


/* WARNING: Removing unreachable block (ram,0x803312ac) */
/* WARNING: Removing unreachable block (ram,0x803312c0) */
/* WARNING: Removing unreachable block (ram,0x803312b8) */

int TRKInitializeNub(void)

{
  int iVar1;
  int iVar2;
  
  gTRKBigEndian = 1;
  usr_put_initialize();
  iVar1 = TRKInitializeEventQueue();
  if (iVar1 == 0) {
    iVar1 = TRKInitializeMessageBuffers();
  }
  if (iVar1 == 0) {
    iVar1 = TRKInitializeDispatcher();
  }
  if (iVar1 == 0) {
    iVar2 = TRKInitializeIntDrivenUART(0xe100,1,0,&gTRKInputPendingPtr);
    TRKTargetSetInputPendingPtr(gTRKInputPendingPtr);
    if (iVar2 != 0) {
      iVar1 = iVar2;
    }
  }
  if (iVar1 == 0) {
    iVar1 = TRKInitializeSerialHandler();
  }
  if (iVar1 == 0) {
    iVar1 = TRKInitializeTarget();
  }
  return iVar1;
}

