#include <JPADraw/JPADrawVisitor.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <gx/GXAttr.h>
#include <gx/GXGeometry.h>
#include <mtx/mtx.h>
#include <gx/GXTransform.h>
#include <gx/GXTexture.h>
#include <gx/GXTev.h>
#include <mtx/mtxvec.h>
#include <JPABase/JPAEmitter.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JPADraw/JPADrawVisitor.h>
#include <JKernel/JKRHeap.h>
#include <JPADrawExecPoint.h>
#include <JPADrawExecYBillBoard.h>
#include <JPADrawCalcScaleAnmTimingReverseX.h>
#include <JPADrawCalcAlphaFlickMultSin.h>
#include <JPADrawCalcScaleAnmTimingReverseY.h>
#include <JPADrawExecRegisterPrmAlphaAnm.h>
#include <JPADrawExecGenPrjTexMtx.h>
#include <JPADrawCalcTextureAnmIndexRandom.h>
#include <JPADrawCalcTextureAnmIndexMerge.h>
#include <JPADrawCalcScaleCopyX2Y.h>
#include <JPADrawExecRotBillBoard.h>
#include <JPADrawCalcColorEnv.h>
#include <JPADrawExecRegisterPrmCEnv.h>
#include <JPADrawExecDirectionalCross.h>
#include <JPADrawCalcEmitterVisitor.h>
#include <JPADrawCalcColorAnmFrameMerge.h>
#include <JPADrawExecSetPointSize.h>
#include <JPADrawExecRegisterEnvColorAnm.h>
#include <JPADrawExecBillBoard.h>
#include <JPADrawCalcParticleVisitor.h>
#include <JPADrawCalcScaleX.h>
#include <JPADrawExecLoadTexture.h>
#include <JPADrawCalcColorAnmFrameReverse.h>
#include <JPADrawCalcScaleY.h>
#include <JPADrawExecRegisterColorChildPE.h>
#include <JPADrawExecStripeCross.h>
#include <JPADrawExecRotationCross.h>
#include <JPADrawExecParticleVisitor.h>
#include <JPADrawCalcScaleAnmTimingNormal.h>
#include <JPADrawExecRotDirectionalCross.h>
#include <JPADrawExecRegisterColorEmitterE.h>
#include <JPADrawCalcScaleAnmTimingRepeatY.h>
#include <JPADrawCalcScaleAnmTimingRepeatX.h>
#include <JPADrawCalcScaleYBySpeed.h>
#include <JPADrawExecRotDirectional.h>
#include <JPADrawExecDirectional.h>
#include <JPADrawCalcScaleXBySpeed.h>
#include <JPADrawCalcChildScaleOut.h>
#include <JPADrawExecRegisterColorEmitterP.h>
#include <JPADrawCalcAlphaFlickNrmSin.h>
#include <JPADrawExecGenIdtMtx.h>
#include <JPADrawExecRotation.h>
#include <JPADrawCalcColorAnmFrameRandom.h>
#include <JPADrawExecLine.h>
#include <JPADrawExecGenTexMtx0.h>
#include <JPADrawExecDirBillBoard.h>
#include <JPADrawExecEmitterVisitor.h>
#include <JPADrawCalcAlpha.h>
#include <JPADrawExecRotYBillBoard.h>
#include <JPADrawCalcAlphaFlickAddSin.h>
#include <JPADrawCalcColorCopyFromEmitter.h>
#include <JPADrawCalcColorPrm.h>
#include <JPADrawCalcTextureAnmIndexReverse.h>
#include <JPADrawExecCallBack.h>
#include <JPADrawExecRegisterPrmAEnv.h>
#include <JPADrawExecStripe.h>
#include <JPADrawCalcTextureAnmIndexNormal.h>
#include <JPADrawExecSetLineWidth.h>
#include <JPADrawExecLoadExTex.h>
#include <JPADrawCalcTextureAnmIndexRepeat.h>
#include <JPADrawExecSetTexMtx.h>
#include <JPADrawCalcColorAnmFrameRepeat.h>
#include <JPADrawCalcChildAlphaOut.h>
#include <JPADrawExecRegisterPrmColorAnm.h>
#include <JPADrawExecLoadDefaultTexture.h>
#include <JPADrawExecRegisterColorEmitterPE.h>
#include <JPADrawCalcColorAnmFrameNormal.h>
#include <JPADrawExecGenPrjMtx.h>


namespace JPADrawContext {
struct JPADrawSetupTev * pcb;
}

/* __thiscall JPADrawExecLoadExTex::exec(JPADrawContext const *) */

void __thiscall JPADrawExecLoadExTex::exec(JPADrawExecLoadExTex *this,JPADrawContext *param_1)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  JPATexture *pJVar4;
  GXTexCoordID dst_coord;
  
  if (param_1->mpTexIdxArray == (short *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JPADrawVisitor.cpp",0x32,"pDC->pTexIdx");
    m_Do_printf::OSPanic("JPADrawVisitor.cpp",0x32,&DAT_80366a20);
  }
  dst_coord = GX_TEXCOORD1;
  iVar2 = (**(code **)(*(int *)param_1->mpExTexShape + 0xc))();
  if (iVar2 == 2) {
    gx::GXSetTexCoordGen2(GX_TEXCOORD1,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
    gx::GXSetTexCoordGen2(GX_TEXCOORD2,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
    gx::GXEnableTexOffsets(1,1,1);
    gx::GXEnableTexOffsets(2,1,1);
    uVar3 = (**(code **)(*(int *)param_1->mpExTexShape + 0x1c))();
    pJVar4 = param_1->mpTextureResource->mpTexArray[(ushort)param_1->mpTexIdxArray[uVar3 & 0xff]];
    (**(code **)(pJVar4->vtbl + 0x10))(pJVar4,5);
    uVar3 = (**(code **)(*(int *)param_1->mpExTexShape + 0x20))();
    pJVar4 = param_1->mpTextureResource->mpTexArray[(ushort)param_1->mpTexIdxArray[uVar3 & 0xff]];
    (**(code **)(pJVar4->vtbl + 0x10))(pJVar4,6);
    dst_coord = GX_TEXCOORD3;
  }
  else {
    if ((iVar2 < 2) && (0 < iVar2)) {
      gx::GXSetTexCoordGen2(GX_TEXCOORD1,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
      gx::GXEnableTexOffsets(1,1,1);
      uVar3 = (**(code **)(*(int *)param_1->mpExTexShape + 0x1c))();
      pJVar4 = param_1->mpTextureResource->mpTexArray[(ushort)param_1->mpTexIdxArray[uVar3 & 0xff]];
      (**(code **)(pJVar4->vtbl + 0x10))(pJVar4,5);
      dst_coord = GX_TEXCOORD2;
    }
  }
  iVar2 = (**(code **)(*(int *)param_1->mpExTexShape + 0x24))();
  if (iVar2 != 0) {
    gx::GXSetTexCoordGen2(dst_coord,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
    gx::GXEnableTexOffsets(dst_coord,1,1);
    uVar3 = (**(code **)(*(int *)param_1->mpExTexShape + 0x28))();
    pJVar4 = param_1->mpTextureResource->mpTexArray[(ushort)param_1->mpTexIdxArray[uVar3 & 0xff]];
    (**(code **)(pJVar4->vtbl + 0x10))(pJVar4,7);
  }
  return;
}


/* __thiscall JPADrawExecGenPrjMtx::exec(JPADrawContext const *) */

void __thiscall JPADrawExecGenPrjMtx::exec(JPADrawExecGenPrjMtx *this,JPADrawContext *param_1)

{
  double dVar1;
  MTX34 MStack56;
  
  dVar1 = (double)JPADraw::_2504;
  mtx::C_MTXLightPerspective
            ((double)(float)JPABaseEmitter::emtrInfo.field_0x104,
             (double)(float)JPABaseEmitter::emtrInfo.field_0x108,dVar1,(double)JPADraw::_2505,dVar1,
             dVar1,&MStack56);
  mtx::PSMTXConcat(&MStack56,&JPADrawContext::pcb->mViewMtx,&MStack56);
  gx::GXLoadTexMtxImm(&MStack56,GX_TEXMTX0,0);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX3x4,GX_TG_POS,GX_TEXMTX0,false,GX_PTIDENTITY);
  gx::GXEnableTexOffsets(0,1,1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8025fefc) */
/* WARNING: Removing unreachable block (ram,0x8025feec) */
/* WARNING: Removing unreachable block (ram,0x8025fee4) */
/* WARNING: Removing unreachable block (ram,0x8025fef4) */
/* WARNING: Removing unreachable block (ram,0x8025ff04) */
/* __thiscall JPADrawExecGenPrjTexMtx::exec(JPADrawContext const *) */

void __thiscall JPADrawExecGenPrjTexMtx::exec(JPADrawExecGenPrjTexMtx *this,JPADrawContext *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f27;
  double dVar6;
  undefined8 in_f28;
  double dVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  MTX34 local_c8;
  MTX34 MStack152;
  longlong local_68;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  dVar5 = (double)JPADraw::_2504;
  mtx::C_MTXLightPerspective
            ((double)(float)JPABaseEmitter::emtrInfo.field_0x104,
             (double)(float)JPABaseEmitter::emtrInfo.field_0x108,dVar5,(double)JPADraw::_2505,dVar5,
             dVar5,&MStack152);
  dVar6 = (double)param_1->mpBaseEmitter->mTick;
  dVar5 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexStaticTransX)();
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexScrollTransX)();
  dVar10 = (double)(float)((double)(float)(dVar6 * dVar4) + dVar5);
  dVar5 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexStaticTransY)();
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexScrollTransY)();
  dVar9 = (double)(float)((double)(float)(dVar6 * dVar4) + dVar5);
  dVar5 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexStaticScaleX)();
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexScrollScaleX)();
  dVar8 = (double)(float)((double)(float)(dVar6 * dVar4) + dVar5);
  dVar5 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexStaticScaleY)();
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexScrollScaleY)();
  dVar7 = (double)(float)((double)(float)(dVar6 * dVar4) + dVar5);
  dVar5 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexScrollRotate)();
  uVar1 = (uint)(JPADraw::_2523 * (float)(dVar6 * dVar5));
  local_68 = (longlong)(int)uVar1;
  iVar2 = (int)(uVar1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  dVar4 = (double)JKernel::JMath::jmaSinTable[iVar2];
  dVar6 = (double)JKernel::JMath::jmaCosTable[iVar2];
  local_c8.m[0][0] = (float)(dVar8 * dVar6);
  local_c8.m[0][1] = (float)(-dVar8 * dVar4);
  dVar5 = (double)JPADraw::_2504;
  local_c8.m[0][2] =
       (float)(dVar5 + (double)(float)(dVar8 * (double)((float)(dVar4 * (double)(float)(dVar5 + 
                                                  dVar9)) - (float)(dVar6 * (double)(float)(dVar5 + 
                                                  dVar10)))));
  local_c8.m[0][3] = JPADraw::_2524;
  local_c8.m[1][0] = (float)(dVar7 * dVar4);
  local_c8.m[1][1] = (float)(dVar7 * dVar6);
  local_c8.m[1][2] =
       (float)(dVar5 + (double)(float)(-dVar7 * (double)((float)(dVar4 * (double)(float)(dVar5 + 
                                                  dVar10)) +
                                                  (float)(dVar6 * (double)(float)(dVar5 + dVar9)))))
  ;
  local_c8.m[1][3] = JPADraw::_2524;
  local_c8.m[2][0] = JPADraw::_2524;
  local_c8.m[2][1] = JPADraw::_2524;
  local_c8.m[2][2] = JPADraw::_2525;
  local_c8.m[2][3] = JPADraw::_2524;
  mtx::PSMTXConcat(&local_c8,&MStack152,&MStack152);
  mtx::PSMTXConcat(&MStack152,&JPADrawContext::pcb->mViewMtx,&local_c8);
  gx::GXLoadTexMtxImm(&local_c8,GX_TEXMTX0,0);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX3x4,GX_TG_POS,GX_TEXMTX0,false,GX_PTIDENTITY);
  gx::GXEnableTexOffsets(0,1,1);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  __psq_l0(auStack56,uVar3);
  __psq_l1(auStack56,uVar3);
  __psq_l0(auStack72,uVar3);
  __psq_l1(auStack72,uVar3);
  return;
}


/* __thiscall JPADrawExecGenTexMtx0::exec(JPADrawContext const *) */

void __thiscall JPADrawExecGenTexMtx0::exec(JPADrawExecGenTexMtx0 *this,JPADrawContext *param_1)

{
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_TEXMTX0,false,GX_PTIDENTITY);
  gx::GXEnableTexOffsets(0,1,1);
  return;
}


/* __thiscall JPADrawExecGenIdtMtx::exec(JPADrawContext const *) */

void __thiscall JPADrawExecGenIdtMtx::exec(JPADrawExecGenIdtMtx *this,JPADrawContext *param_1)

{
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXEnableTexOffsets(0,1,1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x802602c8) */
/* WARNING: Removing unreachable block (ram,0x802602b8) */
/* WARNING: Removing unreachable block (ram,0x802602a8) */
/* WARNING: Removing unreachable block (ram,0x802602b0) */
/* WARNING: Removing unreachable block (ram,0x802602c0) */
/* WARNING: Removing unreachable block (ram,0x802602d0) */
/* __thiscall JPADrawExecSetTexMtx::exec(JPADrawContext const *) */

void __thiscall JPADrawExecSetTexMtx::exec(JPADrawExecSetTexMtx *this,JPADrawContext *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f26;
  double dVar6;
  undefined8 in_f27;
  double dVar7;
  undefined8 in_f28;
  double dVar8;
  undefined8 in_f29;
  double dVar9;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  longlong local_a8;
  undefined4 local_a0;
  uint uStack156;
  undefined4 local_98;
  uint uStack148;
  undefined4 local_90;
  uint uStack140;
  undefined4 local_88;
  uint uStack132;
  undefined4 local_80;
  uint uStack124;
  longlong local_78;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  uStack124 = (uint)param_1->mpBaseEmitter->mTick;
  local_a8 = (longlong)(int)uStack124;
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTilingX)();
  dVar11 = (double)(float)((double)JPADraw::_2504 * dVar4);
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTilingY)();
  dVar10 = (double)(float)((double)JPADraw::_2504 * dVar4);
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexStaticTransX)();
  dVar5 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexScrollTransX)();
  uStack156 = uStack124 ^ 0x80000000;
  local_a0 = 0x43300000;
  dVar9 = (double)(float)((double)(float)((double)(float)((double)CONCAT44(0x43300000,uStack156) -
                                                         JPADraw::_2554) * dVar5) + dVar4);
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexStaticTransY)();
  dVar5 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexScrollTransY)();
  uStack148 = uStack124 ^ 0x80000000;
  local_98 = 0x43300000;
  dVar8 = (double)(float)((double)(float)((double)(float)((double)CONCAT44(0x43300000,uStack148) -
                                                         JPADraw::_2554) * dVar5) + dVar4);
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexStaticScaleX)();
  dVar5 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexScrollScaleX)();
  uStack140 = uStack124 ^ 0x80000000;
  local_90 = 0x43300000;
  dVar7 = (double)(float)((double)(float)((double)(float)((double)CONCAT44(0x43300000,uStack140) -
                                                         JPADraw::_2554) * dVar5) + dVar4);
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexStaticScaleY)();
  dVar5 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexScrollScaleY)();
  uStack132 = uStack124 ^ 0x80000000;
  local_88 = 0x43300000;
  dVar6 = (double)(float)((double)(float)((double)(float)((double)CONCAT44(0x43300000,uStack132) -
                                                         JPADraw::_2554) * dVar5) + dVar4);
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexScrollRotate)();
  uStack124 = uStack124 ^ 0x80000000;
  local_80 = 0x43300000;
  uVar1 = (uint)(JPADraw::_2523 *
                (float)((double)(float)((double)CONCAT44(0x43300000,uStack124) - JPADraw::_2554) *
                       dVar4));
  local_78 = (longlong)(int)uVar1;
  iVar2 = (int)(uVar1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  dVar4 = (double)JKernel::JMath::jmaSinTable[iVar2];
  dVar5 = (double)JKernel::JMath::jmaCosTable[iVar2];
  local_d8 = (float)(dVar7 * dVar5);
  local_d4 = (float)(-dVar7 * dVar4);
  local_d0 = JPADraw::_2524;
  local_cc = (float)(dVar11 + (double)(float)(dVar7 * (double)((float)(dVar4 * (double)(float)(
                                                  dVar10 + dVar8)) -
                                                  (float)(dVar5 * (double)(float)(dVar11 + dVar9))))
                    );
  local_c8 = (float)(dVar6 * dVar4);
  local_c4 = (float)(dVar6 * dVar5);
  local_c0 = JPADraw::_2524;
  local_bc = (float)(dVar10 + (double)(float)(-dVar6 * (double)((float)(dVar4 * (double)(float)(
                                                  dVar11 + dVar9)) +
                                                  (float)(dVar5 * (double)(float)(dVar10 + dVar8))))
                    );
  local_b8 = JPADraw::_2524;
  local_b4 = JPADraw::_2524;
  local_b0 = JPADraw::_2525;
  local_ac = JPADraw::_2524;
  gx::GXLoadTexMtxImm(&local_d8,GX_TEXMTX0,1);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_TEXMTX0,false,GX_PTIDENTITY);
  gx::GXEnableTexOffsets(0,1,1);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  __psq_l0(auStack56,uVar3);
  __psq_l1(auStack56,uVar3);
  __psq_l0(auStack72,uVar3);
  __psq_l1(auStack72,uVar3);
  __psq_l0(auStack88,uVar3);
  __psq_l1(auStack88,uVar3);
  return;
}


/* __thiscall JPADrawExecLoadDefaultTexture::exec(JPADrawContext const *) */

void __thiscall
JPADrawExecLoadDefaultTexture::exec(JPADrawExecLoadDefaultTexture *this,JPADrawContext *pDrawCtx)

{
  gx::GXLoadTexObj((GXTexObj *)&(pDrawCtx->mpTextureResource->mDefaultTexture).mTexObj,0);
  return;
}


/* __thiscall JPADrawExecLoadTexture::exec(JPADrawContext const *) */

void __thiscall JPADrawExecLoadTexture::exec(JPADrawExecLoadTexture *this,JPADrawContext *param_1)

{
  JPATexture *pJVar1;
  
  pJVar1 = param_1->mpTextureResource->mpTexArray[(ushort)param_1->mpDraw->mTexIdx];
  (**(code **)(pJVar1->vtbl + 0x10))(pJVar1,0);
  return;
}


/* __thiscall JPADrawExecSetPointSize::exec(JPADrawContext const *,
                                            JPABaseParticle *) */

void __thiscall
JPADrawExecSetPointSize::exec
          (JPADrawExecSetPointSize *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  gx::GXSetPointSize((int)(JPADrawContext::pcb->mGlobalScale2D[0] * param_2->mScaleX),5);
  return;
}


/* __thiscall JPADrawExecSetLineWidth::exec(JPADrawContext const *,
                                            JPABaseParticle *) */

void __thiscall
JPADrawExecSetLineWidth::exec
          (JPADrawExecSetLineWidth *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  gx::GXSetLineWidth((int)(JPADrawContext::pcb->mGlobalScale2D[0] * param_2->mScaleX),5);
  return;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall JPADrawExecRegisterPrmColorAnm::exec(JPADrawContext const *,
                                                   JPABaseParticle *) */

void __thiscall
JPADrawExecRegisterPrmColorAnm::exec
          (JPADrawExecRegisterPrmColorAnm *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  uint uVar1;
  uint uVar2;
  _GXColor _Var3;
  _GXColor local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint uStack12;
  longlong local_8;
  
  _Var3 = param_2->mPrmColor;
  uVar2 = (uint)CONCAT12((char)((((uint)_Var3 & 0xff0000) >> 0x10) *
                                ((JPADrawContext::pcb->mGlobalPrmColor).g + 1) >> 8),SUB42(_Var3,0))
  ;
  local_14._2_2_ =
       SUB42(_Var3,0) & 0xff |
       (ushort)(byte)(((uVar2 & 0xff00) >> 8) * ((JPADrawContext::pcb->mGlobalPrmColor).b + 1) >> 8)
       << 8;
  uStack12 = (local_14._2_2_ & 0xff) * ((JPADrawContext::pcb->mGlobalPrmColor).a + 1) >> 8 & 0xff;
  local_10 = 0x43300000;
  uVar1 = (uint)(param_2->mAlphaOut *
                (float)((double)CONCAT44(0x43300000,uStack12) - JPADraw::_2616));
  local_8 = (longlong)(int)uVar1;
  local_14 = (_GXColor)
             ((((uint)_Var3 >> 0x18) * ((JPADrawContext::pcb->mGlobalPrmColor).r + 1) >> 8) << 0x18
              | uVar2 & 0xffff0000 | local_14._2_2_ & 0xffffff00 | uVar1 & 0xff);
  local_18 = local_14;
  gx::GXSetTevColor(GX_TEVREG0,&local_18);
  return;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall JPADrawExecRegisterPrmAlphaAnm::exec(JPADrawContext const *,
                                                   JPABaseParticle *) */

void __thiscall
JPADrawExecRegisterPrmAlphaAnm::exec
          (JPADrawExecRegisterPrmAlphaAnm *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  uint uVar1;
  uint uVar2;
  _GXColor _Var3;
  _GXColor local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint uStack12;
  longlong local_8;
  
  _Var3 = param_1->mpDraw->mPrmColor;
  uVar2 = (uint)CONCAT12((char)((((uint)_Var3 & 0xff0000) >> 0x10) *
                                ((JPADrawContext::pcb->mGlobalPrmColor).g + 1) >> 8),SUB42(_Var3,0))
  ;
  local_14._2_2_ =
       SUB42(_Var3,0) & 0xff |
       (ushort)(byte)(((uVar2 & 0xff00) >> 8) * ((JPADrawContext::pcb->mGlobalPrmColor).b + 1) >> 8)
       << 8;
  uStack12 = (local_14._2_2_ & 0xff) * ((JPADrawContext::pcb->mGlobalPrmColor).a + 1) >> 8 & 0xff;
  local_10 = 0x43300000;
  uVar1 = (uint)(param_2->mAlphaOut *
                (float)((double)CONCAT44(0x43300000,uStack12) - JPADraw::_2616));
  local_8 = (longlong)(int)uVar1;
  local_14 = (_GXColor)
             ((((uint)_Var3 >> 0x18) * ((JPADrawContext::pcb->mGlobalPrmColor).r + 1) >> 8) << 0x18
              | uVar2 & 0xffff0000 | local_14._2_2_ & 0xffffff00 | uVar1 & 0xff);
  local_18 = local_14;
  gx::GXSetTevColor(GX_TEVREG0,&local_18);
  return;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall JPADrawExecRegisterEnvColorAnm::exec(JPADrawContext const *,
                                                   JPABaseParticle *) */

void __thiscall
JPADrawExecRegisterEnvColorAnm::exec
          (JPADrawExecRegisterEnvColorAnm *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  uint uVar1;
  _GXColor _Var2;
  _GXColor local_8;
  undefined4 local_4;
  
  _Var2 = param_2->mEnvColor;
  uVar1 = (uint)CONCAT12((char)((((uint)_Var2 & 0xff0000) >> 0x10) *
                                ((JPADrawContext::pcb->mGlobalEnvColor).g + 1) >> 8),SUB42(_Var2,0))
  ;
  local_4._2_2_ =
       SUB42(_Var2,0) & 0xff |
       (ushort)(byte)(((uVar1 & 0xff00) >> 8) * ((JPADrawContext::pcb->mGlobalEnvColor).b + 1) >> 8)
       << 8;
  local_4 = (_GXColor)
            ((((uint)_Var2 >> 0x18) * ((JPADrawContext::pcb->mGlobalEnvColor).r + 1) >> 8) << 0x18 |
             uVar1 & 0xffff0000 | (uint)local_4._2_2_);
  local_8 = local_4;
  gx::GXSetTevColor(GX_TEVREG1,&local_8);
  return;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall JPADrawExecRegisterPrmCEnv::exec(JPADrawContext const *,
                                               JPABaseParticle *) */

void __thiscall
JPADrawExecRegisterPrmCEnv::exec
          (JPADrawExecRegisterPrmCEnv *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  uint uVar1;
  uint uVar2;
  _GXColor _Var3;
  _GXColor _Var4;
  _GXColor local_28;
  _GXColor local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint uStack20;
  longlong local_10;
  
  _Var3 = param_2->mPrmColor;
  _Var4 = param_2->mEnvColor;
  uVar2 = (uint)CONCAT12((char)((((uint)_Var3 & 0xff0000) >> 0x10) *
                                ((JPADrawContext::pcb->mGlobalPrmColor).g + 1) >> 8),SUB42(_Var3,0))
  ;
  local_1c._2_2_ =
       SUB42(_Var3,0) & 0xff |
       (ushort)(byte)(((uVar2 & 0xff00) >> 8) * ((JPADrawContext::pcb->mGlobalPrmColor).b + 1) >> 8)
       << 8;
  uStack20 = (local_1c._2_2_ & 0xff) * ((JPADrawContext::pcb->mGlobalPrmColor).a + 1) >> 8 & 0xff;
  local_18 = 0x43300000;
  uVar1 = (uint)(param_2->mAlphaOut *
                (float)((double)CONCAT44(0x43300000,uStack20) - JPADraw::_2616));
  local_10 = (longlong)(int)uVar1;
  local_1c = (_GXColor)
             ((((uint)_Var3 >> 0x18) * ((JPADrawContext::pcb->mGlobalPrmColor).r + 1) >> 8) << 0x18
              | uVar2 & 0xffff0000 | local_1c._2_2_ & 0xffffff00 | uVar1 & 0xff);
  uVar1 = (uint)CONCAT12((char)((((uint)_Var4 & 0xff0000) >> 0x10) *
                                ((JPADrawContext::pcb->mGlobalEnvColor).g + 1) >> 8),SUB42(_Var4,0))
  ;
  local_20._2_2_ =
       SUB42(_Var4,0) & 0xff |
       (ushort)(byte)(((uVar1 & 0xff00) >> 8) * ((JPADrawContext::pcb->mGlobalEnvColor).b + 1) >> 8)
       << 8;
  local_20 = (_GXColor)
             ((((uint)_Var4 >> 0x18) * ((JPADrawContext::pcb->mGlobalEnvColor).r + 1) >> 8) << 0x18
              | uVar1 & 0xffff0000 | (uint)local_20._2_2_);
  local_24 = local_1c;
  gx::GXSetTevColor(GX_TEVREG0,&local_24);
  local_28 = local_20;
  gx::GXSetTevColor(GX_TEVREG1,&local_28);
  return;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall JPADrawExecRegisterPrmAEnv::exec(JPADrawContext const *,
                                               JPABaseParticle *) */

void __thiscall
JPADrawExecRegisterPrmAEnv::exec
          (JPADrawExecRegisterPrmAEnv *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  uint uVar1;
  uint uVar2;
  _GXColor _Var3;
  _GXColor _Var4;
  _GXColor local_28;
  _GXColor local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint uStack20;
  longlong local_10;
  
  _Var3 = param_1->mpDraw->mPrmColor;
  _Var4 = param_2->mEnvColor;
  uVar2 = (uint)CONCAT12((char)((((uint)_Var3 & 0xff0000) >> 0x10) *
                                ((JPADrawContext::pcb->mGlobalPrmColor).g + 1) >> 8),SUB42(_Var3,0))
  ;
  local_1c._2_2_ =
       SUB42(_Var3,0) & 0xff |
       (ushort)(byte)(((uVar2 & 0xff00) >> 8) * ((JPADrawContext::pcb->mGlobalPrmColor).b + 1) >> 8)
       << 8;
  uStack20 = (local_1c._2_2_ & 0xff) * ((JPADrawContext::pcb->mGlobalPrmColor).a + 1) >> 8 & 0xff;
  local_18 = 0x43300000;
  uVar1 = (uint)(param_2->mAlphaOut *
                (float)((double)CONCAT44(0x43300000,uStack20) - JPADraw::_2616));
  local_10 = (longlong)(int)uVar1;
  local_1c = (_GXColor)
             ((((uint)_Var3 >> 0x18) * ((JPADrawContext::pcb->mGlobalPrmColor).r + 1) >> 8) << 0x18
              | uVar2 & 0xffff0000 | local_1c._2_2_ & 0xffffff00 | uVar1 & 0xff);
  uVar1 = (uint)CONCAT12((char)((((uint)_Var4 & 0xff0000) >> 0x10) *
                                ((JPADrawContext::pcb->mGlobalEnvColor).g + 1) >> 8),SUB42(_Var4,0))
  ;
  local_20._2_2_ =
       SUB42(_Var4,0) & 0xff |
       (ushort)(byte)(((uVar1 & 0xff00) >> 8) * ((JPADrawContext::pcb->mGlobalEnvColor).b + 1) >> 8)
       << 8;
  local_20 = (_GXColor)
             ((((uint)_Var4 >> 0x18) * ((JPADrawContext::pcb->mGlobalEnvColor).r + 1) >> 8) << 0x18
              | uVar1 & 0xffff0000 | (uint)local_20._2_2_);
  local_24 = local_1c;
  gx::GXSetTevColor(GX_TEVREG0,&local_24);
  local_28 = local_20;
  gx::GXSetTevColor(GX_TEVREG1,&local_28);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80260b40) */
/* WARNING: Removing unreachable block (ram,0x80260b30) */
/* WARNING: Removing unreachable block (ram,0x80260b20) */
/* WARNING: Removing unreachable block (ram,0x80260b28) */
/* WARNING: Removing unreachable block (ram,0x80260b38) */
/* WARNING: Removing unreachable block (ram,0x80260b48) */
/* __thiscall JPADrawExecSetTexMtx::exec(JPADrawContext const *,
                                         JPABaseParticle *) */

void __thiscall
JPADrawExecSetTexMtx::exec
          (JPADrawExecSetTexMtx *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f26;
  double dVar6;
  undefined8 in_f27;
  double dVar7;
  undefined8 in_f28;
  double dVar8;
  undefined8 in_f29;
  double dVar9;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  longlong local_a8;
  undefined4 local_a0;
  uint uStack156;
  undefined4 local_98;
  uint uStack148;
  undefined4 local_90;
  uint uStack140;
  undefined4 local_88;
  uint uStack132;
  undefined4 local_80;
  uint uStack124;
  longlong local_78;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  uStack124 = (uint)param_2->mCurFrame;
  local_a8 = (longlong)(int)uStack124;
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTilingX)();
  dVar11 = (double)(float)((double)JPADraw::_2504 * dVar4);
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTilingY)();
  dVar10 = (double)(float)((double)JPADraw::_2504 * dVar4);
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexStaticTransX)();
  dVar5 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexScrollTransX)();
  uStack156 = uStack124 ^ 0x80000000;
  local_a0 = 0x43300000;
  dVar9 = (double)(float)((double)(float)((double)(float)((double)CONCAT44(0x43300000,uStack156) -
                                                         JPADraw::_2554) * dVar5) + dVar4);
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexStaticTransY)();
  dVar5 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexScrollTransY)();
  uStack148 = uStack124 ^ 0x80000000;
  local_98 = 0x43300000;
  dVar8 = (double)(float)((double)(float)((double)(float)((double)CONCAT44(0x43300000,uStack148) -
                                                         JPADraw::_2554) * dVar5) + dVar4);
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexStaticScaleX)();
  dVar5 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexScrollScaleX)();
  uStack140 = uStack124 ^ 0x80000000;
  local_90 = 0x43300000;
  dVar7 = (double)(float)((double)(float)((double)(float)((double)CONCAT44(0x43300000,uStack140) -
                                                         JPADraw::_2554) * dVar5) + dVar4);
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexStaticScaleY)();
  dVar5 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexScrollScaleY)();
  uStack132 = uStack124 ^ 0x80000000;
  local_88 = 0x43300000;
  dVar6 = (double)(float)((double)(float)((double)(float)((double)CONCAT44(0x43300000,uStack132) -
                                                         JPADraw::_2554) * dVar5) + dVar4);
  dVar4 = (double)(*(code *)param_1->mpBaseArc->vtbl->getTexScrollRotate)();
  uStack124 = uStack124 ^ 0x80000000;
  local_80 = 0x43300000;
  uVar1 = (uint)(JPADraw::_2523 *
                (float)((double)(float)((double)CONCAT44(0x43300000,uStack124) - JPADraw::_2554) *
                       dVar4));
  local_78 = (longlong)(int)uVar1;
  iVar2 = (int)(uVar1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  dVar4 = (double)JKernel::JMath::jmaSinTable[iVar2];
  dVar5 = (double)JKernel::JMath::jmaCosTable[iVar2];
  local_d8 = (float)(dVar7 * dVar5);
  local_d4 = (float)(-dVar7 * dVar4);
  local_d0 = JPADraw::_2524;
  local_cc = (float)(dVar11 + (double)(float)(dVar7 * (double)((float)(dVar4 * (double)(float)(
                                                  dVar10 + dVar8)) -
                                                  (float)(dVar5 * (double)(float)(dVar11 + dVar9))))
                    );
  local_c8 = (float)(dVar6 * dVar4);
  local_c4 = (float)(dVar6 * dVar5);
  local_c0 = JPADraw::_2524;
  local_bc = (float)(dVar10 + (double)(float)(-dVar6 * (double)((float)(dVar4 * (double)(float)(
                                                  dVar11 + dVar9)) +
                                                  (float)(dVar5 * (double)(float)(dVar10 + dVar8))))
                    );
  local_b8 = JPADraw::_2524;
  local_b4 = JPADraw::_2524;
  local_b0 = JPADraw::_2525;
  local_ac = JPADraw::_2524;
  gx::GXLoadTexMtxImm(&local_d8,GX_TEXMTX0,1);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  __psq_l0(auStack56,uVar3);
  __psq_l1(auStack56,uVar3);
  __psq_l0(auStack72,uVar3);
  __psq_l1(auStack72,uVar3);
  __psq_l0(auStack88,uVar3);
  __psq_l1(auStack88,uVar3);
  return;
}


