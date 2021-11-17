#include <d_a_demo00.h>
#include <d_a_demo00.h>
#include <d_kankyo_demo.h>
#include <m_Do_ext.h>
#include <f_op_actor.h>
#include <JKernel/JKRHeap.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <mtx/mtxvec.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <JUtility/JUTNameTab.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <J3DGraphAnimator/J3DCluster.h>
#include <J3DGraphAnimator/J3DModel.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <f_op_actor_mng.h>
#include <d_demo.h>
#include <SComponent/c_bg_s.h>
#include <d_bg_s.h>
#include <d_com_inf_game.h>
#include <d_kankyo.h>
#include <J3DGraphAnimator/J3DMaterialAttach.h>
#include <JStudio/stb-data-parse.h>
#include <d_save.h>
#include <d_item.h>
#include <d_vibration.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <daDemo00_c.h>
#include <mDoExt_btpAnm.h>
#include <daDemo00_resID_c.h>
#include <daDemo00_model_c.h>


/* __thiscall daDemo00_resID_c::reset(void) */

void __thiscall daDemo00_resID_c::reset(daDemo00_resID_c *this)

{
  *(undefined4 *)this = 0xffffffff;
  *(undefined4 *)(this + 4) = 0xffffffff;
  *(undefined4 *)(this + 8) = 0xffffffff;
  *(undefined4 *)(this + 0xc) = 0xffffffff;
  *(undefined4 *)(this + 0x10) = 0xffffffff;
  *(undefined4 *)(this + 0x14) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0xffffffff;
  *(undefined4 *)(this + 0x1c) = 0xffffffff;
  *(undefined4 *)(this + 0x20) = 0xffffffff;
  *(undefined4 *)(this + 0x24) = 0xffffffff;
  return;
}


/* __thiscall daDemo00_model_c::reset(void) */

void __thiscall daDemo00_model_c::reset(daDemo00_model_c *this)

{
  daDemo00_resID_c::reset((daDemo00_resID_c *)this);
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  if (*(int *)(this + 0x48) != 0) {
    d_kankyo_demo::dKydm_demo_plight_delete();
    *(undefined4 *)(this + 0x48) = 0;
  }
  *(undefined4 *)(this + 0x44) = 0;
  return;
}


/* __thiscall daDemo00_c::~daDemo00_c(void) */

void __thiscall daDemo00_c::_daDemo00_c(daDemo00_c *this)

