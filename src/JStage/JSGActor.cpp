#include <JStage/JSGActor.h>
#include <JStage/JSGObject.h>
#include <JKernel/JKRHeap.h>
#include <JStage/TActor.h>


namespace JStage {

/* __thiscall TActor::~TActor(void) */

void __thiscall TActor::_TActor(TActor *this)

{
  short in_r4;
  
  if (this != (TActor *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    TObject::_TObject(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TActor::JSGFGetType(void) const */

undefined4 __thiscall TActor::JSGFGetType(TActor *this)

{
  return 2;
}


/* __thiscall TActor::JSGGetTranslation(Vec *) const */

void __thiscall TActor::JSGGetTranslation(TActor *this,Vec *param_1)

{
  return;
}


/* __thiscall TActor::JSGSetTranslation(Vec const &) */

void __thiscall TActor::JSGSetTranslation(TActor *this,Vec *param_1)

{
  return;
}


/* __thiscall TActor::JSGGetScaling(Vec *) const */

void __thiscall TActor::JSGGetScaling(TActor *this,Vec *param_1)

{
  return;
}


/* __thiscall TActor::JSGSetScaling(Vec const &) */

void __thiscall TActor::JSGSetScaling(TActor *this,Vec *param_1)

{
  return;
}


/* __thiscall TActor::JSGGetRotation(Vec *) const */

void __thiscall TActor::JSGGetRotation(TActor *this,Vec *param_1)

{
  return;
}


/* __thiscall TActor::JSGSetRotation(Vec const &) */

void __thiscall TActor::JSGSetRotation(TActor *this,Vec *param_1)

{
  return;
}


/* __thiscall TActor::JSGGetShape(void) const */

undefined4 __thiscall TActor::JSGGetShape(TActor *this)

{
  return 0xffffffff;
}


/* __thiscall TActor::JSGSetShape(unsigned long) */

void __thiscall TActor::JSGSetShape(TActor *this,ulong param_1)

{
  return;
}


/* __thiscall TActor::JSGGetAnimation(void) const */

undefined4 __thiscall TActor::JSGGetAnimation(TActor *this)

{
  return 0xffffffff;
}


/* __thiscall TActor::JSGSetAnimation(unsigned long) */

void __thiscall TActor::JSGSetAnimation(TActor *this,ulong param_1)

{
  return;
}


/* __thiscall TActor::JSGGetAnimationFrame(void) const */

double __thiscall TActor::JSGGetAnimationFrame(TActor *this)

{
  return (double)_342;
}


/* __thiscall TActor::JSGSetAnimationFrame(float) */

double __thiscall TActor::JSGSetAnimationFrame(TActor *this,float param_1)

{
  return (double)param_1;
}


/* __thiscall TActor::JSGGetAnimationFrameMax(void) const */

double __thiscall TActor::JSGGetAnimationFrameMax(TActor *this)

{
  return (double)_342;
}


/* __thiscall TActor::JSGGetAnimationTransition(void) const */

double __thiscall TActor::JSGGetAnimationTransition(TActor *this)

{
  return (double)_342;
}


/* __thiscall TActor::JSGSetAnimationTransition(float) */

double __thiscall TActor::JSGSetAnimationTransition(TActor *this,float param_1)

{
  return (double)param_1;
}


/* __thiscall TActor::JSGGetTextureAnimation(void) const */

undefined4 __thiscall TActor::JSGGetTextureAnimation(TActor *this)

{
  return 0xffffffff;
}


/* __thiscall TActor::JSGSetTextureAnimation(unsigned long) */

void __thiscall TActor::JSGSetTextureAnimation(TActor *this,ulong param_1)

{
  return;
}


/* __thiscall TActor::JSGGetTextureAnimationFrame(void) const */

double __thiscall TActor::JSGGetTextureAnimationFrame(TActor *this)

{
  return (double)_342;
}


/* __thiscall TActor::JSGSetTextureAnimationFrame(float) */

double __thiscall TActor::JSGSetTextureAnimationFrame(TActor *this,float param_1)

{
  return (double)param_1;
}


/* __thiscall TActor::JSGGetTextureAnimationFrameMax(void) const */

double __thiscall TActor::JSGGetTextureAnimationFrameMax(TActor *this)

{
  return (double)_342;
}

