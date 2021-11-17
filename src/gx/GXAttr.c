#include <gx/GXAttr.h>
#include <gx/GXAttr.h>
#include <gx/GXTransform.h>


namespace gx {

void __GXXfVtxSpecs(void)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)(gx + 0x41d) == '\0') {
    if (*(char *)(gx + 0x41c) == '\0') {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  else {
    iVar1 = 2;
  }
  uVar2 = *(uint *)(gx + 0x18);
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,0x1008);
  write_volatile_4(0xcc008000,
                   ((uint)((uVar2 & 3) != 0) + (uint)((uVar2 >> 2 & 3) != 0) +
                    (uint)((uVar2 >> 4 & 3) != 0) + (uint)((uVar2 >> 6 & 3) != 0) +
                    (uint)((uVar2 >> 8 & 3) != 0) + (uint)((uVar2 >> 10 & 3) != 0) +
                    (uint)((uVar2 >> 0xc & 3) != 0) + (uint)((uVar2 >> 0xe & 3) != 0)) * 0x10 |
                   (uint)((*(uint *)(gx + 0x14) >> 0xd & 3) != 0) +
                   (uint)((*(uint *)(gx + 0x14) >> 0xf & 3) != 0) | iVar1 << 2);
  *(undefined2 *)(gx + 2) = 1;
  return;
}


void GXSetVtxDesc(GXAttr param_1,GXAttrType param_2)

{
  int iVar1;
  
  iVar1 = gx;
  switch(param_1) {
  case GX_VA_PNMTXIDX:
    *(uint *)(gx + 0x14) = *(uint *)(gx + 0x14) & 0xfffffffe | param_2;
    break;
  case GX_VA_TEX0MTXIDX:
    *(GXAttrType *)(gx + 0x14) = *(uint *)(gx + 0x14) & 0xfffffffd | param_2 << 1;
    break;
  case GX_VA_TEX1MTXIDX:
    *(GXAttrType *)(gx + 0x14) = *(uint *)(gx + 0x14) & 0xfffffffb | param_2 << 2;
    break;
  case GX_VA_TEX2MTXIDX:
    *(GXAttrType *)(gx + 0x14) = *(uint *)(gx + 0x14) & 0xfffffff7 | param_2 << 3;
    break;
  case GX_VA_TEX3MTXIDX:
    *(GXAttrType *)(gx + 0x14) = *(uint *)(gx + 0x14) & 0xffffffef | param_2 << 4;
    break;
  case GX_VA_TEX4MTXIDX:
    *(GXAttrType *)(gx + 0x14) = *(uint *)(gx + 0x14) & 0xffffffdf | param_2 << 5;
    break;
  case GX_VA_TEX5MTXIDX:
    *(GXAttrType *)(gx + 0x14) = *(uint *)(gx + 0x14) & 0xffffffbf | param_2 << 6;
    break;
  case GX_VA_TEX6MTXIDX:
    *(GXAttrType *)(gx + 0x14) = *(uint *)(gx + 0x14) & 0xffffff7f | param_2 << 7;
    break;
  case GX_VA_TEX7MTXIDX:
    *(GXAttrType *)(gx + 0x14) = *(uint *)(gx + 0x14) & 0xfffffeff | param_2 << 8;
    break;
  case GX_VA_POS:
    *(GXAttrType *)(gx + 0x14) = *(uint *)(gx + 0x14) & 0xfffff9ff | param_2 << 9;
    break;
  case GX_VA_NRM:
    if (param_2 == GX_NONE) {
      *(undefined *)(gx + 0x41c) = 0;
    }
    else {
      *(undefined *)(gx + 0x41c) = 1;
      *(undefined *)(iVar1 + 0x41d) = 0;
      *(GXAttrType *)(iVar1 + 0x418) = param_2;
    }
    break;
  case GX_VA_CLR0:
    *(GXAttrType *)(gx + 0x14) = *(uint *)(gx + 0x14) & 0xffff9fff | param_2 << 0xd;
    break;
  case GX_VA_CLR1:
    *(GXAttrType *)(gx + 0x14) = *(uint *)(gx + 0x14) & 0xfffe7fff | param_2 << 0xf;
    break;
  case GX_VA_TEX0:
    *(uint *)(gx + 0x18) = *(uint *)(gx + 0x18) & 0xfffffffc | param_2;
    break;
  case GX_VA_TEX1:
    *(GXAttrType *)(gx + 0x18) = *(uint *)(gx + 0x18) & 0xfffffff3 | param_2 << 2;
    break;
  case GX_VA_TEX2:
    *(GXAttrType *)(gx + 0x18) = *(uint *)(gx + 0x18) & 0xffffffcf | param_2 << 4;
    break;
  case GX_VA_TEX3:
    *(GXAttrType *)(gx + 0x18) = *(uint *)(gx + 0x18) & 0xffffff3f | param_2 << 6;
    break;
  case GX_VA_TEX4:
    *(GXAttrType *)(gx + 0x18) = *(uint *)(gx + 0x18) & 0xfffffcff | param_2 << 8;
    break;
  case GX_VA_TEX5:
    *(GXAttrType *)(gx + 0x18) = *(uint *)(gx + 0x18) & 0xfffff3ff | param_2 << 10;
    break;
  case GX_VA_TEX6:
    *(GXAttrType *)(gx + 0x18) = *(uint *)(gx + 0x18) & 0xffffcfff | param_2 << 0xc;
    break;
  case GX_VA_TEX7:
    *(GXAttrType *)(gx + 0x18) = *(uint *)(gx + 0x18) & 0xffff3fff | param_2 << 0xe;
    break;
  case GX_VA_NBT:
    if (param_2 == GX_NONE) {
      *(undefined *)(gx + 0x41d) = 0;
    }
    else {
      *(undefined *)(gx + 0x41d) = 1;
      *(undefined *)(iVar1 + 0x41c) = 0;
      *(GXAttrType *)(iVar1 + 0x418) = param_2;
    }
  }
  if ((*(char *)(gx + 0x41c) == '\0') && (*(char *)(gx + 0x41d) == '\0')) {
    *(uint *)(gx + 0x14) = *(uint *)(gx + 0x14) & 0xffffe7ff;
  }
  else {
    *(uint *)(gx + 0x14) = *(uint *)(gx + 0x14) & 0xffffe7ff | *(int *)(gx + 0x418) << 0xb;
  }
  *(uint *)(gx + 0x4f4) = *(uint *)(gx + 0x4f4) | 8;
  return;
}


