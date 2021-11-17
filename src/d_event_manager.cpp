#include <d_event_manager.h>
#include <d_save.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_event_data.h>
#include <d_event_manager.h>
#include <d_resorce.h>
#include <d_stage.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <f_op_actor_iter.h>
#include <d_event.h>
#include <f_op_actor_mng.h>
#include <SComponent/c_xyz.h>
#include <dEvent_manager_c.h>
#include <dEvent_exception_c.h>
#include <dEv_seach_prm.h>


/* __thiscall dEvent_exception_c::init(void) */

int __thiscall dEvent_exception_c::init(dEvent_exception_c *this)

{
  this->mEventInfoIdx = 0xffffffff;
  this->field_0x4 = 0xffffffff;
  this->mState = 0;
  return (int)this;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dEvent_exception_c::setStartDemo(int) */

int __thiscall dEvent_exception_c::setStartDemo(dEvent_exception_c *this,int eventIdx)

{
  dStage_EventInfo_c *pEventInfo;
  bool bVar1;
  uint switchIndex;
  
  pEventInfo = (dStage_EventInfo_c *)
               (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getEventInfo)
                         ();
  if (eventIdx == 0xff) {
    this->mEventInfoIdx = 0xce;
    eventIdx = 0xff;
  }
  else {
    if (eventIdx < 200) {
      if (pEventInfo == (dStage_EventInfo_c *)0x0) {
        eventIdx = 0xff;
      }
      else {
        if ((eventIdx == -1) || (pEventInfo->mCount < eventIdx)) {
          eventIdx = 0xff;
        }
        else {
          switchIndex = (uint)pEventInfo->mpEvents[eventIdx].field_0x13;
          if (switchIndex != 0xff) {
            bVar1 = dSv_info_c::isSwitch
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,switchIndex,
                               (int)(char)dStage_roomControl_c::mStayNo);
            if (bVar1 != false) {
              this->mEventInfoIdx = 0xce;
              return 0xff;
            }
            dSv_info_c::onSwitch
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,switchIndex,
                       (int)(char)dStage_roomControl_c::mStayNo);
          }
          this->mEventInfoIdx = eventIdx;
        }
      }
    }
    else {
      this->mEventInfoIdx = eventIdx;
    }
  }
  return eventIdx;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dEvent_exception_c::getEventName(void) */

char * __thiscall dEvent_exception_c::getEventName(dEvent_exception_c *this)

{
  dStage_EventInfo_c *pEventInfo;
  stage_stag_info_class *pStag;
  char *pcVar1;
  ulong uVar2;
  int iVar3;
  
  pEventInfo = (dStage_EventInfo_c *)
               (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getEventInfo)
                         (0x803c9d58);
  pStag = (stage_stag_info_class *)
          (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  if (this->mEventInfoIdx == -1) {
    pcVar1 = (char *)0x0;
  }
  else {
    if (this->mEventInfoIdx == 0xcf) {
      if (pStag == (stage_stag_info_class *)0x0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_event_manager.cpp",0x9b,"stage_info");
        m_Do_printf::OSPanic("d_event_manager.cpp",0x9b,&DAT_80352908);
      }
      if ((pStag->mStageTypeAndSchbit >> 0x10 & 7) == 3) {
        return "BS_SHUTTER_START";
      }
    }
    iVar3 = this->mEventInfoIdx;
    if ((iVar3 < 0xc9) || (0xd5 < iVar3)) {
      if (pEventInfo == (dStage_EventInfo_c *)0x0) {
        pcVar1 = (char *)0x0;
      }
      else {
        if (pEventInfo->mCount < iVar3) {
          pcVar1 = (char *)0x0;
        }
        else {
          pcVar1 = pEventInfo->mpEvents[iVar3].mName;
        }
      }
    }
    else {
      pcVar1 = (&PTR_JSGSetTextureAnimation_8037748c)[iVar3];
    }
  }
  return pcVar1;
}


/* __thiscall dEvent_manager_c::debugBfProc(void) */

void __thiscall dEvent_manager_c::debugBfProc(dEvent_manager_c *this)

{
  return;
}


/* __thiscall dEvent_manager_c::getSubstance(dEvDtData_c *,
                                             int) */

void * __thiscall
dEvent_manager_c::getSubstance
          (dEvent_manager_c *this,dEvDtData_c *param_1,dEvt__SubstanceType param_2)

{
  dEvt__SubstanceType dVar1;
  ulong uVar2;
  float *pfVar3;
  
  if ((param_1->mSubstanceIdx < 0) || (param_1->mSubstanceSize < 1)) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_event_manager.cpp",0x169,"0");
    m_Do_printf::OSPanic("d_event_manager.cpp",0x169,&DAT_80352908);
    pfVar3 = (float *)0x0;
  }
  else {
    if ((param_2 != __dummy) && (param_2 != param_1->mSubstanceType)) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_event_manager.cpp",0x16e,"0");
      m_Do_printf::OSPanic("d_event_manager.cpp",0x16e,&DAT_80352908);
    }
    dVar1 = param_1->mSubstanceType;
    if (dVar1 == Int) {
      pfVar3 = (float *)((this->parent).mpInts + param_1->mSubstanceIdx);
    }
    else {
      if ((int)dVar1 < 3) {
        if (-1 < (int)dVar1) {
          return (this->parent).mpFloats + param_1->mSubstanceIdx;
        }
      }
      else {
        if ((int)dVar1 < 5) {
          return (float *)((this->parent).mpStrings + param_1->mSubstanceIdx);
        }
      }
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_event_manager.cpp",0x182,"0");
      m_Do_printf::OSPanic("d_event_manager.cpp",0x182,&DAT_80352908);
      pfVar3 = (float *)0x0;
    }
  }
  return pfVar3;
}


/* __thiscall dEvent_manager_c::setData(char const *) */

