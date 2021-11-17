#include <JStage/JSGCamera.h>
#include <JStage/JSGObject.h>
#include <JKernel/JKRHeap.h>
#include <JStage/TCamera.h>


namespace JStage {

/* __thiscall TCamera::~TCamera(void) */

void __thiscall TCamera::_TCamera(TCamera *this)

{
  short in_r4;
  
  if (this != (TCamera *)0x0) {
    this->vtbl = &__vt;
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TCamera::JSGFGetType(void) const */

undefined4 __thiscall TCamera::JSGFGetType(TCamera *this)

{
  return 3;
}


/* __thiscall TCamera::JSGGetProjectionType(void) const */

undefined4 __thiscall TCamera::JSGGetProjectionType(TCamera *this)

{
  return 1;
}


/* __thiscall TCamera::JSGSetProjectionType(TECameraProjection) */

void __thiscall TCamera::JSGSetProjectionType(TCamera *this,TECameraProjection param_1)

{
  return;
}


/* __thiscall TCamera::JSGGetProjectionNear(void) const */

double __thiscall TCamera::JSGGetProjectionNear(TCamera *this)

{
  return (double)_318;
}


/* __thiscall TCamera::JSGSetProjectionNear(float) */

double __thiscall TCamera::JSGSetProjectionNear(TCamera *this,float param_1)

{
  return (double)param_1;
}


/* __thiscall TCamera::JSGGetProjectionFar(void) const */

double __thiscall TCamera::JSGGetProjectionFar(TCamera *this)

{
  return (double)_327;
}


/* __thiscall TCamera::JSGSetProjectionFar(float) */

double __thiscall TCamera::JSGSetProjectionFar(TCamera *this,float param_1)

{
  return (double)param_1;
}


/* __thiscall TCamera::JSGGetProjectionFovy(void) const */

double __thiscall TCamera::JSGGetProjectionFovy(TCamera *this)

{
  return (double)_318;
}


/* __thiscall TCamera::JSGSetProjectionFovy(float) */

double __thiscall TCamera::JSGSetProjectionFovy(TCamera *this,float param_1)

{
  return (double)param_1;
}


/* __thiscall TCamera::JSGGetProjectionAspect(void) const */

double __thiscall TCamera::JSGGetProjectionAspect(TCamera *this)

{
  return (double)_318;
}


/* __thiscall TCamera::JSGSetProjectionAspect(float) */

double __thiscall TCamera::JSGSetProjectionAspect(TCamera *this,float param_1)

{
  return (double)param_1;
}


/* __thiscall TCamera::JSGGetProjectionField(float *) const */

void __thiscall TCamera::JSGGetProjectionField(TCamera *this,float *param_1)

{
  return;
}


/* __thiscall TCamera::JSGSetProjectionField(float const *) */

void __thiscall TCamera::JSGSetProjectionField(TCamera *this,float *param_1)

{
  return;
}


/* __thiscall TCamera::JSGGetViewType(void) const */

undefined4 __thiscall TCamera::JSGGetViewType(TCamera *this)

{
  return 1;
}


/* __thiscall TCamera::JSGSetViewType(TECameraView) */

void __thiscall TCamera::JSGSetViewType(TCamera *this,TECameraView param_1)

{
  return;
}


/* __thiscall TCamera::JSGGetViewPosition(Vec *) const */

void __thiscall TCamera::JSGGetViewPosition(TCamera *this,Vec *param_1)

{
  return;
}


/* __thiscall TCamera::JSGSetViewPosition(Vec const &) */

void __thiscall TCamera::JSGSetViewPosition(TCamera *this,Vec *param_1)

{
  return;
}


/* __thiscall TCamera::JSGGetViewUpVector(Vec *) const */

void __thiscall TCamera::JSGGetViewUpVector(TCamera *this,Vec *param_1)

{
  return;
}


/* __thiscall TCamera::JSGSetViewUpVector(Vec const &) */

void __thiscall TCamera::JSGSetViewUpVector(TCamera *this,Vec *param_1)

{
  return;
}


/* __thiscall TCamera::JSGGetViewTargetPosition(Vec *) const */

void __thiscall TCamera::JSGGetViewTargetPosition(TCamera *this,Vec *param_1)

{
  return;
}


/* __thiscall TCamera::JSGSetViewTargetPosition(Vec const &) */

void __thiscall TCamera::JSGSetViewTargetPosition(TCamera *this,Vec *param_1)

{
  return;
}


/* __thiscall TCamera::JSGGetViewRoll(void) const */

double __thiscall TCamera::JSGGetViewRoll(TCamera *this)

{
  return (double)_318;
}


/* __thiscall TCamera::JSGSetViewRoll(float) */

double __thiscall TCamera::JSGSetViewRoll(TCamera *this,float param_1)

{
  return (double)param_1;
}

