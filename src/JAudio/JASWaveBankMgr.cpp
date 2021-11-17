#include <JAudio/JASWaveBankMgr.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JAudio/JASCalc.h>
#include <JAudio/JASWSParser.h>
#include <JAudio/JASWaveBankMgr.h>
#include <JAudio/JASWaveArcLoader.h>
#include <JASystem/WaveBankMgr.h>


namespace JASystem {
undefined1 WaveBankMgr;
undefined1 WaveBankMgr;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall WaveBankMgr::init(int) */

int __thiscall WaveBankMgr::init(WaveBankMgr *this,EVP_PKEY_CTX *ctx)

{
  ulong uVar1;
  Calc *pCVar2;
  undefined *__n;
  
  __n = (undefined *)0x0;
  _sWaveBank = (Calc *)JKernel::operator_new__((void *)((int)this << 2),JAudio::JASDram);
  if (_sWaveBank == (Calc *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASWaveBankMgr.cpp",0x27,"sWaveBank != 0");
    __n = &DAT_80367e9a;
    m_Do_printf::OSPanic("JASWaveBankMgr.cpp",0x27);
  }
  pCVar2 = _sWaveBank;
  Calc::bzero(_sWaveBank,(void *)((int)this << 2),(size_t)__n);
  _sTableSize = this;
  return (int)pCVar2;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall WaveBankMgr::getWaveBank(int) */

undefined4 __thiscall WaveBankMgr::getWaveBank(WaveBankMgr *this,int param_1)

{
  if ((int)this < 0) {
    return 0;
  }
  if (_sTableSize <= (int)this) {
    return 0;
  }
  return *(undefined4 *)(_sWaveBank + (int)this * 4);
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall WaveBankMgr::registWaveBank(int,
                                                    TWaveBank *) */

undefined4 __thiscall
WaveBankMgr::registWaveBank(WaveBankMgr *this,int param_1,TWaveBank *param_2)

{
  ulong uVar1;
  
  if ((int)this < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASWaveBankMgr.cpp",0x39,"banknum >= 0");
    m_Do_printf::OSPanic("JASWaveBankMgr.cpp",0x39,&DAT_80367e9a);
  }
  if (_sTableSize <= (int)this) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASWaveBankMgr.cpp",0x3a,"banknum < sTableSize");
    m_Do_printf::OSPanic("JASWaveBankMgr.cpp",0x3a,&DAT_80367e9a);
  }
  *(int *)(_sWaveBank + (int)this * 4) = param_1;
  return 1;
}


/* __thiscall WaveBankMgr::registWaveBankWS(int,
                                                      void *) */

undefined4 __thiscall
WaveBankMgr::registWaveBankWS(WaveBankMgr *this,int param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = WSParser::getGroupCount((WSParser *)param_1,(void *)param_1);
  if ((int)((ulonglong)uVar3 >> 0x20) == 1) {
    iVar1 = WSParser::createSimpleWaveBank((WSParser *)param_1,(void *)uVar3);
  }
  else {
    iVar1 = WSParser::createBasicWaveBank((WSParser *)param_1,(void *)uVar3);
  }
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = registWaveBank(this,iVar1,(TWaveBank *)param_2);
  }
  return uVar2;
}


/* __thiscall WaveBankMgr::getWaveArc(int,
                                                int) */

undefined4 __thiscall WaveBankMgr::getWaveArc(WaveBankMgr *this,int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)getWaveBank(this,param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(*piVar1 + 0x10))(piVar1,param_1);
  }
  return uVar2;
}


/* __thiscall WaveBankMgr::loadWave(int,
                                              int,
                                              Kernel::THeap *) */

undefined4 __thiscall
WaveBankMgr::loadWave(WaveBankMgr *this,int param_1,int param_2,THeap *param_3)

{
  TWaveArc *this_00;
  undefined4 uVar1;
  
  this_00 = (TWaveArc *)getWaveArc(this,param_1,param_2);
  if (this_00 == (TWaveArc *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = TWaveArc::load(this_00,(THeap *)param_2);
  }
  return uVar1;
}


namespace WaveBankMgr {

/* __thiscall eraseWave(int,
                                               int) */

bool eraseWave(int param_1,int param_2)

{
  TWaveArc *this;
  char cVar1;
  int in_r5;
  bool bVar2;
  
  this = (TWaveArc *)getWaveArc((WaveBankMgr *)param_1,param_2,in_r5);
  if (this == (TWaveArc *)0x0) {
    bVar2 = false;
  }
  else {
    cVar1 = TWaveArc::erase(this);
    bVar2 = cVar1 != '\0';
  }
  return bVar2;
}

