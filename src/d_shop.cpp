#include <d_shop.h>
#include <d_shop.h>
#include <d_camera.h>
#include <SComponent/c_lib.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <mtx/mtxvec.h>
#include <d_save.h>
#include <f_op_actor_mng.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <d_a_shop_item_static.h>
#include <mtx/vec.h>
#include <SComponent/c_xyz.h>
#include <d_a_itembase_static.h>
#include <d_lib.h>
#include <f_op_msg_mng.h>
#include <d_com_inf_game.h>
#include <d_item.h>
#include <m_Do_ext.h>
#include <JKernel/JKRHeap.h>
#include <SComponent/c_math.h>
#include <mDoExt_brkAnm.h>
#include <ShopCursor_c.h>
#include <mDoExt_baseAnm.h>
#include <ShopCam_action_c.h>
#include <ShopItems_c.h>


/* __thiscall ShopCam_action_c::shop_cam_action_init(void) */

undefined4 __thiscall ShopCam_action_c::shop_cam_action_init(ShopCam_action_c *this)

{
  undefined4 uVar1;
  float *pfVar2;
  undefined *puVar3;
  
  ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c =
       ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c | 0x8000000
  ;
  uVar1 = DAT_80376954;
  *(undefined4 *)this = d_shop::_4140;
  *(undefined4 *)&this->field_0x4 = uVar1;
  *(undefined **)&this->field_0x8 = PTR_shop_cam_action_80376958;
  pfVar2 = (float *)(&d_shop::shop_cam_data_tbl)[this->field_0x56];
  this->field_0x18 = *pfVar2;
  this->field_0x1c = pfVar2[1];
  this->field_0x20 = pfVar2[2];
  puVar3 = (&d_shop::shop_cam_data_tbl)[this->field_0x56];
  this->field_0x24 = *(float *)(puVar3 + 0xc);
  this->field_0x28 = *(float *)(puVar3 + 0x10);
  this->field_0x2c = *(float *)(puVar3 + 0x14);
  this->field_0x30 = *(float *)((&d_shop::shop_cam_data_tbl)[this->field_0x56] + 0x18);
  this->field_0x54 = -1;
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x8005f200) */
/* __thiscall ShopCam_action_c::shop_cam_action(void) */

undefined4 __thiscall ShopCam_action_c::shop_cam_action(ShopCam_action_c *this)

{
  float fVar1;
  float *pfVar2;
  undefined *puVar3;
  camera_class *pcVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  cXyz local_48;
  cXyz local_3c;
  cXyz local_30;
  cXyz local_24;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pcVar4 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
           [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera].mpCamera;
  dCamera_c::Stay(&pcVar4->mBody);
  dCamera_c::SetTrimSize(&pcVar4->mBody,1);
  if (this->field_0x54 < 0) {
    pfVar2 = (float *)(&d_shop::shop_cam_data_tbl)[this->field_0x56];
    local_24.x = *pfVar2;
    local_24.y = pfVar2[1];
    local_24.z = pfVar2[2];
    local_30.x = pfVar2[3];
    local_30.y = pfVar2[4];
    local_30.z = pfVar2[5];
    fVar1 = pfVar2[6];
  }
  else {
    puVar3 = (&d_shop::shop_cam_data_tbl)[this->field_0x56];
    local_24.x = *(float *)(puVar3 + 0x1c);
    local_24.y = *(float *)(puVar3 + 0x20);
    local_24.z = *(float *)(puVar3 + 0x24);
    local_30.x = *(float *)(puVar3 + 0x28);
    local_30.y = *(float *)(puVar3 + 0x2c);
    local_30.z = *(float *)(puVar3 + 0x30);
    fVar1 = *(float *)(puVar3 + 0x34);
  }
  dVar6 = (double)fVar1;
  SComponent::cLib_addCalcPos2((cXyz *)&this->field_0x18,&local_24,d_shop::_4187,d_shop::_4188);
  SComponent::cLib_addCalcPos2((cXyz *)&this->field_0x24,&local_30,d_shop::_4187,d_shop::_4188);
  SComponent::cLib_addCalc2(&this->field_0x30,(float)dVar6,d_shop::_4187,d_shop::_4189);
  local_3c.x = this->field_0x18;
  local_3c.y = this->field_0x1c;
  local_3c.z = this->field_0x20;
  local_48.x = this->field_0x24;
  local_48.y = this->field_0x28;
  local_48.z = this->field_0x2c;
  dCamera_c::Set(&pcVar4->mBody,&local_3c,&local_48,this->field_0x30,0);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8005f350) */
/* __thiscall ShopCam_action_c::rsh_talk_cam_action_init(fopAc_ac_c *,
                                                         cXyz,
                                                         cXyz,
                                                         float) */

undefined4 __thiscall
ShopCam_action_c::rsh_talk_cam_action_init
          (ShopCam_action_c *this,fopAc_ac_c *param_1,cXyz *param_2,cXyz *param_3,float param_4)

