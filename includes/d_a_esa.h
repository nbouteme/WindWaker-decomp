#pragma once
#include <ctypes.h>



namespace d_a_esa {
//Expected size is 0x00000c
extern undefined4 ripple_scale$4426;

//Expected size is 0x00000c
extern undefined4 ripple_scale$4449;

//Expected size is 0x000001
extern undefined1 init$4428;

//Expected size is 0x000001
extern undefined1 init$4451;

undefined4 daEsa_Draw(fopAc_daEsa *param_1);
void bg_check(fopAc_daEsa *param_1);
void esa_1_move(fopAc_daEsa *param_1);
undefined4 daEsa_Execute(fopAc_daEsa *param_1);
undefined4 daEsa_IsDelete(void);
undefined4 daEsa_Delete(fopAc_daEsa *param_1);
bool daEsa_CreateHeap(fopAc_daEsa *param_1);
undefined4 daEsa_Create(fopAc_daEsa *param_1);
}
