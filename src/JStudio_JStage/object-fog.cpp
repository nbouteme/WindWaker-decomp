#include <JStudio_JStage/object-fog.h>
#include <JStudio_JStage/object-actor.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JStudio/jstudio-object.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <JStudio_JStage/object.h>
#include <JStudio_JStage/object-fog.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JStudio_JStage/TVariableValueOutput_object_<JStudio_JStage::TAdaptor_fog,JStage::TFog>.h>
#include <Demangler/JStudio_JStage/TAdaptor_fog.h>


namespace JStudio_JStage {

namespace TAdaptor_fog {
undefined1 saoVVOutput_;
}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TAdaptor_fog::TAdaptor_fog(JStage::TSystem const *,
                                                         JStage::TFog *) */

void __thiscall
TAdaptor_fog::TAdaptor_fog(TAdaptor_fog *this,TSystem *param_1,TFog *param_2)

{
  *(undefined1 **)this = &JStudio::TAdaptor::__vt;
  *(TAdaptor_fog **)(this + 4) = this + 0xc;
  *(undefined4 *)(this + 8) = 6;
  *(undefined1 **)this = &JStudio::TAdaptor_fog::__vt;
  Runtime.PPCEABI.H::__construct_array
            (this + 0xc,JStudio::TVariableValue::TVariableValue,(undefined *)0x0,0x14,6);
  *(undefined1 **)this = &__vt;
  *(TSystem **)(this + 0x84) = param_1;
  *(TFog **)(this + 0x88) = param_2;
  return;
}


/* __thiscall TAdaptor_fog::~TAdaptor_fog(void) */

void __thiscall TAdaptor_fog::_TAdaptor_fog(TAdaptor_fog *this)

{
  short in_r4;
  
  if (this != (TAdaptor_fog *)0x0) {
    *(undefined1 **)this = &__vt;
    (**(code **)(*(int *)this + 0x14))(this,0);
    JStudio::TAdaptor_fog::_TAdaptor_fog((TAdaptor_fog *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TAdaptor_fog::adaptor_do_prepare(JStudio::TObject const *) */

void __thiscall
TAdaptor_fog::adaptor_do_prepare(TAdaptor_fog *this,TObject *param_1)

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
/* __thiscall TAdaptor_fog::adaptor_do_begin(JStudio::TObject const *) */

void __thiscall TAdaptor_fog::adaptor_do_begin(TAdaptor_fog *this,TObject *param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  void *extraout_r4;
  void *pvVar4;
  int *piVar5;
  double dVar6;
  _GXColor local_18 [2];
  
  piVar5 = *(int **)(this + 0x88);
  uVar2 = (**(code **)(*piVar5 + 0x14))(piVar5);
  (**(code **)(*piVar5 + 0x18))(piVar5,uVar2 | 1);
  local_18[0] = (_GXColor)(**(code **)(**(int **)(this + 0x88) + 0x50))();
  dVar6 = (double)JStudio::TAdaptor::adaptor_setVariableValue_GXColor
                            ((TAdaptor *)this,
                             (ulong *)&JStudio::TAdaptor_fog::sauVariableValue_4_COLOR_RGBA,local_18
                            );
  pvVar4 = extraout_r4;
  for (puVar1 = &saoVVOutput_; *(int *)(puVar1 + 4) != -1; puVar1 = puVar1 + 0x20) {
    Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(puVar1 + 0x14),*(void **)(this + 0x88),pvVar4);
    iVar3 = *(int *)(this + 4) + *(int *)(puVar1 + 4) * 0x14;
    *(code **)(iVar3 + 8) = JStudio::TVariableValue::update_immediate_;
    *(undefined4 *)(iVar3 + 4) = 0;
    *(float *)(iVar3 + 0xc) = (float)dVar6;
  }
  return;
}


/* __thiscall TAdaptor_fog::adaptor_do_end(JStudio::TObject const *) */

void __thiscall TAdaptor_fog::adaptor_do_end(TAdaptor_fog *this,TObject *param_1)

{
  uint uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(this + 0x88);
  uVar1 = (**(code **)(*piVar2 + 0x14))(piVar2);
  (**(code **)(*piVar2 + 0x18))(piVar2,uVar1 & 0xfffffffe);
  return;
}


/* __thiscall TAdaptor_fog::adaptor_do_update(JStudio::TObject const *,
                                                              unsigned long) */

void __thiscall
TAdaptor_fog::adaptor_do_update(TAdaptor_fog *this,TObject *param_1,ulong param_2)

{
  _GXColor local_18;
  _GXColor local_14 [4];
  
  JStudio::TAdaptor::adaptor_getVariableValue_GXColor
            ((TAdaptor *)this,local_14,
             (ulong *)&JStudio::TAdaptor_fog::sauVariableValue_4_COLOR_RGBA);
  local_18 = local_14[0];
  (**(code **)(**(int **)(this + 0x88) + 0x54))(*(int **)(this + 0x88),&local_18);
  return;
}


/* __thiscall TAdaptor_fog::adaptor_do_data(JStudio::TObject const *,
                                                            void const *,
                                                            unsigned long,
                                                            void const *,
                                                            unsigned long) */

void __thiscall
TAdaptor_fog::adaptor_do_data
          (TAdaptor_fog *this,TObject *param_1,void *param_2,ulong param_3,void *param_4,
          ulong param_5)

{
  TAdaptor_object_::adaptor_data_
            (*(TAdaptor_object_ **)(this + 0x88),(TObject *)param_2,(void *)param_3,(ulong)param_4,
             (void *)param_5,param_5);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_object_fog_cpp(void)

{
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
  
  local_28 = &TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::__vt;
  local_24 = 4;
  local_20 = _817;
  local_1c = DAT_80397c9c;
  local_18 = DAT_80397ca0;
  local_14 = _818;
  local_10 = DAT_80397ca8;
  local_c = DAT_80397cac;
  _saoVVOutput_ = &TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::__vt;
  DAT_803e8ac0 = 4;
  DAT_803e8ac4 = _817;
  DAT_803e8ac8 = DAT_80397c9c;
  DAT_803e8acc = DAT_80397ca0;
  DAT_803e8ad0 = _818;
  DAT_803e8ad4 = DAT_80397ca8;
  DAT_803e8ad8 = DAT_80397cac;
  Runtime.PPCEABI.H::__register_global_object
            (&TAdaptor_fog::saoVVOutput_,
             TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::
             _TVariableValueOutput_object_,&_821);
  local_28 = &TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_28);
  local_48 = &TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::__vt;
  local_44 = 5;
  local_40 = _822;
  local_3c = DAT_80397cb4;
  local_38 = DAT_80397cb8;
  local_34 = _823;
  local_30 = DAT_80397cc0;
  local_2c = DAT_80397cc4;
  DAT_803e8adc = &TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::__vt;
  DAT_803e8ae0 = 5;
  DAT_803e8ae4 = _822;
  DAT_803e8ae8 = DAT_80397cb4;
  DAT_803e8aec = DAT_80397cb8;
  DAT_803e8af0 = _823;
  DAT_803e8af4 = DAT_80397cc0;
  DAT_803e8af8 = DAT_80397cc4;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8adc,
             TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::
             _TVariableValueOutput_object_,&_826);
  local_48 = &TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_48);
  local_68 = &TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::__vt;
  local_64 = 0xffffffff;
  local_60 = Runtime.PPCEABI.H::__ptmf_null;
  local_5c = DAT_80370fbc;
  local_58 = DAT_80370fc0;
  local_54 = Runtime.PPCEABI.H::__ptmf_null;
  local_50 = DAT_80370fbc;
  local_4c = DAT_80370fc0;
  DAT_803e8afc = &TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::__vt;
  DAT_803e8b00 = 0xffffffff;
  DAT_803e8b04 = Runtime.PPCEABI.H::__ptmf_null;
  DAT_803e8b08 = DAT_80370fbc;
  DAT_803e8b0c = DAT_80370fc0;
  DAT_803e8b10 = Runtime.PPCEABI.H::__ptmf_null;
  DAT_803e8b14 = DAT_80370fbc;
  DAT_803e8b18 = DAT_80370fc0;
  Runtime.PPCEABI.H::__register_global_object
            (&DAT_803e8afc,
             TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::
             _TVariableValueOutput_object_,&_827);
  local_68 = &TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::__vt;
  JStudio::TVariableValue::TOutput::_TOutput((TOutput *)&local_68);
  return;
}


/* __thiscall
   TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::~TVariableValueOutput_object_(void)
    */

TVariableValueOutput_object__JStudio_JStage__TAdaptor_fog_JStage__TFog_ * __thiscall
TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::
_TVariableValueOutput_object_
          (TVariableValueOutput_object__JStudio_JStage__TAdaptor_fog_JStage__TFog_ *this)

{
  short in_r4;
  
  if (this != (TVariableValueOutput_object__JStudio_JStage__TAdaptor_fog_JStage__TFog_ *)0x0) {
    *(undefined1 **)this = &__vt;
    JStudio::TVariableValue::TOutput::_TOutput((TOutput *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return this;
}


/* __thiscall
   TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::operator
   ()(float,
   
   JStudio::TAdaptor *) const */

void __thiscall
TVariableValueOutput_object_<TAdaptor_fog,JStage::TFog>::operator___
          (TVariableValueOutput_object__JStudio_JStage__TAdaptor_fog_JStage__TFog_ *this,
          float param_1,TAdaptor *param_2)

{
  Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 8),*(void **)(param_2 + 0x88),param_2);
  return;
}

