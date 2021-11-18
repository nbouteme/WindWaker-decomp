#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>


namespace d_a_ib {
//[Data] Expected size is 0x000018
extern undefined4 mode_proc$4231;

}
//[Data] Expected size is 0x000044
extern undefined1 daIball_c;


namespace d_a_ib {
//[Data] Expected size is 0x000020
extern struct profile_method_class l_daIball_Method;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_Iball;

//[BSS] Expected size is 0x000001
extern undefined1 init$4234;
}

namespace d_a_ib {
undefined4 itemParamSet_CB(int param_1);
}

namespace d_a_ib {
void CheckCreateHeap(daIball_c *param_1);
}

namespace d_a_ib {
void daIball_Create(daIball_c *param_1);
void daIball_Draw(daIball_c *param_1);
void daIball_Delete(daIball_c *param_1);
undefined4 daIball_IsDelete(void);
void daIball_Execute(daIball_c *param_1);
}
