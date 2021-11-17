#include <d_s_menu.h>
#include <JUtility/JUTDbPrint.h>
#include <d_save.h>
#include <m_Do_audio.h>
#include <d_com_inf_game.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <f_op_scene_mng.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <JKernel/JKRHeap.h>
#include <m_Do_dvd_thread.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JUtility/JUTResFont.h>
#include <d_com_lib_game.h>
#include <myFontClass.h>
#include <JUTResFont.h>

undefined4 d_s_menu;
undefined4 d_s_menu;
undefined4 d_s_menu;
undefined2 d_s_menu;
undefined2 d_s_menu;
undefined4 d_s_menu;
undefined1 d_s_menu;

namespace d_s_menu {

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall dScnMenu_Draw(menu_of_scene_class *) */

undefined4 dScnMenu_Draw(d_s_menu *param_1)

{
  undefined **ppuVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined **ppuVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  JKRArchive__Header *pJVar16;
  uint uVar17;
  undefined4 uStack92;
  undefined4 local_58 [6];
  undefined4 uStack64;
  undefined4 local_3c [6];
  undefined4 local_24;
  
  JUtility::JUTReport(300,0x32,"メニュー");
  if (param_1->timer[0] != 0) {
    JUtility::JUTReport(400,0x32,"<%d>",param_1->timer[0] - 1);
  }
  pJVar16 = param_1->info;
  iVar15 = 0x46;
  iVar6 = l_cursolID - l_startID;
  uVar5 = (uint)*(byte *)&pJVar16->mSignature;
  uVar17 = 0x14;
  if (uVar5 < 0x14) {
    uVar17 = uVar5;
  }
  if (iVar6 < 5) {
    l_startID = iVar6 + l_startID + -5;
    if (l_startID < 0) {
      l_startID = 0;
    }
  }
  else {
    if (0xf < iVar6) {
      iVar13 = uVar5 - 0x14;
      if (iVar13 < 0) {
        iVar13 = 0;
      }
      l_startID = iVar6 + l_startID + -0xf;
      if (iVar13 < l_startID) {
        l_startID = iVar13;
      }
    }
  }
  iVar14 = l_startID * 0x28;
  iVar6 = l_startID;
  for (iVar13 = 0; iVar13 < (int)uVar17; iVar13 = iVar13 + 1) {
    uVar11 = 0x20;
    if (l_cursolID == iVar6) {
      uVar11 = 0x4f;
    }
    iVar12 = pJVar16->mFileSize + iVar14;
    JUtility::JUTReport(0x14,iVar15,"%c %2d %s\x3000＜%s＞",uVar11,iVar6,iVar12,
                        *(int *)(iVar12 + 0x24) + *(char *)(l_groupPoint + iVar6) * 0x2c);
    iVar6 = iVar6 + 1;
    iVar14 = iVar14 + 0x28;
    iVar15 = iVar15 + 0x10;
  }
  JUtility::JUTReport(0x118,400,"Ｘ：進む\x3000Ｙ：戻る");
  iVar6 = 3;
  puVar2 = (undefined4 *)&UNK_80362bf4;
  puVar10 = &uStack64;
  do {
    puVar9 = puVar10;
    puVar7 = puVar2;
    uVar3 = puVar7[2];
    puVar9[1] = puVar7[1];
    puVar9[2] = uVar3;
    iVar6 = iVar6 + -1;
    puVar2 = puVar7 + 2;
    puVar10 = puVar9 + 2;
  } while (iVar6 != 0);
  puVar9[3] = puVar7[3];
  iVar6 = 3;
  ppuVar1 = &PTR_s__80362c10;
  puVar2 = &uStack92;
  do {
    puVar10 = puVar2;
    ppuVar8 = ppuVar1;
    puVar4 = ppuVar8[2];
    puVar10[1] = ppuVar8[1];
    puVar10[2] = puVar4;
    iVar6 = iVar6 + -1;
    ppuVar1 = ppuVar8 + 2;
    puVar2 = puVar10 + 2;
  } while (iVar6 != 0);
  puVar10[3] = ppuVar8[3];
  if (l_timepat < 6) {
    JUtility::JUTReport(0x118,0x1a4,"時刻：%s",local_3c[l_timepat]);
  }
  else {
    JUtility::JUTReport(0x118,0x1a4,"時刻：%d%s",l_timepat + -6,local_24);
  }
  JUtility::JUTReport(0x28,0x1a4,"十字右：進む\x3000十字左：戻る");
  JUtility::JUTReport(200,400,"曜日：%s",local_58[l_weekpat]);
  JUtility::JUTReport(0x28,0x1b8,"%s",
                      (&language_4053)[d_com_inf_game::g_dComIfG_gameInfo.mGameLanguage]);
  iVar6 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2d01);
  if (iVar6 == 0) {
    JUtility::JUTReport(400,0x1a4,"３コン（Ａ）:デモ２３\x3000ＯＦＦ");
  }
  else {
    JUtility::JUTReport(400,0x1a4,"３コン（Ａ）:デモ２３\x3000ＯＮ");
  }
  JUtility::JUTReport(0x24,0x28,"NDEBUG %s %s",mDoMain::COPYDATE_STRING,"FINAL");
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dScnMenu_Execute(menu_of_scene_class *) */

undefined4 dScnMenu_Execute(d_s_menu *param_1)

{
  bool bVar1;
  byte bVar2;
  ushort startCode;
  char cVar3;
  int iVar4;
  JKRArchive__Header *pJVar5;
  
  pJVar5 = param_1->info;
  if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton0 >> 4 & 1) != 0) ||
     ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton0 >> 5 & 1) != 0)) {
    bVar1 = true;
    if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 4 & 1) == 0) &&
       ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 5 & 1) == 0)) {
      cVar3 = m_Do_audio::cLib_calcTimer(param_1->timer + 1);
      if (cVar3 == '\0') {
        param_1->timer[1] = 4;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      param_1->timer[1] = 0x14;
    }
    if (bVar1) {
      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton0 >> 4 & 1) == 0) {
        l_cursolID = l_cursolID + 1;
        if ((int)(uint)*(byte *)&pJVar5->mSignature <= l_cursolID) {
          l_cursolID = 0;
        }
      }
      else {
        l_cursolID = l_cursolID + -1;
        if (l_cursolID < 0) {
          l_cursolID = *(byte *)&pJVar5->mSignature - 1;
        }
      }
    }
  }
  if (((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton1 < '\0') ||
     ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton0 & 1) != 0)) {
    bVar1 = true;
    if (((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') ||
       ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) != 0)) {
      param_1->timer[2] = 0x14;
    }
    else {
      cVar3 = m_Do_audio::cLib_calcTimer(param_1->timer + 2);
      if (cVar3 == '\0') {
        param_1->timer[2] = 4;
      }
      else {
        bVar1 = false;
      }
    }
    iVar4 = l_cursolID;
    if (bVar1) {
      if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton1 < '\0') {
        cVar3 = *(char *)(l_groupPoint + l_cursolID) + -1;
        *(char *)(l_groupPoint + l_cursolID) = cVar3;
        if (cVar3 < '\0') {
          *(char *)(l_groupPoint + l_cursolID) =
               *(char *)(pJVar5->mFileSize + l_cursolID * 0x28 + 0x21) + -1;
        }
      }
      else {
        cVar3 = *(char *)(l_groupPoint + l_cursolID) + '\x01';
        *(char *)(l_groupPoint + l_cursolID) = cVar3;
        if ((int)(uint)*(byte *)(pJVar5->mFileSize + iVar4 * 0x28 + 0x21) <= (int)cVar3) {
          *(undefined *)(l_groupPoint + l_cursolID) = 0;
        }
      }
    }
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 2 & 1) == 0) {
    if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 1 & 1) != 0) &&
       (bVar2 = param_1->timer[0] - 1, param_1->timer[0] = bVar2, bVar2 == 0)) {
      param_1->timer[0] = param_1->timer[0] - 1;
    }
  }
  else {
    bVar2 = param_1->timer[0] + 1;
    param_1->timer[0] = bVar2;
    if (bVar2 == 0) {
      param_1->timer[0] = param_1->timer[0] + 1;
    }
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 4 & 1) != 0) {
    iVar4 = *(int *)(pJVar5->mFileSize + l_cursolID * 0x28 + 0x24) +
            *(char *)(l_groupPoint + l_cursolID) * 0x2c;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext = 0;
    if (param_1->timer[0] == 0) {
      startCode = (ushort)*(byte *)(iVar4 + 0x2a);
    }
    else {
      startCode = param_1->timer[0] - 1;
    }
    d_com_inf_game::dComIfGp_setNextStage
              ((char *)(iVar4 + 0x21),startCode,*(byte *)(iVar4 + 0x29),*(byte *)(iVar4 + 0x2b),
               _4260,0,1,0);
    iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                      ((char *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage,"ENDING");
    if (iVar4 == 0) {
      f_op_scene_mng::fopScnM_ChangeReq(param_1,0xb,0,5);
      JAIZelBasic::bgmStop(JAIZelBasic::zel_basic,0x1e,0);
    }
    else {
      f_op_scene_mng::fopScnM_ChangeReq(param_1,7,0,5);
      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartParameters = 0;
      m_Do_audio::mDoAud_setSceneName
                (0x803c9d48,
                 (int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mStartCode,
                 (int)(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mLayerNo);
    }
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) == 0) {
    if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) != 0) &&
       (l_timepat = l_timepat + 1, 0x1d < l_timepat)) {
      l_timepat = 0;
    }
  }
  else {
    l_timepat = l_timepat + -1;
    if (l_timepat < 0) {
      l_timepat = 0x1d;
    }
  }
  if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 < '\0') {
    l_weekpat = l_weekpat + -1;
    if (l_weekpat < 0) {
      l_weekpat = 6;
    }
  }
  else {
    if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 6 & 1) != 0) &&
       (l_weekpat = l_weekpat + 1, 6 < l_weekpat)) {
      l_weekpat = 0;
    }
  }
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mDayOfWeek = l_weekpat;
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mButton2 >> 3 & 1) != 0) {
    l_languageType = l_languageType + 1;
    if (4 < l_languageType) {
      l_languageType = 0;
    }
    d_com_inf_game::g_dComIfG_gameInfo.mGameLanguage = (&language_4146)[l_languageType];
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[2].mButton2 & 1) != 0) {
    l_demo23 = l_demo23 ^ 1;
    if (l_demo23 == 0) {
      dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2d01);
    }
    else {
      dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2d01);
    }
  }
  d_kankyo::g_env_light.mTimeAdv = _4260;
  if (l_timepat < 6) {
    if (l_timepat == 3) {
      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime = _4267;
      d_kankyo::g_env_light.mCurTime = _4267;
      d_kankyo::g_env_light.mTimeAdv = _4268;
    }
    else {
      if (l_timepat < 3) {
        if (l_timepat == 1) {
          d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime = _4263;
          d_kankyo::g_env_light.mTimeAdv = _4265;
        }
        else {
          if (l_timepat < 1) {
            if (-1 < l_timepat) {
              d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime = _4263;
              d_kankyo::g_env_light.mTimeAdv = _4264;
            }
          }
          else {
            d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime = _4266;
            d_kankyo::g_env_light.mCurTime = _4266;
            d_kankyo::g_env_light.mTimeAdv = _4262;
          }
        }
      }
      else {
        if (l_timepat == 5) {
          d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime = _4271;
          d_kankyo::g_env_light.mCurTime = _4271;
          d_kankyo::g_env_light.mTimeAdv = _4272;
        }
        else {
          if (l_timepat < 5) {
            d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime = _4269;
            d_kankyo::g_env_light.mCurTime = _4269;
            d_kankyo::g_env_light.mTimeAdv = _4270;
          }
        }
      }
    }
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime =
         _4261 * (float)((double)CONCAT44(0x43300000,l_timepat - 6U ^ 0x80000000) - _4274);
    d_kankyo::g_env_light.mTimeAdv = _4262;
  }
  return 1;
}