{
  undefined4 uVar1;
  bool bVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  PTMF local_48;
  cXyz local_3c;
  cXyz local_30;
  undefined auStack8 [8];
  
  dVar4 = (double)param_4;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_48.this_delta = d_shop::_4195;
  local_48.vtbl_offset = DAT_80376960;
  local_48.func = PTR_rsh_talk_cam_action_80376964;
  bVar2 = Runtime.PPCEABI.H::__ptmf_cmpr((PTMF *)this,&local_48);
  if (bVar2 != false) {
    ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c =
         ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c |
         0x8000000;
    uVar1 = DAT_8037696c;
    *(undefined4 *)this = d_shop::_4199;
    *(undefined4 *)&this->field_0x4 = uVar1;
    *(undefined **)&this->field_0x8 = PTR_rsh_talk_cam_action_80376970;
    mtx::PSMTXTrans((double)(param_1->mAttentionPos).x,(double)(param_1->mAttentionPos).y,
                    (double)(param_1->mAttentionPos).z,&mDoMtx_stack_c::now);
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,(param_1->mCurrent).mRot.y);
    mtx::PSMTXMultVec(&mDoMtx_stack_c::now,param_2,&local_30);
    mtx::PSMTXMultVec(&mDoMtx_stack_c::now,param_3,&local_3c);
    this->field_0x18 = local_30.x;
    this->field_0x1c = local_30.y;
    this->field_0x20 = local_30.z;
    this->field_0x24 = local_3c.x;
    this->field_0x28 = local_3c.y;
    this->field_0x2c = local_3c.z;
    this->field_0x30 = (float)dVar4;
    this->field_0x54 = -1;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return 1;
}


/* __thiscall ShopCam_action_c::rsh_talk_cam_action(void) */

undefined4 __thiscall ShopCam_action_c::rsh_talk_cam_action(ShopCam_action_c *this)

{
  camera_class *pcVar1;
  cXyz local_28;
  cXyz local_1c;
  
  pcVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
           [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera].mpCamera;
  dCamera_c::Stay(&pcVar1->mBody);
  dCamera_c::SetTrimSize(&pcVar1->mBody,1);
  local_1c.x = this->field_0x18;
  local_1c.y = this->field_0x1c;
  local_1c.z = this->field_0x20;
  local_28.x = this->field_0x24;
  local_28.y = this->field_0x28;
  local_28.z = this->field_0x2c;
  dCamera_c::Set(&pcVar1->mBody,&local_1c,&local_28,this->field_0x30,0);
  return 1;
}


/* __thiscall ShopCam_action_c::ds_normal_cam_action_init(void) */

undefined4 __thiscall ShopCam_action_c::ds_normal_cam_action_init(ShopCam_action_c *this)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  
  ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c =
       ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c | 0x8000000
  ;
  uVar1 = DAT_80376978;
  *(undefined4 *)this = d_shop::_4250;
  *(undefined4 *)&this->field_0x4 = uVar1;
  *(undefined **)&this->field_0x8 = PTR_ds_normal_cam_action_8037697c;
  fVar2 = d_shop::_4261;
  this->field_0x18 = d_shop::_4261;
  fVar3 = d_shop::_4262;
  this->field_0x1c = d_shop::_4262;
  this->field_0x20 = d_shop::_4263;
  this->field_0x24 = fVar2;
  this->field_0x28 = fVar3;
  this->field_0x2c = d_shop::_4264;
  this->field_0x30 = d_shop::_4265;
  this->field_0x54 = -1;
  return 1;
}


/* __thiscall ShopCam_action_c::ds_normal_cam_action(void) */

undefined4 __thiscall ShopCam_action_c::ds_normal_cam_action(ShopCam_action_c *this)

{
  float fVar1;
  float fVar2;
  camera_class *pcVar3;
  cXyz local_28;
  cXyz local_1c;
  
  pcVar3 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
           [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera].mpCamera;
  dCamera_c::Stay(&pcVar3->mBody);
  dCamera_c::SetTrimSize(&pcVar3->mBody,1);
  fVar1 = d_shop::_4261;
  this->field_0x18 = d_shop::_4261;
  fVar2 = d_shop::_4262;
  this->field_0x1c = d_shop::_4262;
  this->field_0x20 = d_shop::_4263;
  this->field_0x24 = fVar1;
  this->field_0x28 = fVar2;
  this->field_0x2c = d_shop::_4264;
  this->field_0x30 = d_shop::_4265;
  local_1c.x = this->field_0x18;
  local_1c.y = this->field_0x1c;
  local_1c.z = this->field_0x20;
  local_28.x = this->field_0x24;
  local_28.y = this->field_0x28;
  local_28.z = this->field_0x2c;
  dCamera_c::Set(&pcVar3->mBody,&local_1c,&local_28,this->field_0x30,0);
  return 1;
}


/* __thiscall ShopCam_action_c::Save(void) */

void __thiscall ShopCam_action_c::Save(ShopCam_action_c *this)

{
  camera_class *pcVar1;
  
  pcVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera == (camera_class *)0x0) {
    return;
  }
  *(float *)&this->field_0x34 =
       ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mCenterPos).x;
  *(float *)&this->field_0x38 = (pcVar1->mCenterPos).y;
  *(float *)&this->field_0x3c = (pcVar1->mCenterPos).z;
  *(float *)&this->field_0x40 = (pcVar1->mEyePos).x;
  *(float *)&this->field_0x44 = (pcVar1->mEyePos).y;
  *(float *)&this->field_0x48 = (pcVar1->mEyePos).z;
  *(float *)&this->field_0x4c = pcVar1->mFovY;
  return;
}


/* __thiscall ShopCam_action_c::Reset(void) */

void __thiscall ShopCam_action_c::Reset(ShopCam_action_c *this)

