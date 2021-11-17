#include <d_a_item.h>
#include <m_Do_mtx.h>
#include <mtx/mtxvec.h>
#include <d_a_item.h>
#include <d_item.h>
#include <mtx/vec.h>
#include <mtx/mtx.h>
#include <d_bg_s_acch.h>
#include <d_cc_d.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <d_a_itembase_static.h>
#include <d_item_data.h>
#include <d_particle.h>
#include <d_save.h>
#include <d_a_itembase.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <f_op_actor.h>
#include <d_com_inf_game.h>
#include <f_op_actor_mng.h>
#include <d_a_item_static.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <d_event_manager.h>
#include <SComponent/c_lib.h>
#include <SComponent/c_cc_s.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_kankyo.h>
#include <SComponent/c_xyz.h>
#include <d_detect.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <SComponent/c_math.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_a_sea.h>
#include <cXyz.h>
#include <daItem_c.h>
#include <daItemBase_c.h>
#include <daPy_py_c.h>


namespace d_a_item {
undefined1 init$4613;
}

/* __thiscall daItemBase_c::getData(void) */

daItemBase_c_m_data * __thiscall daItemBase_c::getData(daItemBase_c *this)

{
  return &m_data;
}


namespace d_a_item {

/* __stdcall setArrowTrans(short,
                           cXyz) */

cXyz * setArrowTrans(cXyz *__return_storage_ptr__,short param_1,cXyz *param_2)

{
  MTX34 *pMVar1;
  undefined2 in_register_00000010;
  cXyz local_18;
  
  local_18.x = param_2->x;
  local_18.y = param_2->y;
  local_18.z = param_2->z;
  m_Do_mtx::mDoMtx_YrotS(&mDoMtx_stack_c::now,CONCAT22(in_register_00000010,param_1));
  pMVar1 = &mDoMtx_stack_c::now;
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_18,&local_18);
  __return_storage_ptr__->x = local_18.x;
  __return_storage_ptr__->y = local_18.y;
  __return_storage_ptr__->z = local_18.z;
  return (cXyz *)pMVar1;
}

}

/* __thiscall daItem_c::getYOffset(void) */

double __thiscall daItem_c::getYOffset(daItem_c *this)

{
  switch((this->parent).mItemNo) {
  case Heart:
    return (double)d_a_item::0_0;
  case GreenRupee:
  case BlueRupee:
  case YellowRupee:
  case RedRupee:
  case PurpleRupee:
  case OrangeRupee:
  case SilverRupee:
    return (double)d_a_item::0_0;
  case PieceOfHeart:
  case HeartContainer:
    return (double)d_a_item::0_0;
  default:
    return (double)d_a_item::0_0;
  case SmallKey:
  case BigKey:
    return (double)d_a_item::0_0;
  case HerosSword:
    return (double)d_a_item::_4158;
  case HerosShield:
    return (double)d_a_item::_4157;
  case RecoveredHerosSword:
    return (double)d_a_item::10_0;
  case SkullNecklace:
    return (double)d_a_item::0_0;
  case BokoBabaSeed:
    return (double)d_a_item::0_0;
  case GoldenFeather:
    return (double)d_a_item::0_0;
  case KnightsCrest:
    return (double)d_a_item::0_0;
  case RedChuJelly:
  case GreenChuJelly:
  case BlueChuJelly:
    return (double)d_a_item::0_0;
  }
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall daItem_c::set_mtx(void) */

void __thiscall daItem_c::set_mtx(daItem_c *this)

{
  bool bVar1;
  csXyz local_88;
  csXyz local_80;
  csXyz local_78;
  uint local_70;
  cXyz local_68;
  cXyz local_5c;
  cXyz local_50;
  cXyz local_44;
  cXyz local_38;
  cXyz local_2c;
  float local_20;
  float local_1c;
  float local_18;
  cXyz local_14;
  
  local_38.x = (this->parent).parent.mCurrent.mPos.x;
  local_38.y = (this->parent).parent.mCurrent.mPos.y;
  local_38.z = (this->parent).parent.mCurrent.mPos.z;
  local_70 = *(uint *)&(this->parent).parent.mCurrent.mRot;
  local_88.z = (this->parent).parent.mCurrent.mRot.z;
  if ((this->parent).mItemNo == HeartContainer) {
    local_70 = local_70 & 0xffff0000 | (uint)(ushort)(this->parent).parent.mCollisionRot.y;
  }
  local_78._0_4_ = local_70;
  local_78.z = local_88.z;
  local_14.x = local_38.x;
  local_14.y = local_38.y;
  local_14.z = local_38.z;
  set_mtx_base(this,(this->parent).mpModel,&local_38,&local_78);
  bVar1 = d_item::isArrow((this->parent).mItemNo);
  if (bVar1 != false) {
    local_20 = d_a_item::5_0;
    local_1c = d_a_item::0_0;
    local_18 = d_a_item::10_0;
    local_44.x = d_a_item::5_0;
    local_44.y = d_a_item::0_0;
    local_44.z = d_a_item::10_0;
    d_a_item::setArrowTrans(&local_50,(this->parent).parent.mCurrent.mRot.y,&local_44);
    local_2c.x = local_50.x;
    local_2c.y = local_50.y;
    local_2c.z = local_50.z;
    mtx::PSVECAdd(&local_14,&local_2c,&local_14);
    local_5c.x = local_14.x;
    local_5c.y = local_14.y;
    local_5c.z = local_14.z;
    local_80._0_4_ = local_70;
    local_80.z = local_88.z;
    set_mtx_base(this,(this->parent).mpModelArrow[0],&local_5c,&local_80);
    mtx::PSVECAdd(&local_14,&local_2c,&local_14);
    local_68.x = local_14.x;
    local_68.y = local_14.y;
    local_68.z = local_14.z;
    local_88._0_4_ = local_70;
    set_mtx_base(this,(this->parent).mpModelArrow[1],&local_68,&local_88);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800f4fbc) */
/* __thiscall daItem_c::set_mtx_base(J3DModel *,
                                     cXyz,
                                     csXyz) */

void __thiscall
daItem_c::set_mtx_base(daItem_c *this,J3DModel *param_1,cXyz *param_2,csXyz *param_3)

{
  int iVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 != (J3DModel *)0x0) {
    (param_1->mBaseScale).x = (this->parent).parent.mScale.x;
    (param_1->mBaseScale).y = (this->parent).parent.mScale.y;
    (param_1->mBaseScale).z = (this->parent).parent.mScale.z;
    dVar4 = (double)param_2->z;
    dVar3 = (double)getYOffset(this);
    mtx::PSMTXTrans((double)param_2->x,(double)(float)((double)param_2->y + dVar3),dVar4,
                    &mDoMtx_stack_c::now);
    iVar1 = d_item::isRupee((this->parent).mItemNo);
    if (iVar1 != 0) {
      mDoMtx_stack_c::transM
                (d_a_item::0_0,
                 (float)((double)CONCAT44(0x43300000,
                                          (uint)dItem_data::item_info[(this->parent).mItemNo].
                                                mCollisionH) - d_a_item::_4258) * d_a_item::0_5,
                 d_a_item::0_0);
    }
    m_Do_mtx::mDoMtx_ZXYrotM
              (&mDoMtx_stack_c::now,(int)param_3->x,(int)param_3->y,
               (int)(short)(param_3->z + this->field_0x65e));
    iVar1 = d_item::isRupee((this->parent).mItemNo);
    if (iVar1 != 0) {
      mDoMtx_stack_c::transM
                (d_a_item::0_0,
                 (float)((double)CONCAT44(0x43300000,
                                          -(uint)dItem_data::item_info[(this->parent).mItemNo].
                                                 mCollisionH ^ 0x80000000) - d_a_item::_4259) *
                 d_a_item::0_5,d_a_item::0_0);
    }
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,&param_1->mBaseMtx);
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


namespace d_a_item {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall itemGetCallBack(fopAc_ac_c *,
                             dCcD_GObjInf *,
                             fopAc_ac_c *,
                             dCcD_GObjInf *) */

void itemGetCallBack
               (daItem_c *param_1,dCcD_GObjInf *param_2,daPy_lk_c *param_3,dCcD_GObjInf *param_4)

{
  daPy_lk_c *pdVar1;
  int iVar2;
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
  if ((((param_1 != (daItem_c *)0x0) && (iVar2 = ::daItem_c::checkPlayerGet(param_1), iVar2 != 0))
      && (param_3 != (daPy_lk_c *)0x0)) && (param_3 == pdVar1)) {
    ::daItem_c::itemGetExecute(param_1);
  }
  return;
}

}

/* WARNING: Removing unreachable block (ram,0x800f53cc) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall daItem_c::CreateInit(void) */

void __thiscall daItem_c::CreateInit(daItem_c *this)

{
  dItem_data__ItemNo dVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  daItemBase_c_m_data *local_r3_304;
  daItemBase_c_m_data *local_r3_320;
  dItem_data *this_00;
  ushort userID;
  bool bVar7;
  fopAc_ac_c *pfVar5;
  JPABaseEmitter *pJVar6;
  uchar extraout_r4;
  uchar uVar8;
  undefined4 uVar9;
  double dVar10;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  undefined2 local_38 [4];
  undefined4 local_30;
  uint uStack44;
  undefined4 local_28;
  uint uStack36;
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::dBgS_AcchCir::SetWall(&(this->parent).mAcchCir,d_a_item::_4367,d_a_item::_4367);
  dBgS_Acch::Set(&(this->parent).mAcch,&(this->parent).parent.mCurrent.mPos,
                 &(this->parent).parent.mNext.mPos,(fopAc_ac_c *)this,1,&(this->parent).mAcchCir,
                 &(this->parent).parent.mVelocity,(csXyz *)0x0,(csXyz *)0x0);
  (this->parent).mAcch.mFlags = (this->parent).mAcch.mFlags & 0xfffffbff;
  (this->parent).mAcch.mFlags = (this->parent).mAcch.mFlags & 0xfffffff7;
  (this->parent).parent.mpCullMtx = &((this->parent).mpModel)->mBaseMtx;
  ::dCcD_Stts::Init(&(this->parent).mStts,0,0xff,(fopAc_ac_c *)this);
  ::dCcD_Cyl::Set(&(this->parent).mCyl,&m_cyl_src);
  (this->parent).mCyl.parent.parent.parent.mpStts = &(this->parent).mStts;
  (this->parent).mCyl.parent.mObjCo.parent.mpCallback = d_a_item::itemGetCallBack;
  uVar4 = (uint)(this->parent).mItemNo;
  uStack44 = (uint)dItem_data::item_info[uVar4].mCollisionH;
  local_30 = 0x43300000;
  dVar12 = (double)(float)((double)CONCAT44(0x43300000,uStack44) - d_a_item::_4258);
  uStack36 = (uint)dItem_data::item_info[uVar4].mCollisionR;
  local_28 = 0x43300000;
  dVar10 = (double)(float)((double)CONCAT44(0x43300000,uStack36) - d_a_item::_4258);
  dVar11 = (double)(this->parent).parent.mScale.x;
  if ((double)d_a_item::1_0 < dVar11) {
    dVar12 = (double)(float)(dVar12 * dVar11);
    dVar10 = (double)(float)(dVar10 * dVar11);
  }
  ::cM3dGCyl::SetR(&(this->parent).mCyl.mCylAttr.mCyl,(float)dVar10);
  ::cM3dGCyl::SetH(&(this->parent).mCyl.mCylAttr.mCyl,(float)dVar12);
  local_r3_304 = daItemBase_c::getData(&this->parent);
  this->mItemTimer = local_r3_304->field_0x16;
  local_r3_320 = daItemBase_c::getData(&this->parent);
  this->field_0x65a = local_r3_320->field_0x18;
  this->field_0x650 = (this->parent).parent.mVelocity.y;
  this->mCurAction = 0;
  this->mUnknownParam = (byte)((uint)(this->parent).parent.parent.parent.mParameters >> 0x18) & 3;
  uVar4 = (uint)(this->parent).parent.parent.parent.mParameters >> 0x18 & 3;
  if ((uVar4 == 3) || (uVar4 == 1)) {
    this->mStatusFlags = this->mStatusFlags | 2;
  }
  this->mItemAction = (byte)((uint)(this->parent).parent.parent.parent.mParameters >> 0x1a);
  daItemBase_c::show(&this->parent);
  uVar8 = extraout_r4;
  uVar4 = dItem_data::checkSpecialEffect((this->parent).mItemNo);
  if ((uVar4 & 0xff) != 0) {
    this_00 = (dItem_data *)(uint)(this->parent).mItemNo;
    if ((this_00 != (dItem_data *)0x15) ||
       ((this_00 == (dItem_data *)0x15 && ((this->mStatusFlags & 2) != 0)))) {
      userID = dItem_data::getSpecialEffect(this_00,uVar8);
      dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,userID,
                         &(this->parent).parent.mCurrent.mPos,(csXyz *)0x0,(cXyz *)0x0,0xff,
                         &(this->mPtclFollowCb).parent,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                         (cXyz *)0x0);
    }
  }
  fVar3 = d_a_item::0_6;
  fVar2 = d_a_item::1_0;
  dVar1 = (this->parent).mItemNo;
  if ((dVar1 < SilverRupee) && (LargeMagicJar < dVar1)) {
    (this->parent).mScaleTarget.x = d_a_item::0_6;
    (this->parent).mScaleTarget.y = fVar3;
    (this->parent).mScaleTarget.z = fVar3;
  }
  else {
    (this->parent).mScaleTarget.x = d_a_item::1_0;
    (this->parent).mScaleTarget.y = fVar2;
    (this->parent).mScaleTarget.z = fVar2;
  }
  this->mSwitchId = (uint)(this->parent).parent.parent.parent.mParameters >> 0x10 & 0xff;
  if ((this->mSwitchId != 0xff) &&
     (bVar7 = dSv_info_c::isSwitch
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,this->mSwitchId,
                         (int)(char)(this->parent).parent.mOrig.mRoomNo), bVar7 == false)) {
    daItemBase_c::hide(&this->parent);
    this->mStatusFlags = this->mStatusFlags | 2;
  }
  this->mActivationSwitch = (int)(this->parent).parent.mOrig.mRot.z & 0xff;
  (this->parent).parent.mCurrent.mRot.z = 0;
  (this->parent).parent.mOrig.mRot.z = 0;
  initAction(this);
  dVar1 = (this->parent).mItemNo;
  if (dVar1 != HerosShield) {
    if (MasterSwordHalfPower < dVar1) {
      if (dVar1 == RecoveredHerosSword) {
        (this->parent).parent.mCurrent.mRot.x = 0x4000;
      }
      goto LAB_800f533c;
    }
    if (dVar1 != HerosSword) goto LAB_800f533c;
  }
  (this->parent).parent.mStatus = (this->parent).parent.mStatus | 0x4000;
LAB_800f533c:
  set_mtx(this);
  daItemBase_c::animPlay
            (&this->parent,d_a_item::1_0,d_a_item::1_0,d_a_item::1_0,d_a_item::1_0,d_a_item::1_0);
  local_38[0] = 0xf2;
  pfVar5 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_38);
  if (pfVar5 != (fopAc_ac_c *)0x0) {
    pJVar6 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x81e1,
                                &(this->parent).parent.mCurrent.mPos,(csXyz *)0x0,(cXyz *)0x0,0xff,
                                (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                                (cXyz *)0x0);
    this->mpParticleEmitter = pJVar6;
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall daItem_c::_daItem_create(void) */

PhaseState __thiscall daItem_c::_daItem_create(daItem_c *this)

{
  PhaseState PVar1;
  int iVar2;
  uint uVar3;
  
  if (((this->parent).parent.mCondition & Constructed) == 0) {
    if (this != (daItem_c *)0x0) {
      fopAc_ac_c::fopAc_ac_c((fopAc_ac_c *)this);
      (this->parent).vtbl = &daItemBase_c::__vt;
      dBgS_Acch::dBgS_Acch(&(this->parent).mAcch);
      (this->parent).mAcch.mChk.vtbl = &::dBgS_ObjAcch::__vt.mChk_vtbl;
      (this->parent).mAcch.mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)0x8037e9e4;
      (this->parent).mAcch.mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)0x8037e9f0;
      (this->parent).mAcch.mDChk.mPolyPassChk.parent.mbObjThrough = 1;
      ::dBgS_AcchCir::dBgS_AcchCir(&(this->parent).mAcchCir);
      (this->parent).mStts.parent.vtbl = &cCcD_Stts::__vt;
      ::dCcD_GStts::dCcD_GStts(&(this->parent).mStts.mGStts);
      (this->parent).mStts.parent.vtbl = &::dCcD_Stts::__vt.parent;
      (this->parent).mStts.mGStts.parent.vtbl = (cCcD_GStts__vtbl *)0x8037ec40;
      dCcD_GObjInf::dCcD_GObjInf(&(this->parent).mCyl.parent);
      (this->parent).mCyl.mCylAttr.parent.vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_ShapeAttr::__vt;
      (this->parent).mCyl.mCylAttr.parent.mAab.vtbl = &::cM3dGAab::__vt;
      (this->parent).mCyl.mCylAttr.mCyl.vtbl = (cCcD_CylAttr__vtbl *)&::cM3dGCyl::__vt;
      (this->parent).mCyl.mCylAttr.parent.vtbl = &::cCcD_CylAttr::__vt;
      (this->parent).mCyl.mCylAttr.mCyl.vtbl = &cCcD_CylAttr__vtbl_803951ac;
      (this->parent).mCyl.parent.parent.parent.parent.vtbl = &::dCcD_Cyl::__vt.parent;
      (this->parent).mCyl.mCylAttr.parent.vtbl = &::dCcD_Cyl::__vt.mCyl_vtbl;
      (this->parent).mCyl.mCylAttr.mCyl.vtbl = &::dCcD_Cyl::__vt.mCylAttr_vtbl;
      (this->parent).vtbl = &__vt;
      (this->mPtclRippleCb).parent.vtbl =
           (dPa_levelEcallBack__vtbl *)&::JPACallBackBase<JPABaseEmitter*>::__vt;
      (this->mPtclRippleCb).parent.vtbl = (dPa_levelEcallBack__vtbl *)&::dPa_levelEcallBack::__vt;
      (this->mPtclRippleCb).parent.vtbl = (dPa_levelEcallBack__vtbl *)&dPa_rippleEcallBack::__vt;
      (this->mPtclRippleCb).mpBaseEmitter = (JPABaseEmitter *)0x0;
      dPa_followEcallBack::dPa_followEcallBack(&this->mPtclFollowCb,0,0);
      ::dPa_smokeEcallBack::dPa_smokeEcallBack(&this->mPtclSmokeCb,1);
    }
    (this->parent).parent.mCondition = (this->parent).parent.mCondition | Constructed;
  }
  (this->parent).mItemNo = (dItem_data__ItemNo)(this->parent).parent.parent.parent.mParameters;
  if (dItem_data::field_item_res[(this->parent).mItemNo].mModelArcName == (char *)0x0) {
    daItemBase_c::setLoadError(&this->parent);
    PVar1 = cPhs_ERROR_e;
  }
  else {
    (this->parent).mPickupFlag = (uint)(this->parent).parent.parent.parent.mParameters >> 8 & 0xff;
    if ((this->parent).mItemNo != BlueChuJelly) {
      (this->parent).mPickupFlag = (this->parent).mPickupFlag & 0x7f;
      iVar2 = dSv_info_c::isItem(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,
                                 (this->parent).mPickupFlag,
                                 (int)(char)(this->parent).parent.mOrig.mRoomNo);
      if ((iVar2 != 0) && ((this->parent).mPickupFlag != 0x7f)) {
        daItemBase_c::setLoadError(&this->parent);
        return cPhs_ERROR_e;
      }
    }
    PVar1 = d_com_inf_game::dComIfG_resLoad
                      (&(this->parent).mPhs,
                       dItem_data::field_item_res[(this->parent).mItemNo].mModelArcName);
    if (PVar1 == cPhs_COMPLEATE_e) {
      uVar3 = f_op_actor_mng::fopAcM_entrySolidHeap
                        ((fopAc_ac_c *)this,d_a_itembase_static::CheckFieldItemCreateHeap,
                         (uint)(ushort)dItem_data::field_item_res[(this->parent).mItemNo].mHeapSize)
      ;
      if ((uVar3 & 0xff) == 0) {
        PVar1 = cPhs_ERROR_e;
      }
      else {
        CreateInit(this);
      }
    }
  }
  return PVar1;
}


