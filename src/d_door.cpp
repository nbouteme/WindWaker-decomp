#include <d_door.h>
#include <d_door.h>
#include <d_stage.h>
#include <SComponent/c_xyz.h>
#include <SComponent/c_angle.h>
#include <JKernel/JKRHeap.h>
#include <d_event_manager.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <mtx/vec.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <d_save.h>
#include <d_particle.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <m_Do_ext.h>
#include <d_resorce.h>
#include <J3DGraphAnimator/J3DCluster.h>
#include <J3DGraphAnimator/J3DModel.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <d_kankyo.h>
#include <SComponent/c_lib.h>
#include <f_op_msg_mng.h>
#include <d_vibration.h>
#include <dDoor_stop_c.h>
#include <dDoor_smoke_c.h>
#include <daPy_py_c.h>
#include <cSGlobe.h>
#include <dDoor_msg_c.h>
#include <dDoor_info_c.h>
#include <dDoor_key2_c.h>
#include <dDoor_hkyo_c.h>
#include <cSAngle.h>


/* __thiscall dDoor_info_c::getSwbit(void) */

uint __thiscall dDoor_info_c::getSwbit(dDoor_info_c *this)

{
  return (this->parent).parent.parent.mParameters & 0xff;
}


/* __thiscall dDoor_info_c::getSwbit2(void) */

uint __thiscall dDoor_info_c::getSwbit2(dDoor_info_c *this)

{
  return (uint)(this->parent).parent.parent.mParameters >> 0x14 & 0xff;
}


/* __thiscall dDoor_info_c::getType(void) */

uint __thiscall dDoor_info_c::getType(dDoor_info_c *this)

{
  return (uint)(this->parent).parent.parent.mParameters >> 8 & 0xf;
}


/* __thiscall dDoor_info_c::setType(unsigned char) */

void __thiscall dDoor_info_c::setType(dDoor_info_c *this,byte type)

{
  if (0xf < type) {
    return;
  }
  (this->parent).parent.parent.mParameters = (this->parent).parent.parent.mParameters & 0xfffff0ff;
  (this->parent).parent.parent.mParameters =
       (uint)type << 8 | (this->parent).parent.parent.mParameters;
  return;
}


/* __thiscall dDoor_info_c::getEventNo(void) */

uint __thiscall dDoor_info_c::getEventNo(dDoor_info_c *this)

{
  return (uint)(this->parent).parent.parent.mParameters >> 0xc & 0xff;
}


/* __thiscall dDoor_info_c::getFRoomNo(void) */

ushort __thiscall dDoor_info_c::getFRoomNo(dDoor_info_c *this)

{
  return (this->parent).mOrig.mRot.x & 0x3f;
}


/* __thiscall dDoor_info_c::getBRoomNo(void) */

uint __thiscall dDoor_info_c::getBRoomNo(dDoor_info_c *this)

{
  return (uint)(int)(this->parent).mOrig.mRot.x >> 6 & 0x3f;
}


/* __thiscall dDoor_info_c::getShipId(void) */

ushort __thiscall dDoor_info_c::getShipId(dDoor_info_c *this)

{
  return (this->parent).mOrig.mRot.z & 0x3f;
}


/* __thiscall dDoor_info_c::getArg1(void) */

uint __thiscall dDoor_info_c::getArg1(dDoor_info_c *this)

