#include <d_a_spc_item01.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <d_a_itembase.h>
#include <f_op_actor.h>
#include <d_bg_s_acch.h>
#include <d_cc_d.h>
#include <d_save.h>
#include <d_a_itembase_static.h>
#include <d_com_inf_game.h>
#include <f_op_actor_mng.h>
#include <d_a_spc_item01.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <d_item_data.h>
#include <d_particle.h>
#include <d_item.h>
#include <SComponent/c_lib.h>
#include <d_kankyo.h>
#include <daSpcItem01_c.h>


/* __thiscall daSpcItem01_c::set_mtx(void) */

void __thiscall daSpcItem01_c::set_mtx(daSpcItem01_c *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  short sVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  short local_28;
  short sStack38;
  
  uVar5 = *(undefined4 *)(this + 0x204);
  sVar3 = *(short *)(this + 0x208);
  uVar1 = *(undefined4 *)(this + 0x218);
  uVar2 = *(undefined4 *)(this + 0x21c);
  fVar4 = d_a_spc_item01::_4032;
  if (this[0x63a] != (daSpcItem01_c)0x48) {
    fVar4 = d_a_spc_item01::_4031;
  }
  iVar6 = *(int *)(this + 0x29c);
  *(undefined4 *)(iVar6 + 0x18) = *(undefined4 *)(this + 0x214);
  *(undefined4 *)(iVar6 + 0x1c) = uVar1;
  *(undefined4 *)(iVar6 + 0x20) = uVar2;
  mtx::PSMTXTrans((double)*(float *)(this + 0x1f8),(double)(*(float *)(this + 0x1fc) + fVar4),
                  (double)*(float *)(this + 0x200),&mDoMtx_stack_c::now);
  local_28 = (short)((uint)uVar5 >> 0x10);
  sStack38 = (short)uVar5;
  m_Do_mtx::mDoMtx_ZXYrotM(&mDoMtx_stack_c::now,(int)local_28,(int)sStack38,(int)sVar3);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)(this + 0x29c) + 0x24));
  return;
}


/* __thiscall daSpcItem01_c::_delete(void) */

void __thiscall daSpcItem01_c::_delete(daSpcItem01_c *this)

{
  daItemBase_c::DeleteBase
            ((daItemBase_c *)this,dItem_data::field_item_res[(byte)this[0x63a]].mModelArcName);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daSpcItem01_c::_create(void) */

PhaseState __thiscall daSpcItem01_c::_create(daSpcItem01_c *this)

{
  int iVar1;
  PhaseState PVar2;
  uint uVar3;
  
  if ((*(uint *)(this + 0x1c8) & 8) == 0) {
    if (this != (daSpcItem01_c *)0x0) {
      fopAc_ac_c::fopAc_ac_c((fopAc_ac_c *)this);
      *(daItemBase_c__vtbl **)(this + 0x290) = &daItemBase_c::__vt;
      dBgS_Acch::dBgS_Acch((dBgS_Acch *)(this + 700));
      *(dBgS_ObjAcch__vtbl **)(this + 0x2cc) = &::dBgS_ObjAcch::__vt;
      *(undefined4 *)(this + 0x2d0) = 0x8037e9e4;
      *(undefined4 *)(this + 0x2dc) = 0x8037e9f0;
      this[0x2d4] = (daSpcItem01_c)0x1;
      ::dBgS_AcchCir::dBgS_AcchCir((dBgS_AcchCir *)(this + 0x480));
      *(cCcD_Stts__vtbl **)(this + 0x4d8) = &cCcD_Stts::__vt;
      ::dCcD_GStts::dCcD_GStts((dCcD_GStts *)(this + 0x4dc));
      *(dCcD_Stts__vtbl **)(this + 0x4d8) = &::dCcD_Stts::__vt;
      *(undefined4 *)(this + 0x4dc) = 0x8037ec40;
      dCcD_GObjInf::dCcD_GObjInf((dCcD_GObjInf *)(this + 0x4fc));
      *(undefined ***)(this + 0x610) = &::cCcD_ShapeAttr::__vt;
      *(cM3dGAab__vtbl **)(this + 0x60c) = &::cM3dGAab::__vt;
      *(undefined ***)(this + 0x628) = &::cM3dGCyl::__vt;
      *(cCcD_ShapeAttr__vtbl **)(this + 0x610) = &::cCcD_CylAttr::__vt;
      *(cCcD_CylAttr__vtbl **)(this + 0x628) = &cCcD_CylAttr__vtbl_803951ac;
      *(dCcD_Cyl__vtbl **)(this + 0x538) = &::dCcD_Cyl::__vt;
      *(undefined4 *)(this + 0x610) = 0x8038af30;
      *(undefined4 *)(this + 0x628) = 0x8038af84;
      *(daItemBase_c__vtbl **)(this + 0x290) = &__vt;
    }
    *(uint *)(this + 0x1c8) = *(uint *)(this + 0x1c8) | 8;
  }
  this[0x63a] = SUB41(*(undefined4 *)(this + 0xb0),0);
  if ((this[0x63a] == (daSpcItem01_c)0x3b) &&
     (iVar1 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xe20), iVar1 != 0
     )) {
    daItemBase_c::setLoadError((daItemBase_c *)this);
    PVar2 = cPhs_ERROR_e;
  }
  else {
    PVar2 = d_com_inf_game::dComIfG_resLoad
                      ((request_of_phase_process_class *)(this + 0x294),
                       dItem_data::field_item_res[(byte)this[0x63a]].mModelArcName);
    if (PVar2 == cPhs_COMPLEATE_e) {
      uVar3 = f_op_actor_mng::fopAcM_entrySolidHeap
                        ((fopAc_ac_c *)this,d_a_itembase_static::CheckFieldItemCreateHeap,
                         (uint)dItem_data::item_resource[(byte)this[0x63a]].mMaxHeapSize);
      if ((uVar3 & 0xff) == 0) {
        PVar2 = cPhs_ERROR_e;
      }
      else {
        CreateInit(this);
      }
    }
  }
  return PVar2;
}