/* __thiscall daItem_c::_daItem_execute(void) */

undefined4 __thiscall daItem_c::_daItem_execute(daItem_c *this)

{
  bool bVar2;
  int iVar1;
  
  if ((this->mSwitchId == 0xff) ||
     (bVar2 = dSv_info_c::isSwitch
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,this->mSwitchId,
                         (int)(char)(this->parent).parent.mOrig.mRoomNo), bVar2 != false)) {
    if ((this->mSwitchId != 0xff) &&
       (bVar2 = dSv_info_c::isSwitch
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,this->mSwitchId,
                           (int)(char)(this->parent).parent.mOrig.mRoomNo), bVar2 != false)) {
      daItemBase_c::show(&this->parent);
    }
    timeCount(this);
    (this->parent).parent.mEyePos.x = (this->parent).parent.mCurrent.mPos.x;
    (this->parent).parent.mEyePos.y = (this->parent).parent.mCurrent.mPos.y;
    (this->parent).parent.mEyePos.z = (this->parent).parent.mCurrent.mPos.z;
    (this->parent).parent.mEyePos.y =
         (this->parent).parent.mEyePos.y +
         (float)((double)CONCAT44(0x43300000,
                                  (uint)dItem_data::item_info[(this->parent).mItemNo].mCollisionH) -
                d_a_item::_4258) * d_a_item::0_5;
    (this->parent).parent.mAttentionPos.x = (this->parent).parent.mCurrent.mPos.x;
    (this->parent).parent.mAttentionPos.y = (this->parent).parent.mCurrent.mPos.y;
    (this->parent).parent.mAttentionPos.z = (this->parent).parent.mCurrent.mPos.z;
    switch(this->mCurAction) {
    case 0:
    case 1:
      iVar1 = checkActionNow(this);
      if (iVar1 == 0) {
        this->mCurAction = 0;
      }
      else {
        this->mCurAction = 1;
      }
    case 2:
      execWaitMain(this);
      break;
    case 3:
      execBringNezumi(this);
      break;
    case 5:
      execInitNormalDirection(this);
    case 6:
      execMainNormalDirection(this);
      break;
    case 7:
      execInitGetDemoDirection(this);
      break;
    case 8:
      execWaitGetDemoDirection(this);
      break;
    case 9:
      execMainGetDemoDirection(this);
      break;
    case 10:
    case 0xb:
      execWaitMainFromBoss(this);
    }
    daItemBase_c::animPlay
              (&this->parent,d_a_item::1_0,d_a_item::1_0,d_a_item::1_0,d_a_item::1_0,d_a_item::1_0);
    set_mtx(this);
  }
  return 1;
}


/* __thiscall daItem_c::mode_proc_call(void) */

void __thiscall daItem_c::mode_proc_call(daItem_c *this)

