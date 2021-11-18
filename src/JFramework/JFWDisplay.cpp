#include <JFramework/JFWDisplay.h>
#include <os/OSTime.h>
#include <JFramework/JFWDisplay.h>
#include <JUtility/JUTProcBar.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTXfb.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <JUtility/JUTDirectPrint.h>
#include <gx/GXFrameBuf.h>
#include <vi/vi.h>
#include <gx/GXPixel.h>
#include <gx/GXMisc.h>
#include <JUtility/JUTVideo.h>
#include <gx/GXTexture.h>
#include <gx/GXAttr.h>
#include <J2DGraph/J2DOrthoGraph.h>
#include <JUtility/JUTFader.h>
#include <JUtility/JUTDbPrint.h>
#include <JUtility/JUTConsole.h>
#include <os/OSMessage.h>
#include <os/OSThread.h>
#include <os/OSAlarm.h>
#include <os/OSInterrupt.h>
#include <mtx/mtx44.h>
#include <gx/GXTransform.h>
#include <gx/GXLight.h>
#include <gx/GXTev.h>
#include <gx/GXGeometry.h>
#include <m_Do_printf.h>
#include <gx/GXPerf.h>
#include <gx/GXFifo.h>
#include <JFWDisplay.h>


namespace JFramework {
}

namespace JFramework {
undefined clear_z_tobj;
}
struct JFWDisplay * JFWDisplay;

namespace JFramework {
undefined4 prevFrame$2524;
undefined1 init$2525;
undefined4 nextTick$2569;
undefined1 init$2570;
undefined4 nextCount$2577;
undefined1 init$2578;
}

/* __thiscall JFWDisplay::ctor_subroutine(_GXRenderModeObj const *,
                                          bool) */

void __thiscall JFWDisplay::ctor_subroutine(JFWDisplay *this,_GXRenderModeObj *param_1,bool param_2)

