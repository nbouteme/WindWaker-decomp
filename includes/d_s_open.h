#pragma once
#include <ctypes.h>



namespace d_s_open {
//[Data] Expected size is 0x000014
extern undefined * l_dScnOpen_Method;

//[Data] Expected size is 0x000028
extern undefined g_profile_OPEN_SCENE;

//[Data] Expected size is 0x000028
extern undefined g_profile_OPEN2_SCENE;

}

namespace d_s_open {
void dScnOpen_Draw(dScnOpen_c *param_1);
void dScnOpen_Execute(dScnOpen_c *param_1);
undefined4 dScnOpen_IsDelete(void);
undefined4 dScnOpen_Delete(dScnOpen_c *param_1);
void dScnOpen_Create(dScnOpen_c *param_1);
}