/* __thiscall JPADrawExecLoadTexture::exec(JPADrawContext const *,
                                           JPABaseParticle *) */

void __thiscall
JPADrawExecLoadTexture::exec
          (JPADrawExecLoadTexture *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  JPATexture *pJVar1;
  
  pJVar1 = param_1->mpTextureResource->mpTexArray[param_2->mTexIdx];
  (**(code **)(pJVar1->vtbl + 0x10))(pJVar1,0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80260d04) */
/* WARNING: Removing unreachable block (ram,0x80260cf4) */
/* WARNING: Removing unreachable block (ram,0x80260cfc) */
/* WARNING: Removing unreachable block (ram,0x80260d0c) */
/* __thiscall JPADrawExecBillBoard::exec(JPADrawContext const *,
                                         JPABaseParticle *) */

undefined8 __thiscall
JPADrawExecBillBoard::exec
          (JPADrawExecBillBoard *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  undefined8 in_f28;
  double dVar5;
  undefined8 in_f29;
  double dVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  cXyz local_58 [2];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  if ((param_2->mFlags & 8) == 0) {
    dVar7 = (double)(param_2->mScaleX *
                    (JPADrawContext::pcb->mGlobalScale2D[0] - JPADrawContext::pcb->mPivotX));
    dVar6 = (double)(param_2->mScaleY *
                    (JPADrawContext::pcb->mGlobalScale2D[1] - JPADrawContext::pcb->mPivotY));
    dVar5 = (double)(param_2->mScaleX *
                    (JPADrawContext::pcb->mGlobalScale2D[0] + JPADrawContext::pcb->mPivotX));
    dVar8 = (double)(param_2->mScaleY *
                    (JPADrawContext::pcb->mGlobalScale2D[1] + JPADrawContext::pcb->mPivotY));
    local_58[0].x = (param_2->mPosition).x;
    local_58[0].y = (param_2->mPosition).y;
    local_58[0].z = (param_2->mPosition).z;
    mtx::PSMTXMultVec(JPADrawContext::pcb->mpViewMtx,local_58,local_58);
    gx::GXBegin(0x80,0,4);
    fVar1 = (float)(-dVar5 + (double)local_58[0].x);
    this = (JPADrawExecBillBoard *)0xcc010000;
    write_volatile_4(0xcc008000,fVar1);
    fVar2 = (float)(dVar8 + (double)local_58[0].y);
    write_volatile_4(0xcc008000,fVar2);
    write_volatile_4(0xcc008000,local_58[0].z);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].y);
    fVar3 = (float)(dVar7 + (double)local_58[0].x);
    write_volatile_4(0xcc008000,fVar3);
    write_volatile_4(0xcc008000,fVar2);
    write_volatile_4(0xcc008000,local_58[0].z);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].y);
    write_volatile_4(0xcc008000,fVar3);
    fVar2 = (float)(-dVar6 + (double)local_58[0].y);
    write_volatile_4(0xcc008000,fVar2);
    write_volatile_4(0xcc008000,local_58[0].z);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].y);
    write_volatile_4(0xcc008000,fVar1);
    write_volatile_4(0xcc008000,fVar2);
    write_volatile_4(0xcc008000,local_58[0].z);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].y);
    param_1 = (JPADrawContext *)JPADrawContext::pcb;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  return CONCAT44(this,param_1);
}


/* WARNING: Removing unreachable block (ram,0x80260f0c) */
/* WARNING: Removing unreachable block (ram,0x80260efc) */
/* WARNING: Removing unreachable block (ram,0x80260eec) */
/* WARNING: Removing unreachable block (ram,0x80260ef4) */
/* WARNING: Removing unreachable block (ram,0x80260f04) */
/* WARNING: Removing unreachable block (ram,0x80260f14) */
/* __thiscall JPADrawExecRotBillBoard::exec(JPADrawContext const *,
                                            JPABaseParticle *) */

undefined8 __thiscall
JPADrawExecRotBillBoard::exec
          (JPADrawExecRotBillBoard *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 in_f26;
  double dVar3;
  undefined8 in_f27;
  double dVar4;
  undefined8 in_f28;
  double dVar5;
  undefined8 in_f29;
  double dVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  cXyz local_78 [2];
  undefined auStack88 [16];
  undefined auStack72 [16];
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
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  if ((param_2->mFlags & 8) == 0) {
    iVar1 = (int)(uint)(ushort)param_2->mRotateAngle >> (JKernel::JMath::jmaSinShift & 0x3f);
    dVar8 = (double)JKernel::JMath::jmaSinTable[iVar1];
    dVar7 = (double)JKernel::JMath::jmaCosTable[iVar1];
    dVar6 = (double)(-param_2->mScaleX *
                    (JPADrawContext::pcb->mGlobalScale2D[0] + JPADrawContext::pcb->mPivotX));
    dVar5 = (double)(param_2->mScaleY *
                    (JPADrawContext::pcb->mGlobalScale2D[1] + JPADrawContext::pcb->mPivotY));
    dVar4 = (double)(param_2->mScaleX *
                    (JPADrawContext::pcb->mGlobalScale2D[0] - JPADrawContext::pcb->mPivotX));
    dVar3 = (double)(-param_2->mScaleY *
                    (JPADrawContext::pcb->mGlobalScale2D[1] - JPADrawContext::pcb->mPivotY));
    local_78[0].x = (param_2->mPosition).x;
    local_78[0].y = (param_2->mPosition).y;
    local_78[0].z = (param_2->mPosition).z;
    mtx::PSMTXMultVec(JPADrawContext::pcb->mpViewMtx,local_78,local_78);
    gx::GXBegin(0x80,0,4);
    this = (JPADrawExecRotBillBoard *)0xcc010000;
    write_volatile_4(0xcc008000,((float)(dVar6 * dVar7) - (float)(dVar5 * dVar8)) + local_78[0].x);
    write_volatile_4(0xcc008000,(float)(dVar5 * dVar7) + (float)(dVar6 * dVar8) + local_78[0].y);
    write_volatile_4(0xcc008000,local_78[0].z);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].y);
    write_volatile_4(0xcc008000,((float)(dVar4 * dVar7) - (float)(dVar5 * dVar8)) + local_78[0].x);
    write_volatile_4(0xcc008000,(float)(dVar5 * dVar7) + (float)(dVar4 * dVar8) + local_78[0].y);
    write_volatile_4(0xcc008000,local_78[0].z);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].y);
    write_volatile_4(0xcc008000,((float)(dVar4 * dVar7) - (float)(dVar3 * dVar8)) + local_78[0].x);
    write_volatile_4(0xcc008000,(float)(dVar3 * dVar7) + (float)(dVar4 * dVar8) + local_78[0].y);
    write_volatile_4(0xcc008000,local_78[0].z);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].y);
    write_volatile_4(0xcc008000,((float)(dVar6 * dVar7) - (float)(dVar3 * dVar8)) + local_78[0].x);
    write_volatile_4(0xcc008000,(float)(dVar3 * dVar7) + (float)(dVar6 * dVar8) + local_78[0].y);
    write_volatile_4(0xcc008000,local_78[0].z);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].y);
    param_1 = (JPADrawContext *)JPADrawContext::pcb;
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  __psq_l0(auStack56,uVar2);
  __psq_l1(auStack56,uVar2);
  __psq_l0(auStack72,uVar2);
  __psq_l1(auStack72,uVar2);
  __psq_l0(auStack88,uVar2);
  __psq_l1(auStack88,uVar2);
  return CONCAT44(this,param_1);
}


/* __thiscall JPADrawExecYBillBoard::exec(JPADrawContext const *,
                                          JPABaseParticle *) */

undefined8 __thiscall
JPADrawExecYBillBoard::exec
          (JPADrawExecYBillBoard *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  if ((param_2->mFlags & 8) == 0) {
    local_30 = param_2->mScaleX *
               (JPADrawContext::pcb->mGlobalScale2D[0] - JPADrawContext::pcb->mPivotX);
    local_38 = param_2->mScaleY *
               (JPADrawContext::pcb->mGlobalScale2D[1] + JPADrawContext::pcb->mPivotY);
    local_3c = -(param_2->mScaleX *
                (JPADrawContext::pcb->mGlobalScale2D[0] + JPADrawContext::pcb->mPivotX));
    local_34 = JPADraw::_2524;
    local_28 = JPADraw::_2524;
    local_20 = -(param_2->mScaleY *
                (JPADrawContext::pcb->mGlobalScale2D[1] - JPADrawContext::pcb->mPivotY));
    local_1c = JPADraw::_2524;
    local_10 = JPADraw::_2524;
    local_2c = local_38;
    local_24 = local_30;
    local_18 = local_3c;
    local_14 = local_20;
    mtx::PSMTXMultVecArray(&JPADrawContext::pcb->field_0x38,&local_3c,&local_3c,4);
    local_48 = (param_2->mPosition).x;
    local_44 = (param_2->mPosition).y;
    local_40 = (param_2->mPosition).z;
    mtx::PSMTXMultVecSR(JPADrawContext::pcb->mpViewMtx,&local_48,&local_48);
    gx::GXBegin(0x80,0,4);
    this = (JPADrawExecYBillBoard *)0xcc010000;
    write_volatile_4(0xcc008000,local_3c + local_48);
    write_volatile_4(0xcc008000,local_38 + local_44);
    write_volatile_4(0xcc008000,local_34 + local_40);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].y);
    write_volatile_4(0xcc008000,local_30 + local_48);
    write_volatile_4(0xcc008000,local_2c + local_44);
    write_volatile_4(0xcc008000,local_28 + local_40);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].y);
    write_volatile_4(0xcc008000,local_24 + local_48);
    write_volatile_4(0xcc008000,local_20 + local_44);
    write_volatile_4(0xcc008000,local_1c + local_40);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].y);
    write_volatile_4(0xcc008000,local_18 + local_48);
    write_volatile_4(0xcc008000,local_14 + local_44);
    write_volatile_4(0xcc008000,local_10 + local_40);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].y);
    param_1 = (JPADrawContext *)JPADrawContext::pcb;
  }
  return CONCAT44(this,param_1);
}


/* __thiscall JPADrawExecRotYBillBoard::exec(JPADrawContext const *,
                                             JPABaseParticle *) */

undefined8 __thiscall
JPADrawExecRotYBillBoard::exec
          (JPADrawExecRotYBillBoard *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  if ((param_2->mFlags & 8) == 0) {
    iVar4 = (int)(uint)(ushort)param_2->mRotateAngle >> (JKernel::JMath::jmaSinShift & 0x3f);
    fVar1 = JKernel::JMath::jmaSinTable[iVar4];
    fVar2 = JKernel::JMath::jmaCosTable[iVar4];
    fVar3 = -param_2->mScaleX *
            (JPADrawContext::pcb->mGlobalScale2D[0] + JPADrawContext::pcb->mPivotX);
    local_2c = param_2->mScaleY *
               (JPADrawContext::pcb->mGlobalScale2D[1] + JPADrawContext::pcb->mPivotY);
    local_20 = param_2->mScaleX *
               (JPADrawContext::pcb->mGlobalScale2D[0] - JPADrawContext::pcb->mPivotX);
    local_14 = -param_2->mScaleY *
               (JPADrawContext::pcb->mGlobalScale2D[1] - JPADrawContext::pcb->mPivotY);
    local_18 = fVar3 * fVar2;
    local_30 = local_2c * fVar1;
    local_3c = local_18 - local_30;
    local_2c = local_2c * fVar2;
    fVar3 = fVar3 * fVar1;
    local_38 = local_2c + fVar3;
    local_34 = JPADraw::_2524;
    local_24 = local_20 * fVar2;
    local_30 = local_24 - local_30;
    local_20 = local_20 * fVar1;
    local_2c = local_2c + local_20;
    local_28 = JPADraw::_2524;
    fVar1 = local_14 * fVar1;
    local_24 = local_24 - fVar1;
    local_14 = local_14 * fVar2;
    local_20 = local_14 + local_20;
    local_1c = JPADraw::_2524;
    local_18 = local_18 - fVar1;
    local_14 = local_14 + fVar3;
    local_10 = JPADraw::_2524;
    mtx::PSMTXMultVecArray(&JPADrawContext::pcb->field_0x38,&local_3c,&local_3c,4);
    local_48 = (param_2->mPosition).x;
    local_44 = (param_2->mPosition).y;
    local_40 = (param_2->mPosition).z;
    mtx::PSMTXMultVecSR(JPADrawContext::pcb->mpViewMtx,&local_48,&local_48);
    gx::GXBegin(0x80,0,4);
    this = (JPADrawExecRotYBillBoard *)0xcc010000;
    write_volatile_4(0xcc008000,local_3c + local_48);
    write_volatile_4(0xcc008000,local_38 + local_44);
    write_volatile_4(0xcc008000,local_34 + local_40);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].y);
    write_volatile_4(0xcc008000,local_30 + local_48);
    write_volatile_4(0xcc008000,local_2c + local_44);
    write_volatile_4(0xcc008000,local_28 + local_40);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].y);
    write_volatile_4(0xcc008000,local_24 + local_48);
    write_volatile_4(0xcc008000,local_20 + local_44);
    write_volatile_4(0xcc008000,local_1c + local_40);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].y);
    write_volatile_4(0xcc008000,local_18 + local_48);
    write_volatile_4(0xcc008000,local_14 + local_44);
    write_volatile_4(0xcc008000,local_10 + local_40);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].y);
    param_1 = (JPADrawContext *)JPADrawContext::pcb;
  }
  return CONCAT44(this,param_1);
}


namespace JPADraw {

/* __stdcall dirTypeVel(JPABaseParticle *,
                        JPABaseEmitter *,
                        JGeometry::TVec3<float><float>&) */

void dirTypeVel(int param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_3 = *(undefined4 *)(param_1 + 0x34);
  param_3[1] = *(undefined4 *)(param_1 + 0x38);
  param_3[2] = *(undefined4 *)(param_1 + 0x3c);
  return;
}


/* __stdcall dirTypePos(JPABaseParticle *,
                        JPABaseEmitter *,
                        JGeometry::TVec3<float><float>&) */

void dirTypePos(int param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_3 = *(undefined4 *)(param_1 + 0x1c);
  param_3[1] = *(undefined4 *)(param_1 + 0x20);
  param_3[2] = *(undefined4 *)(param_1 + 0x24);
  return;
}


/* __stdcall dirTypePosInv(JPABaseParticle *,
                           JPABaseEmitter *,
                           JGeometry::TVec3<float><float>&) */

void dirTypePosInv(int param_1,undefined4 param_2,float *param_3)

{
  *param_3 = *(float *)(param_1 + 0x1c);
  param_3[1] = *(float *)(param_1 + 0x20);
  param_3[2] = *(float *)(param_1 + 0x24);
  *param_3 = -*param_3;
  param_3[1] = -param_3[1];
  param_3[2] = -param_3[2];
  return;
}


/* __stdcall dirTypeEmtrDir(JPABaseParticle *,
                            JPABaseEmitter *,
                            JGeometry::TVec3<float><float>&) */

void dirTypeEmtrDir(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_3 = JPABaseEmitter::emtrInfo._248_4_;
  param_3[1] = JPABaseEmitter::emtrInfo._252_4_;
  param_3[2] = JPABaseEmitter::emtrInfo._256_4_;
  return;
}


/* WARNING: Removing unreachable block (ram,0x80261484) */
/* WARNING: Removing unreachable block (ram,0x8026147c) */
/* WARNING: Removing unreachable block (ram,0x8026148c) */
/* __stdcall dirTypePrevPtcl(JPABaseParticle *,
                             JPABaseEmitter *,
                             JGeometry::TVec3<float><float>&) */

void dirTypePrevPtcl(int param_1,JPABaseEmitter *param_2,TVec3_float_ *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 in_f29;
  double dVar3;
  undefined8 in_f30;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
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
  dVar5 = (double)*(float *)(param_1 + 0x28);
  dVar4 = (double)*(float *)(param_1 + 0x2c);
  dVar3 = (double)*(float *)(param_1 + 0x30);
  if (*(int **)(param_1 + 8) == (int *)0x0) {
    JPABaseEmitter::calcEmitterGlobalPosition(param_2,param_3);
  }
  else {
    iVar1 = **(int **)(param_1 + 8);
    param_3->x = *(float *)(iVar1 + 0x28);
    param_3->y = *(float *)(iVar1 + 0x2c);
    param_3->z = *(float *)(iVar1 + 0x30);
  }
  param_3->x = (float)((double)param_3->x - dVar5);
  param_3->y = (float)((double)param_3->y - dVar4);
  param_3->z = (float)((double)param_3->z - dVar3);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  return;
}


/* __stdcall rotTypeY(float,
                      float,
                      float &[][][]) */

void rotTypeY(double param_1,double param_2,float *param_3)

{
  float fVar1;
  
  *param_3 = (float)param_2;
  fVar1 = _2524;
  param_3[1] = _2524;
  param_3[2] = (float)-param_1;
  param_3[3] = fVar1;
  param_3[4] = fVar1;
  param_3[5] = _2525;
  param_3[6] = fVar1;
  param_3[7] = fVar1;
  param_3[8] = (float)param_1;
  param_3[9] = fVar1;
  param_3[10] = (float)param_2;
  param_3[0xb] = fVar1;
  return;
}


/* __stdcall rotTypeX(float,
                      float,
                      float &[][][]) */

void rotTypeX(double param_1,double param_2,float *param_3)

{
  float fVar1;
  
  *param_3 = _2525;
  fVar1 = _2524;
  param_3[1] = _2524;
  param_3[2] = fVar1;
  param_3[3] = fVar1;
  param_3[4] = fVar1;
  param_3[5] = (float)param_2;
  param_3[6] = (float)-param_1;
  param_3[7] = fVar1;
  param_3[8] = fVar1;
  param_3[9] = (float)param_1;
  param_3[10] = (float)param_2;
  param_3[0xb] = fVar1;
  return;
}


/* __stdcall rotTypeZ(float,
                      float,
                      float &[][][]) */

void rotTypeZ(double param_1,double param_2,float *param_3)

{
  float fVar1;
  
  *param_3 = (float)param_2;
  param_3[1] = (float)-param_1;
  fVar1 = _2524;
  param_3[2] = _2524;
  param_3[3] = fVar1;
  param_3[4] = (float)param_1;
  param_3[5] = (float)param_2;
  param_3[6] = fVar1;
  param_3[7] = fVar1;
  param_3[8] = fVar1;
  param_3[9] = fVar1;
  param_3[10] = _2525;
  param_3[0xb] = fVar1;
  return;
}


/* __stdcall rotTypeXYZ(float,
                        float,
                        float &[][][]) */

void rotTypeXYZ(double param_1,double param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  
  dVar5 = (double)(_3182 * (float)((double)_2525 - param_2));
  fVar1 = (float)(dVar5 + (double)(float)((double)_3183 * param_1));
  fVar3 = (float)(dVar5 - (double)(float)((double)_3183 * param_1));
  fVar2 = (float)(dVar5 + param_2);
  *param_3 = fVar2;
  param_3[1] = fVar3;
  param_3[2] = fVar1;
  fVar4 = _2524;
  param_3[3] = _2524;
  param_3[4] = fVar1;
  param_3[5] = fVar2;
  param_3[6] = fVar3;
  param_3[7] = fVar4;
  param_3[8] = fVar3;
  param_3[9] = fVar1;
  param_3[10] = fVar2;
  param_3[0xb] = fVar4;
  return;
}


/* __stdcall rotTypeYJiggle(float,
                            float,
                            float &[][][]) */

void rotTypeYJiggle(double param_1,double param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  double dVar3;
  double dVar4;
  
  *param_3 = (float)param_2;
  dVar4 = (double)_3189;
  param_3[1] = (float)(dVar4 * -param_1);
  fVar2 = _3190;
  dVar3 = (double)_3190;
  param_3[2] = (float)(dVar3 * -param_1);
  fVar1 = _2524;
  param_3[3] = _2524;
  param_3[4] = fVar1;
  param_3[5] = fVar2;
  param_3[6] = _3191;
  param_3[7] = fVar1;
  param_3[8] = (float)param_1;
  param_3[9] = (float)(dVar4 * param_2);
  param_3[10] = (float)(dVar3 * param_2);
  param_3[0xb] = fVar1;
  return;
}


/* __stdcall basePlaneTypeXY(float,
                             float,
                             float,
                             float,
                             JGeometry::TVec3<float><float> *) */

void basePlaneTypeXY
               (double param_1,double param_2,double param_3,double param_4,float *param_5)

{
  float fVar1;
  
  *param_5 = (float)param_1;
  param_5[1] = (float)param_3;
  fVar1 = _2524;
  param_5[2] = _2524;
  param_5[3] = (float)param_2;
  param_5[4] = (float)param_3;
  param_5[5] = fVar1;
  param_5[6] = (float)param_2;
  param_5[7] = (float)param_4;
  param_5[8] = fVar1;
  param_5[9] = (float)param_1;
  param_5[10] = (float)param_4;
  param_5[0xb] = fVar1;
  return;
}


/* __stdcall basePlaneTypeXZ(float,
                             float,
                             float,
                             float,
                             JGeometry::TVec3<float><float> *) */

void basePlaneTypeXZ
               (double param_1,double param_2,double param_3,double param_4,cXyz *param_5)

{
  float fVar1;
  
  param_5->x = (float)param_1;
  fVar1 = _2524;
  param_5->y = _2524;
  param_5->z = (float)param_4;
  param_5[1].x = (float)param_2;
  param_5[1].y = fVar1;
  param_5[1].z = (float)param_4;
  param_5[2].x = (float)param_2;
  param_5[2].y = fVar1;
  param_5[2].z = (float)param_3;
  param_5[3].x = (float)param_1;
  param_5[3].y = fVar1;
  param_5[3].z = (float)param_3;
  return;
}

}

