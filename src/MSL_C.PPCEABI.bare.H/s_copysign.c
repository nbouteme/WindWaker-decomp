#include <MSL_C.PPCEABI.bare.H/s_copysign.h>


namespace MSL_C.PPCEABI.bare.H {

/* WARNING: Could not reconcile some variable overlaps */

double copysign(double __x,double __y)

{
  double local_18;
  uint local_10;
  
  local_18._0_4_ = (uint)((ulonglong)__x >> 0x20);
  local_10 = (uint)((ulonglong)__y >> 0x20);
  local_18 = (double)((ulonglong)__x & 0xffffffff |
                     (ulonglong)(local_18._0_4_ & 0x7fffffff | local_10 & 0x80000000) << 0x20);
  return local_18;
}

