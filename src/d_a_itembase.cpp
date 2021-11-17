#include <d_a_itembase.h>
#include <d_com_inf_game.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_resorce.h>
#include <m_Do_ext.h>
#include <JKernel/JKRHeap.h>
#include <d_a_itembase.h>
#include <d_item.h>
#include <d_drawlist.h>
#include <d_kankyo.h>
#include <daItemBase_c.h>


/* __thiscall daItemBase_c::DeleteBase(char const *) */

undefined4 __thiscall daItemBase_c::DeleteBase(daItemBase_c *this,char *param_1)

{
  d_com_inf_game::dComIfG_resDelete(&this->mPhs,param_1);
  return 1;
}


/* __thiscall daItemBase_c::clothCreate(void) */

undefined4 __thiscall daItemBase_c::clothCreate(daItemBase_c *this)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x800f8a84) */
/* __thiscall daItemBase_c::CreateItemHeap(char const *,
                                           short,
                                           short,
                                           short,
                                           short,
                                           short,
                                           short,
                                           short) */

bool __thiscall
daItemBase_c::CreateItemHeap
          (daItemBase_c *this,char *pArcName,short resIdx,short btkAnm1,short btkAnm2,short brkAnm1,
          short brkAnm2,short bckAnm,short param_8)

{
  dItem_data__ItemNo dVar1;
  byte bVar2;
  J3DModelData *pModel;
  ulong uVar3;
  J3DModel *pJVar4;
  J3DAnmTextureSRTKey *pJVar5;
  mDoExt_btkAnm *local_r3_472;
  int iVar6;
  mDoExt_btkAnm *pmVar7;
  J3DAnmTevRegKey *pJVar8;
  mDoExt_brkAnm *pmVar9;
  J3DAnmTransform *pJVar10;
  mDoExt_bckAnm *pmVar11;
  
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     (pArcName,(int)resIdx,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                      0x40);
  if (pModel == (J3DModelData *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_a_itembase.cpp",0x55,"modelData != 0");
    m_Do_printf::OSPanic("d_a_itembase.cpp",0x55,"Halt");
  }
  pJVar4 = m_Do_ext::mDoExt_J3DModel__create(pModel,0,0x11020203);
  this->mpModel = pJVar4;
  if (this->mpModel == (J3DModel *)0x0) {
    return false;
  }
  dVar1 = this->mItemNo;
  if (dVar1 == ThirtyArrows) {
    pJVar4 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11000002);
    this->mpModelArrow[0] = pJVar4;
    if (this->mpModelArrow[0] == (J3DModel *)0x0) {
      return false;
    }
  }
  else {
    if ((TwentyArrows < dVar1) || (dVar1 < TwentyArrows)) {
      this->mpModelArrow[1] = (J3DModel *)0x0;
      this->mpModelArrow[0] = (J3DModel *)0x0;
      goto LAB_800f8bbc;
    }
  }
  pJVar4 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11000002);
  this->mpModelArrow[1] = pJVar4;
  if (this->mpModelArrow[1] == (J3DModel *)0x0) {
    return false;
  }