/* WARNING: Removing unreachable block (ram,0x8015df30) */
/* __thiscall daSpcItem01_c::CreateInit(void) */

undefined4 __thiscall daSpcItem01_c::CreateInit(daSpcItem01_c *this)

{
  float fVar1;
  uint uVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  set_mtx(this);
  *(int *)(this + 0x22c) = *(int *)(this + 0x29c) + 0x24;
  ::dCcD_Stts::Init((dCcD_Stts *)(this + 0x4c0),0,0xff,(fopAc_ac_c *)this);
  ::dCcD_Cyl::Set((dCcD_Cyl *)(this + 0x4fc),(dCcD_SrcCyl *)&d_a_spc_item01::l_cyl_src);
  *(daSpcItem01_c **)(this + 0x540) = this + 0x4c0;
  uVar2 = daItemBase_c::getHeight((daItemBase_c *)this);
  dVar6 = (double)(float)((double)CONCAT44(0x43300000,uVar2 & 0xff) - d_a_spc_item01::_4217);
  uVar2 = daItemBase_c::getR((daItemBase_c *)this);
  dVar4 = (double)(float)((double)CONCAT44(0x43300000,uVar2 & 0xff) - d_a_spc_item01::_4217);
  dVar5 = (double)*(float *)(this + 0x214);
  if ((double)d_a_spc_item01::_4212 < dVar5) {
    dVar6 = (double)(float)(dVar6 * dVar5);
    dVar4 = (double)(float)(dVar4 * dVar5);
  }
  ::cM3dGCyl::SetR((cM3dGCyl *)(this + 0x614),(float)dVar4);
  ::cM3dGCyl::SetH((cM3dGCyl *)(this + 0x614),(float)dVar6);
  ::dBgS_AcchCir::SetWall
            ((dBgS_AcchCir *)(this + 0x480),d_a_spc_item01::_4213,d_a_spc_item01::_4213);
  dBgS_Acch::Set((dBgS_Acch *)(this + 700),(cXyz *)(this + 0x1f8),(cXyz *)(this + 0x1e4),
                 (fopAc_ac_c *)this,1,(dBgS_AcchCir *)(this + 0x480),(cXyz *)(this + 0x220),
                 (csXyz *)0x0,(csXyz *)0x0);
  *(short *)(this + 0x644) = (short)((uint)*(undefined4 *)(this + 0xb0) >> 8);
  *(float *)(this + 600) = d_a_spc_item01::_4214;
  fVar1 = d_a_spc_item01::_4215;
  if (this[0x63a] == (daSpcItem01_c)0x3b) {
    *(float *)(this + 0x214) = d_a_spc_item01::_4215;
    *(float *)(this + 0x218) = fVar1;
    *(float *)(this + 0x21c) = fVar1;
    *(undefined2 *)(this + 0x204) = 4000;
    *(undefined2 *)(this + 0x206) = 0x1068;
    *(undefined2 *)(this + 0x208) = 0x1450;
    *(float *)(this + 600) = d_a_spc_item01::_4031;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return 1;
}


/* __thiscall daSpcItem01_c::_execute(void) */

undefined4 __thiscall daSpcItem01_c::_execute(daSpcItem01_c *this)

{
  *(undefined4 *)(this + 0x260) = *(undefined4 *)(this + 0x1f8);
  *(undefined4 *)(this + 0x264) = *(undefined4 *)(this + 0x1fc);
  *(undefined4 *)(this + 0x268) = *(undefined4 *)(this + 0x200);
  *(undefined4 *)(this + 0x274) = *(undefined4 *)(this + 0x1f8);
  *(undefined4 *)(this + 0x278) = *(undefined4 *)(this + 0x1fc);
  *(undefined4 *)(this + 0x27c) = *(undefined4 *)(this + 0x200);
  *(int *)(this + 0x634) = *(int *)(this + 0x634) + 1;
  set_effect(this);
  scale_anim(this);
  anim_play(this);
  move(this);
  rotate_item(this);
  setCol(this);
  set_mtx(this);
  return 1;
}


/* __thiscall daSpcItem01_c::set_effect(void) */

void __thiscall daSpcItem01_c::set_effect(daSpcItem01_c *this)

{
  char cVar2;
  uint uVar1;
  uchar in_r4;
  
  if (((((*(ushort *)(this + 0x644) & 1) != 0) &&
       (cVar2 = dItem_data::checkAppearEffect((dItem_data *)(uint)(byte)this[0x63a],in_r4),
       cVar2 != '\0')) && (this[0x642] == (daSpcItem01_c)0x0)) &&
     (this[0x63a] != (daSpcItem01_c)0x48)) {
    uVar1 = dItem_data::getAppearEffect((uchar)this[0x63a]);
    dPa_control_c::setSimple
              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,(ushort)uVar1,
               (cXyz *)(this + 0x1f8),0xff,&d_com_inf_game::g_whiteColor,
               &d_com_inf_game::g_whiteColor,0);
  }
  return;
}


