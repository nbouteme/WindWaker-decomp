#include <d_attention.h>
#include <JKernel/JKRHeap.h>
#include <d_attention.h>
#include <m_Do_ext.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_resorce.h>
#include <J3DGraphAnimator/J3DAnimation.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <os/OSCache.h>
#include <d_com_inf_game.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <SComponent/c_angle.h>
#include <f_op_actor_mng.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <mtx/mtx.h>
#include <J3DGraphAnimator/J3DMaterialAttach.h>
#include <dAttLook_c.h>
#include <dAttCatch_c.h>
#include <dAttention_c.h>
#include <dAttDraw_c.h>
#include <dAttParam_c.h>
#include <dAttDraw_CallBack_c.h>
#include <dAttHint_c.h>
#include <dAttList_c.h>


/* __thiscall dAttParam_c::dAttParam_c(long) */

void __thiscall dAttParam_c::dAttParam_c(dAttParam_c *this,long param_1)

{
  this->vtbl = &__vt;
  this->field_0x4 = d_attention::45_0;
  this->field_0x8 = d_attention::30_0;
  this->field_0xc = d_attention::90_0;
  this->field_0x0 = 1;
  this->field_0x18 = d_attention::_0_9;
  this->field_0x10 = d_attention::3000_0;
  this->field_0x14 = d_attention::1000_0;
  return;
}


/* __thiscall dAttParam_c::~dAttParam_c(void) */

void __thiscall dAttParam_c::_dAttParam_c(dAttParam_c *this)

