#include <d_salvage.h>
#include <d_salvage.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_save.h>
#include <d_kankyo.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <dSalvage_control_c.h>


/* __thiscall dSalvage_control_c::init(void) */

int __thiscall dSalvage_control_c::init(dSalvage_control_c *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0xa0;
  do {
    (this + iVar1)[0x30] = (dSalvage_control_c)0xff;
    *(undefined4 *)(this + iVar1 + 0x28) = 0;
    iVar1 = iVar1 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *this = (dSalvage_control_c)0x0;
  this[1] = (dSalvage_control_c)0x0;
  return (int)this;
}


/* __thiscall dSalvage_control_c::init_end(void) */

void __thiscall dSalvage_control_c::init_end(dSalvage_control_c *this)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    init_one_sub(this,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xa0);
  *this = (dSalvage_control_c)0x0;
  this[1] = (dSalvage_control_c)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* __thiscall dSalvage_control_c::entry(fopAc_ac_c *,
                                        JPABaseEmitter *) */

void __thiscall
dSalvage_control_c::entry(dSalvage_control_c *this,fopAc_ac_c *param_1,JPABaseEmitter *param_2)

{
  dSalvage_control_c dVar1;
  uint uVar2;
  dSalvage_control_c dVar3;
  uint switchIndex;
  uint uVar4;
  ulong uVar5;
  bool bVar7;
  int iVar6;
  uint uVar8;
  int iVar9;
  dSalvage_control_c *pdVar10;
  uint uVar11;
  
  if (param_1 == (fopAc_ac_c *)0x0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_salvage.cpp",0x8b,"pact != 0");
    m_Do_printf::OSPanic("d_salvage.cpp",0x8b,"Halt");
  }
  dVar1 = *(dSalvage_control_c *)&(param_1->mCurrent).mRoomNo;
  uVar4 = (param_1->parent).parent.mParameters;
  uVar2 = uVar4 >> 0x1c;
  uVar11 = uVar4 >> 0x14 & 0xff;
  dVar3 = SUB41(uVar4 >> 0xc,0);
  switchIndex = (int)(param_1->mOrig).mRot.z & 0xff;
  bVar7 = false;
  if (dVar1 == (dSalvage_control_c)0x0) {
    uVar8 = (uint)(byte)*this;
    if (0x80 < (byte)*this) {
      bVar7 = true;
    }
  }
  else {
    uVar8 = (byte)this[1] + 0x80;
    dVar3 = dVar1;
    if (0x20 < (byte)this[1]) {
      bVar7 = true;
    }
  }
  if (((char)dVar3 < '\x01') || ('@' < (char)dVar3)) {
    bVar7 = true;
  }
  if ((uVar2 == 2) || (uVar2 == 3)) {
    if (0xf < uVar11) {
      bVar7 = true;
    }
  }
  else {
    if ((uVar2 == 0) && ((uVar11 == 0 || (0x80 < uVar11)))) {
      bVar7 = true;
    }
  }
  if ((uVar2 == 2) && (switchIndex == 0xff)) {
    bVar7 = true;
  }
  if (bVar7) {
    return;
  }
  iVar9 = uVar8 * 0x38;
  pdVar10 = this + iVar9;
  pdVar10[0x35] = (dSalvage_control_c)0x0;
  pdVar10[0x35] = (dSalvage_control_c)((byte)pdVar10[0x35] & 0xfe);
  switch(uVar2) {
  case 0:
    iVar6 = dSv_player_map_c::isCompleteMap
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,uVar11 - 1);
    if (iVar6 != 0) {
      return;
    }
    if (((param_1->mOrig).mRot.z & 3U) !=
        (ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo._89_1_) {
      return;
    }
    pdVar10[0x35] = (dSalvage_control_c)((byte)pdVar10[0x35] | 1);
    break;
  case 2:
    bVar7 = dSv_info_c::isSwitch
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,switchIndex,
                       (int)(char)(param_1->mOrig).mRoomNo);
    if (bVar7 == false) {
      pdVar10[0x35] = (dSalvage_control_c)((byte)pdVar10[0x35] | 1);
    }
  case 3:
    if ((uVar11 != 0x1f) &&
       (iVar6 = dSv_ocean_c::isOceanSvBit
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mOcean,(uchar)dVar3,
                           (ushort)uVar11), iVar6 != 0)) {
      return;
    }
    break;
  case 4:
    if ((uVar11 != 0x1f) &&
       (iVar6 = dSv_ocean_c::isOceanSvBit
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mOcean,(uchar)dVar3,
                           (ushort)uVar11), iVar6 != 0)) {
      return;
    }
    bVar7 = d_kankyo::dKy_daynight_check();
    if (bVar7 == false) {
      pdVar10[0x35] = (dSalvage_control_c)((byte)pdVar10[0x35] | 1);
    }
    break;
  case 6:
    iVar6 = d_kankyo::dKy_moon_type_chk();
    if ((iVar6 != 0) ||
       (iVar6 = dSv_event_c::isEventBit
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,
                           *(ushort *)(&daSalvage_c::m_savelabel + uVar11 * 2)), iVar6 != 0)) {
      pdVar10[0x35] = (dSalvage_control_c)((byte)pdVar10[0x35] | 1);
    }
  }
  pdVar10 = this + iVar9;
  pdVar10[0x30] = dVar1;
  *(float *)(pdVar10 + 4) = (param_1->mCurrent).mPos.x;
  *(float *)(pdVar10 + 8) = (param_1->mCurrent).mPos.y;
  *(float *)(pdVar10 + 0xc) = (param_1->mCurrent).mPos.z;
  *(float *)(pdVar10 + 0x10) = (param_1->mScale).x;
  *(float *)(pdVar10 + 0x14) = (param_1->mScale).y;
  *(float *)(pdVar10 + 0x18) = (param_1->mScale).z;
  pdVar10[0x31] = SUB41(uVar11,0);
  pdVar10[0x32] = (dSalvage_control_c)((byte)uVar4 & 0xf);
  pdVar10[0x33] = SUB41(uVar4 >> 0x1c,0);
  pdVar10[0x34] = SUB41(uVar4 >> 4,0);
  *(uint *)(pdVar10 + 0x24) = switchIndex;
  *(JPABaseEmitter **)(pdVar10 + 0x28) = param_2;
  if (uVar2 == 5) {
    *(float *)(pdVar10 + 0x20) = d_salvage::_4167 * (param_1->mScale).y;
    *(float *)(pdVar10 + 0x1c) = d_salvage::_4169 * (param_1->mScale).x;
  }
  else {
    if ((uVar2 < 5) && (uVar2 == 0)) {
      *(float *)(pdVar10 + 0x20) = d_salvage::_4167 * (param_1->mScale).y;
      *(float *)(pdVar10 + 0x1c) = d_salvage::_4168 * (param_1->mScale).x;
    }
    else {
      *(float *)(this + iVar9 + 0x20) = d_salvage::_4169 * (param_1->mScale).y;
      *(float *)(this + iVar9 + 0x1c) = d_salvage::_4170 * (param_1->mScale).x;
    }
  }
  if (dVar1 == (dSalvage_control_c)0x0) {
    *this = (dSalvage_control_c)((char)*this + '\x01');
  }
  else {
    this[1] = (dSalvage_control_c)((char)this[1] + '\x01');
  }
  return;
}


