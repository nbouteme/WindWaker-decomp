#include <JStage/JSGObject.h>
#include <JKernel/JKRHeap.h>
#include <JStage/TObject.h>


namespace JStage {

/* __thiscall TObject::~TObject(void) */

void __thiscall TObject::_TObject(TObject *this)

{
  short in_r4;
  
  if ((this != (TObject *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall TObject::JSGGetName(void) const */

undefined4 __thiscall TObject::JSGGetName(TObject *this)

{
  return 0;
}


/* __thiscall TObject::JSGGetFlag(void) const */

undefined4 __thiscall TObject::JSGGetFlag(TObject *this)

{
  return 0;
}


/* __thiscall TObject::JSGSetFlag(unsigned long) */

void __thiscall TObject::JSGSetFlag(TObject *this,ulong param_1)

{
  return;
}


/* __thiscall TObject::JSGGetData(unsigned long,
                                          void *,
                                          unsigned long) const */

undefined4 __thiscall
TObject::JSGGetData(TObject *this,ulong param_1,void *param_2,ulong param_3)

{
  return 0;
}


/* __thiscall TObject::JSGSetData(unsigned long,
                                          void const *,
                                          unsigned long) */

void __thiscall TObject::JSGSetData(TObject *this,ulong param_1,void *param_2,ulong param_3)

{
  return;
}


/* __thiscall TObject::JSGGetParent(TObject * *,
                                            unsigned long *) const */

void __thiscall TObject::JSGGetParent(TObject *this,TObject **param_1,ulong *param_2)

{
  return;
}


/* __thiscall TObject::JSGSetParent(TObject *,
                                            unsigned long) */

void __thiscall TObject::JSGSetParent(TObject *this,TObject *param_1,ulong param_2)

{
  return;
}


/* __thiscall TObject::JSGSetRelation(bool,
                                              TObject *,
                                              unsigned long) */

void __thiscall
TObject::JSGSetRelation(TObject *this,bool param_1,TObject *param_2,ulong param_3)

{
  return;
}


/* __thiscall TObject::JSGFindNodeID(char const *) const */

undefined4 __thiscall TObject::JSGFindNodeID(TObject *this,char *param_1)

{
  return 0xffffffff;
}


/* __thiscall TObject::JSGGetNodeTransformation(unsigned long,
                                                        float *[][][][]) const */

undefined4 __thiscall
TObject::JSGGetNodeTransformation(TObject *this,ulong param_1,float *param_2)

{
  float fVar1;
  
  fVar1 = _333;
  *param_2 = _333;
  param_2[1] = fVar1;
  param_2[2] = fVar1;
  param_2[3] = fVar1;
  param_2[4] = fVar1;
  param_2[5] = fVar1;
  param_2[6] = fVar1;
  param_2[7] = fVar1;
  param_2[8] = fVar1;
  param_2[9] = fVar1;
  param_2[10] = fVar1;
  param_2[0xb] = fVar1;
  return 0;
}

