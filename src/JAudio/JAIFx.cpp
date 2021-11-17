#include <JAudio/JAIFx.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JAIFx.h>
#include <JAudio/JASDSPInterface.h>
#include <JAInter/Fx.h>


namespace JAInter {
undefined1 Fx;
undefined1 Fx;
undefined1 Fx;
undefined1 Fx;
undefined1 Fx;

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Fx::init(void) */

int __thiscall Fx::init(Fx *this,EVP_PKEY_CTX *ctx)

{
  uint *puVar1;
  Fx *pFVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  FXBuffer *this_00;
  uchar extraout_r4_00;
  void **extraout_r4;
  void **ppvVar7;
  uchar uVar8;
  uchar extraout_r4_01;
  uchar extraout_r4_02;
  uchar extraout_r4_03;
  uchar extraout_r4_04;
  short *psVar9;
  ulong in_r7;
  Fx *pFVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  
  if (_initOnCodeFxScene != (uint *)0x0) {
    if ((_msCurrentHeap == 0) &&
       (m_Do_printf::OSReport
                  ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
       _msCurrentHeap == 0)) {
      JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
      m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369075);
    }
    _mBufferSizeMax = JKernel::operator_new__(0x10,_msCurrentHeap,4);
    if ((_msCurrentHeap == 0) &&
       (m_Do_printf::OSReport
                  ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
       _msCurrentHeap == 0)) {
      JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
      m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369075);
    }
    _mBufferPointer = JKernel::operator_new__(0x10,_msCurrentHeap,4);
    puVar1 = _initOnCodeFxScene;
    setSceneMax((Fx *)(*_initOnCodeFxScene & 0xff),extraout_r4_00);
    pFVar2 = (Fx *)setBufferMax((Fx *)puVar1[1],puVar1[2],puVar1[3],puVar1[4],in_r7);
    if ((_msCurrentHeap == 0) &&
       (pFVar2 = (Fx *)m_Do_printf::OSReport
                                 (
                                 "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                                 ), _msCurrentHeap == 0)) {
      JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
      pFVar2 = (Fx *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369075);
    }
    iVar5 = _msCurrentHeap;
    uVar3 = getSceneMax(pFVar2);
    uVar11 = JKernel::operator_new__((uVar3 & 0xff) << 2,iVar5,0x20);
    pFVar2 = (Fx *)((ulonglong)uVar11 >> 0x20);
    ppvVar7 = (void **)uVar11;
    if (pFVar2 == (Fx *)0x0) {
      m_Do_printf::OSReport("JAIFx::initHeap Cannot Alloc Heap!!\n");
      JUTAssertion::showAssert(3,"JAIFx.cpp",0x2e,"_heap");
      m_Do_printf::OSPanic("JAIFx.cpp",0x2e,&DAT_80369075);
      ppvVar7 = extraout_r4;
    }
    pFVar2 = (Fx *)setTablePointer(pFVar2,ppvVar7);
    pFVar10 = (Fx *)0x0;
    while( true ) {
      uVar12 = getSceneMax(pFVar2);
      uVar13 = uVar12 & 0xffffffffff;
      if (((uint)(uVar12 >> 0x20) & 0xff) <= ((uint)pFVar10 & 0xff)) break;
      pFVar2 = (Fx *)setScenePointer(pFVar10,(char)_initOnCodeFxScene +
                                             (char)puVar1[((uint)pFVar10 & 0xff) + 5],
                                     _initOnCodeFxScene);
      pFVar10 = pFVar10 + 1;
    }
    for (pFVar2 = (Fx *)0x0; this = (Fx *)(uVar13 >> 0x20), ((uint)pFVar2 & 0xff) < 4;
        pFVar2 = pFVar2 + 1) {
      uVar13 = getBufferSizeMax(pFVar2,(uchar)uVar13);
      uVar8 = (uchar)uVar13;
      if ((int)(uVar13 >> 0x20) != 0) {
        if ((_msCurrentHeap == 0) &&
           (m_Do_printf::OSReport
                      (
                      "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                      ), uVar8 = extraout_r4_01, _msCurrentHeap == 0)) {
          JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
          m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369075);
          uVar8 = extraout_r4_02;
        }
        iVar5 = _msCurrentHeap;
        iVar4 = getBufferSizeMax(pFVar2,uVar8);
        psVar9 = (short *)&DAT_00000020;
        iVar5 = JKernel::operator_new__(iVar4 * 0xa0,iVar5);
        if (iVar5 == 0) {
          m_Do_printf::OSReport("JAIFx::initHeap Cannot Alloc Heap!!\n");
          JUTAssertion::showAssert(3,"JAIFx.cpp",0x39,"_buf");
          psVar9 = (short *)&DAT_80369075;
          m_Do_printf::OSPanic("JAIFx.cpp",0x39);
        }
        pFVar10 = (Fx *)setBufferPointer(pFVar2,(uchar)iVar5,psVar9);
        piVar6 = (int *)getFxconfigTable(pFVar10);
        iVar5 = *piVar6;
        psVar9 = (short *)getBufferPointer(pFVar2,extraout_r4_03);
        this_00 = (FXBuffer *)
                  JASystem::DSPInterface::getFXHandle((DSPInterface *)pFVar2,extraout_r4_04);
        uVar13 = JASystem::DSPInterface::FXBuffer::setFXLine
                           (this_00,psVar9,(FxlineConfig_ *)(iVar5 + ((uint)pFVar2 & 0xff) * 0x20));
      }
    }
  }
  return (int)this;
}


/* __thiscall Fx::setSceneMax(unsigned char) */

void __thiscall Fx::setSceneMax(Fx *this,uchar param_1)

{
  mSceneMax = (char)this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Fx::setBufferMax(unsigned long,
                                        unsigned long,
                                        unsigned long,
                                        unsigned long) */

void __thiscall
Fx::setBufferMax(Fx *this,ulong param_1,ulong param_2,ulong param_3,ulong param_4)

{
  *_mBufferSizeMax = this;
  _mBufferSizeMax[1] = (Fx *)param_1;
  _mBufferSizeMax[2] = (Fx *)param_2;
  _mBufferSizeMax[3] = (Fx *)param_3;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Fx::setTablePointer(void * *) */

void __thiscall Fx::setTablePointer(Fx *this,void **param_1)

{
  _mFxconfigTable = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Fx::setBufferPointer(unsigned char,
                                            short *) */

void __thiscall Fx::setBufferPointer(Fx *this,uchar param_1,short *param_2)

{
  undefined3 in_register_00000010;
  
  *(uint *)(_mBufferPointer + ((uint)this & 0xff) * 4) = CONCAT31(in_register_00000010,param_1);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Fx::setScenePointer(unsigned char,
                                           void *) */

void __thiscall Fx::setScenePointer(Fx *this,uchar param_1,void *param_2)

{
  undefined3 in_register_00000010;
  
  *(uint *)(_mFxconfigTable + ((uint)this & 0xff) * 4) = CONCAT31(in_register_00000010,param_1);
  return;
}


/* __thiscall Fx::getSceneMax(void) */

undefined __thiscall Fx::getSceneMax(Fx *this)

{
  return mSceneMax;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Fx::getBufferSizeMax(unsigned char) */

undefined4 __thiscall Fx::getBufferSizeMax(Fx *this,uchar param_1)

{
  return *(undefined4 *)(_mBufferSizeMax + ((uint)this & 0xff) * 4);
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Fx::getBufferPointer(unsigned char) */

undefined4 __thiscall Fx::getBufferPointer(Fx *this,uchar param_1)

{
  return *(undefined4 *)(_mBufferPointer + ((uint)this & 0xff) * 4);
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Fx::getFxconfigTable(void) */

undefined4 __thiscall Fx::getFxconfigTable(Fx *this)

{
  return _mFxconfigTable;
}