{
  undefined4 uVar1;
  camera_class *pcVar2;
  cXyz local_38;
  cXyz local_2c;
  cXyz local_20;
  cXyz local_14;
  
  pcVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
           [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera].mpCamera;
  local_14.x = *(float *)&this->field_0x34;
  local_14.y = *(float *)&this->field_0x38;
  local_14.z = *(float *)&this->field_0x3c;
  local_20.x = *(float *)&this->field_0x40;
  local_20.y = *(float *)&this->field_0x44;
  local_20.z = *(float *)&this->field_0x48;
  dCamera_c::Set(&pcVar2->mBody,&local_14,&local_20,*(float *)&this->field_0x4c,0);
  dCamera_c::Stay(&pcVar2->mBody);
  local_2c.x = *(float *)&this->field_0x34;
  local_2c.y = *(float *)&this->field_0x38;
  local_2c.z = *(float *)&this->field_0x3c;
  local_38.x = *(float *)&this->field_0x40;
  local_38.y = *(float *)&this->field_0x44;
  local_38.z = *(float *)&this->field_0x48;
  dCamera_c::Reset(&pcVar2->mBody,&local_2c,&local_38,*(float *)&this->field_0x4c,0);
  uVar1 = DAT_80370fbc;
  *(undefined4 *)this = Runtime.PPCEABI.H::__ptmf_null;
  *(undefined4 *)&this->field_0x4 = uVar1;
  *(undefined4 *)&this->field_0x8 = DAT_80370fc0;
  return;
}


/* __thiscall ShopCam_action_c::move(void) */

void __thiscall ShopCam_action_c::move(ShopCam_action_c *this)

{
  bool bVar1;
  void *in_r4;
  
  bVar1 = Runtime.PPCEABI.H::__ptmf_test((PTMF *)this);
  if (bVar1 != false) {
    Runtime.PPCEABI.H::__ptmf_scall((PTMF *)this,this,in_r4);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall ShopItems_c::createItem(int,
                                      int) */

void __thiscall ShopItems_c::createItem(ShopItems_c *this,int numItems,int param_2)

{
  Item_set_pos_data *pIVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_38;
  short local_34;
  cXyz local_30;
  
  local_38 = ::csXyz::Zero._0_4_;
  local_34 = ::csXyz::Zero.z;
  if (this->mItemSetListGlobalIdx == 0) {
    pIVar1 = d_shop::Item_set_pos_data_tbl[this->mItemSetListGlobalIdx];
    local_30.z = pIVar1->mItemPositions[0].z;
    local_30.y = pIVar1->mItemPositions[0].y;
    local_30.x = pIVar1->mItemPositions[0].x;
    dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xd04);
    dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xd02);
    iVar2 = f_op_actor_mng::fopAcM_createShopItem
                      (&local_30,
                       (*d_shop::Item_set_data_tbl[this->mItemSetListGlobalIdx])->mpItemData->
                       mItemNo,(csXyz *)&local_38,param_2,(cXyz *)0x0,(undefined *)0x0);
    this->mItemActorProcessIds[0] = iVar2;
    local_30.x = local_30.x + d_shop::_4384;
    iVar2 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xd04);
    if (iVar2 != 0) {
      iVar2 = f_op_actor_mng::fopAcM_createShopItem
                        (&local_30,
                         d_shop::Item_set_data_tbl[this->mItemSetListGlobalIdx][1]->mpItemData->
                         mItemNo,(csXyz *)&local_38,param_2,(cXyz *)0x0,(undefined *)0x0);
      this->mItemActorProcessIds[1] = iVar2;
      local_30.x = local_30.x + d_shop::_4384;
    }
    iVar2 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xd02);
    if (iVar2 != 0) {
      iVar2 = f_op_actor_mng::fopAcM_createShopItem
                        (&local_30,
                         d_shop::Item_set_data_tbl[this->mItemSetListGlobalIdx][2]->mpItemData->
                         mItemNo,(csXyz *)&local_38,param_2,(cXyz *)0x0,(undefined *)0x0);
      this->mItemActorProcessIds[2] = iVar2;
    }
  }
  else {
    iVar5 = 0;
    iVar4 = 0;
    for (iVar2 = 0; iVar2 < numItems; iVar2 = iVar2 + 1) {
      iVar3 = f_op_actor_mng::fopAcM_createShopItem
                        ((cXyz *)((int)&d_shop::Item_set_pos_data_tbl[this->mItemSetListGlobalIdx]->
                                        mItemPositions[0].x + iVar5),
                         ***(ulong ***)
                            ((int)d_shop::Item_set_data_tbl[this->mItemSetListGlobalIdx] + iVar4),
                         (csXyz *)&local_38,param_2,(cXyz *)0x0,(undefined *)0x0);
      *(int *)((int)this->mItemActorProcessIds + iVar4) = iVar3;
      iVar5 = iVar5 + 0xc;
      iVar4 = iVar4 + 4;
    }
  }
  this->mNumItems = (short)numItems;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall ShopItems_c::Item_Select(int) */

undefined4 __thiscall ShopItems_c::Item_Select(ShopItems_c *this,int param_1)

