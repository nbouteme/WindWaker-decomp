#include <f_op_actor.h>
#include <d_event.h>
#include <JKernel/JKRHeap.h>
#include <f_pc_base.h>
#include <d_meter.h>
#include <f_op_actor_mng.h>
#include <f_pc_leaf.h>
#include <d_map.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <f_pc_method.h>
#include <f_op_draw_tag.h>
#include <f_op_actor_tag.h>
#include <d_demo.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_kankyo.h>
#include <fopAc_cullSizeBox.h>
#include <dEvt_info_c.h>
#include <fopAc_cullSizeSphere.h>
#include <fopAc_ac_c.h>
#include <Demangler/dKy_tevstr_c.h>


namespace f_op_actor {
undefined4 g_fopAc_type;
}
int fopAc_ac_c;

/* __thiscall fopAc_ac_c::fopAc_ac_c(void) */

void __thiscall fopAc_ac_c::fopAc_ac_c(fopAc_ac_c *this)

{
  dEvt_info_c::dEvt_info_c(&this->mEvtInfo);
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


/* __thiscall fopAc_cullSizeSphere::~fopAc_cullSizeSphere(void) */

void __thiscall fopAc_cullSizeSphere::_fopAc_cullSizeSphere(fopAc_cullSizeSphere *this)

{
  short in_r4;
  
  if ((this != (fopAc_cullSizeSphere *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall fopAc_cullSizeBox::~fopAc_cullSizeBox(void) */

void __thiscall fopAc_cullSizeBox::_fopAc_cullSizeBox(fopAc_cullSizeBox *this)

{
  short in_r4;
  
  if ((this != (fopAc_cullSizeBox *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dKy_tevstr_c::~dKy_tevstr_c(void) */

void __thiscall dKy_tevstr_c::_dKy_tevstr_c(dKy_tevstr_c *this)

{
  short in_r4;
  
  if ((this != (dKy_tevstr_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dEvt_info_c::~dEvt_info_c(void) */

void __thiscall dEvt_info_c::_dEvt_info_c(dEvt_info_c *this)

{
  short in_r4;
  
  if ((this != (dEvt_info_c *)0x0) && (this->vtbl = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall fopAc_ac_c::~fopAc_ac_c(void) */

void __thiscall fopAc_ac_c::_fopAc_ac_c(fopAc_ac_c *this)

{
  short in_r4;
  
  if (this != (fopAc_ac_c *)0x0) {
    if (this != (fopAc_ac_c *)0xffffff0c) {
      (this->mEvtInfo).vtbl = &dEvt_info_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace f_op_actor {

/* __stdcall fopAc_IsActor(void *) */

bool fopAc_IsActor(fopAc_ac_c *this)

{
  bool bVar1;
  
  bVar1 = f_pc_base::fpcBs_Is_JustOfType(g_fopAc_type,this->mAcType);
  return bVar1;
}


/* __stdcall fopAc_Draw(void *) */

void fopAc_Draw(fopAc_ac_c *this)

{
  byte bVar2;
  dEvt__MoveApprovalFlag dVar3;
  int iVar1;
  
  bVar2 = d_meter::dMenu_flag();
  if (bVar2 == 0) {
    dVar3 = dEvt_control_c::moveApproval(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,this);
    if (((dVar3 == ForceMove) ||
        (((this->mStatus & ::fopAc_ac_c::stopStatus) == 0 &&
         (((this->mStatus & DoNotDrawIfCulled) == 0 ||
          (iVar1 = f_op_actor_mng::fopAcM_cullingCheck(this), iVar1 == 0)))))) &&
       ((this->mStatus & DoNotDrawNextFrame) == 0)) {
      this->mCondition = this->mCondition & ~DidNotDrawThisFrame;
      f_pc_leaf::fpcLf_DrawMethod(this->mSubMtd,this);
    }
    else {
      this->mCondition = this->mCondition | DidNotDrawThisFrame;
    }
    this->mStatus = this->mStatus & ~DoNotDrawNextFrame;
    if ((-1 < (char)dStage_roomControl_c::mStayNo) && ((this->mStatus & AppearsOnMiniMap) != 0)) {
      dMap_c::drawActorPointMiniMap(this);
    }
    return;
  }
  return;
}


/* __stdcall fopAc_Execute(void *) */

int fopAc_Execute(fopAc_ac_c *this)

{
  float fVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  byte bVar6;
  dEvt__MoveApprovalFlag dVar7;
  profile_method_class *ppVar8;
  uint temp_37f8a50bb5a;
  
  ppVar8 = (profile_method_class *)&DAT_00000001;
  fVar1 = (this->mCurrent).mPos.x;
  uVar2 = (uint)fVar1 & 0x7f800000;
  if (uVar2 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar2 < 0x7f800000) && (uVar2 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"f_op_actor.cpp",0x27d,
               "!(((sizeof(actor->current.pos.x) == sizeof(float)) ? __fpclassifyf((float)(actor->current.pos.x)) : __fpclassifyd((double)(actor->current.pos.x)) ) == 1)"
              );
    m_Do_printf::OSPanic("f_op_actor.cpp",0x27d,"Halt");
  }
  fVar1 = (this->mCurrent).mPos.y;
  uVar2 = (uint)fVar1 & 0x7f800000;
  if (uVar2 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar2 < 0x7f800000) && (uVar2 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"f_op_actor.cpp",0x27e,
               "!(((sizeof(actor->current.pos.y) == sizeof(float)) ? __fpclassifyf((float)(actor->current.pos.y)) : __fpclassifyd((double)(actor->current.pos.y)) ) == 1)"
              );
    m_Do_printf::OSPanic("f_op_actor.cpp",0x27e,"Halt");
  }
  fVar1 = (this->mCurrent).mPos.z;
  uVar2 = (uint)fVar1 & 0x7f800000;
  if (uVar2 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    if ((uVar2 < 0x7f800000) && (uVar2 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 3;
      }
      else {
        iVar4 = 5;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  if (iVar4 == 1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"f_op_actor.cpp",0x27f,
               "!(((sizeof(actor->current.pos.z) == sizeof(float)) ? __fpclassifyf((float)(actor->current.pos.z)) : __fpclassifyd((double)(actor->current.pos.z)) ) == 1)"
              );
    m_Do_printf::OSPanic("f_op_actor.cpp",0x27f,"Halt");
  }
  bVar3 = false;
  fVar1 = (this->mCurrent).mPos.x;
  if ((((_4366 < fVar1) && (fVar1 < _4367)) && (fVar1 = (this->mCurrent).mPos.y, _4366 < fVar1)) &&
     (((fVar1 < _4367 && (fVar1 = (this->mCurrent).mPos.z, _4366 < fVar1)) && (fVar1 < _4367)))) {
    bVar3 = true;
  }
  if (!bVar3) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"f_op_actor.cpp",0x286,
               "-1.0e32f < actor->current.pos.x && actor->current.pos.x < 1.0e32f && -1.0e32f < actor->current.pos.y && actor->current.pos.y < 1.0e32f && -1.0e32f < actor->current.pos.z && actor->current.pos.z < 1.0e32f"
              );
    m_Do_printf::OSPanic("f_op_actor.cpp",0x286,"Halt");
  }
  if (((this->mStatus & DoesNotPause) != 0) ||
     ((bVar6 = d_meter::dMenu_flag(), bVar6 == 0 && (dScnPly_ply_c::pauseTimer == 0)))) {
    (this->mEvtInfo).mCondition = None;
    dVar7 = dEvt_control_c::moveApproval(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,this);
    if ((dVar7 == ForceMove) ||
       (((dVar7 != DontMove && ((this->mStatus & ::fopAc_ac_c::stopStatus) == 0)) &&
        (((this->mStatus & DoNotExecuteIfDidNotDraw) == 0 ||
         ((this->mCondition & DidNotDrawThisFrame) == 0)))))) {
      this->mCondition = this->mCondition & ~DidNotExecuteThisFrame;
      (this->mNext).mPos.x = (this->mCurrent).mPos.x;
      (this->mNext).mPos.y = (this->mCurrent).mPos.y;
      (this->mNext).mPos.z = (this->mCurrent).mPos.z;
      (this->mNext).mRot.x = (this->mCurrent).mRot.x;
      (this->mNext).mRot.y = (this->mCurrent).mRot.y;
      (this->mNext).mRot.z = (this->mCurrent).mRot.z;
      (this->mNext).mRoomNo = (this->mCurrent).mRoomNo;
      (this->mNext).field_0x13 = (this->mCurrent).field_0x13;
      ppVar8 = this->mSubMtd;
      f_pc_method::fpcMtd_Execute(ppVar8,this);
    }
    else {
      this->mCondition = this->mCondition | DidNotExecuteThisFrame;
    }
    fVar1 = (this->mCurrent).mPos.x;
    temp_37f8a50bb5a = (uint)fVar1 & 0x7f800000;
    if (temp_37f8a50bb5a == 0x7f800000) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 2;
      }
      else {
        iVar4 = 1;
      }
    }
    else {
      if ((temp_37f8a50bb5a < 0x7f800000) && (temp_37f8a50bb5a == 0)) {
        if (((uint)fVar1 & 0x7fffff) == 0) {
          iVar4 = 3;
        }
        else {
          iVar4 = 5;
        }
      }
      else {
        iVar4 = 4;
      }
    }
    if (iVar4 == 1) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar5,"f_op_actor.cpp",0x2b4,
                 "!(((sizeof(actor->current.pos.x) == sizeof(float)) ? __fpclassifyf((float)(actor->current.pos.x)) : __fpclassifyd((double)(actor->current.pos.x)) ) == 1)"
                );
      m_Do_printf::OSPanic("f_op_actor.cpp",0x2b4,"Halt");
    }
    fVar1 = (this->mCurrent).mPos.y;
    uVar2 = (uint)fVar1 & 0x7f800000;
    if (uVar2 == 0x7f800000) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 2;
      }
      else {
        iVar4 = 1;
      }
    }
    else {
      if ((uVar2 < 0x7f800000) && (uVar2 == 0)) {
        if (((uint)fVar1 & 0x7fffff) == 0) {
          iVar4 = 3;
        }
        else {
          iVar4 = 5;
        }
      }
      else {
        iVar4 = 4;
      }
    }
    if (iVar4 == 1) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar5,"f_op_actor.cpp",0x2b5,
                 "!(((sizeof(actor->current.pos.y) == sizeof(float)) ? __fpclassifyf((float)(actor->current.pos.y)) : __fpclassifyd((double)(actor->current.pos.y)) ) == 1)"
                );
      m_Do_printf::OSPanic("f_op_actor.cpp",0x2b5,"Halt");
    }
    fVar1 = (this->mCurrent).mPos.z;
    uVar2 = (uint)fVar1 & 0x7f800000;
    if (uVar2 == 0x7f800000) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar4 = 2;
      }
      else {
        iVar4 = 1;
      }
    }
    else {
      if ((uVar2 < 0x7f800000) && (uVar2 == 0)) {
        if (((uint)fVar1 & 0x7fffff) == 0) {
          iVar4 = 3;
        }
        else {
          iVar4 = 5;
        }
      }
      else {
        iVar4 = 4;
      }
    }
    if (iVar4 == 1) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar5,"f_op_actor.cpp",0x2b6,
                 "!(((sizeof(actor->current.pos.z) == sizeof(float)) ? __fpclassifyf((float)(actor->current.pos.z)) : __fpclassifyd((double)(actor->current.pos.z)) ) == 1)"
                );
      m_Do_printf::OSPanic("f_op_actor.cpp",0x2b6,"Halt");
    }
    bVar3 = false;
    fVar1 = (this->mCurrent).mPos.x;
    if (((((_4366 < fVar1) && (fVar1 < _4367)) && (fVar1 = (this->mCurrent).mPos.y, _4366 < fVar1))
        && ((fVar1 < _4367 && (fVar1 = (this->mCurrent).mPos.z, _4366 < fVar1)))) && (fVar1 < _4367)
       ) {
      bVar3 = true;
    }
    if (!bVar3) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar5,"f_op_actor.cpp",0x2bd,
                 "-1.0e32f < actor->current.pos.x && actor->current.pos.x < 1.0e32f && -1.0e32f < actor->current.pos.y && actor->current.pos.y < 1.0e32f && -1.0e32f < actor->current.pos.z && actor->current.pos.z < 1.0e32f"
                );
      m_Do_printf::OSPanic("f_op_actor.cpp",0x2bd,"Halt");
    }
  }
  return (int)ppVar8;
}


/* __stdcall fopAc_IsDelete(void *) */

int fopAc_IsDelete(fopAc_ac_c *this)

{
  int iVar1;
  
  iVar1 = f_pc_method::fpcMtd_IsDelete(this->mSubMtd,this);
  if (iVar1 == 1) {
    f_op_draw_tag::fopDwTg_DrawQTo(&this->mDwTg);
  }
  return iVar1;
}


/* __stdcall fopAc_Delete(void *) */

int fopAc_Delete(fopAc_ac_c *this)

{
  int iVar1;
  dDemo_actor_c *pDemoActor;
  
  iVar1 = f_pc_method::fpcMtd_Delete(&this->mSubMtd->parent,this);
  if (iVar1 == 1) {
    f_op_actor_tag::fopAcTg_ActorQTo(&this->mAcTg);
    f_op_draw_tag::fopDwTg_DrawQTo(&this->mDwTg);
    f_op_actor_mng::fopAcM_DeleteHeap(this);
    pDemoActor = dDemo_object_c::getActor
                           (&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mDemoObj,
                            this->mDemoObjId);
    if (pDemoActor != (dDemo_actor_c *)0x0) {
      dDemo_actor_c::setActor(pDemoActor,(fopAc_ac_c *)0x0);
    }
    JAIZelBasic::seDeleteObject(JAIZelBasic::zel_basic,(Vec *)&this->mEyePos);
    JAIZelBasic::seDeleteObject(JAIZelBasic::zel_basic,(Vec *)&this->mCurrent);
  }
  return iVar1;
}


/* __stdcall fopAc_Create(void *) */

int fopAc_Create(fopAc_ac_c *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  fopAcM_prm_class *pPrm;
  f_pc_profile__Profile_Actor *pProf;
  
  if ((this->parent).parent.mInitState == 0) {
    pProf = (this->parent).parent.mpProf;
    iVar3 = f_pc_base::fpcBs_MakeOfType(&g_fopAc_type);
    this->mAcType = iVar3;
    this->mSubMtd = pProf->mpMtd2;
    f_op_actor_tag::fopAcTg_Init(&this->mAcTg,this);
    f_op_actor_tag::fopAcTg_ToActorQ(&this->mAcTg);
    f_op_draw_tag::fopDwTg_Init(&this->mDwTg,this);
    this->mStatus = pProf->mStatus;
    this->mActorType = pProf->mActorType;
    this->mCullType = pProf->mCullType;
    pPrm = (fopAcM_prm_class *)(this->parent).parent.mpUserData;
    if (pPrm != (fopAcM_prm_class *)0x0) {
      (this->parent).parent.mParameters = pPrm->mParameters;
      (this->mOrig).mPos.x = (pPrm->mPos).x;
      (this->mOrig).mPos.y = (pPrm->mPos).y;
      (this->mOrig).mPos.z = (pPrm->mPos).z;
      (this->mOrig).mRot.x = (pPrm->mRot).x;
      (this->mOrig).mRot.y = (pPrm->mRot).y;
      (this->mOrig).mRot.z = (pPrm->mRot).z;
      (this->mCollisionRot).x = (pPrm->mRot).x;
      (this->mCollisionRot).y = (pPrm->mRot).y;
      (this->mCollisionRot).z = (pPrm->mRot).z;
      this->mParentPcId = pPrm->mParentPcId;
      this->mSubtype = pPrm->mSubtype;
      this->mGbaName = pPrm->mGbaName;
      fVar1 = 0_1 * (float)((double)CONCAT44(0x43300000,(uint)pPrm->mScaleZ) - _4439);
      fVar2 = 0_1 * (float)((double)CONCAT44(0x43300000,(uint)pPrm->mScaleY) - _4439);
      (this->mScale).x = 0_1 * (float)((double)CONCAT44(0x43300000,(uint)pPrm->mScaleX) - _4439);
      (this->mScale).y = fVar2;
      (this->mScale).z = fVar1;
      this->mSetID = pPrm->mEnemyNo;
      (this->mOrig).mRoomNo = pPrm->mRoomNo;
    }
    (this->mNext).mPos.x = (this->mOrig).mPos.x;
    (this->mNext).mPos.y = (this->mOrig).mPos.y;
    (this->mNext).mPos.z = (this->mOrig).mPos.z;
    (this->mNext).mRot.x = (this->mOrig).mRot.x;
    (this->mNext).mRot.y = (this->mOrig).mRot.y;
    (this->mNext).mRot.z = (this->mOrig).mRot.z;
    (this->mNext).mRoomNo = (this->mOrig).mRoomNo;
    (this->mNext).field_0x13 = (this->mOrig).field_0x13;
    (this->mCurrent).mPos.x = (this->mOrig).mPos.x;
    (this->mCurrent).mPos.y = (this->mOrig).mPos.y;
    (this->mCurrent).mPos.z = (this->mOrig).mPos.z;
    (this->mCurrent).mRot.x = (this->mOrig).mRot.x;
    (this->mCurrent).mRot.y = (this->mOrig).mRot.y;
    (this->mCurrent).mRot.z = (this->mOrig).mRot.z;
    (this->mCurrent).mRoomNo = (this->mOrig).mRoomNo;
    (this->mCurrent).field_0x13 = (this->mOrig).field_0x13;
    (this->mEyePos).x = (this->mOrig).mPos.x;
    (this->mEyePos).y = (this->mOrig).mPos.y;
    (this->mEyePos).z = (this->mOrig).mPos.z;
    this->mVelocityYMin = _100_0;
    this->mAttentionDistances[0] = 1;
    this->mAttentionDistances[1] = 2;
    this->mAttentionDistances[2] = 3;
    this->mAttentionDistances[3] = 7;
    this->mAttentionDistances[4] = 8;
    this->mAttentionDistances[7] = 0xf;
    this->mAttentionDistances[5] = 0x10;
    this->mAttentionDistances[6] = 0x10;
    (this->mAttentionPos).x = (this->mOrig).mPos.x;
    (this->mAttentionPos).y = (this->mOrig).mPos.y;
    (this->mAttentionPos).z = (this->mOrig).mPos.z;
    d_kankyo::dKy_tevstr_init(&this->mTevStr,(this->mOrig).mRoomNo,0xff);
  }
  iVar3 = f_pc_method::fpcMtd_Create(&this->mSubMtd->parent,this);
  if (iVar3 == 4) {
    iVar4 = f_pc_leaf::fpcLf_GetPriority(&this->parent);
    f_op_draw_tag::fopDwTg_ToDrawQ(&this->mDwTg,(int)(short)iVar4);
  }
  return iVar3;
}

