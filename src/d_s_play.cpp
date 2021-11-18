#include <d_s_play.h>
#include <d_ovlp_fade2.h>
#include <Runtime.PPCEABI.H/CPlusLibPPCp.h>
#include <d_s_play.h>
#include <JUtility/JUTDbPrint.h>
#include <f_op_msg_mng.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_cc_s.h>
#include <d_bg_s.h>
#include <f_op_overlap_mng.h>
#include <d_com_inf_game.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <f_op_scene_mng.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_kankyo.h>
#include <m_Do_audio.h>
#include <d_meter.h>
#include <d_vibration.h>
#include <d_material.h>
#include <d_kankyo_rain.h>
#include <d_cc_mass_s.h>
#include <d_snap.h>
#include <d_a_player_main.h>
#include <d_particle.h>
#include <d_stage.h>
#include <f_op_draw_iter.h>
#include <f_pc_manager.h>
#include <d_attention.h>
#include <d_map.h>
#include <d_demo.h>
#include <d_detect.h>
#include <d_event.h>
#include <m_Do_hostIO.h>
#include <c_dylink.h>
#include <m_Do_ext.h>
#include <JKernel/JKRHeap.h>
#include <m_Do_Reset.h>
#include <m_Do_graphic.h>
#include <d_com_static.h>
#include <d_a_obj_tribox_static.h>
#include <d_save.h>
#include <JAudio/JAIBankWave.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <m_Do_dvd_thread.h>
#include <JUtility/JUTConsole.h>
#include <d_resorce.h>
#include <d_a_sea.h>
#include <d_drawlist.h>
#include <os/OSTime.h>
#include <d_com_lib_game.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <dScnPly_preLoad_HIO_c.h>
#include <dScnPly_reg_HIO_c.h>
#include <dScnPly_env_otherHIO_c.h>
#include <dScnPly_env_HIO_c.h>
#include <dScnPly_dark_HIO_c.h>
#include <dScnPly_reg_childHIO_c.h>
#include <dScnPly_ply_c.h>
#include <dScnPly_msg_HIO_c.h>
#include <dScnPly_env_debugHIO_c.h>


namespace d_s_play {
}

namespace d_s_play {
struct dScnPly_dark_HIO_c g_darkHIO;
struct dScnPly_reg_HIO_c g_regHIO;
undefined4 g_envHIO;
struct dScnPly_msg_HIO_c g_msgDHIO;
undefined number_of_resPhase;
undefined number_of_dylPhase;
struct request_of_phase_process_class resPhase[10];
undefined dylPhase;
}
byte dScnPly_ply_c;
byte dScnPly_ply_c;

namespace d_s_play {
undefined4 dylPreLoadTime1;
undefined4 resPreLoadTime0;
undefined4 resPreLoadTime1;
undefined4 g_preLoadHIO;
struct mDoDvdThd_mountXArchive_c * l_lkDemoAnmCommand;
}

/* __thiscall dScnPly_ply_c::calcPauseTimer(void) */

void __thiscall dScnPly_ply_c::calcPauseTimer(dScnPly_ply_c *this)

{
  if (nextPauseTimer == 0) {
    d_ovlp_fade2::cLib_calcTimer(&pauseTimer);
  }
  else {
    pauseTimer = nextPauseTimer;
    nextPauseTimer = 0;
  }
  return;
}


/* __thiscall dScnPly_dark_HIO_c::dScnPly_dark_HIO_c(void) */

void __thiscall dScnPly_dark_HIO_c::dScnPly_dark_HIO_c(dScnPly_dark_HIO_c *this)

{
  float fVar1;
  
  this->vtbl = (undefined *)&__vt;
  this->field_0x5 = 0;
  this->field_0x6 = 0;
  this->mDarkStatus[0].mRatio = dStage_roomControl_c::mDarkStatus[0].mRatio;
  Runtime.PPCEABI.H::__copy(this->mDarkStatus[0].mOffs,0x803753a5,2);
  fVar1 = dStage_roomControl_c::mDarkStatus[0].mScale[1];
  this->mDarkStatus[0].mScale[0] = dStage_roomControl_c::mDarkStatus[0].mScale[0];
  this->mDarkStatus[0].mScale[1] = fVar1;
  *(undefined4 *)(this->mDarkStatus + 1) = dStage_roomControl_c::mDarkStatus[1]._0_4_;
  fVar1 = dStage_roomControl_c::mDarkStatus[1].mScale[1];
  this->mDarkStatus[1].mScale[0] = dStage_roomControl_c::mDarkStatus[1].mScale[0];
  this->mDarkStatus[1].mScale[1] = fVar1;
  fVar1 = dStage_roomControl_c::mDarkStatus[2].mScale[0];
  *(undefined4 *)(this->mDarkStatus + 2) = dStage_roomControl_c::mDarkStatus[2]._0_4_;
  this->mDarkStatus[2].mScale[0] = fVar1;
  return;
}


/* __thiscall dScnPly_reg_childHIO_c::dScnPly_reg_childHIO_c(void) */

