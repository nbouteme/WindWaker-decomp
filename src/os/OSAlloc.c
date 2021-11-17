#include <os/OSAlloc.h>
#include <os/OSAlloc.h>
#include <m_Do_printf.h>


namespace os {
undefined4 HeapArray;
undefined4 NumHeaps;
undefined4 ArenaStart;
undefined4 ArenaEnd;

uint ** DLInsert(uint **param_1,uint **param_2)

{
  uint **ppuVar1;
  uint **ppuVar2;
  
  ppuVar1 = (uint **)0x0;
  for (ppuVar2 = param_1; (ppuVar2 != (uint **)0x0 && (ppuVar2 < param_2));
      ppuVar2 = (uint **)ppuVar2[1]) {
    ppuVar1 = ppuVar2;
  }
  param_2[1] = (uint *)ppuVar2;
  *param_2 = (uint *)ppuVar1;
  if (ppuVar2 != (uint **)0x0) {
    *ppuVar2 = (uint *)param_2;
    if ((uint **)((int)param_2 + (int)param_2[2]) == ppuVar2) {
      param_2[2] = (uint *)((int)param_2[2] + (int)ppuVar2[2]);
      ppuVar2 = (uint **)ppuVar2[1];
      param_2[1] = (uint *)ppuVar2;
      if (ppuVar2 != (uint **)0x0) {
        *ppuVar2 = (uint *)param_2;
      }
    }
  }
  if (ppuVar1 == (uint **)0x0) {
    return param_2;
  }
  ppuVar1[1] = (uint *)param_2;
  if ((uint **)((int)ppuVar1 + (int)ppuVar1[2]) != param_2) {
    return param_1;
  }
  ppuVar1[2] = (uint *)((int)ppuVar1[2] + (int)param_2[2]);
  ppuVar1[1] = (uint *)ppuVar2;
  if (ppuVar2 == (uint **)0x0) {
    return param_1;
  }
  *ppuVar2 = (uint *)ppuVar1;
  return param_1;
}


int * OSAllocFromHeap(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int **ppiVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = HeapArray + param_1 * 0xc;
  uVar1 = param_2 + 0x3fU & 0xffffffe0;
  for (piVar6 = *(int **)(iVar5 + 4); (piVar6 != (int *)0x0 && (piVar6[2] < (int)uVar1));
      piVar6 = (int *)piVar6[1]) {
  }
  if (piVar6 == (int *)0x0) {
    return (int *)0x0;
  }
  iVar2 = piVar6[2];
  if (iVar2 - uVar1 < 0x40) {
    iVar2 = *(int *)(iVar5 + 4);
    if ((int *)piVar6[1] != (int *)0x0) {
      *(int *)piVar6[1] = *piVar6;
    }
    if (*piVar6 == 0) {
      iVar2 = piVar6[1];
    }
    else {
      *(int *)(*piVar6 + 4) = piVar6[1];
    }
    *(int *)(iVar5 + 4) = iVar2;
  }
  else {
    piVar6[2] = uVar1;
    piVar4 = (int *)((int)piVar6 + uVar1);
    piVar4[2] = iVar2 - uVar1;
    *piVar4 = *piVar6;
    piVar4[1] = piVar6[1];
    if ((int **)piVar4[1] != (int **)0x0) {
      *(int **)piVar4[1] = piVar4;
    }
    if (*piVar4 == 0) {
      *(int **)(iVar5 + 4) = piVar4;
    }
    else {
      *(int **)(*piVar4 + 4) = piVar4;
    }
  }
  ppiVar3 = *(int ***)(iVar5 + 8);
  piVar6[1] = (int)ppiVar3;
  *piVar6 = 0;
  if (ppiVar3 != (int **)0x0) {
    *ppiVar3 = piVar6;
  }
  *(int **)(iVar5 + 8) = piVar6;
  return piVar6 + 8;
}


void OSFreeToHeap(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = HeapArray + param_1 * 0xc;
  uVar2 = *(undefined4 *)(iVar3 + 8);
  if (*(int **)(param_2 + -0x1c) != (int *)0x0) {
    **(int **)(param_2 + -0x1c) = *(int *)(param_2 + -0x20);
  }
  iVar1 = *(int *)(param_2 + -0x20);
  if (iVar1 == 0) {
    uVar2 = *(undefined4 *)(param_2 + -0x1c);
  }
  else {
    *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_2 + -0x1c);
  }
  *(undefined4 *)(iVar3 + 8) = uVar2;
  uVar2 = DLInsert(*(undefined4 *)(iVar3 + 4));
  *(undefined4 *)(iVar3 + 4) = uVar2;
  return;
}


