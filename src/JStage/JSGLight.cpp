#include <JStage/JSGLight.h>
#include <JStage/JSGObject.h>
#include <JKernel/JKRHeap.h>
#include <JStage/TLight.h>


namespace JStage {

/* __thiscall TLight::~TLight(void) */

void __thiscall TLight::_TLight(TLight *this)

{
  short in_r4;
  
  if (this != (TLight *)0x0) {
    (this->parent).vtbl = &__vt;
    TObject::_TObject(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TLight::JSGFGetType(void) const */

undefined4 __thiscall TLight::JSGFGetType(TLight *this)

{
  return 5;
}


/* __thiscall TLight::JSGGetLightType(void) const */

undefined4 __thiscall TLight::JSGGetLightType(TLight *this)

{
  return 1;
}


/* __thiscall TLight::JSGSetLightType(TELight) */

void __thiscall TLight::JSGSetLightType(TLight *this,TELight param_1)

{
  return;
}


/* __thiscall TLight::JSGGetColor(void) const */

void __thiscall TLight::JSGGetColor(TLight *this)

{
  return;
}


/* __thiscall TLight::JSGSetColor(_GXColor) */

void __thiscall TLight::JSGSetColor(TLight *this,_GXColor *param_1)

{
  return;
}


/* __thiscall TLight::JSGGetDistanceAttenuation(float *,
                                                        float *,
                                                        _GXDistAttnFn *) const */

void __thiscall
TLight::JSGGetDistanceAttenuation
          (TLight *this,float *param_1,float *param_2,undefined param_3)

{
  return;
}


/* __thiscall TLight::JSGSetDistanceAttenuation(float,
                                                        float,
                                                        _GXDistAttnFn) */

double __thiscall
TLight::JSGSetDistanceAttenuation
          (TLight *this,float param_1,float param_2,undefined param_3)

{
  return (double)param_1;
}


/* __thiscall TLight::JSGGetAngleAttenuation(float *,
                                                     _GXSpotFn *) const */

void __thiscall
TLight::JSGGetAngleAttenuation(TLight *this,float *param_1,undefined param_2)

{
  return;
}


/* __thiscall TLight::JSGSetAngleAttenuation(float,
                                                     _GXSpotFn) */

double __thiscall
TLight::JSGSetAngleAttenuation(TLight *this,float param_1,undefined param_2)

{
  return (double)param_1;
}


/* __thiscall TLight::JSGGetPosition(Vec *) const */

void __thiscall TLight::JSGGetPosition(TLight *this,Vec *param_1)

{
  return;
}


/* __thiscall TLight::JSGSetPosition(Vec const &) */

void __thiscall TLight::JSGSetPosition(TLight *this,Vec *param_1)

{
  return;
}


/* __thiscall TLight::JSGGetDirection(Vec *) const */

void __thiscall TLight::JSGGetDirection(TLight *this,Vec *param_1)

{
  return;
}


/* __thiscall TLight::JSGSetDirection(Vec const &) */

void __thiscall TLight::JSGSetDirection(TLight *this,Vec *param_1)

{
  return;
}