void __thiscall dScnPly_reg_childHIO_c::dScnPly_reg_childHIO_c(dScnPly_reg_childHIO_c *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  this->vtbl = (undefined *)&__vt;
  fVar1 = d_s_play::0_0;
  iVar2 = 0;
  iVar3 = 0x1e;
  do {
    *(float *)((int)this->mFloats + iVar2) = fVar1;
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar2 = 0;
  iVar3 = 10;
  do {
    *(undefined2 *)((int)this->mShorts + iVar2) = 0;
    iVar2 = iVar2 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* __thiscall dScnPly_env_otherHIO_c::dScnPly_env_otherHIO_c(void) */

void __thiscall dScnPly_env_otherHIO_c::dScnPly_env_otherHIO_c(dScnPly_env_otherHIO_c *this)

{
  int iVar1;
  int iVar2;
  
  *(undefined1 **)this = &__vt;
  this[5] = (dScnPly_env_otherHIO_c)0x1;
  this[6] = (dScnPly_env_otherHIO_c)0x1;
  iVar1 = 0;
  *(undefined2 *)(this + 0x40) = 0;
  this[7] = (dScnPly_env_otherHIO_c)0x0;
  this[8] = (dScnPly_env_otherHIO_c)0x0;
  this[9] = (dScnPly_env_otherHIO_c)0x0;
  *(float *)(this + 0x44) = d_s_play::_4268;
  this[10] = (dScnPly_env_otherHIO_c)0x0;
  this[0xb] = (dScnPly_env_otherHIO_c)0x0;
  this[0xc] = (dScnPly_env_otherHIO_c)0x0;
  this[0xd] = (dScnPly_env_otherHIO_c)0x80;
  this[0xe] = (dScnPly_env_otherHIO_c)0x10;
  this[0xf] = (dScnPly_env_otherHIO_c)0x0;
  this[0x10] = (dScnPly_env_otherHIO_c)0x0;
  this[0x11] = (dScnPly_env_otherHIO_c)0x0;
  this[0x12] = (dScnPly_env_otherHIO_c)0x0;
  this[0x15] = (dScnPly_env_otherHIO_c)0x0;
  iVar2 = 0x14;
  do {
    *(undefined2 *)(this + iVar1 + 0x18) = 0xffff;
    iVar1 = iVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this[0x16] = (dScnPly_env_otherHIO_c)0x0;
  return;
}


/* __thiscall dScnPly_env_debugHIO_c::dScnPly_env_debugHIO_c(void) */

void __thiscall dScnPly_env_debugHIO_c::dScnPly_env_debugHIO_c(dScnPly_env_debugHIO_c *this)

{
  float fVar1;
  float fVar2;
  
  *(undefined1 **)this = &__vt;
  fVar1 = d_s_play::_4279;
  *(float *)(this + 8) = d_s_play::_4279;
  *(float *)(this + 0xc) = fVar1;
  *(float *)(this + 0x10) = fVar1;
  fVar2 = d_s_play::_4280;
  *(float *)(this + 0x14) = d_s_play::_4280;
  *(float *)(this + 0x18) = fVar2;
  *(float *)(this + 0x1c) = fVar2;
  fVar1 = d_s_play::0_0;
  *(float *)(this + 0x20) = d_s_play::0_0;
  *(float *)(this + 0x24) = fVar1;
  *(float *)(this + 0x28) = fVar1;
  *(float *)(this + 0x2c) = fVar2;
  return;
}


/* __thiscall dScnPly_msg_HIO_c::dScnPly_msg_HIO_c(void) */

void __thiscall dScnPly_msg_HIO_c::dScnPly_msg_HIO_c(dScnPly_msg_HIO_c *this)

{
  *(undefined ***)this = &__vt;
  *(undefined *)&this->field_0x8 = 0;
  *(undefined *)&this->field_0x5 = 0;
  *(undefined *)&this->field_0x6 = 0;
  *(undefined *)&this->field_0x7 = 0;
  *(undefined *)&this->field_0x9 = 0;
  *(undefined2 *)&this->field_0xa = 0;
  *(undefined2 *)&this->field_0xc = 1;
  *(undefined4 *)&this->field_0x10 = 0xffffffff;
  return;
}


/* __thiscall dScnPly_msg_HIO_c::dScnPly_msg_HIO_checkUpdate(unsigned char) */

void __thiscall
dScnPly_msg_HIO_c::dScnPly_msg_HIO_checkUpdate(dScnPly_msg_HIO_c *this,uchar param_1)

{
  *(uchar *)&this->field_0x5 = param_1;
  return;
}


/* __thiscall dScnPly_msg_HIO_c::dScnPly_msg_HIO_setUpdate(unsigned char) */

void __thiscall dScnPly_msg_HIO_c::dScnPly_msg_HIO_setUpdate(dScnPly_msg_HIO_c *this,uchar param_1)

{
  *(uchar *)&this->field_0x7 = param_1;
  return;
}


/* __thiscall dScnPly_msg_HIO_c::dScnPly_msg_HIO_numUpdate(short,
                                                           short) */

void __thiscall
dScnPly_msg_HIO_c::dScnPly_msg_HIO_numUpdate(dScnPly_msg_HIO_c *this,short param_1,short param_2)

{
  *(short *)&this->field_0xa = *(short *)&this->field_0xa + param_1;
  *(short *)&this->field_0xc = *(short *)&this->field_0xc + param_2;
  if (99 < *(short *)&this->field_0xa) {
    *(undefined2 *)&this->field_0xa = 99;
  }
  if (*(short *)&this->field_0xa < 0) {
    *(undefined2 *)&this->field_0xa = 0;
  }
  if (0x7fff < *(short *)&this->field_0xc) {
    *(undefined2 *)&this->field_0xc = 0x7fff;
  }
  if (-1 < *(short *)&this->field_0xc) {
    return;
  }
  *(undefined2 *)&this->field_0xc = 0;
  return;
}


/* __thiscall dScnPly_msg_HIO_c::dScnPly_msg_HIO_padCheck(void) */

void __thiscall dScnPly_msg_HIO_c::dScnPly_msg_HIO_padCheck(dScnPly_msg_HIO_c *this)

{
  if (*(char *)&this->field_0x5 != '\0') {
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mButton2 >> 3 & 1) != 0) {
      dScnPly_msg_HIO_checkUpdate(this,'\0');
    }
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mButton2 >> 4 & 1) == 0) {
      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mButton2 >> 5 & 1) == 0) {
        if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mButton2 >> 6 & 1) == 0) {
          if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mButton2 < '\0') {
            if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mButton1 >> 5 & 1) == 0) {
              if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mButton1 >> 6 & 1) == 0) {
                if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mButton0 & 1) == 0) {
                  dScnPly_msg_HIO_numUpdate(this,0,-1);
                }
                else {
                  dScnPly_msg_HIO_numUpdate(this,0,-10);
                }
              }
              else {
                dScnPly_msg_HIO_numUpdate(this,0,-100);
              }
            }
            else {
              dScnPly_msg_HIO_numUpdate(this,0,-1000);
            }
          }
          else {
            if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mButton3 < '\0') {
              if (*(char *)&this->field_0x6 == '\0') {
                *(undefined *)&this->field_0x6 = 1;
              }
            }
            else {
              if (*(char *)&this->field_0x7 != '\0') {
                if (*(char *)&this->field_0x6 == '\0') {
                  *(undefined *)&this->field_0x6 = 1;
                }
                dScnPly_msg_HIO_setUpdate(this,'\0');
              }
            }
          }
        }
        else {
          if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mButton1 >> 5 & 1) == 0) {
            if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mButton1 >> 6 & 1) == 0) {
              if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mButton0 & 1) == 0) {
                dScnPly_msg_HIO_numUpdate(this,0,1);
              }
              else {
                dScnPly_msg_HIO_numUpdate(this,0,10);
              }
            }
            else {
              dScnPly_msg_HIO_numUpdate(this,0,100);
            }
          }
          else {
            dScnPly_msg_HIO_numUpdate(this,0,1000);
          }
        }
      }
      else {
        if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mButton0 & 1) == 0) {
          dScnPly_msg_HIO_numUpdate(this,-1,0);
        }
        else {
          dScnPly_msg_HIO_numUpdate(this,-10,0);
        }
      }
    }
    else {
      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mButton0 & 1) == 0) {
        dScnPly_msg_HIO_numUpdate(this,1,0);
      }
      else {
        dScnPly_msg_HIO_numUpdate(this,10,0);
      }
    }
    JUtility::JUTReport(0x1d6,0xfa,"Group : %05d",(int)*(short *)&this->field_0xa);
    JUtility::JUTReport(0x1d6,0x10e,"ID    : %05d",(int)*(short *)&this->field_0xc);
  }
  return;
}


/* __thiscall dScnPly_msg_HIO_c::dScnPly_msg_HIO_messageProc(void) */

void __thiscall dScnPly_msg_HIO_c::dScnPly_msg_HIO_messageProc(dScnPly_msg_HIO_c *this)

