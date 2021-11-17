#include <gd/GDGeometry.h>
#include <gd/GDBase.h>


namespace gd {

void GDSetVtxDescv(undefined4 *param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  
  iVar18 = 0;
  uVar17 = 0;
  iVar16 = 0;
  uVar15 = 0;
  uVar14 = 0;
  iVar13 = 1;
  iVar12 = 0;
  iVar11 = 0;
  iVar10 = 0;
  uVar9 = 0;
  iVar8 = 0;
  iVar7 = 0;
  iVar6 = 0;
  iVar5 = 0;
  iVar4 = 0;
  iVar3 = 0;
  iVar2 = 0;
  do {
    switch(*param_1) {
    case 0:
      uVar15 = param_1[1];
      break;
    case 1:
      uVar14 = uVar14 & 0xfffffffe | param_1[1];
      break;
    case 2:
      uVar14 = uVar14 & 0xfffffffd | param_1[1] << 1;
      break;
    case 3:
      uVar14 = uVar14 & 0xfffffffb | param_1[1] << 2;
      break;
    case 4:
      uVar14 = uVar14 & 0xfffffff7 | param_1[1] << 3;
      break;
    case 5:
      uVar14 = uVar14 & 0xffffffef | param_1[1] << 4;
      break;
    case 6:
      uVar14 = uVar14 & 0xffffffdf | param_1[1] << 5;
      break;
    case 7:
      uVar14 = uVar14 & 0xffffffbf | param_1[1] << 6;
      break;
    case 8:
      uVar14 = uVar14 & 0xffffff7f | param_1[1] << 7;
      break;
    case 9:
      iVar13 = param_1[1];
      break;
    case 10:
      if (param_1[1] != 0) {
        iVar18 = 1;
        iVar12 = param_1[1];
      }
      break;
    case 0xb:
      iVar11 = param_1[1];
      uVar17 = uVar17 + (iVar11 != 0);
      break;
    case 0xc:
      iVar10 = param_1[1];
      uVar17 = uVar17 + (iVar10 != 0);
      break;
    case 0xd:
      uVar9 = param_1[1];
      iVar16 = iVar16 + (uint)(uVar9 != 0);
      break;
    case 0xe:
      iVar8 = param_1[1];
      iVar16 = iVar16 + (uint)(iVar8 != 0);
      break;
    case 0xf:
      iVar7 = param_1[1];
      iVar16 = iVar16 + (uint)(iVar7 != 0);
      break;
    case 0x10:
      iVar6 = param_1[1];
      iVar16 = iVar16 + (uint)(iVar6 != 0);
      break;
    case 0x11:
      iVar5 = param_1[1];
      iVar16 = iVar16 + (uint)(iVar5 != 0);
      break;
    case 0x12:
      iVar4 = param_1[1];
      iVar16 = iVar16 + (uint)(iVar4 != 0);
      break;
    case 0x13:
      iVar3 = param_1[1];
      iVar16 = iVar16 + (uint)(iVar3 != 0);
      break;
    case 0x14:
      iVar2 = param_1[1];
      iVar16 = iVar16 + (uint)(iVar2 != 0);
      break;
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
      break;
    case 0x19:
      if (param_1[1] != 0) {
        iVar18 = 2;
        iVar12 = param_1[1];
      }
      break;
    default:
      if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 1U) {
        GDOverflowed();
      }
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = 8;
      if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 1U) {
        GDOverflowed();
      }
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = 0x50;
      if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 4U) {
        GDOverflowed();
      }
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      uVar15 = uVar15 | uVar14 << 1;
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      uVar14 = iVar10 << 0xf | iVar11 << 0xd | iVar12 << 0xb | iVar13 << 9 | uVar15;
      *puVar1 = (char)(uVar14 >> 0x18);
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = (char)(uVar14 >> 0x10);
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = (char)(uVar14 >> 8);
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = (char)uVar15;
      if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 1U) {
        GDOverflowed();
      }
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = 8;
      if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 1U) {
        GDOverflowed();
      }
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = 0x60;
      if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 4U) {
        GDOverflowed();
      }
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      uVar15 = iVar6 << 6 | iVar7 << 4 | uVar9 | iVar8 << 2;
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      uVar9 = iVar2 << 0xe | iVar3 << 0xc | iVar4 << 10 | iVar5 << 8 | uVar15;
      *puVar1 = (char)(uVar9 >> 0x18);
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = (char)(uVar9 >> 0x10);
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = (char)(uVar9 >> 8);
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = (char)uVar15;
      if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 1U) {
        GDOverflowed();
      }
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = 0x10;
      if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 2U) {
        GDOverflowed();
      }
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = 0;
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = 0;
      if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 2U) {
        GDOverflowed();
      }
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = 0x10;
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = 8;
      if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 4U) {
        GDOverflowed();
      }
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      uVar15 = iVar16 << 4 | uVar17 | iVar18 << 2;
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = (char)(uVar15 >> 0x18);
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = (char)(uVar15 >> 0x10);
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = (char)(uVar15 >> 8);
      puVar1 = *(undefined **)(__GDCurrentDL + 8);
      *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
      *puVar1 = (char)uVar15;
      return;
    }
    param_1 = param_1 + 2;
  } while( true );
}


