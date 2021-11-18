#pragma once
#include <ctypes.h>



namespace d_a_disappear {
//[Data] Expected size is 0x00000c
extern undefined ki_item_d$4029;

//[Data] Expected size is 0x000020
extern undefined * l_daDisappear_Method;

//[Data] Expected size is 0x000030
extern undefined g_profile_DISAPPEAR;

undefined4 daDisappear_Draw(void);
undefined4 daDisappear_Execute(base_process_class *param_1);
undefined4 daDisappear_IsDelete(void);
undefined4 daDisappear_Delete(void);
void set_disappear(double param_1,int param_2);
undefined4 daDisappear_Create(fopAc_ac_c *param_1);
}
