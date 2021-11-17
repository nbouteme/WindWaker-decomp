#include <d_a_npc_fa1.h>
#include <d_a_npc_fa1.h>
#include <JKernel/JKRHeap.h>
#include <d_kankyo.h>
#include <SComponent/c_bg_s.h>
#include <d_cc_d.h>
#include <d_particle.h>
#include <m_Do_ext.h>
#include <d_drawlist.h>
#include <d_snap.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <d_attention.h>
#include <f_op_actor_mng.h>
#include <d_bg_s.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <SComponent/c_cc_s.h>
#include <m_Do_audio.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <SComponent/c_math.h>
#include <SComponent/c_lib.h>
#include <d_a_arrow.h>
#include <d_a_nh.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_item.h>
#include <m_Do_hostIO.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <f_op_actor.h>
#include <d_bg_s_acch.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <d_resorce.h>
#include <JUtility/JUTNameTab.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <daNpc_Fa1_c.h>
#include <daNpc_Fa1_HIO2_c.h>
#include <daNpc_Fa1_HIO3_c.h>
#include <fopNpc_npc_c.h>
#include <daNpc_Fa1_McaMorfCallBack1_c.h>
#include <daNpc_Fa1_HIO_c.h>


namespace d_a_npc_fa1 {
undefined l_HIO;
undefined4 l_hio_counter;
undefined4 a_heap_size_tbl$4888;
undefined1 init$4889;
}

/* __thiscall daNpc_Fa1_HIO3_c::daNpc_Fa1_HIO3_c(void) */

void __thiscall daNpc_Fa1_HIO3_c::daNpc_Fa1_HIO3_c(daNpc_Fa1_HIO3_c *this)

{
  *(undefined1 **)this = &__vt;
  this[4] = (daNpc_Fa1_HIO3_c)0xff;
  *(undefined4 *)(this + 8) = d_a_npc_fa1::init_data_4040;
  *(undefined4 *)(this + 0xc) = DAT_8035bffc;
  *(undefined4 *)(this + 0x10) = DAT_8035c000;
  *(undefined4 *)(this + 0x14) = DAT_8035c004;
  *(undefined2 *)(this + 0x18) = DAT_8035c008;
  return;
}


/* __thiscall daNpc_Fa1_HIO2_c::daNpc_Fa1_HIO2_c(void) */

void __thiscall daNpc_Fa1_HIO2_c::daNpc_Fa1_HIO2_c(daNpc_Fa1_HIO2_c *this)

{
  *(undefined1 **)this = &__vt;
  this[4] = (daNpc_Fa1_HIO2_c)0xff;
  *(undefined4 *)(this + 8) = d_a_npc_fa1::init_data_4046;
  *(undefined4 *)(this + 0xc) = DAT_8035c010;
  *(undefined4 *)(this + 0x10) = DAT_8035c014;
  *(undefined4 *)(this + 0x14) = DAT_8035c018;
  *(undefined4 *)(this + 0x18) = DAT_8035c01c;
  *(undefined4 *)(this + 0x1c) = DAT_8035c020;
  *(undefined2 *)(this + 0x20) = DAT_8035c024;
  *(undefined2 *)(this + 0x22) = DAT_8035c026;
  *(undefined2 *)(this + 0x24) = DAT_8035c028;
  return;
}


/* __thiscall daNpc_Fa1_HIO_c::daNpc_Fa1_HIO_c(void) */

void __thiscall daNpc_Fa1_HIO_c::daNpc_Fa1_HIO_c(daNpc_Fa1_HIO_c *this)

{
  *(undefined1 **)this = &__vt;
  daNpc_Fa1_HIO2_c::daNpc_Fa1_HIO2_c((daNpc_Fa1_HIO2_c *)(this + 0x50));
  daNpc_Fa1_HIO3_c::daNpc_Fa1_HIO3_c((daNpc_Fa1_HIO3_c *)(this + 0x78));
  this[4] = (daNpc_Fa1_HIO_c)0xff;
  *(undefined4 *)(this + 8) = d_a_npc_fa1::init_data_4052;
  *(undefined4 *)(this + 0xc) = DAT_8035c030;
  *(undefined4 *)(this + 0x10) = DAT_8035c034;
  *(undefined4 *)(this + 0x14) = DAT_8035c038;
  *(undefined4 *)(this + 0x18) = DAT_8035c03c;
  *(undefined4 *)(this + 0x1c) = DAT_8035c040;
  *(undefined4 *)(this + 0x20) = DAT_8035c044;
  *(undefined4 *)(this + 0x24) = DAT_8035c048;
  *(undefined4 *)(this + 0x28) = DAT_8035c04c;
  *(undefined4 *)(this + 0x2c) = DAT_8035c050;
  *(undefined4 *)(this + 0x30) = DAT_8035c054;
  *(undefined4 *)(this + 0x34) = DAT_8035c058;
  *(undefined4 *)(this + 0x38) = DAT_8035c05c;
  *(undefined2 *)(this + 0x3c) = DAT_8035c060;
  *(undefined2 *)(this + 0x3e) = DAT_8035c062;
  *(undefined2 *)(this + 0x40) = DAT_8035c064;
  *(undefined2 *)(this + 0x42) = DAT_8035c066;
  *(undefined2 *)(this + 0x44) = DAT_8035c068;
  *(undefined2 *)(this + 0x46) = DAT_8035c06a;
  *(undefined2 *)(this + 0x48) = DAT_8035c06c;
  *(undefined2 *)(this + 0x4a) = DAT_8035c06e;
  *(undefined2 *)(this + 0x4c) = DAT_8035c070;
  *(undefined2 *)(this + 0x4e) = DAT_8035c072;
  return;
}


/* __thiscall daNpc_Fa1_HIO3_c::~daNpc_Fa1_HIO3_c(void) */

void __thiscall daNpc_Fa1_HIO3_c::_daNpc_Fa1_HIO3_c(daNpc_Fa1_HIO3_c *this)

