#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>


namespace d_a_demo00 {
//[Data] Expected size is 0x000018
extern undefined l_lightData;

//[Data] Expected size is 0x000020
extern struct profile_method_class l_daDemo00_Method;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_DEMO00;

}
//[Data] Expected size is 0x00000c
extern undefined mDoExt_btpAnm;


namespace d_a_demo00 {
undefined4 awaCheck(J3DModel *param_1);
void createHeapCallBack(daDemo00_c *param_1);
}

namespace d_a_demo00 {
void daDemo00_Draw(daDemo00_c *param_1);
}

namespace d_a_demo00 {
void daDemo00_Execute(daDemo00_c *param_1);
}

namespace d_a_demo00 {
undefined4 daDemo00_IsDelete(void);
undefined4 daDemo00_Delete(daDemo00_c *param_1);
undefined4 daDemo00_Create(fopAc_ac_c *param_1);
}
