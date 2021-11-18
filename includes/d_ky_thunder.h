#pragma once
#include <ctypes.h>

#include <f_pc_profile__Profile_Base.h>


namespace d_ky_thunder {
//[Data] Expected size is 0x000014
extern undefined * l_dThunder_Method;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Base g_profile_KY_THUNDER;

}

namespace d_ky_thunder {
undefined4 dThunder_Draw(dThunder_c *param_1);
undefined4 dThunder_Execute(dThunder_c *param_1);
undefined4 dThunder_IsDelete(void);
undefined4 dThunder_Delete(int param_1);
undefined4 dThunder_Create(dThunder_c *param_1);
}
