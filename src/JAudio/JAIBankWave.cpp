#include <JAudio/JAIBankWave.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JAIGlobalParameter.h>
#include <JAudio/JASWaveArcLoader.h>
#include <JAudio/JASWaveBankMgr.h>
#include <JAudio/JASBankMgr.h>
#include <JAudio/JAIBankWave.h>
#include <JAudio/JASDvdThread.h>
#include <JAInter/BankWave.h>


namespace JAInter {
undefined1 BankWave;
undefined1 BankWave;
undefined1 BankWave;
undefined1 BankWave;
undefined1 BankWave;

namespace BankWave {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall setWsGroupNumber(long,
                                                  long) */

void setWsGroupNumber(long param_1,long param_2)

{
  *(long *)(_wsGroupNumber + param_1 * 4) = param_2;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall setWsLoadStatus(long,
                                                 long) */

void setWsLoadStatus(long param_1,long param_2)

{
  *(long *)(_wsLoadStatus + param_1 * 4) = param_2;
  return;
}

}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall BankWave::init(void) */

int __thiscall BankWave::init(BankWave *this,EVP_PKEY_CTX *ctx)

{
  WaveArcLoader *this_00;
  EVP_PKEY_CTX *ctx_00;
  EVP_PKEY_CTX *ctx_01;
  undefined *puVar1;
  WaveBankMgr *this_01;
  BankMgr *pBVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  if ((_msCurrentHeap == 0) &&
     (m_Do_printf::OSReport
                ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
     _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80368ebd);
  }
  _wsGroupNumber = JKernel::operator_new__(_wsMax << 2,_msCurrentHeap,0x20);
  if ((_msCurrentHeap == 0) &&
     (m_Do_printf::OSReport
                ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
     _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80368ebd);
  }
  puVar1 = &DAT_00000020;
  _wsLoadStatus = (JAIGlobalParameter *)JKernel::operator_new__(_wsMax << 2,_msCurrentHeap);
  uVar5 = JAIGlobalParameter::getParamWavePath(_wsLoadStatus);
  JASystem::WaveArcLoader::setCurrentDir((WaveArcLoader *)((ulonglong)uVar5 >> 0x20),(char *)uVar5);
  ctx_01 = ctx_00;
  this_00 = (WaveArcLoader *)JASystem::WaveBankMgr::init((WaveBankMgr *)0x100,ctx_00);
  JASystem::WaveArcLoader::init(this_00,ctx_01);
  if (_initOnCodeWs != 0) {
    this_01 = (WaveBankMgr *)0x0;
    iVar3 = 0;
    for (iVar4 = 0; ctx_01 = *(EVP_PKEY_CTX **)(_initOnCodeWs + iVar4),
        ctx_01 != (EVP_PKEY_CTX *)0x0; iVar4 = iVar4 + 0xc) {
      if (ctx_01 != (EVP_PKEY_CTX *)0x0) {
        JASystem::WaveBankMgr::registWaveBankWS(this_01,(int)ctx_01,puVar1);
        *(undefined4 *)(_wsGroupNumber + iVar3) = 0xffffffff;
        *(undefined4 *)(_wsLoadStatus + iVar3) = 0;
      }
      this_01 = this_01 + 1;
      iVar3 = iVar3 + 4;
    }
  }
  iVar3 = JASystem::BankMgr::init((BankMgr *)0x100,ctx_01);
  if (_initOnCodeBnk != 0) {
    pBVar2 = (BankMgr *)0x0;
    iVar3 = 0;
    while( true ) {
      iVar4 = *(int *)(_initOnCodeBnk + iVar3);
      if (iVar4 == 0) break;
      if (iVar4 != 0) {
        JASystem::BankMgr::registBankBNK(pBVar2,iVar4,puVar1);
      }
      pBVar2 = pBVar2 + 1;
      iVar3 = iVar3 + 0xc;
    }
    pBVar2 = (BankMgr *)0x0;
    iVar3 = _initOnCodeBnk;
    for (iVar4 = 0; *(int *)(_initOnCodeBnk + iVar4) != 0; iVar4 = iVar4 + 0xc) {
      iVar3 = JASystem::BankMgr::assignWaveBank
                        (pBVar2,((int *)(_initOnCodeBnk + iVar4))[2],(int)puVar1);
      pBVar2 = pBVar2 + 1;
    }
  }
  return iVar3;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall BankWave::setWaveScene(void) */

BankWave * __thiscall BankWave::setWaveScene(BankWave *this)

{
  int iVar1;
  int iVar2;
  
  if (_initOnCodeWs != 0) {
    iVar1 = 0;
    for (iVar2 = 0; *(int *)(_initOnCodeWs + iVar2) != 0; iVar2 = iVar2 + 0xc) {
      if (((int *)(_initOnCodeWs + iVar2))[2] == 0) {
        loadGroupWave(iVar1,0);
      }
      iVar1 = iVar1 + 1;
    }
    this = (BankWave *)&DAT_00000001;
    flags = flags & 0x7f | 0x80;
  }
  return this;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall BankWave::loadSecondStayWave(void) */

void __thiscall BankWave::loadSecondStayWave(BankWave *this)

{
  int iVar1;
  int iVar2;
  
  if (((*(char *)(_seHandle + 5) == '\x03') && ((flags >> 6 & 1) == 0)) && (_initOnCodeWs != 0)) {
    iVar1 = 0;
    for (iVar2 = 0; *(int *)(_initOnCodeWs + iVar2) != 0; iVar2 = iVar2 + 0xc) {
      if (((int *)(_initOnCodeWs + iVar2))[2] == 1) {
        loadGroupWave(iVar1,0);
      }
      iVar1 = iVar1 + 1;
    }
    flags = flags & 0xbf | 0x40;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall BankWave::setSceneSetFinishCallback(long,
                                                           long) */

void __thiscall
BankWave::setSceneSetFinishCallback(BankWave *this,long param_1,long param_2)

{
  _SceneSetFlag = 0xffffffff;
  *(undefined4 *)(_wsLoadStatus + (int)this * 4) = 1;
  JASystem::Dvd::checkPassDvdT
            ((Dvd *)((int)this * 0x10000 + param_1),0,(ulong *)finishSceneSet,
             (FuncDef569 *)&DAT_00000001);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall BankWave::finishSceneSet(unsigned long) */

void __thiscall BankWave::finishSceneSet(BankWave *this,ulong param_1)

{
  _SceneSetFlag = this;
  *(undefined4 *)(_wsLoadStatus + ((uint)this >> 0xe & 0x3fffc)) = 2;
  return;
}


namespace BankWave {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall loadSceneWave(long,
                                               long) */

void loadSceneWave(long param_1,long param_2)

{
  int iVar1;
  
  if (((_initOnCodeWs != 0) && (*(int *)(_initOnCodeWs + param_1 * 0xc + 8) == 2)) &&
     (iVar1 = *(int *)(_wsGroupNumber + param_1 * 4), param_2 != iVar1)) {
    if (iVar1 != -1) {
      JASystem::WaveBankMgr::eraseWave(param_1,iVar1);
    }
    loadGroupWave(param_1,param_2);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall loadGroupWave(long,
                                               long) */

void loadGroupWave(long param_1,long param_2)

{
  long lVar1;
  THeap *in_r6;
  
  lVar1 = 0;
  JASystem::WaveBankMgr::loadWave((WaveBankMgr *)param_1,param_2,0,in_r6);
  setSceneSetFinishCallback((BankWave *)param_1,param_2,lVar1);
  *(long *)(_wsGroupNumber + param_1 * 4) = param_2;
  return;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall BankWave::getWaveLoadStatus(long) */

undefined4 __thiscall BankWave::getWaveLoadStatus(BankWave *this,long param_1)

{
  return *(undefined4 *)(_wsLoadStatus + (int)this * 4);
}


namespace BankWave {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall checkAllWaveLoadStatus(void) */

undefined4 checkAllWaveLoadStatus(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  while( true ) {
    if (*(int *)(_initOnCodeWs + iVar1) == 0) {
      return 0;
    }
    if (*(int *)(_wsLoadStatus + iVar2) == 1) break;
    iVar1 = iVar1 + 0xc;
    iVar2 = iVar2 + 4;
  }
  return 1;
}