void __GXSetVCD(void)

{
  write_volatile_1(DAT_cc008000,8);
  write_volatile_1(DAT_cc008000,0x50);
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x14));
  write_volatile_1(DAT_cc008000,8);
  write_volatile_1(DAT_cc008000,0x60);
  write_volatile_4(0xcc008000,*(undefined4 *)(gx + 0x18));
  __GXXfVtxSpecs();
  return;
}


void __GXCalculateVLim(void)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  
  if (*(short *)(gx + 4) == 0) {
    return;
  }
  uVar3 = *(uint *)(gx + 0x14);
  uVar1 = *(uint *)(gx + 0x18);
  if ((*(uint *)(gx + 0x1c) >> 9 & 1) == 1) {
    sVar2 = 3;
  }
  else {
    sVar2 = 1;
  }
  *(ushort *)(gx + 6) =
       ((ushort)uVar3 & 1) + ((ushort)(uVar3 >> 1) & 1) + ((ushort)(uVar3 >> 2) & 1) +
       ((ushort)(uVar3 >> 3) & 1) + ((ushort)(uVar3 >> 4) & 1) + ((ushort)(uVar3 >> 5) & 1) +
       ((ushort)(uVar3 >> 6) & 1) + ((ushort)(uVar3 >> 7) & 1) + ((ushort)(uVar3 >> 8) & 1) +
       (ushort)(byte)(&tbl3_229)[uVar3 >> 9 & 3] +
       (ushort)(byte)(&tbl3_229)[uVar3 >> 0xb & 3] * sVar2 +
       (ushort)(byte)(&tbl1_227)[uVar3 >> 0xd & 3] + (ushort)(byte)(&tbl1_227)[uVar3 >> 0xf & 3] +
       (ushort)(byte)(&tbl2_228)[uVar1 & 3] + (ushort)(byte)(&tbl2_228)[uVar1 >> 2 & 3] +
       (ushort)(byte)(&tbl2_228)[uVar1 >> 4 & 3] + (ushort)(byte)(&tbl2_228)[uVar1 >> 6 & 3] +
       (ushort)(byte)(&tbl2_228)[uVar1 >> 8 & 3] + (ushort)(byte)(&tbl2_228)[uVar1 >> 10 & 3] +
       (ushort)(byte)(&tbl2_228)[uVar1 >> 0xc & 3] + (ushort)(byte)(&tbl2_228)[uVar1 >> 0xe & 3];
  return;
}


