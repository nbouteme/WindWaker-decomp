#include <JKernel/JKRArchivePub.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <dvd/dvdfs.h>
#include <JKernel/JKRArchivePub.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRMemArchive.h>
#include <JKernel/JKRAramArchive.h>
#include <JKernel/JKRDvdArchive.h>
#include <JKernel/JKRCompArchive.h>
#include <JKernel/JKRArchivePri.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKernel/JKRFileFinder.h>
#include <Demangler/JKRArchive.h>


namespace JKRArchive {

/* __thiscall check_mount_already(long) */

undefined * check_mount_already(long param_1)

{
  JSUPtrLink *pJVar1;
  undefined *puVar2;
  
  pJVar1 = JKRFileLoader::sVolumeList.mpHead;
  while( true ) {
    if (pJVar1 == (JSUPtrLink *)0x0) {
      return (undefined *)0x0;
    }
    puVar2 = pJVar1->mpData;
    if ((*(int *)(puVar2 + 0x2c) == 0x52415243) && (*(int *)(puVar2 + 0x40) == param_1)) break;
    pJVar1 = pJVar1->mpNext;
  }
  *(int *)(puVar2 + 0x34) = *(int *)(puVar2 + 0x34) + 1;
  return puVar2;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRArchive::mount(char const *,
                                JKRArchive::EMountMode,
                                JKRHeap *,
                                JKRArchive::EMountDirection) */

int __thiscall
JKRArchive::mount(JKRArchive *this,char *__special_file,char *__dir,char *__fstype,ulong __rwflag,
                 void *__data)

{
  int iVar1;
  
  iVar1 = dvd::DVDConvertPathToEntrynum((char *)this);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = mount(iVar1,(EMountMode)__special_file,(JKRHeap *)__dir,(EMountDirection)__fstype);
  }
  return iVar1;
}


namespace JKRArchive {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall mount(long,
                                EMountMode,
                                JKRHeap *,
                                EMountDirection) */

int mount(long param_1,EMountMode mountMode,JKRHeap *param_3,EMountDirection param_4)

{
  JKRCompArchive *pJVar1;
  undefined3 in_register_00000010;
  int iVar2;
  undefined4 align;
  JKRCompArchive *local_r31__1;
  
  iVar2 = CONCAT31(in_register_00000010,mountMode);
  pJVar1 = (JKRCompArchive *)check_mount_already(param_1);
  if (pJVar1 == (JKRCompArchive *)0x0) {
    align = 0xfffffffc;
    if (param_4 == 1) {
      align = 4;
    }
    if (iVar2 == 3) {
      pJVar1 = (JKRCompArchive *)JKernel::operator_new(0x6c,param_3,align);
      if (pJVar1 != (JKRCompArchive *)0x0) {
        JKRDvdArchive::JKRDvdArchive((JKRDvdArchive *)pJVar1,param_1,param_4);
      }
    }
    else {
      pJVar1 = local_r31__1;
      if (iVar2 < 3) {
        if (iVar2 == 1) {
          pJVar1 = (JKRCompArchive *)JKernel::operator_new(0x70,param_3,align);
          if (pJVar1 != (JKRCompArchive *)0x0) {
            JKRMemArchive::JKRMemArchive((JKRMemArchive *)pJVar1,param_1,param_4);
          }
        }
        else {
          if ((0 < iVar2) &&
             (pJVar1 = (JKRCompArchive *)JKernel::operator_new(0x6c,param_3,align),
             pJVar1 != (JKRCompArchive *)0x0)) {
            JKRAramArchive::JKRAramArchive((JKRAramArchive *)pJVar1,param_1,param_4);
          }
        }
      }
      else {
        if ((iVar2 < 5) &&
           (pJVar1 = (JKRCompArchive *)JKernel::operator_new(0x80,param_3,align),
           pJVar1 != (JKRCompArchive *)0x0)) {
          JKRCompArchive::JKRCompArchive(pJVar1,param_1,param_4);
        }
      }
    }
    if ((pJVar1 != (JKRCompArchive *)0x0) && ((pJVar1->parent).mMountMode == None)) {
      if (pJVar1 != (JKRCompArchive *)0x0) {
        (*(code *)((pJVar1->parent).parent.parent.vtbl)->_)(pJVar1,1);
      }
      pJVar1 = (JKRCompArchive *)0x0;
    }
  }
  return (int)pJVar1;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRArchive::becomeCurrent(char const *) */

bool __thiscall JKRArchive::becomeCurrent(JKRArchive *this,char *param_1)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  
  if (*param_1 == '/') {
    pcVar3 = param_1 + 1;
    if (*pcVar3 == '\0') {
      pcVar3 = (char *)0x0;
    }
    iVar2 = findDirectory(this,pcVar3,0);
  }
  else {
    iVar2 = findDirectory(this,param_1,_sCurrentDirID);
  }
  if (iVar2 != 0) {
    uVar1 = iVar2 - (int)this->mpNodes;
    _sCurrentDirID = ((int)uVar1 >> 4) + (uint)((int)uVar1 < 0 && (uVar1 & 0xf) != 0);
    _sCurrentVolume = this;
  }
  return iVar2 != 0;
}


/* __thiscall JKRArchive::getDirEntry(JKRArchive::SDirEntry *,
                                      unsigned long) const */

bool __thiscall JKRArchive::getDirEntry(JKRArchive *this,SDirEntry *param_1,ulong param_2)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)findIdxResource(this,param_2);
  if (puVar1 != (undefined2 *)0x0) {
    *param_1 = SUB41((uint)*(undefined4 *)(puVar1 + 2) >> 0x18,0);
    *(undefined2 *)(param_1 + 2) = *puVar1;
    *(char **)(param_1 + 4) = this->mpStrData + (*(uint *)(puVar1 + 2) & 0xffffff);
  }
  return puVar1 != (undefined2 *)0x0;
}


