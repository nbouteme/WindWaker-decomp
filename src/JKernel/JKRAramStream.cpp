#include <JKernel/JKRAramStream.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRAramStream.h>
#include <JKernel/JKRThread.h>
#include <os/OSThread.h>
#include <os/OSMessage.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <m_Do_printf.h>
#include <JSupport/JSUInputStream.h>
#include <JKernel/JKRAramPiece.h>
#include <Demangler/JKRAramStreamCommand.h>
#include <JKRAramStream.h>
#include <Demangler/JSURandomInputStream.h>

undefined1 JKRAramStream;
undefined1 JKRAramStream;
undefined1 JKRAramStream;
undefined1 JKRAramStream;

namespace JKRAramStream {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall create(long) */

JKRAramStream * create(long param_1)

{
  JKRAramStream *this;
  JKRHeap *in_r6;
  
  if (_sAramStreamObject == (JKRAramStream *)0x0) {
    this = (JKRAramStream *)JKernel::operator_new(0x68,JKRHeap::sSystemHeap,0);
    if (this != (JKRAramStream *)0x0) {
      JKRAramStream(this,param_1);
    }
    _sAramStreamObject = this;
    setTransBuffer((JKRAramStream *)0x0,(uchar *)0x0,0,in_r6);
  }
  return _sAramStreamObject;
}

}

/* __thiscall JKRAramStream::JKRAramStream(long) */

void __thiscall JKRAramStream::JKRAramStream(JKRAramStream *this,long param_1)

{
  JKRThread::JKRThread((JKRThread *)this,0x4000,0x10,param_1);
  *(undefined1 **)this = &__vt;
  os::OSResumeThread(*(OSThread **)(this + 0x2c));
  return;
}


/* __thiscall JKRAramStream::~JKRAramStream(void) */

void __thiscall JKRAramStream::_JKRAramStream(JKRAramStream *this)

