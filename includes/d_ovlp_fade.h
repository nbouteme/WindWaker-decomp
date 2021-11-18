#pragma once
#include <ctypes.h>

#include <f_pc_profile__Profile_Actor.h>


namespace d_ovlp_fade {
//[Data] Expected size is 0x000014
extern undefined * l_dOvlpFd_Method;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Actor g_profile_OVERLAP0;

//[Data] Expected size is 0x000028
extern enum fopAcM__Status g_profile_OVERLAP1;

//[Data] Expected size is 0x000028
extern undefined g_profile_OVERLAP6;

//[Data] Expected size is 0x000028
extern undefined g_profile_OVERLAP7;

//[Data] Expected size is 0x000028
extern undefined g_profile_OVERLAP8;

//[BSS] Expected size is 0x000004
extern undefined4 dOvlpFd_execute_f;
undefined4 dOvlpFd_Draw(void);
undefined4 dOvlpFd_FadeOut(int param_1);
undefined4 dOvlpFd_Wait(void);
undefined4 dOvlpFd_FadeIn(int param_1);
undefined4 dOvlpFd_Execute(void);
undefined4 dOvlpFd_IsDelete(void);
undefined4 dOvlpFd_Delete(void);
undefined4 dOvlpFd_Create(void);
}
