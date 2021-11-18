#include <d_minigame_starter.h>
#include <d_com_inf_game.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <m_Do_ext.h>
#include <JKernel/JKRHeap.h>
#include <d_minigame_starter.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_drawlist.h>
#include <J2DGraph/J2DPane.h>
#include <J2DGraph/J2DScreen.h>
#include <f_op_msg_mng.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <dDlst_StarterScrnDraw_c.h>
#include <dMinigame_Starter_c.h>


namespace d_minigame_starter {
}

namespace d_minigame_starter {
}

/* __thiscall dMinigame_Starter_c::_create(void) */

PhaseState __thiscall dMinigame_Starter_c::_create(dMinigame_Starter_c *this)

{
  PhaseState PVar1;
  dRes_info_c *pdVar2;
  ulong uVar3;
  JKRSolidHeap *pJVar4;
  undefined **ppuVar5;
  
  PVar1 = d_com_inf_game::dComIfG_resLoad((request_of_phase_process_class *)(this + 0x100),"Mgst");
  if (PVar1 == cPhs_COMPLEATE_e) {
    pdVar2 = dRes_control_c::getResInfo
                       ("Mgst",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pdVar2 == (dRes_info_c *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_minigame_starter.cpp",0x56,"resInfo != 0");
      m_Do_printf::OSPanic("d_minigame_starter.cpp",0x56,&DAT_803619b9);
    }
    pJVar4 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(0x14c0,0x20);
    *(JKRSolidHeap **)(this + 0x108) = pJVar4;
    if (*(int *)(this + 0x108) == 0) {
      PVar1 = cPhs_ERROR_e;
    }
    else {
      ppuVar5 = (undefined **)JKernel::operator_new(0x318);
      if (ppuVar5 != (undefined **)0x0) {
        *ppuVar5 = (undefined *)&dDlst_base_c::__vt;
        *ppuVar5 = &dDlst_StarterScrnDraw_c::__vt;
      }
      *(undefined ***)(this + 0xfc) = ppuVar5;
      dDlst_StarterScrnDraw_c::setScreen
                (*(dDlst_StarterScrnDraw_c **)(this + 0xfc),"ship_race1.blo",pdVar2->mpArchive);
      m_Do_ext::mDoExt_restoreCurrentHeap();
      m_Do_ext::mDoExt_adjustSolidHeap(*(JKRSolidHeap **)(this + 0x108));
      this[0x111] = (dMinigame_Starter_c)0x0;
      *(undefined2 *)(this + 0x10c) = 0;
      *(undefined2 *)(this + 0x10e) = 3;
      PVar1 = cPhs_COMPLEATE_e;
    }
  }
  return PVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMinigame_Starter_c::_execute(void) */

undefined4 __thiscall dMinigame_Starter_c::_execute(dMinigame_Starter_c *this)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = (int)d_minigame_starter::cdFrame0 +
          (int)d_minigame_starter::cdFrame1 + (int)d_minigame_starter::tmFrame +
          (int)d_minigame_starter::cdFrame2 + (int)d_minigame_starter::cdFrame3 + -0x1e;
  iVar3 = (int)d_minigame_starter::cdFrame4 +
          (int)d_minigame_starter::cdFrame5 + (int)d_minigame_starter::cdFrame6 +
          (int)d_minigame_starter::cdFrame7 + (int)d_minigame_starter::cdFrame8 + -0x17;
  if (this[0x111] == (dMinigame_Starter_c)0x0) {
    uVar1 = 0;
  }
  else {
    iVar5 = iVar4 * 3;
    iVar2 = iVar5 + iVar3;
    if ((int)*(short *)(this + 0x10c) < iVar2 + 0x89) {
      *(short *)(this + 0x10c) = *(short *)(this + 0x10c) + 1;
      if (iVar2 + 0x59 <= (int)*(short *)(this + 0x10c)) {
        this[0x111] = (dMinigame_Starter_c)0x2;
      }
    }
    else {
      this[0x111] = (dMinigame_Starter_c)0x3;
    }
    if ((int)*(short *)(this + 0x10c) <= iVar4 + 0x1e) {
      dDlst_StarterScrnDraw_c::anime1(*(dDlst_StarterScrnDraw_c **)(this + 0xfc),2);
    }
    if ((iVar4 + 0x1c <= (int)*(short *)(this + 0x10c)) &&
       ((int)*(short *)(this + 0x10c) <= iVar4 * 2 + 0x39)) {
      dDlst_StarterScrnDraw_c::anime1(*(dDlst_StarterScrnDraw_c **)(this + 0xfc),1);
    }
    if ((iVar4 * 2 + 0x37 <= (int)*(short *)(this + 0x10c)) &&
       ((int)*(short *)(this + 0x10c) <= iVar5 + 0x54)) {
      dDlst_StarterScrnDraw_c::anime1(*(dDlst_StarterScrnDraw_c **)(this + 0xfc),0);
    }
    if ((iVar5 + 0x54 <= (int)*(short *)(this + 0x10c)) &&
       ((int)*(short *)(this + 0x10c) <= iVar5 + iVar3 + 0x6b)) {
      dDlst_StarterScrnDraw_c::anime2(*(dDlst_StarterScrnDraw_c **)(this + 0xfc));
    }
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall dMinigame_Starter_c::_draw(void) */

undefined4 __thiscall dMinigame_Starter_c::_draw(dMinigame_Starter_c *this)

{
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(this + 0xfc));
  return 1;
}


/* __thiscall dMinigame_Starter_c::_delete(void) */

undefined4 __thiscall dMinigame_Starter_c::_delete(dMinigame_Starter_c *this)

{
  if (*(int *)(this + 0x108) != 0) {
    m_Do_ext::mDoExt_destroySolidHeap();
  }
  d_com_inf_game::dComIfG_resDelete((request_of_phase_process_class *)(this + 0x100),"Mgst");
  return 1;
}


/* __thiscall dMinigame_Starter_c::startCheck(void) */

undefined4 __thiscall dMinigame_Starter_c::startCheck(dMinigame_Starter_c *this)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((this[0x111] == (dMinigame_Starter_c)0x3) || (this[0x111] == (dMinigame_Starter_c)0x2)) {
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall dMinigame_Starter_c::deleteCheck(void) */

uint __thiscall dMinigame_Starter_c::deleteCheck(dMinigame_Starter_c *this)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(3 - (uint)(byte)this[0x111]);
  return uVar1 >> 5 & 0xff;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dDlst_StarterScrnDraw_c::setScreen(char const *,
                                                 JKRArchive *) */

void __thiscall
dDlst_StarterScrnDraw_c::setScreen(dDlst_StarterScrnDraw_c *this,char *param_1,JKRArchive *param_2)

{
  J2DPane *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  TBox2_float_ local_28;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_28.mTL.x = d_minigame_starter::_4092;
    local_28.mTL.y = d_minigame_starter::_4092;
    local_28.mBR.x = d_minigame_starter::_4093;
    local_28.mBR.y = d_minigame_starter::_4094;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 4) = this_00;
  J2DScreen::set(*(J2DScreen **)(this + 4),param_1,param_2);
  iVar3 = 0;
  iVar2 = 0;
  for (iVar1 = 0; iVar1 < d_minigame_starter::dMinigame_Starter_tex_number; iVar1 = iVar1 + 1) {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar2 + 8),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_minigame_starter::label_t_4075 + iVar3));
    iVar3 = iVar3 + 4;
    iVar2 = iVar2 + 0x38;
  }
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 400),*(J2DScreen **)(this + 4),0x646d676f);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x1c8),*(J2DScreen **)(this + 4),0x676f31);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x200),*(J2DScreen **)(this + 4),0x676f32);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x238),*(J2DScreen **)(this + 4),0x676f33);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x270),*(J2DScreen **)(this + 4),0x676f3132);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x2a8),*(J2DScreen **)(this + 4),0x676f3232);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x2e0),*(J2DScreen **)(this + 4),0x676f3332);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x802068e8) */
/* __thiscall dDlst_StarterScrnDraw_c::anime1(int) */

