#include <m_Do_graphic.h>
#include <JFramework/JFWDisplay.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTFader.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <m_Do_graphic.h>
#include <gx/GXTexture.h>
#include <SComponent/c_lib.h>
#include <J2DGraph/J2DPrint.h>
#include <vi/vi.h>
#include <JKernel/JKRSolidHeap.h>
#include <mtx/mtx.h>
#include <gx/GXLight.h>
#include <gx/GXAttr.h>
#include <gx/GXTev.h>
#include <gx/GXPixel.h>
#include <gx/GXGeometry.h>
#include <gx/GXBump.h>
#include <mtx/mtx44.h>
#include <gx/GXTransform.h>
#include <d_particle.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <d_drawlist.h>
#include <JUtility/JUTVideo.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_stage.h>
#include <gx/GXFrameBuf.h>
#include <gx/GXMisc.h>
#include <os/OSThread.h>
#include <m_Do_ext.h>
#include <os/OSCache.h>
#include <os/OSAlarm.h>
#include <os/OSInterrupt.h>
#include <J3DGraphBase/J3DSys.h>
#include <J2DGraph/J2DOrthoGraph.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <base/PPCArch.h>
#include <d_kankyo.h>
#include <J3DGraphBase/J3DDrawBuffer.h>
#include <d_meter.h>
#include <m_Do_mtx.h>
#include <J2DOrthoGraph.h>
#include <mDoGph_gInf_c.h>
#include <dStage_roomDt_c.h>

GXTexObj mDoGph_gInf_c;
GXTexObj mDoGph_gInf_c;
struct MTX34 mDoGph_gInf_c;

namespace m_Do_graphic {
undefined mCaptureThread;
undefined mCaptureTimeOutAlarm;
}
struct JUTFader * mDoGph_gInf_c;
struct ResTIMG * mDoGph_gInf_c;
struct ResTIMG * mDoGph_gInf_c;
void * mDoGph_gInf_c;
undefined1 mDoGph_gInf_c;
undefined1 mDoGph_gInf_c;
undefined1 mDoGph_gInf_c;
byte mDoGph_gInf_c;
float mDoGph_gInf_c;
float mDoGph_gInf_c;
byte mDoGph_gInf_c;
byte mDoGph_gInf_c;
short mDoGph_gInf_c;
short mDoGph_gInf_c;

namespace m_Do_graphic {
undefined g_mDoGph_graphicInfo;
short mCaptureStep;
undefined1 mCaptureCansel;
undefined1 mCaptureEnableGXSetCopyFilter;
undefined4 mCaptureThreadStackHead;
undefined4 mCaptureCaptureBuffer;
undefined4 mCaptureTextureBuffer;
undefined4 mCaptureTextureSize;
undefined4 mCaptureCaptureSize;
undefined4 mCaptureOldCB;
undefined mCaptureThreadQueue;
undefined4 mCaptureTimeOutTicks;
}

/* __thiscall mDoGph_gInf_c::create(void) */

void __thiscall mDoGph_gInf_c::create(mDoGph_gInf_c *this)

{
  JUTDbPrint *this_00;
  JUTFader *this_01;
  ulong uVar1;
  int iVar2;
  bool in_r6;
  undefined4 local_14 [4];
  
  JFWDisplay::createManager((JFWDisplay *)JKRHeap::sCurrentHeap,(JKRHeap *)&DAT_00000002,1,in_r6);
  *(undefined4 *)&JFWDisplay::sManager->field_0x1c = 1;
  this_01 = (JUTFader *)JKernel::operator_new(0x28);
  if (this_01 != (JUTFader *)0x0) {
    local_14[0] = 0;
    JUTFader::JUTFader(this_01,0,0,(uint)(ushort)JUTVideo::sManager->mpRenderMode->field_0x4,
                       (uint)(ushort)JUTVideo::sManager->mpRenderMode->field_0x6,(TColor)local_14);
  }
  if (this_01 == (JUTFader *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"m_Do_graphic.cpp",0x1a0,"faderPtr != 0");
    m_Do_printf::OSPanic("m_Do_graphic.cpp",0x1a0,"Halt");
  }
  JFWDisplay::sManager->mpFader = this_01;
  mFader = this_01;
  JFWDisplay::sManager->mpFader = this_01;
  JUTProcBar::sManager->mbDrawHeapBar = 0;
  JUTProcBar::sManager->mbDrawProcessBar = 0;
  this_00 = JUTDbPrint::sDebugPrint;
  JUTDbPrint::sDebugPrint[0xc] = (JUTDbPrint)0x0;
  createHeap((mDoGph_gInf_c *)this_00);
  iVar2 = gx::GXGetTexBufferSize(0x140,0xf0,6,0,0);
  mFrameBufferTimg = (ResTIMG *)JKRHeap::alloc(iVar2 + 0x20U,0x20,(JKRHeap *)0x0);
  mFrameBufferTex = mFrameBufferTimg + 1;
  SComponent::cLib_memSet(mFrameBufferTimg,0,iVar2 + 0x20U);
  mFrameBufferTimg->mTexFmt = GX_TF_RGBA8;
  mFrameBufferTimg->mTranslucency = 0;
  mFrameBufferTimg->mWidth = 0x140;
  mFrameBufferTimg->mHeight = 0xf0;
  mFrameBufferTimg->mMinFilter = GX_LINEAR;
  mFrameBufferTimg->mMagFilter = GX_LINEAR;
  mFrameBufferTimg->mTexDataOffs = 0x20;
  uVar1 = gx::GXGetTexBufferSize(0x140,0xf0,3,0,0);
  mZbufferTex = (void *)JKRHeap::alloc(uVar1,0x20,(JKRHeap *)0x0);
  SComponent::cLib_memSet(mZbufferTex,0,uVar1);
  J2DPrint::setBuffer(0x400);
  mBlureFlag = 0;
  mFade = 0;
  mBackColor.r = d_com_inf_game::g_clearColor.r;
  mBackColor.g = d_com_inf_game::g_clearColor.g;
  mBackColor.b = d_com_inf_game::g_clearColor.b;
  mBackColor.a = d_com_inf_game::g_clearColor.a;
  mFadeColor.r = d_com_inf_game::g_clearColor.r;
  mFadeColor.g = d_com_inf_game::g_clearColor.g;
  mFadeColor.b = d_com_inf_game::g_clearColor.b;
  mFadeColor.a = d_com_inf_game::g_clearColor.a;
  vi::VISetBlack(1);
  return;
}


/* __thiscall mDoGph_gInf_c::createHeap(void) */

void __thiscall mDoGph_gInf_c::createHeap(mDoGph_gInf_c *this)

{
  JKRHeap *pParent;
  ulong uVar1;
  
  pParent = JKRHeap::sCurrentHeap;
  mHeap[0] = JKRSolidHeap::create(0x10000,JKRHeap::sCurrentHeap,false);
  if (mHeap[0] == (JKRSolidHeap *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"m_Do_graphic.cpp",0x1eb,"mHeap[0] != 0");
    m_Do_printf::OSPanic("m_Do_graphic.cpp",0x1eb,"Halt");
  }
  mHeap[1] = JKRSolidHeap::create(0x10000,pParent,false);
  if (mHeap[1] == (JKRSolidHeap *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"m_Do_graphic.cpp",0x1ed,"mHeap[1] != 0");
    m_Do_printf::OSPanic("m_Do_graphic.cpp",0x1ed,"Halt");
  }
  mCurrentHeap = 0;
  return;
}


namespace mDoGph_gInf_c {

/* __thiscall alloc(unsigned long,
                                   int) */

void * alloc(ulong param_1,int param_2)

{
  void *pvVar1;
  
  pvVar1 = JKRHeap::alloc(&mHeap[mCurrentHeap]->parent,param_1,param_2);
  return pvVar1;
}


/* __thiscall free(void) */

void free(void)

{
  uint uVar1;
  
  uVar1 = (uint)mCurrentHeap;
  mCurrentHeap = (byte)(uVar1 ^ 1);
  JKRHeap::freeAll(&mHeap[uVar1 ^ 1]->parent);
  return;
}


/* __thiscall fadeOut(float,
                                     _GXColor &) */

void fadeOut(float param_1,_GXColor *param_2)

{
  mFadeRate = m_Do_graphic::1_0;
  if (m_Do_graphic::0_0 <= param_1) {
    mFadeRate = m_Do_graphic::0_0;
  }
  mFadeColor.r = param_2->r;
  mFadeColor.g = param_2->g;
  mFadeColor.b = param_2->b;
  mFadeColor.a = param_2->a;
  mFade = 1;
  mFadeSpeed = param_1;
  return;
}


/* __thiscall onBlure(void) */

void onBlure(void)

{
  onBlure(&m_Do_mtx::g_mDoMtx_identity);
  return;
}


/* __thiscall onBlure(float const *[][][][]) */

void onBlure(MTX34 *param_1)

{
  mBlureFlag = 1;
  mtx::PSMTXCopy(param_1,&mBlureMtx);
  return;
}


/* __thiscall fadeOut(float) */

void fadeOut(float param_1)

{
  fadeOut(param_1,&d_com_inf_game::g_clearColor);
  return;
}

}

/* __thiscall mDoGph_gInf_c::calcFade(void) */

void __thiscall mDoGph_gInf_c::calcFade(mDoGph_gInf_c *this)

{
  _GXColor local_58;
  uint local_54;
  MTX44 MStack80;
  longlong local_10;
  
  if (mFade == 0) {
    if (d_com_inf_game::g_dComIfG_gameInfo.field_0x1d1c1 == 0xff) {
      mFadeColor = mFadeColor & 0xffffff00;
    }
    else {
      mFadeColor = (uint)(byte)(-d_com_inf_game::g_dComIfG_gameInfo.field_0x1d1c1 - 1);
    }
  }
  else {
    mFadeRate = mFadeRate + mFadeSpeed;
    if (m_Do_graphic::0_0 <= mFadeRate) {
      if (m_Do_graphic::1_0 < mFadeRate) {
        mFadeRate = m_Do_graphic::1_0;
      }
    }
    else {
      mFadeRate = m_Do_graphic::0_0;
      mFade = 0;
    }
    local_10 = (longlong)(int)(m_Do_graphic::_4386 * mFadeRate);
    mFadeColor = mFadeColor & 0xffffff00 | (int)(m_Do_graphic::_4386 * mFadeRate) & 0xffU;
  }
  if (mFadeColor.a != 0) {
    gx::GXSetNumChans(1);
    gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
    local_54 = mFadeColor;
    gx::GXSetChanMatColor(4,&local_54);
    gx::GXSetNumTexGens(0);
    gx::GXSetNumTevStages(1);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_RASC);
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_RASA);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetZCompLoc(1);
    gx::GXSetZMode(false,GX_ALWAYS,false);
    gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_OR);
    gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
    local_58 = d_com_inf_game::g_clearColor;
    gx::GXSetFog(GX_FOG_NONE,m_Do_graphic::0_0,m_Do_graphic::0_0,m_Do_graphic::0_0,m_Do_graphic::0_0
                 ,&local_58);
    gx::GXSetFogRangeAdj(false,0,(_GXFogAdjTable *)0x0);
    gx::GXSetCullMode(0);
    gx::GXSetDither(1);
    gx::GXSetNumIndStages(0);
    mtx::C_MTXOrtho(m_Do_graphic::0_0,m_Do_graphic::1_0,m_Do_graphic::0_0,m_Do_graphic::1_0,
                    m_Do_graphic::0_0,m_Do_graphic::10_0,&MStack80);
    gx::GXSetProjection(&MStack80,GX_ORTHOGRAPHIC);
    gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
    gx::GXSetCurrentMtx(0);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGB8,0);
    gx::GXBegin(0x80,0,4);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,0xfb);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,0xfb);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,0xfb);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,0xfb);
  }
  return;
}