/* WARNING: Removing unreachable block (ram,0x80261aa8) */
/* WARNING: Removing unreachable block (ram,0x80261aa0) */
/* WARNING: Removing unreachable block (ram,0x80261ab0) */
/* __thiscall JPADrawExecDirectional::exec(JPADrawContext const *,
                                           JPABaseParticle *) */

JPADrawExecDirectional * __thiscall
JPADrawExecDirectional::exec
          (JPADrawExecDirectional *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  undefined8 in_f29;
  double dVar5;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if ((param_2->mFlags & 8) == 0) {
    (*(code *)JPADrawContext::pcb->mpBasePlaneTypeFunc)
              ((double)(-param_2->mScaleX *
                       (JPADrawContext::pcb->mGlobalScale2D[0] + JPADrawContext::pcb->mPivotX)),
               (double)(param_2->mScaleX *
                       (JPADrawContext::pcb->mGlobalScale2D[0] - JPADrawContext::pcb->mPivotX)),
               (double)(param_2->mScaleY *
                       (JPADrawContext::pcb->mGlobalScale2D[1] + JPADrawContext::pcb->mPivotY)),
               (double)(-param_2->mScaleY *
                       (JPADrawContext::pcb->mGlobalScale2D[1] - JPADrawContext::pcb->mPivotY)),
               &local_6c);
    this = (JPADrawExecDirectional *)
           (*(code *)JPADrawContext::pcb->mpDirTypeFunc)(param_2,param_1->mpBaseEmitter,&local_a8);
    fVar1 = local_a0 * local_a0 + local_a8 * local_a8 + local_a4 * local_a4;
    if (JPADraw::_3358 < fVar1) {
      if (JPADraw::_3358 < fVar1) {
        if (JPADraw::_2524 < fVar1) {
          fVar2 = 1.0 / SQRT(fVar1);
          fVar1 = JPADraw::_2504 * fVar2 * (JPADraw::_3359 - fVar1 * fVar2 * fVar2);
        }
        local_a8 = local_a8 * fVar1;
        local_a4 = local_a4 * fVar1;
        local_a0 = local_a0 * fVar1;
      }
      fVar1 = (param_2->mAxis).y;
      fVar2 = (param_2->mAxis).z;
      local_94 = fVar1 * local_a0 - fVar2 * local_a4;
      fVar3 = (param_2->mAxis).x;
      local_84 = fVar2 * local_a8 - fVar3 * local_a0;
      local_74 = fVar3 * local_a4 - fVar1 * local_a8;
      fVar1 = local_74 * local_74 + local_94 * local_94 + local_84 * local_84;
      if (JPADraw::_3358 < fVar1) {
        if (JPADraw::_3358 < fVar1) {
          if (JPADraw::_2524 < fVar1) {
            fVar2 = 1.0 / SQRT(fVar1);
            fVar1 = JPADraw::_2504 * fVar2 * (JPADraw::_3359 - fVar1 * fVar2 * fVar2);
          }
          local_94 = local_94 * fVar1;
          local_84 = local_84 * fVar1;
          local_74 = local_74 * fVar1;
        }
        (param_2->mAxis).x = local_a4 * local_74 - local_a0 * local_84;
        (param_2->mAxis).y = local_a0 * local_94 - local_a8 * local_74;
        (param_2->mAxis).z = local_a8 * local_84 - local_a4 * local_94;
        fVar1 = (param_2->mAxis).z;
        fVar2 = (param_2->mAxis).x;
        fVar3 = (param_2->mAxis).y;
        fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
        if (JPADraw::_3358 < fVar1) {
          if (JPADraw::_2524 < fVar1) {
            fVar2 = 1.0 / SQRT(fVar1);
            fVar1 = JPADraw::_2504 * fVar2 * (JPADraw::_3359 - fVar1 * fVar2 * fVar2);
          }
          (param_2->mAxis).x = (param_2->mAxis).x * fVar1;
          (param_2->mAxis).y = (param_2->mAxis).y * fVar1;
          (param_2->mAxis).z = (param_2->mAxis).z * fVar1;
        }
        local_9c = (param_2->mAxis).x;
        local_98 = local_a8;
        local_90 = JPADraw::_2524;
        local_8c = (param_2->mAxis).y;
        local_88 = local_a4;
        local_80 = JPADraw::_2524;
        local_7c = (param_2->mAxis).z;
        local_78 = local_a0;
        local_70 = JPADraw::_2524;
        mtx::PSMTXMultVecArray(&local_9c,&local_6c,&local_6c,4);
        dVar7 = (double)(param_2->mPosition).x;
        dVar6 = (double)(param_2->mPosition).y;
        dVar5 = (double)(param_2->mPosition).z;
        gx::GXBegin(0x80,0,4);
        this = (JPADrawExecDirectional *)0xcc010000;
        write_volatile_4(0xcc008000,(float)((double)local_6c + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_68 + dVar6));
        write_volatile_4(0xcc008000,(float)((double)local_64 + dVar5));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].y);
        write_volatile_4(0xcc008000,(float)((double)local_60 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_5c + dVar6));
        write_volatile_4(0xcc008000,(float)((double)local_58 + dVar5));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].y);
        write_volatile_4(0xcc008000,(float)((double)local_54 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_50 + dVar6));
        write_volatile_4(0xcc008000,(float)((double)local_4c + dVar5));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].y);
        write_volatile_4(0xcc008000,(float)((double)local_48 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_44 + dVar6));
        write_volatile_4(0xcc008000,(float)((double)local_40 + dVar5));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].y);
      }
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  return this;
}


/* WARNING: Removing unreachable block (ram,0x80261f38) */
/* WARNING: Removing unreachable block (ram,0x80261f30) */
/* WARNING: Removing unreachable block (ram,0x80261f40) */
/* __thiscall JPADrawExecRotDirectional::exec(JPADrawContext const *,
                                              JPABaseParticle *) */

JPADrawExecRotDirectional * __thiscall
JPADrawExecRotDirectional::exec
          (JPADrawExecRotDirectional *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f29;
  double dVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  float local_108;
  float local_104;
  float local_100;
  MTX34 MStack252;
  MTX34 local_cc;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  MTX34 MStack108;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if ((param_2->mFlags & 8) == 0) {
    iVar4 = (int)(uint)(ushort)param_2->mRotateAngle >> (JKernel::JMath::jmaSinShift & 0x3f);
    dVar6 = (double)JKernel::JMath::jmaSinTable[iVar4];
    dVar7 = (double)JKernel::JMath::jmaCosTable[iVar4];
    (*(code *)JPADrawContext::pcb->mpBasePlaneTypeFunc)
              ((double)(-param_2->mScaleX *
                       (JPADrawContext::pcb->mGlobalScale2D[0] + JPADrawContext::pcb->mPivotX)),
               (double)(param_2->mScaleX *
                       (JPADrawContext::pcb->mGlobalScale2D[0] - JPADrawContext::pcb->mPivotX)),
               (double)(param_2->mScaleY *
                       (JPADrawContext::pcb->mGlobalScale2D[1] + JPADrawContext::pcb->mPivotY)),
               (double)(-param_2->mScaleY *
                       (JPADrawContext::pcb->mGlobalScale2D[1] - JPADrawContext::pcb->mPivotY)),
               &local_9c);
    (*(code *)JPADrawContext::pcb->mpRotTypeFunc)(dVar6,dVar7,&MStack108);
    this = (JPADrawExecRotDirectional *)
           (*(code *)JPADrawContext::pcb->mpDirTypeFunc)(param_2,param_1->mpBaseEmitter,&local_108);
    fVar1 = local_100 * local_100 + local_108 * local_108 + local_104 * local_104;
    if (JPADraw::_3358 < fVar1) {
      if (JPADraw::_3358 < fVar1) {
        if (JPADraw::_2524 < fVar1) {
          fVar2 = 1.0 / SQRT(fVar1);
          fVar1 = JPADraw::_2504 * fVar2 * (JPADraw::_3359 - fVar1 * fVar2 * fVar2);
        }
        local_108 = local_108 * fVar1;
        local_104 = local_104 * fVar1;
        local_100 = local_100 * fVar1;
      }
      fVar1 = (param_2->mAxis).y;
      fVar2 = (param_2->mAxis).z;
      local_cc.m[0][2] = fVar1 * local_100 - fVar2 * local_104;
      fVar3 = (param_2->mAxis).x;
      local_cc.m[1][2] = fVar2 * local_108 - fVar3 * local_100;
      local_cc.m[2][2] = fVar3 * local_104 - fVar1 * local_108;
      fVar1 = local_cc.m[2][2] * local_cc.m[2][2] +
              local_cc.m[0][2] * local_cc.m[0][2] + local_cc.m[1][2] * local_cc.m[1][2];
      if (JPADraw::_3358 < fVar1) {
        if (JPADraw::_3358 < fVar1) {
          if (JPADraw::_2524 < fVar1) {
            fVar2 = 1.0 / SQRT(fVar1);
            fVar1 = JPADraw::_2504 * fVar2 * (JPADraw::_3359 - fVar1 * fVar2 * fVar2);
          }
          local_cc.m[0][2] = local_cc.m[0][2] * fVar1;
          local_cc.m[1][2] = local_cc.m[1][2] * fVar1;
          local_cc.m[2][2] = local_cc.m[2][2] * fVar1;
        }
        (param_2->mAxis).x = local_104 * local_cc.m[2][2] - local_100 * local_cc.m[1][2];
        (param_2->mAxis).y = local_100 * local_cc.m[0][2] - local_108 * local_cc.m[2][2];
        (param_2->mAxis).z = local_108 * local_cc.m[1][2] - local_104 * local_cc.m[0][2];
        fVar1 = (param_2->mAxis).z;
        fVar2 = (param_2->mAxis).x;
        fVar3 = (param_2->mAxis).y;
        fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
        if (JPADraw::_3358 < fVar1) {
          if (JPADraw::_2524 < fVar1) {
            fVar2 = 1.0 / SQRT(fVar1);
            fVar1 = JPADraw::_2504 * fVar2 * (JPADraw::_3359 - fVar1 * fVar2 * fVar2);
          }
          (param_2->mAxis).x = (param_2->mAxis).x * fVar1;
          (param_2->mAxis).y = (param_2->mAxis).y * fVar1;
          (param_2->mAxis).z = (param_2->mAxis).z * fVar1;
        }
        local_cc.m[0][0] = (param_2->mAxis).x;
        local_cc.m[0][1] = local_108;
        local_cc.m[0][3] = JPADraw::_2524;
        local_cc.m[1][0] = (param_2->mAxis).y;
        local_cc.m[1][1] = local_104;
        local_cc.m[1][3] = JPADraw::_2524;
        local_cc.m[2][0] = (param_2->mAxis).z;
        local_cc.m[2][1] = local_100;
        local_cc.m[2][3] = JPADraw::_2524;
        mtx::PSMTXConcat(&local_cc,&MStack108,&MStack252);
        mtx::PSMTXMultVecArray(&MStack252,&local_9c,&local_9c,4);
        dVar8 = (double)(param_2->mPosition).x;
        dVar7 = (double)(param_2->mPosition).y;
        dVar6 = (double)(param_2->mPosition).z;
        gx::GXBegin(0x80,0,4);
        this = (JPADrawExecRotDirectional *)0xcc010000;
        write_volatile_4(0xcc008000,(float)((double)local_9c + dVar8));
        write_volatile_4(0xcc008000,(float)((double)local_98 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_94 + dVar6));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].y);
        write_volatile_4(0xcc008000,(float)((double)local_90 + dVar8));
        write_volatile_4(0xcc008000,(float)((double)local_8c + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_88 + dVar6));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].y);
        write_volatile_4(0xcc008000,(float)((double)local_84 + dVar8));
        write_volatile_4(0xcc008000,(float)((double)local_80 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_7c + dVar6));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].y);
        write_volatile_4(0xcc008000,(float)((double)local_78 + dVar8));
        write_volatile_4(0xcc008000,(float)((double)local_74 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_70 + dVar6));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].y);
      }
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  return this;
}


/* WARNING: Removing unreachable block (ram,0x802624b0) */
/* WARNING: Removing unreachable block (ram,0x802624a8) */
/* WARNING: Removing unreachable block (ram,0x802624b8) */
/* __thiscall JPADrawExecDirectionalCross::exec(JPADrawContext const *,
                                                JPABaseParticle *) */

JPADrawExecDirectionalCross * __thiscall
JPADrawExecDirectionalCross::exec
          (JPADrawExecDirectionalCross *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  undefined8 in_f29;
  double dVar5;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if ((param_2->mFlags & 8) == 0) {
    local_9c = -param_2->mScaleX *
               (JPADrawContext::pcb->mGlobalScale2D[0] + JPADrawContext::pcb->mPivotX);
    local_98 = param_2->mScaleY *
               (JPADrawContext::pcb->mGlobalScale2D[1] + JPADrawContext::pcb->mPivotY);
    local_90 = param_2->mScaleX *
               (JPADrawContext::pcb->mGlobalScale2D[0] - JPADrawContext::pcb->mPivotX);
    local_80 = -param_2->mScaleY *
               (JPADrawContext::pcb->mGlobalScale2D[1] - JPADrawContext::pcb->mPivotY);
    local_94 = JPADraw::_2524;
    local_88 = JPADraw::_2524;
    local_7c = JPADraw::_2524;
    local_70 = JPADraw::_2524;
    local_64 = JPADraw::_2504 * (local_90 - local_9c);
    local_6c = JPADraw::_2504 * (local_90 + local_9c);
    local_58 = JPADraw::_2504 * (local_9c - local_90);
    local_8c = local_98;
    local_84 = local_90;
    local_78 = local_9c;
    local_74 = local_80;
    local_68 = local_98;
    local_60 = local_6c;
    local_5c = local_98;
    local_54 = local_6c;
    local_50 = local_80;
    local_4c = local_58;
    local_48 = local_6c;
    local_44 = local_80;
    local_40 = local_64;
    this = (JPADrawExecDirectionalCross *)
           (*(code *)JPADrawContext::pcb->mpDirTypeFunc)(param_2,param_1->mpBaseEmitter,&local_d8);
    fVar1 = local_d0 * local_d0 + local_d8 * local_d8 + local_d4 * local_d4;
    if (JPADraw::_3358 < fVar1) {
      if (JPADraw::_3358 < fVar1) {
        if (JPADraw::_2524 < fVar1) {
          fVar2 = 1.0 / SQRT(fVar1);
          fVar1 = JPADraw::_2504 * fVar2 * (JPADraw::_3359 - fVar1 * fVar2 * fVar2);
        }
        local_d8 = local_d8 * fVar1;
        local_d4 = local_d4 * fVar1;
        local_d0 = local_d0 * fVar1;
      }
      fVar1 = (param_2->mAxis).y;
      fVar2 = (param_2->mAxis).z;
      local_c4 = fVar1 * local_d0 - fVar2 * local_d4;
      fVar3 = (param_2->mAxis).x;
      local_b4 = fVar2 * local_d8 - fVar3 * local_d0;
      local_a4 = fVar3 * local_d4 - fVar1 * local_d8;
      fVar1 = local_a4 * local_a4 + local_c4 * local_c4 + local_b4 * local_b4;
      if (JPADraw::_3358 < fVar1) {
        if (JPADraw::_3358 < fVar1) {
          if (JPADraw::_2524 < fVar1) {
            fVar2 = 1.0 / SQRT(fVar1);
            fVar1 = JPADraw::_2504 * fVar2 * (JPADraw::_3359 - fVar1 * fVar2 * fVar2);
          }
          local_c4 = local_c4 * fVar1;
          local_b4 = local_b4 * fVar1;
          local_a4 = local_a4 * fVar1;
        }
        (param_2->mAxis).x = local_d4 * local_a4 - local_d0 * local_b4;
        (param_2->mAxis).y = local_d0 * local_c4 - local_d8 * local_a4;
        (param_2->mAxis).z = local_d8 * local_b4 - local_d4 * local_c4;
        fVar1 = (param_2->mAxis).z;
        fVar2 = (param_2->mAxis).x;
        fVar3 = (param_2->mAxis).y;
        fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
        if (JPADraw::_3358 < fVar1) {
          if (JPADraw::_2524 < fVar1) {
            fVar2 = 1.0 / SQRT(fVar1);
            fVar1 = JPADraw::_2504 * fVar2 * (JPADraw::_3359 - fVar1 * fVar2 * fVar2);
          }
          (param_2->mAxis).x = (param_2->mAxis).x * fVar1;
          (param_2->mAxis).y = (param_2->mAxis).y * fVar1;
          (param_2->mAxis).z = (param_2->mAxis).z * fVar1;
        }
        local_cc = (param_2->mAxis).x;
        local_c8 = local_d8;
        local_c0 = JPADraw::_2524;
        local_bc = (param_2->mAxis).y;
        local_b8 = local_d4;
        local_b0 = JPADraw::_2524;
        local_ac = (param_2->mAxis).z;
        local_a8 = local_d0;
        local_a0 = JPADraw::_2524;
        mtx::PSMTXMultVecArray(&local_cc,&local_9c,&local_9c,8);
        dVar7 = (double)(param_2->mPosition).x;
        dVar6 = (double)(param_2->mPosition).y;
        dVar5 = (double)(param_2->mPosition).z;
        gx::GXBegin(0x80,0,8);
        this = (JPADrawExecDirectionalCross *)0xcc010000;
        write_volatile_4(0xcc008000,(float)((double)local_9c + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_98 + dVar6));
        write_volatile_4(0xcc008000,(float)((double)local_94 + dVar5));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].y);
        write_volatile_4(0xcc008000,(float)((double)local_90 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_8c + dVar6));
        write_volatile_4(0xcc008000,(float)((double)local_88 + dVar5));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].y);
        write_volatile_4(0xcc008000,(float)((double)local_84 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_80 + dVar6));
        write_volatile_4(0xcc008000,(float)((double)local_7c + dVar5));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].y);
        write_volatile_4(0xcc008000,(float)((double)local_78 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_74 + dVar6));
        write_volatile_4(0xcc008000,(float)((double)local_70 + dVar5));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].y);
        write_volatile_4(0xcc008000,(float)((double)local_6c + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_68 + dVar6));
        write_volatile_4(0xcc008000,(float)((double)local_64 + dVar5));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].y);
        write_volatile_4(0xcc008000,(float)((double)local_60 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_5c + dVar6));
        write_volatile_4(0xcc008000,(float)((double)local_58 + dVar5));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].y);
        write_volatile_4(0xcc008000,(float)((double)local_54 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_50 + dVar6));
        write_volatile_4(0xcc008000,(float)((double)local_4c + dVar5));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].y);
        write_volatile_4(0xcc008000,(float)((double)local_48 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_44 + dVar6));
        write_volatile_4(0xcc008000,(float)((double)local_40 + dVar5));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].y);
      }
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  return this;
}


/* WARNING: Removing unreachable block (ram,0x80262a70) */
/* WARNING: Removing unreachable block (ram,0x80262a68) */
/* WARNING: Removing unreachable block (ram,0x80262a78) */
/* __thiscall JPADrawExecRotDirectionalCross::exec(JPADrawContext const *,
                                                   JPABaseParticle *) */

JPADrawExecRotDirectionalCross * __thiscall
JPADrawExecRotDirectionalCross::exec
          (JPADrawExecRotDirectionalCross *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f29;
  double dVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  float local_138;
  float local_134;
  float local_130;
  MTX34 MStack300;
  MTX34 local_fc;
  MTX34 MStack204;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if ((param_2->mFlags & 8) == 0) {
    iVar4 = (int)(uint)(ushort)param_2->mRotateAngle >> (JKernel::JMath::jmaSinShift & 0x3f);
    local_9c = -param_2->mScaleX *
               (JPADrawContext::pcb->mGlobalScale2D[0] + JPADrawContext::pcb->mPivotX);
    local_98 = param_2->mScaleY *
               (JPADrawContext::pcb->mGlobalScale2D[1] + JPADrawContext::pcb->mPivotY);
    local_90 = param_2->mScaleX *
               (JPADrawContext::pcb->mGlobalScale2D[0] - JPADrawContext::pcb->mPivotX);
    local_80 = -param_2->mScaleY *
               (JPADrawContext::pcb->mGlobalScale2D[1] - JPADrawContext::pcb->mPivotY);
    local_94 = JPADraw::_2524;
    local_88 = JPADraw::_2524;
    local_7c = JPADraw::_2524;
    local_70 = JPADraw::_2524;
    local_64 = JPADraw::_2504 * (local_90 - local_9c);
    local_6c = JPADraw::_2504 * (local_90 + local_9c);
    local_58 = JPADraw::_2504 * (local_9c - local_90);
    local_8c = local_98;
    local_84 = local_90;
    local_78 = local_9c;
    local_74 = local_80;
    local_68 = local_98;
    local_60 = local_6c;
    local_5c = local_98;
    local_54 = local_6c;
    local_50 = local_80;
    local_4c = local_58;
    local_48 = local_6c;
    local_44 = local_80;
    local_40 = local_64;
    (*(code *)JPADrawContext::pcb->mpRotTypeFunc)
              ((double)JKernel::JMath::jmaSinTable[iVar4],(double)JKernel::JMath::jmaCosTable[iVar4]
               ,&MStack204);
    this = (JPADrawExecRotDirectionalCross *)
           (*(code *)JPADrawContext::pcb->mpDirTypeFunc)(param_2,param_1->mpBaseEmitter,&local_138);
    fVar1 = local_130 * local_130 + local_138 * local_138 + local_134 * local_134;
    if (JPADraw::_3358 < fVar1) {
      if (JPADraw::_3358 < fVar1) {
        if (JPADraw::_2524 < fVar1) {
          fVar2 = 1.0 / SQRT(fVar1);
          fVar1 = JPADraw::_2504 * fVar2 * (JPADraw::_3359 - fVar1 * fVar2 * fVar2);
        }
        local_138 = local_138 * fVar1;
        local_134 = local_134 * fVar1;
        local_130 = local_130 * fVar1;
      }
      fVar1 = (param_2->mAxis).y;
      fVar2 = (param_2->mAxis).z;
      local_fc.m[0][2] = fVar1 * local_130 - fVar2 * local_134;
      fVar3 = (param_2->mAxis).x;
      local_fc.m[1][2] = fVar2 * local_138 - fVar3 * local_130;
      local_fc.m[2][2] = fVar3 * local_134 - fVar1 * local_138;
      fVar1 = local_fc.m[2][2] * local_fc.m[2][2] +
              local_fc.m[0][2] * local_fc.m[0][2] + local_fc.m[1][2] * local_fc.m[1][2];
      if (JPADraw::_3358 < fVar1) {
        if (JPADraw::_3358 < fVar1) {
          if (JPADraw::_2524 < fVar1) {
            fVar2 = 1.0 / SQRT(fVar1);
            fVar1 = JPADraw::_2504 * fVar2 * (JPADraw::_3359 - fVar1 * fVar2 * fVar2);
          }
          local_fc.m[0][2] = local_fc.m[0][2] * fVar1;
          local_fc.m[1][2] = local_fc.m[1][2] * fVar1;
          local_fc.m[2][2] = local_fc.m[2][2] * fVar1;
        }
        (param_2->mAxis).x = local_134 * local_fc.m[2][2] - local_130 * local_fc.m[1][2];
        (param_2->mAxis).y = local_130 * local_fc.m[0][2] - local_138 * local_fc.m[2][2];
        (param_2->mAxis).z = local_138 * local_fc.m[1][2] - local_134 * local_fc.m[0][2];
        fVar1 = (param_2->mAxis).z;
        fVar2 = (param_2->mAxis).x;
        fVar3 = (param_2->mAxis).y;
        fVar1 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
        if (JPADraw::_3358 < fVar1) {
          if (JPADraw::_2524 < fVar1) {
            fVar2 = 1.0 / SQRT(fVar1);
            fVar1 = JPADraw::_2504 * fVar2 * (JPADraw::_3359 - fVar1 * fVar2 * fVar2);
          }
          (param_2->mAxis).x = (param_2->mAxis).x * fVar1;
          (param_2->mAxis).y = (param_2->mAxis).y * fVar1;
          (param_2->mAxis).z = (param_2->mAxis).z * fVar1;
        }
        local_fc.m[0][0] = (param_2->mAxis).x;
        local_fc.m[0][1] = local_138;
        local_fc.m[0][3] = JPADraw::_2524;
        local_fc.m[1][0] = (param_2->mAxis).y;
        local_fc.m[1][1] = local_134;
        local_fc.m[1][3] = JPADraw::_2524;
        local_fc.m[2][0] = (param_2->mAxis).z;
        local_fc.m[2][1] = local_130;
        local_fc.m[2][3] = JPADraw::_2524;
        mtx::PSMTXConcat(&local_fc,&MStack204,&MStack300);
        mtx::PSMTXMultVecArray(&MStack300,&local_9c,&local_9c,8);
        dVar8 = (double)(param_2->mPosition).x;
        dVar7 = (double)(param_2->mPosition).y;
        dVar6 = (double)(param_2->mPosition).z;
        gx::GXBegin(0x80,0,8);
        this = (JPADrawExecRotDirectionalCross *)0xcc010000;
        write_volatile_4(0xcc008000,(float)((double)local_9c + dVar8));
        write_volatile_4(0xcc008000,(float)((double)local_98 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_94 + dVar6));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].y);
        write_volatile_4(0xcc008000,(float)((double)local_90 + dVar8));
        write_volatile_4(0xcc008000,(float)((double)local_8c + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_88 + dVar6));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].y);
        write_volatile_4(0xcc008000,(float)((double)local_84 + dVar8));
        write_volatile_4(0xcc008000,(float)((double)local_80 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_7c + dVar6));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].y);
        write_volatile_4(0xcc008000,(float)((double)local_78 + dVar8));
        write_volatile_4(0xcc008000,(float)((double)local_74 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_70 + dVar6));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].y);
        write_volatile_4(0xcc008000,(float)((double)local_6c + dVar8));
        write_volatile_4(0xcc008000,(float)((double)local_68 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_64 + dVar6));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].y);
        write_volatile_4(0xcc008000,(float)((double)local_60 + dVar8));
        write_volatile_4(0xcc008000,(float)((double)local_5c + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_58 + dVar6));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].y);
        write_volatile_4(0xcc008000,(float)((double)local_54 + dVar8));
        write_volatile_4(0xcc008000,(float)((double)local_50 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_4c + dVar6));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].y);
        write_volatile_4(0xcc008000,(float)((double)local_48 + dVar8));
        write_volatile_4(0xcc008000,(float)((double)local_44 + dVar7));
        write_volatile_4(0xcc008000,(float)((double)local_40 + dVar6));
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].x);
        write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].y);
      }
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  return this;
}