/* __thiscall dSalvage_control_c::init_room(signed char) */

void __thiscall dSalvage_control_c::init_room(dSalvage_control_c *this,char param_1)

{
  int iVar1;
  
  iVar1 = 0x80;
  do {
    init_one_sub(this,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xa0);
  this[1] = (dSalvage_control_c)0x0;
  return;
}


/* __thiscall dSalvage_control_c::init_one(int) */

void __thiscall dSalvage_control_c::init_one(dSalvage_control_c *this,int param_1)

{
  init_one_sub(this,param_1);
  if (param_1 < 0x80) {
    *this = (dSalvage_control_c)((char)*this + -1);
  }
  else {
    this[1] = (dSalvage_control_c)((char)this[1] + -1);
  }
  return;
}


/* __thiscall dSalvage_control_c::init_one_sub(int) */

void __thiscall dSalvage_control_c::init_one_sub(dSalvage_control_c *this,int param_1)

{
  dSalvage_control_c *pdVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + param_1 * 0x38 + 0x28);
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x60) = 0xffffffff;
    *(uint *)(iVar2 + 0x20c) = *(uint *)(iVar2 + 0x20c) | 1;
  }
  pdVar1 = this + param_1 * 0x38;
  pdVar1[0x30] = (dSalvage_control_c)0xff;
  *(float *)(pdVar1 + 4) = ::cXyz::Zero.x;
  *(float *)(pdVar1 + 8) = ::cXyz::Zero.y;
  *(float *)(pdVar1 + 0xc) = ::cXyz::Zero.z;
  *(float *)(pdVar1 + 0x10) = ::cXyz::Zero.x;
  *(float *)(pdVar1 + 0x14) = ::cXyz::Zero.y;
  *(float *)(pdVar1 + 0x18) = ::cXyz::Zero.z;
  pdVar1[0x31] = (dSalvage_control_c)0x0;
  pdVar1[0x32] = (dSalvage_control_c)0x0;
  pdVar1[0x34] = (dSalvage_control_c)0x0;
  *(undefined4 *)(pdVar1 + 0x24) = 0;
  *(undefined4 *)(this + param_1 * 0x38 + 0x28) = 0;
  pdVar1[0x35] = (dSalvage_control_c)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dSalvage_control_c::calcDistanceXZ(void) */

