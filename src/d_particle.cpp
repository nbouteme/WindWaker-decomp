#include <d_particle.h>
#include <SComponent/c_node.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_particle.h>
#include <m_Do_ext.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <J3DGraphAnimator/J3DAnimation.h>
#include <mtx/mtx.h>
#include <d_kankyo.h>
#include <J3DGraphAnimator/J3DMaterialAttach.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <SComponent/c_list.h>
#include <J3DGraphBase/J3DPacket.h>
#include <J3DGraphBase/J3DVertex.h>
#include <JPABase/JPAMath.h>
#include <SComponent/c_lib.h>
#include <gx/GXTev.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <gx/GXLight.h>
#include <gx/GXMisc.h>
#include <gx/GXTransform.h>
#include <gx/GXAttr.h>
#include <JPADraw/JPADraw.h>
#include <d_kankyo_wether.h>
#include <SComponent/c_xyz.h>
#include <JPABase/JPAEmitter.h>
#include <mtx/mtxvec.h>
#include <gx/GXGeometry.h>
#include <J3DU/J3DUClipper.h>
#include <JPABase/JPAEmitterManager.h>
#include <JPALoader/JPAResourceManager.h>
#include <d_resorce.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <m_Do_dvd_thread.h>
#include <J3DGraphBase/J3DSys.h>
#include <gx/GXPixel.h>
#include <gx/GXBump.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s.h>
#include <d_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <f_op_actor_mng.h>
#include <d_a_sea.h>
#include <m_Do_mtx.h>
#include <d_com_static.h>
#include <dPa_smokePcallBack.h>
#include <dPa_stripesEcallBack.h>
#include <dPa_simpleData_c.h>
#include <dPa_rippleEcallBack.h>
#include <dPa_modelEmitter_c.h>
#include <dPa_trackEcallBack.h>
#include <dPa_followEcallBack.h>
#include <JPACallBackBase2<JPABaseEmitter*,JPABaseParticle*>.h>
#include <dPa_cutTurnEcallBack_c.h>
#include <dPa_modelControl_c.h>
#include <dPa_waveEcallBack.h>
#include <dPa_bombSmokeEcallBack.h>
#include <dPa_windPcallBack.h>
#include <dPa_simpleEcallBack.h>
#include <dPa_J3DmodelEmitter_c.h>
#include <dPa_control_c.h>
#include <dPa_splashEcallBack.h>
#include <dPa_J3Dmodel_c.h>
#include <dPa_setColorEcallBack.h>
#include <dPa_kageroEcallBack.h>
#include <dPa_selectTexEcallBack.h>
#include <dPa_singleRippleEcallBack.h>
#include <dPa_smokeEcallBack.h>
#include <dPa_ripplePcallBack.h>


namespace d_particle {
struct cXyz pos$5010;
}
undefined dPa_control_c;
undefined1 dPa_control_c;
undefined1 dPa_control_c;
undefined1 dPa_control_c;

namespace d_particle {
char jpcName$5165[32];
}
struct dPa_J3Dmodel_c * dPa_modelControl_c;

namespace d_particle {
undefined1 init$4530;
undefined4 l_smokePcallBack$4528;
undefined1 init$4932;
undefined4 l_windPcallBack$4930;
undefined1 init$5011;
}
struct JPAEmitterManager * dPa_control_c;
undefined1 dPa_control_c;
undefined1 dPa_control_c;
undefined1 dPa_control_c;
undefined1 dPa_control_c;
undefined1 dPa_control_c;
undefined1 dPa_control_c;
undefined1 dPa_control_c;

/* __thiscall dPa_modelEmitter_c::dPa_modelEmitter_c(void) */

void __thiscall dPa_modelEmitter_c::dPa_modelEmitter_c(dPa_modelEmitter_c *this)

