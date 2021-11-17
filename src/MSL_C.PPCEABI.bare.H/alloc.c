#include <MSL_C.PPCEABI.bare.H/alloc.h>
#include <MSL_C.PPCEABI.bare.H/alloc.h>
#include <Runtime.PPCEABI.H/GCN_mem_alloc.h>


namespace MSL_C.PPCEABI.bare.H {
undefined4 protopool$192;
undefined1 init$193;

void free(void *__ptr)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  bool bVar4;
  
  if (init_193 == '\0') {
    FUN_800033a8((int)&protopool_192,0,0x34);
    init_193 = '\x01';
  }
  if (__ptr != (void *)0x0) {
    if ((*(uint *)((int)__ptr + -4) & 1) == 0) {
      uVar3 = *(uint *)(*(uint *)((int)__ptr + -4) + 8);
    }
    else {
      uVar3 = (*(uint *)((int)__ptr + -8) & 0xfffffff8) - 8;
    }
    if (uVar3 < 0x45) {
      deallocate_from_fixed_pools(&protopool_192,__ptr);
    }
    else {
      piVar1 = (int *)(*(uint *)((int)__ptr + -4) & 0xfffffffe);
      Block_link(piVar1,(int)__ptr + -8);
      bVar4 = false;
      if (((piVar1[4] & 2U) == 0) && ((piVar1[4] & 0xfffffff8U) == (piVar1[3] & 0xfffffff8U) - 0x18)
         ) {
        bVar4 = true;
      }
      if (bVar4) {
        piVar2 = (int *)piVar1[1];
        if (piVar2 == piVar1) {
          piVar2 = (int *)0x0;
        }
        if (protopool_192 == piVar1) {
          protopool_192 = piVar2;
        }
        if (piVar2 != (int *)0x0) {
          *piVar2 = *piVar1;
          *(int **)(*piVar2 + 4) = piVar2;
        }
        piVar1[1] = 0;
        *piVar1 = 0;
        Runtime.PPCEABI.H::__sys_free(piVar1);
      }
    }
  }
  return;
}


void deallocate_from_fixed_pools(int **param_1,int **param_2,uint param_3)

{
  uint *puVar1;
  int **ppiVar2;
  int **ppiVar3;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  int iVar7;
  
  iVar7 = 0;
  for (puVar1 = &fix_pool_sizes; *puVar1 < param_3; puVar1 = puVar1 + 1) {
    iVar7 = iVar7 + 1;
  }
  ppiVar2 = (int **)param_2[-1];
  ppiVar3 = param_1 + iVar7 * 2 + 1;
  if (ppiVar2[3] == (int *)0x0) {
    if ((int **)ppiVar3[1] != ppiVar2) {
      if ((int **)*ppiVar3 == ppiVar2) {
        ppiVar3[1] = (int *)*ppiVar3[1];
        *ppiVar3 = (int *)**ppiVar3;
      }
      else {
        (*ppiVar2)[1] = (int)ppiVar2[1];
        *ppiVar2[1] = (int)*ppiVar2;
        ppiVar2[1] = ppiVar3[1];
        *ppiVar2 = (int *)*ppiVar2[1];
        (*ppiVar2)[1] = (int)ppiVar2;
        *ppiVar2[1] = (int)ppiVar2;
        ppiVar3[1] = (int *)ppiVar2;
      }
    }
  }
  *param_2 = ppiVar2[3];
  ppiVar2[3] = (int *)(param_2 + -1);
  piVar5 = ppiVar2[4];
  ppiVar2[4] = (int *)((int)piVar5 + -1);
  if ((int *)((int)piVar5 + -1) == (int *)0x0) {
    if ((int **)ppiVar3[1] == ppiVar2) {
      ppiVar3[1] = ppiVar2[1];
    }
    if ((int **)*ppiVar3 == ppiVar2) {
      *ppiVar3 = *ppiVar2;
    }
    (*ppiVar2)[1] = (int)ppiVar2[1];
    *ppiVar2[1] = (int)*ppiVar2;
    if ((int **)ppiVar3[1] == ppiVar2) {
      ppiVar3[1] = (int *)0x0;
    }
    if ((int **)*ppiVar3 == ppiVar2) {
      *ppiVar3 = (int *)0x0;
    }
    piVar5 = (int *)((uint)ppiVar2[-1] & 0xfffffffe);
    Block_link(piVar5,ppiVar2 + -2);
    bVar6 = false;
    if (((piVar5[4] & 2U) == 0) && ((piVar5[4] & 0xfffffff8U) == (piVar5[3] & 0xfffffff8U) - 0x18))
    {
      bVar6 = true;
    }
    if (bVar6) {
      piVar4 = (int *)piVar5[1];
      if (piVar4 == piVar5) {
        piVar4 = (int *)0x0;
      }
      if (*param_1 == piVar5) {
        *param_1 = piVar4;
      }
      if (piVar4 != (int *)0x0) {
        *piVar4 = *piVar5;
        *(int **)(*piVar4 + 4) = piVar4;
      }
      piVar5[1] = 0;
      *piVar5 = 0;
      Runtime.PPCEABI.H::__sys_free(piVar5);
    }
  }
  return;
}