undefined4 __thiscall dDlst_StarterScrnDraw_c::anime1(dDlst_StarterScrnDraw_c *this,int param_1)

{
  float fVar1;
  short sVar3;
  uint uVar2;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  dDlst_StarterScrnDraw_c *pdVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined8 in_f31;
  double dVar13;
  undefined auStack8 [8];
  
  fVar1 = d_minigame_starter::_4177;
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar8 = 0;
  uVar10 = SEXT24(d_minigame_starter::cdFrame0);
  uVar11 = SEXT24((short)(d_minigame_starter::cdFrame0 + d_minigame_starter::cdFrame1));
  sVar3 = d_minigame_starter::cdFrame0 + d_minigame_starter::cdFrame1 + d_minigame_starter::tmFrame;
  iVar5 = (int)sVar3;
  sVar3 = sVar3 + d_minigame_starter::cdFrame2;
  iVar7 = (int)sVar3;
  iVar6 = (int)(short)(sVar3 + d_minigame_starter::cdFrame3);
  iVar4 = param_1 * 0x38;
  pdVar9 = this + iVar4;
  *(short *)(pdVar9 + 0x1fe) = *(short *)(pdVar9 + 0x1fe) + 1;
  uVar2 = SEXT24(*(short *)(pdVar9 + 0x1fe));
  if ((int)uVar10 < (int)uVar2) {
    if ((int)uVar11 < (int)uVar2) {
      if (iVar5 < (int)uVar2) {
        if (iVar7 < (int)uVar2) {
          if ((int)uVar2 < iVar6) {
            uVar2 = uVar2 - iVar7 ^ 0x80000000;
            uVar10 = iVar6 - iVar7 ^ 0x80000000;
            dVar13 = (double)((float)((double)CONCAT44(0x43300000,uVar10) -
                                     d_minigame_starter::_4185) *
                             (float)((double)CONCAT44(0x43300000,uVar10) - d_minigame_starter::_4185
                                    ));
            f_op_msg_mng::fopMsgM_paneScaleXY
                      ((fopMsgM_pane_class *)(this + iVar4 + 0x1c8),
                       d_minigame_starter::_4180 +
                       d_minigame_starter::_4182 *
                       (float)((double)((float)((double)CONCAT44(0x43300000,uVar2) -
                                               d_minigame_starter::_4185) *
                                       (float)((double)CONCAT44(0x43300000,uVar2) -
                                              d_minigame_starter::_4185)) / dVar13));
            uVar2 = *(short *)(pdVar9 + 0x1fe) - iVar7 ^ 0x80000000;
            f_op_msg_mng::fopMsgM_setNowAlpha
                      ((fopMsgM_pane_class *)(this + iVar4 + 0x1c8),
                       d_minigame_starter::_4180 -
                       (float)((double)((float)((double)CONCAT44(0x43300000,uVar2) -
                                               d_minigame_starter::_4185) *
                                       (float)((double)CONCAT44(0x43300000,uVar2) -
                                              d_minigame_starter::_4185)) / dVar13));
          }
          else {
            f_op_msg_mng::fopMsgM_paneScaleXY
                      ((fopMsgM_pane_class *)(this + iVar4 + 0x1c8),d_minigame_starter::_4183);
            f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar4 + 0x1c8));
            uVar8 = 1;
          }
        }
        else {
          uVar10 = iVar7 - iVar5;
          uVar10 = (int)(uVar2 - iVar5) /
                   (int)(((int)uVar10 >> 2) + (uint)((int)uVar10 < 0 && (uVar10 & 3) != 0));
          uVar2 = uVar10 >> 0x1f;
          if ((uVar10 & 1 ^ uVar2) != uVar2) {
            fVar1 = fVar1 * d_minigame_starter::_4181;
          }
          setRotate(this,(fopMsgM_pane_class *)(this + iVar4 + 0x1c8),fVar1);
        }
      }
    }
    else {
      uVar2 = uVar2 - uVar10 ^ 0x80000000;
      uVar10 = uVar11 - uVar10 ^ 0x80000000;
      dVar13 = (double)(((float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_starter::_4185) *
                        (float)((double)CONCAT44(0x43300000,uVar2) - d_minigame_starter::_4185)) /
                       ((float)((double)CONCAT44(0x43300000,uVar10) - d_minigame_starter::_4185) *
                       (float)((double)CONCAT44(0x43300000,uVar10) - d_minigame_starter::_4185)));
      f_op_msg_mng::fopMsgM_paneScaleXY
                ((fopMsgM_pane_class *)(pdVar9 + 0x1c8),
                 d_minigame_starter::_4178 + (float)((double)d_minigame_starter::_4179 * dVar13));
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar9 + 0x1c8),(float)dVar13);
      f_op_msg_mng::fopMsgM_paneScaleXY
                ((fopMsgM_pane_class *)(pdVar9 + 0x270),
                 d_minigame_starter::_4178 +
                 d_minigame_starter::_4179 *
                 (((float)((double)CONCAT44(0x43300000,(int)*(short *)(pdVar9 + 0x1fe) ^ 0x80000000U
                                           ) - d_minigame_starter::_4185) *
                  (float)((double)CONCAT44(0x43300000,(int)*(short *)(pdVar9 + 0x1fe) ^ 0x80000000U)
                         - d_minigame_starter::_4185)) /
                 ((float)((double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) -
                         d_minigame_starter::_4185) *
                 (float)((double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) -
                        d_minigame_starter::_4185))));
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)(pdVar9 + 0x270),
                 (float)((double)d_minigame_starter::_4180 - dVar13));
      if ((int)*(short *)(pdVar9 + 0x1fe) == uVar11) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x843,(cXyz *)0x0,0,0,d_minigame_starter::_4180,
                   d_minigame_starter::_4180,d_minigame_starter::_4181,d_minigame_starter::_4181,0);
      }
    }
  }
  else {
    f_op_msg_mng::fopMsgM_paneScaleXY
              ((fopMsgM_pane_class *)(this + iVar4 + 0x270),
               d_minigame_starter::_4178 +
               d_minigame_starter::_4179 *
               (((float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - d_minigame_starter::_4185
                        ) *
                (float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - d_minigame_starter::_4185)
                ) / ((float)((double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) -
                            d_minigame_starter::_4185) *
                    (float)((double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) -
                           d_minigame_starter::_4185))));
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)(this + iVar4 + 0x270),
               ((float)((double)CONCAT44(0x43300000,(int)*(short *)(pdVar9 + 0x1fe) ^ 0x80000000U) -
                       d_minigame_starter::_4185) *
               (float)((double)CONCAT44(0x43300000,(int)*(short *)(pdVar9 + 0x1fe) ^ 0x80000000U) -
                      d_minigame_starter::_4185)) /
               ((float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - d_minigame_starter::_4185
                       ) *
               (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - d_minigame_starter::_4185)
               ));
  }
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  return uVar8;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80206c88) */
/* WARNING: Removing unreachable block (ram,0x80206c90) */
/* __thiscall dDlst_StarterScrnDraw_c::anime2(void) */

