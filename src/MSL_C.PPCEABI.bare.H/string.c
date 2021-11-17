#include <MSL_C.PPCEABI.bare.H/string.h>


namespace MSL_C.PPCEABI.bare.H {

char * strrchr(char *__s,int __c)

{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)(__s + -1);
  pbVar1 = (byte *)0x0;
  while( true ) {
    pbVar2 = pbVar2 + 1;
    if (*pbVar2 == 0) break;
    if ((uint)*pbVar2 == (__c & 0xffU)) {
      pbVar1 = pbVar2;
    }
  }
  if (pbVar1 != (byte *)0x0) {
    return (char *)pbVar1;
  }
  if ((__c & 0xffU) != 0) {
    return (char *)(byte *)0x0;
  }
  return (char *)pbVar2;
}


char * strchr(char *__s,int __c)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(__s + -1);
  while( true ) {
    pbVar1 = pbVar1 + 1;
    if (*pbVar1 == 0) break;
    if ((uint)*pbVar1 == (__c & 0xffU)) {
      return (char *)pbVar1;
    }
  }
  if ((__c & 0xffU) == 0) {
    return (char *)pbVar1;
  }
  return (char *)(byte *)0x0;
}


int strncmp(char *__s1,char *__s2,size_t __n)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  
  pbVar2 = (byte *)(__s1 + -1);
  pbVar3 = (byte *)(__s2 + -1);
  iVar4 = __n + 1;
  while( true ) {
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      return 0;
    }
    pbVar2 = pbVar2 + 1;
    uVar1 = (uint)*pbVar2;
    pbVar3 = pbVar3 + 1;
    if (uVar1 != *pbVar3) break;
    if (uVar1 == 0) {
      return 0;
    }
  }
  return uVar1 - *pbVar3;
}


int strcmp(char *__s1,char *__s2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (uint)(byte)*__s1;
  if (uVar3 - (byte)*__s2 != 0) {
    return uVar3 - (byte)*__s2;
  }
  uVar4 = (uint)__s1 & 3;
  if (((uint)__s2 & 3) == uVar4) {
    if (uVar4 != 0) {
      if (uVar3 == 0) {
        return 0;
      }
      for (iVar1 = 3 - uVar4; iVar1 != 0; iVar1 = iVar1 + -1) {
        __s1 = (char *)((byte *)__s1 + 1);
        __s2 = (char *)((byte *)__s2 + 1);
        iVar2 = (uint)(byte)*__s1 - (uint)(byte)*__s2;
        if (iVar2 != 0) {
          return iVar2;
        }
        if ((byte)*__s1 == 0) {
          return 0;
        }
      }
      __s1 = (char *)((byte *)__s1 + 1);
      __s2 = (char *)((byte *)__s2 + 1);
    }
    uVar4 = *(uint *)__s2;
    uVar3 = *(uint *)__s1;
    while ((uVar3 + 0xfefefeff & 0x80808080) == 0) {
      if (uVar3 != uVar4) {
        if (uVar4 < uVar3) {
          return 1;
        }
        return -1;
      }
      __s1 = (char *)((int)__s1 + 4);
      __s2 = (char *)((int)__s2 + 4);
      uVar4 = *(uint *)__s2;
      uVar3 = *(uint *)__s1;
    }
    uVar3 = (uint)(byte)*__s1;
    if (uVar3 - (byte)*__s2 != 0) {
      return uVar3 - (byte)*__s2;
    }
  }
  if (uVar3 == 0) {
    return 0;
  }
  do {
    __s1 = (char *)((int)__s1 + 1);
    __s2 = (char *)((int)__s2 + 1);
    iVar1 = (uint)(byte)*__s1 - (uint)(byte)*__s2;
    if (iVar1 != 0) {
      return iVar1;
    }
  } while ((byte)*__s1 != 0);
  return 0;
}


char * strcat(char *__dest,char *__src)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar3 = __src + -1;
  pcVar2 = __dest + -1;
  do {
    pcVar4 = pcVar2;
    pcVar2 = pcVar4 + 1;
  } while (pcVar4[1] != '\0');
  do {
    pcVar3 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar4 = pcVar4 + 1;
    *pcVar4 = cVar1;
  } while (cVar1 != '\0');
  return __dest;
}


char * strncpy(char *__dest,char *__src,size_t __n)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar2 = __src + -1;
  pcVar4 = __dest + -1;
  iVar3 = __n + 1;
  do {
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return __dest;
    }
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar4 = pcVar4 + 1;
    *pcVar4 = cVar1;
  } while (cVar1 != '\0');
  while (iVar3 = iVar3 + -1, iVar3 != 0) {
    pcVar4 = pcVar4 + 1;
    *pcVar4 = '\0';
  }
  return __dest;
}


char * strcpy(char *__dest,char *__src)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  uVar3 = (uint)__src & 3;
  piVar6 = (int *)__dest;
  if (((uint)__dest & 3) == uVar3) {
    if (uVar3 != 0) {
      cVar2 = *__src;
      *__dest = cVar2;
      if (cVar2 == '\0') {
        return __dest;
      }
      pcVar1 = __dest;
      for (iVar5 = 3 - uVar3; iVar5 != 0; iVar5 = iVar5 + -1) {
        __src = __src + 1;
        cVar2 = *__src;
        pcVar1 = pcVar1 + 1;
        *pcVar1 = cVar2;
        if (cVar2 == '\0') {
          return __dest;
        }
      }
      piVar6 = (int *)(pcVar1 + 1);
      __src = __src + 1;
    }
    iVar5 = *(int *)__src;
    if ((iVar5 + 0xfefefeffU & 0x80808080) == 0) {
      piVar4 = piVar6 + -1;
      do {
        piVar6 = piVar4;
        piVar4 = piVar6 + 1;
        *piVar4 = iVar5;
        __src = (char *)((int)__src + 4);
        iVar5 = *(int *)__src;
      } while ((iVar5 + 0xfefefeffU & 0x80808080) == 0);
      piVar6 = piVar6 + 2;
    }
  }
  cVar2 = *__src;
  *(char *)piVar6 = cVar2;
  if (cVar2 != '\0') {
    do {
      __src = (char *)((int)__src + 1);
      cVar2 = *__src;
      piVar6 = (int *)((int)piVar6 + 1);
      *(char *)piVar6 = cVar2;
    } while (cVar2 != '\0');
    return __dest;
  }
  return __dest;
}


size_t strlen(char *__s)

{
  size_t sVar1;
  char *pcVar2;
  
  pcVar2 = __s + -1;
  sVar1 = 0xffffffff;
  do {
    pcVar2 = pcVar2 + 1;
    sVar1 = sVar1 + 1;
  } while (*pcVar2 != '\0');
  return sVar1;
}

