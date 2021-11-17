#include <d_minigame_terminater.h>
#include <d_com_inf_game.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <m_Do_ext.h>
#include <JKernel/JKRHeap.h>
#include <d_minigame_terminater.h>
#include <f_op_msg_mng.h>
#include <d_drawlist.h>
#include <J2DGraph/J2DPane.h>
#include <J2DGraph/J2DScreen.h>
#include <J2DGraph/J2DPicture.h>
#include <SComponent/c_math.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <dDlst_TerminaterScrnDraw_c.h>
#include <dMinigame_Terminater_c.h>


/* __thiscall dMinigame_Terminater_c::_create(void) */

PhaseState __thiscall dMinigame_Terminater_c::_create(dMinigame_Terminater_c *this)

{
  PhaseState PVar1;
  dRes_info_c *pdVar2;
  ulong uVar3;
  JKRSolidHeap *pJVar4;
  undefined **ppuVar5;
  fopMsgM_prm_class *pfVar6;
  
  PVar1 = d_com_inf_game::dComIfG_resLoad((request_of_phase_process_class *)(this + 0x100),"Mgtem");
  if (PVar1 == cPhs_COMPLEATE_e) {
    pdVar2 = dRes_control_c::getResInfo
                       ("Mgtem",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pdVar2 == (dRes_info_c *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_minigame_terminater.cpp",0x66,"resInfo != 0");
      m_Do_printf::OSPanic("d_minigame_terminater.cpp",0x66,&DAT_80361c85);
    }
    pJVar4 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(0xc0a0,0x20);
    *(JKRSolidHeap **)(this + 0x108) = pJVar4;
    if (*(int *)(this + 0x108) == 0) {
      PVar1 = cPhs_ERROR_e;
    }
    else {
      ppuVar5 = (undefined **)JKernel::operator_new(0x1988);
      if (ppuVar5 != (undefined **)0x0) {
        *ppuVar5 = (undefined *)&dDlst_base_c::__vt;
        *ppuVar5 = &dDlst_TerminaterScrnDraw_c::__vt;
        *(undefined2 *)(ppuVar5 + 0x660) = 0;
        *(undefined2 *)((int)ppuVar5 + 0x1982) = 0;
        *(undefined2 *)(ppuVar5 + 0x661) = 0;
      }
      *(undefined ***)(this + 0xfc) = ppuVar5;
      dDlst_TerminaterScrnDraw_c::setScreen
                (*(dDlst_TerminaterScrnDraw_c **)(this + 0xfc),"ship_race2.blo",pdVar2->mpArchive);
      m_Do_ext::mDoExt_restoreCurrentHeap();
      m_Do_ext::mDoExt_adjustSolidHeap(*(JKRSolidHeap **)(this + 0x108));
      pfVar6 = f_op_msg_mng::fopMsgM_GetAppend((msg_class *)this);
      *(undefined2 *)(this + 0x11a) = *(undefined2 *)&pfVar6[1].mPos.y;
      *(undefined2 *)(this + 0x118) = *(undefined2 *)((int)&pfVar6[1].mPos.y + 2);
      *(fopAc_ac_c **)(this + 0x10c) = pfVar6[1].mpActor;
      *(float *)(this + 0x110) = pfVar6[1].mPos.x;
      if ((*(short *)(this + 0x118) == 2) || (*(short *)(this + 0x118) == 1)) {
        dDlst_TerminaterScrnDraw_c::setScrnSuccess
                  (*(dDlst_TerminaterScrnDraw_c **)(this + 0xfc),*(int *)(this + 0x110),
                   *(int *)(this + 0x10c));
      }
      else {
        dDlst_TerminaterScrnDraw_c::setScrnFailed(*(dDlst_TerminaterScrnDraw_c **)(this + 0xfc));
      }
      *(undefined2 *)(this + 0x114) = 0x14a;
      this[0x11c] = (dMinigame_Terminater_c)0x1;
      PVar1 = cPhs_COMPLEATE_e;
    }
  }
  return PVar1;
}


/* __thiscall dMinigame_Terminater_c::_execute(void) */

undefined4 __thiscall dMinigame_Terminater_c::_execute(dMinigame_Terminater_c *this)

{
  short sVar1;
  
  sVar1 = *(short *)(this + 0x114);
  if (sVar1 < 0xf1) {
    if (*(short *)(this + 0x118) == 2) {
      if (sVar1 < 1) {
        this[0x11c] = (dMinigame_Terminater_c)0x3;
      }
      else {
        dDlst_TerminaterScrnDraw_c::animeSuccess(*(dDlst_TerminaterScrnDraw_c **)(this + 0xfc));
        dDlst_TerminaterScrnDraw_c::animePerfect(*(dDlst_TerminaterScrnDraw_c **)(this + 0xfc));
        *(short *)(this + 0x114) = *(short *)(this + 0x114) + -1;
      }
    }
    else {
      if (*(short *)(this + 0x118) == 1) {
        if (sVar1 < 1) {
          this[0x11c] = (dMinigame_Terminater_c)0x3;
        }
        else {
          dDlst_TerminaterScrnDraw_c::animeSuccess(*(dDlst_TerminaterScrnDraw_c **)(this + 0xfc));
          *(short *)(this + 0x114) = *(short *)(this + 0x114) + -1;
        }
      }
      else {
        if (sVar1 < 1) {
          this[0x11c] = (dMinigame_Terminater_c)0x3;
        }
        else {
          if (sVar1 < 0x78) {
            dDlst_TerminaterScrnDraw_c::animeFailed2(*(dDlst_TerminaterScrnDraw_c **)(this + 0xfc));
          }
          else {
            dDlst_TerminaterScrnDraw_c::animeFailed1(*(dDlst_TerminaterScrnDraw_c **)(this + 0xfc));
          }
          *(short *)(this + 0x114) = *(short *)(this + 0x114) + -1;
        }
      }
    }
  }
  else {
    *(short *)(this + 0x114) = sVar1 + -1;
  }
  return 1;
}


/* __thiscall dMinigame_Terminater_c::_draw(void) */

undefined4 __thiscall dMinigame_Terminater_c::_draw(dMinigame_Terminater_c *this)

{
  if ((*(short *)(this + 0x118) == 2) || (*(short *)(this + 0x118) == 1)) {
    dDlst_TerminaterScrnDraw_c::setAlphaSuccess(*(dDlst_TerminaterScrnDraw_c **)(this + 0xfc));
  }
  else {
    dDlst_TerminaterScrnDraw_c::setAlphaFailed(*(dDlst_TerminaterScrnDraw_c **)(this + 0xfc));
  }
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(this + 0xfc));
  return 1;
}


/* __thiscall dMinigame_Terminater_c::_delete(void) */

undefined4 __thiscall dMinigame_Terminater_c::_delete(dMinigame_Terminater_c *this)

{
  if (*(int *)(this + 0x108) != 0) {
    m_Do_ext::mDoExt_destroySolidHeap();
  }
  d_com_inf_game::dComIfG_resDelete((request_of_phase_process_class *)(this + 0x100),"Mgtem");
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dDlst_TerminaterScrnDraw_c::setScreen(char const *,
                                                    JKRArchive *) */

void __thiscall
dDlst_TerminaterScrnDraw_c::setScreen
          (dDlst_TerminaterScrnDraw_c *this,char *param_1,JKRArchive *param_2)

{
  J2DPane *this_00;
  TBox2_float_ local_28;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_28.mTL.x = d_minigame_terminater::_4104;
    local_28.mTL.y = d_minigame_terminater::_4104;
    local_28.mBR.x = d_minigame_terminater::_4105;
    local_28.mBR.y = d_minigame_terminater::_4106;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 4) = this_00;
  J2DScreen::set(*(J2DScreen **)(this + 4),param_1,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall dDlst_TerminaterScrnDraw_c::setScrnFailed(void) */

void __thiscall dDlst_TerminaterScrnDraw_c::setScrnFailed(dDlst_TerminaterScrnDraw_c *this)

{
  int iVar1;
  dDlst_TerminaterScrnDraw_c *pdVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  for (iVar1 = 0; iVar1 < d_minigame_terminater::dMgtem_perfect_tex; iVar1 = iVar1 + 1) {
    iVar4 = (**(code **)(**(int **)(this + 4) + 0x30))
                      (*(int **)(this + 4),
                       *(undefined4 *)((int)&d_minigame_terminater::perfect_4111 + iVar3));
    *(undefined *)(iVar4 + 0xaa) = 0;
    iVar3 = iVar3 + 4;
  }
  iVar4 = 0;
  iVar3 = 0;
  for (iVar1 = 0; iVar1 < d_minigame_terminater::dMgtem_failed_tex; iVar1 = iVar1 + 1) {
    pdVar2 = this + iVar3;
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar2 + 0x6d0),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_minigame_terminater::failed_4119 + iVar4));
    getRotate(this,(fopMsgM_pane_class *)(pdVar2 + 0x6d0));
    *(undefined2 *)(pdVar2 + 0xd96) = 0;
    *(undefined2 *)(pdVar2 + 0x114e) = 0;
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 0x38;
  }
  iVar3 = 0;
  for (iVar1 = 0; iVar1 < d_minigame_terminater::dMgtem_remain_tex + 1; iVar1 = iVar1 + 1) {
    iVar4 = (**(code **)(**(int **)(this + 4) + 0x30))
                      (*(int **)(this + 4),
                       *(undefined4 *)((int)&d_minigame_terminater::remaintime_4125 + iVar3));
    *(undefined *)(iVar4 + 0xaa) = 0;
    iVar3 = iVar3 + 4;
  }
  iVar3 = 0;
  for (iVar1 = 0; iVar1 < d_minigame_terminater::dMgtem_remain_tex; iVar1 = iVar1 + 1) {
    iVar4 = (**(code **)(**(int **)(this + 4) + 0x30))
                      (*(int **)(this + 4),*(undefined4 *)("rke2rkm2rki3" + iVar3));
    *(undefined *)(iVar4 + 0xaa) = 0;
    iVar3 = iVar3 + 4;
  }
  iVar1 = 0;
  iVar3 = 0;
  do {
    iVar4 = (**(code **)(**(int **)(this + 4) + 0x30))
                      (*(int **)(this + 4),
                       *(undefined4 *)((int)&d_minigame_terminater::perfect_nt_4117 + iVar3));
    *(undefined *)(iVar4 + 0xaa) = 0;
    iVar4 = (**(code **)(**(int **)(this + 4) + 0x30))
                      (*(int **)(this + 4),
                       *(undefined4 *)((int)&d_minigame_terminater::perfect_nk_4118 + iVar3));
    *(undefined *)(iVar4 + 0xaa) = 0;
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar1 < 10);
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x646d7065);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756d36);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756d35);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756d34);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756d33);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756d32);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756d31);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e6d6432);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e6d6431);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756b36);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756b35);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756b34);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756b33);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756b32);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756b31);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e646b32);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e646b31);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x727078);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x7270786b);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e743030);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e6b3030);
  *(undefined *)(iVar1 + 0xaa) = 0;
  iVar1 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x646d6d79);
  *(undefined *)(iVar1 + 0xaa) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall dDlst_TerminaterScrnDraw_c::setScrnSuccess(int,
                                                         int) */

