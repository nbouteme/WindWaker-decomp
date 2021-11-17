#include <d_a_arrow.h>
#include <d_a_arrow.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <m_Do_ext.h>
#include <f_op_actor.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <f_op_actor_mng.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <JPABase/JPAMath.h>
#include <d_particle.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <SComponent/c_cc_s.h>
#include <d_cc_mass_s.h>
#include <d_attention.h>
#include <SComponent/c_lib.h>
#include <SComponent/c_math.h>
#include <d_a_player_main.h>
#include <d_kankyo.h>
#include <SComponent/c_bg_s.h>
#include <d_bg_s.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <d_bg_s_lin_chk.h>
#include <d_cc_d.h>
#include <d_jnt_hit.h>
#include <SComponent/c_m3d.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <SComponent/c_m3d_g_sph.h>
#include <SComponent/c_bg_s_lin_chk.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <JKernel/JKRHeap.h>
#include <SComponent/c_bg_s_chk.h>
#include <daArrow_c.h>
#include <cM3dGSph.h>
#include <Demangler/cCcD_Stts.h>
#include <dBgS_ArrowLinChk.h>
#include <cCcD_SphAttr.h>
#include <dCcD_Cps.h>
#include <dCcD_Sph.h>
#include <cCcD_CpsAttr.h>


namespace d_a_arrow {
undefined4 offset_arrow_pos$5149;
}
undefined1 daArrow_c;

namespace d_a_arrow {
undefined1 init$5151;

/* __stdcall createHeap_CB(fopAc_ac_c *) */

void createHeap_CB(daArrow_c *param_1)

{
  ::daArrow_c::_createHeap(param_1);
  return;
}

}

/* __thiscall daArrow_c::_createHeap(void) */

bool __thiscall daArrow_c::_createHeap(daArrow_c *this)

{
  uint uVar1;
  J3DModelData *pModel;
  ulong uVar2;
  J3DModel *pJVar3;
  
  uVar1 = countLeadingZeros(3 - (uint)*(byte *)&this->field_0x601);
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     ("Link",(uVar1 >> 5) + 0x37 & 0xffff,
                      d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pModel == (J3DModelData *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_a_arrow.cpp",0xbe,"modelData != 0");
    m_Do_printf::OSPanic("d_a_arrow.cpp",0xbe,&DAT_8035b959);
  }
  pJVar3 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11000022);
  *(J3DModel **)&this->field_0x294 = pJVar3;
  return *(int *)&this->field_0x294 != 0;
}


namespace d_a_arrow {

/* __stdcall atHit_CB(fopAc_ac_c *,
                      dCcD_GObjInf *,
                      fopAc_ac_c *,
                      dCcD_GObjInf *) */

void atHit_CB(daArrow_c *param_1,dCcD_GObjInf *param_2,fopAc_ac_c *param_3,
                        dCcD_GObjInf *param_4)

{
  ::daArrow_c::_atHit(param_1,param_2,param_3,param_4);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall daArrow_c::_atHit(dCcD_GObjInf *,
                                fopAc_ac_c *,
                                dCcD_GObjInf *) */

void __thiscall
daArrow_c::_atHit(daArrow_c *this,dCcD_GObjInf *param_1,fopAc_ac_c *param_2,dCcD_GObjInf *param_3)

{
  uint uVar1;
  bool bVar2;
  double dVar3;
  double dVar4;
  float fVar5;
  cXyz cStack52;
  cXyz local_28 [2];
  
  if (((param_2 != (fopAc_ac_c *)0x0) &&
      (bVar2 = f_op_actor::fopAc_IsActor(param_2), bVar2 != false)) &&
     (param_2->mpArrowStopJntHit != (JntHit_c *)0x0)) {
    local_28[0].x = (param_1->mObjAt).mHitPos.x;
    local_28[0].y = (param_1->mObjAt).mHitPos.y;
    local_28[0].z = (param_1->mObjAt).mHitPos.z;
    ::cXyz::operator__(&cStack52,local_28,&(this->parent).mCurrent.mPos);
    fVar5 = mtx::PSVECSquareMag(&cStack52);
    dVar4 = (double)fVar5;
    if ((double)d_a_arrow::_4193 < dVar4) {
      dVar3 = 1.0 / SQRT(dVar4);
      dVar3 = d_a_arrow::_4194 * dVar3 * (d_a_arrow::_4195 - dVar4 * dVar3 * dVar3);
      dVar3 = d_a_arrow::_4194 * dVar3 * (d_a_arrow::_4195 - dVar4 * dVar3 * dVar3);
      dVar4 = (double)(float)(dVar4 * d_a_arrow::_4194 * dVar3 *
                                      (d_a_arrow::_4195 - dVar4 * dVar3 * dVar3));
    }
    if (dVar4 < (double)*(float *)&this->field_0x6fc) {
      *(float *)&this->field_0x6fc = (float)dVar4;
      if (param_2 == (fopAc_ac_c *)0x0) {
        uVar1 = 0xffffffff;
      }
      else {
        uVar1 = (param_2->parent).parent.mBsPcId;
      }
      this->field_0x610 = uVar1;
      if (((param_3->mObjTg).parent.mGFlag & 1) == 0) {
        *(undefined *)&this->field_0x700 = 1;
        *(fopAc_ac_c **)&this->field_0x6ec = param_2;
      }
      else {
        *(undefined *)&this->field_0x700 = 0;
        *(undefined4 *)&this->field_0x6ec = 0;
      }
      *(float *)&this->field_0x6f0 = (param_1->mObjAt).mHitPos.x;
      *(float *)&this->field_0x6f4 = (param_1->mObjAt).mHitPos.y;
      *(float *)&this->field_0x6f8 = (param_1->mObjAt).mHitPos.z;
    }
  }
  return;
}


/* __thiscall daArrow_c::checkCreater(void) */

void __thiscall daArrow_c::checkCreater(daArrow_c *this)

{
  int iVar1;
  int local_18 [5];
  
  iVar1 = f_op_actor_mng::fopAcM_SearchByID((this->parent).mParentPcId,local_18);
  if ((iVar1 != 0) && (*(short *)(local_18[0] + 8) == 0xd3)) {
    *(undefined *)&this->field_0x290 = 1;
  }
  return;
}


/* __thiscall daArrow_c::setLightEffect(void) */

void __thiscall daArrow_c::setLightEffect(daArrow_c *this)

{
  undefined4 uVar1;
  fopAc_ac_c *pfVar2;
  uint parentUniqueID;
  uint uVar3;
  undefined4 local_10 [3];
  
  uVar3 = (uint)*(byte *)&this->field_0x601;
  if (*(byte *)&this->field_0x682 == uVar3) {
    if (uVar3 == 0) {
      return;
    }
    if (*(char *)&this->field_0x688 == '\0') {
      if (this == (daArrow_c *)0x0) {
        parentUniqueID = 0xffffffff;
      }
      else {
        parentUniqueID = (this->parent).parent.parent.mBsPcId;
      }
      uVar1 = f_op_actor_mng::fopAcM_createChild
                        (0x1e0,parentUniqueID,uVar3,(cXyz *)&this->field_0x6a8,
                         (int)(char)(this->parent).mCurrent.mRoomNo,&(this->parent).mCollisionRot,
                         (cXyz *)0x0,-1,(undefined *)0x0);
      *(undefined4 *)&this->field_0x684 = uVar1;
      if (*(int *)&this->field_0x684 != -1) {
        *(undefined *)&this->field_0x688 = 1;
      }
    }
  }
  else {
    local_10[0] = *(undefined4 *)&this->field_0x684;
    pfVar2 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,local_10);
    f_op_actor_mng::fopAcM_delete((base_process_class *)pfVar2);
    *(undefined *)&this->field_0x688 = 0;
  }
  *(undefined *)&this->field_0x682 = *(undefined *)&this->field_0x601;
  return;
}


/* __thiscall daArrow_c::setBlur(void) */

void __thiscall daArrow_c::setBlur(daArrow_c *this)

{
  int iVar1;
  
  iVar1 = *(int *)&this->field_0x66c;
  if (iVar1 != 0) {
    if ((int)(*(byte *)(iVar1 + 0x1ff) - 0x32) < 1) {
      (**(code **)(*(int *)&this->field_0x668 + 0x20))(&this->field_0x668);
    }
    else {
      *(byte *)(iVar1 + 0x1ff) = *(byte *)(iVar1 + 0x1ff) - 0x32;
    }
    mtx::PSMTXTrans((double)(this->parent).mCurrent.mPos.x,(double)(this->parent).mCurrent.mPos.y,
                    (double)(this->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
    m_Do_mtx::mDoMtx_ZXYrotM
              (&mDoMtx_stack_c::now,(int)*(short *)&this->field_0x67c,
               (int)*(short *)&this->field_0x67e,(int)*(short *)&this->field_0x680);
    JPABase::JPASetRMtxTVecfromMtx(&mDoMtx_stack_c::now,iVar1 + 0x1a8,iVar1 + 0x1e4);
  }
  return;
}


/* __thiscall daArrow_c::createBlur(void) */

void __thiscall daArrow_c::createBlur(daArrow_c *this)

{
  if (*(int *)&this->field_0x66c == 0) {
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0x48,
                       &(this->parent).mCurrent.mPos,(csXyz *)0x0,(cXyz *)0x0,0xff,
                       (dPa_levelEcallBack *)&this->field_0x668,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                       (cXyz *)0x0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daArrow_c::setArrowShootSe(void) */

void __thiscall daArrow_c::setArrowShootSe(daArrow_c *this)

{
  sbyte sVar1;
  actor_place *paVar2;
  ulong uVar3;
  
  if (*(byte *)&this->field_0x601 != 0) {
    uVar3 = *(ulong *)(&d_a_arrow::se_4269 + (uint)*(byte *)&this->field_0x601 * 8);
    sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
    paVar2 = &(this->parent).mCurrent;
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,uVar3,&paVar2->mPos,0,sVar1,d_a_arrow::_4288,d_a_arrow::_4288,
               d_a_arrow::_4289,d_a_arrow::_4289,0);
    uVar3 = *(ulong *)(&DAT_8035b8f0 + (uint)*(byte *)&this->field_0x601 * 8);
    sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,uVar3,&paVar2->mPos,0,sVar1,d_a_arrow::_4288,d_a_arrow::_4288,
               d_a_arrow::_4289,d_a_arrow::_4289,0);
  }
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall daArrow_c::setDrawShapeMaterial(void) */

void __thiscall daArrow_c::setDrawShapeMaterial(daArrow_c *this)

{
  (this->field_0x39c).parent.parent.parent.mObjAt.mDamageTypes =
       (&d_a_arrow::arrow_mat_4293)[(uint)*(byte *)&this->field_0x601 * 2];
  (this->field_0x39c).parent.parent.parent.mObjAt.mDamage =
       (&DAT_8035b910)[(uint)*(byte *)&this->field_0x601 * 8];
  if (*(char *)&this->field_0x290 != '\0') {
    (this->field_0x39c).parent.parent.parent.mObjAt.mDamage = 4;
    (this->field_0x39c).parent.parent.parent.mObjAt.mDamageTypes = d_a_arrow::arrow_mat_4293;
    (this->field_0x39c).parent.parent.parent.mObjAt.parent.mCommonFlag =
         (this->field_0x39c).parent.parent.parent.mObjAt.parent.mCommonFlag |
         (CategoryBit1|CategoryBit2|CategoryBit3);
  }
  if (*(ushort *)(&DAT_8035b912 + (uint)*(byte *)&this->field_0x601 * 8) == 0) {
    return;
  }
  *(undefined4 *)&this->field_0x298 =
       *(undefined4 *)
        (*(int *)(*(int *)(*(int *)(*(int *)&this->field_0x294 + 4) + 0x2c) +
                 (uint)*(ushort *)(&DAT_8035b912 + (uint)*(byte *)&this->field_0x601 * 8) * 4) +
        0x60);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daArrow_c::arrowShooting(void) */

void __thiscall daArrow_c::arrowShooting(daArrow_c *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  cXyz local_38;
  cXyz cStack44;
  float local_20;
  float local_1c;
  float local_18;
  
  *(float *)&this->field_0x6a8 = (this->parent).mCurrent.mPos.x;
  *(float *)&this->field_0x6ac = (this->parent).mCurrent.mPos.y;
  *(float *)&this->field_0x6b0 = (this->parent).mCurrent.mPos.z;
  fVar2 = d_a_arrow::_4386;
  fVar1 = JKernel::JMath::jmaCosTable
          [(int)((int)(this->parent).mCurrent.mRot.x & 0xffffU) >>
           (JKernel::JMath::jmaSinShift & 0x3f)];
  (this->parent).mVelocity.x =
       fVar1 * d_a_arrow::_4386 *
               JKernel::JMath::jmaSinTable
               [(int)((int)(this->parent).mCurrent.mRot.y & 0xffffU) >>
                (JKernel::JMath::jmaSinShift & 0x3f)];
  (this->parent).mVelocity.y =
       fVar2 * JKernel::JMath::jmaSinTable
               [(int)((int)(this->parent).mCurrent.mRot.x & 0xffffU) >>
                (JKernel::JMath::jmaSinShift & 0x3f)];
  (this->parent).mVelocity.z =
       fVar1 * fVar2 * JKernel::JMath::jmaCosTable
                       [(int)((int)(this->parent).mCurrent.mRot.y & 0xffffU) >>
                        (JKernel::JMath::jmaSinShift & 0x3f)];
  setArrowShootSe(this);
  if (((*(char *)&this->field_0x601 == '\x03') && (*(char *)&this->field_0x290 == '\0')) &&
     (iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"GanonK"),
     iVar3 != 0)) {
    (this->field_0x39c).mObjAt.mSpl = 0xb;
  }
  *(short *)&this->field_0x67c = (this->parent).mCollisionRot.x;
  *(short *)&this->field_0x67e = (this->parent).mCollisionRot.y;
  *(short *)&this->field_0x680 = (this->parent).mCollisionRot.z;
  createBlur(this);
  *(short *)&this->field_0x602 = _m_count;
  _m_count = _m_count + 1;
  if (_m_count == 5) {
    _m_count = 0;
  }
  ::cXyz::operator_(&cStack44,&(this->parent).mVelocity,d_a_arrow::_4387);
  ::cXyz::operator__(&local_38,&(this->parent).mCurrent.mPos,&cStack44);
  local_20 = local_38.x;
  local_1c = local_38.y;
  local_18 = local_38.z;
  *(float *)&this->field_0x4b4 = (this->parent).mCurrent.mPos.x;
  *(float *)&this->field_0x4b8 = (this->parent).mCurrent.mPos.y;
  *(float *)&this->field_0x4bc = (this->parent).mCurrent.mPos.z;
  *(float *)&this->field_0x4c0 = local_38.x;
  *(float *)&this->field_0x4c4 = local_38.y;
  *(float *)&this->field_0x4c8 = local_38.z;
  *(float *)&this->field_0x4d0 = d_a_arrow::_4388;
  mtx::PSVECSubtract((cXyz *)&this->field_0x4c0,(cXyz *)&this->field_0x4b4,
                     &(this->field_0x39c).mObjAt.mVel);
  cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)&this->field_0x39c);
  dCcMassS_Mng::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,
                    (cCcD_Obj *)&this->field_0x39c,1);
  *(undefined *)&this->field_0x700 = 0;
  *(float *)&this->field_0x6f0 = local_20;
  *(float *)&this->field_0x6f4 = local_1c;
  *(float *)&this->field_0x6f8 = local_18;
  *(float *)&this->field_0x6fc = d_a_arrow::_4389;
  return;
}


/* __thiscall daArrow_c::arrowUseMp(void) */

void __thiscall daArrow_c::arrowUseMp(daArrow_c *this)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18648_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18648_2_ +
       *(short *)(&d_a_arrow::use_mp_4393 + (uint)*(byte *)&this->field_0x601 * 2);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800d5080) */
