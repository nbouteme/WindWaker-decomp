#include <d_wind_arrow.h>
#include <m_Do_ext.h>
#include <os/OSCache.h>
#include <d_wind_arrow.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <mtx/mtx.h>
#include <d_kankyo_wether.h>
#include <SComponent/c_math.h>
#include <mtx/mtxvec.h>
#include <J3DGraphAnimator/J3DMaterialAttach.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <dWindArrow_c.h>


/* __thiscall dWindArrow_c::createHeap(void) */

undefined4 __thiscall dWindArrow_c::createHeap(dWindArrow_c *this)

{
  JKRSolidHeap *pJVar1;
  
  if (*(int *)(this + 0xf8) == 0) {
    pJVar1 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(0,0);
    *(JKRSolidHeap **)(this + 0xf8) = pJVar1;
    if (*(int *)(this + 0xf8) == 0) {
      return 0;
    }
  }
  return 1;
}


/* __thiscall dWindArrow_c::adjustHeap(void) */

void __thiscall dWindArrow_c::adjustHeap(dWindArrow_c *this)

{
  uint uVar1;
  
  m_Do_ext::mDoExt_restoreCurrentHeap();
  uVar1 = m_Do_ext::mDoExt_adjustSolidHeap(*(JKRSolidHeap **)(this + 0xf8));
  if (-1 < (int)uVar1) {
    os::DCStoreRangeNoSync
              (*(undefined4 *)(*(int *)(this + 0xf8) + 0x30),
               *(undefined4 *)(*(int *)(this + 0xf8) + 0x38));
  }
  return;
}


namespace d_wind_arrow {

/* __stdcall dWindArrow_Draw(dWindArrow_c *) */

void dWindArrow_Draw(dWindArrow_c *param_1)

{
  ::dWindArrow_c::draw(param_1);
  return;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dWindArrow_c::draw(void) */

undefined4 __thiscall dWindArrow_c::draw(dWindArrow_c *this)

{
  cXyz *pcVar1;
  int iVar2;
  cXyz local_78;
  MTX34 MStack108;
  MTX34 MStack60;
  
  if ((d_wind_arrow::_4227 != *(float *)(*(int *)(this + 0x10c) + 0xc)) &&
     ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x10000U) != 0)) {
    if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) ||
       ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc & 1U) != 0)) {
      if (init_localstatic4_draw == (code)0x0) {
        _l_offsetPos_localstatic3_draw = d_wind_arrow::_4227;
        DAT_803e80ec = d_wind_arrow::_4228;
        DAT_803e80f0 = d_wind_arrow::_4229;
        Runtime.PPCEABI.H::__register_global_object
                  (l_offsetPos_localstatic3_draw,::cXyz::_cXyz,&d_wind_arrow::_4128);
        init_localstatic4_draw = (code)0x1;
      }
      if (init_localstatic6_draw == (code)0x0) {
        _l_scale_localstatic5_draw = d_wind_arrow::_4230;
        DAT_803e80f8 = d_wind_arrow::_4230;
        DAT_803e80fc = d_wind_arrow::_4230;
        Runtime.PPCEABI.H::__register_global_object
                  (l_scale_localstatic5_draw,::cXyz::_cXyz,&d_wind_arrow::_4130);
        init_localstatic6_draw = (code)0x1;
      }
      iVar2 = *(int *)(this + 0xf4);
      mtx::PSMTXTrans((double)*(float *)(iVar2 + 0x1f8),(double)*(float *)(iVar2 + 0x1fc),
                      (double)*(float *)(iVar2 + 0x200),&mDoMtx_stack_c::now);
      m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,*(short *)(iVar2 + 0x20e));
      mtx::PSMTXCopy(&mDoMtx_stack_c::now,&MStack60);
      pcVar1 = d_kankyo_wether::dKyw_get_wind_vec();
      iVar2 = SComponent::cM_atan2s(pcVar1->x,pcVar1->z);
      m_Do_mtx::mDoMtx_YrotS(&mDoMtx_stack_c::now,iVar2);
      mtx::PSMTXCopy(&mDoMtx_stack_c::now,&MStack108);
      iVar2 = *(int *)(this + 0xfc);
      *(float *)(iVar2 + 0x18) = _l_scale_localstatic5_draw;
      *(float *)(iVar2 + 0x1c) = DAT_803e80f8;
      *(float *)(iVar2 + 0x20) = DAT_803e80fc;
      mtx::PSMTXMultVec(&MStack60,(cXyz *)l_offsetPos_localstatic3_draw,&local_78);
      MStack108.m[0][3] = local_78.x;
      MStack108.m[1][3] = local_78.y;
      MStack108.m[2][3] = local_78.z;
      mtx::PSMTXCopy(&MStack108,(MTX34 *)(*(int *)(this + 0xfc) + 0x24));
      ::mDoExt_btkAnm::entry
                ((mDoExt_btkAnm *)(this + 0x108),*(J3DModelData **)(*(int *)(this + 0xfc) + 4),
                 *(float *)(*(int *)(this + 0x10c) + 0x10));
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
      m_Do_ext::mDoExt_modelUpdateDL(*(J3DModel **)(this + 0xfc));
      J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
           d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
      J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
           d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
      mDoExt_invisibleModel::entryMaskOff((mDoExt_invisibleModel *)(this + 0x100));
      J3DMaterialTable::removeTexMtxAnimator
                ((J3DMaterialTable *)(*(int *)(*(int *)(this + 0xfc) + 4) + 0x58),
                 *(J3DAnmTextureSRTKey **)(this + 0x110));
    }
  }
  return 1;
}


