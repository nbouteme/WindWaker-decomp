#include <d_event_data.h>
#include <d_event_manager.h>
#include <d_kankyo.h>
#include <d_com_inf_game.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_event_data.h>
#include <f_op_msg_mng.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_stage.h>
#include <f_op_actor_mng.h>
#include <m_Do_graphic.h>
#include <d_vibration.h>
#include <d_drawlist.h>
#include <d_resorce.h>
#include <d_demo.h>
#include <d_save.h>
#include <Demangler/dEvDtStaff_c.h>
#include <dEvDtBase_c.h>
#include <dEvDtFlag_c.h>
#include <dEvDtCut_c.h>
#include <dEvDtEvent_c.h>


namespace d_event_data {
undefined4 l_msgId$4247;
undefined4 l_msg$4248;
undefined4 l_msgNo$4249;

/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __stdcall dEvDt_Next_Stage(int,
                              int) */

undefined4 dEvDt_Next_Stage(int staffIdx,byte wipeType)

{
  char *pStageName;
  undefined4 uVar1;
  int *pStartCode;
  int *pRoomNo;
  int *pLayer;
  float *pHour;
  uint *pMode;
  int *pWipe;
  ulong uVar2;
  uint mode;
  byte layerNo;
  byte roomIdx;
  
  roomIdx = 0;
  layerNo = 0xff;
  mode = 0;
  pStageName = (char *)dEvent_manager_c::getMySubstanceP
                                 (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                  "Stage",String);
  if (pStageName == (char *)0x0) {
    uVar1 = 0;
  }
  else {
    pStartCode = (int *)dEvent_manager_c::getMySubstanceP
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                   "StartCode",Int);
    pRoomNo = (int *)dEvent_manager_c::getMySubstanceP
                               (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                "RoomNo",Int);
    if (pRoomNo != (int *)0x0) {
      roomIdx = (byte)*pRoomNo;
    }
    pLayer = (int *)dEvent_manager_c::getMySubstanceP
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,"Layer",
                               Int);
    if (pLayer != (int *)0x0) {
      layerNo = (byte)*pLayer;
    }
    pHour = (float *)dEvent_manager_c::getMySubstanceP
                               (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,"Hour",
                                Float);
    pMode = (uint *)dEvent_manager_c::getMySubstanceP
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,"Mode",
                               Int);
    if (pMode != (uint *)0x0) {
      mode = *pMode;
    }
    pWipe = (int *)dEvent_manager_c::getMySubstanceP
                             (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,"Wipe",
                              Int);
    if (pWipe != (int *)0x0) {
      wipeType = (byte)*pWipe;
    }
    if ((pStageName == (char *)0x0) || (pStartCode == (int *)0x0)) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_event_data.cpp",0x88,"0");
      m_Do_printf::OSPanic("d_event_data.cpp",0x88,&DAT_80352607);
    }
    else {
      if (pHour != (float *)0x0) {
        d_kankyo::dKy_set_nexttime((double)(15_0 * *pHour));
      }
      d_com_inf_game::dComIfGp_setNextStage
                (pStageName,(short)*pStartCode,roomIdx,layerNo,0_0,mode,1,wipeType);
    }
    uVar1 = 1;
  }
  return uVar1;
}

}

/* __thiscall dEvDtFlag_c::flagCheck(int) */

