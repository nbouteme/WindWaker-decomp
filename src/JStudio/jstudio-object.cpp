#include <JStudio/jstudio-object.h>
#include <JKernel/JKRHeap.h>
#include <JStudio/jstudio-object.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JStudio/fvb.h>
#include <JStudio/stb.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JStudio/TObject_ambientLight.h>
#include <Demangler/JStudio/TAdaptor.h>
#include <JStudio/TObject_message.h>
#include <JStudio/TAdaptor_message.h>
#include <JStudio/TObject_camera.h>
#include <JStudio/@unnamed@jstudio_object_cpp@/TOutputVariableValue_BOOL_<JStudio::TAdaptor_camera>.h>
#include <JStudio/@unnamed@jstudio_object_cpp@/TOutputVariableValue_BOOL_<JStudio::TAdaptor_light>.h>
#include <JStudio/TObject_particle.h>
#include <Demangler/JStudio/TObject.h>
#include <JStudio/TAdaptor_fog.h>
#include <JStudio/TObject_sound.h>
#include <JStudio/@unnamed@jstudio_object_cpp@/TOutputVariableValue_BOOL_<JStudio::TAdaptor_particle>.h>
#include <JStudio/TAdaptor_ambientLight.h>
#include <JStudio/TVariableValue/TOutput_none_.h>
#include <JStudio/@unnamed@jstudio_object_cpp@/TOutputVariableValue_BOOL_<JStudio::TAdaptor_sound>.h>
#include <JStudio/TAdaptor_actor.h>
#include <JStudio/TAdaptor_particle.h>
#include <JStudio/@unnamed@jstudio_object_cpp@/TOutputVariableValue_BOOL_<JStudio::TAdaptor_actor>.h>
#include <JStudio/TAdaptor_camera.h>
#include <JStudio/TAdaptor_light.h>
#include <JStudio/TVariableValue.h>
#include <JStudio/TObject_fog.h>
#include <JStudio/TVariableValue/TOutput.h>
#include <JStudio/TAdaptor_sound.h>
#include <JStudio/TObject_actor.h>
#include <JStudio/TObject_light.h>


