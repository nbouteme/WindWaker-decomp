#include <JStudio_JStage/object-actor.h>
#include <JStudio_JStage/object-actor.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JStudio/jstudio-object.h>
#include <JKernel/JKRHeap.h>
#include <mtx/mtxvec.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <JStudio_JStage/object.h>
#include <JStudio/functionvalue.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JStudio/TVariableValue.h>
#include <Demangler/JStudio_JStage/TAdaptor_actor.h>
#include <JStudio_JStage/TVariableValueOutput_object_<JStudio_JStage::TAdaptor_actor,JStage::TActor>.h>
#include <JStudio_JStage/TAdaptor_actor/TVVOutput_ANIMATION_FRAME_.h>


namespace JStudio_JStage {

namespace TAdaptor_actor {
undefined1 saoVVOutput_;
undefined1 saoVVOutput_ANIMATION_FRAME_;
}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TAdaptor_actor::TAdaptor_actor(JStage::TSystem const *,
                                                             JStage::TActor *) */

void __thiscall
TAdaptor_actor::TAdaptor_actor
          (TAdaptor_actor *this,TSystem *param_1,TActor *param_2)

{
  *(undefined1 **)this = &JStudio::TAdaptor::__vt;
  *(TAdaptor_actor **)(this + 4) = this + 0xc;
  *(undefined4 *)(this + 8) = 0xe;
  *(undefined1 **)this = &JStudio::TAdaptor_actor::__vt;
  Runtime.PPCEABI.H::__construct_array
            (this + 0xc,JStudio::TVariableValue::TVariableValue,(undefined *)0x0,0x14,0xe);
  *(undefined1 **)this = &__vt;
  *(TSystem **)(this + 0x124) = param_1;
  *(TActor **)(this + 0x128) = param_2;
  *(undefined4 *)(this + 300) = 0;
  *(undefined4 *)(this + 0x130) = 0xffffffff;
  *(undefined4 *)(this + 0x134) = 0;
  *(undefined4 *)(this + 0x138) = 0xffffffff;
  *(undefined4 *)(this + 0x13c) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  return;
}


/* __thiscall TAdaptor_actor::~TAdaptor_actor(void) */

void __thiscall TAdaptor_actor::_TAdaptor_actor(TAdaptor_actor *this)

{
  short in_r4;
  
  if (this != (TAdaptor_actor *)0x0) {
    *(undefined1 **)this = &__vt;
    (**(code **)(*(int *)this + 0x14))(this,0);
    JStudio::TAdaptor_actor::_TAdaptor_actor((TAdaptor_actor *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TAdaptor_actor::adaptor_do_prepare(JStudio::TObject const *) */

void __thiscall
TAdaptor_actor::adaptor_do_prepare(TAdaptor_actor *this,TObject *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  for (puVar1 = &saoVVOutput_; *(int *)(puVar1 + 4) != -1; puVar1 = puVar1 + 0x20) {
    puVar2 = puVar1;
    if (puVar1 == (undefined1 *)0x0) {
      puVar2 = &JStudio::TVariableValue::soOutput_none_;
    }
    *(undefined1 **)(*(int *)(this + 4) + *(int *)(puVar1 + 4) * 0x14 + 0x10) = puVar2;
  }
  for (puVar1 = &saoVVOutput_ANIMATION_FRAME_; *(int *)(puVar1 + 4) != -1; puVar1 = puVar1 + 0x30) {
    puVar2 = puVar1;
    if (puVar1 == (undefined1 *)0x0) {
      puVar2 = &JStudio::TVariableValue::soOutput_none_;
    }
    *(undefined1 **)(*(int *)(this + 4) + *(int *)(puVar1 + 4) * 0x14 + 0x10) = puVar2;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TAdaptor_actor::adaptor_do_begin(JStudio::TObject const *) */

void __thiscall
TAdaptor_actor::adaptor_do_begin(TAdaptor_actor *this,TObject *param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  void *extraout_r4;
  void *pvVar4;
  int *piVar5;
  undefined *puVar6;
  cXyz *pcVar7;
  double dVar8;
  Vec aVStack88 [12];
  cXyz cStack76;
  undefined4 local_40;
  float local_3c;
  undefined4 local_38;
  cXyz cStack52;
  undefined4 local_28;
  float local_24;
  undefined4 local_20;
  
  piVar5 = *(int **)(this + 0x128);
  uVar2 = (**(code **)(*piVar5 + 0x14))(piVar5);
  (**(code **)(*piVar5 + 0x18))(piVar5,uVar2 | 1);
  puVar6 = param_1[5].vtbl;
  (**(code **)(**(int **)(this + 0x128) + 0x38))(*(int **)(this + 0x128),&cStack52);
  (**(code **)(**(int **)(this + 0x128) + 0x48))(*(int **)(this + 0x128),&local_28);
  (**(code **)(**(int **)(this + 0x128) + 0x40))(*(int **)(this + 0x128),aVStack88);
  if (puVar6[0x75] == '\0') {
    pcVar7 = &cStack52;
  }
  else {
    mtx::PSMTXMultVec((MTX34 *)(puVar6 + 200),&cStack52,&cStack76);
    local_40 = local_28;
    local_3c = local_24 + *(float *)(puVar6 + 0x94);
    local_38 = local_20;
    pcVar7 = &cStack76;
  }
  JStudio::TAdaptor::adaptor_setVariableValue_Vec
            ((TAdaptor *)this,(ulong *)&JStudio::TAdaptor_actor::sauVariableValue_3_TRANSLATION_XYZ,
             (Vec *)pcVar7);
  JStudio::TAdaptor::adaptor_setVariableValue_Vec
            ((TAdaptor *)this,(ulong *)&JStudio::TAdaptor_actor::sauVariableValue_3_ROTATION_XYZ,
             (Vec *)(pcVar7 + 1));
  dVar8 = (double)JStudio::TAdaptor::adaptor_setVariableValue_Vec
                            ((TAdaptor *)this,
                             (ulong *)&JStudio::TAdaptor_actor::sauVariableValue_3_SCALING_XYZ,
                             aVStack88);
  pvVar4 = extraout_r4;
  for (puVar1 = &saoVVOutput_; *(int *)(puVar1 + 4) != -1; puVar1 = puVar1 + 0x20) {
    Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(puVar1 + 0x14),*(void **)(this + 0x128),pvVar4);
    iVar3 = *(int *)(this + 4) + *(int *)(puVar1 + 4) * 0x14;
    *(code **)(iVar3 + 8) = JStudio::TVariableValue::update_immediate_;
    *(undefined4 *)(iVar3 + 4) = 0;
    *(float *)(iVar3 + 0xc) = (float)dVar8;
  }
  for (puVar1 = &saoVVOutput_ANIMATION_FRAME_; *(int *)(puVar1 + 4) != -1; puVar1 = puVar1 + 0x30) {
    Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(puVar1 + 0x18),*(void **)(this + 0x128),pvVar4);
    iVar3 = *(int *)(this + 4) + *(int *)(puVar1 + 4) * 0x14;
    *(code **)(iVar3 + 8) = JStudio::TVariableValue::update_immediate_;
    *(undefined4 *)(iVar3 + 4) = 0;
    *(float *)(iVar3 + 0xc) = (float)dVar8;
  }
  return;
}


/* __thiscall TAdaptor_actor::adaptor_do_end(JStudio::TObject const *) */

void __thiscall
TAdaptor_actor::adaptor_do_end(TAdaptor_actor *this,TObject *param_1)

{
  uint uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(this + 0x128);
  uVar1 = (**(code **)(*piVar2 + 0x14))(piVar2);
  (**(code **)(*piVar2 + 0x18))(piVar2,uVar1 & 0xfffffffe);
  return;
}


/* __thiscall TAdaptor_actor::adaptor_do_update(JStudio::TObject const *,
                                                                unsigned long) */

void __thiscall
TAdaptor_actor::adaptor_do_update
          (TAdaptor_actor *this,TObject *param_1,ulong param_2)

{
  undefined *puVar1;
  cXyz *pcVar2;
  Vec aVStack72 [12];
  cXyz cStack60;
  undefined4 local_30;
  float local_2c;
  undefined4 local_28;
  cXyz cStack36;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  
  puVar1 = param_1[5].vtbl;
  JStudio::TAdaptor::adaptor_getVariableValue_Vec
            ((TAdaptor *)this,(Vec *)&cStack36,
             (ulong *)&JStudio::TAdaptor_actor::sauVariableValue_3_TRANSLATION_XYZ);
  JStudio::TAdaptor::adaptor_getVariableValue_Vec
            ((TAdaptor *)this,(Vec *)&local_18,
             (ulong *)&JStudio::TAdaptor_actor::sauVariableValue_3_ROTATION_XYZ);
  JStudio::TAdaptor::adaptor_getVariableValue_Vec
            ((TAdaptor *)this,aVStack72,
             (ulong *)&JStudio::TAdaptor_actor::sauVariableValue_3_SCALING_XYZ);
  if (puVar1[0x74] == '\0') {
    pcVar2 = &cStack36;
  }
  else {
    mtx::PSMTXMultVec((MTX34 *)(puVar1 + 0x98),&cStack36,&cStack60);
    local_30 = local_18;
    local_2c = local_14 + *(float *)(puVar1 + 0x90);
    local_28 = local_10;
    pcVar2 = &cStack60;
  }
  (**(code **)(**(int **)(this + 0x128) + 0x3c))(*(int **)(this + 0x128),pcVar2);
  (**(code **)(**(int **)(this + 0x128) + 0x4c))(*(int **)(this + 0x128),pcVar2 + 1);
  (**(code **)(**(int **)(this + 0x128) + 0x44))(*(int **)(this + 0x128),aVStack72);
  return;
}


/* __thiscall TAdaptor_actor::adaptor_do_data(JStudio::TObject const *,
                                                              void const *,
                                                              unsigned long,
                                                              void const *,
                                                              unsigned long) */

void __thiscall
TAdaptor_actor::adaptor_do_data
          (TAdaptor_actor *this,TObject *param_1,void *param_2,ulong param_3,void *param_4,
          ulong param_5)

{
  TAdaptor_object_::adaptor_data_
            (*(TAdaptor_object_ **)(this + 0x128),(TObject *)param_2,(void *)param_3,(ulong)param_4,
             (void *)param_5,param_5);
  return;
}


/* __thiscall TAdaptor_actor::adaptor_do_SHAPE(JStudio::data::TEOperationData,
                                                               void const *,
                                                               unsigned long) */

void __thiscall
TAdaptor_actor::adaptor_do_SHAPE
          (TAdaptor_actor *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = _881;
  local_14 = DAT_80397a54;
  local_10 = DAT_80397a58;
  setJSG_ID___Q214JStudio_JStage14TAdaptor_actorFMQ26JStage6TActorFPCvPvUl_vQ37JStudio4data15TEOperationDataPCvUl
            (this,&local_18,param_1,param_2,param_3);
  return;
}


/* __thiscall TAdaptor_actor::adaptor_do_ANIMATION(JStudio::data::TEOperationData,
                                                                   void const *,
                                                                   unsigned long) */

void __thiscall
TAdaptor_actor::adaptor_do_ANIMATION
          (TAdaptor_actor *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = _890;
  local_14 = DAT_80397a60;
  local_10 = DAT_80397a64;
  setJSG_ID___Q214JStudio_JStage14TAdaptor_actorFMQ26JStage6TActorFPCvPvUl_vQ37JStudio4data15TEOperationDataPCvUl
            (this,&local_18,param_1,param_2,param_3);
  return;
}


/* __thiscall
   TAdaptor_actor::adaptor_do_ANIMATION_MODE(JStudio::data::TEOperationData,
                                                                        void const *,
                                                                        unsigned long) */

void __thiscall
TAdaptor_actor::adaptor_do_ANIMATION_MODE
          (TAdaptor_actor *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  if (param_1 != 2) {
    return;
  }
                    /* WARNING: Load size is inaccurate */
  *(undefined4 *)(this + 0x13c) = *param_2;
  return;
}


/* __thiscall
   TAdaptor_actor::adaptor_do_TEXTURE_ANIMATION(JStudio::data::TEOperationData,
                                                                           void const *,
                                                                           unsigned long) */

void __thiscall
TAdaptor_actor::adaptor_do_TEXTURE_ANIMATION
          (TAdaptor_actor *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = _907;
  local_14 = DAT_80397a6c;
  local_10 = DAT_80397a70;
  setJSG_ID___Q214JStudio_JStage14TAdaptor_actorFMQ26JStage6TActorFPCvPvUl_vQ37JStudio4data15TEOperationDataPCvUl
            (this,&local_18,param_1,param_2,param_3);
  return;
}


/* __thiscall
   TAdaptor_actor::adaptor_do_TEXTURE_ANIMATION_MODE(JStudio::data::TEOperationData,
                                                                                void const *,
                                                                                unsigned long) */

void __thiscall
TAdaptor_actor::adaptor_do_TEXTURE_ANIMATION_MODE
          (TAdaptor_actor *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  if (param_1 != 2) {
    return;
  }
                    /* WARNING: Load size is inaccurate */
  *(undefined4 *)(this + 0x140) = *param_2;
  return;
}


/* __thiscall TAdaptor_actor::adaptor_do_PARENT(JStudio::data::TEOperationData,
                                                                void const *,
                                                                unsigned long) */

void __thiscall
TAdaptor_actor::adaptor_do_PARENT
          (TAdaptor_actor *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0x18) {
    uVar1 = (**(code **)(**(int **)(this + 0x124) + 0x38))(*(int **)(this + 0x124),param_2,0);
    *(undefined4 *)(this + 300) = uVar1;
  }
  return;
}


/* __thiscall TAdaptor_actor::adaptor_do_PARENT_NODE(JStudio::data::TEOperationData,
                                                                     void const *,
                                                                     unsigned long) */

void __thiscall
TAdaptor_actor::adaptor_do_PARENT_NODE
          (TAdaptor_actor *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_1 == 0x19) {
                    /* WARNING: Load size is inaccurate */
    *(undefined4 *)(this + 0x130) = *param_2;
  }
  else {
    if ((((int)param_1 < 0x19) && (0x17 < (int)param_1)) &&
       (piVar1 = *(int **)(this + 300), piVar1 != (int *)0x0)) {
      uVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,param_2);
      *(undefined4 *)(this + 0x130) = uVar2;
    }
  }
  return;
}


/* __thiscall
   TAdaptor_actor::adaptor_do_PARENT_ENABLE(JStudio::data::TEOperationData,
                                                                       void const *,
                                                                       unsigned long) */

void __thiscall
TAdaptor_actor::adaptor_do_PARENT_ENABLE
          (TAdaptor_actor *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 2) {
    uVar1 = 0;
    uVar2 = 0xffffffff;
                    /* WARNING: Load size is inaccurate */
    if (*param_2 != 0) {
      uVar1 = *(undefined4 *)(this + 300);
      uVar2 = *(undefined4 *)(this + 0x130);
    }
    (**(code **)(**(int **)(this + 0x128) + 0x28))(*(int **)(this + 0x128),uVar1,uVar2);
  }
  return;
}


/* __thiscall TAdaptor_actor::adaptor_do_RELATION(JStudio::data::TEOperationData,
                                                                  void const *,
                                                                  unsigned long) */

void __thiscall
TAdaptor_actor::adaptor_do_RELATION
          (TAdaptor_actor *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0x18) {
    uVar1 = (**(code **)(**(int **)(this + 0x124) + 0x38))(*(int **)(this + 0x124),param_2,0);
    *(undefined4 *)(this + 0x134) = uVar1;
  }
  return;
}


