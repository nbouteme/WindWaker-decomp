#include <d_a_bomb_static.h>
#include <d_a_bomb_static.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_a_bomb2.h>
#include <Demangler/daBomb2/Act_c.h>
#include <daBomb_c.h>
#include <daObj.h>


/* __thiscall daBomb_c::getBombRestTime(void) */

int __thiscall daBomb_c::getBombRestTime(daBomb_c *this)

{
  _prm_chk_version(this);
  return (int)this->field_0x6fc;
}


/* __thiscall daBomb_c::getBombCheck_Flag(void) */

undefined __thiscall daBomb_c::getBombCheck_Flag(daBomb_c *this)

{
  _prm_chk_version(this);
  return *(undefined *)&this->field_0x6f1;
}


/* __thiscall daBomb_c::setBombCheck_Flag(void) */

void __thiscall daBomb_c::setBombCheck_Flag(daBomb_c *this)

{
  _prm_chk_version(this);
  *(undefined *)&this->field_0x6f1 = 1;
  return;
}


/* __thiscall daBomb_c::setBombFire_ON(void) */

void __thiscall daBomb_c::setBombFire_ON(daBomb_c *this)

{
  _prm_chk_version(this);
  this->field_0x6f2 = 1;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall daBomb_c::setBombNoHit(void) */

void __thiscall daBomb_c::setBombNoHit(daBomb_c *this)

{
  _prm_chk_version(this);
  (this->mCcDSph).parent.parent.parent.parent.mObjTg.parent.mCommonFlag =
       (this->mCcDSph).parent.parent.parent.parent.mObjTg.parent.mCommonFlag & ~EnableCheck;
  (this->mCcDSph).parent.parent.parent.parent.mObjCo.parent.mCommonFlag =
       (this->mCcDSph).parent.parent.parent.parent.mObjCo.parent.mCommonFlag & ~EnableCheck;
  (this->mCcDSph).parent.parent.parent.parent.mObjAt.parent.mCommonFlag =
       (this->mCcDSph).parent.parent.parent.parent.mObjAt.parent.mCommonFlag & 0xfffffffe;
  (this->mCcDSph).parent.parent.parent.parent.mObjAt.parent.mCommonFlag =
       (this->mCcDSph).parent.parent.parent.parent.mObjAt.parent.mCommonFlag & 0xfffffffe;
  *(undefined *)&this->field_0x6f3 = 1;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall daBomb_c::setBombOffCoSet(void) */

void __thiscall daBomb_c::setBombOffCoSet(daBomb_c *this)

{
  _prm_chk_version(this);
  (this->mCcDSph).parent.parent.parent.parent.mObjCo.parent.mCommonFlag =
       (this->mCcDSph).parent.parent.parent.parent.mObjCo.parent.mCommonFlag & ~EnableCheck;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall daBomb_c::setBombOnCoSet(void) */

void __thiscall daBomb_c::setBombOnCoSet(daBomb_c *this)

{
  _prm_chk_version(this);
  (this->mCcDSph).parent.parent.parent.parent.mObjCo.parent.mCommonFlag =
       (this->mCcDSph).parent.parent.parent.parent.mObjCo.parent.mCommonFlag | EnableCheck;
  return;
}


/* __thiscall daBomb_c::setBombNoEff(void) */

void __thiscall daBomb_c::setBombNoEff(daBomb_c *this)

{
  int iVar1;
  
  _prm_chk_version(this);
  if (*(int *)&this->field_0x6e0 != 0) {
    *(undefined4 *)(*(int *)&this->field_0x6e0 + 0x19c) = 0;
    iVar1 = *(int *)&this->field_0x6e0;
    *(undefined4 *)(iVar1 + 0x60) = 0xffffffff;
    *(uint *)(iVar1 + 0x20c) = *(uint *)(iVar1 + 0x20c) | 1;
  }
  *(undefined4 *)&this->field_0x6e0 = 0;
  if (*(int *)&this->field_0x6ec != 0) {
    *(undefined4 *)(*(int *)&this->field_0x6ec + 0x19c) = 0;
    iVar1 = *(int *)&this->field_0x6ec;
    *(undefined4 *)(iVar1 + 0x60) = 0xffffffff;
    *(uint *)(iVar1 + 0x20c) = *(uint *)(iVar1 + 0x20c) | 1;
  }
  *(undefined4 *)&this->field_0x6ec = 0;
  return;
}


/* __thiscall daBomb_c::setBombRestTime(short) */

void __thiscall daBomb_c::setBombRestTime(daBomb_c *this,short param_1)

{
  _prm_chk_version(this);
  this->field_0x6fc = param_1;
  return;
}


/* __thiscall daBomb_c::setNoGravityTime(short) */

void __thiscall daBomb_c::setNoGravityTime(daBomb_c *this,short param_1)

{
  _prm_chk_version(this);
  this->field_0x700 = param_1;
  return;
}


namespace daBomb_c {

/* __thiscall prm_make(State_e,
                                 bool,
                                 bool) */

uint prm_make(State_e param_1,bool param_2,bool param_3)

{
  return (uint)(param_3 != false) * 0x20000 | param_1 | (uint)(param_2 != false) * 0x10000 |
         0x80000000;
}

}

/* __thiscall daBomb_c::chk_state(daBomb_c::State_e) const */

uint __thiscall daBomb_c::chk_state(daBomb_c *this,State_e param_1)

{
  uint uVar1;
  int iVar2;
  
  _prm_chk_version(this);
  iVar2 = prm_get_state(this);
  uVar1 = countLeadingZeros(iVar2 - param_1);
  return uVar1 >> 5;
}


/* __thiscall daBomb_c::change_state(daBomb_c::State_e) */

void __thiscall daBomb_c::change_state(daBomb_c *this,State_e param_1)

{
  (this->parent).parent.parent.mParameters =
       (this->parent).parent.parent.mParameters & 0xffffff00U | param_1;
  _prm_chk_version(this);
  return;
}


/* __thiscall daBomb_c::prm_get_state(void) const */

void __thiscall daBomb_c::prm_get_state(daBomb_c *this)

{
  Prm_e in_r6;
  
  _prm_chk_version(this);
  ::daObj::PrmAbstract((daObj *)this,(fopAc_ac_c *)&DAT_00000008,0,in_r6);
  return;
}


/* __thiscall daBomb_c::get_explode_instant(void) const */

uint __thiscall daBomb_c::get_explode_instant(daBomb_c *this)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(1 - *(int *)&this->field_0x784);
  return uVar1 >> 5;
}


/* __thiscall daBomb_c::prm_get_cheapEff(void) const */

bool __thiscall daBomb_c::prm_get_cheapEff(daBomb_c *this)

{
  int iVar1;
  Prm_e in_r6;
  
  _prm_chk_version(this);
  iVar1 = ::daObj::PrmAbstract((daObj *)this,(fopAc_ac_c *)&DAT_00000001,0x10,in_r6);
  return iVar1 != 0;
}


/* __thiscall daBomb_c::prm_get_angXZero(void) const */

bool __thiscall daBomb_c::prm_get_angXZero(daBomb_c *this)

{
  int iVar1;
  Prm_e in_r6;
  
  _prm_chk_version(this);
  iVar1 = ::daObj::PrmAbstract((daObj *)this,(fopAc_ac_c *)&DAT_00000001,0x11,in_r6);
  return iVar1 != 0;
}


/* __thiscall daBomb_c::prm_get_version(void) const */

void __thiscall daBomb_c::prm_get_version(daBomb_c *this)

{
  Prm_e in_r6;
  
  ::daObj::PrmAbstract((daObj *)this,(fopAc_ac_c *)&DAT_00000001,0x1f,in_r6);
  return;
}


/* __thiscall daBomb_c::_prm_chk_version(void) const */

void __thiscall daBomb_c::_prm_chk_version(daBomb_c *this)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = prm_get_version(this);
  if (iVar1 != 1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_a_bomb_static.cpp",0xce,"ver == L_daBomb_Version");
    m_Do_printf::OSPanic("d_a_bomb_static.cpp",0xce,&DAT_8034fc84);
  }
  return;
}


namespace daBomb2 {

/* __thiscall Act_c::remove_fuse_effect(void) */

void __thiscall Act_c::remove_fuse_effect(Act_c *this)

{
  FuseSmokeCB_c::deleteCallBack((FuseSmokeCB_c *)(this + 0x69c));
  FuseSparksCB_c::deleteCallBack((FuseSparksCB_c *)(this + 0x6b4));
  return;
}


/* __thiscall Act_c::set_time(int) */

void __thiscall Act_c::set_time(Act_c *this,int param_1)

{
  *(int *)(this + 0x738) = param_1;
  return;
}


/* __thiscall Act_c::get_time(void) const */

undefined4 __thiscall Act_c::get_time(Act_c *this)

{
  return *(undefined4 *)(this + 0x738);
}


/* __thiscall Act_c::chk_eat(void) const */

Act_c __thiscall Act_c::chk_eat(Act_c *this)

{
  return this[0x745];
}


/* __thiscall Act_c::set_eat(void) */

void __thiscall Act_c::set_eat(Act_c *this)

{
  this[0x745] = (Act_c)0x1;
  return;
}


/* __thiscall Act_c::set_no_hit(void) */

void __thiscall Act_c::set_no_hit(Act_c *this)

{
  *(uint *)(this + 0x580) = *(uint *)(this + 0x580) & 0xfffffffe;
  *(uint *)(this + 0x594) = *(uint *)(this + 0x594) & 0xfffffffe;
  *(uint *)(this + 0x568) = *(uint *)(this + 0x568) & 0xfffffffe;
  *(uint *)(this + 0x568) = *(uint *)(this + 0x568) & 0xfffffffe;
  return;
}


/* __thiscall Act_c::chk_explode(void) */

uint __thiscall Act_c::chk_explode(Act_c *this)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(2 - *(int *)(this + 0x694));
  return uVar1 >> 5;
}

}

/* __thiscall daObj::PrmAbstract<daBomb_c::Prm_e>(fopAc_ac_c const *,
                                                  daBomb_c::Prm_e,
                                                  daBomb_c::Prm_e) */

uint __thiscall daObj::PrmAbstract(daObj *this,fopAc_ac_c *param_1,Prm_e param_2,Prm_e param_3)

{
  return (1 << (int)param_1) - 1U & *(uint *)(this + 0xb0) >> param_2;
}

