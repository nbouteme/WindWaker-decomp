#include <MSL_C.PPCEABI.bare.H/w_acos.h>
#include <MSL_C.PPCEABI.bare.H/e_acos.h>


namespace MSL_C.PPCEABI.bare.H {

double acos(double __x)

{
  double dVar1;
  
  dVar1 = (double)__ieee754_acos();
  return dVar1;
}