/* __thiscall
   TAdaptor_actor::adaptor_do_RELATION_NODE(JStudio::data::TEOperationData,
                                                                       void const *,
                                                                       unsigned long) */

void __thiscall
TAdaptor_actor::adaptor_do_RELATION_NODE
          (TAdaptor_actor *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_1 == 0x19) {
                    /* WARNING: Load size is inaccurate */
    *(undefined4 *)(this + 0x138) = *param_2;
  }
  else {
    if ((((int)param_1 < 0x19) && (0x17 < (int)param_1)) &&
       (piVar1 = *(int **)(this + 0x134), piVar1 != (int *)0x0)) {
      uVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,param_2);
      *(undefined4 *)(this + 0x138) = uVar2;
    }
  }
  return;
}


/* __thiscall
   TAdaptor_actor::adaptor_do_RELATION_ENABLE(JStudio::data::TEOperationData,
                                                                         void const *,
                                                                         unsigned long) */

void __thiscall
TAdaptor_actor::adaptor_do_RELATION_ENABLE
          (TAdaptor_actor *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  if (param_1 == 2) {
                    /* WARNING: Load size is inaccurate */
    (**(code **)(**(int **)(this + 0x128) + 0x2c))
              (*(int **)(this + 0x128),*param_2 != 0,*(undefined4 *)(this + 0x134),
               *(undefined4 *)(this + 0x138));
  }
  return;
}


