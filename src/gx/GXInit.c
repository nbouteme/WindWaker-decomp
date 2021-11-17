#include <gx/GXInit.h>
#include <gx/GXTexture.h>
#include <os/OS.h>
#include <gx/GXMisc.h>
#include <gx/GXFifo.h>
#include <base/PPCArch.h>
#include <gx/GXBump.h>
#include <gx/GXInit.h>
#include <vi/vi.h>
#include <gx/GXFrameBuf.h>
#include <gx/GXAttr.h>
#include <gx/GXGeometry.h>
#include <gx/GXTransform.h>
#include <gx/GXLight.h>
#include <gx/GXTev.h>
#include <gx/GXPixel.h>
#include <gx/GXPerf.h>


namespace gx {
undefined gxData;
undefined FifoObj;
undefined4 __piReg;
undefined4 __cpReg;
undefined4 __peReg;
undefined4 __memReg;

int __GXDefaultTexRegionCallback(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = GXGetTexObjFmt();
  iVar1 = gx;
  if (((iVar2 == 8) || (iVar2 == 9)) || (iVar2 == 10)) {
    uVar3 = *(uint *)(gx + 0x2cc);
    *(uint *)(gx + 0x2cc) = uVar3 + 1;
    iVar2 = (uVar3 & 3) * 0x10 + 0x288;
  }
  else {
    uVar3 = *(uint *)(gx + 0x2c8);
    *(uint *)(gx + 0x2c8) = uVar3 + 1;
    iVar2 = (uVar3 & 7) * 0x10 + 0x208;
  }
  return iVar1 + iVar2;
}


int __GXDefaultTlutRegionCallback(uint param_1)

{
  int iVar1;
  
  if (param_1 < 0x14) {
    iVar1 = gx + param_1 * 0x10 + 0x2d0;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


undefined * GXInit(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  int iVar14;
  byte bVar15;
  int iVar16;
  int iVar17;
  
  os::OSRegisterVersion(__GXVersion);
  iVar17 = gx;
  iVar16 = 0;
  *(undefined *)(gx + 0x4f0) = 0;
  *(undefined *)(iVar17 + 0x4f1) = 1;
  *(undefined4 *)(iVar17 + 0x4dc) = 0;
  *(undefined4 *)(iVar17 + 0x4e0) = 0;
  GXSetMisc(1,0);
  __cpReg = &DAT_cc000000;
  __piReg = &DAT_cc003000;
  __peReg = &DAT_cc001000;
  __memReg = &DAT_cc004000;
  __GXFifoInit();
  GXInitFifoBase(&FifoObj,param_1,param_2);
  GXSetCPUFifo(&FifoObj);
  GXSetGPFifo(&FifoObj);
  __GXPEInit();
  uVar4 = base::PPCMfhid2();
  base::PPCMtwpar(0xc008000);
  base::PPCMthid2(uVar4 | 0x40000000);
  iVar17 = gx;
  uVar4 = 0;
  *(undefined4 *)(gx + 0x204) = 0;
  iVar7 = 0xc1;
  *(uint *)(iVar17 + 0x204) = *(uint *)(iVar17 + 0x204) & 0xffffff;
  iVar6 = 0xc0;
  *(undefined4 *)(iVar17 + 0x124) = 0xff;
  *(uint *)(iVar17 + 0x124) = *(uint *)(iVar17 + 0x124) & 0xffffff | 0xf000000;
  *(undefined4 *)(iVar17 + 0x7c) = 0;
  *(uint *)(iVar17 + 0x7c) = *(uint *)(iVar17 + 0x7c) & 0xffffff | 0x22000000;
  iVar17 = 8;
  do {
    iVar5 = gx;
    uVar1 = uVar4 >> 1;
    *(undefined4 *)(gx + iVar16 + 0x130) = 0;
    iVar14 = uVar1 * 4 + 0x100;
    *(undefined4 *)(iVar5 + iVar16 + 0x170) = 0;
    *(undefined4 *)(iVar5 + iVar14) = 0;
    *(undefined4 *)(iVar5 + iVar16 + 0x49c) = 0xff;
    puVar11 = (uint *)(iVar5 + iVar16 + 0x130);
    puVar12 = (uint *)(iVar5 + iVar16 + 0x170);
    *puVar11 = *puVar11 & 0xffffff | iVar6 << 0x18;
    *puVar12 = *puVar12 & 0xffffff | iVar7 << 0x18;
    puVar11 = (uint *)(iVar5 + uVar1 * 4 + 0x1b0);
    uVar2 = uVar4 + 1 >> 1;
    *puVar11 = *puVar11 & 0xffffff | (uVar1 + 0xf6) * 0x1000000;
    puVar11 = (uint *)(iVar5 + iVar14);
    *puVar11 = *puVar11 & 0xffffff | (uVar1 + 0x28) * 0x1000000;
    iVar14 = uVar2 * 4 + 0x100;
    *(undefined4 *)(iVar5 + iVar16 + 0x134) = 0;
    *(undefined4 *)(iVar5 + iVar16 + 0x174) = 0;
    *(undefined4 *)(iVar5 + iVar14) = 0;
    *(undefined4 *)(iVar5 + iVar16 + 0x4a0) = 0xff;
    puVar12 = (uint *)(iVar5 + iVar16 + 0x134);
    puVar13 = (uint *)(iVar5 + iVar16 + 0x174);
    puVar11 = (uint *)(iVar5 + uVar2 * 4 + 0x1b0);
    *puVar12 = *puVar12 & 0xffffff | (iVar6 + 2) * 0x1000000;
    puVar12 = (uint *)(iVar5 + iVar14);
    iVar16 = iVar16 + 8;
    *puVar13 = *puVar13 & 0xffffff | (iVar7 + 2) * 0x1000000;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 4;
    uVar4 = uVar4 + 2;
    *puVar11 = *puVar11 & 0xffffff | (uVar2 + 0xf6) * 0x1000000;
    *puVar12 = *puVar12 & 0xffffff | (uVar2 + 0x28) * 0x1000000;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  *(undefined4 *)(iVar5 + 0x120) = 0;
  iVar17 = 0;
  iVar6 = 0x30;
  iVar7 = 0x31;
  *(uint *)(iVar5 + 0x120) = *(uint *)(iVar5 + 0x120) & 0xffffff | 0x27000000;
  iVar16 = 2;
  do {
    iVar5 = gx;
    *(undefined4 *)(gx + iVar17 + 0xb8) = 0;
    *(undefined4 *)(iVar5 + iVar17 + 0xd8) = 0;
    puVar11 = (uint *)(iVar5 + iVar17 + 0xb8);
    puVar12 = (uint *)(iVar5 + iVar17 + 0xd8);
    *puVar11 = *puVar11 & 0xffffff | iVar6 << 0x18;
    puVar11 = (uint *)(iVar5 + iVar17 + 0xbc);
    *puVar12 = *puVar12 & 0xffffff | iVar7 << 0x18;
    *(undefined4 *)(iVar5 + iVar17 + 0xbc) = 0;
    puVar12 = (uint *)(iVar5 + iVar17 + 0xdc);
    *(undefined4 *)(iVar5 + iVar17 + 0xdc) = 0;
    *puVar11 = *puVar11 & 0xffffff | (iVar6 + 2) * 0x1000000;
    puVar11 = (uint *)(iVar5 + iVar17 + 0xc0);
    iVar9 = iVar6 + 6;
    *puVar12 = *puVar12 & 0xffffff | (iVar7 + 2) * 0x1000000;
    puVar12 = (uint *)(iVar5 + iVar17 + 0xe0);
    *(undefined4 *)(iVar5 + iVar17 + 0xc0) = 0;
    iVar8 = iVar17 + 0xc4;
    iVar10 = iVar7 + 6;
    *(undefined4 *)(iVar5 + iVar17 + 0xe0) = 0;
    iVar14 = iVar17 + 0xe4;
    iVar17 = iVar17 + 0x10;
    *puVar11 = *puVar11 & 0xffffff | (iVar6 + 4) * 0x1000000;
    puVar11 = (uint *)(iVar5 + iVar8);
    iVar6 = iVar6 + 8;
    *puVar12 = *puVar12 & 0xffffff | (iVar7 + 4) * 0x1000000;
    puVar12 = (uint *)(iVar5 + iVar14);
    *(undefined4 *)(iVar5 + iVar8) = 0;
    iVar7 = iVar7 + 8;
    *(undefined4 *)(iVar5 + iVar14) = 0;
    *puVar11 = *puVar11 & 0xffffff | iVar9 * 0x1000000;
    *puVar12 = *puVar12 & 0xffffff | iVar10 * 0x1000000;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  *(uint *)(iVar5 + 0xf8) = *(uint *)(iVar5 + 0xf8) & 0xffffff | 0x20000000;
  *(uint *)(iVar5 + 0xfc) = *(uint *)(iVar5 + 0xfc) & 0xffffff | 0x21000000;
  bVar15 = 0;
  *(uint *)(iVar5 + 0x1d0) = *(uint *)(iVar5 + 0x1d0) & 0xffffff | 0x41000000;
  *(uint *)(iVar5 + 0x1d4) = *(uint *)(iVar5 + 0x1d4) & 0xffffff | 0x42000000;
  *(uint *)(iVar5 + 0x1d8) = *(uint *)(iVar5 + 0x1d8) & 0xffffff | 0x40000000;
  *(uint *)(iVar5 + 0x1dc) = *(uint *)(iVar5 + 0x1dc) & 0xffffff | 0x43000000;
  *(uint *)(iVar5 + 0x1fc) = *(uint *)(iVar5 + 0x1fc) & 0xfffffe7f;
  *(undefined4 *)(iVar5 + 0x4f4) = 0;
  *(undefined *)(iVar5 + 0x4f2) = 0;
  uVar4 = DAT_800000f8 / 500;
  __GXFlushTextureState();
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar4 >> 0xb | 0x69000400);
  __GXFlushTextureState();
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,uVar4 / 0x1080 | 0x46000200);
  iVar17 = 0;
  iVar6 = 2;
  do {
    iVar7 = gx;
    puVar11 = (uint *)(gx + iVar17 + 0x1c);
    *puVar11 = *puVar11 & 0xbfffffff | 0x40000000;
    puVar12 = (uint *)(iVar7 + iVar17 + 0x3c);
    puVar11 = (uint *)(iVar7 + iVar17 + 0x20);
    *puVar12 = *puVar12 & 0x7fffffff | 0x80000000;
    puVar12 = (uint *)(iVar7 + iVar17 + 0x40);
    write_volatile_1(DAT_cc008000,8);
    write_volatile_1(DAT_cc008000,bVar15 | 0x80);
    write_volatile_4(0xcc008000,*(undefined4 *)(iVar7 + iVar17 + 0x3c));
    *puVar11 = *puVar11 & 0xbfffffff | 0x40000000;
    puVar11 = (uint *)(iVar7 + iVar17 + 0x24);
    *puVar12 = *puVar12 & 0x7fffffff | 0x80000000;
    puVar12 = (uint *)(iVar7 + iVar17 + 0x44);
    write_volatile_1(DAT_cc008000,8);
    write_volatile_1(DAT_cc008000,bVar15 + 1 | 0x80);
    bVar3 = bVar15 + 3;
    iVar16 = iVar17 + 0x44;
    write_volatile_4(0xcc008000,*(undefined4 *)(iVar7 + iVar17 + 0x40));
    *puVar11 = *puVar11 & 0xbfffffff | 0x40000000;
    puVar11 = (uint *)(iVar7 + iVar17 + 0x28);
    *puVar12 = *puVar12 & 0x7fffffff | 0x80000000;
    puVar12 = (uint *)(iVar7 + iVar17 + 0x48);
    write_volatile_1(DAT_cc008000,8);
    write_volatile_1(DAT_cc008000,bVar15 + 2 | 0x80);
    bVar15 = bVar15 + 4;
    iVar5 = iVar17 + 0x48;
    iVar17 = iVar17 + 0x10;
    write_volatile_4(0xcc008000,*(undefined4 *)(iVar7 + iVar16));
    *puVar11 = *puVar11 & 0xbfffffff | 0x40000000;
    *puVar12 = *puVar12 & 0x7fffffff | 0x80000000;
    write_volatile_1(DAT_cc008000,8);
    write_volatile_1(DAT_cc008000,bVar3 | 0x80);
    write_volatile_4(0xcc008000,*(undefined4 *)(iVar7 + iVar5));
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  write_volatile_1(DAT_cc008000,0x10);
  uVar4 = 0;
  write_volatile_4(0xcc008000,0x1000);
  iVar17 = 0;
  write_volatile_4(0xcc008000,0x3f);
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,0x1012);
  iVar7 = 0x80000;
  write_volatile_4(0xcc008000,1);
  iVar6 = 0;
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,0x5800000f);
  do {
    GXInitTexCacheRegion(gx + iVar6 + 0x208,0,iVar17,0,iVar7,0);
    iVar7 = iVar7 + 0x8000;
    iVar17 = iVar17 + 0x8000;
    iVar6 = iVar6 + 0x10;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 8);
  uVar4 = 0;
  iVar6 = 9;
  iVar7 = 8;
  iVar17 = 0;
  do {
    GXInitTexCacheRegion(gx + iVar17 + 0x288,0,iVar7 << 0xf,0,iVar6 << 0xf,0);
    iVar6 = iVar6 + 2;
    iVar7 = iVar7 + 2;
    iVar17 = iVar17 + 0x10;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 4);
  uVar4 = 0;
  iVar6 = 0xc0000;
  iVar17 = 0;
  do {
    GXInitTlutRegion(gx + iVar17 + 0x2d0,iVar6,0x10);
    iVar6 = iVar6 + 0x2000;
    iVar17 = iVar17 + 0x10;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x10);
  uVar4 = 0;
  iVar17 = 0xe0000;
  do {
    GXInitTlutRegion(gx + (uVar4 + 0x10) * 0x10 + 0x2d0,iVar17,0x40);
    iVar17 = iVar17 + 0x8000;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 4);
  *(undefined2 *)(__cpReg + 6) = 0;
  iVar17 = gx;
  *(uint *)(gx + 0x4ec) = *(uint *)(gx + 0x4ec) & 0xffffff0f;
  write_volatile_1(DAT_cc008000,8);
  write_volatile_1(DAT_cc008000,0x20);
  write_volatile_4(0xcc008000,*(undefined4 *)(iVar17 + 0x4ec));
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_4(0xcc008000,0x1006);
  write_volatile_4(0xcc008000,0);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,0x23000000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,0x24000000);
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,0x67000000);
  __GXSetTmemConfig(0);
  __GXInitGX();
  return &FifoObj;
}


