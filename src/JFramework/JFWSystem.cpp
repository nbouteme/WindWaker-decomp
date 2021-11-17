#include <JFramework/JFWSystem.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <os/OS.h>
#include <dvd/dvd.h>
#include <JKernel/JKRExpHeap.h>
#include <JFramework/JFWSystem.h>
#include <JKernel/JKRAram.h>
#include <JKernel/JKRHeap.h>
#include <os/OSThread.h>
#include <JKernel/JKRThread.h>
#include <JUtility/JUTVideo.h>
#include <JUtility/JUTGraphFifo.h>
#include <JUtility/JUTGamePad.h>
#include <JUtility/JUTDirectPrint.h>
#include <JUtility/JUTException.h>
#include <JUtility/JUTResFont.h>
#include <JUtility/JUTDbPrint.h>
#include <JUtility/JUTConsole.h>
#include <JFWSystem.h>

struct JKRHeap * JFWSystem;
struct JKRHeap * JFWSystem;
undefined1 JFWSystem;
struct JUTDbPrint * JFWSystem;
struct JUTResFont * JFWSystem;
undefined1 JFWSystem;
struct JUTConsole * JFWSystem;
byte JFWSystem;

/* __thiscall JFWSystem::firstInit(void) */

void __thiscall JFWSystem::firstInit(JFWSystem *this)