{
  short in_r4;
  
  if ((this != (daNpc_Fa1_HIO3_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall daNpc_Fa1_HIO2_c::~daNpc_Fa1_HIO2_c(void) */

void __thiscall daNpc_Fa1_HIO2_c::_daNpc_Fa1_HIO2_c(daNpc_Fa1_HIO2_c *this)

{
  short in_r4;
  
  if ((this != (daNpc_Fa1_HIO2_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall daNpc_Fa1_McaMorfCallBack1_c::daNpc_Fa1_McaMorfCallBack1_c(void) */

void __thiscall
daNpc_Fa1_McaMorfCallBack1_c::daNpc_Fa1_McaMorfCallBack1_c(daNpc_Fa1_McaMorfCallBack1_c *this)

{
  (this->parent).vtbl = &mDoExt_McaMorfCallBack1_c::__vt;
  (this->parent).vtbl = &__vt;
  this->field_0x4 = 0;
  this->field_0x6 = 0;
  return;
}


/* __thiscall daNpc_Fa1_McaMorfCallBack1_c::execute(unsigned short,
                                                    J3DTransformInfo *) */

undefined4 __thiscall
daNpc_Fa1_McaMorfCallBack1_c::execute
          (daNpc_Fa1_McaMorfCallBack1_c *this,ushort param_1,J3DTransformInfo *param_2)

{
  if (param_1 == this->field_0x6) {
    (param_2->mRot).x = this->field_0x4;
  }
  return 1;
}


/* __thiscall daNpc_Fa1_c::setPointLightParam(void) */

void __thiscall daNpc_Fa1_c::setPointLightParam(daNpc_Fa1_c *this)

{
  double dVar1;
  
  *(float *)&this->field_0x744 = (this->parent).parent.mAttentionPos.x;
  *(float *)&this->field_0x748 = (this->parent).parent.mAttentionPos.y;
  *(float *)&this->field_0x74c = (this->parent).parent.mAttentionPos.z;
  *(undefined2 *)&this->field_0x750 = 200;
  *(undefined2 *)&this->field_0x752 = 200;
  *(undefined2 *)&this->field_0x754 = 200;
  *(float *)&this->field_0x758 = d_a_npc_fa1::_4081;
  *(float *)&this->field_0x75c = d_a_npc_fa1::_4082;
  dVar1 = (double)d_kankyo::dKy_yuragi_ratio_set((double)d_a_npc_fa1::_4083);
  *(float *)&this->field_0x75c = (float)dVar1;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall daNpc_Fa1_c::createInit(void) */

undefined4 __thiscall daNpc_Fa1_c::createInit(daNpc_Fa1_c *this)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  JPABaseEmitter *pJVar5;
  double dVar6;
  
  this->field_0x794 = (byte)(this->parent).parent.parent.parent.mParameters;
  *(undefined4 *)&this->field_0x764 = 0;
  fVar2 = d_a_npc_fa1::_4082;
  *(float *)&this->field_0x768 = d_a_npc_fa1::_4082;
  *(float *)&this->field_0x76c = fVar2;
  *(float *)&this->field_0x770 = fVar2;
  *(undefined *)&this->field_0x793 = 0;
  bVar1 = this->field_0x794;
  if (bVar1 == 3) {
    init_bottle_baba_wait(this);
    (this->parent).parent.mStatus = (this->parent).parent.mStatus & ~DoNotExecuteIfDidNotDraw;
    (this->parent).parent.mStatus = (this->parent).parent.mStatus | 0x4000;
  }
  else {
    if ((bVar1 == 2) || (bVar1 == 5)) {
      init_bottle_appear_move(this);
      (this->parent).parent.mStatus = (this->parent).parent.mStatus & ~DoNotExecuteIfDidNotDraw;
      (this->parent).parent.mStatus = (this->parent).parent.mStatus | 0x4000;
    }
    else {
      if (bVar1 == 6) {
        init_hover_move(this);
        (this->parent).parent.mStatus = (this->parent).parent.mStatus & ~DoNotExecuteIfDidNotDraw;
      }
      else {
        if (bVar1 == 4) {
          (this->parent).parent.mStatus = (this->parent).parent.mStatus & ~DoNotExecuteIfDidNotDraw;
          (this->parent).parent.mScale.x = d_a_npc_fa1::_4148;
        }
        else {
          (this->parent).parent.mScale.x = DAT_803e42ac;
        }
        if (this->field_0x794 == 1) {
          *(undefined *)&this->field_0x793 = 1;
          (this->parent).parent.mStatus = (this->parent).parent.mStatus & ~DoNotExecuteIfDidNotDraw;
          iVar4 = d_a_npc_fa1::cLib_getRndValue(0,0xff);
          (this->parent).parent.mCurrent.mRot.y =
               (this->parent).parent.mCurrent.mRot.y + (short)(iVar4 << 8);
        }
        else {
          this->field_0x794 = 0;
        }
        init_normal_move(this);
      }
    }
  }
  fVar2 = (this->parent).parent.mCurrent.mPos.z;
  fVar3 = (this->parent).parent.mCurrent.mPos.y + d_a_npc_fa1::_4149;
  (this->mGndChk).parent.mPos.x = (this->parent).parent.mCurrent.mPos.x;
  (this->mGndChk).parent.mPos.y = fVar3;
  (this->mGndChk).parent.mPos.z = fVar2;
  dVar6 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                    &(this->mGndChk).parent);
  this->mGroundYPos = (float)dVar6;
  if ((this->field_0x794 != 6) && (d_a_npc_fa1::_4150 != this->mGroundYPos)) {
    (this->parent).parent.mOrig.mPos.y = d_a_npc_fa1::_4151 + this->mGroundYPos;
  }
  ::dCcD_Stts::Init(&(this->parent).mStts,0xff,0xff,(fopAc_ac_c *)this);
  (this->parent).mCyl.parent.parent.parent.mpStts = &(this->parent).mStts;
  ::dCcD_Cyl::Set(&(this->parent).mCyl,(dCcD_SrcCyl *)&d_a_npc_fa1::l_cyl_src);
  setMtx(this);
  if (this->field_0x794 == 3) {
    setPointLightParam(this);
    d_kankyo::dKy_efplight_set((LIGHT_INFLUENCE *)&this->field_0x744);
  }
  pJVar5 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x52,
                              &(this->parent).parent.mCurrent.mPos,(csXyz *)0x0,(cXyz *)0x0,0xff,
                              &(this->mSparklePtclCallback).parent,-1,(_GXColor *)0x0,
                              (_GXColor *)0x0,(cXyz *)0x0);
  this->mpEmitter = pJVar5;
  return 1;
}


/* __thiscall daNpc_Fa1_c::_draw(void) */

undefined4 __thiscall daNpc_Fa1_c::_draw(daNpc_Fa1_c *this)

{
  J3DModel *pJVar1;
  double dVar2;
  
  pJVar1 = *(J3DModel **)(*(int *)&this->field_0x6cc + 0x50);
  dScnKy_env_light_c::settingTevStruct
            (&d_kankyo::g_env_light,Actor,&(this->parent).parent.mCurrent.mPos,
             &(this->parent).parent.mTevStr);
  dScnKy_env_light_c::setLightTevColorType
            (&d_kankyo::g_env_light,pJVar1,&(this->parent).parent.mTevStr);
  mDoExt_McaMorf::entryDL(*(mDoExt_McaMorf **)&this->field_0x6cc);
  if (d_a_npc_fa1::_4150 != this->mGroundYPos) {
    dDlst_shadowControl_c::setSimple
              (&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mShadowControl,
               &(this->parent).parent.mCurrent.mPos,this->mGroundYPos,d_a_npc_fa1::_4168,
               (cXyz *)&this->field_0x774,0,d_a_npc_fa1::_4169,&dDlst_shadowControl_c::mSimpleTexObj
              );
  }
  dVar2 = (double)d_a_npc_fa1::_4169;
  d_snap::dSnap_RegistFig(dVar2,dVar2,dVar2,0x84,(fopAc_ac_c *)this);
  return 1;
}


/* __thiscall daNpc_Fa1_c::_execute(void) */

undefined4 __thiscall daNpc_Fa1_c::_execute(daNpc_Fa1_c *this)

{
  d_a_npc_fa1::cLib_calcTimer(&this->field_0x788);
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_a_npc_fa1::moveProc + (uint)*(byte *)&this->field_0x790 * 3),this,
             &DAT_80390000);
  (this->parent).parent.mCollisionRot.y = (this->parent).parent.mCurrent.mRot.y;
  mDoExt_McaMorf::play(*(mDoExt_McaMorf **)&this->field_0x6cc,(cXyz *)0x0,0,0);
  setMtx(this);
  if (this->field_0x794 == 3) {
    setPointLightParam(this);
  }
  if ((*(char *)&this->field_0x790 == '\x01') && (this->mpEmitter != (JPABaseEmitter *)0x0)) {
    this->mpEmitter->mRate = d_a_npc_fa1::_4169;
  }
  dAttLook_c::request(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.field_0x148,
                      (fopAc_ac_c *)this,d_a_npc_fa1::_4199,d_a_npc_fa1::_4200,d_a_npc_fa1::_4201,
                      0x6000,1);
  return 1;
}


/* __thiscall daNpc_Fa1_c::checkBinCatch(void) */

bool __thiscall daNpc_Fa1_c::checkBinCatch(daNpc_Fa1_c *this)

{
  bool bVar1;
  
  bVar1 = (this->parent).parent.mEvtInfo.mCommand != 6;
  if (bVar1) {
    dAttCatch_c::request
              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.mCatch,(fopAc_ac_c *)this,'W',
               DAT_803e42b8,DAT_803e42bc,DAT_803e42c0,DAT_803e42e4,1);
    (this->parent).parent.mEvtInfo.mCondition = (this->parent).parent.mEvtInfo.mCondition | 0x40;
  }
  else {
    f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  }
  return !bVar1;
}


/* __thiscall daNpc_Fa1_c::position_move(float,
                                         float) */

void __thiscall daNpc_Fa1_c::position_move(daNpc_Fa1_c *this,float param_1,float param_2)

{
  float fVar1;
  
  fVar1 = (this->parent).parent.mCurrent.mPos.y - (this->parent).parent.mOrig.mPos.y;
  if (fVar1 <= param_1) {
    if (fVar1 < -param_1) {
      (this->parent).parent.mVelocityYMin = param_2;
    }
  }
  else {
    (this->parent).parent.mVelocityYMin = -param_2;
  }
  if (d_a_npc_fa1::_4082 <= (this->parent).parent.mVelocityYMin) {
    (this->parent).parent.mVelocity.y =
         (this->parent).parent.mVelocity.y + (this->parent).parent.mAccelerationY;
    fVar1 = (this->parent).parent.mVelocityYMin;
    if (fVar1 < (this->parent).parent.mVelocity.y) {
      (this->parent).parent.mVelocity.y = fVar1;
    }
  }
  else {
    (this->parent).parent.mVelocity.y =
         (this->parent).parent.mVelocity.y - (this->parent).parent.mAccelerationY;
    fVar1 = (this->parent).parent.mVelocityYMin;
    if ((this->parent).parent.mVelocity.y < fVar1) {
      (this->parent).parent.mVelocity.y = fVar1;
    }
  }
  (this->parent).parent.mVelocity.x =
       (this->parent).parent.mVelocityFwd *
       JKernel::JMath::jmaSinTable
       [(int)((int)(this->parent).parent.mCurrent.mRot.y & 0xffffU) >>
        (JKernel::JMath::jmaSinShift & 0x3f)];
  (this->parent).parent.mVelocity.z =
       (this->parent).parent.mVelocityFwd *
       JKernel::JMath::jmaCosTable
       [(int)((int)(this->parent).parent.mCurrent.mRot.y & 0xffffU) >>
        (JKernel::JMath::jmaSinShift & 0x3f)];
  f_op_actor_mng::fopAcM_posMove((fopAc_ac_c *)this,(cXyz *)0x0);
  return;
}


/* __thiscall daNpc_Fa1_c::BGCheck(void) */

void __thiscall daNpc_Fa1_c::BGCheck(daNpc_Fa1_c *this)

{
  float fVar1;
  cM3dGPla *pcVar2;
  byte bVar3;
  double dVar4;
  
  (this->mGndChk).parent.mPos.x = (this->parent).parent.mCurrent.mPos.x;
  (this->mGndChk).parent.mPos.y = (this->parent).parent.mCurrent.mPos.y;
  (this->mGndChk).parent.mPos.z = (this->parent).parent.mCurrent.mPos.z;
  dVar4 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                    &(this->mGndChk).parent);
  this->mGroundYPos = (float)dVar4;
  fVar1 = d_a_npc_fa1::_4082;
  if ((double)d_a_npc_fa1::_4150 == dVar4) {
    *(float *)&this->field_0x774 = d_a_npc_fa1::_4082;
    *(float *)&this->field_0x778 = d_a_npc_fa1::_4169;
    *(float *)&this->field_0x77c = fVar1;
  }
  else {
    pcVar2 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                             (uint)(ushort)(this->mGndChk).parent.mPolyInfo.mBgIndex,
                             (uint)(ushort)(this->mGndChk).parent.mPolyInfo.mTriIdx);
    *(float *)&this->field_0x774 = (pcVar2->mNorm).x;
    *(float *)&this->field_0x778 = (pcVar2->mNorm).y;
    *(float *)&this->field_0x77c = (pcVar2->mNorm).z;
    bVar3 = dBgS::GetRoomId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                            &(this->mGndChk).parent.mPolyInfo);
    (this->parent).parent.mCurrent.mRoomNo = bVar3;
    (this->parent).parent.mTevStr.mRoomNo = bVar3;
    bVar3 = dBgS::GetPolyColor(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                               &(this->mGndChk).parent.mPolyInfo);
    (this->parent).parent.mTevStr.mEnvrIdxOverride = bVar3;
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_normal_move(void) */

void __thiscall daNpc_Fa1_c::init_normal_move(daNpc_Fa1_c *this)

{
  short sVar1;
  
  *(undefined *)&this->field_0x790 = 0;
  (this->parent).parent.mVelocityFwd = FLOAT_803e42a4;
  (this->parent).parent.mAccelerationY = d_a_npc_fa1::_4275;
  (this->parent).parent.mVelocityYMin = d_a_npc_fa1::_4276;
  sVar1 = d_a_npc_fa1::cLib_getRndValue(DAT_803e42e0,0x3c);
  this->field_0x788 = sVar1;
  if (this->field_0x794 == 4) {
    init_areaMove(this);
  }
  else {
    init_straight2(this);
  }
  return;
}


/* __thiscall daNpc_Fa1_c::normal_move(void) */

void __thiscall daNpc_Fa1_c::normal_move(daNpc_Fa1_c *this)

{
  int iVar1;
  
  (this->parent).parent.mVelocityFwd = FLOAT_803e42a4;
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_a_npc_fa1::moveSubProc + (uint)*(byte *)&this->field_0x792 * 3),this,
             &DAT_80390000);
  position_move(this,d_a_npc_fa1::_4168,d_a_npc_fa1::_4169);
  BGCheck(this);
  findPlayer(this);
  ::cM3dGCyl::SetC(&(this->parent).mCyl.mCylAttr.mCyl,&(this->parent).parent.mCurrent.mPos);
  cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)&(this->parent).mCyl);
  iVar1 = dCcD_GObjInf::ChkCoHit(&(this->parent).mCyl.parent);
  if (iVar1 == 0) {
    iVar1 = checkBinCatch(this);
    if (((iVar1 == 0) && ((*(byte *)&this->field_0x793 & 1) != 0)) && (this->field_0x788 == 0)) {
      init_escape_move(this);
    }
  }
  else {
    init_get_player_move(this);
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_straight(void) */

void __thiscall daNpc_Fa1_c::init_straight(daNpc_Fa1_c *this)

{
  undefined uVar1;
  
  *(undefined *)&this->field_0x792 = 0;
  uVar1 = d_a_npc_fa1::cLib_getRndValue(0x3c,0x3c);
  *(undefined *)&this->field_0x791 = uVar1;
  (this->parent).parent.mAccelerationY = d_a_npc_fa1::_4275;
  return;
}


/* __thiscall daNpc_Fa1_c::init_straight2(void) */

void __thiscall daNpc_Fa1_c::init_straight2(daNpc_Fa1_c *this)

{
  *(undefined *)&this->field_0x792 = 0;
  *(undefined *)&this->field_0x791 = 0;
  (this->parent).parent.mAccelerationY = d_a_npc_fa1::_4169;
  return;
}


/* __thiscall daNpc_Fa1_c::straight(void) */

void __thiscall daNpc_Fa1_c::straight(daNpc_Fa1_c *this)

{
  char cVar1;
  double dVar2;
  double dVar3;
  float fVar4;
  cXyz local_34;
  cXyz local_28;
  float local_1c;
  float local_18;
  float local_14;
  
  (this->parent).parent.mScale.x = DAT_803e42ac;
  cVar1 = m_Do_audio::cLib_calcTimer(&this->field_0x791);
  if (cVar1 == '\0') {
    ::cXyz::operator__(&local_28,&(this->parent).parent.mCurrent.mPos,
                       &(this->parent).parent.mOrig.mPos);
    local_1c = local_28.x;
    local_18 = local_28.y;
    local_14 = local_28.z;
    local_34.x = local_28.x;
    local_34.y = d_a_npc_fa1::_4082;
    local_34.z = local_28.z;
    fVar4 = mtx::PSVECSquareMag(&local_34);
    dVar3 = (double)fVar4;
    if ((double)d_a_npc_fa1::_4082 < dVar3) {
      dVar2 = 1.0 / SQRT(dVar3);
      dVar2 = d_a_npc_fa1::_4339 * dVar2 * (d_a_npc_fa1::_4340 - dVar3 * dVar2 * dVar2);
      dVar2 = d_a_npc_fa1::_4339 * dVar2 * (d_a_npc_fa1::_4340 - dVar3 * dVar2 * dVar2);
      dVar3 = (double)(float)(dVar3 * d_a_npc_fa1::_4339 * dVar2 *
                                      (d_a_npc_fa1::_4340 - dVar3 * dVar2 * dVar2));
    }
    if ((double)(this->parent).parent.mScale.x < dVar3) {
      init_turn(this);
    }
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_turn(void) */

void __thiscall daNpc_Fa1_c::init_turn(daNpc_Fa1_c *this)

{
  undefined uVar1;
  
  *(undefined *)&this->field_0x792 = 1;
  uVar1 = d_a_npc_fa1::cLib_getRndValue(0x3c,0x3c);
  *(undefined *)&this->field_0x791 = uVar1;
  (this->parent).parent.mAccelerationY = d_a_npc_fa1::_4275;
  return;
}


/* __thiscall daNpc_Fa1_c::turn(void) */

void __thiscall daNpc_Fa1_c::turn(daNpc_Fa1_c *this)

{
  char cVar2;
  int iVar1;
  cXyz local_28;
  float local_1c;
  float local_18;
  float local_14;
  
  cVar2 = m_Do_audio::cLib_calcTimer(&this->field_0x791);
  if (cVar2 == '\0') {
    init_straight(this);
  }
  else {
    ::cXyz::operator__(&local_28,&(this->parent).parent.mCurrent.mPos,
                       &(this->parent).parent.mOrig.mPos);
    local_1c = local_28.x;
    local_18 = local_28.y;
    local_14 = local_28.z;
    iVar1 = SComponent::cM_atan2s(-local_28.x,-local_28.z);
    SComponent::cLib_addCalcAngleS(&(this->parent).parent.mCurrent.mRot.y,(short)iVar1,0x20,0x800,1)
    ;
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_areaMove(void) */

void __thiscall daNpc_Fa1_c::init_areaMove(daNpc_Fa1_c *this)

{
  *(undefined *)&this->field_0x792 = 2;
  (this->parent).parent.mAccelerationY = d_a_npc_fa1::_4169;
  *(undefined2 *)&this->field_0x798 = 0;
  *(undefined2 *)&this->field_0x79a = 0;
  return;
}


/* __thiscall daNpc_Fa1_c::areaMove(void) */

void __thiscall daNpc_Fa1_c::areaMove(daNpc_Fa1_c *this)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  double dVar4;
  double dVar5;
  float fVar6;
  cXyz local_34;
  cXyz local_28;
  float local_1c;
  float local_18;
  float local_14;
  
  ::cXyz::operator__(&local_28,&(this->parent).parent.mCurrent.mPos,
                     &(this->parent).parent.mOrig.mPos);
  local_1c = local_28.x;
  local_18 = local_28.y;
  local_14 = local_28.z;
  local_34.x = local_28.x;
  local_34.y = d_a_npc_fa1::_4082;
  local_34.z = local_28.z;
  fVar6 = mtx::PSVECSquareMag(&local_34);
  dVar5 = (double)fVar6;
  if ((double)d_a_npc_fa1::_4082 < dVar5) {
    dVar4 = 1.0 / SQRT(dVar5);
    dVar4 = d_a_npc_fa1::_4339 * dVar4 * (d_a_npc_fa1::_4340 - dVar5 * dVar4 * dVar4);
    dVar4 = d_a_npc_fa1::_4339 * dVar4 * (d_a_npc_fa1::_4340 - dVar5 * dVar4 * dVar4);
    dVar5 = (double)(float)(dVar5 * d_a_npc_fa1::_4339 * dVar4 *
                                    (d_a_npc_fa1::_4340 - dVar5 * dVar4 * dVar4));
  }
  if (dVar5 <= (double)(this->parent).parent.mScale.x) {
    sVar1 = (this->parent).parent.mCurrent.mRot.y;
    sVar2 = d_a_arrow::cLib_calcTimer(&this->field_0x798);
    if (sVar2 == 0) {
      *(ushort *)&this->field_0x79a = *(ushort *)&this->field_0x79a ^ 1;
      uVar3 = d_a_nh::cLib_getRndValue(0xf,0x14);
      *(ushort *)&this->field_0x798 = uVar3 & 0xff;
    }
    sVar2 = 0x2000;
    if (*(short *)&this->field_0x79a != 0) {
      sVar2 = -0x2000;
    }
    SComponent::cLib_addCalcAngleS
              (&(this->parent).parent.mCurrent.mRot.y,sVar1 + sVar2,0x20,0x800,1);
  }
  else {
    init_areaOutMove(this);
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_areaOutMove(void) */

void __thiscall daNpc_Fa1_c::init_areaOutMove(daNpc_Fa1_c *this)

{
  *(undefined *)&this->field_0x792 = 3;
  (this->parent).parent.mAccelerationY = d_a_npc_fa1::_4275;
  *(undefined2 *)&this->field_0x798 = 0;
  *(undefined2 *)&this->field_0x79a = 0;
  return;
}


/* __thiscall daNpc_Fa1_c::areaOutMove(void) */

void __thiscall daNpc_Fa1_c::areaOutMove(daNpc_Fa1_c *this)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  double dVar4;
  double dVar5;
  float fVar6;
  cXyz local_34;
  cXyz local_28;
  float local_1c;
  float local_18;
  float local_14;
  
  ::cXyz::operator__(&local_28,&(this->parent).parent.mCurrent.mPos,
                     &(this->parent).parent.mOrig.mPos);
  local_1c = local_28.x;
  local_18 = local_28.y;
  local_14 = local_28.z;
  local_34.x = local_28.x;
  local_34.y = d_a_npc_fa1::_4082;
  local_34.z = local_28.z;
  fVar6 = mtx::PSVECSquareMag(&local_34);
  dVar5 = (double)fVar6;
  if ((double)d_a_npc_fa1::_4082 < dVar5) {
    dVar4 = 1.0 / SQRT(dVar5);
    dVar4 = d_a_npc_fa1::_4339 * dVar4 * (d_a_npc_fa1::_4340 - dVar5 * dVar4 * dVar4);
    dVar4 = d_a_npc_fa1::_4339 * dVar4 * (d_a_npc_fa1::_4340 - dVar5 * dVar4 * dVar4);
    dVar5 = (double)(float)(dVar5 * d_a_npc_fa1::_4339 * dVar4 *
                                    (d_a_npc_fa1::_4340 - dVar5 * dVar4 * dVar4));
  }
  if ((double)(this->parent).parent.mScale.x <= dVar5) {
    sVar1 = SComponent::cLib_targetAngleY
                      (&(this->parent).parent.mCurrent.mPos,&(this->parent).parent.mOrig.mPos);
    sVar2 = d_a_arrow::cLib_calcTimer(&this->field_0x798);
    if (sVar2 == 0) {
      *(ushort *)&this->field_0x79a = *(ushort *)&this->field_0x79a ^ 1;
      uVar3 = d_a_nh::cLib_getRndValue(0xf,0x14);
      *(ushort *)&this->field_0x798 = uVar3 & 0xff;
    }
    sVar2 = 0x2000;
    if (*(short *)&this->field_0x79a != 0) {
      sVar2 = -0x2000;
    }
    SComponent::cLib_addCalcAngleS
              (&(this->parent).parent.mCurrent.mRot.y,sVar1 + sVar2,0x20,0x800,1);
  }
  else {
    init_areaMove(this);
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_get_player_move(void) */

void __thiscall daNpc_Fa1_c::init_get_player_move(daNpc_Fa1_c *this)

{
  sbyte sVar1;
  
  *(undefined *)&this->field_0x790 = 1;
  this->field_0x788 = DAT_803e42de;
  *(undefined2 *)&this->field_0x78a = DAT_803e42d8;
  *(float *)&this->field_0x780 = d_a_npc_fa1::_4149;
  (this->parent).parent.mCurrent.mRot.y = 0;
  (this->mMcaMorfCallback1).field_0x4 = 0;
  (this->parent).parent.mCurrent.mPos.y =
       ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent.mPos.y;
  sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).parent.mCurrent.mRoomNo);
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x695d,&(this->parent).parent.mCurrent.mPos,0,sVar1,
             d_a_npc_fa1::_4169,d_a_npc_fa1::_4169,d_a_npc_fa1::_4276,d_a_npc_fa1::_4276,0);
  return;
}


/* __thiscall daNpc_Fa1_c::get_player_move(void) */

void __thiscall daNpc_Fa1_c::get_player_move(daNpc_Fa1_c *this)

{
  float fVar1;
  uint uVar2;
  daPy_lk_c *pdVar3;
  short sVar4;
  cXyz local_18;
  
  fVar1 = *(float *)(*(int *)&this->field_0x6cc + 100) + d_a_npc_fa1::_4497;
  if (d_a_npc_fa1::_4498 < fVar1) {
    fVar1 = d_a_npc_fa1::_4498;
  }
  *(float *)(*(int *)&this->field_0x6cc + 100) = fVar1;
  sVar4 = *(short *)&this->field_0x78a;
  (this->parent).parent.mCurrent.mRot.y = (this->parent).parent.mCurrent.mRot.y - sVar4;
  sVar4 = sVar4 + DAT_803e42dc;
  if (DAT_803e42da < sVar4) {
    sVar4 = DAT_803e42da;
  }
  *(short *)&this->field_0x78a = sVar4;
  pdVar3 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  uVar2 = (int)(this->parent).parent.mCurrent.mRot.y + 0x4000U & 0xffff;
  *(float *)&this->field_0x768 =
       *(float *)&this->field_0x780 *
       JKernel::JMath::jmaSinTable[(int)uVar2 >> (JKernel::JMath::jmaSinShift & 0x3f)];
  *(float *)&this->field_0x770 =
       *(float *)&this->field_0x780 *
       JKernel::JMath::jmaCosTable[(int)uVar2 >> (JKernel::JMath::jmaSinShift & 0x3f)];
  *(float *)&this->field_0x76c = *(float *)&this->field_0x76c + DAT_803e42a8;
  ::cXyz::operator__(&local_18,&(pdVar3->parent).parent.mCurrent.mPos,(cXyz *)&this->field_0x768);
  (this->parent).parent.mCurrent.mPos.x = local_18.x;
  (this->parent).parent.mCurrent.mPos.y = local_18.y;
  (this->parent).parent.mCurrent.mPos.z = local_18.z;
  BGCheck(this);
  if (this->field_0x788 == 0) {
    d_item::execItemGet(Fairy);
    f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_escape_move(void) */

void __thiscall daNpc_Fa1_c::init_escape_move(daNpc_Fa1_c *this)

{
  *(undefined *)&this->field_0x790 = 2;
  (this->parent).parent.mAccelerationY = DAT_803e42b4;
  (this->parent).parent.mVelocityYMin = DAT_803e42b0;
  this->field_0x788 = DAT_803e42e2;
  return;
}


/* __thiscall daNpc_Fa1_c::escape_move(void) */

void __thiscall daNpc_Fa1_c::escape_move(daNpc_Fa1_c *this)

{
  float fVar1;
  short sVar3;
  int iVar2;
  
  (this->parent).parent.mVelocity.y =
       (this->parent).parent.mVelocity.y + (this->parent).parent.mAccelerationY;
  fVar1 = (this->parent).parent.mVelocityYMin;
  if (fVar1 < (this->parent).parent.mVelocity.y) {
    (this->parent).parent.mVelocity.y = fVar1;
  }
  (this->parent).parent.mVelocity.x =
       (this->parent).parent.mVelocityFwd *
       JKernel::JMath::jmaSinTable
       [(int)((int)(this->parent).parent.mCurrent.mRot.y & 0xffffU) >>
        (JKernel::JMath::jmaSinShift & 0x3f)];
  (this->parent).parent.mVelocity.z =
       (this->parent).parent.mVelocityFwd *
       JKernel::JMath::jmaCosTable
       [(int)((int)(this->parent).parent.mCurrent.mRot.y & 0xffffU) >>
        (JKernel::JMath::jmaSinShift & 0x3f)];
  f_op_actor_mng::fopAcM_posMove((fopAc_ac_c *)this,(cXyz *)0x0);
  BGCheck(this);
  sVar3 = (this->mMcaMorfCallback1).field_0x4;
  if (sVar3 < 0) {
    sVar3 = sVar3 + 0x800;
    if (0 < sVar3) {
      sVar3 = 0;
    }
  }
  else {
    if ((0 < sVar3) && (sVar3 = sVar3 + -0x800, sVar3 < 0)) {
      sVar3 = 0;
    }
  }
  (this->mMcaMorfCallback1).field_0x4 = sVar3;
  ::cM3dGCyl::SetC(&(this->parent).mCyl.mCylAttr.mCyl,&(this->parent).parent.mCurrent.mPos);
  cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)&(this->parent).mCyl);
  iVar2 = dCcD_GObjInf::ChkCoHit(&(this->parent).mCyl.parent);
  if (iVar2 == 0) {
    if (this->field_0x788 == 0) {
      f_op_actor_mng::fopAcM_delete((base_process_class *)this);
    }
  }
  else {
    init_get_player_move(this);
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_hover_move(void) */

void __thiscall daNpc_Fa1_c::init_hover_move(daNpc_Fa1_c *this)

{
  *(undefined *)&this->field_0x790 = 8;
  (this->parent).parent.mAccelerationY = DAT_803e4320;
  (this->parent).parent.mVelocityYMin = -DAT_803e431c;
  (this->parent).parent.mVelocityFwd = d_a_npc_fa1::_4082;
  return;
}


/* __thiscall daNpc_Fa1_c::hover_move(void) */

void __thiscall daNpc_Fa1_c::hover_move(daNpc_Fa1_c *this)

{
  short target;
  
  position_move(this,DAT_803e4324,DAT_803e431c);
  BGCheck(this);
  target = f_op_actor_mng::fopAcM_searchActorAngleY
                     ((fopAc_ac_c *)this,
                      (fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor);
  SComponent::cLib_addCalcAngleS(&(this->parent).parent.mCurrent.mRot.y,target,8,0x2000,0x400);
  return;
}


/* __thiscall daNpc_Fa1_c::init_bottle_appear_move(void) */

void __thiscall daNpc_Fa1_c::init_bottle_appear_move(daNpc_Fa1_c *this)

{
  *(undefined *)&this->field_0x790 = 3;
  init_up1(this);
  if (this->field_0x794 == 5) {
    d_item::execItemGet(Fairy);
  }
  return;
}


/* __thiscall daNpc_Fa1_c::bottle_appear_move(void) */

void __thiscall daNpc_Fa1_c::bottle_appear_move(daNpc_Fa1_c *this)

{
  float fVar1;
  uint uVar2;
  daPy_lk_c *pdVar3;
  cXyz local_18;
  
  fVar1 = *(float *)(*(int *)&this->field_0x6cc + 100) + d_a_npc_fa1::_4497;
  if (d_a_npc_fa1::_4498 < fVar1) {
    fVar1 = d_a_npc_fa1::_4498;
  }
  *(float *)(*(int *)&this->field_0x6cc + 100) = fVar1;
  (this->parent).parent.mCurrent.mRot.y =
       (this->parent).parent.mCurrent.mRot.y - *(short *)&this->field_0x78a;
  *(short *)&this->field_0x78a = *(short *)&this->field_0x78a + *(short *)&this->field_0x78e;
  if (*(short *)&this->field_0x78c < *(short *)&this->field_0x78a) {
    *(short *)&this->field_0x78a = *(short *)&this->field_0x78c;
  }
  pdVar3 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  uVar2 = (int)(this->parent).parent.mCurrent.mRot.y + 0x4000U & 0xffff;
  *(float *)&this->field_0x768 =
       *(float *)&this->field_0x780 *
       JKernel::JMath::jmaSinTable[(int)uVar2 >> (JKernel::JMath::jmaSinShift & 0x3f)];
  *(float *)&this->field_0x770 =
       *(float *)&this->field_0x780 *
       JKernel::JMath::jmaCosTable[(int)uVar2 >> (JKernel::JMath::jmaSinShift & 0x3f)];
  *(float *)&this->field_0x76c = *(float *)&this->field_0x76c + (this->parent).parent.mVelocity.y;
  ::cXyz::operator__(&local_18,&(pdVar3->parent).parent.mCurrent.mPos,(cXyz *)&this->field_0x768);
  (this->parent).parent.mCurrent.mPos.x = local_18.x;
  (this->parent).parent.mCurrent.mPos.y = local_18.y;
  (this->parent).parent.mCurrent.mPos.z = local_18.z;
  if (d_a_npc_fa1::_4082 <= (this->parent).parent.mVelocityYMin) {
    (this->parent).parent.mVelocity.y =
         (this->parent).parent.mVelocity.y + (this->parent).parent.mAccelerationY;
    fVar1 = (this->parent).parent.mVelocityYMin;
    if (fVar1 < (this->parent).parent.mVelocity.y) {
      (this->parent).parent.mVelocity.y = fVar1;
    }
  }
  else {
    (this->parent).parent.mVelocity.y =
         (this->parent).parent.mVelocity.y - (this->parent).parent.mAccelerationY;
    fVar1 = (this->parent).parent.mVelocityYMin;
    if ((this->parent).parent.mVelocity.y < fVar1) {
      (this->parent).parent.mVelocity.y = fVar1;
    }
  }
  *(float *)&this->field_0x780 = *(float *)&this->field_0x780 + d_a_npc_fa1::_4598;
  if (d_a_npc_fa1::_4149 < *(float *)&this->field_0x780) {
    *(float *)&this->field_0x780 = d_a_npc_fa1::_4149;
  }
  BGCheck(this);
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_a_npc_fa1::bottleMoveSubProc + (uint)*(byte *)&this->field_0x792 * 3),this,
             &DAT_80390000);
  if (this->field_0x788 == 0) {
    if (this->field_0x794 != 5) {
      d_item::execItemGet(Fairy);
    }
    f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_up1(void) */

void __thiscall daNpc_Fa1_c::init_up1(daNpc_Fa1_c *this)

{
  int iVar1;
  double dVar2;
  double dVar3;
  float fVar4;
  cXyz local_24;
  cXyz local_18;
  
  *(undefined *)&this->field_0x792 = 0;
  this->field_0x788 = DAT_803e42e6;
  (this->parent).parent.mVelocityYMin = DAT_803e42cc;
  (this->parent).parent.mVelocity.y = DAT_803e42c4;
  (this->parent).parent.mAccelerationY = DAT_803e42d0;
  *(undefined2 *)&this->field_0x78a = 0;
  *(undefined2 *)&this->field_0x78c = 0;
  *(undefined2 *)&this->field_0x78e = 0;
  ::cXyz::operator__(&local_18,&(this->parent).parent.mCurrent.mPos,
                     &((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                      mCurrent.mPos);
  *(float *)&this->field_0x768 = local_18.x;
  *(float *)&this->field_0x76c = local_18.y;
  *(float *)&this->field_0x770 = local_18.z;
  local_24.z = *(float *)&this->field_0x770;
  local_24.x = *(float *)&this->field_0x768;
  local_24.y = d_a_npc_fa1::_4082;
  fVar4 = mtx::PSVECSquareMag(&local_24);
  dVar3 = (double)fVar4;
  if ((double)d_a_npc_fa1::_4082 < dVar3) {
    dVar2 = 1.0 / SQRT(dVar3);
    dVar2 = d_a_npc_fa1::_4339 * dVar2 * (d_a_npc_fa1::_4340 - dVar3 * dVar2 * dVar2);
    dVar2 = d_a_npc_fa1::_4339 * dVar2 * (d_a_npc_fa1::_4340 - dVar3 * dVar2 * dVar2);
    dVar3 = (double)(float)(dVar3 * d_a_npc_fa1::_4339 * dVar2 *
                                    (d_a_npc_fa1::_4340 - dVar3 * dVar2 * dVar2));
  }
  *(float *)&this->field_0x780 = (float)dVar3;
  iVar1 = SComponent::cM_atan2s(*(float *)&this->field_0x768,*(float *)&this->field_0x770);
  (this->parent).parent.mCurrent.mRot.y = (short)iVar1 + -0x4000;
  return;
}


/* __thiscall daNpc_Fa1_c::up1(void) */

void __thiscall daNpc_Fa1_c::up1(daNpc_Fa1_c *this)

{
  if ((this->parent).parent.mVelocity.y < d_a_npc_fa1::_4082) {
    init_down(this);
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_down(void) */

void __thiscall daNpc_Fa1_c::init_down(daNpc_Fa1_c *this)

{
  *(undefined *)&this->field_0x792 = 1;
  *(undefined2 *)&this->field_0x78c = DAT_803e42e8;
  *(undefined2 *)&this->field_0x78e = DAT_803e42ea;
  return;
}


/* __thiscall daNpc_Fa1_c::down(void) */

void __thiscall daNpc_Fa1_c::down(daNpc_Fa1_c *this)

{
  if (*(float *)&this->field_0x76c < DAT_803e42d4) {
    init_up2(this);
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_up2(void) */

void __thiscall daNpc_Fa1_c::init_up2(daNpc_Fa1_c *this)

{
  sbyte sVar1;
  
  *(undefined *)&this->field_0x792 = 2;
  (this->parent).parent.mVelocityYMin = DAT_803e42c8;
  sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).parent.mCurrent.mRoomNo);
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x6975,&(this->parent).parent.mCurrent.mPos,0,sVar1,
             d_a_npc_fa1::_4169,d_a_npc_fa1::_4169,d_a_npc_fa1::_4276,d_a_npc_fa1::_4276,0);
  return;
}


/* __thiscall daNpc_Fa1_c::up2(void) */

void __thiscall daNpc_Fa1_c::up2(daNpc_Fa1_c *this)

{
  return;
}


/* __thiscall daNpc_Fa1_c::init_bottle_baba_wait(void) */

void __thiscall daNpc_Fa1_c::init_bottle_baba_wait(daNpc_Fa1_c *this)

{
  float fVar1;
  
  *(undefined *)&this->field_0x790 = 4;
  fVar1 = d_a_npc_fa1::_4082;
  (this->parent).parent.mVelocity.x = d_a_npc_fa1::_4082;
  (this->parent).parent.mVelocity.y = fVar1;
  (this->parent).parent.mVelocity.z = fVar1;
  (this->parent).parent.mVelocityFwd = fVar1;
  (this->parent).parent.mVelocityYMin = fVar1;
  (this->parent).parent.mAccelerationY = fVar1;
  this->field_0x788 = DAT_803e4310;
  return;
}


/* __thiscall daNpc_Fa1_c::bottle_baba_wait(void) */

void __thiscall daNpc_Fa1_c::bottle_baba_wait(daNpc_Fa1_c *this)

{
  if (this->field_0x788 == 0) {
    init_bottle_baba_move2(this);
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_bottle_baba_move(void) */

void __thiscall daNpc_Fa1_c::init_bottle_baba_move(daNpc_Fa1_c *this)

{
  *(undefined *)&this->field_0x790 = 5;
  f_op_actor_mng::fopAcM_SearchByName(0x151,(fopAc_ac_c **)&this->field_0x764);
  this->field_0x788 = DAT_803e430e;
  (this->parent).parent.mVelocityFwd = DAT_803e42f4;
  *(undefined2 *)&this->field_0x798 = 1;
  *(undefined4 *)&this->field_0x79c = DAT_803e42fc;
  *(undefined4 *)&this->field_0x7a0 = DAT_803e42f8;
  if (*(int *)&this->field_0x764 != 0) {
    (this->parent).parent.mCurrent.mPos.x =
         d_a_npc_fa1::_4693 + *(float *)(*(int *)&this->field_0x764 + 0x1f8);
    (this->parent).parent.mCurrent.mPos.z = *(float *)(*(int *)&this->field_0x764 + 0x200);
  }
  init_baba_down(this);
  return;
}


/* __thiscall daNpc_Fa1_c::bottle_baba_move(void) */

void __thiscall daNpc_Fa1_c::bottle_baba_move(daNpc_Fa1_c *this)

{
  byte bVar1;
  float fVar2;
  int iVar3;
  actor_place *paVar4;
  cXyz local_28;
  float local_1c;
  float local_18;
  float local_14;
  
  if (*(int *)&this->field_0x764 == 0) {
    init_bottle_baba_move(this);
    BGCheck(this);
  }
  else {
    (this->parent).parent.mVelocityFwd = DAT_803e42f4;
    ::cXyz::operator__(&local_28,(cXyz *)(*(int *)&this->field_0x764 + 0x1f8),
                       &(this->parent).parent.mCurrent.mPos);
    local_1c = local_28.x;
    local_18 = local_28.y;
    local_14 = local_28.z;
    iVar3 = SComponent::cM_atan2s(local_28.x,local_28.z);
    (this->parent).parent.mCurrent.mRot.y = (short)iVar3 + DAT_803e430c;
    (this->parent).parent.mVelocity.x =
         (this->parent).parent.mVelocityFwd *
         JKernel::JMath::jmaSinTable
         [(int)((int)(this->parent).parent.mCurrent.mRot.y & 0xffffU) >>
          (JKernel::JMath::jmaSinShift & 0x3f)];
    (this->parent).parent.mVelocity.z =
         (this->parent).parent.mVelocityFwd *
         JKernel::JMath::jmaCosTable
         [(int)((int)(this->parent).parent.mCurrent.mRot.y & 0xffffU) >>
          (JKernel::JMath::jmaSinShift & 0x3f)];
    if (d_a_npc_fa1::_4082 <= (this->parent).parent.mVelocityYMin) {
      (this->parent).parent.mVelocity.y =
           (this->parent).parent.mVelocity.y + (this->parent).parent.mAccelerationY;
      fVar2 = (this->parent).parent.mVelocityYMin;
      if (fVar2 < (this->parent).parent.mVelocity.y) {
        (this->parent).parent.mVelocity.y = fVar2;
      }
    }
    else {
      (this->parent).parent.mVelocity.y =
           (this->parent).parent.mVelocity.y - (this->parent).parent.mAccelerationY;
      fVar2 = (this->parent).parent.mVelocityYMin;
      if ((this->parent).parent.mVelocity.y < fVar2) {
        (this->parent).parent.mVelocity.y = fVar2;
      }
    }
    paVar4 = &(this->parent).parent.mCurrent;
    mtx::PSVECAdd(&paVar4->mPos,&(this->parent).parent.mVelocity,&paVar4->mPos);
    BGCheck(this);
    bVar1 = *(byte *)&this->field_0x792;
    Runtime.PPCEABI.H::__ptmf_scall
              ((PTMF *)(&d_a_npc_fa1::bottleBabaSubProc + (uint)bVar1 * 3),this,&DAT_80390000);
    if ((bVar1 == 1) &&
       (d_a_npc_fa1::_4729 + *(float *)(*(int *)&this->field_0x764 + 0x1fc) <
        (this->parent).parent.mCurrent.mPos.y)) {
      f_op_actor_mng::fopAcM_delete((base_process_class *)this);
    }
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_bottle_baba_move2(void) */

void __thiscall daNpc_Fa1_c::init_bottle_baba_move2(daNpc_Fa1_c *this)

{
  *(undefined *)&this->field_0x790 = 6;
  *(daPy_lk_c **)&this->field_0x764 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  (this->parent).parent.mVelocityFwd = DAT_803e42f4;
  *(undefined2 *)&this->field_0x798 = 0;
  *(undefined4 *)&this->field_0x79c = DAT_803e4304;
  *(undefined4 *)&this->field_0x7a0 = DAT_803e4300;
  init_baba_down(this);
  return;
}


/* __thiscall daNpc_Fa1_c::bottle_baba_move2(void) */

void __thiscall daNpc_Fa1_c::bottle_baba_move2(daNpc_Fa1_c *this)

{
  float fVar1;
  int iVar2;
  actor_place *paVar3;
  cXyz local_28;
  float local_1c;
  float local_18;
  float local_14;
  
  if (*(int *)&this->field_0x764 == 0) {
    init_bottle_baba_move2(this);
    BGCheck(this);
  }
  else {
    (this->parent).parent.mVelocityFwd = DAT_803e42f4;
    ::cXyz::operator__(&local_28,(cXyz *)(*(int *)&this->field_0x764 + 0x1f8),
                       &(this->parent).parent.mCurrent.mPos);
    local_1c = local_28.x;
    local_18 = local_28.y;
    local_14 = local_28.z;
    iVar2 = SComponent::cM_atan2s(local_28.x,local_28.z);
    (this->parent).parent.mCurrent.mRot.y = (short)iVar2 + DAT_803e430c;
    (this->parent).parent.mVelocity.x =
         (this->parent).parent.mVelocityFwd *
         JKernel::JMath::jmaSinTable
         [(int)((int)(this->parent).parent.mCurrent.mRot.y & 0xffffU) >>
          (JKernel::JMath::jmaSinShift & 0x3f)];
    (this->parent).parent.mVelocity.z =
         (this->parent).parent.mVelocityFwd *
         JKernel::JMath::jmaCosTable
         [(int)((int)(this->parent).parent.mCurrent.mRot.y & 0xffffU) >>
          (JKernel::JMath::jmaSinShift & 0x3f)];
    if (d_a_npc_fa1::_4082 <= (this->parent).parent.mVelocityYMin) {
      (this->parent).parent.mVelocity.y =
           (this->parent).parent.mVelocity.y + (this->parent).parent.mAccelerationY;
      fVar1 = (this->parent).parent.mVelocityYMin;
      if (fVar1 < (this->parent).parent.mVelocity.y) {
        (this->parent).parent.mVelocity.y = fVar1;
      }
    }
    else {
      (this->parent).parent.mVelocity.y =
           (this->parent).parent.mVelocity.y - (this->parent).parent.mAccelerationY;
      fVar1 = (this->parent).parent.mVelocityYMin;
      if ((this->parent).parent.mVelocity.y < fVar1) {
        (this->parent).parent.mVelocity.y = fVar1;
      }
    }
    paVar3 = &(this->parent).parent.mCurrent;
    mtx::PSVECAdd(&paVar3->mPos,&(this->parent).parent.mVelocity,&paVar3->mPos);
    BGCheck(this);
    Runtime.PPCEABI.H::__ptmf_scall
              ((PTMF *)(&d_a_npc_fa1::bottleBabaSubProc + (uint)*(byte *)&this->field_0x792 * 3),
               this,&DAT_80390000);
    if (d_a_npc_fa1::_4769 + *(float *)(*(int *)&this->field_0x764 + 0x1fc) <
        (this->parent).parent.mCurrent.mPos.y) {
      init_bottle_baba_move(this);
    }
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_baba_down(void) */

void __thiscall daNpc_Fa1_c::init_baba_down(daNpc_Fa1_c *this)

{
  sbyte sVar1;
  
  *(undefined *)&this->field_0x792 = 0;
  (this->parent).parent.mVelocity.y = d_a_npc_fa1::_4082;
  (this->parent).parent.mVelocityYMin = *(float *)&this->field_0x79c;
  (this->parent).parent.mAccelerationY = DAT_803e4308;
  if (*(char *)&this->field_0x790 == '\x05') {
    sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).parent.mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x6a2e,&(this->parent).parent.mCurrent.mPos,0,sVar1,
               d_a_npc_fa1::_4169,d_a_npc_fa1::_4169,d_a_npc_fa1::_4276,d_a_npc_fa1::_4276,0);
  }
  return;
}


/* __thiscall daNpc_Fa1_c::baba_down(void) */

void __thiscall daNpc_Fa1_c::baba_down(daNpc_Fa1_c *this)

{
  if ((this->parent).parent.mCurrent.mPos.y < *(float *)(*(int *)&this->field_0x764 + 0x1fc)) {
    init_baba_up(this);
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_baba_up(void) */

void __thiscall daNpc_Fa1_c::init_baba_up(daNpc_Fa1_c *this)

{
  sbyte sVar1;
  
  *(undefined *)&this->field_0x792 = 1;
  (this->parent).parent.mVelocityYMin = *(float *)&this->field_0x7a0;
  if (*(char *)&this->field_0x790 == '\x06') {
    sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).parent.mCurrent.mRoomNo);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x6a2d,&(this->parent).parent.mCurrent.mPos,0,sVar1,
               d_a_npc_fa1::_4169,d_a_npc_fa1::_4169,d_a_npc_fa1::_4276,d_a_npc_fa1::_4276,0);
  }
  return;
}


/* __thiscall daNpc_Fa1_c::init_bigelf_change(void) */

void __thiscall daNpc_Fa1_c::init_bigelf_change(daNpc_Fa1_c *this)

{
  actor_place *paVar1;
  
  *(undefined *)&this->field_0x790 = 7;
  (this->parent).parent.mStatus = (this->parent).parent.mStatus | 0x4000;
  (this->parent).parent.mVelocityFwd = DAT_803e4328;
  (this->parent).parent.mVelocity.x =
       (this->parent).parent.mVelocityFwd *
       JKernel::JMath::jmaSinTable
       [(int)((int)(this->parent).parent.mCurrent.mRot.y & 0xffffU) >>
        (JKernel::JMath::jmaSinShift & 0x3f)];
  (this->parent).parent.mVelocity.z =
       (this->parent).parent.mVelocityFwd *
       JKernel::JMath::jmaCosTable
       [(int)((int)(this->parent).parent.mCurrent.mRot.y & 0xffffU) >>
        (JKernel::JMath::jmaSinShift & 0x3f)];
  paVar1 = &(this->parent).parent.mCurrent;
  mtx::PSVECAdd(&paVar1->mPos,&(this->parent).parent.mVelocity,&paVar1->mPos);
  return;
}


/* __thiscall daNpc_Fa1_c::bigelf_change(void) */

void __thiscall daNpc_Fa1_c::bigelf_change(daNpc_Fa1_c *this)

{
  int iVar1;
  actor_place *paVar2;
  cXyz local_28;
  float local_1c;
  float local_18;
  float local_14;
  
  ::cXyz::operator__(&local_28,&(this->parent).parent.mOrig.mPos,
                     &(this->parent).parent.mCurrent.mPos);
  local_1c = local_28.x;
  local_18 = local_28.y;
  local_14 = local_28.z;
  iVar1 = SComponent::cM_atan2s(local_28.x,local_28.z);
  (this->parent).parent.mCurrent.mRot.y = (short)iVar1 + DAT_803e432c;
  (this->parent).parent.mVelocity.x =
       (this->parent).parent.mVelocityFwd *
       JKernel::JMath::jmaSinTable
       [(int)((int)(this->parent).parent.mCurrent.mRot.y & 0xffffU) >>
        (JKernel::JMath::jmaSinShift & 0x3f)];
  (this->parent).parent.mVelocity.z =
       (this->parent).parent.mVelocityFwd *
       JKernel::JMath::jmaCosTable
       [(int)((int)(this->parent).parent.mCurrent.mRot.y & 0xffffU) >>
        (JKernel::JMath::jmaSinShift & 0x3f)];
  paVar2 = &(this->parent).parent.mCurrent;
  mtx::PSVECAdd(&paVar2->mPos,&(this->parent).parent.mVelocity,&paVar2->mPos);
  BGCheck(this);
  return;
}


/* __thiscall daNpc_Fa1_c::findPlayer(void) */

void __thiscall daNpc_Fa1_c::findPlayer(daNpc_Fa1_c *this)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  short sVar6;
  cXyz local_28;
  float local_1c;
  float local_18;
  float local_14;
  
  ::cXyz::operator__(&local_28,
                     &((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                      mCurrent.mPos,&(this->parent).parent.mCurrent.mPos);
  local_1c = local_28.x;
  local_18 = local_28.y;
  local_14 = local_28.z;
  iVar5 = SComponent::cM_atan2s(local_28.x,local_28.z);
  sVar2 = (short)iVar5 - (this->parent).parent.mCurrent.mRot.y;
  sVar1 = (this->mMcaMorfCallback1).field_0x4;
  if (sVar2 < 0) {
    if (sVar2 < -0x4000) {
      sVar2 = -0x4000;
    }
    uVar3 = sVar2 - sVar1;
    sVar4 = ((short)uVar3 >> 2) + (ushort)((short)uVar3 < 0 && (uVar3 & 3) != 0);
    if (sVar4 < -0x800) {
      sVar4 = -0x800;
    }
    sVar6 = sVar1 + sVar4;
    if ((short)(sVar1 + sVar4) < sVar2) {
      sVar6 = sVar2;
    }
  }
  else {
    if (0x4000 < sVar2) {
      sVar2 = 0x4000;
    }
    uVar3 = sVar2 - sVar1;
    sVar4 = ((short)uVar3 >> 2) + (ushort)((short)uVar3 < 0 && (uVar3 & 3) != 0);
    if (0x800 < sVar4) {
      sVar4 = 0x800;
    }
    sVar6 = sVar1 + sVar4;
    if (sVar2 < (short)(sVar1 + sVar4)) {
      sVar6 = sVar2;
    }
  }
  (this->mMcaMorfCallback1).field_0x4 = sVar6;
  return;
}


/* __thiscall daNpc_Fa1_c::_delete(void) */

undefined4 __thiscall daNpc_Fa1_c::_delete(daNpc_Fa1_c *this)

{
  (*(code *)((this->mSparklePtclCallback).parent.vtbl)->end)(&this->mSparklePtclCallback);
  if (this->field_0x794 == 3) {
    d_kankyo::dKy_efplight_cut((LIGHT_INFLUENCE *)&this->field_0x744);
  }
  if (d_a_npc_fa1::l_hio_counter != 0) {
    d_a_npc_fa1::l_hio_counter = d_a_npc_fa1::l_hio_counter + -1;
  }
  if ((d_a_npc_fa1::l_hio_counter < 1) && (-1 < DAT_803e42a0)) {
    mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e42a0);
    DAT_803e42a0 = -1;
  }
  return 1;
}


namespace d_a_npc_fa1 {

/* __stdcall CheckCreateHeap(fopAc_ac_c *) */

void CheckCreateHeap(daNpc_Fa1_c *param_1)

{
  ::daNpc_Fa1_c::CreateHeap(param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daNpc_Fa1_c::_create(void) */

undefined4 __thiscall daNpc_Fa1_c::_create(daNpc_Fa1_c *this)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (d_a_npc_fa1::init_4889 == '\0') {
    d_a_npc_fa1::a_heap_size_tbl_4888 = 0x1100;
    d_a_npc_fa1::init_4889 = '\x01';
  }
  uVar3 = 4;
  if (((this->parent).parent.mCondition & Constructed) == 0) {
    if (this != (daNpc_Fa1_c *)0x0) {
      daNpc_Fa1_c(this);
    }
    (this->parent).parent.mCondition = (this->parent).parent.mCondition | Constructed;
  }
  uVar1 = f_op_actor_mng::fopAcM_entrySolidHeap
                    ((fopAc_ac_c *)this,d_a_npc_fa1::CheckCreateHeap,
                     d_a_npc_fa1::a_heap_size_tbl_4888);
  if ((uVar1 & 0xff) == 0) {
    uVar3 = 5;
  }
  else {
    (this->parent).parent.mpCullMtx = (MTX34 *)(*(int *)(*(int *)&this->field_0x6cc + 0x50) + 0x24);
    if (DAT_803e42a0 < '\0') {
      DAT_803e42a0 = mDoHIO_subRoot_c::createChild
                               (&mDoHIO_subRoot_c_803a5778,"回復妖精",
                                (JORReflexible *)&d_a_npc_fa1::l_HIO);
      d_a_npc_fa1::l_hio_counter = 1;
    }
    else {
      d_a_npc_fa1::l_hio_counter = d_a_npc_fa1::l_hio_counter + 1;
    }
    iVar2 = createInit(this);
    if (iVar2 == 0) {
      uVar3 = 5;
    }
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall daNpc_Fa1_c::daNpc_Fa1_c(void) */

void __thiscall daNpc_Fa1_c::daNpc_Fa1_c(daNpc_Fa1_c *this)

{
  dBgS_PolyPassChk *pdVar1;
  
  fopAc_ac_c::fopAc_ac_c((fopAc_ac_c *)this);
  (this->parent).vtbl = &::fopNpc_npc_c::__vt;
  (this->parent).mJntCtrl.field_0xc = 0;
  (this->parent).mJntCtrl.field_0xb = 0;
  (this->parent).mEventCut.mpActor = (fopAc_ac_c *)0x0;
  (this->parent).mEventCut.mpTalkActor = (fopNpc_npc_c *)0x0;
  (this->parent).field_0x32c = 0;
  dBgS_Acch::dBgS_Acch((dBgS_Acch *)&(this->parent).mObjAcch);
  (this->parent).mObjAcch.parent.mChk.vtbl = &::dBgS_ObjAcch::__vt.mChk_vtbl;
  (this->parent).mObjAcch.parent.mDChk.mPolyPassChk.parent.vtbl =
       (cBgS_PolyPassChk__vtbl *)0x8037e9e4;
  (this->parent).mObjAcch.parent.mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)0x8037e9f0
  ;
  (this->parent).mObjAcch.parent.mDChk.mPolyPassChk.parent.mbObjThrough = 1;
  ::dBgS_AcchCir::dBgS_AcchCir(&(this->parent).mAcchCir);
  (this->parent).mStts.parent.vtbl = &cCcD_Stts::__vt;
  ::dCcD_GStts::dCcD_GStts(&(this->parent).mStts.mGStts);
  (this->parent).mStts.parent.vtbl = &::dCcD_Stts::__vt.parent;
  (this->parent).mStts.mGStts.parent.vtbl = (cCcD_GStts__vtbl *)0x8037ec40;
  dCcD_GObjInf::dCcD_GObjInf(&(this->parent).mCyl.parent);
  (this->parent).mCyl.mCylAttr.parent.vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_ShapeAttr::__vt;
  (this->parent).mCyl.mCylAttr.parent.mAab.vtbl = &::cM3dGAab::__vt;
  (this->parent).mCyl.mCylAttr.mCyl.vtbl = (cCcD_CylAttr__vtbl *)&::cM3dGCyl::__vt;
  (this->parent).mCyl.mCylAttr.parent.vtbl = &::cCcD_CylAttr::__vt;
  (this->parent).mCyl.mCylAttr.mCyl.vtbl = &cCcD_CylAttr__vtbl_803951ac;
  (this->parent).mCyl.parent.parent.parent.parent.vtbl = &::dCcD_Cyl::__vt.parent;
  (this->parent).mCyl.mCylAttr.parent.vtbl = &::dCcD_Cyl::__vt.mCyl_vtbl;
  (this->parent).mCyl.mCylAttr.mCyl.vtbl = &::dCcD_Cyl::__vt.mCylAttr_vtbl;
  (this->parent).mCurrMsgBsPcId = -1;
  (this->parent).mpCurrMsg = (msg_class *)0x0;
  (this->parent).vtbl = (fopNpc_npc_c__vtbl *)&__vt;
  daNpc_Fa1_McaMorfCallBack1_c::daNpc_Fa1_McaMorfCallBack1_c(&this->mMcaMorfCallback1);
  dPa_followEcallBack::dPa_followEcallBack(&this->mSparklePtclCallback,0,0);
  ::cBgS_GndChk::cBgS_GndChk(&(this->mGndChk).parent);
  (this->mGndChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
  (this->mGndChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt;
  (this->mGndChk).mPolyPassChk.parent.mbObjThrough = 0;
  (this->mGndChk).mPolyPassChk.parent.mbCamThrough = 0;
  (this->mGndChk).mPolyPassChk.parent.mbLinkThrough = 0;
  (this->mGndChk).mPolyPassChk.parent.mbArrowsAndLightThrough = 0;
  (this->mGndChk).mPolyPassChk.parent.mbBombThrough = 0;
  (this->mGndChk).mPolyPassChk.parent.mbBoomerangThrough = 0;
  (this->mGndChk).mPolyPassChk.parent.mbHookshotThrough = 0;
  (this->mGndChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
  (this->mGndChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
  (this->mGndChk).mGrpPassChk.parent.mAttr = 1;
  (this->mGndChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
  (this->mGndChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
  (this->mGndChk).parent.parent.vtbl = &::dBgS_GndChk::__vt;
  (this->mGndChk).parent.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  (this->mGndChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  (this->mGndChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
  (this->mGndChk).parent.parent.mpPolyPassChk = (cBgS_PolyPassChk *)&(this->mGndChk).mPolyPassChk;
  pdVar1 = &(this->mGndChk).mPolyPassChk;
  if (pdVar1 != (dBgS_PolyPassChk *)0x0) {
    pdVar1 = (dBgS_PolyPassChk *)&(this->mGndChk).mGrpPassChk;
  }
  (this->mGndChk).parent.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pdVar1;
  (this->mGndChk).parent.parent.vtbl = &::dBgS_ObjGndChk::__vt;
  (this->mGndChk).parent.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371ed8;
  (this->mGndChk).mPolyPassChk.parent.vtbl = &cBgS_PolyPassChk__vtbl_80371ee4;
  (this->mGndChk).mGrpPassChk.parent.vtbl = &cBgS_GrpPassChk__vtbl_80371ef0;
  (this->mGndChk).mPolyPassChk.parent.mbObjThrough = 1;
  (this->mGndChk).parent.parent.vtbl = &dBgS_ObjGndChk_All::__vt;
  (this->mGndChk).parent.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_8037d43c;
  (this->mGndChk).mPolyPassChk.parent.vtbl = &cBgS_PolyPassChk__vtbl_8037d448;
  (this->mGndChk).mGrpPassChk.parent.vtbl = &cBgS_GrpPassChk__vtbl_8037d454;
  (this->mGndChk).mGrpPassChk.parent.mAttr = (this->mGndChk).mGrpPassChk.parent.mAttr | 0xf;
  return;
}


/* __thiscall daNpc_Fa1_McaMorfCallBack1_c::~daNpc_Fa1_McaMorfCallBack1_c(void) */

void __thiscall
daNpc_Fa1_McaMorfCallBack1_c::_daNpc_Fa1_McaMorfCallBack1_c(daNpc_Fa1_McaMorfCallBack1_c *this)

{
  short in_r4;
  
  if (this != (daNpc_Fa1_McaMorfCallBack1_c *)0x0) {
    (this->parent).vtbl = &__vt;
    if (this != (daNpc_Fa1_McaMorfCallBack1_c *)0x0) {
      (this->parent).vtbl = &mDoExt_McaMorfCallBack1_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall daNpc_Fa1_c::CreateHeap(void) */

undefined4 __thiscall daNpc_Fa1_c::CreateHeap(daNpc_Fa1_c *this)

{
  J3DModelData *pModelData;
  mDoExt_McaMorf *this_00;
  J3DAnmTransformKey *pAnmRes;
  undefined4 uVar1;
  short sVar2;
  
  pModelData = (J3DModelData *)
               dRes_control_c::getRes
                         ("Always",0x1f,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40
                         );
  this_00 = (mDoExt_McaMorf *)JKernel::operator_new(0xb4);
  if (this_00 != (mDoExt_McaMorf *)0x0) {
    pAnmRes = (J3DAnmTransformKey *)
              dRes_control_c::getRes
                        ("Always",0xc,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    this_00 = mDoExt_McaMorf::mDoExt_McaMorf
                        (this_00,1,pModelData,&(this->mMcaMorfCallback1).parent,
                         (mDoExt_McaMorfCallBack2_c *)0x0,pAnmRes,Repeat,d_a_npc_fa1::_4169,0,-1,0,
                         (void *)0x0,0,0x11020203);
  }
  *(mDoExt_McaMorf **)&this->field_0x6cc = this_00;
  if (*(int *)&this->field_0x6cc == 0) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(*(int *)&this->field_0x6cc + 0x50) == 0) {
      *(undefined4 *)&this->field_0x6cc = 0;
      uVar1 = 0;
    }
    else {
      sVar2 = JUTNameTab::getIndex((pModelData->mJointTree).mpNameTable,"neck");
      (this->mMcaMorfCallback1).field_0x6 = sVar2;
      (this->mMcaMorfCallback1).field_0x4 = 0;
      uVar1 = 1;
    }
  }
  return uVar1;
}


/* __thiscall daNpc_Fa1_c::setMtx(void) */

void __thiscall daNpc_Fa1_c::setMtx(daNpc_Fa1_c *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)&this->field_0x6cc + 0x50);
  mtx::PSMTXTrans((double)(this->parent).parent.mCurrent.mPos.x,
                  (double)(this->parent).parent.mCurrent.mPos.y,
                  (double)(this->parent).parent.mCurrent.mPos.z,&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,(this->parent).parent.mCollisionRot.y);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(iVar3 + 0x24));
  mDoExt_McaMorf::calc(*(mDoExt_McaMorf **)&this->field_0x6cc);
  iVar3 = *(int *)(*(int *)(*(int *)&this->field_0x6cc + 0x50) + 0x8c) +
          (uint)(ushort)(this->mMcaMorfCallback1).field_0x6 * 0x30;
  fVar1 = *(float *)(iVar3 + 0x2c);
  fVar2 = *(float *)(iVar3 + 0x1c);
  (this->parent).parent.mAttentionPos.x = *(float *)(iVar3 + 0xc);
  (this->parent).parent.mAttentionPos.y = fVar2;
  (this->parent).parent.mAttentionPos.z = fVar1;
  (this->parent).parent.mEyePos.x = (this->parent).parent.mAttentionPos.x;
  (this->parent).parent.mEyePos.y = (this->parent).parent.mAttentionPos.y;
  (this->parent).parent.mEyePos.z = (this->parent).parent.mAttentionPos.z;
  return;
}


namespace d_a_npc_fa1 {

/* __stdcall daNpc_Fa1_Create(fopAc_ac_c *) */

void daNpc_Fa1_Create(daNpc_Fa1_c *param_1)

{
  ::daNpc_Fa1_c::_create(param_1);
  return;
}


/* __stdcall daNpc_Fa1_Delete(daNpc_Fa1_c *) */

void daNpc_Fa1_Delete(daNpc_Fa1_c *param_1)

{
  ::daNpc_Fa1_c::_delete(param_1);
  return;
}


/* __stdcall daNpc_Fa1_Execute(daNpc_Fa1_c *) */

void daNpc_Fa1_Execute(daNpc_Fa1_c *param_1)

{
  ::daNpc_Fa1_c::_execute(param_1);
  return;
}


/* __stdcall daNpc_Fa1_Draw(daNpc_Fa1_c *) */

void daNpc_Fa1_Draw(daNpc_Fa1_c *param_1)

{
  ::daNpc_Fa1_c::_draw(param_1);
  return;
}


/* __stdcall daNpc_Fa1_IsDelete(daNpc_Fa1_c *) */

undefined4 daNpc_Fa1_IsDelete(void)

{
  return 1;
}

}

/* __thiscall daNpc_Fa1_HIO_c::~daNpc_Fa1_HIO_c(void) */

void __thiscall daNpc_Fa1_HIO_c::_daNpc_Fa1_HIO_c(daNpc_Fa1_HIO_c *this)

{
  short in_r4;
  
  if (this != (daNpc_Fa1_HIO_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (daNpc_Fa1_HIO_c *)0xffffff88) {
      *(undefined1 **)(this + 0x78) = &daNpc_Fa1_HIO3_c::__vt;
    }
    if (this != (daNpc_Fa1_HIO_c *)0xffffffb0) {
      *(undefined1 **)(this + 0x50) = &daNpc_Fa1_HIO2_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_a_npc_fa1 {

/* __stdcall cLib_calcTimer<unsigned short>(unsigned short *) */

short cLib_calcTimer(short *param_1)

{
  if (*param_1 != 0) {
    *param_1 = *param_1 + -1;
  }
  return *param_1;
}


/* __stdcall cLib_getRndValue<unsigned char>(unsigned char,
                                             unsigned char) */

int cLib_getRndValue(uint param_1,uint param_2)

{
  float fVar1;
  
  fVar1 = SComponent::cM_rndF((float)((double)CONCAT44(0x43300000,param_2 & 0xff) - _5397));
  return (int)((float)((double)CONCAT44(0x43300000,param_1 & 0xff) - _5397) + fVar1);
}


/* __stdcall cLib_getRndValue<unsigned short>(unsigned short,
                                              unsigned short) */

int cLib_getRndValue(uint param_1,uint param_2)

{
  float fVar1;
  
  fVar1 = SComponent::cM_rndF((float)((double)CONCAT44(0x43300000,param_2 & 0xffff) - _5397));
  return (int)((float)((double)CONCAT44(0x43300000,param_1 & 0xffff) - _5397) + fVar1);
}


void __sinit_d_a_npc_fa1_cpp(void)

{
  ::daNpc_Fa1_HIO_c::daNpc_Fa1_HIO_c((daNpc_Fa1_HIO_c *)&l_HIO);
  Runtime.PPCEABI.H::__register_global_object();
  moveProc = _4170;
  DAT_8038d30c = DAT_8038d2a0;
  DAT_8038d310 = PTR_normal_move_8038d2a4;
  DAT_8038d314 = _4171;
  DAT_8038d318 = DAT_8038d2ac;
  DAT_8038d31c = PTR_get_player_move_8038d2b0;
  DAT_8038d320 = _4172;
  DAT_8038d324 = DAT_8038d2b8;
  DAT_8038d328 = PTR_escape_move_8038d2bc;
  DAT_8038d32c = _4173;
  DAT_8038d330 = DAT_8038d2c4;
  DAT_8038d334 = PTR_bottle_appear_move_8038d2c8;
  DAT_8038d338 = _4174;
  DAT_8038d33c = DAT_8038d2d0;
  DAT_8038d340 = PTR_bottle_baba_wait_8038d2d4;
  DAT_8038d344 = _4175;
  DAT_8038d348 = DAT_8038d2dc;
  DAT_8038d34c = PTR_bottle_baba_move_8038d2e0;
  DAT_8038d350 = _4176;
  DAT_8038d354 = DAT_8038d2e8;
  DAT_8038d358 = PTR_bottle_baba_move2_8038d2ec;
  DAT_8038d35c = _4177;
  DAT_8038d360 = DAT_8038d2f4;
  DAT_8038d364 = PTR_bigelf_change_8038d2f8;
  DAT_8038d368 = _4178;
  DAT_8038d36c = DAT_8038d300;
  DAT_8038d370 = PTR_hover_move_8038d304;
  moveSubProc = _4262;
  DAT_8038d3a8 = DAT_8038d378;
  DAT_8038d3ac = PTR_straight_8038d37c;
  DAT_8038d3b0 = _4263;
  DAT_8038d3b4 = DAT_8038d384;
  DAT_8038d3b8 = PTR_turn_8038d388;
  DAT_8038d3bc = _4264;
  DAT_8038d3c0 = DAT_8038d390;
  DAT_8038d3c4 = PTR_areaMove_8038d394;
  DAT_8038d3c8 = _4265;
  DAT_8038d3cc = DAT_8038d39c;
  DAT_8038d3d0 = PTR_areaOutMove_8038d3a0;
  bottleMoveSubProc = _4546;
  DAT_8038d3fc = DAT_8038d3d8;
  DAT_8038d400 = PTR_up1_8038d3dc;
  DAT_8038d404 = _4547;
  DAT_8038d408 = DAT_8038d3e4;
  DAT_8038d40c = PTR_down_8038d3e8;
  DAT_8038d410 = _4548;
  DAT_8038d414 = DAT_8038d3f0;
  DAT_8038d418 = PTR_up2_8038d3f4;
  bottleBabaSubProc = _4681;
  DAT_8038d438 = DAT_8038d420;
  DAT_8038d43c = PTR_baba_down_8038d424;
  DAT_8038d440 = _4682;
  DAT_8038d444 = DAT_8038d42c;
  DAT_8038d448 = PTR_up2_8038d430;
  return;
}

}

/* __thiscall fopNpc_npc_c::next_msgStatus(unsigned long *) */

undefined4 __thiscall fopNpc_npc_c::next_msgStatus(fopNpc_npc_c *this,ulong *param_1)

{
  return 0x10;
}


/* __thiscall fopNpc_npc_c::getMsg(void) */

undefined4 __thiscall fopNpc_npc_c::getMsg(fopNpc_npc_c *this)

{
  return 0;
}


/* __thiscall fopNpc_npc_c::anmAtr(unsigned short) */

void __thiscall fopNpc_npc_c::anmAtr(fopNpc_npc_c *this,ushort param_1)

{
  return;
}

