#include <MSL_C.PPCEABI.bare.H/arith.h>


namespace MSL_C.PPCEABI.bare.H {

div_t div(int __numer,int __denom)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 1;
  iVar3 = 1;
  if (__numer < 0) {
    __numer = -__numer;
    iVar2 = -1;
  }
  if (__denom < 0) {
    __denom = -__denom;
    iVar3 = -1;
  }
  iVar1 = (__numer / __denom) * iVar2 * iVar3;
  return (div_t)CONCAT44(iVar1,__numer * iVar2 - iVar3 * iVar1 * __denom);
}


long labs(long __x)

{
  return (__x >> 0x1f ^ __x) - (__x >> 0x1f);
}


int abs(int __x)

{
  return (__x >> 0x1f ^ __x) - (__x >> 0x1f);
}

