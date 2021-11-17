#include <JAudio/JAIStreamMgr.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAudio/JAIGlobalParameter.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <JAudio/JAISound.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JAISeMgr.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JAudio/JAIStreamMgr.h>
#include <JAudio/JASDvdThread.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JAudio/JAIBasic.h>
#include <JAudio/JASDSPInterface.h>
#include <JAudio/JASDSPChannel.h>
#include <JAudio/JASHeapCtrl.h>
#include <os/OSCache.h>
#include <dvd/dvdfs.h>
#include <JAudio/JASCallback.h>
#include <dvd/dvd.h>
#include <JAudio/JASCalc.h>
#include <JAudio/JASSystemHeap.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JAInter/StreamMgr.h>
#include <JAInter/StreamLib.h>


namespace JAInter {
undefined1 StreamMgr;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamMgr;
undefined1 StreamMgr;
undefined1 StreamMgr;
undefined1 StreamMgr;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
undefined1 StreamLib;
}

namespace JAudio {
undefined4 before$1183;
undefined1 init$1184;
undefined2 L1$1209;
undefined2 L2$1210;
undefined2 R1$1211;
undefined2 R2$1212;
undefined4 oldstat$1491;
undefined1 init$1492;
undefined4 old_dspside$1515;
undefined1 init$1516;
}

namespace JAInter {

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamMgr::init(void) */

int __thiscall StreamMgr::init(StreamMgr *this,EVP_PKEY_CTX *ctx)

{
  int *piVar1;
  float fVar2;
  undefined4 uVar3;
  EVP_PKEY_CTX *ctx_00;
  EVP_PKEY_CTX *this_00;
  JAIGlobalParameter *pJVar4;
  void *pvVar5;
  uint uVar6;
  undefined *puVar7;
  int iVar8;
  uint uVar9;
  
  piVar1 = _msBasic;
  flags = flags & 0x1f;
  uVar3 = JAIGlobalParameter::getParamStreamControlBufferMax((JAIGlobalParameter *)0x0);
  ctx_00 = (EVP_PKEY_CTX *)(**(code **)(*piVar1 + 8))(piVar1,uVar3);
  this_00 = ctx_00;
  if (ctx_00 == (EVP_PKEY_CTX *)0x0) {
    m_Do_printf::OSReport("JAIStreamMgr::initHeap Cannot Alloc Heap!!\n");
    JUTAssertion::showAssert(3,"JAIStreamMgr.cpp",0x2e,"soundObjects");
    this_00 = (EVP_PKEY_CTX *)m_Do_printf::OSPanic("JAIStreamMgr.cpp",0x2e,&DAT_80369ef2);
  }
  JAIGlobalParameter::getParamStreamControlBufferMax((JAIGlobalParameter *)this_00);
  LinkSound::init((LinkSound *)&streamControl,ctx_00);
  iVar8 = 0;
  pJVar4 = (JAIGlobalParameter *)0x80290000;
  for (uVar9 = 0; uVar6 = JAIGlobalParameter::getParamStreamParameterBufferMax(pJVar4),
      uVar9 < uVar6; uVar9 = uVar9 + 1) {
    if ((_msCurrentHeap == (JKRHeap *)0x0) &&
       (m_Do_printf::OSReport
                  ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
       _msCurrentHeap == (JKRHeap *)0x0)) {
      JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
      m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369ef2);
    }
    pvVar5 = JKernel::operator_new(0x160,_msCurrentHeap,0x20);
    if (pvVar5 == (void *)0x0) {
      m_Do_printf::OSReport("JAIStreamMgr::initHeap Cannot Alloc Heap!!\n");
      JUTAssertion::showAssert(3,"JAIStreamMgr.cpp",0x34,"_para");
      pJVar4 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIStreamMgr.cpp",0x34,&DAT_80369ef2);
    }
    else {
      pJVar4 = (JAIGlobalParameter *)((int)pvVar5 + 0x14);
      Runtime.PPCEABI.H::__construct_array(pJVar4,MoveParaSet::__defctor,(undefined *)0x0,0x10,0x14)
      ;
    }
    uVar6 = JAIGlobalParameter::getParamStreamParameterLines(pJVar4);
    if ((_msCurrentHeap == (JKRHeap *)0x0) &&
       (m_Do_printf::OSReport
                  ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
       _msCurrentHeap == (JKRHeap *)0x0)) {
      JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
      m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369ef2);
    }
    uVar3 = JKernel::operator_new__((uVar6 & 0xff) * 0x10 + 0x10,_msCurrentHeap,0x20);
    pJVar4 = (JAIGlobalParameter *)
             Runtime.PPCEABI.H::__construct_new_array
                       (uVar3,MoveParaSet::__defctor,0,0x10,uVar6 & 0xff);
    *(JAIGlobalParameter **)((int)pvVar5 + 0x158) = pJVar4;
    if ((*(int *)((int)pvVar5 + 0x158) == 0) &&
       (pJVar4 = (JAIGlobalParameter *)
                 m_Do_printf::OSReport("JAIStreamMgr::initHeap Cannot Alloc Heap!!\n"),
       *(int *)((int)pvVar5 + 0x158) == 0)) {
      JUTAssertion::showAssert(3,"JAIStreamMgr.cpp",0x36,"_para->pan");
      pJVar4 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIStreamMgr.cpp",0x36,&DAT_80369ef2);
    }
    uVar6 = JAIGlobalParameter::getParamStreamParameterLines(pJVar4);
    if ((_msCurrentHeap == (JKRHeap *)0x0) &&
       (m_Do_printf::OSReport
                  ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
       _msCurrentHeap == (JKRHeap *)0x0)) {
      JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
      m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369ef2);
    }
    uVar3 = JKernel::operator_new__((uVar6 & 0xff) * 0x10 + 0x10,_msCurrentHeap,0x20);
    uVar3 = Runtime.PPCEABI.H::__construct_new_array
                      (uVar3,MoveParaSet::__defctor,0,0x10,uVar6 & 0xff);
    *(undefined4 *)((int)pvVar5 + 0x154) = uVar3;
    if ((*(int *)((int)pvVar5 + 0x154) == 0) &&
       (m_Do_printf::OSReport("JAIStreamMgr::initHeap Cannot Alloc Heap!!\n"),
       *(int *)((int)pvVar5 + 0x154) == 0)) {
      JUTAssertion::showAssert(3,"JAIStreamMgr.cpp",0x38,"_para->pitch");
      m_Do_printf::OSPanic("JAIStreamMgr.cpp",0x38,&DAT_80369ef2);
    }
    pJVar4 = DAT_803ed0d0;
    *(void **)(DAT_803ed0d0 + iVar8 + 0x3c) = pvVar5;
    iVar8 = iVar8 + 0x44;
  }
  if ((_msCurrentHeap == (JKRHeap *)0x0) &&
     (m_Do_printf::OSReport
                ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
     _msCurrentHeap == (JKRHeap *)0x0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369ef2);
  }
  _streamUpdate = (undefined *)JKernel::operator_new(0x18,_msCurrentHeap,0x20);
  if (_streamUpdate == (undefined *)0x0) {
    m_Do_printf::OSReport("JAIStreamMgr::initHeap Cannot Alloc Heap!!\n");
    if (_streamUpdate == (undefined *)0x0) {
      JUTAssertion::showAssert(3,"JAIStreamMgr.cpp",0x3d,"streamUpdate");
      m_Do_printf::OSPanic("JAIStreamMgr.cpp",0x3d,&DAT_80369ef2);
    }
  }
  else {
    *(undefined4 *)(_streamUpdate + 0x14) = 0;
  }
  puVar7 = _streamUpdate;
  *_streamUpdate = 0;
  puVar7[1] = 0;
  fVar2 = JAudio::_830;
  *(float *)(puVar7 + 4) = JAudio::_830;
  *(float *)(puVar7 + 8) = fVar2;
  *(float *)(puVar7 + 0xc) = JAudio::_831;
  *(undefined4 *)(puVar7 + 0x10) = 0;
  *(undefined4 *)(puVar7 + 0x14) = 0;
  return (int)puVar7;
}


