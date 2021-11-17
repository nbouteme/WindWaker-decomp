#include <JKernel/JKRFileCache.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRFileCache.h>
#include <JKernel/JKRFileLoader.h>
#include <JSupport/JSUList.h>
#include <dvd/dvdfs.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKernel/JKRDvdFile.h>
#include <JKernel/JKRFile.h>
#include <JKernel/JKRFileFinder.h>
#include <MSL_C.PPCEABI.bare.H/ctype.h>
#include <JKRFileCache/CCacheBlock.h>
#include <JKRFileCache.h>


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRFileCache::mount(char const *,
                                  JKRHeap *,
                                  char const *) */

int __thiscall
JKRFileCache::mount(JKRFileCache *this,char *__special_file,char *__dir,char *__fstype,
                   ulong __rwflag,void *__data)

{
  JKRFileCache *pJVar1;
  size_t sVar2;
  int iVar3;
  JSUPtrLink *pJVar4;
  
  if ((this == (JKRFileCache *)0x0) || (*this != (JKRFileCache)0x2f)) {
    pJVar1 = (JKRFileCache *)0x0;
  }
  else {
    sVar2 = MSL_C.PPCEABI.bare.H::strlen((char *)this);
    pJVar4 = JKRFileLoader::sVolumeList.mpHead;
    if ((sVar2 == 1) || (this[sVar2 - 1] != (JKRFileCache)0x2f)) {
      for (; pJVar4 != (JSUPtrLink *)0x0; pJVar4 = pJVar4->mpNext) {
        pJVar1 = (JKRFileCache *)pJVar4->mpData;
        if (((*(int *)(pJVar1 + 0x2c) == 0x43415348) && (*(char **)(pJVar1 + 0x48) != (char *)0x0))
           && (iVar3 = MSL_C.PPCEABI.bare.H::strcmp(*(char **)(pJVar1 + 0x48),(char *)this),
              iVar3 == 0)) {
          *(int *)(pJVar1 + 0x34) = *(int *)(pJVar1 + 0x34) + 1;
          return (int)pJVar1;
        }
      }
      pJVar1 = (JKRFileCache *)JKernel::operator_new(0x54,(JKRHeap *)__special_file,0);
      if (pJVar1 != (JKRFileCache *)0x0) {
        JKRFileCache(pJVar1,(char *)this,__dir);
      }
    }
    else {
      pJVar1 = (JKRFileCache *)0x0;
    }
  }
  return (int)pJVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRFileCache::JKRFileCache(char const *,
                                         char const *) */

void __thiscall JKRFileCache::JKRFileCache(JKRFileCache *this,char *param_1,char *param_2)

{
  JKRHeap *pJVar1;
  size_t sVar2;
  undefined4 uVar3;
  void *pvVar4;
  char *pcVar5;
  
  JKRFileLoader::JKRFileLoader((JKRFileLoader *)this);
  *(undefined1 **)this = &__vt;
  JSUPtrList::initiate((JSUPtrList *)(this + 0x3c));
  pJVar1 = JKRHeap::findFromRoot(this);
  *(JKRHeap **)(this + 0x38) = pJVar1;
  *(undefined4 *)(this + 0x34) = 1;
  *(undefined4 *)(this + 0x2c) = 0x43415348;
  sVar2 = MSL_C.PPCEABI.bare.H::strlen(param_1);
  uVar3 = JKRHeap::alloc(sVar2 + 1,1,*(JKRHeap **)(this + 0x38));
  *(undefined4 *)(this + 0x48) = uVar3;
  pvVar4 = JKRHeap::alloc(JKRHeap::sSystemHeap,sVar2 + 2,1);
  *(void **)(this + 0x4c) = pvVar4;
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x48),param_1);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x4c),param_1);
  if (param_1[1] == '\0') {
    if (param_2 == (char *)0x0) {
      param_2 = "dvd";
    }
    sVar2 = MSL_C.PPCEABI.bare.H::strlen(param_2);
    pvVar4 = JKRHeap::alloc(JKRHeap::sSystemHeap,sVar2 + 1,0);
    *(void **)(this + 0x50) = pvVar4;
    MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x50),param_2);
    convStrLower(this,*(char **)(this + 0x50));
    *(undefined4 *)(this + 0x28) = *(undefined4 *)(this + 0x50);
  }
  else {
    convStrLower(this,*(char **)(this + 0x48));
    convStrLower(this,*(char **)(this + 0x4c));
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(this + 0x4c),"/");
    if (param_2 == (char *)0x0) {
      pcVar5 = MSL_C.PPCEABI.bare.H::strrchr(*(char **)(this + 0x48),0x2f);
      param_2 = pcVar5 + 1;
    }
    sVar2 = MSL_C.PPCEABI.bare.H::strlen(param_2);
    pvVar4 = JKRHeap::alloc(JKRHeap::sSystemHeap,sVar2 + 1,0);
    *(void **)(this + 0x50) = pvVar4;
    MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x50),param_2);
    convStrLower(this,*(char **)(this + 0x50));
    *(undefined4 *)(this + 0x28) = *(undefined4 *)(this + 0x50);
  }
  JSUPtrList::prepend(&JKRFileLoader::sVolumeList,(JSUPtrLink *)(this + 0x18));
  this[0x30] = (JKRFileCache)0x1;
  return;
}