{
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  msg_class *pmVar4;
  float local_18;
  float local_14;
  float local_10;
  
  dScnPly_msg_HIO_padCheck(this);
  if (*(char *)&this->field_0x6 != '\0') {
    if (*(uint *)&this->field_0x10 == 0xffffffff) {
      uVar2 = (int)*(short *)&this->field_0xa << 0x10 | (int)*(short *)&this->field_0xc;
      local_10 = d_s_play::0_0;
      local_14 = d_s_play::0_0;
      local_18 = d_s_play::0_0;
      sVar1 = *(short *)&this->field_0xa;
      if (((sVar1 != 99) && (sVar1 != 0x62)) && (sVar1 != 0x59)) {
        uVar2 = f_op_msg_mng::fopMsgM_searchMessageNumber(uVar2);
        *(short *)&this->field_0xa = (short)(uVar2 >> 0x10);
        *(short *)&this->field_0xc = (short)uVar2;
      }
      uVar3 = f_op_msg_mng::fopMsgM_messageSet(uVar2,&local_18);
      *(undefined4 *)&this->field_0x10 = uVar3;
    }
    else {
      pmVar4 = f_op_msg_mng::fopMsgM_SearchByID(*(uint *)&this->field_0x10);
      if (pmVar4 != (msg_class *)0x0) {
        if (pmVar4->mMode == 0xe) {
          pmVar4->mMode = 0x10;
        }
        else {
          if (pmVar4->mMode == 0x12) {
            pmVar4->mMode = 0x13;
            *(undefined4 *)&this->field_0x10 = 0xffffffff;
            *(undefined *)&this->field_0x6 = 0;
            *(short *)&this->field_0xc = *(short *)&this->field_0xc + 1;
          }
        }
      }
    }
  }
  return;
}


