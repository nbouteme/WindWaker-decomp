#include <TRK_MINNOW_DOLPHIN/usr_put.h>
#include <TRK_MINNOW_DOLPHIN/msghndlr.h>
#include <m_Do_printf.h>


namespace TRK_MINNOW_DOLPHIN {

void usr_put_initialize(void)

{
  return;
}


void usr_puts_serial(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  char local_18;
  undefined local_17;
  
  while( true ) {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    if (cVar1 == '\0') break;
    uVar2 = GetTRKConnected();
    local_17 = 0;
    local_18 = cVar1;
    SetTRKConnected(0);
    m_Do_printf::OSReport(&local_18);
    SetTRKConnected(uVar2);
  }
  return;
}

