#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>


namespace d_a_vrbox {
//[Data] Expected size is 0x000020
extern struct profile_method_class l_daVrbox_Method;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_VRBOX;

undefined4 daVrbox_Draw(vrbox_class *param_1);
undefined4 daVrbox_color_set(vrbox_class *param_1);
}

namespace d_a_vrbox {
void dungeon_rain_proc(void);
undefined4 daVrbox_Execute(void);
undefined4 daVrbox_IsDelete(void);
undefined4 daVrbox_Delete(void);
undefined4 daVrbox_solidHeapCB(vrbox_class *param_1);
undefined4 daVrbox_Create(vrbox_class *param_1);
}