namespace JStudio {
undefined1 TVariableValue;

namespace TVariableValue {

/* __thiscall TOutput::~TOutput(void) */

void __thiscall TOutput::_TOutput(TOutput *this)

{
  short in_r4;
  
  if ((this != (TOutput *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

}

/* __thiscall TVariableValue::update(double,
                                              TAdaptor *) */

double __thiscall
TVariableValue::update(TVariableValue *this,double param_1,TAdaptor *param_2)

{
  if (*(code **)(this + 8) != (code *)0x0) {
    (**(code **)(this + 8))();
    param_1 = (double)(**(code **)(**(int **)(this + 0x10) + 8))
                                ((double)*(float *)this,*(int **)(this + 0x10),param_2);
  }
  return param_1;
}


/* __thiscall TVariableValue::update_immediate_(TVariableValue *,
                                                         double) */

void __thiscall
TVariableValue::update_immediate_
          (TVariableValue *this,TVariableValue *param_1,double param_2)

{
  *(undefined4 *)this = *(undefined4 *)(this + 0xc);
  *(undefined4 *)(this + 8) = 0;
  return;
}


/* __thiscall TVariableValue::update_time_(TVariableValue *,
                                                    double) */

void __thiscall
TVariableValue::update_time_(TVariableValue *this,TVariableValue *param_1,double param_2)

{
  *(float *)this =
       (float)((double)*(float *)(this + 0xc) *
              ((double)CONCAT44(0x43300000,*(undefined4 *)(this + 4)) - _770) * param_2);
  return;
}


/* __thiscall TVariableValue::update_functionValue_(TVariableValue *,
                                                             double) */

void __thiscall
TVariableValue::update_functionValue_
          (TVariableValue *this,TVariableValue *param_1,double param_2)

{
  double dVar1;
  
  dVar1 = (double)(**(code **)(**(int **)(this + 0xc) + 0x1c))
                            (((double)CONCAT44(0x43300000,*(undefined4 *)(this + 4)) - _770) *
                             param_2);
  *(float *)this = (float)dVar1;
  return;
}


namespace TVariableValue {

/* __thiscall TOutput_none_::~TOutput_none_(void) */

void __thiscall TOutput_none_::_TOutput_none_(TOutput_none_ *this)

{
  short in_r4;
  
  if (this != (TOutput_none_ *)0x0) {
    *(undefined1 **)this = &__vt;
    TOutput::_TOutput((TOutput *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TOutput_none_::operator ()(float,
                                                                  JStudio::TAdaptor *) const */

double __thiscall
TOutput_none_::operator___
          (TOutput_none_ *this,float param_1,TAdaptor *param_2)

{
  return (double)param_1;
}

}

/* __thiscall TAdaptor::~TAdaptor(void) */

void __thiscall TAdaptor::_TAdaptor(TAdaptor *this)

{
  short in_r4;
  
  if ((this != (TAdaptor *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall TAdaptor::adaptor_do_prepare(TObject const *) */

void __thiscall TAdaptor::adaptor_do_prepare(TAdaptor *this,TObject *param_1)

{
  return;
}


/* __thiscall TAdaptor::adaptor_do_begin(TObject const *) */

void __thiscall TAdaptor::adaptor_do_begin(TAdaptor *this,TObject *param_1)

{
  return;
}


/* __thiscall TAdaptor::adaptor_do_end(TObject const *) */

void __thiscall TAdaptor::adaptor_do_end(TAdaptor *this,TObject *param_1)

{
  return;
}


/* __thiscall TAdaptor::adaptor_do_update(TObject const *,
                                                   unsigned long) */

void __thiscall TAdaptor::adaptor_do_update(TAdaptor *this,TObject *param_1,ulong param_2)

{
  return;
}


/* __thiscall TAdaptor::adaptor_do_data(TObject const *,
                                                 void const *,
                                                 unsigned long,
                                                 void const *,
                                                 unsigned long) */

void __thiscall
TAdaptor::adaptor_do_data
          (TAdaptor *this,TObject *param_1,void *param_2,ulong param_3,void *param_4,ulong param_5)

{
  return;
}


/* __thiscall TAdaptor::adaptor_setVariableValue(TObject *,
                                                          unsigned long,
                                                          data::TEOperationData,
                                                          void const *,
                                                          unsigned long) */

TAdaptor * __thiscall
TAdaptor::adaptor_setVariableValue
          (TAdaptor *this,TObject *param_1,ulong param_2,TEOperationData param_3,void *param_4,
          ulong param_5)

{
  code *pcVar1;
  
  switch(param_3) {
  case 0:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x11:
    return this;
  case 1:
    pcVar1 = adaptor_setVariableValue_VOID_;
    break;
  case 2:
    pcVar1 = adaptor_setVariableValue_IMMEDIATE_;
    break;
  case 3:
    pcVar1 = adaptor_setVariableValue_TIME_;
    break;
  case 0x10:
    pcVar1 = adaptor_setVariableValue_FVR_NAME_;
    break;
  case 0x12:
    pcVar1 = adaptor_setVariableValue_FVR_INDEX_;
    break;
  default:
    goto switchD_8026eb40_caseD_13;
  }
  this = (TAdaptor *)(*pcVar1)();
switchD_8026eb40_caseD_13:
  return this;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall TAdaptor::adaptor_setVariableValue_n(TObject *,
                                                            unsigned long const *,
                                                            unsigned long,
                                                            data::TEOperationData,
                                                            void const *,
                                                            unsigned long) */

void __thiscall
TAdaptor::adaptor_setVariableValue_n
          (TAdaptor *this,TObject *param_1,ulong *param_2,ulong param_3,TEOperationData param_4,
          void *param_5,ulong param_6)

{
  code *pcVar1;
  int iVar2;
  ulong *puVar3;
  
  if (param_4 == 3) {
    iVar2 = 4;
    pcVar1 = adaptor_setVariableValue_TIME_;
  }
  else {
    if ((int)param_4 < 3) {
      if (param_4 == 1) {
        iVar2 = 0;
        pcVar1 = adaptor_setVariableValue_VOID_;
      }
      else {
        if ((int)param_4 < 1) {
          return;
        }
        iVar2 = 4;
        pcVar1 = adaptor_setVariableValue_IMMEDIATE_;
      }
    }
    else {
      if (param_4 != 0x12) {
        return;
      }
      iVar2 = 4;
      pcVar1 = adaptor_setVariableValue_FVR_INDEX_;
    }
  }
  puVar3 = param_2 + param_3;
  for (; param_2 != puVar3; param_2 = param_2 + 1) {
    (*pcVar1)(this,param_1,*param_2,param_5,iVar2);
    param_5 = (void *)((int)param_5 + iVar2);
  }
  return;
}


/* __thiscall
   TAdaptor::adaptor_setVariableValue_immediate(TAdaptor::TSetVariableValue_immediate
   const *) */

void __thiscall
TAdaptor::adaptor_setVariableValue_immediate
          (TAdaptor *this,TSetVariableValue_immediate *param_1)

{
  int iVar1;
  int iVar2;
  
  for (; *(int *)param_1 != -1; param_1 = (TSetVariableValue_immediate *)((int)param_1 + 8)) {
    iVar1 = *(int *)((int)param_1 + 4);
    iVar2 = *(int *)(this + 4) + *(int *)param_1 * 0x14;
    *(code **)(iVar2 + 8) = TVariableValue::update_immediate_;
    *(undefined4 *)(iVar2 + 4) = 0;
    *(int *)(iVar2 + 0xc) = iVar1;
  }
  return;
}


/* __thiscall TAdaptor::adaptor_setVariableValue_Vec(unsigned long const *,
                                                              Vec const &) */

void __thiscall
TAdaptor::adaptor_setVariableValue_Vec(TAdaptor *this,ulong *param_1,Vec *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)param_2;
  iVar2 = *(int *)(this + 4) + *param_1 * 0x14;
  *(code **)(iVar2 + 8) = TVariableValue::update_immediate_;
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 0xc) = uVar1;
  uVar1 = *(undefined4 *)(param_2 + 4);
  iVar2 = *(int *)(this + 4) + param_1[1] * 0x14;
  *(code **)(iVar2 + 8) = TVariableValue::update_immediate_;
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 0xc) = uVar1;
  uVar1 = *(undefined4 *)(param_2 + 8);
  iVar2 = *(int *)(this + 4) + param_1[2] * 0x14;
  *(code **)(iVar2 + 8) = TVariableValue::update_immediate_;
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 0xc) = uVar1;
  return;
}


/* __thiscall TAdaptor::adaptor_getVariableValue_Vec(Vec *,
                                                              unsigned long const *) const */

void __thiscall
TAdaptor::adaptor_getVariableValue_Vec(TAdaptor *this,Vec *param_1,ulong *param_2)

{
  *(undefined4 *)param_1 = *(undefined4 *)(*(int *)(this + 4) + *param_2 * 0x14);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(*(int *)(this + 4) + param_2[1] * 0x14);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(this + 4) + param_2[2] * 0x14);
  return;
}


/* __thiscall TAdaptor::adaptor_setVariableValue_GXColor(unsigned long const *,
                                                                  _GXColor const &) */

void __thiscall
TAdaptor::adaptor_setVariableValue_GXColor(TAdaptor *this,ulong *param_1,_GXColor *param_2)

{
  double dVar1;
  byte bVar2;
  double dVar3;
  int iVar4;
  
  dVar3 = _770;
  dVar1 = (double)CONCAT44(0x43300000,(uint)param_2->r) - _770;
  iVar4 = *(int *)(this + 4) + *param_1 * 0x14;
  *(code **)(iVar4 + 8) = TVariableValue::update_immediate_;
  *(undefined4 *)(iVar4 + 4) = 0;
  *(float *)(iVar4 + 0xc) = (float)dVar1;
  bVar2 = param_2->g;
  iVar4 = *(int *)(this + 4) + param_1[1] * 0x14;
  *(code **)(iVar4 + 8) = TVariableValue::update_immediate_;
  *(undefined4 *)(iVar4 + 4) = 0;
  *(float *)(iVar4 + 0xc) = (float)((double)CONCAT44(0x43300000,(uint)bVar2) - dVar3);
  bVar2 = param_2->b;
  iVar4 = *(int *)(this + 4) + param_1[2] * 0x14;
  *(code **)(iVar4 + 8) = TVariableValue::update_immediate_;
  *(undefined4 *)(iVar4 + 4) = 0;
  *(float *)(iVar4 + 0xc) = (float)((double)CONCAT44(0x43300000,(uint)bVar2) - dVar3);
  bVar2 = param_2->a;
  iVar4 = *(int *)(this + 4) + param_1[3] * 0x14;
  *(code **)(iVar4 + 8) = TVariableValue::update_immediate_;
  *(undefined4 *)(iVar4 + 4) = 0;
  *(float *)(iVar4 + 0xc) = (float)((double)CONCAT44(0x43300000,(uint)bVar2) - dVar3);
  return;
}


/* __thiscall TAdaptor::adaptor_getVariableValue_GXColor(_GXColor *,
                                                                  unsigned long const *) const */

void __thiscall
TAdaptor::adaptor_getVariableValue_GXColor(TAdaptor *this,_GXColor *param_1,ulong *param_2)

{
  float fVar1;
  u8 uVar2;
  
  fVar1 = *(float *)(*(int *)(this + 4) + *param_2 * 0x14);
  if (_1037 < fVar1) {
    if (fVar1 < _1038) {
      uVar2 = (u8)(int)fVar1;
    }
    else {
      uVar2 = 0xff;
    }
  }
  else {
    uVar2 = 0;
  }
  param_1->r = uVar2;
  fVar1 = *(float *)(*(int *)(this + 4) + param_2[1] * 0x14);
  if (_1037 < fVar1) {
    if (fVar1 < _1038) {
      uVar2 = (u8)(int)fVar1;
    }
    else {
      uVar2 = 0xff;
    }
  }
  else {
    uVar2 = 0;
  }
  param_1->g = uVar2;
  fVar1 = *(float *)(*(int *)(this + 4) + param_2[2] * 0x14);
  if (_1037 < fVar1) {
    if (fVar1 < _1038) {
      uVar2 = (u8)(int)fVar1;
    }
    else {
      uVar2 = 0xff;
    }
  }
  else {
    uVar2 = 0;
  }
  param_1->b = uVar2;
  fVar1 = *(float *)(*(int *)(this + 4) + param_2[3] * 0x14);
  if (_1037 < fVar1) {
    if (fVar1 < _1038) {
      uVar2 = (u8)(int)fVar1;
    }
    else {
      uVar2 = 0xff;
    }
  }
  else {
    uVar2 = 0;
  }
  param_1->a = uVar2;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall TAdaptor::adaptor_updateVariableValue(TObject *,
                                                             unsigned long) */

void __thiscall
TAdaptor::adaptor_updateVariableValue(TAdaptor *this,TObject *param_1,ulong param_2)

{
  int iVar1;
  TVariableValue *pTVar2;
  TVariableValue *this_00;
  double dVar3;
  
  dVar3 = *(double *)(param_1[5].vtbl + 0x58);
  pTVar2 = *(TVariableValue **)(this + 4);
  iVar1 = *(int *)(this + 8);
  this_00 = pTVar2;
  while (this_00 != pTVar2 + iVar1 * 0x14) {
    if (param_2 < -*(int *)(this_00 + 4) - 1U) {
      *(ulong *)(this_00 + 4) = *(int *)(this_00 + 4) + param_2;
    }
    else {
      *(undefined4 *)(this_00 + 4) = 0xffffffff;
    }
    TVariableValue::update(this_00,dVar3,this);
    this_00 = this_00 + 0x14;
  }
  return;
}


/* __thiscall TAdaptor::adaptor_setVariableValue_VOID_(TAdaptor *,
                                                                TObject *,
                                                                unsigned long,
                                                                void const *,
                                                                unsigned long) */

void __thiscall
TAdaptor::adaptor_setVariableValue_VOID_
          (TAdaptor *this,TAdaptor *param_1,TObject *param_2,ulong param_3,void *param_4,
          ulong param_5)

{
  *(undefined4 *)(*(int *)(this + 4) + (int)param_2 * 0x14 + 8) = 0;
  return;
}


/* __thiscall TAdaptor::adaptor_setVariableValue_IMMEDIATE_(TAdaptor *,
                                                                     TObject *,
                                                                     unsigned long,
                                                                     void const *,
                                                                     unsigned long) */

void __thiscall
TAdaptor::adaptor_setVariableValue_IMMEDIATE_
          (TAdaptor *this,TAdaptor *param_1,TObject *param_2,ulong param_3,void *param_4,
          ulong param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 4) + (int)param_2 * 0x14;
  uVar1 = *(undefined4 *)param_3;
  *(code **)(iVar2 + 8) = TVariableValue::update_immediate_;
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 0xc) = uVar1;
  return;
}


/* __thiscall TAdaptor::adaptor_setVariableValue_TIME_(TAdaptor *,
                                                                TObject *,
                                                                unsigned long,
                                                                void const *,
                                                                unsigned long) */

void __thiscall
TAdaptor::adaptor_setVariableValue_TIME_
          (TAdaptor *this,TAdaptor *param_1,TObject *param_2,ulong param_3,void *param_4,
          ulong param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 4) + (int)param_2 * 0x14;
  uVar1 = *(undefined4 *)param_3;
  *(code **)(iVar2 + 8) = TVariableValue::update_time_;
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 0xc) = uVar1;
  return;
}


/* __thiscall TAdaptor::adaptor_setVariableValue_FVR_NAME_(TAdaptor *,
                                                                    TObject *,
                                                                    unsigned long,
                                                                    void const *,
                                                                    unsigned long) */

void __thiscall
TAdaptor::adaptor_setVariableValue_FVR_NAME_
          (TAdaptor *this,TAdaptor *param_1,TObject *param_2,ulong param_3,void *param_4,
          ulong param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(this + 4) + (int)param_2 * 0x14;
  iVar1 = fvb::TControl::getObject
                    ((TControl *)(*(int *)(param_1 + 0x14) + 0x60),(void *)param_3,(ulong)param_4);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x14);
  }
  *(code **)(iVar3 + 8) = TVariableValue::update_functionValue_;
  *(undefined4 *)(iVar3 + 4) = 0;
  *(undefined4 *)(iVar3 + 0xc) = uVar2;
  return;
}


/* __thiscall TAdaptor::adaptor_setVariableValue_FVR_INDEX_(TAdaptor *,
                                                                     TObject *,
                                                                     unsigned long,
                                                                     void const *,
                                                                     unsigned long) */

void __thiscall
TAdaptor::adaptor_setVariableValue_FVR_INDEX_
          (TAdaptor *this,TAdaptor *param_1,TObject *param_2,ulong param_3,void *param_4,
          ulong param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(this + 4) + (int)param_2 * 0x14;
  iVar1 = fvb::TControl::getObject_index
                    ((TControl *)(*(int *)(param_1 + 0x14) + 0x60),*(ulong *)param_3);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x14);
  }
  *(code **)(iVar3 + 8) = TVariableValue::update_functionValue_;
  *(undefined4 *)(iVar3 + 4) = 0;
  *(undefined4 *)(iVar3 + 0xc) = uVar2;
  return;
}


/* __thiscall TObject::~TObject(void) */

void __thiscall TObject::_TObject(TObject *this)

{
  int *piVar1;
  short in_r4;
  
  if (this != (TObject *)0x0) {
    this[2].vtbl = &__vt;
    piVar1 = (int *)this[0xd].vtbl;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1,1);
    }
    stb::TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TObject::forward_value(unsigned long) */

void __thiscall TObject::forward_value(TObject *this,ulong param_1)

{
  int *this_00;
  
  this_00 = (int *)this[0xd].vtbl;
  if (this_00 != (int *)0x0) {
    TAdaptor::adaptor_updateVariableValue((TAdaptor *)this_00,this,param_1);
    (**(code **)(*this_00 + 0x18))(this_00,this,param_1);
  }
  return;
}


/* __thiscall TObject::do_begin(void) */

void __thiscall TObject::do_begin(TObject *this)

{
  int *piVar1;
  
  piVar1 = (int *)this[0xd].vtbl;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(piVar1,this);
  }
  return;
}


/* __thiscall TObject::do_end(void) */

void __thiscall TObject::do_end(TObject *this)

{
  int *piVar1;
  
  piVar1 = (int *)this[0xd].vtbl;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x14))(piVar1,this);
  }
  return;
}