void GXClearVtxDesc(void)

{
  int iVar1;
  
  iVar1 = gx;
  *(undefined4 *)(gx + 0x14) = 0;
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0xfffff9ff | 0x200;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined *)(iVar1 + 0x41c) = 0;
  *(undefined *)(iVar1 + 0x41d) = 0;
  *(uint *)(iVar1 + 0x4f4) = *(uint *)(iVar1 + 0x4f4) | 8;
  return;
}


void GXSetVtxAttrFmt(GXVtxFmt param_1,GXAttr param_2,GXCompCnt param_3,GXCompType param_4,
                        byte frac)

{
  GXCompCnt *pGVar1;
  GXCompCnt *pGVar2;
  int iVar3;
  uint *puVar4;
  
  iVar3 = gx + param_1 * 4;
  pGVar1 = (GXCompCnt *)(iVar3 + 0x1c);
  pGVar2 = (GXCompCnt *)(iVar3 + 0x3c);
  puVar4 = (uint *)(iVar3 + 0x5c);
  switch(param_2) {
  case GX_VA_POS:
    *pGVar1 = *pGVar1 & ~GX_CLR_RGBA | param_3;
    *pGVar1 = *pGVar1 & 0xfffffff1 | param_4 << 1;
    *pGVar1 = *pGVar1 & 0xfffffe0f | (uint)frac << 4;
    break;
  case GX_VA_NRM:
  case GX_VA_NBT:
    *pGVar1 = *pGVar1 & 0xffffe3ff | param_4 << 10;
    if (param_3 == GX_NRM_NBT3) {
      *pGVar1 = *pGVar1 & 0xfffffdff | 0x200;
      *pGVar1 = *pGVar1 & 0x7fffffff | 0x80000000;
    }
    else {
      *pGVar1 = *pGVar1 & 0xfffffdff | param_3 << 9;
      *pGVar1 = *pGVar1 & 0x7fffffff;
    }
    break;
  case GX_VA_CLR0:
    *pGVar1 = *pGVar1 & 0xffffdfff | param_3 << 0xd;
    *pGVar1 = *pGVar1 & 0xfffe3fff | param_4 << 0xe;
    break;
  case GX_VA_CLR1:
    *pGVar1 = *pGVar1 & 0xfffdffff | param_3 << 0x11;
    *pGVar1 = *pGVar1 & 0xffe3ffff | param_4 << 0x12;
    break;
  case GX_VA_TEX0:
    *pGVar1 = *pGVar1 & 0xffdfffff | param_3 << 0x15;
    *pGVar1 = *pGVar1 & 0xfe3fffff | param_4 << 0x16;
    *pGVar1 = *pGVar1 & 0xc1ffffff | (uint)frac << 0x19;
    break;
  case GX_VA_TEX1:
    *pGVar2 = *pGVar2 & ~GX_CLR_RGBA | param_3;
    *pGVar2 = *pGVar2 & 0xfffffff1 | param_4 << 1;
    *pGVar2 = *pGVar2 & 0xfffffe0f | (uint)frac << 4;
    break;
  case GX_VA_TEX2:
    *pGVar2 = *pGVar2 & 0xfffffdff | param_3 << 9;
    *pGVar2 = *pGVar2 & 0xffffe3ff | param_4 << 10;
    *pGVar2 = *pGVar2 & 0xfffc1fff | (uint)frac << 0xd;
    break;
  case GX_VA_TEX3:
    *pGVar2 = *pGVar2 & 0xfffbffff | param_3 << 0x12;
    *pGVar2 = *pGVar2 & 0xffc7ffff | param_4 << 0x13;
    *pGVar2 = *pGVar2 & 0xf83fffff | (uint)frac << 0x16;
    break;
  case GX_VA_TEX4:
    *pGVar2 = *pGVar2 & 0xf7ffffff | param_3 << 0x1b;
    *pGVar2 = *pGVar2 & 0x8fffffff | param_4 << 0x1c;
    *puVar4 = *puVar4 & 0xffffffe0 | (uint)frac;
    break;
  case GX_VA_TEX5:
    *puVar4 = *puVar4 & 0xffffffdf | param_3 << 5;
    *puVar4 = *puVar4 & 0xfffffe3f | param_4 << 6;
    *puVar4 = *puVar4 & 0xffffc1ff | (uint)frac << 9;
    break;
  case GX_VA_TEX6:
    *puVar4 = *puVar4 & 0xffffbfff | param_3 << 0xe;
    *puVar4 = *puVar4 & 0xfffc7fff | param_4 << 0xf;
    *puVar4 = *puVar4 & 0xff83ffff | (uint)frac << 0x12;
    break;
  case GX_VA_TEX7:
    *puVar4 = *puVar4 & 0xff7fffff | param_3 << 0x17;
    *puVar4 = *puVar4 & 0xf8ffffff | param_4 << 0x18;
    *puVar4 = (uint)frac << 0x1b | *puVar4 & 0x7ffffff;
  }
  iVar3 = gx;
  *(uint *)(gx + 0x4f4) = *(uint *)(gx + 0x4f4) | 0x10;
  *(byte *)(iVar3 + 0x4f2) = *(byte *)(iVar3 + 0x4f2) | (byte)(1 << (param_1 & 0xff));
  return;
}


