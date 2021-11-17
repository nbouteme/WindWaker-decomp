#include <Runtime.PPCEABI.H/global_destructor_chain.h>


namespace Runtime.PPCEABI.H {
undefined4 __global_destructor_chain;

void __destroy_global_chain(void)

{
  code **ppcVar1;
  undefined4 *puVar2;
  
  while (__global_destructor_chain != (int *)0x0) {
    ppcVar1 = (code **)(__global_destructor_chain + 1);
    puVar2 = __global_destructor_chain + 2;
    __global_destructor_chain = (int *)*__global_destructor_chain;
    (**ppcVar1)(*puVar2,0xffffffff);
  }
  return;
}


void __register_global_object
               (undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_3 = __global_destructor_chain;
  param_3[1] = param_2;
  param_3[2] = param_1;
  __global_destructor_chain = param_3;
  return;
}

