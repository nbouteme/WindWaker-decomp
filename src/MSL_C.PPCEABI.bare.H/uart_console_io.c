#include <MSL_C.PPCEABI.bare.H/uart_console_io.h>
#include <exi/EXIUart.h>
#include <TRK_MINNOW_DOLPHIN/mslsupp.h>


namespace MSL_C.PPCEABI.bare.H {
undefined4 initialized$16;

undefined4 __close_console(void)

{
  return 0;
}


undefined4
__write_console
          (undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = 0;
  if ((initialized_16 == 0) && (iVar1 = exi::InitializeUART(0xe100), iVar1 == 0)) {
    initialized_16 = 1;
  }
  if (iVar1 == 0) {
    iVar1 = exi::WriteUARTN(param_2,*param_3);
    if (iVar1 == 0) {
      TRK_MINNOW_DOLPHIN::__TRK_write_console(param_1,param_2,param_3,param_4);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
      *param_3 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

