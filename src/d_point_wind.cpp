#include <d_point_wind.h>
#include <d_kankyo_wether.h>
#include <d_kankyo_rain.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <SComponent/c_xyz.h>
#include <SComponent/c_lib.h>
#include <mtx/vec.h>
#include <dPointWind_c.h>


/* __thiscall dPointWind_c::set_pwind_init(cM3dGCpsS *) */

void __thiscall dPointWind_c::set_pwind_init(dPointWind_c *this,cM3dGCpsS *param_1)

{
  cM3dGCpsS *pcVar1;
  
  this->mpCps = param_1;
  pcVar1 = this->mpCps;
  (this->mInfluence).mPos.x = (pcVar1->mP0).x;
  (this->mInfluence).mPos.y = (pcVar1->mP0).y;
  (this->mInfluence).mPos.z = (pcVar1->mP0).z;
  pcVar1 = this->mpCps;
  (this->mInfluence).mDir.x = (pcVar1->mP1).x;
  (this->mInfluence).mDir.y = (pcVar1->mP1).y;
  (this->mInfluence).mDir.z = (pcVar1->mP1).z;
  (this->mInfluence).mRadius = this->mpCps->mRadius;
  (this->mInfluence).field_0x20 = d_point_wind::0_0;
  (this->mInfluence).mStrength = d_point_wind::1_0;
  d_kankyo_wether::dKyw_pwind_cylinder_set(&this->mInfluence);
  return;
}


/* WARNING: Removing unreachable block (ram,0x800cf5a8) */
/* __thiscall dPointWind_c::set_pwind_move(void) */

void __thiscall dPointWind_c::set_pwind_move(dPointWind_c *this)

{
  bool bVar1;
  cM3dGCpsS *pcVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  float fVar7;
  cXyz local_54;
  cXyz cStack72;
  cXyz local_3c;
  cXyz local_30;
  cXyz local_24;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar6 = (double)d_point_wind::1_8;
  bVar1 = true;
  pcVar2 = this->mpCps;
  local_24.x = (pcVar2->mP0).x;
  local_24.y = (pcVar2->mP0).y;
  local_24.z = (pcVar2->mP0).z;
  local_30.x = (pcVar2->mP1).x;
  local_30.y = (pcVar2->mP1).y;
  local_30.z = (pcVar2->mP1).z;
  d_kankyo_rain::dKyr_get_vectle_calc(&local_24,&local_30,&local_3c);
  iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea");
  if ((iVar3 == 0) && (dStage_roomControl_c::mStayNo == 4)) {
    dVar6 = (double)d_point_wind::11_0;
    bVar1 = false;
    ::cXyz::operator_(&cStack72,&local_3c,d_point_wind::_4025);
    ::cXyz::operator__(&local_54,&local_24,&cStack72);
    (this->mInfluence).mPos.x = local_54.x;
    (this->mInfluence).mPos.y = local_54.y;
    (this->mInfluence).mPos.z = local_54.z;
  }
  (this->mInfluence).mDir.x = local_3c.x;
  (this->mInfluence).mDir.y = local_3c.y;
  (this->mInfluence).mDir.z = local_3c.z;
  (this->mInfluence).mRadius = (float)((double)this->mpCps->mRadius * dVar6);
  (this->mInfluence).field_0x20 = d_point_wind::0_0;
  if (bVar1) {
    fVar7 = (this->mInfluence).mRadius;
    SComponent::cLib_addCalc
              ((float *)&this->mInfluence,(this->mpCps->mP1).x,d_point_wind::0_1,fVar7,
               d_point_wind::0_5 * fVar7);
    fVar7 = (this->mInfluence).mRadius;
    SComponent::cLib_addCalc
              (&(this->mInfluence).mPos.y,(this->mpCps->mP1).y,d_point_wind::0_1,fVar7,
               d_point_wind::0_5 * fVar7);
    fVar7 = (this->mInfluence).mRadius;
    SComponent::cLib_addCalc
              (&(this->mInfluence).mPos.z,(this->mpCps->mP1).z,d_point_wind::0_1,fVar7,
               d_point_wind::0_5 * fVar7);
    fVar7 = mtx::PSVECSquareDistance(&(this->mInfluence).mPos,&local_30);
    dVar6 = (double)fVar7;
    if ((double)d_point_wind::0_0 < dVar6) {
      dVar5 = 1.0 / SQRT(dVar6);
      dVar5 = d_point_wind::_4028 * dVar5 * (d_point_wind::_4029 - dVar6 * dVar5 * dVar5);
      dVar5 = d_point_wind::_4028 * dVar5 * (d_point_wind::_4029 - dVar6 * dVar5 * dVar5);
      dVar6 = (double)(float)(dVar6 * d_point_wind::_4028 * dVar5 *
                                      (d_point_wind::_4029 - dVar6 * dVar5 * dVar5));
    }
    if (dVar6 < (double)(this->mInfluence).mRadius) {
      (this->mInfluence).mPos.x = (this->mpCps->mP0).x;
      (this->mInfluence).mPos.y = (this->mpCps->mP0).y;
      (this->mInfluence).mPos.z = (this->mpCps->mP0).z;
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* __thiscall dPointWind_c::set_pwind_delete(void) */

void __thiscall dPointWind_c::set_pwind_delete(dPointWind_c *this)

{
  d_kankyo_wether::dKyw_pntwind_cut(&this->mInfluence);
  return;
}

