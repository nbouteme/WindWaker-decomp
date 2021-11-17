#include <JKernel/JKRAram.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRAram.h>
#include <JKernel/JKRAramStream.h>
#include <JKernel/JKRDecomp.h>
#include <os/OSThread.h>
#include <JKernel/JKRThread.h>
#include <ar/ar.h>
#include <ar/arq.h>
#include <m_Do_printf.h>
#include <JKernel/JKRAramHeap.h>
#include <os/OSMessage.h>
#include <JKernel/JKRAramPiece.h>
#include <os/OSInterrupt.h>
#include <os/OSMutex.h>
#include <JUtility/JUTAssert.h>
#include <os/OSCache.h>
#include <JSupport/JSUList.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JKRAram.h>
#include <JSUList<JKRAMCommand>.h>

undefined1 JKRAram;

namespace JKernel {
undefined decompMutex;
}
struct JKRAram * JKRAram;

namespace JKernel {
struct JKRHeap * szpBuf;
undefined4 szpEnd;
undefined4 refBuf;
undefined4 refEnd;
undefined4 refCurrent;
undefined4 srcOffset;
undefined4 transLeft;
undefined4 srcLimit;
undefined4 srcAddress;
undefined4 fileOffset;
undefined4 readCount;
undefined4 maxDest;
undefined1 isInitMutex;
}

namespace JKRAram {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall create(unsigned long,
                              unsigned long,
                              long,
                              long,
                              long) */

JKRAram * create(ulong param_1,ulong param_2,long param_3,long param_4,long param_5)

{
  JKRAram *this;
  
  this = sAramObject;
  if ((sAramObject == (JKRAram *)0x0) &&
     (this = (JKRAram *)JKernel::operator_new(0x90,JKRHeap::sSystemHeap,0), this != (JKRAram *)0x0))
  {
    JKRAram(this,param_1,param_2,param_5);
  }
  sAramObject = this;
  JKRAramStream::create(param_3);
  JKRDecomp::create(param_4);
  os::OSResumeThread(sAramObject->field_0x2c);
  return sAramObject;
}

}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JKRAram::JKRAram(unsigned long,
                               unsigned long,
                               long) */

void __thiscall JKRAram::JKRAram(JKRAram *this,ulong param_1,ulong param_2,long param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  ulong uVar4;
  JKRAramHeap *this_00;
  
  JKRThread::JKRThread((JKRThread *)this,0x4000,0x10,param_3);
  this->field_0x0 = (JKRArchive__vtbl *)&__vt;
  iVar1 = ar::ARInit(this + 1,3);
  ar::ARQInit();
  iVar2 = ar::ARGetSize();
  m_Do_printf::OSReport("ARAM size = %08x\n",iVar2);
  this->field_0x6c = param_1;
  if (param_2 == 0xffffffff) {
    this->field_0x74 = (iVar2 - param_1) - iVar1;
    this->field_0x7c = 0;
  }
  else {
    this->field_0x74 = param_2;
    this->field_0x7c = (iVar2 - (param_1 + param_2)) - iVar1;
  }
  uVar3 = ar::ARAlloc(this->field_0x6c);
  this->field_0x68 = uVar3;
  uVar4 = ar::ARAlloc(this->field_0x74);
  this->field_0x70 = uVar4;
  if (this->field_0x7c == 0) {
    this->field_0x78 = 0;
  }
  else {
    uVar3 = ar::ARAlloc();
    this->field_0x78 = uVar3;
  }
  m_Do_printf::OSReport("ARAM audio area %08x: %08x\n",this->field_0x68,this->field_0x6c);
  m_Do_printf::OSReport("ARAM graph area %08x: %08x\n",this->field_0x70,this->field_0x74);
  m_Do_printf::OSReport("ARAM  user area %08x: %08x\n",this->field_0x78,this->field_0x7c);
  this_00 = (JKRAramHeap *)JKernel::operator_new(0x44,JKRHeap::sSystemHeap,0);
  if (this_00 != (JKRAramHeap *)0x0) {
    JKRAramHeap::JKRAramHeap(this_00,this->field_0x70,this->field_0x74);
  }
  this->mpHeap = this_00;
  return;
}


