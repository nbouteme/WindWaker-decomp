#include <m_Do_main.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <m_Do_printf.h>
#include <JKernel/JKRExpHeap.h>
#include <JKernel/JKRHeap.h>
#include <m_Do_machine.h>
#include <os/OSThread.h>
#include <m_Do_main.h>
#include <JUtility/JUTDbPrint.h>
#include <JKernel/JKRAramHeap.h>
#include <JUtility/JUTAssert.h>
#include <JUtility/JUTConsole.h>
#include <DynamicLink.h>
#include <d_resorce.h>
#include <dvd/dvdfs.h>
#include <m_Do_graphic.h>
#include <m_Do_controller_pad.h>
#include <m_Do_ext.h>
#include <m_Do_dvd_thread.h>
#include <f_ap_game.h>
#include <c_dylink.h>
#include <JKernel/JKRSolidHeap.h>
#include <m_Do_MemCard.h>
#include <m_Do_audio.h>
#include <os/OSTime.h>
#include <os/OSArena.h>
#include <os/OSReset.h>
#include <d_com_inf_game.h>
#include <dvd/dvd.h>
#include <os/OS.h>
#include <HeapCheck.h>
#include <JKRHeap.h>


namespace m_Do_main {
struct OSThread mainThread;
undefined1 fillcheck_check_frame;
}

namespace mDoMain {
long sPowerOnTime;
undefined1 sHungUpTime;
}

