#include <JKernel/JKRDvdArchive.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRArchivePri.h>
#include <JKernel/JKRDvdArchive.h>
#include <JSupport/JSUList.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRDvdFile.h>
#include <JKernel/JKRDvdRipper.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <os/OSCache.h>
#include <JKRDvdArchive.h>


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRDvdArchive::JKRDvdArchive(long,
                                           JKRArchive::EMountDirection) */

void __thiscall
JKRDvdArchive::JKRDvdArchive(JKRDvdArchive *this,long param_1,EMountDirection param_2)

{
  uint uVar1;
  int __oflag;
  
  __oflag = 3;
  JKRArchive::JKRArchive((JKRArchive *)this,param_1,DVD);
  this->field_0x0 = (int)&__vt;
  this->field_0x60 = param_2;
  uVar1 = open(this,(char *)param_1,__oflag);
  if ((uVar1 & 0xff) != 0) {
    *(undefined4 *)&this->field_0x2c = 0x52415243;
    *(int *)&this->field_0x28 = this->field_0x54 + *(int *)(this->field_0x48 + 4);
    JSUPtrList::prepend(&JKRFileLoader::sVolumeList,(JSUPtrLink *)&this->field_0x18);
    *(undefined *)&this->field_0x30 = 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRDvdArchive::~JKRDvdArchive(void) */

void __thiscall JKRDvdArchive::_JKRDvdArchive(JKRDvdArchive *this)

{
  JKRDvdFile *pJVar1;
  short in_r4;
  uint uVar2;
  int iVar3;
  
  if (this != (JKRDvdArchive *)0x0) {
    this->field_0x0 = (int)&__vt;
    if (*(char *)&this->field_0x30 == '\x01') {
      if (this->field_0x44 != 0) {
        iVar3 = this->field_0x4c;
        for (uVar2 = 0; uVar2 < *(uint *)((int)(void *)this->field_0x44 + 8); uVar2 = uVar2 + 1) {
          if (*(void **)(iVar3 + 0x10) != (void *)0x0) {
            JKRHeap::free(*(void **)(iVar3 + 0x10),(JKRHeap *)this->field_0x38);
          }
          iVar3 = iVar3 + 0x14;
        }
        JKRHeap::free((void *)this->field_0x44,(JKRHeap *)this->field_0x38);
        this->field_0x44 = 0;
      }
      if ((void *)this->field_0x50 != (void *)0x0) {
        JKRHeap::free((void *)this->field_0x50,(JKRHeap *)0x0);
        this->field_0x50 = 0;
      }
      pJVar1 = this->field_0x68;
      if ((pJVar1 != (JKRDvdFile *)0x0) && (pJVar1 != (JKRDvdFile *)0x0)) {
        (*(code *)((pJVar1->parent).vtbl)->_)(pJVar1,1);
      }
      JSUPtrList::remove(&JKRFileLoader::sVolumeList,(JSUPtrLink *)&this->field_0x18);
      *(undefined *)&this->field_0x30 = 0;
    }
    JKRArchive::_JKRArchive((JKRArchive *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRDvdArchive::open(long) */

int __thiscall JKRDvdArchive::open(JKRDvdArchive *this,char *__file,int __oflag,...)

{
  int iVar1;
  JKRDvdFile *pJVar2;
  uchar *__ptr;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  this->field_0x44 = 0;
  this->field_0x64 = 0;
  this->field_0x48 = 0;
  this->field_0x4c = 0;
  this->field_0x54 = 0;
  pJVar2 = (JKRDvdFile *)JKernel::operator_new(0xf8,JKRHeap::sSystemHeap,0);
  if (pJVar2 != (JKRDvdFile *)0x0) {
    JKRDvdFile::JKRDvdFile(pJVar2,(long)__file);
  }
  this->field_0x68 = pJVar2;
  if (this->field_0x68 == (JKRDvdFile *)0x0) {
    this->field_0x3c = '\0';
    return 0;
  }
  __ptr = (uchar *)JKRHeap::alloc(JKRHeap::sSystemHeap,0x20,0x20);
  if (__ptr == (uchar *)0x0) {
    this->field_0x3c = '\0';
  }
  else {
    JKRDvdRipper::loadToMainRAM((long)__file,__ptr,1,0x20,(JKRHeap *)0x0,1,0,&this->field_0x5c);
    iVar4 = -0x20;
    if (this->field_0x60 == 1) {
      iVar4 = 0x20;
    }
    iVar3 = JKRHeap::alloc(*(ulong *)(__ptr + 0xc),iVar4,(JKRHeap *)this->field_0x38);
    this->field_0x44 = iVar3;
    if ((uchar *)this->field_0x44 == (uchar *)0x0) {
      this->field_0x3c = '\0';
    }
    else {
      JKRDvdRipper::loadToMainRAM
                ((long)__file,(uchar *)this->field_0x44,1,*(ulong *)(__ptr + 0xc),(JKRHeap *)0x0,1,
                 0x20,(int *)0x0);
      this->field_0x48 = this->field_0x44 + *(int *)(this->field_0x44 + 4);
      this->field_0x4c = this->field_0x44 + *(int *)(this->field_0x44 + 0xc);
      this->field_0x54 = this->field_0x44 + *(int *)(this->field_0x44 + 0x14);
      this->field_0x50 = 0;
      uVar5 = 0;
      iVar3 = this->field_0x4c;
      for (iVar1 = *(int *)(this->field_0x44 + 8); iVar1 != 0; iVar1 = iVar1 + -1) {
        if ((*(uint *)(iVar3 + 4) >> 0x18 & 1) != 0) {
          uVar5 = uVar5 | *(uint *)(iVar3 + 4) >> 0x18 & 4;
        }
        iVar3 = iVar3 + 0x14;
      }
      if (uVar5 != 0) {
        iVar4 = MSL_C.PPCEABI.bare.H::abs(iVar4);
        iVar4 = JKRHeap::alloc(*(int *)(this->field_0x44 + 8) << 2,iVar4,(JKRHeap *)this->field_0x38
                              );
        this->field_0x50 = iVar4;
        if (this->field_0x50 == 0) {
          JKRHeap::free(JKRHeap::sSystemHeap,(void *)this->field_0x44);
          this->field_0x3c = '\0';
          goto LAB_802bafa4;
        }
        FUN_800033a8(this->field_0x50,0,*(int *)(this->field_0x44 + 8) << 2);
      }
      this->field_0x64 = *(int *)(__ptr + 8) + *(int *)(__ptr + 0xc);
    }
  }
LAB_802bafa4:
  if (__ptr != (uchar *)0x0) {
    JKRHeap::free(JKRHeap::sSystemHeap,__ptr);
  }
  if (this->field_0x3c == '\0') {
    m_Do_printf::OSReport(":::Cannot alloc memory [%s][%d]\n","JKRDvdArchive.cpp",0x17e);
    pJVar2 = this->field_0x68;
    if ((pJVar2 != (JKRDvdFile *)0x0) && (pJVar2 != (JKRDvdFile *)0x0)) {
      (*(code *)((pJVar2->parent).vtbl)->_)(pJVar2,1);
    }
    iVar4 = 0;
  }
  else {
    iVar4 = 1;
  }
  return iVar4;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRDvdArchive::fetchResource(JKRArchive::SDIFileEntry *,
                                           unsigned long *) */

void * __thiscall
JKRDvdArchive::fetchResource(JKRDvdArchive *this,SDIFileEntry *fileEntry,ulong *param_2)

{
  ulong uVar1;
  uchar **in_r10;
  JKRHeap *pJVar2;
  void *local_18;
  ulong local_14;
  
  if (*(char *)&this->field_0x30 == '\0') {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRDvdArchive.cpp",0x19d,"isMounted()");
    m_Do_printf::OSPanic("JKRDvdArchive.cpp",0x19d,&DAT_8036ba76);
  }
  if (param_2 == (ulong *)0x0) {
    param_2 = &local_14;
  }
  if (((uint)fileEntry->mAttrAndNameOffs >> 0x18 & 4) == 0) {
    pJVar2 = (JKRHeap *)0x0;
  }
  else {
    if (((uint)fileEntry->mAttrAndNameOffs >> 0x18 & 0x80) == 0) {
      pJVar2 = (JKRHeap *)&DAT_00000001;
    }
    else {
      pJVar2 = (JKRHeap *)&DAT_00000002;
    }
  }
  if (fileEntry->mpData == (void *)0x0) {
    uVar1 = fetchResource_subroutine
                      (this->field_0x40,this->field_0x64 + fileEntry->mDataOffs,fileEntry->mDataSize
                       ,this->field_0x38,pJVar2,this->field_0x5c,(int)&local_18,in_r10);
    *param_2 = uVar1;
    if (uVar1 == 0) {
      return (void *)0x0;
    }
    fileEntry->mpData = local_18;
    if (pJVar2 == (JKRHeap *)&DAT_00000002) {
      (**(code **)(this->field_0x0 + 0x48))(this,fileEntry,*param_2);
    }
  }
  else {
    if (pJVar2 == (JKRHeap *)&DAT_00000002) {
      uVar1 = (**(code **)(this->field_0x0 + 0x4c))(this,fileEntry);
      *param_2 = uVar1;
    }
    else {
      *param_2 = fileEntry->mDataSize;
    }
  }
  return fileEntry->mpData;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall JKRDvdArchive::fetchResource(void *,
                                           unsigned long,
                                           JKRArchive::SDIFileEntry *,
                                           unsigned long *) */

void * __thiscall
JKRDvdArchive::fetchResource
          (JKRDvdArchive *this,void *param_1,ulong param_2,SDIFileEntry *fileEntry,ulong *param_4)

{
  ulong uVar1;
  void *pvVar2;
  void *pvVar3;
  char *pcVar4;
  int in_r10;
  
  pcVar4 = (char *)fileEntry;
  if (*(char *)&this->field_0x30 == '\0') {
    uVar1 = JUTAssertion::getSDevice();
    pcVar4 = "isMounted()";
    JUTAssertion::showAssert(uVar1,"JKRDvdArchive.cpp",0x1e9,"isMounted()");
    m_Do_printf::OSPanic("JKRDvdArchive.cpp",0x1e9,&DAT_8036ba76);
  }
  pvVar3 = (void *)fileEntry->mDataSize;
  if (((uint)fileEntry->mAttrAndNameOffs >> 0x18 & 4) == 0) {
    uVar1 = 0;
  }
  else {
    if (((uint)fileEntry->mAttrAndNameOffs >> 0x18 & 0x80) == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 2;
    }
  }
  if (fileEntry->mpData == (void *)0x0) {
    pvVar3 = (void *)fetchResource_subroutine
                               (this->field_0x40,this->field_0x64 + fileEntry->mDataOffs,
                                (ulong)pvVar3,(ulong)param_1,(uchar *)(param_2 & 0xffffffe0),uVar1,
                                this->field_0x5c,in_r10);
  }
  else {
    if ((uVar1 == 2) &&
       (pvVar2 = (void *)(**(code **)(this->field_0x0 + 0x4c))(this,fileEntry),
       pvVar2 != (void *)0x0)) {
      pvVar3 = pvVar2;
    }
    if (param_2 < pvVar3) {
      pvVar3 = (void *)param_2;
    }
    JKRHeap::copyMemory((JKRHeap *)param_1,fileEntry->mpData,pvVar3,(ulong)pcVar4);
  }
  if (param_4 != (ulong *)0x0) {
    *param_4 = (ulong)pvVar3;
  }
  return param_1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall JKRDvdArchive::fetchResource_subroutine(long,
                                                      unsigned long,
                                                      unsigned long,
                                                      unsigned char *,
                                                      unsigned long,
                                                      int,
                                                      int) */

ulong __thiscall
JKRDvdArchive::fetchResource_subroutine
          (JKRDvdArchive *this,long param_1,ulong param_2,ulong param_3,uchar *param_4,ulong param_5
          ,int param_6,int param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uchar auStack64 [4];
  byte bStack60;
  byte bStack59;
  byte bStack58;
  byte bStack57;
  
  uVar2 = param_2 + 0x1f & 0xffffffe0;
  uVar1 = (uint)param_4 & 0xffffffe0;
  if (param_6 == 1) {
    m_Do_printf::OSPanic("JKRDvdArchive.cpp",0x25b,"Sorry, not prepared for SZP archive.\n");
    return 0;
  }
  if (param_6 < 1) {
    if (-1 < param_6) {
      if (param_5 == 0) {
        if (uVar1 < uVar2) {
          uVar2 = uVar1;
        }
        JKRDvdRipper::loadToMainRAM
                  ((long)this,(uchar *)param_3,0,uVar2,(JKRHeap *)0x0,1,param_1,(int *)0x0);
        return uVar2;
      }
      if ((-1 < (int)param_5) && ((int)param_5 < 3)) {
        JKRDvdRipper::loadToMainRAM((long)this,auStack64,2,0x20,(JKRHeap *)0x0,1,param_1,(int *)0x0)
        ;
        os::DCInvalidateRange(auStack64,0x20);
        uVar3 = (uint)bStack57 |
                (uint)bStack58 << 8 | (uint)bStack60 << 0x18 | (uint)bStack59 << 0x10;
        uVar2 = uVar3 + 0x1f & 0xffffffe0;
        if (uVar1 < uVar2) {
          uVar2 = uVar1;
        }
        JKRDvdRipper::loadToMainRAM
                  ((long)this,(uchar *)param_3,1,uVar2,(JKRHeap *)0x0,1,param_1,(int *)0x0);
        return uVar3;
      }
LAB_802bb3f0:
      if (uVar1 < param_2) {
        param_2 = uVar1;
      }
      JKRDvdRipper::loadToMainRAM
                ((long)this,(uchar *)param_3,1,param_2,(JKRHeap *)0x0,1,param_1,(int *)0x0);
      return param_2;
    }
  }
  else {
    if (param_6 < 3) goto LAB_802bb3f0;
  }
  m_Do_printf::OSPanic("JKRDvdArchive.cpp",0x261,":::??? bad sequence\n");
  return 0;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall JKRDvdArchive::fetchResource_subroutine(long,
                                                      unsigned long,
                                                      unsigned long,
                                                      JKRHeap *,
                                                      int,
                                                      int,
                                                      unsigned char * *) */

uint __thiscall
JKRDvdArchive::fetchResource_subroutine
          (JKRDvdArchive *this,long param_1,ulong param_2,ulong param_3,JKRHeap *param_4,int param_5
          ,int param_6,uchar **param_7)

{
  uchar *puVar1;
  ulong uVar2;
  uint uVar3;
  uchar auStack96 [4];
  byte bStack92;
  byte bStack91;
  byte bStack90;
  byte bStack89;
  
  uVar3 = param_2 + 0x1f & 0xffffffe0;
  if (param_5 == 1) {
    m_Do_printf::OSPanic("JKRDvdArchive.cpp",0x2ab,"Sorry, not prepared for SZP archive.\n");
    return 0;
  }
  if (param_5 < 1) {
    if (-1 < param_5) {
      if (param_4 == (JKRHeap *)0x0) {
        puVar1 = (uchar *)JKRHeap::alloc(uVar3,0x20,(JKRHeap *)param_3);
        if (puVar1 == (uchar *)0x0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"JKRDvdArchive.cpp",0x277,"buffer != 0");
          m_Do_printf::OSPanic("JKRDvdArchive.cpp",0x277,&DAT_8036ba76);
        }
        JKRDvdRipper::loadToMainRAM((long)this,puVar1,0,uVar3,(JKRHeap *)0x0,1,param_1,(int *)0x0);
        *(uchar **)param_6 = puVar1;
        return uVar3;
      }
      if ((-1 < (int)param_4) && ((int)param_4 < 3)) {
        JKRDvdRipper::loadToMainRAM((long)this,auStack96,2,0x20,(JKRHeap *)0x0,1,param_1,(int *)0x0)
        ;
        os::DCInvalidateRange(auStack96,0x20);
        uVar3 = (uint)bStack89 |
                (uint)bStack90 << 8 | (uint)bStack92 << 0x18 | (uint)bStack91 << 0x10;
        puVar1 = (uchar *)JKRHeap::alloc(uVar3,0x20,(JKRHeap *)param_3);
        if (puVar1 == (uchar *)0x0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"JKRDvdArchive.cpp",0x294,"buffer");
          m_Do_printf::OSPanic("JKRDvdArchive.cpp",0x294,&DAT_8036ba76);
        }
        JKRDvdRipper::loadToMainRAM((long)this,puVar1,1,uVar3,(JKRHeap *)0x0,1,param_1,(int *)0x0);
        *(uchar **)param_6 = puVar1;
        return uVar3;
      }
LAB_802bb62c:
      puVar1 = (uchar *)JKRHeap::alloc(uVar3,0x20,(JKRHeap *)param_3);
      if (puVar1 == (uchar *)0x0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"JKRDvdArchive.cpp",0x2a0,"buffer");
        m_Do_printf::OSPanic("JKRDvdArchive.cpp",0x2a0,&DAT_8036ba76);
      }
      JKRDvdRipper::loadToMainRAM((long)this,puVar1,1,param_2,(JKRHeap *)0x0,1,param_1,(int *)0x0);
      *(uchar **)param_6 = puVar1;
      return uVar3;
    }
  }
  else {
    if (param_5 < 3) goto LAB_802bb62c;
  }
  m_Do_printf::OSPanic("JKRDvdArchive.cpp",0x2b0,":::??? bad sequence\n");
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRDvdArchive::getExpandedResSize(void const *) const */

uint __thiscall JKRDvdArchive::getExpandedResSize(JKRDvdArchive *this,void *param_1)

{
  uint uVar1;
  SDIFileEntry *pSVar2;
  uchar auStack64 [4];
  byte bStack60;
  byte bStack59;
  byte bStack58;
  byte bStack57;
  
  if (this->field_0x50 == 0) {
    uVar1 = (**(code **)(this->field_0x0 + 0x30))();
  }
  else {
    pSVar2 = JKRArchive::findPtrResource((JKRArchive *)this,param_1);
    if (pSVar2 == (SDIFileEntry *)0x0) {
      uVar1 = 0xffffffff;
    }
    else {
      if (((uint)pSVar2->mAttrAndNameOffs >> 0x18 & 4) == 0) {
        uVar1 = (**(code **)(this->field_0x0 + 0x30))(this,param_1);
      }
      else {
        uVar1 = (**(code **)(this->field_0x0 + 0x4c))(this,pSVar2);
        if (uVar1 == 0) {
          JKRDvdRipper::loadToMainRAM
                    ((long)this->field_0x40,auStack64,2,0x20,(JKRHeap *)0x0,1,
                     this->field_0x64 + pSVar2->mDataOffs,(int *)0x0);
          os::DCInvalidateRange(auStack64,0x20);
          uVar1 = (uint)bStack57 |
                  (uint)bStack58 << 8 | (uint)bStack60 << 0x18 | (uint)bStack59 << 0x10;
          (**(code **)(this->field_0x0 + 0x48))(this,pSVar2,uVar1);
        }
      }
    }
  }
  return uVar1;
}