namespace d_s_play {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dScnPly_Draw(dScnPly_ply_c *) */

undefined4 dScnPly_Draw(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  JUTFader *pJVar3;
  undefined4 uVar4;
  int iVar5;
  ulong uVar6;
  int iVar7;
  uint uVar8;
  byte bVar10;
  create_tag_class *pcVar9;
  JUTFader local_28;
  JUTFader JStack39;
  JUTFader JStack38;
  JUTFader JStack37;
  JUTFader local_24;
  JUTFader JStack35;
  JUTFader JStack34;
  JUTFader JStack33;
  
  dCcS::Move(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS);
  dBgS::ClrMoveFlag(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  iVar5 = f_op_overlap_mng::fopOvlpM_IsPeek();
  if (iVar5 == 0) {
    iVar5 = d_com_inf_game::dComIfG_resetToOpening(param_1);
    if (iVar5 == 0) {
      if (*(short *)(param_1 + 8) == 7) {
        if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext != 0) {
          if (0xb < d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mWipeType) {
            uVar6 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert
                      (uVar6,"d_s_play.cpp",0x3e9,
                       "dComIfGp_getNextStageWipe() < (sizeof(l_wipeType) / sizeof(l_wipeType[0]))")
            ;
            m_Do_printf::OSPanic("d_s_play.cpp",0x3e9,"Halt");
          }
          iVar5 = MSL_C.PPCEABI.bare.H::strcmp
                            ((char *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage,"ENDING");
          if (iVar5 == 0) {
            f_op_scene_mng::fopScnM_ChangeReq(param_1,0xb,0,5);
            JAIZelBasic::bgmStop(JAIZelBasic::zel_basic,0x1e,0);
          }
          else {
            f_op_scene_mng::fopScnM_ChangeReq
                      (param_1,7,
                       (int)*(short *)(&l_wipeType_4411 +
                                      (char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.
                                            mWipeType * 2),5);
            iVar5 = d_kankyo::dKy_getdaytime_hour();
            iVar7 = d_kankyo::dKy_checkEventNightStop();
            pJVar3 = mDoGph_gInf_c::mFader;
            uVar2 = d_com_inf_game::g_saftyWhiteColor;
            uVar1 = d_com_inf_game::g_blackColor;
            if (iVar7 == 0) {
              uVar4 = 0;
              if ((5 < iVar5) && (iVar5 < 0x12)) {
                uVar4 = 1;
              }
              uVar8 = countLeadingZeros(uVar4);
              uVar8 = uVar8 >> 5;
            }
            else {
              uVar8 = 1;
            }
            if (((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mWipeType == 1) ||
                  (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mWipeType == 2)) ||
                 (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mWipeType == 7)) ||
                (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mWipeType == 8 ||
                  (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mWipeType == 10)) &&
                 (uVar8 != 0)))) ||
               (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mWipeType == 9 ||
                 (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mWipeType == 0xb)) &&
                (uVar8 == 0)))) {
              local_24 = SUB41((uint)d_com_inf_game::g_saftyWhiteColor >> 0x18,0);
              mDoGph_gInf_c::mFader[0xc] = local_24;
              JStack35 = SUB41((uint)uVar2 >> 0x10,0);
              pJVar3[0xd] = JStack35;
              JStack34 = SUB41((uint)uVar2 >> 8,0);
              pJVar3[0xe] = JStack34;
              JStack33 = SUB41(uVar2,0);
              pJVar3[0xf] = JStack33;
            }
            else {
              local_28 = SUB41((uint)d_com_inf_game::g_blackColor >> 0x18,0);
              mDoGph_gInf_c::mFader[0xc] = local_28;
              JStack39 = SUB41((uint)uVar1 >> 0x10,0);
              pJVar3[0xd] = JStack39;
              JStack38 = SUB41((uint)uVar1 >> 8,0);
              pJVar3[0xe] = JStack38;
              JStack37 = SUB41(uVar1,0);
              pJVar3[0xf] = JStack37;
            }
            m_Do_audio::mDoAud_setSceneName
                      (0x803c9d48,
                       (int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mStartCode,
                       (int)(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.
                                  mLayerNo);
          }
        }
      }
    }
  }
  bVar10 = d_meter::dMenu_flag();
  if ((bVar10 == 0) && (::dScnPly_ply_c::pauseTimer == 0)) {
    dVibration_c::Run(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration);
    dMat_ice_c::play(_mIce);
    dComIfG_play_c::executeMagma(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
    if ((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpGrassPacket != (dGrass_packet_c *)0x0) ||
         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket != (dTree_packet_c *)0x0)) ||
        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpWoodPacket != (Packet_c *)0x0)) ||
       ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFlowerPacket != (dFlower_packet_c *)0x0 ||
        (iVar5 = d_kankyo_rain::dKyr_poison_live_check(), iVar5 != 0)))) {
      dCcMassS_Mng::Prepare(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng);
    }
    dComIfG_play_c::executeGrass(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
    dComIfG_play_c::executeTree(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
    dComIfG_play_c::executeWood(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
    dComIfG_play_c::executeFlower(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
    d_kankyo_rain::dKyr_poison_light_colision();
    (**(code **)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS.parent.field_0x1400 + 0x14))
              (0x803c5ea8);
    d_snap::dSnap_Execute();
    if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor == (daPy_lk_c *)0x0) ||
       (iVar5 = daPy_lk_c::checkGameOverStart(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor),
       iVar5 == 0)) {
      dPa_control_c::calc3D(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl);
    }
    dPa_control_c::calc2D(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl);
    g__Timer = g__Timer + 1;
  }
  else {
    dVibration_c::Pause(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration);
  }
  dCcS::MassClear(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS);
  dPa_control_c::calcMenu(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl);
  ::dScnPly_msg_HIO_c::dScnPly_msg_HIO_messageProc(&g_msgDHIO);
  dStage_roomControl_c::checkDrawArea(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl);
  for (pcVar9 = (create_tag_class *)f_op_draw_iter::fopDwIt_Begin();
      pcVar9 != (create_tag_class *)0x0;
      pcVar9 = (create_tag_class *)f_op_draw_iter::fopDwIt_Next(pcVar9)) {
    f_pc_manager::fpcM_Draw(pcVar9->mpTagData);
  }
  bVar10 = d_meter::dMenu_flag();
  if (bVar10 == 0) {
    dPa_modelControl_c::draw((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl)->mModelCtrl);
    dComIfG_play_c::drawMagma(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
    dComIfG_play_c::drawGrass(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
    dComIfG_play_c::drawTree(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
    dComIfG_play_c::drawWood(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
    dComIfG_play_c::drawFlower(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
    dCcS::Draw(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS);
    d_snap::dSnap_DebugDraw();
    dAttention_c::Draw(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention);
    dMap_c::mapBufferSendAGB(3);
  }
  return 1;
}


/* __stdcall dScnPly_Execute(dScnPly_ply_c *) */

undefined4 dScnPly_Execute(dScnPly_ply_c *param_1)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  
  iVar1 = f_op_overlap_mng::fopOvlpM_IsPeek();
  if (iVar1 == 0) {
    if (mDoAud_zelAudio_c::mBgmSet != 0) {
      JAIZelBasic::sceneBgmStart(JAIZelBasic::zel_basic);
      JAIZelBasic::load2ndDynamicWave(JAIZelBasic::zel_basic);
      mDoAud_zelAudio_c::mBgmSet = 0;
    }
    cVar2 = ::dScnPly_ply_c::calcPauseTimer(param_1);
    if (cVar2 != '\0') {
      return 1;
    }
  }
  d_kankyo::dKy_itudemo_se();
  bVar3 = d_meter::dMenu_flag();
  if (bVar3 == 0) {
    dDemo_manager_c::update(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr);
    dComIfG_play_c::executeEvtManager(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.mpPlayer == (daPy_lk_c *)0x0) {
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.mpPlayer =
           d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.mPlayerNo = 0;
    }
    else {
      dAttention_c::Run(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0xffffffff);
    }
    dDetect_c::proc(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDetect);
  }
  return 1;
}


/* __stdcall dScnPly_IsDelete(dScnPly_ply_c *) */

undefined4 dScnPly_IsDelete(void)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall dScnPly_Delete(dScnPly_ply_c *) */

undefined4 dScnPly_Delete(undefined4 param_1,undefined4 param_2,short param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  int *piVar5;
  int iVar6;
  undefined8 uVar7;
  
  dAttention_c::_dAttention_c(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention);
  dVibration_c::_dVibration_c(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration);
  (**(code **)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS.parent.field_0x1400 + 0x10))
            (0x803c5ea8);
  dCcS::Dt(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS);
  d_snap::dSnap_Delete();
  d_stage::dStage_Delete();
  dEvt_control_c::remove(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl);
  dPa_control_c::removeScene(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl);
  uVar7 = dComIfG_play_c::removeDemo(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
  dMat_control_c::remove((dMat_control_c *)((ulonglong)uVar7 >> 0x20),(char *)uVar7);
  f_op_msg_mng::fopMsgM_destroyExpHeap(d_com_inf_game::g_dComIfG_gameInfo.field_0x5c1c);
  iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss0");
  if (iVar2 != 0) {
    iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss1");
    if (iVar2 != 0) {
      iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss2");
      if (iVar2 != 0) {
        iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss3");
        if (iVar2 != 0) goto LAB_802351d4;
      }
    }
  }
  d_com_inf_game::dComIfGs_revPlayerRecollectionData();
LAB_802351d4:
  dComIfG_play_c::removeMagma(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
  dComIfG_play_c::removeGrass(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
  dComIfG_play_c::removeTree(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
  dComIfG_play_c::removeWood(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
  dComIfG_play_c::removeFlower(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAirMeter = 0;
  d_com_inf_game::g_dComIfG_gameInfo._23496_1_ = 0;
  DAT_803e7d9a = 0;
  DAT_803e7da4 = 0xffffffff;
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,g_darkHIO._4_1_);
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e7d0c);
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e7d98);
  iVar2 = 0;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 0;
  if (-1 < preLoadNo) {
    piVar5 = (int *)(&PTR_sea_resName_80363128)[preLoadNo * 4];
    bVar1 = (&DAT_8036312d)[preLoadNo * 0x10];
    if ((piVar5 != (int *)0x0) && (*piVar5 != 0)) {
      iVar6 = 0;
      for (iVar3 = 0; iVar3 < (int)(uint)bVar1; iVar3 = iVar3 + 1) {
        d_com_inf_game::dComIfG_resDelete
                  ((request_of_phase_process_class *)((int)&resPhase[0].mpTbl + iVar2),
                   *(char **)((int)piVar5 + iVar6));
        iVar6 = iVar6 + 4;
        iVar2 = iVar2 + 8;
      }
    }
    psVar4 = (short *)(&PTR_sea_dylKeyTbl_80363124)[preLoadNo * 4];
    bVar1 = (&DAT_8036312c)[preLoadNo * 0x10];
    if ((psVar4 != (short *)0x0) && (*psVar4 != 0)) {
      iVar6 = 0;
      iVar3 = 0;
      for (iVar2 = 0; iVar2 < (int)(uint)bVar1; iVar2 = iVar2 + 1) {
        cDylPhs::Unlink((cDylPhs *)(&dylPhase + iVar3),
                        (request_of_phase_process_class *)(int)*(short *)((int)psVar4 + iVar6),
                        param_3);
        iVar6 = iVar6 + 2;
        iVar3 = iVar3 + 8;
      }
    }
  }
  dComIfG_play_c::init(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x80235580) */
/* WARNING: Removing unreachable block (ram,0x80235570) */
/* WARNING: Removing unreachable block (ram,0x80235568) */
/* WARNING: Removing unreachable block (ram,0x80235578) */
/* WARNING: Removing unreachable block (ram,0x80235588) */
/* __stdcall heapSizeCheck(void) */

undefined4 heapSizeCheck(void)

{
  JKRHeap *pJVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  JKRExpHeap *pJVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f27;
  double dVar9;
  undefined8 in_f28;
  double dVar10;
  undefined8 in_f29;
  double dVar11;
  undefined8 in_f30;
  double dVar12;
  undefined8 in_f31;
  double dVar13;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  pJVar1 = m_Do_ext::mDoExt_getArchiveHeap();
  uVar2 = JKRHeap::getFreeSize(pJVar1);
  pJVar1 = m_Do_ext::mDoExt_getArchiveHeap();
  uVar3 = JKRHeap::getTotalFreeSize(pJVar1);
  uVar4 = m_Do_ext::mDoExt_getSafeArchiveHeapSize();
  dVar13 = (double)((float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - _4653) /
                   (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - _4653));
  dVar12 = (double)((float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - _4653) /
                   (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - _4653));
  pJVar5 = m_Do_ext::mDoExt_getGameHeap();
  uVar2 = JKRHeap::getFreeSize(&pJVar5->parent);
  pJVar5 = m_Do_ext::mDoExt_getGameHeap();
  uVar3 = JKRHeap::getTotalFreeSize(&pJVar5->parent);
  uVar4 = m_Do_ext::mDoExt_getSafeGameHeapSize();
  dVar11 = (double)((float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - _4653) /
                   (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - _4653));
  dVar10 = (double)((float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - _4653) /
                   (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - _4653));
  pJVar1 = m_Do_ext::mDoExt_getZeldaHeap();
  JKRHeap::getFreeSize(pJVar1);
  pJVar1 = m_Do_ext::mDoExt_getZeldaHeap();
  uVar2 = JKRHeap::getTotalFreeSize(pJVar1);
  uVar3 = m_Do_ext::mDoExt_getSafeZeldaHeapSize();
  dVar9 = (double)((float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - _4653) /
                  (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - _4653));
  pJVar1 = m_Do_ext::mDoExt_getCommandHeap();
  JKRHeap::getFreeSize(pJVar1);
  pJVar1 = m_Do_ext::mDoExt_getCommandHeap();
  uVar2 = JKRHeap::getTotalFreeSize(pJVar1);
  uVar3 = m_Do_ext::mDoExt_getSafeCommandHeapSize();
  dVar8 = (double)_4651;
  if ((((dVar13 < dVar8) || (dVar12 < dVar8)) || (dVar11 < dVar8)) ||
     (((dVar10 < dVar8 || (dVar9 < dVar8)) ||
      ((double)((float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - _4653) /
               (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - _4653)) < dVar8)))) {
    uVar6 = 0;
  }
  else {
    uVar6 = 1;
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  __psq_l0(auStack56,uVar7);
  __psq_l1(auStack56,uVar7);
  __psq_l0(auStack72,uVar7);
  __psq_l1(auStack72,uVar7);
  return uVar6;
}


/* __stdcall phase_00(dScnPly_ply_c *) */

undefined4 phase_00(dScnPly_ply_c *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *this;
  Act_c *this_00;
  ulong uVar3;
  
  iVar1 = m_Do_audio::mDoAud_isUsedHeapForStreamBuffer();
  if (iVar1 == 0) {
    mDoGph_gInf_c::mBlureFlag = 0;
    if ((param_1->parent).parent.parent.mProcName == 7) {
      iVar1 = heapSizeCheck();
      if (iVar1 == 0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::setWarningMessage_f(uVar3,"d_s_play.cpp",0xd2c,"%s",(___)"Memory Danger !!");
      }
    }
    else {
      iVar1 = heapSizeCheck();
      if (iVar1 == 0) {
        m_Do_Reset::mDoRst_reset(0,0x80000000,0);
      }
      if (*mDoRst::mResetData != 0) {
        this = mDoRst::mResetData;
        if (mDoAud_zelAudio_c::mResetFlag != '\0') {
          this = (int *)JAIZelBasic::resetRecover(JAIZelBasic::zel_basic);
          mDoAud_zelAudio_c::mResetFlag = '\0';
        }
        mDoGph_gInf_c::mFade = 0;
        mDoGph_gInf_c::offMonotone();
        dDlst_list_c::mWipe = 0;
        this_00 = (Act_c *)daTitle_proc_c::daTitle_Kirakira_Sound_flag_on((daTitle_proc_c *)this);
        daObjTribox::Act_c::reset(this_00);
        d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext = 0;
      }
      dSv_info_c::init(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo);
    }
    uVar2 = 2;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __stdcall phase_01(dScnPly_ply_c *) */

byte phase_01(void)

{
  int iVar1;
  
  iVar1 = m_Do_audio::mDoAud_load1stDynamicWave();
  return -(iVar1 != 0) & 2;
}


/* __stdcall phase_0(dScnPly_ply_c *) */

undefined4 phase_0(dScnPly_ply_c *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  ulong uVar4;
  bool bVar5;
  char acStack40 [32];
  
  uVar1 = JAInter::BankWave::checkAllWaveLoadStatus();
  if ((uVar1 & 0xff) == 0) {
    l_lkDemoAnmCommand = (mDoDvdThd_mountXArchive_c *)0x0;
    iVar3 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2d01)
    ;
    bVar5 = iVar3 != 0;
    if ((uint)bVar5 != (int)(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mLkDArcIdx) {
      if (-1 < (char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mLkDArcIdx) {
        (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLkDArc)->parent).parent.vtbl)->
                  unmount)();
      }
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mLkDArcIdx = bVar5;
      MSL_C.PPCEABI.bare.H::sprintf(acStack40,"/res/Object/LkD%02d.arc",(int)bVar5);
      l_lkDemoAnmCommand = mDoDvdThd_mountXArchive_c::create(acStack40,0,ARAM);
      if (l_lkDemoAnmCommand == (mDoDvdThd_mountXArchive_c *)0x0) {
        uVar4 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar4,"d_s_play.cpp",0xd56,"l_lkDemoAnmCommand != 0");
        m_Do_printf::OSPanic("d_s_play.cpp",0xd56,"Halt");
      }
    }
    uVar2 = 2;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __stdcall phase_1(dScnPly_ply_c *) */

undefined4 phase_1(dScnPly_ply_c *param_1)

{
  ulong uVar1;
  int iVar2;
  J3DMaterialTable *pJVar3;
  dMat_control_c *this;
  dRes_control_c *pdVar4;
  
  if (l_lkDemoAnmCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
    if ((l_lkDemoAnmCommand->parent).mStatus == 0) {
      return 0;
    }
    if (l_lkDemoAnmCommand->mpArchive == (JKRArchive *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_s_play.cpp",0xd6f,"l_lkDemoAnmCommand->getArchive()");
      m_Do_printf::OSPanic("d_s_play.cpp",0xd6f,"Halt");
    }
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLkDArc = l_lkDemoAnmCommand->mpArchive;
    if (l_lkDemoAnmCommand != (mDoDvdThd_mountXArchive_c *)0x0) {
      (*(code *)((l_lkDemoAnmCommand->parent).vtbl)->_mDoDvdThd_toMainRam_c)(l_lkDemoAnmCommand,1);
    }
  }
  if (param_1 == (dScnPly_ply_c *)0x0) {
    dStage_roomControl_c::mProcID = 0xffffffff;
  }
  else {
    dStage_roomControl_c::mProcID = (param_1->parent).parent.parent.mBsPcId;
  }
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName._0_4_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mStageName._0_4_;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName._4_4_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mStageName._4_4_;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mRoomNo =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mRoomNo;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStartCode =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mStartCode;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mLayerNo =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mLayerNo;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext = 0;
  JUtility::JUTReportConsole_f
            ("Start StageName:RoomNo [%s:%d]\n",0x803c9d3c,
             (int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mStartCode);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVrboxFlags = 0;
  pdVar4 = &d_com_inf_game::g_dComIfG_gameInfo.mResCtrl;
  iVar2 = dRes_control_c::setStageRes
                    (&d_com_inf_game::g_dComIfG_gameInfo.mResCtrl,"Stage",(JKRHeap *)0x0);
  if (iVar2 != 1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_s_play.cpp",0xd82,"rt == 1");
    m_Do_printf::OSPanic("d_s_play.cpp",0xd82,"Halt");
  }
  pJVar3 = (J3DMaterialTable *)
           dRes_control_c::getRes
                     ("Always",0x57,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  this = (dMat_control_c *)
         dRes_control_c::getRes
                   ("Always",0x41,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  dMat_control_c::create(this,pJVar3,(J3DAnmTextureSRTKey *)pdVar4);
  return 2;
}


/* __stdcall phase_2(dScnPly_ply_c *) */

undefined4 phase_2(dScnPly_ply_c *pPly)

{
  int iVar1;
  ulong uVar2;
  undefined4 uVar3;
  stage_stag_info_class *pStag;
  
  iVar1 = dRes_control_c::syncRes
                    ("Stage",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
  if (iVar1 < 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_s_play.cpp",0xd9d,"rt >= 0");
    m_Do_printf::OSPanic("d_s_play.cpp",0xd9d,"Halt");
  }
  if (iVar1 == 0) {
    d_stage::dStage_infoCreate();
    pStag = (stage_stag_info_class *)
            (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
    dPa_control_c::readScene
              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,
               (uchar)((ushort)pStag->mParticleSceneNo >> 3),&pPly->mpToMainRam);
    uVar3 = 2;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* __stdcall phase_3(dScnPly_ply_c *) */

undefined4 phase_3(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*(int *)(param_1 + 0x1cc) == 0) || (*(char *)(*(int *)(param_1 + 0x1cc) + 0xc) != '\0')) &&
     (iVar1 = JAIZelBasic::check1stDynamicWave(JAIZelBasic::zel_basic), iVar1 == 0)) {
    uVar2 = 2;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8023630c) */
/* WARNING: Removing unreachable block (ram,0x80236314) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall phase_4(dScnPly_ply_c *) */

undefined4 phase_4(dScnPly_ply_c *pPly)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  JFWDisplay *pJVar4;
  dItem_data__ItemNo dVar5;
  byte bVar6;
  ulong uVar7;
  mDoDvdThd_toMainRam_c *pmVar8;
  int iVar9;
  JKRExpHeap *pJVar10;
  undefined4 uVar11;
  EVP_PKEY_CTX *ctx;
  undefined4 uVar12;
  uint uVar13;
  byte *pbVar14;
  int iVar15;
  undefined4 uVar16;
  undefined8 in_f30;
  double dVar17;
  undefined8 in_f31;
  double dVar18;
  undefined8 uVar19;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar16 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (pPly->mpToMainRam == (mDoDvdThd_toMainRam_c *)0x0) {
    dPa_control_c::createScene(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,(void *)0x0);
  }
  else {
    if (pPly->mpToMainRam->mpArchiveHeader == (JKRArchive__Header *)0x0) {
      uVar7 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar7,"d_s_play.cpp",0xdef,"i_this->sceneCommand->getMemAddress() != 0");
      m_Do_printf::OSPanic("d_s_play.cpp",0xdef,"Halt");
    }
    dPa_control_c::createScene
              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,
               pPly->mpToMainRam->mpArchiveHeader);
    pmVar8 = pPly->mpToMainRam;
    if (pmVar8 != (mDoDvdThd_toMainRam_c *)0x0) {
      (*(code *)((pmVar8->parent).vtbl)->_mDoDvdThd_toMainRam_c)(pmVar8,1);
    }
  }
  (**(code **)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS.parent.field_0x1400 + 0xc))(0x803c5ea8)
  ;
  dCcS::Ct(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS);
  dComIfG_play_c::createDemo(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
  d_a_sea::daSea_Init();
  d_snap::dSnap_Create();
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor = (daPy_lk_c *)0x0;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera = 0;
  iVar9 = 0;
  iVar15 = 3;
  do {
    *(undefined4 *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor + iVar9 + 8) = 0;
    iVar9 = iVar9 + 4;
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 1;
  fVar1 = (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(mDoMch_render_c::mRenderModeObj + 6)
                                  ) - _5398);
  dVar17 = (double)fVar1;
  fVar2 = (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(mDoMch_render_c::mRenderModeObj + 4)
                                  ) - _5398);
  dVar18 = (double)fVar2;
  dDlst_window_c::setViewPort
            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow,0_0,0_0,fVar2,fVar1,0_0,_5396);
  dDlst_window_c::setScissor
            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow,0_0,0_0,(float)dVar18,
             (float)dVar17);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCameraInfo = 0;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18541_1_ = 2;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera = (camera_class *)0x0;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mDlstWindowIdx = 0;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mCamIdx = 0;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0x6 = 0xff;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0x8 = 0;
  d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x22c = (dDlst_window_c *)0x0;
  d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x230 = (dDlst_window_c *)0x0;
  d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera = (camera_class *)0x0;
  pJVar10 = (JKRExpHeap *)f_op_msg_mng::fopMsgM_createExpHeap(0x73ea1);
  if (pJVar10 == (JKRExpHeap *)0x0) {
    uVar7 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar7,"d_s_play.cpp",0xe45,"heap != 0");
    m_Do_printf::OSPanic("d_s_play.cpp",0xe45,"Halt");
  }
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5c1c = pJVar10;
  d_stage::dStage_Create();
  pJVar4 = JFWDisplay::sManager;
  *(uint *)&JFWDisplay::sManager->field_0x24 = (DAT_800000f8 >> 2) / 0x1e;
  *(undefined2 *)&pJVar4->field_0x20 = 0;
  g_darkHIO._4_1_ =
       mDoHIO_subRoot_c::createChild
                 (&mDoHIO_subRoot_c_803a5778,"暗闇スポット",(JORReflexible *)&g_darkHIO);
  DAT_803e7d0c = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"描画設定",(JORReflexible *)&g_envHIO);
  DAT_803e7d98 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"Message Data",(JORReflexible *)&g_msgDHIO);
  dAttention_c::dAttention_c
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,
             (fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor,0);
  uVar19 = dVibration_c::Init(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration);
  ctx = (EVP_PKEY_CTX *)uVar19;
  daSteamTag_c::init((daSteamTag_c *)((ulonglong)uVar19 >> 0x20),ctx);
  _m_emitter = 0;
  daYkgr_c::m_flag = 0;
  daYkgr_c::m_alpha_flag = 1;
  daYkgr_c::m_alpha = 0xff;
  daSalvage_c::mNowRoomNo = 0xff;
  _mTagData_p = 0;
  _mSalvageId = 0xffffffff;
  daDai_c::mNowDaizaNum = 0;
  daDai_c::mNowItemNum = 0;
  daNpc_Kg2_c::canon_game_result = 0;
  daIball_c::init((daIball_c *)0x0,ctx);
  d_com_inf_game::g_dComIfG_gameInfo.field_0x1d1c1 = 0xff;
  mDoGph_gInf_c::mFade = 0;
  iVar9 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  if (((iVar9 != 0) && ((*(uint *)(iVar9 + 0xc) >> 0x10 & 7) == 5)) &&
     (iVar9 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x801), iVar9 != 0
     )) {
    d_com_inf_game::dComIfGs_setSelectEquip(0,InvalidItem);
    d_com_inf_game::g_dComIfG_gameInfo._23511_1_ = 0xff;
    dSv_player_collect_c::offCollect
              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,'\0');
  }
  iVar9 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"GTower");
  if (iVar9 == 0) {
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot = InvalidItem;
    iVar9 = 0;
    iVar15 = 3;
    do {
      dVar5 = d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar9];
      if (((dVar5 == HerosBow) || (dVar5 == FireAndIceArrows)) || (dVar5 == LightArrow)) {
        dVar5 = InvalidItem;
        pbVar14 = (byte *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                           mInventorySlotIndexOnButton + iVar9);
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
        mInventorySlotIndexOnButton[iVar9] = -1;
        uVar13 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                             mInventorySlotIndexOnButton[iVar9];
        if (uVar13 == 0xff) {
          d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar9] = InvalidItem;
        }
        else {
          if (uVar13 < 0x15) {
            dVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                    mStageName[uVar13];
          }
          else {
            if (0x17 < uVar13) {
              if (uVar13 < 0x20) {
                dVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar13 + 0xd];
              }
              else {
                if (0x23 < uVar13) {
                  if (uVar13 < 0x2c) {
                    dVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar13 + 9];
                  }
                  else {
                    if ((0x2f < uVar13) && (uVar13 < 0x38)) {
                      dVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar13 + 5];
                    }
                  }
                }
              }
            }
          }
          d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar9] = dVar5;
          uVar13 = (uint)*pbVar14;
          if (uVar13 < 0x15) {
            bVar6 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                    mStageName[uVar13];
          }
          else {
            if (uVar13 < 0x18) {
              bVar6 = 0xff;
            }
            else {
              if (uVar13 < 0x20) {
                bVar6 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar13 + 0xd];
              }
              else {
                if (uVar13 < 0x24) {
                  bVar6 = 0xff;
                }
                else {
                  if (uVar13 < 0x2c) {
                    bVar6 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar13 + 9];
                  }
                  else {
                    if (uVar13 < 0x30) {
                      bVar6 = 0xff;
                    }
                    else {
                      if (uVar13 < 0x38) {
                        bVar6 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                mBits[uVar13 + 5];
                      }
                      else {
                        bVar6 = 0xff;
                      }
                    }
                  }
                }
              }
            }
          }
          if (bVar6 == 0xff) {
            *pbVar14 = 0xff;
          }
        }
      }
      iVar9 = iVar9 + 1;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot == InvalidItem) {
      uVar13 = dSv_player_get_item_c::isItem
                         (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xc,2);
      if (uVar13 == 0) {
        uVar13 = dSv_player_get_item_c::isItem
                           (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xc,1
                           );
        if (uVar13 == 0) {
          uVar13 = dSv_player_get_item_c::isItem
                             (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xc
                              ,0);
          if (uVar13 != 0) {
            d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot = HerosBow;
          }
        }
        else {
          d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot = FireAndIceArrows
          ;
        }
      }
      else {
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot = LightArrow;
      }
    }
  }
  iVar9 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss0");
  if ((((iVar9 == 0) ||
       (iVar9 = MSL_C.PPCEABI.bare.H::strcmp
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss1"),
       iVar9 == 0)) ||
      (iVar9 = MSL_C.PPCEABI.bare.H::strcmp
                         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss2"),
      iVar9 == 0)) ||
     (iVar9 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss3"),
     iVar9 == 0)) {
    d_com_inf_game::dComIfGs_setPlayerRecollectionData();
  }
  JAIZelBasic::monsSeInit(JAIZelBasic::zel_basic);
  uVar13 = countLeadingZeros(7 - (pPly->parent).parent.parent.mProcName);
  mDoAud_zelAudio_c::mBgmSet = (byte)(uVar13 >> 5);
  ::dScnPly_ply_c::pauseTimer = 0;
  ::dScnPly_ply_c::nextPauseTimer = 0;
  iVar9 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Hyrule");
  if (((((iVar9 == 0) ||
        (iVar9 = MSL_C.PPCEABI.bare.H::strcmp
                           (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Hyroom"),
        iVar9 == 0)) ||
       (iVar9 = MSL_C.PPCEABI.bare.H::strcmp
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"kenroom"),
       iVar9 == 0)) &&
      (iVar9 = dSv_event_c::isEventBit
                         (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3802),
      iVar9 == 0)) || (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName[0] == 'X')) {
    mDoGph_gInf_c::onMonotone();
    bVar3 = false;
    iVar9 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Hyrule");
    if ((iVar9 == 0) && (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mLayerNo == 8)) {
      bVar3 = true;
    }
    mDoGph_gInf_c::mMonotoneRate = 400;
    if (bVar3) {
      mDoGph_gInf_c::mMonotoneRate = -600;
    }
    mDoGph_gInf_c::mMonotoneRateSpeed = 0;
  }
  else {
    mDoGph_gInf_c::offMonotone();
  }
  preLoadNo = -1;
  if (doPreLoad != '\0') {
    uVar13 = 0;
    iVar9 = 0;
    do {
      iVar15 = MSL_C.PPCEABI.bare.H::strcmp
                         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                          *(char **)((int)&PreLoadInfoT + iVar9));
      if (iVar15 == 0) {
        preLoadNo = (char)uVar13;
      }
      uVar13 = uVar13 + 1;
      iVar9 = iVar9 + 0x10;
    } while (uVar13 < 0x10);
  }
  uVar12 = 0;
  *mDoRst::mResetData = 0;
  mDoRst::mResetData[1] = 0;
  JUTGamePad::C3ButtonReset::sResetOccurred = 0;
  _sCallback = m_Do_Reset::mDoRst_resetCallBack;
  _sCallbackArg = 0;
  if (preLoadNo < '\0') {
    uVar11 = 4;
  }
  else {
    resPreLoadTime0 = os::OSGetTime();
    uVar11 = 2;
    DAT_803f72c4 = uVar12;
  }
  __psq_l0(auStack8,uVar16);
  __psq_l1(auStack8,uVar16);
  __psq_l0(auStack24,uVar16);
  __psq_l1(auStack24,uVar16);
  return uVar11;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall phase_5(dScnPly_ply_c *) */