void __GXInitGX(void)

{
  undefined *puVar1;
  int iVar2;
  GXAttr attr;
  uint uVar3;
  double dVar4;
  _GXColor local_78;
  undefined4 local_74;
  _GXColor local_70;
  undefined4 local_6c;
  _GXColor local_68;
  undefined4 local_64;
  undefined4 local_60;
  _GXColor local_5c;
  undefined4 local_58;
  MTX34 local_54;
  undefined4 local_20;
  uint uStack28;
  undefined4 local_18;
  uint uStack20;
  
  local_58 = _134;
  local_5c = _135;
  local_60 = _136;
  iVar2 = vi::VIGetTvFormat();
  if (iVar2 == 2) {
    puVar1 = &GXMpal480IntDf;
    goto LAB_803203fc;
  }
  if (iVar2 < 2) {
    if (iVar2 == 0) {
      puVar1 = &GXNtsc480IntDf;
      goto LAB_803203fc;
    }
    if (-1 < iVar2) {
      puVar1 = &GXPal528IntDf;
      goto LAB_803203fc;
    }
  }
  else {
    if (iVar2 == 5) {
      puVar1 = &GXEurgb60Hz480IntDf;
      goto LAB_803203fc;
    }
  }
  puVar1 = &GXNtsc480IntDf;
LAB_803203fc:
  local_64 = local_58;
  GXSetCopyClear(&local_64,0xffffff);
  GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  GXSetTexCoordGen2(GX_TEXCOORD1,GX_TG_MTX2x4,GX_TG_TEX1,GX_IDENTITY,false,GX_PTIDENTITY);
  GXSetTexCoordGen2(GX_TEXCOORD2,GX_TG_MTX2x4,GX_TG_TEX2,GX_IDENTITY,false,GX_PTIDENTITY);
  GXSetTexCoordGen2(GX_TEXCOORD3,GX_TG_MTX2x4,GX_TG_TEX3,GX_IDENTITY,false,GX_PTIDENTITY);
  GXSetTexCoordGen2(GX_TEXCOORD4,GX_TG_MTX2x4,GX_TG_TEX4,GX_IDENTITY,false,GX_PTIDENTITY);
  GXSetTexCoordGen2(GX_TEXCOORD5,GX_TG_MTX2x4,GX_TG_TEX5,GX_IDENTITY,false,GX_PTIDENTITY);
  GXSetTexCoordGen2(GX_TEXCOORD6,GX_TG_MTX2x4,GX_TG_TEX6,GX_IDENTITY,false,GX_PTIDENTITY);
  GXSetTexCoordGen2(GX_TEXCOORD7,GX_TG_MTX2x4,GX_TG_TEX7,GX_IDENTITY,false,GX_PTIDENTITY);
  GXSetNumTexGens(1);
  GXClearVtxDesc();
  GXInvalidateVtxCache();
  attr = GX_VA_POS;
  do {
    GXSetArray(attr,gx,0);
    attr = attr + GX_VA_TEX0MTXIDX;
  } while (attr < GX_VA_NBT);
  uVar3 = 0;
  do {
    GXSetVtxAttrFmtv(uVar3,&GXDefaultVATList);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 8);
  GXSetLineWidth(6,0);
  GXSetPointSize(6,0);
  GXEnableTexOffsets(0,0,0);
  GXEnableTexOffsets(1,0,0);
  GXEnableTexOffsets(2,0,0);
  GXEnableTexOffsets(3,0,0);
  GXEnableTexOffsets(4,0,0);
  GXEnableTexOffsets(5,0,0);
  GXEnableTexOffsets(6,0,0);
  GXEnableTexOffsets(7,0,0);
  local_54.m[0][0] = _196;
  local_54.m[0][1] = _197;
  local_54.m[0][2] = _197;
  local_54.m[0][3] = _197;
  local_54.m[1][0] = _197;
  local_54.m[1][1] = _196;
  local_54.m[1][2] = _197;
  local_54.m[1][3] = _197;
  local_54.m[2][0] = _197;
  local_54.m[2][1] = _197;
  local_54.m[2][2] = _196;
  local_54.m[2][3] = _197;
  GXLoadPosMtxImm(&local_54,0);
  GXLoadNrmMtxImm(&local_54,0);
  GXSetCurrentMtx(0);
  GXLoadTexMtxImm(&local_54,GX_IDENTITY,0);
  GXLoadTexMtxImm(&local_54,0x7d,0);
  uStack20 = (uint)*(ushort *)(puVar1 + 4);
  uStack28 = (uint)*(ushort *)(puVar1 + 8);
  dVar4 = (double)_197;
  local_18 = 0x43300000;
  local_20 = 0x43300000;
  GXSetViewport(dVar4,dVar4,(double)(float)((double)CONCAT44(0x43300000,uStack20) - _200),
                (double)(float)((double)CONCAT44(0x43300000,uStack28) - _200),dVar4,(double)_196);
  GXSetProjectionv(&GXDefaultProjData);
  GXSetCoPlanar(0);
  GXSetCullMode(2);
  GXSetClipMode(false);
  GXSetScissor(0,0,*(undefined2 *)(puVar1 + 4),*(undefined2 *)(puVar1 + 6));
  GXSetScissorBoxOffset(0,0);
  GXSetNumChans(0);
  GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_VTX,0,GX_DF_NONE,GX_AF_NONE);
  local_68 = local_5c;
  GXSetChanAmbColor(4,&local_68);
  local_6c = local_60;
  GXSetChanMatColor(4,&local_6c);
  GXSetChanCtrl(GX_COLOR1A1,false,GX_SRC_REG,GX_SRC_VTX,0,GX_DF_NONE,GX_AF_NONE);
  local_70 = local_5c;
  GXSetChanAmbColor(5,&local_70);
  local_74 = local_60;
  GXSetChanMatColor(5,&local_74);
  GXInvalidateTexAll();
  iVar2 = gx;
  uVar3 = 0;
  *(undefined4 *)(gx + 0x2c8) = 0;
  *(undefined4 *)(iVar2 + 0x2cc) = 0;
  GXSetTexRegionCallback(__GXDefaultTexRegionCallback);
  GXSetTlutRegionCallback(__GXDefaultTlutRegionCallback);
  GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR0A0);
  GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD1,GX_TEXMAP1,GX_COLOR0A0);
  GXSetTevOrder(GX_TEVSTAGE2,GX_TEXCOORD2,GX_TEXMAP2,GX_COLOR0A0);
  GXSetTevOrder(GX_TEVSTAGE3,GX_TEXCOORD3,GX_TEXMAP3,GX_COLOR0A0);
  GXSetTevOrder(GX_TEVSTAGE4,GX_TEXCOORD4,GX_TEXMAP4,GX_COLOR0A0);
  GXSetTevOrder(GX_TEVSTAGE5,GX_TEXCOORD5,GX_TEXMAP5,GX_COLOR0A0);
  GXSetTevOrder(GX_TEVSTAGE6,GX_TEXCOORD6,GX_TEXMAP6,GX_COLOR0A0);
  GXSetTevOrder(GX_TEVSTAGE7,GX_TEXCOORD7,GX_TEXMAP7,GX_COLOR0A0);
  GXSetTevOrder(GX_TEVSTAGE8,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  GXSetTevOrder(GX_TEVSTAGE9,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  GXSetTevOrder(GX_TEVSTAGE10,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  GXSetTevOrder(GX_TEVSTAGE11,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  GXSetTevOrder(GX_TEVSTAGE12,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  GXSetTevOrder(GX_TEVSTAGE13,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  GXSetTevOrder(GX_TEVSTAGE14,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  GXSetTevOrder(GX_TEVSTAGE15,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  GXSetNumTevStages(1);
  GXSetTevOp(0,3);
  GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_AND,GX_ALWAYS,0);
  GXSetZTexture(0,0x11,0);
  do {
    GXSetTevKColorSel(uVar3,6);
    GXSetTevKAlphaSel(uVar3,0);
    GXSetTevSwapMode(uVar3,0,0);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x10);
  GXSetTevSwapModeTable(0,0,1,2,3);
  GXSetTevSwapModeTable(1,0,0,0,3);
  GXSetTevSwapModeTable(2,1,1,1,3);
  GXSetTevSwapModeTable(3,2,2,2,3);
  uVar3 = 0;
  do {
    GXSetTevDirect(uVar3);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x10);
  GXSetNumIndStages(0);
  GXSetIndTexCoordScale(0,0,0);
  GXSetIndTexCoordScale(1,0,0);
  GXSetIndTexCoordScale(2,0,0);
  GXSetIndTexCoordScale(3,0,0);
  local_78 = local_5c;
  GXSetFog(GX_FOG_NONE,_197,_196,_198,_196,&local_78);
  GXSetFogRangeAdj(false,0,(_GXFogAdjTable *)0x0);
  GXSetBlendMode(GX_BM_NONE,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_CLEAR);
  GXSetColorUpdate(true);
  GXSetAlphaUpdate(1);
  GXSetZMode(true,GX_LEQUAL,true);
  GXSetZCompLoc(1);
  GXSetDither(1);
  GXSetDstAlpha(0,0);
  GXSetPixelFmt(0,0);
  GXSetFieldMask(1,1);
  GXSetFieldMode(puVar1[0x18],(uint)*(ushort *)(puVar1 + 0x10) == (uint)*(ushort *)(puVar1 + 8) << 1
                );
  GXSetDispCopySrc(0,0,*(undefined2 *)(puVar1 + 4),*(undefined2 *)(puVar1 + 6));
  GXSetDispCopyDst(*(undefined2 *)(puVar1 + 4),*(undefined2 *)(puVar1 + 6));
  uStack28 = (uint)*(ushort *)(puVar1 + 8);
  uStack20 = (uint)*(ushort *)(puVar1 + 6);
  local_20 = 0x43300000;
  local_18 = 0x43300000;
  GXSetDispCopyYScale((double)((float)((double)CONCAT44(0x43300000,uStack28) - _200) /
                              (float)((double)CONCAT44(0x43300000,uStack20) - _200)));
  GXSetCopyClamp(3);
  GXSetCopyFilter(puVar1[0x19],puVar1 + 0x1a,1,puVar1 + 0x32);
  GXSetDispCopyGamma(0);
  GXSetDispCopyFrame2Field(0);
  GXClearBoundingBox();
  GXPokeColorUpdate(1);
  GXPokeAlphaUpdate(1);
  GXPokeDither(0);
  GXPokeBlendMode(0,0,1,0xf);
  GXPokeAlphaMode(7,0);
  GXPokeAlphaRead(1);
  GXPokeDstAlpha(0,0);
  GXPokeZMode(1,7,1);
  GXSetGPMetric(0x23,0x16);
  GXClearGPMetric();
  return;
}

