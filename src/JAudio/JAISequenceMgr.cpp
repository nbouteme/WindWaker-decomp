#include <JAudio/JAISequenceMgr.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAudio/JAIGlobalParameter.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JAISound.h>
#include <JAudio/JAISeMgr.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JAudio/JAISequenceMgr.h>
#include <JAudio/JASTrack.h>
#include <JAudio/JASOuterParam.h>
#include <JAudio/JASCmdStack.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JAudio/JAIBasic.h>
#include <JAudio/JASResArcLoader.h>
#include <JAudio/JAISequenceHeap.h>
#include <JAudio/JAISystemInterface.h>
#include <mtx/mtxvec.h>
#include <JAInter/MuteBit.h>
#include <Demangler/JAIBasic.h>
#include <JAInter/SeqParameter.h>
#include <JAInter/PlayerParameter.h>
#include <JASystem/Kernel/TPortCmd.h>
#include <JAInter/SequenceMgr.h>
#include <Demangler/JAInter/SeqUpdateData.h>


namespace JAInter {
undefined1 SequenceMgr;
undefined1 SequenceMgr;
undefined1 SequenceMgr;
undefined1 SequenceMgr;

/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x80296078) */
/* WARNING: Removing unreachable block (ram,0x80296068) */
/* WARNING: Removing unreachable block (ram,0x80296070) */
/* WARNING: Removing unreachable block (ram,0x80296080) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::init(void) */

int __thiscall SequenceMgr::init(SequenceMgr *this,EVP_PKEY_CTX *ctx)

