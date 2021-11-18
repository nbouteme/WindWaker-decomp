#pragma once
#include <ctypes.h>

#include <f_pc_profile__Profile_Base.h>


namespace d_s_title {
//[Data] Expected size is 0x000014
extern undefined * l_dScnTitle_Method;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Base g_profile_TITLE_SCENE;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Base g_profile_ENDING_SCENE;

undefined4 dScnTitle_Draw(void);
undefined4 dScnTitle_Execute(scene_class *param_1);
undefined4 dScnTitle_IsDelete(void);
undefined4 dScnTitle_Delete(void);
undefined4 dScnTitle_Create(scene_class *this);
}
