#include <d_event.h>
#include <d_event.h>
#include <d_com_inf_game.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <d_event_manager.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <f_op_actor_mng.h>
#include <d_a_itembase_static.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_vibration.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <dEvt_control_c.h>
#include <dEvt_info_c.h>
#include <dEvt_order_c.h>


/* __thiscall dEvt_control_c::dEvt_control_c(void) */

void __thiscall dEvt_control_c::dEvt_control_c(dEvt_control_c *this)

{
  Runtime.PPCEABI.H::__construct_array
            (this,dEvt_order_c::dEvt_order_c,dEvt_order_c::_dEvt_order_c,0x18,8);
  remove(this);
  return;
}


/* __thiscall dEvt_order_c::dEvt_order_c(void) */

void __thiscall dEvt_order_c::dEvt_order_c(dEvt_order_c *this)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dEvt_control_c::orderOld(unsigned short,
                                       unsigned short,
                                       unsigned short,
                                       unsigned short,
                                       void *,
                                       void *,
                                       void const *) */

void __thiscall
dEvt_control_c::orderOld
          (dEvt_control_c *this,dEvt__EventType eventType,ushort priority,dEvt__OrderFlag flag,
          ushort param_4,fopAc_ac_c *pActor1,fopAc_ac_c *pActor2,char *pEventName)

{
  short eventId;
  
  eventId = dEvent_manager_c::getEventIdx
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,pEventName,0xff);
  order(this,eventType,priority,flag,param_4,pActor1,pActor2,eventId,0xff);
  return;
}


/* __thiscall dEvt_control_c::order(unsigned short,
                                    unsigned short,
                                    unsigned short,
                                    unsigned short,
                                    void *,
                                    void *,
                                    short,
                                    unsigned char) */

undefined4 __thiscall
dEvt_control_c::order
          (dEvt_control_c *this,dEvt__EventType eventType,ushort priority,dEvt__OrderFlag flag,
          ushort param_4,fopAc_ac_c *pActor1,fopAc_ac_c *pActor2,short eventId,byte eventInfoIdx)

