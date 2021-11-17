#include <d_detect.h>
#include <JKernel/JKRHeap.h>
#include <d_detect.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <mtx/vec.h>
#include <f_op_actor.h>
#include <mtx/mtxvec.h>
#include <f_op_actor_iter.h>
#include <d_attention.h>
#include <daObj.h>
#include <dDetect_c.h>
#include <dDetectPlace_c.h>


/* __thiscall dDetectPlace_c::dDetectPlace_c(void) */

void __thiscall dDetectPlace_c::dDetectPlace_c(dDetectPlace_c *this)

{
  (this->mPos).x = ::cXyz::Zero.x;
  (this->mPos).y = ::cXyz::Zero.y;
  (this->mPos).z = ::cXyz::Zero.z;
  this->mEnable = 0;
  return;
}


/* __thiscall dDetectPlace_c::~dDetectPlace_c(void) */

void __thiscall dDetectPlace_c::_dDetectPlace_c(dDetectPlace_c *this)

{
  short in_r4;
  
  if ((this != (dDetectPlace_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dDetectPlace_c::chk_enable(void) const */

bool __thiscall dDetectPlace_c::chk_enable(dDetectPlace_c *this)

{
  return this->mEnable != 0;
}


/* __thiscall dDetect_c::dDetect_c(void) */

void __thiscall dDetect_c::dDetect_c(dDetect_c *this)

{
  Runtime.PPCEABI.H::__construct_array
            (this,dDetectPlace_c::dDetectPlace_c,dDetectPlace_c::_dDetectPlace_c,0x10,1);
  this->mTimer = 0;
  return;
}


/* __thiscall dDetect_c::~dDetect_c(void) */

void __thiscall dDetect_c::_dDetect_c(dDetect_c *this)

{
  short in_r4;
  
  if ((this != (dDetect_c *)0x0) &&
     (Runtime.PPCEABI.H::__destroy_arr(this,dDetectPlace_c::_dDetectPlace_c,0x10,1), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dDetect_c::proc(void) */

void __thiscall dDetect_c::proc(dDetect_c *this)

{
  short sVar1;
  
  sVar1 = this->mPlace[0].mEnable;
  if (sVar1 < 1) {
    if (sVar1 < 0) {
      this->mPlace[0].mEnable = 1;
    }
  }
  else {
    this->mPlace[0].mEnable = sVar1 + -1;
  }
  sVar1 = this->mTimer;
  if (0 < sVar1) {
    this->mTimer = sVar1 + -1;
    return;
  }
  if (-1 < sVar1) {
    return;
  }
  this->mTimer = 1;
  return;
}


/* __thiscall dDetect_c::chk_quake(cXyz const *) const */

undefined4 __thiscall dDetect_c::chk_quake(dDetect_c *this,cXyz *param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (this->mTimer < 1) {
    if ((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x2a4 & 0x2000)
        != 0) {
      if (param_1 == (cXyz *)0x0) {
        uVar2 = 1;
      }
      else {
        cVar1 = chk_quake_area(this,param_1);
        if (cVar1 != '\0') {
          uVar2 = 1;
        }
      }
    }
    if (0 < this->mPlace[0].mEnable) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


/* __thiscall dDetect_c::set_quake(cXyz const *) */

void __thiscall dDetect_c::set_quake(dDetect_c *this,cXyz *pPos)

{
  char cVar1;
  
  if (pPos == (cXyz *)0x0) {
    this->mTimer = -1;
  }
  else {
    cVar1 = dDetectPlace_c::chk_enable(this->mPlace);
    if (cVar1 == '\0') {
      this->mPlace[0].mEnable = -1;
      this->mPlace[0].mPos.x = pPos->x;
      this->mPlace[0].mPos.y = pPos->y;
      this->mPlace[0].mPos.z = pPos->z;
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8009c30c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dDetect_c::chk_quake_area(cXyz const *) const */

undefined4 __thiscall dDetect_c::chk_quake_area(dDetect_c *this,cXyz *pPos)

{
  float fVar1;
  daPy_lk_c *pdVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  float fVar6;
  cXyz local_38;
  cXyz local_2c;
  undefined auStack8 [8];
  
  pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar5 = (double)(_M_attr * _M_attr);
  local_38.z = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent
               .mPos.z;
  local_38.x = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent
               .mPos.x;
  local_38.y = d_detect::_4153;
  local_2c.z = pPos->z;
  local_2c.x = pPos->x;
  local_2c.y = d_detect::_4153;
  fVar6 = mtx::PSVECSquareDistance(&local_38,&local_2c);
  fVar1 = pPos->y - (pdVar2->parent).parent.mCurrent.mPos.y;
  uVar3 = 0;
  if ((((double)fVar6 <= dVar5) && (fVar1 <= DAT_80352fd4)) && (DAT_80352fd8 <= fVar1)) {
    uVar3 = 1;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar3;
}


namespace dDetect_c {

/* WARNING: Removing unreachable block (ram,0x8009c560) */
/* WARNING: Removing unreachable block (ram,0x8009c568) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall search_tag_light(void *,
                                          void *) */

dDetect_c * search_tag_light(fopAc_ac_c *pActor,void *param_2)

{
  f_pc_profile__Profile_Actor *pfVar1;
  bool bVar3;
  uint uVar2;
  Prm_e in_r6;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  float fVar7;
  cXyz local_54;
  cXyz local_48 [2];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  bVar3 = f_op_actor::fopAc_IsActor(pActor);
  if ((bVar3 != false) && ((pActor->parent).parent.mProcName == 0x1db)) {
    if (*(char *)&pActor[1].parent.parent.mPi.parent.mpTagData == '\0') {
LAB_8009c548:
      bVar3 = false;
    }
    else {
      mtx::PSMTXMultVec((MTX34 *)&pActor[1].parent.parent.mLnTg.parent.mbAdded,(cXyz *)param_2,
                        local_48);
      pfVar1 = pActor[1].parent.parent.mpProf;
      if (pfVar1 == (f_pc_profile__Profile_Actor *)0x0) {
        bVar3 = false;
        if ((((_M_box_x_min <= local_48[0].x) && (local_48[0].x <= _M_box_x_max)) &&
            ((_M_box_y_min <= local_48[0].y &&
             ((local_48[0].y <= _M_box_y_max && (_M_box_z_min <= local_48[0].z)))))) &&
           (local_48[0].z <= _M_box_z_max)) {
          bVar3 = true;
        }
      }
      else {
        if (((pfVar1 != (f_pc_profile__Profile_Actor *)&DAT_00000001) ||
            (local_48[0].y < _M_cone_lower)) || (_M_cone_upper < local_48[0].y)) goto LAB_8009c548;
        local_54.x = local_48[0].x;
        local_54.y = d_detect::_4153;
        local_54.z = local_48[0].z;
        fVar7 = mtx::PSVECSquareMag(&local_54);
        dVar6 = (double)fVar7;
        if ((double)d_detect::_4153 < dVar6) {
          dVar5 = 1.0 / SQRT(dVar6);
          dVar5 = d_detect::_4221 * dVar5 * (d_detect::_4222 - dVar6 * dVar5 * dVar5);
          dVar5 = d_detect::_4221 * dVar5 * (d_detect::_4222 - dVar6 * dVar5 * dVar5);
          dVar6 = (double)(float)(dVar6 * d_detect::_4221 * dVar5 *
                                          (d_detect::_4222 - dVar6 * dVar5 * dVar5));
        }
        dVar5 = (double)((local_48[0].y - _M_cone_lower) *
                        (d_detect::_4223 / (_M_cone_upper - _M_cone_lower)));
        uVar2 = ::daObj::PrmAbstract((daObj *)pActor,(fopAc_ac_c *)&DAT_00000004,10,in_r6);
        bVar3 = dVar6 <= (double)(_M_cone_r *
                                 ((float)((double)d_detect::_4223 - dVar5) +
                                 (float)(dVar5 * (double)(d_detect::_4224 *
                                                         (float)((double)CONCAT44(0x43300000,
                                                                                  uVar2 ^ 0x80000000
                                                                                 ) - d_detect::_4226
                                                                )))));
      }
    }
    if (bVar3) goto LAB_8009c560;
  }
  pActor = (fopAc_ac_c *)0x0;
LAB_8009c560:
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return (dDetect_c *)pActor;
}

}

/* __thiscall dDetect_c::chk_light(cXyz const *) const */

bool __thiscall dDetect_c::chk_light(dDetect_c *this,cXyz *pPos)

{
  fopAc_ac_c *pfVar1;
  
  pfVar1 = f_op_actor_iter::fopAcIt_Judge(search_tag_light,pPos);
  return pfVar1 != (fopAc_ac_c *)0x0;
}


/* __thiscall dDetect_c::chk_attention(cXyz *) const */

bool __thiscall dDetect_c::chk_attention(dDetect_c *this,cXyz *pDst)

{
  fopAc_ac_c *pActor;
  
  pActor = dAttLook_c::convPId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.field_0x158,
                               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.field_0x158.
                               field_0xc);
  if (pActor != (fopAc_ac_c *)0x0) {
    pDst->x = (pActor->mEyePos).x;
    pDst->y = (pActor->mEyePos).y;
    pDst->z = (pActor->mEyePos).z;
  }
  return pActor != (fopAc_ac_c *)0x0;
}


/* __thiscall daObj::PrmAbstract<daTagLight::Act_c::Prm_e>(fopAc_ac_c const *,
                                                           daTagLight::Act_c::Prm_e,
                                                           daTagLight::Act_c::Prm_e) */

uint __thiscall daObj::PrmAbstract(daObj *this,fopAc_ac_c *param_1,Prm_e param_2,Prm_e param_3)

{
  return (1 << (int)param_1) - 1U & *(uint *)(this + 0xb0) >> param_2;
}