{
  short in_r4;
  
  if (this != (daDemo00_c *)0x0) {
    if (*(int *)(this + 0xf0) != 0) {
      if (*(mDoExt_McaMorf **)(this + 0x2f0) != (mDoExt_McaMorf *)0x0) {
        mDoExt_McaMorf::stopZelAnime(*(mDoExt_McaMorf **)(this + 0x2f0));
      }
    }
    fopAc_ac_c::_fopAc_ac_c((fopAc_ac_c *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall daDemo00_c::setBaseMtx(void) */

void __thiscall daDemo00_c::setBaseMtx(daDemo00_c *this)

{
  int iVar1;
  
  mtx::PSMTXTrans((double)*(float *)(this + 0x1f8),(double)*(float *)(this + 0x1fc),
                  (double)*(float *)(this + 0x200),&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_XYZrotM
            (&mDoMtx_stack_c::now,(int)*(short *)(this + 0x20c),(int)*(short *)(this + 0x20e),
             (int)*(short *)(this + 0x210));
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)(this + 0x2f4) + 0x24));
  iVar1 = *(int *)(this + 0x2f4);
  *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(this + 0x214);
  *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(this + 0x218);
  *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(this + 0x21c);
  (**(code **)(**(int **)(this + 0x2f4) + 0x10))();
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall daDemo00_c::setShadowSize(void) */

void __thiscall daDemo00_c::setShadowSize(daDemo00_c *this)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  float fVar6;
  cXyz local_70;
  cXyz local_64;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  cXyz local_34;
  cXyz local_28;
  
  iVar3 = *(int *)(*(int *)(this + 0x2f4) + 4);
  local_28.x = d_a_demo00::_4161;
  local_28.y = d_a_demo00::_4161;
  local_28.z = d_a_demo00::_4161;
  local_34.x = d_a_demo00::_4162;
  local_34.y = d_a_demo00::_4162;
  local_34.z = d_a_demo00::_4162;
  for (uVar2 = 0; fVar6 = d_a_demo00::_4163, uVar2 < *(ushort *)(iVar3 + 0x28); uVar2 = uVar2 + 1) {
    iVar1 = *(int *)(*(int *)(iVar3 + 0x2c) + (uint)uVar2 * 4);
    if ((*(byte *)(iVar1 + 0x1a) & 0xf) == 0) {
      mtx::PSMTXMultVec((MTX34 *)(*(int *)(*(int *)(this + 0x2f4) + 0x8c) + (uint)uVar2 * 0x30),
                        (cXyz *)(iVar1 + 0x40),&local_40);
      mtx::PSMTXMultVec((MTX34 *)(*(int *)(*(int *)(this + 0x2f4) + 0x8c) + (uint)uVar2 * 0x30),
                        (cXyz *)(iVar1 + 0x4c),&local_4c);
      if (local_40.x < local_28.x) {
        local_28.x = local_40.x;
      }
      if (local_40.y < local_28.y) {
        local_28.y = local_40.y;
      }
      if (local_40.z < local_28.z) {
        local_28.z = local_40.z;
      }
      if (local_34.x < local_4c.x) {
        local_34.x = local_4c.x;
      }
      if (local_34.y < local_4c.y) {
        local_34.y = local_4c.y;
      }
      if (local_34.z < local_4c.z) {
        local_34.z = local_4c.z;
      }
    }
  }
  *(float *)(*(int *)(this + 0x30c) + 4) = d_a_demo00::_4163 * (local_34.x + local_28.x);
  *(float *)(*(int *)(this + 0x30c) + 8) = fVar6 * (local_34.y + local_28.y);
  *(float *)(*(int *)(this + 0x30c) + 0xc) = fVar6 * (local_34.z + local_28.z);
  ::cXyz::operator__(&local_64,&local_34,&local_28);
  local_58.x = local_64.x;
  local_58.y = local_64.y;
  local_58.z = local_64.z;
  fVar6 = mtx::PSVECSquareMag(&local_58);
  dVar5 = (double)fVar6;
  if ((double)d_a_demo00::_4164 < dVar5) {
    dVar4 = 1.0 / SQRT(dVar5);
    dVar4 = d_a_demo00::_4165 * dVar4 * (d_a_demo00::_4166 - dVar5 * dVar4 * dVar4);
    dVar4 = d_a_demo00::_4165 * dVar4 * (d_a_demo00::_4166 - dVar5 * dVar4 * dVar4);
    dVar5 = (double)(float)(dVar5 * d_a_demo00::_4165 * dVar4 *
                                    (d_a_demo00::_4166 - dVar5 * dVar4 * dVar4));
  }
  *(float *)(*(int *)(this + 0x30c) + 0x10) = (float)((double)d_a_demo00::_4167 * dVar5);
  local_70.x = local_58.x;
  local_70.y = d_a_demo00::_4164;
  local_70.z = local_58.z;
  fVar6 = mtx::PSVECSquareMag(&local_70);
  dVar5 = (double)fVar6;
  if ((double)d_a_demo00::_4164 < dVar5) {
    dVar4 = 1.0 / SQRT(dVar5);
    dVar4 = d_a_demo00::_4165 * dVar4 * (d_a_demo00::_4166 - dVar5 * dVar4 * dVar4);
    dVar4 = d_a_demo00::_4165 * dVar4 * (d_a_demo00::_4166 - dVar5 * dVar4 * dVar4);
    dVar5 = (double)(float)(dVar5 * d_a_demo00::_4165 * dVar4 *
                                    (d_a_demo00::_4166 - dVar5 * dVar4 * dVar4));
  }
  *(float *)(*(int *)(this + 0x30c) + 0x14) = (float)((double)d_a_demo00::_4168 * dVar5);
  return;
}


namespace d_a_demo00 {

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall awaCheck(J3DModel *) */

undefined4 awaCheck(J3DModel *param_1)

{
  uint uVar1;
  ResTIMG *pRVar2;
  char *__s1;
  int iVar3;
  J3DSkinDeform *this;
  ResTIMG *pRVar4;
  ushort uVar5;
  JUTNameTab *this_00;
  J3DTexture *pJVar6;
  J3DModelData *pJVar7;
  
  pJVar7 = param_1->mpModelData;
  pJVar6 = (pJVar7->mMaterialTable).mpTexture;
  if ((pJVar6 != (J3DTexture *)0x0) &&
     (this_00 = (pJVar7->mMaterialTable).mpTexNameTab, this_00 != (JUTNameTab *)0x0)) {
    for (uVar5 = 0; uVar5 < (ushort)pJVar6->mCount; uVar5 = uVar5 + 1) {
      __s1 = (char *)JUTNameTab::getName(this_00,uVar5);
      iVar3 = MSL_C.PPCEABI.bare.H::strcmp(__s1,"B_dummy");
      if ((iVar3 == 0) || (iVar3 = MSL_C.PPCEABI.bare.H::strcmp(__s1,"cy_kankyo"), iVar3 == 0)) {
        this = (J3DSkinDeform *)JKernel::operator_new(0x18);
        if (this != (J3DSkinDeform *)0x0) {
          J3DSkinDeform::J3DSkinDeform(this);
        }
        if (this == (J3DSkinDeform *)0x0) {
          return 0;
        }
        iVar3 = J3DModel::setSkinDeform(param_1,this,1);
        if (iVar3 != 0) {
          return 0;
        }
        iVar3 = MSL_C.PPCEABI.bare.H::strcmp(__s1,"B_dummy");
        pRVar2 = mDoGph_gInf_c::mFrameBufferTimg;
        if (iVar3 == 0) {
          uVar1 = (uint)uVar5;
          pRVar4 = pJVar6->mpTexData + uVar1;
          pRVar4->mTexFmt = mDoGph_gInf_c::mFrameBufferTimg->mTexFmt;
          pRVar4->mTranslucency = pRVar2->mTranslucency;
          pRVar4->mWidth = pRVar2->mWidth;
          pRVar4->mHeight = pRVar2->mHeight;
          pRVar4->mWrapS = pRVar2->mWrapS;
          pRVar4->mWrapT = pRVar2->mWrapT;
          pRVar4->mbHasTlut = pRVar2->mbHasTlut;
          pRVar4->mTlutFmt = pRVar2->mTlutFmt;
          pRVar4->mTlutCount = pRVar2->mTlutCount;
          pRVar4->mTlutDataOffs = pRVar2->mTlutDataOffs;
          pRVar4->mbMipmapEnabled = pRVar2->mbMipmapEnabled;
          pRVar4->mbDoEdgeLOD = pRVar2->mbDoEdgeLOD;
          pRVar4->mbBiasClamp = pRVar2->mbBiasClamp;
          pRVar4->mMaxAniso = pRVar2->mMaxAniso;
          pRVar4->mMinFilter = pRVar2->mMinFilter;
          pRVar4->mMagFilter = pRVar2->mMagFilter;
          pRVar4->mMinLOD = pRVar2->mMinLOD;
          pRVar4->mMaxLOD = pRVar2->mMaxLOD;
          pRVar4->mMipmapCount = pRVar2->mMipmapCount;
          pRVar4->field_0x19 = pRVar2->field_0x19;
          pRVar4->mLODBias = pRVar2->mLODBias;
          pRVar4->mTexDataOffs = pRVar2->mTexDataOffs;
          pRVar4 = pJVar6->mpTexData + uVar1;
          pRVar4->mTexDataOffs = (int)pRVar2 + (pRVar4->mTexDataOffs - (int)pRVar4);
          pRVar4 = pJVar6->mpTexData + uVar1;
          pRVar4->mTlutDataOffs = (int)pRVar2 + (pRVar4->mTlutDataOffs - (int)pRVar4);
          m_Do_ext::mDoExt_modelTexturePatch(pJVar7);
        }
      }
    }
  }
  return 1;
}


/* __stdcall createHeapCallBack(fopAc_ac_c *) */

void createHeapCallBack(daDemo00_c *param_1)

{
  ::daDemo00_c::createHeap(param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall daDemo00_c::createHeap(void) */

undefined4 __thiscall daDemo00_c::createHeap(daDemo00_c *this)

{
  J3DModelData *pModelData;
  ulong uVar1;
  undefined **ppuVar2;
  J3DAnmTexPattern *pJVar3;
  int iVar4;
  J3DAnmTextureSRTKey *pAnm;
  J3DAnmTevRegKey *pJVar5;
  J3DModel *pJVar6;
  J3DAnmTransformKey *pAnmRes;
  ulong uVar7;
  mDoExt_McaMorf *this_00;
  void *pvVar8;
  cBgS_GndChk *this_01;
  cBgS_GndChk *pcVar9;
  
  if (*(int *)(this + 0x2c8) != -1) {
    pModelData = (J3DModelData *)
                 dRes_control_c::getIDRes
                           (dStage_roomControl_c::mDemoArcName,(ushort)*(int *)(this + 0x2c8),
                            d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pModelData == (J3DModelData *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_a_demo00.cpp",0xec,"modelData != 0");
      m_Do_printf::OSPanic("d_a_demo00.cpp",0xec,"Halt");
    }
    uVar1 = 0x11000002;
    if (*(int *)(this + 0x2d4) != -1) {
      ppuVar2 = (undefined **)JKernel::operator_new(0x14);
      if (ppuVar2 != (undefined **)0x0) {
        *ppuVar2 = (undefined *)&::mDoExt_baseAnm::__vt;
        ppuVar2[1] = (undefined *)0x0;
        *ppuVar2 = &::mDoExt_btpAnm::__vt;
        ppuVar2[3] = (undefined *)0x0;
      }
      *(undefined ***)(this + 0x2fc) = ppuVar2;
      if (*(int *)(this + 0x2fc) == 0) {
        return 0;
      }
      pJVar3 = (J3DAnmTexPattern *)
               dRes_control_c::getIDRes
                         (dStage_roomControl_c::mDemoArcName,(ushort)*(undefined4 *)(this + 0x2d4),
                          d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      if (pJVar3 == (J3DAnmTexPattern *)0x0) {
        return 1;
      }
      iVar4 = ::mDoExt_btpAnm::init
                        (*(mDoExt_btpAnm **)(this + 0x2fc),pModelData,pJVar3,1,-1,d_a_demo00::_4424,
                         0,-1,false,0);
      if (iVar4 == 0) {
        return 0;
      }
      uVar1 = 0x15020002;
    }
    if (*(int *)(this + 0x2d8) != -1) {
      ppuVar2 = (undefined **)JKernel::operator_new(0x14);
      if (ppuVar2 != (undefined **)0x0) {
        *ppuVar2 = (undefined *)&::mDoExt_baseAnm::__vt;
        ppuVar2[1] = (undefined *)0x0;
        *ppuVar2 = (undefined *)&::mDoExt_btkAnm::__vt;
        ppuVar2[3] = (undefined *)0x0;
      }
      *(undefined ***)(this + 0x300) = ppuVar2;
      if (*(int *)(this + 0x300) == 0) {
        return 0;
      }
      pAnm = (J3DAnmTextureSRTKey *)
             dRes_control_c::getIDRes
                       (dStage_roomControl_c::mDemoArcName,(ushort)*(undefined4 *)(this + 0x2d8),
                        d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      if (pAnm == (J3DAnmTextureSRTKey *)0x0) {
        return 1;
      }
      iVar4 = ::mDoExt_btkAnm::init
                        (*(mDoExt_btkAnm **)(this + 0x300),pModelData,pAnm,true,~Once,
                         d_a_demo00::_4424,0,-1,false,0);
      if (iVar4 == 0) {
        return 0;
      }
      if ((*(uint *)(this + 0x2d8) & 0x10000000) == 0) {
        uVar1 = uVar1 | 0x200;
      }
      else {
        uVar1 = uVar1 | 0x1200;
      }
    }
    if (*(int *)(this + 0x2dc) != -1) {
      ppuVar2 = (undefined **)JKernel::operator_new(0x18);
      if (ppuVar2 != (undefined **)0x0) {
        *ppuVar2 = (undefined *)&::mDoExt_baseAnm::__vt;
        ppuVar2[1] = (undefined *)0x0;
        *ppuVar2 = (undefined *)&::mDoExt_brkAnm::__vt;
        ppuVar2[3] = (undefined *)0x0;
        ppuVar2[4] = (undefined *)0x0;
      }
      *(undefined ***)(this + 0x304) = ppuVar2;
      if (*(int *)(this + 0x304) == 0) {
        return 0;
      }
      pJVar5 = (J3DAnmTevRegKey *)
               dRes_control_c::getIDRes
                         (dStage_roomControl_c::mDemoArcName,(ushort)*(undefined4 *)(this + 0x2dc),
                          d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      if (pJVar5 == (J3DAnmTevRegKey *)0x0) {
        return 1;
      }
      iVar4 = ::mDoExt_brkAnm::init
                        (*(mDoExt_brkAnm **)(this + 0x304),pModelData,pJVar5,true,~Once,
                         d_a_demo00::_4424,0,-1,false,0);
      if (iVar4 == 0) {
        return 0;
      }
    }
    if (*(int *)(this + 0x2cc) == -1) {
      *(undefined4 *)(this + 0x2f0) = 0;
      pJVar6 = m_Do_ext::mDoExt_J3DModel__create(pModelData,0x80000,uVar1);
      *(J3DModel **)(this + 0x2f4) = pJVar6;
      if (*(int *)(this + 0x2f4) == 0) {
        return 0;
      }
    }
    else {
      pAnmRes = (J3DAnmTransformKey *)
                dRes_control_c::getIDRes
                          (dStage_roomControl_c::mDemoArcName,(ushort)*(int *)(this + 0x2cc),
                           d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      if (pAnmRes == (J3DAnmTransformKey *)0x0) {
        uVar7 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar7,"d_a_demo00.cpp",0x148,"anm != 0");
        m_Do_printf::OSPanic("d_a_demo00.cpp",0x148,"Halt");
      }
      this_00 = (mDoExt_McaMorf *)JKernel::operator_new(0xb4);
      if (this_00 != (mDoExt_McaMorf *)0x0) {
        this_00 = mDoExt_McaMorf::mDoExt_McaMorf
                            (this_00,1,pModelData,(mDoExt_McaMorfCallBack1_c *)0x0,
                             (mDoExt_McaMorfCallBack2_c *)0x0,pAnmRes,~Once,d_a_demo00::_4424,0,-1,1
                             ,(void *)0x0,0x80000,uVar1);
      }
      *(mDoExt_McaMorf **)(this + 0x2f0) = this_00;
      if ((*(int *)(this + 0x2f0) == 0) ||
         (iVar4 = *(int *)(*(int *)(this + 0x2f0) + 0x50), iVar4 == 0)) {
        return 0;
      }
      *(int *)(this + 0x2f4) = iVar4;
      iVar4 = d_a_demo00::awaCheck(*(undefined4 *)(this + 0x2f4));
      if (iVar4 == 0) {
        return 0;
      }
    }
    if (this[0x29c] == (daDemo00_c)0x3) {
      pvVar8 = JKernel::operator_new(8);
      *(void **)(this + 0x2f8) = pvVar8;
      if (*(mDoExt_invisibleModel **)(this + 0x2f8) == (mDoExt_invisibleModel *)0x0) {
        return 0;
      }
      iVar4 = mDoExt_invisibleModel::create
                        (*(mDoExt_invisibleModel **)(this + 0x2f8),*(J3DModel **)(this + 0x2f4));
      if (iVar4 == 0) {
        return 0;
      }
    }
    else {
      *(undefined4 *)(this + 0x2f8) = 0;
    }
    if (*(int *)(this + 0x2ec) != -1) {
      pvVar8 = JKernel::operator_new(0x18);
      *(void **)(this + 0x30c) = pvVar8;
      if (*(int *)(this + 0x30c) == 0) {
        return 0;
      }
      (**(code **)(**(int **)(this + 0x2f4) + 0x10))();
      setShadowSize(this);
    }
    this_01 = (cBgS_GndChk *)JKernel::operator_new(0x58);
    if (this_01 != (cBgS_GndChk *)0x0) {
      ::cBgS_GndChk::cBgS_GndChk(this_01);
      this_01[1].parent.mpPolyPassChk = (cBgS_PolyPassChk *)&::cBgS_PolyPassChk::__vt;
      this_01[1].parent.mpPolyPassChk = (cBgS_PolyPassChk *)&::dBgS_PolyPassChk::__vt;
      *(undefined *)&this_01[1].parent.mpGrpPassChk = 0;
      *(undefined *)((int)&this_01[1].parent.mpGrpPassChk + 1) = 0;
      *(undefined *)((int)&this_01[1].parent.mpGrpPassChk + 2) = 0;
      *(undefined *)((int)&this_01[1].parent.mpGrpPassChk + 3) = 0;
      *(undefined *)&this_01[1].parent.mProcID = 0;
      *(undefined *)((int)&this_01[1].parent.mProcID + 1) = 0;
      *(undefined *)((int)&this_01[1].parent.mProcID + 2) = 0;
      *(undefined ***)&this_01[1].parent.mbExcludeSameProcID = &::cBgS_GrpPassChk::__vt;
      *(undefined ***)&this_01[1].parent.mbExcludeSameProcID = &::dBgS_GrpPassChk::__vt;
      this_01[1].parent.vtbl = (cBgS_Chk__vtbl *)&DAT_00000001;
      this_01[1].parent.mpPolyPassChk = (cBgS_PolyPassChk *)&::dBgS_Chk::__vt;
      *(undefined ***)&this_01[1].parent.mbExcludeSameProcID = &PTR_80371f68;
      (this_01->parent).vtbl = &::dBgS_GndChk::__vt;
      (this_01->mPolyInfo).vtbl = &cBgS_PolyInfo__vtbl_80371f08;
      this_01[1].parent.mpPolyPassChk = (cBgS_PolyPassChk *)&PTR_80371f14;
      *(undefined ***)&this_01[1].parent.mbExcludeSameProcID = &PTR_80371f20;
      (this_01->parent).mpPolyPassChk = (cBgS_PolyPassChk *)(this_01 + 1);
      pcVar9 = this_01 + 1;
      if (pcVar9 != (cBgS_GndChk *)0x0) {
        pcVar9 = (cBgS_GndChk *)&this_01[1].parent.mbExcludeSameProcID;
      }
      (this_01->parent).mpGrpPassChk = (cBgS_GrpPassChk *)pcVar9;
    }
    *(cBgS_GndChk **)(this + 0x314) = this_01;
    iVar4 = *(int *)(this + 0x314);
    if (iVar4 == 0) {
      return 0;
    }
    *(uint *)(iVar4 + 0x30) = *(uint *)(iVar4 + 0x30) & 0xfffffffd;
  }
  if (*(int *)(this + 0x2e8) != -1) {
    pvVar8 = JKernel::operator_new(0x28);
    *(void **)(this + 0x310) = pvVar8;
    if (*(int *)(this + 0x310) == 0) {
      return 0;
    }
    d_kankyo_demo::dKydm_demo_plight_entry
              (*(int *)(this + 0x310),this + 0x1f8,*(int *)(this + 0x2e8),
               (&DAT_8038b019)[(*(int *)(this + 0x2e8) + -1) * 8]);
  }
  return 1;
}


/* __thiscall daDemo00_c::actStandby(dDemo_actor_c *) */

undefined4 __thiscall daDemo00_c::actStandby(daDemo00_c *this,dDemo_actor_c *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((*(int *)(this + 0x2a0) == -1) && (*(int *)(this + 0x2c0) == -1)) {
    return 1;
  }
  *(int *)(this + 0x2c8) = *(int *)(this + 0x2a0);
  *(undefined4 *)(this + 0x2cc) = *(undefined4 *)(this + 0x2a4);
  *(undefined4 *)(this + 0x2d0) = *(undefined4 *)(this + 0x2a8);
  *(undefined4 *)(this + 0x2d4) = *(undefined4 *)(this + 0x2ac);
  *(undefined4 *)(this + 0x2d8) = *(undefined4 *)(this + 0x2b0);
  *(undefined4 *)(this + 0x2dc) = *(undefined4 *)(this + 0x2b4);
  *(undefined4 *)(this + 0x2e0) = *(undefined4 *)(this + 0x2b8);
  *(undefined4 *)(this + 0x2e4) = *(undefined4 *)(this + 700);
  *(undefined4 *)(this + 0x2e8) = *(undefined4 *)(this + 0x2c0);
  *(undefined4 *)(this + 0x2ec) = *(undefined4 *)(this + 0x2c4);
  uVar2 = f_op_actor_mng::fopAcM_entrySolidHeap
                    ((fopAc_ac_c *)this,d_a_demo00::createHeapCallBack,0x4000);
  if ((uVar2 & 0xff) != 0) {
    if (*(int *)(this + 0x2f4) != 0) {
      setBaseMtx(this);
      *(int *)(this + 0x22c) = *(int *)(this + 0x2f4) + 0x24;
      param_1->mpModel = *(J3DModel **)(this + 0x2f4);
      if (*(int *)(this + 0x2f0) != 0) {
        param_1->mAnimationFrameMax =
             (float)((double)CONCAT44(0x43300000,
                                      (int)*(short *)(*(int *)(this + 0x2f0) + 0x60) ^ 0x80000000) -
                    d_a_demo00::_4523);
      }
    }
    uVar1 = DAT_8038b040;
    *(undefined4 *)(this + 0x290) = d_a_demo00::_4492;
    *(undefined4 *)(this + 0x294) = uVar1;
    *(undefined **)(this + 0x298) = PTR_actPerformance_8038b044;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800e6e0c) */
/* __thiscall daDemo00_c::actPerformance(dDemo_actor_c *) */

undefined4 __thiscall daDemo00_c::actPerformance(daDemo00_c *this,dDemo_actor_c *param_1)

{
  float fVar1;
  bool bVar2;
  undefined4 uVar3;
  J3DAnmTransform *pAnimRes;
  J3DAnmTexPattern *pJVar4;
  J3DAnmTextureSRTKey *pAnm;
  J3DAnmTevRegKey *pJVar5;
  int iVar6;
  ulong uVar7;
  sbyte sVar9;
  mDoExt_baseAnm *pmVar8;
  bool bVar10;
  J3DFrameCtrl__LoopMode JVar11;
  undefined4 uVar12;
  double dVar13;
  undefined8 in_f31;
  double dVar14;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40;
  undefined4 local_3c;
  double local_38;
  double local_30;
  undefined auStack8 [8];
  
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((*(int *)(this + 0x2c8) == *(int *)(this + 0x2a0)) &&
     (*(int *)(this + 0x2e8) == *(int *)(this + 0x2c0))) {
    if (*(int *)(this + 0x2f4) == 0) {
      if (*(int *)(this + 0x310) != 0) {
        d_demo::dDemo_setDemoData((fopAc_ac_c *)this,2,(mDoExt_McaMorf *)0x0,(char *)0x0,0,0,0,'\0')
        ;
        d_kankyo_demo::dKydm_demo_plight_execute(*(undefined4 *)(this + 0x310),this + 0x1f8);
      }
    }
    else {
      if ((*(int *)(this + 0x2f0) != 0) && (*(int *)(this + 0x2cc) != *(int *)(this + 0x2a4))) {
        pAnimRes = (J3DAnmTransform *)
                   dRes_control_c::getIDRes
                             (dStage_roomControl_c::mDemoArcName,(ushort)*(int *)(this + 0x2a4),
                              d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
        if (pAnimRes == (J3DAnmTransform *)0x0) goto LAB_800e6e0c;
        fVar1 = d_a_demo00::_4164;
        if ((param_1->mFlags & 0x40U) != 0) {
          fVar1 = param_1->mAnimationTransition;
        }
        mDoExt_McaMorf::setAnm
                  (*(mDoExt_McaMorf **)(this + 0x2f0),pAnimRes,-1,fVar1,d_a_demo00::_4424,
                   d_a_demo00::_4164,d_a_demo00::_4750,(void *)0x0);
        *(undefined4 *)(this + 0x2cc) = *(undefined4 *)(this + 0x2a4);
      }
      if (*(int *)(this + 0x2d4) != *(int *)(this + 0x2ac)) {
        pJVar4 = (J3DAnmTexPattern *)
                 dRes_control_c::getIDRes
                           (dStage_roomControl_c::mDemoArcName,(ushort)*(int *)(this + 0x2ac),
                            d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
        if (pJVar4 == (J3DAnmTexPattern *)0x0) goto LAB_800e6e0c;
        ::mDoExt_btpAnm::init
                  (*(mDoExt_btpAnm **)(this + 0x2fc),*(J3DModelData **)(*(int *)(this + 0x2f4) + 4),
                   pJVar4,1,-1,d_a_demo00::_4424,0,-1,true,0);
        *(undefined4 *)(this + 0x2d4) = *(undefined4 *)(this + 0x2ac);
      }
      if (*(int *)(this + 0x2d8) != *(int *)(this + 0x2b0)) {
        pAnm = (J3DAnmTextureSRTKey *)
               dRes_control_c::getIDRes
                         (dStage_roomControl_c::mDemoArcName,(ushort)*(int *)(this + 0x2b0),
                          d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
        if (pAnm == (J3DAnmTextureSRTKey *)0x0) goto LAB_800e6e0c;
        fVar1 = d_a_demo00::_4164;
        if ((*(uint *)(this + 0x2d8) & 0x10000000) != 0) {
          fVar1 = *(float *)(*(int *)(*(int *)(this + 0x300) + 4) + 0x10);
        }
        JVar11 = ~Once;
        if ((*(uint *)(this + 0x2d8) & 0x10000000) != 0) {
          JVar11 = Repeat;
        }
        local_38 = (double)(longlong)(int)fVar1;
        ::mDoExt_btkAnm::init
                  (*(mDoExt_btkAnm **)(this + 0x300),*(J3DModelData **)(*(int *)(this + 0x2f4) + 4),
                   pAnm,true,JVar11,d_a_demo00::_4424,(short)(int)fVar1,-1,true,0);
        *(undefined4 *)(this + 0x2d8) = *(undefined4 *)(this + 0x2b0);
      }
      if (*(int *)(this + 0x2dc) != *(int *)(this + 0x2b4)) {
        pJVar5 = (J3DAnmTevRegKey *)
                 dRes_control_c::getIDRes
                           (dStage_roomControl_c::mDemoArcName,(ushort)*(int *)(this + 0x2b4),
                            d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
        if (pJVar5 == (J3DAnmTevRegKey *)0x0) goto LAB_800e6e0c;
        fVar1 = d_a_demo00::_4164;
        if ((*(uint *)(this + 0x2dc) & 0x10000000) != 0) {
          fVar1 = *(float *)(*(int *)(*(int *)(this + 0x304) + 4) + 0x10);
        }
        JVar11 = ~Once;
        if ((*(uint *)(this + 0x2dc) & 0x10000000) != 0) {
          JVar11 = Repeat;
        }
        local_38 = (double)(longlong)(int)fVar1;
        ::mDoExt_brkAnm::init
                  (*(mDoExt_brkAnm **)(this + 0x304),*(J3DModelData **)(*(int *)(this + 0x2f4) + 4),
                   pJVar5,true,JVar11,d_a_demo00::_4424,(short)(int)fVar1,-1,true,0);
        *(undefined4 *)(this + 0x2dc) = *(undefined4 *)(this + 0x2b4);
      }
      d_demo::dDemo_setDemoData
                ((fopAc_ac_c *)this,0x2a,(mDoExt_McaMorf *)0x0,(char *)0x0,0,0,0,'\0');
      iVar6 = *(int *)(this + 0x314);
      if (iVar6 != 0) {
        local_3c = *(undefined4 *)(this + 0x200);
        local_40 = d_a_demo00::_4751 + *(float *)(this + 0x1fc);
        local_44 = *(undefined4 *)(this + 0x1f8);
        *(undefined4 *)(iVar6 + 0x24) = local_44;
        *(float *)(iVar6 + 0x28) = local_40;
        *(undefined4 *)(iVar6 + 0x2c) = local_3c;
        dVar13 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                           *(cBgS_GndChk **)(this + 0x314));
        *(float *)(*(int *)(this + 0x314) + 0x54) = (float)dVar13;
        this[0x29e] = (daDemo00_c)0x1;
      }
      setBaseMtx(this);
      if ((param_1->mFlags & 0x40U) == 0) {
        if (*(mDoExt_McaMorf **)(this + 0x2f0) == (mDoExt_McaMorf *)0x0) {
          if (*(mDoExt_baseAnm **)(this + 0x2fc) == (mDoExt_baseAnm *)0x0) {
            if (*(mDoExt_baseAnm **)(this + 0x300) == (mDoExt_baseAnm *)0x0) {
              if (*(mDoExt_baseAnm **)(this + 0x304) != (mDoExt_baseAnm *)0x0) {
                ::mDoExt_baseAnm::play(*(mDoExt_baseAnm **)(this + 0x304));
              }
            }
            else {
              ::mDoExt_baseAnm::play(*(mDoExt_baseAnm **)(this + 0x300));
            }
          }
          else {
            ::mDoExt_baseAnm::play(*(mDoExt_baseAnm **)(this + 0x2fc));
          }
        }
        else {
          mDoExt_McaMorf::play(*(mDoExt_McaMorf **)(this + 0x2f0),(cXyz *)(this + 0x1f8),0,0);
        }
      }
      else {
        fVar1 = param_1->mAnimationFrame;
        dVar13 = (double)fVar1;
        if (dVar13 <= (double)d_a_demo00::_4424) {
          if (*(int *)(this + 0x2f0) != 0) {
            local_30 = (double)(longlong)(int)fVar1;
            local_38 = (double)CONCAT44(0x43300000,(int)(short)(int)fVar1 ^ 0x80000000);
            *(float *)(*(int *)(this + 0x2f0) + 0x68) = (float)(local_38 - d_a_demo00::_4523);
          }
          if (*(int *)(this + 0x2fc) != 0) {
            *(float *)(*(int *)(*(int *)(this + 0x2fc) + 4) + 0x10) = fVar1;
          }
          pmVar8 = *(mDoExt_baseAnm **)(this + 0x300);
          if (pmVar8 != (mDoExt_baseAnm *)0x0) {
            if ((*(uint *)(this + 0x2d8) & 0x10000000) == 0) {
              pmVar8->mpFrameCtrl->mCurrentTime = fVar1;
            }
            else {
              ::mDoExt_baseAnm::play(pmVar8);
            }
          }
          pmVar8 = *(mDoExt_baseAnm **)(this + 0x304);
          if (pmVar8 != (mDoExt_baseAnm *)0x0) {
            if ((*(uint *)(this + 0x2dc) & 0x10000000) == 0) {
              pmVar8->mpFrameCtrl->mCurrentTime = (float)dVar13;
            }
            else {
              ::mDoExt_baseAnm::play(pmVar8);
            }
          }
        }
        else {
          dVar13 = dVar13 - (double)d_a_demo00::_4424;
          dVar14 = (double)(float)dVar13;
          if (*(int *)(this + 0x2f0) != 0) {
            iVar6 = (int)dVar13;
            local_38 = (double)(longlong)iVar6;
            local_30 = (double)CONCAT44(0x43300000,(int)(short)iVar6 ^ 0x80000000);
            *(float *)(*(int *)(this + 0x2f0) + 0x68) = (float)(local_30 - d_a_demo00::_4523);
            iVar6 = (int)(char)dStage_roomControl_c::mStayNo;
            bVar10 = false;
            bVar2 = false;
            if ((*(int *)(this + 0x314) != 0) && (this[0x29e] != (daDemo00_c)0x0)) {
              bVar2 = true;
            }
            if ((bVar2) &&
               (ABS(*(float *)(*(int *)(this + 0x314) + 0x54) - *(float *)(this + 0x1fc)) <
                d_a_demo00::_4752)) {
              bVar10 = true;
            }
            if (bVar10) {
              uVar7 = dBgS::GetMtrlSndId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                         (cBgS_PolyInfo *)(*(int *)(this + 0x314) + 0x14));
            }
            else {
              uVar7 = 0;
            }
            sVar9 = d_com_inf_game::dComIfGp_getReverb(iVar6);
            mDoExt_McaMorf::play
                      (*(mDoExt_McaMorf **)(this + 0x2f0),(cXyz *)(this + 0x1f8),uVar7,sVar9);
          }
          if (*(int *)(this + 0x2fc) != 0) {
            *(float *)(*(int *)(*(int *)(this + 0x2fc) + 4) + 0x10) = (float)dVar14;
            ::mDoExt_baseAnm::play(*(mDoExt_baseAnm **)(this + 0x2fc));
          }
          if (*(int *)(this + 0x300) != 0) {
            if ((*(uint *)(this + 0x2d8) & 0x10000000) == 0) {
              *(float *)(*(int *)(*(int *)(this + 0x300) + 4) + 0x10) = (float)dVar14;
            }
            ::mDoExt_baseAnm::play(*(mDoExt_baseAnm **)(this + 0x300));
          }
          if (*(int *)(this + 0x304) != 0) {
            if ((*(uint *)(this + 0x2dc) & 0x10000000) == 0) {
              *(float *)(*(int *)(*(int *)(this + 0x304) + 4) + 0x10) = (float)dVar14;
            }
            ::mDoExt_baseAnm::play(*(mDoExt_baseAnm **)(this + 0x304));
          }
        }
      }
      if ((param_1->mFlags & 4U) != 0) {
        *(float *)(this + 0x214) = (param_1->mScaling).x;
        *(float *)(this + 0x218) = (param_1->mScaling).y;
        *(float *)(this + 0x21c) = (param_1->mScaling).z;
      }
      if (*(int *)(this + 0x310) != 0) {
        local_50 = *(undefined4 *)(this + 0x1f8);
        local_4c = *(undefined4 *)(this + 0x1fc);
        local_48 = *(undefined4 *)(this + 0x200);
        if ((&d_a_demo00::l_lightData)[(*(int *)(this + 0x2e8) + -1) * 8] == '\x01') {
          iVar6 = JUTNameTab::getIndex
                            (*(JUTNameTab **)(*(int *)(*(int *)(this + 0x2f4) + 4) + 0x54),
                             (&PTR__stringBase0_8038b01c)[(*(int *)(this + 0x2e8) + -1) * 2]);
          iVar6 = *(int *)(*(int *)(this + 0x2f4) + 0x8c) + iVar6 * 0x30;
          local_50 = *(undefined4 *)(iVar6 + 0xc);
          local_4c = *(undefined4 *)(iVar6 + 0x1c);
          local_48 = *(undefined4 *)(iVar6 + 0x2c);
        }
        d_kankyo_demo::dKydm_demo_plight_execute(*(undefined4 *)(this + 0x310),&local_50);
      }
    }
  }
  else {
    daDemo00_model_c::reset((daDemo00_model_c *)(this + 0x2c8));
    uVar3 = DAT_8038b04c;
    *(undefined4 *)(this + 0x290) = d_a_demo00::_4530;
    *(undefined4 *)(this + 0x294) = uVar3;
    *(undefined **)(this + 0x298) = PTR_actLeaving_8038b050;
  }
LAB_800e6e0c:
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  return 1;
}


/* __thiscall daDemo00_c::actLeaving(dDemo_actor_c *) */

undefined4 __thiscall daDemo00_c::actLeaving(daDemo00_c *this,dDemo_actor_c *param_1)

{
  undefined4 uVar1;
  dDemo_actor_c *extraout_r4;
  
  if (*(mDoExt_McaMorf **)(this + 0x2f0) != (mDoExt_McaMorf *)0x0) {
    mDoExt_McaMorf::stopZelAnime(*(mDoExt_McaMorf **)(this + 0x2f0));
    param_1 = extraout_r4;
  }
  f_op_actor_mng::fopAcM_DeleteHeap(this,param_1);
  uVar1 = DAT_8038b058;
  *(undefined4 *)(this + 0x290) = d_a_demo00::_4760;
  *(undefined4 *)(this + 0x294) = uVar1;
  *(undefined **)(this + 0x298) = PTR_actStandby_8038b05c;
  return 1;
}


namespace d_a_demo00 {

/* __stdcall daDemo00_Draw(daDemo00_c *) */

void daDemo00_Draw(daDemo00_c *param_1)

{
  ::daDemo00_c::draw(param_1);
  return;
}

}

/* __thiscall daDemo00_c::draw(void) */

undefined4 __thiscall daDemo00_c::draw(daDemo00_c *this)

{
  mDoExt_btpAnm *this_00;
  mDoExt_btkAnm *this_01;
  mDoExt_brkAnm *this_02;
  mDoExt_invisibleModel *this_03;
  int iVar1;
  ulong *puVar2;
  cXyz local_38;
  cXyz local_2c;
  cXyz local_20;
  longlong local_10;
  
  if (*(int *)(this + 0x2f4) != 0) {
    dScnKy_env_light_c::settingTevStruct
              (&d_kankyo::g_env_light,Actor,(cXyz *)(this + 0x1f8),(dKy_tevstr_c *)(this + 0x10c));
    dScnKy_env_light_c::setLightTevColorType
              (&d_kankyo::g_env_light,*(J3DModel **)(this + 0x2f4),(dKy_tevstr_c *)(this + 0x10c));
    this_00 = *(mDoExt_btpAnm **)(this + 0x2fc);
    if (this_00 != (mDoExt_btpAnm *)0x0) {
      iVar1 = (int)((this_00->parent).mpFrameCtrl)->mCurrentTime;
      local_10 = (longlong)iVar1;
      ::mDoExt_btpAnm::entry(this_00,*(J3DModelData **)(*(int *)(this + 0x2f4) + 4),(short)iVar1);
    }
    this_01 = *(mDoExt_btkAnm **)(this + 0x300);
    if (this_01 != (mDoExt_btkAnm *)0x0) {
      ::mDoExt_btkAnm::entry
                (this_01,*(J3DModelData **)(*(int *)(this + 0x2f4) + 4),
                 ((this_01->parent).mpFrameCtrl)->mCurrentTime);
    }
    this_02 = *(mDoExt_brkAnm **)(this + 0x304);
    if (this_02 != (mDoExt_brkAnm *)0x0) {
      ::mDoExt_brkAnm::entry
                (this_02,*(J3DModelData **)(*(int *)(this + 0x2f4) + 4),
                 ((this_02->parent).mpFrameCtrl)->mCurrentTime);
    }
    this_03 = *(mDoExt_invisibleModel **)(this + 0x2f8);
    if (this_03 == (mDoExt_invisibleModel *)0x0) {
      if ((*(int *)(*(int *)(this + 0x2f4) + 0xc0) != 0) &&
         (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"GTower")
         , iVar1 == 0)) {
        J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
             d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x30;
        J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
             d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x34;
      }
      if (this[0x29c] == (daDemo00_c)0x2) {
        J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
             d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffOpa;
        J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
             d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffXlu;
      }
      else {
        if (this[0x29c] == (daDemo00_c)0x8) {
          J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
               d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0xc;
          J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
               d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x10;
        }
      }
      if (*(mDoExt_McaMorf **)(this + 0x2f0) == (mDoExt_McaMorf *)0x0) {
        m_Do_ext::mDoExt_modelUpdateDL(*(J3DModel **)(this + 0x2f4));
      }
      else {
        mDoExt_McaMorf::updateDL(*(mDoExt_McaMorf **)(this + 0x2f0));
      }
      if (((*(int *)(*(int *)(this + 0x2f4) + 0xc0) != 0) || (this[0x29c] == (daDemo00_c)0x2)) ||
         (this[0x29c] == (daDemo00_c)0x8)) {
        J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
             d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
        J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
             d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
      }
    }
    else {
      if (*(mDoExt_McaMorf **)(this + 0x2f0) == (mDoExt_McaMorf *)0x0) {
        mDoExt_invisibleModel::updateDL(this_03,*(J3DModel **)(this + 0x2f4));
      }
      else {
        mDoExt_invisibleModel::updateDL(this_03,*(mDoExt_McaMorf **)(this + 0x2f0));
      }
    }
    iVar1 = *(int *)(this + 0x30c);
    if ((iVar1 != 0) && (this[0x29e] != (daDemo00_c)0x0)) {
      if ((*(int *)(this + 0x2ec) == 0) || (*(int *)(this + 0x2ec) == 1)) {
        ::cXyz::operator__(&local_38,(cXyz *)(this + 0x1f8),(cXyz *)(iVar1 + 4));
        local_20.x = local_38.x;
        local_20.y = local_38.y;
        local_20.z = local_38.z;
        puVar2 = *(ulong **)(this + 0x30c);
        iVar1 = d_com_inf_game::dComIfGd_setShadow
                          (*puVar2,1 - (*(int *)(this + 0x2ec) == 0),*(J3DModel **)(this + 0x2f4),
                           &local_20,(float)puVar2[4],(float)puVar2[5],*(float *)(this + 0x1fc),
                           *(float *)(*(int *)(this + 0x314) + 0x54),
                           (cBgS_PolyInfo *)(*(int *)(this + 0x314) + 0x14),
                           (dKy_tevstr_c *)(this + 0x10c),0,d_a_demo00::_4424,
                           &dDlst_shadowControl_c::mSimpleTexObj);
        **(int **)(this + 0x30c) = iVar1;
      }
      else {
        local_2c.z = *(float *)(this + 0x200);
        local_2c.y = *(float *)(*(int *)(this + 0x314) + 0x54);
        local_2c.x = *(float *)(this + 0x1f8);
        d_com_inf_game::dComIfGd_setSimpleShadow2
                  (&local_2c,local_2c.y,*(float *)(iVar1 + 0x14),
                   (cBgS_PolyInfo *)(*(int *)(this + 0x314) + 0x14),0,d_a_demo00::_4424,
                   &dDlst_shadowControl_c::mSimpleTexObj);
      }
    }
    if (*(int *)(this + 0x2fc) != 0) {
      J3DMaterialTable::removeTexNoAnimator
                ((J3DMaterialTable *)(*(int *)(*(int *)(this + 0x2f4) + 4) + 0x58),
                 *(J3DAnmTexPattern **)(*(int *)(this + 0x2fc) + 8));
    }
    if (*(int *)(this + 0x300) != 0) {
      J3DMaterialTable::removeTexMtxAnimator
                ((J3DMaterialTable *)(*(int *)(*(int *)(this + 0x2f4) + 4) + 0x58),
                 *(J3DAnmTextureSRTKey **)(*(int *)(this + 0x300) + 8));
    }
    if (*(int *)(this + 0x304) != 0) {
      J3DMaterialTable::removeTevRegAnimator
                ((J3DMaterialTable *)(*(int *)(*(int *)(this + 0x2f4) + 4) + 0x58),
                 *(J3DAnmTevRegKey **)(*(int *)(this + 0x304) + 8));
    }
  }
  return 1;
}


namespace d_a_demo00 {

/* __stdcall daDemo00_Execute(daDemo00_c *) */

void daDemo00_Execute(daDemo00_c *param_1)

{
  ::daDemo00_c::execute(param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daDemo00_c::execute(void) */

undefined4 __thiscall daDemo00_c::execute(daDemo00_c *this)

{
  daDemo00_c dVar1;
  byte bVar2;
  bool bVar3;
  JUTFader *pJVar4;
  uint uVar5;
  dDemo_actor_c *pdVar6;
  ulong uVar7;
  int *piVar8;
  _GXColor *p_Var9;
  uint uVar10;
  daDemo00_c dVar11;
  void *local_e4;
  _GXColor local_e0;
  daDemo00_c *local_dc;
  void *local_d8;
  void *local_d4;
  void *local_d0;
  void *local_cc;
  void *local_c8;
  uint *local_c4;
  uint *local_c0;
  _GXColor local_bc;
  daDemo00_c *local_b8;
  daDemo00_c *local_b4;
  uint *local_b0;
  daDemo00_c *local_ac;
  uint *local_a8;
  daDemo00_c *local_a4;
  cXyz local_a0;
  cXyz local_94;
  TData local_88 [8];
  int local_80;
  uint *local_7c;
  int local_78;
  TData local_74 [8];
  int local_6c;
  daDemo00_c *local_68;
  int local_64;
  TData local_60 [12];
  byte *local_54;
  int local_50;
  TData local_4c [12];
  char *local_40;
  int local_3c;
  TData local_38 [12];
  byte *local_2c;
  int local_28;
  TData local_24 [12];
  byte *local_18;
  int local_14;
  
  this[0x29e] = (daDemo00_c)0x0;
  pdVar6 = dDemo_object_c::getActor
                     (&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mDemoObj,
                      (byte)this[0x1c0]);
  if (pdVar6 != (dDemo_actor_c *)0x0) {
    if ((pdVar6->mFlags & 0x10U) != 0) {
      *(ulong *)(this + 0x2a0) = pdVar6->mShape;
    }
    if ((pdVar6->mFlags & 0x20U) != 0) {
      *(ulong *)(this + 0x2a4) = pdVar6->mNextBckId;
    }
    if ((pdVar6->mFlags & 1U) != 0) {
      dVar11 = this[0x29c];
      this[0x29c] = SUB41(pdVar6->field_0x4c,0);
      dVar1 = this[0x29c];
      if (dVar1 == (daDemo00_c)0x4) {
        local_c8 = pdVar6->field_0x50;
        JStudio::stb::data::TParse_TParagraph_data::getData
                  ((TParse_TParagraph_data *)&local_c8,local_24);
        if (local_24[0] != (TData)0x0) {
          bVar3 = false;
          if (((local_18 != (byte *)0x0) && (local_24[0] == (TData)0x31)) && (local_14 != 0)) {
            bVar3 = true;
          }
          if (bVar3) {
            bVar2 = *local_18;
            if (0x31 < bVar2) {
              uVar7 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert
                        (uVar7,"d_a_demo00.cpp",0x340,"argID < (sizeof(l_eventBit)/sizeof(u16))");
              m_Do_printf::OSPanic("d_a_demo00.cpp",0x340,"Halt");
            }
            if (*(ushort *)(l_eventBit_localstatic3_execute + (uint)bVar2 * 2) != 0xffff) {
              dSv_event_c::onEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,
                         *(ushort *)(l_eventBit_localstatic3_execute + (uint)bVar2 * 2));
            }
          }
        }
      }
      else {
        if (dVar1 == (daDemo00_c)0x5) {
          local_cc = pdVar6->field_0x50;
          JStudio::stb::data::TParse_TParagraph_data::getData
                    ((TParse_TParagraph_data *)&local_cc,local_38);
          if (local_38[0] != (TData)0x0) {
            bVar3 = false;
            if (((local_2c != (byte *)0x0) && (local_38[0] == (TData)0x31)) && (local_28 != 0)) {
              bVar3 = true;
            }
            if (bVar3) {
              bVar2 = *local_2c;
              if (9 < bVar2) {
                uVar7 = JUTAssertion::getSDevice();
                JUTAssertion::showAssert
                          (uVar7,"d_a_demo00.cpp",0x35a,"argID < (sizeof(l_itemNo)/sizeof(u8))");
                m_Do_printf::OSPanic("d_a_demo00.cpp",0x35a,"Halt");
              }
              if (l_itemNo_localstatic4_execute[bVar2] != (code)0xff) {
                d_item::execItemGet((dItem_data__ItemNo)l_itemNo_localstatic4_execute[bVar2]);
              }
            }
          }
        }
        else {
          if (dVar1 == (daDemo00_c)0x6) {
            local_d0 = pdVar6->field_0x50;
            JStudio::stb::data::TParse_TParagraph_data::getData
                      ((TParse_TParagraph_data *)&local_d0,local_4c);
            if (local_4c[0] != (TData)0x0) {
              bVar3 = false;
              if (((local_40 != (char *)0x0) && (local_4c[0] == (TData)0x21)) && (local_3c != 0)) {
                bVar3 = true;
              }
              if (bVar3) {
                mDoGph_gInf_c::mMonotoneRateSpeed = (short)*local_40;
              }
            }
          }
          else {
            if (dVar1 == (daDemo00_c)0x7) {
              local_d4 = pdVar6->field_0x50;
              JStudio::stb::data::TParse_TParagraph_data::getData
                        ((TParse_TParagraph_data *)&local_d4,local_60);
              if (local_60[0] != (TData)0x0) {
                bVar3 = false;
                if (((local_54 != (byte *)0x0) && (local_60[0] == (TData)0x31)) && (local_50 != 0))
                {
                  bVar3 = true;
                }
                if (bVar3) {
                  uVar10 = (uint)*local_54;
                  if (uVar10 < 100) {
                    local_94.x = d_a_demo00::_4164;
                    local_94.y = d_a_demo00::_4424;
                    local_94.z = d_a_demo00::_4164;
                    dVibration_c::StartShock
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,uVar10,1,
                               &local_94);
                  }
                  else {
                    if (uVar10 == 0xff) {
                      dVibration_c::StopQuake
                                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,1);
                    }
                    else {
                      local_a0.x = d_a_demo00::_4164;
                      local_a0.y = d_a_demo00::_4424;
                      local_a0.z = d_a_demo00::_4164;
                      dVibration_c::StartQuake
                                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,uVar10 - 100,1
                                 ,&local_a0);
                    }
                  }
                }
              }
            }
            else {
              if ((dVar1 == (daDemo00_c)0x9) || (dVar1 == (daDemo00_c)0xa)) {
                local_d8 = pdVar6->field_0x50;
                JStudio::stb::data::TParse_TParagraph_data::getData
                          ((TParse_TParagraph_data *)&local_d8,local_74);
                if (local_74[0] != (TData)0x0) {
                  bVar3 = false;
                  if (((local_68 != (daDemo00_c *)0x0) && (local_74[0] == (TData)0x21)) &&
                     (local_64 != 0)) {
                    bVar3 = true;
                  }
                  if (bVar3) {
                    local_a4 = local_68;
                    dVar1 = *local_68;
                    if ((this[0x29c] != dVar11) || (dVar1 != this[0x29d])) {
                      this[0x29d] = dVar1;
                      dVar11 = (daDemo00_c)0x0;
                      local_dc = local_68 + local_6c;
                      local_b8 = local_68 + 1;
                      uVar10 = countLeadingZeros((int)local_dc - (int)local_b8);
                      if ((uVar10 >> 5 & 0xff) == 0) {
                        dVar11 = *local_b8;
                      }
                      local_b4 = local_dc;
                      local_ac = local_dc;
                      local_a4 = local_b8;
                      if (dVar1 == (daDemo00_c)0x0) {
                        piVar8 = (int *)JFWDisplay::sManager->mpFader;
                        if (piVar8 != (int *)0x0) {
                          (**(code **)(*piVar8 + 0x10))(piVar8,(int)(char)dVar11);
                        }
                      }
                      else {
                        piVar8 = (int *)JFWDisplay::sManager->mpFader;
                        if (piVar8 != (int *)0x0) {
                          (**(code **)(*piVar8 + 0xc))(piVar8,(int)(char)dVar11);
                        }
                      }
                      pJVar4 = mDoGph_gInf_c::mFader;
                      p_Var9 = &d_com_inf_game::g_saftyWhiteColor;
                      if (this[0x29c] == (daDemo00_c)0x9) {
                        p_Var9 = &d_com_inf_game::g_blackColor;
                      }
                      local_e0 = *p_Var9;
                      local_e0.r = (u8)((uint)local_e0 >> 0x18);
                      mDoGph_gInf_c::mFader[0xc] = (JUTFader)local_e0.r;
                      local_e0.g = (u8)((uint)local_e0 >> 0x10);
                      pJVar4[0xd] = (JUTFader)local_e0.g;
                      local_e0.b = (u8)((uint)local_e0 >> 8);
                      pJVar4[0xe] = (JUTFader)local_e0.b;
                      pJVar4[0xf] = (JUTFader)local_e0.a;
                      local_bc = local_e0;
                    }
                  }
                }
              }
              else {
                local_e4 = pdVar6->field_0x50;
                JStudio::stb::data::TParse_TParagraph_data::getData
                          ((TParse_TParagraph_data *)&local_e4,local_88);
                if (local_88[0] != (TData)0x0) {
                  bVar3 = false;
                  if (((local_7c != (uint *)0x0) && (local_88[0] == (TData)0x33)) && (local_78 != 0)
                     ) {
                    bVar3 = true;
                  }
                  if (bVar3) {
                    uVar10 = 0xffffffff;
                    local_a8 = local_7c;
                    while( true ) {
                      local_c0 = local_7c + local_80;
                      local_c4 = local_a8;
                      uVar5 = countLeadingZeros((int)local_c0 - (int)local_a8);
                      local_b0 = local_c0;
                      if ((uVar5 >> 5 & 0xff) != 0) break;
                      if ((int)uVar10 < 0) {
                        uVar10 = *local_a8;
                      }
                      else {
                        if (uVar10 == 0) {
                          *(uint *)(this + 0x2ac) = *local_a8;
                        }
                        else {
                          if (uVar10 == 1) {
                            *(uint *)(this + 0x2b0) = *local_a8;
                          }
                          else {
                            if (uVar10 == 2) {
                              *(uint *)(this + 0x2c0) = *local_a8;
                            }
                            else {
                              if (uVar10 == 3) {
                                *(uint *)(this + 700) = *local_a8;
                              }
                              else {
                                if (uVar10 == 4) {
                                  *(uint *)(this + 0x2b4) = *local_a8;
                                }
                                else {
                                  if (uVar10 == 5) {
                                    *(uint *)(this + 0x2c4) = *local_a8;
                                  }
                                  else {
                                    if (uVar10 == 6) {
                                      *(uint *)(this + 0x2b0) = *local_a8 | 0x10000000;
                                    }
                                    else {
                                      if (uVar10 == 7) {
                                        *(uint *)(this + 0x2b4) = *local_a8 | 0x10000000;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                        uVar10 = 0xffffffff;
                      }
                      local_a8 = local_a8 + 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 0x290),this,pdVar6);
    return 1;
  }
  f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  return 1;
}


namespace d_a_demo00 {

/* __stdcall daDemo00_IsDelete(daDemo00_c *) */

undefined4 daDemo00_IsDelete(void)

{
  return 1;
}


/* __stdcall daDemo00_Delete(daDemo00_c *) */

undefined4 daDemo00_Delete(daDemo00_c *param_1)

{
  ::daDemo00_c::_daDemo00_c(param_1);
  return 1;
}


/* __stdcall daDemo00_Create(fopAc_ac_c *) */

undefined4 daDemo00_Create(fopAc_ac_c *param_1)

{
  uint uVar1;
  
  if ((param_1->mCondition & Constructed) == 0) {
    if (param_1 != (fopAc_ac_c *)0x0) {
      fopAc_ac_c::fopAc_ac_c(param_1);
    }
    param_1->mCondition = param_1->mCondition | Constructed;
  }
  d_kankyo::dKy_tevstr_init(&param_1->mTevStr,dStage_roomControl_c::mStayNo,0xff);
  uVar1 = DAT_8038b034;
  param_1[1].parent.parent.mBsType = _4477;
  param_1[1].parent.parent.mBsPcId = uVar1;
  *(undefined **)&param_1[1].parent.parent.mProcName = PTR_actStandby_8038b038;
  ::daDemo00_resID_c::reset((daDemo00_resID_c *)&param_1[1].parent.parent.mpProf);
  param_1[1].parent.parent.field_0xd = 0xff;
  return 4;
}

}

/* __thiscall mDoExt_btpAnm::~mDoExt_btpAnm(void) */

void __thiscall mDoExt_btpAnm::_mDoExt_btpAnm(mDoExt_btpAnm *this)

{
  short in_r4;
  
  if (this != (mDoExt_btpAnm *)0x0) {
    (this->parent).vtbl = (mDoExt_baseAnm__vtbl *)&__vt;
    if (this != (mDoExt_btpAnm *)0x0) {
      (this->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

