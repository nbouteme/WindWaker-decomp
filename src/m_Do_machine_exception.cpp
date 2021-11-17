#include <m_Do_machine_exception.h>
#include <JUtility/JUTConsole.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <m_Do_machine_exception.h>
#include <JKernel/JKRAramHeap.h>
#include <DynamicLink.h>
#include <d_resorce.h>
#include <os/OSTime.h>


namespace m_Do_machine_exception {
undefined4 sConsole;

/* __stdcall print_f(char const *,
                     ...) */

void print_f
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
               undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
               undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16)

{
  byte in_cr1;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  undefined *local_14;
  undefined4 *local_10;
  
  if ((bool)(in_cr1 >> 1 & 1)) {
    local_58 = param_1;
    local_50 = param_2;
    local_48 = param_3;
    local_40 = param_4;
    local_38 = param_5;
    local_30 = param_6;
    local_28 = param_7;
    local_20 = param_8;
  }
  local_18 = 0x1000000;
  local_14 = &stack0x00000008;
  local_10 = &local_78;
  local_78 = param_9;
  local_74 = param_10;
  local_70 = param_11;
  local_6c = param_12;
  local_68 = param_13;
  local_64 = param_14;
  local_60 = param_15;
  local_5c = param_16;
  JUtility::JUTConsole_print_f_va_(sConsole,param_9,&local_18);
  return;
}


/* __stdcall print(char const *) */

void print(char *param_1)

{
  JUTConsole::print(sConsole,param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __stdcall dispHeapInfo(void) */

void dispHeapInfo(void)

{
  JKRHeap *this;
  JKRHeap *this_00;
  JKRHeap *this_01;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  JKRAramHeap *this_02;
  
  this_01 = m_Do_ext::archiveHeap;
  this_00 = m_Do_ext::zeldaHeap;
  this = m_Do_ext::gameHeap;
  uVar1 = JKRHeap::getFreeSize(m_Do_ext::zeldaHeap);
  uVar2 = JKRHeap::getFreeSize(this);
  uVar3 = JKRHeap::getFreeSize(this_01);
  uVar4 = JKRHeap::getTotalFreeSize(this_00);
  uVar5 = JKRHeap::getTotalFreeSize(this);
  uVar6 = JKRHeap::getTotalFreeSize(this_01);
  print("-- Heap Free / TotalFree (KB) --\n");
  print_f("  Zelda %5d / %5d\n",uVar1 >> 10,uVar4 >> 10);
  print_f("   Game %5d / %5d\n",uVar2 >> 10,uVar5 >> 10);
  print_f("Archive %5d / %5d\n",uVar3 >> 10,uVar6 >> 10);
  print("--------------------------------\n");
  this_02 = JKRAram::sAramObject->mpHeap;
  if (this_02 != (JKRAramHeap *)0x0) {
    this_02 = (JKRAramHeap *)JKRAramHeap::dump(this_02);
  }
  DynamicModuleControlBase::dump((DynamicModuleControlBase *)this_02);
  dRes_control_c::dump(&d_com_inf_game::g_dComIfG_gameInfo.mResCtrl);
  (*(code *)this_00->vtbl->dump_sort)(this_00);
  (*(code *)this->vtbl->dump_sort)(this);
  (*(code *)this_01->vtbl->dump_sort)(this_01);
  return;
}


/* __stdcall dispGameInfo(void) */

void dispGameInfo(void)

{
  print_f("Start StageName:RoomNo [%s:%d]\n",0x803c9d3c,
          (int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStartCode);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dispDateInfo(void) */

void dispDateInfo(void)

{
  OSCalendarTime local_30;
  
  print("------------- Date Infomation ---------\n");
  print(" FINAL VERSION\n");
  print("COMPILE USER: FINAL\n");
  print_f("COPYDATE   : %17s\n",mDoMain::COPYDATE_STRING);
  os::OSTicksToCalendarTime(mDoMain::sPowerOnTime,DAT_803f682c,&local_30);
  print_f("PowerOnTime: %04d/%2d/%2d %2d:%2d:%2d`%03d\"%03d\n",local_30.year,local_30.mon,
          local_30.mday,local_30.hour,local_30.min,local_30.sec,local_30.msec,local_30.usec);
  os::OSTicksToCalendarTime(_sHungUpTime,DAT_803f6834,&local_30);
  print_f("HungUpTime : %04d/%2d/%2d %2d:%2d:%2d`%03d\"%03d\n",local_30.year,local_30.mon,
          local_30.mday,local_30.hour,local_30.min,local_30.sec,local_30.msec,local_30.usec);
  os::OSTicksToCalendarTime
            (_sHungUpTime - ((uint)(DAT_803f6834 < DAT_803f682c) + mDoMain::sPowerOnTime),
             DAT_803f6834 - DAT_803f682c,&local_30);
  print_f("PlayTime   : %4d days, %2d:%2d:%2d`%03d\"%03d\n",local_30.yday,local_30.hour,local_30.min
          ,local_30.sec,local_30.msec,local_30.usec);
  print("---------------------------------------\n");
  return;
}


/* __stdcall dispConsoleToTerminal(void) */

void dispConsoleToTerminal(void)

{
  JUTConsole::dumpToTerminal(JFWSystem::systemConsole,0xffffffff);
  return;
}


/* __stdcall exception_addition(JUTConsole *) */

void exception_addition(undefined4 param_1)

{
  sConsole = param_1;
  dispHeapInfo();
  dispDateInfo();
  dispConsoleToTerminal();
  dispGameInfo();
  return;
}