namespace mDoGph_gInf_c {

/* __thiscall onMonotone(void) */

void onMonotone(void)

{
  mMonotone = 1;
  mFrameBufferTimg->mTexFmt = GX_TF_I8;
  dPa_control_c::swapFrameBufferTexture(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl);
  return;
}


/* __thiscall offMonotone(void) */

void offMonotone(void)

{
  mMonotone = 0;
  mFrameBufferTimg->mTexFmt = GX_TF_RGBA8;
  dPa_control_c::swapFrameBufferTexture(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl);
  return;
}

}

/* __thiscall mDoGph_gInf_c::calcMonotone(void) */

void __thiscall mDoGph_gInf_c::calcMonotone(mDoGph_gInf_c *this)

{
  int iVar1;
  short sVar2;
  
  sVar2 = -600;
  if (mMonotoneRateSpeed < 0) {
    sVar2 = 400;
  }
  iVar1 = MSL_C.PPCEABI.bare.H::abs((int)mMonotoneRateSpeed);
  iVar1 = SComponent::cLib_chaseS(&mMonotoneRate,(int)sVar2,(int)(short)iVar1);
  if ((iVar1 != 0) && (0 < mMonotoneRateSpeed)) {
    offMonotone();
  }
  return;
}


namespace m_Do_graphic {

/* __stdcall mDoGph_BlankingON(void) */

void mDoGph_BlankingON(void)

{
  return;
}


/* __stdcall mDoGph_BlankingOFF(void) */

void mDoGph_BlankingOFF(void)

{
  return;
}


/* __stdcall dScnPly_BeforeOfPaint(void) */

void dScnPly_BeforeOfPaint(void)

{
  dDlst_list_c::reset(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList);
  return;
}


/* __stdcall mDoGph_BeforeOfDraw(void) */

undefined4 mDoGph_BeforeOfDraw(void)

{
  dScnPly_BeforeOfPaint();
  return 1;
}


/* __stdcall mDoGph_AfterOfDraw(void) */

undefined4 mDoGph_AfterOfDraw(void)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  _GXColor local_8 [2];
  
  if ((f_ap_game::g_HIO.deven2 & 2) == 0) {
    uVar3 = countLeadingZeros((int)(char)JUTGamePad::mPadStatus[3].button);
    uVar3 = uVar3 >> 5 & 0xff;
    bVar1 = false;
    if (((uVar3 != 0) && (f_ap_game::g_HIO.deven != '\0')) &&
       (JFWSystem::systemConsole[100] == (JUTConsole)0x0)) {
      bVar1 = true;
    }
    bVar2 = false;
    if ((uVar3 != 0) && ((f_ap_game::g_HIO.deven2 & 1) != 0)) {
      bVar2 = true;
    }
    if (mDoMain::developmentMode == '\0') {
      bVar1 = false;
      bVar2 = false;
    }
    JUTProcBar::sManager->mbDrawProcessBar = 1U - !bVar1;
    JUTProcBar::sManager->mbDrawHeapBar = 1U - !bVar1;
    JUTDbPrint::sDebugPrint[0xc] = (JUTDbPrint)('\x01' - !bVar2);
  }
  else {
    JUTProcBar::sManager->mbDrawProcessBar = 0;
    JUTProcBar::sManager->mbDrawHeapBar = 0;
    JUTDbPrint::sDebugPrint[0xc] = (JUTDbPrint)0x1;
  }
  gx::GXSetZCompLoc(1);
  gx::GXSetZMode(false,GX_ALWAYS,false);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_CLEAR);
  gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
  local_8[0] = d_com_inf_game::g_clearColor;
  gx::GXSetFog(GX_FOG_NONE,0_0,0_0,0_0,0_0,local_8);
  gx::GXSetFogRangeAdj(false,0,(_GXFogAdjTable *)0x0);
  gx::GXSetCoPlanar(0);
  gx::GXSetZTexture(0,0x11,0);
  gx::GXSetDither(1);
  gx::GXSetClipMode(false);
  gx::GXSetCullMode(0);
  *(undefined2 *)(mDoMch_render_c::mRenderModeObj + 4) = f_ap_game::g_HIO.field_0x2c;
  *(undefined2 *)(mDoMch_render_c::mRenderModeObj + 6) = f_ap_game::g_HIO.field_0x2e;
  JUTVideo::setRenderMode(JUTVideo::sManager,(_GXRenderModeObj *)mDoMch_render_c::mRenderModeObj);
  dDlst_peekZ_c::peekData(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mPeekZ);
  (**(code **)(*(int *)JFWDisplay::sManager + 0x10))();
  return 1;
}


/* __stdcall clearAlphaBuffer(view_class *,
                              unsigned char) */

void clearAlphaBuffer(int param_1,byte param_2)

{
  _GXColor local_58;
  _GXColor local_54;
  _GXColor local_50;
  MTX44 MStack76;
  
  gx::GXSetNumChans(1);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXSetNumTexGens(0);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A0);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetZCompLoc(1);
  gx::GXSetZMode(false,GX_ALWAYS,false);
  gx::GXSetBlendMode(GX_BM_NONE,GX_BL_ZERO,GX_BL_ZERO,GX_LO_OR);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
  local_54 = d_com_inf_game::g_clearColor;
  gx::GXSetFog(GX_FOG_NONE,0_0,0_0,0_0,0_0,&local_54);
  gx::GXSetFogRangeAdj(false,0,(_GXFogAdjTable *)0x0);
  gx::GXSetCullMode(0);
  gx::GXSetDither(1);
  gx::GXSetColorUpdate(false);
  gx::GXSetAlphaUpdate(1);
  gx::GXSetNumIndStages(0);
  local_50 = (_GXColor)(_4491 & 0xffffff00 | (uint)param_2);
  local_58 = local_50;
  gx::GXSetTevColor(GX_TEVREG0,&local_58);
  mtx::C_MTXOrtho(0_0,1_0,0_0,1_0,0_0,10_0,&MStack76);
  gx::GXSetProjection(&MStack76,GX_ORTHOGRAPHIC);
  gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
  gx::GXSetCurrentMtx(0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGB8,0);
  gx::GXBegin(0x80,0,4);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0xfb);
  gx::GXSetColorUpdate(true);
  gx::GXSetAlphaUpdate(0);
  gx::GXSetProjection((MTX44 *)(param_1 + 0x100),GX_PERSPECTIVE);
  return;
}


/* __stdcall drawAlphaBuffer(view_class *,
                             _GXColor) */

void drawAlphaBuffer(int param_1,_GXColor *param_2)

{
  _GXColor local_58;
  _GXColor local_54;
  MTX44 MStack80;
  
  gx::GXSetNumChans(1);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  local_54 = *param_2;
  gx::GXSetChanMatColor(0,&local_54);
  gx::GXSetNumTexGens(0);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_RASC);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetZCompLoc(1);
  gx::GXSetZMode(false,GX_ALWAYS,false);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_DSTALPHA,GX_BL_ONE,GX_LO_OR);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
  local_58 = d_com_inf_game::g_clearColor;
  gx::GXSetFog(GX_FOG_NONE,0_0,0_0,0_0,0_0,&local_58);
  gx::GXSetFogRangeAdj(false,0,(_GXFogAdjTable *)0x0);
  gx::GXSetCullMode(0);
  gx::GXSetDstAlpha(1,0);
  gx::GXSetDither(1);
  gx::GXSetColorUpdate(true);
  gx::GXSetAlphaUpdate(1);
  gx::GXSetNumIndStages(0);
  mtx::C_MTXOrtho(0_0,1_0,0_0,1_0,0_0,10_0,&MStack80);
  gx::GXSetProjection(&MStack80,GX_ORTHOGRAPHIC);
  gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
  gx::GXSetCurrentMtx(0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGB8,0);
  gx::GXBegin(0x80,0,4);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0xfb);
  gx::GXSetColorUpdate(true);
  gx::GXSetAlphaUpdate(0);
  gx::GXSetDstAlpha(0,0);
  gx::GXSetProjection((MTX44 *)(param_1 + 0x100),GX_PERSPECTIVE);
  return;
}


/* __stdcall drawSpot(view_class *) */

void drawSpot(int param_1)

{
  _GXColor local_58;
  _GXColor local_54;
  _GXColor local_50;
  _GXColor local_4c;
  MTX44 MStack72;
  
  gx::GXSetNumChans(1);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  local_4c = d_com_inf_game::g_clearColor;
  gx::GXSetChanAmbColor(4,&local_4c);
  local_50 = d_com_inf_game::g_clearColor;
  gx::GXSetChanMatColor(4,&local_50);
  gx::GXSetNumTexGens(0);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A0);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  local_54 = d_com_inf_game::g_whiteColor;
  gx::GXSetTevColor(GX_TEVREG0,&local_54);
  gx::GXSetZCompLoc(1);
  gx::GXSetZMode(false,GX_ALWAYS,false);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_DSTALPHA,GX_BL_ONE,GX_LO_OR);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
  local_58 = d_com_inf_game::g_clearColor;
  gx::GXSetFog(GX_FOG_NONE,0_0,0_0,0_0,0_0,&local_58);
  gx::GXSetFogRangeAdj(false,0,(_GXFogAdjTable *)0x0);
  gx::GXSetCullMode(0);
  gx::GXSetDither(1);
  gx::GXSetColorUpdate(false);
  gx::GXSetAlphaUpdate(1);
  mtx::C_MTXOrtho(0_0,1_0,0_0,1_0,0_0,10_0,&MStack72);
  gx::GXSetProjection(&MStack72,GX_ORTHOGRAPHIC);
  gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
  gx::GXSetCurrentMtx(0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGB8,0);
  gx::GXBegin(0x80,0,4);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0xfb);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_RASA);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_ONE,GX_BL_ONE,GX_LO_OR);
  gx::GXBegin(0x80,0,4);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0xfb);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_RASC);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_DSTALPHA,GX_BL_DSTALPHA,GX_LO_OR);
  gx::GXSetNumIndStages(0);
  gx::GXSetColorUpdate(true);
  gx::GXSetAlphaUpdate(0);
  gx::GXBegin(0x80,0,4);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0xfb);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0xfb);
  gx::GXSetProjection((MTX44 *)(param_1 + 0x100),GX_PERSPECTIVE);
  return;
}


