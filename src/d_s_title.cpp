#include <d_s_title.h>
#include <f_op_draw_iter.h>
#include <f_pc_manager.h>
#include <f_op_overlap_mng.h>
#include <d_com_inf_game.h>
#include <f_op_actor_mng.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <f_op_scene_mng.h>
#include <JAudio/JAIBankWave.h>
#include <d_meter.h>


namespace d_s_title {

/* __stdcall dScnTitle_Draw(title_of_scene_class *) */

undefined4 dScnTitle_Draw(void)

{
  create_tag_class *pcVar1;
  
  for (pcVar1 = (create_tag_class *)f_op_draw_iter::fopDwIt_Begin();
      pcVar1 != (create_tag_class *)0x0;
      pcVar1 = (create_tag_class *)f_op_draw_iter::fopDwIt_Next(pcVar1)) {
    f_pc_manager::fpcM_Draw(pcVar1->mpTagData);
  }
  return 1;
}


/* __stdcall dScnTitle_Execute(title_of_scene_class *) */

undefined4 dScnTitle_Execute(scene_class *param_1)

{
  int iVar1;
  ulong uVar2;
  code *pcVar3;
  int local_18 [5];
  
  iVar1 = f_op_overlap_mng::fopOvlpM_IsPeek();
  if ((iVar1 == 0) && (iVar1 = d_com_inf_game::dComIfG_resetToOpening(param_1), iVar1 == 0)) {
    iVar1 = f_op_actor_mng::fopAcM_SearchByID(param_1[2].parent.parent.mPi.mLayerQ,local_18);
    if (iVar1 == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_s_title.cpp",0x83,"rt");
      m_Do_printf::OSPanic("d_s_title.cpp",0x83,&DAT_80363821);
    }
    if (((local_18[0] != 0) && (pcVar3 = *(code **)(local_18[0] + 0x290), pcVar3 != (code *)0x0)) &&
       (*(int *)(local_18[0] + 0x294) != 0)) {
      if ((param_1->parent).parent.mProcName == 0xb) {
        iVar1 = (*pcVar3)();
        if (iVar1 == 0) {
          if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mNumGamesCompleted == 0
             ) {
            f_op_scene_mng::fopScnM_ChangeReq(param_1,0xd,0,5);
          }
          else {
            d_com_inf_game::dComIfG_changeOpeningScene(param_1,8);
          }
          (**(code **)(local_18[0] + 0x294))((double)_4049);
        }
      }
      else {
        if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) != 0) ||
            ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0')) ||
           (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) != 0 ||
            (iVar1 = (*pcVar3)(), iVar1 == 0)))) {
          d_com_inf_game::dComIfG_changeOpeningScene(param_1,8);
          (**(code **)(local_18[0] + 0x294))((double)_4049);
        }
      }
    }
  }
  return 1;
}


/* __stdcall dScnTitle_IsDelete(title_of_scene_class *) */

undefined4 dScnTitle_IsDelete(void)

{
  return 1;
}


/* __stdcall dScnTitle_Delete(title_of_scene_class *) */

undefined4 dScnTitle_Delete(void)

{
  return 1;
}


/* __stdcall dScnTitle_Create(scene_class *) */

undefined4 dScnTitle_Create(scene_class *this)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar2 = JAInter::BankWave::checkAllWaveLoadStatus();
  if ((uVar2 & 0xff) == 0) {
    d_meter::dMenu_flagSet(0);
    fopAc_ac_c::stopStatus = 0;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext = 0;
    iVar1 = -(int)(this->parent).parent.mProcName;
    iVar4 = iVar1 + 10;
    uVar2 = f_op_actor_mng::fopAcM_create
                      (0x1c2,iVar4 - ((uint)(iVar4 == 0) + iVar1 + 9),(cXyz *)0x0,-1,(csXyz *)0x0,
                       (cXyz *)0x0,0xff,(undefined *)0x0);
    this[2].parent.parent.mPi.mLayerQ = uVar2;
    uVar3 = 4;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

