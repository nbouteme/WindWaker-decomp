#include <JUtility/JUTVideo.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTVideo.h>
#include <vi/vi.h>
#include <os/OSTime.h>
#include <os/OSMessage.h>
#include <gx/GXMisc.h>
#include <JUtility/JUTDirectPrint.h>
#include <gx/GXFrameBuf.h>
#include <JUTVideo.h>

struct JUTVideo * JUTVideo;
int JUTVideo;
int JUTVideo;

namespace JUtility {
undefined1 sDrawWaiting;
undefined4 frameBuffer$2182;
undefined1 init$2183;
}

/* __thiscall JUTVideo::createManager(_GXRenderModeObj const *) */

JUTVideo * __thiscall JUTVideo::createManager(JUTVideo *this,_GXRenderModeObj *param_1)

{
  JUTVideo *this_00;
  
  this_00 = sManager;
  if ((sManager == (JUTVideo *)0x0) &&
     (this_00 = (JUTVideo *)JKernel::operator_new(0x58), this_00 != (JUTVideo *)0x0)) {
    JUTVideo(this_00,(_GXRenderModeObj *)this);
  }
  sManager = this_00;
  return sManager;
}


/* __thiscall JUTVideo::destroyManager(void) */

void __thiscall JUTVideo::destroyManager(JUTVideo *this)

{
  if (sManager != (JUTVideo *)0x0) {
    if (sManager != (JUTVideo *)0x0) {
      (**(code **)(sManager->vtbl + 8))(sManager,1);
    }
    sManager = (JUTVideo *)0x0;
  }
  return;
}


/* __thiscall JUTVideo::JUTVideo(_GXRenderModeObj const *) */

void __thiscall JUTVideo::JUTVideo(JUTVideo *this,_GXRenderModeObj *param_1)

{
  int iVar1;
  undefined *puVar2;
  
  this->vtbl = &__vt;
  this->mpRenderMode = (_GXRenderModeObj *)0x0;
  vi::VIInit();
  setRenderMode(this,param_1);
  this->field_0x2c = 1;
  this->field_0x30 = 2;
  vi::VISetBlack(1);
  vi::VIFlush();
  *(undefined4 *)&this->field_0x8 = 0;
  iVar1 = vi::VIGetRetraceCount();
  this->mRetraceCount = iVar1;
  *(undefined4 *)&this->field_0x10 = 1;
  *(undefined4 *)&this->field_0x18 = 0;
  sVideoLastTick = os::OSGetTick();
  sVideoInterval = 670000;
  puVar2 = (undefined *)vi::VISetPreRetraceCallback(preRetraceProc);
  this->mpOldPreRetraceProc = puVar2;
  puVar2 = (undefined *)vi::VISetPostRetraceCallback(postRetraceProc);
  this->mpOldPostRetraceProc = puVar2;
  *(undefined4 *)&this->field_0x24 = 0;
  *(undefined4 *)&this->field_0x28 = 0;
  os::OSInitMessageQueue(&this->mMesgQ,&this->mMesg,1);
  gx::GXSetDrawDoneCallback(drawDoneCallback);
  return;
}


/* __thiscall JUTVideo::~JUTVideo(void) */

void __thiscall JUTVideo::_JUTVideo(JUTVideo *this)