void __thiscall dEvent_manager_c::setData(dEvent_manager_c *this,dEvDt__DataFile *param_1)

{
  dEvDt__DataFile *pdVar1;
  
  if (param_1 == (dEvDt__DataFile *)0x0) {
    return;
  }
  (this->parent).mpEventData = param_1;
  pdVar1 = (this->parent).mpEventData;
  if (0 < pdVar1->mEventsCount) {
    (this->parent).mpEvents = (dEvDtEvent_c *)((int)&param_1->mEventsOffs + pdVar1->mEventsOffs);
  }
  pdVar1 = (this->parent).mpEventData;
  if (0 < pdVar1->mStaffsCount) {
    (this->parent).mpStaffs = (dEvDtStaff_c *)((int)&param_1->mEventsOffs + pdVar1->mStaffsOffs);
  }
  pdVar1 = (this->parent).mpEventData;
  if (0 < pdVar1->mActionsCount) {
    (this->parent).mpCuts = (dEvDtCut_c *)((int)&param_1->mEventsOffs + pdVar1->mActionsOffs);
  }
  pdVar1 = (this->parent).mpEventData;
  if (0 < pdVar1->mPropsCount) {
    (this->parent).mpData = (dEvDtData_c *)((int)&param_1->mEventsOffs + pdVar1->mPropsOffs);
  }
  pdVar1 = (this->parent).mpEventData;
  if (0 < pdVar1->mFloatsCount) {
    (this->parent).mpFloats = (float *)((int)&param_1->mEventsOffs + pdVar1->mFloatsOffs);
  }
  pdVar1 = (this->parent).mpEventData;
  if (0 < pdVar1->mIntsCount) {
    (this->parent).mpInts = (int *)((int)&param_1->mEventsOffs + pdVar1->mIntsOffs);
  }
  pdVar1 = (this->parent).mpEventData;
  if (pdVar1->mStringsCount < 1) {
    return;
  }
  (this->parent).mpStrings = (char *)((int)&param_1->mEventsOffs + pdVar1->mStringsOffs);
  return;
}


/* __thiscall dEvent_manager_c::create(void) */

undefined4 __thiscall dEvent_manager_c::create(dEvent_manager_c *this)