bool __thiscall dEvDtFlag_c::flagCheck(dEvDtFlag_c *this,int param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = flagMaxCheck(this,param_1);
  if (iVar1 == 0) {
    bVar2 = (1 << (param_1 & 0x1fU) &
            *(uint *)((int)this->mFlag + ((uint)param_1 >> 3 & 0x1ffffffc))) != 0;
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}


/* __thiscall dEvDtFlag_c::flagSet(int) */

bool __thiscall dEvDtFlag_c::flagSet(dEvDtFlag_c *this,int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = flagMaxCheck(this,param_1);
  if (iVar1 == 0) {
    uVar2 = (uint)param_1 >> 3 & 0x1ffffffc;
    *(uint *)((int)this->mFlag + uVar2) =
         *(uint *)((int)this->mFlag + uVar2) | 1 << (param_1 & 0x1fU);
  }
  return iVar1 == 0;
}


/* __thiscall dEvDtFlag_c::flagMaxCheck(int) */

undefined4 __thiscall dEvDtFlag_c::flagMaxCheck(dEvDtFlag_c *this,int param_1)

{
  undefined4 uVar1;
  ulong uVar2;
  
  if (param_1 == -1) {
    uVar1 = 1;
  }
  else {
    if (param_1 < 0x2800) {
      uVar1 = 0;
    }
    else {
      if (param_1 >= 0x2800) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_event_data.cpp",0xc0,"flag_id < FlagMax");
        m_Do_printf::OSPanic("d_event_data.cpp",0xc0,&DAT_80352607);
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}


/* __thiscall dEvDtFlag_c::init(void) */

int __thiscall dEvDtFlag_c::init(dEvDtFlag_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0x140;
  do {
    *(undefined4 *)((int)this->mFlag + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return (int)this;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dEvDtEvent_c::finish_check(void) */

undefined4 __thiscall dEvDtEvent_c::finish_check(dEvDtEvent_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  while( true ) {
    iVar1 = *(int *)((int)this->mFlagCheckFinish + iVar3);
    if (iVar1 == -1) {
      return 1;
    }
    iVar1 = dEvDtFlag_c::flagCheck(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mFlag,iVar1);
    if (iVar1 == 0) break;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 4;
    if (2 < iVar2) {
      return 1;
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dEvDtEvent_c::specialStaffProc(dEvDtStaff_c *) */

void __thiscall dEvDtEvent_c::specialStaffProc(dEvDtEvent_c *this,dEvDtStaff_c *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = 0; iVar1 < this->mStaffCount; iVar1 = iVar1 + 1) {
    dEvDtStaff_c::specialProc(param_1 + *(int *)((int)this->mStaffIdx + iVar2));
    iVar2 = iVar2 + 4;
  }
  return;
}


/* __thiscall dEvDtStaff_c::specialProc_WaitStart(int) */

void __thiscall dEvDtStaff_c::specialProc_WaitStart(dEvDtStaff_c *this,int param_1)

{
  int *pTimer;
  
  pTimer = (int *)dEvent_manager_c::getMySubstanceP
                            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,param_1,"Timer",Int
                            );
  if (pTimer == (int *)0x0) {
    this->mTimer = 0;
  }
  else {
    this->mTimer = (short)*pTimer;
  }
  return;
}


/* __thiscall dEvDtStaff_c::specialProc_WaitProc(int) */

void __thiscall dEvDtStaff_c::specialProc_WaitProc(dEvDtStaff_c *this,int param_1)

{
  if (this->mTimer < 1) {
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,param_1);
  }
  else {
    this->mTimer = this->mTimer + -1;
  }
  return;
}


/* __thiscall dEvDtStaff_c::specialProc(void) */

void __thiscall dEvDtStaff_c::specialProc(dEvDtStaff_c *this)

{
  switch(this->mStaffType) {
  case All:
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mIndex);
    break;
  case Timekeeper:
    specialProcTimekeeper(this);
    break;
  case Director:
    specialProcDirector(this);
    break;
  case Message:
    specialProcMessage(this);
    break;
  case Sounds:
    specialProcSound(this);
    break;
  case Light:
    specialProcLight(this);
    break;
  case Package:
    specialProcPackage(this);
    break;
  case Create:
    specialProcCreate(this);
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mIndex);
  }
  return;
}


/* __thiscall dEvDtStaff_c::init(void) */

void __thiscall dEvDtStaff_c::init(dEvDtStaff_c *this)

{
  this->mCurCutIdx = this->mFirstCutIdx;
  this->mTimer = 0;
  this->mWipeDirection = 0;
  this->field_0x45 = 0;
  this->field_0x44 = 0;
  this->mbIsAdvance = 2;
  this->mbNeedsAction = 0;
  this->mCurActionIdx = 0xffffffff;
  if (this->mStaffType != Camera) {
    return;
  }
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mCameraPlay = 1;
  return;
}


/* __thiscall dEvDtStaff_c::advanceCut(int) */

void __thiscall dEvDtStaff_c::advanceCut(dEvDtStaff_c *this,int param_1)

{
  this->mCurCutIdx = param_1;
  this->mTimer = 0;
  this->mWipeDirection = 0;
  this->field_0x45 = 0;
  this->field_0x44 = 0;
  this->mbIsAdvance = 1;
  this->mbNeedsAction = 0;
  this->mCurActionIdx = 0xffffffff;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dEvDtStaff_c::specialProcLight(void) */

void __thiscall dEvDtStaff_c::specialProcLight(dEvDtStaff_c *this)

{
  float fVar1;
  int staffIdx;
  ulong uVar2;
  int iVar3;
  bool bVar6;
  float *pfVar4;
  int *piVar5;
  double dVar7;
  
  staffIdx = dEvent_manager_c::getMyStaffId
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"LIGHT",
                        (fopAc_ac_c *)0x0,0);
  if (staffIdx == -1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_event_data.cpp",0x16a,"0");
    m_Do_printf::OSPanic("d_event_data.cpp",0x16a,&DAT_80352607);
  }
  else {
    iVar3 = dEvent_manager_c::getMyActIdx
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                       &d_event_data::action_table_4196,3,0,0);
    bVar6 = dEvent_manager_c::getIsAddvance
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
    if (bVar6 != false) {
      if (iVar3 == 2) {
        pfVar4 = (float *)dEvent_manager_c::getMySubstanceP
                                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                     "Hour",Float);
        if (pfVar4 != (float *)0x0) {
          fVar1 = d_event_data::_4242 *
                  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime +
                  *pfVar4;
          while (dVar7 = (double)fVar1, d_event_data::_4243 <= dVar7) {
            fVar1 = (float)(dVar7 - d_event_data::_4243);
          }
          d_kankyo::dKy_instant_timechg((double)(float)((double)d_event_data::15_0 * dVar7));
        }
      }
      else {
        if ((iVar3 < 2) && (0 < iVar3)) {
          pfVar4 = (float *)dEvent_manager_c::getMySubstanceP
                                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                       "Hour",Float);
          if (pfVar4 != (float *)0x0) {
            d_kankyo::dKy_instant_timechg((double)(d_event_data::15_0 * *pfVar4));
          }
          piVar5 = (int *)dEvent_manager_c::getMySubstanceP
                                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                     "Weather",Int);
          if ((piVar5 != (int *)0x0) && (*piVar5 == 0)) {
            d_kankyo::dKy_instant_rainchg();
          }
        }
      }
    }
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dEvDtStaff_c::specialProcMessage(void) */

void __thiscall dEvDtStaff_c::specialProcMessage(dEvDtStaff_c *this)

{
  short sVar1;
  int staffIdx;
  ulong uVar2;
  undefined4 uVar3;
  bool bVar5;
  undefined4 *puVar4;
  
  staffIdx = dEvent_manager_c::getMyStaffId
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"MESSAGE",
                        (fopAc_ac_c *)0x0,0);
  if (staffIdx == -1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_event_data.cpp",0x1c2,"0");
    m_Do_printf::OSPanic("d_event_data.cpp",0x1c2,&DAT_80352607);
  }
  else {
    uVar3 = dEvent_manager_c::getMyActIdx
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                       &d_event_data::action_table_4251,9,0,0);
    bVar5 = dEvent_manager_c::getIsAddvance
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
    if (bVar5 != false) {
      switch(uVar3) {
      case 0:
        specialProc_WaitStart(this,staffIdx);
        break;
      case 1:
        d_event_data::l_msgId_4247 = 0xffffffff;
        d_event_data::l_msg_4248 = (msg_class *)0x0;
        puVar4 = (undefined4 *)
                 dEvent_manager_c::getMySubstanceP
                           (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,"msgNo",Int
                           );
        if (puVar4 == (undefined4 *)0x0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_event_data.cpp",0x1d2,"idata");
          m_Do_printf::OSPanic("d_event_data.cpp",0x1d2,&DAT_80352607);
        }
        d_event_data::l_msgNo_4249 = *puVar4;
        this->mWipeDirection = 0;
        break;
      case 3:
      case 5:
        if (d_event_data::l_msg_4248 == (msg_class *)0x0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_event_data.cpp",0x1d8,"l_msg");
          m_Do_printf::OSPanic("d_event_data.cpp",0x1d8,&DAT_80352607);
        }
        d_event_data::l_msg_4248->mMode = 0x10;
        break;
      case 4:
        if (d_event_data::l_msg_4248 == (msg_class *)0x0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_event_data.cpp",0x1dc,"l_msg");
          m_Do_printf::OSPanic("d_event_data.cpp",0x1dc,&DAT_80352607);
        }
        d_event_data::l_msg_4248->mMode = 0xf;
        puVar4 = (undefined4 *)
                 dEvent_manager_c::getMySubstanceP
                           (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,"msgNo",Int
                           );
        if (puVar4 == (undefined4 *)0x0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_event_data.cpp",0x1df,"idata");
          m_Do_printf::OSPanic("d_event_data.cpp",0x1df,&DAT_80352607);
        }
        d_event_data::l_msgNo_4249 = *puVar4;
        f_op_msg_mng::fopMsgM_messageSet();
        break;
      case 7:
        puVar4 = (undefined4 *)
                 dEvent_manager_c::getMySubstanceP
                           (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,"tlpNo",Int
                           );
        if (puVar4 == (undefined4 *)0x0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_event_data.cpp",0x1e5,"idata");
          m_Do_printf::OSPanic("d_event_data.cpp",0x1e5,&DAT_80352607);
        }
        d_com_inf_game::g_dComIfG_gameInfo._23543_1_ = (undefined)*puVar4;
        d_com_inf_game::g_dComIfG_gameInfo._23544_1_ = '\x02';
        specialProc_WaitStart(this,staffIdx);
        break;
      case 8:
        d_com_inf_game::g_dComIfG_gameInfo._23544_1_ = '\x01';
      }
    }
    switch(uVar3) {
    case 0:
    case 7:
      specialProc_WaitProc(this,staffIdx);
      break;
    case 1:
      sVar1 = this->mWipeDirection;
      if (sVar1 == 1) {
        d_event_data::l_msg_4248 = f_op_msg_mng::fopMsgM_SearchByID(d_event_data::l_msgId_4247);
        if (d_event_data::l_msg_4248 != (msg_class *)0x0) {
          this->mWipeDirection = this->mWipeDirection + 1;
        }
      }
      else {
        if (sVar1 < 1) {
          if ((-1 < sVar1) &&
             (d_event_data::l_msgId_4247 =
                   f_op_msg_mng::fopMsgM_messageSet(d_event_data::l_msgNo_4249),
             d_event_data::l_msgId_4247 != 0xffffffff)) {
            this->mWipeDirection = this->mWipeDirection + 1;
          }
        }
        else {
          if (sVar1 < 3) {
            dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
          }
        }
      }
      break;
    case 2:
      if (d_event_data::l_msg_4248 == (msg_class *)0x0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_event_data.cpp",0x209,"l_msg");
        m_Do_printf::OSPanic("d_event_data.cpp",0x209,&DAT_80352607);
      }
      if (d_event_data::l_msg_4248->mMode == 0xe) {
        dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
      }
      break;
    case 3:
    case 6:
      if (d_event_data::l_msg_4248 == (msg_class *)0x0) {
        dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
      }
      else {
        if (d_event_data::l_msg_4248->mMode == 0x12) {
          d_event_data::l_msg_4248->mMode = 0x13;
          d_event_data::l_msgId_4247 = 0xffffffff;
          d_event_data::l_msg_4248 = (msg_class *)0x0;
          dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
        }
      }
      break;
    case 4:
      dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
      break;
    case 5:
      if (((ushort)d_event_data::l_msg_4248->mMode < 0x13) &&
         (0x10 < (ushort)d_event_data::l_msg_4248->mMode)) {
        dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
      }
      break;
    case 8:
      if (d_com_inf_game::g_dComIfG_gameInfo._23544_1_ == '\0') {
        dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
      }
      break;
    default:
      dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dEvDtStaff_c::specialProcSound(void) */

void __thiscall dEvDtStaff_c::specialProcSound(dEvDtStaff_c *this)

{
  int staffIdx;
  ulong uVar1;
  int actionIdx;
  bool bVar5;
  int *piVar2;
  void *pvVar3;
  ulong *puVar4;
  
  staffIdx = dEvent_manager_c::getMyStaffId
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"SOUND",
                        (fopAc_ac_c *)0x0,0);
  if (staffIdx == -1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_event_data.cpp",0x254,"0");
    m_Do_printf::OSPanic("d_event_data.cpp",0x254,&DAT_80352607);
  }
  else {
    actionIdx = dEvent_manager_c::getMyActIdx
                          (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                           &d_event_data::action_table_4350,8,0,0);
    bVar5 = dEvent_manager_c::getIsAddvance
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
    if (bVar5 != false) {
      switch(actionIdx) {
      case 0:
        specialProc_WaitStart(this,staffIdx);
        break;
      case 1:
        JAIZelBasic::bgmStreamPlay(JAIZelBasic::zel_basic);
        break;
      case 2:
        JAIZelBasic::bgmStreamPrepare(JAIZelBasic::zel_basic,0xc0000004);
        break;
      case 3:
        JAIZelBasic::bgmStreamPrepare(JAIZelBasic::zel_basic,0xc0000005);
        break;
      case 4:
        specialProc_WaitStart(this,staffIdx);
        break;
      case 5:
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x806,(cXyz *)0x0,0,0,d_event_data::1_0,d_event_data::1_0,
                   d_event_data::_1_0,d_event_data::_1_0,0);
        break;
      case 6:
        piVar2 = (int *)dEvent_manager_c::getMySubstanceP
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                   "PREPARE",Int);
        if (piVar2 != (int *)0x0) {
          if (6 < *piVar2) {
            uVar1 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar1,"d_event_data.cpp",0x293,"0");
            m_Do_printf::OSPanic("d_event_data.cpp",0x293,&DAT_80352607);
          }
          JAIZelBasic::prepareLandingDemo
                    (JAIZelBasic::zel_basic,
                     *(long *)(&d_event_data::landing_table_4363 + *piVar2 * 4));
        }
        pvVar3 = dEvent_manager_c::getMySubstanceP
                           (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,"START",Int
                           );
        if (pvVar3 != (void *)0x0) {
          JAIZelBasic::startLandingDemo(JAIZelBasic::zel_basic);
        }
        pvVar3 = dEvent_manager_c::getMySubstanceP
                           (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,"END",Int);
        if (pvVar3 != (void *)0x0) {
          JAIZelBasic::endLandingDemo(JAIZelBasic::zel_basic);
        }
        break;
      case 7:
        puVar4 = (ulong *)dEvent_manager_c::getMySubstanceP
                                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                     "Timer",Int);
        if (puVar4 != (ulong *)0x0) {
          JAIZelBasic::bgmStop(JAIZelBasic::zel_basic,*puVar4,0);
        }
      }
    }
    if (actionIdx == 4) {
      if ((uint)(int)this->mTimer <=
          (uint)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->field_0xd8) {
        dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
      }
    }
    else {
      if ((actionIdx < 4) && (actionIdx == 0)) {
        specialProc_WaitProc(this,staffIdx);
      }
      else {
        dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dEvDtStaff_c::specialProcCreate(void) */

void __thiscall dEvDtStaff_c::specialProcCreate(dEvDtStaff_c *this)

{
  int staffIdx;
  int iVar1;
  bool bVar5;
  char *pName;
  dStage__ObjectNameTable *pObjectName;
  ulong *puVar2;
  float *pfVar3;
  undefined4 *puVar4;
  ulong arg;
  csXyz angle;
  cXyz scale;
  cXyz pos;
  
  staffIdx = dEvent_manager_c::getMyStaffId
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"CREATER",
                        (fopAc_ac_c *)0x0,0);
  if (staffIdx == -1) {
    arg = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(arg,"d_event_data.cpp",0x2d3,"0");
    m_Do_printf::OSPanic("d_event_data.cpp",0x2d3,&DAT_80352607);
  }
  else {
    iVar1 = dEvent_manager_c::getMyActIdx
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                       &d_event_data::action_table_4428,2,0,0);
    bVar5 = dEvent_manager_c::getIsAddvance
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
    if ((bVar5 != false) && (iVar1 == 1)) {
      pName = (char *)dEvent_manager_c::getMySubstanceP
                                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                 "MAKECAST",String);
      if (pName == (char *)0x0) {
        arg = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(arg,"d_event_data.cpp",0x2e3,"name");
        m_Do_printf::OSPanic("d_event_data.cpp",0x2e3,&DAT_80352607);
      }
      pObjectName = d_stage::dStage_searchName(pName);
      if (pObjectName == (dStage__ObjectNameTable *)0x0) {
        arg = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(arg,"d_event_data.cpp",0x2e5,"objectName");
        m_Do_printf::OSPanic("d_event_data.cpp",0x2e5,&DAT_80352607);
      }
      puVar2 = (ulong *)dEvent_manager_c::getMySubstanceP
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                   "ARG",Int);
      if (puVar2 == (ulong *)0x0) {
        arg = 0xffffffff;
      }
      else {
        arg = *puVar2;
      }
      pfVar3 = (float *)dEvent_manager_c::getMySubstanceP
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                   "POS",Xyz);
      if (pfVar3 == (float *)0x0) {
        pos.x = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                mCurrent.mPos.x;
        pos.y = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                mCurrent.mPos.y;
        pos.z = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                mCurrent.mPos.z;
      }
      else {
        pos.x = *pfVar3;
        pos.y = pfVar3[1];
        pos.z = pfVar3[2];
      }
      puVar4 = (undefined4 *)
               dEvent_manager_c::getMySubstanceP
                         (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,"ANGLE",Int);
      if (puVar4 == (undefined4 *)0x0) {
        angle.x = 0;
        angle.y = 0;
        angle.z = 0;
      }
      else {
        angle.x = (short)*puVar4;
        angle.y = (short)puVar4[1];
        angle.z = (short)puVar4[2];
      }
      pfVar3 = (float *)dEvent_manager_c::getMySubstanceP
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                   "SCALE",Xyz);
      if (pfVar3 == (float *)0x0) {
        scale.x = d_event_data::1_0;
        scale.y = d_event_data::1_0;
        scale.z = d_event_data::1_0;
      }
      else {
        scale.x = *pfVar3;
        scale.y = pfVar3[1];
        scale.z = pfVar3[2];
      }
      f_op_actor_mng::fopAcM_create
                (pObjectName->mProcName,arg,&pos,(int)(char)dStage_roomControl_c::mStayNo,&angle,
                 &scale,pObjectName->mSubtype,(undefined *)0x0);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dEvDtStaff_c::specialProcDirector(void) */

