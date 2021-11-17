#include <MSL_C.PPCEABI.bare.H/e_fmod.h>


namespace MSL_C.PPCEABI.bare.H {

/* WARNING: Could not reconcile some variable overlaps */

double __ieee754_fmod(double param_1,double param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined8 local_18;
  uint local_10;
  uint uStack12;
  
  local_10 = (uint)((ulonglong)param_2 >> 0x20);
  local_18._0_4_ = (uint)((ulonglong)param_1 >> 0x20);
  uStack12 = SUB84(param_2,0);
  uVar7 = local_10 & 0x7fffffff;
  uVar1 = local_18._0_4_ & 0x80000000;
  local_18._4_4_ = SUB84(param_1,0);
  uVar3 = local_18._0_4_ ^ uVar1;
  if ((((uVar7 | uStack12) == 0) || (0x7fefffff < (int)uVar3)) ||
     (0x7ff00000 < (uVar7 | (uStack12 | -uStack12) >> 0x1f))) {
    return (param_1 * param_2) / (param_1 * param_2);
  }
  if ((int)uVar3 <= (int)uVar7) {
    if ((int)uVar3 < (int)uVar7) {
      return param_1;
    }
    if (local_18._4_4_ < uStack12) {
      return param_1;
    }
    if (local_18._4_4_ == uStack12) {
      return *(double *)(&Zero + (uVar1 >> 0x1c));
    }
  }
  if ((int)uVar3 < 0x100000) {
    if (uVar3 == 0) {
      iVar8 = -0x413;
      for (uVar5 = local_18._4_4_; 0 < (int)uVar5; uVar5 = uVar5 << 1) {
        iVar8 = iVar8 + -1;
      }
    }
    else {
      iVar8 = -0x3fe;
      for (iVar2 = local_18._0_4_ << 0xb; 0 < iVar2; iVar2 = iVar2 << 1) {
        iVar8 = iVar8 + -1;
      }
    }
  }
  else {
    iVar8 = ((int)uVar3 >> 0x14) + -0x3ff;
  }
  if (uVar7 < 0x100000) {
    if (((ulonglong)param_2 & 0x7fffffff00000000) == 0) {
      iVar2 = -0x413;
      for (uVar5 = uStack12; 0 < (int)uVar5; uVar5 = uVar5 << 1) {
        iVar2 = iVar2 + -1;
      }
    }
    else {
      iVar2 = -0x3fe;
      for (iVar6 = uVar7 << 0xb; 0 < iVar6; iVar6 = iVar6 << 1) {
        iVar2 = iVar2 + -1;
      }
    }
  }
  else {
    iVar2 = ((int)uVar7 >> 0x14) + -0x3ff;
  }
  if (iVar8 < -0x3fe) {
    iVar6 = -iVar8 + -0x3fe;
    if (iVar6 < 0x20) {
      uVar5 = local_18._4_4_ >> 0x20 - iVar6;
      local_18._4_4_ = local_18._4_4_ << iVar6;
      uVar5 = uVar3 << iVar6 | uVar5;
    }
    else {
      uVar5 = local_18._4_4_ << -iVar8 + -0x41e;
      local_18._4_4_ = 0;
    }
  }
  else {
    uVar5 = uVar3 & 0xfffff | 0x100000;
  }
  if (iVar2 < -0x3fe) {
    iVar6 = -iVar2 + -0x3fe;
    if (iVar6 < 0x20) {
      uVar3 = uStack12 >> 0x20 - iVar6;
      uStack12 = uStack12 << iVar6;
      uVar3 = uVar7 << iVar6 | uVar3;
    }
    else {
      uVar3 = uStack12 << -iVar2 + -0x41e;
      uStack12 = 0;
    }
  }
  else {
    uVar3 = local_10 & 0xfffff | 0x100000;
  }
  iVar8 = iVar8 - iVar2;
  do {
    if (iVar8 == 0) {
      uVar3 = uVar5 - uVar3;
      if (local_18._4_4_ < uStack12) {
        uVar3 = uVar3 - 1;
      }
      if (-1 < (int)uVar3) {
        local_18._4_4_ = local_18._4_4_ - uStack12;
        uVar5 = uVar3;
      }
      if ((uVar5 | local_18._4_4_) == 0) {
        local_18 = *(double *)(&Zero + (uVar1 >> 0x1c));
      }
      else {
        for (; (int)uVar5 < 0x100000; uVar5 = uVar5 * 2 - iVar8) {
          iVar8 = (int)local_18._4_4_ >> 0x1f;
          local_18._4_4_ = local_18._4_4_ * 2;
          iVar2 = iVar2 + -1;
        }
        if (iVar2 < -0x3fe) {
          uVar7 = -iVar2 - 0x3fe;
          if ((int)uVar7 < 0x15) {
            uVar4 = local_18._4_4_ >> uVar7 | uVar5 << 0x20 - uVar7;
            uVar3 = (int)uVar5 >> (uVar7 & 0x3f);
          }
          else {
            uVar3 = uVar1;
            if ((int)uVar7 < 0x20) {
              uVar4 = uVar5 << 0x20 - uVar7 | local_18._4_4_ >> uVar7;
            }
            else {
              uVar4 = (int)uVar5 >> (-iVar2 - 0x41eU & 0x3f);
            }
          }
          local_18 = (double)CONCAT44(uVar3 | uVar1,uVar4);
        }
        else {
          local_18 = (double)CONCAT44(uVar5 - 0x100000 | (iVar2 + 0x3ff) * 0x100000 | uVar1,
                                      local_18._4_4_);
        }
      }
      return local_18;
    }
    uVar4 = uVar5 - uVar3;
    uVar7 = local_18._4_4_ - uStack12;
    if (local_18._4_4_ < uStack12) {
      uVar4 = uVar4 - 1;
    }
    if ((int)uVar4 < 0) {
      uVar5 = uVar5 * 2 - ((int)local_18._4_4_ >> 0x1f);
      uVar7 = local_18._4_4_;
    }
    else {
      if ((uVar4 | uVar7) == 0) {
        return *(double *)(&Zero + (uVar1 >> 0x1c));
      }
      uVar5 = uVar4 * 2 - ((int)uVar7 >> 0x1f);
    }
    local_18._4_4_ = uVar7 * 2;
    iVar8 = iVar8 + -1;
  } while( true );
}