{
  fopAc_ac_c *pfVar1;
  undefined **in_r4;
  undefined2 local_18;
  short local_16;
  
  if (d_a_item::init_4613 == '\0') {
    d_a_item::mode_proc_4609[0] = d_a_item::_4610;
    d_a_item::mode_proc_4609[1] = DAT_8038ca28;
    d_a_item::mode_proc_4609[2] = PTR_mode_wait_8038ca2c;
    in_r4 = d_a_item::mode_proc_4609;
    d_a_item::mode_proc_4609[3] = d_a_item::_4611;
    d_a_item::mode_proc_4609[4] = DAT_8038ca34;
    d_a_item::mode_proc_4609[5] = PTR_mode_wait_8038ca38;
    d_a_item::mode_proc_4609[6] = d_a_item::_4612;
    d_a_item::mode_proc_4609[7] = DAT_8038ca40;
    d_a_item::mode_proc_4609[8] = PTR_mode_water_8038ca44;
    d_a_item::init_4613 = '\x01';
  }
  if (this->mUnknownParam == 1) {
    itemDefaultRotateY(this);
  }
  else {
    Runtime.PPCEABI.H::__ptmf_scall
              ((PTMF *)(d_a_item::mode_proc_4609 + (uint)this->mMode * 3),this,in_r4);
  }
  if ((this->mStatusFlags & 8) != 0) {
                    /* Boomerang */
    local_16 = 0x1b4;
    pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_16);
    if (pfVar1 == (fopAc_ac_c *)0x0) {
      this->mStatusFlags = this->mStatusFlags & 0xf7;
    }
    else {
      (this->parent).parent.mCurrent.mPos.x = (pfVar1->mCurrent).mPos.x;
      (this->parent).parent.mCurrent.mPos.y = (pfVar1->mCurrent).mPos.y;
      (this->parent).parent.mCurrent.mPos.z = (pfVar1->mCurrent).mPos.z;
    }
  }
  if ((this->mStatusFlags & 0x40) != 0) {
    local_18 = 0x1c4;
    pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_18);
    if (pfVar1 == (fopAc_ac_c *)0x0) {
      this->mStatusFlags = this->mStatusFlags & 0xbf;
    }
    else {
      (this->parent).parent.mCurrent.mPos.x = (pfVar1->mCurrent).mPos.x;
      (this->parent).parent.mCurrent.mPos.y = (pfVar1->mCurrent).mPos.y;
      (this->parent).parent.mCurrent.mPos.z = (pfVar1->mCurrent).mPos.z;
    }
  }
  if (this->mUnknownParam == 1) {
    if ((((this->parent).parent.mStatus & 0x100000) != 0) || ((this->mStatusFlags & 8) != 0)) {
      this->mUnknownParam = 3;
    }
  }
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall daItem_c::execInitNormalDirection(void) */

void __thiscall daItem_c::execInitNormalDirection(daItem_c *this)

{
  float fVar1;
  float fVar2;
  daItemBase_c_m_data *pdVar3;
  JPABaseEmitter *pJVar4;
  cXyz local_28;
  float local_1c;
  float local_18;
  float local_14;
  
  ::daPy_py_c::getHeadTopPos
            (&local_28,&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent);
  local_1c = local_28.x;
  local_14 = local_28.z;
  local_18 = local_28.y + d_a_item::_4696;
  (this->parent).parent.mCurrent.mPos.x = local_28.x;
  (this->parent).parent.mCurrent.mPos.y = local_18;
  (this->parent).parent.mCurrent.mPos.z = local_28.z;
  (this->parent).parent.mCurrent.mRot.z = 0;
  (this->parent).parent.mCurrent.mRot.x = 0;
  fVar1 = (this->parent).mScaleTarget.z;
  fVar2 = (this->parent).mScaleTarget.y;
  (this->parent).parent.mScale.x = (this->parent).mScaleTarget.x;
  (this->parent).parent.mScale.y = fVar2;
  (this->parent).parent.mScale.z = fVar1;
  this->field_0x65e = 0;
  pdVar3 = daItemBase_c::getData(&this->parent);
  *(undefined2 *)&this->field_0x65c = *(undefined2 *)&pdVar3->field_0x40;
  pdVar3 = daItemBase_c::getData(&this->parent);
  fVar2 = d_a_item::0_0;
  fVar1 = *(float *)&pdVar3->field_0x38;
  (this->parent).parent.mVelocity.x = d_a_item::0_0;
  (this->parent).parent.mVelocity.y = fVar1;
  (this->parent).parent.mVelocity.z = fVar2;
  pdVar3 = daItemBase_c::getData(&this->parent);
  (this->parent).parent.mAccelerationY = *(float *)&pdVar3->field_0x3c;
  daItemBase_c::show(&this->parent);
  *(cCcD_Obj__DamageTypes *)((int)&(this->parent).mCyl.parent.parent.parent.parent.mObjTg + 0x10) =
       0;
  (this->parent).mCyl.parent.parent.parent.parent.mObjCo.parent.mCommonFlag =
       (this->parent).mCyl.parent.parent.parent.parent.mObjCo.parent.mCommonFlag & ~EnableCheck;
  (*(code *)((this->mPtclSmokeCb).parent.parent.vtbl)->end)(&this->mPtclSmokeCb);
  pJVar4 = this->mpParticleEmitter;
  if (pJVar4 != (JPABaseEmitter *)0x0) {
    pJVar4->mMaxFrame = -1;
    pJVar4->mFlags = pJVar4->mFlags | 1;
    this->mpParticleEmitter = (JPABaseEmitter *)0x0;
  }
  this->mCurAction = 6;
  return;
}


/* __thiscall daItem_c::execMainNormalDirection(void) */

void __thiscall daItem_c::execMainNormalDirection(daItem_c *this)

{
  camera_class *pcVar1;
  cXyz local_28;
  float local_1c;
  float local_18;
  float local_14;
  
  ::daPy_py_c::getHeadTopPos
            (&local_28,&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent);
  local_1c = local_28.x;
  local_14 = local_28.z;
  local_18 = local_28.y + d_a_item::_4696;
  (this->parent).parent.mCurrent.mPos.x = local_28.x;
  (this->parent).parent.mCurrent.mPos.z = local_28.z;
  f_op_actor_mng::fopAcM_posMoveF((fopAc_ac_c *)this,(cXyz *)0x0);
  if ((this->parent).parent.mCurrent.mPos.y < local_18) {
    (this->parent).parent.mCurrent.mPos.y = local_18;
  }
  pcVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  (this->parent).parent.mCurrent.mRot.x =
       (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->field_0x230;
  (this->parent).parent.mCurrent.mRot.y = pcVar1->field_0x232;
  (this->parent).parent.mCurrent.mRot.z = *(short *)&pcVar1->field_0x234;
  *(short *)&this->field_0x65c = *(short *)&this->field_0x65c + -1;
  if (*(short *)&this->field_0x65c < 0) {
    f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daItem_c::execInitGetDemoDirection(void) */

void __thiscall daItem_c::execInitGetDemoDirection(daItem_c *this)

{
  daPy_lk_c *pdVar1;
  daPy_lk_c *pdVar2;
  undefined4 uVar3;
  
  pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  daItemBase_c::hide(&this->parent);
  (*(code *)((this->mPtclFollowCb).parent.vtbl)->end)(&this->mPtclFollowCb);
  if (pdVar1 == pdVar2) {
    f_op_actor_mng::fopAcM_orderItemEvent(this);
    (this->parent).parent.mEvtInfo.mCondition =
         (this->parent).parent.mEvtInfo.mCondition | CanGetItem;
    uVar3 = f_op_actor_mng::fopAcM_createItemForTrBoxDemo
                      (&(this->parent).parent.mCurrent,(this->parent).mItemNo,0xffffffff,
                       (int)(char)(this->parent).parent.mCurrent.mRoomNo,0,0);
    *(undefined4 *)&this->field_0x670 = uVar3;
    this->mCurAction = 8;
  }
  return;
}


/* __thiscall daItem_c::execWaitGetDemoDirection(void) */

void __thiscall daItem_c::execWaitGetDemoDirection(daItem_c *this)

{
  daItemBase_c::hide(&this->parent);
  if ((this->parent).parent.mEvtInfo.mCommand == InGetItem) {
    this->mCurAction = 9;
    if (*(int *)&this->field_0x670 != -1) {
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPtItem = *(int *)&this->field_0x670;
    }
  }
  else {
    f_op_actor_mng::fopAcM_orderItemEvent(this);
    (this->parent).parent.mEvtInfo.mCondition =
         (this->parent).parent.mEvtInfo.mCondition | CanGetItem;
  }
  return;
}


/* __thiscall daItem_c::execMainGetDemoDirection(void) */

void __thiscall daItem_c::execMainGetDemoDirection(daItem_c *this)

{
  bool bVar1;
  
  daItemBase_c::hide(&this->parent);
  bVar1 = dEvent_manager_c::endCheckOld
                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"DEFAULT_GETITEM");
  if (bVar1 != false) {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags | 8;
    f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  }
  return;
}


/* __thiscall daItem_c::execBringNezumi(void) */

void __thiscall daItem_c::execBringNezumi(daItem_c *this)

{
  if (this->mUnknownParam != 1) {
    f_op_actor_mng::fopAcM_posMoveF((fopAc_ac_c *)this,(cXyz *)&(this->parent).mStts);
  }
  mode_proc_call(this);
  return;
}


/* WARNING: Removing unreachable block (ram,0x800f5f1c) */
/* WARNING: Removing unreachable block (ram,0x800f5f14) */
/* WARNING: Removing unreachable block (ram,0x800f5f24) */
/* __thiscall daItem_c::execWaitMain(void) */

void __thiscall daItem_c::execWaitMain(daItem_c *this)

{
  daItemBase_c_m_data *pdVar1;
  int iVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined8 in_f29;
  double dVar5;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  checkGetItem(this);
  if (this->mUnknownParam != 1) {
    f_op_actor_mng::fopAcM_posMoveF((fopAc_ac_c *)this,(cXyz *)&(this->parent).mStts);
  }
  mode_proc_call(this);
  if ((this->mStatusFlags & 2) == 0) {
    pdVar1 = daItemBase_c::getData(&this->parent);
    dVar7 = (double)((this->parent).mScaleTarget.x / pdVar1->mScaleAnimSpeed);
    pdVar1 = daItemBase_c::getData(&this->parent);
    dVar6 = (double)((this->parent).mScaleTarget.y / pdVar1->mScaleAnimSpeed);
    pdVar1 = daItemBase_c::getData(&this->parent);
    dVar5 = (double)((this->parent).mScaleTarget.z / pdVar1->mScaleAnimSpeed);
    SComponent::cLib_chaseF
              (&(this->parent).parent.mScale.x,(this->parent).mScaleTarget.x,(float)dVar7);
    SComponent::cLib_chaseF
              (&(this->parent).parent.mScale.y,(this->parent).mScaleTarget.y,(float)dVar6);
    SComponent::cLib_chaseF
              (&(this->parent).parent.mScale.z,(this->parent).mScaleTarget.z,(float)dVar5);
  }
  iVar2 = checkItemDisappear(this);
  if ((iVar2 != 0) && (this->mItemTimer == 0)) {
    if (this->field_0x65a == 0) {
      f_op_actor_mng::fopAcM_delete((base_process_class *)this);
    }
    pdVar1 = daItemBase_c::getData(&this->parent);
    iVar2 = (this->parent).field_0x634;
    if (iVar2 == (iVar2 / (int)pdVar1->field_0x14) * (int)pdVar1->field_0x14) {
      daItemBase_c::changeDraw(&this->parent);
    }
  }
  if ((dItem_data::item_info[(this->parent).mItemNo].mSpecialBehaviors & IsAlwaysDeactivated) == 0)
  {
    iVar2 = this->mActivationSwitch;
    if ((iVar2 == 0xff) ||
       ((iVar2 != 0xff &&
        (bVar3 = dSv_info_c::isSwitch
                           (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,iVar2,
                            (int)(char)(this->parent).parent.mOrig.mRoomNo), bVar3 != false)))) {
      ::cM3dGCyl::SetC(&(this->parent).mCyl.mCylAttr.mCyl,&(this->parent).parent.mCurrent.mPos);
      cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,
                (cCcD_Obj *)&(this->parent).mCyl);
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  return;
}


/* __thiscall daItem_c::execWaitMainFromBoss(void) */

void __thiscall daItem_c::execWaitMainFromBoss(daItem_c *this)

{
  checkGetItem(this);
  if (this->mUnknownParam != 1) {
    f_op_actor_mng::fopAcM_posMoveF((fopAc_ac_c *)this,(cXyz *)&(this->parent).mStts);
  }
  mode_proc_call(this);
  if (this->mCurAction != 0xb) {
    scaleAnimFromBossItem(this);
  }
  ::cM3dGCyl::SetC(&(this->parent).mCyl.mCylAttr.mCyl,&(this->parent).parent.mCurrent.mPos);
  cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)&(this->parent).mCyl);
  return;
}


/* __thiscall daItem_c::scaleAnimFromBossItem(void) */

void __thiscall daItem_c::scaleAnimFromBossItem(daItem_c *this)

{
  short sVar1;
  float fVar2;
  sbyte sVar3;
  uint uVar4;
  
  sVar1 = (this->parent).field_0x638;
  if (sVar1 < 0x1e) {
    uVar4 = (this->parent).field_0x634;
    (this->parent).parent.mScale.x =
         d_a_item::1_0 +
         (d_a_item::2_0 *
         JKernel::JMath::jmaSinTable
         [(int)(uVar4 * 0x2000 - 0x4000 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]) /
         (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - d_a_item::_4259);
    if ((this->parent).parent.mScale.x < d_a_item::0_0) {
      (this->parent).parent.mScale.x = d_a_item::0_0;
    }
    (this->parent).parent.mScale.y = (this->parent).parent.mScale.x;
    (this->parent).parent.mScale.z = (this->parent).parent.mScale.x;
  }
  else {
    if (sVar1 == 0x1e) {
      sVar3 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).parent.mCurrent.mRoomNo);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x583d,&(this->parent).parent.mEyePos,0,sVar3,d_a_item::1_0,
                 d_a_item::1_0,d_a_item::_4836,d_a_item::_4836,0);
    }
    fVar2 = d_a_item::1_0;
    (this->parent).parent.mScale.x = d_a_item::1_0;
    (this->parent).parent.mScale.y = fVar2;
    (this->parent).parent.mScale.z = fVar2;
  }
  return;
}