/* __thiscall daArrow_c::ShieldReflect(void) */

void __thiscall daArrow_c::ShieldReflect(daArrow_c *this)

{
  float fVar1;
  float fVar2;
  short sVar3;
  short sVar4;
  daPy_lk_c *pdVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  fopAc_ac_c *pfVar9;
  short sVar11;
  JPABaseEmitter *pJVar10;
  uint uVar12;
  undefined4 uVar13;
  double dVar14;
  undefined8 in_f31;
  double dVar15;
  float fVar16;
  fopAc_ac_c *local_50;
  cXyz local_4c;
  float local_40;
  float local_3c;
  float local_38;
  undefined auStack8 [8];
  
  uVar13 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar16 = mtx::PSVECSquareMag(&(this->parent).mVelocity);
  pdVar5 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
  dVar15 = (double)fVar16;
  if ((double)d_a_arrow::_4193 < dVar15) {
    dVar14 = 1.0 / SQRT(dVar15);
    dVar14 = d_a_arrow::_4194 * dVar14 * (d_a_arrow::_4195 - dVar15 * dVar14 * dVar14);
    dVar14 = d_a_arrow::_4194 * dVar14 * (d_a_arrow::_4195 - dVar15 * dVar14 * dVar14);
    dVar15 = (double)(float)(dVar15 * d_a_arrow::_4194 * dVar14 *
                                      (d_a_arrow::_4195 - dVar15 * dVar14 * dVar14));
  }
  sVar3 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).parent.mCollisionRot.y;
  sVar4 = *(short *)&((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).field_0x2b6;
  uVar12 = SEXT24(*(short *)&((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).
                             field_0x2b4);
  iVar7 = f_op_actor_mng::fopAcM_SearchByName(0xf8,&local_50);
  if (((iVar7 != 0) &&
      (uVar8 = dAttention_c::LockonTruth(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention),
      (uVar8 & 0xff) != 0)) &&
     (pfVar9 = dAttention_c::LockonTarget(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0),
     pfVar9 == local_50)) {
    local_40 = (local_50->mCurrent).mPos.x;
    local_38 = (local_50->mCurrent).mPos.z;
    local_3c = d_a_arrow::_4471 + d_s_play::g_regHIO.mChild[8].mFloats[0];
    sVar11 = SComponent::cLib_targetAngleX(&(pdVar5->parent).parent.mCurrent,&local_40);
    uVar12 = SEXT24(-sVar11);
    (local_50->parent).parent.mParameters = 0x23;
    *(short *)&this->field_0x608 = d_s_play::g_regHIO.mChild[0].mShorts[3] + 0xf;
    pJVar10 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x3ee,
                                 &(pdVar5->parent).parent.mCurrent.mPos,(csXyz *)0x0,(cXyz *)0x0,
                                 0xff,(dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                                 (cXyz *)0x0);
    *(JPABaseEmitter **)&this->field_0x60c = pJVar10;
  }
  iVar7 = (int)(uVar12 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar16 = JKernel::JMath::jmaSinTable[iVar7];
  iVar6 = (int)((int)(short)(sVar3 + sVar4) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar1 = JKernel::JMath::jmaCosTable[iVar6];
  fVar2 = JKernel::JMath::jmaCosTable[iVar7];
  (this->parent).mVelocity.x =
       (float)((double)(JKernel::JMath::jmaSinTable[iVar6] * fVar2) * dVar15);
  (this->parent).mVelocity.y = (float)(-(double)fVar16 * dVar15);
  (this->parent).mVelocity.z = (float)((double)(fVar1 * fVar2) * dVar15);
  local_4c.z = (this->parent).mVelocity.z;
  local_4c.x = (this->parent).mVelocity.x;
  local_4c.y = d_a_arrow::_4193;
  fVar16 = mtx::PSVECSquareMag(&local_4c);
  dVar15 = (double)fVar16;
  if ((double)d_a_arrow::_4193 < dVar15) {
    dVar14 = 1.0 / SQRT(dVar15);
    dVar14 = d_a_arrow::_4194 * dVar14 * (d_a_arrow::_4195 - dVar15 * dVar14 * dVar14);
    dVar14 = d_a_arrow::_4194 * dVar14 * (d_a_arrow::_4195 - dVar15 * dVar14 * dVar14);
    dVar15 = (double)(float)(dVar15 * d_a_arrow::_4194 * dVar14 *
                                      (d_a_arrow::_4195 - dVar15 * dVar14 * dVar14));
  }
  iVar7 = SComponent::cM_atan2s(-(this->parent).mVelocity.y,(float)-dVar15);
  (this->parent).mCollisionRot.x = (short)iVar7;
  iVar7 = SComponent::cM_atan2s(-(this->parent).mVelocity.x,-(this->parent).mVelocity.z);
  (this->parent).mCollisionRot.y = (short)iVar7;
  (this->parent).mCollisionRot.z = 0;
  __psq_l0(auStack8,uVar13);
  __psq_l1(auStack8,uVar13);
  return;
}


/* WARNING: Removing unreachable block (ram,0x800d5368) */
/* __thiscall daArrow_c::check_water_in(void) */

undefined4 __thiscall daArrow_c::check_water_in(daArrow_c *this)

{
  byte bVar1;
  char cVar2;
  float fVar3;
  undefined uVar5;
  sbyte sVar6;
  undefined4 uVar4;
  uint parentUniqueID;
  int in_r6;
  undefined4 uVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f31;
  float local_58;
  cXyz local_54;
  cXyz cStack72;
  cXyz cStack60;
  cXyz local_30 [2];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  bVar1 = *(byte *)&this->field_0x699;
  uVar5 = daPy_lk_c::setItemWaterEffect((daPy_lk_c *)this,(fopAc_ac_c *)(uint)bVar1,1,in_r6);
  *(undefined *)&this->field_0x699 = uVar5;
  if (((fopAc_ac_c *)(uint)bVar1 == (fopAc_ac_c *)0x0) && (*(char *)&this->field_0x699 == '\x01')) {
    f_op_actor_mng::fopAcM_getWaterY(&(this->parent).mCurrent.mPos,&local_58);
    fVar3 = (this->parent).mCurrent.mPos.y;
    dVar9 = (double)ABS((this->parent).mNext.mPos.y - fVar3);
    dVar8 = (double)d_a_arrow::_4288;
    if (dVar8 <= dVar9) {
      dVar9 = (double)(float)((double)ABS(local_58 - fVar3) / dVar9);
      if (dVar8 < dVar9) {
        dVar9 = dVar8;
      }
      ::cXyz::operator_(&cStack60,&(this->parent).mNext.mPos,(float)dVar9);
      ::cXyz::operator_(&cStack72,&(this->parent).mCurrent.mPos,
                        (float)((double)d_a_arrow::_4288 - dVar9));
      ::cXyz::operator__(&local_54,&cStack60,&cStack72);
      local_30[0].x = local_54.x;
      local_30[0].y = local_54.y;
      local_30[0].z = local_54.z;
    }
    else {
      local_30[0].x = (this->parent).mCurrent.mPos.x;
      local_30[0].y = (this->parent).mCurrent.mPos.y;
      local_30[0].z = (this->parent).mCurrent.mPos.z;
    }
    uVar4 = DAT_803898ac;
    *(undefined4 *)&this->field_0x68c = d_a_arrow::_4483;
    *(undefined4 *)&this->field_0x690 = uVar4;
    *(undefined **)&this->field_0x694 = PTR_procWater_803898b0;
    (this->parent).parent.parent.mParameters = 4;
    cVar2 = *(char *)&this->field_0x601;
    if (cVar2 == '\x01') {
      *(undefined4 *)&this->field_0x6a4 = 1;
      dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0x35a,local_30,
                         (csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,
                         (_GXColor *)0x0,(cXyz *)0x0);
      if (*(char *)&this->field_0x6e4 == '\0') {
        d_kankyo::dKy_arrowcol_chg_on(&(this->parent).mCurrent,0);
      }
    }
    else {
      if (cVar2 == '\x02') {
        *(undefined4 *)&this->field_0x6a4 = 300;
        if (this == (daArrow_c *)0x0) {
          parentUniqueID = 0xffffffff;
        }
        else {
          parentUniqueID = (this->parent).parent.parent.mBsPcId;
        }
        f_op_actor_mng::fopAcM_createChild
                  (0x1df,parentUniqueID,(uint)*(byte *)&this->field_0x601,local_30,
                   (int)(char)(this->parent).mCurrent.mRoomNo,&(this->parent).mCurrent.mRot,
                   (cXyz *)0x0,-1,(undefined *)0x0);
        if (*(char *)&this->field_0x6e4 == '\0') {
          d_kankyo::dKy_arrowcol_chg_on(&(this->parent).mCurrent,1);
        }
      }
      else {
        if (cVar2 == '\x03') {
          dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0x2a1,local_30
                             ,(csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                             (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
          sVar6 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x69dc,&(this->parent).mCurrent.mPos,0,sVar6,
                     d_a_arrow::_4288,d_a_arrow::_4288,d_a_arrow::_4289,d_a_arrow::_4289,0);
          if (*(char *)&this->field_0x6e4 == '\0') {
            d_kankyo::dKy_arrowcol_chg_on(&(this->parent).mCurrent,2);
          }
          *(undefined4 *)&this->field_0x6a4 = 1;
        }
        else {
          *(undefined4 *)&this->field_0x6a4 = 1;
        }
      }
    }
    *(undefined *)&this->field_0x698 = 0;
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return uVar4;
}


/* __thiscall daArrow_c::changeArrowMp(void) */

char __thiscall daArrow_c::changeArrowMp(daArrow_c *this)

{
  return -((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic == 0) + -1)
  ;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daArrow_c::changeArrowType(void) */

daArrow_c * __thiscall daArrow_c::changeArrowType(daArrow_c *this)

{
  char cVar1;
  char cVar2;
  daArrow_c *pdVar3;
  
  cVar1 = *(char *)&this->field_0x601;
  *(float *)&this->field_0x660 = d_a_arrow::_4193;
  cVar2 = *(char *)&this->field_0x601;
  if (cVar2 == '\0') {
    if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic == 0) ||
       ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot != FireAndIceArrows
        && (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot != LightArrow)))
       ) {
      *(undefined *)&this->field_0x601 = 0;
    }
    else {
      *(undefined *)&this->field_0x601 = 1;
    }
  }
  else {
    if (cVar2 == '\x01') {
      if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic == 0) ||
         ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot !=
           FireAndIceArrows &&
          (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot != LightArrow))))
      {
        *(undefined *)&this->field_0x601 = 0;
      }
      else {
        *(undefined *)&this->field_0x601 = 2;
      }
    }
    else {
      if (cVar2 == '\x02') {
        if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic < 2) ||
           (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot != LightArrow))
        {
          *(undefined *)&this->field_0x601 = 0;
        }
        else {
          *(undefined *)&this->field_0x601 = 3;
        }
      }
      else {
        if (cVar2 == '\x03') {
          *(undefined *)&this->field_0x601 = 0;
        }
      }
    }
  }
  pdVar3 = this;
  if (*(char *)&this->field_0x601 != cVar1) {
    m_keep_type = *(char *)&this->field_0x601;
    pdVar3 = (daArrow_c *)
             f_op_actor_mng::fopAcM_fastCreate
                       (0x1de,0,&(this->parent).mCurrent.mPos,
                        (int)(char)(this->parent).mCurrent.mRoomNo,(csXyz *)0x0,(cXyz *)0x0,0xff,
                        (undefined *)0x0,(void *)0x0);
    if (pdVar3 == (daArrow_c *)0x0) {
      *(char *)&this->field_0x601 = cVar1;
      m_keep_type = cVar1;
      setDrawShapeMaterial(this);
      pdVar3 = this;
    }
    else {
      *(char *)&this->field_0x601 = cVar1;
      f_op_actor_mng::fopAcM_delete((base_process_class *)this);
    }
  }
  return pdVar3;
}


