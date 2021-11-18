#pragma once
#include <ctypes.h>



namespace d_operate_wind {
//[Data] Expected size is 0x000014
extern undefined * l_dOperate_wind_Method;

//[Data] Expected size is 0x000028
extern undefined g_profile_OPERATE_WIND;

}
//[Data] Expected size is 0x00000c
extern undefined1 dOperate_wind_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_Ow_mask_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_Ow_main_c;

//[Data] Expected size is 0x00000c
extern undefined1 dOw_HIO_c;


namespace d_operate_wind {
//[BSS] Expected size is 0x00001c
extern undefined g_owHIO;
//[BSS] Expected size is 0x000001
extern undefined1 wind_flag$5173;
//[BSS] Expected size is 0x000001
extern undefined1 init$5174;
}

namespace d_operate_wind {
undefined4 dOw_Draw(int param_1);
undefined4 dOw_Execute(int param_1);
undefined4 dOw_IsDelete(void);
undefined4 dOw_Delete(dOw_c *param_1);
undefined4 dOw_Create(dOw_c *param_1);
}

namespace d_operate_wind {
void __sinit_d_operate_wind_cpp(void);
}
