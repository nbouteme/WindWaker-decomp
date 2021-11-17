#include <d_drawlist.h>
#include <gx/GXAttr.h>
#include <gx/GXLight.h>
#include <gx/GXTev.h>
#include <gx/GXPixel.h>
#include <gx/GXGeometry.h>
#include <gx/GXTexture.h>
#include <gx/GXTransform.h>
#include <m_Do_lib.h>
#include <J2DGraph/J2DPicture.h>
#include <MSL_C.PPCEABI.bare.H/w_fmod.h>
#include <d_drawlist.h>
#include <mtx/mtxvec.h>
#include <mtx/mtx.h>
#include <gf/GFTransform.h>
#include <gf/GFLight.h>
#include <gf/GFGeometry.h>
#include <gx/GXDisplayList.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <gf/GFPixel.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <J3DGraphBase/J3DDrawBuffer.h>
#include <m_Do_mtx.h>
#include <J3DGraphBase/J3DShape.h>
#include <J3DGraphBase/J3DPacket.h>
#include <gx/GXFrameBuf.h>
#include <gx/GXMisc.h>
#include <J3DU/J3DUClipper.h>
#include <SComponent/c_bg_s_chk.h>
#include <SComponent/c_bg_s.h>
#include <d_a_sea.h>
#include <mtx/mtx44.h>
#include <d_kankyo.h>
#include <J3DGraphAnimator/J3DModel.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <J3DGraphBase/J3DSys.h>
#include <gx/GXBump.h>
#include <d_resorce.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <m_Do_ext.h>
#include <J3DGraphBase/J3DTransform.h>
#include <JKernel/JKRArchivePub.h>
#include <d_camera.h>
#include <d_kankyo_rain.h>
#include <dDlst_alphaVolPacket.h>
#include <dDlst_2DPoint_c.h>
#include <dDlst_mirrorPacket.h>
#include <dDlst_2DTri_c.h>
#include <dDlst_window_c.h>
#include <dDlst_2DT2_c.h>
#include <dDlst_2DT_c.h>
#include <dDlst_alphaInvVolPacket.h>
#include <dDlst_alphaModel_c.h>
#include <dDlst_peekZ_c.h>
#include <dDlst_2Dm_c.h>
#include <cBgS_ShdwDraw.h>
#include <dDlst_shadowControl_c.h>
#include <dDlst_alphaModelData_c.h>
#include <dDlst_shadowRealPoly_c.h>
#include <dDlst_shadowTri_c.h>
#include <dDlst_2DMt_c.h>
#include <dDlst_alphaModelPacket.h>
#include <dDlst_effectLine_c.h>
#include <dDlst_shadowPoly_c.h>
#include <ShdwDrawPoly_c.h>
#include <dDlst_list_c.h>
#include <dDlst_shadowReal_c.h>
#include <dDlst_shadowSimple_c.h>
#include <dDlst_2DM_c.h>
#include <cM_rnd_c.h>
#include <mDoExt_3DlineMatSortPacket.h>
#include <dDlst_2D_c.h>

struct _GXTexObj dDlst_shadowControl_c;

namespace d_drawlist {
struct cXyz l_p1Offset$5970;
struct cXyz l_p2Offset$5974;
}
struct dDlst_2DT2_c dDlst_list_c;

namespace d_drawlist {
undefined1 init$5972;
undefined1 init$5976;
}
struct ResTIMG * dDlst_list_c;
struct ResTIMG * dDlst_list_c;
byte dDlst_list_c;
float dDlst_list_c;
float dDlst_list_c;

/* __thiscall dDlst_window_c::setViewPort(float,
                                          float,
                                          float,
                                          float,
                                          float,
                                          float) */

void __thiscall
dDlst_window_c::setViewPort
          (dDlst_window_c *this,float param_1,float param_2,float param_3,float param_4,
          float param_5,float param_6)

{
  this->mXOrig = param_1;
  this->mYOrig = param_2;
  this->mWidth = param_3;
  this->mHeight = param_4;
  this->mNearZ = param_5;
  this->mFarZ = param_6;
  return;
}


/* __thiscall dDlst_window_c::setScissor(float,
                                         float,
                                         float,
                                         float) */

void __thiscall
dDlst_window_c::setScissor
          (dDlst_window_c *this,float param_1,float param_2,float param_3,float param_4)

{
  this->mScissorXOrig = param_1;
  this->mScissorYOrig = param_2;
  this->mScissorWidth = param_3;
  this->mScissorHeight = param_4;
  return;
}


/* __thiscall dDlst_2DTri_c::draw(void) */

void __thiscall dDlst_2DTri_c::draw(dDlst_2DTri_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 local_38;
  short local_34 [4];
  short local_2c [6];
  longlong local_20;
  longlong local_18;
  
  iVar7 = (int)((int)*(short *)(this + 0xc) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar3 = JKernel::JMath::jmaCosTable[iVar7];
  fVar4 = JKernel::JMath::jmaSinTable[iVar7];
  uVar9 = 0;
  iVar7 = 0;
  iVar10 = 3;
  do {
    fVar1 = *(float *)(this + 0x10);
    iVar8 = (int)(uVar9 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
    fVar5 = JKernel::JMath::jmaSinTable[iVar8];
    fVar2 = *(float *)(this + 0x14);
    fVar6 = JKernel::JMath::jmaCosTable[iVar8];
    iVar8 = (int)(fVar1 * fVar5 * fVar3 + fVar2 * fVar6 * fVar4);
    local_20 = (longlong)iVar8;
    *(short *)((int)local_2c + iVar7) = *(short *)(this + 4) + (short)iVar8;
    iVar8 = (int)(fVar2 * fVar6 * fVar3 - fVar1 * fVar5 * fVar4);
    local_18 = (longlong)iVar8;
    *(short *)((int)local_34 + iVar7) = *(short *)(this + 6) + (short)iVar8;
    uVar9 = uVar9 - 0x5555;
    iVar7 = iVar7 + 2;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetNumChans(1);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  local_38 = *(undefined4 *)(this + 8);
  gx::GXSetChanMatColor(4,&local_38);
  gx::GXSetNumTexGens(0);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
  gx::GXSetTevOp(0,4);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
  gx::GXBegin(0x90,0,3);
  write_volatile_2(0xcc008000,local_2c[0]);
  write_volatile_2(0xcc008000,local_34[0]);
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,local_2c[1]);
  write_volatile_2(0xcc008000,local_34[1]);
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,local_2c[2]);
  write_volatile_2(0xcc008000,local_34[2]);
  write_volatile_2(0xcc008000,0);
  return;
}


/* __thiscall dDlst_2DPoint_c::draw(void) */

void __thiscall dDlst_2DPoint_c::draw(dDlst_2DPoint_c *this)

{
  undefined4 local_18 [5];
  
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetNumChans(1);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  local_18[0] = *(undefined4 *)(this + 8);
  gx::GXSetChanMatColor(4,local_18);
  gx::GXSetNumTexGens(0);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
  gx::GXSetTevOp(0,4);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
  gx::GXSetPointSize(this[0xc],0);
  gx::GXBegin(0xb8,0,1);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 4));
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 6));
  write_volatile_2(0xcc008000,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dDlst_2DT_c::draw(void) */

void __thiscall dDlst_2DT_c::draw(dDlst_2DT_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  undefined2 uVar11;
  double dVar12;
  uint local_88;
  GXTexObj GStack132;
  undefined4 local_60;
  uint uStack92;
  undefined4 local_58;
  uint uStack84;
  undefined4 local_50;
  uint uStack76;
  undefined4 local_48;
  uint uStack68;
  longlong local_40;
  longlong local_38;
  longlong local_30;
  longlong local_28;
  
  uStack92 = (uint)*(ushort *)(this + 0xe);
  local_60 = 0x43300000;
  fVar5 = (float)((double)CONCAT44(0x43300000,uStack92) - d_drawlist::_4386);
  uStack84 = (uint)*(ushort *)(this + 0x10);
  local_58 = 0x43300000;
  fVar6 = (float)((double)CONCAT44(0x43300000,uStack84) - d_drawlist::_4386);
  uStack76 = (int)*(short *)(this + 0x16) - (int)*(short *)(this + 0x12) ^ 0x80000000;
  local_50 = 0x43300000;
  fVar7 = (d_drawlist::0_5 * (float)((double)CONCAT44(0x43300000,uStack76) - d_drawlist::_4389)) /
          *(float *)(this + 0x24);
  uStack68 = (int)*(short *)(this + 0x18) - (int)*(short *)(this + 0x14) ^ 0x80000000;
  local_48 = 0x43300000;
  fVar8 = (d_drawlist::0_5 * (float)((double)CONCAT44(0x43300000,uStack68) - d_drawlist::_4389)) /
          *(float *)(this + 0x28);
  iVar1 = (int)(d_drawlist::_4383 * ((*(float *)(this + 0x1c) - fVar7) / fVar5));
  local_40 = (longlong)iVar1;
  iVar2 = (int)(d_drawlist::_4383 * ((*(float *)(this + 0x20) - fVar8) / fVar6));
  local_38 = (longlong)iVar2;
  iVar3 = (int)(d_drawlist::_4383 * ((*(float *)(this + 0x1c) + fVar7) / fVar5));
  local_30 = (longlong)iVar3;
  iVar4 = (int)(d_drawlist::_4383 * ((*(float *)(this + 0x20) + fVar8) / fVar6));
  local_28 = (longlong)iVar4;
  gx::GXInitTexObj(&GStack132,*(void **)(this + 4),uStack92,uStack84,(_GXTexFmt)this[0xc],GX_CLAMP,
                   GX_CLAMP,false);
  dVar12 = (double)d_drawlist::0_0;
  gx::GXInitTexObjLOD(dVar12,dVar12,dVar12,&GStack132,1,1,0,0,0);
  gx::GXLoadTexObj(&GStack132,0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_CLR0,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXSetNumChans(1);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  d_drawlist::l_color_4348 = d_drawlist::l_color_4348 & 0xffffff00 | (uint)(byte)this[0xd];
  local_88 = d_drawlist::l_color_4348;
  gx::GXSetChanMatColor(4,&local_88);
  gx::GXSetNumTexGens(1);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR0A0);
  gx::GXSetTevOp(0,0);
  gx::GXSetBlendMode(GX_BM_NONE,GX_BL_ZERO,GX_BL_ZERO,GX_LO_SET);
  gx::GXBegin(0x80,0,4);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x12));
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x14));
  write_volatile_2(0xcc008000,0);
  write_volatile_4(0xcc008000,0xffffffff);
  uVar11 = (undefined2)iVar1;
  write_volatile_2(0xcc008000,uVar11);
  uVar9 = (undefined2)iVar2;
  write_volatile_2(0xcc008000,uVar9);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x16));
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x14));
  write_volatile_2(0xcc008000,0);
  write_volatile_4(0xcc008000,0xffffffff);
  uVar10 = (undefined2)iVar3;
  write_volatile_2(0xcc008000,uVar10);
  write_volatile_2(0xcc008000,uVar9);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x16));
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x18));
  write_volatile_2(0xcc008000,0);
  write_volatile_4(0xcc008000,0xffffffff);
  write_volatile_2(0xcc008000,uVar10);
  uVar9 = (undefined2)iVar4;
  write_volatile_2(0xcc008000,uVar9);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x12));
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x18));
  write_volatile_2(0xcc008000,0);
  write_volatile_4(0xcc008000,0xffffffff);
  write_volatile_2(0xcc008000,uVar11);
  write_volatile_2(0xcc008000,uVar9);
  return;
}


/* WARNING: Removing unreachable block (ram,0x800811c4) */
/* WARNING: Removing unreachable block (ram,0x800811b4) */
/* WARNING: Removing unreachable block (ram,0x800811a4) */
/* WARNING: Removing unreachable block (ram,0x80081194) */
/* WARNING: Removing unreachable block (ram,0x8008119c) */
/* WARNING: Removing unreachable block (ram,0x800811ac) */
/* WARNING: Removing unreachable block (ram,0x800811bc) */
/* WARNING: Removing unreachable block (ram,0x800811cc) */
/* __thiscall dDlst_2DT2_c::draw(void) */

