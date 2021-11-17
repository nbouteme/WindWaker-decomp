#include <JStage/JSGFog.h>
#include <JStage/JSGObject.h>
#include <JKernel/JKRHeap.h>
#include <JStage/TFog.h>


namespace JStage {

/* __thiscall TFog::~TFog(void) */

void __thiscall TFog::_TFog(TFog *this)

{
  short in_r4;
  
  if (this != (TFog *)0x0) {
    *(undefined1 **)this = &__vt;
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TFog::JSGFGetType(void) const */

undefined4 __thiscall TFog::JSGFGetType(TFog *this)

{
  return 6;
}


/* __thiscall TFog::JSGGetFogFunction(void) const */

undefined4 __thiscall TFog::JSGGetFogFunction(TFog *this)

{
  return 0;
}


/* __thiscall TFog::JSGSetFogFunction(_GXFogType) */

void __thiscall TFog::JSGSetFogFunction(TFog *this,_GXFogType param_1)

{
  return;
}


/* __thiscall TFog::JSGGetStartZ(void) const */

double __thiscall TFog::JSGGetStartZ(TFog *this)

{
  return (double)_318;
}


/* __thiscall TFog::JSGSetStartZ(float) */

double __thiscall TFog::JSGSetStartZ(TFog *this,float param_1)

{
  return (double)param_1;
}


/* __thiscall TFog::JSGGetEndZ(void) const */

double __thiscall TFog::JSGGetEndZ(TFog *this)

{
  return (double)_327;
}


/* __thiscall TFog::JSGSetEndZ(float) */

double __thiscall TFog::JSGSetEndZ(TFog *this,float param_1)

{
  return (double)param_1;
}


/* __thiscall TFog::JSGGetColor(void) const */

void __thiscall TFog::JSGGetColor(TFog *this)

{
  return;
}


/* __thiscall TFog::JSGSetColor(_GXColor) */

void __thiscall TFog::JSGSetColor(TFog *this,_GXColor *param_1)

{
  return;
}

