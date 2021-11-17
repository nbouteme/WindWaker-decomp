#include <d_s_logo.h>
#include <os/OSReset.h>
#include <vi/vi.h>
#include <os/OSRtc.h>
#include <d_drawlist.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_resorce.h>
#include <d_com_inf_game.h>
#include <d_a_npc_fa1.h>
#include <f_op_scene_mng.h>
#include <m_Do_Reset.h>
#include <d_particle.h>
#include <m_Do_ext.h>
#include <d_s_actor_data_mng.h>
#include <JKernel/JKRAramHeap.h>
#include <c_dylink.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKernel/JKRHeap.h>
#include <m_Do_dvd_thread.h>
#include <d_s_logo.h>
#include <JFramework/JFWDisplay.h>
#include <d_com_lib_game.h>


namespace d_s_logo {
struct mDoDvdThd_mountXArchive_c * l_anmCommand;
struct mDoDvdThd_mountXArchive_c * l_fmapCommand;
struct mDoDvdThd_mountXArchive_c * l_itemResCommand;
struct mDoDvdThd_mountXArchive_c * l_fmapResCommand;
struct mDoDvdThd_mountXArchive_c * l_dmapResCommand;
struct mDoDvdThd_mountXArchive_c * l_clctResCommand;
struct mDoDvdThd_mountXArchive_c * l_optResCommand;
struct mDoDvdThd_mountXArchive_c * l_saveResCommand;
struct mDoDvdThd_mountXArchive_c * l_clothResCommand;
struct mDoDvdThd_mountXArchive_c * l_itemiconCommand;
struct mDoDvdThd_mountXArchive_c * l_actioniconCommand;
struct mDoDvdThd_mountXArchive_c * l_scopeResCommand;
struct mDoDvdThd_mountXArchive_c * l_camResCommand;
struct mDoDvdThd_mountXArchive_c * l_swimResCommand;
struct mDoDvdThd_mountXArchive_c * l_windResCommand;
struct mDoDvdThd_mountXArchive_c * l_nameResCommand;
struct mDoDvdThd_mountXArchive_c * l_tmsgCommand;
struct mDoDvdThd_mountXArchive_c * l_dmsgCommand;
struct mDoDvdThd_mountXArchive_c * l_errorResCommand;
struct mDoDvdThd_mountXArchive_c * l_msgDtCommand;
struct mDoDvdThd_mountXArchive_c * l_msgDtCommand2;
struct mDoDvdThd_mountXArchive_c * l_msgCommand;
struct mDoDvdThd_mountXArchive_c * l_menuCommand;
struct mDoDvdThd_mountXArchive_c * l_fontCommand;
struct mDoDvdThd_mountXArchive_c * l_rubyCommand;
struct mDoDvdThd_mountXArchive_c * l_particleCommand;
struct mDoDvdThd_mountXArchive_c * l_itemTableCommand;
struct mDoDvdThd_mountXArchive_c * l_ActorDataCommand;
struct mDoDvdThd_mountXArchive_c * l_FmapDataCommand;
struct mDoDvdThd_mountXArchive_c * l_lodCommand;

/* __stdcall checkProgSelect(dScnLogo_c *) */

void checkProgSelect(int param_1)

{
  int iVar1;
  
  iVar1 = os::OSGetResetCode();
  if (iVar1 == 0) {
    iVar1 = vi::VIGetDTVStatus();
    if (iVar1 != 0) {
      iVar1 = os::OSGetProgressiveMode();
      if ((iVar1 == 1) || ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton1 < '\0')) {
        *(undefined *)(param_1 + 0x1ea) = 1;
        *(undefined *)(param_1 + 0x1e9) = 0;
      }
    }
  }
  else {
    *(undefined *)(param_1 + 0x1ea) = 0;
  }
  return;
}


/* __stdcall nintendoInDraw(dScnLogo_c *) */

undefined4 nintendoInDraw(int param_1)

{
  int *piVar1;
  
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1cc));
  if (*(short *)(param_1 + 0x1ec) == 0) {
    if (*(char *)(param_1 + 0x1ea) == '\0') {
      *(undefined *)(param_1 + 0x1e8) = 1;
      *(undefined2 *)(param_1 + 0x1ec) = 0x1e;
      piVar1 = (int *)JFWDisplay::sManager->mpFader;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x10))(piVar1,0x1e);
      }
    }
    else {
      *(undefined *)(param_1 + 0x1e8) = 5;
      *(undefined2 *)(param_1 + 0x1ec) = 0x1e;
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall nintendoOutDraw(dScnLogo_c *) */

undefined4 nintendoOutDraw(int param_1)

{
  int *piVar1;
  
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1cc));
  if (*(char *)(param_1 + 0x1e9) == '\0') {
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      *(dDlst_base_c **)(param_1 + 0x1e0));
  }
  else {
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      *(dDlst_base_c **)(param_1 + 0x1e4));
  }
  if (*(short *)(param_1 + 0x1ec) == 0) {
    *(undefined *)(param_1 + 0x1e8) = 3;
    *(undefined2 *)(param_1 + 0x1ec) = 0x5a;
    piVar1 = (int *)JFWDisplay::sManager->mpFader;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xc))(piVar1,0x1e);
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall nintendoOut2Draw(dScnLogo_c *) */

undefined4 nintendoOut2Draw(int param_1)

