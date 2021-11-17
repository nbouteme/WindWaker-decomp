#include <d_a_npc_mk_static.h>
#include <d_npc.h>
#include <SComponent/c_lib.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <d_a_npc_mk_static.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <SComponent/c_m3d.h>
#include <d_cc_d.h>
#include <d_save.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_math.h>
#include <SComponent/c_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <daNpc_Mk_Static_c.h>


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daNpc_Mk_Static_c::aroundWalk(fopAc_ac_c *,
                                            fopAc_ac_c *,
                                            unsigned char) */

void __thiscall
daNpc_Mk_Static_c::aroundWalk
          (daNpc_Mk_Static_c *this,fopAc_ac_c *param_1,fopAc_ac_c *param_2,uchar param_3)

{
  double dVar1;
  double dVar2;
  float fVar3;
  short local_58 [2];
  float local_54;
  cXyz local_50;
  cXyz local_44;
  cXyz local_38;
  cXyz local_2c;
  float local_20;
  float local_1c;
  float local_18;
  
  local_2c.x = (param_1->mCurrent).mPos.x;
  local_2c.y = (param_1->mCurrent).mPos.y;
  local_2c.z = (param_1->mCurrent).mPos.z;
  local_38.x = (param_2->mCurrent).mPos.x;
  local_38.y = (param_2->mCurrent).mPos.y;
  local_38.z = (param_2->mCurrent).mPos.z;
  d_npc::dNpc_calc_DisXZ_AngY(&local_2c,&local_38,(float *)0x0,local_58);
  if (param_3 == '\0') {
    ::cXyz::operator__(&local_44,&(param_1->mCurrent).mPos,&(param_2->mCurrent).mPos);
    local_20 = local_44.x;
    local_1c = local_44.y;
    local_18 = local_44.z;
    local_50.x = local_44.x;
    local_50.y = d_a_npc_mk_static::_4088;
    local_50.z = local_44.z;
    fVar3 = mtx::PSVECSquareMag(&local_50);
    dVar2 = (double)fVar3;
    if ((double)d_a_npc_mk_static::_4088 < dVar2) {
      dVar1 = 1.0 / SQRT(dVar2);
      dVar1 = d_a_npc_mk_static::_4089 * dVar1 * (d_a_npc_mk_static::_4090 - dVar2 * dVar1 * dVar1);
      dVar1 = d_a_npc_mk_static::_4089 * dVar1 * (d_a_npc_mk_static::_4090 - dVar2 * dVar1 * dVar1);
      local_54 = (float)(dVar2 * d_a_npc_mk_static::_4089 * dVar1 *
                                 (d_a_npc_mk_static::_4090 - dVar2 * dVar1 * dVar1));
      dVar2 = (double)local_54;
    }
    if (dVar2 <= (double)d_a_npc_mk_static::_4091) {
      if ((double)d_a_npc_mk_static::_4092 <= dVar2) {
        local_58[0] = local_58[0] + 0x3a00;
      }
      else {
        local_58[0] = local_58[0] + 0x4000;
      }
    }
    else {
      local_58[0] = local_58[0] + 0x3400;
    }
    SComponent::cLib_addCalcAngleS(&(param_1->mCurrent).mRot.y,local_58[0],8,0x800,0x200);
  }
  else {
    local_58[0] = local_58[0] + 0x3000;
    SComponent::cLib_addCalcAngleS(&(param_1->mCurrent).mRot.y,local_58[0],2,0x800,0x400);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daNpc_Mk_Static_c::turnPath(fopAc_ac_c *,
                                          dNpc_PathRun_c *,
                                          unsigned char) */

undefined4 __thiscall
daNpc_Mk_Static_c::turnPath
          (daNpc_Mk_Static_c *this,fopAc_ac_c *param_1,dNpc_PathRun_c *param_2,uchar param_3)

{
  short local_48 [2];
  cXyz local_44;
  cXyz local_38;
  cXyz local_2c;
  float local_20;
  float local_1c;
  float local_18;
  
  dNpc_PathRun_c::getPoint(&local_2c,param_2,param_2->mCurrPointIndex);
  local_20 = local_2c.x;
  local_1c = local_2c.y;
  local_18 = local_2c.z;
  local_38.x = (param_1->mCurrent).mPos.x;
  local_38.y = (param_1->mCurrent).mPos.y;
  local_38.z = (param_1->mCurrent).mPos.z;
  local_44.x = local_2c.x;
  local_44.y = local_2c.y;
  local_44.z = local_2c.z;
  d_npc::dNpc_calc_DisXZ_AngY(&local_38,&local_44,(float *)0x0,local_48);
  if ((param_3 & 2) == 0) {
    SComponent::cLib_addCalcAngleS(&(param_1->mCurrent).mRot.y,local_48[0],8,0x800,0x200);
  }
  else {
    SComponent::cLib_addCalcAngleS(&(param_1->mCurrent).mRot.y,local_48[0],2,0x2000,0x400);
  }
  if (JKernel::JMath::jmaCosTable
      [(int)((int)(param_1->mCurrent).mRot.y - (int)local_48[0] & 0xffffU) >>
       (JKernel::JMath::jmaSinShift & 0x3f)] < d_a_npc_mk_static::_4088) {
    *(float *)(this + 4) =
         d_a_npc_mk_static::_4125 +
         JKernel::JMath::jmaCosTable
         [(int)((int)(param_1->mCurrent).mRot.y - (int)local_48[0] & 0xffffU) >>
          (JKernel::JMath::jmaSinShift & 0x3f)];
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daNpc_Mk_Static_c::chkPath(fopAc_ac_c *,
                                         dNpc_PathRun_c *,
                                         unsigned char) */

undefined4 __thiscall
daNpc_Mk_Static_c::chkPath
          (daNpc_Mk_Static_c *this,fopAc_ac_c *param_1,dNpc_PathRun_c *param_2,uchar param_3)

{
  bool bVar2;
  undefined4 uVar1;
  int iVar3;
  cXyz local_28 [2];
  
  local_28[0].x = (param_1->mCurrent).mPos.x;
  local_28[0].y = (param_1->mCurrent).mPos.y;
  local_28[0].z = (param_1->mCurrent).mPos.z;
  iVar3 = (param_3 & 1) - 1;
  bVar2 = dNpc_PathRun_c::chkPointPass
                    (param_2,local_28,
                     (bool)((char)iVar3 - ((iVar3 == 0) + (char)(param_3 & 1) + -2)));
  if (bVar2 == false) {
    uVar1 = 0;
  }
  else {
    if ((param_3 & 1) == 0) {
      dNpc_PathRun_c::incIdxLoop(param_2);
    }
    else {
      dNpc_PathRun_c::decIdxLoop(param_2);
    }
    this[0xf] = this[0xc];
    this[0xc] = *(daNpc_Mk_Static_c *)&param_2->mCurrPointIndex;
    uVar1 = 1;
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall daNpc_Mk_Static_c::walkPath(fopAc_ac_c *,
                                          dNpc_PathRun_c *,
                                          unsigned char) */

undefined4 __thiscall
daNpc_Mk_Static_c::walkPath
          (daNpc_Mk_Static_c *this,fopAc_ac_c *param_1,dNpc_PathRun_c *param_2,uchar param_3)

{
  undefined4 uVar1;
  
  uVar1 = chkPath(this,param_1,param_2,param_3);
  turnPath(this,param_1,param_2,param_3);
  return uVar1;
}


/* __thiscall daNpc_Mk_Static_c::getSpeedF(float,
                                           float) */

double __thiscall daNpc_Mk_Static_c::getSpeedF(daNpc_Mk_Static_c *this,float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  
  fVar2 = param_1;
  if (this[0xd] != (daNpc_Mk_Static_c)0x0) {
    fVar2 = param_2;
    if ((uint)*(ushort *)(this + 8) < (uint)(*(ushort *)(this + 10) >> 1)) {
      fVar2 = param_1 + (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 8)) -
                               d_a_npc_mk_static::_4160) *
                        (d_a_npc_mk_static::_4158 /
                        (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(this + 10)) -
                               d_a_npc_mk_static::_4160)) * (param_2 - param_1);
    }
  }
  fVar1 = *(float *)(this + 4);
  *(float *)(this + 4) = d_a_npc_mk_static::_4125;
  return (double)(fVar2 * fVar1);
}


/* __thiscall daNpc_Mk_Static_c::init(unsigned char,
                                      unsigned short) */

int __thiscall daNpc_Mk_Static_c::init(daNpc_Mk_Static_c *this,EVP_PKEY_CTX *ctx)

{
  undefined2 in_r5;
  
  *this = (daNpc_Mk_Static_c)0x0;
  this[0xe] = SUB41(ctx,0);
  *(undefined2 *)(this + 8) = in_r5;
  *(undefined2 *)(this + 10) = in_r5;
  this[0xd] = (daNpc_Mk_Static_c)0x0;
  *(float *)(this + 4) = d_a_npc_mk_static::_4125;
  return (int)this;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daNpc_Mk_Static_c::goFarLink_3(fopAc_ac_c *,
                                             dNpc_PathRun_c *) */

daNpc_Mk_Static_c __thiscall
daNpc_Mk_Static_c::goFarLink_3(daNpc_Mk_Static_c *this,fopAc_ac_c *param_1,dNpc_PathRun_c *param_2)

{
  daPy_lk_c *pdVar1;
  short sVar4;
  short sVar5;
  int iVar2;
  uint uVar3;
  daNpc_Mk_Static_c dVar6;
  float local_78;
  dNpc_PathRun_c dStack116;
  cXyz local_6c;
  cXyz local_60;
  float afStack84 [2];
  float fStack76;
  cXyz local_48;
  cXyz local_3c [3];
  undefined **local_18;
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
  dNpc_PathRun_c::setInfDrct(&dStack116,param_2->mPath);
  if (this[0xf] == this[0xc]) {
    dVar6 = *this;
  }
  else {
    dNpc_PathRun_c::getPoint(&local_60,&dStack116,(uchar)this[0xf]);
    local_3c[0].x = local_60.x;
    local_3c[0].y = local_60.y;
    local_3c[0].z = local_60.z;
    dNpc_PathRun_c::getPoint(&local_6c,&dStack116,(uchar)this[0xc]);
    local_48.x = local_6c.x;
    local_48.y = local_6c.y;
    local_48.z = local_6c.z;
    sVar4 = SComponent::cLib_targetAngleY
                      (&(param_1->mCurrent).mPos,&(pdVar1->parent).parent.mCurrent.mPos);
    sVar5 = SComponent::cLib_targetAngleY(local_3c,&local_48);
    local_18 = &::cM3dGLin::__vt;
    if ((((*this == (daNpc_Mk_Static_c)0x1) || (*this == (daNpc_Mk_Static_c)0x2)) &&
        (iVar2 = MSL_C.PPCEABI.bare.H::abs((int)sVar5 - (int)sVar4), iVar2 < 0x1800)) &&
       ((uVar3 = SComponent::cM3d_Len2dSqPntAndSegLine
                           ((pdVar1->parent).parent.mCurrent.mPos.x,
                            (pdVar1->parent).parent.mCurrent.mPos.z,local_3c[0].x,local_3c[0].z,
                            local_48.x,local_48.z,afStack84,&fStack76,&local_78),
        (uVar3 & 0xff) != 0 && (local_78 < d_a_npc_mk_static::_4243)))) {
      if (*this == (daNpc_Mk_Static_c)0x1) {
        return (daNpc_Mk_Static_c)0x2;
      }
      return (daNpc_Mk_Static_c)0x1;
    }
    dVar6 = *this;
  }
  return dVar6;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall daNpc_Mk_Static_c::goFarLink_2(fopAc_ac_c *,
                                             dNpc_PathRun_c *) */

undefined4 __thiscall
daNpc_Mk_Static_c::goFarLink_2(daNpc_Mk_Static_c *this,fopAc_ac_c *param_1,dNpc_PathRun_c *param_2)

{
  daPy_lk_c *pdVar1;
  short sVar5;
  short sVar6;
  short sVar7;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  char cVar8;
  uint __x;
  int __x_00;
  int iVar9;
  float local_98;
  dNpc_PathRun_c dStack148;
  cXyz local_8c;
  cXyz local_80;
  cXyz local_74;
  float afStack104 [2];
  float fStack96;
  cXyz local_5c;
  cXyz local_50;
  cXyz local_44 [3];
  undefined **local_20;
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
  dNpc_PathRun_c::setInfDrct(&dStack148,param_2->mPath);
  dStack148.mCurrPointIndex = *(byte *)(this + 0xf);
  dNpc_PathRun_c::getPoint(&local_74,&dStack148,dStack148.mCurrPointIndex);
  local_44[0].x = local_74.x;
  local_44[0].y = local_74.y;
  local_44[0].z = local_74.z;
  dNpc_PathRun_c::incIdxLoop(&dStack148);
  dNpc_PathRun_c::getPoint(&local_80,&dStack148,dStack148.mCurrPointIndex);
  local_50.x = local_80.x;
  local_50.y = local_80.y;
  local_50.z = local_80.z;
  dNpc_PathRun_c::decIdxLoop(&dStack148);
  dNpc_PathRun_c::decIdxLoop(&dStack148);
  dNpc_PathRun_c::getPoint(&local_8c,&dStack148,dStack148.mCurrPointIndex);
  local_5c.x = local_8c.x;
  local_5c.y = local_8c.y;
  local_5c.z = local_8c.z;
  sVar5 = SComponent::cLib_targetAngleY(local_44,&(pdVar1->parent).parent.mCurrent.mPos);
  sVar6 = SComponent::cLib_targetAngleY(local_44,&local_50);
  sVar7 = SComponent::cLib_targetAngleY(local_44,&local_5c);
  local_20 = &::cM3dGLin::__vt;
  iVar9 = (int)sVar6 - (int)sVar5;
  iVar2 = MSL_C.PPCEABI.bare.H::abs(iVar9);
  if (((0x17ff < iVar2) ||
      (uVar3 = SComponent::cM3d_Len2dSqPntAndSegLine
                         ((pdVar1->parent).parent.mCurrent.mPos.x,
                          (pdVar1->parent).parent.mCurrent.mPos.z,local_44[0].x,local_44[0].z,
                          local_50.x,local_50.z,afStack104,&fStack96,&local_98), (uVar3 & 0xff) == 0
      )) || (d_a_npc_mk_static::_4243 <= local_98)) {
    __x_00 = (int)sVar7 - (int)sVar5;
    iVar2 = MSL_C.PPCEABI.bare.H::abs(__x_00);
    if (((iVar2 < 0x1800) &&
        (uVar3 = SComponent::cM3d_Len2dSqPntAndSegLine
                           ((pdVar1->parent).parent.mCurrent.mPos.x,
                            (pdVar1->parent).parent.mCurrent.mPos.z,local_44[0].x,local_44[0].z,
                            local_5c.x,local_5c.z,afStack104,&fStack96,&local_98),
        (uVar3 & 0xff) != 0)) && (local_98 < d_a_npc_mk_static::_4243)) {
      return 1;
    }
    cVar8 = dNpc_PathRun_c::setNearPathIndxMk2
                      (&dStack148,&(pdVar1->parent).parent.mCurrent.mPos,(uchar)this[0xf],'\x05');
    if (cVar8 == '\0') {
      iVar2 = MSL_C.PPCEABI.bare.H::abs(__x_00);
      iVar9 = MSL_C.PPCEABI.bare.H::abs(iVar9);
      if (iVar9 < iVar2) {
        uVar4 = 2;
      }
      else {
        uVar4 = 1;
      }
    }
    else {
      __x = (uint)dStack148.mCurrPointIndex - (uint)(byte)this[0xf];
      uVar3 = MSL_C.PPCEABI.bare.H::abs(__x);
      if ((-__x & ~__x) >> 0x1f == (uint)(uVar3 < 6) - ((int)uVar3 >> 0x1f)) {
        uVar4 = 2;
      }
      else {
        uVar4 = 1;
      }
    }
  }
  else {
    uVar4 = 2;
  }
  return uVar4;
}


/* __thiscall daNpc_Mk_Static_c::runaway_com2(dNpc_PathRun_c *,
                                              unsigned char) */

uint __thiscall
daNpc_Mk_Static_c::runaway_com2(daNpc_Mk_Static_c *this,dNpc_PathRun_c *param_1,uchar param_2)

{
  bool bVar2;
  uint uVar1;
  
  *(daNpc_Mk_Static_c *)&param_1->mCurrPointIndex = this[0xf];
  if (param_2 == '\x01') {
    bVar2 = dNpc_PathRun_c::incIdxLoop(param_1);
    uVar1 = (uint)bVar2;
  }
  else {
    uVar1 = dNpc_PathRun_c::decIdxLoop(param_1);
  }
  this[0xc] = *(daNpc_Mk_Static_c *)&param_1->mCurrPointIndex;
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800cbf70) */
/* WARNING: Removing unreachable block (ram,0x800cc354) */
/* __thiscall daNpc_Mk_Static_c::runAwayProc(fopAc_ac_c *,
                                             dNpc_PathRun_c *,
                                             dCcD_Cyl *,
                                             short *) */

uint __thiscall
daNpc_Mk_Static_c::runAwayProc
          (daNpc_Mk_Static_c *this,fopAc_ac_c *param_1,dNpc_PathRun_c *param_2,dCcD_Cyl *param_3,
          short *param_4)

{
  daNpc_Mk_Static_c dVar1;
  daPy_lk_c *pdVar2;
  daPy_lk_c *pdVar3;
  short sVar6;
  uint uVar4;
  int iVar5;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  float fVar10;
  cXyz local_8c;
  cXyz local_80;
  cXyz local_74;
  cXyz local_68;
  cXyz local_5c;
  cXyz local_50;
  cXyz local_44;
  cXyz local_38;
  undefined auStack8 [8];
  
  pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pdVar3 = (daPy_lk_c *)
           dCcD_GAtTgCoCommonBase::GetAc((dCcD_GAtTgCoCommonBase *)&(param_3->parent).mObjCo);
  if (pdVar3 == pdVar2) {
    sVar6 = SComponent::cLib_targetAngleY
                      (&(pdVar2->parent).parent.mCurrent.mPos,&(param_1->mCurrent).mPos);
    *param_4 = sVar6;
    uVar4 = 4;
    goto LAB_800cc354;
  }
  if (this[0xe] != (daNpc_Mk_Static_c)0x0) {
    this[0xe] = (daNpc_Mk_Static_c)((char)this[0xe] + -1);
  }
  dVar1 = *this;
  if (dVar1 == (daNpc_Mk_Static_c)0x3) {
    ::cXyz::operator__(&local_5c,&(pdVar2->parent).parent.mCurrent.mPos,&(param_1->mCurrent).mPos);
    local_80.x = local_5c.x;
    local_80.y = d_a_npc_mk_static::_4088;
    local_80.z = local_5c.z;
    fVar10 = mtx::PSVECSquareMag(&local_80);
    dVar9 = (double)fVar10;
    if ((double)d_a_npc_mk_static::_4088 < dVar9) {
      dVar8 = 1.0 / SQRT(dVar9);
      dVar8 = d_a_npc_mk_static::_4089 * dVar8 * (d_a_npc_mk_static::_4090 - dVar9 * dVar8 * dVar8);
      dVar8 = d_a_npc_mk_static::_4089 * dVar8 * (d_a_npc_mk_static::_4090 - dVar9 * dVar8 * dVar8);
      dVar9 = (double)(float)(dVar9 * d_a_npc_mk_static::_4089 * dVar8 *
                                      (d_a_npc_mk_static::_4090 - dVar9 * dVar8 * dVar8));
    }
    if (dVar9 < (double)d_a_npc_mk_static::_4570) {
      this[0xe] = (daNpc_Mk_Static_c)0xa;
      uVar4 = goFarLink_2(this,param_1,param_2);
      runaway_com2(this,param_2,(uchar)uVar4);
      goto LAB_800cc354;
    }
    if (*(ushort *)(this + 8) + 3 < (uint)*(ushort *)(this + 10)) {
      *(short *)(this + 8) = (short)(*(ushort *)(this + 8) + 3);
    }
  }
  else {
    if ((byte)dVar1 < 3) {
      if (dVar1 == (daNpc_Mk_Static_c)0x0) {
        dVar9 = (double)dNpc_PathRun_c::setNearPathIndxMk(param_2,&(param_1->mCurrent).mPos);
        this[0xc] = *(daNpc_Mk_Static_c *)&param_2->mCurrPointIndex;
        this[0xf] = this[0xc];
        if (dVar9 < (double)d_a_npc_mk_static::_4568) {
          uVar4 = 3;
        }
        else {
          uVar4 = 5;
        }
        goto LAB_800cc354;
      }
      ::cXyz::operator__(&local_68,&(pdVar2->parent).parent.mCurrent.mPos,&(param_1->mCurrent).mPos)
      ;
      local_8c.x = local_68.x;
      local_8c.y = d_a_npc_mk_static::_4088;
      local_8c.z = local_68.z;
      fVar10 = mtx::PSVECSquareMag(&local_8c);
      dVar9 = (double)fVar10;
      if ((double)d_a_npc_mk_static::_4088 < dVar9) {
        dVar8 = 1.0 / SQRT(dVar9);
        dVar8 = d_a_npc_mk_static::_4089 * dVar8 *
                (d_a_npc_mk_static::_4090 - dVar9 * dVar8 * dVar8);
        dVar8 = d_a_npc_mk_static::_4089 * dVar8 *
                (d_a_npc_mk_static::_4090 - dVar9 * dVar8 * dVar8);
        dVar9 = (double)(float)(dVar9 * d_a_npc_mk_static::_4089 * dVar8 *
                                        (d_a_npc_mk_static::_4090 - dVar9 * dVar8 * dVar8));
      }
      iVar5 = walkPath(this,param_1,param_2,'\x03' - (*this == (daNpc_Mk_Static_c)0x1));
      if (iVar5 != 0) {
        if (dVar9 <= (double)d_a_npc_mk_static::_4571) {
          uVar4 = goFarLink_2(this,param_1,param_2);
          if ((uVar4 & 0xff) != (uint)(byte)*this) {
            runaway_com2(this,param_2,(uchar)uVar4);
          }
        }
        else {
          uVar4 = 3;
        }
        goto LAB_800cc354;
      }
      if (this[0xe] == (daNpc_Mk_Static_c)0x0) {
        this[0xe] = (daNpc_Mk_Static_c)0xa;
        uVar4 = goFarLink_3(this,param_1,param_2);
        if ((uVar4 & 0xff) != (uint)(byte)*this) {
          this[0xf] = this[0xc];
          runaway_com2(this,param_2,(uchar)uVar4);
        }
        goto LAB_800cc354;
      }
      if (this[0xd] == (daNpc_Mk_Static_c)0x0) {
        if (dVar9 < (double)d_a_npc_mk_static::_4573) {
          this[0xd] = (daNpc_Mk_Static_c)0x1;
        }
      }
      else {
        if (*(short *)(this + 8) != 0) {
          *(short *)(this + 8) = *(short *)(this + 8) + -1;
        }
        if ((double)d_a_npc_mk_static::_4572 < dVar9) {
          this[0xd] = (daNpc_Mk_Static_c)0x0;
        }
      }
    }
    else {
      if (dVar1 == (daNpc_Mk_Static_c)0x5) {
        dNpc_PathRun_c::getPoint(&local_44,param_2,(uchar)this[0xc]);
        local_38.x = local_44.x;
        local_38.y = local_44.y;
        local_38.z = local_44.z;
        ::cXyz::operator__(&local_50,&local_38,&(param_1->mCurrent).mPos);
        local_74.x = local_50.x;
        local_74.y = d_a_npc_mk_static::_4088;
        local_74.z = local_50.z;
        fVar10 = mtx::PSVECSquareMag(&local_74);
        dVar9 = (double)fVar10;
        if ((double)d_a_npc_mk_static::_4088 < dVar9) {
          dVar8 = 1.0 / SQRT(dVar9);
          dVar8 = d_a_npc_mk_static::_4089 * dVar8 *
                  (d_a_npc_mk_static::_4090 - dVar9 * dVar8 * dVar8);
          dVar8 = d_a_npc_mk_static::_4089 * dVar8 *
                  (d_a_npc_mk_static::_4090 - dVar9 * dVar8 * dVar8);
          dVar9 = (double)(float)(dVar9 * d_a_npc_mk_static::_4089 * dVar8 *
                                          (d_a_npc_mk_static::_4090 - dVar9 * dVar8 * dVar8));
        }
        if (dVar9 < (double)d_a_npc_mk_static::_4569) {
          uVar4 = 3;
          goto LAB_800cc354;
        }
        turnPath(this,param_1,param_2,'\x02');
      }
    }
  }
  uVar4 = (uint)(byte)*this;
LAB_800cc354:
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return uVar4;
}


/* __thiscall daNpc_Mk_Static_c::chkGameSet(void) */

undefined4 __thiscall daNpc_Mk_Static_c::chkGameSet(daNpc_Mk_Static_c *this)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x20);
  if ((((iVar1 == 0) ||
       (iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x10),
       iVar1 == 0)) ||
      (iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,8),
      iVar1 == 0)) ||
     (iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,4),
     iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall daNpc_Mk_Static_c::setRndPathPos(fopAc_ac_c *,
                                               dNpc_PathRun_c *) */

void __thiscall
daNpc_Mk_Static_c::setRndPathPos
          (daNpc_Mk_Static_c *this,fopAc_ac_c *param_1,dNpc_PathRun_c *param_2)

{
  uint uVar1;
  cBgS_PolyPassChk *pcVar2;
  double dVar3;
  float fVar4;
  cXyz local_a8;
  float local_9c;
  float local_98;
  float local_94;
  cBgS_GndChk local_90;
  cBgS_PolyPassChk local_50;
  undefined local_44 [12];
  undefined4 local_38;
  uint uStack52;
  longlong local_30;
  
  ::cBgS_GndChk::cBgS_GndChk(&local_90);
  pcVar2 = &local_50;
  local_50.mbObjThrough = 0;
  local_50.mbCamThrough = 0;
  local_50.mbLinkThrough = 0;
  local_50.mbArrowsAndLightThrough = 0;
  local_50.mbBombThrough = 0;
  local_50.mbBoomerangThrough = 0;
  local_50.mbHookshotThrough = 0;
  local_44._4_4_ = 1;
  local_90.parent.vtbl = &::dBgS_GndChk::__vt;
  local_90.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  local_50.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_44._0_4_ = &PTR_80371f20;
  local_90.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar2;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_90.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_44;
  }
  local_90.parent.mpPolyPassChk = pcVar2;
  if (param_2->mPath != (dPath *)0x0) {
    uVar1 = dNpc_PathRun_c::maxPoint(param_2);
    uStack52 = uVar1 & 0xff ^ 0x80000000;
    local_38 = 0x43300000;
    fVar4 = SComponent::cM_rndF((float)((double)CONCAT44(0x43300000,uStack52) -
                                       d_a_npc_mk_static::_4656));
    local_30 = (longlong)(int)fVar4;
    dNpc_PathRun_c::getPoint(&local_a8,param_2,(uchar)(int)fVar4);
    (param_1->mCurrent).mPos.x = local_a8.x;
    (param_1->mCurrent).mPos.y = local_a8.y;
    (param_1->mCurrent).mPos.z = local_a8.z;
    local_90.mFlagIn = local_90.mFlagIn & 0xfffffffd;
    local_94 = (param_1->mCurrent).mPos.z;
    local_98 = d_a_npc_mk_static::_4573 + (param_1->mCurrent).mPos.y;
    local_9c = (param_1->mCurrent).mPos.x;
    local_90.mPos.x = local_9c;
    local_90.mPos.y = local_98;
    local_90.mPos.z = local_94;
    dVar3 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_90);
    (param_1->mCurrent).mPos.y = (float)dVar3;
    (param_1->mNext).mPos.x = (param_1->mCurrent).mPos.x;
    (param_1->mNext).mPos.y = (param_1->mCurrent).mPos.y;
    (param_1->mNext).mPos.z = (param_1->mCurrent).mPos.z;
  }
  local_50.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_44._0_4_ = &PTR_80371f20;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_50.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_44._0_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != &DAT_00000044) &&
       (local_44._0_4_ = &::dBgS_GrpPassChk::__vt, (undefined *)register0x00000004 != &DAT_00000044)
       ) {
      local_44._0_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar2 != (cBgS_PolyPassChk *)0x0) &&
       (local_50.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar2 != (cBgS_PolyPassChk *)0x0)) {
      local_50.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_90.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_90.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_90.parent);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daNpc_Mk_Static_c::chkPointPass(cXyz *,
                                              cXyz *,
                                              cXyz *) */

undefined4 __thiscall
daNpc_Mk_Static_c::chkPointPass(daNpc_Mk_Static_c *this,cXyz *param_1,cXyz *param_2,cXyz *param_3)

{
  undefined4 uVar1;
  short sVar2;
  short sVar3;
  
  if ((param_1->x == param_2->x) && (param_1->z == param_2->z)) {
    uVar1 = 1;
  }
  else {
    if ((param_3->x == param_2->x) && (param_3->z == param_2->z)) {
      uVar1 = 1;
    }
    else {
      sVar2 = SComponent::cLib_targetAngleY(param_1,param_2);
      sVar3 = SComponent::cLib_targetAngleY(param_3,param_2);
      if (d_a_npc_mk_static::_4088 <=
          JKernel::JMath::jmaCosTable
          [(int)((int)sVar2 - (int)sVar3 & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f)]) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}

