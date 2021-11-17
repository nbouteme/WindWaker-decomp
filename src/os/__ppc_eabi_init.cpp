#include <os/__ppc_eabi_init.h>
#include <os/__ppc_eabi_init.h>
#include <Runtime.PPCEABI.H/__init_cpp_exceptions.h>
#include <base/PPCArch.h>


namespace os {

void __init_user(void)

{
  __init_cpp();
  return;
}


void __init_cpp(void)

{
  undefined **ppuVar1;
  
  for (ppuVar1 = &Runtime.PPCEABI.H::__init_cpp_exceptions_reference;
      (code *)*ppuVar1 != (code *)0x0; ppuVar1 = (code **)ppuVar1 + 1) {
    (*(code *)*ppuVar1)();
  }
  return;
}


void _ExitProcess(void)

{
  base::PPCHalt();
  return;
}