{
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1cc));
  if (*(char *)(param_1 + 0x1e9) == '\0') {
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      *(dDlst_base_c **)(param_1 + 0x1e0));
  }
  else {
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      *(dDlst_base_c **)(param_1 + 0x1e4));
  }
  if (*(short *)(param_1 + 0x1ec) == 0) {
    *(undefined *)(param_1 + 0x1e8) = 9;
    *(undefined2 *)(param_1 + 0x1ec) = 300;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall progInDraw(dScnLogo_c *) */

undefined4 progInDraw(int param_1)

{
  undefined uVar1;
  
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1cc));
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1d4));
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1d8));
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1dc));
  uVar1 = (undefined)
          (int)(_4387 * (_4388 - (float)((double)CONCAT44(0x43300000,
                                                          (uint)*(ushort *)(param_1 + 0x1ec)) -
                                        _4391) / _4389));
  *(undefined *)(*(int *)(param_1 + 0x1d4) + 300) = uVar1;
  *(undefined *)(*(int *)(param_1 + 0x1d8) + 300) = uVar1;
  *(undefined *)(*(int *)(param_1 + 0x1dc) + 300) = uVar1;
  if (*(short *)(param_1 + 0x1ec) == 0) {
    *(undefined *)(param_1 + 0x1e8) = 6;
    *(undefined2 *)(param_1 + 0x1ec) = 600;
    *(undefined2 *)(param_1 + 0x1ee) = 0x1e;
    *(undefined2 *)(param_1 + 0x1f0) = *(undefined2 *)(param_1 + 0x1ee);
    *(undefined2 *)(param_1 + 0x1f2) = 0;
    *(undefined *)(param_1 + 0x1eb) = 0;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall progSelDraw(dScnLogo_c *) */

undefined4 progSelDraw(int param_1)

{
  float fVar1;
  undefined uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined uVar5;
  int iVar6;
  undefined uStack182;
  undefined uStack181;
  undefined uStack178;
  undefined uStack177;
  undefined uStack174;
  undefined uStack170;
  undefined uStack169;
  undefined uStack166;
  undefined uStack162;
  undefined uStack161;
  undefined uStack158;
  undefined uStack157;
  undefined uStack154;
  undefined uStack153;
  undefined local_90;
  undefined uStack143;
  undefined local_84;
  undefined uStack131;
  undefined local_6c;
  undefined uStack107;
  undefined local_60;
  undefined local_54;
  undefined uStack83;
  undefined local_48;
  undefined uStack71;
  undefined local_3c;
  undefined uStack59;
  
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1cc));
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1d4));
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1d8));
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1dc));
  if (*(char *)(param_1 + 0x1eb) != '\0') {
    if (*(short *)(param_1 + 500) == 0) {
      *(undefined *)(param_1 + 0x1e8) = 7;
      *(undefined2 *)(param_1 + 0x1ec) = 0x1e;
      *(undefined2 *)(param_1 + 0x1ee) = 0x1e;
      *(undefined2 *)(param_1 + 0x1f0) = *(undefined2 *)(param_1 + 0x1ee);
      *(undefined2 *)(param_1 + 0x1f2) = 0;
    }
    else {
      *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + -1;
    }
    goto LAB_8022c708;
  }
  if (*(char *)(param_1 + 0x1e9) == '\0') {
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton0 >> 6 & 1) == 0) {
      if (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosX <= _4636) goto LAB_8022c5f8;
    }
    JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,_4388,_4388,_4637,_4637,0);
    *(undefined *)(param_1 + 0x1e9) = 1;
    *(undefined2 *)(param_1 + 0x1ee) = 0x1e;
    *(undefined2 *)(param_1 + 0x1f0) = *(undefined2 *)(param_1 + 0x1ee);
    *(undefined2 *)(param_1 + 0x1f2) = 0;
  }
  else {
    if (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton0) {
      if (_4638 <= m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosX) goto LAB_8022c5f8;
    }
    JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,_4388,_4388,_4637,_4637,0);
    *(undefined *)(param_1 + 0x1e9) = 0;
    *(undefined2 *)(param_1 + 0x1ee) = 0x1e;
    *(undefined2 *)(param_1 + 0x1f0) = *(undefined2 *)(param_1 + 0x1ee);
    *(undefined2 *)(param_1 + 0x1f2) = 0;
  }
LAB_8022c5f8:
  if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) != 0) ||
     (*(short *)(param_1 + 0x1ec) == 0)) {
    if (*(char *)(param_1 + 0x1e9) == '\0') {
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x80d,(cXyz *)0x0,0,0,_4388,_4388,_4637,_4637,0);
    }
    else {
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x880,(cXyz *)0x0,0,0,_4388,_4388,_4637,_4637,0);
    }
    if (*(ushort *)(param_1 + 0x1ec) < 0x21d) {
      *(undefined *)(param_1 + 0x1e8) = 7;
      *(undefined2 *)(param_1 + 0x1ec) = 0x1e;
      *(undefined2 *)(param_1 + 0x1ee) = 0x1e;
      *(undefined2 *)(param_1 + 0x1f0) = *(undefined2 *)(param_1 + 0x1ee);
      *(undefined2 *)(param_1 + 0x1f2) = 0;
    }
    else {
      *(undefined *)(param_1 + 0x1eb) = 1;
      *(short *)(param_1 + 500) = *(short *)(param_1 + 0x1ec) + -0x21c;
    }
  }
