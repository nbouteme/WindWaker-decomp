#include <MSL_C.PPCEABI.bare.H/strtoul.h>
#include <MSL_C.PPCEABI.bare.H/scanf.h>
#include <MSL_C.PPCEABI.bare.H/strtoul.h>


namespace MSL_C.PPCEABI.bare.H {

long strtol(char *__nptr,char **__endptr,int __base)

{
  uint uVar1;
  int local_28;
  uint local_24;
  int local_20;
  char *local_1c;
  undefined4 local_18;
  
  local_18 = 0;
  local_1c = __nptr;
  uVar1 = __strtoul(__base,0x7fffffff,__StringRead,&local_1c,&local_20,&local_24,&local_28);
  if (__endptr != (char **)0x0) {
    *__endptr = __nptr + local_20;
  }
  if (((local_28 == 0) && ((local_24 != 0 || (uVar1 < 0x80000000)))) &&
     ((local_24 == 0 || (uVar1 < 0x80000001)))) {
    if (local_24 != 0) {
      uVar1 = -uVar1;
    }
  }
  else {
    errno = 0x22;
    uVar1 = 0x7fffffff - ((int)(-local_24 | local_24) >> 0x1f);
  }
  return uVar1;
}


ulong strtoul(char *__nptr,char **__endptr,int __base)

{
  ulong uVar1;
  int local_28;
  int local_24;
  int local_20;
  char *local_1c;
  undefined4 local_18;
  
  local_18 = 0;
  local_1c = __nptr;
  uVar1 = __strtoul(__base,0x7fffffff,__StringRead,&local_1c,&local_20,&local_24,&local_28);
  if (__endptr != (char **)0x0) {
    *__endptr = __nptr + local_20;
  }
  if (local_28 == 0) {
    if (local_24 != 0) {
      uVar1 = -uVar1;
    }
  }
  else {
    uVar1 = 0xffffffff;
    errno = 0x22;
  }
  return uVar1;
}


uint __strtoul
               (uint param_1,uint param_2,code *param_3,undefined4 param_4,int *param_5,
               undefined4 *param_6,undefined4 *param_7)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  uVar6 = 1;
  iVar9 = 0;
  iVar5 = 0;
  uVar8 = 0;
  uVar7 = 0;
  *param_7 = 0;
  *param_6 = 0;
  if (((((int)param_1 < 0) || (param_1 == 1)) || (0x24 < (int)param_1)) || ((int)param_2 < 1)) {
    uVar6 = 0x40;
    uVar2 = param_2;
  }
  else {
    iVar9 = 1;
    uVar2 = (*param_3)(param_4,0,0);
  }
  if (param_1 != 0) {
    uVar7 = 0xffffffff / param_1;
  }
  do {
    if ((((int)param_2 < iVar9) || (uVar2 == 0xffffffff)) || ((uVar6 & 0x60) != 0)) {
      if ((uVar6 & 0x34) == 0) {
        uVar8 = 0;
        *param_5 = 0;
      }
      else {
        *param_5 = iVar9 + iVar5 + -1;
      }
      (*param_3)(param_4,uVar2,1);
      return uVar8;
    }
    switch(uVar6) {
    case 1:
      if (((&__ctype_map)[uVar2 & 0xff] & 6) == 0) {
        if (uVar2 == 0x2b) {
          iVar9 = iVar9 + 1;
          uVar2 = (*param_3)(param_4,0,0);
        }
        else {
          if (uVar2 == 0x2d) {
            iVar9 = iVar9 + 1;
            uVar2 = (*param_3)(param_4,0,0);
            *param_6 = 1;
          }
        }
        uVar6 = 2;
      }
      else {
        uVar2 = (*param_3)(param_4,0,0);
        iVar5 = iVar5 + 1;
      }
      break;
    case 2:
      if (((param_1 == 0) || (param_1 == 0x10)) && (uVar2 == 0x30)) {
        uVar6 = 4;
        iVar9 = iVar9 + 1;
        uVar2 = (*param_3)(param_4,0,0);
      }
      else {
        uVar6 = 8;
      }
      break;
    case 4:
      if ((uVar2 == 0x58) || (uVar2 == 0x78)) {
        param_1 = 0x10;
        uVar6 = 8;
        iVar9 = iVar9 + 1;
        uVar2 = (*param_3)(param_4,0,0);
      }
      else {
        if (param_1 == 0) {
          param_1 = 8;
        }
        uVar6 = 0x10;
      }
      break;
    case 8:
    case 0x10:
      if (param_1 == 0) {
        param_1 = 10;
      }
      if (uVar7 == 0) {
        uVar7 = 0xffffffff / param_1;
      }
      uVar4 = uVar2 & 0xff;
      if (((&__ctype_map)[uVar4] & 0x10) == 0) {
        if (((&__ctype_map)[uVar4] & 0xc0) != 0) {
          if (uVar2 == 0xffffffff) {
            uVar3 = 0xffffffff;
          }
          else {
            uVar3 = (uint)(byte)(&__upper_map)[uVar4];
          }
          if ((int)(uVar3 - 0x37) < (int)param_1) {
            if (uVar2 == 0xffffffff) {
              uVar4 = 0xffffffff;
            }
            else {
              uVar4 = (uint)(byte)(&__upper_map)[uVar4];
            }
            uVar4 = uVar4 - 0x37;
            goto LAB_8032e20c;
          }
        }
        if (uVar6 == 0x10) {
          uVar6 = 0x20;
        }
        else {
          uVar6 = 0x40;
        }
      }
      else {
        uVar4 = uVar2 - 0x30;
        if ((int)uVar4 < (int)param_1) {
LAB_8032e20c:
          if (uVar7 < uVar8) {
            *param_7 = 1;
          }
          if (-(uVar8 * param_1) - 1 < uVar4) {
            *param_7 = 1;
          }
          uVar8 = uVar8 * param_1 + uVar4;
          uVar6 = 0x10;
          iVar9 = iVar9 + 1;
          uVar2 = (*param_3)(param_4,0,0);
        }
        else {
          bVar1 = uVar6 == 0x10;
          uVar6 = 0x40;
          if (bVar1) {
            uVar6 = 0x20;
          }
        }
      }
    }
  } while( true );
}

