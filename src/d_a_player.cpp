#include <d_a_player.h>
#include <d_cc_d.h>
#include <mtx/vec.h>
#include <SComponent/c_xyz.h>
#include <SComponent/c_lib.h>
#include <JPABase/JPAMath.h>
#include <d_a_player.h>
#include <d_particle.h>
#include <d_vibration.h>
#include <JKernel/JKRHeap.h>
#include <daPy_py_c.h>
#include <daPy_mtxFollowEcallBack_c.h>


/* __thiscall daPy_py_c::changePlayer(fopAc_ac_c *) */

void __thiscall daPy_py_c::changePlayer(daPy_py_c *this,fopAc_ac_c *pPlayer)

{
  if (pPlayer == (fopAc_ac_c *)0x0) {
    return;
  }
  if (dStage_roomControl_c::mStayNo != (pPlayer->mCurrent).mRoomNo) {
    return;
  }
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor = (daPy_lk_c *)pPlayer;
  ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mBody).mpPlayerActor =
       pPlayer;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.mFlags =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.mFlags | 0x80;
  return;
}


/* WARNING: Removing unreachable block (ram,0x80102b64) */
/* __thiscall daPy_py_c::objWindHitCheck(dCcD_Cyl *) */

void __thiscall daPy_py_c::objWindHitCheck(daPy_py_c *this,dCcD_Cyl *param_1)

{
  int iVar1;
  cCcD_Obj *pcVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  float fVar7;
  cXyz local_60;
  cXyz local_54;
  cXyz local_48;
  cXyz cStack60;
  cXyz local_30 [2];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_30[0].x = d_a_player::_4168;
  local_30[0].y = d_a_player::_4168;
  local_30[0].z = d_a_player::_4168;
  dVar6 = (double)d_a_player::_4169;
  iVar1 = dCcD_GObjInf::ChkTgHit(&param_1->parent);
  if (((iVar1 != 0) &&
      (pcVar2 = dCcD_GObjInf::GetTgHitObj(&param_1->parent), pcVar2 != (cCcD_Obj *)0x0)) &&
     (((pcVar2->parent).mObjAt.mDamageTypes & DekuLeafWind) != 0)) {
    local_54.x = (param_1->parent).mObjTg.mAtVel.x;
    local_30[0].y = (param_1->parent).mObjTg.mAtVel.y;
    local_54.z = (param_1->parent).mObjTg.mAtVel.z;
    local_54.y = d_a_player::_4168;
    local_30[0].x = local_54.x;
    local_30[0].z = local_54.z;
    fVar7 = mtx::PSVECSquareMag(&local_54);
    dVar5 = (double)fVar7;
    if ((double)d_a_player::_4168 < dVar5) {
      dVar6 = 1.0 / SQRT(dVar5);
      dVar6 = d_a_player::_4170 * dVar6 * (d_a_player::_4171 - dVar5 * dVar6 * dVar6);
      dVar6 = d_a_player::_4170 * dVar6 * (d_a_player::_4171 - dVar5 * dVar6 * dVar6);
      dVar5 = (double)(float)(dVar5 * d_a_player::_4170 * dVar6 *
                                      (d_a_player::_4171 - dVar5 * dVar6 * dVar6));
    }
    dVar6 = (double)d_a_player::_4172;
    if (dVar5 < dVar6) {
      ::cXyz::operator__(&cStack60,&(this->parent).mCurrent.mPos,&(param_1->parent).mObjTg.mHitPos);
      ::cXyz::operator_(&local_48,&cStack60,d_a_player::_4173);
      local_30[0].x = local_48.x;
      local_30[0].y = local_48.y;
      local_30[0].z = local_48.z;
      local_60.x = local_48.x;
      local_60.y = d_a_player::_4168;
      local_60.z = local_48.z;
      fVar7 = mtx::PSVECSquareMag(&local_60);
      dVar5 = (double)fVar7;
      if ((double)d_a_player::_4168 < dVar5) {
        dVar4 = 1.0 / SQRT(dVar5);
        dVar4 = d_a_player::_4170 * dVar4 * (d_a_player::_4171 - dVar5 * dVar4 * dVar4);
        dVar4 = d_a_player::_4170 * dVar4 * (d_a_player::_4171 - dVar5 * dVar4 * dVar4);
        dVar5 = (double)(float)(dVar5 * d_a_player::_4170 * dVar4 *
                                        (d_a_player::_4171 - dVar5 * dVar4 * dVar4));
      }
    }
    if ((double)d_a_player::_4173 < dVar5) {
      mtx::PSVECScale(local_30,local_30,(float)((double)d_a_player::_4173 / dVar5));
    }
  }
  SComponent::cLib_addCalc
            (&this->field_0x2f8,local_30[0].x,d_a_player::_4174,(float)dVar6,d_a_player::_4174);
  SComponent::cLib_addCalc
            (&this->field_0x300,local_30[0].z,d_a_player::_4174,(float)dVar6,d_a_player::_4174);
  (this->parent).mCurrent.mPos.x = (this->parent).mCurrent.mPos.x + this->field_0x2f8;
  (this->parent).mCurrent.mPos.z = (this->parent).mCurrent.mPos.z + this->field_0x300;
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __thiscall daPy_mtxFollowEcallBack_c::execute(JPABaseEmitter *) */

void __thiscall
daPy_mtxFollowEcallBack_c::execute(daPy_mtxFollowEcallBack_c *this,JPABaseEmitter *param_1)

{
  JPABase::JPASetRMtxTVecfromMtx
            (this->field_0x8,&param_1->mGlobalRotation,&param_1->mGlobalTranslation);
  return;
}


/* __thiscall daPy_mtxFollowEcallBack_c::end(void) */

void __thiscall daPy_mtxFollowEcallBack_c::end(daPy_mtxFollowEcallBack_c *this)

{
  int iVar1;
  
  iVar1 = this->field_0x4;
  if (iVar1 == 0) {
    return;
  }
  *(undefined4 *)(iVar1 + 0x60) = 0xffffffff;
  *(uint *)(iVar1 + 0x20c) = *(uint *)(iVar1 + 0x20c) | 1;
  *(uint *)(this->field_0x4 + 0x20c) = *(uint *)(this->field_0x4 + 0x20c) & 0xffffffbf;
  *(undefined4 *)(this->field_0x4 + 0x19c) = 0;
  this->field_0x4 = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall daPy_mtxFollowEcallBack_c::makeEmitter(unsigned short,
                                                     float *[][][][],
                                                     cXyz const *,
                                                     cXyz const *) */

void __thiscall
daPy_mtxFollowEcallBack_c::makeEmitter
          (daPy_mtxFollowEcallBack_c *this,ushort param_1,MTX34 *param_2,cXyz *param_3,cXyz *param_4
          )

{
  end(this);
  this->field_0x8 = (float *)param_2;
  dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,param_1,param_3,
                     (csXyz *)0x0,param_4,0xff,(dPa_levelEcallBack *)this,-1,(_GXColor *)0x0,
                     (_GXColor *)0x0,(cXyz *)0x0);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall daPy_mtxFollowEcallBack_c::makeEmitterColor(unsigned short,
                                                          float *[][][][],
                                                          cXyz const *,
                                                          _GXColor const *,
                                                          _GXColor const *) */

void __thiscall
daPy_mtxFollowEcallBack_c::makeEmitterColor
          (daPy_mtxFollowEcallBack_c *this,ushort param_1,float *param_2,cXyz *param_3,
          _GXColor *param_4,_GXColor *param_5)

{
  end(this);
  this->field_0x8 = param_2;
  dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,1,param_1,param_3,
                     (csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)this,-1,param_4,param_5,
                     (cXyz *)0x0);
  return;
}


/* __thiscall daPy_py_c::setDoButtonQuake(void) */

void __thiscall daPy_py_c::setDoButtonQuake(daPy_py_c *this)

{
  undefined4 local_18;
  cXyz local_14;
  
  if ((this->field_0x29c & 0x200000) == 0) {
    this->field_0x29c = this->field_0x29c | 0x200000;
    this->field_0x296 = 0x3c;
    local_18 = 0x10ffee;
    local_14.x = d_a_player::_4168;
    local_14.y = d_a_player::_4172;
    local_14.z = d_a_player::_4168;
    dVibration_c::StartQuake
              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,(uchar *)&local_18,0,1,&local_14
              );
  }
  return;
}