/* __thiscall daItem_c::_daItem_draw(void) */

undefined4 __thiscall daItem_c::_daItem_draw(daItem_c *this)

{
  char cVar2;
  undefined4 uVar1;
  
  cVar2 = daItemBase_c::chkDraw(&this->parent);
  if (cVar2 == '\0') {
    uVar1 = 1;
  }
  else {
    uVar1 = (*(code *)((this->parent).vtbl)->DrawBase)(this);
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall daItem_c::setTevStr(void) */

void __thiscall daItem_c::setTevStr(daItem_c *this)

{
  J3DModel *pJVar1;
  int iVar2;
  int iVar3;
  
  dScnKy_env_light_c::settingTevStruct
            (&d_kankyo::g_env_light,Actor,&(this->parent).parent.mCurrent.mPos,
             &(this->parent).parent.mTevStr);
  (this->parent).parent.mTevStr.mColorC0.r = 0x96;
  (this->parent).parent.mTevStr.mColorC0.g = 0x96;
  (this->parent).parent.mTevStr.mColorC0.b = 0x96;
  (this->parent).parent.mTevStr.mColorK0.r = 0xff;
  (this->parent).parent.mTevStr.mColorK0.g = 0xff;
  (this->parent).parent.mTevStr.mColorK0.b = 0xff;
  dScnKy_env_light_c::setLightTevColorType
            (&d_kankyo::g_env_light,(this->parent).mpModel,&(this->parent).parent.mTevStr);
  iVar2 = 0;
  iVar3 = 0;
  do {
    pJVar1 = *(J3DModel **)((int)(this->parent).mpModelArrow + iVar3);
    if (pJVar1 != (J3DModel *)0x0) {
      dScnKy_env_light_c::setLightTevColorType
                (&d_kankyo::g_env_light,pJVar1,&(this->parent).parent.mTevStr);
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar2 < 2);
  return;
}


/* __thiscall daItem_c::_daItem_delete(void) */

undefined4 __thiscall daItem_c::_daItem_delete(daItem_c *this)

{
  JPABaseEmitter *pJVar1;
  
  dPa_rippleEcallBack::end(&this->mPtclRippleCb);
  (*(code *)((this->mPtclFollowCb).parent.vtbl)->end)(&this->mPtclFollowCb);
  (*(code *)((this->mPtclSmokeCb).parent.parent.vtbl)->end)(&this->mPtclSmokeCb);
  pJVar1 = this->mpParticleEmitter;
  if (pJVar1 != (JPABaseEmitter *)0x0) {
    pJVar1->mMaxFrame = -1;
    pJVar1->mFlags = pJVar1->mFlags | 1;
    this->mpParticleEmitter = (JPABaseEmitter *)0x0;
  }
  daItemBase_c::DeleteBase
            (&this->parent,dItem_data::field_item_res[(this->parent).mItemNo].mModelArcName);
  return 1;
}


namespace d_a_item {

/* WARNING: Removing unreachable block (ram,0x800f640c) */
/* WARNING: Removing unreachable block (ram,0x800f6414) */
/* __stdcall Reflect(cXyz &,
                     cXyz *,
                     float,
                     float) */

uint Reflect(cXyz *param_1,cXyz *param_2,float param_3,float param_4)

{
  bool bVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  float fVar6;
  cXyz local_94;
  cXyz cStack136;
  cXyz local_7c;
  cXyz local_70;
  cXyz local_64;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar4 = (double)param_4;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  fVar6 = mtx::PSVECSquareMag(param_2);
  dVar5 = (double)fVar6;
  if ((double)0_0 < dVar5) {
    dVar3 = 1.0 / SQRT(dVar5);
    dVar3 = _4937 * dVar3 * (_4938 - dVar5 * dVar3 * dVar3);
    dVar3 = _4937 * dVar3 * (_4938 - dVar5 * dVar3 * dVar3);
    dVar5 = (double)(float)(dVar5 * _4937 * dVar3 * (_4938 - dVar5 * dVar3 * dVar3));
  }
  ::cXyz::normalize(&local_64);
  local_4c.x = local_64.x;
  local_4c.y = local_64.y;
  local_4c.z = local_64.z;
  ::cXyz::normalize(&local_70);
  local_58.x = local_70.x;
  local_58.y = local_70.y;
  local_58.z = local_70.z;
  ::cXyz::operator_(&local_7c,&local_4c,_4836);
  local_4c.x = local_7c.x;
  local_4c.y = local_7c.y;
  local_4c.z = local_7c.z;
  dVar3 = (double)mtx::PSVECDotProduct(&local_58,&local_4c);
  bVar1 = 0_0 <= (float)((double)2_0 * dVar3);
  ::cXyz::operator_(&cStack136,&local_58,(float)((double)2_0 * dVar3));
  ::cXyz::operator__(&local_94,&cStack136,&local_4c);
  local_40.x = local_94.x;
  local_40.y = local_94.y;
  local_40.z = local_94.z;
  mtx::PSVECScale(&local_40,&local_40,(float)dVar5);
  param_2->x = (float)((double)local_40.x * dVar4);
  param_2->y = local_40.y;
  param_2->z = (float)((double)local_40.z * dVar4);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  return (uint)bVar1;
}

}

/* WARNING: Type propagation algorithm not settling */
/* __thiscall daItem_c::itemGetExecute(void) */

void __thiscall daItem_c::itemGetExecute(daItem_c *this)

{
  daItem_c *pdVar1;
  int iVar2;
  undefined2 local_18;
  undefined2 local_16 [7];
  
  if (this->mCurAction != 5) {
    this->mCurAction = 5;
    switch((this->parent).mItemNo) {
    case Heart:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x821,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      d_item::execItemGet((this->parent).mItemNo);
      break;
    case GreenRupee:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x826,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      d_item::execItemGet((this->parent).mItemNo);
      break;
    case BlueRupee:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x835,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      d_item::execItemGet((this->parent).mItemNo);
      break;
    case YellowRupee:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x835,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      d_item::execItemGet((this->parent).mItemNo);
      break;
    case RedRupee:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x836,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      d_item::execItemGet((this->parent).mItemNo);
      break;
    case PurpleRupee:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x836,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      d_item::execItemGet((this->parent).mItemNo);
      break;
    case OrangeRupee:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x836,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      d_item::execItemGet((this->parent).mItemNo);
      break;
    case PieceOfHeart:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x821,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      this->mCurAction = 7;
      break;
    case HeartContainer:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x821,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      this->mCurAction = 7;
      break;
    case SmallMagicJar:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x879,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      d_item::execItemGet((this->parent).mItemNo);
      break;
    case LargeMagicJar:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x87a,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      d_item::execItemGet((this->parent).mItemNo);
      break;
    case FiveBombs:
    case TenBombs:
    case TwentyBombs:
    case ThirtyBombs:
    case TenArrows:
    case TwentyArrows:
    case ThirtyArrows:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x827,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      d_item::execItemGet((this->parent).mItemNo);
      break;
    case SilverRupee:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x836,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      d_item::execItemGet((this->parent).mItemNo);
      break;
    case SmallKey:
      this->mCurAction = 7;
      break;
    case triple_heart:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x821,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      d_item::execItemGet((this->parent).mItemNo);
      break;
    case JoyPendant:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x87b,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      iVar2 = dSv_player_get_bag_item_c::isBeast
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,7);
      if (iVar2 == 0) {
        this->mCurAction = 7;
        dSv_player_get_bag_item_c::onBeast
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,7);
      }
      else {
        d_item::execItemGet((this->parent).mItemNo);
      }
      break;
    case DekuLeaf:
      this->mCurAction = 7;
      break;
    case HerosSword:
      local_16[0] = 0x101;
      pdVar1 = (daItem_c *)
               f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_16);
      if ((pdVar1 != (daItem_c *)0x0) && ((pdVar1->parent).mItemNo == HerosShield)) {
        itemGetExecute(pdVar1);
      }
      this->mCurAction = 7;
      break;
    case HerosShield:
      local_18 = 0x101;
      pdVar1 = (daItem_c *)
               f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_18);
      if ((pdVar1 != (daItem_c *)0x0) && ((pdVar1->parent).mItemNo == HerosSword)) {
        itemGetExecute(pdVar1);
      }
      this->mCurAction = 7;
      break;
    case RecoveredHerosSword:
      this->mCurAction = 7;
      break;
    case SkullNecklace:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x87b,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      iVar2 = dSv_player_get_bag_item_c::isBeast
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,0);
      if (iVar2 == 0) {
        this->mCurAction = 7;
        dSv_player_get_bag_item_c::onBeast
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,0);
      }
      else {
        d_item::execItemGet((this->parent).mItemNo);
      }
      break;
    case BokoBabaSeed:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x87b,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      iVar2 = dSv_player_get_bag_item_c::isBeast
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,1);
      if (iVar2 == 0) {
        this->mCurAction = 7;
        dSv_player_get_bag_item_c::onBeast
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,1);
      }
      else {
        d_item::execItemGet((this->parent).mItemNo);
      }
      break;
    case GoldenFeather:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x87b,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      iVar2 = dSv_player_get_bag_item_c::isBeast
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,2);
      if (iVar2 == 0) {
        this->mCurAction = 7;
        dSv_player_get_bag_item_c::onBeast
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,2);
      }
      else {
        d_item::execItemGet((this->parent).mItemNo);
      }
      break;
    case KnightsCrest:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x87b,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      iVar2 = dSv_player_get_bag_item_c::isBeast
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,3);
      if (iVar2 == 0) {
        this->mCurAction = 7;
        dSv_player_get_bag_item_c::onBeast
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,3);
      }
      else {
        d_item::execItemGet((this->parent).mItemNo);
      }
      break;
    case RedChuJelly:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x87b,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      iVar2 = dSv_player_get_bag_item_c::isBeast
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,4);
      if (iVar2 == 0) {
        this->mCurAction = 7;
        dSv_player_get_bag_item_c::onBeast
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,4);
      }
      else {
        d_item::execItemGet((this->parent).mItemNo);
      }
      break;
    case GreenChuJelly:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x87b,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      iVar2 = dSv_player_get_bag_item_c::isBeast
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,5);
      if (iVar2 == 0) {
        this->mCurAction = 7;
        dSv_player_get_bag_item_c::onBeast
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,5);
      }
      else {
        d_item::execItemGet((this->parent).mItemNo);
      }
      break;
    case BlueChuJelly:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x87b,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      iVar2 = dSv_player_get_bag_item_c::isBeast
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,6);
      if (iVar2 == 0) {
        this->mCurAction = 7;
        dSv_player_get_bag_item_c::onBeast
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,6);
      }
      else {
        d_item::execItemGet((this->parent).mItemNo);
      }
      break;
    case AllPurposeBait:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8ec,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      iVar2 = dSv_player_get_bag_item_c::isBait
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,0);
      if (iVar2 == 0) {
        this->mCurAction = 7;
        dSv_player_get_bag_item_c::onBait
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,0);
      }
      else {
        d_item::execItemGet((this->parent).mItemNo);
      }
      break;
    case HyoiPear:
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8ec,(cXyz *)0x0,0,0,d_a_item::1_0,d_a_item::1_0,
                 d_a_item::_4836,d_a_item::_4836,0);
      iVar2 = dSv_player_get_bag_item_c::isBait
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,1);
      if (iVar2 == 0) {
        this->mCurAction = 7;
        dSv_player_get_bag_item_c::onBait
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,1);
      }
      else {
        d_item::execItemGet((this->parent).mItemNo);
      }
    }
    iVar2 = (this->parent).mPickupFlag;
    if ((this->parent).mItemNo == BlueChuJelly) {
      dSv_memBit_c::onSwitch
                ((dSv_memBit_c *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + 0xe),
                 iVar2);
    }
    else {
      dSv_info_c::onItem(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,iVar2,
                         (int)(char)(this->parent).parent.mCurrent.mRoomNo);
    }
    this->mStatusFlags = this->mStatusFlags & 0xfb;
    *(cCcD_Obj__DamageTypes *)((int)&(this->parent).mCyl.parent.parent.parent.parent.mObjTg + 0x10)
         = 0;
    (this->parent).mCyl.parent.parent.parent.parent.mObjCo.parent.mCommonFlag =
         (this->parent).mCyl.parent.parent.parent.parent.mObjCo.parent.mCommonFlag & ~EnableCheck;
    (*(code *)((this->parent).mCyl.parent.parent.parent.parent.vtbl)->ClrTgHit)
              (&(this->parent).mCyl);
    (*(code *)((this->parent).mCyl.parent.parent.parent.parent.vtbl)->ClrCoHit)
              (&(this->parent).mCyl);
  }
  return;
}


