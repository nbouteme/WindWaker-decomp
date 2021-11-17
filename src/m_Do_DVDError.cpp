#include <m_Do_DVDError.h>
#include <os/OSTime.h>
#include <os/OSThread.h>
#include <m_Do_DVDError.h>
#include <os/OSAlarm.h>
#include <JKernel/JKRThread.h>
#include <JKernel/JKRHeap.h>
#include <dvd/dvd.h>
#include <m_Do_dvd_thread.h>


namespace m_Do_DVDError {
undefined DvdErr_thread;
undefined Alarm;
undefined1 mDoDvdErr_initialized;

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall mDoDvdErr_ThdInit(void) */

void mDoDvdErr_ThdInit(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (mDoDvdErr_initialized == '\0') {
    iVar1 = os::OSGetTime();
    os::OSGetCurrentThread();
    iVar2 = os::OSGetThreadPriority();
    os::OSCreateThread(&DvdErr_thread,mDoDvdErr_Watch,0,&Alarm,0x1000,iVar2 + -3,1);
    os::OSResumeThread((OSThread *)&DvdErr_thread);
    os::OSCreateAlarm(&Alarm);
    os::OSSetPeriodicAlarm(&Alarm,0x80020000,iVar1,param_2,0,DAT_800000f8 >> 2,AlarmHandler);
    mDoDvdErr_initialized = '\x01';
  }
  return;
}


/* __stdcall mDoDvdErr_ThdCleanup(void) */

void mDoDvdErr_ThdCleanup(void)

{
  if (mDoDvdErr_initialized != '\0') {
    os::OSCancelThread(&DvdErr_thread);
    os::OSCancelAlarm(&Alarm);
    mDoDvdErr_initialized = '\0';
  }
  return;
}


/* __stdcall mDoDvdErr_Watch(void *) */

void mDoDvdErr_Watch(void)

{
  OSThread *pOVar1;
  int iVar2;
  JKRThread JStack120;
  
  pOVar1 = (OSThread *)os::OSGetCurrentThread();
  JKRThread::JKRThread(&JStack120,pOVar1,0);
  JKRThread::_JKRThread(&JStack120);
  JKRHeap::becomeCurrentHeap((JKRHeap *)0x0);
  do {
    iVar2 = dvd::DVDGetDriveStatus();
    if (iVar2 == -1) {
      mDoDvdThd::suspend((mDoDvdThd *)&DAT_ffffffff);
    }
    os::OSSuspendThread(&DvdErr_thread);
  } while( true );
}


/* __stdcall AlarmHandler(OSAlarm *,
                          OSContext *) */

void AlarmHandler(void)

{
  os::OSResumeThread((OSThread *)&DvdErr_thread);
  return;
}

