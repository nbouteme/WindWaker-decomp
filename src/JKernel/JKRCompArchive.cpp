#include <JKernel/JKRCompArchive.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRArchivePri.h>
#include <JKernel/JKRCompArchive.h>
#include <JSupport/JSUList.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRDvdFile.h>
#include <JKernel/JKRDvdRipper.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKernel/JKRAramHeap.h>
#include <JKernel/JKRDvdAramRipper.h>
#include <JKernel/JKRDecomp.h>
#include <JKernel/JKRAram.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <JKernel/JKRAramArchive.h>
#include <JKernel/JKRDvdArchive.h>
#include <JKernel/JKRMemArchive.h>
#include <os/OSCache.h>
#include <JKRCompArchive.h>


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRCompArchive::JKRCompArchive(long,
                                             JKRArchive::EMountDirection) */

void __thiscall
JKRCompArchive::JKRCompArchive(JKRCompArchive *this,long param_1,EMountDirection param_2)

{
  uint uVar1;
  int __oflag;
  
  __oflag = 4;
  JKRArchive::JKRArchive(&this->parent,param_1,Comp);
  (this->parent).parent.parent.vtbl = (JKRArchive__vtbl *)&__vt;
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
/* __thiscall JKRCompArchive::~JKRCompArchive(void) */

void __thiscall JKRCompArchive::_JKRCompArchive(JKRCompArchive *this)

{
  JKRArchive__DataHeader *__ptr;
  JKRAramHeap *pJVar1;
  void *__ptr_00;
  int *piVar2;
  short in_r4;
  uint uVar3;
  SDIFileEntry *pSVar4;
  
  if (this != (JKRCompArchive *)0x0) {
    (this->parent).parent.parent.vtbl = (JKRArchive__vtbl *)&__vt;
    if ((this->parent).mpDataHeader != (JKRArchive__DataHeader *)0x0) {
      pSVar4 = (this->parent).mpFileEntries;
      uVar3 = 0;
      while( true ) {
        __ptr = (this->parent).mpDataHeader;
        if ((uint)__ptr->mFileEntryCount <= uVar3) break;
        if ((((uint)pSVar4->mAttrAndNameOffs >> 0x18 & 0x10) == 0) &&
           (pSVar4->mpData != (void *)0x0)) {
          JKRHeap::free(pSVar4->mpData,(this->parent).mpHeap);
        }
        pSVar4 = pSVar4 + 1;
        uVar3 = uVar3 + 1;
      }
      JKRHeap::free(__ptr,(this->parent).mpHeap);
      (this->parent).mpDataHeader = (JKRArchive__DataHeader *)0x0;
    }
    pJVar1 = this->field_0x68;
    if ((pJVar1 != (JKRAramHeap *)0x0) && (pJVar1 != (JKRAramHeap *)0x0)) {
      (**(code **)(pJVar1->vtbl + 8))(pJVar1,1);
    }
    __ptr_00 = (void *)(this->parent).field_0x50;
    if (__ptr_00 != (void *)0x0) {
      JKRHeap::free(__ptr_00,(JKRHeap *)0x0);
      (this->parent).field_0x50 = 0;
    }
    piVar2 = this->field_0x70;
    if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0x0)) {
      (**(code **)(*piVar2 + 8))(piVar2,1);
    }
    JSUPtrList::remove(&JKRFileLoader::sVolumeList,&(this->parent).parent.mVolumeLink);
    (this->parent).parent.mbIsMounted = 0;
    JKRArchive::_JKRArchive(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall JKRCompArchive::open(long) */

int __thiscall JKRCompArchive::open(JKRCompArchive *this,char *__file,int __oflag,...)

{
  uint uVar1;
  uchar *size;
  JKRDecomp__CompressionType archiveCompType;
  JKRDvdFile *this_00;
  ulong uVar2;
  JKRArchive__DataHeader *pJVar3;
  JKRAramHeap *pJVar4;
  JKRDecomp *this_01;
  JKRArchive__Header *pJVar5;
  JKRHeap *this_02;
  int *piVar6;
  int iVar7;
  uint uVar8;
  SDIFileEntry *pSVar9;
  ulong uVar10;
  int unaff_r29;
  JKRArchive__Header *header;
  
  (this->parent).mpDataHeader = (JKRArchive__DataHeader *)0x0;
  (this->parent).mpHeader = (JKRArchive__Header *)0x0;
  this->field_0x68 = (JKRAramHeap *)0x0;
  this->field_0x6c = 0;
  this->mSizeOfMemPart = 0;
  this->mSizeOfAramPart = 0;
  this->field_0x7c = 0;
  (this->parent).mpNodes = (undefined *)0x0;
  (this->parent).mpFileEntries = (SDIFileEntry *)0x0;
  (this->parent).mpStrData = (char *)0x0;
  this_00 = (JKRDvdFile *)JKernel::operator_new(0xf8,JKRHeap::sSystemHeap,0);
  if (this_00 != (JKRDvdFile *)0x0) {
    JKRDvdFile::JKRDvdFile(this_00,(long)__file);
  }
  this->field_0x70 = (int *)this_00;
  if (this->field_0x70 == (int *)0x0) {
    (this->parent).mMountMode = None;
    return 0;
  }
  header = (JKRArchive__Header *)JKRHeap::alloc(JKRHeap::sSystemHeap,0x20,-0x20);
  if (header == (JKRArchive__Header *)0x0) {
    (this->parent).mMountMode = None;
    goto LAB_802bbf5c;
  }
  JKRDvdRipper::loadToMainRAM
            ((long)__file,(uchar *)header,1,0x20,(JKRHeap *)0x0,1,0,
             (int *)&(this->parent).mCompressionType);
  this->mSizeOfMemPart = header->mSizeOfMemPart;
  this->mSizeOfAramPart = header->mSizeOfAramPart;
  if ((this->mSizeOfMemPart & 0x1fU) != 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JKRCompArchive.cpp",0x15a,"( mSizeOfMemPart & 0x1f ) == 0");
    m_Do_printf::OSPanic("JKRCompArchive.cpp",0x15a,&DAT_8036bb1f);
  }
  if ((this->mSizeOfAramPart & 0x1fU) != 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JKRCompArchive.cpp",0x15b,"( mSizeOfAramPart & 0x1f ) == 0");
    m_Do_printf::OSPanic("JKRCompArchive.cpp",0x15b,&DAT_8036bb1f);
  }
  archiveCompType = (this->parent).mCompressionType;
  if (archiveCompType == Yay0Compressed) {
    iVar7 = (**(code **)(*this->field_0x70 + 0x1c))();
    uVar8 = iVar7 + 0x1fU & 0xffffffe0;
    unaff_r29 = -0x20;
    if ((this->parent).mMountDirection == 1) {
      unaff_r29 = 0x20;
    }
    this_01 = (JKRDecomp *)JKRHeap::alloc(JKRHeap::sSystemHeap,uVar8,-unaff_r29);
    if (this_01 == (JKRDecomp *)0x0) {
      (this->parent).mMountMode = None;
      pJVar5 = header;
    }
    else {
      uVar2 = 0;
      iVar7 = 0;
      JKRDvdRipper::loadToMainRAM
                ((long)__file,(uchar *)this_01,2,uVar8,(JKRHeap *)0x0,1,0,(int *)0x0);
      size = (uchar *)(((uint)(byte)this_01[7] |
                       (uint)(byte)this_01[6] << 8 |
                       (uint)(byte)this_01[4] << 0x18 | (uint)(byte)this_01[5] << 0x10) + 0x1f &
                      0xffffffe0);
      pJVar5 = (JKRArchive__Header *)JKRHeap::alloc((ulong)size,-unaff_r29,(this->parent).mpHeap);
      if (pJVar5 == (JKRArchive__Header *)0x0) {
        (this->parent).mMountMode = None;
        pJVar5 = header;
      }
      else {
        uVar10 = 0;
        JKRDecomp::orderSync(this_01,(uchar *)pJVar5,size,0,uVar2);
        JKRHeap::free(JKRHeap::sSystemHeap,this_01);
        pJVar3 = (JKRArchive__DataHeader *)
                 JKRHeap::alloc(pJVar5->mFileDataOffs + this->mSizeOfMemPart,unaff_r29,
                                (this->parent).mpHeap);
        (this->parent).mpDataHeader = pJVar3;
        this_02 = (JKRHeap *)(this->parent).mpDataHeader;
        if (this_02 == (JKRHeap *)0x0) {
          (this->parent).mMountMode = None;
        }
        else {
          JKRHeap::copyMemory(this_02,pJVar5 + 1,
                              (void *)(pJVar5->mFileDataOffs + this->mSizeOfMemPart),uVar10);
          (this->parent).mpHeader =
               (JKRArchive__Header *)
               ((int)&((this->parent).mpDataHeader)->mNodeCount + pJVar5->mFileDataOffs);
          if (this->mSizeOfAramPart != 0) {
            pJVar4 = (JKRAramHeap *)
                     JKRAramHeap::alloc(JKRAram::sAramObject->mpHeap,this->mSizeOfAramPart,0);
            this->field_0x68 = pJVar4;
            if (this->field_0x68 == (JKRAramHeap *)0x0) {
              (this->parent).mMountMode = None;
            }
            else {
              JKRAram::mainRamToAram
                        ((JKRAram *)
                         ((int)&pJVar5->mSignature +
                         pJVar5->mHeaderSize + pJVar5->mFileDataOffs + this->mSizeOfMemPart),
                         (uchar *)this->field_0x68->field_0x14,this->mSizeOfAramPart,0,0,0,
                         (JKRHeap *)&DAT_ffffffff,iVar7);
            }
          }
        }
      }
    }
    pJVar3 = (this->parent).mpDataHeader;
    (this->parent).mpNodes = (undefined *)((int)&pJVar3->mNodeCount + pJVar3->mNodeOffs);
    pJVar3 = (this->parent).mpDataHeader;
    (this->parent).mpFileEntries =
         (SDIFileEntry *)((int)&pJVar3->mNodeCount + pJVar3->mFileEntryOffs);
    pJVar3 = (this->parent).mpDataHeader;
    (this->parent).mpStrData = (char *)((int)&pJVar3->mNodeCount + pJVar3->mStrTableOffs);
    this->field_0x6c = pJVar5->mHeaderSize + pJVar5->mFileDataOffs;
    header = pJVar5;
  }
  else {
    if ((int)archiveCompType < 1) {
      if (-1 < (int)archiveCompType) {
LAB_802bbb94:
        unaff_r29 = -0x20;
        if ((this->parent).mMountDirection == 1) {
          unaff_r29 = 0x20;
        }
        pJVar3 = (JKRArchive__DataHeader *)
                 JKRHeap::alloc(header->mFileDataOffs + this->mSizeOfMemPart,unaff_r29,
                                (this->parent).mpHeap);
        (this->parent).mpDataHeader = pJVar3;
        pJVar3 = (this->parent).mpDataHeader;
        if (pJVar3 == (JKRArchive__DataHeader *)0x0) {
          (this->parent).mMountMode = None;
        }
        else {
          uVar2 = 1;
          JKRDvdRipper::loadToMainRAM
                    ((long)__file,(uchar *)pJVar3,1,header->mFileDataOffs + this->mSizeOfMemPart,
                     (JKRHeap *)0x0,1,0x20,(int *)0x0);
          (this->parent).mpHeader =
               (JKRArchive__Header *)
               ((int)&((this->parent).mpDataHeader)->mNodeCount + header->mFileDataOffs);
          if (this->mSizeOfAramPart != 0) {
            pJVar4 = (JKRAramHeap *)
                     JKRAramHeap::alloc(JKRAram::sAramObject->mpHeap,this->mSizeOfAramPart,0);
            this->field_0x68 = pJVar4;
            if (this->field_0x68 == (JKRAramHeap *)0x0) {
              (this->parent).mMountMode = None;
              goto LAB_802bbea8;
            }
            JKRDvdAramRipper::loadToAram
                      ((JKRDvdAramRipper *)__file,this->field_0x68->field_0x14,1,
                       header->mHeaderSize + header->mFileDataOffs + this->mSizeOfMemPart,0,uVar2);
          }
          pJVar3 = (this->parent).mpDataHeader;
          (this->parent).mpNodes = (undefined *)((int)&pJVar3->mNodeCount + pJVar3->mNodeOffs);
          pJVar3 = (this->parent).mpDataHeader;
          (this->parent).mpFileEntries =
               (SDIFileEntry *)((int)&pJVar3->mNodeCount + pJVar3->mFileEntryOffs);
          pJVar3 = (this->parent).mpDataHeader;
          (this->parent).mpStrData = (char *)((int)&pJVar3->mNodeCount + pJVar3->mStrTableOffs);
          this->field_0x6c = header->mHeaderSize + header->mFileDataOffs;
        }
      }
    }
    else {
      if ((int)archiveCompType < 3) goto LAB_802bbb94;
    }
  }
LAB_802bbea8:
  (this->parent).field_0x50 = 0;
  uVar8 = 0;
  pSVar9 = (this->parent).mpFileEntries;
  for (iVar7 = ((this->parent).mpDataHeader)->mFileEntryCount; iVar7 != 0; iVar7 = iVar7 + -1) {
    uVar1 = (uint)pSVar9->mAttrAndNameOffs >> 0x18;
    if ((((uint)pSVar9->mAttrAndNameOffs >> 0x18 & 1) != 0) && ((uVar1 & 0x10) == 0)) {
      uVar8 = uVar8 | uVar1 & 4;
    }
    pSVar9 = pSVar9 + 1;
  }
  if (uVar8 != 0) {
    iVar7 = MSL_C.PPCEABI.bare.H::abs(unaff_r29);
    iVar7 = JKRHeap::alloc(((this->parent).mpDataHeader)->mFileEntryCount << 2,iVar7,
                           (this->parent).mpHeap);
    (this->parent).field_0x50 = iVar7;
    iVar7 = (this->parent).field_0x50;
    if (iVar7 == 0) {
      JKRHeap::free(JKRHeap::sSystemHeap,(this->parent).mpDataHeader);
      (this->parent).mMountMode = None;
    }
    else {
      FUN_800033a8(iVar7,0,((this->parent).mpDataHeader)->mFileEntryCount << 2);
    }
  }
LAB_802bbf5c:
  if (header != (JKRArchive__Header *)0x0) {
    JKRHeap::free(JKRHeap::sSystemHeap,header);
  }
  if ((this->parent).mMountMode == None) {
    m_Do_printf::OSReport
              (":::[%s: %d] Cannot alloc memory in mounting CompArchive\n","JKRCompArchive.cpp",
               0x224);
    piVar6 = this->field_0x70;
    if ((piVar6 != (int *)0x0) && (piVar6 != (int *)0x0)) {
      (**(code **)(*piVar6 + 8))(piVar6,1);
    }
    iVar7 = 0;
  }
  else {
    iVar7 = 1;
  }
  return iVar7;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRCompArchive::fetchResource(JKRArchive::SDIFileEntry *,
                                            unsigned long *) */

void * __thiscall
JKRCompArchive::fetchResource(JKRCompArchive *this,SDIFileEntry *param_1,ulong *param_2)

{
  uint uVar1;
  ulong uVar2;
  uchar **in_r8;
  uchar **in_r10;
  JKRHeap *pJVar3;
  void *local_28;
  void *local_24;
  ulong local_20 [4];
  
  if ((this->parent).parent.mbIsMounted == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JKRCompArchive.cpp",0x242,"isMounted()");
    m_Do_printf::OSPanic("JKRCompArchive.cpp",0x242,&DAT_8036bb1f);
  }
  uVar2 = param_1->mDataSize;
  uVar1 = (uint)param_1->mAttrAndNameOffs >> 0x18;
  if (((uint)param_1->mAttrAndNameOffs >> 0x18 & 4) == 0) {
    pJVar3 = (JKRHeap *)0x0;
  }
  else {
    if ((uVar1 & 0x80) == 0) {
      pJVar3 = (JKRHeap *)&DAT_00000001;
    }
    else {
      pJVar3 = (JKRHeap *)&DAT_00000002;
    }
  }
  if (param_2 == (ulong *)0x0) {
    param_2 = local_20;
  }
  if (param_1->mpData == (void *)0x0) {
    if ((uVar1 & 0x10) == 0) {
      if ((uVar1 & 0x20) == 0) {
        if ((uVar1 & 0x40) != 0) {
          uVar2 = JKRDvdArchive::fetchResource_subroutine
                            ((this->parent).field_0x40,this->field_0x6c + param_1->mDataOffs,uVar2,
                             (ulong)(this->parent).mpHeap,pJVar3,(this->parent).mCompressionType,
                             (int)&local_28,in_r10);
          if (param_2 != (ulong *)0x0) {
            *param_2 = uVar2;
          }
          param_1->mpData = local_28;
          if (pJVar3 == (JKRHeap *)&DAT_00000002) {
            (*(code *)((this->parent).parent.parent.vtbl)->setExpandSize)(this,param_1,*param_2);
          }
        }
      }
      else {
        uVar2 = JKRAramArchive::fetchResource_subroutine
                          ((JKRAramArchive *)
                           ((param_1->mDataOffs + this->field_0x68->field_0x14) -
                           this->mSizeOfMemPart),uVar2,(ulong)(this->parent).mpHeap,pJVar3,
                           (int)&local_24,in_r8);
        *param_2 = uVar2;
        param_1->mpData = local_24;
        if (pJVar3 == (JKRHeap *)&DAT_00000002) {
          (*(code *)((this->parent).parent.parent.vtbl)->setExpandSize)(this,param_1,*param_2);
        }
      }
    }
    else {
      param_1->mpData = (void *)((int)&((this->parent).mpHeader)->mSignature + param_1->mDataOffs);
      *param_2 = uVar2;
    }
  }
  else {
    if (param_2 != (ulong *)0x0) {
      *param_2 = uVar2;
    }
  }
  return param_1->mpData;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall JKRCompArchive::fetchResource(void *,
                                            unsigned long,
                                            JKRArchive::SDIFileEntry *,
                                            unsigned long *) */

void * __thiscall
JKRCompArchive::fetchResource
          (JKRCompArchive *this,void *param_1,ulong param_2,SDIFileEntry *param_3,ulong *param_4)

{
  uint uVar1;
  uchar *puVar2;
  ulong uVar3;
  char *pcVar4;
  int in_r10;
  void *pvVar5;
  void *pvVar6;
  
  pvVar6 = (void *)0x0;
  pcVar4 = (char *)param_3;
  if ((this->parent).parent.mbIsMounted == 0) {
    uVar3 = JUTAssertion::getSDevice();
    pcVar4 = "isMounted()";
    JUTAssertion::showAssert(uVar3,"JKRCompArchive.cpp",0x2b8,"isMounted()");
    m_Do_printf::OSPanic("JKRCompArchive.cpp",0x2b8,&DAT_8036bb1f);
  }
  pvVar5 = (void *)param_3->mDataSize;
  puVar2 = (uchar *)((int)pvVar5 + 0x1fU & 0xffffffe0);
  uVar1 = (uint)param_3->mAttrAndNameOffs >> 0x18;
  if (((uint)param_3->mAttrAndNameOffs >> 0x18 & 4) == 0) {
    uVar3 = 0;
  }
  else {
    if ((uVar1 & 0x80) == 0) {
      uVar3 = 1;
    }
    else {
      uVar3 = 2;
    }
  }
  if (param_3->mpData == (void *)0x0) {
    if ((uVar1 & 0x10) == 0) {
      if ((uVar1 & 0x20) == 0) {
        if ((uVar1 & 0x40) == 0) {
          m_Do_printf::OSPanic("JKRCompArchive.cpp",0x2f4,":::CompArchive: bad mode.");
        }
        else {
          pvVar6 = (void *)JKRDvdArchive::fetchResource_subroutine
                                     ((this->parent).field_0x40,
                                      this->field_0x6c + param_3->mDataOffs,(ulong)puVar2,
                                      (ulong)param_1,(uchar *)(param_2 & 0xffffffe0),uVar3,
                                      (this->parent).mCompressionType,in_r10);
        }
      }
      else {
        pvVar6 = (void *)JKRAramArchive::fetchResource_subroutine
                                   ((JKRAramArchive *)
                                    ((param_3->mDataOffs + this->field_0x68->field_0x14) -
                                    this->mSizeOfMemPart),(ulong)puVar2,(ulong)param_1,
                                    (uchar *)(param_2 & 0xffffffe0),uVar3,uVar3);
      }
    }
    else {
      pvVar6 = (void *)JKRMemArchive::fetchResource_subroutine
                                 ((JKRMemArchive *)
                                  ((int)&((this->parent).mpHeader)->mSignature + param_3->mDataOffs)
                                  ,puVar2,(ulong)param_1,(uchar *)(param_2 & 0xffffffe0),uVar3,uVar3
                                 );
    }
  }
  else {
    if ((uVar3 == 2) &&
       (pvVar6 = (void *)(*(code *)((this->parent).parent.parent.vtbl)->getExpandSize)(this,param_3)
       , pvVar6 != (void *)0x0)) {
      pvVar5 = pvVar6;
    }
    pvVar6 = pvVar5;
    if (param_2 < pvVar5) {
      pvVar6 = (void *)param_2;
    }
    JKRHeap::copyMemory((JKRHeap *)param_1,param_3->mpData,pvVar6,(ulong)pcVar4);
  }
  if (param_4 != (ulong *)0x0) {
    *param_4 = (ulong)pvVar6;
  }
  return param_1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JKRCompArchive::removeResourceAll(void) */

void __thiscall JKRCompArchive::removeResourceAll(JKRCompArchive *this)

{
  uint uVar1;
  SDIFileEntry *pSVar2;
  
  if (((this->parent).mpDataHeader != (JKRArchive__DataHeader *)0x0) &&
     ((this->parent).mMountMode != Mem)) {
    pSVar2 = (this->parent).mpFileEntries;
    for (uVar1 = 0; uVar1 < (uint)((this->parent).mpDataHeader)->mFileEntryCount; uVar1 = uVar1 + 1)
    {
      if (pSVar2->mpData != (void *)0x0) {
        if (((uint)pSVar2->mAttrAndNameOffs >> 0x18 & 0x10) == 0) {
          JKRHeap::free(pSVar2->mpData,(this->parent).mpHeap);
        }
        pSVar2->mpData = (void *)0x0;
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRCompArchive::removeResource(void *) */

undefined4 __thiscall JKRCompArchive::removeResource(JKRCompArchive *this,void *param_1)

{
  SDIFileEntry *pSVar1;
  undefined4 uVar2;
  
  pSVar1 = JKRArchive::findPtrResource(&this->parent,param_1);
  if (pSVar1 == (SDIFileEntry *)0x0) {
    uVar2 = 0;
  }
  else {
    if (((uint)pSVar1->mAttrAndNameOffs >> 0x18 & 0x10) == 0) {
      JKRHeap::free(param_1,(this->parent).mpHeap);
    }
    pSVar1->mpData = (void *)0x0;
    uVar2 = 1;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRCompArchive::getExpandedResSize(void const *) const */

uint __thiscall JKRCompArchive::getExpandedResSize(JKRCompArchive *this,void *dataPtr)

{
  uint uVar1;
  SDIFileEntry *fileEntry;
  ulong *in_stack_ffffffa8;
  uchar auStack64 [4];
  byte bStack60;
  byte bStack59;
  byte bStack58;
  byte bStack57;
  SDIFileEntry__AttributeType attrType;
  
  if ((this->parent).field_0x50 == 0) {
    uVar1 = (*(code *)((this->parent).parent.parent.vtbl)->getResSize)();
  }
  else {
    fileEntry = JKRArchive::findPtrResource(&this->parent,dataPtr);
    if (fileEntry == (SDIFileEntry *)0x0) {
      uVar1 = 0xffffffff;
    }
    else {
      attrType = (uint)fileEntry->mAttrAndNameOffs >> 0x18;
      if (((uint)fileEntry->mAttrAndNameOffs >> 0x18 & 4) == 0) {
        uVar1 = (*(code *)((this->parent).parent.parent.vtbl)->getResSize)(this,dataPtr);
      }
      else {
        if ((attrType & MEM) == 0) {
          if ((attrType & ARAM) == 0) {
            if ((attrType & DVD) == 0) {
              m_Do_printf::OSPanic("JKRCompArchive.cpp",0x3b0,"illegal resource.");
            }
            else {
              JKRDvdRipper::loadToMainRAM
                        ((long)(this->parent).field_0x40,auStack64,2,0x20,(JKRHeap *)0x0,1,
                         this->field_0x6c + fileEntry->mDataOffs,(int *)0x0);
              os::DCInvalidateRange(auStack64,0x20);
            }
          }
          else {
            JKRAram::aramToMainRam
                      ((JKRAram *)(fileEntry->mDataOffs + this->field_0x68->field_0x14),
                       (ulong)auStack64,&DAT_00000020,0,0,0,(JKRHeap *)&DAT_ffffffff,0,
                       in_stack_ffffffa8);
          }
          uVar1 = (uint)bStack57 |
                  (uint)bStack58 << 8 | (uint)bStack60 << 0x18 | (uint)bStack59 << 0x10;
          (*(code *)((this->parent).parent.parent.vtbl)->setExpandSize)(this,fileEntry,uVar1);
        }
        else {
          uVar1 = (uint)*(byte *)((int)dataPtr + 7) |
                  (uint)*(byte *)((int)dataPtr + 6) << 8 |
                  (uint)*(byte *)((int)dataPtr + 4) << 0x18 |
                  (uint)*(byte *)((int)dataPtr + 5) << 0x10;
        }
      }
    }
  }
  return uVar1;
}