void __thiscall
dDlst_TerminaterScrnDraw_c::setScrnSuccess(dDlst_TerminaterScrnDraw_c *this,int param_1,int param_2)

{
  J2DScreen *pJVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar5 = 0;
  iVar6 = 0;
  for (iVar3 = 0; iVar3 < d_minigame_terminater::dMgtem_perfect_tex; iVar3 = iVar3 + 1) {
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 4) + 0x30))
                       (*(int **)(this + 4),
                        *(undefined4 *)((int)&d_minigame_terminater::perfect_4203 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar5 + 8),pJVar1);
    iVar5 = iVar5 + 0x38;
    iVar6 = iVar6 + 4;
  }
  iVar5 = 0;
  for (iVar3 = 0; iVar3 < d_minigame_terminater::dMgtem_failed_tex; iVar3 = iVar3 + 1) {
    iVar6 = (**(code **)(**(int **)(this + 4) + 0x30))
                      (*(int **)(this + 4),
                       *(undefined4 *)((int)&d_minigame_terminater::failed_4211 + iVar5));
    *(undefined *)(iVar6 + 0xaa) = 0;
    iVar5 = iVar5 + 4;
  }
  iVar5 = 0;
  iVar6 = 0;
  for (iVar3 = 0; iVar3 < d_minigame_terminater::dMgtem_yougot_tex; iVar3 = iVar3 + 1) {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar6 + 0xa88),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_minigame_terminater::yougot_4217 + iVar5));
    iVar5 = iVar5 + 4;
    iVar6 = iVar6 + 0x38;
  }
  iVar5 = 0;
  iVar6 = 0;
  for (iVar3 = 0; iVar3 < d_minigame_terminater::dMgtem_remain_tex; iVar3 = iVar3 + 1) {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar6 + 0xd60),*(J2DScreen **)(this + 4),
               *(int *)("yotree2rem2rei3" + iVar5 + 3));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar6 + 0x1118),*(J2DScreen **)(this + 4),
               *(int *)("rke2rkm2rki3" + iVar5));
    iVar5 = iVar5 + 4;
    iVar6 = iVar6 + 0x38;
  }
  iVar3 = 0;
  iVar6 = 0;
  iVar5 = 0;
  do {
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 4) + 0x30))
                       (*(int **)(this + 4),
                        *(undefined4 *)((int)&d_minigame_terminater::perfect_nt_4209 + iVar5));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar6 + 0x238),pJVar1);
    pJVar1 = (J2DScreen *)
             (**(code **)(**(int **)(this + 4) + 0x30))
                       (*(int **)(this + 4),
                        *(undefined4 *)((int)&d_minigame_terminater::perfect_nk_4210 + iVar5));
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + iVar6 + 0x468),pJVar1);
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 0x38;
    iVar5 = iVar5 + 4;
  } while (iVar3 < 10);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x646d7065);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x698),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756d36);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x14d0),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756d35);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1508),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e6d6432);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1540),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756d34);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1578),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756d33);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x15b0),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e6d6431);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x15e8),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756d32);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1620),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756d31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1658),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756b36);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1690),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756b35);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x16c8),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e646b32);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1700),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756b34);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1738),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756b33);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 6000),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e646b31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x17a8),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756b32);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x17e0),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e756b31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1818),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x727078);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1850),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x7270786b);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1888),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e743030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x18c0),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x6e6b3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x18f8),pJVar1);
  pJVar1 = (J2DScreen *)(**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x646d6d79);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1930),pJVar1);
  uVar2 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x727033);
  *(undefined4 *)(this + 0x1968) = uVar2;
  uVar2 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x727032);
  *(undefined4 *)(this + 0x196c) = uVar2;
  uVar2 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x727031);
  *(undefined4 *)(this + 0x1970) = uVar2;
  uVar2 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x72706b33);
  *(undefined4 *)(this + 0x1974) = uVar2;
  uVar2 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x72706b32);
  *(undefined4 *)(this + 0x1978) = uVar2;
  uVar2 = (**(code **)(**(int **)(this + 4) + 0x30))(*(int **)(this + 4),0x72706b31);
  *(undefined4 *)(this + 0x197c) = uVar2;
  iVar6 = (param_2 / 100) / 0x3c;
  iVar3 = (param_2 / 100) % 0x3c;
  iVar5 = iVar6 / 10;
  changeNumberTexture(this,*(J2DPane **)(this + 0x1658),iVar5);
  iVar6 = iVar6 % 10;
  changeNumberTexture(this,*(J2DPane **)(this + 0x1620),iVar6);
  iVar4 = iVar3 / 10;
  changeNumberTexture(this,*(J2DPane **)(this + 0x15b0),iVar4);
  iVar3 = iVar3 % 10;
  changeNumberTexture(this,*(J2DPane **)(this + 0x1578),iVar3);
  iVar7 = (param_2 % 100) / 10;
  changeNumberTexture(this,*(J2DPane **)(this + 0x1508),iVar7);
  iVar8 = (param_2 % 100) % 10;
  changeNumberTexture(this,*(J2DPane **)(this + 0x14d0),iVar8);
  changeNumberTexture(this,*(J2DPane **)(this + 0x1818),iVar5);
  changeNumberTexture(this,*(J2DPane **)(this + 0x17e0),iVar6);
  changeNumberTexture(this,*(J2DPane **)(this + 6000),iVar4);
  changeNumberTexture(this,*(J2DPane **)(this + 0x1738),iVar3);
  changeNumberTexture(this,*(J2DPane **)(this + 0x16c8),iVar7);
  changeNumberTexture(this,*(J2DPane **)(this + 0x1690),iVar8);
  iVar3 = (param_1 % 100) / 10;
  changeNumberTexture(this,*(J2DPane **)(this + 0x1968),param_1 % 10);
  changeNumberTexture(this,*(J2DPane **)(this + 0x196c),iVar3);
  changeNumberTexture(this,*(J2DPane **)(this + 0x1970),param_1 / 100);
  changeNumberTexture(this,*(J2DPane **)(this + 0x1974),param_1 % 10);
  changeNumberTexture(this,*(J2DPane **)(this + 0x1978),iVar3);
  changeNumberTexture(this,*(J2DPane **)(this + 0x197c),param_1 / 100);
  return;
}


/* __thiscall dDlst_TerminaterScrnDraw_c::changeNumberTexture(J2DPane *,
                                                              int) */

void __thiscall
dDlst_TerminaterScrnDraw_c::changeNumberTexture
          (dDlst_TerminaterScrnDraw_c *this,J2DPane *param_1,int param_2)

{
  char *pcVar1;
  
  if ((param_2 < 0) || (9 < param_2)) {
    param_2 = 0;
  }
  pcVar1 = (char *)getNumber(this,param_2);
  J2DPicture::changeTexture((J2DPicture *)param_1,pcVar1,0);
  return;
}


/* __thiscall dDlst_TerminaterScrnDraw_c::getNumber(int) */

undefined * __thiscall
dDlst_TerminaterScrnDraw_c::getNumber(dDlst_TerminaterScrnDraw_c *this,int param_1)

{
  return (&d_minigame_terminater::number_4258)[param_1];
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDlst_TerminaterScrnDraw_c::setAlphaFailed(void) */

void __thiscall dDlst_TerminaterScrnDraw_c::setAlphaFailed(dDlst_TerminaterScrnDraw_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = 0; iVar1 < d_minigame_terminater::dMgtem_failed_tex; iVar1 = iVar1 + 1) {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x6d0));
    iVar2 = iVar2 + 0x38;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dDlst_TerminaterScrnDraw_c::setAlphaSuccess(void) */