/* __thiscall JKRFileCache::~JKRFileCache(void) */

void __thiscall JKRFileCache::_JKRFileCache(JKRFileCache *this)

{
  short in_r4;
  
  if (this != (JKRFileCache *)0x0) {
    *(undefined1 **)this = &__vt;
    (**(code **)(*(int *)this + 0x24))();
    if (*(void **)(this + 0x48) != (void *)0x0) {
      JKRHeap::free(*(void **)(this + 0x48),*(JKRHeap **)(this + 0x38));
    }
    if (*(void **)(this + 0x4c) != (void *)0x0) {
      JKRHeap::free(JKRHeap::sSystemHeap,*(void **)(this + 0x4c));
    }
    if (*(void **)(this + 0x50) != (void *)0x0) {
      JKRHeap::free(JKRHeap::sSystemHeap,*(void **)(this + 0x50));
    }
    JSUPtrList::remove(&JKRFileLoader::sVolumeList,(JSUPtrLink *)(this + 0x18));
    if (this != (JKRFileCache *)0xffffffc4) {
      JSUPtrList::_JSUPtrList((JSUPtrList *)(this + 0x3c));
    }
    JKRFileLoader::_JKRFileLoader((JKRFileLoader *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRFileCache::becomeCurrent(char const *) */

bool __thiscall JKRFileCache::becomeCurrent(JKRFileCache *this,char *param_1)

{
  void *__ptr;
  int iVar1;
  
  __ptr = (void *)getDvdPathName(this,param_1);
  iVar1 = dvd::DVDChangeDir();
  if (iVar1 != 0) {
    _sCurrentVolume = this;
    JKRHeap::free(JKRHeap::sSystemHeap,*(void **)(this + 0x4c));
    *(void **)(this + 0x4c) = __ptr;
    if ((*(char **)(this + 0x4c))[1] != '\0') {
      MSL_C.PPCEABI.bare.H::strcat(*(char **)(this + 0x4c),"/");
    }
  }
  else {
    JKRHeap::free(JKRHeap::sSystemHeap,__ptr);
  }
  return iVar1 != 0;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRFileCache::getResource(char const *) */

void * __thiscall JKRFileCache::getResource(JKRFileCache *this,char *param_1)

{
  void *__buf;
  ulong uVar1;
  char *__ptr;
  int iVar2;
  JSUPtrLink *pLink;
  void *__fd;
  undefined auStack264 [144];
  ulong local_78;
  
  if (this[0x30] == (JKRFileCache)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRFileCache.cpp",0xed,"isMounted()");
    m_Do_printf::OSPanic("JKRFileCache.cpp",0xed,&DAT_8036b8f3);
  }
  __fd = (void *)0x0;
  __ptr = (char *)getDvdPathName(this,param_1);
  JKRDvdFile::JKRDvdFile((JKRDvdFile *)auStack264,__ptr);
  if (auStack264[24] != 0) {
    iVar2 = findCacheBlock(this,auStack264._140_4_);
    if (iVar2 == 0) {
      __buf = (void *)(local_78 + 0x1f & 0xffffffe0);
      __fd = (void *)JKRHeap::alloc((ulong)__buf,0x20,*(JKRHeap **)(this + 0x38));
      if (__fd != (void *)0x0) {
        JKRFile::read((JKRFile *)auStack264,(int)__fd,__buf,0);
        pLink = (JSUPtrLink *)JKernel::operator_new(0x20,JKRHeap::sSystemHeap,0);
        if (pLink != (JSUPtrLink *)0x0) {
          CCacheBlock::CCacheBlock((CCacheBlock *)pLink,auStack264._140_4_,local_78,__fd);
        }
        JSUPtrList::append((JSUPtrList *)(this + 0x3c),pLink);
      }
    }
    else {
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 1;
      __fd = *(void **)(iVar2 + 0x1c);
    }
  }
  JKRHeap::free(JKRHeap::sSystemHeap,__ptr);
  JKRDvdFile::_JKRDvdFile((JKRDvdFile *)auStack264);
  return __fd;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRFileCache::getResource(unsigned long,
                                        char const *) */

undefined4 __thiscall JKRFileCache::getResource(JKRFileCache *this,ulong param_1,char *param_2)

{
  ulong uVar1;
  size_t sVar2;
  char cVar4;
  undefined4 uVar3;
  char acStack280 [268];
  
  if (this[0x30] == (JKRFileCache)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRFileCache.cpp",0x12f,"isMounted()");
    m_Do_printf::OSPanic("JKRFileCache.cpp",0x12f,&DAT_8036b8f3);
  }
  sVar2 = MSL_C.PPCEABI.bare.H::strlen(*(char **)(this + 0x48));
  MSL_C.PPCEABI.bare.H::strcpy(acStack280,*(char **)(this + 0x48));
  cVar4 = findFile(this,acStack280,param_2);
  if (cVar4 == '\0') {
    uVar3 = 0;
  }
  else {
    uVar3 = (**(code **)(*(int *)this + 0x14))(this,acStack280 + sVar2);
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRFileCache::readResource(void *,
                                         unsigned long,
                                         char const *) */

void * __thiscall
JKRFileCache::readResource(JKRFileCache *this,void *param_1,ulong param_2,char *param_3)

{
  ulong uVar1;
  char *__ptr;
  int iVar2;
  void *__buf;
  undefined auStack280 [144];
  int local_88;
  
  if (this[0x30] == (JKRFileCache)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRFileCache.cpp",0x158,"isMounted()");
    m_Do_printf::OSPanic("JKRFileCache.cpp",0x158,&DAT_8036b8f3);
  }
  __ptr = (char *)getDvdPathName(this,param_3);
  JKRDvdFile::JKRDvdFile((JKRDvdFile *)auStack280,__ptr);
  __buf = (void *)0x0;
  while (auStack280[24] != 0) {
    __buf = (void *)(local_88 + 0x1fU & 0xffffffe0);
    param_2 = param_2 & 0xffffffe0;
    if (param_2 < __buf) {
      __buf = (void *)param_2;
    }
    iVar2 = findCacheBlock(this,auStack280._140_4_);
    if (iVar2 == 0) {
      JKRFile::read((JKRFile *)auStack280,(int)param_1,__buf,0);
    }
    else {
      copy_bytes((byte *)param_1,*(byte **)(iVar2 + 0x1c),(int)__buf);
    }
  }
  JKRHeap::free(JKRHeap::sSystemHeap,__ptr);
  JKRDvdFile::_JKRDvdFile((JKRDvdFile *)auStack280);
  return __buf;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRFileCache::readResource(void *,
                                         unsigned long,
                                         unsigned long,
                                         char const *) */

undefined4 __thiscall
JKRFileCache::readResource
          (JKRFileCache *this,void *param_1,ulong param_2,ulong param_3,char *param_4)

{
  ulong uVar1;
  size_t sVar2;
  char cVar4;
  undefined4 uVar3;
  char acStack280 [260];
  
  if (this[0x30] == (JKRFileCache)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRFileCache.cpp",0x19c,"isMounted()");
    m_Do_printf::OSPanic("JKRFileCache.cpp",0x19c,&DAT_8036b8f3);
  }
  sVar2 = MSL_C.PPCEABI.bare.H::strlen(*(char **)(this + 0x48));
  MSL_C.PPCEABI.bare.H::strcpy(acStack280,*(char **)(this + 0x48));
  cVar4 = findFile(this,acStack280,param_4);
  if (cVar4 == '\0') {
    uVar3 = 0;
  }
  else {
    uVar3 = (**(code **)(*(int *)this + 0x1c))(this,param_1,param_2,acStack280 + sVar2);
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall JKRFileCache::removeResourceAll(void) */

void __thiscall JKRFileCache::removeResourceAll(JKRFileCache *this)

{
  ulong uVar1;
  JSUPtrLink *pJVar2;
  JSUPtrLink *pJVar3;
  JKRHeap *this_00;
  
  if (this[0x30] == (JKRFileCache)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRFileCache.cpp",0x1b9,"isMounted()");
    m_Do_printf::OSPanic("JKRFileCache.cpp",0x1b9,&DAT_8036b8f3);
  }
  pJVar3 = *(JSUPtrLink **)(this + 0x3c);
  while (pJVar3 != (JSUPtrLink *)0x0) {
    JKRHeap::free(*(void **)((int)pJVar3->mpData + 0x1c),*(JKRHeap **)(this + 0x38));
    JSUPtrList::remove((JSUPtrList *)(this + 0x3c),(JSUPtrLink *)pJVar3->mpData);
    pJVar2 = pJVar3->mpNext;
    this_00 = (JKRHeap *)pJVar3->mpData;
    pJVar3 = pJVar2;
    if (this_00 != (JKRHeap *)0x0) {
      if (this_00 != (JKRHeap *)0x0) {
        JSUPtrLink::_JSUPtrLink((JSUPtrLink *)this_00);
      }
      JKernel::operator_delete(this_00);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRFileCache::removeResource(void *) */

undefined4 __thiscall JKRFileCache::removeResource(JKRFileCache *this,void *param_1)

{
  int iVar1;
  ulong uVar2;
  JKRHeap *this_00;
  undefined4 uVar3;
  
  if (this[0x30] == (JKRFileCache)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JKRFileCache.cpp",0x1cf,"isMounted()");
    m_Do_printf::OSPanic("JKRFileCache.cpp",0x1cf,&DAT_8036b8f3);
  }
  this_00 = (JKRHeap *)findCacheBlock(this,param_1);
  if (this_00 == (JKRHeap *)0x0) {
    uVar3 = 0;
  }
  else {
    iVar1 = *(int *)&this_00->field_0x10 + -1;
    *(int *)&this_00->field_0x10 = iVar1;
    if (iVar1 == 0) {
      JKRHeap::free(param_1,*(JKRHeap **)(this + 0x38));
      JSUPtrList::remove((JSUPtrList *)(this + 0x3c),(JSUPtrLink *)this_00);
      if (this_00 != (JKRHeap *)0x0) {
        if (this_00 != (JKRHeap *)0x0) {
          JSUPtrLink::_JSUPtrLink((JSUPtrLink *)this_00);
        }
        JKernel::operator_delete(this_00);
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}


/* __thiscall JKRFileCache::detachResource(void *) */

undefined4 __thiscall JKRFileCache::detachResource(JKRFileCache *this,void *param_1)

{
  ulong uVar1;
  JKRHeap *this_00;
  undefined4 uVar2;
  
  if (this[0x30] == (JKRFileCache)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRFileCache.cpp",0x1ea,"isMounted()");
    m_Do_printf::OSPanic("JKRFileCache.cpp",0x1ea,&DAT_8036b8f3);
  }
  this_00 = (JKRHeap *)findCacheBlock(this,param_1);
  if (this_00 == (JKRHeap *)0x0) {
    uVar2 = 0;
  }
  else {
    JSUPtrList::remove((JSUPtrList *)(this + 0x3c),(JSUPtrLink *)this_00);
    if (this_00 != (JKRHeap *)0x0) {
      if (this_00 != (JKRHeap *)0x0) {
        JSUPtrLink::_JSUPtrLink((JSUPtrLink *)this_00);
      }
      JKernel::operator_delete(this_00);
    }
    uVar2 = 1;
  }
  return uVar2;
}


/* __thiscall JKRFileCache::getResSize(void const *) const */

undefined4 __thiscall JKRFileCache::getResSize(JKRFileCache *this,void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = findCacheBlock(this,param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x18);
  }
  return uVar2;
}


/* __thiscall JKRFileCache::countFile(char const *) const */

int __thiscall JKRFileCache::countFile(JKRFileCache *this,char *param_1)

{
  char *__ptr;
  bool bVar2;
  int iVar1;
  int iVar3;
  undefined auStack40 [12];
  int aiStack28 [5];
  
  iVar3 = 0;
  __ptr = (char *)getDvdPathName(this,param_1);
  bVar2 = dvd::DVDOpenDir(__ptr,aiStack28);
  if (bVar2 != false) {
    while (iVar1 = dvd::DVDReadDir(aiStack28,auStack40), iVar1 != 0) {
      iVar3 = iVar3 + 1;
    }
    dvd::DVDCloseDir(aiStack28);
  }
  JKRHeap::free(JKRHeap::sSystemHeap,__ptr);
  return iVar3;
}


/* __thiscall JKRFileCache::getFirstFile(char const *) const */

JKRDvdFinder * __thiscall JKRFileCache::getFirstFile(JKRFileCache *this,char *param_1)

{
  char *__ptr;
  JKRDvdFinder *this_00;
  
  __ptr = (char *)getDvdPathName(this,param_1);
  this_00 = (JKRDvdFinder *)JKernel::operator_new(0x24,JKRHeap::sSystemHeap,0);
  if (this_00 != (JKRDvdFinder *)0x0) {
    JKRDvdFinder::JKRDvdFinder(this_00,__ptr);
  }
  JKRHeap::free(JKRHeap::sSystemHeap,__ptr);
  if (this_00[0x10] != (JKRDvdFinder)0x1) {
    if (this_00 != (JKRDvdFinder *)0x0) {
      (**(code **)(*(int *)(this_00 + 0xc) + 8))(this_00,1);
    }
    this_00 = (JKRDvdFinder *)0x0;
  }
  return this_00;
}


/* __thiscall JKRFileCache::findCacheBlock(void const *) const */

int __thiscall JKRFileCache::findCacheBlock(JKRFileCache *this,void *param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 0x3c);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    if (*(void **)(*piVar1 + 0x1c) == param_1) break;
    piVar1 = (int *)piVar1[3];
  }
  return *piVar1;
}


/* __thiscall JKRFileCache::findCacheBlock(unsigned long) const */

int __thiscall JKRFileCache::findCacheBlock(JKRFileCache *this,ulong param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 0x3c);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    if (param_1 == *(ulong *)(*piVar1 + 0x14)) break;
    piVar1 = (int *)piVar1[3];
  }
  return *piVar1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall JKRFileCache::findFile(char *,
                                     char const *) const */

uint __thiscall JKRFileCache::findFile(JKRFileCache *this,char *param_1,char *param_2)

{
  uint uVar1;
  size_t sVar2;
  bool bVar4;
  int iVar3;
  uint uVar5;
  char *pcVar6;
  undefined auStack56 [4];
  int local_34;
  char *local_30;
  int aiStack44 [5];
  
  uVar5 = 0;
  sVar2 = MSL_C.PPCEABI.bare.H::strlen(param_1);
  bVar4 = dvd::DVDOpenDir(param_1,aiStack44);
  if (bVar4 != false) {
    pcVar6 = param_1 + sVar2;
    do {
      while( true ) {
        iVar3 = dvd::DVDReadDir(aiStack44,auStack56);
        if (iVar3 == 0) goto LAB_802b7d34;
        if (local_34 == 0) break;
        *pcVar6 = '/';
        MSL_C.PPCEABI.bare.H::strcpy(pcVar6 + 1,local_30);
        uVar5 = findFile(this,param_1,param_2);
        if ((uVar5 & 0xff) != 0) goto LAB_802b7d34;
        *pcVar6 = '\0';
      }
      iVar3 = MSL_C.PPCEABI.bare.H::strcmp(param_2,local_30);
      uVar1 = countLeadingZeros(iVar3);
      uVar5 = uVar1 >> 5;
    } while ((uVar1 >> 5 & 0xff) == 0);
    MSL_C.PPCEABI.bare.H::strcat(param_1,"/");
    MSL_C.PPCEABI.bare.H::strcat(param_1,param_2);
LAB_802b7d34:
    dvd::DVDCloseDir(aiStack44);
  }
  return uVar5;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRFileCache::getDvdPathName(char const *) const */

char * __thiscall JKRFileCache::getDvdPathName(JKRFileCache *this,char *param_1)

{
  size_t sVar1;
  size_t sVar2;
  char *__dest;
  
  if (*param_1 == '/') {
    sVar1 = MSL_C.PPCEABI.bare.H::strlen(param_1);
    sVar2 = MSL_C.PPCEABI.bare.H::strlen(*(char **)(this + 0x48));
    __dest = (char *)JKRHeap::alloc(JKRHeap::sSystemHeap,sVar2 + sVar1 + 2,1);
    MSL_C.PPCEABI.bare.H::strcpy(__dest,*(char **)(this + 0x48));
    if (param_1[1] != '\0') {
      if (*(char *)(*(int *)(this + 0x48) + 1) == '\0') {
        MSL_C.PPCEABI.bare.H::strcat(__dest,param_1 + 1);
      }
      else {
        MSL_C.PPCEABI.bare.H::strcat(__dest,param_1);
      }
    }
  }
  else {
    sVar1 = MSL_C.PPCEABI.bare.H::strlen(param_1);
    sVar2 = MSL_C.PPCEABI.bare.H::strlen(*(char **)(this + 0x4c));
    __dest = (char *)JKRHeap::alloc(JKRHeap::sSystemHeap,sVar2 + sVar1 + 2,1);
    MSL_C.PPCEABI.bare.H::strcpy(__dest,*(char **)(this + 0x4c));
    MSL_C.PPCEABI.bare.H::strcat(__dest,param_1);
  }
  convStrLower(this,__dest);
  return __dest;
}


/* __thiscall JKRFileCache::convStrLower(char *) const */

void __thiscall JKRFileCache::convStrLower(JKRFileCache *this,char *param_1)

{
  int iVar1;
  
  while( true ) {
    if (*param_1 == '\0') break;
    iVar1 = MSL_C.PPCEABI.bare.H::tolower((int)*param_1);
    *param_1 = (char)iVar1;
    param_1 = param_1 + 1;
  }
  return;
}


namespace JKRFileCache {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall CCacheBlock::CCacheBlock(unsigned long,
                                                     unsigned long,
                                                     void const *) */

void __thiscall
CCacheBlock::CCacheBlock(CCacheBlock *this,ulong param_1,ulong param_2,void *param_3)

{
  JSUPtrLink::JSUPtrLink((JSUPtrLink *)this,this);
  *(undefined4 *)(this + 0x10) = 1;
  *(ulong *)(this + 0x14) = param_1;
  *(ulong *)(this + 0x18) = param_2;
  *(void **)(this + 0x1c) = param_3;
  return;
}

}

/* __thiscall JKRFileCache::getFsResource(char const *) */

void __thiscall JKRFileCache::getFsResource(JKRFileCache *this,char *param_1)

{
  (**(code **)(*(int *)this + 0x14))();
  return;
}


/* __thiscall JKRFileCache::getNameResource(unsigned long,
                                            char const *) */

void __thiscall JKRFileCache::getNameResource(JKRFileCache *this,ulong param_1,char *param_2)

{
  (**(code **)(*(int *)this + 0x18))();
  return;
}


/* __thiscall JKRFileCache::readFsResource(void *,
                                           unsigned long,
                                           char const *) */

void __thiscall
JKRFileCache::readFsResource(JKRFileCache *this,void *param_1,ulong param_2,char *param_3)

{
  (**(code **)(*(int *)this + 0x1c))();
  return;
}


/* __thiscall JKRFileCache::readNameResource(void *,
                                             unsigned long,
                                             unsigned long,
                                             char const *) */

void __thiscall
JKRFileCache::readNameResource
          (JKRFileCache *this,void *param_1,ulong param_2,ulong param_3,char *param_4)

{
  (**(code **)(*(int *)this + 0x20))();
  return;
}