/* __thiscall daArrow_c::changeArrowTypeNotReady(void) */

void __thiscall daArrow_c::changeArrowTypeNotReady(daArrow_c *this)

{
  if (m_keep_type == '\0') {
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic == 0) {
      return;
    }
    if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot != FireAndIceArrows
        ) && (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot != LightArrow)
       ) {
      return;
    }
    m_keep_type = 1;
    return;
  }
  if (m_keep_type != '\x01') {
    if (m_keep_type != '\x02') {
      if (m_keep_type != '\x03') {
        return;
      }
      m_keep_type = 0;
      return;
    }
    if ((1 < d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic) &&
       (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot == LightArrow)) {
      m_keep_type = 3;
      return;
    }
    m_keep_type = 0;
    return;
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic == 0) {
    return;
  }
  if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot != FireAndIceArrows)
     && (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot != LightArrow)) {
    return;
  }
  m_keep_type = 2;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daArrow_c::setRoomInfo(void) */

void __thiscall daArrow_c::setRoomInfo(daArrow_c *this)

{
  byte bVar1;
  byte bVar2;
  double dVar3;
  
  (this->field_0x30c).mPos.x = (this->parent).mCurrent.mPos.x;
  (this->field_0x30c).mPos.y = (this->parent).mCurrent.mPos.y;
  (this->field_0x30c).mPos.z = (this->parent).mCurrent.mPos.z;
  dVar3 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                    &this->field_0x30c);
  bVar1 = dStage_roomControl_c::mStayNo;
  if ((double)d_a_arrow::_5094 != dVar3) {
    bVar1 = dBgS::GetRoomId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                            &(this->field_0x30c).mPolyInfo);
    bVar2 = dBgS::GetPolyColor(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                               &(this->field_0x30c).mPolyInfo);
    (this->parent).mTevStr.mEnvrIdxOverride = bVar2;
  }
  (this->parent).mTevStr.mRoomNo = bVar1;
  (this->field_0x37c).mRoomNo = bVar1;
  (this->parent).mCurrent.mRoomNo = bVar1;
  return;
}


/* __thiscall daArrow_c::setKeepMatrix(void) */

void __thiscall daArrow_c::setKeepMatrix(daArrow_c *this)

{
  float fVar1;
  float fVar2;
  daPy_lk_c *pdVar3;
  MTX34 *pMVar4;
  int local_18 [4];
  
  pdVar3 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  if (*(char *)&this->field_0x290 == '\0') {
    mtx::PSMTXTrans((double)d_a_arrow::_5137,(double)d_a_arrow::_5138,(double)d_a_arrow::_5139,
                    &mDoMtx_stack_c::now);
    m_Do_mtx::mDoMtx_XYZrotM(&mDoMtx_stack_c::now,0xb0b6,0x238e,0xffff9ccd);
    pMVar4 = (MTX34 *)(*(code *)pdVar3->vtbl->getLeftHandMatrix)(pdVar3);
    mtx::PSMTXConcat(pMVar4,&mDoMtx_stack_c::now,&mDoMtx_stack_c::now);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)&this->field_0x294 + 0x24));
    fVar2 = mDoMtx_stack_c::now.m[2][3];
    fVar1 = mDoMtx_stack_c::now.m[1][3];
    (this->parent).mCurrent.mPos.x = mDoMtx_stack_c::now.m[0][3];
    (this->parent).mCurrent.mPos.y = fVar1;
    (this->parent).mCurrent.mPos.z = fVar2;
    m_Do_mtx::mDoMtx_MtxToRot(&mDoMtx_stack_c::now,&(this->parent).mCollisionRot);
    (this->parent).mCurrent.mRot.y = (this->parent).mCollisionRot.y;
    (this->parent).mCurrent.mRot.x = -(this->parent).mCollisionRot.x;
  }
  else {
    f_op_actor_mng::fopAcM_SearchByID((this->parent).mParentPcId,local_18);
    mtx::PSMTXTrans((double)d_a_arrow::_5134,(double)d_a_arrow::_5135,(double)d_a_arrow::_5136,
                    &mDoMtx_stack_c::now);
    m_Do_mtx::mDoMtx_XYZrotM(&mDoMtx_stack_c::now,0x238e,0x2cdf,0x29be);
    mtx::PSMTXConcat((MTX34 *)(*(int *)(*(int *)(*(int *)(local_18[0] + 0x330) + 0x50) + 0x8c) +
                              0x390),&mDoMtx_stack_c::now,&mDoMtx_stack_c::now);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)&this->field_0x294 + 0x24));
    fVar2 = mDoMtx_stack_c::now.m[2][3];
    fVar1 = mDoMtx_stack_c::now.m[1][3];
    (this->parent).mCurrent.mPos.x = mDoMtx_stack_c::now.m[0][3];
    (this->parent).mCurrent.mPos.y = fVar1;
    (this->parent).mCurrent.mPos.z = fVar2;
    m_Do_mtx::mDoMtx_MtxToRot(&mDoMtx_stack_c::now,&(this->parent).mCollisionRot);
    (this->parent).mCurrent.mRot.y = (this->parent).mCollisionRot.y;
    (this->parent).mCurrent.mRot.x = -(this->parent).mCollisionRot.x;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daArrow_c::setStopActorMatrix(void) */

void __thiscall daArrow_c::setStopActorMatrix(daArrow_c *this)

{
  int iVar1;
  float fVar2;
  float fVar3;
  short sVar5;
  fopAc_ac_c *pfVar4;
  J3DModel *pJVar6;
  short sVar7;
  int local_38;
  csXyz local_34;
  float local_2c;
  float local_28;
  float local_24;
  undefined4 local_20;
  uint uStack28;
  longlong local_18;
  
  sVar7 = 0;
  sVar5 = d_a_arrow::cLib_calcTimer(&this->field_0x604);
  if (sVar5 != 0) {
    uStack28 = (int)this->field_0x604 ^ 0x80000000;
    local_20 = 0x43300000;
    fVar2 = (float)((double)CONCAT44(0x43300000,uStack28) - d_a_arrow::_5209) / d_a_arrow::_5205;
    iVar1 = (int)(d_a_arrow::_5206 * fVar2 * fVar2 *
                 JKernel::JMath::jmaSinTable
                 [(int)(this->field_0x604 * 0x52fb & 0xffffU) >>
                  (JKernel::JMath::jmaSinShift & 0x3f)]);
    local_18 = (longlong)iVar1;
    sVar7 = (short)iVar1;
  }
  local_38 = this->field_0x610;
  pfVar4 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_38);
  if (pfVar4 != (fopAc_ac_c *)0x0) {
    if (pfVar4->mpArrowStopJntHit != (JntHit_c *)0x0) {
      pJVar6 = pfVar4->mpArrowStopJntHit->mpModel;
      if (d_a_arrow::init_5151 == '\0') {
        d_a_arrow::offset_arrow_pos_5149 = d_a_arrow::_4193;
        DAT_803e3660 = d_a_arrow::_4193;
        DAT_803e3664 = d_a_arrow::_5207;
        Runtime.PPCEABI.H::__register_global_object
                  (&d_a_arrow::offset_arrow_pos_5149,::cXyz::_cXyz,&d_a_arrow::_5150);
        d_a_arrow::init_5151 = '\x01';
      }
      mtx::PSMTXCopy(pJVar6->mpNodeMtx + this->field_0x614,&mDoMtx_stack_c::now);
      m_Do_mtx::mDoMtx_MtxToRot(&mDoMtx_stack_c::now,&local_34);
      mDoMtx_stack_c::transM((this->field_0x618).x,(this->field_0x618).y,(this->field_0x618).z);
      m_Do_mtx::mDoMtx_ZXYrotM
                (&mDoMtx_stack_c::now,(int)(this->field_0x6e6).x,(int)(this->field_0x6e6).y,
                 (int)(this->field_0x6e6).z);
      fVar3 = mDoMtx_stack_c::now.m[2][3];
      fVar2 = mDoMtx_stack_c::now.m[1][3];
      local_2c = mDoMtx_stack_c::now.m[0][3];
      local_28 = mDoMtx_stack_c::now.m[1][3];
      local_24 = mDoMtx_stack_c::now.m[2][3];
      (this->parent).mCurrent.mPos.x = mDoMtx_stack_c::now.m[0][3];
      (this->parent).mCurrent.mPos.y = fVar2;
      (this->parent).mCurrent.mPos.z = fVar3;
      mtx::PSMTXTrans((double)(this->parent).mCurrent.mPos.x,(double)(this->parent).mCurrent.mPos.y,
                      (double)(this->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
      m_Do_mtx::mDoMtx_ZXYrotM(&mDoMtx_stack_c::now,(int)local_34.x,(int)local_34.y,(int)local_34.z)
      ;
      m_Do_mtx::mDoMtx_ZXYrotM
                (&mDoMtx_stack_c::now,(int)(this->field_0x6e6).x,(int)(this->field_0x6e6).y,
                 (int)(this->field_0x6e6).z);
      m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,sVar7);
      mDoMtx_stack_c::transM(d_a_arrow::offset_arrow_pos_5149,DAT_803e3660,DAT_803e3664);
      mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)&this->field_0x294 + 0x24));
    }
  }
  return;
}


/* __thiscall daArrow_c::procWait(void) */

undefined4 __thiscall daArrow_c::procWait(daArrow_c *this)

