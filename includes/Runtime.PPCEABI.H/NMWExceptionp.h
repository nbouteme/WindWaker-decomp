#pragma once
#include <ctypes.h>



namespace Runtime.PPCEABI.H {
void __destroy_new_array(int param_1,code *param_2);
void __destroy_arr(int param_1,code *param_2,int param_3,int param_4);
void __construct_array(void *param_1,undefined *constructor,undefined *destructor,int elementSize,uint numElements);
}

namespace Runtime.PPCEABI.H {
int * __construct_new_array(int *param_1,code *param_2,code *param_3,int param_4,uint param_5);
}
