#include <JKernel/JKRDvdAramRipper.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRDvdFile.h>
#include <JKernel/JKRDvdAramRipper.h>
#include <JKernel/JKRHeap.h>
#include <os/OSMutex.h>
#include <os/OSThread.h>
#include <JSupport/JSUFileStream.h>
#include <dvd/dvdfs.h>
#include <vi/vi.h>
#include <os/OSCache.h>
#include <JKernel/JKRDecomp.h>
#include <JKernel/JKRAramHeap.h>
#include <JKernel/JKRAramStream.h>
#include <JSupport/JSUList.h>
#include <JSupport/JSUInputStream.h>
#include <os/OSInterrupt.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKernel/JKRAramPiece.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JKRDvdAramRipper.h>
#include <JSUList<JKRADCommand>.h>
#include <Demangler/JSUFileInputStream.h>
#include <Demangler/JKRADCommand.h>

undefined1 JKRDvdAramRipper;

namespace JKernel {
undefined decompMutex;
undefined4 szpBuf;
undefined4 szpEnd;
undefined4 refBuf;
undefined4 refEnd;
undefined4 refCurrent;
undefined4 dmaBuf;
undefined4 dmaEnd;
undefined4 dmaCurrent;
undefined4 srcOffset;
undefined4 transLeft;
undefined4 srcLimit;
undefined4 srcFile;
undefined4 fileOffset;
undefined4 readCount;
undefined4 maxDest;
undefined1 isInitMutex;
}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRDvdAramRipper::loadToAram(long,
                                           unsigned long,
                                           JKRExpandSwitch,
                                           unsigned long,
                                           unsigned long) */

undefined4 __thiscall
JKRDvdAramRipper::loadToAram
          (JKRDvdAramRipper *this,long param_1,ulong param_2,JKRExpandSwitch param_3,ulong param_4,
          ulong param_5)

{
  uint uVar1;
  undefined4 uVar2;
  ulong __oflag;
  JKRDvdFile JStack280;
  
  __oflag = param_2;
  JKRDvdFile::JKRDvdFile(&JStack280);
  uVar1 = JKRDvdFile::open(&JStack280,(char *)this,__oflag);
  if ((uVar1 & 0xff) == 0) {
    JKRDvdFile::_JKRDvdFile(&JStack280);
    uVar2 = 0;
  }
  else {
    uVar2 = loadToAram((JKRDvdAramRipper *)&JStack280,(JKRDvdFile *)param_1,param_2,param_3,param_4,
                       param_5);
    JKRDvdFile::_JKRDvdFile(&JStack280);
  }
  return uVar2;
}


/* __thiscall JKRDvdAramRipper::loadToAram(JKRDvdFile *,
                                           unsigned long,
                                           JKRExpandSwitch,
                                           unsigned long,
                                           unsigned long) */

undefined4 __thiscall
JKRDvdAramRipper::loadToAram
          (JKRDvdAramRipper *this,JKRDvdFile *param_1,ulong param_2,JKRExpandSwitch param_3,
          ulong param_4,ulong param_5)

