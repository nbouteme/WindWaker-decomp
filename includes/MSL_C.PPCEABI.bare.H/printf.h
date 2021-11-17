#pragma once
#include <ctypes.h>



namespace MSL_C.PPCEABI.bare.H {
int sprintf(char *__s,char *__format,...);
int snprintf(char *__s,size_t __maxlen,char *__format,...);
int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg);
int vprintf(char *__format,__gnuc_va_list __arg);
int printf(char *__format,...);
undefined4 __StringWrite(int *param_1,byte *param_2,int param_3);
FILE * __FileWrite(FILE *param_1,void *param_2,size_t param_3);
int __pformatter(code *param_1,undefined4 param_2,char *param_3,undefined4 param_4);
byte * float2str(double param_1,int param_2,int param_3);
void round_decimal(int param_1,int param_2);
char * double2hex(ulonglong param_1,int param_2,int param_3);
char * longlong2str(uint param_1,uint param_2,int param_3,char *param_4);
char * long2str(uint param_1,int param_2,char *param_3);
char * parse_format(int param_1,undefined4 param_2,uint *param_3);
}
