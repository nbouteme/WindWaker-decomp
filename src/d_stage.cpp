#include <d_stage.h>
#include <d_stage.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_save.h>
#include <JKernel/JKRHeap.h>
#include <f_op_scene_mng.h>
#include <SComponent/c_lib.h>
#include <d_kankyo.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <mtx/mtx.h>
#include <d_drawlist.h>
#include <m_Do_ext.h>
#include <JKernel/JKRExpHeap.h>
#include <f_pc_layer.h>
#include <f_pc_stdcreate_req.h>
#include <SComponent/c_malloc.h>
#include <f_op_camera_mng.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <mtx/mtxvec.h>
#include <d_a_sea.h>
#include <f_op_actor_mng.h>
#include <f_op_msg_mng.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <d_a_ship_static.h>
#include <d_com_inf_game.h>
#include <f_op_kankyo_mng.h>
#include <d_resorce.h>
#include <d_map.h>
#include <d_event_manager.h>
#include <d_bg_s.h>
#include <SComponent/c_bg_s.h>
#include <d_a_player_main.h>
#include <d_timer.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <dStage_stageDt_c.h>
#include <dStage_KeepDoorInfo.h>
#include <dStage_roomStatus_c.h>
#include <dStage_startStage_c.h>
#include <daPy_py_c.h>
#include <dStage_roomControl_c.h>
#include <stage_tgsc_data_class.h>
#include <stage_tresure_data_class.h>
#include <dStage_KeepTresureInfo.h>
#include <dStage_roomDt_c.h>
#include <dStage_nextStage_c.h>


namespace d_stage {
undefined TresureInfo;
undefined4 DoorInfo;
struct cXyz l_offset$4537;
struct MTX34 l_m$4541[2];
}
struct dStage_roomStatus_c dStage_roomControl_c[64];
struct JKRExpHeap * dStage_roomControl_c[101];

namespace d_stage {
undefined1 init$4539;
}
int dStage_roomControl_c;
byte dStage_roomControl_c;
undefined1 dStage_roomControl_c;
undefined1 dStage_roomControl_c;
char dStage_roomControl_c[8];
byte dStage_roomControl_c;

/* __thiscall dStage_nextStage_c::set(char const *,
                                      signed char,
                                      short,
                                      signed char,
                                      signed char) */

void __thiscall
dStage_nextStage_c::set
          (dStage_nextStage_c *this,char *param_1,char startCode,short roomIdx,char layerNo,
          char wipeType)

{
  if (this->mbHasNext == 0) {
    this->mbHasNext = 1;
    this->mWipeType = wipeType;
    dStage_startStage_c::set(&this->parent,param_1,startCode,roomIdx,layerNo);
  }
  return;
}


