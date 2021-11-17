#include <MSL_C.PPCEABI.bare.H/mem_funcs.h>


namespace MSL_C.PPCEABI.bare.H {

void __copy_longs_rev_unaligned(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  
  puVar9 = (uint *)(param_1 + param_3);
  puVar6 = (undefined *)(param_2 + param_3);
  uVar2 = (uint)puVar9 & 3;
  if (uVar2 != 0) {
    param_3 = param_3 - uVar2;
    do {
      puVar6 = puVar6 + -1;
      uVar2 = uVar2 - 1;
      puVar9 = (uint *)((int)puVar9 + -1);
      *(undefined *)puVar9 = *puVar6;
    } while (uVar2 != 0);
  }
  iVar4 = ((uint)puVar6 & 3) * 8;
  iVar5 = ((uint)puVar6 & 3) * -8 + 0x20;
  uVar2 = param_3 >> 3;
  uVar3 = *(uint *)(puVar6 + -((uint)puVar6 & 3));
  puVar8 = (uint *)(puVar6 + -((uint)puVar6 & 3));
  do {
    puVar10 = puVar9;
    puVar7 = puVar8;
    uVar1 = puVar7[-1];
    uVar2 = uVar2 - 1;
    puVar10[-1] = uVar1 << iVar4 | uVar3 >> iVar5;
    puVar8 = puVar7 + -2;
    uVar3 = *puVar8;
    puVar9 = puVar10 + -2;
    *puVar9 = uVar3 << iVar4 | uVar1 >> iVar5;
  } while (uVar2 != 0);
  if ((param_3 & 4) != 0) {
    puVar8 = puVar7 + -3;
    puVar9 = puVar10 + -3;
    *puVar9 = *puVar8 << iVar4 | uVar3 >> iVar5;
  }
  param_3 = param_3 & 3;
  if (param_3 == 0) {
    return;
  }
  puVar6 = (undefined *)((int)puVar8 + ((uint)puVar6 & 3));
  do {
    puVar6 = puVar6 + -1;
    param_3 = param_3 - 1;
    puVar9 = (uint *)((int)puVar9 + -1);
    *(undefined *)puVar9 = *puVar6;
  } while (param_3 != 0);
  return;
}


void __copy_longs_unaligned(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  undefined *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  
  puVar8 = (undefined *)(param_2 + -1);
  uVar5 = -param_1 & 3;
  puVar2 = (undefined *)(param_1 + -1);
  if (uVar5 != 0) {
    param_3 = param_3 - uVar5;
    do {
      puVar8 = puVar8 + 1;
      uVar5 = uVar5 - 1;
      puVar2 = puVar2 + 1;
      *puVar2 = *puVar8;
    } while (uVar5 != 0);
  }
  uVar1 = (uint)(puVar8 + 1) & 3;
  uVar5 = param_3 >> 3;
  uVar11 = (int)(puVar8 + 1) * 8 & 0x18;
  uVar4 = *(uint *)(puVar8 + (1 - uVar1));
  iVar12 = 0x20 - uVar11;
  puVar7 = (uint *)(puVar2 + -3);
  puVar10 = (uint *)(puVar8 + (1 - uVar1));
  do {
    puVar9 = puVar10;
    puVar6 = puVar7;
    uVar3 = puVar9[1];
    uVar5 = uVar5 - 1;
    puVar6[1] = uVar4 << uVar11 | uVar3 >> iVar12;
    puVar10 = puVar9 + 2;
    uVar4 = *puVar10;
    puVar7 = puVar6 + 2;
    *puVar7 = uVar3 << uVar11 | uVar4 >> iVar12;
  } while (uVar5 != 0);
  if ((param_3 & 4) != 0) {
    puVar10 = puVar9 + 3;
    puVar7 = puVar6 + 3;
    *puVar7 = uVar4 << uVar11 | *puVar10 >> iVar12;
  }
  param_3 = param_3 & 3;
  puVar8 = (undefined *)((int)puVar7 + 3);
  if (param_3 == 0) {
    return;
  }
  puVar2 = (undefined *)((int)puVar10 + (3 - (4 - uVar1)));
  do {
    puVar2 = puVar2 + 1;
    param_3 = param_3 - 1;
    puVar8 = puVar8 + 1;
    *puVar8 = *puVar2;
  } while (param_3 != 0);
  return;
}


void __copy_longs_rev_aligned(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(param_1 + param_3);
  puVar2 = (undefined4 *)(param_2 + param_3);
  uVar1 = (uint)puVar3 & 3;
  if (uVar1 != 0) {
    param_3 = param_3 - uVar1;
    do {
      puVar2 = (undefined4 *)((int)puVar2 + -1);
      uVar1 = uVar1 - 1;
      puVar3 = (undefined4 *)((int)puVar3 + -1);
      *(undefined *)puVar3 = *(undefined *)puVar2;
    } while (uVar1 != 0);
  }
  for (uVar1 = param_3 >> 5; uVar1 != 0; uVar1 = uVar1 - 1) {
    puVar3[-1] = puVar2[-1];
    puVar3[-2] = puVar2[-2];
    puVar3[-3] = puVar2[-3];
    puVar3[-4] = puVar2[-4];
    puVar3[-5] = puVar2[-5];
    puVar3[-6] = puVar2[-6];
    puVar3[-7] = puVar2[-7];
    puVar2 = puVar2 + -8;
    puVar3 = puVar3 + -8;
    *puVar3 = *puVar2;
  }
  for (uVar1 = param_3 >> 2 & 7; uVar1 != 0; uVar1 = uVar1 - 1) {
    puVar2 = puVar2 + -1;
    puVar3 = puVar3 + -1;
    *puVar3 = *puVar2;
  }
  param_3 = param_3 & 3;
  if (param_3 != 0) {
    do {
      puVar2 = (undefined4 *)((int)puVar2 + -1);
      param_3 = param_3 - 1;
      puVar3 = (undefined4 *)((int)puVar3 + -1);
      *(undefined *)puVar3 = *(undefined *)puVar2;
    } while (param_3 != 0);
    return;
  }
  return;
}


void __copy_longs_aligned(int param_1,int param_2,uint param_3)

{
  undefined *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  
  puVar5 = (undefined *)(param_2 + -1);
  uVar3 = -param_1 & 3;
  puVar1 = (undefined *)(param_1 + -1);
  if (uVar3 != 0) {
    param_3 = param_3 - uVar3;
    do {
      puVar5 = puVar5 + 1;
      uVar3 = uVar3 - 1;
      puVar1 = puVar1 + 1;
      *puVar1 = *puVar5;
    } while (uVar3 != 0);
  }
  puVar4 = (undefined4 *)(puVar5 + -3);
  puVar2 = (undefined4 *)(puVar1 + -3);
  for (uVar3 = param_3 >> 5; uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2[1] = puVar4[1];
    puVar2[2] = puVar4[2];
    puVar2[3] = puVar4[3];
    puVar2[4] = puVar4[4];
    puVar2[5] = puVar4[5];
    puVar2[6] = puVar4[6];
    puVar2[7] = puVar4[7];
    puVar4 = puVar4 + 8;
    puVar2 = puVar2 + 8;
    *puVar2 = *puVar4;
  }
  for (uVar3 = param_3 >> 2 & 7; uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar4 = puVar4 + 1;
    puVar2 = puVar2 + 1;
    *puVar2 = *puVar4;
  }
  puVar5 = (undefined *)((int)puVar4 + 3);
  param_3 = param_3 & 3;
  puVar1 = (undefined *)((int)puVar2 + 3);
  if (param_3 != 0) {
    do {
      puVar5 = puVar5 + 1;
      param_3 = param_3 - 1;
      puVar1 = puVar1 + 1;
      *puVar1 = *puVar5;
    } while (param_3 != 0);
    return;
  }
  return;
}

