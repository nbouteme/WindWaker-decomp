#include <gd/GDBase.h>
#include <os/OSCache.h>


namespace gd {
undefined4 __GDCurrentDL;
undefined4 overflowcb;

void GDInitGDLObj(int *param_1,int param_2,int param_3)

{
  *param_1 = param_2;
  param_1[2] = param_2;
  param_1[3] = param_2 + param_3;
  param_1[1] = param_3;
  return;
}


void GDFlushCurrToMem(void)

{
  os::DCFlushRange(*__GDCurrentDL,__GDCurrentDL[1]);
  return;
}


void GDPadCurr32(void)

{
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(__GDCurrentDL + 8) & 0x1f;
  if (uVar3 == 0) {
    return;
  }
  uVar1 = 0x20 - uVar3;
  if (uVar3 < 0x20) {
    uVar3 = uVar1 >> 3;
    if (uVar3 != 0) {
      do {
        puVar2 = *(undefined **)(__GDCurrentDL + 8);
        *(undefined **)(__GDCurrentDL + 8) = puVar2 + 1;
        *puVar2 = 0;
        puVar2 = *(undefined **)(__GDCurrentDL + 8);
        *(undefined **)(__GDCurrentDL + 8) = puVar2 + 1;
        *puVar2 = 0;
        puVar2 = *(undefined **)(__GDCurrentDL + 8);
        *(undefined **)(__GDCurrentDL + 8) = puVar2 + 1;
        *puVar2 = 0;
        puVar2 = *(undefined **)(__GDCurrentDL + 8);
        *(undefined **)(__GDCurrentDL + 8) = puVar2 + 1;
        *puVar2 = 0;
        puVar2 = *(undefined **)(__GDCurrentDL + 8);
        *(undefined **)(__GDCurrentDL + 8) = puVar2 + 1;
        *puVar2 = 0;
        puVar2 = *(undefined **)(__GDCurrentDL + 8);
        *(undefined **)(__GDCurrentDL + 8) = puVar2 + 1;
        *puVar2 = 0;
        puVar2 = *(undefined **)(__GDCurrentDL + 8);
        *(undefined **)(__GDCurrentDL + 8) = puVar2 + 1;
        *puVar2 = 0;
        puVar2 = *(undefined **)(__GDCurrentDL + 8);
        *(undefined **)(__GDCurrentDL + 8) = puVar2 + 1;
        *puVar2 = 0;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
      uVar1 = uVar1 & 7;
      if (uVar1 == 0) {
        return;
      }
    }
    do {
      puVar2 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar2 + 1;
      *puVar2 = 0;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
    return;
  }
  return;
}


void GDOverflowed(void)

{
  if (overflowcb != (code *)0x0) {
    (*overflowcb)();
  }
  return;
}

