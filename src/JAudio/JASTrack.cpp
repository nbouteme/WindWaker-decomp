#include <JAudio/JASTrack.h>
#include <JAudio/JASTrack.h>
#include <JAudio/JASRegisterParam.h>
#include <JAudio/JASChannelMgr.h>
#include <JAudio/JASCalc.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JAudio/JASSeqCtrl.h>
#include <JAudio/JASTrackPort.h>
#include <JAudio/JASTrackInterrupt.h>
#include <JAudio/JASNoteMgr.h>
#include <JAudio/JASOuterParam.h>
#include <JAudio/JASSeqParser.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JAudio/JASChGlobal.h>
#include <JAudio/JASBankMgr.h>
#include <JAudio/JASChannel.h>
#include <JAudio/JASPlayer_impl.h>
#include <JAudio/JASCallback.h>
#include <JKernel/JKRHeap.h>
#include <JASystem/TTrack/TimedParam_.h>
#include <JASystem/TVibrate.h>
#include <JASystem/TTrack/MoveParam_.h>
#include <Demangler/JASystem/TTrack.h>
#include <JASystem/TTrack/AInnerParam_.h>


namespace JASystem {

namespace TTrack {
undefined1 sCallBackFunc;
undefined1 sParser;
undefined1 sFreeList;
}

/* __thiscall TTrack::TTrack(void) */

void __thiscall TTrack::TTrack(TTrack *this)

{
  float fVar1;
  int iVar2;
  EVP_PKEY_CTX *in_r4;
  int iVar3;
  
  TVibrate::TVibrate((TVibrate *)(this + 0xec));
  TimedParam_::TimedParam_((TimedParam_ *)(this + 0x16c));
  TRegisterParam::TRegisterParam((TRegisterParam *)(this + 0x28c));
  *(undefined4 *)(this + 0x31c) = 0;
  fVar1 = JAudio::_680;
  *(float *)(this + 0x364) = JAudio::_680;
  *(float *)(this + 0x368) = fVar1;
  *(undefined4 *)(this + 0x36c) = 0;
  *(undefined4 *)(this + 0x370) = 0;
  *(undefined2 *)(this + 0x374) = 0;
  *(undefined2 *)(this + 0x376) = 0x78;
  *(undefined2 *)(this + 0x378) = 0x78;
  this[0x37a] = (TTrack)0x0;
  this[0x37b] = (TTrack)0x0;
  this[0x37c] = (TTrack)0x0;
  this[0x37d] = (TTrack)0x0;
  this[0x37e] = (TTrack)0x0;
  this[0x385] = (TTrack)0x0;
  this[0x386] = (TTrack)0x0;
  this[0x387] = (TTrack)0x0;
  this[0x388] = (TTrack)0x0;
  this[0x389] = (TTrack)0x0;
  TChannelMgr::init((TChannelMgr *)(this + 0xf8),in_r4);
  iVar2 = 0;
  iVar3 = 0xc;
  do {
    *(undefined2 *)(this + iVar2 + 0x304) = *(undefined2 *)(&Player::sAdsTable + iVar2);
    iVar2 = iVar2 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  Calc::bzero((Calc *)(this + 0x16c),(void *)0x120,(size_t)&Player::sAdsTable);
  return;
}


namespace TTrack {

/* __thiscall TimedParam_::TimedParam_(void) */

void __thiscall TimedParam_::TimedParam_(TimedParam_ *this)

{
  AInnerParam_::AInnerParam_((AInnerParam_ *)this);
  Runtime.PPCEABI.H::__construct_array(this,MoveParam_::MoveParam_,(undefined *)0x0,0x10,0x12);
  return;
}

}

/* __thiscall TTrack::init(void) */

int __thiscall TTrack::init(TTrack *this,EVP_PKEY_CTX *ctx)

{
  TTrack TVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  EVP_PKEY_CTX *ctx_00;
  EVP_PKEY_CTX *ctx_01;
  EVP_PKEY_CTX *extraout_r4;
  TTrack *pTVar8;
  int iVar9;
  
  TSeqCtrl::init((TSeqCtrl *)this,ctx);
  TTrackPort::init((TTrackPort *)(this + 0x48),ctx);
  TIntrMgr::init((TIntrMgr *)(this + 0x88),ctx);
  TNoteMgr::init((TNoteMgr *)(this + 0xb4),ctx);
  TChannelMgr::initAllocChannel((TChannelMgr *)(this + 0xf8),0);
  initTimed(this);
  TRegisterParam::init((TRegisterParam *)(this + 0x28c),ctx_00);
  *(undefined4 *)(this + 0x2fc) = 0xf;
  TVar1 = Player::sEnvelopeDef;
  this[0x2cc] = Player::sEnvelopeDef;
  uVar2 = DAT_8036756c;
  *(undefined4 *)(this + 0x2d0) = DAT_8036756c;
  uVar3 = DAT_80367570;
  *(undefined4 *)(this + 0x2d4) = DAT_80367570;
  puVar4 = PTR_sRelTable_80367574;
  *(undefined **)(this + 0x2d8) = PTR_sRelTable_80367574;
  uVar5 = DAT_80367578;
  *(undefined4 *)(this + 0x2dc) = DAT_80367578;
  uVar6 = DAT_8036757c;
  *(undefined4 *)(this + 0x2e0) = DAT_8036757c;
  *(undefined4 *)(this + 0x300) = 0xf;
  this[0x2e4] = TVar1;
  *(undefined4 *)(this + 0x2e8) = uVar2;
  *(undefined4 *)(this + 0x2ec) = uVar3;
  *(undefined **)(this + 0x2f0) = puVar4;
  *(undefined4 *)(this + 0x2f4) = uVar5;
  *(undefined4 *)(this + 0x2f8) = uVar6;
  ctx_01 = (EVP_PKEY_CTX *)0x0;
  *(undefined4 *)(this + 0x31c) = 0;
  iVar7 = 0;
  iVar9 = 0x10;
  do {
    *(undefined4 *)(this + iVar7 + 800) = 0;
    iVar7 = iVar7 + 4;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if (*(TOuterParam **)(this + 0x360) != (TOuterParam *)0x0) {
    TOuterParam::initExtBuffer(*(TOuterParam **)(this + 0x360));
    ctx_01 = extraout_r4;
  }
  *(float *)(this + 0x364) = JAudio::_680;
  *(float *)(this + 0x368) = JAudio::_737;
  *(undefined4 *)(this + 0x36c) = 0;
  TVibrate::init((TVibrate *)(this + 0xec),ctx_01);
  *(undefined4 *)(this + 0x370) = 0;
  *(undefined2 *)(this + 0x374) = 0;
  *(undefined2 *)(this + 0x376) = 0x78;
  *(undefined2 *)(this + 0x378) = 0x30;
  updateTempo(this);
  this[0x37a] = (TTrack)0x0;
  this[0x37b] = (TTrack)0x0;
  this[0x37c] = (TTrack)0xa;
  this[0x37d] = (TTrack)0x0;
  this[0x37e] = (TTrack)0x0;
  iVar7 = 0;
  iVar9 = 3;
  do {
    pTVar8 = this + iVar7;
    pTVar8[0x37f] = (TTrack)0x0;
    pTVar8[0x382] = (TTrack)0x0;
    pTVar8[0x15a] = (TTrack)0xd;
    iVar7 = iVar7 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  this[0x385] = (TTrack)0x0;
  this[0x386] = (TTrack)0x0;
  this[0x387] = (TTrack)0x1;
  this[0x388] = (TTrack)0x0;
  return 0;
}


/* __thiscall TTrack::inherit(void) */

void __thiscall TTrack::inherit(TTrack *this)

{
  TTrack *pTVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(this + 0x31c) != 0) {
    *(undefined2 *)(this + 0x376) = *(undefined2 *)(*(int *)(this + 0x31c) + 0x376);
    this[0x388] = (TTrack)0x0;
    *(undefined4 *)(this + 0x368) = *(undefined4 *)(*(int *)(this + 0x31c) + 0x368);
    *(undefined2 *)(this + 0x378) = *(undefined2 *)(*(int *)(this + 0x31c) + 0x378);
    this[0x387] = *(TTrack *)(*(int *)(this + 0x31c) + 0x387);
    this[0x385] = *(TTrack *)(*(int *)(this + 0x31c) + 0x385);
    this[0x37c] = *(TTrack *)(*(int *)(this + 0x31c) + 0x37c);
    this[0x37d] = *(TTrack *)(*(int *)(this + 0x31c) + 0x37d);
    this[0x386] = *(TTrack *)(*(int *)(this + 0x31c) + 0x386);
    if (((byte)this[0x37b] & 2) == 0) {
      TRegisterParam::inherit
                ((TRegisterParam *)(this + 0x28c),(TRegisterParam *)(*(int *)(this + 0x31c) + 0x28c)
                );
      iVar2 = 0;
      iVar3 = 3;
      do {
        pTVar1 = this + iVar2;
        pTVar1[0x37f] = *(TTrack *)(*(int *)(this + 0x31c) + iVar2 + 0x37f);
        pTVar1[0x382] = *(TTrack *)(*(int *)(this + 0x31c) + iVar2 + 0x382);
        pTVar1[0x15a] = *(TTrack *)(*(int *)(this + 0x31c) + iVar2 + 0x15a);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall TTrack::mainProc(void) */

undefined4 __thiscall TTrack::mainProc(TTrack *this)

{
  float fVar1;
  TChannel *pTVar2;
  char cVar5;
  undefined4 uVar3;
  ulong uVar4;
  TTrack *this_00;
  int iVar6;
  int iVar7;
  undefined5 uVar8;
  
  iVar6 = 0;
  if ((this[0x388] != (TTrack)0x0) && (*(int *)(this + 0x31c) != 0)) {
    fVar1 = (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 0x376)) - JAudio::_804) /
            (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(*(int *)(this + 0x31c) + 0x376)) -
                   JAudio::_804);
    if (JAudio::_737 < fVar1) {
      fVar1 = JAudio::_737;
    }
    *(float *)(this + 0x364) = *(float *)(this + 0x364) + fVar1;
    if (*(float *)(this + 0x364) < JAudio::_737) {
      return 0;
    }
    *(float *)(this + 0x364) = *(float *)(this + 0x364) - JAudio::_737;
  }
  if (((*(int *)(this + 0x31c) != 0) && (*(int *)(this + 0xf8) != 0)) &&
     (pTVar2 = (TChannel *)TChannelMgr::getListHead((TChannelMgr *)(this + 0xf8),0),
     pTVar2 != (TChannel *)0x0)) {
    TChannelMgr::addListHead((TChannelMgr *)(*(int *)(this + 0x31c) + 0xf8),pTVar2,0);
    *(int *)(pTVar2 + 4) = *(int *)(this + 0x31c) + 0xf8;
    *(int *)(this + 0xf8) = *(int *)(this + 0xf8) + -1;
    *(int *)(*(int *)(this + 0x31c) + 0xf8) = *(int *)(*(int *)(this + 0x31c) + 0xf8) + 1;
  }
  TIntrMgr::request((TIntrMgr *)(this + 0x88),7);
  TIntrMgr::timerProcess((TIntrMgr *)(this + 0x88));
  tryInterrupt(this);
  if ((this[0x385] != (TTrack)0x0) && (((byte)this[0x37c] & 2) != 0)) goto LAB_80280eb0;
  if (*(int *)(this + 8) == -1) {
    cVar5 = checkNoteStop(this,0);
    if (cVar5 != '\0') {
      *(undefined4 *)(this + 8) = 0;
      goto LAB_80280e74;
    }
  }
  else {
LAB_80280e74:
    if (0 < *(int *)(this + 8)) {
      cVar5 = TSeqCtrl::waitCountDown((TSeqCtrl *)this);
      if (cVar5 == '\0') goto LAB_80280ea8;
      TNoteMgr::endProcess((TNoteMgr *)(this + 0xb4));
    }
    iVar6 = TSeqParser::parseSeq((TSeqParser *)&sParser,this);
  }
LAB_80280ea8:
  updateTimedParam(this);
LAB_80280eb0:
  updateSeq(this,0,false);
  if (iVar6 < 0) {
    uVar3 = 0xffffffff;
  }
  else {
    iVar6 = 0;
    iVar7 = 0;
    do {
      this_00 = *(TTrack **)(this + iVar7 + 800);
      if ((this_00 != (TTrack *)0x0) && (this_00[0x37e] != (TTrack)0x0)) {
        if (this != *(TTrack **)(this_00 + 0x31c)) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar4,"JASTrack.cpp",0x114,"this == child->mParent");
          m_Do_printf::OSPanic("JASTrack.cpp",0x114,"Halt");
        }
        uVar8 = mainProc(this_00);
        if ((char)((uint5)uVar8 >> 0x20) == -1) {
          close(this_00,(int)uVar8);
          *(undefined4 *)(this + iVar7 + 800) = 0;
        }
      }
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar6 < 0x10);
    uVar3 = 0;
  }
  return uVar3;
}


/* __thiscall TTrack::setInterrupt(unsigned short) */

void __thiscall TTrack::setInterrupt(TTrack *this,ushort param_1)

{
  TIntrMgr::request((TIntrMgr *)(this + 0x88),(uint)param_1);
  return;
}


/* __thiscall TTrack::tryInterrupt(void) */

undefined4 __thiscall TTrack::tryInterrupt(TTrack *this)

{
  undefined4 uVar1;
  void *pvVar2;
  
  if (*(int *)(this + 0x44) == 0) {
    pvVar2 = (void *)TIntrMgr::checkIntr((TIntrMgr *)(this + 0x88));
    if (pvVar2 == (void *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = TSeqCtrl::callIntr((TSeqCtrl *)this,pvVar2);
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall TTrack::assignExtBuffer(TTrack::TOuterParam *) */

void __thiscall TTrack::assignExtBuffer(TTrack *this,TOuterParam *param_1)

{
  *(TOuterParam **)(this + 0x360) = param_1;
  return;
}


/* __thiscall TTrack::releaseChannelAll(void) */

void __thiscall TTrack::releaseChannelAll(TTrack *this)

{
  if (*(int *)(this + 0x31c) == 0) {
    TGlobalChannel::releaseAll((TGlobalChannel *)(this + 0xf8),(TChannelMgr *)this);
  }
  else {
    TChannelMgr::receiveAllChannels
              ((TChannelMgr *)(*(int *)(this + 0x31c) + 0xf8),(TChannelMgr *)(this + 0xf8));
  }
  return;
}


/* __thiscall TTrack::flushAll(void) */

void __thiscall TTrack::flushAll(TTrack *this)

{
  TChannelMgr::stopAll((TChannelMgr *)(this + 0xf8));
  TChannelMgr::stopAllRelease((TChannelMgr *)(this + 0xf8));
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TTrack::moveFreeChannel(TChannelMgr *,
                                                TChannelMgr *,
                                                int) */

undefined4 __thiscall
TTrack::moveFreeChannel
          (TTrack *this,TChannelMgr *param_1,TChannelMgr *param_2,int param_3)

{
  TChannel *pTVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((int)param_2 < 0) {
    uVar2 = *(undefined4 *)this;
    TChannelMgr::receiveAllChannels(param_1,(TChannelMgr *)this);
  }
  else {
    iVar3 = 0;
    while (((iVar3 < (int)param_2 && (*(int *)this != 0)) &&
           (pTVar1 = (TChannel *)TChannelMgr::getListHead((TChannelMgr *)this,0),
           pTVar1 != (TChannel *)0x0))) {
      *(int *)this = *(int *)this + -1;
      TChannelMgr::addListHead(param_1,pTVar1,0);
      *(int *)param_1 = *(int *)param_1 + 1;
      iVar3 = iVar3 + 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}


/* __thiscall TTrack::initTimed(void) */

void __thiscall TTrack::initTimed(TTrack *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  TTrack *pTVar4;
  byte bVar5;
  
  fVar3 = JAudio::_737;
  fVar1 = JAudio::_680;
  for (bVar5 = 0; fVar2 = JAudio::_680, bVar5 < 0x12; bVar5 = bVar5 + 1) {
    pTVar4 = this + (uint)bVar5 * 0x10;
    *(float *)(pTVar4 + 0x174) = fVar1;
    *(float *)(pTVar4 + 0x16c) = fVar3;
    *(float *)(pTVar4 + 0x170) = fVar3;
  }
  *(float *)(this + 0x17c) = JAudio::_680;
  *(float *)(this + 0x180) = fVar2;
  fVar1 = JAudio::_935;
  *(float *)(this + 0x19c) = JAudio::_935;
  *(float *)(this + 0x1a0) = fVar1;
  *(float *)(this + 0x26c) = fVar1;
  *(float *)(this + 0x270) = fVar1;
  *(float *)(this + 0x27c) = fVar2;
  *(float *)(this + 0x280) = fVar2;
  *(float *)(this + 0x18c) = fVar2;
  *(float *)(this + 400) = fVar2;
  *(float *)(this + 0x1ac) = fVar2;
  *(float *)(this + 0x1b0) = fVar2;
  for (bVar5 = 1; fVar1 = JAudio::_680, bVar5 < 4; bVar5 = bVar5 + 1) {
    *(float *)(this + (uint)bVar5 * 0x10 + 0x22c) = fVar2;
    *(float *)(this + (uint)bVar5 * 0x10 + 0x230) = fVar2;
  }
  *(float *)(this + 0x1bc) = JAudio::_680;
  *(float *)(this + 0x1c0) = fVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TTrack::connectBus(int,
                                           int) */

void __thiscall TTrack::connectBus(TTrack *this,int param_1,int param_2)

{
  ulong uVar1;
  
  if (5 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASTrack.cpp",0x1e6,"line < (6)");
    m_Do_printf::OSPanic("JASTrack.cpp",0x1e6,"Halt");
  }
  *(short *)(this + param_1 * 2 + 0x146) = (short)param_2;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall TTrack::noteOn(unsigned char,
                                       long,
                                       long,
                                       long,
                                       unsigned long) */

undefined4 __thiscall
TTrack::noteOn
          (TTrack *this,uchar param_1,long param_2,long param_3,long param_4,ulong param_5)

{
  undefined4 uVar1;
  ulong uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  TChannel *this_00;
  ushort extraout_r4;
  char *pcVar6;
  ulong in_r9;
  int *this_01;
  
  if ((this[0x386] == (TTrack)0x0) || (((byte)this[0x37c] & 0x40) == 0)) {
    pcVar6 = (char *)param_3;
    noteOff(this,param_1,0);
    this_01 = (int *)(this + 0xf8);
    iVar3 = *(int *)(this + 0x31c);
    while( true ) {
      if ((*this_01 != 0) && (this_01[2] != 0)) goto LAB_802812f4;
      if (iVar3 == 0) break;
      this_01 = (int *)(iVar3 + 0xf8);
      iVar3 = *(int *)(iVar3 + 0x31c);
    }
    this_01 = (int *)(this + 0xf8);
LAB_802812f4:
    if (this[0x37b] == (TTrack)0x4) {
      if (*(int *)(this + 0x31c) == 0) {
        uVar2 = JUTAssertion::getSDevice();
        pcVar6 = "mParent != 0";
        JUTAssertion::showAssert(uVar2,"JASTrack.cpp",0x20f,"mParent != 0");
        m_Do_printf::OSPanic("JASTrack.cpp",0x20f,"Halt");
      }
      if (this_01 != (int *)(*(int *)(this + 0x31c) + 0xf8)) {
        iVar3 = moveFreeChannel((TTrack *)this_01,
                                (TChannelMgr *)(int *)(*(int *)(this + 0x31c) + 0xf8),
                                (TChannelMgr *)&DAT_00000001,(int)pcVar6);
        if (iVar3 != 1) {
          m_Do_printf::OSReport
                    ("in Player (NOTE-MODE) ... ボイス借用に失敗しました！！ (%d)\n",
                     *this_01);
        }
        this_01 = (int *)(*(int *)(this + 0x31c) + 0xf8);
      }
    }
    else {
      if (this_01 != (int *)(this + 0xf8)) {
        iVar3 = moveFreeChannel((TTrack *)this_01,(TChannelMgr *)(this + 0xf8),
                                (TChannelMgr *)&DAT_00000001,(int)pcVar6);
        if (iVar3 != 1) {
          m_Do_printf::OSReport
                    ("in Player ボイス借用に失敗しました！！ (%d)\n",*this_01);
        }
        this_01 = (int *)(this + 0xf8);
      }
    }
    uVar4 = TRegisterParam::getBankNumber((TRegisterParam *)(this + 0x28c));
    uVar4 = BankMgr::getPhysicalNumber((BankMgr *)(uVar4 & 0xff),extraout_r4);
    uVar5 = TRegisterParam::getProgramNumber((TRegisterParam *)(this + 0x28c));
    this_00 = (TChannel *)
              BankMgr::noteOn((BankMgr *)this_01,(TChannelMgr *)(uVar4 & 0xff),uVar5 & 0xff,
                              param_2 & 0xff,(uchar)param_3,(uchar)param_4,in_r9);
    if (this_00 == (TChannel *)0x0) {
      uVar1 = 0xffffffff;
    }
    else {
      TNoteMgr::setChannel((TNoteMgr *)(this + 0xb4),(uint)param_1,this_00);
      *(ulong *)(this_00 + 0xe8) = param_5;
      TChannel::setPanPower
                (this_00,(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 0x29c)) -
                                JAudio::_804),
                 (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 0x29e)) - JAudio::_804
                        ),(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 0x2a0)) -
                                 JAudio::_804),JAudio::_680);
      overwriteOsc(this,this_00);
      if (*(ushort *)(this + 0x374) != 0) {
        TChannel::directReleaseOsc(this_00,0,*(ushort *)(this + 0x374));
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall TTrack::overwriteOsc(TChannel *) */

void __thiscall TTrack::overwriteOsc(TTrack *this,TChannel *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  undefined4 uVar5;
  int iVar6;
  TTrack *pTVar7;
  int iVar8;
  int iVar9;
  
  iVar6 = 0;
  iVar9 = 0;
  iVar8 = 0;
  do {
    uVar2 = *(uint *)(this + iVar8 + 0x2fc);
    if (uVar2 != 0xf) {
      uVar1 = uVar2 & 3;
      if ((uVar2 & 8) == 0) {
        if ((uVar2 & 4) != 0) {
          pTVar7 = this + iVar9;
          uVar5 = *(undefined4 *)(pTVar7 + 0x2d8);
          iVar3 = TChannel::isOsc(param_1,uVar1);
          if (iVar3 == 0) {
            uVar4 = JUTAssertion::getSDevice();
            JUTAssertion::setWarningMessage_f
                      (uVar4,"JASTrack.cpp",0x25b,"%s",(___)"cannot copy osc");
            goto LAB_802815b0;
          }
          TChannel::copyOsc(param_1,uVar1,(Osc_ *)(pTVar7 + 0x2cc));
          *(undefined4 *)(pTVar7 + 0x2d8) = uVar5;
        }
      }
      else {
        iVar3 = TChannel::isOsc(param_1,uVar1);
        if (iVar3 == 0) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::setWarningMessage_f(uVar4,"JASTrack.cpp",0x251,"%s",(___)"cannot copy osc");
          goto LAB_802815b0;
        }
        TChannel::copyOsc(param_1,uVar1,(Osc_ *)(this + iVar9 + 0x2cc));
      }
      TChannel::overwriteOsc(param_1,uVar1,(Osc_ *)(this + iVar9 + 0x2cc));
    }
LAB_802815b0:
    iVar6 = iVar6 + 1;
    iVar9 = iVar9 + 0x18;
    iVar8 = iVar8 + 4;
    if (1 < iVar6) {
      return;
    }
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TTrack::noteOff(unsigned char,
                                        unsigned short) */

undefined4 __thiscall TTrack::noteOff(TTrack *this,uchar param_1,ushort param_2)

{
  TChannel *this_00;
  undefined4 uVar1;
  
  this_00 = (TChannel *)TNoteMgr::getChannel((TNoteMgr *)(this + 0xb4),(uint)param_1);
  if (this_00 == (TChannel *)0x0) {
    uVar1 = 0;
  }
  else {
    if (param_2 == 0) {
      TChannel::stop(this_00,0);
    }
    else {
      TChannel::stop(this_00,param_2);
    }
    TNoteMgr::releaseChannel((TNoteMgr *)(this + 0xb4),(uint)param_1);
    uVar1 = 1;
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TTrack::gateOn(unsigned char,
                                       long,
                                       long,
                                       long) */

undefined4 __thiscall
TTrack::gateOn(TTrack *this,uchar param_1,long param_2,long param_3,long param_4)

{
  BankMgr *this_00;
  undefined4 uVar1;
  ulong uVar2;
  
  uVar2 = param_4;
  this_00 = (BankMgr *)TNoteMgr::getChannel((TNoteMgr *)(this + 0xb4),(uint)param_1);
  if (this_00 == (BankMgr *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    BankMgr::gateOn(this_00,(TChannel *)(param_2 & 0xff),(uchar)param_3,(uchar)param_4,uVar2);
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall TTrack::checkNoteStop(long) */

uint __thiscall TTrack::checkNoteStop(TTrack *this,long param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = TNoteMgr::getChannel((TNoteMgr *)(this + 0xb4),param_1);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = countLeadingZeros(0xff - (uint)*(byte *)(iVar1 + 1));
    uVar2 = uVar2 >> 5 & 0xff;
  }
  return uVar2;
}


/* __thiscall TTrack::oscSetupFull(unsigned char,
                                             unsigned long,
                                             unsigned long) */

void __thiscall
TTrack::oscSetupFull(TTrack *this,uchar param_1,ulong param_2,ulong param_3)

{
  uint uVar1;
  TTrack *pTVar2;
  
  uVar1 = (param_1 & 0x10) >> 4;
  if (param_1 != '\0') {
    pTVar2 = this + uVar1 * 0x18;
    pTVar2[0x2cc] = Player::sEnvelopeDef;
    *(undefined4 *)(pTVar2 + 0x2d0) = DAT_8036756c;
    *(undefined4 *)(pTVar2 + 0x2d4) = DAT_80367570;
    *(undefined **)(pTVar2 + 0x2d8) = PTR_sRelTable_80367574;
    *(undefined4 *)(pTVar2 + 0x2dc) = DAT_80367578;
    *(undefined4 *)(pTVar2 + 0x2e0) = DAT_8036757c;
    pTVar2[0x2cc] = (TTrack)(param_1 & 0xf);
    if ((TTrack)(param_1 & 0xf) == (TTrack)0x1) {
      *(float *)(pTVar2 + 0x2e0) = JAudio::_737;
    }
  }
  if ((param_1 & 0x40) != 0) {
    if (param_2 == 0) {
      *(undefined4 *)(this + uVar1 * 0x18 + 0x2d4) = 0;
    }
    *(ulong *)(this + uVar1 * 0x18 + 0x2d4) = *(int *)this + param_2;
  }
  if ((param_1 & 0x20) != 0) {
    if (param_3 == 0) {
      *(undefined1 **)(this + uVar1 * 0x18 + 0x2d8) = &Player::sRelTable;
    }
    *(ulong *)(this + uVar1 * 0x18 + 0x2d8) = *(int *)this + param_3;
    return;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x802817f8) */
/* __thiscall TTrack::oscSetupSimpleEnv(unsigned char,
                                                  unsigned long) */

void __thiscall TTrack::oscSetupSimpleEnv(TTrack *this,uchar param_1,ulong param_2)

{
  if (param_1 == '\x01') {
    *(ulong *)(this + 0x2d8) = *(int *)this + param_2;
    return;
  }
  if (param_1 == '\0') {
    this[0x2cc] = Player::sEnvelopeDef;
    *(undefined4 *)(this + 0x2d0) = DAT_8036756c;
    *(undefined4 *)(this + 0x2d4) = DAT_80367570;
    *(undefined **)(this + 0x2d8) = PTR_sRelTable_80367574;
    *(undefined4 *)(this + 0x2dc) = DAT_80367578;
    *(undefined4 *)(this + 0x2e0) = DAT_8036757c;
    *(ulong *)(this + 0x2d4) = *(int *)this + param_2;
    return;
  }
  return;
}


/* __thiscall TTrack::updateOscParam(int,
                                               float) */

void __thiscall TTrack::updateOscParam(TTrack *this,int param_1,float param_2)

{
  ulong uVar1;
  
  if (param_1 == 9) {
    *(float *)(this + 0x2f4) = param_2;
    return;
  }
  if (param_1 < 9) {
    if (param_1 == 7) {
      *(float *)(this + 0x2d0) = param_2;
      return;
    }
    if (6 < param_1) {
      *(float *)(this + 0x2e0) = param_2;
      return;
    }
    if (5 < param_1) {
      *(float *)(this + 0x2dc) = param_2;
      return;
    }
  }
  else {
    if (param_1 == 0xb) {
      *(float *)(this + 0x2f8) = param_2;
      return;
    }
    if (param_1 < 0xb) {
      *(float *)(this + 0x2e8) = param_2;
      return;
    }
  }
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar1,"JASTrack.cpp",0x2f1,"false");
  m_Do_printf::OSPanic("JASTrack.cpp",0x2f1,"Halt");
  return;
}


/* WARNING: Removing unreachable block (ram,0x80281918) */
/* __thiscall TTrack::oscSetupSimple(unsigned char) */

void __thiscall TTrack::oscSetupSimple(TTrack *this,uchar param_1)

{
  if (param_1 == '\x01') {
    this[0x2cc] = Player::sTremoroDef;
    *(undefined4 *)(this + 0x2d0) = DAT_8036759c;
    *(undefined **)(this + 0x2d4) = PTR_sTreTable_803675a0;
    *(undefined **)(this + 0x2d8) = PTR_sTreTable_803675a4;
    *(undefined4 *)(this + 0x2dc) = DAT_803675a8;
    *(undefined4 *)(this + 0x2e0) = DAT_803675ac;
    return;
  }
  if (param_1 != '\0') {
    if (param_1 < 3) {
      this[0x2e4] = Player::sTremoroDef;
      *(undefined4 *)(this + 0x2e8) = DAT_8036759c;
      *(undefined **)(this + 0x2ec) = PTR_sTreTable_803675a0;
      *(undefined **)(this + 0x2f0) = PTR_sTreTable_803675a4;
      *(undefined4 *)(this + 0x2f4) = DAT_803675a8;
      *(undefined4 *)(this + 0x2f8) = DAT_803675ac;
      return;
    }
    return;
  }
  this[0x2e4] = Player::sVibratoDef;
  *(undefined4 *)(this + 0x2e8) = DAT_80367584;
  *(undefined **)(this + 0x2ec) = PTR_sVibTable_80367588;
  *(undefined **)(this + 0x2f0) = PTR_sVibTable_8036758c;
  *(undefined4 *)(this + 0x2f4) = DAT_80367590;
  *(undefined4 *)(this + 0x2f8) = DAT_80367594;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80281a84) */
/* __thiscall TTrack::updateTimedParam(void) */

void __thiscall TTrack::updateTimedParam(TTrack *this)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar2 = 0;
  iVar3 = 0;
  dVar5 = (double)JAudio::_680;
  do {
    pfVar1 = (float *)(this + iVar3 + 0x16c);
    if (dVar5 < (double)pfVar1[2]) {
      *pfVar1 = *pfVar1 + pfVar1[3];
      pfVar1[2] = pfVar1[2] - JAudio::_737;
      if ((iVar2 < 6) || (10 < iVar2)) {
        *(uint *)(this + 0x370) = *(uint *)(this + 0x370) | 1 << iVar2;
      }
      else {
        updateOscParam(this,iVar2,*pfVar1);
      }
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x10;
  } while (iVar2 < 0x12);
  *(uint *)(this + 0x370) = *(uint *)(this + 0x370) | 2;
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80281e68) */
/* WARNING: Removing unreachable block (ram,0x80281e58) */
/* WARNING: Removing unreachable block (ram,0x80281e48) */
/* WARNING: Removing unreachable block (ram,0x80281b40) */
/* WARNING: Removing unreachable block (ram,0x80281e50) */
/* WARNING: Removing unreachable block (ram,0x80281e60) */
/* WARNING: Removing unreachable block (ram,0x80281e70) */
/* __thiscall TTrack::updateTrackAll(void) */

void __thiscall TTrack::updateTrackAll(TTrack *this)

{
  float fVar1;
  TTrack TVar2;
  Player *this_00;
  char cVar4;
  undefined2 uVar3;
  byte bVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f26;
  double dVar9;
  double dVar10;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar11;
  undefined8 in_f30;
  double dVar12;
  undefined8 in_f31;
  double dVar13;
  char local_78 [8];
  double local_70;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
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
  __psq_st1(auStack88,(int)in_f26,0);
  if (this[0x37b] != (TTrack)0x4) {
    local_70 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 0x2a2));
    dVar9 = (double)((float)(local_70 - JAudio::_804) / JAudio::_1184);
    *(uint *)(this + 0x160) = *(ushort *)(this + 0x2a6) | 0x10000;
    *(undefined2 *)(this + 0x164) = 0;
    TVar2 = (TTrack)0x0;
    __psq_st0(local_78,(int)((ulonglong)(double)(JAudio::_1185 * *(float *)(this + 0x27c)) >> 0x20),
              0x60006);
    this_00 = (Player *)(int)local_78[0];
    if (local_78[0] < '\0') {
      TVar2 = (TTrack)-local_78[0];
      this_00 = (Player *)0x0;
    }
    this[0x158] = (TTrack)0x10;
    this[0x152] = TVar2;
    this[0x153] = SUB41(this_00,0);
    dVar12 = (double)*(float *)(this + 0x16c);
    if (this[0x37d] == (TTrack)0x0) {
      dVar12 = (double)(float)(dVar12 * dVar12);
    }
    if (this[0x386] != (TTrack)0x0) {
      dVar12 = (double)JAudio::_680;
    }
    local_70 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 0x29a));
    dVar7 = (double)Player::pitchToCent(this_00,*(float *)(this + 0x17c),
                                        (float)(local_70 - JAudio::_804));
    dVar8 = (double)TVibrate::getValue((TVibrate *)(this + 0xec));
    dVar13 = (double)(float)(dVar7 * dVar8);
    dVar11 = (double)*(float *)(this + 0x19c);
    dVar7 = (double)*(float *)(this + 0x18c);
    dVar8 = (double)*(float *)(this + 0x1ac);
    if (*(TOuterParam **)(this + 0x360) != (TOuterParam *)0x0) {
      cVar4 = TOuterParam::checkOuterSwitch(*(TOuterParam **)(this + 0x360),1);
      if (cVar4 != '\0') {
        dVar12 = (double)(float)(dVar12 * (double)*(float *)(*(int *)(this + 0x360) + 4));
      }
      cVar4 = TOuterParam::checkOuterSwitch(*(TOuterParam **)(this + 0x360),2);
      if (cVar4 != '\0') {
        dVar13 = (double)(float)(dVar13 * (double)*(float *)(*(int *)(this + 0x360) + 8));
      }
      cVar4 = TOuterParam::checkOuterSwitch(*(TOuterParam **)(this + 0x360),4);
      if (cVar4 != '\0') {
        dVar7 = (double)panCalc(this,(float)dVar7,*(float *)(*(int *)(this + 0x360) + 0xc),
                                (float)dVar9,(uchar)this[0x380]);
      }
      cVar4 = TOuterParam::checkOuterSwitch(*(TOuterParam **)(this + 0x360),0x10);
      if (cVar4 != '\0') {
        dVar8 = (double)panCalc(this,(float)dVar8,*(float *)(*(int *)(this + 0x360) + 0x10),
                                (float)dVar9,(uchar)this[0x381]);
      }
      cVar4 = TOuterParam::checkOuterSwitch(*(TOuterParam **)(this + 0x360),8);
      if (cVar4 != '\0') {
        dVar11 = (double)panCalc(this,(float)dVar11,*(float *)(*(int *)(this + 0x360) + 0x14),
                                 (float)dVar9,(uchar)this[0x37f]);
      }
    }
    if ((*(int *)(this + 0x31c) == 0) || (((byte)this[0x37b] & 1) != 0)) {
      *(float *)(this + 0x110) = (float)dVar12;
      *(float *)(this + 0x114) = (float)dVar13;
      *(float *)(this + 0x118) = (float)dVar11;
      *(float *)(this + 0x11c) = (float)dVar7;
      *(float *)(this + 0x120) = (float)dVar8;
    }
    else {
      local_70 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 0x2a4));
      fVar1 = (float)(local_70 - JAudio::_804) / JAudio::_1184;
      dVar10 = (double)fVar1;
      *(float *)(this + 0x110) =
           (float)((double)*(float *)(*(int *)(this + 0x31c) + 0x110) * dVar12);
      *(float *)(this + 0x114) =
           (float)((double)*(float *)(*(int *)(this + 0x31c) + 0x114) * dVar13);
      dVar9 = (double)panCalc(this,(float)dVar11,*(float *)(*(int *)(this + 0x31c) + 0x118),fVar1,
                              (uchar)this[0x382]);
      *(float *)(this + 0x118) = (float)dVar9;
      dVar9 = (double)panCalc(this,(float)dVar7,*(float *)(*(int *)(this + 0x31c) + 0x11c),
                              (float)dVar10,(uchar)this[899]);
      *(float *)(this + 0x11c) = (float)dVar9;
      dVar9 = (double)panCalc(this,(float)dVar8,*(float *)(*(int *)(this + 0x31c) + 0x120),
                              (float)dVar10,(uchar)this[900]);
      *(float *)(this + 0x120) = (float)dVar9;
      if ((*(TOuterParam **)(this + 0x360) != (TOuterParam *)0x0) &&
         (cVar4 = TOuterParam::checkOuterSwitch(*(TOuterParam **)(this + 0x360),0x80), cVar4 != '\0'
         )) {
        for (bVar5 = 0; bVar5 < 8; bVar5 = bVar5 + 1) {
          uVar3 = TOuterParam::getIntFirFilter(*(TOuterParam **)(this + 0x360),bVar5);
          *(undefined2 *)(this + (uint)bVar5 * 2 + 0x124) = uVar3;
        }
        this[0x159] = (TTrack)0x8;
      }
      fVar1 = JAudio::_1184;
      for (bVar5 = 0; bVar5 < 4; bVar5 = bVar5 + 1) {
        *(short *)(this + (uint)bVar5 * 2 + 0x134) =
             (short)(int)(fVar1 * *(float *)(this + (uint)bVar5 * 0x10 + 0x22c));
      }
      this[0x159] = (TTrack)((byte)this[0x159] | 0x20);
      *(short *)(this + 0x144) = (short)(int)(JAudio::_1184 * *(float *)(this + 0x1bc));
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  __psq_l0(auStack56,uVar6);
  __psq_l1(auStack56,uVar6);
  __psq_l0(auStack72,uVar6);
  __psq_l1(auStack72,uVar6);
  __psq_l0(auStack88,uVar6);
  __psq_l1(auStack88,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x8028233c) */
/* WARNING: Removing unreachable block (ram,0x8028232c) */
/* WARNING: Removing unreachable block (ram,0x8028231c) */
/* WARNING: Removing unreachable block (ram,0x80281f24) */
/* WARNING: Removing unreachable block (ram,0x80282324) */
/* WARNING: Removing unreachable block (ram,0x80282334) */
/* WARNING: Removing unreachable block (ram,0x80282344) */
/* __thiscall TTrack::updateTrack(unsigned long) */

void __thiscall TTrack::updateTrack(TTrack *this,ulong param_1)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  TTrack TVar7;
  TTrack *this_00;
  char cVar9;
  undefined2 uVar8;
  byte bVar10;
  undefined4 uVar11;
  double dVar12;
  undefined8 in_f26;
  double dVar13;
  double in_f27;
  double in_f28;
  double in_f29;
  double in_f30;
  undefined8 in_f31;
  double dVar14;
  char local_98 [8];
  double local_90;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,SUB84(in_f30,0),0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,SUB84(in_f29,0),0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,SUB84(in_f28,0),0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,SUB84(in_f27,0),0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  if (this[0x37b] != (TTrack)0x4) {
    local_90 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 0x2a2));
    dVar13 = (double)((float)(local_90 - JAudio::_804) / JAudio::_1184);
    this_00 = this;
    if ((param_1 & 0x20000) != 0) {
      TVar7 = (TTrack)0x0;
      __psq_st0(local_98,(int)((ulonglong)(double)(JAudio::_1185 * *(float *)(this + 0x27c)) >> 0x20
                              ),0x60006);
      this_00 = (TTrack *)(int)local_98[0];
      if (local_98[0] < '\0') {
        TVar7 = (TTrack)-local_98[0];
        this_00 = (TTrack *)0x0;
      }
      this[0x152] = TVar7;
      this[0x153] = SUB41(this_00,0);
    }
    if (((param_1 & 0x40) != 0) && (*(int *)(this + 0x31c) == 0)) {
      this_00 = (TTrack *)updateTempo(this);
    }
    dVar14 = (double)JAudio::_737;
    uVar2 = param_1 & 1;
    if (uVar2 != 0) {
      in_f30 = (double)*(float *)(this + 0x16c);
      if (this[0x37d] == (TTrack)0x0) {
        in_f30 = (double)(float)(in_f30 * in_f30);
      }
      if (this[0x386] != (TTrack)0x0) {
        in_f30 = (double)JAudio::_680;
      }
      this_00 = *(TTrack **)(this + 0x360);
      if ((this_00 != (TTrack *)0x0) &&
         (this_00 = (TTrack *)TOuterParam::checkOuterSwitch((TOuterParam *)this_00,1),
         ((uint)this_00 & 0xff) != 0)) {
        this_00 = *(TTrack **)(this + 0x360);
        in_f30 = (double)(float)(in_f30 * (double)*(float *)((TOuterParam *)this_00 + 4));
      }
      if ((this[0x385] != (TTrack)0x0) && (((byte)this[0x37c] & 1) != 0)) {
        in_f30 = (double)(float)(in_f30 * (double)*(float *)(this + 0x26c));
      }
    }
    uVar3 = param_1 & 2;
    if (uVar3 != 0) {
      local_90 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 0x29a));
      dVar14 = (double)Player::pitchToCent((Player *)this_00,*(float *)(this + 0x17c),
                                           (float)(local_90 - JAudio::_804));
      dVar12 = (double)TVibrate::getValue((TVibrate *)(this + 0xec));
      dVar14 = (double)(float)(dVar14 * dVar12);
      if ((*(TOuterParam **)(this + 0x360) != (TOuterParam *)0x0) &&
         (cVar9 = TOuterParam::checkOuterSwitch(*(TOuterParam **)(this + 0x360),2), cVar9 != '\0'))
      {
        dVar14 = (double)(float)(dVar14 * (double)*(float *)(*(int *)(this + 0x360) + 8));
      }
    }
    uVar4 = param_1 & 8;
    if (uVar4 != 0) {
      in_f29 = (double)*(float *)(this + 0x19c);
      if ((*(TOuterParam **)(this + 0x360) != (TOuterParam *)0x0) &&
         (cVar9 = TOuterParam::checkOuterSwitch(*(TOuterParam **)(this + 0x360),8), cVar9 != '\0'))
      {
        in_f29 = (double)panCalc(this,(float)in_f29,*(float *)(*(int *)(this + 0x360) + 0x14),
                                 (float)dVar13,(uchar)this[0x37f]);
      }
    }
    uVar5 = param_1 & 4;
    if (uVar5 != 0) {
      in_f28 = (double)*(float *)(this + 0x18c);
      if ((*(TOuterParam **)(this + 0x360) != (TOuterParam *)0x0) &&
         (cVar9 = TOuterParam::checkOuterSwitch(*(TOuterParam **)(this + 0x360),4), cVar9 != '\0'))
      {
        in_f28 = (double)panCalc(this,(float)in_f28,*(float *)(*(int *)(this + 0x360) + 0xc),
                                 (float)dVar13,(uchar)this[0x380]);
      }
    }
    uVar6 = param_1 & 0x10;
    if (uVar6 != 0) {
      in_f27 = (double)*(float *)(this + 0x1ac);
      if ((*(TOuterParam **)(this + 0x360) != (TOuterParam *)0x0) &&
         (cVar9 = TOuterParam::checkOuterSwitch(*(TOuterParam **)(this + 0x360),0x10), cVar9 != '\0'
         )) {
        in_f27 = (double)panCalc(this,(float)in_f27,*(float *)(*(int *)(this + 0x360) + 0x10),
                                 (float)dVar13,(uchar)this[0x381]);
      }
    }
    fVar1 = JAudio::_1184;
    if ((param_1 & 0xf000) != 0) {
      for (bVar10 = 0; bVar10 < 4; bVar10 = bVar10 + 1) {
        local_90 = (double)(longlong)(int)(fVar1 * *(float *)(this + (uint)bVar10 * 0x10 + 0x22c));
        *(short *)(this + (uint)bVar10 * 2 + 0x134) =
             (short)(int)(fVar1 * *(float *)(this + (uint)bVar10 * 0x10 + 0x22c));
      }
      this[0x159] = (TTrack)((byte)this[0x159] | 0x20);
    }
    if (((*(TOuterParam **)(this + 0x360) != (TOuterParam *)0x0) && ((param_1 & 0x80) != 0)) &&
       (cVar9 = TOuterParam::checkOuterSwitch(*(TOuterParam **)(this + 0x360),0x80), cVar9 != '\0'))
    {
      for (bVar10 = 0; bVar10 < 8; bVar10 = bVar10 + 1) {
        uVar8 = TOuterParam::getIntFirFilter(*(TOuterParam **)(this + 0x360),bVar10);
        *(undefined2 *)(this + (uint)bVar10 * 2 + 0x124) = uVar8;
      }
      this[0x159] = (TTrack)(((byte)this[0x159] & 0x20) + 8);
    }
    if ((param_1 & 0x20) != 0) {
      *(short *)(this + 0x144) = (short)(int)(JAudio::_1184 * *(float *)(this + 0x1bc));
    }
    if ((*(int *)(this + 0x31c) == 0) || (((byte)this[0x37b] & 1) != 0)) {
      if (uVar2 != 0) {
        *(float *)(this + 0x110) = (float)in_f30;
      }
      if (uVar3 != 0) {
        *(float *)(this + 0x114) = (float)dVar14;
      }
      if (uVar4 != 0) {
        *(float *)(this + 0x118) = (float)in_f29;
      }
      if (uVar5 != 0) {
        *(float *)(this + 0x11c) = (float)in_f28;
      }
      if (uVar6 != 0) {
        *(float *)(this + 0x120) = (float)in_f27;
      }
    }
    else {
      local_90 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 0x2a4));
      fVar1 = (float)(local_90 - JAudio::_804) / JAudio::_1184;
      dVar13 = (double)fVar1;
      if (uVar2 != 0) {
        *(float *)(this + 0x110) =
             (float)((double)*(float *)(*(int *)(this + 0x31c) + 0x110) * in_f30);
      }
      if (uVar3 != 0) {
        *(float *)(this + 0x114) =
             (float)((double)*(float *)(*(int *)(this + 0x31c) + 0x114) * dVar14);
      }
      if (uVar4 != 0) {
        dVar14 = (double)panCalc(this,(float)in_f29,*(float *)(*(int *)(this + 0x31c) + 0x118),fVar1
                                 ,(uchar)this[0x382]);
        *(float *)(this + 0x118) = (float)dVar14;
      }
      if (uVar5 != 0) {
        dVar14 = (double)panCalc(this,(float)in_f28,*(float *)(*(int *)(this + 0x31c) + 0x11c),
                                 (float)dVar13,(uchar)this[899]);
        *(float *)(this + 0x11c) = (float)dVar14;
      }
      if (uVar6 != 0) {
        dVar13 = (double)panCalc(this,(float)in_f27,*(float *)(*(int *)(this + 0x31c) + 0x120),
                                 (float)dVar13,(uchar)this[900]);
        *(float *)(this + 0x120) = (float)dVar13;
      }
    }
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  __psq_l0(auStack40,uVar11);
  __psq_l1(auStack40,uVar11);
  __psq_l0(auStack56,uVar11);
  __psq_l1(auStack56,uVar11);
  __psq_l0(auStack72,uVar11);
  __psq_l1(auStack72,uVar11);
  __psq_l0(auStack88,uVar11);
  __psq_l1(auStack88,uVar11);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TTrack::updateTempo(void) */

void __thiscall TTrack::updateTempo(TTrack *this)

{
  double dVar1;
  char cVar3;
  ulong uVar2;
  TTrack *this_00;
  int iVar4;
  int iVar5;
  
  dVar1 = JAudio::_804;
  if (*(int *)(this + 0x31c) == 0) {
    *(float *)(this + 0x368) =
         (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 0x378)) - JAudio::_804);
    *(float *)(this + 0x368) =
         *(float *)(this + 0x368) *
         (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 0x376)) - dVar1);
    *(float *)(this + 0x368) = *(float *)(this + 0x368) / _gDacRate;
    *(float *)(this + 0x368) = *(float *)(this + 0x368) * JAudio::_1348;
    if ((*(TOuterParam **)(this + 0x360) != (TOuterParam *)0x0) &&
       (cVar3 = TOuterParam::checkOuterSwitch(*(TOuterParam **)(this + 0x360),0x40), cVar3 != '\0'))
    {
      *(float *)(this + 0x368) =
           *(float *)(this + 0x368) * *(float *)(*(int *)(this + 0x360) + 0x18);
    }
  }
  else {
    *(undefined4 *)(this + 0x368) = *(undefined4 *)(*(int *)(this + 0x31c) + 0x368);
    *(undefined2 *)(this + 0x378) = *(undefined2 *)(*(int *)(this + 0x31c) + 0x378);
  }
  iVar4 = 0;
  iVar5 = 0;
  do {
    this_00 = *(TTrack **)(this + iVar5 + 800);
    if ((this_00 != (TTrack *)0x0) && (this_00[0x37e] != (TTrack)0x0)) {
      if (this != *(TTrack **)(this_00 + 0x31c)) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"JASTrack.cpp",0x487,"this == child->mParent");
        m_Do_printf::OSPanic("JASTrack.cpp",0x487,"Halt");
      }
      updateTempo(this_00);
    }
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 0x10);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall TTrack::updateSeq(unsigned long,
                                          bool) */

void __thiscall TTrack::updateSeq(TTrack *this,ulong param_1,bool param_2)

{
  uint uVar1;
  TTrack *this_00;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_1 | *(uint *)(this + 0x370);
  if (*(TOuterParam **)(this + 0x360) != (TOuterParam *)0x0) {
    uVar1 = TOuterParam::getOuterUpdate(*(TOuterParam **)(this + 0x360));
    uVar3 = uVar3 | uVar1 & 0xffff;
    TOuterParam::setOuterUpdate(*(TOuterParam **)(this + 0x360),0);
  }
  TVibrate::incCounter((TVibrate *)(this + 0xec));
  *(undefined4 *)(this + 0x370) = 0;
  if (uVar3 != 0) {
    updateTrack(this,uVar3);
  }
  iVar2 = 0;
  iVar4 = 0;
  do {
    this_00 = *(TTrack **)(this + iVar4 + 800);
    if ((this_00 != (TTrack *)0x0) && (this_00[0x37e] != (TTrack)0x0)) {
      if (param_2 == false) {
        *(uint *)(this_00 + 0x370) = *(uint *)(this_00 + 0x370) | uVar3;
      }
      else {
        updateSeq(this_00,uVar3,param_2);
      }
    }
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar2 < 0x10);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TTrack::seqTimeToDspTime(long,
                                                 unsigned char) */

int __thiscall TTrack::seqTimeToDspTime(TTrack *this,long param_1,uchar param_2)

{
  float fVar1;
  double local_10;
  
  local_10 = (double)CONCAT44(0x43300000,(uint)param_2);
  fVar1 = ((float)((double)CONCAT44(0x43300000,param_1 ^ 0x80000000) - JAudio::_1386) *
          (float)(local_10 - JAudio::_804)) / JAudio::_1382;
  if (this[0x387] == (TTrack)0x0) {
    local_10 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 0x378));
    fVar1 = (JAudio::_1383 * fVar1) / (float)(local_10 - JAudio::_804);
    if (_gOutputRate == 0) {
      local_10 = (double)CONCAT44(0x43300000,_gSubFrames);
      fVar1 = (fVar1 * (float)(local_10 - JAudio::_804)) / JAudio::_1384;
    }
  }
  else {
    fVar1 = fVar1 / *(float *)(this + 0x368);
  }
  return (int)fVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8028276c) */