void 
     setJSG_ID___Q214JStudio_JStage14TAdaptor_actorFMQ26JStage6TActorFPCvPvUl_vQ37JStudio4data15TEOperationDataPCvUl
               (int param_1,PTMF *param_2,int param_3,void **param_4)

{
  if (param_3 == 0x19) {
    Runtime.PPCEABI.H::__ptmf_scall(param_2,*(void **)(param_1 + 0x128),*param_4);
  }
  return;
}


namespace TAdaptor_actor {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80276bd8) */
/* WARNING: Removing unreachable block (ram,0x80276be0) */
/* __thiscall TVVOutput_ANIMATION_FRAME_::operator ()(float,
                                                                                      
   JStudio::TAdaptor *) const */

void __thiscall
TVVOutput_ANIMATION_FRAME_::operator___
          (TVVOutput_ANIMATION_FRAME_ *this,float param_1,TAdaptor *param_2)

{
  code *pcVar1;
  TAdaptor *extraout_r4;
  uint uVar2;
  void *this_00;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar4 = (double)param_1;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  this_00 = *(void **)(param_2 + 0x128);
  uVar2 = *(uint *)(param_2 + *(int *)(this + 8) + -1);
  dVar5 = dVar4;
  Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 0x24),this_00,param_2);
  if ((uVar2 >> 8 & 0xff) == 1) {
    dVar5 = (double)(float)(dVar4 - dVar5);
  }
  if ((double)_1006 < dVar4) {
    pcVar1 = (code *)JStudio::TFunctionValue::toFunction_outside
                               ((TFunctionValue *)(uVar2 & 0xff),(int)param_2);
    (*pcVar1)(dVar5,dVar4);
    param_2 = extraout_r4;
  }
  Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 0xc),this_00,param_2);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return;
}


