#include <MSL_C.PPCEABI.bare.H/s_floor.h>


namespace MSL_C.PPCEABI.bare.H {

double floor(double __x)

{
  uint uVar1;
  uint uVar2;
  uint local_8;
  uint uStack4;
  
  local_8 = (uint)((ulonglong)__x >> 0x20);
  uStack4 = SUB84(__x,0);
  uVar1 = local_8 >> 0x14 & 0x7ff;
  uVar2 = uVar1 - 0x3ff;
  if ((int)uVar2 < 0x14) {
    if ((int)uVar2 < 0) {
      if (_126 < _125 + __x) {
        if ((longlong)__x < 0) {
          if ((local_8 & 0x7fffffff | uStack4) != 0) {
            __x = -1.0;
          }
        }
        else {
          __x = 0.0;
        }
      }
    }
    else {
      uVar1 = 0xfffff >> (uVar2 & 0x3f);
      if (((uStack4 | local_8 & uVar1) != 0) && (_126 < _125 + __x)) {
        if ((longlong)__x < 0) {
          local_8 = local_8 + (0x100000 >> (uVar2 & 0x3f));
        }
        __x = (double)((ulonglong)(local_8 & ~uVar1) << 0x20);
      }
    }
  }
  else {
    if ((int)uVar2 < 0x34) {
      uVar1 = 0xffffffff >> uVar1 - 0x413;
      if (((uStack4 & uVar1) != 0) && (_126 < _125 + __x)) {
        if ((longlong)__x < 0) {
          if (uVar2 == 0x14) {
            __x = (double)((ulonglong)__x & 0xffffffff | (ulonglong)(local_8 + 1) << 0x20);
          }
          else {
            uVar2 = uStack4 + (1 << 0x34 - uVar2);
            if (uVar2 < uStack4) {
              local_8 = local_8 + 1;
            }
            __x = (double)CONCAT44(local_8,uVar2);
          }
        }
        __x = (double)((ulonglong)__x & 0xffffffff00000000 | (ulonglong)(SUB84(__x,0) & ~uVar1));
      }
    }
    else {
      if (uVar2 == 0x400) {
        __x = __x + __x;
      }
    }
  }
  return __x;
}