undefined4 OSSetCurrentHeap(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = __OSCurrHeap;
  __OSCurrHeap = param_1;
  return uVar1;
}


void OSInitAlloc(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = 0;
  HeapArray = param_1;
  NumHeaps = param_3;
  for (iVar2 = 0; iVar2 < NumHeaps; iVar2 = iVar2 + 1) {
    puVar3 = (undefined4 *)(HeapArray + iVar1);
    *puVar3 = 0xffffffff;
    iVar1 = iVar1 + 0xc;
    puVar3[2] = 0;
    puVar3[1] = 0;
  }
  __OSCurrHeap = 0xffffffff;
  ArenaStart = HeapArray + param_3 * 0xc + 0x1fU & 0xffffffe0;
  ArenaEnd = param_2 & 0xffffffe0;
  return;
}


int OSCreateHeap(int param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  puVar1 = (undefined4 *)(param_1 + 0x1fU & 0xffffffe0);
  iVar2 = 0;
  piVar3 = HeapArray;
  iVar4 = NumHeaps;
  if (0 < NumHeaps) {
    do {
      if (*piVar3 < 0) {
        *piVar3 = (param_2 & 0xffffffe0) - (int)puVar1;
        *puVar1 = 0;
        puVar1[1] = 0;
        puVar1[2] = *piVar3;
        piVar3[1] = (int)puVar1;
        piVar3[2] = 0;
        return iVar2;
      }
      piVar3 = piVar3 + 3;
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return -1;
}


void OSDestroyHeap(int param_1)

{
  *(undefined4 *)(HeapArray + param_1 * 0xc) = 0xffffffff;
  return;
}


/* WARNING: Type propagation algorithm not settling */

undefined * OSCheckHeap(int param_1)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int **ppiVar4;
  int **ppiVar5;
  int *piVar6;
  
  iVar1 = 0;
  puVar2 = (undefined *)0x0;
  if (HeapArray == 0) {
    m_Do_printf::OSReport(_354,0x37d);
    return (undefined *)0xffffffff;
  }
  if ((param_1 < 0) || (NumHeaps <= param_1)) {
    m_Do_printf::OSReport(_355,0x37e);
    return (undefined *)0xffffffff;
  }
  piVar3 = (int *)(HeapArray + param_1 * 0xc);
  if (*piVar3 < 0) {
    m_Do_printf::OSReport(_356,0x381);
    return (undefined *)0xffffffff;
  }
  ppiVar4 = (int **)piVar3[2];
  if ((ppiVar4 != (int **)0x0) && (*ppiVar4 != (int *)0x0)) {
    m_Do_printf::OSReport(_357,899);
    return (undefined *)0xffffffff;
  }
  while (ppiVar4 != (int **)0x0) {
    if ((ppiVar4 < ArenaStart) || (ArenaEnd <= ppiVar4)) {
      m_Do_printf::OSReport(_358,0x386);
      return (undefined *)0xffffffff;
    }
    if (((uint)ppiVar4 & 0x1f) != 0) {
      m_Do_printf::OSReport(_359,0x387);
      return (undefined *)0xffffffff;
    }
    ppiVar5 = (int **)ppiVar4[1];
    if ((ppiVar5 != (int **)0x0) && ((int **)*ppiVar5 != ppiVar4)) {
      m_Do_printf::OSReport(_360,0x388);
      return (undefined *)0xffffffff;
    }
    piVar6 = ppiVar4[2];
    if (piVar6 < &DAT_00000040) {
      m_Do_printf::OSReport(_361,0x389);
      return (undefined *)0xffffffff;
    }
    if (((uint)piVar6 & 0x1f) != 0) {
      m_Do_printf::OSReport(_362,0x38a);
      return (undefined *)0xffffffff;
    }
    iVar1 = iVar1 + (int)piVar6;
    if ((iVar1 < 1) || (ppiVar4 = ppiVar5, *piVar3 < iVar1)) {
      m_Do_printf::OSReport(_363,0x38d);
      return (undefined *)0xffffffff;
    }
  }
  ppiVar4 = (int **)piVar3[1];
  if ((ppiVar4 != (int **)0x0) && (*ppiVar4 != (int *)0x0)) {
    m_Do_printf::OSReport(_364,0x395);
    return (undefined *)0xffffffff;
  }
  do {
    if (ppiVar4 == (int **)0x0) {
      if (iVar1 == *piVar3) {
        return puVar2;
      }
      m_Do_printf::OSReport(_366,0x3a8);
      return (undefined *)0xffffffff;
    }
    if ((ppiVar4 < ArenaStart) || (ArenaEnd <= ppiVar4)) {
      m_Do_printf::OSReport(_358,0x398);
      return (undefined *)0xffffffff;
    }
    if (((uint)ppiVar4 & 0x1f) != 0) {
      m_Do_printf::OSReport(_359,0x399);
      return (undefined *)0xffffffff;
    }
    ppiVar5 = (int **)ppiVar4[1];
    if ((ppiVar5 != (int **)0x0) && ((int **)*ppiVar5 != ppiVar4)) {
      m_Do_printf::OSReport(_360,0x39a);
      return (undefined *)0xffffffff;
    }
    piVar6 = ppiVar4[2];
    if (piVar6 < &DAT_00000040) {
      m_Do_printf::OSReport(_361,0x39b);
      return (undefined *)0xffffffff;
    }
    if (((uint)piVar6 & 0x1f) != 0) {
      m_Do_printf::OSReport(_362,0x39c);
      return (undefined *)0xffffffff;
    }
    if ((ppiVar5 != (int **)0x0) && (ppiVar5 <= (int **)((int)ppiVar4 + (int)piVar6))) {
      m_Do_printf::OSReport(_365,0x39d);
      return (undefined *)0xffffffff;
    }
    iVar1 = iVar1 + (int)piVar6;
    puVar2 = (undefined *)((int)piVar6 + (int)((int)puVar2 + -0x20));
  } while ((0 < iVar1) && (ppiVar4 = ppiVar5, iVar1 <= *piVar3));
  m_Do_printf::OSReport(_363,0x3a1);
  return (undefined *)0xffffffff;
}


int OSReferentSize(int param_1)

{
  return *(int *)(param_1 + -0x18) + -0x20;
}


void OSDumpHeap(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  m_Do_printf::OSReport(_385,param_1);
  piVar2 = (int *)(HeapArray + param_1 * 0xc);
  if (*piVar2 < 0) {
    m_Do_printf::OSReport(_386);
  }
  else {
    m_Do_printf::OSReport(_387);
    m_Do_printf::OSReport(_388);
    for (puVar1 = (undefined4 *)piVar2[2]; puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[1]) {
      m_Do_printf::OSReport(_389,puVar1,puVar1[2],(int)puVar1 + puVar1[2],*puVar1,puVar1[1]);
    }
    m_Do_printf::OSReport(_390);
    for (puVar1 = (undefined4 *)piVar2[1]; puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[1]) {
      m_Do_printf::OSReport(_389,puVar1,puVar1[2],(int)puVar1 + puVar1[2],*puVar1,puVar1[1]);
    }
  }
  return;
}

