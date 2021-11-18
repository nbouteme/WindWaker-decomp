#pragma once
#include <ctypes.h>

#include <f_pc_profile__Profile_Base.h>


namespace d_menu_window {
//[Data] Expected size is 0x000014
extern undefined * l_dMs_Method;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Base g_profile_MENUWINDOW;

}
//[Data] Expected size is 0x00000c
extern undefined1 dName_c;

//[Data] Expected size is 0x00000c
extern undefined1 dMenu_Fmap2_c;

//[Data] Expected size is 0x00000c
extern undefined1 dMenu_Fmap_c;

//[Data] Expected size is 0x00000c
extern undefined1 dMw_DHIO_c;

//[Data] Expected size is 0x00000c
extern undefined1 dMw_HIO_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_MENU_CLOTH_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_MENU_CAPTURE_c;


namespace d_menu_window {
//[Data] Expected size is 0x000001
extern undefined1 lockFlag;

//[BSS] Expected size is 0x00000c
extern undefined1 dMv_CIO_c;
//[BSS] Expected size is 0x0000e8
extern undefined g_mwHIO;
//[BSS] Expected size is 0x0000c8
extern undefined g_mwDHIO;
//[BSS] Expected size is 0x000004
extern undefined4 cloth_c;
//[BSS] Expected size is 0x000004
extern undefined4 fonttype;
//[BSS] Expected size is 0x000004
extern undefined4 rfonttype;
//[BSS] Expected size is 0x000004
extern struct dDlst_MENU_CAPTURE_c * dMs_capture_c;
//[BSS] Expected size is 0x000004
extern undefined4 dMs_cloth_c;
//[BSS] Expected size is 0x000004
extern undefined4 dMi_c;
//[BSS] Expected size is 0x000004
extern undefined4 dMc_c;
//[BSS] Expected size is 0x000004
extern undefined4 dMd_c;
//[BSS] Expected size is 0x000004
extern undefined4 dMf_c;
//[BSS] Expected size is 0x000004
extern undefined4 dNm_c;
//[BSS] Expected size is 0x000004
extern undefined4 dMs_c;
//[BSS] Expected size is 0x000001
extern undefined1 event_wait_frame;
//[BSS] Expected size is 0x000002
extern undefined2 timer$7109;
//[BSS] Expected size is 0x000001
extern undefined1 init$7110;
}

namespace d_menu_window {
void dMs_item_create(int param_1);
void dMs_item_delete(int param_1);
void dMs_collect_create(int param_1);
void dMs_collect_create2(int param_1);
void dMs_collect_delete(int param_1);
void dMs_fmap_create(int param_1);
void dMs_fmap_delete(int param_1);
void dMs_dmap_create(int param_1);
void dMs_dmap_delete(int param_1);
void dMs_name_create(void);
void dMs_name_delete(void);
void dMs_save_delete(void);
void dMs_cloth_create(int param_1,EVP_PKEY_CTX *param_2);
void dMs_cloth_delete(int param_1);
void dMs_clothOnly_create(undefined4 param_1,EVP_PKEY_CTX *param_2);
void dMs_clothOnly_delete(void);
void dMs_onButtonBit(int param_1,byte param_2);
void dMs_offButtonBit(int param_1,byte param_2);
bool dMs_isButtonBit(int param_1,byte param_2);
undefined4 dMs_isPush_L_Button(undefined4 param_1);
undefined4 dMs_isPush_R_Button(undefined4 param_1);
void dMs_childHeap_freeAll(int param_1);
void dMs_telescopeMove(int param_1);
void dMs_placenameMove(void);
undefined4 dMs_Draw(void);
undefined4 dMs_Execute(int param_1);
undefined4 dMs_IsDelete(void);
undefined4 dMs_Delete(int param_1);
undefined4 dMs_Create(sub_ms_screen_class *this);
}

namespace d_menu_window {
void __sinit_d_menu_window_cpp(void);
}
