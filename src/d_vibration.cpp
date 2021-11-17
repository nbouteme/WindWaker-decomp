#include <d_vibration.h>
#include <SComponent/c_math.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_save.h>
#include <d_vibration.h>
#include <SComponent/c_xyz.h>
#include <d_camera.h>
#include <JUtility/JUTGamePad.h>
#include <JKernel/JKRHeap.h>
#include <dVibration_c.h>
#include <@unnamed@d_vibration_cpp@.h>


namespace d_vibration {
undefined data$4141;
}

/* __thiscall @unnamed@d_vibration_cpp@::makedata(unsigned short *,
                                                  unsigned long,
                                                  long) */

void __thiscall
@unnamed@d_vibration_cpp@::makedata
          (_unnamed_d_vibration_cpp_ *this,ushort *param_1,ulong param_2,long param_3)

{
  *(short *)this = (short)param_2;
  *(short *)(this + 2) = (short)((uint)param_1 >> 0x10);
  *(short *)(this + 4) = (short)param_1;
  *(undefined2 *)(this + 6) = 0;
  return;
}


/* __thiscall @unnamed@d_vibration_cpp@::rollshift(unsigned long,
                                                   long,
                                                   long) */

uint __thiscall
@unnamed@d_vibration_cpp@::rollshift
          (_unnamed_d_vibration_cpp_ *this,ulong param_1,long param_2,long param_3)

{
  int iVar1;
  
  iVar1 = param_2 - (param_2 / (int)param_1) * param_1;
  return (uint)this >> iVar1 | (int)this << param_1 - iVar1;
}


/* __thiscall @unnamed@d_vibration_cpp@::makebits(unsigned long,
                                                  long,
                                                  long) */