void GXSetVtxAttrFmtv(uint param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  
  iVar2 = gx + param_1 * 4;
  puVar4 = (uint *)(iVar2 + 0x1c);
  puVar5 = (uint *)(iVar2 + 0x3c);
  puVar6 = (uint *)(iVar2 + 0x5c);
  for (; iVar2 = gx, *param_2 != 0xff; param_2 = param_2 + 4) {
    uVar3 = (uint)*(byte *)(param_2 + 3);
    iVar2 = param_2[2];
    uVar1 = param_2[1];
    switch(*param_2) {
    case 9:
      *puVar4 = *puVar4 & 0xfffffffe | uVar1;
      *puVar4 = *puVar4 & 0xfffffff1 | iVar2 << 1;
      *puVar4 = *puVar4 & 0xfffffe0f | uVar3 << 4;
      break;
    case 10:
    case 0x19:
      *puVar4 = *puVar4 & 0xffffe3ff | iVar2 << 10;
      if (uVar1 == 2) {
        *puVar4 = *puVar4 & 0xfffffdff | 0x200;
        *puVar4 = *puVar4 & 0x7fffffff | 0x80000000;
      }
      else {
        *puVar4 = *puVar4 & 0xfffffdff | uVar1 << 9;
        *puVar4 = *puVar4 & 0x7fffffff;
      }
      break;
    case 0xb:
      *puVar4 = *puVar4 & 0xffffdfff | uVar1 << 0xd;
      *puVar4 = *puVar4 & 0xfffe3fff | iVar2 << 0xe;
      break;
    case 0xc:
      *puVar4 = *puVar4 & 0xfffdffff | uVar1 << 0x11;
      *puVar4 = *puVar4 & 0xffe3ffff | iVar2 << 0x12;
      break;
    case 0xd:
      *puVar4 = *puVar4 & 0xffdfffff | uVar1 << 0x15;
      *puVar4 = *puVar4 & 0xfe3fffff | iVar2 << 0x16;
      *puVar4 = *puVar4 & 0xc1ffffff | uVar3 << 0x19;
      break;
    case 0xe:
      *puVar5 = *puVar5 & 0xfffffffe | uVar1;
      *puVar5 = *puVar5 & 0xfffffff1 | iVar2 << 1;
      *puVar5 = *puVar5 & 0xfffffe0f | uVar3 << 4;
      break;
    case 0xf:
      *puVar5 = *puVar5 & 0xfffffdff | uVar1 << 9;
      *puVar5 = *puVar5 & 0xffffe3ff | iVar2 << 10;
      *puVar5 = *puVar5 & 0xfffc1fff | uVar3 << 0xd;
      break;
    case 0x10:
      *puVar5 = *puVar5 & 0xfffbffff | uVar1 << 0x12;
      *puVar5 = *puVar5 & 0xffc7ffff | iVar2 << 0x13;
      *puVar5 = *puVar5 & 0xf83fffff | uVar3 << 0x16;
      break;
    case 0x11:
      *puVar5 = *puVar5 & 0xf7ffffff | uVar1 << 0x1b;
      *puVar5 = *puVar5 & 0x8fffffff | iVar2 << 0x1c;
      *puVar6 = *puVar6 & 0xffffffe0 | uVar3;
      break;
    case 0x12:
      *puVar6 = *puVar6 & 0xffffffdf | uVar1 << 5;
      *puVar6 = *puVar6 & 0xfffffe3f | iVar2 << 6;
      *puVar6 = *puVar6 & 0xffffc1ff | uVar3 << 9;
      break;
    case 0x13:
      *puVar6 = *puVar6 & 0xffffbfff | uVar1 << 0xe;
      *puVar6 = *puVar6 & 0xfffc7fff | iVar2 << 0xf;
      *puVar6 = *puVar6 & 0xff83ffff | uVar3 << 0x12;
      break;
    case 0x14:
      *puVar6 = *puVar6 & 0xff7fffff | uVar1 << 0x17;
      *puVar6 = *puVar6 & 0xf8ffffff | iVar2 << 0x18;
      *puVar6 = uVar3 << 0x1b | *puVar6 & 0x7ffffff;
    }
  }
  *(uint *)(gx + 0x4f4) = *(uint *)(gx + 0x4f4) | 0x10;
  *(byte *)(iVar2 + 0x4f2) = *(byte *)(iVar2 + 0x4f2) | (byte)(1 << (param_1 & 0xff));
  return;
}