/* WARNING: Removing unreachable block (ram,0x80262d9c) */
/* WARNING: Removing unreachable block (ram,0x80262d8c) */
/* WARNING: Removing unreachable block (ram,0x80262d7c) */
/* WARNING: Removing unreachable block (ram,0x80262d6c) */
/* WARNING: Removing unreachable block (ram,0x80262d74) */
/* WARNING: Removing unreachable block (ram,0x80262d84) */
/* WARNING: Removing unreachable block (ram,0x80262d94) */
/* WARNING: Removing unreachable block (ram,0x80262da4) */
/* __thiscall JPADrawExecDirBillBoard::exec(JPADrawContext const *,
                                            JPABaseParticle *) */

JPADrawExecDirBillBoard * __thiscall
JPADrawExecDirBillBoard::exec
          (JPADrawExecDirBillBoard *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  double dVar9;
  undefined8 in_f24;
  double dVar10;
  undefined8 in_f25;
  double dVar11;
  undefined8 in_f26;
  double dVar12;
  undefined8 in_f27;
  double dVar13;
  undefined8 in_f28;
  double dVar14;
  undefined8 in_f29;
  double dVar15;
  undefined8 in_f30;
  double dVar16;
  undefined8 in_f31;
  double dVar17;
  cXyz local_a8;
  float local_9c;
  float local_98;
  float local_94;
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  if ((param_2->mFlags & 8) == 0) {
    (*(code *)JPADrawContext::pcb->mpDirTypeFunc)(param_2,param_1->mpBaseEmitter,&local_9c);
    this = (JPADrawExecDirBillBoard *)JPADrawContext::pcb->mpViewMtx;
    fVar1 = ((MTX34 *)this)->m[2][0];
    fVar2 = ((MTX34 *)this)->m[2][1];
    fVar3 = ((MTX34 *)this)->m[2][2];
    fVar4 = local_9c * fVar2 - local_98 * fVar1;
    fVar1 = local_94 * fVar1 - local_9c * fVar3;
    local_9c = local_98 * fVar3 - local_94 * fVar2;
    fVar2 = fVar4 * fVar4 + local_9c * local_9c + fVar1 * fVar1;
    if (JPADraw::_3358 < fVar2) {
      local_98 = fVar1;
      local_94 = fVar4;
      if (JPADraw::_3358 < fVar2) {
        if (JPADraw::_2524 < fVar2) {
          fVar3 = 1.0 / SQRT(fVar2);
          fVar2 = JPADraw::_2504 * fVar3 * (JPADraw::_3359 - fVar2 * fVar3 * fVar3);
        }
        local_9c = local_9c * fVar2;
        local_98 = fVar1 * fVar2;
        local_94 = fVar4 * fVar2;
      }
      mtx::PSMTXMultVecSR(JPADrawContext::pcb->mpViewMtx,&local_9c,&local_9c);
      fVar7 = param_2->mScaleX *
              (JPADrawContext::pcb->mGlobalScale2D[0] - JPADrawContext::pcb->mPivotX);
      fVar2 = param_2->mScaleY *
              (JPADrawContext::pcb->mGlobalScale2D[1] + JPADrawContext::pcb->mPivotY);
      fVar6 = -(param_2->mScaleX *
               (JPADrawContext::pcb->mGlobalScale2D[0] + JPADrawContext::pcb->mPivotX));
      fVar4 = -(param_2->mScaleY *
               (JPADrawContext::pcb->mGlobalScale2D[1] - JPADrawContext::pcb->mPivotY));
      fVar5 = local_9c * fVar2;
      fVar1 = local_98 * fVar6;
      dVar17 = (double)(fVar5 + fVar1);
      fVar6 = local_9c * fVar6;
      fVar2 = local_98 * fVar2;
      dVar13 = (double)(fVar6 - fVar2);
      fVar3 = local_98 * fVar7;
      dVar16 = (double)(fVar5 + fVar3);
      fVar7 = local_9c * fVar7;
      dVar12 = (double)(fVar7 - fVar2);
      fVar2 = local_9c * fVar4;
      dVar15 = (double)(fVar2 + fVar3);
      fVar4 = local_98 * fVar4;
      dVar11 = (double)(fVar7 - fVar4);
      dVar14 = (double)(fVar2 + fVar1);
      dVar10 = (double)(fVar6 - fVar4);
      local_a8.x = (param_2->mPosition).x;
      local_a8.y = (param_2->mPosition).y;
      local_a8.z = (param_2->mPosition).z;
      mtx::PSMTXMultVec(JPADrawContext::pcb->mpViewMtx,&local_a8,&local_a8);
      gx::GXBegin(0x80,0,4);
      dVar9 = (double)local_a8.x;
      this = (JPADrawExecDirBillBoard *)0xcc010000;
      write_volatile_4(0xcc008000,(float)(dVar13 + dVar9));
      dVar13 = (double)local_a8.y;
      write_volatile_4(0xcc008000,(float)(dVar17 + dVar13));
      write_volatile_4(0xcc008000,local_a8.z);
      write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].x);
      write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].y);
      write_volatile_4(0xcc008000,(float)(dVar12 + dVar9));
      write_volatile_4(0xcc008000,(float)(dVar16 + dVar13));
      write_volatile_4(0xcc008000,local_a8.z);
      write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].x);
      write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].y);
      write_volatile_4(0xcc008000,(float)(dVar11 + dVar9));
      write_volatile_4(0xcc008000,(float)(dVar15 + dVar13));
      write_volatile_4(0xcc008000,local_a8.z);
      write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].x);
      write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].y);
      write_volatile_4(0xcc008000,(float)(dVar10 + dVar9));
      write_volatile_4(0xcc008000,(float)(dVar14 + dVar13));
      write_volatile_4(0xcc008000,local_a8.z);
      write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].x);
      write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].y);
    }
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  __psq_l0(auStack40,uVar8);
  __psq_l1(auStack40,uVar8);
  __psq_l0(auStack56,uVar8);
  __psq_l1(auStack56,uVar8);
  __psq_l0(auStack72,uVar8);
  __psq_l1(auStack72,uVar8);
  __psq_l0(auStack88,uVar8);
  __psq_l1(auStack88,uVar8);
  __psq_l0(auStack104,uVar8);
  __psq_l1(auStack104,uVar8);
  __psq_l0(auStack120,uVar8);
  __psq_l1(auStack120,uVar8);
  return this;
}


/* WARNING: Removing unreachable block (ram,0x80262f98) */
/* WARNING: Removing unreachable block (ram,0x80262f90) */
/* WARNING: Removing unreachable block (ram,0x80262fa0) */
/* __thiscall JPADrawExecRotation::exec(JPADrawContext const *,
                                        JPABaseParticle *) */

undefined8 __thiscall
JPADrawExecRotation::exec
          (JPADrawExecRotation *this,JPADrawContext *param_1,JPABaseParticle *pParticle)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 in_f29;
  double dVar3;
  undefined8 in_f30;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  undefined auStack104 [52];
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
  if ((pParticle->mFlags & 8) == 0) {
    iVar1 = (int)(uint)(ushort)pParticle->mRotateAngle >> (JKernel::JMath::jmaSinShift & 0x3f);
    dVar3 = (double)JKernel::JMath::jmaSinTable[iVar1];
    dVar4 = (double)JKernel::JMath::jmaCosTable[iVar1];
    (*(code *)JPADrawContext::pcb->mpBasePlaneTypeFunc)
              ((double)(-pParticle->mScaleX *
                       (JPADrawContext::pcb->mGlobalScale2D[0] + JPADrawContext::pcb->mPivotX)),
               (double)(pParticle->mScaleX *
                       (JPADrawContext::pcb->mGlobalScale2D[0] - JPADrawContext::pcb->mPivotX)),
               (double)(pParticle->mScaleY *
                       (JPADrawContext::pcb->mGlobalScale2D[1] + JPADrawContext::pcb->mPivotY)),
               (double)(-pParticle->mScaleY *
                       (JPADrawContext::pcb->mGlobalScale2D[1] - JPADrawContext::pcb->mPivotY)),
               &local_98);
    (*(code *)JPADrawContext::pcb->mpRotTypeFunc)(dVar3,dVar4,auStack104);
    mtx::PSMTXMultVecArray(auStack104,&local_98,&local_98,4);
    dVar5 = (double)(pParticle->mPosition).x;
    dVar4 = (double)(pParticle->mPosition).y;
    dVar3 = (double)(pParticle->mPosition).z;
    gx::GXBegin(0x80,0,4);
    this = (JPADrawExecRotation *)0xcc010000;
    write_volatile_4(0xcc008000,(float)((double)local_98 + dVar5));
    write_volatile_4(0xcc008000,(float)((double)local_94 + dVar4));
    write_volatile_4(0xcc008000,(float)((double)local_90 + dVar3));
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].y);
    write_volatile_4(0xcc008000,(float)((double)local_8c + dVar5));
    write_volatile_4(0xcc008000,(float)((double)local_88 + dVar4));
    write_volatile_4(0xcc008000,(float)((double)local_84 + dVar3));
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].y);
    write_volatile_4(0xcc008000,(float)((double)local_80 + dVar5));
    write_volatile_4(0xcc008000,(float)((double)local_7c + dVar4));
    write_volatile_4(0xcc008000,(float)((double)local_78 + dVar3));
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].y);
    write_volatile_4(0xcc008000,(float)((double)local_74 + dVar5));
    write_volatile_4(0xcc008000,(float)((double)local_70 + dVar4));
    write_volatile_4(0xcc008000,(float)((double)local_6c + dVar3));
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].y);
    param_1 = (JPADrawContext *)JPADrawContext::pcb;
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  return CONCAT44(this,param_1);
}


/* WARNING: Removing unreachable block (ram,0x802632c8) */
/* WARNING: Removing unreachable block (ram,0x802632c0) */
/* WARNING: Removing unreachable block (ram,0x802632d0) */
/* __thiscall JPADrawExecRotationCross::exec(JPADrawContext const *,
                                             JPABaseParticle *) */

undefined8 __thiscall
JPADrawExecRotationCross::exec
          (JPADrawExecRotationCross *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 in_f29;
  double dVar3;
  undefined8 in_f30;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack200 [48];
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
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
  if ((param_2->mFlags & 8) == 0) {
    iVar1 = (int)(uint)(ushort)param_2->mRotateAngle >> (JKernel::JMath::jmaSinShift & 0x3f);
    local_98 = -param_2->mScaleX *
               (JPADrawContext::pcb->mGlobalScale2D[0] + JPADrawContext::pcb->mPivotX);
    local_94 = param_2->mScaleY *
               (JPADrawContext::pcb->mGlobalScale2D[1] + JPADrawContext::pcb->mPivotY);
    local_8c = param_2->mScaleX *
               (JPADrawContext::pcb->mGlobalScale2D[0] - JPADrawContext::pcb->mPivotX);
    local_7c = -param_2->mScaleY *
               (JPADrawContext::pcb->mGlobalScale2D[1] - JPADrawContext::pcb->mPivotY);
    local_90 = JPADraw::_2524;
    local_84 = JPADraw::_2524;
    local_78 = JPADraw::_2524;
    local_6c = JPADraw::_2524;
    local_60 = JPADraw::_2504 * (local_8c - local_98);
    local_68 = JPADraw::_2504 * (local_8c + local_98);
    local_54 = JPADraw::_2504 * (local_98 - local_8c);
    local_88 = local_94;
    local_80 = local_8c;
    local_74 = local_98;
    local_70 = local_7c;
    local_64 = local_94;
    local_5c = local_68;
    local_58 = local_94;
    local_50 = local_68;
    local_4c = local_7c;
    local_48 = local_54;
    local_44 = local_68;
    local_40 = local_7c;
    local_3c = local_60;
    (*(code *)JPADrawContext::pcb->mpRotTypeFunc)
              ((double)JKernel::JMath::jmaSinTable[iVar1],(double)JKernel::JMath::jmaCosTable[iVar1]
               ,auStack200);
    mtx::PSMTXMultVecArray(auStack200,&local_98,&local_98,8);
    dVar5 = (double)(param_2->mPosition).x;
    dVar4 = (double)(param_2->mPosition).y;
    dVar3 = (double)(param_2->mPosition).z;
    gx::GXBegin(0x80,0,8);
    this = (JPADrawExecRotationCross *)0xcc010000;
    write_volatile_4(0xcc008000,(float)((double)local_98 + dVar5));
    write_volatile_4(0xcc008000,(float)((double)local_94 + dVar4));
    write_volatile_4(0xcc008000,(float)((double)local_90 + dVar3));
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].y);
    write_volatile_4(0xcc008000,(float)((double)local_8c + dVar5));
    write_volatile_4(0xcc008000,(float)((double)local_88 + dVar4));
    write_volatile_4(0xcc008000,(float)((double)local_84 + dVar3));
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].y);
    write_volatile_4(0xcc008000,(float)((double)local_80 + dVar5));
    write_volatile_4(0xcc008000,(float)((double)local_7c + dVar4));
    write_volatile_4(0xcc008000,(float)((double)local_78 + dVar3));
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].y);
    write_volatile_4(0xcc008000,(float)((double)local_74 + dVar5));
    write_volatile_4(0xcc008000,(float)((double)local_70 + dVar4));
    write_volatile_4(0xcc008000,(float)((double)local_6c + dVar3));
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].y);
    write_volatile_4(0xcc008000,(float)((double)local_68 + dVar5));
    write_volatile_4(0xcc008000,(float)((double)local_64 + dVar4));
    write_volatile_4(0xcc008000,(float)((double)local_60 + dVar3));
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[0].y);
    write_volatile_4(0xcc008000,(float)((double)local_5c + dVar5));
    write_volatile_4(0xcc008000,(float)((double)local_58 + dVar4));
    write_volatile_4(0xcc008000,(float)((double)local_54 + dVar3));
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[1].y);
    write_volatile_4(0xcc008000,(float)((double)local_50 + dVar5));
    write_volatile_4(0xcc008000,(float)((double)local_4c + dVar4));
    write_volatile_4(0xcc008000,(float)((double)local_48 + dVar3));
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[2].y);
    write_volatile_4(0xcc008000,(float)((double)local_44 + dVar5));
    write_volatile_4(0xcc008000,(float)((double)local_40 + dVar4));
    write_volatile_4(0xcc008000,(float)((double)local_3c + dVar3));
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].x);
    write_volatile_4(0xcc008000,JPADrawContext::pcb->mTexCoordPoints[3].y);
    param_1 = (JPADrawContext *)JPADrawContext::pcb;
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  return CONCAT44(this,param_1);
}


/* WARNING: Removing unreachable block (ram,0x80263360) */
/* WARNING: Removing unreachable block (ram,0x80263358) */
/* WARNING: Removing unreachable block (ram,0x80263368) */
/* __thiscall JPADrawExecPoint::exec(JPADrawContext const *,
                                     JPABaseParticle *) */