int phase_5(void)

{
  byte bVar1;
  ulong uVar2;
  PhaseState PVar3;
  char *pcVar4;
  char *extraout_r4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  pcVar4 = (char *)(uint)preLoadNo;
  if ((char)preLoadNo < '\0') {
    iVar7 = 2;
  }
  else {
    iVar7 = 2;
    piVar6 = (int *)(&PTR_sea_resName_80363128)[(char)preLoadNo * 4];
    bVar1 = (&DAT_8036312d)[(char)preLoadNo * 0x10];
    if ((piVar6 != (int *)0x0) && (*piVar6 != 0)) {
      if (0x23 < bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar2,"d_s_play.cpp",0xef0,
                   "resNameNum <= (sizeof(resPhase) / sizeof(resPhase[0]))");
        m_Do_printf::OSPanic("d_s_play.cpp",0xef0,"Halt");
        pcVar4 = extraout_r4;
      }
      iVar9 = 0;
      iVar8 = 0;
      for (iVar5 = 0; iVar5 < (int)(uint)bVar1; iVar5 = iVar5 + 1) {
        pcVar4 = *(char **)((int)piVar6 + iVar9);
        PVar3 = d_com_inf_game::dComIfG_resLoad
                          ((request_of_phase_process_class *)((int)&resPhase[0].mpTbl + iVar8),
                           pcVar4);
        if (PVar3 != cPhs_COMPLEATE_e) {
          iVar7 = 0;
        }
        iVar9 = iVar9 + 4;
        iVar8 = iVar8 + 8;
      }
    }
    if (iVar7 == 4) {
      resPreLoadTime1 = os::OSGetTime();
      DAT_803f72cc = pcVar4;
    }
  }
  return iVar7;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall phase_6(dScnPly_ply_c *) */

