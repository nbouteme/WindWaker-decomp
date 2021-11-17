#include <JStudio/object-id.h>
#include <JStudio/object/TIDData.h>


namespace JStudio {

namespace object {

/* __thiscall TIDData::isEqual(TIDData const &,
                                                TIDData const &) */

undefined4 __thiscall
TIDData::isEqual(TIDData *this,TIDData *param_1,TIDData *param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(this + 4);
  if (uVar3 != *(uint *)(param_1 + 4)) {
    return 0;
  }
  piVar1 = *(int **)this;
  piVar2 = *(int **)param_1;
  if (piVar1 == piVar2) {
    return 1;
  }
  uVar4 = uVar3 >> 2;
  if (3 < uVar3) {
    do {
      if (*piVar1 != *piVar2) {
        return 0;
      }
      uVar3 = uVar3 - 4;
      piVar1 = piVar1 + 1;
      piVar2 = piVar2 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  if (uVar3 != 2) {
    if ((int)uVar3 < 2) {
      if ((int)uVar3 < 1) {
        return 1;
      }
      goto LAB_80274bc8;
    }
    if (3 < (int)uVar3) {
      return 1;
    }
    if (*(char *)piVar1 != *(char *)piVar2) {
      return 0;
    }
    piVar1 = (int *)((int)piVar1 + 1);
    piVar2 = (int *)((int)piVar2 + 1);
  }
  if (*(char *)piVar1 != *(char *)piVar2) {
    return 0;
  }
  piVar1 = (int *)((int)piVar1 + 1);
  piVar2 = (int *)((int)piVar2 + 1);
LAB_80274bc8:
  if (*(char *)piVar1 == *(char *)piVar2) {
    return 1;
  }
  return 0;
}

