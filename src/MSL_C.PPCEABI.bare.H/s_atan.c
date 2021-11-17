#include <MSL_C.PPCEABI.bare.H/s_atan.h>


namespace MSL_C.PPCEABI.bare.H {

/* WARNING: Could not reconcile some variable overlaps */

double atan(double __x)

{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined8 local_8;
  
  local_8._0_4_ = (uint)((ulonglong)__x >> 0x20);
  local_8._0_4_ = local_8._0_4_ & 0x7fffffff;
  if (local_8._0_4_ < 0x44100000) {
    if (local_8._0_4_ < 0x3fdc0000) {
      if ((local_8._0_4_ < 0x3e200000) && (_117 < _116 + __x)) {
        return __x;
      }
      iVar1 = -1;
      local_8 = __x;
    }
    else {
      local_8 = ABS(__x);
      if (local_8._0_4_ < 0x3ff30000) {
        if (local_8._0_4_ < 0x3fe60000) {
          iVar1 = 0;
          local_8 = (_118 * local_8 - _117) / (_118 + local_8);
        }
        else {
          iVar1 = 1;
          local_8 = (local_8 - _117) / (_117 + local_8);
        }
      }
      else {
        if (local_8._0_4_ < 0x40038000) {
          iVar1 = 2;
          local_8 = (local_8 - _119) / (_119 * local_8 + _117);
        }
        else {
          iVar1 = 3;
          local_8 = _120 / local_8;
        }
      }
    }
    dVar2 = local_8 * local_8;
    dVar4 = dVar2 * dVar2;
    dVar3 = dVar4 * (dVar4 * (dVar4 * (dVar4 * (dVar4 * DAT_80371450 + DAT_80371440) + DAT_80371430)
                             + DAT_80371420) + DAT_80371410);
    dVar2 = dVar2 * (dVar4 * (dVar4 * (dVar4 * (dVar4 * (dVar4 * DAT_80371458 + DAT_80371448) +
                                               DAT_80371438) + DAT_80371428) + DAT_80371418) + aT);
    if (iVar1 < 0) {
      dVar2 = -(local_8 * (dVar2 + dVar3) - local_8);
    }
    else {
      dVar2 = *(double *)(&atanhi + iVar1 * 8) -
              ((local_8 * (dVar2 + dVar3) - *(double *)(&atanlo + iVar1 * 8)) - local_8);
      if ((longlong)__x < 0) {
        dVar2 = -dVar2;
      }
    }
  }
  else {
    if ((local_8._0_4_ < 0x7ff00001) &&
       ((local_8._0_4_ != 0x7ff00000 || (local_8._4_4_ = SUB84(__x,0), local_8._4_4_ == 0)))) {
      if ((longlong)__x < 0x100000000) {
        dVar2 = -DAT_803713e0 - DAT_80371400;
      }
      else {
        dVar2 = DAT_803713e0 + DAT_80371400;
      }
    }
    else {
      dVar2 = __x + __x;
    }
  }
  return dVar2;
}