/* __thiscall
   TVVOutput_ANIMATION_FRAME_::~TVVOutput_ANIMATION_FRAME_(void) */

void __thiscall
TVVOutput_ANIMATION_FRAME_::_TVVOutput_ANIMATION_FRAME_
          (TVVOutput_ANIMATION_FRAME_ *this)

{
  short in_r4;
  
  if (this != (TVVOutput_ANIMATION_FRAME_ *)0x0) {
    *(undefined1 **)this = &__vt;
    JStudio::TVariableValue::TOutput::_TOutput((TOutput *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_object_actor_cpp(void)

{
  undefined1 *local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined1 *local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined1 *local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 *local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_cc = &TVariableValueOutput_object_<TAdaptor_actor,JStage::TActor>::__vt;
  local_c8 = 1;
  local_c4 = _1008;
  local_c0 = DAT_80397a78;
  local_bc = DAT_80397a7c;
  local_b8 = _1009;
  local_b4 = DAT_80397a84;
  local_b0 = DAT_80397a88;
  _saoVVOutput_ = &TVariableValueOutput_object_<TAdaptor_actor,JStage::TActor>::__vt
  ;
  DAT_803e88c4 = 1;
  DAT_803e88c8 = _1008;
  DAT_803e88cc = DAT_80397a78;
  DAT_803e88d0 = DAT_80397a7c;
  DAT_803e88d4 = _1009;
  DAT_803e88d8 = DAT_80397a84;
  DAT_803e88dc = DAT_80397a88;
  Runtime.PPCEABI.H::__register_global_object
            (&TAdaptor_actor::saoVVOutput_,
             TVariableValueOutput_object_<TAdaptor_actor,JStage::TActor>::
             _TVariableValueOutput_object_,&_1012);
  local_cc = &TVariableValueOutput_object_<TAdaptor_actor,JStage::TActor>::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_cc);
  local_ec = &TVariableValueOutput_object_<TAdaptor_actor,JStage::TActor>::__vt;
  local_e8 = 0xffffffff;
  local_e4 = Runtime.PPCEABI.H::__ptmf_null;
  local_e0 = DAT_80370fbc;
  local_dc = DAT_80370fc0;
  local_d8 = Runtime.PPCEABI.H::__ptmf_null;
  local_d4 = DAT_80370fbc;
  local_d0 = DAT_80370fc0;
  DAT_803e88e0 = &TVariableValueOutput_object_<TAdaptor_actor,JStage::TActor>::__vt;
  DAT_803e88e4 = 0xffffffff;
  DAT_803e88e8 = Runtime.PPCEABI.H::__ptmf_null;
  DAT_803e88ec = DAT_80370fbc;
  DAT_803e88f0 = DAT_80370fc0;
  DAT_803e88f4 = Runtime.PPCEABI.H::__ptmf_null;
  DAT_803e88f8 = DAT_80370fbc;
  DAT_803e88fc = DAT_80370fc0;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e88e0,
             TVariableValueOutput_object_<TAdaptor_actor,JStage::TActor>::
             _TVariableValueOutput_object_,&_1013);
  local_ec = &TVariableValueOutput_object_<TAdaptor_actor,JStage::TActor>::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_ec);
  local_4c = &TAdaptor_actor::TVVOutput_ANIMATION_FRAME_::__vt;
  local_48 = 0;
  local_44 = 0x13d;
  local_40 = _1014;
  local_3c = DAT_80397a90;
  local_38 = DAT_80397a94;
  local_34 = _1015;
  local_30 = DAT_80397a9c;
  local_2c = DAT_80397aa0;
  local_28 = _1016;
  local_24 = DAT_80397aa8;
  local_20 = DAT_80397aac;
  _saoVVOutput_ANIMATION_FRAME_ = &TAdaptor_actor::TVVOutput_ANIMATION_FRAME_::__vt;
  DAT_803e8928 = 0;
  DAT_803e892c = 0x13d;
  DAT_803e8930 = _1014;
  DAT_803e8934 = DAT_80397a90;
  DAT_803e8938 = DAT_80397a94;
  DAT_803e893c = _1015;
  DAT_803e8940 = DAT_80397a9c;
  DAT_803e8944 = DAT_80397aa0;
  DAT_803e8948 = _1016;
  DAT_803e894c = DAT_80397aa8;
  DAT_803e8950 = DAT_80397aac;
  Runtime.PPCEABI.H::__register_global_object
            (&TAdaptor_actor::saoVVOutput_ANIMATION_FRAME_,
             TAdaptor_actor::TVVOutput_ANIMATION_FRAME_::_TVVOutput_ANIMATION_FRAME_,&_1020);
  local_4c = &TAdaptor_actor::TVVOutput_ANIMATION_FRAME_::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_4c);
  local_7c = &TAdaptor_actor::TVVOutput_ANIMATION_FRAME_::__vt;
  local_78 = 2;
  local_74 = 0x141;
  local_70 = _1021;
  local_6c = DAT_80397ab4;
  local_68 = DAT_80397ab8;
  local_64 = _1022;
  local_60 = DAT_80397ac0;
  local_5c = DAT_80397ac4;
  local_58 = _1023;
  local_54 = DAT_80397acc;
  local_50 = DAT_80397ad0;
  DAT_803e8954 = &TAdaptor_actor::TVVOutput_ANIMATION_FRAME_::__vt;
  DAT_803e8958 = 2;
  DAT_803e895c = 0x141;
  DAT_803e8960 = _1021;
  DAT_803e8964 = DAT_80397ab4;
  DAT_803e8968 = DAT_80397ab8;
  DAT_803e896c = _1022;
  DAT_803e8970 = DAT_80397ac0;
  DAT_803e8974 = DAT_80397ac4;
  DAT_803e8978 = _1023;
  DAT_803e897c = DAT_80397acc;
  DAT_803e8980 = DAT_80397ad0;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8954,TAdaptor_actor::TVVOutput_ANIMATION_FRAME_::_TVVOutput_ANIMATION_FRAME_,
             &_1027);
  local_7c = &TAdaptor_actor::TVVOutput_ANIMATION_FRAME_::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_7c);
  local_ac = &TAdaptor_actor::TVVOutput_ANIMATION_FRAME_::__vt;
  local_a8 = 0xffffffff;
  local_a4 = 0;
  local_a0 = Runtime.PPCEABI.H::__ptmf_null;
  local_9c = DAT_80370fbc;
  local_98 = DAT_80370fc0;
  local_94 = Runtime.PPCEABI.H::__ptmf_null;
  local_90 = DAT_80370fbc;
  local_8c = DAT_80370fc0;
  local_88 = Runtime.PPCEABI.H::__ptmf_null;
  local_84 = DAT_80370fbc;
  local_80 = DAT_80370fc0;
  DAT_803e8984 = &TAdaptor_actor::TVVOutput_ANIMATION_FRAME_::__vt;
  DAT_803e8988 = 0xffffffff;
  DAT_803e898c = 0;
  DAT_803e8990 = Runtime.PPCEABI.H::__ptmf_null;
  DAT_803e8994 = DAT_80370fbc;
  DAT_803e8998 = DAT_80370fc0;
  DAT_803e899c = Runtime.PPCEABI.H::__ptmf_null;
  DAT_803e89a0 = DAT_80370fbc;
  DAT_803e89a4 = DAT_80370fc0;
  DAT_803e89a8 = Runtime.PPCEABI.H::__ptmf_null;
  DAT_803e89ac = DAT_80370fbc;
  DAT_803e89b0 = DAT_80370fc0;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8984,TAdaptor_actor::TVVOutput_ANIMATION_FRAME_::_TVVOutput_ANIMATION_FRAME_,
             &_1028);
  local_ac = &TAdaptor_actor::TVVOutput_ANIMATION_FRAME_::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_ac);
  return;
}

}

