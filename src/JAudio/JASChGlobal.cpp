#include <JAudio/JASChGlobal.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JASChannelMgr.h>
#include <JAudio/JASChGlobal.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JAudio/JASChannel.h>
#include <JAudio/JASChAllocQueue.h>
#include <JAudio/JASOscillator.h>
#include <JSupport/JSUList.h>
#include <Demangler/JASystem/TChannel.h>
#include <JASystem/TOscillator.h>
#include <JASystem/TGlobalChannel.h>


namespace JASystem {
undefined1 TGlobalChannel;
undefined1 TGlobalChannel;
undefined1 TGlobalChannel;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TGlobalChannel::getChannelHandle(unsigned long) */

int __thiscall TGlobalChannel::getChannelHandle(TGlobalChannel *this,ulong param_1)

{
  ulong uVar1;
  
  if ((TGlobalChannel *)0xff < this) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASChGlobal.cpp",0x22,"ch_num < (256)");
    m_Do_printf::OSPanic("JASChGlobal.cpp",0x22,&DAT_8036843f);
  }
  return _sChannel + (int)this * 0xec;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TGlobalChannel::init(void) */

int __thiscall TGlobalChannel::init(TGlobalChannel *this,EVP_PKEY_CTX *ctx)

{
  undefined4 *this_00;
  ulong uVar1;
  undefined4 uVar2;
  JKRHeap *ctx_00;
  JKRHeap *extraout_r4;
  EVP_PKEY_CTX *ctx_01;
  int iVar3;
  int iVar4;
  int iVar5;
  
  ctx_00 = JAudio::JASDram;
  _sChannelMgr = (undefined4 *)JKernel::operator_new(0x74,JAudio::JASDram,0x20);
  if (_sChannelMgr == (undefined4 *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASChGlobal.cpp",0x2c,"sChannelMgr");
    m_Do_printf::OSPanic("JASChGlobal.cpp",0x2c,&DAT_8036843f);
    ctx_00 = extraout_r4;
  }
  this_00 = _sChannelMgr;
  TChannelMgr::init((TChannelMgr *)_sChannelMgr,(EVP_PKEY_CTX *)ctx_00);
  uVar2 = JKernel::operator_new__(0xec10,JAudio::JASDram,0x20);
  _sChannel = Runtime.PPCEABI.H::__construct_new_array
                        (uVar2,TChannel::TChannel,TChannel::_TChannel,0xec,0x100);
  if (_sChannel == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASChGlobal.cpp",0x32,"sChannel");
    m_Do_printf::OSPanic("JASChGlobal.cpp",0x32,&DAT_8036843f);
  }
  uVar2 = JKernel::operator_new__(0x8010,JAudio::JASDram,0x20);
  _sOscillator = Runtime.PPCEABI.H::__construct_new_array
                           (uVar2,TOscillator::TOscillator,TOscillator::_TOscillator,0x20,0x400);
  if (_sOscillator == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASChGlobal.cpp",0x34,"sOscillator");
    m_Do_printf::OSPanic("JASChGlobal.cpp",0x34,&DAT_8036843f);
  }
  iVar3 = 0;
  iVar5 = 0;
  iVar4 = 0;
  do {
    uVar1 = 0;
    do {
      TChannel::setOscillator
                ((TChannel *)(_sChannel + iVar5),uVar1,
                 (TOscillator *)(_sOscillator + (uVar1 + iVar4) * 0x20));
      uVar1 = uVar1 + 1;
    } while (uVar1 < 4);
    TChannel::init((TChannel *)(_sChannel + iVar5),ctx_01);
    TChannelMgr::addListHead((TChannelMgr *)this_00,(TChannel *)(_sChannel + iVar5),0);
    *(undefined4 **)(_sChannel + iVar5 + 4) = this_00;
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 0xec;
    iVar4 = iVar4 + 4;
  } while (iVar3 < 0x100);
  *this_00 = 0x100;
  iVar3 = m_Do_printf::OSReport("----- JASChannel size : %d\n",0xec);
  return iVar3;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TGlobalChannel::alloc(TChannelMgr *,
                                              unsigned long) */

TChannelMgr * __thiscall
TGlobalChannel::alloc(TGlobalChannel *this,TChannelMgr *param_1,ulong param_2)

{
  TChannel *this_00;
  EVP_PKEY_CTX *ctx;
  TChannelMgr *pTVar1;
  
  pTVar1 = (TChannelMgr *)0x0;
  while ((pTVar1 < param_1 &&
         (this_00 = (TChannel *)TChannelMgr::getListHead((TChannelMgr *)_sChannelMgr,0),
         this_00 != (TChannel *)0x0))) {
    TChannelMgr::addListHead((TChannelMgr *)this,this_00,0);
    *(TGlobalChannel **)(this_00 + 4) = this;
    TChannel::init(this_00,ctx);
    pTVar1 = pTVar1 + 1;
  }
  *(TChannelMgr **)this = pTVar1 + *(int *)this;
  *_sChannelMgr = *_sChannelMgr - (int)pTVar1;
  return pTVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TGlobalChannel::release(TChannel *) */

undefined4 __thiscall TGlobalChannel::release(TGlobalChannel *this,TChannel *param_1)

{
  TChannelMgr::addListHead((TChannelMgr *)_sChannelMgr,(TChannel *)this,0);
  **(int **)(this + 4) = **(int **)(this + 4) + -1;
  *_sChannelMgr = *_sChannelMgr + 1;
  *(int **)(this + 4) = _sChannelMgr;
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TGlobalChannel::releaseAll(TChannelMgr *) */

undefined4 __thiscall
TGlobalChannel::releaseAll(TGlobalChannel *this,TChannelMgr *param_1)

{
  TChannel *pTVar1;
  TDSPQueue *this_00;
  int iVar2;
  undefined8 uVar3;
  
  while (pTVar1 = (TChannel *)TChannelMgr::getListHead((TChannelMgr *)this,0),
        pTVar1 != (TChannel *)0x0) {
    TChannelMgr::addListHead((TChannelMgr *)_sChannelMgr,pTVar1,0);
    *(int **)(pTVar1 + 4) = _sChannelMgr;
  }
  while (pTVar1 = (TChannel *)TChannelMgr::getListHead((TChannelMgr *)this,1),
        pTVar1 != (TChannel *)0x0) {
    TChannelMgr::addListHead((TChannelMgr *)_sChannelMgr,pTVar1,1);
    *(int **)(pTVar1 + 4) = _sChannelMgr;
    *(undefined4 *)(pTVar1 + 0xd4) = 1;
  }
  while (pTVar1 = (TChannel *)TChannelMgr::getListHead((TChannelMgr *)this,2),
        pTVar1 != (TChannel *)0x0) {
    TChannelMgr::addListHead((TChannelMgr *)_sChannelMgr,pTVar1,2);
    *(int **)(pTVar1 + 4) = _sChannelMgr;
    *(undefined4 *)(pTVar1 + 0xd4) = 1;
  }
  while( true ) {
    uVar3 = TChannelMgr::getListHead((TChannelMgr *)this,3);
    this_00 = (TDSPQueue *)((ulonglong)uVar3 >> 0x20);
    if (this_00 == (TDSPQueue *)0x0) break;
    iVar2 = TDSPQueue::deleteQueue(this_00,(TChannel *)uVar3);
    if (iVar2 == 0) {
      TChannelMgr::addListHead((TChannelMgr *)_sChannelMgr,(TChannel *)this_00,3);
    }
    else {
      TChannelMgr::addListHead((TChannelMgr *)_sChannelMgr,(TChannel *)this_00,0);
    }
    *(int **)(this_00 + 4) = _sChannelMgr;
  }
  *_sChannelMgr = *_sChannelMgr + *(int *)this;
  *(undefined4 *)this = 0;
  return 0;
}


/* __thiscall TOscillator::~TOscillator(void) */

void __thiscall TOscillator::_TOscillator(TOscillator *this)

{
  short in_r4;
  
  if ((this != (TOscillator *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall TOscillator::TOscillator(void) */

void __thiscall TOscillator::TOscillator(TOscillator *this)

{
  EVP_PKEY_CTX *in_r4;
  
  init(this,in_r4);
  return;
}


/* __thiscall TChannel::~TChannel(void) */

void __thiscall TChannel::_TChannel(TChannel *this)

{
  short in_r4;
  
  if (this != (TChannel *)0x0) {
    if (this != (TChannel *)0xffffff28) {
      JSUPtrLink::_JSUPtrLink((JSUPtrLink *)(this + 0xd8));
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TChannel::TChannel(void) */

void __thiscall TChannel::TChannel(TChannel *this)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  JSUPtrLink::JSUPtrLink((JSUPtrLink *)(this + 0xd8),this);
  iVar1 = 0;
  iVar2 = 4;
  do {
    *(undefined4 *)(this + iVar1 + 0x38) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