JPADrawExecPoint * __thiscall
JPADrawExecPoint::exec(JPADrawExecPoint *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  undefined4 uVar1;
  undefined8 in_f29;
  double dVar2;
  undefined8 in_f30;
  double dVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if ((param_2->mFlags & 8) == 0) {
    dVar4 = (double)(param_2->mPosition).x;
    dVar3 = (double)(param_2->mPosition).y;
    dVar2 = (double)(param_2->mPosition).z;
    gx::GXBegin(0xb8,0,1);
    this = (JPADrawExecPoint *)0xcc010000;
    write_volatile_4(0xcc008000,(float)dVar4);
    write_volatile_4(0xcc008000,(float)dVar3);
    write_volatile_4(0xcc008000,(float)dVar2);
    write_volatile_4(0xcc008000,JPADraw::_2524);
    write_volatile_4(0xcc008000,JPADraw::_2524);
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  __psq_l0(auStack40,uVar1);
  __psq_l1(auStack40,uVar1);
  return this;
}


/* WARNING: Removing unreachable block (ram,0x802634e8) */
/* WARNING: Removing unreachable block (ram,0x802634d8) */
/* WARNING: Removing unreachable block (ram,0x802634c8) */
/* WARNING: Removing unreachable block (ram,0x802634d0) */
/* WARNING: Removing unreachable block (ram,0x802634e0) */
/* WARNING: Removing unreachable block (ram,0x802634f0) */
/* __thiscall JPADrawExecLine::exec(JPADrawContext const *,
                                    JPABaseParticle *) */

JPADrawExecLine * __thiscall
JPADrawExecLine::exec(JPADrawExecLine *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  undefined8 in_f26;
  double dVar7;
  undefined8 in_f27;
  double dVar8;
  undefined8 in_f28;
  double dVar9;
  undefined8 in_f29;
  double dVar10;
  undefined8 in_f30;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  if ((param_2->mFlags & 8) == 0) {
    dVar12 = (double)(param_2->mPosition).x;
    dVar11 = (double)(param_2->mPosition).y;
    dVar10 = (double)(param_2->mPosition).z;
    fVar1 = (param_2->mVelocity).x;
    fVar2 = (param_2->mVelocity).y;
    fVar3 = (param_2->mVelocity).z;
    fVar4 = fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2;
    if (JPADraw::_3358 < fVar4) {
      if (JPADraw::_3358 < fVar4) {
        if (JPADraw::_2524 < fVar4) {
          fVar5 = 1.0 / SQRT(fVar4);
          fVar4 = JPADraw::_2504 * fVar5 * (JPADraw::_3359 - fVar4 * fVar5 * fVar5);
        }
        fVar1 = fVar1 * fVar4;
        fVar2 = fVar2 * fVar4;
        fVar3 = fVar3 * fVar4;
      }
      fVar4 = JPADrawContext::pcb->mGlobalScale2D[1] * param_2->mScaleY;
      dVar9 = (double)(float)(dVar12 - (double)(fVar1 * fVar4));
      dVar8 = (double)(float)(dVar11 - (double)(fVar2 * fVar4));
      dVar7 = (double)(float)(dVar10 - (double)(fVar3 * fVar4));
      gx::GXBegin(0xa8,0,2);
      this = (JPADrawExecLine *)0xcc010000;
      write_volatile_4(0xcc008000,(float)dVar12);
      write_volatile_4(0xcc008000,(float)dVar11);
      write_volatile_4(0xcc008000,(float)dVar10);
      write_volatile_4(0xcc008000,JPADraw::_2524);
      write_volatile_4(0xcc008000,JPADraw::_2524);
      write_volatile_4(0xcc008000,(float)dVar9);
      write_volatile_4(0xcc008000,(float)dVar8);
      write_volatile_4(0xcc008000,(float)dVar7);
      write_volatile_4(0xcc008000,JPADraw::_2524);
      write_volatile_4(0xcc008000,JPADraw::_2525);
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  __psq_l0(auStack56,uVar6);
  __psq_l1(auStack56,uVar6);
  __psq_l0(auStack72,uVar6);
  __psq_l1(auStack72,uVar6);
  __psq_l0(auStack88,uVar6);
  __psq_l1(auStack88,uVar6);
  return this;
}


namespace JPADraw {

/* __stdcall stripeGetNext(JSULink<JPABaseParticle> *) */

undefined4 stripeGetNext(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}


/* __stdcall stripeGetPrev(JSULink<JPABaseParticle> *) */

undefined4 stripeGetPrev(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}

}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80263a40) */
/* WARNING: Removing unreachable block (ram,0x80263a30) */
/* WARNING: Removing unreachable block (ram,0x80263a20) */
/* WARNING: Removing unreachable block (ram,0x80263a10) */
/* WARNING: Removing unreachable block (ram,0x80263a00) */
/* WARNING: Removing unreachable block (ram,0x802639f8) */
/* WARNING: Removing unreachable block (ram,0x80263a08) */
/* WARNING: Removing unreachable block (ram,0x80263a18) */
/* WARNING: Removing unreachable block (ram,0x80263a28) */
/* WARNING: Removing unreachable block (ram,0x80263a38) */
/* WARNING: Removing unreachable block (ram,0x80263a48) */
/* __thiscall JPADrawExecStripe::exec(JPADrawContext const *) */

void __thiscall JPADrawExecStripe::exec(JPADrawExecStripe *this,JPADrawContext *param_1)

{
  float fVar1;
  float fVar2;
  code *pcVar3;
  int iVar4;
  JSUPtrLink *pJVar5;
  JPABaseParticle *pPtcl;
  uint uVar6;
  undefined4 uVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  undefined8 in_f21;
  double dVar14;
  undefined8 in_f22;
  double dVar15;
  undefined8 in_f23;
  double dVar16;
  undefined8 in_f24;
  double dVar17;
  undefined8 in_f25;
  double sx0_cos;
  undefined8 in_f26;
  double posZ;
  undefined8 in_f27;
  double posY;
  undefined8 in_f28;
  double posX;
  undefined8 in_f29;
  double dVar18;
  undefined8 in_f30;
  double sx0_sin;
  undefined8 in_f31;
  double dVar19;
  cXyz dirAxis;
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  float temp_63ff8984053;
  float sx0;
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  uVar6 = param_1->mpActiveParticles->mCount;
  if (1 < uVar6) {
    dVar16 = (double)JPADraw::_2524;
    dVar15 = (double)(JPADraw::_2525 /
                     (float)((double)CONCAT44(0x43300000,uVar6 - 1) - JPADraw::_2616));
    iVar4 = (*(code *)param_1->mpBaseArc->vtbl->getListOrder)();
    if (iVar4 == 0) {
      pJVar5 = param_1->mpActiveParticles->mpHead;
      pcVar3 = JPADraw::stripeGetNext;
    }
    else {
      pJVar5 = param_1->mpActiveParticles->mpTail;
      pcVar3 = JPADraw::stripeGetPrev;
      dVar16 = (double)JPADraw::_2525;
      dVar15 = -dVar15;
    }
    gx::GXBegin(0x98,0,(uVar6 & 0x7fff) << 1);
    dVar19 = (double)JPADraw::_3358;
    dVar14 = (double)JPADraw::_2524;
    while (pJVar5 != (JSUPtrLink *)0x0) {
      pPtcl = (JPABaseParticle *)pJVar5->mpData;
      posX = (double)(pPtcl->mPosition).x;
      posY = (double)(pPtcl->mPosition).y;
      posZ = (double)(pPtcl->mPosition).z;
      iVar4 = (int)(uint)(ushort)pPtcl->mRotateAngle >> (JKernel::JMath::jmaSinShift & 0x3f);
      sx0 = -pPtcl->mScaleX *
            (JPADrawContext::pcb->mGlobalScale2D[0] + JPADrawContext::pcb->mPivotX);
      sx0_sin = (double)(sx0 * JKernel::JMath::jmaSinTable[iVar4]);
      sx0_cos = (double)(sx0 * JKernel::JMath::jmaCosTable[iVar4]);
      temp_63ff8984053 =
           pPtcl->mScaleX * (JPADrawContext::pcb->mGlobalScale2D[0] - JPADrawContext::pcb->mPivotX);
      dVar18 = (double)(temp_63ff8984053 * JKernel::JMath::jmaSinTable[iVar4]);
      dVar17 = (double)(temp_63ff8984053 * JKernel::JMath::jmaCosTable[iVar4]);
      (*(code *)JPADrawContext::pcb->mpDirTypeFunc)(pPtcl,param_1->mpBaseEmitter,&dirAxis);
      dVar10 = (double)(dirAxis.z * dirAxis.z + dirAxis.x * dirAxis.x + dirAxis.y * dirAxis.y);
      if (dVar19 < dVar10) {
        if (dVar19 < dVar10) {
          if ((double)JPADraw::_2524 < dVar10) {
            sx0 = (float)(1.0 / SQRT(dVar10));
            dVar10 = (double)(JPADraw::_2504 * sx0 *
                             (JPADraw::_3359 - (float)(dVar10 * (double)(sx0 * sx0))));
          }
          dirAxis.x = (float)((double)dirAxis.x * dVar10);
          dirAxis.y = (float)((double)dirAxis.y * dVar10);
          dirAxis.z = (float)((double)dirAxis.z * dVar10);
        }
      }
      else {
        dirAxis.x = JPADraw::_2524;
        dirAxis.y = JPADraw::_2525;
        dirAxis.z = JPADraw::_2524;
      }
      sx0 = (pPtcl->mAxis).y;
      fVar1 = (pPtcl->mAxis).z;
      dVar12 = (double)(sx0 * dirAxis.z - fVar1 * dirAxis.y);
      fVar2 = (pPtcl->mAxis).x;
      dVar11 = (double)(fVar1 * dirAxis.x - fVar2 * dirAxis.z);
      dVar10 = (double)(fVar2 * dirAxis.y - sx0 * dirAxis.x);
      dVar13 = (double)((float)(dVar10 * dVar10) +
                       (float)(dVar12 * dVar12) + (float)(dVar11 * dVar11));
      if (dVar19 < dVar13) {
        if (dVar19 < dVar13) {
          if ((double)JPADraw::_2524 < dVar13) {
            sx0 = (float)(1.0 / SQRT(dVar13));
            dVar13 = (double)(JPADraw::_2504 * sx0 *
                             (JPADraw::_3359 - (float)(dVar13 * (double)(sx0 * sx0))));
          }
          dVar12 = (double)(float)(dVar12 * dVar13);
          dVar11 = (double)(float)(dVar11 * dVar13);
          dVar10 = (double)(float)(dVar10 * dVar13);
        }
      }
      else {
        dVar12 = (double)JPADraw::_2525;
        dVar11 = (double)JPADraw::_2524;
        dVar10 = dVar11;
      }
      (pPtcl->mAxis).x = (float)((double)dirAxis.y * dVar10) - (float)((double)dirAxis.z * dVar11);
      (pPtcl->mAxis).y = (float)((double)dirAxis.z * dVar12) - (float)((double)dirAxis.x * dVar10);
      (pPtcl->mAxis).z = (float)((double)dirAxis.x * dVar11) - (float)((double)dirAxis.y * dVar12);
      sx0 = (pPtcl->mAxis).z;
      fVar1 = (pPtcl->mAxis).x;
      fVar2 = (pPtcl->mAxis).y;
      dVar13 = (double)(sx0 * sx0 + fVar1 * fVar1 + fVar2 * fVar2);
      if (dVar19 < dVar13) {
        if ((double)JPADraw::_2524 < dVar13) {
          sx0 = (float)(1.0 / SQRT(dVar13));
          dVar13 = (double)(JPADraw::_2504 * sx0 *
                           (JPADraw::_3359 - (float)(dVar13 * (double)(sx0 * sx0))));
        }
        (pPtcl->mAxis).x = (float)((double)(pPtcl->mAxis).x * dVar13);
        (pPtcl->mAxis).y = (float)((double)(pPtcl->mAxis).y * dVar13);
        (pPtcl->mAxis).z = (float)((double)(pPtcl->mAxis).z * dVar13);
      }
      dVar9 = (double)(pPtcl->mAxis).x;
      dVar8 = (double)(pPtcl->mAxis).y;
      dVar13 = (double)(pPtcl->mAxis).z;
      write_volatile_4(0xcc008000,
                       (float)((double)((float)(sx0_sin * dVar9) +
                                       (float)(sx0_cos * (double)(float)dVar12) +
                                       (float)(dVar14 * (double)dirAxis.x)) + posX));
      write_volatile_4(0xcc008000,
                       (float)((double)((float)(sx0_sin * dVar8) +
                                       (float)(sx0_cos * (double)(float)dVar11) +
                                       (float)(dVar14 * (double)dirAxis.y)) + posY));
      write_volatile_4(0xcc008000,
                       (float)((double)((float)(sx0_sin * dVar13) +
                                       (float)(sx0_cos * (double)(float)dVar10) +
                                       (float)(dVar14 * (double)dirAxis.z)) + posZ));
      write_volatile_4(0xcc008000,JPADraw::_2524);
      write_volatile_4(0xcc008000,(float)dVar16);
      write_volatile_4(0xcc008000,
                       (float)((double)((float)(dVar18 * dVar9) +
                                       (float)(dVar17 * (double)(float)dVar12) +
                                       (float)(dVar14 * (double)dirAxis.x)) + posX));
      write_volatile_4(0xcc008000,
                       (float)((double)((float)(dVar18 * dVar8) +
                                       (float)(dVar17 * (double)(float)dVar11) +
                                       (float)(dVar14 * (double)dirAxis.y)) + posY));
      write_volatile_4(0xcc008000,
                       (float)((double)((float)(dVar18 * dVar13) +
                                       (float)(dVar17 * (double)(float)dVar10) +
                                       (float)(dVar14 * (double)dirAxis.z)) + posZ));
      write_volatile_4(0xcc008000,JPADraw::_2525);
      write_volatile_4(0xcc008000,(float)dVar16);
      pJVar5 = (JSUPtrLink *)(*pcVar3)(pJVar5);
      dVar16 = (double)(float)(dVar16 + dVar15);
    }
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  __psq_l0(auStack56,uVar7);
  __psq_l1(auStack56,uVar7);
  __psq_l0(auStack72,uVar7);
  __psq_l1(auStack72,uVar7);
  __psq_l0(auStack88,uVar7);
  __psq_l1(auStack88,uVar7);
  __psq_l0(auStack104,uVar7);
  __psq_l1(auStack104,uVar7);
  __psq_l0(auStack120,uVar7);
  __psq_l1(auStack120,uVar7);
  __psq_l0(auStack136,uVar7);
  __psq_l1(auStack136,uVar7);
  __psq_l0(auStack152,uVar7);
  __psq_l1(auStack152,uVar7);
  __psq_l0(auStack168,uVar7);
  __psq_l1(auStack168,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x80264388) */
/* WARNING: Removing unreachable block (ram,0x80264378) */
/* WARNING: Removing unreachable block (ram,0x80264368) */
/* WARNING: Removing unreachable block (ram,0x80264358) */
/* WARNING: Removing unreachable block (ram,0x80264348) */
/* WARNING: Removing unreachable block (ram,0x80264338) */
/* WARNING: Removing unreachable block (ram,0x80264340) */
/* WARNING: Removing unreachable block (ram,0x80264350) */
/* WARNING: Removing unreachable block (ram,0x80264360) */
/* WARNING: Removing unreachable block (ram,0x80264370) */
/* WARNING: Removing unreachable block (ram,0x80264380) */
/* WARNING: Removing unreachable block (ram,0x80264390) */
/* __thiscall JPADrawExecStripeCross::exec(JPADrawContext const *) */

void __thiscall JPADrawExecStripeCross::exec(JPADrawExecStripeCross *this,JPADrawContext *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  code *pcVar6;
  int iVar7;
  JSUPtrLink *pJVar8;
  undefined *puVar9;
  uint uVar10;
  JSUPtrLink *pJVar11;
  undefined4 uVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  undefined8 in_f20;
  double dVar18;
  undefined8 in_f21;
  undefined8 in_f22;
  double dVar19;
  undefined8 in_f23;
  undefined8 in_f24;
  undefined8 in_f25;
  double dVar20;
  double dVar21;
  undefined8 in_f26;
  double dVar22;
  double dVar23;
  undefined8 in_f27;
  double dVar24;
  undefined8 in_f28;
  double dVar25;
  undefined8 in_f29;
  double dVar26;
  undefined8 in_f30;
  double dVar27;
  undefined8 in_f31;
  double dVar28;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  undefined4 local_e8;
  int iStack228;
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  uVar10 = param_1->mpActiveParticles->mCount;
  if (1 < uVar10) {
    iStack228 = uVar10 - 1;
    local_e8 = 0x43300000;
    dVar28 = (double)(JPADraw::_2525 /
                     (float)((double)CONCAT44(0x43300000,iStack228) - JPADraw::_2616));
    iVar7 = (*(code *)param_1->mpBaseArc->vtbl->getListOrder)();
    if (iVar7 == 0) {
      pJVar11 = param_1->mpActiveParticles->mpHead;
      pcVar6 = JPADraw::stripeGetNext;
      fVar1 = JPADraw::_2524;
    }
    else {
      pJVar11 = param_1->mpActiveParticles->mpTail;
      pcVar6 = JPADraw::stripeGetPrev;
      dVar28 = -dVar28;
      fVar1 = JPADraw::_2525;
    }
    dVar19 = (double)fVar1;
    dVar21 = dVar19;
    gx::GXBegin(0x98,0,(uVar10 & 0x7fff) << 1);
    dVar27 = (double)JPADraw::_3358;
    dVar18 = (double)JPADraw::_2524;
    pJVar8 = pJVar11;
    while (pJVar8 != (JSUPtrLink *)0x0) {
      puVar9 = pJVar8->mpData;
      dVar24 = (double)*(float *)(puVar9 + 0x28);
      dVar22 = (double)*(float *)(puVar9 + 0x2c);
      dVar20 = (double)*(float *)(puVar9 + 0x30);
      iVar7 = (int)(uint)*(ushort *)(puVar9 + 0xc0) >> (JKernel::JMath::jmaSinShift & 0x3f);
      fVar1 = -*(float *)(puVar9 + 0x9c) *
              (JPADrawContext::pcb->mGlobalScale2D[0] + JPADrawContext::pcb->mPivotX);
      dVar26 = (double)(fVar1 * JKernel::JMath::jmaSinTable[iVar7]);
      dVar23 = (double)(fVar1 * JKernel::JMath::jmaCosTable[iVar7]);
      fVar1 = *(float *)(puVar9 + 0x9c) *
              (JPADrawContext::pcb->mGlobalScale2D[0] - JPADrawContext::pcb->mPivotX);
      dVar25 = (double)(fVar1 * JKernel::JMath::jmaSinTable[iVar7]);
      dVar17 = (double)(fVar1 * JKernel::JMath::jmaCosTable[iVar7]);
      (*(code *)JPADrawContext::pcb->mpDirTypeFunc)(puVar9,param_1->mpBaseEmitter,&local_118);
      dVar15 = (double)(local_110 * local_110 + local_118 * local_118 + local_114 * local_114);
      if (dVar27 < dVar15) {
        if (dVar27 < dVar15) {
          if ((double)JPADraw::_2524 < dVar15) {
            fVar1 = (float)(1.0 / SQRT(dVar15));
            dVar15 = (double)(JPADraw::_2504 * fVar1 *
                             (JPADraw::_3359 - (float)(dVar15 * (double)(fVar1 * fVar1))));
          }
          local_118 = (float)((double)local_118 * dVar15);
          local_114 = (float)((double)local_114 * dVar15);
          local_110 = (float)((double)local_110 * dVar15);
        }
      }
      else {
        local_118 = JPADraw::_2524;
        local_114 = JPADraw::_2525;
        local_110 = JPADraw::_2524;
      }
      dVar14 = (double)(*(float *)(puVar9 + 0x90) * local_110 -
                       *(float *)(puVar9 + 0x94) * local_114);
      dVar13 = (double)(*(float *)(puVar9 + 0x94) * local_118 -
                       *(float *)(puVar9 + 0x8c) * local_110);
      dVar15 = (double)(*(float *)(puVar9 + 0x8c) * local_114 -
                       *(float *)(puVar9 + 0x90) * local_118);
      dVar16 = (double)((float)(dVar15 * dVar15) +
                       (float)(dVar14 * dVar14) + (float)(dVar13 * dVar13));
      if (dVar27 < dVar16) {
        if (dVar27 < dVar16) {
          if ((double)JPADraw::_2524 < dVar16) {
            fVar1 = (float)(1.0 / SQRT(dVar16));
            dVar16 = (double)(JPADraw::_2504 * fVar1 *
                             (JPADraw::_3359 - (float)(dVar16 * (double)(fVar1 * fVar1))));
          }
          dVar14 = (double)(float)(dVar14 * dVar16);
          dVar13 = (double)(float)(dVar13 * dVar16);
          dVar15 = (double)(float)(dVar15 * dVar16);
        }
      }
      else {
        dVar14 = (double)JPADraw::_2525;
        dVar13 = (double)JPADraw::_2524;
        dVar15 = dVar13;
      }
      *(float *)(puVar9 + 0x8c) =
           (float)((double)local_114 * dVar15) - (float)((double)local_110 * dVar13);
      *(float *)(puVar9 + 0x90) =
           (float)((double)local_110 * dVar14) - (float)((double)local_118 * dVar15);
      *(float *)(puVar9 + 0x94) =
           (float)((double)local_118 * dVar13) - (float)((double)local_114 * dVar14);
      dVar16 = (double)(*(float *)(puVar9 + 0x94) * *(float *)(puVar9 + 0x94) +
                       *(float *)(puVar9 + 0x8c) * *(float *)(puVar9 + 0x8c) +
                       *(float *)(puVar9 + 0x90) * *(float *)(puVar9 + 0x90));
      if (dVar27 < dVar16) {
        if ((double)JPADraw::_2524 < dVar16) {
          fVar1 = (float)(1.0 / SQRT(dVar16));
          dVar16 = (double)(JPADraw::_2504 * fVar1 *
                           (JPADraw::_3359 - (float)(dVar16 * (double)(fVar1 * fVar1))));
        }
        *(float *)(puVar9 + 0x8c) = (float)((double)*(float *)(puVar9 + 0x8c) * dVar16);
        *(float *)(puVar9 + 0x90) = (float)((double)*(float *)(puVar9 + 0x90) * dVar16);
        *(float *)(puVar9 + 0x94) = (float)((double)*(float *)(puVar9 + 0x94) * dVar16);
      }
      local_10c = (float)dVar14;
      local_108 = (float)dVar13;
      local_104 = (float)dVar15;
      local_100 = local_118;
      local_fc = local_114;
      local_f8 = local_110;
      local_f4 = *(float *)(puVar9 + 0x8c);
      local_f0 = *(float *)(puVar9 + 0x90);
      local_ec = *(float *)(puVar9 + 0x94);
      write_volatile_4(0xcc008000,
                       (float)((double)((float)(dVar26 * (double)local_f4) +
                                       (float)(dVar23 * (double)(float)dVar14) +
                                       (float)(dVar18 * (double)local_118)) + dVar24));
      write_volatile_4(0xcc008000,
                       (float)((double)((float)(dVar26 * (double)local_f0) +
                                       (float)(dVar23 * (double)(float)dVar13) +
                                       (float)(dVar18 * (double)local_114)) + dVar22));
      write_volatile_4(0xcc008000,
                       (float)((double)((float)(dVar26 * (double)local_ec) +
                                       (float)(dVar23 * (double)(float)dVar15) +
                                       (float)(dVar18 * (double)local_110)) + dVar20));
      write_volatile_4(0xcc008000,JPADraw::_2524);
      write_volatile_4(0xcc008000,(float)dVar19);
      write_volatile_4(0xcc008000,
                       (float)((double)((float)(dVar25 * (double)local_f4) +
                                       (float)(dVar17 * (double)(float)dVar14) +
                                       (float)(dVar18 * (double)local_118)) + dVar24));
      write_volatile_4(0xcc008000,
                       (float)((double)((float)(dVar25 * (double)local_f0) +
                                       (float)(dVar17 * (double)(float)dVar13) +
                                       (float)(dVar18 * (double)local_114)) + dVar22));
      write_volatile_4(0xcc008000,
                       (float)((double)((float)(dVar25 * (double)local_ec) +
                                       (float)(dVar17 * (double)(float)dVar15) +
                                       (float)(dVar18 * (double)local_110)) + dVar20));
      write_volatile_4(0xcc008000,JPADraw::_2525);
      write_volatile_4(0xcc008000,(float)dVar19);
      pJVar8 = (JSUPtrLink *)(*pcVar6)(pJVar8);
      dVar19 = (double)(float)(dVar19 + dVar28);
    }
    gx::GXBegin(0x98,0,(uVar10 & 0x7fff) << 1);
    dVar19 = (double)JPADraw::_3358;
    dVar18 = (double)JPADraw::_2524;
    while (pJVar11 != (JSUPtrLink *)0x0) {
      puVar9 = pJVar11->mpData;
      iVar7 = (int)(uint)*(ushort *)(puVar9 + 0xc0) >> (JKernel::JMath::jmaSinShift & 0x3f);
      fVar5 = *(float *)(puVar9 + 0xa0) *
              (JPADrawContext::pcb->mGlobalScale2D[1] + JPADrawContext::pcb->mPivotY);
      fVar1 = fVar5 * JKernel::JMath::jmaCosTable[iVar7];
      fVar5 = fVar5 * -JKernel::JMath::jmaSinTable[iVar7];
      fVar4 = -*(float *)(puVar9 + 0xa0) *
              (JPADrawContext::pcb->mGlobalScale2D[1] - JPADrawContext::pcb->mPivotY);
      fVar3 = fVar4 * JKernel::JMath::jmaCosTable[iVar7];
      fVar4 = fVar4 * -JKernel::JMath::jmaSinTable[iVar7];
      local_118 = *(float *)(puVar9 + 0x34);
      local_114 = *(float *)(puVar9 + 0x38);
      local_110 = *(float *)(puVar9 + 0x3c);
      dVar27 = (double)(local_110 * local_110 + local_118 * local_118 + local_114 * local_114);
      if (dVar19 < dVar27) {
        if (dVar19 < dVar27) {
          if ((double)JPADraw::_2524 < dVar27) {
            fVar2 = (float)(1.0 / SQRT(dVar27));
            dVar27 = (double)(JPADraw::_2504 * fVar2 *
                             (JPADraw::_3359 - (float)(dVar27 * (double)(fVar2 * fVar2))));
          }
          local_118 = (float)((double)local_118 * dVar27);
          local_114 = (float)((double)local_114 * dVar27);
          local_110 = (float)((double)local_110 * dVar27);
        }
      }
      else {
        local_118 = JPADraw::_2524;
        local_114 = JPADraw::_2525;
        local_110 = JPADraw::_2524;
      }
      dVar23 = (double)(*(float *)(puVar9 + 0x90) * local_110 -
                       *(float *)(puVar9 + 0x94) * local_114);
      dVar15 = (double)(*(float *)(puVar9 + 0x94) * local_118 -
                       *(float *)(puVar9 + 0x8c) * local_110);
      dVar27 = (double)(*(float *)(puVar9 + 0x8c) * local_114 -
                       *(float *)(puVar9 + 0x90) * local_118);
      dVar17 = (double)((float)(dVar27 * dVar27) +
                       (float)(dVar23 * dVar23) + (float)(dVar15 * dVar15));
      if (dVar19 < dVar17) {
        if (dVar19 < dVar17) {
          if ((double)JPADraw::_2524 < dVar17) {
            fVar2 = (float)(1.0 / SQRT(dVar17));
            dVar17 = (double)(JPADraw::_2504 * fVar2 *
                             (JPADraw::_3359 - (float)(dVar17 * (double)(fVar2 * fVar2))));
          }
          dVar23 = (double)(float)(dVar23 * dVar17);
          dVar15 = (double)(float)(dVar15 * dVar17);
          dVar27 = (double)(float)(dVar27 * dVar17);
        }
      }
      else {
        dVar23 = (double)JPADraw::_2525;
        dVar15 = (double)JPADraw::_2524;
        dVar27 = dVar15;
      }
      *(float *)(puVar9 + 0x8c) =
           (float)((double)local_114 * dVar27) - (float)((double)local_110 * dVar15);
      *(float *)(puVar9 + 0x90) =
           (float)((double)local_110 * dVar23) - (float)((double)local_118 * dVar27);
      *(float *)(puVar9 + 0x94) =
           (float)((double)local_118 * dVar15) - (float)((double)local_114 * dVar23);
      dVar17 = (double)(*(float *)(puVar9 + 0x94) * *(float *)(puVar9 + 0x94) +
                       *(float *)(puVar9 + 0x8c) * *(float *)(puVar9 + 0x8c) +
                       *(float *)(puVar9 + 0x90) * *(float *)(puVar9 + 0x90));
      if (dVar19 < dVar17) {
        if ((double)JPADraw::_2524 < dVar17) {
          fVar2 = (float)(1.0 / SQRT(dVar17));
          dVar17 = (double)(JPADraw::_2504 * fVar2 *
                           (JPADraw::_3359 - (float)(dVar17 * (double)(fVar2 * fVar2))));
        }
        *(float *)(puVar9 + 0x8c) = (float)((double)*(float *)(puVar9 + 0x8c) * dVar17);
        *(float *)(puVar9 + 0x90) = (float)((double)*(float *)(puVar9 + 0x90) * dVar17);
        *(float *)(puVar9 + 0x94) = (float)((double)*(float *)(puVar9 + 0x94) * dVar17);
      }
      local_10c = (float)dVar23;
      local_108 = (float)dVar15;
      local_104 = (float)dVar27;
      local_100 = local_118;
      local_fc = local_114;
      local_f8 = local_110;
      local_f4 = *(float *)(puVar9 + 0x8c);
      local_f0 = *(float *)(puVar9 + 0x90);
      local_ec = *(float *)(puVar9 + 0x94);
      write_volatile_4(0xcc008000,
                       fVar1 * local_f4 +
                       fVar5 * (float)dVar23 + (float)(dVar18 * (double)local_118) +
                       *(float *)(puVar9 + 0x28));
      write_volatile_4(0xcc008000,
                       fVar1 * local_f0 +
                       fVar5 * (float)dVar15 + (float)(dVar18 * (double)local_114) +
                       *(float *)(puVar9 + 0x2c));
      write_volatile_4(0xcc008000,
                       fVar1 * local_ec +
                       fVar5 * (float)dVar27 + (float)(dVar18 * (double)local_110) +
                       *(float *)(puVar9 + 0x30));
      write_volatile_4(0xcc008000,JPADraw::_2524);
      write_volatile_4(0xcc008000,(float)dVar21);
      write_volatile_4(0xcc008000,
                       fVar3 * local_f4 +
                       fVar4 * (float)dVar23 + (float)(dVar18 * (double)local_118) +
                       *(float *)(puVar9 + 0x28));
      write_volatile_4(0xcc008000,
                       fVar3 * local_f0 +
                       fVar4 * (float)dVar15 + (float)(dVar18 * (double)local_114) +
                       *(float *)(puVar9 + 0x2c));
      write_volatile_4(0xcc008000,
                       fVar3 * local_ec +
                       fVar4 * (float)dVar27 + (float)(dVar18 * (double)local_110) +
                       *(float *)(puVar9 + 0x30));
      write_volatile_4(0xcc008000,JPADraw::_2525);
      write_volatile_4(0xcc008000,(float)dVar21);
      pJVar11 = (JSUPtrLink *)(*pcVar6)();
      dVar21 = (double)(float)(dVar21 + dVar28);
    }
  }
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  __psq_l0(auStack40,uVar12);
  __psq_l1(auStack40,uVar12);
  __psq_l0(auStack56,uVar12);
  __psq_l1(auStack56,uVar12);
  __psq_l0(auStack72,uVar12);
  __psq_l1(auStack72,uVar12);
  __psq_l0(auStack88,uVar12);
  __psq_l1(auStack88,uVar12);
  __psq_l0(auStack104,uVar12);
  __psq_l1(auStack104,uVar12);
  __psq_l0(auStack120,uVar12);
  __psq_l1(auStack120,uVar12);
  __psq_l0(auStack136,uVar12);
  __psq_l1(auStack136,uVar12);
  __psq_l0(auStack152,uVar12);
  __psq_l1(auStack152,uVar12);
  __psq_l0(auStack168,uVar12);
  __psq_l1(auStack168,uVar12);
  __psq_l0(auStack184,uVar12);
  __psq_l1(auStack184,uVar12);
  return;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall JPADrawExecRegisterColorEmitterPE::exec(JPADrawContext const *) */

void __thiscall
JPADrawExecRegisterColorEmitterPE::exec
          (JPADrawExecRegisterColorEmitterPE *this,JPADrawContext *param_1)

{
  uint uVar1;
  _GXColor _Var2;
  _GXColor _Var3;
  _GXColor local_18;
  _GXColor local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  _Var2 = param_1->mpDraw->mPrmColor;
  _Var3 = param_1->mpDraw->mEnvColor;
  uVar1 = (uint)CONCAT12((char)((((uint)_Var2 & 0xff0000) >> 0x10) *
                                ((JPADrawContext::pcb->mGlobalPrmColor).g + 1) >> 8),SUB42(_Var2,0))
  ;
  local_c._2_2_ =
       SUB42(_Var2,0) & 0xff |
       (ushort)(byte)(((uVar1 & 0xff00) >> 8) * ((JPADrawContext::pcb->mGlobalPrmColor).b + 1) >> 8)
       << 8;
  local_c = (_GXColor)
            ((((uint)_Var2 >> 0x18) * ((JPADrawContext::pcb->mGlobalPrmColor).r + 1) >> 8) << 0x18 |
             uVar1 & 0xffff0000 | local_c._2_2_ & 0xffffff00 |
            (local_c._2_2_ & 0xff) * ((JPADrawContext::pcb->mGlobalPrmColor).a + 1) >> 8 & 0xff);
  uVar1 = (uint)CONCAT12((char)((((uint)_Var3 & 0xff0000) >> 0x10) *
                                ((JPADrawContext::pcb->mGlobalEnvColor).g + 1) >> 8),SUB42(_Var3,0))
  ;
  local_10._2_2_ =
       SUB42(_Var3,0) & 0xff |
       (ushort)(byte)(((uVar1 & 0xff00) >> 8) * ((JPADrawContext::pcb->mGlobalEnvColor).b + 1) >> 8)
       << 8;
  local_10 = (_GXColor)
             ((((uint)_Var3 >> 0x18) * ((JPADrawContext::pcb->mGlobalEnvColor).r + 1) >> 8) << 0x18
              | uVar1 & 0xffff0000 | (uint)local_10._2_2_);
  local_14 = local_c;
  gx::GXSetTevColor(GX_TEVREG0,&local_14);
  local_18 = local_10;
  gx::GXSetTevColor(GX_TEVREG1,&local_18);
  return;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall JPADrawExecRegisterColorEmitterP::exec(JPADrawContext const *) */

void __thiscall
JPADrawExecRegisterColorEmitterP::exec
          (JPADrawExecRegisterColorEmitterP *this,JPADrawContext *param_1)

{
  uint uVar1;
  _GXColor _Var2;
  _GXColor local_8;
  undefined4 local_4;
  
  _Var2 = param_1->mpDraw->mPrmColor;
  uVar1 = (uint)CONCAT12((char)((((uint)_Var2 & 0xff0000) >> 0x10) *
                                ((JPADrawContext::pcb->mGlobalPrmColor).g + 1) >> 8),SUB42(_Var2,0))
  ;
  local_4._2_2_ =
       SUB42(_Var2,0) & 0xff |
       (ushort)(byte)(((uVar1 & 0xff00) >> 8) * ((JPADrawContext::pcb->mGlobalPrmColor).b + 1) >> 8)
       << 8;
  local_4 = (_GXColor)
            ((((uint)_Var2 >> 0x18) * ((JPADrawContext::pcb->mGlobalPrmColor).r + 1) >> 8) << 0x18 |
             uVar1 & 0xffff0000 | local_4._2_2_ & 0xffffff00 |
            (local_4._2_2_ & 0xff) * ((JPADrawContext::pcb->mGlobalPrmColor).a + 1) >> 8 & 0xff);
  local_8 = local_4;
  gx::GXSetTevColor(GX_TEVREG0,&local_8);
  return;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall JPADrawExecRegisterColorEmitterE::exec(JPADrawContext const *) */

void __thiscall
JPADrawExecRegisterColorEmitterE::exec
          (JPADrawExecRegisterColorEmitterE *this,JPADrawContext *param_1)

{
  uint uVar1;
  _GXColor _Var2;
  _GXColor local_8;
  undefined4 local_4;
  
  _Var2 = param_1->mpDraw->mEnvColor;
  uVar1 = (uint)CONCAT12((char)((((uint)_Var2 & 0xff0000) >> 0x10) *
                                ((JPADrawContext::pcb->mGlobalEnvColor).g + 1) >> 8),SUB42(_Var2,0))
  ;
  local_4._2_2_ =
       SUB42(_Var2,0) & 0xff |
       (ushort)(byte)(((uVar1 & 0xff00) >> 8) * ((JPADrawContext::pcb->mGlobalEnvColor).b + 1) >> 8)
       << 8;
  local_4 = (_GXColor)
            ((((uint)_Var2 >> 0x18) * ((JPADrawContext::pcb->mGlobalEnvColor).r + 1) >> 8) << 0x18 |
             uVar1 & 0xffff0000 | (uint)local_4._2_2_);
  local_8 = local_4;
  gx::GXSetTevColor(GX_TEVREG1,&local_8);
  return;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall JPADrawExecRegisterColorChildPE::exec(JPADrawContext const *) */

void __thiscall
JPADrawExecRegisterColorChildPE::exec(JPADrawExecRegisterColorChildPE *this,JPADrawContext *param_1)

{
  uint uVar1;
  uint uVar2;
  _GXColor local_18;
  _GXColor local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = (_GXColor)(**(code **)(*(int *)param_1->mpSweepArc + 0x70))();
  uVar2 = (**(code **)(*(int *)param_1->mpSweepArc + 0x74))();
  uVar1 = (uint)CONCAT12((char)((((uint)local_c & 0xff0000) >> 0x10) *
                                ((JPADrawContext::pcb->mGlobalPrmColor).g + 1) >> 8),
                         SUB42(local_c,0));
  local_c._2_2_ =
       SUB42(local_c,0) & 0xff |
       (ushort)(byte)(((uVar1 & 0xff00) >> 8) * ((JPADrawContext::pcb->mGlobalPrmColor).b + 1) >> 8)
       << 8;
  local_c = (_GXColor)
            ((((uint)local_c >> 0x18) * ((JPADrawContext::pcb->mGlobalPrmColor).r + 1) >> 8) << 0x18
             | uVar1 & 0xffff0000 | local_c._2_2_ & 0xffffff00 |
            (local_c._2_2_ & 0xff) * ((JPADrawContext::pcb->mGlobalPrmColor).a + 1) >> 8 & 0xff);
  uVar1 = (uint)CONCAT12((char)(((uVar2 & 0xff0000) >> 0x10) *
                                ((JPADrawContext::pcb->mGlobalEnvColor).g + 1) >> 8),(ushort)uVar2);
  local_10._2_2_ =
       (ushort)uVar2 & 0xff |
       (ushort)(byte)(((uVar1 & 0xff00) >> 8) * ((JPADrawContext::pcb->mGlobalEnvColor).b + 1) >> 8)
       << 8;
  local_10 = (_GXColor)
             (((uVar2 >> 0x18) * ((JPADrawContext::pcb->mGlobalEnvColor).r + 1) >> 8) << 0x18 |
              uVar1 & 0xffff0000 | (uint)local_10._2_2_);
  local_14 = local_c;
  gx::GXSetTevColor(GX_TEVREG0,&local_14);
  local_18 = local_10;
  gx::GXSetTevColor(GX_TEVREG1,&local_18);
  return;
}


/* __thiscall JPADrawCalcColorPrm::calc(JPADrawContext const *) */

void __thiscall JPADrawCalcColorPrm::calc(JPADrawCalcColorPrm *this,JPADrawContext *param_1)

{
  undefined4 uVar1;
  JPADraw *pJVar2;
  u8 local_18;
  u8 uStack23;
  u8 uStack22;
  u8 uStack21;
  
  uVar1 = (*(code *)param_1->mpBaseArc->vtbl->getPrmColor2)
                    (param_1->mpBaseArc,(int)*(short *)(JPADrawContext::pcb + 1));
  pJVar2 = param_1->mpDraw;
  local_18 = (u8)((uint)uVar1 >> 0x18);
  (pJVar2->mPrmColor).r = local_18;
  uStack23 = (u8)((uint)uVar1 >> 0x10);
  (pJVar2->mPrmColor).g = uStack23;
  uStack22 = (u8)((uint)uVar1 >> 8);
  (pJVar2->mPrmColor).b = uStack22;
  uStack21 = (u8)uVar1;
  (pJVar2->mPrmColor).a = uStack21;
  return;
}


/* __thiscall JPADrawCalcColorEnv::calc(JPADrawContext const *) */

void __thiscall JPADrawCalcColorEnv::calc(JPADrawCalcColorEnv *this,JPADrawContext *param_1)

{
  undefined4 uVar1;
  JPADraw *pJVar2;
  u8 local_18;
  u8 uStack23;
  u8 uStack22;
  u8 uStack21;
  
  uVar1 = (*(code *)param_1->mpBaseArc->vtbl->getEnvColor2)
                    (param_1->mpBaseArc,(int)*(short *)(JPADrawContext::pcb + 1));
  pJVar2 = param_1->mpDraw;
  local_18 = (u8)((uint)uVar1 >> 0x18);
  (pJVar2->mEnvColor).r = local_18;
  uStack23 = (u8)((uint)uVar1 >> 0x10);
  (pJVar2->mEnvColor).g = uStack23;
  uStack22 = (u8)((uint)uVar1 >> 8);
  (pJVar2->mEnvColor).b = uStack22;
  uStack21 = (u8)uVar1;
  (pJVar2->mEnvColor).a = uStack21;
  return;
}


/* __thiscall JPADrawCalcColorAnmFrameNormal::calc(JPADrawContext const *) */

void __thiscall
JPADrawCalcColorAnmFrameNormal::calc(JPADrawCalcColorAnmFrameNormal *this,JPADrawContext *param_1)

{
  int iVar1;
  short sVar2;
  
  iVar1 = (int)param_1->mpBaseEmitter->mTick;
  sVar2 = (*(code *)param_1->mpBaseArc->vtbl->getColorRegAnmMaxFrm)();
  if (sVar2 <= iVar1) {
    sVar2 = (*(code *)param_1->mpBaseArc->vtbl->getColorRegAnmMaxFrm)();
    iVar1 = (int)sVar2;
  }
  *(short *)(JPADrawContext::pcb + 1) = (short)iVar1;
  return;
}


/* WARNING: Removing unreachable block (ram,0x802648c4) */
/* __thiscall JPADrawCalcColorAnmFrameRepeat::calc(JPADrawContext const *) */

void __thiscall
JPADrawCalcColorAnmFrameRepeat::calc(JPADrawCalcColorAnmFrameRepeat *this,JPADrawContext *param_1)

{
  short sVar2;
  uint uVar1;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar4 = (double)param_1->mpBaseEmitter->mTick;
  sVar2 = (*(code *)param_1->mpBaseArc->vtbl->getColorRegAnmMaxFrm)();
  uVar1 = Runtime.PPCEABI.H::__cvt_fp2unsigned(dVar4);
  *(short *)(JPADrawContext::pcb + 1) =
       (short)uVar1 - (short)(uVar1 / ((int)sVar2 + 1U)) * (short)((int)sVar2 + 1U);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __thiscall JPADrawCalcColorAnmFrameReverse::calc(JPADrawContext const *) */

void __thiscall
JPADrawCalcColorAnmFrameReverse::calc(JPADrawCalcColorAnmFrameReverse *this,JPADrawContext *param_1)

{
  int iVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  short sVar5;
  
  iVar1 = (int)param_1->mpBaseEmitter->mTick;
  sVar5 = (*(code *)param_1->mpBaseArc->vtbl->getColorRegAnmMaxFrm)();
  uVar4 = (ushort)(iVar1 / (int)sVar5);
  uVar2 = uVar4 & 1;
  sVar3 = (short)iVar1 - uVar4 * sVar5;
  *(ushort *)(JPADrawContext::pcb + 1) = sVar3 + uVar2 * sVar5 + uVar2 * sVar3 * -2;
  return;
}


/* __thiscall JPADrawCalcColorAnmFrameMerge::calc(JPADrawContext const *) */

void __thiscall
JPADrawCalcColorAnmFrameMerge::calc(JPADrawCalcColorAnmFrameMerge *this,JPADrawContext *param_1)

{
  *(undefined2 *)(JPADrawContext::pcb + 1) = 0;
  return;
}


/* __thiscall JPADrawCalcColorAnmFrameRandom::calc(JPADrawContext const *) */

void __thiscall
JPADrawCalcColorAnmFrameRandom::calc(JPADrawCalcColorAnmFrameRandom *this,JPADrawContext *param_1)

{
  *(undefined2 *)(JPADrawContext::pcb + 1) = 0;
  return;
}


/* __thiscall JPADrawCalcTextureAnmIndexNormal::calc(JPADrawContext const *) */

void __thiscall
JPADrawCalcTextureAnmIndexNormal::calc(JPADrawCalcTextureAnmIndexNormal *this,JPADrawContext *pCtx)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)pCtx->mpBaseEmitter->mTick;
  uVar1 = (*(code *)pCtx->mpBaseArc->vtbl->getTextureAnmKeyNum)();
  if ((int)((uVar1 & 0xff) - 1) < (int)uVar2) {
    uVar2 = (*(code *)pCtx->mpBaseArc->vtbl->getTextureAnmKeyNum)();
    uVar2 = (uVar2 & 0xff) - 1;
  }
  uVar2 = (*(code *)pCtx->mpBaseArc->vtbl->getTextureIndex2)(pCtx->mpBaseArc,uVar2 & 0xff);
  pCtx->mpDraw->mTexIdx = pCtx->mpTexIdxArray[uVar2 & 0xff];
  return;
}


/* WARNING: Removing unreachable block (ram,0x80264ab4) */
/* __thiscall JPADrawCalcTextureAnmIndexRepeat::calc(JPADrawContext const *) */

void __thiscall
JPADrawCalcTextureAnmIndexRepeat::calc
          (JPADrawCalcTextureAnmIndexRepeat *this,JPADrawContext *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 in_f31;
  double dVar3;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar3 = (double)param_1->mpBaseEmitter->mTick;
  uVar1 = (*(code *)param_1->mpBaseArc->vtbl->getTextureAnmKeyNum)();
  uVar1 = (*(code *)param_1->mpBaseArc->vtbl->getTextureIndex2)
                    (param_1->mpBaseArc,
                     (int)dVar3 - ((int)dVar3 / (int)(uVar1 & 0xff)) * (uVar1 & 0xff) & 0xff);
  param_1->mpDraw->mTexIdx = param_1->mpTexIdxArray[uVar1 & 0xff];
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* __thiscall JPADrawCalcTextureAnmIndexReverse::calc(JPADrawContext const *) */

void __thiscall
JPADrawCalcTextureAnmIndexReverse::calc
          (JPADrawCalcTextureAnmIndexReverse *this,JPADrawContext *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (int)param_1->mpBaseEmitter->mTick;
  uVar2 = (*(code *)param_1->mpBaseArc->vtbl->getTextureAnmKeyNum)();
  iVar3 = (uVar2 & 0xff) - 1;
  uVar1 = iVar4 / iVar3;
  uVar2 = uVar1 & 1;
  iVar4 = iVar4 - uVar1 * iVar3;
  uVar2 = (*(code *)param_1->mpBaseArc->vtbl->getTextureIndex2)
                    (param_1->mpBaseArc,iVar4 + uVar2 * iVar3 + uVar2 * iVar4 * -2 & 0xff);
  param_1->mpDraw->mTexIdx = param_1->mpTexIdxArray[uVar2 & 0xff];
  return;
}


/* __thiscall JPADrawCalcTextureAnmIndexMerge::calc(JPADrawContext const *) */

void __thiscall
JPADrawCalcTextureAnmIndexMerge::calc(JPADrawCalcTextureAnmIndexMerge *this,JPADrawContext *param_1)

{
  ushort uVar1;
  
  uVar1 = (*(code *)param_1->mpBaseArc->vtbl->getTextureIndex)();
  param_1->mpDraw->mTexIdx = uVar1 & 0xff;
  return;
}


/* __thiscall JPADrawCalcTextureAnmIndexRandom::calc(JPADrawContext const *) */

void __thiscall
JPADrawCalcTextureAnmIndexRandom::calc
          (JPADrawCalcTextureAnmIndexRandom *this,JPADrawContext *param_1)

{
  ushort uVar1;
  
  uVar1 = (*(code *)param_1->mpBaseArc->vtbl->getTextureIndex)();
  param_1->mpDraw->mTexIdx = uVar1 & 0xff;
  return;
}


/* __thiscall JPADrawExecCallBack::exec(JPADrawContext const *) */

void __thiscall JPADrawExecCallBack::exec(JPADrawExecCallBack *this,JPADrawContext *pDC)

{
  JPACallBackBase *pJVar1;
  
  pJVar1 = pDC->mpBaseEmitter->mpEmitterCallBack;
  if (pJVar1 != (JPACallBackBase *)0x0) {
    (**(code **)(pJVar1->vtbl + 0x18))();
  }
  return;
}


/* __thiscall JPADrawExecCallBack::exec(JPADrawContext const *,
                                        JPABaseParticle *) */

void __thiscall
JPADrawExecCallBack::exec
          (JPADrawExecCallBack *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  JPACallBackBase2 *pJVar1;
  
  pJVar1 = param_2->mpCallBack2;
  if (pJVar1 != (JPACallBackBase2 *)0x0) {
    (**(code **)(pJVar1->vtbl + 0x14))(pJVar1,param_1->mpBaseEmitter);
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x80264d98) */
/* __thiscall JPADrawCalcScaleX::calc(JPADrawContext const *,
                                      JPABaseParticle *) */

void __thiscall
JPADrawCalcScaleX::calc(JPADrawCalcScaleX *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x24))();
  if (dVar2 <= (double)*(float *)&JPADrawContext::pcb->field_0xac) {
    dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x28))();
    if ((double)*(float *)&JPADrawContext::pcb->field_0xac <= dVar2) {
      param_2->mScaleX = param_2->mScaleOut;
    }
    else {
      dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x28))();
      dVar3 = (double)(float)((double)*(float *)&JPADrawContext::pcb->field_0xac - dVar2);
      dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x4c))();
      param_2->mScaleX = param_2->mScaleOut * (JPADraw::_2525 + (float)(dVar2 * dVar3));
    }
  }
  else {
    dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x2c))();
    dVar3 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x44))();
    param_2->mScaleX =
         param_2->mScaleOut *
         (float)((double)(float)((double)*(float *)&JPADrawContext::pcb->field_0xac * dVar3) + dVar2
                );
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80264ec8) */
/* __thiscall JPADrawCalcScaleY::calc(JPADrawContext const *,
                                      JPABaseParticle *) */