/* __thiscall TTrack::setParam(int,
                                         float,
                                         int) */

void __thiscall TTrack::setParam(TTrack *this,int param_1,float param_2,int param_3)

{
  ulong uVar1;
  float *pfVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar4 = (double)param_2;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASTrack.cpp",0x4d4,"target >= 0");
    m_Do_printf::OSPanic("JASTrack.cpp",0x4d4,"Halt");
  }
  if (0x11 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASTrack.cpp",0x4d5,"target < TIMED_PARAMS");
    m_Do_printf::OSPanic("JASTrack.cpp",0x4d5,"Halt");
  }
  pfVar2 = (float *)(this + param_1 * 0x10 + 0x16c);
  pfVar2[1] = (float)dVar4;
  dVar4 = JAudio::_1386;
  if (param_3 < 1) {
    *pfVar2 = pfVar2[1];
    pfVar2[3] = JAudio::_680;
    pfVar2[2] = JAudio::_737;
  }
  else {
    pfVar2[3] = (pfVar2[1] - *pfVar2) /
                (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000U) - JAudio::_1386);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000U) - dVar4);
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __thiscall TTrack::setSeqData(unsigned char *,
                                           long,
                                           int) */

undefined4 __thiscall
TTrack::setSeqData(TTrack *this,uchar *param_1,long param_2,int param_3)