namespace JStudio {

/* __thiscall TVariableValue::TVariableValue(void) */

void __thiscall TVariableValue::TVariableValue(TVariableValue *this)

{
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined1 **)(this + 0x10) = &soOutput_none_;
  return;
}

}

namespace JStudio_JStage {

/* __thiscall
   TVariableValueOutput_object_<TAdaptor_actor,JStage::TActor>::~TVariableValueOutput_object_(void)
    */

TVariableValueOutput_object__JStudio_JStage__TAdaptor_actor_JStage__TActor_ * __thiscall
TVariableValueOutput_object_<TAdaptor_actor,JStage::TActor>::
_TVariableValueOutput_object_
          (TVariableValueOutput_object__JStudio_JStage__TAdaptor_actor_JStage__TActor_ *this)

{
  short in_r4;
  
  if (this != (TVariableValueOutput_object__JStudio_JStage__TAdaptor_actor_JStage__TActor_ *)0x0) {
    *(undefined1 **)this = &__vt;
    JStudio::TVariableValue::TOutput::_TOutput((TOutput *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return this;
}


/* __thiscall
   TVariableValueOutput_object_<TAdaptor_actor,JStage::TActor>::operator
   ()(float,
   
   JStudio::TAdaptor *) const */

void __thiscall
TVariableValueOutput_object_<TAdaptor_actor,JStage::TActor>::
operator___(TVariableValueOutput_object__JStudio_JStage__TAdaptor_actor_JStage__TActor_ *this,
           float param_1,TAdaptor *param_2)

{
  Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 8),*(void **)(param_2 + 0x128),param_2);
  return;
}

