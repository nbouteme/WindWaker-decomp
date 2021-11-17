#include <m_Do_machine.h>
#include <m_Do_ext.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <m_Do_printf.h>
#include <m_Do_machine.h>
#include <JKernel/JKRHeap.h>
#include <os/OSTime.h>
#include <JUtility/JUTGamePad.h>
#include <base/PPCArch.h>
#include <os/OSInterrupt.h>
#include <JUtility/JUTException.h>
#include <os/OSReset.h>
#include <JUtility/JUTAssert.h>
#include <JUtility/JUTConsole.h>
#include <m_Do_machine_exception.h>
#include <vi/vi.h>
#include <os/OS.h>
#include <os/OSArena.h>
#include <os/OSMemory.h>
#include <JFramework/JFWSystem.h>
#include <JKernel/JKRAramStream.h>
#include <JKernel/JKRThread.h>
#include <os/OSThread.h>
#include <JMath/JMath.h>
#include <SComponent/c_malloc.h>
#include <SComponent/c_math.h>
#include <m_Do_dvd_thread.h>
#include <m_Do_DVDError.h>
#include <m_Do_MemCard.h>


namespace mDoMch {
undefined1 mDebugFill;
}

namespace m_Do_machine {
undefined4 solidHeapErrors;
undefined4 gameHeapErrors;
undefined4 zeldaHeapErrors;
undefined4 commandHeapErrors;
undefined4 archiveHeapErrors;
undefined4 unknownHeapErrors;
undefined4 heapErrors;
undefined1 tmpString$4003;
byte key_link$4106;
byte key_ganon$4107;
byte key_zelda$4108;

/* __stdcall myGetHeapTypeByString(JKRHeap *) */

char * myGetHeapTypeByString(JKRExpHeap *param_1)

{
  char *pcVar1;
  JKRExpHeap *pJVar2;
  int iVar3;
  undefined local_18;
  undefined uStack23;
  undefined uStack22;
  undefined uStack21;
  
  if (param_1 == (JKRExpHeap *)JKRHeap::sSystemHeap) {
    pcVar1 = "SystemHeap";
  }
  else {
    pJVar2 = (JKRExpHeap *)m_Do_ext::mDoExt_getZeldaHeap();
    if (param_1 == pJVar2) {
      pcVar1 = "ZeldaHeap";
    }
    else {
      pJVar2 = m_Do_ext::mDoExt_getGameHeap();
      if (param_1 == pJVar2) {
        pcVar1 = "GameHeap";
      }
      else {
        pJVar2 = (JKRExpHeap *)m_Do_ext::mDoExt_getArchiveHeap();
        if (param_1 == pJVar2) {
          pcVar1 = "ArchiveHeap";
        }
        else {
          pJVar2 = (JKRExpHeap *)m_Do_ext::mDoExt_getCommandHeap();
          if (param_1 == pJVar2) {
            pcVar1 = "CommandHeap";
          }
          else {
            iVar3 = (*(code *)((param_1->parent).vtbl)->getHeapType)(param_1);
            if (iVar3 == 0x534c4944) {
              pcVar1 = "SLID";
            }
            else {
              if (iVar3 < 0x534c4944) {
                if (iVar3 == 0x41535448) {
                  return "ASTH";
                }
                if (iVar3 < 0x41535448) {
                  if (iVar3 == 0) {
                    return "(Null)";
                  }
                }
                else {
                  if (iVar3 == 0x45585048) {
                    return "EXPH";
                  }
                }
              }
              else {
                if (iVar3 == 0x554e4954) {
                  return "UNIT";
                }
                if ((iVar3 < 0x554e4954) && (iVar3 == 0x53544448)) {
                  return "STDH";
                }
              }
              local_18 = (undefined)((uint)iVar3 >> 0x18);
              tmpString_4003 = local_18;
              uStack23 = (undefined)((uint)iVar3 >> 0x10);
              uRam803f6911 = uStack23;
              uStack22 = (undefined)((uint)iVar3 >> 8);
              uRam803f6912 = uStack22;
              uStack21 = (undefined)iVar3;
              uRam803f6913 = uStack21;
              uRam803f6914 = 0;
              pcVar1 = &tmpString_4003;
            }
          }
        }
      }
    }
  }
  return pcVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall myMemoryErrorRoutine(void *,
                                  unsigned long,
                                  int) */

void myMemoryErrorRoutine(JKRHeap *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined local_20;
  undefined uStack31;
  undefined uStack30;
  
  iVar1 = (*(code *)param_1->vtbl->getHeapType)();
  if (iVar1 != 0x534c4944) {
    m_Do_printf::OSReport_Error
              ("Error: Cannot allocate memory %d(0x%x)byte in %d byte alignment from %08x\n",param_2
               ,param_2,param_3,param_1);
  }
  uVar2 = (*(code *)param_1->vtbl->getHeapType)(param_1);
  if (iVar1 != 0x534c4944) {
    iVar1 = param_1->mSize;
    uVar3 = myGetHeapTypeByString(param_1);
    uVar4 = JKRHeap::getTotalFreeSize(param_1);
    uVar5 = JKRHeap::getFreeSize(param_1);
    local_20 = (undefined)(uVar2 >> 0x18);
    uStack31 = (undefined)(uVar2 >> 0x10);
    uStack30 = (undefined)(uVar2 >> 8);
    m_Do_printf::OSReport_Error
              ("FreeSize=%08x TotalFreeSize=%08x HeapType=%08x(%c%c%c%c) HeapSize=%08x %s\n",uVar5,
               uVar4,uVar2,local_20,uStack31,uStack30,uVar2 & 0xff,iVar1,uVar3);
  }
  if (heapErrors == 0) {
    (*(code *)param_1->vtbl->dump_sort)(param_1);
  }
  heapErrors = heapErrors + 1;
  if (param_1 == m_Do_ext::zeldaHeap) {
    zeldaHeapErrors = zeldaHeapErrors + 1;
  }
  else {
    if (param_1 == m_Do_ext::gameHeap) {
      gameHeapErrors = gameHeapErrors + 1;
    }
    else {
      if (param_1 == m_Do_ext::commandHeap) {
        commandHeapErrors = commandHeapErrors + 1;
      }
      else {
        if (param_1 == m_Do_ext::archiveHeap) {
          archiveHeapErrors = archiveHeapErrors + 1;
        }
        else {
          iVar1 = (*(code *)param_1->vtbl->getHeapType)(param_1);
          if (iVar1 == 0x534c4944) {
            solidHeapErrors = solidHeapErrors + 1;
          }
          else {
            unknownHeapErrors = unknownHeapErrors + 1;
          }
        }
      }
    }
  }
  return;
}


/* __stdcall myHeapCheckRecursive(JKRHeap *) */

void myHeapCheckRecursive(int *param_1)

{
  char cVar3;
  undefined4 uVar1;
  int iVar2;
  
  cVar3 = (**(code **)(*param_1 + 0x14))();
  if (cVar3 == '\0') {
    uVar1 = myGetHeapTypeByString(param_1);
    m_Do_printf::OSReport_Error("error in %08x(%s)\n",param_1,uVar1);
  }
  iVar2 = param_1[0x10];
  if (iVar2 != 0) {
    iVar2 = iVar2 + -0xc;
  }
  while (iVar2 != 0) {
    myHeapCheckRecursive(*(undefined4 *)(iVar2 + 0xc));
    iVar2 = *(int *)(iVar2 + 0x18);
    if (iVar2 != 0) {
      iVar2 = iVar2 + -0xc;
    }
  }
  return;
}


/* __stdcall mDoMch_HeapCheckAll(void) */

void mDoMch_HeapCheckAll(void)

{
  myHeapCheckRecursive(JKRHeap::sRootHeap);
  return;
}


/* __stdcall developKeyCheck(unsigned long,
                             unsigned long) */

int developKeyCheck(int param_1,int param_2)

{
  if ((param_2 == 0x74) && (param_1 == 4)) {
    if ((key_link_4106 == 3) && ((key_ganon_4107 == 6 && (key_zelda_4108 == 5)))) {
      mDoMain::developmentMode = '\x01';
    }
    else {
      key_link_4106 = 0;
      key_ganon_4107 = 0;
      key_zelda_4108 = 0;
    }
  }
  if ((param_2 == 0x42) && (param_1 == 0x40)) {
    key_link_4106 = key_link_4106 + 1;
  }
  if ((param_2 == 0x28) && (param_1 == 0x20)) {
    key_ganon_4107 = key_ganon_4107 + 1;
  }
  if ((param_2 == 0x11) && (param_1 == 0x10)) {
    key_zelda_4108 = key_zelda_4108 + 1;
  }
  return (int)mDoMain::developmentMode;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall myExceptionCallback(unsigned short,
                                 OSContext *,
                                 unsigned long,
                                 unsigned long) */

void myExceptionCallback(undefined4 param_1,undefined4 param_2)

{
  JUTException *this;
  JUTGamePad *this_00;
  ulong local_b8;
  ulong local_b4;
  JUTGamePad JStack176;
  
  _sHungUpTime = os::OSGetTime();
  DAT_803f6834 = param_2;
  this_00 = (JUTGamePad *)m_Do_printf::OSReportEnable();
  JUTGamePad::clearForReset(this_00);
  m_Do_printf::OSReport("振動停止＆原点復帰\n");
  this = JUTException::sErrorManager;
  if (JUTException::sErrorManager == (JUTException *)0x0) {
    m_Do_printf::OSReport("例外マネージャがありません\n");
    base::PPCHalt();
  }
  if (mDoMain::developmentMode == '\0') {
    JUTGamePad::JUTGamePad(&JStack176,0);
    *(JUTGamePad **)(this + 0x70) = &JStack176;
    *(undefined4 *)(this + 0x74) = 0xffffffff;
    if (this == (JUTException *)0x0) {
      base::PPCHalt();
    }
    else {
      os::OSEnableInterrupts();
      m_Do_printf::OSReport("キー入力を受け付けています\n");
      while (mDoMain::developmentMode == '\0') {
        JUTException::readPad(this,&local_b8,&local_b4);
        developKeyCheck(local_b8,local_b4);
        JUTException::waitTime(0x1e);
        if (JUTGamePad::C3ButtonReset::sResetOccurred != '\0') {
          m_Do_printf::OSReport("リセット受け付けています\n");
          os::OSResetSystem(1,0,0);
        }
      }
      m_Do_printf::OSReport("JUTAssertionを可視化しました\n");
      JUTAssertion::setVisible(true);
      JUTDbPrint::sDebugPrint[0xc] = (JUTDbPrint)0x1;
      *(undefined4 *)(JFWSystem::systemConsole + 0x58) = 3;
    }
    JUTGamePad::_JUTGamePad(&JStack176);
  }
  else {
    m_Do_printf::OSReport("3秒間停止\n");
    JUTException::waitTime(3000);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall fault_callback_scroll(unsigned short,
                                   OSContext *,
                                   unsigned long,
                                   unsigned long) */

void fault_callback_scroll(void)

{
  bool bVar1;
  JUTConsole *pJVar2;
  JUTException *this;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  JUTConsole *this_00;
  int iVar7;
  ulong local_c8;
  ulong local_c4;
  JUTGamePad JStack192;
  
  this_00 = _sConsole;
  this = JUTException::sErrorManager;
  JUTGamePad::JUTGamePad(&JStack192,0);
  *(JUTGamePad **)(this + 0x70) = &JStack192;
  *(undefined4 *)(this + 0x74) = 0xffffffff;
  uVar3 = JUTException::isEnablePad(this);
  uVar3 = countLeadingZeros(uVar3 & 0xff);
  if ((uVar3 >> 5 & 0xff) == 0) {
    JUTConsole::print(this_00,"PUSH START BUTTON TO ADDITIONAL INFOMATION\n");
    JUTConsole::print(this_00,"--------------------------------------\n");
    JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
    os::OSEnableInterrupts();
    iVar7 = 0;
    iVar6 = 0;
    do {
      JUTException::readPad(this,&local_c8,&local_c4);
      if (JUTGamePad::C3ButtonReset::sResetOccurred != '\0') {
        os::OSResetSystem(1,0,0);
      }
      bVar1 = local_c8 == 0x1000;
      if (bVar1) {
        m_Do_machine_exception::exception_addition(this_00);
      }
      pJVar2 = JFWSystem::systemConsole;
      if (local_c8 == 0x10) {
        this_00 = _sConsole;
        if (*(JUTConsole **)(JUTConsoleManager::sManager + 0x10) != JFWSystem::systemConsole) {
          *(float *)(JFWSystem::systemConsole + 0x50) = _4261;
          *(float *)(pJVar2 + 0x54) = _4262;
          *(undefined4 *)(pJVar2 + 0x40) = 8;
          *(undefined4 *)(pJVar2 + 0x44) = 0x20;
          *(undefined4 *)(pJVar2 + 0x48) = 0x17;
          if (*(uint *)(pJVar2 + 0x24) < *(uint *)(pJVar2 + 0x48)) {
            *(uint *)(pJVar2 + 0x48) = *(uint *)(pJVar2 + 0x24);
          }
          pJVar2[100] = (JUTConsole)0x1;
          *(undefined4 *)(pJVar2 + 0x58) = 3;
          this_00 = pJVar2;
        }
        JUTConsoleManager::setDirectConsole(JUTConsoleManager::sManager,this_00);
        bVar1 = true;
      }
      if (local_c8 == 0x100) {
        JUTConsole::scroll(this_00,*(int *)(this_00 + 0x24));
        bVar1 = true;
      }
      if (local_c8 == 0x200) {
        JUTConsole::scroll(this_00,-*(int *)(this_00 + 0x24));
        bVar1 = true;
      }
      if (local_c4 == 8) {
        if (iVar7 < 3) {
          iVar6 = -1;
        }
        else {
          if (iVar7 < 5) {
            iVar6 = -2;
          }
          else {
            iVar6 = -8;
            if (iVar7 < 7) {
              iVar6 = -4;
            }
          }
        }
        JUTConsole::scroll(this_00,iVar6);
        bVar1 = true;
        iVar6 = 0;
        iVar7 = iVar7 + 1;
      }
      else {
        if (local_c4 == 4) {
          if (iVar6 < 3) {
            iVar7 = 1;
          }
          else {
            if (iVar6 < 5) {
              iVar7 = 2;
            }
            else {
              iVar7 = 8;
              if (iVar6 < 7) {
                iVar7 = 4;
              }
            }
          }
          JUTConsole::scroll(this_00,iVar7);
          bVar1 = true;
          iVar7 = 0;
          iVar6 = iVar6 + 1;
        }
        else {
          iVar7 = 0;
          iVar6 = 0;
        }
      }
      if (bVar1) {
        iVar4 = vi::VIGetRetraceCount();
        do {
          iVar5 = vi::VIGetRetraceCount();
        } while (iVar4 == iVar5);
        JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
      }
      JUTException::waitTime(0x1e);
    } while( true );
  }
  m_Do_machine_exception::exception_addition(this_00);
  JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
  do {
    JUTConsole::scroll(this_00,-*(int *)(this_00 + 0x24));
    JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
    JUTException::waitTime(2000);
    do {
      for (iVar6 = *(int *)(this_00 + 0x48); iVar6 != 0; iVar6 = iVar6 + -1) {
        JUTConsole::scroll(this_00,1);
        JUTConsoleManager::drawDirect(JUTConsoleManager::sManager,true);
        iVar4 = *(int *)(this_00 + 0x48);
        uVar3 = JUTConsole::getLineOffset(this_00);
        iVar7 = JUTConsole::getUsedLine(this_00);
        if ((iVar7 - iVar4) + 1U <= uVar3) break;
        JUTException::waitTime(0x14);
      }
      JUTException::waitTime(3000);
      iVar7 = *(int *)(this_00 + 0x48);
      uVar3 = JUTConsole::getLineOffset(this_00);
      iVar6 = JUTConsole::getUsedLine(this_00);
    } while (uVar3 < (iVar6 - iVar7) + 1U);
  } while( true );
}


/* __stdcall mDoMch_Create(void) */

undefined4 mDoMch_Create(void)

{
  undefined *puVar1;
  JUTConsole *pJVar2;
  uint uVar3;
  ulong uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  JFWSystem *this;
  JKRHeap *pJVar8;
  JKRThread *this_00;
  OSThread *pOVar9;
  char *in_r6;
  int iVar10;
  
  if ((mDoMain::developmentMode == '\0') ||
     (uVar3 = os::OSGetConsoleType(), (uVar3 & 0x10000000) == 0)) {
    m_Do_printf::OSReportDisable();
  }
  JKRHeap::sDefaultFillFlag = '\x01' - (::mDoMch::mDebugFill == '\0');
  if (JFWSystem::sInitCalled != 0) {
    uVar4 = JUTAssertion::getSDevice();
    in_r6 = "sInitCalled == 0";
    JUTAssertion::showAssert(uVar4,"JFWSystem.h",0x2f,"sInitCalled == 0");
    m_Do_printf::OSPanic("JFWSystem.h",0x2f,"Halt");
  }
  JFWSystem::CSetUpParam::maxStdHeaps = 1;
  uVar3 = os::OSGetArenaHi();
  uVar5 = os::OSGetArenaLo();
  if ((0x81800000 < uVar3) && (uVar5 < uVar3 + 0xfe800000)) {
    os::OSSetArenaHi(uVar3 + 0xfe800000);
  }
  iVar6 = os::OSGetArenaHi();
  iVar7 = os::OSGetArenaLo();
  iVar10 = (iVar6 - iVar7) + -0xf0;
  uVar3 = os::OSGetConsoleSimulatedMemSize();
  if (0x2ffffff < uVar3) {
    iVar10 = (iVar6 - iVar7) + -0x10000f0;
  }
  if (mDoMain::memMargin != -1) {
    iVar10 = iVar10 + mDoMain::memMargin;
  }
  if (JFWSystem::sInitCalled != 0) {
    uVar4 = JUTAssertion::getSDevice();
    in_r6 = "sInitCalled == 0";
    JUTAssertion::showAssert(uVar4,"JFWSystem.h",0x32,"sInitCalled == 0");
    m_Do_printf::OSPanic("JFWSystem.h",0x32,"Halt");
  }
  JFWSystem::CSetUpParam::sysHeapSize = iVar10 + -0xd20c00;
  if (JFWSystem::sInitCalled != 0) {
    uVar4 = JUTAssertion::getSDevice();
    in_r6 = "sInitCalled == 0";
    JUTAssertion::showAssert(uVar4,"JFWSystem.h",0x35,"sInitCalled == 0");
    m_Do_printf::OSPanic("JFWSystem.h",0x35,"Halt");
  }
  JFWSystem::CSetUpParam::fifoBufSize = 0xa0000;
  if (JFWSystem::sInitCalled != 0) {
    uVar4 = JUTAssertion::getSDevice();
    in_r6 = "sInitCalled == 0";
    JUTAssertion::showAssert(uVar4,"JFWSystem.h",0x3a,"sInitCalled == 0");
    m_Do_printf::OSPanic("JFWSystem.h",0x3a,"Halt");
  }
  JFWSystem::CSetUpParam::aramAudioBufSize = 0xa00000;
  if (JFWSystem::sInitCalled != 0) {
    uVar4 = JUTAssertion::getSDevice();
    in_r6 = "sInitCalled == 0";
    JUTAssertion::showAssert(uVar4,"JFWSystem.h",0x3d,"sInitCalled == 0");
    m_Do_printf::OSPanic("JFWSystem.h",0x3d,"Halt");
  }
  puVar1 = ::mDoMch_render_c::mRenderModeObj;
  this = (JFWSystem *)&DAT_005d0000;
  JFWSystem::CSetUpParam::aramGraphBufSize = 0x5ce000;
  if (JFWSystem::sInitCalled != 0) {
    uVar4 = JUTAssertion::getSDevice();
    in_r6 = "sInitCalled == 0";
    JUTAssertion::showAssert(uVar4,"JFWSystem.h",0x50,"sInitCalled == 0");
    this = (JFWSystem *)m_Do_printf::OSPanic("JFWSystem.h",0x50,"Halt");
  }
  JFWSystem::CSetUpParam::renderMode = puVar1;
  JFWSystem::init(this);
  if (mDoMain::developmentMode == '\0') {
    JUTAssertion::setVisible(false);
    JUTDbPrint::sDebugPrint[0xc] = (JUTDbPrint)0x0;
  }
  JKRHeap::setErrorHandler(myMemoryErrorRoutine);
  JKRHeap::setErrorFlag(JKRHeap::sRootHeap,true);
  JKRHeap::setErrorFlag(JFWSystem::systemHeap,true);
  pJVar8 = JKRHeap::sRootHeap;
  m_Do_ext::mDoExt_createCommandHeap(0x1000,JKRHeap::sRootHeap);
  m_Do_ext::mDoExt_createArchiveHeap(0xa51400,pJVar8);
  m_Do_ext::mDoExt_createGameHeap(0x2ce800,pJVar8);
  pJVar8 = JKRHeap::sSystemHeap;
  iVar6 = JKRHeap::getFreeSize(JKRHeap::sSystemHeap);
  if ((int)(iVar6 - 0x10000U) < 1) {
    uVar4 = JUTAssertion::getSDevice();
    in_r6 = "size > 0";
    JUTAssertion::showAssert(uVar4,"m_Do_machine.cpp",0x450,"size > 0");
    m_Do_printf::OSPanic("m_Do_machine.cpp",0x450,"Halt");
  }
  pJVar8 = m_Do_ext::mDoExt_createZeldaHeap(iVar6 - 0x10000U,pJVar8);
  JKRHeap::becomeCurrentHeap(pJVar8);
  JKRAramStream::setTransBuffer
            ((JKRAramStream *)0x0,(uchar *)0x2000,(ulong)JKRHeap::sSystemHeap,(JKRHeap *)in_r6);
  JKRAram::sSzpBufferSize = 0x2000;
  JKRDvdAramRipper::sSzpBufferSize = 0x2000;
  JKRDvdRipper::sSzpBufferSize = 0x2000;
  JKRThreadSwitch::createManager((JKRHeap *)0x0);
  this_00 = (JKRThread *)JKernel::operator_new(0x68);
  if (this_00 != (JKRThread *)0x0) {
    pOVar9 = (OSThread *)os::OSGetCurrentThread();
    JKRThread::JKRThread(this_00,pOVar9,0);
  }
  pJVar2 = JFWSystem::systemConsole;
  *(undefined4 *)(JFWSystem::systemConsole + 0x58) = 3;
  *(undefined4 *)(pJVar2 + 0x40) = 0x10;
  *(undefined4 *)(pJVar2 + 0x44) = 0x2a;
  JUTException::appendMapFile("/maps/framework.map");
  JUTException::setPreUserCallback(myExceptionCallback);
  JUTException::setPostUserCallback(fault_callback_scroll);
  JKernel::JMath::JMANewSinTable(0xc);
  pJVar8 = m_Do_ext::mDoExt_getZeldaHeap();
  cMl::init(pJVar8);
  SComponent::cM_initRnd(100,100,100);
  os::OSGetCurrentThread();
  iVar6 = os::OSGetThreadPriority();
  mDoDvdThd::create(iVar6 + -2);
  m_Do_DVDError::mDoDvdErr_ThdInit();
  mDoMemCd_Ctrl_c::ThdInit(&m_Do_MemCard::g_mDoMemCd_control);
  return 1;
}

