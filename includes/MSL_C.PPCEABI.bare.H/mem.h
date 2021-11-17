#pragma once
#include <ctypes.h>



namespace MSL_C.PPCEABI.bare.H {
int memcmp(void *__s1,void *__s2,size_t __n);
char * __memrchr(int param_1,char param_2,int param_3);
void * memchr(void *__s,int __c,size_t __n);
void * memmove(void *__dest,void *__src,size_t __n);
}