{
  ulong uVar1;
  undefined in_r5;
  
  if (rootHeap != (JKRHeap *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JFWSystem.cpp",0x50,"rootHeap == 0");
    in_r5 = 0xc;
    this = (JFWSystem *)m_Do_printf::OSPanic("JFWSystem.cpp",0x50);
  }
  os::OSInit(this);
  dvd::DVDInit();
  rootHeap = (JKRHeap *)JKRExpHeap::createRoot((JKRExpHeap *)CSetUpParam::maxStdHeaps,0,(bool)in_r5)
  ;
  systemHeap = (JKRHeap *)JKRExpHeap::create(CSetUpParam::sysHeapSize,rootHeap,false);
  return;
}


/* WARNING: Removing unreachable block (ram,0x802551a0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JFWSystem::init(void) */

int __thiscall JFWSystem::init(JFWSystem *this)

{
  ulong uVar1;
  JKRThread *this_00;
  OSThread *pOVar2;
  JUTDirectPrint *this_01;
  JUTResFont *pJVar3;
  JUTConsole *pJVar4;
  uint uVar5;
  JUTException *this_02;
  int iVar6;
  undefined4 uVar7;
  undefined8 in_f31;
  double dVar8;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (sInitCalled != 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JFWSystem.cpp",0x65,"sInitCalled == false");
    this = (JFWSystem *)m_Do_printf::OSPanic("JFWSystem.cpp",0x65,&DAT_8036630c);
  }
  if (rootHeap == (JKRHeap *)0x0) {
    firstInit(this);
  }
  sInitCalled = 1;
  pOVar2 = (OSThread *)CSetUpParam::aramGraphBufSize;
  JKRAram::create(CSetUpParam::aramAudioBufSize,CSetUpParam::aramGraphBufSize,
                  CSetUpParam::streamPriority,CSetUpParam::decompPriority,
                  CSetUpParam::aPiecePriority);
  this_00 = (JKRThread *)JKernel::operator_new(0x68);
  if (this_00 != (JKRThread *)0x0) {
    pOVar2 = (OSThread *)os::OSGetCurrentThread();
    JKRThread::JKRThread(this_00,pOVar2,4);
  }
  _mainThread = this_00;
  JUTVideo::createManager((JUTVideo *)CSetUpParam::renderMode,(_GXRenderModeObj *)pOVar2);
  iVar6 = CSetUpParam::fifoBufSize;
  this_01 = (JUTDirectPrint *)JKernel::operator_new(0x1c);
  if (this_01 != (JUTDirectPrint *)0x0) {
    JUTGraphFifo::JUTGraphFifo((JUTGraphFifo *)this_01,iVar6);
  }
  JUTGamePad::init();
  JUTDirectPrint::start(this_01);
  JUTAssertion::create();
  JUTException::create(this_01);
  pJVar3 = (JUTResFont *)JKernel::operator_new(0x70);
  if (pJVar3 != (JUTResFont *)0x0) {
    JUTResFont::JUTResFont(pJVar3,(ResFONT *)CSetUpParam::systemFontRes,(JKRHeap *)0x0);
  }
  systemFont = pJVar3;
  debugPrint = (JUTDbPrint *)JUTDbPrint::start((JUTFont *)0x0,(JKRHeap *)0x0);
  JUTDbPrint::changeFont(debugPrint,&systemFont->parent);
  _systemConsoleManager = JUTConsoleManager::createManager((JKRHeap *)0x0);
  pJVar4 = JUTConsole::create(0x3c,200,(JKRHeap *)0x0);
  pJVar3 = systemFont;
  systemConsole = pJVar4;
  *(JUTResFont **)(pJVar4 + 0x4c) = systemFont;
  uVar5 = (*(code *)((pJVar3->parent).vtbl)->getHeight)(pJVar3);
  dVar8 = (double)(float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - JFramework::_2209);
  uVar5 = (*(code *)((pJVar3->parent).vtbl)->getWidth)(pJVar3);
  *(float *)(pJVar4 + 0x50) =
       (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - JFramework::_2209);
  *(float *)(pJVar4 + 0x54) = (float)dVar8;
  if (*(ushort *)(CSetUpParam::renderMode + 6) < 300) {
    uVar5 = (*(code *)((systemFont->parent).vtbl)->getHeight)();
    dVar8 = (double)(JFramework::_2206 *
                    (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - JFramework::_2209));
    uVar5 = (*(code *)((systemFont->parent).vtbl)->getWidth)();
    pJVar4 = systemConsole;
    *(float *)(systemConsole + 0x50) =
         JFramework::_2207 *
         (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - JFramework::_2209);
    *(float *)(pJVar4 + 0x54) = (float)dVar8;
    pJVar4 = systemConsole;
    *(undefined4 *)(systemConsole + 0x40) = 0x14;
    *(undefined4 *)(pJVar4 + 0x44) = 0x19;
  }
  else {
    uVar5 = (*(code *)((systemFont->parent).vtbl)->getHeight)();
    dVar8 = (double)(float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - JFramework::_2209);
    uVar5 = (*(code *)((systemFont->parent).vtbl)->getWidth)();
    pJVar4 = systemConsole;
    *(float *)(systemConsole + 0x50) =
         JFramework::_2207 *
         (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - JFramework::_2209);
    *(float *)(pJVar4 + 0x54) = (float)dVar8;
    pJVar4 = systemConsole;
    *(undefined4 *)(systemConsole + 0x40) = 0x14;
    *(undefined4 *)(pJVar4 + 0x44) = 0x32;
  }
  pJVar4 = systemConsole;
  *(undefined4 *)(systemConsole + 0x48) = 0x19;
  if (*(uint *)(pJVar4 + 0x24) < *(uint *)(pJVar4 + 0x48)) {
    *(uint *)(pJVar4 + 0x48) = *(uint *)(pJVar4 + 0x24);
  }
  systemConsole[100] = (JUTConsole)0x0;
  *(undefined4 *)(systemConsole + 0x58) = 3;
  JUtility::JUTSetReportConsole(systemConsole);
  JUtility::JUTSetWarningConsole(systemConsole);
  uVar1 = 4;
  this_02 = (JUTException *)JKRHeap::alloc(systemHeap,CSetUpParam::exConsoleBufferSize,4);
  iVar6 = JUTException::createConsole(this_02,(void *)CSetUpParam::exConsoleBufferSize,uVar1);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return iVar6;
}

