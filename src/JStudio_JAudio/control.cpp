#include <JStudio_JAudio/control.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <JStudio_JAudio/object-sound.h>
#include <JStudio/jstudio-object.h>
#include <JStudio/jstudio-control.h>
#include <JStudio_JAudio/control.h>
#include <Demangler/JStudio_JAudio/@unnamed@control_cpp@.h>
#include <Demangler/JStudio_JAudio/TCreateObject.h>


namespace JStudio_JAudio {

namespace TCreateObject {
}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall
   @unnamed@control_cpp@::createObject_SOUND_JAI_(JStudio::stb::data::TParse_TBlock_object
   const &,
                                                                             JAIBasic *) */

TObject_sound * __thiscall
@unnamed@control_cpp@::createObject_SOUND_JAI_
          (_unnamed_control_cpp_ *this,TParse_TBlock_object *param_1,JAIBasic *param_2)

{
  TAdaptor_sound *this_00;
  TObject_sound *this_01;
  int *piVar1;
  
  this_00 = (TAdaptor_sound *)JKernel::operator_new(0x104);
  if (this_00 != (TAdaptor_sound *)0x0) {
    TAdaptor_sound::TAdaptor_sound(this_00,(JAIBasic *)param_1);
  }
  if (this_00 == (TAdaptor_sound *)0x0) {
    this_01 = (TObject_sound *)0x0;
  }
  else {
    this_01 = (TObject_sound *)JKernel::operator_new(0x38);
    if (this_01 != (TObject_sound *)0x0) {
      JStudio::TObject_sound::TObject_sound
                (this_01,(TParse_TBlock_object *)this,(TAdaptor_sound *)this_00);
    }
    if (this_01 == (TObject_sound *)0x0) {
      this_01 = (TObject_sound *)0x0;
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


/* __thiscall TCreateObject::~TCreateObject(void) */

void __thiscall TCreateObject::_TCreateObject(TCreateObject *this)

{
  short in_r4;
  
  if (this != (TCreateObject *)0x0) {
    *(undefined1 **)this = &__vt;
    JStudio::TCreateObject::_TCreateObject((TCreateObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TCreateObject::create(JStudio::TObject * *,
                                                    JStudio::stb::data::TParse_TBlock_object const
   &) */

bool __thiscall
TCreateObject::create
          (TCreateObject *this,TObject **param_1,TParse_TBlock_object *param_2)

{
  bool bVar1;
  TObject *pTVar2;
  
  bVar1 = *(int *)(*(int *)param_2 + 4) == 0x4a534e44;
  if (bVar1) {
    pTVar2 = (TObject *)
             @unnamed@control_cpp@::createObject_SOUND_JAI_
                       ((_unnamed_control_cpp_ *)param_2,*(TParse_TBlock_object **)(this + 0xc),
                        (JAIBasic *)param_2);
    *param_1 = pTVar2;
  }
  return bVar1;
}