{
  dEvDt__DataFile *pdVar1;
  
  dEvDtBase_c::init(&this->parent);
  this->mCameraPlay = 0;
  dEvent_exception_c::init(&this->mException);
  dEvDtFlag_c::init(&this->mFlag);
  pdVar1 = (dEvDt__DataFile *)
           dRes_control_c::getRes
                     ("Stage","event_list.dat",
                      d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
  setData(this,pdVar1);
  return 1;
}


/* __thiscall dEvent_manager_c::remove(void) */

int __thiscall dEvent_manager_c::remove(dEvent_manager_c *this,char *__filename)

{
  int iVar1;
  
  dEvDtBase_c::init(&this->parent);
  this->mCameraPlay = 0;
  dEvent_exception_c::init(&this->mException);
  iVar1 = dEvDtFlag_c::init(&this->mFlag);
  return iVar1;
}


namespace d_event_manager {

/* __stdcall findObjectCallBack(fopAc_ac_c *,
                                void *) */

int findObjectCallBack(fopAc_ac_c *pAct,dEv_seach_prm *pSearch)

{
  dStage__ObjectNameTable *pdVar1;
  
  if (pSearch == (dEv_seach_prm *)0x0) {
    pAct = (fopAc_ac_c *)0x0;
  }
  else {
    pdVar1 = d_stage::dStage_searchName(pSearch->mpActorName);
    if (pdVar1 == (dStage__ObjectNameTable *)0x0) {
      pAct = (fopAc_ac_c *)0x0;
    }
    else {
      if (((pdVar1->mProcName != (pAct->parent).parent.mBsTypeId) ||
          (pdVar1->mSubtype != pAct->mSubtype)) ||
         ((pSearch->mMask != 0 &&
          (pSearch->mValue != (pSearch->mMask & (pAct->parent).parent.mParameters))))) {
        pAct = (fopAc_ac_c *)0x0;
      }
    }
  }
  return (int)pAct;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall extraOnObjectCallBack(fopAc_ac_c *,
                                   void *) */

undefined4 extraOnObjectCallBack(fopAc_ac_c *param_1,dEv_seach_prm *param_2)

{
  int iVar1;
  dStage__ObjectNameTable *pdVar2;
  char *__s1;
  
  if (param_2 != (dEv_seach_prm *)0x0) {
    __s1 = param_2->mpActorName;
    iVar1 = MSL_C.PPCEABI.bare.H::strcmp(__s1,"ALL");
    if (iVar1 == 0) {
      param_1->mStatus = param_1->mStatus | 0x800;
      if ((param_2->mCastInFlag & 1U) != 0) {
        param_1->mStatus = param_1->mStatus | 0x8000;
      }
    }
    else {
      pdVar2 = d_stage::dStage_searchName(__s1);
      if ((((pdVar2 != (dStage__ObjectNameTable *)0x0) &&
           (pdVar2->mProcName == (param_1->parent).parent.mBsTypeId)) &&
          (pdVar2->mSubtype == param_1->mSubtype)) &&
         (((param_2->mMask == 0 ||
           (param_2->mValue == (param_2->mMask & (param_1->parent).parent.mParameters))) &&
          (param_1->mStatus = param_1->mStatus | 0x800, (param_2->mCastInFlag & 1U) != 0)))) {
        param_1->mStatus = param_1->mStatus | 0x8000;
      }
    }
  }
  return 0;
}


/* __stdcall extraOffObjectCallBack(fopAc_ac_c *,
                                    void *) */

undefined4 extraOffObjectCallBack(fopAc_ac_c *param_1,char *param_2)

{
  int iVar1;
  dStage__ObjectNameTable *pdVar2;
  
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp(param_2,"ALL");
  if (iVar1 == 0) {
    param_1->mStatus = param_1->mStatus & 0xfffff7ff;
    param_1->mStatus = param_1->mStatus & 0xffff7fff;
  }
  else {
    pdVar2 = d_stage::dStage_searchName(param_2);
    if (((pdVar2 != (dStage__ObjectNameTable *)0x0) &&
        (pdVar2->mProcName == (param_1->parent).parent.mBsTypeId)) &&
       (pdVar2->mSubtype == param_1->mSubtype)) {
      param_1->mStatus = param_1->mStatus & 0xfffff7ff;
    }
  }
  return 0;
}


/* __stdcall allOffObjectCallBack(fopAc_ac_c *,
                                  void *) */

undefined4 allOffObjectCallBack(int param_1)

{
  *(uint *)(param_1 + 0x1c4) = *(uint *)(param_1 + 0x1c4) & 0xffff67ff;
  return 0;
}

}

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dEvent_manager_c::startProc(dEvDtEvent_c *) */

void __thiscall dEvent_manager_c::startProc(dEvent_manager_c *this,dEvDtEvent_c *param_1)

{
  fopAc_ac_c *pShutter;
  int iVar1;
  int iVar2;
  dEvDtStaff_c *pStaff;
  int staffIdx;
  dEv_seach_prm searchPrm;
  
  dEv_seach_prm::dEv_seach_prm(&searchPrm,(char *)0x0,0,0);
  iVar1 = 0;
  for (iVar2 = 0; iVar2 < param_1->mStaffCount; iVar2 = iVar2 + 1) {
    staffIdx = *(int *)((int)param_1->mStaffIdx + iVar1);
    pStaff = (this->parent).mpStaffs + staffIdx;
    if (pStaff->mStaffType == Normal) {
      pShutter = (fopAc_ac_c *)specialCast(this,pStaff->mName,1);
      if (pShutter == (fopAc_ac_c *)0x0) {
        setPrmStaff(this,&searchPrm,staffIdx);
        pShutter = f_op_actor_iter::fopAcIt_Judge(d_event_manager::findObjectCallBack,&searchPrm);
      }
      if (pShutter != (fopAc_ac_c *)0x0) {
        pShutter->mStatus = pShutter->mStatus | 0x8000;
      }
    }
    if (pStaff->mStaffType == All) {
      setPrmStaff(this,&searchPrm,staffIdx);
      f_op_actor_iter::fopAcIt_Judge(d_event_manager::extraOnObjectCallBack,&searchPrm);
    }
    dEvDtStaff_c::init(pStaff);
    iVar1 = iVar1 + 4;
  }
  param_1->mEventState = Playing;
  dEvDtFlag_c::init(&this->mFlag);
  return;
}


/* __thiscall dEvent_manager_c::closeProc(dEvDtEvent_c *) */

void __thiscall dEvent_manager_c::closeProc(dEvent_manager_c *this,dEvDtEvent_c *param_1)

{
  param_1->mEventState = 4;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dEvent_manager_c::endProc(short,
                                        int) */

void __thiscall dEvent_manager_c::endProc(dEvent_manager_c *this,short param_1,int param_2)

{
  dEvDtEvent_c *pdVar1;
  ulong uVar2;
  
  pdVar1 = getEventData(this,param_1);
  if (pdVar1 == (dEvDtEvent_c *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_event_manager.cpp",0x2ec,"0");
    m_Do_printf::OSPanic("d_event_manager.cpp",0x2ec,&DAT_80352908);
  }
  else {
    if (param_2 != 0) {
      closeProc(this,pdVar1);
    }
    if (pdVar1->mEventState == 4) {
      f_op_actor_iter::fopAcIt_Judge(d_event_manager::allOffObjectCallBack,&DAT_80352924);
      this->mCameraPlay = 0;
      pdVar1->mEventState = None;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dEvent_manager_c::mainProc(void) */

void __thiscall dEvent_manager_c::mainProc(dEvent_manager_c *this)

{
  int iVar1;
  int iVar2;
  dEvDtEvent_c *pdVar3;
  int iVar4;
  
  if ((this->parent).mpEventData != (dEvDt__DataFile *)0x0) {
    iVar4 = 0;
    for (iVar2 = 0; iVar2 < ((this->parent).mpEventData)->mEventsCount; iVar2 = iVar2 + 1) {
      pdVar3 = (dEvDtEvent_c *)(((this->parent).mpEvents)->mName + iVar4);
      if ((pdVar3->mEventState == Playing) &&
         (iVar1 = dEvDtEvent_c::finish_check(pdVar3), iVar1 != 0)) {
        closeProc(this,pdVar3);
      }
      iVar4 = iVar4 + 0xb0;
    }
    iVar4 = 0;
    for (iVar2 = 0; iVar2 < ((this->parent).mpEventData)->mEventsCount; iVar2 = iVar2 + 1) {
      pdVar3 = (dEvDtEvent_c *)(((this->parent).mpEvents)->mName + iVar4);
      if (pdVar3->mEventState == Ordered) {
        startProc(this,pdVar3);
      }
      iVar4 = iVar4 + 0xb0;
    }
    iVar4 = 0;
    for (iVar2 = 0; iVar2 < ((this->parent).mpEventData)->mEventsCount; iVar2 = iVar2 + 1) {
      pdVar3 = (dEvDtEvent_c *)(((this->parent).mpEvents)->mName + iVar4);
      if (pdVar3->mEventState == Playing) {
        dEvDtBase_c::advanceCut(&this->parent,pdVar3);
      }
      iVar4 = iVar4 + 0xb0;
    }
    iVar4 = 0;
    for (iVar2 = 0; iVar2 < ((this->parent).mpEventData)->mEventsCount; iVar2 = iVar2 + 1) {
      pdVar3 = (dEvDtEvent_c *)(((this->parent).mpEvents)->mName + iVar4);
      if (pdVar3->mEventState == Playing) {
        dEvDtEvent_c::specialStaffProc(pdVar3,(this->parent).mpStaffs);
      }
      iVar4 = iVar4 + 0xb0;
    }
  }
  return;
}


/* __thiscall dEvent_manager_c::runProc(void) */

void __thiscall dEvent_manager_c::runProc(dEvent_manager_c *this)

{
  exceptionProc(this);
  debugBfProc(this);
  dEvt_control_c::check(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl);
  mainProc(this);
  return;
}


/* __thiscall dEvent_manager_c::getEventData(short) */

dEvDtEvent_c * __thiscall dEvent_manager_c::getEventData(dEvent_manager_c *this,short eventIdx)

{
  dEvDt__DataFile *pdVar1;
  
  pdVar1 = (this->parent).mpEventData;
  if (((pdVar1 != (dEvDt__DataFile *)0x0) && (-1 < eventIdx)) &&
     ((int)eventIdx < pdVar1->mEventsCount)) {
    return (this->parent).mpEvents + eventIdx;
  }
  return (dEvDtEvent_c *)0x0;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dEvent_manager_c::getEventIdx(char const *,
                                            unsigned char) */

int __thiscall
dEvent_manager_c::getEventIdx(dEvent_manager_c *this,char *eventNameString,uchar stageEVNTListIndex)

{
  uint uVar1;
  dStage_EventInfo_c *pEventInfo;
  int iVar2;
  int iVar3;
  int iVar4;
  
  pEventInfo = (dStage_EventInfo_c *)
               (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getEventInfo)
                         ();
  if ((this->parent).mpEventData == (dEvDt__DataFile *)0x0) {
    iVar2 = -1;
  }
  else {
    if (((pEventInfo == (dStage_EventInfo_c *)0x0) ||
        (uVar1 = (uint)stageEVNTListIndex, uVar1 == 0xff)) || (pEventInfo->mCount <= (int)uVar1)) {
      if (eventNameString == (char *)0x0) {
        iVar2 = -1;
      }
      else {
        iVar4 = 0;
        for (iVar2 = 0; iVar2 < ((this->parent).mpEventData)->mEventsCount; iVar2 = iVar2 + 1) {
          iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                            (eventNameString,((this->parent).mpEvents)->mName + iVar4);
          if (iVar3 == 0) {
            return (int)(short)iVar2;
          }
          iVar4 = iVar4 + 0xb0;
        }
        iVar2 = -1;
      }
    }
    else {
      iVar2 = getEventIdx(this,pEventInfo->mpEvents[uVar1].mName,0xff);
    }
  }
  return iVar2;
}


/* __thiscall dEvent_manager_c::order(short) */

bool __thiscall dEvent_manager_c::order(dEvent_manager_c *this,short param_1)

{
  dEvDtEvent_c *pdVar1;
  
  pdVar1 = getEventData(this,param_1);
  if (pdVar1 != (dEvDtEvent_c *)0x0) {
    pdVar1->mEventState = Ordered;
  }
  return pdVar1 != (dEvDtEvent_c *)0x0;
}


/* __thiscall dEvent_manager_c::startCheck(short) */

uint __thiscall dEvent_manager_c::startCheck(dEvent_manager_c *this,short param_1)

{
  dEvDtEvent_c *pdVar1;
  uint uVar2;
  
  pdVar1 = getEventData(this,param_1);
  if (pdVar1 == (dEvDtEvent_c *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = countLeadingZeros(2 - pdVar1->mEventState);
    uVar2 = uVar2 >> 5;
  }
  return uVar2;
}


/* __thiscall dEvent_manager_c::startCheckOld(char const *) */

int __thiscall dEvent_manager_c::startCheckOld(dEvent_manager_c *this,char *param_1)

{
  short sVar2;
  int iVar1;
  
  sVar2 = getEventIdx(this,param_1,0xff);
  iVar1 = startCheck(this,sVar2);
  return iVar1;
}


/* __thiscall dEvent_manager_c::endCheck(short) */

bool __thiscall dEvent_manager_c::endCheck(dEvent_manager_c *this,short param_1)

{
  uint uVar1;
  dEvDtEvent_c *pdVar2;
  undefined uVar3;
  
  pdVar2 = getEventData(this,param_1);
  if (pdVar2 == (dEvDtEvent_c *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar1 = countLeadingZeros(4 - pdVar2->mEventState);
    uVar3 = (undefined)(uVar1 >> 5);
  }
  return (bool)uVar3;
}


/* __thiscall dEvent_manager_c::endCheckOld(char const *) */

bool __thiscall dEvent_manager_c::endCheckOld(dEvent_manager_c *this,char *param_1)

{
  short sVar1;
  bool bVar2;
  
  sVar1 = getEventIdx(this,param_1,0xff);
  bVar2 = endCheck(this,sVar1);
  return bVar2;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* __thiscall dEvent_manager_c::getMyStaffId(char const *,
                                             fopAc_ac_c *,
                                             int) */

int __thiscall
dEvent_manager_c::getMyStaffId(dEvent_manager_c *this,char *param_1,fopAc_ac_c *pActor,int param_3)

{
  dEvDtEvent__EventState dVar1;
  int iVar2;
  int iVar3;
  dEvDtStaff_c *pStaff;
  int iVar4;
  int iVar5;
  dEvDtEvent_c *pEvent;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode != 0) &&
      ((this->parent).mpEventData != (dEvDt__DataFile *)0x0)) &&
     ((pActor == (fopAc_ac_c *)0x0 || ((pActor->mStatus & 0x8000) != 0)))) {
    iVar7 = 0;
    for (iVar8 = 0; iVar8 < ((this->parent).mpEventData)->mEventsCount; iVar8 = iVar8 + 1) {
      pEvent = (dEvDtEvent_c *)(((this->parent).mpEvents)->mName + iVar7);
      dVar1 = pEvent->mEventState;
      if (((dVar1 == Playing) || (dVar1 == 4)) || (dVar1 == 3)) {
        iVar5 = pEvent->mStaffCount;
        iVar6 = 0;
        for (iVar3 = 0; iVar3 < iVar5; iVar3 = iVar3 + 1) {
          iVar4 = *(int *)((int)pEvent->mStaffIdx + iVar6);
          pStaff = (this->parent).mpStaffs + iVar4;
          if (((pStaff->mStaffType != All) &&
              (iVar2 = MSL_C.PPCEABI.bare.H::strcmp(param_1,pStaff->mName), iVar2 == 0)) &&
             (param_3 == pStaff->field_0x20)) {
            return iVar4;
          }
          iVar6 = iVar6 + 4;
        }
      }
      iVar7 = iVar7 + 0xb0;
    }
  }
  return -1;
}


/* __thiscall dEvent_manager_c::getIsAddvance(int) */

bool __thiscall dEvent_manager_c::getIsAddvance(dEvent_manager_c *this,int staffIdx)

{
  if (staffIdx == -1) {
    return false;
  }
  return (bool)(this->parent).mpStaffs[staffIdx].mbIsAdvance;
}


namespace d_event_manager {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dEvmng_strcmp(char const *,
                           char *) */

undefined4 dEvmng_strcmp(char *param_1,char *param_2)

{
  size_t sVar1;
  size_t sVar2;
  ulong uVar3;
  undefined4 uVar4;
  
  sVar1 = MSL_C.PPCEABI.bare.H::strlen(param_1);
  sVar2 = MSL_C.PPCEABI.bare.H::strlen(param_2);
  if ((sVar1 < 100) && (sVar2 < 100)) {
    if (sVar2 < sVar1) {
      uVar4 = 1;
    }
    else {
      for (; sVar1 != 0; sVar1 = sVar1 - 1) {
        if (*param_1 != *param_2) {
          return 1;
        }
        param_2 = param_2 + 1;
        param_1 = param_1 + 1;
      }
      uVar4 = 0;
    }
  }
  else {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_event_manager.cpp",0x44a,"0");
    m_Do_printf::OSPanic("d_event_manager.cpp",0x44a,&DAT_80352908);
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

}

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dEvent_manager_c::getMyActIdx(int,
                                            char const * *,
                                            int,
                                            int,
                                            int) */

int __thiscall
dEvent_manager_c::getMyActIdx
          (dEvent_manager_c *this,int staffIdx,char **pActions,int actionCount,int force,int param_5
          )

{
  int iVar1;
  char *pCutName;
  ulong uVar2;
  int iVar3;
  dEvDtStaff_c *pdVar4;
  int iVar5;
  
  if (staffIdx == -1) {
    iVar1 = -1;
  }
  else {
    pdVar4 = (this->parent).mpStaffs + staffIdx;
    if ((pdVar4->mbNeedsAction == 0) || (force != 0)) {
      pCutName = getMyNowCutName(this,staffIdx);
      if (pCutName == (char *)0x0) {
        iVar1 = -1;
      }
      else {
        pdVar4->mbNeedsAction = 1;
        iVar5 = 0;
        for (iVar1 = 0; iVar1 < actionCount; iVar1 = iVar1 + 1) {
          if (*(int *)((int)pActions + iVar5) == 0) {
            uVar2 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar2,"d_event_manager.cpp",0x46a,"action[i]");
            m_Do_printf::OSPanic("d_event_manager.cpp",0x46a,&DAT_80352908);
          }
          if (param_5 == 0) {
            iVar3 = MSL_C.PPCEABI.bare.H::strcmp(*(char **)((int)pActions + iVar5),pCutName);
            if (iVar3 == 0) {
              pdVar4->mCurActionIdx = iVar1;
              return iVar1;
            }
          }
          else {
            iVar3 = d_event_manager::dEvmng_strcmp(*(undefined4 *)((int)pActions + iVar5),pCutName);
            if (iVar3 == 0) {
              pdVar4->mCurActionIdx = iVar1;
              return iVar1;
            }
          }
          iVar5 = iVar5 + 4;
        }
        pdVar4->mCurActionIdx = 0xffffffff;
        iVar1 = -1;
      }
    }
    else {
      iVar1 = pdVar4->mCurActionIdx;
    }
  }
  return iVar1;
}


/* __thiscall dEvent_manager_c::getMyActName(int) */

char * __thiscall dEvent_manager_c::getMyActName(dEvent_manager_c *this,int param_1)

{
  char *pcVar1;
  
  if (param_1 == -1) {
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = getMyNowCutName(this,param_1);
    if (pcVar1 == (char *)0x0) {
      pcVar1 = (char *)0x0;
    }
  }
  return pcVar1;
}


/* __thiscall dEvent_manager_c::getMyNowCutName(int) */

char * __thiscall dEvent_manager_c::getMyNowCutName(dEvent_manager_c *this,int staffIdx)

{
  if (staffIdx == -1) {
    return ((dEvDtCut_c *)0x0)->mName;
  }
  return (this->parent).mpCuts[(this->parent).mpStaffs[staffIdx].mCurCutIdx].mName;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dEvent_manager_c::getMyDataP(int,
                                           char const *,
                                           int) */

dEvDtData_c * __thiscall
dEvent_manager_c::getMyDataP(dEvent_manager_c *this,int staffIdx,char *pDataName,int param_3)

{
  int iVar1;
  dEvDtCut_c *pdVar2;
  dEvDtData_c *pData;
  
  if (staffIdx != -1) {
    if (param_3 == 0) {
      pdVar2 = (this->parent).mpCuts + (this->parent).mpStaffs[staffIdx].mCurCutIdx;
    }
    else {
      pdVar2 = (this->parent).mpCuts + (this->parent).mpStaffs[staffIdx].mFirstCutIdx;
    }
    iVar1 = pdVar2->field_0x38;
    while (iVar1 != -1) {
      pData = (this->parent).mpData + iVar1;
      iVar1 = MSL_C.PPCEABI.bare.H::strcmp(pDataName,pData->mName);
      if (iVar1 == 0) {
        return pData;
      }
      iVar1 = pData->mNextDataIdx;
    }
  }
  return (dEvDtData_c *)0x0;
}


/* __thiscall dEvent_manager_c::getMySubstanceP(int,
                                                char const *,
                                                int) */

void * __thiscall
dEvent_manager_c::getMySubstanceP
          (dEvent_manager_c *this,int staffIdx,char *pDataName,dEvt__SubstanceType pType)

{
  dEvDtData_c *pdVar1;
  void *pvVar2;
  
  pdVar1 = getMyDataP(this,staffIdx,pDataName,0);
  if (pdVar1 == (dEvDtData_c *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    pvVar2 = getSubstance(this,pdVar1,pType);
  }
  return pvVar2;
}


/* __thiscall dEvent_manager_c::getMySubstanceNum(int,
                                                  char const *) */

int __thiscall
dEvent_manager_c::getMySubstanceNum(dEvent_manager_c *this,int staffIdx,char *param_2)

{
  dEvDtData_c *pdVar1;
  int iVar2;
  
  pdVar1 = getMyDataP(this,staffIdx,param_2,0);
  if (pdVar1 == (dEvDtData_c *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = pdVar1->mSubstanceSize;
  }
  return iVar2;
}


/* __thiscall dEvent_manager_c::cutEnd(int) */

void __thiscall dEvent_manager_c::cutEnd(dEvent_manager_c *this,int staffIdx)

{
  if (staffIdx != -1) {
    dEvDtFlag_c::flagSet
              (&this->mFlag,
               (this->parent).mpCuts[(this->parent).mpStaffs[staffIdx].mCurCutIdx].mFlagIdx);
  }
  return;
}


/* __thiscall dEvent_manager_c::getEventPrio(short) */

int __thiscall dEvent_manager_c::getEventPrio(dEvent_manager_c *this,short param_1)

{
  dEvDtEvent_c *pdVar1;
  int iVar2;
  
  pdVar1 = getEventData(this,param_1);
  if (pdVar1 == (dEvDtEvent_c *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = pdVar1->mPriority;
  }
  return iVar2;
}


/* __thiscall dEvent_manager_c::getEventEndSound(short) */

byte __thiscall dEvent_manager_c::getEventEndSound(dEvent_manager_c *this,short param_1)

{
  dEvDtEvent_c *pdVar1;
  byte bVar2;
  
  pdVar1 = getEventData(this,param_1);
  if (pdVar1 == (dEvDtEvent_c *)0x0) {
    bVar2 = 0;
  }
  else {
    bVar2 = pdVar1->mEventEndSound;
  }
  return bVar2;
}


/* __thiscall dEvent_manager_c::exceptionProc(void) */

void __thiscall dEvent_manager_c::exceptionProc(dEvent_manager_c *this)

{
  int iVar1;
  char *eventNameString;
  short eventIndex;
  bool bVar2;
  undefined uVar3;
  
  eventNameString = dEvent_exception_c::getEventName(&this->mException);
  eventIndex = getEventIdx(this,eventNameString,0xff);
  if (eventIndex == -1) {
    (this->mException).mEventInfoIdx = 0xffffffff;
  }
  else {
    iVar1 = (this->mException).mEventInfoIdx;
    uVar3 = 0xff;
    if (iVar1 < 200) {
      uVar3 = (undefined)iVar1;
    }
    iVar1 = (this->mException).mState;
    if (iVar1 == 1) {
      iVar1 = startCheck(this,eventIndex);
      if (iVar1 == 0) {
        f_op_actor_mng::fopAcM_orderOtherEvent2
                  ((fopAc_ac_c *)0x0,eventNameString,RequiresPartnerPcId,0xffff);
      }
      else {
        (this->mException).mState = 2;
        iVar1 = MSL_C.PPCEABI.bare.H::strcmp(eventNameString,"MEETSHISHIOH");
        if (iVar1 == 0) {
          dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xf80);
        }
        iVar1 = MSL_C.PPCEABI.bare.H::strcmp(eventNameString,"look_tetra");
        if (iVar1 == 0) {
          dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x280);
        }
      }
    }
    else {
      if (iVar1 < 1) {
        if (-1 < iVar1) {
          (this->mException).mState = 1;
          f_op_actor_mng::fopAcM_orderOtherEventId((fopAc_ac_c *)0x0,eventIndex,uVar3,0xffff,0,1);
        }
      }
      else {
        if ((iVar1 < 3) && (bVar2 = endCheck(this,eventIndex), bVar2 != false)) {
          d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags =
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags | 8;
          (this->mException).mState = 0;
          (this->mException).mEventInfoIdx = 0xffffffff;
        }
      }
    }
  }
  return;
}


/* __thiscall dEvent_manager_c::issueStaff(char const *) */

void __thiscall dEvent_manager_c::issueStaff(dEvent_manager_c *this,char *param_1)

{
  dEv_seach_prm dStack24;
  
  dEv_seach_prm::dEv_seach_prm(&dStack24,param_1,0,0);
  f_op_actor_iter::fopAcIt_Judge(d_event_manager::extraOnObjectCallBack,&dStack24);
  return;
}


/* __thiscall dEvent_manager_c::cancelStaff(char const *) */

void __thiscall dEvent_manager_c::cancelStaff(dEvent_manager_c *this,char *param_1)

{
  f_op_actor_iter::fopAcIt_Judge(d_event_manager::extraOffObjectCallBack,param_1);
  return;
}


/* __thiscall dEvent_manager_c::setGoal(cXyz *) */

void __thiscall dEvent_manager_c::setGoal(dEvent_manager_c *this,cXyz *param_1)

{
  (this->mGoal).x = param_1->x;
  (this->mGoal).y = param_1->y;
  (this->mGoal).z = param_1->z;
  return;
}


/* __thiscall dEvent_manager_c::getGoal(void) */

cXyz * __thiscall dEvent_manager_c::getGoal(dEvent_manager_c *this)

{
  return &this->mGoal;
}


namespace d_event_manager {

/* __stdcall findShutterCallBack(fopAc_ac_c *,
                                 void *) */

fopAc_ac_c * findShutterCallBack(fopAc_ac_c *pAct,dEvt__FindShutterData *pData)

{
  cXyz diff;
  
  if (pData->mBsTypeId == (pAct->parent).parent.mBsTypeId) {
    ::cXyz::operator__(&diff,&(pAct->mOrig).mPos,&(pData->mpRelativeAct->mOrig).mPos);
    if ((((10_0 <= diff.x) || (diff.x <= _10_0)) || (10_0 <= diff.y)) ||
       (((diff.y <= _10_0 || (10_0 <= diff.z)) || (diff.z <= _10_0)))) {
      pAct = (fopAc_ac_c *)0x0;
    }
  }
  else {
    pAct = (fopAc_ac_c *)0x0;
  }
  return pAct;
}

}

/* __thiscall dEvent_manager_c::specialCast_Shutter(short,
                                                    int) */

fopAc_ac_c * __thiscall
dEvent_manager_c::specialCast_Shutter(dEvent_manager_c *this,short mTypeId,int bSetGoal)

{
  int iVar1;
  ulong uVar2;
  fopAc_ac_c *pShutter;
  dEvt__FindShutterData findShutterData;
  cXyz local_20;
  
  findShutterData.mpRelativeAct =
       (fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  findShutterData.mBsTypeId = mTypeId;
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor == (daPy_lk_c *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_event_manager.cpp",0x623,"0");
    m_Do_printf::OSPanic("d_event_manager.cpp",0x623,&DAT_80352908);
  }
  pShutter = f_op_actor_iter::fopAcIt_Judge(d_event_manager::findShutterCallBack,&findShutterData);
  if ((pShutter != (fopAc_ac_c *)0x0) && (bSetGoal != 0)) {
    local_20.y = (pShutter->mOrig).mPos.y;
    iVar1 = (int)((int)((findShutterData.mpRelativeAct)->mOrig).mRot.y + 0x8000U & 0xffff) >>
            (JKernel::JMath::jmaSinShift & 0x3f);
    local_20.x = (pShutter->mOrig).mPos.x +
                 d_event_manager::100_0 * JKernel::JMath::jmaSinTable[iVar1];
    local_20.z = (pShutter->mOrig).mPos.z +
                 d_event_manager::100_0 * JKernel::JMath::jmaCosTable[iVar1];
    setGoal(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,&local_20);
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPt2 =
         dEvt_control_c::getPId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,pShutter);
  }
  return pShutter;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dEvent_manager_c::specialCast(char const *,
                                            int) */

fopAc_ac_c * __thiscall
dEvent_manager_c::specialCast(dEvent_manager_c *this,char *param_1,int bSetGoal)

{
  int iVar1;
  fopAc_ac_c *pActor;
  
  pActor = (fopAc_ac_c *)0x0;
  if (param_1 == (char *)0x0) {
    pActor = (fopAc_ac_c *)0x0;
  }
  else {
    iVar1 = MSL_C.PPCEABI.bare.H::strcmp(param_1,"SHUTTER_DOOR");
    if (iVar1 == 0) {
      pActor = specialCast_Shutter(this,0x12e,bSetGoal);
      if (pActor == (fopAc_ac_c *)0x0) {
        pActor = specialCast_Shutter(this,0x12f,bSetGoal);
      }
      if (pActor == (fopAc_ac_c *)0x0) {
        pActor = specialCast_Shutter(this,0x132,bSetGoal);
      }
      if (pActor == (fopAc_ac_c *)0x0) {
        pActor = specialCast_Shutter(this,0x133,bSetGoal);
      }
      if (pActor != (fopAc_ac_c *)0x0) {
        d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags | 0x10;
      }
    }
    if (pActor != (fopAc_ac_c *)0x0) {
      if (bSetGoal == 0) {
        pActor->mStatus = pActor->mStatus & 0xffffefff;
      }
      else {
        pActor->mStatus = pActor->mStatus | 0x1000;
      }
    }
  }
  return pActor;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dEvent_manager_c::setPrmStaff(void *,
                                            int) */

void __thiscall
dEvent_manager_c::setPrmStaff(dEvent_manager_c *this,dEv_seach_prm *pSearchPrm,int staffIdx)

{
  ulong uVar1;
  dEvDtData_c *pDevPrmMask;
  ulong *puVar2;
  dEvDtData_c *pdVar3;
  dEvDtStaff_c *pdVar4;
  
  pdVar4 = (this->parent).mpStaffs + staffIdx;
  if (pdVar4 == (dEvDtStaff_c *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_event_manager.cpp",0x66b,"staff_data");
    m_Do_printf::OSPanic("d_event_manager.cpp",0x66b,&DAT_80352908);
  }
  if (pSearchPrm == (dEv_seach_prm *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_event_manager.cpp",0x66c,"prm");
    m_Do_printf::OSPanic("d_event_manager.cpp",0x66c,&DAT_80352908);
  }
  pSearchPrm->mpActorName = pdVar4->mName;
  pDevPrmMask = getMyDataP(this,staffIdx,"DEV_PRM_MASK",1);
  if (pDevPrmMask == (dEvDtData_c *)0x0) {
    pSearchPrm->mMask = 0;
    pSearchPrm->mValue = 0;
  }
  else {
    puVar2 = (ulong *)getSubstance(this,pDevPrmMask,Int);
    if (puVar2 == (ulong *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_event_manager.cpp",0x678,"i_data");
      m_Do_printf::OSPanic("d_event_manager.cpp",0x678,&DAT_80352908);
    }
    pSearchPrm->mMask = *puVar2;
    pSearchPrm->mValue = puVar2[1];
  }
  pSearchPrm->mCastInFlag = 0;
  pdVar3 = getMyDataP(this,staffIdx,"CAST_IN",1);
  if (pdVar3 != (dEvDtData_c *)0x0) {
    pSearchPrm->mCastInFlag = pSearchPrm->mCastInFlag | 1;
  }
  return;
}


/* __thiscall dEvent_manager_c::getToolId(unsigned char,
                                          int) */

uint __thiscall dEvent_manager_c::getToolId(dEvent_manager_c *this,byte eventInfoIdx,int param_2)

{
  int iVar1;
  uint uVar2;
  dStage_EventInfo_c *mpEventInfo;
  undefined3 in_register_00000010;
  int iVar3;
  uint uVar4;
  
  uVar4 = CONCAT31(in_register_00000010,eventInfoIdx);
  mpEventInfo = (dStage_EventInfo_c *)
                (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getEventInfo
                )();
  if ((((eventInfoIdx != 0xff) && (mpEventInfo != (dStage_EventInfo_c *)0x0)) &&
      ((int)(uint)eventInfoIdx < mpEventInfo->mCount)) &&
     (iVar1 = param_2 + 1, iVar3 = param_2, -1 < param_2)) {
    do {
      uVar2 = (uint)mpEventInfo->mpEvents[uVar4 & 0xff].field_0x12;
      if (uVar2 == 0xff) {
        if (iVar3 == 0) {
          return uVar4;
        }
      }
      else {
        if (param_2 == uVar2) {
          return uVar4;
        }
      }
      uVar4 = (uint)*(byte *)(mpEventInfo->mpEvents + (uVar4 & 0xff));
      if (uVar4 == 0xff) {
        return 0xff;
      }
      iVar3 = iVar3 + -1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return 0xff;
}


/* __thiscall dEv_seach_prm::dEv_seach_prm(char const *,
                                           unsigned long,
                                           unsigned long) */

void __thiscall
dEv_seach_prm::dEv_seach_prm(dEv_seach_prm *this,char *param_1,ulong param_2,ulong param_3)

{
  this->mpActorName = param_1;
  this->mMask = param_2;
  this->mValue = param_3;
  this->mCastInFlag = 0;
  return;
}


namespace d_event_manager {

/* __stdcall dEv_extra_createCB(void *) */

undefined4 dEv_extra_createCB(int param_1)

{
  *(uint *)(param_1 + 0x1c4) = *(uint *)(param_1 + 0x1c4) | 0x800;
  return 4;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dEv_talkman_get_action(int) */

int dEv_talkman_get_action(int param_1)

{
  int staffIdx;
  int iVar1;
  
  staffIdx = ::dEvent_manager_c::getMyStaffId
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"TALKMAN",
                        (fopAc_ac_c *)0x0,0);
  if (staffIdx == -1) {
    iVar1 = -1;
  }
  else {
    iVar1 = ::dEvent_manager_c::getMyActIdx
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                       &action_table_4789,3,0,0);
    if (iVar1 == param_1) {
      ::dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
    }
  }
  return iVar1;
}

}

/* __thiscall dEvent_manager_c::ChkPresentEnd(void) */

uint __thiscall dEvent_manager_c::ChkPresentEnd(dEvent_manager_c *this)

{
  int iVar1;
  
  iVar1 = d_event_manager::dEv_talkman_get_action(0);
  return (iVar1 >> 0x1f) + (uint)(iVar1 != 0) & 0xff;
}


/* __thiscall dEvent_manager_c::CancelPresent(void) */

uint __thiscall dEvent_manager_c::CancelPresent(dEvent_manager_c *this)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = d_event_manager::dEv_talkman_get_action(1);
  uVar1 = countLeadingZeros(1 - iVar2);
  return uVar1 >> 5 & 0xff;
}


/* __thiscall dEvent_manager_c::checkStartDemo(void) */

int __thiscall dEvent_manager_c::checkStartDemo(dEvent_manager_c *this)

{
  int iVar1;
  int iVar2;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
    return 0;
  }
  iVar1 = -(this->mException).mEventInfoIdx;
  iVar2 = iVar1 + -1;
  return iVar2 - ((uint)(iVar2 == 0) + iVar1 + -2);
}


namespace d_event_manager {

/* __stdcall dEvmng_daNpc_Tt_Conv(unsigned char) */

uint dEvmng_daNpc_Tt_Conv(byte param_1)

{
  ulong uVar1;
  uint uVar2;
  
  if (4 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_event_manager.cpp",0x716,"0");
    m_Do_printf::OSPanic("d_event_manager.cpp",0x716,&DAT_80352908);
  }
  uVar2 = 0;
  while( true ) {
    if (4 < (uVar2 & 0xff)) {
      return 0;
    }
    if ((&daNpc_Tt_tact_table)[uVar2 & 0xff] == param_1) break;
    uVar2 = uVar2 + 1;
  }
  return uVar2;
}


/* __stdcall dEvmng_daNpc_Tt_GetEvFlag(int) */

undefined2 dEvmng_daNpc_Tt_GetEvFlag(int param_1)

{
  return *(undefined2 *)(&dance_table_4855 + param_1 * 2);
}

