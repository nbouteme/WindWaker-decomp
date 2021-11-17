#include <MSL_C.PPCEABI.bare.H/math_ppc.h>
#include <MSL_C.PPCEABI.bare.H/s_tan.h>
#include <MSL_C.PPCEABI.bare.H/s_sin.h>
#include <MSL_C.PPCEABI.bare.H/s_cos.h>
#include <MSL_C.PPCEABI.bare.H/w_acos.h>


namespace MSL_C.PPCEABI.bare.H {

float tanf(float __x)

{
  double dVar1;
  
  dVar1 = tan((double)__x);
  return (float)dVar1;
}


float sinf(float __x)

{
  double dVar1;
  
  dVar1 = sin((double)__x);
  return (float)dVar1;
}


float cosf(float __x)

{
  double dVar1;
  
  dVar1 = cos((double)__x);
  return (float)dVar1;
}


float acosf(float __x)

{
  double dVar1;
  
  dVar1 = acos((double)__x);
  return (float)dVar1;
}