{
  fopAc_ac_c *this_00;
  int iVar1;
  cXyz *pcVar2;
  double dVar3;
  double dVar4;
  float fVar5;
  int local_70;
  cXyz local_6c;
  cXyz local_60;
  cXyz cStack84;
  cXyz local_48;
  cXyz local_3c;
  cXyz local_30;
  cXyz local_24;
  
  local_70 = this->mItemActorProcessIds[param_1];
  this_00 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_70);
  if (this_00 != (fopAc_ac_c *)0x0) {
    iVar1 = daShopItem_c::getRotateP((daShopItem_c *)this_00);
    pcVar2 = (cXyz *)daShopItem_c::getPosP((daShopItem_c *)this_00);
    local_24.x = (this_00->mOrig).mPos.x;
    local_24.y = (this_00->mOrig).mPos.y;
    local_24.z = (this_00->mOrig).mPos.z;
    local_30.x = (this->field_0x30).x;
    local_30.y = (this->field_0x30).y;
    local_30.z = (this->field_0x30).z;
    daShopItem_c::getCenter((daShopItem_c *)&cStack84);
    mtx::PSVECSubtract(&local_30,&cStack84,&local_30);
    if (this->field_0x3c == 1) {
      ::cXyz::operator__(&local_60,&local_30,&local_24);
      local_3c.x = local_60.x;
      local_3c.y = local_60.y;
      local_3c.z = local_60.z;
      fVar5 = mtx::PSVECSquareMag(&local_3c);
      dVar4 = (double)fVar5;
      if ((double)d_shop::_4457 < dVar4) {
        dVar3 = 1.0 / SQRT(dVar4);
        dVar3 = d_shop::_4458 * dVar3 * (d_shop::_4459 - dVar4 * dVar3 * dVar3);
        dVar3 = d_shop::_4458 * dVar3 * (d_shop::_4459 - dVar4 * dVar3 * dVar3);
        dVar4 = (double)(float)(dVar4 * d_shop::_4458 * dVar3 *
                                        (d_shop::_4459 - dVar4 * dVar3 * dVar3));
      }
      SComponent::cLib_addCalcPos2
                (pcVar2,&local_30,d_shop::_4460,(float)((double)d_shop::_4461 * dVar4));
    }
    else {
      ::cXyz::operator__(&local_6c,&local_30,&local_24);
      local_48.x = local_6c.x;
      local_48.y = local_6c.y;
      local_48.z = local_6c.z;
      fVar5 = mtx::PSVECSquareMag(&local_48);
      dVar4 = (double)fVar5;
      if ((double)d_shop::_4457 < dVar4) {
        dVar3 = 1.0 / SQRT(dVar4);
        dVar3 = d_shop::_4458 * dVar3 * (d_shop::_4459 - dVar4 * dVar3 * dVar3);
        dVar3 = d_shop::_4458 * dVar3 * (d_shop::_4459 - dVar4 * dVar3 * dVar3);
        dVar4 = (double)(float)(dVar4 * d_shop::_4458 * dVar3 *
                                        (d_shop::_4459 - dVar4 * dVar3 * dVar3));
      }
      SComponent::cLib_addCalcPos2
                (pcVar2,&local_24,d_shop::_4460,(float)((double)d_shop::_4462 * dVar4));
    }
    *(short *)(iVar1 + 2) = *(short *)(iVar1 + 2) + 0x400;
  }
  return 1;
}


/* __thiscall ShopItems_c::Item_Wait(int) */

bool __thiscall ShopItems_c::Item_Wait(ShopItems_c *this,int param_1)

{
  fopAc_ac_c *this_00;
  int iVar1;
  cXyz *pcVar2;
  int local_18;
  cXyz local_14;
  
  local_18 = this->mItemActorProcessIds[param_1];
  this_00 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_18);
  if (this_00 != (fopAc_ac_c *)0x0) {
    iVar1 = daShopItem_c::getRotateP((daShopItem_c *)this_00);
    SComponent::cLib_addCalcAngleS((short *)(iVar1 + 2),(this_00->mOrig).mRot.y,4,0x800,0x80);
    pcVar2 = (cXyz *)daShopItem_c::getPosP((daShopItem_c *)this_00);
    local_14.x = (this_00->mOrig).mPos.x;
    local_14.y = (this_00->mOrig).mPos.y;
    local_14.z = (this_00->mOrig).mPos.z;
    SComponent::cLib_addCalcPos2(pcVar2,&local_14,d_shop::_4460,d_shop::_4188);
  }
  return this_00 != (fopAc_ac_c *)0x0;
}


/* __thiscall ShopItems_c::Item_ZoomUp(cXyz &) */

undefined4 __thiscall ShopItems_c::Item_ZoomUp(ShopItems_c *this,cXyz *param_1)

{
  this->field_0x3c = 1;
  (this->field_0x30).x = param_1->x;
  (this->field_0x30).y = param_1->y;
  (this->field_0x30).z = param_1->z;
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall ShopItems_c::Item_Move(void) */

undefined4 __thiscall ShopItems_c::Item_Move(ShopItems_c *this)

{
  daItemBase_c *this_00;
  int offset;
  int iVar1;
  undefined4 local_18 [3];
  
  offset = 0;
  for (iVar1 = 0; iVar1 < this->mNumItems; iVar1 = iVar1 + 1) {
    if (iVar1 == this->mSelectedItemIdx) {
      if (*(int *)((int)this->mItemActorProcessIds + offset) != -1) {
        Item_Select(this,iVar1);
      }
    }
    else {
      if (*(int *)((int)this->mItemActorProcessIds + offset) != -1) {
        Item_Wait(this,iVar1);
      }
    }
    if (*(char *)((int)this->mItemActorProcessIds + (short)iVar1 + 0x24) == '\x01') {
      local_18[0] = *(undefined4 *)((int)this->mItemActorProcessIds + offset);
      this_00 = (daItemBase_c *)
                f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,local_18);
      if (this_00 != (daItemBase_c *)0x0) {
        daItemBase_c::hide(this_00);
      }
    }
    offset = offset + 4;
  }
  this->field_0x3c = 0;
  return 1;
}


/* __thiscall ShopItems_c::getSelectItemPos(void) */

void __thiscall ShopItems_c::getSelectItemPos(ShopItems_c *this)