{
  short in_r4;
  
  if (this != (JKRAramStream *)0x0) {
    *(undefined1 **)this = &__vt;
    JKRThread::_JKRThread((JKRThread *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JKRAramStream::run(void) */

void __thiscall JKRAramStream::run(JKRAramStream *this)

{
  int iVar1;
  JKRAramStreamCommand *extraout_r4;
  int *local_18 [5];
  
  os::OSInitMessageQueue((OSMessageQueue *)&sMessageQueue,(OSMessage *)&sMessageBuffer,4);
  do {
    while( true ) {
      os::OSReceiveMessage(&sMessageQueue,local_18,1);
      iVar1 = *local_18[0];
      if (iVar1 != 2) break;
      writeToAram((JKRAramStream *)local_18[0],extraout_r4);
    }
    if ((iVar1 < 2) && (0 < iVar1)) {
      readFromAram((JKRAramStream *)local_18[0]);
    }
  } while( true );
}


/* __thiscall JKRAramStream::readFromAram(void) */

undefined4 __thiscall JKRAramStream::readFromAram(JKRAramStream *this)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall JKRAramStream::writeToAram(JKRAramStreamCommand *) */

int __thiscall JKRAramStream::writeToAram(JKRAramStream *this,JKRAramStreamCommand *param_1)

{
  ulong uVar1;
  ssize_t sVar2;
  JKRAramBlock *in_r8;
  void *__buf;
  ulong size;
  long lVar3;
  JKRHeap *pHeap;
  uint __nbytes;
  ulong uVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  
  uVar6 = *(uint *)(this + 8);
  lVar3 = *(long *)(this + 0x14);
  iVar5 = 0;
  uVar4 = *(ulong *)(this + 4);
  __buf = *(void **)(this + 0x18);
  uVar1 = *(ulong *)(this + 0x1c);
  pHeap = *(JKRHeap **)(this + 0x20);
  if (__buf == (void *)0x0) {
    size = 0x400;
    if (uVar1 != 0) {
      size = uVar1;
    }
    if (pHeap == (JKRHeap *)0x0) {
      uVar7 = JKRHeap::alloc(size,-0x20,(JKRHeap *)0x0);
      *(int *)(this + 0x18) = (int)((ulonglong)uVar7 >> 0x20);
    }
    else {
      uVar7 = JKRHeap::alloc(size,-0x20,pHeap);
      *(int *)(this + 0x18) = (int)((ulonglong)uVar7 >> 0x20);
    }
    __buf = (void *)((ulonglong)uVar7 >> 0x20);
    param_1 = (JKRAramStreamCommand *)uVar7;
    *(ulong *)(this + 0x1c) = size;
    this[0x24] = (JKRAramStream)0x1;
  }
  else {
    size = 0x400;
    if (uVar1 != 0) {
      size = uVar1;
    }
    *(ulong *)(this + 0x1c) = size;
    this[0x24] = (JKRAramStream)0x0;
  }
  if (__buf == (void *)0x0) {
    if (pHeap == (JKRHeap *)0x0) {
      (*(code *)JKRHeap::sCurrentHeap->vtbl->dump)();
    }
    else {
      (*(code *)pHeap->vtbl->dump)(pHeap,param_1);
    }
    m_Do_printf::OSReport(":::Cannot alloc memory [%s][%d]\n","JKRAramStream.cpp",0xa8);
    m_Do_printf::OSPanic("JKRAramStream.cpp",0xa9,"abort\n");
  }
  if (__buf != (void *)0x0) {
    JSURandomInputStream::seek(*(JSURandomInputStream **)(this + 0x10),lVar3,0);
    for (; uVar6 != 0; uVar6 = uVar6 - __nbytes) {
      __nbytes = uVar6;
      if (size < uVar6) {
        __nbytes = size;
      }
      sVar2 = JSUInputStream::read(*(JSUInputStream **)(this + 0x10),__buf,__nbytes);
      if (sVar2 == 0) {
        iVar5 = 0;
        break;
      }
      JKRAramPiece::orderSync((JKRAramPiece *)0x0,(int)__buf,uVar4,__nbytes,0,in_r8);
      iVar5 = iVar5 + __nbytes;
      uVar4 = uVar4 + __nbytes;
    }
    if (this[0x24] != (JKRAramStream)0x0) {
      JKRHeap::free(__buf,(JKRHeap *)0x0);
      this[0x24] = (JKRAramStream)0x0;
    }
  }
  os::OSSendMessage(this + 0x2c,iVar5,0);
  return iVar5;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRAramStream::write_StreamToAram_Async(JSUFileInputStream *,
                                                      unsigned long,
                                                      unsigned long,
                                                      unsigned long) */

undefined4 * __thiscall
JKRAramStream::write_StreamToAram_Async
          (JKRAramStream *this,JSUFileInputStream *param_1,ulong param_2,ulong param_3,ulong param_4
          )

{
  undefined4 *this_00;
  
  this_00 = (undefined4 *)JKernel::operator_new(0x58,JKRHeap::sSystemHeap,0xfffffffc);
  if (this_00 != (undefined4 *)0x0) {
    JKRAramStreamCommand::JKRAramStreamCommand((JKRAramStreamCommand *)this_00);
  }
  *this_00 = 2;
  this_00[1] = param_1;
  this_00[2] = param_2;
  this_00[4] = this;
  this_00[10] = 0;
  this_00[5] = param_3;
  this_00[6] = _transBuffer;
  this_00[8] = _transHeap;
  this_00[7] = _transSize;
  os::OSInitMessageQueue((OSMessageQueue *)(this_00 + 0xb),(OSMessage *)(this_00 + 0x13),1);
  os::OSSendMessage(&sMessageQueue,this_00,1);
  return this_00;
}


/* __thiscall JKRAramStream::sync(JKRAramStreamCommand *,
                                  int) */

void __thiscall JKRAramStream::sync(JKRAramStream *this)

{
  int in_r4;
  undefined4 local_18 [5];
  
  if (in_r4 == 0) {
    os::OSReceiveMessage(this + 0x2c,local_18,1);
  }
  else {
    os::OSReceiveMessage(this + 0x2c,local_18,0);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRAramStream::setTransBuffer(unsigned char *,
                                            unsigned long,
                                            JKRHeap *) */

void __thiscall
JKRAramStream::setTransBuffer(JKRAramStream *this,uchar *param_1,ulong param_2,JKRHeap *param_3)

{
  _transBuffer = 0;
  _transSize = 0x400;
  if (this != (JKRAramStream *)0x0) {
    _transBuffer = (uint)(this + 0x1f) & 0xffffffe0;
  }
  if (param_1 != (uchar *)0x0) {
    _transSize = (uint)param_1 & 0xffffffe0;
  }
  if (param_2 == 0) {
    _transHeap = 0;
    return;
  }
  if (this != (JKRAramStream *)0x0) {
    _transHeap = 0;
    return;
  }
  _transHeap = param_2;
  return;
}


/* __thiscall JKRAramStreamCommand::JKRAramStreamCommand(void) */

void __thiscall JKRAramStreamCommand::JKRAramStreamCommand(JKRAramStreamCommand *this)

{
  this[0x24] = (JKRAramStreamCommand)0x0;
  return;
}


/* __thiscall JSURandomInputStream::getAvailable(void) const */

int __thiscall JSURandomInputStream::getAvailable(JSURandomInputStream *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*(int *)this + 0x18))();
  iVar2 = (**(code **)(*(int *)this + 0x1c))(this);
  return iVar1 - iVar2;
}

