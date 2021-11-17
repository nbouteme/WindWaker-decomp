#include <d_s_room.h>
#include <d_map.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <f_pc_manager.h>
#include <f_op_actor_mng.h>
#include <d_stage.h>
#include <d_s_room.h>
#include <f_pc_layer_iter.h>
#include <d_save.h>
#include <f_op_scene_mng.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_resorce.h>
#include <d_particle.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_com_static.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRExpHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_com_inf_game.h>
#include <d_com_lib_game.h>


namespace d_s_room {
undefined arcName$4176;

/* __stdcall setMapImage(room_of_scene_class *) */

void setMapImage(room_of_scene_class *param_1)

{
  if ((param_1->mbSetMap == 0) && (-1 < (char)::dStage_roomControl_c::mStayNo)) {
    dMap_c::setImage((param_1->parent).parent.parent.mParameters,
                     (int)(char)::dStage_roomControl_c::mStayNo,
                     ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                     mCurrent.mPos.y);
    param_1->mbSetMap = 1;
  }
  return;
}


/* __stdcall deleteMapImage(room_of_scene_class *) */

void deleteMapImage(int param_1,int param_2)

{
  if (*(char *)(param_1 + 0x1da) != '\0') {
    dMap_c::deleteImage(*(dMap_c **)(param_1 + 0xb0),param_2);
  }
  return;
}


/* __stdcall setArcName(room_of_scene_class *) */

char * setArcName(room_of_scene_class *param_1)

{
  MSL_C.PPCEABI.bare.H::sprintf(&arcName_4176,"Room%d",(param_1->parent).parent.parent.mParameters);
  return &arcName_4176;
}


/* __stdcall dScnRoom_Draw(room_of_scene_class *) */

undefined4 dScnRoom_Draw(void)

{
  return 1;
}


/* __stdcall deleteJugge(void *,
                         void *) */

undefined4 deleteJugge(base_process_class *param_1)

{
  f_pc_manager::fpcM_Delete(param_1);
  return 0;
}


/* __stdcall objectSetCheck(room_of_scene_class *) */

void objectSetCheck(room_of_scene_class *param_1)

{
  int iVar1;
  ulong roomIdx;
  
  roomIdx = (param_1->parent).parent.parent.mParameters;
  if (param_1->mbReLoaded == 0) {
    if ((::dStage_roomControl_c::mStatus[roomIdx].mFlags & Hidden) == 0) {
      f_op_actor_mng::fopAcM_create
                (0x1bc,roomIdx,(cXyz *)0x0,-1,(csXyz *)0x0,(cXyz *)0x0,0xff,(undefined *)0x0);
      d_stage::dStage_dt_c_roomReLoader(param_1->mpRoomData,param_1->mpRoomStatus,roomIdx);
      param_1->mbReLoaded = 1;
    }
  }
  else {
    if ((::dStage_roomControl_c::mStatus[roomIdx].mFlags & Hidden) != 0) {
      f_pc_layer_iter::fpcLyIt_Judge(&(param_1->parent).parent.mLayer,deleteJugge,0);
      iVar1 = ::dStage_roomControl_c::getZoneNo(roomIdx);
      dSv_zoneBit_c::clearRoomSwitch
                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mZone[iVar1].mZoneBit);
      param_1->mbReLoaded = 0;
    }
  }
  return;
}


/* __stdcall dScnRoom_Execute(room_of_scene_class *) */

undefined4 dScnRoom_Execute(room_of_scene_class *param_1)

{
  int roomIdx;
  RoomStatusFlags flags;
  RoomStatusFlags *pFlags;
  
                    /* mRoomIdx */
  roomIdx = (param_1->parent).parent.parent.mParameters;
  setMapImage(param_1);
  pFlags = &::dStage_roomControl_c::mStatus[roomIdx].mFlags;
  flags = *pFlags;
  if ((flags & IsUnloading) == 0) {
    if ((flags & IsLoading) == 0) {
      objectSetCheck(param_1);
    }
    else {
      *pFlags = flags & ~IsLoading;
      *pFlags = *pFlags | Loaded;
    }
  }
  else {
    f_op_scene_mng::fopScnM_DeleteReq(&param_1->parent);
  }
  return 1;
}


/* __stdcall dScnRoom_IsDelete(room_of_scene_class *) */

undefined4 dScnRoom_IsDelete(void)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dScnRoom_Delete(room_of_scene_class *) */

undefined4 dScnRoom_Delete(room_of_scene_class *param_1)