undefined4 __thiscall dDlst_StarterScrnDraw_c::anime2(dDlst_StarterScrnDraw_c *this)

{
  short sVar2;
  uint uVar1;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  uVar8 = 0;
  uVar6 = SEXT24(d_minigame_starter::cdFrame4);
  iVar7 = (int)(short)(d_minigame_starter::cdFrame4 + d_minigame_starter::cdFrame5);
  sVar2 = d_minigame_starter::cdFrame4 + d_minigame_starter::cdFrame5 + d_minigame_starter::cdFrame6
  ;
  iVar3 = (int)sVar2;
  sVar2 = sVar2 + d_minigame_starter::cdFrame7;
  iVar4 = (int)sVar2;
  iVar5 = (int)(short)(sVar2 + d_minigame_starter::cdFrame8);
  *(short *)(this + 0x3e) = *(short *)(this + 0x3e) + 1;
  uVar1 = SEXT24(*(short *)(this + 0x3e));
  if ((int)uVar6 < (int)uVar1) {
    if (iVar7 < (int)uVar1) {
      if (iVar3 < (int)uVar1) {
        if (iVar4 < (int)uVar1) {
          if ((int)uVar1 < iVar5) {
            uVar1 = uVar1 - iVar4 ^ 0x80000000;
            uVar6 = iVar5 - iVar4 ^ 0x80000000;
            dVar11 = (double)(((float)((double)CONCAT44(0x43300000,uVar1) -
                                      d_minigame_starter::_4185) *
                              (float)((double)CONCAT44(0x43300000,uVar1) - d_minigame_starter::_4185
                                     )) /
                             ((float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_starter::_4185
                                     ) *
                             (float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_starter::_4185)
                             ));
            dVar10 = (double)(d_minigame_starter::_4266 -
                             (float)((double)d_minigame_starter::_4267 * dVar11));
            scaleAnime(this,(d_minigame_starter::_4180 -
                            (float)((double)d_minigame_starter::_4265 * dVar11)) * DAT_803e6a80);
            setRotate(this,(fopMsgM_pane_class *)(this + 400),(float)dVar10);
            f_op_msg_mng::fopMsgM_setNowAlpha
                      ((fopMsgM_pane_class *)(this + 8),
                       (float)((double)d_minigame_starter::_4180 - dVar11));
          }
          else {
            scaleAnime(this,d_minigame_starter::_4265 * DAT_803e6a80);
            setRotate(this,(fopMsgM_pane_class *)(this + 400),d_minigame_starter::_4268);
            f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 8));
            uVar8 = 1;
          }
        }
        else {
          uVar1 = uVar1 - iVar3 ^ 0x80000000;
          uVar6 = iVar4 - iVar3 ^ 0x80000000;
          setRotate(this,(fopMsgM_pane_class *)(this + 400),
                    d_minigame_starter::_4263 -
                    d_minigame_starter::_4264 *
                    (((float)((double)CONCAT44(0x43300000,uVar1) - d_minigame_starter::_4185) *
                     (float)((double)CONCAT44(0x43300000,uVar1) - d_minigame_starter::_4185)) /
                    ((float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_starter::_4185) *
                    (float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_starter::_4185))));
        }
      }
    }
    else {
      uVar1 = uVar1 - uVar6 ^ 0x80000000;
      uVar6 = iVar7 - uVar6 ^ 0x80000000;
      scaleAnime(this,(d_minigame_starter::_4261 -
                      d_minigame_starter::_4262 *
                      (((float)((double)CONCAT44(0x43300000,uVar1) - d_minigame_starter::_4185) *
                       (float)((double)CONCAT44(0x43300000,uVar1) - d_minigame_starter::_4185)) /
                      ((float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_starter::_4185) *
                      (float)((double)CONCAT44(0x43300000,uVar6) - d_minigame_starter::_4185)))) *
                      DAT_803e6a80);
      if (*(short *)(this + 0x3e) == iVar7) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x844,(cXyz *)0x0,0,0,d_minigame_starter::_4180,
                   d_minigame_starter::_4180,d_minigame_starter::_4181,d_minigame_starter::_4181,0);
      }
    }
  }
  else {
    dVar11 = (double)(((float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) -
                              d_minigame_starter::_4185) *
                      (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) -
                             d_minigame_starter::_4185)) /
                     ((float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) -
                             d_minigame_starter::_4185) *
                     (float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) -
                            d_minigame_starter::_4185)));
    dVar10 = (double)(d_minigame_starter::_4259 -
                     (float)((double)d_minigame_starter::_4260 * dVar11));
    scaleAnime(this,(d_minigame_starter::_4183 - (float)((double)d_minigame_starter::_4258 * dVar11)
                    ) * DAT_803e6a80);
    setRotate(this,(fopMsgM_pane_class *)(this + 400),(float)dVar10);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 8),(float)dVar11);
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  return uVar8;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80206d84) */
/* __thiscall dDlst_StarterScrnDraw_c::scaleAnime(float) */

