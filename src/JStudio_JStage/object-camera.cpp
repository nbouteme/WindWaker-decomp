#include <JStudio_JStage/object-camera.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JStudio_JStage/object-actor.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JStudio/jstudio-object.h>
#include <JKernel/JKRHeap.h>
#include <mtx/mtxvec.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <JStudio_JStage/object.h>
#include <JStudio_JStage/object-camera.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JStudio_JStage/TVariableValueOutput_object_<JStudio_JStage::TAdaptor_camera,JStage::TCamera>.h>
#include <Demangler/JStudio_JStage/TAdaptor_camera.h>


namespace JStudio_JStage {

namespace TAdaptor_camera {
undefined1 saoVVOutput_;
}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TAdaptor_camera::TAdaptor_camera(JStage::TSystem const *,
                                                               JStage::TCamera *) */

void __thiscall
TAdaptor_camera::TAdaptor_camera
          (TAdaptor_camera *this,TSystem *param_1,TCamera *param_2)

{
  *(undefined1 **)this = &JStudio::TAdaptor::__vt;
  *(TAdaptor_camera **)(this + 4) = this + 0xc;
  *(undefined4 *)(this + 8) = 0xb;
  *(undefined1 **)this = &JStudio::TAdaptor_camera::__vt;
  Runtime.PPCEABI.H::__construct_array
            (this + 0xc,JStudio::TVariableValue::TVariableValue,(undefined *)0x0,0x14,0xb);
  *(undefined1 **)this = &__vt;
  *(TSystem **)(this + 0xe8) = param_1;
  *(TCamera **)(this + 0xec) = param_2;
  return;
}


/* __thiscall TAdaptor_camera::~TAdaptor_camera(void) */

void __thiscall TAdaptor_camera::_TAdaptor_camera(TAdaptor_camera *this)

{
  short in_r4;
  
  if (this != (TAdaptor_camera *)0x0) {
    *(undefined1 **)this = &__vt;
    (**(code **)(*(int *)this + 0x14))(this,0);
    JStudio::TAdaptor_camera::_TAdaptor_camera((TAdaptor_camera *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TAdaptor_camera::adaptor_do_prepare(JStudio::TObject const *) */

void __thiscall
TAdaptor_camera::adaptor_do_prepare(TAdaptor_camera *this,TObject *param_1)

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
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TAdaptor_camera::adaptor_do_begin(JStudio::TObject const *) */

void __thiscall
TAdaptor_camera::adaptor_do_begin(TAdaptor_camera *this,TObject *param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  void *extraout_r4;
  void *pvVar4;
  int *piVar5;
  cXyz *pcVar6;
  undefined *puVar7;
  MTX34 *pMtx;
  double dVar8;
  cXyz cStack72;
  cXyz cStack60;
  cXyz cStack48;
  cXyz cStack36;
  
  piVar5 = *(int **)(this + 0xec);
  uVar2 = (**(code **)(*piVar5 + 0x14))(piVar5);
  (**(code **)(*piVar5 + 0x18))(piVar5,uVar2 | 1);
  puVar7 = param_1[5].vtbl;
  (**(code **)(**(int **)(this + 0xec) + 0x70))(*(int **)(this + 0xec),&cStack48);
  (**(code **)(**(int **)(this + 0xec) + 0x80))(*(int **)(this + 0xec),&cStack36);
  if (puVar7[0x75] == '\0') {
    pcVar6 = &cStack48;
  }
  else {
    pMtx = (MTX34 *)(puVar7 + 200);
    mtx::PSMTXMultVec(pMtx,&cStack48,&cStack72);
    mtx::PSMTXMultVec(pMtx,&cStack36,&cStack60);
    pcVar6 = &cStack72;
  }
  JStudio::TAdaptor::adaptor_setVariableValue_Vec
            ((TAdaptor *)this,(ulong *)&JStudio::TAdaptor_camera::sauVariableValue_3_POSITION_XYZ,
             (Vec *)pcVar6);
  dVar8 = (double)JStudio::TAdaptor::adaptor_setVariableValue_Vec
                            ((TAdaptor *)this,
                             (ulong *)&JStudio::TAdaptor_camera::
                                       sauVariableValue_3_TARGET_POSITION_XYZ,(Vec *)(pcVar6 + 1));
  pvVar4 = extraout_r4;
  for (puVar1 = &saoVVOutput_; *(int *)(puVar1 + 4) != -1; puVar1 = puVar1 + 0x20) {
    Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(puVar1 + 0x14),*(void **)(this + 0xec),pvVar4);
    iVar3 = *(int *)(this + 4) + *(int *)(puVar1 + 4) * 0x14;
    *(code **)(iVar3 + 8) = JStudio::TVariableValue::update_immediate_;
    *(undefined4 *)(iVar3 + 4) = 0;
    *(float *)(iVar3 + 0xc) = (float)dVar8;
  }
  return;
}


/* __thiscall TAdaptor_camera::adaptor_do_end(JStudio::TObject const *) */

void __thiscall
TAdaptor_camera::adaptor_do_end(TAdaptor_camera *this,TObject *param_1)

{
  uint uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(this + 0xec);
  uVar1 = (**(code **)(*piVar2 + 0x14))(piVar2);
  (**(code **)(*piVar2 + 0x18))(piVar2,uVar1 & 0xfffffffe);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TAdaptor_camera::adaptor_do_update(JStudio::TObject const *,
                                                                 unsigned long) */

void __thiscall
TAdaptor_camera::adaptor_do_update
          (TAdaptor_camera *this,TObject *param_1,ulong param_2)

{
  undefined *puVar1;
  MTX34 *pMtx;
  cXyz *pcVar2;
  cXyz cStack72;
  cXyz cStack60;
  cXyz cStack48;
  cXyz acStack36 [2];
  
  puVar1 = param_1[5].vtbl;
  JStudio::TAdaptor::adaptor_getVariableValue_Vec
            ((TAdaptor *)this,(Vec *)&cStack48,
             (ulong *)&JStudio::TAdaptor_camera::sauVariableValue_3_POSITION_XYZ);
  JStudio::TAdaptor::adaptor_getVariableValue_Vec
            ((TAdaptor *)this,(Vec *)acStack36,
             (ulong *)&JStudio::TAdaptor_camera::sauVariableValue_3_TARGET_POSITION_XYZ);
  if (puVar1[0x74] == '\0') {
    pcVar2 = &cStack48;
  }
  else {
    pMtx = (MTX34 *)(puVar1 + 0x98);
    mtx::PSMTXMultVec(pMtx,&cStack48,&cStack72);
    mtx::PSMTXMultVec(pMtx,acStack36,&cStack60);
    pcVar2 = &cStack72;
  }
  (**(code **)(**(int **)(this + 0xec) + 0x74))(*(int **)(this + 0xec),pcVar2);
  (**(code **)(**(int **)(this + 0xec) + 0x84))(*(int **)(this + 0xec),pcVar2 + 1);
  return;
}


/* __thiscall TAdaptor_camera::adaptor_do_data(JStudio::TObject const *,
                                                               void const *,
                                                               unsigned long,
                                                               void const *,
                                                               unsigned long) */

void __thiscall
TAdaptor_camera::adaptor_do_data
          (TAdaptor_camera *this,TObject *param_1,void *param_2,ulong param_3,void *param_4,
          ulong param_5)

{
  TAdaptor_object_::adaptor_data_
            (*(TAdaptor_object_ **)(this + 0xec),(TObject *)param_2,(void *)param_3,(ulong)param_4,
             (void *)param_5,param_5);
  return;
}


/* __thiscall TAdaptor_camera::adaptor_do_PARENT(JStudio::data::TEOperationData,
                                                                 void const *,
                                                                 unsigned long) */

void __thiscall
TAdaptor_camera::adaptor_do_PARENT
          (TAdaptor_camera *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0x18) {
    uVar1 = (**(code **)(**(int **)(this + 0xe8) + 0x38))(*(int **)(this + 0xe8),param_2,0);
    *(undefined4 *)(this + 0xf0) = uVar1;
  }
  return;
}


/* __thiscall
   TAdaptor_camera::adaptor_do_PARENT_NODE(JStudio::data::TEOperationData,
                                                                      void const *,
                                                                      unsigned long) */

void __thiscall
TAdaptor_camera::adaptor_do_PARENT_NODE
          (TAdaptor_camera *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (param_1 == 0x19) {
                    /* WARNING: Load size is inaccurate */
    *(undefined4 *)(this + 0xf4) = *param_2;
  }
  else {
    if ((((int)param_1 < 0x19) && (0x17 < (int)param_1)) &&
       (piVar1 = *(int **)(this + 0xf0), piVar1 != (int *)0x0)) {
      uVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,param_2);
      *(undefined4 *)(this + 0xf4) = uVar2;
    }
  }
  return;
}


/* __thiscall
   TAdaptor_camera::adaptor_do_PARENT_ENABLE(JStudio::data::TEOperationData,
                                                                        void const *,
                                                                        unsigned long) */

void __thiscall
TAdaptor_camera::adaptor_do_PARENT_ENABLE
          (TAdaptor_camera *this,TEOperationData param_1,void *param_2,ulong param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == 2) {
    uVar1 = 0;
    uVar2 = 0xffffffff;
                    /* WARNING: Load size is inaccurate */
    if (*param_2 != 0) {
      uVar1 = *(undefined4 *)(this + 0xf0);
      uVar2 = *(undefined4 *)(this + 0xf4);
    }
    (**(code **)(**(int **)(this + 0xec) + 0x28))(*(int **)(this + 0xec),uVar1,uVar2);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_object_camera_cpp(void)

{
  undefined1 *local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 *local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 *local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined1 *local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_28 = &TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::__vt;
  local_24 = 7;
  local_20 = _886;
  local_1c = DAT_80397bc4;
  local_18 = DAT_80397bc8;
  local_14 = _887;
  local_10 = DAT_80397bd0;
  local_c = DAT_80397bd4;
  _saoVVOutput_ =
       &TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::__vt;
  DAT_803e89f8 = 7;
  DAT_803e89fc = _886;
  DAT_803e8a00 = DAT_80397bc4;
  DAT_803e8a04 = DAT_80397bc8;
  DAT_803e8a08 = _887;
  DAT_803e8a0c = DAT_80397bd0;
  DAT_803e8a10 = DAT_80397bd4;
  Runtime.PPCEABI.H::__register_global_object
            (&TAdaptor_camera::saoVVOutput_,
             TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::
             _TVariableValueOutput_object_,&_890);
  local_28 = &TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_28);
  local_48 = &TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::__vt;
  local_44 = 6;
  local_40 = _891;
  local_3c = DAT_80397bdc;
  local_38 = DAT_80397be0;
  local_34 = _892;
  local_30 = DAT_80397be8;
  local_2c = DAT_80397bec;
  DAT_803e8a14 = &TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::
                  __vt;
  DAT_803e8a18 = 6;
  DAT_803e8a1c = _891;
  DAT_803e8a20 = DAT_80397bdc;
  DAT_803e8a24 = DAT_80397be0;
  DAT_803e8a28 = _892;
  DAT_803e8a2c = DAT_80397be8;
  DAT_803e8a30 = DAT_80397bec;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8a14,
             TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::
             _TVariableValueOutput_object_,&_895);
  local_48 = &TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_48);
  local_68 = &TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::__vt;
  local_64 = 8;
  local_60 = _896;
  local_5c = DAT_80397bf4;
  local_58 = DAT_80397bf8;
  local_54 = _897;
  local_50 = DAT_80397c00;
  local_4c = DAT_80397c04;
  DAT_803e8a34 = &TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::
                  __vt;
  DAT_803e8a38 = 8;
  DAT_803e8a3c = _896;
  DAT_803e8a40 = DAT_80397bf4;
  DAT_803e8a44 = DAT_80397bf8;
  DAT_803e8a48 = _897;
  DAT_803e8a4c = DAT_80397c00;
  DAT_803e8a50 = DAT_80397c04;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8a34,
             TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::
             _TVariableValueOutput_object_,&_900);
  local_68 = &TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_68);
  local_88 = &TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::__vt;
  local_84 = 9;
  local_80 = _901;
  local_7c = DAT_80397c0c;
  local_78 = DAT_80397c10;
  local_74 = _902;
  local_70 = DAT_80397c18;
  local_6c = DAT_80397c1c;
  DAT_803e8a54 = &TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::
                  __vt;
  DAT_803e8a58 = 9;
  DAT_803e8a5c = _901;
  DAT_803e8a60 = DAT_80397c0c;
  DAT_803e8a64 = DAT_80397c10;
  DAT_803e8a68 = _902;
  DAT_803e8a6c = DAT_80397c18;
  DAT_803e8a70 = DAT_80397c1c;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8a54,
             TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::
             _TVariableValueOutput_object_,&_905);
  local_88 = &TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_88);
  local_a8 = &TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::__vt;
  local_a4 = 0xffffffff;
  local_a0 = Runtime.PPCEABI.H::__ptmf_null;
  local_9c = DAT_80370fbc;
  local_98 = DAT_80370fc0;
  local_94 = Runtime.PPCEABI.H::__ptmf_null;
  local_90 = DAT_80370fbc;
  local_8c = DAT_80370fc0;
  DAT_803e8a74 = &TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::
                  __vt;
  DAT_803e8a78 = 0xffffffff;
  DAT_803e8a7c = Runtime.PPCEABI.H::__ptmf_null;
  DAT_803e8a80 = DAT_80370fbc;
  DAT_803e8a84 = DAT_80370fc0;
  DAT_803e8a88 = Runtime.PPCEABI.H::__ptmf_null;
  DAT_803e8a8c = DAT_80370fbc;
  DAT_803e8a90 = DAT_80370fc0;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8a74,
             TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::
             _TVariableValueOutput_object_,&_906);
  local_a8 = &TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_a8);
  return;
}


/* __thiscall
   TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::~TVariableValueOutput_object_(void)
    */

TVariableValueOutput_object__JStudio_JStage__TAdaptor_camera_JStage__TCamera_ * __thiscall
TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::
_TVariableValueOutput_object_
          (TVariableValueOutput_object__JStudio_JStage__TAdaptor_camera_JStage__TCamera_ *this)

{
  short in_r4;
  
  if (this != (TVariableValueOutput_object__JStudio_JStage__TAdaptor_camera_JStage__TCamera_ *)0x0)
  {
    *(undefined1 **)this = &__vt;
    JStudio::TVariableValue::TOutput::_TOutput((TOutput *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return this;
}


/* __thiscall
   TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::operator
   ()(float,
   
   JStudio::TAdaptor *) const */

void __thiscall
TVariableValueOutput_object_<TAdaptor_camera,JStage::TCamera>::
operator___(TVariableValueOutput_object__JStudio_JStage__TAdaptor_camera_JStage__TCamera_ *this,
           float param_1,TAdaptor *param_2)

{
  Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 8),*(void **)(param_2 + 0xec),param_2);
  return;
}