/* __thiscall JKRAram::~JKRAram(void) */

void __thiscall JKRAram::_JKRAram(JKRAram *this)

{
  JKRAramHeap *pJVar1;
  short in_r4;
  
  if (this != (JKRAram *)0x0) {
    this->field_0x0 = (JKRArchive__vtbl *)&__vt;
    sAramObject = (JKRAram *)0x0;
    pJVar1 = this->mpHeap;
    if ((pJVar1 != (JKRAramHeap *)0x0) && (pJVar1 != (JKRAramHeap *)0x0)) {
      (**(code **)(pJVar1->vtbl + 8))(pJVar1,1);
    }
    JKRThread::_JKRThread((JKRThread *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* __thiscall JKRAram::run(void) */

void __thiscall JKRAram::run(JKRAram *this)

{
  JKRAMCommand *extraout_r4;
  JKRAMCommand *pJVar1;
  JKRAramPiece *this_00;
  JKRHeap__vtbl *pJVar2;
  JKRHeap *local_18 [3];
  
  os::OSInitMessageQueue((OSMessageQueue *)&sMessageQueue,(OSMessage *)&sMessageBuffer,4);
  do {
    do {
      os::OSReceiveMessage(&sMessageQueue,local_18,1);
      pJVar2 = local_18[0]->vtbl;
      this_00 = *(JKRAramPiece **)&local_18[0]->field_0x4;
      pJVar1 = extraout_r4;
      JKernel::operator_delete(local_18[0]);
    } while (pJVar2 != (JKRHeap__vtbl *)0x1);
    JKRAramPiece::startDMA(this_00,pJVar1);
  } while( true );
}


/* __thiscall JKRAram::checkOkAddress(unsigned char *,
                                      unsigned long,
                                      JKRAramBlock *,
                                      unsigned long) */

undefined4 __thiscall
JKRAram::checkOkAddress
          (JKRAram *this,uchar *param_1,ulong param_2,JKRAramBlock *param_3,ulong param_4)

{
  undefined4 uVar1;
  
  if ((((uint)this & 0x1f) == 0) || (((uint)param_1 & 0x1f) == 0)) {
    if ((param_2 == 0) || ((&param_3->field_0x0 + *(int *)(param_2 + 0x14) & 0x1fU) == 0)) {
      uVar1 = 1;
    }
    else {
      m_Do_printf::OSPanic("JKRAram.cpp",0xeb,":::address not 32Byte aligned.");
      uVar1 = 0;
    }
  }
  else {
    m_Do_printf::OSPanic("JKRAram.cpp",0xe2,":::address not 32Byte aligned.");
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall JKRAram::changeGroupIdIfNeed(unsigned char *,
                                           int) */

void __thiscall JKRAram::changeGroupIdIfNeed(JKRAram *this,uchar *param_1,int param_2)

{
  int iVar1;
  
  if ((-1 < (int)param_1) &&
     (iVar1 = (*(code *)JKRHeap::sCurrentHeap->vtbl->getHeapType)(), iVar1 == 0x45585048)) {
    *(char *)((int)&this[-1].field_0x74 + 3) = (char)param_1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall JKRAram::mainRamToAram(unsigned char *,
                                     unsigned long,
                                     unsigned long,
                                     JKRExpandSwitch,
                                     unsigned long,
                                     JKRHeap *,
                                     int) */

int * __thiscall
JKRAram::mainRamToAram
          (JKRAram *this,uchar *param_1,ulong param_2,ulong param_3,JKRExpandSwitch param_4,
          ulong param_5,JKRHeap *param_6,int param_7)

{
  uchar uVar1;
  JKRDecomp__CompressionType JVar2;
  uchar *extraout_r4;
  JKRExpandSwitch JVar3;
  JKRAramBlock *pJVar4;
  uchar *puVar5;
  int *piVar6;
  
  piVar6 = (int *)0x0;
  JVar3 = param_4;
  pJVar4 = (JKRAramBlock *)param_5;
  checkOkAddress(this,param_1,0,(JKRAramBlock *)0x0,param_4);
  puVar5 = extraout_r4;
  if (param_3 == 1) {
    JVar2 = JKRDecomp::checkCompressed((JKRDecomp *)this,extraout_r4);
    param_3 = (ulong)(JVar2 != NotCompressed);
  }
  uVar1 = (uchar)param_6;
  if (param_3 == 1) {
    JVar2 = JKRDecomp::checkCompressed((JKRDecomp *)this,puVar5);
    if (JVar2 == NotCompressed) {
      puVar5 = (uchar *)0x0;
    }
    else {
      puVar5 = (uchar *)((uint)*(byte *)&this->field_0x7 |
                        (uint)*(byte *)&this->field_0x6 << 8 |
                        (uint)*(byte *)&this->field_0x4 << 0x18 |
                        (uint)*(byte *)&this->field_0x5 << 0x10);
    }
    if ((param_4 == 0) || (puVar5 < param_4)) {
      param_4 = (JKRExpandSwitch)puVar5;
    }
    if (param_1 == (uchar *)0x0) {
      piVar6 = (int *)JKRAramHeap::alloc(sAramObject->mpHeap,param_4,0);
      if (piVar6 == (int *)0x0) {
        return (int *)0x0;
      }
      if ((int)param_6 < 0) {
        uVar1 = sAramObject->mpHeap->field_0x40;
      }
      *(uchar *)(piVar6 + 8) = uVar1;
      param_1 = (uchar *)piVar6[5];
    }
    if ((param_2 == 0) || (puVar5 < param_2)) {
      param_2 = (ulong)puVar5;
    }
    if (param_2 < param_4) {
      param_4 = param_2;
    }
    puVar5 = (uchar *)JKRHeap::alloc(param_4,-0x20,(JKRHeap *)param_5);
    if (puVar5 == (uchar *)0x0) {
      if ((piVar6 != (int *)0x0) && (piVar6 != (int *)0x0)) {
        (**(code **)(*piVar6 + 8))(piVar6,1);
      }
      piVar6 = (int *)0x0;
    }
    else {
      JKRDecomp::orderSync((JKRDecomp *)this,puVar5,(uchar *)param_4,0,JVar3);
      JKRAramPiece::orderSync
                ((JKRAramPiece *)0x0,(int)puVar5,(ulong)param_1,param_2,(ulong)piVar6,pJVar4);
      JKRHeap::free(puVar5,(JKRHeap *)param_5);
      if (piVar6 == (int *)0x0) {
        piVar6 = (int *)&DAT_ffffffff;
      }
    }
  }
  else {
    if (param_1 == (uchar *)0x0) {
      piVar6 = (int *)JKRAramHeap::alloc(sAramObject->mpHeap,param_2,0);
      if ((int)param_6 < 0) {
        uVar1 = sAramObject->mpHeap->field_0x40;
      }
      *(uchar *)(piVar6 + 8) = uVar1;
      if (piVar6 == (int *)0x0) {
        return (int *)0x0;
      }
      param_1 = (uchar *)piVar6[5];
    }
    JKRAramPiece::orderSync
              ((JKRAramPiece *)0x0,(int)this,(ulong)param_1,param_2,(ulong)piVar6,pJVar4);
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)&DAT_ffffffff;
    }
  }
  return piVar6;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall JKRAram::mainRamToAram(unsigned char *,
                                     JKRAramBlock *,
                                     unsigned long,
                                     JKRExpandSwitch,
                                     unsigned long,
                                     JKRHeap *,
                                     int) */

void __thiscall
JKRAram::mainRamToAram
          (JKRAram *this,uchar *param_1,JKRAramBlock *param_2,ulong param_3,JKRExpandSwitch param_4,
          ulong param_5,JKRHeap *param_6,int param_7)

{
  JKRAramBlock *pJVar1;
  
  checkOkAddress(this,(uchar *)0x0,(ulong)param_1,(JKRAramBlock *)0x0,param_4);
  if (param_1 == (uchar *)0x0) {
    mainRamToAram(this,(uchar *)0x0,(ulong)param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    pJVar1 = *(JKRAramBlock **)(param_1 + 0x18);
    if ((param_3 == 1) && (pJVar1 <= param_4)) {
      param_4 = (JKRExpandSwitch)pJVar1;
    }
    if (pJVar1 < param_2) {
      param_2 = pJVar1;
    }
    mainRamToAram(this,*(uchar **)(param_1 + 0x14),(ulong)param_2,param_3,param_4,param_5,param_6,
                  param_7);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall JKRAram::aramToMainRam(unsigned long,
                                     unsigned char *,
                                     unsigned long,
                                     JKRExpandSwitch,
                                     unsigned long,
                                     JKRHeap *,
                                     int,
                                     unsigned long *) */

ulong __thiscall
JKRAram::aramToMainRam
          (JKRAram *this,ulong param_1,uchar *param_2,ulong param_3,JKRExpandSwitch param_4,
          ulong param_5,JKRHeap *param_6,int param_7,ulong *param_8)

{
  JKRDecomp *this_00;
  uchar *extraout_r4;
  uint uVar1;
  JKRDecomp *pJVar2;
  ulong uVar3;
  JKRAramBlock *pJVar4;
  uchar *unaff_r23;
  JKRDecomp__CompressionType JVar5;
  JKRDecomp aJStack96 [4];
  byte bStack92;
  byte bStack91;
  byte bStack90;
  byte bStack89;
  
  JVar5 = NotCompressed;
  if (param_7 != 0) {
    *(undefined4 *)param_7 = 0;
  }
  uVar1 = 0;
  pJVar4 = (JKRAramBlock *)param_5;
  checkOkAddress((JKRAram *)param_1,(uchar *)this,0,(JKRAramBlock *)0x0,param_4);
  if (param_3 == 1) {
    JKRAramPiece::orderSync((JKRAramPiece *)&DAT_00000001,(int)this,(ulong)aJStack96,0x20,0,pJVar4);
    JVar5 = JKRDecomp::checkCompressed(aJStack96,extraout_r4);
    uVar1 = (uint)bStack89;
    unaff_r23 = (uchar *)(uVar1 | (uint)bStack90 << 8 |
                                  (uint)bStack92 << 0x18 | (uint)bStack91 << 0x10);
  }
  if (JVar5 == Yaz0Compressed) {
    if ((param_4 != 0) && (param_4 < unaff_r23)) {
      unaff_r23 = (uchar *)param_4;
    }
    if (param_1 == 0) {
      param_1 = JKRHeap::alloc((ulong)unaff_r23,0x20,(JKRHeap *)param_5);
      uVar1 = param_5;
    }
    if ((JKRAram *)param_1 == (JKRAram *)0x0) {
      param_1 = 0;
    }
    else {
      changeGroupIdIfNeed((JKRAram *)param_1,(uchar *)param_6,uVar1);
      JKernel::JKRDecompressFromAramToMainRam(this,param_1,param_2,unaff_r23,0);
      if (param_7 != 0) {
        *(uchar **)param_7 = unaff_r23;
      }
    }
  }
  else {
    if (JVar5 == Yay0Compressed) {
      this_00 = (JKRDecomp *)JKRHeap::alloc((ulong)param_2,-0x20,(JKRHeap *)param_5);
      if (this_00 == (JKRDecomp *)0x0) {
        param_1 = 0;
      }
      else {
        uVar3 = 0;
        pJVar2 = this_00;
        JKRAramPiece::orderSync
                  ((JKRAramPiece *)&DAT_00000001,(int)this,(ulong)this_00,(ulong)param_2,0,pJVar4);
        if ((param_4 != 0) && (param_4 < unaff_r23)) {
          unaff_r23 = (uchar *)param_4;
        }
        if (param_1 == 0) {
          pJVar2 = (JKRDecomp *)param_5;
          param_1 = JKRHeap::alloc((ulong)unaff_r23,0x20,(JKRHeap *)param_5);
        }
        if ((JKRAram *)param_1 == (JKRAram *)0x0) {
          JKRHeap::free(this_00,(JKRHeap *)0x0);
          param_1 = 0;
        }
        else {
          changeGroupIdIfNeed((JKRAram *)param_1,(uchar *)param_6,(int)pJVar2);
          JKRDecomp::orderSync(this_00,(uchar *)param_1,unaff_r23,0,uVar3);
          JKRHeap::free(this_00,(JKRHeap *)param_5);
          if (param_7 != 0) {
            *(uchar **)param_7 = unaff_r23;
          }
        }
      }
    }
    else {
      if (param_1 == 0) {
        param_1 = JKRHeap::alloc((ulong)param_2,0x20,(JKRHeap *)param_5);
        uVar1 = param_5;
      }
      if ((JKRAram *)param_1 == (JKRAram *)0x0) {
        param_1 = 0;
      }
      else {
        changeGroupIdIfNeed((JKRAram *)param_1,(uchar *)param_6,uVar1);
        JKRAramPiece::orderSync
                  ((JKRAramPiece *)&DAT_00000001,(int)this,param_1,(ulong)param_2,0,pJVar4);
        if (param_7 != 0) {
          *(uchar **)param_7 = param_2;
        }
      }
    }
  }
  return param_1;
}


namespace JKRAram {

/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall aramToMainRam(JKRAramBlock *,
                                     unsigned char *,
                                     unsigned long,
                                     unsigned long,
                                     JKRExpandSwitch,
                                     unsigned long,
                                     JKRHeap *,
                                     int,
                                     unsigned long *) */

undefined4
aramToMainRam
          (JKRAramBlock *param_1,uchar *param_2,ulong param_3,ulong param_4,JKRExpandSwitch param_5,
          ulong param_6,JKRHeap *param_7,int param_8,ulong *param_9)

{
  uchar *puVar1;
  undefined4 uVar2;
  ulong *in_stack_ffffffd8;
  
  if (param_9 != (ulong *)0x0) {
    *param_9 = 0;
  }
  checkOkAddress((JKRAram *)param_2,(uchar *)0x0,(ulong)param_1,(JKRAramBlock *)param_4,param_5);
  if (param_1 == (JKRAramBlock *)0x0) {
    m_Do_printf::OSPanic("JKRAram.cpp",0x2ab,":::Bad Aram Block specified.\n");
  }
  puVar1 = (uchar *)param_1->field_0x18;
  if (param_4 < puVar1) {
    if (param_3 == 0) {
      param_3 = (ulong)puVar1;
    }
    if (puVar1 < (uchar *)(param_3 + param_4)) {
      param_3 = (ulong)(puVar1 + -param_4);
    }
    uVar2 = aramToMainRam((JKRAram *)(param_4 + param_1->field_0x14),(ulong)param_2,(uchar *)param_3
                          ,param_5,param_6,(ulong)param_7,(JKRHeap *)param_8,(int)param_9,
                          in_stack_ffffffd8);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

}

namespace JKernel {

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall JKRDecompressFromAramToMainRam(unsigned long,
                                            void *,
                                            unsigned long,
                                            unsigned long,
                                            unsigned long) */

undefined4
JKRDecompressFromAramToMainRam
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  int iVar4;
  
  uVar2 = os::OSDisableInterrupts();
  if (isInitMutex == '\0') {
    os::OSInitMutex((OSMutex *)&decompMutex);
    isInitMutex = '\x01';
  }
  os::OSRestoreInterrupts(uVar2);
  os::OSLockMutex((OSMutex *)&decompMutex);
  uVar1 = ::JKRAram::sSzpBufferSize;
  szpBuf = (JKRHeap *)::JKRHeap::alloc(::JKRHeap::sSystemHeap,::JKRAram::sSzpBufferSize,0x20);
  if (szpBuf == (JKRHeap *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"JKRAram.cpp",0x435,"szpBuf != 0");
    m_Do_printf::OSPanic("JKRAram.cpp",0x435,&DAT_8036b786);
  }
  szpEnd = (int)&szpBuf->vtbl + uVar1;
  if (param_5 == 0) {
    refBuf = (void *)0x0;
  }
  else {
    refBuf = ::JKRHeap::alloc(::JKRHeap::sSystemHeap,0x1120,0);
    if (refBuf == (void *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"JKRAram.cpp",0x43e,"refBuf != 0");
      m_Do_printf::OSPanic("JKRAram.cpp",0x43e,&DAT_8036b786);
    }
    refEnd = (int)refBuf + 0x1120;
    refCurrent = refBuf;
  }
  srcOffset = 0;
  transLeft = -1;
  if (param_3 != 0) {
    transLeft = param_3;
  }
  readCount = 0;
  srcAddress = param_1;
  fileOffset = param_5;
  maxDest = param_4;
  iVar4 = firstSrcData();
  uVar2 = *(undefined4 *)(iVar4 + 4);
  decompSZS_subroutine(iVar4,param_2);
  ::JKRHeap::free(szpBuf,(JKRHeap *)0x0);
  if (refBuf != (void *)0x0) {
    ::JKRHeap::free(refBuf,(JKRHeap *)0x0);
  }
  os::DCStoreRangeNoSync(param_2,uVar2);
  os::OSUnlockMutex(&decompMutex);
  return 0;
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
        if ((srcLimit < pbVar3) && (transLeft != 0)) {
          pbVar3 = (byte *)nextSrcData();
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

JKRHeap * firstSrcData(void)

{
  JKRHeap *pJVar1;
  JKRAramBlock *in_r8;
  uint uVar2;
  
  pJVar1 = szpBuf;
  srcLimit = szpEnd + -0x19;
  uVar2 = szpEnd - (int)szpBuf;
  if (transLeft < (uint)(szpEnd - (int)szpBuf)) {
    uVar2 = transLeft;
  }
  ::JKRAramPiece::orderSync
            ((JKRAramPiece *)&DAT_00000001,srcAddress + srcOffset,(ulong)szpBuf,
             uVar2 + 0x1f & 0xffffffe0,0,in_r8);
  if (transLeft - uVar2 == 0) {
    srcLimit = (int)&pJVar1->vtbl + uVar2;
  }
  srcOffset = srcOffset + uVar2;
  transLeft = transLeft - uVar2;
  return pJVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall nextSrcData(unsigned char *) */

JKRHeap * nextSrcData(byte *param_1)

{
  ulong uVar1;
  JKRAramBlock *in_r8;
  uint uVar2;
  uint length;
  JKRHeap *dst;
  
  length = szpEnd - (int)param_1;
  dst = szpBuf;
  if ((length & 0x1f) != 0) {
    dst = (JKRHeap *)((int)szpBuf + (0x20 - (length & 0x1f)));
  }
  copy_bytes((byte *)dst,param_1,length);
  uVar2 = szpEnd - ((int)dst + length);
  if (transLeft < uVar2) {
    uVar2 = transLeft;
  }
  if (uVar2 == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JKRAram.cpp",0x551,"transSize > 0");
    m_Do_printf::OSPanic("JKRAram.cpp",0x551,&DAT_8036b786);
  }
  ::JKRAramPiece::orderSync
            ((JKRAramPiece *)&DAT_00000001,srcAddress + srcOffset,(int)dst + length,
             uVar2 + 0x1f & 0xffffffe0,0,in_r8);
  if (transLeft - uVar2 == 0) {
    srcLimit = (int)dst + length + uVar2;
  }
  srcOffset = srcOffset + uVar2;
  transLeft = transLeft - uVar2;
  return dst;
}


void __sinit_JKRAram_cpp(void)

{
  JSUPtrList::initiate((JSUPtrList *)&::JKRAram::sAramCommandList);
  Runtime.PPCEABI.H::__register_global_object
            (&::JKRAram::sAramCommandList,::JSUList<JKRAMCommand>::_JSUList,&_287);
  return;
}

}

/* __thiscall JSUList<JKRAMCommand>::~JSUList(void) */

JSUList_JKRAMCommand_ * __thiscall JSUList<JKRAMCommand>::_JSUList(JSUList_JKRAMCommand_ *this)

{
  short in_r4;
  
  if ((this != (JSUList_JKRAMCommand_ *)0x0) &&
     (JSUPtrList::_JSUPtrList((JSUPtrList *)this), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return this;
}