/* __thiscall daItem_c::itemDefaultRotateY(void) */

void __thiscall daItem_c::itemDefaultRotateY(daItem_c *this)

{
  short sVar1;
  daItemBase_c_m_data *pdVar2;
  
  pdVar2 = daItemBase_c::getData(&this->parent);
  sVar1 = (short)(0xffff / (int)pdVar2->mNumFramesPerFullSpin);
  f_op_actor_mng::fopAcM_addAngleY
            ((fopAc_ac_c *)this,(this->parent).parent.mCurrent.mRot.y + sVar1,sVar1);
  return;
}


/* __thiscall daItem_c::checkItemDisappear(void) */

bool __thiscall daItem_c::checkItemDisappear(daItem_c *this)

{
  byte bVar1;
  bool bVar2;
  
  bVar2 = this->mCurAction != 3;
  if (!bVar2) {
    daItemBase_c::show(&this->parent);
  }
  bVar1 = this->mStatusFlags;
  bVar2 = this->mCurAction != 4 &&
          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0 &&
          ((dItem_data::item_info[(this->parent).mItemNo].mSpecialBehaviors & NeverFadeAndDisappear)
           == 0 && ((bVar1 & 0x10) == 0 && ((bVar1 & 2) == 0 && bVar2))));
  if ((((bVar1 & 8) != 0) || ((bVar1 & 0x40) != 0)) ||
     (((this->parent).parent.mStatus & 0x100000) != 0)) {
    bVar2 = false;
    daItemBase_c::show(&this->parent);
  }
  return bVar2;
}


/* __thiscall daItem_c::setItemTimer(int) */

void __thiscall daItem_c::setItemTimer(daItem_c *this,int param_1)

{
  if (param_1 == -1) {
    this->mStatusFlags = this->mStatusFlags | 0x10;
    return;
  }
  this->mItemTimer = (short)param_1;
  return;
}


/* __thiscall daItem_c::checkPlayerGet(void) */

int __thiscall daItem_c::checkPlayerGet(daItem_c *this)

{
  daItemBase_c_m_data *pdVar1;
  int iVar2;
  
  pdVar1 = daItemBase_c::getData(&this->parent);
  if ((this->parent).field_0x638 < pdVar1->field_0x42) {
    iVar2 = 0;
  }
  else {
    iVar2 = -(uint)this->mCurAction + 3;
    iVar2 = iVar2 - ((uint)(iVar2 == 0) + -(uint)this->mCurAction + 2);
  }
  return iVar2;
}


/* __thiscall daItem_c::itemActionForRupee(void) */

undefined4 __thiscall daItem_c::itemActionForRupee(daItem_c *this)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  daItemBase_c_m_data *pdVar4;
  
  dBgS_Acch::CrrPos(&(this->parent).mAcch,&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  checkWall(this);
  uVar3 = (this->parent).mAcch.mFlags;
  if ((uVar3 & 0x80) == 0) {
    if ((uVar3 & 0x20) != 0) {
      itemDefaultRotateY(this);
      (this->parent).parent.mVelocityFwd = d_a_item::0_0;
      this->mStatusFlags = this->mStatusFlags & 0xfb;
      this->field_0x66c = 1;
    }
  }
  else {
    pdVar4 = daItemBase_c::getData(&this->parent);
    fVar2 = d_a_item::0_0;
    fVar1 = this->field_0x650 * pdVar4->field_0x4;
    if (fVar1 <= (this->parent).parent.mAccelerationY - d_a_item::0_5) {
      (this->parent).parent.mVelocity.x = d_a_item::0_0;
      (this->parent).parent.mVelocity.y = -fVar1;
      (this->parent).parent.mVelocity.z = fVar2;
    }
    else {
      (this->parent).parent.mVelocityFwd = d_a_item::0_0;
    }
    this->field_0x66c = this->field_0x66c + 1;
    if (1 < this->field_0x66c) {
      this->mStatusFlags = this->mStatusFlags & 0xfb;
    }
    set_bound_se(this);
  }
  fVar1 = (this->parent).parent.mVelocity.y;
  if (d_a_item::0_0 != fVar1) {
    this->field_0x650 = fVar1;
  }
  pdVar4 = daItemBase_c::getData(&this->parent);
  this->field_0x654 = *(undefined2 *)&pdVar4->field_0x1a;
  if (this->field_0x66c == 0) {
    this->field_0x656 = (this->parent).parent.mCurrent.mRot.x + this->field_0x654;
  }
  else {
    this->field_0x656 = 0;
  }
  if ((this->mStatusFlags & 2) == 0) {
    SComponent::cLib_chaseAngleS
              (&(this->parent).parent.mCurrent.mRot,(int)this->field_0x656,
               (int)(short)this->field_0x654);
  }
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x800f7120) */
/* __thiscall daItem_c::itemActionForHeart(void) */

undefined4 __thiscall daItem_c::itemActionForHeart(daItem_c *this)