{
  return (uint)(int)(this->parent).mOrig.mRot.z >> 8 & 0xff;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDoor_info_c::adjoinPlayer(void) */

undefined4 __thiscall dDoor_info_c::adjoinPlayer(dDoor_info_c *this)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = getFRoomNo(this);
  uVar2 = getBRoomNo(this);
  if (((uVar1 & 0xff) == 0x3f) || ((uVar2 & 0xff) == 0x3f)) {
    uVar3 = 1;
  }
  else {
    iVar4 = dStage_roomControl_c::checkRoomDisp
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,uVar1 & 0xff);
    if ((iVar4 == 0) &&
       (iVar4 = dStage_roomControl_c::checkRoomDisp
                          (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,uVar2 & 0xff),
       iVar4 == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}


/* __thiscall dDoor_info_c::getViewRoomNo(void) */

int __thiscall dDoor_info_c::getViewRoomNo(dDoor_info_c *this)

{
  int iVar1;
  cXyz local_28;
  cXyz local_1c;
  
  ::cXyz::operator__(&local_28,&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mEyePos,
                     &(this->parent).mCurrent.mPos);
  local_1c.x = local_28.x;
  local_1c.y = local_28.y;
  local_1c.z = local_28.z;
  if (d_door::0_0 <= local_28.x * (this->mAngleVec).x + local_28.z * (this->mAngleVec).z) {
    iVar1 = getFRoomNo(this);
  }
  else {
    iVar1 = getBRoomNo(this);
  }
  return iVar1;
}


/* __thiscall dDoor_info_c::frontCheckOld(void) */

undefined4 __thiscall dDoor_info_c::frontCheckOld(dDoor_info_c *this)

{
  short sVar2;
  undefined4 uVar1;
  cSAngle local_28 [2];
  cSAngle local_24 [2];
  cSGlobe cStack32;
  cXyz cStack24;
  
  ::cXyz::operator__(&cStack24,
                     &((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                      mCurrent.mPos,&(this->parent).mCurrent.mPos);
  cSGlobe::cSGlobe(&cStack32,&cStack24);
  cSAngle::operator__(local_28,&cStack32.mAngleY,(this->parent).mCurrent.mRot.y);
  local_24[0] = local_28[0];
  sVar2 = cSAngle::Abs(local_24);
  if ((sVar2 < 0x4000) && (-1 < sVar2)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall cSAngle::~cSAngle(void) */

void __thiscall cSAngle::_cSAngle(cSAngle *this)

{
  short in_r4;
  
  if ((this != (cSAngle *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall cSGlobe::~cSGlobe(void) */

void __thiscall cSGlobe::_cSGlobe(cSGlobe *this)

{
  short in_r4;
  
  if ((this != (cSGlobe *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDoor_info_c::frontCheck(void) */

int __thiscall dDoor_info_c::frontCheck(dDoor_info_c *this)

{
  char roomB;
  char roomF;
  int iVar1;
  uint roomF_;
  uint roomB_;
  uint stayNo;
  
  stayNo = SEXT14((char)dStage_roomControl_c::mStayNo);
  roomB = getBRoomNo(this);
  roomF = getFRoomNo(this);
  if (roomF == roomB) {
    iVar1 = frontCheckOld(this);
  }
  else {
    roomF_ = getFRoomNo(this);
    if (stayNo == (roomF_ & 0xff)) {
      iVar1 = 0;
    }
    else {
      roomB_ = getBRoomNo(this);
      iVar1 = 2 - (uint)(stayNo == (roomB_ & 0xff));
    }
  }
  return iVar1;
}


/* __thiscall dDoor_info_c::drawCheck_local(void) */

undefined4 __thiscall dDoor_info_c::drawCheck_local(dDoor_info_c *this)

{
  dEvt__ActorCommand dVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar5;
  uint uVar4;
  
  iVar2 = adjoinPlayer(this);
  if (((iVar2 == 0) && (dVar1 = (this->parent).mEvtInfo.mCommand, dVar1 != InDemo)) &&
     (dVar1 != InDoor)) {
    uVar3 = 0;
  }
  else {
    cVar5 = getFRoomNo(this);
    if ((cVar5 == '?') || (cVar5 = getBRoomNo(this), cVar5 == '?')) {
      (this->parent).mTevStr.mRoomNo = dStage_roomControl_c::mStayNo;
    }
    else {
      iVar2 = getViewRoomNo(this);
      (this->parent).mTevStr.mRoomNo = (char)iVar2;
    }
    (this->parent).mCurrent.mRoomNo = (this->parent).mTevStr.mRoomNo;
    cVar5 = frontCheck(this);
    if (cVar5 == '\x02') {
      this->mRoomNo = 0xff;
    }
    else {
      this->mRoomNo = dStage_roomControl_c::mStayNo;
    }
    iVar2 = dStage_roomControl_c::checkRoomDisp
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                       (int)(this->parent).mTevStr.mRoomNo);
    if (iVar2 == 0) {
      uVar3 = 1;
    }
    else {
      uVar4 = getViewRoomNo(this);
      if (((uVar4 & 0xff) == 0x3f) &&
         ((cVar5 = getFRoomNo(this), cVar5 != '?' || (cVar5 = getBRoomNo(this), cVar5 != '?')))) {
        uVar3 = 1;
      }
      else {
        uVar3 = 2;
      }
    }
  }
  return uVar3;
}


/* __thiscall dDoor_info_c::drawCheck(int) */

uint __thiscall dDoor_info_c::drawCheck(dDoor_info_c *this,int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = drawCheck_local(this);
  if (iVar2 == 0) {
    (this->parent).mStatus = (this->parent).mStatus & ~AppearsOnMiniMap;
  }
  else {
    if (param_1 == 0) {
      (this->parent).mStatus = (this->parent).mStatus & 0xffffffc0 | 0x29;
    }
    else {
      (this->parent).mStatus = (this->parent).mStatus & 0xffffffc0 | 0x2a;
    }
  }
  uVar1 = countLeadingZeros(2 - iVar2);
  return uVar1 >> 5 & 0xff;
}


/* __thiscall dDoor_info_c::checkExecute(void) */

undefined4 __thiscall dDoor_info_c::checkExecute(dDoor_info_c *this)

{
  dEvt__ActorCommand dVar1;
  byte bVar4;
  undefined4 uVar2;
  int iVar3;
  
  bVar4 = frontCheck(this);
  this->mFrontCheck = bVar4;
  if (((this->parent).mStatus & 0x1000) == 0) {
    dVar1 = (this->parent).mEvtInfo.mCommand;
    if ((dVar1 == InDemo) || (dVar1 == InDoor)) {
      uVar2 = 2;
    }
    else {
      if (this->mRoomNo2 == dStage_roomControl_c::mStayNo) {
        if ((this->mFrontCheck == 2) || (iVar3 = adjoinPlayer(this), iVar3 == 0)) {
          uVar2 = 0;
        }
        else {
          uVar2 = 2;
        }
      }
      else {
        uVar2 = 0;
      }
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


/* __thiscall dDoor_info_c::startDemoProc(void) */

void __thiscall dDoor_info_c::startDemoProc(dDoor_info_c *this)

{
  daPy_lk_c *pdVar1;
  short sVar2;
  int iVar3;
  ulong uVar4;
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  iVar3 = dEvent_manager_c::getMyStaffId
                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"SHUTTER_DOOR",
                     (fopAc_ac_c *)0x0,0);
  this->mStaffId = iVar3;
  (this->parent).mCollisionRot.y = (this->parent).mCurrent.mRot.y;
  if (pdVar1 == (daPy_lk_c *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_door.cpp",0x112,"player");
    m_Do_printf::OSPanic("d_door.cpp",0x112,&DAT_80351eff);
  }
  sVar2 = (pdVar1->parent).parent.mOrig.mRot.y - (this->parent).mOrig.mRot.y;
  if (sVar2 < 0) {
    sVar2 = -sVar2;
  }
  if ((sVar2 < 0x1000) && (-1000 < sVar2)) {
    (this->parent).mCollisionRot.y = (this->parent).mCollisionRot.y + 0x7fff;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dDoor_info_c::makeEventId(int) */

void __thiscall dDoor_info_c::makeEventId(dDoor_info_c *this,int param_1)

{
  byte eventInfoIdx;
  undefined uVar3;
  undefined2 uVar1;
  short sVar2;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = 0;
  iVar6 = 0;
  iVar5 = 0;
  do {
    eventInfoIdx = getEventNo(this);
    uVar3 = dEvent_manager_c::getToolId
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,eventInfoIdx,iVar4);
    *(undefined *)((int)&this->field_0x2b8 + iVar4 + 2) = uVar3;
    uVar1 = dEvent_manager_c::getEventIdx
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                       *(char **)((int)&d_door::table_4415 + iVar5),
                       *(uchar *)((int)&this->field_0x2b8 + iVar4 + 2));
    *(undefined2 *)(&this->field_0x2a2 + iVar6) = uVar1;
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 2;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 0xc);
  if (param_1 == 2) {
    uVar1 = dEvent_manager_c::getEventIdx
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"DEFAULT_SHUTTER_DOOR_12"
                       ,this->field_0x2bc);
    *(undefined2 *)((int)&this->field_0x2a4 + 2) = uVar1;
    sVar2 = dEvent_manager_c::getEventIdx
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"DEFAULT_SHUTTER_DOOR_12"
                       ,this->field_0x2bd);
    this->field_0x2a8 = sVar2;
  }
  else {
    if ((param_1 < 2) && (0 < param_1)) {
      uVar1 = dEvent_manager_c::getEventIdx
                        (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                         "DEFAULT_SHUTTER_DOOR_10",this->field_0x2bc);
      *(undefined2 *)((int)&this->field_0x2a4 + 2) = uVar1;
      sVar2 = dEvent_manager_c::getEventIdx
                        (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                         "DEFAULT_SHUTTER_DOOR_10",this->field_0x2bd);
      this->field_0x2a8 = sVar2;
    }
  }
  return;
}


/* __thiscall dDoor_info_c::initProc(int) */

void __thiscall dDoor_info_c::initProc(dDoor_info_c *this,int param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = (int)((int)(this->parent).mOrig.mRot.y & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar1 = JKernel::JMath::jmaCosTable[iVar2];
  (this->mAngleVec).x = JKernel::JMath::jmaSinTable[iVar2];
  (this->mAngleVec).y = d_door::0_0;
  (this->mAngleVec).z = fVar1;
  makeEventId(this,param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDoor_info_c::initOpenDemo(int) */

void __thiscall dDoor_info_c::initOpenDemo(dDoor_info_c *this,int param_1)

{
  int iVar1;
  
  if (*(char *)((int)&this->field_0x2c4 + 2) != '\t') {
    dMap_c::mAGBMapSendStopFlg = 1;
  }
  (this->parent).mCollisionRot.y = (this->parent).mCurrent.mRot.y;
  if (this->mFrontCheck == 1) {
    (this->parent).mCollisionRot.y = (this->parent).mCollisionRot.y + 0x7fff;
  }
  iVar1 = dEvent_manager_c::getMyStaffId
                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"SHUTTER_DOOR",
                     (fopAc_ac_c *)0x0,0);
  this->mStaffId = iVar1;
  if (param_1 != 0) {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags | 2;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8006bd94) */
/* WARNING: Removing unreachable block (ram,0x8006bd84) */
/* WARNING: Removing unreachable block (ram,0x8006bd8c) */
/* WARNING: Removing unreachable block (ram,0x8006bd9c) */
/* __thiscall dDoor_info_c::checkArea(float,
                                      float,
                                      float) */

undefined4 __thiscall
dDoor_info_c::checkArea(dDoor_info_c *this,float param_1,float param_2,float param_3)

{
  daPy_lk_c *pdVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar10;
  cXyz local_78;
  cXyz cStack108;
  cXyz local_60;
  float local_54;
  float local_50;
  float local_4c;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  dVar8 = (double)param_3;
  dVar9 = (double)param_2;
  dVar6 = (double)param_1;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  ::cXyz::operator__(&local_60,
                     &((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                      mCurrent.mPos,&(this->parent).mCurrent.mPos);
  local_54 = local_60.x;
  local_50 = local_60.y;
  local_4c = local_60.z;
  local_78.x = local_60.x;
  local_78.y = d_door::0_0;
  local_78.z = local_60.z;
  fVar10 = mtx::PSVECSquareMag(&local_78);
  dVar7 = (double)fVar10;
  if (dVar7 <= dVar8) {
    ::cXyz::normalize(&cStack108);
    dVar8 = (double)(local_54 * (this->mAngleVec).x + local_4c * (this->mAngleVec).z);
    dVar8 = (double)(float)(dVar8 * (double)(float)(dVar7 * dVar8));
    if (dVar8 <= dVar9) {
      if ((double)(float)(dVar7 - dVar8) <= dVar6) {
        sVar2 = (this->parent).mCurrent.mRot.y;
        if (this->mFrontCheck == 1) {
          sVar2 = sVar2 + 0x7fff;
        }
        iVar4 = MSL_C.PPCEABI.bare.H::abs
                          ((int)(short)(sVar2 - (pdVar1->parent).parent.mCurrent.mRot.y));
        if (iVar4 < 0x5000) {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  __psq_l0(auStack56,uVar5);
  __psq_l1(auStack56,uVar5);
  return uVar3;
}


/* __thiscall dDoor_info_c::openInitCom(int) */

void __thiscall dDoor_info_c::openInitCom(dDoor_info_c *this,int param_1)

{
  byte bVar1;
  char cVar2;
  undefined uVar3;
  uint uVar4;
  
  if (this->mFrontCheck == 0) {
    bVar1 = getFRoomNo(this);
    this->mFRoomNo = bVar1;
    bVar1 = getBRoomNo(this);
    this->mBRoomNo = bVar1;
  }
  else {
    bVar1 = getBRoomNo(this);
    this->mFRoomNo = bVar1;
    bVar1 = getFRoomNo(this);
    this->mBRoomNo = bVar1;
  }
  uVar4 = (uint)this->mBRoomNo;
  if (((this->mFRoomNo != uVar4) && (this->mFRoomNo != 0x3f)) && (uVar4 != 0x3f)) {
    dStage_roomControl_c::mStatus[uVar4].mFlags =
         dStage_roomControl_c::mStatus[uVar4].mFlags & ~Hidden;
  }
  if ((param_1 != 0) && (cVar2 = getShipId(this), cVar2 != '?')) {
    uVar3 = getShipId(this);
    d_stage::dStage_setShipPos(uVar3,this->mBRoomNo);
  }
  return;
}


/* __thiscall dDoor_info_c::openProcCom(void) */

void __thiscall dDoor_info_c::openProcCom(dDoor_info_c *this)

{
  int iVar1;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_14 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent.
             mPos.y;
  local_8 = (this->parent).mCurrent.mPos.y;
  iVar1 = (int)((int)(this->parent).mCollisionRot.y + 0x7fffU & 0xffff) >>
          (JKernel::JMath::jmaSinShift & 0x3f);
  local_c = (this->parent).mCurrent.mPos.x + d_door::_4572 * JKernel::JMath::jmaSinTable[iVar1];
  local_4 = (this->parent).mCurrent.mPos.z + d_door::_4572 * JKernel::JMath::jmaCosTable[iVar1];
  local_18 = d_door::_4573 *
             ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent.
             mPos.x + d_door::_4574 * local_c;
  local_10 = d_door::_4573 *
             ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent.
             mPos.z + d_door::_4574 * local_4;
  (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->vtbl->setPlayerPosAndAngle1
  )(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor,&local_18,
    (int)((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent.mRot.
         y);
  return;
}


/* __thiscall dDoor_info_c::closeEndCom(void) */

void __thiscall dDoor_info_c::closeEndCom(dDoor_info_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  daPy_lk_c *pdVar5;
  uint uVar6;
  short sVar7;
  cXyz local_38;
  cXyz local_2c;
  float local_20;
  float local_1c;
  float local_18;
  
  uVar6 = (uint)this->mFRoomNo;
  if (((uVar6 != this->mBRoomNo) && (uVar6 != 0x3f)) && (this->mBRoomNo != 0x3f)) {
    dStage_roomControl_c::mStatus[uVar6].mFlags =
         dStage_roomControl_c::mStatus[uVar6].mFlags | Hidden;
  }
  pdVar5 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  ::cXyz::operator__(&local_38,
                     &((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                      mCurrent.mPos,&(this->parent).mCurrent.mPos);
  local_20 = local_38.x;
  local_1c = local_38.y;
  local_18 = local_38.z;
  fVar1 = (this->mAngleVec).x;
  fVar2 = (this->mAngleVec).z;
  fVar4 = local_38.x * fVar1 + local_38.z * fVar2;
  fVar3 = d_door::_4620;
  if (fVar4 < d_door::0_0) {
    fVar3 = d_door::_4619;
  }
  local_2c.z = (this->parent).mCurrent.mPos.z - fVar3 * fVar2;
  local_2c.y = (this->parent).mCurrent.mPos.y;
  local_2c.x = (this->parent).mCurrent.mPos.x - fVar3 * fVar1;
  if (fVar4 <= d_door::0_0) {
    sVar7 = (this->parent).mCurrent.mRot.y + -0x8000;
  }
  else {
    sVar7 = (this->parent).mCurrent.mRot.y;
  }
  dSv_restart_c::setRoom
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart,&local_2c,sVar7,
             (pdVar5->parent).parent.mCurrent.mRoomNo);
  return;
}


/* __thiscall dDoor_info_c::getDemoAction(void) */

int __thiscall dDoor_info_c::getDemoAction(dDoor_info_c *this)

{
  int iVar1;
  
  iVar1 = dEvent_manager_c::getMyActIdx
                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffId,
                     &d_door::action_table_4624,0x16,0,0);
  return iVar1;
}


/* __thiscall dDoor_info_c::setGoal(void) */

void __thiscall dDoor_info_c::setGoal(dDoor_info_c *this)

{
  int iVar1;
  cXyz local_c;
  
  local_c.y = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent.
              mPos.y;
  iVar1 = (int)((int)(this->parent).mCollisionRot.y + 0x7fffU & 0xffff) >>
          (JKernel::JMath::jmaSinShift & 0x3f);
  local_c.x = d_door::0_8 *
              (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent
               .mPos.x + d_door::350_0 * JKernel::JMath::jmaSinTable[iVar1]) +
              d_door::0_2 *
              ((this->parent).mCurrent.mPos.x + d_door::250_0 * JKernel::JMath::jmaSinTable[iVar1]);
  local_c.z = d_door::0_8 *
              (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent
               .mPos.z + d_door::350_0 * JKernel::JMath::jmaCosTable[iVar1]) +
              d_door::0_2 *
              ((this->parent).mCurrent.mPos.z + d_door::250_0 * JKernel::JMath::jmaCosTable[iVar1]);
  dEvent_manager_c::setGoal(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,&local_c);
  return;
}


/* __thiscall dDoor_info_c::setPlayerAngle(int) */

void __thiscall dDoor_info_c::setPlayerAngle(dDoor_info_c *this,int param_1)

{
  short sVar1;
  
  sVar1 = (this->parent).mCollisionRot.y;
  if (param_1 != 0) {
    sVar1 = sVar1 + 0x7fff;
  }
  (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x306 = sVar1;
  return;
}


/* __thiscall dDoor_info_c::setPosAndAngle(cXyz *,
                                           short) */

void __thiscall dDoor_info_c::setPosAndAngle(dDoor_info_c *this,cXyz *param_1,short param_2)

{
  float fVar1;
  dEvt__ActorCommand dVar2;
  int iVar3;
  
  dVar2 = (this->parent).mEvtInfo.mCommand;
  if (dVar2 == InDemo) {
    return;
  }
  if (dVar2 == InDoor) {
    return;
  }
  if (param_1 != (cXyz *)0x0) {
    (this->parent).mCurrent.mPos.x = param_1->x;
    (this->parent).mCurrent.mPos.y = param_1->y;
    (this->parent).mCurrent.mPos.z = param_1->z;
    (this->parent).mAttentionPos.x = (this->parent).mCurrent.mPos.x;
    (this->parent).mAttentionPos.y = (this->parent).mCurrent.mPos.y;
    (this->parent).mAttentionPos.z = (this->parent).mCurrent.mPos.z;
    (this->parent).mAttentionPos.y = (this->parent).mAttentionPos.y + d_door::_4689;
    (this->parent).mEyePos.x = (this->parent).mAttentionPos.x;
    (this->parent).mEyePos.y = (this->parent).mAttentionPos.y;
    (this->parent).mEyePos.z = (this->parent).mAttentionPos.z;
  }
  (this->parent).mCurrent.mRot.y = param_2;
  (this->parent).mCollisionRot.y = (this->parent).mCurrent.mRot.y;
  iVar3 = (int)((int)(this->parent).mCurrent.mRot.y & 0xffffU) >>
          (JKernel::JMath::jmaSinShift & 0x3f);
  fVar1 = JKernel::JMath::jmaCosTable[iVar3];
  (this->mAngleVec).x = JKernel::JMath::jmaSinTable[iVar3];
  (this->mAngleVec).y = d_door::0_0;
  (this->mAngleVec).z = fVar1;
  return;
}


/* __thiscall dDoor_smoke_c::smokeInit(dDoor_info_c *) */

void __thiscall dDoor_smoke_c::smokeInit(dDoor_smoke_c *this,dDoor_info_c *param_1)

{
  float fVar1;
  JPABaseEmitter *pJVar2;
  
  this->field_0x28 = (param_1->parent).mCurrent.mPos.x;
  this->field_0x2c = (param_1->parent).mCurrent.mPos.y;
  this->field_0x30 = (param_1->parent).mCurrent.mPos.z;
  this->field_0x22 = (param_1->parent).mCollisionRot.y;
  pJVar2 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x2022,
                              (cXyz *)&this->field_0x28,(csXyz *)&this->field_0x20,(cXyz *)0x0,0xaa,
                              (dPa_levelEcallBack *)this,(param_1->parent).mCurrent.mRoomNo,
                              (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  this->field_0x34 = '\0';
  this->field_0x35 = 0;
  if (pJVar2 != (JPABaseEmitter *)0x0) {
    pJVar2->mRate = d_door::_4718;
    pJVar2->mSpread = d_door::_4719;
    fVar1 = d_door::_4720;
    (pJVar2->mGlobalScale).x = d_door::_4720;
    (pJVar2->mGlobalScale).y = fVar1;
    (pJVar2->mGlobalScale).z = fVar1;
    (pJVar2->mGlobalScale2D).x = fVar1;
    (pJVar2->mGlobalScale2D).y = fVar1;
    (pJVar2->mGlobalScale2D).z = fVar1;
  }
  return;
}


/* __thiscall dDoor_smoke_c::smokeProc(dDoor_info_c *) */

void __thiscall dDoor_smoke_c::smokeProc(dDoor_smoke_c *this,dDoor_info_c *param_1)

{
  float fVar1;
  
  if (this->field_0x35 == 0) {
    this->field_0x35 = 1;
  }
  else {
    fVar1 = d_door::_4733;
    if ((this->field_0x34 & 1U) != 0) {
      fVar1 = d_door::_4732;
    }
    fVar1 = (float)((double)CONCAT44(0x43300000,(uint)(byte)this->field_0x34 * 0x14 ^ 0x80000000) -
                   d_door::_4735) * fVar1;
    this->field_0x34 = this->field_0x34 + '\x01';
    this->field_0x28 = this->field_0x28 + fVar1 * (param_1->mAngleVec).z;
    this->field_0x30 = this->field_0x30 + fVar1 * (param_1->mAngleVec).x;
  }
  return;
}


/* __thiscall dDoor_smoke_c::smokeEnd(void) */

void __thiscall dDoor_smoke_c::smokeEnd(dDoor_smoke_c *this)

{
  (*(code *)this->vtbl->end)();
  return;
}


/* __thiscall dDoor_key2_c::keyResLoad(void) */

void __thiscall dDoor_key2_c::keyResLoad(dDoor_key2_c *this)

{
  d_com_inf_game::dComIfG_resLoad(&this->field_0x18,"Key");
  return;
}


/* __thiscall dDoor_key2_c::keyResDelete(void) */

void __thiscall dDoor_key2_c::keyResDelete(dDoor_key2_c *this)

{
  d_com_inf_game::dComIfG_resDelete(&this->field_0x18,"Key");
  return;
}


/* __thiscall dDoor_key2_c::keyInit(dDoor_info_c *) */

void __thiscall dDoor_key2_c::keyInit(dDoor_key2_c *this,dDoor_info_c *param_1)

{
  byte bVar2;
  uint uVar1;
  sbyte sVar3;
  
  if (((this->mpModel == (J3DModel *)0x0) || (this->mbEnabled == 0)) || (param_1->mFrontCheck != 0))
  {
    this->field_0x20 = 0;
  }
  else {
    bVar2 = dDoor_info_c::getSwbit(param_1);
    if (bVar2 < 0x80) {
      uVar1 = dDoor_info_c::getSwbit(param_1);
      dSv_info_c::onSwitch(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,uVar1 & 0xff,-1);
    }
    if (this->mbIsBossDoor == 0) {
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48d4 =
           d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48d4 + -1;
    }
    if (this->mbIsBossDoor == 1) {
      sVar3 = d_com_inf_game::dComIfGp_getReverb((int)(char)(param_1->parent).mCurrent.mRoomNo);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x69ae,&(param_1->parent).mEyePos,0,sVar3,d_door::_4732,
                 d_door::_4732,d_door::_4733,d_door::_4733,0);
    }
    else {
      sVar3 = d_com_inf_game::dComIfGp_getReverb((int)(char)(param_1->parent).mCurrent.mRoomNo);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x6948,&(param_1->parent).mEyePos,0,sVar3,d_door::_4732,
                 d_door::_4732,d_door::_4733,d_door::_4733,0);
    }
    this->field_0x20 = 1;
  }
  return;
}


/* __thiscall dDoor_key2_c::keyProc(void) */

undefined4 __thiscall dDoor_key2_c::keyProc(dDoor_key2_c *this)

{
  int iVar1;
  undefined4 uVar2;
  
  if (this->field_0x20 == 0) {
    uVar2 = 1;
  }
  else {
    iVar1 = ::mDoExt_baseAnm::play(&(this->mBckAnim).parent);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      keyOff(this);
      this->field_0x20 = 0;
      uVar2 = 1;
    }
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDoor_key2_c::keyCreate_Nkey(void) */

bool __thiscall dDoor_key2_c::keyCreate_Nkey(dDoor_key2_c *this)

{
  J3DModelData *pModel;
  ulong uVar1;
  J3DModel *pJVar2;
  J3DAnmTransform *pJVar3;
  int iVar4;
  bool bVar5;
  
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     ("Key",9,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pModel == (J3DModelData *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_door.cpp",0x2cc,"modelData != 0");
    m_Do_printf::OSPanic("d_door.cpp",0x2cc,&DAT_80351eff);
  }
  pJVar2 = m_Do_ext::mDoExt_J3DModel__create(pModel,0,0x11020203);
  this->mpModel = pJVar2;
  if (this->mpModel == (J3DModel *)0x0) {
    bVar5 = false;
  }
  else {
    pJVar3 = (J3DAnmTransform *)
             dRes_control_c::getRes
                       ("Key",5,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    iVar4 = ::mDoExt_bckAnm::init(&this->mBckAnim,pModel,pJVar3,true,Once,d_door::_4732,0,-1,false);
    bVar5 = iVar4 != 0;
  }
  return bVar5;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDoor_key2_c::keyCreate_Bkey(void) */

undefined4 __thiscall dDoor_key2_c::keyCreate_Bkey(dDoor_key2_c *this)

{
  J3DModelData *pModel;
  ulong uVar1;
  J3DModel *pJVar2;
  undefined4 uVar3;
  J3DAnmTransform *pJVar4;
  int iVar5;
  J3DSkinDeform *this_00;
  
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     ("Key",8,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pModel == (J3DModelData *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_door.cpp",0x2e4,"modelData != 0");
    m_Do_printf::OSPanic("d_door.cpp",0x2e4,&DAT_80351eff);
  }
  pJVar2 = m_Do_ext::mDoExt_J3DModel__create(pModel,0,0x11020203);
  this->mpModel = pJVar2;
  if (this->mpModel == (J3DModel *)0x0) {
    uVar3 = 0;
  }
  else {
    pJVar4 = (J3DAnmTransform *)
             dRes_control_c::getRes
                       ("Key",4,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    iVar5 = ::mDoExt_bckAnm::init(&this->mBckAnim,pModel,pJVar4,true,Once,d_door::_4732,0,-1,false);
    if (iVar5 == 0) {
      uVar3 = 0;
    }
    else {
      this_00 = (J3DSkinDeform *)JKernel::operator_new(0x18);
      if (this_00 != (J3DSkinDeform *)0x0) {
        J3DSkinDeform::J3DSkinDeform(this_00);
      }
      if (this_00 == (J3DSkinDeform *)0x0) {
        uVar3 = 0;
      }
      else {
        iVar5 = J3DModel::setSkinDeform(this->mpModel,this_00,1);
        if (iVar5 == 4) {
          uVar3 = 0;
        }
        else {
          if ((3 < iVar5) || (iVar5 != 0)) {
            uVar1 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar1,"d_door.cpp",0x306,"0");
            m_Do_printf::OSPanic("d_door.cpp",0x306,&DAT_80351eff);
          }
          uVar3 = 1;
        }
      }
    }
  }
  return uVar3;
}


/* __thiscall dDoor_key2_c::keyCreate(int) */

void __thiscall dDoor_key2_c::keyCreate(dDoor_key2_c *this,int isBossDoor)

{
  this->mbIsBossDoor = (byte)isBossDoor;
  if (isBossDoor == 1) {
    keyCreate_Bkey(this);
  }
  else {
    keyCreate_Nkey(this);
  }
  return;
}


/* __thiscall dDoor_key2_c::keyOn(void) */

void __thiscall dDoor_key2_c::keyOn(dDoor_key2_c *this)

{
  this->mbEnabled = 1;
  return;
}


/* __thiscall dDoor_key2_c::keyOff(void) */

void __thiscall dDoor_key2_c::keyOff(dDoor_key2_c *this)

{
  this->mbEnabled = 0;
  return;
}


/* __thiscall dDoor_key2_c::calcMtx(dDoor_info_c *) */

void __thiscall dDoor_key2_c::calcMtx(dDoor_key2_c *this,dDoor_info_c *param_1)

{
  if (this->mbEnabled != 0) {
    mtx::PSMTXTrans((double)(param_1->parent).mCurrent.mPos.x,
                    (double)(param_1->parent).mCurrent.mPos.y,
                    (double)(param_1->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,(param_1->parent).mCurrent.mRot.y);
    if (this->mbIsBossDoor == 1) {
      mDoMtx_stack_c::transM(d_door::0_0,d_door::_4854,d_door::_4855);
    }
    else {
      mDoMtx_stack_c::transM(d_door::0_0,d_door::_4689,d_door::_4855);
    }
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,&this->mpModel->mBaseMtx);
  }
  return;
}


/* __thiscall dDoor_key2_c::draw(dDoor_info_c *) */

void __thiscall dDoor_key2_c::draw(dDoor_key2_c *this,dDoor_info_c *param_1)

{
  J3DModelData *pJVar1;
  
  pJVar1 = this->mpModel->mpModelData;
  dScnKy_env_light_c::setLightTevColorType
            (&d_kankyo::g_env_light,this->mpModel,&(param_1->parent).mTevStr);
  ::mDoExt_bckAnm::entry(&this->mBckAnim,pJVar1,((this->mBckAnim).parent.mpFrameCtrl)->mCurrentTime)
  ;
  m_Do_ext::mDoExt_modelUpdateDL(this->mpModel);
  return;
}


/* __thiscall dDoor_stop_c::calcMtx(dDoor_info_c *) */

void __thiscall dDoor_stop_c::calcMtx(dDoor_stop_c *this,dDoor_info_c *door)

{
  if ((this->field_0x8 != 0) && (this->mpModel != (J3DModel *)0x0)) {
    mtx::PSMTXTrans((double)(door->parent).mCurrent.mPos.x,
                    (double)((door->parent).mCurrent.mPos.y + this->field_0x4),
                    (double)(door->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,(door->parent).mCurrent.mRot.y);
    if (this->mFrontCheck == 1) {
      m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,0x7fff);
    }
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,&this->mpModel->mBaseMtx);
  }
  return;
}


/* __thiscall dDoor_stop_c::closeInit(dDoor_info_c *) */

void __thiscall dDoor_stop_c::closeInit(dDoor_stop_c *this,dDoor_info_c *param_1)

{
  char cVar1;
  sbyte sVar2;
  
  this->field_0x4 = d_door::_4905;
  (param_1->parent).mVelocityFwd = d_door::0_0;
  cVar1 = dDoor_info_c::getArg1(param_1);
  if (cVar1 == '\x11') {
    sVar2 = d_com_inf_game::dComIfGp_getReverb((int)(char)(param_1->parent).mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x697c,&(param_1->parent).mEyePos,0,sVar2,d_door::_4732,
               d_door::_4732,d_door::_4733,d_door::_4733,0);
  }
  else {
    sVar2 = d_com_inf_game::dComIfGp_getReverb((int)(char)(param_1->parent).mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x6906,&(param_1->parent).mEyePos,0,sVar2,d_door::_4732,
               d_door::_4732,d_door::_4733,d_door::_4733,0);
  }
  this->field_0xb = 1;
  return;
}


/* __thiscall dDoor_stop_c::closeProc(dDoor_info_c *) */

undefined4 __thiscall dDoor_stop_c::closeProc(dDoor_stop_c *this,dDoor_info_c *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (this->field_0xb == 0) {
    uVar1 = 1;
  }
  else {
    SComponent::cLib_chaseF(&(param_1->parent).mVelocityFwd,d_door::_4914,d_door::_4915);
    iVar2 = SComponent::cLib_chaseF(&this->field_0x4,d_door::0_0,(param_1->parent).mVelocityFwd);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      this->field_0xb = 0;
      uVar1 = 2;
    }
  }
  return uVar1;
}


/* __thiscall dDoor_stop_c::openInit(dDoor_info_c *) */

void __thiscall dDoor_stop_c::openInit(dDoor_stop_c *this,dDoor_info_c *param_1)

{
  float fVar1;
  char cVar2;
  sbyte sVar3;
  
  fVar1 = d_door::0_0;
  this->field_0x4 = d_door::0_0;
  (param_1->parent).mVelocityFwd = fVar1;
  cVar2 = dDoor_info_c::getArg1(param_1);
  if (cVar2 == '\x11') {
    sVar3 = d_com_inf_game::dComIfGp_getReverb((int)(char)(param_1->parent).mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x697d,&(param_1->parent).mEyePos,0,sVar3,d_door::_4732,
               d_door::_4732,d_door::_4733,d_door::_4733,0);
  }
  else {
    sVar3 = d_com_inf_game::dComIfGp_getReverb((int)(char)(param_1->parent).mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x6906,&(param_1->parent).mEyePos,0,sVar3,d_door::_4732,
               d_door::_4732,d_door::_4733,d_door::_4733,0);
  }
  this->field_0xb = 1;
  return;
}


/* __thiscall dDoor_stop_c::openProc(dDoor_info_c *) */

undefined4 __thiscall dDoor_stop_c::openProc(dDoor_stop_c *this,dDoor_info_c *door)

{
  undefined4 uVar1;
  int iVar2;
  
  if (this->field_0xb == 0) {
    uVar1 = 1;
  }
  else {
    SComponent::cLib_chaseF(&(door->parent).mVelocityFwd,d_door::_4941,d_door::_4942);
    iVar2 = SComponent::cLib_chaseF(&this->field_0x4,d_door::_4905,(door->parent).mVelocityFwd);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      this->field_0xb = 0;
      this->field_0x8 = 0;
      uVar1 = 2;
    }
  }
  return uVar1;
}


/* __thiscall dDoor_stop_c::create(void) */

undefined4 __thiscall dDoor_stop_c::create(dDoor_stop_c *this)

{
  J3DModelData *pModel;
  J3DModel *pJVar1;
  
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     ("Stage","stop10.bmd",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,
                      0x40);
  if (pModel == (J3DModelData *)0x0) {
    pModel = (J3DModelData *)
             dRes_control_c::getRes
                       ("Stage","stop10.bdl",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,
                        0x40);
  }
  if (pModel != (J3DModelData *)0x0) {
    pJVar1 = m_Do_ext::mDoExt_J3DModel__create(pModel,0,0x11020203);
    this->mpModel = pJVar1;
    if (this->mpModel == (J3DModel *)0x0) {
      return 0;
    }
  }
  return 1;
}


/* __thiscall dDoor_msg_c::init(short) */

int __thiscall dDoor_msg_c::init(dDoor_msg_c *this,EVP_PKEY_CTX *ctx)

{
  this->field_0xa = (short)ctx;
  this->field_0x0 = 0xffffffff;
  this->mMsg = 0;
  this->field_0x8 = '\0';
  return (int)this;
}


/* WARNING: Removing unreachable block (ram,0x8006ced8) */
/* __thiscall dDoor_msg_c::proc(cXyz *) */

undefined4 __thiscall dDoor_msg_c::proc(dDoor_msg_c *this,cXyz *param_1)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  msg_class *pmVar4;
  ulong uVar5;
  int iVar6;
  undefined4 uVar7;
  cXyz *extraout_r4;
  cXyz local_18;
  
  bVar1 = this->field_0x8;
  if (bVar1 == 2) {
    if (this->mMsg == 0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_door.cpp",0x3ba,"m_msg");
      m_Do_printf::OSPanic("d_door.cpp",0x3ba,&DAT_80351eff);
    }
    if (*(short *)(this->mMsg + 0xf8) == 6) {
      sVar2 = this->field_0xa;
      if ((sVar2 == 0x1bbd) || ((sVar2 < 0x1bbd && (sVar2 == 0x6a8)))) {
        local_18.x = d_door::0_0;
        local_18.y = d_door::_4732;
        local_18.z = d_door::0_0;
        dVibration_c::StartShock
                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,7,-0x21,&local_18);
      }
      this->field_0x8 = this->field_0x8 + '\x01';
    }
    goto LAB_8006d09c;
  }
  if (bVar1 < 2) {
    if (bVar1 == 0) {
      uVar3 = f_op_msg_mng::fopMsgM_messageSet((int)this->field_0xa);
      this->field_0x0 = uVar3;
      if (this->field_0x0 != 0xffffffff) {
        this->field_0x8 = this->field_0x8 + '\x01';
      }
    }
    else {
      pmVar4 = f_op_msg_mng::fopMsgM_SearchByID(this->field_0x0);
      this->mMsg = (int)pmVar4;
      if (this->mMsg != 0) {
        this->field_0x8 = this->field_0x8 + '\x01';
      }
    }
    goto LAB_8006d09c;
  }
  if (3 < bVar1) goto LAB_8006d09c;
  if (this->mMsg == 0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_door.cpp",0x3ca,"m_msg");
    m_Do_printf::OSPanic("d_door.cpp",0x3ca,&DAT_80351eff);
    param_1 = extraout_r4;
  }
  if (*(short *)(this->mMsg + 0xf8) != 0xe) goto LAB_8006d09c;
  sVar2 = this->field_0xa;
  if (sVar2 < 0x1bc0) {
    if (sVar2 == 0x1bbd) {
LAB_8006d060:
      this->field_0xa = this->field_0xa + 1;
      *(undefined2 *)(this->mMsg + 0xf8) = 0xf;
      f_op_msg_mng::fopMsgM_messageSet((int)this->field_0xa,param_1);
      goto LAB_8006d09c;
    }
  }
  else {
    if (sVar2 < 0x1bc3) goto LAB_8006d060;
  }
  this->field_0x8 = this->field_0x8 + '\x01';
  *(undefined2 *)(this->mMsg + 0xf8) = 0x10;
LAB_8006d09c:
  iVar6 = this->mMsg;
  if ((iVar6 == 0) || (*(short *)(iVar6 + 0xf8) != 0x12)) {
    uVar7 = 0;
  }
  else {
    *(undefined2 *)(iVar6 + 0xf8) = 0x13;
    uVar7 = 1;
  }
  return uVar7;
}


/* __thiscall dDoor_hkyo_c::resLoad(void) */

PhaseState __thiscall dDoor_hkyo_c::resLoad(dDoor_hkyo_c *this)

{
  PhaseState PVar1;
  
  if (this[0x11] == (dDoor_hkyo_c)0x0) {
    PVar1 = cPhs_COMPLEATE_e;
  }
  else {
    PVar1 = d_com_inf_game::dComIfG_resLoad((request_of_phase_process_class *)this,"Hkyo");
  }
  return PVar1;
}


/* __thiscall dDoor_hkyo_c::resDelete(void) */

void __thiscall dDoor_hkyo_c::resDelete(dDoor_hkyo_c *this)

{
  if (this[0x11] != (dDoor_hkyo_c)0x0) {
    d_com_inf_game::dComIfG_resDelete((request_of_phase_process_class *)this,"Hkyo");
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDoor_hkyo_c::create(void) */

bool __thiscall dDoor_hkyo_c::create(dDoor_hkyo_c *this)

{
  J3DModelData *pModel;
  ulong uVar1;
  J3DModel *pJVar2;
  undefined **ppuVar3;
  J3DAnmTevRegKey *pJVar4;
  int iVar5;
  bool bVar6;
  
  if (this[0x11] == (dDoor_hkyo_c)0x0) {
    bVar6 = true;
  }
  else {
    pModel = (J3DModelData *)
             dRes_control_c::getRes
                       ("Hkyo",4,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pModel == (J3DModelData *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_door.cpp",0x41c,"modelData != 0");
      m_Do_printf::OSPanic("d_door.cpp",0x41c,&DAT_80351eff);
    }
    pJVar2 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11000202);
    *(J3DModel **)(this + 8) = pJVar2;
    if (*(int *)(this + 8) == 0) {
      bVar6 = false;
    }
    else {
      ppuVar3 = (undefined **)JKernel::operator_new(0x18);
      if (ppuVar3 != (undefined **)0x0) {
        *ppuVar3 = (undefined *)&::mDoExt_baseAnm::__vt;
        ppuVar3[1] = (undefined *)0x0;
        *ppuVar3 = (undefined *)&::mDoExt_brkAnm::__vt;
        ppuVar3[3] = (undefined *)0x0;
        ppuVar3[4] = (undefined *)0x0;
      }
      *(undefined ***)(this + 0xc) = ppuVar3;
      if (*(int *)(this + 0xc) == 0) {
        bVar6 = false;
      }
      else {
        pJVar4 = (J3DAnmTevRegKey *)
                 dRes_control_c::getRes
                           ("Hkyo",8,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
        iVar5 = ::mDoExt_brkAnm::init
                          (*(mDoExt_brkAnm **)(this + 0xc),pModel,pJVar4,true,Repeat,d_door::_4732,0
                           ,-1,false,0);
        bVar6 = iVar5 != 0;
      }
    }
  }
  return bVar6;
}


/* __thiscall dDoor_hkyo_c::setAnm(unsigned char) */

void __thiscall dDoor_hkyo_c::setAnm(dDoor_hkyo_c *this,uchar param_1)

{
  J3DAnmTevRegKey *pJVar1;
  long fileIndex;
  J3DModelData *pJVar2;
  
  if ((this[0x10] != (dDoor_hkyo_c)param_1) && (this[0x10] = (dDoor_hkyo_c)param_1, param_1 != '\0')
     ) {
    if (param_1 == '\x02') {
      fileIndex = 8;
    }
    else {
      if ((param_1 < 2) && (param_1 != '\0')) {
        fileIndex = 7;
      }
      else {
        fileIndex = 9;
      }
    }
    pJVar2 = *(J3DModelData **)(*(int *)(this + 8) + 4);
    pJVar1 = (J3DAnmTevRegKey *)
             dRes_control_c::getRes
                       ("Hkyo",fileIndex,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                        0x40);
    ::mDoExt_brkAnm::init
              (*(mDoExt_brkAnm **)(this + 0xc),pJVar2,pJVar1,true,Repeat,d_door::_4732,0,-1,true,0);
  }
  return;
}


/* __thiscall dDoor_hkyo_c::init(void) */

int __thiscall dDoor_hkyo_c::init(dDoor_hkyo_c *this,EVP_PKEY_CTX *ctx)

{
  this[0x10] = (dDoor_hkyo_c)0x0;
  return (int)this;
}


/* WARNING: Removing unreachable block (ram,0x8006d444) */
/* __thiscall dDoor_hkyo_c::calcMtx(dDoor_info_c *,
                                    float) */

void __thiscall dDoor_hkyo_c::calcMtx(dDoor_hkyo_c *this,dDoor_info_c *param_1,float param_2)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar2 = (double)param_2;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((this[0x11] != (dDoor_hkyo_c)0x0) && (*(int *)(this + 8) != 0)) {
    mtx::PSMTXTrans((double)(param_1->parent).mCurrent.mPos.x,
                    (double)(param_1->parent).mCurrent.mPos.y,
                    (double)(param_1->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,(param_1->parent).mCurrent.mRot.y);
    mDoMtx_stack_c::transM(d_door::0_0,(float)dVar2,d_door::0_0);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)(this + 8) + 0x24));
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDoor_hkyo_c::draw(dDoor_info_c *) */

void __thiscall dDoor_hkyo_c::draw(dDoor_hkyo_c *this,dDoor_info_c *param_1)

{
  int iVar1;
  J3DModelData *pJVar2;
  
  if ((((this[0x11] != (dDoor_hkyo_c)0x0) && (this[0x10] != (dDoor_hkyo_c)0x0)) &&
      (*(int *)(this + 8) != 0)) && (iVar1 = chkFirst(this), iVar1 == 0)) {
    pJVar2 = (*(J3DModel **)(this + 8))->mpModelData;
    dScnKy_env_light_c::setLightTevColorType
              (&d_kankyo::g_env_light,*(J3DModel **)(this + 8),&(param_1->parent).mTevStr);
    ::mDoExt_brkAnm::entry
              (*(mDoExt_brkAnm **)(this + 0xc),pJVar2,
               (((*(mDoExt_brkAnm **)(this + 0xc))->parent).mpFrameCtrl)->mCurrentTime);
    m_Do_ext::mDoExt_modelUpdateDL(*(J3DModel **)(this + 8));
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDoor_hkyo_c::proc(dDoor_info_c *) */

void __thiscall dDoor_hkyo_c::proc(dDoor_hkyo_c *this,dDoor_info_c *param_1)

{
  dDoor_hkyo_c dVar1;
  int iVar2;
  sbyte sVar3;
  
  dVar1 = this[0x11];
  if (dVar1 == (dDoor_hkyo_c)0x0) {
    return;
  }
  if (*(int *)(this + 8) == 0) {
    return;
  }
  if (dVar1 == (dDoor_hkyo_c)0x3) {
    iVar2 = dSv_player_collect_c::isTact
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
    if ((iVar2 == 0) ||
       (iVar2 = dSv_event_c::isEventBit
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1704),
       iVar2 != 0)) {
      setAnm(this,'\0');
    }
    else {
      setAnm(this,'\x03');
    }
    goto LAB_8006d6b8;
  }
  if ((byte)dVar1 < 3) {
    if (dVar1 == (dDoor_hkyo_c)0x1) {
      iVar2 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x108);
      if (iVar2 == 0) {
        iVar2 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x110);
        if (iVar2 == 0) {
          setAnm(this,'\0');
        }
        else {
          setAnm(this,'\x02');
        }
      }
      else {
        setAnm(this,'\x01');
      }
      goto LAB_8006d6b8;
    }
    if (dVar1 != (dDoor_hkyo_c)0x0) {
      iVar2 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1704);
      if ((iVar2 == 0) ||
         (iVar2 = dSv_event_c::isEventBit
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1b01),
         iVar2 != 0)) {
        setAnm(this,'\0');
      }
      else {
        setAnm(this,'\x03');
      }
      goto LAB_8006d6b8;
    }
  }
  else {
    if ((byte)dVar1 < 5) {
      iVar2 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1710);
      if (iVar2 == 0) {
        setAnm(this,'\x03');
      }
      else {
        setAnm(this,'\0');
      }
      goto LAB_8006d6b8;
    }
  }
  setAnm(this,'\0');
LAB_8006d6b8:
  if (this[0x10] != (dDoor_hkyo_c)0x0) {
    ::mDoExt_baseAnm::play(*(mDoExt_baseAnm **)(this + 0xc));
    sVar3 = d_com_inf_game::dComIfGp_getReverb((int)(char)(param_1->parent).mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x61d4,&(param_1->parent).mEyePos,0,sVar3,d_door::_4732,
               d_door::_4732,d_door::_4733,d_door::_4733,0);
  }
  return;
}


/* __thiscall dDoor_hkyo_c::chkFirst(void) */

undefined4 __thiscall dDoor_hkyo_c::chkFirst(dDoor_hkyo_c *this)

{
  undefined4 uVar1;
  int iVar2;
  
  if (this[0x11] == (dDoor_hkyo_c)0x1) {
    if ((this[0x10] == (dDoor_hkyo_c)0x1) &&
       (iVar2 = dSv_event_c::isEventBit
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2602),
       iVar2 == 0)) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall dDoor_hkyo_c::onFirst(void) */

void __thiscall dDoor_hkyo_c::onFirst(dDoor_hkyo_c *this)

{
  dDoor_hkyo_c dVar1;
  
  dVar1 = this[0x10];
  if (dVar1 == (dDoor_hkyo_c)0x2) {
    dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2601);
  }
  else {
    if (((byte)dVar1 < 2) && (dVar1 != (dDoor_hkyo_c)0x0)) {
      dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2602);
    }
  }
  return;
}


/* __thiscall dDoor_hkyo_c::chkStart(void) */

uint __thiscall dDoor_hkyo_c::chkStart(dDoor_hkyo_c *this)

{
  return ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x2a4 >> 5 & 1;
}


/* __thiscall daPy_py_c::setPlayerPosAndAngle(cXyz *,
                                              short) */

void __thiscall daPy_py_c::setPlayerPosAndAngle(daPy_py_c *this,cXyz *param_1,short param_2)

{
  return;
}

