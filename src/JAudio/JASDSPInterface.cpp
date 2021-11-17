#include <JAudio/JASDSPInterface.h>
#include <JAudio/dspproc.h>
#include <os/OSCache.h>
#include <JAudio/JASCalc.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JAudio/JASDSPInterface.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <os/OSInterrupt.h>
#include <JASystem/DSPInterface.h>
#include <JASystem/DSPInterface/DSPBuffer.h>
#include <JASystem/DSPInterface/FXBuffer.h>


namespace JASystem {
undefined1 DSPInterface;
undefined1 DSPInterface;
undefined1 DSPInterface;
undefined1 DSPInterface;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DSPInterface::setDSPMixerLevel(float) */

void __thiscall DSPInterface::setDSPMixerLevel(DSPInterface *this,float param_1)

{
  _sDSPVolume = param_1;
  JAudio::DsetMixerLevel();
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DSPInterface::getDSPHandle(unsigned char) */

int __thiscall DSPInterface::getDSPHandle(DSPInterface *this,uchar param_1)

{
  return _CH_BUF + ((uint)this & 0xff) * 0x180;
}


/* __thiscall DSPInterface::setFilterTable(short *,
                                                     short *,
                                                     unsigned long) */

void __thiscall
DSPInterface::setFilterTable
          (DSPInterface *this,short *param_1,short *param_2,ulong param_3)

{
  if (param_2 == (short *)0x0) {
    return;
  }
  do {
    *(short *)this = *param_1;
    this = (DSPInterface *)((int)this + 2);
    param_1 = param_1 + 1;
    param_2 = (short *)((int)param_2 + -1);
  } while (param_2 != (short *)0x0);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DSPInterface::flushBuffer(void) */

void __thiscall DSPInterface::flushBuffer(DSPInterface *this)

{
  os::DCFlushRange(_CH_BUF,0x6000);
  os::DCFlushRange(_FX_BUF,0x80);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DSPInterface::invalChannelAll(void) */

void __thiscall DSPInterface::invalChannelAll(DSPInterface *this)

{
  os::DCInvalidateRange(_CH_BUF,0x6000);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DSPInterface::clearBuffer(void) */

void __thiscall DSPInterface::clearBuffer(DSPInterface *this)

{
  size_t in_r5;
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    Calc::bzero((Calc *)(_CH_BUF + iVar2),(void *)0x180,in_r5);
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 0x180;
  } while (uVar1 < 0x40);
  uVar1 = 0;
  iVar2 = 0;
  do {
    Calc::bzero((Calc *)(_FX_BUF + iVar2),&DAT_00000020,in_r5);
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 0x20;
  } while (uVar1 < 4);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DSPInterface::setupBuffer(void) */

void __thiscall DSPInterface::setupBuffer(DSPInterface *this)

{
  JAudio::DsetupTable(0x40,_CH_BUF,&DSPRES_FILTER,&DSPADPCM_FILTER,_FX_BUF);
  JAudio::DsetDolbyDelay(&DOLBY2_DELAY_BUF,10);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DSPInterface::initBuffer(void) */

void __thiscall DSPInterface::initBuffer(DSPInterface *this)

{
  bool bVar1;
  DSPInterface *pDVar2;
  ulong uVar3;
  byte bVar4;
  
  _CH_BUF = JKernel::operator_new__(0x6000,JAudio::JASDram,0x20);
  pDVar2 = (DSPInterface *)JKernel::operator_new__(0x80,JAudio::JASDram,0x20);
  bVar1 = false;
  if ((_CH_BUF != 0) && (pDVar2 != (DSPInterface *)0x0)) {
    bVar1 = true;
  }
  _FX_BUF = pDVar2;
  if (!bVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"JASDSPInterface.cpp",0xa3,"(CH_BUF != 0) && (FX_BUF != 0)");
    pDVar2 = (DSPInterface *)m_Do_printf::OSPanic("JASDSPInterface.cpp",0xa3,&DAT_8036831b);
  }
  for (bVar4 = 0; bVar4 < 4; bVar4 = bVar4 + 1) {
    pDVar2 = (DSPInterface *)
             FXBuffer::setFXLine((FXBuffer *)(_FX_BUF + (uint)bVar4 * 0x20),(short *)0x0,
                                 (FxlineConfig_ *)0x0);
  }
  pDVar2 = (DSPInterface *)clearBuffer(pDVar2);
  pDVar2 = (DSPInterface *)setupBuffer(pDVar2);
  flushBuffer(pDVar2);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DSPInterface::getFXHandle(unsigned char) */

int __thiscall DSPInterface::getFXHandle(DSPInterface *this,uchar param_1)

{
  return _FX_BUF + ((uint)this & 0xff) * 0x20;
}


namespace DSPInterface {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8028a484) */
/* __thiscall FXBuffer::setFXLine(short *,
                                                          FxlineConfig_ *)
    */

undefined4 __thiscall
FXBuffer::setFXLine(FXBuffer *this,short *param_1,FxlineConfig_ *param_2)

{
  int iVar1;
  undefined4 uVar2;
  ulong uVar3;
  FxlineConfig_ *__n;
  ulong in_r6;
  
  __n = param_2;
  uVar2 = os::OSDisableInterrupts();
  *(undefined2 *)this = 0;
  if (param_2 != (FxlineConfig_ *)0x0) {
    *(undefined2 *)(this + 10) = *(undefined2 *)(param_2 + 4);
    *(undefined2 *)(this + 8) = *(undefined2 *)(&SEND_TABLE + (uint)*(ushort *)(param_2 + 2) * 2);
    *(undefined2 *)(this + 0xe) = *(undefined2 *)(param_2 + 8);
    *(undefined2 *)(this + 0xc) = *(undefined2 *)(&SEND_TABLE + (uint)*(ushort *)(param_2 + 6) * 2);
    *(short *)(this + 2) = (short)*(undefined4 *)(param_2 + 0xc);
    m_Do_printf::OSReport("FX LINE Buffer %x/ SIZE %d\n",param_1,*(undefined4 *)(param_2 + 0xc));
    __n = (FxlineConfig_ *)&DAT_00000008;
    setFilterTable((DSPInterface *)(this + 0x10),(short *)(param_2 + 0x10),(short *)&DAT_00000008,
                   in_r6);
  }
  if ((param_1 == (short *)0x0) || (param_2 == (FxlineConfig_ *)0x0)) {
    if ((param_2 == (FxlineConfig_ *)0x0) || (param_1 != (short *)0x0)) {
      *(short **)(this + 4) = param_1;
    }
  }
  else {
    iVar1 = *(int *)(param_2 + 0xc);
    *(short **)(this + 4) = param_1;
    Calc::bzero((Calc *)param_1,(void *)(iVar1 * 0xa0),(size_t)__n);
    if (((uint)param_1 & 0x1f) != 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar3,"JASDSPInterface.cpp",0xdb,"(reinterpret_cast<u32>(buffer) & 0x1f) == 0");
      m_Do_printf::OSPanic("JASDSPInterface.cpp",0xdb,&DAT_8036831b);
    }
    os::DCFlushRange(param_1,(void *)(iVar1 * 0xa0));
  }
  if (*(int *)(this + 4) == 0) {
    *(undefined2 *)this = 0;
  }
  else {
    *(ushort *)this = (ushort)(byte)*param_2;
  }
  os::DCFlushRange(this,0x20);
  os::OSRestoreInterrupts(uVar2);
  return 1;
}


/* __thiscall DSPBuffer::allocInit(void) */

void __thiscall DSPBuffer::allocInit(DSPBuffer *this)

{
  *(undefined2 *)(this + 0xc) = 0;
  *(undefined2 *)(this + 2) = 0;
  *(undefined2 *)(this + 0x10a) = 0;
  *(undefined2 *)this = 0;
  *(undefined2 *)(this + 0x58) = 0;
  initFilter(this);
  flushChannel(this);
  return;
}


/* __thiscall DSPBuffer::playStart(void) */

void __thiscall DSPBuffer::playStart(DSPBuffer *this)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(this + 0x10c) = 0;
  *(undefined2 *)(this + 0x60) = 0;
  *(undefined2 *)(this + 8) = 1;
  *(undefined2 *)(this + 0x66) = 0;
  iVar1 = 0;
  iVar2 = 4;
  do {
    *(undefined2 *)(this + iVar1 + 0x78) = 0;
    *(undefined2 *)(this + iVar1 + 0xa8) = 0;
    iVar1 = iVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = 0;
  iVar2 = 0x14;
  do {
    *(undefined2 *)(this + iVar1 + 0x80) = 0;
    iVar1 = iVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined2 *)this = 1;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8028a68c) */
/* __thiscall DSPBuffer::setWaveInfo(JASystem::Driver::Wave_ *,
                                                             unsigned long,
                                                             unsigned long) */

void __thiscall
DSPBuffer::setWaveInfo
          (DSPBuffer *this,Wave_ *param_1,ulong param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  
  *(ulong *)(this + 0x118) = param_2;
  *(ushort *)(this + 100) = (ushort)(byte)(&JAudio::COMP_BLOCKSAMPLES_485)[(byte)param_1[1]];
  *(ushort *)(this + 0x100) = (ushort)(byte)(&JAudio::COMP_BLOCKBYTES_486)[(byte)param_1[1]];
  *(undefined4 *)(this + 0x68) = 0;
  if (3 < *(ushort *)(this + 0x100)) {
    *(undefined4 *)(this + 0x11c) = *(undefined4 *)(param_1 + 0x1c);
    *(short *)(this + 0x102) = (short)*(undefined4 *)(param_1 + 0x10);
    if (*(short *)(this + 0x102) == 0) {
      *(undefined4 *)(this + 0x114) = *(undefined4 *)(this + 0x11c);
    }
    else {
      if (param_3 == 1) {
        param_3 = *(ulong *)(param_1 + 0x14);
      }
      *(undefined4 *)(this + 0x110) = *(undefined4 *)(param_1 + 0x14);
      *(undefined4 *)(this + 0x114) = *(undefined4 *)(param_1 + 0x18);
      *(undefined2 *)(this + 0x104) = *(undefined2 *)(param_1 + 0x20);
      *(undefined2 *)(this + 0x106) = *(undefined2 *)(param_1 + 0x22);
    }
    if ((param_3 != 0) && (param_3 < *(uint *)(this + 0x114))) {
      if ((byte)param_1[1] < 2) {
        *(ulong *)(this + 0x68) = param_3;
        *(ulong *)(this + 0x118) =
             *(int *)(this + 0x118) + (param_3 * *(ushort *)(this + 0x100) >> 4);
        *(ulong *)(this + 0x110) = *(int *)(this + 0x110) - param_3;
        *(ulong *)(this + 0x114) = *(int *)(this + 0x114) - param_3;
      }
      else {
        if ((byte)param_1[1] < 4) {
          *(ulong *)(this + 0x68) = param_3;
        }
      }
    }
    iVar1 = 0;
    iVar2 = 0x10;
    do {
      *(undefined2 *)(this + iVar1 + 0xb0) = 0;
      iVar1 = iVar1 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    return;
  }
  return;
}


/* __thiscall DSPBuffer::setOscInfo(unsigned long) */

void __thiscall DSPBuffer::setOscInfo(DSPBuffer *this,ulong param_1)

{
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined2 *)(this + 100) = 0x10;
  *(short *)(this + 0x100) = (short)param_1;
  return;
}


/* __thiscall DSPBuffer::initAutoMixer(void) */

void __thiscall DSPBuffer::initAutoMixer(DSPBuffer *this)

{
  if (*(short *)(this + 0x58) != 0) {
    *(undefined2 *)(this + 0x54) = *(undefined2 *)(this + 0x56);
    return;
  }
  *(undefined2 *)(this + 0x54) = 0;
  *(undefined2 *)(this + 0x58) = 1;
  return;
}


/* __thiscall DSPBuffer::setAutoMixer(unsigned short,
                                                              unsigned char,
                                                              unsigned char,
                                                              unsigned char,
                                                              unsigned char) */

void __thiscall
DSPBuffer::setAutoMixer
          (DSPBuffer *this,ushort param_1,uchar param_2,uchar param_3,uchar param_4,uchar param_5)

{
  *(ushort *)(this + 0x50) = CONCAT11(param_2,param_3);
  *(ushort *)(this + 0x52) = (ushort)param_4 << 8;
  *(ushort *)(this + 0x56) = param_1;
  *(undefined2 *)(this + 0x58) = 1;
  return;
}


/* __thiscall DSPBuffer::setPitch(unsigned short) */

void __thiscall DSPBuffer::setPitch(DSPBuffer *this,ushort param_1)

{
  if (0x7ffe < param_1) {
    param_1 = 0x7fff;
  }
  *(ushort *)(this + 4) = param_1;
  return;
}


/* __thiscall DSPBuffer::setMixerInitDelayMax(unsigned char) */

void __thiscall
DSPBuffer::setMixerInitDelayMax(DSPBuffer *this,uchar param_1)

{
  *(ushort *)(this + 0xe) = (ushort)param_1;
  return;
}


/* __thiscall DSPBuffer::setMixerInitVolume(unsigned char,
                                                                    short,
                                                                    unsigned char) */

void __thiscall
DSPBuffer::setMixerInitVolume
          (DSPBuffer *this,uchar param_1,short param_2,uchar param_3)

{
  DSPBuffer *pDVar1;
  
  pDVar1 = this + (uint)param_1 * 8 + 0x10;
  *(short *)(pDVar1 + 4) = param_2;
  *(short *)(pDVar1 + 2) = param_2;
  *(ushort *)(pDVar1 + 6) = CONCAT11(param_3,param_3);
  return;
}


/* __thiscall DSPBuffer::setMixerVolume(unsigned char,
                                                                short,
                                                                unsigned char) */

void __thiscall
DSPBuffer::setMixerVolume
          (DSPBuffer *this,uchar param_1,short param_2,uchar param_3)

{
  DSPBuffer *pDVar1;
  
  if (*(short *)(this + 0x10a) != 0) {
    return;
  }
  pDVar1 = this + (uint)param_1 * 8 + 0x10;
  *(short *)(pDVar1 + 2) = param_2;
  *(ushort *)(pDVar1 + 6) = (ushort)param_3 << 8 | *(ushort *)(pDVar1 + 6) & 0xff;
  return;
}


/* __thiscall DSPBuffer::setMixerVolumeOnly(unsigned char,
                                                                    short) */

void __thiscall
DSPBuffer::setMixerVolumeOnly(DSPBuffer *this,uchar param_1,short param_2)

{
  if (*(short *)(this + 0x10a) != 0) {
    return;
  }
  *(short *)(this + (uint)param_1 * 8 + 0x12) = param_2;
  return;
}


/* __thiscall DSPBuffer::setPauseFlag(unsigned char) */

void __thiscall DSPBuffer::setPauseFlag(DSPBuffer *this,uchar param_1)

{
  *(ushort *)(this + 0xc) = (ushort)param_1;
  return;
}


/* __thiscall DSPBuffer::flushChannel(void) */

void __thiscall DSPBuffer::flushChannel(DSPBuffer *this)

{
  os::DCFlushRange(this,0x180);
  return;
}


/* __thiscall DSPBuffer::initFilter(void) */

void __thiscall DSPBuffer::initFilter(DSPBuffer *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 8;
  do {
    *(undefined2 *)(this + iVar1 + 0x120) = 0;
    iVar1 = iVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined2 *)(this + 0x120) = 0x7fff;
  iVar1 = 0;
  iVar2 = 4;
  do {
    *(undefined2 *)(this + iVar1 + 0x148) = 0;
    iVar1 = iVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined2 *)(this + 0x148) = 0x7fff;
  *(undefined2 *)(this + 0x150) = 0;
  return;
}


/* __thiscall DSPBuffer::setFilterMode(unsigned short) */

void __thiscall DSPBuffer::setFilterMode(DSPBuffer *this,ushort param_1)

{
  ushort uVar1;
  
  uVar1 = param_1 & 0x1f;
  if ((param_1 & 0x20) == 0) {
    if (0x18 < uVar1) {
      uVar1 = 0x18;
    }
  }
  else {
    if (0x14 < uVar1) {
      uVar1 = 0x14;
    }
  }
  *(ushort *)(this + 0x108) = (param_1 & 0x20) + uVar1;
  return;
}


/* __thiscall DSPBuffer::setIIRFilterParam(short *) */

void __thiscall DSPBuffer::setIIRFilterParam(DSPBuffer *this,short *param_1)

{
  ulong in_r6;
  
  setFilterTable((DSPInterface *)(this + 0x148),param_1,(short *)&DAT_00000004,in_r6);
  return;
}


/* __thiscall DSPBuffer::setFIR8FilterParam(short *) */

void __thiscall
DSPBuffer::setFIR8FilterParam(DSPBuffer *this,short *param_1)

{
  ulong in_r6;
  
  setFilterTable((DSPInterface *)(this + 0x120),param_1,(short *)&DAT_00000008,in_r6);
  return;
}


/* __thiscall DSPBuffer::setDistFilter(short) */

void __thiscall DSPBuffer::setDistFilter(DSPBuffer *this,short param_1)

{
  *(short *)(this + 0x150) = param_1;
  return;
}


/* __thiscall DSPBuffer::setBusConnect(unsigned char,
                                                               unsigned char) */

void __thiscall
DSPBuffer::setBusConnect(DSPBuffer *this,uchar param_1,uchar param_2)

{
  *(undefined2 *)(this + (uint)param_1 * 8 + 0x10) =
       *(undefined2 *)(&JAudio::connect_table_627 + (uint)param_2 * 2);
  return;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall DSP_CreateMap2(unsigned long) */

uint DSP_CreateMap2(int param_1)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  psVar1 = (short *)(_CH_BUF + param_1 * 0x1800);
  iVar3 = 0x10;
  do {
    uVar2 = (uVar2 & 0x7fff) << 1;
    if (*psVar1 != 0) {
      uVar2 = uVar2 | 1;
    }
    psVar1 = psVar1 + 0xc0;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return uVar2;
}

