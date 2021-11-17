#include <MSL_C.PPCEABI.bare.H/k_tan.h>


namespace MSL_C.PPCEABI.bare.H {

/* WARNING: Removing unreachable block (ram,0x803304e4) */
/* WARNING: Could not reconcile some variable overlaps */

double __kernel_tan(double param_1,double param_2,uint param_3)

{
  uint uVar1;
  double dVar2;
  undefined8 in_f31;
  double dVar3;
  undefined8 local_38;
  double local_30;
  double local_28;
  double local_20;
  undefined auStack8 [8];
  
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_38._0_4_ = (uint)((ulonglong)param_1 >> 0x20);
  uVar1 = local_38._0_4_ & 0x7fffffff;
  if ((uVar1 < 0x3e300000) && ((int)param_1 == 0)) {
    local_38._4_4_ = SUB84(param_1,0);
    if ((param_3 + 1 | uVar1 | local_38._4_4_) == 0) {
      param_1 = _95 / ABS(param_1);
    }
    else {
      if (param_3 != 1) {
        param_1 = _96 / param_1;
      }
    }
  }
  else {
    local_38 = param_1;
    if (0x3fe59427 < uVar1) {
      if ((longlong)param_1 < 0) {
        param_2 = -param_2;
        local_38 = -param_1;
      }
      local_38 = (_97 - local_38) + (_98 - param_2);
      param_2 = _99;
    }
    dVar2 = local_38 * local_38;
    dVar3 = dVar2 * dVar2;
    dVar2 = T * dVar2 * local_38 +
            dVar2 * (dVar2 * local_38 *
                     (dVar3 * (dVar3 * (dVar3 * (dVar3 * (dVar3 * DAT_803713b8 + DAT_803713a8) +
                                                DAT_80371398) + DAT_80371388) + DAT_80371378) +
                      DAT_80371368 +
                     dVar2 * (dVar3 * (dVar3 * (dVar3 * (dVar3 * (dVar3 * DAT_803713c0 +
                                                                 DAT_803713b0) + DAT_803713a0) +
                                               DAT_80371390) + DAT_80371380) + DAT_80371370)) +
                    param_2) + param_2;
    param_1 = local_38 + dVar2;
    if (uVar1 < 0x3fe59428) {
      if (param_3 != 1) {
        local_28 = (double)((ulonglong)param_1 & 0xffffffff00000000);
        local_30 = (double)((ulonglong)(_96 / param_1) & 0xffffffff00000000);
        param_1 = (_96 / param_1) *
                  (local_30 * (dVar2 - (local_28 - local_38)) + local_30 * local_28 + _95) +
                  local_30;
      }
    }
    else {
      local_20 = (double)CONCAT44(0x43300000,param_3 ^ 0x80000000);
      param_1 = ((double)CONCAT44(0x43300000,1 - (local_38._0_4_ >> 0x1e & 2) ^ 0x80000000) - _102)
                * -(_100 * (local_38 - ((param_1 * param_1) / (param_1 + (local_20 - _102)) - dVar2)
                           ) - (local_20 - _102));
    }
  }
  __psq_l0(auStack8,0);
  __psq_l1(auStack8,0);
  return param_1;
}

