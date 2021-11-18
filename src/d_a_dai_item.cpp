#include <d_a_dai_item.h>
#include <d_com_inf_game.h>
#include <d_a_dai_item.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <m_Do_ext.h>
#include <JKernel/JKRHeap.h>
#include <d_cloth_packet.h>
#include <f_op_actor_mng.h>
#include <d_bg_s_acch.h>
#include <d_kankyo_wether.h>
#include <SComponent/c_math.h>
#include <JUtility/JUTNameTab.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_com_static.h>
#include <d_kankyo.h>
#include <f_op_actor.h>
#include <d_cc_d.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <SComponent/c_lib.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <d_particle.h>
#include <JPABase/JPAMath.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_drawlist.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <daStandItem_c.h>
#include <cCcD_CylAttr.h>
#include <Demangler/dCcD_Cyl.h>


namespace d_a_dai_item {
}

namespace dCcD_Cyl {
}

namespace d_a_dai_item {
undefined Vobj03_pos0;
undefined Vobj03_pos1;
undefined Vobj04_pos0;
undefined Vobj04_pos1;
undefined Vobj05_pos0;
undefined Vobj05_pos1;
undefined Vobj07_0_pos0;
undefined Vobj07_0_pos1;
undefined1 init$4895;

/* __stdcall convItemNo(unsigned char) */

undefined4 convItemNo(undefined param_1)

{
  switch(param_1) {
  case 0x8c:
    return 0;
  case 0x8d:
    return 1;
  case 0x8e:
    return 2;
  case 0x8f:
    return 3;
  case 0x90:
    return 4;
  case 0x91:
    return 5;
  case 0x92:
    return 6;
  case 0x93:
    return 7;
  case 0x94:
    return 8;
  case 0x95:
    return 9;
  case 0x96:
    return 10;
  case 0x97:
    return 0xb;
  default:
    return 0;
  }
}

}

/* __thiscall daStandItem_c::_delete(void) */

undefined4 __thiscall daStandItem_c::_delete(daStandItem_c *this)

{
  JPABaseEmitter *pJVar1;
  
  pJVar1 = this->field_0x694;
  if (pJVar1 != (JPABaseEmitter *)0x0) {
    pJVar1->mMaxFrame = -1;
    pJVar1->mFlags = pJVar1->mFlags | 1;
    this->field_0x694 = (JPABaseEmitter *)0x0;
  }
  pJVar1 = this->field_0x690;
  if (pJVar1 != (JPABaseEmitter *)0x0) {
    pJVar1->mMaxFrame = -1;
    pJVar1->mFlags = pJVar1->mFlags | 1;
    this->field_0x690 = (JPABaseEmitter *)0x0;
  }
  pJVar1 = this->field_0x698;
  if (pJVar1 != (JPABaseEmitter *)0x0) {
    pJVar1->mFlags = pJVar1->mFlags & 0xffffffbf;
    pJVar1 = this->field_0x698;
    pJVar1->mMaxFrame = -1;
    pJVar1->mFlags = pJVar1->mFlags | 1;
    this->field_0x698 = (JPABaseEmitter *)0x0;
  }
  d_com_inf_game::dComIfG_resDelete(&this->mPhsDai,"Fdai");
  d_com_inf_game::dComIfG_resDelete(&this->mPhsCloth,"Cloth");
  return 1;
}


