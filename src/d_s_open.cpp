#include <d_s_open.h>
#include <d_com_inf_game.h>
#include <m_Do_ext.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKernel/JKRHeap.h>
#include <d_s_open_sub.h>
#include <f_op_overlap_mng.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <m_Do_audio.h>
#include <d_s_open.h>
#include <f_op_draw_iter.h>
#include <f_pc_manager.h>
#include <d_drawlist.h>
#include <f_op_scene_mng.h>
#include <dScnOpen_c.h>


namespace d_s_open {
}

/* __thiscall dScnOpen_c::create(void) */

PhaseState __thiscall dScnOpen_c::create(dScnOpen_c *this)

{
  JFWDisplay *pJVar1;
  PhaseState PVar2;
  JKRSolidHeap *pJVar3;
  ulong uVar4;
  dScnOpen_proc_c *this_00;
  
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext = 0;
  *(undefined4 *)(this + 0x1d0) = 0;
  PVar2 = d_com_inf_game::dComIfG_resLoad
                    ((request_of_phase_process_class *)(this + 0x1c4),"Opening");
  if (PVar2 == cPhs_COMPLEATE_e) {
    pJVar3 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(0x20000,0);
    *(JKRSolidHeap **)(this + 0x1cc) = pJVar3;
    if (*(int *)(this + 0x1cc) == 0) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_s_open.cpp",0x3b,"solid_heap != 0");
      m_Do_printf::OSPanic("d_s_open.cpp",0x3b,&DAT_80362f75);
    }
    this_00 = (dScnOpen_proc_c *)JKernel::operator_new(0x2c8);
    if (this_00 != (dScnOpen_proc_c *)0x0) {
      dScnOpen_proc_c::dScnOpen_proc_c(this_00);
    }
    *(dScnOpen_proc_c **)(this + 0x1d0) = this_00;
    this[0x1d4] = (dScnOpen_c)0x0;
    m_Do_ext::mDoExt_restoreCurrentHeap();
    m_Do_ext::mDoExt_adjustSolidHeap(*(JKRSolidHeap **)(this + 0x1cc));
    pJVar1 = JFWDisplay::sManager;
    *(uint *)&JFWDisplay::sManager->field_0x24 = (DAT_800000f8 >> 2) / 0x1e;
    *(undefined2 *)&pJVar1->field_0x20 = 0;
    PVar2 = cPhs_COMPLEATE_e;
  }
  else {
    if (PVar2 == cPhs_ERROR_e) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_s_open.cpp",0x48,"rt == cPhs_COMPLEATE_e");
      m_Do_printf::OSPanic("d_s_open.cpp",0x48,&DAT_80362f75);
    }
  }
  return PVar2;
}


/* __thiscall dScnOpen_c::execute(void) */

undefined4 __thiscall dScnOpen_c::execute(dScnOpen_c *this)

{
  int iVar1;
  
  if (((*(int *)(*(int *)(this + 0x1d0) + 0x2b0) < 5) ||
      (iVar1 = f_op_overlap_mng::fopOvlpM_IsPeek(), iVar1 != 0)) ||
     (iVar1 = d_com_inf_game::dComIfG_resetToOpening(this), iVar1 != 0)) goto LAB_80232c74;
  if (*(short *)(this + 8) == 0xf) {
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
      if ((-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3) &&
         ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) == 0)) goto LAB_80232c50;
    }
    this[0x1d4] = (dScnOpen_c)0x1;
    JAIZelBasic::bgmStop(JAIZelBasic::zel_basic,0x14,0);
  }
LAB_80232c50:
  if ((this[0x1d4] == (dScnOpen_c)0x1) &&
     (iVar1 = m_Do_audio::mDoAud_isUsedHeapForStreamBuffer(), iVar1 == 0)) {
    d_com_inf_game::dComIfG_changeOpeningScene((scene_class *)this,9);
  }
LAB_80232c74:
  dScnOpen_proc_c::proc_execute(*(dScnOpen_proc_c **)(this + 0x1d0));
  if (*(int *)(*(int *)(this + 0x1d0) + 0x2b0) == 0x2c) {
    changeGameScene(this);
  }
  return 1;
}


/* __thiscall dScnOpen_c::draw(void) */

undefined4 __thiscall dScnOpen_c::draw(dScnOpen_c *this)

{
  create_tag_class *pcVar1;
  
  d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x22c =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow;
  d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x230 =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow;
  for (pcVar1 = (create_tag_class *)f_op_draw_iter::fopDwIt_Begin();
      pcVar1 != (create_tag_class *)0x0;
      pcVar1 = (create_tag_class *)f_op_draw_iter::fopDwIt_Next(pcVar1)) {
    f_pc_manager::fpcM_Draw(pcVar1->mpTagData);
  }
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(this + 0x1d0));
  return 1;
}


/* __thiscall dScnOpen_c::~dScnOpen_c(void) */

void __thiscall dScnOpen_c::_dScnOpen_c(dScnOpen_c *this)

{
  int *piVar1;
  short in_r4;
  
  if (this != (dScnOpen_c *)0x0) {
    piVar1 = *(int **)(this + 0x1d0);
    if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) {
      (**(code **)(*piVar1 + 8))(piVar1,1);
    }
    if (*(int *)(this + 0x1cc) != 0) {
      m_Do_ext::mDoExt_destroySolidHeap();
    }
    d_com_inf_game::dComIfG_resDelete((request_of_phase_process_class *)(this + 0x1c4),"Opening");
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 0;
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dScnOpen_c::changeGameScene(void) */

void __thiscall dScnOpen_c::changeGameScene(dScnOpen_c *this)

{
  int iVar1;
  
  iVar1 = f_op_overlap_mng::fopOvlpM_IsPeek();
  if (iVar1 == 0) {
    if (*(short *)(this + 8) == 0xf) {
      d_com_inf_game::dComIfG_changeOpeningScene((scene_class *)this,9);
    }
    else {
      iVar1 = f_op_scene_mng::fopScnM_ChangeReq(this,7,0,5);
      if (iVar1 != 0) {
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartParameters = 0;
        m_Do_audio::mDoAud_setSceneName
                  (0x803c9d48,
                   (int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mStartCode,
                   (int)(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mLayerNo);
      }
    }
  }
  return;
}


namespace d_s_open {

/* __stdcall dScnOpen_Draw(dScnOpen_c *) */

void dScnOpen_Draw(dScnOpen_c *param_1)

{
  ::dScnOpen_c::draw(param_1);
  return;
}


/* __stdcall dScnOpen_Execute(dScnOpen_c *) */

void dScnOpen_Execute(dScnOpen_c *param_1)

{
  ::dScnOpen_c::execute(param_1);
  return;
}


/* __stdcall dScnOpen_IsDelete(dScnOpen_c *) */

undefined4 dScnOpen_IsDelete(void)

{
  return 1;
}


/* __stdcall dScnOpen_Delete(dScnOpen_c *) */

undefined4 dScnOpen_Delete(dScnOpen_c *param_1)

{
  ::dScnOpen_c::_dScnOpen_c(param_1);
  return 1;
}


/* __stdcall dScnOpen_Create(scene_class *) */

void dScnOpen_Create(dScnOpen_c *param_1)

{
  ::dScnOpen_c::create(param_1);
  return;
}

