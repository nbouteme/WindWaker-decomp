#include <MSL_C.PPCEABI.bare.H/mem.h>
#include <MSL_C.PPCEABI.bare.H/mem_funcs.h>


namespace MSL_C.PPCEABI.bare.H {

int memcmp(void *__s1,void *__s2,size_t __n)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = (byte *)((int)__s1 + -1);
  pbVar3 = (byte *)((int)__s2 + -1);
  iVar1 = __n + 1;
  do {
    iVar1 = iVar1 + -1;
    if (iVar1 == 0) {
      return 0;
    }
    pbVar2 = pbVar2 + 1;
    pbVar3 = pbVar3 + 1;
  } while (*pbVar2 == *pbVar3);
  if (*pbVar3 <= *pbVar2) {
    return 1;
  }
  return -1;
}


char * __memrchr(int param_1,char param_2,int param_3)

{
  char *pcVar1;
  
  pcVar1 = (char *)(param_1 + param_3);
  param_3 = param_3 + 1;
  do {
    param_3 = param_3 + -1;
    if (param_3 == 0) {
      return (char *)0x0;
    }
    pcVar1 = pcVar1 + -1;
  } while (*pcVar1 != param_2);
  return pcVar1;
}


void * memchr(void *__s,int __c,size_t __n)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = (byte *)((int)__s + -1);
  iVar2 = __n + 1;
  do {
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
      return (byte *)0x0;
    }
    pbVar1 = pbVar1 + 1;
  } while ((uint)*pbVar1 != (__c & 0xffU));
  return pbVar1;
}


void * memmove(void *__dest,void *__src,size_t __n)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  iVar1 = countLeadingZeros((uint)__dest ^ (uint)__src);
  iVar1 = (int)__dest << iVar1;
  if (__n < 0x20) {
    if (iVar1 < 0) {
      puVar2 = (undefined *)((int)__src + __n);
      puVar3 = (undefined *)((int)__dest + __n);
      iVar1 = __n + 1;
      while (iVar1 = iVar1 + -1, iVar1 != 0) {
        puVar2 = puVar2 + -1;
        puVar3 = puVar3 + -1;
        *puVar3 = *puVar2;
      }
    }
    else {
      puVar2 = (undefined *)((int)__src + -1);
      puVar3 = (undefined *)((int)__dest + -1);
      iVar1 = __n + 1;
      while (iVar1 = iVar1 + -1, iVar1 != 0) {
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
        *puVar3 = *puVar2;
      }
    }
  }
  else {
    if ((((uint)__dest ^ (uint)__src) & 3) == 0) {
      if (iVar1 < 0) {
        __copy_longs_rev_aligned();
      }
      else {
        __copy_longs_aligned();
      }
    }
    else {
      if (iVar1 < 0) {
        __copy_longs_rev_unaligned();
      }
      else {
        __copy_longs_unaligned();
      }
    }
  }
  return __dest;
}

