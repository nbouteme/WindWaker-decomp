#include <MSL_C.PPCEABI.bare.H/buffer_io.h>


namespace MSL_C.PPCEABI.bare.H {

int __flush_buffer(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1[9] - param_1[7] != 0) {
    param_1[10] = param_1[9] - param_1[7];
    iVar1 = (*(code *)param_1[0x10])(*param_1,param_1[7],param_1 + 10,param_1[0x12]);
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = param_1[10];
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    param_1[6] = param_1[6] + param_1[10];
  }
  param_1[9] = param_1[7];
  param_1[10] = param_1[8];
  param_1[10] = param_1[10] - (param_1[6] & param_1[0xb]);
  param_1[0xd] = param_1[6];
  return 0;
}


void __prep_buffer(int param_1)

{
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x20);
  *(uint *)(param_1 + 0x28) =
       *(int *)(param_1 + 0x28) - (*(uint *)(param_1 + 0x18) & *(uint *)(param_1 + 0x2c));
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x18);
  return;
}

