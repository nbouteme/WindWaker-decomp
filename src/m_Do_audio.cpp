#include <m_Do_audio.h>
#include <m_Do_audio.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JAudio/JAIGlobalParameter.h>
#include <JAudio/JAIStreamMgr.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JAIBasic.h>
#include <m_Do_dvd_thread.h>
#include <JAudio/JAISequenceMgr.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <JKernel/JKRSolidHeap.h>
#include <os/OSRtc.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <JAZelAudio/JAIZelInst.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JAIZelInst.h>
#include <mDoAud_zelAudio_c.h>

struct JAIZelInst mDoAud_zelAudio_c;

namespace m_Do_audio {
undefined4 g_mDoAud_zelAudio;
}
undefined1 mDoAud_zelAudio_c;
undefined1 mDoAud_zelAudio_c;
byte mDoAud_zelAudio_c;
undefined1 mDoAud_zelAudio_c;

namespace m_Do_audio {
undefined4 g_mDoAud_audioHeap;
undefined4 mDoAud_StreamBufferPointer;
undefined1 mDoAud_StreamBufferBlocks;
undefined4 mDoAud_audioStreamHeap;
undefined4 l_affCommand;
undefined4 l_arcCommand;
}

/* __thiscall mDoAud_zelAudio_c::reset(void) */

void __thiscall mDoAud_zelAudio_c::reset(mDoAud_zelAudio_c *this)

{
  mBgmSet = 0;
  return;
}


/* __thiscall mDoAud_zelAudio_c::calcLoadTimer(void) */

mDoAud_zelAudio_c * __thiscall mDoAud_zelAudio_c::calcLoadTimer(mDoAud_zelAudio_c *this)

{
  if (1 < mLoadTimer) {
    this = (mDoAud_zelAudio_c *)m_Do_audio::cLib_calcTimer(&mLoadTimer);
  }
  return this;
}


namespace m_Do_audio {

/* __stdcall mDoAud_isUsedHeapForStreamBuffer(void) */

bool mDoAud_isUsedHeapForStreamBuffer(void)

{
  return mDoAud_StreamBufferPointer != 0;
}


/* __stdcall mDoAud_allocStreamBuffer(void) */

void mDoAud_allocStreamBuffer(undefined4 param_1,void *param_2)

{
  ulong uVar1;
  StreamLib *this;
  ulong uVar2;
  char cVar3;
  void *extraout_r4;
  JAIGlobalParameter *this_00;
  
  if (mDoAud_StreamBufferPointer != (void *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"m_Do_audio.cpp",0x62,"mDoAud_StreamBufferPointer == 0");
    m_Do_printf::OSPanic("m_Do_audio.cpp",0x62,"Halt");
    param_2 = extraout_r4;
  }
  this_00 = (JAIGlobalParameter *)(uint)mDoAud_StreamBufferBlocks;
  while( true ) {
    this = (StreamLib *)
           JAIGlobalParameter::setParamStreamDecodedBufferBlocks(this_00,(ulong)param_2);
    uVar1 = JAInter::StreamLib::getNeedBufferSize(this);
    if (mDoAud_audioStreamHeap != (JKRHeap *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"m_Do_audio.cpp",0x7c,"mDoAud_audioStreamHeap == 0");
      m_Do_printf::OSPanic("m_Do_audio.cpp",0x7c,"Halt");
    }
    mDoAud_audioStreamHeap = m_Do_ext::archiveHeap;
    mDoAud_StreamBufferPointer = (void *)JKRHeap::alloc(uVar1,0,m_Do_ext::archiveHeap);
    if (mDoAud_StreamBufferPointer == (void *)0x0) {
      mDoAud_audioStreamHeap = m_Do_ext::gameHeap;
      mDoAud_StreamBufferPointer = (void *)JKRHeap::alloc(uVar1,0,m_Do_ext::gameHeap);
    }
    if (mDoAud_StreamBufferPointer == (void *)0x0) {
      mDoAud_audioStreamHeap = m_Do_ext::zeldaHeap;
      mDoAud_StreamBufferPointer = (void *)JKRHeap::alloc(uVar1,0,m_Do_ext::zeldaHeap);
    }
    if (mDoAud_StreamBufferPointer != (void *)0x0) break;
    if (this_00 < (JAIGlobalParameter *)&DAT_00000004) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"m_Do_audio.cpp",0x90,"mDoAud_StreamBufferPointer");
      m_Do_printf::OSPanic("m_Do_audio.cpp",0x90,"Halt");
      return;
    }
    this_00 = this_00 + -1;
    param_2 = mDoAud_StreamBufferPointer;
  }
  cVar3 = JAIBasic::allocStreamBuffer
                    ((JAIBasic *)&g_mDoAud_zelAudio,mDoAud_StreamBufferPointer,uVar1);
  if (cVar3 != '\0') {
    return;
  }
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"m_Do_audio.cpp",0x94,"success");
  m_Do_printf::OSPanic("m_Do_audio.cpp",0x94,"Halt");
  return;
}


/* __stdcall mDoAud_deallocStreamBuffer(void) */

void mDoAud_deallocStreamBuffer(void)