LAB_8022c708:
  uVar4 = _4442;
  uVar3 = _4425;
  fVar1 = (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(param_1 + 0x1f0)) - _4391) /
          (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(param_1 + 0x1ee)) - _4391);
  if (*(short *)(param_1 + 0x1f2) != 0) {
    fVar1 = _4388 - fVar1;
  }
  uVar5 = (undefined)(int)(_4639 * fVar1);
  local_60 = (undefined)(int)(_4387 * fVar1);
  if (*(char *)(param_1 + 0x1e9) == '\0') {
    uStack170 = (undefined)((uint)_4442 >> 8);
    uStack169 = (undefined)_4442;
    iVar6 = *(int *)(param_1 + 0x1d8);
    local_6c = (undefined)((uint)_4442 >> 0x18);
    *(undefined *)(iVar6 + 0x108) = local_6c;
    uStack107 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0x109) = uStack107;
    *(undefined *)(iVar6 + 0x10a) = uStack170;
    *(undefined *)(iVar6 + 0x10b) = uStack169;
    uVar2 = (undefined)_4446;
    uStack174 = (undefined)((uint)_4446 >> 8);
    iVar6 = *(int *)(param_1 + 0x1d8);
    *(undefined *)(iVar6 + 0x10c) = local_60;
    *(undefined *)(iVar6 + 0x10d) = uVar5;
    *(undefined *)(iVar6 + 0x10e) = uStack174;
    *(undefined *)(iVar6 + 0x10f) = uVar2;
    uVar3 = _4450;
    uStack178 = (undefined)((uint)_4450 >> 8);
    uStack177 = (undefined)_4450;
    iVar6 = *(int *)(param_1 + 0x1dc);
    local_84 = (undefined)((uint)_4450 >> 0x18);
    *(undefined *)(iVar6 + 0x108) = local_84;
    uStack131 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar6 + 0x109) = uStack131;
    *(undefined *)(iVar6 + 0x10a) = uStack178;
    *(undefined *)(iVar6 + 0x10b) = uStack177;
    uVar3 = _4454;
    uStack182 = (undefined)((uint)_4454 >> 8);
    uStack181 = (undefined)_4454;
    iVar6 = *(int *)(param_1 + 0x1dc);
    local_90 = (undefined)((uint)_4454 >> 0x18);
    *(undefined *)(iVar6 + 0x10c) = local_90;
    uStack143 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar6 + 0x10d) = uStack143;
    *(undefined *)(iVar6 + 0x10e) = uStack182;
    *(undefined *)(iVar6 + 0x10f) = uStack181;
  }
  else {
    uStack154 = (undefined)((uint)_4425 >> 8);
    uStack153 = (undefined)_4425;
    iVar6 = *(int *)(param_1 + 0x1d8);
    local_3c = (undefined)((uint)_4425 >> 0x18);
    *(undefined *)(iVar6 + 0x108) = local_3c;
    uStack59 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar6 + 0x109) = uStack59;
    *(undefined *)(iVar6 + 0x10a) = uStack154;
    *(undefined *)(iVar6 + 0x10b) = uStack153;
    uVar3 = _4429;
    uStack158 = (undefined)((uint)_4429 >> 8);
    uStack157 = (undefined)_4429;
    iVar6 = *(int *)(param_1 + 0x1d8);
    local_48 = (undefined)((uint)_4429 >> 0x18);
    *(undefined *)(iVar6 + 0x10c) = local_48;
    uStack71 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar6 + 0x10d) = uStack71;
    *(undefined *)(iVar6 + 0x10e) = uStack158;
    *(undefined *)(iVar6 + 0x10f) = uStack157;
    uVar3 = _4433;
    uStack162 = (undefined)((uint)_4433 >> 8);
    uStack161 = (undefined)_4433;
    iVar6 = *(int *)(param_1 + 0x1dc);
    local_54 = (undefined)((uint)_4433 >> 0x18);
    *(undefined *)(iVar6 + 0x108) = local_54;
    uStack83 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar6 + 0x109) = uStack83;
    *(undefined *)(iVar6 + 0x10a) = uStack162;
    *(undefined *)(iVar6 + 0x10b) = uStack161;
    uVar2 = (undefined)_4437;
    uStack166 = (undefined)((uint)_4437 >> 8);
    iVar6 = *(int *)(param_1 + 0x1dc);
    *(undefined *)(iVar6 + 0x10c) = local_60;
    *(undefined *)(iVar6 + 0x10d) = uVar5;
    *(undefined *)(iVar6 + 0x10e) = uStack166;
    *(undefined *)(iVar6 + 0x10f) = uVar2;
  }
  if (*(short *)(param_1 + 0x1f0) == 0) {
    *(undefined2 *)(param_1 + 0x1f0) = *(undefined2 *)(param_1 + 0x1ee);
    *(ushort *)(param_1 + 0x1f2) = *(ushort *)(param_1 + 0x1f2) ^ 1;
  }
  else {
    *(short *)(param_1 + 0x1f0) = *(short *)(param_1 + 0x1f0) + -1;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall progOutDraw(dScnLogo_c *) */

undefined4 progOutDraw(int param_1)

{
  undefined uVar1;
  int iVar2;
  int *piVar3;
  
  uVar1 = (undefined)
          (int)(_4387 * ((float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(param_1 + 0x1ec)) -
                                _4391) / _4389));
  *(undefined *)(*(int *)(param_1 + 0x1d4) + 300) = uVar1;
  *(undefined *)(*(int *)(param_1 + 0x1d8) + 300) = uVar1;
  *(undefined *)(*(int *)(param_1 + 0x1dc) + 300) = uVar1;
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1cc));
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1d4));
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1d8));
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1dc));
  if (*(short *)(param_1 + 0x1ec) == 0) {
    iVar2 = os::OSGetProgressiveMode();
    if ((iVar2 == 0) || (*(char *)(param_1 + 0x1e9) != '\0')) {
      iVar2 = os::OSGetProgressiveMode();
      if ((iVar2 == 0) && (*(char *)(param_1 + 0x1e9) != '\0')) {
        *(undefined *)(param_1 + 0x1e8) = 1;
        *(undefined2 *)(param_1 + 0x1ec) = 0x1e;
        piVar3 = (int *)JFWDisplay::sManager->mpFader;
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0x10))(piVar3,0x1e);
        }
      }
      else {
        *(undefined *)(param_1 + 0x1e8) = 8;
        *(undefined2 *)(param_1 + 0x1ec) = 600;
        *(undefined2 *)(param_1 + 0x1f0) = 0x1e;
      }
    }
    else {
      *(undefined *)(param_1 + 0x1e8) = 2;
      *(undefined2 *)(param_1 + 0x1ec) = 0x1e;
      piVar3 = (int *)JFWDisplay::sManager->mpFader;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x10))(piVar3,0x1e);
      }
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall progSetDraw(dScnLogo_c *) */

undefined4 progSetDraw(int param_1)

