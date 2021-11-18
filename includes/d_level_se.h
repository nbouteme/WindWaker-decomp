#pragma once
#include <ctypes.h>



namespace d_level_se {
//[Data] Expected size is 0x000014
extern undefined * l_dLevelSe_Method;

//[Data] Expected size is 0x000028
extern undefined g_profile_LEVEL_SE;

undefined4 dLevelSe_Execute(int param_1);
undefined4 dLevelSe_IsDelete(void);
undefined4 dLevelSe_Delete(int param_1);
undefined4 dLevelSe_Create(void);
}