void __thiscall dSalvage_control_c::calcDistanceXZ(dSalvage_control_c *this)

{
  daPy_lk_c *pdVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  float fVar7;
  cXyz local_34;
  cXyz local_28;
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  iVar3 = 0;
  iVar4 = 0;
  do {
    iVar2 = checkRegist(this,iVar3);
    if (iVar2 != 0) {
      ::cXyz::operator__(&local_28,&(pdVar1->parent).parent.mCurrent.mPos,(cXyz *)(this + iVar4 + 4)
                        );
      local_34.x = local_28.x;
      local_34.y = d_salvage::_4243;
      local_34.z = local_28.z;
      fVar7 = mtx::PSVECSquareMag(&local_34);
      dVar6 = (double)fVar7;
      if ((double)d_salvage::_4243 < dVar6) {
        dVar5 = 1.0 / SQRT(dVar6);
        dVar5 = d_salvage::_4244 * dVar5 * (d_salvage::_4245 - dVar6 * dVar5 * dVar5);
        dVar5 = d_salvage::_4244 * dVar5 * (d_salvage::_4245 - dVar6 * dVar5 * dVar5);
        dVar6 = (double)(float)(dVar6 * d_salvage::_4244 * dVar5 *
                                        (d_salvage::_4245 - dVar6 * dVar5 * dVar5));
      }
      *(float *)(this + iVar4 + 0x2c) = (float)dVar6;
    }
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar3 < 0xa0);
  return;
}


/* __thiscall dSalvage_control_c::getPos(int) */

void __thiscall dSalvage_control_c::getPos(dSalvage_control_c *this,int param_1)

{
  int iVar1;
  int in_r5;
  
  iVar1 = param_1 + in_r5 * 0x38;
  *(undefined4 *)this = *(undefined4 *)(iVar1 + 4);
  *(undefined4 *)(this + 4) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(this + 8) = *(undefined4 *)(iVar1 + 0xc);
  return;
}


/* __thiscall dSalvage_control_c::getPosP(int) */

dSalvage_control_c * __thiscall dSalvage_control_c::getPosP(dSalvage_control_c *this,int param_1)

{
  return this + param_1 * 0x38 + 4;
}


/* __thiscall dSalvage_control_c::getScale(int) */

void __thiscall dSalvage_control_c::getScale(dSalvage_control_c *this,int param_1)

{
  int iVar1;
  int in_r5;
  
  iVar1 = param_1 + in_r5 * 0x38;
  *(undefined4 *)this = *(undefined4 *)(iVar1 + 0x10);
  *(undefined4 *)(this + 4) = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 *)(this + 8) = *(undefined4 *)(iVar1 + 0x18);
  return;
}


/* __thiscall dSalvage_control_c::getR(int) */

double __thiscall dSalvage_control_c::getR(dSalvage_control_c *this,int param_1)

{
  return (double)*(float *)(this + param_1 * 0x38 + 0x1c);
}


/* __thiscall dSalvage_control_c::getH(int) */

double __thiscall dSalvage_control_c::getH(dSalvage_control_c *this,int param_1)

{
  return (double)*(float *)(this + param_1 * 0x38 + 0x20);
}


/* __thiscall dSalvage_control_c::getRoomNo(int) */

dSalvage_control_c __thiscall dSalvage_control_c::getRoomNo(dSalvage_control_c *this,int param_1)

{
  return this[param_1 * 0x38 + 0x30];
}


/* __thiscall dSalvage_control_c::getItemNo(int) */

dSalvage_control_c __thiscall dSalvage_control_c::getItemNo(dSalvage_control_c *this,int param_1)

{
  return this[param_1 * 0x38 + 0x34];
}


