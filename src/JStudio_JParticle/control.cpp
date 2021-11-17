#include <JStudio_JParticle/control.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <JStudio_JParticle/object-particle.h>
#include <JStudio/jstudio-object.h>
#include <JStudio/jstudio-control.h>
#include <JStudio_JParticle/control.h>
#include <Demangler/JStudio_JParticle/@unnamed@control_cpp@.h>
#include <Demangler/JStudio_JParticle/TCreateObject.h>


namespace JStudio_JParticle {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall
   @unnamed@control_cpp@::createObject_PARTICLE_JPA_(JStudio::stb::data::TParse_TBlock_object
   const &,
                                                                                   JPAEmitterManager
   *,
                                                                                   JStage::TSystem
   const *) */

TObject_particle * __thiscall
@unnamed@control_cpp@::createObject_PARTICLE_JPA_
          (_unnamed_control_cpp_ *this,TParse_TBlock_object *param_1,JPAEmitterManager *param_2,
          TSystem *param_3)

{
  TAdaptor_particle *this_00;
  TObject_particle *this_01;
  int *piVar1;
  
  this_00 = (TAdaptor_particle *)JKernel::operator_new(0x1d0);
  if (this_00 != (TAdaptor_particle *)0x0) {
    TAdaptor_particle::TAdaptor_particle(this_00,(JPAEmitterManager *)param_1,(TSystem *)param_2);
  }
  if (this_00 == (TAdaptor_particle *)0x0) {
    this_01 = (TObject_particle *)0x0;
  }
  else {
    this_01 = (TObject_particle *)JKernel::operator_new(0x38);
    if (this_01 != (TObject_particle *)0x0) {
      JStudio::TObject_particle::TObject_particle
                (this_01,(TParse_TBlock_object *)this,(TAdaptor_particle *)this_00);
    }
    if (this_01 == (TObject_particle *)0x0) {
      this_01 = (TObject_particle *)0x0;
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
    *(undefined ***)this = &__vt;
    JStudio::TCreateObject::_TCreateObject((TCreateObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TCreateObject::create(JStudio::TObject * *,
                                                       JStudio::stb::data::TParse_TBlock_object
   const &) */

bool __thiscall
TCreateObject::create
          (TCreateObject *this,TObject **param_1,TParse_TBlock_object *param_2)

{
  bool bVar1;
  TObject *pTVar2;
  
  bVar1 = *(int *)(*(int *)param_2 + 4) == 0x4a505443;
  if (bVar1) {
    pTVar2 = (TObject *)
             @unnamed@control_cpp@::createObject_PARTICLE_JPA_
                       ((_unnamed_control_cpp_ *)param_2,*(TParse_TBlock_object **)(this + 0xc),
                        *(JPAEmitterManager **)(this + 0x10),(TSystem *)this);
    *param_1 = pTVar2;
  }
  return bVar1;
}

