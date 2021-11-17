#include <gx/GXTev.h>


namespace gx {

void GXSetTevOp(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  
  iVar1 = gx;
  if (param_1 == 0) {
    puVar3 = (uint *)(&TEVCOpTableST0 + param_2 * 4);
    puVar5 = (uint *)(&TEVAOpTableST0 + param_2 * 4);
  }
  else {
    puVar3 = (uint *)(&TEVCOpTableST1 + param_2 * 4);
    puVar5 = (uint *)(&TEVAOpTableST1 + param_2 * 4);
  }
  iVar4 = gx + param_1 * 4;
  write_volatile_1(DAT_cc008000,0x61);
  uVar2 = *puVar3 & 0xffffff | *(uint *)(iVar4 + 0x130) & 0xff000000;
  write_volatile_4(0xcc008000,uVar2);
  *(uint *)(iVar4 + 0x130) = uVar2;
  write_volatile_1(DAT_cc008000,0x61);
  uVar2 = *puVar5 & 0xfffff0 | *(uint *)(iVar4 + 0x170) & 0xff00000f;
  write_volatile_4(0xcc008000,uVar2);
  *(uint *)(iVar4 + 0x170) = uVar2;
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetTevColorIn(GXTevStageID param_1,GXTevColorArg param_2,GXTevColorArg param_3,
                        GXTevColorArg param_4,GXTevColorArg param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = gx;
  iVar3 = gx + param_1 * 4;
  write_volatile_1(DAT_cc008000,0x61);
  uVar2 = param_5 & 0xf |
          (param_4 & 0xf) << 4 |
          (param_3 & 0xf) << 8 | (param_2 & 0xf) << 0xc | *(uint *)(iVar3 + 0x130) & 0xffff0000;
  write_volatile_4(0xcc008000,uVar2);
  *(uint *)(iVar3 + 0x130) = uVar2;
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetTevAlphaIn(GXTevStageID param_1,GXTevAlphaArg param_2,GXTevAlphaArg param_3,
                        GXTevAlphaArg param_4,GXTevAlphaArg param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = gx;
  iVar3 = gx + param_1 * 4;
  write_volatile_1(DAT_cc008000,0x61);
  uVar2 = (param_5 & GX_CA_ZERO) << 4 |
          (param_4 & GX_CA_ZERO) << 7 |
          (param_3 & GX_CA_ZERO) << 10 |
          (param_2 & GX_CA_ZERO) << 0xd | *(uint *)(iVar3 + 0x170) & 0xffff000f;
  write_volatile_4(0xcc008000,uVar2);
  *(uint *)(iVar3 + 0x170) = uVar2;
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetTevColorOp(GXTevStageID param_1,GXTevOp param_2,GXTevBias param_3,GXTevScale param_4,
                        bool param_5,GXTevRegID param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = gx;
  uVar2 = *(uint *)(gx + param_1 * 4 + 0x130);
  uVar3 = (param_2 & 1) << 0x12;
  if ((int)param_2 < 2) {
    uVar3 = (param_3 & 3) << 0x10 | (param_4 & GX_CS_DIVIDE_2) << 0x14 | uVar3 | uVar2 & 0xffc8ffff;
  }
  else {
    uVar3 = (param_2 & 6) << 0x13 | uVar3 | uVar2 & 0xffc8ffff | 0x30000;
  }
  write_volatile_1(DAT_cc008000,0x61);
  uVar3 = (param_6 & GX_TEVREG2) << 0x16 | (param_5 & 1) << 0x13 | uVar3 & 0xff37ffff;
  write_volatile_4(0xcc008000,uVar3);
  *(uint *)(gx + param_1 * 4 + 0x130) = uVar3;
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetTevAlphaOp(GXTevStageID param_1,GXTevOp param_2,GXTevBias param_3,GXTevScale param_4,
                        bool param_5,GXTevRegID param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = gx;
  uVar2 = *(uint *)(gx + param_1 * 4 + 0x170);
  uVar3 = (param_2 & 1) << 0x12;
  if ((int)param_2 < 2) {
    uVar3 = (param_3 & 3) << 0x10 | (param_4 & GX_CS_DIVIDE_2) << 0x14 | uVar3 | uVar2 & 0xffc8ffff;
  }
  else {
    uVar3 = (param_2 & 6) << 0x13 | uVar3 | uVar2 & 0xffc8ffff | 0x30000;
  }
  write_volatile_1(DAT_cc008000,0x61);
  uVar3 = (param_6 & GX_TEVREG2) << 0x16 | (param_5 & 1) << 0x13 | uVar3 & 0xff37ffff;
  write_volatile_4(0xcc008000,uVar3);
  *(uint *)(gx + param_1 * 4 + 0x170) = uVar3;
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetTevColor(GXTevRegID param_1,_GXColor *param_2)

{
  uint uVar1;
  
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   (uint)param_2->r | (uint)param_2->a << 0xc | (param_1 * 2 + 0xe0) * 0x1000000);
  write_volatile_1(DAT_cc008000,0x61);
  uVar1 = (uint)param_2->b | (uint)param_2->g << 0xc | (param_1 * 2 + 0xe1) * 0x1000000;
  write_volatile_4(0xcc008000,uVar1);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar1);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar1);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetTevColorS10(GXTevRegID param_1,_GXColorS10 *param_2)

{
  uint uVar1;
  
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   (int)param_2->r & 0x7ffU | ((int)param_2->a & 0x7ffU) << 0xc |
                   (param_1 * 2 + 0xe0) * 0x1000000);
  write_volatile_1(DAT_cc008000,0x61);
  uVar1 = (int)param_2->b & 0x7ffU | ((int)param_2->g & 0x7ffU) << 0xc |
          (param_1 * 2 + 0xe1) * 0x1000000;
  write_volatile_4(0xcc008000,uVar1);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar1);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar1);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetTevKColor(int param_1,byte *param_2)

{
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   (uint)*param_2 | (uint)param_2[3] << 0xc | 0x800000 |
                   (param_1 * 2 + 0xe0) * 0x1000000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   (uint)param_2[2] | (uint)param_2[1] << 0xc | 0x800000 |
                   (param_1 * 2 + 0xe1) * 0x1000000);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetTevKColorSel(uint param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(gx + ((int)param_1 >> 1) * 4 + 0x1b0);
  if ((param_1 & 1) == 0) {
    *puVar1 = *puVar1 & 0xfffffe0f | param_2 << 4;
  }
  else {
    *puVar1 = *puVar1 & 0xfff83fff | param_2 << 0xe;
  }
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*puVar1);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetTevKAlphaSel(uint param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(gx + ((int)param_1 >> 1) * 4 + 0x1b0);
  if ((param_1 & 1) == 0) {
    *puVar1 = *puVar1 & 0xffffc1ff | param_2 << 9;
  }
  else {
    *puVar1 = *puVar1 & 0xff07ffff | param_2 << 0x13;
  }
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*puVar1);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetTevSwapMode(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = gx;
  puVar2 = (uint *)(gx + param_1 * 4 + 0x170);
  *puVar2 = *puVar2 & 0xfffffffc | param_2;
  *puVar2 = *puVar2 & 0xfffffff3 | param_3 << 2;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*puVar2);
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetTevSwapModeTable(int param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  
  iVar1 = gx;
  puVar3 = (uint *)(gx + param_1 * 8 + 0x1b0);
  *puVar3 = *puVar3 & 0xfffffffc | param_2;
  *puVar3 = *puVar3 & 0xfffffff3 | param_3 << 2;
  puVar2 = (uint *)(iVar1 + (param_1 * 2 + 1) * 4 + 0x1b0);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*puVar3);
  *puVar2 = *puVar2 & 0xfffffffc | param_4;
  *puVar2 = *puVar2 & 0xfffffff3 | param_5 << 2;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*puVar2);
  *(undefined2 *)(iVar1 + 2) = 0;
  return;
}


