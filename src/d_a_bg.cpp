#include <d_a_bg.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <JKernel/JKRHeap.h>
#include <J3DGraphAnimator/J3DMaterialAnm.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <m_Do_ext.h>
#include <d_a_bg.h>
#include <JUtility/JUTNameTab.h>
#include <d_resorce.h>
#include <d_kankyo.h>
#include <d_bg_w.h>
#include <SComponent/c_bg_w.h>
#include <SComponent/c_bg_s.h>
#include <d_magma.h>
#include <d_grass.h>
#include <d_tree.h>
#include <d_wood.h>
#include <d_flower.h>
#include <f_op_actor.h>
#include <J3DU/J3DUClipper.h>
#include <m_Do_audio.h>
#include <f_op_actor_mng.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_stage.h>
#include <JKernel/JKRSolidHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_com_inf_game.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <d_bg_s.h>
#include <daBg_brkAnm_c.h>
#include <daBg_c.h>
#include <daBg_btkAnm_c.h>


namespace d_a_bg {
undefined arcName$4148;
}

/* __thiscall daBg_c::setArcName(void) */

undefined * __thiscall daBg_c::setArcName(daBg_c *this)

{
  MSL_C.PPCEABI.bare.H::sprintf
            (&d_a_bg::arcName_4148,"Room%d",(this->parent).parent.parent.mParameters);
  return &d_a_bg::arcName_4148;
}


namespace d_a_bg {

/* __stdcall createMatAnm(J3DModelData *,
                          unsigned short) */

undefined4 createMatAnm(int param_1,ushort param_2)

{
  uint uVar1;
  J3DMaterialAnm *this;
  int iVar2;
  
  if (param_2 != 0xffff) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x60) + (uint)param_2 * 4);
    uVar1 = *(uint *)(iVar2 + 0x3c);
    if (0xbfffffff < uVar1) {
      uVar1 = 0;
    }
    if (uVar1 == 0) {
      this = (J3DMaterialAnm *)JKernel::operator_new(0x6c);
      if (this == (J3DMaterialAnm *)0x0) {
        return 0;
      }
      this->vtbl = (undefined *)&J3DMaterialAnm::__vt;
      J3DMaterialAnm::initialize(this);
      *(J3DMaterialAnm **)(iVar2 + 0x3c) = this;
    }
  }
  return 1;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall daBg_btkAnm_c::create(J3DModelData *,
                                    J3DAnmTextureSRTKey *) */

undefined4 __thiscall
daBg_btkAnm_c::create(daBg_btkAnm_c *this,J3DModelData *param_1,J3DAnmTextureSRTKey *param_2)