uint __thiscall
@unnamed@d_vibration_cpp@::makebits
          (_unnamed_d_vibration_cpp_ *this,ulong param_1,long param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  
  uVar3 = (uint)this & -1 << 0x20 - param_1;
  uVar1 = uVar3;
  for (uVar2 = param_1; (int)uVar2 < param_2; uVar2 = uVar2 + param_1) {
    uVar1 = uVar3 | uVar1 >> param_1;
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8009c71c) */
/* __thiscall @unnamed@d_vibration_cpp@::randombit(long,
                                                   long) */

uint __thiscall
@unnamed@d_vibration_cpp@::randombit(_unnamed_d_vibration_cpp_ *this,long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  double in_f1;
  double extraout_f1;
  undefined8 in_f31;
  double dVar5;
  float fVar6;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar3 = 0;
  dVar5 = d_vibration::_4102;
  for (iVar2 = 0; iVar2 < (int)this; iVar2 = iVar2 + 1) {
    fVar6 = SComponent::cM_rnd((float)in_f1);
    uVar1 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                      ((double)((float)((double)CONCAT44(0x43300000,param_1 ^ 0x80000000) - dVar5) *
                               fVar6));
    uVar3 = uVar3 | 0x40000000 >> (uVar1 & 0x3f);
    in_f1 = extraout_f1;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dVibration_c::Run(void) */

undefined4 __thiscall dVibration_c::Run(dVibration_c *this)

{
  int iVar1;
  char cVar6;
  dCamera_c *pdVar2;
  uchar *puVar3;
  int iVar4;
  _unnamed_d_vibration_cpp_ *p_Var5;
  uint uVar7;
  int extraout_r4;
  int extraout_r4_00;
  uint *in_r5;
  long lVar8;
  uint in_r6;
  uint uVar9;
  ulong uVar10;
  uint local_58;
  cXyz cStack84;
  float local_48;
  float local_44;
  float local_40;
  cXyz local_3c;
  cXyz cStack48;
  cXyz acStack36 [2];
  
  this->field_0x7c = 1;
  cVar6 = dSv_player_config_c::checkVibration
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig);
  if (cVar6 != '\x01') {
    this->field_0x60 = 0xffffffff;
    this->field_0x48 = 0xffffffff;
    this->field_0x70 = 0xffffff9d;
    this->field_0x58 = 0xffffff9d;
  }
  if ((this->field_0x20 == 0) || (this->field_0x44 == 0)) {
    uVar7 = 0;
    if (this->field_0x0 == -1) {
      this->field_0x20 = 0xffffff9d;
    }
    else {
      if (-1 < (int)this->field_0x20) {
        uVar7 = 1;
      }
    }
    if (this->field_0x24 == -1) {
      this->field_0x44 = 0xffffff9d;
    }
    else {
      if (-1 < (int)this->field_0x44) {
        uVar7 = uVar7 | 2;
      }
    }
    if (uVar7 == 2) {
      uVar10 = *(ulong *)&this->field_0x2c;
      lVar8 = this->field_0x78;
      local_58 = @unnamed@d_vibration_cpp@::rollshift
                           (*(_unnamed_d_vibration_cpp_ **)&this->field_0x28,uVar10,lVar8,in_r6);
      uVar7 = @unnamed@d_vibration_cpp@::randombit
                        (*(_unnamed_d_vibration_cpp_ **)&this->field_0x30,uVar10,lVar8);
      local_58 = local_58 | uVar7;
      ::cXyz::norm(&cStack48);
      pdVar2 = (dCamera_c *)d_camera::dCam_getBody();
      in_r5 = &local_58;
      in_r6 = *(uint *)&this->field_0x34;
      dCamera_c::StartShake(pdVar2,uVar10,(uchar *)in_r5,in_r6,&cStack48);
    }
    else {
      if (uVar7 < 2) {
        if (uVar7 == 0) {
LAB_8009c990:
          pdVar2 = (dCamera_c *)d_camera::dCam_getBody();
          dCamera_c::StopShake(pdVar2);
        }
        else {
          lVar8 = *(long *)&this->field_0x8;
          local_58 = *(uint *)&this->field_0x4;
          uVar7 = @unnamed@d_vibration_cpp@::randombit
                            (*(_unnamed_d_vibration_cpp_ **)&this->field_0xc,lVar8,(long)in_r5);
          local_58 = local_58 | uVar7;
          ::cXyz::norm(acStack36);
          pdVar2 = (dCamera_c *)d_camera::dCam_getBody();
          in_r5 = &local_58;
          in_r6 = *(uint *)&this->field_0x10;
          dCamera_c::StartShake(pdVar2,lVar8,(uchar *)in_r5,in_r6,acStack36);
        }
      }
      else {
        if (3 < uVar7) goto LAB_8009c990;
        local_58 = *(int *)&this->field_0x4 << this->field_0x20;
        uVar10 = *(int *)&this->field_0x8 - this->field_0x20;
        p_Var5 = (_unnamed_d_vibration_cpp_ *)
                 @unnamed@d_vibration_cpp@::makebits
                           (*(_unnamed_d_vibration_cpp_ **)&this->field_0x28,
                            *(ulong *)&this->field_0x2c,uVar10,in_r6);
        lVar8 = this->field_0x78;
        uVar7 = @unnamed@d_vibration_cpp@::rollshift(p_Var5,uVar10,lVar8,in_r6);
        local_58 = local_58 | uVar7;
        p_Var5 = *(_unnamed_d_vibration_cpp_ **)&this->field_0x30;
        if ((int)*(_unnamed_d_vibration_cpp_ **)&this->field_0x30 <
            (int)*(_unnamed_d_vibration_cpp_ **)&this->field_0xc) {
          p_Var5 = *(_unnamed_d_vibration_cpp_ **)&this->field_0xc;
        }
        uVar7 = @unnamed@d_vibration_cpp@::randombit(p_Var5,uVar10,lVar8);
        local_58 = local_58 | uVar7;
        ::cXyz::operator__(&local_3c,(cXyz *)&this->field_0x14,(cXyz *)&this->field_0x38);
        local_48 = local_3c.x;
        local_44 = local_3c.y;
        local_40 = local_3c.z;
        ::cXyz::norm(&cStack84);
        pdVar2 = (dCamera_c *)d_camera::dCam_getBody();
        in_r5 = &local_58;
        in_r6 = *(uint *)&this->field_0x10 | *(uint *)&this->field_0x34;
        dCamera_c::StartShake(pdVar2,uVar10,(uchar *)in_r5,in_r6,&cStack84);
        this->field_0x44 = 0;
        this->field_0x20 = 0;
      }
    }
  }
  if (899 < (int)this->field_0x70) {
    JUTGamePad::CRumble::stopPatternedRumbleAtThePeriod
              (&m_Do_controller_pad::g_mDoCPd_gamePad[0]->mRumble);
    JUTGamePad::CRumble::stopMotor
              ((CRumble *)(int)m_Do_controller_pad::g_mDoCPd_gamePad[0]->mPortIdx,extraout_r4);
    this->field_0x70 = 0xffffffff;
  }
  if ((this->field_0x58 == 0) || (this->field_0x70 == 0)) {
    uVar7 = 0;
    if (this->field_0x48 == -1) {
      this->field_0x58 = 0xffffff9d;
    }
    else {
      if (-1 < (int)this->field_0x58) {
        uVar7 = 1;
      }
    }
    if (this->field_0x60 == -1) {
      this->field_0x70 = 0xffffff9d;
    }
    else {
      if (-1 < (int)this->field_0x70) {
        uVar7 = uVar7 | 2;
      }
    }
    if (uVar7 == 2) {
      uVar10 = *(ulong *)&this->field_0x68;
      lVar8 = this->field_0x78;
      uVar7 = @unnamed@d_vibration_cpp@::rollshift
                        (*(_unnamed_d_vibration_cpp_ **)&this->field_0x64,uVar10,lVar8,in_r6);
      uVar9 = @unnamed@d_vibration_cpp@::randombit
                        (*(_unnamed_d_vibration_cpp_ **)&this->field_0x6c,uVar10,lVar8);
      this->field_0x74 = 0x7fffffff;
      puVar3 = (uchar *)@unnamed@d_vibration_cpp@::makedata
                                  ((_unnamed_d_vibration_cpp_ *)&d_vibration::data_4141,
                                   (ushort *)(uVar7 | uVar9),uVar10,in_r6);
      JUTGamePad::CRumble::startPatternedRumble
                (&m_Do_controller_pad::g_mDoCPd_gamePad[0]->mRumble,puVar3,1,0x3c);
    }
    else {
      if (uVar7 < 2) {
        if (uVar7 != 0) {
          uVar10 = *(ulong *)&this->field_0x50;
          uVar9 = *(uint *)&this->field_0x4c;
          uVar7 = @unnamed@d_vibration_cpp@::randombit
                            (*(_unnamed_d_vibration_cpp_ **)&this->field_0x54,uVar10,(long)in_r5);
          this->field_0x5c = uVar10;
          puVar3 = (uchar *)@unnamed@d_vibration_cpp@::makedata
                                      ((_unnamed_d_vibration_cpp_ *)&d_vibration::data_4141,
                                       (ushort *)(uVar9 | uVar7),uVar10,in_r6);
          JUTGamePad::CRumble::startPatternedRumble
                    (&m_Do_controller_pad::g_mDoCPd_gamePad[0]->mRumble,puVar3,0,0x3c);
          goto LAB_8009cbe4;
        }
      }
      else {
        if (uVar7 < 4) {
          iVar1 = *(int *)&this->field_0x4c;
          iVar4 = this->field_0x58;
          uVar10 = *(int *)&this->field_0x50 - iVar4;
          p_Var5 = (_unnamed_d_vibration_cpp_ *)
                   @unnamed@d_vibration_cpp@::makebits
                             (*(_unnamed_d_vibration_cpp_ **)&this->field_0x64,
                              *(ulong *)&this->field_0x68,uVar10,in_r6);
          lVar8 = this->field_0x78;
          uVar7 = @unnamed@d_vibration_cpp@::rollshift(p_Var5,uVar10,lVar8,in_r6);
          p_Var5 = *(_unnamed_d_vibration_cpp_ **)&this->field_0x6c;
          if ((int)*(_unnamed_d_vibration_cpp_ **)&this->field_0x6c <
              (int)*(_unnamed_d_vibration_cpp_ **)&this->field_0x54) {
            p_Var5 = *(_unnamed_d_vibration_cpp_ **)&this->field_0x54;
          }
          uVar9 = @unnamed@d_vibration_cpp@::randombit(p_Var5,uVar10,lVar8);
          this->field_0x74 = uVar10;
          this->field_0x5c = uVar10;
          this->field_0x70 = 0;
          this->field_0x58 = 0;
          puVar3 = (uchar *)@unnamed@d_vibration_cpp@::makedata
                                      ((_unnamed_d_vibration_cpp_ *)&d_vibration::data_4141,
                                       (ushort *)(iVar1 << iVar4 | uVar7 | uVar9),uVar10,in_r6);
          JUTGamePad::CRumble::startPatternedRumble
                    (&m_Do_controller_pad::g_mDoCPd_gamePad[0]->mRumble,puVar3,0,0x3c);
          goto LAB_8009cbe4;
        }
      }
      JUTGamePad::CRumble::stopPatternedRumbleAtThePeriod
                (&m_Do_controller_pad::g_mDoCPd_gamePad[0]->mRumble);
      JUTGamePad::CRumble::stopMotor
                ((CRumble *)(int)m_Do_controller_pad::g_mDoCPd_gamePad[0]->mPortIdx,extraout_r4_00);
      this->field_0x74 = 0xffffff9d;
      this->field_0x5c = 0xffffff9d;
    }
  }
LAB_8009cbe4:
  if ((-2 < (int)this->field_0x20) &&
     (this->field_0x20 = this->field_0x20 + 1, *(int *)&this->field_0x8 < (int)this->field_0x20)) {
    this->field_0x20 = 0;
    this->field_0x0 = 0xffffffff;
  }
  if ((-2 < (int)this->field_0x58) &&
     (this->field_0x58 = this->field_0x58 + 1, (int)this->field_0x5c < (int)this->field_0x58)) {
    this->field_0x58 = 0;
    this->field_0x48 = 0xffffffff;
  }
  if ((-2 < (int)this->field_0x44) &&
     (this->field_0x44 = this->field_0x44 + 1, *(int *)&this->field_0x2c < (int)this->field_0x44)) {
    this->field_0x44 = 0;
  }
  if ((-2 < (int)this->field_0x70) &&
     (this->field_0x70 = this->field_0x70 + 1, (int)this->field_0x74 < (int)this->field_0x70)) {
    this->field_0x70 = 0;
  }
  this->field_0x78 = this->field_0x78 + 1;
  return 1;
}


/* __thiscall dVibration_c::StartShock(int,
                                       int,
                                       cXyz) */

bool __thiscall dVibration_c::StartShock(dVibration_c *this,int param_1,int param_2,cXyz *param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  bVar1 = (param_2 & 0x3eU) != 0;
  if (bVar1) {
    this->field_0x0 = param_1;
    this->field_0x20 = 0;
    *(int *)&this->field_0x10 = param_2;
    *(float *)&this->field_0x14 = param_3->x;
    *(float *)&this->field_0x18 = param_3->y;
    *(float *)&this->field_0x1c = param_3->z;
    iVar3 = param_1 * 8;
    *(undefined4 *)&this->field_0x4 = *(undefined4 *)(&DAT_803530b4 + iVar3);
    *(uint *)&this->field_0x8 = (uint)*(ushort *)(&DAT_803530b2 + iVar3);
    *(uint *)&this->field_0xc = (uint)*(ushort *)(&CS_patt + iVar3);
  }
  bVar2 = (param_2 & 1U) != 0;
  if (bVar2) {
    this->field_0x48 = param_1;
    this->field_0x58 = 0;
    *(undefined4 *)&this->field_0x4c = *(undefined4 *)(&DAT_80352fe4 + param_1 * 8);
    *(uint *)&this->field_0x50 = (uint)*(ushort *)(&DAT_80352fe2 + param_1 * 8);
  }
  return bVar2 || bVar1;
}


/* __thiscall dVibration_c::StartQuake(int,
                                       int,
                                       cXyz) */

bool __thiscall dVibration_c::StartQuake(dVibration_c *this,int param_1,int param_2,cXyz *param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  bVar1 = (param_2 & 0x3eU) != 0;
  if (bVar1) {
    this->field_0x24 = param_1;
    this->field_0x44 = 0;
    *(int *)&this->field_0x34 = param_2;
    *(float *)&this->field_0x38 = param_3->x;
    *(float *)&this->field_0x3c = param_3->y;
    *(float *)&this->field_0x40 = param_3->z;
    iVar3 = param_1 * 8;
    *(undefined4 *)&this->field_0x28 = *(undefined4 *)(&DAT_803531e4 + iVar3);
    *(uint *)&this->field_0x2c = (uint)*(ushort *)(&DAT_803531e2 + iVar3);
    *(uint *)&this->field_0x30 = (uint)*(ushort *)(&CQ_patt + iVar3);
  }
  bVar2 = (param_2 & 1U) != 0;
  if (bVar2) {
    this->field_0x60 = param_1;
    this->field_0x70 = 0;
    iVar3 = param_1 * 8;
    *(undefined4 *)&this->field_0x64 = *(undefined4 *)(&DAT_80353184 + iVar3);
    *(uint *)&this->field_0x68 = (uint)*(ushort *)(&DAT_80353182 + iVar3);
    *(uint *)&this->field_0x6c = (uint)*(ushort *)(&CQ_patt + iVar3);
  }
  return bVar2 || bVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dVibration_c::StartQuake(unsigned char const *,
                                       int,
                                       int,
                                       cXyz) */

bool __thiscall
dVibration_c::StartQuake(dVibration_c *this,uchar *param_1,int param_2,int param_3,cXyz *param_4)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  _unnamed_d_vibration_cpp_ *this_00;
  
  uVar4 = (uint)*(ushort *)param_1;
  uVar5 = (uint)param_1[-(uint)(uVar4 - 0x19 < 0x7fffffe7) & 5];
  this_00 = (_unnamed_d_vibration_cpp_ *)
            (uVar5 | (uint)param_1[-(uint)(uVar4 - 0x11 < 0x7fffffef) & 4] << 8 |
                     (uint)param_1[-(uint)(uVar4 - 1 < 0x7fffffff) & 2] << 0x18 |
                     (uint)param_1[-(uint)(uVar4 - 9 < 0x7ffffff7) & 3] << 0x10);
  bVar1 = (param_3 & 0x3eU) != 0;
  if (bVar1) {
    this->field_0x24 = 0;
    this->field_0x44 = 0;
    *(int *)&this->field_0x34 = param_3;
    *(float *)&this->field_0x38 = param_4->x;
    *(float *)&this->field_0x3c = param_4->y;
    *(float *)&this->field_0x40 = param_4->z;
    uVar3 = @unnamed@d_vibration_cpp@::makebits(this_00,(uint)param_1[1],0x20,uVar5);
    *(undefined4 *)&this->field_0x28 = uVar3;
    *(undefined4 *)&this->field_0x2c = 0x20;
    *(int *)&this->field_0x30 = param_2;
  }
  bVar2 = (param_3 & 1U) != 0;
  if (bVar2) {
    this->field_0x60 = 0;
    this->field_0x70 = 0;
    uVar3 = @unnamed@d_vibration_cpp@::makebits(this_00,(uint)param_1[1],0x20,uVar5);
    *(undefined4 *)&this->field_0x64 = uVar3;
    *(undefined4 *)&this->field_0x68 = 0x20;
    *(int *)&this->field_0x6c = param_2;
  }
  return bVar2 || bVar1;
}


/* __thiscall dVibration_c::StopQuake(int) */

undefined4 __thiscall dVibration_c::StopQuake(dVibration_c *this,int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 & 0x3eU) != 0) {
    *(uint *)&this->field_0x34 = *(uint *)&this->field_0x34 & ~param_1;
    if (*(int *)&this->field_0x34 == 0) {
      this->field_0x24 = 0xffffffff;
    }
    this->field_0x44 = 0;
    uVar1 = 1;
  }
  if (((param_1 & 1U) != 0) && (this->field_0x60 != -1)) {
    this->field_0x60 = 0xffffffff;
    this->field_0x70 = 0;
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall dVibration_c::Kill(void) */

void __thiscall dVibration_c::Kill(dVibration_c *this)

{
  JUTGamePad::CRumble::stopPatternedRumble
            (&m_Do_controller_pad::g_mDoCPd_gamePad[0]->mRumble,
             m_Do_controller_pad::g_mDoCPd_gamePad[0]->mPortIdx);
  JUTGamePad::CRumble::stopMotorHard((int)m_Do_controller_pad::g_mDoCPd_gamePad[0]->mPortIdx);
  setDefault(this);
  return;
}


/* __thiscall dVibration_c::CheckQuake(void) */

undefined4 __thiscall dVibration_c::CheckQuake(dVibration_c *this)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((this->field_0x24 != -1) || (this->field_0x60 != -1)) {
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall dVibration_c::setDefault(void) */

void __thiscall dVibration_c::setDefault(dVibration_c *this)

{
  this->field_0x48 = 0xffffffff;
  this->field_0x0 = 0xffffffff;
  this->field_0x60 = 0xffffffff;
  this->field_0x24 = 0xffffffff;
  this->field_0x58 = 0xffffff9d;
  this->field_0x20 = 0xffffff9d;
  this->field_0x70 = 0xffffff9d;
  this->field_0x44 = 0xffffff9d;
  this->field_0x74 = 0xffffff9d;
  this->field_0x5c = 0xffffff9d;
  this->field_0x7c = 0;
  this->field_0x78 = 0;
  return;
}


/* __thiscall dVibration_c::Init(void) */

void __thiscall dVibration_c::Init(dVibration_c *this)

{
  setDefault(this);
  return;
}


/* __thiscall dVibration_c::Pause(void) */

void __thiscall dVibration_c::Pause(dVibration_c *this)

{
  if (this->field_0x7c != -1) {
    if ((this->field_0x48 != -1) || (this->field_0x60 != -1)) {
      JUTGamePad::CRumble::stopPatternedRumble
                (&m_Do_controller_pad::g_mDoCPd_gamePad[0]->mRumble,
                 m_Do_controller_pad::g_mDoCPd_gamePad[0]->mPortIdx);
      JUTGamePad::CRumble::stopMotorHard((int)m_Do_controller_pad::g_mDoCPd_gamePad[0]->mPortIdx);
    }
    this->field_0x48 = 0xffffffff;
    this->field_0x0 = 0xffffffff;
    this->field_0x58 = 0xffffff9d;
    this->field_0x20 = 0xffffff9d;
    if (this->field_0x24 != -1) {
      this->field_0x44 = 0;
    }
    if (this->field_0x60 != -1) {
      this->field_0x70 = 0;
    }
    this->field_0x7c = 0xffffffff;
  }
  return;
}


/* __thiscall dVibration_c::dVibration_c(void) */

void __thiscall dVibration_c::dVibration_c(dVibration_c *this)

{
  this->field_0x80 = &__vt;
  setDefault(this);
  return;
}


/* __thiscall dVibration_c::~dVibration_c(void) */

void __thiscall dVibration_c::_dVibration_c(dVibration_c *this)

{
  short in_r4;
  
  if (this != (dVibration_c *)0x0) {
    this->field_0x80 = &__vt;
    Kill(this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

