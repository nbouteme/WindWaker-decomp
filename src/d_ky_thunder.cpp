#include <d_ky_thunder.h>
#include <m_Do_ext.h>
#include <os/OSCache.h>
#include <d_ky_thunder.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <mtx/mtx.h>
#include <J3DGraphAnimator/J3DMaterialAttach.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <f_op_kankyo_mng.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <SComponent/c_math.h>
#include <d_kankyo_rain.h>
#include <dThunder_c.h>


/* __thiscall dThunder_c::createHeap(void) */

undefined4 __thiscall dThunder_c::createHeap(dThunder_c *this)

{
  JKRSolidHeap *pJVar1;
  
  if (this->mpHeap == (JKRHeap *)0x0) {
    pJVar1 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(0x4a0,0x20);
    this->mpHeap = &pJVar1->parent;
    if (this->mpHeap == (JKRHeap *)0x0) {
      return 0;
    }
  }
  return 1;
}


/* __thiscall dThunder_c::adjustHeap(void) */

void __thiscall dThunder_c::adjustHeap(dThunder_c *this)

{
  uint uVar1;
  
  m_Do_ext::mDoExt_restoreCurrentHeap();
  uVar1 = m_Do_ext::mDoExt_adjustSolidHeap((JKRSolidHeap *)this->mpHeap);
  if (-1 < (int)uVar1) {
    os::DCStoreRangeNoSync(this->mpHeap->mpDataBegin,this->mpHeap->mSize);
  }
  return;
}


namespace d_ky_thunder {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dThunder_Draw(dThunder_c *) */

undefined4 dThunder_Draw(dThunder_c *param_1)

{
  J3DModel *pJVar1;
  MTX34 MStack72;
  longlong local_18;
  longlong local_10;
  
  if (::dThunder_c::init_localstatic4_draw == (code)0x0) {
    ::dThunder_c::l_offsetPos_localstatic3_draw.x = _4210;
    ::dThunder_c::l_offsetPos_localstatic3_draw.y = _4211;
    ::dThunder_c::l_offsetPos_localstatic3_draw.z = _4212;
    Runtime.PPCEABI.H::__register_global_object
              (::dThunder_c::l_offsetPos_localstatic3_draw,::cXyz::_cXyz,&_4142);
    ::dThunder_c::init_localstatic4_draw = (code)0x1;
  }
  mtx::PSMTXTrans((double)(param_1->mPos).x,(double)(param_1->mPos).y,(double)(param_1->mPos).z,
                  &mDoMtx_stack_c::now);
  local_18 = (longlong)(int)param_1->mRotation;
  m_Do_mtx::mDoMtx_ZrotM(&mDoMtx_stack_c::now,(short)(int)param_1->mRotation);
  local_10 = (longlong)(int)param_1->mRotation;
  m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,(short)(int)param_1->mRotation);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,&MStack72);
  pJVar1 = param_1->mpModel;
  (pJVar1->mBaseScale).x = (param_1->mScale).x;
  (pJVar1->mBaseScale).y = (param_1->mScale).y;
  (pJVar1->mBaseScale).z = (param_1->mScale).z;
  mtx::PSMTXCopy(&MStack72,&param_1->mpModel->mBaseMtx);
  ::mDoExt_btkAnm::entry(&param_1->mBtkAnm,param_1->mpModel->mpModelData,param_1->mBtkTime);
  ::mDoExt_brkAnm::entry
            (&param_1->mBrkAnm,param_1->mpModel->mpModelData,
             ((param_1->mBrkAnm).parent.mpFrameCtrl)->mCurrentTime);
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  m_Do_ext::mDoExt_modelUpdateDL(param_1->mpModel);
  mDoExt_invisibleModel::entryMaskOff(&param_1->mInvisibleModel);
  J3DMaterialTable::removeTexMtxAnimator
            (&param_1->mpModel->mpModelData->mMaterialTable,(param_1->mBtkAnm).mpAnmSRT);
  J3DMaterialTable::removeTevRegAnimator
            (&param_1->mpModel->mpModelData->mMaterialTable,(param_1->mBrkAnm).mpAnm);
  return 1;
}


/* __stdcall dThunder_Execute(dThunder_c *) */

undefined4 dThunder_Execute(dThunder_c *param_1)

{
  int iVar1;
  
  ((param_1->mBrkAnm).parent.mpFrameCtrl)->mSpeed = 1_0;
  iVar1 = ::mDoExt_baseAnm::play(&(param_1->mBrkAnm).parent);
  if (iVar1 != 0) {
    JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x69f6,&param_1->mPos,0,0,1_0,1_0,_1_0,_1_0,0);
    f_op_kankyo_mng::fopKyM_Delete(param_1);
  }
  return 1;
}