{
  undefined4 uVar1;
  
  (this->parent).mVelocityFwd = d_a_arrow::_4193;
  setKeepMatrix(this);
  mtx::PSMTXCopy((MTX34 *)(*(int *)&this->field_0x294 + 0x24),(MTX34 *)&this->field_0x6b4);
  (this->field_0x6e6).x = (this->parent).mCollisionRot.x;
  (this->field_0x6e6).y = (this->parent).mCollisionRot.y;
  (this->field_0x6e6).z = (this->parent).mCollisionRot.z;
  if ((this->parent).parent.parent.mParameters == 1) {
    if (*(char *)&this->field_0x290 == '\0') {
      arrowUseMp(this);
      checkRestMp(this);
    }
    uVar1 = DAT_803898b8;
    *(undefined4 *)&this->field_0x68c = d_a_arrow::_5221;
    *(undefined4 *)&this->field_0x690 = uVar1;
    *(undefined **)&this->field_0x694 = PTR_procMove_803898bc;
    arrowShooting(this);
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall daArrow_c::procMove(void) */

undefined4 __thiscall daArrow_c::procMove(daArrow_c *this)

{
  byte bVar1;
  undefined4 uVar2;
  actor_place *paVar3;
  int iVar4;
  fopAc_ac_c *pfVar5;
  cXyz *pcVar6;
  sbyte sVar9;
  char cVar10;
  cM3dGPla *pcVar7;
  ulong uVar8;
  bool bVar11;
  uint parentUniqueID;
  dCcD_GObjAt *pdVar12;
  int iVar13;
  cCcD_Obj__Status cVar14;
  double dVar15;
  double dVar16;
  float fVar17;
  csXyz cStack272;
  csXyz local_108;
  csXyz local_100;
  csXyz local_f8;
  cXyz local_f0;
  cXyz local_e4;
  cXyz local_d8;
  cXyz local_cc;
  cXyz local_c0;
  cXyz cStack180;
  cXyz cStack168;
  cXyz cStack156;
  cXyz local_90;
  cXyz cStack132;
  cXyz local_78;
  cXyz cStack108;
  cXyz local_60;
  cXyz cStack84;
  float local_48;
  float local_44;
  float local_40;
  cXyz local_3c;
  cXyz local_30;
  cXyz local_24;
  
  (this->parent).mVelocityFwd = d_a_arrow::100_0;
  paVar3 = &(this->parent).mCurrent;
  mtx::PSVECAdd(&paVar3->mPos,&(this->parent).mVelocity,&paVar3->mPos);
  ::cXyz::operator_(&cStack84,&(this->parent).mVelocity,d_a_arrow::_5753);
  ::cXyz::operator__(&local_60,&(this->parent).mCurrent.mPos,&cStack84);
  local_24.x = local_60.x;
  local_24.y = local_60.y;
  local_24.z = local_60.z;
  ::dBgS_LinChk::Set((dBgS_LinChk *)&this->field_0x2a0,&(this->parent).mNext.mPos,&local_24,
                     &this->parent);
  (this->field_0x6e6).x = (this->parent).mCollisionRot.x;
  (this->field_0x6e6).y = (this->parent).mCollisionRot.y;
  (this->field_0x6e6).z = (this->parent).mCollisionRot.z;
  mtx::PSMTXCopy((MTX34 *)(*(int *)&this->field_0x294 + 0x24),(MTX34 *)&this->field_0x6b4);
  *(short *)&this->field_0x680 = *(short *)&this->field_0x680 + 0x889;
  iVar13 = 0;
  iVar4 = dCcD_GObjInf::ChkAtHit(&this->field_0x39c);
  if (iVar4 != 0) {
    if (((*(char *)&this->field_0x601 == '\x03') && (*(char *)&this->field_0x664 == '\0')) &&
       (((this->field_0x39c).mObjAt.parent.mStatus & Hit) != 0)) {
      pdVar12 = &(this->field_0x39c).mObjAt;
      pfVar5 = dCcD_GAtTgCoCommonBase::GetAc(&pdVar12->parent);
      if ((pfVar5->parent).parent.mProcName == 0xa9) {
        dCcD_GAtTgCoCommonBase::GetAc(&pdVar12->parent);
        local_3c.x = (this->field_0x39c).mObjAt.mHitPos.x;
        local_3c.y = (this->field_0x39c).mObjAt.mHitPos.y;
        local_3c.z = (this->field_0x39c).mObjAt.mHitPos.z;
        iVar13 = -1;
        *(undefined *)&this->field_0x664 = 1;
        ShieldReflect(this);
        goto LAB_800d5fe8;
      }
    }
    if (*(char *)&this->field_0x700 == '\0') {
      pfVar5 = dCcD_GAtTgCoCommonBase::GetAc(&(this->field_0x39c).mObjAt.parent);
      local_3c.x = (this->field_0x39c).mObjAt.mHitPos.x;
      local_3c.y = (this->field_0x39c).mObjAt.mHitPos.y;
      local_3c.z = (this->field_0x39c).mObjAt.mHitPos.z;
      cVar14 = (this->field_0x39c).mObjAt.parent.mStatus & Hit;
    }
    else {
      pfVar5 = *(fopAc_ac_c **)&this->field_0x6ec;
      local_3c.x = *(float *)&this->field_0x6f0;
      local_3c.y = *(float *)&this->field_0x6f4;
      local_3c.z = *(float *)&this->field_0x6f8;
      cVar14 = 0;
    }
    if (pfVar5 != (fopAc_ac_c *)0x0) {
      if (*(char *)&this->field_0x601 == '\x03') {
        pdVar12 = &(this->field_0x39c).mObjAt;
        pfVar5 = dCcD_GAtTgCoCommonBase::GetAc(&pdVar12->parent);
        if ((((pfVar5->parent).parent.mProcName == 0xf5) ||
            (pfVar5 = dCcD_GAtTgCoCommonBase::GetAc(&pdVar12->parent),
            (pfVar5->parent).parent.mProcName == 0xf6)) ||
           (pfVar5 = dCcD_GAtTgCoCommonBase::GetAc(&pdVar12->parent),
           (pfVar5->parent).parent.mProcName == 0xf7)) {
          if (cVar14 == 0) {
            iVar13 = 0;
          }
          else {
            *(float *)&this->field_0x6a8 = local_3c.x;
            *(float *)&this->field_0x6ac = local_3c.y;
            *(float *)&this->field_0x6b0 = local_3c.z;
            ::cXyz::operator_(&cStack108,&(this->parent).mVelocity,d_a_arrow::_5753);
            ::cXyz::operator__(&local_78,&local_3c,&cStack108);
            (this->parent).mCurrent.mPos.x = local_78.x;
            (this->parent).mCurrent.mPos.y = local_78.y;
            (this->parent).mCurrent.mPos.z = local_78.z;
            if (*(char *)&this->field_0x6e4 == '\0') {
              d_kankyo::dKy_arrowcol_chg_on(&(this->parent).mCurrent,2);
            }
            uVar2 = DAT_803898c4;
            *(undefined4 *)&this->field_0x68c = d_a_arrow::_5255;
            *(undefined4 *)&this->field_0x690 = uVar2;
            *(undefined **)&this->field_0x694 = PTR_procStop_BG_803898c8;
            (this->parent).mStatus = (this->parent).mStatus | 0x4000;
            (this->parent).parent.parent.mParameters = 2;
            this->field_0x604 = 0x28;
            cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                            (uint)(ushort)(this->field_0x2a0).mPolyInfo.mBgIndex,
                            (uint)(ushort)(this->field_0x2a0).mPolyInfo.mTriIdx);
            local_cc.z = (this->parent).mVelocity.z;
            local_cc.x = (this->parent).mVelocity.x;
            local_cc.y = d_a_arrow::_4193;
            fVar17 = mtx::PSVECSquareMag(&local_cc);
            dVar16 = (double)fVar17;
            if ((double)d_a_arrow::_4193 < dVar16) {
              dVar15 = 1.0 / SQRT(dVar16);
              dVar15 = d_a_arrow::_4194 * dVar15 * (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15);
              dVar15 = d_a_arrow::_4194 * dVar15 * (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15);
              dVar16 = (double)(float)(dVar16 * d_a_arrow::_4194 * dVar15 *
                                                (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15));
            }
            iVar4 = SComponent::cM_atan2s((this->parent).mVelocity.y,(float)dVar16);
            local_100.x = (short)iVar4;
            iVar4 = SComponent::cM_atan2s((this->parent).mVelocity.x,(this->parent).mVelocity.z);
            local_100.y = (short)iVar4;
            local_100.z = 0;
            mtx::PSMTXTrans((double)(this->parent).mCurrent.mPos.x,
                            (double)(this->parent).mCurrent.mPos.y,
                            (double)(this->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
            m_Do_mtx::mDoMtx_ZXYrotM(&mDoMtx_stack_c::now,(int)local_100.x,(int)local_100.y,0);
            mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)&this->field_0x6b4);
            dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0x2a1,
                               (cXyz *)&this->field_0x6a8,&local_100,(cXyz *)0x0,0xff,
                               (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                               (cXyz *)0x0);
            sVar9 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x69dc,&(this->parent).mCurrent.mPos,0,sVar9,
                       d_a_arrow::_4288,d_a_arrow::_4288,d_a_arrow::_4289,d_a_arrow::_4289,0);
            f_op_actor_mng::fopAcM_delete((base_process_class *)this);
          }
        }
        else {
          iVar13 = 0;
        }
      }
      else {
        if (cVar14 == 0) {
          if (pfVar5->mpArrowStopJntHit != (JntHit_c *)0x0) {
            iVar4 = JntHit_c::searchJntHitPosAngleOffset
                              (pfVar5->mpArrowStopJntHit,&local_3c,&(this->parent).mCollisionRot,
                               &local_30,&local_f8);
            this->field_0x614 = iVar4;
            if (this->field_0x614 < 0) {
              if (this->field_0x614 == -3) {
                f_op_actor_mng::fopAcM_delete((base_process_class *)this);
                return 1;
              }
            }
            else {
              (this->field_0x6e6).x = local_f8.x;
              (this->field_0x6e6).y = local_f8.y;
              (this->field_0x6e6).z = local_f8.z;
              (this->field_0x618).x = local_30.x;
              (this->field_0x618).y = local_30.y;
              (this->field_0x618).z = local_30.z;
              iVar13 = 2;
            }
          }
        }
        else {
          iVar13 = 1;
        }
      }
    }
  }
LAB_800d5fe8:
  if (0 < iVar13) {
    this->field_0x604 = 0x28;
    (this->parent).mStatus = (this->parent).mStatus | 0x4000;
    if (*(int *)&this->field_0x66c != 0) {
      (**(code **)(*(int *)&this->field_0x668 + 0x20))(&this->field_0x668);
    }
    if (iVar13 == 1) {
      (this->parent).parent.parent.mParameters = 3;
      uVar2 = DAT_803898d0;
      *(undefined4 *)&this->field_0x68c = d_a_arrow::_5275;
      *(undefined4 *)&this->field_0x690 = uVar2;
      *(undefined **)&this->field_0x694 = PTR_procReturn_803898d4;
      pcVar6 = &(this->parent).mVelocity;
      mtx::PSVECScale(pcVar6,pcVar6,d_a_arrow::_5754);
      local_d8.z = (this->parent).mVelocity.z;
      local_d8.x = (this->parent).mVelocity.x;
      local_d8.y = d_a_arrow::_4193;
      fVar17 = mtx::PSVECSquareMag(&local_d8);
      dVar16 = (double)fVar17;
      if ((double)d_a_arrow::_4193 < dVar16) {
        dVar15 = 1.0 / SQRT(dVar16);
        dVar15 = d_a_arrow::_4194 * dVar15 * (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15);
        dVar15 = d_a_arrow::_4194 * dVar15 * (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15);
        dVar16 = (double)(float)(dVar16 * d_a_arrow::_4194 * dVar15 *
                                          (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15));
      }
      (this->parent).mVelocity.y = (float)((double)(this->parent).mVelocity.y + dVar16);
      (this->parent).mCurrent.mPos.x = (this->parent).mNext.mPos.x;
      (this->parent).mCurrent.mPos.y = (this->parent).mNext.mPos.y;
      (this->parent).mCurrent.mPos.z = (this->parent).mNext.mPos.z;
      *(undefined2 *)&this->field_0x69c = 0x2c00;
      mtx::PSMTXTrans((double)(this->parent).mCurrent.mPos.x,(double)(this->parent).mCurrent.mPos.y,
                      (double)(this->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
      m_Do_mtx::mDoMtx_ZXYrotM
                (&mDoMtx_stack_c::now,(int)(this->parent).mCollisionRot.x,
                 (int)(this->parent).mCollisionRot.y,0);
      mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)&this->field_0x294 + 0x24));
      sVar9 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x287a,&(this->parent).mCurrent.mPos,0x20,sVar9,
                 d_a_arrow::_4288,d_a_arrow::_4288,d_a_arrow::_4289,d_a_arrow::_4289,0);
    }
    else {
      if (iVar13 == 2) {
        (this->parent).parent.parent.mParameters = 2;
        uVar2 = DAT_803898dc;
        *(undefined4 *)&this->field_0x68c = d_a_arrow::_5279;
        *(undefined4 *)&this->field_0x690 = uVar2;
        *(undefined **)&this->field_0x694 = PTR_procStop_Actor_803898e0;
        cVar10 = *(char *)&this->field_0x601;
        if (cVar10 == '\x01') {
          sVar9 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x69da,&(this->parent).mCurrent.mPos,0,sVar9,
                     d_a_arrow::_4288,d_a_arrow::_4288,d_a_arrow::_4289,d_a_arrow::_4289,0);
          *(undefined *)&this->field_0x698 = 0;
        }
        else {
          if (cVar10 == '\x02') {
            sVar9 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x69db,&(this->parent).mCurrent.mPos,0,sVar9,
                       d_a_arrow::_4288,d_a_arrow::_4288,d_a_arrow::_4289,d_a_arrow::_4289,0);
          }
          else {
            if (cVar10 == '\x03') {
              sVar9 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo)
              ;
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x69dc,&(this->parent).mCurrent.mPos,0,sVar9,
                         d_a_arrow::_4288,d_a_arrow::_4288,d_a_arrow::_4289,d_a_arrow::_4289,0);
              *(undefined *)&this->field_0x698 = 0;
            }
          }
        }
        setStopActorMatrix(this);
      }
    }
    goto LAB_800d6934;
  }
  cVar10 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&this->field_0x2a0);
  if (cVar10 == '\0') {
    check_water_in(this);
    goto LAB_800d6934;
  }
  *(float *)&this->field_0x6a8 = (this->field_0x2a0).mLin.mP1.x;
  *(float *)&this->field_0x6ac = (this->field_0x2a0).mLin.mP1.y;
  *(float *)&this->field_0x6b0 = (this->field_0x2a0).mLin.mP1.z;
  ::cXyz::operator_(&cStack132,&(this->parent).mVelocity,d_a_arrow::_5753);
  ::cXyz::operator__(&local_90,&(this->field_0x2a0).mLin.mP1,&cStack132);
  (this->parent).mCurrent.mPos.x = local_90.x;
  (this->parent).mCurrent.mPos.y = local_90.y;
  (this->parent).mCurrent.mPos.z = local_90.z;
  cVar10 = check_water_in(this);
  if (cVar10 != '\0') goto LAB_800d6934;
  bVar1 = *(byte *)&this->field_0x601;
  if (bVar1 == 2) {
    iVar4 = 1;
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
LAB_800d6360:
        iVar4 = -1;
      }
      else {
        iVar4 = 0;
      }
    }
    else {
      if (3 < bVar1) goto LAB_800d6360;
      iVar4 = 2;
    }
  }
  if ((-1 < iVar4) && (*(char *)&this->field_0x6e4 == '\0')) {
    d_kankyo::dKy_arrowcol_chg_on(&(this->parent).mCurrent);
  }
  uVar2 = DAT_803898e8;
  *(undefined4 *)&this->field_0x68c = d_a_arrow::_5301;
  *(undefined4 *)&this->field_0x690 = uVar2;
  *(undefined **)&this->field_0x694 = PTR_procStop_BG_803898ec;
  (this->parent).mStatus = (this->parent).mStatus | 0x4000;
  (this->parent).parent.parent.mParameters = 2;
  this->field_0x604 = 0x28;
  pcVar7 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                           (uint)(ushort)(this->field_0x2a0).mPolyInfo.mBgIndex,
                           (uint)(ushort)(this->field_0x2a0).mPolyInfo.mTriIdx);
  local_e4.z = (pcVar7->mNorm).z;
  local_e4.x = (pcVar7->mNorm).x;
  local_e4.y = d_a_arrow::_4193;
  fVar17 = mtx::PSVECSquareMag(&local_e4);
  dVar16 = (double)fVar17;
  if ((double)d_a_arrow::_4193 < dVar16) {
    dVar15 = 1.0 / SQRT(dVar16);
    dVar15 = d_a_arrow::_4194 * dVar15 * (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15);
    dVar15 = d_a_arrow::_4194 * dVar15 * (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15);
    dVar16 = (double)(float)(dVar16 * d_a_arrow::_4194 * dVar15 *
                                      (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15));
  }
  iVar4 = SComponent::cM_atan2s(-(pcVar7->mNorm).y,(float)-dVar16);
  local_108.x = (short)iVar4;
  iVar4 = SComponent::cM_atan2s(-(pcVar7->mNorm).x,-(pcVar7->mNorm).z);
  local_108.y = (short)iVar4;
  local_108.z = 0;
  mtx::PSMTXTrans((double)(this->parent).mCurrent.mPos.x,(double)(this->parent).mCurrent.mPos.y,
                  (double)(this->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_ZXYrotM(&mDoMtx_stack_c::now,(int)local_108.x,(int)local_108.y,0);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)&this->field_0x6b4);
  cVar10 = *(char *)&this->field_0x601;
  if (cVar10 == '\x01') {
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0x29a,
                       (cXyz *)&this->field_0x6a8,&local_108,(cXyz *)0x0,0xff,
                       (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0x29b,
                       (cXyz *)&this->field_0x6a8,&local_108,(cXyz *)0x0,0xff,
                       (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
    sVar9 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x69da,&(this->parent).mCurrent.mPos,0,sVar9,d_a_arrow::_4288,
               d_a_arrow::_4288,d_a_arrow::_4289,d_a_arrow::_4289,0);
    *(undefined *)&this->field_0x698 = 0;
  }
  else {
    if (cVar10 == '\x02') {
      iVar4 = dBgS::ChkGrpInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                              &(this->field_0x2a0).mPolyInfo,0x200);
      if (iVar4 == 0) {
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0x29e,
                           (cXyz *)&this->field_0x6a8,&local_108,(cXyz *)0x0,0xff,
                           (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0)
        ;
        if (this == (daArrow_c *)0x0) {
          parentUniqueID = 0xffffffff;
        }
        else {
          parentUniqueID = (this->parent).parent.parent.mBsPcId;
        }
        f_op_actor_mng::fopAcM_createChild
                  (0x1df,parentUniqueID,(uint)*(byte *)&this->field_0x601,(cXyz *)&this->field_0x6a8
                   ,(int)(char)(this->parent).mCurrent.mRoomNo,&this->field_0x6e6,(cXyz *)0x0,-1,
                   (undefined *)0x0);
        sVar9 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x69db,&(this->parent).mCurrent.mPos,0,sVar9,
                   d_a_arrow::_4288,d_a_arrow::_4288,d_a_arrow::_4289,d_a_arrow::_4289,0);
      }
      else {
        f_op_actor_mng::fopAcM_create
                  (0x2c,0,(cXyz *)&this->field_0x6a8,(int)(char)(this->parent).mCurrent.mRoomNo,
                   (csXyz *)0x0,(cXyz *)0x0,0xff,(undefined *)0x0);
      }
    }
    else {
      if (cVar10 == '\x03') {
        dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0x2a1,
                           (cXyz *)&this->field_0x6a8,&local_108,(cXyz *)0x0,0xff,
                           (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0)
        ;
        sVar9 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x69dc,&(this->parent).mCurrent.mPos,0,sVar9,
                   d_a_arrow::_4288,d_a_arrow::_4288,d_a_arrow::_4289,d_a_arrow::_4289,0);
        *(undefined *)&this->field_0x698 = 0;
      }
    }
  }
  iVar4 = dBgS::GetAttributeCode
                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&(this->field_0x2a0).mPolyInfo);
  uVar8 = dBgS::GetMtrlSndId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                             &(this->field_0x2a0).mPolyInfo);
  uVar2 = DAT_803898f4;
  if ((*(char *)&this->field_0x601 == '\0') &&
     ((((iVar4 == 3 || (iVar4 == 0x14)) || (iVar4 == 0xf)) || ((iVar4 == 9 || (iVar4 == 0x15)))))) {
    *(undefined4 *)&this->field_0x68c = d_a_arrow::_5320;
    *(undefined4 *)&this->field_0x690 = uVar2;
    *(undefined **)&this->field_0x694 = PTR_procReturn_803898f8;
    (this->parent).parent.parent.mParameters = 3;
    pcVar6 = &(this->parent).mVelocity;
    mtx::PSVECScale(pcVar6,pcVar6,d_a_arrow::_5754);
    local_f0.z = (this->parent).mVelocity.z;
    local_f0.x = (this->parent).mVelocity.x;
    local_f0.y = d_a_arrow::_4193;
    fVar17 = mtx::PSVECSquareMag(&local_f0);
    dVar16 = (double)fVar17;
    if ((double)d_a_arrow::_4193 < dVar16) {
      dVar15 = 1.0 / SQRT(dVar16);
      dVar15 = d_a_arrow::_4194 * dVar15 * (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15);
      dVar15 = d_a_arrow::_4194 * dVar15 * (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15);
      dVar16 = (double)(float)(dVar16 * d_a_arrow::_4194 * dVar15 *
                                        (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15));
    }
    (this->parent).mVelocity.y = (float)((double)(this->parent).mVelocity.y + dVar16);
    (this->parent).mCurrent.mPos.x = (this->parent).mNext.mPos.x;
    (this->parent).mCurrent.mPos.y = (this->parent).mNext.mPos.y;
    (this->parent).mCurrent.mPos.z = (this->parent).mNext.mPos.z;
    *(undefined2 *)&this->field_0x69c = 0x2c00;
    SComponent::cM3d_CalcVecZAngle(pcVar7,&cStack272);
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,0xc,
                       (cXyz *)&this->field_0x6a8,&cStack272,(cXyz *)0x0,0xff,
                       (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
    sVar9 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x287a,&(this->parent).mCurrent.mPos,uVar8,sVar9,
               d_a_arrow::_4288,d_a_arrow::_4288,d_a_arrow::_4289,d_a_arrow::_4289,0);
  }
  else {
    sVar9 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x2879,&(this->parent).mCurrent.mPos,uVar8,sVar9,
               d_a_arrow::_4288,d_a_arrow::_4288,d_a_arrow::_4289,d_a_arrow::_4289,0);
  }