{
  char *pName;
  dStage_roomStatus_c *pdVar1;
  int iVar2;
  JKRHeap *this;
  char cVar3;
  int iVar4;
  
  iVar4 = (param_1->parent).parent.parent.mParameters;
  deleteMapImage();
  pName = setArcName(param_1);
  dRes_control_c::deleteRes(pName,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
  ::dStage_roomControl_c::mStatus[iVar4].mFlags = 0;
  pdVar1 = ::dStage_roomControl_c::getStatusRoomDt
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,iVar4);
  (*(code *)((pdVar1->parent).parent.vtbl)->init)();
  if (param_1->mbHasRoomParticle != 0) {
    dPa_control_c::removeRoomScene(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl);
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext == 0) {
    if (*(short *)&param_1->field_0x1dc == 1) {
      dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1a80);
    }
    iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea");
    if (iVar2 == 0) {
      dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,800);
    }
  }
  if (*(short *)&param_1->field_0x1dc == 2) {
    dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1c40);
  }
  cVar3 = 'w';
  iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea");
  if (iVar2 == 0) {
    daNpc_Md_c::m_seaTalk = 0;
  }
  daSalvage_c::init_room((daSalvage_c *)(int)(char)iVar4,cVar3);
  this = ::dStage_roomControl_c::getMemoryBlock(iVar4);
  if (this != (JKRHeap *)0x0) {
    JKRHeap::freeAll(this);
  }
  return 1;
}


/* __stdcall phase_0(room_of_scene_class *) */

int phase_0(room_of_scene_class *param_1)