{
  short in_r4;
  
  if (this != (JUTVideo *)0x0) {
    this->vtbl = &__vt;
    vi::VISetPreRetraceCallback(this->mpOldPreRetraceProc);
    vi::VISetPostRetraceCallback(this->mpOldPostRetraceProc);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTVideo::preRetraceProc(unsigned long) */

void __thiscall JUTVideo::preRetraceProc(JUTVideo *this,ulong param_1)

{
  JUTXfb *pJVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(code **)&sManager->field_0x24 != (code *)0x0) {
    this = (JUTVideo *)(**(code **)&sManager->field_0x24)();
  }
  iVar2 = os::OSGetTick(this);
  pJVar1 = JUTXfb::sManager;
  sVideoInterval = iVar2 - sVideoLastTick;
  sVideoLastTick = iVar2;
  if (JUTXfb::sManager == (JUTXfb *)0x0) {
    vi::VISetBlack(1);
    vi::VIFlush();
  }
  else {
    if (JUtility::init_2183 == '\0') {
      JUtility::frameBuffer_2182 = (void *)0x0;
      JUtility::init_2183 = '\x01';
    }
    if (JUtility::frameBuffer_2182 != (void *)0x0) {
      JUTDirectPrint::changeFrameBuffer
                (_sDirectPrint,JUtility::frameBuffer_2182,sManager->mpRenderMode->field_0x4,
                 sManager->mpRenderMode->field_0x6);
    }
    if (sManager->field_0x2c == 1) {
      iVar2 = sManager->field_0x30;
      if (0 < iVar2) {
        iVar2 = iVar2 + -1;
      }
      sManager->field_0x30 = iVar2;
      sManager->field_0x2c = 1 - (iVar2 == 0);
      vi::VISetBlack(1);
      vi::VIFlush();
    }
    else {
      if (pJVar1 == (JUTXfb *)0x0) {
        vi::VISetBlack(1);
        vi::VIFlush();
      }
      else {
        iVar2 = *(int *)(pJVar1 + 0x10);
        if ((iVar2 == 3) || (iVar2 == 2)) {
          if (JUtility::sDrawWaiting == '\0') {
            *(short *)(pJVar1 + 0x18) = *(short *)(pJVar1 + 0x16);
            if (*(short *)(pJVar1 + 0x16) < 0) {
              vi::VISetBlack(1);
              vi::VIFlush();
            }
            else {
              vi::VISetBlack(0);
              if (*(short *)(pJVar1 + 0x18) < 0) {
                uVar3 = 0;
              }
              else {
                uVar3 = *(undefined4 *)(pJVar1 + *(short *)(pJVar1 + 0x18) * 4);
              }
              vi::VISetNextFrameBuffer(uVar3);
              vi::VIFlush();
              if (*(short *)(pJVar1 + 0x18) < 0) {
                JUtility::frameBuffer_2182 = (void *)0x0;
              }
              else {
                JUtility::frameBuffer_2182 = *(void **)(pJVar1 + *(short *)(pJVar1 + 0x18) * 4);
              }
            }
          }
        }
        else {
          if (iVar2 == 1) {
            if (*(int *)(pJVar1 + 0x1c) == 0) {
              if (*(short *)(pJVar1 + 0x16) < 0) {
                vi::VISetBlack(1);
              }
              else {
                *(short *)(pJVar1 + 0x18) = *(short *)(pJVar1 + 0x16);
                if (*(short *)(pJVar1 + 0x18) < 0) {
                  uVar3 = 0;
                }
                else {
                  uVar3 = *(undefined4 *)(pJVar1 + *(short *)(pJVar1 + 0x18) * 4);
                }
                gx::GXCopyDisp(uVar3,1);
                gx::GXFlush();
                *(undefined4 *)(pJVar1 + 0x1c) = 2;
                if (*(short *)(pJVar1 + 0x18) < 0) {
                  JUtility::frameBuffer_2182 = (void *)0x0;
                }
                else {
                  JUtility::frameBuffer_2182 = *(void **)(pJVar1 + *(short *)(pJVar1 + 0x18) * 4);
                }
                vi::VISetBlack(0);
              }
            }
            vi::VIFlush();
          }
        }
      }
    }
  }
  return;
}


/* __thiscall JUTVideo::drawDoneStart(void) */

void __thiscall JUTVideo::drawDoneStart(JUTVideo *this)

{
  JUtility::sDrawWaiting = 1;
  gx::GXSetDrawDone();
  return;
}


/* __thiscall JUTVideo::dummyNoDrawWait(void) */

void __thiscall JUTVideo::dummyNoDrawWait(JUTVideo *this)

{
  JUtility::sDrawWaiting = 0;
  return;
}


/* __thiscall JUTVideo::drawDoneCallback(void) */

JUTVideo * __thiscall JUTVideo::drawDoneCallback(JUTVideo *this)

{
  short sVar1;
  JUTXfb *pJVar2;
  undefined4 uVar3;
  
  pJVar2 = JUTXfb::sManager;
  if (JUTXfb::sManager != (JUTXfb *)0x0) {
    this = (JUTVideo *)0x0;
    JUtility::sDrawWaiting = 0;
    if (*(int *)(JUTXfb::sManager + 0x10) == 1) {
      if (*(int *)(JUTXfb::sManager + 0x1c) == 1) {
        *(undefined4 *)(JUTXfb::sManager + 0x1c) = 0;
        sVar1 = *(short *)(pJVar2 + 0x16);
        if (-1 < sVar1) {
          this = *(JUTVideo **)(pJVar2 + sVar1 * 4);
        }
        if (this != (JUTVideo *)0x0) {
          if (sVar1 < 0) {
            uVar3 = 0;
          }
          else {
            uVar3 = *(undefined4 *)(pJVar2 + sVar1 * 4);
          }
          vi::VISetNextFrameBuffer(uVar3);
          this = (JUTVideo *)vi::VIFlush();
        }
      }
    }
  }
  return this;
}


/* __thiscall JUTVideo::postRetraceProc(unsigned long) */

void __thiscall JUTVideo::postRetraceProc(JUTVideo *this,ulong param_1)

{
  undefined4 uVar1;
  
  if (*(code **)&sManager->field_0x28 != (code *)0x0) {
    this = (JUTVideo *)(**(code **)&sManager->field_0x28)();
  }
  uVar1 = vi::VIGetRetraceCount(this);
  os::OSSendMessage(&sManager->mMesgQ,uVar1,0);
  return;
}


/* __thiscall JUTVideo::setRenderMode(_GXRenderModeObj const *) */

void __thiscall JUTVideo::setRenderMode(JUTVideo *this,_GXRenderModeObj *param_1)

{
  if ((this->mpRenderMode != (_GXRenderModeObj *)0x0) &&
     (param_1->field_0x0 != this->mpRenderMode->field_0x0)) {
    this->field_0x2c = 1;
    this->field_0x30 = 4;
  }
  this->mpRenderMode = param_1;
  vi::VIConfigure(this->mpRenderMode);
  vi::VIFlush();
  if (this->field_0x2c != 0) {
    vi::VIWaitForRetrace();
    vi::VIWaitForRetrace();
  }
  return;
}


/* __thiscall JUTVideo::waitRetraceIfNeed(void) */

void __thiscall JUTVideo::waitRetraceIfNeed(JUTVideo *this)

{
  return;
}

