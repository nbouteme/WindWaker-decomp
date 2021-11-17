#pragma once
#include <ctypes.h>



namespace MSL_C.PPCEABI.bare.H {
size_t wcstombs(char *__s,wchar_t *__pwcs,size_t __n);
uint unicode_to_UTF8(int param_1,uint param_2);
}
