#pragma once
#include <ctypes.h>

#include <f_pc_profile__Profile_Base.h>


namespace d_envse {
//[Data] Expected size is 0x000014
extern undefined * l_dEnvSe_Method;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Base g_profile_ENVSE;

undefined4 dEnvSe_Draw(void);
void dEnvSe_getNearPathPos(cXyz *param_1,cXyz *param_2,dPath *param_3);
}

namespace d_envse {
void dEnvSe_Execute(dEnvSe_c *param_1);
undefined4 dEnvSe_IsDelete(void);
undefined4 dEnvSe_Delete(int param_1);
undefined4 dEnvSe_Create(void);
}