{
  ulong uVar1;
  char cVar2;
  
  if (mDoAud_StreamBufferPointer == (void *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"m_Do_audio.cpp",0xae,"mDoAud_StreamBufferPointer");
    m_Do_printf::OSPanic("m_Do_audio.cpp",0xae,"Halt");
  }
  cVar2 = JAIBasic::deallocStreamBuffer((JAIBasic *)&g_mDoAud_zelAudio);
  if (cVar2 == '\0') {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"m_Do_audio.cpp",0xb6,"success");
    m_Do_printf::OSPanic("m_Do_audio.cpp",0xb6,"Halt");
  }
  JKRHeap::free(mDoAud_StreamBufferPointer,mDoAud_audioStreamHeap);
  mDoAud_StreamBufferPointer = (void *)0x0;
  mDoAud_audioStreamHeap = (JKRHeap *)0x0;
  return;
}


/* __stdcall mDoAud_executeStreamBuffer(void) */

void mDoAud_executeStreamBuffer(void)

{
  return;
}


/* __stdcall mDoAud_setupStreamBuffer(void) */

void mDoAud_setupStreamBuffer(undefined4 param_1,bool param_2)

{
  FuncDef579 *extraout_r4;
  FuncDef580 *extraout_r4_00;
  
  JAIGlobalParameter::setParamStreamInsideBufferCut((JAIGlobalParameter *)&DAT_00000001,param_2);
  mDoAud_StreamBufferPointer = 0;
  mDoAud_StreamBufferBlocks = 0xc;
  mDoAud_audioStreamHeap = 0;
  JAInter::StreamLib::setAllocBufferCallback((StreamLib *)mDoAud_allocStreamBuffer,extraout_r4);
  JAInter::StreamLib::setDeallocBufferCallback
            ((StreamLib *)mDoAud_deallocStreamBuffer,extraout_r4_00);
  return;
}


/* __stdcall mDoAud_Create(void) */

void mDoAud_Create(undefined4 param_1,undefined4 param_2)

{
  ulong uVar1;
  JKRArchive *pJVar2;
  undefined8 uVar3;
  SequenceMgr aSStack104 [104];
  
  uVar3 = CONCAT44(l_affCommand,param_2);
  if (l_affCommand == (JKRArchive *)0x0) {
    uVar3 = mDoDvdThd_toMainRam_c::create("/Audiores/JaiInit.aaf",2,(JKRHeap *)0x0);
    l_affCommand = (JKRArchive *)(int)((ulonglong)uVar3 >> 0x20);
    if (l_affCommand == (JKRArchive *)0x0) {
      return;
    }
  }
  l_affCommand = (JKRArchive *)((ulonglong)uVar3 >> 0x20);
  if (l_arcCommand == (mDoDvdThd_command_c *)0x0) {
    JAInter::SequenceMgr::getArchiveName(aSStack104,(char *)uVar3);
    l_arcCommand = mDoDvdThd_mountArchive_c::create((char *)aSStack104,'\0',(JKRHeap *)0x0);
    if (l_arcCommand == (mDoDvdThd_command_c *)0x0) {
      return;
    }
  }
  if ((*(char *)&(l_affCommand->parent).parent.mHeapLink.mpList != '\0') &&
     (l_arcCommand->mStatus != 0)) {
    pJVar2 = l_affCommand;
    JAIGlobalParameter::setParamInitDataPointer((l_affCommand->parent).mVolumeLink.mpList);
    JAInter::SequenceMgr::setArchivePointer((SequenceMgr *)l_arcCommand[1].parent.mpNextNode,pJVar2)
    ;
    mDoAud_setupStreamBuffer();
    if (g_mDoAud_audioHeap == (JKRSolidHeap *)0x0) {
      m_Do_printf::OSReport_Error
                ("ヒープ確保失敗につきオーディオ初期化できません\n");
    }
    else {
      JKRHeap::becomeCurrentHeap((JKRHeap *)0x0);
      JAIZelBasic::init((JAIZelBasic *)&g_mDoAud_zelAudio,(EVP_PKEY_CTX *)g_mDoAud_audioHeap);
      JKRHeap::becomeCurrentHeap(m_Do_ext::zeldaHeap);
      JKRSolidHeap::adjustSize(g_mDoAud_audioHeap);
    }
    JAIZelBasic::setEventBit
              ((JAIZelBasic *)&g_mDoAud_zelAudio,
               &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent);
    ::mDoAud_zelAudio_c::reset((mDoAud_zelAudio_c *)&g_mDoAud_zelAudio);
    uVar1 = os::OSGetSoundMode();
    JAIZelBasic::setOutputMode(JAIZelBasic::zel_basic,uVar1);
    JKRHeap::free((l_affCommand->parent).mVolumeLink.mpList,(JKRHeap *)0x0);
    if (l_affCommand != (JKRArchive *)0x0) {
      (*(code *)((l_affCommand->parent).parent.mHeapLink.mpPrev)->mpPrev)(l_affCommand,1);
    }
    if (l_arcCommand != (mDoDvdThd_command_c *)0x0) {
      (*(code *)l_arcCommand->vtbl->_mDoDvdThd_toMainRam_c)(l_arcCommand,1);
    }
    ::mDoAud_zelAudio_c::mInitFlag = 1;
    mDoDvdThd::SyncWidthSound = 1;
  }
  return;
}


