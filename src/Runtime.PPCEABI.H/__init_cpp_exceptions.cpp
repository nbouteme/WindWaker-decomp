#include <Runtime.PPCEABI.H/__init_cpp_exceptions.h>
#include <Runtime.PPCEABI.H/Gecko_ExceptionPPCp.h>
#include <Runtime.PPCEABI.H/__init_cpp_exceptions.h>


namespace Runtime.PPCEABI.H {

/* __stdcall GetR2(void) */

undefined4 GetR2(void)

{
  return 0x803ffd00;
}


void __fini_cpp_exceptions(void)

{
  if (fragmentID != -2) {
    __unregister_fragment();
    fragmentID = -2;
  }
  return;
}


void __init_cpp_exceptions(void)

{
  undefined4 uVar1;
  
  if (fragmentID == -2) {
    uVar1 = GetR2();
    fragmentID = __register_fragment(&PTR__206_800056bc,uVar1);
  }
  return;
}

