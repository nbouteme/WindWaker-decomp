#pragma once
#include <ctypes.h>

#include <f_pc_profile__Profile_Base.h>


namespace d_kyeff2 {
//[Data] Expected size is 0x000014
extern undefined * l_dKyeff2_Method;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Base g_profile_KYEFF2;

undefined4 dKyeff2_Draw(void);
}

namespace d_kyeff2 {
void dKyeff2_Execute(dKyeff2_c *param_1);
undefined4 dKyeff2_IsDelete(void);
undefined4 dKyeff2_Delete(void);
undefined4 dKyeff2_Create(void);
}