void __thiscall dEvDtStaff_c::specialProcDirector(dEvDtStaff_c *this)

{
  daPy_lk_c *pdVar1;
  int iVar2;
  int staffIdx;
  ulong uVar3;
  undefined4 uVar4;
  bool bVar7;
  float *pRate;
  int *pColor;
  uchar *puVar5;
  float *pRate_;
  int *piVar6;
  _GXColor local_38;
  cXyz local_34;
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
  staffIdx = dEvent_manager_c::getMyStaffId
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"DIRECTOR",
                        (fopAc_ac_c *)0x0,0);
  if (staffIdx == -1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_event_data.cpp",0x330,"0");
    m_Do_printf::OSPanic("d_event_data.cpp",0x330,&DAT_80352607);
  }
  else {
    uVar4 = dEvent_manager_c::getMyActIdx
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                       &d_event_data::action_table_4506,9,0,0);
    bVar7 = dEvent_manager_c::getIsAddvance
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
    if (bVar7 != false) {
      switch(uVar4) {
      case 0:
        specialProc_WaitStart(this,staffIdx);
        break;
      case 1:
        d_event_data::dEvDt_Next_Stage(staffIdx,0);
        break;
      case 2:
        pRate = (float *)dEvent_manager_c::getMySubstanceP
                                   (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                    "Rate",Float);
        pColor = (int *)dEvent_manager_c::getMySubstanceP
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                   "Color",Int);
        if (pRate == (float *)0x0) {
          uVar3 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar3,"d_event_data.cpp",0x343,"rate");
          m_Do_printf::OSPanic("d_event_data.cpp",0x343,&DAT_80352607);
        }
        if (d_event_data::0_0 < *pRate) {
          mDoGph_gInf_c::mFadeRate = d_event_data::0_0;
        }
        if (pColor == (int *)0x0) {
          mDoGph_gInf_c::fadeOut(*pRate);
        }
        else {
          local_38.r = (u8)*pColor;
          local_38.g = (u8)pColor[1];
          local_38.b = (u8)pColor[2];
          local_38.a = (u8)pColor[3];
          mDoGph_gInf_c::fadeOut(*pRate,&local_38);
        }
        break;
      case 3:
        piVar6 = (int *)dEvent_manager_c::getMySubstanceP
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                   "BGM_ID",Int);
        if (piVar6 == (int *)0x0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *piVar6;
        }
        JAIZelBasic::bgmStart
                  (JAIZelBasic::zel_basic,(uint)(&d_event_data::bgm_table_4521)[iVar2],0,0);
        break;
      case 4:
        specialProc_WaitStart(this,staffIdx);
        if (this->mTimer == 0) {
          uVar3 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar3,"d_event_data.cpp",0x36b,"0");
          m_Do_printf::OSPanic("d_event_data.cpp",0x36b,&DAT_80352607);
        }
        puVar5 = (uchar *)dEvent_manager_c::getMySubstanceP
                                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                     "Pattern",Int);
        piVar6 = (int *)dEvent_manager_c::getMySubstanceP
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                   "Type",Int);
        if ((puVar5 == (uchar *)0x0) || (piVar6 == (int *)0x0)) {
          uVar3 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar3,"d_event_data.cpp",0x36f,"0");
          m_Do_printf::OSPanic("d_event_data.cpp",0x36f,&DAT_80352607);
        }
        local_34.x = d_event_data::0_0;
        local_34.y = d_event_data::1_0;
        local_34.z = d_event_data::0_0;
        dVibration_c::StartQuake
                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,puVar5,0,*piVar6,&local_34);
        break;
      case 5:
        piVar6 = (int *)dEvent_manager_c::getMySubstanceP
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                   "SENUM",Int);
        if ((piVar6 != (int *)0x0) && (*piVar6 < 1)) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,*(ulong *)(&d_event_data::se_table_4535 + *piVar6 * 4),
                     (cXyz *)0x0,0,0,d_event_data::1_0,d_event_data::1_0,d_event_data::_1_0,
                     d_event_data::_1_0,0);
        }
        break;
      case 6:
        pRate_ = (float *)dEvent_manager_c::getMySubstanceP
                                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                     "Rate",Float);
        if (pRate_ == (float *)0x0) {
          uVar3 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar3,"d_event_data.cpp",900,"rate");
          m_Do_printf::OSPanic("d_event_data.cpp",900,&DAT_80352607);
        }
        dDlst_list_c::wipeIn(-*pRate_);
        if (*pRate_ <= d_event_data::0_0) {
          this->mWipeDirection = 1;
        }
        else {
          this->mWipeDirection = 0;
        }
        piVar6 = (int *)dEvent_manager_c::getMySubstanceP
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                   "SOUND",Int);
        if ((piVar6 != (int *)0x0) && (*piVar6 == 0)) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8da,(cXyz *)0x0,0,0,d_event_data::1_0,
                     d_event_data::1_0,d_event_data::_1_0,d_event_data::_1_0,0);
        }
        break;
      case 7:
        (pdVar1->parent).field_0x29c = (pdVar1->parent).field_0x29c & 0xf7ffffff;
        break;
      case 8:
        (pdVar1->parent).field_0x29c = (pdVar1->parent).field_0x29c | 0x8000000;
      }
    }
    switch(uVar4) {
    case 0:
      specialProc_WaitProc(this,staffIdx);
      break;
    case 1:
      break;
    case 2:
      if (mDoGph_gInf_c::mFade == 0) {
        dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
      }
      else {
        if (d_event_data::1_0 <= mDoGph_gInf_c::mFadeRate) {
          pRate = (float *)dEvent_manager_c::getMySubstanceP
                                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                      "Rate",Float);
          if (pRate == (float *)0x0) {
            uVar3 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar3,"d_event_data.cpp",0x3b8,"rate");
            m_Do_printf::OSPanic("d_event_data.cpp",0x3b8,&DAT_80352607);
          }
          if (d_event_data::0_0 < *pRate) {
            dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
          }
        }
      }
      break;
    default:
      dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
      break;
    case 4:
      if (this->mTimer < 1) {
        dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
      }
      else {
        this->mTimer = this->mTimer + -1;
        if (this->mTimer == 0) {
          dVibration_c::StopQuake(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,-1);
        }
      }
      break;
    case 6:
      if (this->mWipeDirection == 0) {
        if (d_event_data::1_0 <= dDlst_list_c::mWipeRate) {
          dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
        }
      }
      else {
        if (d_event_data::0_0 == dDlst_list_c::mWipeRate) {
          dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
        }
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x800733ac) */
/* __thiscall dEvDtStaff_c::specialProcPackage(void) */

