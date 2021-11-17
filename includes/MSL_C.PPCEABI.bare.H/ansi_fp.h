#pragma once
#include <ctypes.h>



namespace MSL_C.PPCEABI.bare.H {
void __num2dec(int param_1,int param_2);
void __num2dec_internal(double param_1,char *param_2);
void __two_exp(undefined4 *param_1,ushort param_2);
void __str2dec(undefined *param_1,char *param_2,undefined2 param_3);
void __timesdec(undefined *param_1,int param_2,int param_3);
void __ull2dec(undefined *param_1,undefined4 param_2,uint param_3,uint param_4);
int __count_trailing_zerol(uint param_1);
}
