#include <MSL_C.PPCEABI.bare.H/abort_exit.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <os/__ppc_eabi_init.h>


namespace MSL_C.PPCEABI.bare.H {
undefined __atexit_funcs;
undefined4 __aborting;
undefined4 __atexit_curr_func;
undefined4 __stdio_exit;
undefined4 __console_exit;

void exit(int __status)

{
  undefined **ppuVar1;
  
  if (__aborting == 0) {
    Runtime.PPCEABI.H::__destroy_global_chain();
    for (ppuVar1 = &Runtime.PPCEABI.H::__destroy_global_chain_reference;
        (code *)*ppuVar1 != (code *)0x0; ppuVar1 = (code **)ppuVar1 + 1) {
      (*(code *)*ppuVar1)();
    }
    if (__stdio_exit != (code *)0x0) {
      (*__stdio_exit)();
      __stdio_exit = (code *)0x0;
    }
  }
  while (0 < __atexit_curr_func) {
    __atexit_curr_func = __atexit_curr_func + -1;
    (**(code **)(&__atexit_funcs + __atexit_curr_func * 4))();
  }
  if (__console_exit != (code *)0x0) {
    (*__console_exit)();
    __console_exit = (code *)0x0;
  }
  os::_ExitProcess();
  return;
}