void SubBlock_merge_next(uint *param_1,uint **param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *param_1 & 0xfffffff8;
  puVar1 = (uint *)((int)param_1 + uVar3);
  uVar2 = *puVar1;
  if ((uVar2 & 2) != 0) {
    return;
  }
  *param_1 = *param_1 & 7;
  uVar3 = uVar3 + (uVar2 & 0xfffffff8);
  *param_1 = *param_1 | uVar3;
  if ((*param_1 & 2) == 0) {
    *(uint *)((int)param_1 + (uVar3 - 4)) = uVar3;
  }
  if ((*param_1 & 2) == 0) {
    *(uint *)((int)param_1 + uVar3) = *(uint *)((int)param_1 + uVar3) & 0xfffffffb;
  }
  else {
    *(uint *)((int)param_1 + uVar3) = *(uint *)((int)param_1 + uVar3) | 4;
  }
  if (*param_2 == puVar1) {
    *param_2 = (uint *)(*param_2)[3];
  }
  if (*param_2 == puVar1) {
    *param_2 = (uint *)0x0;
  }
  *(uint *)(puVar1[3] + 8) = puVar1[2];
  *(uint *)(puVar1[2] + 0xc) = puVar1[3];
  return;
}


void Block_link(int param_1,uint *param_2)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint **ppuVar5;
  
  uVar4 = *param_2 & 0xfffffff8;
  *param_2 = *param_2 & 0xfffffffd;
  puVar3 = (uint *)((int)param_2 + uVar4);
  *puVar3 = *puVar3 & 0xfffffffb;
  puVar3[-1] = uVar4;
  ppuVar5 = (uint **)(param_1 + ((*(uint *)(param_1 + 0xc) & 0xfffffff8) - 4));
  if (*ppuVar5 == (uint *)0x0) {
    *ppuVar5 = param_2;
    param_2[2] = (uint)param_2;
    param_2[3] = (uint)param_2;
  }
  else {
    param_2[2] = (*ppuVar5)[2];
    *(uint **)(param_2[2] + 0xc) = param_2;
    param_2[3] = (uint)*ppuVar5;
    (*ppuVar5)[2] = (uint)param_2;
    *ppuVar5 = param_2;
    puVar3 = *ppuVar5;
    if (((*puVar3 & 4) == 0) && (uVar4 = puVar3[-1], (uVar4 & 2) == 0)) {
      puVar2 = (uint *)((int)puVar3 - uVar4);
      *puVar2 = *puVar2 & 7;
      *puVar2 = *puVar2 | uVar4 + (*puVar3 & 0xfffffff8) & 0xfffffff8;
      if ((*puVar2 & 2) == 0) {
        iVar1 = uVar4 + (*puVar3 & 0xfffffff8);
        *(int *)((int)puVar2 + iVar1 + -4) = iVar1;
      }
      if (*ppuVar5 == puVar3) {
        *ppuVar5 = (uint *)(*ppuVar5)[3];
      }
      *(uint *)(puVar3[3] + 8) = puVar3[2];
      *(uint *)(*(int *)(puVar3[3] + 8) + 0xc) = puVar3[3];
      puVar3 = puVar2;
    }
    *ppuVar5 = puVar3;
    SubBlock_merge_next(*ppuVar5,ppuVar5);
  }
  if (*(uint *)(param_1 + 8) < (**ppuVar5 & 0xfffffff8)) {
    *(uint *)(param_1 + 8) = **ppuVar5 & 0xfffffff8;
  }
  return;
}