/* __thiscall TObject::do_wait(unsigned long) */

void __thiscall TObject::do_wait(TObject *this,ulong param_1)

{
  forward_value(this,param_1);
  return;
}


/* __thiscall TObject::do_data(void const *,
                                        unsigned long,
                                        void const *,
                                        unsigned long) */

void __thiscall
TObject::do_data(TObject *this,void *param_1,ulong param_2,void *param_3,ulong param_4)

{
  int *piVar1;
  
  piVar1 = (int *)this[0xd].vtbl;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))(piVar1,this,param_1,param_2,param_3,param_4);
  }
  return;
}


/* __thiscall TObject::TObject(stb::data::TParse_TBlock_object const &,
                                        TAdaptor *) */

void __thiscall
TObject::TObject(TObject *this,TParse_TBlock_object *param_1,TAdaptor *param_2)

{
  stb::TObject::TObject((TObject *)this,param_1);
  this[2].vtbl = &__vt;
  this[0xd].vtbl = param_2;
  return;
}


/* __thiscall TAdaptor_actor::~TAdaptor_actor(void) */

void __thiscall TAdaptor_actor::_TAdaptor_actor(TAdaptor_actor *this)

{
  short in_r4;
  
  if (this != (TAdaptor_actor *)0x0) {
    *(undefined1 **)this = &__vt;
    TAdaptor::_TAdaptor((TAdaptor *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_actor::TObject_actor(stb::data::TParse_TBlock_object const
   &,
                                                    TAdaptor_actor *) */

void __thiscall
TObject_actor::TObject_actor
          (TObject_actor *this,TParse_TBlock_object *param_1,TAdaptor_actor *param_2)

{
  TObject::TObject((TObject *)this,param_1,(TAdaptor *)param_2);
  *(undefined1 **)(this + 8) = &__vt;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TObject_actor::do_paragraph(unsigned long,
                                                   void const *,
                                                   unsigned long) */

void __thiscall
TObject_actor::do_paragraph(TObject_actor *this,ulong param_1,void *param_2,ulong param_3)

{
  undefined *puVar1;
  undefined1 *puVar2;
  ulong uVar3;
  ulong *puVar4;
  TAdaptor *this_00;
  PTMF local_28 [2];
  
  puVar4 = (ulong *)&TAdaptor_actor::sauVariableValue_3_TRANSLATION_XYZ;
  this_00 = *(TAdaptor **)(this + 0x34);
  if (this_00 == (TAdaptor *)0x0) {
    return;
  }
  puVar1 = (undefined *)(param_1 & 0x1f);
  local_28[0].this_delta = Runtime.PPCEABI.H::__ptmf_null;
  local_28[0].vtbl_offset = DAT_80370fbc;
  local_28[0].func = DAT_80370fc0;
  switch(param_1 >> 5) {
  case 9:
    uVar3 = 3;
    break;
  case 10:
    uVar3 = 4;
    break;
  case 0xb:
    uVar3 = 5;
    break;
  case 0xc:
    goto LAB_8026f76c;
  case 0xd:
    uVar3 = 6;
    break;
  case 0xe:
    uVar3 = 7;
    break;
  case 0xf:
    uVar3 = 8;
    break;
  case 0x10:
    puVar4 = (ulong *)&TAdaptor_actor::sauVariableValue_3_ROTATION_XYZ;
    goto LAB_8026f76c;
  case 0x11:
    uVar3 = 9;
    break;
  case 0x12:
    uVar3 = 10;
    break;
  case 0x13:
    uVar3 = 0xb;
    break;
  case 0x14:
    puVar4 = (ulong *)&TAdaptor_actor::sauVariableValue_3_SCALING_XYZ;
LAB_8026f76c:
    TAdaptor::adaptor_setVariableValue_n
              (this_00,(TObject *)this,puVar4,3,(TEOperationData)puVar1,param_2,param_3);
    return;
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4d:
    return;
  case 0x30:
    local_28[0].this_delta = _1269;
    local_28[0].vtbl_offset = DAT_80396fb4;
    local_28[0].func = DAT_80396fb8;
    goto LAB_8026f77c;
  case 0x31:
    local_28[0].this_delta = _1271;
    local_28[0].vtbl_offset = DAT_80396fc0;
    local_28[0].func = DAT_80396fc4;
    goto LAB_8026f77c;
  case 0x32:
    local_28[0].this_delta = _1273;
    local_28[0].vtbl_offset = DAT_80396fcc;
    local_28[0].func = DAT_80396fd0;
    uVar3 = 0xc;
    puVar2 = &@unnamed@jstudio_object_cpp@::soovv_actor_PARENT_ENABLE_;
    goto LAB_8026f6d8;
  case 0x33:
    local_28[0].this_delta = _1276;
    local_28[0].vtbl_offset = DAT_80396fd8;
    local_28[0].func = DAT_80396fdc;
    goto LAB_8026f77c;
  case 0x34:
    local_28[0].this_delta = _1278;
    local_28[0].vtbl_offset = DAT_80396fe4;
    local_28[0].func = DAT_80396fe8;
    goto LAB_8026f77c;
  case 0x35:
    local_28[0].this_delta = _1280;
    local_28[0].vtbl_offset = DAT_80396ff0;
    local_28[0].func = DAT_80396ff4;
    uVar3 = 0xd;
    puVar2 = &@unnamed@jstudio_object_cpp@::soovv_actor_RELATION_ENABLE_;
LAB_8026f6d8:
    if ((puVar1 < (undefined *)0x13) && (&DAT_00000010 <= puVar1)) {
      TAdaptor::adaptor_setVariableValue
                (this_00,(TObject *)this,uVar3,(TEOperationData)puVar1,param_2,param_3);
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &TVariableValue::soOutput_none_;
      }
      *(undefined1 **)(*(int *)(this_00 + 4) + uVar3 * 0x14 + 0x10) = puVar2;
      return;
    }
    Runtime.PPCEABI.H::__ptmf_scall(local_28,this_00,puVar1);
    return;
  case 0x39:
    local_28[0].this_delta = _1258;
    local_28[0].vtbl_offset = DAT_80396f78;
    local_28[0].func = DAT_80396f7c;
    goto LAB_8026f77c;
  case 0x3a:
    local_28[0].this_delta = _1261;
    local_28[0].vtbl_offset = DAT_80396f84;
    local_28[0].func = DAT_80396f88;
    goto LAB_8026f77c;
  case 0x3b:
    uVar3 = 0;
    break;
  case 0x43:
    local_28[0].this_delta = _1263;
    local_28[0].vtbl_offset = DAT_80396f90;
    local_28[0].func = DAT_80396f94;
    goto LAB_8026f77c;
  case 0x4b:
    uVar3 = 1;
    break;
  case 0x4c:
    local_28[0].this_delta = _1265;
    local_28[0].vtbl_offset = DAT_80396f9c;
    local_28[0].func = DAT_80396fa0;
    goto LAB_8026f77c;
  case 0x4e:
    local_28[0].this_delta = _1267;
    local_28[0].vtbl_offset = DAT_80396fa8;
    local_28[0].func = DAT_80396fac;
LAB_8026f77c:
    Runtime.PPCEABI.H::__ptmf_scall(local_28,this_00,puVar1);
  default:
    goto switchD_8026f500_caseD_46;
  }
  TAdaptor::adaptor_setVariableValue
            (this_00,(TObject *)this,uVar3,(TEOperationData)puVar1,param_2,param_3);
switchD_8026f500_caseD_46:
  return;
}


/* __thiscall TAdaptor_ambientLight::~TAdaptor_ambientLight(void) */

void __thiscall TAdaptor_ambientLight::_TAdaptor_ambientLight(TAdaptor_ambientLight *this)

{
  short in_r4;
  
  if (this != (TAdaptor_ambientLight *)0x0) {
    *(undefined1 **)this = &__vt;
    TAdaptor::_TAdaptor((TAdaptor *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall
   TObject_ambientLight::TObject_ambientLight(stb::data::TParse_TBlock_object
   const &,
                                                                  TAdaptor_ambientLight *)
    */

void __thiscall
TObject_ambientLight::TObject_ambientLight
          (TObject_ambientLight *this,TParse_TBlock_object *param_1,TAdaptor_ambientLight *param_2)

{
  TObject::TObject((TObject *)this,param_1,(TAdaptor *)param_2);
  *(undefined1 **)(this + 8) = &__vt;
  return;
}


/* __thiscall TObject_ambientLight::do_paragraph(unsigned long,
                                                          void const *,
                                                          unsigned long) */

void __thiscall
TObject_ambientLight::do_paragraph
          (TObject_ambientLight *this,ulong param_1,void *param_2,ulong param_3)

{
  uint uVar1;
  ulong *puVar2;
  TAdaptor *this_00;
  ulong uVar3;
  
  this_00 = *(TAdaptor **)(this + 0x34);
  if (this_00 != (TAdaptor *)0x0) {
    uVar1 = param_1 >> 5;
    if (uVar1 == 0x20) {
      uVar3 = 3;
    }
    else {
      if (0x1f < uVar1) {
        if (uVar1 == 0x22) {
          puVar2 = (ulong *)&TAdaptor_ambientLight::sauVariableValue_4_COLOR_RGBA;
          uVar3 = 4;
        }
        else {
          if (0x21 < uVar1) {
            return;
          }
          puVar2 = (ulong *)&TAdaptor_ambientLight::sauVariableValue_3_COLOR_RGB;
          uVar3 = 3;
        }
        TAdaptor::adaptor_setVariableValue_n
                  (this_00,(TObject *)this,puVar2,uVar3,param_1 & 0x1f,param_2,param_3);
        return;
      }
      if (uVar1 == 0x1e) {
        uVar3 = 1;
      }
      else {
        if (uVar1 < 0x1e) {
          if (uVar1 < 0x1d) {
            return;
          }
          uVar3 = 0;
        }
        else {
          uVar3 = 2;
        }
      }
    }
    TAdaptor::adaptor_setVariableValue(this_00,(TObject *)this,uVar3,param_1 & 0x1f,param_2,param_3)
    ;
  }
  return;
}


/* __thiscall TAdaptor_camera::~TAdaptor_camera(void) */

void __thiscall TAdaptor_camera::_TAdaptor_camera(TAdaptor_camera *this)

{
  short in_r4;
  
  if (this != (TAdaptor_camera *)0x0) {
    *(undefined1 **)this = &__vt;
    TAdaptor::_TAdaptor((TAdaptor *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_camera::TObject_camera(stb::data::TParse_TBlock_object const
   &,
                                                      TAdaptor_camera *) */

void __thiscall
TObject_camera::TObject_camera
          (TObject_camera *this,TParse_TBlock_object *param_1,TAdaptor_camera *param_2)

{
  TObject::TObject((TObject *)this,param_1,(TAdaptor *)param_2);
  *(undefined1 **)(this + 8) = &__vt;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8026fb70) */
/* __thiscall TObject_camera::do_paragraph(unsigned long,
                                                    void const *,
                                                    unsigned long) */

void __thiscall
TObject_camera::do_paragraph
          (TObject_camera *this,ulong param_1,void *param_2,ulong param_3)

{
  undefined *puVar1;
  ulong *puVar2;
  ulong uVar3;
  TAdaptor *this_00;
  PTMF local_18;
  
  this_00 = *(TAdaptor **)(this + 0x34);
  if (this_00 == (TAdaptor *)0x0) {
    return;
  }
  puVar1 = (undefined *)(param_1 & 0x1f);
  local_18.this_delta = Runtime.PPCEABI.H::__ptmf_null;
  local_18.vtbl_offset = DAT_80370fbc;
  local_18.func = DAT_80370fc0;
  switch(param_1 >> 5) {
  case 0x15:
    uVar3 = 0;
    break;
  case 0x16:
    uVar3 = 1;
    break;
  case 0x17:
    uVar3 = 2;
    break;
  case 0x18:
    puVar2 = (ulong *)&TAdaptor_camera::sauVariableValue_3_POSITION_XYZ;
    uVar3 = 3;
    goto LAB_8026fbb8;
  case 0x19:
    uVar3 = 3;
    break;
  case 0x1a:
    uVar3 = 4;
    break;
  case 0x1b:
    uVar3 = 5;
    break;
  case 0x1c:
    puVar2 = (ulong *)&TAdaptor_camera::sauVariableValue_3_TARGET_POSITION_XYZ;
    uVar3 = 3;
    goto LAB_8026fbb8;
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
    return;
  case 0x26:
    uVar3 = 7;
    break;
  case 0x27:
    uVar3 = 6;
    break;
  case 0x28:
    uVar3 = 8;
    break;
  case 0x29:
    uVar3 = 9;
    break;
  case 0x2a:
    puVar2 = (ulong *)&TAdaptor_camera::sauVariableValue_2_DISTANCE_NEAR_FAR;
    uVar3 = 2;
LAB_8026fbb8:
    TAdaptor::adaptor_setVariableValue_n
              (this_00,(TObject *)this,puVar2,uVar3,(TEOperationData)puVar1,param_2,param_3);
    return;
  case 0x30:
    local_18.this_delta = _1388;
    local_18.vtbl_offset = DAT_80397114;
    local_18.func = DAT_80397118;
    goto LAB_8026fbc8;
  case 0x31:
    local_18.this_delta = _1391;
    local_18.vtbl_offset = DAT_80397120;
    local_18.func = DAT_80397124;
LAB_8026fbc8:
    Runtime.PPCEABI.H::__ptmf_scall(&local_18,this_00,puVar1);
    return;
  case 0x32:
    local_18.this_delta = _1393;
    local_18.vtbl_offset = DAT_8039712c;
    local_18.func = DAT_80397130;
    if ((puVar1 < (undefined *)0x13) && (&DAT_00000010 <= puVar1)) {
      TAdaptor::adaptor_setVariableValue
                (this_00,(TObject *)this,10,(TEOperationData)puVar1,param_2,param_3);
      *(undefined1 **)(*(int *)(this_00 + 4) + 0xd8) =
           &@unnamed@jstudio_object_cpp@::soovv_camera_PARENT_ENABLE_;
    }
    else {
      Runtime.PPCEABI.H::__ptmf_scall(&local_18,this_00,puVar1);
    }
  default:
    goto switchD_8026fa40_caseD_1e;
  }
  TAdaptor::adaptor_setVariableValue
            (this_00,(TObject *)this,uVar3,(TEOperationData)puVar1,param_2,param_3);
switchD_8026fa40_caseD_1e:
  return;
}


/* __thiscall TAdaptor_fog::~TAdaptor_fog(void) */

void __thiscall TAdaptor_fog::_TAdaptor_fog(TAdaptor_fog *this)

{
  short in_r4;
  
  if (this != (TAdaptor_fog *)0x0) {
    *(undefined1 **)this = &__vt;
    TAdaptor::_TAdaptor((TAdaptor *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_fog::TObject_fog(stb::data::TParse_TBlock_object const &,
                                                TAdaptor_fog *) */

void __thiscall
TObject_fog::TObject_fog
          (TObject_fog *this,TParse_TBlock_object *param_1,TAdaptor_fog *param_2)

{
  TObject::TObject((TObject *)this,param_1,(TAdaptor *)param_2);
  *(undefined1 **)(this + 8) = &__vt;
  return;
}


/* __thiscall TObject_fog::do_paragraph(unsigned long,
                                                 void const *,
                                                 unsigned long) */

void __thiscall
TObject_fog::do_paragraph(TObject_fog *this,ulong param_1,void *param_2,ulong param_3)

{
  TAdaptor *this_00;
  ulong *puVar1;
  ulong uVar2;
  
  this_00 = *(TAdaptor **)(this + 0x34);
  if (this_00 == (TAdaptor *)0x0) {
    return;
  }
  switch(param_1 >> 5) {
  case 0x1d:
    uVar2 = 0;
    break;
  case 0x1e:
    uVar2 = 1;
    break;
  case 0x1f:
    uVar2 = 2;
    break;
  case 0x20:
    uVar2 = 3;
    break;
  case 0x21:
    puVar1 = (ulong *)&TAdaptor_fog::sauVariableValue_3_COLOR_RGB;
    uVar2 = 3;
    goto LAB_8026fd68;
  case 0x22:
    puVar1 = (ulong *)&TAdaptor_fog::sauVariableValue_4_COLOR_RGBA;
    uVar2 = 4;
    goto LAB_8026fd68;
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
    return;
  case 0x2b:
    uVar2 = 4;
    break;
  case 0x2c:
    uVar2 = 5;
    break;
  case 0x2d:
    puVar1 = (ulong *)&TAdaptor_fog::sauVariableValue_2_RANGE_BEGIN_END;
    uVar2 = 2;
LAB_8026fd68:
    TAdaptor::adaptor_setVariableValue_n
              (this_00,(TObject *)this,puVar1,uVar2,param_1 & 0x1f,param_2,param_3);
    return;
  default:
    return;
  }
  TAdaptor::adaptor_setVariableValue(this_00,(TObject *)this,uVar2,param_1 & 0x1f,param_2,param_3);
  return;
}


/* __thiscall TAdaptor_light::~TAdaptor_light(void) */

void __thiscall TAdaptor_light::_TAdaptor_light(TAdaptor_light *this)

{
  short in_r4;
  
  if (this != (TAdaptor_light *)0x0) {
    *(undefined1 **)this = &__vt;
    TAdaptor::_TAdaptor((TAdaptor *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_light::TObject_light(stb::data::TParse_TBlock_object const
   &,
                                                    TAdaptor_light *) */

void __thiscall
TObject_light::TObject_light
          (TObject_light *this,TParse_TBlock_object *param_1,TAdaptor_light *param_2)

{
  TObject::TObject((TObject *)this,param_1,(TAdaptor *)param_2);
  *(undefined1 **)(this + 8) = &__vt;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8026ffd4) */
/* __thiscall TObject_light::do_paragraph(unsigned long,
                                                   void const *,
                                                   unsigned long) */

void __thiscall
TObject_light::do_paragraph(TObject_light *this,ulong param_1,void *param_2,ulong param_3)

{
  undefined *puVar1;
  ulong *puVar2;
  ulong uVar3;
  TAdaptor *this_00;
  PTMF local_18;
  
  this_00 = *(TAdaptor **)(this + 0x34);
  if (this_00 == (TAdaptor *)0x0) {
    return;
  }
  puVar1 = (undefined *)(param_1 & 0x1f);
  local_18.this_delta = Runtime.PPCEABI.H::__ptmf_null;
  local_18.vtbl_offset = DAT_80370fbc;
  local_18.func = DAT_80370fc0;
  switch(param_1 >> 5) {
  case 0x15:
    uVar3 = 4;
    break;
  case 0x16:
    uVar3 = 5;
    break;
  case 0x17:
    uVar3 = 6;
    break;
  case 0x18:
    puVar2 = (ulong *)&TAdaptor_light::sauVariableValue_3_POSITION_XYZ;
    uVar3 = 3;
    goto LAB_8027001c;
  case 0x19:
    uVar3 = 7;
    break;
  case 0x1a:
    uVar3 = 8;
    break;
  case 0x1b:
    uVar3 = 9;
    break;
  case 0x1c:
    puVar2 = (ulong *)&TAdaptor_light::sauVariableValue_3_TARGET_POSITION_XYZ;
    uVar3 = 3;
    goto LAB_8027001c;
  case 0x1d:
    uVar3 = 0;
    break;
  case 0x1e:
    uVar3 = 1;
    break;
  case 0x1f:
    uVar3 = 2;
    break;
  case 0x20:
    uVar3 = 3;
    break;
  case 0x21:
    puVar2 = (ulong *)&TAdaptor_light::sauVariableValue_3_COLOR_RGB;
    uVar3 = 3;
    goto LAB_8027001c;
  case 0x22:
    puVar2 = (ulong *)&TAdaptor_light::sauVariableValue_4_COLOR_RGBA;
    uVar3 = 4;
    goto LAB_8027001c;
  case 0x23:
    uVar3 = 10;
    break;
  case 0x24:
    uVar3 = 0xb;
    break;
  case 0x25:
    puVar2 = (ulong *)&TAdaptor_light::sauVariableValue_2_DIRECTION_THETA_PHI;
    uVar3 = 2;
LAB_8027001c:
    TAdaptor::adaptor_setVariableValue_n
              (this_00,(TObject *)this,puVar2,uVar3,(TEOperationData)puVar1,param_2,param_3);
    return;
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
    return;
  case 0x36:
    local_18.this_delta = _1504;
    local_18.vtbl_offset = DAT_803971f4;
    local_18.func = DAT_803971f8;
    if ((puVar1 < (undefined *)0x13) && (&DAT_00000010 <= puVar1)) {
      TAdaptor::adaptor_setVariableValue
                (this_00,(TObject *)this,0xc,(TEOperationData)puVar1,param_2,param_3);
      *(undefined1 **)(*(int *)(this_00 + 4) + 0x100) =
           &@unnamed@jstudio_object_cpp@::soovv_light_ENABLE_;
      return;
    }
    Runtime.PPCEABI.H::__ptmf_scall(&local_18,this_00,puVar1);
    return;
  case 0x37:
    local_18.this_delta = _1507;
    local_18.vtbl_offset = DAT_80397200;
    local_18.func = DAT_80397204;
    Runtime.PPCEABI.H::__ptmf_scall(&local_18,this_00,puVar1);
  default:
    goto switchD_8026fe98_caseD_23;
  }
  TAdaptor::adaptor_setVariableValue
            (this_00,(TObject *)this,uVar3,(TEOperationData)puVar1,param_2,param_3);
switchD_8026fe98_caseD_23:
  return;
}


/* __thiscall TAdaptor_message::~TAdaptor_message(void) */

void __thiscall TAdaptor_message::_TAdaptor_message(TAdaptor_message *this)

{
  short in_r4;
  
  if (this != (TAdaptor_message *)0x0) {
    *(undefined1 **)this = &__vt;
    TAdaptor::_TAdaptor((TAdaptor *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_message::TObject_message(stb::data::TParse_TBlock_object
   const &,
                                                        TAdaptor_message *) */

void __thiscall
TObject_message::TObject_message
          (TObject_message *this,TParse_TBlock_object *param_1,TAdaptor_message *param_2)

{
  TObject::TObject((TObject *)this,param_1,(TAdaptor *)param_2);
  *(undefined1 **)(this + 8) = &__vt;
  return;
}


/* __thiscall TObject_message::do_paragraph(unsigned long,
                                                     void const *,
                                                     unsigned long) */

void __thiscall
TObject_message::do_paragraph
          (TObject_message *this,ulong param_1,void *param_2,ulong param_3)

{
  PTMF local_18 [2];
  
  if ((*(void **)(this + 0x34) != (void *)0x0) && (param_1 >> 5 == 0x42)) {
    local_18[0].this_delta = _1569;
    local_18[0].vtbl_offset = DAT_80397298;
    local_18[0].func = DAT_8039729c;
    Runtime.PPCEABI.H::__ptmf_scall(local_18,*(void **)(this + 0x34),(void *)(param_1 & 0x1f));
  }
  return;
}


/* __thiscall TAdaptor_particle::~TAdaptor_particle(void) */

void __thiscall TAdaptor_particle::_TAdaptor_particle(TAdaptor_particle *this)

{
  short in_r4;
  
  if (this != (TAdaptor_particle *)0x0) {
    *(undefined1 **)this = &__vt;
    TAdaptor::_TAdaptor((TAdaptor *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_particle::TObject_particle(stb::data::TParse_TBlock_object
   const &,
                                                          TAdaptor_particle *) */

void __thiscall
TObject_particle::TObject_particle
          (TObject_particle *this,TParse_TBlock_object *param_1,TAdaptor_particle *param_2)

{
  TObject::TObject((TObject *)this,param_1,(TAdaptor *)param_2);
  *(undefined1 **)(this + 8) = &__vt;
  return;
}


/* WARNING: Removing unreachable block (ram,0x80270458) */
/* __thiscall TObject_particle::do_paragraph(unsigned long,
                                                      void const *,
                                                      unsigned long) */

void __thiscall
TObject_particle::do_paragraph
          (TObject_particle *this,ulong param_1,void *param_2,ulong param_3)

{
  undefined *puVar1;
  ulong *puVar2;
  ulong uVar3;
  TAdaptor *this_00;
  PTMF local_18;
  
  this_00 = *(TAdaptor **)(this + 0x34);
  if (this_00 == (TAdaptor *)0x0) {
    return;
  }
  puVar1 = (undefined *)(param_1 & 0x1f);
  local_18.this_delta = Runtime.PPCEABI.H::__ptmf_null;
  local_18.vtbl_offset = DAT_80370fbc;
  local_18.func = DAT_80370fc0;
  switch(param_1 >> 5) {
  case 9:
    uVar3 = 0;
    break;
  case 10:
    uVar3 = 1;
    break;
  case 0xb:
    uVar3 = 2;
    break;
  case 0xc:
    puVar2 = (ulong *)&TAdaptor_particle::sauVariableValue_3_TRANSLATION_XYZ;
    uVar3 = 3;
    goto LAB_802704a0;
  case 0xd:
    uVar3 = 3;
    break;
  case 0xe:
    uVar3 = 4;
    break;
  case 0xf:
    uVar3 = 5;
    break;
  case 0x10:
    puVar2 = (ulong *)&TAdaptor_particle::sauVariableValue_3_ROTATION_XYZ;
    uVar3 = 3;
    goto LAB_802704a0;
  case 0x11:
    uVar3 = 6;
    break;
  case 0x12:
    uVar3 = 7;
    break;
  case 0x13:
    uVar3 = 8;
    break;
  case 0x14:
    puVar2 = (ulong *)&TAdaptor_particle::sauVariableValue_3_SCALING_XYZ;
    uVar3 = 3;
    goto LAB_802704a0;
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
    return;
  case 0x1d:
    uVar3 = 9;
    break;
  case 0x1e:
    uVar3 = 10;
    break;
  case 0x1f:
    uVar3 = 0xb;
    break;
  case 0x20:
    uVar3 = 0xc;
    break;
  case 0x21:
    puVar2 = (ulong *)&TAdaptor_particle::sauVariableValue_3_COLOR_RGB;
    uVar3 = 3;
    goto LAB_802704a0;
  case 0x22:
    puVar2 = (ulong *)&TAdaptor_particle::sauVariableValue_4_COLOR_RGBA;
    uVar3 = 4;
    goto LAB_802704a0;
  case 0x2e:
    uVar3 = 0x12;
    break;
  case 0x2f:
    uVar3 = 0x13;
    break;
  case 0x30:
    local_18.this_delta = _1616;
    local_18.vtbl_offset = DAT_803972b0;
    local_18.func = DAT_803972b4;
    goto LAB_802704b0;
  case 0x31:
    local_18.this_delta = _1618;
    local_18.vtbl_offset = DAT_803972bc;
    local_18.func = DAT_803972c0;
    goto LAB_802704b0;
  case 0x32:
    local_18.this_delta = _1620;
    local_18.vtbl_offset = DAT_803972c8;
    local_18.func = DAT_803972cc;
    if ((puVar1 < (undefined *)0x13) && (&DAT_00000010 <= puVar1)) {
      TAdaptor::adaptor_setVariableValue
                (this_00,(TObject *)this,0x11,(TEOperationData)puVar1,param_2,param_3);
      *(undefined1 **)(*(int *)(this_00 + 4) + 0x164) =
           &@unnamed@jstudio_object_cpp@::soovv_particle_PARENT_ENABLE_;
      return;
    }
    Runtime.PPCEABI.H::__ptmf_scall(&local_18,this_00,puVar1);
    return;
  case 0x44:
    local_18.this_delta = _1613;
    local_18.vtbl_offset = DAT_803972a4;
    local_18.func = DAT_803972a8;
LAB_802704b0:
    Runtime.PPCEABI.H::__ptmf_scall(&local_18,this_00,puVar1);
    return;
  case 0x45:
    uVar3 = 0xd;
    break;
  case 0x46:
    uVar3 = 0xe;
    break;
  case 0x47:
    uVar3 = 0xf;
    break;
  case 0x48:
    uVar3 = 0x10;
    break;
  case 0x49:
    puVar2 = (ulong *)&TAdaptor_particle::sauVariableValue_3_COLOR1_RGB;
    uVar3 = 3;
    goto LAB_802704a0;
  case 0x4a:
    puVar2 = (ulong *)&TAdaptor_particle::sauVariableValue_4_COLOR1_RGBA;
    uVar3 = 4;
LAB_802704a0:
    TAdaptor::adaptor_setVariableValue_n
              (this_00,(TObject *)this,puVar2,uVar3,(TEOperationData)puVar1,param_2,param_3);
  default:
    goto switchD_802702a4_caseD_42;
  }
  TAdaptor::adaptor_setVariableValue
            (this_00,(TObject *)this,uVar3,(TEOperationData)puVar1,param_2,param_3);
switchD_802702a4_caseD_42:
  return;
}


/* __thiscall TAdaptor_sound::~TAdaptor_sound(void) */

void __thiscall TAdaptor_sound::_TAdaptor_sound(TAdaptor_sound *this)

{
  short in_r4;
  
  if (this != (TAdaptor_sound *)0x0) {
    *(undefined1 **)this = &__vt;
    TAdaptor::_TAdaptor((TAdaptor *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_sound::TObject_sound(stb::data::TParse_TBlock_object const
   &,
                                                    TAdaptor_sound *) */

void __thiscall
TObject_sound::TObject_sound
          (TObject_sound *this,TParse_TBlock_object *param_1,TAdaptor_sound *param_2)

{
  TObject::TObject((TObject *)this,param_1,(TAdaptor *)param_2);
  *(undefined1 **)(this + 8) = &__vt;
  return;
}


/* WARNING: Removing unreachable block (ram,0x802706f0) */
/* __thiscall TObject_sound::do_paragraph(unsigned long,
                                                   void const *,
                                                   unsigned long) */

void __thiscall
TObject_sound::do_paragraph(TObject_sound *this,ulong param_1,void *param_2,ulong param_3)

{
  undefined *puVar1;
  ulong uVar2;
  TAdaptor *this_00;
  PTMF local_18;
  
  this_00 = *(TAdaptor **)(this + 0x34);
  if (this_00 == (TAdaptor *)0x0) {
    return;
  }
  puVar1 = (undefined *)(param_1 & 0x1f);
  local_18.this_delta = Runtime.PPCEABI.H::__ptmf_null;
  local_18.vtbl_offset = DAT_80370fbc;
  local_18.func = DAT_80370fc0;
  switch(param_1 >> 5) {
  case 0x15:
    uVar2 = 0;
    break;
  case 0x16:
    uVar2 = 1;
    break;
  case 0x17:
    uVar2 = 2;
    break;
  case 0x18:
    TAdaptor::adaptor_setVariableValue_n
              (this_00,(TObject *)this,(ulong *)&TAdaptor_sound::sauVariableValue_3_POSITION_XYZ,3,
               (TEOperationData)puVar1,param_2,param_3);
    return;
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x39:
  case 0x3a:
  case 0x3b:
    return;
  case 0x2e:
    uVar2 = 3;
    break;
  case 0x2f:
    uVar2 = 4;
    break;
  case 0x38:
    local_18.this_delta = _1694;
    local_18.vtbl_offset = DAT_803973e8;
    local_18.func = DAT_803973ec;
    if ((puVar1 < (undefined *)0x13) && (&DAT_00000010 <= puVar1)) {
      TAdaptor::adaptor_setVariableValue
                (this_00,(TObject *)this,5,(TEOperationData)puVar1,param_2,param_3);
      *(undefined1 **)(*(int *)(this_00 + 4) + 0x74) =
           &@unnamed@jstudio_object_cpp@::soovv_sound_LOCATED_;
      return;
    }
    Runtime.PPCEABI.H::__ptmf_scall(&local_18,this_00,puVar1);
    return;
  case 0x3c:
    local_18.this_delta = _1691;
    local_18.vtbl_offset = DAT_803973dc;
    local_18.func = DAT_803973e0;
    Runtime.PPCEABI.H::__ptmf_scall(&local_18,this_00,puVar1);
    return;
  case 0x3d:
    uVar2 = 6;
    break;
  case 0x3e:
    uVar2 = 7;
    break;
  case 0x3f:
    uVar2 = 8;
    break;
  case 0x40:
    uVar2 = 9;
    break;
  case 0x41:
    uVar2 = 10;
    break;
  default:
    goto switchD_802705f4_caseD_2d;
  }
  TAdaptor::adaptor_setVariableValue
            (this_00,(TObject *)this,uVar2,(TEOperationData)puVar1,param_2,param_3);
switchD_802705f4_caseD_2d:
  return;
}


/* __thiscall TObject_sound::~TObject_sound(void) */

void __thiscall TObject_sound::_TObject_sound(TObject_sound *this)

{
  short in_r4;
  
  if (this != (TObject_sound *)0x0) {
    *(undefined1 **)(this + 8) = &__vt;
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_particle::~TObject_particle(void) */

void __thiscall TObject_particle::_TObject_particle(TObject_particle *this)

{
  short in_r4;
  
  if (this != (TObject_particle *)0x0) {
    *(undefined1 **)(this + 8) = &__vt;
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_message::~TObject_message(void) */

void __thiscall TObject_message::_TObject_message(TObject_message *this)

{
  short in_r4;
  
  if (this != (TObject_message *)0x0) {
    *(undefined1 **)(this + 8) = &__vt;
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_light::~TObject_light(void) */

void __thiscall TObject_light::_TObject_light(TObject_light *this)

{
  short in_r4;
  
  if (this != (TObject_light *)0x0) {
    *(undefined1 **)(this + 8) = &__vt;
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_fog::~TObject_fog(void) */

void __thiscall TObject_fog::_TObject_fog(TObject_fog *this)

{
  short in_r4;
  
  if (this != (TObject_fog *)0x0) {
    *(undefined1 **)(this + 8) = &__vt;
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_camera::~TObject_camera(void) */

void __thiscall TObject_camera::_TObject_camera(TObject_camera *this)

{
  short in_r4;
  
  if (this != (TObject_camera *)0x0) {
    *(undefined1 **)(this + 8) = &__vt;
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_ambientLight::~TObject_ambientLight(void) */

void __thiscall TObject_ambientLight::_TObject_ambientLight(TObject_ambientLight *this)

{
  short in_r4;
  
  if (this != (TObject_ambientLight *)0x0) {
    *(undefined1 **)(this + 8) = &__vt;
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TObject_actor::~TObject_actor(void) */

void __thiscall TObject_actor::_TObject_actor(TObject_actor *this)

{
  short in_r4;
  
  if (this != (TObject_actor *)0x0) {
    *(undefined1 **)(this + 8) = &__vt;
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_jstudio_object_cpp(void)

{
  _soovv_actor_PARENT_ENABLE_ =
       &@unnamed@jstudio_object_cpp@::TOutputVariableValue_BOOL_<TAdaptor_actor>::__vt;
  DAT_803e8800 = _730;
  DAT_803e8804 = DAT_80396ee4;
  DAT_803e8808 = DAT_80396ee8;
  Runtime.PPCEABI.H::__register_global_object
            (&@unnamed@jstudio_object_cpp@::soovv_actor_PARENT_ENABLE_,
             @unnamed@jstudio_object_cpp@::TOutputVariableValue_BOOL_<TAdaptor_actor>::
             _TOutputVariableValue_BOOL_,&_732);
  _soovv_actor_RELATION_ENABLE_ =
       &@unnamed@jstudio_object_cpp@::TOutputVariableValue_BOOL_<TAdaptor_actor>::__vt;
  DAT_803e881c = _733;
  DAT_803e8820 = DAT_80396ef0;
  DAT_803e8824 = DAT_80396ef4;
  Runtime.PPCEABI.H::__register_global_object
            (&@unnamed@jstudio_object_cpp@::soovv_actor_RELATION_ENABLE_,
             @unnamed@jstudio_object_cpp@::TOutputVariableValue_BOOL_<TAdaptor_actor>::
             _TOutputVariableValue_BOOL_,&_735);
  _soovv_camera_PARENT_ENABLE_ =
       &@unnamed@jstudio_object_cpp@::TOutputVariableValue_BOOL_<TAdaptor_camera>::__vt;
  DAT_803e8838 = _736;
  DAT_803e883c = DAT_80396efc;
  DAT_803e8840 = DAT_80396f00;
  Runtime.PPCEABI.H::__register_global_object
            (&@unnamed@jstudio_object_cpp@::soovv_camera_PARENT_ENABLE_,
             @unnamed@jstudio_object_cpp@::TOutputVariableValue_BOOL_<TAdaptor_camera>::
             _TOutputVariableValue_BOOL_,&_738);
  _soovv_light_ENABLE_ =
       &@unnamed@jstudio_object_cpp@::TOutputVariableValue_BOOL_<TAdaptor_light>::__vt;
  DAT_803e8854 = _739;
  DAT_803e8858 = DAT_80396f08;
  DAT_803e885c = DAT_80396f0c;
  Runtime.PPCEABI.H::__register_global_object
            (&@unnamed@jstudio_object_cpp@::soovv_light_ENABLE_,
             @unnamed@jstudio_object_cpp@::TOutputVariableValue_BOOL_<TAdaptor_light>::
             _TOutputVariableValue_BOOL_,&_741);
  _soovv_particle_PARENT_ENABLE_ =
       &@unnamed@jstudio_object_cpp@::TOutputVariableValue_BOOL_<TAdaptor_particle>::__vt;
  DAT_803e8870 = _742;
  DAT_803e8874 = DAT_80396f14;
  DAT_803e8878 = DAT_80396f18;
  Runtime.PPCEABI.H::__register_global_object
            (&@unnamed@jstudio_object_cpp@::soovv_particle_PARENT_ENABLE_,
             @unnamed@jstudio_object_cpp@::TOutputVariableValue_BOOL_<TAdaptor_particle>::
             _TOutputVariableValue_BOOL_,&_744);
  _soovv_sound_LOCATED_ =
       &@unnamed@jstudio_object_cpp@::TOutputVariableValue_BOOL_<TAdaptor_sound>::__vt;
  DAT_803e888c = _745;
  DAT_803e8890 = DAT_80396f20;
  DAT_803e8894 = DAT_80396f24;
  Runtime.PPCEABI.H::__register_global_object
            (&@unnamed@jstudio_object_cpp@::soovv_sound_LOCATED_,
             @unnamed@jstudio_object_cpp@::TOutputVariableValue_BOOL_<TAdaptor_sound>::
             _TOutputVariableValue_BOOL_,&_747);
  _soOutput_none_ = &TVariableValue::TOutput_none_::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&TVariableValue::soOutput_none_,TVariableValue::TOutput_none_::_TOutput_none_,&_786);
  return;
}


namespace @unnamed@jstudio_object_cpp@ {

/* __thiscall
   TOutputVariableValue_BOOL_<JStudio::TAdaptor_sound>::~TOutputVariableValue_BOOL_(void)
    */

TOutputVariableValue_BOOL__JStudio__TAdaptor_sound_ * __thiscall
TOutputVariableValue_BOOL_<JStudio::TAdaptor_sound>::
_TOutputVariableValue_BOOL_(TOutputVariableValue_BOOL__JStudio__TAdaptor_sound_ *this)

{
  short in_r4;
  
  if (this != (TOutputVariableValue_BOOL__JStudio__TAdaptor_sound_ *)0x0) {
    *(undefined1 **)this = &__vt;
    TVariableValue::TOutput::_TOutput((TOutput *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return this;
}


/* __thiscall
   TOutputVariableValue_BOOL_<JStudio::TAdaptor_particle>::~TOutputVariableValue_BOOL_(void)
    */

TOutputVariableValue_BOOL__JStudio__TAdaptor_particle_ * __thiscall
TOutputVariableValue_BOOL_<JStudio::TAdaptor_particle>::
_TOutputVariableValue_BOOL_(TOutputVariableValue_BOOL__JStudio__TAdaptor_particle_ *this)

{
  short in_r4;
  
  if (this != (TOutputVariableValue_BOOL__JStudio__TAdaptor_particle_ *)0x0) {
    *(undefined1 **)this = &__vt;
    TVariableValue::TOutput::_TOutput((TOutput *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return this;
}


/* __thiscall
   TOutputVariableValue_BOOL_<JStudio::TAdaptor_light>::~TOutputVariableValue_BOOL_(void)
    */

TOutputVariableValue_BOOL__JStudio__TAdaptor_light_ * __thiscall
TOutputVariableValue_BOOL_<JStudio::TAdaptor_light>::
_TOutputVariableValue_BOOL_(TOutputVariableValue_BOOL__JStudio__TAdaptor_light_ *this)

{
  short in_r4;
  
  if (this != (TOutputVariableValue_BOOL__JStudio__TAdaptor_light_ *)0x0) {
    *(undefined1 **)this = &__vt;
    TVariableValue::TOutput::_TOutput((TOutput *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return this;
}


/* __thiscall
   TOutputVariableValue_BOOL_<JStudio::TAdaptor_camera>::~TOutputVariableValue_BOOL_(void)
    */

TOutputVariableValue_BOOL__JStudio__TAdaptor_camera_ * __thiscall
TOutputVariableValue_BOOL_<JStudio::TAdaptor_camera>::
_TOutputVariableValue_BOOL_(TOutputVariableValue_BOOL__JStudio__TAdaptor_camera_ *this)

{
  short in_r4;
  
  if (this != (TOutputVariableValue_BOOL__JStudio__TAdaptor_camera_ *)0x0) {
    *(undefined1 **)this = &__vt;
    TVariableValue::TOutput::_TOutput((TOutput *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return this;
}


/* __thiscall
   TOutputVariableValue_BOOL_<JStudio::TAdaptor_actor>::~TOutputVariableValue_BOOL_(void)
    */

TOutputVariableValue_BOOL__JStudio__TAdaptor_actor_ * __thiscall
TOutputVariableValue_BOOL_<JStudio::TAdaptor_actor>::
_TOutputVariableValue_BOOL_(TOutputVariableValue_BOOL__JStudio__TAdaptor_actor_ *this)

{
  short in_r4;
  
  if (this != (TOutputVariableValue_BOOL__JStudio__TAdaptor_actor_ *)0x0) {
    *(undefined1 **)this = &__vt;
    TVariableValue::TOutput::_TOutput((TOutput *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return this;
}


/* __thiscall
   TOutputVariableValue_BOOL_<JStudio::TAdaptor_sound>::operator
   ()(float,
   
   JStudio::TAdaptor *) const */

void __thiscall
TOutputVariableValue_BOOL_<JStudio::TAdaptor_sound>::
operator___(TOutputVariableValue_BOOL__JStudio__TAdaptor_sound_ *this,float param_1,
           TAdaptor *param_2)

{
  Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 4),param_2,&DAT_00000002);
  return;
}


/* __thiscall
   TOutputVariableValue_BOOL_<JStudio::TAdaptor_particle>::operator
   ()(float,
   
   JStudio::TAdaptor *) const */

void __thiscall
TOutputVariableValue_BOOL_<JStudio::TAdaptor_particle>::
operator___(TOutputVariableValue_BOOL__JStudio__TAdaptor_particle_ *this,float param_1,
           TAdaptor *param_2)

{
  Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 4),param_2,&DAT_00000002);
  return;
}


/* __thiscall
   TOutputVariableValue_BOOL_<JStudio::TAdaptor_light>::operator
   ()(float,
   
   JStudio::TAdaptor *) const */

void __thiscall
TOutputVariableValue_BOOL_<JStudio::TAdaptor_light>::
operator___(TOutputVariableValue_BOOL__JStudio__TAdaptor_light_ *this,float param_1,
           TAdaptor *param_2)

{
  Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 4),param_2,&DAT_00000002);
  return;
}


/* __thiscall
   TOutputVariableValue_BOOL_<JStudio::TAdaptor_camera>::operator
   ()(float,
   
   JStudio::TAdaptor *) const */

void __thiscall
TOutputVariableValue_BOOL_<JStudio::TAdaptor_camera>::
operator___(TOutputVariableValue_BOOL__JStudio__TAdaptor_camera_ *this,float param_1,
           TAdaptor *param_2)

{
  Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 4),param_2,&DAT_00000002);
  return;
}


/* __thiscall
   TOutputVariableValue_BOOL_<JStudio::TAdaptor_actor>::operator
   ()(float,
   
   JStudio::TAdaptor *) const */

void __thiscall
TOutputVariableValue_BOOL_<JStudio::TAdaptor_actor>::
operator___(TOutputVariableValue_BOOL__JStudio__TAdaptor_actor_ *this,float param_1,
           TAdaptor *param_2)

{
  Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 4),param_2,&DAT_00000002);
  return;
}

