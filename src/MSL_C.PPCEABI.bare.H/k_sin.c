#include <MSL_C.PPCEABI.bare.H/k_sin.h>


namespace MSL_C.PPCEABI.bare.H {

double __kernel_sin(double param_1,double param_2,int param_3)

{
  double dVar1;
  double dVar2;
  double dVar3;
  uint local_18;
  
  local_18 = (uint)((ulonglong)param_1 >> 0x20);
  if ((0x3e3fffff < (local_18 & 0x7fffffff)) || ((int)param_1 != 0)) {
    dVar3 = param_1 * param_1;
    dVar2 = dVar3 * param_1;
    dVar1 = dVar3 * (dVar3 * (dVar3 * (_65 * dVar3 + _64) + _63) + _62) + _61;
    if (param_3 == 0) {
      param_1 = dVar2 * (dVar3 * dVar1 + _66) + param_1;
    }
    else {
      param_1 = param_1 - -(_66 * dVar2 - (dVar3 * (_67 * param_2 - dVar2 * dVar1) - param_2));
    }
  }
  return param_1;
}

