#include <d_a_player_npc.h>
#include <d_bg_s_acch.h>
#include <d_bg_s.h>
#include <d_a_player_npc.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_save.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <SComponent/c_lib.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <f_op_actor_mng.h>
#include <d_event_manager.h>
#include <m_Do_lib.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <f_op_actor_iter.h>
#include <daPy_npc_c.h>


namespace d_a_player_npc {
undefined4 l_offsetPos$4174;
undefined1 init$4176;
}

/* __thiscall daPy_npc_c::check_initialRoom(void) */

undefined4 __thiscall daPy_npc_c::check_initialRoom(daPy_npc_c *this)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((char)(this->parent).parent.mOrig.mRoomNo < '\0') {
    dBgS_Acch::CrrPos(&this->mAcch,&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
    if ((d_a_player_npc::_4092 == (this->mAcch).field_0x94) ||
       (iVar1 = dBgS::GetGroundCode(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                    &(this->mAcch).mGndChk.parent.mPolyInfo), iVar1 == 4)) {
      uVar2 = 0;
    }
    else {
      iVar1 = dBgS::GetRoomId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                              &(this->mAcch).mGndChk.parent.mPolyInfo);
      if ((iVar1 < 0) || ((dStage_roomControl_c::mStatus[iVar1].mFlags & HasBgW) == 0)) {
        uVar2 = 0;
      }
      else {
        (this->parent).parent.mOrig.mRoomNo = (byte)iVar1;
        (this->parent).parent.mCurrent.mRoomNo = (byte)iVar1;
        uVar2 = 0xffffffff;
      }
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


/* __thiscall daPy_npc_c::check_moveStop(void) */

undefined4 __thiscall daPy_npc_c::check_moveStop(daPy_npc_c *this)

{
  int iVar1;
  
  iVar1 = (int)(char)(this->parent).parent.mCurrent.mRoomNo;
  if ((-1 < iVar1) && ((dStage_roomControl_c::mStatus[iVar1].mFlags & HasBgW) != 0)) {
    return 0;
  }
  if (((dStage_roomControl_c::mStatus[iVar1].mFlags & HasBgW) == 0) || (0x1d < this->field_0x4e8)) {
    (this->parent).parent.mCurrent.mPos.x = (this->parent).parent.mOrig.mPos.x;
    (this->parent).parent.mCurrent.mPos.y = (this->parent).parent.mOrig.mPos.y;
    (this->parent).parent.mCurrent.mPos.z = (this->parent).parent.mOrig.mPos.z;
    (this->parent).parent.mCurrent.mRot.x = (this->parent).parent.mOrig.mRot.x;
    (this->parent).parent.mCurrent.mRot.y = (this->parent).parent.mOrig.mRot.y;
    (this->parent).parent.mCurrent.mRot.z = (this->parent).parent.mOrig.mRot.z;
    (this->parent).parent.mCurrent.mRoomNo = (this->parent).parent.mOrig.mRoomNo;
    (this->parent).parent.mCurrent.field_0x13 = (this->parent).parent.mOrig.field_0x13;
    (this->parent).parent.mCollisionRot.x = (this->parent).parent.mOrig.mRot.x;
    (this->parent).parent.mCollisionRot.y = (this->parent).parent.mOrig.mRot.y;
    (this->parent).parent.mCollisionRot.z = (this->parent).parent.mOrig.mRot.z;
    (this->parent).parent.mVelocityFwd = d_a_player_npc::_4128;
    this->field_0x4e8 = 0;
  }
  if (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mEvtInfo.mCommand
      != InDoor) {
    (this->parent).field_0x2a0 = (this->parent).field_0x2a0 & 0xfffffffd;
  }
  return 1;
}


/* __thiscall daPy_npc_c::setRestart(signed char) */

void __thiscall daPy_npc_c::setRestart(daPy_npc_c *this,char param_1)

{
  uint uVar1;
  
  if (param_1 == d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.field_0x1) {
    uVar1 = countLeadingZeros(3 - (uint)((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)
                                        ->parent).parent.mEvtInfo.mCommand);
    if (((uVar1 >> 5 & 0xff) == 0) &&
       ((this->parent).parent.mCurrent.mRoomNo !=
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mRoomNo)) {
      unconditionalSetRestart(this,param_1);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall daPy_npc_c::unconditionalSetRestart(signed char) */

void __thiscall daPy_npc_c::unconditionalSetRestart(daPy_npc_c *this,char param_1)

{
  dSv_restart_c::setRestartOption(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart,param_1);
  dSv_player_priest_c::set
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mPriest,param_1,
             &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mPos,
             d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mRotY,
             d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mRoomNo);
  (this->parent).parent.mOrig.mPos.x = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mPos.x;
  (this->parent).parent.mOrig.mPos.y = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mPos.y;
  (this->parent).parent.mOrig.mPos.z = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mPos.z;
  (this->parent).parent.mOrig.mRot.y = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mRotY;
  (this->parent).parent.mOrig.mRoomNo = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mRoomNo;
  return;
}


/* __thiscall daPy_npc_c::setOffsetHomePos(void) */

void __thiscall daPy_npc_c::setOffsetHomePos(daPy_npc_c *this)

{
  actor_place *paVar1;
  
  if (d_a_player_npc::init_4176 == '\0') {
    d_a_player_npc::l_offsetPos_4174 = d_a_player_npc::_4180;
    DAT_803e4730 = d_a_player_npc::_4128;
    DAT_803e4734 = d_a_player_npc::_4128;
    Runtime.PPCEABI.H::__register_global_object
              (&d_a_player_npc::l_offsetPos_4174,::cXyz::_cXyz,&d_a_player_npc::_4175);
    d_a_player_npc::init_4176 = '\x01';
  }
  paVar1 = &(this->parent).parent.mOrig;
  SComponent::cLib_offsetPos
            (&paVar1->mPos,&paVar1->mPos,(this->parent).parent.mOrig.mRot.y,
             (cXyz *)&d_a_player_npc::l_offsetPos_4174);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall daPy_npc_c::setPointRestart(short,
                                          signed char) */

void __thiscall daPy_npc_c::setPointRestart(daPy_npc_c *this,short param_1,char param_2)

{
  byte bVar1;
  short rotY;
  int iVar2;
  ulong uVar3;
  int *piVar4;
  stage_actor_class *spawnPoint;
  uint uVar5;
  bool bVar6;
  uint uVar7;
  
  iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getPlayer)
                    (0x803c9d58);
  if (iVar2 == 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_a_player_npc.cpp",0x9d,"dComIfGp_getStagePlayer() != 0");
    m_Do_printf::OSPanic("d_a_player_npc.cpp",0x9d,"Halt");
  }
  piVar4 = (int *)(*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                            getSclsInfo)(0x803c9d58);
  if (piVar4 == (int *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_a_player_npc.cpp",0x9f,"sclsinfo != 0");
    m_Do_printf::OSPanic("d_a_player_npc.cpp",0x9f,"Halt");
  }
  bVar6 = false;
  if (-1 < param_1) {
    if ((int)param_1 < *piVar4) {
      bVar6 = true;
    }
  }
  if (!bVar6) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar3,"d_a_player_npc.cpp",0xa1,"0 <= i_point && i_point < sclsinfo->num");
    m_Do_printf::OSPanic("d_a_player_npc.cpp",0xa1,"Halt");
  }
  iVar2 = piVar4[1];
  if (iVar2 == 0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_a_player_npc.cpp",0xa3,"scls_data != 0");
    m_Do_printf::OSPanic("d_a_player_npc.cpp",0xa3,"Halt");
  }
  spawnPoint = (stage_actor_class *)
               (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getPlayer)
                         (0x803c9d58);
  bVar1 = *(byte *)(iVar2 + param_1 * 0xc + 8);
  uVar7 = 0;
  for (iVar2 = *(int *)&spawnPoint->field_0x4;
      (uVar5 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getPlayerNum)
                         (0x803c9d58), (int)uVar7 < (int)(uVar5 & 0xffff) &&
      ((*(ushort *)(iVar2 + 0x1c) & 0xff) != (ushort)bVar1)); iVar2 = iVar2 + 0x20) {
    uVar7 = uVar7 + 1;
  }
  uVar5 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getPlayerNum)
                    (0x803c9d58);
  if (uVar7 == (uVar5 & 0xffff)) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_a_player_npc.cpp",0xae,"i != dComIfGp_getStagePlayerNum()");
    m_Do_printf::OSPanic("d_a_player_npc.cpp",0xae,"Halt");
  }
  (this->parent).parent.mOrig.mPos.x = *(float *)(iVar2 + 0xc);
  (this->parent).parent.mOrig.mPos.y = *(float *)(iVar2 + 0x10);
  (this->parent).parent.mOrig.mPos.z = *(float *)(iVar2 + 0x14);
  (this->parent).parent.mOrig.mRot.y = *(short *)(iVar2 + 0x1a);
  (this->parent).parent.mOrig.mRoomNo = 0xff;
  setOffsetHomePos(this);
  (this->parent).parent.mCurrent.mPos.x = (this->parent).parent.mOrig.mPos.x;
  (this->parent).parent.mCurrent.mPos.y = (this->parent).parent.mOrig.mPos.y;
  (this->parent).parent.mCurrent.mPos.z = (this->parent).parent.mOrig.mPos.z;
  (this->parent).parent.mCurrent.mRot.x = (this->parent).parent.mOrig.mRot.x;
  (this->parent).parent.mCurrent.mRot.y = (this->parent).parent.mOrig.mRot.y;
  (this->parent).parent.mCurrent.mRot.z = (this->parent).parent.mOrig.mRot.z;
  (this->parent).parent.mCurrent.mRoomNo = (this->parent).parent.mOrig.mRoomNo;
  (this->parent).parent.mCurrent.field_0x13 = (this->parent).parent.mOrig.field_0x13;
  (this->parent).parent.mNext.mPos.x = (this->parent).parent.mOrig.mPos.x;
  (this->parent).parent.mNext.mPos.y = (this->parent).parent.mOrig.mPos.y;
  (this->parent).parent.mNext.mPos.z = (this->parent).parent.mOrig.mPos.z;
  (this->parent).parent.mNext.mRot.x = (this->parent).parent.mOrig.mRot.x;
  (this->parent).parent.mNext.mRot.y = (this->parent).parent.mOrig.mRot.y;
  (this->parent).parent.mNext.mRot.z = (this->parent).parent.mOrig.mRot.z;
  (this->parent).parent.mNext.mRoomNo = (this->parent).parent.mOrig.mRoomNo;
  (this->parent).parent.mNext.field_0x13 = (this->parent).parent.mOrig.field_0x13;
  (this->parent).parent.mCollisionRot.x = (this->parent).parent.mOrig.mRot.x;
  (this->parent).parent.mCollisionRot.y = (this->parent).parent.mOrig.mRot.y;
  (this->parent).parent.mCollisionRot.z = (this->parent).parent.mOrig.mRot.z;
  rotY = (this->parent).parent.mOrig.mRot.y;
  dSv_restart_c::setRestartOption
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart,param_2,
             &(this->parent).parent.mOrig.mPos,rotY,-1);
  dSv_player_priest_c::set
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mPriest,param_2,
             &(this->parent).parent.mOrig.mPos,rotY,-1);
  dSv_player_priest_c::set
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mPriest,param_2,
             &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mPos,
             d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mRotY,
             d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mRoomNo);
  f_op_actor_mng::fopAcM_setStageLayer((fopAc_ac_c *)this);
  return;
}


