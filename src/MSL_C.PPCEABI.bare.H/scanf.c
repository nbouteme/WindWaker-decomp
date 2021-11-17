#include <MSL_C.PPCEABI.bare.H/scanf.h>


namespace MSL_C.PPCEABI.bare.H {

byte * __StringRead(byte **param_1,byte *param_2,int param_3)

{
  byte bVar1;
  
  if (param_3 == 1) {
    if (param_1[1] == (byte *)0x0) {
      *param_1 = *param_1 + -1;
    }
    else {
      param_1[1] = (byte *)0x0;
    }
    return param_2;
  }
  if (param_3 < 1) {
    if (-1 < param_3) {
      bVar1 = **param_1;
      if (bVar1 != 0) {
        *param_1 = *param_1 + 1;
        return (byte *)(uint)bVar1;
      }
      param_1[1] = &DAT_00000001;
      return &DAT_ffffffff;
    }
  }
  else {
    if (param_3 < 3) {
      return param_1[1];
    }
  }
  return (byte *)0x0;
}

