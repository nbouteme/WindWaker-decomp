#include <JStudio_JStage/control.h>
#include <JStudio/jstudio-control.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JStudio_JStage/control.h>
#include <JStudio_JStage/object-actor.h>
#include <JStudio/jstudio-object.h>
#include <JStudio_JStage/object-camera.h>
#include <JStudio_JStage/object-ambientlight.h>
#include <JStudio_JStage/object-light.h>
#include <JStudio_JStage/object-fog.h>
#include <Demangler/JStudio_JStage/TCreateObject.h>
#include <JStudio_JStage/@unnamed@control_cpp@.h>


namespace JStudio_JStage {

/* __thiscall TCreateObject::~TCreateObject(void) */

void __thiscall TCreateObject::_TCreateObject(TCreateObject *this)

{
  short in_r4;
  
  if (this != (TCreateObject *)0x0) {
    *(undefined ***)this = &__vt;
    JStudio::TCreateObject::_TCreateObject((TCreateObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TCreateObject::create(JStudio::TObject * *,
                                                    JStudio::stb::data::TParse_TBlock_object const
   &) */

bool __thiscall
TCreateObject::create
          (TCreateObject *this,TObject **param_1,TParse_TBlock_object *param_2)

{
  code *pcVar1;
  TObject *pTVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = *(int *)(*(int *)param_2 + 4);
  if (iVar3 == 0x4a434d52) {
    pcVar1 = @unnamed@control_cpp@::createObject_JSG_;
    uVar4 = 3;
  }
  else {
    if (iVar3 < 0x4a434d52) {
      if (iVar3 == 0x4a414354) {
        pcVar1 = @unnamed@control_cpp@::createObject_JSG_;
        uVar4 = 2;
      }
      else {
        if ((0x4a414353 < iVar3) || (iVar3 != 0x4a41424c)) {
          return false;
        }
        pcVar1 = @unnamed@control_cpp@::createObject_JSG_;
        uVar4 = 4;
      }
    }
    else {
      if (iVar3 == 0x4a4c4954) {
        pcVar1 = @unnamed@control_cpp@::createObject_JSG_;
        uVar4 = 5;
      }
      else {
        if (0x4a4c4953 < iVar3) {
          return false;
        }
        if (iVar3 != 0x4a464f47) {
          return false;
        }
        pcVar1 = @unnamed@control_cpp@::createObject_JSG_;
        uVar4 = 6;
      }
    }
  }
  iVar3 = (**(code **)(*(int *)this + 0x10))(this,param_2,uVar4);
  if (iVar3 != 0) {
    pTVar2 = (TObject *)(*pcVar1)(param_2,iVar3,*(undefined4 *)(this + 0xc));
    *param_1 = pTVar2;
  }
  return iVar3 != 0;
}


/* __thiscall TCreateObject::find(JStudio::stb::data::TParse_TBlock_object const &,
                                                  JStage::TEObject) */

int * __thiscall
TCreateObject::find
          (TCreateObject *this,TParse_TBlock_object *param_1,TEObject param_2)

{
  int *piVar1;
  TEObject TVar2;
  
  piVar1 = (int *)(**(code **)(**(int **)(this + 0xc) + 0x38))
                            (*(int **)(this + 0xc),*(int *)param_1 + 0xc);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    TVar2 = (**(code **)(*piVar1 + 0xc))();
    if (TVar2 != param_2) {
      piVar1 = (int *)0x0;
    }
  }
  return piVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall
   @unnamed@control_cpp@::createObject_JSG_<TAdaptor_actor,JStage::TActor>(JStudio::stb::data::TParse_TBlock_object
   const &,
   
   JStage::TObject *,
   
   JStage::TSystem const *) */

TObject_actor * __thiscall
@unnamed@control_cpp@::createObject_JSG_
          (_unnamed_control_cpp_ *this,TParse_TBlock_object *param_1,TObject *param_2,
          TSystem *param_3)

{
  TAdaptor_actor *this_00;
  TObject_actor *this_01;
  int *piVar1;
  
  this_00 = (TAdaptor_actor *)JKernel::operator_new(0x144);
  if (this_00 != (TAdaptor_actor *)0x0) {
    TAdaptor_actor::TAdaptor_actor(this_00,(TSystem *)param_2,(TActor *)param_1);
  }
  if (this_00 == (TAdaptor_actor *)0x0) {
    this_01 = (TObject_actor *)0x0;
  }
  else {
    this_01 = (TObject_actor *)JKernel::operator_new(0x38);
    if (this_01 != (TObject_actor *)0x0) {
      JStudio::TObject_actor::TObject_actor
                (this_01,(TParse_TBlock_object *)this,(TAdaptor_actor *)this_00);
    }
    if (this_01 == (TObject_actor *)0x0) {
      this_01 = (TObject_actor *)0x0;
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


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall
   @unnamed@control_cpp@::createObject_JSG_<TAdaptor_camera,JStage::TCamera>(JStudio::stb::data::TParse_TBlock_object
   const &,
   
   JStage::TObject *,
   
   JStage::TSystem const *) */

TObject_camera * __thiscall
@unnamed@control_cpp@::createObject_JSG_
          (_unnamed_control_cpp_ *this,TParse_TBlock_object *param_1,TObject *param_2,
          TSystem *param_3)

{
  TAdaptor_camera *this_00;
  TObject_camera *this_01;
  int *piVar1;
  
  this_00 = (TAdaptor_camera *)JKernel::operator_new(0xf8);
  if (this_00 != (TAdaptor_camera *)0x0) {
    TAdaptor_camera::TAdaptor_camera(this_00,(TSystem *)param_2,(TCamera *)param_1);
  }
  if (this_00 == (TAdaptor_camera *)0x0) {
    this_01 = (TObject_camera *)0x0;
  }
  else {
    this_01 = (TObject_camera *)JKernel::operator_new(0x38);
    if (this_01 != (TObject_camera *)0x0) {
      JStudio::TObject_camera::TObject_camera
                (this_01,(TParse_TBlock_object *)this,(TAdaptor_camera *)this_00);
    }
    if (this_01 == (TObject_camera *)0x0) {
      this_01 = (TObject_camera *)0x0;
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


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall
   @unnamed@control_cpp@::createObject_JSG_<TAdaptor_ambientLight,JStage::TAmbientLight>(JStudio::stb::data::TParse_TBlock_object
   const &,
   
   JStage::TObject *,
   
   JStage::TSystem const *) */

TObject_ambientLight * __thiscall
@unnamed@control_cpp@::createObject_JSG_
          (_unnamed_control_cpp_ *this,TParse_TBlock_object *param_1,TObject *param_2,
          TSystem *param_3)

{
  TAdaptor_ambientLight *this_00;
  TObject_ambientLight *this_01;
  int *piVar1;
  
  this_00 = (TAdaptor_ambientLight *)JKernel::operator_new(100);
  if (this_00 != (TAdaptor_ambientLight *)0x0) {
    TAdaptor_ambientLight::TAdaptor_ambientLight
              (this_00,(TSystem *)param_2,(TAmbientLight *)param_1);
  }
  if (this_00 == (TAdaptor_ambientLight *)0x0) {
    this_01 = (TObject_ambientLight *)0x0;
  }
  else {
    this_01 = (TObject_ambientLight *)JKernel::operator_new(0x38);
    if (this_01 != (TObject_ambientLight *)0x0) {
      JStudio::TObject_ambientLight::TObject_ambientLight
                (this_01,(TParse_TBlock_object *)this,(TAdaptor_ambientLight *)this_00);
    }
    if (this_01 == (TObject_ambientLight *)0x0) {
      this_01 = (TObject_ambientLight *)0x0;
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


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall
   @unnamed@control_cpp@::createObject_JSG_<TAdaptor_light,JStage::TLight>(JStudio::stb::data::TParse_TBlock_object
   const &,
   
   JStage::TObject *,
   
   JStage::TSystem const *) */

TObject_light * __thiscall
@unnamed@control_cpp@::createObject_JSG_
          (_unnamed_control_cpp_ *this,TParse_TBlock_object *param_1,TObject *param_2,
          TSystem *param_3)

{
  TAdaptor_light *this_00;
  TObject_light *this_01;
  int *piVar1;
  
  this_00 = (TAdaptor_light *)JKernel::operator_new(0x11c);
  if (this_00 != (TAdaptor_light *)0x0) {
    TAdaptor_light::TAdaptor_light(this_00,(TSystem *)param_2,(TLight *)param_1);
  }
  if (this_00 == (TAdaptor_light *)0x0) {
    this_01 = (TObject_light *)0x0;
  }
  else {
    this_01 = (TObject_light *)JKernel::operator_new(0x38);
    if (this_01 != (TObject_light *)0x0) {
      JStudio::TObject_light::TObject_light
                (this_01,(TParse_TBlock_object *)this,(TAdaptor_light *)this_00);
    }
    if (this_01 == (TObject_light *)0x0) {
      this_01 = (TObject_light *)0x0;
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


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall
   @unnamed@control_cpp@::createObject_JSG_<TAdaptor_fog,JStage::TFog>(JStudio::stb::data::TParse_TBlock_object
   const &,
   
   JStage::TObject *,
   
   JStage::TSystem const *) */

TObject_fog * __thiscall
@unnamed@control_cpp@::createObject_JSG_
          (_unnamed_control_cpp_ *this,TParse_TBlock_object *param_1,TObject *param_2,
          TSystem *param_3)

{
  TAdaptor_fog *this_00;
  TObject_fog *this_01;
  int *piVar1;
  
  this_00 = (TAdaptor_fog *)JKernel::operator_new(0x8c);
  if (this_00 != (TAdaptor_fog *)0x0) {
    TAdaptor_fog::TAdaptor_fog(this_00,(TSystem *)param_2,(TFog *)param_1);
  }
  if (this_00 == (TAdaptor_fog *)0x0) {
    this_01 = (TObject_fog *)0x0;
  }
  else {
    this_01 = (TObject_fog *)JKernel::operator_new(0x38);
    if (this_01 != (TObject_fog *)0x0) {
      JStudio::TObject_fog::TObject_fog
                (this_01,(TParse_TBlock_object *)this,(TAdaptor_fog *)this_00);
    }
    if (this_01 == (TObject_fog *)0x0) {
      this_01 = (TObject_fog *)0x0;
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

