#include <MSL_C.PPCEABI.bare.H/s_ldexp.h>
#include <MSL_C.PPCEABI.bare.H/s_copysign.h>


namespace MSL_C.PPCEABI.bare.H {

/* WARNING: Could not reconcile some variable overlaps */

double ldexp(double __x,int __exponent)

{
  uint uVar1;
  int iVar2;
  double local_18;
  uint local_10;
  uint uStack12;
  
  local_10 = (uint)((ulonglong)__x >> 0x20);
  uStack12 = SUB84(__x,0);
  if ((local_10 & 0x7ff00000) == 0x7ff00000) {
    if ((((ulonglong)__x & 0xfffff00000000) == 0) && (uStack12 == 0)) {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    if (((local_10 & 0x7ff00000) < 0x7ff00000) && (((ulonglong)__x & 0x7ff0000000000000) == 0)) {
      if ((((ulonglong)__x & 0xfffff00000000) == 0) && (uStack12 == 0)) {
        uVar1 = 3;
      }
      else {
        uVar1 = 5;
      }
    }
    else {
      uVar1 = 4;
    }
  }
  if (uVar1 < 3) {
    return __x;
  }
  if (_102 == __x) {
    return __x;
  }
  uVar1 = local_10 >> 0x14 & 0x7ff;
  local_18 = __x;
  if (uVar1 == 0) {
    if ((uStack12 | local_10 & 0x7fffffff) == 0) {
      return __x;
    }
    local_18 = __x * _103;
    local_18._0_4_ = (uint)((ulonglong)local_18 >> 0x20);
    uVar1 = (local_18._0_4_ >> 0x14 & 0x7ff) - 0x36;
    local_10 = local_18._0_4_;
    if (__exponent < -50000) {
      return _104 * local_18;
    }
  }
  if (uVar1 == 0x7ff) {
    local_18 = local_18 + local_18;
  }
  else {
    iVar2 = uVar1 + __exponent;
    if (iVar2 < 0x7ff) {
      if (iVar2 < 1) {
        if (iVar2 < -0x35) {
          if (__exponent < 0xc351) {
            local_18 = copysign(_104,local_18);
            local_18 = _104 * local_18;
          }
          else {
            local_18 = copysign(_105,local_18);
            local_18 = _105 * local_18;
          }
        }
        else {
          local_18 = (double)((ulonglong)local_18 & 0xffffffff |
                             (ulonglong)(local_10 & 0x800fffff | (iVar2 + 0x36) * 0x100000) << 0x20)
          ;
          local_18 = _106 * local_18;
        }
      }
      else {
        local_18 = (double)((ulonglong)local_18 & 0xffffffff |
                           (ulonglong)(local_10 & 0x800fffff | iVar2 * 0x100000) << 0x20);
      }
    }
    else {
      local_18 = copysign(_105,local_18);
      local_18 = _105 * local_18;
    }
  }
  return local_18;
}

