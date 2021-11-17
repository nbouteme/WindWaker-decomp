#include <JStudio_JStage/object-ambientlight.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JStudio_JStage/object-actor.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JStudio/jstudio-object.h>
#include <JKernel/JKRHeap.h>
#include <JStudio_JStage/object.h>
#include <Demangler/JStudio_JStage/TAdaptor_ambientLight.h>


namespace JStudio_JStage {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TAdaptor_ambientLight::TAdaptor_ambientLight(JStage::TSystem const *,
                                                                           JStage::TAmbientLight *)
    */

void __thiscall
TAdaptor_ambientLight::TAdaptor_ambientLight
          (TAdaptor_ambientLight *this,TSystem *param_1,TAmbientLight *param_2)

{
  *(undefined1 **)this = &JStudio::TAdaptor::__vt;
  *(TAdaptor_ambientLight **)(this + 4) = this + 0xc;
  *(undefined4 *)(this + 8) = 4;
  *(undefined1 **)this = &JStudio::TAdaptor_ambientLight::__vt;
  Runtime.PPCEABI.H::__construct_array
            (this + 0xc,JStudio::TVariableValue::TVariableValue,(undefined *)0x0,0x14,4);
  *(undefined1 **)this = &__vt;
  *(TSystem **)(this + 0x5c) = param_1;
  *(TAmbientLight **)(this + 0x60) = param_2;
  return;
}


/* __thiscall TAdaptor_ambientLight::~TAdaptor_ambientLight(void) */

void __thiscall
TAdaptor_ambientLight::_TAdaptor_ambientLight(TAdaptor_ambientLight *this)

{
  short in_r4;
  
  if (this != (TAdaptor_ambientLight *)0x0) {
    *(undefined1 **)this = &__vt;
    (**(code **)(*(int *)this + 0x14))(this,0);
    JStudio::TAdaptor_ambientLight::_TAdaptor_ambientLight((TAdaptor_ambientLight *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TAdaptor_ambientLight::adaptor_do_prepare(JStudio::TObject const *) */

void __thiscall
TAdaptor_ambientLight::adaptor_do_prepare
          (TAdaptor_ambientLight *this,TObject *param_1)

{
  return;
}


/* __thiscall TAdaptor_ambientLight::adaptor_do_begin(JStudio::TObject const *) */

void __thiscall
TAdaptor_ambientLight::adaptor_do_begin
          (TAdaptor_ambientLight *this,TObject *param_1)

{
  uint uVar1;
  int *piVar2;
  _GXColor local_18 [4];
  
  piVar2 = *(int **)(this + 0x60);
  uVar1 = (**(code **)(*piVar2 + 0x14))(piVar2);
  (**(code **)(*piVar2 + 0x18))(piVar2,uVar1 | 1);
  local_18[0] = (_GXColor)(**(code **)(**(int **)(this + 0x60) + 0x38))();
  JStudio::TAdaptor::adaptor_setVariableValue_GXColor
            ((TAdaptor *)this,
             (ulong *)&JStudio::TAdaptor_ambientLight::sauVariableValue_4_COLOR_RGBA,local_18);
  return;
}


/* __thiscall TAdaptor_ambientLight::adaptor_do_end(JStudio::TObject const *) */

void __thiscall
TAdaptor_ambientLight::adaptor_do_end(TAdaptor_ambientLight *this,TObject *param_1)

{
  uint uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(this + 0x60);
  uVar1 = (**(code **)(*piVar2 + 0x14))(piVar2);
  (**(code **)(*piVar2 + 0x18))(piVar2,uVar1 & 0xfffffffe);
  return;
}


/* __thiscall TAdaptor_ambientLight::adaptor_do_update(JStudio::TObject const *,
                                                                       unsigned long) */

void __thiscall
TAdaptor_ambientLight::adaptor_do_update
          (TAdaptor_ambientLight *this,TObject *param_1,ulong param_2)

{
  _GXColor local_18;
  _GXColor local_14 [4];
  
  JStudio::TAdaptor::adaptor_getVariableValue_GXColor
            ((TAdaptor *)this,local_14,
             (ulong *)&JStudio::TAdaptor_ambientLight::sauVariableValue_4_COLOR_RGBA);
  local_18 = local_14[0];
  (**(code **)(**(int **)(this + 0x60) + 0x3c))(*(int **)(this + 0x60),&local_18);
  return;
}


/* __thiscall TAdaptor_ambientLight::adaptor_do_data(JStudio::TObject const *,
                                                                     void const *,
                                                                     unsigned long,
                                                                     void const *,
                                                                     unsigned long) */

void __thiscall
TAdaptor_ambientLight::adaptor_do_data
          (TAdaptor_ambientLight *this,TObject *param_1,void *param_2,ulong param_3,void *param_4,
          ulong param_5)

{
  TAdaptor_object_::adaptor_data_
            (*(TAdaptor_object_ **)(this + 0x60),(TObject *)param_2,(void *)param_3,(ulong)param_4,
             (void *)param_5,param_5);
  return;
}

