#include <JStudio_JParticle/object-particle.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JStudio_JStage/object-actor.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JKernel/JKRHeap.h>
#include <JPABase/JPAEmitterManager.h>
#include <JStudio/jstudio-object.h>
#include <mtx/mtxvec.h>
#include <JPABase/JPAMath.h>
#include <JStudio/jstudio-math.h>
#include <mtx/mtx.h>
#include <JStudio_JParticle/object-particle.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JStudio_JParticle/TAdaptor_particle/TJPACallback_.h>
#include <Demangler/JStudio_JParticle/TAdaptor_particle/TVVOOn_BEGIN_FADE_IN_.h>
#include <Demangler/JStudio_JParticle/TAdaptor_particle/TVVOOn_END_FADE_OUT_.h>
#include <Demangler/JStudio_JParticle/TAdaptor_particle.h>


namespace JStudio_JParticle {

namespace TAdaptor_particle {

namespace TVVOOn_END_FADE_OUT_ {
}
}
}

namespace JStudio_JParticle {

namespace TAdaptor_particle {

namespace TVVOOn_BEGIN_FADE_IN_ {
}
}
undefined4 aoData$1383;
undefined1 init$1384;

namespace TAdaptor_particle {
undefined1 soVVOOn_BEGIN_FADE_IN_;
undefined1 soVVOOn_END_FADE_OUT_;
}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TAdaptor_particle::TAdaptor_particle(JPAEmitterManager *,
                                                                      JStage::TSystem const *) */

void __thiscall
TAdaptor_particle::TAdaptor_particle
          (TAdaptor_particle *this,JPAEmitterManager *param_1,TSystem *param_2)

{
  *(undefined1 **)this = &JStudio::TAdaptor::__vt;
  *(TAdaptor_particle **)(this + 4) = this + 0xc;
  *(undefined4 *)(this + 8) = 0x14;
  *(undefined1 **)this = &JStudio::TAdaptor_particle::__vt;
  Runtime.PPCEABI.H::__construct_array
            (this + 0xc,JStudio::TVariableValue::TVariableValue,(undefined *)0x0,0x14,0x14);
  *(undefined1 **)this = &__vt;
  *(JPAEmitterManager **)(this + 0x19c) = param_1;
  *(undefined4 *)(this + 0x1a0) = 0;
  *(undefined1 **)(this + 0x1a4) = &::JPACallBackBase<JPABaseEmitter*>::__vt;
  *(undefined1 **)(this + 0x1a4) = &TJPACallback_::__vt;
  *(TAdaptor_particle **)(this + 0x1a8) = this;
  *(undefined4 *)(this + 0x1ac) = 0;
  *(undefined4 *)(this + 0x1b0) = 0xffffffff;
  *(undefined4 *)(this + 0x1b4) = 0;
  *(undefined4 *)(this + 0x1b8) = 0;
  *(undefined4 *)(this + 0x1bc) = 0;
  *(TSystem **)(this + 0x1c0) = param_2;
  *(undefined4 *)(this + 0x1c4) = 0;
  *(undefined4 *)(this + 0x1c8) = 0xffffffff;
  this[0x1cc] = (TAdaptor_particle)0x0;
  return;
}


namespace TAdaptor_particle {

/* __thiscall TJPACallback_::~TJPACallback_(void) */

void __thiscall
TJPACallback_::_TJPACallback_(TJPACallback_ *this)

{
  short in_r4;
  
  if (this != (TJPACallback_ *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (TJPACallback_ *)0x0) {
      *(undefined1 **)this = &::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

}

/* __thiscall TAdaptor_particle::~TAdaptor_particle(void) */

void __thiscall TAdaptor_particle::_TAdaptor_particle(TAdaptor_particle *this)

{
  short in_r4;
  
  if (this != (TAdaptor_particle *)0x0) {
    *(undefined1 **)this = &__vt;
    if (*(JPABaseEmitter **)(this + 0x1a0) != (JPABaseEmitter *)0x0) {
      JPAEmitterManager::forceDeleteEmitter
                (*(JPAEmitterManager **)(this + 0x19c),*(JPABaseEmitter **)(this + 0x1a0));
    }
    if (this != (TAdaptor_particle *)0xfffffe5c) {
      *(undefined1 **)(this + 0x1a4) = &TJPACallback_::__vt;
      if (this != (TAdaptor_particle *)0xfffffe5c) {
        *(undefined1 **)(this + 0x1a4) = &::JPACallBackBase<JPABaseEmitter*>::__vt;
      }
    }
    JStudio::TAdaptor_particle::_TAdaptor_particle((TAdaptor_particle *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TAdaptor_particle::adaptor_do_prepare(JStudio::TObject const *) */

void __thiscall
TAdaptor_particle::adaptor_do_prepare(TAdaptor_particle *this,TObject *param_1)

{
  if (init_1384 == '\0') {
    aoData_1383 = 0;
    DAT_803e8cac = _1493;
    DAT_803e8cb0 = 1;
    DAT_803e8cb4 = _1493;
    DAT_803e8cb8 = 2;
    DAT_803e8cbc = _1493;
    DAT_803e8cc0 = 3;
    DAT_803e8cc4 = _1493;
    DAT_803e8cc8 = 4;
    DAT_803e8ccc = _1493;
    DAT_803e8cd0 = 5;
    DAT_803e8cd4 = _1493;
    DAT_803e8cd8 = 6;
    DAT_803e8cdc = _1494;
    DAT_803e8ce0 = 7;
    DAT_803e8ce4 = _1494;
    DAT_803e8ce8 = 8;
    DAT_803e8cec = _1494;
    DAT_803e8cf0 = 9;
    DAT_803e8cf4 = _1495;
    DAT_803e8cf8 = 10;
    DAT_803e8cfc = _1495;
    DAT_803e8d00 = 0xb;
    DAT_803e8d04 = _1495;
    DAT_803e8d08 = 0xc;
    DAT_803e8d0c = _1495;
    DAT_803e8d10 = 0xd;
    DAT_803e8d14 = _1495;
    DAT_803e8d18 = 0xe;
    DAT_803e8d1c = _1495;
    DAT_803e8d20 = 0xf;
    DAT_803e8d24 = _1495;
    DAT_803e8d28 = 0x10;
    DAT_803e8d2c = _1495;
    DAT_803e8d30 = 0xffffffff;
    DAT_803e8d34 = MSL_C.PPCEABI.bare.H::__float_nan;
    init_1384 = '\x01';
  }
  JStudio::TAdaptor::adaptor_setVariableValue_immediate
            ((TAdaptor *)this,(TSetVariableValue_immediate *)&aoData_1383);
  *(undefined1 **)(*(int *)(this + 4) + 0x178) = &soVVOOn_BEGIN_FADE_IN_;
  *(undefined1 **)(*(int *)(this + 4) + 0x18c) = &soVVOOn_END_FADE_OUT_;
  *(TObject **)(this + 0x1ac) = param_1;
  return;
}


/* __thiscall TAdaptor_particle::adaptor_do_end(JStudio::TObject const *) */

void __thiscall
TAdaptor_particle::adaptor_do_end(TAdaptor_particle *this,TObject *param_1)

{
  return;
}


/* __thiscall TAdaptor_particle::adaptor_do_update(JStudio::TObject const *,
                                                                      unsigned long) */

void __thiscall
TAdaptor_particle::adaptor_do_update
          (TAdaptor_particle *this,TObject *param_1,ulong param_2)

{
  if (*(uint *)(this + 0x1b8) == 0) {
    return;
  }
  if (*(uint *)(this + 0x1b8) <= *(uint *)(this + 0x1bc)) {
    return;
  }
  *(uint *)(this + 0x1bc) = *(uint *)(this + 0x1bc) + param_2;
  if (*(uint *)(this + 0x1bc) < *(uint *)(this + 0x1b8)) {
    return;
  }
  if (*(int *)(this + 0x1b4) != 2) {
    *(undefined4 *)(this + 0x1b4) = 0;
  }
  *(undefined4 *)(this + 0x1b8) = 0;
  *(undefined4 *)(this + 0x1bc) = 0;
  return;
}


/* __thiscall
   TAdaptor_particle::adaptor_do_PARTICLE(JStudio::data::TEOperationData,
                                                                        void const *,
                                                                        unsigned long) */

void __thiscall
TAdaptor_particle::adaptor_do_PARTICLE
          (TAdaptor_particle *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  if (param_1 != 0x19) {
    return;
  }
                    /* WARNING: Load size is inaccurate */
  *(undefined4 *)(this + 0x1b0) = *param_2;
  return;
}


/* __thiscall
   TAdaptor_particle::adaptor_do_PARENT(JStudio::data::TEOperationData,
                                                                      void const *,
                                                                      unsigned long) */

void __thiscall
TAdaptor_particle::adaptor_do_PARENT
          (TAdaptor_particle *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0x18) && (piVar1 = *(int **)(this + 0x1c0), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x38))(piVar1,param_2,0);
    *(undefined4 *)(this + 0x1c4) = uVar2;
  }
  return;
}


/* __thiscall
   TAdaptor_particle::adaptor_do_PARENT_NODE(JStudio::data::TEOperationData,
                                                                           void const *,
                                                                           unsigned long) */

void __thiscall
TAdaptor_particle::adaptor_do_PARENT_NODE
          (TAdaptor_particle *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_1 == 0x19) {
                    /* WARNING: Load size is inaccurate */
    *(undefined4 *)(this + 0x1c8) = *param_2;
  }
  else {
    if ((((int)param_1 < 0x19) && (0x17 < (int)param_1)) &&
       (piVar1 = *(int **)(this + 0x1c4), piVar1 != (int *)0x0)) {
      uVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,param_2);
      *(undefined4 *)(this + 0x1c8) = uVar2;
    }
  }
  return;
}


/* __thiscall
   TAdaptor_particle::adaptor_do_PARENT_ENABLE(JStudio::data::TEOperationData,
                                                                             void const *,
                                                                             unsigned long) */

void __thiscall
TAdaptor_particle::adaptor_do_PARENT_ENABLE
          (TAdaptor_particle *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  if (param_1 != 2) {
    return;
  }
                    /* WARNING: Load size is inaccurate */
  this[0x1cc] = (TAdaptor_particle)('\x01' - (*param_2 == 0));
  return;
}


namespace TAdaptor_particle {

/* WARNING: Removing unreachable block (ram,0x80279e0c) */
/* __thiscall TVVOOn_BEGIN_FADE_IN_::operator ()(float,
                                                                                       
   JStudio::TAdaptor *) const */

void __thiscall
TVVOOn_BEGIN_FADE_IN_::operator___
          (TVVOOn_BEGIN_FADE_IN_ *this,float param_1,TAdaptor *param_2)

{
  JPABaseEmitter *pJVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  TVec3_float_ local_2c;
  undefined auStack8 [8];
  
  dVar5 = (double)param_1;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar3 = *(undefined4 *)(param_2 + 0x1b0);
  if (*(JPABaseEmitter **)(param_2 + 0x1a0) != (JPABaseEmitter *)0x0) {
    JPAEmitterManager::forceDeleteEmitter
              (*(JPAEmitterManager **)(param_2 + 0x19c),*(JPABaseEmitter **)(param_2 + 0x1a0));
  }
  local_2c.x = _1571;
  local_2c.y = DAT_80366cac;
  local_2c.z = DAT_80366cb0;
  pJVar1 = JPAEmitterManager::createSimpleEmitterID
                     (*(JPAEmitterManager **)(param_2 + 0x19c),&local_2c,(ushort)uVar3,
                      (uchar)((uint)uVar3 >> 0x18),(uchar)((uint)uVar3 >> 0x10),
                      (JPACallBackBase *)(param_2 + 0x1a4),(JPACallBackBase2 *)0x0);
  *(JPABaseEmitter **)(param_2 + 0x1a0) = pJVar1;
  iVar2 = *(int *)(param_2 + 0x1a0);
  if (iVar2 != 0) {
    *(uint *)(iVar2 + 0x20c) = *(uint *)(iVar2 + 0x20c) | 0x40;
    *(undefined4 *)(param_2 + 0x1b4) = 1;
    uVar3 = Runtime.PPCEABI.H::__cvt_fp2unsigned(dVar5);
    *(undefined4 *)(param_2 + 0x1b8) = uVar3;
    *(undefined4 *)(param_2 + 0x1bc) = 0;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* __thiscall TVVOOn_END_FADE_OUT_::operator ()(float,
                                                                                      
   JStudio::TAdaptor *) const */

TVVOOn_END_FADE_OUT_ * __thiscall
TVVOOn_END_FADE_OUT_::operator___
          (TVVOOn_END_FADE_OUT_ *this,float param_1,TAdaptor *param_2)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  
  dVar2 = (double)param_1;
  if (*(int *)(param_2 + 0x1a0) != 0) {
    if ((*(int *)(param_2 + 0x1b4) == 1) && (*(int *)(param_2 + 0x1bc) != 0)) {
      *(undefined4 *)(param_2 + 0x1b4) = 2;
      dVar3 = ((double)CONCAT44(0x43300000,*(undefined4 *)(param_2 + 0x1b8)) - _1597) /
              ((double)CONCAT44(0x43300000,*(undefined4 *)(param_2 + 0x1bc)) - _1597);
      uVar1 = Runtime.PPCEABI.H::__cvt_fp2unsigned(dVar2 * dVar3);
      *(undefined4 *)(param_2 + 0x1b8) = uVar1;
      this = (TVVOOn_END_FADE_OUT_ *)Runtime.PPCEABI.H::__cvt_fp2unsigned(dVar2 * (dVar3 - _1595));
      *(TVVOOn_END_FADE_OUT_ **)(param_2 + 0x1bc) = this;
    }
    else {
      *(undefined4 *)(param_2 + 0x1b4) = 2;
      this = (TVVOOn_END_FADE_OUT_ *)Runtime.PPCEABI.H::__cvt_fp2unsigned(dVar2);
      *(TVVOOn_END_FADE_OUT_ **)(param_2 + 0x1b8) = this;
      *(undefined4 *)(param_2 + 0x1bc) = 0;
    }
  }
  return this;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8027a298) */
/* __thiscall TJPACallback_::execute(JPABaseEmitter *) */

void __thiscall
TJPACallback_::execute
          (TJPACallback_ *this,JPABaseEmitter *param_1)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  int iVar4;
  u8 uVar5;
  int *piVar6;
  char cVar7;
  int iVar8;
  int iVar9;
  cXyz *pcVar10;
  Vec *in_r7;
  undefined4 uVar11;
  double dVar12;
  undefined8 in_f31;
  double dVar13;
  _GXColor local_108;
  float local_104;
  float local_100;
  float local_fc;
  cXyz cStack248;
  undefined4 local_ec;
  float local_e8;
  undefined4 local_e4;
  cXyz local_e0;
  undefined4 local_d4;
  float local_d0;
  undefined4 local_cc;
  MTX34 MStack200;
  MTX34 MStack152;
  MTX34 MStack104;
  double local_38;
  longlong local_30;
  double local_28;
  undefined auStack8 [8];
  
  dVar13 = _1714;
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  bVar3 = false;
  if (((param_1->mFlags & 8) != 0) &&
     ((param_1->mActiveParticles).mCount + (param_1->mChildParticles).mCount == 0)) {
    bVar3 = true;
  }
  if (bVar3) {
    *(undefined4 *)(*(int *)(this + 4) + 0x1b4) = 0;
    *(undefined4 *)(*(int *)(this + 4) + 0x1b8) = 0;
    *(undefined4 *)(*(int *)(this + 4) + 0x1bc) = 0;
    JPAEmitterManager::forceDeleteEmitter
              (*(JPAEmitterManager **)(*(int *)(this + 4) + 0x19c),param_1);
    *(undefined4 *)(*(int *)(this + 4) + 0x1a0) = 0;
  }
  else {
    iVar8 = *(int *)(this + 4);
    iVar9 = *(int *)(iVar8 + 0x1b8);
    local_38 = (double)CONCAT44(0x43300000,iVar9);
    dVar12 = local_38 - _1597;
    iVar4 = *(int *)(iVar8 + 0x1b4);
    if (iVar4 == 2) {
      if (iVar9 == 0) {
        if (param_1 != (JPABaseEmitter *)0x0) {
          param_1->mFlags = param_1->mFlags | 1;
          param_1->mMaxFrame = 1;
        }
      }
      else {
        local_38 = (double)CONCAT44(0x43300000,iVar9 - *(int *)(iVar8 + 0x1bc));
        dVar13 = (local_38 - _1597) / dVar12;
      }
    }
    else {
      dVar13 = _1595;
      if (((iVar4 < 2) && (0 < iVar4)) && (iVar9 != 0)) {
        local_38 = (double)CONCAT44(0x43300000,*(undefined4 *)(iVar8 + 0x1bc));
        dVar13 = (local_38 - _1597) / dVar12;
      }
    }
    iVar8 = *(int *)(*(int *)(this + 8) + 0x14);
    param_1->mFlags = param_1->mFlags | 4;
    JStudio::TAdaptor::adaptor_getVariableValue_Vec
              (*(TAdaptor **)(this + 4),(Vec *)&local_e0,
               (ulong *)&JStudio::TAdaptor_particle::sauVariableValue_3_TRANSLATION_XYZ);
    JStudio::TAdaptor::adaptor_getVariableValue_Vec
              (*(TAdaptor **)(this + 4),(Vec *)&local_d4,
               (ulong *)&JStudio::TAdaptor_particle::sauVariableValue_3_ROTATION_XYZ);
    JStudio::TAdaptor::adaptor_getVariableValue_Vec
              (*(TAdaptor **)(this + 4),(Vec *)&local_104,
               (ulong *)&JStudio::TAdaptor_particle::sauVariableValue_3_SCALING_XYZ);
    iVar4 = *(int *)(this + 4);
    if (*(char *)(iVar4 + 0x1cc) == '\0') {
      if (*(char *)(iVar8 + 0x74) == '\0') {
        pcVar10 = &local_e0;
      }
      else {
        mtx::PSMTXMultVec((MTX34 *)(iVar8 + 0x98),&local_e0,&cStack248);
        local_ec = local_d4;
        local_e8 = local_d0 + *(float *)(iVar8 + 0x90);
        local_e4 = local_cc;
        pcVar10 = &cStack248;
      }
      fVar1 = pcVar10->y;
      fVar2 = pcVar10->z;
      (param_1->mGlobalTranslation).x = pcVar10->x;
      (param_1->mGlobalTranslation).y = fVar1;
      (param_1->mGlobalTranslation).z = fVar2;
      iVar4 = (int)(_1715 * ((double)pcVar10[1].x / _1716));
      local_38 = (double)(longlong)iVar4;
      iVar8 = (int)(_1715 * ((double)pcVar10[1].y / _1716));
      local_30 = (longlong)iVar8;
      iVar9 = (int)(_1715 * ((double)pcVar10[1].z / _1716));
      local_28 = (double)(longlong)iVar9;
      JPABase::JPAGetXYZRotateMtx
                ((int)(short)iVar4,(int)(short)iVar8,(int)(short)iVar9,&param_1->mGlobalRotation);
      (param_1->mGlobalScale).x = local_104;
      (param_1->mGlobalScale).y = local_100;
      (param_1->mGlobalScale).z = local_fc;
      (param_1->mGlobalScale2D).x = local_104;
      (param_1->mGlobalScale2D).y = local_100;
      (param_1->mGlobalScale2D).z = local_fc;
    }
    else {
      piVar6 = *(int **)(iVar4 + 0x1c4);
      if ((piVar6 == (int *)0x0) ||
         (cVar7 = (**(code **)(*piVar6 + 0x34))(piVar6,*(undefined4 *)(iVar4 + 0x1c8),&MStack104),
         cVar7 == '\0')) goto LAB_8027a298;
      JStudio::math::getTransformation_SRxyzT
                ((math *)&MStack152,&local_104,(Vec *)&local_d4,(Vec *)&local_e0,in_r7);
      mtx::PSMTXConcat(&MStack104,&MStack152,&MStack200);
      JPABase::JPASetRMtxSTVecfromMtx
                (&MStack200,&param_1->mGlobalRotation,&param_1->mGlobalScale,
                 &param_1->mGlobalTranslation);
    }
    JStudio::TAdaptor::adaptor_getVariableValue_GXColor
              (*(TAdaptor **)(this + 4),&local_108,
               (ulong *)&JStudio::TAdaptor_particle::sauVariableValue_4_COLOR_RGBA);
    (param_1->mGlobalPrmColor).r = local_108.r;
    (param_1->mGlobalPrmColor).g = local_108.g;
    (param_1->mGlobalPrmColor).b = local_108.b;
    local_28 = (double)CONCAT44(0x43300000,(uint)local_108.a);
    dVar13 = dVar13 * (local_28 - _1597);
    uVar5 = 0xff;
    if (dVar13 < _1717) {
      iVar4 = (int)dVar13;
      local_30 = (longlong)iVar4;
      uVar5 = (u8)iVar4;
    }
    (param_1->mGlobalPrmColor).a = uVar5;
    JStudio::TAdaptor::adaptor_getVariableValue_GXColor
              (*(TAdaptor **)(this + 4),&local_108,
               (ulong *)&JStudio::TAdaptor_particle::sauVariableValue_4_COLOR1_RGBA);
    (param_1->mGlobalEnvColor).r = local_108.r;
    (param_1->mGlobalEnvColor).g = local_108.g;
    (param_1->mGlobalEnvColor).b = local_108.b;
    param_1->mFlags = param_1->mFlags & 0xfffffffb;
  }
LAB_8027a298:
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  return;
}


/* __thiscall
   TVVOOn_END_FADE_OUT_::~TVVOOn_END_FADE_OUT_(void) */

void __thiscall
TVVOOn_END_FADE_OUT_::_TVVOOn_END_FADE_OUT_
          (TVVOOn_END_FADE_OUT_ *this)

{
  short in_r4;
  
  if (this != (TVVOOn_END_FADE_OUT_ *)0x0) {
    *(undefined1 **)this = &__vt;
    JStudio::TVariableValue::TOutput::_TOutput((TOutput *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall
   TVVOOn_BEGIN_FADE_IN_::~TVVOOn_BEGIN_FADE_IN_(void) */

void __thiscall
TVVOOn_BEGIN_FADE_IN_::_TVVOOn_BEGIN_FADE_IN_
          (TVVOOn_BEGIN_FADE_IN_ *this)

{
  short in_r4;
  
  if (this != (TVVOOn_BEGIN_FADE_IN_ *)0x0) {
    *(undefined1 **)this = &__vt;
    JStudio::TVariableValue::TOutput::_TOutput((TOutput *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_object_particle_cpp(void)

{
  _soVVOOn_BEGIN_FADE_IN_ = &TAdaptor_particle::TVVOOn_BEGIN_FADE_IN_::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&TAdaptor_particle::soVVOOn_BEGIN_FADE_IN_,
             TAdaptor_particle::TVVOOn_BEGIN_FADE_IN_::_TVVOOn_BEGIN_FADE_IN_,&_1721);
  _soVVOOn_END_FADE_OUT_ = &TAdaptor_particle::TVVOOn_END_FADE_OUT_::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&TAdaptor_particle::soVVOOn_END_FADE_OUT_,
             TAdaptor_particle::TVVOOn_END_FADE_OUT_::_TVVOOn_END_FADE_OUT_,&_1722);
  return;
}

