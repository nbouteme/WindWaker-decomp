#include <JAudio/JAISeMgr.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAudio/JAIGlobalParameter.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JAISound.h>
#include <JAudio/JAISeMgr.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JAudio/JAIBasic.h>
#include <mtx/mtxvec.h>
#include <JAudio/JASTrack.h>
#include <JAudio/JAISequenceMgr.h>
#include <JAudio/JAISystemInterface.h>
#include <JAudio/JASCmdStack.h>
#include <JAInter/SeMgr.h>
#include <JAInter/MoveParaSetInitZero.h>
#include <JAInter/MoveParaSetInitHalf.h>
#include <JAInter/SeParameter.h>
#include <Demangler/JAInter/MoveParaSet.h>


namespace JAInter {
undefined1 SeMgr;
undefined1 SeMgr;
undefined1 SeMgr;
undefined1 SeMgr;
undefined1 SeMgr;
undefined1 SeMgr;
undefined1 SeMgr;
undefined1 SeMgr;
undefined1 SeMgr;
undefined1 SeMgr;
undefined1 SeMgr;
undefined1 SeMgr;

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80293348) */
/* WARNING: Removing unreachable block (ram,0x80293340) */
/* WARNING: Removing unreachable block (ram,0x80293350) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SeMgr::init(void) */

int __thiscall SeMgr::init(SeMgr *this,EVP_PKEY_CTX *ctx)

