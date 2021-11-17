#include <JKernel/JKRArchivePri.h>
#include <JKernel/JKRFileLoader.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JKernel/JKRArchivePri.h>
#include <MSL_C.PPCEABI.bare.H/ctype.h>
#include <Demangler/JKRArchive.h>
#include <Demangler/JKRArchive/CArcName.h>


namespace JKRArchive {
undefined1 sCurrentDirID;
}

/* __thiscall JKRArchive::JKRArchive(void) */

void __thiscall JKRArchive::JKRArchive(JKRArchive *this)

{
  JKRFileLoader::JKRFileLoader(&this->parent);
  (this->parent).parent.vtbl = &__vt;
  (this->parent).mbIsMounted = 0;
  this->mMountDirection = 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRArchive::JKRArchive(long,
                                     JKRArchive::EMountMode) */

void __thiscall JKRArchive::JKRArchive(JKRArchive *this,long param_1,EMountMode param_2)

{
  JKRHeap *pJVar1;
  
  JKRFileLoader::JKRFileLoader(&this->parent);
  (this->parent).parent.vtbl = &__vt;
  (this->parent).mbIsMounted = 0;
  this->mMountMode = param_2;
  (this->parent).field_0x34 = 1;
  this->field_0x58 = 1;
  pJVar1 = JKRHeap::findFromRoot(this);
  this->mpHeap = pJVar1;
  if (this->mpHeap == (JKRHeap *)0x0) {
    this->mpHeap = JKRHeap::sCurrentHeap;
  }
  this->field_0x40 = (JKRDvdArchive *)param_1;
  if (_sCurrentVolume == (JKRArchive *)0x0) {
    _sCurrentDirID = 0;
    _sCurrentVolume = this;
  }
  return;
}


/* __thiscall JKRArchive::~JKRArchive(void) */

void __thiscall JKRArchive::_JKRArchive(JKRArchive *this)

{
  short in_r4;
  
  if (this != (JKRArchive *)0x0) {
    (this->parent).parent.vtbl = &__vt;
    JKRFileLoader::_JKRFileLoader(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JKRArchive::isSameName(JKRArchive::CArcName &,
                                     unsigned long,
                                     unsigned short) const */

uint __thiscall
JKRArchive::isSameName(JKRArchive *this,CArcName *param_1,ulong param_2,ushort param_3)

{
  uint uVar1;
  int iVar2;
  
  if (param_1->mHash == param_3) {
    iVar2 = MSL_C.PPCEABI.bare.H::strcmp(this->mpStrData + param_2,param_1->mName);
    uVar1 = countLeadingZeros(iVar2);
    uVar1 = uVar1 >> 5;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall JKRArchive::findResType(unsigned long) const */

ulong * __thiscall JKRArchive::findResType(JKRArchive *this,ulong param_1)

{
  int iVar1;
  ulong *puVar2;
  
  puVar2 = (ulong *)this->mpNodes;
  iVar1 = this->mpDataHeader->mNodeCount;
  while( true ) {
    if (iVar1 == 0) {
      return (ulong *)0x0;
    }
    if (*puVar2 == param_1) break;
    puVar2 = puVar2 + 4;
    iVar1 = iVar1 + -1;
  }
  return puVar2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRArchive::findDirectory(char const *,
                                        unsigned long) const */

undefined * __thiscall JKRArchive::findDirectory(JKRArchive *this,char *param_1,ulong param_2)

{
  undefined *puVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  SDIFileEntry *pSVar5;
  CArcName CStack296;
  
  if (param_1 == (char *)0x0) {
    puVar1 = this->mpNodes + param_2 * 0x10;
  }
  else {
    pcVar2 = (char *)CArcName::store(&CStack296,param_1,'/');
    puVar1 = this->mpNodes;
    pSVar5 = this->mpFileEntries + *(int *)(puVar1 + param_2 * 0x10 + 0xc);
    for (iVar4 = 0; iVar4 < (int)(uint)*(ushort *)(puVar1 + param_2 * 0x10 + 10); iVar4 = iVar4 + 1)
    {
      cVar3 = isSameName(this,&CStack296,pSVar5->mAttrAndNameOffs & 0xffffff,pSVar5->mNameHash);
      if (cVar3 != '\0') {
        if (((uint)pSVar5->mAttrAndNameOffs >> 0x18 & 2) != 0) {
          puVar1 = (undefined *)findDirectory(this,pcVar2,pSVar5->mDataOffs);
          return puVar1;
        }
        break;
      }
      pSVar5 = pSVar5 + 1;
    }
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRArchive::findTypeResource(unsigned long,
                                           char const *) const */

SDIFileEntry * __thiscall JKRArchive::findTypeResource(JKRArchive *this,ulong param_1,char *param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  SDIFileEntry *pSVar4;
  CArcName CStack280;
  
  if (param_1 != 0) {
    CArcName::store(&CStack280,param_2);
    iVar1 = findResType(this,param_1);
    if (iVar1 != 0) {
      pSVar4 = this->mpFileEntries + *(int *)(iVar1 + 0xc);
      for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)(iVar1 + 10); iVar3 = iVar3 + 1) {
        cVar2 = isSameName(this,&CStack280,pSVar4->mAttrAndNameOffs & 0xffffff,pSVar4->mNameHash);
        if (cVar2 != '\0') {
          return pSVar4;
        }
        pSVar4 = pSVar4 + 1;
      }
    }
  }
  return (SDIFileEntry *)0x0;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRArchive::findFsResource(char const *,
                                         unsigned long) const */

SDIFileEntry * __thiscall JKRArchive::findFsResource(JKRArchive *this,char *param_1,ulong param_2)

{
  char *pcVar1;
  undefined *puVar2;
  char cVar4;
  SDIFileEntry *pSVar3;
  int iVar5;
  CArcName CStack296;
  
  if (param_1 != (char *)0x0) {
    pcVar1 = (char *)CArcName::store(&CStack296,param_1,'/');
    puVar2 = this->mpNodes;
    pSVar3 = this->mpFileEntries + *(int *)(puVar2 + param_2 * 0x10 + 0xc);
    for (iVar5 = 0; iVar5 < (int)(uint)*(ushort *)(puVar2 + param_2 * 0x10 + 10); iVar5 = iVar5 + 1)
    {
      cVar4 = isSameName(this,&CStack296,pSVar3->mAttrAndNameOffs & 0xffffff,pSVar3->mNameHash);
      if (cVar4 != '\0') {
        if (((uint)pSVar3->mAttrAndNameOffs >> 0x18 & 2) != 0) {
          pSVar3 = (SDIFileEntry *)findFsResource(this,pcVar1,pSVar3->mDataOffs);
          return pSVar3;
        }
        if (pcVar1 == (char *)0x0) {
          return pSVar3;
        }
        return (SDIFileEntry *)0x0;
      }
      pSVar3 = pSVar3 + 1;
    }
  }
  return (SDIFileEntry *)0x0;
}


/* __thiscall JKRArchive::findIdxResource(unsigned long) const */

SDIFileEntry * __thiscall JKRArchive::findIdxResource(JKRArchive *this,ulong param_1)

{
  if (param_1 < (uint)this->mpDataHeader->mFileEntryCount) {
    return this->mpFileEntries + param_1;
  }
  return (SDIFileEntry *)0x0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRArchive::findNameResource(char const *) const */

SDIFileEntry * __thiscall JKRArchive::findNameResource(JKRArchive *this,char *param_1)

{
  char cVar1;
  uint uVar2;
  SDIFileEntry *pSVar3;
  CArcName CStack280;
  
  pSVar3 = this->mpFileEntries;
  CArcName::store(&CStack280,param_1);
  uVar2 = 0;
  while( true ) {
    if ((uint)this->mpDataHeader->mFileEntryCount <= uVar2) {
      return (SDIFileEntry *)0x0;
    }
    cVar1 = isSameName(this,&CStack280,pSVar3->mAttrAndNameOffs & 0xffffff,pSVar3->mNameHash);
    if (cVar1 != '\0') break;
    pSVar3 = pSVar3 + 1;
    uVar2 = uVar2 + 1;
  }
  return pSVar3;
}


/* __thiscall JKRArchive::findPtrResource(void const *) const */

SDIFileEntry * __thiscall JKRArchive::findPtrResource(JKRArchive *this,void *dataPtr)

{
  int iVar1;
  SDIFileEntry *pSVar2;
  
  pSVar2 = this->mpFileEntries;
  iVar1 = this->mpDataHeader->mFileEntryCount;
  while( true ) {
    if (iVar1 == 0) {
      return (SDIFileEntry *)0x0;
    }
    if (pSVar2->mpData == dataPtr) break;
    pSVar2 = pSVar2 + 1;
    iVar1 = iVar1 + -1;
  }
  return pSVar2;
}


/* __thiscall JKRArchive::findIdResource(unsigned short) const */

SDIFileEntry * __thiscall JKRArchive::findIdResource(JKRArchive *this,ushort param_1)

{
  uint uVar1;
  int iVar2;
  SDIFileEntry *pSVar3;
  SDIFileEntry *pSVar4;
  
  uVar1 = (uint)param_1;
  if (uVar1 != 0xffff) {
    pSVar3 = this->mpFileEntries;
    pSVar4 = pSVar3 + uVar1;
    if (((ushort)pSVar4->mId == uVar1) && (((uint)pSVar4->mAttrAndNameOffs >> 0x18 & 1) != 0)) {
      return pSVar4;
    }
    for (iVar2 = this->mpDataHeader->mFileEntryCount; iVar2 != 0; iVar2 = iVar2 + -1) {
      if ((pSVar3->mId == param_1) && (((uint)pSVar3->mAttrAndNameOffs >> 0x18 & 1) != 0)) {
        return pSVar3;
      }
      pSVar3 = pSVar3 + 1;
    }
  }
  return (SDIFileEntry *)0x0;
}


namespace JKRArchive {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall CArcName::store(char const *) */

void __thiscall CArcName::store(CArcName *this,char *param_1)

{
  int iVar1;
  int iVar2;
  
  this->mHash = 0;
  iVar2 = 0;
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    iVar1 = MSL_C.PPCEABI.bare.H::tolower((int)*param_1);
    this->mHash = (short)iVar1 + this->mHash * 3;
    if (iVar2 < 0x100) {
      this->mName[iVar2] = (char)iVar1;
      iVar2 = iVar2 + 1;
    }
  }
  this->mSize = (short)iVar2;
  this->mName[iVar2] = '\0';
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall CArcName::store(char const *,
                                          char) */

char * __thiscall CArcName::store(CArcName *this,char *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  this->mHash = 0;
  iVar4 = 0;
  while( true ) {
    cVar1 = *param_1;
    if ((cVar1 == '\0') || (cVar1 == param_2)) break;
    iVar2 = MSL_C.PPCEABI.bare.H::tolower((int)cVar1);
    this->mHash = (short)iVar2 + this->mHash * 3;
    if (iVar4 < 0x100) {
      this->mName[iVar4] = (char)iVar2;
      iVar4 = iVar4 + 1;
    }
    param_1 = param_1 + 1;
  }
  this->mSize = (short)iVar4;
  this->mName[iVar4] = '\0';
  if (*param_1 == '\0') {
    pcVar3 = (char *)0x0;
  }
  else {
    pcVar3 = param_1 + 1;
  }
  return pcVar3;
}

}

/* __thiscall JKRArchive::setExpandSize(JKRArchive::SDIFileEntry *,
                                        unsigned long) */

void __thiscall JKRArchive::setExpandSize(JKRArchive *this,SDIFileEntry *param_1,ulong param_2)

{
  uint uVar1;
  
  uVar1 = ((int)param_1 - (int)this->mpFileEntries) / 0x14;
  if (this->field_0x50 == 0) {
    return;
  }
  if ((uint)this->mpDataHeader->mFileEntryCount <= uVar1) {
    return;
  }
  *(ulong *)(this->field_0x50 + uVar1 * 4) = param_2;
  return;
}


/* __thiscall JKRArchive::getExpandSize(JKRArchive::SDIFileEntry *) const */

undefined4 __thiscall JKRArchive::getExpandSize(JKRArchive *this,SDIFileEntry *param_1)

{
  uint uVar1;
  
  uVar1 = ((int)param_1 - (int)this->mpFileEntries) / 0x14;
  if ((this->field_0x50 != 0) && (uVar1 < (uint)this->mpDataHeader->mFileEntryCount)) {
    return *(undefined4 *)(this->field_0x50 + uVar1 * 4);
  }
  return 0;
}