{
  init(this,(EVP_PKEY_CTX *)param_1);
  this[0x37b] = (TTrack)0x3;
  TSeqCtrl::start((TSeqCtrl *)this,param_1,0);
  updateTrackAll(this);
  this[0x37e] = (TTrack)0x2;
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x8028281c) */
/* __thiscall TTrack::startSeq(void) */

undefined4 __thiscall TTrack::startSeq(TTrack *this)

{
  TTrack TVar1;
  void *in_r5;
  
  TVar1 = this[0x37e];
  if (TVar1 == (TTrack)0x2) {
    this[0x37e] = (TTrack)0x1;
  }
  else {
    if ((byte)TVar1 < 2) {
      if (TVar1 != (TTrack)0x0) {
        m_Do_printf::OSReport("in Player StartSeq:   既に動作中です\n");
        return 0;
      }
      m_Do_printf::OSReport("in Player StartSeq:   準備ができていません\n");
      return 0;
    }
    if ((byte)TVar1 < 4) {
      m_Do_printf::OSReport("in Player StartSeq: 停止中です\n");
      return 0;
    }
  }
  Kernel::registerSubFrameCallback((Kernel *)rootCallback,(FuncDef572 *)this,in_r5);
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x802828c0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TTrack::stopSeq(void) */

undefined4 __thiscall TTrack::stopSeq(TTrack *this)

{
  TTrack TVar1;
  
  TVar1 = this[0x37e];
  if (TVar1 != (TTrack)0x1) {
    if (TVar1 == (TTrack)0x0) {
      return 1;
    }
    if ((byte)TVar1 < 3) {
      this[0x37e] = (TTrack)0x0;
      if (this[0x389] == (TTrack)0x0) {
        return 1;
      }
      if (this == (TTrack *)0x0) {
        return 1;
      }
      *(TTrack **)this = _sFreeList;
      _sFreeList = this;
      return 1;
    }
  }
  this[0x37e] = (TTrack)0x3;
  return 1;
}


/* __thiscall TTrack::stopSeqMain(void) */

void __thiscall TTrack::stopSeqMain(TTrack *this)

{
  int __fd;
  
  updateSeq(this,0,true);
  close(this,__fd);
  return;
}


/* __thiscall TTrack::noteOffAll(void) */

void __thiscall TTrack::noteOffAll(TTrack *this)

{
  EVP_PKEY_CTX *in_r4;
  EVP_PKEY_CTX *extraout_r4;
  EVP_PKEY_CTX *extraout_r4_00;
  byte bVar1;
  
  if (*(int *)(this + 0x31c) == 0) {
    for (bVar1 = 0; bVar1 < 8; bVar1 = bVar1 + 1) {
      noteOff(this,bVar1,10);
      in_r4 = extraout_r4;
    }
  }
  else {
    for (bVar1 = 0; bVar1 < 8; bVar1 = bVar1 + 1) {
      noteOff(this,bVar1,0);
      in_r4 = extraout_r4_00;
    }
  }
  TNoteMgr::init((TNoteMgr *)(this + 0xb4),in_r4);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TTrack::close(void) */

int __thiscall TTrack::close(TTrack *this,int __fd)

{
  int extraout_r4;
  int __fd_00;
  int iVar1;
  int iVar2;
  
  if (this[0x37e] != (TTrack)0x0) {
    noteOffAll(this);
    this[0x37e] = (TTrack)0x0;
    iVar1 = 0;
    iVar2 = 0;
    __fd_00 = extraout_r4;
    do {
      if (*(TTrack **)(this + iVar2 + 800) != (TTrack *)0x0) {
        close(*(TTrack **)(this + iVar2 + 800),__fd_00);
        *(undefined4 *)(this + iVar2 + 800) = 0;
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar1 < 0x10);
    this[0x386] = (TTrack)0x0;
    releaseChannelAll(this);
    if ((this[0x389] != (TTrack)0x0) && (this != (TTrack *)0x0)) {
      *(TTrack **)this = _sFreeList;
      _sFreeList = this;
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TTrack::muteTrack(bool) */

void __thiscall TTrack::muteTrack(TTrack *this,bool param_1)

{
  int iVar1;
  byte bVar3;
  int iVar2;
  
  this[0x386] = (TTrack)param_1;
  *(uint *)(this + 0x370) = *(uint *)(this + 0x370) | 1;
  if ((this[0x386] != (TTrack)0x0) && (((byte)this[0x37c] & 0x20) != 0)) {
    for (bVar3 = 0; bVar3 < 8; bVar3 = bVar3 + 1) {
      noteOff(this,bVar3,10);
    }
  }
  iVar1 = 0;
  iVar2 = 0;
  do {
    if (*(TTrack **)(this + iVar2 + 800) != (TTrack *)0x0) {
      muteTrack(*(TTrack **)(this + iVar2 + 800),param_1);
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar1 < 0x10);
  return;
}


/* __thiscall TTrack::start(void *,
                                      unsigned long) */

undefined4 __thiscall TTrack::start(TTrack *this,void *param_1,ulong param_2)

{
  TSeqCtrl::start((TSeqCtrl *)this,param_1,param_2);
  this[0x37e] = (TTrack)0x1;
  updateTrackAll(this);
  return 0;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TTrack::openChild(unsigned char,
                                          unsigned char) */

int * __thiscall TTrack::openChild(TTrack *this,uchar param_1,uchar param_2)

{
  uint uVar1;
  ulong uVar2;
  int *this_00;
  undefined3 in_register_00000010;
  EVP_PKEY_CTX *ctx;
  EVP_PKEY_CTX *extraout_r4;
  TTrack *pTVar3;
  
  ctx = (EVP_PKEY_CTX *)CONCAT31(in_register_00000010,param_1);
  if (0xf < param_1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASTrack.cpp",0x5a8,"trk_no < MAX_CHILDREN");
    m_Do_printf::OSPanic("JASTrack.cpp",0x5a8,"Halt");
    ctx = extraout_r4;
  }
  pTVar3 = this + (uint)param_1 * 4;
  if (*(TTrack **)(pTVar3 + 800) != (TTrack *)0x0) {
    close(*(TTrack **)(pTVar3 + 800),(int)ctx);
    *(undefined4 *)(pTVar3 + 800) = 0;
  }
  if (_sFreeList == (int *)0x0) {
    this_00 = (int *)0x0;
  }
  else {
    this_00 = _sFreeList;
    _sFreeList = (int *)*_sFreeList;
  }
  if (this_00 != (int *)0x0) {
    TTrack((TTrack *)this_00);
  }
  if (this_00 == (int *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f
              (uVar2,"JASTrack.cpp",0x5b3,"%s",(___)"JASTrackが足りません。\n");
    this_00 = (int *)0x0;
  }
  else {
    init((TTrack *)this_00,ctx);
    *(undefined *)((int)this_00 + 0x389) = 1;
    this_00[199] = (int)this;
    *(uchar *)((int)this_00 + 0x37b) = param_2;
    uVar1 = *(uint *)(this + 0x36c);
    if (0x6fffffff < (uVar1 & 0xf0000000)) {
      m_Do_printf::OSReport
                (
                "JASTrack:openTrack: 階層が8段階を超えてしまい、不正なトラックIDが生成されました\n"
                );
    }
    this_00[0xdb] =
         (uVar1 & 0xf0000000) + 0x10000000 |
         (*(uint *)(this + 0x36c) & 0xffffff) << 4 | (uint)param_1;
    *(int **)(pTVar3 + 800) = this_00;
    inherit((TTrack *)this_00);
  }
  return this_00;
}


/* __thiscall TTrack::loadTbl(unsigned long,
                                        unsigned long,
                                        unsigned long) */

TTrack * __thiscall
TTrack::loadTbl(TTrack *this,ulong param_1,ulong param_2,ulong param_3)

{
  uint uVar1;
  
  if (param_3 == 6) {
    this = (TTrack *)TSeqCtrl::get24((TSeqCtrl *)this,param_1 + param_2 * 3);
  }
  else {
    if ((int)param_3 < 6) {
      if (param_3 == 4) {
        this = (TTrack *)(uint)*(byte *)(*(int *)this + param_1 + param_2);
      }
      else {
        if (3 < (int)param_3) {
          uVar1 = TSeqCtrl::get16((TSeqCtrl *)this,param_1 + param_2 * 2);
          this = (TTrack *)(uVar1 & 0xffff);
        }
      }
    }
    else {
      if (param_3 == 8) {
        this = (TTrack *)TSeqCtrl::get32((TSeqCtrl *)this,param_1 + param_2);
      }
      else {
        if ((int)param_3 < 8) {
          this = (TTrack *)TSeqCtrl::get32((TSeqCtrl *)this,param_1 + param_2 * 4);
        }
      }
    }
  }
  return this;
}


/* __thiscall TTrack::exchangeRegisterValue(unsigned char) */

uint __thiscall TTrack::exchangeRegisterValue(TTrack *this,uchar param_1)

{
  uint uVar1;
  undefined3 in_register_00000010;
  
  if (param_1 < 0x40) {
    uVar1 = readReg32(this,param_1);
  }
  else {
    uVar1 = (uint)*(ushort *)
                   (this + ((CONCAT31(in_register_00000010,param_1) + -0x40) * 2 & 0x1feU) + 0x68);
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TTrack::readReg32(unsigned char) */

uint __thiscall TTrack::readReg32(TTrack *this,uchar param_1)

{
  ulong uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)param_1;
  if (uVar3 < 0x28) {
    if (uVar3 == 0x23) {
      iVar2 = readReg16(this,'\x04');
      uVar3 = readReg16(this,'\x05');
      return iVar2 << 0x10 | uVar3 & 0xffff;
    }
  }
  else {
    if (uVar3 < 0x2c) {
      if ((int)(uVar3 - 0x28) < 0) {
        uVar1 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar1,"JASRegisterParam.h",0x82,"index >= 0");
        m_Do_printf::OSPanic("JASRegisterParam.h",0x82,"Halt");
      }
      if (3 < (int)(uVar3 - 0x28)) {
        uVar1 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar1,"JASRegisterParam.h",0x83,"index < 4");
        m_Do_printf::OSPanic("JASRegisterParam.h",0x83,"Halt");
      }
      return *(uint *)(this + uVar3 * 4 + 0x20c);
    }
  }
  uVar3 = readReg16(this,param_1);
  return uVar3 & 0xffff;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TTrack::readReg16(unsigned char) */

uint __thiscall TTrack::readReg16(TTrack *this,uchar param_1)

{
  bool bVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 == '#') {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASTrack.cpp",0x611,"target != TRegisterParam::PARAM_REG_XY");
    m_Do_printf::OSPanic("JASTrack.cpp",0x611,"Halt");
  }
  bVar1 = false;
  if ((param_1 < 0x28) || (0x2b < param_1)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"JASTrack.cpp",0x612,
               "target < TRegisterParam::PARAM_REG_AR0 || target > TRegisterParam::PARAM_REG_AR3");
    m_Do_printf::OSPanic("JASTrack.cpp",0x612,"Halt");
  }
  switch(param_1) {
  case ' ':
    uVar4 = TRegisterParam::getBankNumber((TRegisterParam *)(this + 0x28c));
    uVar4 = uVar4 & 0xff;
    break;
  case '!':
    uVar4 = TRegisterParam::getProgramNumber((TRegisterParam *)(this + 0x28c));
    uVar4 = uVar4 & 0xff;
    break;
  case '\"':
    uVar3 = readReg16(this,'\0');
    uVar4 = readReg16(this,'\x01');
    uVar4 = (uVar3 & 0xff) << 8 | uVar4;
    break;
  default:
    uVar4 = (uint)*(ushort *)(this + (uint)param_1 * 2 + 0x28c);
    break;
  case ',':
    uVar4 = 0;
    iVar5 = 0x3c;
    iVar6 = 0x10;
    do {
      uVar4 = (uVar4 & 0x7fff) << 1;
      if ((*(int *)(this + iVar5 + 800) != 0) &&
         (*(char *)(*(int *)(this + iVar5 + 800) + 0x37e) != '\0')) {
        uVar4 = uVar4 | 1;
      }
      iVar5 = iVar5 + -4;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    break;
  case '-':
    uVar4 = 0;
    iVar5 = 7;
    do {
      uVar3 = checkNoteStop(this,iVar5);
      uVar4 = (uVar4 & 0x7fff) << 1 | uVar3 & 0xff;
      iVar5 = iVar5 + -1;
    } while (-1 < iVar5);
    break;
  case '0':
    if (*(int *)(this + 0xc) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (uint)*(ushort *)(this + *(int *)(this + 0xc) * 2 + 0x2e);
    }
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x802830e8) */
/* __thiscall TTrack::writeRegDirect(unsigned char,
                                               unsigned short) */

void __thiscall TTrack::writeRegDirect(TTrack *this,uchar param_1,ushort param_2)

{
  Player *this_00;
  uint uVar1;
  
  this_00 = (Player *)(uint)param_2;
  uVar1 = (uint)param_1;
  if (param_1 < 0x20) {
    if (param_1 < 3) {
      this_00 = (Player *)(param_2 & 0xff);
      param_2 = Player::extend8to16(this_00,param_1);
    }
  }
  else {
    if (param_1 == '\"') {
      writeRegDirect(this,'\0',(ushort)((uint)this_00 >> 8));
      uVar1 = 1;
      this_00 = (Player *)(param_2 & 0xff);
    }
    else {
      if (param_1 < 0x22) {
        return;
      }
    }
  }
  *(short *)(this + uVar1 * 2 + 0x28c) = (short)this_00;
  *(ushort *)(this + 0x292) = param_2;
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x80283318) */
/* WARNING: Removing unreachable block (ram,0x802834f0) */
/* __thiscall TTrack::writeRegParam(unsigned char) */

void __thiscall TTrack::writeRegParam(TTrack *this,uchar param_1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uchar *puVar4;
  short sVar7;
  Player *this_00;
  short sVar8;
  ushort uVar9;
  ushort uVar10;
  ulong uVar5;
  int iVar6;
  uchar extraout_r4;
  uchar extraout_r4_00;
  uchar extraout_r4_01;
  uchar extraout_r4_02;
  uchar extraout_r4_03;
  uchar extraout_r4_04;
  uchar uVar11;
  uint unaff_r22;
  uint uVar12;
  Player *unaff_r24;
  ulong unaff_r25;
  ulong unaff_r26;
  byte bVar13;
  byte bVar14;
  uint uVar15;
  ushort unaff_r31;
  int iVar16;
  
  bVar13 = param_1 & 0xf;
  if (bVar13 == 10) {
    pbVar3 = *(byte **)(this + 4);
    *(byte **)(this + 4) = pbVar3 + 1;
    bVar13 = *pbVar3;
    bVar14 = bVar13 & 0xc;
    unaff_r26 = (bVar13 >> 4) + 4;
    bVar13 = 10;
  }
  else {
    if (bVar13 < 10) {
      if (8 < bVar13) {
        pbVar3 = *(byte **)(this + 4);
        *(byte **)(this + 4) = pbVar3 + 1;
        bVar13 = *pbVar3;
        bVar14 = bVar13 & 0xc;
        bVar13 = bVar13 & 0xf0;
        if (bVar14 == 8) {
          bVar14 = 0x10;
        }
        goto LAB_80283204;
      }
    }
    else {
      if (bVar13 < 0xc) {
        bVar14 = 0;
        bVar13 = 0xb;
        goto LAB_80283204;
      }
    }
    bVar14 = param_1 & 0xc;
    bVar13 = param_1 & 3;
  }
LAB_80283204:
  pbVar3 = *(byte **)(this + 4);
  *(byte **)(this + 4) = pbVar3 + 1;
  bVar1 = *pbVar3;
  uVar15 = (uint)bVar1;
  if (bVar13 == 10) {
    puVar4 = *(uchar **)(this + 4);
    *(uchar **)(this + 4) = puVar4 + 1;
    unaff_r25 = readReg32(this,*puVar4);
  }
  switch(bVar14) {
  case 0:
    puVar4 = *(uchar **)(this + 4);
    *(uchar **)(this + 4) = puVar4 + 1;
    sVar7 = readReg16(this,*puVar4);
    unaff_r24 = (Player *)(int)sVar7;
    break;
  case 4:
    pbVar3 = *(byte **)(this + 4);
    *(byte **)(this + 4) = pbVar3 + 1;
    unaff_r24 = (Player *)(uint)*pbVar3;
    break;
  case 8:
    pbVar3 = *(byte **)(this + 4);
    *(byte **)(this + 4) = pbVar3 + 1;
    bVar2 = *pbVar3;
    if ((bVar2 & 0x80) == 0) {
      unaff_r24 = (Player *)(int)(short)((ushort)bVar2 << 8 | (ushort)bVar2 << 1);
    }
    else {
      unaff_r24 = (Player *)(int)(short)((ushort)bVar2 << 8);
    }
    break;
  case 0xc:
    sVar7 = TSeqCtrl::read16((TSeqCtrl *)this);
    unaff_r24 = (Player *)(int)sVar7;
    break;
  case 0x10:
    unaff_r24 = (Player *)&DAT_ffffffff;
  }
  sVar8 = (short)unaff_r24;
  this_00 = (Player *)readReg16(this,bVar1);
  sVar7 = (short)this_00;
  uVar12 = SEXT24(sVar7);
  uVar11 = extraout_r4;
  if (bVar13 == 0x20) {
    if (bVar14 == 4) {
      sVar8 = Player::extend8to16((Player *)((uint)unaff_r24 & 0xff),extraout_r4);
      uVar11 = extraout_r4_02;
    }
    if (sVar8 < 0) {
      unaff_r24 = (Player *)(int)(short)((int)uVar12 >> (-(int)sVar8 & 0x3fU));
    }
    else {
      unaff_r24 = (Player *)(int)(short)(uVar12 << (int)sVar8);
    }
  }
  else {
    if (bVar13 < 0x20) {
      if (bVar13 == 10) {
        unaff_r22 = loadTbl(this,unaff_r25,(int)sVar8,unaff_r26);
        unaff_r24 = (Player *)(int)(short)unaff_r22;
        uVar11 = extraout_r4_04;
      }
      else {
        if (bVar13 < 10) {
          if (bVar13 == 2) {
            writeRegDirect(this,'\x04',(ushort)(uVar12 * (int)sVar8 >> 0x10));
            writeRegDirect(this,'\x05',(ushort)(uVar12 * (int)sVar8));
            return;
          }
          if (bVar13 < 2) {
            if (bVar13 != 0) {
              if (bVar14 == 4) {
                unaff_r24 = (Player *)
                            Player::extend8to16((Player *)((uint)unaff_r24 & 0xff),extraout_r4);
                uVar11 = extraout_r4_00;
              }
              unaff_r24 = unaff_r24 + uVar12;
            }
          }
          else {
            if (bVar13 < 4) {
              *(short *)(this + 0x292) = sVar7 - sVar8;
              return;
            }
          }
        }
        else {
          if (bVar13 == 0x10) {
            if (bVar14 == 4) {
              sVar8 = Player::extend8to16((Player *)((uint)unaff_r24 & 0xff),extraout_r4);
              uVar11 = extraout_r4_01;
            }
            if (sVar8 < 0) {
              unaff_r24 = (Player *)(int)(short)((int)(uVar12 & 0xffff) >> (-(int)sVar8 & 0x3fU));
            }
            else {
              unaff_r24 = (Player *)(int)(short)((uVar12 & 0xffff) << (int)sVar8);
            }
          }
          else {
            if ((bVar13 < 0x10) && (bVar13 < 0xc)) {
              unaff_r24 = (Player *)(int)(short)(sVar7 - sVar8);
            }
          }
        }
      }
    }
    else {
      if (bVar13 == 0x50) {
        unaff_r24 = (Player *)((uint)unaff_r24 ^ uVar12);
      }
      else {
        if (bVar13 < 0x50) {
          if (bVar13 == 0x40) {
            unaff_r24 = (Player *)((uint)unaff_r24 | uVar12);
          }
          else {
            if ((bVar13 < 0x40) && (bVar13 == 0x30)) {
              unaff_r24 = (Player *)((uint)unaff_r24 & uVar12);
            }
          }
        }
        else {
          if (bVar13 == 0x90) {
            unaff_r22 = Player::getRandomS32(this_00);
            unaff_r24 = (Player *)
                        (int)(short)((short)unaff_r22 -
                                    (short)(unaff_r22 / ((uint)unaff_r24 & 0xffff)) *
                                    (short)((uint)unaff_r24 & 0xffff));
            uVar11 = extraout_r4_03;
          }
          else {
            if ((bVar13 < 0x90) && (bVar13 == 0x60)) {
              unaff_r24 = (Player *)(int)-sVar7;
            }
          }
        }
      }
    }
  }
  uVar9 = (ushort)unaff_r24;
  if (uVar15 == 0x22) {
    writeRegDirect(this,'\0',(ushort)((uint)(int)(short)uVar9 >> 8));
    uVar15 = 1;
    unaff_r24 = (Player *)((int)(short)uVar9 & 0xff);
    uVar9 = (ushort)unaff_r24;
  }
  else {
    if (uVar15 < 0x22) {
      if (uVar15 == 0x20) {
        uVar10 = TRegisterParam::getProgramNumber((TRegisterParam *)(this + 0x28c));
        unaff_r24 = (Player *)(int)(short)(uVar10 & 0xff | (ushort)((int)(short)uVar9 << 8));
        uVar15 = 6;
        uVar9 = unaff_r31;
      }
      else {
        if (uVar15 < 0x20) {
          if (uVar15 < 3) {
            unaff_r24 = (Player *)((uint)unaff_r24 & 0xff);
            uVar9 = Player::extend8to16(unaff_r24,uVar11);
          }
        }
        else {
          iVar6 = TRegisterParam::getBankNumber((TRegisterParam *)(this + 0x28c));
          unaff_r24 = (Player *)(int)(short)((ushort)(iVar6 << 8) | uVar9 & 0xff);
          uVar15 = 6;
          uVar9 = unaff_r31;
        }
      }
    }
    else {
      if (uVar15 == 0x2e) {
        unaff_r24 = (Player *)(int)(short)(*(ushort *)(this + 0x2a6) & 0xff00 | uVar9 & 0xff);
        uVar15 = 0xd;
        uVar9 = unaff_r31;
      }
      else {
        if (uVar15 < 0x2e) {
          if ((uVar15 < 0x2c) && (0x27 < uVar15)) {
            if ((int)(uVar15 - 0x28) < 0) {
              uVar5 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert(uVar5,"JASRegisterParam.h",0x7c,"index >= 0");
              m_Do_printf::OSPanic("JASRegisterParam.h",0x7c,"Halt");
            }
            if (3 < (int)(uVar15 - 0x28)) {
              uVar5 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert(uVar5,"JASRegisterParam.h",0x7d,"index < 4");
              m_Do_printf::OSPanic("JASRegisterParam.h",0x7d,"Halt");
            }
            *(uint *)(this + uVar15 * 4 + 0x20c) = unaff_r22;
            return;
          }
        }
        else {
          if (uVar15 < 0x30) {
            unaff_r24 = (Player *)
                        (int)(short)((ushort)((int)(short)uVar9 << 8) |
                                    *(ushort *)(this + 0x2a6) & 0xff);
            uVar15 = 0xd;
            uVar9 = unaff_r31;
          }
        }
      }
    }
  }
  *(short *)(this + uVar15 * 2 + 0x28c) = (short)unaff_r24;
  *(ushort *)(this + 0x292) = uVar9;
  if (uVar15 == 7) {
    *(uint *)(this + 0x370) = *(uint *)(this + 0x370) | 2;
  }
  else {
    if (uVar15 < 7) {
      if (5 < uVar15) {
        iVar6 = 0;
        iVar16 = 2;
        do {
          *(undefined4 *)(this + iVar6 + 0x2fc) = 0xf;
          iVar6 = iVar6 + 4;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
      }
    }
    else {
      if (uVar15 == 0xd) {
        *(uint *)(this + 0x160) = *(ushort *)(this + 0x2a6) | 0x10000;
        *(undefined2 *)(this + 0x164) = 0;
      }
    }
  }
  return;
}


/* __thiscall TTrack::readSelfPort(int) */

void __thiscall TTrack::readSelfPort(TTrack *this,int param_1)

{
  TTrackPort::readImport((TTrackPort *)(this + 0x48),param_1);
  return;
}


/* __thiscall TTrack::writeSelfPort(int,
                                              unsigned short) */

void __thiscall TTrack::writeSelfPort(TTrack *this,int param_1,ushort param_2)

{
  TTrackPort::writeExport((TTrackPort *)(this + 0x48),param_1,param_2);
  return;
}


/* __thiscall TTrack::writePortAppDirect(unsigned long,
                                                   unsigned short) */

undefined4 __thiscall
TTrack::writePortAppDirect(TTrack *this,ulong param_1,ushort param_2)

{
  ulong uVar1;
  
  TTrackPort::writeImport((TTrackPort *)(this + 0x48),param_1,param_2);
  if ((param_1 == 0) || (param_1 == 1)) {
    uVar1 = 4;
    if (param_1 == 0) {
      uVar1 = 3;
    }
    TIntrMgr::request((TIntrMgr *)(this + 0x88),uVar1);
  }
  return 1;
}


/* __thiscall TTrack::readPortAppDirect(unsigned long,
                                                  unsigned short *) */

undefined4 __thiscall
TTrack::readPortAppDirect(TTrack *this,ulong param_1,ushort *param_2)

{
  ushort uVar1;
  
  uVar1 = TTrackPort::readExport((TTrackPort *)(this + 0x48),param_1);
  *param_2 = uVar1;
  return 1;
}


/* __thiscall TTrack::routeTrack(unsigned long) */

TTrack * __thiscall TTrack::routeTrack(TTrack *this,ulong param_1)

{
  uint uVar1;
  
  uVar1 = param_1 >> 0x1c;
  if (uVar1 == 0) {
    return this;
  }
  do {
    this = *(TTrack **)(this + (param_1 & 0xf) * 4 + 800);
    if (this == (TTrack *)0x0) {
      return (TTrack *)0x0;
    }
    param_1 = param_1 >> 4;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return this;
}


/* __thiscall TTrack::writePortApp(unsigned long,
                                             unsigned short) */

undefined4 __thiscall TTrack::writePortApp(TTrack *this,ulong param_1,ushort param_2)

{
  TTrack *this_00;
  undefined4 uVar1;
  
  this_00 = (TTrack *)routeTrack(this,param_1);
  if (this_00 == (TTrack *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = writePortAppDirect(this_00,param_1 >> 0x10 & 0xff,param_2);
  }
  return uVar1;
}


/* __thiscall TTrack::readPortApp(unsigned long,
                                            unsigned short *) */

undefined4 __thiscall TTrack::readPortApp(TTrack *this,ulong param_1,ushort *param_2)

{
  TTrack *this_00;
  undefined4 uVar1;
  
  this_00 = (TTrack *)routeTrack(this,param_1);
  if (this_00 == (TTrack *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = readPortAppDirect(this_00,param_1 >> 0x10 & 0xff,param_2);
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall TTrack::pause(bool,
                                      bool) */

int __thiscall TTrack::pause(TTrack *this)

{
  uint uVar1;
  TChannel *pTVar2;
  ulong uVar3;
  TTrack in_r4;
  char in_r5;
  TTrack *this_00;
  byte bVar6;
  int iVar4;
  int iVar5;
  int iVar7;
  
  this[0x385] = in_r4;
  if (in_r4 == (TTrack)0x0) {
    *(uint *)(this + 0x370) = *(uint *)(this + 0x370) | 1;
    iVar4 = 0;
    do {
      pTVar2 = (TChannel *)TNoteMgr::getChannel((TNoteMgr *)(this + 0xb4),iVar4);
      if (pTVar2 != (TChannel *)0x0) {
        TChannel::setPauseFlag(pTVar2,'\0');
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
  }
  else {
    if (((byte)this[0x37c] & 1) != 0) {
      *(uint *)(this + 0x370) = *(uint *)(this + 0x370) | 1;
    }
    if (((byte)this[0x37c] & 4) != 0) {
      for (bVar6 = 0; bVar6 < 8; bVar6 = bVar6 + 1) {
        noteOff(this,bVar6,10);
      }
    }
    if (((byte)this[0x37c] & 8) != 0) {
      iVar4 = 0;
      do {
        pTVar2 = (TChannel *)TNoteMgr::getChannel((TNoteMgr *)(this + 0xb4),iVar4);
        if (pTVar2 != (TChannel *)0x0) {
          TChannel::setPauseFlag(pTVar2,'\x01');
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 8);
    }
  }
  uVar1 = countLeadingZeros((uint)(byte)in_r4);
  iVar4 = TIntrMgr::request((TIntrMgr *)(this + 0x88),uVar1 >> 5);
  if (in_r5 != '\0') {
    iVar5 = 0;
    iVar7 = 0;
    do {
      this_00 = *(TTrack **)(this + iVar7 + 800);
      if ((this_00 != (TTrack *)0x0) && (this_00[0x37e] != (TTrack)0x0)) {
        if (this != *(TTrack **)(this_00 + 0x31c)) {
          uVar3 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar3,"JASTrack.cpp",0x83d,"this == child->mParent");
          m_Do_printf::OSPanic("JASTrack.cpp",0x83d,"Halt");
        }
        iVar4 = pause(this_00);
      }
      iVar5 = iVar5 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar5 < 0x10);
  }
  return iVar4;
}


/* __thiscall TTrack::getTranspose(void) const */

int __thiscall TTrack::getTranspose(TTrack *this)

{
  int iVar1;
  
  if (*(TTrack **)(this + 0x31c) == (TTrack *)0x0) {
    iVar1 = (int)(char)this[0x37a];
  }
  else {
    iVar1 = getTranspose(*(TTrack **)(this + 0x31c));
    iVar1 = (char)this[0x37a] + iVar1;
  }
  return iVar1;
}


/* __thiscall TTrack::setTempo(unsigned short) */

void __thiscall TTrack::setTempo(TTrack *this,ushort param_1)

{
  *(ushort *)(this + 0x376) = param_1;
  if (*(int *)(this + 0x31c) == 0) {
    updateTempo(this);
  }
  else {
    this[0x388] = (TTrack)0x1;
  }
  return;
}


/* __thiscall TTrack::setTimebase(unsigned short) */

void __thiscall TTrack::setTimebase(TTrack *this,ushort param_1)

{
  *(ushort *)(this + 0x378) = param_1;
  if (*(int *)(this + 0x31c) == 0) {
    updateTempo(this);
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x80283c80) */
/* __thiscall TTrack::rootCallback(void *) */

undefined4 __thiscall TTrack::rootCallback(TTrack *this,void *param_1)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (this == (TTrack *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    if (this[0x37e] == (TTrack)0x0) {
      uVar1 = 0xffffffff;
    }
    else {
      if (this[0x37e] == (TTrack)0x3) {
        stopSeqMain(this);
        uVar1 = 0xffffffff;
      }
      else {
        *(float *)(this + 0x364) = *(float *)(this + 0x364) + *(float *)(this + 0x368);
        dVar4 = (double)JAudio::_737;
        if (dVar4 <= (double)*(float *)(this + 0x364)) {
          do {
            if ((double)*(float *)(this + 0x364) < dVar4) goto LAB_80283c7c;
            *(float *)(this + 0x364) = (float)((double)*(float *)(this + 0x364) - dVar4);
            cVar2 = mainProc(this);
          } while (cVar2 != -1);
          stopSeqMain(this);
          uVar1 = 0xffffffff;
        }
        else {
          updateSeq(this,0,true);
LAB_80283c7c:
          uVar1 = 0;
        }
      }
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return uVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TTrack::registerSeqCallback(unsigned short *(TTrack *,unsigned
   short)) */

void __thiscall TTrack::registerSeqCallback(TTrack *this,FuncDef575 *param_1)

{
  if (_sCallBackFunc != (TTrack *)0x0) {
    m_Do_printf::OSReport("in Player ... overwrite callback\n");
  }
  _sCallBackFunc = this;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TTrack::newMemPool(int) */

void __thiscall TTrack::newMemPool(TTrack *this,int param_1)

{
  int **this_00;
  ulong uVar1;
  TOuterParam *pTVar2;
  int *piVar3;
  int iVar4;
  
  this_00 = (int **)JKernel::operator_new__(0x38c,JAudio::JASDram,0);
  if (this_00 == (int **)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASTrack.cpp",0x8aa,"runner");
    m_Do_printf::OSPanic("JASTrack.cpp",0x8aa,"Halt");
  }
  pTVar2 = (TOuterParam *)JKernel::operator_new(0x2c,JAudio::JASDram,0);
  if (pTVar2 != (TOuterParam *)0x0) {
    TOuterParam::TOuterParam(pTVar2);
  }
  if (pTVar2 == (TOuterParam *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASTrack.cpp",0x8ac,"outer");
    m_Do_printf::OSPanic("JASTrack.cpp",0x8ac,"Halt");
  }
  assignExtBuffer((TTrack *)this_00,pTVar2);
  _sFreeList = this_00;
  for (iVar4 = 1; iVar4 < (int)this; iVar4 = iVar4 + 1) {
    piVar3 = (int *)JKernel::operator_new__(0x38c,JAudio::JASDram,0);
    *this_00 = piVar3;
    if (*this_00 == (int *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"JASTrack.cpp",0x8b4,"runner->next");
      m_Do_printf::OSPanic("JASTrack.cpp",0x8b4,"Halt");
    }
    pTVar2 = (TOuterParam *)JKernel::operator_new(0x2c,JAudio::JASDram,0);
    if (pTVar2 != (TOuterParam *)0x0) {
      TOuterParam::TOuterParam(pTVar2);
    }
    if (pTVar2 == (TOuterParam *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"JASTrack.cpp",0x8b6,"outer");
      m_Do_printf::OSPanic("JASTrack.cpp",0x8b6,"Halt");
    }
    assignExtBuffer((TTrack *)*this_00,pTVar2);
    this_00 = (int **)*this_00;
  }
  *this_00 = (int *)0x0;
  return;
}


/* __thiscall TVibrate::TVibrate(void) */

void __thiscall TVibrate::TVibrate(TVibrate *this)

{
  EVP_PKEY_CTX *in_r4;
  
  init(this,in_r4);
  return;
}


/* __thiscall TVibrate::init(void) */

int __thiscall TVibrate::init(TVibrate *this,EVP_PKEY_CTX *ctx)

{
  float fVar1;
  
  *(float *)(this + 8) = JAudio::_1953;
  fVar1 = JAudio::_680;
  *(float *)(this + 4) = JAudio::_680;
  *(float *)this = fVar1;
  return (int)this;
}


/* __thiscall TVibrate::incCounter(void) */

void __thiscall TVibrate::incCounter(TVibrate *this)

{
  *(float *)this = *(float *)this + *(float *)(this + 8);
  if ((double)*(float *)this < JAudio::_1960) {
    return;
  }
  *(float *)this = (float)((double)*(float *)this - (double)JAudio::_1961);
  return;
}


/* __thiscall TVibrate::getValue(void) const */

double __thiscall TVibrate::getValue(TVibrate *this)

{
  bool bVar1;
  Player *this_00;
  double dVar2;
  double extraout_f1;
  
  if (JAudio::_680 == *(float *)(this + 4)) {
    dVar2 = (double)JAudio::_737;
  }
  else {
    dVar2 = (double)*(float *)this;
    bVar1 = false;
    if (JAudio::_1980 <= dVar2) {
      bVar1 = true;
      if (JAudio::_1983 <= dVar2) {
        dVar2 = (double)(float)((double)JAudio::_1961 - dVar2);
      }
      else {
        dVar2 = (double)(float)(dVar2 - (double)JAudio::_1982);
      }
    }
    else {
      if (JAudio::_1981 <= dVar2) {
        dVar2 = (double)(float)((double)JAudio::_1982 - dVar2);
      }
    }
    this_00 = (Player *)Calc::sinfT((Calc *)this,(float)dVar2);
    dVar2 = extraout_f1;
    if (bVar1) {
      dVar2 = -extraout_f1;
    }
    dVar2 = (double)Player::pitchToCent(this_00,(float)(dVar2 * (double)*(float *)(this + 4)),
                                        JAudio::_1984);
  }
  return dVar2;
}


namespace TTrack {

/* __thiscall MoveParam_::MoveParam_(void) */

void __thiscall MoveParam_::MoveParam_(MoveParam_ *this)

{
  float fVar1;
  
  fVar1 = JAudio::_680;
  *(float *)this = JAudio::_680;
  *(float *)(this + 4) = fVar1;
  *(float *)(this + 8) = fVar1;
  *(float *)(this + 0xc) = fVar1;
  return;
}


/* __thiscall AInnerParam_::AInnerParam_(void) */

void __thiscall AInnerParam_::AInnerParam_(AInnerParam_ *this)

{
  float fVar1;
  
  fVar1 = JAudio::_680;
  *(float *)this = JAudio::_680;
  *(float *)(this + 4) = fVar1;
  *(float *)(this + 8) = fVar1;
  *(float *)(this + 0xc) = fVar1;
  *(float *)(this + 0x10) = fVar1;
  *(float *)(this + 0x14) = fVar1;
  *(float *)(this + 0x18) = fVar1;
  *(float *)(this + 0x1c) = fVar1;
  *(float *)(this + 0x20) = fVar1;
  *(float *)(this + 0x24) = fVar1;
  *(float *)(this + 0x28) = fVar1;
  *(float *)(this + 0x2c) = fVar1;
  *(float *)(this + 0x30) = fVar1;
  *(float *)(this + 0x34) = fVar1;
  *(float *)(this + 0x38) = fVar1;
  *(float *)(this + 0x3c) = fVar1;
  *(float *)(this + 0x40) = fVar1;
  *(float *)(this + 0x44) = fVar1;
  *(float *)(this + 0x48) = fVar1;
  *(float *)(this + 0x4c) = fVar1;
  *(float *)(this + 0x50) = fVar1;
  *(float *)(this + 0x54) = fVar1;
  *(float *)(this + 0x58) = fVar1;
  *(float *)(this + 0x5c) = fVar1;
  *(float *)(this + 0x60) = fVar1;
  *(float *)(this + 100) = fVar1;
  *(float *)(this + 0x68) = fVar1;
  *(float *)(this + 0x6c) = fVar1;
  *(float *)(this + 0x70) = fVar1;
  *(float *)(this + 0x74) = fVar1;
  *(float *)(this + 0x78) = fVar1;
  *(float *)(this + 0x7c) = fVar1;
  *(float *)(this + 0x80) = fVar1;
  *(float *)(this + 0x84) = fVar1;
  *(float *)(this + 0x88) = fVar1;
  *(float *)(this + 0x8c) = fVar1;
  *(float *)(this + 0x90) = fVar1;
  *(float *)(this + 0x94) = fVar1;
  *(float *)(this + 0x98) = fVar1;
  *(float *)(this + 0x9c) = fVar1;
  *(float *)(this + 0xa0) = fVar1;
  *(float *)(this + 0xa4) = fVar1;
  *(float *)(this + 0xa8) = fVar1;
  *(float *)(this + 0xac) = fVar1;
  *(float *)(this + 0xb0) = fVar1;
  *(float *)(this + 0xb4) = fVar1;
  *(float *)(this + 0xb8) = fVar1;
  *(float *)(this + 0xbc) = fVar1;
  Runtime.PPCEABI.H::__construct_array(this + 0xc0,MoveParam_::MoveParam_,(undefined *)0x0,0x10,4);
  fVar1 = JAudio::_680;
  *(float *)(this + 0x100) = JAudio::_680;
  *(float *)(this + 0x104) = fVar1;
  *(float *)(this + 0x108) = fVar1;
  *(float *)(this + 0x10c) = fVar1;
  *(float *)(this + 0x110) = fVar1;
  *(float *)(this + 0x114) = fVar1;
  *(float *)(this + 0x118) = fVar1;
  *(float *)(this + 0x11c) = fVar1;
  return;
}

