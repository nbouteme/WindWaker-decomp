#include <os/OSArena.h>


namespace os {
undefined4 __OSArenaHi;

undefined4 OSGetArenaHi(void)

{
  return __OSArenaHi;
}


undefined4 OSGetArenaLo(void)

{
  return __OSArenaLo;
}


void OSSetArenaHi(undefined4 param_1)

{
  __OSArenaHi = param_1;
  return;
}


void OSSetArenaLo(undefined4 param_1)

{
  __OSArenaLo = param_1;
  return;
}


uint OSAllocFromArenaLo(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 - 1;
  uVar2 = ~uVar1 & __OSArenaLo + uVar1;
  __OSArenaLo = ~uVar1 & uVar2 + param_1 + uVar1;
  return uVar2;
}