/* WARNING: Inlined function: FUN_80328f14 */
/* WARNING: Inlined function: FUN_80328f60 */
/* WARNING: Could not reconcile some variable overlaps */
/* __stdcall drawDepth(view_class *,
                       view_port_class *,
                       int) */

void drawDepth(camera_class *pView,dDlst_window_c *pViewPort,uint param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  camera_class *this;
  dStage_FileList_dt_c *pFILI;
  dStage_roomStatus_c *pdVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  ushort uVar12;
  short sVar13;
  undefined2 uVar14;
  uint uVar15;
  ResTIMG *pRVar16;
  void *pvVar17;
  double dVar18;
  _GXColor local_e8;
  float z;
  float y;
  float x;
  _GXColorS10 local_d8;
  float viewport [6];
  float projection [7];
  MTX44 MStack156;
  longlong local_58;
  longlong local_50;
  longlong local_48;
  double local_40;
  
  this = pView;
  if (::mDoGph_gInf_c::mAutoForcus != 0) {
    gx::GXGetProjectionv(projection);
    gx::GXGetViewportv(viewport);
    gx::GXProject((double)(pView->mCenterPos).x,(double)(pView->mCenterPos).y,
                  (double)(pView->mCenterPos).z,&pView->mViewMtx,projection,viewport,&x,&y,&z);
    this = (camera_class *)(int)(_4693 * z);
    local_58 = (longlong)(int)this;
    uVar15 = 0xff0000 - (int)this >> 8;
    if ((int)uVar15 < -0x400) {
      param_3 = 0xfffffc00;
    }
    else {
      param_3 = uVar15 & ~((int)(-uVar15 & ~uVar15) >> 0x1f);
    }
  }
  if (::mDoGph_gInf_c::mMonotone == 0) {
    pFILI = (dStage_FileList_dt_c *)0x0;
    if (-1 < (char)dStage_roomControl_c::mStayNo) {
      pdVar6 = dStage_roomControl_c::getStatusRoomDt
                         (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                          (int)(char)dStage_roomControl_c::mStayNo);
      pFILI = (dStage_FileList_dt_c *)(*(code *)((pdVar6->parent).parent.vtbl)->getFileListInfo)();
    }
    uVar1 = (ushort)param_3;
    if (pFILI == (dStage_FileList_dt_c *)0x0) {
      if (::mDoGph_gInf_c::mAutoForcus == 0) {
        l_tevColor0_4558._4_4_ =
             l_tevColor0_4558._4_4_ & 0xffff0000 | (uint)(ushort)(uVar1 - DAT_803e7d50);
      }
      else {
        uVar12 = -DAT_803e7d50;
        if ((short)uVar1 < -DAT_803e7d50) {
          uVar12 = uVar1;
        }
        l_tevColor0_4558._4_4_ = l_tevColor0_4558._4_4_ & 0xffff0000 | (uint)uVar12;
      }
    }
    else {
      if (::mDoGph_gInf_c::mAutoForcus == 0) {
        l_tevColor0_4558._4_4_ =
             l_tevColor0_4558._4_4_ & 0xffff0000 |
             (uint)(ushort)(uVar1 - ((ushort)((uint)pFILI->mParam >> 7) & 0xff));
      }
      else {
        uVar15 = -((uint)pFILI->mParam >> 7 & 0xff);
        if ((int)param_3 < (int)uVar15) {
          uVar15 = param_3;
        }
        l_tevColor0_4558._4_4_ = l_tevColor0_4558._4_4_ & 0xffff0000 | uVar15 & 0xffff;
      }
    }
  }
  else {
    ::mDoGph_gInf_c::calcMonotone((mDoGph_gInf_c *)this);
    l_tevColor0_4558._4_4_ =
         l_tevColor0_4558._4_4_ & 0xffff0000 | (uint)(ushort)::mDoGph_gInf_c::mMonotoneRate;
  }
  pvVar17 = ::mDoGph_gInf_c::mZbufferTex;
  pRVar16 = ::mDoGph_gInf_c::mFrameBufferTex;
  local_58 = (longlong)(int)pViewPort->mXOrig;
  uVar12 = (ushort)(int)pViewPort->mXOrig & 0xfff8;
  local_50 = (longlong)(int)pViewPort->mYOrig;
  uVar1 = (ushort)(int)pViewPort->mYOrig;
  uVar2 = uVar1 & 0xfff8;
  iVar7 = (int)(short)uVar2;
  uVar2 = uVar2 & ~((short)uVar1 >> 0xf);
  local_48 = (longlong)(int)pViewPort->mWidth;
  uVar1 = (ushort)(int)pViewPort->mWidth & 0xfff8;
  local_40 = (double)(longlong)(int)pViewPort->mHeight;
  uVar15 = SEXT24((short)((ushort)(int)pViewPort->mHeight & 0xfff8));
  if (iVar7 < 0) {
    uVar15 = uVar15 + iVar7;
    uVar3 = -iVar7 >> 1 & 0xffff;
    iVar7 = gx::GXGetTexBufferSize(0x140,uVar3,3,0,0);
    pvVar17 = (void *)((int)pvVar17 + iVar7);
    iVar7 = gx::GXGetTexBufferSize(0x140,uVar3,::mDoGph_gInf_c::mFrameBufferTimg->mTexFmt,0,0);
    pRVar16 = (ResTIMG *)(&pRVar16->mTexFmt + iVar7);
  }
  uVar3 = (int)(short)uVar1 >> 1 & 0xffff;
  sVar13 = (short)uVar15;
  uVar4 = (int)sVar13 >> 1 & 0xffff;
  gx::GXSetCopyFilter(0,0,1,(int)&JUTVideo::sManager->mpRenderMode[4].field_0x0 + 2);
  uVar5 = (int)(short)uVar1 & 0xffff;
  gx::GXSetTexCopySrc(uVar12,uVar2,uVar5,uVar15 & 0xffff);
  gx::GXSetTexCopyDst(uVar3,uVar4,0x13,1);
  gx::GXCopyTex(pvVar17,0);
  gx::GXSetTexCopySrc(uVar12,uVar2,uVar5,uVar15 & 0xffff);
  gx::GXSetTexCopyDst(uVar3,uVar4,::mDoGph_gInf_c::mFrameBufferTimg->mTexFmt,1);
  gx::GXCopyTex(pRVar16,0);
  gx::GXInitTexObj(&::mDoGph_gInf_c::mZbufferTexObj,pvVar17,uVar3,uVar4,GX_TF_IA8,GX_CLAMP,GX_CLAMP,
                   false);
  dVar18 = (double)0_0;
  gx::GXInitTexObjLOD(dVar18,dVar18,dVar18,&::mDoGph_gInf_c::mZbufferTexObj,0,0,0,0,0);
  gx::GXInitTexObj(&::mDoGph_gInf_c::mFrameBufferTexObj,pRVar16,uVar3,uVar4,
                   ::mDoGph_gInf_c::mFrameBufferTimg->mTexFmt,GX_CLAMP,GX_CLAMP,false);
  dVar18 = (double)0_0;
  gx::GXInitTexObjLOD(dVar18,dVar18,dVar18,&::mDoGph_gInf_c::mFrameBufferTexObj,1,1,0,0,0);
  gx::GXPixModeSync();
  gx::GXLoadTexObj(&::mDoGph_gInf_c::mFrameBufferTexObj,1);
  gx::GXLoadTexObj(&::mDoGph_gInf_c::mZbufferTexObj,0);
  gx::GXSetNumChans(0);
  gx::GXSetNumTexGens(2);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetTexCoordGen2(GX_TEXCOORD1,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetNumTevStages(3);
  local_d8._0_4_ = l_tevColor0_4558._0_4_;
  local_d8._4_4_ = l_tevColor0_4558._4_4_;
  gx::GXSetTevColorS10(GX_TEVREG0,&local_d8);
  gx::GXSetTevSwapModeTable(3,3,1,2,0);
  gx::GXSetTevSwapMode(0,0,3);
  gx::GXSetTevKAlphaSel(0,0);
  gx::GXSetTevKAlphaSel(2,0);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_KONST,GX_CA_TEXA,GX_CA_KONST,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_COMP_RGB8_EQ,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_ZERO,GX_CA_APREV,GX_CA_TEXA,GX_CA_A0);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_4,true,GX_TEVPREV);
  gx::GXSetTevOrder(GX_TEVSTAGE2,GX_TEXCOORD1,GX_TEXMAP1,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE2,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_TEXC);
  gx::GXSetTevColorOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE2,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_APREV);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetZCompLoc(1);
  gx::GXSetZMode(false,GX_ALWAYS,false);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_CLEAR);
  gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
  local_e8 = d_com_inf_game::g_clearColor;
  gx::GXSetFog(GX_FOG_NONE,0_0,0_0,0_0,0_0,&local_e8);
  gx::GXSetCullMode(0);
  gx::GXSetDither(1);
  gx::GXSetNumIndStages(0);
  mtx::C_MTXOrtho(pViewPort->mYOrig,pViewPort->mYOrig + pViewPort->mHeight,pViewPort->mXOrig,
                  pViewPort->mXOrig + pViewPort->mWidth,0_0,10_0,&MStack156);
  gx::GXSetProjection(&MStack156,GX_ORTHOGRAPHIC);
  gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
  gx::GXSetCurrentMtx(0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGB8,0);
  gx::GXBegin(0x80,0,4);
  write_volatile_2(0xcc008000,uVar12);
  write_volatile_2(0xcc008000,uVar2);
  write_volatile_2(0xcc008000,0xfffb);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_2(0xcc008000,uVar1);
  write_volatile_2(0xcc008000,uVar2);
  write_volatile_2(0xcc008000,0xfffb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_2(0xcc008000,uVar1);
  write_volatile_2(0xcc008000,sVar13);
  write_volatile_2(0xcc008000,0xfffb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_2(0xcc008000,uVar12);
  write_volatile_2(0xcc008000,sVar13);
  write_volatile_2(0xcc008000,0xfffb);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,1);
  gx::GXSetTevSwapModeTable(3,2,2,2,3);
  gx::GXSetTevSwapMode(0,0,0);
  if (uVar2 == 0) {
    local_40 = (double)(longlong)(int)pViewPort->mScissorYOrig;
    sVar13 = (short)(int)pViewPort->mScissorYOrig;
    if (sVar13 != 0) {
      local_40 = (double)CONCAT44(0x43300000,(int)sVar13 ^ 0x80000000);
      iVar7 = (int)((float)(local_40 - _4698) + pViewPort->mScissorHeight);
      local_48 = (longlong)iVar7;
      gx::GXSetNumChans(1);
      gx::GXSetChanCtrl(GX_ALPHA0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
      gx::GXSetNumTexGens(0);
      gx::GXSetNumTevStages(1);
      gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
      gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
      gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
      gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetBlendMode(GX_BM_NONE,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_CLEAR);
      gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
      gx::GXClearVtxDesc();
      gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
      gx::GXBegin(0x80,0,8);
      write_volatile_2(0xcc008000,0);
      write_volatile_2(0xcc008000,0);
      write_volatile_2(0xcc008000,0xfffb);
      write_volatile_2(0xcc008000,0x280);
      write_volatile_2(0xcc008000,0);
      write_volatile_2(0xcc008000,0xfffb);
      write_volatile_2(0xcc008000,0x280);
      write_volatile_2(0xcc008000,sVar13);
      write_volatile_2(0xcc008000,0xfffb);
      write_volatile_2(0xcc008000,0);
      write_volatile_2(0xcc008000,sVar13);
      write_volatile_2(0xcc008000,0xfffb);
      write_volatile_2(0xcc008000,0);
      uVar14 = (undefined2)iVar7;
      write_volatile_2(0xcc008000,uVar14);
      write_volatile_2(0xcc008000,0xfffb);
      write_volatile_2(0xcc008000,0x280);
      write_volatile_2(0xcc008000,uVar14);
      write_volatile_2(0xcc008000,0xfffb);
      write_volatile_2(0xcc008000,0x280);
      write_volatile_2(0xcc008000,0x1e0);
      write_volatile_2(0xcc008000,0xfffb);
      write_volatile_2(0xcc008000,0);
      write_volatile_2(0xcc008000,0x1e0);
      write_volatile_2(0xcc008000,0xfffb);
    }
  }
  uVar8 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)pViewPort->mScissorHeight);
  uVar9 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)pViewPort->mScissorWidth);
  uVar10 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)pViewPort->mScissorYOrig);
  uVar11 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)pViewPort->mScissorXOrig);
  gx::GXSetScissor(uVar11,uVar10,uVar9,uVar8);
  gx::GXSetProjection(&pView->mProjMtx,GX_PERSPECTIVE);
  return;
}

}

