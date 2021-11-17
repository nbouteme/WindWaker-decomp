#pragma once
#include <ctypes.h>



namespace d_s_logo {
//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_anmCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_fmapCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_itemResCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_fmapResCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_dmapResCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_clctResCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_optResCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_saveResCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_clothResCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_itemiconCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_actioniconCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_scopeResCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_camResCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_swimResCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_windResCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_nameResCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_tmsgCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_dmsgCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_errorResCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_msgDtCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_msgDtCommand2;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_msgCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_menuCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_fontCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_rubyCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_particleCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_itemTableCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_ActorDataCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_FmapDataCommand;

//Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_lodCommand;

void checkProgSelect(int param_1);
undefined4 nintendoInDraw(int param_1);
undefined4 nintendoOutDraw(int param_1);
undefined4 nintendoOut2Draw(int param_1);
undefined4 progInDraw(int param_1);
undefined4 progSelDraw(int param_1);
undefined4 progOutDraw(int param_1);
undefined4 progSetDraw(int param_1);
undefined4 progChangeDraw(int param_1);
undefined4 dolbyInDraw(int param_1);
undefined4 dolbyOutDraw(int param_1);
undefined4 dvdWaitDraw(scene_class *param_1,undefined4 param_2,int param_3);
void dScnLogo_Draw(int param_1);
undefined4 dScnLogo_Execute(undefined4 param_1);
undefined4 dScnLogo_IsDelete(void);
undefined4 dScnLogo_Delete(int param_1);
undefined4 phase_0(int param_1);
undefined4 phase_1(int param_1,undefined4 param_2,int param_3);
mDoDvdThd_mountXArchive_c * aramMount(char *param_1);
mDoDvdThd_mountXArchive_c * onMemMount(char *param_1);
undefined4 phase_2(int param_1);
void dScnLogo_Create(void *param_1);
}