{
  float fVar1;
  float fVar2;
  daItemBase_c_m_data *pdVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar6 = (double)(this->parent).parent.mVelocity.y;
  if (dVar6 < (double)d_a_item::0_0) {
    (this->parent).parent.mAccelerationY = d_a_item::0_0;
    pdVar3 = daItemBase_c::getData(&this->parent);
    fVar2 = d_a_item::0_0;
    fVar1 = *(float *)&pdVar3->field_0x20;
    (this->parent).parent.mVelocity.x = d_a_item::0_0;
    (this->parent).parent.mVelocity.y = fVar1;
    (this->parent).parent.mVelocity.z = fVar2;
  }
  dBgS_Acch::CrrPos(&(this->parent).mAcch,&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  uVar4 = (this->parent).mAcch.mFlags;
  if (((uVar4 & 0x80) == 0) && ((uVar4 & 0x20) == 0)) {
    if (dVar6 < (double)d_a_item::0_0) {
      pdVar3 = daItemBase_c::getData(&this->parent);
      dVar6 = (double)*(float *)&pdVar3->field_0x24;
      pdVar3 = daItemBase_c::getData(&this->parent);
      (this->parent).parent.mVelocityFwd =
           (float)(dVar6 * (double)JKernel::JMath::jmaSinTable
                                   [(int)((this->parent).field_0x634 *
                                          (int)*(short *)&pdVar3->field_0x28 & 0xffffU) >>
                                    (JKernel::JMath::jmaSinShift & 0x3f)]);
    }
  }
  else {
    this->mStatusFlags = this->mStatusFlags & 0xfb;
    this->field_0x65e = 0;
    fVar1 = d_a_item::0_0;
    (this->parent).parent.mVelocity.x = d_a_item::0_0;
    (this->parent).parent.mVelocity.y = d_a_item::_4836;
    (this->parent).parent.mVelocity.z = fVar1;
    (this->parent).parent.mVelocityFwd = fVar1;
    itemDefaultRotateY(this);
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return 1;
}


/* __thiscall daItem_c::itemActionForKey(void) */

undefined4 __thiscall daItem_c::itemActionForKey(daItem_c *this)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  daItemBase_c_m_data *pdVar4;
  
  dBgS_Acch::CrrPos(&(this->parent).mAcch,&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  checkWall(this);
  uVar3 = (this->parent).mAcch.mFlags;
  if ((uVar3 & 0x80) == 0) {
    if ((uVar3 & 0x20) != 0) {
      this->field_0x66c = 1;
      this->field_0x656 = 0;
      (this->parent).parent.mCurrent.mRot.x = 0;
      this->mStatusFlags = this->mStatusFlags & 0xfb;
      itemDefaultRotateY(this);
    }
  }
  else {
    pdVar4 = daItemBase_c::getData(&this->parent);
    fVar2 = d_a_item::0_0;
    fVar1 = this->field_0x650 * pdVar4->field_0x4;
    if (fVar1 <= (this->parent).parent.mAccelerationY - d_a_item::0_5) {
      (this->parent).parent.mVelocity.x = d_a_item::0_0;
      (this->parent).parent.mVelocity.y = -fVar1;
      (this->parent).parent.mVelocity.z = fVar2;
    }
    else {
      (this->parent).parent.mVelocityFwd = d_a_item::0_0;
      (this->parent).parent.mCurrent.mRot.x = 0x4000;
      this->field_0x656 = (this->parent).parent.mCurrent.mRot.x;
      this->field_0x654 = 0;
    }
    this->field_0x66c = this->field_0x66c + 1;
    if (1 < this->field_0x66c) {
      this->mStatusFlags = this->mStatusFlags & 0xfb;
    }
  }
  fVar1 = (this->parent).parent.mVelocity.y;
  if (d_a_item::0_0 != fVar1) {
    this->field_0x650 = fVar1;
  }
  pdVar4 = daItemBase_c::getData(&this->parent);
  this->field_0x654 = *(undefined2 *)&pdVar4->field_0x1a;
  if (this->field_0x66c == 0) {
    this->field_0x656 = (this->parent).parent.mCurrent.mRot.x + this->field_0x654;
  }
  else {
    this->field_0x656 = 0;
  }
  SComponent::cLib_chaseAngleS
            (&(this->parent).parent.mCurrent.mRot,(int)this->field_0x656,
             (int)(short)this->field_0x654);
  return 1;
}


/* __thiscall daItem_c::itemActionForEmono(void) */

undefined4 __thiscall daItem_c::itemActionForEmono(daItem_c *this)

{
  float fVar1;
  float fVar2;
  short sVar3;
  uint uVar4;
  daItemBase_c_m_data *pdVar5;
  
  dBgS_Acch::CrrPos(&(this->parent).mAcch,&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  uVar4 = (this->parent).mAcch.mFlags;
  if ((uVar4 & 0x80) == 0) {
    if ((uVar4 & 0x20) != 0) {
      pdVar5 = daItemBase_c::getData(&this->parent);
      uVar4 = 0xffff / (int)pdVar5->mNumFramesPerFullSpin;
      sVar3 = (short)uVar4;
      sVar3 = (sVar3 >> 1) + (ushort)(sVar3 < 0 && (uVar4 & 1) != 0);
      f_op_actor_mng::fopAcM_addAngleY
                ((fopAc_ac_c *)this,(this->parent).parent.mCurrent.mRot.y + sVar3,sVar3);
      (this->parent).parent.mVelocityFwd = d_a_item::0_0;
    }
  }
  else {
    pdVar5 = daItemBase_c::getData(&this->parent);
    fVar2 = d_a_item::0_0;
    fVar1 = this->field_0x650 * pdVar5->field_0x4;
    if (fVar1 <= (this->parent).parent.mAccelerationY - d_a_item::0_5) {
      (this->parent).parent.mVelocity.x = d_a_item::0_0;
      (this->parent).parent.mVelocity.y = -fVar1;
      (this->parent).parent.mVelocity.z = fVar2;
    }
    else {
      (this->parent).parent.mVelocityFwd = d_a_item::0_0;
    }
    set_bound_se(this);
  }
  fVar1 = (this->parent).parent.mVelocity.y;
  if (d_a_item::0_0 != fVar1) {
    this->field_0x650 = fVar1;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* WARNING: Removing unreachable block (ram,0x800f7878) */
/* __thiscall daItem_c::itemActionForSword(void) */

undefined4 __thiscall daItem_c::itemActionForSword(daItem_c *this)

{
  int iVar1;
  dItem_data__ItemNo dVar2;
  float fVar3;
  float fVar4;
  char cVar5;
  sbyte sVar6;
  cBgS_PolyPassChk *pcVar7;
  undefined4 uVar8;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  cXyz local_c8;
  cXyz local_bc;
  cBgS_GndChk local_b0;
  cBgS_PolyPassChk local_70;
  undefined local_64 [12];
  double local_58;
  double local_50;
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dBgS_Acch::CrrPos(&(this->parent).mAcch,&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  cVar5 = dDetect_c::chk_quake
                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDetect,
                     &(this->parent).parent.mCurrent.mPos);
  fVar4 = d_a_item::0_0;
  if (((cVar5 != '\0') && ((this->mStatusFlags & 0x20) == 0)) &&
     (((this->parent).mAcch.mFlags & 0x20) != 0)) {
    (this->parent).parent.mVelocity.x = d_a_item::0_0;
    (this->parent).parent.mVelocity.y = d_a_item::_5519;
    (this->parent).parent.mVelocity.z = fVar4;
    (this->parent).parent.mAccelerationY = d_a_item::_5520;
  }
  fVar4 = d_a_item::0_0;
  if (((this->parent).mAcch.mFlags & 0x80) != 0) {
    fVar3 = d_a_item::_5521 * this->field_0x650;
    (this->parent).parent.mVelocity.x = d_a_item::0_0;
    (this->parent).parent.mVelocity.y = -fVar3;
    (this->parent).parent.mVelocity.z = fVar4;
    dVar2 = (this->parent).mItemNo;
    if (dVar2 == HerosSword) {
      if (0xf < (this->parent).field_0x638) {
        sVar6 = d_com_inf_game::dComIfGp_getReverb
                          ((int)(char)(this->parent).parent.mCurrent.mRoomNo);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x6971,&(this->parent).parent.mEyePos,0,sVar6,
                   d_a_item::1_0,d_a_item::1_0,d_a_item::_4836,d_a_item::_4836,0);
      }
    }
    else {
      if ((dVar2 == HerosShield) && (0xf < (this->parent).field_0x638)) {
        sVar6 = d_com_inf_game::dComIfGp_getReverb
                          ((int)(char)(this->parent).parent.mCurrent.mRoomNo);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x6972,&(this->parent).parent.mEyePos,0,sVar6,
                   d_a_item::1_0,d_a_item::1_0,d_a_item::_4836,d_a_item::_4836,0);
      }
    }
  }
  ::cBgS_GndChk::cBgS_GndChk(&local_b0);
  pcVar7 = &local_70;
  local_70.mbCamThrough = 0;
  local_70.mbLinkThrough = 0;
  local_70.mbArrowsAndLightThrough = 0;
  local_70.mbBombThrough = 0;
  local_70.mbBoomerangThrough = 0;
  local_70.mbHookshotThrough = 0;
  local_64._4_4_ = 1;
  local_b0.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar7;
  if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
    local_b0.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_64;
  }
  local_b0.parent.vtbl = &::dBgS_ObjGndChk::__vt;
  local_b0.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371ed8;
  local_70.vtbl = &cBgS_PolyPassChk__vtbl_80371ee4;
  local_64._0_4_ = &cBgS_GrpPassChk__vtbl_80371ef0;
  local_70.mbObjThrough = 1;
  local_bc.x = d_a_item::0_0;
  local_bc.y = d_a_item::0_0;
  local_bc.z = d_a_item::0_0;
  local_c8.x = d_a_item::0_0;
  local_c8.y = d_a_item::_5522;
  local_c8.z = d_a_item::0_0;
  local_b0.parent.mpPolyPassChk = pcVar7;
  mtx::PSMTXTrans((double)(this->parent).parent.mCurrent.mPos.x,
                  (double)(this->parent).parent.mCurrent.mPos.y,
                  (double)(this->parent).parent.mCurrent.mPos.z,&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_ZXYrotM
            (&mDoMtx_stack_c::now,(int)(this->parent).parent.mCurrent.mRot.x,
             (int)(this->parent).parent.mCurrent.mRot.y,(int)(this->parent).parent.mCurrent.mRot.z);
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_bc,&local_bc);
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_c8,&local_c8);
  local_b0.mPos.x = local_bc.x;
  local_b0.mPos.y = local_bc.y;
  local_b0.mPos.z = local_bc.z;
  dVar9 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_b0);
  dVar10 = (double)(float)(dVar9 - (double)local_bc.y);
  local_b0.mPos.x = local_c8.x;
  local_b0.mPos.y = local_c8.y;
  local_b0.mPos.z = local_c8.z;
  dVar9 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_b0);
  if (*(char *)&this->field_0x666 == '\x01') {
    *(undefined2 *)&this->field_0x660 = 0x2000;
  }
  if (((double)d_a_item::0_0 < dVar10) ||
     ((double)d_a_item::0_0 < (double)(float)(dVar9 - (double)local_c8.y))) {
    if (dVar10 <= (double)d_a_item::0_0) {
      if ((double)d_a_item::0_0 < (double)(float)(dVar9 - (double)local_c8.y)) {
        local_50 = (double)CONCAT44(0x43300000,(int)*(short *)&this->field_0x660 ^ 0x80000000);
        iVar1 = (int)(d_a_item::_5523 * (float)(local_50 - d_a_item::_4259));
        local_58 = (double)(longlong)iVar1;
        *(short *)&this->field_0x660 = (short)iVar1;
      }
    }
    else {
      local_58 = (double)CONCAT44(0x43300000,(int)*(short *)&this->field_0x660 ^ 0x80000000);
      iVar1 = (int)(d_a_item::_5523 * (float)(local_58 - d_a_item::_4259));
      local_50 = (double)(longlong)iVar1;
      *(short *)&this->field_0x660 = (short)iVar1;
    }
    *(char *)&this->field_0x666 = *(char *)&this->field_0x666 + '\x01';
  }
  if (*(short *)&this->field_0x660 == 0) {
    *(undefined *)&this->field_0x666 = 0;
  }
  else {
    SComponent::cLib_addCalcAngleS2
              (&(this->parent).parent.mCurrent.mRot.x,*(short *)&this->field_0x660 + 0x4000,10,0x800
              );
  }
  if (cVar5 == '\0') {
    this->mStatusFlags = this->mStatusFlags & 0xdf;
  }
  else {
    this->mStatusFlags = this->mStatusFlags | 0x20;
  }
  local_70.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_64._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
  if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
    local_70.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_64._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x64) &&
       (local_64._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x64)) {
      local_64._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar7 != (cBgS_PolyPassChk *)0x0) &&
       (local_70.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar7 != (cBgS_PolyPassChk *)0x0)) {
      local_70.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_b0.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_b0.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_b0.parent);
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return 1;
}


/* __thiscall daItem_c::itemActionForArrow(void) */

undefined4 __thiscall daItem_c::itemActionForArrow(daItem_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  fopAc_ac_c *pfVar4;
  JPABaseEmitter *pJVar5;
  uint uVar6;
  daItemBase_c_m_data *pdVar7;
  undefined2 local_18;
  undefined2 local_16 [9];
  
  dBgS_Acch::CrrPos(&(this->parent).mAcch,&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  if ((this->field_0x66c == 0) && (this->mpParticleEmitter != (JPABaseEmitter *)0x0)) {
    local_16[0] = 0xf2;
    pfVar4 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_16);
    if (pfVar4 != (fopAc_ac_c *)0x0) {
      fVar1 = (this->parent).parent.mCurrent.mPos.y;
      fVar2 = (this->parent).parent.mCurrent.mPos.z;
      pJVar5 = this->mpParticleEmitter;
      (pJVar5->mGlobalTranslation).x = (this->parent).parent.mCurrent.mPos.x;
      (pJVar5->mGlobalTranslation).y = fVar1;
      (pJVar5->mGlobalTranslation).z = fVar2;
    }
  }
  uVar6 = (this->parent).mAcch.mFlags;
  if ((uVar6 & 0x80) == 0) {
    if (((uVar6 & 0x20) != 0) &&
       ((this->parent).parent.mVelocityFwd = d_a_item::0_0, (this->parent).mItemNo != HeartContainer
       )) {
      itemDefaultRotateY(this);
    }
  }
  else {
    pdVar7 = daItemBase_c::getData(&this->parent);
    fVar3 = d_a_item::0_5;
    fVar2 = d_a_item::0_0;
    fVar1 = this->field_0x650 * pdVar7->field_0x4;
    if (fVar1 <= (this->parent).parent.mAccelerationY - d_a_item::0_5) {
      (this->parent).parent.mVelocity.x = d_a_item::0_0;
      (this->parent).parent.mVelocity.y = -fVar1;
      (this->parent).parent.mVelocity.z = fVar2;
      (this->parent).parent.mVelocityFwd = (this->parent).parent.mVelocityFwd * fVar3;
    }
    else {
      (this->parent).parent.mVelocityFwd = d_a_item::0_0;
    }
    this->field_0x66c = this->field_0x66c + 1;
    if (this->field_0x66c == 1) {
      local_18 = 0xf2;
      pfVar4 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_18);
      if (pfVar4 != (fopAc_ac_c *)0x0) {
        pJVar5 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0xa1e2,
                                    &(this->parent).parent.mCurrent.mPos,(csXyz *)0x0,(cXyz *)0x0,
                                    0xff,(dPa_levelEcallBack *)&this->mPtclSmokeCb,
                                    (this->parent).parent.mCurrent.mRoomNo,(_GXColor *)0x0,
                                    (_GXColor *)0x0,(cXyz *)0x0);
        if (pJVar5 != (JPABaseEmitter *)0x0) {
          pJVar5->mMaxFrame = 1;
        }
      }
    }
    pJVar5 = this->mpParticleEmitter;
    if (pJVar5 != (JPABaseEmitter *)0x0) {
      pJVar5->mMaxFrame = -1;
      pJVar5->mFlags = pJVar5->mFlags | 1;
      this->mpParticleEmitter = (JPABaseEmitter *)0x0;
    }
    set_bound_se(this);
  }
  if ((this->parent).mItemNo == HeartContainer) {
    if (this->field_0x66c != 0) {
      daItemBase_c::getData(&this->parent);
      pdVar7 = daItemBase_c::getData(&this->parent);
      SComponent::cLib_addCalcAngleS
                (&this->field_0x654,(short)(0xffff / (int)pdVar7->mNumFramesPerFullSpin),10,0x400,
                 0x100);
    }
    SComponent::cLib_chaseAngleS
              (&(this->parent).parent.mCollisionRot.y,
               (int)(short)((this->parent).parent.mCollisionRot.y + this->field_0x654));
  }
  fVar1 = (this->parent).parent.mVelocity.y;
  if (d_a_item::0_0 != fVar1) {
    this->field_0x650 = fVar1;
  }
  return 1;
}


/* __thiscall daItem_c::checkWall(void) */

void __thiscall daItem_c::checkWall(daItem_c *this)

{
  uint uVar1;
  cM3dGPla *pcVar2;
  int iVar3;
  cXyz local_28;
  cXyz local_1c;
  
  if (((this->parent).mAcch.mFlags & 0x10) != 0) {
    pcVar2 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                             (uint)(ushort)(this->parent).mAcchCir.mPolyInfo.mBgIndex,
                             (uint)(ushort)(this->parent).mAcchCir.mPolyInfo.mTriIdx);
    local_1c.x = (pcVar2->mNorm).x;
    local_1c.y = (pcVar2->mNorm).y;
    local_1c.z = (pcVar2->mNorm).z;
    uVar1 = (int)(this->parent).parent.mCurrent.mRot.y & 0xffff;
    local_28.z = (this->parent).parent.mVelocityFwd;
    local_28.x = local_28.z *
                 JKernel::JMath::jmaSinTable[(int)uVar1 >> (JKernel::JMath::jmaSinShift & 0x3f)];
    local_28.y = (this->parent).parent.mVelocity.y;
    local_28.z = local_28.z *
                 JKernel::JMath::jmaCosTable[(int)uVar1 >> (JKernel::JMath::jmaSinShift & 0x3f)];
    if ((SComponent::G_CM3D_F_ABS_MIN <= ABS(local_28.x)) ||
       (SComponent::G_CM3D_F_ABS_MIN <= ABS(local_28.z))) {
      d_a_item::Reflect(&local_1c,&local_28,d_a_item::1_0,d_a_item::1_0);
      if (SComponent::G_CM3D_F_ABS_MIN <= ABS(local_28.x)) {
        iVar3 = SComponent::cM_atan2s(local_28.x,local_28.z);
        (this->parent).parent.mCurrent.mRot.y = (short)iVar3;
      }
    }
  }
  return;
}