void __thiscall dEvDtStaff_c::specialProcPackage(dEvDtStaff_c *this)

{
  float fVar1;
  int staffIdx;
  ulong uVar2;
  int iVar3;
  bool bVar6;
  char *pcVar4;
  cXyz *pPos;
  float *pfVar5;
  int *mpFlag;
  uchar *puVar7;
  undefined4 uVar8;
  undefined8 in_f31;
  double dVar9;
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  staffIdx = dEvent_manager_c::getMyStaffId
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"PACKAGE",
                        (fopAc_ac_c *)0x0,0);
  if (staffIdx == -1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_event_data.cpp",0x3f2,"0");
    m_Do_printf::OSPanic("d_event_data.cpp",0x3f2,&DAT_80352607);
  }
  else {
    iVar3 = dEvent_manager_c::getMyActIdx
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                       &d_event_data::action_table_4648,3,0,0);
    bVar6 = dEvent_manager_c::getIsAddvance
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
    if (bVar6 != false) {
      if (iVar3 == 0) {
        specialProc_WaitStart(this,staffIdx);
      }
      else {
        if ((-1 < iVar3) && (iVar3 < 3)) {
          pcVar4 = (char *)dEvent_manager_c::getMySubstanceP
                                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                      "FileName",String);
          pPos = (cXyz *)dEvent_manager_c::getMySubstanceP
                                   (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                    "OffsetPos",Xyz);
          pfVar5 = (float *)dEvent_manager_c::getMySubstanceP
                                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                       "OffsetAngY",Float);
          fVar1 = d_event_data::0_0;
          if (pfVar5 != (float *)0x0) {
            fVar1 = *pfVar5;
          }
          dVar9 = (double)fVar1;
          puVar7 = (uchar *)0x0;
          if (dStage_roomControl_c::mDemoArcName[0] != '\0') {
            puVar7 = (uchar *)dRes_control_c::getRes
                                        (dStage_roomControl_c::mDemoArcName,pcVar4,
                                         d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                                         0x40);
          }
          if (puVar7 == (uchar *)0x0) {
            puVar7 = (uchar *)dRes_control_c::getRes
                                        ("Stage",pcVar4,
                                         d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40
                                        );
          }
          if (puVar7 == (uchar *)0x0) {
            uVar2 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar2,"d_event_data.cpp",0x42e,"demo_data");
            m_Do_printf::OSPanic("d_event_data.cpp",0x42e,&DAT_80352607);
          }
          dDemo_manager_c::create
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr,puVar7,pPos,(float)dVar9);
          d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mCullFarClipRatio = d_event_data::10_0;
          mpFlag = (int *)dEvent_manager_c::getMySubstanceP
                                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                                     "EventFlag",Int);
          if (mpFlag != (int *)0x0) {
            dSv_event_c::onEventBit
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,(ushort)*mpFlag);
          }
        }
      }
    }
    if (iVar3 == 0) {
      specialProc_WaitProc(this,staffIdx);
    }
    else {
      if (iVar3 < 0) {
        if (-2 < iVar3) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_event_data.cpp",0x45c,"0");
          m_Do_printf::OSPanic("d_event_data.cpp",0x45c,&DAT_80352607);
          dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
        }
      }
      else {
        if ((iVar3 < 2) && (this->mWipeDirection == 0)) {
          if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mState == 2) {
            iVar3 = d_event_data::dEvDt_Next_Stage(staffIdx,5);
            if (iVar3 == 0) {
              dDemo_manager_c::remove(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr);
            }
            else {
              this->mWipeDirection = 1;
            }
          }
          if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mState == 0) {
            dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
          }
        }
      }
    }
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dEvDtStaff_c::specialProcTimekeeper(void) */