void __thiscall dDlst_StarterScrnDraw_c::scaleAnime(dDlst_StarterScrnDraw_c *this,float param_1)

{
  int iVar1;
  dDlst_StarterScrnDraw_c *pdVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar5 = (double)param_1;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  *(float *)(this + 0x1bc) = (float)((double)*(float *)(this + 0x1b4) * dVar5);
  *(float *)(this + 0x1c0) = (float)((double)*(float *)(this + 0x1b8) * dVar5);
  iVar1 = 0;
  for (iVar3 = 0; iVar3 < d_minigame_starter::dMinigame_Starter_tex_number; iVar3 = iVar3 + 1) {
    pdVar2 = this + iVar1;
    *(float *)(pdVar2 + 0x34) = (float)((double)*(float *)(pdVar2 + 0x2c) * dVar5);
    *(float *)(pdVar2 + 0x38) = (float)((double)*(float *)(pdVar2 + 0x30) * dVar5);
    iVar1 = iVar1 + 0x38;
  }
  *(undefined4 *)(this + 0x1ac) = *(undefined4 *)(this + 0x1a4);
  *(undefined4 *)(this + 0x1b0) = *(undefined4 *)(this + 0x1a8);
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(this + 400));
  iVar3 = 0;
  for (iVar1 = 0; iVar1 < d_minigame_starter::dMinigame_Starter_tex_number; iVar1 = iVar1 + 1) {
    pdVar2 = this + iVar3;
    *(float *)(pdVar2 + 0x24) = (float)((double)*(float *)(pdVar2 + 0x1c) * dVar5);
    *(float *)(pdVar2 + 0x28) = (float)((double)*(float *)(pdVar2 + 0x20) * dVar5);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(pdVar2 + 8));
    iVar3 = iVar3 + 0x38;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* __thiscall dDlst_StarterScrnDraw_c::setRotate(fopMsgM_pane_class *,
                                                 float) */