void GDSetArray(int param_1,int param_2,undefined param_3)

{
  undefined *puVar1;
  char *pcVar2;
  char cVar3;
  
  if (param_1 == 0x19) {
    cVar3 = '\x01';
  }
  else {
    cVar3 = (char)param_1 + -9;
  }
  if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 1U) {
    GDOverflowed();
  }
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 8;
  if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 1U) {
    GDOverflowed();
  }
  pcVar2 = *(char **)(__GDCurrentDL + 8);
  *(char **)(__GDCurrentDL + 8) = pcVar2 + 1;
  *pcVar2 = cVar3 + -0x60;
  if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 4U) {
    GDOverflowed();
  }
  param_2 = param_2 + -0x80000000;
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)param_2 >> 0x18);
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)param_2 >> 0x10);
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)param_2 >> 8);
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)param_2;
  if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 1U) {
    GDOverflowed();
  }
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 8;
  if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 1U) {
    GDOverflowed();
  }
  pcVar2 = *(char **)(__GDCurrentDL + 8);
  *(char **)(__GDCurrentDL + 8) = pcVar2 + 1;
  *pcVar2 = cVar3 + -0x50;
  if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 4U) {
    GDOverflowed();
  }
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = param_3;
  return;
}


void GDSetArrayRaw(int param_1,undefined4 param_2,undefined param_3)

{
  undefined *puVar1;
  char *pcVar2;
  char cVar3;
  
  if (param_1 == 0x19) {
    cVar3 = '\x01';
  }
  else {
    cVar3 = (char)param_1 + -9;
  }
  if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 1U) {
    GDOverflowed();
  }
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 8;
  if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 1U) {
    GDOverflowed();
  }
  pcVar2 = *(char **)(__GDCurrentDL + 8);
  *(char **)(__GDCurrentDL + 8) = pcVar2 + 1;
  *pcVar2 = cVar3 + -0x60;
  if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 4U) {
    GDOverflowed();
  }
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)param_2 >> 0x18);
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)param_2 >> 0x10);
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)((uint)param_2 >> 8);
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = (char)param_2;
  if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 1U) {
    GDOverflowed();
  }
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 8;
  if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 1U) {
    GDOverflowed();
  }
  pcVar2 = *(char **)(__GDCurrentDL + 8);
  *(char **)(__GDCurrentDL + 8) = pcVar2 + 1;
  *pcVar2 = cVar3 + -0x50;
  if (*(uint *)(__GDCurrentDL + 0xc) < *(int *)(__GDCurrentDL + 8) + 4U) {
    GDOverflowed();
  }
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = 0;
  puVar1 = *(undefined **)(__GDCurrentDL + 8);
  *(undefined **)(__GDCurrentDL + 8) = puVar1 + 1;
  *puVar1 = param_3;
  return;
}

