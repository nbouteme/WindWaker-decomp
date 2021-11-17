#include <MSL_C.PPCEABI.bare.H/e_asin.h>


namespace MSL_C.PPCEABI.bare.H {

double __ieee754_asin(double param_1,double param_2)

{
  uint uVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  uint local_18;
  uint uStack20;
  double local_10;
  
  local_18 = (uint)((ulonglong)param_1 >> 0x20);
  uVar1 = local_18 & 0x7fffffff;
  if (uVar1 < 0x3ff00000) {
    if (uVar1 < 0x3fe00000) {
      if (uVar1 < 0x3e400000) {
        if (_108 < _107 + param_1) {
          return param_1;
        }
      }
      else {
        param_2 = param_1 * param_1;
      }
      param_1 = param_1 * ((param_2 *
                           (param_2 * (param_2 * (param_2 * (param_2 * (_114 * param_2 + _113) +
                                                            _112) + _111) + _110) + _109)) /
                          (param_2 * (param_2 * (param_2 * (_118 * param_2 + _117) + _116) + _115) +
                          _108)) + param_1;
    }
    else {
      dVar2 = _119 * (_108 - ABS(param_1));
      dVar5 = dVar2 * (dVar2 * (dVar2 * (_118 * dVar2 + _117) + _116) + _115) + _108;
      dVar4 = dVar2 * (dVar2 * (dVar2 * (dVar2 * (dVar2 * (_114 * dVar2 + _113) + _112) + _111) +
                               _110) + _109);
      if (dVar2 <= _120) {
        dVar3 = _120;
        if (_120 != dVar2) {
          if (dVar2 == _120) {
            dVar3 = (double)__float_huge;
          }
          else {
            dVar3 = (double)__float_nan;
          }
        }
      }
      else {
        dVar3 = 1.0 / SQRT(dVar2);
        dVar3 = _119 * dVar3 * -(dVar2 * dVar3 * dVar3 - _121);
        dVar3 = _119 * dVar3 * -(dVar2 * dVar3 * dVar3 - _121);
        dVar3 = _119 * dVar3 * -(dVar2 * dVar3 * dVar3 - _121);
        dVar3 = dVar2 * _119 * dVar3 * -(dVar2 * dVar3 * dVar3 - _121);
      }
      if (uVar1 < 0x3fef3333) {
        local_10 = (double)((ulonglong)dVar3 & 0xffffffff00000000);
        param_1 = _123 - ((_122 * dVar3 * (dVar4 / dVar5) -
                          -(_122 * (-(local_10 * local_10 - dVar2) / (dVar3 + local_10)) - _106)) -
                         -(_122 * local_10 - _123));
      }
      else {
        param_1 = _105 - (_122 * (dVar3 * (dVar4 / dVar5) + dVar3) - _106);
      }
      if ((int)local_18 < 1) {
        param_1 = -param_1;
      }
    }
  }
  else {
    uStack20 = SUB84(param_1,0);
    if ((uVar1 + 0xc0100000 | uStack20) == 0) {
      param_1 = _105 * param_1 + _106 * param_1;
    }
    else {
      param_1 = (double)__float_nan;
    }
  }
  return param_1;
}