void __thiscall
dDlst_StarterScrnDraw_c::setRotate
          (dDlst_StarterScrnDraw_c *this,fopMsgM_pane_class *param_1,float param_2)

{
  double dVar1;
  J2DScreen *pJVar2;
  
  dVar1 = (double)CONCAT44(0x43300000,
                           (int)((param_1->mSize).y * d_minigame_starter::_4265) ^ 0x80000000) -
          d_minigame_starter::_4185;
  pJVar2 = param_1->mpPane;
  (pJVar2->parent).mBasePosition.x =
       (float)((double)CONCAT44(0x43300000,
                                (int)((param_1->mSize).x * d_minigame_starter::_4265) ^ 0x80000000)
              - d_minigame_starter::_4185);
  (pJVar2->parent).mBasePosition.y = (float)dVar1;
  (pJVar2->parent).mRotationAxis = 'z';
  (pJVar2->parent).mRotation = param_2;
  (*(code *)((pJVar2->parent).vtbl)->calcMtx)();
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dDlst_StarterScrnDraw_c::draw(void) */

void __thiscall dDlst_StarterScrnDraw_c::draw(dDlst_StarterScrnDraw_c *this)

{
  J2DOrthoGraph *pCtx;
  int iVar1;
  int iVar2;
  
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 8));
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x1c8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x270));
    pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 3);
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_minigame_starter::_4092,d_minigame_starter::_4092,
                  &pCtx->parent);
  return;
}