LAB_800d6934:
  bVar11 = Runtime.PPCEABI.H::__ptmf_cmpr((PTMF *)&this->field_0x68c,(PTMF *)&d_a_arrow::_5323);
  if (bVar11 == false) {
    mtx::PSMTXTrans((double)(this->parent).mCurrent.mPos.x,(double)(this->parent).mCurrent.mPos.y,
                    (double)(this->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
    m_Do_mtx::mDoMtx_ZXYrotM
              (&mDoMtx_stack_c::now,(int)(this->parent).mCollisionRot.x,
               (int)(this->parent).mCollisionRot.y,0);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)&this->field_0x294 + 0x24));
  }
  else {
    ::cXyz::operator__(&cStack156,&(this->parent).mCurrent.mPos,(cXyz *)&this->field_0x6a8);
    fVar17 = mtx::PSVECSquareMag(&cStack156);
    dVar16 = (double)fVar17;
    if ((double)d_a_arrow::_4193 < dVar16) {
      dVar15 = 1.0 / SQRT(dVar16);
      dVar15 = d_a_arrow::_4194 * dVar15 * (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15);
      dVar15 = d_a_arrow::_4194 * dVar15 * (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15);
      dVar16 = (double)(float)(dVar16 * d_a_arrow::_4194 * dVar15 *
                                        (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15));
    }
    if (dVar16 <= (double)d_a_arrow::_5755) {
      ::cXyz::operator__(&cStack168,&(this->parent).mCurrent.mPos,(cXyz *)&this->field_0x6a8);
      fVar17 = mtx::PSVECSquareMag(&cStack168);
      dVar16 = (double)fVar17;
      if ((double)d_a_arrow::_4193 < dVar16) {
        dVar15 = 1.0 / SQRT(dVar16);
        dVar15 = d_a_arrow::_4194 * dVar15 * (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15);
        dVar15 = d_a_arrow::_4194 * dVar15 * (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15);
        dVar16 = (double)(float)(dVar16 * d_a_arrow::_4194 * dVar15 *
                                          (d_a_arrow::_4195 - dVar16 * dVar15 * dVar15));
      }
      if ((double)d_a_arrow::_5758 < dVar16) {
        *(undefined *)&this->field_0x6e4 = 1;
      }
    }
    else {
      (this->parent).mVelocity.y = (this->parent).mVelocity.y - d_a_arrow::_5756;
      if ((this->parent).mVelocity.y < d_a_arrow::_5757) {
        (this->parent).mVelocity.y = d_a_arrow::_5757;
      }
      if ((this->parent).mCurrent.mPos.y < *(float *)&this->field_0x6ac) {
        f_op_actor_mng::fopAcM_delete((base_process_class *)this);
        return 1;
      }
    }
    createBlur(this);
    mtx::PSMTXTrans((double)(this->parent).mCurrent.mPos.x,(double)(this->parent).mCurrent.mPos.y,
                    (double)(this->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
    m_Do_mtx::mDoMtx_ZXYrotM
              (&mDoMtx_stack_c::now,(int)(this->parent).mCollisionRot.x,
               (int)(this->parent).mCollisionRot.y,0);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)&this->field_0x294 + 0x24));
    ::cXyz::operator_(&cStack180,&(this->parent).mVelocity,d_a_arrow::_4387);
    ::cXyz::operator__(&local_c0,&(this->parent).mCurrent.mPos,&cStack180);
    local_48 = local_c0.x;
    local_44 = local_c0.y;
    local_40 = local_c0.z;
    *(float *)&this->field_0x4b4 = (this->parent).mCurrent.mPos.x;
    *(float *)&this->field_0x4b8 = (this->parent).mCurrent.mPos.y;
    *(float *)&this->field_0x4bc = (this->parent).mCurrent.mPos.z;
    *(float *)&this->field_0x4c0 = local_c0.x;
    *(float *)&this->field_0x4c4 = local_c0.y;
    *(float *)&this->field_0x4c8 = local_c0.z;
    *(float *)&this->field_0x4d0 = d_a_arrow::_4388;
    mtx::PSVECSubtract((cXyz *)&this->field_0x4c0,(cXyz *)&this->field_0x4b4,
                       &(this->field_0x39c).mObjAt.mVel);
    cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)&this->field_0x39c);
    dCcMassS_Mng::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,
                      (cCcD_Obj *)&this->field_0x39c,1);
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x800d6e50) */
/* __thiscall daArrow_c::procReturn(void) */

undefined4 __thiscall daArrow_c::procReturn(daArrow_c *this)

{
  uint uVar1;
  actor_place *paVar2;
  undefined uVar4;
  char cVar5;
  cM3dGPla *pcVar3;
  int in_r6;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  float fVar9;
  cXyz local_54;
  cXyz cStack72;
  float local_3c;
  float local_38;
  float local_34;
  cXyz local_30;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  (this->parent).mVelocityFwd = d_a_arrow::_4193;
  (this->parent).mVelocity.y = (this->parent).mVelocity.y - d_a_arrow::_5756;
  paVar2 = &(this->parent).mCurrent;
  mtx::PSVECAdd(&paVar2->mPos,&(this->parent).mVelocity,&paVar2->mPos);
  (this->parent).mCollisionRot.x = (this->parent).mCollisionRot.x + *(short *)&this->field_0x69c;
  ::cXyz::operator_(&cStack72,&(this->parent).mVelocity,d_a_arrow::_5753);
  ::cXyz::operator__(&local_54,&(this->parent).mCurrent.mPos,&cStack72);
  local_30.x = local_54.x;
  local_30.y = local_54.y;
  local_30.z = local_54.z;
  uVar4 = daPy_lk_c::setItemWaterEffect
                    ((daPy_lk_c *)this,(fopAc_ac_c *)(uint)*(byte *)&this->field_0x699,1,in_r6);
  *(undefined *)&this->field_0x699 = uVar4;
  ::dBgS_LinChk::Set((dBgS_LinChk *)&this->field_0x2a0,&(this->parent).mNext.mPos,&local_30,
                     &this->parent);
  setBlur(this);
  cVar5 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&this->field_0x2a0);
  if (cVar5 == '\0') {
    if ((*(char *)&this->field_0x69a != '\0') && ((this->parent).mVelocity.y < d_a_arrow::_4193)) {
      f_op_actor_mng::fopAcM_delete((base_process_class *)this);
    }
  }
  else {
    pcVar3 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                             (uint)(ushort)(this->field_0x2a0).mPolyInfo.mBgIndex,
                             (uint)(ushort)(this->field_0x2a0).mPolyInfo.mTriIdx);
    fVar9 = mtx::PSVECSquareMag(&(this->parent).mVelocity);
    dVar8 = (double)fVar9;
    if ((double)d_a_arrow::_4193 < dVar8) {
      dVar7 = 1.0 / SQRT(dVar8);
      dVar7 = d_a_arrow::_4194 * dVar7 * (d_a_arrow::_4195 - dVar8 * dVar7 * dVar7);
      dVar7 = d_a_arrow::_4194 * dVar7 * (d_a_arrow::_4195 - dVar8 * dVar7 * dVar7);
      dVar8 = (double)(float)(dVar8 * d_a_arrow::_4194 * dVar7 *
                                      (d_a_arrow::_4195 - dVar8 * dVar7 * dVar7));
    }
    mtx::C_VECReflect(&(this->parent).mVelocity,pcVar3,&local_3c);
    fVar9 = d_a_arrow::_5814;
    (this->parent).mVelocity.x = d_a_arrow::_5814 * (float)((double)local_3c * dVar8);
    (this->parent).mVelocity.y = fVar9 * (float)((double)local_38 * dVar8);
    (this->parent).mVelocity.z = fVar9 * (float)((double)local_34 * dVar8);
    uVar1 = -(int)*(short *)&this->field_0x69c;
    *(ushort *)&this->field_0x69c =
         (short)((int)uVar1 >> 1) + (ushort)(0 < *(short *)&this->field_0x69c && (uVar1 & 1) != 0);
    pcVar3 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                             (uint)(ushort)(this->field_0x2a0).mPolyInfo.mBgIndex,
                             (uint)(ushort)(this->field_0x2a0).mPolyInfo.mTriIdx);
    if (d_a_arrow::_5814 <= (pcVar3->mNorm).y) {
      *(undefined *)&this->field_0x69a = 1;
    }
  }
  mtx::PSMTXTrans((double)(this->parent).mCurrent.mPos.x,(double)(this->parent).mCurrent.mPos.y,
                  (double)(this->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_ZXYrotM
            (&mDoMtx_stack_c::now,(int)(this->parent).mCollisionRot.x,
             (int)(this->parent).mCollisionRot.y,0);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)&this->field_0x294 + 0x24));
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daArrow_c::procStop_BG(void) */

