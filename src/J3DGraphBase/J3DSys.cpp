#include <J3DGraphBase/J3DSys.h>
#include <J3DGraphBase/J3DTevs.h>
#include <mtx/mtx.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <gx/GXTexture.h>
#include <JRenderer/JRenderer.h>
#include <gx/GXMisc.h>
#include <gx/GXAttr.h>
#include <gx/GXTransform.h>
#include <gx/GXGeometry.h>
#include <gx/GXPixel.h>
#include <gx/GXTev.h>
#include <gx/GXBump.h>
#include <J3DGraphBase/J3DSys.h>
#include <gx/GXLight.h>
#include <J3DSys.h>


namespace J3DGraphBase {
struct J3DSys j3dSys;
}
struct MTX34 J3DSys;
struct TVec3<float> J3DSys;
struct TVec3<float> J3DSys;
undefined1 J3DSys;

namespace J3DGraphBase {
undefined j3dDefaultViewNo;
}

/* __thiscall J3DSys::J3DSys(void) */

void __thiscall J3DSys::J3DSys(J3DSys *this)

{
  int iVar1;
  int iVar2;
  
  J3DGraphBase::makeTexCoordTable();
  J3DGraphBase::makeTevSwapTable();
  J3DGraphBase::makeAlphaCmpTable();
  J3DGraphBase::makeZModeTable();
  this->mCurFlags = 0;
  mtx::PSMTXIdentity(&this->mCurViewMtx);
  this->mCurDrawMode = 1;
  this->mCurMaterialMode = 0;
  this->mpCurModel = (J3DModel *)0x0;
  this->field_0x44 = (undefined *)0x0;
  iVar1 = 0;
  iVar2 = 2;
  do {
    *(undefined4 *)((int)this->mpCurDrawBuffers + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->mpCurTex = (J3DTexture *)0x0;
  this->mpCurMatPacket = (J3DMatPacket *)0x0;
  this->mpCurShapePacket = (J3DShapePacket *)0x0;
  this->mpCurDrawPosMtxArr = (MTX34 *)0x0;
  this->mpCurDrawNrmMtxArr = (MTX34 *)0x0;
  this->mpCurVtxPos = (cXyz *)0x0;
  this->mpCurVtxNrm = (cXyz *)0x0;
  this->mpCurVtxClr = (_GXColor *)0x0;
  (this->mCurNBTScale).x = 0.0;
  *(undefined4 *)&this->field_0x104 = 0;
  (this->mCurNBTScale).y = 0.0;
  iVar1 = 0;
  iVar2 = 8;
  do {
    *(undefined2 *)(&sTexCoordScaleTable + iVar1) = 1;
    *(undefined2 *)((int)&DAT_803edbca + iVar1) = 1;
    *(undefined2 *)((int)&DAT_803edbcc + iVar1) = 0;
    *(undefined2 *)((int)&DAT_803edbce + iVar1) = 0;
    iVar1 = iVar1 + 8;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


/* __thiscall J3DSys::loadPosMtxIndx(int,
                                     unsigned short) const */

void __thiscall J3DSys::loadPosMtxIndx(J3DSys *this,int param_1,ushort param_2)

{
  write_volatile_1(DAT_cc008000,0x20);
  write_volatile_2(0xcc008000,param_2);
  write_volatile_2(0xcc008000,(short)param_1 * 0xc | 0xb000);
  return;
}


/* __thiscall J3DSys::loadNrmMtxIndx(int,
                                     unsigned short) const */

void __thiscall J3DSys::loadNrmMtxIndx(J3DSys *this,int param_1,ushort param_2)

{
  write_volatile_1(DAT_cc008000,0x28);
  write_volatile_2(0xcc008000,param_2);
  write_volatile_2(0xcc008000,(short)param_1 * 9 + 0x400U | 0x8000);
  return;
}


namespace J3DGraphBase {

/* __stdcall J3DFifoLoadPosMtxImm(float *[][][][],
                                  unsigned long) */

void J3DFifoLoadPosMtxImm(undefined4 *param_1,int param_2)

{
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_2(0xcc008000,0xb);
  write_volatile_2(0xcc008000,(short)(param_2 << 2));
  write_volatile_4(0xcc008000,*param_1);
  write_volatile_4(0xcc008000,param_1[1]);
  write_volatile_4(0xcc008000,param_1[2]);
  write_volatile_4(0xcc008000,param_1[3]);
  write_volatile_4(0xcc008000,param_1[4]);
  write_volatile_4(0xcc008000,param_1[5]);
  write_volatile_4(0xcc008000,param_1[6]);
  write_volatile_4(0xcc008000,param_1[7]);
  write_volatile_4(0xcc008000,param_1[8]);
  write_volatile_4(0xcc008000,param_1[9]);
  write_volatile_4(0xcc008000,param_1[10]);
  write_volatile_4(0xcc008000,param_1[0xb]);
  return;
}


/* __stdcall J3DFifoLoadNrmMtxImm(float *[][][][],
                                  unsigned long) */

void J3DFifoLoadNrmMtxImm(undefined4 *param_1,short param_2)

{
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_2(0xcc008000,8);
  write_volatile_2(0xcc008000,param_2 * 3 + 0x400);
  write_volatile_4(0xcc008000,*param_1);
  write_volatile_4(0xcc008000,param_1[1]);
  write_volatile_4(0xcc008000,param_1[2]);
  write_volatile_4(0xcc008000,param_1[4]);
  write_volatile_4(0xcc008000,param_1[5]);
  write_volatile_4(0xcc008000,param_1[6]);
  write_volatile_4(0xcc008000,param_1[8]);
  write_volatile_4(0xcc008000,param_1[9]);
  write_volatile_4(0xcc008000,param_1[10]);
  return;
}


/* __stdcall J3DFifoLoadNrmMtxImm3x3(float *[][][],
                                     unsigned long) */

void J3DFifoLoadNrmMtxImm3x3(undefined4 *param_1,short param_2)

{
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_2(0xcc008000,8);
  write_volatile_2(0xcc008000,param_2 * 3 + 0x400);
  write_volatile_4(0xcc008000,*param_1);
  write_volatile_4(0xcc008000,param_1[1]);
  write_volatile_4(0xcc008000,param_1[2]);
  write_volatile_4(0xcc008000,param_1[3]);
  write_volatile_4(0xcc008000,param_1[4]);
  write_volatile_4(0xcc008000,param_1[5]);
  write_volatile_4(0xcc008000,param_1[6]);
  write_volatile_4(0xcc008000,param_1[7]);
  write_volatile_4(0xcc008000,param_1[8]);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall J3DSys::setTexCacheRegion(_GXTexCacheSize) */

void __thiscall J3DSys::setTexCacheRegion(J3DSys *this,_GXTexCacheSize param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint local_48 [4];
  int local_38 [7];
  
  local_38[0] = J3DGraphBase::_1505;
  local_38[1] = DAT_80370c04;
  local_38[2] = DAT_80370c08;
  local_38[3] = DAT_80370c0c;
  local_48[0] = J3DGraphBase::_1506;
  local_48[1] = DAT_80370c14;
  local_48[2] = DAT_80370c18;
  local_48[3] = DAT_80370c1c;
  uVar4 = local_48[param_1];
  *(uint *)&this->field_0x60 = uVar4;
  if ((this->mCurFlags & 0x80000000) == 0) {
    iVar3 = 0;
    for (uVar2 = 0; uVar2 < uVar4; uVar2 = uVar2 + 1) {
      iVar1 = uVar2 * local_38[param_1];
      gx::GXInitTexCacheRegion
                ((int)this->mpCurDrawBuffers + iVar3 + 0x1c,0,iVar1,param_1,iVar1 + 0x80000,param_1)
      ;
      iVar1 = uVar2 * local_38[param_1];
      JRenderer::JRNLoadTexCached(uVar2,iVar1,param_1,iVar1 + 0x80000,param_1);
      iVar3 = iVar3 + 0x10;
    }
  }
  else {
    iVar3 = 0;
    for (uVar2 = 0; uVar2 < uVar4; uVar2 = uVar2 + 1) {
      if ((uVar2 & 1) == 0) {
        iVar1 = uVar2 * local_38[param_1];
        gx::GXInitTexCacheRegion
                  ((int)this->mpCurDrawBuffers + iVar3 + 0x1c,0,iVar1,param_1,iVar1 + 0x80000,
                   param_1);
        iVar1 = uVar2 * local_38[param_1];
        JRenderer::JRNLoadTexCached(uVar2,iVar1,param_1,iVar1 + 0x80000,param_1);
      }
      else {
        iVar1 = uVar2 * local_38[param_1];
        gx::GXInitTexCacheRegion
                  ((int)this->mpCurDrawBuffers + iVar3 + 0x1c,0,iVar1 + 0x80000,param_1,iVar1,
                   param_1);
        iVar1 = uVar2 * local_38[param_1];
        JRenderer::JRNLoadTexCached(uVar2,iVar1 + 0x80000,param_1,iVar1,param_1);
      }
      iVar3 = iVar3 + 0x10;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DSys::drawInit(void) */

void __thiscall J3DSys::drawInit(J3DSys *this)

{
  undefined4 *puVar1;
  GXTevStageID GVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  byte bVar9;
  int iVar10;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  float local_2c [7];
  
  gx::GXSetMisc(2,0);
  gx::GXInvalidateVtxCache();
  gx::GXSetCurrentMtx(0);
  gx::GXSetCullMode(2);
  gx::GXSetCoPlanar(0);
  gx::GXSetClipMode(false);
  gx::GXSetColorUpdate(true);
  gx::GXSetDither(1);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_NOOP);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_AND,GX_ALWAYS,0);
  gx::GXSetZMode(true,GX_LEQUAL,true);
  gx::GXSetZCompLoc(1);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_NRM,GX_CLR_RGB,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA8,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_CLR1,GX_CLR_RGBA,GX_RGBA8,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,7);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX1,GX_CLR_RGBA,GX_RGBA4,7);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX2,GX_CLR_RGBA,GX_RGBA4,7);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX3,GX_CLR_RGBA,GX_RGBA4,7);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX4,GX_CLR_RGBA,GX_RGBA4,7);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX5,GX_CLR_RGBA,GX_RGBA4,7);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX6,GX_CLR_RGBA,GX_RGBA4,7);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX7,GX_CLR_RGBA,GX_RGBA4,7);
  gx::GXSetNumIndStages(0);
  reinitTexture(this);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE2,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE3,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE4,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE5,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE6,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE7,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE8,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE9,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE10,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE11,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE12,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE13,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE14,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE15,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  uVar8 = 0;
  iVar10 = 0;
  do {
    gx::GXLoadTexMtxImm(&J3DGraphBase::j3dIdentityMtx,iVar10 + GX_TEXMTX0,0);
    uVar8 = uVar8 + 1;
    iVar10 = iVar10 + 3;
  } while (uVar8 < 10);
  puVar7 = &local_30;
  puVar6 = &DAT_80370c1c;
  iVar10 = 3;
  do {
    puVar1 = puVar6 + 1;
    puVar6 = puVar6 + 2;
    uVar5 = *puVar6;
    puVar7[1] = *puVar1;
    puVar7 = puVar7 + 2;
    *puVar7 = uVar5;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  for (bVar9 = 0; bVar9 < 3; bVar9 = bVar9 + 1) {
    gx::GXSetIndTexMtx(bVar9 + GX_ITM_0,(float (*) [6])local_2c,1);
  }
  local_38 = J3DGraphBase::j3dDefaultColInfo;
  gx::GXSetChanMatColor(4,&local_38);
  local_3c = J3DGraphBase::j3dDefaultColInfo;
  gx::GXSetChanMatColor(5,&local_3c);
  gx::GXSetNumChans(J3DGraphBase::j3dDefaultColorChanNum);
  gx::GXSetNumTexGens(1);
  gx::GXSetNumTevStages(1);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_CLAMP,GX_AF_NONE);
  gx::GXSetChanCtrl(GX_COLOR1A1,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_CLAMP,GX_AF_NONE);
  for (bVar9 = 0; bVar9 < 8; bVar9 = bVar9 + 1) {
    iVar10 = (uint)bVar9 * 4;
    gx::GXSetTexCoordGen2
              ((uint)bVar9,(uint)(byte)(&J3DGraphBase::j3dDefaultTexCoordInfo)[iVar10],
               (uint)(byte)(&DAT_80370d4d)[iVar10],(uint)(byte)(&DAT_80370d4e)[iVar10],false,
               GX_PTIDENTITY);
  }
  for (bVar9 = 0; uVar5 = J3DGraphBase::j3dDefaultTevKColor, bVar9 < 4; bVar9 = bVar9 + 1) {
    gx::GXSetIndTexCoordScale(bVar9,0,0);
  }
  for (bVar9 = 0; uVar4 = DAT_803fc948, uVar3 = J3DGraphBase::j3dDefaultTevColor, bVar9 < 4;
      bVar9 = bVar9 + 1) {
    local_40 = uVar5;
    gx::GXSetTevKColor(bVar9,&local_40);
  }
  for (bVar9 = 0; bVar9 < 4; bVar9 = bVar9 + 1) {
    local_34 = uVar3;
    local_30 = uVar4;
    gx::GXSetTevColorS10((uint)bVar9,(_GXColorS10 *)&local_34);
  }
  for (bVar9 = 0; bVar9 < 0x10; bVar9 = bVar9 + 1) {
    GVar2 = (GXTevStageID)bVar9;
    gx::GXSetTevColorIn(GVar2,GX_CC_RASC,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
    gx::GXSetTevColorOp(GVar2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GVar2,GX_CA_RASA,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
    gx::GXSetTevAlphaOp(GVar2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  }
  for (bVar9 = 0; bVar9 < 0x10; bVar9 = bVar9 + 1) {
    gx::GXSetTevSwapMode(bVar9,0,0);
  }
  gx::GXSetTevSwapModeTable(0,0,1,2,3);
  gx::GXSetTevSwapModeTable(1,0,0,0,3);
  gx::GXSetTevSwapModeTable(2,1,1,1,3);
  gx::GXSetTevSwapModeTable(3,2,2,2,3);
  for (bVar9 = 0; bVar9 < 0x10; bVar9 = bVar9 + 1) {
    gx::GXSetTevIndirect(bVar9,0,0,0,0,0,0,0,0,0);
  }
  setTexCacheRegion(this,0);
  return;
}


/* __thiscall J3DSys::reinitGX(void) */

void __thiscall J3DSys::reinitGX(J3DSys *this)

{
  reinitGenMode(this);
  reinitLighting(this);
  reinitTransform(this);
  reinitTexture(this);
  reinitTevStages(this);
  reinitIndStages(this);
  reinitPixelProc(this);
  return;
}


/* __thiscall J3DSys::reinitGenMode(void) */

void __thiscall J3DSys::reinitGenMode(J3DSys *this)

{
  gx::GXSetNumChans(0);
  gx::GXSetNumTexGens(1);
  gx::GXSetNumTevStages(1);
  gx::GXSetNumIndStages(0);
  gx::GXSetCullMode(2);
  gx::GXSetCoPlanar(0);
  return;
}


/* __thiscall J3DSys::reinitLighting(void) */

void __thiscall J3DSys::reinitLighting(J3DSys *this)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c [3];
  
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_VTX,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXSetChanCtrl(GX_COLOR1A1,false,GX_SRC_REG,GX_SRC_VTX,0,GX_DF_NONE,GX_AF_NONE);
  local_c[0] = J3DGraphBase::ColorBlack;
  gx::GXSetChanAmbColor(4,local_c);
  local_10 = J3DGraphBase::ColorBlack;
  gx::GXSetChanAmbColor(5,&local_10);
  local_14 = J3DGraphBase::ColorWhite;
  gx::GXSetChanMatColor(4,&local_14);
  local_18 = J3DGraphBase::ColorWhite;
  gx::GXSetChanMatColor(5,&local_18);
  return;
}


/* __thiscall J3DSys::reinitTransform(void) */

void __thiscall J3DSys::reinitTransform(J3DSys *this)

{
  gx::GXSetCurrentMtx(0);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetTexCoordGen2(GX_TEXCOORD1,GX_TG_MTX2x4,GX_TG_TEX1,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetTexCoordGen2(GX_TEXCOORD2,GX_TG_MTX2x4,GX_TG_TEX2,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetTexCoordGen2(GX_TEXCOORD3,GX_TG_MTX2x4,GX_TG_TEX3,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetTexCoordGen2(GX_TEXCOORD4,GX_TG_MTX2x4,GX_TG_TEX4,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetTexCoordGen2(GX_TEXCOORD5,GX_TG_MTX2x4,GX_TG_TEX5,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetTexCoordGen2(GX_TEXCOORD6,GX_TG_MTX2x4,GX_TG_TEX6,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetTexCoordGen2(GX_TEXCOORD7,GX_TG_MTX2x4,GX_TG_TEX7,GX_IDENTITY,false,GX_PTIDENTITY);
  return;
}


/* __thiscall J3DSys::reinitTexture(void) */

void __thiscall J3DSys::reinitTexture(J3DSys *this)

{
  GXTexObj GStack40;
  
  gx::GXInitTexObj(&GStack40,&J3DGraphBase::NullTexData,4,4,GX_TF_IA8,GX_CLAMP,GX_CLAMP,false);
  gx::GXLoadTexObj(&GStack40,0);
  gx::GXLoadTexObj(&GStack40,1);
  gx::GXLoadTexObj(&GStack40,2);
  gx::GXLoadTexObj(&GStack40,3);
  gx::GXLoadTexObj(&GStack40,4);
  gx::GXLoadTexObj(&GStack40,5);
  gx::GXLoadTexObj(&GStack40,6);
  gx::GXLoadTexObj(&GStack40,7);
  return;
}


/* __thiscall J3DSys::reinitTevStages(void) */

void __thiscall J3DSys::reinitTevStages(J3DSys *this)

{
  GXTevStageID GVar1;
  _GXColor local_28;
  _GXColor local_24;
  _GXColor local_20;
  _GXColor local_1c;
  _GXColor local_18;
  _GXColor local_14;
  _GXColor local_10 [3];
  
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE2,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE3,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE4,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE5,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE6,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE7,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE8,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE9,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE10,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE11,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE12,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE13,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE14,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevOrder(GX_TEVSTAGE15,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  local_10[0] = J3DGraphBase::ColorWhite;
  gx::GXSetTevColor(GX_TEVREG0,local_10);
  local_14 = J3DGraphBase::ColorWhite;
  gx::GXSetTevColor(GX_TEVREG1,&local_14);
  local_18 = J3DGraphBase::ColorWhite;
  gx::GXSetTevColor(GX_TEVREG2,&local_18);
  local_1c = J3DGraphBase::ColorWhite;
  gx::GXSetTevKColor(0,&local_1c);
  local_20 = J3DGraphBase::ColorWhite;
  gx::GXSetTevKColor(1,&local_20);
  local_24 = J3DGraphBase::ColorWhite;
  gx::GXSetTevKColor(2,&local_24);
  local_28 = J3DGraphBase::ColorWhite;
  gx::GXSetTevKColor(3,&local_28);
  GVar1 = GX_TEVSTAGE0;
  do {
    gx::GXSetTevColorIn(GVar1,GX_CC_RASC,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
    gx::GXSetTevColorOp(GVar1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GVar1,GX_CA_RASA,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
    gx::GXSetTevAlphaOp(GVar1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevKColorSel(GVar1,6);
    gx::GXSetTevKAlphaSel(GVar1,0);
    gx::GXSetTevSwapMode(GVar1,0,0);
    GVar1 = GVar1 + GX_TEVSTAGE1;
  } while (GVar1 < GX_MAX_TEVSTAGE);
  gx::GXSetTevSwapModeTable(0,0,1,2,3);
  gx::GXSetTevSwapModeTable(1,0,0,0,3);
  gx::GXSetTevSwapModeTable(2,1,1,1,3);
  gx::GXSetTevSwapModeTable(3,2,2,2,3);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_AND,GX_ALWAYS,0);
  return;
}


/* __thiscall J3DSys::reinitIndStages(void) */

void __thiscall J3DSys::reinitIndStages(J3DSys *this)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    gx::GXSetTevDirect(uVar1);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x10);
  gx::GXSetIndTexOrder(0,0,0);
  gx::GXSetIndTexOrder(1,1,1);
  gx::GXSetIndTexOrder(2,2,2);
  gx::GXSetIndTexOrder(3,3,3);
  gx::GXSetIndTexCoordScale(0,0,0);
  gx::GXSetIndTexCoordScale(1,0,0);
  gx::GXSetIndTexCoordScale(2,0,0);
  gx::GXSetIndTexCoordScale(3,0,0);
  gx::GXSetIndTexMtx(GX_ITM_0,(float (*) [6])&J3DGraphBase::IndMtx,1);
  gx::GXSetIndTexMtx(GX_ITM_1,(float (*) [6])&J3DGraphBase::IndMtx,1);
  gx::GXSetIndTexMtx(GX_ITM_2,(float (*) [6])&J3DGraphBase::IndMtx,1);
  return;
}


/* __thiscall J3DSys::reinitPixelProc(void) */

void __thiscall J3DSys::reinitPixelProc(J3DSys *this)

{
  _GXColor local_8 [2];
  
  gx::GXSetBlendMode(GX_BM_NONE,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_CLEAR);
  gx::GXSetColorUpdate(true);
  gx::GXSetAlphaUpdate(1);
  gx::GXSetDither(1);
  local_8[0] = J3DGraphBase::ColorBlack;
  gx::GXSetFog(GX_FOG_NONE,J3DGraphBase::_1702,J3DGraphBase::_1703,J3DGraphBase::_1704,
               J3DGraphBase::_1703,local_8);
  gx::GXSetFogRangeAdj(false,0,(_GXFogAdjTable *)0x0);
  gx::GXSetZMode(true,GX_LEQUAL,true);
  gx::GXSetZCompLoc(1);
  return;
}


namespace J3DGraphBase {

void __sinit_J3DSys_cpp(void)

{
  ::J3DSys::J3DSys(&j3dSys);
  return;
}

