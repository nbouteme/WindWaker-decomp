#include <MSL_C.PPCEABI.bare.H/w_asin.h>
#include <MSL_C.PPCEABI.bare.H/e_asin.h>


namespace MSL_C.PPCEABI.bare.H {

double asin(double __x)

{
  double dVar1;
  
  dVar1 = (double)__ieee754_asin();
  return dVar1;
}