/* __thiscall daPy_py_c::stopDoButtonQuake(int) */

void __thiscall daPy_py_c::stopDoButtonQuake(daPy_py_c *this,int param_1)

{
  if ((0 < this->field_0x296) &&
     (this->field_0x296 = this->field_0x296 + -1, this->field_0x296 == 0)) {
    dVibration_c::StopQuake(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,-1);
  }
  if ((param_1 != 0) && (this->field_0x296 == 0)) {
    this->field_0x29c = this->field_0x29c & 0xffdfffff;
  }
  return;
}


/* __thiscall daPy_mtxFollowEcallBack_c::~daPy_mtxFollowEcallBack_c(void) */

void __thiscall
daPy_mtxFollowEcallBack_c::_daPy_mtxFollowEcallBack_c(daPy_mtxFollowEcallBack_c *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (daPy_mtxFollowEcallBack_c *)0x0;
  if (bVar1) {
    this->vtbl = &__vt;
    if ((bVar1) && (this->vtbl = (dPa_levelEcallBack__vtbl *)&::dPa_levelEcallBack::__vt, bVar1)) {
      this->vtbl = (dPa_levelEcallBack__vtbl *)&::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall daPy_mtxFollowEcallBack_c::setup(JPABaseEmitter *,
                                               cXyz const *,
                                               csXyz const *,
                                               signed char) */

void __thiscall
daPy_mtxFollowEcallBack_c::setup
          (daPy_mtxFollowEcallBack_c *this,JPABaseEmitter *param_1,cXyz *param_2,csXyz *param_3,
          char param_4)

{
  this->field_0x4 = param_1;
  return;
}

