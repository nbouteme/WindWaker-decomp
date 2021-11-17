#include <d_com_static.h>
#include <SComponent/c_lib.h>
#include <d_salvage.h>
#include <d_kankyo.h>
#include <d_save.h>
#include <d_com_static.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <d_a_ib.h>
#include <f_op_actor.h>
#include <SComponent/c_math.h>
#include <f_op_actor_mng.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <d_particle.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JKernel/JKRHeap.h>
#include <daArrow_c.h>
#include <daTagKbItem_c.h>
#include <daTitle_proc_c.h>
#include <daAgbsw0_c.h>
#include <daSalvage_c.h>
#include <daObjLight/Act_c.h>
#include <daIball_c.h>
#include <daSteamTag_c.h>
#include <daObj_Roten_c.h>
#include <JPACallBackBase<JPABaseEmitter*>.h>
#include <dPa_smokeEcallBack.h>
#include <daNpc_Md_c.h>
#include <dPa_levelEcallBack.h>
#include <daDai_c.h>


namespace Global {
undefined g_dComIfG_gameInfo.field_0x1d1d4;
}
undefined1 daNpc_Os_c;
undefined1 daNpc_Os_c;
undefined1 daIball_c;
undefined1 daLodbg_c;
undefined1 daLodbg_c;
undefined1 daSteamTag_c;
undefined1 daYkgr_c;
undefined1 daYkgr_c;
undefined1 daYkgr_c;
float daYkgr_c;
undefined1 daYkgr_c;
undefined1 daYkgr_c;

namespace daTagWaterlevel {

namespace Act_c {
undefined1 M_now;
undefined1 M_state;
}
}
undefined1 daAgbsw0_c;
undefined1 daAgbsw0_c;
undefined1 daSalvage_c;
undefined1 daSalvage_c;
undefined1 daSalvage_c;

namespace daObjLight {
short Act_c;
int Act_c;
int Act_c;
undefined1 Act_c;
}
undefined1 daDai_c;
undefined1 daDai_c;
undefined1 daNpc_Md_c;
undefined1 daNpc_Md_c;
undefined1 daNpc_Md_c;
undefined1 daNpc_Md_c;
undefined1 daNpc_Md_c;
undefined1 daNpc_Sarace_c;
undefined1 daNpc_Sarace_c;
undefined1 daCanon_c;
undefined1 daNpc_Kg2_c;
undefined1 daNpc_Kg2_c;
undefined1 daArrow_c;
undefined1 daNpc_Ji1_c;
byte daNpc_kam_c;
undefined1 daNpc_Bs1_c;
undefined1 daNpc_Bs1_c;
undefined1 daNpc_Bs1_c;

/* __thiscall daSteamTag_c::init(void) */

int __thiscall daSteamTag_c::init(daSteamTag_c *this,EVP_PKEY_CTX *ctx)

{
  mEmitterNum = 0;
  return (int)this;
}


namespace daObjPirateship {

/* WARNING: Removing unreachable block (ram,0x800566d0) */
/* __thiscall getShipOffsetY(short *,
                                              short *,
                                              float) */

double getShipOffsetY(short *param_1,short *param_2,float param_3)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar2 = (double)param_3;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((*param_1 < 0x4001) && (-0x4001 < *param_1)) {
    SComponent::cLib_addCalcAngleS2(param_2,0x180,0x10,0x300);
  }
  else {
    SComponent::cLib_addCalcAngleS2(param_2,0x280,0x10,0x300);
  }
  *param_1 = *param_1 + *param_2;
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return (double)(float)(dVar2 * (double)JKernel::JMath::jmaSinTable
                                         [(int)((int)*param_1 & 0xffffU) >>
                                          (JKernel::JMath::jmaSinShift & 0x3f)]);
}

}

/* __thiscall daAgbsw0_c::incTclDispose(void) */

void __thiscall daAgbsw0_c::incTclDispose(daAgbsw0_c *this)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.mpAgb == (daAgb_c *)0x0) {
    return;
  }
  if (*(char *)&(d_com_inf_game::g_dComIfG_gameInfo.mpAgb)->field_0x672 == '\0') {
    return;
  }
  if (1 < mFigureDispose) {
    return;
  }
  mFigureDispose = mFigureDispose + 1;
  return;
}


/* __thiscall daAgbsw0_c::incTclBeat(void) */