/* __thiscall dSalvage_control_c::getSwitchNo(int) */

undefined4 __thiscall dSalvage_control_c::getSwitchNo(dSalvage_control_c *this,int param_1)

{
  return *(undefined4 *)(this + param_1 * 0x38 + 0x24);
}


/* __thiscall dSalvage_control_c::getSaveNo(int) */

dSalvage_control_c __thiscall dSalvage_control_c::getSaveNo(dSalvage_control_c *this,int param_1)

{
  return this[param_1 * 0x38 + 0x31];
}


/* __thiscall dSalvage_control_c::getType(int) */

dSalvage_control_c __thiscall dSalvage_control_c::getType(dSalvage_control_c *this,int param_1)

{
  return this[param_1 * 0x38 + 0x32];
}


/* __thiscall dSalvage_control_c::getKind(int) */

dSalvage_control_c __thiscall dSalvage_control_c::getKind(dSalvage_control_c *this,int param_1)

{
  return this[param_1 * 0x38 + 0x33];
}


/* __thiscall dSalvage_control_c::getDistance(int) */

double __thiscall dSalvage_control_c::getDistance(dSalvage_control_c *this,int param_1)

{
  return (double)*(float *)(this + param_1 * 0x38 + 0x2c);
}


/* __thiscall dSalvage_control_c::getAlphaPtr(int) */

dSalvage_control_c * __thiscall
dSalvage_control_c::getAlphaPtr(dSalvage_control_c *this,int param_1)

{
  return this + param_1 * 0x38 + 0x37;
}


/* __thiscall dSalvage_control_c::getDrawMode(int) */

dSalvage_control_c __thiscall dSalvage_control_c::getDrawMode(dSalvage_control_c *this,int param_1)

{
  return this[param_1 * 0x38 + 0x37];
}


/* __thiscall dSalvage_control_c::checkRegist(int) */

int __thiscall dSalvage_control_c::checkRegist(dSalvage_control_c *this,int param_1)

{
  int iVar1;
  
  iVar1 = -(int)(char)this[param_1 * 0x38 + 0x30] + -1;
  return iVar1 - ((uint)(iVar1 == 0) + -(int)(char)this[param_1 * 0x38 + 0x30] + -2);
}


/* __thiscall dSalvage_control_c::checkUsed(int) */

uint __thiscall dSalvage_control_c::checkUsed(dSalvage_control_c *this,int param_1)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros((byte)this[param_1 * 0x38 + 0x35] & 1);
  return uVar1 >> 5;
}


/* __thiscall dSalvage_control_c::setPos(int,
                                         cXyz) */

void __thiscall dSalvage_control_c::setPos(dSalvage_control_c *this,int param_1,cXyz *param_2)

{
  dSalvage_control_c *pdVar1;
  
  pdVar1 = this + param_1 * 0x38;
  *(float *)(pdVar1 + 4) = param_2->x;
  *(float *)(pdVar1 + 8) = param_2->y;
  *(float *)(pdVar1 + 0xc) = param_2->z;
  return;
}


/* __thiscall dSalvage_control_c::setFlag(int,
                                          unsigned char) */

void __thiscall dSalvage_control_c::setFlag(dSalvage_control_c *this,int param_1,uchar param_2)

{
  (this + param_1 * 0x38)[0x35] =
       (dSalvage_control_c)((byte)(this + param_1 * 0x38)[0x35] | param_2);
  return;
}


/* __thiscall dSalvage_control_c::clrFlag(int,
                                          unsigned char) */

void __thiscall dSalvage_control_c::clrFlag(dSalvage_control_c *this,int param_1,uchar param_2)

{
  (this + param_1 * 0x38)[0x35] =
       (dSalvage_control_c)((byte)(this + param_1 * 0x38)[0x35] & ~param_2);
  return;
}


/* __thiscall dSalvage_control_c::setNowAlpha(int,
                                              unsigned char) */

void __thiscall dSalvage_control_c::setNowAlpha(dSalvage_control_c *this,int param_1,uchar param_2)

{
  this[param_1 * 0x38 + 0x37] = (dSalvage_control_c)param_2;
  return;
}


/* __thiscall dSalvage_control_c::setDrawMode(int,
                                              int) */

void __thiscall dSalvage_control_c::setDrawMode(dSalvage_control_c *this,int param_1,int param_2)

{
  this[param_1 * 0x38 + 0x38] = SUB41(param_2,0);
  return;
}

