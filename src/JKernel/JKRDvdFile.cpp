#include <JKernel/JKRDvdFile.h>
#include <JKernel/JKRDisposer.h>
#include <JSupport/JSUList.h>
#include <JKernel/JKRDvdFile.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <os/OSMutex.h>
#include <os/OSMessage.h>
#include <dvd/dvdfs.h>
#include <dvd/dvd.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <os/OSThread.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JSUList<JKRDvdFile>.h>
#include <JKRDvdFile.h>

struct JSUPtrList JKRDvdFile;

/* __thiscall JKRDvdFile::JKRDvdFile(void) */

void __thiscall JKRDvdFile::JKRDvdFile(JKRDvdFile *this)

{
  JKRDisposer::JKRDisposer(&this->parent);
  (this->parent).vtbl = (JKRArchive__vtbl *)&JKRFile::__vt;
  this->mStatus = 0;
  (this->parent).vtbl = (JKRArchive__vtbl *)&__vt;
  JSUPtrLink::JSUPtrLink(&this->mLink,this);
  initiate(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRDvdFile::JKRDvdFile(char const *) */

void __thiscall JKRDvdFile::JKRDvdFile(JKRDvdFile *this,char *param_1)

{
  byte bVar1;
  
  JKRDisposer::JKRDisposer(&this->parent);
  (this->parent).vtbl = (JKRArchive__vtbl *)&JKRFile::__vt;
  this->mStatus = 0;
  (this->parent).vtbl = (JKRArchive__vtbl *)&__vt;
  JSUPtrLink::JSUPtrLink(&this->mLink,this);
  initiate(this);
  bVar1 = (*(code *)((this->parent).vtbl)->unmount)(this,param_1);
  this->mStatus = bVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRDvdFile::JKRDvdFile(long) */

void __thiscall JKRDvdFile::JKRDvdFile(JKRDvdFile *this,long param_1)

{
  byte bVar1;
  
  JKRDisposer::JKRDisposer(&this->parent);
  (this->parent).vtbl = (JKRArchive__vtbl *)&JKRFile::__vt;
  this->mStatus = 0;
  (this->parent).vtbl = (JKRArchive__vtbl *)&__vt;
  JSUPtrLink::JSUPtrLink(&this->mLink,this);
  initiate(this);
  bVar1 = (*(code *)((this->parent).vtbl)->readResource2)(this,param_1);
  this->mStatus = bVar1;
  return;
}


/* __thiscall JKRDvdFile::~JKRDvdFile(void) */

void __thiscall JKRDvdFile::_JKRDvdFile(JKRDvdFile *this)

{
  short in_r4;
  
  if (this != (JKRDvdFile *)0x0) {
    (this->parent).vtbl = (JKRArchive__vtbl *)&__vt;
    (*(code *)((this->parent).vtbl)->becomeCurrent)();
    if (this != (JKRDvdFile *)0xffffff1c) {
      JSUPtrLink::_JSUPtrLink(&this->mLink);
    }
    if (this != (JKRDvdFile *)0x0) {
      (this->parent).vtbl = (JKRArchive__vtbl *)&JKRFile::__vt;
      JKRDisposer::_JKRDisposer(&this->parent);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JKRDvdFile::initiate(void) */

void __thiscall JKRDvdFile::initiate(JKRDvdFile *this)

{
  this->field_0x98 = this;
  os::OSInitMutex(&this->field_0x1c);
  os::OSInitMutex(&this->field_0x34);
  os::OSInitMessageQueue(&this->field_0xc0,this->field_0xe0,1);
  os::OSInitMessageQueue(&this->field_0x9c,this->field_0xbc,1);
  this->field_0xf4 = (undefined *)0x0;
  *(undefined4 *)&this->field_0x50 = 0;
  *(undefined4 *)&this->field_0x58 = 0;
  return;
}


/* __thiscall JKRDvdFile::open(char const *) */

int __thiscall JKRDvdFile::open(JKRDvdFile *this,char *filename)

{
  bool bVar1;
  
  if (this->mStatus == 0) {
    bVar1 = dvd::DVDOpen(filename,(int)&this->mNum);
    this->mStatus = 1 - (bVar1 == false);
    if (this->mStatus != 0) {
      JSUPtrList::append(&sDvdList,&this->mLink);
      dvd::DVDGetCommandBlockStatus(&this->mNum);
    }
  }
  return (uint)this->mStatus;
}


/* __thiscall JKRDvdFile::open(long) */

int __thiscall JKRDvdFile::open(JKRDvdFile *this,char *__file,int __oflag,...)

{
  int iVar1;
  
  if (this->mStatus == 0) {
    iVar1 = dvd::DVDFastOpen(__file,&this->mNum);
    this->mStatus = 1 - (iVar1 == 0);
    if (this->mStatus != 0) {
      JSUPtrList::append(&sDvdList,&this->mLink);
      dvd::DVDGetCommandBlockStatus(&this->mNum);
    }
  }
  return (uint)this->mStatus;
}


/* __thiscall JKRDvdFile::close(void) */

int __thiscall JKRDvdFile::close(JKRDvdFile *this,int __fd)

{
  int iVar1;
  
  if (this->mStatus != 0) {
    iVar1 = dvd::DVDClose(&this->mNum);
    if (iVar1 == 0) {
      this = (JKRDvdFile *)m_Do_printf::OSPanic("JKRDvdFile.cpp",0xd4,"cannot close DVD file\n");
    }
    else {
      this->mStatus = 0;
      this = (JKRDvdFile *)JSUPtrList::remove(&sDvdList,&this->mLink);
    }
  }
  return (int)this;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRDvdFile::readData(void *,
                                   long,
                                   long) */

JKRDvdFile * __thiscall
JKRDvdFile::readData(JKRDvdFile *this,void *param_1,long param_2,long param_3)

{
  ulong uVar1;
  JKRDvdFile *pJVar2;
  undefined *puVar3;
  int iVar4;
  
  if ((param_2 & 0x1fU) != 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRDvdFile.cpp",0xec,"( length & 0x1f ) == 0");
    m_Do_printf::OSPanic("JKRDvdFile.cpp",0xec,&DAT_8036bc45);
  }
  os::OSLockMutex(&this->field_0x1c);
  if (this->field_0xf4 == (undefined *)0x0) {
    puVar3 = (undefined *)os::OSGetCurrentThread();
    this->field_0xf4 = puVar3;
    pJVar2 = (JKRDvdFile *)&DAT_ffffffff;
    iVar4 = dvd::DVDReadAsyncPrio(&this->mNum,param_1,param_2,param_3,doneProcess,2);
    if (iVar4 != 0) {
      pJVar2 = this;
      sync(this);
    }
    this->field_0xf4 = (undefined *)0x0;
    os::OSUnlockMutex(&this->field_0x1c);
  }
  else {
    os::OSUnlockMutex(&this->field_0x1c);
    pJVar2 = (JKRDvdFile *)&DAT_ffffffff;
  }
  return pJVar2;
}


/* __thiscall JKRDvdFile::writeData(void const *,
                                    long,
                                    long) */

undefined4 __thiscall
JKRDvdFile::writeData(JKRDvdFile *this,void *param_1,long param_2,long param_3)

{
  ulong uVar1;
  
  if ((param_2 & 0x1fU) != 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRDvdFile.cpp",0x154,"( length & 0x1f ) == 0");
    m_Do_printf::OSPanic("JKRDvdFile.cpp",0x154,&DAT_8036bc45);
  }
  return 0xffffffff;
}


/* __thiscall JKRDvdFile::sync(void) */

void __thiscall JKRDvdFile::sync(JKRDvdFile *this)

{
  undefined local_18 [20];
  
  os::OSLockMutex(&this->field_0x1c);
  os::OSReceiveMessage(&this->field_0xc0,local_18,1);
  this->field_0xf4 = (undefined *)0x0;
  os::OSUnlockMutex(&this->field_0x1c);
  return;
}


/* __thiscall JKRDvdFile::doneProcess(long,
                                      DVDFileInfo *) */

void __thiscall JKRDvdFile::doneProcess(JKRDvdFile *this,long param_1,DVDFileInfo *param_2)

{
  os::OSSendMessage(*(int *)(param_1 + 0x3c) + 0xc0,this,0);
  return;
}


/* __thiscall JKRDvdFile::getFileSize(void) const */

undefined4 __thiscall JKRDvdFile::getFileSize(JKRDvdFile *this)

{
  return *(undefined4 *)&this->field_0x90;
}


namespace JKernel {

void __sinit_JKRDvdFile_cpp(void)

{
  JSUPtrList::initiate(&::JKRDvdFile::sDvdList);
  Runtime.PPCEABI.H::__register_global_object
            (&::JKRDvdFile::sDvdList,::JSUList<JKRDvdFile>::_JSUList,&_578);
  return;
}

}

/* __thiscall JSUList<JKRDvdFile>::~JSUList(void) */

JSUList_JKRDvdFile_ * __thiscall JSUList<JKRDvdFile>::_JSUList(JSUList_JKRDvdFile_ *this)

{
  short in_r4;
  
  if ((this != (JSUList_JKRDvdFile_ *)0x0) &&
     (JSUPtrList::_JSUPtrList((JSUPtrList *)this), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return this;
}