void __thiscall
JPADrawCalcScaleY::calc(JPADrawCalcScaleY *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x24))();
  if (dVar2 <= (double)*(float *)&JPADrawContext::pcb->field_0xac) {
    dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x28))();
    if ((double)*(float *)&JPADrawContext::pcb->field_0xac <= dVar2) {
      param_2->mScaleY = param_2->mScaleOut;
    }
    else {
      dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x28))();
      dVar3 = (double)(float)((double)*(float *)&JPADrawContext::pcb->field_0xac - dVar2);
      dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x50))();
      param_2->mScaleY = param_2->mScaleOut * (JPADraw::_2525 + (float)(dVar2 * dVar3));
    }
  }
  else {
    dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x30))();
    dVar3 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x48))();
    param_2->mScaleY =
         param_2->mScaleOut *
         (float)((double)(float)((double)*(float *)&JPADrawContext::pcb->field_0xac * dVar3) + dVar2
                );
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80265090) */
/* WARNING: Removing unreachable block (ram,0x80265080) */
/* WARNING: Removing unreachable block (ram,0x80265088) */
/* WARNING: Removing unreachable block (ram,0x80265098) */
/* __thiscall JPADrawCalcScaleXBySpeed::calc(JPADrawContext const *,
                                             JPABaseParticle *) */

void __thiscall
JPADrawCalcScaleXBySpeed::calc
          (JPADrawCalcScaleXBySpeed *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  dVar8 = (double)(param_2->mVelocity).x;
  dVar7 = (double)(param_2->mVelocity).y;
  dVar6 = (double)(param_2->mVelocity).z;
  dVar4 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x24))();
  if (dVar4 <= (double)*(float *)&JPADrawContext::pcb->field_0xac) {
    dVar4 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x28))();
    if ((double)*(float *)&JPADrawContext::pcb->field_0xac <= dVar4) {
      param_2->mScaleX = param_2->mScaleOut;
    }
    else {
      dVar4 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x28))();
      dVar5 = (double)(float)((double)*(float *)&JPADrawContext::pcb->field_0xac - dVar4);
      dVar4 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x4c))();
      param_2->mScaleX = param_2->mScaleOut * (JPADraw::_2525 + (float)(dVar4 * dVar5));
    }
  }
  else {
    dVar4 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x2c))();
    dVar5 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x44))();
    param_2->mScaleX =
         param_2->mScaleOut *
         (float)((double)(float)((double)*(float *)&JPADrawContext::pcb->field_0xac * dVar5) + dVar4
                );
  }
  fVar1 = (float)(dVar6 * dVar6) + (float)(dVar8 * dVar8) + (float)(dVar7 * dVar7);
  if (JPADraw::_2524 < fVar1) {
    fVar2 = 1.0 / SQRT(fVar1);
    fVar1 = fVar1 * JPADraw::_2504 * fVar2 * (JPADraw::_3359 - fVar1 * fVar2 * fVar2);
  }
  param_2->mScaleX = param_2->mScaleX * JPADraw::_5354 * fVar1;
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  __psq_l0(auStack56,uVar3);
  __psq_l1(auStack56,uVar3);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80265260) */
/* WARNING: Removing unreachable block (ram,0x80265250) */
/* WARNING: Removing unreachable block (ram,0x80265258) */
/* WARNING: Removing unreachable block (ram,0x80265268) */
/* __thiscall JPADrawCalcScaleYBySpeed::calc(JPADrawContext const *,
                                             JPABaseParticle *) */

void __thiscall
JPADrawCalcScaleYBySpeed::calc
          (JPADrawCalcScaleYBySpeed *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  dVar8 = (double)(param_2->mVelocity).x;
  dVar7 = (double)(param_2->mVelocity).y;
  dVar6 = (double)(param_2->mVelocity).z;
  dVar4 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x24))();
  if (dVar4 <= (double)*(float *)&JPADrawContext::pcb->field_0xac) {
    dVar4 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x28))();
    if ((double)*(float *)&JPADrawContext::pcb->field_0xac <= dVar4) {
      param_2->mScaleY = param_2->mScaleOut;
    }
    else {
      dVar4 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x28))();
      dVar5 = (double)(float)((double)*(float *)&JPADrawContext::pcb->field_0xac - dVar4);
      dVar4 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x50))();
      param_2->mScaleY = param_2->mScaleOut * (JPADraw::_2525 + (float)(dVar4 * dVar5));
    }
  }
  else {
    dVar4 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x30))();
    dVar5 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x48))();
    param_2->mScaleY =
         param_2->mScaleOut *
         (float)((double)(float)((double)*(float *)&JPADrawContext::pcb->field_0xac * dVar5) + dVar4
                );
  }
  fVar1 = (float)(dVar6 * dVar6) + (float)(dVar8 * dVar8) + (float)(dVar7 * dVar7);
  if (JPADraw::_2524 < fVar1) {
    fVar2 = 1.0 / SQRT(fVar1);
    fVar1 = fVar1 * JPADraw::_2504 * fVar2 * (JPADraw::_3359 - fVar1 * fVar2 * fVar2);
  }
  param_2->mScaleY = param_2->mScaleY * JPADraw::_5354 * fVar1;
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  __psq_l0(auStack56,uVar3);
  __psq_l1(auStack56,uVar3);
  return;
}


/* __thiscall JPADrawCalcScaleCopyX2Y::calc(JPADrawContext const *,
                                            JPABaseParticle *) */

void __thiscall
JPADrawCalcScaleCopyX2Y::calc
          (JPADrawCalcScaleCopyX2Y *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  param_2->mScaleY = param_2->mScaleX;
  return;
}


/* __thiscall JPADrawCalcScaleAnmTimingNormal::calc(JPADrawContext const *,
                                                    JPABaseParticle *) */

void __thiscall
JPADrawCalcScaleAnmTimingNormal::calc
          (JPADrawCalcScaleAnmTimingNormal *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  *(float *)&JPADrawContext::pcb->field_0xac = param_2->mCurNormTime;
  return;
}


/* WARNING: Removing unreachable block (ram,0x80265354) */
/* __thiscall JPADrawCalcScaleAnmTimingRepeatX::calc(JPADrawContext const *,
                                                     JPABaseParticle *) */

void __thiscall
JPADrawCalcScaleAnmTimingRepeatX::calc
          (JPADrawCalcScaleAnmTimingRepeatX *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  short sVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar1 = param_2->mCurFrame;
  sVar2 = (**(code **)(*(int *)param_1->mpExtraArc + 0x3c))();
  dVar4 = (double)(float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - JPADraw::_2554);
  sVar2 = (**(code **)(*(int *)param_1->mpExtraArc + 0x3c))();
  *(float *)&JPADrawContext::pcb->field_0xac =
       (float)((double)(float)((double)CONCAT44(0x43300000,
                                                (int)fVar1 - ((int)fVar1 / (int)sVar2) * (int)sVar2
                                                ^ 0x80000000) - JPADraw::_2554) / dVar4);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80265424) */
/* __thiscall JPADrawCalcScaleAnmTimingRepeatY::calc(JPADrawContext const *,
                                                     JPABaseParticle *) */

void __thiscall
JPADrawCalcScaleAnmTimingRepeatY::calc
          (JPADrawCalcScaleAnmTimingRepeatY *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  short sVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar1 = param_2->mCurFrame;
  sVar2 = (**(code **)(*(int *)param_1->mpExtraArc + 0x40))();
  dVar4 = (double)(float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - JPADraw::_2554);
  sVar2 = (**(code **)(*(int *)param_1->mpExtraArc + 0x40))();
  *(float *)&JPADrawContext::pcb->field_0xac =
       (float)((double)(float)((double)CONCAT44(0x43300000,
                                                (int)fVar1 - ((int)fVar1 / (int)sVar2) * (int)sVar2
                                                ^ 0x80000000) - JPADraw::_2554) / dVar4);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80265560) */
/* WARNING: Removing unreachable block (ram,0x80265568) */
/* __thiscall JPADrawCalcScaleAnmTimingReverseX::calc(JPADrawContext const *,
                                                      JPABaseParticle *) */

void __thiscall
JPADrawCalcScaleAnmTimingReverseX::calc
          (JPADrawCalcScaleAnmTimingReverseX *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  short sVar2;
  undefined4 uVar3;
  undefined8 in_f30;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  fVar1 = param_2->mCurFrame;
  sVar2 = (**(code **)(*(int *)param_1->mpExtraArc + 0x3c))();
  dVar4 = (double)(float)((double)CONCAT44(0x43300000,(int)fVar1 / (int)sVar2 & 1U ^ 0x80000000) -
                         JPADraw::_2554);
  fVar1 = param_2->mCurFrame;
  sVar2 = (**(code **)(*(int *)param_1->mpExtraArc + 0x3c))();
  dVar5 = (double)(float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - JPADraw::_2554);
  sVar2 = (**(code **)(*(int *)param_1->mpExtraArc + 0x3c))();
  fVar1 = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                   (int)fVar1 -
                                                   ((int)fVar1 / (int)sVar2) * (int)sVar2 ^
                                                   0x80000000) - JPADraw::_2554) / dVar5);
  *(float *)&JPADrawContext::pcb->field_0xac =
       (float)(dVar4 + (double)(fVar1 - (float)((double)JPADraw::_5420 * dVar4) * fVar1));
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802656a4) */
/* WARNING: Removing unreachable block (ram,0x802656ac) */
/* __thiscall JPADrawCalcScaleAnmTimingReverseY::calc(JPADrawContext const *,
                                                      JPABaseParticle *) */

void __thiscall
JPADrawCalcScaleAnmTimingReverseY::calc
          (JPADrawCalcScaleAnmTimingReverseY *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  short sVar2;
  undefined4 uVar3;
  undefined8 in_f30;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  fVar1 = param_2->mCurFrame;
  sVar2 = (**(code **)(*(int *)param_1->mpExtraArc + 0x40))();
  dVar4 = (double)(float)((double)CONCAT44(0x43300000,(int)fVar1 / (int)sVar2 & 1U ^ 0x80000000) -
                         JPADraw::_2554);
  fVar1 = param_2->mCurFrame;
  sVar2 = (**(code **)(*(int *)param_1->mpExtraArc + 0x40))();
  dVar5 = (double)(float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - JPADraw::_2554);
  sVar2 = (**(code **)(*(int *)param_1->mpExtraArc + 0x40))();
  fVar1 = (float)((double)(float)((double)CONCAT44(0x43300000,
                                                   (int)fVar1 -
                                                   ((int)fVar1 / (int)sVar2) * (int)sVar2 ^
                                                   0x80000000) - JPADraw::_2554) / dVar5);
  *(float *)&JPADrawContext::pcb->field_0xac =
       (float)(dVar4 + (double)(fVar1 - (float)((double)JPADraw::_5420 * dVar4) * fVar1));
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return;
}


/* __thiscall JPADrawCalcColorPrm::calc(JPADrawContext const *,
                                        JPABaseParticle *) */

void __thiscall
JPADrawCalcColorPrm::calc
          (JPADrawCalcColorPrm *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  undefined4 uVar1;
  u8 local_18;
  u8 uStack23;
  u8 uStack22;
  u8 uStack21;
  
  uVar1 = (*(code *)param_1->mpBaseArc->vtbl->getPrmColor2)
                    (param_1->mpBaseArc,(int)*(short *)(JPADrawContext::pcb + 1));
  local_18 = (u8)((uint)uVar1 >> 0x18);
  (param_2->mPrmColor).r = local_18;
  uStack23 = (u8)((uint)uVar1 >> 0x10);
  (param_2->mPrmColor).g = uStack23;
  uStack22 = (u8)((uint)uVar1 >> 8);
  (param_2->mPrmColor).b = uStack22;
  uStack21 = (u8)uVar1;
  (param_2->mPrmColor).a = uStack21;
  return;
}


/* __thiscall JPADrawCalcColorEnv::calc(JPADrawContext const *,
                                        JPABaseParticle *) */

void __thiscall
JPADrawCalcColorEnv::calc
          (JPADrawCalcColorEnv *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  undefined4 uVar1;
  u8 local_18;
  u8 uStack23;
  u8 uStack22;
  u8 uStack21;
  
  uVar1 = (*(code *)param_1->mpBaseArc->vtbl->getEnvColor2)
                    (param_1->mpBaseArc,(int)*(short *)(JPADrawContext::pcb + 1));
  local_18 = (u8)((uint)uVar1 >> 0x18);
  (param_2->mEnvColor).r = local_18;
  uStack23 = (u8)((uint)uVar1 >> 0x10);
  (param_2->mEnvColor).g = uStack23;
  uStack22 = (u8)((uint)uVar1 >> 8);
  (param_2->mEnvColor).b = uStack22;
  uStack21 = (u8)uVar1;
  (param_2->mEnvColor).a = uStack21;
  return;
}


/* __thiscall JPADrawCalcColorCopyFromEmitter::calc(JPADrawContext const *,
                                                    JPABaseParticle *) */