namespace JKRArchive {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall getGlbResource(unsigned long,
                                         char const *,
                                         JKRArchive *) */

int getGlbResource(ulong param_1,char *param_2,JKRArchive *param_3)

{
  int *piVar1;
  int iVar2;
  JSUPtrLink *pJVar3;
  
  iVar2 = 0;
  pJVar3 = JKRFileLoader::sVolumeList.mpHead;
  if (param_3 == (JKRArchive *)0x0) {
    while ((pJVar3 != (JSUPtrLink *)0x0 &&
           ((piVar1 = (int *)pJVar3->mpData, piVar1[0xb] != 0x52415243 ||
            (iVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,param_1,param_2), iVar2 == 0))))) {
      pJVar3 = pJVar3->mpNext;
    }
  }
  else {
    iVar2 = (*(code *)((param_3->parent).parent.vtbl)->getResource2)(param_3,param_1,param_2);
  }
  return iVar2;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRArchive::getResource(char const *) */

undefined4 __thiscall JKRArchive::getResource(JKRArchive *this,char *param_1)

{
  ulong uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((this->parent).mbIsMounted == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRArchivePub.cpp",0x11d,"isMounted()");
    m_Do_printf::OSPanic("JKRArchivePub.cpp",0x11d,&DAT_8036b916);
  }
  if (*param_1 == '/') {
    iVar2 = findFsResource(this,param_1 + 1,0);
  }
  else {
    iVar2 = findFsResource(this,param_1,_sCurrentDirID);
  }
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (*(code *)((this->parent).parent.vtbl)->fetchResource1)(this,iVar2,0);
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRArchive::getResource(unsigned long,
                                      char const *) */

undefined4 __thiscall JKRArchive::getResource(JKRArchive *this,ulong param_1,char *param_2)

{
  ulong uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((this->parent).mbIsMounted == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRArchivePub.cpp",0x14c,"isMounted()");
    m_Do_printf::OSPanic("JKRArchivePub.cpp",0x14c,&DAT_8036b916);
  }
  if ((param_1 == 0) || (param_1 == 0x3f3f3f3f)) {
    iVar2 = findNameResource(this,param_2);
  }
  else {
    iVar2 = findTypeResource(this,param_1,param_2);
  }
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (*(code *)((this->parent).parent.vtbl)->fetchResource1)(this,iVar2,0);
  }
  return uVar3;
}


namespace JKRArchive {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall readTypeResource(void *,
                                           unsigned long,
                                           unsigned long,
                                           char const *,
                                           JKRArchive *) */

int readTypeResource
              (void *pDst,ulong size,ulong param_3,char *pFilename,JKRArchive *pArc)

{
  int iVar1;
  int *piVar2;
  JSUPtrLink *pJVar3;
  
  iVar1 = 0;
  pJVar3 = JKRFileLoader::sVolumeList.mpHead;
  if (pArc == (JKRArchive *)0x0) {
    while ((pJVar3 != (JSUPtrLink *)0x0 &&
           ((piVar2 = (int *)pJVar3->mpData, piVar2[0xb] != 0x52415243 ||
            (iVar1 = (**(code **)(*piVar2 + 0x20))(piVar2,pDst,size,param_3,pFilename), iVar1 == 0))
           ))) {
      pJVar3 = pJVar3->mpNext;
    }
  }
  else {
    iVar1 = (*(code *)((pArc->parent).parent.vtbl)->readResource2)(pArc,pDst,size,param_3,pFilename)
    ;
  }
  return iVar1;
}

}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRArchive::readResource(void *,
                                       unsigned long,
                                       unsigned long,
                                       char const *) */

undefined4 __thiscall
JKRArchive::readResource(JKRArchive *this,void *param_1,ulong param_2,ulong param_3,char *param_4)

{
  ulong uVar1;
  int iVar2;
  undefined4 local_28 [5];
  
  if ((this->parent).mbIsMounted == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRArchivePub.cpp",0x1eb,"isMounted()");
    m_Do_printf::OSPanic("JKRArchivePub.cpp",0x1eb,&DAT_8036b916);
  }
  if ((param_3 == 0) || (param_3 == 0x3f3f3f3f)) {
    iVar2 = findNameResource(this,param_4);
  }
  else {
    iVar2 = findTypeResource(this,param_3,param_4);
  }
  if (iVar2 == 0) {
    local_28[0] = 0;
  }
  else {
    (*(code *)((this->parent).parent.vtbl)->fetchResource2)(this,param_1,param_2,iVar2,local_28);
  }
  return local_28[0];
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRArchive::readResource(void *,
                                       unsigned long,
                                       char const *) */

undefined4 __thiscall
JKRArchive::readResource(JKRArchive *this,void *param_1,ulong param_2,char *param_3)

{
  ulong uVar1;
  int iVar2;
  undefined4 local_18 [2];
  
  if ((this->parent).mbIsMounted == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRArchivePub.cpp",0x219,"isMounted()");
    m_Do_printf::OSPanic("JKRArchivePub.cpp",0x219,&DAT_8036b916);
  }
  if (*param_3 == '/') {
    iVar2 = findFsResource(this,param_3 + 1,0);
  }
  else {
    iVar2 = findFsResource(this,param_3,_sCurrentDirID);
  }
  if (iVar2 == 0) {
    local_18[0] = 0;
  }
  else {
    (*(code *)((this->parent).parent.vtbl)->fetchResource2)(this,param_1,param_2,iVar2,local_18);
  }
  return local_18[0];
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRArchive::readIdxResource(void *,
                                          unsigned long,
                                          unsigned long) */

int __thiscall
JKRArchive::readIdxResource(JKRArchive *this,void *param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  int iVar2;
  int local_18;
  
  if ((this->parent).mbIsMounted == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRArchivePub.cpp",0x251,"isMounted()");
    m_Do_printf::OSPanic("JKRArchivePub.cpp",0x251,&DAT_8036b916);
  }
  iVar2 = findIdxResource(this,param_3);
  if (iVar2 == 0) {
    local_18 = 0;
  }
  else {
    (*(code *)((this->parent).parent.vtbl)->fetchResource2)(this,param_1,param_2,iVar2,&local_18);
  }
  return local_18;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRArchive::readResource(void *,
                                       unsigned long,
                                       unsigned short) */

undefined4 __thiscall
JKRArchive::readResource(JKRArchive *this,void *param_1,ulong param_2,ushort param_3)

{
  ulong uVar1;
  int iVar2;
  undefined4 local_18 [2];
  
  if ((this->parent).mbIsMounted == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRArchivePub.cpp",0x273,"isMounted()");
    m_Do_printf::OSPanic("JKRArchivePub.cpp",0x273,&DAT_8036b916);
  }
  iVar2 = findIdResource(this,param_3);
  if (iVar2 == 0) {
    local_18[0] = 0;
  }
  else {
    (*(code *)((this->parent).parent.vtbl)->fetchResource2)(this,param_1,param_2,iVar2,local_18);
  }
  return local_18[0];
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRArchive::removeResourceAll(void) */

void __thiscall JKRArchive::removeResourceAll(JKRArchive *this)

{
  uint uVar1;
  SDIFileEntry *pSVar2;
  
  if ((this->mpDataHeader != (JKRArchive__DataHeader *)0x0) && (this->mMountMode != Mem)) {
    pSVar2 = this->mpFileEntries;
    for (uVar1 = 0; uVar1 < (uint)this->mpDataHeader->mFileEntryCount; uVar1 = uVar1 + 1) {
      if (pSVar2->mpData != (void *)0x0) {
        JKRHeap::free(pSVar2->mpData,this->mpHeap);
        pSVar2->mpData = (void *)0x0;
      }
      pSVar2 = pSVar2 + 1;
    }
  }
  return;
}


/* __thiscall JKRArchive::removeResource(void *) */

bool __thiscall JKRArchive::removeResource(JKRArchive *this,void *param_1)

{
  ulong uVar1;
  SDIFileEntry *pSVar2;
  
  if (param_1 == (void *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRArchivePub.cpp",0x2af,"resource != 0");
    m_Do_printf::OSPanic("JKRArchivePub.cpp",0x2af,&DAT_8036b916);
  }
  pSVar2 = findPtrResource(this,param_1);
  if (pSVar2 != (SDIFileEntry *)0x0) {
    pSVar2->mpData = (void *)0x0;
    JKRHeap::free(param_1,this->mpHeap);
  }
  return pSVar2 != (SDIFileEntry *)0x0;
}


/* __thiscall JKRArchive::detachResource(void *) */

bool __thiscall JKRArchive::detachResource(JKRArchive *this,void *param_1)

{
  ulong uVar1;
  SDIFileEntry *pSVar2;
  
  if (param_1 == (void *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRArchivePub.cpp",0x2cf,"resource != 0");
    m_Do_printf::OSPanic("JKRArchivePub.cpp",0x2cf,&DAT_8036b916);
  }
  pSVar2 = findPtrResource(this,param_1);
  if (pSVar2 != (SDIFileEntry *)0x0) {
    pSVar2->mpData = (void *)0x0;
  }
  return pSVar2 != (SDIFileEntry *)0x0;
}


/* __thiscall JKRArchive::getResSize(void const *) const */

int __thiscall JKRArchive::getResSize(JKRArchive *this,void *param_1)

{
  ulong uVar1;
  SDIFileEntry *pSVar2;
  int iVar3;
  
  if (param_1 == (void *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRArchivePub.cpp",0x2ea,"resource != 0");
    m_Do_printf::OSPanic("JKRArchivePub.cpp",0x2ea,&DAT_8036b916);
  }
  pSVar2 = findPtrResource(this,param_1);
  if (pSVar2 == (SDIFileEntry *)0x0) {
    iVar3 = -1;
  }
  else {
    iVar3 = pSVar2->mDataSize;
  }
  return iVar3;
}


/* __thiscall JKRArchive::countResource(unsigned long) const */

int __thiscall JKRArchive::countResource(JKRArchive *this,ulong param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = findResType(this,param_1);
  if (iVar1 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = 0;
    uVar4 = *(uint *)(iVar1 + 0xc);
    uVar3 = uVar4 + *(ushort *)(iVar1 + 10);
    iVar2 = uVar4 * 0x14;
    iVar1 = uVar3 - uVar4;
    if (uVar4 < uVar3) {
      do {
        if ((*(uint *)((int)&this->mpFileEntries->mAttrAndNameOffs + iVar2) >> 0x18 & 1) != 0) {
          iVar5 = iVar5 + 1;
        }
        iVar2 = iVar2 + 0x14;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return iVar5;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRArchive::countFile(char const *) const */

undefined2 __thiscall JKRArchive::countFile(JKRArchive *this,char *param_1)

{
  int iVar1;
  undefined2 uVar2;
  char *pcVar3;
  
  if (*param_1 == '/') {
    pcVar3 = param_1 + 1;
    if (*pcVar3 == '\0') {
      pcVar3 = (char *)0x0;
    }
    iVar1 = findDirectory(this,pcVar3,0);
  }
  else {
    iVar1 = findDirectory(this,param_1,_sCurrentDirID);
  }
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined2 *)(iVar1 + 10);
  }
  return uVar2;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRArchive::getFirstFile(char const *) const */

JKRArcFinder * __thiscall JKRArchive::getFirstFile(JKRArchive *this,char *param_1)

{
  int iVar1;
  JKRArcFinder *this_00;
  char *pcVar2;
  
  if (*param_1 == '/') {
    pcVar2 = param_1 + 1;
    if (*pcVar2 == '\0') {
      pcVar2 = (char *)0x0;
    }
    iVar1 = findDirectory(this,pcVar2,0);
  }
  else {
    iVar1 = findDirectory(this,param_1,_sCurrentDirID);
  }
  if (iVar1 == 0) {
    this_00 = (JKRArcFinder *)0x0;
  }
  else {
    this_00 = (JKRArcFinder *)JKernel::operator_new(0x24,JKRHeap::sSystemHeap,0);
    if (this_00 != (JKRArcFinder *)0x0) {
      JKRArcFinder::JKRArcFinder(this_00,this,*(long *)(iVar1 + 0xc),(uint)*(ushort *)(iVar1 + 10));
    }
  }
  return this_00;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRArchive::getFirstResource(unsigned long) const */

JKRArcFinder * __thiscall JKRArchive::getFirstResource(JKRArchive *this,ulong param_1)

{
  int iVar1;
  uint uVar2;
  JKRArcFinder *this_00;
  long lVar3;
  
  iVar1 = findResType(this,param_1);
  if ((iVar1 == 0) || (uVar2 = getFileAttribute(this,*(ulong *)(iVar1 + 0xc)), (uVar2 & 1) == 0)) {
    this_00 = (JKRArcFinder *)JKernel::operator_new(0x24,JKRHeap::sSystemHeap,0);
    if (this_00 != (JKRArcFinder *)0x0) {
      JKRArcFinder::JKRArcFinder(this_00,this,0,0);
    }
  }
  else {
    this_00 = (JKRArcFinder *)JKernel::operator_new(0x24,JKRHeap::sSystemHeap,0);
    if (this_00 != (JKRArcFinder *)0x0) {
      lVar3 = countResource(this,param_1);
      JKRArcFinder::JKRArcFinder(this_00,this,*(long *)(iVar1 + 0xc),lVar3);
    }
  }
  return this_00;
}


/* __thiscall JKRArchive::getFileAttribute(unsigned long) const */

uint __thiscall JKRArchive::getFileAttribute(JKRArchive *this,ulong param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = findIdxResource(this,param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(uint *)(iVar1 + 4) >> 0x18;
  }
  return uVar2;
}