{
  JKRDvdAramRipper *this_00;
  undefined4 uVar1;
  ulong in_r9;
  
  this_00 = (JKRDvdAramRipper *)
            loadToAram_Async(this,param_1,param_2,0,(FuncDef587 *)param_3,param_4,in_r9);
  syncAram(this_00,(JKRADCommand *)0x0,param_2);
  if (*(int *)(this_00 + 0x44) < 0) {
    JKRADCommand::_JKRADCommand((JKRADCommand *)this_00);
    uVar1 = 0;
  }
  else {
    if (param_1 == (JKRDvdFile *)0x0) {
      uVar1 = *(undefined4 *)(this_00 + 0x20);
      JKRADCommand::_JKRADCommand((JKRADCommand *)this_00);
    }
    else {
      JKRADCommand::_JKRADCommand((JKRADCommand *)this_00);
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall JKRDvdAramRipper::loadToAram_Async(JKRDvdFile *,
                                                 unsigned long,
                                                 JKRExpandSwitch,
                                                 void *(unsigned long),
                                                 unsigned long,
                                                 unsigned long) */

JKRDvdAramRipper * __thiscall
JKRDvdAramRipper::loadToAram_Async
          (JKRDvdAramRipper *this,JKRDvdFile *param_1,ulong param_2,JKRExpandSwitch param_3,
          FuncDef587 *param_4,ulong param_5,ulong param_6)

{
  JKRDvdAramRipper *this_00;
  int iVar1;
  JKRHeap *pJVar2;
  
  pJVar2 = JKRHeap::sSystemHeap;
  this_00 = (JKRDvdAramRipper *)JKernel::operator_new(0x50,JKRHeap::sSystemHeap,0xfffffffc);
  if (this_00 != (JKRDvdAramRipper *)0x0) {
    JKRADCommand::JKRADCommand((JKRADCommand *)this_00);
  }
  *(JKRDvdAramRipper **)(this_00 + 0x10) = this;
  *(JKRDvdFile **)(this_00 + 0x1c) = param_1;
  *(undefined4 *)(this_00 + 0x20) = 0;
  *(ulong *)(this_00 + 0x24) = param_2;
  *(JKRExpandSwitch *)(this_00 + 0x40) = param_3;
  *(FuncDef587 **)(this_00 + 0x14) = param_4;
  *(ulong *)(this_00 + 0x18) = param_5;
  iVar1 = callCommand_Async(this_00,(JKRADCommand *)pJVar2);
  if (iVar1 == 0) {
    JKRADCommand::_JKRADCommand((JKRADCommand *)this_00);
    this_00 = (JKRDvdAramRipper *)0x0;
  }
  return this_00;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall JKRDvdAramRipper::callCommand_Async(JKRADCommand *) */

JKRDvdAramRipper * __thiscall
JKRDvdAramRipper::callCommand_Async(JKRDvdAramRipper *this,JKRADCommand *param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int *this_00;
  uint uVar4;
  undefined4 uVar5;
  uchar *extraout_r4;
  ulong in_r7;
  ulong unaff_r25;
  JKRDecomp__CompressionType JVar6;
  int *piVar7;
  JKRDecomp aJStack96 [4];
  byte bStack92;
  byte bStack91;
  byte bStack90;
  byte bStack89;
  
  bVar1 = true;
  piVar7 = *(int **)(this + 0x10);
  JVar6 = NotCompressed;
  os::OSLockMutex((OSMutex *)(piVar7 + 0xd));
  if (piVar7[0x14] == 0) {
    iVar3 = os::OSGetCurrentThread();
    piVar7[0x14] = iVar3;
    this_00 = (int *)JKernel::operator_new(0x10,JKRHeap::sSystemHeap,0xfffffffc);
    if (this_00 != (int *)0x0) {
      JSUFileInputStream::JSUFileInputStream((JSUFileInputStream *)this_00,(JKRFile *)piVar7);
    }
    piVar7[0x15] = (int)this_00;
    uVar4 = (**(code **)(*piVar7 + 0x1c))(piVar7);
    uVar2 = *(uint *)(this + 0x18);
    if ((uVar2 != 0) && (uVar2 < uVar4)) {
      uVar4 = uVar2;
    }
    uVar4 = uVar4 + 0x1f & 0xffffffe0;
    if (*(int *)(this + 0x24) == 1) {
      while( true ) {
        in_r7 = 2;
        iVar3 = dvd::DVDReadPrio(piVar7 + 0x17,aJStack96,0x20,0);
        if (-1 < iVar3) break;
        if (errorRetry == '\0') {
          if (this_00 != (int *)0x0) {
            (**(code **)(*this_00 + 8))(this_00,1);
          }
          return (JKRDvdAramRipper *)0x0;
        }
        vi::VIWaitForRetrace();
      }
      os::DCInvalidateRange(aJStack96,0x20);
      JVar6 = JKRDecomp::checkCompressed(aJStack96,extraout_r4);
      unaff_r25 = (uint)bStack89 |
                  (uint)bStack90 << 8 | (uint)bStack92 << 0x18 | (uint)bStack91 << 0x10;
      uVar2 = *(uint *)(this + 0x18);
      if ((uVar2 != 0) && (uVar2 < unaff_r25)) {
        unaff_r25 = uVar2;
      }
    }
    if (JVar6 == NotCompressed) {
      *(undefined4 *)(this + 0x24) = 0;
    }
    if (*(int *)(this + 0x24) == 1) {
      if ((*(int *)(this + 0x1c) == 0) && (*(int *)(this + 0x20) == 0)) {
        uVar5 = JKRAramHeap::alloc(JKRAram::sAramObject->mpHeap,unaff_r25,0);
        *(undefined4 *)(this + 0x20) = uVar5;
        if (*(int *)(this + 0x20) != 0) {
          *(undefined4 *)(this + 0x1c) = *(undefined4 *)(*(int *)(this + 0x20) + 0x14);
        }
        piVar7[0x13] = *(int *)(this + 0x20);
      }
      if (*(int *)(this + 0x20) != 0) {
        *(undefined4 *)(this + 0x1c) = *(undefined4 *)(*(int *)(this + 0x20) + 0x14);
      }
      if (*(int *)(this + 0x1c) == 0) {
        piVar7[0x14] = 0;
        return (JKRDvdAramRipper *)0x0;
      }
    }
    else {
      if ((*(int *)(this + 0x1c) == 0) && (*(int *)(this + 0x20) == 0)) {
        uVar5 = JKRAramHeap::alloc(JKRAram::sAramObject->mpHeap,uVar4,0);
        *(undefined4 *)(this + 0x20) = uVar5;
      }
      if (*(int *)(this + 0x20) != 0) {
        *(undefined4 *)(this + 0x1c) = *(undefined4 *)(*(int *)(this + 0x20) + 0x14);
      }
      if (*(int *)(this + 0x1c) == 0) {
        piVar7[0x14] = 0;
        return (JKRDvdAramRipper *)0x0;
      }
    }
    if (JVar6 == NotCompressed) {
      uVar5 = JKRAramStream::write_StreamToAram_Async
                        ((JKRAramStream *)this_00,*(JSUFileInputStream **)(this + 0x1c),
                         uVar4 - *(ulong *)(this + 0x14),*(ulong *)(this + 0x14),in_r7);
      *(undefined4 *)(this + 0x4c) = uVar5;
    }
    else {
      if (JVar6 == Yay0Compressed) {
        uVar5 = JKRAramStream::write_StreamToAram_Async
                          ((JKRAramStream *)this_00,*(JSUFileInputStream **)(this + 0x1c),
                           uVar4 - *(ulong *)(this + 0x14),*(ulong *)(this + 0x14),in_r7);
        *(undefined4 *)(this + 0x4c) = uVar5;
      }
      else {
        if (JVar6 == Yaz0Compressed) {
          *(undefined4 *)(this + 0x4c) = 0;
          JKernel::JKRDecompressFromDVDToAram
                    (*(undefined4 *)(this + 0x10),*(undefined4 *)(this + 0x1c),uVar4,unaff_r25,
                     *(undefined4 *)(this + 0x14),0);
        }
      }
    }
    if (*(code **)(this + 0x40) == (code *)0x0) {
      JSUPtrList::append((JSUPtrList *)&sDvdAramAsyncList,(JSUPtrLink *)this);
    }
    else {
      (**(code **)(this + 0x40))(this);
    }
  }
  else {
    bVar1 = false;
  }
  os::OSUnlockMutex(piVar7 + 0xd);
  if (!bVar1) {
    this = (JKRDvdAramRipper *)0x0;
  }
  return this;
}


/* __thiscall JSUFileInputStream::~JSUFileInputStream(void) */

void __thiscall JSUFileInputStream::_JSUFileInputStream(JSUFileInputStream *this)

{
  short in_r4;
  
  if (this != (JSUFileInputStream *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (JSUFileInputStream *)0x0) {
      *(undefined1 **)this = &JSURandomInputStream::__vt;
      JSUInputStream::_JSUInputStream((JSUInputStream *)this);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JKRDvdAramRipper::syncAram(JKRADCommand *,
                                         int) */

undefined4 __thiscall
JKRDvdAramRipper::syncAram(JKRDvdAramRipper *this,JKRADCommand *param_1,int param_2)

{
  JKRAramStream *this_00;
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 0x10);
  os::OSLockMutex((OSMutex *)(iVar2 + 0x34));
  this_00 = *(JKRAramStream **)(this + 0x4c);
  if (this_00 != (JKRAramStream *)0x0) {
    JKRAramStream::sync(this_00);
    *(uint *)(this + 0x44) = -(uint)(this_00 == (JKRAramStream *)0x0);
    if ((param_1 != (JKRADCommand *)0x0) && (this_00 == (JKRAramStream *)0x0)) {
      os::OSUnlockMutex(iVar2 + 0x34);
      return 0;
    }
  }
  JSUPtrList::remove((JSUPtrList *)&sDvdAramAsyncList,(JSUPtrLink *)this);
  if (*(JKRHeap **)(this + 0x4c) != (JKRHeap *)0x0) {
    JKernel::operator_delete(*(JKRHeap **)(this + 0x4c));
  }
  piVar1 = *(int **)(iVar2 + 0x54);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  *(undefined4 *)(iVar2 + 0x50) = 0;
  os::OSUnlockMutex(iVar2 + 0x34);
  return 1;
}


/* __thiscall JKRADCommand::JKRADCommand(void) */

void __thiscall JKRADCommand::JKRADCommand(JKRADCommand *this)

{
  JSUPtrLink::JSUPtrLink((JSUPtrLink *)this,this);
  *(undefined4 *)(this + 0x44) = 0;
  this[0x48] = (JKRADCommand)0x0;
  return;
}


/* __thiscall JKRADCommand::~JKRADCommand(void) */

void __thiscall JKRADCommand::_JKRADCommand(JKRADCommand *this)

{
  int *piVar1;
  short in_r4;
  
  if (this != (JKRADCommand *)0x0) {
    if ((this[0x48] == (JKRADCommand)0x1) && (piVar1 = *(int **)(this + 0x10), piVar1 != (int *)0x0)
       ) {
      (**(code **)(*piVar1 + 8))(piVar1,1);
    }
    if (this != (JKRADCommand *)0x0) {
      JSUPtrLink::_JSUPtrLink((JSUPtrLink *)this);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace JKernel {

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall JKRDecompressFromDVDToAram(JKRDvdFile *,
                                        unsigned long,
                                        unsigned long,
                                        unsigned long,
                                        unsigned long,
                                        unsigned long) */

undefined4
JKRDecompressFromDVDToAram
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
          int param_6)

{
  undefined4 uVar1;
  ulong uVar2;
  int iVar3;
  
  uVar1 = os::OSDisableInterrupts();
  if (isInitMutex == '\0') {
    os::OSInitMutex((OSMutex *)&decompMutex);
    isInitMutex = '\x01';
  }
  os::OSRestoreInterrupts(uVar1);
  os::OSLockMutex((OSMutex *)&decompMutex);
  iVar3 = ::JKRDvdAramRipper::sSzpBufferSize;
  szpBuf = ::JKRHeap::alloc(::JKRHeap::sSystemHeap,::JKRDvdAramRipper::sSzpBufferSize,0x20);
  if (szpBuf == (void *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JKRDvdAramRipper.cpp",0x2b5,"szpBuf != 0");
    m_Do_printf::OSPanic("JKRDvdAramRipper.cpp",0x2b5,&DAT_8036bcf9);
  }
  szpEnd = (int)szpBuf + iVar3;
  refBuf = ::JKRHeap::alloc(::JKRHeap::sSystemHeap,0x1120,0);
  if (refBuf == (void *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JKRDvdAramRipper.cpp",0x2bd,"refBuf != 0");
    m_Do_printf::OSPanic("JKRDvdAramRipper.cpp",0x2bd,&DAT_8036bcf9);
  }
  refEnd = (int)refBuf + 0x1120;
  refCurrent = refBuf;
  dmaBuf = ::JKRHeap::alloc(::JKRHeap::sSystemHeap,0x100,0x20);
  if (dmaBuf == (void *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JKRDvdAramRipper.cpp",0x2c6,"dmaBuf != 0");
    m_Do_printf::OSPanic("JKRDvdAramRipper.cpp",0x2c6,&DAT_8036bcf9);
  }
  dmaEnd = (int)dmaBuf + 0x100;
  dmaCurrent = dmaBuf;
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
  ::JKRHeap::free(szpBuf,(JKRHeap *)0x0);
  ::JKRHeap::free(refBuf,(JKRHeap *)0x0);
  ::JKRHeap::free(dmaBuf,(JKRHeap *)0x0);
  os::OSUnlockMutex(&decompMutex);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __stdcall decompSZS_subroutine(unsigned char *,
                                  unsigned long) */

undefined4 decompSZS_subroutine(char *param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  
  iVar8 = 0;
  uVar7 = 0;
  if ((((*param_1 == 'Y') && (param_1[1] == 'a')) && (param_1[2] == 'z')) && (param_1[3] == '0')) {
    uVar10 = param_2 + (*(int *)(param_1 + 4) - fileOffset);
    if (param_2 + maxDest < uVar10) {
      uVar10 = param_2 + maxDest;
    }
    pbVar4 = (byte *)(param_1 + 0x10);
    uVar6 = param_2;
    do {
      pbVar5 = pbVar4;
      if (iVar8 == 0) {
        if ((srcLimit < pbVar4) && (transLeft != 0)) {
          pbVar4 = (byte *)nextSrcData(pbVar4);
        }
        uVar7 = (uint)*pbVar4;
        iVar8 = 8;
        pbVar5 = pbVar4 + 1;
      }
      if ((uVar7 & 0x80) == 0) {
        iVar2 = (int)(uint)*pbVar5 >> 4;
        pbVar9 = refCurrent + (-1 - ((*pbVar5 & 0xf) << 8 | (uint)pbVar5[1]));
        pbVar4 = pbVar5 + 2;
        if (pbVar9 < refBuf) {
          pbVar9 = pbVar9 + ((int)refEnd - (int)refBuf);
        }
        if (iVar2 == 0) {
          iVar2 = *pbVar4 + 0x12;
          pbVar4 = pbVar5 + 3;
        }
        else {
          iVar2 = iVar2 + 2;
        }
        do {
          if (fileOffset <= readCount) {
            pbVar5 = dmaCurrent + 1;
            *dmaCurrent = *pbVar9;
            dmaCurrent = pbVar5;
            param_2 = param_2 + 1;
            if (dmaCurrent == dmaEnd) {
              iVar3 = dmaBufferFlush(uVar6);
              uVar6 = uVar6 + iVar3;
            }
            if (param_2 == uVar10) break;
          }
          pbVar5 = refCurrent + 1;
          *refCurrent = *pbVar9;
          refCurrent = pbVar5;
          if (refCurrent == refEnd) {
            refCurrent = refBuf;
          }
          pbVar9 = pbVar9 + 1;
          if (pbVar9 == refEnd) {
            pbVar9 = refBuf;
          }
          readCount = readCount + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      else {
        if (fileOffset <= readCount) {
          pbVar4 = dmaCurrent + 1;
          *dmaCurrent = *pbVar5;
          dmaCurrent = pbVar4;
          param_2 = param_2 + 1;
          if (dmaCurrent == dmaEnd) {
            iVar2 = dmaBufferFlush(uVar6);
            uVar6 = uVar6 + iVar2;
          }
          if (param_2 == uVar10) break;
        }
        pbVar4 = refCurrent + 1;
        *refCurrent = *pbVar5;
        refCurrent = pbVar4;
        if (refCurrent == refEnd) {
          refCurrent = refBuf;
        }
        readCount = readCount + 1;
        pbVar4 = pbVar5 + 1;
      }
      uVar7 = uVar7 << 1;
      iVar8 = iVar8 + -1;
    } while (param_2 < uVar10);
    dmaBufferFlush(uVar6);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
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
    iVar2 = dvd::DVDReadPrio(srcFile + 0x5c,iVar1,uVar3,0,2);
    if (-1 < iVar2) {
      srcOffset = srcOffset + uVar3;
      transLeft = transLeft - uVar3;
      return iVar1;
    }
    if (::JKRDvdAramRipper::errorRetry == '\0') break;
    vi::VIWaitForRetrace();
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
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
    JUTAssertion::showAssert(uVar1,"JKRDvdAramRipper.cpp",0x3c6,"transSize > 0");
    m_Do_printf::OSPanic("JKRDvdAramRipper.cpp",0x3c6,&DAT_8036bcf9);
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
    if (::JKRDvdAramRipper::errorRetry == '\0') break;
    vi::VIWaitForRetrace();
  }
  return (byte *)0x0;
}


/* __stdcall dmaBufferFlush(unsigned long) */

uint dmaBufferFlush(ulong param_1)

{
  uint uVar1;
  JKRAramBlock *in_r8;
  
  if (dmaCurrent == dmaBuf) {
    uVar1 = 0;
  }
  else {
    uVar1 = (dmaCurrent - dmaBuf) + 0x1fU & 0xffffffe0;
    ::JKRAramPiece::orderSync((JKRAramPiece *)0x0,dmaBuf,param_1,uVar1,0,in_r8);
    dmaCurrent = dmaBuf;
  }
  return uVar1;
}


void __sinit_JKRDvdAramRipper_cpp(void)

{
  JSUPtrList::initiate((JSUPtrList *)&::JKRDvdAramRipper::sDvdAramAsyncList);
  Runtime.PPCEABI.H::__register_global_object
            (&::JKRDvdAramRipper::sDvdAramAsyncList,::JSUList<JKRADCommand>::_JSUList,&_287);
  return;
}

}

/* __thiscall JSUList<JKRADCommand>::~JSUList(void) */

JSUList_JKRADCommand_ * __thiscall JSUList<JKRADCommand>::_JSUList(JSUList_JKRADCommand_ *this)

{
  short in_r4;
  
  if ((this != (JSUList_JKRADCommand_ *)0x0) &&
     (JSUPtrList::_JSUPtrList((JSUPtrList *)this), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return this;
}