{
  *(undefined1 **)(this + 0xc) = &__vt;
  SComponent::cNd_ForcedClear((node_class *)this);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dPa_J3DmodelEmitter_c::dPa_J3DmodelEmitter_c(JPABaseEmitter *,
                                                           J3DModelData *,
                                                           dKy_tevstr_c &,
                                                           J3DAnmTexPattern *,
                                                           unsigned short,
                                                           int) */

void __thiscall
dPa_J3DmodelEmitter_c::dPa_J3DmodelEmitter_c
          (dPa_J3DmodelEmitter_c *this,JPABaseEmitter *param_1,J3DModelData *param_2,
          dKy_tevstr_c *param_3,J3DAnmTexPattern *param_4,ushort param_5,int param_6)

{
  uint uVar1;
  undefined4 uVar2;
  JKRSolidHeap *pJVar3;
  int iVar4;
  ushort uVar5;
  dKy_tevstr_c *pdVar6;
  
  pdVar6 = param_3;
  dPa_modelEmitter_c::dPa_modelEmitter_c((dPa_modelEmitter_c *)this);
  *(undefined1 **)(this + 0xc) = &__vt;
  *(undefined4 *)(this + 0x28) = J3DGraphBase::j3dDefaultLightInfo;
  *(undefined4 *)(this + 0x2c) = DAT_80370d1c;
  *(undefined4 *)(this + 0x30) = DAT_80370d20;
  *(undefined4 *)(this + 0x34) = DAT_80370d24;
  *(undefined4 *)(this + 0x38) = DAT_80370d28;
  *(undefined4 *)(this + 0x3c) = DAT_80370d2c;
  this[0x40] = DAT_80370d30;
  this[0x41] = DAT_80370d31;
  this[0x42] = DAT_80370d32;
  this[0x43] = DAT_80370d33;
  *(undefined4 *)(this + 0x44) = DAT_80370d34;
  *(undefined4 *)(this + 0x48) = DAT_80370d38;
  *(undefined4 *)(this + 0x4c) = DAT_80370d3c;
  *(undefined4 *)(this + 0x50) = DAT_80370d40;
  *(undefined4 *)(this + 0x54) = DAT_80370d44;
  *(undefined4 *)(this + 0x58) = DAT_80370d48;
  *(JPABaseEmitter **)(this + 0x10) = param_1;
  *(J3DModelData **)(this + 0x18) = param_2;
  this[0x26] = SUB41(param_6,0);
  *(float *)(this + 0x28) = (param_3->mLightObj).mPos.x;
  *(float *)(this + 0x2c) = (param_3->mLightObj).mPos.y;
  *(float *)(this + 0x30) = (param_3->mLightObj).mPos.z;
  *(float *)(this + 0x34) = (param_3->mLightObj).mDir.x;
  *(float *)(this + 0x38) = (param_3->mLightObj).mDir.y;
  *(float *)(this + 0x3c) = (param_3->mLightObj).mDir.z;
  this[0x40] = *(dPa_J3DmodelEmitter_c *)&(param_3->mLightObj).mColor.r;
  this[0x41] = *(dPa_J3DmodelEmitter_c *)&(param_3->mLightObj).mColor.g;
  this[0x42] = *(dPa_J3DmodelEmitter_c *)&(param_3->mLightObj).mColor.b;
  this[0x43] = *(dPa_J3DmodelEmitter_c *)&(param_3->mLightObj).mColor.a;
  *(float *)(this + 0x44) = (param_3->mLightObj).mCosAtten.x;
  *(float *)(this + 0x48) = (param_3->mLightObj).mCosAtten.y;
  *(float *)(this + 0x4c) = (param_3->mLightObj).mCosAtten.z;
  *(float *)(this + 0x50) = (param_3->mLightObj).mDistAtten.x;
  *(float *)(this + 0x54) = (param_3->mLightObj).mDistAtten.y;
  *(float *)(this + 0x58) = (param_3->mLightObj).mDistAtten.z;
  *(float *)(this + 0x9c) = (param_3->mLightPosWorld).x;
  *(float *)(this + 0xa0) = (param_3->mLightPosWorld).y;
  *(float *)(this + 0xa4) = (param_3->mLightPosWorld).z;
  uVar2 = *(undefined4 *)&(param_3->mColorC0).b;
  *(undefined4 *)(this + 0xa8) = *(undefined4 *)&param_3->mColorC0;
  *(undefined4 *)(this + 0xac) = uVar2;
  *(_GXColor *)(this + 0xb0) = param_3->mColorK0;
  *(_GXColor *)(this + 0xb4) = param_3->mColorK1;
  uVar2 = *(undefined4 *)&(param_3->mFogColor).b;
  *(undefined4 *)(this + 0xb8) = *(undefined4 *)&param_3->mFogColor;
  *(undefined4 *)(this + 0xbc) = uVar2;
  *(float *)(this + 0xc0) = param_3->mFogStartZ;
  *(float *)(this + 0xc4) = param_3->mFogEndZ;
  *(float *)(this + 200) = param_3->mColpatBlend;
  this[0xcc] = *(dPa_J3DmodelEmitter_c *)&param_3->mInitTimer;
  this[0xcd] = *(dPa_J3DmodelEmitter_c *)&param_3->mEnvrIdxCurr;
  this[0xce] = *(dPa_J3DmodelEmitter_c *)&param_3->mEnvrIdxPrev;
  this[0xcf] = *(dPa_J3DmodelEmitter_c *)&param_3->mColpatCurr;
  this[0xd0] = *(dPa_J3DmodelEmitter_c *)&param_3->mColpatPrev;
  this[0xd1] = *(dPa_J3DmodelEmitter_c *)&param_3->mRoomNo;
  this[0xd2] = *(dPa_J3DmodelEmitter_c *)&param_3->mEnvrIdxOverride;
  this[0xd3] = *(dPa_J3DmodelEmitter_c *)&param_3->mLightMode;
  this[0xd4] = *(dPa_J3DmodelEmitter_c *)&param_3->mInitType;
  *(J3DAnmTexPattern **)(this + 0x1c) = param_4;
  if (*(int *)(this + 0x1c) == 0) {
    *(undefined4 *)(this + 0x14) = 0;
    *(undefined4 *)(this + 0x20) = 0;
  }
  else {
    uVar5 = *(ushort *)(*(int *)(this + 0x1c) + 0x1a);
    pJVar3 = m_Do_ext::mDoExt_createSolidHeapToCurrent
                       ((uint)uVar5 * 0xc + 0x10,(JKRHeap *)0x0,0,(char)pdVar6);
    *(JKRSolidHeap **)(this + 0x14) = pJVar3;
    if (*(int *)(this + 0x14) != 0) {
      uVar1 = (uint)uVar5;
      uVar2 = JKernel::operator_new__(uVar1 * 0xc + 0x10);
      uVar2 = Runtime.PPCEABI.H::__construct_new_array
                        (uVar2,J3DTexNoAnm::J3DTexNoAnm,J3DTexNoAnm::_J3DTexNoAnm,0xc,uVar1);
      *(undefined4 *)(this + 0x20) = uVar2;
      if (*(int *)(this + 0x20) != 0) {
        J3DAnmTexPattern::searchUpdateMaterialID
                  (*(J3DAnmTexPattern **)(this + 0x1c),*(J3DModelData **)(this + 0x18));
        iVar4 = *(int *)(this + 0x20);
        for (uVar5 = 0; uVar5 < uVar1; uVar5 = uVar5 + 1) {
          *(ushort *)(iVar4 + 4) = uVar5;
          *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(this + 0x1c);
          iVar4 = iVar4 + 0xc;
        }
        *(ushort *)(this + 0x24) = param_5;
      }
      m_Do_ext::mDoExt_restoreCurrentHeap();
      m_Do_ext::mDoExt_adjustSolidHeap(*(JKRSolidHeap **)(this + 0x14));
    }
  }
  param_1->mFlags = param_1->mFlags | 0x40;
  return;
}


/* __thiscall dPa_modelEmitter_c::~dPa_modelEmitter_c(void) */

void __thiscall dPa_modelEmitter_c::_dPa_modelEmitter_c(dPa_modelEmitter_c *this)

{
  short in_r4;
  
  if ((this != (dPa_modelEmitter_c *)0x0) && (*(undefined1 **)(this + 0xc) = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dPa_J3DmodelEmitter_c::~dPa_J3DmodelEmitter_c(void) */

void __thiscall dPa_J3DmodelEmitter_c::_dPa_J3DmodelEmitter_c(dPa_J3DmodelEmitter_c *this)

{
  short in_r4;
  
  if (this != (dPa_J3DmodelEmitter_c *)0x0) {
    *(undefined1 **)(this + 0xc) = &__vt;
    if (*(int *)(this + 0x14) != 0) {
      m_Do_ext::mDoExt_destroySolidHeap();
    }
    if (this != (dPa_J3DmodelEmitter_c *)0x0) {
      *(undefined1 **)(this + 0xc) = &dPa_modelEmitter_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8007ad9c) */
/* WARNING: Removing unreachable block (ram,0x8007ad8c) */
/* WARNING: Removing unreachable block (ram,0x8007ad7c) */
/* WARNING: Removing unreachable block (ram,0x8007abdc) */
/* WARNING: Removing unreachable block (ram,0x8007ad74) */
/* WARNING: Removing unreachable block (ram,0x8007ad84) */
/* WARNING: Removing unreachable block (ram,0x8007ad94) */
/* WARNING: Removing unreachable block (ram,0x8007ada4) */
/* __thiscall dPa_J3DmodelEmitter_c::draw(void) */

void __thiscall dPa_J3DmodelEmitter_c::draw(dPa_J3DmodelEmitter_c *this)

{
  float fVar1;
  dPa_J3DmodelEmitter_c dVar2;
  int iVar3;
  J3DModel *pJVar4;
  int iVar5;
  J3DModelData *in_r4;
  J3DModelData *extraout_r4;
  int *piVar6;
  undefined4 uVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  undefined8 in_f25;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  double dVar15;
  undefined8 in_f29;
  double dVar16;
  undefined8 in_f30;
  double dVar17;
  undefined8 in_f31;
  double dVar18;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  MTX34 MStack252;
  MTX34 local_cc;
  undefined4 local_98;
  uint uStack148;
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
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
  *(uint *)(*(int *)(this + 0x10) + 0x20c) = *(uint *)(*(int *)(this + 0x10) + 0x20c) & 0xfffffffb;
  iVar3 = *(int *)(this + 0x10);
  if ((int **)(iVar3 + 0x17c) != (int **)0x0) {
    mtx::PSMTXIdentity(&local_cc);
    mtx::PSMTXIdentity(&MStack252);
    dVar15 = (double)d_particle::_4264;
    dVar16 = (double)d_particle::_4269;
    dVar18 = (double)d_particle::0_0;
    dVar17 = d_particle::_4272;
    for (piVar6 = *(int **)(iVar3 + 0x17c); piVar6 != (int *)0x0; piVar6 = (int *)piVar6[3]) {
      pJVar4 = (J3DModel *)dPa_modelControl_c::newModel(*(dPa_modelControl_c **)(this + 0x18),in_r4)
      ;
      if (pJVar4 == (J3DModel *)0x0) goto LAB_8007ad74;
      iVar3 = *piVar6;
      dVar8 = (double)*(float *)(iVar3 + 0x34);
      dVar9 = (double)*(float *)(iVar3 + 0x38);
      dVar10 = (double)*(float *)(iVar3 + 0x3c);
      dVar13 = (double)((float)(dVar10 * dVar10) + (float)(dVar8 * dVar8) + (float)(dVar9 * dVar9));
      if (dVar15 < dVar13) {
        if (dVar15 < dVar13) {
          if ((double)d_particle::0_0 < dVar13) {
            fVar1 = (float)(1.0 / SQRT(dVar13));
            dVar13 = (double)(d_particle::0_5 * fVar1 *
                             (d_particle::_4268 - (float)(dVar13 * (double)(fVar1 * fVar1))));
          }
          dVar8 = (double)(float)(dVar8 * dVar13);
          dVar9 = (double)(float)(dVar9 * dVar13);
          dVar10 = (double)(float)(dVar10 * dVar13);
        }
      }
      else {
        dVar8 = (double)d_particle::0_0;
        dVar9 = (double)d_particle::1_0;
        dVar10 = dVar8;
      }
      dVar11 = (double)((float)((double)*(float *)(iVar3 + 0x90) * dVar10) -
                       (float)((double)*(float *)(iVar3 + 0x94) * dVar9));
      dVar13 = (double)((float)((double)*(float *)(iVar3 + 0x94) * dVar8) -
                       (float)((double)*(float *)(iVar3 + 0x8c) * dVar10));
      dVar12 = (double)((float)((double)*(float *)(iVar3 + 0x8c) * dVar9) -
                       (float)((double)*(float *)(iVar3 + 0x90) * dVar8));
      dVar14 = (double)((float)(dVar12 * dVar12) +
                       (float)(dVar11 * dVar11) + (float)(dVar13 * dVar13));
      if (dVar15 < dVar14) {
        if (dVar15 < dVar14) {
          if ((double)d_particle::0_0 < dVar14) {
            fVar1 = (float)(1.0 / SQRT(dVar14));
            dVar14 = (double)(d_particle::0_5 * fVar1 *
                             (d_particle::_4268 - (float)(dVar14 * (double)(fVar1 * fVar1))));
          }
          dVar11 = (double)(float)(dVar11 * dVar14);
          dVar13 = (double)(float)(dVar13 * dVar14);
          dVar12 = (double)(float)(dVar12 * dVar14);
        }
      }
      else {
        dVar11 = (double)d_particle::0_0;
        dVar12 = (double)d_particle::1_0;
        dVar13 = dVar11;
      }
      *(float *)(iVar3 + 0x8c) = (float)(dVar9 * dVar12) - (float)(dVar10 * dVar13);
      *(float *)(iVar3 + 0x90) = (float)(dVar10 * dVar11) - (float)(dVar8 * dVar12);
      *(float *)(iVar3 + 0x94) = (float)(dVar8 * dVar13) - (float)(dVar9 * dVar11);
      dVar14 = (double)(*(float *)(iVar3 + 0x94) * *(float *)(iVar3 + 0x94) +
                       *(float *)(iVar3 + 0x8c) * *(float *)(iVar3 + 0x8c) +
                       *(float *)(iVar3 + 0x90) * *(float *)(iVar3 + 0x90));
      if (dVar15 < dVar14) {
        if ((double)d_particle::0_0 < dVar14) {
          fVar1 = (float)(1.0 / SQRT(dVar14));
          dVar14 = (double)(d_particle::0_5 * fVar1 *
                           (d_particle::_4268 - (float)(dVar14 * (double)(fVar1 * fVar1))));
        }
        *(float *)(iVar3 + 0x8c) = (float)((double)*(float *)(iVar3 + 0x8c) * dVar14);
        *(float *)(iVar3 + 0x90) = (float)((double)*(float *)(iVar3 + 0x90) * dVar14);
        *(float *)(iVar3 + 0x94) = (float)((double)*(float *)(iVar3 + 0x94) * dVar14);
      }
      local_cc.m[0][0] = *(float *)(iVar3 + 0x8c);
      local_cc.m[0][1] = (float)dVar8;
      local_cc.m[0][2] = (float)dVar11;
      local_cc.m[1][0] = *(float *)(iVar3 + 0x90);
      local_cc.m[1][1] = (float)dVar9;
      local_cc.m[1][2] = (float)dVar13;
      local_cc.m[2][0] = *(float *)(iVar3 + 0x94);
      local_cc.m[2][1] = (float)dVar10;
      local_cc.m[2][2] = (float)dVar12;
      uStack148 = (uint)*(ushort *)(iVar3 + 0xc0);
      local_98 = 0x43300000;
      dVar10 = (double)(float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack148) -
                                                       dVar17));
      if (dVar10 != dVar18) {
        dVar2 = this[0x26];
        if (dVar2 == (dPa_J3DmodelEmitter_c)0x2) {
          mtx::PSMTXRotRad(&MStack252,'z',(float)((double)d_particle::_4270 * dVar10));
        }
        else {
          if ((byte)dVar2 < 2) {
            if (dVar2 == (dPa_J3DmodelEmitter_c)0x0) {
              mtx::PSMTXRotRad(&MStack252,'y',(float)((double)d_particle::_4270 * dVar10));
            }
            else {
              mtx::PSMTXRotRad(&MStack252,'x',(float)((double)d_particle::_4270 * dVar10));
            }
          }
          else {
            if ((byte)dVar2 < 4) {
              local_108 = d_particle::_4100;
              local_104 = DAT_80352a84;
              local_100 = DAT_80352a88;
              mtx::PSMTXRotAxisRad
                        ((double)(float)((double)d_particle::_4270 * dVar10),&MStack252,&local_108);
            }
          }
        }
        mtx::PSMTXConcat(&local_cc,&MStack252,&local_cc);
      }
      mtx::PSMTXConcat(&local_cc,&MStack252,&local_cc);
      local_cc.m[1][3] = *(float *)(iVar3 + 0x2c);
      local_cc.m[2][3] = *(float *)(iVar3 + 0x30);
      local_cc.m[0][3] = *(float *)(iVar3 + 0x28);
      iVar5 = *(int *)(this + 0x10);
      dVar9 = (double)(*(float *)(iVar5 + 0x1f0) * *(float *)(iVar3 + 0x9c));
      dVar8 = (double)(*(float *)(iVar5 + 500) * *(float *)(iVar3 + 0xa0));
      dVar10 = (double)(*(float *)(iVar5 + 0x1f8) * *(float *)(iVar3 + 0x9c));
      dScnKy_env_light_c::setLightTevColorType
                (&d_kankyo::g_env_light,pJVar4,(dKy_tevstr_c *)(this + 0x28));
      if ((*(int *)(this + 0x1c) != 0) && (*(int *)(this + 0x20) != 0)) {
        uStack148 = (uint)*(ushort *)(this + 0x24);
        local_98 = 0x43300000;
        *(float *)(*(int *)(this + 0x1c) + 8) =
             (float)((double)CONCAT44(0x43300000,uStack148) - d_particle::_4272);
        J3DMaterialTable::setTexNoAnimator
                  ((J3DMaterialTable *)(*(int *)(this + 0x18) + 0x58),
                   *(J3DAnmTexPattern **)(this + 0x1c),*(J3DTexNoAnm **)(this + 0x20));
      }
      (pJVar4->mBaseScale).x = (float)dVar9;
      (pJVar4->mBaseScale).y = (float)dVar8;
      (pJVar4->mBaseScale).z = (float)dVar10;
      mtx::PSMTXCopy(&local_cc,&pJVar4->mBaseMtx);
      m_Do_ext::mDoExt_modelUpdateDL(pJVar4);
      in_r4 = *(J3DModelData **)(this + 0x1c);
      if (in_r4 != (J3DModelData *)0x0) {
        J3DMaterialTable::removeTexNoAnimator
                  ((J3DMaterialTable *)(*(int *)(this + 0x18) + 0x58),(J3DAnmTexPattern *)in_r4);
        in_r4 = extraout_r4;
      }
    }
  }
  *(uint *)(*(int *)(this + 0x10) + 0x20c) = *(uint *)(*(int *)(this + 0x10) + 0x20c) | 4;
LAB_8007ad74:
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
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dPa_modelControl_c::dPa_modelControl_c(J3DModelData *) */

void __thiscall
dPa_modelControl_c::dPa_modelControl_c(dPa_modelControl_c *this,J3DModelData *param_1)

{
  undefined4 uVar1;
  ulong uVar2;
  J3DModel *pJVar3;
  int iVar4;
  dPa_J3Dmodel_c *pdVar5;
  
  uVar1 = JKernel::operator_new__(0x410);
  mModel = (dPa_J3Dmodel_c *)
           Runtime.PPCEABI.H::__construct_new_array(uVar1,dPa_J3Dmodel_c::dPa_J3Dmodel_c,0,8,0x80);
  if (mModel == (dPa_J3Dmodel_c *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_particle.cpp",0x10f,"mModel != 0");
    m_Do_printf::OSPanic("d_particle.cpp",0x10f,&DAT_80352aa7);
  }
  iVar4 = 0;
  pdVar5 = mModel;
  do {
    pJVar3 = m_Do_ext::mDoExt_J3DModel__create(param_1,0x80000,0x37221223);
    pdVar5->mpModel = pJVar3;
    if (pdVar5->mpModel == (J3DModel *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_particle.cpp",0x120,"model->mModel != 0");
      m_Do_printf::OSPanic("d_particle.cpp",0x120,&DAT_80352aa7);
    }
    iVar4 = iVar4 + 1;
    pdVar5 = pdVar5 + 1;
  } while (iVar4 < 0x80);
  SComponent::cLs_Create(&this->parent);
  return;
}


/* __thiscall dPa_J3Dmodel_c::dPa_J3Dmodel_c(void) */

void __thiscall dPa_J3Dmodel_c::dPa_J3Dmodel_c(dPa_J3Dmodel_c *this)

{
  this->mbInit = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dPa_modelControl_c::~dPa_modelControl_c(void) */

void __thiscall dPa_modelControl_c::_dPa_modelControl_c(dPa_modelControl_c *this)

{
  short in_r4;
  node_class *pnVar1;
  node_class *pnVar2;
  
  if (this != (dPa_modelControl_c *)0x0) {
    pnVar1 = (this->parent).mpHead;
    while (pnVar2 = pnVar1, pnVar2 != (node_class *)0x0) {
      pnVar1 = pnVar2->mpNextNode;
      SComponent::cLs_SingleCut(pnVar2);
      if (pnVar2 != (node_class *)0x0) {
        (*(code *)(pnVar2[1].mpPrevNode)->mpNextNode)(pnVar2,1);
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dPa_modelControl_c::newModel(J3DModelData *) */

J3DModel * __thiscall dPa_modelControl_c::newModel(dPa_modelControl_c *this,J3DModelData *param_1)

{
  ushort uVar1;
  J3DShapePacket *pJVar2;
  ushort uVar3;
  J3DMatPacket *this_00;
  J3DMaterial *pJVar4;
  J3DModel *pJVar5;
  dPa_J3Dmodel_c *pMd;
  int iVar6;
  
  iVar6 = 0x80;
  pMd = mModel;
  do {
    if (pMd->mbInit == 0) {
      pMd->mbInit = 1;
      pJVar5 = pMd->mpModel;
      pJVar5->mpModelData = (J3DModelData *)this;
      pJVar2 = pJVar5->mpShapePackets;
      for (uVar3 = 0; uVar3 < *(ushort *)&this->field_0x7c; uVar3 = uVar3 + 1) {
        pJVar2->mpShape = *(J3DShape **)(this->field_0x80 + (uint)uVar3 * 4);
        pJVar2 = pJVar2 + 1;
      }
      this_00 = pJVar5->mpMatPackets;
      for (uVar3 = 0; uVar3 < *(ushort *)&this->field_0x5c; uVar3 = uVar3 + 1) {
        pJVar4 = *(J3DMaterial **)(this->field_0x60 + (uint)uVar3 * 4);
        this_00->mpMaterial = pJVar4;
        uVar1 = pJVar4->mpShape->mShapeIdx;
        pJVar2 = pJVar5->mpShapePackets;
        this_00->mpShapePacket = pJVar2 + uVar1;
        J3DMatPacket::addShapePacket(this_00,pJVar2 + uVar1);
        this_00->mpTexture = (J3DTexture *)this->field_0x70;
        (this_00->parent).mpDLObj = pJVar4->mpDLObj;
        this_00 = this_00 + 1;
      }
      J3DVertexBuffer::setVertexData(&pJVar5->mVertexBuffer,&this->mVertexData);
      return pMd->mpModel;
    }
    pMd = pMd + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return (J3DModel *)0x0;
}


/* __thiscall dPa_modelControl_c::draw(void) */

void __thiscall dPa_modelControl_c::draw(dPa_modelControl_c *this)

{
  dPa_J3Dmodel_c *pdVar1;
  bool bVar2;
  undefined *puVar3;
  node_class *pnVar4;
  node_class *pnVar5;
  int iVar6;
  
  iVar6 = 0x80;
  pdVar1 = mModel;
  do {
    pdVar1->mbInit = 0;
    pdVar1 = pdVar1 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  d_kankyo::dKy_GxFog_set();
  pnVar4 = (this->parent).mpHead;
  while (pnVar5 = pnVar4, pnVar5 != (node_class *)0x0) {
    pnVar4 = pnVar5->mpNextNode;
    puVar3 = pnVar5[1].mpData;
    bVar2 = false;
    if (((*(uint *)(puVar3 + 0x20c) & 8) != 0) &&
       (*(int *)(puVar3 + 0x184) + *(int *)(puVar3 + 400) == 0)) {
      bVar2 = true;
    }
    if (bVar2) {
      *(uint *)(puVar3 + 0x20c) = *(uint *)(puVar3 + 0x20c) & 0xffffffbf;
      SComponent::cLs_SingleCut(pnVar5);
      if (pnVar5 != (node_class *)0x0) {
        (*(code *)(pnVar5[1].mpPrevNode)->mpNextNode)(pnVar5,1);
      }
    }
    else {
      (*(code *)pnVar5[1].mpPrevNode[1].mpPrevNode)(pnVar5);
    }
  }
  return;
}


/* __thiscall dPa_followEcallBack::dPa_followEcallBack(unsigned char,
                                                       unsigned char) */

void __thiscall
dPa_followEcallBack::dPa_followEcallBack(dPa_followEcallBack *this,byte param_1,byte param_2)

{
  (this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&::JPACallBackBase<JPABaseEmitter*>::__vt;
  (this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&::dPa_levelEcallBack::__vt;
  (this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&__vt;
  this->field_0x11 = param_1;
  this->field_0x12 = param_2;
  this->field_0x13 = 0;
  this->mpEmitter = (JPABaseEmitter *)0x0;
  return;
}


/* __thiscall dPa_followEcallBack::execute(JPABaseEmitter *) */

void __thiscall dPa_followEcallBack::execute(dPa_followEcallBack *this,JPABaseEmitter *param_1)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  bool bVar4;
  short *psVar5;
  ushort local_18 [8];
  
  if ((this->field_0x12 == '\0') && ((this->field_0x10 & 2) == 0)) {
    pfVar3 = *(float **)&this->field_0x8;
    fVar1 = pfVar3[2];
    fVar2 = pfVar3[1];
    (param_1->mGlobalTranslation).x = *pfVar3;
    (param_1->mGlobalTranslation).y = fVar2;
    (param_1->mGlobalTranslation).z = fVar1;
    psVar5 = *(short **)&this->field_0xc;
    if (psVar5 != (short *)0x0) {
      JPABase::JPAGetXYZRotateMtx
                ((int)*psVar5,(int)psVar5[1],(int)psVar5[2],&param_1->mGlobalRotation);
    }
  }
  bVar4 = false;
  if ((param_1->mFlags & 8) != 0) {
    if ((param_1->mActiveParticles).mCount + (param_1->mChildParticles).mCount == 0) {
      bVar4 = true;
    }
  }
  if (bVar4) {
    (*(code *)((this->parent).vtbl)->end)(this);
  }
  if ((this->field_0x10 & 1) != 0) {
    local_18[0] = (ushort)(param_1->mGlobalPrmColor).a;
    SComponent::cLib_chaseS(local_18,1,4);
    (param_1->mGlobalPrmColor).a = (u8)local_18[0];
  }
  return;
}


/* __thiscall dPa_followEcallBack::draw(JPABaseEmitter *) */

void __thiscall dPa_followEcallBack::draw(dPa_followEcallBack *this,JPABaseEmitter *param_1)

{
  if (param_1->mGroupID == 4) {
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dPa_followEcallBack::setup(JPABaseEmitter *,
                                         cXyz const *,
                                         csXyz const *,
                                         signed char) */

void __thiscall
dPa_followEcallBack::setup
          (dPa_followEcallBack *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,
          char param_4)

{
  (*(code *)((this->parent).vtbl)->end)();
  if (this->field_0x13 == 0) {
    this->mpEmitter = param_1;
    param_1->mFlags = param_1->mFlags | 0x40;
  }
  if (this->field_0x12 == '\0') {
    if (this->field_0x11 != '\0') {
      param_1->mMaxFrame = 0;
    }
    *(cXyz **)&this->field_0x8 = param_2;
    *(csXyz **)&this->field_0xc = param_3;
    this->field_0x10 = 0;
  }
  return;
}


/* __thiscall dPa_followEcallBack::end(void) */

void __thiscall dPa_followEcallBack::end(dPa_followEcallBack *this)

{
  JPABaseEmitter *pJVar1;
  
  pJVar1 = this->mpEmitter;
  if (pJVar1 == (JPABaseEmitter *)0x0) {
    return;
  }
  pJVar1->mMaxFrame = -1;
  pJVar1->mFlags = pJVar1->mFlags | 1;
  this->mpEmitter->mFlags = this->mpEmitter->mFlags & 0xffffffbf;
  this->mpEmitter->mpEmitterCallBack = (JPACallBackBase *)0x0;
  this->field_0x10 = this->field_0x10 | 1;
  this->mpEmitter = (JPABaseEmitter *)0x0;
  return;
}


/* __thiscall dPa_smokeEcallBack::dPa_smokeEcallBack(unsigned char) */

void __thiscall dPa_smokeEcallBack::dPa_smokeEcallBack(dPa_smokeEcallBack *this,byte param_1)

{
  undefined4 uVar1;
  u8 local_18;
  u8 uStack23;
  u8 uStack22;
  u8 uStack21;
  
  dPa_followEcallBack::dPa_followEcallBack(&this->parent,0,0);
  (this->parent).parent.vtbl = &__vt;
  uVar1 = d_particle::_4501;
  local_18 = (u8)((uint)d_particle::_4501 >> 0x18);
  (this->field_0x16).r = local_18;
  uStack23 = (u8)((uint)uVar1 >> 0x10);
  (this->field_0x16).g = uStack23;
  uStack22 = (u8)((uint)uVar1 >> 8);
  (this->field_0x16).b = uStack22;
  uStack21 = (u8)uVar1;
  (this->field_0x16).a = uStack21;
  (this->parent).field_0x11 = param_1;
  (this->parent).field_0x12 = '\0';
  this->mTevstr = (dKy_tevstr_c *)0x0;
  this->field_0x14 = -1;
  this->field_0x15 = 0;
  return;
}


/* __thiscall dPa_followEcallBack::~dPa_followEcallBack(void) */

void __thiscall dPa_followEcallBack::_dPa_followEcallBack(dPa_followEcallBack *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dPa_followEcallBack *)0x0;
  if (bVar1) {
    (this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&__vt;
    if ((bVar1) &&
       ((this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&::dPa_levelEcallBack::__vt, bVar1)) {
      (this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dPa_smokeEcallBack::dPa_smokeEcallBack(unsigned char,
                                                     unsigned char,
                                                     unsigned char,
                                                     unsigned char) */

void __thiscall
dPa_smokeEcallBack::dPa_smokeEcallBack
          (dPa_smokeEcallBack *this,uchar param_1,uchar param_2,uchar param_3,uchar param_4)

{
  undefined4 uVar1;
  u8 local_28;
  u8 uStack39;
  u8 uStack38;
  u8 uStack37;
  
  dPa_followEcallBack::dPa_followEcallBack(&this->parent,0,0);
  (this->parent).parent.vtbl = &__vt;
  uVar1 = d_particle::_4515;
  local_28 = (u8)((uint)d_particle::_4515 >> 0x18);
  (this->field_0x16).r = local_28;
  uStack39 = (u8)((uint)uVar1 >> 0x10);
  (this->field_0x16).g = uStack39;
  uStack38 = (u8)((uint)uVar1 >> 8);
  (this->field_0x16).b = uStack38;
  uStack37 = (u8)uVar1;
  (this->field_0x16).a = uStack37;
  (this->parent).field_0x11 = param_1;
  (this->parent).field_0x12 = param_2;
  (this->parent).field_0x13 = param_4;
  this->mTevstr = (dKy_tevstr_c *)0x0;
  this->field_0x14 = -1;
  (this->parent).field_0x10 = param_3;
  this->field_0x15 = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dPa_smokeEcallBack::dPa_smokeEcallBack(_GXColor const &,
                                                     dKy_tevstr_c *,
                                                     unsigned char) */

void __thiscall
dPa_smokeEcallBack::dPa_smokeEcallBack
          (dPa_smokeEcallBack *this,_GXColor *param_1,dKy_tevstr_c *param_2,uchar param_3)

{
  dPa_followEcallBack::dPa_followEcallBack(&this->parent,0,0);
  (this->parent).parent.vtbl = &__vt;
  (this->field_0x16).r = param_1->r;
  (this->field_0x16).g = param_1->g;
  (this->field_0x16).b = param_1->b;
  (this->field_0x16).a = param_1->a;
  this->mTevstr = param_2;
  (this->parent).field_0x11 = param_3;
  (this->parent).field_0x12 = '\0';
  this->field_0x14 = -1;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dPa_smokeEcallBack::setup(JPABaseEmitter *,
                                        cXyz const *,
                                        csXyz const *,
                                        signed char) */

void __thiscall
dPa_smokeEcallBack::setup
          (dPa_smokeEcallBack *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,
          char param_4)

{
  if (d_particle::init_4530 == '\0') {
    d_particle::l_smokePcallBack_4528 = &dPa_smokePcallBack::__vt;
    Runtime.PPCEABI.H::__register_global_object
              (&d_particle::l_smokePcallBack_4528,dPa_smokePcallBack::_dPa_smokePcallBack,
               &d_particle::_4529);
    d_particle::init_4530 = '\x01';
  }
  dPa_followEcallBack::setup(&this->parent,param_1,param_2,param_3,param_4);
  this->field_0x14 = param_4;
  param_1->mpParticleCallBack = (JPACallBackBase2 *)&dPa_control_c::mSmokePcallback;
  *(uint *)&param_1->field_0x210 = (uint)this->field_0x15;
  return;
}


/* __thiscall dPa_smokePcallBack::~dPa_smokePcallBack(void) */

void __thiscall dPa_smokePcallBack::_dPa_smokePcallBack(dPa_smokePcallBack *this)

{
  short in_r4;
  
  if (this != (dPa_smokePcallBack *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dPa_smokePcallBack *)0x0) {
      *(undefined1 **)this = &JPACallBackBase2<JPABaseEmitter*,JPABaseParticle*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPACallBackBase2<JPABaseEmitter *,JPABaseParticle *>::~JPACallBackBase2(void) */

JPACallBackBase2_JPABaseEmitter__JPABaseParticle__ * __thiscall
JPACallBackBase2<JPABaseEmitter*,JPABaseParticle*>::_JPACallBackBase2
          (JPACallBackBase2_JPABaseEmitter__JPABaseParticle__ *this)

{
  short in_r4;
  
  if ((this != (JPACallBackBase2_JPABaseEmitter__JPABaseParticle__ *)0x0) &&
     (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return this;
}


namespace d_particle {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Could not reconcile some variable overlaps */
/* __stdcall initiateLighting(_GXColorS10 &,
                              _GXColor &,
                              _GXColor &) */

void initiateLighting(_GXColorS10 *param_1,_GXColor *param_2,_GXColor *param_3)

{
  _GXColor local_28;
  _GXColor local_24;
  undefined4 local_20;
  _GXColorS10 local_1c;
  
  gx::GXSetChanCtrl(GX_COLOR0A0,true,GX_SRC_REG,GX_SRC_VTX,1,GX_DF_CLAMP,GX_AF_NONE);
  local_20 = d_com_inf_game::g_blackColor;
  gx::GXSetChanAmbColor(4,&local_20);
  local_1c._0_4_ = *(undefined4 *)param_1;
  local_1c._4_4_ = *(undefined4 *)&param_1->b;
  gx::GXSetTevColorS10(GX_TEVREG0,&local_1c);
  local_24 = *param_2;
  gx::GXSetTevKColor(0,&local_24);
  gx::GXSetTevKColorSel(0,0xc);
  local_28 = *param_3;
  gx::GXSetTevKColor(1,&local_28);
  gx::GXSetTevKColorSel(2,0xd);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall smokeEcallBack(JPABaseEmitter *,
                            dKy_tevstr_c *,
                            signed char,
                            _GXColor) */

void smokeEcallBack
               (JPABaseEmitter *param_1,dKy_tevstr_c *param_2,sbyte param_3,_GXColor *param_4)

{
  _GXColor local_28;
  _GXColorS10 local_24 [3];
  
  gx::GXFlush();
  gx::GXLoadNrmMtxImm(JPADraw::cb.mpViewMtx,0);
  gx::GXInvalidateVtxCache();
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_NRM,GX_CLR_RGB,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA8,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_NRM,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_CLR0,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  if (((param_1->mDraw).field_0xc2 & 1) == 0) {
    gx::GXSetNumChans(1);
    if (param_2 == (dKy_tevstr_c *)0x0) {
      local_24[0].r = d_kankyo::g_env_light.mActorC0.r;
      local_24[0].g = d_kankyo::g_env_light.mActorC0.g;
      local_24[0].b = d_kankyo::g_env_light.mActorC0.b;
      local_24[0].a = 0xff;
      local_28.r = (u8)d_kankyo::g_env_light.mActorK0.r;
      local_28.g = (u8)d_kankyo::g_env_light.mActorK0.g;
      local_28.b = (u8)d_kankyo::g_env_light.mActorK0.b;
      local_28.a = 0xff;
      initiateLighting(local_24,&local_28,param_4);
    }
    else {
      initiateLighting(&param_2->mColorC0,&param_2->mColorK0,param_4);
    }
    param_4->a = (param_1->mGlobalPrmColor).a;
    gx::GXSetNumTexGens(2);
    gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
    gx::GXSetTexCoordGen2(GX_TEXCOORD1,GX_TG_SRTG,GX_TG_COLOR0,GX_IDENTITY,false,GX_PTIDENTITY);
    JPADraw::loadTexture(&param_1->mDraw,1,1);
    gx::GXSetNumTevStages(3);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C0,GX_CC_KONST,GX_CC_TEXC,GX_CC_ZERO);
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_RASA,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD1,GX_TEXMAP1,GX_COLOR0A0);
    gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_C0,GX_CC_CPREV,GX_CC_TEXC,GX_CC_ZERO);
    gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_ZERO,GX_CA_APREV,GX_CA_TEXA,GX_CA_ZERO);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
    gx::GXSetTevColorIn(GX_TEVSTAGE2,GX_CC_ZERO,GX_CC_CPREV,GX_CC_KONST,GX_CC_ZERO);
    gx::GXSetTevColorOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE2,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_APREV);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevOrder(GX_TEVSTAGE2,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  }
  return;
}

}

/* __thiscall dPa_smokeEcallBack::draw(JPABaseEmitter *) */

void __thiscall dPa_smokeEcallBack::draw(dPa_smokeEcallBack *this,JPABaseEmitter *param_1)

{
  _GXColor local_8 [2];
  
  local_8[0] = this->field_0x16;
  d_particle::smokeEcallBack(param_1,this->mTevstr,this->field_0x14,local_8);
  return;
}


/* __thiscall dPa_smokeEcallBack::end(void) */

void __thiscall dPa_smokeEcallBack::end(dPa_smokeEcallBack *this)

{
  JPABaseEmitter *pJVar1;
  
  pJVar1 = (this->parent).mpEmitter;
  if (pJVar1 == (JPABaseEmitter *)0x0) {
    return;
  }
  pJVar1->mMaxFrame = -1;
  pJVar1->mFlags = pJVar1->mFlags | 1;
  pJVar1 = (this->parent).mpEmitter;
  pJVar1->mFlags = pJVar1->mFlags & 0xffffffbf;
  ((this->parent).mpEmitter)->mpEmitterCallBack = (JPACallBackBase *)&dPa_control_c::mSmokeEcallback
  ;
  (this->parent).field_0x10 = (this->parent).field_0x10 | 1;
  (this->parent).mpEmitter = (JPABaseEmitter *)0x0;
  return;
}


namespace d_particle {

/* __stdcall dPa_setWindPower(JPABaseParticle *) */

void dPa_setWindPower(JPABaseParticle *pPtcl)

{
  float local_38;
  cXyz local_34;
  cXyz local_28;
  cXyz local_1c;
  
  local_1c.x = (pPtcl->mGlobalPosition).x;
  local_1c.y = (pPtcl->mGlobalPosition).y;
  local_1c.z = (pPtcl->mGlobalPosition).z;
  d_kankyo_wether::dKyw_get_AllWind_vec(&local_1c,&local_28,&local_38);
  ::cXyz::operator_(&local_34,&local_28,8_0 * local_38);
  (pPtcl->mGlobalPosition).x = local_1c.x + local_34.x;
  (pPtcl->mGlobalPosition).y = local_1c.y + local_34.y;
  (pPtcl->mGlobalPosition).z = local_1c.z + local_34.z;
  return;
}

}

/* __thiscall dPa_smokePcallBack::execute(JPABaseEmitter *,
                                          JPABaseParticle *) */

dPa_smokePcallBack * __thiscall
dPa_smokePcallBack::execute
          (dPa_smokePcallBack *this,JPABaseEmitter *param_1,JPABaseParticle *param_2)

{
  if (*(int *)&param_1->field_0x210 == 0) {
    this = (dPa_smokePcallBack *)d_particle::dPa_setWindPower(param_2);
  }
  return this;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8007c358) */
/* WARNING: Removing unreachable block (ram,0x8007c348) */
/* WARNING: Removing unreachable block (ram,0x8007c338) */
/* WARNING: Removing unreachable block (ram,0x8007c328) */
/* WARNING: Removing unreachable block (ram,0x8007c318) */
/* WARNING: Removing unreachable block (ram,0x8007c308) */
/* WARNING: Removing unreachable block (ram,0x8007c2f8) */
/* WARNING: Removing unreachable block (ram,0x8007c2e8) */
/* WARNING: Removing unreachable block (ram,0x8007c2d8) */
/* WARNING: Removing unreachable block (ram,0x8007c2e0) */
/* WARNING: Removing unreachable block (ram,0x8007c2f0) */
/* WARNING: Removing unreachable block (ram,0x8007c300) */
/* WARNING: Removing unreachable block (ram,0x8007c310) */
/* WARNING: Removing unreachable block (ram,0x8007c320) */
/* WARNING: Removing unreachable block (ram,0x8007c330) */
/* WARNING: Removing unreachable block (ram,0x8007c340) */
/* WARNING: Removing unreachable block (ram,0x8007c350) */
/* WARNING: Removing unreachable block (ram,0x8007c360) */
/* __thiscall dPa_smokePcallBack::draw(JPABaseEmitter *,
                                       JPABaseParticle *) */

void __thiscall
dPa_smokePcallBack::draw(dPa_smokePcallBack *this,JPABaseEmitter *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  u8 uVar2;
  MTX34 *pMVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f14;
  double dVar9;
  undefined8 in_f15;
  double dVar10;
  double dVar11;
  undefined8 in_f16;
  double dVar12;
  undefined8 in_f17;
  double dVar13;
  undefined8 in_f18;
  undefined8 in_f19;
  undefined8 in_f20;
  undefined8 in_f21;
  undefined8 in_f22;
  undefined8 in_f23;
  undefined8 in_f24;
  double dVar14;
  undefined8 in_f25;
  double dVar15;
  undefined8 in_f26;
  double dVar16;
  undefined8 in_f27;
  double dVar17;
  undefined8 in_f28;
  double dVar18;
  undefined8 in_f29;
  double dVar19;
  double dVar20;
  undefined8 in_f30;
  double dVar21;
  double dVar22;
  undefined8 in_f31;
  double dVar23;
  double dVar24;
  cXyz local_168;
  undefined4 local_158;
  uint uStack340;
  undefined4 local_150;
  uint uStack332;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  float local_134;
  undefined auStack280 [16];
  undefined auStack264 [16];
  undefined auStack248 [16];
  undefined auStack232 [16];
  undefined auStack216 [16];
  undefined auStack200 [16];
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
  
  uVar5 = 0;
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
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  __psq_st0(auStack216,(int)((ulonglong)in_f18 >> 0x20),0);
  __psq_st1(auStack216,(int)in_f18,0);
  __psq_st0(auStack232,(int)((ulonglong)in_f17 >> 0x20),0);
  __psq_st1(auStack232,(int)in_f17,0);
  __psq_st0(auStack248,(int)((ulonglong)in_f16 >> 0x20),0);
  __psq_st1(auStack248,(int)in_f16,0);
  __psq_st0(auStack264,(int)((ulonglong)in_f15 >> 0x20),0);
  __psq_st1(auStack264,(int)in_f15,0);
  __psq_st0(auStack280,(int)((ulonglong)in_f14 >> 0x20),0);
  __psq_st1(auStack280,(int)in_f14,0);
  local_168.x = (param_2->mPosition).x;
  local_168.y = (param_2->mPosition).y;
  local_168.z = (param_2->mPosition).z;
  iVar4 = (int)(uint)(ushort)param_2->mRotateAngle >> (JKernel::JMath::jmaSinShift & 0x3f);
  dVar21 = (double)JKernel::JMath::jmaSinTable[iVar4];
  dVar19 = (double)JKernel::JMath::jmaCosTable[iVar4];
  dVar10 = (double)(d_particle::2_0 * param_2->mScaleX * JPADraw::cb.mGlobalScale2D[0]);
  dVar23 = (double)(d_particle::2_0 * param_2->mScaleY * JPADraw::cb.mGlobalScale2D[1]);
  uStack340 = JPABaseEmitter::getPivotX(param_1);
  uStack340 = uStack340 & 0xff;
  local_158 = 0x43300000;
  dVar9 = -(double)(d_particle::0_5 *
                   (float)(dVar10 * (double)(float)((double)CONCAT44(0x43300000,uStack340) -
                                                   d_particle::_4272)));
  dVar11 = (double)(float)(dVar10 + dVar9);
  uStack332 = JPABaseEmitter::getPivotY(param_1);
  pMVar3 = JPADraw::cb.mpViewMtx;
  uStack332 = uStack332 & 0xff;
  local_150 = 0x43300000;
  dVar12 = -(double)(d_particle::0_5 *
                    (float)(dVar23 * (double)(float)((double)CONCAT44(0x43300000,uStack332) -
                                                    d_particle::_4272)));
  dVar13 = (double)(float)(dVar23 + dVar12);
  uVar2 = (param_1->mGlobalPrmColor).a;
  mtx::PSMTXMultVec(JPADraw::cb.mpViewMtx,&local_168,&local_168);
  dVar10 = (double)local_168.x;
  dVar18 = (double)(float)((double)((float)(dVar19 * dVar9) - (float)(dVar21 * dVar13)) + dVar10);
  dVar23 = (double)local_168.y;
  dVar17 = (double)(float)((double)((float)(dVar19 * dVar13) + (float)(dVar21 * dVar9)) + dVar23);
  dVar24 = (double)local_168.z;
  local_134 = (float)((double)((float)(dVar19 * dVar11) - (float)(dVar21 * dVar13)) + dVar10);
  local_138 = (float)((double)((float)(dVar19 * dVar13) + (float)(dVar21 * dVar11)) + dVar23);
  local_13c = (float)((double)((float)(dVar19 * dVar11) - (float)(dVar21 * dVar12)) + dVar10);
  local_140 = (float)((double)((float)(dVar19 * dVar12) + (float)(dVar21 * dVar11)) + dVar23);
  local_144 = (float)((double)((float)(dVar19 * dVar9) - (float)(dVar21 * dVar12)) + dVar10);
  local_148 = (float)((double)((float)(dVar19 * dVar12) + (float)(dVar21 * dVar9)) + dVar23);
  dVar20 = (double)(float)((double)pMVar3->m[3] - dVar10);
  dVar22 = (double)(float)((double)pMVar3->m[1][3] - dVar23);
  dVar16 = (double)(float)((double)pMVar3->m[2][3] - dVar24);
  dVar15 = (double)(float)(dVar18 - dVar10);
  dVar14 = (double)(float)(dVar17 - dVar23);
  dVar9 = (double)(float)(dVar24 - dVar24);
  dVar21 = (double)(float)((double)local_134 - dVar10);
  dVar19 = (double)(float)((double)local_138 - dVar23);
  dVar13 = (double)(float)((double)local_13c - dVar10);
  dVar12 = (double)(float)((double)local_140 - dVar23);
  dVar11 = (double)(float)((double)local_144 - dVar10);
  dVar23 = (double)(float)((double)local_148 - dVar23);
  dVar10 = (double)((float)(dVar16 * dVar16) + (float)(dVar20 * dVar20) + (float)(dVar22 * dVar22));
  if ((double)d_particle::_4264 < dVar10) {
    if ((double)d_particle::0_0 < dVar10) {
      fVar1 = (float)(1.0 / SQRT(dVar10));
      dVar10 = (double)(d_particle::0_5 * fVar1 *
                       (d_particle::_4268 - (float)(dVar10 * (double)(fVar1 * fVar1))));
    }
    dVar20 = (double)(float)(dVar20 * dVar10);
    dVar22 = (double)(float)(dVar22 * dVar10);
    dVar16 = (double)(float)(dVar16 * dVar10);
  }
  dVar6 = (double)((float)(dVar9 * dVar9) + (float)(dVar15 * dVar15) + (float)(dVar14 * dVar14));
  dVar10 = dVar9;
  if ((double)d_particle::_4264 < dVar6) {
    if ((double)d_particle::0_0 < dVar6) {
      fVar1 = (float)(1.0 / SQRT(dVar6));
      dVar6 = (double)(d_particle::0_5 * fVar1 *
                      (d_particle::_4268 - (float)(dVar6 * (double)(fVar1 * fVar1))));
    }
    dVar15 = (double)(float)(dVar15 * dVar6);
    dVar14 = (double)(float)(dVar14 * dVar6);
    dVar10 = (double)(float)(dVar9 * dVar6);
  }
  dVar7 = (double)((float)(dVar9 * dVar9) + (float)(dVar21 * dVar21) + (float)(dVar19 * dVar19));
  dVar6 = dVar9;
  if ((double)d_particle::_4264 < dVar7) {
    if ((double)d_particle::0_0 < dVar7) {
      fVar1 = (float)(1.0 / SQRT(dVar7));
      dVar7 = (double)(d_particle::0_5 * fVar1 *
                      (d_particle::_4268 - (float)(dVar7 * (double)(fVar1 * fVar1))));
    }
    dVar21 = (double)(float)(dVar21 * dVar7);
    dVar19 = (double)(float)(dVar19 * dVar7);
    dVar6 = (double)(float)(dVar9 * dVar7);
  }
  dVar8 = (double)((float)(dVar9 * dVar9) + (float)(dVar13 * dVar13) + (float)(dVar12 * dVar12));
  dVar7 = dVar9;
  if ((double)d_particle::_4264 < dVar8) {
    if ((double)d_particle::0_0 < dVar8) {
      fVar1 = (float)(1.0 / SQRT(dVar8));
      dVar8 = (double)(d_particle::0_5 * fVar1 *
                      (d_particle::_4268 - (float)(dVar8 * (double)(fVar1 * fVar1))));
    }
    dVar13 = (double)(float)(dVar13 * dVar8);
    dVar12 = (double)(float)(dVar12 * dVar8);
    dVar7 = (double)(float)(dVar9 * dVar8);
  }
  dVar8 = (double)((float)(dVar9 * dVar9) + (float)(dVar11 * dVar11) + (float)(dVar23 * dVar23));
  if ((double)d_particle::_4264 < dVar8) {
    if ((double)d_particle::0_0 < dVar8) {
      fVar1 = (float)(1.0 / SQRT(dVar8));
      dVar8 = (double)(d_particle::0_5 * fVar1 *
                      (d_particle::_4268 - (float)(dVar8 * (double)(fVar1 * fVar1))));
    }
    dVar11 = (double)(float)(dVar11 * dVar8);
    dVar23 = (double)(float)(dVar23 * dVar8);
    dVar9 = (double)(float)(dVar9 * dVar8);
  }
  gx::GXBegin(0xa0,0,6);
  write_volatile_4(0xcc008000,local_168.x);
  write_volatile_4(0xcc008000,local_168.y);
  write_volatile_4(0xcc008000,local_168.z);
  write_volatile_4(0xcc008000,(float)dVar20);
  write_volatile_4(0xcc008000,(float)dVar22);
  write_volatile_4(0xcc008000,(float)dVar16);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,uVar2);
  write_volatile_4(0xcc008000,d_particle::0_5);
  write_volatile_4(0xcc008000,d_particle::0_5);
  write_volatile_4(0xcc008000,(float)dVar18);
  write_volatile_4(0xcc008000,(float)dVar17);
  write_volatile_4(0xcc008000,(float)dVar24);
  write_volatile_4(0xcc008000,(float)dVar15);
  write_volatile_4(0xcc008000,(float)dVar14);
  write_volatile_4(0xcc008000,(float)dVar10);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,uVar2);
  write_volatile_4(0xcc008000,d_particle::0_0);
  write_volatile_4(0xcc008000,d_particle::0_0);
  write_volatile_4(0xcc008000,local_134);
  write_volatile_4(0xcc008000,local_138);
  write_volatile_4(0xcc008000,(float)dVar24);
  write_volatile_4(0xcc008000,(float)dVar21);
  write_volatile_4(0xcc008000,(float)dVar19);
  write_volatile_4(0xcc008000,(float)dVar6);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,uVar2);
  write_volatile_4(0xcc008000,d_particle::1_0);
  write_volatile_4(0xcc008000,d_particle::0_0);
  write_volatile_4(0xcc008000,local_13c);
  write_volatile_4(0xcc008000,local_140);
  write_volatile_4(0xcc008000,(float)dVar24);
  write_volatile_4(0xcc008000,(float)dVar13);
  write_volatile_4(0xcc008000,(float)dVar12);
  write_volatile_4(0xcc008000,(float)dVar7);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,uVar2);
  write_volatile_4(0xcc008000,d_particle::1_0);
  write_volatile_4(0xcc008000,d_particle::1_0);
  write_volatile_4(0xcc008000,local_144);
  write_volatile_4(0xcc008000,local_148);
  write_volatile_4(0xcc008000,(float)dVar24);
  write_volatile_4(0xcc008000,(float)dVar11);
  write_volatile_4(0xcc008000,(float)dVar23);
  write_volatile_4(0xcc008000,(float)dVar9);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,uVar2);
  write_volatile_4(0xcc008000,d_particle::0_0);
  write_volatile_4(0xcc008000,d_particle::1_0);
  write_volatile_4(0xcc008000,(float)dVar18);
  write_volatile_4(0xcc008000,(float)dVar17);
  write_volatile_4(0xcc008000,(float)dVar24);
  write_volatile_4(0xcc008000,(float)dVar15);
  write_volatile_4(0xcc008000,(float)dVar14);
  write_volatile_4(0xcc008000,(float)dVar10);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,0xff);
  write_volatile_1(DAT_cc008000,uVar2);
  write_volatile_4(0xcc008000,d_particle::0_0);
  write_volatile_4(0xcc008000,d_particle::0_0);
  param_2->mFlags = param_2->mFlags | 8;
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  __psq_l0(auStack56,uVar5);
  __psq_l1(auStack56,uVar5);
  __psq_l0(auStack72,uVar5);
  __psq_l1(auStack72,uVar5);
  __psq_l0(auStack88,uVar5);
  __psq_l1(auStack88,uVar5);
  __psq_l0(auStack104,uVar5);
  __psq_l1(auStack104,uVar5);
  __psq_l0(auStack120,uVar5);
  __psq_l1(auStack120,uVar5);
  __psq_l0(auStack136,uVar5);
  __psq_l1(auStack136,uVar5);
  __psq_l0(auStack152,uVar5);
  __psq_l1(auStack152,uVar5);
  __psq_l0(auStack168,uVar5);
  __psq_l1(auStack168,uVar5);
  __psq_l0(auStack184,uVar5);
  __psq_l1(auStack184,uVar5);
  __psq_l0(auStack200,uVar5);
  __psq_l1(auStack200,uVar5);
  __psq_l0(auStack216,uVar5);
  __psq_l1(auStack216,uVar5);
  __psq_l0(auStack232,uVar5);
  __psq_l1(auStack232,uVar5);
  __psq_l0(auStack248,uVar5);
  __psq_l1(auStack248,uVar5);
  __psq_l0(auStack264,uVar5);
  __psq_l1(auStack264,uVar5);
  __psq_l0(auStack280,uVar5);
  __psq_l1(auStack280,uVar5);
  return;
}


/* __thiscall dPa_selectTexEcallBack::draw(JPABaseEmitter *) */

void __thiscall dPa_selectTexEcallBack::draw(dPa_selectTexEcallBack *this,JPABaseEmitter *param_1)

{
  JPADraw::loadTexture(&param_1->mDraw,(byte)this[4],0);
  return;
}


/* __thiscall dPa_simpleEcallBack::dPa_simpleEcallBack(void) */

void __thiscall dPa_simpleEcallBack::dPa_simpleEcallBack(dPa_simpleEcallBack *this)

{
  this->vtbl = &::JPACallBackBase<JPABaseEmitter*>::__vt;
  this->vtbl = &__vt;
  Runtime.PPCEABI.H::__construct_array
            (this->mSimpleData,dPa_simpleData_c::dPa_simpleData_c,
             dPa_simpleData_c::_dPa_simpleData_c,0x14,0x20);
  this->mpBaseEmitter = (JPABaseEmitter *)0x0;
  this->mCount = 0;
  return;
}


/* __thiscall dPa_simpleData_c::~dPa_simpleData_c(void) */

void __thiscall dPa_simpleData_c::_dPa_simpleData_c(dPa_simpleData_c *this)

{
  short in_r4;
  
  if ((this != (dPa_simpleData_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dPa_simpleData_c::dPa_simpleData_c(void) */

void __thiscall dPa_simpleData_c::dPa_simpleData_c(dPa_simpleData_c *this)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dPa_simpleEcallBack::executeAfter(JPABaseEmitter *) */

void __thiscall dPa_simpleEcallBack::executeAfter(dPa_simpleEcallBack *this,JPABaseEmitter *pEmtr)

{
  u8 uVar1;
  u8 uVar2;
  byte bVar3;
  byte bVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  JPABaseParticle *pParticle;
  int iVar9;
  dPa_simpleData_c *pSimple;
  cXyz local_38;
  
  iVar7 = JPABaseEmitter::emtrInfo.mVolumeEmitCount;
  if (JPABaseEmitter::emtrInfo.mVolumeEmitCount < 1) {
    this->mCount = 0;
  }
  else {
    pSimple = this->mSimpleData;
    pEmtr->mFlags = pEmtr->mFlags & 0xfffffffe;
    while (this->mCount != 0) {
      local_38.x = (pSimple->mPos).x;
      local_38.y = (pSimple->mPos).y;
      local_38.z = (pSimple->mPos).z;
      uVar8 = J3DUClipper::clip(&mDoLib_clipper::mClipper,&J3DGraphBase::j3dSys.mCurViewMtx,
                                &local_38,d_particle::_4971);
      if (uVar8 == 0) {
        fVar5 = (pSimple->mPos).z;
        fVar6 = (pSimple->mPos).y;
        (pEmtr->mGlobalTranslation).x = (pSimple->mPos).x;
        (pEmtr->mGlobalTranslation).y = fVar6;
        (pEmtr->mGlobalTranslation).z = fVar5;
        uVar1 = (pSimple->mPrmColor).b;
        uVar2 = (pSimple->mPrmColor).g;
        (pEmtr->mGlobalPrmColor).r = (pSimple->mPrmColor).r;
        (pEmtr->mGlobalPrmColor).g = uVar2;
        (pEmtr->mGlobalPrmColor).b = uVar1;
        (pEmtr->mGlobalPrmColor).a = (pSimple->mPrmColor).a;
        bVar3 = pSimple->mEnvColor[2];
        bVar4 = pSimple->mEnvColor[1];
        (pEmtr->mGlobalEnvColor).r = pSimple->mEnvColor[0];
        (pEmtr->mGlobalEnvColor).g = bVar4;
        (pEmtr->mGlobalEnvColor).b = bVar3;
        iVar9 = 0;
        while ((iVar9 < iVar7 &&
               (pParticle = (JPABaseParticle *)JPABaseEmitter::createParticle(pEmtr),
               pParticle != (JPABaseParticle *)0x0))) {
          fVar5 = (pSimple->mPos).z;
          fVar6 = (pSimple->mPos).y;
          (pParticle->mGlobalPosition).x = (pSimple->mPos).x;
          (pParticle->mGlobalPosition).y = fVar6;
          (pParticle->mGlobalPosition).z = fVar5;
          if (pSimple->mbAffectedByWind != 0) {
            if (d_particle::init_4932 == '\0') {
              d_particle::l_windPcallBack_4930 = &dPa_windPcallBack::__vt;
              Runtime.PPCEABI.H::__register_global_object
                        (&d_particle::l_windPcallBack_4930,dPa_windPcallBack::_dPa_windPcallBack,
                         &d_particle::_4931);
              d_particle::init_4932 = '\x01';
            }
            pParticle->mpCallBack2 = (JPACallBackBase2 *)&d_particle::l_windPcallBack_4930;
          }
          iVar9 = iVar9 + 1;
        }
      }
      this->mCount = this->mCount + -1;
      pSimple = pSimple + 1;
    }
  }
  pEmtr->mFlags = pEmtr->mFlags | 1;
  return;
}


/* __thiscall dPa_windPcallBack::~dPa_windPcallBack(void) */

void __thiscall dPa_windPcallBack::_dPa_windPcallBack(dPa_windPcallBack *this)

{
  short in_r4;
  
  if (this != (dPa_windPcallBack *)0x0) {
    (this->parent).vtbl = &__vt;
    if (this != (dPa_windPcallBack *)0x0) {
      (this->parent).vtbl = &JPACallBackBase2<JPABaseEmitter*,JPABaseParticle*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dPa_simpleEcallBack::draw(JPABaseEmitter *) */

void __thiscall dPa_simpleEcallBack::draw(dPa_simpleEcallBack *this,JPABaseEmitter *pPtcl)

{
  _GXColor local_14;
  
  if (this->mbIsSmoke != 0) {
    local_14 = d_particle::_4982;
    d_particle::smokeEcallBack(pPtcl,(dKy_tevstr_c *)0x0,-1,&local_14);
  }
  if (pPtcl->mGroupID == 4) {
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A0);
  }
  return;
}


/* __thiscall dPa_simpleEcallBack::create(JPAEmitterManager *,
                                          unsigned short,
                                          unsigned char) */

JPABaseEmitter * __thiscall
dPa_simpleEcallBack::create
          (dPa_simpleEcallBack *this,JPAEmitterManager *param_1,ushort param_2,uchar param_3)

{
  int iVar1;
  
  this->mpBaseEmitter = (JPABaseEmitter *)0x0;
  this->mGrpID = param_3;
  this->mResID = param_2;
  iVar1 = createEmitter(this,param_1);
  if (iVar1 != 0) {
    if ((param_2 == 0xa06a) || (param_2 == 42000)) {
      this->mbIsSmoke = 1;
      this->mpBaseEmitter->mpParticleCallBack = (JPACallBackBase2 *)&dPa_control_c::mSmokePcallback;
    }
    else {
      this->mbIsSmoke = 0;
    }
  }
  return this->mpBaseEmitter;
}


/* __thiscall dPa_simpleEcallBack::createEmitter(JPAEmitterManager *) */

JPABaseEmitter * __thiscall
dPa_simpleEcallBack::createEmitter(dPa_simpleEcallBack *this,JPAEmitterManager *param_1)

{
  uchar rmID;
  JPABaseEmitter *pJVar1;
  
  if (this->mpBaseEmitter == (JPABaseEmitter *)0x0) {
    if (d_particle::init_5011 == '\0') {
      d_particle::pos_5010.x = d_particle::0_0;
      d_particle::pos_5010.y = d_particle::0_0;
      d_particle::pos_5010.z = d_particle::0_0;
      d_particle::init_5011 = '\x01';
    }
    rmID = dPa_control_c::getRM_ID(this->mResID);
    pJVar1 = JPAEmitterManager::createSimpleEmitterID
                       (param_1,(TVec3_float_ *)&d_particle::pos_5010,this->mResID,this->mGrpID,rmID
                        ,(JPACallBackBase *)0x0,(JPACallBackBase2 *)0x0);
    this->mpBaseEmitter = pJVar1;
    if (this->mpBaseEmitter == (JPABaseEmitter *)0x0) {
      return (JPABaseEmitter *)0x0;
    }
    this->mpBaseEmitter->mpEmitterCallBack = (JPACallBackBase *)this;
    this->mpBaseEmitter->mMaxFrame = 0;
    this->mpBaseEmitter->mFlags = this->mpBaseEmitter->mFlags | 1;
  }
  return this->mpBaseEmitter;
}


/* __thiscall dPa_simpleEcallBack::set(cXyz const *,
                                       unsigned char,
                                       _GXColor const &,
                                       _GXColor const &,
                                       int) */

int __thiscall
dPa_simpleEcallBack::set
          (dPa_simpleEcallBack *this,cXyz *pos,uchar alpha,_GXColor *pPrmColor,_GXColor *pEnvColor,
          int bAffectedByWind)

{
  dPa_simpleData_c *pdVar1;
  
  if (0x1f < this->mCount) {
    return 0;
  }
  pdVar1 = this->mSimpleData + this->mCount;
  (pdVar1->mPos).x = pos->x;
  (pdVar1->mPos).y = pos->y;
  (pdVar1->mPos).z = pos->z;
  (pdVar1->mPrmColor).r = pPrmColor->r;
  (pdVar1->mPrmColor).g = pPrmColor->g;
  (pdVar1->mPrmColor).b = pPrmColor->b;
  (pdVar1->mPrmColor).a = alpha;
  pdVar1->mEnvColor[0] = pEnvColor->r;
  pdVar1->mEnvColor[1] = pEnvColor->g;
  pdVar1->mEnvColor[2] = pEnvColor->b;
  pdVar1->mbAffectedByWind = (byte)bAffectedByWind;
  this->mCount = this->mCount + 1;
  return 1;
}


/* __thiscall dPa_windPcallBack::execute(JPABaseEmitter *,
                                         JPABaseParticle *) */

void __thiscall
dPa_windPcallBack::execute(dPa_windPcallBack *this,JPABaseEmitter *param_1,JPABaseParticle *param_2)

{
  d_particle::dPa_setWindPower(param_2);
  return;
}


/* __thiscall dPa_control_c::dPa_control_c(void) */

void __thiscall dPa_control_c::dPa_control_c(dPa_control_c *this)

{
  JKRHeap *pJVar1;
  ulong uVar2;
  code *pcVar3;
  undefined uVar4;
  
  pcVar3 = dPa_simpleEcallBack::_dPa_simpleEcallBack;
  uVar4 = 0x90;
  Runtime.PPCEABI.H::__construct_array
            (this->mSimpleCallbacks,dPa_simpleEcallBack::dPa_simpleEcallBack,
             dPa_simpleEcallBack::_dPa_simpleEcallBack,0x290,0x19);
  pJVar1 = m_Do_ext::mDoExt_createSolidHeapFromSystem(0x16e800,0,pcVar3,(bool)uVar4);
  this->mpHeap = pJVar1;
  if (this->mpHeap == (JKRHeap *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_particle.cpp",0x4d8,"mHeap != 0");
    m_Do_printf::OSPanic("d_particle.cpp",0x4d8,&DAT_80352aa7);
  }
  this->mSceneNo = 0xff;
  this->mCount = 0;
  mEmitterMng = (JPAEmitterManager *)0x0;
  this->mNumSimple = 0;
  this->mpCommonResMgr = (JPAResourceManager *)0x0;
  this->mpSceneResMgr = (JPAResourceManager *)0x0;
  return;
}


/* __thiscall dPa_simpleEcallBack::~dPa_simpleEcallBack(void) */

void __thiscall dPa_simpleEcallBack::_dPa_simpleEcallBack(dPa_simpleEcallBack *this)

{
  short in_r4;
  
  if (this != (dPa_simpleEcallBack *)0x0) {
    this->vtbl = &__vt;
    Runtime.PPCEABI.H::__destroy_arr
              (this->mSimpleData,dPa_simpleData_c::_dPa_simpleData_c,0x14,0x20);
    if (this != (dPa_simpleEcallBack *)0x0) {
      this->vtbl = &::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace dPa_control_c {

/* __thiscall getRM_ID(unsigned short) */

ushort getRM_ID(ushort userID)

{
  return userID >> 0xf;
}

}

/* __thiscall dPa_control_c::swapFrameBufferTexture(void) */

void __thiscall dPa_control_c::swapFrameBufferTexture(dPa_control_c *this)

{
  if (this->mpCommonResMgr != (JPAResourceManager *)0x0) {
    JPAResourceManager::swapTexture
              (this->mpCommonResMgr,mDoGph_gInf_c::mFrameBufferTimg,"AK_kagerouSwap00");
  }
  if (this->mpSceneResMgr != (JPAResourceManager *)0x0) {
    JPAResourceManager::swapTexture
              (this->mpSceneResMgr,mDoGph_gInf_c::mFrameBufferTimg,"AK_kagerouSwap00");
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dPa_control_c::createCommon(void const *) */

void __thiscall dPa_control_c::createCommon(dPa_control_c *this,void *param_1)

{
  ushort uVar1;
  byte bVar2;
  JPAResourceManager *this_00;
  ulong uVar3;
  JPAEmitterManager *this_01;
  undefined4 uVar4;
  dPa_modelControl_c *this_02;
  J3DModelData *pJVar5;
  char cVar6;
  ushort uVar7;
  
  this_00 = (JPAResourceManager *)JKernel::operator_new(0xc,this->mpHeap,0);
  if (this_00 != (JPAResourceManager *)0x0) {
    JPAResourceManager::JPAResourceManager(this_00,param_1,this->mpHeap);
  }
  this->mpCommonResMgr = this_00;
  if (this->mpCommonResMgr == (JPAResourceManager *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_particle.cpp",0x521,"mCommonResMng != 0");
    m_Do_printf::OSPanic("d_particle.cpp",0x521,&DAT_80352aa7);
  }
  JPAResourceManager::swapTexture
            (this->mpCommonResMgr,mDoGph_gInf_c::mFrameBufferTimg,"AK_kagerouSwap00");
  this_01 = (JPAEmitterManager *)JKernel::operator_new(0x110,this->mpHeap,0);
  if (this_01 != (JPAEmitterManager *)0x0) {
    JPAEmitterManager::JPAEmitterManager(this_01,this->mpCommonResMgr,3000,0x96,200,this->mpHeap);
  }
  mEmitterMng = this_01;
  if (this_01 == (JPAEmitterManager *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_particle.cpp",0x52c,"mEmitterMng != 0");
    m_Do_printf::OSPanic("d_particle.cpp",0x52c,&DAT_80352aa7);
  }
  uVar4 = m_Do_ext::mDoExt_setCurrentHeap(this->mpHeap);
  this_02 = (dPa_modelControl_c *)JKernel::operator_new(0xc);
  if (this_02 != (dPa_modelControl_c *)0x0) {
    pJVar5 = (J3DModelData *)
             dRes_control_c::getRes
                       ("Always",0x31,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    dPa_modelControl_c::dPa_modelControl_c(this_02,pJVar5);
  }
  this->mModelCtrl = this_02;
  if (this->mModelCtrl == (dPa_modelControl_c *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_particle.cpp",0x534,"mModelControl != 0");
    m_Do_printf::OSPanic("d_particle.cpp",0x534,&DAT_80352aa7);
  }
  uVar7 = 0;
  while( true ) {
    if (7 < uVar7) break;
    uVar1 = dPa_name::j_o_id[uVar7];
    cVar6 = JPAEmitterResource::checkUserIndexDuplication
                      (this->mpCommonResMgr->mpEmitterResource,uVar1);
    if (cVar6 != '\0') {
      bVar2 = 0;
      if ((uVar1 & 0x4000) != 0) {
        bVar2 = 4;
      }
      newSimple(this,uVar1,bVar2);
    }
    uVar7 = uVar7 + 1;
  }
  this->mNumSimpleCommon = this->mNumSimple;
  m_Do_ext::mDoExt_setCurrentHeap(uVar4);
  m_Do_ext::mDoExt_adjustSolidHeap((JKRSolidHeap *)this->mpHeap);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dPa_control_c::createRoomScene(void const *) */

void __thiscall dPa_control_c::createRoomScene(dPa_control_c *this,void *param_1)

{
  ushort uVar1;
  byte bVar2;
  JKRHeap *pJVar3;
  ulong uVar4;
  JPAResourceManager *this_00;
  char cVar5;
  ushort uVar6;
  
  pJVar3 = (JKRHeap *)m_Do_ext::mDoExt_createSolidHeapFromGame(0,0);
  this->mpSceneHeap = pJVar3;
  if (this->mpSceneHeap == (JKRHeap *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_particle.cpp",0x559,"mSceneHeap != 0");
    m_Do_printf::OSPanic("d_particle.cpp",0x559,&DAT_80352aa7);
  }
  this->mpData = param_1;
  this_00 = (JPAResourceManager *)JKernel::operator_new(0xc,this->mpSceneHeap,0);
  if (this_00 != (JPAResourceManager *)0x0) {
    JPAResourceManager::JPAResourceManager(this_00,this->mpData,this->mpSceneHeap);
  }
  this->mpSceneResMgr = this_00;
  if (this->mpSceneResMgr == (JPAResourceManager *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_particle.cpp",0x55d,"mSceneResMng != 0");
    m_Do_printf::OSPanic("d_particle.cpp",0x55d,&DAT_80352aa7);
  }
  JPAResourceManager::swapTexture
            (this->mpSceneResMgr,mDoGph_gInf_c::mFrameBufferTimg,"AK_kagerouSwap00");
  mEmitterMng->mpSceneResMgr = this->mpSceneResMgr;
  m_Do_ext::mDoExt_adjustSolidHeap((JKRSolidHeap *)this->mpSceneHeap);
  uVar6 = 0;
  while( true ) {
    if (0x21 < uVar6) break;
    uVar1 = dPa_name::s_o_id[uVar6];
    cVar5 = JPAEmitterResource::checkUserIndexDuplication
                      (this->mpSceneResMgr->mpEmitterResource,uVar1);
    if (cVar5 != '\0') {
      if ((uVar1 & 0x4000) == 0) {
        bVar2 = 0;
        if ((uVar1 & 0x2000) != 0) {
          bVar2 = 2;
        }
      }
      else {
        bVar2 = 4;
      }
      newSimple(this,uVar1,bVar2);
    }
    uVar6 = uVar6 + 1;
  }
  return;
}


/* __thiscall dPa_control_c::readScene(unsigned char,
                                       mDoDvdThd_toMainRam_c * *) */

int __thiscall
dPa_control_c::readScene(dPa_control_c *this,uchar i_no,mDoDvdThd_toMainRam_c **pDstToMainRam)

{
  byte bVar1;
  int iVar2;
  ulong uVar3;
  mDoDvdThd_toMainRam_c *pmVar4;
  
  if (i_no == 0xff) {
    iVar2 = 0;
  }
  else {
    bVar1 = this->mCount;
    this->mCount = bVar1 + 1;
    if (bVar1 == 0) {
      this->mSceneNo = i_no;
      MSL_C.PPCEABI.bare.H::sprintf(d_particle::jpcName_5165,"/res/Particle/Pscene%03d.jpc");
      pmVar4 = (mDoDvdThd_toMainRam_c *)
               mDoDvdThd_toMainRam_c::create(d_particle::jpcName_5165,0,(JKRHeap *)0x0);
      *pDstToMainRam = pmVar4;
      iVar2 = 1;
    }
    else {
      if (i_no == this->mSceneNo) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_particle.cpp",0x587,"i_no != mSceneNo");
        m_Do_printf::OSPanic("d_particle.cpp",0x587,&DAT_80352aa7);
      }
      iVar2 = 1;
    }
  }
  return iVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dPa_control_c::createScene(void const *) */

void __thiscall dPa_control_c::createScene(dPa_control_c *this,void *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = 0; iVar1 < (int)(uint)this->mNumSimpleCommon; iVar1 = iVar1 + 1) {
    dPa_simpleEcallBack::createEmitter
              ((dPa_simpleEcallBack *)
               (this->mSimpleCallbacks[0].mSimpleData[0].mEnvColor + iVar2 + -0x20),mEmitterMng);
    iVar2 = iVar2 + 0x290;
  }
  if (param_1 != (void *)0x0) {
    createRoomScene(this,param_1);
  }
  return;
}


/* __thiscall dPa_control_c::removeRoomScene(void) */

undefined4 __thiscall dPa_control_c::removeRoomScene(dPa_control_c *this)

{
  byte bVar1;
  
  if (((this->mpSceneHeap != (JKRHeap *)0x0) && (this->mCount != 0)) &&
     (bVar1 = this->mCount - 1, this->mCount = bVar1, bVar1 == 0)) {
    JPAEmitterManager::clearResourceManager(mEmitterMng,'\x01');
    m_Do_ext::mDoExt_destroySolidHeap(this->mpSceneHeap);
    this->mpSceneHeap = (JKRHeap *)0x0;
    this->mpSceneResMgr = (JPAResourceManager *)0x0;
    JKRHeap::free(this->mpData,(JKRHeap *)0x0);
    this->mNumSimple = this->mNumSimpleCommon;
    return 1;
  }
  return 0;
}


/* __thiscall dPa_control_c::removeScene(void) */

void __thiscall dPa_control_c::removeScene(dPa_control_c *this)

{
  int iVar1;
  int iVar2;
  
  removeRoomScene(this);
  iVar1 = 0;
  for (iVar2 = 0; iVar2 < (int)(uint)this->mNumSimpleCommon; iVar2 = iVar2 + 1) {
    *(undefined4 *)(this->mSimpleCallbacks[0].mSimpleData[0].mEnvColor + iVar1 + -0x1c) = 0;
    iVar1 = iVar1 + 0x290;
  }
  JPAEmitterManager::forceDeleteAllEmitter(mEmitterMng);
  dPa_modelControl_c::_dPa_modelControl_c(this->mModelCtrl);
  return;
}


/* __thiscall dPa_control_c::calc3D(void) */

dPa_control_c * __thiscall dPa_control_c::calc3D(dPa_control_c *this)

{
  byte bVar1;
  
  for (bVar1 = 0; bVar1 < 7; bVar1 = bVar1 + 1) {
    this = (dPa_control_c *)JPAEmitterManager::calc(mEmitterMng,bVar1);
  }
  return this;
}


/* __thiscall dPa_control_c::calc2D(void) */

dPa_control_c * __thiscall dPa_control_c::calc2D(dPa_control_c *this)

{
  byte bVar1;
  
  for (bVar1 = 7; bVar1 < 9; bVar1 = bVar1 + 1) {
    this = (dPa_control_c *)JPAEmitterManager::calc(mEmitterMng,bVar1);
  }
  return this;
}


/* __thiscall dPa_control_c::calcMenu(void) */

dPa_control_c * __thiscall dPa_control_c::calcMenu(dPa_control_c *this)

{
  byte bVar1;
  
  for (bVar1 = 9; bVar1 < 0xb; bVar1 = bVar1 + 1) {
    this = (dPa_control_c *)JPAEmitterManager::calc(mEmitterMng,bVar1);
  }
  return this;
}


/* __thiscall dPa_control_c::draw(JPADrawInfo *,
                                  unsigned char) */

void __thiscall dPa_control_c::draw(dPa_control_c *this,JPADrawInfo *param_1,byte param_2)

{
  if (mEmitterMng != (JPAEmitterManager *)0x0) {
    J3DSys::reinitGX(&J3DGraphBase::j3dSys);
    d_kankyo::dKy_setLight_again();
    JPAEmitterManager::draw(mEmitterMng,param_1,param_2);
    gx::GXSetAlphaUpdate(0);
    gx::GXSetNumIndStages(0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* __thiscall dPa_control_c::set(unsigned char,
                                 unsigned short,
                                 cXyz const *,
                                 csXyz const *,
                                 cXyz const *,
                                 unsigned char,
                                 dPa_levelEcallBack *,
                                 signed char,
                                 _GXColor const *,
                                 _GXColor const *,
                                 cXyz const *) */

JPABaseEmitter * __thiscall
dPa_control_c::set(dPa_control_c *this,byte groupID,ushort userID,cXyz *pPos,csXyz *pRot,
                  cXyz *pScale,byte alpha,dPa_levelEcallBack *pCallBack,char setupInfo,
                  _GXColor *pPrmColor,_GXColor *pEnvColor,cXyz *pPublicScale2D)

{
  u8 uVar1;
  u8 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uchar rmID;
  JPABaseEmitter *pEmitter;
  TVec3_float_ local_48;
  
  local_48.z = pPos->z;
  local_48.y = pPos->y;
  local_48.x = pPos->x;
  rmID = getRM_ID(userID);
  pEmitter = JPAEmitterManager::createSimpleEmitterID
                       (mEmitterMng,&local_48,userID,groupID,rmID,(JPACallBackBase *)0x0,
                        (JPACallBackBase2 *)0x0);
  if (pEmitter == (JPABaseEmitter *)0x0) {
    pEmitter = (JPABaseEmitter *)0x0;
  }
  else {
    if (pRot != (csXyz *)0x0) {
      JPABase::JPAGetXYZRotateMtx((int)pRot->x,(int)pRot->y,(int)pRot->z,&pEmitter->mGlobalRotation)
      ;
    }
    if (pScale != (cXyz *)0x0) {
      fVar3 = pScale->x;
      fVar4 = pScale->y;
      fVar5 = pScale->z;
      (pEmitter->mGlobalScale).x = fVar3;
      (pEmitter->mGlobalScale).y = fVar4;
      (pEmitter->mGlobalScale).z = fVar5;
      (pEmitter->mGlobalScale2D).x = fVar3;
      (pEmitter->mGlobalScale2D).y = fVar4;
      (pEmitter->mGlobalScale2D).z = fVar5;
    }
    (pEmitter->mGlobalPrmColor).a = alpha;
    if (pCallBack == (dPa_levelEcallBack *)0x0) {
      if ((userID & 0x4000) != 0) {
        pEmitter->mpEmitterCallBack = (JPACallBackBase *)&mKagero;
      }
    }
    else {
      pEmitter->mpEmitterCallBack = (JPACallBackBase *)pCallBack;
      (*(code *)pCallBack->vtbl->setup)(pCallBack,pEmitter,pPos,pRot,setupInfo);
    }
    if (pPrmColor != (_GXColor *)0x0) {
      uVar1 = pPrmColor->b;
      uVar2 = pPrmColor->g;
      (pEmitter->mGlobalPrmColor).r = pPrmColor->r;
      (pEmitter->mGlobalPrmColor).g = uVar2;
      (pEmitter->mGlobalPrmColor).b = uVar1;
    }
    if (pEnvColor != (_GXColor *)0x0) {
      uVar1 = pEnvColor->b;
      uVar2 = pEnvColor->g;
      (pEmitter->mGlobalEnvColor).r = pEnvColor->r;
      (pEmitter->mGlobalEnvColor).g = uVar2;
      (pEmitter->mGlobalEnvColor).b = uVar1;
    }
    if (pPublicScale2D != (cXyz *)0x0) {
      fVar3 = pPublicScale2D->y;
      fVar4 = pPublicScale2D->z;
      (pEmitter->mGlobalScale2D).x = pPublicScale2D->x;
      (pEmitter->mGlobalScale2D).y = fVar3;
      (pEmitter->mGlobalScale2D).z = fVar4;
    }
  }
  return pEmitter;
}


/* __thiscall dPa_control_c::setBombSmoke(unsigned short,
                                          cXyz const *,
                                          csXyz const *,
                                          cXyz const *,
                                          unsigned char) */

void __thiscall
dPa_control_c::setBombSmoke
          (dPa_control_c *this,ushort param_1,cXyz *param_2,csXyz *param_3,cXyz *param_4,
          uchar param_5)

{
  JPABaseEmitter *pJVar1;
  
  pJVar1 = set(this,3,param_1,param_2,param_3,param_4,param_5,
               (dPa_levelEcallBack *)&mBombSmokeEcallBack,-1,(_GXColor *)0x0,(_GXColor *)0x0,
               (cXyz *)0x0);
  if (pJVar1 != (JPABaseEmitter *)0x0) {
    if (param_1 == 0x2009) {
      *(undefined4 *)&pJVar1->field_0x210 = 0x460501;
    }
    else {
      *(undefined4 *)&pJVar1->field_0x210 = 0x280478;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f0c */
/* WARNING: Inlined function: FUN_80328f58 */
/* WARNING: Removing unreachable block (ram,0x8007d970) */
/* WARNING: Removing unreachable block (ram,0x8007d968) */
/* WARNING: Removing unreachable block (ram,0x8007d978) */
/* __thiscall dPa_control_c::setSimpleLand(int,
                                           cXyz const *,
                                           csXyz const *,
                                           float,
                                           float,
                                           float,
                                           dKy_tevstr_c *,
                                           int *,
                                           int) */

JPABaseEmitter * __thiscall
dPa_control_c::setSimpleLand
          (dPa_control_c *this,int param_1,cXyz *param_2,csXyz *param_3,float param_4,float param_5,
          float param_6,dKy_tevstr_c *param_7,int *param_8,int param_9)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  JPABaseEmitter *pJVar4;
  cBgS_PolyPassChk *pcVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  _GXColor local_e8;
  _GXColor _Stack228;
  _GXColor _Stack224;
  cXyz local_dc;
  float local_d0;
  float local_cc;
  float local_c8;
  cBgS_GndChk local_c4;
  cBgS_PolyPassChk local_84;
  cBgS_GrpPassChk__vtbl *local_78;
  undefined4 local_74;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar10 = (double)param_6;
  dVar9 = (double)param_5;
  dVar7 = (double)param_4;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  bVar1 = false;
  if ((param_7 != (dKy_tevstr_c *)0x0) && (param_8 != (int *)0x0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_particle.cpp",0x6b1,"(i_tevStr != 0) && (i_return_id != 0)");
    m_Do_printf::OSPanic("d_particle.cpp",0x6b1,&DAT_80352aa7);
  }
  iVar3 = checkAtrCodeEffect(this,param_1);
  *param_8 = iVar3;
  if (*param_8 == -1) {
    pJVar4 = (JPABaseEmitter *)0x0;
  }
  else {
    if (param_1 == -1) {
      ::cBgS_GndChk::cBgS_GndChk(&local_c4);
      pcVar5 = &local_84;
      local_84.mbCamThrough = 0;
      local_84.mbLinkThrough = 0;
      local_84.mbArrowsAndLightThrough = 0;
      local_84.mbBombThrough = 0;
      local_84.mbBoomerangThrough = 0;
      local_84.mbHookshotThrough = 0;
      local_74 = 1;
      local_c4.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar5;
      if (pcVar5 != (cBgS_PolyPassChk *)0x0) {
        local_c4.parent.mpGrpPassChk = (cBgS_GrpPassChk *)&local_78;
      }
      local_c4.parent.vtbl = &::dBgS_ObjGndChk::__vt;
      local_c4.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371ed8;
      local_84.vtbl = &cBgS_PolyPassChk__vtbl_80371ee4;
      local_78 = &cBgS_GrpPassChk__vtbl_80371ef0;
      local_84.mbObjThrough = 1;
      local_c8 = param_2->z;
      local_cc = d_particle::_5459 + param_2->y;
      local_d0 = param_2->x;
      local_c4.parent.mpPolyPassChk = pcVar5;
      local_c4.mPos.x = local_d0;
      local_c4.mPos.y = local_cc;
      local_c4.mPos.z = local_c8;
      dVar8 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_c4)
      ;
      if ((double)d_particle::_1_0E9 != dVar8) {
        dBgS::GetAttributeCode(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&local_c4.mPolyInfo);
      }
      local_84.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
      local_78 = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
      if (pcVar5 != (cBgS_PolyPassChk *)0x0) {
        local_84.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
        local_78 = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
        if (((undefined *)register0x00000004 != (undefined *)0x78) &&
           (local_78 = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
           (undefined *)register0x00000004 != (undefined *)0x78)) {
          local_78 = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
        }
        if ((pcVar5 != (cBgS_PolyPassChk *)0x0) &&
           (local_84.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
           pcVar5 != (cBgS_PolyPassChk *)0x0)) {
          local_84.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
        }
      }
      local_c4.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
      local_c4.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
      cBgS_Chk::_cBgS_Chk(&local_c4.parent);
    }
    pJVar4 = (JPABaseEmitter *)0x0;
    iVar3 = *param_8;
    if (iVar3 == 0x23) {
      if ((param_9 & 4U) != 0) {
        local_dc.x = (float)dVar10;
        local_dc.y = (float)dVar10;
        local_dc.z = (float)dVar10;
        d_kankyo::dKy_get_seacolor(&_Stack224,&_Stack228);
        if ((param_9 & 0x10U) == 0) {
          pJVar4 = set(this,0,(ushort)*param_8,param_2,param_3,&local_dc,0xff,
                       (dPa_levelEcallBack *)0x0,-1,&_Stack224,(_GXColor *)0x0,(cXyz *)0x0);
        }
        else {
          pJVar4 = set(this,1,(ushort)*param_8,param_2,param_3,&local_dc,0xff,
                       (dPa_levelEcallBack *)0x0,-1,&_Stack224,(_GXColor *)0x0,(cXyz *)0x0);
        }
      }
    }
    else {
      if (iVar3 == 0x24) {
        if ((param_9 & 2U) != 0) {
          local_dc.x = (float)dVar9;
          local_dc.y = (float)dVar9;
          local_dc.z = (float)dVar9;
          local_e8 = (_GXColor)
                     CONCAT31(CONCAT21((param_7->mColorC0).g & 0xffU | (param_7->mColorC0).r << 8,
                                       (char)(param_7->mColorC0).b),(char)(param_7->mColorC0).a);
          if ((param_9 & 0x10U) == 0) {
            pJVar4 = set(this,0,(ushort)*param_8,param_2,param_3,&local_dc,0xff,
                         (dPa_levelEcallBack *)0x0,-1,&local_e8,&param_7->mColorK0,(cXyz *)0x0);
          }
          else {
            pJVar4 = set(this,1,(ushort)*param_8,param_2,param_3,&local_dc,0xff,
                         (dPa_levelEcallBack *)0x0,-1,&local_e8,&param_7->mColorK0,(cXyz *)0x0);
          }
        }
      }
      else {
        if (iVar3 == 0x2022) {
          if ((param_9 & 8U) != 0) {
            *param_8 = 0x2027;
          }
          if ((param_9 & 9U) != 0) {
            local_dc.x = (float)dVar7;
            local_dc.y = (float)dVar7;
            local_dc.z = (float)dVar7;
            if ((param_9 & 0x10U) == 0) {
              pJVar4 = set(this,2,(ushort)*param_8,param_2,param_3,&local_dc,0x80,
                           (dPa_levelEcallBack *)&mSmokeEcallback,-1,(_GXColor *)0x0,(_GXColor *)0x0
                           ,(cXyz *)0x0);
            }
            else {
              pJVar4 = set(this,3,(ushort)*param_8,param_2,param_3,&local_dc,0x80,
                           (dPa_levelEcallBack *)&mSmokeEcallback,-1,(_GXColor *)0x0,(_GXColor *)0x0
                           ,(cXyz *)0x0);
            }
          }
        }
      }
    }
    if (pJVar4 != (JPABaseEmitter *)0x0) {
      pJVar4->mMaxFrame = 1;
      pJVar4->mRate = d_particle::_4268;
      pJVar4->mSpread = d_particle::_5461;
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  return pJVar4;
}


/* WARNING: Inlined function: FUN_80328ea8 */
/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328ef4 */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dPa_control_c::setSimpleLand(cBgS_PolyInfo &,
                                           cXyz const *,
                                           csXyz const *,
                                           float,
                                           float,
                                           float,
                                           dKy_tevstr_c *,
                                           int *,
                                           int) */

undefined4 __thiscall
dPa_control_c::setSimpleLand
          (dPa_control_c *this,cBgS_PolyInfo *param_1,cXyz *param_2,csXyz *param_3,float param_4,
          float param_5,float param_6,dKy_tevstr_c *param_7,int *param_8,int param_9)

{
  char cVar3;
  int iVar1;
  undefined4 uVar2;
  double dVar4;
  double dVar5;
  double dVar6;
  
  dVar6 = (double)param_6;
  dVar5 = (double)param_5;
  dVar4 = (double)param_4;
  cVar3 = cBgS::ChkPolySafe((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,param_1);
  if (cVar3 == '\0') {
    uVar2 = 0;
  }
  else {
    iVar1 = dBgS::GetAttributeCode(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,param_1);
    uVar2 = setSimpleLand(this,iVar1,param_2,param_3,(float)dVar4,(float)dVar5,(float)dVar6,param_7,
                          param_8,param_9);
  }
  return uVar2;
}


/* __thiscall dPa_control_c::checkAtrCodeEffect(int) */

undefined4 __thiscall dPa_control_c::checkAtrCodeEffect(dPa_control_c *this,int param_1)

{
  if (param_1 == 0x13) {
    return 0x23;
  }
  if (param_1 == 4) {
    return 0x24;
  }
  if ((((param_1 != 0x1b) && (param_1 != 0xf)) && (param_1 != 5)) && (param_1 != 10)) {
    return 0x2022;
  }
  return 0xffffffff;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dPa_control_c::setNormalStripes(unsigned short,
                                              cXyz const *,
                                              csXyz const *,
                                              cXyz const *,
                                              unsigned char,
                                              unsigned short) */

void __thiscall
dPa_control_c::setNormalStripes
          (dPa_control_c *this,ushort param_1,cXyz *param_2,csXyz *param_3,cXyz *param_4,
          uchar param_5,ushort param_6)

{
  JPABaseEmitter *pJVar1;
  
  pJVar1 = set(this,0,param_1,param_2,param_3,param_4,param_5,(dPa_levelEcallBack *)&mStripes,-1,
               (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  if (pJVar1 != (JPABaseEmitter *)0x0) {
    *(uint *)&pJVar1->field_0x210 = (uint)param_6;
  }
  return;
}


/* __thiscall dPa_control_c::newSimple(unsigned short,
                                       unsigned char) */

undefined4 __thiscall dPa_control_c::newSimple(dPa_control_c *this,ushort param_1,byte param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (this->mNumSimple < 0x19) {
    iVar2 = dPa_simpleEcallBack::create
                      (this->mSimpleCallbacks + this->mNumSimple,mEmitterMng,param_1,param_2);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      this->mNumSimple = this->mNumSimple + 1;
      uVar1 = 1;
    }
  }
  else {
    m_Do_printf::OSReport(&DAT_80352b8f);
    uVar1 = 0;
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dPa_control_c::setSimple(unsigned short,
                                       cXyz const *,
                                       unsigned char,
                                       _GXColor const &,
                                       _GXColor const &,
                                       int) */

int __thiscall
dPa_control_c::setSimple
          (dPa_control_c *this,ushort param_1,cXyz *param_2,uchar param_3,_GXColor *param_4,
          _GXColor *param_5,int param_6)

{
  dPa_simpleEcallBack *this_00;
  int iVar1;
  
  this_00 = getSimple(this,param_1);
  if (this_00 == (dPa_simpleEcallBack *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = dPa_simpleEcallBack::set(this_00,param_2,param_3,param_4,param_5,param_6);
  }
  return iVar1;
}


/* __thiscall dPa_control_c::getSimple(unsigned short) */

dPa_simpleEcallBack * __thiscall dPa_control_c::getSimple(dPa_control_c *this,ushort param_1)

{
  uint uVar1;
  dPa_simpleEcallBack *pdVar2;
  
  pdVar2 = this->mSimpleCallbacks;
  uVar1 = (uint)this->mNumSimple;
  while( true ) {
    if (uVar1 == 0) {
      return (dPa_simpleEcallBack *)0x0;
    }
    if (param_1 == pdVar2->mResID) break;
    pdVar2 = pdVar2 + 1;
    uVar1 = uVar1 - 1;
  }
  return pdVar2;
}


/* __thiscall dPa_rippleEcallBack::setup(JPABaseEmitter *,
                                         cXyz const *,
                                         csXyz const *,
                                         signed char) */

void __thiscall
dPa_rippleEcallBack::setup
          (dPa_rippleEcallBack *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,
          char param_4)

{
  param_1->mpParticleCallBack = (JPACallBackBase2 *)&dPa_control_c::mRipplePcallBack;
  this->mPos = param_2;
  this->mRate = d_particle::1_0;
  this->mFlags = this->mFlags | 1;
  this->mpBaseEmitter = param_1;
  return;
}


/* __thiscall dPa_rippleEcallBack::end(void) */

void __thiscall dPa_rippleEcallBack::end(dPa_rippleEcallBack *this)

{
  JPABaseEmitter *pJVar1;
  
  pJVar1 = this->mpBaseEmitter;
  if (pJVar1 == (JPABaseEmitter *)0x0) {
    return;
  }
  pJVar1->mMaxFrame = -1;
  pJVar1->mFlags = pJVar1->mFlags | 1;
  this->mpBaseEmitter->mFlags = this->mpBaseEmitter->mFlags & 0xffffffbf;
  this->mpBaseEmitter->mpEmitterCallBack = (JPACallBackBase *)0x0;
  this->mFlags = this->mFlags | 2;
  this->mpBaseEmitter = (JPABaseEmitter *)0x0;
  return;
}


/* __thiscall dPa_rippleEcallBack::execute(JPABaseEmitter *) */

void __thiscall dPa_rippleEcallBack::execute(dPa_rippleEcallBack *this,JPABaseEmitter *param_1)

{
  float fVar1;
  float fVar2;
  cXyz *pcVar3;
  _GXColor local_18;
  _GXColor local_14;
  
  pcVar3 = this->mPos;
  fVar1 = pcVar3->z;
  fVar2 = pcVar3->y;
  (param_1->mGlobalTranslation).x = pcVar3->x;
  (param_1->mGlobalTranslation).y = fVar2;
  (param_1->mGlobalTranslation).z = fVar1;
  param_1->mRate = d_particle::0_0667 + d_particle::0_1333 * this->mRate;
  if ((this->mFlags & 1) != 0) {
    d_kankyo::dKy_get_seacolor(&local_14,&local_18);
    (param_1->mGlobalPrmColor).r = local_14.r;
    (param_1->mGlobalPrmColor).g = local_14.g;
    (param_1->mGlobalPrmColor).b = local_14.b;
  }
  return;
}


/* __thiscall dPa_rippleEcallBack::draw(JPABaseEmitter *) */

void __thiscall dPa_rippleEcallBack::draw(dPa_rippleEcallBack *this,JPABaseEmitter *param_1)

{
  if ((dPa_control_c::mStatus & 1) != 0) {
    gx::GXSetZMode(false,GX_NEVER,false);
  }
  return;
}


/* __thiscall dPa_singleRippleEcallBack::setup(JPABaseEmitter *,
                                               cXyz const *,
                                               csXyz const *,
                                               signed char) */

void __thiscall
dPa_singleRippleEcallBack::setup
          (dPa_singleRippleEcallBack *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,
          char param_4)

{
  param_1->mpParticleCallBack = (JPACallBackBase2 *)&dPa_control_c::mRipplePcallBack;
  return;
}


/* __thiscall dPa_singleRippleEcallBack::execute(JPABaseEmitter *) */

void __thiscall
dPa_singleRippleEcallBack::execute(dPa_singleRippleEcallBack *this,JPABaseEmitter *param_1)

{
  _GXColor _Stack24;
  _GXColor local_14 [4];
  
  d_kankyo::dKy_get_seacolor(local_14,&_Stack24);
  (param_1->mGlobalPrmColor).r = local_14[0].r;
  (param_1->mGlobalPrmColor).g = local_14[0].g;
  (param_1->mGlobalPrmColor).b = local_14[0].b;
  return;
}


/* __thiscall dPa_singleRippleEcallBack::draw(JPABaseEmitter *) */

void __thiscall
dPa_singleRippleEcallBack::draw(dPa_singleRippleEcallBack *this,JPABaseEmitter *param_1)

{
  if ((dPa_control_c::mStatus & 1) != 0) {
    gx::GXSetZMode(false,GX_NEVER,false);
  }
  return;
}


/* __thiscall dPa_ripplePcallBack::execute(JPABaseEmitter *,
                                           JPABaseParticle *) */

void __thiscall
dPa_ripplePcallBack::execute
          (dPa_ripplePcallBack *this,JPABaseEmitter *param_1,JPABaseParticle *param_2)

{
  uint uVar1;
  float local_18;
  cXyz local_14;
  
  local_14.x = (param_2->mPosition).x;
  local_14.y = (param_2->mPosition).y;
  local_14.z = (param_2->mPosition).z;
  uVar1 = f_op_actor_mng::fopAcM_getWaterY(&local_14,&local_18);
  if (uVar1 != 0) {
    (param_2->mGlobalPosition).y = local_18;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8007e230) */
/* WARNING: Removing unreachable block (ram,0x8007e220) */
/* WARNING: Removing unreachable block (ram,0x8007e210) */
/* WARNING: Removing unreachable block (ram,0x8007e200) */
/* WARNING: Removing unreachable block (ram,0x8007e1f0) */
/* WARNING: Removing unreachable block (ram,0x8007e1e0) */
/* WARNING: Removing unreachable block (ram,0x8007e1d0) */
/* WARNING: Removing unreachable block (ram,0x8007e1d8) */
/* WARNING: Removing unreachable block (ram,0x8007e1e8) */
/* WARNING: Removing unreachable block (ram,0x8007e1f8) */
/* WARNING: Removing unreachable block (ram,0x8007e208) */
/* WARNING: Removing unreachable block (ram,0x8007e218) */
/* WARNING: Removing unreachable block (ram,0x8007e228) */
/* WARNING: Removing unreachable block (ram,0x8007e238) */
/* __thiscall dPa_ripplePcallBack::draw(JPABaseEmitter *,
                                        JPABaseParticle *) */

void __thiscall
dPa_ripplePcallBack::draw
          (dPa_ripplePcallBack *this,JPABaseEmitter *param_1,JPABaseParticle *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined8 in_f18;
  double dVar11;
  undefined8 in_f19;
  double dVar12;
  undefined8 in_f20;
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
  double dVar18;
  undefined8 in_f26;
  double dVar19;
  undefined8 in_f27;
  double dVar20;
  undefined8 in_f28;
  double dVar21;
  undefined8 in_f29;
  double dVar22;
  undefined8 in_f30;
  double dVar23;
  undefined8 in_f31;
  double dVar24;
  float local_f8;
  cXyz local_f4;
  undefined auStack216 [16];
  undefined auStack200 [16];
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
  
  uVar10 = 0;
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
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  __psq_st0(auStack216,(int)((ulonglong)in_f18 >> 0x20),0);
  __psq_st1(auStack216,(int)in_f18,0);
  local_f4.x = (param_2->mPosition).x;
  dVar20 = (double)local_f4.x;
  local_f4.y = (param_2->mPosition).y;
  dVar19 = (double)local_f4.y;
  local_f4.z = (param_2->mPosition).z;
  dVar18 = (double)local_f4.z;
  iVar8 = (int)(uint)(ushort)param_2->mRotateAngle >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar1 = JKernel::JMath::jmaSinTable[iVar8];
  fVar2 = JKernel::JMath::jmaCosTable[iVar8];
  fVar6 = d_particle::0_5 * d_particle::2_0 * param_2->mScaleX * JPADraw::cb.mGlobalScale2D[0];
  fVar7 = d_particle::0_5 * d_particle::2_0 * param_2->mScaleY * JPADraw::cb.mGlobalScale2D[1];
  fVar3 = fVar1 * -fVar6;
  dVar24 = (double)(fVar2 * fVar7 + fVar3);
  fVar5 = fVar2 * -fVar6;
  dVar17 = (double)(fVar5 - fVar1 * fVar7);
  dVar23 = (double)(fVar2 * fVar7 + fVar1 * fVar6);
  dVar16 = (double)(fVar2 * fVar6 - fVar1 * fVar7);
  fVar4 = fVar2 * -fVar7;
  dVar22 = (double)(fVar4 + fVar1 * fVar6);
  fVar1 = fVar1 * -fVar7;
  dVar15 = (double)(fVar2 * fVar6 - fVar1);
  dVar21 = (double)(fVar4 + fVar3);
  dVar14 = (double)(fVar5 - fVar1);
  if ((dPa_control_c::mStatus & 1) == 0) {
    uVar9 = f_op_actor_mng::fopAcM_getWaterY(&local_f4,&local_f8);
    if (uVar9 == 0) {
      local_f8 = (float)((double)d_particle::2_0 + dVar19);
    }
    else {
      local_f8 = d_particle::2_0 + local_f8;
    }
    dVar11 = (double)local_f8;
    dVar12 = dVar11;
    dVar13 = dVar11;
    dVar19 = dVar11;
  }
  else {
    local_f4.x = (float)(dVar17 + dVar20);
    local_f4.z = (float)(dVar24 + dVar18);
    uVar9 = f_op_actor_mng::fopAcM_getWaterY(&local_f4,&local_f8);
    if (uVar9 == 0) {
      fVar1 = (float)((double)d_particle::2_0 + dVar19);
    }
    else {
      fVar1 = d_particle::2_0 + local_f8;
    }
    dVar13 = (double)fVar1;
    local_f4.x = (float)(dVar16 + dVar20);
    local_f4.y = (float)dVar19;
    local_f4.z = (float)(dVar23 + dVar18);
    uVar9 = f_op_actor_mng::fopAcM_getWaterY(&local_f4,&local_f8);
    if (uVar9 == 0) {
      fVar1 = (float)((double)d_particle::2_0 + dVar19);
    }
    else {
      fVar1 = d_particle::2_0 + local_f8;
    }
    dVar12 = (double)fVar1;
    local_f4.x = (float)(dVar15 + dVar20);
    local_f4.y = (float)dVar19;
    local_f4.z = (float)(dVar22 + dVar18);
    uVar9 = f_op_actor_mng::fopAcM_getWaterY(&local_f4,&local_f8);
    if (uVar9 == 0) {
      fVar1 = (float)((double)d_particle::2_0 + dVar19);
    }
    else {
      fVar1 = d_particle::2_0 + local_f8;
    }
    dVar11 = (double)fVar1;
    local_f4.x = (float)(dVar14 + dVar20);
    local_f4.y = (float)dVar19;
    local_f4.z = (float)(dVar21 + dVar18);
    uVar9 = f_op_actor_mng::fopAcM_getWaterY(&local_f4,&local_f8);
    if (uVar9 == 0) {
      dVar19 = (double)(float)((double)d_particle::2_0 + dVar19);
    }
    else {
      dVar19 = (double)(d_particle::2_0 + local_f8);
    }
  }
  gx::GXSetCullMode(0);
  gx::GXBegin(0x80,0,4);
  write_volatile_4(0xcc008000,(float)(dVar17 + dVar20));
  write_volatile_4(0xcc008000,(float)dVar13);
  write_volatile_4(0xcc008000,(float)(dVar24 + dVar18));
  write_volatile_4(0xcc008000,d_particle::0_0);
  write_volatile_4(0xcc008000,d_particle::0_0);
  write_volatile_4(0xcc008000,(float)(dVar16 + dVar20));
  write_volatile_4(0xcc008000,(float)dVar12);
  write_volatile_4(0xcc008000,(float)(dVar23 + dVar18));
  write_volatile_4(0xcc008000,d_particle::1_0);
  write_volatile_4(0xcc008000,d_particle::0_0);
  write_volatile_4(0xcc008000,(float)(dVar15 + dVar20));
  write_volatile_4(0xcc008000,(float)dVar11);
  write_volatile_4(0xcc008000,(float)(dVar22 + dVar18));
  write_volatile_4(0xcc008000,d_particle::1_0);
  write_volatile_4(0xcc008000,d_particle::1_0);
  write_volatile_4(0xcc008000,(float)(dVar14 + dVar20));
  write_volatile_4(0xcc008000,(float)dVar19);
  write_volatile_4(0xcc008000,(float)(dVar21 + dVar18));
  write_volatile_4(0xcc008000,d_particle::0_0);
  write_volatile_4(0xcc008000,d_particle::1_0);
  param_2->mFlags = param_2->mFlags | 8;
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  __psq_l0(auStack40,uVar10);
  __psq_l1(auStack40,uVar10);
  __psq_l0(auStack56,uVar10);
  __psq_l1(auStack56,uVar10);
  __psq_l0(auStack72,uVar10);
  __psq_l1(auStack72,uVar10);
  __psq_l0(auStack88,uVar10);
  __psq_l1(auStack88,uVar10);
  __psq_l0(auStack104,uVar10);
  __psq_l1(auStack104,uVar10);
  __psq_l0(auStack120,uVar10);
  __psq_l1(auStack120,uVar10);
  __psq_l0(auStack136,uVar10);
  __psq_l1(auStack136,uVar10);
  __psq_l0(auStack152,uVar10);
  __psq_l1(auStack152,uVar10);
  __psq_l0(auStack168,uVar10);
  __psq_l1(auStack168,uVar10);
  __psq_l0(auStack184,uVar10);
  __psq_l1(auStack184,uVar10);
  __psq_l0(auStack200,uVar10);
  __psq_l1(auStack200,uVar10);
  __psq_l0(auStack216,uVar10);
  __psq_l1(auStack216,uVar10);
  return;
}


/* __thiscall dPa_waveEcallBack::setup(JPABaseEmitter *,
                                       cXyz const *,
                                       csXyz const *,
                                       signed char) */

void __thiscall
dPa_waveEcallBack::setup
          (dPa_waveEcallBack *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,char param_4
          )

{
  this->mpPos = param_2;
  this->mpRot = param_3;
  this->mVel = d_particle::0_0;
  this->mVelFade2 = d_particle::1_0;
  this->mpBaseEmitter = param_1;
  this->mMaxDistance = d_particle::10000_0;
  this->mState = 0;
  this->mFadeTimer = 0;
  return;
}


/* __thiscall dPa_waveEcallBack::remove(void) */

int __thiscall dPa_waveEcallBack::remove(dPa_waveEcallBack *this)

{
  JPABaseEmitter *pJVar1;
  
  if (this->mpBaseEmitter == (JPABaseEmitter *)0x0) {
    return (int)this;
  }
  this->mpBaseEmitter->mpEmitterCallBack = (JPACallBackBase *)0x0;
  pJVar1 = this->mpBaseEmitter;
  pJVar1->mMaxFrame = -1;
  pJVar1->mFlags = pJVar1->mFlags | 1;
  this->mpBaseEmitter = (JPABaseEmitter *)0x0;
  return (int)this;
}


/* WARNING: Removing unreachable block (ram,0x8007e464) */
/* __thiscall dPa_waveEcallBack::executeAfter(JPABaseEmitter *) */

void __thiscall dPa_waveEcallBack::executeAfter(dPa_waveEcallBack *this,JPABaseEmitter *pEmitter)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  cXyz *pcVar7;
  undefined4 uVar8;
  double base;
  double dVar9;
  undefined8 in_f31;
  double velTarget;
  undefined auStack8 [8];
  
  fVar2 = JPABaseEmitter::emtrInfo.mEmitterGlobalRot.m[2][0];
  fVar1 = JPABaseEmitter::emtrInfo.mEmitterGlobalRot.m[1][0];
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  this->mRotMtx[0].x = JPABaseEmitter::emtrInfo.mEmitterGlobalRot.m[0][0];
  this->mRotMtx[0].y = fVar1;
  this->mRotMtx[0].z = fVar2;
  fVar2 = JPABaseEmitter::emtrInfo.mEmitterGlobalRot.m[2][1];
  fVar1 = JPABaseEmitter::emtrInfo.mEmitterGlobalRot.m[1][1];
  this->mRotMtx[1].x = JPABaseEmitter::emtrInfo.mEmitterGlobalRot.m[0][1];
  this->mRotMtx[1].y = fVar1;
  this->mRotMtx[1].z = fVar2;
  fVar2 = JPABaseEmitter::emtrInfo.mEmitterGlobalRot.m[2][2];
  fVar1 = JPABaseEmitter::emtrInfo.mEmitterGlobalRot.m[1][2];
  this->mRotMtx[2].x = JPABaseEmitter::emtrInfo.mEmitterGlobalRot.m[0][2];
  this->mRotMtx[2].y = fVar1;
  this->mRotMtx[2].z = fVar2;
  if (this->mState == 0) {
    fVar1 = (pEmitter->mGlobalTranslation).x;
    fVar2 = (pEmitter->mGlobalTranslation).y;
    fVar3 = (pEmitter->mGlobalTranslation).z;
    pcVar7 = this->mpPos;
    fVar4 = pcVar7->x;
    fVar5 = pcVar7->y;
    fVar6 = pcVar7->z;
    (pEmitter->mGlobalTranslation).x = fVar4;
    (pEmitter->mGlobalTranslation).y = fVar5;
    (pEmitter->mGlobalTranslation).z = fVar6;
    fVar4 = fVar4 - fVar1;
    fVar5 = fVar5 - fVar2;
    fVar6 = fVar6 - fVar3;
    fVar1 = fVar6 * fVar6 + fVar4 * fVar4 + fVar5 * fVar5;
    if (d_particle::0_0 < fVar1) {
      fVar2 = 1.0 / SQRT(fVar1);
      fVar1 = fVar1 * d_particle::0_5 * fVar2 * (d_particle::_4268 - fVar1 * fVar2 * fVar2);
    }
    if (this->mMaxDistance <= fVar1) {
      fVar1 = this->mMaxDistance;
    }
    velTarget = (double)(this->mVelFade2 * this->mVelFade1 * fVar1);
    JPABase::JPAGetXYZRotateMtx(0,(int)this->mpRot->y,0,&pEmitter->mGlobalRotation);
    base = (double)this->mVel;
    dVar9 = (double)this->mVelSpeed;
    if (dVar9 < (double)ABS((float)(velTarget - base))) {
      if ((float)(velTarget - base) <= d_particle::0_0) {
        velTarget = (double)(float)(base - dVar9);
      }
      else {
        velTarget = (double)(float)(base + dVar9);
      }
    }
    pEmitter->mInitialVelDir = (float)velTarget;
    this->mVel = (float)velTarget;
  }
  else {
    pEmitter->mInitialVelDir = d_particle::0_0;
    if (this->mFadeTimer < 1) {
      remove(this);
    }
    else {
      this->mFadeTimer = this->mFadeTimer + -1;
    }
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8007e7dc) */
/* WARNING: Removing unreachable block (ram,0x8007e7cc) */
/* WARNING: Removing unreachable block (ram,0x8007e7c4) */
/* WARNING: Removing unreachable block (ram,0x8007e7d4) */
/* WARNING: Removing unreachable block (ram,0x8007e7e4) */
/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall dPa_waveEcallBack::draw(JPABaseEmitter *) */

void __thiscall dPa_waveEcallBack::draw(dPa_waveEcallBack *this,JPABaseEmitter *pEmtr)

{
  JPABaseParticle *pPtcl;
  JSUPtrLink *pJVar1;
  uint uVar2;
  int iVar3;
  cXyz *pCollapse;
  undefined4 uVar4;
  undefined8 in_f27;
  double dVar5;
  undefined8 in_f28;
  double dVar6;
  undefined8 in_f29;
  double z;
  undefined8 in_f30;
  double y;
  undefined8 in_f31;
  double x;
  _GXColor local_f8;
  _GXColor local_f4;
  _GXColor local_f0;
  _GXColor local_ec;
  cXyz local_e8;
  cXyz local_dc;
  cXyz local_c4;
  cXyz local_b8;
  cXyz local_7c;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  float cpx_;
  float cpy_;
  float cpz_;
  
  uVar4 = 0;
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
  uVar2 = (pEmtr->mActiveParticles).mCount;
  x = (double)(pEmtr->mGlobalTranslation).x;
  y = (double)(pEmtr->mGlobalTranslation).y;
  z = (double)(pEmtr->mGlobalTranslation).z;
  dVar5 = (double)(d_particle::1_0 /
                  (float)((double)CONCAT44(0x43300000,uVar2 - 1) - d_particle::_4272));
  if (1 < uVar2) {
    gx::GXSetCullMode(0);
    gx::GXSetClipMode(false);
    gx::GXSetMisc(1,8);
    d_kankyo::dKy_get_seacolor(&local_ec,&local_f0);
    local_ec = (_GXColor)CONCAT31(local_ec._0_3_,0xff);
    local_f0 = (_GXColor)CONCAT31(local_f0._0_3_,0xff);
    local_f4 = local_ec;
    gx::GXSetTevColor(GX_TEVREG0,&local_f4);
    local_f8 = local_f0;
    gx::GXSetTevColor(GX_TEVREG1,&local_f8);
    pCollapse = this->mCollapsePos;
    iVar3 = 0;
    do {
      dVar6 = (double)d_particle::0_0;
      cpz_ = pCollapse->z;
      cpy_ = pCollapse->y;
      cpx_ = pCollapse->x;
      local_e8.x = this->mRotMtx[0].x * cpx_ + this->mRotMtx[1].x * cpy_;
      local_e8.y = this->mRotMtx[0].y * cpx_ + this->mRotMtx[1].y * cpy_;
      local_e8.z = this->mRotMtx[0].z * cpx_ + this->mRotMtx[1].z * cpy_;
      cpy_ = local_e8.x + this->mRotMtx[2].x * cpz_;
      cpx_ = local_e8.y + this->mRotMtx[2].y * cpz_;
      cpz_ = local_e8.z + this->mRotMtx[2].z * cpz_;
      gx::GXBegin(0xa0,0,uVar2 + 1 & 0xffff);
      write_volatile_4(0xcc008000,(float)(x + (double)cpy_));
      write_volatile_4(0xcc008000,(float)(y + (double)cpx_));
      write_volatile_4(0xcc008000,(float)(z + (double)cpz_));
      write_volatile_4(0xcc008000,d_particle::0_5);
      write_volatile_4(0xcc008000,d_particle::0_0);
      for (pJVar1 = (pEmtr->mActiveParticles).mpHead; pJVar1 != (JSUPtrLink *)0x0;
          pJVar1 = (JSUPtrLink *)(&pJVar1->mpData)[3]) {
        pPtcl = (JPABaseParticle *)pJVar1->mpData;
        write_volatile_4(0xcc008000,(pPtcl->mPosition).x);
        write_volatile_4(0xcc008000,(pPtcl->mPosition).y);
        write_volatile_4(0xcc008000,(pPtcl->mPosition).z);
        write_volatile_4(0xcc008000,(float)dVar6);
        write_volatile_4(0xcc008000,d_particle::1_0);
        dVar6 = (double)(float)(dVar6 + dVar5);
      }
      iVar3 = iVar3 + 1;
      pCollapse = pCollapse + 1;
    } while (iVar3 < 2);
    gx::GXSetMisc(1,0);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  __psq_l0(auStack72,uVar4);
  __psq_l1(auStack72,uVar4);
  return;
}


/* __thiscall dPa_splashEcallBack::setup(JPABaseEmitter *,
                                         cXyz const *,
                                         csXyz const *,
                                         signed char) */

void __thiscall
dPa_splashEcallBack::setup
          (dPa_splashEcallBack *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,
          char param_4)

{
  this->mpPos = param_2;
  this->mpRot = param_3;
  this->mpBaseEmitter = param_1;
  this->mState = 0;
  return;
}


/* __thiscall dPa_splashEcallBack::remove(void) */

int __thiscall dPa_splashEcallBack::remove(dPa_splashEcallBack *this)

{
  JPABaseEmitter *pJVar1;
  
  if (this->mpBaseEmitter == (JPABaseEmitter *)0x0) {
    return (int)this;
  }
  this->mpBaseEmitter->mpEmitterCallBack = (JPACallBackBase *)0x0;
  pJVar1 = this->mpBaseEmitter;
  pJVar1->mMaxFrame = -1;
  pJVar1->mFlags = pJVar1->mFlags | 1;
  this->mpBaseEmitter = (JPABaseEmitter *)0x0;
  return (int)this;
}


/* __thiscall dPa_splashEcallBack::execute(JPABaseEmitter *) */

void __thiscall dPa_splashEcallBack::execute(dPa_splashEcallBack *this,JPABaseEmitter *param_1)

{
  float fVar1;
  float fVar2;
  short sVar3;
  int iVar4;
  cXyz *pcVar5;
  _GXColor local_28;
  _GXColor _Stack36;
  float local_20;
  float local_1c;
  float local_18;
  
  d_kankyo::dKy_get_seacolor(&_Stack36,&local_28);
  (param_1->mGlobalPrmColor).r = _Stack36.r;
  (param_1->mGlobalPrmColor).g = _Stack36.g;
  (param_1->mGlobalPrmColor).b = _Stack36.b;
  if (this->mState == 0) {
    pcVar5 = this->mpPos;
    fVar1 = pcVar5->z;
    fVar2 = pcVar5->y;
    (param_1->mGlobalTranslation).x = pcVar5->x;
    (param_1->mGlobalTranslation).y = fVar2;
    (param_1->mGlobalTranslation).z = fVar1;
    fVar1 = this->mScaleTimer / this->mMaxScaleTimer;
    sVar3 = this->mpRot->y;
    if (d_particle::1_0 < fVar1) {
      fVar1 = d_particle::1_0;
    }
    (param_1->mGlobalScale).x = fVar1;
    (param_1->mGlobalScale).y = fVar1;
    (param_1->mGlobalScale).z = fVar1;
    (param_1->mGlobalScale2D).x = fVar1;
    (param_1->mGlobalScale2D).y = fVar1;
    (param_1->mGlobalScale2D).z = fVar1;
    param_1->mInitialVelDir = d_particle::15_0 * fVar1;
    JPABase::JPAGetXYZRotateMtx(0,(int)sVar3,0,&param_1->mGlobalRotation);
  }
  else {
    local_20 = (param_1->mGlobalScale2D).x;
    local_1c = (param_1->mGlobalScale2D).y;
    local_18 = (param_1->mGlobalScale2D).z;
    iVar4 = SComponent::cLib_chaseF(&local_20,d_particle::0_0,d_particle::0_2);
    if (iVar4 == 0) {
      (param_1->mGlobalScale).x = local_20;
      (param_1->mGlobalScale).y = local_20;
      (param_1->mGlobalScale).z = local_20;
      (param_1->mGlobalScale2D).x = local_20;
      (param_1->mGlobalScale2D).y = local_20;
      (param_1->mGlobalScale2D).z = local_20;
      param_1->mInitialVelDir = d_particle::15_0 * local_20;
    }
    else {
      remove(this);
    }
  }
  return;
}


/* __thiscall dPa_cutTurnEcallBack_c::setup(JPABaseEmitter *,
                                            cXyz const *,
                                            csXyz const *,
                                            signed char) */

void __thiscall
dPa_cutTurnEcallBack_c::setup
          (dPa_cutTurnEcallBack_c *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,
          char param_4)

{
  *(JPABaseEmitter **)&this->field_0xc = param_1;
  this->field_0x6 = 0;
  *(undefined *)&this->field_0x5 = 0;
  this->field_0x4 = 0xff;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dPa_cutTurnEcallBack_c::executeAfter(JPABaseEmitter *) */

void __thiscall
dPa_cutTurnEcallBack_c::executeAfter(dPa_cutTurnEcallBack_c *this,JPABaseEmitter *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  cXyz *pcVar5;
  
  if (*(char *)&this->field_0x5 == '\0') {
    iVar4 = (int)this->field_0x6;
    if ((0 < this->field_0x6) && (this->field_0x8 != (cXyz *)0x0)) {
      pcVar5 = this->field_0x8 + iVar4 + -1;
      while (iVar4 = iVar4 + -1, 0 < iVar4) {
        iVar3 = JPABaseEmitter::createParticle(param_1);
        if (iVar3 != 0) {
          fVar1 = pcVar5->y;
          fVar2 = pcVar5->z;
          *(float *)(iVar3 + 0x10) = pcVar5->x;
          *(float *)(iVar3 + 0x14) = fVar1;
          *(float *)(iVar3 + 0x18) = fVar2;
        }
        pcVar5 = pcVar5 + -1;
      }
      fVar1 = pcVar5->z;
      fVar2 = pcVar5->y;
      (param_1->mGlobalTranslation).x = pcVar5->x;
      (param_1->mGlobalTranslation).y = fVar2;
      (param_1->mGlobalTranslation).z = fVar1;
      (param_1->mGlobalPrmColor).a = this->field_0x4;
      this->field_0x6 = 0;
    }
  }
  else {
    param_1->mMaxFrame = -1;
    param_1->mFlags = param_1->mFlags | 1;
    param_1->mpEmitterCallBack = (JPACallBackBase *)0x0;
    *(undefined4 *)&this->field_0xc = 0;
  }
  return;
}


/* __thiscall dPa_cutTurnEcallBack_c::end(void) */

void __thiscall dPa_cutTurnEcallBack_c::end(dPa_cutTurnEcallBack_c *this)

{
  int iVar1;
  
  if (*(int *)&this->field_0xc == 0) {
    return;
  }
  *(undefined4 *)(*(int *)&this->field_0xc + 0x19c) = 0;
  iVar1 = *(int *)&this->field_0xc;
  *(undefined4 *)(iVar1 + 0x60) = 0xffffffff;
  *(uint *)(iVar1 + 0x20c) = *(uint *)(iVar1 + 0x20c) | 1;
  *(undefined4 *)&this->field_0xc = 0;
  *(undefined *)&this->field_0x5 = 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8007f000) */
/* WARNING: Removing unreachable block (ram,0x8007eff0) */
/* WARNING: Removing unreachable block (ram,0x8007efe0) */
/* WARNING: Removing unreachable block (ram,0x8007efd0) */
/* WARNING: Removing unreachable block (ram,0x8007efc0) */
/* WARNING: Removing unreachable block (ram,0x8007efc8) */
/* WARNING: Removing unreachable block (ram,0x8007efd8) */
/* WARNING: Removing unreachable block (ram,0x8007efe8) */
/* WARNING: Removing unreachable block (ram,0x8007eff8) */
/* WARNING: Removing unreachable block (ram,0x8007f008) */
/* __thiscall dPa_stripesEcallBack::draw(JPABaseEmitter *) */

dPa_stripesEcallBack * __thiscall
dPa_stripesEcallBack::draw(dPa_stripesEcallBack *this,JPABaseEmitter *param_1)

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
  float fVar12;
  float fVar13;
  float fVar14;
  int iVar15;
  uint uVar16;
  undefined *puVar17;
  uint uVar18;
  JSUPtrLink *pJVar19;
  uint uVar20;
  undefined4 uVar21;
  double dVar22;
  undefined8 in_f22;
  undefined8 in_f23;
  undefined8 in_f24;
  undefined8 in_f25;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar23;
  undefined8 in_f31;
  double dVar24;
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
  
  uVar21 = 0;
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
  if (((param_1->mDraw).field_0xc2 & 2) != 0) {
    dVar24 = (double)(d_particle::_6415 *
                     (float)((double)CONCAT44(0x43300000,*(undefined4 *)&param_1->field_0x210) -
                            d_particle::_4272));
    uVar18 = (param_1->mChildParticles).mCount;
    this = (dPa_stripesEcallBack *)(uVar18 / 5);
    dVar23 = (double)(d_particle::1_0 /
                     (float)((double)CONCAT44(0x43300000,this + -1) - d_particle::_4272));
    uVar16 = (param_1->mActiveParticles).mCount;
    if (((uVar16 == (uVar16 / 5) * 5) && (9 < uVar18)) && (uVar18 == (int)this * 5)) {
      for (uVar16 = 0; (uVar16 & 0xff) < 5; uVar16 = uVar16 + 1) {
        this = (dPa_stripesEcallBack *)gx::GXBegin(0x98,0,(uVar18 << 1) / 5 & 0xffff);
        uVar20 = 0;
        dVar22 = (double)d_particle::0_0;
        for (pJVar19 = (param_1->mChildParticles).mpHead; pJVar19 != (JSUPtrLink *)0x0;
            pJVar19 = pJVar19->mpNext) {
          this = (dPa_stripesEcallBack *)0x5;
          if ((uVar20 & 0xffff) % 5 == (uVar16 & 0xff)) {
            puVar17 = pJVar19->mpData;
            iVar15 = (int)(uint)*(ushort *)(puVar17 + 0xc0) >> (JKernel::JMath::jmaSinShift & 0x3f);
            fVar1 = (float)(dVar24 * (double)(d_particle::_6416 * *(float *)(puVar17 + 0x9c) *
                                             (param_1->mGlobalScale2D).x));
            fVar5 = -fVar1 * JKernel::JMath::jmaSinTable[iVar15];
            fVar7 = -fVar1 * JKernel::JMath::jmaCosTable[iVar15];
            fVar6 = fVar1 * JKernel::JMath::jmaSinTable[iVar15];
            fVar1 = fVar1 * JKernel::JMath::jmaCosTable[iVar15];
            fVar2 = *(float *)(puVar17 + 0x34);
            fVar3 = *(float *)(puVar17 + 0x38);
            fVar4 = *(float *)(puVar17 + 0x3c);
            fVar9 = fVar4 * fVar4 + fVar2 * fVar2 + fVar3 * fVar3;
            fVar8 = d_particle::0_0;
            fVar10 = d_particle::0_0;
            fVar11 = d_particle::1_0;
            if ((d_particle::_4264 < fVar9) &&
               (fVar8 = fVar2, fVar10 = fVar4, fVar11 = fVar3, d_particle::_4264 < fVar9)) {
              if (d_particle::0_0 < fVar9) {
                fVar8 = 1.0 / SQRT(fVar9);
                fVar9 = d_particle::0_5 * fVar8 * (d_particle::_4268 - fVar9 * fVar8 * fVar8);
              }
              fVar8 = fVar2 * fVar9;
              fVar10 = fVar4 * fVar9;
              fVar11 = fVar3 * fVar9;
            }
            fVar12 = *(float *)(puVar17 + 0x90) * fVar10 - *(float *)(puVar17 + 0x94) * fVar11;
            fVar13 = *(float *)(puVar17 + 0x94) * fVar8 - *(float *)(puVar17 + 0x8c) * fVar10;
            fVar14 = *(float *)(puVar17 + 0x8c) * fVar11 - *(float *)(puVar17 + 0x90) * fVar8;
            fVar4 = fVar14 * fVar14 + fVar12 * fVar12 + fVar13 * fVar13;
            fVar2 = d_particle::1_0;
            fVar3 = d_particle::0_0;
            fVar9 = d_particle::0_0;
            if ((d_particle::_4264 < fVar4) &&
               (fVar2 = fVar12, fVar3 = fVar14, fVar9 = fVar13, d_particle::_4264 < fVar4)) {
              if (d_particle::0_0 < fVar4) {
                fVar2 = 1.0 / SQRT(fVar4);
                fVar4 = d_particle::0_5 * fVar2 * (d_particle::_4268 - fVar4 * fVar2 * fVar2);
              }
              fVar2 = fVar12 * fVar4;
              fVar3 = fVar14 * fVar4;
              fVar9 = fVar13 * fVar4;
            }
            *(float *)(puVar17 + 0x8c) = fVar11 * fVar3 - fVar10 * fVar9;
            *(float *)(puVar17 + 0x90) = fVar10 * fVar2 - fVar8 * fVar3;
            *(float *)(puVar17 + 0x94) = fVar8 * fVar9 - fVar11 * fVar2;
            fVar4 = *(float *)(puVar17 + 0x94) * *(float *)(puVar17 + 0x94) +
                    *(float *)(puVar17 + 0x8c) * *(float *)(puVar17 + 0x8c) +
                    *(float *)(puVar17 + 0x90) * *(float *)(puVar17 + 0x90);
            if (d_particle::_4264 < fVar4) {
              if (d_particle::0_0 < fVar4) {
                fVar12 = 1.0 / SQRT(fVar4);
                fVar4 = d_particle::0_5 * fVar12 * (d_particle::_4268 - fVar4 * fVar12 * fVar12);
              }
              *(float *)(puVar17 + 0x8c) = *(float *)(puVar17 + 0x8c) * fVar4;
              *(float *)(puVar17 + 0x90) = *(float *)(puVar17 + 0x90) * fVar4;
              *(float *)(puVar17 + 0x94) = *(float *)(puVar17 + 0x94) * fVar4;
            }
            this = (dPa_stripesEcallBack *)0xcc010000;
            write_volatile_4(0xcc008000,
                             fVar5 * *(float *)(puVar17 + 0x8c) +
                             fVar7 * fVar2 + d_particle::0_0 * fVar8 + *(float *)(puVar17 + 0x28));
            write_volatile_4(0xcc008000,
                             fVar5 * *(float *)(puVar17 + 0x90) +
                             fVar7 * fVar9 + d_particle::0_0 * fVar11 + *(float *)(puVar17 + 0x2c));
            write_volatile_4(0xcc008000,
                             fVar5 * *(float *)(puVar17 + 0x94) +
                             fVar7 * fVar3 + d_particle::0_0 * fVar10 + *(float *)(puVar17 + 0x30));
            write_volatile_4(0xcc008000,d_particle::0_0);
            write_volatile_4(0xcc008000,(float)dVar22);
            write_volatile_4(0xcc008000,
                             fVar6 * *(float *)(puVar17 + 0x8c) +
                             fVar1 * fVar2 + d_particle::0_0 * fVar8 + *(float *)(puVar17 + 0x28));
            write_volatile_4(0xcc008000,
                             fVar6 * *(float *)(puVar17 + 0x90) +
                             fVar1 * fVar9 + d_particle::0_0 * fVar11 + *(float *)(puVar17 + 0x2c));
            write_volatile_4(0xcc008000,
                             fVar6 * *(float *)(puVar17 + 0x94) +
                             fVar1 * fVar3 + d_particle::0_0 * fVar10 + *(float *)(puVar17 + 0x30));
            write_volatile_4(0xcc008000,d_particle::1_0);
            write_volatile_4(0xcc008000,(float)dVar22);
            dVar22 = (double)(float)(dVar22 + dVar23);
          }
          uVar20 = uVar20 + 1;
        }
      }
    }
  }
  __psq_l0(auStack8,uVar21);
  __psq_l1(auStack8,uVar21);
  __psq_l0(auStack24,uVar21);
  __psq_l1(auStack24,uVar21);
  __psq_l0(auStack40,uVar21);
  __psq_l1(auStack40,uVar21);
  __psq_l0(auStack56,uVar21);
  __psq_l1(auStack56,uVar21);
  __psq_l0(auStack72,uVar21);
  __psq_l1(auStack72,uVar21);
  __psq_l0(auStack88,uVar21);
  __psq_l1(auStack88,uVar21);
  __psq_l0(auStack104,uVar21);
  __psq_l1(auStack104,uVar21);
  __psq_l0(auStack120,uVar21);
  __psq_l1(auStack120,uVar21);
  __psq_l0(auStack136,uVar21);
  __psq_l1(auStack136,uVar21);
  __psq_l0(auStack152,uVar21);
  __psq_l1(auStack152,uVar21);
  return this;
}


/* __thiscall dPa_kageroEcallBack::draw(JPABaseEmitter *) */

void __thiscall dPa_kageroEcallBack::draw(dPa_kageroEcallBack *this,JPABaseEmitter *param_1)

{
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dPa_bombSmokeEcallBack::execute(JPABaseEmitter *) */

void __thiscall
dPa_bombSmokeEcallBack::execute(dPa_bombSmokeEcallBack *this,JPABaseEmitter *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  ushort local_18 [2];
  uint local_14 [2];
  
  local_14[0] = *(uint *)&param_1->field_0x210 >> 0x10;
  uVar1 = *(uint *)&param_1->field_0x210 & 0xff;
  iVar3 = (int)(short)((ushort)(*(uint *)&param_1->field_0x210 >> 8) & 0xff);
  iVar2 = d_particle::cLib_calcTimer(local_14);
  if (iVar2 == 0) {
    local_18[0] = (ushort)(param_1->mGlobalPrmColor).a;
    iVar2 = SComponent::cLib_chaseS(local_18,uVar1,iVar3);
    if (iVar2 != 0) {
      param_1->mpEmitterCallBack = (JPACallBackBase *)0x0;
    }
    (param_1->mGlobalPrmColor).a = (u8)local_18[0];
  }
  *(uint *)&param_1->field_0x210 = (int)(short)uVar1 | local_14[0] << 0x10 | iVar3 << 8;
  return;
}


/* __thiscall dPa_trackEcallBack::getMaxWaterY(JGeometry::TVec3<float><float> *) */

void __thiscall dPa_trackEcallBack::getMaxWaterY(dPa_trackEcallBack *this,TVec3_float_ *pVec)

{
  uint uVar1;
  double dVar2;
  
  uVar1 = d_a_sea::daSea_ChkArea(pVec->x,pVec->z);
  if ((uVar1 & 0xff) == 0) {
    if (d_particle::_1_0E9 == this->mMaxY) {
      pVec->y = this->mBaseY;
    }
    else {
      pVec->y = this->mMaxY;
    }
  }
  else {
    dVar2 = (double)d_a_sea::daSea_calcWave((double)pVec->x,(double)pVec->z);
    pVec->y = (float)dVar2;
    if (pVec->y < this->mMaxY) {
      pVec->y = this->mMaxY;
    }
  }
  pVec->y = pVec->y + d_particle::2_0;
  return;
}


/* __thiscall dPa_trackEcallBack::setup(JPABaseEmitter *,
                                        cXyz const *,
                                        csXyz const *,
                                        signed char) */

void __thiscall
dPa_trackEcallBack::setup
          (dPa_trackEcallBack *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,
          char param_4)

{
  this->mpPos = param_2;
  this->mState = 0;
  this->mpRot = param_3;
  this->mpBaseEmitter = param_1;
  return;
}


/* __thiscall dPa_trackEcallBack::remove(void) */

int __thiscall dPa_trackEcallBack::remove(dPa_trackEcallBack *this)

{
  JPABaseEmitter *pJVar1;
  
  if (this->mpBaseEmitter == (JPABaseEmitter *)0x0) {
    return (int)this;
  }
  this->mpBaseEmitter->mpEmitterCallBack = (JPACallBackBase *)0x0;
  pJVar1 = this->mpBaseEmitter;
  pJVar1->mMaxFrame = -1;
  pJVar1->mFlags = pJVar1->mFlags | 1;
  this->mpBaseEmitter = (JPABaseEmitter *)0x0;
  return (int)this;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dPa_trackEcallBack::execute(JPABaseEmitter *) */

void __thiscall dPa_trackEcallBack::execute(dPa_trackEcallBack *this,JPABaseEmitter *param_1)

{
  float fVar1;
  float fVar2;
  short sVar3;
  cXyz *pcVar4;
  JSUPtrLink *pJVar5;
  JPABaseParticle *puVar6;
  JSUPtrLink *pJVar6;
  ushort local_38;
  ushort local_36;
  _GXColor _Stack52;
  _GXColor local_30;
  TVec3_float_ local_2c;
  TVec3_float_ local_20;
  
  d_kankyo::dKy_get_seacolor(&local_30,&_Stack52);
  (param_1->mGlobalPrmColor).r = local_30.r;
  (param_1->mGlobalPrmColor).g = local_30.g;
  (param_1->mGlobalPrmColor).b = local_30.b;
  if (this->mState == 0) {
    pcVar4 = this->mpPos;
    fVar1 = pcVar4->z;
    fVar2 = pcVar4->y;
    (param_1->mGlobalTranslation).x = pcVar4->x;
    (param_1->mGlobalTranslation).y = fVar2;
    (param_1->mGlobalTranslation).z = fVar1;
    if (this->mVel < d_particle::0_0) {
      sVar3 = this->mpRot->y + -0x8000;
    }
    else {
      sVar3 = this->mpRot->y;
    }
    JPABase::JPAGetXYZRotateMtx(0,(int)sVar3,0,&param_1->mGlobalRotation);
    local_38 = (ushort)(param_1->mGlobalPrmColor).a;
    if (ABS(this->mVel) <= this->mMinVel) {
      SComponent::cLib_chaseS(&local_38,0,5);
    }
    else {
      SComponent::cLib_chaseS(&local_38,0xff,5);
    }
    (param_1->mGlobalPrmColor).a = (u8)local_38;
  }
  else {
    local_20.x = (param_1->mGlobalTranslation).x;
    local_20.y = (param_1->mGlobalTranslation).y;
    local_20.z = (param_1->mGlobalTranslation).z;
    getMaxWaterY(this,&local_20);
    local_36 = (ushort)(param_1->mGlobalPrmColor).a;
    SComponent::cLib_chaseS(&local_36,0,10);
    (param_1->mGlobalPrmColor).a = (u8)local_36;
    if (local_36 == 0) {
      remove(this);
      return;
    }
  }
  pJVar5 = (param_1->mActiveParticles).mpHead;
  while (pJVar5 != (JSUPtrLink *)0x0) {
    pJVar6 = (JSUPtrLink *)(&pJVar5->mpData)[3];
    puVar6 = (JPABaseParticle *)pJVar5->mpData;
    local_2c.x = (puVar6->mGlobalPosition).x;
    local_2c.y = (puVar6->mGlobalPosition).y;
    local_2c.z = (puVar6->mGlobalPosition).z;
    getMaxWaterY(this,&local_2c);
    (puVar6->mGlobalPosition).x = local_2c.x;
    (puVar6->mGlobalPosition).y = local_2c.y;
    (puVar6->mGlobalPosition).z = local_2c.z;
    pJVar5 = pJVar6;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x8007f604) */
/* WARNING: Removing unreachable block (ram,0x8007f5f4) */
/* WARNING: Removing unreachable block (ram,0x8007f5ec) */
/* WARNING: Removing unreachable block (ram,0x8007f5fc) */
/* WARNING: Removing unreachable block (ram,0x8007f60c) */
/* __thiscall dPa_trackEcallBack::draw(JPABaseEmitter *) */

void __thiscall dPa_trackEcallBack::draw(dPa_trackEcallBack *this,JPABaseEmitter *pEmitter)

{
  float fVar1;
  uint trackCount;
  JPABaseParticle *pPtcl_;
  dPa_trackEcallBack *pTrack__;
  JPABaseParticle *pPtcl;
  dPa_trackEcallBack *pTrack;
  uint uVar2;
  uint uVar3;
  JSUPtrLink *pJVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
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
  TVec3_float_ local_c8;
  MTX34 MStack188;
  undefined4 local_88;
  uint uStack132;
  undefined4 local_80;
  int iStack124;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
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
  uStack132 = (pEmitter->mActiveParticles).mCount;
  if (5 < uStack132) {
    if ((dPa_control_c::mStatus & 1) != 0) {
      gx::GXSetZMode(false,GX_NEVER,false);
    }
    local_88 = 0x43300000;
    trackCount = Runtime.PPCEABI.H::__cvt_fp2unsigned
                           ((double)(d_particle::_6610 *
                                    (float)((double)CONCAT44(0x43300000,uStack132) -
                                           d_particle::_4272)));
    iStack124 = trackCount - 1;
    local_80 = 0x43300000;
    dVar11 = (double)(d_particle::1_0 /
                     (float)((double)CONCAT44(0x43300000,iStack124) - d_particle::_4272));
    gx::GXSetCullMode(0);
    mtx::PSMTXIdentity(&MStack188);
    MStack188.m[1][1] = this->mExScaleY;
    MStack188.m[1][3] = this->mExTransY * pEmitter->mTick;
    gx::GXLoadTexMtxImm(&MStack188,GX_TEXMTX1,1);
    gx::GXSetTexCoordGen2(GX_TEXCOORD1,GX_TG_MTX2x4,GX_TG_TEX0,GX_TEXMTX1,false,GX_PTIDENTITY);
    pJVar4 = (pEmitter->mActiveParticles).mpHead;
    fVar1 = d_particle::0_0;
    for (uVar3 = 0; dVar12 = (double)fVar1, uVar3 < trackCount; uVar3 = uVar3 + 1) {
      if (uVar3 == 0) {
        iVar5 = 0;
        iVar6 = 3;
        do {
          pPtcl = (JPABaseParticle *)pJVar4->mpData;
          pTrack = (dPa_trackEcallBack *)((int)this->mPos + iVar5 + -0x10);
          pTrack->mPos[0].x = (pPtcl->mPosition).x;
          pTrack->mPos[0].y = (pPtcl->mPosition).y;
          pTrack->mPos[0].z = (pPtcl->mPosition).z;
          pJVar4 = (JSUPtrLink *)(&pJVar4->mpData)[3];
          iVar5 = iVar5 + 0xc;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      else {
        gx::GXBegin(0x98,0,6);
        uVar2 = 0;
        iVar5 = 0;
        dVar9 = (double)(float)(dVar12 - dVar11);
        dVar10 = (double)d_particle::0_5;
        fVar1 = d_particle::0_0;
        do {
          dVar8 = (double)fVar1;
          pPtcl_ = (JPABaseParticle *)pJVar4->mpData;
          local_c8.x = (pPtcl_->mPosition).x;
          local_c8.y = (pPtcl_->mPosition).y;
          local_c8.z = (pPtcl_->mPosition).z;
          getMaxWaterY(this,&local_c8);
          write_volatile_4(0xcc008000,local_c8.x);
          write_volatile_4(0xcc008000,local_c8.y);
          write_volatile_4(0xcc008000,local_c8.z);
          write_volatile_4(0xcc008000,(float)dVar8);
          write_volatile_4(0xcc008000,(float)dVar12);
          pTrack__ = (dPa_trackEcallBack *)((int)this->mPos + iVar5 + -0x10);
          write_volatile_4(0xcc008000,pTrack__->mPos[0].x);
          write_volatile_4(0xcc008000,pTrack__->mPos[0].y);
          write_volatile_4(0xcc008000,pTrack__->mPos[0].z);
          write_volatile_4(0xcc008000,(float)dVar8);
          write_volatile_4(0xcc008000,(float)dVar9);
          pTrack__->mPos[0].x = local_c8.x;
          pTrack__->mPos[0].y = local_c8.y;
          pTrack__->mPos[0].z = local_c8.z;
          fVar1 = (float)(dVar8 + dVar10);
          pJVar4 = (JSUPtrLink *)(&pJVar4->mpData)[3];
          uVar2 = uVar2 + 1;
          iVar5 = iVar5 + 0xc;
        } while (uVar2 < 3);
      }
      fVar1 = (float)(dVar12 + dVar11);
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
  return;
}


/* __thiscall dPa_trackEcallBack::~dPa_trackEcallBack(void) */

void __thiscall dPa_trackEcallBack::_dPa_trackEcallBack(dPa_trackEcallBack *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dPa_trackEcallBack *)0x0;
  if (bVar1) {
    (this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&__vt;
    if ((bVar1) &&
       ((this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&::dPa_levelEcallBack::__vt, bVar1)) {
      (this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dPa_bombSmokeEcallBack::~dPa_bombSmokeEcallBack(void) */

void __thiscall dPa_bombSmokeEcallBack::_dPa_bombSmokeEcallBack(dPa_bombSmokeEcallBack *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dPa_bombSmokeEcallBack *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &::dPa_levelEcallBack::__vt, bVar1)) {
      *(undefined1 **)this = &::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dPa_bombSmokeEcallBack::setup(JPABaseEmitter *,
                                            cXyz const *,
                                            csXyz const *,
                                            signed char) */

void __thiscall
dPa_bombSmokeEcallBack::setup
          (dPa_bombSmokeEcallBack *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,
          char param_4)

{
  return;
}


/* __thiscall dPa_kageroEcallBack::~dPa_kageroEcallBack(void) */

void __thiscall dPa_kageroEcallBack::_dPa_kageroEcallBack(dPa_kageroEcallBack *this)

{
  short in_r4;
  
  if (this != (dPa_kageroEcallBack *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dPa_kageroEcallBack *)0x0) {
      *(undefined1 **)this = &::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dPa_stripesEcallBack::~dPa_stripesEcallBack(void) */

void __thiscall dPa_stripesEcallBack::_dPa_stripesEcallBack(dPa_stripesEcallBack *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dPa_stripesEcallBack *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &::dPa_levelEcallBack::__vt, bVar1)) {
      *(undefined1 **)this = &::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dPa_stripesEcallBack::setup(JPABaseEmitter *,
                                          cXyz const *,
                                          csXyz const *,
                                          signed char) */

void __thiscall
dPa_stripesEcallBack::setup
          (dPa_stripesEcallBack *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,
          char param_4)

{
  return;
}


/* __thiscall dPa_cutTurnEcallBack_c::~dPa_cutTurnEcallBack_c(void) */

void __thiscall dPa_cutTurnEcallBack_c::_dPa_cutTurnEcallBack_c(dPa_cutTurnEcallBack_c *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dPa_cutTurnEcallBack_c *)0x0;
  if (bVar1) {
    (this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&__vt;
    if ((bVar1) &&
       ((this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&::dPa_levelEcallBack::__vt, bVar1)) {
      (this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dPa_splashEcallBack::~dPa_splashEcallBack(void) */

void __thiscall dPa_splashEcallBack::_dPa_splashEcallBack(dPa_splashEcallBack *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dPa_splashEcallBack *)0x0;
  if (bVar1) {
    (this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&__vt;
    if ((bVar1) &&
       ((this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&::dPa_levelEcallBack::__vt, bVar1)) {
      (this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dPa_waveEcallBack::~dPa_waveEcallBack(void) */

void __thiscall dPa_waveEcallBack::_dPa_waveEcallBack(dPa_waveEcallBack *this)

{
  short in_r4;
  
  if (this != (dPa_waveEcallBack *)0x0) {
    (this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&__vt;
    Runtime.PPCEABI.H::__destroy_arr(this->mCollapsePos,::cXyz::_cXyz,0xc,2);
    if ((this != (dPa_waveEcallBack *)0x0) &&
       ((this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&::dPa_levelEcallBack::__vt,
       this != (dPa_waveEcallBack *)0x0)) {
      (this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dPa_ripplePcallBack::~dPa_ripplePcallBack(void) */

void __thiscall dPa_ripplePcallBack::_dPa_ripplePcallBack(dPa_ripplePcallBack *this)

{
  short in_r4;
  
  if (this != (dPa_ripplePcallBack *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dPa_ripplePcallBack *)0x0) {
      *(undefined1 **)this = &JPACallBackBase2<JPABaseEmitter*,JPABaseParticle*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPACallBackBase2<JPABaseEmitter *,JPABaseParticle *>::init(JPABaseEmitter *,
                                                                         JPABaseParticle *) */

int __thiscall
JPACallBackBase2<JPABaseEmitter*,JPABaseParticle*>::init
          (JPACallBackBase2_JPABaseEmitter__JPABaseParticle__ *this,EVP_PKEY_CTX *ctx)

{
  return (int)this;
}


/* __thiscall dPa_singleRippleEcallBack::~dPa_singleRippleEcallBack(void) */

void __thiscall
dPa_singleRippleEcallBack::_dPa_singleRippleEcallBack(dPa_singleRippleEcallBack *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dPa_singleRippleEcallBack *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &::dPa_levelEcallBack::__vt, bVar1)) {
      *(undefined1 **)this = &::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dPa_rippleEcallBack::~dPa_rippleEcallBack(void) */

void __thiscall dPa_rippleEcallBack::_dPa_rippleEcallBack(dPa_rippleEcallBack *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dPa_rippleEcallBack *)0x0;
  if (bVar1) {
    (this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&__vt;
    if ((bVar1) &&
       ((this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&::dPa_levelEcallBack::__vt, bVar1)) {
      (this->parent).vtbl = (dPa_levelEcallBack__vtbl *)&::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPACallBackBase2<JPABaseEmitter *,JPABaseParticle *>::draw(JPABaseEmitter *,
                                                                         JPABaseParticle *) */

void __thiscall
JPACallBackBase2<JPABaseEmitter*,JPABaseParticle*>::draw
          (JPACallBackBase2_JPABaseEmitter__JPABaseParticle__ *this,JPABaseEmitter *param_1,
          JPABaseParticle *param_2)

{
  return;
}


/* __thiscall dPa_selectTexEcallBack::~dPa_selectTexEcallBack(void) */

void __thiscall dPa_selectTexEcallBack::_dPa_selectTexEcallBack(dPa_selectTexEcallBack *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dPa_selectTexEcallBack *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &::dPa_levelEcallBack::__vt, bVar1)) {
      *(undefined1 **)this = &::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dPa_selectTexEcallBack::setup(JPABaseEmitter *,
                                            cXyz const *,
                                            csXyz const *,
                                            signed char) */

void __thiscall
dPa_selectTexEcallBack::setup
          (dPa_selectTexEcallBack *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,
          char param_4)

{
  return;
}


/* __thiscall JPACallBackBase2<JPABaseEmitter *,JPABaseParticle *>::execute(JPABaseEmitter *,
                                                                            JPABaseParticle *) */

void __thiscall
JPACallBackBase2<JPABaseEmitter*,JPABaseParticle*>::execute
          (JPACallBackBase2_JPABaseEmitter__JPABaseParticle__ *this,JPABaseEmitter *param_1,
          JPABaseParticle *param_2)

{
  return;
}


namespace d_particle {

/* __stdcall cLib_calcTimer<unsigned long>(unsigned long *) */

int cLib_calcTimer(int *param_1)

{
  if (*param_1 != 0) {
    *param_1 = *param_1 + -1;
  }
  return *param_1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_d_particle_cpp(void)

{
  undefined4 local_44;
  undefined4 local_3c;
  undefined4 local_34;
  
  _mTsubo = &::dPa_selectTexEcallBack::__vt;
  DAT_803e2174 = 0;
  Runtime.PPCEABI.H::__register_global_object
            (&::dPa_control_c::mTsubo,::dPa_selectTexEcallBack::_dPa_selectTexEcallBack,&_5042);
  _DAT_803e2178 = &::dPa_selectTexEcallBack::__vt;
  DAT_803e217c = 1;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e2178,::dPa_selectTexEcallBack::_dPa_selectTexEcallBack,&_5043);
  DAT_803e2180 = &::dPa_selectTexEcallBack::__vt;
  DAT_803e2184 = 2;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e2180,::dPa_selectTexEcallBack::_dPa_selectTexEcallBack,&_5044);
  DAT_803e2188 = &::dPa_selectTexEcallBack::__vt;
  DAT_803e218c = 3;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e2188,::dPa_selectTexEcallBack::_dPa_selectTexEcallBack,&_5045);
  local_34 = CONCAT31(CONCAT21(CONCAT11(l_lifeBallColor,DAT_8037b2d9),DAT_8037b2da),DAT_8037b2db);
  _mLifeBall = &::dPa_setColorEcallBack::__vt;
  DAT_803e21b8 = local_34;
  Runtime.PPCEABI.H::__register_global_object
            (&::dPa_control_c::mLifeBall,::dPa_setColorEcallBack::_dPa_setColorEcallBack,&_5046);
  local_3c = CONCAT31(CONCAT21(CONCAT11(DAT_8037b2dc,DAT_8037b2dd),DAT_8037b2de),DAT_8037b2df);
  DAT_803e21bc = &::dPa_setColorEcallBack::__vt;
  DAT_803e21c0 = local_3c;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e21bc,::dPa_setColorEcallBack::_dPa_setColorEcallBack,&_5047);
  local_44 = CONCAT31(CONCAT21(CONCAT11(DAT_8037b2e0,DAT_8037b2e1),DAT_8037b2e2),DAT_8037b2e3);
  DAT_803e21c4 = &::dPa_setColorEcallBack::__vt;
  DAT_803e21c8 = local_44;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e21c4,::dPa_setColorEcallBack::_dPa_setColorEcallBack,&_5048);
  _mStripes = &::dPa_stripesEcallBack::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::dPa_control_c::mStripes,::dPa_stripesEcallBack::_dPa_stripesEcallBack,&_5049);
  _mKagero = &::dPa_kageroEcallBack::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::dPa_control_c::mKagero,::dPa_kageroEcallBack::_dPa_kageroEcallBack,&_5050);
  ::dPa_smokeEcallBack::dPa_smokeEcallBack
            ((dPa_smokeEcallBack *)&::dPa_control_c::mSmokeEcallback,'\0','\x01','\x01','\x01');
  Runtime.PPCEABI.H::__register_global_object();
  _mSmokePcallback = &::dPa_smokePcallBack::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::dPa_control_c::mSmokePcallback,::dPa_smokePcallBack::_dPa_smokePcallBack,&_5052);
  _mSingleRippleEcallBack = &::dPa_singleRippleEcallBack::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::dPa_control_c::mSingleRippleEcallBack,
             ::dPa_singleRippleEcallBack::_dPa_singleRippleEcallBack,&_5053);
  _mRipplePcallBack = &::dPa_ripplePcallBack::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::dPa_control_c::mRipplePcallBack,::dPa_ripplePcallBack::_dPa_ripplePcallBack,&_5054);
  _mBombSmokeEcallBack = &::dPa_bombSmokeEcallBack::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::dPa_control_c::mBombSmokeEcallBack,::dPa_bombSmokeEcallBack::_dPa_bombSmokeEcallBack
             ,&_5055);
  return;
}

}

/* __thiscall dPa_setColorEcallBack::draw(JPABaseEmitter *) */

void __thiscall dPa_setColorEcallBack::draw(dPa_setColorEcallBack *this,JPABaseEmitter *param_1)

{
  _GXColor local_8 [2];
  
  local_8[0] = *(_GXColor *)(this + 4);
  gx::GXSetTevColor(GX_TEVREG1,local_8);
  return;
}


/* __thiscall dPa_setColorEcallBack::setup(JPABaseEmitter *,
                                           cXyz const *,
                                           csXyz const *,
                                           signed char) */

void __thiscall
dPa_setColorEcallBack::setup
          (dPa_setColorEcallBack *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,
          char param_4)

{
  return;
}


/* __thiscall dPa_setColorEcallBack::~dPa_setColorEcallBack(void) */

void __thiscall dPa_setColorEcallBack::_dPa_setColorEcallBack(dPa_setColorEcallBack *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dPa_setColorEcallBack *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &::dPa_levelEcallBack::__vt, bVar1)) {
      *(undefined1 **)this = &::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