/* __stdcall dThunder_IsDelete(dThunder_c *) */

undefined4 dThunder_IsDelete(void)

{
  return 1;
}


/* __stdcall dThunder_Delete(dThunder_c *) */

undefined4 dThunder_Delete(int param_1)

{
  JAIZelBasic::seDeleteObject(JAIZelBasic::zel_basic,(Vec *)(param_1 + 0x140));
  JAIZelBasic::seDeleteObject(JAIZelBasic::zel_basic,(Vec *)(param_1 + 0x14c));
  if (param_1 != 0) {
    m_Do_ext::mDoExt_destroySolidHeap(*(undefined4 *)(param_1 + 0xf8));
    if (param_1 != -0xfc) {
      if (param_1 != -0x11c) {
        *(undefined ***)(param_1 + 0x11c) = &::mDoExt_brkAnm::__vt;
        if (param_1 != -0x11c) {
          *(undefined ***)(param_1 + 0x11c) = &::mDoExt_baseAnm::__vt;
        }
      }
      if ((param_1 != -0x108) &&
         (*(undefined ***)(param_1 + 0x108) = &::mDoExt_btkAnm::__vt, param_1 != -0x108)) {
        *(undefined ***)(param_1 + 0x108) = &::mDoExt_baseAnm::__vt;
      }
    }
  }
  return 1;
}


/* __stdcall dThunder_Create(kankyo_class *) */

undefined4 dThunder_Create(dThunder_c *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ::dThunder_c::createHeap(param_1);
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else {
    uVar2 = ::dThunder_c::create(param_1);
    ::dThunder_c::adjustHeap(param_1);
  }
  return uVar2;
}

}

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x801990ac) */
/* __thiscall dThunder_c::create(void) */