/* __thiscall daSpcItem01_c::scale_anim(void) */

void __thiscall daSpcItem01_c::scale_anim(daSpcItem01_c *this)

{
  int iVar1;
  
  iVar1 = d_item::isRupee((byte)this[0x63a]);
  if (iVar1 != 0) {
    SComponent::cLib_chaseF((float *)(this + 0x214),d_a_spc_item01::_4212,d_a_spc_item01::_4257);
    SComponent::cLib_chaseF((float *)(this + 0x218),d_a_spc_item01::_4212,d_a_spc_item01::_4257);
    SComponent::cLib_chaseF((float *)(this + 0x21c),d_a_spc_item01::_4212,d_a_spc_item01::_4257);
  }
  return;
}


/* __thiscall daSpcItem01_c::anim_play(void) */

void __thiscall daSpcItem01_c::anim_play(daSpcItem01_c *this)

{
  float fVar1;
  
  fVar1 = d_a_spc_item01::_4212;
  if (this[0x63a] == (daSpcItem01_c)0x48) {
    fVar1 = d_a_spc_item01::_4031;
  }
  daItemBase_c::animPlay
            ((daItemBase_c *)this,d_a_spc_item01::_4212,d_a_spc_item01::_4212,d_a_spc_item01::_4212,
             d_a_spc_item01::_4212,fVar1);
  return;
}


/* __thiscall daSpcItem01_c::move(void) */

void __thiscall daSpcItem01_c::move(daSpcItem01_c *this)