{
  ushort uVar1;
  int *piVar2;
  undefined uVar3;
  
  uVar1 = *(ushort *)(param_1 + 0x1f0);
  if (uVar1 == 0) {
    uVar3 = 0xff;
  }
  else {
    uVar3 = (undefined)
            (int)(_4387 * (_4388 - (float)((double)CONCAT44(0x43300000,(uint)uVar1) - _4391) / _4389
                          ));
    *(ushort *)(param_1 + 0x1f0) = uVar1 - 1;
  }
  *(undefined *)(*(int *)(param_1 + 0x1d4) + 300) = uVar3;
  *(undefined *)(*(int *)(param_1 + 0x1d8) + 300) = uVar3;
  *(undefined *)(*(int *)(param_1 + 0x1dc) + 300) = uVar3;
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1cc));
  if (*(char *)(param_1 + 0x1e9) == '\0') {
    *(undefined *)(*(int *)(param_1 + 0x1e0) + 300) = uVar3;
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      *(dDlst_base_c **)(param_1 + 0x1e0));
  }
  else {
    *(undefined *)(*(int *)(param_1 + 0x1e4) + 300) = uVar3;
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      *(dDlst_base_c **)(param_1 + 0x1e4));
  }
  if (*(short *)(param_1 + 0x1ec) == 0) {
    if (*(char *)(param_1 + 0x1e9) == '\0') {
      *(undefined *)(param_1 + 0x1e8) = 2;
    }
    else {
      os::OSSetProgressiveMode(0);
      *(undefined *)(param_1 + 0x1e8) = 1;
    }
    *(undefined2 *)(param_1 + 0x1ec) = 0x1e;
    piVar2 = (int *)JFWDisplay::sManager->mpFader;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x10))(piVar2,0x1e);
    }
  }
  return 1;
}


/* __stdcall progChangeDraw(dScnLogo_c *) */

undefined4 progChangeDraw(int param_1)

{
  int *piVar1;
  
  if ((*(short *)(param_1 + 0x1ec) == 299) && (*(char *)(param_1 + 0x1e9) == '\0')) {
    mDoMch_render_c::mRenderModeObj = &m_Do_machine::g_ntscZeldaProg;
    os::OSSetProgressiveMode(1);
  }
  if (*(short *)(param_1 + 0x1ec) == 0) {
    *(undefined *)(param_1 + 0x1e8) = 3;
    *(undefined2 *)(param_1 + 0x1ec) = 0x5a;
    piVar1 = (int *)JFWDisplay::sManager->mpFader;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xc))(piVar1,0x1e);
    }
  }
  return 1;
}


/* __stdcall dolbyInDraw(dScnLogo_c *) */

undefined4 dolbyInDraw(int param_1)

{
  int *piVar1;
  
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1d0));
  if (*(short *)(param_1 + 0x1ec) == 0) {
    *(undefined *)(param_1 + 0x1e8) = 4;
    *(undefined2 *)(param_1 + 0x1ec) = 0x1e;
    piVar1 = (int *)JFWDisplay::sManager->mpFader;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(piVar1,0x1e);
    }
  }
  return 1;
}


/* __stdcall dolbyOutDraw(dScnLogo_c *) */

undefined4 dolbyOutDraw(int param_1)

{
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x1d0));
  if (*(short *)(param_1 + 0x1ec) == 0) {
    *(undefined *)(param_1 + 0x1e8) = 10;
  }
  return 1;
}


/* __stdcall dvdWaitDraw(dScnLogo_c *) */

undefined4 dvdWaitDraw(scene_class *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = dRes_control_c::syncAllRes
                    (&d_com_inf_game::g_dComIfG_gameInfo.mResCtrl,(dRes_info_c *)&DAT_00000040,
                     param_3);
  if ((((((((iVar1 == 0) && ((l_anmCommand->parent).mStatus != 0)) &&
          ((l_fmapCommand->parent).mStatus != 0)) &&
         ((((l_itemResCommand->parent).mStatus != 0 && ((l_fmapResCommand->parent).mStatus != 0)) &&
          (((l_dmapResCommand->parent).mStatus != 0 &&
           (((l_clctResCommand->parent).mStatus != 0 && ((l_optResCommand->parent).mStatus != 0)))))
          ))) && ((l_saveResCommand->parent).mStatus != 0)) &&
       (((((((l_clothResCommand->parent).mStatus != 0 && ((l_itemiconCommand->parent).mStatus != 0))
           && ((l_actioniconCommand->parent).mStatus != 0)) &&
          (((l_scopeResCommand->parent).mStatus != 0 && ((l_camResCommand->parent).mStatus != 0))))
         && ((l_swimResCommand->parent).mStatus != 0)) &&
        ((((l_windResCommand->parent).mStatus != 0 && ((l_nameResCommand->parent).mStatus != 0)) &&
         ((((l_tmsgCommand->parent).mStatus != 0 &&
           ((((l_dmsgCommand->parent).mStatus != 0 && ((l_errorResCommand->parent).mStatus != 0)) &&
            ((l_msgDtCommand->parent).mStatus != 0)))) &&
          ((((l_msgDtCommand2->parent).mStatus != 0 && ((l_msgCommand->parent).mStatus != 0)) &&
           ((l_menuCommand->parent).mStatus != 0)))))))))) &&
      ((((l_fontCommand->parent).mStatus != 0 && ((l_rubyCommand->parent).mStatus != 0)) &&
       (((l_particleCommand->parent).mStatus != 0 &&
        ((((l_itemTableCommand->parent).mStatus != 0 && ((l_ActorDataCommand->parent).mStatus != 0))
         && ((l_FmapDataCommand->parent).mStatus != 0)))))))) &&
     (((l_lodCommand->parent).mStatus != 0 && (*mDoRst::mResetData == 0)))) {
    d_com_inf_game::dComIfG_changeOpeningScene(param_1,8);
  }
  return 1;
}


/* __stdcall dScnLogo_Draw(dScnLogo_c *) */

void dScnLogo_Draw(int param_1)

{
  d_a_npc_fa1::cLib_calcTimer(param_1 + 0x1ec);
  (*(code *)(&l_execFunc_4864)[*(byte *)(param_1 + 0x1e8)])(param_1);
  return;
}


/* __stdcall dScnLogo_Execute(dScnLogo_c *) */

undefined4 dScnLogo_Execute(undefined4 param_1)