void __thiscall dEvDtStaff_c::specialProcTimekeeper(dEvDtStaff_c *this)

{
  int staffIdx;
  ulong uVar1;
  int iVar2;
  bool bVar4;
  undefined4 *puVar3;
  
  staffIdx = dEvent_manager_c::getMyStaffId
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"TIMEKEEPER",
                        (fopAc_ac_c *)0x0,0);
  if (staffIdx == -1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_event_data.cpp",0x471,"0");
    m_Do_printf::OSPanic("d_event_data.cpp",0x471,&DAT_80352607);
  }
  else {
    iVar2 = dEvent_manager_c::getMyActIdx
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,
                       &d_event_data::action_table_4728,2,0,0);
    bVar4 = dEvent_manager_c::getIsAddvance
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
    if ((((bVar4 != false) && (iVar2 != 1)) && (iVar2 < 1)) && (-1 < iVar2)) {
      puVar3 = (undefined4 *)
               dEvent_manager_c::getMySubstanceP
                         (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx,"Timer",Int);
      if (puVar3 == (undefined4 *)0x0) {
        uVar1 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar1,"d_event_data.cpp",0x482,"idata");
        m_Do_printf::OSPanic("d_event_data.cpp",0x482,&DAT_80352607);
      }
      this->mTimer = (short)*puVar3;
    }
    if (iVar2 == 0) {
      if (this->mTimer < 1) {
        dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
      }
      else {
        this->mTimer = this->mTimer + -1;
      }
    }
    else {
      if (iVar2 < 0) {
        if (-2 < iVar2) {
          uVar1 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar1,"d_event_data.cpp",0x49f,"0");
          m_Do_printf::OSPanic("d_event_data.cpp",0x49f,&DAT_80352607);
          dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
        }
      }
      else {
        if (iVar2 < 2) {
          dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,staffIdx);
        }
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dEvDtCut_c::startCheck(void) */

