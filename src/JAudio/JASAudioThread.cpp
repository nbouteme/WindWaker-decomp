#include <JAudio/JASAudioThread.h>
#include <JAudio/JASProbe.h>
#include <os/OSMessage.h>
#include <JKernel/JKRThread.h>
#include <JAudio/JASAiCtrl.h>
#include <JAudio/JASDSPBuf.h>
#include <JAudio/JASAudioThread.h>
#include <JAudio/JASDriverIF.h>
#include <ai/ai.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <os/OSThread.h>
#include <dsp/dsp.h>
#include <JAudio/JASSystemHeap.h>
#include <JAudio/JASDvdThread.h>
#include <JAudio/JASKernelDebug.h>
#include <JASystem/TAudioThread.h>


namespace JASystem {
undefined1 TAudioThread;
undefined1 TAudioThread;
undefined1 TAudioThread;
undefined1 TAudioThread;
undefined1 TAudioThread;
undefined1 TAudioThread;
undefined1 TAudioThread;
undefined1 TAudioThread;
undefined1 TAudioThread;
}

namespace JAudio {
undefined4 first$357;
undefined1 init$358;
}

namespace JASystem {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TAudioThread::syncAudio(void) */

void __thiscall TAudioThread::syncAudio(TAudioThread *this)

{
  long in_r4;
  char *in_r5;
  
  if (JAudio::init_358 == '\0') {
    JAudio::first_357 = 1;
    JAudio::init_358 = '\x01';
  }
  if (JAudio::first_357 == 0) {
    Kernel::probeFinish((Kernel *)&DAT_00000004,in_r4);
  }
  JAudio::first_357 = 0;
  Kernel::probeStart((Kernel *)&DAT_00000004,(long)"UPDATE-DAC",in_r5);
  if (_sAudioprocMQInit != 0) {
    os::OSSendMessage(&sAudioprocMQ,0,0);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TAudioThread::audioproc(void *) */

void __thiscall TAudioThread::audioproc(TAudioThread *this,void *param_1)

{
  Kernel *pKVar1;
  TDSP_DACBuffer *pTVar2;
  int iVar3;
  ulong uVar4;
  EVP_PKEY_CTX *ctx;
  long extraout_r4;
  char *pcVar5;
  undefined8 uVar6;
  int local_78;
  JKRThread JStack116;
  
  JKRThread::JKRThread(&JStack116,(OSThread *)&sAudioThread,0);
  pKVar1 = (Kernel *)&sAudioprocMQ;
  ctx = (EVP_PKEY_CTX *)&saAudioMsgBuf;
  os::OSInitMessageQueue((OSMessageQueue *)&sAudioprocMQ,(OSMessage *)&saAudioMsgBuf,0x10);
  _sAudioprocMQInit = 1;
  pTVar2 = (TDSP_DACBuffer *)Kernel::init(pKVar1,ctx);
  iVar3 = TDSP_DACBuffer::init(pTVar2,ctx);
  uVar6 = CONCAT44(iVar3,ctx);
  if (_sbIsDSPBoot == 0) {
    uVar6 = JAudio::DspBoot(syncDSP);
    _sbIsDSPBoot = 1;
  }
  Driver::init((Driver *)((ulonglong)uVar6 >> 0x20),(EVP_PKEY_CTX *)uVar6);
  ai::AISetDSPSampleRate(_gAiSetting);
  ai::AIRegisterDMACallback(syncAudio);
  ai::AIStartDMA();
  do {
    while( true ) {
      while( true ) {
        do {
          pcVar5 = &DAT_00000001;
          pKVar1 = (Kernel *)os::OSReceiveMessage(&sAudioprocMQ,&local_78);
        } while (local_78 == 2);
        if (local_78 < 2) break;
        if (local_78 < 4) {
          m_Do_printf::OSReport("----- Audio thread stops\n");
          os::OSExitThread(0);
        }
      }
      if (local_78 == 0) break;
      if (-1 < local_78) {
        if (_snIntCount == 0) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar4,"JASAudioThread.cpp",0x91,"snIntCount != 0");
          pcVar5 = "Halt";
          m_Do_printf::OSPanic("JASAudioThread.cpp",0x91);
        }
        iVar3 = _snIntCount;
        _snIntCount = _snIntCount + -1;
        if (_snIntCount == 0) {
          pTVar2 = (TDSP_DACBuffer *)Kernel::probeFinish((Kernel *)&DAT_00000007,iVar3);
          TDSP_DACBuffer::finishDSPFrame(pTVar2);
        }
        else {
          pTVar2 = (TDSP_DACBuffer *)
                   Kernel::probeStart((Kernel *)&DAT_00000002,(long)"SFR_DSP",pcVar5);
          TDSP_DACBuffer::updateDSP(pTVar2);
          Kernel::probeFinish((Kernel *)&DAT_00000002,extraout_r4);
        }
      }
    }
    Kernel::updateDac(pKVar1);
  } while( true );
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TAudioThread::syncDSP(void *) */

void __thiscall TAudioThread::syncDSP(TAudioThread *this,void *param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = CONCAT44(this,param_1);
  do {
    uVar3 = dsp::DSPCheckMailFromDSP((int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
  } while ((int)((ulonglong)uVar3 >> 0x20) == 0);
  uVar1 = dsp::DSPReadMailFromDSP();
  if (uVar1 >> 0x10 == (uint)_JAS_DSP_PREFIX) {
    if ((uVar1 & 0xff00) == 0xff00) {
      if (_sAudioprocMQInit == 0) {
        JAudio::DSPReleaseHalt();
      }
      else {
        iVar2 = os::OSSendMessage(&sAudioprocMQ,1,0);
        if (iVar2 == 0) {
          m_Do_printf::OSReport("----- syncDSP : Send Miss\n");
        }
      }
    }
    else {
      JAudio::DspFinishWork(uVar1 & 0xffff);
    }
  }
  else {
    m_Do_printf::OSReport("----- syncDSP : Mail format error %x\n");
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TAudioThread::setPriority(unsigned char,
                                                  unsigned char) */

void __thiscall TAudioThread::setPriority(TAudioThread *this,uchar param_1,uchar param_2)

{
  _sbIsPrioritySet = 1;
  _sDSPPrio = (uint)this & 0xff;
  _sDVDPrio = (uint)param_1;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TAudioThread::start(JKRSolidHeap *,
                                            unsigned long,
                                            unsigned long) */

void __thiscall
TAudioThread::start(TAudioThread *this,JKRSolidHeap *param_1,ulong param_2,ulong param_3)

{
  int iVar1;
  Dvd *this_00;
  JKRSolidHeap *pJVar2;
  ulong extraout_r4;
  ulong uVar3;
  undefined8 uVar4;
  
  pJVar2 = param_1;
  if (_sbIsPrioritySet == 0) {
    os::OSGetCurrentThread();
    uVar4 = os::OSGetThreadPriority();
    iVar1 = (int)((ulonglong)uVar4 >> 0x20);
    pJVar2 = (JKRSolidHeap *)uVar4;
    _sDSPPrio = iVar1 + -3;
    _sDVDPrio = (Dvd *)(iVar1 + -4);
  }
  Kernel::sysDramSetup((Kernel *)this,pJVar2);
  Kernel::sysAramSetup((Kernel *)param_1,extraout_r4);
  uVar3 = 0x1000;
  this_00 = (Dvd *)Dvd::createThread(_sDVDPrio,0x5a,0x1000,param_3);
  Dvd::resumeThread(this_00);
  Kernel::stackInit((Kernel *)&saAudioStack,(long_long *)&DAT_00000200,uVar3);
  if ((param_2 & 2) != 0) {
    os::OSCreateThread(&sAudioThread,audioproc,0,&sAudioprocMQ,0x1000,_sDSPPrio,1);
    os::OSResumeThread((OSThread *)&sAudioThread);
  }
  return;
}