undefined4 __thiscall daArrow_c::procStop_BG(daArrow_c *this)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  uint uVar4;
  char cVar6;
  int iVar5;
  
  (this->parent).mVelocityFwd = d_a_arrow::_4193;
  cVar6 = cBgS::ChkPolySafe((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                            &(this->field_0x2a0).mPolyInfo);
  if (cVar6 == '\0') {
    f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  }
  else {
    bVar3 = false;
    if (this->field_0x604 < 1) {
      if (*(char *)&this->field_0x600 != '\0') {
        f_op_actor_mng::fopAcM_delete((base_process_class *)this);
        return 1;
      }
    }
    else {
      this->field_0x604 = this->field_0x604 + -1;
      fVar2 = d_a_arrow::_5879 *
              (float)((double)CONCAT44(0x43300000,(int)this->field_0x604 ^ 0x80000000) -
                     d_a_arrow::_5209);
      (this->parent).mCollisionRot.x =
           (short)(int)((float)((double)CONCAT44(0x43300000,(int)(this->field_0x6e6).x ^ 0x80000000)
                               - d_a_arrow::_5209) +
                       d_a_arrow::_5206 * fVar2 * fVar2 *
                       JKernel::JMath::jmaSinTable
                       [(int)(this->field_0x604 * 0x52fb & 0xffffU) >>
                        (JKernel::JMath::jmaSinShift & 0x3f)]);
      (this->parent).mCollisionRot.y = (this->field_0x6e6).y;
      bVar3 = true;
    }
    setBlur(this);
    cVar6 = dBgS::ChkMoveBG(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                            &(this->field_0x2a0).mPolyInfo);
    if (cVar6 != '\0') {
      dBgS::MoveBgTransPos
                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&(this->field_0x2a0).mPolyInfo,true,
                 (cXyz *)&this->field_0x6a8,&(this->parent).mCurrent.mRot,
                 &(this->parent).mCollisionRot);
      bVar3 = true;
    }
    fVar2 = d_a_arrow::_5880;
    if (bVar3) {
      fVar1 = JKernel::JMath::jmaCosTable
              [(int)((int)(this->parent).mCollisionRot.x & 0xffffU) >>
               (JKernel::JMath::jmaSinShift & 0x3f)];
      (this->parent).mCurrent.mPos.x =
           *(float *)&this->field_0x6a8 -
           fVar1 * d_a_arrow::_5880 *
                   JKernel::JMath::jmaSinTable
                   [(int)((int)(this->parent).mCollisionRot.y & 0xffffU) >>
                    (JKernel::JMath::jmaSinShift & 0x3f)];
      (this->parent).mCurrent.mPos.y =
           *(float *)&this->field_0x6ac +
           fVar2 * JKernel::JMath::jmaSinTable
                   [(int)((int)(this->parent).mCollisionRot.x & 0xffffU) >>
                    (JKernel::JMath::jmaSinShift & 0x3f)];
      (this->parent).mCurrent.mPos.z =
           *(float *)&this->field_0x6b0 -
           fVar1 * fVar2 * JKernel::JMath::jmaCosTable
                           [(int)((int)(this->parent).mCollisionRot.y & 0xffffU) >>
                            (JKernel::JMath::jmaSinShift & 0x3f)];
      mtx::PSMTXTrans((double)(this->parent).mCurrent.mPos.x,(double)(this->parent).mCurrent.mPos.y,
                      (double)(this->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
      m_Do_mtx::mDoMtx_ZXYrotM
                (&mDoMtx_stack_c::now,(int)(this->parent).mCollisionRot.x,
                 (int)(this->parent).mCollisionRot.y,0);
      mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)&this->field_0x294 + 0x24));
    }
    if (*(char *)&this->field_0x601 == '\0') {
      ::cM3dGSph::SetC((cM3dGSph *)&this->field_0x5ec,&(this->parent).mCurrent.mPos);
      cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)&this->field_0x4d4
               );
      if (*(int *)&this->field_0x6a0 == 0) {
        *(undefined *)&this->field_0x600 = 1;
        *(undefined *)&this->field_0x698 = 0;
      }
      else {
        *(int *)&this->field_0x6a0 = *(int *)&this->field_0x6a0 + -1;
        uVar4 = *(uint *)&this->field_0x6a0;
        if ((int)uVar4 < 0x3c) {
          if ((uVar4 & 1 ^ uVar4 >> 0x1f) == uVar4 >> 0x1f) {
            *(undefined *)&this->field_0x698 = 0;
          }
          else {
            *(undefined *)&this->field_0x698 = 1;
          }
        }
        else {
          *(undefined *)&this->field_0x698 = 1;
        }
      }
      iVar5 = dCcD_GObjInf::ChkCoHit(&this->field_0x4d4);
      if (iVar5 != 0) {
        d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48e0 =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48e0 + 1;
        f_op_actor_mng::fopAcM_createItemForSimpleDemo
                  ((double)d_a_arrow::_4193,(double)d_a_arrow::_4193,&(this->parent).mCurrent,0x10,
                   0xffffffff,0,0);
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x827,(cXyz *)0x0,0,0,d_a_arrow::_4288,d_a_arrow::_4288,
                   d_a_arrow::_4289,d_a_arrow::_4289,0);
        f_op_actor_mng::fopAcM_delete((base_process_class *)this);
        return 1;
      }
    }
    if (*(char *)&this->field_0x290 != '\0') {
      *(undefined *)&this->field_0x600 = 1;
    }
  }
  return 1;
}


/* __thiscall daArrow_c::procStop_Actor(void) */

undefined4 __thiscall daArrow_c::procStop_Actor(daArrow_c *this)

{
  fopAc_ac_c *pfVar1;
  int local_18 [5];
  
  (this->parent).mVelocityFwd = d_a_arrow::_4193;
  if (*(char *)&this->field_0x600 == '\0') {
    setBlur(this);
    local_18[0] = this->field_0x610;
    pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,local_18);
    if (pfVar1 == (fopAc_ac_c *)0x0) {
      *(undefined *)&this->field_0x600 = 1;
    }
    else {
      setStopActorMatrix(this);
    }
  }
  else {
    f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  }
  return 1;
}


/* __thiscall daArrow_c::procWater(void) */

undefined4 __thiscall daArrow_c::procWater(daArrow_c *this)

{
  if (*(int *)&this->field_0x6a4 < 1) {
    f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  }
  else {
    *(int *)&this->field_0x6a4 = *(int *)&this->field_0x6a4 + -1;
  }
  return 1;
}


/* __thiscall daArrow_c::checkRestMp(void) */

void __thiscall daArrow_c::checkRestMp(daArrow_c *this)

{
  if (*(short *)(&d_a_arrow::use_mp_5906 + (uint)m_keep_type * 2) <=
      (short)(ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic) {
    return;
  }
  m_keep_type = 0;
  return;
}


/* __thiscall daArrow_c::setTypeByPlayer(void) */

void __thiscall daArrow_c::setTypeByPlayer(daArrow_c *this)

{
  checkRestMp(this);
  *(undefined *)&this->field_0x601 = m_keep_type;
  return;
}


/* __thiscall daArrow_c::createInit(void) */

undefined4 __thiscall daArrow_c::createInit(daArrow_c *this)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  if (*(char *)&this->field_0x601 == '\x03') {
    *(undefined4 *)&this->field_0x29c =
         *(undefined4 *)&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x2ec4;
  }
  else {
    *(undefined4 *)&this->field_0x29c =
         *(undefined4 *)&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x2ec0;
  }
  uVar1 = DAT_8038990c;
  *(undefined4 *)&this->field_0x68c = d_a_arrow::_5928;
  *(undefined4 *)&this->field_0x690 = uVar1;
  *(undefined **)&this->field_0x694 = PTR_procWait_80389910;
  setKeepMatrix(this);
  (this->parent).mpCullMtx = (MTX34 *)(*(int *)&this->field_0x294 + 0x24);
  fVar2 = d_a_arrow::_6001;
  (this->parent).mCullSizeBoxMin.x = d_a_arrow::_6001;
  (this->parent).mCullSizeBoxMin.y = fVar2;
  (this->parent).mCullSizeBoxMin.z = d_a_arrow::_4193;
  fVar2 = d_a_arrow::_6002;
  (this->parent).mCullSizeBoxMax.x = d_a_arrow::_6002;
  (this->parent).mCullSizeBoxMax.y = fVar2;
  (this->parent).mCullSizeBoxMax.z = d_a_arrow::_6003;
  ::dCcD_Stts::Init((dCcD_Stts *)&this->field_0x360,10,0xff,&this->parent);
  ::dCcD_Cps::Set((dCcD_Cps *)&this->field_0x39c,(dCcD_SrcCps *)&m_at_cps_src);
  (this->field_0x39c).parent.parent.mpStts = (dCcD_Stts *)&this->field_0x360;
  (this->field_0x39c).mObjAt.parent.mpCallback = d_a_arrow::atHit_CB;
  ::dCcD_Sph::Set((dCcD_Sph *)&this->field_0x4d4,(dCcD_SrcSph *)&m_co_sph_src);
  (this->field_0x4d4).parent.parent.mpStts = (dCcD_Stts *)&this->field_0x360;
  *(undefined2 *)&this->field_0x602 = 0xffff;
  if (*(char *)&this->field_0x601 != '\x03') {
    iVar4 = *(int *)(*(int *)&this->field_0x294 + 4);
    iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 0x2c) + 0x10) + 0x60) + 8);
    *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | 1;
    iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 0x2c) + 8) + 0x60) + 8);
    *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | 1;
    iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 0x2c) + 0xc) + 0x60) + 8);
    *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | 1;
    iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 0x2c) + 0xc) + 0x60) + 4) + 8);
    *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | 1;
  }
  setDrawShapeMaterial(this);
  *(undefined *)&this->field_0x698 = 1;
  *(undefined *)&this->field_0x699 = 0;
  *(undefined *)&this->field_0x69a = 0;
  *(undefined2 *)&this->field_0x69c = 0;
  *(undefined4 *)&this->field_0x6a0 = 300;
  *(undefined4 *)&this->field_0x6a4 = 0;
  *(undefined *)&this->field_0x6e4 = 0;
  *(undefined *)&this->field_0x688 = 0;
  *(undefined *)&this->field_0x664 = 0;
  this->field_0x604 = 0;
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daArrow_c::_execute(void) */

undefined4 __thiscall daArrow_c::_execute(daArrow_c *this)

{
  float fVar1;
  float fVar2;
  daPy_lk_c *pdVar3;
  int iVar4;
  bool bVar5;
  void *extraout_r4;
  void *pvVar6;
  float fVar7;
  cXyz local_48;
  cXyz cStack60;
  cXyz local_30;
  undefined4 local_20;
  uint uStack28;
  
  if (*(char *)&this->field_0x290 != '\0') {
    if (*(char *)&this->field_0x664 == '\0') {
      iVar4 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->vtbl->
                        checkPlayerGuard)();
      if (iVar4 == 0) {
        (this->field_0x39c).mObjAt.mSpl = 0xb;
        (this->field_0x39c).parent.parent.parent.mObjAt.mDamageTypes = LightArrow;
      }
      else {
        (this->field_0x39c).mObjAt.mSpl = 0;
        (this->field_0x39c).parent.parent.parent.mObjAt.mDamageTypes = NormalArrow;
      }
    }
    else {
      (this->field_0x39c).mObjAt.mSpl = 0;
      (this->field_0x39c).parent.parent.parent.mObjAt.mDamageTypes = NormalArrow;
    }
  }
  if (*(short *)&this->field_0x608 != 0) {
    *(short *)&this->field_0x608 = *(short *)&this->field_0x608 + -1;
    pdVar3 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
    bVar5 = false;
    local_30.x = d_a_arrow::_4193;
    local_30.y = d_a_arrow::_6143 + d_s_play::g_regHIO.mChild[0].mFloats[8];
    local_30.z = d_a_arrow::_6144 + d_s_play::g_regHIO.mChild[0].mFloats[9];
    m_Do_mtx::mDoMtx_YrotS
              (SComponent::calc_mtx,
               (int)((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                    mCollisionRot.y);
    SComponent::MtxPosition(&local_30,&cStack60);
    ::cXyz::operator__(&local_48,&(pdVar3->parent).parent.mCurrent.mPos,&cStack60);
    (this->parent).mCurrent.mPos.x = local_48.x;
    (this->parent).mCurrent.mPos.y = local_48.y;
    (this->parent).mCurrent.mPos.z = local_48.z;
    mtx::PSMTXTrans((double)(this->parent).mCurrent.mPos.x,(double)(this->parent).mCurrent.mPos.y,
                    (double)(this->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
    m_Do_mtx::mDoMtx_ZXYrotM
              (&mDoMtx_stack_c::now,(int)(this->parent).mCollisionRot.x,
               (int)(this->parent).mCollisionRot.y,0);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)&this->field_0x294 + 0x24));
    iVar4 = *(int *)&this->field_0x60c;
    if (iVar4 != 0) {
      if (*(short *)&this->field_0x608 == 0) {
        *(undefined4 *)(iVar4 + 0x60) = 0xffffffff;
        *(uint *)(iVar4 + 0x20c) = *(uint *)(iVar4 + 0x20c) | 1;
        *(undefined4 *)&this->field_0x60c = 0;
        bVar5 = true;
      }
      else {
        uStack28 = (int)*(short *)&this->field_0x608 ^ 0x80000000;
        local_20 = 0x43300000;
        fVar7 = d_a_arrow::_5756 * (float)((double)CONCAT44(0x43300000,uStack28) - d_a_arrow::_5209)
        ;
        if (d_a_arrow::_6145 < fVar7) {
          fVar7 = d_a_arrow::_6145;
        }
        fVar1 = (this->parent).mCurrent.mPos.z;
        fVar2 = (this->parent).mCurrent.mPos.y;
        *(float *)(iVar4 + 0x1e4) = (this->parent).mCurrent.mPos.x;
        *(float *)(iVar4 + 0x1e8) = fVar2;
        *(float *)(iVar4 + 0x1ec) = fVar1;
        iVar4 = *(int *)&this->field_0x60c;
        *(float *)(iVar4 + 0x1d8) = fVar7;
        *(float *)(iVar4 + 0x1dc) = fVar7;
        *(float *)(iVar4 + 0x1e0) = fVar7;
        *(float *)(iVar4 + 0x1f0) = fVar7;
        *(float *)(iVar4 + 500) = fVar7;
        *(float *)(iVar4 + 0x1f8) = fVar7;
      }
    }
    if (!bVar5) {
      return 1;
    }
  }
  if (*(short *)&this->field_0x602 == _m_count) {
    *(undefined *)&this->field_0x600 = 1;
  }
  fVar1 = d_a_arrow::_4193;
  fVar7 = *(float *)&this->field_0x660;
  if (fVar7 <= d_a_arrow::_4193) {
    fVar7 = SComponent::cM_rnd(fVar7);
    if (fVar7 < d_a_arrow::_6146) {
      *(float *)&this->field_0x660 = *(float *)&this->field_0x660 + d_a_arrow::_4288;
    }
  }
  else {
    *(float *)&this->field_0x660 = fVar7 + d_a_arrow::_4288;
    uStack28 = (int)*(short *)(*(int *)&this->field_0x29c + 6) ^ 0x80000000;
    local_20 = 0x43300000;
    if ((float)((double)CONCAT44(0x43300000,uStack28) - d_a_arrow::_5209) <=
        *(float *)&this->field_0x660) {
      *(float *)&this->field_0x660 = fVar1;
    }
  }
  setLightEffect(this);
  pvVar6 = extraout_r4;
  bVar5 = Runtime.PPCEABI.H::__ptmf_test((PTMF *)&this->field_0x68c);
  if (bVar5 != false) {
    Runtime.PPCEABI.H::__ptmf_scall((PTMF *)&this->field_0x68c,this,pvVar6);
  }
  (this->parent).mAttentionPos.x = (this->parent).mCurrent.mPos.x;
  (this->parent).mAttentionPos.y = (this->parent).mCurrent.mPos.y;
  (this->parent).mAttentionPos.z = (this->parent).mCurrent.mPos.z;
  (this->parent).mEyePos.x = (this->parent).mCurrent.mPos.x;
  (this->parent).mEyePos.y = (this->parent).mCurrent.mPos.y;
  (this->parent).mEyePos.z = (this->parent).mCurrent.mPos.z;
  setRoomInfo(this);
  return 1;
}