{
  fopAc_ac_c *this_00;
  cXyz *this_01;
  short *in_r4;
  undefined4 local_18;
  cXyz cStack20;
  
  if (*in_r4 < 0) {
    *(float *)this = ::cXyz::Zero.x;
    this->mItemActorProcessIds[0] = (int)::cXyz::Zero.y;
    this->mItemActorProcessIds[1] = (int)::cXyz::Zero.z;
  }
  else {
    local_18 = *(undefined4 *)(in_r4 + *in_r4 * 2 + 2);
    this_00 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_18);
    if (this_00 == (fopAc_ac_c *)0x0) {
      *(float *)this = ::cXyz::Zero.x;
      this->mItemActorProcessIds[0] = (int)::cXyz::Zero.y;
      this->mItemActorProcessIds[1] = (int)::cXyz::Zero.z;
    }
    else {
      daShopItem_c::getCenter((daShopItem_c *)&cStack20);
      this_01 = (cXyz *)daShopItem_c::getPosP((daShopItem_c *)this_00);
      ::cXyz::operator__((cXyz *)this,this_01,&cStack20);
    }
  }
  return;
}


/* __thiscall ShopItems_c::getSelectItemBasePos(void) */

void __thiscall ShopItems_c::getSelectItemBasePos(ShopItems_c *this)

{
  fopAc_ac_c *pfVar1;
  short *in_r4;
  undefined4 local_18;
  cXyz cStack20;
  
  if (*in_r4 < 0) {
    *(float *)this = ::cXyz::Zero.x;
    this->mItemActorProcessIds[0] = (int)::cXyz::Zero.y;
    this->mItemActorProcessIds[1] = (int)::cXyz::Zero.z;
  }
  else {
    local_18 = *(undefined4 *)(in_r4 + *in_r4 * 2 + 2);
    pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_18);
    if (pfVar1 == (fopAc_ac_c *)0x0) {
      *(float *)this = ::cXyz::Zero.x;
      this->mItemActorProcessIds[0] = (int)::cXyz::Zero.y;
      this->mItemActorProcessIds[1] = (int)::cXyz::Zero.z;
    }
    else {
      daShopItem_c::getCenter((daShopItem_c *)&cStack20);
      ::cXyz::operator__((cXyz *)this,&(pfVar1->mOrig).mPos,&cStack20);
    }
  }
  return;
}


/* __thiscall ShopItems_c::hideSelectItem(void) */

void __thiscall ShopItems_c::hideSelectItem(ShopItems_c *this)

{
  daItemBase_c *this_00;
  int local_18 [5];
  
  if (-1 < this->mSelectedItemIdx) {
    local_18[0] = this->mItemActorProcessIds[this->mSelectedItemIdx];
    this_00 = (daItemBase_c *)
              f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,local_18);
    if (this_00 != (daItemBase_c *)0x0) {
      daItemBase_c::hide(this_00);
    }
    this->field_0x3e = 1;
  }
  return;
}


/* __thiscall ShopItems_c::SoldOutItem(int) */

void __thiscall ShopItems_c::SoldOutItem(ShopItems_c *this,int param_1)

{
  daItemBase_c *this_00;
  int local_18 [4];
  
  local_18[0] = this->mItemActorProcessIds[param_1];
  this_00 = (daItemBase_c *)f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,local_18)
  ;
  if (this_00 != (daItemBase_c *)0x0) {
    daItemBase_c::hide(this_00);
  }
  *(undefined *)((int)this->mItemActorProcessIds + param_1 + 0x24) = 1;
  return;
}


/* __thiscall ShopItems_c::getItemNo(int) */

uint __thiscall ShopItems_c::getItemNo(ShopItems_c *this,int param_1)

{
  return this->mpItemSetList[param_1]->mpItemData->mItemNo & 0xff;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall ShopItems_c::showItem(void) */

void __thiscall ShopItems_c::showItem(ShopItems_c *this)

{
  short sVar1;
  daItemBase_c *this_00;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_28 [4];
  
  iVar3 = 0;
  iVar4 = 0;
  while( true ) {
    if (this->mNumItems <= iVar3) break;
    local_28[0] = *(undefined4 *)((int)this->mItemActorProcessIds + iVar4);
    this_00 = (daItemBase_c *)
              f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,local_28);
    if ((this_00 != (daItemBase_c *)0x0) &&
       (*(char *)((int)this->mItemActorProcessIds + iVar3 + 0x24) != '\x01')) {
      daItemBase_c::show(this_00);
      (this_00->parent).mCurrent.mPos.x = (this_00->parent).mOrig.mPos.x;
      (this_00->parent).mCurrent.mPos.y = (this_00->parent).mOrig.mPos.y;
      (this_00->parent).mCurrent.mPos.z = (this_00->parent).mOrig.mPos.z;
      sVar1 = (this_00->parent).mOrig.mRot.y;
      iVar2 = daShopItem_c::getRotateP((daShopItem_c *)this_00);
      *(short *)(iVar2 + 2) = sVar1;
    }
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 4;
  }
  this->field_0x3e = 0;
  return;
}


/* __thiscall ShopItems_c::getSelectItemNo(void) */

uint __thiscall ShopItems_c::getSelectItemNo(ShopItems_c *this)

{
  return this->mpItemSetList[this->mSelectedItemIdx]->mpItemData->mItemNo & 0xff;
}


/* __thiscall ShopItems_c::getSelectItemShowMsg(void) */

ulong __thiscall ShopItems_c::getSelectItemShowMsg(ShopItems_c *this)

{
  return this->mpItemSetList[this->mSelectedItemIdx]->mSelectedMsgID;
}


/* __thiscall ShopItems_c::getSelectItemBuyMsg(void) */

ulong __thiscall ShopItems_c::getSelectItemBuyMsg(ShopItems_c *this)

{
  return this->mpItemSetList[this->mSelectedItemIdx]->mConfirmationMsgID;
}