{
  if (*mDoRst::mResetData != 0) {
    f_op_scene_mng::fopScnM_ChangeReq(param_1,5,0,5);
  }
  return 1;
}


/* __stdcall dScnLogo_IsDelete(dScnLogo_c *) */

undefined4 dScnLogo_IsDelete(void)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dScnLogo_Delete(dScnLogo_c *) */

undefined4 dScnLogo_Delete(int param_1)

{
  int *piVar1;
  void *ball128b;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (*mDoRst::mResetData != 0) {
    m_Do_Reset::mDoRst_reset(0,0x80000000,0);
  }
  piVar1 = *(int **)(param_1 + 0x1cc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  piVar1 = *(int **)(param_1 + 0x1d0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  piVar1 = *(int **)(param_1 + 0x1d4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  piVar1 = *(int **)(param_1 + 0x1d8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  piVar1 = *(int **)(param_1 + 0x1dc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  piVar1 = *(int **)(param_1 + 0x1e0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  piVar1 = *(int **)(param_1 + 0x1e4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  dPa_control_c::createCommon
            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,l_particleCommand->mpArchive);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpAnmArchive = l_anmCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFMapArchive = l_fmapCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemResArchive = l_itemResCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFMapResArchive = l_fmapResCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDMapResArchive = l_dmapResCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpClctResArchive = l_clctResCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpOptResArchive = l_optResCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpSaveResArchive = l_saveResCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpClothResArchive = l_clothResCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive = l_itemiconCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpActionIconArchive = l_actioniconCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpScopeResArchive = l_scopeResCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCamResArchive = l_camResCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpSwimResArchive = l_swimResCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpWindResArchive = l_windResCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpNameResArchive = l_nameResCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTmsgArchive = l_tmsgCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDmsgArchive = l_dmsgCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpErrorResArchive = l_errorResCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpEnglishTextArchive = l_msgDtCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpHyruleTextArchive = l_msgDtCommand2->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive = l_msgCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMenuArchive = l_menuCommand->mpArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFontArchive = l_fontCommand->mpArchive;
  if (l_anmCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_anmCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_anmCommand,1);
  }
  if (l_fmapCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_fmapCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_fmapCommand,1);
  }
  if (l_itemResCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_itemResCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_itemResCommand,1);
  }
  if (l_fmapResCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_fmapResCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_fmapResCommand,1);
  }
  if (l_dmapResCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_dmapResCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_dmapResCommand,1);
  }
  if (l_clctResCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_clctResCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_clctResCommand,1);
  }
  if (l_optResCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_optResCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_optResCommand,1);
  }
  if (l_saveResCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_saveResCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_saveResCommand,1);
  }
  if (l_clothResCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_clothResCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_clothResCommand,1);
  }
  if (l_itemiconCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_itemiconCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_itemiconCommand,1);
  }
  if (l_actioniconCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_actioniconCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_actioniconCommand,1);
  }
  if (l_scopeResCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_scopeResCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_scopeResCommand,1);
  }
  if (l_camResCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_camResCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_camResCommand,1);
  }
  if (l_swimResCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_swimResCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_swimResCommand,1);
  }
  if (l_windResCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_windResCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_windResCommand,1);
  }
  if (l_nameResCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_nameResCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_nameResCommand,1);
  }
  if (l_tmsgCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_tmsgCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_tmsgCommand,1);
  }
  if (l_dmsgCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_dmsgCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_dmsgCommand,1);
  }
  if (l_errorResCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_errorResCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_errorResCommand,1);
  }
  if (l_msgDtCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_msgDtCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_msgDtCommand,1);
  }
  if (l_msgDtCommand2 != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_msgDtCommand2->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_msgDtCommand2,1);
  }
  if (l_msgCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_msgCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_msgCommand,1);
  }
  if (l_menuCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_menuCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_menuCommand,1);
  }
  if (l_fontCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_fontCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_fontCommand,1);
  }
  if (l_rubyCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_rubyCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_rubyCommand,1);
  }
  if (l_particleCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_particleCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_particleCommand,1);
  }
  m_Do_ext::mDoExt_getMesgFont();
  m_Do_ext::mDoExt_getRubyFont();
  d_com_inf_game::g_dComIfG_gameInfo.mpItemTableArchive = l_itemTableCommand->mpArchive;
  if (l_itemTableCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_itemTableCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_itemTableCommand,1);
  }
  dADM::SetData(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM,l_ActorDataCommand->mpArchive);
  d_com_inf_game::g_dComIfG_gameInfo.mpFmapDataArchive = (FmapData *)l_FmapDataCommand->mpArchive;
  if (l_ActorDataCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_ActorDataCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_ActorDataCommand,1);
  }
  if (l_FmapDataCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_FmapDataCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_FmapDataCommand,1);
  }
  if (l_lodCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    (*(code *)((l_lodCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_lodCommand,1);
  }
  ball128b = dRes_control_c::getRes
                       ("Always",0x71,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  dDlst_shadowControl_c::setSimpleTex(ball128b);
  dRes_control_c::deleteRes("Logo",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  iVar4 = 0;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 0;
  uVar3 = 0;
  do {
    uVar2 = JKRAramHeap::alloc(JKRAram::sAramObject->mpHeap,0x2000,0);
    *(undefined4 *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow + iVar4 + -0x44) =
         uVar2;
    d_com_inf_game::g_dComIfG_gameInfo._23547_1_ =
         d_com_inf_game::g_dComIfG_gameInfo._23547_1_ & ~(byte)(1 << (uVar3 & 0xff));
    uVar3 = uVar3 + 1;
    iVar4 = iVar4 + 4;
  } while ((int)uVar3 < 3);
  iVar4 = 0;
  iVar5 = 0;
  do {
    uVar2 = JKRAramHeap::alloc(JKRAram::sAramObject->mpHeap,0x70,0);
    *(undefined4 *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow + iVar5 + -0x38) =
         uVar2;
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 4);
  m_Do_ext::mDoExt_setSafeGameHeapSize();
  m_Do_ext::mDoExt_setSafeZeldaHeapSize();
  m_Do_ext::mDoExt_setSafeCommandHeapSize();
  m_Do_ext::mDoExt_setSafeArchiveHeapSize();
  return 1;
}


/* __stdcall phase_0(dScnLogo_c *) */

undefined4 phase_0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  ulong uVar4;
  
  iVar1 = os::OSGetResetCode();
  if (iVar1 == 0) {
    iVar1 = vi::VIGetDTVStatus();
    if (iVar1 == 0) {
      os::OSSetProgressiveMode(0);
    }
  }
  else {
    iVar1 = os::OSGetProgressiveMode();
    if (iVar1 == 1) {
      mDoMch_render_c::mRenderModeObj = &m_Do_machine::g_ntscZeldaProg;
    }
  }
  iVar1 = c_dylink::cDyl_InitAsyncIsDone();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    if ((mDoAud_zelAudio_c::mInitFlag == '\0') ||
       (iVar1 = JAIZelBasic::checkFirstWaves(JAIZelBasic::zel_basic), iVar1 == 0)) {
      pcVar3 = "System";
      dRes_control_c::setRes
                ("System",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40,
                 "/res/Object/",0,(JKRHeap *)0x0);
      if (pcVar3 != (char *)0x1) {
        uVar4 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar4,"d_s_logo.cpp",0x546,"rt == 1");
        m_Do_printf::OSPanic("d_s_logo.cpp",0x546,"Halt");
      }
      pcVar3 = "Logo";
      dRes_control_c::setRes
                ("Logo",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40,"/res/Object/",
                 2,(JKRHeap *)0x0);
      if (pcVar3 != (char *)0x1) {
        uVar4 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar4,"d_s_logo.cpp",0x54a,"rt == 1");
        m_Do_printf::OSPanic("d_s_logo.cpp",0x54a,"Halt");
      }
      *(undefined *)(param_1 + 0x1ea) = 0;
      (*(code *)m_Do_ext::archiveHeap->vtbl->dump_sort)();
      uVar2 = 2;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall phase_1(dScnLogo_c *) */

undefined4 phase_1(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  ResTIMG *pRVar3;
  ulong uVar4;
  JKRExpHeap *this;
  void *pvVar5;
  
  iVar1 = dRes_control_c::syncAllRes
                    (&d_com_inf_game::g_dComIfG_gameInfo.mResCtrl,(dRes_info_c *)&DAT_00000040,
                     param_3);
  if (iVar1 == 0) {
    pRVar3 = (ResTIMG *)
             dRes_control_c::getRes
                       ("System",3,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pRVar3 == (ResTIMG *)0x0) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_s_logo.cpp",0x592,"toonImage != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x592,"Halt");
    }
    dDlst_list_c::mToonImage = pRVar3;
    pRVar3 = (ResTIMG *)
             dRes_control_c::getRes
                       ("System",4,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pRVar3 == (ResTIMG *)0x0) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_s_logo.cpp",0x597,"toonImage != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x597,"Halt");
    }
    dDlst_list_c::mToonExImage = pRVar3;
    this = m_Do_ext::mDoExt_getGameHeap();
    pvVar5 = JKRHeap::alloc(&this->parent,0x3c8a0,4);
    *(void **)(param_1 + 0x1f8) = pvVar5;
    uVar2 = 2;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __stdcall aramMount(char const *) */

