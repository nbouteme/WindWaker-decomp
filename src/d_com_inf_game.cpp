#include <d_com_inf_game.h>
#include <d_com_inf_game.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_com_static.h>
#include <d_kankyo.h>
#include <d_save.h>
#include <JKernel/JKRHeap.h>
#include <d_particle.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_demo.h>
#include <d_event_manager.h>
#include <d_magma.h>
#include <d_grass.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <d_flower.h>
#include <d_tree.h>
#include <d_wood.h>
#include <m_Do_audio.h>
#include <f_op_scene_mng.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_resorce.h>
#include <d_com_lib_game.h>
#include <d_stage.h>
#include <SComponent/c_bg_s.h>
#include <d_drawlist.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <SComponent/c_cc_s.h>
#include <d_cc_mass_s.h>
#include <d_s_actor_data_mng.h>
#include <d_event.h>
#include <d_event_data.h>
#include <d_vibration.h>
#include <d_detect.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <d_attention.h>
#include <dTree_anm_c.h>
#include <dGrass_packet_c.h>
#include <dSv_zone_c.h>
#include <dComIfG_inf_c.h>
#include <cM3dGAab.h>
#include <dComIfG_play_c.h>
#include <dDlst_window_c.h>
#include <dFlower_packet_c.h>
#include <dTree_data_c.h>
#include <Demangler/mDoExt_McaMorfCallBack1_c.h>
#include <dEvt_order_c.h>
#include <dCcMassS_Mng.h>
#include <cBgS_ChkElm.h>
#include <dComIfG_camera_info_class.h>
#include <dCcS.h>
#include <cCcD_DivideInfo.h>
#include <dBgS.h>
#include <dCcMassS_Obj.h>
#include <cM3dGCps.h>
#include <dGrass_data_c.h>
#include <cCcD_DivideArea.h>
#include <dSv_memory_c.h>
#include <dAttDraw_CallBack_c.h>
#include <cM3dGCyl.h>
#include <dFlower_data_c.h>
#include <dTree_packet_c.h>
#include <cCcS.h>
#include <cCcD_ShapeAttr.h>
#include <cBgS.h>


namespace d_com_inf_game {
struct dComIfG_inf_c g_dComIfG_gameInfo;
}

/* __thiscall dComIfG_play_c::ct(void) */

void __thiscall dComIfG_play_c::ct(dComIfG_play_c *this)

{
  float fVar1;
  
  this->field_0x4841 = 0;
  this->mParticleCtrl = (dPa_control_c *)0x0;
  this->mpDemoMgr = (dDemo_manager_c *)0x0;
  this->mpMagmaPacket = (dMagma_packet_c *)0x0;
  this->mpGrassPacket = (dGrass_packet_c *)0x0;
  this->mpTreePacket = (dTree_packet_c *)0x0;
  this->mpWoodPacket = (Packet_c *)0x0;
  this->mpFlowerPacket = (dFlower_packet_c *)0x0;
  *(undefined *)&this[1].mBgS.parent.mChkElm[0x12].mProcID = 0xff;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[0x12].mProcID + 1) = 0xff;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[0x12].mProcID + 2) = 0xff;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[0x12].mProcID + 3) = 0xff;
  fVar1 = d_com_inf_game::0_0;
  this[1].mBgS.parent.mChkElm[0x12].mpActorPtr = (fopAc_ac_c *)d_com_inf_game::0_0;
  this[1].mBgS.parent.mChkElm[0x12].vtbl = (undefined *)fVar1;
  this[1].mBgS.parent.mChkElm[0x13].mpBgW = (dBgW *)fVar1;
  this->mLkDArcIdx = 0xff;
  init(this);
  return;
}


/* __thiscall dComIfG_play_c::init(void) */

int __thiscall dComIfG_play_c::init(dComIfG_play_c *this)

{
  int iVar1;
  int iVar2;
  
  this->mpCurPlayerActor[0] = (daPy_lk_c *)0x0;
  this->mCurCamera = 0xff;
  iVar1 = 0;
  iVar2 = 3;
  do {
    *(undefined4 *)((int)this->mpCurPlayerActor + iVar1 + 8) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return (int)this;
}


/* __thiscall dComIfG_play_c::itemInit(void) */

void __thiscall dComIfG_play_c::itemInit(dComIfG_play_c *this)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  uchar uVar4;
  int iVar5;
  int iVar6;
  
  fVar1 = d_com_inf_game::0_0;
  *(float *)&this->field_0x48b8 = d_com_inf_game::0_0;
  this->mAdjustHp = (int)fVar1;
  this->mAdjustRupees = 0;
  this->mAirMeter = 0;
  this->field_0x48c8 = 0;
  this->mNpcNameMessageID = 0;
  this->mItemNameMessageID = 0;
  this->field_0x48d4 = 0;
  this->mCollectHeartPieceCount = 0;
  *(undefined2 *)&this->field_0x48d8 = 0;
  *(undefined2 *)&this->field_0x48da = 0;
  *(undefined2 *)&this->field_0x48dc = 0;
  *(undefined2 *)&this->field_0x48de = 0;
  this->field_0x48e0 = 0;
  *(undefined2 *)&this->field_0x48e2 = 0;
  *(undefined2 *)&this->field_0x48e4 = 0;
  *(undefined2 *)&this->field_0x48e6 = 0;
  iVar5 = 4;
  do {
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(undefined2 *)&this[1].mBgS.parent.mChkElm[1].vtbl = 0;
  *(undefined2 *)((int)&this[1].mBgS.parent.mChkElm[1].vtbl + 2) = 0;
  *(undefined2 *)&this[1].mBgS.parent.mChkElm[2].mpBgW = 0;
  *(undefined2 *)((int)&this[1].mBgS.parent.mChkElm[2].mpBgW + 2) = 0;
  *(undefined2 *)&this[1].mBgS.parent.mChkElm[2].mFlags = 0;
  *(undefined2 *)((int)&this[1].mBgS.parent.mChkElm[2].mFlags + 2) = 0;
  *(undefined2 *)&this[1].mBgS.parent.mChkElm[2].mProcID = 0;
  *(undefined2 *)((int)&this[1].mBgS.parent.mChkElm[2].mProcID + 2) = 0;
  *(undefined *)&this[1].mBgS.parent.mChkElm[2].mpActorPtr = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[2].mpActorPtr + 1) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[2].mpActorPtr + 2) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[2].mpActorPtr + 3) = 0;
  *(undefined *)&this[1].mBgS.parent.mChkElm[2].vtbl = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[2].vtbl + 1) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[2].vtbl + 2) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[2].vtbl + 3) = 0;
  *(undefined *)&this[1].mBgS.parent.mChkElm[3].mpBgW = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[3].mpBgW + 1) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[3].mpBgW + 2) = 0;
  iVar5 = 0;
  iVar6 = 4;
  do {
    iVar3 = (int)&(this->mBgS).parent.mChkElm[0].mpBgW + iVar5;
    *(undefined *)(iVar3 + 0x4933) = 0;
    *(undefined *)(iVar3 + 0x4937) = 0;
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[3].mProcID + 3) = 0;
  *(undefined *)&this[1].mBgS.parent.mChkElm[3].mpActorPtr = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[3].mpActorPtr + 1) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[3].mpActorPtr + 2) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[3].mpActorPtr + 3) = 0;
  *(undefined *)&this[1].mBgS.parent.mChkElm[3].vtbl = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[3].vtbl + 1) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[3].vtbl + 2) = 0;
  bVar2 = d_com_inf_game::dComIfGs_checkGetItem(Telescope);
  if (bVar2 == false) {
    *(undefined *)((int)&this[1].mBgS.parent.mChkElm[3].vtbl + 3) = 0x15;
  }
  else {
    *(undefined *)((int)&this[1].mBgS.parent.mChkElm[3].vtbl + 3) = 0;
  }
  *(undefined *)&this[1].mBgS.parent.mChkElm[4].mpBgW = 7;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[4].mpBgW + 1) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[4].mpBgW + 2) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[4].mpBgW + 3) = 0;
  *(undefined *)&this[1].mBgS.parent.mChkElm[4].mFlags = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[4].mFlags + 1) = 0;
  iVar5 = 0;
  iVar6 = 6;
  do {
    *(undefined *)((int)&this[1].mBgS.parent.mChkElm[4].mFlags + iVar5 + 2) = 0;
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *(undefined *)&this[1].mBgS.parent.mChkElm[4].mpActorPtr = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[4].mpActorPtr + 1) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[4].mpActorPtr + 2) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[4].mpActorPtr + 3) = 0;
  *(undefined *)&this[1].mBgS.parent.mChkElm[4].vtbl = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[4].vtbl + 1) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[4].vtbl + 2) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[4].vtbl + 3) = 0;
  *(undefined *)&this[1].mBgS.parent.mChkElm[5].mpBgW = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[5].mpBgW + 1) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[5].mpBgW + 2) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[5].mpBgW + 3) = 0;
  *(undefined *)&this[1].mBgS.parent.mChkElm[5].mFlags = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[5].mFlags + 1) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[5].mFlags + 2) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[5].mFlags + 3) = 0;
  *(undefined *)&this[1].mBgS.parent.mChkElm[5].mProcID = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[5].mProcID + 1) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[5].mProcID + 2) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[5].mpActorPtr + 1) = 0;
  uVar4 = '0';
  MSL_C.PPCEABI.bare.H::strcpy((char *)((int)&this[1].mBgS.parent.mChkElm[5].mpActorPtr + 2),"");
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[6].mProcID + 3) = 0;
  *(undefined *)&this[1].mBgS.parent.mChkElm[6].mpActorPtr = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[6].mpActorPtr + 1) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[6].mpActorPtr + 2) = 0;
  *(undefined *)((int)&this[1].mBgS.parent.mChkElm[5].mProcID + 3) =
       d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._3_1_;
  daArrow_c::setKeepType((daArrow_c *)0x0,uVar4);
  this[1].mBgS.parent.mChkElm[7].mpBgW = (dBgW *)0x0;
  this[1].mBgS.parent.mChkElm[7].mFlags = 0;
  iVar5 = 0;
  iVar6 = 10;
  do {
    *(undefined4 *)((int)&this[1].mBgS.parent.mChkElm[7].mProcID + iVar5) = 0;
    iVar5 = iVar5 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return;
}