/* __thiscall daArrow_c::_draw(void) */

undefined4 __thiscall daArrow_c::_draw(daArrow_c *this)

{
  int iVar1;
  
  if (*(char *)&this->field_0x698 != '\0') {
    dScnKy_env_light_c::settingTevStruct
              (&d_kankyo::g_env_light,Actor,&(this->parent).mCurrent.mPos,&(this->parent).mTevStr);
    dScnKy_env_light_c::setLightTevColorType
              (&d_kankyo::g_env_light,*(J3DModel **)&this->field_0x294,&(this->parent).mTevStr);
    if (*(char *)&this->field_0x601 != '\x03') {
      iVar1 = *(int *)(*(int *)&this->field_0x298 + 8);
      *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfffffffe;
      iVar1 = *(int *)(*(int *)&this->field_0x298 + 4);
      if (iVar1 != 0) {
        iVar1 = *(int *)(iVar1 + 8);
        *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfffffffe;
      }
    }
    *(undefined4 *)(*(int *)&this->field_0x29c + 8) = *(undefined4 *)&this->field_0x660;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0xc;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x10;
    m_Do_ext::mDoExt_modelUpdateDL(*(J3DModel **)&this->field_0x294);
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
    if (*(char *)&this->field_0x601 != '\x03') {
      iVar1 = *(int *)(*(int *)&this->field_0x298 + 8);
      *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 1;
      iVar1 = *(int *)(*(int *)&this->field_0x298 + 4);
      if (iVar1 != 0) {
        iVar1 = *(int *)(iVar1 + 8);
        *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 1;
      }
    }
  }
  return 1;
}


/* __thiscall daArrow_c::_create(void) */

int __thiscall daArrow_c::_create(daArrow_c *this)