int phase_6(undefined4 param_1,undefined4 param_2,char *param_3)

{
  byte bVar1;
  ulong uVar2;
  uint uVar3;
  uint extraout_r4;
  int iVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  
  uVar3 = (uint)preLoadNo;
  if ((char)preLoadNo < '\0') {
    iVar6 = 2;
  }
  else {
    iVar6 = 2;
    psVar5 = (short *)(&PTR_sea_dylKeyTbl_80363124)[(char)preLoadNo * 4];
    bVar1 = (&DAT_8036312c)[(char)preLoadNo * 0x10];
    if ((psVar5 != (short *)0x0) && (*psVar5 != 0)) {
      if (0x1b < bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar2,"d_s_play.cpp",0xf12,
                   "dylKeyTblNum <= (sizeof(dylPhase) / sizeof(dylPhase[0]))");
        param_3 = "Halt";
        m_Do_printf::OSPanic("d_s_play.cpp",0xf12);
        uVar3 = extraout_r4;
      }
      iVar8 = 0;
      iVar7 = 0;
      for (iVar4 = 0; iVar4 < (int)(uint)bVar1; iVar4 = iVar4 + 1) {
        uVar9 = cDylPhs::Link((cDylPhs *)(&dylPhase + iVar7),
                              (request_of_phase_process_class *)(int)*(short *)((int)psVar5 + iVar8)
                              ,(short)param_3);
        uVar3 = (uint)uVar9;
        if ((int)((ulonglong)uVar9 >> 0x20) != 4) {
          iVar6 = 0;
        }
        iVar8 = iVar8 + 2;
        iVar7 = iVar7 + 8;
      }
    }
    if (iVar6 == 4) {
      dylPreLoadTime1 = os::OSGetTime();
      DAT_803f72bc = uVar3;
    }
  }
  return iVar6;
}


