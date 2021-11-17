#include <JSupport/JSUMemoryStream.h>
#include <JSUMemoryInputStream.h>


/* __thiscall JSUMemoryInputStream::setBuffer(void const *,
                                              long) */

void __thiscall
JSUMemoryInputStream::setBuffer(JSUMemoryInputStream *this,void *param_1,long param_2)

{
  *(void **)(this + 8) = param_1;
  *(long *)(this + 0xc) = param_2;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}


/* __thiscall JSUMemoryInputStream::readData(void *,
                                             long) */

int __thiscall JSUMemoryInputStream::readData(JSUMemoryInputStream *this,void *param_1,long param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x10);
  if (*(int *)(this + 0xc) < iVar1 + param_2) {
    param_2 = *(int *)(this + 0xc) - iVar1;
  }
  if (0 < param_2) {
    copy_bytes((byte *)param_1,(byte *)(*(int *)(this + 8) + iVar1),param_2);
    *(int *)(this + 0x10) = *(int *)(this + 0x10) + param_2;
  }
  return param_2;
}


/* __thiscall JSUMemoryInputStream::seekPos(long,
                                            JSUStreamSeekFrom) */

int __thiscall
JSUMemoryInputStream::seekPos(JSUMemoryInputStream *this,long param_1,JSUStreamSeekFrom param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x10);
  if (param_2 == 1) {
    *(int *)(this + 0x10) = iVar1 + param_1;
  }
  else {
    if ((int)param_2 < 1) {
      if (-1 < (int)param_2) {
        *(long *)(this + 0x10) = param_1;
      }
    }
    else {
      if ((int)param_2 < 3) {
        *(int *)(this + 0x10) = *(int *)(this + 0xc) - param_1;
      }
    }
  }
  if (*(int *)(this + 0x10) < 0) {
    *(undefined4 *)(this + 0x10) = 0;
  }
  if (*(int *)(this + 0xc) < *(int *)(this + 0x10)) {
    *(int *)(this + 0x10) = *(int *)(this + 0xc);
  }
  return *(int *)(this + 0x10) - iVar1;
}


/* __thiscall JSUMemoryInputStream::getLength(void) const */

undefined4 __thiscall JSUMemoryInputStream::getLength(JSUMemoryInputStream *this)

{
  return *(undefined4 *)(this + 0xc);
}


/* __thiscall JSUMemoryInputStream::getPosition(void) const */

undefined4 __thiscall JSUMemoryInputStream::getPosition(JSUMemoryInputStream *this)

{
  return *(undefined4 *)(this + 0x10);
}

