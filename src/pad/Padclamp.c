#include <pad/Padclamp.h>
#include <pad/Padclamp.h>


namespace pad {

void ClampStick(char *param_1,char *param_2,char param_3,char param_4,char param_5)

{
  int iVar1;
  char cVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = (int)*param_1;
  iVar6 = (int)*param_2;
  if (iVar1 < 0) {
    cVar2 = -1;
    iVar1 = -iVar1;
  }
  else {
    cVar2 = '\x01';
  }
  if (iVar6 < 0) {
    cVar4 = -1;
    iVar6 = -iVar6;
  }
  else {
    cVar4 = '\x01';
  }
  iVar3 = (int)param_5;
  if (iVar3 < iVar1) {
    iVar1 = iVar1 - iVar3;
  }
  else {
    iVar1 = 0;
  }
  if (iVar3 < iVar6) {
    iVar6 = iVar6 - iVar3;
  }
  else {
    iVar6 = 0;
  }
  if ((iVar1 == 0) && (iVar6 == 0)) {
    *param_2 = '\0';
    *param_1 = '\0';
    return;
  }
  iVar3 = (int)param_4;
  if (iVar3 * iVar1 < iVar3 * iVar6) {
    iVar5 = iVar3 * param_3;
    iVar3 = iVar3 * iVar6 + iVar1 * (param_3 - iVar3);
    if (iVar5 < iVar3) {
      iVar1 = (int)(char)((iVar1 * iVar5) / iVar3);
      iVar6 = (int)(char)((iVar6 * iVar5) / iVar3);
    }
  }
  else {
    iVar5 = iVar3 * param_3;
    iVar3 = iVar3 * iVar1 + iVar6 * (param_3 - iVar3);
    if (iVar5 < iVar3) {
      iVar1 = (int)(char)((iVar1 * iVar5) / iVar3);
      iVar6 = (int)(char)((iVar6 * iVar5) / iVar3);
    }
  }
  *param_1 = cVar2 * (char)iVar1;
  *param_2 = cVar4 * (char)iVar6;
  return;
}


void PADClamp(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(char *)(param_1 + 10) == '\0') {
      ClampStick(param_1 + 2,param_1 + 3,DAT_80370fab,DAT_80370fac,DAT_80370faa);
      ClampStick(param_1 + 4,param_1 + 5,DAT_80370fae,DAT_80370faf,DAT_80370fad);
      if (ClampRegion < *(byte *)(param_1 + 6)) {
        if (DAT_80370fa9 < *(byte *)(param_1 + 6)) {
          *(byte *)(param_1 + 6) = DAT_80370fa9;
        }
        *(byte *)(param_1 + 6) = *(char *)(param_1 + 6) - ClampRegion;
      }
      else {
        *(undefined *)(param_1 + 6) = 0;
      }
      if (ClampRegion < *(byte *)(param_1 + 7)) {
        if (DAT_80370fa9 < *(byte *)(param_1 + 7)) {
          *(byte *)(param_1 + 7) = DAT_80370fa9;
        }
        *(byte *)(param_1 + 7) = *(char *)(param_1 + 7) - ClampRegion;
      }
      else {
        *(undefined *)(param_1 + 7) = 0;
      }
    }
    iVar1 = iVar1 + 1;
    param_1 = param_1 + 0xc;
  } while (iVar1 < 4);
  return;
}

