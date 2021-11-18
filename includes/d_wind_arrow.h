#pragma once
#include <ctypes.h>

#include <f_pc_profile__Profile_Base.h>


namespace d_wind_arrow {
//[Data] Expected size is 0x000014
extern undefined * l_dWindArrow_Method;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Base g_profile_WIND_ARROW;

}

namespace d_wind_arrow {
void dWindArrow_Draw(dWindArrow_c *param_1);
}

namespace d_wind_arrow {
undefined4 dWindArrow_Execute(int param_1);
undefined4 dWindArrow_IsDelete(void);
undefined4 dWindArrow_Delete(int param_1);
undefined4 dWindArrow_Create(dWindArrow_c *param_1);
}