void GXSetAlphaCompare
               (GXCompare param_1,byte param_2,GXAlphaOp param_3,GXCompare param_4,byte param_5)

{
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   ((uint)param_5 << 8 | param_2 | 0xf3000000 | (param_1 & 0xffc7) << 0x10 |
                   param_4 << 0x13) & 0xff3fffff | param_3 << 0x16);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetZTexture(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  if (param_2 == 0x13) {
    uVar1 = 1;
  }
  else {
    if (param_2 < 0x13) {
      if (param_2 == 0x11) {
        uVar1 = 0;
        goto LAB_80326364;
      }
    }
    else {
      if (param_2 == 0x16) {
        uVar1 = 2;
        goto LAB_80326364;
      }
    }
    uVar1 = 2;
  }
LAB_80326364:
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,param_3 & 0xffffff | 0xf4000000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar1 | (param_1 & 0x3fffff) << 2 | 0xf5000000);
  *(undefined2 *)(gx + 2) = 0;
  return;
}


void GXSetTevOrder(GXTevStageID param_1,GXTexCoordID param_2,GXTexMapID param_3,
                      GXChannelID param_4)

{
  int iVar1;
  GXTexMapID *pGVar2;
  GXTexMapID GVar3;
  
  iVar1 = gx;
  GVar3 = param_3 & ~GX_TEX_DISABLE;
  *(GXTexMapID *)(gx + param_1 * 4 + 0x49c) = param_3;
  pGVar2 = (GXTexMapID *)
           (iVar1 + (((int)param_1 >> 1) +
                    (uint)((int)param_1 < 0 && (param_1 & GX_TEVSTAGE1) != GX_TEVSTAGE0)) * 4 +
                    0x100);
  if (GX_TEXMAP7 < GVar3) {
    GVar3 = GX_TEXMAP0;
  }
  if ((int)param_2 < 8) {
    *(uint *)(gx + 0x4e0) = *(uint *)(gx + 0x4e0) | 1 << param_1;
  }
  else {
    param_2 = GX_TEXCOORD0;
    *(uint *)(gx + 0x4e0) = *(uint *)(gx + 0x4e0) & ~(1 << param_1);
  }
  if ((param_1 & GX_TEVSTAGE1) == GX_TEVSTAGE0) {
    *pGVar2 = *pGVar2 & ~GX_TEXMAP7 | GVar3;
    *pGVar2 = *pGVar2 & 0xffffffc7 | param_2 << 3;
    if (param_4 == GX_COLOR_NULL) {
      iVar1 = 7;
    }
    else {
      iVar1 = *(int *)(&c2r_194 + param_4 * 4);
    }
    *pGVar2 = *pGVar2 & 0xfffffc7f | iVar1 << 7;
    iVar1 = 0;
    if ((param_3 != GX_TEXMAP_NULL) && ((param_3 & GX_TEX_DISABLE) == GX_TEXMAP0)) {
      iVar1 = 1;
    }
    *pGVar2 = *pGVar2 & 0xffffffbf | iVar1 << 6;
  }
  else {
    *pGVar2 = *pGVar2 & 0xffff8fff | GVar3 << 0xc;
    *pGVar2 = *pGVar2 & 0xfffc7fff | param_2 << 0xf;
    if (param_4 == GX_COLOR_NULL) {
      iVar1 = 7;
    }
    else {
      iVar1 = *(int *)(&c2r_194 + param_4 * 4);
    }
    *pGVar2 = *pGVar2 & 0xffc7ffff | iVar1 << 0x13;
    iVar1 = 0;
    if ((param_3 != GX_TEXMAP_NULL) && ((param_3 & GX_TEX_DISABLE) == GX_TEXMAP0)) {
      iVar1 = 1;
    }
    *pGVar2 = *pGVar2 & 0xfffbffff | iVar1 << 0x12;
  }
  iVar1 = gx;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,*pGVar2);
  *(undefined2 *)(gx + 2) = 0;
  *(uint *)(iVar1 + 0x4f4) = *(uint *)(iVar1 + 0x4f4) | 1;
  return;
}


void GXSetNumTevStages(uint param_1)

{
  int iVar1;
  
  iVar1 = gx;
  *(uint *)(gx + 0x204) = *(uint *)(gx + 0x204) & 0xffffc3ff | ((param_1 & 0xff) - 1) * 0x400;
  *(uint *)(iVar1 + 0x4f4) = *(uint *)(iVar1 + 0x4f4) | 4;
  return;
}

