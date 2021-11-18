#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>


namespace d_a_bg {
//[Data] Expected size is 0x000020
extern struct profile_method_class l_daBg_Method;

//[Data] Expected size is 0x000034
extern struct f_pc_profile__Profile_Actor g_profile_BG;

//[BSS] Expected size is 0x000020
extern undefined arcName$4148;
}

namespace d_a_bg {
undefined4 createMatAnm(int param_1,ushort param_2);
}

namespace d_a_bg {
void checkCreateHeap(daBg_c *param_1);
}

namespace d_a_bg {
undefined4 daBg_Draw(daBg_c *param_1);
undefined4 daBg_Execute(daBg_c *param_1);
uint daBg_IsDelete(int param_1);
undefined4 daBg_Delete(daBg_c *param_1);
void daBg_Create(daBg_c *param_1);
}
