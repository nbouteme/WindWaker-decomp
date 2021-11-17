#include <JAudio/JAIBasic.h>
#include <JAudio/JAIBasic.h>
#include <JAudio/JAIBankWave.h>
#include <JAudio/JAIDummyObject.h>
#include <JAudio/JAIFx.h>
#include <JAudio/JAISequenceMgr.h>
#include <JAudio/JAISeMgr.h>
#include <JAudio/JAIStreamMgr.h>
#include <JAudio/JAISequenceHeap.h>
#include <JKernel/JKRSolidHeap.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <JKernel/JKRArchivePub.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JKernel/JKRHeap.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <JAudio/JASTrack.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAudio/JASAudioThread.h>
#include <JAudio/JASDriverIF.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <mtx/mtx.h>
#include <JAudio/JAIInitData.h>
#include <JAudio/JAISoundTable.h>
#include <JAudio/JAIGlobalParameter.h>
#include <JAudio/JAISound.h>
#include <JAudio/JAIConst.h>
#include <JAudio/JAISystemInterface.h>
#include <JAudio/JASOuterParam.h>
#include <Demangler/JAIBasic.h>
#include <JAInter/Camera.h>


namespace JAIBasic {
undefined1 msBasic;
undefined1 msCurrentHeap;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::JAIBasic(void) */

void __thiscall JAIBasic::JAIBasic(JAIBasic *this)

{
  *(undefined ***)this = &__vt;
  _msBasic = this;
  this[0xe] = (JAIBasic)((byte)this[0xe] & 0x7f);
  this[0xe] = (JAIBasic)((byte)this[0xe] & 0xbf);
  this[0xe] = (JAIBasic)((byte)this[0xe] & 0xdf);
  this[0xe] = (JAIBasic)((byte)this[0xe] & 0xef);
  this[0xe] = (JAIBasic)((byte)this[0xe] & 0xf7);
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  this[0xc] = (JAIBasic)0x2;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  _msCurrentHeap = JAudio::JASDram;
  return;
}


/* __thiscall JAIBasic::initDriver(JKRSolidHeap *,
                                   unsigned long,
                                   unsigned char) */

void __thiscall
JAIBasic::initDriver(JAIBasic *this,JKRSolidHeap *param_1,ulong param_2,uchar param_3)

{
  initAudioThread(this,param_1,param_2,param_3);
  return;
}


/* __thiscall JAIBasic::initInterface(unsigned char) */

void __thiscall JAIBasic::initInterface(JAIBasic *this,uchar param_1)

{
  initInterfaceMain(this);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::initInterfaceMain(void) */

void __thiscall JAIBasic::initInterfaceMain(JAIBasic *this)

{
  BankWave *this_00;
  Fx *this_01;
  SequenceMgr *pSVar1;
  SeMgr *pSVar2;
  StreamMgr *this_02;
  EVP_PKEY_CTX *ctx;
  undefined8 uVar3;
  
  initHeap(this);
  initResourcePath(this);
  initArchive(this);
  uVar3 = initReadFile(this);
  this_00 = (BankWave *)((ulonglong)uVar3 >> 0x20);
  if (this_00 != (BankWave *)0x0) {
    if (-1 < (char)this[0xe]) {
      uVar3 = JAInter::BankWave::setWaveScene(this_00);
    }
    ctx = (EVP_PKEY_CTX *)uVar3;
    this_01 = (Fx *)JAInter::DummyObjectMgr::init((DummyObjectMgr *)((ulonglong)uVar3 >> 0x20),ctx);
    pSVar1 = (SequenceMgr *)JAInter::Fx::init(this_01,ctx);
    pSVar2 = (SeMgr *)JAInter::SequenceMgr::init(pSVar1,ctx);
    this_02 = (StreamMgr *)JAInter::SeMgr::init(pSVar2,ctx);
    JAInter::StreamMgr::init(this_02,ctx);
    JAInter::HeapMgr::init((HeapMgr *)(_stayHeapMax & 0xff),_stayHeapSize);
    initCamera(this);
    pSVar2 = (SeMgr *)(**(code **)(*(int *)this + 0x20))(this);
    pSVar1 = (SequenceMgr *)JAInter::SeMgr::startSeSequence(pSVar2);
    if (-1 < (char)this[0xe]) {
      JAInter::SequenceMgr::checkEntriedSeq(pSVar1);
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::initHeap(void) */

void __thiscall JAIBasic::initHeap(JAIBasic *this)

{
  JKRSolidHeap *pJVar1;
  
  if (_interfaceHeapSize == 0) {
    _msCurrentHeap = JAudio::JASDram;
  }
  else {
    pJVar1 = JKRSolidHeap::create(_interfaceHeapSize,JAudio::JASDram,false);
    *(JKRSolidHeap **)(this + 8) = pJVar1;
    _msCurrentHeap = *(JKRHeap **)(this + 8);
  }
  if ((_msCurrentHeap == (JKRHeap *)0x0) &&
     (m_Do_printf::OSReport
                ("JAIBasic::initHeap オーディオヒープが異常（NULL）です。\n"),
     _msCurrentHeap == (JKRHeap *)0x0)) {
    JUTAssertion::showAssert(3,"JAIBasic.cpp",0xba,"msCurrentHeap");
    m_Do_printf::OSPanic("JAIBasic.cpp",0xba,&DAT_80368b54);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::initArchive(void) */

JAIBasic * __thiscall JAIBasic::initArchive(JAIBasic *this)

{
  char *in_r4;
  ulong in_r7;
  void *in_r8;
  JKRArchive JStack104;
  
  if (_arcPointer == (JAIBasic *)0x0) {
    JAInter::SequenceMgr::getArchiveName((SequenceMgr *)&JStack104,in_r4);
    this = (JAIBasic *)
           JKRArchive::mount(&JStack104,&DAT_00000003,_msCurrentHeap,&DAT_00000001,in_r7,in_r8);
    _arcPointer = this;
    if ((this == (JAIBasic *)0x0) &&
       (this = (JAIBasic *)
               m_Do_printf::OSReport
                         (
                         "JAIBasic::initArchive シーケンスアーカイブのマウントに失敗しました。\n"
                         ), _arcPointer == (JAIBasic *)0x0)) {
      JUTAssertion::showAssert(3,"JAIBasic.cpp",0xce,"JAISequenceMgr::arcPointer");
      this = (JAIBasic *)m_Do_printf::OSPanic("JAIBasic.cpp",0xce,&DAT_80368b54);
    }
  }
  return this;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::initResourcePath(void) */

JAIBasic * __thiscall JAIBasic::initResourcePath(JAIBasic *this)

{
  size_t sVar1;
  size_t sVar2;
  char *pcVar3;
  
  if (_audioResPath != (char *)0x0) {
    sVar1 = MSL_C.PPCEABI.bare.H::strlen(_wavePath);
    sVar2 = MSL_C.PPCEABI.bare.H::strlen(_audioResPath);
    pcVar3 = (char *)JKRHeap::alloc(JAudio::JASDram,sVar2 + sVar1 + 1,0);
    MSL_C.PPCEABI.bare.H::sprintf(pcVar3,"%s%s%c",_audioResPath,_wavePath,0);
    _wavePath = pcVar3;
    sVar1 = MSL_C.PPCEABI.bare.H::strlen(_streamPath);
    sVar2 = MSL_C.PPCEABI.bare.H::strlen(_audioResPath);
    pcVar3 = (char *)JKRHeap::alloc(JAudio::JASDram,sVar2 + sVar1 + 1,0);
    this = (JAIBasic *)MSL_C.PPCEABI.bare.H::sprintf(pcVar3,"%s%s%c",_audioResPath,_streamPath,0);
    _streamPath = pcVar3;
  }
  return this;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::setCameraInfo(Vec *,
                                      Vec *,
                                      float *[][][][],
                                      unsigned long) */

void __thiscall
JAIBasic::setCameraInfo(JAIBasic *this,Vec *param_1,Vec *param_2,float *param_3,ulong param_4)

{
  int iVar1;
  
  if (_audioCameraMax <= param_4) {
    return;
  }
  iVar1 = param_4 * 0xc;
  *(Vec **)(*(int *)(this + 4) + iVar1) = param_1;
  *(Vec **)(*(int *)(this + 4) + iVar1 + 4) = param_2;
  *(float **)(*(int *)(this + 4) + iVar1 + 8) = param_3;
  return;
}


/* __thiscall JAIBasic::initStream(void) */

void __thiscall JAIBasic::initStream(JAIBasic *this)

{
  EVP_PKEY_CTX *in_r4;
  
  if (((byte)this[0xe] >> 4 & 1) == 0) {
    JAInter::StreamLib::init((StreamLib *)(uint)(((byte)this[0xe] >> 3 & 1) != 0),in_r4);
  }
  return;
}


/* __thiscall JAIBasic::setRegisterTrackCallback(void) */

void __thiscall JAIBasic::setRegisterTrackCallback(JAIBasic *this)

{
  FuncDef575 *in_r4;
  
  JASystem::TTrack::registerSeqCallback((TTrack *)setParameterSeqSync,in_r4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::initAudioThread(JKRSolidHeap *,
                                        unsigned long,
                                        unsigned char) */

void __thiscall
JAIBasic::initAudioThread(JAIBasic *this,JKRSolidHeap *param_1,ulong param_2,uchar param_3)

{
  Driver *this_00;
  int extraout_r4;
  undefined3 in_register_00000018;
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = CONCAT31(in_register_00000018,param_3);
  uVar2 = 1;
  if ((param_3 & 1) != 0) {
    uVar2 = 3;
  }
  JASystem::TAudioThread::setPriority
            ((TAudioThread *)(uint)JAIGlobalParameter::audioSystemThreadPriority,
             JAIGlobalParameter::audioDvdThreadPriority,(uchar)param_2);
  JASystem::TAudioThread::start((TAudioThread *)param_1,(JKRSolidHeap *)param_2,uVar2,uVar1);
  JASystem::TTrack::newMemPool(_systemTrackMax,extraout_r4);
  this_00 = (Driver *)(**(code **)(*(int *)this + 0x1c))(this);
  JASystem::Driver::setMixerLevel(this_00,_inputGainDown,_outputGainUp);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::initCamera(void) */

void __thiscall JAIBasic::initCamera(JAIBasic *this)

{
  float fVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  float local_2c;
  float local_28;
  float local_24;
  
  uVar3 = _audioCameraMax;
  if ((_msCurrentHeap == 0) &&
     (m_Do_printf::OSReport
                ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
     _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80368b54);
  }
  uVar2 = JKernel::operator_new__(uVar3 * 0xc + 0x10,_msCurrentHeap,0x20);
  uVar2 = Runtime.PPCEABI.H::__construct_new_array(uVar2,JAInter::Camera::__defctor,0,0xc,uVar3);
  *(undefined4 *)(this + 4) = uVar2;
  if ((*(int *)(this + 4) == 0) &&
     (m_Do_printf::OSReport("JAIBasic::initAllocParameter Cannot Alloc Heap!! (mAudioCamera)\n"),
     *(int *)(this + 4) == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.cpp",0x123,"mAudioCamera");
    m_Do_printf::OSPanic("JAIBasic.cpp",0x123,&DAT_80368b54);
  }
  local_2c = JAudio::_861;
  if (**(int **)(this + 4) == 0) {
    *_nullCamera = JAudio::_861;
    _nullCamera[1] = local_2c;
    fVar1 = JAudio::_862;
    _nullCamera[2] = JAudio::_862;
    *DAT_803ed054 = local_2c;
    DAT_803ed054[1] = local_2c;
    DAT_803ed054[2] = fVar1;
    local_28 = JAudio::_863;
    local_24 = local_2c;
    local_38 = _dummyZeroVec;
    local_34 = DAT_8039b17c;
    local_30 = DAT_8039b180;
    mtx::C_MTXLookAt(&JAInter::Const::camMtx,_nullCamera,&local_2c,&local_38);
    for (uVar3 = 0; uVar3 < _audioCameraMax; uVar3 = uVar3 + 1) {
      setCameraInfo(this,(Vec *)_nullCamera,(Vec *)DAT_803ed054,(float *)&JAInter::Const::camMtx,
                    uVar3);
    }
  }
  return;
}


namespace JAInter {

/* __thiscall Camera::__defctor(void) */

void __thiscall Camera::__defctor(Camera *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::initReadFile(void) */

undefined4 __thiscall JAIBasic::initReadFile(JAIBasic *this)

{
  JAIBasic JVar1;
  int iVar2;
  
  JVar1 = this[0xc];
  if (JVar1 != (JAIBasic)0x3) {
    if ((byte)JVar1 < 3) {
      if (1 < (byte)JVar1) {
        iVar2 = JAInter::InitData::checkInitDataFile((InitData *)this);
        if (iVar2 != 0) {
          return 1;
        }
        return 0;
      }
    }
    else {
      if ((byte)JVar1 < 5) {
        if (_aafPointer != 0) {
          JAInter::InitData::checkInitDataOnMemory((InitData *)this);
          return 1;
        }
        if (_aafPointer != 0) {
          return 1;
        }
        m_Do_printf::OSReport("JAIBasic::initReadFile Init Data Pointer is NULL !!!\n");
        if (_aafPointer != 0) {
          return 1;
        }
        JUTAssertion::showAssert(3,"JAIBasic.cpp",0x15d,"JAIInitData::aafPointer");
        m_Do_printf::OSPanic("JAIBasic.cpp",0x15d,&DAT_80368b54);
        return 1;
      }
    }
  }
  if (((byte)JVar1 < 5) &&
     (m_Do_printf::OSReport
                ("JAIBasic::initReadFile 初期設定読み込みモードが異常です。\n"),
     (byte)this[0xc] < 5)) {
    JUTAssertion::showAssert(3,"JAIBasic.cpp",0x161,"initLoadFileSw>=JAI_INIT_MODE_MAX");
    m_Do_printf::OSPanic("JAIBasic.cpp",0x161,&DAT_80368b54);
  }
  return 1;
}


/* __thiscall JAIBasic::processFrameWork(void) */

void __thiscall JAIBasic::processFrameWork(JAIBasic *this)

{
  BankWave *this_00;
  SeMgr *this_01;
  SequenceMgr *this_02;
  StreamMgr *this_03;
  
  this_00 = (BankWave *)JAInter::DummyObjectMgr::check((DummyObjectMgr *)this);
  this_01 = (SeMgr *)JAInter::BankWave::loadSecondStayWave(this_00);
  this_02 = (SequenceMgr *)JAInter::SeMgr::processGFrameSe(this_01);
  this_03 = (StreamMgr *)JAInter::SequenceMgr::processGFrameSequence(this_02);
  JAInter::StreamMgr::processGFrameStream(this_03);
  *(int *)(this + 0x10) = *(int *)(this + 0x10) + 1;
  return;
}


/* __thiscall JAIBasic::startSoundVec(unsigned long,
                                      JAISound * *,
                                      Vec *,
                                      unsigned long,
                                      unsigned long,
                                      unsigned char) */

void __thiscall
JAIBasic::startSoundVec
          (JAIBasic *this,JAISoundInfoID param_1,JAISound **param_2,Vec *param_3,ulong param_4,
          ulong param_5,uchar param_6)

{
  Actor local_18;
  
  local_18.field_0x0 = param_3;
  local_18.field_0x4 = param_3;
  local_18.field_0x8 = param_3;
  local_18.field_0xc = (undefined *)param_5;
  startSoundActor(this,param_1,param_2,&local_18,param_4,param_6);
  return;
}


/* __thiscall JAIBasic::startSoundActor(unsigned long,
                                        JAISound * *,
                                        JAInter::Actor *,
                                        unsigned long,
                                        unsigned char) */

void __thiscall
JAIBasic::startSoundActor
          (JAIBasic *this,JAISoundInfoID param_1,JAISound **param_2,Actor *param_3,ulong param_4,
          uchar param_5)

{
  startSoundDirectID(this,param_1,param_2,param_3,param_4,param_5);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall JAIBasic::startSoundDirectID(unsigned long,
                                           JAISound * *,
                                           JAInter::Actor *,
                                           unsigned long,
                                           unsigned char) */

void __thiscall
JAIBasic::startSoundDirectID
          (JAIBasic *this,ulong param_1,JAISound **param_2,Actor *param_3,ulong param_4,
          uchar param_5)

{
  void *pvVar1;
  
  pvVar1 = (void *)JAInter::SoundTable::getInfoPointer(param_1);
  if (pvVar1 != (void *)0x0) {
    startSoundBasic(this,param_1,param_2,param_3,param_4,param_5,pvVar1);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::startSoundBasic(unsigned long,
                                        JAISound * *,
                                        JAInter::Actor *,
                                        unsigned long,
                                        unsigned char,
                                        void *) */

void __thiscall
JAIBasic::startSoundBasic
          (JAIBasic *this,ulong param_1,JAISound **param_2,Actor *param_3,ulong param_4,
          uchar param_5,void *param_6)

{
  uint uVar1;
  undefined3 in_register_00000020;
  
  uVar1 = param_1 & 0xc0000000;
  if (uVar1 == 0xc0000000) {
    if (((JAInter::StreamMgr::flags >> 6 & 1) == 0) && (((byte)this[0xe] >> 5 & 1) != 1)) {
      JAInter::StreamMgr::storeStreamBuffer(param_2,param_3,param_1,param_4,param_5,param_6);
    }
  }
  else {
    if ((int)uVar1 < -0x40000000) {
      if ((int)uVar1 < -0x7fffffff) {
        if (((byte)this[0xe] >> 6 & 1) == 1) {
          return;
        }
        if ((_seHandle != 0) && ((*(uint *)(_seHandle + 0xc) & 0x3ff) == (param_1 & 0x3ff))) {
          return;
        }
        if (param_2 == (JAISound **)0x0) {
          param_2 = (JAISound **)(_FixSeqBufPointer + (uint)*(byte *)((int)param_6 + 5) * 4);
        }
        JAInter::SequenceMgr::storeSeqBuffer
                  ((SequenceMgr *)param_2,(JAISound **)param_3,(Actor *)param_1,param_4,
                   CONCAT31(in_register_00000020,param_5),(uchar)param_6,param_6);
        return;
      }
    }
    else {
      if (uVar1 == 0) {
        if (*(char *)(_seEntryCancel + (param_1 >> 0xc)) == '\0') {
          JAInter::SeMgr::storeSeBuffer
                    ((SeMgr *)param_2,(JAISound **)param_3,(Actor *)param_1,param_4,
                     CONCAT31(in_register_00000020,param_5),(uchar)param_6,param_6);
          return;
        }
        if (param_2 == (JAISound **)0x0) {
          return;
        }
        *param_2 = (JAISound *)0x0;
        return;
      }
    }
    m_Do_printf::OSReport
              ("JAIBasic::startSoundBasic サウンドカテゴリービットが異常です。\n")
    ;
    JUTAssertion::showAssert(3,"JAIBasic.cpp",0x237,"0");
    m_Do_printf::OSPanic("JAIBasic.cpp",0x237,&DAT_80368b54);
  }
  return;
}


/* __thiscall JAIBasic::stopSoundHandle(JAISound *,
                                        unsigned long) */

JAIBasic * __thiscall JAIBasic::stopSoundHandle(JAIBasic *this,JAISound *param_1,ulong param_2)

{
  uint uVar1;
  JAIBasic *pJVar2;
  
  if (param_1 != (JAISound *)0x0) {
    uVar1 = param_1->field_0xc & 0xc0000000;
    if (uVar1 == 0xc0000000) {
      this = (JAIBasic *)
             JAInter::StreamMgr::releaseStreamBuffer
                       ((StreamMgr *)param_1,(JAISound *)param_2,param_2);
    }
    else {
      if ((int)uVar1 < -0x40000000) {
        if ((int)uVar1 < -0x7fffffff) {
          pJVar2 = (JAIBasic *)
                   JAInter::SequenceMgr::releaseSeqBuffer
                             ((SequenceMgr *)param_1,(JAISound *)param_2,param_2);
          return pJVar2;
        }
      }
      else {
        if (uVar1 == 0) {
          pJVar2 = (JAIBasic *)
                   JAInter::SeMgr::releaseSeBuffer((SeMgr *)param_1,(JAISound *)param_2,param_2);
          return pJVar2;
        }
      }
      m_Do_printf::OSReport
                (
                "JAIBasic::stopSoundHandle サウンドカテゴリービットが異常です。\n"
                );
      JUTAssertion::showAssert(3,"JAIBasic.cpp",0x269,"0");
      this = (JAIBasic *)m_Do_printf::OSPanic("JAIBasic.cpp",0x269,&DAT_80368b54);
    }
  }
  return this;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::stopPlayingCategoryObjectSe(unsigned char,
                                                    void *) */

void __thiscall JAIBasic::stopPlayingCategoryObjectSe(JAIBasic *this,uchar param_1,void *param_2)

{
  uint uVar1;
  JAISound *pJVar2;
  JAISound *pJVar3;
  
  uVar1 = JAIGlobalParameter::getParamSeCategoryMax((JAIGlobalParameter *)this);
  if (param_1 < uVar1) {
    pJVar3 = *(JAISound **)(_seRegist + (uint)param_1 * 0xc + 4);
    while (pJVar2 = pJVar3, pJVar2 != (JAISound *)0x0) {
      pJVar3 = *(JAISound **)&pJVar2[1].field_0x14;
      if (*(void **)&pJVar2[1].field_0x4 == param_2) {
        stopSoundHandle(this,pJVar2,0);
      }
    }
  }
  return;
}


/* __thiscall JAIBasic::stopAllSe(unsigned char,
                                  void *) */

void __thiscall JAIBasic::stopAllSe(JAIBasic *this,uchar param_1,void *param_2)

{
  stopPlayingCategoryObjectSe(this,param_1,param_2);
  return;
}


/* __thiscall JAIBasic::stopActorSoundOneBuffer(void *,
                                                JAISound *) */

JAIBasic * __thiscall
JAIBasic::stopActorSoundOneBuffer(JAIBasic *this,void *param_1,JAISound *param_2)

{
  JAISound *pJVar1;
  
  while (param_2 != (JAISound *)0x0) {
    if (*(void **)&param_2[1].field_0x4 == param_1) {
      pJVar1 = *(JAISound **)&param_2[1].field_0x14;
      this = (JAIBasic *)JAISound::stop(param_2,1);
      param_2 = pJVar1;
    }
    else {
      param_2 = *(JAISound **)&param_2[1].field_0x14;
    }
  }
  return this;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JAIBasic::stopIDSoundOneBuffer(unsigned long,
                                             JAISound *) */

void __thiscall JAIBasic::stopIDSoundOneBuffer(JAIBasic *this,ulong param_1,JAISound *param_2)

{
  JAISound *pJVar1;
  
  while (pJVar1 = param_2, pJVar1 != (JAISound *)0x0) {
    param_2 = *(JAISound **)&pJVar1[1].field_0x14;
    if (pJVar1->field_0xc == param_1) {
      stopSoundHandle(this,pJVar1,0);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JAIBasic::stopIDActorSoundOneBuffer(unsigned long,
                                                  void *,
                                                  JAISound *) */

void __thiscall
JAIBasic::stopIDActorSoundOneBuffer(JAIBasic *this,ulong param_1,void *param_2,JAISound *param_3)

{
  JAISound *pJVar1;
  
  while (pJVar1 = param_3, pJVar1 != (JAISound *)0x0) {
    param_3 = *(JAISound **)&pJVar1[1].field_0x14;
    if ((pJVar1->field_0xc == param_1) && (*(void **)&pJVar1[1].field_0x4 == param_2)) {
      stopSoundHandle(this,pJVar1,0);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::stopAllSound(void *) */

void __thiscall JAIBasic::stopAllSound(JAIBasic *this,void *param_1)

{
  JAIBasic *this_00;
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  this_00 = this;
  for (uVar2 = 0; uVar1 = JAIGlobalParameter::getParamSeCategoryMax((JAIGlobalParameter *)this_00),
      uVar2 < uVar1; uVar2 = uVar2 + 1) {
    this_00 = (JAIBasic *)
              stopActorSoundOneBuffer(this,param_1,*(JAISound **)(_seRegist + iVar3 + 4));
    iVar3 = iVar3 + 0xc;
  }
  stopActorSoundOneBuffer(this,param_1,DAT_803ed0bc);
  stopActorSoundOneBuffer(this,param_1,DAT_803ed0cc);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::stopAllSound(unsigned long) */

void __thiscall JAIBasic::stopAllSound(JAIBasic *this,ulong param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xc0000000;
  if (uVar1 == 0xc0000000) {
    stopIDSoundOneBuffer(this,param_1,DAT_803ed0cc);
  }
  else {
    if ((int)uVar1 < -0x40000000) {
      if ((int)uVar1 < -0x7fffffff) {
        stopIDSoundOneBuffer(this,param_1,DAT_803ed0bc);
        return;
      }
    }
    else {
      if (uVar1 == 0) {
        uVar1 = JAInter::SeMgr::changeIDToCategory((SeMgr *)param_1,param_1);
        stopIDSoundOneBuffer(this,param_1,*(JAISound **)(_seRegist + (uVar1 & 0xff) * 0xc + 4));
        return;
      }
    }
    m_Do_printf::OSReport
              ("JAIBasic::stopAllSound サウンドカテゴリービットが異常です。\n");
    JUTAssertion::showAssert(3,"JAIBasic.cpp",0x35b,"0");
    m_Do_printf::OSPanic("JAIBasic.cpp",0x35b,&DAT_80368b54);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::stopAllSound(unsigned long,
                                     void *) */

void __thiscall JAIBasic::stopAllSound(JAIBasic *this,ulong param_1,void *param_2)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xc0000000;
  if (uVar1 == 0xc0000000) {
    stopIDActorSoundOneBuffer(this,param_1,param_2,DAT_803ed0cc);
  }
  else {
    if ((int)uVar1 < -0x40000000) {
      if ((int)uVar1 < -0x7fffffff) {
        stopIDActorSoundOneBuffer(this,param_1,param_2,DAT_803ed0bc);
        return;
      }
    }
    else {
      if (uVar1 == 0) {
        uVar1 = JAInter::SeMgr::changeIDToCategory((SeMgr *)param_1,param_1);
        stopIDActorSoundOneBuffer
                  (this,param_1,param_2,*(JAISound **)(_seRegist + (uVar1 & 0xff) * 0xc + 4));
        return;
      }
    }
    m_Do_printf::OSReport
              ("JAIBasic::stopAllSound サウンドカテゴリービットが異常です。\n");
    JUTAssertion::showAssert(3,"JAIBasic.cpp",0x370,"0");
    m_Do_printf::OSPanic("JAIBasic.cpp",0x370,&DAT_80368b54);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::deleteObject(void *) */

void __thiscall JAIBasic::deleteObject(JAIBasic *this,void *param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  JAIGlobalParameter *this_00;
  uint uVar4;
  undefined4 in_r5;
  JAISound *pJVar5;
  JAISound *this_01;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = 0;
  iVar8 = 0;
  this_00 = (JAIGlobalParameter *)this;
  for (uVar6 = 0; uVar4 = JAIGlobalParameter::getParamSeCategoryMax(this_00), uVar6 < uVar4;
      uVar6 = uVar6 + 1) {
    this_00 = _seRegist;
    pJVar5 = *(JAISound **)(_seRegist + iVar8 + 4);
    while (this_01 = pJVar5, this_01 != (JAISound *)0x0) {
      pJVar5 = *(JAISound **)&this_01[1].field_0x14;
      if (*(void **)&this_01[1].field_0x4 == param_1) {
        bVar1 = false;
        iVar2 = JAISound::checkSwBit(this_01,0x8000);
        if ((iVar2 != 0) && (bVar1 = true, iVar7 == 0)) {
          iVar7 = JAInter::DummyObjectMgr::getPointer(_dummyObjectLifeTime,0,SUB41(in_r5,0));
        }
        if ((bVar1) && (iVar7 != 0)) {
          puVar3 = *(undefined4 **)&this_01[1].field_0x8;
          *(undefined4 *)(iVar7 + 0xc) = *puVar3;
          *(undefined4 *)(iVar7 + 0x10) = puVar3[1];
          *(undefined4 *)(iVar7 + 0x14) = puVar3[2];
          *(JAISound **)(iVar7 + 8) = this_01;
          this_00 = (JAIGlobalParameter *)JAISound::clearMainSoundPPointer(this_01);
          this_01[1].field_0x18 = iVar7 + 8;
          *(int *)&this_01[1].field_0x8 = iVar7 + 0xc;
          *(undefined4 *)&this_01[1].field_0x4 = 0;
        }
        else {
          in_r5 = 0;
          this_00 = (JAIGlobalParameter *)stopSoundHandle(this,this_01,0);
        }
      }
    }
    iVar8 = iVar8 + 0xc;
  }
  return;
}


/* __thiscall JAIBasic::getMapInfoFxline(unsigned long) */

bool __thiscall JAIBasic::getMapInfoFxline(JAIBasic *this,ulong param_1)

{
  return param_1 != 0;
}


/* __thiscall JAIBasic::getMapInfoGround(unsigned long) */

bool __thiscall JAIBasic::getMapInfoGround(JAIBasic *this,ulong param_1)

{
  return param_1 != 0;
}


/* __thiscall JAIBasic::getMapInfoFxParameter(unsigned long) */

double __thiscall JAIBasic::getMapInfoFxParameter(JAIBasic *this,ulong param_1)

{
  if (param_1 == 0) {
    return (double)JAudio::_861;
  }
  return (double)JAudio::_863;
}


/* __thiscall JAIBasic::getSoundOffsetNumberFromID(unsigned long) */

uint __thiscall JAIBasic::getSoundOffsetNumberFromID(JAIBasic *this,ulong param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = JAInter::SoundTable::getInfoFormat((SoundTable *)param_1,param_1);
  if ((uVar1 & 1) == 0) {
    uVar1 = param_1 & 0x3ff;
  }
  else {
    iVar2 = JAInter::SoundTable::getInfoPointer(param_1);
    uVar1 = (uint)*(ushort *)(iVar2 + 6);
  }
  return uVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::setSeCategoryVolume(unsigned char,
                                            unsigned char) */

void __thiscall JAIBasic::setSeCategoryVolume(JAIBasic *this,uchar param_1,uchar param_2)

{
  *(float *)(_seCategoryVolume + (uint)param_1 * 4) =
       (float)((double)CONCAT44(0x43300000,(uint)param_2) - JAudio::_1235) / JAudio::_1233;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80290e84) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAIBasic::setParameterSeqSync(JASystem::TTrack *,
                                            unsigned short) */

undefined4 __thiscall JAIBasic::setParameterSeqSync(JAIBasic *this,TTrack *param_1,ushort param_2)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  uint *puVar5;
  SystemInterface *this_00;
  ulong uVar6;
  ulong extraout_r4;
  uchar in_r8;
  SequenceMgr *this_01;
  TOuterParam *this_02;
  int iVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  
  iVar3 = _seTrackUpdate;
  uVar2 = (uint)param_1 & 0xffff;
  if (uVar2 == 1) {
    this_02 = *(TOuterParam **)(this + 0x360);
    iVar7 = (*(uint *)(this + 0x36c) & 0xff) * 0x18;
    JASystem::TTrack::TOuterParam::setParam(this_02,'\x01',*(float *)(_seTrackUpdate + iVar7 + 4));
    JASystem::TTrack::TOuterParam::setParam(this_02,'\b',*(float *)(iVar3 + iVar7 + 0x10));
    JASystem::TTrack::TOuterParam::setParam(this_02,'\x02',*(float *)(iVar3 + iVar7 + 8));
    JASystem::TTrack::TOuterParam::setParam(this_02,'\x04',*(float *)(iVar3 + iVar7 + 0xc));
    fVar1 = JAudio::_861;
    if (*(char *)(_msBasic + 0xd) == '\x02') {
      fVar1 = *(float *)(iVar3 + iVar7 + 0x14);
    }
    JASystem::TTrack::TOuterParam::setParam(this_02,'\x10',fVar1);
  }
  else {
    if (uVar2 == 0) {
      for (this_01 = (SequenceMgr *)0x0; this_01 < _seqPlayTrackMax; this_01 = this_01 + 1) {
        uVar8 = JAInter::SequenceMgr::getPlayTrackInfo(this_01,(ulong)param_1);
        param_1 = (TTrack *)uVar8;
        if (*(int *)((int)((ulonglong)uVar8 >> 0x20) + 0x48) != 0) {
          iVar3 = JAInter::SequenceMgr::getPlayTrackInfo(this_01,(ulong)param_1);
          uVar8 = JAISound::getSeqParameter(*(JAISound **)(iVar3 + 0x48));
          uVar9 = JAInter::SequenceMgr::getPlayTrackInfo(this_01,(ulong)uVar8);
          param_1 = (TTrack *)uVar9;
          if ((*(uint *)(*(int *)((int)((ulonglong)uVar9 >> 0x20) + 0x48) + 0xc) & 0x800) == 0) {
            iVar3 = *(int *)(this + 0x31c);
          }
          else {
            iVar3 = *(int *)(*(int *)(this + 0x31c) + 0x31c);
          }
          if ((int)((ulonglong)uVar8 >> 0x20) + 0x1360 == iVar3) {
            uVar8 = JAInter::routeToTrack(*(JAInter **)(this + 0x36c),(ulong)param_1);
            pvVar4 = (void *)((ulonglong)uVar8 >> 0x20);
            uVar8 = JAInter::SequenceMgr::getPlayTrackInfo(this_01,(ulong)uVar8);
            uVar6 = (ulong)uVar8;
            puVar5 = (uint *)JAInter::SoundTable::getInfoPointer
                                       (*(ulong *)(*(int *)((int)((ulonglong)uVar8 >> 0x20) + 0x48)
                                                  + 0xc));
            uVar2 = *puVar5;
            this_00 = (SystemInterface *)JAInter::SequenceMgr::getPlayTrackInfo(this_01,uVar6);
            JAInter::SystemInterface::outerInit
                      (this_00,(SeqUpdateData *)this,pvVar4,uVar2 >> 8 & 0xffff,0,in_r8);
            iVar3 = JAInter::SequenceMgr::getPlayTrackInfo(this_01,extraout_r4);
            param_1 = *(TTrack **)(iVar3 + 4);
            *(uint *)(iVar3 + 4) = (uint)param_1 | 1 << (int)pvVar4;
            this_01 = _seqPlayTrackMax;
          }
        }
      }
    }
    else {
      if (uVar2 == 0x7f) {
        JASystem::TTrack::writePortApp((TTrack *)this,0,(ushort)JAInter::SeMgr::seScene);
      }
    }
  }
  return 0;
}


/* __thiscall JAIBasic::setSeExtParameter(JAISound *) */

JAIBasic * __thiscall JAIBasic::setSeExtParameter(JAIBasic *this,JAISound *param_1)

{
  JAIBasic *pJVar1;
  
  if (param_1 != (JAISound *)0x0) {
    pJVar1 = (JAIBasic *)
             JAInter::SoundTable::getInfoFormat((SoundTable *)param_1->field_0xc,(ulong)param_1);
    this = pJVar1;
    if (((uint)pJVar1 & 4) != 0) {
      this = (JAIBasic *)
             JAISound::setVolume(param_1,(float)((double)CONCAT44(0x43300000,
                                                                  (uint)*(byte *)(*(int *)(param_1 +
                                                                                          2) + 0xc))
                                                - JAudio::_1235) / JAudio::_1233,0,1);
    }
    if (((uint)pJVar1 & 8) != 0) {
      this = (JAIBasic *)
             JAISound::setFxmix(param_1,(float)((double)CONCAT44(0x43300000,
                                                                 (uint)*(byte *)(*(int *)(param_1 +
                                                                                         2) + 0xd))
                                               - JAudio::_1235) / JAudio::_1233,0,'\x01');
    }
    if (((uint)pJVar1 & 2) != 0) {
      this = (JAIBasic *)JAISound::setPitch(param_1,*(float *)(*(int *)(param_1 + 2) + 8),0,'\x01');
    }
  }
  return this;
}


/* __thiscall JAIBasic::makeSound(unsigned long) */

void __thiscall JAIBasic::makeSound(JAIBasic *this,ulong param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(this + 8) == 0) {
    uVar1 = JKernel::operator_new__(param_1 * 0x44 + 0x10,JAudio::JASDram,0);
    Runtime.PPCEABI.H::__construct_new_array(uVar1,JAISound::JAISound,0,0x44,param_1);
  }
  else {
    uVar1 = JKernel::operator_new__(param_1 * 0x44 + 0x10,*(int *)(this + 8),0);
    Runtime.PPCEABI.H::__construct_new_array(uVar1,JAISound::JAISound,0,0x44,param_1);
  }
  return;
}


/* __thiscall JAIBasic::allocStreamBuffer(void *,
                                          long) */

bool __thiscall JAIBasic::allocStreamBuffer(JAIBasic *this,void *param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  
  lVar2 = param_2;
  uVar1 = JAInter::StreamLib::getNeedBufferSize((StreamLib *)this);
  if (uVar1 <= (uint)param_2) {
    JAInter::StreamLib::allocBuffer((StreamLib *)param_1,(void *)param_2,lVar2);
  }
  return uVar1 <= (uint)param_2;
}


/* __thiscall JAIBasic::deallocStreamBuffer(void) */

void __thiscall JAIBasic::deallocStreamBuffer(JAIBasic *this)

{
  JAInter::StreamLib::deallocBuffer((StreamLib *)this);
  return;
}