/* __thiscall dStage_roomDt_c::getFileListInfo(void) const */

dStage_FileList_dt_c * __thiscall dStage_roomDt_c::getFileListInfo(dStage_roomDt_c *this)

{
  return this->mpFileList;
}


namespace m_Do_graphic {

/* __stdcall motionBlure(view_class *) */

void motionBlure(view_class *pView)

{
  _GXColor local_58;
  _GXColor local_54;
  _GXColor local_50;
  MTX44 MStack76;
  
  if (::mDoGph_gInf_c::mBlureFlag != '\0') {
    gx::GXLoadTexObj(&::mDoGph_gInf_c::mFrameBufferTexObj,0);
    local_50 = (_GXColor)((uint)local_50 & 0xffffff00 | (uint)::mDoGph_gInf_c::mBlureRate);
    gx::GXSetNumChans(0);
    gx::GXSetNumTexGens(1);
    gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_TEXMTX0,false,GX_PTIDENTITY);
    gx::GXLoadTexMtxImm(&::mDoGph_gInf_c::mBlureMtx,GX_TEXMTX0,1);
    gx::GXSetNumTevStages(1);
    local_54 = local_50;
    gx::GXSetTevColor(GX_TEVREG0,&local_54);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_TEXC);
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A0);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetZCompLoc(1);
    gx::GXSetZMode(false,GX_ALWAYS,false);
    gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_CLEAR);
    gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
    local_58 = d_com_inf_game::g_clearColor;
    gx::GXSetFog(GX_FOG_NONE,0_0,0_0,0_0,0_0,&local_58);
    gx::GXSetCullMode(0);
    gx::GXSetDither(1);
    mtx::C_MTXOrtho(0_0,1_0,0_0,1_0,0_0,10_0,&MStack76);
    gx::GXSetProjection(&MStack76,GX_ORTHOGRAPHIC);
    gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
    gx::GXSetCurrentMtx(0);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGB8,0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGB8,0);
    gx::GXBegin(0x80,0,4);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,0xfb);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,0xfb);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,0xfb);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,1);
    write_volatile_1(DAT_cc008000,0xfb);
    write_volatile_1(DAT_cc008000,0);
    write_volatile_1(DAT_cc008000,1);
    gx::GXSetProjection((MTX44 *)&pView[1].parent.mLnTg.parent.parent.mpData,GX_PERSPECTIVE);
  }
  return;
}


/* __stdcall mCaptureAlarmHandler(OSAlarm *,
                                  OSContext *) */

void mCaptureAlarmHandler(void)

{
  os::OSWakeupThread(&mCaptureThreadQueue);
  return;
}


/* __stdcall mDoGph_setCaptureStep(short) */

void mDoGph_setCaptureStep(short param_1)

{
  mCaptureStep = param_1;
  return;
}


/* __stdcall mDoGph_getCaptureStep(void) */

int mDoGph_getCaptureStep(void)

{
  return (int)mCaptureStep;
}


/* __stdcall mDoGph_getCaptureTextureBuffer(void) */

undefined4 mDoGph_getCaptureTextureBuffer(void)

{
  return mCaptureTextureBuffer;
}


/* __stdcall mDoGph_setCaptureTextureFormat(unsigned char) */

void mDoGph_setCaptureTextureFormat(undefined param_1)

{
  mCaptureTextureFormat = param_1;
  return;
}


/* __stdcall mDoGph_setCaptureCaptureFormat(unsigned char) */

void mDoGph_setCaptureCaptureFormat(undefined param_1)

{
  mCaptureCaptureFormat = param_1;
  return;
}


/* __stdcall mDoGph_CaptureCansel(void) */

void mDoGph_CaptureCansel(void)

