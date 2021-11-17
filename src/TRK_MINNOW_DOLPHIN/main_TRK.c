#include <TRK_MINNOW_DOLPHIN/main_TRK.h>
#include <TRK_MINNOW_DOLPHIN/nubinit.h>
#include <TRK_MINNOW_DOLPHIN/mainloop.h>


namespace TRK_MINNOW_DOLPHIN {
undefined4 TRK_mainError;

void TRK_main(void)

{
  TRK_mainError = TRKInitializeNub();
  if (TRK_mainError == 0) {
    TRKNubWelcome();
    TRKNubMainLoop();
  }
  TRK_mainError = TRKTerminateNub();
  return;
}

