#pragma once
#include <ctypes.h>



namespace MSL_C.PPCEABI.bare.H {
int fseek(FILE *__stream,long __off,int __whence);
undefined4 _fseek(undefined4 *param_1,uint param_2,int param_3);
long ftell(FILE *__stream);
}