{
  if (mCaptureStep < 0) {
    mCaptureStep = 0;
    mCaptureCansel = 0;
    return;
  }
  if (mCaptureStep == 0) {
    return;
  }
  mCaptureCansel = 1;
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* __stdcall blockenc(unsigned char *) */

void blockenc(int param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  byte *pbVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint local_a8 [4];
  byte local_98 [48];
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  
  uVar18 = 0;
  uVar14 = 0;
  iVar17 = 0;
  do {
    uVar16 = 0;
    pbVar12 = (byte *)(param_1 + iVar17);
    uVar23 = uVar18;
    for (iVar11 = 0;
        (uVar23 != 0 &&
        (((local_98[iVar11] != *pbVar12 || (local_98[iVar11 + 1] != pbVar12[1])) ||
         (local_98[iVar11 + 2] != pbVar12[2])))); iVar11 = iVar11 + 3) {
      uVar16 = uVar16 + 1;
      uVar23 = uVar23 - 1;
    }
    if (uVar16 == uVar18) {
      iVar11 = uVar16 * 3;
      local_98[iVar11] = *pbVar12;
      local_98[iVar11 + 1] = pbVar12[1];
      local_98[iVar11 + 2] = pbVar12[2];
      uVar18 = uVar18 + 1;
    }
    uVar14 = uVar14 + 3;
    iVar17 = iVar17 + 4;
  } while (uVar14 < 0x30);
  uVar16 = 0;
  uVar14 = 0;
  if (1 < uVar18) {
    uVar23 = 0x7fffffff;
    for (uVar21 = 0; uVar21 < uVar18 * 3 - 3; uVar21 = uVar21 + 3) {
      uVar13 = (uint)local_98[uVar21];
      uVar15 = (uint)local_98[uVar21 + 1];
      uVar7 = (uint)local_98[uVar21 + 2];
      uVar6 = uVar21;
      while (uVar8 = uVar6 + 3, uVar8 < uVar18 * 3) {
        uVar10 = (uint)local_98[uVar6 + 3];
        uVar2 = (uint)local_98[uVar6 + 4];
        uVar6 = (uint)local_98[uVar6 + 5];
        local_54 = uVar13 * 0x96 + uVar10 * 0x5a >> 3;
        local_58 = uVar15 * 0x127 + uVar2 * 0xb1 >> 3;
        local_5c = uVar7 * 0x37 + uVar6 * 0x21 >> 3;
        local_60 = uVar10 * 0x96 + uVar13 * 0x5a >> 3;
        local_64 = uVar2 * 0x127 + uVar15 * 0xb1 >> 3;
        local_68 = uVar6 * 0x37 + uVar7 * 0x21 >> 3;
        uVar19 = 0;
        iVar17 = 0;
        for (uVar20 = 0; uVar20 < 0x10; uVar20 = uVar20 + 1) {
          pbVar12 = (byte *)(param_1 + iVar17);
          uVar3 = (uint)pbVar12[2];
          iVar11 = uVar7 * 0xb + uVar3 * -0xb;
          uVar4 = (uint)*pbVar12;
          iVar9 = uVar13 * 0x1e + uVar4 * -0x1e;
          uVar5 = (uint)pbVar12[1];
          iVar22 = uVar15 * 0x3b + uVar5 * -0x3b;
          local_a8[0] = iVar9 * iVar9 + iVar22 * iVar22 + iVar11 * iVar11;
          iVar11 = uVar6 * 0xb + uVar3 * -0xb;
          iVar9 = uVar10 * 0x1e + uVar4 * -0x1e;
          iVar22 = uVar2 * 0x3b + uVar5 * -0x3b;
          local_a8[1] = iVar9 * iVar9 + iVar22 * iVar22 + iVar11 * iVar11;
          iVar11 = local_5c + uVar3 * -0xb;
          iVar9 = local_54 + uVar4 * -0x1e;
          iVar22 = local_58 + uVar5 * -0x3b;
          local_a8[2] = iVar9 * iVar9 + iVar22 * iVar22 + iVar11 * iVar11;
          iVar11 = local_68 + uVar3 * -0xb;
          iVar9 = local_60 + uVar4 * -0x1e;
          iVar22 = local_64 + uVar5 * -0x3b;
          local_a8[3] = iVar9 * iVar9 + iVar22 * iVar22 + iVar11 * iVar11;
          iVar11 = 0;
          uVar3 = 0x7fffffff;
          iVar9 = 4;
          do {
            if (*(uint *)((int)local_a8 + iVar11) < uVar3) {
              uVar3 = *(uint *)((int)local_a8 + iVar11);
            }
            iVar11 = iVar11 + 4;
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
          uVar19 = uVar19 + uVar3;
          iVar17 = iVar17 + 4;
        }
        uVar6 = uVar8;
        if (uVar19 < uVar23) {
          uVar14 = uVar8;
          uVar16 = uVar21;
          uVar23 = uVar19;
        }
      }
    }
  }
  uVar16 = (uint)((local_98 + 2)[uVar16] >> 3) |
           (local_98[uVar16] & 0xf8) << 8 | ((local_98 + 1)[uVar16] & 0xfc) << 3;
  uVar14 = (uint)((local_98 + 2)[uVar14] >> 3) |
           (local_98[uVar14] & 0xf8) << 8 | ((local_98 + 1)[uVar14] & 0xfc) << 3;
  bVar1 = uVar16 == uVar14;
  uVar18 = uVar16;
  if ((uVar14 <= uVar16) && (uVar18 = uVar14, uVar14 = uVar16, bVar1)) {
    uVar18 = 0;
  }
  *(char *)(param_1 + 0x40) = (char)(uVar14 >> 8);
  *(char *)(param_1 + 0x41) = (char)uVar14;
  *(char *)(param_1 + 0x42) = (char)(uVar18 >> 8);
  *(char *)(param_1 + 0x43) = (char)uVar18;
  uVar16 = uVar14 >> 8 & 0xf8;
  uVar23 = uVar14 >> 3 & 0xfc;
  uVar14 = uVar14 & 0x1f;
  uVar21 = uVar18 >> 8 & 0xf8;
  uVar6 = uVar18 >> 3 & 0xfc;
  uVar18 = uVar18 & 0x1f;
  iVar17 = 0x1e;
  uVar15 = 0;
  for (uVar13 = 0; uVar13 < 0x40; uVar13 = uVar13 + 4) {
    pbVar12 = (byte *)(param_1 + uVar13);
    uVar7 = (uint)pbVar12[2];
    iVar11 = uVar14 * 0x58 + uVar7 * -0xb;
    uVar8 = (uint)*pbVar12;
    iVar9 = uVar16 * 0x1e + uVar8 * -0x1e;
    uVar10 = (uint)pbVar12[1];
    iVar22 = uVar23 * 0x3b + uVar10 * -0x3b;
    local_a8[0] = iVar9 * iVar9 + iVar22 * iVar22 + iVar11 * iVar11;
    iVar11 = uVar18 * 0x58 + uVar7 * -0xb;
    iVar9 = uVar21 * 0x1e + uVar8 * -0x1e;
    iVar22 = uVar6 * 0x3b + uVar10 * -0x3b;
    local_a8[1] = iVar9 * iVar9 + iVar22 * iVar22 + iVar11 * iVar11;
    iVar11 = (uVar14 * 0x1b8 + uVar18 * 0x108 >> 3) + uVar7 * -0xb;
    iVar9 = (uVar16 * 0x96 + uVar21 * 0x5a >> 3) + uVar8 * -0x1e;
    iVar22 = (uVar23 * 0x127 + uVar6 * 0xb1 >> 3) + uVar10 * -0x3b;
    local_a8[2] = iVar9 * iVar9 + iVar22 * iVar22 + iVar11 * iVar11;
    iVar22 = (uVar18 * 0x1b8 + uVar14 * 0x108 >> 3) + uVar7 * -0xb;
    iVar9 = (uVar21 * 0x96 + uVar16 * 0x5a >> 3) + uVar8 * -0x1e;
    iVar11 = (uVar6 * 0x127 + uVar23 * 0xb1 >> 3) + uVar10 * -0x3b;
    local_a8[3] = iVar9 * iVar9 + iVar11 * iVar11 + iVar22 * iVar22;
    uVar7 = 0;
    uVar10 = 0;
    uVar8 = 0x7fffffff;
    iVar11 = 0;
    iVar9 = 4;
    do {
      if (*(uint *)((int)local_a8 + iVar11) < uVar8) {
        uVar7 = uVar10;
        uVar8 = *(uint *)((int)local_a8 + iVar11);
      }
      uVar10 = uVar10 + 1;
      iVar11 = iVar11 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    uVar15 = uVar15 | (uVar7 & 3) << iVar17;
    iVar17 = iVar17 + -2;
  }
  *(char *)(param_1 + 0x44) = (char)(uVar15 >> 0x18);
  *(char *)(param_1 + 0x45) = (char)(uVar15 >> 0x10);
  *(char *)(param_1 + 0x46) = (char)(uVar15 >> 8);
  *(char *)(param_1 + 0x47) = (char)uVar15;
  return;
}


/* WARNING: Inlined function: FUN_80328f14 */
/* WARNING: Inlined function: FUN_80328f60 */
/* __stdcall encode_s3tc(unsigned char *,
                         unsigned char *,
                         int,
                         int,
                         _GXTexFmt) */

int encode_s3tc(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  int iVar5;
  ulong uVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  byte local_88 [64];
  byte abStack72 [16];
  
  iVar20 = 0;
  if (param_5 == 1) {
    uVar19 = 0xff;
    uVar18 = 0;
    for (iVar13 = 0; iVar13 < param_4; iVar13 = iVar13 + 8) {
      iVar17 = 0;
      for (iVar14 = 0; iVar14 < param_3; iVar14 = iVar14 + 8) {
        iVar15 = 0;
        do {
          iVar16 = 0;
          do {
            iVar9 = 0;
            iVar5 = 0;
            iVar10 = 0;
            do {
              iVar7 = iVar10 + iVar16 + iVar17 + param_3 * (iVar13 + iVar15);
              pbVar11 = (byte *)(param_1 + iVar7);
              iVar21 = 4;
              do {
                uVar12 = (uint)*pbVar11;
                if (uVar12 < uVar19) {
                  uVar19 = uVar12;
                }
                if (uVar18 < uVar12) {
                  uVar18 = uVar12;
                }
                bVar2 = (byte)(((uVar12 - 0x10) * 0xff) / 0xdb);
                bVar3 = bVar2 & 0xf8;
                local_88[iVar9] = bVar3;
                local_88[iVar9 + 1] = bVar2 & 0xfc;
                local_88[iVar9 + 2] = bVar3;
                local_88[iVar9 + 3] = 0xff;
                iVar9 = iVar9 + 4;
                iVar7 = iVar7 + 1;
                pbVar11 = pbVar11 + 1;
                iVar21 = iVar21 + -1;
              } while (iVar21 != 0);
              iVar5 = iVar5 + 1;
              iVar10 = iVar10 + 8;
            } while (iVar5 < 4);
            blockenc(local_88,iVar7);
            copy_bytes((byte *)(param_2 + iVar20),abStack72,8);
            iVar16 = iVar16 + 4;
            iVar20 = iVar20 + 8;
          } while (iVar16 < 8);
          iVar15 = iVar15 + 4;
        } while (iVar15 < 8);
        iVar17 = iVar17 + 0x20;
      }
    }
    bVar4 = false;
    if ((0xf < uVar19) && (uVar18 < 0xec)) {
      bVar4 = true;
    }
    if (!bVar4) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"m_Do_graphic.cpp",0x8a7,"16 <= i8low && i8high <= 235");
      m_Do_printf::OSPanic("m_Do_graphic.cpp",0x8a7,"Halt");
    }
  }
  else {
    if (param_5 == 4) {
      for (iVar13 = 0; iVar13 < param_4; iVar13 = iVar13 + 8) {
        for (iVar14 = 0; iVar14 < param_3; iVar14 = iVar14 + 8) {
          iVar17 = 0;
          do {
            iVar15 = 0;
            do {
              iVar5 = 0;
              iVar9 = 0;
              iVar16 = 0;
              do {
                puVar8 = (ushort *)
                         (param_1 + iVar16 + (iVar14 + iVar15) * 8 + param_3 * (iVar13 + iVar17) * 2
                         );
                iVar10 = 4;
                do {
                  uVar1 = *puVar8;
                  local_88[iVar5] = (byte)(uVar1 >> 8) & 0xf8;
                  local_88[iVar5 + 1] = (byte)(uVar1 >> 3) & 0xfc;
                  local_88[iVar5 + 2] = (char)uVar1 << 3;
                  local_88[iVar5 + 3] = 0xff;
                  iVar5 = iVar5 + 4;
                  puVar8 = puVar8 + 1;
                  iVar10 = iVar10 + -1;
                } while (iVar10 != 0);
                iVar9 = iVar9 + 1;
                iVar16 = iVar16 + 8;
              } while (iVar9 < 4);
              blockenc(local_88);
              copy_bytes((byte *)(param_2 + iVar20),abStack72,8);
              iVar15 = iVar15 + 4;
              iVar20 = iVar20 + 8;
            } while (iVar15 < 8);
            iVar17 = iVar17 + 4;
          } while (iVar17 < 8);
        }
      }
    }
    else {
      if (param_5 == 6) {
        for (iVar13 = 0; iVar13 < param_4; iVar13 = iVar13 + 8) {
          for (iVar14 = 0; iVar14 < param_3; iVar14 = iVar14 + 8) {
            iVar17 = 0;
            do {
              iVar15 = 0;
              do {
                iVar16 = 0;
                iVar5 = 0;
                iVar9 = 0;
                do {
                  iVar10 = iVar9 + (iVar14 + iVar15) * 0x10 + param_3 * (iVar13 + iVar17) * 4;
                  iVar7 = iVar10 + 0x20;
                  iVar21 = 4;
                  do {
                    local_88[iVar16] = ((byte *)(param_1 + iVar10))[1] & 0xf8;
                    local_88[iVar16 + 1] = *(byte *)(param_1 + iVar7) & 0xfc;
                    local_88[iVar16 + 2] = ((byte *)(param_1 + iVar7))[1] & 0xf8;
                    local_88[iVar16 + 3] = *(byte *)(param_1 + iVar10);
                    local_88[iVar16 + 3] = 0xff;
                    iVar16 = iVar16 + 4;
                    iVar10 = iVar10 + 2;
                    iVar7 = iVar7 + 2;
                    iVar21 = iVar21 + -1;
                  } while (iVar21 != 0);
                  iVar5 = iVar5 + 1;
                  iVar9 = iVar9 + 8;
                } while (iVar5 < 4);
                blockenc(local_88);
                copy_bytes((byte *)(param_2 + iVar20),abStack72,8);
                iVar15 = iVar15 + 4;
                iVar20 = iVar20 + 8;
              } while (iVar15 < 8);
              iVar17 = iVar17 + 4;
            } while (iVar17 < 8);
          }
        }
      }
    }
  }
  return iVar20;
}


/* __stdcall setUpRectangle(void) */

void setUpRectangle(void)

{
  _GXColor local_58;
  _GXColor local_54;
  _GXColor local_50;
  MTX44 MStack76;
  
  gx::GXSetNumChans(0);
  gx::GXSetNumTexGens(1);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetNumTevStages(1);
  local_50 = mCaptureMonoColor0;
  gx::GXSetTevColor(GX_TEVREG0,&local_50);
  local_54 = mCaptureMonoColor1;
  gx::GXSetTevColor(GX_TEVREG1,&local_54);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C0,GX_CC_C1,GX_CC_TEXC,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_KONST);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetZCompLoc(1);
  gx::GXSetZMode(false,GX_ALWAYS,false);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_COPY);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
  local_58 = d_com_inf_game::g_clearColor;
  gx::GXSetFog(GX_FOG_NONE,0_0,0_0,0_0,0_0,&local_58);
  gx::GXSetClipMode(true);
  gx::GXSetCullMode(0);
  gx::GXSetDither(1);
  gx::GXSetNumIndStages(0);
  gx::GXSetTevDirect(0);
  mtx::C_MTXOrtho(_5160,_5161,_5162,_5163,0_0,10_0,&MStack76);
  gx::GXSetProjection(&MStack76,GX_ORTHOGRAPHIC);
  gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
  gx::GXSetCurrentMtx(0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGB8,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall drawRectangle(int,
                           int,
                           int,
                           int) */

void drawRectangle
               (undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  gx::GXBegin(0x80,0,4);
  write_volatile_2(0xcc008000,param_1);
  write_volatile_2(0xcc008000,param_2);
  write_volatile_2(0xcc008000,0xfffb);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_2(0xcc008000,param_3);
  write_volatile_2(0xcc008000,param_2);
  write_volatile_2(0xcc008000,0xfffb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_2(0xcc008000,param_3);
  write_volatile_2(0xcc008000,param_4);
  write_volatile_2(0xcc008000,0xfffb);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_2(0xcc008000,param_1);
  write_volatile_2(0xcc008000,param_4);
  write_volatile_2(0xcc008000,0xfffb);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall mDoGph_allocFromAny(unsigned long,
                                 int) */

void * mDoGph_allocFromAny(ulong param_1,int param_2)

{
  JKRHeap *pJVar1;
  void *pvVar2;
  JKRExpHeap *pHeap;
  
  pJVar1 = m_Do_ext::mDoExt_getZeldaHeap();
  pvVar2 = (void *)JKRHeap::alloc(param_1,param_2,pJVar1);
  if (pvVar2 == (void *)0x0) {
    pHeap = m_Do_ext::mDoExt_getGameHeap();
    pvVar2 = (void *)JKRHeap::alloc(param_1,param_2,&pHeap->parent);
  }
  if (pvVar2 == (void *)0x0) {
    pJVar1 = m_Do_ext::mDoExt_getArchiveHeap();
    pvVar2 = (void *)JKRHeap::alloc(param_1,param_2,pJVar1);
  }
  if (pvVar2 == (void *)0x0) {
    pvVar2 = JKRHeap::alloc(JKRHeap::sSystemHeap,param_1,param_2);
  }
  if (pvVar2 == (void *)0x0) {
    pvVar2 = ::mDoGph_gInf_c::mZbufferTex;
  }
  FUN_800033a8((int)pvVar2,0,param_1);
  return pvVar2;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __stdcall mDoGph_screenCaptureDraw(void) */

void mDoGph_screenCaptureDraw(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  double dVar5;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  GXTexObj GStack120;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined auStack64 [32];
  
  uVar4 = (uint)mCaptureSizeWidth;
  uVar3 = (uint)mCaptureSizeHeight;
  iVar2 = (int)mCaptureCenterX;
  iVar1 = (int)mCaptureCenterY;
  gx::GXGetProjectionv(auStack64);
  gx::GXGetViewportv(&local_58);
  gx::GXGetScissor(&local_7c,&local_80,&local_84,&local_88);
  dVar5 = (double)0_0;
  gx::GXSetViewport(dVar5,dVar5,(double)_5233,(double)_5234,dVar5,(double)1_0);
  setUpRectangle();
  if (mCaptureCaptureBuffer == (void *)0x0) {
    if (mCaptureTextureBuffer == (void *)0x0) goto LAB_8000aa6c;
    gx::GXInitTexObj(&GStack120,mCaptureTextureBuffer,uVar4,uVar3,mCaptureTextureFormat,GX_CLAMP,
                     GX_CLAMP,false);
  }
  else {
    gx::GXInitTexObj(&GStack120,mCaptureCaptureBuffer,uVar4,uVar3,mCaptureCaptureFormat,GX_CLAMP,
                     GX_CLAMP,false);
  }
  gx::GXLoadTexObj(&GStack120,0);
  if (mCaptureDraw == '\x01') {
    drawRectangle(iVar2 - uVar4,iVar1 - uVar3,iVar2 + uVar4,iVar1 + uVar3);
  }
  else {
    if (mCaptureDraw == '\x02') {
      drawRectangle(iVar2 - ((int)uVar4 >> 1),iVar1 - ((int)uVar3 >> 1),iVar2 + ((int)uVar4 >> 1),
                    iVar1 + ((int)uVar3 >> 1));
    }
    else {
      if (mCaptureDraw == '\x03') {
        drawRectangle(iVar2 + uVar4 * -2,iVar1 + uVar3 * -2,iVar2 + uVar4 * 2,iVar1 + uVar3 * 2);
      }
      else {
        if (mCaptureDraw == '\x04') {
          drawRectangle(iVar2 - uVar4,iVar1 - uVar3,iVar2,iVar1);
          drawRectangle(iVar2,iVar1 - uVar3,iVar2 + uVar4,iVar1);
          drawRectangle(iVar2 - uVar4,iVar1,iVar2,iVar1 + uVar3);
          drawRectangle(iVar2,iVar1,iVar2 + uVar4,iVar1 + uVar3);
        }
      }
    }
  }
LAB_8000aa6c:
  gx::GXSetProjectionv(auStack64);
  gx::GXSetViewport((double)local_58,(double)local_54,(double)local_50,(double)local_4c,
                    (double)local_48,(double)local_44);
  gx::GXSetScissor(local_7c,local_80,local_84,local_88);
  gx::GXSetClipMode(false);
  return;
}


/* __stdcall mCaptureProc(void *) */

undefined4 mCaptureProc(void)

{
  undefined4 uVar1;
  
  uVar1 = encode_s3tc(mCaptureCaptureBuffer,mCaptureTextureBuffer,mCaptureSizeWidth,
                      mCaptureSizeHeight,mCaptureCaptureFormat);
  os::DCStoreRange(mCaptureTextureBuffer,mCaptureTextureSize);
  os::OSExitThread(uVar1);
  return uVar1;
}


/* __stdcall mCaptureGXDrawSyncCallback(unsigned short) */

void mCaptureGXDrawSyncCallback(void)

{
  undefined4 uVar1;
  code *pcVar2;
  ulong uVar3;
  
  os::OSCancelAlarm(&mCaptureTimeOutAlarm);
  uVar1 = os::OSDisableInterrupts();
  if (mCaptureStep == 2) {
    pcVar2 = (code *)gx::GXSetDrawSyncCallback(mCaptureOldCB);
    if (pcVar2 != mCaptureGXDrawSyncCallback) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"m_Do_graphic.cpp",0xa5f,"oldcb == mCaptureGXDrawSyncCallback")
      ;
      m_Do_printf::OSPanic("m_Do_graphic.cpp",0xa5f,"Halt");
    }
    mCaptureOldCB = 0;
    mCaptureStep = mCaptureStep + 1;
  }
  os::OSRestoreInterrupts(uVar1);
  return;
}


/* __stdcall mCaptureGXDrawSyncTimeOut(OSAlarm *,
                                       OSContext *) */

void mCaptureGXDrawSyncTimeOut(void)

{
  m_Do_printf::OSReport_Error("キャプチャタイムアウト\n");
  mCaptureGXDrawSyncCallback(0);
  if (mCaptureCaptureBuffer != (void *)0x0) {
    JKRHeap::free(mCaptureCaptureBuffer,(JKRHeap *)0x0);
    mCaptureCaptureBuffer = (void *)0x0;
  }
  if (mCaptureTextureBuffer != (void *)0x0) {
    JKRHeap::free(mCaptureTextureBuffer,(JKRHeap *)0x0);
    mCaptureTextureBuffer = (void *)0x0;
  }
  mCaptureStep = -1;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall mDoGph_screenCapture(void) */

undefined4 mDoGph_screenCapture(void)

{
  undefined4 uVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  double dVar7;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined auStack64 [40];
  
  uVar6 = (uint)mCaptureSizeWidth;
  uVar5 = (uint)mCaptureSizeHeight;
  iVar4 = (int)mCaptureCenterX;
  iVar3 = (int)mCaptureCenterY;
  mCaptureTextureSize = gx::GXGetTexBufferSize(uVar6,uVar5,mCaptureTextureFormat,0,0);
  mCaptureTextureBuffer = (void *)mDoGph_allocFromAny(mCaptureTextureSize,0x20);
  if (mCaptureTextureBuffer == (void *)0x0) {
    mCaptureStep = -1;
    uVar1 = 0;
  }
  else {
    if (mCaptureTextureFormat == '\x0e') {
      mCaptureCaptureSize = gx::GXGetTexBufferSize(uVar6,uVar5,mCaptureCaptureFormat,0,0);
      mCaptureCaptureBuffer = (void *)mDoGph_allocFromAny(mCaptureCaptureSize,0x20);
      if (mCaptureCaptureBuffer == (void *)0x0) {
        JKRHeap::free(mCaptureTextureBuffer,(JKRHeap *)0x0);
        mCaptureStep = -1;
        mCaptureTextureBuffer = (void *)0x0;
        return 0;
      }
    }
    else {
      mCaptureCaptureFormat = mCaptureTextureFormat;
      mCaptureCaptureBuffer = mCaptureTextureBuffer;
    }
    gx::GXGetProjectionv(auStack64);
    gx::GXGetViewportv(&local_58);
    gx::GXGetScissor(&local_5c,&local_60,&local_64,&local_68);
    dVar7 = (double)0_0;
    gx::GXSetViewport(dVar7,dVar7,(double)_5233,(double)_5234,dVar7,(double)1_0);
    if (mCaptureEnableGXSetCopyFilter != '\0') {
      gx::GXSetCopyFilter(0,0,0,0);
    }
    setUpRectangle();
    gx::GXSetTexCopySrc(iVar4 - uVar6 & 0xffff,iVar3 - uVar5 & 0xffff,uVar6 << 1,uVar5 << 1);
    gx::GXSetTexCopyDst(uVar6,uVar5,mCaptureCaptureFormat,1);
    os::DCInvalidateRange(mCaptureCaptureBuffer,mCaptureCaptureSize);
    gx::GXCopyTex(mCaptureCaptureBuffer,0);
    gx::GXPixModeSync();
    if (mCaptureOldCB != 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"m_Do_graphic.cpp",0xac1,"mCaptureOldCB == 0");
      m_Do_printf::OSPanic("m_Do_graphic.cpp",0xac1,"Halt");
    }
    mCaptureOldCB = gx::GXSetDrawSyncCallback(mCaptureGXDrawSyncCallback);
    os::OSCreateAlarm(&mCaptureTimeOutAlarm);
    os::OSSetAlarm(&mCaptureTimeOutAlarm,0x80010000,mCaptureTimeOutTicks,DAT_803f68ec,
                   mCaptureGXDrawSyncTimeOut);
    mCaptureStep = mCaptureStep + 1;
    gx::GXSetDrawSync(0);
    gx::GXSetProjectionv(auStack64);
    gx::GXSetViewport((double)local_58,(double)local_54,(double)local_50,(double)local_4c,
                      (double)local_48,(double)local_44);
    gx::GXSetScissor(local_5c,local_60,local_64,local_68);
    gx::GXSetClipMode(false);
    uVar1 = 1;
  }
  return uVar1;
}


/* __stdcall setLight(void) */

void setLight(void)

{
  double dVar1;
  _GXColor local_48;
  _GXLightObj _Stack68;
  
  gx::GXInitLightPos((double)_5288,(double)0_0,(double)_5289,&_Stack68);
  dVar1 = (double)0_0;
  gx::GXInitLightDir(dVar1,dVar1,dVar1,&_Stack68);
  local_48 = d_com_inf_game::g_whiteColor;
  gx::GXInitLightColor(&_Stack68,&local_48);
  gx::GXInitLightDistAttn(&_Stack68,0_0,0_0,GX_DA_GENTLE);
  gx::GXInitLightSpot(&_Stack68,0_0,GX_SP_FLAT);
  gx::GXLoadLightObjImm(&_Stack68,GX_LIGHT0);
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __stdcall mDoGph_Painter(void) */

undefined4 mDoGph_Painter(void)

{
  uint uVar1;
  bool bVar2;
  JFWDisplay *pJVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  byte bVar10;
  dPa_control_c *this;
  dDlst_list_c *this_00;
  dDlst_window_c *pWindow;
  camera_class *pView;
  u8 uStack534;
  u8 uStack533;
  _GXColor local_214;
  _GXColor local_210;
  _GXColor local_20c;
  undefined4 local_208;
  undefined auStack516 [4];
  TBox2_float_ local_200;
  TBox2_float_ local_1f0;
  JPADrawInfo local_1e0;
  JPADrawInfo local_1d4;
  JPADrawInfo JStack456;
  MTX34 MStack444;
  MTX34 MStack396;
  undefined auStack344 [40];
  dDlst_window_c dStack304;
  J2DOrthoGraph JStack264;
  
  JFWDisplay::sManager->mpFader = ::mDoGph_gInf_c::mFader;
  pJVar3 = JFWDisplay::sManager;
  uVar5 = ::mDoGph_gInf_c::mBackColor;
  uStack534 = (u8)((uint)::mDoGph_gInf_c::mBackColor >> 8);
  uStack533 = (u8)::mDoGph_gInf_c::mBackColor;
  local_208 = ::mDoGph_gInf_c::mBackColor;
  local_214.r = (u8)((uint)::mDoGph_gInf_c::mBackColor >> 0x18);
  (JFWDisplay::sManager->mClearColor).r = local_214.r;
  local_214.g = (u8)((uint)uVar5 >> 0x10);
  (pJVar3->mClearColor).g = local_214.g;
  (pJVar3->mClearColor).b = uStack534;
  (pJVar3->mClearColor).a = uStack533;
  (**(code **)(*(int *)JFWDisplay::sManager + 8))();
  gx::GXSetAlphaUpdate(0);
  ::mDoGph_gInf_c::mBackColor =
       CONCAT31(CONCAT21(CONCAT11(d_com_inf_game::g_clearColor.r,d_com_inf_game::g_clearColor.g),
                         d_com_inf_game::g_clearColor.b),d_com_inf_game::g_clearColor.a);
  ::mDoGph_gInf_c::free();
  if (mCaptureEnableGXSetCopyFilter != '\0') {
    gx::GXSetCopyFilter(0,0,0,0);
  }
  J3DSys::drawInit(&J3DGraphBase::j3dSys);
  gx::GXSetDither(1);
  ::J2DOrthoGraph::J2DOrthoGraph(&JStack264,0_0,0_0,_5233,_5234,_5850,1_0);
  local_1f0.mTL.x = _5162;
  local_1f0.mTL.y = _5160;
  local_1f0.mBR.x = _5163;
  local_1f0.mBR.y = _5161;
  ::J2DOrthoGraph::setOrtho(&JStack264,&local_1f0,_5850,1_0);
  ::J2DOrthoGraph::setPort(&JStack264);
  d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph = &JStack264;
  dDlst_list_c::draw(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                     (dDlst_base_c **)&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x3c,
                     d_com_inf_game::g_dComIfG_gameInfo.mDlstList._76_4_);
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 != 0) {
    pWindow = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow;
    iVar4 = (int)(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCameraInfo;
    pView = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar4].mpCamera;
    if (pView != (camera_class *)0x0) {
      dDlst_shadowControl_c::imageDraw
                (&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mShadowControl,&pView->mViewMtx);
      if ((0_0 != d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mXOrig) ||
         (0_0 != d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mYOrig)) {
        dStack304.mXOrig =
             _5851 * (_5852 * d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mXOrig +
                     d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mWidth) - _5853;
        dStack304.mYOrig =
             _5851 * (_5852 * d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mYOrig +
                     d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mHeight) - _5854;
        dStack304.mWidth = _5233;
        dStack304.mHeight = _5234;
        dStack304.mNearZ = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mNearZ;
        dStack304.mFarZ = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mFarZ;
        dStack304.mScissorXOrig =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mScissorXOrig;
        dStack304.mScissorYOrig =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mScissorYOrig;
        dStack304.mScissorWidth =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mScissorWidth;
        dStack304.mScissorHeight =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mScissorHeight;
        pWindow = &dStack304;
      }
      gx::GXSetViewport((double)pWindow->mXOrig,(double)pWindow->mYOrig,(double)pWindow->mWidth,
                        (double)pWindow->mHeight,(double)pWindow->mNearZ,(double)pWindow->mFarZ);
      uVar5 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)pWindow->mHeight);
      uVar6 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)pWindow->mWidth);
      uVar7 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)pWindow->mYOrig);
      uVar8 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)pWindow->mXOrig);
      gx::GXSetScissor(uVar8,uVar7,uVar6,uVar5);
      JStack456.mpViewMtx = &pView->mViewMtx;
      JStack456.mFovY = pView->mFovY;
      JStack456.mAspect = pView->mAspect;
      bVar2 = false;
      iVar9 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"GTower");
      if (iVar9 == 0) {
        if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mLayerNo == 9) {
          bVar2 = true;
        }
      }
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5cf4 =
           d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5cf8 = pView;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5cfc = pWindow;
      gx::GXSetProjection(&pView->mProjMtx,GX_PERSPECTIVE);
      base::PPCSync();
      mtx::PSMTXCopy(&pView->mViewMtx,&J3DGraphBase::j3dSys.mCurViewMtx);
      d_kankyo::dKy_setLight();
      J3DGraphBase::j3dSys.mCurDrawMode = 3;
      J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufSkyOpa);
      J3DGraphBase::j3dSys.mCurDrawMode = 4;
      J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufSkyXlu);
      bVar10 = d_meter::dMenu_flag();
      if (((bVar10 == 0) && ((dPa_control_c::mStatus & 1) != 0)) &&
         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl != (dPa_control_c *)0x0)) {
        dPa_control_c::draw(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,&JStack456,5);
      }
      gx::GXSetClipMode(false);
      J3DGraphBase::j3dSys.mCurDrawMode = 3;
      J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufWorldOpa);
      dDlst_shadowControl_c::draw
                (&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mShadowControl,&pView->mViewMtx);
      dDlst_alphaModel_c::draw
                (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel0,&pView->mViewMtx);
      local_20c = (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel0)->mColor;
      drawAlphaBuffer((int)pView,&local_20c);
      if ((d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel1)->mCount != 0) {
        clearAlphaBuffer(pView,0);
        dDlst_alphaModel_c::draw
                  (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel1,&pView->mViewMtx);
        local_210 = (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel1)->mColor;
        drawAlphaBuffer((int)pView,&local_210);
      }
      if (::mDoGph_gInf_c::mMonotone == 0) {
        J3DGraphBase::j3dSys.mCurDrawMode = 3;
        J3DDrawBuffer::drawTail(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpLinkBuf);
        J3DGraphBase::j3dSys.mCurDrawMode = 3;
        J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0xc);
      }
      J3DGraphBase::j3dSys.mCurDrawMode = 3;
      J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa);
      J3DGraphBase::j3dSys.mCurDrawMode = 4;
      J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufWorldXlu);
      if ((d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel2)->mCount != 0) {
        clearAlphaBuffer(pView,((d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel2)->mColor
                               ).a);
      }
      bVar10 = d_meter::dMenu_flag();
      if (((bVar10 == 0) && ((dPa_control_c::mStatus & 1) == 0)) &&
         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl != (dPa_control_c *)0x0)) {
        dPa_control_c::draw(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,&JStack456,5);
      }
      if (::mDoGph_gInf_c::mMonotone == 0) {
        J3DGraphBase::j3dSys.mCurDrawMode = 3;
        J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x10);
      }
      J3DGraphBase::j3dSys.mCurDrawMode = 4;
      J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu);
      bVar10 = d_meter::dMenu_flag();
      if (bVar10 == 0) {
        if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl != (dPa_control_c *)0x0) {
          dPa_control_c::draw(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,&JStack456,0);
        }
        if ((::mDoGph_gInf_c::mMonotone == 0) &&
           (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl != (dPa_control_c *)0x0)) {
          dPa_control_c::draw(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,&JStack456,1);
        }
        local_1d4.mpViewMtx = (MTX34 *)&dPa_control_c::mWindViewMatrix;
        local_1d4.mFovY = pView->mFovY;
        local_1d4.mAspect = pView->mAspect;
        if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl != (dPa_control_c *)0x0) {
          dPa_control_c::draw(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,&local_1d4,6);
        }
        if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl != (dPa_control_c *)0x0) {
          dPa_control_c::draw(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,&JStack456,2);
        }
        if ((::mDoGph_gInf_c::mMonotone == 0) &&
           (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl != (dPa_control_c *)0x0)) {
          dPa_control_c::draw(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,&JStack456,3);
        }
        gx::GXSetClipMode(false);
      }
      J3DGraphBase::j3dSys.mCurDrawMode = 3;
      J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpWetherFxBuffer);
      J3DSys::reinitGX(&J3DGraphBase::j3dSys);
      gx::GXSetNumIndStages(0);
      if ((d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel2)->mCount != 0) {
        dDlst_alphaModel_c::draw
                  (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel0,&pView->mViewMtx);
        dDlst_alphaModel_c::draw
                  (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel2,&pView->mViewMtx);
        drawSpot(pView);
      }
      gx::GXSetClipMode(false);
      J3DGraphBase::j3dSys.mCurDrawMode = 3;
      J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffOpa
                         );
      J3DGraphBase::j3dSys.mCurDrawMode = 4;
      J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffXlu
                         );
      bVar10 = d_meter::dMenu_flag();
      if (bVar10 == 0) {
        motionBlure((view_class *)pView);
        drawDepth(pView,pWindow,
                  (int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar4].field_0x10);
        if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl != (dPa_control_c *)0x0) {
          dPa_control_c::draw(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,&JStack456,4);
        }
        gx::GXSetClipMode(false);
        J3DGraphBase::j3dSys.mCurDrawMode = 3;
        J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x30);
        J3DGraphBase::j3dSys.mCurDrawMode = 4;
        J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x34);
        J3DSys::reinitGX(&J3DGraphBase::j3dSys);
        this = (dPa_control_c *)0x0;
        gx::GXSetNumIndStages(0);
        if ((bVar2) &&
           (this = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,
           d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl != (dPa_control_c *)0x0)) {
          dPa_control_c::draw(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,&JStack456,0);
        }
        if (::mDoGph_gInf_c::mMonotone != 0) {
          clearAlphaBuffer(pView,0);
          J3DGraphBase::j3dSys.mCurDrawMode = 3;
          J3DDrawBuffer::drawTail(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpLinkBuf);
          J3DGraphBase::j3dSys.mCurDrawMode = 3;
          J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0xc);
          J3DGraphBase::j3dSys.mCurDrawMode = 3;
          J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x10);
          if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl != (dPa_control_c *)0x0) {
            dPa_control_c::draw(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,&JStack456,1)
            ;
          }
          this = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl;
          if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl != (dPa_control_c *)0x0) {
            dPa_control_c::draw(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,&JStack456,3)
            ;
          }
        }
        ::mDoGph_gInf_c::calcFade((mDoGph_gInf_c *)this);
        if (mCaptureStep == 1) {
          if (mCaptureCansel == '\0') {
            mDoGph_screenCapture();
          }
          else {
            mCaptureStep = 0;
          }
        }
      }
    }
  }
  if (mCaptureStep == 3) {
    if (mCaptureCansel == '\0') {
      if (mCaptureTextureFormat == '\x0e') {
        mCaptureThreadStackHead = (void *)mDoGph_allocFromAny(mCaptureThreadStackSize,0x20);
        if (mCaptureThreadStackHead == (void *)0x0) {
          mCaptureProc(0);
          if (mCaptureCaptureBuffer != (void *)0x0) {
            JKRHeap::free(mCaptureCaptureBuffer,(JKRHeap *)0x0);
            mCaptureCaptureBuffer = (void *)0x0;
          }
          mCaptureStep = 5;
        }
        else {
          os::OSCreateThread(&mCaptureThread,mCaptureProc,0,
                             (int)mCaptureThreadStackHead + mCaptureThreadStackSize,
                             mCaptureThreadStackSize,mCaptureThreadPriority,0);
          os::OSResumeThread((OSThread *)&mCaptureThread);
          mCaptureStep = mCaptureStep + 1;
        }
      }
      else {
        mCaptureCaptureBuffer = (void *)0x0;
        mCaptureStep = 5;
      }
    }
    else {
      if (mCaptureCaptureBuffer != (void *)0x0) {
        JKRHeap::free(mCaptureCaptureBuffer,(JKRHeap *)0x0);
        mCaptureCaptureBuffer = (void *)0x0;
      }
      if (mCaptureTextureBuffer != (dDlst_list_c *)0x0) {
        JKRHeap::free(mCaptureTextureBuffer,(JKRHeap *)0x0);
        mCaptureTextureBuffer = (dDlst_list_c *)0x0;
      }
      mCaptureStep = 0;
    }
  }
  if (mCaptureStep == 4) {
    if (mCaptureCansel != '\0') {
      os::OSCancelThread(&mCaptureThread);
    }
    iVar4 = os::OSIsThreadTerminated(&mCaptureThread);
    if (iVar4 == 0) {
      uVar1 = DAT_800000f8 >> 2;
      os::OSCreateAlarm(auStack344);
      os::OSInitThreadQueue(&mCaptureThreadQueue);
      os::OSSetAlarm(auStack344,0x80010000,0,(uVar1 / 1000) * 10,mCaptureAlarmHandler);
      os::OSSleepThread(&mCaptureThreadQueue);
      os::OSCancelAlarm(auStack344);
    }
    else {
      if (mCaptureCaptureBuffer != (void *)0x0) {
        JKRHeap::free(mCaptureCaptureBuffer,(JKRHeap *)0x0);
        mCaptureCaptureBuffer = (void *)0x0;
      }
      if (mCaptureThreadStackHead != (void *)0x0) {
        JKRHeap::free(mCaptureThreadStackHead,(JKRHeap *)0x0);
        mCaptureThreadStackHead = (void *)0x0;
      }
      os::OSJoinThread(&mCaptureThread,auStack516);
      mCaptureStep = mCaptureStep + 1;
    }
  }
  this_00 = (dDlst_list_c *)(int)mCaptureStep;
  if ((((((int)&this_00[-1].mPeekZ.mEntries[0x31].mpDest + 1U & 0xffff) < 2) ||
       (this_00 == (dDlst_list_c *)0x5)) && (mCaptureDraw != '\0')) && (mCaptureCansel == '\0')) {
    this_00 = (dDlst_list_c *)mDoGph_screenCaptureDraw();
  }
  if ((mCaptureStep == 5) && (mCaptureCansel != '\0')) {
    mCaptureStep = 6;
  }
  if (mCaptureStep == 6) {
    this_00 = mCaptureTextureBuffer;
    if (mCaptureTextureBuffer != (dDlst_list_c *)0x0) {
      JKRHeap::free(mCaptureTextureBuffer,(JKRHeap *)0x0);
      mCaptureTextureBuffer = (dDlst_list_c *)0x0;
    }
    mCaptureStep = 0;
    mCaptureCansel = '\0';
  }
  dDlst_list_c::calcWipe(this_00);
  J3DSys::reinitGX(&J3DGraphBase::j3dSys);
  gx::GXSetNumIndStages(0);
  local_200.mTL.x = _5162;
  local_200.mTL.y = _5160;
  local_200.mBR.x = _5163;
  local_200.mBR.y = _5161;
  ::J2DOrthoGraph::setOrtho(&JStack264,&local_200,_5857,_5858);
  ::J2DOrthoGraph::setPort(&JStack264);
  mtx::PSMTXTrans((double)_5853,(double)_5854,(double)0_0,&MStack396);
  local_1e0.mpViewMtx = &MStack396;
  local_1e0.mFovY = 0_0;
  local_1e0.mAspect = _5859;
  bVar10 = d_meter::dMenu_flag();
  if ((bVar10 == 0) &&
     (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl != (dPa_control_c *)0x0)) {
    dPa_control_c::draw(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,&local_1e0,8);
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl != (dPa_control_c *)0x0) {
    dPa_control_c::draw(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,&local_1e0,10);
  }
  if (*(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x38)->mpPacketBuf != (J3DPacket *)0x0) {
    mtx::PSMTXCopy(&J3DGraphBase::j3dSys.mCurViewMtx,&MStack444);
    setLight();
    mtx::PSMTXTrans((double)_5853,(double)_5854,(double)_5860,&mDoMtx_stack_c::now);
    m_Do_mtx::mDoMtx_ZrotM(&mDoMtx_stack_c::now,-0x8000);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,&J3DGraphBase::j3dSys.mCurViewMtx);
    J3DGraphBase::j3dSys.mCurDrawMode = 3;
    J3DDrawBuffer::draw(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x38);
    J3DSys::reinitGX(&J3DGraphBase::j3dSys);
    gx::GXSetNumIndStages(0);
    mtx::PSMTXCopy(&MStack444,&J3DGraphBase::j3dSys.mCurViewMtx);
  }
  dDlst_list_c::draw(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                     d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DArr,
                     d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa);
  dDlst_list_c::draw(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                     (dDlst_base_c **)&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x54,
                     d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x94);
  dDlst_list_c::draw(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                     (dDlst_base_c **)&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x1a4,
                     d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x224);
  bVar10 = d_meter::dMenu_flag();
  if ((bVar10 == 0) &&
     (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl != (dPa_control_c *)0x0)) {
    dPa_control_c::draw(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,&local_1e0,7);
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl != (dPa_control_c *)0x0) {
    dPa_control_c::draw(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,&local_1e0,9);
  }
  (**(code **)(*(int *)JFWDisplay::sManager + 0xc))();
  return 1;
}

}

