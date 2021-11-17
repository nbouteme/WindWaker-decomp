#pragma once
#include <ctypes.h>



namespace d_envse {
undefined4 dEnvSe_Draw(void);
void dEnvSe_getNearPathPos(cXyz *param_1,cXyz *param_2,dPath *param_3);
}

namespace d_envse {
void dEnvSe_Execute(dEnvSe_c *param_1);
undefined4 dEnvSe_IsDelete(void);
undefined4 dEnvSe_Delete(int param_1);
undefined4 dEnvSe_Create(void);
}