int __thiscall dEvDtCut_c::startCheck(dEvDtCut_c *this)

{
  int res;
  int flag;
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  while( true ) {
    flag = *(int *)((int)this->mFlagCheck + iVar2);
    if (flag == -1) {
      if (iVar1 != 0) {
        return 1;
      }
      return -1;
    }
    res = dEvDtFlag_c::flagCheck(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mFlag,flag);
    if (res == 0) break;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 4;
    if (2 < iVar1) {
      return 1;
    }
  }
  return 0;
}


/* __thiscall dEvDtBase_c::init(void) */

int __thiscall dEvDtBase_c::init(dEvDtBase_c *this)

{
  this->mpEventData = (dEvDt__DataFile *)0x0;
  this->mpEvents = (dEvDtEvent_c *)0x0;
  this->mpStaffs = (dEvDtStaff_c *)0x0;
  this->mpCuts = (dEvDtCut_c *)0x0;
  this->mpData = (dEvDtData_c *)0x0;
  this->mpFloats = (float *)0x0;
  this->mpInts = (int *)0x0;
  this->mpStrings = (char *)0x0;
  return (int)this;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dEvDtBase_c::advanceCut(dEvDtEvent_c *) */

void __thiscall dEvDtBase_c::advanceCut(dEvDtBase_c *this,dEvDtEvent_c *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = 0; iVar1 < param_1->mStaffCount; iVar1 = iVar1 + 1) {
    advanceCutLocal(this,this->mpStaffs + *(int *)((int)param_1->mStaffIdx + iVar2));
    iVar2 = iVar2 + 4;
  }
  return;
}