namespace m_Do_main {
undefined1 mDisplayHeapSize;
undefined1 mSelectHeapBar;
undefined1 mCheckHeap;
float console_position_x$4105;
undefined1 init$4106;
float console_position_y$4108;
undefined1 init$4109;
float console_scroll$4111;
undefined1 init$4112;
undefined4 frame$4236;

/* __stdcall version_check(void) */

void version_check(void)

{
  int iVar1;
  
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp("05Sep2002","05Sep2002");
  if ((iVar1 == 0) && (iVar1 = MSL_C.PPCEABI.bare.H::strcmp("",""), iVar1 == 0)) {
    return;
  }
  m_Do_printf::OSReport_Error("SDKのバージョンが一致しません。停止します\n");
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

}

/* __thiscall HeapCheck::CheckHeap1(void) */

void __thiscall HeapCheck::CheckHeap1(HeapCheck *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = JKRExpHeap::getTotalUsedSize(this->field_0x4);
  iVar2 = JKRHeap::getFreeSize(&this->field_0x4->parent);
  if (this->field_0x8 < iVar1) {
    this->field_0x8 = iVar1;
  }
  if (iVar2 < this->field_0xc) {
    this->field_0xc = iVar2;
  }
  return;
}


namespace m_Do_main {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall CheckHeap(JUTGamePad *) */

void CheckHeap(JUTGamePad *param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  HeapCheck *this;
  int iVar4;
  
  m_Do_machine::mDoMch_HeapCheckAll();
  os::OSCheckActiveThreads();
  bVar1 = false;
  if ((((param_1->mButton).mButtonDown & 0xffffffef) == 0x60) &&
     (((param_1->mButton).mButtonReleased & 0x10) != 0)) {
    bVar1 = true;
  }
  iVar3 = 0;
  iVar4 = 0;
  do {
    ::HeapCheck::CheckHeap1(*(HeapCheck **)((int)&HeapCheckTable + iVar4));
    if (bVar1) {
      this = *(HeapCheck **)((int)&HeapCheckTable + iVar4);
      iVar2 = ::HeapCheck::getUsedCount(this);
      this->used = iVar2;
      iVar2 = JKRExpHeap::getTotalUsedSize(this->field_0x4);
      this->totalsize = iVar2;
    }
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar3 < 6);
  return;
}


/* __stdcall countUsed(JKRExpHeap *) */

int countUsed(int param_1)

{
  int iVar1;
  int iVar2;
  
  os::OSDisableScheduler();
  iVar2 = 0;
  for (iVar1 = *(int *)(param_1 + 0x80); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
    iVar2 = iVar2 + 1;
  }
  os::OSEnableScheduler();
  return iVar2;
}

}

/* __thiscall HeapCheck::getUsedCount(void) const */

void __thiscall HeapCheck::getUsedCount(HeapCheck *this)

{
  m_Do_main::countUsed(this->field_0x4);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall HeapCheck::heapDisplay(void) */

void __thiscall HeapCheck::heapDisplay(HeapCheck *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar6 = (this->field_0x4->parent).mSize;
  iVar1 = this->field_0x14 * this->field_0x18;
  this->field_0x10 = iVar1;
  iVar1 = iVar6 - iVar1;
  iVar2 = JKRExpHeap::getTotalUsedSize(this->field_0x4);
  iVar3 = JKRHeap::getTotalFreeSize(&this->field_0x4->parent);
  iVar4 = JKRHeap::getFreeSize(&this->field_0x4->parent);
  JUtility::JUTReport(100,0xd4,"[%sName]",this->field_0x0);
  JUtility::JUTReport(100,0xe3,"HeapSize         %8ld",iVar6);
  this->field_0x10 = this->field_0x14 * this->field_0x18;
  JUtility::JUTReport(100,0xf0,"TargetHeapSize   %8ld");
  JUtility::JUTReport(100,0xfd,"TotalFree        %8ld",iVar3 - iVar1);
  JUtility::JUTReport(100,0x10a,"FreeSize         %8ld",iVar4 - iVar1);
  JUtility::JUTReport(100,0x117,"TotalUsedSize    %8ld",iVar2);
  iVar3 = this->field_0x14 * this->field_0x18;
  this->field_0x10 = iVar3;
  JUtility::JUTReport(100,0x124,"TotalUsedRate        %3ld%%",(iVar2 * 100) / iVar3);
  JUtility::JUTReport(100,0x131,"MaxTotalUsedSize %8ld",this->field_0x8);
  iVar2 = this->field_0x14 * this->field_0x18;
  this->field_0x10 = iVar2;
  JUtility::JUTReport(100,0x13e,"MaxTotalUsedRate     %3ld%%",(this->field_0x8 * 100) / iVar2);
  JUtility::JUTReport(100,0x14b,"MinFreeSize      %8ld",this->field_0xc - iVar1);
  iVar2 = this->field_0x14 * this->field_0x18;
  this->field_0x10 = iVar2;
  JUtility::JUTReport(100,0x158,"MinFreeRate          %3ld%%",
                      ((this->field_0xc - iVar1) * 100) / iVar2);
  uVar5 = m_Do_main::countUsed(this->field_0x4);
  JUtility::JUTReport(100,0x165,"UsedCount             %3ld%",uVar5);
  return;
}


namespace m_Do_main {

/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __stdcall debugDisplay(void) */

void debugDisplay(void)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  int iVar4;
  JKRAramHeap *this;
  int iVar5;
  int iVar6;
  int unaff_r28;
  int unaff_r29;
  int iVar7;
  HeapCheck *this_00;
  
  uVar1 = (uint)mSelectHeapBar;
  if ((uVar1 != 0) && (uVar1 < 7)) {
    ::HeapCheck::heapDisplay(*(HeapCheck **)(&DAT_80371680 + uVar1 * 4));
  }
  if (mHeapBriefType == 5) {
    this = JKRAram::sAramObject->mpHeap;
    if (this != (JKRAramHeap *)0x0) {
      JUtility::JUTReport(500,100,"ARAM Free");
      uVar2 = JKRAramHeap::getFreeSize(this);
      JUtility::JUTReport(500,0x72,"%d",uVar2);
      JUtility::JUTReport(500,0x80,"TotalFree");
      uVar2 = JKRAramHeap::getTotalFreeSize(this);
      JUtility::JUTReport(500,0x8e,"%d",uVar2);
    }
  }
  else {
    if (mHeapBriefType != 0) {
      if (5 < mHeapBriefType) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"m_Do_main.cpp",0x213,"mHeapBriefType < HeapCheckTableNum");
        m_Do_printf::OSPanic("m_Do_main.cpp",0x213,"Halt");
      }
      JUtility::JUTReport(500,100,"%s",(&desc1_4076)[mHeapBriefType]);
      JUtility::JUTReport(500,0x72,"%s",(&desc2_4077)[mHeapBriefType]);
      iVar7 = 0;
      iVar6 = 0;
      iVar5 = 0;
      do {
        this_00 = *(HeapCheck **)((int)&HeapCheckTable + iVar5);
        if (mHeapBriefType == 3) {
          unaff_r29 = ::HeapCheck::getUsedCount(this_00);
          unaff_r28 = JKRExpHeap::getTotalUsedSize(this_00->field_0x4);
        }
        else {
          if (mHeapBriefType < 3) {
            if (mHeapBriefType == 1) {
              unaff_r29 = ::JKRHeap::getTotalFreeSize(&this_00->field_0x4->parent);
              unaff_r28 = ::JKRHeap::getFreeSize(&this_00->field_0x4->parent);
            }
            else {
              if (mHeapBriefType != 0) {
                unaff_r29 = this_00->field_0x8;
                unaff_r28 = (this_00->field_0x4->parent).mSize;
              }
            }
          }
          else {
            if (mHeapBriefType < 5) {
              iVar4 = ::HeapCheck::getUsedCount(this_00);
              unaff_r29 = iVar4 - this_00->used;
              iVar4 = JKRExpHeap::getTotalUsedSize(this_00->field_0x4);
              unaff_r28 = iVar4 - this_00->totalsize;
            }
          }
        }
        JUtility::JUTReport(500,iVar6 + 0x96," [%s]",this_00->field_0x0);
        JUtility::JUTReport(500,iVar6 + 0xa4,"%10d",unaff_r29);
        JUtility::JUTReport(500,iVar6 + 0xb2,"%10d",unaff_r28);
        iVar7 = iVar7 + 1;
        iVar6 = iVar6 + 0x2c;
        iVar5 = iVar5 + 4;
      } while (iVar7 < 6);
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x800061b8) */
/* WARNING: Removing unreachable block (ram,0x800061c0) */
/* __stdcall Debug_console(JUTGamePad *) */

undefined4 Debug_console(JUTGamePad *param_1,int param_2)

{
  int iVar1;
  JUTConsole *this;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  JKRAramHeap *this_00;
  undefined4 uVar5;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  double local_38;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  this = JFWSystem::systemConsole;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (JFWSystem::systemConsole != (JUTConsole *)0x0) {
    if (init_4106 == '\0') {
      console_position_x_4105 = _4181;
      init_4106 = '\x01';
    }
    if (init_4109 == '\0') {
      console_position_y_4108 = _4182;
      init_4109 = '\x01';
    }
    if (init_4112 == '\0') {
      console_scroll_4111 = _4183;
      init_4112 = '\x01';
    }
    if ((((param_1->mButton).mButtonReleased & 0x10) != 0) &&
       (((param_1->mButton).mButtonDown & 0xffffffef) == 0)) {
      uVar2 = countLeadingZeros((uint)(byte)JFWSystem::systemConsole[100]);
      JFWSystem::systemConsole[100] = SUB41(uVar2 >> 5,0);
      JUTAssertion::setMessageCount((JUTAssertion *)0x0,param_2);
    }
    if (this[100] != (JUTConsole)0x0) {
      uVar2 = (param_1->mButton).mButtonDown;
      if ((((uVar2 & 0x40) == 0) || ((uVar2 & 0x20) == 0)) &&
         (((param_1->mButton).mTriggerLeftRaw == 0 || ((param_1->mButton).mTriggerRightRaw == 0))))
      {
        if (((param_1->mButton).mButtonReleased & 4) != 0) {
          f_ap_game::g_HIO.deven = f_ap_game::g_HIO.deven ^ 1;
        }
        if (((param_1->mButton).mButtonReleased & 1) != 0) {
          this_00 = JKRAram::sAramObject->mpHeap;
          if (this_00 != (JKRAramHeap *)0x0) {
            this_00 = (JKRAramHeap *)JKRAramHeap::dump(this_00);
          }
          DynamicModuleControlBase::dump((DynamicModuleControlBase *)this_00);
          dRes_control_c::dump(&d_com_inf_game::g_dComIfG_gameInfo.mResCtrl);
        }
        if (((param_1->mButton).mButtonReleased & 2) != 0) {
          (*(code *)::JKRHeap::sSystemHeap->vtbl->dump_sort)();
        }
        if (((param_1->mButton).mButtonReleased & 8) != 0) {
          (*(code *)m_Do_ext::zeldaHeap->vtbl->dump_sort)();
          (*(code *)m_Do_ext::gameHeap->vtbl->dump_sort)();
          (*(code *)m_Do_ext::archiveHeap->vtbl->dump_sort)();
        }
        JUtility::JUTReport(0x1e,0x1b8,1,"Press L+R trigger to control console.");
        JUtility::JUTReport(0x1e,0x1c2,1,"Press [Z] trigger to close this window.");
      }
      else {
        dVar7 = (double)(param_1->mStickMain).mPosX;
        dVar6 = (double)(param_1->mStickMain).mPosY;
        if ((((uVar2 & 0x400) != 0) && ((uVar2 & 0x800) != 0)) &&
           (((param_1->mButton).mButtonReleased & 0x1000) != 0)) {
          JUTConsole::clear(this);
        }
        uVar3 = (param_1->mButton).mButtonDown;
        uVar2 = uVar3 & 0x400;
        if ((uVar2 == 0) && ((uVar3 & 0x800) == 0)) {
          dVar7 = (double)console_scroll_4111;
          console_scroll_4111 = (float)(dVar7 - dVar6);
          if (console_scroll_4111 <= _4184) {
            if (_4185 <= console_scroll_4111) {
              uVar2 = 0;
            }
            else {
              uVar2 = -(int)-console_scroll_4111;
            }
          }
          else {
            uVar2 = (uint)(dVar7 - dVar6);
          }
          if (uVar2 != 0) {
            local_38 = (double)CONCAT44(0x43300000,uVar2 ^ 0x80000000);
            console_scroll_4111 = console_scroll_4111 - (float)(local_38 - _4187);
            JUTConsole::scroll(this,uVar2);
          }
        }
        else {
          if (uVar2 != 0) {
            console_position_x_4105 = (float)((double)console_position_x_4105 + dVar7);
          }
          if (((param_1->mButton).mButtonDown & 0x800) != 0) {
            console_position_y_4108 = (float)((double)console_position_y_4108 - dVar6);
          }
        }
        if (((param_1->mButton).mButtonReleased & 0x100) != 0) {
          JUTConsole::dumpToTerminal(this,0xffffffff);
          *(undefined4 *)(this + 0x58) = 3;
        }
        JUtility::JUTReport(0x1e,0x186,1,"Press X+Y+START to CLEAR console.");
        JUtility::JUTReport(0x1e,400,1,"3DStick UP/Down to scroll");
        JUtility::JUTReport(0x1e,0x19a,1,"Press A to output terminal from console.");
        uVar4 = JUTConsole::getLineOffset(this);
        JUtility::JUTReport(0x1e,0x1a4,1,"SCROLL：%3d %3d %3d Output=%1x",uVar4,
                            *(undefined4 *)(this + 0x40),*(undefined4 *)(this + 0x44),
                            *(undefined4 *)(this + 0x58));
      }
      iVar1 = (int)console_position_y_4108;
      *(int *)(this + 0x40) = (int)console_position_x_4105;
      *(int *)(this + 0x44) = iVar1;
      uVar4 = 1;
      goto LAB_800061b8;
    }
  }
  uVar4 = 0;
LAB_800061b8:
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return uVar4;
}

}

/* __thiscall JKRHeap::dump_sort(void) */

undefined4 __thiscall JKRHeap::dump_sort(JKRHeap *this)

{
  return 1;
}


namespace m_Do_main {

/* __stdcall LOAD_COPYDATE(void *) */

void LOAD_COPYDATE(void)

{
  bool bVar1;
  byte abStack96 [32];
  undefined auStack64 [64];
  
  bVar1 = dvd::DVDOpen("/COPYDATE",(int)auStack64);
  if (bVar1 != false) {
    dvd::DVDReadPrio(auStack64,abStack96,0x20,0,2);
    copy_bytes((byte *)::mDoMain::COPYDATE_STRING,abStack96,0x11);
    dvd::DVDClose(auStack64);
  }
  return;
}


/* __stdcall debug(void) */

void debug(void)

{
  undefined4 in_r4;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  
  if (::mDoMain::developmentMode != '\0') {
    if (mCheckHeap != '\0') {
      CheckHeap(m_Do_controller_pad::g_mDoCPd_gamePad[2]);
      in_r4 = extraout_r4;
    }
    if ((((m_Do_controller_pad::g_mDoCPd_gamePad[2]->mButton).mButtonDown & 0xffffffef) == 0x20) &&
       (((m_Do_controller_pad::g_mDoCPd_gamePad[2]->mButton).mButtonReleased & 0x10) != 0)) {
      mDisplayHeapSize = mDisplayHeapSize ^ 1;
    }
    if (mDisplayHeapSize != 0) {
      if ((((m_Do_controller_pad::g_mDoCPd_gamePad[2]->mButton).mButtonDown & 0xffffffef) == 0x40)
         && (((m_Do_controller_pad::g_mDoCPd_gamePad[2]->mButton).mButtonReleased & 0x10) != 0)) {
        if (mHeapBriefType < 5) {
          mHeapBriefType = mHeapBriefType + 1;
        }
        else {
          mHeapBriefType = 1;
        }
      }
      debugDisplay();
      in_r4 = extraout_r4_00;
    }
    Debug_console(m_Do_controller_pad::g_mDoCPd_gamePad[2],in_r4);
  }
  return;
}


/* __stdcall main01(void) */

void main01(void)

{
  JUTConsole *pJVar1;
  undefined4 uVar2;
  uint uVar3;
  
  m_Do_machine::mDoMch_Create();
  m_Do_graphic::mDoGph_Create();
  m_Do_controller_pad::mDoCPd_Create();
  DAT_803715b0 = ::JKRHeap::sRootHeap;
  DAT_803715d4 = ::JKRHeap::sSystemHeap;
  DAT_803715f8 = m_Do_ext::mDoExt_getZeldaHeap();
  DAT_8037161c = m_Do_ext::mDoExt_getGameHeap();
  DAT_80371640 = m_Do_ext::mDoExt_getArchiveHeap();
  DAT_80371664 = m_Do_ext::mDoExt_getCommandHeap();
  pJVar1 = JFWSystem::systemConsole;
  uVar2 = 0;
  if (::mDoMain::developmentMode != '\0') {
    uVar2 = 3;
  }
  *(undefined4 *)(JFWSystem::systemConsole + 0x58) = uVar2;
  *(undefined4 *)(pJVar1 + 0x40) = 0x20;
  *(undefined4 *)(pJVar1 + 0x44) = 0x2a;
  mDoDvdThd_callback_c::create(LOAD_COPYDATE,(void *)0x0);
  f_ap_game::fapGm_Create();
  mDisplayHeapSize = 0;
  c_dylink::cDyl_InitAsync();
  m_Do_audio::g_mDoAud_audioHeap = JKRSolidHeap::create(0x166800,::JKRHeap::sCurrentHeap,false);
  do {
    frame_4236 = frame_4236 + 1;
    uVar3 = (uint)fillcheck_check_frame;
    if ((uVar3 != 0) && (frame_4236 == (frame_4236 / uVar3) * uVar3)) {
      m_Do_machine::mDoMch_HeapCheckAll();
    }
    if (mDoDvdThd::SyncWidthSound != '\0') {
      mDoMemCd_Ctrl_c::update(&m_Do_MemCard::g_mDoMemCd_control);
    }
    m_Do_controller_pad::mDoCPd_Read();
    m_Do_audio::mDoAud_Execute();
    f_ap_game::fapGm_Execute();
    debug();
  } while( true );
}


void main(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined auStack56 [48];
  
  uVar4 = os::OSGetCurrentThread();
  uVar1 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar3 = (undefined4)uVar4;
  ::mDoMain::sPowerOnTime = os::OSGetTime();
  DAT_803f682c = uVar3;
  m_Do_printf::OSReportInit();
  version_check();
  mDoRst::mResetData = (undefined4 *)os::OSAllocFromArenaLo(0x10,4);
  if (mDoRst::mResetData == (undefined4 *)0x0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar2 = os::OSGetResetCode();
  if (iVar2 == 0) {
    *mDoRst::mResetData = 0;
    mDoRst::mResetData[1] = 0;
    mDoRst::mResetData[1] = 0;
    mDoRst::mResetData[2] = 0;
    mDoRst::mResetData[3] = 0xffffffff;
  }
  dComIfG_inf_c::ct(&d_com_inf_game::g_dComIfG_gameInfo);
  if ((char)::mDoMain::developmentMode < '\0') {
    iVar2 = dvd::DVDGetCurrentDiskID();
    if (*(byte *)(iVar2 + 7) < 0x91) {
      if (*(byte *)(iVar2 + 7) < 0x81) {
        ::mDoMain::developmentMode = 0;
      }
      else {
        iVar2 = os::OSGetConsoleType();
        ::mDoMain::developmentMode = (byte)((uint)iVar2 >> 0x1c) & 1;
      }
    }
    else {
      ::mDoMain::developmentMode = 1;
    }
  }
  uVar3 = os::OSGetThreadPriority(uVar1);
  os::OSCreateThread(&mainThread,main01,0,auStack56,0xf000,uVar3,0);
  os::OSResumeThread(&mainThread);
  os::OSSetThreadPriority(uVar1,0x1f);
  os::OSSuspendThread(uVar1);
  return;
}