namespace d_a_dai_item {

/* __stdcall CheckCreateHeap(fopAc_ac_c *) */

void CheckCreateHeap(daStandItem_c *param_1)

{
  ::daStandItem_c::CreateHeap(param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daStandItem_c::CreateHeap(void) */

undefined4 __thiscall daStandItem_c::CreateHeap(daStandItem_c *this)

{
  byte bVar1;
  J3DModelData *pModel;
  ulong uVar2;
  J3DModel *pJVar3;
  J3DAnmTransform *pJVar4;
  mDoExt_bckAnm *pBckAnm;
  int iVar5;
  void *pvVar6;
  void *pvVar7;
  dCloth_packet_c *pdVar8;
  long clothRes [4];
  undefined *clothFunc [4];
  
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     ("Fdai",(int)(short)m_bmdidx[this->mItemType],
                      d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pModel == (J3DModelData *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_a_dai_item.cpp",0x239,"modelData != 0");
    m_Do_printf::OSPanic("d_a_dai_item.cpp",0x239,"Halt");
  }
  if (this->mItemNo == 0x97) {
    pJVar3 = m_Do_ext::mDoExt_J3DModel__create(pModel,0,0x11020203);
    this->mpModel = pJVar3;
  }
  else {
    pJVar3 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11000022);
    this->mpModel = pJVar3;
  }
  if (this->mpModel == (J3DModel *)0x0) {
    return 0;
  }
  if (m_bckidx[this->mItemType] != -1) {
    pJVar4 = (J3DAnmTransform *)
             dRes_control_c::getRes
                       ("Fdai",(int)m_bckidx[this->mItemType],
                        d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pJVar4 == (J3DAnmTransform *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_a_dai_item.cpp",0x250,"pbck != 0");
      m_Do_printf::OSPanic("d_a_dai_item.cpp",0x250,"Halt");
    }
    pBckAnm = (mDoExt_bckAnm *)JKernel::operator_new(0x10);
    if (pBckAnm != (mDoExt_bckAnm *)0x0) {
      (pBckAnm->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
      (pBckAnm->parent).mpFrameCtrl = (J3DFrameCtrl *)0x0;
      (pBckAnm->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_bckAnm::__vt;
      pBckAnm->mpMtxCalc = (J3DMtxCalc *)0x0;
    }
    this->mpBckAnm = pBckAnm;
    if ((this->mpBckAnm == (mDoExt_bckAnm *)0x0) ||
       (iVar5 = ::mDoExt_bckAnm::init
                          (this->mpBckAnm,pModel,pJVar4,true,
                           (J3DFrameCtrl__LoopMode)
                           *(undefined4 *)(&d_a_dai_item::playmode_4108 + (uint)this->mItemType * 4)
                           ,d_a_dai_item::1_0,0,-1,false), iVar5 == 0)) {
      return 0;
    }
    ((this->mpBckAnm->parent).mpFrameCtrl)->mSpeed = d_a_dai_item::0_0;
  }
  bVar1 = this->mItemNo;
  if ((((bVar1 != 0x8f) && (bVar1 != 0x90)) && (bVar1 != 0x91)) && (bVar1 != 0x93)) {
    this->mpCloth = (dCloth_packet_c *)0x0;
    return 1;
  }
  clothFunc[0] = d_a_dai_item::_4125;
  clothFunc[1] = PTR_dClothVobj04_create_8035bc5c;
  clothFunc[2] = PTR_dClothVobj05_create_8035bc60;
  clothFunc[3] = PTR_dClothVobj07_0_create_8035bc64;
  clothRes[0] = d_a_dai_item::_4126;
  clothRes[1] = DAT_8035bc6c;
  clothRes[2] = DAT_8035bc70;
  clothRes[3] = _DAT_8035bc74;
  if (bVar1 == 0x91) {
    this->mClothType = 2;
    goto LAB_800e3a50;
  }
  if (bVar1 < 0x91) {
    if (bVar1 == 0x8f) {
      this->mClothType = 0;
      goto LAB_800e3a50;
    }
    if (0x8e < bVar1) {
      this->mClothType = 1;
      goto LAB_800e3a50;
    }
  }
  this->mClothType = 3;
LAB_800e3a50:
  pvVar6 = dRes_control_c::getRes
                     ("Fdai",clothRes[this->mClothType],
                      d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  pvVar7 = dRes_control_c::getRes
                     ("Cloth",3,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  pdVar8 = (dCloth_packet_c *)
           (*(code *)clothFunc[this->mClothType])
                     (pvVar6,pvVar7,&(this->parent).mTevStr,
                      (&d_a_dai_item::VobjFlagPosTbl)[this->mClothType]);
  this->mpCloth = pdVar8;
  if (this->mpCloth != (dCloth_packet_c *)0x0) {
    return 1;
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall daStandItem_c::CreateInit(void) */

void __thiscall daStandItem_c::CreateInit(daStandItem_c *this)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  cXyz *pcVar7;
  int iVar8;
  char *pcVar9;
  ushort uVar10;
  JUTNameTab *this_00;
  double dVar11;
  float fVar12;
  double local_30;
  double local_20;
  
  (this->parent).mpCullMtx = &this->mpModel->mBaseMtx;
  f_op_actor_mng::fopAcM_setCullSizeBox
            (&this->parent,(double)d_a_dai_item::_100_0,(double)d_a_dai_item::0_0,
             (double)d_a_dai_item::_100_0,(double)d_a_dai_item::100_0,(double)d_a_dai_item::300_0,
             (double)d_a_dai_item::100_0);
  ::dBgS_AcchCir::SetWall(&this->mAcchCir,d_a_dai_item::_4261,d_a_dai_item::_4261);
  dBgS_Acch::Set(&this->mAcch,&(this->parent).mCurrent.mPos,&(this->parent).mNext.mPos,&this->parent
                 ,1,&this->mAcchCir,&(this->parent).mVelocity,(csXyz *)0x0,(csXyz *)0x0);
  if (((this->parent).mStatus & IsBeingCarried) == 0) {
    mode_wait_init(this);
  }
  else {
    mode_carry_init(this);
  }
  this->field_0x624 = 0;
  pcVar7 = d_kankyo_wether::dKyw_get_wind_vec();
  (this->field_0x6a4).x = pcVar7->x;
  (this->field_0x6a4).y = pcVar7->y;
  (this->field_0x6a4).z = pcVar7->z;
  iVar8 = SComponent::cM_atan2s((this->field_0x6a4).x,(this->field_0x6a4).z);
  this->field_0x6a2 = (short)iVar8;
  set_mtx(this);
  uVar10 = 0;
  this->mpModel->mpUserData = (void *)0x0;
  this_00 = (this->mpModel->mpModelData->mJointTree).mpNameTable;
  bVar1 = this->mItemNo;
  if (bVar1 == 0x95) {
    for (; uVar10 < (ushort)(this->mpModel->mpModelData->mJointTree).mJointCount;
        uVar10 = uVar10 + 1) {
      pcVar9 = (char *)JUTNameTab::getName(this_00,uVar10);
      iVar8 = MSL_C.PPCEABI.bare.H::strcmp("tuboko_head",pcVar9);
      if ((iVar8 == 0) || (iVar8 = MSL_C.PPCEABI.bare.H::strcmp("tuboko_base",pcVar9), iVar8 == 0))
      {
        ((this->mpModel->mpModelData->mJointTree).mpJoints[uVar10]->parent).mpCalcCallBack =
             daiItemNodeCallBack;
      }
    }
    this->mpModel->mpUserData = this;
    (*(code *)this->mpModel->vtbl->calc)();
  }
  else {
    if ((bVar1 < 0x95) && (bVar1 == 0x92)) {
      for (uVar10 = 0; uVar10 < (ushort)(this->mpModel->mpModelData->mJointTree).mJointCount;
          uVar10 = uVar10 + 1) {
        pcVar9 = (char *)JUTNameTab::getName(this_00,uVar10);
        iVar8 = MSL_C.PPCEABI.bare.H::strcmp("top",pcVar9);
        if (iVar8 == 0) {
          ((this->mpModel->mpModelData->mJointTree).mpJoints[uVar10]->parent).mpCalcCallBack =
               daiItemNodeCallBack;
          break;
        }
      }
      this->mpModel->mpUserData = this;
      (*(code *)this->mpModel->vtbl->calc)();
    }
  }
  dVar11 = d_kankyo_wether::dKyw_get_wind_pow();
  this->field_0x6bc = (float)dVar11;
  uVar4 = (uint)this->mItemType;
  sVar2 = m_stop_min_time[uVar4];
  sVar3 = m_stop_max_time[uVar4];
  uVar5 = (int)m_anim_min_time[uVar4] + (int)m_anim_max_time[uVar4];
  uVar4 = (int)m_anim_max_time[uVar4] - (int)m_anim_min_time[uVar4];
  this->mBckPlayTimer = 0;
  uVar6 = (int)sVar3 - (int)sVar2;
  local_30 = (double)CONCAT44(0x43300000,
                              (int)(short)((short)((int)uVar6 >> 1) +
                                          (ushort)((int)uVar6 < 0 && (uVar6 & 1) != 0)) ^ 0x80000000
                             );
  fVar12 = SComponent::cM_rndFX((float)(local_30 - d_a_dai_item::_4263));
  dVar11 = d_a_dai_item::_4263;
  uVar6 = (int)sVar2 + (int)sVar3;
  this->mBckStopTimer =
       (short)(int)((float)((double)CONCAT44(0x43300000,
                                             (int)(short)((short)((int)uVar6 >> 1) +
                                                         (ushort)((int)uVar6 < 0 && (uVar6 & 1) != 0
                                                                 )) ^ 0x80000000) -
                           d_a_dai_item::_4263) + fVar12);
  if (sVar3 == 0) {
    local_20 = (double)CONCAT44(0x43300000,
                                (int)(short)((short)((int)uVar4 >> 1) +
                                            (ushort)((int)uVar4 < 0 && (uVar4 & 1) != 0)) ^
                                0x80000000);
    fVar12 = SComponent::cM_rndFX((float)(local_20 - dVar11));
    this->mBckPlayTimer =
         (short)(int)((float)((double)CONCAT44(0x43300000,
                                               (int)(short)((short)((int)uVar5 >> 1) +
                                                           (ushort)((int)uVar5 < 0 &&
                                                                   (uVar5 & 1) != 0)) ^ 0x80000000)
                             - d_a_dai_item::_4263) + fVar12);
  }
  this->field_0x690 = (JPABaseEmitter *)0x0;
  this->field_0x694 = (JPABaseEmitter *)0x0;
  this->field_0x698 = (JPABaseEmitter *)0x0;
  dScnKy_env_light_c::settingTevStruct
            (&d_kankyo::g_env_light,Actor,&(this->parent).mCurrent.mPos,&(this->parent).mTevStr);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daStandItem_c::_create(void) */

PhaseState __thiscall daStandItem_c::_create(daStandItem_c *this)

{
  byte bVar4;
  PhaseState PVar1;
  PhaseState PVar2;
  uint uVar3;
  
  if (((this->parent).mCondition & Constructed) == 0) {
    if (this != (daStandItem_c *)0x0) {
      fopAc_ac_c::fopAc_ac_c(&this->parent);
      *(cCcD_Stts__vtbl **)&this->field_0x2c0 = &cCcD_Stts::__vt;
      ::dCcD_GStts::dCcD_GStts((dCcD_GStts *)&this->field_0x2c4);
      *(dCcD_Stts__vtbl **)&this->field_0x2c0 = &::dCcD_Stts::__vt;
      *(undefined4 *)&this->field_0x2c4 = 0x8037ec40;
      dCcD_GObjInf::dCcD_GObjInf((dCcD_GObjInf *)&this->field_0x2e4);
      *(undefined ***)&this->field_0x3f8 = &::cCcD_ShapeAttr::__vt;
      *(cM3dGAab__vtbl **)&this->field_0x3f4 = &::cM3dGAab::__vt;
      *(undefined ***)&this->field_0x410 = &::cM3dGCyl::__vt;
      *(cCcD_ShapeAttr__vtbl **)&this->field_0x3f8 = &::cCcD_CylAttr::__vt;
      *(cCcD_CylAttr__vtbl **)&this->field_0x410 = &cCcD_CylAttr__vtbl_803951ac;
      *(dCcD_Cyl__vtbl **)&this->field_0x320 = &::dCcD_Cyl::__vt;
      *(undefined4 *)&this->field_0x3f8 = 0x8038af30;
      *(undefined4 *)&this->field_0x410 = 0x8038af84;
      dBgS_Acch::dBgS_Acch(&this->mAcch);
      (this->mAcch).mChk.vtbl = &::dBgS_ObjAcch::__vt.mChk_vtbl;
      (this->mAcch).mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)0x8037e9e4;
      (this->mAcch).mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)0x8037e9f0;
      (this->mAcch).mDChk.mPolyPassChk.parent.mbObjThrough = 1;
      ::dBgS_AcchCir::dBgS_AcchCir(&this->mAcchCir);
    }
    (this->parent).mCondition = (this->parent).mCondition | Constructed;
  }
  this->mItemNo = (byte)(this->parent).parent.parent.mParameters;
  bVar4 = d_a_dai_item::convItemNo(this->mItemNo);
  this->mItemType = bVar4;
  PVar1 = d_com_inf_game::dComIfG_resLoad(&this->mPhsDai,"Fdai");
  PVar2 = PVar1;
  if ((PVar1 == cPhs_COMPLEATE_e) &&
     (PVar2 = d_com_inf_game::dComIfG_resLoad(&this->mPhsCloth,"Cloth"), PVar2 == cPhs_COMPLEATE_e))
  {
    uVar3 = f_op_actor_mng::fopAcM_entrySolidHeap
                      (&this->parent,d_a_dai_item::CheckCreateHeap,(uint)m_heapsize[this->mItemType]
                      );
    if ((uVar3 & 0xff) == 0) {
      PVar2 = cPhs_ERROR_e;
    }
    else {
      CreateInit(this);
      PVar2 = PVar1;
    }
  }
  return PVar2;
}


/* __thiscall dCcD_Cyl::~dCcD_Cyl(void) */

void __thiscall dCcD_Cyl::_dCcD_Cyl(dCcD_Cyl *this)

{
  short in_r4;
  
  if (this != (dCcD_Cyl *)0x0) {
    (this->parent).parent.parent.parent.vtbl = &__vt.parent;
    (this->mCylAttr).parent.vtbl = &__vt.mCyl_vtbl;
    (this->mCylAttr).mCyl.vtbl = &__vt.mCylAttr_vtbl;
    if (this != (dCcD_Cyl *)0xffffff08) {
      (this->mCylAttr).parent.vtbl = &::cCcD_CylAttr::__vt;
      (this->mCylAttr).mCyl.vtbl = &cCcD_CylAttr__vtbl_803951ac;
      if (this != (dCcD_Cyl *)0xfffffee8) {
        (this->mCylAttr).mCyl.vtbl = (cCcD_CylAttr__vtbl *)&::cM3dGCyl::__vt;
      }
      if (this != (dCcD_Cyl *)0xffffff08) {
        (this->mCylAttr).parent.vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_ShapeAttr::__vt;
        if (this != (dCcD_Cyl *)0xffffff08) {
          (this->mCylAttr).parent.mAab.vtbl = &::cM3dGAab::__vt;
        }
      }
    }
    dCcD_GObjInf::_dCcD_GObjInf(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x800e4420) */
/* __thiscall daStandItem_c::set_mtx(void) */

void __thiscall daStandItem_c::set_mtx(daStandItem_c *this)

{
  uint uVar1;
  J3DModel *pJVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  float fVar8;
  float local_b0;
  float local_ac;
  float local_a8;
  cXyz local_a4;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  cXyz local_5c;
  cXyz local_50;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pJVar2 = this->mpModel;
  (pJVar2->mBaseScale).x = (this->parent).mScale.x;
  (pJVar2->mBaseScale).y = (this->parent).mScale.y;
  (pJVar2->mBaseScale).z = (this->parent).mScale.z;
  mtx::PSMTXTrans((double)(this->parent).mCurrent.mPos.x,(double)(this->parent).mCurrent.mPos.y,
                  (double)(this->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_ZXYrotM
            (&mDoMtx_stack_c::now,(int)(this->parent).mCurrent.mRot.x,
             (int)(this->parent).mCurrent.mRot.y,(int)(this->parent).mCurrent.mRot.z);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,&this->mpModel->mBaseMtx);
  if (this->mpCloth != (dCloth_packet_c *)0x0) {
    local_74 = d_a_dai_item::0_0;
    local_94 = d_a_dai_item::_4514 + d_s_play::g_regHIO.mChild[10].mFloats[15];
    local_6c = d_a_dai_item::0_0;
    local_50.x = d_a_dai_item::0_0;
    local_50.z = d_a_dai_item::0_0;
    local_80 = d_a_dai_item::0_0;
    local_78 = d_a_dai_item::0_0;
    local_44 = d_a_dai_item::0_0;
    local_3c = d_a_dai_item::0_0;
    local_8c = d_a_dai_item::0_0;
    local_88 = d_a_dai_item::_4515 + d_s_play::g_regHIO.mChild[10].mFloats[15];
    local_84 = d_a_dai_item::0_0;
    local_38 = d_a_dai_item::0_0;
    local_30 = d_a_dai_item::0_0;
    local_98 = d_a_dai_item::0_0;
    local_90 = d_a_dai_item::0_0;
    local_2c = d_a_dai_item::0_0;
    local_24 = d_a_dai_item::0_0;
    local_7c = local_94;
    local_70 = local_94;
    local_50.y = local_94;
    local_40 = local_94;
    local_34 = local_88;
    local_28 = local_94;
    ::cXyz::operator__(&local_a4,&(this->parent).mCurrent.mPos,&local_50 + this->mClothType);
    local_68 = local_a4.x;
    local_64 = local_a4.y;
    local_60 = local_a4.z;
    d_kankyo_wether::dKyw_get_AllWind_vecpow(&local_b0,&local_68);
    local_5c.x = local_b0;
    local_5c.y = local_ac;
    local_5c.z = local_a8;
    fVar8 = mtx::PSVECSquareMag(&local_5c);
    dVar7 = (double)fVar8;
    if ((double)d_a_dai_item::0_0 < dVar7) {
      dVar5 = 1.0 / SQRT(dVar7);
      dVar5 = d_a_dai_item::_4516 * dVar5 * (d_a_dai_item::_4517 - dVar7 * dVar5 * dVar5);
      dVar5 = d_a_dai_item::_4516 * dVar5 * (d_a_dai_item::_4517 - dVar7 * dVar5 * dVar5);
      dVar7 = (double)(float)(dVar7 * d_a_dai_item::_4516 * dVar5 *
                                      (d_a_dai_item::_4517 - dVar7 * dVar5 * dVar5));
    }
    fVar8 = mtx::PSVECSquareMag(&this->field_0x6a4);
    dVar5 = (double)fVar8;
    if ((double)d_a_dai_item::0_0 < dVar5) {
      dVar6 = 1.0 / SQRT(dVar5);
      dVar6 = d_a_dai_item::_4516 * dVar6 * (d_a_dai_item::_4517 - dVar5 * dVar6 * dVar6);
      dVar6 = d_a_dai_item::_4516 * dVar6 * (d_a_dai_item::_4517 - dVar5 * dVar6 * dVar6);
      dVar5 = (double)(float)(dVar5 * d_a_dai_item::_4516 * dVar6 *
                                      (d_a_dai_item::_4517 - dVar5 * dVar6 * dVar6));
    }
    if ((float)(dVar7 - dVar5) <= d_a_dai_item::_4518) {
      SComponent::cLib_addCalcPos2(&this->field_0x6a4,&local_5c,d_a_dai_item::0_1,d_a_dai_item::0_1)
      ;
      iVar3 = SComponent::cM_atan2s((this->field_0x6a4).x,(this->field_0x6a4).z);
      SComponent::cLib_addCalcAngleS2(&this->field_0x6a2,(short)iVar3,0x10,0x400);
    }
    else {
      (this->field_0x6a4).x = local_5c.x;
      (this->field_0x6a4).y = local_5c.y;
      (this->field_0x6a4).z = local_5c.z;
      iVar3 = SComponent::cM_atan2s((this->field_0x6a4).x,(this->field_0x6a4).z);
      SComponent::cLib_addCalcAngleS2(&this->field_0x6a2,(short)iVar3,4,0x1000);
    }
    uVar1 = (uint)this->mClothType;
    mDoMtx_stack_c::transM((&local_50)[uVar1].x,(&local_50)[uVar1].y,(&local_50)[uVar1].z);
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,this->field_0x6a2 - (this->parent).mCurrent.mRot.y);
    dCloth_packet_c::setMtx(this->mpCloth,&mDoMtx_stack_c::now);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* __thiscall daStandItem_c::_execute(void) */

undefined4 __thiscall daStandItem_c::_execute(daStandItem_c *this)

{
  this->mTimer = this->mTimer + 1;
  execAction(this);
  itemProc(this);
  set_mtx(this);
  if (this->mpCloth != (dCloth_packet_c *)0x0) {
    (**(code **)((this->mpCloth->parent).vtbl + 0x1c))();
  }
  return 1;
}


/* __thiscall daStandItem_c::itemProc(void) */

void __thiscall daStandItem_c::itemProc(daStandItem_c *this)

{
  bool bVar1;
  
  if ((this->mMode == 1) &&
     (bVar1 = Runtime.PPCEABI.H::__ptmf_test
                        ((PTMF *)(&d_a_dai_item::item_action_tbl + (uint)this->mItemType * 3)),
     bVar1 != false)) {
    Runtime.PPCEABI.H::__ptmf_scall
              ((PTMF *)(&d_a_dai_item::item_action_tbl + (uint)this->mItemType * 3),this,
               &DAT_80390000);
  }
  return;
}


/* __thiscall daStandItem_c::actionFobj00(void) */

undefined4 __thiscall daStandItem_c::actionFobj00(daStandItem_c *this)

{
  animTest(this);
  return 1;
}


/* __thiscall daStandItem_c::actionFobj01(void) */

undefined4 __thiscall daStandItem_c::actionFobj01(daStandItem_c *this)

{
  animTest(this);
  return 1;
}


/* __thiscall daStandItem_c::actionFobj02(void) */

undefined4 __thiscall daStandItem_c::actionFobj02(daStandItem_c *this)

{
  animTest(this);
  return 1;
}


/* __thiscall daStandItem_c::actionFobj03(void) */

undefined4 __thiscall daStandItem_c::actionFobj03(daStandItem_c *this)

{
  return 1;
}


/* __thiscall daStandItem_c::actionFobj04(void) */

undefined4 __thiscall daStandItem_c::actionFobj04(daStandItem_c *this)

{
  return 1;
}


/* __thiscall daStandItem_c::actionFobj05(void) */

undefined4 __thiscall daStandItem_c::actionFobj05(daStandItem_c *this)

{
  double dVar1;
  
  dVar1 = d_kankyo_wether::dKyw_get_wind_pow();
  if ((this->mpBckAnm != (mDoExt_bckAnm *)0x0) && ((double)d_a_dai_item::0_0 < dVar1)) {
    ::mDoExt_baseAnm::play(&this->mpBckAnm->parent);
  }
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x800e4754) */
/* __thiscall daStandItem_c::actionFobj06(void) */

undefined4 __thiscall daStandItem_c::actionFobj06(daStandItem_c *this)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  float fVar6;
  cXyz local_54;
  float local_48;
  float local_44;
  float local_40;
  cXyz local_3c;
  cXyz local_30;
  longlong local_20;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  d_kankyo_wether::dKyw_get_AllWind_vecpow(&local_48,&(this->parent).mCurrent);
  local_30.x = local_48;
  local_30.y = local_44;
  local_30.z = local_40;
  local_54.x = local_48;
  local_54.y = d_a_dai_item::0_0;
  local_54.z = local_40;
  fVar6 = mtx::PSVECSquareMag(&local_54);
  dVar5 = (double)fVar6;
  if ((double)d_a_dai_item::0_0 < dVar5) {
    dVar4 = 1.0 / SQRT(dVar5);
    dVar4 = d_a_dai_item::_4516 * dVar4 * (d_a_dai_item::_4517 - dVar5 * dVar4 * dVar4);
    dVar4 = d_a_dai_item::_4516 * dVar4 * (d_a_dai_item::_4517 - dVar5 * dVar4 * dVar4);
    dVar5 = (double)(float)(dVar5 * d_a_dai_item::_4516 * dVar4 *
                                    (d_a_dai_item::_4517 - dVar5 * dVar4 * dVar4));
  }
  local_3c.x = d_a_dai_item::0_0;
  local_3c.y = d_a_dai_item::0_0;
  local_3c.z = d_a_dai_item::0_0;
  sVar2 = SComponent::cLib_targetAngleY(&local_3c,&local_30);
  SComponent::cLib_distanceAngleS(sVar2,(this->parent).mCurrent.mRot.y);
  this->field_0x6c4 = this->field_0x6c4 + ABS((float)(dVar5 * (double)d_a_dai_item::1_0));
  if (d_a_dai_item::4_0 < this->field_0x6c4) {
    this->field_0x6c4 = d_a_dai_item::4_0;
  }
  iVar1 = (int)(d_a_dai_item::1536_0 * this->field_0x6c4);
  local_20 = (longlong)iVar1;
  this->field_0x6b2 = (short)iVar1;
  dVar5 = d_kankyo_wether::dKyw_get_wind_pow();
  dVar4 = (double)(float)((double)d_a_dai_item::0_1 + dVar5);
  dVar5 = d_kankyo_wether::dKyw_get_wind_pow();
  SComponent::cLib_addCalc
            (&this->field_0x6c4,d_a_dai_item::0_0,d_a_dai_item::0_08,
             (float)((double)d_a_dai_item::0_3 + dVar5),(float)dVar4);
  this->field_0x6b4 = this->field_0x6b4 + this->field_0x6b2;
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return 1;
}


/* __thiscall daStandItem_c::actionFobj07(void) */

undefined4 __thiscall daStandItem_c::actionFobj07(daStandItem_c *this)

{
  double dVar1;
  
  dVar1 = d_kankyo_wether::dKyw_get_wind_pow();
  if ((this->mpBckAnm != (mDoExt_bckAnm *)0x0) && ((double)d_a_dai_item::0_0 < dVar1)) {
    ::mDoExt_baseAnm::play(&this->mpBckAnm->parent);
  }
  return 1;
}


/* __thiscall daStandItem_c::actionFobj08(void) */

undefined4 __thiscall daStandItem_c::actionFobj08(daStandItem_c *this)

{
  animTest(this);
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x800e4b78) */
/* __thiscall daStandItem_c::actionFobj09(void) */

undefined4 __thiscall daStandItem_c::actionFobj09(daStandItem_c *this)

{
  bool bVar1;
  JPABaseEmitter *pJVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  float fVar6;
  cXyz local_34;
  cXyz local_28;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::cXyz::operator__(&local_28,
                     &((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).parent.
                      mCurrent.mPos,&(this->parent).mCurrent.mPos);
  local_34.x = local_28.x;
  local_34.y = d_a_dai_item::0_0;
  local_34.z = local_28.z;
  fVar6 = mtx::PSVECSquareMag(&local_34);
  dVar5 = (double)fVar6;
  if ((double)d_a_dai_item::0_0 < dVar5) {
    dVar4 = 1.0 / SQRT(dVar5);
    dVar4 = d_a_dai_item::_4516 * dVar4 * (d_a_dai_item::_4517 - dVar5 * dVar4 * dVar4);
    dVar4 = d_a_dai_item::_4516 * dVar4 * (d_a_dai_item::_4517 - dVar5 * dVar4 * dVar4);
    dVar5 = (double)(float)(dVar5 * d_a_dai_item::_4516 * dVar4 *
                                    (d_a_dai_item::_4517 - dVar5 * dVar4 * dVar4));
  }
  animTestForOneTime(this);
  if (((double)d_a_dai_item::500_0 <= dVar5) || (this->mbBckDidPlay != 0)) {
    bVar1 = this->mbBckDidPlay != 0;
    if (bVar1) {
      if (bVar1) {
        if (this->field_0x6b1 == 0) {
          pJVar2 = this->field_0x690;
          if (pJVar2 != (JPABaseEmitter *)0x0) {
            pJVar2->mMaxFrame = -1;
            pJVar2->mFlags = pJVar2->mFlags | 1;
            this->field_0x690 = (JPABaseEmitter *)0x0;
          }
          if (this->field_0x694 == (JPABaseEmitter *)0x0) {
            pJVar2 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,
                                        0x82b4,&(this->parent).mCurrent.mPos,
                                        &(this->parent).mCurrent.mRot,(cXyz *)0x0,0xff,
                                        (dPa_levelEcallBack *)0x0,(this->parent).mCurrent.mRoomNo,
                                        &(this->parent).mTevStr.mColorK0,(_GXColor *)0x0,(cXyz *)0x0
                                       );
            this->field_0x694 = pJVar2;
          }
          if (this->field_0x698 == (JPABaseEmitter *)0x0) {
            pJVar2 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,
                                        0x82b5,&(this->parent).mCurrent.mPos,
                                        &(this->parent).mCurrent.mRot,(cXyz *)0x0,0xff,
                                        (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0
                                        ,(cXyz *)0x0);
            this->field_0x698 = pJVar2;
          }
          pJVar2 = this->field_0x698;
          if (pJVar2 != (JPABaseEmitter *)0x0) {
            pJVar2->mFlags = pJVar2->mFlags | 0x40;
          }
        }
        pJVar2 = this->field_0x694;
        if (pJVar2 != (JPABaseEmitter *)0x0) {
          JPABase::JPASetRMtxTVecfromMtx
                    (&this->field_0x660,&pJVar2->mGlobalRotation,&pJVar2->mGlobalTranslation);
        }
        pJVar2 = this->field_0x698;
        if (pJVar2 != (JPABaseEmitter *)0x0) {
          JPABase::JPASetRMtxTVecfromMtx
                    (&this->field_0x630,&pJVar2->mGlobalRotation,&pJVar2->mGlobalTranslation);
        }
      }
    }
    else {
      pJVar2 = this->field_0x690;
      if (pJVar2 != (JPABaseEmitter *)0x0) {
        pJVar2->mMaxFrame = -1;
        pJVar2->mFlags = pJVar2->mFlags | 1;
        this->field_0x690 = (JPABaseEmitter *)0x0;
      }
      pJVar2 = this->field_0x694;
      if (pJVar2 != (JPABaseEmitter *)0x0) {
        pJVar2->mMaxFrame = -1;
        pJVar2->mFlags = pJVar2->mFlags | 1;
        this->field_0x694 = (JPABaseEmitter *)0x0;
      }
      pJVar2 = this->field_0x698;
      if (pJVar2 != (JPABaseEmitter *)0x0) {
        pJVar2->mFlags = pJVar2->mFlags & 0xffffffbf;
        pJVar2 = this->field_0x698;
        pJVar2->mMaxFrame = -1;
        pJVar2->mFlags = pJVar2->mFlags | 1;
        this->field_0x698 = (JPABaseEmitter *)0x0;
      }
    }
  }
  else {
    pJVar2 = this->field_0x694;
    if (pJVar2 != (JPABaseEmitter *)0x0) {
      pJVar2->mMaxFrame = -1;
      pJVar2->mFlags = pJVar2->mFlags | 1;
      this->field_0x694 = (JPABaseEmitter *)0x0;
    }
    pJVar2 = this->field_0x698;
    if (pJVar2 != (JPABaseEmitter *)0x0) {
      pJVar2->mFlags = pJVar2->mFlags & 0xffffffbf;
      pJVar2 = this->field_0x698;
      pJVar2->mMaxFrame = -1;
      pJVar2->mFlags = pJVar2->mFlags | 1;
      this->field_0x698 = (JPABaseEmitter *)0x0;
    }
    pJVar2 = this->field_0x690;
    if (pJVar2 == (JPABaseEmitter *)0x0) {
      pJVar2 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x82b3,
                                  &(this->parent).mCurrent.mPos,&(this->parent).mCurrent.mRot,
                                  (cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,
                                  (this->parent).mCurrent.mRoomNo,&(this->parent).mTevStr.mColorK0,
                                  (_GXColor *)0x0,(cXyz *)0x0);
      this->field_0x690 = pJVar2;
    }
    else {
      JPABase::JPASetRMtxTVecfromMtx
                (&this->field_0x660,&pJVar2->mGlobalRotation,&pJVar2->mGlobalTranslation);
    }
  }
  this->field_0x6b1 = this->mbBckDidPlay;
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return 1;
}


/* __thiscall daStandItem_c::actionFobj10(void) */

undefined4 __thiscall daStandItem_c::actionFobj10(daStandItem_c *this)

{
  animTest(this);
  return 1;
}


/* __thiscall daStandItem_c::actionFobj11(void) */

undefined4 __thiscall daStandItem_c::actionFobj11(daStandItem_c *this)

{
  this->mBckSpeed = d_a_dai_item::1_0;
  animTest(this);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daStandItem_c::animTest(void) */

void __thiscall daStandItem_c::animTest(daStandItem_c *this)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  float fVar6;
  double local_28;
  double local_18;
  
  uVar5 = (uint)this->mItemType;
  sVar1 = m_anim_min_time[uVar5];
  sVar2 = m_anim_max_time[uVar5];
  sVar3 = m_stop_min_time[uVar5];
  sVar4 = m_stop_max_time[uVar5];
  this->mbBckDidPlay = 0;
  if (this->mBckPlayTimer < 1) {
    if (0 < this->mBckStopTimer) {
      this->mBckStopTimer = this->mBckStopTimer + -1;
      if (sVar2 == 0) {
        this->mBckStopTimer = 1;
      }
      if (this->mBckStopTimer == 0) {
        uVar5 = (int)sVar2 - (int)sVar1;
        local_18 = (double)CONCAT44(0x43300000,
                                    (int)(short)((short)((int)uVar5 >> 1) +
                                                (ushort)((int)uVar5 < 0 && (uVar5 & 1) != 0)) ^
                                    0x80000000);
        fVar6 = SComponent::cM_rndFX((float)(local_18 - d_a_dai_item::_4263));
        uVar5 = (int)sVar1 + (int)sVar2;
        this->mBckPlayTimer =
             (short)(int)((float)((double)CONCAT44(0x43300000,
                                                   (int)(short)((short)((int)uVar5 >> 1) +
                                                               (ushort)((int)uVar5 < 0 &&
                                                                       (uVar5 & 1) != 0)) ^
                                                   0x80000000) - d_a_dai_item::_4263) + fVar6);
        this->mBckSpeed = d_a_dai_item::1_0;
        if (this->mpBckAnm != (mDoExt_bckAnm *)0x0) {
          ((this->mpBckAnm->parent).mpFrameCtrl)->mSpeed = this->mBckSpeed;
        }
      }
    }
  }
  else {
    this->mBckPlayTimer = this->mBckPlayTimer + -1;
    if (this->mpBckAnm != (mDoExt_bckAnm *)0x0) {
      ::mDoExt_baseAnm::play(&this->mpBckAnm->parent);
      this->mbBckDidPlay = 1;
    }
    if (sVar4 == 0) {
      this->mBckPlayTimer = 0x10;
      ((this->mpBckAnm->parent).mpFrameCtrl)->mSpeed = d_a_dai_item::1_0;
    }
    if ((this->mBckPlayTimer < 0xf) && (sVar4 != 0)) {
      SComponent::cLib_addCalc
                (&this->mBckSpeed,d_a_dai_item::0_0,d_a_dai_item::0_1,d_a_dai_item::0_1,
                 d_a_dai_item::0_05);
      ((this->mpBckAnm->parent).mpFrameCtrl)->mSpeed = this->mBckSpeed;
    }
    if ((d_a_dai_item::0_0 == this->mBckSpeed) || (this->mBckPlayTimer == 0)) {
      ((this->mpBckAnm->parent).mpFrameCtrl)->mSpeed = d_a_dai_item::0_0;
      uVar5 = (int)sVar4 - (int)sVar3;
      local_28 = (double)CONCAT44(0x43300000,
                                  (int)(short)((short)((int)uVar5 >> 1) +
                                              (ushort)((int)uVar5 < 0 && (uVar5 & 1) != 0)) ^
                                  0x80000000);
      fVar6 = SComponent::cM_rndFX((float)(local_28 - d_a_dai_item::_4263));
      uVar5 = (int)sVar3 + (int)sVar4;
      this->mBckStopTimer =
           (short)(int)((float)((double)CONCAT44(0x43300000,
                                                 (int)(short)((short)((int)uVar5 >> 1) +
                                                             (ushort)((int)uVar5 < 0 &&
                                                                     (uVar5 & 1) != 0)) ^ 0x80000000
                                                ) - d_a_dai_item::_4263) + fVar6);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall daStandItem_c::animTestForOneTime(void) */

void __thiscall daStandItem_c::animTestForOneTime(daStandItem_c *this)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  float fVar7;
  double local_38;
  double local_28;
  
  uVar5 = (uint)this->mItemType;
  sVar1 = m_anim_min_time[uVar5];
  sVar2 = m_anim_max_time[uVar5];
  sVar3 = m_stop_min_time[uVar5];
  sVar4 = m_stop_max_time[uVar5];
  this->mbBckDidPlay = 0;
  iVar6 = ::mDoExt_baseAnm::play(&this->mpBckAnm->parent);
  if (this->mBckStopTimer < 1) {
    if (0 < this->mBckPlayTimer) {
      this->mBckPlayTimer = this->mBckPlayTimer + -1;
      sVar1 = this->mBckPlayTimer;
      if ((sVar1 < 1) || (iVar6 == 0)) {
        if ((sVar1 == 0) && (iVar6 != 0)) {
          uVar5 = (int)sVar4 - (int)sVar3;
          local_28 = (double)CONCAT44(0x43300000,
                                      (int)(short)((short)((int)uVar5 >> 1) +
                                                  (ushort)((int)uVar5 < 0 && (uVar5 & 1) != 0)) ^
                                      0x80000000);
          fVar7 = SComponent::cM_rndFX((float)(local_28 - d_a_dai_item::_4263));
          uVar5 = (int)sVar3 + (int)sVar4;
          this->mBckStopTimer =
               (short)(int)((float)((double)CONCAT44(0x43300000,
                                                     (int)(short)((short)((int)uVar5 >> 1) +
                                                                 (ushort)((int)uVar5 < 0 &&
                                                                         (uVar5 & 1) != 0)) ^
                                                     0x80000000) - d_a_dai_item::_4263) + fVar7);
        }
        else {
          if (sVar1 == 0) {
            this->mBckPlayTimer = 1;
          }
        }
      }
      else {
        ((this->mpBckAnm->parent).mpFrameCtrl)->mSpeed = d_a_dai_item::1_0;
        ((this->mpBckAnm->parent).mpFrameCtrl)->mCurrentTime = d_a_dai_item::0_0;
      }
    }
  }
  else {
    this->mBckStopTimer = this->mBckStopTimer + -1;
    if (this->mBckStopTimer == 0) {
      ((this->mpBckAnm->parent).mpFrameCtrl)->mSpeed = d_a_dai_item::1_0;
      ((this->mpBckAnm->parent).mpFrameCtrl)->mCurrentTime = d_a_dai_item::0_0;
      uVar5 = (int)sVar2 - (int)sVar1;
      local_38 = (double)CONCAT44(0x43300000,
                                  (int)(short)((short)((int)uVar5 >> 1) +
                                              (ushort)((int)uVar5 < 0 && (uVar5 & 1) != 0)) ^
                                  0x80000000);
      fVar7 = SComponent::cM_rndFX((float)(local_38 - d_a_dai_item::_4263));
      uVar5 = (int)sVar1 + (int)sVar2;
      this->mBckPlayTimer =
           (short)(int)((float)((double)CONCAT44(0x43300000,
                                                 (int)(short)((short)((int)uVar5 >> 1) +
                                                             (ushort)((int)uVar5 < 0 &&
                                                                     (uVar5 & 1) != 0)) ^ 0x80000000
                                                ) - d_a_dai_item::_4263) + fVar7);
    }
  }
  if ((sVar4 == 0) && (iVar6 != 0)) {
    ((this->mpBckAnm->parent).mpFrameCtrl)->mSpeed = d_a_dai_item::1_0;
    ((this->mpBckAnm->parent).mpFrameCtrl)->mCurrentTime = d_a_dai_item::0_0;
  }
  if (iVar6 == 0) {
    this->mbBckDidPlay = 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daStandItem_c::execAction(void) */

void __thiscall daStandItem_c::execAction(daStandItem_c *this)

{
  undefined4 *in_r4;
  undefined4 *extraout_r4;
  undefined4 *extraout_r4_00;
  uint uVar1;
  
  if (d_a_dai_item::init_4895 == '\0') {
    d_a_dai_item::mode_proc_4891 = d_a_dai_item::_4892;
    DAT_8038ae2c = DAT_8038ae08;
    DAT_8038ae30 = PTR_mode_carry_8038ae0c;
    in_r4 = &d_a_dai_item::mode_proc_4891;
    DAT_8038ae34 = d_a_dai_item::_4893;
    DAT_8038ae38 = DAT_8038ae14;
    DAT_8038ae3c = PTR_mode_wait_8038ae18;
    DAT_8038ae40 = d_a_dai_item::_4894;
    DAT_8038ae44 = DAT_8038ae20;
    DAT_8038ae48 = PTR_mode_drop_8038ae24;
    d_a_dai_item::init_4895 = '\x01';
  }
  uVar1 = (this->parent).mStatus >> 0xd & 1;
  if ((uVar1 != 0) && (this->field_0x624 == 0)) {
    mode_carry_init(this);
    in_r4 = extraout_r4;
  }
  if ((this->field_0x624 != 0) && (uVar1 == 0)) {
    mode_wait_init(this);
    in_r4 = extraout_r4_00;
  }
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_a_dai_item::mode_proc_4891 + this->mMode * 3),this,in_r4);
  this->field_0x624 = (byte)uVar1;
  return;
}


/* __thiscall daStandItem_c::mode_carry_init(void) */

void __thiscall daStandItem_c::mode_carry_init(daStandItem_c *this)

{
  (this->parent).mVelocityFwd = d_a_dai_item::0_0;
  (this->parent).mVelocity.x = ::cXyz::Zero.x;
  (this->parent).mVelocity.y = ::cXyz::Zero.y;
  (this->parent).mVelocity.z = ::cXyz::Zero.z;
  (this->parent).mAttentionFlags = (this->parent).mAttentionFlags & ~Action_Carry;
  this->field_0x310 = this->field_0x310 & 0xfffffffe;
  this->mMode = 0;
  return;
}


/* __thiscall daStandItem_c::mode_carry(void) */

void __thiscall daStandItem_c::mode_carry(daStandItem_c *this)

{
  if (((this->parent).mStatus & IsBeingCarried) == 0) {
    mode_drop_init(this);
  }
  return;
}


/* __thiscall daStandItem_c::mode_wait_init(void) */

void __thiscall daStandItem_c::mode_wait_init(daStandItem_c *this)

{
  float fVar1;
  
  fVar1 = d_a_dai_item::0_0;
  (this->parent).mVelocityFwd = d_a_dai_item::0_0;
  (this->parent).mVelocity.x = fVar1;
  (this->parent).mVelocity.y = fVar1;
  (this->parent).mVelocity.z = fVar1;
  this->field_0x310 = this->field_0x310 | 1;
  this->mMode = 1;
  return;
}


/* __thiscall daStandItem_c::mode_wait(void) */

void __thiscall daStandItem_c::mode_wait(daStandItem_c *this)

{
  return;
}


/* __thiscall daStandItem_c::mode_drop_init(void) */

void __thiscall daStandItem_c::mode_drop_init(daStandItem_c *this)

{
  this->mMode = 2;
  return;
}


/* __thiscall daStandItem_c::mode_drop(void) */

void __thiscall daStandItem_c::mode_drop(daStandItem_c *this)

{
  sbyte sVar1;
  
  f_op_actor_mng::fopAcM_posMoveF(&this->parent,(cXyz *)0x0);
  dBgS_Acch::CrrPos(&this->mAcch,&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  if (((this->mAcch).mFlags & 0x20) != 0) {
    sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x2870,&(this->parent).mEyePos,0,sVar1,d_a_dai_item::1_0,
               d_a_dai_item::1_0,d_a_dai_item::_1_0,d_a_dai_item::_1_0,0);
    mode_wait_init(this);
  }
  return;
}


/* __thiscall daStandItem_c::_draw(void) */

undefined4 __thiscall daStandItem_c::_draw(daStandItem_c *this)

{
  mDoExt_bckAnm *this_00;
  
  dScnKy_env_light_c::settingTevStruct
            (&d_kankyo::g_env_light,Actor,&(this->parent).mCurrent.mPos,&(this->parent).mTevStr);
  dScnKy_env_light_c::setLightTevColorType
            (&d_kankyo::g_env_light,this->mpModel,&(this->parent).mTevStr);
  if (this->mItemNo == 0x92) {
    (*(this->mpModel->mpModelData->mJointTree).mpJoints)->mpMtxCalc = (J3DMtxCalc *)0x0;
  }
  else {
    this_00 = this->mpBckAnm;
    if (this_00 != (mDoExt_bckAnm *)0x0) {
      ::mDoExt_bckAnm::entry
                (this_00,this->mpModel->mpModelData,((this_00->parent).mpFrameCtrl)->mCurrentTime);
    }
  }
  if (this->mItemNo == 0x97) {
    d_drawlist::dDlst_texSpecmapST
              (&(this->parent).mEyePos,&(this->parent).mTevStr,this->mpModel->mpModelData,
               d_a_dai_item::1_0);
  }
  m_Do_ext::mDoExt_modelUpdateDL(this->mpModel);
  if (this->mpCloth != (dCloth_packet_c *)0x0) {
    (**(code **)((this->mpCloth->parent).vtbl + 0x20))();
  }
  return 1;
}


namespace d_a_dai_item {

/* __stdcall daStandItem_Create(void *) */

void daStandItem_Create(daStandItem_c *param_1)

{
  ::daStandItem_c::_create(param_1);
  return;
}


/* __stdcall daStandItem_Delete(void *) */

undefined daStandItem_Delete(daStandItem_c *param_1)

{
  undefined uVar1;
  
  uVar1 = ::daStandItem_c::_delete(param_1);
  return uVar1;
}


/* __stdcall daStandItem_Draw(void *) */

undefined daStandItem_Draw(daStandItem_c *param_1)

{
  undefined uVar1;
  
  uVar1 = ::daStandItem_c::_draw(param_1);
  return uVar1;
}


/* __stdcall daStandItem_Execute(void *) */

undefined daStandItem_Execute(daStandItem_c *param_1)

{
  undefined uVar1;
  
  uVar1 = ::daStandItem_c::_execute(param_1);
  return uVar1;
}


/* __stdcall daStandItem_IsDelete(void *) */

undefined4 daStandItem_IsDelete(void)

{
  return 1;
}

}

/* __thiscall dCcD_Cyl::GetShapeAttr(void) */

cCcD_CylAttr * __thiscall dCcD_Cyl::GetShapeAttr(dCcD_Cyl *this)

{
  if (this == (dCcD_Cyl *)0x0) {
    return (cCcD_CylAttr *)0x0;
  }
  return &this->mCylAttr;
}


/* __thiscall cCcD_CylAttr::GetCoCP(void) const */

cM3dGCyl * __thiscall cCcD_CylAttr::GetCoCP(cCcD_CylAttr *this)

{
  return &this->mCyl;
}


/* __thiscall cCcD_CylAttr::CrossAtTg(cCcD_AabAttr const &,
                                      cXyz *) const */

undefined4 __thiscall
cCcD_CylAttr::CrossAtTg(cCcD_CylAttr *this,cCcD_AabAttr *param_1,cXyz *param_2)

{
  return 0;
}


/* __thiscall cCcD_CylAttr::CrossAtTg(cCcD_PntAttr const &,
                                      cXyz *) const */

undefined4 __thiscall
cCcD_CylAttr::CrossAtTg(cCcD_CylAttr *this,cCcD_PntAttr *param_1,cXyz *param_2)

{
  return 0;
}


/* __thiscall cCcD_CylAttr::CrossCo(cCcD_AabAttr const &,
                                    float *) const */

undefined4 __thiscall cCcD_CylAttr::CrossCo(cCcD_CylAttr *this,cCcD_AabAttr *param_1,float *param_2)

{
  return 0;
}


/* __thiscall cCcD_CylAttr::CrossCo(cCcD_TriAttr const &,
                                    float *) const */

undefined4 __thiscall cCcD_CylAttr::CrossCo(cCcD_CylAttr *this,cCcD_TriAttr *param_1,float *param_2)

{
  return 0;
}


/* __thiscall cCcD_CylAttr::CrossCo(cCcD_PntAttr const &,
                                    float *) const */

undefined4 __thiscall cCcD_CylAttr::CrossCo(cCcD_CylAttr *this,cCcD_PntAttr *param_1,float *param_2)

{
  return 0;
}


namespace d_a_dai_item {

void __sinit_d_a_dai_item_cpp(void)

{
  Runtime.PPCEABI.H::__construct_array(&Vobj03_pos0,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x19);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4057,&_4058);
  Runtime.PPCEABI.H::__construct_array(&Vobj03_pos1,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x19);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4059,&_4060);
  Runtime.PPCEABI.H::__construct_array(&Vobj04_pos0,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x19);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4061,&_4062);
  Runtime.PPCEABI.H::__construct_array(&Vobj04_pos1,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x19);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4063,&_4064);
  Runtime.PPCEABI.H::__construct_array(&Vobj05_pos0,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x19);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4065,&_4066);
  Runtime.PPCEABI.H::__construct_array(&Vobj05_pos1,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x19);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4067,&_4068);
  Runtime.PPCEABI.H::__construct_array(&Vobj07_0_pos0,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x19);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4069,&_4070);
  Runtime.PPCEABI.H::__construct_array(&Vobj07_0_pos1,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x19);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4071,&_4072);
  item_action_tbl = _4527;
  DAT_8038ad78 = DAT_8038ace8;
  DAT_8038ad7c = PTR_actionFobj00_8038acec;
  DAT_8038ad80 = _4528;
  DAT_8038ad84 = DAT_8038acf4;
  DAT_8038ad88 = PTR_actionFobj01_8038acf8;
  DAT_8038ad8c = _4529;
  DAT_8038ad90 = DAT_8038ad00;
  DAT_8038ad94 = PTR_actionFobj02_8038ad04;
  DAT_8038ad98 = _4530;
  DAT_8038ad9c = DAT_8038ad0c;
  DAT_8038ada0 = PTR_actionFobj03_8038ad10;
  DAT_8038ada4 = _4531;
  DAT_8038ada8 = DAT_8038ad18;
  DAT_8038adac = PTR_actionFobj04_8038ad1c;
  DAT_8038adb0 = _4532;
  DAT_8038adb4 = DAT_8038ad24;
  DAT_8038adb8 = PTR_actionFobj05_8038ad28;
  DAT_8038adbc = _4533;
  DAT_8038adc0 = DAT_8038ad30;
  DAT_8038adc4 = PTR_actionFobj06_8038ad34;
  DAT_8038adc8 = _4534;
  DAT_8038adcc = DAT_8038ad3c;
  DAT_8038add0 = PTR_actionFobj07_8038ad40;
  DAT_8038add4 = _4535;
  DAT_8038add8 = DAT_8038ad48;
  DAT_8038addc = PTR_actionFobj08_8038ad4c;
  DAT_8038ade0 = _4536;
  DAT_8038ade4 = DAT_8038ad54;
  DAT_8038ade8 = PTR_actionFobj09_8038ad58;
  DAT_8038adec = _4537;
  DAT_8038adf0 = DAT_8038ad60;
  DAT_8038adf4 = PTR_actionFobj10_8038ad64;
  DAT_8038adf8 = _4538;
  DAT_8038adfc = DAT_8038ad6c;
  DAT_8038ae00 = PTR_actionFobj11_8038ad70;
  return;
}


void __arraydtor_4071(void)

{
  Runtime.PPCEABI.H::__destroy_arr(&Vobj07_0_pos1,::cXyz::_cXyz,0xc,0x19);
  return;
}


void __arraydtor_4069(void)

{
  Runtime.PPCEABI.H::__destroy_arr(&Vobj07_0_pos0,::cXyz::_cXyz,0xc,0x19);
  return;
}


void __arraydtor_4067(void)

{
  Runtime.PPCEABI.H::__destroy_arr(&Vobj05_pos1,::cXyz::_cXyz,0xc,0x19);
  return;
}


void __arraydtor_4065(void)

{
  Runtime.PPCEABI.H::__destroy_arr(&Vobj05_pos0,::cXyz::_cXyz,0xc,0x19);
  return;
}


void __arraydtor_4063(void)

{
  Runtime.PPCEABI.H::__destroy_arr(&Vobj04_pos1,::cXyz::_cXyz,0xc,0x19);
  return;
}


void __arraydtor_4061(void)

{
  Runtime.PPCEABI.H::__destroy_arr(&Vobj04_pos0,::cXyz::_cXyz,0xc,0x19);
  return;
}


void __arraydtor_4059(void)

{
  Runtime.PPCEABI.H::__destroy_arr(&Vobj03_pos1,::cXyz::_cXyz,0xc,0x19);
  return;
}


void __arraydtor_4057(void)

{
  Runtime.PPCEABI.H::__destroy_arr(&Vobj03_pos0,::cXyz::_cXyz,0xc,0x19);
  return;
}

}

/* [thunk]:__thiscall dCcD_Cyl::~dCcD_Cyl(void) */

void __thiscall dCcD_Cyl::_dCcD_Cyl(dCcD_Cyl *this)

{
  _dCcD_Cyl((dCcD_Cyl *)&this[-1].parent.parent.parent.parent.mObjTg);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* [thunk]:__thiscall dCcD_Cyl::~dCcD_Cyl(void) */

void __thiscall dCcD_Cyl::_dCcD_Cyl(dCcD_Cyl *this)

{
  _dCcD_Cyl((dCcD_Cyl *)&this[-1].parent.parent.parent.parent.mObjCo.parent.vtbl);
  return;
}

