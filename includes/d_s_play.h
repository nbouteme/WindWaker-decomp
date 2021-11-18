#pragma once
#include <ctypes.h>

#include <dScnPly_reg_HIO_c.h>
#include <dScnPly_dark_HIO_c.h>
#include <f_pc_profile__Profile_Base.h>
#include <dScnPly_msg_HIO_c.h>


namespace d_s_play {
//[Data] Expected size is 0x000018
extern undefined l_wipeType$4411;

//[Data] Expected size is 0x000014
extern undefined * sea_resName;

//[Data] Expected size is 0x00005c
extern undefined * M_Dai_resName;

//[Data] Expected size is 0x000054
extern undefined * majroom_resName;

//[Data] Expected size is 0x000060
extern undefined * ma2room_resName;

//[Data] Expected size is 0x000044
extern undefined * ma3room_resName;

//[Data] Expected size is 0x00008c
extern undefined * M_NewD2_resName;

//[Data] Expected size is 0x00008c
extern undefined * kindan_resName;

//[Data] Expected size is 0x000064
extern undefined * kaze_resName;

//[Data] Expected size is 0x00000e
extern undefined Siren_dylKeyTbl;

//[Data] Expected size is 0x000028
extern undefined * Siren_resName;

//[Data] Expected size is 0x000016
extern undefined GanonJ_dylKeyTbl;

//[Data] Expected size is 0x000038
extern undefined * GanonJ_resName;

//[Data] Expected size is 0x00001a
extern undefined GanonK_dylKeyTbl;

//[Data] Expected size is 0x000020
extern undefined * GanonK_resName;

//[Data] Expected size is 0x00000a
extern undefined GanonM_dylKeyTbl;

//[Data] Expected size is 0x000014
extern undefined * GanonM_resName;

//[Data] Expected size is 0x000028
extern undefined * l_method$5457;

//[Data] Expected size is 0x000014
extern undefined * l_dScnPly_Method;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Base g_profile_PLAY_SCENE;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Base g_profile_OPENING_SCENE;

//[Data] Expected size is 0x000028
extern undefined g_profile_OPENING2_SCENE;

}
//[Data] Expected size is 0x00000c
extern pointer dScnPly_msg_HIO_c;

//[Data] Expected size is 0x00000c
extern undefined1 dScnPly_env_debugHIO_c;

//[Data] Expected size is 0x00000c
extern undefined1 dScnPly_env_otherHIO_c;

//[Data] Expected size is 0x00000c
extern pointer dScnPly_reg_childHIO_c;

//[Data] Expected size is 0x00000c
extern pointer dScnPly_dark_HIO_c;

//[Data] Expected size is 0x00000c
extern pointer dScnPly_preLoad_HIO_c;

//[Data] Expected size is 0x00000c
extern pointer dScnPly_env_HIO_c;

//[Data] Expected size is 0x00000c
extern pointer dScnPly_reg_HIO_c;


namespace d_s_play {
//[Data] Expected size is 0x000004
extern undefined M_DragB_resName;

//[Data] Expected size is 0x000008
extern undefined * kinBOSS_resName;

//[Data] Expected size is 0x000004
extern undefined * M_DaiB_resName;

//[Data] Expected size is 0x000004
extern undefined * SirenB_resName;

//[Data] Expected size is 0x000001
extern undefined1 preLoadNo;

//[Data] Expected size is 0x000001
extern undefined1 doPreLoad;

//[BSS] Expected size is 0x000028
extern struct dScnPly_dark_HIO_c g_darkHIO;
//[BSS] Expected size is 0x000c68
extern struct dScnPly_reg_HIO_c g_regHIO;
//[BSS] Expected size is 0x000080
extern undefined4 g_envHIO;
//[BSS] Expected size is 0x000014
extern struct dScnPly_msg_HIO_c g_msgDHIO;
//[BSS] Expected size is 0x000023
extern undefined number_of_resPhase;
//[BSS] Expected size is 0x00001b
extern undefined number_of_dylPhase;
//[BSS] Expected size is 0x000118
extern struct request_of_phase_process_class resPhase[10];
//[BSS] Expected size is 0x0000d8
extern undefined dylPhase;
}
//[BSS] Expected size is 0x000001
extern byte dScnPly_ply_c;
//[BSS] Expected size is 0x000001
extern byte dScnPly_ply_c;

namespace d_s_play {
//[BSS] Expected size is 0x000008
extern undefined4 dylPreLoadTime1;
//[BSS] Expected size is 0x000008
extern undefined4 resPreLoadTime0;
//[BSS] Expected size is 0x000008
extern undefined4 resPreLoadTime1;
//[BSS] Expected size is 0x000004
extern undefined4 g_preLoadHIO;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_lkDemoAnmCommand;
}

namespace d_s_play {
undefined4 dScnPly_Draw(int param_1);
undefined4 dScnPly_Execute(dScnPly_ply_c *param_1);
undefined4 dScnPly_IsDelete(void);
undefined4 dScnPly_Delete(undefined4 param_1,undefined4 param_2,short param_3);
undefined4 heapSizeCheck(void);
undefined4 phase_00(dScnPly_ply_c *param_1);
byte phase_01(void);
undefined4 phase_0(dScnPly_ply_c *param_1);
undefined4 phase_1(dScnPly_ply_c *param_1);
undefined4 phase_2(dScnPly_ply_c *pPly);
undefined4 phase_3(int param_1);
undefined4 phase_4(dScnPly_ply_c *pPly);
int phase_5(void);
int phase_6(undefined4 param_1,undefined4 param_2,char *param_3);
undefined4 phase_compleate(void);
void dScnPly_Create(dScnPly_ply_c *param_1);
}

namespace d_s_play {
void __sinit_d_s_play_cpp(void);
}