namespace d_shop {

/* __stdcall dShop_get_next_select(int,
                                   ShopItems_c *) */

int dShop_get_next_select(int param_1,short *param_2)

{
  short *psVar1;
  int iVar2;
  
  iVar2 = (int)*param_2;
  do {
    psVar1 = (short *)((&select_list_data_tbl)[param_2[0x21]] + ((short)iVar2 + 1) * 8);
    if (param_1 == 0) {
      iVar2 = (int)*psVar1;
    }
    else {
      if (param_1 == 1) {
        iVar2 = (int)psVar1[1];
      }
    }
    if (param_1 == 2) {
      iVar2 = (int)psVar1[2];
    }
    else {
      if (param_1 == 3) {
        iVar2 = (int)psVar1[3];
      }
    }
  } while (((int)(short)iVar2 != (int)*param_2) && (*(int *)(param_2 + (short)iVar2 * 2 + 2) == -1))
  ;
  return iVar2;
}

}

/* __thiscall ShopItems_c::setItemSetDataList(void) */

void __thiscall ShopItems_c::setItemSetDataList(ShopItems_c *this)

{
  this->mpItemSetList =
       (__shop_items_set_data **)d_shop::Item_set_data_tbl[this->mItemSetListGlobalIdx];
  return;
}


/* __thiscall ShopItems_c::setItemSetDataList(__shop_items_set_data * *) */

void __thiscall
ShopItems_c::setItemSetDataList(ShopItems_c *this,__shop_items_set_data **itemSetList)

{
  this->mpItemSetList = itemSetList;
  return;
}


/* __thiscall ShopItems_c::isSoldOutItemAll(void) */

undefined4 __thiscall ShopItems_c::isSoldOutItemAll(ShopItems_c *this)

{
  short sVar1;
  
  sVar1 = 0;
  while( true ) {
    if (this->mNumItems <= sVar1) {
      return 1;
    }
    if (*(char *)((int)this->mItemActorProcessIds + sVar1 + 0x24) != '\x01') break;
    sVar1 = sVar1 + 1;
  }
  return 0;
}


namespace d_shop {

/* WARNING: Inlined function: FUN_80328f10 */
/* WARNING: Inlined function: FUN_80328f5c */
/* __stdcall dShop_now_triggercheck(msg_class *,
                                    STControl *,
                                    ShopItems_c *,
                                    unsigned long *,
                                    unsigned long *(void *),
                                    void *) */

int dShop_now_triggercheck
              (msg_class *param_1,STControl *param_2,short *param_3,undefined4 *param_4,
              code *param_5,undefined4 param_6)

{
  short sVar1;
  short sVar2;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  char cVar8;
  undefined4 uVar3;
  int iVar9;
  int iVar10;
  short unaff_r22;
  int iVar11;
  
  sVar1 = *param_3;
  iVar11 = *(int *)(param_3 + 0x12);
  sVar2 = param_3[0x21];
  iVar10 = 0;
  STControl::checkTrigger(param_2);
  sVar4 = dShop_get_next_select(0,param_3);
  sVar5 = dShop_get_next_select(1,param_3);
  sVar6 = dShop_get_next_select(2,param_3);
  sVar7 = dShop_get_next_select(3,param_3);
  if ((sVar1 == sVar4) || (cVar8 = STControl::checkLeftTrigger(param_2), cVar8 == '\0')) {
    if ((sVar1 != sVar5) && (cVar8 = STControl::checkRightTrigger(param_2), cVar8 != '\0')) {
      iVar10 = 1;
      unaff_r22 = sVar5;
    }
  }
  else {
    iVar10 = 1;
    unaff_r22 = sVar4;
  }
  if ((sVar1 == sVar6) || (cVar8 = STControl::checkUpTrigger(param_2), cVar8 == '\0')) {
    if ((sVar1 != sVar7) && (cVar8 = STControl::checkDownTrigger(param_2), cVar8 != '\0')) {
      iVar10 = 1;
      unaff_r22 = sVar7;
    }
  }
  else {
    iVar10 = 1;
    unaff_r22 = sVar6;
  }
  if (iVar10 != 0) {
    if (unaff_r22 < 0) {
      if (param_5 == (code *)0x0) {
        *param_4 = *(undefined4 *)(&default_select_msg + sVar2 * 4);
      }
      else {
        uVar3 = (*param_5)(param_6);
        *param_4 = uVar3;
      }
    }
    else {
      iVar9 = (int)unaff_r22;
      if (*(char *)((int)param_3 + iVar9 + 0x28) == '\x01') {
        *param_4 = *(undefined4 *)(*(int *)(iVar11 + iVar9 * 4) + 0xc);
      }
      else {
        *param_4 = *(undefined4 *)(*(int *)(iVar11 + iVar9 * 4) + 4);
      }
    }
    param_1->mMode = 0xf;
    f_op_msg_mng::fopMsgM_messageSet(*param_4);
    f_op_msg_mng::fopMsgM_messageSendOn();
    *param_3 = unaff_r22;
  }
  return iVar10;
}


/* WARNING: Removing unreachable block (ram,0x800603b8) */
/* WARNING: Removing unreachable block (ram,0x800603d0) */
/* __stdcall dShop_maxCheck(int,
                            int) */

undefined4 dShop_maxCheck(int param_1)

{
  char cVar1;
  
  if ((param_1 == 0x82) || (param_1 == 0x83)) {
    cVar1 = dSv_player_bag_item_c::checkBaitItemEmpty
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem);
    if (cVar1 == '\0') {
      return 1;
    }
  }
  else {
    if ((param_1 < 0x10) || (0x12 < param_1)) {
      if ((10 < param_1) &&
         ((param_1 < 0xf &&
          (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ ==
           d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2)))) {
        return 1;
      }
    }
    else {
      if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ ==
          d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1) {
        return 1;
      }
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall dShop_BoughtErrorStatus(ShopItems_c *,
                                     int,
                                     int) */

uint dShop_BoughtErrorStatus(short *param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  bool bVar4;
  int iVar3;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  
  puVar7 = (undefined4 *)**(int **)(*(int *)(param_1 + 0x12) + *param_1 * 4);
  bVar1 = *(byte *)(puVar7 + 3);
  uVar9 = *puVar7;
  uVar8 = 0;
  if ((bVar1 & 1) != 0) {
    if (puVar7[2] == 0x27) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot == InvalidItem) {
        uVar8 = 1;
      }
    }
    else {
      bVar4 = d_com_inf_game::dComIfGs_checkGetItem((dItem_data__ItemNo)puVar7[2]);
      if (bVar4 == false) {
        uVar8 = 1;
      }
    }
  }
  if ((bVar1 & 2) != 0) {
    bVar4 = d_com_inf_game::dComIfGs_checkGetItem((dItem_data__ItemNo)puVar7[1]);
    if (bVar4 != false) {
      uVar8 = uVar8 | 2;
    }
  }
  if ((bVar1 & 8) != 0) {
    cVar5 = '\0';
    iVar6 = 0;
    iVar10 = 4;
    do {
      iVar3 = iVar6 + 0xe;
      if (iVar3 < 0x15) {
        bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[2].
                mStageName[iVar6 + 2];
      }
      else {
        if (iVar3 < 0x18) {
          bVar2 = 0xff;
        }
        else {
          if (iVar3 < 0x20) {
            bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem)[1].mBits
                    [iVar6 + 6];
          }
          else {
            if (iVar3 < 0x24) {
              bVar2 = 0xff;
            }
            else {
              if (iVar3 < 0x2c) {
                bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem)[1].
                        mBits[iVar6 + 2];
              }
              else {
                if (iVar3 < 0x30) {
                  bVar2 = 0xff;
                }
                else {
                  if (iVar3 < 0x38) {
                    bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [iVar6 + 0x13];
                  }
                  else {
                    bVar2 = 0xff;
                  }
                }
              }
            }
          }
        }
      }
      if (bVar2 != 0xff) {
        cVar5 = cVar5 + '\x01';
      }
      iVar6 = iVar6 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    if (cVar5 == '\0') {
      uVar8 = uVar8 | 8;
    }
  }
  if ((bVar1 & 0x10) != 0) {
    cVar5 = dSv_player_item_c::checkEmptyBottle
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem);
    if (cVar5 == '\0') {
      uVar8 = uVar8 | 0x10;
    }
  }
  if ((bVar1 & 4) != 0) {
    iVar6 = dShop_maxCheck(uVar9,0);
    if (iVar6 != 0) {
      uVar8 = uVar8 | 4;
    }
  }
  if ((bVar1 & 0x20) != 0) {
    if (param_3 == -1) {
      param_3 = 0;
    }
    if ((int)(uint)(ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                           mCurrRupees < param_3) {
      uVar8 = uVar8 | 0x20;
    }
    else {
      if ((param_2 == 1) && (uVar8 == 0)) {
        d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees - param_3;
      }
    }
  }
  if ((param_2 == 1) && (uVar8 == 0)) {
    d_item::execItemGet((dItem_data__ItemNo)uVar9);
  }
  return uVar8;
}

}

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x80060810) */
/* __thiscall ShopCursor_c::ShopCursor_c(J3DModelData *,
                                         J3DAnmTevRegKey *,
                                         float) */