/* __thiscall dEvDtBase_c::advanceCutLocal(dEvDtStaff_c *) */

undefined4 __thiscall dEvDtBase_c::advanceCutLocal(dEvDtBase_c *this,dEvDtStaff_c *pStaff)

{
  int iVar1;
  dEvDtCut_c *pCut;
  
  pCut = this->mpCuts + pStaff->mCurCutIdx;
  if (pCut->mNextCutIdx != -1) {
    iVar1 = dEvDtCut_c::startCheck(this->mpCuts + pCut->mNextCutIdx);
    if (iVar1 != 0) {
      if (iVar1 < 0) {
        if ((-2 < iVar1) &&
           (iVar1 = dEvDtFlag_c::flagCheck
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mFlag,
                               pCut->mFlagIdx), iVar1 != 0)) {
          dEvDtStaff_c::advanceCut(pStaff,pCut->mNextCutIdx);
          return 1;
        }
      }
      else {
        if (iVar1 < 2) {
          dEvDtFlag_c::flagSet
                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mFlag,pCut->mFlagIdx);
          dEvDtStaff_c::advanceCut(pStaff,pCut->mNextCutIdx);
          return 1;
        }
      }
    }
  }
  if (pStaff->mbIsAdvance < 2) {
    pStaff->mbIsAdvance = 0;
  }
  else {
    pStaff->mbIsAdvance = 1;
  }
  return 0;
}

