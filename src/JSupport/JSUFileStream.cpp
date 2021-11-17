#include <JSupport/JSUFileStream.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <Demangler/JSUFileInputStream.h>


/* __thiscall JSUFileInputStream::JSUFileInputStream(JKRFile *) */

void __thiscall JSUFileInputStream::JSUFileInputStream(JSUFileInputStream *this,JKRFile *param_1)

{
  *(undefined1 **)this = &JSUIosBase::__vt;
  this[4] = (JSUFileInputStream)0x0;
  *(undefined1 **)this = &JSUInputStream::__vt;
  *(undefined1 **)this = &JSURandomInputStream::__vt;
  *(undefined1 **)this = &__vt;
  *(JKRFile **)(this + 8) = param_1;
  *(undefined4 *)(this + 0xc) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JSUFileInputStream::readData(void *,
                                           long) */

int __thiscall JSUFileInputStream::readData(JSUFileInputStream *this,void *param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (*(char *)(*(int **)(this + 8) + 6) != '\0') {
    uVar1 = (**(code **)(**(int **)(this + 8) + 0x1c))();
    if (uVar1 < (uint)(*(int *)(this + 0xc) + param_2)) {
      iVar2 = (**(code **)(**(int **)(this + 8) + 0x1c))();
      param_2 = iVar2 - *(int *)(this + 0xc);
    }
    if (0 < param_2) {
      iVar3 = (**(code **)(**(int **)(this + 8) + 0x14))
                        (*(int **)(this + 8),param_1,param_2,*(undefined4 *)(this + 0xc));
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      else {
        *(int *)(this + 0xc) = *(int *)(this + 0xc) + iVar3;
      }
    }
  }
  return iVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JSUFileInputStream::seekPos(long,
                                          JSUStreamSeekFrom) */

int __thiscall
JSUFileInputStream::seekPos(JSUFileInputStream *this,long param_1,JSUStreamSeekFrom param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(this + 0xc);
  if (param_2 == 1) {
    *(int *)(this + 0xc) = iVar3 + param_1;
  }
  else {
    if ((int)param_2 < 1) {
      if (-1 < (int)param_2) {
        *(long *)(this + 0xc) = param_1;
      }
    }
    else {
      if ((int)param_2 < 3) {
        iVar1 = (**(code **)(**(int **)(this + 8) + 0x1c))();
        *(int *)(this + 0xc) = iVar1 - param_1;
      }
    }
  }
  if (*(int *)(this + 0xc) < 0) {
    *(undefined4 *)(this + 0xc) = 0;
  }
  iVar1 = (**(code **)(**(int **)(this + 8) + 0x1c))();
  if (iVar1 < *(int *)(this + 0xc)) {
    uVar2 = (**(code **)(**(int **)(this + 8) + 0x1c))();
    *(undefined4 *)(this + 0xc) = uVar2;
  }
  return *(int *)(this + 0xc) - iVar3;
}


/* __thiscall JSUFileInputStream::getLength(void) const */

void __thiscall JSUFileInputStream::getLength(JSUFileInputStream *this)

{
  (**(code **)(**(int **)(this + 8) + 0x1c))();
  return;
}


/* __thiscall JSUFileInputStream::getPosition(void) const */

undefined4 __thiscall JSUFileInputStream::getPosition(JSUFileInputStream *this)

{
  return *(undefined4 *)(this + 0xc);
}

