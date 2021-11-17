#include <MSL_C.PPCEABI.bare.H/e_acos.h>


namespace MSL_C.PPCEABI.bare.H {

double __ieee754_acos(double param_1)

{
  uint uVar1;
  double dVar2;
  double dVar3;
  uint local_18;
  uint uStack20;
  double local_10;
  
  local_18 = (uint)((ulonglong)param_1 >> 0x20);
  uVar1 = local_18 & 0x7fffffff;
  if (uVar1 < 0x3ff00000) {
    if (uVar1 < 0x3fe00000) {
      dVar2 = _105;
      if (0x3c600000 < uVar1) {
        dVar2 = param_1 * param_1;
        dVar2 = _105 - (param_1 -
                       -(param_1 * ((dVar2 * (dVar2 * (dVar2 * (dVar2 * (dVar2 * (_112 * dVar2 +
                                                                                 _111) + _110) +
                                                               _109) + _108) + _107)) /
                                   (dVar2 * (dVar2 * (dVar2 * (_117 * dVar2 + _116) + _115) + _114)
                                   + _113)) - _106));
      }
    }
    else {
      if ((longlong)param_1 < 0) {
        dVar2 = _118 * (_113 + param_1);
        if (dVar2 <= _103) {
          dVar3 = _103;
          if (_103 != dVar2) {
            if (dVar2 == _103) {
              dVar3 = (double)__float_huge;
            }
            else {
              dVar3 = (double)__float_nan;
            }
          }
        }
        else {
          dVar3 = 1.0 / SQRT(dVar2);
          dVar3 = _118 * dVar3 * -(dVar2 * dVar3 * dVar3 - _119);
          dVar3 = _118 * dVar3 * -(dVar2 * dVar3 * dVar3 - _119);
          dVar3 = _118 * dVar3 * -(dVar2 * dVar3 * dVar3 - _119);
          dVar3 = dVar2 * _118 * dVar3 * -(dVar2 * dVar3 * dVar3 - _119);
        }
        dVar2 = -(_120 * (dVar3 + (((dVar2 * (dVar2 * (dVar2 * (dVar2 * (dVar2 * (_112 * dVar2 +
                                                                                 _111) + _110) +
                                                               _109) + _108) + _107)) /
                                   (dVar2 * (dVar2 * (dVar2 * (_117 * dVar2 + _116) + _115) + _114)
                                   + _113)) * dVar3 - _106)) - _104);
      }
      else {
        dVar2 = _118 * (_113 - param_1);
        if (dVar2 <= _103) {
          dVar3 = _103;
          if (_103 != dVar2) {
            if (dVar2 == _103) {
              dVar3 = (double)__float_huge;
            }
            else {
              dVar3 = (double)__float_nan;
            }
          }
        }
        else {
          dVar3 = 1.0 / SQRT(dVar2);
          dVar3 = _118 * dVar3 * -(dVar2 * dVar3 * dVar3 - _119);
          dVar3 = _118 * dVar3 * -(dVar2 * dVar3 * dVar3 - _119);
          dVar3 = _118 * dVar3 * -(dVar2 * dVar3 * dVar3 - _119);
          dVar3 = dVar2 * _118 * dVar3 * -(dVar2 * dVar3 * dVar3 - _119);
        }
        local_10 = (double)((ulonglong)dVar3 & 0xffffffff00000000);
        dVar2 = _120 * (local_10 +
                       ((dVar2 * (dVar2 * (dVar2 * (dVar2 * (dVar2 * (_112 * dVar2 + _111) + _110) +
                                                   _109) + _108) + _107)) /
                       (dVar2 * (dVar2 * (dVar2 * (_117 * dVar2 + _116) + _115) + _114) + _113)) *
                       dVar3 + -(local_10 * local_10 - dVar2) / (dVar3 + local_10));
      }
    }
  }
  else {
    uStack20 = SUB84(param_1,0);
    if ((uVar1 + 0xc0100000 | uStack20) == 0) {
      dVar2 = _104;
      if (0 < (int)local_18) {
        dVar2 = _103;
      }
    }
    else {
      dVar2 = (double)__float_nan;
    }
  }
  return dVar2;
}