void __thiscall dDlst_2DT2_c::draw(dDlst_2DT2_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f24;
  double dVar9;
  undefined8 in_f25;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  double dVar10;
  undefined8 in_f29;
  double dVar11;
  undefined8 in_f30;
  double dVar12;
  undefined8 in_f31;
  double dVar13;
  _GXColor local_98;
  _GXColor local_94 [4];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGB,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXLoadTexObj((GXTexObj *)(this + 4),0);
  gx::GXSetNumChans(0);
  local_94[0] = *(_GXColor *)(this + 0x3c);
  gx::GXSetTevColor(GX_TEVREG0,local_94);
  gx::GXSetNumTexGens(1);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  if (this[0x42] == (dDlst_2DT2_c)0x0) {
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
  }
  else {
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A0);
  }
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetZCompLoc(0);
  gx::GXSetZMode(false,GX_ALWAYS,false);
  gx::GXSetBlendMode(GX_BM_NONE,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_CLEAR);
  gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
  local_98 = d_com_inf_game::g_clearColor;
  gx::GXSetFog(GX_FOG_NONE,d_drawlist::0_0,d_drawlist::0_0,d_drawlist::0_0,d_drawlist::0_0,&local_98
              );
  gx::GXSetCullMode(0);
  gx::GXSetDither(1);
  gx::GXSetClipMode(true);
  gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
  gx::GXSetCurrentMtx(0);
  fVar1 = *(float *)(this + 0x24);
  fVar2 = *(float *)(this + 0x2c);
  dVar13 = (double)(fVar1 + fVar2);
  fVar3 = *(float *)(this + 0x28);
  fVar4 = *(float *)(this + 0x30);
  dVar12 = (double)(fVar3 + fVar4);
  if ((this[0x40] == (dDlst_2DT2_c)0x0) || (this[0x41] == (dDlst_2DT2_c)0x0)) {
    if (this[0x40] == (dDlst_2DT2_c)0x0) {
      if (this[0x41] == (dDlst_2DT2_c)0x0) {
        dVar6 = (double)d_drawlist::0_0;
        dVar9 = dVar6;
        if (dVar6 != (double)*(float *)(this + 0x34)) {
          fVar1 = d_drawlist::0_5 *
                  (float)((double)d_drawlist::1_0 / (double)*(float *)(this + 0x34));
          dVar6 = (double)(d_drawlist::0_5 - fVar1);
          dVar9 = (double)(d_drawlist::0_5 + fVar1);
        }
        dVar11 = (double)d_drawlist::0_0;
        dVar10 = dVar11;
        if (dVar11 != (double)*(float *)(this + 0x38)) {
          fVar1 = d_drawlist::0_5 *
                  (float)((double)d_drawlist::1_0 / (double)*(float *)(this + 0x38));
          dVar11 = (double)(d_drawlist::0_5 - fVar1);
          dVar10 = (double)(d_drawlist::0_5 + fVar1);
        }
        gx::GXBegin(0x80,0,4);
        write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x24));
        write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x28));
        write_volatile_4(0xcc008000,(float)dVar6);
        write_volatile_4(0xcc008000,(float)dVar11);
        write_volatile_4(0xcc008000,(float)dVar13);
        write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x28));
        write_volatile_4(0xcc008000,(float)dVar9);
        write_volatile_4(0xcc008000,(float)dVar11);
        write_volatile_4(0xcc008000,(float)dVar13);
        write_volatile_4(0xcc008000,(float)dVar12);
        write_volatile_4(0xcc008000,(float)dVar9);
        write_volatile_4(0xcc008000,(float)dVar10);
        write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x24));
        write_volatile_4(0xcc008000,(float)dVar12);
        write_volatile_4(0xcc008000,(float)dVar6);
        write_volatile_4(0xcc008000,(float)dVar10);
      }
      else {
        dVar9 = (double)(fVar3 + d_drawlist::0_5 * fVar4);
        if (d_drawlist::0_0 == *(float *)(this + 0x34)) {
          dVar10 = (double)d_drawlist::1_0;
          dVar6 = dVar10;
        }
        else {
          fVar1 = d_drawlist::0_5 * (d_drawlist::1_0 / *(float *)(this + 0x34));
          dVar10 = (double)(d_drawlist::0_5 - fVar1);
          dVar6 = (double)(d_drawlist::0_5 + fVar1);
        }
        dVar8 = (double)d_drawlist::0_0;
        dVar11 = dVar8;
        if (dVar8 != (double)*(float *)(this + 0x38)) {
          dVar11 = (double)d_drawlist::1_0;
          dVar8 = (double)(float)(dVar11 - (double)(float)(dVar11 / (double)*(float *)(this + 0x38))
                                 );
        }
        gx::GXBegin(0x80,0,8);
        write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x24));
        write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x28));
        write_volatile_4(0xcc008000,(float)dVar10);
        write_volatile_4(0xcc008000,(float)dVar8);
        write_volatile_4(0xcc008000,(float)dVar13);
        write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x28));
        write_volatile_4(0xcc008000,(float)dVar6);
        write_volatile_4(0xcc008000,(float)dVar8);
        write_volatile_4(0xcc008000,(float)dVar13);
        write_volatile_4(0xcc008000,(float)dVar9);
        write_volatile_4(0xcc008000,(float)dVar6);
        write_volatile_4(0xcc008000,(float)dVar11);
        write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x24));
        write_volatile_4(0xcc008000,(float)dVar9);
        write_volatile_4(0xcc008000,(float)dVar10);
        write_volatile_4(0xcc008000,(float)dVar11);
        write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x24));
        write_volatile_4(0xcc008000,(float)dVar9);
        write_volatile_4(0xcc008000,(float)dVar10);
        write_volatile_4(0xcc008000,(float)dVar11);
        write_volatile_4(0xcc008000,(float)dVar13);
        write_volatile_4(0xcc008000,(float)dVar9);
        write_volatile_4(0xcc008000,(float)dVar6);
        write_volatile_4(0xcc008000,(float)dVar11);
        write_volatile_4(0xcc008000,(float)dVar13);
        write_volatile_4(0xcc008000,(float)dVar12);
        write_volatile_4(0xcc008000,(float)dVar6);
        write_volatile_4(0xcc008000,(float)dVar8);
        write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x24));
        write_volatile_4(0xcc008000,(float)dVar12);
        write_volatile_4(0xcc008000,(float)dVar10);
        write_volatile_4(0xcc008000,(float)dVar8);
      }
    }
    else {
      dVar10 = (double)(fVar1 + d_drawlist::0_5 * fVar2);
      dVar6 = (double)d_drawlist::0_0;
      dVar9 = dVar6;
      if (dVar6 != (double)*(float *)(this + 0x34)) {
        dVar6 = (double)d_drawlist::1_0;
        dVar9 = (double)(float)(dVar6 - (double)(float)(dVar6 / (double)*(float *)(this + 0x34)));
      }
      fVar1 = d_drawlist::1_0;
      if (d_drawlist::0_0 != *(float *)(this + 0x38)) {
        fVar1 = d_drawlist::0_5 - d_drawlist::0_5 * (d_drawlist::1_0 / *(float *)(this + 0x38));
      }
      dVar11 = (double)fVar1;
      gx::GXBegin(0x80,0,8);
      write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x24));
      write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x28));
      write_volatile_4(0xcc008000,(float)dVar9);
      write_volatile_4(0xcc008000,(float)dVar11);
      write_volatile_4(0xcc008000,(float)dVar10);
      write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x28));
      write_volatile_4(0xcc008000,(float)dVar6);
      write_volatile_4(0xcc008000,(float)dVar11);
      write_volatile_4(0xcc008000,(float)dVar10);
      write_volatile_4(0xcc008000,(float)dVar12);
      write_volatile_4(0xcc008000,(float)dVar6);
      write_volatile_4(0xcc008000,d_drawlist::1_0);
      write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x24));
      write_volatile_4(0xcc008000,(float)dVar12);
      write_volatile_4(0xcc008000,(float)dVar9);
      write_volatile_4(0xcc008000,d_drawlist::1_0);
      write_volatile_4(0xcc008000,(float)dVar10);
      write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x28));
      write_volatile_4(0xcc008000,(float)dVar6);
      write_volatile_4(0xcc008000,(float)dVar11);
      write_volatile_4(0xcc008000,(float)dVar13);
      write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x28));
      write_volatile_4(0xcc008000,(float)dVar9);
      write_volatile_4(0xcc008000,(float)dVar11);
      write_volatile_4(0xcc008000,(float)dVar13);
      write_volatile_4(0xcc008000,(float)dVar12);
      write_volatile_4(0xcc008000,(float)dVar9);
      write_volatile_4(0xcc008000,d_drawlist::1_0);
      write_volatile_4(0xcc008000,(float)dVar10);
      write_volatile_4(0xcc008000,(float)dVar12);
      write_volatile_4(0xcc008000,(float)dVar6);
      write_volatile_4(0xcc008000,d_drawlist::1_0);
    }
  }
  else {
    dVar11 = (double)(fVar1 + d_drawlist::0_5 * fVar2);
    dVar10 = (double)(fVar3 + d_drawlist::0_5 * fVar4);
    dVar6 = (double)d_drawlist::0_0;
    dVar9 = dVar6;
    if (dVar6 != (double)*(float *)(this + 0x34)) {
      dVar6 = (double)d_drawlist::1_0;
      dVar9 = (double)(float)(dVar6 - (double)(float)(dVar6 / (double)*(float *)(this + 0x34)));
    }
    dVar7 = (double)d_drawlist::0_0;
    dVar8 = dVar7;
    if (dVar7 != (double)*(float *)(this + 0x38)) {
      dVar7 = (double)d_drawlist::1_0;
      dVar8 = (double)(float)(dVar7 - (double)(float)(dVar7 / (double)*(float *)(this + 0x38)));
    }
    gx::GXBegin(0x80,0,0x10);
    write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x24));
    write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x28));
    write_volatile_4(0xcc008000,(float)dVar9);
    write_volatile_4(0xcc008000,(float)dVar8);
    write_volatile_4(0xcc008000,(float)dVar11);
    write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x28));
    write_volatile_4(0xcc008000,(float)dVar6);
    write_volatile_4(0xcc008000,(float)dVar8);
    write_volatile_4(0xcc008000,(float)dVar11);
    write_volatile_4(0xcc008000,(float)dVar10);
    write_volatile_4(0xcc008000,(float)dVar6);
    write_volatile_4(0xcc008000,(float)dVar7);
    write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x24));
    write_volatile_4(0xcc008000,(float)dVar10);
    write_volatile_4(0xcc008000,(float)dVar9);
    write_volatile_4(0xcc008000,(float)dVar7);
    write_volatile_4(0xcc008000,(float)dVar11);
    write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x28));
    write_volatile_4(0xcc008000,(float)dVar6);
    write_volatile_4(0xcc008000,(float)dVar8);
    write_volatile_4(0xcc008000,(float)dVar13);
    write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x28));
    write_volatile_4(0xcc008000,(float)dVar9);
    write_volatile_4(0xcc008000,(float)dVar8);
    write_volatile_4(0xcc008000,(float)dVar13);
    write_volatile_4(0xcc008000,(float)dVar10);
    write_volatile_4(0xcc008000,(float)dVar9);
    write_volatile_4(0xcc008000,(float)dVar7);
    write_volatile_4(0xcc008000,(float)dVar11);
    write_volatile_4(0xcc008000,(float)dVar10);
    write_volatile_4(0xcc008000,(float)dVar6);
    write_volatile_4(0xcc008000,(float)dVar7);
    write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x24));
    write_volatile_4(0xcc008000,(float)dVar10);
    write_volatile_4(0xcc008000,(float)dVar9);
    write_volatile_4(0xcc008000,(float)dVar7);
    write_volatile_4(0xcc008000,(float)dVar11);
    write_volatile_4(0xcc008000,(float)dVar10);
    write_volatile_4(0xcc008000,(float)dVar6);
    write_volatile_4(0xcc008000,(float)dVar7);
    write_volatile_4(0xcc008000,(float)dVar11);
    write_volatile_4(0xcc008000,(float)dVar12);
    write_volatile_4(0xcc008000,(float)dVar6);
    write_volatile_4(0xcc008000,(float)dVar8);
    write_volatile_4(0xcc008000,*(undefined4 *)(this + 0x24));
    write_volatile_4(0xcc008000,(float)dVar12);
    write_volatile_4(0xcc008000,(float)dVar9);
    write_volatile_4(0xcc008000,(float)dVar8);
    write_volatile_4(0xcc008000,(float)dVar11);
    write_volatile_4(0xcc008000,(float)dVar10);
    write_volatile_4(0xcc008000,(float)dVar6);
    write_volatile_4(0xcc008000,(float)dVar7);
    write_volatile_4(0xcc008000,(float)dVar13);
    write_volatile_4(0xcc008000,(float)dVar10);
    write_volatile_4(0xcc008000,(float)dVar9);
    write_volatile_4(0xcc008000,(float)dVar7);
    write_volatile_4(0xcc008000,(float)dVar13);
    write_volatile_4(0xcc008000,(float)dVar12);
    write_volatile_4(0xcc008000,(float)dVar9);
    write_volatile_4(0xcc008000,(float)dVar8);
    write_volatile_4(0xcc008000,(float)dVar11);
    write_volatile_4(0xcc008000,(float)dVar12);
    write_volatile_4(0xcc008000,(float)dVar6);
    write_volatile_4(0xcc008000,(float)dVar8);
  }
  gx::GXSetClipMode(false);
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setup2D)();
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  __psq_l0(auStack56,uVar5);
  __psq_l1(auStack56,uVar5);
  __psq_l0(auStack72,uVar5);
  __psq_l1(auStack72,uVar5);
  __psq_l0(auStack88,uVar5);
  __psq_l1(auStack88,uVar5);
  __psq_l0(auStack104,uVar5);
  __psq_l1(auStack104,uVar5);
  __psq_l0(auStack120,uVar5);
  __psq_l1(auStack120,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328e9c */
/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328ee8 */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dDlst_2DT2_c::init(ResTIMG *,
                                 float,
                                 float,
                                 float,
                                 float,
                                 unsigned char,
                                 unsigned char,
                                 unsigned char,
                                 float,
                                 float) */

int __thiscall
dDlst_2DT2_c::init(dDlst_2DT2_c *this,ResTIMG *param_1,float param_2,float param_3,float param_4,
                  float param_5,byte param_6,byte param_7,byte param_8,float param_9,float param_10)

{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  dDlst_2DT2_c local_48;
  dDlst_2DT2_c dStack71;
  dDlst_2DT2_c dStack70;
  dDlst_2DT2_c dStack69;
  
  dVar7 = (double)param_9;
  dVar8 = (double)param_10;
  dVar5 = (double)param_4;
  dVar6 = (double)param_5;
  dVar4 = (double)param_3;
  dVar3 = (double)param_2;
  iVar2 = m_Do_lib::mDoLib_setResTimgObj(param_1,this + 4,0,(GXTlutObj *)0x0);
  *(float *)(this + 0x24) = (float)dVar3;
  *(float *)(this + 0x28) = (float)dVar4;
  *(float *)(this + 0x2c) = (float)dVar5;
  *(float *)(this + 0x30) = (float)dVar6;
  *(float *)(this + 0x34) = (float)dVar7;
  *(float *)(this + 0x38) = (float)dVar8;
  uVar1 = d_drawlist::_4582;
  local_48 = SUB41((uint)d_drawlist::_4582 >> 0x18,0);
  this[0x3c] = local_48;
  dStack71 = SUB41((uint)uVar1 >> 0x10,0);
  this[0x3d] = dStack71;
  dStack70 = SUB41((uint)uVar1 >> 8,0);
  this[0x3e] = dStack70;
  dStack69 = SUB41(uVar1,0);
  this[0x3f] = dStack69;
  this[0x40] = (dDlst_2DT2_c)param_7;
  if ((this[0x40] != (dDlst_2DT2_c)0x0) && (iVar2 = gx::GXGetTexObjWrapS(this + 4), iVar2 == 2)) {
    this[0x40] = (dDlst_2DT2_c)0x0;
  }
  this[0x41] = (dDlst_2DT2_c)param_8;
  if ((this[0x41] != (dDlst_2DT2_c)0x0) && (iVar2 = gx::GXGetTexObjWrapT(this + 4), iVar2 == 2)) {
    this[0x41] = (dDlst_2DT2_c)0x0;
  }
  this[0x42] = (dDlst_2DT2_c)param_6;
  return iVar2;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall dDlst_2DM_c::draw(void) */

void __thiscall dDlst_2DM_c::draw(dDlst_2DM_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  float fVar8;
  float fVar9;
  short sVar10;
  short sVar11;
  _GXTexWrapMode wrap_s;
  short sVar12;
  short sVar13;
  undefined2 uVar14;
  double dVar15;
  _GXColor local_298;
  _GXColor local_294;
  GXTexObj GStack656;
  GXTexObj GStack624;
  undefined auStack592 [432];
  undefined4 local_a0;
  uint uStack156;
  longlong local_98;
  undefined4 local_90;
  uint uStack140;
  longlong local_88;
  undefined4 local_80;
  uint uStack124;
  undefined4 local_78;
  uint uStack116;
  undefined4 local_70;
  uint uStack108;
  longlong local_68;
  undefined4 local_60;
  uint uStack92;
  longlong local_58;
  undefined4 local_50;
  uint uStack76;
  longlong local_48;
  undefined4 local_40;
  uint uStack60;
  longlong local_38;
  
  sVar6 = *(short *)(this + 0x22);
  sVar7 = *(short *)(this + 0x24);
  uStack156 = (int)sVar6 ^ 0x80000000;
  local_a0 = 0x43300000;
  iVar1 = (int)(d_drawlist::_4655 +
               (float)((double)CONCAT44(0x43300000,uStack156) - d_drawlist::_4389));
  local_98 = (longlong)iVar1;
  uStack140 = (int)sVar7 ^ 0x80000000;
  local_90 = 0x43300000;
  iVar2 = (int)(d_drawlist::_4655 +
               (float)((double)CONCAT44(0x43300000,uStack140) - d_drawlist::_4389));
  local_88 = (longlong)iVar2;
  uStack124 = (uint)*(ushort *)(this + 0x2e);
  local_80 = 0x43300000;
  fVar8 = d_drawlist::_4655 / (float)((double)CONCAT44(0x43300000,uStack124) - d_drawlist::_4386);
  uStack116 = (uint)*(ushort *)(this + 0x30);
  local_78 = 0x43300000;
  fVar9 = d_drawlist::_4655 / (float)((double)CONCAT44(0x43300000,uStack116) - d_drawlist::_4386);
  uStack108 = (int)*(short *)(this + 0x32) ^ 0x80000000;
  local_70 = 0x43300000;
  iVar3 = (int)((float)((double)CONCAT44(0x43300000,uStack108) - d_drawlist::_4389) * fVar8);
  local_68 = (longlong)iVar3;
  uStack92 = (int)*(short *)(this + 0x34) ^ 0x80000000;
  local_60 = 0x43300000;
  iVar4 = (int)((float)((double)CONCAT44(0x43300000,uStack92) - d_drawlist::_4389) * fVar9);
  local_58 = (longlong)iVar4;
  uStack76 = (uint)*(ushort *)(this + 0x1e);
  local_50 = 0x43300000;
  iVar5 = (int)((float)((double)CONCAT44(0x43300000,uStack76) - d_drawlist::_4386) * fVar8);
  local_48 = (longlong)iVar5;
  sVar10 = (short)iVar3;
  sVar12 = sVar10 + (short)iVar5;
  uStack60 = (uint)*(ushort *)(this + 0x20);
  local_40 = 0x43300000;
  iVar3 = (int)((float)((double)CONCAT44(0x43300000,uStack60) - d_drawlist::_4386) * fVar9);
  local_38 = (longlong)iVar3;
  sVar11 = (short)iVar4;
  sVar13 = sVar11 + (short)iVar3;
  gx::GXGetVtxAttrFmtv(0,auStack592);
  gx::GXInitTexObj(&GStack656,*(void **)(this + 0x18),(uint)*(ushort *)(this + 0x1e),
                   (uint)*(ushort *)(this + 0x20),(_GXTexFmt)this[0x1c],GX_CLAMP,GX_CLAMP,false);
  dVar15 = (double)d_drawlist::0_0;
  gx::GXInitTexObjLOD(dVar15,dVar15,dVar15,&GStack656,1,1,0,0,0);
  wrap_s = GX_REPEAT - (this[0xc] == (dDlst_2DM_c)0x0);
  gx::GXInitTexObj(&GStack624,*(void **)(this + 0x28),(uint)*(ushort *)(this + 0x2e),
                   (uint)*(ushort *)(this + 0x30),(_GXTexFmt)this[0x2c],wrap_s,wrap_s,false);
  dVar15 = (double)d_drawlist::0_0;
  gx::GXInitTexObjLOD(dVar15,dVar15,dVar15,&GStack624,1,1,0,0,0);
  gx::GXLoadTexObj(&GStack656,0);
  gx::GXLoadTexObj(&GStack624,1);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,8);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX1,GX_CLR_RGBA,GX_RGBA4,8);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX1,GX_DIRECT);
  gx::GXSetNumChans(0);
  local_294 = *(_GXColor *)(this + 0xd);
  gx::GXSetTevColor(GX_TEVREG0,&local_294);
  local_298 = *(_GXColor *)(this + 0x11);
  gx::GXSetTevColor(GX_TEVREG1,&local_298);
  gx::GXSetNumTexGens(2);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetTexCoordGen2(GX_TEXCOORD1,GX_TG_MTX2x4,GX_TG_TEX1,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetNumTevStages(2);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C1,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_A1,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD1,GX_TEXMAP1,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_ZERO,GX_CC_TEXC,GX_CC_CPREV,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_ZERO,GX_CA_TEXA,GX_CA_APREV,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
  gx::GXBegin(0x80,0,4);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 4));
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 6));
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,sVar6);
  write_volatile_2(0xcc008000,sVar7);
  write_volatile_2(0xcc008000,sVar10);
  write_volatile_2(0xcc008000,sVar11);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 8));
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 6));
  write_volatile_2(0xcc008000,0);
  uVar14 = (undefined2)iVar1;
  write_volatile_2(0xcc008000,uVar14);
  write_volatile_2(0xcc008000,sVar7);
  write_volatile_2(0xcc008000,sVar12);
  write_volatile_2(0xcc008000,sVar11);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 8));
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 10));
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,uVar14);
  uVar14 = (undefined2)iVar2;
  write_volatile_2(0xcc008000,uVar14);
  write_volatile_2(0xcc008000,sVar12);
  write_volatile_2(0xcc008000,sVar13);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 4));
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 10));
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,sVar6);
  write_volatile_2(0xcc008000,uVar14);
  write_volatile_2(0xcc008000,sVar10);
  write_volatile_2(0xcc008000,sVar13);
  gx::GXSetVtxAttrFmtv(0,auStack592);
  return;
}


/* __thiscall dDlst_2Dm_c::init(ResTIMG *,
                                ResTIMG *,
                                float,
                                float) */

int __thiscall
dDlst_2Dm_c::init(dDlst_2Dm_c *this,ResTIMG *ctx,ResTIMG *param_2,float param_3,float param_4)

{
  byte bVar2;
  int iVar1;
  double dVar3;
  double dVar4;
  
  dVar4 = (double)param_4;
  dVar3 = (double)param_3;
  bVar2 = m_Do_lib::mDoLib_setResTimgObj(ctx,this->mTex,0,&this->mTex[0].mTlutObj);
  this->mTex[0].mbHasTlut = bVar2;
  iVar1 = m_Do_lib::mDoLib_setResTimgObj(param_2,this->mTex + 1,1,&this->mTex[1].mTlutObj);
  this->mTex[1].mbHasTlut = (byte)iVar1;
  (this->mScale).x = (float)dVar3;
  (this->mScale).y = (float)dVar4;
  return iVar1;
}


/* __thiscall dDlst_2Dm_c::setPos(short,
                                  short,
                                  short,
                                  short) */

void __thiscall
dDlst_2Dm_c::setPos(dDlst_2Dm_c *this,short param_1,short param_2,short param_3,short param_4)

{
  this->mX1 = param_1;
  this->mY1 = param_2;
  this->mX2 = param_3;
  this->mY2 = param_4;
  return;
}


/* __thiscall dDlst_2Dm_c::setScale(float,
                                    float) */

void __thiscall dDlst_2Dm_c::setScale(dDlst_2Dm_c *this,float param_1,float param_2)

{
  (this->mScale).x = param_1;
  (this->mScale).y = param_2;
  return;
}


/* __thiscall dDlst_2Dm_c::setScroll(int,
                                     short,
                                     short) */

void __thiscall dDlst_2Dm_c::setScroll(dDlst_2Dm_c *this,int param_1,short param_2,short param_3)

{
  this->mTex[param_1].mScrollX = param_2;
  this->mTex[param_1].mScrollY = param_3;
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x80081d7c) */
/* WARNING: Removing unreachable block (ram,0x80081d84) */
/* __thiscall dDlst_2Dm_c::draw(void) */