{
  int *piVar1;
  JKRHeap *pJVar2;
  float fVar3;
  undefined4 uVar4;
  EVP_PKEY_CTX *ctx_00;
  EVP_PKEY_CTX *this_00;
  int iVar5;
  JAIGlobalParameter *pJVar6;
  float *pfVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  JAIGlobalParameter *pJVar11;
  uint uVar12;
  JAIGlobalParameter *pJVar13;
  undefined4 uVar14;
  undefined8 in_f28;
  double dVar15;
  undefined8 in_f29;
  double dVar16;
  undefined8 in_f30;
  double dVar17;
  undefined8 in_f31;
  double dVar18;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  piVar1 = _msBasic;
  uVar14 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  uVar4 = JAIGlobalParameter::getParamSeqControlBufferMax((JAIGlobalParameter *)this);
  ctx_00 = (EVP_PKEY_CTX *)(**(code **)(*piVar1 + 8))(piVar1,uVar4);
  this_00 = ctx_00;
  if (ctx_00 == (EVP_PKEY_CTX *)0x0) {
    m_Do_printf::OSReport("JAISequenceMgr::initHeap Cannot Alloc Heap!!\n");
    JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",0x29,"soundObjects");
    this_00 = (EVP_PKEY_CTX *)m_Do_printf::OSPanic("JAISequenceMgr.cpp",0x29,&DAT_80369496);
  }
  if ((_msCurrentHeap == (JKRHeap *)0x0) &&
     (this_00 = (EVP_PKEY_CTX *)
                m_Do_printf::OSReport
                          (
                          "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                          ), _msCurrentHeap == (JKRHeap *)0x0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    this_00 = (EVP_PKEY_CTX *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369496);
  }
  pJVar2 = _msCurrentHeap;
  iVar5 = JAIGlobalParameter::getParamSeqPlayTrackMax((JAIGlobalParameter *)this_00);
  _FixSeqBufPointer = (JAIGlobalParameter *)JKernel::operator_new__(iVar5 << 2,pJVar2,0x20);
  JAIGlobalParameter::getParamSeqControlBufferMax(_FixSeqBufPointer);
  LinkSound::init((LinkSound *)&seqControl,ctx_00);
  iVar5 = 0;
  pJVar6 = (JAIGlobalParameter *)0x80290000;
  for (pJVar13 = (JAIGlobalParameter *)0x0;
      pJVar6 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeqControlBufferMax(pJVar6),
      pJVar13 < pJVar6; pJVar13 = pJVar13 + 1) {
    if ((_msCurrentHeap == (JKRHeap *)0x0) &&
       (m_Do_printf::OSReport
                  ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
       _msCurrentHeap == (JKRHeap *)0x0)) {
      JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
      m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369496);
    }
    pfVar7 = (float *)JKernel::operator_new(0x1718,_msCurrentHeap,0x20);
    fVar3 = JAudio::_885;
    if (pfVar7 == (float *)0x0) {
      m_Do_printf::OSReport("JAISequenceMgr::initHeap Cannot Alloc Heap!!\n");
      JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",0x2f,"_para");
      m_Do_printf::OSPanic("JAISequenceMgr.cpp",0x2f,&DAT_80369496);
    }
    else {
      pfVar7[1] = JAudio::_885;
      *pfVar7 = fVar3;
      pfVar7[3] = 0.0;
      Runtime.PPCEABI.H::__construct_array
                (pfVar7 + 4,MoveParaSet::__defctor,(undefined *)0x0,0x10,0x10);
      Runtime.PPCEABI.H::__construct_array
                (pfVar7 + 0x44,MoveParaSet::__defctor,(undefined *)0x0,0x10,0x14);
      Runtime.PPCEABI.H::__construct_array
                (pfVar7 + 0x98,MoveParaSet::__defctor,(undefined *)0x0,0x10,0x20);
      Runtime.PPCEABI.H::__construct_array
                (pfVar7 + 0x118,MoveParaSetInitHalf::MoveParaSetInitHalf,(undefined *)0x0,0x10,0x20)
      ;
      Runtime.PPCEABI.H::__construct_array
                (pfVar7 + 0x198,MoveParaSet::__defctor,(undefined *)0x0,0x10,0x20);
      Runtime.PPCEABI.H::__construct_array
                (pfVar7 + 0x218,MoveParaSetInitZero::MoveParaSetInitZero,(undefined *)0x0,0x10,0x20)
      ;
      Runtime.PPCEABI.H::__construct_array
                (pfVar7 + 0x298,MoveParaSetInitZero::MoveParaSetInitZero,(undefined *)0x0,0x10,0x20)
      ;
      Runtime.PPCEABI.H::__construct_array
                (pfVar7 + 0x318,MoveParaSetInitZero::MoveParaSetInitZero,(undefined *)0x0,0x10,0x20)
      ;
      Runtime.PPCEABI.H::__construct_array(pfVar7 + 0x4cf,MuteBit::MuteBit,(undefined *)0x0,1,0x20);
      JASystem::TTrack::TTrack((TTrack *)(pfVar7 + 0x4d8));
      JASystem::TTrack::TOuterParam::TOuterParam((TOuterParam *)(pfVar7 + 0x5bb));
    }
    pJVar6 = DAT_803ed0c0;
    *(float **)(DAT_803ed0c0 + iVar5 + 0x3c) = pfVar7;
    uVar12 = JAIGlobalParameter::getParamSeqParameterLines(pJVar6);
    if ((_msCurrentHeap == (JKRHeap *)0x0) &&
       (m_Do_printf::OSReport
                  ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
       _msCurrentHeap == (JKRHeap *)0x0)) {
      JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
      m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369496);
    }
    uVar4 = JKernel::operator_new__((uVar12 & 0xff) * 0x10 + 0x10,_msCurrentHeap,0x20);
    pJVar6 = (JAIGlobalParameter *)
             Runtime.PPCEABI.H::__construct_new_array
                       (uVar4,MoveParaSet::__defctor,0,0x10,uVar12 & 0xff);
    pfVar7[0x94] = (float)pJVar6;
    if ((pfVar7[0x94] == 0.0) &&
       (pJVar6 = (JAIGlobalParameter *)
                 m_Do_printf::OSReport("JAISequenceMgr::initHeap Cannot Alloc Heap!!\n"),
       pfVar7[0x94] == 0.0)) {
      JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",0x32,"_para->seqPan");
      pJVar6 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISequenceMgr.cpp",0x32,&DAT_80369496);
    }
    uVar12 = JAIGlobalParameter::getParamSeqParameterLines(pJVar6);
    if ((_msCurrentHeap == (JKRHeap *)0x0) &&
       (m_Do_printf::OSReport
                  ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
       _msCurrentHeap == (JKRHeap *)0x0)) {
      JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
      m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369496);
    }
    uVar4 = JKernel::operator_new__((uVar12 & 0xff) * 0x10 + 0x10,_msCurrentHeap,0x20);
    pJVar6 = (JAIGlobalParameter *)
             Runtime.PPCEABI.H::__construct_new_array
                       (uVar4,MoveParaSet::__defctor,0,0x10,uVar12 & 0xff);
    pfVar7[0x95] = (float)pJVar6;
    if ((pfVar7[0x95] == 0.0) &&
       (pJVar6 = (JAIGlobalParameter *)
                 m_Do_printf::OSReport("JAISequenceMgr::initHeap Cannot Alloc Heap!!\n"),
       pfVar7[0x95] == 0.0)) {
      JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",0x34,"_para->seqPitch");
      pJVar6 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISequenceMgr.cpp",0x34,&DAT_80369496);
    }
    uVar12 = JAIGlobalParameter::getParamSeqParameterLines(pJVar6);
    if ((_msCurrentHeap == (JKRHeap *)0x0) &&
       (m_Do_printf::OSReport
                  ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
       _msCurrentHeap == (JKRHeap *)0x0)) {
      JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
      m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369496);
    }
    uVar4 = JKernel::operator_new__((uVar12 & 0xff) * 0x10 + 0x10,_msCurrentHeap,0x20);
    pJVar6 = (JAIGlobalParameter *)
             Runtime.PPCEABI.H::__construct_new_array
                       (uVar4,MoveParaSet::__defctor,0,0x10,uVar12 & 0xff);
    pfVar7[0x96] = (float)pJVar6;
    if ((pfVar7[0x96] == 0.0) &&
       (pJVar6 = (JAIGlobalParameter *)
                 m_Do_printf::OSReport("JAISequenceMgr::initHeap Cannot Alloc Heap!!\n"),
       pfVar7[0x96] == 0.0)) {
      JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",0x36,"_para->seqFxmix");
      pJVar6 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISequenceMgr.cpp",0x36,&DAT_80369496);
    }
    uVar12 = JAIGlobalParameter::getParamSeqParameterLines(pJVar6);
    if ((_msCurrentHeap == (JKRHeap *)0x0) &&
       (m_Do_printf::OSReport
                  ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
       _msCurrentHeap == (JKRHeap *)0x0)) {
      JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
      m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369496);
    }
    uVar4 = JKernel::operator_new__((uVar12 & 0xff) * 0x10 + 0x10,_msCurrentHeap,0x20);
    pJVar6 = (JAIGlobalParameter *)
             Runtime.PPCEABI.H::__construct_new_array
                       (uVar4,MoveParaSet::__defctor,0,0x10,uVar12 & 0xff);
    pfVar7[0x97] = (float)pJVar6;
    if ((pfVar7[0x97] == 0.0) &&
       (pJVar6 = (JAIGlobalParameter *)
                 m_Do_printf::OSReport("JAISequenceMgr::initHeap Cannot Alloc Heap!!\n"),
       pfVar7[0x97] == 0.0)) {
      JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",0x38,"_para->seqDolby");
      pJVar6 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISequenceMgr.cpp",0x38,&DAT_80369496);
    }
    iVar5 = iVar5 + 0x44;
  }
  if ((_msCurrentHeap == (JKRHeap *)0x0) &&
     (pJVar6 = (JAIGlobalParameter *)
               m_Do_printf::OSReport
                         (
                         "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                         ), _msCurrentHeap == (JKRHeap *)0x0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    pJVar6 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369496);
  }
  pJVar2 = _msCurrentHeap;
  iVar5 = JAIGlobalParameter::getParamSeqPlayTrackMax(pJVar6);
  pJVar6 = (JAIGlobalParameter *)JKernel::operator_new__(iVar5 << 2,pJVar2,0x20);
  _FixSeqBufPointer = pJVar6;
  if ((pJVar6 == (JAIGlobalParameter *)0x0) &&
     (pJVar6 = (JAIGlobalParameter *)
               m_Do_printf::OSReport("JAISequenceMgr::initHeap Cannot Alloc Heap!!\n"),
     _FixSeqBufPointer == (JAIGlobalParameter *)0x0)) {
    JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",0x3c,"FixSeqBufPointer");
    pJVar6 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISequenceMgr.cpp",0x3c,&DAT_80369496);
  }
  iVar5 = JAIGlobalParameter::getParamSeqPlayTrackMax(pJVar6);
  if ((_msCurrentHeap == (JKRHeap *)0x0) &&
     (m_Do_printf::OSReport
                ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
     _msCurrentHeap == (JKRHeap *)0x0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369496);
  }
  uVar4 = JKernel::operator_new__(iVar5 * 0x50 + 0x10,_msCurrentHeap,0x20);
  pJVar6 = (JAIGlobalParameter *)
           Runtime.PPCEABI.H::__construct_new_array(uVar4,SeqUpdateData::SeqUpdateData,0,0x50,iVar5)
  ;
  _seqTrackInfo = pJVar6;
  if ((pJVar6 == (JAIGlobalParameter *)0x0) &&
     (pJVar6 = (JAIGlobalParameter *)
               m_Do_printf::OSReport("JAISequenceMgr::initHeap Cannot Alloc Heap!!\n"),
     _seqTrackInfo == (JAIGlobalParameter *)0x0)) {
    JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",0x3e,"seqTrackInfo");
    pJVar6 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISequenceMgr.cpp",0x3e,&DAT_80369496);
  }
  iVar5 = 0;
  iVar9 = 0;
  dVar16 = (double)JAudio::_885;
  dVar17 = (double)JAudio::_888;
  dVar18 = (double)JAudio::_887;
  dVar15 = (double)JAudio::_886;
  for (uVar12 = 0; uVar8 = JAIGlobalParameter::getParamSeqPlayTrackMax(pJVar6),
      pJVar6 = _FixSeqBufPointer, uVar12 < uVar8; uVar12 = uVar12 + 1) {
    *(undefined4 *)(_FixSeqBufPointer + iVar9) = 0;
    pJVar11 = _seqTrackInfo + iVar5;
    *(float *)(pJVar11 + 0xc) = (float)dVar16;
    *(float *)(pJVar11 + 0x18) = (float)dVar15;
    *(float *)(pJVar11 + 0x10) = (float)dVar16;
    *(float *)(pJVar11 + 0x14) = (float)dVar18;
    *(float *)(pJVar11 + 0x1c) = (float)dVar18;
    *(float *)(pJVar11 + 0x20) = (float)dVar16;
    iVar10 = 0;
    for (pJVar13 = (JAIGlobalParameter *)0x0;
        pJVar6 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeqTrackMax(pJVar6),
        pJVar13 < pJVar6; pJVar13 = pJVar13 + 1) {
      *(float *)(*(int *)(pJVar11 + 0x24) + iVar10) = (float)dVar16;
      *(float *)(*(int *)(pJVar11 + 0x30) + iVar10) = (float)dVar17;
      *(float *)(*(int *)(pJVar11 + 0x28) + iVar10) = (float)dVar16;
      *(float *)(*(int *)(pJVar11 + 0x2c) + iVar10) = (float)dVar18;
      *(float *)(*(int *)(pJVar11 + 0x34) + iVar10) = (float)dVar18;
      pJVar6 = *(JAIGlobalParameter **)(pJVar11 + 0x44);
      *(undefined4 *)(pJVar6 + iVar10) = 0;
      iVar10 = iVar10 + 4;
    }
    iVar5 = iVar5 + 0x50;
    iVar9 = iVar9 + 4;
  }
  __psq_l0(auStack8,uVar14);
  __psq_l1(auStack8,uVar14);
  __psq_l0(auStack24,uVar14);
  __psq_l1(auStack24,uVar14);
  __psq_l0(auStack40,uVar14);
  __psq_l1(auStack40,uVar14);
  __psq_l0(auStack56,uVar14);
  __psq_l1(auStack56,uVar14);
  return uVar8;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SeqUpdateData::SeqUpdateData(void) */

void __thiscall SeqUpdateData::SeqUpdateData(SeqUpdateData *this)

{
  int iVar1;
  undefined4 uVar2;
  JAIGlobalParameter *pJVar3;
  int iVar4;
  
  *this = (SeqUpdateData)0x0;
  this[1] = (SeqUpdateData)0x0;
  this[2] = (SeqUpdateData)0x0;
  this[3] = (SeqUpdateData)0x0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  if ((_msCurrentHeap == 0) &&
     (m_Do_printf::OSReport
                ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
     _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369496);
  }
  uVar2 = JKernel::operator_new__(0x7cc,_msCurrentHeap,0x20);
  pJVar3 = (JAIGlobalParameter *)
           Runtime.PPCEABI.H::__construct_new_array
                     (uVar2,PlayerParameter::PlayerParameter,PlayerParameter::_PlayerParameter,0x3c,
                      0x21);
  *(JAIGlobalParameter **)(this + 0x4c) = pJVar3;
  if ((*(int *)(this + 0x4c) == 0) &&
     (pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSReport("JAISeqUpdateData Cannot alloc Heap!!\n")
     , *(int *)(this + 0x4c) == 0)) {
    JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",0x51,"systemTrackParameter");
    pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISequenceMgr.cpp",0x51,&DAT_80369496);
  }
  if ((_msCurrentHeap == 0) &&
     (pJVar3 = (JAIGlobalParameter *)
               m_Do_printf::OSReport
                         (
                         "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                         ), _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369496);
  }
  iVar1 = _msCurrentHeap;
  iVar4 = JAIGlobalParameter::getParamSeqTrackMax(pJVar3);
  pJVar3 = (JAIGlobalParameter *)JKernel::operator_new__(iVar4 << 2,iVar1,0x20);
  *(JAIGlobalParameter **)(this + 0x24) = pJVar3;
  if ((*(int *)(this + 0x24) == 0) &&
     (pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSReport("JAISeqUpdateData Cannot Alloc Heap!!\n")
     , *(int *)(this + 0x24) == 0)) {
    JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",0x53,"trackVolume");
    pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISequenceMgr.cpp",0x53,&DAT_80369496);
  }
  if ((_msCurrentHeap == 0) &&
     (pJVar3 = (JAIGlobalParameter *)
               m_Do_printf::OSReport
                         (
                         "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                         ), _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369496);
  }
  iVar1 = _msCurrentHeap;
  iVar4 = JAIGlobalParameter::getParamSeqTrackMax(pJVar3);
  pJVar3 = (JAIGlobalParameter *)JKernel::operator_new__(iVar4 << 2,iVar1,0x20);
  *(JAIGlobalParameter **)(this + 0x30) = pJVar3;
  if ((*(int *)(this + 0x30) == 0) &&
     (pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSReport("JAISeqUpdateData Cannot Alloc Heap!!\n")
     , *(int *)(this + 0x30) == 0)) {
    JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",0x55,"trackPan");
    pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISequenceMgr.cpp",0x55,&DAT_80369496);
  }
  if ((_msCurrentHeap == 0) &&
     (pJVar3 = (JAIGlobalParameter *)
               m_Do_printf::OSReport
                         (
                         "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                         ), _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369496);
  }
  iVar1 = _msCurrentHeap;
  iVar4 = JAIGlobalParameter::getParamSeqTrackMax(pJVar3);
  pJVar3 = (JAIGlobalParameter *)JKernel::operator_new__(iVar4 << 2,iVar1,0x20);
  *(JAIGlobalParameter **)(this + 0x28) = pJVar3;
  if ((*(int *)(this + 0x28) == 0) &&
     (pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSReport("JAISeqUpdateData Cannot Alloc Heap!!\n")
     , *(int *)(this + 0x28) == 0)) {
    JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",0x57,"trackPitch");
    pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISequenceMgr.cpp",0x57,&DAT_80369496);
  }
  if ((_msCurrentHeap == 0) &&
     (pJVar3 = (JAIGlobalParameter *)
               m_Do_printf::OSReport
                         (
                         "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                         ), _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369496);
  }
  iVar1 = _msCurrentHeap;
  iVar4 = JAIGlobalParameter::getParamSeqTrackMax(pJVar3);
  pJVar3 = (JAIGlobalParameter *)JKernel::operator_new__(iVar4 << 2,iVar1,0x20);
  *(JAIGlobalParameter **)(this + 0x2c) = pJVar3;
  if ((*(int *)(this + 0x2c) == 0) &&
     (pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSReport("JAISeqUpdateData Cannot Alloc Heap!!\n")
     , *(int *)(this + 0x2c) == 0)) {
    JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",0x59,"trackFxmix");
    pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISequenceMgr.cpp",0x59,&DAT_80369496);
  }
  if ((_msCurrentHeap == 0) &&
     (pJVar3 = (JAIGlobalParameter *)
               m_Do_printf::OSReport
                         (
                         "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                         ), _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369496);
  }
  iVar1 = _msCurrentHeap;
  iVar4 = JAIGlobalParameter::getParamSeqTrackMax(pJVar3);
  pJVar3 = (JAIGlobalParameter *)JKernel::operator_new__(iVar4 << 2,iVar1,0x20);
  *(JAIGlobalParameter **)(this + 0x34) = pJVar3;
  if ((*(int *)(this + 0x34) == 0) &&
     (pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSReport("JAISeqUpdateData Cannot Alloc Heap!!\n")
     , *(int *)(this + 0x34) == 0)) {
    JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",0x5b,"trackDolby");
    pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISequenceMgr.cpp",0x5b,&DAT_80369496);
  }
  if ((_msCurrentHeap == 0) &&
     (pJVar3 = (JAIGlobalParameter *)
               m_Do_printf::OSReport
                         (
                         "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                         ), _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    pJVar3 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369496);
  }
  iVar1 = _msCurrentHeap;
  iVar4 = JAIGlobalParameter::getParamSeqTrackMax(pJVar3);
  uVar2 = JKernel::operator_new__((iVar4 + 1) * 4,iVar1,0x20);
  *(undefined4 *)(this + 0x44) = uVar2;
  if ((*(int *)(this + 0x44) == 0) &&
     (m_Do_printf::OSReport("JAISeqUpdateData Cannot Alloc Heap!!\n"), *(int *)(this + 0x44) == 0))
  {
    JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",99,"trackupdate");
    m_Do_printf::OSPanic("JAISequenceMgr.cpp",99,&DAT_80369496);
  }
  return;
}


/* __thiscall PlayerParameter::~PlayerParameter(void) */

void __thiscall PlayerParameter::_PlayerParameter(PlayerParameter *this)

{
  short in_r4;
  
  if ((this != (PlayerParameter *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall PlayerParameter::PlayerParameter(void) */

void __thiscall PlayerParameter::PlayerParameter(PlayerParameter *this)

{
  JASystem::Kernel::TPortCmd::TPortCmd((TPortCmd *)(this + 0x2c));
  return;
}


/* __thiscall SequenceMgr::getArchiveName(char *) */

void __thiscall SequenceMgr::getArchiveName(SequenceMgr *this,char *param_1)

{
  JAIGlobalParameter *pJVar1;
  char *pcVar2;
  
  *this = (SequenceMgr)0x0;
  pJVar1 = (JAIGlobalParameter *)
           JAIGlobalParameter::getParamAudioResPath((JAIGlobalParameter *)this);
  if (pJVar1 != (JAIGlobalParameter *)0x0) {
    pcVar2 = (char *)JAIGlobalParameter::getParamAudioResPath(pJVar1);
    pJVar1 = (JAIGlobalParameter *)MSL_C.PPCEABI.bare.H::strcat((char *)this,pcVar2);
  }
  pcVar2 = (char *)JAIGlobalParameter::getParamSequenceArchivesPath(pJVar1);
  pJVar1 = (JAIGlobalParameter *)MSL_C.PPCEABI.bare.H::strcat((char *)this,pcVar2);
  pcVar2 = (char *)JAIGlobalParameter::getParamSequenceArchivesFileName(pJVar1);
  MSL_C.PPCEABI.bare.H::strcat((char *)this,pcVar2);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::setArchivePointer(JKRArchive *) */

void __thiscall SequenceMgr::setArchivePointer(SequenceMgr *this,JKRArchive *param_1)

{
  _arcPointer = this;
  return;
}


/* __thiscall SequenceMgr::processGFrameSequence(void) */

void __thiscall SequenceMgr::processGFrameSequence(SequenceMgr *this)

{
  SequenceMgr *pSVar1;
  
  pSVar1 = (SequenceMgr *)checkEntriedSeq(this);
  pSVar1 = (SequenceMgr *)checkFadeoutSeq(pSVar1);
  pSVar1 = (SequenceMgr *)checkStoppedSeq(pSVar1);
  pSVar1 = (SequenceMgr *)checkPlayingSeq(pSVar1);
  pSVar1 = (SequenceMgr *)checkStartedSeq(pSVar1);
  pSVar1 = (SequenceMgr *)checkReadSeq(pSVar1);
  checkSeqWave(pSVar1);
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::checkEntriedSeq(void) */

void __thiscall SequenceMgr::checkEntriedSeq(SequenceMgr *this)

{
  byte bVar1;
  JKRArchive *pJVar2;
  HeapMgr *this_00;
  int iVar3;
  HeapMgr *pHVar4;
  JAIGlobalParameter *pJVar5;
  uint uVar6;
  uchar extraout_r4_00;
  undefined4 extraout_r4;
  JAIGlobalParameter *in_r5;
  uchar uVar7;
  code *in_r7;
  ulong in_r9;
  int iVar8;
  HeapMgr *pHVar9;
  HeapMgr *pHVar10;
  HeapMgr *pHVar11;
  uint uVar12;
  int iVar13;
  ulonglong uVar14;
  byte local_38 [20];
  
  uVar12 = 0;
  iVar13 = 0;
  do {
    uVar6 = JAIGlobalParameter::getParamSeqPlayTrackMax((JAIGlobalParameter *)this);
    if (uVar6 <= uVar12) {
      return;
    }
    pHVar11 = _seqTrackInfo + iVar13;
    this = *(SequenceMgr **)(pHVar11 + 0x48);
    if (((this != (SequenceMgr *)0x0) && ((*(uint *)(pHVar11 + 8) & 1) != 0)) &&
       (pHVar11[3] == (HeapMgr)0x0)) {
      pJVar2 = (JKRArchive *)
               JAIBasic::getSoundOffsetNumberFromID
                         (_msBasic,*(ulong *)((JAIGlobalParameter *)this + 0xc));
      this_00 = (HeapMgr *)JASystem::ResArcLoader::getResSize(_arcPointer,pJVar2,(ushort)in_r5);
      this = (SequenceMgr *)
             HeapMgr::checkOnMemory
                       ((HeapMgr *)(*(uint *)(*(int *)(pHVar11 + 0x48) + 0xc) & 0x3ff),
                        (ulong)local_38,(uchar *)in_r5);
      if (this == (SequenceMgr *)0x0) {
        iVar3 = JAISound::checkSwBit(*(JAISound **)(pHVar11 + 0x48),0x10);
        if (iVar3 != 0) {
          this = (SequenceMgr *)
                 HeapMgr::getFreeStayHeapPointer
                           (this_00,*(uint *)(*(int *)(pHVar11 + 0x48) + 0xc) & 0x3ff,(ulong)in_r5);
          local_38[0] = 0xff;
          iVar3 = JAISound::getSeqParameter(*(JAISound **)(pHVar11 + 0x48));
          *(undefined *)(iVar3 + 0x1260) = 0xff;
          if ((this == (SequenceMgr *)0x0) &&
             (iVar3 = JAISound::checkSwBit(*(JAISound **)(pHVar11 + 0x48),0x20), iVar3 == 0)) {
            m_Do_printf::OSReport
                      ("JAISequenceMgr::ステイヒープに入りませんでした。\n");
            JUTAssertion::showAssert(3,"JAISequenceMgr.cpp",0xb1,"buffer");
            in_r5 = (JAIGlobalParameter *)&DAT_80369496;
            m_Do_printf::OSPanic("JAISequenceMgr.cpp",0xb1);
          }
        }
        if ((this == (SequenceMgr *)0x0) &&
           ((pHVar4 = (HeapMgr *)JAISound::checkSwBit(*(JAISound **)(pHVar11 + 0x48),0x20),
            pHVar4 != (HeapMgr *)0x0 ||
            (pHVar4 = (HeapMgr *)JAISound::checkSwBit(*(JAISound **)(pHVar11 + 0x48),0x10),
            pHVar4 == (HeapMgr *)0x0)))) {
          pJVar5 = (JAIGlobalParameter *)HeapMgr::checkUsefulAutoHeapPosition(pHVar4);
          local_38[0] = (byte)pJVar5;
          pHVar4 = (HeapMgr *)JAIGlobalParameter::getParamAutoHeapMax(pJVar5);
          if ((JAIGlobalParameter *)(uint)local_38[0] < pHVar4) {
            pJVar5 = (JAIGlobalParameter *)
                     JAIGlobalParameter::getParamAutoHeapRoomSize((JAIGlobalParameter *)pHVar4);
            if (this_00 < pJVar5) goto LAB_80296ad8;
            JAIGlobalParameter::getParamAutoHeapRoomSize(pJVar5);
            this = (SequenceMgr *)JAISound::stop(*(JAISound **)(pHVar11 + 0x48),0);
          }
          else {
            iVar3 = 0;
            for (pHVar10 = (HeapMgr *)0x0;
                pHVar4 = (HeapMgr *)
                         JAIGlobalParameter::getParamAutoHeapMax((JAIGlobalParameter *)pHVar4),
                pHVar10 < pHVar4; pHVar10 = pHVar10 + 1) {
              iVar8 = HeapMgr::getAutoHeapPointer(pHVar4);
              pHVar4 = *(HeapMgr **)(iVar8 + iVar3 + 0x10);
              if (pHVar4 != (HeapMgr *)&DAT_ffffffff) {
                for (pHVar9 = (HeapMgr *)0x0;
                    pJVar5 = (JAIGlobalParameter *)
                             JAIGlobalParameter::getParamSeqPlayTrackMax
                                       ((JAIGlobalParameter *)pHVar4), pHVar9 < pJVar5;
                    pHVar9 = pHVar9 + 1) {
                  pHVar4 = _seqTrackInfo;
                  if (*(int *)(_seqTrackInfo + (int)pHVar9 * 0x50 + 0x48) != 0) {
                    iVar8 = HeapMgr::getAutoHeapPointer(_seqTrackInfo);
                    pHVar4 = *(HeapMgr **)(_seqTrackInfo + (int)pHVar9 * 0x50 + 0x48);
                    if ((*(uint *)((JAIGlobalParameter *)pHVar4 + 0xc) & 0x3ff) ==
                        *(uint *)(iVar8 + iVar3 + 8)) {
                      pHVar4 = (HeapMgr *)
                               JAIGlobalParameter::getParamSeqPlayTrackMax
                                         ((JAIGlobalParameter *)pHVar4);
                      pHVar9 = pHVar4;
                    }
                  }
                }
                pHVar4 = (HeapMgr *)JAIGlobalParameter::getParamSeqPlayTrackMax(pJVar5);
                if (pHVar9 == pHVar4) {
                  pHVar4 = (HeapMgr *)
                           HeapMgr::releaseAutoHeapPointer
                                     ((HeapMgr *)((uint)pHVar10 & 0xff),extraout_r4_00);
                  local_38[0] = (byte)pHVar10;
                }
              }
              iVar3 = iVar3 + 0x14;
            }
            uVar6 = JAIGlobalParameter::getParamAutoHeapMax((JAIGlobalParameter *)pHVar4);
            if (local_38[0] < uVar6) {
LAB_80296ad8:
              bVar1 = local_38[0];
              iVar3 = JAISound::getSeqParameter(*(JAISound **)(pHVar11 + 0x48));
              *(byte *)(iVar3 + 0x1260) = bVar1;
              iVar8 = (*(JAISound **)(pHVar11 + 0x48))->field_0xc;
              iVar3 = JAISound::getSeqParameter(*(JAISound **)(pHVar11 + 0x48));
              this = (SequenceMgr *)
                     HeapMgr::getFreeAutoHeapPointer
                               ((HeapMgr *)(uint)*(byte *)(iVar3 + 0x1260),(uchar)iVar8,(ulong)in_r5
                               );
              goto LAB_80296b04;
            }
            this = (SequenceMgr *)JAISound::stop(*(JAISound **)(pHVar11 + 0x48),0);
          }
        }
        else {
LAB_80296b04:
          uVar7 = (uchar)in_r5;
          iVar3 = JAISound::checkSwBit(*(JAISound **)(pHVar11 + 0x48),0x40);
          in_r5 = (JAIGlobalParameter *)this;
          pJVar5 = (JAIGlobalParameter *)this;
          if (iVar3 == 0) {
            *(undefined *)(*(int *)(pHVar11 + 0x48) + 5) = 1;
            uVar6 = (uint)local_38[0];
            HeapMgr::setAutoHeapLoadedFlag((HeapMgr *)(uint)local_38[0],'\x01',uVar7);
            pHVar11[3] = (HeapMgr)0x1;
            in_r7 = checkDvdLoadArc;
            uVar14 = JASystem::ResArcLoader::loadResourceAsync
                               (_arcPointer,pJVar2,(ushort)this,(uchar *)this_00,
                                (ulong)checkDvdLoadArc,
                                (FuncDef573 *)(uVar6 << 8 | uVar12 | (int)pJVar2 << 0x10),in_r9);
          }
          else {
            JASystem::ResArcLoader::loadResource
                      (_arcPointer,pJVar2,(ushort)this,(uchar *)this_00,(ulong)in_r7);
            uVar14 = CONCAT44(*(int *)(pHVar11 + 0x48),extraout_r4);
            *(undefined *)(*(int *)(pHVar11 + 0x48) + 5) = 2;
          }
LAB_80296bd4:
          this = (SequenceMgr *)(JAIGlobalParameter *)(uVar14 >> 0x20);
          if (pJVar5 == (JAIGlobalParameter *)0x0) {
            this = (SequenceMgr *)stopSeq(*(SequenceMgr **)(pHVar11 + 0x48),(JAISound *)uVar14);
          }
          else {
            *(JAIGlobalParameter **)(pHVar11 + 0x40) = pJVar5;
            *(uint *)(pHVar11 + 8) = *(uint *)(pHVar11 + 8) ^ 1;
          }
        }
      }
      else {
        if (this != (SequenceMgr *)&DAT_ffffffff) {
          if ((HeapMgr *)(uint)local_38[0] != (HeapMgr *)0xff) {
            HeapMgr::getFreeAutoHeapPointer
                      ((HeapMgr *)(uint)local_38[0],
                       (uchar)*(undefined4 *)(*(int *)(pHVar11 + 0x48) + 0xc),(ulong)in_r5);
          }
          bVar1 = local_38[0];
          uVar14 = JAISound::getSeqParameter(*(JAISound **)(pHVar11 + 0x48));
          *(byte *)((int)(uVar14 >> 0x20) + 0x1260) = bVar1;
          uVar14 = uVar14 & 0xffffffff | (ulonglong)*(uint *)(pHVar11 + 0x48) << 0x20;
          *(undefined *)(*(uint *)(pHVar11 + 0x48) + 5) = 2;
          pJVar5 = (JAIGlobalParameter *)this;
          goto LAB_80296bd4;
        }
      }
    }
    uVar12 = uVar12 + 1;
    iVar13 = iVar13 + 0x50;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::checkFadeoutSeq(void) */

void __thiscall SequenceMgr::checkFadeoutSeq(SequenceMgr *this)

{
  int iVar1;
  uint uVar2;
  JAISound *extraout_r4;
  int iVar3;
  uint uVar4;
  int iVar5;
  double extraout_f1;
  
  iVar5 = 0;
  for (uVar4 = 0; uVar2 = JAIGlobalParameter::getParamSeqPlayTrackMax((JAIGlobalParameter *)this),
      uVar4 < uVar2; uVar4 = uVar4 + 1) {
    iVar3 = _seqTrackInfo + iVar5;
    this = *(SequenceMgr **)(iVar3 + 0x48);
    if ((((JAISound *)this != (JAISound *)0x0) && (*(char *)((int)this + 5) == '\x05')) &&
       (this = (SequenceMgr *)JAISound::getSeqInterVolume((JAISound *)this,'\a'),
       (double)JAudio::_887 == extraout_f1)) {
      iVar1 = JAISound::getSeqParameter(*(JAISound **)(iVar3 + 0x48));
      JASystem::TTrack::stopSeq((TTrack *)(iVar1 + 0x1360));
      JAISound::clearMainSoundPPointer(*(JAISound **)(iVar3 + 0x48));
      this = (SequenceMgr *)stopSeq(*(SequenceMgr **)(iVar3 + 0x48),extraout_r4);
      *(undefined4 *)(iVar3 + 8) = 0;
    }
    iVar5 = iVar5 + 0x50;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::checkStoppedSeq(void) */

void __thiscall SequenceMgr::checkStoppedSeq(SequenceMgr *this)

{
  uint uVar1;
  JAISound *extraout_r4;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  
  iVar4 = 0;
  for (uVar3 = 0; uVar1 = JAIGlobalParameter::getParamSeqPlayTrackMax((JAIGlobalParameter *)this),
      uVar3 < uVar1; uVar3 = uVar3 + 1) {
    iVar2 = _seqTrackInfo + iVar4;
    this = *(SequenceMgr **)(iVar2 + 0x48);
    if ((JAISound *)this != (JAISound *)0x0) {
      if ((*(char *)((int)this + 5) == '\x04') || (*(char *)((int)this + 5) == '\x05')) {
        uVar5 = JAISound::getSeqParameter((JAISound *)this);
        this = (SequenceMgr *)
               SystemInterface::checkSeqActiveFlag
                         ((SystemInterface *)((int)((ulonglong)uVar5 >> 0x20) + 0x1360),
                          (TTrack *)uVar5);
        if (((uint)this & 0xff) == 0) {
          JAISound::clearMainSoundPPointer(*(JAISound **)(iVar2 + 0x48));
          this = (SequenceMgr *)stopSeq(*(SequenceMgr **)(iVar2 + 0x48),extraout_r4);
          *(undefined4 *)(iVar2 + 8) = 0;
        }
      }
    }
    iVar4 = iVar4 + 0x50;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::checkPlayingSeq(void) */

void __thiscall SequenceMgr::checkPlayingSeq(SequenceMgr *this)

{
  SeqUpdateData *pSVar1;
  JAIGlobalParameter *this_00;
  int iVar2;
  ulong in_r7;
  uint uVar3;
  int iVar4;
  int iVar5;
  SystemInterface *this_01;
  SequenceMgr *this_02;
  undefined8 uVar6;
  
  this_02 = (SequenceMgr *)0x0;
  iVar5 = 0;
  do {
    uVar6 = JAIGlobalParameter::getParamSeqPlayTrackMax((JAIGlobalParameter *)this);
    if ((SequenceMgr *)((ulonglong)uVar6 >> 0x20) <= this_02) {
      return;
    }
    this_01 = (SystemInterface *)(_seqTrackInfo + iVar5);
    this = *(SequenceMgr **)(this_01 + 0x48);
    if ((this != (SequenceMgr *)0x0) && (3 < (byte)((JAIGlobalParameter *)this)[5])) {
      this_00 = (JAIGlobalParameter *)checkPlayingSeqTrack(this_02,(ulong)uVar6);
      uVar3 = 0;
      while( true ) {
        this = (SequenceMgr *)JAIGlobalParameter::getParamSeqTrackMax(this_00);
        if ((JAIGlobalParameter *)this + 1 <= (JAIGlobalParameter *)(uVar3 & 0xff)) break;
        this_00 = *(JAIGlobalParameter **)(this_01 + 0x44);
        pSVar1 = (SeqUpdateData *)(uVar3 & 0xff);
        iVar4 = (uVar3 & 0xff) * 4;
        if (*(int *)(this_00 + iVar4) != 0) {
          if (pSVar1 != (SeqUpdateData *)&DAT_00000020) {
            iVar2 = JAISound::getSeqParameter(*(JAISound **)(this_01 + 0x48));
            this_00 = *(JAIGlobalParameter **)(*(int *)(iVar2 + 0x135c) + 4);
            if ((1 << (int)(JAIGlobalParameter *)(uVar3 & 0xff) & (uint)this_00) == 0)
            goto LAB_80296e28;
          }
          SystemInterface::setSeqPortargsU32
                    (this_01,pSVar1,1,(uchar)*(undefined4 *)(*(int *)(this_01 + 0x44) + iVar4),in_r7
                    );
          this_00 = (JAIGlobalParameter *)
                    JASystem::Kernel::TPortCmd::addPortCmdOnce
                              ((TPortCmd *)(*(int *)(this_01 + 0x4c) + (int)pSVar1 * 0x3c + 0x2c));
        }
LAB_80296e28:
        uVar3 = uVar3 + 1;
      }
    }
    this_02 = this_02 + 1;
    iVar5 = iVar5 + 0x50;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::checkStartedSeq(void) */

void __thiscall SequenceMgr::checkStartedSeq(SequenceMgr *this)

{
  uint uVar1;
  SystemInterface *this_00;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  ulonglong uVar5;
  
  iVar3 = 0;
  for (uVar2 = 0; uVar1 = JAIGlobalParameter::getParamSeqPlayTrackMax((JAIGlobalParameter *)this),
      uVar2 < uVar1; uVar2 = uVar2 + 1) {
    this_00 = (SystemInterface *)(_seqTrackInfo + iVar3);
    this = *(SequenceMgr **)(this_00 + 0x48);
    if ((JAISound *)this != (JAISound *)0x0) {
      if (*(char *)((int)this + 5) == '\x03') {
        uVar4 = JAISound::getSeqParameter((JAISound *)this);
        uVar5 = SystemInterface::checkSeqActiveFlag
                          ((SystemInterface *)((int)((ulonglong)uVar4 >> 0x20) + 0x1360),
                           (TTrack *)uVar4);
        this = (SequenceMgr *)(JAISound *)(uVar5 >> 0x20);
        if ((uVar5 & 0xff00000000) != 0) {
          *(undefined *)(*(int *)(this_00 + 0x48) + 5) = 4;
          this = (SequenceMgr *)SystemInterface::trackInit(this_00,(SeqUpdateData *)uVar5);
        }
      }
    }
    iVar3 = iVar3 + 0x50;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x80297114) */
/* WARNING: Removing unreachable block (ram,0x8029710c) */
/* WARNING: Removing unreachable block (ram,0x8029711c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::checkReadSeq(void) */

void __thiscall SequenceMgr::checkReadSeq(SequenceMgr *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  JAISound *pJVar4;
  JKRArchive *pJVar5;
  JAIGlobalParameter *this_00;
  uint uVar6;
  SequenceMgr *pSVar7;
  ulong extraout_r4;
  ulong in_r5;
  ushort uVar8;
  JAIGlobalParameter *pJVar9;
  uint uVar10;
  int iVar11;
  SystemInterface *this_01;
  SequenceMgr *this_02;
  undefined4 uVar12;
  undefined8 in_f29;
  double dVar13;
  undefined8 in_f30;
  double dVar14;
  undefined8 in_f31;
  double dVar15;
  undefined8 uVar16;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  iVar11 = 0;
  for (this_02 = (SequenceMgr *)0x0;
      pSVar7 = (SequenceMgr *)
               JAIGlobalParameter::getParamSeqPlayTrackMax((JAIGlobalParameter *)this),
      this_02 < pSVar7; this_02 = this_02 + 1) {
    this_01 = (SystemInterface *)(_seqTrackInfo + iVar11);
    this = *(SequenceMgr **)(this_01 + 0x48);
    if (((JAISound *)this != (JAISound *)0x0) && (*(char *)((int)this + 5) == '\x02')) {
      iVar3 = JAISound::getSeqParameter((JAISound *)this);
      this = (SequenceMgr *)*(JAISound **)(iVar3 + 0x1264);
      if (*(JAISound **)(iVar3 + 0x1264) == (JAISound *)&DAT_ffffffff) {
        iVar3 = JAISound::getSeqParameter(*(JAISound **)(this_01 + 0x48));
        this = (SequenceMgr *)*(JAISound **)(iVar3 + 0x135c);
        if (*(char *)&(*(JAISound **)(iVar3 + 0x135c))->field_0x2 == '\0') {
          pJVar4 = (JAISound *)JAISound::getSeqParameter(*(JAISound **)(this_01 + 0x48));
          uVar8 = (ushort)in_r5;
          this = (SequenceMgr *)pJVar4;
          if (*(char *)((int)&pJVar4[0xb6].field_0x1c + 2) == '\0') {
            pJVar5 = (JKRArchive *)
                     JAIBasic::getSoundOffsetNumberFromID
                               ((JAIBasic *)_msBasic,*(ulong *)(*(int *)(this_01 + 0x48) + 0xc));
            in_r5 = JASystem::ResArcLoader::getResSize(_arcPointer,pJVar5,uVar8);
            JASystem::TTrack::setSeqData
                      ((TTrack *)(pJVar4 + 0x9b),*(uchar **)(this_01 + 0x40),in_r5,0);
            fVar1 = JAudio::_885;
            this_00 = _seqTrackInfo;
            pJVar9 = _seqTrackInfo + (uint)*(byte *)(*(int *)(this_01 + 0x48) + 4) * 0x50;
            dVar13 = (double)JAudio::_885;
            *(float *)(pJVar9 + 0xc) = JAudio::_885;
            *(float *)(pJVar9 + 0x18) = JAudio::_886;
            *(float *)(pJVar9 + 0x10) = fVar1;
            fVar2 = JAudio::_887;
            dVar14 = (double)JAudio::_887;
            *(float *)(pJVar9 + 0x14) = JAudio::_887;
            *(float *)(pJVar9 + 0x1c) = fVar2;
            *(float *)(pJVar9 + 0x20) = fVar1;
            iVar3 = 0;
            dVar15 = (double)JAudio::_888;
            for (uVar10 = 0; uVar6 = JAIGlobalParameter::getParamSeqTrackMax(this_00),
                uVar10 < uVar6; uVar10 = uVar10 + 1) {
              *(float *)(*(int *)(pJVar9 + 0x24) + iVar3) = (float)dVar13;
              *(float *)(*(int *)(pJVar9 + 0x30) + iVar3) = (float)dVar15;
              *(float *)(*(int *)(pJVar9 + 0x28) + iVar3) = (float)dVar13;
              *(float *)(*(int *)(pJVar9 + 0x2c) + iVar3) = (float)dVar14;
              *(float *)(*(int *)(pJVar9 + 0x34) + iVar3) = (float)dVar14;
              this_00 = *(JAIGlobalParameter **)(pJVar9 + 0x44);
              *(undefined4 *)(this_00 + iVar3) = 0;
              iVar3 = iVar3 + 4;
            }
            *(undefined *)(*(int *)(this_01 + 0x48) + 5) = 3;
            if (1 < *(uint *)&(*(JAISound **)(this_01 + 0x48))->field_0x14) {
              JAISound::setSeqInterVolume(*(JAISound **)(this_01 + 0x48),'\a',JAudio::_887,0);
              in_r5 = *(ulong *)&(*(JAISound **)(this_01 + 0x48))->field_0x14;
              JAISound::setSeqInterVolume(*(JAISound **)(this_01 + 0x48),'\a',JAudio::_885,in_r5);
            }
            if (*this_01 != (SystemInterface)0x0) {
              in_r5 = (ulong)(byte)this_01[1];
              JAISound::setPauseMode
                        (*(JAISound **)(this_01 + 0x48),(uchar)*this_01,(uchar)this_01[1]);
              *(float *)(this_01 + 0xc) = JAudio::_1280;
            }
            (**(code **)(*_msBasic + 0x18))(_msBasic,*(undefined4 *)(this_01 + 0x48));
            uVar16 = checkPlayingSeqTrack(this_02,extraout_r4);
            this = (SequenceMgr *)(JAISound *)((ulonglong)uVar16 >> 0x20);
            if (*(int *)(this_01 + 0x48) != 0) {
              SystemInterface::rootInit(this_01,(SeqUpdateData *)uVar16);
              this = (SequenceMgr *)JASystem::TTrack::startSeq((TTrack *)(pJVar4 + 0x9b));
            }
          }
        }
      }
    }
    iVar11 = iVar11 + 0x50;
  }
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  __psq_l0(auStack40,uVar12);
  __psq_l1(auStack40,uVar12);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::checkSeqWave(void) */

void __thiscall SequenceMgr::checkSeqWave(SequenceMgr *this)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  JAISound *pJVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = 0;
  for (uVar6 = 0; uVar3 = JAIGlobalParameter::getParamSeqPlayTrackMax((JAIGlobalParameter *)this),
      iVar1 = _seqTrackInfo, uVar6 < uVar3; uVar6 = uVar6 + 1) {
    iVar5 = iVar7 + 0x48;
    this = *(SequenceMgr **)(_seqTrackInfo + iVar5);
    if (((JAISound *)this != (JAISound *)0x0) &&
       (this = (SequenceMgr *)JAISound::getSeqParameter((JAISound *)this),
       (JAISound *)this != (JAISound *)0x0)) {
      iVar2 = JAISound::getSeqParameter(*(JAISound **)(iVar1 + iVar5));
      this = (SequenceMgr *)*(JAISound **)(iVar2 + 0x1264);
      if ((*(JAISound **)(iVar2 + 0x1264) != (JAISound *)&DAT_ffffffff) &&
         (this = (SequenceMgr *)_SceneSetFlag, _SceneSetFlag != (JAISound *)&DAT_ffffffff)) {
        iVar2 = JAISound::getSeqParameter(*(JAISound **)(iVar1 + iVar5));
        pJVar4 = *(JAISound **)(iVar2 + 0x1264);
        if ((((pJVar4 == _SceneSetFlag) || (pJVar4 == (JAISound *)0xff00ff00)) ||
            ((((uint)pJVar4 & 0xffff0000) == ((uint)_SceneSetFlag & 0xffff0000) &&
             (pJVar4 == (JAISound *)0xffff)))) ||
           ((this = (SequenceMgr *)((uint)pJVar4 & 0xffff),
            (JAISound *)this == (JAISound *)((uint)_SceneSetFlag & 0xffff) &&
            (pJVar4 == (JAISound *)0xffff0000)))) {
          this = (SequenceMgr *)JAISound::getSeqParameter(*(JAISound **)(iVar1 + iVar5));
          *(undefined4 *)&((JAISound *)((int)this + 0x1260))->field_0x4 = 0xffffffff;
        }
      }
    }
    iVar7 = iVar7 + 0x50;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x80297358) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::checkPlayingSeqUpdateMultiplication(unsigned long,
                                                                        unsigned char,
                                                                        unsigned long,
                                                                        MoveParaSet *,
                                                                        unsigned long *,
                                                                        unsigned char,
                                                                        float *) */

void __thiscall
SequenceMgr::checkPlayingSeqUpdateMultiplication
          (SequenceMgr *this,ulong param_1,uchar param_2,ulong param_3,MoveParaSet *param_4,
          ulong *param_5,uchar param_6,float *param_7)

{
  float fVar1;
  int iVar2;
  SeqUpdateData *pSVar3;
  JAIGlobalParameter *this_00;
  int iVar4;
  undefined3 in_register_00000014;
  ulong uVar5;
  uchar uVar6;
  undefined3 in_register_00000024;
  MoveParaSet *this_01;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined8 in_f31;
  double dVar12;
  undefined auStack8 [8];
  
  iVar2 = _seqTrackInfo;
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar10 = (int)this * 0x50;
  iVar9 = iVar10 + 8;
  if ((*(uint *)(_seqTrackInfo + iVar9) & CONCAT31(in_register_00000014,param_2)) != 0) {
    uVar8 = 0;
    uVar5 = param_3;
    fVar1 = JAudio::_885;
    while( true ) {
      uVar6 = (uchar)uVar5;
      dVar12 = (double)fVar1;
      if ((param_1 & 0xff) <= (uVar8 & 0xff)) break;
      this = (SequenceMgr *)(uVar8 & 0xff);
      this_01 = (MoveParaSet *)(param_3 + (uVar8 & 0xff) * 0x10);
      uVar7 = 1 << (int)this;
      if (((*(uint *)param_4 & uVar7) != 0) &&
         (this = (SequenceMgr *)MoveParaSet::move(this_01), this == (SequenceMgr *)0x0)) {
        *(uint *)param_4 = *(uint *)param_4 ^ uVar7;
      }
      fVar1 = (float)(dVar12 * (double)*(float *)(this_01 + 4));
      uVar8 = uVar8 + 1;
    }
    if ((double)*(float *)CONCAT31(in_register_00000024,param_6) != dVar12) {
      *(float *)CONCAT31(in_register_00000024,param_6) = fVar1;
      pSVar3 = (SeqUpdateData *)JAIGlobalParameter::getParamSeqTrackMax((JAIGlobalParameter *)this);
      this_00 = (JAIGlobalParameter *)
                SystemInterface::setSeqPortargsF32
                          ((SystemInterface *)(_seqTrackInfo + iVar10),pSVar3,(ulong)param_5,uVar6,
                           (float)dVar12);
      iVar4 = JAIGlobalParameter::getParamSeqTrackMax(this_00);
      iVar10 = *(int *)(_seqTrackInfo + iVar10 + 0x44);
      *(uint *)(iVar10 + iVar4 * 4) =
           *(uint *)(iVar10 + iVar4 * 4) | 1 << ((uint)param_5 & 0xff) - 2;
    }
    if (*(int *)param_4 == 0) {
      *(uint *)(iVar2 + iVar9) = *(uint *)(iVar2 + iVar9) ^ CONCAT31(in_register_00000014,param_2);
    }
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x802974d0) */
/* WARNING: Removing unreachable block (ram,0x802974d8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::checkPlayingSeqUpdateAddition(unsigned long,
                                                                  unsigned char,
                                                                  unsigned long,
                                                                  MoveParaSet *,
                                                                  unsigned long *,
                                                                  unsigned char,
                                                                  float *,
                                                                  float) */

void __thiscall
SequenceMgr::checkPlayingSeqUpdateAddition
          (SequenceMgr *this,ulong param_1,uchar param_2,ulong param_3,MoveParaSet *param_4,
          ulong *param_5,uchar param_6,float *param_7,float param_8)

{
  float fVar1;
  int iVar2;
  SeqUpdateData *pSVar3;
  JAIGlobalParameter *this_00;
  int iVar4;
  undefined3 in_register_00000014;
  ulong uVar5;
  uchar uVar6;
  undefined3 in_register_00000024;
  MoveParaSet *this_01;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  double dVar12;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar13;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  iVar2 = _seqTrackInfo;
  dVar12 = (double)param_8;
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  iVar10 = (int)this * 0x50;
  iVar9 = iVar10 + 8;
  if ((*(uint *)(_seqTrackInfo + iVar9) & CONCAT31(in_register_00000014,param_2)) != 0) {
    uVar8 = 0;
    uVar5 = param_3;
    fVar1 = JAudio::_887;
    while( true ) {
      uVar6 = (uchar)uVar5;
      dVar13 = (double)fVar1;
      if ((param_1 & 0xff) <= (uVar8 & 0xff)) break;
      this = (SequenceMgr *)(uVar8 & 0xff);
      this_01 = (MoveParaSet *)(param_3 + (uVar8 & 0xff) * 0x10);
      uVar7 = 1 << (int)this;
      if (((*(uint *)param_4 & uVar7) != 0) &&
         (this = (SequenceMgr *)MoveParaSet::move(this_01), this == (SequenceMgr *)0x0)) {
        *(uint *)param_4 = *(uint *)param_4 ^ uVar7;
      }
      fVar1 = (float)(dVar13 + (double)(float)((double)*(float *)(this_01 + 4) - dVar12));
      uVar8 = uVar8 + 1;
    }
    dVar13 = (double)(float)(dVar13 + dVar12);
    dVar12 = (double)JAudio::_885;
    if ((dVar13 <= dVar12) && (dVar12 = dVar13, dVar13 < (double)JAudio::_887)) {
      dVar12 = (double)JAudio::_887;
    }
    if ((double)*(float *)CONCAT31(in_register_00000024,param_6) != dVar12) {
      *(float *)CONCAT31(in_register_00000024,param_6) = (float)dVar12;
      pSVar3 = (SeqUpdateData *)JAIGlobalParameter::getParamSeqTrackMax((JAIGlobalParameter *)this);
      this_00 = (JAIGlobalParameter *)
                SystemInterface::setSeqPortargsF32
                          ((SystemInterface *)(_seqTrackInfo + iVar10),pSVar3,(ulong)param_5,uVar6,
                           (float)dVar12);
      iVar4 = JAIGlobalParameter::getParamSeqTrackMax(this_00);
      iVar10 = *(int *)(_seqTrackInfo + iVar10 + 0x44);
      *(uint *)(iVar10 + iVar4 * 4) =
           *(uint *)(iVar10 + iVar4 * 4) | 1 << ((uint)param_5 & 0xff) - 2;
    }
    if (*(int *)param_4 == 0) {
      *(uint *)(iVar2 + iVar9) = *(uint *)(iVar2 + iVar9) ^ CONCAT31(in_register_00000014,param_2);
    }
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::checkPlayingSeqUpdateTrack(unsigned long,
                                                               unsigned long,
                                                               MoveParaSet *,
                                                               unsigned long *,
                                                               unsigned char,
                                                               float *) */

void __thiscall
SequenceMgr::checkPlayingSeqUpdateTrack
          (SequenceMgr *this,ulong param_1,ulong param_2,MoveParaSet *param_3,ulong *param_4,
          uchar param_5,float *param_6)

{
  int iVar1;
  int iVar2;
  JAIGlobalParameter *pJVar3;
  JAIGlobalParameter *this_00;
  uint uVar4;
  MoveParaSet *pMVar5;
  undefined3 in_register_00000020;
  MoveParaSet *this_01;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar2 = _seqTrackInfo;
  iVar8 = (int)this * 0x50;
  iVar7 = iVar8 + 8;
  if ((*(uint *)(_seqTrackInfo + iVar7) & param_1) != 0) {
    uVar6 = 0;
    this_00 = (JAIGlobalParameter *)((uint)param_4 & 0xff);
    pJVar3 = this_00 + -2;
    pMVar5 = param_3;
    while( true ) {
      uVar4 = JAIGlobalParameter::getParamSeqTrackMax(this_00);
      if (uVar4 <= (uVar6 & 0xff)) break;
      this_01 = (MoveParaSet *)(param_2 + (uVar6 & 0xff) * 0x10);
      this_00 = *(JAIGlobalParameter **)param_3;
      uVar4 = 1 << (uVar6 & 0xff);
      if (((uint)this_00 & uVar4) != 0) {
        this_00 = (JAIGlobalParameter *)MoveParaSet::move(this_01);
        if (this_00 == (JAIGlobalParameter *)0x0) {
          *(uint *)param_3 = *(uint *)param_3 ^ uVar4;
        }
        iVar1 = (int)(SeqUpdateData *)(uVar6 & 0xff) * 4;
        if (*(float *)(this_01 + 4) != *(float *)(CONCAT31(in_register_00000020,param_5) + iVar1)) {
          *(float *)(CONCAT31(in_register_00000020,param_5) + iVar1) = *(float *)(this_01 + 4);
          SystemInterface::setSeqPortargsF32
                    ((SystemInterface *)(_seqTrackInfo + iVar8),(SeqUpdateData *)(uVar6 & 0xff),
                     (ulong)param_4,(uchar)pMVar5,*(float *)(this_01 + 4));
          this_00 = *(JAIGlobalParameter **)(iVar8 + _seqTrackInfo + 0x44);
          *(uint *)(this_00 + iVar1) = *(uint *)(this_00 + iVar1) | 1 << (int)pJVar3;
        }
      }
      uVar6 = uVar6 + 1;
    }
    if (*(int *)param_3 == 0) {
      *(uint *)(iVar2 + iVar7) = *(uint *)(iVar2 + iVar7) ^ param_1;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x80297df0) */
/* WARNING: Removing unreachable block (ram,0x80297de0) */
/* WARNING: Removing unreachable block (ram,0x80297de8) */
/* WARNING: Removing unreachable block (ram,0x80297df8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::checkPlayingSeqTrack(unsigned long) */

void __thiscall SequenceMgr::checkPlayingSeqTrack(SequenceMgr *this,ulong param_1)

{
  MoveParaSet MVar1;
  char cVar2;
  int iVar3;
  MoveParaSet *this_00;
  int iVar4;
  MoveParaSet *this_01;
  JAISound *pJVar5;
  JAIGlobalParameter *pJVar6;
  MTX34 *pMtx;
  ulong uVar7;
  SeqUpdateData *pSVar8;
  TTrack *this_02;
  JAISound *extraout_r4;
  ulong uVar9;
  uchar uVar10;
  float *pfVar11;
  float *in_r10;
  cXyz *pDst;
  JAIGlobalParameter *pJVar12;
  uint uVar13;
  int iVar14;
  byte bVar15;
  JAIGlobalParameter *pJVar16;
  byte bVar17;
  int iVar18;
  int iVar19;
  undefined4 uVar20;
  double dVar21;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double dVar22;
  undefined8 in_f28;
  double dVar23;
  undefined8 in_f29;
  double dVar24;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar25;
  ushort local_98 [2];
  float local_94;
  longlong local_90;
  undefined4 local_88;
  uint uStack132;
  longlong local_80;
  double local_78;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar20 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  iVar18 = (int)this * 0x50;
  iVar19 = _seqTrackInfo + iVar18;
  iVar3 = JAISound::getSeqParameter(*(JAISound **)(iVar19 + 0x48));
  if (*(char *)(iVar3 + 0x1261) != '\x02') {
    this_00 = (MoveParaSet *)JAISound::getSeqParameter(*(JAISound **)(iVar19 + 0x48));
    iVar3 = *(int *)(iVar19 + 0x44);
    uVar13 = 0;
    this_01 = this_00;
    while( true ) {
      iVar4 = JAIGlobalParameter::getParamSeqTrackMax((JAIGlobalParameter *)this_01);
      this_01 = (MoveParaSet *)(iVar4 + 1);
      if (this_01 <= (JAIGlobalParameter *)(uVar13 & 0xff)) break;
      *(undefined4 *)(iVar3 + (uVar13 & 0xff) * 4) = 0;
      uVar13 = uVar13 + 1;
    }
    if ((*(uint *)(iVar19 + 8) & 2) != 0) {
      pJVar5 = *(JAISound **)(iVar19 + 0x48);
      if ((*(ulong *)&pJVar5->field_0x14 == 0) || (*(byte *)&pJVar5->field_0x5 < 4)) {
        if (2 < *(byte *)&pJVar5->field_0x5) {
          JASystem::TTrack::stopSeq((TTrack *)(this_00 + 0x1360));
        }
        JAISound::clearMainSoundPPointer(*(JAISound **)(iVar19 + 0x48));
        stopSeq(*(SequenceMgr **)(iVar19 + 0x48),extraout_r4);
        *(undefined4 *)(iVar19 + 8) = 0;
        goto LAB_80297de0;
      }
      JAISound::setSeqInterVolume(pJVar5,'\a',JAudio::_887,*(ulong *)&pJVar5->field_0x14);
      *(undefined *)(*(int *)(iVar19 + 0x48) + 5) = 5;
      *(uint *)(iVar19 + 8) = *(uint *)(iVar19 + 8) ^ 2;
    }
    pJVar6 = *(JAIGlobalParameter **)(iVar19 + 0x48);
    if ((pJVar6 != (JAIGlobalParameter *)0x0) && (*(int *)(pJVar6 + 0x24) != 0)) {
      pJVar6 = (JAIGlobalParameter *)(uint)(byte)pJVar6[8];
      if (pJVar6 == (JAIGlobalParameter *)&DAT_00000004) {
        pJVar6 = (JAIGlobalParameter *)
                 JAIGlobalParameter::getParamAudioCameraMax((JAIGlobalParameter *)&DAT_00000004);
        pJVar12 = (JAIGlobalParameter *)0x0;
        pJVar16 = pJVar6;
      }
      else {
        pJVar16 = pJVar6 + 1;
        pJVar12 = pJVar6;
      }
      dVar25 = (double)JAudio::_887;
      dVar23 = (double)JAudio::_1662;
      iVar4 = (int)pJVar12 * 0x1c;
      iVar14 = (int)pJVar12 * 0xc;
      dVar24 = JAudio::_1665;
      for (; pJVar12 < pJVar16; pJVar12 = pJVar12 + 1) {
        pDst = (cXyz *)(*(int *)(*(int *)(iVar19 + 0x48) + 0x20) + iVar4);
        pDst[1].x = pDst->x;
        pDst[1].y = pDst->y;
        pDst[1].z = pDst->z;
        pMtx = *(MTX34 **)(*(int *)(_msBasic + 4) + iVar14 + 8);
        mtx::PSMTXMultVec(pMtx,*(cXyz **)(*(int *)(iVar19 + 0x48) + 0x28),pDst);
        dVar22 = (double)(pDst->z * pDst->z + pDst->x * pDst->x + pDst->y * pDst->y);
        if (dVar25 < dVar22) {
          dVar21 = 1.0 / SQRT(dVar22);
          dVar21 = JAudio::_1660 * dVar21 * (JAudio::_1661 - dVar22 * dVar21 * dVar21);
          dVar21 = JAudio::_1660 * dVar21 * (JAudio::_1661 - dVar22 * dVar21 * dVar21);
          local_94 = (float)(dVar22 * JAudio::_1660 * dVar21 *
                                      (JAudio::_1661 - dVar22 * dVar21 * dVar21));
          dVar22 = (double)local_94;
        }
        pDst[2].x = (float)dVar22;
        JAIGlobalParameter::getParamDistanceMax((JAIGlobalParameter *)pMtx);
        pJVar6 = (JAIGlobalParameter *)
                 (**(code **)(**(int **)(iVar19 + 0x48) + 0xc))(*(int **)(iVar19 + 0x48),0);
        dVar22 = extraout_f1;
        uVar13 = JAIGlobalParameter::getParamDistanceParameterMoveTime(pJVar6);
        local_90 = (longlong)(int)(dVar23 * dVar22);
        uStack132 = (int)(dVar23 * dVar22) & 0xff;
        local_88 = 0x43300000;
        JAISound::setSeqInterVolume
                  (*(JAISound **)(iVar19 + 0x48),'\x04',
                   (float)((double)CONCAT44(0x43300000,uStack132) - dVar24),uVar13 & 0xff);
        pJVar6 = (JAIGlobalParameter *)(**(code **)(**(int **)(iVar19 + 0x48) + 0x10))();
        dVar22 = extraout_f1_00;
        uVar13 = JAIGlobalParameter::getParamDistanceParameterMoveTime(pJVar6);
        local_80 = (longlong)(int)dVar22;
        local_78 = (double)CONCAT44(0x43300000,(int)dVar22 & 0xff);
        JAISound::setSeqInterPan
                  (*(JAISound **)(iVar19 + 0x48),'\x04',(float)(local_78 - dVar24),uVar13 & 0xff);
        pJVar6 = (JAIGlobalParameter *)
                 (**(code **)(**(int **)(iVar19 + 0x48) + 8))(*(int **)(iVar19 + 0x48),0x100);
        dVar22 = extraout_f1_01;
        uVar7 = JAIGlobalParameter::getParamDopplarMoveTime(pJVar6);
        pJVar6 = (JAIGlobalParameter *)
                 JAISound::setSeqInterPitch
                           (*(JAISound **)(iVar19 + 0x48),'\x04',(float)dVar22,uVar7);
        iVar14 = iVar14 + 0xc;
        iVar4 = iVar4 + 0x1c;
      }
    }
    iVar4 = *(int *)(iVar19 + 0x48);
    if (iVar4 != 0) {
      pJVar6 = *(JAIGlobalParameter **)(iVar4 + 0x18);
      *(JAIGlobalParameter **)(iVar4 + 0x18) = pJVar6 + 1;
    }
    if (*(int *)(iVar19 + 8) != 0) {
      iVar4 = JAIGlobalParameter::getParamSeqPlayTrackMax(pJVar6);
      cVar2 = (char)iVar19;
      pJVar6 = (JAIGlobalParameter *)
               checkPlayingSeqUpdateMultiplication
                         (this,iVar4 + 0xcU & 0xff,'\0',(ulong)(this_00 + 0x110),this_00 + 0x126c,
                          (ulong *)&DAT_00000002,cVar2 + '\f',in_r10);
      uVar7 = JAIGlobalParameter::getParamSeqParameterLines(pJVar6);
      pJVar6 = (JAIGlobalParameter *)
               checkPlayingSeqUpdateAddition
                         (this,uVar7,'\0',*(ulong *)(this_00 + 0x250),this_00 + 0x1270,
                          (ulong *)&DAT_00000004,cVar2 + '\x18',in_r10,JAudio::_886);
      uVar7 = JAIGlobalParameter::getParamSeqParameterLines(pJVar6);
      pJVar6 = (JAIGlobalParameter *)
               checkPlayingSeqUpdateMultiplication
                         (this,uVar7,'\0',*(ulong *)(this_00 + 0x254),this_00 + 0x1274,
                          (ulong *)&DAT_00000003,cVar2 + '\x10',in_r10);
      uVar7 = JAIGlobalParameter::getParamSeqParameterLines(pJVar6);
      pJVar6 = (JAIGlobalParameter *)
               checkPlayingSeqUpdateAddition
                         (this,uVar7,'\0',*(ulong *)(this_00 + 600),this_00 + 0x1278,(ulong *)0x5,
                          cVar2 + '\x14',in_r10,JAudio::_887);
      uVar7 = JAIGlobalParameter::getParamSeqParameterLines(pJVar6);
      uVar9 = *(ulong *)(this_00 + 0x25c);
      pfVar11 = (float *)(iVar19 + 0x1c);
      checkPlayingSeqUpdateAddition
                (this,uVar7,'\0',uVar9,this_00 + 0x127c,(ulong *)0x6,(uchar)pfVar11,in_r10,
                 JAudio::_886);
      uVar10 = (uchar)uVar9;
      if ((*(uint *)(iVar19 + 8) & 4) != 0) {
        pJVar6 = (JAIGlobalParameter *)MoveParaSet::move(this_00);
        if (pJVar6 == (JAIGlobalParameter *)0x0) {
          *(uint *)(iVar19 + 8) = *(uint *)(iVar19 + 8) ^ 4;
        }
        if (*(float *)(iVar19 + 0x20) != *(float *)(this_00 + 4)) {
          *(float *)(iVar19 + 0x20) = *(float *)(this_00 + 4);
          pSVar8 = (SeqUpdateData *)JAIGlobalParameter::getParamSeqTrackMax(pJVar6);
          pJVar6 = (JAIGlobalParameter *)
                   SystemInterface::setSeqPortargsF32
                             ((SystemInterface *)(_seqTrackInfo + iVar18),pSVar8,9,uVar10,
                              *(float *)(this_00 + 4));
          iVar4 = JAIGlobalParameter::getParamSeqTrackMax(pJVar6);
          *(uint *)(iVar3 + iVar4 * 4) = *(uint *)(iVar3 + iVar4 * 4) | 0x80;
        }
      }
      if ((*(uint *)(iVar19 + 8) & 0x10) != 0) {
        for (bVar15 = 0; bVar15 < 0x10; bVar15 = bVar15 + 1) {
          uVar13 = 1 << (uint)bVar15;
          if (((*(uint *)(this_00 + 0x1268) & uVar13) != 0) &&
             (iVar4 = MoveParaSet::move(this_00 + (uint)bVar15 * 0x10 + 0x10), iVar4 == 0)) {
            *(uint *)(this_00 + 0x1268) = *(uint *)(this_00 + 0x1268) ^ uVar13;
          }
          uVar7 = (uint)bVar15 << 0x10;
          JASystem::TTrack::readPortApp((TTrack *)(this_00 + 0x1360),uVar7,local_98);
          uVar13 = (uint)*(float *)(this_00 + (uint)bVar15 * 0x10 + 0x14);
          local_78 = (double)(longlong)(int)uVar13;
          if ((uint)local_98[0] != (uVar13 & 0xffff)) {
            JASystem::TTrack::writePortApp((TTrack *)(this_00 + 0x1360),uVar7,(ushort)uVar13);
          }
        }
        if (*(int *)(this_00 + 0x1268) == 0) {
          *(uint *)(iVar19 + 8) = *(uint *)(iVar19 + 8) ^ 0x10;
        }
      }
      pJVar6 = *(JAIGlobalParameter **)(iVar19 + 8);
      if (((uint)pJVar6 & 0x20) != 0) {
        *(uint *)(iVar19 + 8) = (uint)pJVar6 ^ 0x20;
        for (pJVar5 = (JAISound *)0x0; uVar13 = JAIGlobalParameter::getParamSeqTrackMax(pJVar6),
            ((uint)pJVar5 & 0xff) < uVar13; pJVar5 = (JAISound *)&pJVar5->field_0x1) {
          iVar4 = ((uint)pJVar5 & 0xff) + 0x133c;
          MVar1 = this_00[iVar4];
          pJVar6 = (JAIGlobalParameter *)((byte)MVar1 >> 5 & 1);
          if ((((byte)MVar1 >> 5 & 1) != 0) &&
             (pJVar6 = (JAIGlobalParameter *)((byte)MVar1 >> 6 & 1),
             (char)MVar1 < '\0' != (((byte)MVar1 >> 6 & 1) != 0))) {
            this_02 = (TTrack *)
                      SystemInterface::trackToSeqp
                                (*(SystemInterface **)(iVar19 + 0x48),pJVar5,(uchar)MVar1);
            if (this_02 != (TTrack *)0x0) {
              JASystem::TTrack::muteTrack(this_02,((byte)this_00[iVar4] >> 6 & 1) != 0);
            }
            bVar15 = (byte)this_00[iVar4] >> 6;
            pJVar6 = (JAIGlobalParameter *)(bVar15 & 1);
            this_00[iVar4] =
                 (MoveParaSet)(((bVar15 & 1) != 0) * -0x80 | (byte)this_00[iVar4] & 0x7f);
          }
        }
      }
      checkPlayingSeqUpdateTrack
                (this,0x40,(ulong)(this_00 + 0x260),this_00 + 0x1280,(ulong *)&DAT_00000002,
                 (uchar)*(undefined4 *)(iVar19 + 0x24),pfVar11);
      checkPlayingSeqUpdateTrack
                (this,0x80,(ulong)(this_00 + 0x460),this_00 + 0x1284,(ulong *)&DAT_00000004,
                 (uchar)*(undefined4 *)(iVar19 + 0x30),pfVar11);
      checkPlayingSeqUpdateTrack
                (this,0x200,(ulong)(this_00 + 0x660),this_00 + 0x1288,(ulong *)&DAT_00000003,
                 (uchar)*(undefined4 *)(iVar19 + 0x28),pfVar11);
      checkPlayingSeqUpdateTrack
                (this,0x800,(ulong)(this_00 + 0x860),this_00 + 0x128c,(ulong *)0x5,
                 (uchar)*(undefined4 *)(iVar19 + 0x2c),pfVar11);
      uVar7 = 6;
      checkPlayingSeqUpdateTrack
                (this,0x100,(ulong)(this_00 + 0xa60),this_00 + 0x1290,(ulong *)0x6,
                 (uchar)*(undefined4 *)(iVar19 + 0x34),pfVar11);
      pJVar6 = *(JAIGlobalParameter **)(iVar19 + 8);
      if (((uint)pJVar6 & 0x800000) != 0) {
        *(uint *)(iVar19 + 8) = (uint)pJVar6 ^ 0x800000;
        for (uVar13 = 0;
            pJVar6 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeqTrackMax(pJVar6),
            (JAIGlobalParameter *)(uVar13 & 0xff) < pJVar6; uVar13 = uVar13 + 1) {
          pSVar8 = (SeqUpdateData *)(uVar13 & 0xff);
          if (this_00[(int)(pSVar8 + 0x131c)] == (MoveParaSet)0x1) {
            *(uint *)(iVar3 + (int)pSVar8 * 4) = *(uint *)(iVar3 + (int)pSVar8 * 4) | 0x40;
            pJVar6 = (JAIGlobalParameter *)
                     SystemInterface::setSeqPortargsU32
                               ((SystemInterface *)(_seqTrackInfo + iVar18),pSVar8,8,'\x01',uVar7);
            this_00[(int)(pSVar8 + 0x131c)] = (MoveParaSet)0x0;
          }
        }
      }
      if ((*(uint *)(iVar19 + 8) & 0x1000) != 0) {
        bVar15 = 0;
        while( true ) {
          uVar13 = JAIGlobalParameter::getParamSeqTrackMax(pJVar6);
          if (uVar13 <= bVar15) break;
          pJVar6 = *(JAIGlobalParameter **)(this_00 + 0x1298);
          uVar13 = 1 << (uint)bVar15;
          if (((uint)pJVar6 & uVar13) != 0) {
            *(uint *)(this_00 + 0x1298) = (uint)pJVar6 ^ uVar13;
            pJVar6 = (JAIGlobalParameter *)((uint)bVar15 * 4);
            pJVar12 = pJVar6 + 0x129c;
            for (bVar17 = 0; bVar17 < 0x10; bVar17 = bVar17 + 1) {
              pJVar6 = (JAIGlobalParameter *)&DAT_00000001;
              if ((*(uint *)(this_00 + (int)pJVar12) & 1 << (uint)bVar17) != 0) {
                uVar7 = JAISound::getTrackPortRoute(*(JAISound **)(iVar19 + 0x48),bVar15,bVar17);
                pJVar6 = (JAIGlobalParameter *)
                         JASystem::TTrack::writePortApp
                                   ((TTrack *)(this_00 + 0x1360),uVar7,
                                    *(ushort *)
                                     (this_00 + (uint)bVar17 * 2 + 0xe60 + (uint)bVar15 * 0x20));
                *(uint *)(this_00 + (int)pJVar12) =
                     *(uint *)(this_00 + (int)pJVar12) ^ 1 << (uint)bVar17;
              }
            }
          }
          bVar15 = bVar15 + 1;
        }
        if (*(int *)(this_00 + 0x1298) == 0) {
          *(uint *)(iVar19 + 8) = *(uint *)(iVar19 + 8) ^ 0x1000;
        }
      }
    }
  }
LAB_80297de0:
  __psq_l0(auStack8,uVar20);
  __psq_l1(auStack8,uVar20);
  __psq_l0(auStack24,uVar20);
  __psq_l1(auStack24,uVar20);
  __psq_l0(auStack40,uVar20);
  __psq_l1(auStack40,uVar20);
  __psq_l0(auStack56,uVar20);
  __psq_l1(auStack56,uVar20);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::stopSeq(JAISound *) */

void __thiscall SequenceMgr::stopSeq(SequenceMgr *this,JAISound *param_1)

{
  JAIGlobalParameter *this_00;
  uint uVar1;
  uchar extraout_r4;
  JAISound *this_01;
  uint uVar2;
  int iVar3;
  
  this_00 = (JAIGlobalParameter *)JAISound::getSwBit((JAISound *)this);
  if (((uint)this_00 & 1) != 0) {
    iVar3 = 0;
    for (uVar2 = 0; uVar1 = JAIGlobalParameter::getParamSeqPlayTrackMax(this_00), uVar2 < uVar1;
        uVar2 = uVar2 + 1) {
      this_01 = *(JAISound **)(_seqTrackInfo + iVar3 + 0x48);
      this_00 = _seqTrackInfo;
      if ((((JAISound *)this != this_01) && (this_01 != (JAISound *)0x0)) &&
         (this_00 = (JAIGlobalParameter *)JAISound::getSwBit(this_01), ((uint)this_00 & 2) == 0)) {
        this_00 = (JAIGlobalParameter *)JAISound::setSeqInterVolume(this_01,'\n',JAudio::_885,10);
      }
      iVar3 = iVar3 + 0x50;
    }
  }
  *(undefined4 *)(this + 0x38) = 0;
  iVar3 = JAISound::getSeqParameter((JAISound *)this);
  *(undefined4 *)(iVar3 + 0x135c) = 0;
  if (2 < (byte)this[5]) {
    iVar3 = JAISound::getSeqParameter((JAISound *)this);
    HeapMgr::releaseAutoHeapPointer((HeapMgr *)(uint)*(byte *)(iVar3 + 0x1260),extraout_r4);
  }
  this[5] = (SequenceMgr)0x0;
  LinkSound::releaseSound((LinkSound *)&seqControl,(JAISound *)this);
  *(undefined4 *)(_seqTrackInfo + (uint)(byte)this[4] * 0x50 + 0x48) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::checkDvdLoadArc(unsigned long,
                                                    unsigned long) */

uint __thiscall SequenceMgr::checkDvdLoadArc(SequenceMgr *this,ulong param_1,ulong param_2)

{
  JAIBasic *pJVar1;
  uint uVar2;
  uint uVar3;
  uchar uVar4;
  uchar extraout_r4;
  HeapMgr *this_00;
  int iVar5;
  undefined8 uVar6;
  
  uVar6 = CONCAT44(this,param_1);
  uVar2 = param_1 & 0xff;
  this_00 = (HeapMgr *)(param_1 >> 8 & 0xff);
  if (this_00 != (HeapMgr *)0xff) {
    uVar6 = HeapMgr::setAutoHeapLoadedFlag(this_00,'\0',(uchar)param_2);
  }
  uVar3 = (uint)((ulonglong)uVar6 >> 0x20);
  uVar4 = (uchar)uVar6;
  if (uVar2 < 0xfe) {
    pJVar1 = (JAIBasic *)(_seqTrackInfo + uVar2 * 0x50);
    iVar5 = *(int *)(pJVar1 + 0x48);
    pJVar1[3] = (JAIBasic)0x0;
    if ((iVar5 != 0) && (*(char *)(iVar5 + 5) == '\x01')) {
      pJVar1 = (JAIBasic *)JAIBasic::getInterface(pJVar1);
      uVar2 = JAIBasic::getSoundOffsetNumberFromID(pJVar1,*(ulong *)(iVar5 + 0xc));
      uVar4 = extraout_r4;
      if ((param_1 >> 0x10 & 0x3ff) == (uVar2 & 0xffff)) {
        *(undefined *)(iVar5 + 5) = 2;
        return uVar2;
      }
    }
    uVar3 = HeapMgr::releaseAutoHeapPointer(this_00,uVar4);
  }
  else {
    if (uVar2 == 0xfe) {
      uVar3 = HeapMgr::releaseAutoHeapPointer(this_00,uVar4);
    }
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::storeSeqBuffer(JAISound * *,
                                                   Actor *,
                                                   unsigned long,
                                                   unsigned long,
                                                   unsigned char,
                                                   void *) */

void __thiscall
SequenceMgr::storeSeqBuffer
          (SequenceMgr *this,JAISound **param_1,Actor *param_2,ulong param_3,ulong param_4,
          uchar param_5,void *param_6)

{
  byte bVar1;
  JAISound *pJVar2;
  int iVar3;
  JAIGlobalParameter *pJVar4;
  uint uVar5;
  JAISound *extraout_r4;
  JAISound *extraout_r4_00;
  undefined3 in_register_00000020;
  uint *puVar6;
  JAIGlobalParameter *pJVar7;
  uint uVar8;
  int iVar9;
  JAISound *this_00;
  uint uVar10;
  int iVar11;
  undefined8 uVar12;
  
  puVar6 = (uint *)CONCAT31(in_register_00000020,param_5);
  bVar1 = *(byte *)((int)puVar6 + 5);
  uVar10 = (uint)bVar1;
  if ((this != (SequenceMgr *)0x0) && (pJVar2 = *(JAISound **)this, pJVar2 != (JAISound *)0x0)) {
    if (uVar10 == *(byte *)&pJVar2->field_0x4) {
      iVar9 = JAISound::checkSoundHandle(pJVar2,(ulong)param_2,puVar6);
      if (iVar9 != 0) {
        return;
      }
    }
    else {
      JAISound::stop(pJVar2,0);
    }
  }
  pJVar4 = _seqTrackInfo;
  iVar11 = uVar10 * 0x50;
  iVar9 = iVar11 + 0x48;
  pJVar2 = *(JAISound **)(_seqTrackInfo + iVar9);
  if (pJVar2 != (JAISound *)0x0) {
    if (*(char *)&pJVar2->field_0x5 == '\x05') {
      iVar3 = JAISound::getSeqParameter(pJVar2);
      JASystem::TTrack::stopSeq((TTrack *)(iVar3 + 0x1360));
      JAISound::clearMainSoundPPointer(*(JAISound **)(pJVar4 + iVar9));
      stopSeq(*(SequenceMgr **)(pJVar4 + iVar9),extraout_r4);
    }
    else {
      if (*(char *)&pJVar2->field_0x5 == '\x01') {
        *(undefined4 *)this = 0;
        return;
      }
      if (*(byte *)(puVar6 + 1) < *(byte *)(*(int *)(pJVar2 + 2) + 4)) {
        *(undefined4 *)this = 0;
        return;
      }
      iVar3 = JAISound::getSeqParameter(pJVar2);
      JASystem::TTrack::stopSeq((TTrack *)(iVar3 + 0x1360));
      JAISound::clearMainSoundPPointer(*(JAISound **)(pJVar4 + iVar9));
      stopSeq(*(SequenceMgr **)(pJVar4 + iVar9),extraout_r4_00);
    }
  }
  pJVar2 = (JAISound *)LinkSound::getSound((LinkSound *)&seqControl);
  if (pJVar2 == (JAISound *)0x0) {
    *(undefined4 *)this = 0;
  }
  else {
    uVar12 = JAISound::getSeqParameter(pJVar2);
    SeqParameter::init((SeqParameter *)((ulonglong)uVar12 >> 0x20),(EVP_PKEY_CTX *)uVar12);
    *(JAISound **)(pJVar4 + iVar9) = pJVar2;
    *(Actor **)(*(int *)(pJVar4 + iVar9) + 0xc) = param_2;
    pJVar7 = _seqTrackInfo + iVar11;
    iVar3 = JAISound::getSeqParameter(*(JAISound **)(pJVar4 + iVar9));
    *(JAIGlobalParameter **)(iVar3 + 0x135c) = pJVar7;
    *(byte *)(*(int *)(pJVar4 + iVar9) + 4) = bVar1;
    *(undefined4 *)(_seqTrackInfo + iVar11 + 8) = 1;
    iVar9 = 0;
    _seqTrackInfo[iVar11 + 2] = (JAIGlobalParameter)0x0;
    pJVar4 = _seqTrackInfo + iVar11;
    *(undefined4 *)(pJVar4 + 4) = 0;
    if ((*puVar6 & 1) != 0) {
      for (uVar8 = 0; uVar5 = JAIGlobalParameter::getParamSeqPlayTrackMax(pJVar4), uVar8 < uVar5;
          uVar8 = uVar8 + 1) {
        this_00 = *(JAISound **)(_seqTrackInfo + iVar9 + 0x48);
        pJVar4 = _seqTrackInfo;
        if (((uVar8 != uVar10) && (this_00 != (JAISound *)0x0)) &&
           (pJVar4 = (JAIGlobalParameter *)JAISound::getSwBit(this_00), ((uint)pJVar4 & 2) == 0)) {
          pJVar4 = (JAIGlobalParameter *)JAISound::setSeqInterVolume(this_00,'\n',JAudio::_887,10);
        }
        iVar9 = iVar9 + 0x50;
      }
    }
    JAISound::initParameter
              (pJVar2,(JAISound **)this,(Actor *)param_1,(ulong)param_2,param_3,(uchar)param_4,
               puVar6);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::releaseSeqBuffer(JAISound *,
                                                     unsigned long) */

void __thiscall
SequenceMgr::releaseSeqBuffer(SequenceMgr *this,JAISound *param_1,ulong param_2)

{
  SequenceMgr SVar1;
  int iVar2;
  uchar extraout_r4_00;
  JAISound *extraout_r4;
  
  SVar1 = this[5];
  if (((byte)SVar1 < 4) || (param_1 == (JAISound *)0x0)) {
    if ((byte)SVar1 < 3) {
      if (SVar1 != (SequenceMgr)0x0) {
        iVar2 = JAISound::getSeqParameter((JAISound *)this);
        HeapMgr::releaseAutoHeapPointer((HeapMgr *)(uint)*(byte *)(iVar2 + 0x1260),extraout_r4_00);
      }
    }
    else {
      iVar2 = JAISound::getSeqParameter((JAISound *)this);
      JASystem::TTrack::stopSeq((TTrack *)(iVar2 + 0x1360));
    }
    JAISound::clearMainSoundPPointer((JAISound *)this);
    stopSeq(this,extraout_r4);
  }
  else {
    iVar2 = _seqTrackInfo + (uint)(byte)this[4] * 0x50;
    *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | 2;
    *(JAISound **)(*(int *)(_seqTrackInfo + (uint)(byte)this[4] * 0x50 + 0x48) + 0x14) = param_1;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SequenceMgr::getPlayTrackInfo(unsigned long) */

int __thiscall SequenceMgr::getPlayTrackInfo(SequenceMgr *this,ulong param_1)

{
  return _seqTrackInfo + (int)this * 0x50;
}


/* __thiscall MuteBit::MuteBit(void) */

void __thiscall MuteBit::MuteBit(MuteBit *this)

{
  *this = (MuteBit)((byte)*this & 0x7f);
  *this = (MuteBit)((byte)*this & 0xdf);
  return;
}


namespace Kernel {

/* __thiscall TPortCmd::~TPortCmd(void) */

void __thiscall TPortCmd::_TPortCmd(TPortCmd *this)

{
  short in_r4;
  
  if ((this != (TPortCmd *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

}
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::getInterface(void) */

undefined4 __thiscall JAIBasic::getInterface(JAIBasic *this)

{
  return _msBasic;
}


namespace JAInter {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80298574) */
/* WARNING: Removing unreachable block (ram,0x8029856c) */
/* WARNING: Removing unreachable block (ram,0x8029857c) */
/* __thiscall SeqParameter::init(void) */

int __thiscall SeqParameter::init(SeqParameter *this,EVP_PKEY_CTX *ctx)

{
  float fVar1;
  JAIGlobalParameter *pJVar2;
  uint uVar3;
  float *pfVar4;
  SeqParameter *pSVar5;
  uint uVar6;
  JAIGlobalParameter *pJVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined8 in_f29;
  double dVar13;
  undefined8 in_f30;
  double dVar14;
  undefined8 in_f31;
  double dVar15;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  pJVar2 = (JAIGlobalParameter *)
           JASystem::TTrack::assignExtBuffer
                     ((TTrack *)(this + 0x1360),(TOuterParam *)(this + 0x16ec));
  *(undefined4 *)(this + 0x1264) = 0xffffffff;
  fVar1 = JAudio::_885;
  dVar15 = (double)JAudio::_885;
  *(float *)(this + 4) = JAudio::_885;
  *(float *)this = fVar1;
  *(undefined4 *)(this + 0xc) = 0;
  this[0x1261] = (SeqParameter)0x0;
  *(undefined2 *)(this + 0x1262) = 0;
  *(undefined4 *)(this + 0x1268) = 0;
  *(undefined4 *)(this + 0x126c) = 0;
  *(undefined4 *)(this + 0x1270) = 0;
  *(undefined4 *)(this + 0x1274) = 0;
  *(undefined4 *)(this + 0x1278) = 0;
  *(undefined4 *)(this + 0x127c) = 0;
  *(undefined4 *)(this + 0x1280) = 0;
  *(undefined4 *)(this + 0x1284) = 0;
  *(undefined4 *)(this + 0x1288) = 0;
  *(undefined4 *)(this + 0x128c) = 0;
  *(undefined4 *)(this + 0x1290) = 0;
  *(undefined4 *)(this + 0x1294) = 0;
  *(undefined4 *)(this + 0x1298) = 0;
  iVar10 = 0;
  iVar9 = 0;
  iVar8 = 0;
  dVar14 = (double)JAudio::_886;
  dVar13 = (double)JAudio::_887;
  for (uVar6 = 0; uVar3 = JAIGlobalParameter::getParamSeqTrackMax(pJVar2), fVar1 = JAudio::_887,
      uVar6 < uVar3; uVar6 = uVar6 + 1) {
    pSVar5 = this + iVar8;
    *(float *)(pSVar5 + 0x264) = (float)dVar15;
    *(float *)(pSVar5 + 0x260) = (float)dVar15;
    *(undefined4 *)(pSVar5 + 0x26c) = 0;
    *(float *)(pSVar5 + 0x464) = (float)dVar14;
    *(float *)(pSVar5 + 0x460) = (float)dVar14;
    *(undefined4 *)(pSVar5 + 0x46c) = 0;
    *(float *)(pSVar5 + 0x664) = (float)dVar15;
    *(float *)(pSVar5 + 0x660) = (float)dVar15;
    *(undefined4 *)(pSVar5 + 0x66c) = 0;
    *(float *)(pSVar5 + 0x864) = (float)dVar13;
    *(float *)(pSVar5 + 0x860) = (float)dVar13;
    *(undefined4 *)(pSVar5 + 0x86c) = 0;
    *(float *)(pSVar5 + 0xa64) = (float)dVar14;
    *(float *)(pSVar5 + 0xa60) = (float)dVar14;
    *(undefined4 *)(pSVar5 + 0xa6c) = 0;
    *(float *)(pSVar5 + 0xc64) = (float)dVar13;
    *(float *)(pSVar5 + 0xc60) = (float)dVar13;
    *(undefined4 *)(pSVar5 + 0xc6c) = 0;
    this[uVar6 + 0x131c] = (SeqParameter)0x0;
    *(undefined4 *)(this + iVar9 + 0x129c) = 0;
    pJVar2 = (JAIGlobalParameter *)0x0;
    iVar11 = 0x10;
    do {
      *(undefined2 *)(this + iVar10 + (int)(pJVar2 + 0xe60)) = 0;
      pJVar2 = pJVar2 + 2;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    iVar10 = iVar10 + 0x20;
    iVar9 = iVar9 + 4;
    iVar8 = iVar8 + 0x10;
  }
  pJVar2 = (JAIGlobalParameter *)0x0;
  iVar8 = 0x10;
  do {
    pSVar5 = this + (int)pJVar2;
    *(float *)(pSVar5 + 0x14) = fVar1;
    *(float *)(pSVar5 + 0x10) = fVar1;
    *(undefined4 *)(pSVar5 + 0x1c) = 0;
    pJVar2 = pJVar2 + 0x10;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar8 = 0;
  dVar13 = (double)JAudio::_885;
  for (pJVar7 = (JAIGlobalParameter *)0x0;
      pJVar2 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeqPlayTrackMax(pJVar2),
      pJVar7 < pJVar2 + 0xc; pJVar7 = pJVar7 + 1) {
    pJVar2 = (JAIGlobalParameter *)(this + iVar8);
    *(float *)((SeqParameter *)pJVar2 + 0x114) = (float)dVar13;
    *(float *)((SeqParameter *)pJVar2 + 0x110) = (float)dVar13;
    *(undefined4 *)((SeqParameter *)pJVar2 + 0x11c) = 0;
    iVar8 = iVar8 + 0x10;
  }
  iVar8 = 0;
  dVar13 = (double)JAudio::_886;
  dVar14 = (double)JAudio::_885;
  dVar15 = (double)JAudio::_887;
  for (uVar6 = 0; uVar3 = JAIGlobalParameter::getParamSeqParameterLines(pJVar2),
      uVar6 < (uVar3 & 0xff); uVar6 = uVar6 + 1) {
    pfVar4 = (float *)(*(int *)(this + 0x250) + iVar8);
    pfVar4[1] = (float)dVar13;
    *pfVar4 = (float)dVar13;
    pJVar2 = (JAIGlobalParameter *)0x0;
    pfVar4[3] = 0.0;
    pfVar4 = (float *)(*(int *)(this + 0x254) + iVar8);
    pfVar4[1] = (float)dVar14;
    *pfVar4 = (float)dVar14;
    pfVar4[3] = 0.0;
    pfVar4 = (float *)(*(int *)(this + 600) + iVar8);
    pfVar4[1] = (float)dVar15;
    *pfVar4 = (float)dVar15;
    pfVar4[3] = 0.0;
    pfVar4 = (float *)(*(int *)(this + 0x25c) + iVar8);
    pfVar4[1] = (float)dVar13;
    *pfVar4 = (float)dVar13;
    pfVar4[3] = 0.0;
    iVar8 = iVar8 + 0x10;
  }
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  __psq_l0(auStack40,uVar12);
  __psq_l1(auStack40,uVar12);
  return uVar3;
}