void __thiscall
JPADrawCalcColorCopyFromEmitter::calc
          (JPADrawCalcColorCopyFromEmitter *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  JPADraw *pJVar1;
  
  pJVar1 = param_1->mpDraw;
  (param_2->mPrmColor).r = (pJVar1->mPrmColor).r;
  (param_2->mPrmColor).g = (pJVar1->mPrmColor).g;
  (param_2->mPrmColor).b = (pJVar1->mPrmColor).b;
  (param_2->mPrmColor).a = (pJVar1->mPrmColor).a;
  pJVar1 = param_1->mpDraw;
  (param_2->mEnvColor).r = (pJVar1->mEnvColor).r;
  (param_2->mEnvColor).g = (pJVar1->mEnvColor).g;
  (param_2->mEnvColor).b = (pJVar1->mEnvColor).b;
  (param_2->mEnvColor).a = (pJVar1->mEnvColor).a;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPADrawCalcColorAnmFrameNormal::calc(JPADrawContext const *,
                                                   JPABaseParticle *) */

void __thiscall
JPADrawCalcColorAnmFrameNormal::calc
          (JPADrawCalcColorAnmFrameNormal *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  short sVar2;
  undefined2 uVar3;
  
  fVar1 = param_2->mCurFrame;
  sVar2 = (*(code *)param_1->mpBaseArc->vtbl->getColorRegAnmMaxFrm)();
  if ((int)fVar1 < (int)sVar2) {
    uVar3 = (undefined2)(int)param_2->mCurFrame;
  }
  else {
    uVar3 = (*(code *)param_1->mpBaseArc->vtbl->getColorRegAnmMaxFrm)();
  }
  *(undefined2 *)(JPADrawContext::pcb + 1) = uVar3;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JPADrawCalcColorAnmFrameRepeat::calc(JPADrawContext const *,
                                                   JPABaseParticle *) */

void __thiscall
JPADrawCalcColorAnmFrameRepeat::calc
          (JPADrawCalcColorAnmFrameRepeat *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  short sVar3;
  short sVar4;
  int iVar2;
  
  fVar1 = param_2->mCurFrame;
  sVar3 = (*(code *)param_1->mpBaseArc->vtbl->getColorRegAnmMaxFrm)();
  sVar4 = (*(code *)param_1->mpBaseArc->vtbl->getColLoopOffset)();
  iVar2 = (int)fVar1 + (param_2->mLoopOffset & (int)sVar4);
  *(short *)(JPADrawContext::pcb + 1) =
       (short)iVar2 - (short)(iVar2 / (sVar3 + 1)) * (short)(sVar3 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPADrawCalcColorAnmFrameReverse::calc(JPADrawContext const *,
                                                    JPABaseParticle *) */

void __thiscall
JPADrawCalcColorAnmFrameReverse::calc
          (JPADrawCalcColorAnmFrameReverse *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  short sVar5;
  short sVar6;
  int iVar4;
  
  sVar5 = (*(code *)param_1->mpBaseArc->vtbl->getColLoopOffset)();
  uVar3 = param_2->mLoopOffset;
  sVar6 = (*(code *)param_1->mpBaseArc->vtbl->getColorRegAnmMaxFrm)();
  iVar4 = (uVar3 & (int)sVar5) + (int)param_2->mCurFrame;
  uVar2 = (ushort)(iVar4 / (int)sVar6);
  uVar1 = uVar2 & 1;
  sVar5 = (short)iVar4 - uVar2 * sVar6;
  *(ushort *)(JPADrawContext::pcb + 1) = sVar5 + uVar1 * sVar6 + uVar1 * sVar5 * -2;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPADrawCalcColorAnmFrameMerge::calc(JPADrawContext const *,
                                                  JPABaseParticle *) */

void __thiscall
JPADrawCalcColorAnmFrameMerge::calc
          (JPADrawCalcColorAnmFrameMerge *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  int iVar1;
  uint uVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  
  sVar3 = (*(code *)param_1->mpBaseArc->vtbl->getColLoopOffset)();
  uVar2 = param_2->mLoopOffset;
  sVar4 = (*(code *)param_1->mpBaseArc->vtbl->getColorRegAnmMaxFrm)();
  uVar5 = (int)sVar4 + 1;
  iVar1 = (int)((float)((double)CONCAT44(0x43300000,uVar2 & (int)sVar3 ^ 0x80000000) -
                       JPADraw::_2554) +
               (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - JPADraw::_2554) *
               param_2->mCurNormTime);
  *(short *)(JPADrawContext::pcb + 1) = (short)iVar1 - (short)(iVar1 / (int)uVar5) * (short)uVar5;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPADrawCalcColorAnmFrameRandom::calc(JPADrawContext const *,
                                                   JPABaseParticle *) */

void __thiscall
JPADrawCalcColorAnmFrameRandom::calc
          (JPADrawCalcColorAnmFrameRandom *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  short sVar2;
  short sVar3;
  uint uVar1;
  
  sVar2 = (*(code *)param_1->mpBaseArc->vtbl->getColorRegAnmMaxFrm)();
  sVar3 = (*(code *)param_1->mpBaseArc->vtbl->getColLoopOffset)();
  uVar1 = param_2->mLoopOffset & (int)sVar3;
  *(short *)(JPADrawContext::pcb + 1) =
       (short)uVar1 - (short)((int)uVar1 / (sVar2 + 1)) * (short)(sVar2 + 1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80265c18) */
/* WARNING: Removing unreachable block (ram,0x80265c20) */
/* __thiscall JPADrawCalcAlpha::calc(JPADrawContext const *,
                                     JPABaseParticle *) */

void __thiscall
JPADrawCalcAlpha::calc(JPADrawCalcAlpha *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f30;
  double dVar4;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar4 = (double)param_2->mCurNormTime;
  dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x68))();
  if (dVar2 <= dVar4) {
    dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x6c))();
    if (dVar4 <= dVar2) {
      dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x74))();
    }
    else {
      dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x6c))();
      dVar4 = (double)(float)(dVar4 - dVar2);
      dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x90))();
      dVar4 = (double)(float)(dVar2 * dVar4);
      dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x74))();
      dVar2 = (double)(float)(dVar2 + dVar4);
    }
  }
  else {
    dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x70))();
    dVar3 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x8c))();
    dVar2 = (double)(float)((double)(float)(dVar4 * dVar3) + dVar2);
  }
  param_2->mAlphaOut = (float)dVar2;
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80265d34) */
/* __thiscall JPADrawCalcAlphaFlickNrmSin::calc(JPADrawContext const *,
                                                JPABaseParticle *) */

void __thiscall
JPADrawCalcAlphaFlickNrmSin::calc
          (JPADrawCalcAlphaFlickNrmSin *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  double dVar3;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x7c))();
  dVar3 = (double)JKernel::JMath::jmaSinTable
                  [(int)((int)((float)((double)JPADraw::_2525 - dVar2) *
                              param_2->mAlphaWaveRandom *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)param_2->mCurFrame << 0xe ^ 0x80000000)
                                     - JPADraw::_2554)) & 0xffffU) >>
                   (JKernel::JMath::jmaSinShift & 0x3f)];
  dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x84))();
  param_2->mAlphaOut =
       param_2->mAlphaOut *
       (float)((double)JPADraw::_2525 +
              (double)(param_2->mAlphaWaveRandom *
                      (float)((double)(JPADraw::_2504 * (float)(dVar3 - (double)JPADraw::_2525)) *
                             dVar2)));
  if (param_2->mAlphaOut < JPADraw::_2524) {
    param_2->mAlphaOut = JPADraw::_2524;
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80265e9c) */
/* WARNING: Removing unreachable block (ram,0x80265ea4) */
/* __thiscall JPADrawCalcAlphaFlickAddSin::calc(JPADrawContext const *,
                                                JPABaseParticle *) */

void __thiscall
JPADrawCalcAlphaFlickAddSin::calc
          (JPADrawCalcAlphaFlickAddSin *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f30;
  double dVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar3 = (double)(param_2->mAlphaWaveRandom *
                  (float)((double)CONCAT44(0x43300000,(int)param_2->mCurFrame << 0xe ^ 0x80000000) -
                         JPADraw::_2554));
  dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x80))();
  dVar4 = (double)JKernel::JMath::jmaSinTable
                  [(int)((int)(dVar3 * (double)(float)((double)JPADraw::_2525 - dVar2)) & 0xffffU)
                   >> (JKernel::JMath::jmaSinShift & 0x3f)];
  dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x7c))();
  dVar3 = (double)JKernel::JMath::jmaSinTable
                  [(int)((int)(dVar3 * (double)(float)((double)JPADraw::_2525 - dVar2)) & 0xffffU)
                   >> (JKernel::JMath::jmaSinShift & 0x3f)];
  dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x84))();
  param_2->mAlphaOut =
       param_2->mAlphaOut *
       JPADraw::_2504 *
       (JPADraw::_5420 +
       param_2->mAlphaWaveRandom *
       (float)(dVar2 * (double)(JPADraw::_2504 * ((float)(dVar3 + dVar4) - JPADraw::_5420))));
  if (param_2->mAlphaOut < JPADraw::_2524) {
    param_2->mAlphaOut = JPADraw::_2524;
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80266020) */
/* WARNING: Removing unreachable block (ram,0x80266018) */
/* WARNING: Removing unreachable block (ram,0x80266028) */
/* __thiscall JPADrawCalcAlphaFlickMultSin::calc(JPADrawContext const *,
                                                 JPABaseParticle *) */

void __thiscall
JPADrawCalcAlphaFlickMultSin::calc
          (JPADrawCalcAlphaFlickMultSin *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f29;
  double dVar4;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  dVar5 = (double)(param_2->mAlphaWaveRandom *
                  (float)((double)CONCAT44(0x43300000,(int)param_2->mCurFrame << 0xe ^ 0x80000000) -
                         JPADraw::_2554));
  dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x84))();
  dVar4 = (double)(param_2->mAlphaWaveRandom * (float)((double)JPADraw::_2504 * dVar2));
  dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x80))();
  dVar6 = (double)JKernel::JMath::jmaSinTable
                  [(int)((int)(dVar5 * (double)(float)((double)JPADraw::_2525 - dVar2)) & 0xffffU)
                   >> (JKernel::JMath::jmaSinShift & 0x3f)];
  dVar2 = (double)(**(code **)(*(int *)param_1->mpExtraArc + 0x7c))();
  dVar3 = (double)JPADraw::_2525;
  param_2->mAlphaOut =
       param_2->mAlphaOut *
       (float)(dVar3 + (double)(float)(dVar4 * (double)(float)((double)JKernel::JMath::jmaSinTable
                                                                       [(int)((int)(dVar5 * (double)
                                                  (float)(dVar3 - dVar2)) & 0xffffU) >>
                                                  (JKernel::JMath::jmaSinShift & 0x3f)] - dVar3))) *
       (float)(dVar3 + (double)(float)(dVar4 * (double)(float)(dVar6 - dVar3)));
  if (param_2->mAlphaOut < JPADraw::_2524) {
    param_2->mAlphaOut = JPADraw::_2524;
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  __psq_l0(auStack40,uVar1);
  __psq_l1(auStack40,uVar1);
  return;
}


/* __thiscall JPADrawCalcTextureAnmIndexNormal::calc(JPADrawContext const *,
                                                     JPABaseParticle *) */

