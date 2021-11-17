#pragma once
#include <ctypes.h>



namespace MSL_C.PPCEABI.bare.H {
//Expected size is 0x000038
extern undefined4 protopool$192;

//Expected size is 0x000001
extern undefined1 init$193;

void free(void *__ptr);
void deallocate_from_fixed_pools(int **param_1,int **param_2,uint param_3);
void SubBlock_merge_next(uint *param_1,uint **param_2);
void Block_link(int param_1,uint *param_2);
}
