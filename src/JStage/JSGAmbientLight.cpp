#include <JStage/JSGAmbientLight.h>
#include <JStage/JSGObject.h>
#include <JKernel/JKRHeap.h>
#include <JStage/TAmbientLight.h>


namespace JStage {

/* __thiscall TAmbientLight::~TAmbientLight(void) */

void __thiscall TAmbientLight::_TAmbientLight(TAmbientLight *this)

{
  short in_r4;
  
  if (this != (TAmbientLight *)0x0) {
    *(undefined1 **)this = &__vt;
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TAmbientLight::JSGFGetType(void) const */

undefined4 __thiscall TAmbientLight::JSGFGetType(TAmbientLight *this)

{
  return 4;
}


/* __thiscall TAmbientLight::JSGGetColor(void) const */

void __thiscall TAmbientLight::JSGGetColor(TAmbientLight *this)

{
  return;
}


/* __thiscall TAmbientLight::JSGSetColor(_GXColor) */

void __thiscall TAmbientLight::JSGSetColor(TAmbientLight *this,_GXColor *param_1)

{
  return;
}

