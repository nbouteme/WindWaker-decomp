#include <m_Do_lib.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <gx/GXTexture.h>
#include <J3DU/J3DUClipper.h>
#include <mtx/mtxvec.h>
#include <m_Do_lib.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JKernel/JKRHeap.h>
#include <J3DUClipper.h>

struct J3DUClipper mDoLib_clipper;
float mDoLib_clipper;
float mDoLib_clipper;

namespace m_Do_lib {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall mDoLib_setResTimgObj(ResTIMG *,
                                  _GXTexObj *,
                                  unsigned long,
                                  _GXTlutObj *) */

byte mDoLib_setResTimgObj
               (ResTIMG *pResTIMG,GXTexObj *pTex,long param_3,GXTlutObj *param_4)

{
  ulong uVar1;
  
  if (pResTIMG->mbHasTlut == 0) {
    gx::GXInitTexObj(pTex,&pResTIMG->mTexFmt + pResTIMG->mTexDataOffs,(uint)pResTIMG->mWidth,
                     (uint)pResTIMG->mHeight,pResTIMG->mTexFmt,pResTIMG->mWrapS,pResTIMG->mWrapT,
                     SUB41(1 - (uint)pResTIMG->mMipmapCount >> 0x1f,0));
  }
  else {
    if (param_4 == (GXTlutObj *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"m_Do_lib.cpp",0x2b,"o_tlutObj != 0");
      m_Do_printf::OSPanic("m_Do_lib.cpp",0x2b,"Halt");
    }
    gx::GXInitTlutObj(param_4,&pResTIMG->mTexFmt + pResTIMG->mTlutDataOffs,pResTIMG->mTlutFmt,
                      pResTIMG->mTlutCount);
    gx::GXInitTexObjCI(pTex,&pResTIMG->mTexFmt + pResTIMG->mTexDataOffs,pResTIMG->mWidth,
                       pResTIMG->mHeight,pResTIMG->mTexFmt,pResTIMG->mWrapS,pResTIMG->mWrapT,
                       1 - pResTIMG->mMipmapCount >> 0x1f,param_3);
  }
  gx::GXInitTexObjLOD((double)(0_125 * (float)((double)CONCAT44(0x43300000,
                                                                (int)(char)pResTIMG->mMinLOD ^
                                                                0x80000000) - _3991)),
                      (double)(0_125 * (float)((double)CONCAT44(0x43300000,
                                                                (int)(char)pResTIMG->mMaxLOD ^
                                                                0x80000000) - _3991)),
                      (double)(0_01 * (float)((double)CONCAT44(0x43300000,
                                                               (int)pResTIMG->mLODBias ^ 0x80000000)
                                             - _3991)),pTex,pResTIMG->mMinFilter,
                      pResTIMG->mMagFilter,pResTIMG->mbBiasClamp,pResTIMG->mbDoEdgeLOD,
                      pResTIMG->mMaxAniso);
  return pResTIMG->mbHasTlut;
}

}

namespace mDoLib_clipper {

/* WARNING: Removing unreachable block (ram,0x80017730) */
/* __thiscall setup(float,
                                    float,
                                    float,
                                    float) */

void setup(float fovy,float aspect,float near,float far)

{
  int iVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar3 = (double)fovy;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  mClipper.mFovY = fovy;
  mClipper.mAspect = aspect;
  mClipper.mNear = near;
  mClipper.mFar = far;
  mSystemFar = far;
  J3DUClipper::calcViewFrustum(&mClipper);
  iVar1 = (int)((int)((double)m_Do_lib::_4092 * dVar3) & 0xffffU) >>
          (JKernel::JMath::jmaSinShift & 0x3f);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  mFovyRate = JKernel::JMath::jmaCosTable[iVar1] / JKernel::JMath::jmaSinTable[iVar1];
  return;
}

}

namespace m_Do_lib {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall mDoLib_project(Vec *,
                            Vec *) */

void mDoLib_project(cXyz *param_1,cXyz *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar5 = _4136;
  if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera == (camera_class *)0x0) {
    param_2->x = _4136;
    param_2->y = fVar5;
    param_2->z = fVar5;
  }
  else {
    mtx::PSMTXMultVec((MTX34 *)&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->field_0x1a0
                      ,param_1,param_2);
    fVar5 = *(float *)&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->field_0x1dc +
            param_1->z *
            *(float *)&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->field_0x1d8 +
            param_1->x *
            *(float *)&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->field_0x1d0 +
            param_1->y *
            *(float *)&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->field_0x1d4;
    if (_4136 <= param_2->z) {
      param_2->z = _4136;
    }
    if (_4136 < fVar5) {
      fVar5 = _4138 / fVar5;
      param_2->z = param_2->z * fVar5;
    }
    else {
      if (_4136 == fVar5) {
        param_2->z = param_2->z * _4137;
        fVar5 = _4137;
      }
      else {
        param_2->z = param_2->z * (_4138 / fVar5);
        fVar5 = _4137;
      }
    }
    fVar6 = _4138;
    fVar1 = (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x230)->mXOrig;
    if (_4136 == fVar1) {
      fVar2 = (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x230)->mWidth;
    }
    else {
      fVar1 = _4138 * (_4139 * fVar1 +
                      (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x230)->mWidth) - _4140;
      fVar2 = _4141;
    }
    fVar3 = (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x230)->mYOrig;
    if (_4136 == fVar3) {
      fVar4 = (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x230)->mHeight;
    }
    else {
      fVar3 = _4138 * (_4139 * fVar3 +
                      (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x230)->mHeight) - _4142;
      fVar4 = _4143;
    }
    param_2->x = fVar1 + fVar2 * (_4138 + param_2->x * fVar5);
    param_2->y = fVar3 + fVar4 * (fVar6 + param_2->y * -fVar5);
  }
  return;
}


/* __stdcall mDoLib_pos2camera(Vec *,
                               Vec *) */

void mDoLib_pos2camera(cXyz *param_1,cXyz *param_2)

{
  mtx::PSMTXMultVec(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtx,param_1,
                    param_2);
  return;
}


/* __stdcall mDoLib_cnvind32(unsigned long) */

undefined4 mDoLib_cnvind32(undefined4 param_1)

{
  undefined local_4;
  undefined uStack3;
  undefined uStack2;
  
  uStack2 = (undefined)((uint)param_1 >> 8);
  uStack3 = (undefined)((uint)param_1 >> 0x10);
  local_4 = (undefined)((uint)param_1 >> 0x18);
  return CONCAT31(CONCAT21(CONCAT11((char)param_1,uStack2),uStack3),local_4);
}


/* __stdcall mDoLib_cnvind16(unsigned short) */

undefined2 mDoLib_cnvind16(undefined2 param_1)

{
  undefined local_4;
  
  local_4 = (undefined)((ushort)param_1 >> 8);
  return CONCAT11((char)param_1,local_4);
}


void __sinit_m_Do_lib_cpp(undefined4 param_1,EVP_PKEY_CTX *param_2)

{
  ::mDoLib_clipper::mClipper._0_4_ = &::J3DUClipper::__vt;
  ::J3DUClipper::init(&::mDoLib_clipper::mClipper,param_2);
  Runtime.PPCEABI.H::__register_global_object
            (&::mDoLib_clipper::mClipper,::J3DUClipper::_J3DUClipper,&_4080);
  return;
}

}

/* __thiscall J3DUClipper::~J3DUClipper(void) */

void __thiscall J3DUClipper::_J3DUClipper(J3DUClipper *this)

{
  short in_r4;
  
  if ((this != (J3DUClipper *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

