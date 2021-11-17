#include <MSL_C.PPCEABI.bare.H/s_modf.h>


namespace MSL_C.PPCEABI.bare.H {

/* WARNING: Could not reconcile some variable overlaps */

double modf(double __x,double *__iptr)

{
  uint uVar1;
  uint uVar2;
  undefined8 local_8;
  
  local_8._0_4_ = (uint)((ulonglong)__x >> 0x20);
  local_8._4_4_ = SUB84(__x,0);
  uVar1 = local_8._0_4_ >> 0x14 & 0x7ff;
  uVar2 = uVar1 - 0x3ff;
  if ((int)uVar2 < 0x14) {
    if ((int)uVar2 < 0) {
      *(uint *)__iptr = local_8._0_4_ & 0x80000000;
      *(undefined4 *)((int)__iptr + 4) = 0;
    }
    else {
      uVar1 = 0xfffff >> (uVar2 & 0x3f);
      if ((local_8._4_4_ | local_8._0_4_ & uVar1) == 0) {
        local_8 = (double)((ulonglong)(local_8._0_4_ & 0x80000000) << 0x20);
        *__iptr = __x;
        __x = local_8;
      }
      else {
        *(uint *)__iptr = local_8._0_4_ & ~uVar1;
        *(undefined4 *)((int)__iptr + 4) = 0;
        __x = __x - *__iptr;
      }
    }
  }
  else {
    if ((int)uVar2 < 0x34) {
      uVar1 = 0xffffffff >> uVar1 - 0x413;
      if ((local_8._4_4_ & uVar1) == 0) {
        local_8 = (double)((ulonglong)(local_8._0_4_ & 0x80000000) << 0x20);
        *__iptr = __x;
        __x = local_8;
      }
      else {
        *(uint *)__iptr = local_8._0_4_;
        *(uint *)((int)__iptr + 4) = local_8._4_4_ & ~uVar1;
        __x = __x - *__iptr;
      }
    }
    else {
      local_8 = (double)((ulonglong)(local_8._0_4_ & 0x80000000) << 0x20);
      *__iptr = __x;
      __x = local_8;
    }
  }
  return __x;
}

