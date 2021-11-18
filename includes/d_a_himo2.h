#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>
#include <Demangler/dCcD_SrcSph.h>


namespace d_a_himo2 {
//[Data] Expected size is 0x000040
extern struct dCcD_SrcSph sph_src$5934;

//[Data] Expected size is 0x000020
extern struct profile_method_class l_daHimo2_Method;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_HIMO2;

}

namespace mDoExt_3DlineMat_c {
//[Data] Expected size is 0x000014
extern undefined __vt;

}
//[Data] Expected size is 0x00000c
extern undefined1 himo2HIO_c;


namespace d_a_himo2 {
//[BSS] Expected size is 0x000024
extern undefined4 l_himo2HIO;
//[BSS] Expected size is 0x000004
extern float rope_scale;
//[BSS] Expected size is 0x000004
extern undefined4 btd;
//[BSS] Expected size is 0x000004
extern undefined4 dr;
void spin_draw(int param_1);
void himo2_control(int param_1,int param_2);
void himo2_control2(int param_1,int param_2);
void himo2_draw(int param_1,int param_2);
void himo_hang_draw(int param_1);
void himo2_disp(int param_1);
undefined4 daHimo2_Draw(int param_1);
undefined4 s_a_d_sub(fopAc_ac_c *param_1,int param_2);
int search_target(void *param_1,float *param_2);
}

namespace d_a_himo2 {
fopAc_ac_c * dr_a_sub(fopAc_ac_c *param_1);
fopAc_ac_c * b_a_sub(fopAc_ac_c *param_1);
undefined4 himo2_bg_check(int param_1);
void pl_pos_add(int param_1);
void new_himo2_move(fopAc_ac_c *param_1);
double cM_scos(uint param_1);
double cM_ssin(uint param_1);
}

namespace d_a_himo2 {
undefined4 daHimo2_Execute(void *param_1);
undefined4 daHimo2_IsDelete(void);
undefined4 daHimo2_Delete(void);
bool CallbackCreateHeap(int param_1);
undefined4 daHimo2_Create(fopAc_ac_c *param_1);
void __sinit_d_a_himo2_cpp(void);
}

namespace d_a_himo2 {
void dComIfGs_isEventBit(ushort param_1);
char * dComIfGp_getStartStageName(void);
void fopAcM_searchPlayerAngleY(fopAc_ac_c *param_1);
void dComIfGp_event_reset(void);
void mDoAud_seStart(ulong param_1,cXyz *param_2,ulong param_3,sbyte param_4);
void fopAcM_OnStatus(int param_1,uint param_2);
void fopAcM_seStartCurrent(int param_1,ulong param_2,ulong param_3);
}

namespace d_a_himo2 {
void dComIfGs_onEventBit(ushort param_1);
void fopAcM_OffStatus(int param_1,uint param_2);
undefined4 fopAcM_GetID(int param_1);
undefined4 fopAcM_GetParam(int param_1);
}

namespace d_a_himo2 {
int fopAcM_GetName(int param_1);
void fopAcM_seStart(int param_1,ulong param_2,ulong param_3);
void fopAcM_SetParam(int param_1,undefined4 param_2);
}

namespace d_a_himo2 {
daPy_lk_c * daPy_getPlayerLinkActorClass(void);
}

namespace d_a_himo2 {
undefined4 dComIfGp_getAttention(void);
}

namespace d_a_himo2 {
camera_class * dComIfGp_getCamera(int param_1);
int dComIfGp_getPlayerCameraID(int param_1);
daPy_lk_c * dComIfGp_getPlayer(int param_1);
}