void __thiscall dDlst_TerminaterScrnDraw_c::setAlphaSuccess(dDlst_TerminaterScrnDraw_c *this)

{
  int iVar1;
  int iVar2;
  
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 8));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x238));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x468));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x698));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xa88));
  iVar2 = 0;
  for (iVar1 = 0; iVar1 < d_minigame_terminater::dMgtem_remain_tex; iVar1 = iVar1 + 1) {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0xd60));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x1118));
    iVar2 = iVar2 + 0x38;
  }
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x14d0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x1690));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 8);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1850));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1888));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x18c0));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x18f8));
  return;
}


/* __thiscall dDlst_TerminaterScrnDraw_c::getRotate(fopMsgM_pane_class *) */

void __thiscall
dDlst_TerminaterScrnDraw_c::getRotate(dDlst_TerminaterScrnDraw_c *this,fopMsgM_pane_class *param_1)

{
  float fVar1;
  
  fVar1 = (param_1->mpPane->parent).mRotation;
  if (d_minigame_terminater::_4295 < fVar1) {
    fVar1 = fVar1 - d_minigame_terminater::_4294;
  }
  param_1->mUserData = (short)(int)fVar1;
  return;
}


/* __thiscall dDlst_TerminaterScrnDraw_c::setRotate(fopMsgM_pane_class *,
                                                    float) */

void __thiscall
dDlst_TerminaterScrnDraw_c::setRotate
          (dDlst_TerminaterScrnDraw_c *this,fopMsgM_pane_class *param_1,float param_2)

{
  double dVar1;
  J2DScreen *pJVar2;
  
  dVar1 = (double)CONCAT44(0x43300000,
                           (int)((param_1->mSize).y * d_minigame_terminater::_4305) ^ 0x80000000) -
          d_minigame_terminater::_4308;
  pJVar2 = param_1->mpPane;
  (pJVar2->parent).mBasePosition.x =
       (float)((double)CONCAT44(0x43300000,
                                (int)((param_1->mSize).x * d_minigame_terminater::_4305) ^
                                0x80000000) - d_minigame_terminater::_4308);
  (pJVar2->parent).mBasePosition.y = (float)dVar1;
  (pJVar2->parent).mRotationAxis = 'z';
  (pJVar2->parent).mRotation = param_2;
  (*(code *)((pJVar2->parent).vtbl)->calcMtx)();
  return;
}


/* __thiscall dDlst_TerminaterScrnDraw_c::setScale(fopMsgM_pane_class *,
                                                   float) */

void __thiscall
dDlst_TerminaterScrnDraw_c::setScale
          (dDlst_TerminaterScrnDraw_c *this,fopMsgM_pane_class *param_1,float param_2)

