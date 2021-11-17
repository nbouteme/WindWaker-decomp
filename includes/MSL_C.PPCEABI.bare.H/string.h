#pragma once
#include <ctypes.h>



namespace MSL_C.PPCEABI.bare.H {
char * strrchr(char *__s,int __c);
char * strchr(char *__s,int __c);
int strncmp(char *__s1,char *__s2,size_t __n);
int strcmp(char *__s1,char *__s2);
char * strcat(char *__dest,char *__src);
char * strncpy(char *__dest,char *__src,size_t __n);
char * strcpy(char *__dest,char *__src);
size_t strlen(char *__s);
}