{
  byte bVar1;
  undefined4 uVar2;
  ulong uVar3;
  dEvt_order_c *pOrder2;
  dEvt_order_c *pOrder;
  
  if ((char)this->mOrderCount < 8) {
    pOrder = this->mOrder + (char)this->mOrderCount;
    pOrder->mEventType = eventType;
    pOrder->mPriority = priority;
    pOrder->mFlag = flag;
    pOrder->mpActor1 = pActor1;
    pOrder->mpActor2 = pActor2;
    pOrder->mEventId = eventId;
    pOrder->field_0x4 = param_4;
    pOrder->mEventInfoIdx = eventInfoIdx;
    if (pOrder->mPriority == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_event.cpp",0x93,"0");
      m_Do_printf::OSPanic("d_event.cpp",0x93,&DAT_8035257e);
    }
    if (this->mOrderCount == 0) {
      this->mFirstOrderIdx = 0;
      pOrder->mNextOrderIdx = 0xff;
    }
    else {
      bVar1 = this->mFirstOrderIdx;
      pOrder2 = this->mOrder + (char)bVar1;
      if ((ushort)pOrder->mPriority < (ushort)pOrder2->mPriority) {
        this->mFirstOrderIdx = this->mOrderCount;
        pOrder->mNextOrderIdx = bVar1;
      }
      else {
        while (bVar1 = pOrder2->mNextOrderIdx, -1 < (char)bVar1) {
          if ((ushort)pOrder->mPriority < (ushort)this->mOrder[(char)bVar1].mPriority) break;
          pOrder2 = this->mOrder + (char)bVar1;
        }
        pOrder->mNextOrderIdx = bVar1;
        pOrder2->mNextOrderIdx = this->mOrderCount;
      }
    }
    this->mOrderCount = this->mOrderCount + 1;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dEvt_control_c::setParam(dEvt_order_c *) */

void __thiscall dEvt_control_c::setParam(dEvt_control_c *this,dEvt_order_c *pOrder)

{
  dStage_EventInfo_c *pEventInfo;
  uint uVar1;
  int iVar2;
  
  pEventInfo = (dStage_EventInfo_c *)
               (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getEventInfo)
                         ();
  uVar1 = getPId(this,pOrder->mpActor1);
  this->mPt1 = uVar1;
  uVar1 = getPId(this,pOrder->mpActor2);
  this->mPt2 = uVar1;
  this->mEventId = pOrder->mEventId;
  this->field_0xd6 = pOrder->field_0x4;
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor == (daPy_lk_c *)pOrder->mpActor1) {
    iVar2 = getPId(this,pOrder->mpActor2);
    this->mPtTalk = iVar2;
    iVar2 = getPId(this,pOrder->mpActor2);
    this->mPtItem = iVar2;
  }
  else {
    iVar2 = getPId(this,(fopAc_ac_c *)(daPy_lk_c *)pOrder->mpActor1);
    this->mPtTalk = iVar2;
    iVar2 = getPId(this,pOrder->mpActor1);
    this->mPtItem = iVar2;
  }
  this->field_0xdf = pOrder->mEventInfoIdx;
  uVar1 = (uint)pOrder->mEventInfoIdx;
  if (((uVar1 == 0xff) || (pEventInfo == (dStage_EventInfo_c *)0x0)) ||
     (pEventInfo->mCount <= (int)uVar1)) {
    this->field_0xde = 0xff;
  }
  else {
    this->field_0xde = pEventInfo->mpEvents[uVar1].field_0x10;
  }
  this->mCullFarClipRatio = d_event::1_0;
  this->mStateFlags = 0;
  return;
}


/* __thiscall dEvt_control_c::beforeFlagProc(dEvt_order_c *) */

undefined4 __thiscall dEvt_control_c::beforeFlagProc(dEvt_control_c *this,dEvt_order_c *pOrder)

{
  if (((pOrder->mFlag & RequiresActiveActor2) != None) &&
     (((pOrder->mpActor2->mEvtInfo).mCondition & CanTalk) != CanTalk)) {
    return 0;
  }
  return 1;
}


/* __thiscall dEvt_control_c::afterFlagProc(dEvt_order_c *) */

void __thiscall dEvt_control_c::afterFlagProc(dEvt_control_c *this,dEvt_order_c *pOrder)

{
  uint uVar1;
  
  if ((pOrder->mFlag & RequiresPartnerPcId) != None) {
    uVar1 = getPId(this,(fopAc_ac_c *)0x0);
    this->mPt2 = uVar1;
  }
  if ((pOrder->mFlag & IssueStaffAll) != None) {
    dEvent_manager_c::issueStaff(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"ALL");
  }
  if ((pOrder->mFlag & UnkFlagSet) != None) {
    this->mStateFlags = this->mStateFlags | 0x20;
  }
  return;
}


/* __thiscall dEvt_control_c::commonCheck(dEvt_order_c *,
                                          unsigned short,
                                          unsigned short) */

undefined4 __thiscall
dEvt_control_c::commonCheck
          (dEvt_control_c *this,dEvt_order_c *pOrder,dEvt__ActorCondition checkOrderFlag,
          dEvt__ActorCommand setActorMode)

{
  uint uVar1;
  fopAc_ac_c *pActor1;
  fopAc_ac_c *pActor2;
  
  pActor1 = pOrder->mpActor1;
  pActor2 = pOrder->mpActor2;
  if (pActor1 != (fopAc_ac_c *)0x0) {
    uVar1 = countLeadingZeros((uint)(checkOrderFlag & (pActor1->mEvtInfo).mCondition) -
                              (uint)checkOrderFlag);
    if ((((uVar1 >> 5 & 0xff) != 0) && (pActor2 != (fopAc_ac_c *)0x0)) &&
       ((uint)checkOrderFlag == (uint)(checkOrderFlag & (pActor2->mEvtInfo).mCondition))) {
      (pActor1->mEvtInfo).mCommand = setActorMode;
      (pActor2->mEvtInfo).mCommand = setActorMode;
      setParam(this,pOrder);
      return 1;
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dEvt_control_c::talkCheck(dEvt_order_c *) */

undefined4 __thiscall dEvt_control_c::talkCheck(dEvt_control_c *this,dEvt_order_c *pOrder)

{
  int iVar1;
  short sVar4;
  ulong uVar2;
  undefined4 uVar3;
  fopAc_ac_c *pActor2;
  
  pActor2 = pOrder->mpActor2;
  iVar1 = commonCheck(this,pOrder,CanTalk,InTalk);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    this->mMode = 1;
    if (this->mEventId == -1) {
      if ((pActor2 == (fopAc_ac_c *)0x0) ||
         (iVar1 = dEvt_info_c::getEventName(&pActor2->mEvtInfo), iVar1 == 0)) {
        sVar4 = dEvent_manager_c::getEventIdx
                          (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"DEFAULT_TALK",0xff);
        this->mEventId = sVar4;
      }
      else {
        this->mEventId = (pActor2->mEvtInfo).mEventId;
      }
    }
    iVar1 = dEvent_manager_c::order
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEventId);
    if (iVar1 == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_event.cpp",0x145,"0");
      m_Do_printf::OSPanic("d_event.cpp",0x145,&DAT_8035257e);
    }
    uVar3 = 1;
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dEvt_control_c::talkXyCheck(dEvt_order_c *) */

undefined4 __thiscall dEvt_control_c::talkXyCheck(dEvt_control_c *this,dEvt_order_c *pOrder)

{
  dEvt__EventType dVar1;
  int iVar2;
  short sVar4;
  ulong uVar3;
  code *pcVar5;
  int button;
  fopAc_ac_c *pActor2;
  
  pActor2 = pOrder->mpActor2;
  dVar1 = pOrder->mEventType;
  if (dVar1 == Talk_YBtn) {
    button = 1;
  }
  else {
    if ((dVar1 < Talk_YBtn) && (Item < dVar1)) {
      button = 0;
    }
    else {
      button = 2;
    }
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[button] == InvalidItem) {
    return 0;
  }
  if ((pActor2 == (fopAc_ac_c *)0x0) ||
     (((pActor2->mEvtInfo).mCondition & CanTalkItem) != CanTalkItem)) {
    return 0;
  }
  iVar2 = commonCheck(this,pOrder,CanTalk,InTalk);
  if (iVar2 == 0) {
    return 0;
  }
  this->mMode = 1;
  this->mItemNo = d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[button];
  dVar1 = pOrder->mEventType;
  if (dVar1 == Talk_YBtn) {
    this->mTalkButton = 2;
  }
  else {
    if ((dVar1 < Talk_YBtn) && (Item < dVar1)) {
      this->mTalkButton = 1;
    }
    else {
      this->mTalkButton = 3;
    }
  }
  if (pActor2 != (fopAc_ac_c *)0x0) {
    pcVar5 = (code *)(pActor2->mEvtInfo).mpEventCB;
    if (pcVar5 == (code *)0x0) {
      sVar4 = -1;
    }
    else {
      sVar4 = (*pcVar5)(pActor2,button);
    }
    if (sVar4 != -1) {
      this->mEventId = sVar4;
      goto LAB_800704ec;
    }
  }
  sVar4 = dEvent_manager_c::getEventIdx
                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"DEFAULT_TALK_XY",0xff);
  this->mEventId = sVar4;
LAB_800704ec:
  button = dEvent_manager_c::order
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEventId);
  if (button == 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_event.cpp",0x191,"0");
    m_Do_printf::OSPanic("d_event.cpp",0x191,&DAT_8035257e);
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dEvt_control_c::photoCheck(dEvt_order_c *) */

undefined4 __thiscall dEvt_control_c::photoCheck(dEvt_control_c *this,dEvt_order_c *param_1)

{
  ulong uVar1;
  int iVar2;
  undefined4 uVar3;
  short sVar4;
  code *pcVar5;
  fopAc_ac_c *pActor2;
  
  pActor2 = param_1->mpActor2;
  this->mbInPhoto = 0;
  if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe == 1) {
    if (pActor2 == (fopAc_ac_c *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_event.cpp",0x1a5,"actor2");
      m_Do_printf::OSPanic("d_event.cpp",0x1a5,&DAT_8035257e);
    }
    iVar2 = commonCheck(this,param_1,CanTalk,InTalk);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      pcVar5 = (code *)(pActor2->mEvtInfo).mpPhotoCB;
      if (pcVar5 == (code *)0x0) {
        sVar4 = -1;
      }
      else {
        sVar4 = (*pcVar5)(pActor2,0);
      }
      if (sVar4 == -1) {
        sVar4 = dEvent_manager_c::getEventIdx
                          (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"DEFAULT_TALK",0xff);
        this->mEventId = sVar4;
      }
      else {
        this->mEventId = sVar4;
      }
      iVar2 = dEvent_manager_c::order
                        (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEventId);
      if (iVar2 == 0) {
        uVar1 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar1,"d_event.cpp",0x1b5,"0");
        m_Do_printf::OSPanic("d_event.cpp",0x1b5,&DAT_8035257e);
      }
      this->mbInPhoto = 1;
      this->mMode = 1;
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


/* __thiscall dEvt_control_c::catchCheck(dEvt_order_c *) */

undefined4 __thiscall dEvt_control_c::catchCheck(dEvt_control_c *this,dEvt_order_c *param_1)

{
  fopAc_ac_c *pfVar1;
  undefined4 uVar2;
  int iVar3;
  ulong uVar4;
  
  pfVar1 = param_1->mpActor2;
  if ((param_1->mpActor1 == (fopAc_ac_c *)0x0) ||
     ((pfVar1 != (fopAc_ac_c *)0x0 && (((pfVar1->mEvtInfo).mCondition & 0x40) != 0x40)))) {
    uVar2 = 0;
  }
  else {
    (param_1->mpActor1->mEvtInfo).mCommand = 6;
    if (pfVar1 != (fopAc_ac_c *)0x0) {
      (pfVar1->mEvtInfo).mCommand = 6;
    }
    setParam(this,param_1);
    this->mItemNo = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.mCatch.field_0x14;
    this->mMode = 2;
    if ((this->mEventId != -1) &&
       (iVar3 = dEvent_manager_c::order
                          (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEventId),
       iVar3 == 0)) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_event.cpp",0x1e3,"0");
      m_Do_printf::OSPanic("d_event.cpp",0x1e3,&DAT_8035257e);
    }
    this->mStateFlags = this->mStateFlags | 0x80;
    uVar2 = 1;
  }
  return uVar2;
}


/* __thiscall dEvt_control_c::talkEnd(void) */

undefined4 __thiscall dEvt_control_c::talkEnd(dEvt_control_c *this)

{
  short sVar1;
  fopAc_ac_c *pfVar2;
  daItemBase_c *pItem;
  
  pfVar2 = convPId(this,this->mPt1);
  if (pfVar2 != (fopAc_ac_c *)0x0) {
    (pfVar2->mEvtInfo).mCommand = None;
  }
  pfVar2 = convPId(this,this->mPt2);
  if (pfVar2 != (fopAc_ac_c *)0x0) {
    (pfVar2->mEvtInfo).mCommand = None;
  }
  if (this->mEventId != -1) {
    dEvent_manager_c::endProc(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEventId,1);
    this->mEventId = -1;
  }
  pItem = (daItemBase_c *)f_op_actor_mng::fopAcM_getItemEventPartner(0);
  if ((pItem != (daItemBase_c *)0x0) &&
     ((sVar1 = (pItem->parent).parent.parent.mProcName, sVar1 == 0x101 || (sVar1 == 0x103)))) {
    daItemBase_c::dead(pItem);
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dEvt_control_c::demoCheck(dEvt_order_c *) */

undefined4 __thiscall dEvt_control_c::demoCheck(dEvt_control_c *this,dEvt_order_c *pOrder)

{
  ulong uVar1;
  undefined4 uVar2;
  int iVar3;
  byte bVar4;
  fopAc_ac_c *pActor2;
  fopAc_ac_c *pActor1;
  short eventId;
  
  pActor1 = pOrder->mpActor1;
  pActor2 = pOrder->mpActor2;
  eventId = pOrder->mEventId;
  if (pActor2 == (fopAc_ac_c *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_event.cpp",0x21f,"0");
    m_Do_printf::OSPanic("d_event.cpp",0x21f,&DAT_8035257e);
    uVar2 = 0;
  }
  else {
    iVar3 = beforeFlagProc(this,pOrder);
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      iVar3 = dEvent_manager_c::order(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,eventId);
      if (iVar3 == 0) {
        uVar2 = 0;
      }
      else {
        if (pActor1 != (fopAc_ac_c *)0x0) {
          (pActor1->mEvtInfo).mCommand = InDemo;
        }
        if (pActor2 != (fopAc_ac_c *)0x0) {
          (pActor2->mEvtInfo).mCommand = InDemo;
        }
        this->mMode = 2;
        setParam(this,pOrder);
        afterFlagProc(this,pOrder);
        bVar4 = dEvent_manager_c::getEventEndSound
                          (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,eventId);
        if ((bVar4 != 0) && (this->mEventEndSound == 0)) {
          this->mEventEndSound = bVar4;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x806,(cXyz *)0x0,0,0,d_event::1_0,d_event::1_0,
                     d_event::_4253,d_event::_4253,0);
        }
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}


/* __thiscall dEvt_control_c::demoEnd(void) */

undefined4 __thiscall dEvt_control_c::demoEnd(dEvt_control_c *this)

{
  fopAc_ac_c *pActor;
  
  pActor = convPId(this,this->mPt1);
  if (pActor != (fopAc_ac_c *)0x0) {
    (pActor->mEvtInfo).mCommand = None;
  }
  pActor = convPId(this,this->mPt2);
  if (pActor != (fopAc_ac_c *)0x0) {
    (pActor->mEvtInfo).mCommand = None;
  }
  if (this->mEventId != -1) {
    dEvent_manager_c::endProc(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEventId,1);
    this->mEventId = -1;
  }
  dEvent_manager_c::cancelStaff(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"ALL");
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dEvt_control_c::potentialCheck(dEvt_order_c *) */

bool __thiscall dEvt_control_c::potentialCheck(dEvt_control_c *this,dEvt_order_c *pOrder)

{
  ulong uVar1;
  int iVar2;
  fopAc_ac_c *pfVar3;
  
  pfVar3 = pOrder->mpActor1;
  if ((pfVar3 == (fopAc_ac_c *)0x0) || (pOrder->mpActor2 == (fopAc_ac_c *)0x0)) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_event.cpp",0x280,"0");
    m_Do_printf::OSPanic("d_event.cpp",0x280,&DAT_8035257e);
  }
  iVar2 = beforeFlagProc(this,pOrder);
  if (iVar2 != 0) {
    (pfVar3->mEvtInfo).mCommand = InDemo;
    this->mMode = 2;
    setParam(this,pOrder);
    afterFlagProc(this,pOrder);
  }
  return iVar2 != 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dEvt_control_c::doorCheck(dEvt_order_c *) */

undefined4 __thiscall dEvt_control_c::doorCheck(dEvt_control_c *this,dEvt_order_c *pOrder)

{
  short sVar1;
  int iVar2;
  fopAc_ac_c *pfVar3;
  dEvDtEvent_c *pdVar4;
  ulong uVar5;
  undefined4 uVar6;
  
  iVar2 = commonCheck(this,pOrder,CanDoor,InDoor);
  if (iVar2 == 0) {
    uVar6 = 0;
  }
  else {
    this->mMode = 2;
    pfVar3 = convPId(this,this->mPt2);
    if (((this->mEventId == -1) && (pfVar3 != (fopAc_ac_c *)0x0)) &&
       (sVar1 = (pfVar3->mEvtInfo).mEventId, sVar1 != -1)) {
      this->mEventId = sVar1;
    }
    if ((this->mEventId == -1) ||
       (pdVar4 = dEvent_manager_c::getEventData
                           (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEventId),
       pdVar4 == (dEvDtEvent_c *)0x0)) {
      this->mEventId = -1;
      this->mStateFlags = this->mStateFlags | 8;
    }
    else {
      iVar2 = dEvent_manager_c::order
                        (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEventId);
      if (iVar2 == 0) {
        uVar5 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar5,"d_event.cpp",0x2c0,"0");
        m_Do_printf::OSPanic("d_event.cpp",0x2c0,&DAT_8035257e);
      }
    }
    if (pOrder->mEventType == Treasure) {
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags =
           d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags | 4;
    }
    uVar6 = 1;
  }
  return uVar6;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dEvt_control_c::itemCheck(dEvt_order_c *) */

undefined4 __thiscall dEvt_control_c::itemCheck(dEvt_control_c *this,dEvt_order_c *pOrder)

{
  int iVar1;
  short sVar4;
  ulong uVar2;
  undefined4 uVar3;
  
  iVar1 = commonCheck(this,pOrder,CanGetItem,InGetItem);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    this->mMode = 2;
    sVar4 = dEvent_manager_c::getEventIdx
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"DEFAULT_GETITEM",0xff);
    this->mEventId = sVar4;
    iVar1 = dEvent_manager_c::order
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEventId);
    if (iVar1 == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_event.cpp",0x2ea,"0");
      m_Do_printf::OSPanic("d_event.cpp",0x2ea,&DAT_8035257e);
    }
    uVar3 = 1;
  }
  return uVar3;
}


/* __thiscall dEvt_control_c::endProc(void) */

undefined4 __thiscall dEvt_control_c::endProc(dEvt_control_c *this)

{
  byte bVar1;
  ulong uVar2;
  
  bVar1 = this->mMode;
  if (bVar1 == 2) {
    demoEnd(this);
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) {
        talkEnd(this);
        goto LAB_80070d98;
      }
    }
    else {
      if (bVar1 < 4) goto LAB_80070d98;
    }
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_event.cpp",0x315,"0");
    m_Do_printf::OSPanic("d_event.cpp",0x315,&DAT_8035257e);
  }
LAB_80070d98:
  this->mMode = 0;
  this->field_0xde = 0xff;
  this->field_0xdf = 0xff;
  this->mTalkButton = 0;
  this->mbInPhoto = 0;
  this->mItemNo = 0xff;
  this->mStateFlags = 0;
  return 1;
}


/* __thiscall dEvt_control_c::checkChange(void) */

undefined4 __thiscall dEvt_control_c::checkChange(dEvt_control_c *this)

{
  int iVar1;
  byte orderIdx;
  
  if (this->mOrderCount != 0) {
    orderIdx = this->mFirstOrderIdx;
    do {
      iVar1 = (int)(char)orderIdx;
      orderIdx = this->mOrder[iVar1].mNextOrderIdx;
      if (this->mOrder[iVar1].mEventType == Change) {
        return 1;
      }
    } while (-1 < (char)orderIdx);
  }
  return 0;
}


/* __thiscall dEvt_control_c::changeProc(void) */

undefined4 __thiscall dEvt_control_c::changeProc(dEvt_control_c *this)

{
  int iVar1;
  dEvt_order_c *pOrder;
  byte nextOrderIdx;
  
  if (this->mOrderCount != 0) {
    this->mOrderCount = 0;
    nextOrderIdx = this->mFirstOrderIdx;
    do {
      pOrder = this->mOrder + (char)nextOrderIdx;
      nextOrderIdx = pOrder->mNextOrderIdx;
      if ((pOrder->mEventType == Change) && (iVar1 = demoCheck(this,pOrder), iVar1 != 0)) {
        return 1;
      }
    } while (-1 < (char)nextOrderIdx);
  }
  return 0;
}


/* __thiscall dEvt_control_c::checkStart(void) */

undefined4 __thiscall dEvt_control_c::checkStart(dEvt_control_c *this)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  dEvt_order_c *pOrder;
  byte orderIdx;
  
  if (this->mOrderCount != 0) {
    orderIdx = this->mFirstOrderIdx;
    this->mOrderCount = 0;
    do {
      pOrder = this->mOrder + (char)orderIdx;
      orderIdx = pOrder->mNextOrderIdx;
      switch(pOrder->mEventType) {
      case Talk:
        iVar2 = talkCheck(this,pOrder);
        if (iVar2 != 0) {
          return 1;
        }
        break;
      case Door:
      case Treasure:
        iVar2 = doorCheck(this,pOrder);
        if (iVar2 != 0) {
          return 1;
        }
        break;
      case Other:
        iVar2 = demoCheck(this,pOrder);
        if (iVar2 != 0) {
          return 1;
        }
        break;
      case Compulsory:
        this->mMode = 3;
        setParam(this,pOrder);
        return 1;
      case Potential:
        uVar1 = potentialCheck(this,pOrder);
        return uVar1;
      case Item:
        uVar1 = itemCheck(this,pOrder);
        return uVar1;
      case Talk_XBtn:
      case Talk_YBtn:
      case Talk_ZBtn:
        iVar2 = talkXyCheck(this,pOrder);
        if (iVar2 != 0) {
          return 1;
        }
        break;
      case Catch:
        iVar2 = catchCheck(this,pOrder);
        if (iVar2 != 0) {
          return 1;
        }
        break;
      case Photo:
        iVar2 = photoCheck(this,pOrder);
        if (iVar2 != 0) {
          return 1;
        }
        break;
      case Change:
        break;
      default:
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_event.cpp",0x39c,"0");
        m_Do_printf::OSPanic("d_event.cpp",0x39c,&DAT_8035257e);
      }
    } while (-1 < (char)orderIdx);
  }
  return 0;
}


/* __thiscall dEvt_control_c::soundProc(void) */

undefined4 __thiscall dEvt_control_c::soundProc(dEvt_control_c *this)

{
  if ((this->mEventEndSound != 0) && (this->mMode != 2)) {
    this->mEventEndSound = 0;
  }
  return 1;
}


/* __thiscall dEvt_control_c::check(void) */

undefined4 __thiscall dEvt_control_c::check(dEvt_control_c *this)

{
  int iVar1;
  
  this->field_0xdb = 0;
  this->field_0xdc = this->mOrderCount;
  if ((this->mStateFlags & 8U) != 0) {
    this->mbEndProc = 1;
    this->mStateFlags = this->mStateFlags & 0xfff7;
  }
  if ((this->mMode != 0) && (this->mbEndProc == 1)) {
    this->mbEndProc = 0;
    endProc(this);
  }
  iVar1 = checkChange(this);
  if (iVar1 != 0) {
    if (this->mMode != 0) {
      this->mbEndProc = 0;
      endProc(this);
    }
    changeProc(this);
  }
  if ((this->mMode == 0) && (iVar1 = checkStart(this), iVar1 != 0)) {
    dVibration_c::StopQuake(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,-1);
  }
  soundProc(this);
  this->mOrderCount = 0;
  return 0;
}


/* __thiscall dEvt_control_c::photoCheck(void) */

undefined4 __thiscall dEvt_control_c::photoCheck(dEvt_control_c *this)

{
  dEvt__EventType dVar1;
  int iVar2;
  fopAc_ac_c *pfVar3;
  dEvt_order_c *pdVar4;
  
  if (this->mOrderCount != 0) {
    pdVar4 = this->mOrder + (char)this->mFirstOrderIdx;
    iVar2 = -1;
    dVar1 = pdVar4->mEventType;
    if (dVar1 == Talk_YBtn) {
      iVar2 = 1;
    }
    else {
      if (dVar1 < Talk_YBtn) {
        if (Item < dVar1) {
          iVar2 = 0;
        }
      }
      else {
        if (dVar1 < Catch) {
          iVar2 = 2;
        }
      }
    }
    if ((iVar2 != -1) &&
       (((d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar2] == PictoBox ||
         (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar2] == DeluxePictoBox)) &&
        (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ != '\0')))) {
      pfVar3 = pdVar4->mpActor2;
      if (pfVar3 == (fopAc_ac_c *)0x0) {
        return 0;
      }
      if ((pfVar3->mAttentionFlags & 0x1000000) == 0) {
        return 0;
      }
      if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe == 2) {
        return 0;
      }
      if (pdVar4->mpActor1 != (fopAc_ac_c *)0x0) {
        if ((((pdVar4->mpActor1->mEvtInfo).mCondition & CanTalk) == CanTalk) &&
           (((pfVar3->mEvtInfo).mCondition & CanTalk) == CanTalk)) {
          pdVar4->mEventType = Photo;
          d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe = 2;
          return 1;
        }
        return 0;
      }
      return 0;
    }
  }
  return 0;
}


