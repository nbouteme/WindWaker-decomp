#include <JAudio/JASDSPBuf.h>
#include <JKernel/JKRHeap.h>
#include <os/OSCache.h>
#include <m_Do_printf.h>
#include <JAudio/JASProbe.h>
#include <JAudio/JASDSPInterface.h>
#include <JAudio/JASCallback.h>
#include <JAudio/JASDSPChannel.h>
#include <JAudio/JASDSPBuf.h>
#include <JASystem/TDSP_DACBuffer.h>


namespace JASystem {
undefined1 TDSP_DACBuffer;
undefined1 TDSP_DACBuffer;
undefined1 TDSP_DACBuffer;
undefined1 TDSP_DACBuffer;
undefined1 TDSP_DACBuffer;
undefined1 TDSP_DACBuffer;
undefined1 TDSP_DACBuffer;

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TDSP_DACBuffer::init(void) */

int __thiscall TDSP_DACBuffer::init(TDSP_DACBuffer *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = _gFrameSamples;
  if (_isInit == 0) {
    writeBuffer = numDSPBuf - 1;
    readBuffer = 0;
    _dsp_buf = JKernel::operator_new__((uint)numDSPBuf << 2,JAudio::JASDram,0x20);
    iVar6 = 0;
    iVar1 = iVar2 << 1;
    iVar2 = iVar2 << 2;
    for (iVar5 = 0; iVar5 < (int)(uint)numDSPBuf; iVar5 = iVar5 + 1) {
      uVar3 = JKernel::operator_new__(iVar2,JAudio::JASDram,0x20);
      *(undefined4 *)(_dsp_buf + iVar6) = uVar3;
      iVar4 = 0;
      for (iVar7 = iVar1; iVar7 != 0; iVar7 = iVar7 + -1) {
        *(undefined2 *)(*(int *)(iVar6 + _dsp_buf) + iVar4) = 0;
        iVar4 = iVar4 + 2;
      }
      os::DCStoreRange(*(undefined4 *)(_dsp_buf + iVar6),iVar2);
      iVar6 = iVar6 + 4;
    }
    this = (TDSP_DACBuffer *)m_Do_printf::OSReport("DSP_DAC buffer size : %d\n",iVar1);
    dspStatus = 0;
    _isInit = 1;
  }
  return (int)this;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TDSP_DACBuffer::updateDSP(void) */

void __thiscall TDSP_DACBuffer::updateDSP(TDSP_DACBuffer *this)

{
  DSPInterface *this_00;
  Kernel *pKVar1;
  TDSPChannel *this_01;
  long extraout_r4;
  char *in_r5;
  
  _dacSyncCounter = _dacSyncCounter + 1;
  this_00 = (DSPInterface *)Kernel::probeStart((Kernel *)&DAT_00000003,(long)"SFR-UPDATE",in_r5);
  pKVar1 = (Kernel *)DSPInterface::invalChannelAll(this_00);
  this_01 = (TDSPChannel *)Kernel::subframeCallback(pKVar1);
  pKVar1 = (Kernel *)TDSPChannel::updateAll(this_01);
  Kernel::aiCallback(pKVar1);
  Kernel::probeFinish((Kernel *)&DAT_00000003,extraout_r4);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TDSP_DACBuffer::mixDSP(long) */

undefined4 __thiscall TDSP_DACBuffer::mixDSP(TDSP_DACBuffer *this,long param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  TDSP_DACBuffer *pTVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = _gFrameSamples;
  uVar5 = readBuffer + 1 & 0xff;
  if (uVar5 == numDSPBuf) {
    uVar5 = 0;
  }
  if ((uVar5 == writeBuffer) && (2 < numDSPBuf)) {
    iVar3 = *(int *)(_dsp_buf + (uint)readBuffer * 4) + -2;
    uVar1 = *(undefined2 *)(iVar3 + (_gFrameSamples & 0xfffffffe));
    uVar5 = _gFrameSamples * 2;
    uVar2 = *(undefined2 *)(iVar3 + uVar5);
    iVar3 = 0;
    uVar6 = _gFrameSamples;
    if (_gFrameSamples != 0) {
      do {
        *(undefined2 *)(*(int *)(_dsp_buf + (uint)readBuffer * 4) + iVar3) = uVar1;
        iVar3 = iVar3 + 2;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    iVar3 = uVar7 << 1;
    if (uVar7 < uVar5) {
      do {
        *(undefined2 *)(*(int *)(_dsp_buf + (uint)readBuffer * 4) + iVar3) = uVar2;
        iVar3 = iVar3 + 2;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    if (dspStatus == '\0') {
      pTVar4 = (TDSP_DACBuffer *)
               m_Do_printf::OSReport("----- JASDSPBuf::process DACSYNC -- DSP Wait\n");
      finishDSPFrame(pTVar4);
    }
  }
  else {
    readBuffer = (byte)uVar5;
    pTVar4 = (TDSP_DACBuffer *)
             os::DCInvalidateRange(*(undefined4 *)(_dsp_buf + uVar5 * 4),_gFrameSamples << 2);
    if (dspStatus == '\0') {
      finishDSPFrame(pTVar4);
    }
  }
  return *(undefined4 *)(_dsp_buf + (uint)readBuffer * 4);
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TDSP_DACBuffer::finishDSPFrame(void) */

void __thiscall TDSP_DACBuffer::finishDSPFrame(TDSP_DACBuffer *this)

{
  int iVar1;
  TDSP_DACBuffer *this_00;
  byte bVar3;
  int iVar2;
  char *in_r5;
  
  iVar1 = _gFrameSamples;
  bVar3 = writeBuffer + 1;
  if (bVar3 == numDSPBuf) {
    bVar3 = 0;
  }
  if (bVar3 == readBuffer) {
    dspStatus = 0;
  }
  else {
    _snIntCount = _gSubFrames;
    writeBuffer = bVar3;
    Kernel::probeStart((Kernel *)&DAT_00000007,(long)"DSP-MAIN",in_r5);
    iVar2 = *(int *)(_dsp_buf + (uint)writeBuffer * 4);
    this_00 = (TDSP_DACBuffer *)JAudio::DsyncFrame2(_gSubFrames,iVar2,iVar2 + iVar1 * 2);
    dspStatus = 1;
    updateDSP(this_00);
    if (_callback != (code *)0x0) {
      (*_callback)(*(undefined4 *)(_dsp_buf + (uint)writeBuffer * 4),iVar1);
    }
  }
  return;
}