/* __thiscall daItem_c::set_bound_se(void) */

void __thiscall daItem_c::set_bound_se(daItem_c *this)

{
  dItem_data__ItemNo dVar1;
  uint uVar2;
  sbyte sVar3;
  
  if (9 < (this->parent).field_0x638) {
    uVar2 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)(d_a_item::2_0 * ABS(this->field_0x650)));
    if (100 < uVar2) {
      uVar2 = 100;
    }
    dVar1 = (this->parent).mItemNo;
    if (dVar1 != SilverRupee) {
      if (dVar1 < SilverRupee) {
        if (dVar1 < SmallMagicJar) {
          if (dVar1 < PieceOfHeart) {
            if (dVar1 != Heart) {
              sVar3 = d_com_inf_game::dComIfGp_getReverb
                                ((int)(char)(this->parent).parent.mCurrent.mRoomNo);
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x6a06,&(this->parent).parent.mEyePos,uVar2,sVar3,
                         d_a_item::1_0,d_a_item::1_0,d_a_item::_4836,d_a_item::_4836,0);
            }
          }
          else {
            sVar3 = d_com_inf_game::dComIfGp_getReverb
                              ((int)(char)(this->parent).parent.mCurrent.mRoomNo);
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x6991,&(this->parent).parent.mEyePos,uVar2,sVar3,
                       d_a_item::1_0,d_a_item::1_0,d_a_item::_4836,d_a_item::_4836,0);
          }
        }
        else {
          if (dVar1 < FiveBombs) {
            sVar3 = d_com_inf_game::dComIfGp_getReverb
                              ((int)(char)(this->parent).parent.mCurrent.mRoomNo);
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x6a07,&(this->parent).parent.mEyePos,uVar2,sVar3,
                       d_a_item::1_0,d_a_item::1_0,d_a_item::_4836,d_a_item::_4836,0);
          }
          else {
            sVar3 = d_com_inf_game::dComIfGp_getReverb
                              ((int)(char)(this->parent).parent.mCurrent.mRoomNo);
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x6989,&(this->parent).parent.mEyePos,uVar2,sVar3,
                       d_a_item::1_0,d_a_item::1_0,d_a_item::_4836,d_a_item::_4836,0);
          }
        }
      }
      else {
        if (dVar1 < FireAndIceArrows) {
          if (ThirtyArrows < dVar1) {
            return;
          }
        }
        else {
          if (LightArrow < dVar1) {
            return;
          }
        }
        sVar3 = d_com_inf_game::dComIfGp_getReverb
                          ((int)(char)(this->parent).parent.mCurrent.mRoomNo);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x6988,&(this->parent).parent.mEyePos,uVar2,sVar3,
                   d_a_item::1_0,d_a_item::1_0,d_a_item::_4836,d_a_item::_4836,0);
      }
    }
  }
  return;
}


/* __thiscall daItem_c::checkGetItem(void) */

undefined4 __thiscall daItem_c::checkGetItem(daItem_c *this)

{
  int iVar1;
  cCcD_Obj *pcVar2;
  cCcD_Obj__DamageTypes cVar3;
  
  iVar1 = checkPlayerGet(this);
  if (((iVar1 != 0) && (iVar1 = dCcD_GObjInf::ChkTgHit(&(this->parent).mCyl.parent), iVar1 != 0)) &&
     (pcVar2 = dCcD_GObjInf::GetTgHitObj(&(this->parent).mCyl.parent), pcVar2 != (cCcD_Obj *)0x0)) {
    cVar3 = (pcVar2->parent).mObjAt.mDamageTypes;
    if ((cVar3 & Sword) != 0) {
      itemGetExecute(this);
      return 1;
    }
    if ((cVar3 & Boomerang) != 0) {
      this->mStatusFlags = this->mStatusFlags | 8;
    }
  }
  return 0;
}


/* __thiscall daItem_c::timeCount(void) */

undefined4 __thiscall daItem_c::timeCount(daItem_c *this)

{
  short sVar1;
  int iVar2;
  
  (this->parent).field_0x634 = (this->parent).field_0x634 + 1;
  sVar1 = (this->parent).field_0x638;
  if (sVar1 < m_timer_max) {
    (this->parent).field_0x638 = sVar1 + 1;
  }
  iVar2 = checkPlayerGet(this);
  if ((iVar2 != 0) && (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0)) {
    if (this->mItemTimer < 1) {
      if (0 < this->field_0x65a) {
        this->field_0x65a = this->field_0x65a + -1;
      }
    }
    else {
      this->mItemTimer = this->mItemTimer + -1;
    }
  }
  return 1;
}


/* __thiscall daItem_c::mode_wait_init(void) */

void __thiscall daItem_c::mode_wait_init(daItem_c *this)

{
  daItemBase_c_m_data *pdVar1;
  
  this->mMode = 0;
  pdVar1 = daItemBase_c::getData(&this->parent);
  (this->parent).parent.mAccelerationY = pdVar1->mFieldItemGravity;
  dPa_rippleEcallBack::end(&this->mPtclRippleCb);
  return;
}


/* __thiscall daItem_c::mode_water_init(void) */

void __thiscall daItem_c::mode_water_init(daItem_c *this)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  double dVar4;
  cXyz local_28;
  undefined4 local_18;
  uint uStack20;
  undefined4 local_10;
  uint uStack12;
  
  this->mMode = 2;
  uVar3 = d_a_sea::daSea_ChkArea
                    ((this->parent).parent.mCurrent.mPos.x,(this->parent).parent.mCurrent.mPos.z);
  if ((uVar3 & 0xff) == 0) {
    if ((((this->parent).mAcch.mFlags & 0x800) == 0) ||
       ((this->parent).mAcch.mWtrChk.parent.mHeight < (this->parent).parent.mCurrent.mPos.y)) {
      mode_wait_init(this);
    }
    (this->parent).parent.mCurrent.mPos.y = (this->parent).mAcch.mWtrChk.parent.mHeight;
  }
  else {
    dVar4 = (double)d_a_sea::daSea_calcWave
                              ((double)(this->parent).parent.mCurrent.mPos.x,
                               (double)(this->parent).parent.mCurrent.mPos.z);
    if ((double)(this->parent).parent.mCurrent.mPos.y < dVar4) {
      (this->parent).parent.mCurrent.mPos.y = (float)dVar4;
    }
  }
  fVar1 = d_a_item::0_0;
  (this->parent).parent.mVelocity.x = d_a_item::0_0;
  (this->parent).parent.mVelocity.y = fVar1;
  (this->parent).parent.mVelocity.z = fVar1;
  (this->parent).parent.mVelocityFwd = fVar1;
  (this->parent).parent.mCurrent.mRot.z = 0;
  (this->parent).parent.mCurrent.mRot.x = 0;
  this->field_0x65e = 0;
  this->field_0x654 = 0;
  this->mStatusFlags = this->mStatusFlags & 0xfb;
  fVar1 = (this->parent).mScaleTarget.z;
  fVar2 = (this->parent).mScaleTarget.y;
  (this->parent).parent.mScale.x = (this->parent).mScaleTarget.x;
  (this->parent).parent.mScale.y = fVar2;
  (this->parent).parent.mScale.z = fVar1;
  uStack20 = (uint)dItem_data::item_info[(this->parent).mItemNo].mMaybeShadowRelated;
  local_18 = 0x43300000;
  uStack12 = (uint)dItem_data::item_info[1].mMaybeShadowRelated;
  local_10 = 0x43300000;
  local_28.x = ((float)((double)CONCAT44(0x43300000,uStack20) - d_a_item::_4258) /
               (float)((double)CONCAT44(0x43300000,uStack12) - d_a_item::_4258)) *
               (this->parent).parent.mScale.x;
  local_28.y = local_28.x;
  local_28.z = local_28.x;
  dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,5,0x33,
                     &(this->parent).parent.mCurrent.mPos,(csXyz *)0x0,&local_28,0xff,
                     &(this->mPtclRippleCb).parent,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  (this->mPtclRippleCb).mRate = d_a_item::0_0;
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* __thiscall daItem_c::mode_wait(void) */

void __thiscall daItem_c::mode_wait(daItem_c *this)

{
  char cVar2;
  uint uVar1;
  uchar in_r4;
  cBgS_PolyPassChk *pcVar3;
  double dVar4;
  cBgS_GndChk local_8c;
  cBgS_PolyPassChk local_4c;
  undefined local_40 [12];
  
  if (((this->mStatusFlags & 4) != 0) &&
     (cVar2 = dItem_data::checkAppearEffect((dItem_data *)(uint)(this->parent).mItemNo,in_r4),
     cVar2 != '\0')) {
    uVar1 = dItem_data::getAppearEffect((this->parent).mItemNo);
    dPa_control_c::setSimple
              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,(ushort)uVar1,
               &(this->parent).parent.mCurrent.mPos,0xff,&d_com_inf_game::g_whiteColor,
               &d_com_inf_game::g_whiteColor,0);
  }
  switch((this->parent).mItemNo) {
  case Heart:
  case triple_heart:
    itemActionForHeart(this);
    break;
  default:
    itemActionForRupee(this);
    break;
  case PieceOfHeart:
  case HeartContainer:
  case FiveBombs:
  case TenBombs:
  case TwentyBombs:
  case ThirtyBombs:
  case TenArrows:
  case TwentyArrows:
  case ThirtyArrows:
  case FireAndIceArrows:
  case LightArrow:
    itemActionForArrow(this);
    break;
  case SmallMagicJar:
  case LargeMagicJar:
  case JoyPendant:
  case SkullNecklace:
  case BokoBabaSeed:
  case GoldenFeather:
  case KnightsCrest:
  case RedChuJelly:
  case GreenChuJelly:
  case BlueChuJelly:
    itemActionForEmono(this);
    break;
  case SmallKey:
    itemActionForKey(this);
    break;
  case HerosSword:
  case HerosShield:
  case RecoveredHerosSword:
    itemActionForSword(this);
  }
  if (((((this->parent).mAcch.mFlags & 0x800) != 0) &&
      ((this->parent).parent.mCurrent.mPos.y < (this->parent).mAcch.mWtrChk.parent.mHeight)) ||
     ((uVar1 = d_a_sea::daSea_ChkArea
                         ((this->parent).parent.mCurrent.mPos.x,
                          (this->parent).parent.mCurrent.mPos.z), (uVar1 & 0xff) != 0 &&
      (dVar4 = (double)d_a_sea::daSea_calcWave
                                 ((double)(this->parent).parent.mCurrent.mPos.x,
                                  (double)(this->parent).parent.mCurrent.mPos.z),
      (double)(this->parent).parent.mCurrent.mPos.y < dVar4)))) {
    mode_water_init(this);
  }
  ::cBgS_GndChk::cBgS_GndChk(&local_8c);
  pcVar3 = &local_4c;
  local_4c.mbCamThrough = 0;
  local_4c.mbLinkThrough = 0;
  local_4c.mbArrowsAndLightThrough = 0;
  local_4c.mbBombThrough = 0;
  local_4c.mbBoomerangThrough = 0;
  local_4c.mbHookshotThrough = 0;
  local_8c.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar3;
  if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
    local_8c.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_40;
  }
  local_4c.mbObjThrough = 1;
  local_8c.parent.vtbl = (cBgS_Chk__vtbl *)&dBgS_ObjGndChk_Yogan::__vt;
  local_8c.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80371e60;
  local_4c.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_80371e6c;
  local_40._0_4_ = (undefined **)&DAT_80371e78;
  local_40._4_4_ = 4;
  local_8c.mPos.z = (this->parent).parent.mNext.mPos.z;
  local_8c.mPos.y = (this->parent).parent.mNext.mPos.y;
  local_8c.mPos.x = (this->parent).parent.mNext.mPos.x;
  local_8c.parent.mpPolyPassChk = pcVar3;
  dVar4 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_8c);
  if (((double)d_a_item::_6004 != dVar4) && ((double)(this->parent).parent.mCurrent.mPos.y < dVar4))
  {
    f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  }
  local_4c.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_40._0_4_ = &PTR_80371f20;
  if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
    local_4c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_40._0_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != &DAT_00000040) &&
       (local_40._0_4_ = &::dBgS_GrpPassChk::__vt, (undefined *)register0x00000004 != &DAT_00000040)
       ) {
      local_40._0_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar3 != (cBgS_PolyPassChk *)0x0) &&
       (local_4c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar3 != (cBgS_PolyPassChk *)0x0)) {
      local_4c.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_8c.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_8c.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_8c.parent);
  return;
}