LAB_800f8bbc:
  this->mpBtkAnm1 = (mDoExt_btkAnm *)0x0;
  if (btkAnm1 != -1) {
    pJVar5 = (J3DAnmTextureSRTKey *)
             dRes_control_c::getRes
                       (pArcName,(int)btkAnm1,
                        d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pJVar5 == (J3DAnmTextureSRTKey *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_a_itembase.cpp",0x8c,"pbtk != 0");
      m_Do_printf::OSPanic("d_a_itembase.cpp",0x8c,"Halt");
    }
    local_r3_472 = (mDoExt_btkAnm *)JKernel::operator_new(0x14);
    if (local_r3_472 != (mDoExt_btkAnm *)0x0) {
      (local_r3_472->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
      (local_r3_472->parent).mpFrameCtrl = (J3DFrameCtrl *)0x0;
      (local_r3_472->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_btkAnm::__vt;
      local_r3_472->mpTexMtxAnm = (J3DTexMtxAnm *)0x0;
    }
    this->mpBtkAnm1 = local_r3_472;
    if ((this->mpBtkAnm1 == (mDoExt_btkAnm *)0x0) ||
       (iVar6 = ::mDoExt_btkAnm::init
                          (this->mpBtkAnm1,pModel,pJVar5,true,Repeat,d_a_itembase::1_0,0,-1,false,0)
       , iVar6 == 0)) {
      return false;
    }
  }
  this->mpBtkAnm2 = (mDoExt_btkAnm *)0x0;
  if (btkAnm2 != -1) {
    pJVar5 = (J3DAnmTextureSRTKey *)
             dRes_control_c::getRes
                       (pArcName,(int)btkAnm2,
                        d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pJVar5 == (J3DAnmTextureSRTKey *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_a_itembase.cpp",0x9c,"pbtk != 0");
      m_Do_printf::OSPanic("d_a_itembase.cpp",0x9c,"Halt");
    }
    pmVar7 = (mDoExt_btkAnm *)JKernel::operator_new(0x14);
    if (pmVar7 != (mDoExt_btkAnm *)0x0) {
      (pmVar7->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
      (pmVar7->parent).mpFrameCtrl = (J3DFrameCtrl *)0x0;
      (pmVar7->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_btkAnm::__vt;
      pmVar7->mpTexMtxAnm = (J3DTexMtxAnm *)0x0;
    }
    this->mpBtkAnm2 = pmVar7;
    if ((this->mpBtkAnm2 == (mDoExt_btkAnm *)0x0) ||
       (iVar6 = ::mDoExt_btkAnm::init
                          (this->mpBtkAnm2,pModel,pJVar5,true,Repeat,d_a_itembase::1_0,0,-1,false,0)
       , iVar6 == 0)) {
      return false;
    }
  }
  this->mpBrkAnm1 = (mDoExt_brkAnm *)0x0;
  if (brkAnm1 != -1) {
    pJVar8 = (J3DAnmTevRegKey *)
             dRes_control_c::getRes
                       (pArcName,(int)brkAnm1,
                        d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pJVar8 == (J3DAnmTevRegKey *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_a_itembase.cpp",0xac,"pbrk != 0");
      m_Do_printf::OSPanic("d_a_itembase.cpp",0xac,"Halt");
    }
    bVar2 = dItem_data::item_resource[this->mItemNo].mTevRegAnimFrameIndex;
    pmVar9 = (mDoExt_brkAnm *)JKernel::operator_new(0x18);
    if (pmVar9 != (mDoExt_brkAnm *)0x0) {
      (pmVar9->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
      (pmVar9->parent).mpFrameCtrl = (J3DFrameCtrl *)0x0;
      (pmVar9->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_brkAnm::__vt;
      pmVar9->mpCRegAnm = (J3DTevColorAnm *)0x0;
      pmVar9->mpKRegAnm = (J3DTevKColorAnm *)0x0;
    }
    this->mpBrkAnm1 = pmVar9;
    if ((this->mpBrkAnm1 == (mDoExt_brkAnm *)0x0) ||
       (iVar6 = ::mDoExt_brkAnm::init
                          (this->mpBrkAnm1,pModel,pJVar8,bVar2 == 0xff,Repeat,d_a_itembase::1_0,0,-1
                           ,false,0), iVar6 == 0)) {
      return false;
    }
  }
  this->mpBrkAnm2 = (mDoExt_brkAnm *)0x0;
  if (brkAnm2 != -1) {
    pJVar8 = (J3DAnmTevRegKey *)
             dRes_control_c::getRes
                       (pArcName,(int)brkAnm2,
                        d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pJVar8 == (J3DAnmTevRegKey *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_a_itembase.cpp",0xc5,"pbrk != 0");
      m_Do_printf::OSPanic("d_a_itembase.cpp",0xc5,"Halt");
    }
    pmVar9 = (mDoExt_brkAnm *)JKernel::operator_new(0x18);
    if (pmVar9 != (mDoExt_brkAnm *)0x0) {
      (pmVar9->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
      (pmVar9->parent).mpFrameCtrl = (J3DFrameCtrl *)0x0;
      (pmVar9->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_brkAnm::__vt;
      pmVar9->mpCRegAnm = (J3DTevColorAnm *)0x0;
      pmVar9->mpKRegAnm = (J3DTevKColorAnm *)0x0;
    }
    this->mpBrkAnm2 = pmVar9;
    if ((this->mpBrkAnm2 == (mDoExt_brkAnm *)0x0) ||
       (iVar6 = ::mDoExt_brkAnm::init
                          (this->mpBrkAnm2,pModel,pJVar8,true,Repeat,d_a_itembase::1_0,0,-1,false,0)
       , iVar6 == 0)) {
      return false;
    }
  }
  this->mpBckAnm = (mDoExt_bckAnm *)0x0;
  if (bckAnm != -1) {
    pJVar10 = (J3DAnmTransform *)
              dRes_control_c::getRes
                        (pArcName,(int)bckAnm,
                         d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pJVar10 == (J3DAnmTransform *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_a_itembase.cpp",0xd4,"pbck != 0");
      m_Do_printf::OSPanic("d_a_itembase.cpp",0xd4,"Halt");
    }
    pmVar11 = (mDoExt_bckAnm *)JKernel::operator_new(0x10);
    if (pmVar11 != (mDoExt_bckAnm *)0x0) {
      (pmVar11->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
      (pmVar11->parent).mpFrameCtrl = (J3DFrameCtrl *)0x0;
      (pmVar11->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_bckAnm::__vt;
      pmVar11->mpMtxCalc = (J3DMtxCalc *)0x0;
    }
    this->mpBckAnm = pmVar11;
    if ((this->mpBckAnm == (mDoExt_bckAnm *)0x0) ||
       (iVar6 = ::mDoExt_bckAnm::init
                          (this->mpBckAnm,pModel,pJVar10,true,Repeat,d_a_itembase::1_0,0,-1,false),
       iVar6 == 0)) {
      return false;
    }
  }
  iVar6 = (*(code *)this->vtbl->clothCreate)(this);
  return iVar6 != 0;
}


/* __thiscall daItemBase_c::DrawBase(void) */

undefined4 __thiscall daItemBase_c::DrawBase(daItemBase_c *this)

{
  (*(code *)this->vtbl->setTevStr)();
  (*(code *)this->vtbl->animEntry)(this);
  (*(code *)this->vtbl->setListStart)(this);
  (*(code *)this->vtbl->settingBeforeDraw)(this);
  m_Do_ext::mDoExt_modelUpdateDL(this->mpModel);
  if (this->mpModelArrow[0] != (J3DModel *)0x0) {
    m_Do_ext::mDoExt_modelUpdateDL(this->mpModelArrow[0]);
  }
  if (this->mpModelArrow[1] != (J3DModel *)0x0) {
    m_Do_ext::mDoExt_modelUpdateDL(this->mpModelArrow[1]);
  }
  setListEnd(this);
  (*(code *)this->vtbl->setShadow)(this);
  return 1;
}


/* __thiscall daItemBase_c::setListStart(void) */

void __thiscall daItemBase_c::setListStart(daItemBase_c *this)

{
  if (mDoGph_gInf_c::mMonotone == 0) {
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffXlu;
    return;
  }
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0xc;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x10
  ;
  return;
}


/* __thiscall daItemBase_c::setListEnd(void) */

void __thiscall daItemBase_c::setListEnd(daItemBase_c *this)

{
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  return;
}


/* __thiscall daItemBase_c::settingBeforeDraw(void) */

void __thiscall daItemBase_c::settingBeforeDraw(daItemBase_c *this)

{
  dItem_data__ItemNo dVar1;
  bool bVar2;
  
  bVar2 = d_item::isBomb(this->mItemNo);
  if (bVar2 != false) {
    *(float *)(*(int *)&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x2eb0 + 8) =
         d_a_itembase::_4340;
    (*(this->mpModel->mpModelData->mJointTree).mpJoints)->mpMtxCalc = (J3DMtxCalc *)0x0;
  }
  dVar1 = this->mItemNo;
  if (((dVar1 == Bombs) || (dVar1 == SkullHammer)) || (dVar1 == SmallKey)) {
    d_drawlist::dDlst_texSpecmapST
              (&(this->parent).mEyePos,&(this->parent).mTevStr,this->mpModel->mpModelData,
               d_a_itembase::1_0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall daItemBase_c::setTevStr(void) */

void __thiscall daItemBase_c::setTevStr(daItemBase_c *this)

{
  J3DModel *pJVar1;
  int iVar2;
  int iVar3;
  
  dScnKy_env_light_c::settingTevStruct
            (&d_kankyo::g_env_light,Actor,&(this->parent).mCurrent.mPos,&(this->parent).mTevStr);
  dScnKy_env_light_c::setLightTevColorType
            (&d_kankyo::g_env_light,this->mpModel,&(this->parent).mTevStr);
  iVar2 = 0;
  iVar3 = 0;
  do {
    pJVar1 = *(J3DModel **)((int)this->mpModelArrow + iVar3);
    if (pJVar1 != (J3DModel *)0x0) {
      dScnKy_env_light_c::setLightTevColorType
                (&d_kankyo::g_env_light,pJVar1,&(this->parent).mTevStr);
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar2 < 2);
  return;
}


/* __thiscall daItemBase_c::setShadow(void) */

void __thiscall daItemBase_c::setShadow(daItemBase_c *this)

{
  float fVar1;
  int iVar2;
  
  fVar1 = (this->parent).mScale.x *
          (float)((double)CONCAT44(0x43300000,
                                   (uint)dItem_data::item_info[this->mItemNo].mMaybeShadowRelated) -
                 d_a_itembase::_4369);
  if ((dItem_data::item_info[this->mItemNo].mSpecialBehaviors & UseNonSimpleShadows?) == 0) {
    d_com_inf_game::dComIfGd_setSimpleShadow2
              (&(this->parent).mCurrent.mPos,(this->mAcch).field_0x94,fVar1,
               &(this->mAcch).mGndChk.parent.mPolyInfo,0,d_a_itembase::1_0,
               &dDlst_shadowControl_c::mSimpleTexObj);
  }
  else {
    iVar2 = d_com_inf_game::dComIfGd_setShadow
                      (*(ulong *)&this->field_0x62c,1,this->mpModel,&(this->parent).mCurrent.mPos,
                       d_a_itembase::_4367,fVar1,(this->parent).mCurrent.mPos.y,
                       (this->mAcch).field_0x94,&(this->mAcch).mGndChk.parent.mPolyInfo,
                       &(this->parent).mTevStr,0,d_a_itembase::1_0,
                       &dDlst_shadowControl_c::mSimpleTexObj);
    *(int *)&this->field_0x62c = iVar2;
  }
  return;
}


/* __thiscall daItemBase_c::animEntry(void) */

void __thiscall daItemBase_c::animEntry(daItemBase_c *this)

{
  mDoExt_brkAnm *pmVar1;
  mDoExt_btkAnm *pmVar2;
  mDoExt_bckAnm *this_00;
  
  pmVar1 = this->mpBrkAnm1;
  if (pmVar1 != (mDoExt_brkAnm *)0x0) {
    if ((int)(char)dItem_data::item_resource[this->mItemNo].mTevRegAnimFrameIndex == 0xffffffff) {
      ::mDoExt_brkAnm::entry
                (pmVar1,this->mpModel->mpModelData,((pmVar1->parent).mpFrameCtrl)->mCurrentTime);
    }
    else {
      ::mDoExt_brkAnm::entry
                (pmVar1,this->mpModel->mpModelData,
                 (float)((double)CONCAT44(0x43300000,
                                          (int)(char)dItem_data::item_resource[this->mItemNo].
                                                     mTevRegAnimFrameIndex ^ 0x80000000) -
                        d_a_itembase::_4449));
    }
  }
  pmVar2 = this->mpBtkAnm1;
  if (pmVar2 != (mDoExt_btkAnm *)0x0) {
    ::mDoExt_btkAnm::entry
              (pmVar2,this->mpModel->mpModelData,((pmVar2->parent).mpFrameCtrl)->mCurrentTime);
  }
  pmVar1 = this->mpBrkAnm2;
  if (pmVar1 != (mDoExt_brkAnm *)0x0) {
    ::mDoExt_brkAnm::entry
              (pmVar1,this->mpModel->mpModelData,((pmVar1->parent).mpFrameCtrl)->mCurrentTime);
  }
  pmVar2 = this->mpBtkAnm2;
  if (pmVar2 != (mDoExt_btkAnm *)0x0) {
    ::mDoExt_btkAnm::entry
              (pmVar2,this->mpModel->mpModelData,((pmVar2->parent).mpFrameCtrl)->mCurrentTime);
  }
  this_00 = this->mpBckAnm;
  if (this_00 != (mDoExt_bckAnm *)0x0) {
    ::mDoExt_bckAnm::entry
              (this_00,this->mpModel->mpModelData,((this_00->parent).mpFrameCtrl)->mCurrentTime);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328ea4 */
/* WARNING: Inlined function: FUN_80328ef0 */
/* __thiscall daItemBase_c::animPlay(float,
                                     float,
                                     float,
                                     float,
                                     float) */

void __thiscall
daItemBase_c::animPlay
          (daItemBase_c *this,float param_1,float param_2,float param_3,float param_4,float param_5)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar4 = (double)param_5;
  dVar2 = (double)param_3;
  dVar3 = (double)param_4;
  dVar1 = (double)param_2;
  if ((this->mpBrkAnm1 != (mDoExt_brkAnm *)0x0) &&
     (dItem_data::item_resource[this->mItemNo].mTevRegAnimFrameIndex == 0xff)) {
    ((this->mpBrkAnm1->parent).mpFrameCtrl)->mSpeed = param_1;
    ::mDoExt_baseAnm::play(&this->mpBrkAnm1->parent);
  }
  if (this->mpBtkAnm1 != (mDoExt_btkAnm *)0x0) {
    ((this->mpBtkAnm1->parent).mpFrameCtrl)->mSpeed = (float)dVar2;
    ::mDoExt_baseAnm::play(&this->mpBtkAnm1->parent);
  }
  if (this->mpBrkAnm2 != (mDoExt_brkAnm *)0x0) {
    ((this->mpBrkAnm2->parent).mpFrameCtrl)->mSpeed = (float)dVar1;
    ::mDoExt_baseAnm::play(&this->mpBrkAnm2->parent);
  }
  if (this->mpBtkAnm2 != (mDoExt_btkAnm *)0x0) {
    ((this->mpBtkAnm2->parent).mpFrameCtrl)->mSpeed = (float)dVar3;
    ::mDoExt_baseAnm::play(&this->mpBtkAnm2->parent);
  }
  if (this->mpBckAnm != (mDoExt_bckAnm *)0x0) {
    ((this->mpBckAnm->parent).mpFrameCtrl)->mSpeed = (float)dVar4;
    ::mDoExt_baseAnm::play(&this->mpBckAnm->parent);
  }
  return;
}