undefined4 __thiscall dThunder_c::create(dThunder_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  J3DModelData *pModel;
  ulong uVar4;
  J3DModel *pJVar5;
  undefined4 uVar6;
  int iVar7;
  J3DAnmTextureSRTKey *pAnm;
  J3DAnmTevRegKey *pJVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  double dVar12;
  undefined8 in_f31;
  double dVar13;
  float fVar14;
  float fVar15;
  cXyz fwd;
  undefined auStack8 [8];
  camera_class *pCamera;
  
  pCamera = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (this != (dThunder_c *)0x0) {
    (this->mBtkAnm).parent.vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
    (this->mBtkAnm).parent.mpFrameCtrl = (J3DFrameCtrl *)0x0;
    (this->mBtkAnm).parent.vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_btkAnm::__vt;
    (this->mBtkAnm).mpTexMtxAnm = (J3DTexMtxAnm *)0x0;
    (this->mBrkAnm).parent.vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
    (this->mBrkAnm).parent.mpFrameCtrl = (J3DFrameCtrl *)0x0;
    (this->mBrkAnm).parent.vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_brkAnm::__vt;
    (this->mBrkAnm).mpCRegAnm = (J3DTevColorAnm *)0x0;
    (this->mBrkAnm).mpKRegAnm = (J3DTevKColorAnm *)0x0;
  }
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     ("Always",0x3e,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pModel == (J3DModelData *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_ky_thunder.cpp",0x6e,"modelData != 0");
    m_Do_printf::OSPanic("d_ky_thunder.cpp",0x6e,&DAT_8035f02f);
  }
  pJVar5 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x1000200);
  this->mpModel = pJVar5;
  if (this->mpModel == (J3DModel *)0x0) {
    uVar6 = 5;
  }
  else {
    iVar7 = mDoExt_invisibleModel::create(&this->mInvisibleModel,this->mpModel);
    if (iVar7 == 0) {
      uVar6 = 5;
    }
    else {
      pAnm = (J3DAnmTextureSRTKey *)
             dRes_control_c::getRes
                       ("Always",0x60,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      if (pAnm == (J3DAnmTextureSRTKey *)0x0) {
        uVar4 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar4,"d_ky_thunder.cpp",0x7d,"anm != 0");
        m_Do_printf::OSPanic("d_ky_thunder.cpp",0x7d,&DAT_8035f02f);
      }
      iVar7 = ::mDoExt_btkAnm::init
                        (&this->mBtkAnm,pModel,pAnm,false,Repeat,d_ky_thunder::1_0,0,-1,false,0);
      if (iVar7 == 0) {
        uVar6 = 5;
      }
      else {
        pJVar8 = (J3DAnmTevRegKey *)
                 dRes_control_c::getRes
                           ("Always",0x52,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                            0x40);
        if (pJVar8 == (J3DAnmTevRegKey *)0x0) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar4,"d_ky_thunder.cpp",0x8c,"canm != 0");
          m_Do_printf::OSPanic("d_ky_thunder.cpp",0x8c,&DAT_8035f02f);
        }
        iVar7 = ::mDoExt_brkAnm::init
                          (&this->mBrkAnm,pModel,pJVar8,true,Once,d_ky_thunder::1_0,0,-1,false,0);
        if (iVar7 == 0) {
          uVar6 = 5;
        }
        else {
          fVar14 = SComponent::cM_rndF(d_ky_thunder::1_0);
          this->mBtkTime = fVar14;
          fVar3 = d_ky_thunder::_4385;
          fVar15 = d_ky_thunder::_4384;
          fVar14 = d_ky_thunder::_4383;
          if (d_kankyo::g_env_light.mThunderStateTimer < 10) {
            fVar14 = d_ky_thunder::1_0;
          }
          dVar13 = (double)fVar14;
          this->mRotation = d_ky_thunder::_4386;
          fVar14 = SComponent::cM_rndFX(this->mRotation);
          this->mRotation = (float)(dVar13 * (double)fVar14);
          fVar14 = SComponent::cM_rndF(d_ky_thunder::15_0);
          (this->mScale).x = (float)(dVar13 * (double)(d_ky_thunder::5_0 + fVar14));
          fVar14 = SComponent::cM_rndFX(d_ky_thunder::1_0);
          if (d_ky_thunder::0_5 <= (double)fVar14) {
            (this->mScale).x = (this->mScale).x * d_ky_thunder::_1_0;
          }
          fVar14 = SComponent::cM_rndF(d_ky_thunder::60_0);
          (this->mScale).y = (float)(dVar13 * (double)(d_ky_thunder::20_0 + fVar14));
          (this->mScale).z = d_ky_thunder::1_0;
          d_kankyo_rain::dKyr_get_vectle_calc(&pCamera->mEyePos,&pCamera->mCenterPos,&fwd);
          dVar13 = (double)(fwd.x * fwd.x + fwd.z * fwd.z);
          if ((double)d_ky_thunder::_4210 < dVar13) {
            dVar12 = 1.0 / SQRT(dVar13);
            dVar12 = d_ky_thunder::0_5 * dVar12 * (d_ky_thunder::_4392 - dVar13 * dVar12 * dVar12);
            dVar12 = d_ky_thunder::0_5 * dVar12 * (d_ky_thunder::_4392 - dVar13 * dVar12 * dVar12);
            dVar13 = (double)(float)(dVar13 * d_ky_thunder::0_5 * dVar12 *
                                              (d_ky_thunder::_4392 - dVar13 * dVar12 * dVar12));
          }
          iVar7 = SComponent::cM_atan2s(fwd.x,fwd.z);
          uVar9 = SComponent::cM_atan2s(fwd.y,(float)dVar13);
          fVar14 = SComponent::cM_rndFX(d_ky_thunder::1_0);
          if (fVar14 < d_ky_thunder::_4210) {
            uVar10 = iVar7 - 0x4000;
          }
          else {
            uVar10 = SEXT24((short)((short)iVar7 + 0x4000));
          }
          fVar14 = JKernel::JMath::jmaCosTable
                   [(int)(uVar9 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
          iVar7 = (int)(uVar10 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
          fVar1 = JKernel::JMath::jmaSinTable[iVar7];
          fVar2 = JKernel::JMath::jmaCosTable[iVar7];
          fVar15 = SComponent::cM_rndF(fVar15);
          dVar13 = (double)fVar15;
          (this->mPos).x =
               (pCamera->mEyePos).x + d_ky_thunder::_4393 * fwd.x +
               (float)((double)(fVar14 * fVar1) * dVar13);
          fVar15 = SComponent::cM_rndFX(fVar3);
          (this->mPos).y = (pCamera->mEyePos).y + fVar15;
          (this->mPos).z =
               (pCamera->mEyePos).z + d_ky_thunder::_4393 * fwd.z +
               (float)((double)(fVar14 * fVar2) * dVar13);
          fVar14 = SComponent::cM_rndF(d_ky_thunder::1_0);
          if (fVar14 < d_ky_thunder::_4394) {
            (this->mPosNeg).x = -(this->mPos).x;
            (this->mPosNeg).y = -(this->mPos).y;
            (this->mPosNeg).z = -(this->mPos).z;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x69f6,&this->mPosNeg,0,0,d_ky_thunder::1_0,
                       d_ky_thunder::1_0,d_ky_thunder::_1_0,d_ky_thunder::_1_0,0);
          }
          uVar6 = 4;
        }
      }
    }
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  return uVar6;
}

