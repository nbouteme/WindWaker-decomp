#include <JKernel/JKRDvdRipper.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRDvdFile.h>
#include <JKernel/JKRDvdRipper.h>
#include <dvd/dvdfs.h>
#include <vi/vi.h>
#include <os/OSCache.h>
#include <JKernel/JKRDecomp.h>
#include <JKernel/JKRHeap.h>
#include <m_Do_printf.h>
#include <os/OSInterrupt.h>
#include <os/OSMutex.h>
#include <JUtility/JUTAssert.h>
#include <JSupport/JSUList.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JSUList<JKRDMCommand>.h>
#include <JKRDvdRipper.h>

undefined1 JKRDvdRipper;

namespace JKernel {
undefined decompMutex;
undefined4 szpBuf;
undefined4 szpEnd;
undefined4 refBuf;
undefined4 refEnd;
undefined4 refCurrent;
undefined4 srcOffset;
undefined4 transLeft;
undefined4 srcLimit;
undefined4 srcFile;
undefined4 fileOffset;
undefined4 readCount;
undefined4 maxDest;
undefined1 isInitMutex;
}

namespace JKRDvdRipper {

/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall loadToMainRAM(char const *,
                                          unsigned char *,
                                          JKRExpandSwitch,
                                          unsigned long,
                                          JKRHeap *,
                                          EAllocDirection,
                                          unsigned long,
                                          int *) */

undefined4
loadToMainRAM
          (char *param_1,uchar *param_2,JKRExpandSwitch param_3,ulong param_4,JKRHeap *param_5,
          EAllocDirection param_6,ulong param_7,int *param_8)

{
  uint uVar1;
  undefined4 uVar2;
  JKRDvdFile local_118;
  
  JKRDvdFile::JKRDvdFile(&local_118);
  uVar1 = JKRDvdFile::open(&local_118,param_1);
  if ((uVar1 & 0xff) == 0) {
    JKRDvdFile::_JKRDvdFile(&local_118);
    uVar2 = 0;
  }
  else {
    uVar2 = loadToMainRAM(&local_118,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    JKRDvdFile::_JKRDvdFile(&local_118);
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall loadToMainRAM(long,
                                          unsigned char *,
                                          JKRExpandSwitch,
                                          unsigned long,
                                          JKRHeap *,
                                          EAllocDirection,
                                          unsigned long,
                                          int *) */

JKRArchive__Header *
loadToMainRAM
          (long param_1,uchar *param_2,JKRExpandSwitch param_3,ulong param_4,JKRHeap *param_5,
          EAllocDirection param_6,ulong param_7,int *param_8)

{
  uint uVar1;
  JKRArchive__Header *pJVar2;
  JKRExpandSwitch __oflag;
  JKRDvdFile JStack280;
  
  __oflag = param_3;
  JKRDvdFile::JKRDvdFile(&JStack280);
  uVar1 = JKRDvdFile::open(&JStack280,(char *)param_1,__oflag);
  if ((uVar1 & 0xff) == 0) {
    JKRDvdFile::_JKRDvdFile(&JStack280);
    pJVar2 = (JKRArchive__Header *)0x0;
  }
  else {
    pJVar2 = (JKRArchive__Header *)
             loadToMainRAM(&JStack280,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    JKRDvdFile::_JKRDvdFile(&JStack280);
  }
  return pJVar2;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* __thiscall loadToMainRAM(JKRDvdFile *,
                                          unsigned char *,
                                          JKRExpandSwitch,
                                          unsigned long,
                                          JKRHeap *,
                                          EAllocDirection,
                                          unsigned long,
                                          int *) */

uchar * loadToMainRAM
                  (JKRDvdFile *param_1,uchar *param_2,JKRExpandSwitch param_3,ulong param_4,
                  JKRHeap *param_5,EAllocDirection param_6,ulong param_7,int *outCompType)

{
  uint size;
  bool bVar1;
  int iVar2;
  uchar *extraout_r4;
  uchar *extraout_r4_00;
  ulong uVar3;
  uchar *unaff_r24;
  JKRDecomp__CompressionType JVar4;
  JKRDecomp *this;
  JKRDecomp aJStack160 [64];
  JKRDecomp aJStack96 [4];
  byte bStack92;
  byte bStack91;
  byte bStack90;
  byte bStack89;
  
  bVar1 = false;
  JVar4 = NotCompressed;
  this = (JKRDecomp *)0x0;
  iVar2 = (*(code *)((param_1->parent).vtbl)->readResource1)();
  size = iVar2 + 0x1fU & 0xffffffe0;
  if (param_3 == 1) {
    while (iVar2 = dvd::DVDReadPrio(&param_1->mNum,aJStack96,0x20,0,2), iVar2 < 0) {
      if ((iVar2 == -3) || (errorRetry == '\0')) {
        return (uchar *)0x0;
      }
      vi::VIWaitForRetrace();
    }
    os::DCInvalidateRange(aJStack96,0x20);
    JVar4 = JKRDecomp::checkCompressed(aJStack96,extraout_r4);
    unaff_r24 = (uchar *)((uint)bStack89 |
                         (uint)bStack90 << 8 | (uint)bStack92 << 0x18 | (uint)bStack91 << 0x10);
  }
  if (outCompType != (int *)0x0) {
    *outCompType = JVar4;
  }
  if ((param_3 == 1) && (JVar4 != NotCompressed)) {
    if ((param_4 != 0) && (param_4 < unaff_r24)) {
      unaff_r24 = (uchar *)param_4;
    }
    if (param_2 == (uchar *)0x0) {
      iVar2 = -0x20;
      if (param_6 == 1) {
        iVar2 = 0x20;
      }
      param_2 = (uchar *)JKRHeap::alloc((ulong)unaff_r24,iVar2,param_5);
      bVar1 = true;
    }
    if (param_2 == (uchar *)0x0) {
      return (uchar *)0x0;
    }
    if (((JVar4 == Yay0Compressed) &&
        (this = (JKRDecomp *)JKRHeap::alloc(size,0x20,param_5), this == (JKRDecomp *)0x0)) &&
       (bVar1)) {
      JKRHeap::free(param_2,(JKRHeap *)0x0);
      return (uchar *)0x0;
    }
  }
  else {
    if (param_2 == (uchar *)0x0) {
      iVar2 = -0x20;
      if (param_6 == 1) {
        iVar2 = 0x20;
      }
      param_2 = (uchar *)JKRHeap::alloc(size - param_7,iVar2,param_5);
      bVar1 = true;
    }
    if (param_2 == (uchar *)0x0) {
      return (uchar *)0x0;
    }
  }
  if (JVar4 == NotCompressed) {
    JVar4 = NotCompressed;
    if (param_7 != 0) {
      while (iVar2 = dvd::DVDReadPrio(&param_1->mNum,aJStack160,0x20,param_7,2), iVar2 < 0) {
        if ((iVar2 == -3) || (errorRetry == '\0')) {
          if (bVar1) {
            JKRHeap::free(param_2,(JKRHeap *)0x0);
          }
          return (uchar *)0x0;
        }
        vi::VIWaitForRetrace();
      }
      os::DCInvalidateRange(aJStack160,0x20);
      JVar4 = JKRDecomp::checkCompressed(aJStack160,extraout_r4_00);
    }
    if (((JVar4 == NotCompressed) || (param_3 == 2)) || (param_3 == 0)) {
      uVar3 = size - param_7;
      if ((param_4 != 0) && (param_4 < uVar3)) {
        uVar3 = param_4;
      }
      while (iVar2 = dvd::DVDReadPrio(&param_1->mNum,param_2,uVar3,param_7,2), iVar2 < 0) {
        if ((iVar2 == -3) || (errorRetry == '\0')) {
          if (bVar1) {
            JKRHeap::free(param_2,(JKRHeap *)0x0);
          }
          return (uchar *)0x0;
        }
        vi::VIWaitForRetrace();
      }
    }
    else {
      if (JVar4 == Yaz0Compressed) {
        JKernel::JKRDecompressFromDVD(param_1,param_2,size,param_4,0,param_7);
      }
      else {
        m_Do_printf::OSPanic("JKRDvdRipper.cpp",0x13a,"Sorry, not prepared for SZP resource\n");
      }
    }
  }
  else {
    if (JVar4 == Yay0Compressed) {
      if (param_7 != 0) {
        m_Do_printf::OSPanic("JKRDvdRipper.cpp",0x144,":::Not support SZP with offset read");
      }
      while( true ) {
        uVar3 = 2;
        iVar2 = dvd::DVDReadPrio(&param_1->mNum,this,size,0);
        if (-1 < iVar2) break;
        if ((iVar2 == -3) || (errorRetry == '\0')) {
          if (bVar1) {
            JKRHeap::free(param_2,(JKRHeap *)0x0);
          }
          JKRHeap::free(this,(JKRHeap *)0x0);
          return (uchar *)0x0;
        }
        vi::VIWaitForRetrace();
      }
      JKRDecomp::orderSync(this,param_2,unaff_r24,param_7,uVar3);
      JKRHeap::free(this,(JKRHeap *)0x0);
    }
    else {
      if (JVar4 == Yaz0Compressed) {
        iVar2 = JKernel::JKRDecompressFromDVD(param_1,param_2,size,unaff_r24,param_7,0);
        if (iVar2 != 0) {
          if (bVar1) {
            JKRHeap::free(param_2,(JKRHeap *)0x0);
          }
          param_2 = (uchar *)0x0;
        }
      }
      else {
        if (bVar1) {
          JKRHeap::free(param_2,(JKRHeap *)0x0);
        }
        param_2 = (uchar *)0x0;
      }
    }
  }
  return param_2;
}

}

namespace JKernel {

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall JKRDecompressFromDVD(JKRDvdFile *,
                                  void *,
                                  unsigned long,
                                  unsigned long,
                                  unsigned long,
                                  unsigned long) */

undefined4
JKRDecompressFromDVD
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
          int param_6)

{
  undefined4 uVar1;
  ulong uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = os::OSDisableInterrupts();
  if (isInitMutex == '\0') {
    os::OSInitMutex((OSMutex *)&decompMutex);
    isInitMutex = '\x01';
  }
  os::OSRestoreInterrupts(uVar1);
  os::OSLockMutex((OSMutex *)&decompMutex);
  iVar3 = ::JKRDvdRipper::sSzpBufferSize;
  szpBuf = ::JKRHeap::alloc(::JKRHeap::sSystemHeap,::JKRDvdRipper::sSzpBufferSize,-0x20);
  if (szpBuf == (void *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JKRDvdRipper.cpp",0x374,"szpBuf != 0");
    m_Do_printf::OSPanic("JKRDvdRipper.cpp",0x374,&DAT_8036bcb7);
  }
  szpEnd = (int)szpBuf + iVar3;
  if (param_5 == 0) {
    refBuf = (void *)0x0;
  }
  else {
    refBuf = ::JKRHeap::alloc(::JKRHeap::sSystemHeap,0x1120,-4);
    if (refBuf == (void *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"JKRDvdRipper.cpp",0x37d,"refBuf != 0");
      m_Do_printf::OSPanic("JKRDvdRipper.cpp",0x37d,&DAT_8036bcb7);
    }
    refEnd = (int)refBuf + 0x1120;
    refCurrent = refBuf;
  }
  transLeft = param_3 - param_6;
  readCount = 0;
  srcOffset = param_6;
  srcFile = param_1;
  fileOffset = param_5;
  maxDest = param_4;
  iVar3 = firstSrcData();
  if (iVar3 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = decompSZS_subroutine(iVar3,param_2);
  }
  uVar4 = *(undefined4 *)(iVar3 + 4);
  ::JKRHeap::free(szpBuf,(JKRHeap *)0x0);
  if (refBuf != (void *)0x0) {
    ::JKRHeap::free(refBuf,(JKRHeap *)0x0);
  }
  os::DCStoreRangeNoSync(param_2,uVar4);
  os::OSUnlockMutex(&decompMutex);
  return uVar1;
}


/* __stdcall decompSZS_subroutine(unsigned char *,
                                  unsigned char *) */

undefined4 decompSZS_subroutine(char *param_1,byte *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  
  iVar5 = 0;
  uVar1 = 0;
  if ((((*param_1 == 'Y') && (param_1[1] == 'a')) && (param_1[2] == 'z')) && (param_1[3] == '0')) {
    pbVar9 = param_2 + (*(int *)(param_1 + 4) - fileOffset);
    if (param_2 + maxDest < param_2 + (*(int *)(param_1 + 4) - fileOffset)) {
      pbVar9 = param_2 + maxDest;
    }
    pbVar3 = (byte *)(param_1 + 0x10);
    do {
      pbVar4 = pbVar3;
      if (iVar5 == 0) {
        if (((srcLimit < pbVar3) && (transLeft != 0)) &&
           (pbVar3 = (byte *)nextSrcData(), pbVar3 == (byte *)0x0)) {
          return 0xffffffff;
        }
        uVar1 = (uint)*pbVar3;
        iVar5 = 8;
        pbVar4 = pbVar3 + 1;
      }
      if ((uVar1 & 0x80) == 0) {
        uVar7 = (*pbVar4 & 0xf) << 8 | (uint)pbVar4[1];
        iVar6 = (int)(uint)*pbVar4 >> 4;
        pbVar3 = pbVar4 + 2;
        if (fileOffset == 0) {
          pbVar8 = param_2 + (-1 - uVar7);
        }
        else {
          pbVar8 = refCurrent + (-1 - uVar7);
          if (pbVar8 < refBuf) {
            pbVar8 = pbVar8 + ((int)refEnd - (int)refBuf);
          }
        }
        if (iVar6 == 0) {
          iVar6 = *pbVar3 + 0x12;
          pbVar3 = pbVar4 + 3;
        }
        else {
          iVar6 = iVar6 + 2;
        }
        if (fileOffset == 0) {
          do {
            *param_2 = *pbVar8;
            param_2 = param_2 + 1;
            if (param_2 == pbVar9) break;
            readCount = readCount + 1;
            iVar6 = iVar6 + -1;
            pbVar8 = pbVar8 + 1;
          } while (iVar6 != 0);
        }
        else {
          do {
            if (fileOffset <= readCount) {
              *param_2 = *pbVar8;
              param_2 = param_2 + 1;
              if (param_2 == pbVar9) break;
            }
            pbVar4 = refCurrent + 1;
            *refCurrent = *pbVar8;
            refCurrent = pbVar4;
            if (refCurrent == refEnd) {
              refCurrent = refBuf;
            }
            pbVar8 = pbVar8 + 1;
            if (pbVar8 == refEnd) {
              pbVar8 = refBuf;
            }
            readCount = readCount + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
      else {
        if (fileOffset == 0) {
          *param_2 = *pbVar4;
          param_2 = param_2 + 1;
          if (param_2 == pbVar9) break;
        }
        else {
          if (fileOffset <= readCount) {
            *param_2 = *pbVar4;
            param_2 = param_2 + 1;
            if (param_2 == pbVar9) break;
          }
          pbVar3 = refCurrent + 1;
          *refCurrent = *pbVar4;
          refCurrent = pbVar3;
          if (refCurrent == refEnd) {
            refCurrent = refBuf;
          }
        }
        pbVar3 = pbVar4 + 1;
        readCount = readCount + 1;
      }
      uVar1 = uVar1 << 1;
      iVar5 = iVar5 + -1;
    } while (param_2 < pbVar9);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


/* __stdcall firstSrcData(void) */

int firstSrcData(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = szpBuf;
  srcLimit = szpEnd + -0x19;
  uVar3 = szpEnd - szpBuf;
  if (transLeft < (uint)(szpEnd - szpBuf)) {
    uVar3 = transLeft;
  }
  while( true ) {
    iVar2 = dvd::DVDReadPrio(srcFile + 0x5c,iVar1,uVar3,srcOffset,2);
    if (-1 < iVar2) {
      if (transLeft - uVar3 == 0) {
        srcLimit = iVar1 + uVar3;
      }
      srcOffset = srcOffset + uVar3;
      transLeft = transLeft - uVar3;
      return iVar1;
    }
    if ((iVar2 == -3) || (::JKRDvdRipper::errorRetry == '\0')) break;
    vi::VIWaitForRetrace();
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall nextSrcData(unsigned char *) */

byte * nextSrcData(byte *param_1)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  byte *dst;
  
  uVar3 = szpEnd - (int)param_1;
  dst = szpBuf;
  if ((uVar3 & 0x1f) != 0) {
    dst = szpBuf + (0x20 - (uVar3 & 0x1f));
  }
  copy_bytes(dst,param_1,uVar3);
  pbVar4 = dst + uVar3;
  uVar3 = szpEnd - (int)pbVar4;
  if (transLeft < (uint)(szpEnd - (int)pbVar4)) {
    uVar3 = transLeft;
  }
  if (uVar3 == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRDvdRipper.cpp",0x498,"transSize > 0");
    m_Do_printf::OSPanic("JKRDvdRipper.cpp",0x498,&DAT_8036bcb7);
  }
  while( true ) {
    iVar2 = dvd::DVDReadPrio(srcFile + 0x5c,pbVar4,uVar3,srcOffset,2);
    if (-1 < iVar2) {
      if (transLeft - uVar3 == 0) {
        srcLimit = pbVar4 + uVar3;
      }
      srcOffset = srcOffset + uVar3;
      transLeft = transLeft - uVar3;
      return dst;
    }
    if (iVar2 == -3) break;
    vi::VIWaitForRetrace();
  }
  return (byte *)0x0;
}

}

/* __thiscall JKRDvdRipper::isErrorRetry(void) */

undefined __thiscall JKRDvdRipper::isErrorRetry(JKRDvdRipper *this)

{
  return errorRetry;
}


namespace JKernel {

void __sinit_JKRDvdRipper_cpp(void)

{
  JSUPtrList::initiate((JSUPtrList *)&::JKRDvdRipper::sDvdAsyncList);
  Runtime.PPCEABI.H::__register_global_object
            (&::JKRDvdRipper::sDvdAsyncList,::JSUList<JKRDMCommand>::_JSUList,&_283);
  return;
}

}

/* __thiscall JSUList<JKRDMCommand>::~JSUList(void) */

JSUList_JKRDMCommand_ * __thiscall JSUList<JKRDMCommand>::_JSUList(JSUList_JKRDMCommand_ *this)

{
  short in_r4;
  
  if ((this != (JSUList_JKRDMCommand_ *)0x0) &&
     (JSUPtrList::_JSUPtrList((JSUPtrList *)this), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return this;
}