namespace d_wind_arrow {

/* __stdcall dWindArrow_Execute(dWindArrow_c *) */

undefined4 dWindArrow_Execute(int param_1)

{
  float *pfVar1;
  
  pfVar1 = d_kankyo_wether::dKyw_get_wind_power();
  *(float *)(*(int *)(param_1 + 0x10c) + 0xc) = *pfVar1;
  ::mDoExt_baseAnm::play((mDoExt_baseAnm *)(param_1 + 0x108));
  return 1;
}


/* __stdcall dWindArrow_IsDelete(dWindArrow_c *) */

undefined4 dWindArrow_IsDelete(void)

{
  return 1;
}


/* __stdcall dWindArrow_Delete(dWindArrow_c *) */

undefined4 dWindArrow_Delete(int param_1)

{
  if (param_1 != 0) {
    m_Do_ext::mDoExt_destroySolidHeap(*(undefined4 *)(param_1 + 0xf8));
    if (((param_1 != -0xfc) && (param_1 != -0x108)) &&
       (*(undefined ***)(param_1 + 0x108) = &::mDoExt_btkAnm::__vt, param_1 != -0x108)) {
      *(undefined ***)(param_1 + 0x108) = &::mDoExt_baseAnm::__vt;
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dWindArrow_Create(kankyo_class *) */

undefined4 dWindArrow_Create(dWindArrow_c *param_1)

{
  int iVar1;
  undefined4 uVar2;
  J3DModelData *pModel;
  ulong uVar3;
  J3DModel *pJVar4;
  J3DAnmTextureSRTKey *pAnm;
  
  iVar1 = ::dWindArrow_c::createHeap(param_1);
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else {
    if (param_1 != (dWindArrow_c *)0x0) {
      *(undefined ***)(param_1 + 0x108) = &::mDoExt_baseAnm::__vt;
      *(undefined4 *)(param_1 + 0x10c) = 0;
      *(undefined ***)(param_1 + 0x108) = &::mDoExt_btkAnm::__vt;
      *(undefined4 *)(param_1 + 0x114) = 0;
    }
    pModel = (J3DModelData *)
             dRes_control_c::getRes
                       ("Always",0x3c,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pModel == (J3DModelData *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_wind_arrow.cpp",0x56,"modelData != 0");
      m_Do_printf::OSPanic("d_wind_arrow.cpp",0x56,&DAT_80363ac7);
    }
    pJVar4 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x200);
    *(J3DModel **)(param_1 + 0xfc) = pJVar4;
    if (*(J3DModel **)(param_1 + 0xfc) == (J3DModel *)0x0) {
      uVar2 = 5;
    }
    else {
      iVar1 = mDoExt_invisibleModel::create
                        ((mDoExt_invisibleModel *)(param_1 + 0x100),*(J3DModel **)(param_1 + 0xfc));
      if (iVar1 == 0) {
        uVar2 = 5;
      }
      else {
        pAnm = (J3DAnmTextureSRTKey *)
               dRes_control_c::getRes
                         ("Always",0x5f,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40
                         );
        if (pAnm == (J3DAnmTextureSRTKey *)0x0) {
          uVar3 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar3,"d_wind_arrow.cpp",0x65,"anm != 0");
          m_Do_printf::OSPanic("d_wind_arrow.cpp",0x65,&DAT_80363ac7);
        }
        iVar1 = ::mDoExt_btkAnm::init
                          ((mDoExt_btkAnm *)(param_1 + 0x108),pModel,pAnm,true,Repeat,_4308,0,-1,
                           false,0);
        if (iVar1 == 0) {
          uVar2 = 5;
        }
        else {
          uVar2 = 4;
        }
      }
    }
    ::dWindArrow_c::adjustHeap(param_1);
  }
  return uVar2;
}

