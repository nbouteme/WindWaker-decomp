#pragma once
#include <ctypes.h>

#include <f_pc_profile__Profile_Actor.h>


namespace d_ovlp_fade2 {
//[Data] Expected size is 0x000014
extern undefined * l_dOvlpFd2_Method;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Actor g_profile_OVERLAP2;

//[Data] Expected size is 0x000028
extern enum fopAcM__Status g_profile_OVERLAP3;

}
//[Data] Expected size is 0x000010
extern pointer dOvlpFd2_dlst_c;


namespace d_ovlp_fade2 {
undefined4 dOvlpFd2_Draw(int param_1);
undefined4 dOvlpFd2_Execute(void *param_1,void *param_2);
undefined4 dOvlpFd2_IsDelete(void);
undefined4 dOvlpFd2_Delete(void);
undefined4 dOvlpFd2_Create(dOvlpFd2_c *param_1);
char cLib_calcTimer(char *param_1);
}