{
  (param_1->mPosCenter).x = (param_1->mPosCenterOrig).x * param_2;
  (param_1->mPosCenter).y = (param_1->mPosCenterOrig).y * param_2;
  (param_1->mSize).x = (param_1->mSizeOrig).x * param_2;
  (param_1->mSize).y = (param_1->mSizeOrig).y * param_2;
  f_op_msg_mng::fopMsgM_cposMove(param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80208418) */
/* WARNING: Removing unreachable block (ram,0x80208420) */
/* __thiscall dDlst_TerminaterScrnDraw_c::animeF1(int) */

bool __thiscall dDlst_TerminaterScrnDraw_c::animeF1(dDlst_TerminaterScrnDraw_c *this,int param_1)

{
  short sVar1;
  dDlst_TerminaterScrnDraw_c *pdVar2;
  fopMsgM_pane_class *this_00;
  undefined4 uVar3;
  undefined8 in_f30;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  pdVar2 = this + param_1 * 0x38;
  sVar1 = *(short *)(pdVar2 + 0xd96);
  if (0x19 >= sVar1) {
    *(short *)(pdVar2 + 0xd96) = sVar1 + 1;
    dVar5 = (double)(((float)((double)CONCAT44(0x43300000,
                                               (int)*(short *)(pdVar2 + 0xd96) ^ 0x80000000U) -
                             d_minigame_terminater::_4308) *
                     (float)((double)CONCAT44(0x43300000,
                                              (int)*(short *)(pdVar2 + 0xd96) ^ 0x80000000U) -
                            d_minigame_terminater::_4308)) / d_minigame_terminater::_4334);
    dVar4 = (double)(d_minigame_terminater::_4335 *
                     (float)((double)d_minigame_terminater::_4336 - dVar5) +
                    (float)((double)CONCAT44(0x43300000,(int)*(short *)(pdVar2 + 0x706) ^ 0x80000000
                                            ) - d_minigame_terminater::_4308));
    this_00 = (fopMsgM_pane_class *)(this + param_1 * 0x38 + 0x6d0);
    f_op_msg_mng::fopMsgM_paneTrans
              (this_00,(double)(d_minigame_terminater::_4337 *
                               (float)((double)d_minigame_terminater::_4336 - dVar5)),
               (double)d_minigame_terminater::_4104);
    setRotate(this,this_00,(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha(this_00,(float)dVar5);
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return 0x19 < sVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80208e10) */
/* WARNING: Removing unreachable block (ram,0x80208e18) */
/* __thiscall dDlst_TerminaterScrnDraw_c::animeF2(int) */

undefined4 __thiscall
dDlst_TerminaterScrnDraw_c::animeF2(dDlst_TerminaterScrnDraw_c *this,int param_1)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  dDlst_TerminaterScrnDraw_c *pdVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  fopMsgM_pane_class *this_00;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined8 in_f30;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  uVar9 = 0;
  iVar3 = param_1 * 0x38;
  pdVar5 = this + iVar3;
  iVar4 = (int)DAT_80361be8;
  if (*(short *)(pdVar5 + 0xd96) < iVar4) {
    *(short *)(pdVar5 + 0xd96) = *(short *)(pdVar5 + 0xd96) + 1;
    uVar2 = SEXT24(*(short *)(pdVar5 + 0xd96));
    uVar6 = SEXT24(d_minigame_terminater::animeFrame_4344);
    if ((int)uVar6 < (int)uVar2) {
      iVar8 = (int)DAT_80361bde;
      if (iVar8 < (int)uVar2) {
        iVar7 = (int)DAT_80361be0;
        if (iVar7 < (int)uVar2) {
          iVar8 = (int)DAT_80361be2;
          if (iVar8 < (int)uVar2) {
            iVar7 = (int)DAT_80361be4;
            if (iVar7 < (int)uVar2) {
              iVar8 = (int)DAT_80361be6;
              if (iVar8 < (int)uVar2) {
                if ((int)uVar2 <= iVar4) {
                  uVar2 = uVar2 - iVar8 ^ 0x80000000;
                  uVar6 = iVar4 - iVar8 ^ 0x80000000;
                  fVar1 = d_minigame_terminater::_4336 -
                          ((float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308
                                  ) *
                          (float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308)
                          ) / ((float)((double)CONCAT44(0x43300000,uVar6) -
                                      d_minigame_terminater::_4308) *
                              (float)((double)CONCAT44(0x43300000,uVar6) -
                                     d_minigame_terminater::_4308));
                  dVar11 = (double)((float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_80361c1a ^ 0x80000000) -
                                           d_minigame_terminater::_4308) +
                                   fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                    (int)DAT_80361c18 -
                                                                    (int)DAT_80361c1a ^ 0x80000000)
                                                  - d_minigame_terminater::_4308));
                  f_op_msg_mng::fopMsgM_paneTrans
                            ((fopMsgM_pane_class *)(this + iVar3 + 0x6d0),
                             (double)((float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_80361bfa ^ 0x80000000) -
                                             d_minigame_terminater::_4308) +
                                     fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                      (int)DAT_80361bf8 -
                                                                      (int)DAT_80361bfa ^ 0x80000000
                                                                     ) -
                                                    d_minigame_terminater::_4308)),
                             (double)((float)((double)CONCAT44(0x43300000,
                                                               (int)DAT_80361c0a ^ 0x80000000) -
                                             d_minigame_terminater::_4308) +
                                     fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                      (int)DAT_80361c08 -
                                                                      (int)DAT_80361c0a ^ 0x80000000
                                                                     ) -
                                                    d_minigame_terminater::_4308)));
                  setRotate(this,(fopMsgM_pane_class *)(this + iVar3 + 0x6d0),(float)dVar11);
                }
              }
              else {
                uVar2 = uVar2 - iVar7 ^ 0x80000000;
                uVar6 = iVar8 - iVar7 ^ 0x80000000;
                fVar1 = d_minigame_terminater::_4336 -
                        ((float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308)
                        * (float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308)
                        ) / ((float)((double)CONCAT44(0x43300000,uVar6) -
                                    d_minigame_terminater::_4308) *
                            (float)((double)CONCAT44(0x43300000,uVar6) -
                                   d_minigame_terminater::_4308));
                dVar11 = (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c18 ^ 0x80000000
                                                          ) - d_minigame_terminater::_4308) +
                                 fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                  (int)DAT_80361c16 -
                                                                  (int)DAT_80361c18 ^ 0x80000000) -
                                                d_minigame_terminater::_4308));
                f_op_msg_mng::fopMsgM_paneTrans
                          ((fopMsgM_pane_class *)(this + iVar3 + 0x6d0),
                           (double)((float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_80361bf8 ^ 0x80000000) -
                                           d_minigame_terminater::_4308) +
                                   fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                    (int)DAT_80361bf6 -
                                                                    (int)DAT_80361bf8 ^ 0x80000000)
                                                  - d_minigame_terminater::_4308)),
                           (double)((float)((double)CONCAT44(0x43300000,
                                                             (int)DAT_80361c08 ^ 0x80000000) -
                                           d_minigame_terminater::_4308) +
                                   fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                    (int)DAT_80361c06 -
                                                                    (int)DAT_80361c08 ^ 0x80000000)
                                                  - d_minigame_terminater::_4308)));
                setRotate(this,(fopMsgM_pane_class *)(this + iVar3 + 0x6d0),(float)dVar11);
              }
            }
            else {
              uVar2 = uVar2 - iVar8 ^ 0x80000000;
              uVar6 = iVar7 - iVar8 ^ 0x80000000;
              fVar1 = d_minigame_terminater::_4336 -
                      ((float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308) *
                      (float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308)) /
                      ((float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_terminater::_4308) *
                      (float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_terminater::_4308));
              dVar11 = (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c16 ^ 0x80000000)
                                       - d_minigame_terminater::_4308) +
                               fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_80361c14 -
                                                                (int)DAT_80361c16 ^ 0x80000000) -
                                              d_minigame_terminater::_4308));
              f_op_msg_mng::fopMsgM_paneTrans
                        ((fopMsgM_pane_class *)(this + iVar3 + 0x6d0),
                         (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361bf6 ^ 0x80000000
                                                          ) - d_minigame_terminater::_4308) +
                                 fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                  (int)DAT_80361bf4 -
                                                                  (int)DAT_80361bf6 ^ 0x80000000) -
                                                d_minigame_terminater::_4308)),
                         (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c06 ^ 0x80000000
                                                          ) - d_minigame_terminater::_4308) +
                                 fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                  (int)DAT_80361c04 -
                                                                  (int)DAT_80361c06 ^ 0x80000000) -
                                                d_minigame_terminater::_4308)));
              setRotate(this,(fopMsgM_pane_class *)(this + iVar3 + 0x6d0),(float)dVar11);
            }
          }
          else {
            uVar2 = uVar2 - iVar7 ^ 0x80000000;
            uVar6 = iVar8 - iVar7 ^ 0x80000000;
            fVar1 = d_minigame_terminater::_4336 -
                    ((float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308) *
                    (float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308)) /
                    ((float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_terminater::_4308) *
                    (float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_terminater::_4308));
            dVar11 = (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c14 ^ 0x80000000) -
                                     d_minigame_terminater::_4308) +
                             fVar1 * (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_80361c12 - (int)DAT_80361c14
                                                              ^ 0x80000000) -
                                            d_minigame_terminater::_4308));
            f_op_msg_mng::fopMsgM_paneTrans
                      ((fopMsgM_pane_class *)(this + iVar3 + 0x6d0),
                       (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361bf4 ^ 0x80000000)
                                       - d_minigame_terminater::_4308) +
                               fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_80361bf2 -
                                                                (int)DAT_80361bf4 ^ 0x80000000) -
                                              d_minigame_terminater::_4308)),
                       (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c04 ^ 0x80000000)
                                       - d_minigame_terminater::_4308) +
                               fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_80361c02 -
                                                                (int)DAT_80361c04 ^ 0x80000000) -
                                              d_minigame_terminater::_4308)));
            setRotate(this,(fopMsgM_pane_class *)(this + iVar3 + 0x6d0),(float)dVar11);
          }
        }
        else {
          uVar2 = uVar2 - iVar8 ^ 0x80000000;
          uVar6 = iVar7 - iVar8 ^ 0x80000000;
          fVar1 = d_minigame_terminater::_4336 -
                  ((float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308) *
                  (float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308)) /
                  ((float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_terminater::_4308) *
                  (float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_terminater::_4308));
          dVar11 = (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c12 ^ 0x80000000) -
                                   d_minigame_terminater::_4308) +
                           fVar1 * (float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_80361c10 - (int)DAT_80361c12 ^
                                                            0x80000000) -
                                          d_minigame_terminater::_4308));
          f_op_msg_mng::fopMsgM_paneTrans
                    ((fopMsgM_pane_class *)(this + iVar3 + 0x6d0),
                     (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361bf2 ^ 0x80000000) -
                                     d_minigame_terminater::_4308) +
                             fVar1 * (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_80361bf0 - (int)DAT_80361bf2
                                                              ^ 0x80000000) -
                                            d_minigame_terminater::_4308)),
                     (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c02 ^ 0x80000000) -
                                     d_minigame_terminater::_4308) +
                             fVar1 * (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_80361c00 - (int)DAT_80361c02
                                                              ^ 0x80000000) -
                                            d_minigame_terminater::_4308)));
          setRotate(this,(fopMsgM_pane_class *)(this + iVar3 + 0x6d0),(float)dVar11);
        }
      }
      else {
        uVar2 = uVar2 - uVar6 ^ 0x80000000;
        uVar6 = iVar8 - uVar6 ^ 0x80000000;
        fVar1 = d_minigame_terminater::_4336 -
                ((float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308) *
                (float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308)) /
                ((float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_terminater::_4308) *
                (float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_terminater::_4308));
        dVar11 = (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c10 ^ 0x80000000) -
                                 d_minigame_terminater::_4308) +
                         fVar1 * (float)((double)CONCAT44(0x43300000,
                                                          (int)DAT_80361c0e - (int)DAT_80361c10 ^
                                                          0x80000000) - d_minigame_terminater::_4308
                                        ));
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + iVar3 + 0x6d0),
                   (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361bf0 ^ 0x80000000) -
                                   d_minigame_terminater::_4308) +
                           fVar1 * (float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_80361bee - (int)DAT_80361bf0 ^
                                                            0x80000000) -
                                          d_minigame_terminater::_4308)),
                   (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c00 ^ 0x80000000) -
                                   d_minigame_terminater::_4308) +
                           fVar1 * (float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_80361bfe - (int)DAT_80361c00 ^
                                                            0x80000000) -
                                          d_minigame_terminater::_4308)));
        setRotate(this,(fopMsgM_pane_class *)(this + iVar3 + 0x6d0),(float)dVar11);
      }
    }
    else {
      dVar12 = (double)(((float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) -
                                d_minigame_terminater::_4308) *
                        (float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) -
                               d_minigame_terminater::_4308)) /
                       ((float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) -
                               d_minigame_terminater::_4308) *
                       (float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) -
                              d_minigame_terminater::_4308)));
      fVar1 = (float)((double)d_minigame_terminater::_4336 - dVar12);
      dVar11 = (double)(d_minigame_terminater::_4492 * fVar1 +
                       (float)((double)CONCAT44(0x43300000,(int)DAT_80361c0e ^ 0x80000000) -
                              d_minigame_terminater::_4308));
      this_00 = (fopMsgM_pane_class *)(this + iVar3 + 0x6d0);
      f_op_msg_mng::fopMsgM_paneTrans
                (this_00,(double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361bee ^ 0x80000000
                                                          ) - d_minigame_terminater::_4308) +
                                 fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                  (int)d_minigame_terminater::
                                                                       transX_4345 -
                                                                  (int)DAT_80361bee ^ 0x80000000) -
                                                d_minigame_terminater::_4308)),
                 (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361bfe ^ 0x80000000) -
                                 d_minigame_terminater::_4308) +
                         fVar1 * (float)((double)CONCAT44(0x43300000,
                                                          (int)d_minigame_terminater::transY_4346 -
                                                          (int)DAT_80361bfe ^ 0x80000000) -
                                        d_minigame_terminater::_4308)));
      setRotate(this,this_00,(float)dVar11);
      f_op_msg_mng::fopMsgM_setNowAlpha(this_00,(float)dVar12);
    }
  }
  else {
    uVar9 = 1;
  }
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  return uVar9;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x802091b0) */
/* WARNING: Removing unreachable block (ram,0x802091b8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dDlst_TerminaterScrnDraw_c::animeF3(int) */

