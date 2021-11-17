#include <JAudio/JASChannel.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JAudio/JASOscillator.h>
#include <JAudio/JASChannel.h>
#include <JAudio/JASChAllocQueue.h>
#include <JAudio/JASChannelMgr.h>
#include <JAudio/JASDSPInterface.h>
#include <JAudio/JASDSPChannel.h>
#include <JAudio/JASDriverIF.h>
#include <JAudio/JASChGlobal.h>
#include <JAudio/JASCalc.h>
#include <Demangler/JASystem/TChannel.h>


namespace JASystem {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TChannel::init(void) */

int __thiscall TChannel::init(TChannel *this,EVP_PKEY_CTX *ctx)

{
  ushort uVar1;
  ulong uVar2;
  EVP_PKEY_CTX *ctx_00;
  EVP_PKEY_CTX *extraout_r4;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  ctx_00 = (EVP_PKEY_CTX *)0x0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  this[0xc] = (TChannel)0x0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0xd4) = 0;
  if (*(int *)(this + 4) == 0) {
    *(undefined2 *)(this + 0xb0) = 0x150;
    *(undefined2 *)(this + 0xb2) = 0x210;
    *(undefined2 *)(this + 0xb4) = 0x352;
    *(undefined2 *)(this + 0xb6) = 0x412;
    *(undefined2 *)(this + 0xb8) = 0;
    *(undefined2 *)(this + 0xba) = 0;
    *(undefined4 *)(this + 0x48) = 0x10101;
    *(undefined2 *)(this + 0x4c) = 600;
    this[0x60] = (TChannel)0x1a;
    this[0x61] = (TChannel)0x1;
    this[0x62] = (TChannel)0x1;
  }
  else {
    iVar5 = 6;
    do {
      *(undefined2 *)(this + (int)(ctx_00 + 0xb0)) =
           *(undefined2 *)(ctx_00 + *(int *)(this + 4) + 0x4e);
      ctx_00 = ctx_00 + 2;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    *(undefined4 *)(this + 0x48) = *(undefined4 *)(*(int *)(this + 4) + 0x68);
    *(undefined2 *)(this + 0x4c) = *(undefined2 *)(*(int *)(this + 4) + 0x6c);
    ctx_00 = (EVP_PKEY_CTX *)0x0;
    iVar5 = 3;
    do {
      this[(int)(ctx_00 + 0x60)] = *(TChannel *)(ctx_00 + *(int *)(this + 4) + 0x62);
      ctx_00 = ctx_00 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  uVar3 = 0;
  iVar5 = 0;
  do {
    iVar4 = iVar5 + 0x38;
    if (*(int *)(this + iVar4) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"JASChannel.cpp",0x9b,"osc[i]");
      m_Do_printf::OSPanic("JASChannel.cpp",0x9b,&DAT_803684ce);
      ctx_00 = extraout_r4;
    }
    **(undefined4 **)(this + iVar4) = 0;
    TOscillator::init(*(TOscillator **)(this + iVar4),ctx_00);
    uVar3 = uVar3 + 1;
    iVar5 = iVar5 + 4;
  } while (uVar3 < 4);
  this[2] = (TChannel)0x0;
  uVar1 = *(ushort *)(this + 200);
  *(ushort *)(this + 200) = uVar1 + 1;
  if (*(short *)(this + 200) == 0) {
    *(undefined2 *)(this + 200) = 1;
  }
  *(undefined4 *)(this + 0xe8) = 0;
  return (uint)uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TChannel::setOscillator(unsigned long,
                                                TOscillator *) */

void __thiscall TChannel::setOscillator(TChannel *this,ulong param_1,TOscillator *param_2)

{
  ulong uVar1;
  
  if (3 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASChannel.cpp",0xad,"oscnum < (4)");
    m_Do_printf::OSPanic("JASChannel.cpp",0xad,&DAT_803684ce);
  }
  *(TOscillator **)(this + param_1 * 4 + 0x38) = param_2;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TChannel::setOscInit(unsigned long,
                                             TOscillator::Osc_ const *) */

void __thiscall TChannel::setOscInit(TChannel *this,ulong param_1,Osc_ *param_2)

{
  ulong uVar1;
  
  if (3 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASChannel.cpp",0xb7,"oscnum < (4)");
    m_Do_printf::OSPanic("JASChannel.cpp",0xb7,&DAT_803684ce);
  }
  **(Osc_ ***)(this + param_1 * 4 + 0x38) = param_2;
  TOscillator::initStart(*(TOscillator **)(this + param_1 * 4 + 0x38));
  return;
}


/* __thiscall TChannel::forceStopOsc(unsigned long) */

undefined4 __thiscall TChannel::forceStopOsc(TChannel *this,ulong param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  
  if (3 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASChannel.cpp",0xc3,"numosc < (4)");
    m_Do_printf::OSPanic("JASChannel.cpp",0xc3,&DAT_803684ce);
  }
  if (**(int **)(this + param_1 * 4 + 0x38) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = TOscillator::forceStop((TOscillator *)*(int **)(this + param_1 * 4 + 0x38));
  }
  return uVar2;
}


/* __thiscall TChannel::releaseOsc(unsigned long) */

undefined4 __thiscall TChannel::releaseOsc(TChannel *this,ulong param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  
  if (3 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASChannel.cpp",0xd1,"numosc < (4)");
    m_Do_printf::OSPanic("JASChannel.cpp",0xd1,&DAT_803684ce);
  }
  if (**(int **)(this + param_1 * 4 + 0x38) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = TOscillator::release((TOscillator *)*(int **)(this + param_1 * 4 + 0x38));
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TChannel::directReleaseOsc(unsigned long,
                                                   unsigned short) */

void __thiscall TChannel::directReleaseOsc(TChannel *this,ulong param_1,ushort param_2)

{
  ulong uVar1;
  
  if (3 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASChannel.cpp",0xe0,"oscnum < (4)");
    m_Do_printf::OSPanic("JASChannel.cpp",0xe0,&DAT_803684ce);
  }
  *(ushort *)(*(int *)(this + param_1 * 4 + 0x38) + 0x18) = param_2;
  return;
}


/* __thiscall TChannel::bankOscToOfs(unsigned long) */

double __thiscall TChannel::bankOscToOfs(TChannel *this,ulong param_1)

{
  ulong uVar1;
  double dVar2;
  
  if (3 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASChannel.cpp",0xea,"oscnum < (4)");
    m_Do_printf::OSPanic("JASChannel.cpp",0xea,&DAT_803684ce);
  }
  if (**(int **)(this + param_1 * 4 + 0x38) == 0) {
    dVar2 = (double)JAudio::_468;
  }
  else {
    dVar2 = (double)TOscillator::getOffset((TOscillator *)*(int **)(this + param_1 * 4 + 0x38));
  }
  return dVar2;
}


/* WARNING: Removing unreachable block (ram,0x8028b970) */
/* WARNING: Removing unreachable block (ram,0x8028ba78) */
/* __thiscall TChannel::effectOsc(unsigned long,
                                            float) */

void __thiscall TChannel::effectOsc(TChannel *this,ulong param_1,float param_2)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  ulong uVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar6 = (double)param_2;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (3 < param_1) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"JASChannel.cpp",0xf6,"oscnum < (4)");
    m_Do_printf::OSPanic("JASChannel.cpp",0xf6,&DAT_803684ce);
  }
  bVar1 = ***(byte ***)(this + param_1 * 4 + 0x38);
  if (bVar1 == 2) {
    *(float *)(this + 0x74) = *(float *)(this + 0x74) + (float)(dVar6 - JAudio::_500);
    fVar2 = *(float *)(this + 0x74);
    fVar3 = JAudio::_501;
    if ((JAudio::_501 < fVar2) && (fVar3 = fVar2, JAudio::_468 <= fVar2)) {
      fVar3 = JAudio::_468;
    }
    *(float *)(this + 0x74) = fVar3;
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 == 0) {
        *(float *)(this + 0x98) = (float)((double)*(float *)(this + 0x98) * dVar6);
      }
      else {
        *(float *)(this + 0x94) = (float)((double)*(float *)(this + 0x94) * dVar6);
      }
    }
    else {
      if (bVar1 == 4) {
        *(float *)(this + 0x8c) = (float)((double)*(float *)(this + 0x8c) + dVar6);
        fVar2 = *(float *)(this + 0x8c);
        fVar3 = JAudio::_501;
        if ((JAudio::_501 < fVar2) && (fVar3 = fVar2, JAudio::_468 <= fVar2)) {
          fVar3 = JAudio::_468;
        }
        *(float *)(this + 0x8c) = fVar3;
      }
      else {
        if (bVar1 < 4) {
          *(float *)(this + 0x80) = (float)((double)*(float *)(this + 0x80) + dVar6);
          fVar2 = *(float *)(this + 0x80);
          fVar3 = JAudio::_501;
          if ((JAudio::_501 < fVar2) && (fVar3 = fVar2, JAudio::_468 <= fVar2)) {
            fVar3 = JAudio::_468;
          }
          *(float *)(this + 0x80) = fVar3;
        }
      }
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* __thiscall TChannel::getOscState(unsigned long) const */

undefined __thiscall TChannel::getOscState(TChannel *this,ulong param_1)

{
  ulong uVar1;
  
  if (3 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASChannel.cpp",0x112,"oscnum < (4)");
    m_Do_printf::OSPanic("JASChannel.cpp",0x112,&DAT_803684ce);
  }
  return *(undefined *)(*(int *)(this + param_1 * 4 + 0x38) + 4);
}


/* __thiscall TChannel::isOsc(unsigned long) */

bool __thiscall TChannel::isOsc(TChannel *this,ulong param_1)

{
  ulong uVar1;
  
  if (3 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASChannel.cpp",0x11c,"oscnum < (4)");
    m_Do_printf::OSPanic("JASChannel.cpp",0x11c,&DAT_803684ce);
  }
  return **(int **)(this + param_1 * 4 + 0x38) != 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TChannel::copyOsc(unsigned long,
                                          TOscillator::Osc_ *) */

void __thiscall TChannel::copyOsc(TChannel *this,ulong param_1,Osc_ *param_2)

{
  ulong uVar1;
  int iVar2;
  Osc_ *pOVar3;
  
  if (3 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASChannel.cpp",0x127,"oscnum < (4)");
    m_Do_printf::OSPanic("JASChannel.cpp",0x127,&DAT_803684ce);
  }
  iVar2 = isOsc(this,param_1);
  if (iVar2 == 0) {
    m_Do_printf::OSReport("osc[%d] is NULL\n",param_1);
  }
  else {
    pOVar3 = **(Osc_ ***)(this + param_1 * 4 + 0x38);
    *param_2 = *pOVar3;
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(pOVar3 + 4);
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(pOVar3 + 8);
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(pOVar3 + 0xc);
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(pOVar3 + 0x10);
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(pOVar3 + 0x14);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TChannel::overwriteOsc(unsigned long,
                                               TOscillator::Osc_ *) */

void __thiscall TChannel::overwriteOsc(TChannel *this,ulong param_1,Osc_ *param_2)

{
  ulong uVar1;
  double dVar2;
  
  if (3 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASChannel.cpp",0x134,"oscnum < (4)");
    m_Do_printf::OSPanic("JASChannel.cpp",0x134,&DAT_803684ce);
  }
  setOscInit(this,param_1,param_2);
  dVar2 = (double)bankOscToOfs(this,param_1);
  effectOsc(this,param_1,(float)dVar2);
  return;
}


/* __thiscall TChannel::setKeySweepTarget(unsigned char,
                                                    unsigned long) */

void __thiscall TChannel::setKeySweepTarget(TChannel *this,uchar param_1,ulong param_2)

{
  uint uVar1;
  
  if ((this[0xc] == (TChannel)0x2) || (*(int *)(this + 0x10) == 0)) {
    uVar1 = (uint)param_1;
  }
  else {
    uVar1 = (param_1 + 0x3c) - (uint)*(byte *)(*(int *)(this + 0x10) + 2);
  }
  if ((int)uVar1 < 0) {
    uVar1 = 0;
  }
  else {
    if (0x7f < (int)uVar1) {
      uVar1 = 0x7f;
    }
  }
  if (param_2 == 0) {
    *(float *)(this + 0x58) =
         *(float *)(&Driver::C5BASE_PITCHTABLE + uVar1 * 4) * *(float *)(this + 0x50);
    *(undefined4 *)(this + 0x2c) = 0;
    return;
  }
  *(float *)(this + 0x9c) =
       *(float *)(&Driver::C5BASE_PITCHTABLE + uVar1 * 4) * *(float *)(this + 0x50);
  *(short *)(this + 0xa2) = (short)param_2;
  *(code **)(this + 0x2c) = extraUpdate;
  return;
}


/* __thiscall TChannel::setPauseFlag(unsigned char) */

void __thiscall TChannel::setPauseFlag(TChannel *this,uchar param_1)

{
  this[2] = (TChannel)param_1;
  return;
}


/* __thiscall TChannel::setPauseFlagReq(unsigned char) */

void __thiscall TChannel::setPauseFlagReq(TChannel *this,uchar param_1)

{
  this[2] = (TChannel)param_1;
  this[3] = (TChannel)0x1;
  return;
}


/* __thiscall TChannel::checkLogicalChannel(void) */

undefined4 __thiscall TChannel::checkLogicalChannel(TChannel *this)

{
  undefined4 uVar1;
  
  if ((*(int *)(this + 0x10) == 0) && (this[0xc] == (TChannel)0x0)) {
    m_Do_printf::OSReport("----- checkLC : 波形がアサインされていません\n");
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall TChannel::play(unsigned long) */

bool __thiscall TChannel::play(TChannel *this,ulong param_1)

{
  bool bVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    param_1 = 0xffffffff;
  }
  *(ulong *)(this + 0x30) = param_1;
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(this + 0x30);
  *(code **)(this + 0x28) = updatecallLogicalChannel;
  *(undefined4 *)(this + 0x20) = 0;
  uVar2 = checkLogicalChannel(this);
  bVar1 = (int)((ulonglong)uVar2 >> 0x20) != 0;
  if (bVar1) {
    TDSPQueue::enQueue((TDSPQueue *)this,(TChannel *)uVar2);
    TChannelMgr::addListTail(*(TChannelMgr **)(this + 4),this,3);
  }
  return bVar1;
}


/* __thiscall TChannel::stop(unsigned short) */

void __thiscall TChannel::stop(TChannel *this,ushort param_1)

{
  undefined2 in_register_00000010;
  ulong uVar1;
  
  uVar1 = CONCAT22(in_register_00000010,param_1);
  if (*(int *)(this + 0x20) == 0) {
    updatecallLogicalChannel(this,(TChannel *)0x6,uVar1);
  }
  else {
    if (param_1 == 0) {
      updatecallLogicalChannel(this,(TChannel *)0x0,uVar1);
    }
    else {
      directReleaseOsc(this,0,param_1);
      updatecallLogicalChannel(this,(TChannel *)0x0,uVar1);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TChannel::updateJcToDSP(void) */

void __thiscall TChannel::updateJcToDSP(TChannel *this)

{
  byte bVar1;
  DSPBuffer *this_00;
  
  this_00 = *(DSPBuffer **)(*(int *)(this + 0x20) + 0xc);
  if (*(int *)(this + 0xd4) == 0) {
    bVar1 = 0;
    while( true ) {
      if (5 < bVar1) break;
      DSPInterface::DSPBuffer::setMixerVolume
                (this_00,bVar1,*(short *)(this + (uint)bVar1 * 2 + 0xbc),
                 *(uchar *)(*(int *)(this + 4) + bVar1 + 0x5a));
      bVar1 = bVar1 + 1;
    }
    DSPInterface::DSPBuffer::setPitch(this_00,*(ushort *)(this + 0xa0));
    if ((*(byte *)(*(int *)(this + 4) + 0x61) & 0x20) != 0) {
      DSPInterface::DSPBuffer::setIIRFilterParam(this_00,(short *)(*(int *)(this + 4) + 0x3c));
    }
    if ((*(byte *)(*(int *)(this + 4) + 0x61) & 0x1f) != 0) {
      DSPInterface::DSPBuffer::setFIR8FilterParam(this_00,(short *)(*(int *)(this + 4) + 0x2c));
    }
    DSPInterface::DSPBuffer::setFilterMode(this_00,(ushort)*(byte *)(*(int *)(this + 4) + 0x61));
    DSPInterface::DSPBuffer::setDistFilter(this_00,*(short *)(*(int *)(this + 4) + 0x4c));
    DSPInterface::DSPBuffer::setPauseFlag(this_00,(uchar)this[2]);
    DSPInterface::DSPBuffer::flushChannel(*(DSPBuffer **)(*(int *)(this + 0x20) + 0xc));
  }
  else {
    for (bVar1 = 0; bVar1 < 6; bVar1 = bVar1 + 1) {
      DSPInterface::DSPBuffer::setMixerVolumeOnly
                (this_00,bVar1,*(short *)(this + (uint)bVar1 * 2 + 0xbc));
    }
    DSPInterface::DSPBuffer::setPitch(this_00,*(ushort *)(this + 0xa0));
    DSPInterface::DSPBuffer::setPauseFlag(this_00,(uchar)this[2]);
    DSPInterface::DSPBuffer::flushChannel(this_00);
  }
  return;
}


/* __thiscall TChannel::forceStopLogicalChannel(void) */

bool __thiscall TChannel::forceStopLogicalChannel(TChannel *this)

{
  TDSPChannel *this_00;
  
  this_00 = *(TDSPChannel **)(this + 0x20);
  if (this_00 != (TDSPChannel *)0x0) {
    TDSPChannel::forceStop(this_00);
  }
  return this_00 != (TDSPChannel *)0x0;
}


/* __thiscall TChannel::stopLogicalChannel(void) */

bool __thiscall TChannel::stopLogicalChannel(TChannel *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x20);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined2 *)(*(int *)(this + 0x20) + 6) = 0;
    TDSPChannel::stop(*(TDSPChannel **)(this + 0x20));
    TDSPChannel::free(*(TDSPChannel **)(this + 0x20),this);
    *(undefined4 *)(this + 0x20) = 0;
  }
  else {
    m_Do_printf::OSReport("----- stopLC : DSP Ch is not assigned\n");
  }
  return iVar1 != 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8028c250) */
/* __thiscall TChannel::playLogicalChannel(void) */

undefined4 __thiscall TChannel::playLogicalChannel(TChannel *this)

{
  TChannel TVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  byte bVar6;
  ulong uVar5;
  DSPBuffer *this_00;
  double dVar7;
  byte local_18;
  
  if (*(int *)(this + 0x20) == 0) {
    m_Do_printf::OSReport("----- playLC DSP Ch が割当てられていません\n");
    uVar3 = 0;
  }
  else {
    iVar4 = checkLogicalChannel(this);
    if (iVar4 == 0) {
      uVar3 = 0;
    }
    else {
      *(code **)(*(int *)(this + 0x20) + 0x10) = updatecallDSPChannel;
      *(undefined2 *)(*(int *)(this + 0x20) + 6) = 1;
      this_00 = *(DSPBuffer **)(*(int *)(this + 0x20) + 0xc);
      TVar1 = this[0xc];
      if (TVar1 != (TChannel)0x1) {
        if (TVar1 == (TChannel)0x0) {
          DSPInterface::DSPBuffer::setWaveInfo
                    (this_00,*(Wave_ **)(this + 0x10),*(ulong *)(this + 0x14),
                     *(ulong *)(this + 0xe8));
        }
        else {
          if ((byte)TVar1 < 3) {
            DSPInterface::DSPBuffer::setOscInfo(this_00,*(ulong *)(this + 0x14));
          }
        }
      }
      for (bVar6 = 0; bVar6 < 6; bVar6 = bVar6 + 1) {
        uVar2 = *(undefined2 *)(this + (int)((Driver *)((uint)bVar6 * 2) + 0xb0));
        iVar4 = Driver::getOutputMode((Driver *)((uint)bVar6 * 2));
        local_18 = (byte)((ushort)uVar2 >> 8);
        if (iVar4 == 0) {
          if (local_18 == 9) {
            local_18 = 2;
          }
          else {
            if ((local_18 < 9) && (7 < local_18)) {
              local_18 = 0xb;
            }
          }
        }
        else {
          if ((iVar4 == 1) && (local_18 == 8)) {
            local_18 = 0xb;
          }
        }
        DSPInterface::DSPBuffer::setBusConnect(this_00,bVar6,local_18);
      }
      *(undefined4 *)(this + 0xa4) = *(undefined4 *)(this + 4);
      uVar5 = 0;
      do {
        iVar4 = isOsc(this,uVar5);
        if (iVar4 != 0) {
          dVar7 = (double)bankOscToOfs(this,uVar5);
          effectOsc(this,uVar5,(float)dVar7);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 4);
      updateEffectorParam(this);
      updateJcToDSPInit(this);
      *(char *)(*(int *)(this + 0x20) + 3) = (char)*(undefined4 *)(this + 0x48);
      *(undefined2 *)(*(int *)(this + 0x20) + 4) = *(undefined2 *)(this + 0x4c);
      TDSPChannel::play(*(TDSPChannel **)(this + 0x20));
      uVar3 = 1;
    }
  }
  return uVar3;
}


/* WARNING: Removing unreachable block (ram,0x8028c608) */
/* WARNING: Removing unreachable block (ram,0x8028c600) */
/* WARNING: Removing unreachable block (ram,0x8028c610) */
/* __thiscall TChannel::updateEffectorParam(void) */

void __thiscall TChannel::updateEffectorParam(TChannel *this)

{
  TChannel TVar1;
  float fVar2;
  Driver *this_00;
  int iVar3;
  uchar in_r6;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f29;
  double dVar9;
  double in_f30;
  double in_f31;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,SUB84(in_f30,0),0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  dVar9 = (double)JAudio::_501;
  this_00 = *(Driver **)(this + 4);
  if (*(Driver **)(this + 0xa4) == this_00) {
    *(undefined4 *)(this + 0xa8) = *(undefined4 *)(this_00 + 0x1c);
    *(undefined4 *)(this + 0xac) = *(undefined4 *)(*(int *)(this + 4) + 0x18);
    *(undefined4 *)(this + 0x78) = *(undefined4 *)(*(int *)(this + 4) + 0x20);
    *(undefined4 *)(this + 0x84) = *(undefined4 *)(*(int *)(this + 4) + 0x24);
    *(undefined4 *)(this + 0x90) = *(undefined4 *)(*(int *)(this + 4) + 0x28);
    iVar3 = 0;
    iVar4 = 3;
    do {
      TVar1 = *(TChannel *)(*(int *)(this + 4) + iVar3 + 0x62);
      this_00 = (Driver *)(uint)(byte)TVar1;
      this[iVar3 + 0x60] = TVar1;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  iVar3 = Driver::getOutputMode(this_00);
  if (iVar3 == 1) {
    if ((PanMatrix_ *)(uint)(byte)this[0x60] == (PanMatrix_ *)0x0) {
      in_f31 = (double)JAudio::_549;
    }
    else {
      in_f31 = (double)calcPan(this + 0x70,(PanMatrix_ *)(this + 100),
                               (PanMatrix_ *)(uint)(byte)this[0x60],in_r6);
    }
    in_f30 = (double)calcEffect(this + 0x7c,(PanMatrix_ *)(this + 100),
                                (PanMatrix_ *)(uint)(byte)this[0x61],in_r6);
    dVar9 = (double)JAudio::_501;
  }
  else {
    if (iVar3 < 1) {
      if (-1 < iVar3) {
        in_f31 = (double)JAudio::_549;
        dVar9 = (double)JAudio::_501;
        in_f30 = (double)calcEffect(this + 0x7c,(PanMatrix_ *)(this + 100),
                                    (PanMatrix_ *)(uint)(byte)this[0x61],in_r6);
      }
    }
    else {
      if (iVar3 < 3) {
        if ((PanMatrix_ *)(uint)(byte)this[0x60] == (PanMatrix_ *)0x0) {
          in_f31 = (double)JAudio::_549;
        }
        else {
          in_f31 = (double)calcPan(this + 0x70,(PanMatrix_ *)(this + 100),
                                   (PanMatrix_ *)(uint)(byte)this[0x60],in_r6);
        }
        in_f30 = (double)calcEffect(this + 0x7c,(PanMatrix_ *)(this + 100),
                                    (PanMatrix_ *)(uint)(byte)this[0x61],in_r6);
        dVar9 = (double)calcEffect(this + 0x88,(PanMatrix_ *)(this + 100),
                                   (PanMatrix_ *)(uint)(byte)this[0x62],in_r6);
      }
    }
  }
  fVar2 = *(float *)(this + 0xac) * *(float *)(this + 0x5c) * *(float *)(this + 0x98);
  dVar6 = (double)JAudio::_501;
  if ((dVar6 < in_f31) && (dVar6 = in_f31, (double)JAudio::_468 <= in_f31)) {
    dVar6 = (double)JAudio::_468;
  }
  dVar7 = (double)JAudio::_501;
  if ((dVar7 < in_f30) && (dVar7 = in_f30, (double)JAudio::_468 <= in_f30)) {
    dVar7 = (double)JAudio::_468;
  }
  dVar8 = (double)JAudio::_501;
  if ((dVar8 < dVar9) && (dVar8 = dVar9, (double)JAudio::_468 <= dVar9)) {
    dVar8 = (double)JAudio::_468;
  }
  *(short *)(this + 0xa0) =
       (short)(int)(JAudio::_738 *
                   *(float *)(this + 0xa8) * *(float *)(this + 0x58) * *(float *)(this + 0x94));
  if (*(short *)(this + 0xb0) == -1) {
    updateAutoMixer(this,fVar2,(float)dVar6,(float)dVar7,(float)dVar8);
  }
  else {
    updateMixer(this,fVar2,(float)dVar6,(float)dVar7,(float)dVar8);
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TChannel::killBrokenLogicalChannels(TDSPChannel *) */

void __thiscall TChannel::killBrokenLogicalChannels(TChannel *this,TDSPChannel *param_1)

{
  TChannel *this_00;
  TDSPChannel *extraout_r4;
  TGlobalChannel *this_01;
  TChannelMgr *this_02;
  undefined8 uVar1;
  
  this_01 = (TGlobalChannel *)0x0;
  do {
    uVar1 = TGlobalChannel::getChannelHandle(this_01,(ulong)param_1);
    this_00 = (TChannel *)((ulonglong)uVar1 >> 0x20);
    param_1 = (TDSPChannel *)uVar1;
    if (((this_00 != (TChannel *)0x0) && (*(TChannel **)(this_00 + 0x20) == this)) &&
       (this_02 = *(TChannelMgr **)(this_00 + 4), this_02 != (TChannelMgr *)0x0)) {
      stopLogicalChannel(this_00);
      uVar1 = TChannelMgr::moveListHead(this_02,this_00,0);
      param_1 = (TDSPChannel *)uVar1;
      if ((int)((ulonglong)uVar1 >> 0x20) == 0) {
        m_Do_printf::OSReport("----- killBrokenLogicalChannels : Cutできない\n");
        param_1 = extraout_r4;
      }
    }
    this_01 = this_01 + 1;
  } while (this_01 < (TGlobalChannel *)0x100);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall TChannel::updatecallDSPChannel(TDSPChannel *,
                                                       unsigned long) */

uint __thiscall
TChannel::updatecallDSPChannel(TChannel *this,TDSPChannel *param_1,ulong param_2)

{
  float fVar1;
  uint uVar2;
  int *this_00;
  Driver *this_01;
  TDSPChannel *extraout_r4;
  TChannel *pTVar3;
  int iVar4;
  ulong uVar5;
  TChannelMgr *this_02;
  TChannel *this_03;
  double dVar6;
  
  if (*(int *)(this + 0x10) == 0) {
    this_03 = (TChannel *)0x0;
  }
  else {
    this_03 = *(TChannel **)(this + 8);
  }
  this_02 = *(TChannelMgr **)(this_03 + 4);
  iVar4 = 0;
  if (this_03 == (TChannel *)0x0) {
    m_Do_printf::OSReport("-----Error JASDriver::commonCallbackLC DSPchのsignがNULL\n");
    *(undefined4 *)(this + 0x10) = 0;
    this[3] = (TChannel)0x0;
    killBrokenLogicalChannels(this,extraout_r4);
    return 0;
  }
  pTVar3 = *(TChannel **)(this_03 + 0x20);
  if (pTVar3 == this) {
    if (param_1 == (TDSPChannel *)&DAT_00000002) {
      if (*(code **)(this_03 + 0x28) == (code *)0x0) {
        stopLogicalChannel(this_03);
        iVar4 = TChannelMgr::moveListHead(this_02,this_03,0);
        if (iVar4 == 0) {
          m_Do_printf::OSReport("----- updatecallDSPChannel : Cutできない\n");
        }
      }
      else {
        (**(code **)(this_03 + 0x28))(this_03,1);
      }
      return 0;
    }
    this_00 = *(int **)(this_03 + 0x10);
    if ((this_00 != (int *)0x0) && (this_00 = (int *)this_00[9], *this_00 == 0)) {
      TDSPChannel::forceStop((TDSPChannel *)this);
      return 0xffffffff;
    }
    if (param_1 == (TDSPChannel *)&DAT_00000004) {
      uVar2 = *(uint *)(this_03 + 0x48) >> 0x10 & 0xff;
      if ((pTVar3 != (TChannel *)0x0) && (uVar2 < (byte)pTVar3[3])) {
        pTVar3[3] = SUB41(uVar2,0);
      }
      return 0;
    }
    if (param_1 == (TDSPChannel *)&DAT_00000003) {
      forceStopOsc(this_03,0);
      this_00 = (int *)TChannelMgr::moveListHead(this_02,this_03,3);
      if (this_00 == (int *)0x0) {
        m_Do_printf::OSReport("----- updatecallDSPChannel : Cutできない\n");
        return 1;
      }
      param_1 = (TDSPChannel *)0x0;
    }
    fVar1 = JAudio::_468;
    if (param_1 == (TDSPChannel *)0x0) {
      *(float *)(this_03 + 0x94) = JAudio::_468;
      *(float *)(this_03 + 0x98) = fVar1;
      *(float *)(this_03 + 0x74) = JAudio::_549;
      fVar1 = JAudio::_501;
      *(float *)(this_03 + 0x80) = JAudio::_501;
      *(float *)(this_03 + 0x8c) = fVar1;
      uVar5 = 0;
      do {
        this_01 = (Driver *)isOsc(this_03,uVar5);
        if (this_01 != (Driver *)0x0) {
          dVar6 = (double)bankOscToOfs(this_03,uVar5);
          this_01 = (Driver *)effectOsc(this_03,uVar5,(float)dVar6);
          if ((uVar5 == 0) &&
             (this_01 = (Driver *)getOscState(this_03,0), ((uint)this_01 & 0xff) == 0)) {
            if (*(code **)(this_03 + 0x28) == (code *)0x0) {
              m_Do_printf::OSReport("----- updatecallDSPCh JC停止のためのUPDATECALLがNULL\n")
              ;
              iVar4 = stopLogicalChannel(this_03);
              if (iVar4 == 0) {
                TDSPChannel::stop((TDSPChannel *)this);
              }
              iVar4 = TChannelMgr::moveListHead(this_02,this_03,0);
              if (iVar4 == 0) {
                m_Do_printf::OSReport("----- updatecallDSPChannel : Cutできない update\n");
              }
              return 0;
            }
            (**(code **)(this_03 + 0x28))(this_03,2);
            return 0;
          }
          iVar4 = iVar4 + 1;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < 4);
      if (iVar4 != 0) {
        this_01 = (Driver *)updateEffectorParam(this_03);
        this_03[3] = (TChannel)0x1;
      }
      if ((*(code **)(this_03 + 0x2c) != (code *)0x0) &&
         (this_01 = (Driver *)(**(code **)(this_03 + 0x2c))(this_03,0),
         this_01 == (Driver *)&DAT_00000001)) {
        this_01 = (Driver *)(uint)(byte)this_03[3];
        this_03[3] = (TChannel)((char)this_03[3] + 1);
      }
      this_00 = (int *)Driver::getUpdateInterval(this_01);
      if (*(int *)(this_03 + 0x28) == 0) {
        return (uint)this_00 & 0xff;
      }
      iVar4 = *(int *)(this_03 + 0x34);
      if (0 < iVar4) {
        if ((int)((uint)this_00 & 0xff) < iVar4) {
          *(uint *)(this_03 + 0x34) = iVar4 - ((uint)this_00 & 0xff);
        }
        else {
          *(undefined4 *)(this_03 + 0x34) = 0;
        }
      }
    }
    if (*(int *)(this_03 + 0x34) == 0) {
      this_00 = (int *)(**(code **)(this_03 + 0x28))(this_03,0);
      *(undefined4 *)(this_03 + 0x34) = *(undefined4 *)(this_03 + 0x30);
    }
    if (this_03[3] != (TChannel)0x0) {
      this_00 = (int *)updateJcToDSP(this_03);
      this_03[3] = (TChannel)0x0;
    }
    uVar2 = Driver::getUpdateInterval((Driver *)this_00);
    return uVar2 & 0xff;
  }
  if (pTVar3 != (TChannel *)0x0) {
    if (*(int *)(pTVar3 + 0x10) == 0) {
      pTVar3 = (TChannel *)0x0;
    }
    else {
      pTVar3 = *(TChannel **)(pTVar3 + 8);
    }
    if (this_03 == pTVar3) {
      killBrokenLogicalChannels(this,param_1);
      goto LAB_8028c7a8;
    }
  }
  stopLogicalChannel(this_03);
  iVar4 = TChannelMgr::moveListHead(this_02,this_03,0);
  if (iVar4 == 0) {
    m_Do_printf::OSReport("----- updatecallDSPChannel : Cutできない\n");
  }
LAB_8028c7a8:
  TDSPChannel::forceDelete((TDSPChannel *)this);
  return 0;
}


/* __thiscall TChannel::calcEffect(Driver::PanMatrix_ const *,
                                             Driver::PanMatrix_ const *,
                                             unsigned char) */

double __thiscall
TChannel::calcEffect(TChannel *this,PanMatrix_ *param_1,PanMatrix_ *param_2,uchar param_3)

{
  byte bVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = (double)JAudio::_501;
  iVar2 = ((uint)param_2 & 0xff) * 3;
  bVar1 = (&Driver::calc_sw_table)[iVar2];
  if (bVar1 == 1) {
    dVar3 = (double)(float)(dVar3 + (double)*(float *)this);
  }
  else {
    if ((bVar1 != 0) && (bVar1 < 3)) {
      dVar3 = (double)(float)(dVar3 + (double)(*(float *)this * *(float *)param_1));
    }
  }
  bVar1 = (&DAT_80398c29)[iVar2];
  if (bVar1 == 1) {
    dVar3 = (double)(float)(dVar3 + (double)*(float *)(this + 4));
  }
  else {
    if ((bVar1 != 0) && (bVar1 < 3)) {
      dVar3 = (double)(float)(dVar3 + (double)(*(float *)(this + 4) * *(float *)(param_1 + 4)));
    }
  }
  bVar1 = (&DAT_80398c2a)[iVar2];
  if (bVar1 == 1) {
    return (double)(float)(dVar3 + (double)*(float *)(this + 8));
  }
  if (bVar1 == 0) {
    return dVar3;
  }
  if (bVar1 < 3) {
    return (double)(float)(dVar3 + (double)(*(float *)(this + 8) * *(float *)(param_1 + 8)));
  }
  return dVar3;
}


/* __thiscall TChannel::calcPan(Driver::PanMatrix_ const *,
                                          Driver::PanMatrix_ const *,
                                          unsigned char) */

double __thiscall
TChannel::calcPan(TChannel *this,PanMatrix_ *param_1,PanMatrix_ *param_2,uchar param_3)

{
  byte bVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = ((uint)param_2 & 0xff) * 3;
  bVar1 = (&Driver::calc_sw_table)[iVar3];
  if (bVar1 == 1) {
    fVar2 = JAudio::_501 + (*(float *)this - JAudio::_549);
  }
  else {
    fVar2 = JAudio::_501;
    if ((bVar1 != 0) && (bVar1 < 3)) {
      fVar2 = JAudio::_501 + (*(float *)this - JAudio::_549) * *(float *)param_1;
    }
  }
  bVar1 = (&DAT_80398c29)[iVar3];
  if (bVar1 == 1) {
    fVar2 = fVar2 + (*(float *)(this + 4) - JAudio::_549);
  }
  else {
    if ((bVar1 != 0) && (bVar1 < 3)) {
      fVar2 = fVar2 + (*(float *)(this + 4) - JAudio::_549) * *(float *)(param_1 + 4);
    }
  }
  bVar1 = (&DAT_80398c2a)[iVar3];
  if (bVar1 == 1) {
    fVar2 = fVar2 + (*(float *)(this + 8) - JAudio::_549);
  }
  else {
    if ((bVar1 != 0) && (bVar1 < 3)) {
      fVar2 = fVar2 + (*(float *)(this + 8) - JAudio::_549) * *(float *)(param_1 + 8);
    }
  }
  return (double)(fVar2 + JAudio::_549);
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TChannel::updateJcToDSPInit(void) */

void __thiscall TChannel::updateJcToDSPInit(TChannel *this)

{
  DSPBuffer *this_00;
  byte bVar1;
  
  this_00 = *(DSPBuffer **)(*(int *)(this + 0x20) + 0xc);
  if (*(short *)(this + 0xb0) == -1) {
    DSPInterface::DSPBuffer::initAutoMixer(this_00);
  }
  else {
    DSPInterface::DSPBuffer::setMixerInitDelayMax(this_00,*(uchar *)(*(int *)(this + 4) + 0x60));
    bVar1 = 0;
    while( true ) {
      if (5 < bVar1) break;
      DSPInterface::DSPBuffer::setMixerInitVolume
                (this_00,bVar1,*(short *)(this + (uint)bVar1 * 2 + 0xbc),
                 *(uchar *)(*(int *)(this + 4) + bVar1 + 0x5a));
      bVar1 = bVar1 + 1;
    }
  }
  DSPInterface::DSPBuffer::setPitch(this_00,*(ushort *)(this + 0xa0));
  if ((*(byte *)(*(int *)(this + 4) + 0x61) & 0x20) != 0) {
    DSPInterface::DSPBuffer::setIIRFilterParam(this_00,(short *)(*(int *)(this + 4) + 0x3c));
  }
  if ((*(byte *)(*(int *)(this + 4) + 0x61) & 0x1f) != 0) {
    DSPInterface::DSPBuffer::setFIR8FilterParam(this_00,(short *)(*(int *)(this + 4) + 0x2c));
  }
  DSPInterface::DSPBuffer::setFilterMode(this_00,(ushort)*(byte *)(*(int *)(this + 4) + 0x61));
  DSPInterface::DSPBuffer::setPauseFlag(this_00,(uchar)this[2]);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8028ce84) */
/* WARNING: Removing unreachable block (ram,0x8028ce74) */
/* WARNING: Removing unreachable block (ram,0x8028ce7c) */
/* WARNING: Removing unreachable block (ram,0x8028ce8c) */
/* __thiscall TChannel::updateAutoMixer(float,
                                                  float,
                                                  float,
                                                  float) */

void __thiscall
TChannel::updateAutoMixer
          (TChannel *this,float param_1,float param_2,float param_3,float param_4)

{
  uint uVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar7;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar5 = (double)param_3;
  dVar6 = (double)param_4;
  dVar4 = (double)param_2;
  dVar3 = (double)param_1;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  dVar7 = (double)JAudio::_501;
  if ((dVar7 < dVar3) && (dVar7 = dVar3, (double)JAudio::_468 <= dVar3)) {
    dVar7 = (double)JAudio::_468;
  }
  uVar1 = Driver::getAutoLevel((Driver *)this);
  dVar3 = (double)JAudio::_911;
  DSPInterface::DSPBuffer::setAutoMixer
            (*(DSPBuffer **)(*(int *)(this + 0x20) + 0xc),
             (ushort)(int)(dVar7 * (double)(float)((double)CONCAT44(0x43300000,uVar1 & 0xffff) -
                                                  JAudio::_913)),(uchar)(int)(dVar3 * dVar4),
             (uchar)(int)(dVar3 * dVar6),(uchar)(int)(dVar3 * dVar5),
             (uchar)*(undefined2 *)(this + 0xb2));
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  __psq_l0(auStack56,uVar2);
  __psq_l1(auStack56,uVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8028d100) */
/* WARNING: Removing unreachable block (ram,0x8028d0f0) */
/* WARNING: Removing unreachable block (ram,0x8028d0e0) */
/* WARNING: Removing unreachable block (ram,0x8028d0d0) */
/* WARNING: Removing unreachable block (ram,0x8028d0c0) */
/* WARNING: Removing unreachable block (ram,0x8028d0c8) */
/* WARNING: Removing unreachable block (ram,0x8028d0d8) */
/* WARNING: Removing unreachable block (ram,0x8028d0e8) */
/* WARNING: Removing unreachable block (ram,0x8028d0f8) */
/* WARNING: Removing unreachable block (ram,0x8028d108) */
/* __thiscall TChannel::updateMixer(float,
                                              float,
                                              float,
                                              float) */

void __thiscall
TChannel::updateMixer
          (TChannel *this,float param_1,float param_2,float param_3,float param_4)

{
  ushort uVar1;
  TChannel *this_00;
  int iVar2;
  uint uVar3;
  TChannel *pTVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double dVar8;
  double dVar9;
  double dVar10;
  undefined8 in_f22;
  undefined8 in_f23;
  undefined8 in_f24;
  undefined8 in_f25;
  double in_f26;
  undefined8 in_f27;
  double dVar11;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar12;
  undefined8 in_f30;
  double dVar13;
  undefined8 in_f31;
  double dVar14;
  char local_c8;
  byte bStack199;
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar9 = (double)param_3;
  dVar10 = (double)param_4;
  dVar8 = (double)param_2;
  dVar7 = (double)param_1;
  uVar5 = 0;
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
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,SUB84(in_f26,0),0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  uVar3 = 0;
  iVar2 = 0;
  dVar6 = (double)JAudio::_468;
  dVar13 = (double)(float)(dVar6 - dVar8);
  dVar12 = (double)(float)(dVar6 - dVar9);
  dVar6 = (double)(float)(dVar6 - dVar10);
  this_00 = this;
  do {
    pTVar4 = this + iVar2;
    uVar1 = *(ushort *)(pTVar4 + 0xb0);
    local_c8 = (char)(uVar1 >> 8);
    if (local_c8 == '\0') {
      *(undefined2 *)(pTVar4 + 0xbc) = 0;
    }
    else {
      bStack199 = (byte)uVar1;
      dVar11 = dVar7;
      if (bStack199 >> 4 != 0) {
        switch(bStack199 >> 4) {
        case 1:
          in_f26 = dVar8;
          break;
        case 2:
          in_f26 = dVar9;
          break;
        case 3:
          in_f26 = dVar10;
          break;
        case 5:
          in_f26 = dVar13;
          break;
        case 6:
          in_f26 = dVar12;
          break;
        case 7:
          in_f26 = dVar6;
        }
        this_00 = (TChannel *)Calc::sinfT((Calc *)&JAudio::_966,(float)in_f26);
        dVar11 = (double)(float)(dVar11 * extraout_f1);
      }
      bStack199 = bStack199 & 0xf;
      if ((uVar1 & 0xf) != 0) {
        switch(bStack199) {
        case 1:
          in_f26 = dVar8;
          break;
        case 2:
          in_f26 = dVar9;
          break;
        case 3:
          in_f26 = dVar10;
          break;
        case 5:
          in_f26 = dVar13;
          break;
        case 6:
          in_f26 = dVar12;
          break;
        case 7:
          in_f26 = dVar6;
        }
        if ((bStack199 == 7) || ((bStack199 < 7 && (bStack199 == 3)))) {
          this_00 = (TChannel *)Calc::sinfDolby2((Calc *)&JAudio::_967,(float)in_f26);
          dVar11 = (double)(float)(dVar11 * extraout_f1_00);
        }
        else {
          this_00 = (TChannel *)Calc::sinfT((Calc *)&JAudio::_967,(float)in_f26);
          dVar11 = (double)(float)(dVar11 * extraout_f1_01);
        }
      }
      dVar14 = (double)JAudio::_501;
      if ((dVar14 < dVar11) && (dVar14 = dVar11, (double)JAudio::_468 <= dVar11)) {
        dVar14 = (double)JAudio::_468;
      }
      this_00 = (TChannel *)Driver::getChannelLevel((Driver *)this_00);
      *(short *)(pTVar4 + 0xbc) =
           (short)(int)(dVar14 * (double)(float)((double)CONCAT44(0x43300000,(uint)this_00 & 0xffff)
                                                - JAudio::_913));
    }
    uVar3 = uVar3 + 1;
    iVar2 = iVar2 + 2;
  } while (uVar3 < 6);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  __psq_l0(auStack56,uVar5);
  __psq_l1(auStack56,uVar5);
  __psq_l0(auStack72,uVar5);
  __psq_l1(auStack72,uVar5);
  __psq_l0(auStack88,uVar5);
  __psq_l1(auStack88,uVar5);
  __psq_l0(auStack104,uVar5);
  __psq_l1(auStack104,uVar5);
  __psq_l0(auStack120,uVar5);
  __psq_l1(auStack120,uVar5);
  __psq_l0(auStack136,uVar5);
  __psq_l1(auStack136,uVar5);
  __psq_l0(auStack152,uVar5);
  __psq_l1(auStack152,uVar5);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8028d1fc) */
/* __thiscall TChannel::extraUpdate(TChannel *,
                                              unsigned long) */

undefined8 __thiscall
TChannel::extraUpdate(TChannel *this,TChannel *param_1,ulong param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (*(short *)(this + 0xa2) == 0) {
    uVar2 = 0;
  }
  else {
    dVar4 = (double)(*(float *)(this + 0x9c) - *(float *)(this + 0x58));
    uVar1 = Driver::getUpdateInterval((Driver *)this);
    if ((uint)*(ushort *)(this + 0xa2) <= (uVar1 & 0xff)) {
      *(undefined2 *)(this + 0xa2) = 1;
    }
    param_1 = (TChannel *)(uVar1 & 0xff);
    *(float *)(this + 0x58) =
         *(float *)(this + 0x58) +
         (float)(dVar4 / (double)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 0xa2))
                                        - JAudio::_913)) *
         (float)((double)CONCAT44(0x43300000,param_1) - JAudio::_913);
    if ((int)((uint)*(ushort *)(this + 0xa2) - (uVar1 & 0xff)) < 1) {
      *(undefined2 *)(this + 0xa2) = 0;
    }
    else {
      *(ushort *)(this + 0xa2) = *(ushort *)(this + 0xa2) - (short)param_1;
    }
    if (*(short *)(this + 0xa2) == 0) {
      *(undefined4 *)(this + 0x2c) = 0;
    }
    uVar2 = 1;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return CONCAT44(uVar2,param_1);
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TChannel::updatecallLogicalChannel(TChannel *,
                                                           unsigned long) */

undefined4 __thiscall
TChannel::updatecallLogicalChannel(TChannel *this,TChannel *param_1,ulong param_2)

{
  int iVar1;
  TChannel *extraout_r4;
  TChannel *extraout_r4_00;
  TChannel *extraout_r4_01;
  TChannel *extraout_r4_02;
  TChannel *pTVar2;
  ulong uVar3;
  TChannelMgr *this_00;
  undefined8 uVar4;
  
  this_00 = *(TChannelMgr **)(this + 4);
  if (param_1 == (TChannel *)0x0) {
    uVar3 = 0;
    do {
      releaseOsc(this,uVar3);
      uVar3 = uVar3 + 1;
    } while (uVar3 < 4);
    if (*(int *)(this + 0x20) != 0) {
      *(char *)(*(int *)(this + 0x20) + 3) = (char)((uint)*(undefined4 *)(this + 0x48) >> 8);
    }
    iVar1 = TChannelMgr::moveListTail(this_00,this,2);
    if (iVar1 == 0) {
      m_Do_printf::OSReport("----- updatecallLC : CUT失敗(release)\n");
    }
    *(undefined4 *)(this + 0x30) = 0xffffffff;
  }
  else {
    if ((param_1 + -1 < (TChannel *)&DAT_00000002) || (param_1 == (TChannel *)0x6)) {
      if (*(int *)(this_00 + 4) == 0) {
        uVar3 = *(ulong *)(this + 0xcc);
        iVar1 = TChannelMgr::moveListHead(this_00,this,0);
        if (iVar1 == 0) {
          m_Do_printf::OSReport("----- updatecallLC : CUT失敗(not extra)\n");
        }
        TChannelMgr::checkLimitStop(this_00,this,uVar3);
        pTVar2 = extraout_r4_02;
      }
      else {
        uVar4 = TChannelMgr::cutList(this_00,this);
        pTVar2 = (TChannel *)uVar4;
        if ((int)((ulonglong)uVar4 >> 0x20) == -1) {
          m_Do_printf::OSReport("----- updatecallLC : CUT失敗(extra)\n");
          pTVar2 = extraout_r4;
        }
        else {
          *(int *)(this_00 + 4) = *(int *)(this_00 + 4) + -1;
          uVar3 = *(ulong *)(this + 0xcc);
          if (uVar3 != 0) {
            *(undefined4 *)(this + 0xcc) = 0;
            TChannelMgr::checkLimitStop(this_00,this,uVar3);
            pTVar2 = extraout_r4_00;
          }
          TGlobalChannel::release((TGlobalChannel *)this,pTVar2);
          pTVar2 = extraout_r4_01;
        }
      }
      if (param_1 == (TChannel *)0x6) {
        TDSPQueue::deleteQueue((TDSPQueue *)this,pTVar2);
      }
      else {
        stopLogicalChannel(this);
      }
      this[1] = (TChannel)0xff;
      *(undefined4 *)(this + 0x30) = 0xffffffff;
      *(undefined4 *)(this + 0x28) = 0;
    }
  }
  return 0;
}