/* __stdcall mDoAud_Execute(void) */

void mDoAud_Execute(void)

{
  mDoAud_zelAudio_c *this;
  
  if (::mDoAud_zelAudio_c::mInitFlag == '\0') {
    mDoAud_Create();
  }
  else {
    mDoAud_executeStreamBuffer();
    this = (mDoAud_zelAudio_c *)JAIZelBasic::gframeProcess((JAIZelBasic *)&g_mDoAud_zelAudio);
    ::mDoAud_zelAudio_c::calcLoadTimer(this);
  }
  return;
}


/* __stdcall mDoAud_getTactDirection(int,
                                     int) */

uint mDoAud_getTactDirection(int param_1,uint param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  
  fVar1 = m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickCValue;
  sVar4 = m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickCAngle;
  if (param_1 != 0) {
    fVar1 = m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainValue;
    sVar4 = m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainAngle;
  }
  if (_4149 <= fVar1) {
    iVar2 = MSL_C.PPCEABI.bare.H::abs((int)sVar4);
    if (param_2 == 0) {
      if (iVar2 < 0x6001) {
        uVar3 = SEXT24(sVar4);
        if ((int)uVar3 < 0x2000) {
          param_2 = ((uint)(uVar3 < 0xffffe001) - ((int)uVar3 >> 0x1f)) + 2;
        }
        else {
          param_2 = 2;
        }
      }
      else {
        param_2 = 1;
      }
    }
    else {
      if (iVar2 < 0x7001) {
        if ((sVar4 < 0x3000) || (0x5000 < sVar4)) {
          if ((sVar4 < -0x2fff) && (-0x5001 < sVar4)) {
            param_2 = 4;
          }
          else {
            if (iVar2 < 0x1000) {
              param_2 = 3;
            }
          }
        }
        else {
          param_2 = 2;
        }
      }
      else {
        param_2 = 1;
      }
    }
  }
  else {
    if (param_1 == 0) {
      param_2 = 0;
    }
    else {
      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton0 >> 5 & 1) == 0) {
        if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton0 >> 6 & 1) == 0) {
          if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton0 < '\0') {
            param_2 = 4;
          }
          else {
            param_2 = (uint)((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton0 >> 4 & 1) != 0);
          }
        }
        else {
          param_2 = 2;
        }
      }
      else {
        param_2 = 3;
      }
    }
  }
  return param_2;
}


/* __stdcall mDoAud_setSceneName(char const *,
                                 long,
                                 long) */

void mDoAud_setSceneName(char *pSceneName,long startCode,long layerNo)

{
  if (::mDoAud_zelAudio_c::mLoadTimer == '\0') {
    JAIZelBasic::setSceneName(JAIZelBasic::zel_basic,pSceneName,startCode,layerNo);
    ::mDoAud_zelAudio_c::mLoadTimer = '$';
  }
  return;
}


/* __stdcall mDoAud_load1stDynamicWave(void) */

undefined4 mDoAud_load1stDynamicWave(void)

{
  undefined4 uVar1;
  
  if (::mDoAud_zelAudio_c::mLoadTimer == 0) {
    uVar1 = 1;
  }
  else {
    if (::mDoAud_zelAudio_c::mLoadTimer < 2) {
      JAIZelBasic::load1stDynamicWave(JAIZelBasic::zel_basic);
      ::mDoAud_zelAudio_c::mLoadTimer = 0;
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* __stdcall cLib_calcTimer<unsigned char>(unsigned char *) */

char cLib_calcTimer(char *param_1)

{
  if (*param_1 != '\0') {
    *param_1 = *param_1 + -1;
  }
  return *param_1;
}


void __sinit_m_Do_audio_cpp(void)

{
  ::JAIZelInst::JAIZelInst(&::mDoAud_zelAudio_c::mTact);
  Runtime.PPCEABI.H::__register_global_object();
  JAIZelBasic::JAIZelBasic((JAIZelBasic *)&g_mDoAud_zelAudio);
  g_mDoAud_zelAudio = &::mDoAud_zelAudio_c::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&g_mDoAud_zelAudio,::mDoAud_zelAudio_c::_mDoAud_zelAudio_c,&_3978);
  return;
}

}

/* __thiscall mDoAud_zelAudio_c::~mDoAud_zelAudio_c(void) */

void __thiscall mDoAud_zelAudio_c::_mDoAud_zelAudio_c(mDoAud_zelAudio_c *this)

{
  short in_r4;
  
  if (this != (mDoAud_zelAudio_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (mDoAud_zelAudio_c *)0x0) {
      *(undefined1 **)this = &JAIZelBasic::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JAIZelInst::~JAIZelInst(void) */

void __thiscall JAIZelInst::_JAIZelInst(JAIZelInst *this)

{
  short in_r4;
  
  if ((this != (JAIZelInst *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