undefined4 __thiscall
dDlst_TerminaterScrnDraw_c::animeF3(dDlst_TerminaterScrnDraw_c *this,int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  dDlst_TerminaterScrnDraw_c *pdVar7;
  fopMsgM_pane_class *this_00;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined8 in_f30;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  float fVar13;
  double local_98;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  uVar8 = 0;
  iVar9 = param_1 * 0x38;
  pdVar7 = this + iVar9;
  if (*(short *)(pdVar7 + 0x114e) == 0) {
    fVar13 = SComponent::cM_rndF(d_minigame_terminater::_4557);
    iVar2 = (int)fVar13;
    if (5 < iVar2) {
      iVar2 = 5;
    }
    *(undefined2 *)(this + iVar9 + 0xd96) =
         *(undefined2 *)(&d_minigame_terminater::rot_4508 + iVar2 * 2);
  }
  sVar1 = _UNK_803fb47e;
  uVar6 = SEXT24(_UNK_803fb47e);
  if ((int)*(short *)(pdVar7 + 0x114e) < (int)uVar6) {
    *(short *)(pdVar7 + 0x114e) = *(short *)(pdVar7 + 0x114e) + 1;
    uVar5 = SEXT24(*(short *)(pdVar7 + 0x114e));
    uVar4 = SEXT24(d_minigame_terminater::animeFrame_4506);
    if ((int)uVar4 < (int)uVar5) {
      uVar3 = uVar5 - uVar4 ^ 0x80000000;
      uVar4 = (int)sVar1 - uVar4 ^ 0x80000000;
      dVar12 = (double)(d_minigame_terminater::_4336 -
                       ((float)((double)CONCAT44(0x43300000,uVar3) - d_minigame_terminater::_4308) *
                       (float)((double)CONCAT44(0x43300000,uVar3) - d_minigame_terminater::_4308)) /
                       ((float)((double)CONCAT44(0x43300000,uVar4) - d_minigame_terminater::_4308) *
                       (float)((double)CONCAT44(0x43300000,uVar4) - d_minigame_terminater::_4308)));
      local_98 = (double)CONCAT44(0x43300000,(int)*(short *)(this + iVar9 + 0xd96) ^ 0x80000000);
      dVar11 = (double)((float)((double)CONCAT44(0x43300000,
                                                 (int)*(short *)(this + iVar9 + 0x706) ^ 0x80000000)
                               - d_minigame_terminater::_4308) +
                       (float)(local_98 - d_minigame_terminater::_4308) *
                       (((float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) -
                                d_minigame_terminater::_4308) *
                        (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) -
                               d_minigame_terminater::_4308)) /
                       ((float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) -
                               d_minigame_terminater::_4308) *
                       (float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) -
                              d_minigame_terminater::_4308))));
      this_00 = (fopMsgM_pane_class *)(this + iVar9 + 0x6d0);
      f_op_msg_mng::fopMsgM_paneTrans
                (this_00,(double)d_minigame_terminater::_4104,
                 (double)((float)((double)CONCAT44(0x43300000,(int)_UNK_803fb484 ^ 0x80000000) -
                                 d_minigame_terminater::_4308) +
                         (float)(dVar12 * (double)(float)((double)CONCAT44(0x43300000,
                                                                           (int)_UNK_803fb482 -
                                                                           (int)_UNK_803fb484 ^
                                                                           0x80000000) -
                                                         d_minigame_terminater::_4308))));
      f_op_msg_mng::fopMsgM_setNowAlpha(this_00,(float)dVar12);
      setRotate(this,this_00,(float)dVar11);
    }
    else {
      uVar5 = uVar5 ^ 0x80000000;
      local_98 = (double)CONCAT44(0x43300000,uVar5);
      dVar11 = (double)((float)((double)CONCAT44(0x43300000,
                                                 (int)*(short *)(this + iVar9 + 0x706) ^ 0x80000000)
                               - d_minigame_terminater::_4308) +
                       (float)((double)CONCAT44(0x43300000,
                                                (int)*(short *)(this + iVar9 + 0xd96) ^ 0x80000000)
                              - d_minigame_terminater::_4308) *
                       (((float)((double)CONCAT44(0x43300000,uVar5) - d_minigame_terminater::_4308)
                        * (float)((double)CONCAT44(0x43300000,uVar5) - d_minigame_terminater::_4308)
                        ) / ((float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) -
                                    d_minigame_terminater::_4308) *
                            (float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) -
                                   d_minigame_terminater::_4308))));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + iVar9 + 0x6d0),(double)d_minigame_terminater::_4104,
                 (double)((float)((double)CONCAT44(0x43300000,(int)_UNK_803fb482 ^ 0x80000000) -
                                 d_minigame_terminater::_4308) +
                         (d_minigame_terminater::_4336 -
                         ((float)(local_98 - d_minigame_terminater::_4308) *
                         (float)((double)CONCAT44(0x43300000,uVar5) - d_minigame_terminater::_4308))
                         / ((float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) -
                                   d_minigame_terminater::_4308) *
                           (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) -
                                  d_minigame_terminater::_4308))) *
                         (float)((double)CONCAT44(0x43300000,
                                                  (int)d_minigame_terminater::transY_4507 -
                                                  (int)_UNK_803fb482 ^ 0x80000000) -
                                d_minigame_terminater::_4308)));
      setRotate(this,(fopMsgM_pane_class *)(this + iVar9 + 0x6d0),(float)dVar11);
    }
  }
  else {
    uVar8 = 1;
  }
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  return uVar8;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x802093f8) */
/* WARNING: Removing unreachable block (ram,0x802093f0) */
/* WARNING: Removing unreachable block (ram,0x80209400) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dDlst_TerminaterScrnDraw_c::animeS1(void) */

bool __thiscall dDlst_TerminaterScrnDraw_c::animeS1(dDlst_TerminaterScrnDraw_c *this)

{
  bool bVar1;
  short sVar2;
  float fVar3;
  uint uVar4;
  dDlst_TerminaterScrnDraw_c *pdVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined8 in_f29;
  double dVar10;
  undefined8 in_f30;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  dVar12 = (double)((*(float *)(this + 0xa8c) +
                    *(float *)(this + 0xbc4) + *(float *)(this + 0xa8c) + *(float *)(this + 0xba4))
                   * d_minigame_terminater::_4305);
  sVar2 = *(short *)(this + 0xabe);
  bVar1 = _UNK_803fb48e <= sVar2;
  if (!bVar1) {
    *(short *)(this + 0xabe) = sVar2 + 1;
  }
  uVar4 = SEXT24(*(short *)(this + 0xabe));
  uVar6 = SEXT24(d_minigame_terminater::animeFrame_4573);
  if ((int)uVar6 < (int)uVar4) {
    uVar4 = uVar4 - uVar6 ^ 0x80000000;
    uVar6 = (int)_UNK_803fb48e - uVar6 ^ 0x80000000;
    dVar11 = (double)(((float)((double)CONCAT44(0x43300000,uVar4) - d_minigame_terminater::_4308) *
                      (float)((double)CONCAT44(0x43300000,uVar4) - d_minigame_terminater::_4308)) /
                     ((float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_terminater::_4308) *
                     (float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_terminater::_4308)));
    fVar3 = d_minigame_terminater::_4611 + (float)((double)d_minigame_terminater::_4612 * dVar11);
  }
  else {
    dVar11 = (double)d_minigame_terminater::_4104;
    fVar3 = d_minigame_terminater::_4609 +
            d_minigame_terminater::_4610 *
            (((float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - d_minigame_terminater::_4308
                     ) *
             (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - d_minigame_terminater::_4308)
             ) / ((float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) -
                         d_minigame_terminater::_4308) *
                 (float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) -
                        d_minigame_terminater::_4308)));
  }
  dVar10 = (double)fVar3;
  iVar8 = 0;
  for (iVar7 = 0; iVar7 < d_minigame_terminater::dMgtem_yougot_tex; iVar7 = iVar7 + 1) {
    if (iVar7 == 0) {
      pdVar5 = this + iVar8;
      *(float *)(pdVar5 + 0xaa4) =
           (float)(dVar12 - (double)(float)(dVar10 * (double)(float)(dVar12 - (double)*(float *)(
                                                  pdVar5 + 0xa9c))));
      *(undefined4 *)(pdVar5 + 0xaa8) = *(undefined4 *)(pdVar5 + 0xaa0);
    }
    else {
      pdVar5 = this + iVar8;
      *(float *)(pdVar5 + 0xaa4) = (float)((double)*(float *)(pdVar5 + 0xa9c) * dVar10);
      *(float *)(pdVar5 + 0xaa8) = (float)((double)*(float *)(pdVar5 + 0xaa0) * dVar10);
    }
    pdVar5 = this + iVar8;
    *(float *)(pdVar5 + 0xab4) = (float)((double)*(float *)(pdVar5 + 0xaac) * dVar10);
    *(float *)(pdVar5 + 0xab8) = (float)((double)*(float *)(pdVar5 + 0xab0) * dVar10);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar5 + 0xa88));
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar5 + 0xa88),(float)dVar11);
    iVar8 = iVar8 + 0x38;
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  __psq_l0(auStack40,uVar9);
  __psq_l1(auStack40,uVar9);
  return bVar1;
}


/* __thiscall dDlst_TerminaterScrnDraw_c::animeS2(fopMsgM_pane_class *) */

bool __thiscall
dDlst_TerminaterScrnDraw_c::animeS2(dDlst_TerminaterScrnDraw_c *this,fopMsgM_pane_class *param_1)

{
  uint uVar1;
  
  param_1->mUserData = param_1->mUserData + 1;
  uVar1 = SEXT24(param_1->mUserData);
  if (7 >= (int)uVar1) {
    f_op_msg_mng::fopMsgM_setNowAlpha
              (param_1,((float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) -
                               d_minigame_terminater::_4308) *
                       (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) -
                              d_minigame_terminater::_4308)) / d_minigame_terminater::_4630);
  }
  return 7 < (int)uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80209a8c) */
/* __thiscall dDlst_TerminaterScrnDraw_c::animeS3(void) */