/* __stdcall phase_compleate(void *) */

undefined4 phase_compleate(void)

{
  return 4;
}


/* __stdcall dScnPly_Create(scene_class *) */

void dScnPly_Create(dScnPly_ply_c *param_1)

{
  d_com_lib_game::dComLbG_PhaseHandler(&param_1->mLoadPhs,(cPhs__Handler *)&l_method_5457,param_1);
  return;
}

}

/* __thiscall dScnPly_msg_HIO_c::~dScnPly_msg_HIO_c(void) */

void __thiscall dScnPly_msg_HIO_c::_dScnPly_msg_HIO_c(dScnPly_msg_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dScnPly_msg_HIO_c *)0x0) && (*(undefined ***)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dScnPly_env_debugHIO_c::~dScnPly_env_debugHIO_c(void) */

void __thiscall dScnPly_env_debugHIO_c::_dScnPly_env_debugHIO_c(dScnPly_env_debugHIO_c *this)

{
  short in_r4;
  
  if ((this != (dScnPly_env_debugHIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dScnPly_env_otherHIO_c::~dScnPly_env_otherHIO_c(void) */

void __thiscall dScnPly_env_otherHIO_c::_dScnPly_env_otherHIO_c(dScnPly_env_otherHIO_c *this)

{
  short in_r4;
  
  if ((this != (dScnPly_env_otherHIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dScnPly_reg_childHIO_c::~dScnPly_reg_childHIO_c(void) */

void __thiscall dScnPly_reg_childHIO_c::_dScnPly_reg_childHIO_c(dScnPly_reg_childHIO_c *this)

{
  short in_r4;
  
  if ((this != (dScnPly_reg_childHIO_c *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dScnPly_dark_HIO_c::~dScnPly_dark_HIO_c(void) */

void __thiscall dScnPly_dark_HIO_c::_dScnPly_dark_HIO_c(dScnPly_dark_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dScnPly_dark_HIO_c *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_s_play {

void __sinit_d_s_play_cpp(void)

{
  ::dScnPly_dark_HIO_c::dScnPly_dark_HIO_c(&g_darkHIO);
  Runtime.PPCEABI.H::__register_global_object();
  g_regHIO.vtbl = (undefined *)&::dScnPly_reg_HIO_c::__vt;
  Runtime.PPCEABI.H::__construct_array
            (g_regHIO.mChild,::dScnPly_reg_childHIO_c::dScnPly_reg_childHIO_c,
             ::dScnPly_reg_childHIO_c::_dScnPly_reg_childHIO_c,0x90,0x16);
  Runtime.PPCEABI.H::__register_global_object
            (&g_regHIO,::dScnPly_reg_HIO_c::_dScnPly_reg_HIO_c,0x803e7088);
  g_envHIO = &::dScnPly_env_HIO_c::__vt;
  ::dScnPly_env_otherHIO_c::dScnPly_env_otherHIO_c((dScnPly_env_otherHIO_c *)&DAT_803e7d10);
  ::dScnPly_env_debugHIO_c::dScnPly_env_debugHIO_c((dScnPly_env_debugHIO_c *)&DAT_803e7d58);
  Runtime.PPCEABI.H::__register_global_object
            (&g_envHIO,::dScnPly_env_HIO_c::_dScnPly_env_HIO_c,&_4236);
  ::dScnPly_msg_HIO_c::dScnPly_msg_HIO_c(&g_msgDHIO);
  Runtime.PPCEABI.H::__register_global_object();
  g_preLoadHIO = &::dScnPly_preLoad_HIO_c::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&g_preLoadHIO,::dScnPly_preLoad_HIO_c::_dScnPly_preLoad_HIO_c,&_4574);
  return;
}

}

/* __thiscall dScnPly_preLoad_HIO_c::~dScnPly_preLoad_HIO_c(void) */

void __thiscall dScnPly_preLoad_HIO_c::_dScnPly_preLoad_HIO_c(dScnPly_preLoad_HIO_c *this)

{
  short in_r4;
  
  if (this != (dScnPly_preLoad_HIO_c *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (dScnPly_preLoad_HIO_c *)0x0) {
      *(undefined1 **)this = &::mDoHIO_entry_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dScnPly_env_HIO_c::~dScnPly_env_HIO_c(void) */

void __thiscall dScnPly_env_HIO_c::_dScnPly_env_HIO_c(dScnPly_env_HIO_c *this)

{
  short in_r4;
  
  if (this != (dScnPly_env_HIO_c *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (dScnPly_env_HIO_c *)0xffffffb0) {
      *(undefined1 **)(this + 0x50) = &dScnPly_env_debugHIO_c::__vt;
    }
    if (this != (dScnPly_env_HIO_c *)&DAT_fffffff8) {
      *(undefined1 **)(this + 8) = &dScnPly_env_otherHIO_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dScnPly_reg_HIO_c::~dScnPly_reg_HIO_c(void) */

void __thiscall dScnPly_reg_HIO_c::_dScnPly_reg_HIO_c(dScnPly_reg_HIO_c *this)

{
  short in_r4;
  
  if (this != (dScnPly_reg_HIO_c *)0x0) {
    this->vtbl = (undefined *)&__vt;
    Runtime.PPCEABI.H::__destroy_arr
              (this->mChild,dScnPly_reg_childHIO_c::_dScnPly_reg_childHIO_c,0x90,0x16);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