{
  undefined4 uVar1;
  JUTProcBar *pJVar2;
  
  this->field_0x28 = param_2;
  *(undefined2 *)&this->field_0x2a = 3;
  (this->mClearColor).r = 0;
  (this->mClearColor).g = 0;
  (this->mClearColor).b = 0;
  (this->mClearColor).a = 0;
  *(undefined4 *)&this->field_0x10 = 0xffffff;
  if (param_1 == (_GXRenderModeObj *)0x0) {
    param_1 = JUTVideo::sManager->mpRenderMode;
  }
  *(_GXRenderModeObj **)&this->field_0x8 = param_1;
  *(undefined2 *)&this->field_0x18 = 0;
  this->mpFader = (JUTFader *)0x0;
  *(undefined2 *)&this->field_0x20 = 1;
  *(undefined4 *)&this->field_0x24 = 0;
  *(float *)&this->field_0x2c = JFramework::_2164;
  *(undefined4 *)&this->field_0x34 = 0;
  uVar1 = os::OSGetTick();
  *(undefined4 *)&this->field_0x30 = uVar1;
  *(undefined4 *)&this->field_0x38 = 0;
  *(undefined2 *)&this->field_0x3c = 0;
  *(undefined *)&this->field_0x3e = 0;
  *(undefined4 *)&this->field_0x1c = 0;
  pJVar2 = (JUTProcBar *)clearEfb_init(this);
  pJVar2 = (JUTProcBar *)JUTProcBar::create(pJVar2);
  JUTProcBar::clear(pJVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JFWDisplay::JFWDisplay(_GXRenderModeObj const *,
                                     JKRHeap *,
                                     JUTXfb::EXfbNumber,
                                     bool) */

void __thiscall
JFWDisplay::JFWDisplay
          (JFWDisplay *this,_GXRenderModeObj *param_1,JKRHeap *param_2,EXfbNumber param_3,
          bool param_4)

{
  undefined4 uVar1;
  EXfbNumber EVar2;
  
  *(undefined1 **)this = &__vt;
  this->mClearColor = (_GXColor)0xffffffff;
  EVar2 = param_3;
  ctor_subroutine(this,param_1,param_4);
  uVar1 = JUTXfb::createManager
                    ((JUTXfb *)param_1,(_GXRenderModeObj *)param_2,(JKRHeap *)param_3,EVar2);
  *(undefined4 *)&this->field_0x14 = uVar1;
  return;
}


/* __thiscall JFWDisplay::~JFWDisplay(void) */

void __thiscall JFWDisplay::_JFWDisplay(JFWDisplay *this)

{
  JUTProcBar *this_00;
  JUTXfb *this_01;
  short in_r4;
  
  if (this != (JFWDisplay *)0x0) {
    *(undefined1 **)this = &__vt;
    this_00 = (JUTProcBar *)waitBlanking(this,2);
    this_01 = (JUTXfb *)JUTProcBar::destroy(this_00);
    JUTXfb::destroyManager(this_01);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JFWDisplay::createManager(JKRHeap *,
                                        JUTXfb::EXfbNumber,
                                        bool) */

JFWDisplay * __thiscall
JFWDisplay::createManager(JFWDisplay *this,JKRHeap *param_1,EXfbNumber param_2,bool param_3)

{
  uint uVar1;
  JUTAssertion *this_00;
  JFWDisplay *this_01;
  char *in_r8;
  
  this_00 = (JUTAssertion *)JUTAssertion::getSDevice();
  uVar1 = countLeadingZeros(sManager);
  JUTAssertion::setConfirmMessage
            (this_00,(ulong)"JFWDisplay.cpp",(char *)0xf3,uVar1 >> 5,true,in_r8);
  this_01 = sManager;
  if ((sManager == (JFWDisplay *)0x0) &&
     (this_01 = (JFWDisplay *)JKernel::operator_new(0x40), this_01 != (JFWDisplay *)0x0)) {
    JFWDisplay(this_01,(_GXRenderModeObj *)0x0,(JKRHeap *)this,(EXfbNumber)param_1,SUB41(param_2,0))
    ;
  }
  sManager = this_01;
  return sManager;
}


namespace JFramework {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall callDirectDraw(void) */

void callDirectDraw(void)

{
  JUTAssertion *this;
  void *pvVar1;
  
  if (*(short *)(JUTXfb::sManager + 0x14) < 0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = *(void **)(JUTXfb::sManager + *(short *)(JUTXfb::sManager + 0x14) * 4);
  }
  this = (JUTAssertion *)
         JUTDirectPrint::changeFrameBuffer
                   (_sDirectPrint,pvVar1,JUTVideo::sManager->mpRenderMode->field_0x4,
                    JUTVideo::sManager->mpRenderMode->field_0x6);
  JUTAssertion::flushMessage(this);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JFWDisplay::prepareCopyDisp(void) */

void __thiscall JFWDisplay::prepareCopyDisp(JFWDisplay *this)

{
  short sVar1;
  short sVar2;
  short sVar3;
  _GXRenderModeObj *p_Var4;
  undefined8 uVar5;
  _GXColor local_28 [3];
  
  p_Var4 = JUTVideo::sManager->mpRenderMode;
  sVar1 = p_Var4->field_0x4;
  sVar2 = p_Var4->field_0x6;
  sVar3 = p_Var4->field_0x8;
  uVar5 = gx::GXGetYScaleFactor();
  local_28[0] = this->mClearColor;
  gx::GXSetCopyClear(local_28,*(undefined4 *)&this->field_0x10);
  gx::GXSetDispCopySrc(0,0,sVar1,sVar2);
  gx::GXSetDispCopyDst(sVar1,sVar3);
  gx::GXSetDispCopyYScale(uVar5);
  vi::VIFlush();
  gx::GXSetCopyFilter(*(undefined *)((int)&p_Var4[2].field_0x0 + 1),(int)&p_Var4[2].field_0x0 + 2,1,
                      (int)&p_Var4[4].field_0x0 + 2);
  gx::GXSetCopyClamp(*(undefined2 *)&this->field_0x2a);
  gx::GXSetDispCopyGamma(*(undefined2 *)&this->field_0x18);
  gx::GXSetZMode(true,GX_LEQUAL,true);
  if (this->field_0x28 != 0) {
    gx::GXSetAlphaUpdate(1);
  }
  return;
}


/* __thiscall JFWDisplay::drawendXfb_single(void) */

void __thiscall JFWDisplay::drawendXfb_single(JFWDisplay *this)

{
  JUTXfb *pJVar1;
  
  pJVar1 = JUTXfb::sManager;
  if (-1 < *(short *)(JUTXfb::sManager + 0x14)) {
    prepareCopyDisp(this);
    JFramework::JFWGXDrawDoneAutoAbort();
    gx::GXFlush();
    *(undefined2 *)(pJVar1 + 0x16) = *(undefined2 *)(pJVar1 + 0x14);
  }
  return;
}


/* __thiscall JFWDisplay::exchangeXfb_double(void) */

void __thiscall JFWDisplay::exchangeXfb_double(JFWDisplay *this)

{
  ushort uVar1;
  JUTXfb *pJVar2;
  undefined4 uVar3;
  JUTVideo *pJVar4;
  _GXColor local_18 [4];
  
  pJVar2 = JUTXfb::sManager;
  if (*(short *)(JUTXfb::sManager + 0x16) == *(short *)(JUTXfb::sManager + 0x18)) {
    if (-1 < *(short *)(JUTXfb::sManager + 0x14)) {
      prepareCopyDisp(this);
      if (*(short *)(pJVar2 + 0x14) < 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined4 *)(pJVar2 + *(short *)(pJVar2 + 0x14) * 4);
      }
      pJVar4 = (JUTVideo *)gx::GXCopyDisp(uVar3,1);
      if (*(int *)&this->field_0x1c == 0) {
        pJVar4 = (JUTVideo *)gx::GXDrawDone();
        JUTVideo::dummyNoDrawWait(pJVar4);
      }
      else {
        JUTVideo::drawDoneStart(pJVar4);
      }
      if (*(int *)&this->field_0x1c == 0) {
        JFramework::callDirectDraw();
      }
    }
    uVar1 = *(ushort *)(pJVar2 + 0x14);
    *(ushort *)(pJVar2 + 0x16) = uVar1;
    *(ushort *)(pJVar2 + 0x14) = (uVar1 ^ 1) & -((short)uVar1 >> 0xf) - 1U;
  }
  else {
    local_18[0] = this->mClearColor;
    clearEfb(this,local_18);
    if (*(short *)(pJVar2 + 0x14) < 0) {
      *(undefined2 *)(pJVar2 + 0x14) = 0;
    }
  }
  return;
}


/* __thiscall JFWDisplay::exchangeXfb_triple(void) */

void __thiscall JFWDisplay::exchangeXfb_triple(JFWDisplay *this)

{
  JUTXfb *pJVar1;
  short sVar2;
  
  pJVar1 = JUTXfb::sManager;
  if (-1 < *(short *)(JUTXfb::sManager + 0x14)) {
    JFramework::callDirectDraw();
  }
  *(undefined2 *)(pJVar1 + 0x16) = *(undefined2 *)(pJVar1 + 0x14);
  sVar2 = *(short *)(pJVar1 + 0x14) + 1;
  do {
    if ((2 < sVar2) || (sVar2 < 0)) {
      sVar2 = 0;
    }
  } while (sVar2 == *(short *)(pJVar1 + 0x18));
  *(short *)(pJVar1 + 0x14) = sVar2;
  return;
}


/* __thiscall JFWDisplay::copyXfb_triple(void) */

void __thiscall JFWDisplay::copyXfb_triple(JFWDisplay *this)

{
  short sVar1;
  JUTXfb *pJVar2;
  undefined4 uVar3;
  
  pJVar2 = JUTXfb::sManager;
  if (-1 < *(short *)(JUTXfb::sManager + 0x14)) {
    prepareCopyDisp(this);
    sVar1 = *(short *)(pJVar2 + 0x14);
    if (sVar1 < 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined4 *)(pJVar2 + sVar1 * 4);
    }
    gx::GXCopyDisp(uVar3,1);
    gx::GXPixModeSync();
  }
  return;
}


/* __thiscall JFWDisplay::preGX(void) */

void __thiscall JFWDisplay::preGX(JFWDisplay *this)

{
  gx::GXInvalidateTexAll();
  gx::GXInvalidateVtxCache();
  if (*(char *)(*(int *)&this->field_0x8 + 0x19) == '\0') {
    if (this->field_0x28 == 0) {
      gx::GXSetPixelFmt(0,0);
      gx::GXSetDither(0);
    }
    else {
      gx::GXSetPixelFmt(1,0);
      gx::GXSetDither(1);
    }
  }
  else {
    gx::GXSetPixelFmt(2,0);
    gx::GXSetDither(1);
  }
  return;
}


/* __thiscall JFWDisplay::endGX(void) */

void __thiscall JFWDisplay::endGX(JFWDisplay *this)

{
  JUTProcBar *this_00;
  J2DOrthoGraph local_f8;
  undefined4 local_20;
  uint uStack28;
  undefined4 local_18;
  uint uStack20;
  
  uStack28 = (uint)(ushort)JUTVideo::sManager->mpRenderMode->field_0x4;
  local_20 = 0x43300000;
  uStack20 = (uint)(ushort)JUTVideo::sManager->mpRenderMode->field_0x6;
  local_18 = 0x43300000;
  J2DOrthoGraph::J2DOrthoGraph
            (&local_f8,JFramework::_2164,JFramework::_2164,
             (float)((double)CONCAT44(0x43300000,uStack28) - JFramework::_2446),
             (float)((double)CONCAT44(0x43300000,uStack20) - JFramework::_2446),JFramework::_2443,
             JFramework::_2444);
  if (this->mpFader != (JUTFader *)0x0) {
    J2DOrthoGraph::setPort(&local_f8);
    JUTFader::control(this->mpFader);
  }
  J2DOrthoGraph::setPort(&local_f8);
  JUTDbPrint::flush(JUTDbPrint::sDebugPrint);
  if (JUTConsoleManager::sManager != (JUTConsoleManager *)0x0) {
    J2DOrthoGraph::setPort(&local_f8);
    JUTConsoleManager::draw(JUTConsoleManager::sManager);
  }
  J2DOrthoGraph::setPort(&local_f8);
  this_00 = JUTProcBar::sManager;
  JUTProcBar::draw(JUTProcBar::sManager);
  if ((*(int *)&this->field_0x1c != 0) ||
     (this_00 = (JUTProcBar *)JUTXfb::sManager, *(int *)(JUTXfb::sManager + 0x10) == 1)) {
    JUTAssertion::flushMessage_dbPrint((JUTAssertion *)this_00);
  }
  gx::GXFlush();
  return;
}


/* __thiscall JFWDisplay::beginRender(void) */

void __thiscall JFWDisplay::beginRender(JFWDisplay *this)

{
  JUTXfb *pJVar1;
  JUTProcBar *pJVar2;
  int iVar3;
  undefined4 uVar4;
  _GXColor local_18 [4];
  
  pJVar2 = JUTProcBar::sManager;
  iVar3 = os::OSGetTick();
  *(uint *)&pJVar2->field_0x54 =
       (uint)((iVar3 - *(int *)&pJVar2->field_0x50) * 8) / ((DAT_800000f8 >> 2) / 0x1e848);
  if (*(int *)&pJVar2->field_0x54 == 0) {
    *(undefined4 *)&pJVar2->field_0x54 = 1;
  }
  pJVar2 = JUTProcBar::sManager;
  *(undefined *)&JUTProcBar::sManager->field_0x60 = 0xff;
  *(undefined *)&pJVar2->field_0x61 = 0x81;
  *(undefined *)&pJVar2->field_0x62 = 0x1e;
  uVar4 = os::OSGetTick();
  *(undefined4 *)&pJVar2->field_0x50 = uVar4;
  pJVar2 = JUTProcBar::sManager;
  *(undefined *)&JUTProcBar::sManager->field_0x10 = 0xff;
  *(undefined *)&pJVar2->field_0x11 = 0x81;
  *(undefined *)&pJVar2->field_0x12 = 0x1e;
  uVar4 = os::OSGetTick();
  *(undefined4 *)pJVar2 = uVar4;
  JFramework::waitForTick(*(undefined4 *)&this->field_0x24,*(undefined2 *)&this->field_0x20);
  JUTVideo::waitRetraceIfNeed(JUTVideo::sManager);
  iVar3 = os::OSGetTick();
  *(int *)&this->field_0x34 = iVar3 - *(int *)&this->field_0x30;
  *(int *)&this->field_0x30 = iVar3;
  *(int *)&this->field_0x38 = *(int *)&this->field_0x30 - JUTVideo::sVideoLastTick;
  pJVar2 = JUTProcBar::sManager;
  iVar3 = os::OSGetTick();
  *(uint *)&pJVar2->field_0x4 =
       (uint)((iVar3 - *(int *)pJVar2) * 8) / ((DAT_800000f8 >> 2) / 0x1e848);
  if (*(int *)&pJVar2->field_0x4 == 0) {
    *(undefined4 *)&pJVar2->field_0x4 = 1;
  }
  pJVar2 = JUTProcBar::sManager;
  *(undefined *)&JUTProcBar::sManager->field_0x24 = 0xff;
  *(undefined *)&pJVar2->field_0x25 = 0x81;
  *(undefined *)&pJVar2->field_0x26 = 0x1e;
  uVar4 = os::OSGetTick();
  *(undefined4 *)&pJVar2->field_0x14 = uVar4;
  pJVar1 = JUTXfb::sManager;
  iVar3 = *(int *)(JUTXfb::sManager + 0x10);
  if (iVar3 == 2) {
    exchangeXfb_double(this);
  }
  else {
    if (iVar3 < 2) {
      if (0 < iVar3) {
        if (*(int *)(JUTXfb::sManager + 0x1c) == 2) {
          *(undefined4 *)(JUTXfb::sManager + 0x1c) = 1;
        }
        else {
          *(undefined4 *)(JUTXfb::sManager + 0x1c) = 1;
          local_18[0] = this->mClearColor;
          clearEfb(this,local_18);
        }
        *(undefined2 *)(pJVar1 + 0x14) = *(undefined2 *)&this->field_0x3c;
      }
    }
    else {
      if (iVar3 < 4) {
        exchangeXfb_triple(this);
      }
    }
  }
  preGX(this);
  return;
}


/* __thiscall JFWDisplay::endRender(void) */

void __thiscall JFWDisplay::endRender(JFWDisplay *this)

{
  JUTProcBar *pJVar1;
  int iVar2;
  undefined4 uVar3;
  
  endGX(this);
  iVar2 = *(int *)(JUTXfb::sManager + 0x10);
  if (iVar2 != 2) {
    if (iVar2 < 2) {
      if (0 < iVar2) {
        drawendXfb_single(this);
      }
    }
    else {
      if (iVar2 < 4) {
        copyXfb_triple(this);
      }
    }
  }
  pJVar1 = JUTProcBar::sManager;
  *(undefined *)&JUTProcBar::sManager->field_0x38 = 0xff;
  *(undefined *)&pJVar1->field_0x39 = 0x81;
  *(undefined *)&pJVar1->field_0x3a = 0x1e;
  uVar3 = os::OSGetTick();
  *(undefined4 *)&pJVar1->field_0x28 = uVar3;
  calcCombinationRatio(this);
  return;
}


/* __thiscall JFWDisplay::endFrame(void) */

void __thiscall JFWDisplay::endFrame(JFWDisplay *this)

{
  JUTProcBar *pJVar1;
  int iVar2;
  undefined4 uVar3;
  
  pJVar1 = JUTProcBar::sManager;
  iVar2 = os::OSGetTick();
  *(uint *)&pJVar1->field_0x2c =
       (uint)((iVar2 - *(int *)&pJVar1->field_0x28) * 8) / ((DAT_800000f8 >> 2) / 0x1e848);
  if (*(int *)&pJVar1->field_0x2c == 0) {
    *(undefined4 *)&pJVar1->field_0x2c = 1;
  }
  pJVar1 = JUTProcBar::sManager;
  *(undefined *)&JUTProcBar::sManager->field_0x4c = 0xff;
  *(undefined *)&pJVar1->field_0x4d = 0x81;
  *(undefined *)&pJVar1->field_0x4e = 0x1e;
  uVar3 = os::OSGetTick();
  *(undefined4 *)&pJVar1->field_0x3c = uVar3;
  iVar2 = *(int *)(JUTXfb::sManager + 0x10);
  if (iVar2 == 2) {
    JFramework::JFWGXDrawDoneAutoAbort();
    gx::GXFlush();
  }
  else {
    if ((1 < iVar2) && (iVar2 < 4)) {
      JFramework::JFWGXDrawDoneAutoAbort();
      gx::GXFlush();
    }
  }
  pJVar1 = JUTProcBar::sManager;
  iVar2 = os::OSGetTick();
  *(uint *)&pJVar1->field_0x40 =
       (uint)((iVar2 - *(int *)&pJVar1->field_0x3c) * 8) / ((DAT_800000f8 >> 2) / 0x1e848);
  if (*(int *)&pJVar1->field_0x40 == 0) {
    *(undefined4 *)&pJVar1->field_0x40 = 1;
  }
  pJVar1 = JUTProcBar::sManager;
  iVar2 = os::OSGetTick();
  *(uint *)&pJVar1->field_0x18 =
       (uint)((iVar2 - *(int *)&pJVar1->field_0x14) * 8) / ((DAT_800000f8 >> 2) / 0x1e848);
  if (*(int *)&pJVar1->field_0x18 == 0) {
    *(undefined4 *)&pJVar1->field_0x18 = 1;
  }
  if (JFramework::init_2525 == '\0') {
    JFramework::prevFrame_2524 = vi::VIGetRetraceCount();
    JFramework::init_2525 = '\x01';
  }
  iVar2 = vi::VIGetRetraceCount();
  *(int *)&JUTProcBar::sManager->field_0x104 = iVar2 - JFramework::prevFrame_2524;
  JFramework::prevFrame_2524 = iVar2;
  return;
}


/* __thiscall JFWDisplay::waitBlanking(int) */

void __thiscall JFWDisplay::waitBlanking(JFWDisplay *this,int param_1)

{
  bool bVar1;
  
  while (bVar1 = 0 < param_1, param_1 = param_1 + -1, bVar1) {
    JFramework::waitForTick(*(undefined4 *)&this->field_0x24,*(undefined2 *)&this->field_0x20);
  }
  return;
}


namespace JFramework {

/* __stdcall waitForTick(unsigned long,
                         unsigned short) */

void waitForTick(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint extraout_r4;
  int local_18 [4];
  
  if (param_1 == 0) {
    if (init_2578 == '\0') {
      nextCount_2577 = vi::VIGetRetraceCount();
      init_2578 = '\x01';
    }
    uVar1 = 1;
    if ((param_2 & 0xffff) != 0) {
      uVar1 = param_2 & 0xffff;
    }
    do {
      iVar2 = os::OSReceiveMessage(&JUTVideo::sManager->mMesgQ,local_18,1);
      if (iVar2 == 0) {
        local_18[0] = 0;
      }
    } while (local_18[0] - nextCount_2577 < 0);
    nextCount_2577 = local_18[0] + uVar1;
  }
  else {
    if (init_2570 == '\0') {
      nextTick_2569 = os::OSGetTime();
      init_2570 = '\x01';
      DAT_803f73a4 = param_2;
    }
    uVar1 = os::OSGetTime();
    while ((uVar1 ^ 0x80000000) < (uint)(param_2 < DAT_803f73a4) + (nextTick_2569 ^ 0x80000000)) {
      ::JFWDisplay::threadSleep(::JFWDisplay::sManager,param_2);
      param_2 = extraout_r4;
      uVar1 = os::OSGetTime();
    }
    DAT_803f73a4 = param_2 + param_1;
    nextTick_2569 = uVar1 + CARRY4(param_2,param_1);
  }
  return;
}


/* __stdcall JFWThreadAlarmHandler(OSAlarm *,
                                   OSContext *) */

void JFWThreadAlarmHandler(int param_1)

{
  os::OSResumeThread(*(OSThread **)(param_1 + 0x28));
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JFWDisplay::threadSleep(long long) */

void __thiscall JFWDisplay::threadSleep(JFWDisplay *this,long_long param_1)

{
  undefined4 uVar1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined auStack72 [40];
  undefined4 local_20;
  
  os::OSCreateAlarm(auStack72);
  local_20 = os::OSGetCurrentThread();
  uVar1 = os::OSDisableInterrupts();
  os::OSSetAlarm(auStack72,0x80250000,in_r5,in_r6,JFramework::JFWThreadAlarmHandler);
  os::OSSuspendThread(local_20);
  os::OSRestoreInterrupts(uVar1);
  return;
}


/* __thiscall JFWDisplay::clearEfb_init(void) */

void __thiscall JFWDisplay::clearEfb_init(JFWDisplay *this)

{
  double dVar1;
  
  gx::GXInitTexObj((GXTexObj *)&JFramework::clear_z_tobj,&JFramework::clear_z_TX,4,4,GX_CTF_B8,
                   GX_REPEAT,GX_REPEAT,false);
  dVar1 = (double)JFramework::_2164;
  gx::GXInitTexObjLOD(dVar1,dVar1,dVar1,&JFramework::clear_z_tobj,0,0,0,0,0);
  return;
}


/* __thiscall JFWDisplay::clearEfb(_GXColor) */

void __thiscall JFWDisplay::clearEfb(JFWDisplay *this,_GXColor *param_1)

{
  _GXColor local_8 [2];
  
  local_8[0] = *param_1;
  clearEfb(this,0,0,(uint)*(ushort *)(*(int *)&this->field_0x8 + 4),
           (uint)*(ushort *)(*(int *)&this->field_0x8 + 6),local_8);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall JFWDisplay::clearEfb(int,
                                   int,
                                   int,
                                   int,
                                   _GXColor) */

void __thiscall
JFWDisplay::clearEfb
          (JFWDisplay *this,int param_1,int param_2,int param_3,int param_4,_GXColor *param_5)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  double dVar6;
  _GXColor local_88;
  MTX44 MStack132;
  undefined4 local_40;
  uint uStack60;
  undefined4 local_38;
  uint uStack52;
  undefined4 local_30;
  uint uStack44;
  undefined4 local_28;
  uint uStack36;
  
  uVar1 = *(ushort *)(*(int *)&this->field_0x8 + 6);
  uStack60 = (uint)uVar1;
  uVar2 = *(ushort *)(*(int *)&this->field_0x8 + 4);
  uStack52 = (uint)uVar2;
  local_40 = 0x43300000;
  local_38 = 0x43300000;
  mtx::C_MTXOrtho(JFramework::_2164,
                  (float)((double)CONCAT44(0x43300000,uStack60) - JFramework::_2446),
                  JFramework::_2164,
                  (float)((double)CONCAT44(0x43300000,uStack52) - JFramework::_2446),
                  JFramework::_2164,JFramework::_2444,&MStack132);
  gx::GXSetProjection(&MStack132,GX_ORTHOGRAPHIC);
  dVar6 = (double)JFramework::_2164;
  uStack44 = (uint)uVar2;
  local_30 = 0x43300000;
  uStack36 = (uint)uVar1;
  local_28 = 0x43300000;
  gx::GXSetViewport(dVar6,dVar6,
                    (double)(float)((double)CONCAT44(0x43300000,uStack44) - JFramework::_2446),
                    (double)(float)((double)CONCAT44(0x43300000,uStack36) - JFramework::_2446),dVar6
                    ,(double)JFramework::_2444);
  gx::GXSetScissor(0,0,uVar2,uVar1);
  gx::GXLoadPosMtxImm((MTX34 *)&JFramework::e_mtx,0);
  gx::GXSetCurrentMtx(0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGB,GX_RGBX8,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGB565,0);
  gx::GXSetNumChans(0);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXSetChanCtrl(GX_COLOR1A1,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXSetNumTexGens(1);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXLoadTexObj((GXTexObj *)&JFramework::clear_z_tobj,0);
  gx::GXSetNumTevStages(1);
  local_88 = *param_5;
  gx::GXSetTevColor(GX_TEVREG0,&local_88);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_C0);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A0);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
  gx::GXSetZTexture(2,0x16,0);
  gx::GXSetZCompLoc(0);
  gx::GXSetBlendMode(GX_BM_NONE,GX_BL_ZERO,GX_BL_ZERO,GX_LO_NOOP);
  if (this->field_0x28 != 0) {
    gx::GXSetAlphaUpdate(1);
    gx::GXSetDstAlpha(1,0);
  }
  gx::GXSetZMode(true,GX_ALWAYS,true);
  gx::GXSetCullMode(2);
  gx::GXBegin(0x80,0,4);
  sVar5 = (short)param_1;
  write_volatile_2(0xcc008000,sVar5);
  sVar4 = (short)param_2;
  write_volatile_2(0xcc008000,sVar4);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0);
  sVar3 = sVar5 + (short)param_3;
  write_volatile_2(0xcc008000,sVar3);
  write_volatile_2(0xcc008000,sVar4);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_2(0xcc008000,sVar3);
  sVar4 = sVar4 + (short)param_4;
  write_volatile_2(0xcc008000,sVar4);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_2(0xcc008000,sVar5);
  write_volatile_2(0xcc008000,sVar4);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,1);
  gx::GXSetZTexture(0,0x16,0);
  gx::GXSetZCompLoc(1);
  if (this->field_0x28 != 0) {
    gx::GXSetDstAlpha(0,0);
  }
  return;
}


/* __thiscall JFWDisplay::calcCombinationRatio(void) */

void __thiscall JFWDisplay::calcCombinationRatio(JFWDisplay *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)&this->field_0x34;
  for (iVar3 = JUTVideo::sVideoInterval; iVar3 < iVar2 * 2; iVar3 = iVar3 + JUTVideo::sVideoInterval
      ) {
  }
  uVar1 = (iVar3 + iVar2 * -2) - *(int *)&this->field_0x38;
  if ((int)uVar1 < 0) {
    uVar1 = uVar1 + JUTVideo::sVideoInterval;
  }
  *(float *)&this->field_0x2c =
       (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - JFramework::_2801) /
       (float)((double)CONCAT44(0x43300000,iVar2) - JFramework::_2446);
  if (JFramework::_2444 < *(float *)&this->field_0x2c) {
    *(float *)&this->field_0x2c = JFramework::_2444;
  }
  return;
}


namespace JFramework {

/* __stdcall JFWGXDrawDoneAutoAbort(void) */

void JFWGXDrawDoneAutoAbort(void)

{
  undefined auStack40 [40];
  
  if (JFWAutoAbortGfx == '\0') {
    gx::GXDrawDone();
  }
  else {
    os::OSCreateAlarm(auStack40);
    os::OSSetAlarm(auStack40,0x80250000,0,DAT_800000f8 >> 2,JFWGXAbortAlarmHandler);
    gx::GXDrawDone();
    os::OSCancelAlarm(auStack40);
  }
  return;
}


/* __stdcall JFWGXAbortAlarmHandler(OSAlarm *,
                                    OSContext *) */

void JFWGXAbortAlarmHandler(void)

{
  ulong uVar1;
  ___ in_r7;
  
  diagnoseGpHang();
  if (JFWAutoAbortGfx == '\x01') {
    m_Do_printf::OSReport("GXAbortFrame() を呼び出し、復帰します\n");
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f(uVar1,"JFWDisplay.cpp",0x54b,"GP FREEZE! AUTO RESUME",in_r7);
    gx::GXAbortFrame();
    gx::GXSetDrawDone();
  }
  else {
    m_Do_printf::OSReport("自動復帰しません\n");
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f(uVar1,"JFWDisplay.cpp",0x546,"GP FREEZE!",in_r7);
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JFWDisplay.cpp",0x547,"0");
    m_Do_printf::OSPanic("JFWDisplay.cpp",0x547,&DAT_8036637e);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall diagnoseGpHang(void) */

void diagnoseGpHang(void)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  undefined uStack56;
  char local_37;
  char local_36 [2];
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18 [2];
  
  gx::GXReadXfRasMetric(&local_1c,local_18,&local_24,&local_20);
  gx::GXReadXfRasMetric(&local_2c,&local_28,&local_34,&local_30);
  uVar1 = countLeadingZeros(local_28 - local_18[0]);
  uVar2 = uVar1 >> 5 & 0xff;
  uVar1 = countLeadingZeros(local_2c - local_1c);
  uVar1 = uVar1 >> 5 & 0xff;
  bVar3 = local_30 != local_20;
  gx::GXGetGPStatus(&uStack56,&uStack56,local_36,&local_37,&uStack56);
  m_Do_printf::OSReport
            ("GP status %d%d%d%d%d%d --> ",local_36[0],local_37,uVar2,uVar1,bVar3,
             local_34 != local_24);
  if ((uVar1 == 0) && (bVar3)) {
    m_Do_printf::OSReport("GP hang due to XF stall bug.\n");
  }
  else {
    if ((uVar2 == 0) && ((uVar1 != 0 && (bVar3)))) {
      m_Do_printf::OSReport("GP hang due to unterminated primitive.\n");
    }
    else {
      if ((local_37 == '\0') && (((uVar2 != 0 && (uVar1 != 0)) && (bVar3)))) {
        m_Do_printf::OSReport("GP hang due to illegal instruction.\n");
      }
      else {
        if ((((local_36[0] == '\0') || (local_37 == '\0')) ||
            ((uVar2 == 0 || ((uVar1 == 0 || (!bVar3)))))) || (local_34 == local_24)) {
          m_Do_printf::OSReport("GP is in unknown state.\n");
        }
        else {
          m_Do_printf::OSReport("GP appears to be not hung (waiting for input).\n");
        }
      }
    }
  }
  return;
}