undefined4 __thiscall dDlst_TerminaterScrnDraw_c::animeS3(dDlst_TerminaterScrnDraw_c *this)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 in_f31;
  double dVar10;
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar8 = 0;
  iVar3 = (int)DAT_80361c30;
  if (*(short *)(this + 0x1966) < iVar3) {
    *(short *)(this + 0x1966) = *(short *)(this + 0x1966) + 1;
    uVar2 = SEXT24(*(short *)(this + 0x1966));
    uVar5 = SEXT24(d_minigame_terminater::animeFrame_4636);
    if ((int)uVar5 < (int)uVar2) {
      iVar7 = (int)DAT_80361c2a;
      if (iVar7 < (int)uVar2) {
        iVar6 = (int)DAT_80361c2c;
        if (iVar6 < (int)uVar2) {
          iVar7 = (int)DAT_80361c2e;
          if (iVar7 < (int)uVar2) {
            if ((int)uVar2 <= iVar3) {
              uVar2 = uVar2 - iVar7 ^ 0x80000000;
              uVar5 = iVar3 - iVar7 ^ 0x80000000;
              f_op_msg_mng::fopMsgM_paneTrans
                        ((fopMsgM_pane_class *)(this + 0x1930),(double)d_minigame_terminater::_4104,
                         (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c3e ^ 0x80000000
                                                          ) - d_minigame_terminater::_4308) +
                                 (d_minigame_terminater::_4336 -
                                 ((float)((double)CONCAT44(0x43300000,uVar2) -
                                         d_minigame_terminater::_4308) *
                                 (float)((double)CONCAT44(0x43300000,uVar2) -
                                        d_minigame_terminater::_4308)) /
                                 ((float)((double)CONCAT44(0x43300000,uVar5) -
                                         d_minigame_terminater::_4308) *
                                 (float)((double)CONCAT44(0x43300000,uVar5) -
                                        d_minigame_terminater::_4308))) *
                                 (float)((double)CONCAT44(0x43300000,
                                                          (int)DAT_80361c3c - (int)DAT_80361c3e ^
                                                          0x80000000) - d_minigame_terminater::_4308
                                        )));
            }
          }
          else {
            uVar2 = uVar2 - iVar6 ^ 0x80000000;
            uVar5 = iVar7 - iVar6 ^ 0x80000000;
            fVar1 = d_minigame_terminater::_4336 -
                    ((float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308) *
                    (float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308)) /
                    ((float)((double)CONCAT44(0x43300000,uVar5) - d_minigame_terminater::_4308) *
                    (float)((double)CONCAT44(0x43300000,uVar5) - d_minigame_terminater::_4308));
            dVar10 = (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c48 ^ 0x80000000) -
                                     d_minigame_terminater::_4308) +
                             fVar1 * (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_80361c46 - (int)DAT_80361c48
                                                              ^ 0x80000000) -
                                            d_minigame_terminater::_4308));
            f_op_msg_mng::fopMsgM_paneTrans
                      ((fopMsgM_pane_class *)(this + 0x1930),(double)d_minigame_terminater::_4104,
                       (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c3c ^ 0x80000000)
                                       - d_minigame_terminater::_4308) +
                               fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                (int)DAT_80361c3a -
                                                                (int)DAT_80361c3c ^ 0x80000000) -
                                              d_minigame_terminater::_4308)));
            fVar1 = d_minigame_terminater::_4104;
            piVar4 = *(int **)(this + 0x1930);
            piVar4[0x27] = (int)d_minigame_terminater::_4104;
            piVar4[0x28] = (int)fVar1;
            *(undefined *)(piVar4 + 0x2a) = 0x7a;
            piVar4[0x29] = (int)(float)dVar10;
            (**(code **)(*piVar4 + 0x20))();
          }
        }
        else {
          uVar2 = uVar2 - iVar7 ^ 0x80000000;
          uVar5 = iVar6 - iVar7 ^ 0x80000000;
          fVar1 = d_minigame_terminater::_4336 -
                  ((float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308) *
                  (float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308)) /
                  ((float)((double)CONCAT44(0x43300000,uVar5) - d_minigame_terminater::_4308) *
                  (float)((double)CONCAT44(0x43300000,uVar5) - d_minigame_terminater::_4308));
          dVar10 = (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c46 ^ 0x80000000) -
                                   d_minigame_terminater::_4308) +
                           fVar1 * (float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_80361c44 - (int)DAT_80361c46 ^
                                                            0x80000000) -
                                          d_minigame_terminater::_4308));
          f_op_msg_mng::fopMsgM_paneTrans
                    ((fopMsgM_pane_class *)(this + 0x1930),(double)d_minigame_terminater::_4104,
                     (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c3a ^ 0x80000000) -
                                     d_minigame_terminater::_4308) +
                             fVar1 * (float)((double)CONCAT44(0x43300000,
                                                              (int)DAT_80361c38 - (int)DAT_80361c3a
                                                              ^ 0x80000000) -
                                            d_minigame_terminater::_4308)));
          fVar1 = d_minigame_terminater::_4104;
          piVar4 = *(int **)(this + 0x1930);
          piVar4[0x27] = (int)d_minigame_terminater::_4104;
          piVar4[0x28] = (int)fVar1;
          *(undefined *)(piVar4 + 0x2a) = 0x7a;
          piVar4[0x29] = (int)(float)dVar10;
          (**(code **)(*piVar4 + 0x20))();
        }
      }
      else {
        uVar2 = uVar2 - uVar5 ^ 0x80000000;
        uVar5 = iVar7 - uVar5 ^ 0x80000000;
        fVar1 = d_minigame_terminater::_4336 -
                ((float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308) *
                (float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_terminater::_4308)) /
                ((float)((double)CONCAT44(0x43300000,uVar5) - d_minigame_terminater::_4308) *
                (float)((double)CONCAT44(0x43300000,uVar5) - d_minigame_terminater::_4308));
        dVar10 = (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c44 ^ 0x80000000) -
                                 d_minigame_terminater::_4308) +
                         fVar1 * (float)((double)CONCAT44(0x43300000,
                                                          (int)DAT_80361c42 - (int)DAT_80361c44 ^
                                                          0x80000000) - d_minigame_terminater::_4308
                                        ));
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0x1930),(double)d_minigame_terminater::_4104,
                   (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c38 ^ 0x80000000) -
                                   d_minigame_terminater::_4308) +
                           fVar1 * (float)((double)CONCAT44(0x43300000,
                                                            (int)DAT_80361c36 - (int)DAT_80361c38 ^
                                                            0x80000000) -
                                          d_minigame_terminater::_4308)));
        fVar1 = d_minigame_terminater::_4104;
        piVar4 = *(int **)(this + 0x1930);
        piVar4[0x27] = (int)d_minigame_terminater::_4104;
        piVar4[0x28] = (int)fVar1;
        *(undefined *)(piVar4 + 0x2a) = 0x7a;
        piVar4[0x29] = (int)(float)dVar10;
        (**(code **)(*piVar4 + 0x20))();
      }
    }
    else {
      dVar10 = (double)(((float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) -
                                d_minigame_terminater::_4308) *
                        (float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) -
                               d_minigame_terminater::_4308)) /
                       ((float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) -
                               d_minigame_terminater::_4308) *
                       (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) -
                              d_minigame_terminater::_4308)));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x1930),(double)d_minigame_terminater::_4104,
                 (double)((float)((double)CONCAT44(0x43300000,(int)DAT_80361c36 ^ 0x80000000) -
                                 d_minigame_terminater::_4308) +
                         (float)((double)d_minigame_terminater::_4336 - dVar10) *
                         (float)((double)CONCAT44(0x43300000,
                                                  (int)d_minigame_terminater::transY_4637 -
                                                  (int)DAT_80361c36 ^ 0x80000000) -
                                d_minigame_terminater::_4308)));
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1850),(float)dVar10);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x1888),(float)dVar10);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x18c0),(float)dVar10);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x18f8),(float)dVar10);
      if (*(short *)(this + 0x1966) == d_minigame_terminater::animeFrame_4636) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x849,(cXyz *)0x0,0,0,d_minigame_terminater::_4336,
                   d_minigame_terminater::_4336,d_minigame_terminater::_4730,
                   d_minigame_terminater::_4730,0);
      }
    }
  }
  else {
    uVar8 = 1;
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  return uVar8;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDlst_TerminaterScrnDraw_c::animeFailed1(void) */

undefined4 __thiscall dDlst_TerminaterScrnDraw_c::animeFailed1(dDlst_TerminaterScrnDraw_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = 0; iVar1 < d_minigame_terminater::dMgtem_failed_tex; iVar1 = iVar1 + 1) {
    if (iVar1 < d_minigame_terminater::dMgtem_failed_tex + -1) {
      if ((iVar2 <= *(short *)(this + 0x1980)) && ((int)*(short *)(this + 0x1980) < iVar2 + 0x1a)) {
        animeF1(this,iVar1);
      }
    }
    else {
      if ((iVar2 <= *(short *)(this + 0x1980)) && ((int)*(short *)(this + 0x1980) < iVar2 + 0x2c)) {
        animeF2(this,iVar1);
      }
    }
    iVar2 = iVar2 + 3;
  }
  *(short *)(this + 0x1980) = *(short *)(this + 0x1980) + 1;
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDlst_TerminaterScrnDraw_c::animeFailed2(void) */

undefined4 __thiscall dDlst_TerminaterScrnDraw_c::animeFailed2(dDlst_TerminaterScrnDraw_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = 0; iVar1 < d_minigame_terminater::dMgtem_failed_tex; iVar1 = iVar1 + 1) {
    if ((iVar2 <= *(short *)(this + 0x1982)) && ((int)*(short *)(this + 0x1982) < iVar2 + 10)) {
      animeF3(this,(d_minigame_terminater::dMgtem_failed_tex + -1) - iVar1);
    }
    iVar2 = iVar2 + 3;
  }
  *(short *)(this + 0x1982) = *(short *)(this + 0x1982) + 1;
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDlst_TerminaterScrnDraw_c::animeSuccess(void) */

undefined4 __thiscall dDlst_TerminaterScrnDraw_c::animeSuccess(dDlst_TerminaterScrnDraw_c *this)

{
  int iVar1;
  
  if (*(short *)(this + 0x1982) < 0xb) {
    if (*(short *)(this + 0x1982) == 0) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x848,(cXyz *)0x0,0,0,d_minigame_terminater::_4336,
                 d_minigame_terminater::_4336,d_minigame_terminater::_4730,
                 d_minigame_terminater::_4730,0);
    }
    animeS1(this);
  }
  if (*(short *)(this + 0x1982) < 0x14) {
    for (iVar1 = 0; iVar1 < d_minigame_terminater::dMgtem_remain_tex; iVar1 = iVar1 + 1) {
      if ((iVar1 <= *(short *)(this + 0x1982)) && ((int)*(short *)(this + 0x1982) < iVar1 + 7)) {
        animeS2(this,(fopMsgM_pane_class *)
                     (this + ((d_minigame_terminater::dMgtem_remain_tex + -1) - iVar1) * 0x38 +
                             0xd60));
        animeS2(this,(fopMsgM_pane_class *)
                     (this + ((d_minigame_terminater::dMgtem_remain_tex + -1) - iVar1) * 0x38 +
                             0x1118));
      }
    }
  }
  if ((1 < *(short *)(this + 0x1982)) && (*(short *)(this + 0x1982) < 0x14)) {
    iVar1 = 0;
    do {
      if ((iVar1 + 2 <= (int)*(short *)(this + 0x1982)) &&
         ((int)*(short *)(this + 0x1982) < iVar1 + 9)) {
        animeS2(this,(fopMsgM_pane_class *)(this + (7 - iVar1) * 0x38 + 0x14d0));
        animeS2(this,(fopMsgM_pane_class *)(this + (7 - iVar1) * 0x38 + 0x1690));
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
  }
  if ((0x12 < *(short *)(this + 0x1982)) && (*(short *)(this + 0x1982) < 0x21)) {
    animeS3(this);
  }
  *(short *)(this + 0x1982) = *(short *)(this + 0x1982) + 1;
  return 0;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x8020a4b0) */
/* WARNING: Removing unreachable block (ram,0x8020a4a8) */
/* WARNING: Removing unreachable block (ram,0x8020a4b8) */
/* __thiscall dDlst_TerminaterScrnDraw_c::animePerfect(void) */

undefined4 __thiscall dDlst_TerminaterScrnDraw_c::animePerfect(dDlst_TerminaterScrnDraw_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  short sVar4;
  float fVar5;
  short sVar7;
  undefined4 uVar6;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  bool bVar13;
  undefined4 uVar14;
  undefined8 in_f29;
  double dVar15;
  undefined8 in_f30;
  double dVar16;
  undefined8 in_f31;
  double dVar17;
  undefined local_c8;
  undefined uStack199;
  undefined uStack198;
  undefined uStack197;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a0;
  uint uStack156;
  undefined4 local_98;
  uint uStack148;
  undefined4 local_90;
  uint uStack140;
  undefined4 local_88;
  uint uStack132;
  undefined4 local_80;
  uint uStack124;
  undefined4 local_78;
  uint uStack116;
  double local_70;
  undefined4 local_68;
  uint uStack100;
  undefined4 local_60;
  uint uStack92;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  sVar4 = DAT_803e6b10;
  uVar14 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  local_c4 = 0xffffffff;
  local_c0 = 0xffffffff;
  local_bc = 0xffffffff;
  local_b8 = 0xffffffff;
  local_b4 = 0xffffffff;
  local_b0 = 0xffffffff;
  local_ac = 0xffffffff;
  local_a8 = 0xffffffff;
  uStack100 = SEXT24(DAT_803e6b1a);
  uStack140 = SEXT24(DAT_803e6b10);
  iVar12 = (int)(short)(DAT_803e6b10 + DAT_803e6b12);
  sVar7 = DAT_803e6b10 + DAT_803e6b12 + DAT_803e6b14;
  iVar11 = (int)sVar7;
  sVar7 = sVar7 + DAT_803e6b16;
  iVar10 = (int)sVar7;
  sVar7 = sVar7 + DAT_803e6b18;
  iVar9 = (int)sVar7;
  if (DAT_803e6b1c + 0x20 < (int)*(short *)(this + 0x1982)) {
    if (*(short *)(this + 0x1984) == 0) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x860,(cXyz *)0x0,0,0,d_minigame_terminater::_4336,
                 d_minigame_terminater::_4336,d_minigame_terminater::_4730,
                 d_minigame_terminater::_4730,0);
    }
    *(short *)(this + 0x1984) = *(short *)(this + 0x1984) + 1;
    uStack156 = SEXT24(*(short *)(this + 0x1984));
    if ((int)uStack140 < (int)uStack156) {
      if (iVar12 < (int)uStack156) {
        if (iVar11 < (int)uStack156) {
          if (iVar10 < (int)uStack156) {
            if (iVar9 < (int)uStack156) {
              if ((int)(short)(sVar7 + (short)(uStack100 << 1)) <= (int)uStack156) {
                *(short *)(this + 0x1984) = sVar7;
              }
              fVar5 = d_minigame_terminater::_4959;
              fVar2 = d_minigame_terminater::_4958;
              uStack92 = *(short *)(this + 0x1984) - iVar9 ^ 0x80000000;
              local_60 = 0x43300000;
              uStack100 = uStack100 ^ 0x80000000;
              local_68 = 0x43300000;
              fVar1 = d_minigame_terminater::_4959 +
                      d_minigame_terminater::_4960 *
                      ((float)((double)CONCAT44(0x43300000,uStack92) - d_minigame_terminater::_4308)
                      / (float)((double)CONCAT44(0x43300000,uStack100) -
                               d_minigame_terminater::_4308));
              bVar13 = d_minigame_terminater::_4959 < fVar1;
              if (bVar13) {
                fVar1 = d_minigame_terminater::_4106 - fVar1;
              }
              iVar9 = 0;
              iVar10 = 0;
              for (uVar8 = 0; (int)uVar8 < (int)d_minigame_terminater::dMgtem_perfect_tex;
                  uVar8 = uVar8 + 1) {
                if (bVar13) {
                  uStack92 = uVar8 ^ 0x80000000;
                  local_60 = 0x43300000;
                  fVar3 = fVar1 - d_minigame_terminater::_4961 *
                                  (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) -
                                         d_minigame_terminater::_4308);
                }
                else {
                  uStack100 = uVar8 ^ 0x80000000;
                  local_68 = 0x43300000;
                  fVar3 = fVar1 + d_minigame_terminater::_4961 *
                                  (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) -
                                         d_minigame_terminater::_4308);
                }
                if (fVar5 < fVar3) {
                  fVar3 = d_minigame_terminater::_4106 - fVar3;
                }
                if (fVar3 < fVar2) {
                  fVar3 = d_minigame_terminater::_4962 - fVar3;
                }
                *(undefined *)(undefined4 *)((int)&local_c4 + iVar10) = 0xff;
                local_70 = (double)(longlong)(int)fVar3;
                *(char *)((int)&local_c4 + iVar10 + 1) = (char)(int)fVar3;
                *(undefined *)((int)&local_c4 + iVar10 + 2) = 0;
                *(undefined *)((int)&local_c4 + iVar10 + 3) = 0xff;
                uVar6 = *(undefined4 *)((int)&local_c4 + iVar10);
                iVar11 = *(int *)(this + iVar9 + 8);
                local_c8 = (undefined)((uint)uVar6 >> 0x18);
                *(undefined *)(iVar11 + 0x104) = local_c8;
                uStack199 = (undefined)((uint)uVar6 >> 0x10);
                *(undefined *)(iVar11 + 0x105) = uStack199;
                uStack198 = (undefined)((uint)uVar6 >> 8);
                *(undefined *)(iVar11 + 0x106) = uStack198;
                uStack197 = (undefined)uVar6;
                *(undefined *)(iVar11 + 0x107) = uStack197;
                iVar9 = iVar9 + 0x38;
                iVar10 = iVar10 + 4;
              }
            }
            else {
              uStack100 = uStack156 - iVar10 ^ 0x80000000;
              local_60 = 0x43300000;
              local_68 = 0x43300000;
              uStack116 = iVar9 - iVar10 ^ 0x80000000;
              local_70 = (double)CONCAT44(0x43300000,uStack116);
              local_78 = 0x43300000;
              uStack124 = (int)DAT_80361c54 ^ 0x80000000;
              local_80 = 0x43300000;
              uStack132 = (int)DAT_80361c56 - (int)DAT_80361c54 ^ 0x80000000;
              local_88 = 0x43300000;
              uStack92 = uStack100;
              setRotate(this,(fopMsgM_pane_class *)(this + 0x698),
                        (float)((double)CONCAT44(0x43300000,uStack124) -
                               d_minigame_terminater::_4308) +
                        (((float)((double)CONCAT44(0x43300000,uStack100) -
                                 d_minigame_terminater::_4308) *
                         (float)((double)CONCAT44(0x43300000,uStack100) -
                                d_minigame_terminater::_4308)) /
                        ((float)(local_70 - d_minigame_terminater::_4308) *
                        (float)((double)CONCAT44(0x43300000,uStack116) -
                               d_minigame_terminater::_4308))) *
                        (float)((double)CONCAT44(0x43300000,uStack132) -
                               d_minigame_terminater::_4308));
            }
          }
          else {
            uStack100 = uStack156 - iVar11 ^ 0x80000000;
            local_60 = 0x43300000;
            local_68 = 0x43300000;
            uStack116 = iVar10 - iVar11 ^ 0x80000000;
            local_70 = (double)CONCAT44(0x43300000,uStack116);
            local_78 = 0x43300000;
            uStack124 = (int)DAT_80361c52 ^ 0x80000000;
            local_80 = 0x43300000;
            uStack132 = (int)DAT_80361c54 - (int)DAT_80361c52 ^ 0x80000000;
            local_88 = 0x43300000;
            uStack92 = uStack100;
            setRotate(this,(fopMsgM_pane_class *)(this + 0x698),
                      (float)((double)CONCAT44(0x43300000,uStack124) - d_minigame_terminater::_4308)
                      + (((float)((double)CONCAT44(0x43300000,uStack100) -
                                 d_minigame_terminater::_4308) *
                         (float)((double)CONCAT44(0x43300000,uStack100) -
                                d_minigame_terminater::_4308)) /
                        ((float)(local_70 - d_minigame_terminater::_4308) *
                        (float)((double)CONCAT44(0x43300000,uStack116) -
                               d_minigame_terminater::_4308))) *
                        (float)((double)CONCAT44(0x43300000,uStack132) -
                               d_minigame_terminater::_4308));
          }
        }
        else {
          uStack100 = uStack156 - iVar12 ^ 0x80000000;
          local_60 = 0x43300000;
          local_68 = 0x43300000;
          uStack116 = iVar11 - iVar12 ^ 0x80000000;
          local_70 = (double)CONCAT44(0x43300000,uStack116);
          local_78 = 0x43300000;
          uStack124 = (int)DAT_80361c50 ^ 0x80000000;
          local_80 = 0x43300000;
          uStack132 = (int)DAT_80361c52 - (int)DAT_80361c50 ^ 0x80000000;
          local_88 = 0x43300000;
          uStack92 = uStack100;
          setRotate(this,(fopMsgM_pane_class *)(this + 0x698),
                    (float)((double)CONCAT44(0x43300000,uStack124) - d_minigame_terminater::_4308) +
                    (((float)((double)CONCAT44(0x43300000,uStack100) - d_minigame_terminater::_4308)
                     * (float)((double)CONCAT44(0x43300000,uStack100) - d_minigame_terminater::_4308
                              )) /
                    ((float)(local_70 - d_minigame_terminater::_4308) *
                    (float)((double)CONCAT44(0x43300000,uStack116) - d_minigame_terminater::_4308)))
                    * (float)((double)CONCAT44(0x43300000,uStack132) - d_minigame_terminater::_4308)
                   );
        }
      }
      else {
        uStack100 = uStack156 - uStack140 ^ 0x80000000;
        local_60 = 0x43300000;
        local_68 = 0x43300000;
        uStack116 = iVar12 - uStack140 ^ 0x80000000;
        local_70 = (double)CONCAT44(0x43300000,uStack116);
        local_78 = 0x43300000;
        uStack124 = (int)DAT_80361c4e ^ 0x80000000;
        local_80 = 0x43300000;
        uStack132 = (int)DAT_80361c50 - (int)DAT_80361c4e ^ 0x80000000;
        local_88 = 0x43300000;
        uStack92 = uStack100;
        setRotate(this,(fopMsgM_pane_class *)(this + 0x698),
                  (float)((double)CONCAT44(0x43300000,uStack124) - d_minigame_terminater::_4308) +
                  (((float)((double)CONCAT44(0x43300000,uStack100) - d_minigame_terminater::_4308) *
                   (float)((double)CONCAT44(0x43300000,uStack100) - d_minigame_terminater::_4308)) /
                  ((float)(local_70 - d_minigame_terminater::_4308) *
                  (float)((double)CONCAT44(0x43300000,uStack116) - d_minigame_terminater::_4308))) *
                  (float)((double)CONCAT44(0x43300000,uStack132) - d_minigame_terminater::_4308));
      }
    }
    else {
      uStack156 = uStack156 ^ 0x80000000;
      local_a0 = 0x43300000;
      local_98 = 0x43300000;
      uStack140 = uStack140 ^ 0x80000000;
      local_90 = 0x43300000;
      local_88 = 0x43300000;
      fVar2 = (float)((double)CONCAT44(0x43300000,uStack140) - d_minigame_terminater::_4308) *
              (float)((double)CONCAT44(0x43300000,uStack140) - d_minigame_terminater::_4308);
      fVar1 = ((float)((double)CONCAT44(0x43300000,uStack156) - d_minigame_terminater::_4308) *
              (float)((double)CONCAT44(0x43300000,uStack156) - d_minigame_terminater::_4308)) /
              fVar2;
      dVar17 = (double)fVar1;
      uStack124 = (int)d_minigame_terminater::rot_4821 ^ 0x80000000;
      local_80 = 0x43300000;
      uStack116 = (int)DAT_80361c4e - (int)d_minigame_terminater::rot_4821 ^ 0x80000000;
      local_78 = 0x43300000;
      dVar16 = (double)((float)((double)CONCAT44(0x43300000,uStack124) -
                               d_minigame_terminater::_4308) +
                       (float)(dVar17 * (double)(float)((double)CONCAT44(0x43300000,uStack116) -
                                                       d_minigame_terminater::_4308)));
      uStack100 = (int)(short)(sVar4 - *(short *)(this + 0x1984)) ^ 0x80000000;
      local_70 = (double)CONCAT44(0x43300000,uStack100);
      local_68 = 0x43300000;
      uStack92 = (int)DAT_803e6afa ^ 0x80000000;
      local_60 = 0x43300000;
      dVar15 = (double)(d_minigame_terminater::_4336 +
                       ((float)((double)CONCAT44(0x43300000,uStack92) - d_minigame_terminater::_4308
                               ) / d_minigame_terminater::_4958 - d_minigame_terminater::_4336) *
                       (((float)(local_70 - d_minigame_terminater::_4308) *
                        (float)((double)CONCAT44(0x43300000,uStack100) -
                               d_minigame_terminater::_4308)) / fVar2));
      uStack148 = uStack156;
      uStack132 = uStack140;
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 8),fVar1);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x238),(float)dVar17);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x468),(float)dVar17);
      setRotate(this,(fopMsgM_pane_class *)(this + 0x698),(float)dVar16);
      iVar10 = 0;
      for (iVar9 = 0; iVar9 < d_minigame_terminater::dMgtem_perfect_tex; iVar9 = iVar9 + 1) {
        setScale(this,(fopMsgM_pane_class *)(this + iVar10 + 8),(float)dVar15);
        iVar10 = iVar10 + 0x38;
      }
      iVar10 = 0;
      iVar9 = 0;
      do {
        setScale(this,(fopMsgM_pane_class *)(this + iVar9 + 0x238),(float)dVar15);
        setScale(this,(fopMsgM_pane_class *)(this + iVar9 + 0x468),(float)dVar15);
        iVar10 = iVar10 + 1;
        iVar9 = iVar9 + 0x38;
      } while (iVar10 < 10);
    }
  }
  __psq_l0(auStack8,uVar14);
  __psq_l1(auStack8,uVar14);
  __psq_l0(auStack24,uVar14);
  __psq_l1(auStack24,uVar14);
  __psq_l0(auStack40,uVar14);
  __psq_l1(auStack40,uVar14);
  return 0;
}


