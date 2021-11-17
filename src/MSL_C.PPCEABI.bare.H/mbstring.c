#include <MSL_C.PPCEABI.bare.H/mbstring.h>
#include <MSL_C.PPCEABI.bare.H/mbstring.h>
#include <MSL_C.PPCEABI.bare.H/string.h>


namespace MSL_C.PPCEABI.bare.H {

size_t wcstombs(char *__s,wchar_t *__pwcs,size_t __n)

{
  size_t __n_00;
  size_t sVar1;
  char acStack40 [20];
  
  sVar1 = 0;
  if ((__s == (char *)0x0) || (__pwcs == (wchar_t *)0x0)) {
    sVar1 = 0;
  }
  else {
    for (; sVar1 <= __n; sVar1 = sVar1 + __n_00) {
      if (*__pwcs == L'\0') {
        __s[sVar1] = '\0';
        return sVar1;
      }
      __pwcs = __pwcs + 1;
      __n_00 = unicode_to_UTF8(acStack40);
      if (__n < sVar1 + __n_00) {
        return sVar1;
      }
      strncpy(__s + sVar1,acStack40,__n_00);
    }
  }
  return sVar1;
}


uint unicode_to_UTF8(int param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte local_8 [8];
  
  if (param_1 == 0) {
    return 0;
  }
  if ((param_2 & 0xffff) < 0x80) {
    uVar2 = 1;
  }
  else {
    if ((param_2 & 0xffff) < 0x800) {
      uVar2 = 2;
    }
    else {
      uVar2 = 3;
    }
  }
  pbVar3 = (byte *)(param_1 + uVar2);
  if (uVar2 != 2) {
    if (uVar2 < 2) {
      if (uVar2 == 0) {
        return 0;
      }
      goto LAB_8032b488;
    }
    if (3 < uVar2) {
      return uVar2;
    }
    bVar1 = (byte)param_2;
    param_2 = param_2 >> 6 & 0x3ff;
    pbVar3 = pbVar3 + -1;
    *pbVar3 = bVar1 & 0x3f | 0x80;
  }
  bVar1 = (byte)param_2;
  param_2 = param_2 >> 6 & 0x3ff;
  pbVar3 = pbVar3 + -1;
  *pbVar3 = bVar1 & 0x3f | 0x80;
LAB_8032b488:
  pbVar3[-1] = (byte)param_2 | local_8[uVar2];
  return uVar2;
}