void __GXSetVAT(void)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 0;
  iVar1 = 0;
  while( true ) {
    if (7 < bVar2) break;
    if (((uint)*(byte *)(gx + 0x4f2) & 1 << (uint)bVar2) != 0) {
      write_volatile_1(DAT_cc008000,8);
      write_volatile_1(DAT_cc008000,bVar2 | 0x70);
      write_volatile_4(0xcc008000,*(undefined4 *)(gx + iVar1 + 0x1c));
      write_volatile_1(DAT_cc008000,8);
      write_volatile_1(DAT_cc008000,bVar2 | 0x80);
      write_volatile_4(0xcc008000,*(undefined4 *)(gx + iVar1 + 0x3c));
      write_volatile_1(DAT_cc008000,8);
      write_volatile_1(DAT_cc008000,bVar2 | 0x90);
      write_volatile_4(0xcc008000,*(undefined4 *)(gx + iVar1 + 0x5c));
    }
    iVar1 = iVar1 + 4;
    bVar2 = bVar2 + 1;
  }
  *(undefined *)(gx + 0x4f2) = 0;
  return;
}


void GXGetVtxAttrFmt(int param_1,undefined4 param_2,uint *param_3,uint *param_4,byte *param_5)

{
  uint uVar1;
  byte bVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  
  iVar4 = gx + param_1 * 4;
  puVar3 = (uint *)(iVar4 + 0x1c);
  puVar5 = (uint *)(iVar4 + 0x3c);
  puVar6 = (uint *)(iVar4 + 0x5c);
  switch(param_2) {
  case 9:
    *param_3 = *puVar3 & 1;
    *param_4 = *puVar3 >> 1 & 7;
    *param_5 = (byte)(*puVar3 >> 4) & 0x1f;
    return;
  case 10:
  case 0x19:
    break;
  case 0xb:
    *param_3 = *puVar3 >> 0xd & 1;
    *param_4 = *puVar3 >> 0xe & 7;
    *param_5 = 0;
    return;
  case 0xc:
    *param_3 = *puVar3 >> 0x11 & 1;
    *param_4 = *puVar3 >> 0x12 & 7;
    *param_5 = 0;
    return;
  case 0xd:
    *param_3 = *puVar3 >> 0x15 & 1;
    *param_4 = *puVar3 >> 0x16 & 7;
    *param_5 = (byte)(*puVar3 >> 0x19) & 0x1f;
    return;
  case 0xe:
    *param_3 = *puVar5 & 1;
    *param_4 = *puVar5 >> 1 & 7;
    *param_5 = (byte)(*puVar5 >> 4) & 0x1f;
    return;
  case 0xf:
    *param_3 = *puVar5 >> 9 & 1;
    *param_4 = *puVar5 >> 10 & 7;
    *param_5 = (byte)(*puVar5 >> 0xd) & 0x1f;
    return;
  case 0x10:
    *param_3 = *puVar5 >> 0x12 & 1;
    *param_4 = *puVar5 >> 0x13 & 7;
    *param_5 = (byte)(*puVar5 >> 0x16) & 0x1f;
    return;
  case 0x11:
    *param_3 = *puVar5 >> 0x1b & 1;
    *param_4 = *puVar5 >> 0x1c & 7;
    *param_5 = (byte)*puVar6 & 0x1f;
    return;
  case 0x12:
    *param_3 = *puVar6 >> 5 & 1;
    *param_4 = *puVar6 >> 6 & 7;
    *param_5 = (byte)(*puVar6 >> 9) & 0x1f;
    return;
  case 0x13:
    *param_3 = *puVar6 >> 0xe & 1;
    *param_4 = *puVar6 >> 0xf & 7;
    *param_5 = (byte)(*puVar6 >> 0x12) & 0x1f;
    return;
  case 0x14:
    *param_3 = *puVar6 >> 0x17 & 1;
    *param_4 = *puVar6 >> 0x18 & 7;
    *param_5 = (byte)(*puVar6 >> 0x1b);
    return;
  default:
    *param_3 = 1;
    *param_4 = 0;
    *param_5 = 0;
    return;
  }
  *param_3 = *puVar3 >> 9 & 1;
  if ((*param_3 == 1) && ((int)*puVar3 < 0)) {
    *param_3 = 2;
  }
  *param_4 = *puVar3 >> 10 & 7;
  uVar1 = *param_4;
  if (uVar1 != 2) {
    if ((int)uVar1 < 2) {
      if (0 < (int)uVar1) {
        bVar2 = 6;
        goto LAB_8032234c;
      }
    }
    else {
      if ((int)uVar1 < 4) {
        bVar2 = 0xe;
        goto LAB_8032234c;
      }
    }
  }
  bVar2 = 0;
LAB_8032234c:
  *param_5 = bVar2;
  return;
}