namespace dComIfG_play_c {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall getLayerNo(int) */

uint getLayerNo(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = SEXT14((char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mLayerNo);
  if ((int)uVar2 < 0) {
    iVar3 = d_kankyo::dKy_getdaytime_hour();
    iVar4 = d_kankyo::dKy_checkEventNightStop();
    if (iVar4 == 0) {
      uVar1 = 0;
      if ((5 < iVar3) && (iVar3 < 0x12)) {
        uVar1 = 1;
      }
      uVar2 = countLeadingZeros(uVar1);
      uVar2 = uVar2 >> 5;
    }
    else {
      uVar2 = 1;
    }
    iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea");
    if (iVar3 == 0) {
      if (param_1 == 0x2c) {
        iVar3 = dSv_event_c::isEventBit
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x520);
        if (iVar3 == 0) {
          iVar3 = dSv_event_c::isEventBit
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xe20);
          if (iVar3 == 0) {
            iVar3 = dSv_event_c::isEventBit
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x101);
            if (iVar3 != 0) {
              uVar2 = 9;
            }
          }
          else {
            uVar2 = uVar2 | 2;
          }
        }
        else {
          uVar2 = uVar2 | 4;
        }
      }
      else {
        if (param_1 == 0xb) {
          iVar3 = dSv_event_c::isEventBit
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2d01);
          if (iVar3 == 0) {
            iVar3 = d_kankyo::dKy_checkEventNightStop();
            if (iVar3 != 0) {
              uVar2 = uVar2 | 2;
            }
          }
          else {
            uVar2 = uVar2 | 4;
          }
        }
        else {
          if (param_1 == 1) {
            iVar3 = dSv_event_c::isEventBit
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1820);
            uVar2 = 1;
            if (iVar3 != 0) {
              uVar2 = 3;
            }
          }
        }
      }
    }
    else {
      iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"A_mori");
      if (iVar3 == 0) {
        iVar3 = dSv_event_c::isEventBit
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xf80);
        if (iVar3 != 0) {
          uVar2 = uVar2 | 2;
        }
      }
      else {
        iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Asoko");
        if (iVar3 == 0) {
          iVar3 = dSv_event_c::isEventBit
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x520);
          if (iVar3 != 0) {
            uVar2 = uVar2 | 2;
          }
        }
        else {
          iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Hyrule")
          ;
          if (iVar3 == 0) {
            iVar3 = dSv_player_collect_c::getTriforceNum
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect);
            if (iVar3 == 8) {
              uVar2 = uVar2 | 4;
            }
            else {
              iVar3 = dSv_event_c::isEventBit
                                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3280);
              if (iVar3 != 0) {
                uVar2 = uVar2 | 2;
              }
            }
          }
          else {
            iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                               "Hyroom");
            if (iVar3 == 0) {
              iVar3 = dSv_player_collect_c::getTriforceNum
                                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect)
              ;
              if ((iVar3 == 8) &&
                 (iVar3 = dSv_event_c::isEventBit
                                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2c01
                                    ), iVar3 == 0)) {
                uVar2 = uVar2 | 4;
              }
              else {
                iVar3 = dSv_event_c::isEventBit
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3280);
                if (iVar3 == 0) {
                  iVar3 = dSv_event_c::isEventBit
                                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3b40
                                    );
                  if (iVar3 != 0) {
                    uVar2 = uVar2 | 6;
                  }
                }
                else {
                  uVar2 = uVar2 | 2;
                }
              }
            }
            else {
              iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                                (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                 "kenroom");
              if (iVar3 == 0) {
                iVar3 = dSv_event_c::isEventBit
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2c01);
                if ((iVar3 == 0) &&
                   ((iVar3 = dSv_event_c::isEventBit
                                       (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,
                                        0x3802), iVar3 == 0 ||
                    (iVar3 = dSv_event_c::isEventBit
                                       (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,
                                        0x3280), iVar3 != 0)))) {
                  iVar3 = dSv_player_collect_c::getTriforceNum
                                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                      mCollect);
                  if (iVar3 == 8) {
                    uVar2 = uVar2 | 4;
                  }
                  else {
                    iVar3 = dSv_event_c::isEventBit
                                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,
                                       0x3802);
                    if (iVar3 != 0) {
                      uVar2 = uVar2 | 2;
                    }
                  }
                }
                else {
                  uVar2 = uVar2 | 6;
                }
              }
              else {
                iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                                  (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                   "M2tower");
                if (iVar3 == 0) {
                  iVar3 = dSv_event_c::isEventBit
                                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2d01
                                    );
                  if (iVar3 != 0) {
                    uVar2 = uVar2 | 2;
                  }
                }
                else {
                  iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                     "GanonK");
                  if (iVar3 == 0) {
                    iVar3 = dSv_event_c::isEventBit
                                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,
                                       0x3b02);
                    if (iVar3 == 0) {
                      uVar2 = 8;
                    }
                  }
                  else {
                    iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName
                                       ,"GTower");
                    if ((iVar3 == 0) &&
                       (iVar3 = dSv_event_c::isEventBit
                                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,
                                           0x4002), iVar3 == 0)) {
                      uVar2 = 8;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar2;
}

}

/* __thiscall dComIfG_play_c::createParticle(void) */

void __thiscall dComIfG_play_c::createParticle(dComIfG_play_c *this)