mDoDvdThd_mountXArchive_c * aramMount(char *param_1)

{
  mDoDvdThd_mountXArchive_c *pmVar1;
  
  pmVar1 = mDoDvdThd_mountXArchive_c::create(param_1,0,ARAM);
  return pmVar1;
}


/* __stdcall onMemMount(char const *) */

mDoDvdThd_mountXArchive_c * onMemMount(char *param_1)

{
  mDoDvdThd_mountXArchive_c *pmVar1;
  
  pmVar1 = mDoDvdThd_mountXArchive_c::create(param_1,0,Mem);
  return pmVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall phase_2(dScnLogo_c *) */

undefined4 phase_2(int param_1)

{
  JFWDisplay *pJVar1;
  int iVar2;
  ulong uVar3;
  undefined4 uVar4;
  ResTIMG *pRVar5;
  dDlst_2D_c *pdVar6;
  char *pcVar7;
  undefined *puVar8;
  int *piVar9;
  undefined uStack70;
  undefined uStack69;
  undefined uStack66;
  undefined uStack65;
  undefined uStack62;
  undefined uStack61;
  undefined local_34;
  undefined uStack51;
  undefined local_28;
  undefined uStack39;
  undefined local_1c;
  undefined uStack27;
  
  iVar2 = dRes_control_c::syncRes
                    ("Logo",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (iVar2 < 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x5bd,"rt >= 0");
    m_Do_printf::OSPanic("d_s_logo.cpp",0x5bd,"Halt");
  }
  if (iVar2 == 0) {
    dComIfG_play_c::createParticle(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
    pRVar5 = (ResTIMG *)
             dRes_control_c::getRes
                       ("Logo",3,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pRVar5 == (ResTIMG *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x5ca,"timg != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x5ca,"Halt");
    }
    pdVar6 = (dDlst_2D_c *)JKernel::operator_new(0x130);
    if (pdVar6 != (dDlst_2D_c *)0x0) {
      dDlst_2D_c::dDlst_2D_c(pdVar6,pRVar5,0x85,0xaa,'\0');
    }
    *(dDlst_2D_c **)(param_1 + 0x1cc) = pdVar6;
    if (*(int *)(param_1 + 0x1cc) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x5cd,"i_this->nintendoImg != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x5cd,"Halt");
    }
    *(undefined *)(*(int *)(param_1 + 0x1cc) + 300) = 0xff;
    uVar4 = _5373;
    uStack62 = (undefined)((uint)_5373 >> 8);
    uStack61 = (undefined)_5373;
    iVar2 = *(int *)(param_1 + 0x1cc);
    local_1c = (undefined)((uint)_5373 >> 0x18);
    *(undefined *)(iVar2 + 0x108) = local_1c;
    uStack27 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar2 + 0x109) = uStack27;
    *(undefined *)(iVar2 + 0x10a) = uStack62;
    *(undefined *)(iVar2 + 0x10b) = uStack61;
    pRVar5 = (ResTIMG *)
             dRes_control_c::getRes
                       ("Logo",9,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pRVar5 == (ResTIMG *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x5da,"timg != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x5da,"Halt");
    }
    pdVar6 = (dDlst_2D_c *)JKernel::operator_new(0x130);
    if (pdVar6 != (dDlst_2D_c *)0x0) {
      dDlst_2D_c::dDlst_2D_c(pdVar6,pRVar5,0xda,0xa6,'\0');
    }
    *(dDlst_2D_c **)(param_1 + 0x1d0) = pdVar6;
    if (*(int *)(param_1 + 0x1d0) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x5de,"i_this->dolbyImg != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x5de,"Halt");
    }
    *(undefined *)(*(int *)(param_1 + 0x1d0) + 300) = 0xff;
    pRVar5 = (ResTIMG *)
             dRes_control_c::getRes
                       ("Logo",4,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pRVar5 == (ResTIMG *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x61d,"timg != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x61d,"Halt");
    }
    pdVar6 = (dDlst_2D_c *)JKernel::operator_new(0x130);
    if (pdVar6 != (dDlst_2D_c *)0x0) {
      dDlst_2D_c::dDlst_2D_c(pdVar6,pRVar5,0x71,0x119,'\0');
    }
    *(dDlst_2D_c **)(param_1 + 0x1d4) = pdVar6;
    if (*(int *)(param_1 + 0x1d4) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x61f,"i_this->progchoiceImg != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x61f,"Halt");
    }
    *(undefined *)(*(int *)(param_1 + 0x1d4) + 300) = 0;
    pRVar5 = (ResTIMG *)
             dRes_control_c::getRes
                       ("Logo",8,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pRVar5 == (ResTIMG *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x62b,"timg != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x62b,"Halt");
    }
    pdVar6 = (dDlst_2D_c *)JKernel::operator_new(0x130);
    if (pdVar6 != (dDlst_2D_c *)0x0) {
      dDlst_2D_c::dDlst_2D_c(pdVar6,pRVar5,0xd3,0x174,'\0');
    }
    *(dDlst_2D_c **)(param_1 + 0x1d8) = pdVar6;
    if (*(int *)(param_1 + 0x1d8) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x62d,"i_this->progyesImg != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x62d,"Halt");
    }
    uVar4 = _5380;
    uStack66 = (undefined)((uint)_5380 >> 8);
    uStack65 = (undefined)_5380;
    iVar2 = *(int *)(param_1 + 0x1d8);
    local_28 = (undefined)((uint)_5380 >> 0x18);
    *(undefined *)(iVar2 + 0x108) = local_28;
    uStack39 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar2 + 0x109) = uStack39;
    *(undefined *)(iVar2 + 0x10a) = uStack66;
    *(undefined *)(iVar2 + 0x10b) = uStack65;
    *(undefined *)(*(int *)(param_1 + 0x1d8) + 300) = 0;
    pRVar5 = (ResTIMG *)
             dRes_control_c::getRes
                       ("Logo",6,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pRVar5 == (ResTIMG *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x63a,"timg != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x63a,"Halt");
    }
    pdVar6 = (dDlst_2D_c *)JKernel::operator_new(0x130);
    if (pdVar6 != (dDlst_2D_c *)0x0) {
      dDlst_2D_c::dDlst_2D_c(pdVar6,pRVar5,0x15e,0x174,'\0');
    }
    *(dDlst_2D_c **)(param_1 + 0x1dc) = pdVar6;
    if (*(int *)(param_1 + 0x1dc) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x63c,"i_this->prognoImg != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x63c,"Halt");
    }
    uVar4 = _5385;
    uStack70 = (undefined)((uint)_5385 >> 8);
    uStack69 = (undefined)_5385;
    iVar2 = *(int *)(param_1 + 0x1dc);
    local_34 = (undefined)((uint)_5385 >> 0x18);
    *(undefined *)(iVar2 + 0x108) = local_34;
    uStack51 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar2 + 0x109) = uStack51;
    *(undefined *)(iVar2 + 0x10a) = uStack70;
    *(undefined *)(iVar2 + 0x10b) = uStack69;
    *(undefined *)(*(int *)(param_1 + 0x1dc) + 300) = 0;
    pRVar5 = (ResTIMG *)
             dRes_control_c::getRes
                       ("Logo",7,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pRVar5 == (ResTIMG *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x649,"timg != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x649,"Halt");
    }
    pdVar6 = (dDlst_2D_c *)JKernel::operator_new(0x130);
    if (pdVar6 != (dDlst_2D_c *)0x0) {
      dDlst_2D_c::dDlst_2D_c(pdVar6,pRVar5,0x99,0x135,'\0');
    }
    *(dDlst_2D_c **)(param_1 + 0x1e0) = pdVar6;
    if (*(int *)(param_1 + 0x1e0) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x64b,"i_this->progImg != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x64b,"Halt");
    }
    *(undefined *)(*(int *)(param_1 + 0x1e0) + 300) = 0;
    pRVar5 = (ResTIMG *)
             dRes_control_c::getRes
                       ("Logo",5,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pRVar5 == (ResTIMG *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x657,"timg != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x657,"Halt");
    }
    pdVar6 = (dDlst_2D_c *)JKernel::operator_new(0x130);
    if (pdVar6 != (dDlst_2D_c *)0x0) {
      dDlst_2D_c::dDlst_2D_c(pdVar6,pRVar5,0x99,0x135,'\0');
    }
    *(dDlst_2D_c **)(param_1 + 0x1e4) = pdVar6;
    if (*(int *)(param_1 + 0x1e4) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x659,"i_this->interImg != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x659,"Halt");
    }
    *(undefined *)(*(int *)(param_1 + 0x1e4) + 300) = 0;
    JKRHeap::free(*(void **)(param_1 + 0x1f8),(JKRHeap *)0x0);
    l_lodCommand = aramMount("/res/Stage/sea/LODALL.arc");
    if (l_lodCommand == (mDoDvdThd_mountXArchive_c *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x66d,"l_lodCommand != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x66d,"Halt");
    }
    pcVar7 = "Always";
    dRes_control_c::setRes
              ("Always",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40,"/res/Object/",
               0,(JKRHeap *)0x0);
    if (pcVar7 != (char *)0x1) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x672,"rt == 1");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x672,"Halt");
    }
    (*(code *)m_Do_ext::archiveHeap->vtbl->dump_sort)();
    puVar8 = &DAT_8036292b;
    dRes_control_c::setRes
              ("Link",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40,"/res/Object/",0,
               (JKRHeap *)0x0);
    if (puVar8 != (undefined *)0x1) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x677,"rt == 1");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x677,"Halt");
    }
    puVar8 = &DAT_80362930;
    dRes_control_c::setRes
              ("Agb",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40,"/res/Object/",0,
               (JKRHeap *)0x0);
    if (puVar8 != (undefined *)0x1) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x67b,"rt == 1");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x67b,"Halt");
    }
    l_anmCommand = aramMount("/res/Object/LkAnm.arc");
    l_fmapCommand = aramMount("/res/Fmap/Fmap.arc");
    l_itemResCommand = aramMount("/res/Msg/itemres.arc");
    l_fmapResCommand = aramMount("/res/Msg/fmapres.arc");
    l_dmapResCommand = aramMount("/res/Msg/dmapres.arc");
    l_clctResCommand = aramMount("/res/Msg/clctres.arc");
    l_optResCommand = aramMount("/res/Msg/optres.arc");
    l_clothResCommand = aramMount("/res/Msg/clothres.arc");
    l_itemiconCommand = aramMount("/res/Msg/itemicon.arc");
    l_actioniconCommand = aramMount("/res/Msg/acticon.arc");
    l_scopeResCommand = aramMount("/res/Msg/scoperes.arc");
    l_camResCommand = aramMount("/res/Msg/camres.arc");
    l_swimResCommand = onMemMount("/res/Msg/swimres.arc");
    l_windResCommand = aramMount("/res/Msg/windres.arc");
    l_nameResCommand = aramMount("/res/Msg/nameres.arc");
    l_tmsgCommand = aramMount("/res/Msg/tmsgres.arc");
    l_dmsgCommand = aramMount("/res/Msg/dmsgres.arc");
    l_errorResCommand = aramMount("/res/Msg/errorres.arc");
    l_saveResCommand = aramMount("/res/Msg/saveres.arc");
    l_msgDtCommand = onMemMount("/res/Msg/bmgres.arc");
    l_msgDtCommand2 = onMemMount("/res/Msg/bmgresh.arc");
    l_msgCommand = aramMount("/res/Msg/msgres.arc");
    l_menuCommand = onMemMount("/res/Msg/menures.arc");
    l_fontCommand = onMemMount("/res/Msg/fontres.arc");
    l_rubyCommand = onMemMount("/res/Msg/rubyres.arc");
    l_particleCommand =
         (mDoDvdThd_mountXArchive_c *)
         mDoDvdThd_toMainRam_c::create
                   ("/res/Particle/common.jpc",0,
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl)->mpHeap);
    l_itemTableCommand =
         (mDoDvdThd_mountXArchive_c *)
         mDoDvdThd_toMainRam_c::create("/res/ItemTable/item_table.bin",0,(JKRHeap *)0x0);
    if (l_itemTableCommand == (mDoDvdThd_mountXArchive_c *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x6cf,"l_itemTableCommand != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x6cf,"Halt");
    }
    l_ActorDataCommand =
         (mDoDvdThd_mountXArchive_c *)
         mDoDvdThd_toMainRam_c::create("/res/ActorDat/ActorDat.bin",0,(JKRHeap *)0x0);
    if (l_ActorDataCommand == (mDoDvdThd_mountXArchive_c *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x6d3,"l_ActorDataCommand != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x6d3,"Halt");
    }
    l_FmapDataCommand =
         (mDoDvdThd_mountXArchive_c *)
         mDoDvdThd_toMainRam_c::create("/res/FmapDat/FmapDat.bin",0,(JKRHeap *)0x0);
    if (l_FmapDataCommand == (mDoDvdThd_mountXArchive_c *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_logo.cpp",0x6d7,"l_FmapDataCommand != 0");
      m_Do_printf::OSPanic("d_s_logo.cpp",0x6d7,"Halt");
    }
    JAIZelBasic::loadStaticWaves(JAIZelBasic::zel_basic);
    pJVar1 = JFWDisplay::sManager;
    *(uint *)&JFWDisplay::sManager->field_0x24 = (DAT_800000f8 >> 2) / 0x3c;
    *(undefined2 *)&pJVar1->field_0x20 = 0;
    JFWDisplay::waitBlanking(JFWDisplay::sManager,0);
    piVar9 = (int *)JFWDisplay::sManager->mpFader;
    if (piVar9 != (int *)0x0) {
      (**(code **)(*piVar9 + 0xc))(piVar9,0x1e);
    }
    *(undefined2 *)(param_1 + 0x1ec) = 0x5a;
    *mDoRst::mResetData = 0;
    mDoRst::mResetData[1] = 0;
    mDoRst::mResetData[1] = 0;
    JUTGamePad::C3ButtonReset::sResetOccurred = 0;
    _sCallback = m_Do_Reset::mDoRst_resetCallBack;
    _sCallbackArg = 0;
    uVar4 = 4;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


/* __stdcall dScnLogo_Create(scene_class *) */

void dScnLogo_Create(void *param_1)

{
  checkProgSelect();
  d_com_lib_game::dComLbG_PhaseHandler
            ((request_of_phase_process_class *)((int)param_1 + 0x1c4),
             (cPhs__Handler *)&l_method_5571,param_1);
  return;
}