/* __thiscall daPy_npc_c::checkRestart(signed char) */

undefined4 __thiscall daPy_npc_c::checkRestart(daPy_npc_c *this,char param_1)

{
  undefined4 uVar1;
  
  if (param_1 == d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.field_0x1) {
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.field_0x4 < 0) {
      (this->parent).parent.mOrig.mPos.x =
           d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mPos.x;
      (this->parent).parent.mOrig.mPos.y =
           d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mPos.y;
      (this->parent).parent.mOrig.mPos.z =
           d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mPos.z;
      (this->parent).parent.mOrig.mRot.y = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mRotY
      ;
      (this->parent).parent.mOrig.mRoomNo =
           d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mRoomNo;
      (this->parent).parent.mCurrent.mPos.x = (this->parent).parent.mOrig.mPos.x;
      (this->parent).parent.mCurrent.mPos.y = (this->parent).parent.mOrig.mPos.y;
      (this->parent).parent.mCurrent.mPos.z = (this->parent).parent.mOrig.mPos.z;
      (this->parent).parent.mCurrent.mRot.x = (this->parent).parent.mOrig.mRot.x;
      (this->parent).parent.mCurrent.mRot.y = (this->parent).parent.mOrig.mRot.y;
      (this->parent).parent.mCurrent.mRot.z = (this->parent).parent.mOrig.mRot.z;
      (this->parent).parent.mCurrent.mRoomNo = (this->parent).parent.mOrig.mRoomNo;
      (this->parent).parent.mCurrent.field_0x13 = (this->parent).parent.mOrig.field_0x13;
      (this->parent).parent.mNext.mPos.x = (this->parent).parent.mOrig.mPos.x;
      (this->parent).parent.mNext.mPos.y = (this->parent).parent.mOrig.mPos.y;
      (this->parent).parent.mNext.mPos.z = (this->parent).parent.mOrig.mPos.z;
      (this->parent).parent.mNext.mRot.x = (this->parent).parent.mOrig.mRot.x;
      (this->parent).parent.mNext.mRot.y = (this->parent).parent.mOrig.mRot.y;
      (this->parent).parent.mNext.mRot.z = (this->parent).parent.mOrig.mRot.z;
      (this->parent).parent.mNext.mRoomNo = (this->parent).parent.mOrig.mRoomNo;
      (this->parent).parent.mNext.field_0x13 = (this->parent).parent.mOrig.field_0x13;
      (this->parent).parent.mCollisionRot.x = (this->parent).parent.mOrig.mRot.x;
      (this->parent).parent.mCollisionRot.y = (this->parent).parent.mOrig.mRot.y;
      (this->parent).parent.mCollisionRot.z = (this->parent).parent.mOrig.mRot.z;
    }
    else {
      setPointRestart(this,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.field_0x4,'\x01');
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall daPy_npc_c::initialRestartOption(signed char,
                                               int) */

undefined4 __thiscall daPy_npc_c::initialRestartOption(daPy_npc_c *this,char param_1,int param_2)

{
  byte roomNo;
  short rotY;
  undefined4 uVar1;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpPlayerPartnerActor == (daPy_npc_c *)0x0) {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpPlayerPartnerActor = this;
    if ((param_2 != 0) && (param_1 != d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.field_0x1)
       ) {
      roomNo = (this->parent).parent.mCurrent.mRoomNo;
      rotY = (this->parent).parent.mOrig.mRot.y;
      dSv_restart_c::setRestartOption
                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart,param_1,
                 &(this->parent).parent.mOrig.mPos,rotY,roomNo);
      dSv_player_priest_c::set
                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mPriest,param_1,
                 &(this->parent).parent.mOrig.mPos,rotY,roomNo);
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall daPy_npc_c::checkNowPosMove(char const *) */

uint __thiscall daPy_npc_c::checkNowPosMove(daPy_npc_c *this,char *param_1)

{
  uint uVar1;
  int iVar2;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
    uVar1 = 1;
  }
  else {
    if ((this->parent).parent.mEvtInfo.mCommand == InTalk) {
      uVar1 = 1;
    }
    else {
      if (((this->field_0x4e4 & 2) == 0) || ((this->field_0x4e4 & 1) != 0)) {
        iVar2 = dEvent_manager_c::getMyStaffId
                          (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,param_1,
                           (fopAc_ac_c *)0x0,0);
        if (iVar2 == -1) {
          uVar1 = (this->parent).parent.mStatus >> 0xb & 1;
        }
        else {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


/* __thiscall daPy_npc_c::drawDamageFog(void) */

void __thiscall daPy_npc_c::drawDamageFog(daPy_npc_c *this)

{
  float fVar1;
  undefined auStack24 [8];
  float local_10;
  
  if (this->field_0x4e9 != 0) {
    m_Do_lib::mDoLib_pos2camera(&(this->parent).parent.mCurrent,auStack24);
    fVar1 = JKernel::JMath::jmaSinTable
            [(int)((g__Timer & 0x1fU) << 0xb) >> (JKernel::JMath::jmaSinShift & 0x3f)];
    (this->parent).parent.mTevStr.mFogColor.r = 0xff;
    (this->parent).parent.mTevStr.mFogColor.g = 0x3c;
    (this->parent).parent.mTevStr.mFogColor.b = 0x3c;
    (this->parent).parent.mTevStr.mFogStartZ =
         (-local_10 - d_a_player_npc::_4342) + d_a_player_npc::_4342 * ABS(fVar1);
    (this->parent).parent.mTevStr.mFogEndZ =
         d_a_player_npc::_4343 + (this->parent).parent.mTevStr.mFogStartZ;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8015aed8) */
/* __thiscall daPy_npc_c::chkMoveBlock(cXyz *) */

undefined4 __thiscall daPy_npc_c::chkMoveBlock(daPy_npc_c *this,cXyz *param_1)

{
  fopAc_ac_c *pfVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  float fVar6;
  cXyz local_74;
  cXyz cStack104;
  cXyz cStack92;
  cXyz local_50 [2];
  cXyz local_38;
  cXyz cStack44;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pfVar1 = d_a_player_npc::daPy_npc_SearchAreaByName
                     (this,0x2d,(double)d_a_player_npc::_4343,&cStack44);
  if (pfVar1 != (fopAc_ac_c *)0x0) {
    ::cXyz::operator__(local_50,&(pfVar1->mCurrent).mPos,&(pfVar1->mNext).mPos);
    local_38.x = local_50[0].x;
    local_38.y = local_50[0].y;
    local_38.z = local_50[0].z;
    fVar6 = mtx::PSVECSquareMag(&local_38);
    dVar5 = (double)fVar6;
    if ((double)d_a_player_npc::_4128 < dVar5) {
      dVar4 = 1.0 / SQRT(dVar5);
      dVar4 = d_a_player_npc::_4432 * dVar4 * (d_a_player_npc::_4433 - dVar5 * dVar4 * dVar4);
      dVar4 = d_a_player_npc::_4432 * dVar4 * (d_a_player_npc::_4433 - dVar5 * dVar4 * dVar4);
      dVar5 = (double)(float)(dVar5 * d_a_player_npc::_4432 * dVar4 *
                                      (d_a_player_npc::_4433 - dVar5 * dVar4 * dVar4));
    }
    if ((double)d_a_player_npc::_4434 < dVar5) {
      if (param_1 != (cXyz *)0x0) {
        param_1->x = local_38.x;
        param_1->y = local_38.y;
        param_1->z = local_38.z;
      }
      ::cXyz::normalizeZP(&cStack92);
      ::cXyz::normalizeZP(&cStack104);
      dVar5 = (double)mtx::PSVECDotProduct(&cStack44,&local_38);
      local_38.y = d_a_player_npc::_4128;
      cStack44.y = d_a_player_npc::_4128;
      ::cXyz::outprod(&local_74,&cStack44,&local_38);
      if (dVar5 < (double)d_a_player_npc::_4435) {
        if (d_a_player_npc::_4128 <= local_74.y) {
          uVar2 = 1;
        }
        else {
          uVar2 = 0xffffffff;
        }
        goto LAB_8015aed8;
      }
      if (d_a_player_npc::_4180 + (this->parent).parent.mCurrent.mPos.y < (pfVar1->mCurrent).mPos.y)
      {
        if (d_a_player_npc::_4128 <= local_74.y) {
          uVar2 = 1;
        }
        else {
          uVar2 = 0xffffffff;
        }
        goto LAB_8015aed8;
      }
    }
  }
  uVar2 = 0;
LAB_8015aed8:
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return uVar2;
}


namespace d_a_player_npc {

/* __stdcall daPy_npc_JudgeForPNameAndDistance(void *,
                                               void *) */

undefined4 daPy_npc_JudgeForPNameAndDistance(fopAc_ac_c *param_1,short *param_2)

{
  double dVar1;
  double dVar2;
  float fVar3;
  cXyz local_24;
  cXyz local_18;
  
  if (*param_2 == (param_1->parent).parent.mProcName) {
    ::cXyz::operator__(&local_24,&(param_1->mCurrent).mPos,(cXyz *)(param_2 + 2));
    local_18.x = local_24.x;
    local_18.y = local_24.y;
    local_18.z = local_24.z;
    fVar3 = mtx::PSVECSquareMag(&local_18);
    dVar2 = (double)fVar3;
    if ((double)_4128 < dVar2) {
      dVar1 = 1.0 / SQRT(dVar2);
      dVar1 = _4432 * dVar1 * (_4433 - dVar2 * dVar1 * dVar1);
      dVar1 = _4432 * dVar1 * (_4433 - dVar2 * dVar1 * dVar1);
      dVar2 = (double)(float)(dVar2 * _4432 * dVar1 * (_4433 - dVar2 * dVar1 * dVar1));
    }
    if ((dVar2 < (double)*(float *)(param_2 + 0xe)) && (dVar2 < (double)*(float *)(param_2 + 0x10)))
    {
      *(float *)(param_2 + 0x10) = (float)dVar2;
      *(fopAc_ac_c **)(param_2 + 0x12) = param_1;
      *(float *)(param_2 + 8) = local_18.x;
      *(float *)(param_2 + 10) = local_18.y;
      *(float *)(param_2 + 0xc) = local_18.z;
    }
  }
  return 0;
}


/* __stdcall daPy_npc_SearchAreaByName(fopAc_ac_c *,
                                       short,
                                       float,
                                       cXyz *) */

fopAc_ac_c *
daPy_npc_SearchAreaByName
          (daPy_npc_c *param_1,short procName,double dist,cXyz *param_4)

{
  short local_38 [2];
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  fopAc_ac_c *local_14;
  
  local_34 = (param_1->parent).parent.mCurrent.mPos.x;
  local_30 = (param_1->parent).parent.mCurrent.mPos.y;
  local_2c = (param_1->parent).parent.mCurrent.mPos.z;
  local_1c = (float)dist;
  local_18 = (float)dist;
  local_14 = (fopAc_ac_c *)0x0;
  local_28 = _4128;
  local_24 = _4128;
  local_20 = _4128;
  local_38[0] = procName;
  f_op_actor_iter::fopAcIt_Judge(daPy_npc_JudgeForPNameAndDistance,local_38);
  if (param_4 != (cXyz *)0x0) {
    param_4->x = local_28;
    param_4->y = local_24;
    param_4->z = local_20;
  }
  return local_14;
}

