#include <JKernel/JKRMemArchive.h>
#include <JKernel/JKRArchivePri.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRMemArchive.h>
#include <JSupport/JSUList.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRArchivePub.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKernel/JKRDvdRipper.h>
#include <JKernel/JKRDecomp.h>
#include <JKRMemArchive.h>


/* __thiscall JKRMemArchive::JKRMemArchive(void) */

void __thiscall JKRMemArchive::JKRMemArchive(JKRMemArchive *this)

{
  JKRArchive::JKRArchive(&this->parent);
  (this->parent).parent.parent.vtbl = &__vt;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRMemArchive::JKRMemArchive(long,
                                           JKRArchive::EMountDirection) */

void __thiscall
JKRMemArchive::JKRMemArchive(JKRMemArchive *this,long param_1,EMountDirection param_2)

{
  uint uVar1;
  
  JKRArchive::JKRArchive(&this->parent,param_1,Mem);
  (this->parent).parent.parent.vtbl = &__vt;
  (this->parent).parent.mbIsMounted = 0;
  (this->parent).mMountDirection = param_2;
  uVar1 = open(this,param_1,(this->parent).mMountDirection);
  if ((uVar1 & 0xff) != 0) {
    (this->parent).parent.field_0x2c = 0x52415243;
    (this->parent).parent.field_0x28 =
         (this->parent).mpStrData + *(int *)((this->parent).mpNodes + 4);
    JSUPtrList::prepend(&JKRFileLoader::sVolumeList,&(this->parent).parent.mVolumeLink);
    (this->parent).parent.mbIsMounted = 1;
  }
  return;
}


/* __thiscall JKRMemArchive::~JKRMemArchive(void) */

void __thiscall JKRMemArchive::_JKRMemArchive(JKRMemArchive *this)

{
  JKRArchive__Header *__ptr;
  short in_r4;
  
  if (this != (JKRMemArchive *)0x0) {
    (this->parent).parent.parent.vtbl = &__vt;
    if ((this->parent).parent.mbIsMounted == 1) {
      if (this->mbInitialized != 0) {
        __ptr = (this->parent).mpHeader;
        if (__ptr != (JKRArchive__Header *)0x0) {
          JKRHeap::free(__ptr,(this->parent).mpHeap);
        }
      }
      JSUPtrList::remove(&JKRFileLoader::sVolumeList,&(this->parent).parent.mVolumeLink);
      (this->parent).parent.mbIsMounted = 0;
    }
    JKRArchive::_JKRArchive(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRMemArchive::fixedInit(long) */

void __thiscall JKRMemArchive::fixedInit(JKRMemArchive *this,long param_1)

{
  (this->parent).parent.mbIsMounted = 0;
  (this->parent).mMountMode = Mem;
  (this->parent).parent.field_0x34 = 1;
  (this->parent).field_0x58 = 2;
  (this->parent).mpHeap = JKRHeap::sCurrentHeap;
  (this->parent).field_0x40 = (JKRDvdArchive *)param_1;
  if (_sCurrentVolume != (JKRMemArchive *)0x0) {
    return;
  }
  _sCurrentVolume = this;
  _sCurrentDirID = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRMemArchive::mountFixed(void *,
                                        JKRMemBreakFlag) */

undefined4 __thiscall
JKRMemArchive::mountFixed(JKRMemArchive *this,void *param_1,JKRMemBreakFlag param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = JKRArchive::check_mount_already((long)param_1);
  if (iVar1 == 0) {
    fixedInit(this,(long)param_1);
    uVar3 = open(this,(char *)param_1,0xffff,param_2);
    if ((uVar3 & 0xff) == 0) {
      uVar2 = 0;
    }
    else {
      (this->parent).parent.field_0x2c = 0x52415243;
      (this->parent).parent.field_0x28 =
           (this->parent).mpStrData + *(int *)((this->parent).mpNodes + 4);
      JSUPtrList::prepend(&JKRFileLoader::sVolumeList,&(this->parent).parent.mVolumeLink);
      uVar3 = countLeadingZeros(1 - param_2);
      this->mbInitialized = (byte)(uVar3 >> 5);
      (this->parent).parent.mbIsMounted = 1;
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRMemArchive::unmountFixed(void) */

void __thiscall JKRMemArchive::unmountFixed(JKRMemArchive *this)

{
  ulong uVar1;
  JKRArchive__Header *__ptr;
  
  if ((this->parent).parent.mbIsMounted == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRMemArchive.cpp",0x151,"isMounted()");
    m_Do_printf::OSPanic("JKRMemArchive.cpp",0x151,&DAT_8036b94e);
  }
  if ((this->parent).parent.field_0x34 != 1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRMemArchive.cpp",0x154,"mMountCount == 1");
    m_Do_printf::OSPanic("JKRMemArchive.cpp",0x154,&DAT_8036b94e);
  }
  if (_sCurrentVolume == this) {
    _sCurrentVolume = (JKRMemArchive *)0x0;
  }
  if ((this->mbInitialized != 0) &&
     (__ptr = (this->parent).mpHeader, __ptr != (JKRArchive__Header *)0x0)) {
    JKRHeap::free(__ptr,(this->parent).mpHeap);
  }
  JSUPtrList::remove(&JKRFileLoader::sVolumeList,&(this->parent).parent.mVolumeLink);
  (this->parent).parent.mbIsMounted = 0;
  return;
}


/* __thiscall JKRMemArchive::open(long,
                                  JKRArchive::EMountDirection) */

int __thiscall JKRMemArchive::open(JKRMemArchive *this,long param_1,EMountDirection param_2)

{
  JKRArchive__Header *pHeader;
  ulong uVar1;
  JKRArchive__DataHeader *pJVar2;
  
  (this->parent).mpHeader = (JKRArchive__Header *)0x0;
  (this->parent).mpDataHeader = (JKRArchive__DataHeader *)0x0;
  this->mpFileData = 0;
  (this->parent).mpNodes = (undefined *)0x0;
  (this->parent).mpFileEntries = (SDIFileEntry *)0x0;
  (this->parent).mpStrData = (char *)0x0;
  this->mbInitialized = 0;
  (this->parent).mMountDirection = param_2;
  if ((this->parent).mMountDirection == 1) {
    pHeader = JKRDvdRipper::loadToMainRAM
                        (param_1,(uchar *)0x0,1,0,(this->parent).mpHeap,1,0,
                         (int *)&(this->parent).mCompressionType);
    (this->parent).mpHeader = pHeader;
  }
  else {
    pHeader = JKRDvdRipper::loadToMainRAM
                        (param_1,(uchar *)0x0,1,0,(this->parent).mpHeap,2,0,
                         (int *)&(this->parent).mCompressionType);
    (this->parent).mpHeader = pHeader;
  }
  pHeader = (this->parent).mpHeader;
  if (pHeader == (JKRArchive__Header *)0x0) {
    (this->parent).mMountMode = None;
  }
  else {
    if (pHeader->mSignature != 0x52415243) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"JKRMemArchive.cpp",0x1a2,"mArcHeader->signature ==\'RARC\'");
      m_Do_printf::OSPanic("JKRMemArchive.cpp",0x1a2,&DAT_8036b94e);
    }
    pHeader = (this->parent).mpHeader;
    (this->parent).mpDataHeader =
         (JKRArchive__DataHeader *)((int)&pHeader->mSignature + pHeader->mHeaderSize);
    pJVar2 = (this->parent).mpDataHeader;
    (this->parent).mpNodes = (undefined *)((int)&pJVar2->mNodeCount + pJVar2->mNodeOffs);
    pJVar2 = (this->parent).mpDataHeader;
    (this->parent).mpFileEntries =
         (SDIFileEntry *)((int)&pJVar2->mNodeCount + pJVar2->mFileEntryOffs);
    pJVar2 = (this->parent).mpDataHeader;
    (this->parent).mpStrData = (char *)((int)&pJVar2->mNodeCount + pJVar2->mStrTableOffs);
    pHeader = (this->parent).mpHeader;
    this->mpFileData = (int)&pHeader->mSignature + pHeader->mHeaderSize + pHeader->mFileDataOffs;
    this->mbInitialized = 1;
  }
  if ((this->parent).mMountMode == None) {
    m_Do_printf::OSReport(":::Cannot alloc memory [%s][%d]\n","JKRMemArchive.cpp",0x1b8);
  }
  return (uint)((this->parent).mMountMode != None);
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRMemArchive::open(void *,
                                  unsigned long,
                                  JKRMemBreakFlag) */

int __thiscall JKRMemArchive::open(JKRMemArchive *this,char *__file,int __oflag,...)

{
  uint uVar1;
  ulong uVar2;
  JKRArchive__Header *pJVar3;
  JKRArchive__DataHeader *pJVar4;
  JKRHeap *pJVar5;
  int in_r6;
  
  (this->parent).mpHeader = (JKRArchive__Header *)__file;
  if (((this->parent).mpHeader)->mSignature != 0x52415243) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JKRMemArchive.cpp",0x1d7,"mArcHeader->signature ==\'RARC\'");
    m_Do_printf::OSPanic("JKRMemArchive.cpp",0x1d7,&DAT_8036b94e);
  }
  pJVar3 = (this->parent).mpHeader;
  (this->parent).mpDataHeader =
       (JKRArchive__DataHeader *)((int)&pJVar3->mSignature + pJVar3->mHeaderSize);
  pJVar4 = (this->parent).mpDataHeader;
  (this->parent).mpNodes = (undefined *)((int)&pJVar4->mNodeCount + pJVar4->mNodeOffs);
  pJVar4 = (this->parent).mpDataHeader;
  (this->parent).mpFileEntries = (SDIFileEntry *)((int)&pJVar4->mNodeCount + pJVar4->mFileEntryOffs)
  ;
  pJVar4 = (this->parent).mpDataHeader;
  (this->parent).mpStrData = (char *)((int)&pJVar4->mNodeCount + pJVar4->mStrTableOffs);
  pJVar3 = (this->parent).mpHeader;
  this->mpFileData = (int)&pJVar3->mSignature + pJVar3->mHeaderSize + pJVar3->mFileDataOffs;
  uVar1 = countLeadingZeros(1 - in_r6);
  this->mbInitialized = (byte)(uVar1 >> 5);
  pJVar5 = JKRHeap::findFromRoot(__file);
  (this->parent).mpHeap = pJVar5;
  (this->parent).mCompressionType = NotCompressed;
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRMemArchive::fetchResource(JKRArchive::SDIFileEntry *,
                                           unsigned long *) */

void * __thiscall
JKRMemArchive::fetchResource(JKRMemArchive *this,SDIFileEntry *param_1,ulong *param_2)

{
  ulong uVar1;
  
  if ((this->parent).parent.mbIsMounted == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRMemArchive.cpp",0x217,"isMounted()");
    m_Do_printf::OSPanic("JKRMemArchive.cpp",0x217,&DAT_8036b94e);
  }
  if (param_1->mpData == (void *)0x0) {
    param_1->mpData = (void *)(this->mpFileData + param_1->mDataOffs);
  }
  if (param_2 != (ulong *)0x0) {
    *param_2 = param_1->mDataSize;
  }
  return param_1->mpData;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall JKRMemArchive::fetchResource(void *,
                                           unsigned long,
                                           JKRArchive::SDIFileEntry *,
                                           unsigned long *) */

void * __thiscall
JKRMemArchive::fetchResource
          (JKRMemArchive *this,void *param_1,ulong param_2,SDIFileEntry *param_3,ulong *param_4)

{
  ulong uVar1;
  uchar *length;
  int in_r8;
  
  if ((this->parent).parent.mbIsMounted == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRMemArchive.cpp",0x23f,"isMounted()");
    m_Do_printf::OSPanic("JKRMemArchive.cpp",0x23f,&DAT_8036b94e);
  }
  length = (uchar *)param_3->mDataSize;
  if (param_2 < (uchar *)param_3->mDataSize) {
    length = (uchar *)param_2;
  }
  if ((byte *)param_3->mpData == (byte *)0x0) {
    if (((uint)param_3->mAttrAndNameOffs >> 0x18 & 4) == 0) {
      uVar1 = 0;
    }
    else {
      if (((uint)param_3->mAttrAndNameOffs >> 0x18 & 0x80) == 0) {
        uVar1 = 1;
      }
      else {
        uVar1 = 2;
      }
    }
    length = (uchar *)fetchResource_subroutine
                                ((JKRMemArchive *)(this->mpFileData + param_3->mDataOffs),length,
                                 (ulong)param_1,(uchar *)param_2,uVar1,in_r8);
  }
  else {
    copy_bytes((byte *)param_1,(byte *)param_3->mpData,(int)length);
  }
  if (param_4 != (ulong *)0x0) {
    *param_4 = (ulong)length;
  }
  return param_1;
}


/* __thiscall JKRMemArchive::removeResourceAll(void) */

void __thiscall JKRMemArchive::removeResourceAll(JKRMemArchive *this)

{
  ulong uVar1;
  SDIFileEntry *pSVar2;
  uint uVar3;
  
  if ((this->parent).parent.mbIsMounted == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRMemArchive.cpp",0x26e,"isMounted()");
    m_Do_printf::OSPanic("JKRMemArchive.cpp",0x26e,&DAT_8036b94e);
  }
  if (((this->parent).mpDataHeader != (JKRArchive__DataHeader *)0x0) &&
     ((this->parent).mMountMode != Mem)) {
    pSVar2 = (this->parent).mpFileEntries;
    for (uVar3 = 0; uVar3 < (uint)((this->parent).mpDataHeader)->mFileEntryCount; uVar3 = uVar3 + 1)
    {
      if (pSVar2->mpData != (void *)0x0) {
        pSVar2->mpData = (void *)0x0;
      }
    }
  }
  return;
}


/* __thiscall JKRMemArchive::removeResource(void *) */

bool __thiscall JKRMemArchive::removeResource(JKRMemArchive *this,void *param_1)

{
  ulong uVar1;
  SDIFileEntry *pSVar2;
  
  if ((this->parent).parent.mbIsMounted == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRMemArchive.cpp",0x28d,"isMounted()");
    m_Do_printf::OSPanic("JKRMemArchive.cpp",0x28d,&DAT_8036b94e);
  }
  pSVar2 = JKRArchive::findPtrResource(&this->parent,param_1);
  if (pSVar2 != (SDIFileEntry *)0x0) {
    pSVar2->mpData = (void *)0x0;
  }
  return pSVar2 != (SDIFileEntry *)0x0;
}


/* __thiscall JKRMemArchive::fetchResource_subroutine(unsigned char *,
                                                      unsigned long,
                                                      unsigned char *,
                                                      unsigned long,
                                                      int) */

uchar * __thiscall
JKRMemArchive::fetchResource_subroutine
          (JKRMemArchive *this,uchar *param_1,ulong param_2,uchar *param_3,ulong param_4,int param_5
          )

{
  uint uVar1;
  
  if (param_4 == 0) {
    if (param_3 < param_1) {
      param_1 = param_3;
    }
    copy_bytes((byte *)param_2,(byte *)this,(int)param_1);
  }
  else {
    if (((int)param_4 < 0) || (2 < (int)param_4)) {
      m_Do_printf::OSPanic("JKRMemArchive.cpp",0x2bf,":::??? bad sequence\n");
      param_1 = (uchar *)0x0;
    }
    else {
      uVar1 = (uint)*(byte *)((int)&(this->parent).parent.parent.mpHeap + 3);
      param_1 = (uchar *)(uVar1 | (uint)*(byte *)((int)&(this->parent).parent.parent.mpHeap + 2) <<
                                  8 | (uint)*(byte *)&(this->parent).parent.parent.mpHeap << 0x18 |
                                      (uint)*(byte *)((int)&(this->parent).parent.parent.mpHeap + 1)
                                      << 0x10);
      if (param_3 < param_1) {
        param_1 = param_3;
      }
      JKRDecomp::orderSync((JKRDecomp *)this,(uchar *)param_2,param_1,0,uVar1);
    }
  }
  return param_1;
}


/* __thiscall JKRMemArchive::getExpandedResSize(void const *) const */

uint __thiscall JKRMemArchive::getExpandedResSize(JKRMemArchive *this,void *param_1)

{
  SDIFileEntry *pSVar1;
  uint uVar2;
  
  pSVar1 = JKRArchive::findPtrResource(&this->parent,param_1);
  if (pSVar1 == (SDIFileEntry *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    if (((uint)pSVar1->mAttrAndNameOffs >> 0x18 & 4) == 0) {
      uVar2 = (*(code *)((this->parent).parent.parent.vtbl)->getResSize)(this,param_1);
    }
    else {
      uVar2 = (uint)*(byte *)((int)param_1 + 7) |
              (uint)*(byte *)((int)param_1 + 6) << 8 |
              (uint)*(byte *)((int)param_1 + 4) << 0x18 | (uint)*(byte *)((int)param_1 + 5) << 0x10;
    }
  }
  return uVar2;
}

