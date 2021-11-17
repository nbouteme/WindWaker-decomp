#include <MSL_C.PPCEABI.bare.H/s_cos.h>
#include <MSL_C.PPCEABI.bare.H/k_cos.h>
#include <MSL_C.PPCEABI.bare.H/e_rem_pio2.h>
#include <MSL_C.PPCEABI.bare.H/k_sin.h>


namespace MSL_C.PPCEABI.bare.H {

/* WARNING: Removing unreachable block (ram,0x80330784) */

double cos(double theta)

{
  uint uVar1;
  double dVar2;
  uint local_18;
  undefined8 local_10;
  undefined8 local_8;
  
  local_18 = (uint)((ulonglong)theta >> 0x20);
  if ((local_18 & 0x7fffffff) < 0x3fe921fc) {
    dVar2 = (double)__kernel_cos(theta,_73);
  }
  else {
    if ((local_18 & 0x7fffffff) < 0x7ff00000) {
      uVar1 = __ieee754_rem_pio2(&local_10);
      uVar1 = uVar1 & 3;
      if (uVar1 == 1) {
        dVar2 = (double)__kernel_sin(local_10,local_8,1);
        dVar2 = -dVar2;
      }
      else {
        if (uVar1 == 0) {
          dVar2 = (double)__kernel_cos(local_10,local_8);
        }
        else {
          if (uVar1 < 3) {
            dVar2 = (double)__kernel_cos(local_10,local_8);
            dVar2 = -dVar2;
          }
          else {
            dVar2 = (double)__kernel_sin(local_10,local_8,1);
          }
        }
      }
    }
    else {
      dVar2 = theta - theta;
    }
  }
  return dVar2;
}