/* __thiscall dEvt_control_c::moveApproval(void *) */

dEvt__MoveApprovalFlag __thiscall
dEvt_control_c::moveApproval(dEvt_control_c *this,fopAc_ac_c *pActor)

{
  byte bVar1;
  fopAc_ac_c *pfVar2;
  dEvt__MoveApprovalFlag dVar3;
  fopAcM__Status status;
  
  bVar1 = this->mMode;
  if (bVar1 == 0) {
    return NormalMove;
  }
  if (bVar1 == 2) {
    pfVar2 = convPId(this,this->mPt1);
    if ((pfVar2 == pActor) || (pfVar2 = convPId(this,this->mPt2), pfVar2 == pActor)) {
      return ForceMove;
    }
    if (pActor->mDemoObjId != 0) {
      return ForceMove;
    }
  }
  else {
    if (bVar1 < 2) {
      if ((bVar1 != 0) &&
         ((pfVar2 = convPId(this,this->mPt1), pfVar2 == pActor ||
          (pfVar2 = convPId(this,this->mPt2), pfVar2 == pActor)))) {
        return ForceMove;
      }
    }
    else {
      if ((bVar1 < 4) && (pfVar2 = convPId(this,this->mPt1), pfVar2 == pActor)) {
        return ForceMove;
      }
    }
  }
  status = pActor->mStatus;
  if ((status & 0x8000) == 0) {
    if ((this->mMode == 1) && ((status & 0x40) != 0)) {
      dVar3 = NormalMove;
    }
    else {
      if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mState == 1) {
        dVar3 = NormalMove;
      }
      else {
        if ((status & 0x800) == 0) {
          if (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 3) ||
              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 1)) &&
             ((status & IsBossOrMiniBoss) != 0)) {
            dVar3 = DontMove;
          }
          else {
            if (((this->mStateFlags & 0x80U) == 0) || ((status & IsBossOrMiniBoss) == 0)) {
              if ((status & 0x4000) == 0) {
                dVar3 = (dEvt__MoveApprovalFlag)(status >> 0xd) & NormalMove;
              }
              else {
                dVar3 = NormalMove;
              }
            }
            else {
              dVar3 = DontMove;
            }
          }
        }
        else {
          dVar3 = NormalMove;
        }
      }
    }
  }
  else {
    dVar3 = ForceMove;
  }
  return dVar3;
}


