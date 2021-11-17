#include <MSL_C.PPCEABI.bare.H/wchar_io.h>


namespace MSL_C.PPCEABI.bare.H {

/* WARNING: Removing unreachable block (ram,0x8032e3c8) */

int fwide(__FILE *__fp,int __mode)

{
  byte bVar1;
  byte bVar2;
  
  if ((__fp == (__FILE *)0x0) || ((*(ushort *)&__fp->_IO_read_ptr >> 6 & 7) == 0)) {
    return (int)(__FILE *)0x0;
  }
  bVar1 = *(byte *)((int)&__fp->_IO_read_ptr + 1);
  bVar2 = bVar1 >> 4 & 3;
  if (bVar2 == 1) {
    return (int)&DAT_ffffffff;
  }
  if (bVar2 != 0) {
    if (bVar2 < 3) {
      return (int)&DAT_00000001;
    }
    return (int)__fp;
  }
  if (__mode < 1) {
    if (__mode < 0) {
      *(byte *)((int)&__fp->_IO_read_ptr + 1) = bVar1 & 0xcf | 0x10;
    }
  }
  else {
    *(byte *)((int)&__fp->_IO_read_ptr + 1) = bVar1 & 0xcf | 0x20;
  }
  return (int)(__FILE *)__mode;
}