void GXGetVtxAttrFmtv(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = 9;
  do {
    *param_2 = iVar1;
    GXGetVtxAttrFmt(param_1,iVar1,param_2 + 1,param_2 + 2,param_2 + 3);
    iVar1 = iVar1 + 1;
    param_2 = param_2 + 4;
  } while (iVar1 < 0x15);
  *param_2 = 0xff;
  return;
}


void GXSetArray(GXAttr attr,uint dataPointer,uint dataSize)

{
  byte bVar1;
  int iVar2;
  
  if (attr == GX_VA_NBT) {
    attr = GX_VA_NRM;
  }
  bVar1 = (char)attr - 9;
  write_volatile_1(DAT_cc008000,8);
  write_volatile_1(DAT_cc008000,bVar1 | 0xa0);
  iVar2 = attr + ~GX_VA_TEX7;
  write_volatile_4(0xcc008000,dataPointer & 0x3fffffff);
  if ((-1 < iVar2) && (iVar2 < 4)) {
    *(uint *)(gx + iVar2 * 4 + 0x88) = dataPointer & 0x3fffffff;
  }
  write_volatile_1(DAT_cc008000,8);
  write_volatile_1(DAT_cc008000,bVar1 | 0xb0);
  iVar2 = attr + ~GX_VA_TEX7;
  write_volatile_4(0xcc008000,dataSize & 0xff);
  if (iVar2 < 0) {
    return;
  }
  if (3 < iVar2) {
    return;
  }
  *(uint *)(gx + iVar2 * 4 + 0x98) = dataSize & 0xff;
  return;
}


void GXInvalidateVtxCache(void)

{
  write_volatile_1(DAT_cc008000,0x48);
  return;
}


