#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>


namespace d_a_hookshot {
//[Data] Expected size is 0x000200
extern undefined l_chainS3TCTEX;

//[Data] Expected size is 0x000090
extern undefined l_pos;

//[Data] Expected size is 0x000060
extern undefined l_texCoord;

//[Data] Expected size is 0x00007a
extern undefined l_chainDL;

//[Data] Expected size is 0x0000a8
extern undefined l_matDL;

//[Data] Expected size is 0x00004c
extern undefined l_at_cps_src;

//[Data] Expected size is 0x000020
extern struct profile_method_class l_daHookshot_Method;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_HOOKSHOT;

}
//[Data] Expected size is 0x000030
extern pointer dBgS_RopeLinChk;

//[Data] Expected size is 0x000018
extern undefined1 daHookshot_shape;


namespace d_a_hookshot {
void daHookshot_Draw(daHookshot_c *param_1);
void daHookshot_rockLineCallback(int param_1,int param_2,int param_3);
}

namespace d_a_hookshot {
void daHookshot_Execute(daHookshot_c *param_1);
undefined4 daHookshot_IsDelete(void);
}

namespace d_a_hookshot {
undefined4 daHookshot_Delete(daHookshot_c *param_1);
}

namespace d_a_hookshot {
void daHookshot_Create(daHookshot_c *param_1);
void __sinit_d_a_hookshot_cpp(void);
}
