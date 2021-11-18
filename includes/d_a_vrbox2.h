#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>


namespace d_a_vrbox2 {
//[Data] Expected size is 0x000020
extern struct profile_method_class l_daVrbox2_Method;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_VRBOX2;

//[Data] Expected size is 0x000004
extern undefined1 l_zmodeInfo;

void texScrollCheck(float *param_1);
undefined4 daVrbox2_Draw(vrbox2_class *param_1);
undefined4 daVrbox2_color_set(vrbox2_class *param_1);
undefined4 daVrbox2_Execute(void);
undefined4 daVrbox2_IsDelete(void);
undefined4 daVrbox2_Delete(void);
undefined4 daVrbox2_solidHeapCB(vrbox2_class *param_1);
undefined4 daVrbox2_Create(fopAc_ac_c *param_1);
}
