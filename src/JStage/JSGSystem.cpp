#include <JStage/JSGSystem.h>
#include <JStage/JSGObject.h>
#include <JKernel/JKRHeap.h>
#include <JStage/TSystem.h>


namespace JStage {

/* __thiscall TSystem::~TSystem(void) */

void __thiscall TSystem::_TSystem(TSystem *this)

{
  short in_r4;
  
  if (this != (TSystem *)0x0) {
    *(undefined1 **)this = &__vt;
    TObject::_TObject((TObject *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TSystem::JSGFGetType(void) const */

undefined4 __thiscall TSystem::JSGFGetType(TSystem *this)

{
  return 1;
}


/* __thiscall TSystem::JSGFindObject(char const *,
                                             TEObject) const */

undefined4 __thiscall TSystem::JSGFindObject(TSystem *this,char *param_1,TEObject param_2)

{
  return 0;
}


/* __thiscall TSystem::JSGCreateObject(char const *,
                                               TEObject,
                                               unsigned long) */

undefined4 __thiscall
TSystem::JSGCreateObject(TSystem *this,char *param_1,TEObject param_2,ulong param_3)

{
  return 0;
}


/* __thiscall TSystem::JSGDestroyObject(TObject *) */

void __thiscall TSystem::JSGDestroyObject(TSystem *this,TObject *param_1)

{
  return;
}


/* __thiscall TSystem::JSGGetSystemData(unsigned long) */

undefined4 __thiscall TSystem::JSGGetSystemData(TSystem *this,ulong param_1)

{
  return 0;
}


/* __thiscall TSystem::JSGSetSystemData(unsigned long,
                                                unsigned long) */

void __thiscall TSystem::JSGSetSystemData(TSystem *this,ulong param_1,ulong param_2)

{
  return;
}