{
  short in_r4;
  
  if ((this != (dAttParam_c *)0x0) && (this->vtbl = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dAttDraw_CallBack_c::execute(unsigned short,
                                           J3DTransformInfo *) */

undefined4 __thiscall
dAttDraw_CallBack_c::execute(dAttDraw_CallBack_c *this,ushort param_1,J3DTransformInfo *param_2)

{
  if (param_1 == 0) {
    (param_2->mTranslation).y =
         (param_2->mTranslation).y * (d_attention::_4017 + d_s_play::g_regHIO.mChild[6].mFloats[17])
    ;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall dAttention_c::dAttention_c(fopAc_ac_c *,
                                         unsigned long) */

void __thiscall dAttention_c::dAttention_c(dAttention_c *this,fopAc_ac_c *pActor,ulong playerNo)

{
  bool bVar1;
  JKRSolidHeap *pJVar2;
  ulong uVar3;
  J3DModelData *pModelData;
  J3DAnmColor *this_00;
  mDoExt_McaMorf *this_01;
  J3DAnmTransformKey *pAnmRes;
  undefined4 uVar4;
  int iVar5;
  EVP_PKEY_CTX *extraout_r4;
  EVP_PKEY_CTX *ctx;
  EVP_PKEY_CTX *extraout_r4_00;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  *(mDoExt_McaMorfCallBack1_c__vtbl **)&this->field_0x8 = &mDoExt_McaMorfCallBack1_c::__vt;
  *(undefined1 **)&this->field_0x8 = &dAttDraw_CallBack_c::__vt;
  (this->mAttParam).vtbl = &dAttParam_c::__vt;
  this->mpPlayer = (daPy_lk_c *)pActor;
  this->mPlayerNo = playerNo;
  initList(this,0xffffffff);
  this->mFlagMask = 0;
  this->field_0x1c = -1;
  this->field_0x19 = 0;
  this->mLockOnState = 0;
  this->field_0x1a = 0;
  this->field_0x1b = 0;
  this->mLockOnTargetBsPcID = -1;
  pJVar2 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(0x3600,0);
  this->mpHeap = &pJVar2->parent;
  if (this->mpHeap == (JKRHeap *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_attention.cpp",0xb9,"heap != 0");
    m_Do_printf::OSPanic("d_attention.cpp",0xb9,"Halt");
  }
  pModelData = (J3DModelData *)
               dRes_control_c::getRes
                         ("Always",0x3d,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40
                         );
  if (pModelData == (J3DModelData *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_attention.cpp",0xbe,"modelData != 0");
    m_Do_printf::OSPanic("d_attention.cpp",0xbe,"Halt");
  }
  uVar6 = 0;
  uVar7 = 0;
  iVar8 = 0;
  do {
    this_00 = (J3DAnmColor *)
              dRes_control_c::getRes
                        ("Always",(uint)*(ushort *)((int)d_attention::l_bpkIdx_4021 + iVar8),
                         d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (this_00 == (J3DAnmColor *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_attention.cpp",0xcc,"anmCol != 0");
      m_Do_printf::OSPanic("d_attention.cpp",0xcc,"Halt");
    }
    J3DAnmColor::searchUpdateMaterialID(this_00,pModelData);
    if (uVar6 < *(ushort *)(this_00 + 0x18)) {
      uVar6 = (uint)*(ushort *)(this_00 + 0x18);
    }
    uVar7 = uVar7 + 1;
    iVar8 = iVar8 + 2;
  } while (uVar7 < 5);
  iVar9 = 0;
  iVar8 = 0;
  do {
    this_01 = (mDoExt_McaMorf *)JKernel::operator_new(0xb4);
    if (this_01 != (mDoExt_McaMorf *)0x0) {
      pAnmRes = (J3DAnmTransformKey *)
                dRes_control_c::getRes
                          ("Always",0x19,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                           0x40);
      this_01 = mDoExt_McaMorf::mDoExt_McaMorf
                          (this_01,1,pModelData,(mDoExt_McaMorfCallBack1_c *)&this->field_0x8,
                           (mDoExt_McaMorfCallBack2_c *)0x0,pAnmRes,Repeat,d_attention::1_0,0,-1,1,
                           (void *)0x0,0x80000,0x1000003);
    }
    *(mDoExt_McaMorf **)((int)this->mLockOnList + iVar8 + -0x1c) = this_01;
    bVar1 = false;
    iVar5 = *(int *)((int)this->mLockOnList + iVar8 + -0x1c);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0x50) != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar3,"d_attention.cpp",0xe3,"draw[i].anm != 0 && draw[i].anm->getModel() != 0");
      m_Do_printf::OSPanic("d_attention.cpp",0xe3,"Halt");
    }
    *(undefined4 *)((int)this->mLockOnList + iVar8 + -0x18) = 0;
    uVar4 = JKernel::operator_new__(uVar6 * 8 + 0x10);
    uVar4 = Runtime.PPCEABI.H::__construct_new_array
                      (uVar4,J3DMatColorAnm::J3DMatColorAnm,J3DMatColorAnm::_J3DMatColorAnm,8,uVar6)
    ;
    *(undefined4 *)((int)this->mLockOnList + iVar8 + -0x14) = uVar4;
    iVar9 = iVar9 + 1;
    iVar8 = iVar8 + 0xc;
  } while (iVar9 < 2);
  m_Do_ext::mDoExt_restoreCurrentHeap();
  ctx = extraout_r4;
  uVar6 = m_Do_ext::mDoExt_adjustSolidHeap((JKRSolidHeap *)this->mpHeap);
  if (-1 < (int)uVar6) {
    os::DCStoreRangeNoSync(this->mpHeap->mpDataBegin,this->mpHeap->mSize);
    ctx = extraout_r4_00;
  }
  this->field_0x28 = 0xff;
  this->mFlags = 0;
  dAttHint_c::init(&this->mHint,ctx);
  dAttCatch_c::init(&this->mCatch,ctx);
  dAttLook_c::init(&this->field_0x148,ctx);
  dAttLook_c::init(&this->field_0x158,ctx);
  if (&this->mAttParam != (dAttParam_c *)0x0) {
    dAttParam_c::dAttParam_c(&this->mAttParam,0);
  }
  return;
}


/* __thiscall dAttention_c::~dAttention_c(void) */

void __thiscall dAttention_c::_dAttention_c(dAttention_c *this)

{
  short in_r4;
  
  if (this != (dAttention_c *)0x0) {
    if (this->mpHeap != (JKRHeap *)0x0) {
      m_Do_ext::mDoExt_destroySolidHeap();
      this->mpHeap = (JKRHeap *)0x0;
    }
    dAttParam_c::_dAttParam_c(&this->mAttParam);
    if (this != (dAttention_c *)&DAT_fffffff8) {
      *(undefined1 **)&this->field_0x8 = &dAttDraw_CallBack_c::__vt;
      if (this != (dAttention_c *)&DAT_fffffff8) {
        *(mDoExt_McaMorfCallBack1_c__vtbl **)&this->field_0x8 = &mDoExt_McaMorfCallBack1_c::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dAttention_c::GetActionList(long) */

int __thiscall dAttention_c::GetActionList(dAttention_c *this,long param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = this->mActionNum;
  if (iVar2 != 0) {
    iVar1 = this->mActionOffs + param_1;
    return (int)this + (iVar1 - (iVar1 / iVar2) * iVar2) * 0x10 + 0xdc;
  }
  return 0;
}


/* __thiscall dAttention_c::GetLockonList(long) */

dAttList_c * __thiscall dAttention_c::GetLockonList(dAttention_c *this,long idx)

{
  int iVar1;
  int iVar2;
  
  iVar2 = this->mLockOnNum;
  if (iVar2 != 0) {
    iVar1 = this->mLockOnOffs + idx;
    return (dAttList_c *)((int)this + (iVar1 - (iVar1 / iVar2) * iVar2) * 0x10 + 0x54);
  }
  return (dAttList_c *)0x0;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dAttention_c::getActionBtnB(void) */

dAttList_c * __thiscall dAttention_c::getActionBtnB(dAttention_c *this)

{
  dAttList_c *pEntry;
  uint uVar1;
  dAttention_c *pEntry_;
  fopAc_ac_c *pActor;
  int iVar2;
  int iVar3;
  
  pEntry = GetLockonList(this,0);
  if ((((pEntry == (dAttList_c *)0x0) ||
       (pActor = dAttList_c::getActor(pEntry), pActor == (fopAc_ac_c *)0x0)) ||
      (pEntry->mType != LockOn_Talk)) ||
     ((uVar1 = LockonTruth(this), (uVar1 & 0xff) == 0 ||
      (pActor = dAttList_c::getActor(pEntry), (pActor->mAttentionFlags & TalkFlag_NoTalk) != 0)))) {
    if (this->mActionNum == 0) {
      pEntry = (dAttList_c *)0x0;
    }
    else {
      iVar3 = 0;
      for (iVar2 = 0; iVar2 < this->mActionNum; iVar2 = iVar2 + 1) {
        pEntry_ = (dAttention_c *)((int)this->mLockOnList + iVar3 + -0x54);
        if (pEntry_->mActionList[0].mType != Action_Talk) {
          return pEntry_->mActionList;
        }
        pActor = dAttList_c::getActor(pEntry_->mActionList);
        if ((pActor->mAttentionFlags & TalkFlag_NoTalk) == 0) {
          return pEntry_->mActionList;
        }
        iVar3 = iVar3 + 0x10;
      }
      pEntry = (dAttList_c *)0x0;
    }
  }
  return pEntry;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dAttention_c::getActionBtnXYZ_local(int) */

dAttList_c * __thiscall dAttention_c::getActionBtnXYZ_local(dAttention_c *this,int button)

{
  dAttList_c *pEntry;
  fopAc_ac_c *pfVar1;
  uint uVar2;
  short sVar3;
  dAttention_c *pAttention;
  code *pcVar4;
  int iVar5;
  int iVar6;
  
  pEntry = GetLockonList(this,0);
  if ((((pEntry == (dAttList_c *)0x0) ||
       (pfVar1 = dAttList_c::getActor(pEntry), pfVar1 == (fopAc_ac_c *)0x0)) ||
      (pEntry->mType != LockOn_Talk)) || (uVar2 = LockonTruth(this), (uVar2 & 0xff) == 0)) {
    if (this->mActionNum != 0) {
      iVar6 = 0;
      for (iVar5 = 0; iVar5 < this->mActionNum; iVar5 = iVar5 + 1) {
        pAttention = (dAttention_c *)((int)this->mLockOnList + iVar6 + -0x54);
        if (pAttention->mActionList[0].mType == Action_Talk) {
          pfVar1 = dAttList_c::getActor(pAttention->mActionList);
          if (((pfVar1->mEvtInfo).mCondition & CanTalkItem) == CanTalkItem) {
            pcVar4 = (code *)(pfVar1->mEvtInfo).mpCheckCB;
            if (pcVar4 == (code *)0x0) {
              sVar3 = 1;
            }
            else {
              sVar3 = (*pcVar4)(pfVar1,button);
            }
            if (sVar3 != 0) {
              return pAttention->mActionList;
            }
          }
        }
        iVar6 = iVar6 + 0x10;
      }
    }
  }
  else {
    pfVar1 = dAttList_c::getActor(pEntry);
    if (((pfVar1->mEvtInfo).mCondition & CanTalkItem) == CanTalkItem) {
      pcVar4 = (code *)(pfVar1->mEvtInfo).mpCheckCB;
      if (pcVar4 == (code *)0x0) {
        sVar3 = 1;
      }
      else {
        sVar3 = (*pcVar4)(pfVar1,button);
      }
      if (sVar3 != 0) {
        return pEntry;
      }
    }
  }
  return (dAttList_c *)0x0;
}


/* __thiscall dAttention_c::getActionBtnX(void) */

dAttList_c * __thiscall dAttention_c::getActionBtnX(dAttention_c *this)

{
  char cVar2;
  dAttList_c *pdVar1;
  
  cVar2 = d_com_inf_game::dComIfGs_checkGetItemNum
                    (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[0]);
  if (cVar2 == '\0') {
    pdVar1 = (dAttList_c *)0x0;
  }
  else {
    pdVar1 = getActionBtnXYZ_local(this,0);
  }
  return pdVar1;
}


/* __thiscall dAttention_c::getActionBtnY(void) */

dAttList_c * __thiscall dAttention_c::getActionBtnY(dAttention_c *this)

{
  char cVar2;
  dAttList_c *pdVar1;
  
  cVar2 = d_com_inf_game::dComIfGs_checkGetItemNum
                    (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[1]);
  if (cVar2 == '\0') {
    pdVar1 = (dAttList_c *)0x0;
  }
  else {
    pdVar1 = getActionBtnXYZ_local(this,1);
  }
  return pdVar1;
}


/* __thiscall dAttention_c::getActionBtnZ(void) */

dAttList_c * __thiscall dAttention_c::getActionBtnZ(dAttention_c *this)

{
  char cVar2;
  dAttList_c *pdVar1;
  
  cVar2 = d_com_inf_game::dComIfGs_checkGetItemNum
                    (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[2]);
  if (cVar2 == '\0') {
    pdVar1 = (dAttList_c *)0x0;
  }
  else {
    pdVar1 = getActionBtnXYZ_local(this,2);
  }
  return pdVar1;
}


/* __thiscall dAttention_c::chkAttMask(unsigned long,
                                       unsigned long) */

uint __thiscall dAttention_c::chkAttMask(dAttention_c *this,ulong type,ulong mask)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = loc_type_num;
  if (0 < loc_type_num) {
    do {
      if (type == (int)*(short *)((int)&loc_type_tbl[0].mType + iVar1)) {
        return mask & *(ushort *)((int)&loc_type_tbl[0].mAttentionFlagMask + iVar1);
      }
      iVar1 = iVar1 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 1;
}


namespace d_attention {

/* __stdcall check_event_condition(unsigned long,
                                   unsigned short) */

undefined4 check_event_condition(int locType,dEvt__ActorCondition behaviorFlags)

{
  if (locType != 4) {
    if (locType < 4) {
      if ((locType != 2) &&
         (((1 < locType || (0 < locType)) && ((behaviorFlags & CanTalk) == None)))) {
        return 1;
      }
    }
    else {
      if (locType == 6) {
        if ((behaviorFlags & CanDoor) == None) {
          return 1;
        }
      }
      else {
        if ((locType < 6) && ((behaviorFlags & CanDoor) == None)) {
          return 1;
        }
      }
    }
  }
  return 0;
}


/* __stdcall check_flontofplayer(unsigned long,
                                 short,
                                 short) */

undefined4 check_flontofplayer(uint bits,short angle1,short angle2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (angle1 < 0) {
    angle1 = -angle1;
  }
  if (angle2 < 0) {
    angle2 = -angle2;
  }
  iVar1 = 0;
  iVar2 = 0;
  iVar3 = 3;
  do {
    if ((bits & *(uint *)((int)ftp_table_4271 + iVar2)) != 0) {
      if (*(short *)((int)ang_table_4272 + iVar1) < angle1) {
        return 1;
      }
    }
    iVar1 = iVar1 + 2;
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar1 = 0x10;
  iVar2 = 0x20;
  iVar3 = 6;
  do {
    if ((bits & *(uint *)((int)ftp_table_4271 + iVar2)) != 0) {
      if (*(short *)((int)ftp_table_4271 + iVar1 + 0x1e) < angle2) {
        return 1;
      }
    }
    iVar1 = iVar1 + -2;
    iVar2 = iVar2 + -4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 0;
}


/* __stdcall distace_weight(float,
                            short,
                            float) */

double distace_weight(double distance,short angle,double distanceAngleWeight)

{
  float fVar1;
  
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)angle ^ 0x80000000) - _4304) / 32768_0;
  return (double)(float)(distance *
                        (double)((float)((double)1_0 - distanceAngleWeight) +
                                (float)(distanceAngleWeight * (double)(fVar1 * fVar1))));
}


/* __stdcall distace_angle_adjust(float,
                                  short,
                                  float) */

double distace_angle_adjust(double distance,short angle,double distanceAnglePct)

{
  float fVar1;
  double dVar2;
  
  dVar2 = (double)((float)((double)CONCAT44(0x43300000,(int)angle ^ 0x80000000) - _4304) / 32768_0);
  if (dVar2 < (double)0_0) {
    dVar2 = -dVar2;
  }
  fVar1 = (float)((double)1_0 - dVar2);
  return (double)(float)(distance *
                        (double)((float)((double)1_0 - distanceAnglePct) +
                                (float)(distanceAnglePct * (double)(fVar1 * fVar1))));
}


/* WARNING: Removing unreachable block (ram,0x8009de20) */
/* WARNING: Removing unreachable block (ram,0x8009de10) */
/* WARNING: Removing unreachable block (ram,0x8009de18) */
/* WARNING: Removing unreachable block (ram,0x8009de28) */
/* __stdcall check_distace(cXyz *,
                           short,
                           cXyz *,
                           float,
                           float,
                           float,
                           float) */

int check_distace
              (cXyz *pPlayerPos,short angle1,cXyz *pActorPos,double maxDistXZBase,
              double maxDistAngleMul,double maxDeltaY,double minDeltaY)

{
  int iVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar5;
  float fVar6;
  cXyz local_74;
  cXyz delta;
  cXyz local_5c;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  ::cXyz::operator__(&delta,pActorPos,pPlayerPos);
  local_5c.x = delta.x;
  local_5c.y = delta.y;
  local_5c.z = delta.z;
  if (((double)delta.y <= minDeltaY) || (maxDeltaY <= (double)delta.y)) {
    iVar1 = 0;
  }
  else {
    dVar4 = distace_angle_adjust(maxDistAngleMul,angle1,(double)1_0);
    dVar5 = (double)(float)(maxDistXZBase + dVar4);
    local_74.x = local_5c.x;
    local_74.y = 0_0;
    local_74.z = local_5c.z;
    fVar6 = mtx::PSVECSquareMag(&local_74);
    dVar4 = (double)fVar6;
    if ((double)0_0 < dVar4) {
      dVar3 = 1.0 / SQRT(dVar4);
      dVar3 = _4358 * dVar3 * (_4359 - dVar4 * dVar3 * dVar3);
      dVar3 = _4358 * dVar3 * (_4359 - dVar4 * dVar3 * dVar3);
      dVar4 = (double)(float)(dVar4 * _4358 * dVar3 * (_4359 - dVar4 * dVar3 * dVar3));
    }
    if (dVar4 <= dVar5) {
      iVar1 = 1;
    }
    else {
      iVar1 = 0;
    }
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

}

/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* WARNING: Removing unreachable block (ram,0x8009e014) */
/* WARNING: Removing unreachable block (ram,0x8009e00c) */
/* WARNING: Removing unreachable block (ram,0x8009e01c) */
/* __thiscall dAttention_c::calcWeight(int,
                                       fopAc_ac_c *,
                                       float,
                                       short,
                                       short,
                                       unsigned long *) */

float __thiscall
dAttention_c::calcWeight
          (dAttention_c *this,char mode,fopAc_ac_c *pActor,float distance,short angle1,short angle2,
          int *pDstLocType)

{
  fopAc_ac_c *pfVar1;
  int iVar2;
  undefined3 in_register_00000010;
  undefined2 in_register_00000018;
  undefined2 in_register_0000001c;
  uint distIdx;
  int iVar3;
  dAttention__TypeTableEntry *pType;
  int i;
  int typeTableNum;
  dAttention__TypeTableEntry *pTypeTbl;
  undefined4 uVar4;
  double dVar5;
  double distance_00;
  double dVar6;
  double weight;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  double bestWeightDivisor;
  int grabActorID;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  distance_00 = (double)distance;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  typeTableNum = act_type_num;
  if (CONCAT31(in_register_00000010,mode) == 0x4c) {
    typeTableNum = loc_type_num;
  }
  pTypeTbl = act_type_tbl;
  if (CONCAT31(in_register_00000010,mode) == 0x4c) {
    pTypeTbl = loc_type_tbl;
  }
  bestWeightDivisor = (double)d_attention::0_0;
  dVar6 = bestWeightDivisor;
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor != (daPy_lk_c *)0x0) {
    grabActorID = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->vtbl->
                            getGrabActorID)();
    pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&grabActorID);
    if (pActor == pfVar1) {
      dVar6 = (double)d_attention::0_0;
      goto LAB_8009e00c;
    }
  }
  iVar3 = 0;
  for (i = 0; i < typeTableNum; i = i + 1) {
    pType = (dAttention__TypeTableEntry *)((int)&pTypeTbl->mType + iVar3);
    if ((pActor->mAttentionFlags & this->mFlagMask & (uint)pType->mAttentionFlagMask) != 0) {
      distIdx = (uint)pActor->mAttentionDistances[pType->mType];
      iVar2 = d_attention::check_event_condition((int)pType->mType,(pActor->mEvtInfo).mCondition);
      if (iVar2 == 0) {
        iVar2 = d_attention::check_flontofplayer
                          (dist_table[distIdx].mFrontAngleCheckBits,
                           CONCAT22(in_register_00000018,angle1),
                           CONCAT22(in_register_0000001c,angle2));
        if (iVar2 == 0) {
          iVar2 = d_attention::check_distace
                            (&(this->mpPlayer->parent).parent.mAttentionPos,angle1,
                             &pActor->mAttentionPos,(double)dist_table[distIdx].mDistXZMax,
                             (double)dist_table[distIdx].mDistXZAngleAdjust,
                             (double)dist_table[distIdx].mDeltaYMax,
                             (double)dist_table[distIdx].mDeltaYMin);
          if (iVar2 == 0) {
            weight = (double)d_attention::0_0;
          }
          else {
            weight = d_attention::distace_weight(distance_00,angle1,(double)d_attention::0_5);
          }
        }
        else {
          weight = (double)d_attention::0_0;
        }
      }
      else {
        weight = (double)d_attention::0_0;
      }
      if (((double)d_attention::0_0 < weight) &&
         (dVar5 = (double)dist_table[distIdx].mWeightDivisor, bestWeightDivisor < dVar5)) {
        dVar6 = (double)(float)(weight / dVar5);
        *pDstLocType = (int)pType->mType;
        bestWeightDivisor = dVar5;
      }
    }
    iVar3 = iVar3 + 4;
  }
LAB_8009e00c:
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  return (float)dVar6;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8009e100) */
/* WARNING: Removing unreachable block (ram,0x8009e108) */
/* __thiscall dAttention_c::setLList(fopAc_ac_c *,
                                     float,
                                     float,
                                     unsigned long) */

void __thiscall
dAttention_c::setLList(dAttention_c *this,fopAc_ac_c *pActor,float weight,float distance,ulong type)

{
  int iVar1;
  int iVar2;
  int iVar3;
  dAttention_c *pList;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar9 = (double)distance;
  dVar8 = (double)weight;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar6 = (double)d_attention::0_0;
  if (dVar6 < dVar8) {
    iVar1 = this->mLockOnNum;
    if (iVar1 < 8) {
      this->mLockOnNum = iVar1 + 1;
    }
    else {
      iVar3 = 0;
      iVar2 = 0;
      iVar1 = 0;
      iVar4 = 8;
      do {
        dVar7 = (double)*(float *)((int)&this->mLockOnList[0].mWeight + iVar2);
        if (dVar6 < dVar7) {
          iVar1 = iVar3;
          dVar6 = dVar7;
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x10;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    pList = (dAttention_c *)&this->mLockOnList[iVar1 + -6].mPcId;
    if (dVar8 < (double)pList->mLockOnList[0].mWeight) {
      dAttList_c::setActor(this->mLockOnList + iVar1,pActor);
      pList->mLockOnList[0].mWeight = (float)dVar8;
      pList->mLockOnList[0].mDistance = (float)dVar9;
      pList->mLockOnList[0].mType = type;
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8009e1ec) */
/* WARNING: Removing unreachable block (ram,0x8009e1f4) */
/* __thiscall dAttention_c::setAList(fopAc_ac_c *,
                                     float,
                                     float,
                                     unsigned long) */

void __thiscall
dAttention_c::setAList(dAttention_c *this,fopAc_ac_c *pActor,float weight,float distance,ulong type)

{
  int iVar1;
  int iVar2;
  int iVar3;
  dAttention_c *pList;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar9 = (double)distance;
  dVar8 = (double)weight;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar6 = (double)d_attention::0_0;
  if (dVar6 < dVar8) {
    iVar1 = this->mActionNum;
    if (iVar1 < 4) {
      this->mActionNum = iVar1 + 1;
    }
    else {
      iVar3 = 0;
      iVar2 = 0;
      iVar1 = 0;
      iVar4 = 4;
      do {
        dVar7 = (double)*(float *)((int)&this->mActionList[0].mWeight + iVar2);
        if (dVar6 < dVar7) {
          iVar1 = iVar3;
          dVar6 = dVar7;
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x10;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    pList = (dAttention_c *)&this->mLockOnList[iVar1 + -6].mPcId;
    if (dVar8 < (double)pList->mActionList[0].mWeight) {
      dAttList_c::setActor(this->mActionList + iVar1,pActor);
      pList->mActionList[0].mWeight = (float)dVar8;
      pList->mActionList[0].mDistance = (float)dVar9;
      pList->mActionList[0].mType = type;
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8009e2ac) */
/* __thiscall dAttention_c::initList(unsigned long) */

void __thiscall dAttention_c::initList(dAttention_c *this,ulong flagMask)

{
  int iVar1;
  dAttention_c *pList;
  dAttention_c *pList2;
  int iVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  this->mFlagMask = flagMask;
  iVar1 = 0;
  iVar2 = 0;
  dVar4 = (double)d_attention::_4463;
  do {
    pList = (dAttention_c *)((int)this->mLockOnList + iVar2 + -0x54);
    dAttList_c::setActor(pList->mLockOnList,(fopAc_ac_c *)0x0);
    pList->mLockOnList[0].mWeight = (float)dVar4;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x10;
  } while (iVar1 < 8);
  iVar1 = 0;
  this->mLockOnOffs = 0;
  this->mLockOnNum = 0;
  iVar2 = 0;
  dVar4 = (double)d_attention::_4463;
  do {
    pList2 = (dAttention_c *)((int)this->mLockOnList + iVar2 + -0x54);
    dAttList_c::setActor(pList2->mActionList,(fopAc_ac_c *)0x0);
    pList2->mActionList[0].mWeight = (float)dVar4;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x10;
  } while (iVar1 < 4);
  this->mActionOffs = 0;
  this->mActionNum = 0;
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


namespace d_attention {

/* __stdcall select_attention(fopAc_ac_c *,
                              void *) */

void select_attention(fopAc_ac_c *param_1,dAttention_c *param_2)

{
  ::dAttention_c::SelectAttention(param_2,param_1);
  return;
}

}

/* __thiscall dAttention_c::makeList(void) */

int __thiscall dAttention_c::makeList(dAttention_c *this)

{
  f_op_actor_iter::fopAcIt_Executor(d_attention::select_attention,this);
  return this->mLockOnNum + this->mActionNum;
}


/* __thiscall dAttention_c::SelectAttention(fopAc_ac_c *) */

undefined4 __thiscall dAttention_c::SelectAttention(dAttention_c *this,fopAc_ac_c *pActor)

{
  daPy_lk_c *pPlayer;
  float fVar1;
  cSAngle angle2;
  cSAngle angle1;
  int type;
  cSGlobe local_34;
  cSGlobe cStack44;
  cXyz cStack36;
  cXyz cStack24;
  
  pPlayer = this->mpPlayer;
  if (((daPy_lk_c *)pActor != pPlayer) && (pPlayer != (daPy_lk_c *)0x0)) {
    this->mFlagMask = *(fopAc_ac_c__AttentionFlags *)&pPlayer->parent;
    ::cXyz::operator__(&cStack24,&pActor->mAttentionPos,
                       &(this->mpPlayer->parent).parent.mAttentionPos);
    cSGlobe::cSGlobe(&cStack44,&cStack24);
    cSAngle::operator__(&angle1,&cStack44.mAngleY,(this->mpPlayer->parent).parent.mCollisionRot.y);
    ::cXyz::operator__(&cStack36,&(this->mpPlayer->parent).parent.mAttentionPos,
                       &pActor->mAttentionPos);
    cSGlobe::cSGlobe(&local_34,&cStack36);
    cSAngle::operator__(&angle2,&local_34.mAngleY,(pActor->mCollisionRot).y);
    fVar1 = calcWeight(this,'L',pActor,cStack44.mDistance,angle1,angle2,&type);
    setLList(this,pActor,fVar1,cStack44.mDistance,type);
    fVar1 = calcWeight(this,'A',pActor,cStack44.mDistance,angle1,angle2,&type);
    setAList(this,pActor,fVar1,cStack44.mDistance,type);
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dAttention_c::sortList(void) */

void __thiscall dAttention_c::sortList(dAttention_c *this)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  byte abStack56 [24];
  
  iVar5 = 0;
  for (iVar1 = 0; iVar1 < this->mLockOnNum + -1; iVar1 = iVar1 + 1) {
    iVar2 = iVar1 + 1;
    pfVar4 = (float *)((int)&this->mLockOnList[0].mWeight + iVar5);
    iVar6 = iVar2 * 0x10;
    for (; iVar2 < this->mLockOnNum; iVar2 = iVar2 + 1) {
      pfVar3 = (float *)((int)&this->mLockOnList[0].mWeight + iVar6);
      if (*pfVar3 < *pfVar4) {
        copy_bytes(abStack56,(byte *)pfVar3,0x10);
        copy_bytes((byte *)pfVar3,(byte *)pfVar4,0x10);
        copy_bytes((byte *)pfVar4,abStack56,0x10);
      }
      iVar6 = iVar6 + 0x10;
    }
    iVar5 = iVar5 + 0x10;
  }
  iVar5 = 0;
  for (iVar1 = 0; iVar1 < this->mActionNum + -1; iVar1 = iVar1 + 1) {
    iVar2 = iVar1 + 1;
    pfVar4 = (float *)((int)&this->mActionList[0].mWeight + iVar5);
    iVar6 = iVar2 * 0x10;
    for (; iVar2 < this->mActionNum; iVar2 = iVar2 + 1) {
      pfVar3 = (float *)((int)&this->mActionList[0].mWeight + iVar6);
      if (*pfVar3 < *pfVar4) {
        copy_bytes(abStack56,(byte *)pfVar3,0x10);
        copy_bytes((byte *)pfVar3,(byte *)pfVar4,0x10);
        copy_bytes((byte *)pfVar4,abStack56,0x10);
      }
      iVar6 = iVar6 + 0x10;
    }
    iVar5 = iVar5 + 0x10;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dAttention_c::stockAttention(unsigned long) */

void __thiscall dAttention_c::stockAttention(dAttention_c *this,ulong param_1)

{
  fopAc_ac_c *pfVar1;
  int iVar2;
  fopAc_ac_c *pfVar3;
  
  pfVar1 = LockonTarget(this,0);
  initList(this,param_1);
  iVar2 = makeList(this);
  if (iVar2 != 0) {
    sortList(this);
  }
  pfVar3 = dAttList_c::getActor(this->mLockOnList);
  if (pfVar1 != pfVar3) {
    if (pfVar1 == (fopAc_ac_c *)0x0) {
      this->mFlags = this->mFlags | 1;
    }
    else {
      pfVar1 = dAttList_c::getActor(this->mLockOnList);
      if (pfVar1 != (fopAc_ac_c *)0x0) {
        this->mFlags = this->mFlags | 2;
      }
    }
    this->mFlags = this->mFlags | 4;
  }
  LockonTarget(this,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dAttention_c::nextAttention(unsigned long) */

void __thiscall dAttention_c::nextAttention(dAttention_c *this,ulong interactMask)

{
  fopAc_ac_c *pfVar1;
  int iVar2;
  fopAc_ac_c *pfVar3;
  int local_18;
  
  local_18 = this->mLockOnTargetBsPcID;
  pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_18);
  initList(this,interactMask);
  iVar2 = makeList(this);
  if (iVar2 != 0) {
    sortList(this);
  }
  pfVar3 = dAttList_c::getActor(this->mLockOnList);
  if ((pfVar1 == pfVar3) && (1 < this->mLockOnNum)) {
    this->mLockOnOffs = 1;
  }
  LockonTarget(this,0);
  return;
}


/* __thiscall dAttention_c::freeAttention(void) */

undefined4 __thiscall dAttention_c::freeAttention(dAttention_c *this)

{
  this->mLockOnOffs = 0;
  this->mLockOnNum = 0;
  this->mActionOffs = 0;
  this->mActionNum = 0;
  initList(this,0xffffffff);
  return 0;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8009e958) */
/* __thiscall dAttention_c::chaseAttention(void) */

int __thiscall dAttention_c::chaseAttention(dAttention_c *this)

{
  int idx;
  fopAc_ac_c *pActor;
  int iVar2;
  dAttention_c *pList;
  int iVar1;
  uint distIdx;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  float fVar5;
  cSAngle angle2;
  cSAngle local_64 [2];
  cSAngle local_60;
  cSAngle angle1;
  int type;
  cSGlobe cStack84;
  cSGlobe globe;
  cXyz cStack68;
  cXyz acStack56 [2];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  idx = this->mLockOnOffs;
  pActor = dAttList_c::getActor(this->mLockOnList + idx);
  if (pActor == (fopAc_ac_c *)0x0) {
    iVar1 = 0;
  }
  else {
    ::cXyz::operator__(acStack56,&pActor->mAttentionPos,
                       &(this->mpPlayer->parent).parent.mAttentionPos);
    cSGlobe::cSGlobe(&globe,acStack56);
    cSAngle::operator__(local_64,&globe.mAngleY,(this->mpPlayer->parent).parent.mCollisionRot.y);
    angle1 = local_64[0];
    ::cXyz::operator__(&cStack68,&(this->mpPlayer->parent).parent.mAttentionPos,
                       &pActor->mAttentionPos);
    cSGlobe::cSGlobe(&cStack84,&cStack68);
    cSAngle::operator__(&angle2,&cStack84.mAngleY,(pActor->mCollisionRot).y);
    local_60 = angle2;
    fVar5 = calcWeight(this,'L',pActor,globe.mDistance,angle1,angle2,&type);
    dVar4 = (double)fVar5;
    if ((double)d_attention::0_0 < dVar4) {
      dAttList_c::setActor(this->mLockOnList + idx,pActor);
      pList = (dAttention_c *)&this->mLockOnList[idx + -6].mPcId;
      pList->mLockOnList[0].mWeight = (float)dVar4;
      pList->mLockOnList[0].mDistance = globe.mDistance;
      pList->mLockOnList[0].mType = type;
      iVar1 = 1;
    }
    else {
      type = this->mLockOnList[idx].mType;
      distIdx = (uint)pActor->mAttentionDistances[type];
      iVar2 = chkAttMask(this,type,pActor->mAttentionFlags);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar2 = d_attention::check_event_condition(type,(pActor->mEvtInfo).mCondition);
        if (iVar2 == 0) {
          iVar2 = d_attention::check_flontofplayer
                            (dist_table[distIdx].mFrontAngleCheckBits,(int)angle1,(int)local_60);
          if (iVar2 == 0) {
            iVar2 = d_attention::check_distace
                              (&(this->mpPlayer->parent).parent.mAttentionPos,angle1,
                               &pActor->mAttentionPos,(double)dist_table[distIdx].mDistXZMaxRelease,
                               (double)dist_table[distIdx].mDistXZAngleAdjust,
                               (double)dist_table[distIdx].mDeltaYMax,
                               (double)dist_table[distIdx].mDeltaYMin);
            if (iVar2 == 0) {
              iVar1 = 0;
            }
            else {
              dVar4 = d_attention::distace_weight
                                ((double)globe.mDistance,angle1,(double)d_attention::0_5);
              this->mLockOnList[idx].mWeight = (float)dVar4;
              iVar1 = 1;
            }
          }
          else {
            iVar1 = 0;
          }
        }
        else {
          iVar1 = 0;
        }
      }
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return iVar1;
}


/* __thiscall dAttention_c::EnemyDistance(fopAc_ac_c *) */

double __thiscall dAttention_c::EnemyDistance(dAttention_c *this,fopAc_ac_c *pActor)

{
  daPy_lk_c *pdVar1;
  double dVar2;
  
  pdVar1 = this->mpPlayer;
  if (((daPy_lk_c *)pActor == pdVar1) || (pdVar1 == (daPy_lk_c *)0x0)) {
    dVar2 = (double)d_attention::_1_0;
  }
  else {
    if ((pActor->parent).parent.mBsTypeId == 0xa9) {
      dVar2 = (double)d_attention::_1_0;
    }
    else {
      if (((pActor->mAttentionFlags & LockOn_Enemy) == 0) &&
         ((pActor->mAttentionFlags & EnemyFlag_NoLockOn) == 0)) {
        dVar2 = (double)d_attention::_1_0;
      }
      else {
        dVar2 = (double)f_op_actor_mng::fopAcM_searchActorDistance(pdVar1,pActor);
        if ((double)(dist_table[pActor->mAttentionDistances[2]].mDistXZMax +
                    dist_table[pActor->mAttentionDistances[2]].mDistXZAngleAdjust) <= dVar2) {
          dVar2 = (double)d_attention::_1_0;
        }
      }
    }
  }
  return dVar2;
}


namespace d_attention {

/* __stdcall sound_attention(fopAc_ac_c *,
                             void *) */

undefined4 sound_attention(fopAc_ac_c *pActor,dAttention_c *pAttention)

{
  uint uVar1;
  double dVar2;
  
  dVar2 = (double)::dAttention_c::EnemyDistance(pAttention,pActor);
  if (((double)0_0 <= dVar2) && (dVar2 < (double)pAttention->mEnemyDistance)) {
    if (pActor == (fopAc_ac_c *)0x0) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = (pActor->parent).parent.mBsPcId;
    }
    pAttention->mEnemyBsPcId = uVar1;
    pAttention->mEnemyDistance = (float)dVar2;
  }
  return 0;
}

}

/* __thiscall dAttention_c::runSoundProc(void) */

void __thiscall dAttention_c::runSoundProc(dAttention_c *this)

{
  fopAc_ac_c *pActor;
  int local_18;
  
  this->mEnemyBsPcId = -1;
  this->mEnemyDistance = d_attention::10000_0;
  if ((this->mFlags & 0x80000000) == 0) {
    f_op_actor_iter::fopAcIt_Executor(d_attention::sound_attention,this);
    local_18 = this->mEnemyBsPcId;
    pActor = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_18);
    if (pActor != (fopAc_ac_c *)0x0) {
      JAIZelBasic::bgmNowBattle(JAIZelBasic::zel_basic,d_attention::0_1 * this->mEnemyDistance);
      this->mFlags = this->mFlags | 0x100;
    }
  }
  return;
}


/* __thiscall dAttention_c::runDrawProc(void) */

void __thiscall dAttention_c::runDrawProc(dAttention_c *this)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = this->mFlags;
  if ((uVar1 >> 3 & 1) == 0) {
    if ((uVar1 & 0x10) == 0) {
      if ((uVar1 & 1) == 0) {
        if ((uVar1 & 2) == 0) {
          if ((this->mLockOnNum < 1) && (this->field_0x28 == 0)) {
            dAttDraw_c::setAnm((dAttDraw_c *)&this->field_0x38,0x1a,0x47,0);
            this->field_0x28 = 1;
            this->mFlags = this->mFlags | 0x40000000;
          }
        }
        else {
          dAttDraw_c::setAnm((dAttDraw_c *)&this->field_0x38,0x18,0x45,0);
          dAttDraw_c::setAnm((dAttDraw_c *)&this->field_0x44,0x1a,0x47,0);
          this->mFlags = this->mFlags | 0x40000000;
        }
      }
      else {
        dAttDraw_c::setAnm((dAttDraw_c *)&this->field_0x38,0x18,0x45,0);
        this->mFlags = this->mFlags | 0x40000000;
      }
    }
    else {
      dAttDraw_c::setAnm((dAttDraw_c *)&this->field_0x38,0x17,0x44,0);
      if (-1 < (char)this->field_0x28) {
        this->field_0x28 = 1;
        this->mFlags = this->mFlags | 0x40000000;
      }
      if (((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x37a02371U) == 0) ||
         ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc & 0x11U) != 0)) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x805,(cXyz *)0x0,0,0,d_attention::1_0,d_attention::1_0,
                   d_attention::_1_0,d_attention::_1_0,0);
      }
    }
  }
  else {
    dAttDraw_c::setAnm((dAttDraw_c *)&this->field_0x38,0x1b,0x48,0);
    if (((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x37a02371U) == 0) ||
       ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc & 0x11U) != 0)) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x804,(cXyz *)0x0,0,0,d_attention::1_0,d_attention::1_0,
                 d_attention::_1_0,d_attention::_1_0,0);
    }
  }
  if (this->mLockOnState == 1) {
    iVar2 = mDoExt_McaMorf::play(*(mDoExt_McaMorf **)&this->field_0x38,(cXyz *)0x0,0,0);
    if (iVar2 != 0) {
      dAttDraw_c::setAnm((dAttDraw_c *)&this->field_0x38,0x19,-1,2);
      this->mFlags = this->mFlags & 0xbfffffff;
    }
  }
  else {
    iVar2 = mDoExt_McaMorf::play(*(mDoExt_McaMorf **)&this->field_0x38,(cXyz *)0x0,0,0);
    if (iVar2 != 0) {
      this->mFlags = this->mFlags & 0xbfffffff;
      this->field_0x28 = 0xff;
    }
  }
  iVar2 = mDoExt_McaMorf::play(*(mDoExt_McaMorf **)&this->field_0x44,(cXyz *)0x0,0,0);
  if (iVar2 != 0) {
    *(undefined4 *)&this->field_0x48 = 0;
  }
  return;
}


/* __thiscall dAttention_c::runDebugDisp0(void) */

void __thiscall dAttention_c::runDebugDisp0(dAttention_c *this)

{
  return;
}


/* __thiscall dAttention_c::runDebugDisp(void) */

void __thiscall dAttention_c::runDebugDisp(dAttention_c *this)

{
  return;
}


/* WARNING: Removing unreachable block (ram,0x8009ee20) */
/* __thiscall dAttention_c::judgementButton(void) */

void __thiscall dAttention_c::judgementButton(dAttention_c *this)

{
  byte bVar1;
  
  if (((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x37a02371U) == 0) &&
     ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc & 0x11U) == 0)) {
    bVar1 = this->field_0x1a;
    if (bVar1 == 1) {
      this->field_0x1a = 2;
    }
    else {
      if (bVar1 == 0) {
        if (m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPlayerNo].mTriggerLeftLevel == 0) {
          return;
        }
        this->field_0x1a = 1;
        return;
      }
      if (2 < bVar1) {
        return;
      }
    }
    if (m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPlayerNo].mTriggerLeftLevel != 0) {
      return;
    }
    this->field_0x1a = 0;
    return;
  }
  if (2 < this->field_0x1a) {
    return;
  }
  if (this->field_0x1a == 0) {
    return;
  }
  this->field_0x1a = 0;
  return;
}


/* __thiscall dAttention_c::judgementTriggerProc(void) */

void __thiscall dAttention_c::judgementTriggerProc(dAttention_c *this)

{
  uint uVar1;
  
  uVar1 = chaseAttention(this);
  if ((uVar1 & 0xff) != 0) {
    this->mFlags = this->mFlags | 8;
    this->mLockOnState = 1;
  }
  return;
}


/* __thiscall dAttention_c::judgementLostCheck(void) */

bool __thiscall dAttention_c::judgementLostCheck(dAttention_c *this)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = chaseAttention(this);
  bVar1 = (uVar2 & 0xff) == 0;
  if (bVar1) {
    this->mLockOnState = 0;
    this->mFlags = this->mFlags | 0x10;
    freeAttention(this);
    this->mFlags = this->mFlags | 0x40;
  }
  return bVar1;
}


/* WARNING: Removing unreachable block (ram,0x8009ef74) */
/* __thiscall dAttention_c::judgementStatusSw(unsigned long) */

void __thiscall dAttention_c::judgementStatusSw(dAttention_c *this,ulong param_1)

{
  byte bVar1;
  int iVar2;
  fopAc_ac_c *pfVar3;
  
  bVar1 = this->mLockOnState;
  if (bVar1 == 1) {
    iVar2 = LockonTargetPId(this,0);
    this->mLockOnTargetBsPcID = iVar2;
    if (this->field_0x1a == 1) {
      if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPlayerNo].mStickMainPosY <=
            d_attention::_0_9) || (iVar2 = nextAttention(this,param_1), iVar2 == 0)) ||
         (this->mLockOnNum < 2)) {
        this->mLockOnState = 2;
        this->mFlags = this->mFlags | 0x10;
      }
      else {
        this->mFlags = this->mFlags | 8;
      }
    }
    else {
      judgementLostCheck(this);
    }
  }
  else {
    if (bVar1 == 0) {
      this->mLockOnTargetBsPcID = -1;
      stockAttention(this,param_1);
      if (this->field_0x1a == 1) {
        judgementTriggerProc(this);
      }
    }
    else {
      if (bVar1 < 3) {
        this->mFlags = this->mFlags | 0x40;
        if (this->field_0x1a == 1) {
          this->mLockOnState = 0;
          judgementTriggerProc(this);
        }
        else {
          pfVar3 = LockonTarget(this,0);
          if ((pfVar3 == (fopAc_ac_c *)0x0) || ((this->mFlags & 0x40000000) == 0)) {
            this->mLockOnState = 0;
            freeAttention(this);
          }
        }
      }
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8009f0d0) */
/* __thiscall dAttention_c::judgementStatusHd(unsigned long) */

void __thiscall dAttention_c::judgementStatusHd(dAttention_c *this,ulong param_1)

{
  byte bVar1;
  int iVar2;
  fopAc_ac_c *pfVar3;
  
  bVar1 = this->mLockOnState;
  if (bVar1 == 1) {
    iVar2 = LockonTargetPId(this,0);
    this->mLockOnTargetBsPcID = iVar2;
    iVar2 = judgementLostCheck(this);
    if ((iVar2 == 0) && (this->field_0x1a == 0)) {
      this->mLockOnState = 2;
      this->mFlags = this->mFlags | 0x10;
    }
  }
  else {
    if (bVar1 == 0) {
      this->mLockOnTargetBsPcID = -1;
      stockAttention(this,param_1);
      if (this->field_0x1a == 1) {
        judgementTriggerProc(this);
      }
    }
    else {
      if (bVar1 < 3) {
        this->mFlags = this->mFlags | 0x40;
        if (this->field_0x1a == 1) {
          iVar2 = nextAttention(this,param_1);
          if (iVar2 == 0) {
            this->mLockOnState = 0;
            freeAttention(this);
          }
          else {
            this->mFlags = this->mFlags | 8;
            this->mLockOnState = 1;
          }
        }
        else {
          pfVar3 = LockonTarget(this,0);
          if ((pfVar3 == (fopAc_ac_c *)0x0) || ((this->mFlags & 0x40000000) == 0)) {
            this->mLockOnState = 0;
            freeAttention(this);
          }
        }
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dAttention_c::Run(unsigned long) */

undefined4 __thiscall dAttention_c::Run(dAttention_c *this,ulong interactMask)

{
  uint uVar1;
  fopAc_ac_c *pfVar2;
  
  uVar1 = countLeadingZeros((uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig.
                                  field_0x2);
  if ((this->mFlags & 0x80) != 0) {
    this->mpPlayer = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
    this->mPlayerNo = 0;
  }
  runDebugDisp0(this);
  this->mFlags = this->mFlags & 0xf8000000;
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
    judgementButton(this);
    if ((uVar1 >> 5 & 0xff) == 0) {
      judgementStatusSw(this,interactMask);
    }
    else {
      judgementStatusHd(this,interactMask);
    }
    if ((this->mFlags >> 0x1c & 1) == 0) {
      if (m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPlayerNo].mTriggerLeftLevel != 0) {
        pfVar2 = LockonTarget(this,0);
        if (pfVar2 == (fopAc_ac_c *)0x0) {
          this->mFlags = this->mFlags | 0x20000020;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x81c,(cXyz *)0x0,0,0,d_attention::1_0,d_attention::1_0,
                     d_attention::_1_0,d_attention::_1_0,0);
        }
        this->mFlags = this->mFlags | 0x10000000;
      }
    }
    else {
      if (m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPlayerNo].mTriggerLeftLevel == 0) {
        if ((this->mFlags & 0x20000000) != 0) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x81d,(cXyz *)0x0,0,0,d_attention::1_0,d_attention::1_0,
                     d_attention::_1_0,d_attention::_1_0,0);
          this->mFlags = this->mFlags & 0xdfffffff;
        }
        this->mFlags = this->mFlags & 0xefffffff;
      }
    }
  }
  else {
    this->mLockOnState = 0;
    this->field_0x1a = 0;
    this->field_0x1b = 0;
    this->mFlags = this->mFlags & 0xdfffffff;
    this->mFlags = this->mFlags & 0xefffffff;
    this->mFlags = this->mFlags & 0xf8000000;
    this->mLockOnTargetBsPcID = -1;
    freeAttention(this);
  }
  this->field_0x19 = this->mLockOnState;
  runSoundProc(this);
  runDrawProc(this);
  runDebugDisp(this);
  if (this->mLockOnState == 1) {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mPlayerNo].field_0x8 =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mPlayerNo].field_0x8 | 1;
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mPlayerNo].field_0x8 =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mPlayerNo].field_0x8 &
         0xfffffffe;
  }
  dAttHint_c::proc(&this->mHint);
  dAttCatch_c::proc(&this->mCatch);
  dAttLook_c::proc(&this->field_0x148);
  dAttLook_c::proc(&this->field_0x158);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dAttention_c::Draw(void) */

void __thiscall dAttention_c::Draw(dAttention_c *this)

{
  fopAc_ac_c *pfVar1;
  int iVar2;
  fopAc_ac_c *pfVar3;
  undefined4 uVar4;
  undefined4 local_48;
  float afStack68 [14];
  
  mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                    afStack68);
  pfVar1 = LockonTarget(this,0);
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) &&
     (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 0)) {
    if (pfVar1 == (fopAc_ac_c *)0x0) {
      if ('\0' < (char)this->field_0x28) {
        local_48 = *(undefined4 *)&this->field_0x50;
        pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_48);
        if (pfVar1 == (fopAc_ac_c *)0x0) {
          dAttDraw_c::draw((dAttDraw_c *)&this->field_0x38,(cXyz *)&this->field_0x2c,afStack68);
        }
        else {
          dAttDraw_c::draw((dAttDraw_c *)&this->field_0x38,&pfVar1->mAttentionPos,afStack68);
          *(float *)&this->field_0x2c = (pfVar1->mAttentionPos).x;
          *(float *)&this->field_0x30 = (pfVar1->mAttentionPos).y;
          *(float *)&this->field_0x34 = (pfVar1->mAttentionPos).z;
        }
      }
    }
    else {
      if (pfVar1 != (fopAc_ac_c *)0x0) {
        dAttDraw_c::draw((dAttDraw_c *)&this->field_0x38,&pfVar1->mAttentionPos,afStack68);
      }
      if ((1 < this->mLockOnNum) && (*(int *)&this->field_0x48 != 0)) {
        iVar2 = this->mLockOnOffs;
        if (iVar2 == 0) {
          iVar2 = this->mLockOnNum;
        }
        pfVar3 = dAttList_c::getActor(this->mLockOnList + iVar2 + -1);
        if (pfVar3 != (fopAc_ac_c *)0x0) {
          pfVar3 = dAttList_c::getActor(this->mLockOnList + iVar2 + -1);
          dAttDraw_c::draw((dAttDraw_c *)&this->field_0x44,&pfVar3->mAttentionPos,afStack68);
        }
      }
      uVar4 = LockonTargetPId(this,0);
      *(undefined4 *)&this->field_0x50 = uVar4;
      *(float *)&this->field_0x2c = (pfVar1->mAttentionPos).x;
      *(float *)&this->field_0x30 = (pfVar1->mAttentionPos).y;
      *(float *)&this->field_0x34 = (pfVar1->mAttentionPos).z;
      this->field_0x28 = 0;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dAttDraw_c::setAnm(int,
                                 int,
                                 int) */

void __thiscall dAttDraw_c::setAnm(dAttDraw_c *this,int param_1,int param_2,int param_3)

{
  J3DAnmTransform *pAnimRes;
  void *pvVar1;
  
  pAnimRes = (J3DAnmTransform *)
             dRes_control_c::getRes
                       ("Always",param_1,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                        0x40);
  mDoExt_McaMorf::setAnm
            (*(mDoExt_McaMorf **)this,pAnimRes,param_3,d_attention::0_0,d_attention::1_0,
             d_attention::0_0,d_attention::_1_0,(void *)0x0);
  if (param_2 < 0) {
    *(undefined4 *)(this + 4) = 0;
  }
  else {
    pvVar1 = dRes_control_c::getRes
                       ("Always",param_2,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                        0x40);
    *(void **)(this + 4) = pvVar1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dAttDraw_c::draw(cXyz &,
                               float *[][][][]) */

void __thiscall dAttDraw_c::draw(dAttDraw_c *this,cXyz *param_1,float *param_2)

{
  J3DAnmColor *pJVar1;
  ushort *puVar2;
  ushort uVar3;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)this + 0x50);
  mtx::PSMTXTrans((double)param_1->x,(double)param_1->y,(double)param_1->z,&mDoMtx_stack_c::now);
  mtx::PSMTXConcat(&mDoMtx_stack_c::now,(MTX34 *)param_2,&mDoMtx_stack_c::now);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(iVar4 + 0x24));
  iVar4 = *(int *)(iVar4 + 4);
  if (*(int *)(this + 4) == 0) {
    pJVar1 = (J3DAnmColor *)
             dRes_control_c::getRes
                       ("Always",0x45,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    J3DMaterialTable::removeMatColorAnimator((J3DMaterialTable *)(iVar4 + 0x58),pJVar1);
  }
  else {
    *(undefined4 *)(*(int *)(this + 4) + 8) = *(undefined4 *)(*(int *)this + 0x68);
    puVar2 = *(ushort **)(this + 8);
    for (uVar3 = 0; pJVar1 = *(J3DAnmColor **)(this + 4), uVar3 < *(ushort *)(pJVar1 + 0x18);
        uVar3 = uVar3 + 1) {
      *(J3DAnmColor **)(puVar2 + 2) = pJVar1;
      *puVar2 = uVar3;
      puVar2 = puVar2 + 4;
    }
    J3DMaterialTable::setMatColorAnimator
              ((J3DMaterialTable *)(iVar4 + 0x58),pJVar1,*(J3DMatColorAnm **)(this + 8));
  }
  if (mDoGph_gInf_c::mMonotone == 0) {
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffXlu;
  }
  else {
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0xc;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x10;
  }
  mDoExt_McaMorf::updateDL(*(mDoExt_McaMorf **)this);
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  return;
}


/* __thiscall dAttention_c::LockonTarget(long) */

fopAc_ac_c * __thiscall dAttention_c::LockonTarget(dAttention_c *this,long idx)

{
  int iVar1;
  int iVar2;
  fopAc_ac_c *pfVar3;
  
  iVar2 = this->mLockOnNum;
  if (idx < iVar2) {
    iVar1 = this->mLockOnOffs + idx;
    if (iVar2 <= iVar1) {
      iVar1 = iVar1 - iVar2;
    }
    pfVar3 = dAttList_c::getActor(this->mLockOnList + iVar1);
  }
  else {
    pfVar3 = (fopAc_ac_c *)0x0;
  }
  return pfVar3;
}


/* __thiscall dAttention_c::LockonReleaseDistanse(void) */

double __thiscall dAttention_c::LockonReleaseDistanse(dAttention_c *this)

{
  byte bVar1;
  uint uVar2;
  fopAc_ac_c *pfVar3;
  double dVar4;
  cSAngle acStack40 [2];
  cSAngle local_24;
  cSGlobe cStack32;
  cXyz cStack24;
  
  uVar2 = LockonTruth(this);
  if ((uVar2 & 0xff) == 0) {
    dVar4 = (double)d_attention::0_0;
  }
  else {
    pfVar3 = dAttList_c::getActor(this->mLockOnList + this->mLockOnOffs);
    if (pfVar3 == (fopAc_ac_c *)0x0) {
      dVar4 = (double)d_attention::0_0;
    }
    else {
      bVar1 = pfVar3->mAttentionDistances[this->mLockOnList[this->mLockOnOffs].mType];
      ::cXyz::operator__(&cStack24,&pfVar3->mAttentionPos,
                         &(this->mpPlayer->parent).parent.mAttentionPos);
      cSGlobe::cSGlobe(&cStack32,&cStack24);
      cSAngle::operator__(acStack40,&cStack32.mAngleY,
                          (this->mpPlayer->parent).parent.mCollisionRot.y);
      cSAngle::cSAngle(&local_24,acStack40);
      dVar4 = d_attention::distace_angle_adjust
                        ((double)dist_table[bVar1].mDistXZAngleAdjust,local_24,
                         (double)d_attention::1_0);
      dVar4 = (double)(float)((double)dist_table[bVar1].mDistXZMaxRelease + dVar4);
    }
  }
  return dVar4;
}


/* __thiscall dAttention_c::LockonTargetPId(long) */

int __thiscall dAttention_c::LockonTargetPId(dAttention_c *this,long param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = this->mLockOnNum;
  if (iVar2 <= param_1) {
    return 0;
  }
  iVar1 = this->mLockOnOffs + param_1;
  if (iVar2 <= iVar1) {
    iVar1 = iVar1 - iVar2;
  }
  return this->mLockOnList[iVar1].mPcId;
}


/* __thiscall dAttention_c::ActionTarget(long) */

fopAc_ac_c * __thiscall dAttention_c::ActionTarget(dAttention_c *this,long param_1)

{
  int iVar1;
  int iVar2;
  fopAc_ac_c *pfVar3;
  
  iVar2 = this->mActionNum;
  if (param_1 < iVar2) {
    iVar1 = this->mActionOffs + param_1;
    if (iVar2 <= iVar1) {
      iVar1 = iVar1 - iVar2;
    }
    pfVar3 = dAttList_c::getActor(this->mActionList + iVar1);
  }
  else {
    pfVar3 = (fopAc_ac_c *)0x0;
  }
  return pfVar3;
}


/* __thiscall dAttention_c::LockonTruth(void) */

int __thiscall dAttention_c::LockonTruth(dAttention_c *this)

{
  fopAc_ac_c *pfVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((this->mLockOnState == 1) ||
     ((this->mLockOnState == 2 && (pfVar1 = LockonTarget(this,0), pfVar1 != (fopAc_ac_c *)0x0)))) {
    iVar2 = 1;
  }
  return iVar2;
}


/* __thiscall dAttList_c::getActor(void) */

fopAc_ac_c * __thiscall dAttList_c::getActor(dAttList_c *this)

{
  fopAc_ac_c *pfVar1;
  int local_8;
  
  local_8 = this->mPcId;
  pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_8);
  return pfVar1;
}


/* __thiscall dAttList_c::setActor(fopAc_ac_c *) */

void __thiscall dAttList_c::setActor(dAttList_c *this,fopAc_ac_c *param_1)

{
  uint uVar1;
  
  if (param_1 == (fopAc_ac_c *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (param_1->parent).parent.mBsPcId;
  }
  this->mPcId = uVar1;
  return;
}


/* __thiscall dAttHint_c::getPId(void *) */

undefined4 __thiscall dAttHint_c::getPId(dAttHint_c *this,void *param_1)

{
  if (param_1 != (void *)0x0) {
    return *(undefined4 *)((int)param_1 + 4);
  }
  return 0xffffffff;
}


/* __thiscall dAttHint_c::convPId(unsigned int) */

void __thiscall dAttHint_c::convPId(dAttHint_c *this,uint param_1)

{
  uint local_8;
  
  local_8 = param_1;
  f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_8);
  return;
}


/* __thiscall dAttHint_c::request(fopAc_ac_c *,
                                  int) */

undefined4 __thiscall dAttHint_c::request(dAttHint_c *this,fopAc_ac_c *pActor,int priority)

{
  undefined4 uVar1;
  
  if (priority < 0) {
    priority = 0x1ff;
  }
  if (priority <= this->mBestPriority) {
    uVar1 = getPId(this,pActor);
    this->mHintActorBsPcID = uVar1;
    this->mBestPriority = priority;
  }
  return 1;
}


/* __thiscall dAttHint_c::init(void) */

int __thiscall dAttHint_c::init(dAttHint_c *this,EVP_PKEY_CTX *ctx)

{
  this->mHintActorBsPcID = 0xffffffff;
  this->field_0x8 = 0xffffffff;
  this->mBestPriority = 0x200;
  return (int)this;
}


/* __thiscall dAttHint_c::proc(void) */

void __thiscall dAttHint_c::proc(dAttHint_c *this)

{
  this->field_0x8 = this->mHintActorBsPcID;
  this->mHintActorBsPcID = 0xffffffff;
  this->mBestPriority = 0x200;
  return;
}


/* __thiscall dAttCatch_c::convPId(unsigned int) */

void __thiscall dAttCatch_c::convPId(dAttCatch_c *this,uint param_1)

{
  uint local_8 [2];
  
  local_8[0] = param_1;
  f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,local_8);
  return;
}


/* __thiscall dAttCatch_c::init(void) */

int __thiscall dAttCatch_c::init(dAttCatch_c *this,EVP_PKEY_CTX *ctx)

{
  this->field_0xc = 0x56;
  this->field_0x0 = -1;
  this->field_0x10 = -1;
  this->field_0x4 = 3;
  return (int)this;
}


/* __thiscall dAttCatch_c::proc(void) */

void __thiscall dAttCatch_c::proc(dAttCatch_c *this)

{
  this->field_0x10 = this->field_0x0;
  this->field_0x14 = this->field_0xc;
  this->field_0x0 = -1;
  this->field_0x4 = 3;
  this->field_0xc = 0x56;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8009fde8) */
/* WARNING: Removing unreachable block (ram,0x8009fde0) */
/* WARNING: Removing unreachable block (ram,0x8009fdf0) */
/* __thiscall dAttCatch_c::request(fopAc_ac_c *,
                                   unsigned char,
                                   float,
                                   float,
                                   float,
                                   short,
                                   int) */

undefined4 __thiscall
dAttCatch_c::request
          (dAttCatch_c *this,fopAc_ac_c *param_1,uchar param_2,float param_3,float param_4,
          float param_5,short param_6,int param_7)

{
  daPy_lk_c *pdVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  float fVar8;
  cSAngle local_88 [2];
  float local_84;
  cSGlobe cStack128;
  cXyz local_78;
  cXyz local_6c;
  cXyz local_60 [2];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  dVar5 = (double)param_5;
  dVar7 = (double)param_4;
  dVar6 = (double)param_3;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if ((int)this->field_0x4 < param_7) {
    uVar3 = 0;
  }
  else {
    ::cXyz::operator__(&local_6c,&param_1->mAttentionPos,
                       &((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent
                        .mAttentionPos);
    local_60[0].x = local_6c.x;
    local_60[0].y = local_6c.y;
    local_60[0].z = local_6c.z;
    if (((double)local_6c.y < dVar5) || (dVar7 < (double)local_6c.y)) {
      uVar3 = 0;
    }
    else {
      local_78.x = local_6c.x;
      local_78.y = d_attention::0_0;
      local_78.z = local_6c.z;
      fVar8 = mtx::PSVECSquareMag(&local_78);
      dVar7 = (double)fVar8;
      if ((double)d_attention::0_0 < dVar7) {
        dVar5 = 1.0 / SQRT(dVar7);
        dVar5 = d_attention::_4358 * dVar5 * (d_attention::_4359 - dVar7 * dVar5 * dVar5);
        dVar5 = d_attention::_4358 * dVar5 * (d_attention::_4359 - dVar7 * dVar5 * dVar5);
        local_84 = (float)(dVar7 * d_attention::_4358 * dVar5 *
                                   (d_attention::_4359 - dVar7 * dVar5 * dVar5));
        dVar7 = (double)local_84;
      }
      if (dVar7 <= dVar6) {
        if (param_6 != 0) {
          cSGlobe::cSGlobe(&cStack128,local_60);
          cSAngle::operator__(local_88,&cStack128.mAngleY,(pdVar1->parent).parent.mCollisionRot.y);
          if (local_88[0] < 0) {
            local_88[0] = -local_88[0];
          }
          if (param_6 < local_88[0]) {
            uVar3 = 0;
            goto LAB_8009fde0;
          }
        }
        if ((param_7 < (int)this->field_0x4) || (dVar7 < (double)this->field_0x8)) {
          this->field_0x4 = param_7;
          this->field_0xc = param_2;
          if (param_1 == (fopAc_ac_c *)0x0) {
            uVar2 = 0xffffffff;
          }
          else {
            uVar2 = (param_1->parent).parent.mBsPcId;
          }
          this->field_0x0 = uVar2;
          this->field_0x8 = (float)dVar7;
          uVar3 = 1;
        }
        else {
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0;
      }
    }
  }
LAB_8009fde0:
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  return uVar3;
}


/* __thiscall dAttLook_c::convPId(unsigned int) */

fopAc_ac_c * __thiscall dAttLook_c::convPId(dAttLook_c *this,uint param_1)

{
  fopAc_ac_c *pfVar1;
  uint local_8;
  
  local_8 = param_1;
  pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_8);
  return pfVar1;
}


/* __thiscall dAttLook_c::init(void) */

int __thiscall dAttLook_c::init(dAttLook_c *this,EVP_PKEY_CTX *ctx)

{
  this->field_0x0 = -1;
  this->field_0xc = -1;
  this->field_0x4 = 3;
  return (int)this;
}


/* __thiscall dAttLook_c::proc(void) */

void __thiscall dAttLook_c::proc(dAttLook_c *this)

{
  this->field_0xc = this->field_0x0;
  this->field_0x0 = -1;
  this->field_0x4 = 3;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800a0074) */
/* WARNING: Removing unreachable block (ram,0x800a006c) */
/* WARNING: Removing unreachable block (ram,0x800a007c) */
/* __thiscall dAttLook_c::request(fopAc_ac_c *,
                                  float,
                                  float,
                                  float,
                                  short,
                                  int) */

undefined4 __thiscall
dAttLook_c::request(dAttLook_c *this,fopAc_ac_c *param_1,float param_2,float param_3,float param_4,
                   short param_5,int param_6)

{
  daPy_lk_c *pdVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  float fVar8;
  cSAngle local_88 [2];
  float local_84;
  cSGlobe cStack128;
  cXyz local_78;
  cXyz local_6c;
  cXyz local_60;
  cXyz local_54;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  dVar5 = (double)param_4;
  dVar7 = (double)param_3;
  dVar6 = (double)param_2;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if ((int)this->field_0x4 < param_6) {
    uVar3 = 0;
  }
  else {
    ::cXyz::operator__(&local_60,&param_1->mEyePos,
                       &((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent
                        .mEyePos);
    local_54.x = local_60.x;
    local_54.y = local_60.y;
    local_54.z = local_60.z;
    if (((double)local_60.y < dVar5) || (dVar7 < (double)local_60.y)) {
      uVar3 = 0;
    }
    else {
      local_78.x = local_60.x;
      local_78.y = d_attention::0_0;
      local_78.z = local_60.z;
      fVar8 = mtx::PSVECSquareMag(&local_78);
      dVar7 = (double)fVar8;
      if ((double)d_attention::0_0 < dVar7) {
        dVar5 = 1.0 / SQRT(dVar7);
        dVar5 = d_attention::_4358 * dVar5 * (d_attention::_4359 - dVar7 * dVar5 * dVar5);
        dVar5 = d_attention::_4358 * dVar5 * (d_attention::_4359 - dVar7 * dVar5 * dVar5);
        local_84 = (float)(dVar7 * d_attention::_4358 * dVar5 *
                                   (d_attention::_4359 - dVar7 * dVar5 * dVar5));
        dVar7 = (double)local_84;
      }
      if (dVar7 <= dVar6) {
        if (param_5 != 0) {
          ::cXyz::operator__(&local_6c,&(param_1->mCurrent).mPos,
                             &(pdVar1->parent).parent.mCurrent.mPos);
          local_54.x = local_6c.x;
          local_54.y = local_6c.y;
          local_54.z = local_6c.z;
          cSGlobe::cSGlobe(&cStack128,&local_54);
          cSAngle::operator__(local_88,&cStack128.mAngleY,(pdVar1->parent).parent.mCollisionRot.y);
          if (local_88[0] < 0) {
            local_88[0] = -local_88[0];
          }
          if (param_5 < local_88[0]) {
            uVar3 = 0;
            goto LAB_800a006c;
          }
        }
        if ((param_6 < (int)this->field_0x4) || (dVar7 < (double)this->field_0x8)) {
          this->field_0x4 = param_6;
          if (param_1 == (fopAc_ac_c *)0x0) {
            uVar2 = 0xffffffff;
          }
          else {
            uVar2 = (param_1->parent).parent.mBsPcId;
          }
          this->field_0x0 = uVar2;
          this->field_0x8 = (float)dVar7;
          uVar3 = 1;
        }
        else {
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0;
      }
    }
  }
LAB_800a006c:
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800a0250) */
/* __thiscall dAttLook_c::requestF(fopAc_ac_c *,
                                   short,
                                   int) */

undefined4 __thiscall
dAttLook_c::requestF(dAttLook_c *this,fopAc_ac_c *param_1,short param_2,int param_3)

{
  daPy_lk_c *pdVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  float fVar7;
  cSAngle local_68 [2];
  float local_64;
  cSGlobe cStack96;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  cXyz local_34;
  undefined auStack8 [8];
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((int)this->field_0x4 < param_3) {
    uVar3 = 0;
  }
  else {
    ::cXyz::operator__(&local_40,&param_1->mEyePos,
                       &((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent
                        .mEyePos);
    local_34.x = local_40.x;
    local_34.y = local_40.y;
    local_34.z = local_40.z;
    local_58.x = local_40.x;
    local_58.y = d_attention::0_0;
    local_58.z = local_40.z;
    fVar7 = mtx::PSVECSquareMag(&local_58);
    dVar6 = (double)fVar7;
    if ((double)d_attention::0_0 < dVar6) {
      dVar5 = 1.0 / SQRT(dVar6);
      dVar5 = d_attention::_4358 * dVar5 * (d_attention::_4359 - dVar6 * dVar5 * dVar5);
      dVar5 = d_attention::_4358 * dVar5 * (d_attention::_4359 - dVar6 * dVar5 * dVar5);
      local_64 = (float)(dVar6 * d_attention::_4358 * dVar5 *
                                 (d_attention::_4359 - dVar6 * dVar5 * dVar5));
      dVar6 = (double)local_64;
    }
    if (param_2 != 0) {
      ::cXyz::operator__(&local_4c,&(param_1->mCurrent).mPos,&(pdVar1->parent).parent.mCurrent.mPos)
      ;
      local_34.x = local_4c.x;
      local_34.y = local_4c.y;
      local_34.z = local_4c.z;
      cSGlobe::cSGlobe(&cStack96,&local_34);
      cSAngle::operator__(local_68,&cStack96.mAngleY,(pdVar1->parent).parent.mCollisionRot.y);
      if (local_68[0] < 0) {
        local_68[0] = -local_68[0];
      }
      if (param_2 < local_68[0]) {
        uVar3 = 0;
        goto LAB_800a0250;
      }
    }
    if ((param_3 < (int)this->field_0x4) || (dVar6 < (double)this->field_0x8)) {
      this->field_0x4 = param_3;
      if (param_1 == (fopAc_ac_c *)0x0) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = (param_1->parent).parent.mBsPcId;
      }
      this->field_0x0 = uVar2;
      this->field_0x8 = (float)dVar6;
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
LAB_800a0250:
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar3;
}

