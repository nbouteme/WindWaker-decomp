#include <MSL_C.PPCEABI.bare.H/w_fmod.h>
#include <MSL_C.PPCEABI.bare.H/e_fmod.h>


namespace MSL_C.PPCEABI.bare.H {

double fmod(double __x,double __y)

{
  double dVar1;
  
  dVar1 = (double)__ieee754_fmod();
  return dVar1;
}

