#include <JUtility/JUTGba.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTGba.h>
#include <gba/GBA.h>
#include <os/OSMessage.h>
#include <os/OSThread.h>
#include <gba/GBAGetProcessStatus.h>
#include <JKernel/JKRThread.h>
#include <os/OSTime.h>
#include <os/OSAlarm.h>
#include <os/OSInterrupt.h>
#include <gba/GBAJoyBoot.h>
#include <si/SIBios.h>
#include <gba/GBARead.h>
#include <gba/GBAWrite.h>
#include <JUTGba.h>

undefined1 JUTGba;

/* __thiscall JUTGba::JUTGba(void) */

void __thiscall JUTGba::JUTGba(JUTGba *this)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::create(void) */

JUTGba * __thiscall JUTGba::create(JUTGba *this)

{
  ulong uVar1;
  JUTGba *pJVar2;
  OSMessageQueue *pOVar3;
  OSMessageQueue *pOVar4;
  OSThread *pOVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if (_sManager != (JUTGba *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTGba.cpp",0x3d,"sManager == 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0x3d,&DAT_8036c9b9);
  }
  pJVar2 = (JUTGba *)JKernel::operator_new(0x4de0);
  if (pJVar2 != (JUTGba *)0x0) {
    JUTGba(pJVar2);
  }
  _sManager = pJVar2;
  gba::GBAInit();
  m_Do_printf::OSReport(":::GBA: Init()\n");
  pOVar5 = (OSThread *)0x0;
  iVar6 = 0;
  do {
    pOVar3 = (OSMessageQueue *)(_sManager + iVar6 + 0x4c60);
    iVar9 = 0x5c;
    pOVar4 = pOVar3;
    do {
      *(undefined *)&(pOVar4->queueSend).head = 0;
      pOVar4 = (OSMessageQueue *)((int)&(pOVar4->queueSend).head + 1);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    pOVar3[1].queueReceive.head = pOVar5;
    pOVar3[1].queueReceive.tail = (OSThread *)0x0;
    pOVar3[1].msgArray = (OSMessage *)0x0;
    pOVar3[1].queueSend.tail = (OSThread *)0x0;
    os::OSInitMessageQueue(pOVar3,(OSMessage *)(pOVar3 + 1),1);
    pOVar5 = (OSThread *)&pOVar5->field_0x1;
    iVar6 = iVar6 + 0x5c;
  } while ((int)pOVar5 < 4);
  iVar6 = 0;
  iVar8 = 0;
  iVar7 = 0;
  iVar9 = 0;
  do {
    pJVar2 = _sManager + iVar9 + 0x4c60;
    m_Do_printf::OSReport(":::GBA: Create Thread %d\n",iVar6);
    os::OSCreateThread(_sManager + iVar7,gbaThreadMain,pJVar2,_sManager + iVar8 + 0x1c60,0x1000,8,0)
    ;
    os::OSResumeThread((OSThread *)(_sManager + iVar7));
    iVar6 = iVar6 + 1;
    iVar8 = iVar8 + 0x1000;
    iVar7 = iVar7 + 0x318;
    iVar9 = iVar9 + 0x5c;
  } while (iVar6 < 4);
  return _sManager;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::result_common(int,
                                    unsigned long,
                                    unsigned long *) */

undefined4 __thiscall JUTGba::result_common(JUTGba *this,int param_1,ulong param_2,ulong *param_3)

{
  int iVar1;
  
  iVar1 = _sManager + param_1 * 0x5c + 0x4c60;
  if (*(ulong *)(iVar1 + 0x24) != param_2) {
    return 0xffffffff;
  }
  if (*(char *)(iVar1 + 0x3c) != '\x01') {
    *param_3 = 0;
    return 0xfffffffe;
  }
  *param_3 = *(ulong *)(iVar1 + 0x40);
  return 0;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::resultStatus_common(int,
                                          unsigned long,
                                          unsigned char *) */

undefined4 __thiscall
JUTGba::resultStatus_common(JUTGba *this,int param_1,ulong param_2,uchar *param_3)

{
  int iVar1;
  
  iVar1 = _sManager + param_1 * 0x5c + 0x4c60;
  if (*(ulong *)(iVar1 + 0x24) != param_2) {
    return 0xffffffff;
  }
  if (*(char *)(iVar1 + 0x3c) != '\x01') {
    return 0xfffffffe;
  }
  if ((*(int *)(iVar1 + 0x40) == 0) && (param_3 != (uchar *)0x0)) {
    *param_3 = *(uchar *)(iVar1 + 0x44);
  }
  return *(undefined4 *)(iVar1 + 0x40);
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::doJoyBoot(int,
                                long,
                                long,
                                unsigned char *,
                                unsigned long,
                                void *(JUTGbaParam *,void *),
                                void *) */

void __thiscall
JUTGba::doJoyBoot(JUTGba *this,int param_1,long param_2,long param_3,uchar *param_4,ulong param_5,
                 FuncDef592 *param_6,void *param_7)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  
  if (_sManager == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JUTGba.cpp",0xb7,"sManager != 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0xb7,&DAT_8036c9b9);
  }
  bVar1 = false;
  if ((param_4 != (uchar *)0x0) && (param_5 != 0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JUTGba.cpp",0xb8,"program != 0 && length != 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0xb8,&DAT_8036c9b9);
  }
  iVar3 = _sManager + param_1 * 0x5c + 0x4c60;
  *(uchar **)(iVar3 + 0x2c) = param_4;
  *(ulong *)(iVar3 + 0x30) = param_5;
  *(long *)(iVar3 + 0x34) = param_2;
  *(long *)(iVar3 + 0x38) = param_3;
  *(FuncDef592 **)(iVar3 + 0x4c) = param_6;
  *(void **)(iVar3 + 0x50) = param_7;
  *(undefined *)(iVar3 + 0x3c) = 0;
  os::OSSendMessage(iVar3,1,1);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::resultJoyBoot(int,
                                    unsigned char *) */

undefined4 __thiscall JUTGba::resultJoyBoot(JUTGba *this,int param_1,uchar *param_2)

{
  ulong uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (_sManager == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTGba.cpp",0xd4,"sManager != 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0xd4,&DAT_8036c9b9);
  }
  iVar2 = _sManager + param_1 * 0x5c + 0x4c60;
  if (*(int *)(iVar2 + 0x24) == 1) {
    if (*(char *)(iVar2 + 0x3c) == '\0') {
      if (*(int *)(iVar2 + 0x40) == 1) {
        if (param_2 != (uchar *)0x0) {
          *param_2 = 0xff;
        }
      }
      else {
        if (param_2 != (uchar *)0x0) {
          gba::GBAGetProcessStatus(param_1,param_2);
        }
      }
      uVar3 = 0xfffffffe;
    }
    else {
      if (*(int *)(iVar2 + 0x40) == 0) {
        if (param_2 != (uchar *)0x0) {
          *param_2 = 'd';
        }
      }
      else {
        if (param_2 != (uchar *)0x0) {
          *param_2 = '\0';
        }
      }
      uVar3 = *(undefined4 *)(iVar2 + 0x40);
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::doInitProbe(int,
                                  void *(JUTGbaParam *,void *),
                                  void *) */

void __thiscall JUTGba::doInitProbe(JUTGba *this,int param_1,FuncDef593 *param_2,void *param_3)

{
  ulong uVar1;
  int iVar2;
  
  if (_sManager == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTGba.cpp",0xff,"sManager != 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0xff,&DAT_8036c9b9);
  }
  iVar2 = _sManager + param_1 * 0x5c + 0x4c60;
  *(FuncDef593 **)(iVar2 + 0x4c) = param_2;
  *(void **)(iVar2 + 0x50) = param_3;
  *(undefined *)(iVar2 + 0x3c) = 0;
  os::OSSendMessage(iVar2,2,1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::resultInitProbe(int,
                                      unsigned long *) */

void __thiscall JUTGba::resultInitProbe(JUTGba *this,int param_1,ulong *param_2)

{
  ulong uVar1;
  
  if (_sManager == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTGba.cpp",0x116,"sManager != 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0x116,&DAT_8036c9b9);
  }
  result_common(this,param_1,2,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::doProbe(int,
                              void *(JUTGbaParam *,void *),
                              void *) */

void __thiscall JUTGba::doProbe(JUTGba *this,int param_1,FuncDef594 *param_2,void *param_3)

{
  ulong uVar1;
  int iVar2;
  
  if (_sManager == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTGba.cpp",0x11f,"sManager != 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0x11f,&DAT_8036c9b9);
  }
  iVar2 = _sManager + param_1 * 0x5c + 0x4c60;
  *(FuncDef594 **)(iVar2 + 0x4c) = param_2;
  *(void **)(iVar2 + 0x50) = param_3;
  *(undefined *)(iVar2 + 0x3c) = 0;
  os::OSSendMessage(iVar2,3,1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::resultProbe(int,
                                  unsigned long *) */

void __thiscall JUTGba::resultProbe(JUTGba *this,int param_1,ulong *param_2)

{
  ulong uVar1;
  
  if (_sManager == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTGba.cpp",0x136,"sManager != 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0x136,&DAT_8036c9b9);
  }
  result_common(this,param_1,3,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::doReset(int,
                              void *(JUTGbaParam *,void *),
                              void *) */

void __thiscall JUTGba::doReset(JUTGba *this,int param_1,FuncDef595 *param_2,void *param_3)

{
  ulong uVar1;
  int iVar2;
  
  if (_sManager == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTGba.cpp",0x140,"sManager != 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0x140,&DAT_8036c9b9);
  }
  iVar2 = _sManager + param_1 * 0x5c + 0x4c60;
  *(FuncDef595 **)(iVar2 + 0x4c) = param_2;
  *(void **)(iVar2 + 0x50) = param_3;
  *(undefined *)(iVar2 + 0x3c) = 0;
  os::OSSendMessage(iVar2,4,1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::resultReset(int,
                                  unsigned char *) */

void __thiscall JUTGba::resultReset(JUTGba *this,int param_1,uchar *param_2)

{
  ulong uVar1;
  
  if (_sManager == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTGba.cpp",0x154,"sManager != 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0x154,&DAT_8036c9b9);
  }
  resultStatus_common(this,param_1,4,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::doRead(int,
                             unsigned char *,
                             void *(JUTGbaParam *,void *),
                             void *) */

void __thiscall
JUTGba::doRead(JUTGba *this,int param_1,uchar *param_2,FuncDef596 *param_3,void *param_4)

{
  ulong uVar1;
  int iVar2;
  
  if (_sManager == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTGba.cpp",0x15e,"sManager != 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0x15e,&DAT_8036c9b9);
  }
  iVar2 = _sManager + param_1 * 0x5c + 0x4c60;
  *(FuncDef596 **)(iVar2 + 0x4c) = param_3;
  *(void **)(iVar2 + 0x50) = param_4;
  *(undefined *)(iVar2 + 0x3c) = 0;
  *(uchar **)(iVar2 + 0x48) = param_2;
  os::OSSendMessage(iVar2,5,1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::resultRead(int,
                                 unsigned char *) */

void __thiscall JUTGba::resultRead(JUTGba *this,int param_1,uchar *param_2)

{
  ulong uVar1;
  
  if (_sManager == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTGba.cpp",0x173,"sManager != 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0x173,&DAT_8036c9b9);
  }
  resultStatus_common(this,param_1,5,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::doWrite(int,
                              unsigned char *,
                              void *(JUTGbaParam *,void *),
                              void *) */

void __thiscall
JUTGba::doWrite(JUTGba *this,int param_1,uchar *param_2,FuncDef597 *param_3,void *param_4)

{
  ulong uVar1;
  int iVar2;
  
  if (_sManager == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTGba.cpp",0x17d,"sManager != 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0x17d,&DAT_8036c9b9);
  }
  iVar2 = _sManager + param_1 * 0x5c + 0x4c60;
  *(FuncDef597 **)(iVar2 + 0x4c) = param_3;
  *(void **)(iVar2 + 0x50) = param_4;
  *(undefined *)(iVar2 + 0x3c) = 0;
  *(uchar **)(iVar2 + 0x48) = param_2;
  os::OSSendMessage(iVar2,6,1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::resultWrite(int,
                                  unsigned char *) */

void __thiscall JUTGba::resultWrite(JUTGba *this,int param_1,uchar *param_2)

{
  ulong uVar1;
  
  if (_sManager == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTGba.cpp",0x193,"sManager != 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0x193,&DAT_8036c9b9);
  }
  resultStatus_common(this,param_1,6,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::doGetStatus(int,
                                  void *(JUTGbaParam *,void *),
                                  void *) */

void __thiscall JUTGba::doGetStatus(JUTGba *this,int param_1,FuncDef598 *param_2,void *param_3)

{
  ulong uVar1;
  int iVar2;
  
  if (_sManager == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTGba.cpp",0x19d,"sManager != 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0x19d,&DAT_8036c9b9);
  }
  iVar2 = _sManager + param_1 * 0x5c + 0x4c60;
  *(FuncDef598 **)(iVar2 + 0x4c) = param_2;
  *(void **)(iVar2 + 0x50) = param_3;
  *(undefined *)(iVar2 + 0x3c) = 0;
  os::OSSendMessage(iVar2,7,1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::resultGetStatus(int,
                                      unsigned char *) */

void __thiscall JUTGba::resultGetStatus(JUTGba *this,int param_1,uchar *param_2)

{
  ulong uVar1;
  
  if (_sManager == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JUTGba.cpp",0x1b2,"sManager != 0");
    m_Do_printf::OSPanic("JUTGba.cpp",0x1b2,&DAT_8036c9b9);
  }
  resultStatus_common(this,param_1,7,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGba::gbaThreadMain(void *) */

undefined4 __thiscall JUTGba::gbaThreadMain(JUTGba *this,void *param_1)

{
  OSThread *pOVar1;
  int iVar2;
  undefined4 extraout_r4;
  long_long extraout_r4_00;
  long_long extraout_r4_01;
  long_long extraout_r4_02;
  long_long extraout_r4_03;
  long_long extraout_r4_04;
  long_long extraout_r4_05;
  long_long extraout_r4_06;
  long_long extraout_r4_07;
  long_long extraout_r4_08;
  long_long lVar3;
  undefined8 uVar4;
  JUTGba *local_98 [2];
  int local_90;
  uint local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  JKRThread JStack120;
  
  pOVar1 = (OSThread *)os::OSGetCurrentThread();
  JKRThread::JKRThread(&JStack120,pOVar1,0);
  JKRThread::_JKRThread(&JStack120);
  JKRHeap::becomeCurrentHeap((JKRHeap *)0x0);
  local_98[0] = this;
  do {
    uVar4 = os::OSReceiveMessage(this,&local_88,0);
    local_7c = (int)((ulonglong)uVar4 >> 0x20);
    if (local_7c == 0) {
      this[0x54] = (JUTGba)0x0;
      os::OSReceiveMessage(this,&local_88,1);
      uVar4 = CONCAT44(local_7c,extraout_r4);
    }
    this[0x54] = (JUTGba)0x1;
    *(undefined4 *)(this + 0x40) = 0;
    *(int *)(this + 0x24) = local_88;
    local_90 = os::OSGetTime();
    local_7c = (int)((ulonglong)uVar4 >> 0x20);
    local_8c = (uint)uVar4;
    local_84 = 0;
    local_80 = 0;
    if (local_88 == 8) {
      gbaThread_Destroy(_sManager,(JUTGbaThreadVar *)local_98);
      local_7c = (int)((ulonglong)uVar4 >> 0x20);
      local_8c = (uint)uVar4;
      this[0x3c] = (JUTGba)0x1;
      return 0;
    }
    while( true ) {
      local_7c = (int)((ulonglong)uVar4 >> 0x20);
      local_84 = 0;
      if (*(int *)(this + 0x58) != 0) break;
      iVar2 = os::OSGetTime();
      local_7c = (int)((ulonglong)uVar4 >> 0x20);
      if (0x80000000 <
          (uint)(((DAT_800000f8 >> 2) / 1000) * 4000 < (uint)uVar4 - local_8c) +
          (iVar2 - ((uint)((uint)uVar4 < local_8c) + local_90) ^ 0x80000000)) {
        if (*(int *)(this + 0x40) != 3) {
          *(undefined4 *)(this + 0x40) = 1;
          this[0x3c] = (JUTGba)0x1;
        }
        break;
      }
      switch(local_88) {
      default:
        m_Do_printf::OSPanic("JUTGba.cpp",0x26f,"UNKNOWN GBA COMMAND.");
        lVar3 = extraout_r4_07;
        break;
      case 1:
        gbaThread_JoyBoot(_sManager,(JUTGbaThreadVar *)local_98);
        lVar3 = extraout_r4_00;
        break;
      case 2:
        gbaThread_InitProbe(_sManager,(JUTGbaThreadVar *)local_98);
        lVar3 = extraout_r4_01;
        break;
      case 3:
        gbaThread_Probe(_sManager,(JUTGbaThreadVar *)local_98);
        lVar3 = extraout_r4_02;
        break;
      case 4:
        gbaThread_Reset(_sManager,(JUTGbaThreadVar *)local_98);
        lVar3 = extraout_r4_03;
        break;
      case 5:
        gbaThread_Read(_sManager,(JUTGbaThreadVar *)local_98);
        lVar3 = extraout_r4_04;
        break;
      case 6:
        gbaThread_Write(_sManager,(JUTGbaThreadVar *)local_98);
        lVar3 = extraout_r4_05;
        break;
      case 7:
        gbaThread_GetStatus(_sManager,(JUTGbaThreadVar *)local_98);
        lVar3 = extraout_r4_06;
      }
      if (local_84 == 0) {
        if (*(code **)(this + 0x4c) != (code *)0x0) {
          (**(code **)(this + 0x4c))(this,*(undefined4 *)(this + 0x50));
        }
        break;
      }
      if (local_80 != 0) {
        gbaThread_sleep(_sManager,lVar3);
        lVar3 = extraout_r4_08;
      }
      uVar4 = CONCAT44(local_7c,lVar3);
      local_88 = local_84;
    }
  } while( true );
}


namespace JUtility {

/* __stdcall JUTGBAThreadAlarmHandler(OSAlarm *,
                                      OSContext *) */

void JUTGBAThreadAlarmHandler(int param_1)

{
  os::OSResumeThread(*(OSThread **)(param_1 + 0x28));
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JUTGba::gbaThread_sleep(long long) */

void __thiscall JUTGba::gbaThread_sleep(JUTGba *this,long_long param_1)

{
  undefined4 uVar1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined auStack72 [40];
  undefined4 local_20;
  
  os::OSCreateAlarm(auStack72);
  local_20 = os::OSGetCurrentThread();
  uVar1 = os::OSDisableInterrupts();
  os::OSSetAlarm(auStack72,0x802d0000,in_r5,in_r6,JUtility::JUTGBAThreadAlarmHandler);
  os::OSSuspendThread(local_20);
  os::OSRestoreInterrupts(uVar1);
  return;
}


/* __thiscall JUTGba::gbaThread_Destroy(JUTGbaThreadVar *) */

void __thiscall JUTGba::gbaThread_Destroy(JUTGba *this,JUTGbaThreadVar *param_1)

{
  *(undefined4 *)(*(int *)param_1 + 0x40) = 0;
  return;
}


/* __thiscall JUTGba::gbaThread_JoyBoot(JUTGbaThreadVar *) */

undefined4 __thiscall JUTGba::gbaThread_JoyBoot(JUTGba *this,JUTGbaThreadVar *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)param_1;
  uVar2 = gba::GBAJoyBoot(*(undefined4 *)(iVar3 + 0x28),*(undefined4 *)(iVar3 + 0x34),
                          *(undefined4 *)(iVar3 + 0x38),*(undefined4 *)(iVar3 + 0x2c),
                          *(undefined4 *)(iVar3 + 0x30),iVar3 + 0x44);
  *(undefined4 *)(iVar3 + 0x40) = uVar2;
  iVar1 = *(int *)(iVar3 + 0x40);
  if (iVar1 == 0) {
    *(undefined *)(iVar3 + 0x3c) = 1;
  }
  else {
    if ((iVar1 == 1) || (iVar1 == 3)) {
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
      *(uint *)(param_1 + 0x18) = ((DAT_800000f8 >> 2) / 1000) * 0xf;
    }
  }
  return *(undefined4 *)(iVar3 + 0x40);
}


/* __thiscall JUTGba::gbaThread_InitProbe(JUTGbaThreadVar *) */

undefined4 __thiscall JUTGba::gbaThread_InitProbe(JUTGba *this,JUTGbaThreadVar *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar3 = *(int *)param_1;
  uVar4 = si::SIProbe(*(undefined4 *)(iVar3 + 0x28));
  uVar2 = (uint)uVar4;
  *(int *)(iVar3 + 0x40) = (int)((ulonglong)uVar4 >> 0x20);
  iVar1 = os::OSGetTime();
  if ((uint)(((DAT_800000f8 >> 2) / 1000) * 1000 < uVar2 - *(uint *)(param_1 + 0xc)) +
      (iVar1 - ((uint)(uVar2 < *(uint *)(param_1 + 0xc)) + *(int *)(param_1 + 8)) ^ 0x80000000) <
      0x80000001) {
    if (*(int *)(iVar3 + 0x40) == 0x80) {
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
      *(uint *)(param_1 + 0x18) = ((DAT_800000f8 >> 2) / 1000) * 0xf;
    }
    else {
      if (*(int *)(iVar3 + 0x40) == 8) {
        *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
        *(uint *)(param_1 + 0x18) = ((DAT_800000f8 >> 2) / 1000) * 0x32;
      }
      else {
        *(undefined *)(iVar3 + 0x3c) = 1;
      }
    }
  }
  else {
    *(undefined4 *)(iVar3 + 0x40) = 8;
    *(undefined *)(iVar3 + 0x3c) = 1;
  }
  return *(undefined4 *)(iVar3 + 0x40);
}


/* __thiscall JUTGba::gbaThread_Probe(JUTGbaThreadVar *) */

undefined4 __thiscall JUTGba::gbaThread_Probe(JUTGba *this,JUTGbaThreadVar *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)param_1;
  uVar1 = si::SIProbe(*(undefined4 *)(iVar2 + 0x28));
  *(undefined4 *)(iVar2 + 0x40) = uVar1;
  if (*(int *)(iVar2 + 0x40) == 0x80) {
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x10);
    *(uint *)(param_1 + 0x18) = ((DAT_800000f8 >> 2) / 1000) * 0xf;
  }
  else {
    *(undefined *)(iVar2 + 0x3c) = 1;
  }
  return *(undefined4 *)(iVar2 + 0x40);
}


/* __thiscall JUTGba::gbaThread_Reset(JUTGbaThreadVar *) */

undefined4 __thiscall JUTGba::gbaThread_Reset(JUTGba *this,JUTGbaThreadVar *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)param_1;
  uVar1 = gba::GBAReset(*(undefined4 *)(iVar2 + 0x28),iVar2 + 0x44);
  *(undefined4 *)(iVar2 + 0x40) = uVar1;
  *(undefined *)(iVar2 + 0x3c) = 1;
  return *(undefined4 *)(iVar2 + 0x40);
}


/* __thiscall JUTGba::gbaThread_Read(JUTGbaThreadVar *) */

undefined4 __thiscall JUTGba::gbaThread_Read(JUTGba *this,JUTGbaThreadVar *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)param_1;
  uVar1 = gba::GBARead(*(undefined4 *)(iVar2 + 0x28),*(undefined4 *)(iVar2 + 0x48),iVar2 + 0x44);
  *(undefined4 *)(iVar2 + 0x40) = uVar1;
  *(undefined *)(iVar2 + 0x3c) = 1;
  return *(undefined4 *)(iVar2 + 0x40);
}


/* __thiscall JUTGba::gbaThread_Write(JUTGbaThreadVar *) */

undefined4 __thiscall JUTGba::gbaThread_Write(JUTGba *this,JUTGbaThreadVar *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)param_1;
  uVar1 = gba::GBAWrite(*(undefined4 *)(iVar2 + 0x28),*(undefined4 *)(iVar2 + 0x48),iVar2 + 0x44);
  *(undefined4 *)(iVar2 + 0x40) = uVar1;
  *(undefined *)(iVar2 + 0x3c) = 1;
  return *(undefined4 *)(iVar2 + 0x40);
}


/* __thiscall JUTGba::gbaThread_GetStatus(JUTGbaThreadVar *) */

undefined4 __thiscall JUTGba::gbaThread_GetStatus(JUTGba *this,JUTGbaThreadVar *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)param_1;
  uVar1 = gba::GBAGetStatus(*(undefined4 *)(iVar2 + 0x28),iVar2 + 0x44);
  *(undefined4 *)(iVar2 + 0x40) = uVar1;
  *(undefined *)(iVar2 + 0x3c) = 1;
  return *(undefined4 *)(iVar2 + 0x40);
}