{
  JAIGlobalParameter *pJVar1;
  JAIGlobalParameter *this_00;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  JAIGlobalParameter *pJVar9;
  int iVar10;
  undefined4 uVar11;
  undefined8 in_f29;
  double dVar12;
  undefined8 in_f30;
  double dVar13;
  undefined8 in_f31;
  double dVar14;
  undefined8 uVar15;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  piVar2 = _msBasic;
  if (_msBasic[7] != 0) {
    pJVar1 = (JAIGlobalParameter *)
             JAIGlobalParameter::setParamSeTrackMax((JAIGlobalParameter *)0x0,(ulong)ctx);
    iVar8 = 0;
    for (piVar7 = (int *)0x0; piVar2 = (int *)JAIGlobalParameter::getParamSoundSceneMax(pJVar1),
        piVar7 < piVar2; piVar7 = (int *)((int)piVar7 + 1)) {
      pJVar9 = (JAIGlobalParameter *)0x0;
      iVar3 = 0;
      for (pJVar1 = (JAIGlobalParameter *)0x0;
          this_00 = (JAIGlobalParameter *)
                    JAIGlobalParameter::getParamSeCategoryMax((JAIGlobalParameter *)piVar2),
          pJVar1 < this_00; pJVar1 = pJVar1 + 1) {
        piVar2 = *(int **)(iVar8 + _msBasic[7]);
        pJVar9 = pJVar9 + (byte)*(JAIGlobalParameter *)((int)piVar2 + iVar3);
        iVar3 = iVar3 + 2;
      }
      uVar15 = JAIGlobalParameter::getParamSeTrackMax(this_00);
      pJVar1 = (JAIGlobalParameter *)((ulonglong)uVar15 >> 0x20);
      if (pJVar1 < pJVar9) {
        pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::setParamSeTrackMax(pJVar9,(ulong)uVar15);
      }
      iVar8 = iVar8 + 4;
    }
  }
  if ((_msCurrentHeap == 0) &&
     (piVar2 = (int *)m_Do_printf::OSReport
                                (
                                "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                                ), _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    piVar2 = (int *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_8036920d);
  }
  iVar8 = _msCurrentHeap;
  iVar3 = JAIGlobalParameter::getParamSeCategoryMax((JAIGlobalParameter *)piVar2);
  pJVar1 = (JAIGlobalParameter *)JKernel::operator_new__(iVar3 * 0xc,iVar8,0x20);
  _seRegist = pJVar1;
  if ((pJVar1 == (JAIGlobalParameter *)0x0) &&
     (pJVar1 = (JAIGlobalParameter *)
               m_Do_printf::OSReport("JAIData::initHeap Cannot Alloc Heap!!\n"),
     _seRegist == (JAIGlobalParameter *)0x0)) {
    JUTAssertion::showAssert(3,"JAISeMgr.cpp",0x3f,"seRegist");
    pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISeMgr.cpp",0x3f,&DAT_8036920d);
  }
  if ((_msCurrentHeap == 0) &&
     (pJVar1 = (JAIGlobalParameter *)
               m_Do_printf::OSReport
                         (
                         "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                         ), _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_8036920d);
  }
  iVar8 = _msCurrentHeap;
  iVar3 = JAIGlobalParameter::getParamSeCategoryMax(pJVar1);
  pJVar1 = (JAIGlobalParameter *)JKernel::operator_new__(iVar3 << 2,iVar8,0x20);
  _sePlaySound = pJVar1;
  if ((pJVar1 == (JAIGlobalParameter *)0x0) &&
     (pJVar1 = (JAIGlobalParameter *)
               m_Do_printf::OSReport("JAIData::initHeap Cannot Alloc Heap!!\n"),
     _sePlaySound == (JAIGlobalParameter *)0x0)) {
    JUTAssertion::showAssert(3,"JAISeMgr.cpp",0x41,"sePlaySound");
    pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISeMgr.cpp",0x41,&DAT_8036920d);
  }
  if ((_msCurrentHeap == 0) &&
     (pJVar1 = (JAIGlobalParameter *)
               m_Do_printf::OSReport
                         (
                         "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                         ), _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_8036920d);
  }
  iVar8 = _msCurrentHeap;
  iVar3 = JAIGlobalParameter::getParamSeCategoryMax(pJVar1);
  pJVar1 = (JAIGlobalParameter *)JKernel::operator_new__(iVar3 << 2,iVar8,0x20);
  _seRegistBuffer = pJVar1;
  if ((pJVar1 == (JAIGlobalParameter *)0x0) &&
     (pJVar1 = (JAIGlobalParameter *)
               m_Do_printf::OSReport("JAIData::initHeap Cannot Alloc Heap!!\n"),
     _seRegistBuffer == (JAIGlobalParameter *)0x0)) {
    JUTAssertion::showAssert(3,"JAISeMgr.cpp",0x43,"seRegistBuffer");
    pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISeMgr.cpp",0x43,&DAT_8036920d);
  }
  iVar3 = 0;
  iVar8 = 0;
  for (pJVar9 = (JAIGlobalParameter *)0x0;
      pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeCategoryMax(pJVar1),
      piVar2 = _msBasic, pJVar9 < pJVar1; pJVar9 = pJVar9 + 1) {
    uVar4 = JAIGlobalParameter::getParamSeRegistMax(pJVar1);
    uVar4 = (**(code **)(*piVar2 + 8))(piVar2,uVar4);
    *(undefined4 *)(_seRegistBuffer + iVar8) = uVar4;
    pJVar1 = _seRegistBuffer;
    if ((*(int *)(_seRegistBuffer + iVar8) == 0) &&
       (m_Do_printf::OSReport("JAIData::initHeap Cannot Alloc Heap!!\n"), pJVar1 = _seRegistBuffer,
       *(int *)(_seRegistBuffer + iVar8) == 0)) {
      JUTAssertion::showAssert(3,"JAISeMgr.cpp",0x48,"seRegistBuffer[i]");
      pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISeMgr.cpp",0x48,&DAT_8036920d);
    }
    JAIGlobalParameter::getParamSeRegistMax(pJVar1);
    LinkSound::init((LinkSound *)(_seRegist + iVar3),*(EVP_PKEY_CTX **)(_seRegistBuffer + iVar8));
    if ((_msCurrentHeap == 0) &&
       (m_Do_printf::OSReport
                  ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
       _msCurrentHeap == 0)) {
      JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
      m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_8036920d);
    }
    uVar4 = JKernel::operator_new__(0x40,_msCurrentHeap,0x20);
    *(undefined4 *)(_sePlaySound + iVar8) = uVar4;
    if ((*(int *)(_sePlaySound + iVar8) == 0) &&
       (m_Do_printf::OSReport("JAIData::initHeap Cannot Alloc Heap!!\n"),
       *(int *)(_sePlaySound + iVar8) == 0)) {
      JUTAssertion::showAssert(3,"JAISeMgr.cpp",0x4e,"sePlaySound[i]");
      m_Do_printf::OSPanic("JAISeMgr.cpp",0x4e,&DAT_8036920d);
    }
    pJVar1 = (JAIGlobalParameter *)0x0;
    iVar10 = 0x10;
    do {
      *(undefined4 *)(pJVar1 + *(int *)(_sePlaySound + iVar8)) = 0;
      pJVar1 = pJVar1 + 4;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    iVar3 = iVar3 + 0xc;
    iVar8 = iVar8 + 4;
  }
  if ((_msCurrentHeap == 0) &&
     (pJVar1 = (JAIGlobalParameter *)
               m_Do_printf::OSReport
                         (
                         "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                         ), _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_8036920d);
  }
  iVar8 = _msCurrentHeap;
  iVar3 = JAIGlobalParameter::getParamSeTrackMax(pJVar1);
  pJVar1 = (JAIGlobalParameter *)JKernel::operator_new__(iVar3 * 0x18,iVar8,0x20);
  _seTrackUpdate = pJVar1;
  if ((pJVar1 == (JAIGlobalParameter *)0x0) &&
     (pJVar1 = (JAIGlobalParameter *)
               m_Do_printf::OSReport("JAIData::initHeap Cannot Alloc Heap!!\n"),
     _seTrackUpdate == (JAIGlobalParameter *)0x0)) {
    JUTAssertion::showAssert(3,"JAISeMgr.cpp",0x56,"seTrackUpdate");
    pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISeMgr.cpp",0x56,&DAT_8036920d);
  }
  iVar8 = 0;
  dVar12 = (double)JAudio::_969;
  dVar13 = (double)JAudio::_970;
  dVar14 = (double)JAudio::_971;
  for (pJVar9 = (JAIGlobalParameter *)0x0;
      pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeTrackMax(pJVar1), pJVar9 < pJVar1
      ; pJVar9 = pJVar9 + 1) {
    pJVar1 = _seTrackUpdate + iVar8;
    *(float *)(pJVar1 + 4) = (float)dVar12;
    *(float *)(pJVar1 + 8) = (float)dVar12;
    *(float *)(pJVar1 + 0xc) = (float)dVar13;
    *(float *)(pJVar1 + 0x10) = (float)dVar14;
    *pJVar1 = (JAIGlobalParameter)0xff;
    *(float *)(pJVar1 + 0x14) = (float)dVar13;
    iVar8 = iVar8 + 0x18;
  }
  pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeRegistMax(pJVar1);
  iVar8 = JAIGlobalParameter::getParamSeCategoryMax(pJVar1);
  if ((_msCurrentHeap == 0) &&
     (m_Do_printf::OSReport
                ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
     _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_8036920d);
  }
  uVar4 = JKernel::operator_new__(iVar8 * (int)pJVar1 * 0x444 + 0x10,_msCurrentHeap,0x20);
  pJVar9 = (JAIGlobalParameter *)
           Runtime.PPCEABI.H::__construct_new_array
                     (uVar4,SeParameter::SeParameter,0,0x444,iVar8 * (int)pJVar1);
  pJVar1 = pJVar9;
  if (pJVar9 == (JAIGlobalParameter *)0x0) {
    m_Do_printf::OSReport("JAIData::initHeap Cannot Alloc Heap!!\n");
    JUTAssertion::showAssert(3,"JAISeMgr.cpp",99,"parameterObject");
    pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISeMgr.cpp",99,&DAT_8036920d);
  }
  _seParameterUsedEndPointer = 0;
  _seParameterFreeStartPointer = pJVar9;
  *(undefined4 *)(pJVar9 + 0x43c) = 0;
  *(JAIGlobalParameter **)(pJVar9 + 0x440) = pJVar9 + 0x444;
  uVar6 = 1;
  iVar8 = 0x444;
  while( true ) {
    pJVar1 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeRegistMax(pJVar1);
    iVar3 = JAIGlobalParameter::getParamSeCategoryMax(pJVar1);
    if (iVar3 * (int)pJVar1 - 1U <= uVar6) break;
    pJVar1 = pJVar9 + iVar8;
    *(JAIGlobalParameter **)(pJVar1 + 0x43c) = pJVar9 + (uVar6 - 1) * 0x444;
    *(JAIGlobalParameter **)(pJVar1 + 0x440) = pJVar9 + (uVar6 + 1) * 0x444;
    uVar6 = uVar6 + 1;
    iVar8 = iVar8 + 0x444;
  }
  *(JAIGlobalParameter **)(pJVar9 + uVar6 * 0x444 + 0x43c) = pJVar9 + (uVar6 - 1) * 0x444;
  *(undefined4 *)(pJVar9 + uVar6 * 0x444 + 0x440) = 0;
  piVar2 = _msBasic;
  pJVar1 = (JAIGlobalParameter *)_msBasic[7];
  if ((JAIGlobalParameter *)_msBasic[7] == (JAIGlobalParameter *)0x0) {
    if ((_msCurrentHeap == 0) &&
       (piVar2 = (int *)m_Do_printf::OSReport
                                  (
                                  "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                                  ), _msCurrentHeap == 0)) {
      JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
      piVar2 = (int *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_8036920d);
    }
    iVar8 = _msCurrentHeap;
    iVar3 = JAIGlobalParameter::getParamSoundSceneMax((JAIGlobalParameter *)piVar2);
    _categoryInfoTable = (JAIGlobalParameter *)JKernel::operator_new__(iVar3 << 2,iVar8,0x20);
    if ((_categoryInfoTable == (JAIGlobalParameter *)0x0) &&
       (m_Do_printf::OSReport("JAIData::initHeap Cannot Alloc Heap!!\n"),
       _categoryInfoTable == (JAIGlobalParameter *)0x0)) {
      JUTAssertion::showAssert(3,"JAISeMgr.cpp",0x7c,"categoryInfoTable");
      m_Do_printf::OSPanic("JAISeMgr.cpp",0x7c,&DAT_8036920d);
    }
    iVar8 = 0;
    pJVar1 = (JAIGlobalParameter *)(os::_838 + 4);
    for (piVar7 = (int *)0x0; piVar2 = (int *)JAIGlobalParameter::getParamSoundSceneMax(pJVar1),
        pJVar1 = _categoryInfoTable, piVar7 < piVar2; piVar7 = (int *)((int)piVar7 + 1)) {
      *(undefined1 **)(_categoryInfoTable + iVar8) = &Const::sCInfos_0;
      iVar8 = iVar8 + 4;
    }
  }
  _categoryInfoTable = pJVar1;
  if ((_msCurrentHeap == 0) &&
     (piVar2 = (int *)m_Do_printf::OSReport
                                (
                                "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                                ), _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    piVar2 = (int *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_8036920d);
  }
  iVar8 = _msCurrentHeap;
  uVar4 = JAIGlobalParameter::getParamSeCategoryMax((JAIGlobalParameter *)piVar2);
  pJVar1 = (JAIGlobalParameter *)JKernel::operator_new__(uVar4,iVar8,0x20);
  _seEntryCancel = pJVar1;
  if ((pJVar1 == (JAIGlobalParameter *)0x0) &&
     (pJVar1 = (JAIGlobalParameter *)
               m_Do_printf::OSReport
                         ("JAIBasic::initAllocParameter Cannot Alloc Heap!! (seEntryCancel)\n"),
     _seEntryCancel == (JAIGlobalParameter *)0x0)) {
    JUTAssertion::showAssert(3,"JAISeMgr.cpp",0x84,"seEntryCancel");
    pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISeMgr.cpp",0x84,&DAT_8036920d);
  }
  if ((_msCurrentHeap == 0) &&
     (pJVar1 = (JAIGlobalParameter *)
               m_Do_printf::OSReport
                         (
                         "JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"
                         ), _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_8036920d);
  }
  iVar8 = _msCurrentHeap;
  iVar3 = JAIGlobalParameter::getParamSeCategoryMax(pJVar1);
  pJVar1 = (JAIGlobalParameter *)JKernel::operator_new__(iVar3 << 2,iVar8,0x20);
  _seCategoryVolume = pJVar1;
  if ((pJVar1 == (JAIGlobalParameter *)0x0) &&
     (pJVar1 = (JAIGlobalParameter *)
               m_Do_printf::OSReport
                         ("JAIBasic::initAllocParameter Cannot Alloc Heap!!(seCategoryVolume)\n"),
     _seCategoryVolume == (JAIGlobalParameter *)0x0)) {
    JUTAssertion::showAssert(3,"JAISeMgr.cpp",0x86,"seCategoryVolume");
    pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISeMgr.cpp",0x86,&DAT_8036920d);
  }
  iVar8 = 0;
  dVar12 = (double)JAudio::_969;
  for (uVar6 = 0; uVar5 = JAIGlobalParameter::getParamSeCategoryMax(pJVar1), uVar6 < uVar5;
      uVar6 = uVar6 + 1) {
    _seEntryCancel[uVar6] = (JAIGlobalParameter)0x0;
    pJVar1 = _seCategoryVolume;
    *(float *)(_seCategoryVolume + iVar8) = (float)dVar12;
    iVar8 = iVar8 + 4;
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  __psq_l0(auStack40,uVar11);
  __psq_l1(auStack40,uVar11);
  return uVar5;
}


/* __thiscall SeParameter::SeParameter(void) */

void __thiscall SeParameter::SeParameter(SeParameter *this)

{
  Runtime.PPCEABI.H::__construct_array
            (this + 0x24,MoveParaSet::__defctor,(undefined *)0x0,0x10,0x10);
  Runtime.PPCEABI.H::__construct_array(this + 0x124,MoveParaSet::__defctor,(undefined *)0x0,0x10,8);
  Runtime.PPCEABI.H::__construct_array
            (this + 0x1a4,MoveParaSetInitHalf::MoveParaSetInitHalf,(undefined *)0x0,0x10,8);
  Runtime.PPCEABI.H::__construct_array(this + 0x224,MoveParaSet::__defctor,(undefined *)0x0,0x10,8);
  Runtime.PPCEABI.H::__construct_array
            (this + 0x2a4,MoveParaSetInitZero::MoveParaSetInitZero,(undefined *)0x0,0x10,8);
  Runtime.PPCEABI.H::__construct_array
            (this + 0x324,MoveParaSetInitZero::MoveParaSetInitZero,(undefined *)0x0,0x10,8);
  Runtime.PPCEABI.H::__construct_array(this + 0x3a4,MoveParaSet::__defctor,(undefined *)0x0,0x10,8);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SeMgr::startSeSequence(void) */

void __thiscall SeMgr::startSeSequence(SeMgr *this)

{
  _seHandle = 0;
  JAIBasic::startSoundActor
            (_msBasic,(JAISoundInfoID)&DAT_80000800,(JAISound **)&seHandle,(Actor *)0x0,1,'\x04');
  if ((_seHandle == 0) &&
     (m_Do_printf::OSReport("SEシーケンスの再生に失敗しました。\n"), _seHandle == 0)
     ) {
    JUTAssertion::showAssert(3,"JAISeMgr.cpp",0x95,"JAISeMgr::seHandle");
    m_Do_printf::OSPanic("JAISeMgr.cpp",0x95,&DAT_8036920d);
  }
  return;
}


/* __thiscall SeMgr::processGFrameSe(void) */

void __thiscall SeMgr::processGFrameSe(SeMgr *this)

{
  SeMgr *pSVar1;
  
  pSVar1 = (SeMgr *)checkNextFrameSe(this);
  pSVar1 = (SeMgr *)checkPlayingSe(pSVar1);
  checkSeMovePara(pSVar1);
  return;
}


/* WARNING: Inlined function: FUN_80328f14 */
/* WARNING: Inlined function: FUN_80328f60 */
/* WARNING: Removing unreachable block (ram,0x80293c6c) */
/* WARNING: Removing unreachable block (ram,0x80293c5c) */
/* WARNING: Removing unreachable block (ram,0x80293c54) */
/* WARNING: Removing unreachable block (ram,0x80293c64) */
/* WARNING: Removing unreachable block (ram,0x80293c74) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SeMgr::checkNextFrameSe(void) */

void __thiscall SeMgr::checkNextFrameSe(SeMgr *this)

{
  SeMgr SVar1;
  uint uVar2;
  JAIGlobalParameter *pJVar3;
  JAIGlobalParameter *pJVar4;
  ushort uVar7;
  byte *pbVar5;
  SeMgr *this_00;
  uint uVar6;
  JAISound *pJVar8;
  JAISound *extraout_r4;
  JAISound *extraout_r4_00;
  JAISound *extraout_r4_01;
  JAISound *extraout_r4_02;
  int iVar9;
  JAISound *pJVar10;
  JAISound *pJVar11;
  int iVar12;
  int iVar13;
  byte bVar14;
  uint uVar15;
  JAISound *this_01;
  JAIGlobalParameter *pJVar16;
  JAISound *pJVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  undefined4 uVar23;
  double dVar24;
  double extraout_f1;
  double extraout_f1_00;
  double dVar25;
  undefined8 in_f27;
  undefined8 in_f28;
  double dVar26;
  undefined8 in_f29;
  double dVar27;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar28;
  ulonglong uVar29;
  JAISound JStack408;
  undefined4 local_164;
  byte abStack352 [4];
  JAISound *apJStack348 [2];
  byte local_154 [4];
  JAISound *local_150;
  int local_14c [47];
  undefined4 local_90;
  uint uStack140;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar23 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  JAISound::JAISound(&JStack408);
  if (3 < *(byte *)&_seHandle->field_0x5) {
    pJVar4 = (JAIGlobalParameter *)
             JAIGlobalParameter::getParamDistanceMax((JAIGlobalParameter *)_seHandle);
    dVar25 = extraout_f1;
    pJVar4 = (JAIGlobalParameter *)JAIGlobalParameter::getParamDistanceMax(pJVar4);
    dVar28 = (double)(float)(extraout_f1_00 * dVar25);
    dVar25 = (double)JAIGlobalParameter::getParamDistanceMax(pJVar4);
    dVar25 = (double)(float)(dVar25 / (double)JAudio::_1413);
    if ((double)JAudio::_970 == dVar25) {
      dVar25 = (double)JAudio::_969;
    }
    iVar21 = 0;
    iVar20 = 0;
    iVar19 = 0;
    pJVar4 = (JAIGlobalParameter *)&DAT_80000000;
    for (uVar22 = 0; uVar6 = JAIGlobalParameter::getParamSeCategoryMax(pJVar4), uVar22 < uVar6;
        uVar22 = uVar22 + 1) {
      pJVar10 = (JAISound *)0xff;
      pJVar8 = (JAISound *)0x0;
      for (bVar14 = 0; bVar14 < *(byte *)(iVar19 + *(int *)(_categoryInfoTable + (uint)seScene * 4))
          ; bVar14 = bVar14 + 1) {
        uVar6 = (uint)bVar14;
        (&local_150)[uVar6 * 3] = (JAISound *)0x7fffffff;
        local_154[uVar6 * 0xc] = 0xff;
        (&local_150)[uVar6 * 3 + 1] = (JAISound *)0x0;
      }
      pJVar17 = (JAISound *)0x0;
      this_01 = *(JAISound **)(_seRegist + iVar20 + 4);
      while (this_01 != (JAISound *)0x0) {
        if ((*(char *)&this_01->field_0x5 == '\x01') && ((this_01->field_0xc & 0xc00U) != 0)) {
          *(char *)&this_01->field_0x6 = *(char *)&this_01->field_0x6 + -1;
        }
        else {
          if (((this_01->field_0xc & 0xc00U) == 0) && (*(char *)&this_01->field_0x5 == '\x05')) {
            local_164 = *(undefined4 *)&this_01[1].field_0x14;
            releaseSeRegist((SeMgr *)this_01,pJVar8);
            this_01 = &JStack408;
            pJVar8 = extraout_r4;
          }
        }
        if (*(char *)&this_01->field_0x6 == '\0') {
          local_164 = *(undefined4 *)&this_01[1].field_0x14;
          releaseSeRegist((SeMgr *)this_01,pJVar8);
          this_01 = &JStack408;
          pJVar8 = extraout_r4_00;
        }
        else {
          if (*(char *)&this_01->field_0x5 != '\0') {
            dVar27 = (double)JAudio::_1414;
            pJVar4 = (JAIGlobalParameter *)(uint)*(byte *)&this_01->field_0x8;
            if (pJVar4 == (JAIGlobalParameter *)&DAT_00000004) {
              pJVar4 = (JAIGlobalParameter *)
                       JAIGlobalParameter::getParamAudioCameraMax
                                 ((JAIGlobalParameter *)&DAT_00000004);
              pJVar3 = (JAIGlobalParameter *)0x0;
              pJVar16 = pJVar4;
            }
            else {
              pJVar16 = pJVar4 + 1;
              pJVar3 = pJVar4;
            }
            dVar26 = (double)JAudio::_970;
            dVar24 = JAudio::_1418;
            for (; ((uint)pJVar3 & 0xff) < ((uint)pJVar16 & 0xff); pJVar3 = pJVar3 + 1) {
              pJVar8 = (JAISound *)(*(int *)(this_01 + 1) + ((uint)pJVar3 & 0xff) * 0x1c);
              pJVar8->field_0xc = *(int *)&pJVar8->field_0x0;
              *(undefined4 *)&pJVar8->field_0x10 = *(undefined4 *)&pJVar8->field_0x4;
              *(undefined4 *)&pJVar8->field_0x14 = *(undefined4 *)&pJVar8->field_0x8;
              if (*(cXyz **)&this_01[1].field_0x8 == (cXyz *)0x0) {
                *(undefined4 *)&pJVar8->field_0x0 = _dummyZeroVec;
                *(undefined4 *)&pJVar8->field_0x4 = DAT_8039b17c;
                *(undefined4 *)&pJVar8->field_0x8 = DAT_8039b180;
              }
              else {
                pJVar10 = pJVar8;
                mtx::PSMTXMultVec(*(MTX34 **)
                                   (*(int *)(_msBasic + 4) + ((uint)pJVar3 & 0xff) * 0xc + 8),
                                  *(cXyz **)&this_01[1].field_0x8,(cXyz *)pJVar8);
              }
              pJVar8->field_0x18 =
                   (uint)(*(float *)&pJVar8->field_0x8 * *(float *)&pJVar8->field_0x8 +
                         *(float *)&pJVar8->field_0x0 * *(float *)&pJVar8->field_0x0 +
                         *(float *)&pJVar8->field_0x4 * *(float *)&pJVar8->field_0x4);
              uVar7 = JAISound::getInfoPriority(this_01);
              uVar7 = uVar7 & 0xff;
              if (*(short *)&this_01->field_0xa != 0) {
                uVar7 = uVar7 + *(short *)&this_01->field_0xa;
                if ((short)uVar7 < 0) {
                  uVar7 = 0;
                }
                else {
                  if (0xff < (short)uVar7) {
                    uVar7 = 0xff;
                  }
                }
              }
              uStack140 = (0xff - (short)uVar7) * (0xff - (short)uVar7) * 0x1690 ^ 0x80000000;
              local_90 = 0x43300000;
              iVar18 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                                 ((double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                                   uStack140) -
                                                                 dVar24) / dVar25));
              pJVar4 = (JAIGlobalParameter *)
                       Runtime.PPCEABI.H::__cvt_fp2unsigned
                                 ((double)(float)((double)(float)pJVar8->field_0x18 / dVar25));
              *(JAIGlobalParameter **)&this_01->field_0x10 = pJVar4 + iVar18;
              if (dVar26 < (double)*(float *)&pJVar8->field_0x8) {
                pJVar4 = (JAIGlobalParameter *)
                         Runtime.PPCEABI.H::__cvt_fp2unsigned
                                   ((double)(float)((double)(float)((double)JAudio::_1415 *
                                                                   (double)*(float *)&pJVar8->
                                                  field_0x8) / dVar25));
                *(JAIGlobalParameter **)&this_01->field_0x10 = pJVar4 + *(int *)&this_01->field_0x10
                ;
              }
              if ((((uint)pJVar3 & 0xff) == 0) || ((double)(float)pJVar8->field_0x18 < dVar27)) {
                dVar27 = (double)(float)pJVar8->field_0x18;
              }
            }
            if (*(char *)&this_01->field_0x8 == '\x04') {
              uVar15 = *(uint *)&this_01->field_0x10;
              uVar6 = JAIGlobalParameter::getParamAudioCameraMax(pJVar4);
              *(uint *)&this_01->field_0x10 = uVar15 / uVar6;
            }
            uVar29 = JAISound::getSwBit(this_01);
            pJVar8 = (JAISound *)uVar29;
            dVar24 = dVar28;
            if ((uVar29 & 0x2000000000) == 0) {
              dVar24 = (double)JAudio::_1416;
            }
            if (dVar27 <= dVar24) {
              uVar6 = JAISound::getSeCategoryNumber(this_01);
              pJVar8 = (JAISound *)
                       (uint)*(byte *)(*(int *)(_categoryInfoTable + (uint)seScene * 4) +
                                      (uVar6 & 0xff) * 2);
              for (pJVar11 = (JAISound *)0x0; (JAISound *)((uint)pJVar11 & 0xff) < pJVar8;
                  pJVar11 = (JAISound *)&pJVar11->field_0x1) {
                pJVar10 = *(JAISound **)&this_01->field_0x10;
                uVar6 = (uint)pJVar11 & 0xff;
                pbVar5 = local_154 + uVar6 * 0xc;
                if ((pJVar10 < (&local_150)[uVar6 * 3]) ||
                   (((&local_150)[uVar6 * 3] == pJVar10 &&
                    (pJVar10 = (JAISound *)(uint)*pbVar5,
                    (JAISound *)(uint)*(byte *)&this_01->field_0x5 <= pJVar10)))) {
                  if (pJVar17 < pJVar8) {
                    pJVar17 = (JAISound *)(&pJVar17->field_0x1 & 0xff);
                  }
                  for (uVar15 = (int)&pJVar8[-1].field_0x1c + 3U & 0xff;
                      pJVar10 = (JAISound *)(uVar15 & 0xff),
                      (JAISound *)((uint)pJVar11 & 0xff) < pJVar10; uVar15 = uVar15 - 1) {
                    uVar2 = uVar15 & 0xff;
                    (&local_150)[uVar2 * 3] = apJStack348[uVar2 * 3];
                    (&local_150)[uVar2 * 3 + 1] = apJStack348[uVar2 * 3 + 1];
                    *pbVar5 = abStack352[uVar2 * 0xc];
                  }
                  (&local_150)[uVar6 * 3] = *(JAISound **)&this_01->field_0x10;
                  (&local_150)[uVar6 * 3 + 1] = this_01;
                  *pbVar5 = *(byte *)&this_01->field_0x5;
                  pJVar11 = pJVar8;
                }
              }
            }
            else {
              if ((this_01->field_0xc & 0xc00U) == 0) {
                if (*(char *)&this_01->field_0x5 != '\x01') {
                  bVar14 = *(byte *)&this_01->field_0x4;
                  if (bVar14 != 0xff) {
                    iVar18 = JAISound::getSeqParameter(_seHandle);
                    JASystem::TTrack::writePortApp
                              ((TTrack *)(iVar18 + 0x1360),
                               (bVar14 >> 4) + 0x20000000 + (bVar14 & 0xf) * 0x10,0);
                    pJVar10 = (JAISound *)&DAT_00000001;
                    JAISound::setTrackInterruptSwitch
                              (_seHandle,*(uchar *)&this_01->field_0x4,'\x01');
                    pJVar8 = extraout_r4_01;
                  }
                }
                *(undefined *)&this_01->field_0x5 = 5;
                *(undefined *)&this_01->field_0x4 = 0xff;
              }
              else {
                local_164 = *(undefined4 *)&this_01[1].field_0x14;
                releaseSeBuffer((SeMgr *)this_01,(JAISound *)0x0,(ulong)pJVar10);
                this_01 = &JStack408;
                pJVar8 = extraout_r4_02;
              }
            }
          }
        }
        if (this_01 != (JAISound *)0x0) {
          this_01 = *(JAISound **)&this_01[1].field_0x14;
        }
      }
      for (uVar6 = 0; (JAISound *)(uVar6 & 0xff) < pJVar17; uVar6 = uVar6 + 1) {
        pJVar10 = (&local_150)[(uVar6 & 0xff) * 3 + 1];
        if (*(char *)&pJVar10->field_0x5 == '\x01') {
          *(undefined *)&pJVar10->field_0x5 = 2;
        }
        else {
          if (*(char *)&pJVar10->field_0x5 == '\x04') {
            *(undefined *)&pJVar10->field_0x5 = 3;
          }
        }
      }
      pJVar4 = *(JAIGlobalParameter **)(_categoryInfoTable + (uint)seScene * 4);
      pJVar16 = (JAIGlobalParameter *)(uint)(byte)pJVar4[iVar19];
      for (uVar6 = 0; (JAIGlobalParameter *)(uVar6 & 0xff) < pJVar16; uVar6 = uVar6 + 1) {
        pJVar3 = (JAIGlobalParameter *)0x0;
        pJVar10 = *(JAISound **)(iVar21 + _sePlaySound);
        iVar18 = (uVar6 & 0xff) * 4;
        this_00 = *(SeMgr **)(&pJVar10->field_0x0 + iVar18);
        if (this_00 == (SeMgr *)0x0) {
          pJVar3 = (JAIGlobalParameter *)&DAT_00000001;
        }
        else {
          SVar1 = this_00[5];
          if (SVar1 == (SeMgr)0x4) {
            if ((*(uint *)(this_00 + 0xc) & 0xc00) == 0) {
              this_00[5] = (SeMgr)0x1;
              this_00[6] = (SeMgr)0x0;
            }
            else {
              releaseSeRegist(this_00,pJVar10);
            }
            pJVar3 = (JAIGlobalParameter *)&DAT_00000001;
          }
          else {
            if ((SVar1 == (SeMgr)0x0) || (SVar1 == (SeMgr)0x5)) {
              *(undefined4 *)(&pJVar10->field_0x0 + iVar18) = 0;
              pJVar3 = (JAIGlobalParameter *)&DAT_00000001;
            }
            else {
              for (pJVar4 = (JAIGlobalParameter *)0x0;
                  (JAIGlobalParameter *)((uint)pJVar4 & 0xff) < pJVar16; pJVar4 = pJVar4 + 1) {
                iVar12 = ((uint)pJVar4 & 0xff) * 0xc + 8;
                if (*(int *)(iVar18 + *(int *)(_sePlaySound + iVar21)) ==
                    *(int *)(local_154 + iVar12)) {
                  *(undefined4 *)(local_154 + iVar12) = 0;
                  pJVar4 = pJVar16;
                }
              }
            }
          }
        }
        pJVar4 = pJVar3;
        if (pJVar3 == (JAIGlobalParameter *)&DAT_00000001) {
          uVar15 = 0;
          while( true ) {
            pJVar4 = (JAIGlobalParameter *)(uVar15 & 0xff);
            if (pJVar16 <= pJVar4) break;
            iVar13 = (uVar15 & 0xff) * 0xc + 8;
            iVar12 = *(int *)(local_154 + iVar13);
            if ((iVar12 != 0) && (*(char *)(iVar12 + 5) != '\x03')) {
              for (pJVar4 = (JAIGlobalParameter *)0x0;
                  (JAIGlobalParameter *)((uint)pJVar4 & 0xff) < pJVar16; pJVar4 = pJVar4 + 1) {
                iVar9 = *(int *)(*(int *)(_sePlaySound + iVar21) + ((uint)pJVar4 & 0xff) * 4);
                if ((iVar9 != 0) && (*(int *)(local_154 + iVar13) == iVar9)) {
                  pJVar3 = (JAIGlobalParameter *)0x0;
                  pJVar4 = pJVar16;
                }
              }
              if (pJVar3 == (JAIGlobalParameter *)&DAT_00000001) {
                *(int *)(iVar18 + *(int *)(iVar21 + _sePlaySound)) = iVar12;
                *(undefined4 *)(local_154 + iVar13) = 0;
                uVar15 = (uint)(pJVar16 + 1) & 0xff;
              }
            }
            uVar15 = uVar15 + 1;
          }
          if (pJVar4 == pJVar16) {
            pJVar4 = *(JAIGlobalParameter **)(iVar21 + _sePlaySound);
            *(undefined4 *)(pJVar4 + iVar18) = 0;
          }
        }
      }
      iVar21 = iVar21 + 4;
      iVar20 = iVar20 + 0xc;
      iVar19 = iVar19 + 2;
    }
  }
  __psq_l0(auStack8,uVar23);
  __psq_l1(auStack8,uVar23);
  __psq_l0(auStack24,uVar23);
  __psq_l1(auStack24,uVar23);
  __psq_l0(auStack40,uVar23);
  __psq_l1(auStack40,uVar23);
  __psq_l0(auStack56,uVar23);
  __psq_l1(auStack56,uVar23);
  __psq_l0(auStack72,uVar23);
  __psq_l1(auStack72,uVar23);
  return;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* WARNING: Removing unreachable block (ram,0x802941bc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SeMgr::checkPlayingSe(void) */

void __thiscall SeMgr::checkPlayingSe(SeMgr *this)

{
  uchar uVar1;
  int iVar2;
  JAIGlobalParameter *pJVar3;
  int iVar4;
  ushort uVar7;
  uint uVar5;
  ushort uVar8;
  uint uVar6;
  JAISound *extraout_r4;
  JAISound *extraout_r4_00;
  JAISound *pJVar9;
  JAISound *extraout_r4_01;
  JAISound *extraout_r4_02;
  byte bVar10;
  ulong uVar11;
  uint uVar12;
  uint uVar13;
  JAISound *this_00;
  byte bVar14;
  TTrack *this_01;
  undefined4 uVar15;
  double dVar16;
  double extraout_f1;
  double dVar17;
  undefined8 in_f31;
  double dVar18;
  undefined8 uVar19;
  ulonglong uVar20;
  ushort local_58;
  ushort local_56;
  float local_54;
  float local_50;
  longlong local_48;
  undefined auStack8 [8];
  
  uVar15 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar13 = 0;
  uVar12 = 0;
  do {
    uVar6 = JAIGlobalParameter::getParamSeCategoryMax((JAIGlobalParameter *)this);
    if (uVar6 <= (uVar12 & 0xff)) {
      __psq_l0(auStack8,uVar15);
      __psq_l1(auStack8,uVar15);
      return;
    }
    for (bVar14 = 0;
        bVar14 < *(byte *)((uVar12 & 0xff) * 2 + *(int *)(_categoryInfoTable + (uint)seScene * 4));
        bVar14 = bVar14 + 1) {
      this_00 = *(JAISound **)(*(int *)((uVar12 & 0xff) * 4 + _sePlaySound) + (uint)bVar14 * 4);
      if (this_00 != (JAISound *)0x0) {
        this_00->field_0x18 = this_00->field_0x18 + 1;
        uVar11 = (uVar13 >> 4 & 0xf) + 0x20000000 + (uVar13 & 0xf) * 0x10;
        iVar2 = JAISound::getSeqParameter(_seHandle);
        this_01 = (TTrack *)(iVar2 + 0x1360);
        JASystem::TTrack::readPortApp(this_01,uVar11 + 0x20000,&local_56);
        pJVar3 = (JAIGlobalParameter *)JASystem::TTrack::readPortApp(this_01,uVar11,&local_58);
        iVar2 = *(int *)(this_00 + 1);
        uVar6 = 0;
        dVar18 = (double)JAudio::_970;
        while( true ) {
          uVar19 = JAIGlobalParameter::getParamAudioCameraMax(pJVar3);
          if ((uint)((ulonglong)uVar19 >> 0x20) <= (uVar6 & 0xff)) break;
          pJVar3 = (JAIGlobalParameter *)((uVar6 & 0xff) * 0x1c);
          dVar17 = (double)*(float *)(pJVar3 + 0x18 + iVar2);
          if (dVar18 < dVar17) {
            dVar16 = 1.0 / SQRT(dVar17);
            dVar16 = JAudio::_1616 * dVar16 * (JAudio::_1617 - dVar17 * dVar16 * dVar16);
            dVar16 = JAudio::_1616 * dVar16 * (JAudio::_1617 - dVar17 * dVar16 * dVar16);
            local_50 = (float)(dVar17 * JAudio::_1616 * dVar16 *
                                        (JAudio::_1617 - dVar17 * dVar16 * dVar16));
            dVar17 = (double)local_50;
          }
          *(float *)(pJVar3 + 0x18 + iVar2) = (float)dVar17;
          uVar6 = uVar6 + 1;
        }
        if (*(char *)&this_00->field_0x5 == '\x02') {
          uVar20 = JAISound::getSwBit(this_00);
          *(char *)&this_00->field_0x4 = (char)uVar13;
          if ((uVar20 & 0x800000000) != 0) {
            setSeqMuteFromSeStart((SeMgr *)this_00,(JAISound *)uVar20);
          }
          uVar6 = (uint)(uVar20 >> 0x20) & 0xc0;
          if ((uVar20 & 0xc000000000) != 0) {
            _random = _random * 0x19660d + 0x3c6ef35f;
            local_54 = (float)(_random >> 9 | 0x3f800000);
            iVar2 = (int)(JAudio::_1618 * (local_54 - JAudio::_969));
            local_48 = (longlong)iVar2;
            bVar10 = (byte)iVar2;
            if (uVar6 == 0x80) {
              *(byte *)&this_00->field_0x7 = bVar10 & 0x1f;
            }
            else {
              if (uVar6 < 0x80) {
                if (uVar6 == 0x40) {
                  *(byte *)&this_00->field_0x7 = bVar10 & 0xf;
                }
                else {
LAB_80293e88:
                  *(undefined *)&this_00->field_0x7 = 0;
                }
              }
              else {
                if (uVar6 != 0xc0) goto LAB_80293e88;
                *(byte *)&this_00->field_0x7 = bVar10 & 0x3f;
              }
            }
          }
          iVar2 = JAISound::getSeParameter(this_00);
          bVar10 = 0;
          while (*(ushort *)(iVar2 + 0x20) != 0) {
            if (((uint)*(ushort *)(iVar2 + 0x20) & 1 << (uint)bVar10) != 0) {
              uVar1 = *(uchar *)&this_00->field_0x4;
              iVar4 = JAISound::getSeParameter(this_00);
              JAISound::setTrackPortData
                        (_seHandle,uVar1,bVar10,*(ushort *)(iVar4 + (uint)bVar10 * 2));
              *(ushort *)(iVar2 + 0x20) = *(ushort *)(iVar2 + 0x20) ^ (ushort)(1 << (uint)bVar10);
            }
            bVar10 = bVar10 + 1;
          }
          (**(code **)(*(int *)this_00 + 0x14))(this_00);
          (**(code **)(*_msBasic + 0x18))(_msBasic,this_00);
          pJVar9 = extraout_r4;
          if (1 < *(uint *)&this_00->field_0x14) {
            JAISound::setSeInterVolume(this_00,'\x06',JAudio::_970,0,'\0');
            JAISound::setSeInterVolume
                      (this_00,'\x06',JAudio::_1619,*(ulong *)&this_00->field_0x14,'\0');
            *(undefined4 *)&this_00->field_0x14 = 0;
            pJVar9 = extraout_r4_00;
          }
          sendSeAllParameter((SeMgr *)this_00,pJVar9);
          uVar7 = JAIBasic::getSoundOffsetNumberFromID((JAIBasic *)_msBasic,this_00->field_0xc);
          pJVar3 = (JAIGlobalParameter *)JAISound::checkSwBit(this_00,0x800);
          if (pJVar3 != (JAIGlobalParameter *)0x0) {
            pJVar3 = (JAIGlobalParameter *)
                     (**(code **)(*_msBasic + 0x10))(_msBasic,this_00->field_0x1c);
            uVar7 = uVar7 + (short)pJVar3;
          }
          iVar2 = JAIGlobalParameter::getParamAudioCameraMax(pJVar3);
          if ((iVar2 == 1) &&
             (pJVar3 = (JAIGlobalParameter *)JAISound::checkSwBit(this_00,0x1000),
             pJVar3 != (JAIGlobalParameter *)0x0)) {
            iVar2 = *(int *)(this_00 + 1);
            pJVar3 = (JAIGlobalParameter *)JAIGlobalParameter::getParamDistanceMax(pJVar3);
            if (extraout_f1 <= (double)*(float *)(iVar2 + 0x18)) {
              uVar8 = JAIGlobalParameter::getParamSeDistanceWaitMax(pJVar3);
            }
            else {
              JAIGlobalParameter::getParamDistanceMax(pJVar3);
              uVar6 = Runtime.PPCEABI.H::__cvt_fp2unsigned();
              pJVar3 = (JAIGlobalParameter *)
                       Runtime.PPCEABI.H::__cvt_fp2unsigned
                                 ((double)*(float *)(*(int *)(this_00 + 1) + 0x18));
              uVar5 = JAIGlobalParameter::getParamSeDistanceWaitMax(pJVar3);
              uVar8 = (ushort)(((uVar5 & 0xffff) * (int)pJVar3) / uVar6);
            }
          }
          else {
            uVar8 = 0;
          }
          JASystem::TTrack::writePortApp(this_01,uVar11 + 0x30000,uVar8);
          uVar8 = (**(code **)(*_msBasic + 0xc))(_msBasic,this_00->field_0x1c);
          JASystem::TTrack::writePortApp(this_01,uVar11 + 0x60000,uVar8);
          JASystem::TTrack::writePortApp(this_01,uVar11 + 0x40000,uVar7);
          JASystem::TTrack::writePortApp(this_01,uVar11,1);
          if ((this_00->field_0xc & 0xc00U) == 0) {
            *(undefined *)&this_00->field_0x5 = 5;
          }
          else {
            *(undefined *)&this_00->field_0x5 = 4;
          }
        }
        else {
          if ((local_56 == 0) && (local_58 != 1)) {
            releaseSeRegist((SeMgr *)this_00,(JAISound *)uVar19);
          }
          else {
            if (*(int *)&this_00->field_0x14 == 0) {
              if (*(char *)&this_00->field_0x5 == '\x03') {
                (**(code **)(*(int *)this_00 + 0x14))(this_00);
                sendSeAllParameter((SeMgr *)this_00,extraout_r4_02);
                if ((this_00->field_0xc & 0xc00U) == 0) {
                  *(undefined *)&this_00->field_0x5 = 5;
                }
                else {
                  *(undefined *)&this_00->field_0x5 = 4;
                }
              }
            }
            else {
              uVar19 = JAISound::getSeParameter(this_00);
              if (JAudio::_970 == *(float *)((int)((ulonglong)uVar19 >> 0x20) + 0x188)) {
                releaseSeRegist((SeMgr *)this_00,(JAISound *)uVar19);
              }
              else {
                (**(code **)(*(int *)this_00 + 0x14))(this_00);
                sendSeAllParameter((SeMgr *)this_00,extraout_r4_01);
                if ((this_00->field_0xc & 0xc00U) == 0) {
                  *(undefined *)&this_00->field_0x5 = 5;
                }
                else {
                  *(undefined *)&this_00->field_0x5 = 4;
                }
              }
            }
          }
        }
      }
      uVar13 = uVar13 + 1;
    }
    uVar12 = uVar12 + 1;
    this = (SeMgr *)_categoryInfoTable;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SeMgr::setSeqMuteFromSeStart(JAISound *) */

void __thiscall SeMgr::setSeqMuteFromSeStart(SeMgr *this,JAISound *param_1)

{
  int iVar1;
  JAIGlobalParameter *pJVar2;
  uint uVar3;
  JAISound *this_00;
  SequenceMgr *this_01;
  undefined8 uVar4;
  
  pJVar2 = (JAIGlobalParameter *)this;
  for (this_01 = (SequenceMgr *)0x0; uVar4 = JAIGlobalParameter::getParamSeqPlayTrackMax(pJVar2),
      this_01 < (SequenceMgr *)((ulonglong)uVar4 >> 0x20); this_01 = this_01 + 1) {
    iVar1 = SequenceMgr::getPlayTrackInfo(this_01,(ulong)uVar4);
    this_00 = *(JAISound **)(iVar1 + 0x48);
    pJVar2 = _seHandle;
    if (((this_01 != (SequenceMgr *)(uint)(byte)_seHandle[4]) && (this_00 != (JAISound *)0x0)) &&
       (pJVar2 = (JAIGlobalParameter *)JAISound::getSwBit(this_00), ((uint)pJVar2 & 8) == 0)) {
      pJVar2 = (JAIGlobalParameter *)JAIGlobalParameter::getParamSeqMuteMoveSpeedSePlay(pJVar2);
      uVar3 = JAIGlobalParameter::getParamSeqMuteVolumeSePlay(pJVar2);
      JAISound::setSeqInterVolume
                (this_00,'\t',
                 (float)((double)CONCAT44(0x43300000,uVar3 & 0xff) - JAudio::_1640) / JAudio::_1619,
                 (ulong)pJVar2);
      pJVar2 = (JAIGlobalParameter *)&DAT_00000001;
      _seqMuteFlagFromSe = _seqMuteFlagFromSe | 1 << (uint)(byte)this[4];
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SeMgr::clearSeqMuteFromSeStop(JAISound *) */

void __thiscall SeMgr::clearSeqMuteFromSeStop(SeMgr *this,JAISound *param_1)

{
  JAIGlobalParameter *this_00;
  int iVar1;
  ulong uVar2;
  JAISound *this_01;
  SequenceMgr *this_02;
  undefined8 uVar3;
  
  if ((_seqMuteFlagFromSe != 0) &&
     (this_00 = (JAIGlobalParameter *)JAISound::getSwBit((JAISound *)this), ((uint)this_00 & 8) != 0
     )) {
    for (this_02 = (SequenceMgr *)0x0; uVar3 = JAIGlobalParameter::getParamSeqPlayTrackMax(this_00),
        this_02 < (SequenceMgr *)((ulonglong)uVar3 >> 0x20); this_02 = this_02 + 1) {
      iVar1 = SequenceMgr::getPlayTrackInfo(this_02,(ulong)uVar3);
      this_01 = *(JAISound **)(iVar1 + 0x48);
      this_00 = _seHandle;
      if ((this_02 != (SequenceMgr *)(uint)(byte)_seHandle[4]) && (this_01 != (JAISound *)0x0)) {
        this_00 = (JAIGlobalParameter *)JAISound::getSwBit(this_01);
        if (((uint)this_00 & 8) == 0) {
          this_00 = (JAIGlobalParameter *)&DAT_00000001;
          _seqMuteFlagFromSe = _seqMuteFlagFromSe & (1 << (uint)(byte)this[4] ^ 0xffffffffU);
          if (_seqMuteFlagFromSe == 0) {
            uVar2 = JAIGlobalParameter::getParamSeqMuteMoveSpeedSePlay
                              ((JAIGlobalParameter *)&DAT_00000001);
            this_00 = (JAIGlobalParameter *)
                      JAISound::setSeqInterVolume(this_01,'\t',JAudio::_969,uVar2);
          }
        }
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SeMgr::checkSeMovePara(void) */

void __thiscall SeMgr::checkSeMovePara(SeMgr *this)

{
  JAIGlobalParameter *this_00;
  int iVar1;
  uint uVar2;
  byte bVar3;
  JAISound *this_01;
  uint uVar4;
  int iVar5;
  
  if ((_seHandle != (JAISound *)0x0) &&
     (this_00 = (JAIGlobalParameter *)JAISound::getSeqParameter(_seHandle),
     this_00[0x1261] != (JAIGlobalParameter)0x2)) {
    for (uVar4 = 0; uVar2 = JAIGlobalParameter::getParamSeCategoryMax(this_00),
        (uVar4 & 0xff) < uVar2; uVar4 = uVar4 + 1) {
      this_00 = (JAIGlobalParameter *)((uVar4 & 0xff) * 0xc);
      for (this_01 = *(JAISound **)(this_00 + _seRegist + 4); this_01 != (JAISound *)0x0;
          this_01 = *(JAISound **)&this_01[1].field_0x14) {
        for (bVar3 = 0; bVar3 < 8; bVar3 = bVar3 + 1) {
          iVar1 = JAISound::getSeParameter(this_01);
          iVar5 = (uint)bVar3 * 0x10;
          MoveParaSet::move((MoveParaSet *)(iVar1 + iVar5 + 0x124));
          iVar1 = JAISound::getSeParameter(this_01);
          MoveParaSet::move((MoveParaSet *)(iVar1 + iVar5 + 0x1a4));
          iVar1 = JAISound::getSeParameter(this_01);
          MoveParaSet::move((MoveParaSet *)(iVar1 + iVar5 + 0x2a4));
          iVar1 = JAISound::getSeParameter(this_01);
          MoveParaSet::move((MoveParaSet *)(iVar1 + iVar5 + 0x324));
          iVar1 = JAISound::getSeParameter(this_01);
          MoveParaSet::move((MoveParaSet *)(iVar1 + iVar5 + 0x3a4));
          iVar1 = JAISound::getSeParameter(this_01);
          this_00 = (JAIGlobalParameter *)MoveParaSet::move((MoveParaSet *)(iVar1 + iVar5 + 0x224));
        }
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SeMgr::sendSeAllParameter(JAISound *) */

void __thiscall SeMgr::sendSeAllParameter(SeMgr *this,JAISound *param_1)

{
  SeMgr SVar1;
  char cVar2;
  JAISound *pJVar3;
  uint uVar4;
  JAIGlobalParameter *this_00;
  SystemInterface *this_01;
  ulong extraout_r4;
  ulong uVar5;
  float *in_r9;
  int iVar6;
  double dVar7;
  undefined8 uVar8;
  
  cVar2 = (char)_seTrackUpdate + (char)this[4] * '\x18';
  uVar8 = JAISound::getSeParameter((JAISound *)this);
  iVar6 = (int)((ulonglong)uVar8 >> 0x20);
  pJVar3 = (JAISound *)
           SequenceMgr::getPlayTrackInfo((SequenceMgr *)(uint)*(byte *)(_seHandle + 4),(ulong)uVar8)
  ;
  uVar4 = JAISound::getSeCategoryNumber((JAISound *)this);
  checkPlayingSeUpdateMultiplication
            (this,pJVar3,*(SeqUpdateData **)(iVar6 + 0x424),(float *)(iVar6 + 0x124),
             (MoveParaSet *)&DAT_00000002,*(float *)(_seCategoryVolume + (uVar4 & 0xff) * 4),
             cVar2 + '\x04',in_r9);
  checkPlayingSeUpdateAddition
            (this,pJVar3,*(SeqUpdateData **)(iVar6 + 0x428),(float *)(iVar6 + 0x1a4),
             (MoveParaSet *)&DAT_00000004,cVar2 + '\x10',in_r9,JAudio::_971);
  checkPlayingSeUpdateMultiplication
            (this,pJVar3,*(SeqUpdateData **)(iVar6 + 0x42c),(float *)(iVar6 + 0x224),
             (MoveParaSet *)&DAT_00000003,JAudio::_969,cVar2 + '\b',in_r9);
  this_00 = (JAIGlobalParameter *)
            checkPlayingSeUpdateAddition
                      (this,pJVar3,*(SeqUpdateData **)(iVar6 + 0x430),(float *)(iVar6 + 0x2a4),
                       (MoveParaSet *)0x5,cVar2 + '\f',in_r9,JAudio::_970);
  dVar7 = (double)JAIGlobalParameter::getParamSeDolbyCenterValue(this_00);
  uVar5 = 6;
  checkPlayingSeUpdateAddition
            (this,pJVar3,*(SeqUpdateData **)(iVar6 + 0x438),(float *)(iVar6 + 0x3a4),
             (MoveParaSet *)0x6,cVar2 + '\x14',in_r9,(float)(dVar7 / (double)JAudio::_1619));
  SVar1 = this[4];
  iVar6 = *(int *)(*(int *)&pJVar3[2].field_0x4 + (int)(SeqUpdateData *)(uint)(byte)SVar1 * 4);
  if (iVar6 != 0) {
    this_01 = (SystemInterface *)
              SequenceMgr::getPlayTrackInfo
                        ((SequenceMgr *)(uint)*(byte *)(_seHandle + 4),extraout_r4);
    SystemInterface::setSeqPortargsU32
              (this_01,(SeqUpdateData *)(uint)(byte)SVar1,1,(uchar)iVar6,uVar5);
    JASystem::Kernel::TPortCmd::addPortCmdOnce
              ((TPortCmd *)(pJVar3[2].field_0xc + (uint)(byte)this[4] * 0x3c + 0x2c));
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x802946d0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SeMgr::checkPlayingSeUpdateMultiplication(JAISound *,
                                                                 SeqUpdateData *,
                                                                 float *,
                                                                 MoveParaSet *,
                                                                 float,
                                                                 unsigned char,
                                                                 float *) */

void __thiscall
SeMgr::checkPlayingSeUpdateMultiplication
          (SeMgr *this,JAISound *param_1,SeqUpdateData *param_2,float *param_3,MoveParaSet *param_4,
          float param_5,uchar param_6,float *param_7)

{
  float fVar1;
  int iVar2;
  SystemInterface *this_00;
  undefined3 in_register_00000020;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar1 = param_3[0x1d];
  if (JAudio::_1732 == fVar1) {
    if (param_2 != (SeqUpdateData *)0x0) {
      param_3[1] = *(float *)param_2;
    }
    iVar2 = 0;
    iVar3 = 7;
    fVar1 = JAudio::_969;
    do {
      fVar1 = fVar1 * *(float *)((int)param_3 + iVar2 + 4);
      iVar2 = iVar2 + 0x10;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  dVar5 = (double)(fVar1 * param_5);
  if (((double)*(float *)CONCAT31(in_register_00000020,param_6) != dVar5) &&
     (*(float *)CONCAT31(in_register_00000020,param_6) = fVar1 * param_5, this[5] != (SeMgr)0x2)) {
    iVar2 = (uint)(byte)this[4] * 4;
    *(uint *)(*(int *)&param_1[2].field_0x4 + iVar2) =
         *(uint *)(*(int *)&param_1[2].field_0x4 + iVar2) | 1 << ((uint)param_4 & 0xff) - 2;
    this_00 = (SystemInterface *)
              SequenceMgr::getPlayTrackInfo((SequenceMgr *)(uint)*(byte *)(_seHandle + 4),1);
    SystemInterface::setSeqPortargsF32
              (this_00,(SeqUpdateData *)(uint)(byte)this[4],(ulong)param_4,(uchar)iVar2,(float)dVar5
              );
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Removing unreachable block (ram,0x802947ec) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SeMgr::checkPlayingSeUpdateAddition(JAISound *,
                                                           SeqUpdateData *,
                                                           float *,
                                                           MoveParaSet *,
                                                           unsigned char,
                                                           float *,
                                                           float) */

void __thiscall
SeMgr::checkPlayingSeUpdateAddition
          (SeMgr *this,JAISound *param_1,SeqUpdateData *param_2,float *param_3,MoveParaSet *param_4,
          uchar param_5,float *param_6,float param_7)

{
  float fVar1;
  int iVar2;
  SystemInterface *this_00;
  undefined3 in_register_00000020;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar5 = (double)param_3[0x1d];
  if ((double)JAudio::_1732 == dVar5) {
    if (param_2 != (SeqUpdateData *)0x0) {
      param_3[1] = *(float *)param_2;
    }
    iVar2 = 0;
    iVar3 = 7;
    fVar1 = JAudio::_970;
    do {
      fVar1 = fVar1 + (*(float *)((int)param_3 + iVar2 + 4) - param_7);
      iVar2 = iVar2 + 0x10;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    dVar6 = (double)(fVar1 + param_7);
    dVar5 = (double)JAudio::_970;
    if ((dVar5 <= dVar6) && (dVar5 = dVar6, (double)JAudio::_969 < dVar6)) {
      dVar5 = (double)JAudio::_969;
    }
  }
  if (((double)*(float *)CONCAT31(in_register_00000020,param_5) != dVar5) &&
     (*(float *)CONCAT31(in_register_00000020,param_5) = (float)dVar5, this[5] != (SeMgr)0x2)) {
    iVar2 = (uint)(byte)this[4] * 4;
    *(uint *)(*(int *)&param_1[2].field_0x4 + iVar2) =
         *(uint *)(*(int *)&param_1[2].field_0x4 + iVar2) | 1 << ((uint)param_4 & 0xff) - 2;
    this_00 = (SystemInterface *)
              SequenceMgr::getPlayTrackInfo((SequenceMgr *)(uint)*(byte *)(_seHandle + 4),1);
    SystemInterface::setSeqPortargsF32
              (this_00,(SeqUpdateData *)(uint)(byte)this[4],(ulong)param_4,(uchar)iVar2,(float)dVar5
              );
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* __thiscall SeMgr::changeIDToCategory(unsigned long) */

uint __thiscall SeMgr::changeIDToCategory(SeMgr *this,ulong param_1)

{
  return (uint)this >> 0xc & 0xff;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SeMgr::releaseSeRegist(JAISound *) */

void __thiscall SeMgr::releaseSeRegist(SeMgr *this,JAISound *param_1)

{
  SeMgr SVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  JAISound *extraout_r4;
  byte bVar5;
  undefined8 uVar6;
  
  if (this[5] != (SeMgr)0x1) {
    SVar1 = this[4];
    iVar3 = JAISound::getSeqParameter(_seHandle);
    JASystem::TTrack::writePortApp
              ((TTrack *)(iVar3 + 0x1360),
               ((byte)SVar1 >> 4) + 0x20000000 + ((byte)SVar1 & 0xf) * 0x10,0);
    JAISound::setTrackInterruptSwitch(_seHandle,(uchar)this[4],'\x01');
    param_1 = extraout_r4;
  }
  clearSeqMuteFromSeStop(this,param_1);
  uVar4 = JAISound::getSeCategoryNumber((JAISound *)this);
  bVar2 = *(byte *)(*(int *)(_categoryInfoTable + (uint)seScene * 4) + (uVar4 & 0xff) * 2);
  uVar4 = JAISound::getSeCategoryNumber((JAISound *)this);
  for (bVar5 = 0; bVar5 < bVar2; bVar5 = bVar5 + 1) {
    iVar3 = *(int *)((uVar4 & 0xff) * 4 + _sePlaySound);
    if (*(SeMgr **)(iVar3 + (uint)bVar5 * 4) == this) {
      *(undefined4 *)(iVar3 + (uint)bVar5 * 4) = 0;
      bVar5 = bVar2;
    }
  }
  JAISound::clearMainSoundPPointer((JAISound *)this);
  this[5] = (SeMgr)0x0;
  this[4] = (SeMgr)0xff;
  uVar6 = JAISound::getSeParameter((JAISound *)this);
  releaseSeParameterPointer((SeMgr *)((ulonglong)uVar6 >> 0x20),(SeParameter *)uVar6);
  LinkSound::releaseSound((LinkSound *)(_seRegist + (uVar4 & 0xff) * 0xc),(JAISound *)this);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SeMgr::getSeParametermeterPointer(void) */

int __thiscall SeMgr::getSeParametermeterPointer(SeMgr *this)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = _seParameterFreeStartPointer;
  if (_seParameterFreeStartPointer != 0) {
    if (_seParameterUsedEndPointer == 0) {
      puVar2 = (undefined4 *)(_seParameterFreeStartPointer + 0x440);
      _seParameterFreeStartPointer = *(undefined4 *)(_seParameterFreeStartPointer + 0x440);
      *puVar2 = 0;
    }
    else {
      piVar1 = (int *)(_seParameterFreeStartPointer + 0x440);
      _seParameterFreeStartPointer = *(undefined4 *)(_seParameterFreeStartPointer + 0x440);
      *piVar1 = _seParameterUsedEndPointer;
      *(int *)(_seParameterUsedEndPointer + 0x43c) = iVar3;
    }
    *(undefined4 *)(iVar3 + 0x43c) = 0;
    _seParameterUsedEndPointer = iVar3;
    return iVar3;
  }
  return 0;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SeMgr::releaseSeParameterPointer(SeParameter *) */

void __thiscall SeMgr::releaseSeParameterPointer(SeMgr *this,SeParameter *param_1)

{
  if (this == (SeMgr *)0x0) {
    return;
  }
  if (_seParameterUsedEndPointer == this) {
    _seParameterUsedEndPointer = *(SeMgr **)(this + 0x440);
    if (*(int *)(this + 0x440) != 0) {
      *(undefined4 *)(*(int *)(this + 0x440) + 0x43c) = 0;
    }
  }
  else {
    *(undefined4 *)(*(int *)(this + 0x43c) + 0x440) = *(undefined4 *)(this + 0x440);
    if (*(int *)(this + 0x440) != 0) {
      *(undefined4 *)(*(int *)(this + 0x440) + 0x43c) = *(undefined4 *)(this + 0x43c);
    }
  }
  *(SeMgr **)(this + 0x440) = _seParameterFreeStartPointer;
  if (*(int *)(this + 0x440) != 0) {
    *(SeMgr **)(*(int *)(this + 0x440) + 0x43c) = this;
  }
  _seParameterFreeStartPointer = this;
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x80294e94) */
/* WARNING: Removing unreachable block (ram,0x80294e9c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SeMgr::storeSeBuffer(JAISound * *,
                                            Actor *,
                                            unsigned long,
                                            unsigned long,
                                            unsigned char,
                                            void *) */

void __thiscall
SeMgr::storeSeBuffer
          (SeMgr *this,JAISound **param_1,Actor *param_2,ulong param_3,ulong param_4,uchar param_5,
          void *param_6)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  JAISound *pJVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  JAIGlobalParameter *this_00;
  JAISound **ppJVar12;
  JAIGlobalParameter *pJVar13;
  undefined3 in_register_00000020;
  uint *puVar14;
  JAISound *pJVar15;
  undefined *puVar16;
  int iVar17;
  int iVar18;
  undefined4 uVar19;
  double dVar20;
  double dVar21;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar22;
  undefined8 uVar23;
  JAISound *local_98 [17];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  puVar14 = (uint *)CONCAT31(in_register_00000020,param_5);
  uVar19 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  ppJVar12 = param_1;
  if (((this != (SeMgr *)0x0) && (pJVar6 = *(JAISound **)this, pJVar6 != (JAISound *)0x0)) &&
     ((bVar1 = param_2 != (Actor *)pJVar6->field_0xc, bVar1 ||
      ((!bVar1 && (((uint)param_2 & 0xc00) == 0x800)))))) {
    uVar23 = JAISound::checkSoundHandle(pJVar6,(ulong)param_2,puVar14);
    ppJVar12 = (JAISound **)uVar23;
    if ((int)((ulonglong)uVar23 >> 0x20) != 0) goto LAB_80294e94;
  }
  uVar7 = changeIDToCategory((SeMgr *)param_2,(ulong)ppJVar12);
  iVar17 = (uVar7 & 0xff) * 0xc;
  pJVar6 = *(JAISound **)(_seRegist + iVar17 + 4);
  if (param_1 == (JAISound **)0x0) {
    param_1 = (JAISound **)&Const::nullActor;
  }
  puVar16 = *(undefined **)param_1;
  bVar11 = 0;
  bVar10 = *(byte *)(*(int *)(_categoryInfoTable + (uint)seScene * 4) +
                     ((uint)param_2 >> 0xb & 0x1fe) + 1);
  while (pJVar6 != (JAISound *)0x0) {
    if (*(undefined **)&pJVar6[1].field_0x4 == puVar16) {
      if ((param_2 == (Actor *)pJVar6->field_0xc) && ((*puVar14 & 0x80000) == 0)) {
        if (((uint)param_2 & 0x800) == 0) {
          if (*(char *)&pJVar6->field_0x4 == -1) {
            *(undefined *)&pJVar6->field_0x5 = 1;
          }
          else {
            *(undefined *)&pJVar6->field_0x5 = 4;
          }
          if ((this != (SeMgr *)0x0) && (*(int *)this == 0)) {
            pJVar6[1].field_0x18 = (uint)this;
            *(JAISound **)this = pJVar6;
          }
          goto LAB_80294e94;
        }
        JAISound::stop(pJVar6,0);
        pJVar6 = (JAISound *)0x0;
        bVar11 = 0xff;
      }
      else {
        pJVar15 = pJVar6;
        if (bVar11 != 0) {
          bVar8 = JAISound::getInfoPriority(pJVar6);
          bVar9 = JAISound::getInfoPriority(local_98[0]);
          if (bVar9 < bVar8) {
            local_98[bVar11] = pJVar6;
            pJVar15 = local_98[0];
          }
          else {
            iVar18 = 0;
            for (uVar7 = (uint)bVar11; uVar7 != 0; uVar7 = uVar7 - 1) {
              *(undefined4 *)((int)local_98 + iVar18 + 4) = *(undefined4 *)((int)local_98 + iVar18);
              iVar18 = iVar18 + 4;
            }
          }
        }
        local_98[0] = pJVar15;
        pJVar6 = *(JAISound **)&pJVar6[1].field_0x14;
        bVar11 = bVar11 + 1;
      }
    }
    else {
      pJVar6 = *(JAISound **)&pJVar6[1].field_0x14;
    }
  }
  if (bVar11 == bVar10) {
    bVar10 = JAISound::getInfoPriority(local_98[0]);
    if (*(byte *)(puVar14 + 1) < bVar10) goto LAB_80294e94;
    uVar23 = JAISound::getInfoPriority(local_98[0]);
    if (((uint)*(byte *)(puVar14 + 1) == ((uint)((ulonglong)uVar23 >> 0x20) & 0xff)) &&
       (*(char *)&local_98[0]->field_0x5 == '\x05')) goto LAB_80294e94;
    releaseSeRegist((SeMgr *)local_98[0],(JAISound *)uVar23);
  }
  pJVar6 = (JAISound *)LinkSound::getSound((LinkSound *)(_seRegist + iVar17));
  if (pJVar6 == (JAISound *)0x0) {
    dVar22 = (double)JAudio::_970;
    pJVar6 = (JAISound *)0x0;
    for (pJVar15 = *(JAISound **)(_seRegist + iVar17 + 4); pJVar15 != (JAISound *)0x0;
        pJVar15 = *(JAISound **)&pJVar15[1].field_0x14) {
      dVar21 = (double)JAudio::_970;
      bVar10 = *(byte *)&pJVar15->field_0x8;
      if (bVar10 == 4) {
        bVar10 = 0;
        bVar11 = JAIGlobalParameter::getParamAudioCameraMax((JAIGlobalParameter *)&DAT_00000004);
      }
      else {
        bVar11 = bVar10 + 1;
      }
      for (; bVar10 < bVar11; bVar10 = bVar10 + 1) {
        dVar20 = (double)*(float *)(*(int *)(pJVar15 + 1) + (uint)bVar10 * 0x1c + 0x18);
        if (dVar21 <= dVar20) {
          dVar21 = dVar20;
        }
      }
      if ((*(char *)&pJVar15->field_0x5 != '\x01') && (dVar22 <= dVar21)) {
        pJVar6 = pJVar15;
        dVar22 = dVar21;
      }
    }
    if (pJVar6 == (JAISound *)0x0) {
      if (this != (SeMgr *)0x0) {
        *(undefined4 *)this = 0;
      }
      goto LAB_80294e94;
    }
    JAISound::stop(pJVar6,0);
    pJVar6 = (JAISound *)LinkSound::getSound((LinkSound *)(_seRegist + iVar17));
  }
  this_00 = (JAIGlobalParameter *)getSeParametermeterPointer((SeMgr *)pJVar6);
  if (this_00 == (JAIGlobalParameter *)0x0) {
    LinkSound::releaseSound((LinkSound *)(_seRegist + iVar17),pJVar6);
    *(undefined4 *)this = 0;
  }
  else {
    dVar21 = (double)JAIGlobalParameter::getParamSeDolbyCenterValue(this_00);
    fVar4 = JAudio::_971;
    fVar3 = JAudio::_970;
    fVar2 = JAudio::_969;
    dVar22 = (double)JAudio::_1619;
    iVar17 = 0;
    iVar18 = 8;
    do {
      pJVar13 = this_00 + iVar17;
      *(float *)(pJVar13 + 0x128) = fVar2;
      *(float *)(pJVar13 + 0x124) = fVar2;
      *(undefined4 *)(pJVar13 + 0x130) = 0;
      *(float *)(pJVar13 + 0x1a8) = fVar4;
      *(float *)(pJVar13 + 0x1a4) = fVar4;
      *(undefined4 *)(pJVar13 + 0x1b0) = 0;
      *(float *)(pJVar13 + 0x228) = fVar2;
      *(float *)(pJVar13 + 0x224) = fVar2;
      *(undefined4 *)(pJVar13 + 0x230) = 0;
      *(float *)(pJVar13 + 0x2a8) = fVar3;
      *(float *)(pJVar13 + 0x2a4) = fVar3;
      *(undefined4 *)(pJVar13 + 0x2b0) = 0;
      *(float *)(pJVar13 + 0x328) = fVar3;
      *(float *)(pJVar13 + 0x324) = fVar3;
      *(undefined4 *)(pJVar13 + 0x330) = 0;
      *(float *)(pJVar13 + 0x3a8) = (float)(dVar21 / dVar22);
      *(float *)(pJVar13 + 0x3a4) = (float)(dVar21 / dVar22);
      *(undefined4 *)(pJVar13 + 0x3b0) = 0;
      fVar5 = JAudio::_1732;
      iVar17 = iVar17 + 0x10;
      iVar18 = iVar18 + -1;
    } while (iVar18 != 0);
    *(float *)(this_00 + 0x198) = JAudio::_1732;
    *(float *)(this_00 + 0x194) = fVar5;
    *(undefined4 *)(this_00 + 0x1a0) = 0;
    *(float *)(this_00 + 0x218) = fVar5;
    *(float *)(this_00 + 0x214) = fVar5;
    *(undefined4 *)(this_00 + 0x220) = 0;
    *(float *)(this_00 + 0x298) = fVar5;
    *(float *)(this_00 + 0x294) = fVar5;
    *(undefined4 *)(this_00 + 0x2a0) = 0;
    *(float *)(this_00 + 0x318) = fVar5;
    *(float *)(this_00 + 0x314) = fVar5;
    *(undefined4 *)(this_00 + 800) = 0;
    *(float *)(this_00 + 0x398) = fVar5;
    *(float *)(this_00 + 0x394) = fVar5;
    *(undefined4 *)(this_00 + 0x3a0) = 0;
    *(float *)(this_00 + 0x418) = fVar5;
    *(float *)(this_00 + 0x414) = fVar5;
    *(undefined4 *)(this_00 + 0x420) = 0;
    *(undefined4 *)(this_00 + 0x424) = 0;
    *(undefined4 *)(this_00 + 0x428) = 0;
    *(undefined4 *)(this_00 + 0x42c) = 0;
    *(undefined4 *)(this_00 + 0x430) = 0;
    *(undefined4 *)(this_00 + 0x434) = 0;
    *(undefined4 *)(this_00 + 0x438) = 0;
    *(undefined2 *)(this_00 + 0x20) = 0;
    pJVar6[1].field_0x1c = (int)this_00;
    *(undefined *)&pJVar6->field_0x5 = 1;
    *(undefined *)&pJVar6->field_0x4 = 0xff;
    JAISound::initParameter
              (pJVar6,(JAISound **)this,(Actor *)param_1,(ulong)param_2,param_3,(uchar)param_4,
               puVar14);
  }
LAB_80294e94:
  __psq_l0(auStack8,uVar19);
  __psq_l1(auStack8,uVar19);
  __psq_l0(auStack24,uVar19);
  __psq_l1(auStack24,uVar19);
  return;
}


/* __thiscall SeMgr::releaseSeBuffer(JAISound *,
                                              unsigned long) */

void __thiscall SeMgr::releaseSeBuffer(SeMgr *this,JAISound *param_1,ulong param_2)

{
  if (this[5] != (SeMgr)0x0) {
    if ((param_1 == (JAISound *)0x0) || (this[5] == (SeMgr)0x1)) {
      releaseSeRegist(this,param_1);
    }
    else {
      *(JAISound **)(this + 0x14) = param_1;
      JAISound::setSeInterVolume((JAISound *)this,'\x06',JAudio::_970,(ulong)param_1,'\0');
    }
  }
  return;
}


/* __thiscall MoveParaSetInitZero::MoveParaSetInitZero(void) */

void __thiscall MoveParaSetInitZero::MoveParaSetInitZero(MoveParaSetInitZero *this)

{
  float fVar1;
  
  fVar1 = JAudio::_970;
  *(float *)(this + 4) = JAudio::_970;
  *(float *)this = fVar1;
  *(undefined4 *)(this + 0xc) = 0;
  return;
}


/* __thiscall MoveParaSetInitHalf::MoveParaSetInitHalf(void) */

void __thiscall MoveParaSetInitHalf::MoveParaSetInitHalf(MoveParaSetInitHalf *this)

{
  float fVar1;
  
  fVar1 = JAudio::_971;
  *(float *)(this + 4) = JAudio::_971;
  *(float *)this = fVar1;
  *(undefined4 *)(this + 0xc) = 0;
  return;
}


/* __thiscall MoveParaSet::__defctor(void) */

void __thiscall MoveParaSet::__defctor(MoveParaSet *this)

{
  float fVar1;
  
  fVar1 = JAudio::_969;
  *(float *)(this + 4) = JAudio::_969;
  *(float *)this = fVar1;
  *(undefined4 *)(this + 0xc) = 0;
  return;
}

