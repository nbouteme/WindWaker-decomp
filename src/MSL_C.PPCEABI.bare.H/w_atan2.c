#include <MSL_C.PPCEABI.bare.H/w_atan2.h>
#include <MSL_C.PPCEABI.bare.H/e_atan2.h>


namespace MSL_C.PPCEABI.bare.H {

double atan2(double __y,double __x)

{
  double dVar1;
  
  dVar1 = (double)__ieee754_atan2();
  return dVar1;
}