{
  uint uVar1;
  
  if (param_1 == (room_of_scene_class *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (param_1->parent).parent.parent.mBsPcId;
  }
  ::dStage_roomControl_c::mStatus[(param_1->parent).parent.parent.mParameters].mRoomBsPcId = uVar1;
  return 2;
}


/* __stdcall phase_1(room_of_scene_class *) */

undefined4 phase_1(room_of_scene_class *param_1)

{
  JKRExpHeap *this;
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  this = (JKRExpHeap *)
         ::dStage_roomControl_c::getMemoryBlock((param_1->parent).parent.parent.mParameters);
  if ((this == (JKRExpHeap *)0x0) || (iVar1 = JKRExpHeap::getTotalUsedSize(this), iVar1 == 0)) {
    pcVar3 = setArcName(param_1);
    iVar1 = dRes_control_c::setStageRes
                      (&d_com_inf_game::g_dComIfG_gameInfo.mResCtrl,pcVar3,(JKRHeap *)this);
    if (iVar1 == 0) {
      d_stage::dStage_escapeRestart();
      uVar2 = 5;
    }
    else {
      uVar2 = 2;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall phase_2(room_of_scene_class *) */

undefined4 phase_2(room_of_scene_class *param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  ulong uVar4;
  dStage_roomStatus_c *pStatus;
  undefined *puVar5;
  dStage_roomStatus_c *pdVar6;
  dStage_Lbnk_c *pLbnk;
  uint uVar7;
  dStage_FileList_dt_c *pFili;
  byte bHasRoomParticle;
  int roomIdx;
  byte *pBanks;
  
  pcVar1 = setArcName(param_1);
  iVar2 = dRes_control_c::syncRes
                    (pcVar1,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
  if (iVar2 < 0) {
    d_stage::dStage_escapeRestart();
    uVar3 = 5;
  }
  else {
    if (iVar2 < 0) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_s_room.cpp",0x1c0,"rt >= 0");
      m_Do_printf::OSPanic("d_s_room.cpp",0x1c0,&DAT_80363790);
    }
    if (iVar2 == 0) {
      roomIdx = (param_1->parent).parent.parent.mParameters;
      iVar2 = ::dStage_roomControl_c::getZoneNo(roomIdx);
      if (iVar2 < 0) {
        iVar2 = dSv_info_c::createZone(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,roomIdx);
        ::dStage_roomControl_c::setZoneNo(roomIdx,iVar2);
      }
      pStatus = ::dStage_roomControl_c::getStatusRoomDt
                          (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,roomIdx);
      param_1->mpRoomStatus = pStatus;
      (param_1->mpRoomStatus->parent).mRoomNo = (byte)roomIdx;
      puVar5 = (undefined *)
               dRes_control_c::getRes
                         (pcVar1,"room.dzr",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,
                          0x40);
      param_1->mpRoomData = puVar5;
      if (param_1->mpRoomData != (undefined *)0x0) {
        d_stage::dStage_dt_c_roomLoader(param_1->mpRoomData,param_1->mpRoomStatus);
        if (::dStage_roomControl_c::mDemoArcName[0] == '\0') {
          pdVar6 = ::dStage_roomControl_c::getStatusRoomDt
                             (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,roomIdx);
          pLbnk = (dStage_Lbnk_c *)(*(code *)((pdVar6->parent).parent.vtbl)->getLbnk)();
          if ((pLbnk != (dStage_Lbnk_c *)0x0) && (pBanks = pLbnk->mpBanks, pBanks != (byte *)0x0)) {
            uVar7 = dComIfG_play_c::getLayerNo(roomIdx);
            uVar7 = (uint)pBanks[uVar7];
            if (uVar7 != 0xff) {
              if (99 < uVar7) {
                uVar4 = JUTAssertion::getSDevice();
                JUTAssertion::showAssert(uVar4,"d_s_room.cpp",0x1db,"0 <= bank && bank < 100");
                m_Do_printf::OSPanic("d_s_room.cpp",0x1db,&DAT_80363790);
              }
              MSL_C.PPCEABI.bare.H::sprintf(::dStage_roomControl_c::mDemoArcName,"Demo%02d",uVar7);
              pcVar1 = ::dStage_roomControl_c::mDemoArcName;
              dRes_control_c::setRes
                        (::dStage_roomControl_c::mDemoArcName,
                         d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40,"/res/Object/"
                         ,0,(JKRHeap *)0x0);
              if (pcVar1 == (char *)0x0) {
                ::dStage_roomControl_c::mDemoArcName[0] = '\0';
              }
            }
          }
        }
        pdVar6 = ::dStage_roomControl_c::getStatusRoomDt
                           (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,roomIdx);
        pFili = (dStage_FileList_dt_c *)(*(code *)((pdVar6->parent).parent.vtbl)->getFileListInfo)()
        ;
        if (pFili == (dStage_FileList_dt_c *)0x0) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar4,"d_s_room.cpp",499,"fileList != 0");
          m_Do_printf::OSPanic("d_s_room.cpp",499,&DAT_80363790);
        }
        iVar2 = dPa_control_c::readScene
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,
                           (uchar)((uint)pFili->mParam >> 0x15),&param_1->mDoDvdParticle);
        param_1->mbHasRoomParticle = (byte)iVar2;
      }
      uVar3 = 2;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}

}

namespace dStage_roomControl_c {

/* __thiscall setZoneNo(int,
                                              int) */

void setZoneNo(int param_1,int param_2)

{
  mStatus[param_1].mZoneNo = (byte)param_2;
  return;
}

}

namespace d_s_room {

/* __stdcall phase_3(room_of_scene_class *) */

undefined4 phase_3(room_of_scene_class *param_1)

{
  int iVar1;
  mDoDvdThd_toMainRam_c *pmVar2;
  ulong uVar3;
  
  if (::dStage_roomControl_c::mDemoArcName[0] != '\0') {
    iVar1 = dRes_control_c::syncRes
                      (::dStage_roomControl_c::mDemoArcName,
                       d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (iVar1 < 0) {
      d_stage::dStage_escapeRestart();
      return 5;
    }
    if (0 < iVar1) {
      return 0;
    }
  }
  pmVar2 = param_1->mDoDvdParticle;
  if (pmVar2 != (mDoDvdThd_toMainRam_c *)0x0) {
    if ((pmVar2->parent).mStatus == 0) {
      return 0;
    }
    if (pmVar2->mpArchiveHeader == (JKRArchive__Header *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar3,"d_s_room.cpp",0x215,"i_this->sceneCommand->getMemAddress() != 0");
      m_Do_printf::OSPanic("d_s_room.cpp",0x215,&DAT_80363790);
    }
    dPa_control_c::createRoomScene
              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,
               param_1->mDoDvdParticle->mpArchiveHeader);
    pmVar2 = param_1->mDoDvdParticle;
    if (pmVar2 != (mDoDvdThd_toMainRam_c *)0x0) {
      (*(code *)((pmVar2->parent).vtbl)->_mDoDvdThd_toMainRam_c)(pmVar2,1);
    }
  }
  objectSetCheck(param_1);
  return 2;
}


/* __stdcall phase_4(room_of_scene_class *) */

undefined4 phase_4(room_of_scene_class *param_1)

{
  undefined4 uVar1;
  bool bVar3;
  int iVar2;
  int iVar4;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor == (daPy_lk_c *)0x0) {
    uVar1 = 0;
  }
  else {
    iVar4 = (param_1->parent).parent.parent.mParameters;
    setMapImage(param_1);
    bVar3 = d_com_inf_game::dComIfGs_checkGetItem(DinsPearl);
    if (bVar3 != false) {
      *(undefined2 *)&param_1->field_0x1dc = 1;
    }
    iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Omori");
    if ((iVar2 == 0) &&
       (bVar3 = d_com_inf_game::dComIfGs_checkGetItem(FaroresPearl), bVar3 != false)) {
      *(undefined2 *)&param_1->field_0x1dc = 2;
    }
    if (iVar4 == 0xd) {
      dSv_event_c::setEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xb8ff,0);
      iVar4 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3f02);
      if (iVar4 != 0) {
        dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1580);
      }
    }
    uVar1 = 4;
  }
  return uVar1;
}


/* __stdcall dScnRoom_Create(scene_class *) */

void dScnRoom_Create(room_of_scene_class *param_1)

{
  d_com_lib_game::dComLbG_PhaseHandler(&param_1->mPhs,(cPhs__Handler *)&l_method_4448,param_1);
  return;
}