void __thiscall dDlst_2Dm_c::draw(dDlst_2Dm_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  undefined4 uVar12;
  undefined2 uVar13;
  undefined4 uVar14;
  undefined8 in_f30;
  double dVar15;
  undefined8 in_f31;
  double dVar16;
  _GXColor local_278;
  _GXColor local_274;
  undefined auStack624 [432];
  undefined4 local_c0;
  uint uStack188;
  longlong local_b8;
  undefined4 local_b0;
  uint uStack172;
  longlong local_a8;
  undefined4 local_a0;
  uint uStack156;
  undefined4 local_98;
  uint uStack148;
  undefined4 local_90;
  uint uStack140;
  longlong local_88;
  undefined4 local_80;
  uint uStack124;
  longlong local_78;
  undefined4 local_70;
  uint uStack108;
  longlong local_68;
  undefined4 local_60;
  uint uStack92;
  longlong local_58;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar14 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  sVar6 = this->mTex[0].mScrollX;
  sVar7 = this->mTex[0].mScrollY;
  uStack188 = (int)sVar6 ^ 0x80000000;
  local_c0 = 0x43300000;
  iVar1 = (int)(d_drawlist::_4655 +
               (float)((double)CONCAT44(0x43300000,uStack188) - d_drawlist::_4389));
  local_b8 = (longlong)iVar1;
  uStack172 = (int)sVar7 ^ 0x80000000;
  local_b0 = 0x43300000;
  iVar2 = (int)(d_drawlist::_4655 +
               (float)((double)CONCAT44(0x43300000,uStack172) - d_drawlist::_4389));
  local_a8 = (longlong)iVar2;
  uStack156 = gx::GXGetTexObjWidth(this->mTex + 1);
  uStack156 = uStack156 & 0xffff;
  local_a0 = 0x43300000;
  dVar16 = (double)((d_drawlist::_4655 * (this->mScale).x) /
                   (float)((double)CONCAT44(0x43300000,uStack156) - d_drawlist::_4386));
  uStack148 = gx::GXGetTexObjHeight(this->mTex + 1);
  uStack148 = uStack148 & 0xffff;
  local_98 = 0x43300000;
  dVar15 = (double)((d_drawlist::_4655 * (this->mScale).y) /
                   (float)((double)CONCAT44(0x43300000,uStack148) - d_drawlist::_4386));
  uStack140 = (int)this->mTex[1].mScrollX ^ 0x80000000;
  local_90 = 0x43300000;
  iVar3 = (int)((double)(float)((double)CONCAT44(0x43300000,uStack140) - d_drawlist::_4389) * dVar16
               );
  local_88 = (longlong)iVar3;
  uStack124 = (int)this->mTex[1].mScrollY ^ 0x80000000;
  local_80 = 0x43300000;
  iVar4 = (int)((double)(float)((double)CONCAT44(0x43300000,uStack124) - d_drawlist::_4389) * dVar15
               );
  local_78 = (longlong)iVar4;
  uStack108 = gx::GXGetTexObjWidth(this->mTex);
  uStack108 = uStack108 & 0xffff;
  local_70 = 0x43300000;
  iVar5 = (int)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,uStack108) - d_drawlist::_4386)
               );
  local_68 = (longlong)iVar5;
  sVar8 = (short)iVar3;
  sVar10 = sVar8 + (short)iVar5;
  uStack92 = gx::GXGetTexObjHeight(this->mTex);
  uStack92 = uStack92 & 0xffff;
  local_60 = 0x43300000;
  iVar3 = (int)(dVar15 * (double)(float)((double)CONCAT44(0x43300000,uStack92) - d_drawlist::_4386))
  ;
  local_58 = (longlong)iVar3;
  sVar9 = (short)iVar4;
  sVar11 = sVar9 + (short)iVar3;
  gx::GXGetVtxAttrFmtv(0,auStack624);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,8);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX1,GX_CLR_RGBA,GX_RGBA4,8);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX1,GX_DIRECT);
  gx::GXLoadTexObj(&this->mTex[0].mTexObj,0);
  if (this->mTex[0].mbHasTlut != 0) {
    uVar12 = gx::GXGetTexObjTlut(this->mTex);
    gx::GXLoadTlut(&this->mTex[0].mTlutObj,uVar12);
  }
  gx::GXLoadTexObj(&this->mTex[1].mTexObj,1);
  if (this->mTex[1].mbHasTlut != 0) {
    uVar12 = gx::GXGetTexObjTlut(this->mTex + 1);
    gx::GXLoadTlut(&this->mTex[1].mTlutObj,uVar12);
  }
  gx::GXSetNumChans(0);
  local_274 = this->mC0;
  gx::GXSetTevColor(GX_TEVREG0,&local_274);
  local_278 = this->mC1;
  gx::GXSetTevColor(GX_TEVREG1,&local_278);
  gx::GXSetNumTexGens(2);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetTexCoordGen2(GX_TEXCOORD1,GX_TG_MTX2x4,GX_TG_TEX1,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetNumTevStages(2);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C1,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_A1,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD1,GX_TEXMAP1,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_ZERO,GX_CC_TEXC,GX_CC_CPREV,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_ZERO,GX_CA_TEXA,GX_CA_APREV,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
  gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
  gx::GXSetCurrentMtx(0);
  gx::GXBegin(0x80,0,4);
  write_volatile_2(0xcc008000,this->mX1);
  write_volatile_2(0xcc008000,this->mY1);
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,sVar6);
  write_volatile_2(0xcc008000,sVar7);
  write_volatile_2(0xcc008000,sVar8);
  write_volatile_2(0xcc008000,sVar9);
  write_volatile_2(0xcc008000,this->mX2);
  write_volatile_2(0xcc008000,this->mY1);
  write_volatile_2(0xcc008000,0);
  uVar13 = (undefined2)iVar1;
  write_volatile_2(0xcc008000,uVar13);
  write_volatile_2(0xcc008000,sVar7);
  write_volatile_2(0xcc008000,sVar10);
  write_volatile_2(0xcc008000,sVar9);
  write_volatile_2(0xcc008000,this->mX2);
  write_volatile_2(0xcc008000,this->mY2);
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,uVar13);
  uVar13 = (undefined2)iVar2;
  write_volatile_2(0xcc008000,uVar13);
  write_volatile_2(0xcc008000,sVar10);
  write_volatile_2(0xcc008000,sVar11);
  write_volatile_2(0xcc008000,this->mX1);
  write_volatile_2(0xcc008000,this->mY2);
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,sVar6);
  write_volatile_2(0xcc008000,uVar13);
  write_volatile_2(0xcc008000,sVar8);
  write_volatile_2(0xcc008000,sVar11);
  gx::GXSetVtxAttrFmtv(0,auStack624);
  __psq_l0(auStack8,uVar14);
  __psq_l1(auStack8,uVar14);
  __psq_l0(auStack24,uVar14);
  __psq_l1(auStack24,uVar14);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dDlst_2DMt_c::draw(void) */

void __thiscall dDlst_2DMt_c::draw(dDlst_2DMt_c *this)

{
  GXTevColorArg GVar1;
  GXTevAlphaArg GVar2;
  int iVar3;
  char *pcVar4;
  GXTevStageID dst_coord;
  int iVar5;
  _GXColor local_1d8;
  undefined auStack468 [444];
  
  gx::GXGetVtxAttrFmtv(0,auStack468);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  pcVar4 = *(char **)(this + 8);
  dst_coord = GX_TEVSTAGE0;
  iVar5 = 0;
  for (iVar3 = 0; iVar3 < (int)(uint)(byte)this[4]; iVar3 = iVar3 + 1) {
    if (*pcVar4 != '\0') {
      if (pcVar4[1] != '\0') {
        gx::GXLoadTlut(pcVar4 + 0x24,iVar3);
      }
      gx::GXLoadTexObj((GXTexObj *)(pcVar4 + 4),dst_coord);
      gx::GXSetVtxAttrFmt(GX_VTXFMT0,dst_coord + GX_TEVSTAGE13,GX_CLR_RGBA,GX_F32,0);
      gx::GXSetVtxDesc(dst_coord + GX_TEVSTAGE13,GX_DIRECT);
      local_1d8 = *(_GXColor *)(pcVar4 + 0x30);
      gx::GXSetTevColor(dst_coord + GX_TEVREG0,&local_1d8);
      gx::GXSetTexCoordGen2
                (dst_coord,GX_TG_MTX2x4,dst_coord + GX_TEVSTAGE4,GX_IDENTITY,false,GX_PTIDENTITY);
      gx::GXSetTevOrder(dst_coord,dst_coord,dst_coord,GX_COLOR_NULL);
      GVar1 = GX_CC_ZERO;
      if (dst_coord != GX_TEVSTAGE0) {
        GVar1 = GX_CC_CPREV;
      }
      gx::GXSetTevColorIn(dst_coord,GX_CC_ZERO,iVar5 + GX_CC_C0,GX_CC_TEXC,GVar1);
      gx::GXSetTevColorOp(dst_coord,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      GVar2 = GX_CA_ZERO;
      if (dst_coord != GX_TEVSTAGE0) {
        GVar2 = GX_CA_APREV;
      }
      gx::GXSetTevAlphaIn(dst_coord,GX_CA_ZERO,dst_coord + GX_TEVREG0,GX_CA_TEXA,GVar2);
      gx::GXSetTevAlphaOp(dst_coord,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      dst_coord = dst_coord + GX_TEVSTAGE1;
      iVar5 = iVar5 + 2;
      if (2 < (int)dst_coord) break;
    }
    pcVar4 = pcVar4 + 0x44;
  }
  if (dst_coord != GX_TEVSTAGE0) {
    gx::GXSetNumChans(0);
    gx::GXSetNumTexGens(dst_coord & 0xff);
    gx::GXSetNumTevStages(dst_coord & 0xff);
    gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
    gx::GXBegin(0x80,0,4);
    write_volatile_2(0xcc008000,*(undefined2 *)(this + 0xc));
    write_volatile_2(0xcc008000,*(undefined2 *)(this + 0xe));
    write_volatile_2(0xcc008000,0);
    pcVar4 = *(char **)(this + 8);
    for (iVar3 = 0; iVar3 < (int)(uint)(byte)this[4]; iVar3 = iVar3 + 1) {
      if (*pcVar4 != '\0') {
        write_volatile_4(0xcc008000,*(undefined4 *)(pcVar4 + 0x34));
        write_volatile_4(0xcc008000,*(undefined4 *)(pcVar4 + 0x38));
      }
      pcVar4 = pcVar4 + 0x44;
    }
    write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x10));
    write_volatile_2(0xcc008000,*(undefined2 *)(this + 0xe));
    write_volatile_2(0xcc008000,0);
    pcVar4 = *(char **)(this + 8);
    for (iVar3 = 0; iVar3 < (int)(uint)(byte)this[4]; iVar3 = iVar3 + 1) {
      if (*pcVar4 != '\0') {
        write_volatile_4(0xcc008000,*(float *)(pcVar4 + 0x34) + *(float *)(pcVar4 + 0x3c));
        write_volatile_4(0xcc008000,*(undefined4 *)(pcVar4 + 0x38));
      }
      pcVar4 = pcVar4 + 0x44;
    }
    write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x10));
    write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x12));
    write_volatile_2(0xcc008000,0);
    pcVar4 = *(char **)(this + 8);
    for (iVar3 = 0; iVar3 < (int)(uint)(byte)this[4]; iVar3 = iVar3 + 1) {
      if (*pcVar4 != '\0') {
        write_volatile_4(0xcc008000,*(float *)(pcVar4 + 0x34) + *(float *)(pcVar4 + 0x3c));
        write_volatile_4(0xcc008000,*(float *)(pcVar4 + 0x38) + *(float *)(pcVar4 + 0x40));
      }
      pcVar4 = pcVar4 + 0x44;
    }
    write_volatile_2(0xcc008000,*(undefined2 *)(this + 0xc));
    write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x12));
    write_volatile_2(0xcc008000,0);
    pcVar4 = *(char **)(this + 8);
    for (iVar3 = 0; iVar3 < (int)(uint)(byte)this[4]; iVar3 = iVar3 + 1) {
      if (*pcVar4 != '\0') {
        write_volatile_4(0xcc008000,*(undefined4 *)(pcVar4 + 0x34));
        write_volatile_4(0xcc008000,*(float *)(pcVar4 + 0x38) + *(float *)(pcVar4 + 0x40));
      }
      pcVar4 = pcVar4 + 0x44;
    }
    gx::GXSetVtxAttrFmtv(0,auStack468);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dDlst_2D_c::dDlst_2D_c(ResTIMG *,
                                     short,
                                     short,
                                     unsigned char) */

void __thiscall
dDlst_2D_c::dDlst_2D_c(dDlst_2D_c *this,ResTIMG *param_1,short param_2,short param_3,uchar param_4)

{
  this->field_0x0 = &dDlst_base_c::__vt;
  this->field_0x0 = &__vt;
  J2DPicture::J2DPicture((J2DPicture *)&this->field_0x4);
  J2DPicture::initiate((J2DPicture *)&this->field_0x4,param_1,(ResTLUT *)0x0);
  this->field_0x128 = param_2;
  this->field_0x12a = param_3;
  this->field_0x12c = param_4;
  return;
}


/* __thiscall dDlst_2D_c::draw(void) */

void __thiscall dDlst_2D_c::draw(dDlst_2D_c *this)

{
  int iVar1;
  
  *(uchar *)&this->field_0xb0 = this->field_0x12c;
  if (*(char *)&this->field_0xe0 != '\0') {
    iVar1 = *(int *)(*(int *)&this->field_0xd0 + 0x20);
    J2DPicture::draw((J2DPicture *)&this->field_0x4,
                     (float)((double)CONCAT44(0x43300000,(int)this->field_0x128 ^ 0x80000000) -
                            d_drawlist::_4389),
                     (float)((double)CONCAT44(0x43300000,(int)this->field_0x12a ^ 0x80000000) -
                            d_drawlist::_4389),
                     (float)((double)CONCAT44(0x43300000,*(ushort *)(iVar1 + 2) ^ 0x80000000) -
                            d_drawlist::_4389),
                     (float)((double)CONCAT44(0x43300000,*(ushort *)(iVar1 + 4) ^ 0x80000000) -
                            d_drawlist::_4389),false,false,false);
  }
  return;
}


/* __thiscall cM_rnd_c::init(int,
                             int,
                             int) */

void __thiscall cM_rnd_c::init(cM_rnd_c *this,int param_1,int param_2,int param_3)

{
  this->field_0x0 = param_1;
  this->field_0x4 = param_2;
  this->field_0x8 = param_3;
  return;
}


/* __thiscall cM_rnd_c::get(void) */

double __thiscall cM_rnd_c::get(cM_rnd_c *this)

{
  double dVar1;
  
  this->field_0x0 = (this->field_0x0 * 0xab) % 0x763d;
  this->field_0x4 = (this->field_0x4 * 0xac) % 0x7663;
  this->field_0x8 = (this->field_0x8 * 0xaa) % 0x7673;
  dVar1 = MSL_C.PPCEABI.bare.H::fmod
                    ((double)((float)((double)CONCAT44(0x43300000,this->field_0x8 ^ 0x80000000) -
                                     d_drawlist::_4389) / d_drawlist::_4924 +
                             (float)((double)CONCAT44(0x43300000,this->field_0x0 ^ 0x80000000) -
                                    d_drawlist::_4389) / d_drawlist::_4925 +
                             (float)((double)CONCAT44(0x43300000,this->field_0x4 ^ 0x80000000) -
                                    d_drawlist::_4389) / d_drawlist::_4926),d_drawlist::_4927);
  return (double)ABS((float)dVar1);
}


/* WARNING: Removing unreachable block (ram,0x80082388) */
/* __thiscall cM_rnd_c::getF(float) */

double __thiscall cM_rnd_c::getF(cM_rnd_c *this,float param_1)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar2 = (double)param_1;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar3 = (double)get(this);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return (double)(float)(dVar2 * dVar3);
}


/* WARNING: Removing unreachable block (ram,0x800823d0) */
/* __thiscall cM_rnd_c::getFX(float) */

double __thiscall cM_rnd_c::getFX(cM_rnd_c *this,float param_1)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar2 = (double)param_1;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar3 = (double)get(this);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return (double)(d_drawlist::_4939 *
                 (float)(dVar2 * (double)(float)(dVar3 - (double)d_drawlist::0_5)));
}


/* WARNING: Removing unreachable block (ram,0x8008240c) */
/* __thiscall cM_rnd_c::getValue(float,
                                 float) */

double __thiscall cM_rnd_c::getValue(cM_rnd_c *this,float param_1,float param_2)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar2 = (double)param_1;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar3 = (double)getF(this,param_2);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return (double)(float)(dVar2 + dVar3);
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x80082774) */
/* __thiscall dDlst_effectLine_c::draw(void) */

void __thiscall dDlst_effectLine_c::draw(dDlst_effectLine_c *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  _GXColor local_78;
  cXyz local_74;
  cXyz local_68;
  undefined4 local_58;
  uint uStack84;
  undefined4 local_50;
  uint uStack76;
  longlong local_48;
  longlong local_40;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetNumChans(1);
  gx::GXSetChanCtrl(GX_COLOR0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_CLAMP,GX_AF_NONE);
  gx::GXSetNumTexGens(0);
  gx::GXSetNumTevStages(1);
  local_78 = *(_GXColor *)(this + 0x1c);
  gx::GXSetTevColor(GX_TEVREG0,&local_78);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_C0);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A0);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetZMode(false,GX_LEQUAL,false);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_CLEAR);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
  gx::GXSetCullMode(0);
  gx::GXSetClipMode(false);
  gx::GXLoadPosMtxImm(&J3DGraphBase::j3dSys.mCurViewMtx,0);
  gx::GXSetCurrentMtx(0);
  uStack84 = (uint)*(ushort *)(this + 0x20);
  local_58 = 0x43300000;
  uStack76 = (uint)*(ushort *)(this + 0x22);
  local_50 = 0x43300000;
  dVar5 = (double)cM_rnd_c::getValue((cM_rnd_c *)(this + 4),
                                     (float)((double)CONCAT44(0x43300000,uStack84) -
                                            d_drawlist::_4386),
                                     (float)((double)CONCAT44(0x43300000,uStack76) -
                                            d_drawlist::_4386));
  local_48 = (longlong)(int)dVar5;
  dVar8 = d_drawlist::_4386;
  for (iVar3 = 0; iVar3 < (int)dVar5; iVar3 = iVar3 + 1) {
    dVar6 = (double)cM_rnd_c::getFX((cM_rnd_c *)(this + 4),d_drawlist::_5010);
    local_48 = (longlong)(int)dVar6;
    dVar7 = (double)cM_rnd_c::getValue((cM_rnd_c *)(this + 4),*(float *)(this + 0x28),
                                       *(float *)(this + 0x2c));
    uVar1 = (int)dVar6 & 0xffff;
    iVar2 = (int)uVar1 >> (JKernel::JMath::jmaSinShift & 0x3f);
    local_68.x = *(float *)(this + 0x10) +
                 (float)(dVar7 * (double)JKernel::JMath::jmaSinTable[iVar2]);
    local_68.y = *(float *)(this + 0x14) +
                 (float)(dVar7 * (double)JKernel::JMath::jmaCosTable[iVar2]);
    local_68.z = *(float *)(this + 0x18);
    dVar6 = (double)cM_rnd_c::getValue((cM_rnd_c *)(this + 4),*(float *)(this + 0x30),
                                       *(float *)(this + 0x34));
    iVar2 = (int)uVar1 >> (JKernel::JMath::jmaSinShift & 0x3f);
    local_74.x = local_68.x + (float)(dVar6 * (double)JKernel::JMath::jmaSinTable[iVar2]);
    local_74.y = local_68.y + (float)(dVar6 * (double)JKernel::JMath::jmaCosTable[iVar2]);
    local_74.z = *(float *)(this + 0x18);
    mtx::PSMTXMultVec(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mInvViewMtx,
                      &local_68,&local_68);
    mtx::PSMTXMultVec(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mInvViewMtx,
                      &local_74,&local_74);
    uStack76 = (uint)*(ushort *)(this + 0x24);
    local_50 = 0x43300000;
    uStack84 = (uint)*(ushort *)(this + 0x26);
    local_58 = 0x43300000;
    dVar6 = (double)cM_rnd_c::getValue((cM_rnd_c *)(this + 4),
                                       (float)((double)CONCAT44(0x43300000,uStack76) - dVar8),
                                       (float)((double)CONCAT44(0x43300000,uStack84) - dVar8));
    local_40 = (longlong)(int)dVar6;
    gx::GXSetLineWidth((int)dVar6,0);
    gx::GXBegin(0xa8,0,2);
    write_volatile_4(0xcc008000,local_68.x);
    write_volatile_4(0xcc008000,local_68.y);
    write_volatile_4(0xcc008000,local_68.z);
    write_volatile_4(0xcc008000,local_74.x);
    write_volatile_4(0xcc008000,local_74.y);
    write_volatile_4(0xcc008000,local_74.z);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* __thiscall dDlst_effectLine_c::update(cXyz &,
                                         _GXColor &,
                                         unsigned short,
                                         unsigned short,
                                         unsigned short,
                                         unsigned short,
                                         float,
                                         float,
                                         float,
                                         float) */

void __thiscall
dDlst_effectLine_c::update
          (dDlst_effectLine_c *this,cXyz *param_1,_GXColor *param_2,ushort param_3,ushort param_4,
          ushort param_5,ushort param_6,float param_7,float param_8,float param_9,float param_10)

{
  *(float *)(this + 0x10) = param_1->x;
  *(float *)(this + 0x14) = param_1->y;
  *(float *)(this + 0x18) = param_1->z;
  this[0x1c] = *(dDlst_effectLine_c *)&param_2->r;
  this[0x1d] = *(dDlst_effectLine_c *)&param_2->g;
  this[0x1e] = *(dDlst_effectLine_c *)&param_2->b;
  this[0x1f] = *(dDlst_effectLine_c *)&param_2->a;
  *(ushort *)(this + 0x20) = param_3;
  *(ushort *)(this + 0x22) = param_4;
  *(ushort *)(this + 0x24) = param_5;
  *(ushort *)(this + 0x26) = param_6;
  *(float *)(this + 0x28) = param_7;
  *(float *)(this + 0x2c) = param_8;
  *(float *)(this + 0x30) = param_9;
  *(float *)(this + 0x34) = param_10;
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,(dDlst_base_c *)this);
  return;
}


/* __thiscall dDlst_alphaModelData_c::set(unsigned char,
                                          float *[][][][],
                                          unsigned char) */

void __thiscall
dDlst_alphaModelData_c::set
          (dDlst_alphaModelData_c *this,dDlst_alphaModelData__Type param_1,MTX34 *pMtx,uchar param_3
          )

{
  this->mType = param_1;
  this->mpMtx = pMtx;
  this->mAlpha = param_3;
  return;
}


/* __thiscall dDlst_alphaModelData_c::draw(float *[][][][]) */

void __thiscall dDlst_alphaModelData_c::draw(dDlst_alphaModelData_c *this,MTX34 *param_1)