{
  uint uVar1;
  int iVar2;
  
  if (((this->parent).mCondition & Constructed) == 0) {
    if (this != (daArrow_c *)0x0) {
      daArrow_c(this);
    }
    (this->parent).mCondition = (this->parent).mCondition | Constructed;
  }
  checkCreater(this);
  if (*(char *)&this->field_0x290 == '\0') {
    setTypeByPlayer(this);
  }
  else {
    *(undefined *)&this->field_0x601 = 3;
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda == 8) {
    *(undefined *)&this->field_0x601 = 0;
  }
  uVar1 = f_op_actor_mng::fopAcM_entrySolidHeap
                    (&this->parent,d_a_arrow::createHeap_CB,
                     *(ulong *)(&d_a_arrow::heap_size_6231 + (uint)*(byte *)&this->field_0x601 * 4))
  ;
  if ((uVar1 & 0xff) == 0) {
    iVar2 = 5;
  }
  else {
    iVar2 = createInit(this);
    iVar2 = 5 - (uint)(iVar2 != 0);
  }
  return iVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daArrow_c::daArrow_c(void) */

void __thiscall daArrow_c::daArrow_c(daArrow_c *this)

{
  cBgS_GrpPassChk *pcVar1;
  
  fopAc_ac_c::fopAc_ac_c(&this->parent);
  (this->field_0x2a0).parent.vtbl = &cBgS_Chk::__vt;
  (this->field_0x2a0).parent.mpPolyPassChk = (cBgS_PolyPassChk *)0x0;
  (this->field_0x2a0).parent.mpGrpPassChk = (cBgS_GrpPassChk *)0x0;
  (this->field_0x2a0).parent.mbExcludeSameProcID = true;
  (this->field_0x2a0).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  (this->field_0x2a0).mPolyInfo.mTriIdx = -1;
  (this->field_0x2a0).mPolyInfo.mBgIndex = 0x100;
  (this->field_0x2a0).mPolyInfo.mpBgW = (cBgW *)0x0;
  (this->field_0x2a0).mPolyInfo.mProcID = -1;
  (this->field_0x2a0).parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
  (this->field_0x2a0).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
  (this->field_0x2a0).mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
  ::cBgS_LinChk::ct(&this->field_0x2a0);
  *(undefined ***)&this->field_0x2f8 = &::cBgS_PolyPassChk::__vt;
  *(undefined ***)&this->field_0x2f8 = &::dBgS_PolyPassChk::__vt;
  *(undefined *)&this->field_0x2fc = 0;
  *(undefined *)&this->field_0x2fd = 0;
  *(undefined *)&this->field_0x2fe = 0;
  *(undefined *)&this->field_0x2ff = 0;
  *(undefined *)&this->field_0x300 = 0;
  *(undefined *)&this->field_0x301 = 0;
  *(undefined *)&this->field_0x302 = 0;
  *(undefined ***)&this->field_0x304 = &::cBgS_GrpPassChk::__vt;
  *(undefined ***)&this->field_0x304 = &::dBgS_GrpPassChk::__vt;
  *(undefined4 *)&this->field_0x308 = 1;
  *(undefined ***)&this->field_0x2f8 = &::dBgS_Chk::__vt;
  *(undefined ***)&this->field_0x304 = &PTR_80371f68;
  (this->field_0x2a0).parent.vtbl = (cBgS_Chk__vtbl *)&::dBgS_LinChk::__vt;
  (this->field_0x2a0).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80371f38;
  *(undefined ***)&this->field_0x2f8 = &PTR_80371f44;
  *(undefined ***)&this->field_0x304 = &PTR_80371f50;
  (this->field_0x2a0).parent.mpPolyPassChk = (cBgS_PolyPassChk *)&this->field_0x2f8;
  pcVar1 = (cBgS_GrpPassChk *)&this->field_0x2f8;
  if (pcVar1 != (cBgS_GrpPassChk *)0x0) {
    pcVar1 = (cBgS_GrpPassChk *)&this->field_0x304;
  }
  (this->field_0x2a0).parent.mpGrpPassChk = pcVar1;
  (this->field_0x2a0).parent.vtbl = (cBgS_Chk__vtbl *)&dBgS_ArrowLinChk::__vt;
  (this->field_0x2a0).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80389bc4;
  *(undefined ***)&this->field_0x2f8 = &PTR_80389bd0;
  *(undefined ***)&this->field_0x304 = &PTR_80389bdc;
  *(undefined *)&this->field_0x2ff = 1;
  *(uint *)&this->field_0x308 = *(uint *)&this->field_0x308 | 4;
  *(uint *)&this->field_0x308 = *(uint *)&this->field_0x308 | 1;
  ::cBgS_GndChk::cBgS_GndChk(&this->field_0x30c);
  *(undefined ***)&this->field_0x34c = &::cBgS_PolyPassChk::__vt;
  *(undefined ***)&this->field_0x34c = &::dBgS_PolyPassChk::__vt;
  *(undefined *)&this->field_0x350 = 0;
  *(undefined *)&this->field_0x351 = 0;
  *(undefined *)&this->field_0x352 = 0;
  *(undefined *)&this->field_0x353 = 0;
  *(undefined *)&this->field_0x354 = 0;
  *(undefined *)&this->field_0x355 = 0;
  *(undefined *)&this->field_0x356 = 0;
  *(undefined ***)&this->field_0x358 = &::cBgS_GrpPassChk::__vt;
  *(undefined ***)&this->field_0x358 = &::dBgS_GrpPassChk::__vt;
  *(undefined4 *)&this->field_0x35c = 1;
  *(undefined ***)&this->field_0x34c = &::dBgS_Chk::__vt;
  *(undefined ***)&this->field_0x358 = &PTR_80371f68;
  (this->field_0x30c).parent.vtbl = &::dBgS_GndChk::__vt;
  (this->field_0x30c).mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  *(undefined ***)&this->field_0x34c = &PTR_80371f14;
  *(undefined ***)&this->field_0x358 = &PTR_80371f20;
  (this->field_0x30c).parent.mpPolyPassChk = (cBgS_PolyPassChk *)&this->field_0x34c;
  pcVar1 = (cBgS_GrpPassChk *)&this->field_0x34c;
  if (pcVar1 != (cBgS_GrpPassChk *)0x0) {
    pcVar1 = (cBgS_GrpPassChk *)&this->field_0x358;
  }
  (this->field_0x30c).parent.mpGrpPassChk = pcVar1;
  (this->field_0x30c).parent.vtbl = &::dBgS_ObjGndChk::__vt;
  (this->field_0x30c).mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371ed8;
  *(cBgS_PolyPassChk__vtbl **)&this->field_0x34c = &cBgS_PolyPassChk__vtbl_80371ee4;
  *(cBgS_GrpPassChk__vtbl **)&this->field_0x358 = &cBgS_GrpPassChk__vtbl_80371ef0;
  *(undefined *)&this->field_0x350 = 1;
  *(cCcD_Stts__vtbl **)&this->field_0x378 = &cCcD_Stts::__vt;
  ::dCcD_GStts::dCcD_GStts(&this->field_0x37c);
  *(dCcD_Stts__vtbl **)&this->field_0x378 = &::dCcD_Stts::__vt;
  (this->field_0x37c).parent.vtbl = (cCcD_GStts__vtbl *)0x8037ec40;
  dCcD_GObjInf::dCcD_GObjInf(&this->field_0x39c);
  *(undefined ***)&this->field_0x4b0 = &::cCcD_ShapeAttr::__vt;
  *(cM3dGAab__vtbl **)&this->field_0x4ac = &::cM3dGAab::__vt;
  *(undefined ***)&this->field_0x4cc = &::cM3dGLin::__vt;
  *(undefined ***)&this->field_0x4cc = &::cM3dGCps::__vt;
  *(cCcD_ShapeAttr__vtbl **)&this->field_0x4b0 = &::cCcD_CpsAttr::__vt;
  *(undefined **)&this->field_0x4cc = &DAT_8039520c;
  (this->field_0x39c).parent.parent.parent.vtbl = (cCcD_GObjInf__vtbl *)&::dCcD_Cps::__vt;
  *(undefined **)&this->field_0x4b0 = &DAT_80389a8c;
  *(undefined **)&this->field_0x4cc = &DAT_80389ae0;
  dCcD_GObjInf::dCcD_GObjInf(&this->field_0x4d4);
  *(undefined ***)&this->field_0x5e8 = &::cCcD_ShapeAttr::__vt;
  *(cM3dGAab__vtbl **)&this->field_0x5e4 = &::cM3dGAab::__vt;
  *(undefined ***)&this->field_0x5fc = &::cM3dGSph::__vt;
  *(undefined ***)&this->field_0x5e8 = &::cCcD_SphAttr::__vt;
  *(undefined ***)&this->field_0x5fc = &PTR_8039514c;
  (this->field_0x4d4).parent.parent.parent.vtbl = (cCcD_GObjInf__vtbl *)&::dCcD_Sph::__vt;
  *(undefined **)&this->field_0x5e8 = &DAT_803899f8;
  *(undefined **)&this->field_0x5fc = &DAT_80389a4c;
  dPa_followEcallBack::dPa_followEcallBack((dPa_followEcallBack *)&this->field_0x668,0,0);
  return;
}


/* __thiscall dCcD_Sph::~dCcD_Sph(void) */

void __thiscall dCcD_Sph::_dCcD_Sph(dCcD_Sph *this)

{
  short in_r4;
  
  if (this != (dCcD_Sph *)0x0) {
    (this->parent).parent.parent.parent.vtbl = (cCcD_GObjInf__vtbl *)&__vt;
    (this->mSphAttr).parent.vtbl = (cCcD_ShapeAttr__vtbl *)&DAT_803899f8;
    (this->mSphAttr).mSph.vtbl = &DAT_80389a4c;
    if (this != (dCcD_Sph *)0xffffff08) {
      (this->mSphAttr).parent.vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_SphAttr::__vt;
      (this->mSphAttr).mSph.vtbl = (undefined *)&PTR_8039514c;
      if (this != (dCcD_Sph *)0xfffffee8) {
        (this->mSphAttr).mSph.vtbl = (undefined *)&::cM3dGSph::__vt;
      }
      if (this != (dCcD_Sph *)0xffffff08) {
        (this->mSphAttr).parent.vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_ShapeAttr::__vt;
        if (this != (dCcD_Sph *)0xffffff08) {
          (this->mSphAttr).parent.mAab.vtbl = &::cM3dGAab::__vt;
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


/* __thiscall cCcD_SphAttr::~cCcD_SphAttr(void) */

void __thiscall cCcD_SphAttr::_cCcD_SphAttr(cCcD_SphAttr *this)

{
  short in_r4;
  
  if (this != (cCcD_SphAttr *)0x0) {
    (this->parent).vtbl = (cCcD_ShapeAttr__vtbl *)&__vt;
    (this->mSph).vtbl = (undefined *)&PTR_8039514c;
    if (this != (cCcD_SphAttr *)0xffffffe0) {
      (this->mSph).vtbl = (undefined *)&::cM3dGSph::__vt;
    }
    if ((this != (cCcD_SphAttr *)0x0) &&
       ((this->parent).vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_ShapeAttr::__vt,
       this != (cCcD_SphAttr *)0x0)) {
      (this->parent).mAab.vtbl = &::cM3dGAab::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cM3dGSph::~cM3dGSph(void) */

void __thiscall cM3dGSph::_cM3dGSph(cM3dGSph *this)

{
  short in_r4;
  
  if ((this != (cM3dGSph *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dCcD_Cps::~dCcD_Cps(void) */

void __thiscall dCcD_Cps::_dCcD_Cps(dCcD_Cps *this)

{
  short in_r4;
  
  if (this != (dCcD_Cps *)0x0) {
    (this->parent).parent.parent.parent.vtbl = (cCcD_GObjInf__vtbl *)&__vt;
    (this->mAttr).parent.vtbl = (cCcD_ShapeAttr__vtbl *)&DAT_80389a8c;
    (this->mAttr).mCps.parent.vtbl = &DAT_80389ae0;
    if (this != (dCcD_Cps *)0xffffff08) {
      (this->mAttr).parent.vtbl = &::cCcD_CpsAttr::__vt;
      (this->mAttr).mCps.parent.vtbl = &DAT_8039520c;
      if (this != (dCcD_Cps *)0xfffffee8) {
        (this->mAttr).mCps.parent.vtbl = (undefined *)&::cM3dGCps::__vt;
        if (this != (dCcD_Cps *)0xfffffee8) {
          (this->mAttr).mCps.parent.vtbl = (undefined *)&::cM3dGLin::__vt;
        }
      }
      if (this != (dCcD_Cps *)0xffffff08) {
        (this->mAttr).parent.vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_ShapeAttr::__vt;
        if (this != (dCcD_Cps *)0xffffff08) {
          (this->mAttr).parent.mAab.vtbl = &::cM3dGAab::__vt;
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


/* __thiscall cCcD_Stts::~cCcD_Stts(void) */

void __thiscall cCcD_Stts::_cCcD_Stts(cCcD_Stts *this)

{
  short in_r4;
  
  if ((this != (cCcD_Stts *)0x0) && (this->vtbl = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dBgS_ArrowLinChk::~dBgS_ArrowLinChk(void) */

void __thiscall dBgS_ArrowLinChk::_dBgS_ArrowLinChk(dBgS_ArrowLinChk *this)

{
  short in_r4;
  
  if (this != (dBgS_ArrowLinChk *)0x0) {
    (this->parent).parent.parent.vtbl = (cBgS_Chk__vtbl *)&__vt;
    (this->parent).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80389bc4;
    (this->parent).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80389bd0;
    (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80389bdc;
    if (this != (dBgS_ArrowLinChk *)0x0) {
      (this->parent).parent.parent.vtbl = (cBgS_Chk__vtbl *)&::dBgS_LinChk::__vt;
      (this->parent).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80371f38;
      (this->parent).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f44;
      (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f50;
      if (this != (dBgS_ArrowLinChk *)0xffffffa8) {
        (this->parent).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
        (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
        if (this != (dBgS_ArrowLinChk *)0xffffff9c) {
          (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt
          ;
          if (this != (dBgS_ArrowLinChk *)0xffffff9c) {
            (this->parent).mGrpPassChk.parent.vtbl =
                 (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
          }
        }
        if ((this != (dBgS_ArrowLinChk *)0xffffffa8) &&
           ((this->parent).mPolyPassChk.parent.vtbl =
                 (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
           this != (dBgS_ArrowLinChk *)0xffffffa8)) {
          (this->parent).mPolyPassChk.parent.vtbl =
               (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
        }
      }
      if (this != (dBgS_ArrowLinChk *)0x0) {
        (this->parent).parent.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
        (this->parent).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
        if (this != (dBgS_ArrowLinChk *)0xffffffdc) {
          (this->parent).parent.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
        }
        if (this != (dBgS_ArrowLinChk *)0xffffffec) {
          (this->parent).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
        }
        cBgS_Chk::_cBgS_Chk((cBgS_Chk *)this);
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall daArrow_c::_delete(void) */

undefined4 __thiscall daArrow_c::_delete(daArrow_c *this)

{
  (**(code **)(*(int *)&this->field_0x668 + 0x20))();
  return 1;
}


namespace d_a_arrow {

/* __stdcall daArrowCreate(void *) */

void daArrowCreate(daArrow_c *param_1)

{
  ::daArrow_c::_create(param_1);
  return;
}


/* __stdcall daArrowDelete(void *) */

void daArrowDelete(daArrow_c *param_1)

{
  ::daArrow_c::_delete(param_1);
  return;
}


/* __stdcall daArrowExecute(void *) */

void daArrowExecute(daArrow_c *param_1)

{
  ::daArrow_c::_execute(param_1);
  return;
}


/* __stdcall daArrowDraw(void *) */

void daArrowDraw(daArrow_c *param_1)

{
  ::daArrow_c::_draw(param_1);
  return;
}


/* __stdcall daArrowIsDelete(void *) */

undefined4 daArrowIsDelete(void)

{
  return 1;
}

}

/* __thiscall dCcD_Sph::GetShapeAttr(void) */

cCcD_SphAttr * __thiscall dCcD_Sph::GetShapeAttr(dCcD_Sph *this)

{
  if (this == (dCcD_Sph *)0x0) {
    return (cCcD_SphAttr *)0x0;
  }
  return &this->mSphAttr;
}


/* __thiscall cCcD_SphAttr::GetCoCP(void) const */

cM3dGSph * __thiscall cCcD_SphAttr::GetCoCP(cCcD_SphAttr *this)

{
  return &this->mSph;
}


/* __thiscall cCcD_SphAttr::CrossAtTg(cCcD_AabAttr const &,
                                      cXyz *) const */

undefined4 __thiscall
cCcD_SphAttr::CrossAtTg(cCcD_SphAttr *this,cCcD_AabAttr *param_1,cXyz *param_2)

{
  return 0;
}


/* __thiscall cCcD_SphAttr::CrossAtTg(cCcD_PntAttr const &,
                                      cXyz *) const */

undefined4 __thiscall
cCcD_SphAttr::CrossAtTg(cCcD_SphAttr *this,cCcD_PntAttr *param_1,cXyz *param_2)

{
  return 0;
}


/* __thiscall cCcD_SphAttr::CrossAtTg(cCcD_ShapeAttr const &,
                                      cXyz *) const */

void __thiscall cCcD_SphAttr::CrossAtTg(cCcD_SphAttr *this,cCcD_ShapeAttr *param_1,cXyz *param_2)

{
  (*(code *)param_1->vtbl->CrossAtTg_Sph)(param_1,this);
  return;
}


/* __thiscall cCcD_SphAttr::CrossCo(cCcD_AabAttr const &,
                                    float *) const */

undefined4 __thiscall cCcD_SphAttr::CrossCo(cCcD_SphAttr *this,cCcD_AabAttr *param_1,float *param_2)

{
  return 0;
}


/* __thiscall cCcD_SphAttr::CrossCo(cCcD_TriAttr const &,
                                    float *) const */

undefined4 __thiscall cCcD_SphAttr::CrossCo(cCcD_SphAttr *this,cCcD_TriAttr *param_1,float *param_2)

{
  return 0;
}


/* __thiscall cCcD_SphAttr::CrossCo(cCcD_PntAttr const &,
                                    float *) const */

undefined4 __thiscall cCcD_SphAttr::CrossCo(cCcD_SphAttr *this,cCcD_PntAttr *param_1,float *param_2)

{
  return 0;
}


/* __thiscall cCcD_SphAttr::CrossCo(cCcD_ShapeAttr const &,
                                    float *) const */

void __thiscall cCcD_SphAttr::CrossCo(cCcD_SphAttr *this,cCcD_ShapeAttr *param_1,float *param_2)

{
  (*(code *)param_1->vtbl->CrossCo_Sph)(param_1,this);
  return;
}


/* __thiscall dCcD_Cps::GetShapeAttr(void) */

cCcD_CpsAttr * __thiscall dCcD_Cps::GetShapeAttr(dCcD_Cps *this)

{
  if (this == (dCcD_Cps *)0x0) {
    return (cCcD_CpsAttr *)0x0;
  }
  return &this->mAttr;
}


/* __thiscall cCcD_CpsAttr::CrossAtTg(cCcD_AabAttr const &,
                                      cXyz *) const */

undefined4 __thiscall
cCcD_CpsAttr::CrossAtTg(cCcD_CpsAttr *this,cCcD_AabAttr *param_1,cXyz *param_2)

{
  return 0;
}


/* __thiscall cCcD_CpsAttr::CrossAtTg(cCcD_PntAttr const &,
                                      cXyz *) const */

undefined4 __thiscall
cCcD_CpsAttr::CrossAtTg(cCcD_CpsAttr *this,cCcD_PntAttr *param_1,cXyz *param_2)

{
  return 0;
}


/* __thiscall cCcD_CpsAttr::CrossAtTg(cCcD_ShapeAttr const &,
                                      cXyz *) const */

void __thiscall cCcD_CpsAttr::CrossAtTg(cCcD_CpsAttr *this,cCcD_ShapeAttr *param_1,cXyz *param_2)

{
  (*(code *)param_1->vtbl->CrossAtTg_Cps)(param_1,this);
  return;
}


/* __thiscall cCcD_CpsAttr::CrossCo(cCcD_AabAttr const &,
                                    float *) const */

undefined4 __thiscall cCcD_CpsAttr::CrossCo(cCcD_CpsAttr *this,cCcD_AabAttr *param_1,float *param_2)

{
  return 0;
}


/* __thiscall cCcD_CpsAttr::CrossCo(cCcD_TriAttr const &,
                                    float *) const */

undefined4 __thiscall cCcD_CpsAttr::CrossCo(cCcD_CpsAttr *this,cCcD_TriAttr *param_1,float *param_2)

{
  return 0;
}


/* __thiscall cCcD_CpsAttr::CrossCo(cCcD_PntAttr const &,
                                    float *) const */

undefined4 __thiscall cCcD_CpsAttr::CrossCo(cCcD_CpsAttr *this,cCcD_PntAttr *param_1,float *param_2)

{
  return 0;
}


/* __thiscall cCcD_CpsAttr::CrossCo(cCcD_ShapeAttr const &,
                                    float *) const */

void __thiscall cCcD_CpsAttr::CrossCo(cCcD_CpsAttr *this,cCcD_ShapeAttr *param_1,float *param_2)

{
  (*(code *)param_1->vtbl->CrossCo_Cps)(param_1,this);
  return;
}


namespace d_a_arrow {

/* __stdcall cLib_calcTimer<short>(short *) */

int cLib_calcTimer(short *param_1)

{
  if (*param_1 != 0) {
    *param_1 = *param_1 + -1;
  }
  return (int)*param_1;
}

}

/* [thunk]:__thiscall dBgS_ArrowLinChk::~dBgS_ArrowLinChk(void) */

void __thiscall dBgS_ArrowLinChk::_dBgS_ArrowLinChk(dBgS_ArrowLinChk *this)

{
  _dBgS_ArrowLinChk((dBgS_ArrowLinChk *)&this[-1].parent.mPolyPassChk);
  return;
}


/* [thunk]:__thiscall dBgS_ArrowLinChk::~dBgS_ArrowLinChk(void) */

void __thiscall dBgS_ArrowLinChk::_dBgS_ArrowLinChk(dBgS_ArrowLinChk *this)

{
  _dBgS_ArrowLinChk((dBgS_ArrowLinChk *)&this[-1].parent.parent.parent.mProcID);
  return;
}


/* [thunk]:__thiscall dBgS_ArrowLinChk::~dBgS_ArrowLinChk(void) */

void __thiscall dBgS_ArrowLinChk::_dBgS_ArrowLinChk(dBgS_ArrowLinChk *this)

{
  _dBgS_ArrowLinChk((dBgS_ArrowLinChk *)&this[-1].parent.parent.mPolyInfo);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* [thunk]:__thiscall dCcD_Cps::~dCcD_Cps(void) */

void __thiscall dCcD_Cps::_dCcD_Cps(dCcD_Cps *this)

{
  _dCcD_Cps((dCcD_Cps *)&this[-1].parent.parent.parent.parent.mObjTg.parent.mpHitObj);
  return;
}


/* [thunk]:__thiscall dCcD_Cps::~dCcD_Cps(void) */

void __thiscall dCcD_Cps::_dCcD_Cps(dCcD_Cps *this)

{
  _dCcD_Cps((dCcD_Cps *)&this[-1].parent.parent.parent.mAreaFlag);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* [thunk]:__thiscall dCcD_Sph::~dCcD_Sph(void) */

void __thiscall dCcD_Sph::_dCcD_Sph(dCcD_Sph *this)

{
  _dCcD_Sph((dCcD_Sph *)&this[-1].parent.parent.parent.parent.mObjAt.mDamage);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* [thunk]:__thiscall dCcD_Sph::~dCcD_Sph(void) */

void __thiscall dCcD_Sph::_dCcD_Sph(dCcD_Sph *this)

{
  _dCcD_Sph((dCcD_Sph *)&this[-1].parent.parent.parent.parent.mObjCo.parent.mpHitObj);
  return;
}

