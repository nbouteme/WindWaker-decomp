#include <m_Do_Reset.h>
#include <JUtility/JUTVideo.h>
#include <gx/GXMisc.h>
#include <vi/vi.h>
#include <dvd/dvd.h>
#include <JUtility/JUTXfb.h>
#include <m_Do_DVDError.h>
#include <JUtility/JUTGamePad.h>
#include <gx/GXFifo.h>
#include <os/OSInterrupt.h>
#include <os/OSThread.h>
#include <m_Do_Reset.h>
#include <os/OSCache.h>
#include <os/OSReboot.h>
#include <os/OSReset.h>
#include <mDoRst.h>

undefined4 mDoRst;

namespace m_Do_Reset {

/* __stdcall my_OSCancelAlarmAll(void) */

void my_OSCancelAlarmAll(void)

{
  return;
}


/* __stdcall destroyVideo(void) */

void destroyVideo(JUTVideo *param_1)

{
  JUTVideo::destroyManager(param_1);
  gx::GXSetDrawDoneCallback(0);
  vi::VISetBlack(1);
  vi::VIFlush();
  vi::VIWaitForRetrace();
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* __stdcall mDoRst_reset(int,
                          unsigned long,
                          int) */

void mDoRst_reset(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  JUTGamePad *this;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = dvd::DVDGetDriveStatus();
  if (iVar1 == -1) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  JUTXfb::clearIndex(JUTXfb::sManager);
  this = (JUTGamePad *)m_Do_DVDError::mDoDvdErr_ThdCleanup();
  JUTGamePad::clearForReset(this);
  mDoAud_zelAudio_c::mInitFlag = 0;
  vi::VIWaitForRetrace();
  vi::VIWaitForRetrace();
  iVar1 = gx::GXGetCurrentGXThread();
  uVar2 = os::OSDisableInterrupts();
  iVar3 = os::OSGetCurrentThread();
  if (iVar1 != iVar3) {
    os::OSCancelThread(iVar1);
    gx::GXSetCurrentGXThread();
  }
  gx::GXFlush();
  gx::GXAbortFrame();
  gx::GXDrawDone();
  os::OSRestoreInterrupts(uVar2);
  destroyVideo();
  my_OSCancelAlarmAll();
  os::LCDisable();
  os::OSSetSaveRegion(::mDoRst::mResetData,0x80017f00);
  os::OSResetSystem(param_1,param_2,param_3);
  do {
    vi::VIWaitForRetrace();
  } while( true );
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall mDoRst_resetCallBack(int,
                                  void *) */

void mDoRst_resetCallBack(JUTGamePad *param_1)

{
  int iVar1;
  ulong extraout_r4;
  ulong extraout_r4_00;
  
  if (*::mDoRst::mResetData == 0) {
    if (param_1 == (JUTGamePad *)&DAT_ffffffff) {
      JUTGamePad::clearForReset((JUTGamePad *)&DAT_ffffffff);
      JUTGamePad::CRumble::setEnabled((CRumble *)0xf0000000,extraout_r4);
    }
    else {
      if (::mDoRst::mResetData[2] != 0) {
        _sCallback = mDoRst_resetCallBack;
        _sCallbackArg = 0;
        JUTGamePad::C3ButtonReset::sResetOccurred = 0;
        return;
      }
      ::mDoRst::mResetData[2] = 1;
      ::mDoRst::mResetData[3] = (int)param_1;
      JUTGamePad::clearForReset(param_1);
      JUTGamePad::CRumble::setEnabled((CRumble *)0xf0000000,extraout_r4_00);
    }
    iVar1 = dvd::DVDCheckDisk();
    if (iVar1 == 0) {
      mDoRst_reset(1,0x80000000,0);
    }
    *::mDoRst::mResetData = 1;
  }
  return;
}

}

/* __thiscall mDoRst::getResetData(void) */

undefined4 __thiscall mDoRst::getResetData(mDoRst *this)

{
  return mResetData;
}