{
  dDlst_alphaModelData__Type dVar1;
  double dVar2;
  uint local_a0;
  uint color;
  MTX34 MStack152;
  MTX34 MStack104;
  MTX34 MStack56;
  
  mtx::PSMTXConcat(param_1,this->mpMtx,&MStack56);
  gf::GFLoadPosMtxImm(&MStack56,0);
  gf::GFSetCurrentMtx(0,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c);
  color = color & 0xffffff00 | (uint)(byte)(this->mAlpha << 2);
  local_a0 = color;
  gf::GFSetChanMatColor(2,&local_a0);
  dVar1 = this->mType;
  if (dVar1 == Bonbori) {
    gf::GFSetArray(GX_VA_POS,(int)d_drawlist::l_bonboriPos,0xc);
    gx::GXCallDisplayList(&d_drawlist::l_backRevZMat,0x40);
    gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
    gx::GXCallDisplayList(&d_drawlist::l_frontZMat,0x20);
    gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
    gx::GXCallDisplayList(&d_drawlist::l_frontNoZSubMat,0x20);
    gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
  }
  else {
    if (dVar1 == BonboriTwice) {
      gf::GFSetArray(GX_VA_POS,(int)d_drawlist::l_bonboriPos,0xc);
      dVar2 = (double)d_drawlist::0_8;
      mtx::PSMTXScale(dVar2,dVar2,dVar2,&MStack104);
      mtx::PSMTXConcat(&MStack56,&MStack104,&MStack104);
      gf::GFLoadPosMtxImm(&MStack104,3);
      gx::GXCallDisplayList(&d_drawlist::l_backRevZMat,0x40);
      gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
      gf::GFSetCurrentMtx(3,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c);
      gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
      gx::GXCallDisplayList(&d_drawlist::l_frontZMat,0x20);
      gf::GFSetCurrentMtx(0,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c);
      gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
      gf::GFSetCurrentMtx(3,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c);
      gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
      gx::GXCallDisplayList(&d_drawlist::l_frontNoZSubMat,0x20);
      gf::GFSetCurrentMtx(0,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c);
      gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
      gf::GFSetCurrentMtx(3,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c);
      gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
    }
    else {
      if (dVar1 == BonboriThrice) {
        gf::GFSetArray(GX_VA_POS,(int)d_drawlist::l_bonboriPos,0xc);
        dVar2 = (double)d_drawlist::0_8;
        mtx::PSMTXScale(dVar2,dVar2,dVar2,&MStack152);
        mtx::PSMTXConcat(&MStack56,&MStack152,&MStack152);
        gf::GFLoadPosMtxImm(&MStack152,3);
        dVar2 = (double)d_drawlist::0_6;
        mtx::PSMTXScale(dVar2,dVar2,dVar2,&MStack152);
        mtx::PSMTXConcat(&MStack56,&MStack152,&MStack152);
        gf::GFLoadPosMtxImm(&MStack152,6);
        gx::GXCallDisplayList(&d_drawlist::l_backRevZMat,0x40);
        gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
        gf::GFSetCurrentMtx(3,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c);
        gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
        gf::GFSetCurrentMtx(6,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c);
        gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
        gx::GXCallDisplayList(&d_drawlist::l_frontZMat,0x20);
        gf::GFSetCurrentMtx(0,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c);
        gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
        gf::GFSetCurrentMtx(3,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c);
        gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
        gf::GFSetCurrentMtx(6,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c);
        gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
        gx::GXCallDisplayList(&d_drawlist::l_frontNoZSubMat,0x20);
        gf::GFSetCurrentMtx(0,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c);
        gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
        gf::GFSetCurrentMtx(3,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c);
        gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
        gf::GFSetCurrentMtx(6,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c,0x3c);
        gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
      }
      else {
        if (dVar1 == BeamCheck) {
          gf::GFSetArray(GX_VA_POS,(int)&d_drawlist::l_s_beam_checkPos,0xc);
          gx::GXCallDisplayList(&d_drawlist::l_backRevZMat,0x40);
          gx::GXCallDisplayList(&d_drawlist::l_s_beam_checkDL,0xe0);
          gx::GXCallDisplayList(&d_drawlist::l_frontZMat,0x20);
          gx::GXCallDisplayList(&d_drawlist::l_s_beam_checkDL,0xe0);
          gx::GXCallDisplayList(&d_drawlist::l_frontNoZSubMat,0x20);
          gx::GXCallDisplayList(&d_drawlist::l_s_beam_checkDL,0xe0);
        }
        else {
          if (dVar1 == Cube) {
            gf::GFSetArray(GX_VA_POS,(int)&d_drawlist::l_cubePos,0xc);
            gx::GXCallDisplayList(&d_drawlist::l_backRevZMat,0x40);
            gx::GXCallDisplayList(&d_drawlist::l_frontZMat,0x20);
            gx::GXCallDisplayList(&d_drawlist::l_cubeDL,0x40);
          }
          else {
            if (dVar1 == Bonbori2) {
              gf::GFSetArray(GX_VA_POS,(int)&d_drawlist::l_bonbori2Pos,0xc);
              gx::GXCallDisplayList(&d_drawlist::l_backRevZMat,0x40);
              gx::GXCallDisplayList(&d_drawlist::l_bonbori2DL,0x2a0);
              gx::GXCallDisplayList(&d_drawlist::l_frontZMat,0x20);
              gx::GXCallDisplayList(&d_drawlist::l_bonbori2DL,0x2a0);
              gx::GXCallDisplayList(&d_drawlist::l_frontNoZSubMat,0x20);
              gx::GXCallDisplayList(&d_drawlist::l_bonbori2DL,0x2a0);
            }
          }
        }
      }
    }
  }
  return;
}


/* __thiscall dDlst_alphaModel_c::dDlst_alphaModel_c(void) */

void __thiscall dDlst_alphaModel_c::dDlst_alphaModel_c(dDlst_alphaModel_c *this)

{
  this->mCapacity = 0;
  this->mpData = (dDlst_alphaModelData_c *)0x0;
  this->mCount = 0;
  return;
}


namespace dDlst_alphaModel_c {

/* __thiscall create(int) */

dDlst_alphaModel_c * create(int param_1)

{
  JKRHeap *this;
  undefined4 uVar1;
  int iVar2;
  
  this = (JKRHeap *)JKernel::operator_new(0xc);
  if (this != (JKRHeap *)0x0) {
    dDlst_alphaModel_c((dDlst_alphaModel_c *)this);
  }
  if (this != (JKRHeap *)0x0) {
    uVar1 = JKernel::operator_new__(param_1 * 8 + 0x10);
    iVar2 = Runtime.PPCEABI.H::__construct_new_array
                      (uVar1,dDlst_alphaModelData_c::dDlst_alphaModelData_c,
                       dDlst_alphaModelData_c::_dDlst_alphaModelData_c,8,param_1);
    if (iVar2 != 0) {
      *(int *)&this->field_0x8 = iVar2;
      *(short *)&this->field_0x4 = (short)param_1;
      return (dDlst_alphaModel_c *)this;
    }
    if (this != (JKRHeap *)0x0) {
      JKernel::operator_delete(this);
    }
  }
  return (dDlst_alphaModel_c *)(JKRHeap *)0x0;
}

}

/* __thiscall dDlst_alphaModelData_c::~dDlst_alphaModelData_c(void) */

void __thiscall dDlst_alphaModelData_c::_dDlst_alphaModelData_c(dDlst_alphaModelData_c *this)

