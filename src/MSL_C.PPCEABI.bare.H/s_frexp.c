#include <MSL_C.PPCEABI.bare.H/s_frexp.h>


namespace MSL_C.PPCEABI.bare.H {

/* WARNING: Could not reconcile some variable overlaps */

double frexp(double __x,int *__exponent)

{
  double dVar1;
  uint uVar2;
  undefined8 local_8;
  
  local_8._0_4_ = (uint)((ulonglong)__x >> 0x20);
  *__exponent = 0;
  dVar1 = _60;
  uVar2 = local_8._0_4_ & 0x7fffffff;
  local_8._4_4_ = SUB84(__x,0);
  local_8 = __x;
  if ((uVar2 < 0x7ff00000) && ((uVar2 | local_8._4_4_) != 0)) {
    if (uVar2 < 0x100000) {
      *__exponent = -0x36;
      local_8 = __x * dVar1;
      local_8._0_4_ = (uint)((ulonglong)local_8 >> 0x20);
      uVar2 = local_8._0_4_ & 0x7fffffff;
    }
    local_8 = (double)((ulonglong)local_8 & 0xffffffff |
                       ((ulonglong)local_8._0_4_ & 0x800fffff) << 0x20 | 0x3fe0000000000000);
    *__exponent = ((int)uVar2 >> 0x14) + *__exponent + -0x3fe;
  }
  return local_8;
}