/* __thiscall daItem_c::mode_water(void) */

void __thiscall daItem_c::mode_water(daItem_c *this)

{
  float fVar1;
  short sVar2;
  uint uVar3;
  double dVar4;
  
  dBgS_Acch::CrrPos(&(this->parent).mAcch,&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  uVar3 = d_a_sea::daSea_ChkArea
                    ((this->parent).parent.mCurrent.mPos.x,(this->parent).parent.mCurrent.mPos.z);
  if ((uVar3 & 0xff) == 0) {
    if ((((this->parent).mAcch.mFlags & 0x800) == 0) ||
       (fVar1 = (this->parent).mAcch.mWtrChk.parent.mHeight,
       fVar1 < (this->parent).parent.mCurrent.mPos.y)) {
      mode_wait_init(this);
    }
    else {
      (this->parent).parent.mCurrent.mPos.y = fVar1;
    }
  }
  else {
    dVar4 = (double)d_a_sea::daSea_calcWave
                              ((double)(this->parent).parent.mCurrent.mPos.x,
                               (double)(this->parent).parent.mCurrent.mPos.z);
    if (dVar4 < (double)(this->parent).parent.mCurrent.mPos.y) {
      mode_wait_init(this);
    }
    else {
      (this->parent).parent.mCurrent.mPos.y = (float)dVar4;
    }
  }
  sVar2 = (short)(0xffff / (int)daItemBase_c::m_data.mNumFramesPerFullSpin);
  f_op_actor_mng::fopAcM_addAngleY
            ((fopAc_ac_c *)this,(this->parent).parent.mCurrent.mRot.y + sVar2,sVar2);
  return;
}


/* WARNING: Removing unreachable block (ram,0x800f8934) */
/* __thiscall daItem_c::initAction(void) */

undefined4 __thiscall daItem_c::initAction(daItem_c *this)

{
  byte bVar1;
  float fVar2;
  daItemBase_c_m_data *pdVar3;
  daItemBase_c_m_data *local_r3_308;
  bool bVar4;
  undefined4 uVar5;
  double in_f31;
  double dVar6;
  float fVar7;
  double local_28;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  if ((this->mStatusFlags & 2) == 0) {
    switch(this->mItemAction) {
    case 1:
      fVar7 = SComponent::cM_rndFX(d_a_item::5_0);
      dVar6 = (double)fVar7;
      pdVar3 = daItemBase_c::getData(&this->parent);
      in_f31 = (double)(float)((double)pdVar3->field_0x8 + dVar6);
      pdVar3 = daItemBase_c::getData(&this->parent);
      (this->parent).parent.mVelocityFwd = pdVar3->field_0x10 / d_a_item::10_0;
      if (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainValue != d_a_item::0_0) {
        pdVar3 = daItemBase_c::getData(&this->parent);
        (this->parent).parent.mVelocityFwd = pdVar3->field_0x10;
      }
      fVar7 = SComponent::cM_rndF(d_a_item::65535_0);
      (this->parent).parent.mCurrent.mRot.y = (short)(int)fVar7;
      break;
    case 2:
    case 4:
    case 9:
      (this->parent).parent.mVelocityFwd = d_a_item::0_0;
      fVar7 = SComponent::cM_rndF(d_a_item::65535_0);
      (this->parent).parent.mCurrent.mRot.y = (short)(int)fVar7;
      fVar7 = SComponent::cM_rndFX(d_a_item::5_0);
      dVar6 = (double)fVar7;
      pdVar3 = daItemBase_c::getData(&this->parent);
      in_f31 = (double)(float)((double)pdVar3->field_0x8 + dVar6);
      break;
    case 3:
      in_f31 = (double)d_a_item::25_0;
      fVar7 = SComponent::cM_rndF(d_a_item::65535_0);
      (this->parent).parent.mCurrent.mRot.y = (short)(int)fVar7;
      pdVar3 = daItemBase_c::getData(&this->parent);
      (this->parent).parent.mVelocityFwd = pdVar3->mVelocityScale;
      break;
    case 6:
      fVar7 = SComponent::cM_rndFX(d_a_item::5_0);
      dVar6 = (double)fVar7;
      pdVar3 = daItemBase_c::getData(&this->parent);
      in_f31 = (double)(float)((double)pdVar3->field_0x8 + dVar6);
      break;
    case 7:
      pdVar3 = daItemBase_c::getData(&this->parent);
      (this->parent).parent.mVelocityFwd = d_a_item::1_5 * pdVar3->mVelocityScale;
      fVar7 = SComponent::cM_rndF(d_a_item::65535_0);
      (this->parent).parent.mCurrent.mRot.y = (short)(int)fVar7;
      fVar7 = SComponent::cM_rndFX(d_a_item::5_0);
      dVar6 = (double)fVar7;
      pdVar3 = daItemBase_c::getData(&this->parent);
      in_f31 = (double)(float)((double)pdVar3->field_0x8 + dVar6);
      break;
    case 8:
      fVar7 = SComponent::cM_rndF(d_a_item::65535_0);
      (this->parent).parent.mCurrent.mRot.y = (short)(int)fVar7;
      fVar7 = SComponent::cM_rndFX(d_a_item::5_0);
      dVar6 = (double)fVar7;
      pdVar3 = daItemBase_c::getData(&this->parent);
      in_f31 = (double)(float)((double)(float)pdVar3->field_0x44 + dVar6);
      pdVar3 = daItemBase_c::getData(&this->parent);
      (this->parent).parent.mVelocityFwd = pdVar3->mVelocityScale;
      break;
    case 10:
      pdVar3 = daItemBase_c::getData(&this->parent);
      (this->parent).parent.mAccelerationY = pdVar3->mFieldItemGravity;
      fVar7 = d_a_item::0_0;
      (this->parent).parent.mScale.x = d_a_item::0_0;
      (this->parent).parent.mScale.y = fVar7;
      (this->parent).parent.mScale.z = fVar7;
      this->mMode = 0;
      break;
    case 0xb:
      fVar7 = SComponent::cM_rndF(d_a_item::65535_0);
      (this->parent).parent.mCurrent.mRot.y = (short)(int)fVar7;
      in_f31 = (double)d_a_item::0_0;
      (this->parent).parent.mVelocityFwd = d_a_item::0_0;
    }
    this->field_0x65e = 0;
    bVar4 = d_item::isHeart((this->parent).mItemNo);
    if (bVar4 != false) {
      (this->parent).parent.mVelocityFwd = d_a_item::2_0 * (this->parent).parent.mVelocityFwd;
      pdVar3 = daItemBase_c::getData(&this->parent);
      local_28 = (double)CONCAT44(0x43300000,(int)*(short *)&pdVar3->field_0x2a ^ 0x80000000);
      fVar7 = SComponent::cM_rndFX((float)(local_28 - d_a_item::_4259));
      this->field_0x65e = (short)(int)fVar7;
    }
    pdVar3 = daItemBase_c::getData(&this->parent);
    (this->parent).parent.mAccelerationY = pdVar3->mFieldItemGravity;
    fVar7 = d_a_item::0_0;
    (this->parent).parent.mVelocity.x = d_a_item::0_0;
    (this->parent).parent.mVelocity.y = (float)in_f31;
    (this->parent).parent.mVelocity.z = fVar7;
    (this->parent).parent.mScale.x = fVar7;
    (this->parent).parent.mScale.y = fVar7;
    (this->parent).parent.mScale.z = fVar7;
    this->mMode = 0;
    this->mStatusFlags = this->mStatusFlags | 4;
  }
  else {
    fVar7 = (this->parent).mScaleTarget.z;
    fVar2 = (this->parent).mScaleTarget.y;
    (this->parent).parent.mScale.x = (this->parent).mScaleTarget.x;
    (this->parent).parent.mScale.y = fVar2;
    (this->parent).parent.mScale.z = fVar7;
    fVar2 = d_a_item::1_0;
    fVar7 = d_a_item::0_0;
    bVar1 = this->mItemAction;
    if (bVar1 == 5) {
      (this->parent).parent.mVelocity.x = d_a_item::0_0;
      (this->parent).parent.mVelocity.y = fVar7;
      (this->parent).parent.mVelocity.z = fVar7;
      (this->parent).parent.mVelocityFwd = fVar7;
      (this->parent).parent.mScale.x = fVar7;
      (this->parent).parent.mScale.y = fVar7;
      (this->parent).parent.mScale.z = fVar7;
      this->mCurAction = 10;
      (this->parent).parent.mStatus = (this->parent).parent.mStatus | 0x4000;
      this->field_0x654 = 0x4a8;
    }
    else {
      if (bVar1 < 5) {
        if (3 < bVar1) {
          fVar7 = SComponent::cM_rndF(d_a_item::65535_0);
          (this->parent).parent.mCurrent.mRot.y = (short)(int)fVar7;
          fVar7 = SComponent::cM_rndF(d_a_item::5_0);
          dVar6 = (double)fVar7;
          pdVar3 = daItemBase_c::getData(&this->parent);
          dVar6 = (double)(float)((double)*(float *)&pdVar3->field_0x2c + dVar6);
          pdVar3 = daItemBase_c::getData(&this->parent);
          fVar7 = SComponent::cM_rndF(*(float *)&pdVar3->field_0x30);
          (this->parent).parent.mVelocityFwd = fVar7;
          fVar7 = d_a_item::0_0;
          (this->parent).parent.mVelocity.x = d_a_item::0_0;
          (this->parent).parent.mVelocity.y = (float)dVar6;
          (this->parent).parent.mVelocity.z = fVar7;
        }
      }
      else {
        if (bVar1 == 0xc) {
          (this->parent).parent.mScale.x = d_a_item::1_0;
          (this->parent).parent.mScale.y = fVar2;
          (this->parent).parent.mScale.z = fVar2;
          this->mCurAction = 0xb;
          (this->parent).parent.mStatus = (this->parent).parent.mStatus | 0x4000;
          this->field_0x654 = 0x4a8;
        }
      }
    }
    local_r3_308 = daItemBase_c::getData(&this->parent);
    (this->parent).parent.mAccelerationY = local_r3_308->mFieldItemGravity;
    this->mStatusFlags = this->mStatusFlags & 0xfb;
    this->mMode = 0;
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return 1;
}


namespace d_a_item {

/* __stdcall daItem_Draw(daItem_c *) */

void daItem_Draw(daItem_c *param_1)

{
  ::daItem_c::_daItem_draw(param_1);
  return;
}


/* __stdcall daItem_Execute(daItem_c *) */

void daItem_Execute(daItem_c *param_1)

{
  ::daItem_c::_daItem_execute(param_1);
  return;
}


/* __stdcall daItem_IsDelete(daItem_c *) */

void daItem_IsDelete(daItem_c *param_1)

{
  ::daItem_c::_daItem_isdelete(param_1);
  return;
}


/* __stdcall daItem_Delete(daItem_c *) */

void daItem_Delete(daItem_c *param_1)

{
  ::daItem_c::_daItem_delete(param_1);
  return;
}


/* __stdcall daItem_Create(fopAc_ac_c *) */

void daItem_Create(daItem_c *this)

{
  ::daItem_c::_daItem_create(this);
  return;
}

}

/* __thiscall daItem_c::_daItem_isdelete(void) */

undefined4 __thiscall daItem_c::_daItem_isdelete(daItem_c *this)

{
  return 1;
}


/* __thiscall daPy_py_c::getHeadTopPos(void) const */

cXyz * __thiscall daPy_py_c::getHeadTopPos(cXyz *__return_storage_ptr__,daPy_py_c *this)

{
  __return_storage_ptr__->x = (this->mHeadTopPos).x;
  __return_storage_ptr__->y = (this->mHeadTopPos).y;
  __return_storage_ptr__->z = (this->mHeadTopPos).z;
  return __return_storage_ptr__;
}