/* __thiscall J2DOrthoGraph::~J2DOrthoGraph(void) */

void __thiscall J2DOrthoGraph::_J2DOrthoGraph(J2DOrthoGraph *this,short flag)

{
  if (this != (J2DOrthoGraph *)0x0) {
    (this->parent).vtbl = (J2DGrafContext__vtable *)&__vt;
    if (this != (J2DOrthoGraph *)0x0) {
      (this->parent).vtbl = (J2DGrafContext__vtable *)&J2DGrafContext::__vt;
    }
    if (0 < flag) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace m_Do_graphic {

/* __stdcall mDoGph_Create(void) */

undefined4 mDoGph_Create(void)

{
  JKRSolidHeap *this;
  EVP_PKEY_CTX *ctx;
  undefined1 in_r6;
  
  this = m_Do_ext::mDoExt_createSolidHeapToCurrent(0,(JKRHeap *)0x0,0,in_r6);
  ::mDoGph_gInf_c::create((mDoGph_gInf_c *)this);
  dDlst_list_c::init(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,ctx);
  m_Do_ext::mDoExt_adjustSolidHeap(this);
  m_Do_ext::mDoExt_restoreCurrentHeap();
  JFramework::JFWAutoAbortGfx = '\x02' - (mDoMain::developmentMode == '\0');
  return 1;
}


void __sinit_m_Do_graphic_cpp(void)

{
  mCaptureTimeOutTicks = 0;
  DAT_803f68ec = DAT_800000f8 >> 2;
  return;
}