/* __thiscall dEvt_control_c::compulsory(void *,
                                         char const *,
                                         unsigned short) */

undefined4 __thiscall
dEvt_control_c::compulsory(dEvt_control_c *this,fopAc_ac_c *pActor1,char *pEventName,ushort param_3)

{
  undefined4 uVar1;
  
  if (this->mMode == 0) {
    uVar1 = orderOld(this,Compulsory,1,None,param_3,pActor1,(fopAc_ac_c *)0x0,pEventName);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall dEvt_control_c::remove(void) */

int __thiscall dEvt_control_c::remove(dEvt_control_c *this)

{
  this->mMode = 0;
  this->mbEndProc = 0;
  this->mOrderCount = 0;
  *(undefined *)&this->field_0xdd = 0;
  this->mEventEndSound = 0;
  this->field_0xdb = 0;
  this->mCullFarClipRatio = d_event::_4548;
  this->field_0xde = 0xff;
  this->field_0xdf = 0xff;
  this->mTalkButton = 0;
  this->mbInPhoto = 0;
  this->mItemNo = 0xff;
  this->mStateFlags = 0;
  return (int)this;
}


/* __thiscall dEvt_control_c::getStageEventDt(void) */

dStage_Event_dt_c * __thiscall dEvt_control_c::getStageEventDt(dEvt_control_c *this)

{
  dStage_EventInfo_c *pEventInfo;
  dStage_Event_dt_c *pdVar1;
  uint uVar2;
  
  pEventInfo = (dStage_EventInfo_c *)
               (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getEventInfo)
                         ();
  if (this->mMode == 0) {
    pdVar1 = (dStage_Event_dt_c *)0x0;
  }
  else {
    if (((pEventInfo == (dStage_EventInfo_c *)0x0) ||
        (uVar2 = (uint)this->field_0xdf, uVar2 == 0xff)) || (pEventInfo->mCount <= (int)uVar2)) {
      pdVar1 = (dStage_Event_dt_c *)0x0;
    }
    else {
      pdVar1 = pEventInfo->mpEvents + uVar2;
    }
  }
  return pdVar1;
}


/* __thiscall dEvt_control_c::nextStageEventDt(void *) */

dStage_Event_dt_c * __thiscall dEvt_control_c::nextStageEventDt(dEvt_control_c *this,void *param_1)

{
  dStage_EventInfo_c *pEventInfo;
  dStage_Event_dt_c *pdVar1;
  uint uVar2;
  
  pEventInfo = (dStage_EventInfo_c *)
               (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getEventInfo)
                         ();
  if (param_1 == (void *)0x0) {
    pdVar1 = (dStage_Event_dt_c *)0x0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (((pEventInfo == (dStage_EventInfo_c *)0x0) || (uVar2 = (uint)*param_1, uVar2 == 0xff)) ||
       (pEventInfo->mCount <= (int)uVar2)) {
      pdVar1 = (dStage_Event_dt_c *)0x0;
    }
    else {
      pdVar1 = pEventInfo->mpEvents + uVar2;
    }
  }
  return pdVar1;
}


/* __thiscall dEvt_control_c::getPId(void *) */

uint __thiscall dEvt_control_c::getPId(dEvt_control_c *this,fopAc_ac_c *pActor)

{
  if (pActor == (fopAc_ac_c *)0x0) {
    return 0xffffffff;
  }
  if (pActor != (fopAc_ac_c *)0x0) {
    return (pActor->parent).parent.mBsPcId;
  }
  return 0xffffffff;
}


/* __thiscall dEvt_control_c::convPId(unsigned int) */

fopAc_ac_c * __thiscall dEvt_control_c::convPId(dEvt_control_c *this,uint param_1)

{
  fopAc_ac_c *pfVar1;
  uint mPcID;
  
  mPcID = param_1;
  pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&mPcID);
  return pfVar1;
}


/* __thiscall dEvt_control_c::getTactFreeMStick(int) */

byte __thiscall dEvt_control_c::getTactFreeMStick(dEvt_control_c *this,int param_1)

{
  return this->mTactFreeMStick[param_1];
}


/* __thiscall dEvt_control_c::getTactFreeCStick(int) */

byte __thiscall dEvt_control_c::getTactFreeCStick(dEvt_control_c *this,int param_1)

{
  return this->mTactFreeCStick[param_1 + 1];
}


/* __thiscall dEvt_info_c::dEvt_info_c(void) */

void __thiscall dEvt_info_c::dEvt_info_c(dEvt_info_c *this)

{
  this->vtbl = &__vt;
  this->mCommand = None;
  this->mCondition = None;
  this->mEventId = -1;
  this->mMapToolId = -1;
  this->mpEventCB = (undefined *)0x0;
  this->mpCheckCB = (undefined *)0x0;
  return;
}


/* __thiscall dEvt_info_c::setEventName(char *) */

void __thiscall dEvt_info_c::setEventName(dEvt_info_c *this,char *param_1)

{
  short sVar1;
  
  if (param_1 == (char *)0x0) {
    this->mEventId = -1;
  }
  else {
    sVar1 = dEvent_manager_c::getEventIdx
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,param_1,0xff);
    this->mEventId = sVar1;
  }
  return;
}


/* __thiscall dEvt_info_c::getEventName(void) */

dEvDtEvent_c * __thiscall dEvt_info_c::getEventName(dEvt_info_c *this)

{
  dEvDtEvent_c *pEventData;
  
  if (this->mEventId == -1) {
    pEventData = (dEvDtEvent_c *)0x0;
  }
  else {
    pEventData = dEvent_manager_c::getEventData
                           (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEventId);
    if (pEventData == (dEvDtEvent_c *)0x0) {
      pEventData = (dEvDtEvent_c *)0x0;
    }
  }
  return pEventData;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dEvt_control_c::giveItemCut(unsigned char) */

bool __thiscall dEvt_control_c::giveItemCut(dEvt_control_c *this,uchar staffId)

{
  int staffIdx;
  
  staffIdx = dEvent_manager_c::getMyStaffId
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"GIVEMAN",
                        (fopAc_ac_c *)0x0,0);
  if (staffIdx != -1) {
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
    this->mCurStaffId = staffId;
  }
  return staffIdx != -1;
}