/* __stdcall dScnMenu_IsDelete(menu_of_scene_class *) */

undefined4 dScnMenu_IsDelete(void)

{
  return 1;
}


/* __stdcall dScnMenu_Delete(menu_of_scene_class *) */

undefined4 dScnMenu_Delete(d_s_menu *param_1)

{
  JUTResFont *pJVar1;
  
  JUTDbPrint::changeFont(JUTDbPrint::sDebugPrint,&JFWSystem::systemFont->parent);
  pJVar1 = param_1->resFont;
  if (pJVar1 != (JUTResFont *)0x0) {
    (*(code *)((pJVar1->parent).vtbl)->_)(pJVar1,1);
  }
  JKRHeap::free(param_1->info,(JKRHeap *)0x0);
  JKRHeap::free(param_1->fontArchive,(JKRHeap *)0x0);
  f_ap_game::g_HIO.deven2 = f_ap_game::g_HIO.deven2 & 0xfd;
  dSv_restart_c::setRestartOption(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart,'\0');
  return 1;
}


/* __stdcall phase_1(menu_of_scene_class *) */

undefined4 phase_1(d_s_menu *param_1)

{
  mDoDvdThd_toMainRam_c *uVar1;
  ulong uVar2;
  mDoDvdThd_toMainRam_c *pmVar3;
  
  uVar1 = (mDoDvdThd_toMainRam_c *)
          mDoDvdThd_toMainRam_c::create("/res/Menu/Menu1.dat",0,(JKRHeap *)0x0);
  param_1->command = uVar1;
  if (param_1->command == (mDoDvdThd_toMainRam_c *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_s_menu.cpp",0x2dc,"i_this->command != 0");
    m_Do_printf::OSPanic("d_s_menu.cpp",0x2dc,"Halt");
  }
  pmVar3 = (mDoDvdThd_toMainRam_c *)
           mDoDvdThd_toMainRam_c::create("/res/Menu/kanfont_fix16.bfn",0,(JKRHeap *)0x0);
  param_1->fontCommand = pmVar3;
  if (param_1->fontCommand == (mDoDvdThd_toMainRam_c *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_s_menu.cpp",0x2df,"i_this->fontCommand != 0");
    m_Do_printf::OSPanic("d_s_menu.cpp",0x2df,"Halt");
  }
  return 2;
}


/* __stdcall phase_2(menu_of_scene_class *) */

int phase_2(d_s_menu *param_1)

{
  JFWDisplay *pJVar1;
  int iVar2;
  ulong uVar3;
  mDoDvdThd_toMainRam_c *pmVar4;
  JUTResFont *this;
  int iVar5;
  JKRArchive__Header *pJVar6;
  
  if (((param_1->command->parent).mStatus == 0) || ((param_1->fontCommand->parent).mStatus == 0)) {
    iVar2 = 0;
  }
  else {
    param_1->info = param_1->command->mpArchiveHeader;
    if (param_1->info == (JKRArchive__Header *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_s_menu.cpp",0x30b,"i_this->info != 0");
      m_Do_printf::OSPanic("d_s_menu.cpp",0x30b,"Halt");
    }
    pmVar4 = param_1->command;
    if (pmVar4 != (mDoDvdThd_toMainRam_c *)0x0) {
      (*(code *)((pmVar4->parent).vtbl)->_mDoDvdThd_toMainRam_c)(pmVar4,1);
    }
    pJVar6 = param_1->info;
    pJVar6->mFileSize = (int)&pJVar6->mSignature + pJVar6->mFileSize;
    iVar2 = 0;
    for (iVar5 = 0; iVar5 < (int)(uint)*(byte *)&pJVar6->mSignature; iVar5 = iVar5 + 1) {
      *(int *)(pJVar6->mFileSize + iVar2 + 0x24) =
           (int)&pJVar6->mSignature + *(int *)(pJVar6->mFileSize + iVar2 + 0x24);
      iVar2 = iVar2 + 0x28;
    }
    if (l_groupPoint == 0) {
      l_groupPoint = JKernel::operator_new__();
      if (l_groupPoint == 0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_s_menu.cpp",0x318,"l_groupPoint != 0");
        m_Do_printf::OSPanic("d_s_menu.cpp",0x318,"Halt");
      }
      for (iVar2 = 0; iVar2 < (int)(uint)*(byte *)&pJVar6->mSignature; iVar2 = iVar2 + 1) {
        *(undefined *)(l_groupPoint + iVar2) = 0;
      }
    }
    param_1->fontArchive = (ResFONT *)param_1->fontCommand->mpArchiveHeader;
    pmVar4 = param_1->fontCommand;
    if (pmVar4 != (mDoDvdThd_toMainRam_c *)0x0) {
      (*(code *)((pmVar4->parent).vtbl)->_mDoDvdThd_toMainRam_c)(pmVar4,1);
    }
    if (param_1->fontArchive != (ResFONT *)0x0) {
      this = (JUTResFont *)JKernel::operator_new(0x70);
      if (this != (JUTResFont *)0x0) {
        ::JUTResFont::JUTResFont(this,param_1->fontArchive,(JKRHeap *)0x0);
        (this->parent).vtbl = (JUTFont__vtbl *)&::myFontClass::__vt;
      }
      param_1->resFont = this;
      if (param_1->resFont != (JUTResFont *)0x0) {
        JUTDbPrint::changeFont(JUTDbPrint::sDebugPrint,&param_1->resFont->parent);
      }
    }
    pJVar1 = JFWDisplay::sManager;
    *(uint *)&JFWDisplay::sManager->field_0x24 = (DAT_800000f8 >> 2) / 0x3c;
    *(undefined2 *)&pJVar1->field_0x20 = 0;
    mDoGph_gInf_c::mBackColor.r = d_com_inf_game::g_clearColor.r;
    mDoGph_gInf_c::mBackColor.g = d_com_inf_game::g_clearColor.g;
    mDoGph_gInf_c::mBackColor.b = d_com_inf_game::g_clearColor.b;
    mDoGph_gInf_c::mBackColor.a = d_com_inf_game::g_clearColor.a;
    f_ap_game::g_HIO.deven2 = f_ap_game::g_HIO.deven2 | 2;
    iVar2 = 4;
  }
  return iVar2;
}


/* __stdcall dScnMenu_Create(scene_class *) */

void dScnMenu_Create(d_s_menu *param_1)

{
  l_languageType = d_com_inf_game::g_dComIfG_gameInfo.mGameLanguage;
  d_com_lib_game::dComLbG_PhaseHandler
            ((request_of_phase_process_class *)&param_1->request_phase,
             (cPhs__Handler *)d_s_phase_list,param_1);
  return;
}

}

/* __thiscall myFontClass::~myFontClass(void) */

void __thiscall myFontClass::_myFontClass(myFontClass *this)

{
  short in_r4;
  
  if (this != (myFontClass *)0x0) {
    *(undefined ***)this = &__vt;
    JUTResFont::_JUTResFont((JUTResFont *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JUTResFont::getResFont(void) const */

ResFONT * __thiscall JUTResFont::getResFont(JUTResFont *this)

{
  return this->mpResFONT;
}


/* __thiscall JUTResFont::getFontType(void) const */

short __thiscall JUTResFont::getFontType(JUTResFont *this)

{
  return this->mpINF1->mFontEncoding;
}


/* __thiscall JUTResFont::getLeading(void) const */

ushort __thiscall JUTResFont::getLeading(JUTResFont *this)

{
  return this->mpINF1->mFallbackLeading;
}


/* __thiscall JUTResFont::getWidth(void) const */

ushort __thiscall JUTResFont::getWidth(JUTResFont *this)

{
  return this->mpINF1->mFallbackWidth;
}


/* __thiscall JUTResFont::getAscent(void) const */

short __thiscall JUTResFont::getAscent(JUTResFont *this)

{
  return this->mpINF1->mAscent;
}


/* __thiscall JUTResFont::getDescent(void) const */

short __thiscall JUTResFont::getDescent(JUTResFont *this)

{
  return this->mpINF1->mDescent;
}


/* __thiscall JUTResFont::getHeight(void) const */

int __thiscall JUTResFont::getHeight(JUTResFont *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)((this->parent).vtbl)->getDescent)();
  iVar2 = (*(code *)((this->parent).vtbl)->getAscent)(this);
  return iVar2 + iVar1;
}