void GXSetTexCoordGen2
               (GXTexCoordID dst_coord,GXTexGenType func,GXTexGenSrc src_param,GXTexMtx mtx,
               bool normalize,GXPTTexMtx postmtx)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = 0;
  iVar1 = 5;
  switch(src_param) {
  case GX_TG_POS:
    iVar1 = 0;
    iVar3 = 1;
    break;
  case GX_TG_NRM:
    iVar1 = 1;
    iVar3 = 1;
    break;
  case GX_TG_BINRM:
    iVar1 = 3;
    iVar3 = 1;
    break;
  case GX_TG_TANGENT:
    iVar1 = 4;
    iVar3 = 1;
    break;
  case GX_TG_TEX0:
    iVar1 = 5;
    break;
  case GX_TG_TEX1:
    iVar1 = 6;
    break;
  case GX_TG_TEX2:
    iVar1 = 7;
    break;
  case GX_TG_TEX3:
    iVar1 = 8;
    break;
  case GX_TG_TEX4:
    iVar1 = 9;
    break;
  case GX_TG_TEX5:
    iVar1 = 10;
    break;
  case GX_TG_TEX6:
    iVar1 = 0xb;
    break;
  case GX_TG_TEX7:
    iVar1 = 0xc;
    break;
  case GX_TG_COLOR0:
    iVar1 = 2;
    break;
  case GX_TG_COLOR1:
    iVar1 = 2;
  }
  if (func == GX_TG_MTX2x4) {
    uVar2 = iVar3 << 2 | iVar1 << 7;
  }
  else {
    if ((int)func < 1) {
      if (-1 < (int)func) {
        uVar2 = iVar3 << 2 | 2U | iVar1 << 7;
      }
    }
    else {
      if (func == GX_TG_SRTG) {
        if (src_param == GX_TG_COLOR0) {
          uVar2 = iVar3 << 2 | 0x20;
        }
        else {
          uVar2 = iVar3 << 2 | 0x30;
        }
        uVar2 = uVar2 | 0x100;
      }
      else {
        if ((int)func < 10) {
          uVar2 = iVar3 << 2 | 0x10U | iVar1 << 7 | (src_param + ~GX_TG_TEX7) * 0x1000 & 0xfffc7000
                  | (func + ~GX_TG_MTX2x4) * 0x8000;
        }
      }
    }
  }
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,dst_coord + 0x1040);
  write_volatile_4(0xcc008000,uVar2);
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,dst_coord + 0x1050);
  write_volatile_4(0xcc008000,postmtx + 0xffffffc0 & 0xfffffeff | (uint)normalize << 8);
  switch(dst_coord) {
  case GX_TEXCOORD0:
    *(GXTexMtx *)(gx + 0x80) = *(uint *)(gx + 0x80) & 0xfffff03f | mtx << 6;
    break;
  case GX_TEXCOORD1:
    *(GXTexMtx *)(gx + 0x80) = *(uint *)(gx + 0x80) & 0xfffc0fff | mtx << 0xc;
    break;
  case GX_TEXCOORD2:
    *(GXTexMtx *)(gx + 0x80) = *(uint *)(gx + 0x80) & 0xff03ffff | mtx << 0x12;
    break;
  case GX_TEXCOORD3:
    *(GXTexMtx *)(gx + 0x80) = *(uint *)(gx + 0x80) & 0xc0ffffff | mtx << 0x18;
    break;
  case GX_TEXCOORD4:
    *(uint *)(gx + 0x84) = *(uint *)(gx + 0x84) & 0xffffffc0 | mtx;
    break;
  case GX_TEXCOORD5:
    *(GXTexMtx *)(gx + 0x84) = *(uint *)(gx + 0x84) & 0xfffff03f | mtx << 6;
    break;
  case GX_TEXCOORD6:
    *(GXTexMtx *)(gx + 0x84) = *(uint *)(gx + 0x84) & 0xfffc0fff | mtx << 0xc;
    break;
  default:
    *(GXTexMtx *)(gx + 0x84) = *(uint *)(gx + 0x84) & 0xff03ffff | mtx << 0x12;
  }
  __GXSetMatrixIndex(dst_coord + GX_TEXCOORD1);
  return;
}


void GXSetNumTexGens(uint param_1)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 0x204) = *(uint *)(gx + 0x204) & 0xfffffff0 | param_1 & 0xff;
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,0x103f);
  write_volatile_4(0xcc008000,param_1 & 0xff);
  *(uint *)(iVar1 + 0x4f4) = *(uint *)(iVar1 + 0x4f4) | 4;
  return;
}