void __thiscall
JPADrawCalcTextureAnmIndexNormal::calc
          (JPADrawCalcTextureAnmIndexNormal *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (*(code *)param_1->mpBaseArc->vtbl->getTextureAnmKeyNum)();
  uVar2 = (uint)param_2->mCurFrame;
  if ((int)((uVar1 & 0xff) - 1) < (int)uVar2) {
    uVar2 = (*(code *)param_1->mpBaseArc->vtbl->getTextureAnmKeyNum)();
    uVar2 = (uVar2 & 0xff) - 1;
  }
  uVar2 = (*(code *)param_1->mpBaseArc->vtbl->getTextureIndex2)(param_1->mpBaseArc,uVar2 & 0xff);
  param_2->mTexIdx = param_1->mpTexIdxArray[uVar2 & 0xff];
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JPADrawCalcTextureAnmIndexRepeat::calc(JPADrawContext const *,
                                                     JPABaseParticle *) */

void __thiscall
JPADrawCalcTextureAnmIndexRepeat::calc
          (JPADrawCalcTextureAnmIndexRepeat *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  uint uVar2;
  short sVar4;
  int iVar3;
  
  fVar1 = param_2->mCurFrame;
  uVar2 = (*(code *)param_1->mpBaseArc->vtbl->getTextureAnmKeyNum)();
  sVar4 = (*(code *)param_1->mpBaseArc->vtbl->getTexLoopOffset)();
  iVar3 = (int)fVar1 + (param_2->mLoopOffset & (int)sVar4);
  uVar2 = (*(code *)param_1->mpBaseArc->vtbl->getTextureIndex2)
                    (param_1->mpBaseArc,
                     iVar3 - (iVar3 / (int)(uVar2 & 0xff)) * (uVar2 & 0xff) & 0xff);
  param_2->mTexIdx = param_1->mpTexIdxArray[uVar2 & 0xff];
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPADrawCalcTextureAnmIndexReverse::calc(JPADrawContext const *,
                                                      JPABaseParticle *) */

void __thiscall
JPADrawCalcTextureAnmIndexReverse::calc
          (JPADrawCalcTextureAnmIndexReverse *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  uint uVar1;
  short sVar4;
  uint uVar2;
  int iVar3;
  int iVar5;
  
  sVar4 = (*(code *)param_1->mpBaseArc->vtbl->getTexLoopOffset)();
  uVar1 = param_2->mLoopOffset;
  uVar2 = (*(code *)param_1->mpBaseArc->vtbl->getTextureAnmKeyNum)();
  iVar5 = (uVar2 & 0xff) - 1;
  iVar3 = (uVar1 & (int)sVar4) + (int)param_2->mCurFrame;
  uVar2 = iVar3 / iVar5;
  uVar1 = uVar2 & 1;
  iVar3 = iVar3 - uVar2 * iVar5;
  uVar1 = (*(code *)param_1->mpBaseArc->vtbl->getTextureIndex2)
                    (param_1->mpBaseArc,iVar3 + uVar1 * iVar5 + uVar1 * iVar3 * -2 & 0xff);
  param_2->mTexIdx = param_1->mpTexIdxArray[uVar1 & 0xff];
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPADrawCalcTextureAnmIndexMerge::calc(JPADrawContext const *,
                                                    JPABaseParticle *) */

void __thiscall
JPADrawCalcTextureAnmIndexMerge::calc
          (JPADrawCalcTextureAnmIndexMerge *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  int iVar1;
  uint uVar2;
  short sVar3;
  
  uVar2 = (*(code *)param_1->mpBaseArc->vtbl->getTextureAnmKeyNum)();
  uVar2 = uVar2 & 0xff;
  sVar3 = (*(code *)param_1->mpBaseArc->vtbl->getTexLoopOffset)();
  iVar1 = (int)((float)((double)CONCAT44(0x43300000,param_2->mLoopOffset & (int)sVar3 ^ 0x80000000)
                       - JPADraw::_2554) +
               (float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - JPADraw::_2554) *
               param_2->mCurNormTime);
  uVar2 = (*(code *)param_1->mpBaseArc->vtbl->getTextureIndex2)
                    (param_1->mpBaseArc,iVar1 - (iVar1 / (int)uVar2) * uVar2 & 0xff);
  param_2->mTexIdx = param_1->mpTexIdxArray[uVar2 & 0xff];
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPADrawCalcTextureAnmIndexRandom::calc(JPADrawContext const *,
                                                     JPABaseParticle *) */

void __thiscall
JPADrawCalcTextureAnmIndexRandom::calc
          (JPADrawCalcTextureAnmIndexRandom *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  short sVar2;
  uint uVar1;
  uint uVar3;
  
  sVar2 = (*(code *)param_1->mpBaseArc->vtbl->getTexLoopOffset)();
  uVar3 = param_2->mLoopOffset & (int)sVar2;
  uVar1 = (*(code *)param_1->mpBaseArc->vtbl->getTextureAnmKeyNum)();
  uVar1 = (*(code *)param_1->mpBaseArc->vtbl->getTextureIndex2)
                    (param_1->mpBaseArc,
                     uVar3 - ((int)uVar3 / (int)(uVar1 & 0xff)) * (uVar1 & 0xff) & 0xff);
  param_2->mTexIdx = param_1->mpTexIdxArray[uVar1 & 0xff];
  return;
}


/* __thiscall JPADrawCalcChildAlphaOut::calc(JPADrawContext const *,
                                             JPABaseParticle *) */

void __thiscall
JPADrawCalcChildAlphaOut::calc
          (JPADrawCalcChildAlphaOut *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  param_2->mAlphaOut = JPADraw::_2525 - param_2->mCurNormTime;
  return;
}


/* __thiscall JPADrawCalcChildScaleOut::calc(JPADrawContext const *,
                                             JPABaseParticle *) */

void __thiscall
JPADrawCalcChildScaleOut::calc
          (JPADrawCalcChildScaleOut *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  
  fVar1 = JPADraw::_2525;
  param_2->mScaleX = param_2->mScaleOut * (JPADraw::_2525 - param_2->mCurNormTime);
  param_2->mScaleY = param_2->mAlphaWaveRandom * (fVar1 - param_2->mCurNormTime);
  return;
}


/* __thiscall JPADrawCalcChildScaleOut::~JPADrawCalcChildScaleOut(void) */

void __thiscall JPADrawCalcChildScaleOut::_JPADrawCalcChildScaleOut(JPADrawCalcChildScaleOut *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcChildScaleOut *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcChildScaleOut *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcParticleVisitor::~JPADrawCalcParticleVisitor(void) */

void __thiscall
JPADrawCalcParticleVisitor::_JPADrawCalcParticleVisitor(JPADrawCalcParticleVisitor *this)

{
  short in_r4;
  
  if ((this != (JPADrawCalcParticleVisitor *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall JPADrawCalcChildAlphaOut::~JPADrawCalcChildAlphaOut(void) */

void __thiscall JPADrawCalcChildAlphaOut::_JPADrawCalcChildAlphaOut(JPADrawCalcChildAlphaOut *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcChildAlphaOut *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcChildAlphaOut *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcAlphaFlickMultSin::~JPADrawCalcAlphaFlickMultSin(void) */

void __thiscall
JPADrawCalcAlphaFlickMultSin::_JPADrawCalcAlphaFlickMultSin(JPADrawCalcAlphaFlickMultSin *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcAlphaFlickMultSin *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcAlphaFlickMultSin *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcAlphaFlickAddSin::~JPADrawCalcAlphaFlickAddSin(void) */

void __thiscall
JPADrawCalcAlphaFlickAddSin::_JPADrawCalcAlphaFlickAddSin(JPADrawCalcAlphaFlickAddSin *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcAlphaFlickAddSin *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcAlphaFlickAddSin *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcAlphaFlickNrmSin::~JPADrawCalcAlphaFlickNrmSin(void) */

void __thiscall
JPADrawCalcAlphaFlickNrmSin::_JPADrawCalcAlphaFlickNrmSin(JPADrawCalcAlphaFlickNrmSin *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcAlphaFlickNrmSin *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcAlphaFlickNrmSin *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcAlpha::~JPADrawCalcAlpha(void) */

void __thiscall JPADrawCalcAlpha::_JPADrawCalcAlpha(JPADrawCalcAlpha *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcAlpha *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcAlpha *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcColorCopyFromEmitter::~JPADrawCalcColorCopyFromEmitter(void) */

void __thiscall
JPADrawCalcColorCopyFromEmitter::_JPADrawCalcColorCopyFromEmitter
          (JPADrawCalcColorCopyFromEmitter *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcColorCopyFromEmitter *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcColorCopyFromEmitter *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcScaleAnmTimingReverseY::~JPADrawCalcScaleAnmTimingReverseY(void) */

void __thiscall
JPADrawCalcScaleAnmTimingReverseY::_JPADrawCalcScaleAnmTimingReverseY
          (JPADrawCalcScaleAnmTimingReverseY *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcScaleAnmTimingReverseY *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcScaleAnmTimingReverseY *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcScaleAnmTimingReverseX::~JPADrawCalcScaleAnmTimingReverseX(void) */

void __thiscall
JPADrawCalcScaleAnmTimingReverseX::_JPADrawCalcScaleAnmTimingReverseX
          (JPADrawCalcScaleAnmTimingReverseX *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcScaleAnmTimingReverseX *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcScaleAnmTimingReverseX *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcScaleAnmTimingRepeatY::~JPADrawCalcScaleAnmTimingRepeatY(void) */

void __thiscall
JPADrawCalcScaleAnmTimingRepeatY::_JPADrawCalcScaleAnmTimingRepeatY
          (JPADrawCalcScaleAnmTimingRepeatY *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcScaleAnmTimingRepeatY *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcScaleAnmTimingRepeatY *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcScaleAnmTimingRepeatX::~JPADrawCalcScaleAnmTimingRepeatX(void) */

void __thiscall
JPADrawCalcScaleAnmTimingRepeatX::_JPADrawCalcScaleAnmTimingRepeatX
          (JPADrawCalcScaleAnmTimingRepeatX *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcScaleAnmTimingRepeatX *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcScaleAnmTimingRepeatX *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcScaleAnmTimingNormal::~JPADrawCalcScaleAnmTimingNormal(void) */

void __thiscall
JPADrawCalcScaleAnmTimingNormal::_JPADrawCalcScaleAnmTimingNormal
          (JPADrawCalcScaleAnmTimingNormal *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcScaleAnmTimingNormal *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcScaleAnmTimingNormal *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcScaleCopyX2Y::~JPADrawCalcScaleCopyX2Y(void) */

void __thiscall JPADrawCalcScaleCopyX2Y::_JPADrawCalcScaleCopyX2Y(JPADrawCalcScaleCopyX2Y *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcScaleCopyX2Y *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcScaleCopyX2Y *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcScaleYBySpeed::~JPADrawCalcScaleYBySpeed(void) */

void __thiscall JPADrawCalcScaleYBySpeed::_JPADrawCalcScaleYBySpeed(JPADrawCalcScaleYBySpeed *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcScaleYBySpeed *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcScaleYBySpeed *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcScaleXBySpeed::~JPADrawCalcScaleXBySpeed(void) */

void __thiscall JPADrawCalcScaleXBySpeed::_JPADrawCalcScaleXBySpeed(JPADrawCalcScaleXBySpeed *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcScaleXBySpeed *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcScaleXBySpeed *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcScaleY::~JPADrawCalcScaleY(void) */

void __thiscall JPADrawCalcScaleY::_JPADrawCalcScaleY(JPADrawCalcScaleY *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcScaleY *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcScaleY *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcScaleX::~JPADrawCalcScaleX(void) */

void __thiscall JPADrawCalcScaleX::_JPADrawCalcScaleX(JPADrawCalcScaleX *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcScaleX *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawCalcScaleX *)0x0) {
      *(undefined1 **)this = &JPADrawCalcParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecCallBack::~JPADrawExecCallBack(void) */

void __thiscall JPADrawExecCallBack::_JPADrawExecCallBack(JPADrawExecCallBack *this)

{
  short in_r4;
  
  if (this != (JPADrawExecCallBack *)0x0) {
    *(undefined ***)this = &__vt;
    *(undefined ***)(this + 4) = &PTR_80396768;
    if (this != (JPADrawExecCallBack *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &JPADrawExecParticleVisitor::__vt;
    }
    if (this != (JPADrawExecCallBack *)0x0) {
      *(undefined1 **)this = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecEmitterVisitor::~JPADrawExecEmitterVisitor(void) */

void __thiscall
JPADrawExecEmitterVisitor::_JPADrawExecEmitterVisitor(JPADrawExecEmitterVisitor *this)

{
  short in_r4;
  
  if ((this != (JPADrawExecEmitterVisitor *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall JPADrawExecParticleVisitor::~JPADrawExecParticleVisitor(void) */

void __thiscall
JPADrawExecParticleVisitor::_JPADrawExecParticleVisitor(JPADrawExecParticleVisitor *this)

{
  short in_r4;
  
  if ((this != (JPADrawExecParticleVisitor *)0x0) && (this->vtbl = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall JPADrawCalcTextureAnmIndexRandom::~JPADrawCalcTextureAnmIndexRandom(void) */

void __thiscall
JPADrawCalcTextureAnmIndexRandom::_JPADrawCalcTextureAnmIndexRandom
          (JPADrawCalcTextureAnmIndexRandom *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcTextureAnmIndexRandom *)0x0) {
    *(undefined1 **)this = &__vt;
    *(undefined **)(this + 4) = &DAT_803967ac;
    if (this != (JPADrawCalcTextureAnmIndexRandom *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &JPADrawCalcParticleVisitor::__vt;
    }
    if (this != (JPADrawCalcTextureAnmIndexRandom *)0x0) {
      *(undefined1 **)this = &JPADrawCalcEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcEmitterVisitor::~JPADrawCalcEmitterVisitor(void) */

void __thiscall
JPADrawCalcEmitterVisitor::_JPADrawCalcEmitterVisitor(JPADrawCalcEmitterVisitor *this)

{
  short in_r4;
  
  if ((this != (JPADrawCalcEmitterVisitor *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall JPADrawCalcTextureAnmIndexMerge::~JPADrawCalcTextureAnmIndexMerge(void) */

void __thiscall
JPADrawCalcTextureAnmIndexMerge::_JPADrawCalcTextureAnmIndexMerge
          (JPADrawCalcTextureAnmIndexMerge *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcTextureAnmIndexMerge *)0x0) {
    *(undefined1 **)this = &__vt;
    *(undefined **)(this + 4) = &DAT_803967e0;
    if (this != (JPADrawCalcTextureAnmIndexMerge *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &JPADrawCalcParticleVisitor::__vt;
    }
    if (this != (JPADrawCalcTextureAnmIndexMerge *)0x0) {
      *(undefined1 **)this = &JPADrawCalcEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcTextureAnmIndexReverse::~JPADrawCalcTextureAnmIndexReverse(void) */

void __thiscall
JPADrawCalcTextureAnmIndexReverse::_JPADrawCalcTextureAnmIndexReverse
          (JPADrawCalcTextureAnmIndexReverse *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcTextureAnmIndexReverse *)0x0) {
    *(undefined1 **)this = &__vt;
    *(undefined **)(this + 4) = &DAT_80396804;
    if (this != (JPADrawCalcTextureAnmIndexReverse *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &JPADrawCalcParticleVisitor::__vt;
    }
    if (this != (JPADrawCalcTextureAnmIndexReverse *)0x0) {
      *(undefined1 **)this = &JPADrawCalcEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcTextureAnmIndexRepeat::~JPADrawCalcTextureAnmIndexRepeat(void) */

void __thiscall
JPADrawCalcTextureAnmIndexRepeat::_JPADrawCalcTextureAnmIndexRepeat
          (JPADrawCalcTextureAnmIndexRepeat *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcTextureAnmIndexRepeat *)0x0) {
    *(undefined1 **)this = &__vt;
    *(undefined **)(this + 4) = &DAT_80396828;
    if (this != (JPADrawCalcTextureAnmIndexRepeat *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &JPADrawCalcParticleVisitor::__vt;
    }
    if (this != (JPADrawCalcTextureAnmIndexRepeat *)0x0) {
      *(undefined1 **)this = &JPADrawCalcEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcTextureAnmIndexNormal::~JPADrawCalcTextureAnmIndexNormal(void) */

void __thiscall
JPADrawCalcTextureAnmIndexNormal::_JPADrawCalcTextureAnmIndexNormal
          (JPADrawCalcTextureAnmIndexNormal *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcTextureAnmIndexNormal *)0x0) {
    *(undefined1 **)this = &__vt;
    *(undefined **)(this + 4) = &DAT_8039684c;
    if (this != (JPADrawCalcTextureAnmIndexNormal *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &JPADrawCalcParticleVisitor::__vt;
    }
    if (this != (JPADrawCalcTextureAnmIndexNormal *)0x0) {
      *(undefined1 **)this = &JPADrawCalcEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcColorAnmFrameRandom::~JPADrawCalcColorAnmFrameRandom(void) */

void __thiscall
JPADrawCalcColorAnmFrameRandom::_JPADrawCalcColorAnmFrameRandom
          (JPADrawCalcColorAnmFrameRandom *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcColorAnmFrameRandom *)0x0) {
    *(undefined1 **)this = &__vt;
    *(undefined **)(this + 4) = &DAT_80396870;
    if (this != (JPADrawCalcColorAnmFrameRandom *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &JPADrawCalcParticleVisitor::__vt;
    }
    if (this != (JPADrawCalcColorAnmFrameRandom *)0x0) {
      *(undefined1 **)this = &JPADrawCalcEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcColorAnmFrameMerge::~JPADrawCalcColorAnmFrameMerge(void) */

void __thiscall
JPADrawCalcColorAnmFrameMerge::_JPADrawCalcColorAnmFrameMerge(JPADrawCalcColorAnmFrameMerge *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcColorAnmFrameMerge *)0x0) {
    *(undefined1 **)this = &__vt;
    *(undefined **)(this + 4) = &DAT_80396894;
    if (this != (JPADrawCalcColorAnmFrameMerge *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &JPADrawCalcParticleVisitor::__vt;
    }
    if (this != (JPADrawCalcColorAnmFrameMerge *)0x0) {
      *(undefined1 **)this = &JPADrawCalcEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcColorAnmFrameReverse::~JPADrawCalcColorAnmFrameReverse(void) */

void __thiscall
JPADrawCalcColorAnmFrameReverse::_JPADrawCalcColorAnmFrameReverse
          (JPADrawCalcColorAnmFrameReverse *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcColorAnmFrameReverse *)0x0) {
    *(undefined1 **)this = &__vt;
    *(undefined **)(this + 4) = &DAT_803968b8;
    if (this != (JPADrawCalcColorAnmFrameReverse *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &JPADrawCalcParticleVisitor::__vt;
    }
    if (this != (JPADrawCalcColorAnmFrameReverse *)0x0) {
      *(undefined1 **)this = &JPADrawCalcEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcColorAnmFrameRepeat::~JPADrawCalcColorAnmFrameRepeat(void) */

void __thiscall
JPADrawCalcColorAnmFrameRepeat::_JPADrawCalcColorAnmFrameRepeat
          (JPADrawCalcColorAnmFrameRepeat *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcColorAnmFrameRepeat *)0x0) {
    *(undefined1 **)this = &__vt;
    *(undefined **)(this + 4) = &DAT_803968dc;
    if (this != (JPADrawCalcColorAnmFrameRepeat *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &JPADrawCalcParticleVisitor::__vt;
    }
    if (this != (JPADrawCalcColorAnmFrameRepeat *)0x0) {
      *(undefined1 **)this = &JPADrawCalcEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcColorAnmFrameNormal::~JPADrawCalcColorAnmFrameNormal(void) */

void __thiscall
JPADrawCalcColorAnmFrameNormal::_JPADrawCalcColorAnmFrameNormal
          (JPADrawCalcColorAnmFrameNormal *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcColorAnmFrameNormal *)0x0) {
    *(undefined1 **)this = &__vt;
    *(undefined **)(this + 4) = &DAT_80396900;
    if (this != (JPADrawCalcColorAnmFrameNormal *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &JPADrawCalcParticleVisitor::__vt;
    }
    if (this != (JPADrawCalcColorAnmFrameNormal *)0x0) {
      *(undefined1 **)this = &JPADrawCalcEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcColorEnv::~JPADrawCalcColorEnv(void) */

void __thiscall JPADrawCalcColorEnv::_JPADrawCalcColorEnv(JPADrawCalcColorEnv *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcColorEnv *)0x0) {
    *(undefined1 **)this = &__vt;
    *(undefined **)(this + 4) = &DAT_80396924;
    if (this != (JPADrawCalcColorEnv *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &JPADrawCalcParticleVisitor::__vt;
    }
    if (this != (JPADrawCalcColorEnv *)0x0) {
      *(undefined1 **)this = &JPADrawCalcEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawCalcColorPrm::~JPADrawCalcColorPrm(void) */

void __thiscall JPADrawCalcColorPrm::_JPADrawCalcColorPrm(JPADrawCalcColorPrm *this)

{
  short in_r4;
  
  if (this != (JPADrawCalcColorPrm *)0x0) {
    *(undefined ***)this = &__vt;
    *(undefined ***)(this + 4) = &PTR_80396948;
    if (this != (JPADrawCalcColorPrm *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &JPADrawCalcParticleVisitor::__vt;
    }
    if (this != (JPADrawCalcColorPrm *)0x0) {
      *(undefined1 **)this = &JPADrawCalcEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecRegisterColorChildPE::~JPADrawExecRegisterColorChildPE(void) */

void __thiscall
JPADrawExecRegisterColorChildPE::_JPADrawExecRegisterColorChildPE
          (JPADrawExecRegisterColorChildPE *this)

{
  short in_r4;
  
  if (this != (JPADrawExecRegisterColorChildPE *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecRegisterColorChildPE *)0x0) {
      *(undefined1 **)this = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecRegisterColorEmitterE::~JPADrawExecRegisterColorEmitterE(void) */

void __thiscall
JPADrawExecRegisterColorEmitterE::_JPADrawExecRegisterColorEmitterE
          (JPADrawExecRegisterColorEmitterE *this)

{
  short in_r4;
  
  if (this != (JPADrawExecRegisterColorEmitterE *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecRegisterColorEmitterE *)0x0) {
      *(undefined1 **)this = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecRegisterColorEmitterP::~JPADrawExecRegisterColorEmitterP(void) */

void __thiscall
JPADrawExecRegisterColorEmitterP::_JPADrawExecRegisterColorEmitterP
          (JPADrawExecRegisterColorEmitterP *this)

{
  short in_r4;
  
  if (this != (JPADrawExecRegisterColorEmitterP *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecRegisterColorEmitterP *)0x0) {
      *(undefined1 **)this = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecRegisterColorEmitterPE::~JPADrawExecRegisterColorEmitterPE(void) */

void __thiscall
JPADrawExecRegisterColorEmitterPE::_JPADrawExecRegisterColorEmitterPE
          (JPADrawExecRegisterColorEmitterPE *this)

{
  short in_r4;
  
  if (this != (JPADrawExecRegisterColorEmitterPE *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecRegisterColorEmitterPE *)0x0) {
      *(undefined1 **)this = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecStripeCross::~JPADrawExecStripeCross(void) */

void __thiscall JPADrawExecStripeCross::_JPADrawExecStripeCross(JPADrawExecStripeCross *this)

{
  short in_r4;
  
  if (this != (JPADrawExecStripeCross *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecStripeCross *)0x0) {
      *(undefined1 **)this = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecStripe::~JPADrawExecStripe(void) */

void __thiscall JPADrawExecStripe::_JPADrawExecStripe(JPADrawExecStripe *this)

{
  short in_r4;
  
  if (this != (JPADrawExecStripe *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecStripe *)0x0) {
      *(undefined1 **)this = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecLine::~JPADrawExecLine(void) */

void __thiscall JPADrawExecLine::_JPADrawExecLine(JPADrawExecLine *this)

{
  short in_r4;
  
  if (this != (JPADrawExecLine *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecLine *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecPoint::~JPADrawExecPoint(void) */

void __thiscall JPADrawExecPoint::_JPADrawExecPoint(JPADrawExecPoint *this)

{
  short in_r4;
  
  if (this != (JPADrawExecPoint *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecPoint *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecRotationCross::~JPADrawExecRotationCross(void) */

void __thiscall JPADrawExecRotationCross::_JPADrawExecRotationCross(JPADrawExecRotationCross *this)

{
  short in_r4;
  
  if (this != (JPADrawExecRotationCross *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecRotationCross *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecRotation::~JPADrawExecRotation(void) */

void __thiscall JPADrawExecRotation::_JPADrawExecRotation(JPADrawExecRotation *this)

{
  short in_r4;
  
  if (this != (JPADrawExecRotation *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecRotation *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecDirBillBoard::~JPADrawExecDirBillBoard(void) */

void __thiscall JPADrawExecDirBillBoard::_JPADrawExecDirBillBoard(JPADrawExecDirBillBoard *this)

{
  short in_r4;
  
  if (this != (JPADrawExecDirBillBoard *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecDirBillBoard *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecRotDirectionalCross::~JPADrawExecRotDirectionalCross(void) */

void __thiscall
JPADrawExecRotDirectionalCross::_JPADrawExecRotDirectionalCross
          (JPADrawExecRotDirectionalCross *this)

{
  short in_r4;
  
  if (this != (JPADrawExecRotDirectionalCross *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecRotDirectionalCross *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecDirectionalCross::~JPADrawExecDirectionalCross(void) */

void __thiscall
JPADrawExecDirectionalCross::_JPADrawExecDirectionalCross(JPADrawExecDirectionalCross *this)

{
  short in_r4;
  
  if (this != (JPADrawExecDirectionalCross *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecDirectionalCross *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecRotDirectional::~JPADrawExecRotDirectional(void) */

void __thiscall
JPADrawExecRotDirectional::_JPADrawExecRotDirectional(JPADrawExecRotDirectional *this)

{
  short in_r4;
  
  if (this != (JPADrawExecRotDirectional *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecRotDirectional *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecDirectional::~JPADrawExecDirectional(void) */

void __thiscall JPADrawExecDirectional::_JPADrawExecDirectional(JPADrawExecDirectional *this)

{
  short in_r4;
  
  if (this != (JPADrawExecDirectional *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecDirectional *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecRotYBillBoard::~JPADrawExecRotYBillBoard(void) */

void __thiscall JPADrawExecRotYBillBoard::_JPADrawExecRotYBillBoard(JPADrawExecRotYBillBoard *this)

{
  short in_r4;
  
  if (this != (JPADrawExecRotYBillBoard *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecRotYBillBoard *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecYBillBoard::~JPADrawExecYBillBoard(void) */

void __thiscall JPADrawExecYBillBoard::_JPADrawExecYBillBoard(JPADrawExecYBillBoard *this)

{
  short in_r4;
  
  if (this != (JPADrawExecYBillBoard *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecYBillBoard *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecRotBillBoard::~JPADrawExecRotBillBoard(void) */

void __thiscall JPADrawExecRotBillBoard::_JPADrawExecRotBillBoard(JPADrawExecRotBillBoard *this)

{
  short in_r4;
  
  if (this != (JPADrawExecRotBillBoard *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecRotBillBoard *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecBillBoard::~JPADrawExecBillBoard(void) */

void __thiscall JPADrawExecBillBoard::_JPADrawExecBillBoard(JPADrawExecBillBoard *this)

{
  short in_r4;
  
  if (this != (JPADrawExecBillBoard *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecBillBoard *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecRegisterPrmAEnv::~JPADrawExecRegisterPrmAEnv(void) */

void __thiscall
JPADrawExecRegisterPrmAEnv::_JPADrawExecRegisterPrmAEnv(JPADrawExecRegisterPrmAEnv *this)

{
  short in_r4;
  
  if (this != (JPADrawExecRegisterPrmAEnv *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecRegisterPrmAEnv *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecRegisterPrmCEnv::~JPADrawExecRegisterPrmCEnv(void) */

void __thiscall
JPADrawExecRegisterPrmCEnv::_JPADrawExecRegisterPrmCEnv(JPADrawExecRegisterPrmCEnv *this)

{
  short in_r4;
  
  if (this != (JPADrawExecRegisterPrmCEnv *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecRegisterPrmCEnv *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecRegisterEnvColorAnm::~JPADrawExecRegisterEnvColorAnm(void) */

void __thiscall
JPADrawExecRegisterEnvColorAnm::_JPADrawExecRegisterEnvColorAnm
          (JPADrawExecRegisterEnvColorAnm *this)

{
  short in_r4;
  
  if (this != (JPADrawExecRegisterEnvColorAnm *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecRegisterEnvColorAnm *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecRegisterPrmAlphaAnm::~JPADrawExecRegisterPrmAlphaAnm(void) */

void __thiscall
JPADrawExecRegisterPrmAlphaAnm::_JPADrawExecRegisterPrmAlphaAnm
          (JPADrawExecRegisterPrmAlphaAnm *this)

{
  short in_r4;
  
  if (this != (JPADrawExecRegisterPrmAlphaAnm *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecRegisterPrmAlphaAnm *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecRegisterPrmColorAnm::~JPADrawExecRegisterPrmColorAnm(void) */

void __thiscall
JPADrawExecRegisterPrmColorAnm::_JPADrawExecRegisterPrmColorAnm
          (JPADrawExecRegisterPrmColorAnm *this)

{
  short in_r4;
  
  if (this != (JPADrawExecRegisterPrmColorAnm *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecRegisterPrmColorAnm *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecSetLineWidth::~JPADrawExecSetLineWidth(void) */

void __thiscall JPADrawExecSetLineWidth::_JPADrawExecSetLineWidth(JPADrawExecSetLineWidth *this)

{
  short in_r4;
  
  if (this != (JPADrawExecSetLineWidth *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecSetLineWidth *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecSetPointSize::~JPADrawExecSetPointSize(void) */

void __thiscall JPADrawExecSetPointSize::_JPADrawExecSetPointSize(JPADrawExecSetPointSize *this)

{
  short in_r4;
  
  if (this != (JPADrawExecSetPointSize *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecSetPointSize *)0x0) {
      *(undefined1 **)this = &JPADrawExecParticleVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecLoadTexture::~JPADrawExecLoadTexture(void) */

void __thiscall JPADrawExecLoadTexture::_JPADrawExecLoadTexture(JPADrawExecLoadTexture *this)

{
  short in_r4;
  
  if (this != (JPADrawExecLoadTexture *)0x0) {
    *(undefined ***)this = &__vt;
    *(undefined ***)(this + 4) = &PTR_80396b0c;
    if (this != (JPADrawExecLoadTexture *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &JPADrawExecParticleVisitor::__vt;
    }
    if (this != (JPADrawExecLoadTexture *)0x0) {
      *(undefined1 **)this = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecLoadDefaultTexture::~JPADrawExecLoadDefaultTexture(void) */

void __thiscall
JPADrawExecLoadDefaultTexture::_JPADrawExecLoadDefaultTexture(JPADrawExecLoadDefaultTexture *this)

{
  short in_r4;
  
  if (this != (JPADrawExecLoadDefaultTexture *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecLoadDefaultTexture *)0x0) {
      *(undefined1 **)this = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecSetTexMtx::~JPADrawExecSetTexMtx(void) */

void __thiscall JPADrawExecSetTexMtx::_JPADrawExecSetTexMtx(JPADrawExecSetTexMtx *this)

{
  short in_r4;
  
  if (this != (JPADrawExecSetTexMtx *)0x0) {
    *(undefined1 **)this = &__vt;
    *(undefined **)(this + 4) = &DAT_80396b40;
    if (this != (JPADrawExecSetTexMtx *)0xfffffffc) {
      *(undefined1 **)(this + 4) = &JPADrawExecParticleVisitor::__vt;
    }
    if (this != (JPADrawExecSetTexMtx *)0x0) {
      *(undefined1 **)this = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecGenIdtMtx::~JPADrawExecGenIdtMtx(void) */

void __thiscall JPADrawExecGenIdtMtx::_JPADrawExecGenIdtMtx(JPADrawExecGenIdtMtx *this)

{
  short in_r4;
  
  if (this != (JPADrawExecGenIdtMtx *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecGenIdtMtx *)0x0) {
      *(undefined1 **)this = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecGenTexMtx0::~JPADrawExecGenTexMtx0(void) */

void __thiscall JPADrawExecGenTexMtx0::_JPADrawExecGenTexMtx0(JPADrawExecGenTexMtx0 *this)

{
  short in_r4;
  
  if (this != (JPADrawExecGenTexMtx0 *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecGenTexMtx0 *)0x0) {
      *(undefined1 **)this = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecGenPrjTexMtx::~JPADrawExecGenPrjTexMtx(void) */

void __thiscall JPADrawExecGenPrjTexMtx::_JPADrawExecGenPrjTexMtx(JPADrawExecGenPrjTexMtx *this)

{
  short in_r4;
  
  if (this != (JPADrawExecGenPrjTexMtx *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecGenPrjTexMtx *)0x0) {
      *(undefined1 **)this = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecGenPrjMtx::~JPADrawExecGenPrjMtx(void) */

void __thiscall JPADrawExecGenPrjMtx::_JPADrawExecGenPrjMtx(JPADrawExecGenPrjMtx *this)

{
  short in_r4;
  
  if (this != (JPADrawExecGenPrjMtx *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecGenPrjMtx *)0x0) {
      *(undefined1 **)this = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPADrawExecLoadExTex::~JPADrawExecLoadExTex(void) */

void __thiscall JPADrawExecLoadExTex::_JPADrawExecLoadExTex(JPADrawExecLoadExTex *this)

{
  short in_r4;
  
  if (this != (JPADrawExecLoadExTex *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JPADrawExecLoadExTex *)0x0) {
      *(undefined1 **)this = &JPADrawExecEmitterVisitor::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* [thunk]:__thiscall JPADrawExecSetTexMtx::exec(JPADrawContext const *,
                                                 JPABaseParticle *) */

void __thiscall
JPADrawExecSetTexMtx::exec
          (JPADrawExecSetTexMtx *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  exec(this + -4,param_1,param_2);
  return;
}


/* [thunk]:__thiscall JPADrawExecSetTexMtx::~JPADrawExecSetTexMtx(void) */

void __thiscall JPADrawExecSetTexMtx::_JPADrawExecSetTexMtx(JPADrawExecSetTexMtx *this)

{
  _JPADrawExecSetTexMtx(this + -4);
  return;
}


/* [thunk]:__thiscall JPADrawExecLoadTexture::exec(JPADrawContext const *,
                                                   JPABaseParticle *) */

void __thiscall
JPADrawExecLoadTexture::exec
          (JPADrawExecLoadTexture *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  exec(this + -4,param_1,param_2);
  return;
}


/* [thunk]:__thiscall JPADrawExecLoadTexture::~JPADrawExecLoadTexture(void) */

void __thiscall JPADrawExecLoadTexture::_JPADrawExecLoadTexture(JPADrawExecLoadTexture *this)

{
  _JPADrawExecLoadTexture(this + -4);
  return;
}


/* [thunk]:__thiscall JPADrawCalcColorPrm::calc(JPADrawContext const *,
                                                JPABaseParticle *) */

void __thiscall
JPADrawCalcColorPrm::calc
          (JPADrawCalcColorPrm *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  calc(this + -4,param_1,param_2);
  return;
}


/* [thunk]:__thiscall JPADrawCalcColorPrm::~JPADrawCalcColorPrm(void) */

void __thiscall JPADrawCalcColorPrm::_JPADrawCalcColorPrm(JPADrawCalcColorPrm *this)

{
  _JPADrawCalcColorPrm(this + -4);
  return;
}


/* [thunk]:__thiscall JPADrawCalcColorEnv::calc(JPADrawContext const *,
                                                JPABaseParticle *) */

void __thiscall
JPADrawCalcColorEnv::calc
          (JPADrawCalcColorEnv *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  calc(this + -4,param_1,param_2);
  return;
}


/* [thunk]:__thiscall JPADrawCalcColorEnv::~JPADrawCalcColorEnv(void) */

void __thiscall JPADrawCalcColorEnv::_JPADrawCalcColorEnv(JPADrawCalcColorEnv *this)

{
  _JPADrawCalcColorEnv(this + -4);
  return;
}


/* [thunk]:__thiscall JPADrawCalcColorAnmFrameNormal::calc(JPADrawContext const *,
                                                           JPABaseParticle *) */

void __thiscall
JPADrawCalcColorAnmFrameNormal::calc
          (JPADrawCalcColorAnmFrameNormal *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  calc(this + -4,param_1,param_2);
  return;
}


/* [thunk]:__thiscall JPADrawCalcColorAnmFrameNormal::~JPADrawCalcColorAnmFrameNormal(void) */

void __thiscall
JPADrawCalcColorAnmFrameNormal::_JPADrawCalcColorAnmFrameNormal
          (JPADrawCalcColorAnmFrameNormal *this)

{
  _JPADrawCalcColorAnmFrameNormal(this + -4);
  return;
}


/* [thunk]:__thiscall JPADrawCalcColorAnmFrameRepeat::calc(JPADrawContext const *,
                                                           JPABaseParticle *) */

void __thiscall
JPADrawCalcColorAnmFrameRepeat::calc
          (JPADrawCalcColorAnmFrameRepeat *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  calc(this + -4,param_1,param_2);
  return;
}


/* [thunk]:__thiscall JPADrawCalcColorAnmFrameRepeat::~JPADrawCalcColorAnmFrameRepeat(void) */

void __thiscall
JPADrawCalcColorAnmFrameRepeat::_JPADrawCalcColorAnmFrameRepeat
          (JPADrawCalcColorAnmFrameRepeat *this)

{
  _JPADrawCalcColorAnmFrameRepeat(this + -4);
  return;
}


/* [thunk]:__thiscall JPADrawCalcColorAnmFrameReverse::calc(JPADrawContext const *,
                                                            JPABaseParticle *) */

void __thiscall
JPADrawCalcColorAnmFrameReverse::calc
          (JPADrawCalcColorAnmFrameReverse *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  calc(this + -4,param_1,param_2);
  return;
}


/* [thunk]:__thiscall JPADrawCalcColorAnmFrameReverse::~JPADrawCalcColorAnmFrameReverse(void) */

void __thiscall
JPADrawCalcColorAnmFrameReverse::_JPADrawCalcColorAnmFrameReverse
          (JPADrawCalcColorAnmFrameReverse *this)

{
  _JPADrawCalcColorAnmFrameReverse(this + -4);
  return;
}


/* [thunk]:__thiscall JPADrawCalcColorAnmFrameMerge::calc(JPADrawContext const *,
                                                          JPABaseParticle *) */

void __thiscall
JPADrawCalcColorAnmFrameMerge::calc
          (JPADrawCalcColorAnmFrameMerge *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  calc(this + -4,param_1,param_2);
  return;
}


/* [thunk]:__thiscall JPADrawCalcColorAnmFrameMerge::~JPADrawCalcColorAnmFrameMerge(void) */

void __thiscall
JPADrawCalcColorAnmFrameMerge::_JPADrawCalcColorAnmFrameMerge(JPADrawCalcColorAnmFrameMerge *this)

{
  _JPADrawCalcColorAnmFrameMerge(this + -4);
  return;
}


/* [thunk]:__thiscall JPADrawCalcColorAnmFrameRandom::calc(JPADrawContext const *,
                                                           JPABaseParticle *) */

void __thiscall
JPADrawCalcColorAnmFrameRandom::calc
          (JPADrawCalcColorAnmFrameRandom *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  calc(this + -4,param_1,param_2);
  return;
}


/* [thunk]:__thiscall JPADrawCalcColorAnmFrameRandom::~JPADrawCalcColorAnmFrameRandom(void) */

void __thiscall
JPADrawCalcColorAnmFrameRandom::_JPADrawCalcColorAnmFrameRandom
          (JPADrawCalcColorAnmFrameRandom *this)

{
  _JPADrawCalcColorAnmFrameRandom(this + -4);
  return;
}


/* [thunk]:__thiscall JPADrawCalcTextureAnmIndexNormal::calc(JPADrawContext const *,
                                                             JPABaseParticle *) */

void __thiscall
JPADrawCalcTextureAnmIndexNormal::calc
          (JPADrawCalcTextureAnmIndexNormal *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  calc(this + -4,param_1,param_2);
  return;
}


/* [thunk]:__thiscall JPADrawCalcTextureAnmIndexNormal::~JPADrawCalcTextureAnmIndexNormal(void) */

void __thiscall
JPADrawCalcTextureAnmIndexNormal::_JPADrawCalcTextureAnmIndexNormal
          (JPADrawCalcTextureAnmIndexNormal *this)

{
  _JPADrawCalcTextureAnmIndexNormal(this + -4);
  return;
}


/* [thunk]:__thiscall JPADrawCalcTextureAnmIndexRepeat::calc(JPADrawContext const *,
                                                             JPABaseParticle *) */

void __thiscall
JPADrawCalcTextureAnmIndexRepeat::calc
          (JPADrawCalcTextureAnmIndexRepeat *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  calc(this + -4,param_1,param_2);
  return;
}


/* [thunk]:__thiscall JPADrawCalcTextureAnmIndexRepeat::~JPADrawCalcTextureAnmIndexRepeat(void) */

void __thiscall
JPADrawCalcTextureAnmIndexRepeat::_JPADrawCalcTextureAnmIndexRepeat
          (JPADrawCalcTextureAnmIndexRepeat *this)

{
  _JPADrawCalcTextureAnmIndexRepeat(this + -4);
  return;
}


/* [thunk]:__thiscall JPADrawCalcTextureAnmIndexReverse::calc(JPADrawContext const *,
                                                              JPABaseParticle *) */

void __thiscall
JPADrawCalcTextureAnmIndexReverse::calc
          (JPADrawCalcTextureAnmIndexReverse *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  calc(this + -4,param_1,param_2);
  return;
}


/* [thunk]:__thiscall JPADrawCalcTextureAnmIndexReverse::~JPADrawCalcTextureAnmIndexReverse(void) */

void __thiscall
JPADrawCalcTextureAnmIndexReverse::_JPADrawCalcTextureAnmIndexReverse
          (JPADrawCalcTextureAnmIndexReverse *this)

{
  _JPADrawCalcTextureAnmIndexReverse(this + -4);
  return;
}


/* [thunk]:__thiscall JPADrawCalcTextureAnmIndexMerge::calc(JPADrawContext const *,
                                                            JPABaseParticle *) */

void __thiscall
JPADrawCalcTextureAnmIndexMerge::calc
          (JPADrawCalcTextureAnmIndexMerge *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  calc(this + -4,param_1,param_2);
  return;
}


/* [thunk]:__thiscall JPADrawCalcTextureAnmIndexMerge::~JPADrawCalcTextureAnmIndexMerge(void) */

void __thiscall
JPADrawCalcTextureAnmIndexMerge::_JPADrawCalcTextureAnmIndexMerge
          (JPADrawCalcTextureAnmIndexMerge *this)

{
  _JPADrawCalcTextureAnmIndexMerge(this + -4);
  return;
}


/* [thunk]:__thiscall JPADrawCalcTextureAnmIndexRandom::calc(JPADrawContext const *,
                                                             JPABaseParticle *) */

void __thiscall
JPADrawCalcTextureAnmIndexRandom::calc
          (JPADrawCalcTextureAnmIndexRandom *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  calc(this + -4,param_1,param_2);
  return;
}


/* [thunk]:__thiscall JPADrawCalcTextureAnmIndexRandom::~JPADrawCalcTextureAnmIndexRandom(void) */

void __thiscall
JPADrawCalcTextureAnmIndexRandom::_JPADrawCalcTextureAnmIndexRandom
          (JPADrawCalcTextureAnmIndexRandom *this)

{
  _JPADrawCalcTextureAnmIndexRandom(this + -4);
  return;
}


/* [thunk]:__thiscall JPADrawExecCallBack::exec(JPADrawContext const *,
                                                JPABaseParticle *) */

void __thiscall
JPADrawExecCallBack::exec
          (JPADrawExecCallBack *this,JPADrawContext *param_1,JPABaseParticle *param_2)

{
  exec(this + -4,param_1,param_2);
  return;
}


/* [thunk]:__thiscall JPADrawExecCallBack::~JPADrawExecCallBack(void) */

void __thiscall JPADrawExecCallBack::_JPADrawExecCallBack(JPADrawExecCallBack *this)

{
  _JPADrawExecCallBack(this + -4);
  return;
}