{
  dPa_control_c *this_00;
  ulong uVar1;
  
  this_00 = (dPa_control_c *)JKernel::operator_new(0x402c);
  if (this_00 != (dPa_control_c *)0x0) {
    dPa_control_c::dPa_control_c(this_00);
  }
  this->mParticleCtrl = this_00;
  if (this->mParticleCtrl == (dPa_control_c *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_com_inf_game.cpp",0x168,"mParticle != 0");
    m_Do_printf::OSPanic("d_com_inf_game.cpp",0x168,&DAT_8034f591);
  }
  return;
}


/* __thiscall dComIfG_play_c::createDemo(void) */

void __thiscall dComIfG_play_c::createDemo(dComIfG_play_c *this)

{
  dDemo_manager_c *this_00;
  ulong uVar1;
  
  this_00 = (dDemo_manager_c *)JKernel::operator_new(0xe0);
  if (this_00 != (dDemo_manager_c *)0x0) {
    dDemo_manager_c::dDemo_manager_c(this_00);
  }
  this->mpDemoMgr = this_00;
  if (this->mpDemoMgr == (dDemo_manager_c *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_com_inf_game.cpp",0x186,"mDemo != 0");
    m_Do_printf::OSPanic("d_com_inf_game.cpp",0x186,&DAT_8034f591);
  }
  return;
}


/* __thiscall dComIfG_play_c::removeDemo(void) */

void __thiscall dComIfG_play_c::removeDemo(dComIfG_play_c *this)

{
  dDemo_manager_c::_dDemo_manager_c(this->mpDemoMgr);
  this->mpDemoMgr = (dDemo_manager_c *)0x0;
  return;
}


/* __thiscall dComIfG_play_c::executeEvtManager(void) */

void __thiscall dComIfG_play_c::executeEvtManager(dComIfG_play_c *this)

{
  dEvent_manager_c::runProc(&this->mEventMgr);
  return;
}


/* __thiscall dComIfG_play_c::createMagma(void) */

dMagma_packet_c * __thiscall dComIfG_play_c::createMagma(dComIfG_play_c *this)

{
  dMagma_packet_c *this_00;
  
  if (this->mpMagmaPacket == (dMagma_packet_c *)0x0) {
    this_00 = (dMagma_packet_c *)JKernel::operator_new(0x698);
    if (this_00 != (dMagma_packet_c *)0x0) {
      dMagma_packet_c::dMagma_packet_c(this_00);
    }
    this->mpMagmaPacket = this_00;
  }
  return this->mpMagmaPacket;
}


/* __thiscall dComIfG_play_c::removeMagma(void) */

void __thiscall dComIfG_play_c::removeMagma(dComIfG_play_c *this)

{
  dMagma_packet_c *pdVar1;
  
  pdVar1 = this->mpMagmaPacket;
  if (pdVar1 != (dMagma_packet_c *)0x0) {
    if (pdVar1 != (dMagma_packet_c *)0x0) {
      (**(code **)((pdVar1->parent).vtbl + 0x14))(pdVar1,1);
    }
    this->mpMagmaPacket = (dMagma_packet_c *)0x0;
  }
  return;
}


/* __thiscall dComIfG_play_c::executeMagma(void) */

void __thiscall dComIfG_play_c::executeMagma(dComIfG_play_c *this)

{
  if (this->mpMagmaPacket != (dMagma_packet_c *)0x0) {
    dMagma_packet_c::calc(this->mpMagmaPacket);
  }
  return;
}


/* __thiscall dComIfG_play_c::drawMagma(void) */

void __thiscall dComIfG_play_c::drawMagma(dComIfG_play_c *this)

{
  if (this->mpMagmaPacket != (dMagma_packet_c *)0x0) {
    dMagma_packet_c::update(this->mpMagmaPacket);
  }
  return;
}


/* __thiscall dComIfG_play_c::createGrass(void) */

dGrass_packet_c * __thiscall dComIfG_play_c::createGrass(dComIfG_play_c *this)

{
  dGrass_packet_c *this_00;
  
  if (this->mpGrassPacket == (dGrass_packet_c *)0x0) {
    this_00 = (dGrass_packet_c *)JKernel::operator_new(0x1a66c);
    if (this_00 != (dGrass_packet_c *)0x0) {
      dGrass_packet_c::dGrass_packet_c(this_00);
    }
    this->mpGrassPacket = this_00;
  }
  return this->mpGrassPacket;
}


/* __thiscall dComIfG_play_c::removeGrass(void) */

void __thiscall dComIfG_play_c::removeGrass(dComIfG_play_c *this)

{
  dGrass_packet_c *pdVar1;
  
  pdVar1 = this->mpGrassPacket;
  if (pdVar1 != (dGrass_packet_c *)0x0) {
    if (pdVar1 != (dGrass_packet_c *)0x0) {
      (**(code **)((pdVar1->parent).vtbl + 0x14))(pdVar1,1);
    }
    this->mpGrassPacket = (dGrass_packet_c *)0x0;
  }
  return;
}


/* __thiscall dGrass_packet_c::~dGrass_packet_c(void) */

void __thiscall dGrass_packet_c::_dGrass_packet_c(dGrass_packet_c *this)

{
  short in_r4;
  
  if (this != (dGrass_packet_c *)0x0) {
    (this->parent).vtbl = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this->mGrassData,dGrass_data_c::_dGrass_data_c,0x44,0x5dc);
    if (this != (dGrass_packet_c *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dGrass_data_c::~dGrass_data_c(void) */

void __thiscall dGrass_data_c::_dGrass_data_c(dGrass_data_c *this)

{
  short in_r4;
  
  if ((this != (dGrass_data_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dComIfG_play_c::executeGrass(void) */

void __thiscall dComIfG_play_c::executeGrass(dComIfG_play_c *this)

{
  if (this->mpGrassPacket != (dGrass_packet_c *)0x0) {
    dGrass_packet_c::calc(this->mpGrassPacket);
  }
  return;
}


/* __thiscall dComIfG_play_c::drawGrass(void) */

void __thiscall dComIfG_play_c::drawGrass(dComIfG_play_c *this)

{
  if (this->mpGrassPacket != (dGrass_packet_c *)0x0) {
    dGrass_packet_c::update(this->mpGrassPacket);
  }
  return;
}


/* __thiscall dComIfG_play_c::createFlower(void) */

dFlower_packet_c * __thiscall dComIfG_play_c::createFlower(dComIfG_play_c *this)

{
  dFlower_packet_c *this_00;
  
  if (this->mpFlowerPacket == (dFlower_packet_c *)0x0) {
    this_00 = (dFlower_packet_c *)JKernel::operator_new(0x462c);
    if (this_00 != (dFlower_packet_c *)0x0) {
      dFlower_packet_c::dFlower_packet_c(this_00);
    }
    this->mpFlowerPacket = this_00;
  }
  return this->mpFlowerPacket;
}


/* __thiscall dComIfG_play_c::removeFlower(void) */

void __thiscall dComIfG_play_c::removeFlower(dComIfG_play_c *this)

{
  int *piVar1;
  
  piVar1 = (int *)this->mpFlowerPacket;
  if (piVar1 != (int *)0x0) {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x14))(piVar1,1);
    }
    this->mpFlowerPacket = (dFlower_packet_c *)0x0;
  }
  return;
}


/* __thiscall dFlower_packet_c::~dFlower_packet_c(void) */

void __thiscall dFlower_packet_c::_dFlower_packet_c(dFlower_packet_c *this)

{
  short in_r4;
  
  if (this != (dFlower_packet_c *)0x0) {
    *(undefined1 **)this = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this + 0x14,dFlower_data_c::_dFlower_data_c,0x44,200);
    if (this != (dFlower_packet_c *)0x0) {
      *(undefined ***)this = &J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dFlower_data_c::~dFlower_data_c(void) */

void __thiscall dFlower_data_c::_dFlower_data_c(dFlower_data_c *this)

{
  short in_r4;
  
  if ((this != (dFlower_data_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dComIfG_play_c::executeFlower(void) */

void __thiscall dComIfG_play_c::executeFlower(dComIfG_play_c *this)

{
  if (this->mpFlowerPacket != (dFlower_packet_c *)0x0) {
    dFlower_packet_c::calc(this->mpFlowerPacket);
  }
  return;
}


/* __thiscall dComIfG_play_c::drawFlower(void) */

void __thiscall dComIfG_play_c::drawFlower(dComIfG_play_c *this)

{
  if (this->mpFlowerPacket != (dFlower_packet_c *)0x0) {
    dFlower_packet_c::update(this->mpFlowerPacket);
  }
  return;
}


/* __thiscall dComIfG_play_c::createTree(void) */

dTree_packet_c * __thiscall dComIfG_play_c::createTree(dComIfG_play_c *this)

{
  dTree_packet_c *this_00;
  
  if (this->mpTreePacket == (dTree_packet_c *)0x0) {
    this_00 = (dTree_packet_c *)JKernel::operator_new(0x6748);
    if (this_00 != (dTree_packet_c *)0x0) {
      dTree_packet_c::dTree_packet_c(this_00);
    }
    this->mpTreePacket = this_00;
  }
  return this->mpTreePacket;
}


/* __thiscall dComIfG_play_c::removeTree(void) */

void __thiscall dComIfG_play_c::removeTree(dComIfG_play_c *this)

{
  dTree_packet_c *pdVar1;
  
  pdVar1 = this->mpTreePacket;
  if (pdVar1 != (dTree_packet_c *)0x0) {
    if (pdVar1 != (dTree_packet_c *)0x0) {
      (**(code **)(pdVar1->vtbl + 0x14))(pdVar1,1);
    }
    this->mpTreePacket = (dTree_packet_c *)0x0;
  }
  return;
}


/* __thiscall dTree_packet_c::~dTree_packet_c(void) */

void __thiscall dTree_packet_c::_dTree_packet_c(dTree_packet_c *this)

{
  short in_r4;
  
  if (this != (dTree_packet_c *)0x0) {
    this->vtbl = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this->mAnm,dTree_anm_c::_dTree_anm_c,0x84,0x48);
    Runtime.PPCEABI.H::__destroy_arr(this->mData,dTree_data_c::_dTree_data_c,0x104,0x40);
    if (this != (dTree_packet_c *)0x0) {
      this->vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dTree_data_c::~dTree_data_c(void) */

void __thiscall dTree_data_c::_dTree_data_c(dTree_data_c *this)

{
  short in_r4;
  
  if ((this != (dTree_data_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dTree_anm_c::~dTree_anm_c(void) */

void __thiscall dTree_anm_c::_dTree_anm_c(dTree_anm_c *this)

{
  short in_r4;
  
  if ((this != (dTree_anm_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dComIfG_play_c::executeTree(void) */

void __thiscall dComIfG_play_c::executeTree(dComIfG_play_c *this)

{
  if (this->mpTreePacket != (dTree_packet_c *)0x0) {
    dTree_packet_c::calc(this->mpTreePacket);
  }
  return;
}


/* __thiscall dComIfG_play_c::drawTree(void) */

void __thiscall dComIfG_play_c::drawTree(dComIfG_play_c *this)

{
  if (this->mpTreePacket != (dTree_packet_c *)0x0) {
    dTree_packet_c::update(this->mpTreePacket);
  }
  return;
}


/* __thiscall dComIfG_play_c::createWood(void) */

Packet_c * __thiscall dComIfG_play_c::createWood(dComIfG_play_c *this)

{
  Packet_c *this_00;
  
  if (this->mpWoodPacket == (Packet_c *)0x0) {
    this_00 = (Packet_c *)JKernel::operator_new(0x15dd0);
    if (this_00 != (Packet_c *)0x0) {
      dWood::Packet_c::Packet_c(this_00);
    }
    this->mpWoodPacket = this_00;
  }
  return this->mpWoodPacket;
}


/* __thiscall dComIfG_play_c::removeWood(void) */

void __thiscall dComIfG_play_c::removeWood(dComIfG_play_c *this)

{
  Packet_c *pPVar1;
  
  pPVar1 = this->mpWoodPacket;
  if (pPVar1 != (Packet_c *)0x0) {
    if (pPVar1 != (Packet_c *)0x0) {
      (**(code **)((pPVar1->parent).vtbl + 0x14))(pPVar1,1);
    }
    this->mpWoodPacket = (Packet_c *)0x0;
  }
  return;
}


/* __thiscall dComIfG_play_c::executeWood(void) */

void __thiscall dComIfG_play_c::executeWood(dComIfG_play_c *this)

{
  if (this->mpWoodPacket != (Packet_c *)0x0) {
    dWood::Packet_c::calc(this->mpWoodPacket);
  }
  return;
}


/* __thiscall dComIfG_play_c::drawWood(void) */

void __thiscall dComIfG_play_c::drawWood(dComIfG_play_c *this)

{
  if (this->mpWoodPacket != (Packet_c *)0x0) {
    dWood::Packet_c::update(this->mpWoodPacket);
  }
  return;
}


/* __thiscall dComIfG_inf_c::ct(void) */

void __thiscall dComIfG_inf_c::ct(dComIfG_inf_c *this)

{
  this->field_0x1d1c1 = 0xff;
  dComIfG_play_c::ct(&this->mPlay);
  return;
}


namespace d_com_inf_game {

/* __stdcall dComIfG_changeOpeningScene(scene_class *,
                                        short) */

undefined4 dComIfG_changeOpeningScene(scene_class *pScene,int procName)

{
  g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext = 0;
  dComIfGp_setNextStage("sea_T",0,0x2c,0,0_0,0,1,0);
  m_Do_audio::mDoAud_setSceneName
            (0x803c9d48,(int)g_dComIfG_gameInfo.mPlay.mNextStage.parent.mStartCode,
             (int)(char)g_dComIfG_gameInfo.mPlay.mNextStage.parent.mLayerNo);
  g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartParameters = 0;
  f_op_scene_mng::fopScnM_ChangeReq(pScene,procName,0,0x1e);
  f_op_scene_mng::fopScnM_ReRequest(procName,0);
  return 1;
}


/* __stdcall dComIfG_resetToOpening(scene_class *) */

undefined4 dComIfG_resetToOpening(scene_class *param_1)

{
  undefined4 uVar1;
  
  if (*mDoRst::mResetData == 0) {
    uVar1 = 0;
  }
  else {
    dComIfG_changeOpeningScene(param_1,8);
    JAIZelBasic::bgmStop(JAIZelBasic::zel_basic,0x1e,0);
    if (mDoAud_zelAudio_c::mResetFlag != '\0') {
      JAIZelBasic::resetProcess(JAIZelBasic::zel_basic);
      mDoAud_zelAudio_c::mResetFlag = '\x01';
    }
    uVar1 = 1;
  }
  return uVar1;
}


/* __stdcall phase_1(char *) */

undefined4 phase_1(char *param_1)

{
  undefined4 uVar1;
  
  dRes_control_c::setRes
            (param_1,g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40,"/res/Object/",0,(JKRHeap *)0x0);
  uVar1 = 2;
  if (param_1 == (char *)0x0) {
    uVar1 = 5;
  }
  return uVar1;
}


/* __stdcall phase_2(char *) */

uint phase_2(char *param_1)

{
  uint uVar1;
  
  uVar1 = dRes_control_c::syncRes(param_1,g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if ((int)uVar1 < 0) {
    uVar1 = 5;
  }
  else {
    uVar1 = ~((int)(-uVar1 & ~uVar1) >> 0x1f) & 2;
  }
  return uVar1;
}


/* __stdcall phase_3(char *) */

undefined4 phase_3(void)

{
  return 4;
}


/* __stdcall dComIfG_resLoad(request_of_phase_process_class *,
                             char const *) */

PhaseState dComIfG_resLoad(request_of_phase_process_class *param_1,char *param_2)

{
  PhaseState PVar1;
  
  if (param_1->mStep == 2) {
    PVar1 = cPhs_COMPLEATE_e;
  }
  else {
    PVar1 = d_com_lib_game::dComLbG_PhaseHandler(param_1,(cPhs__Handler *)&l_method_4526,param_2);
  }
  return PVar1;
}


/* __stdcall dComIfG_resDelete(request_of_phase_process_class *,
                               char const *) */

undefined4 dComIfG_resDelete(request_of_phase_process_class *param_1,char *param_2)

{
  ulong uVar1;
  
  if (param_1->mStep == 1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_com_inf_game.cpp",0x418,"i_phase->id != 1");
    m_Do_printf::OSPanic("d_com_inf_game.cpp",0x418,&DAT_8034f591);
  }
  if (param_1->mStep == 2) {
    dRes_control_c::deleteRes(param_2,g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    param_1->mStep = 0;
  }
  return 0;
}


/* __stdcall dComIfGp_getReverb(int) */

void dComIfGp_getReverb(undefined4 param_1)

{
  roomRead_class *prVar1;
  
  prVar1 = (roomRead_class *)(*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getRoom)();
  d_stage::dStage_roomRead_dt_c_GetReverbStage(prVar1,param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80053590) */
/* WARNING: Removing unreachable block (ram,0x80053588) */
/* WARNING: Removing unreachable block (ram,0x80053598) */
/* __stdcall dComIfGd_setSimpleShadow2(cXyz *,
                                       float,
                                       float,
                                       cBgS_PolyInfo &,
                                       short,
                                       float,
                                       _GXTexObj *) */

undefined4
dComIfGd_setSimpleShadow2
          (cXyz *pPos,float param_2,float param_3,cBgS_PolyInfo *pFloorPoly,short rotY,float param_6
          ,_GXTexObj *pTexObj)

{
  bool bVar1;
  cM3dGPla *pFloorNrm;
  undefined4 uVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_6;
  dVar5 = (double)param_3;
  dVar4 = (double)param_2;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if (((ushort)pFloorPoly->mTriIdx == 0xffff) || (pFloorPoly->mBgIndex == 0x100)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && ((double)_1_0E9 != dVar4)) {
    pFloorNrm = ::cBgS::GetTriPla((cBgS *)&g_dComIfG_gameInfo.mPlay,
                                  (uint)(ushort)pFloorPoly->mBgIndex,
                                  (uint)(ushort)pFloorPoly->mTriIdx);
    uVar2 = dDlst_shadowControl_c::setSimple
                      (&g_dComIfG_gameInfo.mDlstList.mShadowControl,pPos,(float)dVar4,(float)dVar5,
                       (cXyz *)pFloorNrm,rotY,(float)dVar6,pTexObj);
  }
  else {
    uVar2 = 0;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  return uVar2;
}


/* __stdcall dComIfGp_getShip(int,
                              int) */

int dComIfGp_getShip(int param_1,uint param_2)

{
  int iVar1;
  dStage_roomStatus_c *pdVar2;
  int *piVar3;
  int iVar4;
  
  pdVar2 = dStage_roomControl_c::getStatusRoomDt(&g_dComIfG_gameInfo.mPlay.mRoomCtrl,param_1);
  if ((((pdVar2 != (dStage_roomStatus_c *)0x0) &&
       (piVar3 = (int *)(*(code *)((pdVar2->parent).parent.vtbl)->getShip)(), piVar3 != (int *)0x0))
      && (iVar1 = *piVar3, 0 < iVar1)) &&
     (((param_2 != 0xff && (iVar4 = piVar3[1], iVar4 != 0)) && (0 < iVar1)))) {
    do {
      if (param_2 == *(byte *)(iVar4 + 0xe)) {
        return iVar4;
      }
      iVar4 = iVar4 + 0x10;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dComIfGp_getMapTrans(int,
                                  float *,
                                  float *,
                                  short *) */

undefined4
dComIfGp_getMapTrans(int param_1,float *param_2,float *param_3,short *param_4)

{
  int iVar1;
  dStage_Multi_c *local_r3_56;
  dStage_Multi_c__Entry *pdVar2;
  
  local_r3_56 = (dStage_Multi_c *)
                (*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getMulti)();
  if (local_r3_56 != (dStage_Multi_c *)0x0) {
    pdVar2 = local_r3_56->mEntries;
    iVar1 = local_r3_56->mCount;
    if (0 < iVar1) {
      do {
        if (param_1 == (uint)pdVar2->mRoomId) {
          *param_2 = pdVar2->mTransX;
          *param_3 = pdVar2->mTransY;
          *param_4 = pdVar2->mRotY;
          return 1;
        }
        pdVar2 = pdVar2 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return 0;
}


/* __stdcall dComIfGp_getRoomCamera(int) */

stage_camera_class * dComIfGp_getRoomCamera(int param_1)

{
  dStage_roomStatus_c *pdVar1;
  stage_camera_class *psVar2;
  
  pdVar1 = dStage_roomControl_c::getStatusRoomDt(&g_dComIfG_gameInfo.mPlay.mRoomCtrl,param_1);
  if (pdVar1 == (dStage_roomStatus_c *)0x0) {
    psVar2 = (stage_camera_class *)0x0;
  }
  else {
    psVar2 = (stage_camera_class *)(*(code *)((pdVar1->parent).parent.vtbl)->getCamera)();
  }
  return psVar2;
}


/* __stdcall dComIfGp_getRoomArrow(int) */

stage_arrow_class * dComIfGp_getRoomArrow(int param_1)

{
  dStage_roomStatus_c *pdVar1;
  stage_arrow_class *psVar2;
  
  pdVar1 = dStage_roomControl_c::getStatusRoomDt(&g_dComIfG_gameInfo.mPlay.mRoomCtrl,param_1);
  if (pdVar1 == (dStage_roomStatus_c *)0x0) {
    psVar2 = (stage_arrow_class *)0x0;
  }
  else {
    psVar2 = (stage_arrow_class *)(*(code *)((pdVar1->parent).parent.vtbl)->getArrow)();
  }
  return psVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dComIfGp_setNextStage(char const *,
                                   short,
                                   signed char,
                                   signed char,
                                   float,
                                   unsigned long,
                                   int,
                                   signed char) */

void dComIfGp_setNextStage
               (char *pStageName,short startCode,byte roomIdx,byte layerNo,float param_5,uint mode,
               int param_7,byte wipeType)

{
  uint uVar1;
  double dVar2;
  
  dVar2 = (double)param_5;
  dStage_nextStage_c::set
            (&g_dComIfG_gameInfo.mPlay.mNextStage,pStageName,roomIdx,startCode,layerNo,wipeType);
  if (g_dComIfG_gameInfo.mPlay.mpLinkActor != (daPy_lk_c *)0x0) {
    uVar1 = ((g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).field_0x2a0;
    if ((uVar1 & 1) != 0) {
      mode = mode | 0x8000;
    }
    mode = mode | (int)(g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x354e << 0x10;
    if ((uVar1 & 0x8000) != 0) {
      mode = mode | 0x4000;
    }
  }
  if (param_7 != 0) {
    g_dComIfG_gameInfo.mSvInfo.mRestart.mStartCode = startCode;
  }
  g_dComIfG_gameInfo.mSvInfo.field_0x1150 = (float)dVar2;
  g_dComIfG_gameInfo.mSvInfo.mMode = mode;
  return;
}


/* __stdcall dComIfGs_onStageTbox(int,
                                  int) */

void dComIfGs_onStageTbox(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  if (param_1 == *(byte *)(iVar1 + 9) >> 1) {
    dSv_memBit_c::onTbox((dSv_memBit_c *)&g_dComIfG_gameInfo.mSvInfo.mMemory,param_2);
  }
  dSv_memBit_c::onTbox((dSv_memBit_c *)(g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + param_1),param_2)
  ;
  return;
}


/* __stdcall dComIfGs_isStageTbox(int,
                                  int) */

void dComIfGs_isStageTbox(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  if (param_1 == *(byte *)(iVar1 + 9) >> 1) {
    dSv_memBit_c::isTbox((dSv_memBit_c *)&g_dComIfG_gameInfo.mSvInfo.mMemory,param_2);
  }
  else {
    dSv_memBit_c::isTbox
              ((dSv_memBit_c *)(g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + param_1),param_2);
  }
  return;
}


/* __stdcall dComIfGs_isStageBossEnemy(int) */

void dComIfGs_isStageBossEnemy(uint param_1)

{
  stage_stag_info_class *pStagInfo;
  
  pStagInfo = (stage_stag_info_class *)
              (*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  if (param_1 == pStagInfo->mProp >> 1) {
    dSv_memBit_c::isDungeonItem((dSv_memBit_c *)&g_dComIfG_gameInfo.mSvInfo.mMemory,3);
  }
  else {
    dSv_memBit_c::isDungeonItem
              ((dSv_memBit_c *)(g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + param_1),3);
  }
  return;
}


/* __stdcall dComIfGs_onStageLife(int) */

void dComIfGs_onStageLife(uint param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  if (param_1 == *(byte *)(iVar1 + 9) >> 1) {
    dSv_memBit_c::onDungeonItem((dSv_memBit_c *)&g_dComIfG_gameInfo.mSvInfo.mMemory,4);
  }
  dSv_memBit_c::onDungeonItem
            ((dSv_memBit_c *)(g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + param_1),4);
  return;
}


/* __stdcall dComIfGs_isStageLife(int) */

void dComIfGs_isStageLife(uint param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  if (param_1 == *(byte *)(iVar1 + 9) >> 1) {
    dSv_memBit_c::isDungeonItem((dSv_memBit_c *)&g_dComIfG_gameInfo.mSvInfo.mMemory,4);
  }
  else {
    dSv_memBit_c::isDungeonItem
              ((dSv_memBit_c *)(g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + param_1),4);
  }
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __stdcall dComIfGs_checkGetItem(unsigned char) */

bool dComIfGs_checkGetItem(dItem_data__ItemNo itemNo)

{
  dItem_data__ItemNo dVar1;
  char cVar2;
  uint uVar3;
  dSv_player_item_c *pdVar4;
  int iVar5;
  int iVar6;
  
  cVar2 = '\0';
  switch((uint)itemNo) {
  case 0x42:
    uVar3 = dSv_player_collect_c::isCollect(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,3,0);
    if (uVar3 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 0x43:
    uVar3 = dSv_player_collect_c::isCollect(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,4,0);
    if (uVar3 != 0) {
      cVar2 = '\x01';
    }
    break;
  default:
    iVar5 = 0;
    pdVar4 = &g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem;
    iVar6 = 0x3c;
    do {
      if (iVar5 < 0x15) {
        dVar1 = pdVar4->mTelescopeSlot;
      }
      else {
        if (iVar5 < 0x18) {
          dVar1 = InvalidItem;
        }
        else {
          if (iVar5 < 0x20) {
            dVar1 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[iVar5 + 0xd];
          }
          else {
            if (iVar5 < 0x24) {
              dVar1 = InvalidItem;
            }
            else {
              if (iVar5 < 0x2c) {
                dVar1 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[iVar5 + 9];
              }
              else {
                if (iVar5 < 0x30) {
                  dVar1 = InvalidItem;
                }
                else {
                  if (iVar5 < 0x38) {
                    dVar1 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[iVar5 + 5];
                  }
                  else {
                    dVar1 = InvalidItem;
                  }
                }
              }
            }
          }
        }
      }
      if (itemNo == dVar1) {
        cVar2 = cVar2 + '\x01';
      }
      iVar5 = iVar5 + 1;
      pdVar4 = (dSv_player_item_c *)&pdVar4->field_0x1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar5 = 0;
    iVar6 = 3;
    do {
      if (itemNo == g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton
                    [iVar5 + 5]) {
        cVar2 = cVar2 + '\x01';
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if (((0xbe < itemNo) && (itemNo != InvalidItem)) &&
       (iVar5 = dSv_player_map_c::isGetMap
                          (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xfe - (uint)itemNo),
       iVar5 != 0)) {
      cVar2 = cVar2 + '\x01';
    }
    break;
  case 0x61:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 0x62:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 99:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 100:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x03');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 0x65:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x04');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 0x66:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x05');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 0x67:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x06');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 0x68:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\a');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 0x69:
    iVar5 = dSv_player_collect_c::isSymbol(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 0x6a:
    iVar5 = dSv_player_collect_c::isSymbol
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 0x6b:
    iVar5 = dSv_player_collect_c::isSymbol
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 0x6d:
    iVar5 = dSv_player_collect_c::isTact(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 0x6e:
    iVar5 = dSv_player_collect_c::isTact(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 0x6f:
    iVar5 = dSv_player_collect_c::isTact(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 0x70:
    iVar5 = dSv_player_collect_c::isTact(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x03');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 0x71:
    iVar5 = dSv_player_collect_c::isTact(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x04');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
    break;
  case 0x72:
    iVar5 = dSv_player_collect_c::isTact(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x05');
    if (iVar5 != 0) {
      cVar2 = '\x01';
    }
  }
  return (bool)cVar2;
}


/* WARNING: Type propagation algorithm not settling */
/* __stdcall dComIfGs_checkGetItemNum(unsigned char) */

undefined dComIfGs_checkGetItemNum(dItem_data__ItemNo param_1)

{
  dItem_data__ItemNo dVar1;
  uint uVar2;
  dSv_player_bag_item_c *pdVar3;
  dSv_player_item_c *pdVar4;
  int iVar5;
  undefined uVar6;
  int iVar7;
  
  uVar6 = 0;
  switch((uint)param_1) {
  case 0x1f:
    pdVar3 = &g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem;
    iVar5 = 8;
    do {
      if (pdVar3->field_0x0[0] == 0x1f) {
        uVar6 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord._7_1_;
      }
      pdVar3 = (dSv_player_bag_item_c *)(pdVar3->field_0x0 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    break;
  default:
    iVar5 = 0;
    pdVar4 = &g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem;
    iVar7 = 0x3c;
    do {
      if (iVar5 < 0x15) {
        dVar1 = pdVar4->mTelescopeSlot;
      }
      else {
        if (iVar5 < 0x18) {
          dVar1 = InvalidItem;
        }
        else {
          if (iVar5 < 0x20) {
            dVar1 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[iVar5 + 0xd];
          }
          else {
            if (iVar5 < 0x24) {
              dVar1 = InvalidItem;
            }
            else {
              if (iVar5 < 0x2c) {
                dVar1 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[iVar5 + 9];
              }
              else {
                if (iVar5 < 0x30) {
                  dVar1 = InvalidItem;
                }
                else {
                  if (iVar5 < 0x38) {
                    dVar1 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[iVar5 + 5];
                  }
                  else {
                    dVar1 = InvalidItem;
                  }
                }
              }
            }
          }
        }
      }
      if (param_1 == dVar1) {
        uVar6 = 1;
      }
      iVar5 = iVar5 + 1;
      pdVar4 = (dSv_player_item_c *)&pdVar4->field_0x1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    iVar5 = 0;
    iVar7 = 3;
    do {
      if (param_1 ==
          g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton[iVar5 + 5])
      {
        uVar6 = 1;
      }
      iVar5 = iVar5 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    if (((0xbe < param_1) && (param_1 != InvalidItem)) &&
       (iVar5 = dSv_player_map_c::isGetMap
                          (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xfe - (uint)param_1),
       iVar5 != 0)) {
      uVar6 = 1;
    }
    break;
  case 0x27:
    if (g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot != Heart) {
      uVar6 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_;
    }
    break;
  case 0x31:
    if (g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._13_1_ != '\0') {
      uVar6 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_;
    }
    break;
  case 0x42:
    uVar2 = dSv_player_collect_c::isCollect(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,3,0);
    if (uVar2 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x43:
    uVar2 = dSv_player_collect_c::isCollect(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,4,0);
    if (uVar2 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x45:
    pdVar3 = &g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem;
    iVar5 = 8;
    do {
      if (pdVar3->field_0x0[0] == 0x45) {
        uVar6 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord._0_1_;
      }
      pdVar3 = (dSv_player_bag_item_c *)(pdVar3->field_0x0 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    break;
  case 0x46:
    pdVar3 = &g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem;
    iVar5 = 8;
    do {
      if (pdVar3->field_0x0[0] == 0x46) {
        uVar6 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord._1_1_;
      }
      pdVar3 = (dSv_player_bag_item_c *)(pdVar3->field_0x0 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    break;
  case 0x47:
    pdVar3 = &g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem;
    iVar5 = 8;
    do {
      if (pdVar3->field_0x0[0] == 0x47) {
        uVar6 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord._2_1_;
      }
      pdVar3 = (dSv_player_bag_item_c *)(pdVar3->field_0x0 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    break;
  case 0x48:
    pdVar3 = &g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem;
    iVar5 = 8;
    do {
      if (pdVar3->field_0x0[0] == 0x48) {
        uVar6 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord._3_1_;
      }
      pdVar3 = (dSv_player_bag_item_c *)(pdVar3->field_0x0 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    break;
  case 0x49:
    pdVar3 = &g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem;
    iVar5 = 8;
    do {
      if (pdVar3->field_0x0[0] == 0x49) {
        uVar6 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord._4_1_;
      }
      pdVar3 = (dSv_player_bag_item_c *)(pdVar3->field_0x0 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    break;
  case 0x4a:
    pdVar3 = &g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem;
    iVar5 = 8;
    do {
      if (pdVar3->field_0x0[0] == 0x4a) {
        uVar6 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord._5_1_;
      }
      pdVar3 = (dSv_player_bag_item_c *)(pdVar3->field_0x0 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    break;
  case 0x4b:
    pdVar3 = &g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem;
    iVar5 = 8;
    do {
      if (pdVar3->field_0x0[0] == 0x4b) {
        uVar6 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord._6_1_;
      }
      pdVar3 = (dSv_player_bag_item_c *)(pdVar3->field_0x0 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    break;
  case 0x61:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x62:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 99:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 100:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x03');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x65:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x04');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x66:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x05');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x67:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x06');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x68:
    iVar5 = dSv_player_collect_c::isTriforce
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\a');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x69:
    iVar5 = dSv_player_collect_c::isSymbol(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x6a:
    iVar5 = dSv_player_collect_c::isSymbol
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x6b:
    iVar5 = dSv_player_collect_c::isSymbol
                      (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x6d:
    iVar5 = dSv_player_collect_c::isTact(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x6e:
    iVar5 = dSv_player_collect_c::isTact(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x6f:
    iVar5 = dSv_player_collect_c::isTact(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x70:
    iVar5 = dSv_player_collect_c::isTact(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x03');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x71:
    iVar5 = dSv_player_collect_c::isTact(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x04');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
    break;
  case 0x72:
    iVar5 = dSv_player_collect_c::isTact(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x05');
    if (iVar5 != 0) {
      uVar6 = 1;
    }
  }
  return uVar6;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80054664) */
/* WARNING: Removing unreachable block (ram,0x80054654) */
/* WARNING: Removing unreachable block (ram,0x8005465c) */
/* WARNING: Removing unreachable block (ram,0x8005466c) */
/* __stdcall dComIfGd_setShadow(unsigned long,
                                signed char,
                                J3DModel *,
                                cXyz *,
                                float,
                                float,
                                float,
                                float,
                                cBgS_PolyInfo &,
                                dKy_tevstr_c *,
                                short,
                                float,
                                _GXTexObj *) */

int dComIfGd_setShadow
              (ulong id,byte param_2,J3DModel *pModel,cXyz *pPos,float param_5,float param_6,float y
              ,float param_8,cBgS_PolyInfo *pFloorPoly,dKy_tevstr_c *param_10,short rotY,
              float param_12,_GXTexObj *pTexObj)

{
  int iVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  cXyz pos;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_12;
  dVar4 = (double)y;
  dVar5 = (double)param_8;
  dVar3 = (double)param_6;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  if ((double)_1_0E9 < dVar5) {
    iVar1 = dDlst_shadowControl_c::setReal2
                      (&g_dComIfG_gameInfo.mDlstList.mShadowControl,id,param_2,pModel,pPos,param_5,
                       (float)(dVar4 - dVar5),param_10);
    if (iVar1 == 0) {
      pos.z = pPos->z;
      pos.x = pPos->x;
      pos.y = (float)dVar4;
      dComIfGd_setSimpleShadow2(&pos,(float)dVar5,(float)dVar3,pFloorPoly,rotY,(float)dVar6,pTexObj)
      ;
    }
  }
  else {
    iVar1 = 0;
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  __psq_l0(auStack56,uVar2);
  __psq_l1(auStack56,uVar2);
  return iVar1;
}


/* __stdcall getSceneList(int) */

stage_scls_info_class * getSceneList(int i_no)

{
  bool bVar1;
  stage_scls_info_dummy_class *sclsInfo;
  ulong uVar2;
  stage_scls_info_class *sclsData;
  
  sclsInfo = (stage_scls_info_dummy_class *)
             (*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getSclsInfo)();
  if (sclsInfo == (stage_scls_info_dummy_class *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_com_inf_game.cpp",0x854,"sclsInfo != 0");
    m_Do_printf::OSPanic("d_com_inf_game.cpp",0x854,&DAT_8034f591);
  }
  bVar1 = false;
  if (-1 < i_no) {
    if (i_no < sclsInfo->mCount) {
      bVar1 = true;
    }
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_com_inf_game.cpp",0x856,"0 <= i_no && i_no < sclsInfo->num");
    m_Do_printf::OSPanic("d_com_inf_game.cpp",0x856,&DAT_8034f591);
  }
  sclsData = sclsInfo->mpScls;
  if (sclsData == (stage_scls_info_class *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_com_inf_game.cpp",0x858,"sclsData != 0");
    m_Do_printf::OSPanic("d_com_inf_game.cpp",0x858,&DAT_8034f591);
  }
  return sclsData + i_no;
}


/* __stdcall dComIfGd_getMeshSceneList(Vec &) */

stage_scls_info_class * dComIfGd_getMeshSceneList(cXyz *pVec)

{
  uint uVar1;
  stage_scls_info_class *sclsData;
  uint uVar2;
  
  uVar1 = (uint)(2_0E_5 * (350000_0 + pVec->x));
  uVar2 = (uint)(2_0E_5 * (350000_0 + pVec->z));
  if ((int)uVar1 < 0) {
    uVar1 = 0;
  }
  else {
    if (0xd < (int)uVar1) {
      uVar1 = 0xd;
    }
  }
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  else {
    if (0xd < (int)uVar2) {
      uVar2 = 0xd;
    }
  }
  sclsData = getSceneList((uVar1 & 1) +
                          (((int)uVar1 >> 1) + ((int)uVar2 >> 1) * 7) * 4 + (uVar2 & 1) * 2);
  return sclsData;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dComIfGs_checkSeaLandingEvent(signed char) */

int dComIfGs_checkSeaLandingEvent(byte param_1)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  
  pbVar1 = &l_landingEvent_5946;
  uVar3 = 0;
  while ((param_1 != *pbVar1 ||
         (iVar2 = dSv_event_c::isEventBit
                            (&g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,*(ushort *)(pbVar1 + 2)),
         iVar2 != 0))) {
    uVar3 = uVar3 + 1;
    pbVar1 = pbVar1 + 4;
    if (5 < uVar3) {
      return 1;
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dComIfGs_setGameStartStage(void) */

void dComIfGs_setGameStartStage(void)

{
  daPy_lk_c *pdVar1;
  char *pcVar2;
  byte bVar3;
  int iVar4;
  stage_stag_info_class *pStag;
  stage_stag_info_class *pStag2;
  ushort uVar7;
  byte roomNo;
  byte startCode;
  stage_scls_info_class *sclsData;
  stage_map_info_class *psVar5;
  ulong uVar6;
  char cVar8;
  char cVar9;
  uint uVar10;
  char stageName [8];
  cXyz local_30;
  uint stageType;
  
  pcVar2 = &l_checkData_5964;
  uVar10 = 0;
  do {
    if ((*pcVar2 == '\x01') &&
       (iVar4 = dSv_event_c::isEventBit
                          (&g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,*(ushort *)(pcVar2 + 2)),
       iVar4 != 0)) break;
    uVar10 = uVar10 + 1;
    pcVar2 = pcVar2 + 0xe;
  } while (uVar10 < 5);
  iVar4 = MSL_C.PPCEABI.bare.H::strcmp(pcVar2 + 4,"");
  if (iVar4 == 0) {
    pStag = (stage_stag_info_class *)
            (*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)(0x803c9d58);
    stageType = pStag->mStageTypeAndSchbit >> 0x10 & 7;
    pStag2 = (stage_stag_info_class *)
             (*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)(0x803c9d58);
    uVar10 = (uint)(pStag2->mProp >> 1);
    iVar4 = MSL_C.PPCEABI.bare.H::strcmp(g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"PShip");
    pdVar1 = g_dComIfG_gameInfo.mPlay.mpLinkActor;
    if (iVar4 == 0) {
      MSL_C.PPCEABI.bare.H::strcpy(stageName,"sea");
      uVar7 = dSv_event_c::getEventReg(&g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xc3ff);
      bVar3 = (byte)uVar7;
      uVar7 = dSv_event_c::getEventReg(&g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x85ff);
      startCode = (byte)uVar7;
      d_kankyo::dKy_set_nexttime((double)_6043);
    }
    else {
      if (stageType == 7) {
        uVar10 = (g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x3594 & 0xff;
        startCode = (byte)uVar10;
        bVar3 = ((g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).parent.mCurrent.mRoomNo;
        if ((((char)bVar3 < '\0') || (uVar10 == 0xff)) ||
           (iVar4 = dComIfGs_checkSeaLandingEvent(bVar3), iVar4 == 0)) {
          if (g_dComIfG_gameInfo.mPlay.mpShip == (daShip_c *)0x0) {
            sclsData = dComIfGd_getMeshSceneList(&(pdVar1->parent).parent.mCurrent.mPos);
          }
          else {
            sclsData = dComIfGd_getMeshSceneList
                                 (&((g_dComIfG_gameInfo.mPlay.mpShip)->parent).mCurrent.mPos);
          }
          MSL_C.PPCEABI.bare.H::strcpy(stageName,sclsData->mStageName);
          bVar3 = sclsData->mRoomNo;
          startCode = sclsData->mStartCode;
        }
        else {
          MSL_C.PPCEABI.bare.H::strcpy(stageName,g_dComIfG_gameInfo.mPlay.mCurStage.mStageName);
        }
      }
      else {
        if ((((stageType == 1) || (stageType == 6)) || (stageType == 3)) ||
           ((stageType == 8 || (uVar10 == 9)))) {
          sclsData = getSceneList(0);
          MSL_C.PPCEABI.bare.H::strcpy(stageName,sclsData->mStageName);
          bVar3 = sclsData->mRoomNo;
          startCode = sclsData->mStartCode;
        }
        else {
          if (uVar10 == 10) {
            local_30.x = g_dComIfG_gameInfo.mIkadaLinkPos.x;
            local_30.y = g_dComIfG_gameInfo.mIkadaLinkPos.y;
            local_30.z = g_dComIfG_gameInfo.mIkadaLinkPos.z;
            sclsData = dComIfGd_getMeshSceneList(&local_30);
            MSL_C.PPCEABI.bare.H::strcpy(stageName,sclsData->mStageName);
            bVar3 = sclsData->mRoomNo;
            startCode = sclsData->mStartCode;
          }
          else {
            if ((uVar10 - 0xb < 2) || (uVar10 == 0xd)) {
              MSL_C.PPCEABI.bare.H::strcpy(stageName,"sea");
              psVar5 = (stage_map_info_class *)
                       (*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getMapInfo)
                                 (0x803c9d58);
              if (psVar5 == (stage_map_info_class *)0x0) {
                uVar6 = JUTAssertion::getSDevice();
                JUTAssertion::showAssert(uVar6,"d_com_inf_game.cpp",0x93a,"mapInfo != 0");
                m_Do_printf::OSPanic("d_com_inf_game.cpp",0x93a,&DAT_8034f591);
              }
              cVar8 = d_stage::dStage_mapInfo_GetOceanZ(psVar5);
              cVar9 = d_stage::dStage_mapInfo_GetOceanX(psVar5);
              bVar3 = cVar9 + (cVar8 + '\x03') * '\a' + 4;
              startCode = 0;
            }
            else {
              MSL_C.PPCEABI.bare.H::strcpy(stageName,"sea");
              bVar3 = 0xb;
              startCode = 0;
            }
          }
        }
      }
    }
  }
  else {
    MSL_C.PPCEABI.bare.H::strcpy(stageName,pcVar2 + 4);
    bVar3 = pcVar2[0xc];
    startCode = pcVar2[0xd];
  }
  dSv_player_return_place_c::set
            (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace,stageName,bVar3,startCode);
  return;
}


/* __stdcall dComIfGs_gameStart(void) */

void dComIfGs_gameStart(void)

{
  g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext = 0;
  dComIfGp_setNextStage
            (g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace.mStageName,
             (ushort)g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace.mStartCode,
             g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace.mRoomNo,0xff,0_0,0,1,0);
  return;
}


/* __stdcall dComIfGs_copyPlayerRecollectionData(void) */

void dComIfGs_copyPlayerRecollectionData(void)

{
  int iVar1;
  byte local_78 [112];
  
  iVar1 = (*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)(0x803c9d58);
  if ((*(uint *)(iVar1 + 0xc) >> 0x10 & 7) == 3) {
    iVar1 = (*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)(0x803c9d58);
    if (*(byte *)(iVar1 + 9) >> 1 == 3) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)(0x803c9d58);
      if (*(byte *)(iVar1 + 9) >> 1 == 4) {
        iVar1 = 1;
      }
      else {
        iVar1 = (*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)(0x803c9d58);
        if (*(byte *)(iVar1 + 9) >> 1 == 6) {
          iVar1 = 2;
        }
        else {
          iVar1 = (*(code *)(g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)(0x803c9d58);
          if (*(byte *)(iVar1 + 9) >> 1 != 7) {
            return;
          }
          iVar1 = 3;
        }
      }
    }
    copy_bytes(local_78,(byte *)&g_dComIfG_gameInfo,0x18);
    copy_bytes(local_78 + 0x18,&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mTelescopeSlot,0x15);
    copy_bytes(local_78 + 0x2d,
               (byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.field_0x2,3);
    copy_bytes(local_78 + 0x30,(byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax,3);
    copy_bytes(local_78 + 0x33,g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0,0x18);
    copy_bytes(local_78 + 0x4b,(byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord,0x18
              );
    copy_bytes(local_78 + 99,g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData,0xd);
    copy_bytes((byte *)((int)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusC + iVar1 * 0x70),
               local_78,0x70);
  }
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall dComIfGs_setPlayerRecollectionData(void) */

void dComIfGs_setPlayerRecollectionData(undefined4 param_1,uchar param_2)

{
  short sVar1;
  short sVar2;
  dItem_data__ItemNo item;
  dItem_data__ItemNo item_00;
  dItem_data__ItemNo item_01;
  dItem_data__ItemNo item_02;
  byte item_03;
  byte bVar3;
  byte bVar4;
  dItem_data__ItemNo dVar5;
  undefined uVar6;
  undefined uVar7;
  undefined uVar8;
  undefined uVar9;
  undefined uVar10;
  undefined uVar11;
  undefined uVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  byte bVar19;
  int iVar20;
  
  daArrow_c::setKeepType((daArrow_c *)0x0,param_2);
  iVar20 = MSL_C.PPCEABI.bare.H::strcmp(g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss0");
  if ((iVar20 == 0) &&
     (iVar20 = dSv_event_c::isEventBit(&g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3d80), iVar20 != 0
     )) {
    iVar20 = 0;
    g_dComIfG_gameInfo._23744_1_ = 1;
  }
  else {
    iVar20 = MSL_C.PPCEABI.bare.H::strcmp(g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss1");
    if ((iVar20 == 0) &&
       (iVar20 = dSv_event_c::isEventBit(&g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3d40),
       iVar20 != 0)) {
      iVar20 = 1;
      g_dComIfG_gameInfo._23744_1_ = 2;
    }
    else {
      iVar20 = MSL_C.PPCEABI.bare.H::strcmp(g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss2");
      if ((iVar20 == 0) &&
         (iVar20 = dSv_event_c::isEventBit(&g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3d20),
         iVar20 != 0)) {
        iVar20 = 2;
        g_dComIfG_gameInfo._23744_1_ = 3;
      }
      else {
        iVar20 = MSL_C.PPCEABI.bare.H::strcmp
                           (g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss3");
        if (iVar20 != 0) {
          g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton[0] = -1;
          g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton[1] = -1;
          g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton[2] = -1;
          return;
        }
        iVar20 = dSv_event_c::isEventBit(&g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3d10);
        if (iVar20 == 0) {
          g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton[0] = -1;
          g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton[1] = -1;
          g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton[2] = -1;
          return;
        }
        iVar20 = 3;
        g_dComIfG_gameInfo._23744_1_ = 4;
      }
    }
  }
  bVar19 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[4];
  bVar18 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[3];
  bVar17 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[2];
  bVar16 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[1];
  bVar15 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[0];
  bVar14 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2;
  bVar13 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1;
  uVar12 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_;
  uVar11 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_;
  uVar10 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_;
  uVar9 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._17_1_;
  uVar8 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._16_1_;
  uVar7 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._15_1_;
  uVar6 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._14_1_;
  dVar5 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x8;
  bVar4 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic;
  bVar3 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic;
  item_03 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrentWalletIndex;
  item_02 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA._17_1_;
  item_01 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedBracelets;
  item_00 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedShield;
  item = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedSword;
  sVar2 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrHp;
  sVar1 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp;
  iVar20 = iVar20 * 0x70;
  if (*(char *)(&g_dComIfG_gameInfo.mSvInfo.mSave.field_0x1d4 + iVar20) == ' ') {
    copy_bytes((byte *)&g_dComIfG_gameInfo.field_0x5c50,(byte *)&g_dComIfG_gameInfo,0x18);
    copy_bytes((byte *)&g_dComIfG_gameInfo.field_0x5c68,
               &g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mTelescopeSlot,0x15);
    copy_bytes((byte *)&g_dComIfG_gameInfo.field_0x5c7d,
               (byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.field_0x2,3);
    copy_bytes((byte *)&g_dComIfG_gameInfo.field_0x5c80,
               (byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax,3);
    copy_bytes((byte *)&g_dComIfG_gameInfo.field_0x5c83,
               g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0,0x18);
    copy_bytes((byte *)&g_dComIfG_gameInfo.field_0x5c9b,
               (byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord,0x18);
    copy_bytes((byte *)&g_dComIfG_gameInfo.field_0x5cb3,
               g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData,0xd);
    copy_bytes((byte *)&g_dComIfG_gameInfo,
               (byte *)((int)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusC + iVar20),0x18);
    copy_bytes(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mTelescopeSlot,
               (byte *)(&g_dComIfG_gameInfo.mSvInfo.mSave.field_0x1d4 + iVar20),0x15);
    copy_bytes((byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.field_0x2,
               (byte *)(&g_dComIfG_gameInfo.mSvInfo.mSave.field_0x1e9 + iVar20),3);
    copy_bytes((byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax,
               (byte *)(&g_dComIfG_gameInfo.mSvInfo.mSave.field_0x1ec + iVar20),3);
    copy_bytes(g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0,
               (byte *)(&g_dComIfG_gameInfo.mSvInfo.mSave.field_0x1ef + iVar20),0x18);
    copy_bytes((byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord,
               (byte *)(&g_dComIfG_gameInfo.mSvInfo.mSave.field_0x207 + iVar20),0x18);
    copy_bytes(g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData,
               (byte *)(&g_dComIfG_gameInfo.mSvInfo.mSave.field_0x21f + iVar20),0xd);
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp = sVar1 & 0xff;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrHp = sVar2;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic = bVar3;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic = bVar4;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ = uVar10;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ = uVar11;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ = uVar12;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1 = bVar13;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2 = bVar14;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[0] = bVar15;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[1] = bVar16;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[2] = bVar17;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[3] = bVar18;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[4] = bVar19;
    dComIfGs_setSelectEquip(0,item);
    dComIfGs_setSelectEquip(1,item_00);
    dComIfGs_setSelectEquip(2,item_01);
    dComIfGs_setSelectEquip(3,item_02);
    dComIfGs_setSelectEquip(4,item_03);
    g_dComIfG_gameInfo._23511_1_ = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedSword;
    g_dComIfG_gameInfo._23512_1_ = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedShield
    ;
    g_dComIfG_gameInfo._23513_1_ =
         g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedBracelets;
    g_dComIfG_gameInfo._23514_1_ = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA._17_1_;
    g_dComIfG_gameInfo.field_0x5bdb =
         g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrentWalletIndex;
  }
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton[0] = -1;
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton[1] = -1;
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton[2] = -1;
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x8 = dVar5;
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._14_1_ = uVar6;
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._15_1_ = uVar7;
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._16_1_ = uVar8;
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._17_1_ = uVar9;
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* __stdcall dComIfGs_revPlayerRecollectionData(void) */

void dComIfGs_revPlayerRecollectionData(void)

{
  short sVar1;
  short sVar2;
  dItem_data__ItemNo item;
  dItem_data__ItemNo item_00;
  dItem_data__ItemNo item_01;
  dItem_data__ItemNo item_02;
  byte item_03;
  byte bVar3;
  byte bVar4;
  dItem_data__ItemNo dVar5;
  undefined uVar6;
  undefined uVar7;
  undefined uVar8;
  undefined uVar9;
  undefined uVar10;
  undefined uVar11;
  undefined uVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  byte bVar17;
  byte bVar18;
  byte bVar19;
  
  bVar19 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[4];
  bVar18 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[3];
  bVar17 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[2];
  bVar16 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[1];
  bVar15 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[0];
  bVar14 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2;
  bVar13 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1;
  uVar12 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_;
  uVar11 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_;
  uVar10 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_;
  uVar9 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._17_1_;
  uVar8 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._16_1_;
  uVar7 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._15_1_;
  uVar6 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._14_1_;
  dVar5 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x8;
  bVar4 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic;
  bVar3 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic;
  item_03 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrentWalletIndex;
  item_02 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA._17_1_;
  item_01 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedBracelets;
  item_00 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedShield;
  item = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedSword;
  sVar2 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrHp;
  sVar1 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp;
  if (g_dComIfG_gameInfo._23744_1_ != '\0') {
    g_dComIfG_gameInfo._23744_1_ = '\0';
    copy_bytes((byte *)&g_dComIfG_gameInfo,(byte *)&g_dComIfG_gameInfo.field_0x5c50,0x18);
    copy_bytes(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mTelescopeSlot,
               (byte *)&g_dComIfG_gameInfo.field_0x5c68,0x15);
    copy_bytes((byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.field_0x2,
               (byte *)&g_dComIfG_gameInfo.field_0x5c7d,3);
    copy_bytes((byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax,
               (byte *)&g_dComIfG_gameInfo.field_0x5c80,3);
    copy_bytes(g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0,
               (byte *)&g_dComIfG_gameInfo.field_0x5c83,0x18);
    copy_bytes((byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord,
               (byte *)&g_dComIfG_gameInfo.field_0x5c9b,0x18);
    copy_bytes(g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData,
               (byte *)&g_dComIfG_gameInfo.field_0x5cb3,0xd);
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp = sVar1 & 0xff;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrHp = sVar2;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic = bVar3;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic = bVar4;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ = uVar10;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ = uVar11;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ = uVar12;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1 = bVar13;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2 = bVar14;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[0] = bVar15;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[1] = bVar16;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[2] = bVar17;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[3] = bVar18;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[4] = bVar19;
    dComIfGs_setSelectEquip(0,item);
    dComIfGs_setSelectEquip(1,item_00);
    dComIfGs_setSelectEquip(2,item_01);
    dComIfGs_setSelectEquip(3,item_02);
    dComIfGs_setSelectEquip(4,item_03);
    g_dComIfG_gameInfo._23511_1_ = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedSword;
    g_dComIfG_gameInfo._23512_1_ = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedShield
    ;
    g_dComIfG_gameInfo._23513_1_ =
         g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedBracelets;
    g_dComIfG_gameInfo._23514_1_ = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA._17_1_;
    g_dComIfG_gameInfo.field_0x5bdb =
         g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrentWalletIndex;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton[0] = -1;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton[1] = -1;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton[2] = -1;
  }
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x8 = dVar5;
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._14_1_ = uVar6;
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._15_1_ = uVar7;
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._16_1_ = uVar8;
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._17_1_ = uVar9;
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* __stdcall dComIfGs_exchangePlayerRecollectionData(void) */

void dComIfGs_exchangePlayerRecollectionData(void)

{
  dItem_data__ItemNo item;
  dItem_data__ItemNo item_00;
  dItem_data__ItemNo item_01;
  dItem_data__ItemNo item_02;
  byte item_03;
  dItem_data__ItemNo dVar1;
  undefined uVar2;
  undefined uVar3;
  undefined uVar4;
  undefined uVar5;
  byte bVar6;
  byte abStack200 [24];
  byte abStack176 [21];
  byte abStack155 [3];
  byte abStack152 [3];
  byte abStack149 [24];
  byte abStack125 [24];
  byte abStack101 [13];
  byte local_58;
  byte local_57;
  byte local_56;
  byte local_55;
  undefined local_54;
  undefined local_53;
  byte local_52;
  undefined local_51;
  byte local_50;
  byte local_4f;
  byte local_4e;
  short local_4c;
  ushort local_4a;
  
  bVar6 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[4];
  uVar5 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._17_1_;
  uVar4 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._16_1_;
  uVar3 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._15_1_;
  uVar2 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._14_1_;
  dVar1 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x8;
  item_03 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrentWalletIndex;
  item_02 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA._17_1_;
  item_01 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedBracelets;
  item_00 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedShield;
  item = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedSword;
  if (g_dComIfG_gameInfo._23744_1_ != '\0') {
    local_4a = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp;
    local_4c = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrHp;
    local_4e = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic;
    local_4f = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic;
    local_50 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1;
    local_51 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_;
    local_52 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2;
    local_53 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_;
    local_54 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_;
    local_55 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[0];
    local_56 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[1];
    local_57 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[2];
    local_58 = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[3];
    copy_bytes(abStack200,(byte *)&g_dComIfG_gameInfo.field_0x5c50,0x70);
    copy_bytes((byte *)&g_dComIfG_gameInfo.field_0x5c50,(byte *)&g_dComIfG_gameInfo,0x18);
    copy_bytes((byte *)&g_dComIfG_gameInfo.field_0x5c68,
               &g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mTelescopeSlot,0x15);
    copy_bytes((byte *)&g_dComIfG_gameInfo.field_0x5c7d,
               (byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.field_0x2,3);
    copy_bytes((byte *)&g_dComIfG_gameInfo.field_0x5c80,
               (byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax,3);
    copy_bytes((byte *)&g_dComIfG_gameInfo.field_0x5c83,
               g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0,0x18);
    copy_bytes((byte *)&g_dComIfG_gameInfo.field_0x5c9b,
               (byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord,0x18);
    copy_bytes((byte *)&g_dComIfG_gameInfo.field_0x5cb3,
               g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData,0xd);
    copy_bytes((byte *)&g_dComIfG_gameInfo,abStack200,0x18);
    copy_bytes(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mTelescopeSlot,abStack176,0x15);
    copy_bytes((byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.field_0x2,abStack155,3)
    ;
    copy_bytes((byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax,abStack152,3);
    copy_bytes(g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0,abStack149,0x18);
    copy_bytes((byte *)&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord,abStack125,0x18);
    copy_bytes(g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData,abStack101,0xd);
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp = local_4a & 0xff;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrHp = local_4c;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic = local_4e;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic = local_4f;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1 = local_50;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ = local_51;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2 = local_52;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ = local_53;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ = local_54;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[0] = local_55;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[1] = local_56;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[2] = local_57;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[3] = local_58;
    g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData[4] = bVar6;
    dComIfGs_setSelectEquip(0,item);
    dComIfGs_setSelectEquip(1,item_00);
    dComIfGs_setSelectEquip(2,item_01);
    dComIfGs_setSelectEquip(3,item_02);
    dComIfGs_setSelectEquip(4,item_03);
    g_dComIfG_gameInfo._23511_1_ = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedSword;
    g_dComIfG_gameInfo._23512_1_ = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedShield
    ;
    g_dComIfG_gameInfo._23513_1_ =
         g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mEquippedBracelets;
    g_dComIfG_gameInfo._23514_1_ = g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA._17_1_;
    g_dComIfG_gameInfo.field_0x5bdb =
         g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrentWalletIndex;
  }
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x8 = dVar1;
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._14_1_ = uVar2;
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._15_1_ = uVar3;
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._16_1_ = uVar4;
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._17_1_ = uVar5;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __stdcall dComIfGs_setSelectEquip(int,
                                     unsigned char) */

void dComIfGs_setSelectEquip(int category,dItem_data__ItemNo item)

{
  if (category == 1) {
    if (item == MirrorShield) {
      dSv_player_collect_c::onCollect(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,1,1);
    }
    else {
      if ((item < MirrorShield) && (MasterSwordHalfPower < item)) {
        dSv_player_collect_c::onCollect(&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,1,0);
      }
    }
  }
  else {
    if (category < 1) {
      if (-1 < category) {
        if (item == MasterSwordHalfPower) {
          dSv_player_collect_c::onCollect
                    (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,category,2);
        }
        else {
          if (item < MasterSwordHalfPower) {
            if (item == HerosSword) {
              dSv_player_collect_c::onCollect
                        (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,category,0);
            }
            else {
              if (HerosNewClothes < item) {
                dSv_player_collect_c::onCollect
                          (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,category,1);
              }
            }
          }
          else {
            if (item == MasterSwordFullPower) {
              dSv_player_collect_c::onCollect
                        (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,category,3);
            }
          }
        }
      }
    }
    else {
      if ((category < 3) && (item == PowerBracelets)) {
        dSv_player_collect_c::onCollect
                  (&g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,category,0);
      }
    }
  }
  g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton[category + 5] = item
  ;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */

void __sinit_d_com_inf_game_cpp(void)

{
  Runtime.PPCEABI.H::__construct_array
            (g_dComIfG_gameInfo.mSvInfo.mSave.mMemory,::dSv_memory_c::dSv_memory_c,(undefined *)0x0,
             0x24,0x10);
  ::dSv_memory_c::init(&g_dComIfG_gameInfo.mSvInfo.mMemory);
  Runtime.PPCEABI.H::__construct_array
            (g_dComIfG_gameInfo.mSvInfo.mZone,::dSv_zone_c::dSv_zone_c,(undefined *)0x0,0x4c,0x20);
  g_dComIfG_gameInfo.mPlay.mBgS.parent.field_0x1400 = (undefined *)&::cBgS::__vt;
  Runtime.PPCEABI.H::__construct_array
            (&g_dComIfG_gameInfo.mPlay,::cBgS_ChkElm::cBgS_ChkElm,::cBgS_ChkElm::_cBgS_ChkElm,0x14,
             0x100);
  g_dComIfG_gameInfo.mPlay.mBgS.parent.field_0x1400 = (undefined *)&::dBgS::__vt;
  ::cCcS::cCcS(&g_dComIfG_gameInfo.mPlay.mCcS.parent);
  g_dComIfG_gameInfo.mPlay.mCcS.parent.vtbl = (cCcS__vtbl *)&::dCcS::__vt;
  ::dCcMassS_Mng::dCcMassS_Mng(&g_dComIfG_gameInfo.mPlay.mCcS.mMassMng);
  dADM::dADM(&g_dComIfG_gameInfo.mPlay.mADM);
  g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext = 0;
  g_dComIfG_gameInfo.mPlay.mStageData.parent = (dStage_dt_c__vtbl *)&dStage_stageDt_c::__vt;
  dEvt_control_c::dEvt_control_c(&g_dComIfG_gameInfo.mPlay.mEvtCtrl);
  dEvDtBase_c::init(&g_dComIfG_gameInfo.mPlay.mEventMgr.parent);
  g_dComIfG_gameInfo.mPlay.mEventMgr.mException.mEventInfoIdx = 0xffffffff;
  g_dComIfG_gameInfo.mPlay.mAttention._8_4_ = &::dAttDraw_CallBack_c::__vt;
  g_dComIfG_gameInfo.mPlay.mAttention.mAttParam.vtbl = &dAttParam_c::__vt;
  dVibration_c::dVibration_c(&g_dComIfG_gameInfo.mPlay.mVibration);
  dDetect_c::dDetect_c(&g_dComIfG_gameInfo.mPlay.mDetect);
  Runtime.PPCEABI.H::__construct_array
            (g_dComIfG_gameInfo.mPlay.mDlstWindow,::dDlst_window_c::dDlst_window_c,
             ::dDlst_window_c::_dDlst_window_c,0x2c,1);
  Runtime.PPCEABI.H::__construct_array
            (g_dComIfG_gameInfo.mPlay.mCameraInfo,
             ::dComIfG_camera_info_class::dComIfG_camera_info_class,
             ::dComIfG_camera_info_class::_dComIfG_camera_info_class,0x34,1);
  g_dComIfG_gameInfo._23788_4_ = 0xffffffff;
  g_dComIfG_gameInfo._23784_4_ = 0;
  g_dComIfG_gameInfo._23780_4_ = 0;
  g_dComIfG_gameInfo.mpRestartTimer = (dTimer_c *)0x0;
  ::dComIfG_play_c::ct(&g_dComIfG_gameInfo.mPlay);
  dDlst_list_c::dDlst_list_c(&g_dComIfG_gameInfo.mDlstList);
  Runtime.PPCEABI.H::__construct_array
            (&g_dComIfG_gameInfo.mResCtrl,dRes_info_c::dRes_info_c,dRes_info_c::_dRes_info_c,0x24,
             0x40);
  Runtime.PPCEABI.H::__construct_array
            (g_dComIfG_gameInfo.mResCtrl.mStageInfo,dRes_info_c::dRes_info_c,
             dRes_info_c::_dRes_info_c,0x24,0x40);
  ::dComIfG_inf_c::ct(&g_dComIfG_gameInfo);
  Runtime.PPCEABI.H::__register_global_object
            (&g_dComIfG_gameInfo,::dComIfG_inf_c::_dComIfG_inf_c,&_4576);
  return;
}

}

/* __thiscall dComIfG_inf_c::~dComIfG_inf_c(void) */

void __thiscall dComIfG_inf_c::_dComIfG_inf_c(dComIfG_inf_c *this)

{
  short in_r4;
  
  if (this != (dComIfG_inf_c *)0x0) {
    dRes_control_c::_dRes_control_c(&this->mResCtrl);
    dDlst_list_c::_dDlst_list_c(&this->mDlstList);
    dComIfG_play_c::_dComIfG_play_c(&this->mPlay);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dComIfG_play_c::~dComIfG_play_c(void) */

void __thiscall dComIfG_play_c::_dComIfG_play_c(dComIfG_play_c *this)

{
  short in_r4;
  
  if (this != (dComIfG_play_c *)0x0) {
    Runtime.PPCEABI.H::__destroy_arr
              (this->mCameraInfo,dComIfG_camera_info_class::_dComIfG_camera_info_class,0x34,1);
    Runtime.PPCEABI.H::__destroy_arr(this->mDlstWindow,dDlst_window_c::_dDlst_window_c,0x2c,1);
    dDetect_c::_dDetect_c(&this->mDetect);
    dVibration_c::_dVibration_c(&this->mVibration);
    dAttention_c::_dAttention_c(&this->mAttention);
    if (this != (dComIfG_play_c *)0xffffc0c8) {
      Runtime.PPCEABI.H::__destroy_arr(&this->mEvtCtrl,dEvt_order_c::_dEvt_order_c,0x18,8);
    }
    if ((this != (dComIfG_play_c *)0xffffc150) &&
       ((this->mStageData).parent.vtbl = (dStage_dt_c__vtbl *)&dStage_stageDt_c::__vt,
       this != (dComIfG_play_c *)0xffffc150)) {
      (this->mStageData).parent.vtbl = (dStage_dt_c__vtbl *)&dStage_dt_c::__vt;
    }
    dADM::_dADM(&this->mADM);
    dCcS::_dCcS(&this->mCcS);
    if ((this != (dComIfG_play_c *)0x0) &&
       ((this->mBgS).parent.field_0x1400 = (undefined *)&dBgS::__vt, this != (dComIfG_play_c *)0x0))
    {
      (this->mBgS).parent.field_0x1400 = (undefined *)&cBgS::__vt;
      Runtime.PPCEABI.H::__destroy_arr(this,cBgS_ChkElm::_cBgS_ChkElm,0x14,0x100);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dEvt_order_c::~dEvt_order_c(void) */

void __thiscall dEvt_order_c::_dEvt_order_c(dEvt_order_c *this)

{
  short in_r4;
  
  if ((this != (dEvt_order_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dComIfG_camera_info_class::~dComIfG_camera_info_class(void) */

void __thiscall
dComIfG_camera_info_class::_dComIfG_camera_info_class(dComIfG_camera_info_class *this)

{
  short in_r4;
  
  if ((this != (dComIfG_camera_info_class *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dComIfG_camera_info_class::dComIfG_camera_info_class(void) */

void __thiscall
dComIfG_camera_info_class::dComIfG_camera_info_class(dComIfG_camera_info_class *this)

{
  return;
}


/* __thiscall dDlst_window_c::~dDlst_window_c(void) */

void __thiscall dDlst_window_c::_dDlst_window_c(dDlst_window_c *this)

{
  short in_r4;
  
  if ((this != (dDlst_window_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dDlst_window_c::dDlst_window_c(void) */

void __thiscall dDlst_window_c::dDlst_window_c(dDlst_window_c *this)

{
  return;
}


/* __thiscall dAttDraw_CallBack_c::~dAttDraw_CallBack_c(void) */

void __thiscall dAttDraw_CallBack_c::_dAttDraw_CallBack_c(dAttDraw_CallBack_c *this)

{
  short in_r4;
  
  if (this != (dAttDraw_CallBack_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dAttDraw_CallBack_c *)0x0) {
      *(mDoExt_McaMorfCallBack1_c__vtbl **)this = &mDoExt_McaMorfCallBack1_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall mDoExt_McaMorfCallBack1_c::~mDoExt_McaMorfCallBack1_c(void) */

void __thiscall
mDoExt_McaMorfCallBack1_c::_mDoExt_McaMorfCallBack1_c(mDoExt_McaMorfCallBack1_c *this)

{
  short in_r4;
  
  if ((this != (mDoExt_McaMorfCallBack1_c *)0x0) && (this->vtbl = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dCcS::~dCcS(void) */

void __thiscall dCcS::_dCcS(dCcS *this)

{
  short in_r4;
  
  if (this != (dCcS *)0x0) {
    (this->parent).vtbl = (cCcS__vtbl *)&__vt;
    dCcMassS_Mng::_dCcMassS_Mng(&this->mMassMng);
    if (this != (dCcS *)0x0) {
      (this->parent).vtbl = (cCcS__vtbl *)&cCcS::__vt;
      if (this != (dCcS *)0xffffd7f0) {
        (this->parent).mDivideArea.mAab.vtbl = (cM3dGAab__vtbl *)&cCcD_DivideArea::__vt;
        if (this != (dCcS *)0xffffd7f0) {
          (this->parent).mDivideArea.mAab.vtbl = &::cM3dGAab::__vt;
        }
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dCcMassS_Mng::~dCcMassS_Mng(void) */

void __thiscall dCcMassS_Mng::_dCcMassS_Mng(dCcMassS_Mng *this)

{
  short in_r4;
  
  if (this != (dCcMassS_Mng *)0x0) {
    this->vtbl = (undefined *)&__vt;
    if (this != (dCcMassS_Mng *)0xfffffe6c) {
      (this->mDivideInfo).vtbl = (undefined *)&cCcD_DivideInfo::__vt;
    }
    if (this != (dCcMassS_Mng *)0xfffffeac) {
      (this->mCpsAttr).parent.vtbl = &::cCcD_CpsAttr::__vt;
      (this->mCpsAttr).mCps.parent.vtbl = &DAT_8039520c;
      if (this != (dCcMassS_Mng *)0xfffffe8c) {
        (this->mCpsAttr).mCps.parent.vtbl = (undefined *)&::cM3dGCps::__vt;
        if (this != (dCcMassS_Mng *)0xfffffe8c) {
          (this->mCpsAttr).mCps.parent.vtbl = (undefined *)&::cM3dGLin::__vt;
        }
      }
      if (this != (dCcMassS_Mng *)0xfffffeac) {
        (this->mCpsAttr).parent.vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_ShapeAttr::__vt;
        if (this != (dCcMassS_Mng *)0xfffffeac) {
          (this->mCpsAttr).parent.mAab.vtbl = &::cM3dGAab::__vt;
        }
      }
    }
    if (this != (dCcMassS_Mng *)0xffffff10) {
      (this->mCylAttr).parent.vtbl = &::cCcD_CylAttr::__vt;
      (this->mCylAttr).mCyl.vtbl = &cCcD_CylAttr__vtbl_803951ac;
      if (this != (dCcMassS_Mng *)0xfffffef0) {
        (this->mCylAttr).mCyl.vtbl = (cCcD_CylAttr__vtbl *)&::cM3dGCyl::__vt;
      }
      if ((this != (dCcMassS_Mng *)0xffffff10) &&
         ((this->mCylAttr).parent.vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_ShapeAttr::__vt,
         this != (dCcMassS_Mng *)0xffffff10)) {
        (this->mCylAttr).parent.mAab.vtbl = &::cM3dGAab::__vt;
      }
    }
    Runtime.PPCEABI.H::__destroy_arr(this->mMassAreas,dCcMassS_Obj::_dCcMassS_Obj,0x18,2);
    Runtime.PPCEABI.H::__destroy_arr(this->mMassObjs,dCcMassS_Obj::_dCcMassS_Obj,0x18,5);
    if ((this != (dCcMassS_Mng *)0x0) &&
       ((this->mDivideArea).mAab.vtbl = (cM3dGAab__vtbl *)&cCcD_DivideArea::__vt,
       this != (dCcMassS_Mng *)0x0)) {
      (this->mDivideArea).mAab.vtbl = &::cM3dGAab::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dCcMassS_Obj::~dCcMassS_Obj(void) */

void __thiscall dCcMassS_Obj::_dCcMassS_Obj(dCcMassS_Obj *this)

{
  short in_r4;
  
  if (this != (dCcMassS_Obj *)0x0) {
    this->vtbl = (undefined *)&__vt;
    if (this != (dCcMassS_Obj *)0xfffffff4) {
      (this->mDivideInfo).vtbl = (undefined *)&cCcD_DivideInfo::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cCcS::~cCcS(void) */

void __thiscall cCcS::_cCcS(cCcS *this)

{
  short in_r4;
  
  if (this != (cCcS *)0x0) {
    this->vtbl = (cCcS__vtbl *)&__vt;
    if (this != (cCcS *)0xffffd7f0) {
      (this->mDivideArea).mAab.vtbl = (cM3dGAab__vtbl *)&cCcD_DivideArea::__vt;
      if (this != (cCcS *)0xffffd7f0) {
        (this->mDivideArea).mAab.vtbl = &::cM3dGAab::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dBgS::~dBgS(void) */

void __thiscall dBgS::_dBgS(dBgS *this)

{
  short in_r4;
  
  if (this != (dBgS *)0x0) {
    (this->parent).field_0x1400 = (undefined *)&__vt;
    if (this != (dBgS *)0x0) {
      (this->parent).field_0x1400 = (undefined *)&cBgS::__vt;
      Runtime.PPCEABI.H::__destroy_arr(this,cBgS_ChkElm::_cBgS_ChkElm,0x14,0x100);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cBgS::~cBgS(void) */

void __thiscall cBgS::_cBgS(cBgS *this)

{
  short in_r4;
  
  if (this != (cBgS *)0x0) {
    this->field_0x1400 = (undefined *)&__vt;
    Runtime.PPCEABI.H::__destroy_arr(this,cBgS_ChkElm::_cBgS_ChkElm,0x14,0x100);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cBgS_ChkElm::~cBgS_ChkElm(void) */

void __thiscall cBgS_ChkElm::_cBgS_ChkElm(cBgS_ChkElm *this)

{
  short in_r4;
  
  if ((this != (cBgS_ChkElm *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall cBgS_ChkElm::cBgS_ChkElm(void) */

void __thiscall cBgS_ChkElm::cBgS_ChkElm(cBgS_ChkElm *this)

{
  this->vtbl = (undefined *)&__vt;
  Init(this);
  return;
}


/* __thiscall dSv_zone_c::dSv_zone_c(void) */

void __thiscall dSv_zone_c::dSv_zone_c(dSv_zone_c *this)

{
  this->mRoomIdx = 0xff;
  return;
}


/* __thiscall dSv_memory_c::dSv_memory_c(void) */

void __thiscall dSv_memory_c::dSv_memory_c(dSv_memory_c *this)

{
  init(this);
  return;
}


/* __thiscall cM3dGCyl::~cM3dGCyl(void) */

void __thiscall cM3dGCyl::_cM3dGCyl(cM3dGCyl *this)

{
  short in_r4;
  
  if ((this != (cM3dGCyl *)0x0) && (this->vtbl = (cCcD_CylAttr__vtbl *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall cCcD_ShapeAttr::~cCcD_ShapeAttr(void) */

void __thiscall cCcD_ShapeAttr::_cCcD_ShapeAttr(cCcD_ShapeAttr *this)

{
  short in_r4;
  
  if (this != (cCcD_ShapeAttr *)0x0) {
    this->vtbl = (cCcD_ShapeAttr__vtbl *)&__vt;
    if (this != (cCcD_ShapeAttr *)0x0) {
      (this->mAab).vtbl = &::cM3dGAab::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cCcD_ShapeAttr::CrossAtTg(cCcD_ShapeAttr const &,
                                        cXyz *) const */

undefined4 __thiscall
cCcD_ShapeAttr::CrossAtTg(cCcD_ShapeAttr *this,cCcD_ShapeAttr *param_1,cXyz *param_2)

{
  return 0;
}


/* __thiscall cCcD_ShapeAttr::CrossCo(cCcD_ShapeAttr const &,
                                      float *) const */

undefined4 __thiscall
cCcD_ShapeAttr::CrossCo(cCcD_ShapeAttr *this,cCcD_ShapeAttr *param_1,float *param_2)

{
  return 0;
}


/* __thiscall cCcD_ShapeAttr::GetCoCP(void) */

cXyz * __thiscall cCcD_ShapeAttr::GetCoCP(cCcD_ShapeAttr *this)

{
  return &m_virtual_center;
}


/* __thiscall cCcD_ShapeAttr::GetCoCP(void) const */

cXyz * __thiscall cCcD_ShapeAttr::GetCoCP(cCcD_ShapeAttr *this)

{
  return &m_virtual_center;
}


/* __thiscall cM3dGCps::~cM3dGCps(void) */

void __thiscall cM3dGCps::_cM3dGCps(cM3dGCps *this)

{
  short in_r4;
  
  if (this != (cM3dGCps *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    if (this != (cM3dGCps *)0x0) {
      (this->parent).vtbl = (undefined *)&::cM3dGLin::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cCcD_DivideInfo::~cCcD_DivideInfo(void) */

void __thiscall cCcD_DivideInfo::_cCcD_DivideInfo(cCcD_DivideInfo *this)

{
  short in_r4;
  
  if ((this != (cCcD_DivideInfo *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall cM3dGAab::~cM3dGAab(void) */

void __thiscall cM3dGAab::_cM3dGAab(cM3dGAab *this)

{
  short in_r4;
  
  if ((this != (cM3dGAab *)0x0) && (this->vtbl = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall cCcD_DivideArea::~cCcD_DivideArea(void) */

void __thiscall cCcD_DivideArea::_cCcD_DivideArea(cCcD_DivideArea *this)

{
  short in_r4;
  
  if (this != (cCcD_DivideArea *)0x0) {
    (this->mAab).vtbl = (cM3dGAab__vtbl *)&__vt;
    if (this != (cCcD_DivideArea *)0x0) {
      (this->mAab).vtbl = &::cM3dGAab::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