{
  short in_r4;
  
  if ((this != (dDlst_alphaModelData_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dDlst_alphaModelData_c::dDlst_alphaModelData_c(void) */

void __thiscall dDlst_alphaModelData_c::dDlst_alphaModelData_c(dDlst_alphaModelData_c *this)

{
  return;
}


/* __thiscall dDlst_alphaModel_c::set(unsigned char,
                                      float *[][][][],
                                      unsigned char) */

bool __thiscall
dDlst_alphaModel_c::set
          (dDlst_alphaModel_c *this,dDlst_alphaModelData__Type type,MTX34 *pMtx,byte alpha)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = (int)(short)this->mCount;
  bVar1 = iVar2 < (short)this->mCapacity;
  if (bVar1) {
    dDlst_alphaModelData_c::set(this->mpData + iVar2,type,pMtx,alpha);
    this->mCount = this->mCount + 1;
  }
  return bVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dDlst_alphaModel_c::draw(float *[][][][]) */

undefined4 __thiscall dDlst_alphaModel_c::draw(dDlst_alphaModel_c *this,MTX34 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  dDlst_alphaModelData_c *this_00;
  
  if (this->mCount == 0) {
    uVar1 = 0;
  }
  else {
    gx::GXCallDisplayList(&d_drawlist::l_matDL_5108,0x60);
    gf::GFSetVtxDescv(&d_drawlist::l_vtxDescList_5111);
    gf::GFSetVtxAttrFmtv(0,&d_drawlist::l_vtxAttrFmtList_5112);
    gx::GXSetClipMode(false);
    this_00 = this->mpData;
    for (iVar2 = 0; iVar2 < (short)this->mCount; iVar2 = iVar2 + 1) {
      dDlst_alphaModelData_c::draw(this_00,param_1);
      this_00 = this_00 + 1;
    }
    gf::GFSetBlendModeEtc(0,0,0,0,1,0,1);
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall dDlst_alphaModelPacket::draw(void) */

void __thiscall dDlst_alphaModelPacket::draw(dDlst_alphaModelPacket *this)

{
  byte bVar1;
  _GXColor local_48;
  undefined4 local_44;
  MTX34 MStack64;
  
  gx::GXSetNumChans(1);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  local_44 = *(undefined4 *)&this->field_0x11;
  gx::GXSetChanMatColor(4,&local_44);
  gx::GXSetNumTexGens(0);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_RASC);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_RASA);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetZCompLoc(1);
  gx::GXSetZMode(true,GX_LEQUAL,false);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_CLEAR);
  gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
  local_48 = d_com_inf_game::g_clearColor;
  gx::GXSetFog(GX_FOG_NONE,d_drawlist::0_0,d_drawlist::0_0,d_drawlist::0_0,d_drawlist::0_0,&local_48
              );
  gx::GXSetCullMode(1);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,(MTX34 *)this[1].parent.mpNextSibling,&MStack64
                  );
  gx::GXLoadPosMtxImm(&MStack64,0);
  gx::GXSetCurrentMtx(0);
  bVar1 = this->mType;
  if (bVar1 == 0) {
    gx::GXSetArray(GX_VA_POS,d_drawlist::l_bonboriPos,0xc);
    gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
  }
  else {
    if (bVar1 == 1) {
      gx::GXSetArray(GX_VA_POS,d_drawlist::l_bonboriPos,0xc);
      gx::GXCallDisplayList(&d_drawlist::l_bonboriDL,0xa0);
    }
    else {
      if (bVar1 == 2) {
        gx::GXSetArray(GX_VA_POS,&d_drawlist::l_s_beam_checkPos,0xc);
        gx::GXCallDisplayList(&d_drawlist::l_s_beam_checkDL,0xe0);
      }
      else {
        if (bVar1 == 3) {
          gx::GXSetArray(GX_VA_POS,&d_drawlist::l_cubePos,0xc);
          gx::GXCallDisplayList(&d_drawlist::l_cubeDL,0x40);
        }
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dDlst_shadowPoly_c::set(cBgD_Vtx_t *,
                                      unsigned short,
                                      unsigned short,
                                      unsigned short,
                                      cM3dGPla *) */

bool __thiscall
dDlst_shadowPoly_c::set
          (dDlst_shadowPoly_c *this,cBgD_Vtx_t *param_1,ushort param_2,ushort param_3,ushort param_4
          ,cM3dGPla *param_5)

{
  bool bVar1;
  int iVar2;
  cXyz *pcVar3;
  cXyz local_38;
  cXyz local_2c;
  
  iVar2 = (**(code **)(this->vtbl + 0x10))();
  bVar1 = (int)(uint)this->mCount < iVar2;
  if (bVar1) {
    iVar2 = (**(code **)(this->vtbl + 0xc))(this);
    pcVar3 = (cXyz *)(iVar2 + (uint)this->mCount * 0x24);
    ::cXyz::operator_(&local_38,(cXyz *)param_5,d_drawlist::_4939);
    local_2c.x = local_38.x;
    local_2c.y = local_38.y;
    local_2c.z = local_38.z;
    mtx::PSVECAdd((cXyz *)(param_1 + param_2),&local_2c,pcVar3);
    mtx::PSVECAdd((cXyz *)(param_1 + param_3),&local_2c,pcVar3 + 1);
    mtx::PSVECAdd((cXyz *)(param_1 + param_4),&local_2c,pcVar3 + 2);
    this->mCount = this->mCount + 1;
  }
  return bVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dDlst_shadowPoly_c::set(cXyz &,
                                      cXyz &,
                                      cXyz &) */

bool __thiscall
dDlst_shadowPoly_c::set(dDlst_shadowPoly_c *this,cXyz *param_1,cXyz *param_2,cXyz *param_3)

{
  bool bVar1;
  int iVar2;
  dDlst_shadowTri_c *pTri;
  dDlst_shadowTri_c *pdVar3;
  
  iVar2 = (**(code **)(this->vtbl + 0x10))();
  bVar1 = (int)(uint)this->mCount < iVar2;
  if (bVar1) {
    pTri = (dDlst_shadowTri_c *)(**(code **)(this->vtbl + 0xc))(this);
    pdVar3 = pTri + this->mCount;
    pdVar3->mPos[0].x = param_1->x;
    pdVar3->mPos[0].y = param_1->y;
    pdVar3->mPos[0].z = param_1->z;
    pdVar3->mPos[1].x = param_2->x;
    pdVar3->mPos[1].y = param_2->y;
    pdVar3->mPos[1].z = param_2->z;
    pdVar3->mPos[2].x = param_3->x;
    pdVar3->mPos[2].y = param_3->y;
    pdVar3->mPos[2].z = param_3->z;
    this->mCount = this->mCount + 1;
  }
  return bVar1;
}


/* __thiscall dDlst_shadowPoly_c::draw(void) */

void __thiscall dDlst_shadowPoly_c::draw(dDlst_shadowPoly_c *this)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(**(code **)(this->vtbl + 0xc))();
  gx::GXBegin(0x90,0,this->mCount * 3);
  for (iVar2 = 0; iVar2 < (int)(uint)this->mCount; iVar2 = iVar2 + 1) {
    write_volatile_4(0xcc008000,puVar1[6]);
    write_volatile_4(0xcc008000,puVar1[7]);
    write_volatile_4(0xcc008000,puVar1[8]);
    write_volatile_4(0xcc008000,puVar1[3]);
    write_volatile_4(0xcc008000,puVar1[4]);
    write_volatile_4(0xcc008000,puVar1[5]);
    write_volatile_4(0xcc008000,*puVar1);
    write_volatile_4(0xcc008000,puVar1[1]);
    write_volatile_4(0xcc008000,puVar1[2]);
    puVar1 = puVar1 + 9;
  }
  return;
}


/* __thiscall dDlst_shadowReal_c::~dDlst_shadowReal_c(void) */

void __thiscall dDlst_shadowReal_c::_dDlst_shadowReal_c(dDlst_shadowReal_c *this)

{
  short in_r4;
  
  if (this != (dDlst_shadowReal_c *)0x0) {
    JKernel::operator_delete((JKRHeap *)this->mpTexData);
    J3DDrawBuffer::_J3DDrawBuffer(this->mpDrawBuffer);
    if (this != (dDlst_shadowReal_c *)0xffffff54) {
      (this->mShadowPoly).vtbl = (undefined *)&dDlst_shadowRealPoly_c::__vt;
      Runtime.PPCEABI.H::__destroy_arr
                (this->mShadowTri,dDlst_shadowTri_c::_dDlst_shadowTri_c,0x24,0x100);
      if (this != (dDlst_shadowReal_c *)0xffffff54) {
        (this->mShadowPoly).vtbl = (undefined *)&dDlst_shadowPoly_c::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_shadowTri_c::~dDlst_shadowTri_c(void) */

void __thiscall dDlst_shadowTri_c::_dDlst_shadowTri_c(dDlst_shadowTri_c *this)

{
  short in_r4;
  
  if ((this != (dDlst_shadowTri_c *)0x0) &&
     (Runtime.PPCEABI.H::__destroy_arr(this,::cXyz::_cXyz,0xc,3), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_drawlist {

J3DDrawBuffer * J3DDrawBuffer__create__FUl(ulong param_1)

{
  J3DDrawBuffer *this;
  int iVar1;
  
  this = (J3DDrawBuffer *)JKernel::operator_new(0x24);
  if (this != (J3DDrawBuffer *)0x0) {
    J3DDrawBuffer::initialize(this);
    iVar1 = J3DDrawBuffer::allocBuffer(this,param_1);
    if (iVar1 == 0) {
      return this;
    }
    J3DDrawBuffer::_J3DDrawBuffer(this);
  }
  return (J3DDrawBuffer *)0x0;
}

}

/* __thiscall dDlst_shadowReal_c::init(void) */

int __thiscall dDlst_shadowReal_c::init(dDlst_shadowReal_c *this)

{
  undefined4 uVar1;
  void *pvVar2;
  J3DCallBackPacket *pJVar3;
  J3DDrawBuffer *pJVar4;
  double dVar5;
  
  uVar1 = gx::GXGetTexBufferSize(0x80,0x80,0,0,0);
  pvVar2 = (void *)JKernel::operator_new__(uVar1,0x20);
  this->mpTexData = pvVar2;
  gx::GXInitTexObj(&this->mTexData,this->mpTexData,0x80,0x80,GX_TF_I4,GX_CLAMP,GX_CLAMP,false);
  dVar5 = (double)d_drawlist::0_0;
  gx::GXInitTexObjLOD(dVar5,dVar5,dVar5,&this->mTexData,1,1,0,0,0);
  pJVar3 = (J3DCallBackPacket *)JKernel::operator_new(0x14);
  if (pJVar3 != (J3DCallBackPacket *)0x0) {
    (pJVar3->parent).vtbl = (undefined *)&J3DPacket::__vt;
    (pJVar3->parent).mpNextSibling = (J3DPacket *)0x0;
    (pJVar3->parent).mpFirstChild = (J3DPacket *)0x0;
    (pJVar3->parent).field_0xc = (undefined *)0x0;
    (pJVar3->parent).vtbl = &J3DCallBackPacket::__vt;
    pJVar3->mCallBack = (undefined *)0x0;
  }
  this->mpPacket = pJVar3;
  pJVar4 = (J3DDrawBuffer *)JKernel::operator_new(0x24);
  if (pJVar4 != (J3DDrawBuffer *)0x0) {
    J3DDrawBuffer::initialize(pJVar4);
    J3DDrawBuffer::allocBuffer(pJVar4,0x20);
  }
  this->mpDrawBuffer = pJVar4;
  pJVar4 = this->mpDrawBuffer;
  pJVar4->mSortType = 4;
  return (int)pJVar4;
}


/* __thiscall dDlst_shadowReal_c::reset(void) */

void __thiscall dDlst_shadowReal_c::reset(dDlst_shadowReal_c *this)

{
  if (this->mState == 1) {
    this->mState = 2;
  }
  else {
    this->mState = 0;
    this->field_0x1 = 0xff;
  }
  J3DDrawBuffer::frameInit(this->mpDrawBuffer);
  this->mModelNum = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dDlst_shadowReal_c::imageDraw(float *[][][][]) */

void __thiscall dDlst_shadowReal_c::imageDraw(dDlst_shadowReal_c *this,float *param_1)

{
  J3DShapePacket *this_00;
  J3DModelData *pJVar1;
  ushort uVar2;
  byte bVar3;
  J3DModel **ppJVar4;
  
  if (this->mState == 1) {
    gx::GXSetProjection(&this->mRenderProjMtx,GX_ORTHOGRAPHIC);
    if (this->mModelNum == 0) {
      mtx::PSMTXCopy(&this->mViewMtx,&J3DGraphBase::j3dSys.mCurViewMtx);
      J3DDrawBuffer::draw(this->mpDrawBuffer);
    }
    else {
      ppJVar4 = this->mpModels;
      _sOldVcdVatCmd = 0;
      for (bVar3 = 0; bVar3 < this->mModelNum; bVar3 = bVar3 + 1) {
        (*(code *)(*ppJVar4)->vtbl->viewCalc)();
        pJVar1 = (*ppJVar4)->mpModelData;
        J3DShape::loadPreDrawSetting(*(pJVar1->mShapeTable).mpShapes);
        uVar2 = 0;
        while( true ) {
          if ((pJVar1->mShapeTable).mShapeCount <= uVar2) break;
          if (((pJVar1->mShapeTable).mpShapes[uVar2]->mVisFlags & 1U) == 0) {
            this_00 = (*ppJVar4)->mpShapePackets + uVar2;
            this_00->mpViewMtx = &this->mViewMtx;
            J3DShapePacket::drawFast(this_00);
            this_00->mpViewMtx = (MTX34 *)param_1;
          }
          uVar2 = uVar2 + 1;
        }
        ppJVar4 = ppJVar4 + 1;
      }
      _sOldVcdVatCmd = 0;
    }
    gx::GXCopyTex(this->mpTexData,1);
    gx::GXPixModeSync();
  }
  return;
}


/* __thiscall dDlst_shadowReal_c::draw(void) */

void __thiscall dDlst_shadowReal_c::draw(dDlst_shadowReal_c *this)

{
  _GXColor local_48;
  MTX34 MStack68;
  
  if (this->mState == 1) {
    d_drawlist::l_color_5298 =
         (_GXColor)
         ((uint)d_drawlist::l_color_5298 & 0xffffff00 | (int)(uint)this->mAlpha >> 2 & 0xfffffffcU);
    local_48 = d_drawlist::l_color_5298;
    gx::GXSetTevColor(GX_TEVREG0,&local_48);
    gx::GXCallDisplayList(&d_drawlist::l_shadowVolMat,0x40);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
    mtx::PSMTXCopy(&this->mViewMtx,&mDoMtx_stack_c::now);
    mtx::PSMTXInverse(&mDoMtx_stack_c::now,&mDoMtx_stack_c::now);
    mtx::PSMTXInverse(&this->mRenderProjMtx,&MStack68);
    MStack68.m[2][3] = d_drawlist::0_0;
    mtx::PSMTXConcat(&mDoMtx_stack_c::now,&MStack68,&mDoMtx_stack_c::now);
    mDoMtx_stack_c::scaleM(d_drawlist::1_0,d_drawlist::1_0,d_drawlist::_0_003);
    mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&mDoMtx_stack_c::now,&MStack68);
    gx::GXLoadPosMtxImm(&MStack68,3);
    gx::GXSetCurrentMtx(3);
    gx::GXCallDisplayList(&d_drawlist::l_shadowVolDL,0x40);
    gx::GXCallDisplayList(&d_drawlist::l_frontZMat,0x20);
    gx::GXCallDisplayList(&d_drawlist::l_shadowVolDL,0x40);
    gx::GXCallDisplayList(&d_drawlist::l_frontNoZSubMat,0x20);
    gx::GXCallDisplayList(&d_drawlist::l_shadowVolDL,0x40);
    gx::GXCallDisplayList(&d_drawlist::l_shadowProjMat,0x40);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
    gx::GXLoadTexObj(&this->mTexData,0);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    gx::GXSetCurrentMtx(0);
    gx::GXLoadTexMtxImm(&this->mReceiverProjMtx,GX_TEXMTX0,0);
    dDlst_shadowPoly_c::draw(&this->mShadowPoly);
    gx::GXCallDisplayList(&d_drawlist::l_clearMat,0x40);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
    gx::GXSetCurrentMtx(3);
    gx::GXCallDisplayList(&d_drawlist::l_shadowVolDL,0x40);
  }
  return;
}


namespace d_drawlist {

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Unknown calling convention yet parameter storage is locked */
/* __stdcall psdRealCallBack(cBgS_ShdwDraw *,
                             cBgD_Vtx_t *,
                             int,
                             int,
                             int,
                             cM3dGPla *) */

undefined * psdRealCallBack(void)

{
  float fVar1;
  float fVar2;
  int in_r3;
  float *pfVar3;
  undefined *puVar4;
  cBgD_Vtx_t *in_r4;
  cBgD_Vtx_t *pcVar5;
  int in_r5;
  cBgD_Vtx_t *pcVar6;
  int in_r6;
  cBgD_Vtx_t *pcVar7;
  int in_r7;
  cM3dGPla *in_r8;
  double dVar8;
  
  dVar8 = (double)mtx::PSVECDotProduct(*(undefined4 *)(in_r3 + 0x38),in_r8);
  if (dVar8 < (double)_5371) {
    pfVar3 = *(float **)(in_r3 + 0x34);
    fVar1 = (in_r8->mNorm).y;
    if (_5372 < (in_r8->mNorm).z * pfVar3[2] + (in_r8->mNorm).x * *pfVar3 + fVar1 * pfVar3[1] +
                in_r8->mDist) {
      pcVar5 = in_r4 + in_r5;
      pcVar6 = in_r4 + in_r6;
      pcVar7 = in_r4 + in_r7;
      if ((((0_0 < fVar1) ||
           (((fVar2 = *(float *)(in_r3 + 0x18), fVar2 <= (pcVar5->v).y && (fVar2 <= (pcVar6->v).y))
            && (fVar2 <= (pcVar7->v).y)))) &&
          ((((fVar1 <= 0_0 || (fVar1 = *(float *)(in_r3 + 0x18), fVar1 <= (pcVar5->v).y)) ||
            (fVar1 <= (pcVar6->v).y)) || (fVar1 <= (pcVar7->v).y)))) &&
         (((fVar1 = *(float *)(in_r3 + 0x24), (pcVar5->v).y <= fVar1 || ((pcVar6->v).y <= fVar1)) ||
          ((pcVar7->v).y <= fVar1)))) {
        fVar1 = (pcVar5->v).x;
        fVar2 = *(float *)(in_r3 + 0x14);
        if ((((fVar2 <= fVar1) || (fVar2 <= (pcVar6->v).x)) || (fVar2 <= (pcVar7->v).x)) &&
           (((fVar2 = *(float *)(in_r3 + 0x20), fVar1 <= fVar2 || ((pcVar6->v).x <= fVar2)) ||
            ((pcVar7->v).x <= fVar2)))) {
          fVar1 = (pcVar5->v).z;
          fVar2 = *(float *)(in_r3 + 0x1c);
          if ((((fVar2 <= fVar1) || (fVar2 <= (pcVar6->v).z)) || (fVar2 <= (pcVar7->v).z)) &&
             (((fVar2 = *(float *)(in_r3 + 0x28), fVar1 <= fVar2 || ((pcVar6->v).z <= fVar2)) ||
              ((pcVar7->v).z <= fVar2)))) {
            puVar4 = (undefined *)
                     ::dDlst_shadowPoly_c::set
                               (*(dDlst_shadowPoly_c **)(in_r3 + 0x3c),in_r4,(ushort)in_r5,
                                (ushort)in_r6,(ushort)in_r7,in_r8);
            return puVar4;
          }
        }
      }
      return &DAT_00000001;
    }
  }
  return &DAT_00000001;
}


/* __stdcall seaRealCallBack(void *,
                             cXyz &,
                             cXyz &,
                             cXyz &) */

void seaRealCallBack(int param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x18);
  if ((((fVar1 <= param_2->y) || (fVar1 <= param_3->y)) || (fVar1 <= param_4->y)) &&
     (((fVar1 = *(float *)(param_1 + 0x24), param_2->y <= fVar1 || (param_3->y <= fVar1)) ||
      (param_4->y <= fVar1)))) {
    ::dDlst_shadowPoly_c::set(*(dDlst_shadowPoly_c **)(param_1 + 0x3c),param_2,param_3,param_4);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall realPolygonCheck(cXyz *,
                              float,
                              float,
                              cXyz *,
                              dDlst_shadowPoly_c *) */

undefined4
realPolygonCheck
          (double param_1,double param_2,float *param_3,float *param_4,undefined4 param_5)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  undefined4 uVar4;
  cXyz local_78;
  cXyz local_6c;
  undefined local_60 [12];
  bool local_54;
  cBgS_Chk__vtbl *local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  cM3dGAab__vtbl *local_34;
  code *local_30;
  float *local_2c;
  float *local_28;
  undefined4 local_24;
  
  local_60._0_4_ = (cBgS_PolyPassChk *)0x0;
  local_60._4_4_ = (cBgS_GrpPassChk *)0x0;
  local_54 = true;
  local_34 = &::cM3dGAab::__vt;
  local_50 = (cBgS_Chk__vtbl *)&::ShdwDrawPoly_c::__vt;
  fVar1 = _5491 * (float)(param_1 * param_1);
  if (_5492 < fVar1) {
    fVar1 = _5492;
  }
  fVar1 = (float)(param_1 + param_2) - fVar1;
  local_6c.y = param_3[1] - fVar1;
  local_78.y = param_3[1] + (float)((double)_5493 * param_1);
  local_6c.x = *param_3;
  fVar2 = local_6c.x + *param_4 * fVar1;
  local_78.x = fVar2;
  if (fVar2 < local_6c.x) {
    local_78.x = local_6c.x;
    local_6c.x = fVar2;
  }
  local_6c.x = (float)((double)local_6c.x - param_1);
  local_78.x = (float)((double)local_78.x + param_1);
  local_6c.z = param_3[2];
  fVar1 = local_6c.z + param_4[2] * fVar1;
  local_78.z = fVar1;
  if (fVar1 < local_6c.z) {
    local_78.z = local_6c.z;
    local_6c.z = fVar1;
  }
  local_6c.z = (float)((double)local_6c.z - param_1);
  local_78.z = (float)((double)local_78.z + param_1);
  mDoLib_clipper::mClipper.mFar = _5494 * mDoLib_clipper::mFovyRate;
  J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
  uVar3 = J3DUClipper::clip(&mDoLib_clipper::mClipper,&J3DGraphBase::j3dSys.mCurViewMtx,&local_78,
                            &local_6c);
  mDoLib_clipper::mClipper.mFar = mDoLib_clipper::mSystemFar;
  J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
  if (uVar3 == 0) {
    local_4c = local_6c.x;
    local_48 = local_6c.y;
    local_44 = local_6c.z;
    local_40 = local_78.x;
    local_3c = local_78.y;
    local_38 = local_78.z;
    local_30 = psdRealCallBack;
    local_2c = param_3;
    local_28 = param_4;
    local_24 = param_5;
    cBgS::ShdwDraw((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,(cBgS_ShdwDraw *)local_60);
    d_a_sea::daSea_GetPoly(local_60,seaRealCallBack,&local_6c,&local_78);
    local_50 = (cBgS_Chk__vtbl *)&::cBgS_ShdwDraw::__vt;
    if ((undefined *)register0x00000004 != &DAT_0000004c) {
      local_34 = &::cM3dGAab::__vt;
    }
    cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_60);
    uVar4 = 1;
  }
  else {
    local_50 = (cBgS_Chk__vtbl *)&::cBgS_ShdwDraw::__vt;
    if ((undefined *)register0x00000004 != &DAT_0000004c) {
      local_34 = &::cM3dGAab::__vt;
    }
    cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_60);
    uVar4 = 0;
  }
  return uVar4;
}

}

/* __thiscall ShdwDrawPoly_c::~ShdwDrawPoly_c(void) */

void __thiscall ShdwDrawPoly_c::_ShdwDrawPoly_c(ShdwDrawPoly_c *this)

{
  short in_r4;
  
  if (this != (ShdwDrawPoly_c *)0x0) {
    *(undefined1 **)(this + 0x10) = &__vt;
    if (this != (ShdwDrawPoly_c *)0x0) {
      *(undefined1 **)(this + 0x10) = &cBgS_ShdwDraw::__vt;
      if (this != (ShdwDrawPoly_c *)0xffffffec) {
        *(cM3dGAab__vtbl **)(this + 0x2c) = &::cM3dGAab::__vt;
      }
      cBgS_Chk::_cBgS_Chk((cBgS_Chk *)this);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cBgS_ShdwDraw::~cBgS_ShdwDraw(void) */

void __thiscall cBgS_ShdwDraw::_cBgS_ShdwDraw(cBgS_ShdwDraw *this)

{
  short in_r4;
  
  if (this != (cBgS_ShdwDraw *)0x0) {
    *(undefined1 **)&this->field_0x10 = &__vt;
    if (this != (cBgS_ShdwDraw *)0xffffffec) {
      (this->mAab).vtbl = &::cM3dGAab::__vt;
    }
    cBgS_Chk::_cBgS_Chk((cBgS_Chk *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_drawlist {

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x800844e4) */
/* WARNING: Removing unreachable block (ram,0x800844dc) */
/* WARNING: Removing unreachable block (ram,0x800844ec) */
/* __stdcall setShadowRealMtx(float *[][][][],
                              float *[][][][],
                              float *[][][][],
                              cXyz *,
                              cXyz *,
                              float,
                              float,
                              dDlst_shadowPoly_c *,
                              float) */

uint setShadowRealMtx
               (MTX34 *pDstView,MTX44 *pDstRenderProj,MTX34 *pDstReceiverProj,cXyz *pLightPos,
               cXyz *pPos,float param_6,float param_7,dDlst_shadowPoly_c *pPoly,float param_9)

{
  float fVar1;
  uint uVar2;
  char cVar4;
  int iVar3;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  float fVar10;
  cXyz cStack144;
  cXyz local_84;
  cXyz local_78;
  cXyz local_6c;
  cXyz local_60;
  longlong local_50;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar9 = (double)param_7;
  dVar8 = (double)param_6;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  pPoly->mCount = 0;
  if (param_9 < 1_0) {
    fVar1 = 1_0 - param_9;
    if (1_0 < 1_0 - param_9) {
      fVar1 = 1_0;
    }
    fVar1 = _5594 * fVar1;
    local_50 = (longlong)(int)fVar1;
    ::cXyz::operator__(&local_78,pLightPos,pPos);
    local_60.x = local_78.x;
    local_60.z = local_78.z;
    local_60.y = (float)((double)local_78.y + dVar9);
    fVar10 = _5595 * (float)((double)_5596 - dVar9);
    if (0_0 <= fVar10) {
      if (fVar10 < 1_0) {
        local_60.x = local_78.x * fVar10;
        local_60.z = local_78.z * fVar10;
      }
    }
    else {
      local_60.x = 0_0;
      local_60.z = 0_0;
    }
    fVar10 = mtx::PSVECSquareMag(&local_60);
    dVar7 = (double)fVar10;
    if ((double)0_0 < dVar7) {
      dVar6 = 1.0 / SQRT(dVar7);
      dVar6 = _5597 * dVar6 * (_5598 - dVar7 * dVar6 * dVar6);
      dVar6 = _5597 * dVar6 * (_5598 - dVar7 * dVar6 * dVar6);
      dVar7 = (double)(float)(dVar7 * _5597 * dVar6 * (_5598 - dVar7 * dVar6 * dVar6));
    }
    if ((double)0_0 != dVar7) {
      if ((double)(float)((double)local_60.y / dVar7) < (double)_5599) {
        local_60.y = (float)((double)_5599 * dVar7);
        fVar10 = mtx::PSVECSquareMag(&local_60);
        dVar7 = (double)fVar10;
        if ((double)0_0 < dVar7) {
          dVar6 = 1.0 / SQRT(dVar7);
          dVar6 = _5597 * dVar6 * (_5598 - dVar7 * dVar6 * dVar6);
          dVar6 = _5597 * dVar6 * (_5598 - dVar7 * dVar6 * dVar6);
          dVar7 = (double)(float)(dVar7 * _5597 * dVar6 * (_5598 - dVar7 * dVar6 * dVar6));
        }
      }
      dVar7 = (double)(float)((double)(float)((double)0_5 * dVar8) / dVar7);
    }
    mtx::PSVECScale(&local_60,&local_60,(float)dVar7);
    mtx::PSVECAdd(&local_60,pPos,&local_60);
    dVar8 = (double)(float)((double)_5493 * dVar8);
    ::cXyz::operator__(&local_84,pPos,&local_60);
    local_6c.x = local_84.x;
    local_6c.y = local_84.y;
    local_6c.z = local_84.z;
    cVar4 = ::cXyz::isZero(&local_6c);
    if (cVar4 == '\0') {
      ::cXyz::normalize(&cStack144);
    }
    else {
      local_6c.y = _5600;
      local_60.y = 1_0 + pPos->y;
    }
    iVar3 = realPolygonCheck(dVar8,dVar9,pPos,&local_6c,pPoly);
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      m_Do_mtx::mDoMtx_lookAt(pDstView,&local_60,pPos,0);
      dVar9 = -dVar8;
      mtx::C_MTXOrtho((float)dVar8,(float)dVar9,(float)dVar9,(float)dVar8,1_0,10000_0,pDstRenderProj
                     );
      mtx::C_MTXLightOrtho
                ((float)dVar8,(float)dVar9,(float)dVar9,(float)dVar8,0_5,_0_5,0_5,0_5,
                 pDstReceiverProj);
      mtx::PSMTXConcat(pDstReceiverProj,pDstView,pDstReceiverProj);
      uVar2 = (int)fVar1 & 0xff;
    }
  }
  else {
    uVar2 = 0;
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  return uVar2;
}

}

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x800846a0) */
/* WARNING: Removing unreachable block (ram,0x800846a8) */
/* __thiscall dDlst_shadowReal_c::set(unsigned long,
                                      signed char,
                                      J3DModel *,
                                      cXyz *,
                                      float,
                                      float,
                                      dKy_tevstr_c *) */

int __thiscall
dDlst_shadowReal_c::set
          (dDlst_shadowReal_c *this,ulong param_1,char param_2,J3DModel *pModel,cXyz *param_4,
          float param_5,float param_6,dKy_tevstr_c *param_7)

{
  float fVar1;
  J3DDrawBuffer *pJVar2;
  J3DDrawBuffer *pJVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f30;
  undefined8 in_f31;
  TVec3_float_ local_58;
  cXyz local_4c;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar8 = (double)param_6;
  dVar7 = (double)param_5;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if ((this->mState != 1) || (param_1 != this->mID)) {
    d_kankyo::dKy_plight_near_pos(&local_58);
    local_4c.x = local_58.x;
    local_4c.y = local_58.y;
    local_4c.z = local_58.z;
    if (param_7 != (dKy_tevstr_c *)0x0) {
      local_4c.x = (param_7->mLightPosWorld).x;
      local_4c.y = (param_7->mLightPosWorld).y;
      local_4c.z = (param_7->mLightPosWorld).z;
    }
    fVar1 = d_drawlist::0_0;
    if (param_2 != '\0') {
      fVar1 = (float)((double)d_drawlist::_5647 * dVar8);
    }
    uVar4 = d_drawlist::setShadowRealMtx
                      (&this->mViewMtx,&this->mRenderProjMtx,&this->mReceiverProjMtx,&local_4c,
                       param_4,(float)dVar7,(float)dVar8,&this->mShadowPoly,fVar1);
    this->mAlpha = (byte)uVar4;
    if (this->mAlpha == 0) {
      iVar5 = 0;
      goto LAB_800846a0;
    }
    this->mState = 1;
    this->mID = param_1;
    this->field_0x1 = param_2;
    J3DDrawBuffer::setCallBackPacket(this->mpDrawBuffer,this->mpPacket);
    this->mModelNum = 0;
  }
  pJVar3 = J3DGraphBase::j3dSys.mpCurDrawBuffers[1];
  pJVar2 = J3DGraphBase::j3dSys.mpCurDrawBuffers[0];
  mtx::PSMTXCopy(&this->mViewMtx,&J3DGraphBase::j3dSys.mCurViewMtx);
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = this->mpDrawBuffer;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = J3DGraphBase::j3dSys.mpCurDrawBuffers[0];
  (*(code *)pModel->vtbl->entry)(pModel);
  J3DModel::lock(pModel);
  (*(code *)pModel->vtbl->viewCalc)(pModel);
  mtx::PSMTXCopy(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtx,
                 &J3DGraphBase::j3dSys.mCurViewMtx);
  iVar5 = this->mID;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = pJVar2;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = pJVar3;
LAB_800846a0:
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return iVar5;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8008481c) */
/* WARNING: Removing unreachable block (ram,0x80084824) */
/* __thiscall dDlst_shadowReal_c::set2(unsigned long,
                                       signed char,
                                       J3DModel *,
                                       cXyz *,
                                       float,
                                       float,
                                       dKy_tevstr_c *) */

int __thiscall
dDlst_shadowReal_c::set2
          (dDlst_shadowReal_c *this,ulong id,char param_2,J3DModel *pModel,cXyz *pPos,float param_5,
          float param_6,dKy_tevstr_c *pTevStr)

{
  byte bVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f30;
  undefined8 in_f31;
  TVec3_float_ local_58;
  cXyz lightPos;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar8 = (double)param_6;
  dVar7 = (double)param_5;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (this->mModelNum == 0) {
    d_kankyo::dKy_plight_near_pos(&local_58);
    lightPos.x = local_58.x;
    lightPos.y = local_58.y;
    lightPos.z = local_58.z;
    if (pTevStr != (dKy_tevstr_c *)0x0) {
      lightPos.x = (pTevStr->mLightPosWorld).x;
      lightPos.y = (pTevStr->mLightPosWorld).y;
      lightPos.z = (pTevStr->mLightPosWorld).z;
    }
    fVar2 = d_drawlist::0_0;
    if (param_2 != '\0') {
      fVar2 = (float)((double)d_drawlist::_5676 * dVar8);
    }
    uVar3 = d_drawlist::setShadowRealMtx
                      (&this->mViewMtx,&this->mRenderProjMtx,&this->mReceiverProjMtx,&lightPos,pPos,
                       (float)dVar7,(float)dVar8,&this->mShadowPoly,fVar2);
    this->mAlpha = (byte)uVar3;
    if (this->mAlpha == 0) {
      iVar4 = 0;
      goto LAB_8008481c;
    }
    this->mState = 1;
    this->mID = id;
    this->field_0x1 = param_2;
    this->mModelNum = 0;
  }
  if (0x19 < this->mModelNum) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_drawlist.cpp",3999,"mModelNum < MODEL_MAX");
    m_Do_printf::OSPanic("d_drawlist.cpp",3999,&DAT_80352c65);
  }
  bVar1 = this->mModelNum;
  this->mModelNum = bVar1 + 1;
  this->mpModels[bVar1] = pModel;
  iVar4 = this->mID;
LAB_8008481c:
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return iVar4;
}


/* __thiscall dDlst_shadowReal_c::add(J3DModel *) */

undefined4 __thiscall dDlst_shadowReal_c::add(dDlst_shadowReal_c *this,J3DModel *pModel)

{
  byte bVar1;
  undefined4 uVar2;
  ulong uVar3;
  
  if ((this->mModelNum == 0) || (pModel == (J3DModel *)0x0)) {
    uVar2 = 0;
  }
  else {
    if (0x19 < this->mModelNum) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_drawlist.cpp",0xfe0,"mModelNum < MODEL_MAX");
      m_Do_printf::OSPanic("d_drawlist.cpp",0xfe0,&DAT_80352c65);
    }
    bVar1 = this->mModelNum;
    this->mModelNum = bVar1 + 1;
    this->mpModels[bVar1] = pModel;
    uVar2 = 1;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDlst_shadowSimple_c::draw(void) */

void __thiscall dDlst_shadowSimple_c::draw(dDlst_shadowSimple_c *this)

{
  short sVar1;
  short sVar2;
  _GXColor local_18 [3];
  
  d_drawlist::l_color_5690 =
       (_GXColor)((uint)d_drawlist::l_color_5690 & 0xffffff00 | (uint)this->mAlpha);
  local_18[0] = d_drawlist::l_color_5690;
  gx::GXSetTevColor(GX_TEVREG0,local_18);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
  gx::GXLoadPosMtxImm(&this->mVolumeMtx,0);
  gx::GXSetCurrentMtx(0);
  gx::GXCallDisplayList(&d_drawlist::l_frontMat,0x40);
  gx::GXCallDisplayList(&d_drawlist::l_shadowVolumeDL,0x40);
  gx::GXCallDisplayList(&d_drawlist::l_backSubMat,0x20);
  gx::GXCallDisplayList(&d_drawlist::l_shadowVolumeDL,0x40);
  gx::GXLoadPosMtxImm(&this->mMtx,3);
  gx::GXSetCurrentMtx(3);
  if ((GXTexObj *)this->mpTexObj != (GXTexObj *)0x0) {
    gx::GXLoadTexObj((GXTexObj *)this->mpTexObj,0);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
    gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_TEXA,GX_CA_ZERO,GX_CA_A2,GX_CA_ZERO);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_COMP_RGB8_GT,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    sVar1 = gx::GXGetTexObjHeight(this->mpTexObj);
    sVar2 = gx::GXGetTexObjWidth(this->mpTexObj);
    if (sVar2 == sVar1) {
      gx::GXCallDisplayList(&d_drawlist::l_shadowSealTexDL,0x40);
    }
    else {
      gx::GXCallDisplayList(&d_drawlist::l_shadowSealTex2DL,0x40);
    }
  }
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
  gx::GXCallDisplayList(&d_drawlist::l_shadowSealDL,0x60);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
  gx::GXSetCurrentMtx(0);
  gx::GXCallDisplayList(&d_drawlist::l_clearMat,0x40);
  gx::GXCallDisplayList(&d_drawlist::l_shadowVolumeDL,0x40);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80084d20) */
/* WARNING: Removing unreachable block (ram,0x80084d10) */
/* WARNING: Removing unreachable block (ram,0x80084d18) */
/* WARNING: Removing unreachable block (ram,0x80084d28) */
/* __thiscall dDlst_shadowSimple_c::set(cXyz *,
                                        float,
                                        float,
                                        cXyz *,
                                        short,
                                        float,
                                        _GXTexObj *) */

void __thiscall
dDlst_shadowSimple_c::set
          (dDlst_shadowSimple_c *this,cXyz *pPos,float param_2,float param_3,cXyz *pFloorNrm,
          short rotY,float param_6,_GXTexObj *pTexObj)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar8;
  double dVar9;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar7 = (double)param_6;
  dVar6 = (double)param_3;
  dVar5 = (double)param_2;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  dVar8 = (double)(d_drawlist::1_0 +
                  (float)((double)d_drawlist::16_0 * dVar6) * (d_drawlist::1_0 - pFloorNrm->y));
  mtx::PSMTXTrans((double)pPos->x,(double)(float)(dVar5 + dVar8),(double)pPos->z,
                  &mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,rotY);
  dVar9 = (double)(float)(dVar6 * dVar7);
  mDoMtx_stack_c::scaleM
            ((float)dVar6,d_drawlist::16_0 + (float)(dVar8 + dVar8),(float)(dVar6 * dVar7));
  mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&mDoMtx_stack_c::now,&this->mVolumeMtx);
  dVar7 = (double)(d_drawlist::1_0 - pFloorNrm->x * pFloorNrm->x);
  if ((double)d_drawlist::0_0 < dVar7) {
    dVar8 = 1.0 / SQRT(dVar7);
    dVar8 = d_drawlist::_5597 * dVar8 * (d_drawlist::_5598 - dVar7 * dVar8 * dVar8);
    dVar8 = d_drawlist::_5597 * dVar8 * (d_drawlist::_5598 - dVar7 * dVar8 * dVar8);
    dVar7 = (double)(float)(dVar7 * d_drawlist::_5597 * dVar8 *
                                    (d_drawlist::_5598 - dVar7 * dVar8 * dVar8));
  }
  dVar4 = (double)d_drawlist::0_0;
  dVar8 = dVar4;
  if (dVar4 != dVar7) {
    dVar4 = (double)(float)((double)pFloorNrm->y * dVar7);
    dVar8 = (double)(float)(-(double)pFloorNrm->z * dVar7);
  }
  mDoMtx_stack_c::now.m[0][0] = (float)dVar7;
  mDoMtx_stack_c::now.m[0][1] = pFloorNrm->x;
  mDoMtx_stack_c::now.m[0][2] = d_drawlist::0_0;
  mDoMtx_stack_c::now.m[0][3] = pPos->x;
  mDoMtx_stack_c::now.m[1][0] = (float)(-(double)mDoMtx_stack_c::now.m[0][1] * dVar4);
  mDoMtx_stack_c::now.m[1][1] = pFloorNrm->y;
  mDoMtx_stack_c::now.m[1][2] = (float)dVar8;
  mDoMtx_stack_c::now.m[1][3] = (float)dVar5;
  mDoMtx_stack_c::now.m[2][0] = (float)((double)mDoMtx_stack_c::now.m[0][1] * dVar8);
  mDoMtx_stack_c::now.m[2][1] = pFloorNrm->z;
  mDoMtx_stack_c::now.m[2][2] = (float)dVar4;
  mDoMtx_stack_c::now.m[2][3] = pPos->z;
  m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,rotY);
  mDoMtx_stack_c::scaleM((float)dVar6,d_drawlist::1_0,(float)dVar9);
  mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&mDoMtx_stack_c::now,&this->mMtx);
  fVar1 = d_drawlist::1_0 - d_drawlist::_5647 * (float)((double)pPos->y - dVar5);
  fVar2 = d_drawlist::0_0;
  if ((d_drawlist::0_0 <= fVar1) && (fVar2 = fVar1, d_drawlist::1_0 < fVar1)) {
    fVar2 = d_drawlist::1_0;
  }
  this->mAlpha = (byte)(int)(d_drawlist::64_0 * fVar2);
  this->mpTexObj = pTexObj;
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  __psq_l0(auStack56,uVar3);
  __psq_l1(auStack56,uVar3);
  return;
}


/* __thiscall dDlst_shadowControl_c::init(void) */

int __thiscall dDlst_shadowControl_c::init(dDlst_shadowControl_c *this)

{
  int iVar1;
  int iVar2;
  dDlst_shadowReal_c *this_00;
  
  this_00 = this->mShadowReal;
  iVar2 = 0;
  do {
    iVar1 = dDlst_shadowReal_c::init(this_00);
    iVar2 = iVar2 + 1;
    this_00 = this_00 + 1;
  } while (iVar2 < 8);
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDlst_shadowControl_c::reset(void) */

void __thiscall dDlst_shadowControl_c::reset(dDlst_shadowControl_c *this)

{
  int iVar1;
  dDlst_shadowReal_c *this_00;
  
  this_00 = this->mShadowReal;
  iVar1 = 0;
  do {
    dDlst_shadowReal_c::reset(this_00);
    iVar1 = iVar1 + 1;
    this_00 = this_00 + 1;
  } while (iVar1 < 8);
  this->mShadowSimpleCount = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDlst_shadowControl_c::imageDraw(float *[][][][]) */

void __thiscall dDlst_shadowControl_c::imageDraw(dDlst_shadowControl_c *this,MTX34 *param_1)

{
  int iVar1;
  dDlst_shadowReal_c *this_00;
  double dVar2;
  
  dVar2 = (double)d_drawlist::0_0;
  gx::GXSetViewport(dVar2,dVar2,(double)d_drawlist::_4655,(double)d_drawlist::_4655,dVar2,
                    (double)d_drawlist::1_0);
  gx::GXSetScissor(0,0,0x100,0x100);
  gx::GXCallDisplayList(&d_drawlist::l_matDL_5761,0x80);
  gx::GXSetZMode(true,GX_LEQUAL,true);
  gx::GXSetBlendMode(GX_BM_NONE,GX_BL_ONE,GX_BL_ZERO,GX_LO_CLEAR);
  gx::GXSetClipMode(true);
  gx::GXSetTexCopySrc(0,0,0x100,0x100);
  gx::GXSetTexCopyDst(0x80,0x80,0,1);
  J3DGraphBase::j3dSys.mCurDrawMode = 3;
  this_00 = this->mShadowReal;
  iVar1 = 0;
  do {
    dDlst_shadowReal_c::imageDraw(this_00,(float *)param_1);
    iVar1 = iVar1 + 1;
    this_00 = this_00 + 1;
  } while (iVar1 < 8);
  gx::GXSetClipMode(false);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDlst_shadowControl_c::draw(float *[][][][]) */

void __thiscall dDlst_shadowControl_c::draw(dDlst_shadowControl_c *this,MTX34 *param_1)

{
  int iVar1;
  dDlst_shadowSimple_c *this_00;
  dDlst_shadowReal_c *this_01;
  _GXColor local_28;
  _GXColor local_24;
  undefined4 local_20;
  undefined4 local_1c [4];
  
  J3DSys::reinitGX(&J3DGraphBase::j3dSys);
  gx::GXSetNumIndStages(0);
  d_kankyo::dKy_GxFog_set();
  gx::GXSetChanCtrl(GX_ALPHA0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  local_20 = d_drawlist::_5773;
  local_1c[0] = d_drawlist::_5773;
  gx::GXSetChanMatColor(2,local_1c);
  gx::GXSetArray(GX_VA_POS,&d_drawlist::l_shadowVolPos,0xc);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX3x4,GX_TG_POS,GX_TEXMTX0,false,GX_PTIDENTITY);
  gx::GXSetNumTevStages(1);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXLoadPosMtxImm(param_1,0);
  d_drawlist::clearColor_5775 =
       (_GXColor)
       ((uint)d_drawlist::clearColor_5775 & 0xffffff00 | (uint)mDoGph_gInf_c::mBackColor.a);
  local_24 = d_drawlist::clearColor_5775;
  gx::GXSetTevColor(GX_TEVREG1,&local_24);
  local_28 = d_com_inf_game::g_whiteColor;
  gx::GXSetTevColor(GX_TEVREG2,&local_28);
  this_01 = this->mShadowReal;
  iVar1 = 0;
  do {
    dDlst_shadowReal_c::draw(this_01);
    iVar1 = iVar1 + 1;
    this_01 = this_01 + 1;
  } while (iVar1 < 8);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGB8,0);
  gx::GXSetArray(GX_VA_POS,&d_drawlist::l_simpleShadowPos,0xc);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
  this_00 = this->mShadowSimple;
  for (iVar1 = 0; iVar1 < (int)(uint)this->mShadowSimpleCount; iVar1 = iVar1 + 1) {
    dDlst_shadowSimple_c::draw(this_00);
    this_00 = this_00 + 1;
  }
  gx::GXSetColorUpdate(true);
  gx::GXSetAlphaUpdate(0);
  return;
}


/* __thiscall dDlst_shadowControl_c::setReal(unsigned long,
                                             signed char,
                                             J3DModel *,
                                             cXyz *,
                                             float,
                                             float,
                                             dKy_tevstr_c *) */

undefined4 __thiscall
dDlst_shadowControl_c::setReal
          (dDlst_shadowControl_c *this,ulong param_1,char param_2,J3DModel *param_3,cXyz *param_4,
          float param_5,float param_6,dKy_tevstr_c *param_7)

{
  undefined4 uVar1;
  dDlst_shadowReal_c *pdVar2;
  int iVar3;
  
  if (param_1 != 0) {
    pdVar2 = this->mShadowReal;
    iVar3 = 8;
    do {
      if ((pdVar2->mState != 0) && (pdVar2->mID == param_1)) {
        uVar1 = dDlst_shadowReal_c::set
                          (pdVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
        return uVar1;
      }
      pdVar2 = pdVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  pdVar2 = this->mShadowReal;
  iVar3 = 8;
  do {
    if (pdVar2->mState == 0) {
      do {
        iVar3 = this->mNextID + 1;
        this->mNextID = iVar3;
      } while (iVar3 == 0);
      uVar1 = dDlst_shadowReal_c::set
                        (pdVar2,this->mNextID,param_2,param_3,param_4,param_5,param_6,param_7);
      return uVar1;
    }
    pdVar2 = pdVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 0;
}


/* __thiscall dDlst_shadowControl_c::setReal2(unsigned long,
                                              signed char,
                                              J3DModel *,
                                              cXyz *,
                                              float,
                                              float,
                                              dKy_tevstr_c *) */

undefined4 __thiscall
dDlst_shadowControl_c::setReal2
          (dDlst_shadowControl_c *this,ulong id,char param_2,J3DModel *pModel,cXyz *pPos,
          float param_5,float param_6,dKy_tevstr_c *pTevStr)

{
  undefined4 uVar1;
  dDlst_shadowReal_c *pdVar2;
  int iVar3;
  
  if (id != 0) {
    pdVar2 = this->mShadowReal;
    iVar3 = 8;
    do {
      if ((pdVar2->mState != 0) && (pdVar2->mID == id)) {
        uVar1 = dDlst_shadowReal_c::set2(pdVar2,id,param_2,pModel,pPos,param_5,param_6,pTevStr);
        return uVar1;
      }
      pdVar2 = pdVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  pdVar2 = this->mShadowReal;
  iVar3 = 8;
  do {
    if (pdVar2->mState == 0) {
      do {
        iVar3 = this->mNextID + 1;
        this->mNextID = iVar3;
      } while (iVar3 == 0);
      uVar1 = dDlst_shadowReal_c::set2
                        (pdVar2,this->mNextID,param_2,pModel,pPos,param_5,param_6,pTevStr);
      return uVar1;
    }
    pdVar2 = pdVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 0;
}


/* __thiscall dDlst_shadowControl_c::addReal(unsigned long,
                                             J3DModel *) */

undefined4 __thiscall
dDlst_shadowControl_c::addReal(dDlst_shadowControl_c *this,ulong param_1,J3DModel *param_2)

{
  dDlst_shadowReal_c *this_00;
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 != 0) {
    this_00 = this->mShadowReal;
    iVar2 = 8;
    do {
      if ((this_00->mState != 0) && (this_00->mID == param_1)) {
        uVar1 = dDlst_shadowReal_c::add(this_00,param_2);
        return uVar1;
      }
      this_00 = this_00 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 0;
}


/* __thiscall dDlst_shadowControl_c::setSimple(cXyz *,
                                               float,
                                               float,
                                               cXyz *,
                                               short,
                                               float,
                                               _GXTexObj *) */

undefined4 __thiscall
dDlst_shadowControl_c::setSimple
          (dDlst_shadowControl_c *this,cXyz *pPos,float param_2,float param_3,cXyz *pFloorNrm,
          short rotY,float param_6,_GXTexObj *pTexObj)

{
  undefined4 uVar1;
  
  if ((pFloorNrm == (cXyz *)0x0) || (0x7f < this->mShadowSimpleCount)) {
    uVar1 = 0;
  }
  else {
    dDlst_shadowSimple_c::set
              (this->mShadowSimple + this->mShadowSimpleCount,pPos,param_2,param_3,pFloorNrm,rotY,
               param_6,pTexObj);
    this->mShadowSimpleCount = this->mShadowSimpleCount + 1;
    uVar1 = 1;
  }
  return uVar1;
}


namespace dDlst_shadowControl_c {

/* __thiscall setSimpleTex(void *) */

void setSimpleTex(void *param_1)

{
  double dVar1;
  
  gx::GXInitTexObj((GXTexObj *)&mSimpleTexObj,param_1,0x80,0x80,GX_TF_I4,GX_CLAMP,GX_CLAMP,false);
  dVar1 = (double)d_drawlist::0_0;
  gx::GXInitTexObjLOD(dVar1,dVar1,dVar1,&mSimpleTexObj,1,1,0,0,0);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dDlst_mirrorPacket::draw(void) */

void __thiscall dDlst_mirrorPacket::draw(dDlst_mirrorPacket *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  _GXColor local_28;
  _GXColor local_24;
  _GXColor local_20;
  
  J3DSys::reinitGX(&J3DGraphBase::j3dSys);
  gx::GXSetNumIndStages(0);
  d_kankyo::dKy_GxFog_set();
  d_drawlist::l_color_5884 =
       (_GXColor)
       ((uint)d_drawlist::l_color_5884 & 0xffffff00 | (int)(uint)this->mAlpha >> 2 & 0xfffffffcU);
  local_20 = d_drawlist::l_color_5884;
  gx::GXSetTevColor(GX_TEVREG0,&local_20);
  d_drawlist::l_color_5884 =
       (_GXColor)((uint)d_drawlist::l_color_5884 & 0xffffff00 | (uint)mDoGph_gInf_c::mBackColor.a);
  local_24 = d_drawlist::l_color_5884;
  gx::GXSetTevColor(GX_TEVREG1,&local_24);
  local_28 = d_com_inf_game::g_whiteColor;
  gx::GXSetTevColor(GX_TEVREG2,&local_28);
  gx::GXCallDisplayList(&d_drawlist::l_shadowVolMat,0x40);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXLoadPosMtxImm(&J3DGraphBase::j3dSys.mCurViewMtx,0);
  gx::GXSetArray(GX_VA_POS,&d_drawlist::l_shadowVolPos,0xc);
  gx::GXLoadPosMtxImm(&this->mPosMtx,3);
  gx::GXSetCurrentMtx(3);
  gx::GXCallDisplayList(&d_drawlist::l_shadowVolDL,0x40);
  gx::GXCallDisplayList(&d_drawlist::l_frontZMat,0x20);
  gx::GXCallDisplayList(&d_drawlist::l_shadowVolDL,0x40);
  gx::GXCallDisplayList(&d_drawlist::l_frontNoZSubMat,0x20);
  gx::GXCallDisplayList(&d_drawlist::l_shadowVolDL,0x40);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX3x4,GX_TG_POS,GX_TEXMTX0,false,GX_PTIDENTITY);
  gx::GXCallDisplayList(&d_drawlist::l_mirrorProjMat,0x40);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXLoadTexObj(&this->mTexObj,0);
  uVar1 = gx::GXGetTexObjHeight(&this->mTexObj);
  uVar2 = gx::GXGetTexObjWidth(&this->mTexObj);
  gx::GXSetTexCoordScaleManually(0,1,uVar2,uVar1);
  gx::GXLoadTexMtxImm(&this->mTexMtx,GX_TEXMTX0,0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetCurrentMtx(0);
  dDlst_shadowPoly_c::draw(&(this->mShadowPoly).parent);
  gx::GXSetTexCoordScaleManually(0,0,0,0);
  gx::GXCallDisplayList(&d_drawlist::l_clearMat,0x40);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
  gx::GXSetCurrentMtx(3);
  gx::GXCallDisplayList(&d_drawlist::l_shadowVolDL,0x40);
  gx::GXSetColorUpdate(true);
  gx::GXSetAlphaUpdate(0);
  _sOldVcdVatCmd = 0;
  return;
}


/* __thiscall dDlst_mirrorPacket::init(ResTIMG *) */

int __thiscall dDlst_mirrorPacket::init(dDlst_mirrorPacket *this,ResTIMG *ctx)

{
  int iVar1;
  
  if (ctx == (ResTIMG *)0x0) {
    ctx = (ResTIMG *)
          dRes_control_c::getRes
                    ("Always",0x7f,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  }
  iVar1 = m_Do_lib::mDoLib_setResTimgObj(ctx,&this->mTexObj,0,(GXTlutObj *)0x0);
  return iVar1;
}


namespace d_drawlist {

/* __stdcall mirrorPolygonCheck(cXyz *,
                                cXyz *,
                                float,
                                dDlst_shadowPoly_c *) */

void mirrorPolygonCheck(double param_1,cXyz *param_2,cXyz *param_3,undefined4 param_4)

{
  float fVar1;
  cXyz local_78;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  undefined local_48 [12];
  bool local_3c;
  cBgS_Chk__vtbl *local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  cM3dGAab__vtbl *local_1c;
  code *local_18;
  cXyz *local_14;
  float *local_10;
  undefined4 local_c;
  
  local_48._0_4_ = (cBgS_PolyPassChk *)0x0;
  local_48._4_4_ = (cBgS_GrpPassChk *)0x0;
  local_3c = true;
  local_1c = &::cM3dGAab::__vt;
  local_38 = (cBgS_Chk__vtbl *)&::ShdwDrawPoly_c::__vt;
  fVar1 = param_2->x;
  local_54 = param_3->x;
  local_60 = fVar1;
  if (fVar1 < local_54) {
    local_60 = local_54;
    local_54 = fVar1;
  }
  local_54 = (float)((double)local_54 - param_1);
  local_60 = (float)((double)local_60 + param_1);
  fVar1 = param_2->y;
  local_50 = param_3->y;
  local_5c = fVar1;
  if (fVar1 < local_50) {
    local_5c = local_50;
    local_50 = fVar1;
  }
  local_50 = (float)((double)local_50 - param_1);
  local_5c = (float)((double)local_5c + param_1);
  fVar1 = param_2->z;
  local_4c = param_3->z;
  local_58 = fVar1;
  if (fVar1 < local_4c) {
    local_58 = local_4c;
    local_4c = fVar1;
  }
  local_4c = (float)((double)local_4c - param_1);
  local_58 = (float)((double)local_58 + param_1);
  local_18 = psdRealCallBack;
  local_34 = local_54;
  local_30 = local_50;
  local_2c = local_4c;
  local_28 = local_60;
  local_24 = local_5c;
  local_20 = local_58;
  local_14 = param_2;
  ::cXyz::operator__(&local_78,param_3,param_2);
  local_6c = local_78.x;
  local_68 = local_78.y;
  local_64 = local_78.z;
  local_10 = &local_6c;
  local_c = param_4;
  cBgS::ShdwDraw((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,(cBgS_ShdwDraw *)local_48);
  local_38 = (cBgS_Chk__vtbl *)&::cBgS_ShdwDraw::__vt;
  if ((undefined *)register0x00000004 != (undefined *)0x34) {
    local_1c = &::cM3dGAab::__vt;
  }
  cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_48);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800859bc) */
/* __thiscall dDlst_mirrorPacket::update(float *[][][][],
                                         unsigned char,
                                         float) */

void __thiscall
dDlst_mirrorPacket::update(dDlst_mirrorPacket *this,MTX34 *param_1,uchar param_2,float param_3)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  double dVar3;
  cXyz cStack104;
  cXyz cStack92;
  MTX34 MStack80;
  undefined auStack8 [8];
  
  dVar2 = (double)param_3;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  (this->mShadowPoly).parent.mCount = 0;
  dVar3 = dVar2;
  if (d_drawlist::init_5972 == '\0') {
    d_drawlist::l_p1Offset_5970.x = d_drawlist::0_0;
    d_drawlist::l_p1Offset_5970.y = d_drawlist::0_0;
    d_drawlist::l_p1Offset_5970.z = d_drawlist::0_0;
    dVar2 = (double)Runtime.PPCEABI.H::__register_global_object
                              (dVar2,&d_drawlist::l_p1Offset_5970,::cXyz::_cXyz,&d_drawlist::_5971);
    d_drawlist::init_5972 = '\x01';
  }
  if (d_drawlist::init_5976 == '\0') {
    d_drawlist::l_p2Offset_5974.x = d_drawlist::0_0;
    d_drawlist::l_p2Offset_5974.y = d_drawlist::0_0;
    d_drawlist::l_p2Offset_5974.z = d_drawlist::10000_0;
    Runtime.PPCEABI.H::__register_global_object
              (dVar2,&d_drawlist::l_p2Offset_5974,::cXyz::_cXyz,&d_drawlist::_5975);
    d_drawlist::init_5976 = '\x01';
  }
  mtx::PSMTXMultVec(param_1,&d_drawlist::l_p1Offset_5970,&cStack92);
  mtx::PSMTXMultVec(param_1,&d_drawlist::l_p2Offset_5974,&cStack104);
  d_drawlist::mirrorPolygonCheck(dVar3,&cStack92,&cStack104,&this->mShadowPoly);
  m_Do_mtx::mDoMtx_lookAt(&MStack80,&cStack92,&cStack104,0);
  mtx::C_MTXLightOrtho
            (d_drawlist::24_0,d_drawlist::_24_0,d_drawlist::_24_0,d_drawlist::24_0,d_drawlist::0_5,
             d_drawlist::_0_5,d_drawlist::0_5,d_drawlist::0_5,&this->mTexMtx);
  mtx::PSMTXConcat(&this->mTexMtx,&MStack80,&this->mTexMtx);
  mtx::C_MTXOrtho(d_drawlist::24_0,d_drawlist::_24_0,d_drawlist::_24_0,d_drawlist::24_0,
                  d_drawlist::1_0,d_drawlist::10000_0,(MTX44 *)&this->mPosMtx);
  mtx::PSMTXInverse(&MStack80,&mDoMtx_stack_c::now);
  mtx::PSMTXInverse(&this->mPosMtx,&MStack80);
  MStack80.m[2][3] = d_drawlist::0_0;
  mtx::PSMTXConcat(&mDoMtx_stack_c::now,&MStack80,&mDoMtx_stack_c::now);
  mDoMtx_stack_c::scaleM(d_drawlist::1_0,d_drawlist::1_0,d_drawlist::_0_003);
  mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&mDoMtx_stack_c::now,&this->mPosMtx);
  this->mAlpha = param_2;
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dDlst_alphaVolPacket::draw(void) */

void __thiscall dDlst_alphaVolPacket::draw(dDlst_alphaVolPacket *this)

{
  _GXColor local_18 [4];
  
  gx::GXSetChanCtrl(GX_ALPHA0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
  local_18[0] = d_com_inf_game::g_whiteColor;
  gx::GXSetTevColor(GX_TEVREG0,local_18);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
  gx::GXSetArray(GX_VA_POS,&d_drawlist::l_simpleShadowPos,0xc);
  gx::GXLoadPosMtxImm((MTX34 *)(this + 0x10),0);
  gx::GXSetCurrentMtx(0);
  gx::GXCallDisplayList(&d_drawlist::l_frontMat,0x40);
  gx::GXCallDisplayList(&d_drawlist::l_shadowVolumeDL,0x40);
  gx::GXCallDisplayList(&d_drawlist::l_backSubMat,0x20);
  gx::GXCallDisplayList(&d_drawlist::l_shadowVolumeDL,0x40);
  gx::GXSetColorUpdate(true);
  gx::GXSetAlphaUpdate(0);
  _sOldVcdVatCmd = 0;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dDlst_alphaInvVolPacket::draw(void) */

void __thiscall dDlst_alphaInvVolPacket::draw(dDlst_alphaInvVolPacket *this)

{
  _GXColor local_18 [4];
  
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
  gx::GXSetArray(GX_VA_POS,&d_drawlist::l_simpleShadowPos,0xc);
  gx::GXLoadPosMtxImm((MTX34 *)(this + 0x10),0);
  gx::GXSetCurrentMtx(0);
  local_18[0] = d_com_inf_game::g_whiteColor;
  gx::GXSetTevColor(GX_TEVREG0,local_18);
  gx::GXCallDisplayList(&d_drawlist::l_backMat_6018,0x60);
  gx::GXCallDisplayList(&d_drawlist::l_shadowVolumeDL,0x40);
  gx::GXSetColorUpdate(true);
  gx::GXSetAlphaUpdate(0);
  _sOldVcdVatCmd = 0;
  return;
}


/* __thiscall dDlst_peekZ_c::newData(short,
                                     short,
                                     unsigned long *) */

undefined4 __thiscall
dDlst_peekZ_c::newData(dDlst_peekZ_c *this,short param_1,short param_2,ulong *param_3)

{
  dDlst_peekZ_c__Entry *pdVar1;
  
  if (0x3f < (byte)this->mCount) {
    return 0;
  }
  pdVar1 = this->mEntries + (byte)this->mCount;
  pdVar1->mX = param_1;
  pdVar1->mY = param_2;
  pdVar1->mpDest = param_3;
  this->mCount = this->mCount + '\x01';
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDlst_peekZ_c::peekData(void) */

void __thiscall dDlst_peekZ_c::peekData(dDlst_peekZ_c *this)

{
  int iVar1;
  dDlst_peekZ_c__Entry *pdVar2;
  
  pdVar2 = this->mEntries;
  for (iVar1 = 0; iVar1 < (int)(uint)(byte)this->mCount; iVar1 = iVar1 + 1) {
    gx::GXPeekZ(pdVar2->mX,pdVar2->mY,pdVar2->mpDest);
    pdVar2 = pdVar2 + 1;
  }
  this->mCount = '\0';
  return;
}


/* __thiscall dDlst_list_c::dDlst_list_c(void) */

void __thiscall dDlst_list_c::dDlst_list_c(dDlst_list_c *this)

{
  Runtime.PPCEABI.H::__construct_array
            ((this->mShadowControl).mShadowSimple,dDlst_shadowSimple_c::dDlst_shadowSimple_c,
             dDlst_shadowSimple_c::_dDlst_shadowSimple_c,0x68,0x80);
  Runtime.PPCEABI.H::__construct_array
            ((this->mShadowControl).mShadowReal,dDlst_shadowReal_c::dDlst_shadowReal_c,
             dDlst_shadowReal_c::_dDlst_shadowReal_c,0x2544,8);
  (this->mShadowControl).field_0x0 = 0;
  Runtime.PPCEABI.H::__construct_array
            (this->m3DLineMatSortPacket,mDoExt_3DlineMatSortPacket::mDoExt_3DlineMatSortPacket,
             mDoExt_3DlineMatSortPacket::_mDoExt_3DlineMatSortPacket,0x14,2);
  (this->mPeekZ).mCount = '\0';
  *(int *)&this->field_0x50 = &this->field_0x4c;
  *(dDlst_base_c ****)&this->field_0x98 = &this->field_0x94;
  this->mp2DOpaEnd = &this->mp2DOpa;
  this->field_0x228 = &this->field_0x224;
  this->mpBufSkyOpa = (J3DDrawBuffer *)0x0;
  this->mpBufSkyXlu = (J3DDrawBuffer *)0x0;
  this->mpLinkBuf = (J3DDrawBuffer *)0x0;
  this->field_0xc = (J3DDrawBuffer *)0x0;
  this->field_0x10 = (J3DDrawBuffer *)0x0;
  this->mpBufWorldOpa = (J3DDrawBuffer *)0x0;
  this->mpBufWorldXlu = (J3DDrawBuffer *)0x0;
  this->mpBufInvisibleModelOpa = (J3DDrawBuffer *)0x0;
  this->mpBufInvisibleModelXlu = (J3DDrawBuffer *)0x0;
  this->mpWetherFxBuffer = (J3DDrawBuffer *)0x0;
  this->mpBufInvisibleModelMaskOffOpa = (J3DDrawBuffer *)0x0;
  this->mpBufInvisibleModelMaskOffXlu = (J3DDrawBuffer *)0x0;
  this->field_0x30 = (J3DDrawBuffer *)0x0;
  this->field_0x34 = (J3DDrawBuffer *)0x0;
  this->field_0x38 = (J3DDrawBuffer *)0x0;
  this->mpAlphaModel0 = (dDlst_alphaModel_c *)0x0;
  this->mpAlphaModel2 = (dDlst_alphaModel_c *)0x0;
  return;
}


/* __thiscall mDoExt_3DlineMatSortPacket::mDoExt_3DlineMatSortPacket(void) */

void __thiscall
mDoExt_3DlineMatSortPacket::mDoExt_3DlineMatSortPacket(mDoExt_3DlineMatSortPacket *this)

{
  this->field_0x0 = &J3DPacket::__vt;
  this->field_0x4 = 0;
  this->field_0x8 = 0;
  this->field_0xc = 0;
  this->field_0x0 = &__vt;
  this->mp3DlineMat = (mDoExt_3DlineMat_c *)0x0;
  return;
}


/* __thiscall dDlst_shadowReal_c::dDlst_shadowReal_c(void) */

void __thiscall dDlst_shadowReal_c::dDlst_shadowReal_c(dDlst_shadowReal_c *this)

{
  (this->mShadowPoly).vtbl = (undefined *)&dDlst_shadowPoly_c::__vt;
  (this->mShadowPoly).mCount = 0;
  (this->mShadowPoly).vtbl = (undefined *)&dDlst_shadowRealPoly_c::__vt;
  Runtime.PPCEABI.H::__construct_array
            (this->mShadowTri,dDlst_shadowTri_c::dDlst_shadowTri_c,
             dDlst_shadowTri_c::_dDlst_shadowTri_c,0x24,0x100);
  this->mState = 0;
  return;
}


/* __thiscall dDlst_shadowRealPoly_c::~dDlst_shadowRealPoly_c(void) */

void __thiscall dDlst_shadowRealPoly_c::_dDlst_shadowRealPoly_c(dDlst_shadowRealPoly_c *this)

{
  short in_r4;
  
  if (this != (dDlst_shadowRealPoly_c *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    Runtime.PPCEABI.H::__destroy_arr(this->mTri,dDlst_shadowTri_c::_dDlst_shadowTri_c,0x24,0x100);
    if (this != (dDlst_shadowRealPoly_c *)0x0) {
      (this->parent).vtbl = (undefined *)&dDlst_shadowPoly_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_shadowTri_c::dDlst_shadowTri_c(void) */

void __thiscall dDlst_shadowTri_c::dDlst_shadowTri_c(dDlst_shadowTri_c *this)

{
  Runtime.PPCEABI.H::__construct_array(this,::cXyz::cXyz,::cXyz::_cXyz,0xc,3);
  return;
}


/* __thiscall dDlst_shadowPoly_c::~dDlst_shadowPoly_c(void) */

void __thiscall dDlst_shadowPoly_c::_dDlst_shadowPoly_c(dDlst_shadowPoly_c *this)

{
  short in_r4;
  
  if ((this != (dDlst_shadowPoly_c *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dDlst_shadowSimple_c::~dDlst_shadowSimple_c(void) */

void __thiscall dDlst_shadowSimple_c::_dDlst_shadowSimple_c(dDlst_shadowSimple_c *this)

{
  short in_r4;
  
  if ((this != (dDlst_shadowSimple_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dDlst_shadowSimple_c::dDlst_shadowSimple_c(void) */

void __thiscall dDlst_shadowSimple_c::dDlst_shadowSimple_c(dDlst_shadowSimple_c *this)

{
  return;
}


/* __thiscall dDlst_list_c::init(void) */

int __thiscall dDlst_list_c::init(dDlst_list_c *this,EVP_PKEY_CTX *ctx)

{
  J3DDrawBuffer *pJVar1;
  int iVar2;
  dDlst_alphaModel_c *pdVar3;
  
  pJVar1 = d_drawlist::J3DDrawBuffer__create__FUl(0x20);
  this->mpBufSkyOpa = pJVar1;
  pJVar1 = d_drawlist::J3DDrawBuffer__create__FUl(0x20);
  this->mpBufSkyXlu = pJVar1;
  pJVar1 = d_drawlist::J3DDrawBuffer__create__FUl(1);
  this->mpLinkBuf = pJVar1;
  pJVar1 = d_drawlist::J3DDrawBuffer__create__FUl(0x20);
  this->field_0xc = pJVar1;
  pJVar1 = d_drawlist::J3DDrawBuffer__create__FUl(0x20);
  this->field_0x10 = pJVar1;
  pJVar1 = d_drawlist::J3DDrawBuffer__create__FUl(0x80);
  this->mpBufWorldOpa = pJVar1;
  pJVar1 = d_drawlist::J3DDrawBuffer__create__FUl(0x80);
  this->mpBufWorldXlu = pJVar1;
  pJVar1 = d_drawlist::J3DDrawBuffer__create__FUl(0x100);
  this->mpBufInvisibleModelOpa = pJVar1;
  pJVar1 = d_drawlist::J3DDrawBuffer__create__FUl(0x100);
  this->mpBufInvisibleModelXlu = pJVar1;
  pJVar1 = d_drawlist::J3DDrawBuffer__create__FUl(0x20);
  this->mpWetherFxBuffer = pJVar1;
  pJVar1 = d_drawlist::J3DDrawBuffer__create__FUl(0x20);
  this->mpBufInvisibleModelMaskOffOpa = pJVar1;
  pJVar1 = d_drawlist::J3DDrawBuffer__create__FUl(0x100);
  this->mpBufInvisibleModelMaskOffXlu = pJVar1;
  pJVar1 = d_drawlist::J3DDrawBuffer__create__FUl(0x20);
  this->field_0x30 = pJVar1;
  pJVar1 = d_drawlist::J3DDrawBuffer__create__FUl(0x20);
  this->field_0x34 = pJVar1;
  pJVar1 = d_drawlist::J3DDrawBuffer__create__FUl(1);
  this->field_0x38 = pJVar1;
  if ((((((((this->mpBufSkyOpa == (J3DDrawBuffer *)0x0) ||
           (this->mpBufSkyXlu == (J3DDrawBuffer *)0x0)) || (this->mpLinkBuf == (J3DDrawBuffer *)0x0)
          ) || ((this->field_0xc == (J3DDrawBuffer *)0x0 ||
                (this->field_0x10 == (J3DDrawBuffer *)0x0)))) ||
        ((this->mpBufWorldOpa == (J3DDrawBuffer *)0x0 ||
         ((this->mpBufWorldXlu == (J3DDrawBuffer *)0x0 ||
          (this->mpBufInvisibleModelOpa == (J3DDrawBuffer *)0x0)))))) ||
       (this->mpBufInvisibleModelXlu == (J3DDrawBuffer *)0x0)) ||
      (((this->mpWetherFxBuffer == (J3DDrawBuffer *)0x0 ||
        (this->mpBufInvisibleModelMaskOffOpa == (J3DDrawBuffer *)0x0)) ||
       (this->mpBufInvisibleModelMaskOffXlu == (J3DDrawBuffer *)0x0)))) ||
     (((this->field_0x30 == (J3DDrawBuffer *)0x0 || (this->field_0x34 == (J3DDrawBuffer *)0x0)) ||
      (this->field_0x38 == (J3DDrawBuffer *)0x0)))) {
    iVar2 = 0;
  }
  else {
    this->mpBufSkyOpa->mSortType = 5;
    this->mpBufSkyXlu->mSortType = 5;
    this->mpLinkBuf->mSortType = 5;
    this->field_0xc->mSortType = 5;
    this->field_0x10->mSortType = 5;
    this->mpBufWorldXlu->mSortType = 5;
    this->mpBufInvisibleModelXlu->mSortType = 2;
    this->mpWetherFxBuffer->mSortType = 2;
    this->mpBufInvisibleModelMaskOffXlu->mSortType = 2;
    this->field_0x34->mSortType = 2;
    this->field_0x38->mSortType = 5;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = this->mpBufInvisibleModelOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = this->mpBufInvisibleModelXlu;
    *(int *)&this->field_0x4c = &this->field_0x3c;
    this->field_0x94 = (dDlst_base_c **)&this->field_0x54;
    this->mp2DOpa = (dDlst_base_c **)this->mp2DArr;
    this->field_0x224 = (dDlst_base_c **)&this->field_0x1a4;
    dDlst_shadowControl_c::init(&this->mShadowControl);
    pdVar3 = dDlst_alphaModel_c::create(0x40);
    this->mpAlphaModel0 = pdVar3;
    pdVar3 = dDlst_alphaModel_c::create(8);
    this->mpAlphaModel2 = pdVar3;
    pdVar3 = dDlst_alphaModel_c::create(0x10);
    this->mpAlphaModel1 = pdVar3;
    if (((this->mpAlphaModel0 == (dDlst_alphaModel_c *)0x0) ||
        (this->mpAlphaModel2 == (dDlst_alphaModel_c *)0x0)) ||
       (this->mpAlphaModel1 == (dDlst_alphaModel_c *)0x0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
    }
  }
  return iVar2;
}


/* __thiscall dDlst_list_c::~dDlst_list_c(void) */

void __thiscall dDlst_list_c::_dDlst_list_c(dDlst_list_c *this)

{
  short in_r4;
  
  if (this != (dDlst_list_c *)0x0) {
    J3DDrawBuffer::_J3DDrawBuffer(this->mpBufSkyOpa);
    J3DDrawBuffer::_J3DDrawBuffer(this->mpBufSkyXlu);
    J3DDrawBuffer::_J3DDrawBuffer(this->mpLinkBuf);
    J3DDrawBuffer::_J3DDrawBuffer(this->field_0xc);
    J3DDrawBuffer::_J3DDrawBuffer(this->field_0x10);
    J3DDrawBuffer::_J3DDrawBuffer(this->mpBufWorldOpa);
    J3DDrawBuffer::_J3DDrawBuffer(this->mpBufWorldXlu);
    J3DDrawBuffer::_J3DDrawBuffer(this->mpBufInvisibleModelOpa);
    J3DDrawBuffer::_J3DDrawBuffer(this->mpBufInvisibleModelXlu);
    J3DDrawBuffer::_J3DDrawBuffer(this->mpWetherFxBuffer);
    J3DDrawBuffer::_J3DDrawBuffer(this->mpBufInvisibleModelMaskOffOpa);
    J3DDrawBuffer::_J3DDrawBuffer(this->mpBufInvisibleModelMaskOffXlu);
    J3DDrawBuffer::_J3DDrawBuffer(this->field_0x30);
    J3DDrawBuffer::_J3DDrawBuffer(this->field_0x34);
    J3DDrawBuffer::_J3DDrawBuffer(this->field_0x38);
    if ((JKRHeap *)this->mpAlphaModel0 != (JKRHeap *)0x0) {
      JKernel::operator_delete((JKRHeap *)this->mpAlphaModel0);
    }
    if ((JKRHeap *)this->mpAlphaModel2 != (JKRHeap *)0x0) {
      JKernel::operator_delete((JKRHeap *)this->mpAlphaModel2);
    }
    Runtime.PPCEABI.H::__destroy_arr
              (this->m3DLineMatSortPacket,mDoExt_3DlineMatSortPacket::_mDoExt_3DlineMatSortPacket,
               0x14,2);
    if (this != (dDlst_list_c *)0xfffffdb0) {
      Runtime.PPCEABI.H::__destroy_arr
                ((this->mShadowControl).mShadowReal,dDlst_shadowReal_c::_dDlst_shadowReal_c,0x2544,8
                );
      Runtime.PPCEABI.H::__destroy_arr
                ((this->mShadowControl).mShadowSimple,dDlst_shadowSimple_c::_dDlst_shadowSimple_c,
                 0x68,0x80);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_list_c::reset(void) */

void __thiscall dDlst_list_c::reset(dDlst_list_c *this)

{
  int iVar1;
  int iVar2;
  
  J3DDrawBuffer::frameInit(this->mpBufSkyOpa);
  J3DDrawBuffer::frameInit(this->mpBufSkyXlu);
  J3DDrawBuffer::frameInit(this->mpLinkBuf);
  J3DDrawBuffer::frameInit(this->field_0xc);
  J3DDrawBuffer::frameInit(this->field_0x10);
  J3DDrawBuffer::frameInit(this->mpBufWorldOpa);
  J3DDrawBuffer::frameInit(this->mpBufWorldXlu);
  J3DDrawBuffer::frameInit(this->mpBufInvisibleModelOpa);
  J3DDrawBuffer::frameInit(this->mpBufInvisibleModelXlu);
  J3DDrawBuffer::frameInit(this->mpWetherFxBuffer);
  J3DDrawBuffer::frameInit(this->mpBufInvisibleModelMaskOffOpa);
  J3DDrawBuffer::frameInit(this->mpBufInvisibleModelMaskOffXlu);
  J3DDrawBuffer::frameInit(this->field_0x30);
  J3DDrawBuffer::frameInit(this->field_0x34);
  J3DDrawBuffer::frameInit(this->field_0x38);
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = this->mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = this->mpBufInvisibleModelXlu;
  *(int *)&this->field_0x4c = &this->field_0x3c;
  this->field_0x94 = (dDlst_base_c **)&this->field_0x54;
  this->mp2DOpa = (dDlst_base_c **)this->mp2DArr;
  this->field_0x224 = (dDlst_base_c **)&this->field_0x1a4;
  (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel0)->mCount = 0;
  (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel2)->mCount = 0;
  (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel1)->mCount = 0;
  dDlst_shadowControl_c::reset(&this->mShadowControl);
  iVar1 = 0;
  iVar2 = 2;
  do {
    *(undefined4 *)((int)&this->m3DLineMatSortPacket[0].mp3DlineMat + iVar1) = 0;
    iVar1 = iVar1 + 0x14;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall dDlst_list_c::entryZSortXluDrawList(J3DDrawBuffer *,
                                                  J3DPacket *,
                                                  cXyz &) */

void __thiscall
dDlst_list_c::entryZSortXluDrawList
          (dDlst_list_c *this,J3DDrawBuffer *pBuffer,J3DPacket *pPacket,cXyz *pPos)

{
  double dVar1;
  cXyz local_28;
  undefined8 local_18;
  
  local_28.x = pPos->x;
  local_28.y = pPos->y;
  local_28.z = pPos->z;
  dVar1 = J3DGraphBase::J3DCalcZValue(&J3DGraphBase::j3dSys.mCurViewMtx,&local_28);
  dVar1 = -dVar1;
  if (dVar1 <= (double)d_drawlist::_6190) {
    local_18._6_2_ = 0;
  }
  else {
    if ((double)d_drawlist::_6191 <= dVar1) {
      local_18._6_2_ = 0xff;
    }
    else {
      local_18 = (longlong)(int)(dVar1 / (double)d_drawlist::_6192);
      local_18._6_2_ = (short)(int)(dVar1 / (double)d_drawlist::_6192);
    }
  }
  J3DDrawBuffer::entryImm(pBuffer,pPacket,0xff - local_18._6_2_);
  return;
}


/* __thiscall dDlst_list_c::set(dDlst_base_c * & *,
                                dDlst_base_c * & *,
                                dDlst_base_c *) */

void __thiscall
dDlst_list_c::set(dDlst_list_c *this,dDlst_base_c ***pLst,dDlst_base_c ****pEnd,
                 dDlst_base_c *pPacket)

{
  if (*pEnd <= *pLst) {
    return;
  }
  **pLst = pPacket;
  *pLst = *pLst + 1;
  return;
}


/* __thiscall dDlst_list_c::draw(dDlst_base_c * *,
                                 dDlst_base_c * *) */

void __thiscall dDlst_list_c::draw(dDlst_list_c *this,dDlst_base_c **pBegin,dDlst_base_c **pEnd)

{
  for (; pBegin < pEnd; pBegin = pBegin + 1) {
    (**(code **)((*pBegin)->vtbl + 0xc))();
  }
  return;
}


namespace dDlst_list_c {

/* __thiscall wipeIn(float,
                                   _GXColor &) */

void wipeIn(float param_1,_GXColor *param_2)

{
  ResTIMG *pRVar1;
  ulong uVar2;
  
  mWipe = 1;
  mWipeColor.r = param_2->r;
  mWipeColor.g = param_2->g;
  mWipeColor.b = param_2->b;
  mWipeColor.a = param_2->a;
  mWipeRate = d_drawlist::1_0;
  if (d_drawlist::0_0 <= param_1) {
    mWipeRate = d_drawlist::0_0;
  }
  mWipeSpeed = param_1;
  pRVar1 = (ResTIMG *)
           JKRArchive::getGlbResource
                     (0x54494d47,"wipe_00.bti",
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMenuArchive);
  if (pRVar1 == (ResTIMG *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_drawlist.cpp",0x1637,"texture != 0");
    m_Do_printf::OSPanic("d_drawlist.cpp",0x1637,&DAT_80352c65);
  }
  dDlst_2DT2_c::init(&mWipeDlst,pRVar1,d_drawlist::_6224,d_drawlist::_6225,d_drawlist::_6226,
                     d_drawlist::_6227,0,1,1,d_drawlist::_4939,d_drawlist::_6228);
  return;
}


/* __thiscall wipeIn(float) */

void wipeIn(float param_1)

{
  wipeIn(-param_1,&d_com_inf_game::g_blackColor);
  return;
}

}

/* __thiscall dDlst_list_c::calcWipe(void) */

void __thiscall dDlst_list_c::calcWipe(dDlst_list_c *this)

{
  if (mWipe != 0) {
    mWipeRate = mWipeRate + mWipeSpeed;
    if (d_drawlist::0_0 <= mWipeRate) {
      if (d_drawlist::1_0 < mWipeRate) {
        mWipeRate = d_drawlist::1_0;
        mWipe = 0;
      }
    }
    else {
      mWipeRate = d_drawlist::0_0;
    }
    DAT_803e232c = d_drawlist::_4939 * mWipeRate;
    DAT_803e2330 = d_drawlist::_6255 * DAT_803e232c;
    set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x224,
        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x228,(dDlst_base_c *)&mWipeDlst);
  }
  return;
}


namespace d_drawlist {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8008694c) */
/* __stdcall dDlst_texSpecmapST(cXyz const *,
                                dKy_tevstr_c const *,
                                J3DModelData *,
                                float) */

void dDlst_texSpecmapST
               (cXyz *param_1,dKy_tevstr_c *param_2,J3DModelData *param_3,float param_4)

{
  ushort uVar1;
  float fVar2;
  camera_class *pCamera;
  J3DTexGenBlockPatched *pJVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  J3DMaterial *pJVar7;
  undefined4 uVar8;
  undefined8 in_f31;
  double dVar9;
  cXyz local_b8;
  cXyz cStack172;
  cXyz cStack160;
  cXyz local_94;
  MTX34 local_88;
  MTX34 MStack88;
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar9 = (double)(1_0 / param_4);
  pCamera = d_camera::dCam_getCamera();
  ::cXyz::operator__(&local_b8,param_1,&pCamera->mEyePos);
  local_94.x = local_b8.x;
  local_94.y = local_b8.y;
  local_94.z = local_b8.z;
  d_kankyo_rain::dKyr_get_vectle_calc((cXyz *)&param_2->mLightPosWorld,param_1,&cStack172);
  mtx::C_VECHalfAngle(&local_94,&cStack172,&cStack160);
  mtx::C_MTXLookAt(&MStack88,&::cXyz::Zero,&::cXyz::BaseY,&cStack160);
  mtx::PSMTXScale(dVar9,dVar9,(double)1_0,&local_88);
  mtx::PSMTXConcat(&local_88,(MTX34 *)&mtx_adj_6259,&local_88);
  mtx::PSMTXConcat(&local_88,&MStack88,&local_88);
  local_88.m[0][3] = 0_0;
  local_88.m[1][3] = 0_0;
  local_88.m[2][3] = 0_0;
  uVar1 = (param_3->mMaterialTable).mMaterialCount;
  for (uVar6 = 0; (int)uVar6 < (int)(uint)uVar1; uVar6 = uVar6 + 1) {
    pJVar7 = (param_3->mMaterialTable).mpMaterials[uVar6 & 0xffff];
    iVar5 = 0;
    do {
      pJVar3 = pJVar7->mpTexGenBlock;
      iVar4 = (*(code *)pJVar3->vtbl->getTexMtx)(pJVar3,iVar5);
      if ((iVar4 != 0) && (*(char *)(iVar4 + 1) == '\n')) {
        *(float *)(iVar4 + 0x24) = local_88.m[0][0];
        *(float *)(iVar4 + 0x28) = local_88.m[0][1];
        *(float *)(iVar4 + 0x2c) = local_88.m[0][2];
        *(float *)(iVar4 + 0x30) = local_88.m[0][3];
        *(float *)(iVar4 + 0x34) = local_88.m[1][0];
        *(float *)(iVar4 + 0x38) = local_88.m[1][1];
        *(float *)(iVar4 + 0x3c) = local_88.m[1][2];
        *(float *)(iVar4 + 0x40) = local_88.m[1][3];
        *(float *)(iVar4 + 0x44) = local_88.m[2][0];
        *(float *)(iVar4 + 0x48) = local_88.m[2][1];
        *(float *)(iVar4 + 0x4c) = local_88.m[2][2];
        *(float *)(iVar4 + 0x50) = local_88.m[2][3];
        fVar2 = 0_0;
        *(float *)(iVar4 + 0x5c) = 0_0;
        *(float *)(iVar4 + 0x58) = fVar2;
        *(float *)(iVar4 + 0x54) = fVar2;
        *(float *)(iVar4 + 0x60) = 1_0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < 8);
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return;
}

}

/* __thiscall dDlst_alphaInvVolPacket::~dDlst_alphaInvVolPacket(void) */

void __thiscall dDlst_alphaInvVolPacket::_dDlst_alphaInvVolPacket(dDlst_alphaInvVolPacket *this)

{
  short in_r4;
  
  if (this != (dDlst_alphaInvVolPacket *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_alphaInvVolPacket *)0x0) {
      *(undefined ***)this = &J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_alphaVolPacket::~dDlst_alphaVolPacket(void) */

void __thiscall dDlst_alphaVolPacket::_dDlst_alphaVolPacket(dDlst_alphaVolPacket *this)

{
  short in_r4;
  
  if (this != (dDlst_alphaVolPacket *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_alphaVolPacket *)0x0) {
      *(undefined ***)this = &J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_mirrorPacket::~dDlst_mirrorPacket(void) */

void __thiscall dDlst_mirrorPacket::_dDlst_mirrorPacket(dDlst_mirrorPacket *this)

{
  short in_r4;
  
  if (this != (dDlst_mirrorPacket *)0x0) {
    (this->parent).vtbl = &__vt;
    if (this != (dDlst_mirrorPacket *)0xffffff50) {
      (this->mShadowPoly).parent.vtbl = (undefined *)&dDlst_shadowRealPoly_c::__vt;
      Runtime.PPCEABI.H::__destroy_arr
                ((this->mShadowPoly).mTri,dDlst_shadowTri_c::_dDlst_shadowTri_c,0x24,0x100);
      if (this != (dDlst_mirrorPacket *)0xffffff50) {
        (this->mShadowPoly).parent.vtbl = (undefined *)&dDlst_shadowPoly_c::__vt;
      }
    }
    if (this != (dDlst_mirrorPacket *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_shadowRealPoly_c::getTri(void) */

dDlst_shadowTri_c * __thiscall dDlst_shadowRealPoly_c::getTri(dDlst_shadowRealPoly_c *this)

{
  return this->mTri;
}


/* __thiscall dDlst_shadowRealPoly_c::getTriMax(void) */

undefined4 __thiscall dDlst_shadowRealPoly_c::getTriMax(dDlst_shadowRealPoly_c *this)

{
  return 0x100;
}


/* __thiscall dDlst_alphaModelPacket::~dDlst_alphaModelPacket(void) */

void __thiscall dDlst_alphaModelPacket::_dDlst_alphaModelPacket(dDlst_alphaModelPacket *this)

{
  short in_r4;
  
  if (this != (dDlst_alphaModelPacket *)0x0) {
    (this->parent).vtbl = &__vt;
    if (this != (dDlst_alphaModelPacket *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_effectLine_c::~dDlst_effectLine_c(void) */

void __thiscall dDlst_effectLine_c::_dDlst_effectLine_c(dDlst_effectLine_c *this)

{
  short in_r4;
  
  if (this != (dDlst_effectLine_c *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (dDlst_effectLine_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_2D_c::~dDlst_2D_c(void) */

void __thiscall dDlst_2D_c::_dDlst_2D_c(dDlst_2D_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2D_c *)0x0) {
    this->field_0x0 = &__vt;
    J2DPicture::_J2DPicture((J2DPicture *)&this->field_0x4,-1);
    if (this != (dDlst_2D_c *)0x0) {
      this->field_0x0 = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_2DMt_c::~dDlst_2DMt_c(void) */

void __thiscall dDlst_2DMt_c::_dDlst_2DMt_c(dDlst_2DMt_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DMt_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2DMt_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_2Dm_c::~dDlst_2Dm_c(void) */

void __thiscall dDlst_2Dm_c::_dDlst_2Dm_c(dDlst_2Dm_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2Dm_c *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    if (this != (dDlst_2Dm_c *)0x0) {
      (this->parent).vtbl = (undefined *)&dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_2DM_c::~dDlst_2DM_c(void) */

void __thiscall dDlst_2DM_c::_dDlst_2DM_c(dDlst_2DM_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DM_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2DM_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_2DT2_c::~dDlst_2DT2_c(void) */

void __thiscall dDlst_2DT2_c::_dDlst_2DT2_c(dDlst_2DT2_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DT2_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2DT2_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_2DT_c::~dDlst_2DT_c(void) */

void __thiscall dDlst_2DT_c::_dDlst_2DT_c(dDlst_2DT_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DT_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2DT_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_2DPoint_c::~dDlst_2DPoint_c(void) */

void __thiscall dDlst_2DPoint_c::_dDlst_2DPoint_c(dDlst_2DPoint_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DPoint_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2DPoint_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_2DTri_c::~dDlst_2DTri_c(void) */

void __thiscall dDlst_2DTri_c::_dDlst_2DTri_c(dDlst_2DTri_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DTri_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2DTri_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_drawlist {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_d_drawlist_cpp(void)

{
  _mWipeDlst = &::dDlst_2DT2_c::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::dDlst_list_c::mWipeDlst,::dDlst_2DT2_c::_dDlst_2DT2_c,&_6040);
  return;
}