void __thiscall daAgbsw0_c::incTclBeat(daAgbsw0_c *this)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.mpAgb == (daAgb_c *)0x0) {
    return;
  }
  if (*(char *)&(d_com_inf_game::g_dComIfG_gameInfo.mpAgb)->field_0x672 == '\0') {
    return;
  }
  if (5 < mFigureBeat) {
    return;
  }
  mFigureBeat = mFigureBeat + 1;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daSalvage_c::init_room(signed char) */

void __thiscall daSalvage_c::init_room(daSalvage_c *this,char param_1)

{
  if (_mTagData_p != (dSalvage_control_c *)0x0) {
    dSalvage_control_c::init_room(_mTagData_p,(char)this);
  }
  return;
}


namespace daObjLight {

/* __thiscall Act_c::renew_light_angle(void) */

undefined4 __thiscall Act_c::renew_light_angle(Act_c *this)

{
  bool bVar3;
  int iVar1;
  undefined4 uVar2;
  
  M_S_lod_access = 1;
  bVar3 = d_kankyo::dKy_daynight_check();
  if ((bVar3 == true) &&
     (iVar1 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1c02),
     iVar1 == 1)) {
    iVar1 = get_light_dif_angle();
    set_light_dif_angle_LOD((short)iVar1 + 0x80);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


namespace Act_c {

/* __thiscall get_light_angle(void) */

int get_light_angle(void)

{
  int iVar1;
  
  iVar1 = get_light_dif_angle();
  return (int)(short)((short)iVar1 + -0x93e);
}


/* __thiscall get_light_dif_angle(void) */

int get_light_dif_angle(void)

{
  return (int)M_S_light_angle;
}


/* __thiscall set_light_dif_angle_LOD(short) */

void set_light_dif_angle_LOD(short param_1)

{
  if (SComponent::g_Counter != M_S_pre_set_frame_FRRS) {
    M_S_light_angle = param_1;
    M_S_pre_set_frame_LOD = SComponent::g_Counter;
    return;
  }
  M_S_pre_set_frame_LOD = SComponent::g_Counter;
  return;
}

}

/* __thiscall Act_c::set_light_dif_angle_FRRS(short) */

undefined4 __thiscall Act_c::set_light_dif_angle_FRRS(Act_c *this,short param_1)

{
  if ((SComponent::g_Counter != M_S_pre_set_frame_LOD) &&
     (SComponent::g_Counter + -1 == M_S_pre_set_frame_FRRS)) {
    M_S_light_angle = (short)this;
    M_S_pre_set_frame_FRRS = SComponent::g_Counter;
    return 1;
  }
  M_S_pre_set_frame_FRRS = SComponent::g_Counter;
  return 0;
}

}

/* __thiscall daDai_c::getMaxDaiza(void) */

undefined __thiscall daDai_c::getMaxDaiza(daDai_c *this)

{
  return mNowDaizaNum;
}


/* __thiscall daDai_c::getDaizaSetItemNum(void) */

undefined __thiscall daDai_c::getDaizaSetItemNum(daDai_c *this)

{
  return mNowItemNum;
}


/* __thiscall daNpc_Md_c::getMaxFlyingTimer(void) */

undefined4 __thiscall daNpc_Md_c::getMaxFlyingTimer(daNpc_Md_c *this)

{
  return 0x1c2;
}


/* __thiscall daArrow_c::getKeepType(void) */

undefined __thiscall daArrow_c::getKeepType(daArrow_c *this)

{
  return m_keep_type;
}


/* __thiscall daArrow_c::setKeepType(unsigned char) */

void __thiscall daArrow_c::setKeepType(daArrow_c *this,uchar param_1)

{
  m_keep_type = (char)this;
  return;
}


/* __thiscall daIball_c::init(void) */

int __thiscall daIball_c::init(daIball_c *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 5;
  do {
    *(undefined4 *)(&m_ib_actor + iVar1) = 0xffffffff;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return iVar1;
}


/* __thiscall daIball_c::regist(fopAc_ac_c *) */

void __thiscall daIball_c::regist(daIball_c *this,fopAc_ac_c *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 5;
  do {
    if (*(int *)(&m_ib_actor + iVar2) == -1) {
      if (this == (daIball_c *)0x0) {
        uVar1 = 0xffffffff;
      }
      else {
        uVar1 = *(undefined4 *)(this + 4);
      }
      *(undefined4 *)(&m_ib_actor + iVar2) = uVar1;
      return;
    }
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* __thiscall daIball_c::remove(fopAc_ac_c *) */

int __thiscall daIball_c::remove(daIball_c *this,char *__filename)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 5;
  while( true ) {
    if (this == (daIball_c *)0x0) {
      iVar2 = -1;
    }
    else {
      iVar2 = *(int *)(this + 4);
    }
    if (*(int *)(&m_ib_actor + iVar1) == iVar2) break;
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return (int)this;
    }
  }
  *(undefined4 *)(&m_ib_actor + iVar1) = 0xffffffff;
  return (int)this;
}


/* __thiscall daIball_c::remove_old(void) */

void __thiscall daIball_c::remove_old(daIball_c *this)

{
  int iVar1;
  fopAc_ac_c *this_00;
  char *__filename;
  uint uVar2;
  int iVar3;
  uint local_18 [5];
  
  local_18[0] = 0xffffffff;
  iVar1 = 0;
  iVar3 = 5;
  do {
    uVar2 = *(uint *)(&m_ib_actor + iVar1);
    if (uVar2 == 0xffffffff) {
      return;
    }
    if (uVar2 < local_18[0]) {
      local_18[0] = uVar2;
    }
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  this_00 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,local_18);
  if (this_00 != (fopAc_ac_c *)0x0) {
    dead((daIball_c *)this_00);
    remove((daIball_c *)this_00,__filename);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daObj_Roten_c::getCreateCount(void) */

int __thiscall daObj_Roten_c::getCreateCount(daObj_Roten_c *this)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  
  uVar2 = 0;
  for (bVar3 = 0; bVar3 < 0xc; bVar3 = bVar3 + 1) {
    iVar1 = dSv_player_get_bag_item_c::isReserve
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,bVar3);
    if (iVar1 == 0) {
      if (bVar3 == 0) {
        uVar2 = uVar2 + 1;
      }
    }
    else {
      uVar2 = uVar2 + 1;
    }
  }
  if ((int)uVar2 < 10) {
    if ((int)uVar2 < 7) {
      iVar1 = 1 - ((int)(((int)(uVar2 ^ 3) >> 1) - ((uVar2 ^ 3) & uVar2)) >> 0x1f);
    }
    else {
      iVar1 = 3;
    }
  }
  else {
    iVar1 = 4;
  }
  return iVar1;
}


/* __thiscall daTagKbItem_c::kb_dig(fopAc_ac_c *) */

void __thiscall daTagKbItem_c::kb_dig(daTagKbItem_c *this,fopAc_ac_c *param_1)

{
  this[0x299] = (daTagKbItem_c)0x1;
  *(fopAc_ac_c **)(this + 0x2a8) = param_1;
  dig_main(this);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80056ca0) */
/* __thiscall daTagKbItem_c::dig_main(void) */

void __thiscall daTagKbItem_c::dig_main(daTagKbItem_c *this)

{
  daTagKbItem_c dVar1;
  bool bVar3;
  daItem_c *pdVar2;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  float fVar6;
  uint local_38;
  short local_34;
  cXyz local_30;
  longlong local_20;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  bVar3 = dSv_info_c::isSwitch
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,*(int *)(this + 0x2a4),
                     (int)(char)this[0x1e2]);
  if (((bVar3 == false) && (this[0x299] != (daTagKbItem_c)0x0)) &&
     (this[0x298] == (daTagKbItem_c)0x0)) {
    local_30.x = ::cXyz::Zero.x;
    local_30.y = ::cXyz::Zero.y;
    local_30.z = ::cXyz::Zero.z;
    local_38 = ::csXyz::Zero._0_4_;
    local_34 = ::csXyz::Zero.z;
    dVar1 = (daTagKbItem_c)0x0;
    bVar3 = f_op_actor::fopAc_IsActor(*(fopAc_ac_c **)(this + 0x2a8));
    if ((bVar3 != false) && (*(short *)(*(int *)(this + 0x2a8) + 8) == 0xdd)) {
      if (this[0x2a0] != (daTagKbItem_c)0xff) {
        fVar6 = SComponent::cM_rndF(d_com_static::_4558);
        local_20 = (longlong)(int)fVar6;
        local_38 = local_38 & 0xffff0000 | (int)fVar6 & 0xffffU;
        dVar1 = this[0x20a];
        fVar6 = SComponent::cM_rndFX(d_com_static::_4559);
        dVar5 = (double)(d_com_static::_4560 + fVar6);
        fVar6 = SComponent::cM_rndF(d_com_static::_4559);
        pdVar2 = f_op_actor_mng::fopAcM_fastCreateItem
                           ((cXyz *)(*(int *)(this + 0x2a8) + 0x1f8),(uint)(byte)this[0x2a0],
                            (int)(char)dVar1,(csXyz *)&local_38,&local_30,(double)fVar6,dVar5,
                            (double)d_com_static::_4561,*(uint *)(this + 0x29c),0);
        if (pdVar2 != (daItem_c *)0x0) {
          (pdVar2->parent).parent.mStatus = (pdVar2->parent).parent.mStatus | 0x4000;
        }
        if (*(int *)(this + 0x2a4) == 0xff) {
          f_op_actor_mng::fopAcM_delete((base_process_class *)this);
        }
        else {
          dSv_info_c::onSwitch
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,*(int *)(this + 0x2a4),
                     (int)(char)this[0x1e2]);
        }
        dVar1 = (daTagKbItem_c)0x1;
      }
      if (this[0x2a1] != (daTagKbItem_c)0xff) {
        *(ushort *)(*(int *)(this + 0x2a8) + 0x1e0) = (ushort)(byte)this[0x2a1];
        dSv_info_c::onSwitch
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,*(int *)(this + 0x2a4),
                   (int)(char)this[0x1e2]);
        f_op_actor_mng::fopAcM_delete((base_process_class *)this);
        dVar1 = (daTagKbItem_c)0x1;
      }
      if ((bool)dVar1) {
        this[0x298] = dVar1;
      }
      this[0x299] = (daTagKbItem_c)0x0;
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* __thiscall daTitle_proc_c::daTitle_Kirakira_Sound_flag_on(void) */

void __thiscall daTitle_proc_c::daTitle_Kirakira_Sound_flag_on(daTitle_proc_c *this)

{
  daTitle_Kirakira_Sound_flag = 1;
  return;
}


namespace daStandItem_c {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall daiItemNodeCallBack(J3DNode *,
                                                 int) */

undefined4 daiItemNodeCallBack(J3DJoint *param_1,int param_2)

{
  byte bVar1;
  J3DModel *pJVar2;
  bool bVar3;
  daStandItem_c *pThis;
  uint uVar4;
  
  pJVar2 = J3DGraphBase::j3dSys.mpCurModel;
  if (param_2 == 0) {
    uVar4 = (uint)(ushort)(param_1->parent).mAnmMatrixIdx;
    pThis = (daStandItem_c *)(J3DGraphBase::j3dSys.mpCurModel)->mpUserData;
    if (((pThis != (daStandItem_c *)0x0) &&
        (bVar3 = f_op_actor::fopAc_IsActor((fopAc_ac_c *)pThis), bVar3 != false)) &&
       ((pThis->parent).parent.parent.mProcName == 0x1d4)) {
      mtx::PSMTXCopy(pJVar2->mpNodeMtx + uVar4,&mDoMtx_stack_c::now);
      bVar1 = pThis->mItemNo;
      if (bVar1 == 0x95) {
        if (uVar4 == 0) {
          mtx::PSMTXCopy(&mDoMtx_stack_c::now,&pThis->field_0x630);
        }
        else {
          if (uVar4 == 1) {
            mtx::PSMTXCopy(&mDoMtx_stack_c::now,&pThis->field_0x660);
          }
        }
      }
      else {
        if ((bVar1 < 0x95) && (bVar1 == 0x92)) {
          m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,pThis->field_0x6b4);
        }
      }
      mtx::PSMTXCopy(&mDoMtx_stack_c::now,pJVar2->mpNodeMtx + uVar4);
      mtx::PSMTXCopy(&mDoMtx_stack_c::now,&J3DSys::mCurrentMtx);
    }
  }
  return 1;
}

}

namespace d_com_static {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_d_com_static_cpp(void)

{
  ::dPa_smokeEcallBack::dPa_smokeEcallBack
            ((dPa_smokeEcallBack *)&::daNpc_Os_c::m_smoke,'\0','\x01','\x01','\x01');
  Runtime.PPCEABI.H::__register_global_object();
  _m_smoke_tevstr = J3DGraphBase::j3dDefaultLightInfo;
  DAT_803e1e24 = DAT_80370d1c;
  DAT_803e1e28 = DAT_80370d20;
  DAT_803e1e2c = DAT_80370d24;
  DAT_803e1e30 = DAT_80370d28;
  DAT_803e1e34 = DAT_80370d2c;
  DAT_803e1e38 = DAT_80370d30;
  DAT_803e1e39 = DAT_80370d31;
  DAT_803e1e3a = DAT_80370d32;
  DAT_803e1e3b = DAT_80370d33;
  DAT_803e1e3c = DAT_80370d34;
  DAT_803e1e40 = DAT_80370d38;
  DAT_803e1e44 = DAT_80370d3c;
  DAT_803e1e48 = DAT_80370d40;
  DAT_803e1e4c = DAT_80370d44;
  DAT_803e1e50 = DAT_80370d48;
  Runtime.PPCEABI.H::__register_global_object
            (&::daNpc_Os_c::m_smoke_tevstr,dKy_tevstr_c::_dKy_tevstr_c,&_4374);
  return;
}

}

/* __thiscall dPa_smokeEcallBack::~dPa_smokeEcallBack(void) */

void __thiscall dPa_smokeEcallBack::_dPa_smokeEcallBack(dPa_smokeEcallBack *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dPa_smokeEcallBack *)0x0;
  if (bVar1) {
    (this->parent).parent.vtbl = &__vt;
    if (((bVar1) &&
        ((this->parent).parent.vtbl = (dPa_levelEcallBack__vtbl *)&dPa_followEcallBack::__vt, bVar1)
        ) && ((this->parent).parent.vtbl = (dPa_levelEcallBack__vtbl *)&::dPa_levelEcallBack::__vt,
             bVar1)) {
      (this->parent).parent.vtbl =
           (dPa_levelEcallBack__vtbl *)&::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JPACallBackBase<JPABaseEmitter *>::draw(JPABaseEmitter *) */

void __thiscall
JPACallBackBase<JPABaseEmitter*>::draw
          (JPACallBackBase_JPABaseEmitter__ *this,JPABaseEmitter *param_1)

{
  return;
}


/* __thiscall JPACallBackBase<JPABaseEmitter *>::executeAfter(JPABaseEmitter *) */

void __thiscall
JPACallBackBase<JPABaseEmitter*>::executeAfter
          (JPACallBackBase_JPABaseEmitter__ *this,JPABaseEmitter *param_1)

{
  return;
}


/* __thiscall JPACallBackBase<JPABaseEmitter *>::execute(JPABaseEmitter *) */

void __thiscall
JPACallBackBase<JPABaseEmitter*>::execute
          (JPACallBackBase_JPABaseEmitter__ *this,JPABaseEmitter *param_1)

{
  return;
}


/* __thiscall JPACallBackBase<JPABaseEmitter *>::init(JPABaseEmitter *) */

int __thiscall
JPACallBackBase<JPABaseEmitter*>::init(JPACallBackBase_JPABaseEmitter__ *this,EVP_PKEY_CTX *ctx)

{
  return (int)this;
}


/* __thiscall JPACallBackBase<JPABaseEmitter *>::~JPACallBackBase(void) */

JPACallBackBase_JPABaseEmitter__ * __thiscall
JPACallBackBase<JPABaseEmitter*>::_JPACallBackBase(JPACallBackBase_JPABaseEmitter__ *this)

{
  short in_r4;
  
  if ((this != (JPACallBackBase_JPABaseEmitter__ *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)
     ) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return this;
}


/* __thiscall dPa_levelEcallBack::~dPa_levelEcallBack(void) */

void __thiscall dPa_levelEcallBack::_dPa_levelEcallBack(dPa_levelEcallBack *this)

{
  short in_r4;
  
  if (this != (dPa_levelEcallBack *)0x0) {
    this->vtbl = (dPa_levelEcallBack__vtbl *)&__vt;
    if (this != (dPa_levelEcallBack *)0x0) {
      this->vtbl = (dPa_levelEcallBack__vtbl *)&::JPACallBackBase<JPABaseEmitter*>::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

