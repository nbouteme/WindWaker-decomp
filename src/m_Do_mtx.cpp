#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <m_Do_mtx.h>
#include <mtx/mtx.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <JKernel/JKRHeap.h>
#include <SComponent/c_math.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <cXyz.h>
#include <mDoMtx_quatStack_c.h>
#include <mDoMtx_stack_c.h>

struct MTX34 mDoMtx_stack_c;
undefined1 mDoMtx_stack_c;

namespace m_Do_mtx {
undefined4 mDoMtx_quatStack;
undefined mDoMtx_stack;

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall mDoMtx_XYZrotM(float *[][][][],
                            short,
                            short,
                            short) */

void mDoMtx_XYZrotM
               (MTX34 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  MTX34 MStack72;
  
  if ((short)param_4 != 0) {
    mDoMtx_ZrotS(&MStack72,param_4);
    mtx::PSMTXConcat(param_1,&MStack72,param_1);
  }
  if ((short)param_3 != 0) {
    mDoMtx_YrotS(&MStack72,param_3);
    mtx::PSMTXConcat(param_1,&MStack72,param_1);
  }
  if ((short)param_2 != 0) {
    mDoMtx_XrotS(&MStack72,param_2);
    mtx::PSMTXConcat(param_1,&MStack72,param_1);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall mDoMtx_ZXYrotS(float *[][][][],
                            short,
                            short,
                            short) */

void mDoMtx_ZXYrotS
               (MTX34 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  MTX34 MStack72;
  
  if ((short)param_3 == 0) {
    mtx::PSMTXIdentity(param_1);
  }
  else {
    mDoMtx_YrotS(param_1,param_3);
  }
  if ((short)param_2 != 0) {
    mDoMtx_XrotS(&MStack72,param_2);
    mtx::PSMTXConcat(param_1,&MStack72,param_1);
  }
  if ((short)param_4 != 0) {
    mDoMtx_ZrotS(&MStack72,param_4);
    mtx::PSMTXConcat(param_1,&MStack72,param_1);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall mDoMtx_ZXYrotM(float *[][][][],
                            short,
                            short,
                            short) */

void mDoMtx_ZXYrotM
               (MTX34 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  MTX34 MStack72;
  
  if ((short)param_3 != 0) {
    mDoMtx_YrotS(&MStack72,param_3);
    mtx::PSMTXConcat(param_1,&MStack72,param_1);
  }
  if ((short)param_2 != 0) {
    mDoMtx_XrotS(&MStack72,param_2);
    mtx::PSMTXConcat(param_1,&MStack72,param_1);
  }
  if ((short)param_4 != 0) {
    mDoMtx_ZrotS(&MStack72,param_4);
    mtx::PSMTXConcat(param_1,&MStack72,param_1);
  }
  return;
}


/* __stdcall mDoMtx_XrotS(float *[][][][],
                          short) */

void mDoMtx_XrotS(float *param_1,uint param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  
  iVar4 = (int)(param_2 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar1 = JKernel::JMath::jmaCosTable[iVar4];
  fVar2 = JKernel::JMath::jmaSinTable[iVar4];
  *param_1 = 1_0;
  fVar3 = _4029;
  param_1[1] = _4029;
  param_1[2] = fVar3;
  param_1[3] = fVar3;
  param_1[4] = fVar3;
  param_1[5] = fVar1;
  param_1[6] = -fVar2;
  param_1[7] = fVar3;
  param_1[8] = fVar3;
  param_1[9] = fVar2;
  param_1[10] = fVar1;
  param_1[0xb] = fVar3;
  return;
}


/* __stdcall mDoMtx_XrotM(float *[][][][],
                          short) */

void mDoMtx_XrotM(MTX34 *param_1,short param_2)

{
  undefined2 in_register_00000010;
  MTX34 MStack56;
  
  mDoMtx_XrotS(&MStack56,CONCAT22(in_register_00000010,param_2));
  mtx::PSMTXConcat(param_1,&MStack56,param_1);
  return;
}


/* __stdcall mDoMtx_YrotS(float *[][][][],
                          short) */

void mDoMtx_YrotS(float *param_1,uint param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  
  iVar4 = (int)(param_2 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar1 = JKernel::JMath::jmaCosTable[iVar4];
  fVar2 = JKernel::JMath::jmaSinTable[iVar4];
  *param_1 = fVar1;
  fVar3 = _4029;
  param_1[1] = _4029;
  param_1[2] = fVar2;
  param_1[3] = fVar3;
  param_1[4] = fVar3;
  param_1[5] = 1_0;
  param_1[6] = fVar3;
  param_1[7] = fVar3;
  param_1[8] = -fVar2;
  param_1[9] = fVar3;
  param_1[10] = fVar1;
  param_1[0xb] = fVar3;
  return;
}


/* __stdcall mDoMtx_YrotM(float *[][][][],
                          short) */

void mDoMtx_YrotM(MTX34 *param_1,short param_2)

{
  undefined2 in_register_00000010;
  MTX34 MStack56;
  
  mDoMtx_YrotS(&MStack56,CONCAT22(in_register_00000010,param_2));
  mtx::PSMTXConcat(param_1,&MStack56,param_1);
  return;
}


/* __stdcall mDoMtx_ZrotS(float *[][][][],
                          short) */

void mDoMtx_ZrotS(float *param_1,uint param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  
  iVar4 = (int)(param_2 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar1 = JKernel::JMath::jmaCosTable[iVar4];
  fVar2 = JKernel::JMath::jmaSinTable[iVar4];
  *param_1 = fVar1;
  param_1[1] = -fVar2;
  fVar3 = _4029;
  param_1[2] = _4029;
  param_1[3] = fVar3;
  param_1[4] = fVar2;
  param_1[5] = fVar1;
  param_1[6] = fVar3;
  param_1[7] = fVar3;
  param_1[8] = fVar3;
  param_1[9] = fVar3;
  param_1[10] = 1_0;
  param_1[0xb] = fVar3;
  return;
}


/* __stdcall mDoMtx_ZrotM(float *[][][][],
                          short) */

void mDoMtx_ZrotM(MTX34 *param_1,short param_2)

{
  undefined2 in_register_00000010;
  MTX34 MStack56;
  
  mDoMtx_ZrotS(&MStack56,CONCAT22(in_register_00000010,param_2));
  mtx::PSMTXConcat(param_1,&MStack56,param_1);
  return;
}


/* __stdcall mDoMtx_lookAt(float *[][][][],
                           Vec const *,
                           Vec const *,
                           short) */

void mDoMtx_lookAt(MTX34 *pDst,float *param_2,float *param_3,undefined4 param_4)

{
  char cVar1;
  double dVar2;
  cXyz cStack200;
  cXyz local_bc;
  cXyz cStack176;
  cXyz local_a4;
  cXyz local_98;
  cXyz cStack140;
  cXyz local_80;
  cXyz local_74;
  cXyz local_68;
  float local_5c;
  float local_58;
  float local_54;
  cXyz local_50;
  cXyz local_44;
  MTX34 MStack56;
  
  local_44.x = *param_2;
  local_44.y = param_2[1];
  local_44.z = param_2[2];
  local_74.x = *param_3;
  local_74.y = param_3[1];
  local_74.z = param_3[2];
  ::cXyz::operator__(&local_80,&local_44,&local_74);
  local_68.x = local_80.x;
  local_68.y = local_80.y;
  local_68.z = local_80.z;
  ::cXyz::normalize(&cStack140);
  local_50.x = _4029;
  local_50.y = 1_0;
  local_50.z = _4029;
  ::cXyz::outprod(&local_98,&local_50,&local_68);
  local_50.x = local_98.x;
  local_50.y = local_98.y;
  local_50.z = local_98.z;
  cVar1 = ::cXyz::normalizeRS(&local_50);
  if (cVar1 == '\0') {
    local_50.x = -local_68.y;
    local_50.y = _4029;
    local_50.z = _4029;
    ::cXyz::outprod(&local_a4,&local_50,&local_68);
    local_50.x = local_a4.x;
    local_50.y = local_a4.y;
    local_50.z = local_a4.z;
    ::cXyz::normalize(&cStack176);
  }
  ::cXyz::outprod(&local_bc,&local_68,&local_50);
  local_5c = local_bc.x;
  local_58 = local_bc.y;
  local_54 = local_bc.z;
  ::cXyz::normalize(&cStack200);
  pDst->m[0] = local_50.x;
  pDst->m[1] = local_50.y;
  pDst->m[2] = local_50.z;
  dVar2 = (double)mtx::PSVECDotProduct(&local_50,&local_44);
  pDst->m[3] = (float)-dVar2;
  pDst->m[1][0] = local_5c;
  pDst->m[1][1] = local_58;
  pDst->m[1][2] = local_54;
  dVar2 = (double)mtx::PSVECDotProduct(&local_5c,&local_44);
  pDst->m[1][3] = (float)-dVar2;
  pDst->m[2][0] = local_68.x;
  pDst->m[2][1] = local_68.y;
  pDst->m[2][2] = local_68.z;
  dVar2 = (double)mtx::PSVECDotProduct(&local_68,&local_44);
  pDst->m[2][3] = (float)-dVar2;
  mDoMtx_ZrotS(&MStack56,param_4);
  mtx::PSMTXConcat(&MStack56,pDst,pDst);
  return;
}

}

/* __thiscall cXyz::~cXyz(void) */

void __thiscall cXyz::_cXyz(cXyz *this)

{
  short in_r4;
  
  if ((this != (cXyz *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace m_Do_mtx {

/* __stdcall mDoMtx_lookAt(float *[][][][],
                           Vec const *,
                           Vec const *,
                           Vec const *,
                           short) */

void mDoMtx_lookAt(MTX34 *param_1,cXyz *pEye,cXyz *pCenter,cXyz *pUp,int bank)

{
  char cVar1;
  cXyz local_78;
  cXyz local_6c;
  float local_60;
  float local_5c;
  float local_58;
  cXyz local_54;
  cXyz local_48;
  MTX34 MStack60;
  
  local_48.x = pEye->x;
  local_48.y = pEye->y;
  local_48.z = pEye->z;
  local_54.x = pCenter->x;
  local_54.y = pCenter->y;
  local_54.z = pCenter->z;
  local_60 = pUp->x;
  local_5c = pUp->y;
  local_58 = pUp->z;
  ::cXyz::operator__(&local_6c,&local_48,&local_54);
  local_78.x = local_6c.x;
  local_78.y = local_6c.y;
  local_78.z = local_6c.z;
  cVar1 = ::cXyz::normalizeRS(&local_78);
  if (cVar1 == '\0') {
    local_54.z = local_54.z + 1_0;
  }
  if (((ABS(local_60) < SComponent::G_CM3D_F_ABS_MIN) &&
      (ABS(local_5c) < SComponent::G_CM3D_F_ABS_MIN)) &&
     (ABS(local_58) < SComponent::G_CM3D_F_ABS_MIN)) {
    local_5c = 1_0;
  }
  mtx::C_MTXLookAt(param_1,&local_48,&local_60,&local_54);
  mDoMtx_ZrotS(&MStack60,bank);
  mtx::PSMTXConcat(&MStack60,param_1,param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall mDoMtx_concatProjView(float const *[][][][],
                                   float const *[][][][],
                                   float *[][][][]) */

void mDoMtx_concatProjView(MTX34 *param_1,MTX34 *param_2,MTX34 *param_3)

{
  mtx::PSMTXConcat(param_1,param_2,param_3);
  param_3[1].m[0] =
       param_1[1].m[2] * param_2->m[2][0] +
       param_1[1].m[0] * param_2->m[0] + param_1[1].m[1] * param_2->m[1][0];
  param_3[1].m[1] =
       param_1[1].m[2] * param_2->m[2][1] +
       param_1[1].m[0] * param_2->m[1] + param_1[1].m[1] * param_2->m[1][1];
  param_3[1].m[2] =
       param_1[1].m[2] * param_2->m[2][2] +
       param_1[1].m[0] * param_2->m[2] + param_1[1].m[1] * param_2->m[1][2];
  param_3[1].m[3] =
       param_1[1].m[3] +
       param_1[1].m[2] * param_2->m[2][3] +
       param_1[1].m[0] * param_2->m[3] + param_1[1].m[1] * param_2->m[1][3];
  return;
}


/* WARNING: Removing unreachable block (ram,0x8000d518) */
/* WARNING: Removing unreachable block (ram,0x8000d510) */
/* WARNING: Removing unreachable block (ram,0x8000d520) */
/* __stdcall mDoMtx_inverseTranspose(float const *[][][][],
                                     float *[][][][]) */

void mDoMtx_inverseTranspose(MTX34 *param_1,MTX34 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  fVar11 = _4029;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  fVar1 = param_1->m[2][1];
  fVar2 = param_1->m[0];
  fVar3 = param_1->m[1][2];
  fVar4 = param_1->m[1];
  fVar5 = param_1->m[1][0];
  fVar6 = param_1->m[2][2];
  fVar7 = param_1->m[1][1];
  fVar8 = param_1->m[2][0];
  fVar9 = param_1->m[2];
  fVar10 = (((fVar1 * fVar9 * fVar5 + fVar6 * fVar2 * fVar7 + fVar8 * fVar4 * fVar3) -
            fVar9 * fVar8 * fVar7) - fVar6 * fVar5 * fVar4) - fVar3 * fVar2 * fVar1;
  if (_4029 != fVar10) {
    fVar10 = 1_0 / fVar10;
    param_2->m[2][0] = fVar10 * (fVar4 * fVar3 - fVar7 * fVar9);
    param_2->m[2][1] =
         fVar10 * -(param_1->m[0] * param_1->m[1][2] - param_1->m[1][0] * param_1->m[2]);
    param_2->m[2][2] =
         fVar10 * (param_1->m[0] * param_1->m[1][1] - param_1->m[1][0] * param_1->m[1]);
    param_2->m[0] = fVar10 * (fVar7 * fVar6 - fVar1 * fVar3);
    param_2->m[1] = fVar10 * -(fVar5 * fVar6 - fVar8 * fVar3);
    param_2->m[2] = fVar10 * (fVar5 * fVar1 - fVar8 * fVar7);
    param_2->m[3] = fVar11;
    param_2->m[1][0] = fVar10 * -(fVar4 * fVar6 - fVar1 * fVar9);
    param_2->m[1][1] = fVar10 * (fVar2 * fVar6 - fVar8 * fVar9);
    param_2->m[1][2] = fVar10 * -(fVar2 * fVar1 - fVar8 * fVar4);
    param_2->m[1][3] = fVar11;
    param_2->m[2][3] = fVar11;
  }
  __psq_l0(auStack8,0);
  __psq_l1(auStack8,0);
  __psq_l0(auStack24,0);
  __psq_l1(auStack24,0);
  __psq_l0(auStack40,0);
  __psq_l1(auStack40,0);
  return;
}


/* __stdcall mDoMtx_QuatConcat(Quaternion const *,
                               Quaternion const *,
                               Quaternion *) */

void mDoMtx_QuatConcat(float *param_1,float *param_2,float *param_3)

{
  param_3[3] = ((param_1[3] * param_2[3] - *param_1 * *param_2) - param_1[1] * param_2[1]) -
               param_1[2] * param_2[2];
  *param_3 = (param_1[1] * param_2[2] + param_1[3] * *param_2 + *param_1 * param_2[3]) -
             param_1[2] * param_2[1];
  param_3[1] = (param_1[2] * *param_2 + param_1[3] * param_2[1] + param_1[1] * param_2[3]) -
               *param_1 * param_2[2];
  param_3[2] = (*param_1 * param_2[1] + param_1[3] * param_2[2] + param_1[2] * param_2[3]) -
               param_1[1] * *param_2;
  return;
}


/* __stdcall mDoMtx_MtxToRot(float const *[][][][],
                             csXyz *) */

void mDoMtx_MtxToRot(MTX34 *mtx,csXyz *outRot)

{
  float fVar1;
  float fVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  
  fVar1 = mtx->m[2];
  fVar2 = mtx->m[2][2];
  dVar5 = (double)(fVar1 * fVar1 + fVar2 * fVar2);
  if ((double)_4029 < dVar5) {
    dVar4 = 1.0 / SQRT(dVar5);
    dVar4 = _4226 * dVar4 * (_4227 - dVar5 * dVar4 * dVar4);
    dVar4 = _4226 * dVar4 * (_4227 - dVar5 * dVar4 * dVar4);
    dVar5 = (double)(float)(dVar5 * _4226 * dVar4 * (_4227 - dVar5 * dVar4 * dVar4));
  }
  iVar3 = SComponent::cM_atan2s(-mtx->m[1][2],(float)dVar5);
  outRot->x = (short)iVar3;
  if ((outRot->x == 0x4000) || (outRot->x == -0x4000)) {
    outRot->z = 0;
    iVar3 = SComponent::cM_atan2s(-mtx->m[2][0],mtx->m[0]);
    outRot->y = (short)iVar3;
  }
  else {
    iVar3 = SComponent::cM_atan2s(mtx->m[2],mtx->m[2][2]);
    outRot->y = (short)iVar3;
    iVar3 = SComponent::cM_atan2s(mtx->m[1][0],mtx->m[1][1]);
    outRot->z = (short)iVar3;
  }
  return;
}

}

namespace mDoMtx_stack_c {

/* __thiscall push(void) */

undefined4 push(void)

{
  undefined *puVar1;
  ulong uVar2;
  undefined4 uVar3;
  
  puVar1 = next;
  if (next < end) {
    next = next + 0x30;
    mtx::PSMTXCopy(&now,(MTX34 *)puVar1);
    uVar3 = 1;
  }
  else {
    if (next >= end) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"m_Do_mtx.cpp",0x2d3,"next < end");
      m_Do_printf::OSPanic("m_Do_mtx.cpp",0x2d3,"Halt");
    }
    uVar3 = 0;
  }
  return uVar3;
}


/* __thiscall pop(void) */

undefined4 pop(void)

{
  ulong uVar1;
  undefined4 uVar2;
  
  if (&buffer < next) {
    next = next + -0x30;
    mtx::PSMTXCopy((MTX34 *)next,&now);
    uVar2 = 1;
  }
  else {
    if (&buffer >= next) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"m_Do_mtx.cpp",0x2e9,"next > buffer");
      m_Do_printf::OSPanic("m_Do_mtx.cpp",0x2e9,"Halt");
    }
    uVar2 = 0;
  }
  return uVar2;
}


/* __thiscall transM(float,
                                     float,
                                     float) */

void transM(float param_1,float param_2,float param_3)

{
  MTX34 MStack56;
  
  mtx::PSMTXTrans((double)param_1,(double)param_2,(double)param_3,&MStack56);
  mtx::PSMTXConcat(&now,&MStack56,&now);
  return;
}


/* __thiscall scaleM(float,
                                     float,
                                     float) */

void scaleM(float param_1,float param_2,float param_3)

{
  MTX34 MStack56;
  
  mtx::PSMTXScale((double)param_1,(double)param_2,(double)param_3,&MStack56);
  mtx::PSMTXConcat(&now,&MStack56,&now);
  return;
}

}

/* __thiscall mDoMtx_stack_c::lYrotM(long) */

void __thiscall mDoMtx_stack_c::lYrotM(mDoMtx_stack_c *this,long param_1)

{
  MTX34 MStack56;
  
  m_Do_mtx::mDoMtx_YrotS(&MStack56,(int)(short)((uint)this >> 0x10));
  mtx::PSMTXConcat(&now,&MStack56,&now);
  return;
}


/* __thiscall mDoMtx_stack_c::rYrotM(float) */

void __thiscall mDoMtx_stack_c::rYrotM(mDoMtx_stack_c *this,float param_1)

{
  MTX34 MStack56;
  
  mtx::PSMTXRotRad(&MStack56,'Y',param_1);
  mtx::PSMTXConcat(&now,&MStack56,&now);
  return;
}


namespace mDoMtx_stack_c {

/* __thiscall quatM(Quaternion const *) */

void quatM(Quaternion *param_1)

{
  MTX34 MStack56;
  
  mtx::PSMTXQuat(&MStack56,param_1);
  mtx::PSMTXConcat(&now,&MStack56,&now);
  return;
}

}

namespace m_Do_mtx {

void __sinit_m_Do_mtx_cpp(void)

{
  ::mDoMtx_stack_c::next = &::mDoMtx_stack_c::buffer;
  ::mDoMtx_stack_c::end = &_4322;
  Runtime.PPCEABI.H::__register_global_object
            (&mDoMtx_stack,::mDoMtx_stack_c::_mDoMtx_stack_c,&_4322);
  mDoMtx_quatStack = &DAT_803a55e8;
  DAT_803a56f8 = &DAT_803a55f8;
  DAT_803a56fc = &DAT_803a56f8;
  Runtime.PPCEABI.H::__register_global_object
            (&mDoMtx_quatStack,::mDoMtx_quatStack_c::_mDoMtx_quatStack_c,&_4352);
  return;
}

}

/* __thiscall mDoMtx_quatStack_c::~mDoMtx_quatStack_c(void) */

void __thiscall mDoMtx_quatStack_c::_mDoMtx_quatStack_c(mDoMtx_quatStack_c *this)

{
  short in_r4;
  
  if ((this != (mDoMtx_quatStack_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall mDoMtx_stack_c::~mDoMtx_stack_c(void) */

void __thiscall mDoMtx_stack_c::_mDoMtx_stack_c(mDoMtx_stack_c *this)

{
  short in_r4;
  
  if ((this != (mDoMtx_stack_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

