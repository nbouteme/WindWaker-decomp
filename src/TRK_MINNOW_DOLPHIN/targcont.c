#include <TRK_MINNOW_DOLPHIN/targcont.h>
#include <TRK_MINNOW_DOLPHIN/targimpl.h>
#include <TRK_MINNOW_DOLPHIN/dolphin_trk_glue.h>


namespace TRK_MINNOW_DOLPHIN {

undefined4 TRKTargetContinue(void)

{
  TRKTargetSetStopped(0);
  UnreserveEXI2Port();
  TRKSwapAndGo();
  ReserveEXI2Port();
  return 0;
}

