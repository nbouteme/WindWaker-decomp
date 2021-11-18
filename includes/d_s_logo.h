#pragma once
#include <ctypes.h>

#include <f_pc_profile__Profile_Base.h>


namespace d_s_logo {
//[Data] Expected size is 0x00002c
extern undefined * l_execFunc$4864;

//[Data] Expected size is 0x00000c
extern undefined * l_method$5571;

//[Data] Expected size is 0x000014
extern undefined * l_dScnLogo_Method;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Base g_profile_LOGO_SCENE;

//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_anmCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_fmapCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_itemResCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_fmapResCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_dmapResCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_clctResCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_optResCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_saveResCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_clothResCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_itemiconCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_actioniconCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_scopeResCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_camResCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_swimResCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_windResCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_nameResCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_tmsgCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_dmsgCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_errorResCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_msgDtCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_msgDtCommand2;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_msgCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_menuCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_fontCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_rubyCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_particleCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_itemTableCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_ActorDataCommand;
//[BSS] Expected size is 0x000004
extern struct mDoDvdThd_mountXArchive_c * l_FmapDataCommand;
//[BSS] Expected size is 0x000004
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
