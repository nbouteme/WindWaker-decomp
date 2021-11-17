#include <JAudio/JASDriverIF.h>
#include <JAudio/JASDSPInterface.h>
#include <JAudio/JASDSPChannel.h>
#include <JAudio/JASChGlobal.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JASystem/Driver.h>


namespace JASystem {

/* __thiscall Driver::init(void) */

int __thiscall Driver::init(Driver *this,EVP_PKEY_CTX *ctx)

{
  TDSPChannel *this_00;
  int iVar1;
  undefined8 uVar2;
  
  this_00 = (TDSPChannel *)DSPInterface::initBuffer((DSPInterface *)this);
  uVar2 = TDSPChannel::initAll(this_00);
  iVar1 = TGlobalChannel::init((TGlobalChannel *)((ulonglong)uVar2 >> 0x20),(EVP_PKEY_CTX *)uVar2);
  return iVar1;
}


/* WARNING: Removing unreachable block (ram,0x8028aaa4) */
/* WARNING: Removing unreachable block (ram,0x8028aaac) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Driver::setMixerLevel(float,
                                              float) */

void __thiscall Driver::setMixerLevel(Driver *this,float param_1,float param_2)

{
  bool bVar1;
  ulong uVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar4 = (double)param_1;
  dVar5 = (double)param_2;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  bVar1 = false;
  if ((JAudio::_374 <= dVar4) && (dVar4 <= JAudio::_375)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"JASDriverIF.cpp",0x3a,"(0.0 <= channel_level) && (channel_level <= 2.0)");
    this = (Driver *)m_Do_printf::OSPanic("JASDriverIF.cpp",0x3a,&DAT_803683c1);
  }
  bVar1 = false;
  if ((JAudio::_374 <= dVar5) && (dVar5 <= JAudio::_376)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"JASDriverIF.cpp",0x3b,"(0.0 <= dsp_level) && (dsp_level <= 8.0)");
    this = (Driver *)m_Do_printf::OSPanic("JASDriverIF.cpp",0x3b,&DAT_803683c1);
  }
  _MAX_MIXERLEVEL = (undefined2)(int)((double)JAudio::_377 * dVar4);
  DSPInterface::setDSPMixerLevel((DSPInterface *)this,(float)dVar5);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Driver::getChannelLevel(void) */

undefined2 __thiscall Driver::getChannelLevel(Driver *this)

{
  return _MAX_MIXERLEVEL;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Driver::getAutoLevel(void) */

undefined2 __thiscall Driver::getAutoLevel(Driver *this)

{
  return _MAX_AUTOMIXERLEVEL;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Driver::setOutputMode(unsigned long) */

void __thiscall Driver::setOutputMode(Driver *this,ulong param_1)

{
  _JAS_SYSTEM_OUTPUT_MODE = this;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Driver::getOutputMode(void) */

undefined4 __thiscall Driver::getOutputMode(Driver *this)

{
  return _JAS_SYSTEM_OUTPUT_MODE;
}


/* __thiscall Driver::getUpdateInterval(void) */

undefined __thiscall Driver::getUpdateInterval(Driver *this)

{
  return JAS_UPDATE_INTERVAL;
}