{
  mDoExt_btkAnm *pmVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  J3DAnmTextureSRTKey *pJVar5;
  
  pmVar1 = (mDoExt_btkAnm *)JKernel::operator_new(0x14);
  if (pmVar1 != (mDoExt_btkAnm *)0x0) {
    (pmVar1->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
    (pmVar1->parent).mpFrameCtrl = (J3DFrameCtrl *)0x0;
    (pmVar1->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_btkAnm::__vt;
    pmVar1->mpTexMtxAnm = (J3DTexMtxAnm *)0x0;
  }
  this->mpAnm = pmVar1;
  if (this->mpAnm == (mDoExt_btkAnm *)0x0) {
    uVar2 = 0;
  }
  else {
    iVar3 = ::mDoExt_btkAnm::init
                      (this->mpAnm,param_1,param_2,true,Repeat,d_a_bg::_4203,0,-1,false,0);
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      pJVar5 = this->mpAnm->mpAnmSRT;
      for (uVar4 = 0; (uVar4 & 0xffff) < (ushort)pJVar5->mTrackCount / 3; uVar4 = uVar4 + 1) {
        iVar3 = d_a_bg::createMatAnm
                          (param_1,((pJVar5->mMaterialNameTable).mpRes)->mEntries
                                   [(uVar4 & 0xffff) - 2]);
        if (iVar3 == 0) {
          return 0;
        }
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}


/* __thiscall daBg_btkAnm_c::entry(J3DModelData *) */

void __thiscall daBg_btkAnm_c::entry(daBg_btkAnm_c *this,J3DModelData *param_1)

{
  char *pcVar1;
  
  ::mDoExt_btkAnm::entry(this->mpAnm,param_1,d_a_bg::_4223);
  pcVar1 = (char *)JUTNameTab::getName((JUTNameTab *)
                                       &(this->mpAnm->mpAnmSRT->mMaterialNameTable).mpStrData,0);
  if ((((*pcVar1 == 'S') && (pcVar1[1] == 'C')) && (pcVar1[2] == '_')) &&
     ((pcVar1[3] == '0' && (pcVar1[4] == '1')))) {
    this->mbIsSC_01 = 1;
  }
  else {
    this->mbIsSC_01 = 0;
  }
  return;
}


/* __thiscall daBg_btkAnm_c::play(void) */

void __thiscall daBg_btkAnm_c::play(daBg_btkAnm_c *this)

{
  if (this->mbIsSC_01 == 1) {
    ((this->mpAnm->parent).mpFrameCtrl)->mCurrentTime =
         (float)((double)CONCAT44(0x43300000,(uint)d_com_inf_game::g_dComIfG_gameInfo._23792_2_) -
                d_a_bg::_4238);
  }
  else {
    ::mDoExt_baseAnm::play(&this->mpAnm->parent);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daBg_brkAnm_c::create(J3DModelData *,
                                    J3DAnmTevRegKey *) */

undefined4 __thiscall
daBg_brkAnm_c::create(daBg_brkAnm_c *this,J3DModelData *param_1,J3DAnmTevRegKey *param_2)

{
  mDoExt_brkAnm *pmVar1;
  undefined4 uVar2;
  int iVar3;
  ushort uVar4;
  J3DAnmTevRegKey *pJVar5;
  
  pmVar1 = (mDoExt_brkAnm *)JKernel::operator_new(0x18);
  if (pmVar1 != (mDoExt_brkAnm *)0x0) {
    (pmVar1->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
    (pmVar1->parent).mpFrameCtrl = (J3DFrameCtrl *)0x0;
    (pmVar1->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_brkAnm::__vt;
    pmVar1->mpCRegAnm = (J3DTevColorAnm *)0x0;
    pmVar1->mpKRegAnm = (J3DTevKColorAnm *)0x0;
  }
  this->mpAnm = pmVar1;
  if (this->mpAnm == (mDoExt_brkAnm *)0x0) {
    uVar2 = 0;
  }
  else {
    iVar3 = ::mDoExt_brkAnm::init
                      (this->mpAnm,param_1,param_2,true,Repeat,d_a_bg::_4203,0,-1,false,0);
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      pJVar5 = this->mpAnm->mpAnm;
      for (uVar4 = 0; uVar4 < *(ushort *)(pJVar5 + 0x10); uVar4 = uVar4 + 1) {
        iVar3 = d_a_bg::createMatAnm
                          (param_1,*(undefined2 *)(*(int *)(pJVar5 + 0x24) + (uint)uVar4 * 2));
        if (iVar3 == 0) {
          return 0;
        }
      }
      for (uVar4 = 0; uVar4 < *(ushort *)(pJVar5 + 0x12); uVar4 = uVar4 + 1) {
        iVar3 = d_a_bg::createMatAnm
                          (param_1,*(undefined2 *)(*(int *)(pJVar5 + 0x38) + (uint)uVar4 * 2));
        if (iVar3 == 0) {
          return 0;
        }
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}


/* __thiscall daBg_brkAnm_c::entry(J3DModelData *) */

void __thiscall daBg_brkAnm_c::entry(daBg_brkAnm_c *this,J3DModelData *param_1)

{
  ::mDoExt_brkAnm::entry(this->mpAnm,param_1,d_a_bg::_4223);
  this->field_0x4 = 0;
  return;
}


/* __thiscall daBg_brkAnm_c::play(void) */

void __thiscall daBg_brkAnm_c::play(daBg_brkAnm_c *this)

{
  ::mDoExt_baseAnm::play(&this->mpAnm->parent);
  return;
}


namespace d_a_bg {

/* __stdcall checkCreateHeap(fopAc_ac_c *) */

void checkCreateHeap(daBg_c *param_1)

{
  ::daBg_c::createHeap(param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* __thiscall daBg_c::createHeap(void) */

undefined4 __thiscall daBg_c::createHeap(daBg_c *this)

{
  dBgW *mpBgW;
  char *pcVar1;
  J3DModelData *pModel;
  J3DAnmTextureSRTKey *pJVar2;
  daBg_btkAnm_c *pdVar3;
  int iVar4;
  J3DAnmTevRegKey *pJVar5;
  daBg_brkAnm_c *pdVar6;
  J3DModel *pJVar7;
  dKy_tevstr_c *pTevStr;
  cBgD_t *pData;
  uint uVar8;
  ushort uVar9;
  ulong uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  daBg___Bg *pBGModel;
  
  pcVar1 = (char *)setArcName(this);
  iVar11 = (this->parent).parent.parent.mParameters;
  pBGModel = this->mBg;
  iVar13 = 0;
  iVar12 = 0;
  do {
    pModel = (J3DModelData *)
             dRes_control_c::getRes
                       (pcVar1,(char *)(l_modelName_localstatic3_createHeap + iVar12),
                        d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
    if (pModel == (J3DModelData *)0x0) {
      pModel = (J3DModelData *)
               dRes_control_c::getRes
                         (pcVar1,(char *)(l_modelName2_localstatic4_createHeap + iVar12),
                          d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
    }
    if (pModel != (J3DModelData *)0x0) {
      uVar10 = 0x11000022;
      for (uVar9 = 0; uVar9 < (pModel->mMaterialTable).mMaterialCount; uVar9 = uVar9 + 1) {
        (pModel->mMaterialTable).mpMaterials[uVar9]->mpMaterialAnm = (J3DMaterialAnm *)0x0;
      }
      pJVar2 = (J3DAnmTextureSRTKey *)
               dRes_control_c::getRes
                         (pcVar1,(char *)(l_btkName_localstatic5_createHeap + iVar12),
                          d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
      if (pJVar2 == (J3DAnmTextureSRTKey *)0x0) {
        pBGModel->mpTexAnm = (daBg_btkAnm_c *)0x0;
      }
      else {
        pdVar3 = (daBg_btkAnm_c *)JKernel::operator_new(8);
        pBGModel->mpTexAnm = pdVar3;
        if (pBGModel->mpTexAnm == (daBg_btkAnm_c *)0x0) {
          return 0;
        }
        iVar4 = daBg_btkAnm_c::create(pBGModel->mpTexAnm,pModel,pJVar2);
        if (iVar4 == 0) {
          return 0;
        }
        uVar10 = 0x11001222;
      }
      pJVar5 = (J3DAnmTevRegKey *)
               dRes_control_c::getRes
                         (pcVar1,(char *)(l_brkName_localstatic6_createHeap + iVar12),
                          d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
      if (pJVar5 == (J3DAnmTevRegKey *)0x0) {
        pBGModel->mpCAnm = (daBg_brkAnm_c *)0x0;
      }
      else {
        pdVar6 = (daBg_brkAnm_c *)JKernel::operator_new(8);
        pBGModel->mpCAnm = pdVar6;
        if (pBGModel->mpCAnm == (daBg_brkAnm_c *)0x0) {
          return 0;
        }
        iVar4 = daBg_brkAnm_c::create(pBGModel->mpCAnm,pModel,pJVar5);
        if (iVar4 == 0) {
          return 0;
        }
      }
      pJVar7 = m_Do_ext::mDoExt_J3DModel__create(pModel,0,uVar10);
      pBGModel->mpModel = pJVar7;
      if (pBGModel->mpModel == (J3DModel *)0x0) {
        return 0;
      }
      pTevStr = (dKy_tevstr_c *)JKernel::operator_new(0xb0);
      if (pTevStr != (dKy_tevstr_c *)0x0) {
        (pTevStr->mLightObj).mPos.x = J3DGraphBase::j3dDefaultLightInfo;
        (pTevStr->mLightObj).mPos.y = DAT_80370d1c;
        (pTevStr->mLightObj).mPos.z = DAT_80370d20;
        (pTevStr->mLightObj).mDir.x = DAT_80370d24;
        (pTevStr->mLightObj).mDir.y = DAT_80370d28;
        (pTevStr->mLightObj).mDir.z = DAT_80370d2c;
        (pTevStr->mLightObj).mColor.r = DAT_80370d30;
        (pTevStr->mLightObj).mColor.g = DAT_80370d31;
        (pTevStr->mLightObj).mColor.b = DAT_80370d32;
        (pTevStr->mLightObj).mColor.a = DAT_80370d33;
        (pTevStr->mLightObj).mCosAtten.x = DAT_80370d34;
        (pTevStr->mLightObj).mCosAtten.y = DAT_80370d38;
        (pTevStr->mLightObj).mCosAtten.z = DAT_80370d3c;
        (pTevStr->mLightObj).mDistAtten.x = DAT_80370d40;
        (pTevStr->mLightObj).mDistAtten.y = DAT_80370d44;
        (pTevStr->mLightObj).mDistAtten.z = DAT_80370d48;
      }
      pBGModel->mpTevStr = pTevStr;
      if (pBGModel->mpTevStr == (dKy_tevstr_c *)0x0) {
        return 0;
      }
      d_kankyo::dKy_tevstr_init(pBGModel->mpTevStr,(char)iVar11,0xff);
    }
    iVar13 = iVar13 + 1;
    pBGModel = pBGModel + 1;
    iVar12 = iVar12 + 0xd;
    if (3 < iVar13) {
      pData = (cBgD_t *)
              dRes_control_c::getRes
                        (pcVar1,"room.dzb",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,
                         0x40);
      if (pData == (cBgD_t *)0x0) {
        this->mpBgW = (dBgW *)0x0;
      }
      else {
        mpBgW = (dBgW *)JKernel::operator_new(0xbc);
        if (mpBgW != (dBgW *)0x0) {
          mpBgW = dBgW::dBgW(mpBgW);
        }
        this->mpBgW = mpBgW;
        if (this->mpBgW == (dBgW *)0x0) {
          return 0;
        }
        uVar8 = cBgW::Set(&this->mpBgW->parent,pData,Global,(MTX34 *)0x0);
        if ((uVar8 & 0xff) != 0) {
          return 0;
        }
        dStage_roomControl_c::mStatus[iVar11].mpBgW = this->mpBgW;
        (this->mpBgW->parent).mWallCorrectPriority = 0;
      }
      return 1;
    }
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daBg_c::~daBg_c(void) */

void __thiscall daBg_c::_daBg_c(daBg_c *this)

{
  short in_r4;
  int iVar1;
  
  if (this != (daBg_c *)0x0) {
    iVar1 = (this->parent).parent.parent.mParameters;
    if (((this->parent).mpHeap != (JKRHeap *)0x0) && (this->mpBgW != (dBgW *)0x0)) {
      cBgS::Release((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&this->mpBgW->parent);
      dStage_roomControl_c::mStatus[iVar1].mpBgW = (dBgW *)0x0;
    }
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMagmaPacket != (dMagma_packet_c *)0x0) {
      dMagma_room_c::deleteFloor
                ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMagmaPacket)->mRoom + iVar1);
    }
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpGrassPacket != (dGrass_packet_c *)0x0) {
      dGrass_room_c::deleteData
                ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpGrassPacket)->mGrassRoom + iVar1);
    }
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket != (dTree_packet_c *)0x0) {
      dTree_room_c::deleteData
                ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpTreePacket)->mRoom + iVar1);
    }
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpWoodPacket != (Packet_c *)0x0) {
      dWood::Packet_c::delete_room(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpWoodPacket,iVar1);
    }
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFlowerPacket != (dFlower_packet_c *)0x0) {
      dFlower_room_c::deleteData
                ((dFlower_room_c *)
                 (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpFlowerPacket + iVar1 * 4 + 0x44f4));
    }
    dStage_roomControl_c::mStatus[iVar1].mFlags =
         dStage_roomControl_c::mStatus[iVar1].mFlags & ~HasBgW;
    fopAc_ac_c::_fopAc_ac_c(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_a_bg {

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall daBg_Draw(daBg_c *) */

undefined4 daBg_Draw(daBg_c *param_1)

{
  mDoExt_btkAnm *pmVar1;
  mDoExt_brkAnm *pmVar2;
  J3DModel *pModel;
  int iVar3;
  int iVar4;
  daBg___Bg *pdVar5;
  
  iVar4 = (param_1->parent).parent.parent.mParameters;
  pdVar5 = param_1->mBg;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufWorldOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufWorldXlu;
  mDoLib_clipper::mClipper.mFar = _4604;
  J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
  iVar3 = 0;
  do {
    pModel = pdVar5->mpModel;
    if (pModel != (J3DModel *)0x0) {
      if (pdVar5->mpTexAnm != (daBg_btkAnm_c *)0x0) {
        pmVar1 = pdVar5->mpTexAnm->mpAnm;
        (pmVar1->mpAnmSRT->parent).mCurrentTime = ((pmVar1->parent).mpFrameCtrl)->mCurrentTime;
      }
      if (pdVar5->mpCAnm != (daBg_brkAnm_c *)0x0) {
        pmVar2 = pdVar5->mpCAnm->mpAnm;
        *(float *)(pmVar2->mpAnm + 8) = ((pmVar2->parent).mpFrameCtrl)->mCurrentTime;
      }
      (*(code *)pModel->vtbl->calc)(pModel);
      J3DUClipper::clipByBox(&mDoLib_clipper::mClipper,pModel);
      dScnKy_env_light_c::settingTevStruct
                (&d_kankyo::g_env_light,(char)iVar3 + BG0,(cXyz *)0x0,pdVar5->mpTevStr);
      dScnKy_env_light_c::setLightTevColorType(&d_kankyo::g_env_light,pModel,pdVar5->mpTevStr);
      m_Do_ext::mDoExt_modelEntryDL(pModel);
    }
    iVar3 = iVar3 + 1;
    pdVar5 = pdVar5 + 1;
  } while (iVar3 < 4);
  mDoLib_clipper::mClipper.mFar = mDoLib_clipper::mSystemFar;
  J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  dScnKy_env_light_c::settingTevStruct
            (&d_kankyo::g_env_light,BG0,(cXyz *)0x0,&dStage_roomControl_c::mStatus[iVar4].mTevStr);
  return 1;
}


/* __stdcall daBg_Execute(daBg_c *) */

undefined4 daBg_Execute(daBg_c *param_1)

{
  char cVar2;
  int iVar1;
  daBg___Bg *pdVar3;
  
  if (param_1->mUnloadTimer == 0) {
    if ((dStage_roomControl_c::mStatus[(param_1->parent).parent.parent.mParameters].mFlags &
        IsUnloading) == 0) {
      pdVar3 = param_1->mBg;
      iVar1 = 0;
      do {
        if ((mDoGph_gInf_c::mMonotone == 0) || (iVar1 == 2)) {
          if (pdVar3->mpTexAnm != (daBg_btkAnm_c *)0x0) {
            ::daBg_btkAnm_c::play(pdVar3->mpTexAnm);
          }
          if (pdVar3->mpCAnm != (daBg_brkAnm_c *)0x0) {
            ::daBg_brkAnm_c::play(pdVar3->mpCAnm);
          }
        }
        iVar1 = iVar1 + 1;
        pdVar3 = pdVar3 + 1;
      } while (iVar1 < 4);
    }
    else {
      iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea");
      if (iVar1 == 0) {
        param_1->mUnloadTimer = 0x10;
      }
      else {
        param_1->mUnloadTimer = 1;
      }
    }
  }
  else {
    cVar2 = m_Do_audio::cLib_calcTimer(&param_1->mUnloadTimer);
    if (cVar2 == '\0') {
      f_op_actor_mng::fopAcM_delete((base_process_class *)param_1);
    }
  }
  return 1;
}


/* __stdcall daBg_IsDelete(daBg_c *) */

uint daBg_IsDelete(int param_1)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros((uint)*(byte *)(param_1 + 0x2dc));
  return uVar1 >> 5;
}


/* __stdcall daBg_Delete(daBg_c *) */

undefined4 daBg_Delete(daBg_c *param_1)

{
  ::daBg_c::_daBg_c(param_1);
  return 1;
}


/* __stdcall daBg_Create(fopAc_ac_c *) */

void daBg_Create(daBg_c *param_1)

{
  ::daBg_c::create(param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall daBg_c::create(void) */

undefined4 __thiscall daBg_c::create(daBg_c *this)

{
  JKRHeap *pParent;
  JKRSolidHeap *pJVar1;
  ulong uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  J3DModel *pJVar7;
  daBg___Bg *pdVar8;
  J3DModelData *pJVar9;
  int iVar10;
  short local_38 [2];
  float local_34;
  float local_30 [5];
  
  if (((this->parent).mCondition & Constructed) == 0) {
    if (this != (daBg_c *)0x0) {
      fopAc_ac_c::fopAc_ac_c(&this->parent);
    }
    (this->parent).mCondition = (this->parent).mCondition | Constructed;
  }
  iVar10 = (this->parent).parent.parent.mParameters;
  pParent = dStage_roomControl_c::getMemoryBlock(iVar10);
  if (pParent == (JKRHeap *)0x0) {
    uVar5 = f_op_actor_mng::fopAcM_entrySolidHeap(&this->parent,d_a_bg::checkCreateHeap,0);
    if ((uVar5 & 0xff) == 0) {
      d_stage::dStage_escapeRestart();
      return 5;
    }
  }
  else {
    pJVar1 = JKRSolidHeap::create(0xffffffff,pParent,false);
    (this->parent).mpHeap = &pJVar1->parent;
    if ((this->parent).mpHeap == (JKRHeap *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_a_bg.cpp",0x2fd,"heap != 0");
      m_Do_printf::OSPanic("d_a_bg.cpp",0x2fd,&DAT_8035b991);
    }
    uVar3 = m_Do_ext::mDoExt_setCurrentHeap((this->parent).mpHeap);
    iVar4 = createHeap(this);
    if (iVar4 != 1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_a_bg.cpp",0x302,"rt == 1");
      m_Do_printf::OSPanic("d_a_bg.cpp",0x302,&DAT_8035b991);
    }
    m_Do_ext::mDoExt_setCurrentHeap(uVar3);
    JKRSolidHeap::adjustSize((JKRSolidHeap *)(this->parent).mpHeap);
  }
  pdVar8 = this->mBg;
  iVar4 = 0;
  do {
    if (pdVar8->mpModel != (J3DModel *)0x0) {
      pJVar9 = pdVar8->mpModel->mpModelData;
      if (pdVar8->mpTexAnm != (daBg_btkAnm_c *)0x0) {
        daBg_btkAnm_c::entry(pdVar8->mpTexAnm,pJVar9);
      }
      if (pdVar8->mpCAnm != (daBg_brkAnm_c *)0x0) {
        daBg_brkAnm_c::entry(pdVar8->mpCAnm,pJVar9);
      }
    }
    iVar4 = iVar4 + 1;
    pdVar8 = pdVar8 + 1;
  } while (iVar4 < 4);
  uVar5 = d_com_inf_game::dComIfGp_getMapTrans(iVar10,local_30,&local_34,local_38);
  if ((uVar5 & 0xff) != 0) {
    pdVar8 = this->mBg;
    iVar4 = 0;
    do {
      pJVar7 = pdVar8->mpModel;
      if (pJVar7 != (J3DModel *)0x0) {
        mtx::PSMTXTrans((double)local_30[0],(double)d_a_bg::_4223,(double)local_34,
                        &mDoMtx_stack_c::now);
        m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,local_38[0]);
        mtx::PSMTXCopy(&mDoMtx_stack_c::now,&pJVar7->mBaseMtx);
      }
      iVar4 = iVar4 + 1;
      pdVar8 = pdVar8 + 1;
    } while (iVar4 < 4);
  }
  if ((this->mpBgW == (dBgW *)0x0) ||
     (cVar6 = dBgS::Regist(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,this->mpBgW,&this->parent)
     , cVar6 == '\0')) {
    d_kankyo::dKy_tevstr_init(&dStage_roomControl_c::mStatus[iVar10].mTevStr,(char)iVar10,0xff);
    dStage_roomControl_c::mStatus[iVar10].mFlags =
         dStage_roomControl_c::mStatus[iVar10].mFlags | HasBgW;
    uVar3 = 4;
  }
  else {
    d_stage::dStage_escapeRestart();
    uVar3 = 5;
  }
  return uVar3;
}