/* __thiscall dDlst_TerminaterScrnDraw_c::draw(void) */

void __thiscall dDlst_TerminaterScrnDraw_c::draw(dDlst_TerminaterScrnDraw_c *this)

{
  J2DOrthoGraph *pCtx;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_minigame_terminater::_4104,
                  d_minigame_terminater::_4104,&pCtx->parent);
  return;
}


namespace d_minigame_terminater {

/* __stdcall dMinigame_Terminater_Draw(dMinigame_Terminater_c *) */

void dMinigame_Terminater_Draw(dMinigame_Terminater_c *param_1)

{
  ::dMinigame_Terminater_c::_draw(param_1);
  return;
}


/* __stdcall dMinigame_Terminater_Execute(dMinigame_Terminater_c *) */

void dMinigame_Terminater_Execute(dMinigame_Terminater_c *param_1)

{
  ::dMinigame_Terminater_c::_execute(param_1);
  return;
}


/* __stdcall dMinigame_Terminater_IsDelete(dMinigame_Terminater_c *) */

undefined4 dMinigame_Terminater_IsDelete(void)

{
  return 1;
}


/* __stdcall dMinigame_Terminater_Delete(dMinigame_Terminater_c *) */

void dMinigame_Terminater_Delete(dMinigame_Terminater_c *param_1)

{
  ::dMinigame_Terminater_c::_delete(param_1);
  return;
}


/* __stdcall dMinigame_Terminater_Create(msg_class *) */

void dMinigame_Terminater_Create(dMinigame_Terminater_c *param_1)

{
  ::dMinigame_Terminater_c::_create(param_1);
  return;
}

}

/* __thiscall dDlst_TerminaterScrnDraw_c::~dDlst_TerminaterScrnDraw_c(void) */

void __thiscall
dDlst_TerminaterScrnDraw_c::_dDlst_TerminaterScrnDraw_c(dDlst_TerminaterScrnDraw_c *this)

{
  short in_r4;
  
  if (this != (dDlst_TerminaterScrnDraw_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_TerminaterScrnDraw_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