namespace StreamMgr {

/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* WARNING: Removing unreachable block (ram,0x8029c024) */
/* WARNING: Removing unreachable block (ram,0x8029c02c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall storeStreamBuffer(JAISound * *,
                                                    JAInter::Actor *,
                                                    unsigned long,
                                                    unsigned long,
                                                    unsigned char,
                                                    void *) */

void storeStreamBuffer
               (JAISound **param_1,Actor *param_2,ulong param_3,ulong param_4,uchar param_5,
               void *param_6)

{
  float fVar1;
  int iVar2;
  JAISound *this;
  undefined *puVar3;
  float *pfVar4;
  uint uVar5;
  void *pvVar6;
  float *pfVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  pvVar6 = (void *)param_3;
  if (((param_1 == (JAISound **)0x0) || (*param_1 == (JAISound *)0x0)) ||
     (pvVar6 = param_6, iVar2 = JAISound::checkSoundHandle(*param_1,param_3,param_6), iVar2 == 0)) {
    if (DAT_803ed0cc != (StreamMgr *)0x0) {
      releaseStreamBuffer(DAT_803ed0cc,(JAISound *)0x0,(ulong)pvVar6);
    }
    this = (JAISound *)LinkSound::getSound((LinkSound *)&streamControl);
    puVar3 = (undefined *)JAISound::getStreamParameter(this);
    *puVar3 = 0;
    *(undefined4 *)(puVar3 + 4) = 0;
    *(undefined4 *)(puVar3 + 8) = 0;
    *(undefined4 *)(puVar3 + 0xc) = 0;
    *(undefined4 *)(puVar3 + 0x10) = 0;
    fVar1 = JAudio::_830;
    pfVar4 = (float *)0x0;
    iVar2 = 0x14;
    do {
      pfVar7 = (float *)(puVar3 + (int)(pfVar4 + 5));
      pfVar7[1] = fVar1;
      *pfVar7 = fVar1;
      pfVar7[3] = 0.0;
      pfVar4 = pfVar4 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    iVar2 = 0;
    dVar10 = (double)JAudio::_830;
    dVar11 = (double)JAudio::_831;
    for (uVar8 = 0;
        uVar5 = JAIGlobalParameter::getParamStreamParameterLines((JAIGlobalParameter *)pfVar4),
        uVar8 < (uVar5 & 0xff); uVar8 = uVar8 + 1) {
      pfVar4 = (float *)(*(int *)(puVar3 + 0x154) + iVar2);
      pfVar4[1] = (float)dVar10;
      *pfVar4 = (float)dVar10;
      pfVar4[3] = 0.0;
      pfVar4 = (float *)(*(int *)(puVar3 + 0x158) + iVar2);
      pfVar4[1] = (float)dVar11;
      *pfVar4 = (float)dVar11;
      pfVar4[3] = 0.0;
      iVar2 = iVar2 + 0x10;
    }
    *(undefined *)&this->field_0x5 = 1;
    *(undefined *)&this->field_0x6 = 10;
    *(undefined *)(_streamUpdate + 2) = 0;
    JAISound::initParameter(this,param_1,param_2,param_3,param_4,param_5,param_6);
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  return;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamMgr::releaseStreamBuffer(JAISound *,
                                                      unsigned long) */

void __thiscall
StreamMgr::releaseStreamBuffer(StreamMgr *this,JAISound *param_1,ulong param_2)

{
  Dvd *this_00;
  int iVar1;
  
  if ((param_1 == (JAISound *)0x0) || ((byte)this[5] < 4)) {
    StreamLib::stop((StreamLib *)this);
    this[5] = (StreamMgr)0x0;
    *(undefined4 *)(_streamUpdate + 0x14) = 0;
    JAISound::clearMainSoundPPointer((JAISound *)this);
    this_00 = (Dvd *)LinkSound::releaseSound((LinkSound *)&streamControl,(JAISound *)this);
    JASystem::Dvd::unpauseDvdT(this_00);
  }
  else {
    iVar1 = JAISound::getStreamParameter((JAISound *)this);
    if (*(int *)(iVar1 + 0x15c) != 0) {
      iVar1 = JAISound::getStreamParameter((JAISound *)this);
      *(uint *)(*(int *)(iVar1 + 0x15c) + 0x10) = *(uint *)(*(int *)(iVar1 + 0x15c) + 0x10) | 2;
      *(JAISound **)(this + 0x14) = param_1;
    }
  }
  return;
}


/* __thiscall StreamMgr::processGFrameStream(void) */

void __thiscall StreamMgr::processGFrameStream(StreamMgr *this)

{
  StreamMgr *pSVar1;
  
  if ((flags >> 6 & 1) == 0) {
    pSVar1 = (StreamMgr *)checkPlayingStream(this);
    pSVar1 = (StreamMgr *)checkRequestStream(pSVar1);
    pSVar1 = (StreamMgr *)checkWaitStream(pSVar1);
    checkEntriedStream(pSVar1);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamMgr::checkEntriedStream(void) */

void __thiscall StreamMgr::checkEntriedStream(StreamMgr *this)

{
  float fVar1;
  StreamLib *pSVar2;
  int iVar3;
  JAISound *this_00;
  
  pSVar2 = (StreamLib *)&streamControl;
  for (this_00 = DAT_803ed0cc; this_00 != (JAISound *)0x0;
      this_00 = *(JAISound **)&this_00[1].field_0x14) {
    if ((*(char *)&this_00->field_0x5 == '\x01') &&
       (pSVar2 = (StreamLib *)StreamLib::getPlayingFlag(pSVar2), ((uint)pSVar2 & 0xff) != 1)) {
      *(undefined *)&this_00->field_0x5 = 2;
      pSVar2 = _streamUpdate;
      iVar3 = JAISound::getStreamParameter(this_00);
      *(StreamLib **)(iVar3 + 0x15c) = pSVar2;
      pSVar2 = _streamUpdate;
      *_streamUpdate = (StreamLib)0x0;
      pSVar2[1] = (StreamLib)0x0;
      fVar1 = JAudio::_830;
      *(float *)(pSVar2 + 4) = JAudio::_830;
      *(float *)(pSVar2 + 8) = fVar1;
      *(float *)(pSVar2 + 0xc) = JAudio::_831;
      *(undefined4 *)(pSVar2 + 0x10) = 0;
      *(undefined4 *)(pSVar2 + 0x14) = 0;
      pSVar2 = _streamUpdate;
      *(JAISound **)(_streamUpdate + 0x14) = this_00;
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamMgr::checkWaitStream(void) */

void __thiscall StreamMgr::checkWaitStream(StreamMgr *this)

{
  char *__src;
  uint uVar1;
  StreamMgr *this_00;
  int iVar2;
  uchar extraout_r4;
  JAISound *this_01;
  StreamLib aSStack72 [68];
  
  this_01 = *(JAISound **)(_streamUpdate + 0x14);
  if ((this_01 != (JAISound *)0x0) && (*(char *)&this_01->field_0x5 == '\x02')) {
    __src = (char *)JAIGlobalParameter::getParamStreamPath(_streamUpdate);
    MSL_C.PPCEABI.bare.H::strcpy((char *)aSStack72,__src);
    uVar1 = JAIBasic::getSoundOffsetNumberFromID((JAIBasic *)_msBasic,this_01->field_0xc);
    MSL_C.PPCEABI.bare.H::strcat
              ((char *)aSStack72,(char *)((int)_streamList + (uVar1 & 0xffff) * 0x30 + 0x10));
    this_00 = (StreamMgr *)(**(code **)(*_msBasic + 0x18))(_msBasic,this_01);
    *(undefined *)&this_01->field_0x5 = 3;
    checkPlayingStream(this_00);
    iVar2 = JAISound::getStreamParameter(this_01);
    StreamLib::start(aSStack72,*(char **)(iVar2 + 4),
                     (int)_streamList + (this_01->field_0xc & 0x3ffU) * 0x30 + 0x20,_streamList);
    StreamLib::setPrepareFlag((StreamLib *)&DAT_00000001,extraout_r4);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamMgr::checkRequestStream(void) */

void __thiscall StreamMgr::checkRequestStream(StreamMgr *this)

{
  StreamLib *this_00;
  uchar in_r4;
  uchar extraout_r4;
  JAISound *this_01;
  
  this_01 = *(JAISound **)(_streamUpdate + 0x14);
  if (((this_01 != (JAISound *)0x0) && (*(char *)&this_01->field_0x5 == '\x03')) &&
     (*(char *)(_streamUpdate + 2) == '\0')) {
    *(undefined *)&this_01->field_0x5 = 4;
    if (1 < *(uint *)&this_01->field_0x14) {
      JAISound::setStreamInterVolume(this_01,'\a',JAudio::_931,0);
      this_00 = (StreamLib *)
                JAISound::setStreamInterVolume
                          (this_01,'\a',JAudio::_830,*(ulong *)&this_01->field_0x14);
      StreamLib::setVolume(this_00,JAudio::_931);
      in_r4 = extraout_r4;
    }
    StreamLib::setPrepareFlag((StreamLib *)0x0,in_r4);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x8029c708) */
/* WARNING: Removing unreachable block (ram,0x8029c710) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamMgr::checkPlayingStream(void) */

StreamMgr * __thiscall StreamMgr::checkPlayingStream(StreamMgr *this)

{
  float fVar1;
  StreamLib *pSVar2;
  StreamLib *this_00;
  char cVar5;
  int iVar3;
  int iVar4;
  byte bVar7;
  MoveParaSet *pMVar6;
  JAISound *this_01;
  undefined4 uVar8;
  double extraout_f1;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pSVar2 = _streamUpdate;
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  this_01 = *(JAISound **)(_streamUpdate + 0x14);
  if (this_01 != (JAISound *)0x0) {
    if (3 < *(byte *)&this_01->field_0x5) {
      this_00 = (StreamLib *)JAISound::getStreamParameter(this_01);
      cVar5 = StreamLib::getPlayingFlag(this_00);
      if (cVar5 == '\x02') {
        *(undefined *)&this_01->field_0x5 = 0;
        iVar3 = JAISound::getStreamParameter(this_01);
        if (*(int *)(iVar3 + 0x15c) != 0) {
          iVar3 = JAISound::getStreamParameter(this_01);
          *(undefined4 *)(*(int *)(iVar3 + 0x15c) + 0x14) = 0;
        }
        JAISound::clearMainSoundPPointer(this_01);
        this = (StreamMgr *)LinkSound::releaseSound((LinkSound *)&streamControl,this_01);
        goto LAB_8029c708;
      }
      this = (StreamMgr *)(uint)*(byte *)&this_01->field_0x6;
      if (this != (StreamMgr *)0x0) {
        *(byte *)&this_01->field_0x6 = *(byte *)&this_01->field_0x6 - 1;
      }
      if ((*(uint *)(pSVar2 + 0x10) & 2) != 0) {
        this = (StreamMgr *)
               JAISound::setStreamInterVolume
                         (this_01,'\a',JAudio::_931,*(ulong *)&this_01->field_0x14);
        *(undefined *)&this_01->field_0x5 = 5;
        *(uint *)(pSVar2 + 0x10) = *(uint *)(pSVar2 + 0x10) ^ 2;
      }
      if ((*(char *)&this_01->field_0x5 == '\x05') &&
         (((this = (StreamMgr *)JAISound::getStreamInterVolume(this_01,'\a'),
           (double)JAudio::_931 == extraout_f1 || (*(int *)&this_01->field_0x14 == 0)) &&
          (*(char *)&this_01->field_0x6 == '\0')))) {
        StreamLib::stop((StreamLib *)this);
        *(undefined *)&this_01->field_0x5 = 0;
        iVar3 = JAISound::getStreamParameter(this_01);
        if (*(int *)(iVar3 + 0x15c) != 0) {
          iVar3 = JAISound::getStreamParameter(this_01);
          *(undefined4 *)(*(int *)(iVar3 + 0x15c) + 0x14) = 0;
        }
        JAISound::clearMainSoundPPointer(this_01);
        this = (StreamMgr *)LinkSound::releaseSound((LinkSound *)&streamControl,this_01);
      }
    }
    if (2 < *(byte *)&this_01->field_0x5) {
      iVar3 = JAISound::getStreamParameter(this_01);
      if ((*(uint *)(pSVar2 + 0x10) & 0x40000) != 0) {
        fVar1 = JAudio::_830;
        for (bVar7 = 0; dVar10 = (double)fVar1, bVar7 < 0x14; bVar7 = bVar7 + 1) {
          pMVar6 = (MoveParaSet *)(iVar3 + (uint)bVar7 * 0x10 + 0x14);
          if (((*(uint *)(iVar3 + 8) & 1 << (uint)bVar7) != 0) &&
             (iVar4 = MoveParaSet::move(pMVar6), iVar4 == 0)) {
            *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) ^ 1 << (uint)bVar7;
          }
          fVar1 = (float)(dVar10 * (double)*(float *)(pMVar6 + 4));
        }
        if ((double)*(float *)(_streamUpdate + 4) != dVar10) {
          StreamLib::setVolume(_streamUpdate,fVar1);
          *(float *)(_streamUpdate + 4) = (float)dVar10;
        }
        if (*(int *)(iVar3 + 8) == 0) {
          *(uint *)(pSVar2 + 0x10) = *(uint *)(pSVar2 + 0x10) ^ 0x40000;
        }
      }
      if ((*(uint *)(pSVar2 + 0x10) & 0x100000) != 0) {
        fVar1 = JAudio::_830;
        for (bVar7 = 0; dVar10 = (double)fVar1, bVar7 < 7; bVar7 = bVar7 + 1) {
          pMVar6 = (MoveParaSet *)(*(int *)(iVar3 + 0x154) + (uint)bVar7 * 0x10);
          if (((*(uint *)(iVar3 + 0xc) & 1 << (uint)bVar7) != 0) &&
             (iVar4 = MoveParaSet::move(pMVar6), iVar4 == 0)) {
            *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) ^ 1 << (uint)bVar7;
          }
          fVar1 = (float)(dVar10 * (double)*(float *)(pMVar6 + 4));
        }
        if ((double)*(float *)(_streamUpdate + 8) != dVar10) {
          StreamLib::setPitch(_streamUpdate,fVar1);
          *(float *)(_streamUpdate + 8) = (float)dVar10;
        }
        if (*(int *)(iVar3 + 0xc) == 0) {
          *(uint *)(pSVar2 + 0x10) = *(uint *)(pSVar2 + 0x10) ^ 0x100000;
        }
      }
      if ((*(uint *)(pSVar2 + 0x10) & 0x80000) != 0) {
        dVar10 = (double)JAudio::_831;
        fVar1 = JAudio::_931;
        for (bVar7 = 0; dVar9 = (double)fVar1, bVar7 < 7; bVar7 = bVar7 + 1) {
          pMVar6 = (MoveParaSet *)(*(int *)(iVar3 + 0x158) + (uint)bVar7 * 0x10);
          if (((*(uint *)(iVar3 + 0x10) & 1 << (uint)bVar7) != 0) &&
             (iVar4 = MoveParaSet::move(pMVar6), iVar4 == 0)) {
            *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) ^ 1 << (uint)bVar7;
          }
          fVar1 = (float)(dVar9 + (double)(float)((double)*(float *)(pMVar6 + 4) - dVar10));
        }
        dVar9 = (double)(float)(dVar9 + (double)JAudio::_831);
        dVar10 = (double)JAudio::_830;
        if ((dVar9 <= dVar10) && (dVar10 = dVar9, dVar9 < (double)JAudio::_931)) {
          dVar10 = (double)JAudio::_931;
        }
        if ((double)*(float *)(_streamUpdate + 0xc) != dVar10) {
          StreamLib::setPan(_streamUpdate,(float)dVar10);
          *(float *)(_streamUpdate + 0xc) = (float)dVar10;
        }
        if (*(int *)(iVar3 + 0x10) == 0) {
          *(uint *)(pSVar2 + 0x10) = *(uint *)(pSVar2 + 0x10) ^ 0x80000;
        }
      }
      this = (StreamMgr *)this_01->field_0x18;
      this_01->field_0x18 = (uint)(this + 1);
    }
  }
LAB_8029c708:
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  return this;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall StreamLib::Play_DirectPCM(JASystem::TDSPChannel *,
                                                 short *,
                                                 unsigned short,
                                                 unsigned long,
                                                 short,
                                                 unsigned short) */

void __thiscall
StreamLib::Play_DirectPCM
          (StreamLib *this,TDSPChannel *param_1,short *param_2,ushort param_3,ulong param_4,
          short param_5,ushort param_6)

{
  int iVar1;
  DSPBuffer *pDVar2;
  undefined4 extraout_r4;
  uchar extraout_r4_01;
  uchar extraout_r4_02;
  uchar uVar4;
  undefined4 extraout_r4_00;
  undefined4 uVar3;
  undefined2 in_register_00000018;
  byte bVar5;
  
  iVar1 = JASystem::DSPInterface::getDSPHandle((DSPInterface *)(uint)(byte)*this,(uchar)param_1);
  *(TDSPChannel **)(iVar1 + 0x118) = param_1;
  *(undefined2 *)(iVar1 + 0x102) = 0;
  *(undefined2 *)(iVar1 + 0x100) = 0x21;
  if (DAT_803ed120 == 0) {
    *(uint *)(iVar1 + 0x74) = CONCAT22(in_register_00000018,param_3);
  }
  else {
    *(undefined4 *)(iVar1 + 0x74) = 0xffffffff;
  }
  *(TDSPChannel **)(iVar1 + 0x110) = param_1;
  *(int *)(iVar1 + 0x114) = (int)param_2 << 0x10;
  pDVar2 = (DSPBuffer *)
           JASystem::DSPInterface::getDSPHandle((DSPInterface *)(uint)(byte)*this,'\x10');
  JASystem::DSPInterface::DSPBuffer::setMixerInitDelayMax(pDVar2,'\0');
  uVar3 = extraout_r4;
  for (bVar5 = 0; uVar4 = (uchar)uVar3, bVar5 < 6; bVar5 = bVar5 + 1) {
    if (bVar5 < 2) {
      pDVar2 = (DSPBuffer *)
               JASystem::DSPInterface::getDSPHandle((DSPInterface *)(uint)(byte)*this,uVar4);
      JASystem::DSPInterface::DSPBuffer::setMixerInitVolume(pDVar2,bVar5,(short)param_4,'\0');
      uVar4 = extraout_r4_01;
    }
    else {
      pDVar2 = (DSPBuffer *)
               JASystem::DSPInterface::getDSPHandle((DSPInterface *)(uint)(byte)*this,uVar4);
      JASystem::DSPInterface::DSPBuffer::setMixerInitVolume(pDVar2,bVar5,0,'\0');
      uVar4 = extraout_r4_02;
    }
    pDVar2 = (DSPBuffer *)
             JASystem::DSPInterface::getDSPHandle((DSPInterface *)(uint)(byte)*this,uVar4);
    JASystem::DSPInterface::DSPBuffer::setBusConnect(pDVar2,bVar5,bVar5 + 1);
    uVar3 = extraout_r4_00;
  }
  pDVar2 = (DSPBuffer *)
           JASystem::DSPInterface::getDSPHandle((DSPInterface *)(uint)(byte)*this,uVar4);
  JASystem::DSPInterface::DSPBuffer::setPitch(pDVar2,param_5);
  JASystem::TDSPChannel::play((TDSPChannel *)this);
  return;
}


/* __thiscall StreamLib::Get_DirectPCM_LoopRemain(JASystem::DSPInterface::DSPBuffer *) */

uint __thiscall StreamLib::Get_DirectPCM_LoopRemain(StreamLib *this,DSPBuffer *param_1)

{
  return *(uint *)(this + 0x6c) >> 0x10;
}


/* __thiscall StreamLib::Get_DirectPCM_Remain(JASystem::DSPInterface::DSPBuffer *) */

undefined4 __thiscall StreamLib::Get_DirectPCM_Remain(StreamLib *this,DSPBuffer *param_1)

{
  return *(undefined4 *)(this + 0x74);
}


/* __thiscall StreamLib::init(bool) */

int __thiscall StreamLib::init(StreamLib *this,EVP_PKEY_CTX *ctx)

{
  void *size;
  StreamLib *this_00;
  long lVar1;
  
  bufferMode = SUB41(this,0);
  if (((uint)this & 0xff) == 0) {
    size = (void *)getNeedBufferSize(this);
    lVar1 = 0;
    this_00 = (StreamLib *)JKRHeap::alloc(JAudio::JASDram,(ulong)size,0);
    this = (StreamLib *)allocBuffer(this_00,size,lVar1);
  }
  return (int)this;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::allocBuffer(void *,
                                              long) */

void __thiscall StreamLib::allocBuffer(StreamLib *this,void *param_1,long param_2)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if (allocFlag == '\0') {
    JASystem::Kernel::TSolidHeap::init((TSolidHeap *)&streamHeap,(EVP_PKEY_CTX *)this);
    _loop_buffer = JASystem::Kernel::TSolidHeap::alloc((TSolidHeap *)&streamHeap,8);
    if ((_loop_buffer == 0) && (_loop_buffer == 0)) {
      JUTAssertion::showAssert(3,"JAIStreamMgr.cpp",0x22b,"loop_buffer");
      m_Do_printf::OSPanic("JAIStreamMgr.cpp",0x22b,&DAT_80369ef2);
    }
    uVar6 = 0;
    iVar5 = 0;
    do {
      uVar2 = JASystem::Kernel::TSolidHeap::alloc((TSolidHeap *)&streamHeap,_LOOP_BLOCKS << 2);
      *(undefined4 *)(_loop_buffer + iVar5) = uVar2;
      bVar1 = *(int *)(_loop_buffer + iVar5) == 0;
      if ((bVar1) && (bVar1)) {
        JUTAssertion::showAssert(3,"JAIStreamMgr.cpp",0x22f,"loop_buffer[i]");
        m_Do_printf::OSPanic("JAIStreamMgr.cpp",0x22f,&DAT_80369ef2);
      }
      iVar4 = 0;
      for (uVar3 = 0; uVar3 < _LOOP_BLOCKS; uVar3 = uVar3 + 1) {
        uVar2 = JASystem::Kernel::TSolidHeap::alloc((TSolidHeap *)&streamHeap,0x2800);
        *(undefined4 *)(*(int *)(iVar5 + _loop_buffer) + iVar4) = uVar2;
        bVar1 = *(int *)(*(int *)(iVar5 + _loop_buffer) + iVar4) == 0;
        if ((bVar1) && (bVar1)) {
          JUTAssertion::showAssert(3,"JAIStreamMgr.cpp",0x233,"loop_buffer[i][j]");
          m_Do_printf::OSPanic("JAIStreamMgr.cpp",0x233,&DAT_80369ef2);
        }
        iVar4 = iVar4 + 4;
      }
      uVar6 = uVar6 + 1;
      iVar5 = iVar5 + 4;
    } while (uVar6 < 2);
    _store_buffer = JASystem::Kernel::TSolidHeap::alloc((TSolidHeap *)&streamHeap,8);
    if ((_store_buffer == 0) && (_store_buffer == 0)) {
      JUTAssertion::showAssert(3,"JAIStreamMgr.cpp",0x238,"store_buffer");
      m_Do_printf::OSPanic("JAIStreamMgr.cpp",0x238,&DAT_80369ef2);
    }
    uVar6 = 0;
    iVar5 = 0;
    do {
      uVar2 = JASystem::Kernel::TSolidHeap::alloc((TSolidHeap *)&streamHeap,0x5000);
      *(undefined4 *)(_store_buffer + iVar5) = uVar2;
      bVar1 = *(int *)(_store_buffer + iVar5) == 0;
      if ((bVar1) && (bVar1)) {
        JUTAssertion::showAssert(3,"JAIStreamMgr.cpp",0x23c,"store_buffer[i]");
        m_Do_printf::OSPanic("JAIStreamMgr.cpp",0x23c,&DAT_80369ef2);
      }
      uVar6 = uVar6 + 1;
      iVar5 = iVar5 + 4;
    } while (uVar6 < 2);
    if ((_loop_buffer == 0) && (_loop_buffer == 0)) {
      JUTAssertion::showAssert(3,"JAIStreamMgr.cpp",0x23f,"loop_buffer");
      m_Do_printf::OSPanic("JAIStreamMgr.cpp",0x23f,&DAT_80369ef2);
    }
    _adpcm_buffer = JASystem::Kernel::TSolidHeap::alloc((TSolidHeap *)&streamHeap,0x5000);
    if ((_adpcm_buffer == 0) && (_adpcm_buffer == 0)) {
      JUTAssertion::showAssert(3,"JAIStreamMgr.cpp",0x241,"adpcm_buffer");
      m_Do_printf::OSPanic("JAIStreamMgr.cpp",0x241,&DAT_80369ef2);
    }
    allocFlag = '\x01';
  }
  return;
}


/* __thiscall StreamLib::deallocBuffer(void) */

undefined4 __thiscall StreamLib::deallocBuffer(StreamLib *this)

{
  undefined4 uVar1;
  
  if (((bufferMode == '\0') || (allocFlag == '\0')) || (playflag2 == '\x01')) {
    uVar1 = 0;
  }
  else {
    JASystem::Kernel::TSolidHeap::freeAll((TSolidHeap *)&streamHeap);
    allocFlag = '\0';
    uVar1 = 1;
  }
  return uVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::getNeedBufferSize(void) */

int __thiscall StreamLib::getNeedBufferSize(StreamLib *this)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = 0;
  iVar1 = 0x20;
  do {
    iVar1 = iVar1 + (_LOOP_BLOCKS & 0x3ffffff8) * 4 + 0x20;
    uVar4 = _LOOP_BLOCKS;
    if (_LOOP_BLOCKS != 0) {
      do {
        iVar1 = iVar1 + 0x2820;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 2);
  iVar5 = 2;
  iVar1 = iVar1 + 0x20;
  do {
    iVar2 = iVar1;
    iVar5 = iVar5 + -1;
    iVar1 = iVar2 + 0x5020;
  } while (iVar5 != 0);
  return iVar2 + 0xa040;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::setAllocBufferCallback(void *(void)) */

void __thiscall StreamLib::setAllocBufferCallback(StreamLib *this,FuncDef579 *param_1)

{
  _allocCallback = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::setDeallocBufferCallback(void *(void)) */

void __thiscall StreamLib::setDeallocBufferCallback(StreamLib *this,FuncDef580 *param_1)

{
  _deallocCallback = this;
  return;
}


/* __thiscall StreamLib::sync(long) */

void __thiscall StreamLib::sync(StreamLib *this)

{
  if (JAudio::init_1184 == '\0') {
    JAudio::init_1184 = '\x01';
  }
  JAudio::before_1183 = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::__DecodePCM(void) */

void __thiscall StreamLib::__DecodePCM(StreamLib *this)

{
  uint uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  
  puVar2 = *(undefined2 **)(*_loop_buffer + _playside * 4);
  puVar3 = *(undefined2 **)(_loop_buffer[1] + _playside * 4);
  uVar1 = 0;
  puVar4 = _adpcm_buffer;
  while( true ) {
    if (_loadsize >> 2 <= uVar1) break;
    *puVar2 = *puVar4;
    *puVar3 = puVar4[1];
    puVar3 = puVar3 + 1;
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 2;
  }
  _loadup_samples = _loadup_samples + (_loadsize >> 2);
  os::DCStoreRange(*(undefined4 *)(*_loop_buffer + _playside * 4),_loadsize >> 1);
  os::DCStoreRange(*(undefined4 *)(_loop_buffer[1] + _playside * 4),_loadsize >> 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::__DecodeADPCM(void) */

void __thiscall StreamLib::__DecodeADPCM(StreamLib *this)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  short sVar4;
  byte *pbVar5;
  uint uVar6;
  short *psVar7;
  short *psVar8;
  byte *pbVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  
  iVar10 = 0;
  if ((_movieframe == 0) && (_playside == 0)) {
    JAudio::R2_1212 = 0;
    JAudio::R1_1211 = 0;
    JAudio::L2_1210 = 0;
    JAudio::L1_1209 = 0;
  }
  psVar7 = *_store_buffer;
  psVar8 = _store_buffer[1];
  pbVar9 = _adpcm_buffer;
  if (_loop_start_flag != 0) {
    uVar6 = DAT_803ed124 >> 4 & 7;
    iVar10 = uVar6 * 0x12;
    _loadsize = uVar6 * -0x12 + 0x1680;
    pbVar9 = _adpcm_buffer + iVar10;
    _loop_start_flag = 0;
  }
  uVar6 = 0;
  while( true ) {
    if (_loadsize / 0x12 <= uVar6) break;
    bVar2 = *pbVar9 >> 4;
    iVar12 = (*pbVar9 & 0xf) * 4;
    sVar3 = *(short *)(&filter_table + iVar12);
    sVar4 = *(short *)(&DAT_8039b20a + iVar12);
    iVar12 = 8;
    pbVar5 = pbVar9 + 1;
    do {
      pbVar9 = pbVar5;
      bVar1 = *pbVar9;
      JAudio::L2_1210 =
           (short)((int)*(short *)(&table4 + ((int)(uint)bVar1 >> 4) * 2) << bVar2) +
           (short)((int)sVar3 * (int)JAudio::L1_1209 + (int)sVar4 * (int)JAudio::L2_1210 >> 0xb);
      *psVar7 = JAudio::L2_1210;
      JAudio::L1_1209 =
           (short)((int)*(short *)(&table4 + (bVar1 & 0xf) * 2) << bVar2) +
           (short)((int)sVar3 * (int)JAudio::L2_1210 + (int)sVar4 * (int)JAudio::L1_1209 >> 0xb);
      psVar7[1] = JAudio::L1_1209;
      psVar7 = psVar7 + 2;
      iVar12 = iVar12 + -1;
      pbVar5 = pbVar9 + 1;
    } while (iVar12 != 0);
    bVar2 = pbVar9[1];
    bVar1 = bVar2 >> 4;
    iVar12 = (bVar2 & 0xf) * 4;
    sVar3 = *(short *)(&filter_table + iVar12);
    sVar4 = *(short *)(&DAT_8039b20a + iVar12);
    iVar12 = 8;
    pbVar9 = pbVar9 + 2;
    do {
      bVar2 = *pbVar9;
      JAudio::R2_1212 =
           (short)((int)*(short *)(&table4 + ((int)(uint)bVar2 >> 4) * 2) << bVar1) +
           (short)((int)sVar3 * (int)JAudio::R1_1211 + (int)sVar4 * (int)JAudio::R2_1212 >> 0xb);
      *psVar8 = JAudio::R2_1212;
      JAudio::R1_1211 =
           (short)((int)*(short *)(&table4 + (bVar2 & 0xf) * 2) << bVar1) +
           (short)((int)sVar3 * (int)JAudio::R2_1212 + (int)sVar4 * (int)JAudio::R1_1211 >> 0xb);
      psVar8[1] = JAudio::R1_1211;
      pbVar9 = pbVar9 + 1;
      psVar8 = psVar8 + 2;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    uVar6 = uVar6 + 1;
  }
  _loadup_samples = _loadup_samples + ((_loadsize - iVar10) / 0x12 & 0x7ffffff) * 0x10;
  iVar10 = 0;
  for (uVar6 = 0; uVar6 < _loadsize / 0x12 << 4; uVar6 = uVar6 + 1) {
    uVar11 = uVar6 + _shift_sample;
    if (uVar11 == 0x1400) {
      os::DCStoreRange(*(int *)(*_loop_buffer + _playside * 4) + _shift_sample * 2,
                       (0x1400 - _shift_sample) * 2);
      os::DCStoreRange(*(int *)(_loop_buffer[1] + _playside * 4) + _shift_sample * 2,
                       (0x1400 - _shift_sample) * 2);
      _playside = (_playside + 1U) - ((_playside + 1U) / _LOOP_BLOCKS) * _LOOP_BLOCKS;
    }
    if (0x13ff < uVar11) {
      uVar11 = uVar11 - 0x1400;
    }
    *(undefined2 *)(*(int *)(*_loop_buffer + _playside * 4) + uVar11 * 2) =
         *(undefined2 *)((int)*_store_buffer + iVar10);
    *(undefined2 *)(*(int *)(_loop_buffer[1] + _playside * 4) + uVar11 * 2) =
         *(undefined2 *)((int)_store_buffer[1] + iVar10);
    iVar10 = iVar10 + 2;
  }
  uVar6 = uVar6 + _shift_sample;
  os::DCStoreRange(*(undefined4 *)(*_loop_buffer + _playside * 4),0x2800);
  os::DCStoreRange(*(undefined4 *)(_loop_buffer[1] + _playside * 4),0x2800);
  if (uVar6 == 0x1400) {
    _playside = (_playside + 1U) - ((_playside + 1U) / _LOOP_BLOCKS) * _LOOP_BLOCKS;
  }
  if (uVar6 < 0x1400) {
    _shift_sample = uVar6;
    if (0x1400 < uVar6) {
      _shift_sample = uVar6 - 0x1400;
    }
  }
  else {
    _shift_sample = uVar6 - 0x1400;
  }
  return;
}


/* __thiscall StreamLib::__Decode(void) */

void __thiscall StreamLib::__Decode(StreamLib *this)

{
  if (DAT_803ed11a != 3) {
    if (DAT_803ed11a < 3) {
      if (1 < DAT_803ed11a) {
        __DecodePCM((StreamLib *)&header);
        return;
      }
    }
    else {
      if (DAT_803ed11a < 5) {
        __DecodeADPCM((StreamLib *)&header);
        return;
      }
    }
  }
  JUTAssertion::showAssert(3,"JAIStreamMgr.cpp",0x3b4,"0");
  m_Do_printf::OSPanic("JAIStreamMgr.cpp",0x3b4,&DAT_80369ef2);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::__LoadFin(long,
                                            DVDFileInfo *) */

void __thiscall StreamLib::__LoadFin(StreamLib *this,long param_1,DVDFileInfo *param_2)

{
  if (_adpcmbuf_state == 3) {
    _DvdLoadFlag = 0;
    return;
  }
  _adpcmbuf_state = 2;
  _DvdLoadFlag = 0;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::LoadADPCM(void) */

StreamLib * __thiscall StreamLib::LoadADPCM(StreamLib *this)

{
  bool bVar1;
  
  if (_adpcmbuf_state != 0) {
    return this;
  }
  if (DAT_803ed11a != 3) {
    if (DAT_803ed11a < 3) {
      if (1 < DAT_803ed11a) {
        _loadsize = 0x5000;
        goto LAB_8029d280;
      }
    }
    else {
      if (DAT_803ed11a < 5) {
        _loadsize = 0x1680;
        goto LAB_8029d280;
      }
    }
  }
  JUTAssertion::showAssert(3,"JAIStreamMgr.cpp",0x3e0,"0");
  m_Do_printf::OSPanic("JAIStreamMgr.cpp",0x3e0,&DAT_80369ef2);
LAB_8029d280:
  _extra_sample = 0;
  if (_adpcm_remain < _loadsize) {
    if ((_adpcm_remain & 0x1f) == 0) {
      _loadsize = _adpcm_remain;
    }
    else {
      _loadsize = _adpcm_remain + (0x20 - (_adpcm_remain & 0x1f));
      _extra_sample = _loadsize - _adpcm_remain;
    }
  }
  _adpcmbuf_state = 1;
  dvd::DVDReadAsyncPrio(&finfo,_adpcm_buffer,_loadsize,_adpcm_loadpoint,__LoadFin,2);
  bVar1 = _adpcm_remain < _loadsize;
  _adpcm_remain = _adpcm_remain - _loadsize & ~(uint)(StreamLib *)-(uint)bVar1;
  _adpcm_loadpoint = _adpcm_loadpoint + _loadsize;
  _DvdLoadFlag = 1;
  return (StreamLib *)-(uint)bVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::setVolume(float) */

void __thiscall StreamLib::setVolume(StreamLib *this,float param_1)

{
  _stackvolume = param_1;
  outflag_volume = 1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::setPitch(float) */

void __thiscall StreamLib::setPitch(StreamLib *this,float param_1)

{
  _stackpitch = param_1;
  outflag_pitch = 1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::setPan(float) */

void __thiscall StreamLib::setPan(StreamLib *this,float param_1)

{
  _stackpan = param_1;
  outflag_pan = 1;
  return;
}


/* __thiscall StreamLib::stop(void) */

void __thiscall StreamLib::stop(StreamLib *this)

{
  stopflag = 1;
  stopflag2 = 1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::setPauseFlag(unsigned char) */

void __thiscall StreamLib::setPauseFlag(StreamLib *this,uchar param_1)

{
  _outpause = _outpause | (uint)this & 0xff | 0x80;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::clearPauseFlag(unsigned char) */

void __thiscall StreamLib::clearPauseFlag(StreamLib *this,uchar param_1)

{
  _outpause = _outpause & ((uint)this & 0xff ^ 0xff) | 0x80;
  return;
}


/* __thiscall StreamLib::setPrepareFlag(unsigned char) */

void __thiscall StreamLib::setPrepareFlag(StreamLib *this,uchar param_1)

{
  prepareflag = (char)this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::setOutputMode(unsigned long) */

void __thiscall StreamLib::setOutputMode(StreamLib *this,ulong param_1)

{
  _outputmode = this;
  return;
}


/* __thiscall StreamLib::getPlayingFlag(void) */

undefined __thiscall StreamLib::getPlayingFlag(StreamLib *this)

{
  return playflag2;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::setDecodedBufferBlocks(unsigned long) */

void __thiscall StreamLib::setDecodedBufferBlocks(StreamLib *this,ulong param_1)

{
  if ((StreamLib *)&DAT_00000002 < this) {
    if ((StreamLib *)&DAT_0000000c < this) {
      m_Do_printf::OSReport
                (
                "setDecodedBufferBlocks : 13ブロック以上は設定できませんので、使用ブロックを%dから12に変更します。\n"
                );
      this = (StreamLib *)&DAT_0000000c;
    }
  }
  else {
    m_Do_printf::OSReport
              (
              "setDecodedBufferBlocks : 3ブロック以上必要ですので、使用ブロックを%dから3に変更します。\n"
              );
    this = (StreamLib *)&DAT_00000003;
  }
  _LOOP_BLOCKS = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::LoopInit(void) */

void __thiscall StreamLib::LoopInit(StreamLib *this)

{
  uint uVar1;
  
  uVar1 = DAT_803ed124 - (DAT_803ed124 & 0x7f) >> 4;
  _adpcm_remain = _header + uVar1 * -0x12;
  _adpcm_loadpoint = uVar1 * 0x12 + 0x20;
  _loop_start_flag = 1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::directPlayWait(void *) */

undefined4 __thiscall StreamLib::directPlayWait(StreamLib *this,void *param_1)

{
  char cVar2;
  undefined4 uVar1;
  void *in_r5;
  
  cVar2 = getPlayingFlag(this);
  if (cVar2 == '\x01') {
    uVar1 = 0;
  }
  else {
    _startInitFlag = _startInitFlag + 1;
    prepareflag = 0;
    JASystem::Kernel::registerDspCallback((Kernel *)callBack,(FuncDef571 *)0x0,in_r5);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::start(char *,
                                        unsigned long,
                                        void *) */

void __thiscall StreamLib::start(StreamLib *this,char *param_1,ulong param_2,void *param_3)

{
  StreamLib *this_00;
  void *pvVar1;
  
  if (_startInitFlag == 0) {
    pvVar1 = (void *)param_2;
    this_00 = (StreamLib *)MSL_C.PPCEABI.bare.H::strcpy(&Filename,(char *)this);
    _Mode = param_1;
    _Head = param_2;
    if (param_2 == 0) {
      stop(this_00);
      JASystem::Kernel::registerDspCallback((Kernel *)directPlayWait,(FuncDef571 *)0x0,pvVar1);
    }
    else {
      _startInitFlag = _startInitFlag + 1;
      prepareflag = 0;
      JASystem::Kernel::registerDspCallback((Kernel *)callBack,(FuncDef571 *)0x0,pvVar1);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::__start(void) */

void __thiscall StreamLib::__start(StreamLib *this)

{
  TDSPChannel *this_00;
  uint uVar1;
  TDSPChannel **__ptr;
  int iVar2;
  int iVar3;
  
  _startInitFlag = 0;
  if (bufferMode == '\x01') {
    if ((allocFlag == '\0') && (_allocCallback != (code *)0x0)) {
      (*_allocCallback)();
    }
    if ((allocFlag == '\0') && (allocFlag == '\0')) {
      JUTAssertion::showAssert(3,"JAIStreamMgr.cpp",0x4c1,"allocFlag");
      m_Do_printf::OSPanic("JAIStreamMgr.cpp",0x4c1,&DAT_80369ef2);
    }
  }
  _playmode = _Mode;
  _sFillBlockSize = 0;
  if (playflag != '\0') {
    JASystem::TDSPChannel::forceStop(_assign_ch);
    JASystem::TDSPChannel::forceStop(pTRam803f7674);
    playflag = playflag + '\x01';
  }
  dvd::DVDOpen(&Filename,(int)&finfo);
  if (_Head == 0) {
    dvd::DVDReadPrio(&finfo,_adpcm_buffer,0x20,0,2);
  }
  else {
    iVar2 = 0;
    iVar3 = 0x20;
    do {
      *(undefined *)((int)_adpcm_buffer + iVar2) = *(undefined *)(iVar2 + _Head);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  _adpcm_loadpoint = 0x20;
  _header = *_adpcm_buffer;
  DAT_803ed114 = _adpcm_buffer[1];
  DAT_803ed118 = *(undefined2 *)(_adpcm_buffer + 2);
  DAT_803ed11a = *(undefined2 *)((int)_adpcm_buffer + 10);
  DAT_803ed11c = *(undefined2 *)(_adpcm_buffer + 3);
  DAT_803ed11e = *(undefined2 *)((int)_adpcm_buffer + 0xe);
  DAT_803ed120 = _adpcm_buffer[4];
  DAT_803ed124 = _adpcm_buffer[5];
  DAT_803ed128 = (StreamLib *)_adpcm_buffer[6];
  DAT_803ed12c = _adpcm_buffer[7];
  if (_playmode != 0) {
    DAT_803ed120 = 0;
  }
  stopflag = 0;
  stopflag2 = 0;
  playflag2 = 0;
  _outvolume = JAudio::_830;
  _outpitch = JAudio::_830;
  _outpan = JAudio::_831;
  _loadup_samples = 0;
  _movieframe = 0;
  _loop_start_flag = 0;
  _adpcmbuf_state = 0;
  _playside = 0;
  _shift_sample = 0;
  dspFinishFlag = 0;
  _LOOP_SAMPLESIZE = _LOOP_BLOCKS * 0x1400;
  _adpcm_remain = _header;
  _playback_samples = DAT_803ed114;
  LoadADPCM(DAT_803ed128);
  uVar1 = 0;
  iVar2 = 0;
  do {
    __ptr = (TDSPChannel **)(&assign_ch + iVar2);
    this_00 = *__ptr;
    if ((this_00 != (TDSPChannel *)0x0) && (*(int *)(this_00 + 8) != 0)) {
      JASystem::TDSPChannel::free(this_00,__ptr);
    }
    *__ptr = (TDSPChannel *)0x0;
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 4;
  } while (uVar1 < 2);
  dspch_deallockflag = 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x8029e124) */
/* WARNING: Removing unreachable block (ram,0x8029e12c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall StreamLib::callBack(void *) */

undefined4 __thiscall StreamLib::callBack(StreamLib *this,void *param_1)

{
  int iVar1;
  float fVar2;
  TDSPChannel *pTVar3;
  short sVar4;
  undefined4 uVar5;
  ulong uVar6;
  int iVar7;
  DSPBuffer *pDVar8;
  uint uVar9;
  StreamLib *pSVar10;
  uchar extraout_r4_01;
  uchar extraout_r4_02;
  uchar extraout_r4_03;
  uchar extraout_r4_04;
  uchar extraout_r4_05;
  uchar extraout_r4_06;
  StreamLib *pSVar11;
  StreamLib *extraout_r4;
  StreamLib *extraout_r4_00;
  uchar extraout_r4_07;
  uchar extraout_r4_08;
  uchar uVar12;
  uchar extraout_r4_09;
  uchar extraout_r4_10;
  uchar extraout_r4_11;
  uchar extraout_r4_12;
  uchar extraout_r4_13;
  uchar extraout_r4_14;
  uchar extraout_r4_15;
  uchar extraout_r4_16;
  uchar extraout_r4_17;
  ulong in_r5;
  StreamLib *pSVar13;
  ushort in_r9;
  int unaff_r30;
  undefined4 uVar14;
  double dVar15;
  double dVar16;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined8 uVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  Calc *local_88;
  float local_84;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  undefined4 local_60;
  uint uStack92;
  longlong local_58;
  undefined4 local_50;
  uint uStack76;
  longlong local_48;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar17 = CONCAT44(this,param_1);
  uVar14 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (_startInitFlag != 0) {
    if (_DvdLoadFlag != 0) {
      uVar5 = 0;
      goto LAB_8029e124;
    }
    uVar17 = __start(this);
  }
  if (_startInitFlag == 0) {
    if (outflag_volume != '\0') {
      _outvolume = _stackvolume;
      outflag_volume = '\0';
    }
    if (outflag_pitch != '\0') {
      _outpitch = _stackpitch;
      outflag_pitch = '\0';
    }
    if (outflag_pan != '\0') {
      _outpan = _stackpan;
      outflag_pan = '\0';
    }
  }
  if (_assign_ch == (TDSPChannel *)0x0) {
    _assign_ch = (TDSPChannel *)
                 JASystem::TDSPChannel::alloc((TDSPChannel *)0x0,(ulong)&assign_ch,in_r5);
    pTRam803f7674 = (TDSPChannel *)JASystem::TDSPChannel::alloc((TDSPChannel *)0x0,0x803f7674,in_r5)
    ;
    pTVar3 = _assign_ch;
    uVar17 = CONCAT44(pTRam803f7674,_assign_ch);
    if ((_assign_ch != (TDSPChannel *)0x0) &&
       (uVar17 = CONCAT44(pTRam803f7674,_assign_ch), pTRam803f7674 != (TDSPChannel *)0x0)) {
      _assign_ch[3] = (TDSPChannel)0x7f;
      uVar17 = CONCAT44(pTRam803f7674,pTVar3);
      pTRam803f7674[3] = (TDSPChannel)0x7f;
    }
  }
  if ((_assign_ch == (TDSPChannel *)0x0) || (pTRam803f7674 == (TDSPChannel *)0x0)) {
    uVar6 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f
              (uVar6,"JAIStreamMgr.cpp",0x57b,"%s",
               (___)"JAIStream::callBack チャンネルが確保できないor無くなった！\n"
              );
    sync((StreamLib *)&DAT_ffffffff);
    playflag = 0;
    playflag2 = 2;
    uVar5 = 0xffffffff;
  }
  else {
    if (JAudio::init_1492 == '\0') {
      JAudio::oldstat_1491 = 0;
      JAudio::init_1492 = '\x01';
    }
    iVar7 = dvd::DVDGetDriveStatus((int)((ulonglong)uVar17 >> 0x20),(int)uVar17);
    if (iVar7 == 5) {
      _outpause = (StreamLib *)((uint)_outpause | 0x88);
    }
    else {
      if (((iVar7 < 5) && (iVar7 == 0)) &&
         (uVar9 = dvd::DVDGetDriveStatus(), JAudio::oldstat_1491 != uVar9)) {
        _outpause = (StreamLib *)((uint)_outpause & 0xf7 | 0x80);
      }
    }
    uVar18 = dvd::DVDGetDriveStatus();
    JAudio::oldstat_1491 = (uint)(uVar18 >> 0x20);
    pSVar10 = _outpause;
    if (((uint)_outpause & 0x80) != 0) {
      if (((uint)_outpause & 0x7f) != 0) {
        pDVar8 = (DSPBuffer *)
                 JASystem::DSPInterface::getDSPHandle
                           ((DSPInterface *)(uint)(byte)*_assign_ch,(uchar)uVar18);
        JASystem::DSPInterface::DSPBuffer::setPauseFlag(pDVar8,'\x01');
        pDVar8 = (DSPBuffer *)
                 JASystem::DSPInterface::getDSPHandle
                           ((DSPInterface *)(uint)(byte)*pTRam803f7674,extraout_r4_01);
        JASystem::DSPInterface::DSPBuffer::setPauseFlag(pDVar8,'\x01');
        pDVar8 = (DSPBuffer *)
                 JASystem::DSPInterface::getDSPHandle
                           ((DSPInterface *)(uint)(byte)*_assign_ch,extraout_r4_02);
        JASystem::DSPInterface::DSPBuffer::flushChannel(pDVar8);
        pDVar8 = (DSPBuffer *)
                 JASystem::DSPInterface::getDSPHandle
                           ((DSPInterface *)(uint)(byte)*pTRam803f7674,extraout_r4_03);
        JASystem::DSPInterface::DSPBuffer::flushChannel(pDVar8);
        uVar5 = 0;
        goto LAB_8029e124;
      }
      pDVar8 = (DSPBuffer *)
               JASystem::DSPInterface::getDSPHandle
                         ((DSPInterface *)(uint)(byte)*_assign_ch,(uchar)uVar18);
      JASystem::DSPInterface::DSPBuffer::setPauseFlag(pDVar8,'\0');
      pDVar8 = (DSPBuffer *)
               JASystem::DSPInterface::getDSPHandle
                         ((DSPInterface *)(uint)(byte)*pTRam803f7674,extraout_r4_04);
      JASystem::DSPInterface::DSPBuffer::setPauseFlag(pDVar8,'\0');
      pDVar8 = (DSPBuffer *)
               JASystem::DSPInterface::getDSPHandle
                         ((DSPInterface *)(uint)(byte)*_assign_ch,extraout_r4_05);
      JASystem::DSPInterface::DSPBuffer::flushChannel(pDVar8);
      pDVar8 = (DSPBuffer *)
               JASystem::DSPInterface::getDSPHandle
                         ((DSPInterface *)(uint)(byte)*pTRam803f7674,extraout_r4_06);
      uVar18 = JASystem::DSPInterface::DSPBuffer::flushChannel(pDVar8);
      pSVar10 = (StreamLib *)(uVar18 >> 0x20);
      uVar18 = uVar18 & 0xffffffff | (ulonglong)JAudio::oldstat_1491 << 0x20;
    }
    JAudio::oldstat_1491 = (uint)(uVar18 >> 0x20);
    if (_movieframe != 0) {
      uVar17 = JASystem::DSPInterface::getDSPHandle
                         ((DSPInterface *)(uint)(byte)*_assign_ch,(uchar)uVar18);
      pSVar10 = (StreamLib *)((ulonglong)uVar17 >> 0x20);
      if ((*(short *)(pSVar10 + 2) != 0) || (dspFinishFlag != '\0')) {
        if (_adpcmbuf_state == 1) {
          dspFinishFlag = '\x01';
          uVar5 = 0;
        }
        else {
          JASystem::TDSPChannel::free(_assign_ch,&assign_ch);
          JASystem::TDSPChannel::free(pTRam803f7674,(void *)0x803f7674);
          _assign_ch = (TDSPChannel *)0x0;
          pTRam803f7674 = (TDSPChannel *)0x0;
          sync((StreamLib *)&DAT_ffffffff);
          playflag = 0;
          playflag2 = 2;
          if ((bufferMode == '\x01') && (_deallocCallback != (code *)0x0)) {
            (*_deallocCallback)();
          }
          uVar5 = 0xffffffff;
        }
        goto LAB_8029e124;
      }
      iVar7 = Get_DirectPCM_Remain(pSVar10,(DSPBuffer *)uVar17);
      pDVar8 = (DSPBuffer *)&header;
      sync((StreamLib *)(((_playback_samples - iVar7) * (uint)DAT_803ed11e) / (uint)DAT_803ed118));
      _movieframe = _movieframe + 1;
      uVar9 = Get_DirectPCM_LoopRemain(pSVar10,pDVar8);
      pSVar13 = (StreamLib *)((_LOOP_SAMPLESIZE - (uVar9 & 0xffff)) / 0x1400);
      if (JAudio::init_1516 == '\0') {
        JAudio::old_dspside_1515 = (StreamLib *)0x0;
        JAudio::init_1516 = '\x01';
      }
      _sFillBlockSize = (int)_playside - (int)pSVar13;
      if (_playside < pSVar13) {
        _sFillBlockSize = (int)((int)_playside + (int)_LOOP_BLOCKS) - (int)pSVar13;
      }
      if (JAudio::old_dspside_1515 != pSVar13) {
        JAudio::old_dspside_1515 = pSVar13;
      }
      pSVar11 = _playside + 1;
      uVar18 = CONCAT44(JAudio::oldstat_1491,pSVar11);
      pSVar10 = _LOOP_BLOCKS;
      if (pSVar13 == pSVar11 + -(((uint)pSVar11 / (uint)_LOOP_BLOCKS) * (int)_LOOP_BLOCKS)) {
        unaff_r30 = 0;
      }
      else {
        unaff_r30 = 1;
        uVar18 = CONCAT44(JAudio::oldstat_1491,pSVar11);
      }
    }
    JAudio::oldstat_1491 = (uint)(uVar18 >> 0x20);
    if ((stopflag != '\0') && (stopflag2 != '\0')) {
      if (_movieframe == 0) {
        if (_adpcmbuf_state == 1) {
          uVar5 = 0;
        }
        else {
          JASystem::TDSPChannel::free(_assign_ch,&assign_ch);
          JASystem::TDSPChannel::free(pTRam803f7674,(void *)0x803f7674);
          _assign_ch = (TDSPChannel *)0x0;
          pTRam803f7674 = (TDSPChannel *)0x0;
          sync((StreamLib *)&DAT_ffffffff);
          playflag = 0;
          playflag2 = 2;
          if ((bufferMode == '\x01') && (_deallocCallback != (code *)0x0)) {
            (*_deallocCallback)();
          }
          uVar5 = 0xffffffff;
        }
        goto LAB_8029e124;
      }
      stopflag2 = '\0';
      JASystem::TDSPChannel::forceStop(_assign_ch);
      uVar18 = JASystem::TDSPChannel::forceStop(pTRam803f7674);
      pSVar10 = (StreamLib *)(uVar18 >> 0x20);
      uVar18 = uVar18 & 0xffffffff | (ulonglong)JAudio::oldstat_1491 << 0x20;
    }
    JAudio::oldstat_1491 = (uint)(uVar18 >> 0x20);
    uVar19 = uVar18 & 0xffffffff | ZEXT48(pSVar10) << 0x20;
    if (((unaff_r30 == 1) || (_movieframe == 0)) &&
       ((_adpcmbuf_state == 2 || (_adpcmbuf_state == 4)))) {
      if (_adpcmbuf_state == 2) {
        uVar19 = __Decode(pSVar10);
        _adpcmbuf_state = 0;
      }
      pSVar10 = (StreamLib *)(Calc *)(uVar19 >> 0x20);
      uVar18 = uVar19 & 0xffffffff | (ulonglong)JAudio::oldstat_1491 << 0x20;
      if ((_movieframe == 0) &&
         (pSVar10 = _LOOP_BLOCKS, uVar18 = CONCAT44(JAudio::oldstat_1491,_playside),
         _playside == _LOOP_BLOCKS + -2)) {
        if (prepareflag != '\0') {
          prepareflag = '\x02';
          _adpcmbuf_state = 4;
          uVar5 = 0;
          goto LAB_8029e124;
        }
        prepareflag = '\x02';
        playflag2 = 1;
        _movieframe = 1;
        local_88 = JAudio::_1550;
        local_84 = DAT_803fc3f0;
        if (_outputmode == 1) {
          if (JAudio::_831 <= _outpan) {
            dVar15 = (double)JASystem::Calc::sinfT(JAudio::_1550,JAudio::_830 - _outpan);
            local_88 = (Calc *)(float)((double)JAudio::_1657 * dVar15);
            local_84 = JAudio::_830;
            pSVar13 = extraout_r4_00;
          }
          else {
            local_88 = (Calc *)JAudio::_830;
            dVar15 = (double)JASystem::Calc::sinfT(JAudio::_1550,_outpan);
            local_84 = (float)((double)JAudio::_1657 * dVar15);
            pSVar13 = extraout_r4;
          }
          sVar4 = 0x7fff;
        }
        else {
          sVar4 = 0x5a7e;
          pSVar13 = _playside;
        }
        uVar9 = 0;
        iVar7 = 0;
        dVar15 = JAudio::_1660;
        do {
          JASystem::DSPInterface::getDSPHandle
                    ((DSPInterface *)(uint)**(byte **)(&assign_ch + iVar7),(uchar)pSVar13);
          local_80 = (double)CONCAT44(0x43300000,(int)sVar4 ^ 0x80000000);
          uVar6 = (ulong)(_outvolume *
                         (float)(local_80 - dVar15) * *(float *)((int)&local_88 + iVar7));
          local_78 = (double)(longlong)(int)uVar6;
          local_70 = (double)CONCAT44(0x43300000,((uint)DAT_803ed118 << 0xc) / 32000 ^ 0x80000000);
          iVar1 = (int)(_outpitch * (float)(local_70 - dVar15));
          local_68 = (double)(longlong)iVar1;
          uVar19 = Play_DirectPCM(*(StreamLib **)(&assign_ch + iVar7),
                                  **(TDSPChannel ***)(_loop_buffer + iVar7),
                                  (short *)(_LOOP_SAMPLESIZE & 0xffff),(ushort)_playback_samples,
                                  uVar6,(short)iVar1,in_r9);
          pSVar10 = (StreamLib *)(Calc *)(uVar19 >> 0x20);
          pSVar13 = (StreamLib *)uVar19;
          uVar9 = uVar9 + 1;
          iVar7 = iVar7 + 4;
        } while (uVar9 < 2);
        uVar18 = uVar19 & 0xffffffff | (ulonglong)JAudio::oldstat_1491 << 0x20;
        if (_adpcmbuf_state != 3) {
          _adpcmbuf_state = 0;
          uVar18 = uVar19 & 0xffffffff | (ulonglong)JAudio::oldstat_1491 << 0x20;
        }
      }
    }
    JAudio::oldstat_1491 = (uint)(uVar18 >> 0x20);
    if (_movieframe != 0) {
      dVar15 = (double)JAudio::_830;
      if (_outputmode == 1) {
        if ((double)JAudio::_831 <= (double)_outpan) {
          dVar15 = (double)JASystem::Calc::sinfT((Calc *)pSVar10,(float)(dVar15 - (double)_outpan));
          dVar15 = (double)(float)((double)JAudio::_1657 * dVar15);
          fVar2 = JAudio::_830;
          uVar12 = extraout_r4_08;
        }
        else {
          dVar16 = (double)JASystem::Calc::sinfT((Calc *)pSVar10,_outpan);
          fVar2 = (float)((double)JAudio::_1657 * dVar16);
          uVar12 = extraout_r4_07;
        }
        dVar16 = (double)fVar2;
        uVar5 = 0x7fff;
        pDVar8 = (DSPBuffer *)
                 JASystem::DSPInterface::getDSPHandle
                           ((DSPInterface *)(uint)(byte)*_assign_ch,uVar12);
        JASystem::DSPInterface::DSPBuffer::setMixerVolume(pDVar8,'\x01',0,'\0');
        pDVar8 = (DSPBuffer *)
                 JASystem::DSPInterface::getDSPHandle
                           ((DSPInterface *)(uint)(byte)*pTRam803f7674,extraout_r4_09);
        JASystem::DSPInterface::DSPBuffer::setMixerVolume(pDVar8,'\0',0,'\0');
        uVar12 = extraout_r4_10;
      }
      else {
        uVar5 = 0x5a7e;
        fVar2 = JAudio::_1658 * _outvolume;
        local_68 = (double)(longlong)(int)fVar2;
        dVar16 = dVar15;
        pDVar8 = (DSPBuffer *)
                 JASystem::DSPInterface::getDSPHandle
                           ((DSPInterface *)(uint)(byte)*_assign_ch,(uchar)uVar18);
        JASystem::DSPInterface::DSPBuffer::setMixerVolume(pDVar8,'\x01',(short)(int)fVar2,'\0');
        fVar2 = JAudio::_1658 * _outvolume;
        local_70 = (double)(longlong)(int)fVar2;
        pDVar8 = (DSPBuffer *)
                 JASystem::DSPInterface::getDSPHandle
                           ((DSPInterface *)(uint)(byte)*pTRam803f7674,extraout_r4_11);
        JASystem::DSPInterface::DSPBuffer::setMixerVolume(pDVar8,'\0',(short)(int)fVar2,'\0');
        uVar12 = extraout_r4_12;
      }
      local_68 = (double)CONCAT44(0x43300000,uVar5);
      iVar7 = (int)(_outvolume * (float)((double)(float)(local_68 - JAudio::_1664) * dVar15));
      local_70 = (double)(longlong)iVar7;
      pDVar8 = (DSPBuffer *)
               JASystem::DSPInterface::getDSPHandle((DSPInterface *)(uint)(byte)*_assign_ch,uVar12);
      JASystem::DSPInterface::DSPBuffer::setMixerVolume(pDVar8,'\0',(short)iVar7,'\0');
      local_78 = (double)CONCAT44(0x43300000,uVar5);
      iVar7 = (int)(_outvolume * (float)((double)(float)(local_78 - JAudio::_1664) * dVar16));
      local_80 = (double)(longlong)iVar7;
      pDVar8 = (DSPBuffer *)
               JASystem::DSPInterface::getDSPHandle
                         ((DSPInterface *)(uint)(byte)*pTRam803f7674,extraout_r4_13);
      JASystem::DSPInterface::DSPBuffer::setMixerVolume(pDVar8,'\x01',(short)iVar7,'\0');
      uStack92 = ((uint)DAT_803ed118 << 0xc) / 32000 ^ 0x80000000;
      local_60 = 0x43300000;
      iVar7 = (int)(_outpitch * (float)((double)CONCAT44(0x43300000,uStack92) - JAudio::_1660));
      local_58 = (longlong)iVar7;
      pDVar8 = (DSPBuffer *)
               JASystem::DSPInterface::getDSPHandle
                         ((DSPInterface *)(uint)(byte)*_assign_ch,extraout_r4_14);
      JASystem::DSPInterface::DSPBuffer::setPitch(pDVar8,(ushort)iVar7);
      uStack76 = ((uint)DAT_803ed118 << 0xc) / 32000 ^ 0x80000000;
      local_50 = 0x43300000;
      iVar7 = (int)(_outpitch * (float)((double)CONCAT44(0x43300000,uStack76) - JAudio::_1660));
      local_48 = (longlong)iVar7;
      pDVar8 = (DSPBuffer *)
               JASystem::DSPInterface::getDSPHandle
                         ((DSPInterface *)(uint)(byte)*pTRam803f7674,extraout_r4_15);
      JASystem::DSPInterface::DSPBuffer::setPitch(pDVar8,(ushort)iVar7);
      pDVar8 = (DSPBuffer *)
               JASystem::DSPInterface::getDSPHandle
                         ((DSPInterface *)(uint)(byte)*_assign_ch,extraout_r4_16);
      JASystem::DSPInterface::DSPBuffer::flushChannel(pDVar8);
      pDVar8 = (DSPBuffer *)
               JASystem::DSPInterface::getDSPHandle
                         ((DSPInterface *)(uint)(byte)*pTRam803f7674,extraout_r4_17);
      pSVar10 = (StreamLib *)JASystem::DSPInterface::DSPBuffer::flushChannel(pDVar8);
    }
    if (_adpcmbuf_state == 0) {
      if (_adpcm_remain == 0) {
        if (DAT_803ed120 == 0) {
          _adpcmbuf_state = 3;
        }
        else {
          LoopInit((StreamLib *)&header);
        }
      }
      else {
        if (stopflag == '\0') {
          LoadADPCM(pSVar10);
        }
        else {
          _adpcmbuf_state = 3;
        }
      }
    }
    uVar5 = 0;
  }
LAB_8029e124:
  __psq_l0(auStack8,uVar14);
  __psq_l1(auStack8,uVar14);
  __psq_l0(auStack24,uVar14);
  __psq_l1(auStack24,uVar14);
  return uVar5;
}

}

namespace JAudio {

void __sinit_JAIStreamMgr_cpp(void)

{
  ::JASystem::Kernel::TSolidHeap::TSolidHeap((TSolidHeap *)&::JAInter::StreamLib::streamHeap);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

