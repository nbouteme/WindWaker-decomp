#include <MSL_C.PPCEABI.bare.H/k_cos.h>


namespace MSL_C.PPCEABI.bare.H {

double __kernel_cos(double param_1,double param_2)

{
  double dVar1;
  double dVar2;
  uint local_18;
  double local_10;
  
  local_18 = (uint)((ulonglong)param_1 >> 0x20);
  local_18 = local_18 & 0x7fffffff;
  if ((0x3e3fffff < local_18) || (dVar1 = _71, (int)param_1 != 0)) {
    dVar2 = param_1 * param_1;
    dVar1 = dVar2 * (dVar2 * (dVar2 * (dVar2 * (dVar2 * (_77 * dVar2 + _76) + _75) + _74) + _73) +
                    _72);
    if (local_18 < 0x3fd33333) {
      dVar1 = _71 - (_78 * dVar2 - (dVar2 * dVar1 - param_1 * param_2));
    }
    else {
      if (local_18 < 0x3fe90001) {
        local_10 = (double)((ulonglong)(local_18 - 0x200000) << 0x20);
      }
      else {
        local_10 = _79;
      }
      dVar1 = (_71 - local_10) - ((_78 * dVar2 - local_10) - (dVar2 * dVar1 - param_1 * param_2));
    }
  }
  return dVar1;
}

