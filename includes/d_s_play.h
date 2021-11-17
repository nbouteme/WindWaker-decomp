#pragma once
#include <ctypes.h>

#include <dScnPly_reg_HIO_c.h>
#include <dScnPly_dark_HIO_c.h>
#include <dScnPly_msg_HIO_c.h>


namespace d_s_play {
//Expected size is 0x000028
extern struct dScnPly_dark_HIO_c g_darkHIO;

//Expected size is 0x000c68
extern struct dScnPly_reg_HIO_c g_regHIO;

//Expected size is 0x000080
extern undefined4 g_envHIO;

//Expected size is 0x000014
extern struct dScnPly_msg_HIO_c g_msgDHIO;

//Expected size is 0x000023
extern undefined number_of_resPhase;

//Expected size is 0x00001b
extern undefined number_of_dylPhase;

//Expected size is 0x000118
extern struct request_of_phase_process_class resPhase[10];

//Expected size is 0x0000d8
extern undefined dylPhase;

}
//Expected size is 0x000001
extern byte dScnPly_ply_c;

//Expected size is 0x000001
extern byte dScnPly_ply_c;


namespace d_s_play {
//Expected size is 0x000008
extern undefined4 dylPreLoadTime1;

//Expected size is 0x000008
extern undefined4 resPreLoadTime0;

//Expected size is 0x000008
extern undefined4 resPreLoadTime1;

//Expected size is 0x000004
extern undefined4 g_preLoadHIO;

//Expected size is 0x000004
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
