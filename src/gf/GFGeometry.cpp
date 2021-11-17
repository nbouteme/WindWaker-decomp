#include <gf/GFGeometry.h>
#include <Runtime.PPCEABI.H/runtime.h>


namespace gf {

/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __stdcall GFSetVtxDescv(_GXVtxDescList *) */

void GFSetVtxDescv(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  
  iVar1 = 0;
  uVar2 = 0;
  iVar3 = 0;
  uVar4 = 0;
  uVar5 = 0;
  iVar6 = 1;
  iVar7 = 0;
  iVar8 = 0;
  iVar9 = 0;
  uVar17 = 0;
  iVar16 = 0;
  iVar15 = 0;
  iVar14 = 0;
  iVar13 = 0;
  iVar12 = 0;
  iVar11 = 0;
  iVar10 = 0;
  do {
    switch(*param_1) {
    case 0:
      uVar4 = param_1[1];
      break;
    case 1:
      uVar5 = uVar5 & 0xfffffffe | param_1[1];
      break;
    case 2:
      uVar5 = uVar5 & 0xfffffffd | param_1[1] << 1;
      break;
    case 3:
      uVar5 = uVar5 & 0xfffffffb | param_1[1] << 2;
      break;
    case 4:
      uVar5 = uVar5 & 0xfffffff7 | param_1[1] << 3;
      break;
    case 5:
      uVar5 = uVar5 & 0xffffffef | param_1[1] << 4;
      break;
    case 6:
      uVar5 = uVar5 & 0xffffffdf | param_1[1] << 5;
      break;
    case 7:
      uVar5 = uVar5 & 0xffffffbf | param_1[1] << 6;
      break;
    case 8:
      uVar5 = uVar5 & 0xffffff7f | param_1[1] << 7;
      break;
    case 9:
      iVar6 = param_1[1];
      break;
    case 10:
      if (param_1[1] != 0) {
        iVar1 = 1;
        iVar7 = param_1[1];
      }
      break;
    case 0xb:
      iVar8 = param_1[1];
      uVar2 = uVar2 + (iVar8 != 0);
      break;
    case 0xc:
      iVar9 = param_1[1];
      uVar2 = uVar2 + (iVar9 != 0);
      break;
    case 0xd:
      uVar17 = param_1[1];
      iVar3 = iVar3 + (uint)(uVar17 != 0);
      break;
    case 0xe:
      iVar16 = param_1[1];
      iVar3 = iVar3 + (uint)(iVar16 != 0);
      break;
    case 0xf:
      iVar15 = param_1[1];
      iVar3 = iVar3 + (uint)(iVar15 != 0);
      break;
    case 0x10:
      iVar14 = param_1[1];
      iVar3 = iVar3 + (uint)(iVar14 != 0);
      break;
    case 0x11:
      iVar13 = param_1[1];
      iVar3 = iVar3 + (uint)(iVar13 != 0);
      break;
    case 0x12:
      iVar12 = param_1[1];
      iVar3 = iVar3 + (uint)(iVar12 != 0);
      break;
    case 0x13:
      iVar11 = param_1[1];
      iVar3 = iVar3 + (uint)(iVar11 != 0);
      break;
    case 0x14:
      iVar10 = param_1[1];
      iVar3 = iVar3 + (uint)(iVar10 != 0);
      break;
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x18:
      break;
    case 0x19:
      if (param_1[1] != 0) {
        iVar1 = 2;
        iVar7 = param_1[1];
      }
      break;
    default:
      write_volatile_1(DAT_cc008000,8);
      write_volatile_1(DAT_cc008000,0x50);
      write_volatile_4(0xcc008000,
                       iVar9 << 0xf | iVar8 << 0xd | iVar7 << 0xb | iVar6 << 9 | uVar4 | uVar5 << 1)
      ;
      write_volatile_1(DAT_cc008000,8);
      write_volatile_1(DAT_cc008000,0x60);
      write_volatile_4(0xcc008000,
                       iVar10 << 0xe |
                       iVar11 << 0xc |
                       iVar12 << 10 | iVar13 << 8 | iVar14 << 6 | iVar15 << 4 | uVar17 | iVar16 << 2
                      );
      write_volatile_1(DAT_cc008000,0x10);
      write_volatile_2(0xcc008000,0);
      write_volatile_2(0xcc008000,0x1008);
      write_volatile_4(0xcc008000,iVar3 << 4 | uVar2 | iVar1 << 2);
      return;
    }
    param_1 = param_1 + 2;
  } while( true );
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* __stdcall GFSetVtxAttrFmtv(_GXVtxFmt,
                              _GXVtxAttrFmtList *) */

void GFSetVtxAttrFmtv(char param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  uint uVar25;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  uint local_84;
  int local_80;
  uint local_7c;
  uint local_58;
  
  local_7c = 1;
  local_80 = 4;
  local_84 = 0;
  iVar1 = 0;
  local_88 = 4;
  iVar2 = 0;
  local_8c = 1;
  local_90 = 5;
  local_94 = 1;
  local_98 = 5;
  iVar8 = 1;
  iVar9 = 4;
  uVar3 = 0;
  local_58 = 1;
  iVar4 = 4;
  uVar5 = 0;
  iVar6 = 1;
  iVar7 = 4;
  uVar25 = 0;
  iVar24 = 1;
  iVar23 = 4;
  uVar22 = 0;
  iVar21 = 1;
  iVar20 = 4;
  uVar19 = 0;
  iVar18 = 1;
  iVar17 = 4;
  uVar16 = 0;
  iVar15 = 1;
  iVar14 = 4;
  uVar13 = 0;
  iVar12 = 1;
  iVar11 = 4;
  uVar10 = 0;
  for (; *param_2 != 0xff; param_2 = param_2 + 4) {
    switch(*param_2) {
    case 9:
      local_7c = param_2[1];
      local_80 = param_2[2];
      local_84 = (uint)*(byte *)(param_2 + 3);
      break;
    case 10:
    case 0x19:
      local_88 = param_2[2];
      iVar1 = param_2[1];
      if (iVar1 == 2) {
        iVar1 = 1;
        iVar2 = 1;
      }
      else {
        iVar2 = 0;
      }
      break;
    case 0xb:
      local_8c = param_2[1];
      local_90 = param_2[2];
      break;
    case 0xc:
      local_94 = param_2[1];
      local_98 = param_2[2];
      break;
    case 0xd:
      iVar8 = param_2[1];
      iVar9 = param_2[2];
      uVar3 = (uint)*(byte *)(param_2 + 3);
      break;
    case 0xe:
      local_58 = param_2[1];
      iVar4 = param_2[2];
      uVar5 = (uint)*(byte *)(param_2 + 3);
      break;
    case 0xf:
      iVar6 = param_2[1];
      iVar7 = param_2[2];
      uVar25 = (uint)*(byte *)(param_2 + 3);
      break;
    case 0x10:
      iVar24 = param_2[1];
      iVar23 = param_2[2];
      uVar22 = (uint)*(byte *)(param_2 + 3);
      break;
    case 0x11:
      iVar21 = param_2[1];
      iVar20 = param_2[2];
      uVar19 = (uint)*(byte *)(param_2 + 3);
      break;
    case 0x12:
      iVar18 = param_2[1];
      iVar17 = param_2[2];
      uVar16 = (uint)*(byte *)(param_2 + 3);
      break;
    case 0x13:
      iVar15 = param_2[1];
      iVar14 = param_2[2];
      uVar13 = (uint)*(byte *)(param_2 + 3);
      break;
    case 0x14:
      iVar12 = param_2[1];
      iVar11 = param_2[2];
      uVar10 = (uint)*(byte *)(param_2 + 3);
    }
  }
  write_volatile_1(DAT_cc008000,8);
  write_volatile_1(DAT_cc008000,param_1 + 'p');
  write_volatile_4(0xcc008000,
                   iVar2 << 0x1f |
                   uVar3 << 0x19 |
                   iVar9 << 0x16 |
                   iVar8 << 0x15 |
                   local_98 << 0x12 |
                   local_94 << 0x11 |
                   local_90 << 0xe |
                   local_8c << 0xd |
                   local_88 << 10 | iVar1 << 9 | local_84 << 4 | local_7c | local_80 << 1 |
                   0x40000000);
  write_volatile_1(DAT_cc008000,8);
  write_volatile_1(DAT_cc008000,param_1 + -0x80);
  write_volatile_4(0xcc008000,
                   iVar20 << 0x1c |
                   iVar21 << 0x1b |
                   uVar22 << 0x16 |
                   iVar23 << 0x13 |
                   iVar24 << 0x12 |
                   uVar25 << 0xd | iVar7 << 10 | iVar6 << 9 | uVar5 << 4 | local_58 | iVar4 << 1 |
                   0x80000000);
  write_volatile_1(DAT_cc008000,8);
  write_volatile_1(DAT_cc008000,param_1 + -0x70);
  write_volatile_4(0xcc008000,
                   uVar10 << 0x1b |
                   iVar11 << 0x18 |
                   iVar12 << 0x17 |
                   uVar13 << 0x12 |
                   iVar14 << 0xf | iVar15 << 0xe | uVar16 << 9 | iVar17 << 6 | uVar19 | iVar18 << 5)
  ;
  return;
}


/* __stdcall GFSetArray(_GXAttr,
                        void *,
                        unsigned char) */

void GFSetArray(GXAttr param_1,int param_2,uint param_3)

{
  char cVar1;
  
  cVar1 = '\x01';
  if (param_1 != GX_VA_NBT) {
    cVar1 = (char)param_1 + -9;
  }
  write_volatile_1(DAT_cc008000,8);
  write_volatile_1(DAT_cc008000,cVar1 + -0x60);
  write_volatile_4(0xcc008000,param_2 + -0x80000000);
  write_volatile_1(DAT_cc008000,8);
  write_volatile_1(DAT_cc008000,cVar1 + -0x50);
  write_volatile_4(0xcc008000,param_3 & 0xff);
  return;
}


/* __stdcall GFSetCullMode(_GXCullMode) */

void GFSetCullMode(int param_1)

{
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,0xfe00c000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,(uint)(byte)(&cm2hw_488)[param_1] << 0xe);
  return;
}

