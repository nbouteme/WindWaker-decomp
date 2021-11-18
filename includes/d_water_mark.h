#pragma once
#include <ctypes.h>

#include <f_pc_profile__Profile_Base.h>


namespace d_water_mark {
//[Data] Expected size is 0x000014
extern undefined * l_dWaterMark_Method;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Base g_profile_WATER_MARK;

}
//[BSS] Expected size is 0x000054
extern undefined1 dWaterMark_c;
//[BSS] Expected size is 0x000002
extern undefined1 dWaterMark_c;
//[BSS] Expected size is 0x000002
extern undefined1 dWaterMark_c;

namespace d_water_mark {
undefined4 dWaterMark_Draw(int param_1);
}

namespace d_water_mark {
undefined4 dWaterMark_Execute(dWaterMark_c *param_1);
undefined4 dWaterMark_IsDelete(void);
undefined4 dWaterMark_Delete(int param_1);
void dWaterMark_Create(dWaterMark_c *param_1);
}