namespace d_stage {

/* __stdcall dStage_SetErrorRoom(void) */

void dStage_SetErrorRoom(void)

{
  return;
}


/* __stdcall dStage_SetErrorStage(void) */

void dStage_SetErrorStage(void)

{
  return;
}


/* __stdcall dStage_GetKeepTresureInfo(void) */

undefined * dStage_GetKeepTresureInfo(void)

{
  return &TresureInfo;
}


/* __stdcall dStage_GetKeepDoorInfo(void) */

undefined4 * dStage_GetKeepDoorInfo(void)

{
  return &DoorInfo;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dStage_KeepTresureInfoProc(dStage_dt_c *,
                                        stage_tresure_class *) */

void dStage_KeepTresureInfoProc(dStage_dt_c *param_1,stage_tresure_class *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  stage_stag_info_class *pStag;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  pStag = (stage_stag_info_class *)(*(code *)param_1->vtbl->getStagInfo)();
  if (((pStag != (stage_stag_info_class *)0x0) &&
      (uVar1 = pStag->mStageTypeAndSchbit >> 0x10 & 7, uVar1 != 3)) && (uVar1 != 6)) {
    if (param_2 == (stage_tresure_class *)0x0) {
      _TresureInfo = 0;
    }
    else {
      _TresureInfo = *(int *)param_2;
      if ((_TresureInfo < 0x20) && (-1 < _TresureInfo)) {
        if (_TresureInfo != 0) {
          puVar3 = *(undefined4 **)(param_2 + 4);
          puVar4 = (undefined4 *)&DAT_803bcef4;
          for (iVar5 = 0; iVar5 < _TresureInfo; iVar5 = iVar5 + 1) {
            uVar2 = puVar3[1];
            *puVar4 = *puVar3;
            puVar4[1] = uVar2;
            puVar4[2] = puVar3[2];
            puVar4[3] = puVar3[3];
            puVar4[4] = puVar3[4];
            puVar4[5] = puVar3[5];
            *(undefined2 *)(puVar4 + 6) = *(undefined2 *)(puVar3 + 6);
            *(undefined2 *)((int)puVar4 + 0x1a) = *(undefined2 *)((int)puVar3 + 0x1a);
            *(undefined2 *)(puVar4 + 7) = *(undefined2 *)(puVar3 + 7);
            *(undefined2 *)((int)puVar4 + 0x1e) = *(undefined2 *)((int)puVar3 + 0x1e);
            puVar4 = puVar4 + 8;
            puVar3 = puVar3 + 8;
          }
        }
      }
      else {
        _TresureInfo = 0;
      }
    }
  }
  return;
}


/* __stdcall dStage_KeepDoorInfoProc(dStage_dt_c *,
                                     stage_tgsc_class *) */

void dStage_KeepDoorInfoProc(int *param_1,int *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar3 = (**(code **)(*param_1 + 0xb0))();
  if (((iVar3 != 0) && (uVar1 = *(uint *)(iVar3 + 0xc) >> 0x10 & 7, uVar1 != 3)) && (uVar1 != 6)) {
    if (param_2 == (int *)0x0) {
      DoorInfo = 0;
    }
    else {
      DoorInfo = *param_2;
      if ((DoorInfo < 0x40) && (-1 < DoorInfo)) {
        if (DoorInfo != 0) {
          puVar4 = (undefined4 *)param_2[1];
          puVar5 = &DAT_803bd304;
          for (iVar3 = 0; iVar3 < DoorInfo; iVar3 = iVar3 + 1) {
            uVar2 = puVar4[1];
            *puVar5 = *puVar4;
            puVar5[1] = uVar2;
            puVar5[2] = puVar4[2];
            puVar5[3] = puVar4[3];
            puVar5[4] = puVar4[4];
            puVar5[5] = puVar4[5];
            *(undefined2 *)(puVar5 + 6) = *(undefined2 *)(puVar4 + 6);
            *(undefined2 *)((int)puVar5 + 0x1a) = *(undefined2 *)((int)puVar4 + 0x1a);
            *(undefined2 *)(puVar5 + 7) = *(undefined2 *)(puVar4 + 7);
            *(undefined2 *)((int)puVar5 + 0x1e) = *(undefined2 *)((int)puVar4 + 0x1e);
            *(undefined2 *)(puVar5 + 8) = *(undefined2 *)(puVar4 + 8);
            *(undefined *)((int)puVar5 + 0x22) = *(undefined *)((int)puVar4 + 0x22);
            puVar5 = puVar5 + 9;
            puVar4 = puVar4 + 9;
          }
        }
      }
      else {
        DoorInfo = 0;
      }
    }
  }
  return;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dStage_startStage_c::set(char const *,
                                       signed char,
                                       short,
                                       signed char) */

void __thiscall
dStage_startStage_c::set
          (dStage_startStage_c *this,char *param_1,char spawnID,short param_3,char param_4)

{
  MSL_C.PPCEABI.bare.H::strcpy(this->mStageName,param_1);
  this->mStartCode = spawnID;
  this->mRoomNo = param_3;
  this->mLayerNo = param_4;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dStage_roomControl_c::init(void) */

int __thiscall dStage_roomControl_c::init(dStage_roomControl_c *this)

{
  int iVar1;
  int iVar2;
  dStage_roomStatus_c *pdVar3;
  
  mStayNo = 0xff;
  mOldStayNo = 0xff;
  if (-1 < d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mRoomNo) {
    dSv_info_c::initZone(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo);
  }
  pdVar3 = mStatus;
  iVar2 = 0;
  iVar1 = 0;
  do {
    (*(code *)((pdVar3->parent).parent.vtbl)->init)(pdVar3);
    (&mStatus[0].mFlags)[iVar1] = 0;
    pdVar3->field_0x105 = 0;
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mRoomNo < 0) {
      if (-1 < (char)pdVar3->mZoneNo) {
        dSv_zoneBit_c::clearRoomSwitch
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mZone[(char)pdVar3->mZoneNo].mZoneBit
                  );
      }
    }
    else {
      pdVar3->mZoneNo = 0xff;
    }
    pdVar3->mMemBlockIdx = -1;
    pdVar3->mpBgW = (dBgW *)0x0;
    iVar2 = iVar2 + 1;
    pdVar3 = pdVar3 + 1;
    iVar1 = iVar1 + 0x114;
  } while (iVar2 < 0x40);
  mDarkRatio = 0xff;
  iVar1 = 0;
  iVar2 = 0x10;
  do {
    *(undefined4 *)((int)mMemoryBlock + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return iVar1;
}


/* __thiscall dStage_roomControl_c::getStatusRoomDt(int) */

dStage_roomStatus_c * __thiscall
dStage_roomControl_c::getStatusRoomDt(dStage_roomControl_c *this,int param_1)

{
  if ((-1 < param_1) && (param_1 < 0x40)) {
    return mStatus + param_1;
  }
  return (dStage_roomStatus_c *)0x0;
}


namespace dStage_roomControl_c {

/* __thiscall getMemoryBlock(int) */

JKRHeap * getMemoryBlock(int param_1)

{
  if (mStatus[param_1].mMemBlockIdx < 0) {
    return &((JKRExpHeap *)0x0)->parent;
  }
  return &mMemoryBlock[mStatus[param_1].mMemBlockIdx]->parent;
}


/* __thiscall setStayNo(int) */

void setStayNo(int param_1)

{
  mOldStayNo = mStayNo;
  mStayNo = (byte)param_1;
  if ((char)mStayNo == 0xff) {
    return;
  }
  mStatus[(char)mStayNo].field_0x105 = 1;
  return;
}

}

namespace d_stage {

/* __stdcall stayRoomCheck(int,
                           unsigned char *,
                           int) */

undefined4 stayRoomCheck(int param_1,byte *param_2,uint param_3)

{
  if (0 < param_1) {
    do {
      if (param_3 == (*param_2 & 0x3f)) {
        return 1;
      }
      param_2 = param_2 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return 0;
}


/* __stdcall createRoomScene(int) */

undefined4 createRoomScene(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)JKRHeap::alloc(4,-4,(JKRHeap *)0x0);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    *piVar1 = param_1;
    uVar2 = f_op_scene_mng::fopScnM_CreateReq(0x14,0x7fff,0);
  }
  return uVar2;
}

}

/* __thiscall dStage_roomControl_c::checkRoomDisp(int) const */

bool __thiscall dStage_roomControl_c::checkRoomDisp(dStage_roomControl_c *this,int param_1)

{
  if ((mStatus[param_1].mFlags & Hidden) != 0) {
    return false;
  }
  return (mStatus[param_1].mFlags & HasBgW) != 0;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dStage_roomControl_c::loadRoom(int,
                                             unsigned char *) */

undefined4 __thiscall dStage_roomControl_c::loadRoom(dStage_roomControl_c *this,int count,byte *tbl)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  RoomStatusFlags flags;
  byte *pbVar5;
  int idx;
  int iVar6;
  
  idx = 0;
  iVar6 = 0x40;
  do {
    if (((&mStatus[0].mFlags)[idx] & (IsLoading|IsUnloading)) != 0) {
      return 0;
    }
    idx = idx + 0x114;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  bVar1 = true;
  idx = 0;
  iVar6 = 0;
  do {
    if ((((&mStatus[0].mFlags)[iVar6] & Loaded) != 0) &&
       (iVar2 = d_stage::stayRoomCheck(count,tbl,idx), iVar2 == 0)) {
      (&mStatus[0].mFlags)[iVar6] = (&mStatus[0].mFlags)[iVar6] | IsUnloading;
      bVar1 = false;
    }
    idx = idx + 1;
    iVar6 = iVar6 + 0x114;
  } while (idx < 0x40);
  if (bVar1) {
    idx = 0;
    pbVar5 = tbl;
    if (0 < count) {
      do {
        uVar4 = *pbVar5 & 0x3f;
        mStatus[uVar4].mUseCount = 2;
        if ((mStatus[uVar4].mFlags & Loaded) == 0) {
          iVar6 = d_stage::createRoomScene(uVar4);
          if (iVar6 != 0) {
            flags = IsLoading|Hidden;
            if ((tbl[idx] & 0x80) != 0) {
              flags = IsLoading;
            }
            mStatus[uVar4].mFlags = mStatus[uVar4].mFlags | flags;
          }
          return 1;
        }
        idx = idx + 1;
        pbVar5 = pbVar5 + 1;
        count = count + -1;
      } while (count != 0);
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dStage_roomControl_c::zoneCountCheck(int) const */

void __thiscall dStage_roomControl_c::zoneCountCheck(dStage_roomControl_c *this,int param_1)

{
  dStage_roomStatus_c *pStatus;
  byte bVar1;
  int iVar2;
  
  pStatus = mStatus;
  iVar2 = 0;
  do {
    if ((-1 < (char)pStatus->mZoneNo) && ('\0' < (char)pStatus->mUseCount)) {
      dSv_zoneBit_c::clearRoomSwitch
                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mZone[(char)pStatus->mZoneNo].mZoneBit)
      ;
      if (param_1 != mOldStayNo) {
        bVar1 = pStatus->mUseCount - 1;
        pStatus->mUseCount = bVar1;
        if (bVar1 == 0) {
          d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mZone[(char)pStatus->mZoneNo].mRoomIdx = 0xff;
          pStatus->mZoneNo = 0xff;
        }
      }
    }
    iVar2 = iVar2 + 1;
    pStatus = pStatus + 1;
  } while (iVar2 < 0x40);
  setStayNo(param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dStage_roomControl_c::checkDrawArea(void) const */

void __thiscall dStage_roomControl_c::checkDrawArea(dStage_roomControl_c *this)

{
  float fVar1;
  dDlst_alphaModel_c *pdVar2;
  dStage_FileList_dt_c *pFili;
  int iVar3;
  uint uVar4;
  MTX34 *pMtx;
  uint uVar5;
  int iVar6;
  dStage_roomControl__DarkStatus *pStatus;
  int iVar7;
  cXyz local_48;
  undefined auStack60 [12];
  undefined4 local_30;
  uint uStack44;
  daPy_lk_c *pPlayer;
  
  pPlayer = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  if ((-1 < (char)mStayNo) &&
     (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor != (daPy_lk_c *)0x0)) {
    pFili = mStatus[(char)mStayNo].parent.mpFileList;
    uVar5 = 0xff;
    if (pFili != (dStage_FileList_dt_c *)0x0) {
      uVar4 = pFili->mParam;
      pStatus = (dStage_roomControl__DarkStatus *)(mDarkStatus[0].mOffs + (uVar4 & 0x78) * 4 + -1);
      uVar4 = uVar4 & 1;
      if (uVar4 != 0) {
        uVar5 = (uint)pStatus->mRatio;
      }
      SComponent::cLib_chaseUC(&mDarkRatio,uVar5,8);
      uStack44 = (uint)mDarkRatio;
      if (uStack44 != 0xff) {
        local_30 = 0x43300000;
        fVar1 = (float)((double)CONCAT44(0x43300000,uStack44) - d_stage::_4606) * d_stage::_4601;
        if (d_stage::1_0 < fVar1) {
          fVar1 = d_stage::1_0;
        }
        if (uVar4 == 0) {
          d_kankyo::dKy_change_colset(4,0,fVar1);
        }
        else {
          if (uVar5 == uStack44) {
            d_kankyo::dKy_change_colset(0,4,d_stage::1_0 - fVar1);
          }
        }
        iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->vtbl->
                          getBokoFlamePos)
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor,auStack60);
        if (iVar3 == 0) {
          if (d_stage::init_4539 == '\0') {
            d_stage::l_offset_4537.x = d_stage::0_0;
            d_stage::l_offset_4537.y = d_stage::60_0;
            d_stage::l_offset_4537.z = d_stage::0_0;
            Runtime.PPCEABI.H::__register_global_object
                      (&d_stage::l_offset_4537,::cXyz::_cXyz,&d_stage::_4538);
            d_stage::init_4539 = '\x01';
          }
          pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel2;
          d_stage::l_spotColor_4536.a = mDarkRatio;
          ((d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel2)->mColor).r =
               d_stage::l_spotColor_4536.r;
          (pdVar2->mColor).g = d_stage::l_spotColor_4536.g;
          (pdVar2->mColor).b = d_stage::l_spotColor_4536.b;
          (pdVar2->mColor).a = d_stage::l_spotColor_4536.a;
          SComponent::cLib_offsetPos
                    (&local_48,&(pPlayer->parent).parent.mCurrent.mPos,
                     (pPlayer->parent).parent.mCollisionRot.y,&d_stage::l_offset_4537);
          iVar3 = 0;
          iVar7 = 0;
          iVar6 = 0;
          do {
            mtx::PSMTXTrans((double)local_48.x,(double)local_48.y,(double)local_48.z,
                            &mDoMtx_stack_c::now);
            fVar1 = *(float *)((int)pStatus->mScale + iVar6);
            mDoMtx_stack_c::scaleM(fVar1,fVar1,fVar1);
            pMtx = (MTX34 *)((int)d_stage::l_m_4541[0].m + iVar7);
            mtx::PSMTXCopy(&mDoMtx_stack_c::now,pMtx);
            dDlst_alphaModel_c::set
                      (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel2,Bonbori,pMtx,
                       pStatus->mOffs[iVar3]);
            iVar3 = iVar3 + 1;
            iVar7 = iVar7 + 0x30;
            iVar6 = iVar6 + 4;
          } while (iVar3 < 2);
        }
      }
    }
  }
  return;
}


/* __thiscall dStage_roomControl_c::getDarkStatus(void) */

byte * __thiscall dStage_roomControl_c::getDarkStatus(dStage_roomControl_c *this)

{
  dStage_FileList_dt_c *pdVar1;
  
  pdVar1 = mStatus[(char)mStayNo].parent.mpFileList;
  if (pdVar1 == (dStage_FileList_dt_c *)0x0) {
    return (byte *)0x0;
  }
  return mDarkStatus[0].mOffs + (pdVar1->mParam & 0x78U) * 4 + -1;
}


/* __thiscall dStage_roomControl_c::getDarkMode(void) */

undefined4 __thiscall dStage_roomControl_c::getDarkMode(dStage_roomControl_c *this)

{
  undefined4 uVar1;
  dStage_FileList_dt_c *pdVar2;
  
  pdVar2 = mStatus[(char)mStayNo].parent.mpFileList;
  uVar1 = 0;
  if ((pdVar2 != (dStage_FileList_dt_c *)0x0) && ((pdVar2->mParam & 1U) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}


namespace dStage_roomControl_c {

/* __thiscall createMemoryBlock(int,
                                                      unsigned long) */

JKRExpHeap * createMemoryBlock(int param_1,ulong param_2)

{
  JKRHeap *pJVar1;
  JKRExpHeap *pHeap;
  
  JKRHeap::getCurrentGroupId(m_Do_ext::archiveHeap);
  pJVar1 = m_Do_ext::mDoExt_getArchiveHeap();
  pHeap = JKRExpHeap::create(param_2,pJVar1,false);
  mMemoryBlock[param_1] = pHeap;
  return mMemoryBlock[param_1];
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dStage_roomControl_c::destroyMemoryBlock(void) */

void __thiscall dStage_roomControl_c::destroyMemoryBlock(dStage_roomControl_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    if (*(JKRHeap **)((int)mMemoryBlock + iVar2) != (JKRHeap *)0x0) {
      JKRHeap::destroy(*(JKRHeap **)((int)mMemoryBlock + iVar2));
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar1 < 0x10);
  return;
}


/* __thiscall dStage_stageDt_c::init(void) */

int __thiscall dStage_stageDt_c::init(dStage_stageDt_c *this)

{
  this->mpCamera = (stage_camera_class *)0x0;
  this->mpArrow = (stage_arrow_class *)0x0;
  this->field_0xc = (undefined *)0x0;
  this->mpRoomReads = (roomRead_class *)0x0;
  this->mpMapInfo = (stage_map_info_class *)0x0;
  this->mpMapInfoBase = (stage_map_info_dummy_class *)0x0;
  this->mpPaletInfo = (stage_palet_info_class *)0x0;
  this->mpPselectInfo = (stage_pselect_info_class *)0x0;
  this->mpEnvrInfo = (stage_envr_info_class *)0x0;
  this->mpVrboxInfo = (stage_vrbox_info_class *)0x0;
  this->mpPlightInfo = (stage_plight_info_class *)0x0;
  this->mPlightInfoNum = 0;
  this->mpStagInfo = (stage_stag_info_class *)0x0;
  this->mpScls = (stage_scls_info_dummy_class *)0x0;
  this->mpPnt = (dStage_dPnt_c *)0x0;
  this->mpPath = (dStage_dPath_c *)0x0;
  this->mpPnt2 = (dStage_dPnt_c *)0x0;
  this->mpPath2 = (dStage_dPath_c *)0x0;
  this->field_0x60 = (undefined *)0x0;
  this->mpEventInfo = (dStage_EventInfo_c *)0x0;
  this->field_0x68 = (undefined *)0x0;
  this->field_0x6c = (undefined *)0x0;
  this->field_0x70 = (undefined *)0x0;
  this->mpMulti = (dStage_Multi_c *)0x0;
  this->field_0x78 = (undefined *)0x0;
  this->field_0x7c = (undefined *)0x0;
  this->field_0x80 = (undefined *)0x0;
  return (int)this;
}


/* __thiscall dStage_roomDt_c::init(void) */

int __thiscall dStage_roomDt_c::init(dStage_roomDt_c *this,EVP_PKEY_CTX *ctx)

{
  this->mpLightVecInfo = (stage_lightvec_info_class *)0x0;
  this->mLightVecInfoNum = 0;
  this->mpMapInfo = (stage_map_info_class *)0x0;
  this->mpMapInfoBase = (stage_map_info_dummy_class *)0x0;
  this->mpVrbox = (stage_vrbox_info_class *)0x0;
  this->mpFileList = (dStage_FileList_dt_c *)0x0;
  this->mpShip = (dStage_Ship_c *)0x0;
  this->mpPlayer = (stage_actor_class *)0x0;
  this->mpPoint2 = (dStage_dPnt_c *)0x0;
  this->mpPath2 = (dStage_dPath_c *)0x0;
  this->mpCamera = (stage_camera_class *)0x0;
  this->mpArrow = (stage_arrow_class *)0x0;
  this->mpSound = (dStage_SoundInfo_c *)0x0;
  this->mpScls = (stage_scls_info_dummy_class *)0x0;
  this->mpLbnk = (dStage_Lbnk_c *)0x0;
  this->mpTresure = (stage_tresure_class *)0x0;
  this->mpDrTg = (stage_tgsc_class *)0x0;
  this->mpFloor = (dStage_FloorInfo_c *)0x0;
  return (int)this;
}


namespace d_stage {

/* __stdcall dStage_roomInit(int) */

undefined4 dStage_roomInit(int param_1)

{
  ::dStage_roomControl_c::mStatus[param_1].mFlags = IsLoading;
  createRoomScene(param_1);
  ::dStage_roomControl_c::setStayNo(param_1);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dStage_searchName(char const *) */

dStage__ObjectNameTable * dStage_searchName(char *pName)

{
  dStage__ObjectNameTable *__s1;
  int iVar1;
  uint uVar2;
  
  __s1 = l_objectName;
  uVar2 = 0;
  do {
    iVar1 = MSL_C.PPCEABI.bare.H::strcmp(__s1->mName,pName);
    if (iVar1 == 0) {
      return __s1;
    }
    uVar2 = uVar2 + 1;
    __s1 = __s1 + 1;
  } while (uVar2 < 0x339);
  return (dStage__ObjectNameTable *)0x0;
}


/* __stdcall dStage_getName(short,
                            signed char) */

char * dStage_getName(short param_1,char param_2)

{
  dStage__ObjectNameTable *pdVar1;
  int iVar2;
  
  pdVar1 = l_objectName;
  iVar2 = 0x339;
  while ((pdVar1->mProcName != param_1 || (pdVar1->mSubtype != param_2))) {
    pdVar1 = pdVar1 + 1;
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
      return (char *)&_stringBase0;
    }
  }
  return pdVar1->mName;
}


/* __stdcall dStage_getName2(short,
                             signed char) */

char * dStage_getName2(short param_1,byte param_2)

{
  char *pcVar1;
  
  pcVar1 = dStage_getName(param_1,param_2);
  return pcVar1;
}


/* __stdcall dStage_actorCreate(stage_actor_data_class *,
                                fopAcM_prm_class *) */

void dStage_actorCreate(char *param_1,fopAcM_prm_class *param_2)

{
  dStage__ObjectNameTable *pObjectName;
  layer_class *plVar1;
  
  pObjectName = dStage_searchName(param_1);
  if (pObjectName == (dStage__ObjectNameTable *)0x0) {
    JKRHeap::free(param_2,(JKRHeap *)0x0);
  }
  else {
    param_2->mSubtype = pObjectName->mSubtype;
    param_2->mGbaName = pObjectName->mGbaName;
    plVar1 = f_pc_layer::fpcLy_CurrentLayer();
    f_pc_stdcreate_req::fpcSCtRq_Request
              (plVar1,pObjectName->mProcName,(undefined *)0x0,(void *)0x0,param_2);
  }
  return;
}


/* __stdcall dStage_cameraCreate(stage_camera2_data_class *,
                                 int,
                                 int) */

undefined4 dStage_cameraCreate(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  float fVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)cMl::memalignB(-4,0x18);
  fVar1 = 0_0;
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = 0_0;
    puVar2[2] = fVar1;
    puVar2[1] = fVar1;
    *puVar2 = param_3;
    f_op_camera_mng::fopCamM_Create(param_2,0x1e2);
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __stdcall dStage_decodeSearchIkada(void *,
                                      int) */

char * dStage_decodeSearchIkada(void *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char *__s1;
  int *piVar7;
  uint uVar8;
  int iVar9;
  undefined4 uStack156;
  int local_98 [29];
  
  puVar6 = &uStack156;
  puVar5 = (undefined4 *)&UNK_8034ec0c;
  iVar9 = 0xd;
  do {
    puVar1 = puVar5 + 1;
    puVar5 = puVar5 + 2;
    uVar2 = *puVar5;
    puVar6[1] = *puVar1;
    puVar6 = puVar6 + 2;
    *puVar6 = uVar2;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if (param_1 != (void *)0x0) {
    uVar8 = 0;
    iVar9 = 0;
    do {
      piVar7 = (int *)((int)param_1 + 4);
                    /* WARNING: Load size is inaccurate */
      iVar3 = *param_1;
      if (0 < iVar3) {
LAB_80041778:
        if (*piVar7 != *(int *)((int)local_98 + iVar9)) goto LAB_80041818;
        __s1 = (char *)piVar7[2];
        for (iVar3 = 0; iVar3 < piVar7[1]; iVar3 = iVar3 + 1) {
          iVar4 = MSL_C.PPCEABI.bare.H::strcmp(__s1,"ikada_h");
          if ((((iVar4 == 0) || (iVar4 = MSL_C.PPCEABI.bare.H::strcmp(__s1,"ikada_u"), iVar4 == 0))
              || (iVar4 = MSL_C.PPCEABI.bare.H::strcmp(__s1,"ikadaS"), iVar4 == 0)) &&
             (param_2 == (*(uint *)(__s1 + 8) >> 0x12 & 0xff))) {
            return __s1;
          }
          __s1 = __s1 + 0x20;
        }
      }
LAB_80041820:
      uVar8 = uVar8 + 1;
      iVar9 = iVar9 + 8;
    } while (uVar8 < 0xd);
  }
  return (char *)0x0;
LAB_80041818:
  piVar7 = piVar7 + 3;
  iVar3 = iVar3 + -1;
  if (iVar3 == 0) goto LAB_80041820;
  goto LAB_80041778;
}


/* WARNING: Removing unreachable block (ram,0x800419b0) */
/* __stdcall dStage_playerInitIkada(fopAcM_prm_class *,
                                    void *) */

void dStage_playerInitIkada(fopAcM_prm_class *param_1,void *param_2)

{
  short sVar1;
  short sVar2;
  float fVar3;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined8 in_f31;
  double dVar8;
  cXyz local_38;
  cXyz local_2c;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar4 = dStage_decodeSearchIkada(param_2,(uint)d_com_inf_game::g_dComIfG_gameInfo.field_0x5d07);
  if (iVar4 == 0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_stage.cpp",0x636,"ikada_data != 0");
    m_Do_printf::OSPanic("d_stage.cpp",0x636,"Halt");
  }
  param_1->mParameters = d_com_inf_game::g_dComIfG_gameInfo.mLastSeaRoom | 0xff000000;
  param_1->mParameters = param_1->mParameters | 0x80;
  mtx::PSMTXTrans((double)*(float *)(iVar4 + 0xc),(double)*(float *)(iVar4 + 0x10),
                  (double)*(float *)(iVar4 + 0x14),&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,*(short *)(iVar4 + 0x1a));
  local_2c.x = 0_0;
  local_2c.y = 87_0;
  local_2c.z = 550_0;
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_2c,&local_38);
  d_a_sea::daSea_execute(&local_38);
  dVar8 = (double)0_0;
  uVar6 = d_a_sea::daSea_ChkArea(*(float *)(iVar4 + 0xc),*(float *)(iVar4 + 0x14));
  if ((uVar6 & 0xff) != 0) {
    dVar8 = (double)d_a_sea::daSea_calcWave
                              ((double)*(float *)(iVar4 + 0xc),(double)*(float *)(iVar4 + 0x14));
  }
  fVar3 = (float)((double)local_38.y + dVar8) + _4781;
  (param_1->mPos).x = local_38.x;
  (param_1->mPos).y = fVar3;
  (param_1->mPos).z = local_38.z;
  sVar1 = *(short *)(iVar4 + 0x18);
  sVar2 = *(short *)(iVar4 + 0x1a);
  (param_1->mRot).x = 0;
  (param_1->mRot).y = sVar2;
  (param_1->mRot).z = (short)((int)sVar1 << 8);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* __stdcall dStage_chkPlayerId(int,
                                int) */

undefined4 dStage_chkPlayerId(uint param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  ulong uVar4;
  dStage_roomStatus_c *pdVar5;
  int iVar6;
  
  if (param_2 == -1) {
    piVar3 = (int *)(*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                              getPlayer)();
  }
  else {
    bVar1 = false;
    if ((-1 < param_2) && (param_2 < 0x40)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_stage.cpp",0x689,"0 <= room_no && room_no < 64");
      m_Do_printf::OSPanic("d_stage.cpp",0x689,"Halt");
    }
    pdVar5 = ::dStage_roomControl_c::getStatusRoomDt
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,param_2);
    piVar3 = (int *)(*(code *)((pdVar5->parent).parent.vtbl)->getPlayer)();
  }
  if (piVar3 != (int *)0x0) {
    iVar6 = piVar3[1];
    iVar2 = *piVar3;
    if (0 < iVar2) {
      do {
        if (((int)*(short *)(iVar6 + 0x1c) & 0xffU) == param_1) {
          return 1;
        }
        iVar6 = iVar6 + 0x20;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  return 0;
}

}

/* __thiscall dStage_roomDt_c::getPlayer(void) const */

stage_actor_class * __thiscall dStage_roomDt_c::getPlayer(dStage_roomDt_c *this)

{
  return this->mpPlayer;
}


namespace d_stage {

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dStage_playerInit(dStage_dt_c *,
                               void *,
                               int,
                               void *) */

undefined4 dStage_playerInit(dStage_dt_c *pStag,void *pData,int count,void *param_4)

{
  short sVar1;
  int iVar2;
  fopAcM_prm_class *appen;
  ulong uVar3;
  scene_class *psVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  cXyz local_28;
  
  pcVar6 = *(char **)((int)pData + 8);
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor == (daPy_lk_c *)0x0) {
    (*(code *)pStag->vtbl->setPlayer)();
    (*(code *)pStag->vtbl->setPlayerNum)(pStag,count & 0xffff);
    appen = f_op_actor_mng::fopAcM_CreateAppend();
    if (appen == (fopAcM_prm_class *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_stage.cpp",0x6c7,"appen != 0");
      m_Do_printf::OSPanic("d_stage.cpp",0x6c7,"Halt");
    }
    iVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartParameters;
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mRoomNo == -2) {
      dStage_playerInitIkada(appen,param_4);
    }
    else {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mRoomNo == -3) {
        appen->mParameters = d_com_inf_game::g_dComIfG_gameInfo.mTurnRestart.mParamData;
        (appen->mPos).x = d_com_inf_game::g_dComIfG_gameInfo.mTurnRestart.mPos.x;
        (appen->mPos).y = d_com_inf_game::g_dComIfG_gameInfo.mTurnRestart.mPos.y;
        (appen->mPos).z = d_com_inf_game::g_dComIfG_gameInfo.mTurnRestart.mPos.z;
        sVar1 = d_com_inf_game::g_dComIfG_gameInfo.mTurnRestart.mRotY;
        (appen->mRot).x = 0;
        (appen->mRot).y = sVar1;
        (appen->mRot).z = -0x100;
      }
      else {
        if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mRoomNo == -1) {
          appen->mParameters =
               d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartParameters;
          (appen->mPos).x = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartPos.x;
          (appen->mPos).y = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartPos.y;
          (appen->mPos).z = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartPos.z;
          sVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mParameter;
          (appen->mRot).x = 0;
          (appen->mRot).y = sVar1;
          (appen->mRot).z = -0x100;
        }
        else {
          iVar5 = 0;
          iVar7 = count;
          if (0 < count) {
            do {
              if ((*(ushort *)(pcVar6 + 0x1c) & 0xff) ==
                  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mRoomNo) break;
              pcVar6 = pcVar6 + 0x20;
              iVar5 = iVar5 + 1;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
          if (iVar5 == count) {
            uVar3 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar3,"d_stage.cpp",0x6fb,"i != num");
            m_Do_printf::OSPanic("d_stage.cpp",0x6fb,"Halt");
          }
          appen->mParameters = *(long *)(pcVar6 + 8);
          (appen->mPos).x = *(float *)(pcVar6 + 0xc);
          (appen->mPos).y = *(float *)(pcVar6 + 0x10);
          (appen->mPos).z = *(float *)(pcVar6 + 0x14);
          (appen->mRot).x = *(short *)(pcVar6 + 0x18);
          (appen->mRot).y = *(short *)(pcVar6 + 0x1a);
          (appen->mRot).z = *(short *)(pcVar6 + 0x1c);
          appen->mEnemyNo = *(short *)(pcVar6 + 0x1e);
          if ((iVar2 != 0) && (((uint)appen->mParameters >> 0xc & 0xf) != 2)) {
            appen->mParameters = iVar2 & 0xffffffc0U | appen->mParameters & 0x3fU;
          }
        }
      }
    }
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartParameters = 0;
    appen->mEnemyNo = -1;
    appen->mRoomNo = 0xff;
    ::dStage_startStage_c::set
              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage,
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
               (byte)appen->mParameters & 0x3f,
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mRoomNo,
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mLayerNo);
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5d04 = (byte)((uint)(int)(appen->mRot).z >> 8);
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5d05 = (byte)appen->mParameters & 0x3f;
    dStage_actorCreate(pcVar6,appen);
    psVar4 = f_op_scene_mng::fopScnM_SearchByID(::dStage_roomControl_c::mProcID);
    if (psVar4 == (scene_class *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_stage.cpp",0x732,"stageProc != 0");
      m_Do_printf::OSPanic("d_stage.cpp",0x732,"Halt");
    }
    if ((psVar4->parent).parent.mProcName != 7) {
      f_op_actor_mng::fopAcM_create
                (0x1c1,0,(cXyz *)0x0,-1,(csXyz *)0x0,(cXyz *)0x0,0xff,(undefined *)0x0);
    }
    f_op_msg_mng::fopMsgM_Create(0x1f1,0,0);
    local_28.z = (appen->mPos).z;
    local_28.y = _4892 + (appen->mPos).y;
    local_28.x = (appen->mPos).x;
    f_op_actor_mng::fopAcM_create
              (0x1b5,0,&local_28,-1,(csXyz *)0x0,(cXyz *)0x0,0xff,(undefined *)0x0);
    d_com_inf_game::g_dComIfG_gameInfo.mpAgb = (daAgb_c *)0x0;
  }
  return 1;
}


/* __stdcall dStage_cameraInit(dStage_dt_c *,
                               void *,
                               int,
                               void *) */

undefined4 dStage_cameraInit(int *param_1,int param_2)

{
  (**(code **)(*param_1 + 0x10))(param_1,param_2 + 4);
  dStage_cameraCreate(*(undefined4 *)(param_2 + 8),0,0);
  return 1;
}


/* __stdcall dStage_RoomCameraInit(dStage_dt_c *,
                                   void *,
                                   int,
                                   void *) */

undefined4 dStage_RoomCameraInit(int *param_1,int param_2)

{
  (**(code **)(*param_1 + 0x10))(param_1,param_2 + 4);
  return 1;
}


/* __stdcall dStage_arrowInit(dStage_dt_c *,
                              void *,
                              int,
                              void *) */

undefined4 dStage_arrowInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  (*(code *)param_1->vtbl->setArrow)(param_1,(int)param_2 + 4);
  return 1;
}


/* __stdcall dStage_mapInfo_GetOceanX(stage_map_info_class *) */

uint dStage_mapInfo_GetOceanX(stage_map_info_class *param_1)

{
  uint uVar1;
  
  uVar1 = param_1->mOceanXZ & 0xf;
  if ((param_1->mOceanXZ & 8) == 0) {
    return uVar1;
  }
  return uVar1 - 0x10;
}


/* __stdcall dStage_mapInfo_GetOceanZ(stage_map_info_class *) */

uint dStage_mapInfo_GetOceanZ(stage_map_info_class *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(param_1->mOceanXZ >> 4);
  if ((param_1->mOceanXZ >> 4 & 8) == 0) {
    return uVar1;
  }
  return uVar1 - 0x10;
}


/* __stdcall dStage_mapInfoInit(dStage_dt_c *,
                                void *,
                                int,
                                void *) */

undefined4 dStage_mapInfoInit(dStage_dt_c *param_1,void *param_2)

{
  (*(code *)param_1->vtbl->setMapInfo)(param_1,*(undefined4 *)((int)param_2 + 8));
  (*(code *)param_1->vtbl->setMapInfoBase)(param_1,(int)param_2 + 4);
  return 1;
}

}

/* __thiscall dStage_roomDt_c::getMapInfo2(int) const */

int __thiscall dStage_roomDt_c::getMapInfo2(dStage_roomDt_c *this,int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(*(code *)((this->parent).vtbl)->getMapInfoBase)();
  if ((((piVar2 != (int *)0x0) && (iVar3 = *piVar2, iVar3 != 0)) && (iVar1 = piVar2[1], iVar1 != 0))
     && (0 < iVar3)) {
    do {
      if (param_1 == (uint)*(byte *)(iVar1 + 0x35)) {
        return iVar1;
      }
      iVar1 = iVar1 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return 0;
}


/* __thiscall dStage_roomDt_c::getMapInfoBase(void) const */

stage_map_info_dummy_class * __thiscall dStage_roomDt_c::getMapInfoBase(dStage_roomDt_c *this)

{
  return this->mpMapInfoBase;
}


/* __thiscall dStage_stageDt_c::getMapInfo2(int) const */

int __thiscall dStage_stageDt_c::getMapInfo2(dStage_stageDt_c *this,int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(*(code *)((this->parent).vtbl)->getMapInfoBase)();
  if ((((piVar2 != (int *)0x0) && (iVar3 = *piVar2, iVar3 != 0)) && (iVar1 = piVar2[1], iVar1 != 0))
     && (0 < iVar3)) {
    do {
      if (param_1 == (uint)*(byte *)(iVar1 + 0x35)) {
        return iVar1;
      }
      iVar1 = iVar1 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return 0;
}


/* __thiscall dStage_stageDt_c::getMapInfoBase(void) const */

stage_map_info_dummy_class * __thiscall dStage_stageDt_c::getMapInfoBase(dStage_stageDt_c *this)

{
  return this->mpMapInfoBase;
}


namespace d_stage {

/* __stdcall dStage_paletInfoInit(dStage_dt_c *,
                                  void *,
                                  int,
                                  void *) */

undefined4 dStage_paletInfoInit(int *param_1,int param_2)

{
  (**(code **)(*param_1 + 0x4c))(param_1,*(undefined4 *)(param_2 + 8));
  return 1;
}


/* __stdcall dStage_pselectInfoInit(dStage_dt_c *,
                                    void *,
                                    int,
                                    void *) */

undefined4 dStage_pselectInfoInit(int *param_1,int param_2)

{
  (**(code **)(*param_1 + 0x54))(param_1,*(undefined4 *)(param_2 + 8));
  return 1;
}


/* __stdcall dStage_envrInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4 dStage_envrInfoInit(int *param_1,int param_2)

{
  (**(code **)(*param_1 + 0x5c))(param_1,*(undefined4 *)(param_2 + 8));
  return 1;
}


/* __stdcall dStage_filiInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4
dStage_filiInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  if (param_3 == 0) {
    (*(code *)param_1->vtbl->setFileListInfo)(param_1,0);
  }
  else {
    (*(code *)param_1->vtbl->setFileListInfo)(param_1,*(undefined4 *)((int)param_2 + 8));
  }
  return 1;
}


/* __stdcall dStage_vrboxInfoInit(dStage_dt_c *,
                                  void *,
                                  int,
                                  void *) */

undefined4
dStage_vrboxInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  (*(code *)param_1->vtbl->setVrboxInfo)(param_1,*(undefined4 *)((int)param_2 + 8));
  return 1;
}


/* __stdcall dStage_plightInfoInit(dStage_dt_c *,
                                   void *,
                                   int,
                                   void *) */

undefined4
dStage_plightInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  (*(code *)param_1->vtbl->setPlightInfo)(param_1,*(undefined4 *)((int)param_2 + 8));
  (*(code *)param_1->vtbl->setPlightNumInfo)(param_1,param_3);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dStage_lgtvInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4
dStage_lgtvInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  (*(code *)param_1->vtbl->setLightVecInfoNum)(param_1,param_3);
  if (param_3 == 0) {
    (*(code *)param_1->vtbl->setLightVecInfo)(param_1,0);
  }
  else {
    (*(code *)param_1->vtbl->setLightVecInfo)(param_1,*(undefined4 *)((int)param_2 + 8));
  }
  return 1;
}


/* __stdcall dStage_stagInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4
dStage_stagInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  byte bVar1;
  stage_stag_info_class *pStag;
  
  (*(code *)param_1->vtbl->setStagInfo)(param_1,*(undefined4 *)((int)param_2 + 8));
  pStag = (stage_stag_info_class *)(*(code *)param_1->vtbl->getStagInfo)(param_1);
  bVar1 = pStag->mProp >> 1;
  dSv_info_c::getSave(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(uint)bVar1);
  dSv_danBit_c::init(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mDanBit,bVar1);
  return 1;
}


/* __stdcall dStage_sclsInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4 dStage_sclsInfoInit(dStage_dt_c *param_1,int param_2)

{
  (*(code *)param_1->vtbl->setSclsInfo)(param_1,param_2 + 4);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dStage_actorInit(dStage_dt_c *,
                              void *,
                              int,
                              void *) */

fopAcM_prm_class *
dStage_actorInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  int iVar1;
  fopAcM_prm_class *pPrm;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar4 = *(char **)((int)param_2 + 8);
  for (iVar3 = 0; iVar3 < *(int *)((int)param_2 + 4); iVar3 = iVar3 + 1) {
    iVar1 = (*(code *)param_1->vtbl->getRoomNo)(param_1);
    iVar1 = dSv_info_c::isActor(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,
                                (uint)*(ushort *)(pcVar4 + 0x1e),iVar1);
    if ((iVar1 == 0) &&
       (pPrm = f_op_actor_mng::fopAcM_CreateAppend(), pPrm != (fopAcM_prm_class *)0x0)) {
      pPrm->mParameters = *(long *)(pcVar4 + 8);
      (pPrm->mPos).x = *(float *)(pcVar4 + 0xc);
      (pPrm->mPos).y = *(float *)(pcVar4 + 0x10);
      (pPrm->mPos).z = *(float *)(pcVar4 + 0x14);
      (pPrm->mRot).x = *(short *)(pcVar4 + 0x18);
      (pPrm->mRot).y = *(short *)(pcVar4 + 0x1a);
      (pPrm->mRot).z = *(short *)(pcVar4 + 0x1c);
      pPrm->mEnemyNo = *(short *)(pcVar4 + 0x1e);
      bVar2 = (*(code *)param_1->vtbl->getRoomNo)(param_1);
      pPrm->mRoomNo = bVar2;
      dStage_actorCreate(pcVar4,pPrm);
    }
    pcVar4 = pcVar4 + 0x20;
  }
  return (fopAcM_prm_class *)&DAT_00000001;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dStage_tgscInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4
dStage_tgscInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  fopAcM_prm_class *pfVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar4 = *(char **)((int)param_2 + 8);
  iVar3 = 0;
  while( true ) {
    if (*(int *)((int)param_2 + 4) <= iVar3) break;
    pfVar1 = f_op_actor_mng::fopAcM_CreateAppend();
    if (pfVar1 != (fopAcM_prm_class *)0x0) {
      pfVar1->mParameters = *(long *)(pcVar4 + 8);
      (pfVar1->mPos).x = *(float *)(pcVar4 + 0xc);
      (pfVar1->mPos).y = *(float *)(pcVar4 + 0x10);
      (pfVar1->mPos).z = *(float *)(pcVar4 + 0x14);
      (pfVar1->mRot).x = *(short *)(pcVar4 + 0x18);
      (pfVar1->mRot).y = *(short *)(pcVar4 + 0x1a);
      (pfVar1->mRot).z = *(short *)(pcVar4 + 0x1c);
      pfVar1->mEnemyNo = *(short *)(pcVar4 + 0x1e);
      bVar2 = (*(code *)param_1->vtbl->getRoomNo)(param_1);
      pfVar1->mRoomNo = bVar2;
      pfVar1->mScaleX = pcVar4[0x20];
      pfVar1->mScaleY = pcVar4[0x21];
      pfVar1->mScaleZ = pcVar4[0x22];
      dStage_actorCreate(pcVar4,pfVar1);
    }
    pcVar4 = pcVar4 + 0x24;
    iVar3 = iVar3 + 1;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dStage_roomReadInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4
dStage_roomReadInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  int pData;
  
  pData = *(int *)((int)param_2 + 8);
  (*(code *)param_1->vtbl->setRoom)(param_1,(int *)((int)param_2 + 4));
  iVar1 = 0;
  for (iVar2 = 0; iVar2 < *(int *)((int)param_2 + 4); iVar2 = iVar2 + 1) {
    *(int *)(pData + iVar1) = (int)param_4 + *(int *)(pData + iVar1);
    *(int *)(*(int *)(pData + iVar1) + 4) = (int)param_4 + *(int *)(*(int *)(pData + iVar1) + 4);
    iVar1 = iVar1 + 4;
  }
  return 1;
}


/* __stdcall dStage_roomRead_dt_c_GetReverbStage(roomRead_class &,
                                                 int) */

byte dStage_roomRead_dt_c_GetReverbStage(roomRead_class *param_1,int param_2)

{
  if ((param_2 < 0) || (param_1->mCount <= param_2)) {
    param_2 = 0;
  }
  return param_1->mpRooms[0][param_2]->mReverbStage & 0x7f;
}


/* __stdcall dStage_ppntInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4
dStage_ppntInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  (*(code *)param_1->vtbl->setPntInfo)(param_1,(int)param_2 + 4);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dStage_pathInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4
dStage_pathInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  dPath *pData;
  
  pData = *(dPath **)((int)param_2 + 8);
  (*(code *)param_1->vtbl->setPathInfo)(param_1,(int *)((int)param_2 + 4));
  for (iVar2 = 0; iVar2 < *(int *)((int)param_2 + 4); iVar2 = iVar2 + 1) {
    iVar1 = (*(code *)param_1->vtbl->getPnfInf)(param_1);
    pData->mpPnt = (dPath__Point *)(&pData->mpPnt->mArg0 + *(int *)(iVar1 + 4));
    pData = pData + 1;
  }
  return 1;
}


/* __stdcall dStage_rppnInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4
dStage_rppnInfoInit(dStage_dt_c *param_1,int param_2,void *param_3,void *param_4)

{
  (*(code *)param_1->vtbl->setPnt2Info)(param_1,param_2 + 4);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dStage_rpatInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4 dStage_rpatInfoInit(dStage_dt_c *pStage,void *param_2,int param_3,void *param_4)

{
  dStage_dPnt_c *pPnt;
  int iVar1;
  dPath *pData;
  
  pData = *(dPath **)((int)param_2 + 8);
  (*(code *)pStage->vtbl->setPath2Info)(pStage,(int *)((int)param_2 + 4));
  for (iVar1 = 0; iVar1 < *(int *)((int)param_2 + 4); iVar1 = iVar1 + 1) {
    pPnt = (dStage_dPnt_c *)(*(code *)pStage->vtbl->getPnt2Inf)(pStage);
    pData->mpPnt = (dPath__Point *)(&pPnt->mpPoints->mArg0 + (int)&pData->mpPnt->mArg0);
    pData = pData + 1;
  }
  return 1;
}


/* __stdcall dStage_soundInfoInit(dStage_dt_c *,
                                  void *,
                                  int,
                                  void *) */

undefined4 dStage_soundInfoInit(int *param_1,int param_2)

{
  (**(code **)(*param_1 + 0xdc))(param_1,param_2 + 4);
  return 1;
}


/* __stdcall dStage_eventInfoInit(dStage_dt_c *,
                                  void *,
                                  int,
                                  void *) */

undefined4
dStage_eventInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  (*(code *)param_1->vtbl->setEventInfo)(param_1,(int)param_2 + 4);
  return 1;
}


/* __stdcall dStage_floorInfoInit(dStage_dt_c *,
                                  void *,
                                  int,
                                  void *) */

undefined4 dStage_floorInfoInit(int *param_1,int param_2)

{
  (**(code **)(*param_1 + 0xf4))(param_1,param_2 + 4);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dStage_memaInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4 dStage_memaInfoInit(int *param_1,int param_2)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)(param_2 + 4);
  (**(code **)(*param_1 + 0x104))(param_1,piVar5);
  if (piVar5 != (int *)0x0) {
    piVar4 = *(int **)(param_2 + 8);
    for (iVar3 = 0; iVar3 < *piVar5; iVar3 = iVar3 + 1) {
      iVar1 = ::dStage_roomControl_c::createMemoryBlock(iVar3,*piVar4 + 0x300);
      if (iVar1 == 0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_stage.cpp",0xb74,"heap != 0");
        m_Do_printf::OSPanic("d_stage.cpp",0xb74,"Halt");
      }
      piVar4 = piVar4 + 1;
    }
  }
  return 1;
}


/* __stdcall dStage_mecoInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4 dStage_mecoInfoInit(int *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_2 + 4);
  (**(code **)(*param_1 + 0xfc))(param_1,piVar3);
  if (piVar3 != (int *)0x0) {
    pbVar1 = *(byte **)(param_2 + 8);
    for (iVar2 = 0; iVar2 < *piVar3; iVar2 = iVar2 + 1) {
      ::dStage_roomControl_c::mStatus[*pbVar1].mMemBlockIdx = pbVar1[1];
      pbVar1 = pbVar1 + 2;
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dStage_setShipPos(int,
                               int) */

undefined4 dStage_setShipPos(int param_1,int param_2)

{
  int iVar1;
  daShip_c *pdVar2;
  cXyz *pcVar3;
  undefined2 local_18;
  short local_16;
  
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"GanonM");
  if ((iVar1 == 0) &&
     (iVar1 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3d02),
     iVar1 == 0)) {
    param_1 = 0xff;
    param_2 = 0xff;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5d04 = 0xff;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5d05 = 0xff;
  }
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mRoomNo == -3) &&
     (d_com_inf_game::g_dComIfG_gameInfo.mTurnRestart.field_0x34 != 0)) {
    local_16 = 0xa7;
    pdVar2 = (daShip_c *)
             f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_16);
    if (pdVar2 != (daShip_c *)0x0) {
      daShip_c::initStartPos
                (pdVar2,&d_com_inf_game::g_dComIfG_gameInfo.mTurnRestart.field_0x24,
                 d_com_inf_game::g_dComIfG_gameInfo.mTurnRestart.field_0x30);
    }
    d_com_inf_game::g_dComIfG_gameInfo.mTurnRestart.field_0x34 = 0;
  }
  if (param_1 != 0xff) {
    if (param_2 == 0xff) {
      param_2 = (int)(char)::dStage_roomControl_c::mStayNo;
    }
    pcVar3 = (cXyz *)d_com_inf_game::dComIfGp_getShip(param_2,param_1);
    if (pcVar3 != (cXyz *)0x0) {
      local_18 = 0xa7;
      pdVar2 = (daShip_c *)
               f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_18);
      if (pdVar2 != (daShip_c *)0x0) {
        daShip_c::initStartPos(pdVar2,pcVar3,*(short *)&pcVar3[1].x);
        return 1;
      }
    }
  }
  return 0;
}


/* __stdcall dStage_chkTaura(int) */

undefined4 dStage_chkTaura(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea");
  if ((iVar1 == 0) && (param_1 == 0xb)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dStage_shipInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4 dStage_shipInfoInit(int *param_1,int param_2)

{
  char cVar2;
  int iVar1;
  byte bVar3;
  byte bVar4;
  
  (**(code **)(*param_1 + 0x10c))(param_1,param_2 + 4);
  bVar4 = d_com_inf_game::g_dComIfG_gameInfo.field_0x5d05;
  bVar3 = d_com_inf_game::g_dComIfG_gameInfo.field_0x5d04;
  cVar2 = dStage_chkTaura(d_com_inf_game::g_dComIfG_gameInfo.field_0x5d05);
  if (cVar2 != '\0') {
    iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2a08)
    ;
    if (iVar1 == 0) {
      cVar2 = dStage_setShipPos(0x80,bVar4);
      if (cVar2 != '\0') {
        bVar3 = 0xff;
        bVar4 = 0xff;
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5d04 = 0xff;
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5d05 = 0xff;
      }
    }
  }
  cVar2 = dStage_setShipPos(bVar3,bVar4);
  if (cVar2 != '\0') {
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5d04 = 0xff;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5d05 = 0xff;
  }
  return 1;
}


/* __stdcall dStage_multInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4
dStage_multInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  (*(code *)param_1->vtbl->setMulti)(param_1,(int)param_2 + 4);
  return 1;
}


/* __stdcall dStage_lbnkInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4
dStage_lbnkInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  (*(code *)param_1->vtbl->setLbnk)(param_1,(int)param_2 + 4);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dStage_stageTresureInit(dStage_dt_c *,
                                     void *,
                                     int,
                                     void *) */

undefined4
dStage_stageTresureInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  (*(code *)param_1->vtbl->setTresure)(param_1,(stage_tresure_class *)((int)param_2 + 4));
  dStage_actorInit(param_1,param_2,param_3,param_4);
  dStage_KeepTresureInfoProc(param_1,(stage_tresure_class *)((int)param_2 + 4));
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dStage_roomTresureInit(dStage_dt_c *,
                                    void *,
                                    int,
                                    void *) */

undefined4
dStage_roomTresureInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  (*(code *)param_1->vtbl->setTresure)(param_1,(int)param_2 + 4);
  dStage_actorInit(param_1,param_2,param_3,param_4);
  return 1;
}


/* __stdcall dStage_layerTresureInit(dStage_dt_c *,
                                     void *,
                                     int,
                                     void *) */

undefined4
dStage_layerTresureInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  dStage_actorInit(param_1,param_2,param_3,param_4);
  return 1;
}


/* __stdcall dStage_dmapInfoInit(dStage_dt_c *,
                                 void *,
                                 int,
                                 void *) */

undefined4 dStage_dmapInfoInit(int *param_1,int param_2)

{
  (**(code **)(*param_1 + 300))(param_1,param_2 + 4);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dStage_stageDrtgInfoInit(dStage_dt_c *,
                                      void *,
                                      int,
                                      void *) */

undefined4
dStage_stageDrtgInfoInit(dStage_dt_c *param_1,int param_2,int param_3,void *param_4)

{
  (*(code *)param_1->vtbl->setDrTg)(param_1,param_2 + 4);
  dStage_tgscInfoInit(param_1,(void *)param_2,param_3,param_4);
  dStage_KeepDoorInfoProc(param_1,param_2 + 4);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dStage_roomDrtgInfoInit(dStage_dt_c *,
                                     void *,
                                     int,
                                     void *) */

undefined4
dStage_roomDrtgInfoInit(dStage_dt_c *param_1,void *param_2,int param_3,void *param_4)

{
  (*(code *)param_1->vtbl->setDrTg)(param_1,(int)param_2 + 4);
  dStage_tgscInfoInit(param_1,param_2,param_3,param_4);
  return 1;
}


/* __stdcall dKankyo_create(void) */

void dKankyo_create(void)

{
  f_op_kankyo_mng::fopKyM_Create(0x15,0,0);
  f_op_kankyo_mng::fopKyM_Create(0x1e4,0,0);
  f_op_kankyo_mng::fopKyM_Create(0x1e5,0,0);
  f_op_kankyo_mng::fopKyM_Create(0x17,0,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dStage_dt_c_decode(void *,
                                dStage_dt_c *,
                                FuncTable *,
                                int) */

void dStage_dt_c_decode
               (void *pData,dStage_dt_c *pStage,dStage_dt__FuncTable *pTable,int tableCount)

{
  int chunkCount;
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  if (pData != (void *)0x0) {
    iVar4 = 0;
    for (iVar3 = 0; iVar3 < tableCount; iVar3 = iVar3 + 1) {
      piVar1 = (int *)((int)pData + 4);
                    /* WARNING: Load size is inaccurate */
      chunkCount = *pData;
      if (0 < chunkCount) {
        do {
          if (*piVar1 == *(int *)(pTable->mMagic + iVar4)) {
                    /* dStage_stagInfoInit */
            pcVar2 = *(code **)((int)(pTable->mMagic + iVar4) + 8);
            if (pcVar2 != (code *)0x0) {
              (*pcVar2)(pStage,piVar1,piVar1[1],pData);
            }
            break;
          }
          piVar1 = piVar1 + 3;
          chunkCount = chunkCount + -1;
        } while (chunkCount != 0);
      }
      iVar4 = iVar4 + 0xc;
    }
  }
  return;
}


/* __stdcall dStage_dt_c_offsetToPtr(void *) */

void dStage_dt_c_offsetToPtr(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 1;
  for (iVar2 = 0; iVar2 < *param_1; iVar2 = iVar2 + 1) {
    if (piVar1[2] != 0) {
      piVar1[2] = piVar1[2] + (int)param_1;
    }
    piVar1 = piVar1 + 3;
  }
  return;
}


/* __stdcall dStage_dt_c_stageInitLoader(void *,
                                         dStage_dt_c *) */

void dStage_dt_c_stageInitLoader(void *param_1,dStage_dt_c *param_2)

{
  ulong uVar1;
  
  if (param_1 == (void *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_stage.cpp",0xde5,"i_data != 0");
    m_Do_printf::OSPanic("d_stage.cpp",0xde5,"Halt");
  }
  if (param_2 == (dStage_dt_c *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_stage.cpp",0xde6,"i_stage != 0");
    m_Do_printf::OSPanic("d_stage.cpp",0xde6,"Halt");
  }
  dStage_dt_c_offsetToPtr(param_1);
  (*(code *)param_2->vtbl->init)(param_2);
  dStage_dt_c_decode(param_1,param_2,l_funcTable_5296,1);
  return;
}


/* __stdcall layerLoader(void *,
                         dStage_dt_c *,
                         int) */

void layerLoader(void *param_1,dStage_dt_c *param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = dComIfG_play_c::getLayerNo(param_3);
  dStage_dt_c_decode(param_1,param_2,(dStage_dt__FuncTable *)(&l_layerFuncTable_p_5317)[uVar1],3);
  return;
}


/* __stdcall dStage_dt_c_stageLoader(void *,
                                     dStage_dt_c *) */

void dStage_dt_c_stageLoader(void *param_1,dStage_dt_c *param_2)

{
  dStage_dt_c_decode(param_1,param_2,l_funcTable_5322,0x22);
  layerLoader(param_1,param_2,-1);
  return;
}


/* __stdcall dStage_dt_c_roomLoader(void *,
                                    dStage_dt_c *) */

void dStage_dt_c_roomLoader(void *param_1,dStage_dt_c *param_2)

{
  dStage_dt_c_offsetToPtr();
  (*(code *)param_2->vtbl->init)(param_2);
  dStage_dt_c_decode(param_1,param_2,l_funcTable_5327,0x16);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dStage_dt_c_roomReLoader(void *,
                                      dStage_dt_c *,
                                      int) */

void dStage_dt_c_roomReLoader(void *param_1,dStage_dt_c *param_2,int param_3)

{
  dStage_dt_c_decode(param_1,param_2,l_funcTable_5332,7);
  layerLoader(param_1,param_2,param_3);
  return;
}


/* __stdcall dStage_infoCreate(void) */

void dStage_infoCreate(void)

{
  void *pvVar1;
  ulong uVar2;
  
  pvVar1 = dRes_control_c::getRes
                     ("Stage","stage.dzs",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,
                      0x40);
  if (pvVar1 == (void *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_stage.cpp",0xefa,"stageRsrc != 0");
    m_Do_printf::OSPanic("d_stage.cpp",0xefa,"Halt");
  }
  dStage_dt_c_stageInitLoader(pvVar1,&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dStage_Create(void) */

void dStage_Create(void)

{
  void *pvVar1;
  ulong uVar2;
  int iVar3;
  int local_r3_248;
  layer_class *plVar4;
  
  dKankyo_create();
  pvVar1 = dRes_control_c::getRes
                     ("Stage","stage.dzs",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,
                      0x40);
  if (pvVar1 == (void *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_stage.cpp",0xf16,"stageRsrc != 0");
    m_Do_printf::OSPanic("d_stage.cpp",0xf16,"Halt");
  }
  ::dStage_roomControl_c::init(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl);
  dStage_dt_c_stageLoader(pvVar1,0x803c9d58);
  if ((-1 < d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStartCode) &&
     (iVar3 = dStage_roomInit((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStartCode),
     iVar3 == 0)) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_stage.cpp",0xf21,"status");
    m_Do_printf::OSPanic("d_stage.cpp",0xf21,"Halt");
  }
  dMap_c::create();
  ::dStage_roomControl_c::mDemoArcName[0] = '\0';
  pvVar1 = dRes_control_c::getRes
                     ("Stage","vr_sky.bdl",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,
                      0x40);
  if (pvVar1 != (void *)0x0) {
    plVar4 = f_pc_layer::fpcLy_CurrentLayer();
    f_pc_stdcreate_req::fpcSCtRq_Request(plVar4,0x1ba,(undefined *)0x0,(void *)0x0,(void *)0x0);
    plVar4 = f_pc_layer::fpcLy_CurrentLayer();
    f_pc_stdcreate_req::fpcSCtRq_Request(plVar4,0x1bb,(undefined *)0x0,(void *)0x0,(void *)0x0);
  }
  dEvent_manager_c::create(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr);
  return;
}


/* __stdcall dStage_Delete(void) */

void dStage_Delete(void)

{
  char *this;
  int iVar1;
  dMap_c *this_00;
  dRes_info_c *__filename;
  
  this = ::dStage_roomControl_c::mDemoArcName;
  if (::dStage_roomControl_c::mDemoArcName[0] != '\0') {
    this = (char *)dRes_control_c::deleteRes
                             (::dStage_roomControl_c::mDemoArcName,
                              d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  }
  ::dStage_roomControl_c::destroyMemoryBlock((dStage_roomControl_c *)this);
  iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  dSv_info_c::putSave(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(uint)(*(byte *)(iVar1 + 9) >> 1))
  ;
  __filename = d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo;
  this_00 = (dMap_c *)
            dRes_control_c::deleteRes
                      ("Stage",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
  dMap_c::remove(this_00,__filename->mName);
  dEvent_manager_c::remove(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,__filename->mName);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dStage_RoomCheck(cBgS_GndChk *) */

undefined4 dStage_RoomCheck(cBgS_GndChk *param_1)

{
  undefined4 uVar1;
  int roomInfId;
  roomRead_class *pRoom;
  
  roomInfId = dBgS::GetRoomId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&param_1->mPolyInfo);
  if (roomInfId < 0) {
    uVar1 = 0;
  }
  else {
    if (roomInfId != (char)::dStage_roomControl_c::mStayNo) {
      ::dStage_roomControl_c::zoneCountCheck
                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,roomInfId);
    }
    roomInfId = dBgS::GetGrpRoomInfId
                          (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&param_1->mPolyInfo);
    if (roomInfId == 0xff) {
      uVar1 = 0;
    }
    else {
      pRoom = (roomRead_class *)
              (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getRoom)
                        (0x803c9d58);
      if ((pRoom == (roomRead_class *)0x0) || (pRoom->mCount <= roomInfId)) {
        uVar1 = 1;
      }
      else {
        ::dStage_roomControl_c::SetTimePass(pRoom->mpRooms[0][roomInfId]->mbIsTimePass & 3);
        uVar1 = ::dStage_roomControl_c::loadRoom
                          (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                           (uint)pRoom->mpRooms[0][roomInfId]->mNumLoadRoom,
                           pRoom->mpRooms[0][roomInfId]->mpRoomLoadTable);
      }
    }
  }
  return uVar1;
}

}

namespace dStage_roomControl_c {

/* __thiscall SetTimePass(int) */

void SetTimePass(int param_1)

{
  m_time_pass = (byte)param_1;
  return;
}

}

namespace d_stage {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800438e0) */
/* __stdcall dStage_changeSceneExitId(cBgS_PolyInfo &,
                                      float,
                                      unsigned long,
                                      signed char) */

undefined4
dStage_changeSceneExitId
          (cBgS_PolyInfo *pPoly,float param_2,uint param_3,byte roomIdxFallback)

{
  byte roomIdx;
  ushort startCode;
  int iVar1;
  fopAc_ac_c *pActor;
  uint uVar2;
  undefined4 uVar3;
  ulong uVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar6 = (double)param_2;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar1 = dBgS::GetExitId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,pPoly);
  if ((iVar1 == 0x3e) || (iVar1 == 0x3b)) {
    pActor = cBgS::GetActorPointer
                       ((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                        (uint)(ushort)pPoly->mBgIndex);
    uVar2 = (pActor->parent).parent.mParameters;
    roomIdx = (byte)(uVar2 >> 4) & 0x3f;
    startCode = (ushort)(uVar2 >> 10) & 0xff;
    if (iVar1 == 0x3e) {
      d_com_inf_game::dComIfGp_setNextStage
                ("Obshop",startCode,roomIdx,0xff,(float)dVar6,param_3,1,0);
    }
    else {
      if (iVar1 == 0x3b) {
        d_com_inf_game::dComIfGp_setNextStage
                  ("Abship",startCode,roomIdx,0xff,(float)dVar6,param_3,1,0);
      }
    }
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5d07 =
         (byte)((uint)(pActor->parent).parent.mParameters >> 0x12);
    d_com_inf_game::g_dComIfG_gameInfo.mIkadaLinkPos.x = (pActor->mCurrent).mPos.x;
    d_com_inf_game::g_dComIfG_gameInfo.mIkadaLinkPos.y = (pActor->mCurrent).mPos.y;
    d_com_inf_game::g_dComIfG_gameInfo.mIkadaLinkPos.z = (pActor->mCurrent).mPos.z;
    uVar3 = 1;
    d_com_inf_game::g_dComIfG_gameInfo.mLastSeaRoom = roomIdxFallback;
  }
  else {
    if (iVar1 == 0x3d) {
      if (0x3f < d_com_inf_game::g_dComIfG_gameInfo.mLastSeaRoom) {
        uVar4 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar4,"d_stage.cpp",0x1026,
                   "dComIfGp_getIkadaShipBeforeRoomId() >= 0 && dComIfGp_getIkadaShipBeforeRoomId() < 64"
                  );
        m_Do_printf::OSPanic("d_stage.cpp",0x1026,"Halt");
      }
      d_com_inf_game::dComIfGp_setNextStage
                ("sea",-2,d_com_inf_game::g_dComIfG_gameInfo.mLastSeaRoom,0xff,(float)dVar6,param_3,
                 1,0);
      uVar3 = 1;
    }
    else {
      if (iVar1 == 0x3c) {
        iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Asoko");
        if (iVar1 == 0) {
          iVar1 = dSv_event_c::isEventBit
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x808);
          if (iVar1 == 0) {
            d_com_inf_game::dComIfGp_setNextStage("A_umikz",0,0,0xff,(float)dVar6,param_3,1,0);
          }
          else {
            iVar1 = dSv_event_c::isEventBit
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x520);
            if (iVar1 == 0) {
              d_com_inf_game::dComIfGp_setNextStage("MajyuE",0x12,0,0xff,(float)dVar6,param_3,1,0);
            }
            else {
              d_com_inf_game::dComIfGp_setNextStage("sea",5,0xb,0xff,(float)dVar6,param_3,1,0);
            }
          }
        }
        else {
          d_com_inf_game::dComIfGp_setNextStage("Asoko",0,0,0xff,(float)dVar6,param_3,1,0);
        }
        uVar3 = 1;
      }
      else {
        uVar3 = dStage_changeScene(iVar1,(float)dVar6,param_3,roomIdxFallback);
      }
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dStage_changeScene(int,
                                float,
                                unsigned long,
                                signed char) */

undefined4 dStage_changeScene(int sclsIdx,float param_2,uint param_3,byte roomNo)

{
  bool bVar1;
  dStage_roomStatus_c *pdVar2;
  undefined4 uVar3;
  ulong uVar4;
  stage_scls_info_class *pStageName;
  byte bVar5;
  stage_scls_info_dummy_class *pScls;
  double dVar6;
  
  dVar6 = (double)param_2;
  if (roomNo == 0xff) {
    pScls = (stage_scls_info_dummy_class *)
            (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getSclsInfo)();
  }
  else {
    bVar1 = false;
    if ((-1 < (char)roomNo) && ((char)roomNo < '@')) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_stage.cpp",0x1060,"0 <= room_no && room_no < 64");
      m_Do_printf::OSPanic("d_stage.cpp",0x1060,"Halt");
    }
    pdVar2 = ::dStage_roomControl_c::getStatusRoomDt
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,(int)(char)roomNo);
    pScls = (stage_scls_info_dummy_class *)(*(code *)((pdVar2->parent).parent.vtbl)->getSclsInfo)();
  }
  if (pScls == (stage_scls_info_dummy_class *)0x0) {
    uVar3 = 0;
  }
  else {
    bVar1 = false;
    if (-1 < sclsIdx) {
      if (sclsIdx < pScls->mCount) {
        bVar1 = true;
      }
    }
    if (!bVar1) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_stage.cpp",0x106a,"0 <= i_exitId && i_exitId < scls->num");
      m_Do_printf::OSPanic("d_stage.cpp",0x106a,"Halt");
    }
    pStageName = pScls->mpScls + sclsIdx;
    bVar5 = pStageName->mFade & 0xf;
    d_com_inf_game::dComIfGp_setNextStage
              (pStageName->mStageName,(ushort)pStageName->mStartCode,pStageName->mRoomNo,0xff,
               (float)dVar6,param_3,1,bVar5 & ~-(bVar5 == 0xf));
    uVar3 = 1;
  }
  return uVar3;
}

}

/* __thiscall dStage_roomDt_c::getSclsInfo(void) const */

stage_scls_info_dummy_class * __thiscall dStage_roomDt_c::getSclsInfo(dStage_roomDt_c *this)

{
  return this->mpScls;
}


namespace d_stage {

/* __stdcall dStage_restartRoom(unsigned long,
                                unsigned long) */

void dStage_restartRoom(int param_1,int param_2)

{
  d_com_inf_game::dComIfGp_setNextStage
            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,-1,
             d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mRestartCode,0xff,0_0,param_2,0,0);
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartParameters = param_1;
  return;
}


/* WARNING: Removing unreachable block (ram,0x80043bb8) */
/* __stdcall dStage_turnRestart(void) */

void dStage_turnRestart(void)

{
  byte layerNo;
  int iVar1;
  undefined4 uVar2;
  undefined8 in_f31;
  double dVar3;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  layerNo = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mLayerNo;
  if (-1 < (char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mLayerNo) {
    layerNo = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mLayerNo ^ 1;
  }
  d_com_inf_game::dComIfGp_setNextStage
            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,-3,
             d_com_inf_game::g_dComIfG_gameInfo.mTurnRestart.mRoomNo,layerNo,0_0,0,0,6);
  iVar1 = d_kankyo::dKy_getdaytime_hour();
  dVar3 = (double)_5557;
  if ((5 < iVar1) && (iVar1 < 0x12)) {
    dVar3 = (double)0_0;
  }
  if ((5 < iVar1) && (iVar1 < 0x18)) {
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mDayOfWeek =
         d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mDayOfWeek + 1;
    d_kankyo::dKy_DayProc();
  }
  d_kankyo::dKy_set_nexttime(dVar3);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* __stdcall dStage_escapeRestart(void) */

void dStage_escapeRestart(void)

{
  short rotY;
  daPy_lk_c *pdVar1;
  ulong uVar2;
  actor_place *pos;
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
  uVar2 = daPy_lk_c::getDayNightParamData(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor);
  rotY = (pdVar1->parent).parent.mCollisionRot.y;
  pos = &(pdVar1->parent).parent.mCurrent;
  dSv_turnRestart_c::set
            (&d_com_inf_game::g_dComIfG_gameInfo.mTurnRestart,&pos->mPos,rotY,
             (pdVar1->parent).parent.mCurrent.mRoomNo,uVar2,&pos->mPos,rotY,0);
  if ((d_com_inf_game::g_dComIfG_gameInfo._23788_4_ == 3) &&
     (d_com_inf_game::g_dComIfG_gameInfo.mpRestartTimer != (dTimer_c *)0x0)) {
    dTimer_c::deleteRequest(d_com_inf_game::g_dComIfG_gameInfo.mpRestartTimer);
  }
  d_com_inf_game::dComIfGp_setNextStage
            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,-3,
             d_com_inf_game::g_dComIfG_gameInfo.mTurnRestart.mRoomNo,0xff,0_0,0,0,9);
  return;
}


/* __stdcall dStage_checkRestart(void) */

undefined4 dStage_checkRestart(void)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext != 0) {
    if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mRoomNo == -2) ||
       (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mRoomNo == -3)) {
      return 0;
    }
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartParameters != 0) {
      return 1;
    }
  }
  return 0;
}

}

/* __thiscall dStage_roomDt_c::getRoomNo(void) const */

int __thiscall dStage_roomDt_c::getRoomNo(dStage_roomDt_c *this)

{
  return (int)(char)this->mRoomNo;
}


/* __thiscall dStage_roomDt_c::setCamera(stage_camera_class *) */

void __thiscall dStage_roomDt_c::setCamera(dStage_roomDt_c *this,stage_camera_class *param_1)

{
  this->mpCamera = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getCamera(void) const */

stage_camera_class * __thiscall dStage_roomDt_c::getCamera(dStage_roomDt_c *this)

{
  return this->mpCamera;
}


/* __thiscall dStage_roomDt_c::setArrow(stage_arrow_class *) */

void __thiscall dStage_roomDt_c::setArrow(dStage_roomDt_c *this,stage_arrow_class *param_1)

{
  this->mpArrow = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getArrow(void) const */

stage_arrow_class * __thiscall dStage_roomDt_c::getArrow(dStage_roomDt_c *this)

{
  return this->mpArrow;
}


/* __thiscall dStage_roomDt_c::setPlayer(stage_actor_class *) */

void __thiscall dStage_roomDt_c::setPlayer(dStage_roomDt_c *this,stage_actor_class *param_1)

{
  this->mpPlayer = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::setPlayerNum(unsigned short) */

void __thiscall dStage_roomDt_c::setPlayerNum(dStage_roomDt_c *this,ushort param_1)

{
  this->mPlayerNum = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getPlayerNum(void) const */

short __thiscall dStage_roomDt_c::getPlayerNum(dStage_roomDt_c *this)

{
  return this->mPlayerNum;
}


/* __thiscall dStage_roomDt_c::setRoom(roomRead_class *) */

void __thiscall dStage_roomDt_c::setRoom(dStage_roomDt_c *this,roomRead_class *param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorRoom();
  m_Do_printf::OSReport("Room non room data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x64d,"0");
  m_Do_printf::OSPanic("d_stage.h",0x64d,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getRoom(void) const */

undefined4 __thiscall dStage_roomDt_c::getRoom(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non room data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x652,"0");
  m_Do_printf::OSPanic("d_stage.h",0x652,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setMapInfo(stage_map_info_class *) */

void __thiscall dStage_roomDt_c::setMapInfo(dStage_roomDt_c *this,stage_map_info_class *param_1)

{
  this->mpMapInfo = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getMapInfo(void) const */

stage_map_info_class * __thiscall dStage_roomDt_c::getMapInfo(dStage_roomDt_c *this)

{
  return this->mpMapInfo;
}


/* __thiscall dStage_roomDt_c::setMapInfoBase(stage_map_info_dummy_class *) */

void __thiscall
dStage_roomDt_c::setMapInfoBase(dStage_roomDt_c *this,stage_map_info_dummy_class *param_1)

{
  this->mpMapInfoBase = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::setPaletInfo(stage_palet_info_class *) */

void __thiscall dStage_roomDt_c::setPaletInfo(dStage_roomDt_c *this,stage_palet_info_class *param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorRoom();
  m_Do_printf::OSReport("Room non palet data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x66c,"0");
  m_Do_printf::OSPanic("d_stage.h",0x66c,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getPaletInfo(void) const */

undefined4 __thiscall dStage_roomDt_c::getPaletInfo(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non palet data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x670,"0");
  m_Do_printf::OSPanic("d_stage.h",0x670,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setPselectInfo(stage_pselect_info_class *) */

void __thiscall
dStage_roomDt_c::setPselectInfo(dStage_roomDt_c *this,stage_pselect_info_class *param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorRoom();
  m_Do_printf::OSReport("Room non pselect data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x677,"0");
  m_Do_printf::OSPanic("d_stage.h",0x677,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getPselectInfo(void) const */

undefined4 __thiscall dStage_roomDt_c::getPselectInfo(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non pselect data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x67b,"0");
  m_Do_printf::OSPanic("d_stage.h",0x67b,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setEnvrInfo(stage_envr_info_class *) */

void __thiscall dStage_roomDt_c::setEnvrInfo(dStage_roomDt_c *this,stage_envr_info_class *param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorRoom();
  m_Do_printf::OSReport("Room non envr data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x682,"0");
  m_Do_printf::OSPanic("d_stage.h",0x682,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getEnvrInfo(void) const */

undefined4 __thiscall dStage_roomDt_c::getEnvrInfo(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non envr data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x686,"0");
  m_Do_printf::OSPanic("d_stage.h",0x686,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setVrboxInfo(stage_vrbox_info_class *) */

void __thiscall dStage_roomDt_c::setVrboxInfo(dStage_roomDt_c *this,stage_vrbox_info_class *param_1)

{
  this->mpVrbox = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getVrboxInfo(void) const */

stage_vrbox_info_class * __thiscall dStage_roomDt_c::getVrboxInfo(dStage_roomDt_c *this)

{
  return this->mpVrbox;
}


/* __thiscall dStage_roomDt_c::setPlightInfo(stage_plight_info_class *) */

void __thiscall
dStage_roomDt_c::setPlightInfo(dStage_roomDt_c *this,stage_plight_info_class *param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorRoom();
  m_Do_printf::OSReport("Room non plight data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x696,"0");
  m_Do_printf::OSPanic("d_stage.h",0x696,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getPlightInfo(void) const */

undefined4 __thiscall dStage_roomDt_c::getPlightInfo(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non plight data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x69a,"0");
  m_Do_printf::OSPanic("d_stage.h",0x69a,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setPaletNumInfo(int) */

void __thiscall dStage_roomDt_c::setPaletNumInfo(dStage_roomDt_c *this,int param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorRoom();
  m_Do_printf::OSReport("Room non palet num data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x6a4,"0");
  m_Do_printf::OSPanic("d_stage.h",0x6a4,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getPaletNumInfo(void) const */

undefined4 __thiscall dStage_roomDt_c::getPaletNumInfo(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non palet num data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x6a8,"0");
  m_Do_printf::OSPanic("d_stage.h",0x6a8,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setPselectNumInfo(int) */

void __thiscall dStage_roomDt_c::setPselectNumInfo(dStage_roomDt_c *this,int param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorRoom();
  m_Do_printf::OSReport("Room non pselect num data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x6af,"0");
  m_Do_printf::OSPanic("d_stage.h",0x6af,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getPselectNumInfo(void) const */

undefined4 __thiscall dStage_roomDt_c::getPselectNumInfo(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non pselect num data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x6b3,"0");
  m_Do_printf::OSPanic("d_stage.h",0x6b3,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setEnvrNumInfo(int) */

void __thiscall dStage_roomDt_c::setEnvrNumInfo(dStage_roomDt_c *this,int param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorRoom();
  m_Do_printf::OSReport("Room non envr num data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x6ba,"0");
  m_Do_printf::OSPanic("d_stage.h",0x6ba,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getEnvrNumInfo(void) const */

undefined4 __thiscall dStage_roomDt_c::getEnvrNumInfo(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non envr num data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x6be,"0");
  m_Do_printf::OSPanic("d_stage.h",0x6be,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setVrboxNumInfo(int) */

void __thiscall dStage_roomDt_c::setVrboxNumInfo(dStage_roomDt_c *this,int param_1)

{
  this->mVrboxNum = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getVrboxNumInfo(void) const */

int __thiscall dStage_roomDt_c::getVrboxNumInfo(dStage_roomDt_c *this)

{
  return this->mVrboxNum;
}


/* __thiscall dStage_roomDt_c::setPlightNumInfo(int) */

void __thiscall dStage_roomDt_c::setPlightNumInfo(dStage_roomDt_c *this,int param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorRoom();
  m_Do_printf::OSReport("Room non plight num data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x6c7,"0");
  m_Do_printf::OSPanic("d_stage.h",0x6c7,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getPlightNumInfo(void) const */

undefined4 __thiscall dStage_roomDt_c::getPlightNumInfo(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non plight num data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x6cc,"0");
  m_Do_printf::OSPanic("d_stage.h",0x6cc,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setLightVecInfo(stage_lightvec_info_class *) */

void __thiscall
dStage_roomDt_c::setLightVecInfo(dStage_roomDt_c *this,stage_lightvec_info_class *param_1)

{
  this->mpLightVecInfo = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getLightVecInfo(void) const */

stage_lightvec_info_class * __thiscall dStage_roomDt_c::getLightVecInfo(dStage_roomDt_c *this)

{
  return this->mpLightVecInfo;
}


/* __thiscall dStage_roomDt_c::setLightVecInfoNum(int) */

void __thiscall dStage_roomDt_c::setLightVecInfoNum(dStage_roomDt_c *this,int param_1)

{
  this->mLightVecInfoNum = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getLightVecInfoNum(void) const */

int __thiscall dStage_roomDt_c::getLightVecInfoNum(dStage_roomDt_c *this)

{
  return this->mLightVecInfoNum;
}


/* __thiscall dStage_roomDt_c::setStagInfo(stage_stag_info_class *) */

void __thiscall dStage_roomDt_c::setStagInfo(dStage_roomDt_c *this,stage_stag_info_class *param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorRoom();
  m_Do_printf::OSReport("Room non stag data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x6e9,"0");
  m_Do_printf::OSPanic("d_stage.h",0x6e9,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getStagInfo(void) const */

undefined4 __thiscall dStage_roomDt_c::getStagInfo(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non stag data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x6ed,"0");
  m_Do_printf::OSPanic("d_stage.h",0x6ed,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setSclsInfo(stage_scls_info_dummy_class *) */

void __thiscall
dStage_roomDt_c::setSclsInfo(dStage_roomDt_c *this,stage_scls_info_dummy_class *param_1)

{
  this->mpScls = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::setPntInfo(dStage_dPnt_c *) */

void __thiscall dStage_roomDt_c::setPntInfo(dStage_roomDt_c *this,dStage_dPnt_c *param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorRoom();
  m_Do_printf::OSReport("Room non Pnt data !\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x702,"0");
  m_Do_printf::OSPanic("d_stage.h",0x702,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getPntInf(void) const */

undefined4 __thiscall dStage_roomDt_c::getPntInf(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non Pnts data !\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x706,"0");
  m_Do_printf::OSPanic("d_stage.h",0x706,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setPathInfo(dStage_dPath_c *) */

void __thiscall dStage_roomDt_c::setPathInfo(dStage_roomDt_c *this,dStage_dPath_c *param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorRoom();
  m_Do_printf::OSReport("Room non Path data !\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x70d,"0");
  m_Do_printf::OSPanic("d_stage.h",0x70d,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getPathInf(void) const */

undefined4 __thiscall dStage_roomDt_c::getPathInf(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non Path data !\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x711,"0");
  m_Do_printf::OSPanic("d_stage.h",0x711,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setPnt2Info(dStage_dPnt_c *) */

void __thiscall dStage_roomDt_c::setPnt2Info(dStage_roomDt_c *this,dStage_dPnt_c *param_1)

{
  this->mpPoint2 = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getPnt2Inf(void) const */

dStage_dPnt_c * __thiscall dStage_roomDt_c::getPnt2Inf(dStage_roomDt_c *this)

{
  return this->mpPoint2;
}


/* __thiscall dStage_roomDt_c::setPath2Info(dStage_dPath_c *) */

void __thiscall dStage_roomDt_c::setPath2Info(dStage_roomDt_c *this,dStage_dPath_c *param_1)

{
  this->mpPath2 = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getPath2Inf(void) const */

dStage_dPath_c * __thiscall dStage_roomDt_c::getPath2Inf(dStage_roomDt_c *this)

{
  return this->mpPath2;
}


/* __thiscall dStage_roomDt_c::setSoundInfo(dStage_SoundInfo_c *) */

void __thiscall dStage_roomDt_c::setSoundInfo(dStage_roomDt_c *this,dStage_SoundInfo_c *param_1)

{
  this->mpSound = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getSoundInf(void) const */

dStage_SoundInfo_c * __thiscall dStage_roomDt_c::getSoundInf(dStage_roomDt_c *this)

{
  return this->mpSound;
}


/* __thiscall dStage_roomDt_c::setEventInfo(dStage_EventInfo_c *) */

void __thiscall dStage_roomDt_c::setEventInfo(dStage_roomDt_c *this,dStage_EventInfo_c *param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorRoom();
  m_Do_printf::OSReport("Room non event data!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x73a,"0");
  m_Do_printf::OSPanic("d_stage.h",0x73a,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getEventInfo(void) const */

undefined4 __thiscall dStage_roomDt_c::getEventInfo(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non event data!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x73e,"0");
  m_Do_printf::OSPanic("d_stage.h",0x73e,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setFileListInfo(dStage_FileList_dt_c *) */

void __thiscall
dStage_roomDt_c::setFileListInfo(dStage_roomDt_c *this,dStage_FileList_dt_c *param_1)

{
  this->mpFileList = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::setFloorInfo(dStage_FloorInfo_c *) */

void __thiscall dStage_roomDt_c::setFloorInfo(dStage_roomDt_c *this,dStage_FloorInfo_c *param_1)

{
  this->mpFloor = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getFloorInfo(void) const */

dStage_FloorInfo_c * __thiscall dStage_roomDt_c::getFloorInfo(dStage_roomDt_c *this)

{
  return this->mpFloor;
}


/* __thiscall dStage_roomDt_c::setMemoryConfig(dStage_MemoryConfig_c *) */

void __thiscall
dStage_roomDt_c::setMemoryConfig(dStage_roomDt_c *this,dStage_MemoryConfig_c *param_1)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non memory config data!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x76c,"0");
  m_Do_printf::OSPanic("d_stage.h",0x76c,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getMemoryConfig(void) const */

undefined4 __thiscall dStage_roomDt_c::getMemoryConfig(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non memory config data!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x775,"0");
  m_Do_printf::OSPanic("d_stage.h",0x775,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setMemoryMap(dStage_MemoryMap_c *) */

void __thiscall dStage_roomDt_c::setMemoryMap(dStage_roomDt_c *this,dStage_MemoryMap_c *param_1)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non memory map data!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x77f,"0");
  m_Do_printf::OSPanic("d_stage.h",0x77f,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getMemoryMap(void) const */

undefined4 __thiscall dStage_roomDt_c::getMemoryMap(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non memory map data!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x788,"0");
  m_Do_printf::OSPanic("d_stage.h",0x788,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setShip(dStage_Ship_c *) */

void __thiscall dStage_roomDt_c::setShip(dStage_roomDt_c *this,dStage_Ship_c *param_1)

{
  this->mpShip = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getShip(void) const */

dStage_Ship_c * __thiscall dStage_roomDt_c::getShip(dStage_roomDt_c *this)

{
  return this->mpShip;
}


/* __thiscall dStage_roomDt_c::setMulti(dStage_Multi_c *) */

void __thiscall dStage_roomDt_c::setMulti(dStage_roomDt_c *this,dStage_Multi_c *param_1)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non multi data!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x7a9,"0");
  m_Do_printf::OSPanic("d_stage.h",0x7a9,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getMulti(void) const */

undefined4 __thiscall dStage_roomDt_c::getMulti(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("Room non multi data!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x7ae,"0");
  m_Do_printf::OSPanic("d_stage.h",0x7ae,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setLbnk(dStage_Lbnk_c *) */

void __thiscall dStage_roomDt_c::setLbnk(dStage_roomDt_c *this,dStage_Lbnk_c *param_1)

{
  this->mpLbnk = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getLbnk(void) const */

dStage_Lbnk_c * __thiscall dStage_roomDt_c::getLbnk(dStage_roomDt_c *this)

{
  return this->mpLbnk;
}


/* __thiscall dStage_roomDt_c::setTresure(stage_tresure_class *) */

void __thiscall dStage_roomDt_c::setTresure(dStage_roomDt_c *this,stage_tresure_class *param_1)

{
  this->mpTresure = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getTresure(void) const */

stage_tresure_class * __thiscall dStage_roomDt_c::getTresure(dStage_roomDt_c *this)

{
  return this->mpTresure;
}


/* __thiscall dStage_roomDt_c::setDMap(dStage_DMap_c *) */

void __thiscall dStage_roomDt_c::setDMap(dStage_roomDt_c *this,dStage_DMap_c *param_1)

{
  ulong uVar1;
  
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x7d2,"0");
  m_Do_printf::OSPanic("d_stage.h",0x7d2,"Halt");
  return;
}


/* __thiscall dStage_roomDt_c::getDMap(void) const */

undefined4 __thiscall dStage_roomDt_c::getDMap(dStage_roomDt_c *this)

{
  ulong uVar1;
  
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x7d7,"0");
  m_Do_printf::OSPanic("d_stage.h",0x7d7,"Halt");
  return 0;
}


/* __thiscall dStage_roomDt_c::setDrTg(stage_tgsc_class *) */

void __thiscall dStage_roomDt_c::setDrTg(dStage_roomDt_c *this,stage_tgsc_class *param_1)

{
  this->mpDrTg = param_1;
  return;
}


/* __thiscall dStage_roomDt_c::getDrTg(void) const */

stage_tgsc_class * __thiscall dStage_roomDt_c::getDrTg(dStage_roomDt_c *this)

{
  return this->mpDrTg;
}


/* __thiscall dStage_stageDt_c::getRoomNo(void) const */

undefined4 __thiscall dStage_stageDt_c::getRoomNo(dStage_stageDt_c *this)

{
  return 0xffffffff;
}


/* __thiscall dStage_stageDt_c::setCamera(stage_camera_class *) */

void __thiscall dStage_stageDt_c::setCamera(dStage_stageDt_c *this,stage_camera_class *param_1)

{
  this->mpCamera = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getCamera(void) const */

stage_camera_class * __thiscall dStage_stageDt_c::getCamera(dStage_stageDt_c *this)

{
  return this->mpCamera;
}


/* __thiscall dStage_stageDt_c::setArrow(stage_arrow_class *) */

void __thiscall dStage_stageDt_c::setArrow(dStage_stageDt_c *this,stage_arrow_class *param_1)

{
  this->mpArrow = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getArrow(void) const */

stage_arrow_class * __thiscall dStage_stageDt_c::getArrow(dStage_stageDt_c *this)

{
  return this->mpArrow;
}


/* __thiscall dStage_stageDt_c::setPlayer(stage_actor_class *) */

void __thiscall dStage_stageDt_c::setPlayer(dStage_stageDt_c *this,stage_actor_class *param_1)

{
  this->field_0xc = (undefined *)param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getPlayer(void) const */

undefined * __thiscall dStage_stageDt_c::getPlayer(dStage_stageDt_c *this)

{
  return this->field_0xc;
}


/* __thiscall dStage_stageDt_c::setPlayerNum(unsigned short) */

void __thiscall dStage_stageDt_c::setPlayerNum(dStage_stageDt_c *this,ushort param_1)

{
  *(ushort *)&this->field_0x44 = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getPlayerNum(void) const */

undefined2 __thiscall dStage_stageDt_c::getPlayerNum(dStage_stageDt_c *this)

{
  return *(undefined2 *)&this->field_0x44;
}


/* __thiscall dStage_stageDt_c::setRoom(roomRead_class *) */

void __thiscall dStage_stageDt_c::setRoom(dStage_stageDt_c *this,roomRead_class *param_1)

{
  this->mpRoomReads = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getRoom(void) const */

roomRead_class * __thiscall dStage_stageDt_c::getRoom(dStage_stageDt_c *this)

{
  return this->mpRoomReads;
}


/* __thiscall dStage_stageDt_c::setMapInfo(stage_map_info_class *) */

void __thiscall dStage_stageDt_c::setMapInfo(dStage_stageDt_c *this,stage_map_info_class *param_1)

{
  this->mpMapInfo = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getMapInfo(void) const */

stage_map_info_class * __thiscall dStage_stageDt_c::getMapInfo(dStage_stageDt_c *this)

{
  return this->mpMapInfo;
}


/* __thiscall dStage_stageDt_c::setMapInfoBase(stage_map_info_dummy_class *) */

void __thiscall
dStage_stageDt_c::setMapInfoBase(dStage_stageDt_c *this,stage_map_info_dummy_class *param_1)

{
  this->mpMapInfoBase = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::setPaletInfo(stage_palet_info_class *) */

void __thiscall
dStage_stageDt_c::setPaletInfo(dStage_stageDt_c *this,stage_palet_info_class *param_1)

{
  this->mpPaletInfo = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getPaletInfo(void) const */

stage_palet_info_class * __thiscall dStage_stageDt_c::getPaletInfo(dStage_stageDt_c *this)

{
  return this->mpPaletInfo;
}


/* __thiscall dStage_stageDt_c::setPselectInfo(stage_pselect_info_class *) */

void __thiscall
dStage_stageDt_c::setPselectInfo(dStage_stageDt_c *this,stage_pselect_info_class *param_1)

{
  this->mpPselectInfo = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getPselectInfo(void) const */

stage_pselect_info_class * __thiscall dStage_stageDt_c::getPselectInfo(dStage_stageDt_c *this)

{
  return this->mpPselectInfo;
}


/* __thiscall dStage_stageDt_c::setEnvrInfo(stage_envr_info_class *) */

void __thiscall dStage_stageDt_c::setEnvrInfo(dStage_stageDt_c *this,stage_envr_info_class *param_1)

{
  this->mpEnvrInfo = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getEnvrInfo(void) const */

stage_envr_info_class * __thiscall dStage_stageDt_c::getEnvrInfo(dStage_stageDt_c *this)

{
  return this->mpEnvrInfo;
}


/* __thiscall dStage_stageDt_c::setVrboxInfo(stage_vrbox_info_class *) */

void __thiscall
dStage_stageDt_c::setVrboxInfo(dStage_stageDt_c *this,stage_vrbox_info_class *param_1)

{
  this->mpVrboxInfo = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getVrboxInfo(void) const */

stage_vrbox_info_class * __thiscall dStage_stageDt_c::getVrboxInfo(dStage_stageDt_c *this)

{
  return this->mpVrboxInfo;
}


/* __thiscall dStage_stageDt_c::setPlightInfo(stage_plight_info_class *) */

void __thiscall
dStage_stageDt_c::setPlightInfo(dStage_stageDt_c *this,stage_plight_info_class *param_1)

{
  this->mpPlightInfo = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getPlightInfo(void) const */

stage_plight_info_class * __thiscall dStage_stageDt_c::getPlightInfo(dStage_stageDt_c *this)

{
  return this->mpPlightInfo;
}


/* __thiscall dStage_stageDt_c::setPaletNumInfo(int) */

void __thiscall dStage_stageDt_c::setPaletNumInfo(dStage_stageDt_c *this,int param_1)

{
  this->field_0x30 = (undefined *)param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getPaletNumInfo(void) const */

undefined * __thiscall dStage_stageDt_c::getPaletNumInfo(dStage_stageDt_c *this)

{
  return this->field_0x30;
}


/* __thiscall dStage_stageDt_c::setPselectNumInfo(int) */

void __thiscall dStage_stageDt_c::setPselectNumInfo(dStage_stageDt_c *this,int param_1)

{
  this->field_0x34 = (undefined *)param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getPselectNumInfo(void) const */

undefined * __thiscall dStage_stageDt_c::getPselectNumInfo(dStage_stageDt_c *this)

{
  return this->field_0x34;
}


/* __thiscall dStage_stageDt_c::setEnvrNumInfo(int) */

void __thiscall dStage_stageDt_c::setEnvrNumInfo(dStage_stageDt_c *this,int param_1)

{
  this->field_0x38 = (undefined *)param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getEnvrNumInfo(void) const */

undefined * __thiscall dStage_stageDt_c::getEnvrNumInfo(dStage_stageDt_c *this)

{
  return this->field_0x38;
}


/* __thiscall dStage_stageDt_c::setVrboxNumInfo(int) */

void __thiscall dStage_stageDt_c::setVrboxNumInfo(dStage_stageDt_c *this,int param_1)

{
  this->field_0x3c = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getVrboxNumInfo(void) const */

int __thiscall dStage_stageDt_c::getVrboxNumInfo(dStage_stageDt_c *this)

{
  return this->field_0x3c;
}


/* __thiscall dStage_stageDt_c::setLightVecInfo(stage_lightvec_info_class *) */

void __thiscall
dStage_stageDt_c::setLightVecInfo(dStage_stageDt_c *this,stage_lightvec_info_class *param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorStage();
  m_Do_printf::OSReport("stage non LightVec data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x94c,"0");
  m_Do_printf::OSPanic("d_stage.h",0x94c,"Halt");
  return;
}


/* __thiscall dStage_stageDt_c::getLightVecInfo(void) const */

undefined4 __thiscall dStage_stageDt_c::getLightVecInfo(dStage_stageDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("stage non LightVec data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x950,"0");
  m_Do_printf::OSPanic("d_stage.h",0x950,"Halt");
  return 0;
}


/* __thiscall dStage_stageDt_c::setLightVecInfoNum(int) */

void __thiscall dStage_stageDt_c::setLightVecInfoNum(dStage_stageDt_c *this,int param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorStage();
  m_Do_printf::OSReport("stage non LightVecNum data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x957,"0");
  m_Do_printf::OSPanic("d_stage.h",0x957,"Halt");
  return;
}


/* __thiscall dStage_stageDt_c::getLightVecInfoNum(void) const */

undefined4 __thiscall dStage_stageDt_c::getLightVecInfoNum(dStage_stageDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("stage non LightVecNum data !!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x95b,"0");
  m_Do_printf::OSPanic("d_stage.h",0x95b,"Halt");
  return 0;
}


/* __thiscall dStage_stageDt_c::setPlightNumInfo(int) */

void __thiscall dStage_stageDt_c::setPlightNumInfo(dStage_stageDt_c *this,int param_1)

{
  this->mPlightInfoNum = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getPlightNumInfo(void) const */

int __thiscall dStage_stageDt_c::getPlightNumInfo(dStage_stageDt_c *this)

{
  return this->mPlightInfoNum;
}


/* __thiscall dStage_stageDt_c::setStagInfo(stage_stag_info_class *) */

void __thiscall dStage_stageDt_c::setStagInfo(dStage_stageDt_c *this,stage_stag_info_class *param_1)

{
  this->mpStagInfo = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getStagInfo(void) const */

stage_stag_info_class * __thiscall dStage_stageDt_c::getStagInfo(dStage_stageDt_c *this)

{
  return this->mpStagInfo;
}


/* __thiscall dStage_stageDt_c::setSclsInfo(stage_scls_info_dummy_class *) */

void __thiscall
dStage_stageDt_c::setSclsInfo(dStage_stageDt_c *this,stage_scls_info_dummy_class *param_1)

{
  this->mpScls = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getSclsInfo(void) const */

stage_scls_info_dummy_class * __thiscall dStage_stageDt_c::getSclsInfo(dStage_stageDt_c *this)

{
  return this->mpScls;
}


/* __thiscall dStage_stageDt_c::setPntInfo(dStage_dPnt_c *) */

void __thiscall dStage_stageDt_c::setPntInfo(dStage_stageDt_c *this,dStage_dPnt_c *param_1)

{
  this->mpPnt = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getPntInf(void) const */

dStage_dPnt_c * __thiscall dStage_stageDt_c::getPntInf(dStage_stageDt_c *this)

{
  return this->mpPnt;
}


/* __thiscall dStage_stageDt_c::setPathInfo(dStage_dPath_c *) */

void __thiscall dStage_stageDt_c::setPathInfo(dStage_stageDt_c *this,dStage_dPath_c *param_1)

{
  this->mpPath = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getPathInf(void) const */

dStage_dPath_c * __thiscall dStage_stageDt_c::getPathInf(dStage_stageDt_c *this)

{
  return this->mpPath;
}


/* __thiscall dStage_stageDt_c::setPnt2Info(dStage_dPnt_c *) */

void __thiscall dStage_stageDt_c::setPnt2Info(dStage_stageDt_c *this,dStage_dPnt_c *param_1)

{
  this->mpPnt2 = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getPnt2Inf(void) const */

dStage_dPnt_c * __thiscall dStage_stageDt_c::getPnt2Inf(dStage_stageDt_c *this)

{
  return this->mpPnt2;
}


/* __thiscall dStage_stageDt_c::setPath2Info(dStage_dPath_c *) */

void __thiscall dStage_stageDt_c::setPath2Info(dStage_stageDt_c *this,dStage_dPath_c *param_1)

{
  this->mpPath2 = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getPath2Inf(void) const */

dStage_dPath_c * __thiscall dStage_stageDt_c::getPath2Inf(dStage_stageDt_c *this)

{
  return this->mpPath2;
}


/* __thiscall dStage_stageDt_c::setSoundInfo(dStage_SoundInfo_c *) */

void __thiscall dStage_stageDt_c::setSoundInfo(dStage_stageDt_c *this,dStage_SoundInfo_c *param_1)

{
  this->field_0x60 = (undefined *)param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getSoundInf(void) const */

undefined * __thiscall dStage_stageDt_c::getSoundInf(dStage_stageDt_c *this)

{
  return this->field_0x60;
}


/* __thiscall dStage_stageDt_c::setEventInfo(dStage_EventInfo_c *) */

void __thiscall dStage_stageDt_c::setEventInfo(dStage_stageDt_c *this,dStage_EventInfo_c *param_1)

{
  this->mpEventInfo = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getEventInfo(void) const */

dStage_EventInfo_c * __thiscall dStage_stageDt_c::getEventInfo(dStage_stageDt_c *this)

{
  return this->mpEventInfo;
}


/* __thiscall dStage_stageDt_c::setFileListInfo(dStage_FileList_dt_c *) */

void __thiscall
dStage_stageDt_c::setFileListInfo(dStage_stageDt_c *this,dStage_FileList_dt_c *param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorStage();
  m_Do_printf::OSReport("stage non filelist data!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x9ba,"0");
  m_Do_printf::OSPanic("d_stage.h",0x9ba,"Halt");
  return;
}


/* __thiscall dStage_stageDt_c::getFileListInfo(void) const */

undefined4 __thiscall dStage_stageDt_c::getFileListInfo(dStage_stageDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("stage non filelist data!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0x9be,"0");
  m_Do_printf::OSPanic("d_stage.h",0x9be,"Halt");
  return 0;
}


/* __thiscall dStage_stageDt_c::setFloorInfo(dStage_FloorInfo_c *) */

void __thiscall dStage_stageDt_c::setFloorInfo(dStage_stageDt_c *this,dStage_FloorInfo_c *param_1)

{
  this->field_0x68 = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getFloorInfo(void) const */

undefined * __thiscall dStage_stageDt_c::getFloorInfo(dStage_stageDt_c *this)

{
  return this->field_0x68;
}


/* __thiscall dStage_stageDt_c::setMemoryConfig(dStage_MemoryConfig_c *) */

void __thiscall
dStage_stageDt_c::setMemoryConfig(dStage_stageDt_c *this,dStage_MemoryConfig_c *param_1)

{
  this->field_0x6c = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getMemoryConfig(void) const */

undefined * __thiscall dStage_stageDt_c::getMemoryConfig(dStage_stageDt_c *this)

{
  return this->field_0x6c;
}


/* __thiscall dStage_stageDt_c::setMemoryMap(dStage_MemoryMap_c *) */

void __thiscall dStage_stageDt_c::setMemoryMap(dStage_stageDt_c *this,dStage_MemoryMap_c *param_1)

{
  this->field_0x70 = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getMemoryMap(void) const */

undefined * __thiscall dStage_stageDt_c::getMemoryMap(dStage_stageDt_c *this)

{
  return this->field_0x70;
}


/* __thiscall dStage_stageDt_c::setShip(dStage_Ship_c *) */

void __thiscall dStage_stageDt_c::setShip(dStage_stageDt_c *this,dStage_Ship_c *param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorStage();
  m_Do_printf::OSReport("stage non SHIP data!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0xa01,"0");
  m_Do_printf::OSPanic("d_stage.h",0xa01,"Halt");
  return;
}


/* __thiscall dStage_stageDt_c::getShip(void) const */

undefined4 __thiscall dStage_stageDt_c::getShip(dStage_stageDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("stage non SHIP data!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0xa05,"0");
  m_Do_printf::OSPanic("d_stage.h",0xa05,"Halt");
  return 0;
}


/* __thiscall dStage_stageDt_c::setMulti(dStage_Multi_c *) */

void __thiscall dStage_stageDt_c::setMulti(dStage_stageDt_c *this,dStage_Multi_c *param_1)

{
  this->mpMulti = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getMulti(void) const */

dStage_Multi_c * __thiscall dStage_stageDt_c::getMulti(dStage_stageDt_c *this)

{
  return this->mpMulti;
}


/* __thiscall dStage_stageDt_c::setLbnk(dStage_Lbnk_c *) */

void __thiscall dStage_stageDt_c::setLbnk(dStage_stageDt_c *this,dStage_Lbnk_c *param_1)

{
  ulong uVar1;
  
  d_stage::dStage_SetErrorStage();
  m_Do_printf::OSReport("stage non Lbnk data!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0xa1e,"0");
  m_Do_printf::OSPanic("d_stage.h",0xa1e,"Halt");
  return;
}


/* __thiscall dStage_stageDt_c::getLbnk(void) const */

undefined4 __thiscall dStage_stageDt_c::getLbnk(dStage_stageDt_c *this)

{
  ulong uVar1;
  
  m_Do_printf::OSReport("stage non Lbnk data!\n");
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"d_stage.h",0xa25,"0");
  m_Do_printf::OSPanic("d_stage.h",0xa25,"Halt");
  return 0;
}


/* __thiscall dStage_stageDt_c::setTresure(stage_tresure_class *) */

void __thiscall dStage_stageDt_c::setTresure(dStage_stageDt_c *this,stage_tresure_class *param_1)

{
  this->field_0x78 = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getTresure(void) const */

undefined * __thiscall dStage_stageDt_c::getTresure(dStage_stageDt_c *this)

{
  return this->field_0x78;
}


/* __thiscall dStage_stageDt_c::setDMap(dStage_DMap_c *) */

void __thiscall dStage_stageDt_c::setDMap(dStage_stageDt_c *this,dStage_DMap_c *param_1)

{
  this->field_0x7c = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getDMap(void) const */

undefined * __thiscall dStage_stageDt_c::getDMap(dStage_stageDt_c *this)

{
  return this->field_0x7c;
}


/* __thiscall dStage_stageDt_c::setDrTg(stage_tgsc_class *) */

void __thiscall dStage_stageDt_c::setDrTg(dStage_stageDt_c *this,stage_tgsc_class *param_1)

{
  this->field_0x80 = param_1;
  return;
}


/* __thiscall dStage_stageDt_c::getDrTg(void) const */

undefined * __thiscall dStage_stageDt_c::getDrTg(dStage_stageDt_c *this)

{
  return this->field_0x80;
}


namespace d_stage {

void __sinit_d_stage_cpp(void)

{
  Runtime.PPCEABI.H::__construct_array
            (&DAT_803bcef4,::stage_tresure_data_class::stage_tresure_data_class,
             ::stage_tresure_data_class::_stage_tresure_data_class,0x20,0x20);
  Runtime.PPCEABI.H::__register_global_object
            (&TresureInfo,::dStage_KeepTresureInfo::_dStage_KeepTresureInfo,&_4236);
  Runtime.PPCEABI.H::__construct_array
            (&DAT_803bd304,::stage_tgsc_data_class::stage_tgsc_data_class,
             ::stage_tgsc_data_class::_stage_tgsc_data_class,0x24,0x40);
  Runtime.PPCEABI.H::__register_global_object
            (&DoorInfo,::dStage_KeepDoorInfo::_dStage_KeepDoorInfo,&_4241);
  Runtime.PPCEABI.H::__construct_array
            (::dStage_roomControl_c::mStatus,::dStage_roomStatus_c::dStage_roomStatus_c,
             ::dStage_roomStatus_c::_dStage_roomStatus_c,0x114,0x40);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_5591,&_5592);
  return;
}


void __arraydtor_5591(void)

{
  Runtime.PPCEABI.H::__destroy_arr
            (::dStage_roomControl_c::mStatus,::dStage_roomStatus_c::_dStage_roomStatus_c,0x114,0x40)
  ;
  return;
}

}

/* __thiscall dStage_roomStatus_c::~dStage_roomStatus_c(void) */

void __thiscall dStage_roomStatus_c::_dStage_roomStatus_c(dStage_roomStatus_c *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dStage_roomStatus_c *)0x0;
  if (bVar1) {
    if ((bVar1) && ((this->parent).parent.vtbl = (dStage_dt_c__vtbl *)&dStage_roomDt_c::__vt, bVar1)
       ) {
      (this->parent).parent.vtbl = (dStage_dt_c__vtbl *)&dStage_dt_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dStage_roomStatus_c::dStage_roomStatus_c(void) */

void __thiscall dStage_roomStatus_c::dStage_roomStatus_c(dStage_roomStatus_c *this)

{
  (this->parent).parent.vtbl = (dStage_dt_c__vtbl *)&dStage_dt_c::__vt;
  (this->parent).parent.vtbl = (dStage_dt_c__vtbl *)&dStage_roomDt_c::__vt;
  (this->mTevStr).mLightObj.mPos.x = J3DGraphBase::j3dDefaultLightInfo;
  (this->mTevStr).mLightObj.mPos.y = DAT_80370d1c;
  (this->mTevStr).mLightObj.mPos.z = DAT_80370d20;
  (this->mTevStr).mLightObj.mDir.x = DAT_80370d24;
  (this->mTevStr).mLightObj.mDir.y = DAT_80370d28;
  (this->mTevStr).mLightObj.mDir.z = DAT_80370d2c;
  (this->mTevStr).mLightObj.mColor.r = DAT_80370d30;
  (this->mTevStr).mLightObj.mColor.g = DAT_80370d31;
  (this->mTevStr).mLightObj.mColor.b = DAT_80370d32;
  (this->mTevStr).mLightObj.mColor.a = DAT_80370d33;
  (this->mTevStr).mLightObj.mCosAtten.x = DAT_80370d34;
  (this->mTevStr).mLightObj.mCosAtten.y = DAT_80370d38;
  (this->mTevStr).mLightObj.mCosAtten.z = DAT_80370d3c;
  (this->mTevStr).mLightObj.mDistAtten.x = DAT_80370d40;
  (this->mTevStr).mLightObj.mDistAtten.y = DAT_80370d44;
  (this->mTevStr).mLightObj.mDistAtten.z = DAT_80370d48;
  return;
}


/* __thiscall dStage_KeepDoorInfo::~dStage_KeepDoorInfo(void) */

void __thiscall dStage_KeepDoorInfo::_dStage_KeepDoorInfo(dStage_KeepDoorInfo *this)

{
  short in_r4;
  
  if ((this != (dStage_KeepDoorInfo *)0x0) &&
     (Runtime.PPCEABI.H::__destroy_arr
                (this + 4,stage_tgsc_data_class::_stage_tgsc_data_class,0x24,0x40), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall stage_tgsc_data_class::~stage_tgsc_data_class(void) */

void __thiscall stage_tgsc_data_class::_stage_tgsc_data_class(stage_tgsc_data_class *this)

{
  short in_r4;
  
  if ((this != (stage_tgsc_data_class *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall stage_tgsc_data_class::stage_tgsc_data_class(void) */

void __thiscall stage_tgsc_data_class::stage_tgsc_data_class(stage_tgsc_data_class *this)

{
  return;
}


/* __thiscall dStage_KeepTresureInfo::~dStage_KeepTresureInfo(void) */

void __thiscall dStage_KeepTresureInfo::_dStage_KeepTresureInfo(dStage_KeepTresureInfo *this)

{
  short in_r4;
  
  if ((this != (dStage_KeepTresureInfo *)0x0) &&
     (Runtime.PPCEABI.H::__destroy_arr
                (this + 4,stage_tresure_data_class::_stage_tresure_data_class,0x20,0x20), 0 < in_r4)
     ) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall stage_tresure_data_class::~stage_tresure_data_class(void) */

void __thiscall stage_tresure_data_class::_stage_tresure_data_class(stage_tresure_data_class *this)

{
  short in_r4;
  
  if ((this != (stage_tresure_data_class *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall stage_tresure_data_class::stage_tresure_data_class(void) */

void __thiscall stage_tresure_data_class::stage_tresure_data_class(stage_tresure_data_class *this)

{
  return;
}


/* __thiscall daPy_py_c::getBokoFlamePos(cXyz *) */

undefined4 __thiscall daPy_py_c::getBokoFlamePos(daPy_py_c *this,cXyz *param_1)

{
  return 0;
}