namespace d_minigame_starter {

/* __stdcall dMinigame_Starter_Draw(dMinigame_Starter_c *) */

void dMinigame_Starter_Draw(dMinigame_Starter_c *param_1)

{
  ::dMinigame_Starter_c::_draw(param_1);
  return;
}


/* __stdcall dMinigame_Starter_Execute(dMinigame_Starter_c *) */

void dMinigame_Starter_Execute(dMinigame_Starter_c *param_1)

{
  ::dMinigame_Starter_c::_execute(param_1);
  return;
}


/* __stdcall dMinigame_Starter_IsDelete(dMinigame_Starter_c *) */

undefined4 dMinigame_Starter_IsDelete(void)

{
  return 1;
}


/* __stdcall dMinigame_Starter_Delete(dMinigame_Starter_c *) */

void dMinigame_Starter_Delete(dMinigame_Starter_c *param_1)

{
  ::dMinigame_Starter_c::_delete(param_1);
  return;
}


/* __stdcall dMinigame_Starter_Create(msg_class *) */

void dMinigame_Starter_Create(dMinigame_Starter_c *param_1)

{
  ::dMinigame_Starter_c::_create(param_1);
  return;
}

}

/* __thiscall dDlst_StarterScrnDraw_c::~dDlst_StarterScrnDraw_c(void) */

void __thiscall dDlst_StarterScrnDraw_c::_dDlst_StarterScrnDraw_c(dDlst_StarterScrnDraw_c *this)

{
  short in_r4;
  
  if (this != (dDlst_StarterScrnDraw_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_StarterScrnDraw_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

