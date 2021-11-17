#include <JKernel/JKRAramArchive.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRArchivePri.h>
#include <JKernel/JKRAramArchive.h>
#include <JSupport/JSUList.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRDvdFile.h>
#include <JKernel/JKRDvdRipper.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <JKernel/JKRAramHeap.h>
#include <JKernel/JKRDvdAramRipper.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <JKernel/JKRAram.h>
#include <JKernel/JKRDisposer.h>
#include <JKRAramArchive.h>
#include <JKRFile.h>


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRAramArchive::JKRAramArchive(long,
                                             JKRArchive::EMountDirection) */

void __thiscall
JKRAramArchive::JKRAramArchive(JKRAramArchive *this,long param_1,EMountDirection param_2)

{
  uint uVar1;
  int __oflag;
  
  __oflag = 2;
  JKRArchive::JKRArchive(&this->parent,param_1,ARAM);
  (this->parent).parent.parent.vtbl = &__vt;
  (this->parent).mMountDirection = param_2;
  uVar1 = open(this,(char *)param_1,__oflag);
  if ((uVar1 & 0xff) != 0) {
    (this->parent).parent.field_0x2c = 0x52415243;
    (this->parent).parent.field_0x28 =
         (this->parent).mpStrData + *(int *)((this->parent).mpNodes + 4);
    JSUPtrList::prepend(&JKRFileLoader::sVolumeList,&(this->parent).parent.mVolumeLink);
    (this->parent).parent.mbIsMounted = 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRAramArchive::~JKRAramArchive(void) */

void __thiscall JKRAramArchive::_JKRAramArchive(JKRAramArchive *this)

{
  JKRArchive__DataHeader *__ptr;
  void *__ptr_00;
  int *piVar1;
  JKRArchive__Header *pJVar2;
  short in_r4;
  uint uVar3;
  SDIFileEntry *pSVar4;
  
  if (this != (JKRAramArchive *)0x0) {
    (this->parent).parent.parent.vtbl = &__vt;
    if ((this->parent).parent.mbIsMounted == 1) {
      if ((this->parent).mpDataHeader != (JKRArchive__DataHeader *)0x0) {
        pSVar4 = (this->parent).mpFileEntries;
        for (uVar3 = 0; __ptr = (this->parent).mpDataHeader, uVar3 < (uint)__ptr->mFileEntryCount;
            uVar3 = uVar3 + 1) {
          if (pSVar4->mpData != (void *)0x0) {
            JKRHeap::free(pSVar4->mpData,(this->parent).mpHeap);
          }
          pSVar4 = pSVar4 + 1;
        }
        JKRHeap::free(__ptr,(this->parent).mpHeap);
        (this->parent).mpDataHeader = (JKRArchive__DataHeader *)0x0;
      }
      __ptr_00 = (void *)(this->parent).field_0x50;
      if (__ptr_00 != (void *)0x0) {
        JKRHeap::free(__ptr_00,(JKRHeap *)0x0);
        (this->parent).field_0x50 = 0;
      }
      piVar1 = this->field_0x68;
      if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) {
        (**(code **)(*piVar1 + 8))(piVar1,1);
      }
      pJVar2 = (this->parent).mpHeader;
      if ((pJVar2 != (JKRArchive__Header *)0x0) && (pJVar2 != (JKRArchive__Header *)0x0)) {
        (**(code **)(pJVar2->mSignature + 8))(pJVar2,1);
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


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRAramArchive::open(long) */

int __thiscall JKRAramArchive::open(JKRAramArchive *this,char *__file,int __oflag,...)

{
  int iVar1;
  JKRDvdFile *this_00;
  uchar *__ptr;
  JKRArchive__DataHeader *pJVar2;
  JKRArchive__Header *pJVar3;
  void *__ptr_00;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 align;
  SDIFileEntry *pSVar7;
  ulong uVar8;
  
  (this->parent).mpDataHeader = (JKRArchive__DataHeader *)0x0;
  (this->parent).mpNodes = (undefined *)0x0;
  (this->parent).mpFileEntries = (SDIFileEntry *)0x0;
  (this->parent).mpStrData = (char *)0x0;
  (this->parent).mpHeader = (JKRArchive__Header *)0x0;
  align = 0xfffffffc;
  if ((this->parent).mMountDirection == 1) {
    align = 4;
  }
  this_00 = (JKRDvdFile *)JKernel::operator_new(0xf8,JKRHeap::sSystemHeap,align);
  if (this_00 != (JKRDvdFile *)0x0) {
    JKRDvdFile::JKRDvdFile(this_00,(long)__file);
  }
  this->field_0x68 = (int *)this_00;
  if (this->field_0x68 == (int *)0x0) {
    (this->parent).mMountMode = None;
    return 0;
  }
  __ptr = (uchar *)JKRHeap::alloc(JKRHeap::sSystemHeap,0x20,-0x20);
  if (__ptr == (uchar *)0x0) {
    (this->parent).mMountMode = None;
  }
  else {
    JKRDvdRipper::loadToMainRAM
              ((long)__file,__ptr,1,0x20,(JKRHeap *)0x0,1,0,(int *)&(this->parent).mCompressionType)
    ;
    iVar5 = -0x20;
    if ((this->parent).mMountDirection == 1) {
      iVar5 = 0x20;
    }
    uVar6 = *(int *)(__ptr + 0xc) + 0x1fU & 0xffffffe0;
    pJVar2 = (JKRArchive__DataHeader *)JKRHeap::alloc(uVar6,iVar5,(this->parent).mpHeap);
    (this->parent).mpDataHeader = pJVar2;
    pJVar2 = (this->parent).mpDataHeader;
    if (pJVar2 == (JKRArchive__DataHeader *)0x0) {
      (this->parent).mMountMode = None;
    }
    else {
      uVar8 = 1;
      JKRDvdRipper::loadToMainRAM
                ((long)__file,(uchar *)pJVar2,1,uVar6,(JKRHeap *)0x0,1,0x20,(int *)0x0);
      pJVar2 = (this->parent).mpDataHeader;
      (this->parent).mpNodes = (undefined *)((int)&pJVar2->mNodeCount + pJVar2->mNodeOffs);
      pJVar2 = (this->parent).mpDataHeader;
      (this->parent).mpFileEntries =
           (SDIFileEntry *)((int)&pJVar2->mNodeCount + pJVar2->mFileEntryOffs);
      pJVar2 = (this->parent).mpDataHeader;
      (this->parent).mpStrData = (char *)((int)&pJVar2->mNodeCount + pJVar2->mStrTableOffs);
      (this->parent).field_0x50 = 0;
      uVar6 = 0;
      pSVar7 = (this->parent).mpFileEntries;
      for (iVar1 = ((this->parent).mpDataHeader)->mFileEntryCount; iVar1 != 0; iVar1 = iVar1 + -1) {
        if (((uint)pSVar7->mAttrAndNameOffs >> 0x18 & 1) != 0) {
          uVar6 = uVar6 | (uint)pSVar7->mAttrAndNameOffs >> 0x18 & 4;
        }
        pSVar7 = pSVar7 + 1;
      }
      if (uVar6 != 0) {
        iVar5 = MSL_C.PPCEABI.bare.H::abs(iVar5);
        iVar5 = JKRHeap::alloc(((this->parent).mpDataHeader)->mFileEntryCount << 2,iVar5,
                               (this->parent).mpHeap);
        (this->parent).field_0x50 = iVar5;
        iVar5 = (this->parent).field_0x50;
        if (iVar5 == 0) {
          JKRHeap::free((this->parent).mpDataHeader,(JKRHeap *)0x0);
          (this->parent).mMountMode = None;
          goto LAB_802ba46c;
        }
        FUN_800033a8(iVar5,0,((this->parent).mpDataHeader)->mFileEntryCount << 2);
      }
      iVar5 = -(this->parent).mMountDirection;
      iVar1 = iVar5 + 1;
      pJVar3 = (JKRArchive__Header *)
               JKRAramHeap::alloc(JKRAram::sAramObject->mpHeap,
                                  *(int *)(__ptr + 0x10) + 0x1fU & 0xffffffe0,
                                  iVar1 - ((uint)(iVar1 == 0) + iVar5));
      (this->parent).mpHeader = pJVar3;
      pJVar3 = (this->parent).mpHeader;
      if (pJVar3 == (JKRArchive__Header *)0x0) {
        pJVar2 = (this->parent).mpDataHeader;
        if (pJVar2 != (JKRArchive__DataHeader *)0x0) {
          JKRHeap::free(pJVar2,(JKRHeap *)0x0);
        }
        __ptr_00 = (void *)(this->parent).field_0x50;
        if (__ptr_00 != (void *)0x0) {
          JKRHeap::free(__ptr_00,(JKRHeap *)0x0);
        }
        (this->parent).mMountMode = None;
      }
      else {
        JKRDvdAramRipper::loadToAram
                  ((JKRDvdAramRipper *)__file,pJVar3->mSizeOfMemPart,1,
                   *(int *)(__ptr + 8) + *(int *)(__ptr + 0xc),0,uVar8);
      }
    }
  }
LAB_802ba46c:
  if (__ptr != (uchar *)0x0) {
    JKRHeap::free(JKRHeap::sSystemHeap,__ptr);
  }
  if ((this->parent).mMountMode == None) {
    m_Do_printf::OSReport(":::[%s: %d] Cannot alloc memory\n","JKRAramArchive.cpp",400);
    piVar4 = this->field_0x68;
    if ((piVar4 != (int *)0x0) && (piVar4 != (int *)0x0)) {
      (**(code **)(*piVar4 + 8))(piVar4,1);
    }
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
  }
  return iVar5;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRAramArchive::fetchResource(JKRArchive::SDIFileEntry *,
                                            unsigned long *) */

void * __thiscall
JKRAramArchive::fetchResource(JKRAramArchive *this,SDIFileEntry *param_1,ulong *param_2)

{
  ulong uVar1;
  uchar **in_r8;
  JKRHeap *pJVar2;
  void *local_18;
  ulong local_14;
  
  if ((this->parent).parent.mbIsMounted == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRAramArchive.cpp",0x1ab,"isMounted()");
    m_Do_printf::OSPanic("JKRAramArchive.cpp",0x1ab,&DAT_8036b9df);
  }
  if (param_2 == (ulong *)0x0) {
    param_2 = &local_14;
  }
  if (((uint)param_1->mAttrAndNameOffs >> 0x18 & 4) == 0) {
    pJVar2 = (JKRHeap *)0x0;
  }
  else {
    if (((uint)param_1->mAttrAndNameOffs >> 0x18 & 0x80) == 0) {
      pJVar2 = (JKRHeap *)&DAT_00000001;
    }
    else {
      pJVar2 = (JKRHeap *)&DAT_00000002;
    }
  }
  if (param_1->mpData == (void *)0x0) {
    uVar1 = fetchResource_subroutine
                      ((JKRAramArchive *)
                       (param_1->mDataOffs + ((this->parent).mpHeader)->mSizeOfMemPart),
                       param_1->mDataSize,(ulong)(this->parent).mpHeap,pJVar2,(int)&local_18,in_r8);
    *param_2 = uVar1;
    if (uVar1 == 0) {
      return (void *)0x0;
    }
    param_1->mpData = local_18;
    if (pJVar2 == (JKRHeap *)&DAT_00000002) {
      (*(code *)((this->parent).parent.parent.vtbl)->setExpandSize)(this,param_1,*param_2);
    }
  }
  else {
    if (pJVar2 == (JKRHeap *)&DAT_00000002) {
      uVar1 = (*(code *)((this->parent).parent.parent.vtbl)->getExpandSize)(this,param_1);
      *param_2 = uVar1;
    }
    else {
      *param_2 = param_1->mDataSize;
    }
  }
  return param_1->mpData;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall JKRAramArchive::fetchResource(void *,
                                            unsigned long,
                                            JKRArchive::SDIFileEntry *,
                                            unsigned long *) */

void * __thiscall
JKRAramArchive::fetchResource
          (JKRAramArchive *this,void *param_1,ulong param_2,SDIFileEntry *param_3,ulong *param_4)

{
  ulong uVar1;
  void *pvVar2;
  void *pvVar3;
  char *pcVar4;
  int in_r8;
  
  pcVar4 = (char *)param_3;
  if ((this->parent).parent.mbIsMounted == 0) {
    uVar1 = JUTAssertion::getSDevice();
    pcVar4 = "isMounted()";
    JUTAssertion::showAssert(uVar1,"JKRAramArchive.cpp",500,"isMounted()");
    m_Do_printf::OSPanic("JKRAramArchive.cpp",500,&DAT_8036b9df);
  }
  pvVar2 = (void *)param_3->mDataSize;
  if (param_2 < (void *)param_3->mDataSize) {
    pvVar2 = (void *)param_2;
  }
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
  if (param_3->mpData == (void *)0x0) {
    pvVar2 = (void *)fetchResource_subroutine
                               ((JKRAramArchive *)
                                (param_3->mDataOffs + ((this->parent).mpHeader)->mSizeOfMemPart),
                                (ulong)pvVar2,(ulong)param_1,(uchar *)(param_2 & 0xffffffe0),uVar1,
                                in_r8);
  }
  else {
    if ((uVar1 == 2) &&
       (pvVar3 = (void *)(*(code *)((this->parent).parent.parent.vtbl)->getExpandSize)(this,param_3)
       , pvVar3 != (void *)0x0)) {
      pvVar2 = pvVar3;
    }
    if (param_2 < pvVar2) {
      pvVar2 = (void *)param_2;
    }
    JKRHeap::copyMemory((JKRHeap *)param_1,param_3->mpData,pvVar2,(ulong)pcVar4);
  }
  if (param_4 != (ulong *)0x0) {
    *param_4 = (ulong)pvVar2;
  }
  return param_1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRAramArchive::fetchResource_subroutine(unsigned long,
                                                       unsigned long,
                                                       unsigned char *,
                                                       unsigned long,
                                                       int) */

ulong * __thiscall
JKRAramArchive::fetchResource_subroutine
          (JKRAramArchive *this,ulong param_1,ulong param_2,uchar *param_3,ulong param_4,int param_5
          )

{
  uchar *puVar1;
  ulong uVar2;
  uchar *puVar3;
  ulong *in_stack_ffffffd8;
  
  if (((uint)this & 0x1f) != 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JKRAramArchive.cpp",0x265,"( srcAram & 0x1f ) == 0");
    m_Do_printf::OSPanic("JKRAramArchive.cpp",0x265,&DAT_8036b9df);
  }
  puVar3 = (uchar *)(param_1 + 0x1f & 0xffffffe0);
  puVar1 = (uchar *)((uint)param_3 & 0xffffffe0);
  if (param_4 == 0) {
    if (puVar1 < puVar3) {
      puVar3 = puVar1;
    }
    JKRAram::aramToMainRam
              ((JKRAram *)this,param_2,puVar3,0,(JKRExpandSwitch)puVar1,0,(JKRHeap *)&DAT_ffffffff,
               (int)&stack0xffffffd8,in_stack_ffffffd8);
  }
  else {
    if (((int)param_4 < 0) || (2 < (int)param_4)) {
      m_Do_printf::OSPanic("JKRAramArchive.cpp",0x280,":::??? bad sequence\n");
      in_stack_ffffffd8 = (ulong *)0x0;
    }
    else {
      JKRAram::aramToMainRam
                ((JKRAram *)this,param_2,puVar3,1,(JKRExpandSwitch)puVar1,0,(JKRHeap *)&DAT_ffffffff
                 ,(int)&stack0xffffffd8,in_stack_ffffffd8);
    }
  }
  return in_stack_ffffffd8;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall JKRAramArchive::fetchResource_subroutine(unsigned long,
                                                       unsigned long,
                                                       JKRHeap *,
                                                       int,
                                                       unsigned char * *) */

ulong __thiscall
JKRAramArchive::fetchResource_subroutine
          (JKRAramArchive *this,ulong param_1,ulong param_2,JKRHeap *param_3,int param_4,
          uchar **param_5)

{
  uchar *size;
  uint size_00;
  ulong uVar1;
  ulong uVar2;
  ulong *in_stack_ffffff98;
  undefined auStack96 [4];
  byte bStack92;
  byte bStack91;
  byte bStack90;
  byte bStack89;
  
  size = (uchar *)(param_1 + 0x1f & 0xffffffe0);
  if (param_3 == (JKRHeap *)0x0) {
    uVar1 = JKRHeap::alloc((ulong)size,0x20,(JKRHeap *)param_2);
    if (uVar1 == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"JKRAramArchive.cpp",0x296,"buffer != 0");
      m_Do_printf::OSPanic("JKRAramArchive.cpp",0x296,&DAT_8036b9df);
    }
    JKRAram::aramToMainRam
              ((JKRAram *)this,uVar1,size,0,(JKRExpandSwitch)size,0,(JKRHeap *)&DAT_ffffffff,0,
               in_stack_ffffff98);
    *(ulong *)param_4 = uVar1;
  }
  else {
    if (((int)param_3 < 0) || (2 < (int)param_3)) {
      m_Do_printf::OSPanic("JKRAramArchive.cpp",0x2ba,":::??? bad sequence\n");
      param_1 = 0;
    }
    else {
      JKRAram::aramToMainRam
                ((JKRAram *)this,(ulong)auStack96,&DAT_00000020,0,0,0,(JKRHeap *)&DAT_ffffffff,0,
                 in_stack_ffffff98);
      size_00 = ((uint)bStack89 |
                (uint)bStack90 << 8 | (uint)bStack92 << 0x18 | (uint)bStack91 << 0x10) + 0x1f &
                0xffffffe0;
      uVar1 = JKRHeap::alloc(size_00,0x20,(JKRHeap *)param_2);
      param_1 = (ulong)in_stack_ffffff98;
      if (uVar1 == 0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"JKRAramArchive.cpp",0x2b0,"buffer");
        m_Do_printf::OSPanic("JKRAramArchive.cpp",0x2b0,&DAT_8036b9df);
        param_1 = (ulong)in_stack_ffffff98;
      }
      JKRAram::aramToMainRam
                ((JKRAram *)this,uVar1,size,1,size_00,param_2,(JKRHeap *)&DAT_ffffffff,
                 (int)&stack0xffffff98,(ulong *)param_1);
      *(ulong *)param_4 = uVar1;
    }
  }
  return param_1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRAramArchive::getExpandedResSize(void const *) const */

uint __thiscall JKRAramArchive::getExpandedResSize(JKRAramArchive *this,void *param_1)

{
  uint uVar1;
  SDIFileEntry *pSVar2;
  ulong *in_stack_ffffffa8;
  undefined auStack64 [4];
  byte bStack60;
  byte bStack59;
  byte bStack58;
  byte bStack57;
  
  if ((this->parent).field_0x50 == 0) {
    uVar1 = (*(code *)((this->parent).parent.parent.vtbl)->getResSize)();
  }
  else {
    pSVar2 = JKRArchive::findPtrResource(&this->parent,param_1);
    if (pSVar2 == (SDIFileEntry *)0x0) {
      uVar1 = 0xffffffff;
    }
    else {
      if (((uint)pSVar2->mAttrAndNameOffs >> 0x18 & 4) == 0) {
        uVar1 = (*(code *)((this->parent).parent.parent.vtbl)->getResSize)(this,param_1);
      }
      else {
        uVar1 = (*(code *)((this->parent).parent.parent.vtbl)->getExpandSize)(this,pSVar2);
        if (uVar1 == 0) {
          JKRAram::aramToMainRam
                    ((JKRAram *)(pSVar2->mDataOffs + ((this->parent).mpHeader)->mSizeOfMemPart),
                     (ulong)auStack64,&DAT_00000020,0,0,0,(JKRHeap *)&DAT_ffffffff,0,
                     in_stack_ffffffa8);
          uVar1 = (uint)bStack57 |
                  (uint)bStack58 << 8 | (uint)bStack60 << 0x18 | (uint)bStack59 << 0x10;
          (*(code *)((this->parent).parent.parent.vtbl)->setExpandSize)(this,pSVar2,uVar1);
        }
      }
    }
  }
  return uVar1;
}


/* __thiscall JKRFile::~JKRFile(void) */

void __thiscall JKRFile::_JKRFile(JKRFile *this)

{
  short in_r4;
  
  if (this != (JKRFile *)0x0) {
    *(undefined1 **)this = &__vt;
    JKRDisposer::_JKRDisposer((JKRDisposer *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

