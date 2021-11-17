#pragma once
#include <ctypes.h>



namespace d_operate_wind {
//Expected size is 0x00001c
extern undefined g_owHIO;

//Expected size is 0x000001
extern undefined1 wind_flag$5173;

//Expected size is 0x000001
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
