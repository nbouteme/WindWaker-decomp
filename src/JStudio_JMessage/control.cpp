#include <JStudio_JMessage/control.h>
#include <JKernel/JKRHeap.h>
#include <JStudio_JMessage/object-message.h>
#include <JStudio/jstudio-object.h>
#include <JStudio/jstudio-control.h>
#include <JStudio_JMessage/control.h>
#include <Demangler/JStudio_JMessage/@unnamed@control_cpp@.h>
#include <Demangler/JStudio_JMessage/TCreateObject.h>
#include <JStudio_JMessage/TCreateObject_base.h>


namespace JStudio_JMessage {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall
   @unnamed@control_cpp@::createObject_MESSAGE_JMS_(JStudio::stb::data::TParse_TBlock_object
   const &,
                                                                                 JMessage::TControl
   *) */

TObject_message * __thiscall
@unnamed@control_cpp@::createObject_MESSAGE_JMS_
          (_unnamed_control_cpp_ *this,TParse_TBlock_object *param_1,TControl *param_2)

{
  TAdaptor_message *this_00;
  TObject_message *this_01;
  int *piVar1;
  
  this_00 = (TAdaptor_message *)JKernel::operator_new(0x10);
  if (this_00 != (TAdaptor_message *)0x0) {
    TAdaptor_message::TAdaptor_message(this_00,(TControl *)param_1);
  }
  if (this_00 == (TAdaptor_message *)0x0) {
    this_01 = (TObject_message *)0x0;
  }
  else {
    this_01 = (TObject_message *)JKernel::operator_new(0x38);
    if (this_01 != (TObject_message *)0x0) {
      JStudio::TObject_message::TObject_message
                (this_01,(TParse_TBlock_object *)this,(TAdaptor_message *)this_00);
    }
    if (this_01 == (TObject_message *)0x0) {
      this_01 = (TObject_message *)0x0;
    }
    else {
      piVar1 = *(int **)(this_01 + 0x34);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0xc))(piVar1,this_01);
      }
    }
  }
  return this_01;
}


/* __thiscall TCreateObject_base::~TCreateObject_base(void) */

void __thiscall TCreateObject_base::_TCreateObject_base(TCreateObject_base *this)

{
  short in_r4;
  
  if (this != (TCreateObject_base *)0x0) {
    *(undefined1 **)this = &__vt;
    JStudio::TCreateObject::_TCreateObject((TCreateObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TCreateObject_base::create(JStudio::TObject * *,
                                                           JStudio::stb::data::TParse_TBlock_object
   const &) */

undefined4 __thiscall
TCreateObject_base::create
          (TCreateObject_base *this,TObject **param_1,TParse_TBlock_object *param_2)

{
  undefined4 uVar1;
  TParse_TBlock_object *pTVar2;
  TObject *pTVar3;
  TControl *pTVar4;
  
  pTVar4 = *(TControl **)(*(int *)param_2 + 4);
  if (pTVar4 == (TControl *)0x4a4d5347) {
    pTVar2 = (TParse_TBlock_object *)(**(code **)(*(int *)this + 0x10))(this,param_2);
    if (pTVar2 == (TParse_TBlock_object *)0x0) {
      uVar1 = 0;
    }
    else {
      pTVar3 = (TObject *)
               @unnamed@control_cpp@::createObject_MESSAGE_JMS_
                         ((_unnamed_control_cpp_ *)param_2,pTVar2,pTVar4);
      *param_1 = pTVar3;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall TCreateObject::~TCreateObject(void) */

void __thiscall TCreateObject::_TCreateObject(TCreateObject *this)

{
  short in_r4;
  
  if (this != (TCreateObject *)0x0) {
    *(undefined1 **)this = &__vt;
    TCreateObject_base::_TCreateObject_base((TCreateObject_base *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TCreateObject::find(JStudio::stb::data::TParse_TBlock_object const
   &) */

undefined4 __thiscall
TCreateObject::find(TCreateObject *this,TParse_TBlock_object *param_1)

{
  return *(undefined4 *)(this + 0xc);
}