{
  daSpcItem01_c dVar1;
  float fVar2;
  float fVar3;
  
  f_op_actor_mng::fopAcM_posMoveF((fopAc_ac_c *)this,(cXyz *)(this + 0x4c0));
  dBgS_Acch::CrrPos((dBgS_Acch *)(this + 700),&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  fVar2 = d_a_spc_item01::_4031;
  dVar1 = this[0x63a];
  if (dVar1 != (daSpcItem01_c)0x3b) {
    if (((byte)dVar1 < 0x3b) && (dVar1 == (daSpcItem01_c)0x1f)) {
      if ((*(uint *)(this + 0x2e4) & 0x80) != 0) {
        *(float *)(this + 0x220) = d_a_spc_item01::_4031;
        *(float *)(this + 0x224) = fVar2;
        *(float *)(this + 0x228) = fVar2;
        *(float *)(this + 0x254) = fVar2;
      }
    }
    else {
      if ((*(uint *)(this + 0x2e4) & 0x80) != 0) {
        this[0x642] = (daSpcItem01_c)((char)this[0x642] + '\x01');
        fVar3 = d_a_spc_item01::_4031;
        fVar2 = d_a_spc_item01::_4295 * *(float *)(this + 0x63c);
        if (fVar2 <= *(float *)(this + 600) - d_a_spc_item01::_4296) {
          *(float *)(this + 0x220) = d_a_spc_item01::_4031;
          *(float *)(this + 0x224) = -fVar2;
          *(float *)(this + 0x228) = fVar3;
        }
        else {
          *(float *)(this + 0x254) = d_a_spc_item01::_4031;
        }
      }
    }
  }
  if (d_a_spc_item01::_4031 != *(float *)(this + 0x224)) {
    *(float *)(this + 0x63c) = *(float *)(this + 0x224);
  }
  return;
}


/* __thiscall daSpcItem01_c::rotate_item(void) */

void __thiscall daSpcItem01_c::rotate_item(daSpcItem01_c *this)

{
  int iVar1;
  
  iVar1 = d_item::isRupee((byte)this[0x63a]);
  if (iVar1 != 0) {
    if (this[0x642] == (daSpcItem01_c)0x0) {
      *(short *)(this + 0x640) = *(short *)(this + 0x204) + 0x2000;
    }
    else {
      *(undefined2 *)(this + 0x640) = 0;
    }
    SComponent::cLib_chaseAngleS(this + 0x204,(int)*(short *)(this + 0x640),0x2000);
  }
  return;
}


/* __thiscall daSpcItem01_c::setCol(void) */

void __thiscall daSpcItem01_c::setCol(daSpcItem01_c *this)

{
  return;
}


/* __thiscall daSpcItem01_c::_draw(void) */

void __thiscall daSpcItem01_c::_draw(daSpcItem01_c *this)

{
  (**(code **)(*(int *)(this + 0x290) + 8))();
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall daSpcItem01_c::setTevStr(void) */

void __thiscall daSpcItem01_c::setTevStr(daSpcItem01_c *this)

{
  int iVar1;
  int iVar2;
  
  if (this[0x63a] == (daSpcItem01_c)0x48) {
    dScnKy_env_light_c::settingTevStruct
              (&d_kankyo::g_env_light,BG1,(cXyz *)(this + 0x1f8),(dKy_tevstr_c *)(this + 0x10c));
  }
  else {
    dScnKy_env_light_c::settingTevStruct
              (&d_kankyo::g_env_light,Actor,(cXyz *)(this + 0x1f8),(dKy_tevstr_c *)(this + 0x10c));
  }
  dScnKy_env_light_c::setLightTevColorType
            (&d_kankyo::g_env_light,*(J3DModel **)(this + 0x29c),(dKy_tevstr_c *)(this + 0x10c));
  iVar1 = 0;
  iVar2 = 0;
  do {
    if (*(J3DModel **)(this + iVar2 + 0x2a0) != (J3DModel *)0x0) {
      dScnKy_env_light_c::setLightTevColorType
                (&d_kankyo::g_env_light,*(J3DModel **)(this + iVar2 + 0x2a0),
                 (dKy_tevstr_c *)(this + 0x10c));
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar1 < 2);
  return;
}


namespace d_a_spc_item01 {

/* __stdcall daSpcItem01_Draw(daSpcItem01_c *) */

void daSpcItem01_Draw(daSpcItem01_c *param_1)

{
  ::daSpcItem01_c::_draw(param_1);
  return;
}


/* __stdcall daSpcItem01_Execute(daSpcItem01_c *) */

void daSpcItem01_Execute(daSpcItem01_c *param_1)

{
  ::daSpcItem01_c::_execute(param_1);
  return;
}


/* __stdcall daSpcItem01_IsDelete(daSpcItem01_c *) */

undefined4 daSpcItem01_IsDelete(void)

{
  return 1;
}


/* __stdcall daSpcItem01_Delete(daSpcItem01_c *) */

void daSpcItem01_Delete(daSpcItem01_c *param_1)

{
  ::daSpcItem01_c::_delete(param_1);
  return;
}


/* __stdcall daSpcItem01_Create(fopAc_ac_c *) */

void daSpcItem01_Create(daSpcItem01_c *param_1)

{
  ::daSpcItem01_c::_create(param_1);
  return;
}

