#pragma once
#include <ctypes.h>

#include <f_pc_profile__Profile_Base.h>


namespace d_s_name {
//[Data] Expected size is 0x00000c
extern pointer l_method$4165;

//[Data] Expected size is 0x0000c0
extern undefined4 MainProc;

//[Data] Expected size is 0x0000cc
extern undefined4 MemCardCheckProc;

//[Data] Expected size is 0x000018
extern undefined4 NameOpenProc;

//[Data] Expected size is 0x000018
extern undefined4 FileSelOpenProc;

//[Data] Expected size is 0x00003c
extern undefined4 DrawProc;

//[Data] Expected size is 0x000014
extern undefined * l_dScnName_Method;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Base g_profile_NAME_SCENE;

//[Data] Expected size is 0x000028
extern undefined g_profile_NAMEEX_SCENE;

}
//[Data] Expected size is 0x000010
extern undefined1 dDlst_FLSEL_CLOTH_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_BTICN_c;

//[Data] Expected size is 0x00000c
extern undefined1 dSn_HIO_c;


namespace d_s_name {
//[BSS] Expected size is 0x00001c
extern undefined g_snHIO;
}

namespace d_s_name {
undefined4 phase_1(char *param_1);
uint phase_2(char *param_1);
undefined4 phase_3(void);
undefined4 resLoad(request_of_phase_process_class *param_1,void *param_2);
}

namespace d_s_name {
void dScnName_Draw(dScnName_c *param_1);
void dScnName_Execute(dScnName_c *param_1);
undefined4 dScnName_IsDelete(void);
undefined4 dScnName_Delete(dScnName_c *param_1);
void dScnName_Create(dScnName_c *param_1);
}

namespace d_s_name {
void __sinit_d_s_name_cpp(void);
}