void __thiscall
ShopCursor_c::ShopCursor_c
          (ShopCursor_c *this,J3DModelData *param_1,J3DAnmTevRegKey *param_2,float param_3)

{
  float fVar1;
  short *psVar2;
  J3DModel *pJVar3;
  int iVar4;
  ushort uVar6;
  int iVar5;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar8 = (double)param_3;
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  (this->mBrkAnm).parent.vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
  (this->mBrkAnm).parent.mpFrameCtrl = (J3DFrameCtrl *)0x0;
  (this->mBrkAnm).parent.vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_brkAnm::__vt;
  (this->mBrkAnm).mpCRegAnm = (J3DTevColorAnm *)0x0;
  (this->mBrkAnm).mpKRegAnm = (J3DTevKColorAnm *)0x0;
  for (uVar6 = 0; uVar6 < (param_1->mMaterialTable).mMaterialCount; uVar6 = uVar6 + 1) {
    psVar2 = (short *)(**(code **)((param_1->mMaterialTable).mpMaterials[uVar6]->mpPEBlock->vtbl +
                                  0x50))();
    *psVar2 = (ushort)bRam803f61c1 * 2 +
              (ushort)d_shop::ZModeInfo_4898 * 0x10 + (ushort)bRam803f61c2;
  }
  iVar4 = 0;
  iVar5 = 0;
  do {
    pJVar3 = m_Do_ext::mDoExt_J3DModel__create(param_1,0,0x11020203);
    *(J3DModel **)((int)this->mpModels + iVar5) = pJVar3;
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 4);
  this->mpBrkData = param_2;
  iVar4 = ::mDoExt_brkAnm::init
                    (&this->mBrkAnm,param_1,this->mpBrkData,true,Repeat,d_shop::_4931,0,-1,false,0);
  if (iVar4 == 0) {
    this->mpBrkData = (J3DAnmTevRegKey *)0x0;
  }
  this->field_0x38 = d_shop::_4932;
  this->field_0x3c = d_shop::_4933;
  this->field_0x40 = this->field_0x38;
  this->field_0x44 = 0xf;
  this->field_0x48 = (float)dVar8;
  fVar1 = d_shop::_4931;
  this->field_0x4c = d_shop::_4931;
  this->field_0x50 = fVar1;
  this->field_0x54 = 0;
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* __thiscall mDoExt_brkAnm::~mDoExt_brkAnm(void) */

void __thiscall mDoExt_brkAnm::_mDoExt_brkAnm(mDoExt_brkAnm *this)

{
  short in_r4;
  
  if (this != (mDoExt_brkAnm *)0x0) {
    (this->parent).vtbl = (mDoExt_baseAnm__vtbl *)&__vt;
    if (this != (mDoExt_brkAnm *)0x0) {
      (this->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall mDoExt_baseAnm::~mDoExt_baseAnm(void) */

void __thiscall mDoExt_baseAnm::_mDoExt_baseAnm(mDoExt_baseAnm *this)

{
  short in_r4;
  
  if ((this != (mDoExt_baseAnm *)0x0) && (this->vtbl = (mDoExt_baseAnm__vtbl *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall ShopCursor_c::anm_play(void) */

void __thiscall ShopCursor_c::anm_play(ShopCursor_c *this)

{
  short sVar1;
  float fVar2;
  
  ::mDoExt_baseAnm::play(&(this->mBrkAnm).parent);
  sVar1 = this->field_0x44;
  this->field_0x44 = sVar1 + -1;
  if (sVar1 < 1) {
    fVar2 = SComponent::cM_rndF(d_shop::_4189);
    this->field_0x44 = (short)(int)fVar2 + 0xf;
    if (this->field_0x40 <= d_shop::_4460 * (this->field_0x38 + this->field_0x3c)) {
      this->field_0x40 = this->field_0x38;
    }
    else {
      this->field_0x40 = this->field_0x3c;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x80060b04) */
/* WARNING: Removing unreachable block (ram,0x80060b0c) */
/* __thiscall ShopCursor_c::draw(void) */

void __thiscall ShopCursor_c::draw(ShopCursor_c *this)

{
  float fVar1;
  camera_class *pcVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pcVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  sVar3 = SComponent::cLib_targetAngleY
                    (&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mCenterPos
                     ,&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos);
  sVar4 = SComponent::cLib_targetAngleX(&pcVar2->mCenterPos,&pcVar2->mEyePos);
  if (this->field_0x54 != 0) {
    if (this->field_0x40 <= d_shop::_4460 * (this->field_0x38 + this->field_0x3c)) {
      fVar1 = this->field_0x50;
    }
    else {
      fVar1 = this->field_0x4c;
    }
    dVar9 = (double)fVar1;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffXlu;
    iVar5 = 0;
    iVar7 = 0;
    iVar6 = 0;
    dVar10 = (double)d_shop::_5013;
    do {
      mtx::PSMTXTrans((double)(this->mPos).x,(double)(this->mPos).y,(double)(this->mPos).z,
                      &mDoMtx_stack_c::now);
      m_Do_mtx::mDoMtx_XYZrotM(&mDoMtx_stack_c::now,(int)-sVar4,(int)sVar3,0);
      m_Do_mtx::mDoMtx_ZrotM(&mDoMtx_stack_c::now,*(short *)(&d_shop::angle_z_4961 + iVar6));
      mDoMtx_stack_c::transM(d_shop::_4457,(float)(dVar10 * (double)this->field_0x40),d_shop::_4457)
      ;
      fVar1 = this->field_0x48;
      mDoMtx_stack_c::scaleM(fVar1,(float)((double)fVar1 * dVar9),fVar1);
      mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)((int)this->mpModels + iVar7) + 0x24));
      iVar5 = iVar5 + 1;
      iVar7 = iVar7 + 4;
      iVar6 = iVar6 + 2;
    } while (iVar5 < 4);
    ::mDoExt_brkAnm::entry
              (&this->mBrkAnm,this->mpModels[0]->mpModelData,
               ((this->mBrkAnm).parent.mpFrameCtrl)->mCurrentTime);
    m_Do_ext::mDoExt_modelUpdateDL(this->mpModels[0]);
    m_Do_ext::mDoExt_modelUpdateDL(this->mpModels[1]);
    m_Do_ext::mDoExt_modelUpdateDL(this->mpModels[2]);
    m_Do_ext::mDoExt_modelUpdateDL(this->mpModels[3]);
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  return;
}


/* __thiscall ShopCursor_c::setPos(cXyz &) */

void __thiscall ShopCursor_c::setPos(ShopCursor_c *this,cXyz *pos)

{
  (this->mPos).x = pos->x;
  (this->mPos).y = pos->y;
  (this->mPos).z = pos->z;
  return;
}


namespace d_shop {

/* __stdcall ShopCursor_create(J3DModelData *,
                               J3DAnmTevRegKey *,
                               float) */

ShopCursor_c *
ShopCursor_create(J3DModelData *param_1,J3DAnmTevRegKey *brkData,float param_3)

{
  ShopCursor_c *this;
  int iVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = (double)param_3;
  this = (ShopCursor_c *)JKernel::operator_new(0x58);
  if (this != (ShopCursor_c *)0x0) {
    ::ShopCursor_c::ShopCursor_c(this,param_1,brkData,(float)dVar3);
  }
  iVar1 = 0;
  iVar2 = 4;
  do {
    if (*(int *)((int)this->mpModels + iVar1) == 0) {
      this = (ShopCursor_c *)0x0;
    }
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (this->mpBrkData == (J3DAnmTevRegKey *)0x0) {
    this = (ShopCursor_c *)0x0;
  }
  return this;
}

