#include <MSL_C.PPCEABI.bare.H/e_atan2.h>
#include <MSL_C.PPCEABI.bare.H/s_atan.h>


namespace MSL_C.PPCEABI.bare.H {

/* WARNING: Removing unreachable block (ram,0x8032eaf8) */
/* WARNING: Removing unreachable block (ram,0x8032eab0) */
/* WARNING: Removing unreachable block (ram,0x8032ebb0) */
/* WARNING: Removing unreachable block (ram,0x8032ea3c) */

double __ieee754_atan2(double param_1,double param_2)

{
  uint uVar1;
  uint uVar2;
  double dVar3;
  int iVar4;
  uint uVar5;
  uint local_28;
  uint uStack36;
  uint local_20;
  uint uStack28;
  double local_18;
  
  uStack28 = SUB84(param_2,0);
  local_20 = (uint)((ulonglong)param_2 >> 0x20);
  uVar1 = local_20 & 0x7fffffff;
  local_28 = (uint)((ulonglong)param_1 >> 0x20);
  uStack36 = SUB84(param_1,0);
  uVar2 = local_28 & 0x7fffffff;
  if (((uVar1 | (uStack28 | -uStack28) >> 0x1f) < 0x7ff00001) &&
     ((uVar2 | (uStack36 | -uStack36) >> 0x1f) < 0x7ff00001)) {
    if ((local_20 + 0xc0100000 | uStack28) == 0) {
      local_18 = atan(param_1);
    }
    else {
      uVar5 = local_28 >> 0x1f | local_20 >> 0x1e & 2;
      if (((uVar2 | uStack36) != 0) ||
         (((local_18 = _146, uVar5 != 2 && (local_18 = param_1, 1 < uVar5)) &&
          (local_18 = _147, 3 < uVar5)))) {
        local_18 = _149;
        if ((uVar1 | uStack28) == 0) {
          if ((longlong)param_1 < 0) {
            local_18 = _148;
          }
        }
        else {
          if (uVar1 == 0x7ff00000) {
            if (uVar2 == 0x7ff00000) {
              if (uVar5 == 2) {
                return _152;
              }
              dVar3 = _153;
              if (uVar5 < 2) {
                if (uVar5 == 0) {
                  return _150;
                }
                return _151;
              }
            }
            else {
              if (uVar5 == 2) {
                return _146;
              }
              dVar3 = _147;
              if (uVar5 < 2) {
                if (uVar5 == 0) {
                  return _154;
                }
                return _155;
              }
            }
            if (uVar5 < 4) {
              return dVar3;
            }
          }
          if (uVar2 == 0x7ff00000) {
            if ((longlong)param_1 < 0) {
              local_18 = _148;
            }
          }
          else {
            iVar4 = (int)(uVar2 - uVar1) >> 0x14;
            if (iVar4 < 0x3d) {
              if (((longlong)param_2 < 0) && (iVar4 < -0x3c)) {
                local_18 = _154;
              }
              else {
                local_18 = atan(ABS(param_1 / param_2));
              }
            }
            else {
            }
            if (uVar5 == 1) {
              local_18 = (double)((ulonglong)local_18 ^ 0x8000000000000000);
            }
            else {
              if (uVar5 != 0) {
                if (uVar5 < 3) {
                  local_18 = _146 - (local_18 - _156);
                }
                else {
                  local_18 = (local_18 - _156) - _146;
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    local_18 = param_2 + param_1;
  }
  return local_18;
}

