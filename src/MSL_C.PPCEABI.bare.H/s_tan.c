#include <MSL_C.PPCEABI.bare.H/s_tan.h>
#include <MSL_C.PPCEABI.bare.H/k_tan.h>
#include <MSL_C.PPCEABI.bare.H/e_rem_pio2.h>


namespace MSL_C.PPCEABI.bare.H {

double tan(double __x)

{
  uint uVar1;
  double dVar2;
  uint local_18;
  undefined8 local_10;
  undefined8 local_8;
  
  local_18 = (uint)((ulonglong)__x >> 0x20);
  if ((local_18 & 0x7fffffff) < 0x3fe921fc) {
    dVar2 = (double)__kernel_tan(__x,_59,1);
  }
  else {
    if ((local_18 & 0x7fffffff) < 0x7ff00000) {
      uVar1 = __ieee754_rem_pio2(&local_10);
      dVar2 = (double)__kernel_tan(local_10,local_8,(uVar1 & 1) * -2 + 1);
    }
    else {
      dVar2 = __x - __x;
    }
  }
  return dVar2;
}

