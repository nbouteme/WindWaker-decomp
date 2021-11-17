#include <d_a_disappear.h>
#include <f_op_actor_mng.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_particle.h>
#include <f_op_actor.h>
#include <d_a_disappear.h>


namespace d_a_disappear {

/* __stdcall daDisappear_Draw(disappear_class *) */

undefined4 daDisappear_Draw(void)

{
  return 1;
}


/* __stdcall daDisappear_Execute(disappear_class *) */

undefined4 daDisappear_Execute(base_process_class *param_1)

{
  short sVar1;
  int iVar2;
  
  sVar1 = *(short *)&param_1[3].mPi.parent.mpTagData;
  if (sVar1 == 0) {
    f_op_actor_mng::fopAcM_delete(param_1);
  }
  else {
    *(short *)&param_1[3].mPi.parent.mpTagData = sVar1 + -1;
    if (((*(short *)&param_1[3].mPi.parent.mpTagData == 0) &&
        (iVar2 = (int)*(char *)&param_1[3].mDtTg.parent.field_0x11, iVar2 != 1)) && (iVar2 != 3)) {
      if (iVar2 == 2) {
        f_op_actor_mng::fopAcM_createItemForBoss
                  ((cXyz *)&param_1[2].mPi.mMtdTg.parent.mpTagData,0,
                   (int)*(char *)((int)&param_1[2].mPi.mLayerQ + 2),
                   (csXyz *)&param_1[2].mPi.mMtdTg.mpUserData,(cXyz *)0x0,0);
      }
      else {
        if ((iVar2 < 10) || (0xd < iVar2)) {
          f_op_actor_mng::fopAcM_createIball
                    ((cXyz *)&param_1[2].mPi.mMtdTg.parent.mpTagData,(int)param_1[3].mDtTg.mpLayer,
                     (int)*(char *)((int)&param_1[2].mPi.mLayerQ + 2),
                     (csXyz *)&param_1[2].mPi.mMtdTg.mpUserData,
                     (int)param_1[3].mPi.parent.parent.mpNextNode);
        }
        else {
          if (iVar2 < 0xd) {
            f_op_actor_mng::fopAcM_createItem
                      ((cXyz *)&param_1[2].mPi.mMtdTg.parent.mpTagData,
                       (dItem_data__ItemNo)
                       (&d_a_demo00::g_profile_DEMO00.parent.mDefaultParameters)[iVar2],-1,-1,0,
                       (csXyz *)0x0,4,(cXyz *)0x0);
          }
        }
      }
    }
  }
  return 1;
}


/* __stdcall daDisappear_IsDelete(disappear_class *) */

undefined4 daDisappear_IsDelete(void)

{
  return 1;
}


/* __stdcall daDisappear_Delete(disappear_class *) */

undefined4 daDisappear_Delete(void)

{
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x800e7d9c) */
/* __stdcall set_disappear(disappear_class *,
                           float) */

void set_disappear(double param_1,int param_2)

{
  sbyte sVar1;
  undefined4 uVar2;
  undefined8 in_f31;
  cXyz local_28;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  sVar1 = d_com_inf_game::dComIfGp_getReverb((int)*(char *)(param_2 + 0x20a));
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x5801,(cXyz *)(param_2 + 0x260),0,sVar1,_4111,_4111,_4112,_4112
             ,0);
  local_28.x = (float)param_1;
  local_28.y = (float)param_1;
  local_28.z = (float)param_1;
  *(short *)(param_2 + 0x29c) = d_s_play::g_regHIO.mChild[8].mShorts[0] + 0x3a;
  switch(*(undefined *)(param_2 + 0x285)) {
  case 0:
  case 2:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x14,
                       (cXyz *)(param_2 + 0x1f8),(csXyz *)0x0,&local_28,0xff,
                       (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  case 3:
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x13,
                       (cXyz *)(param_2 + 0x1f8),(csXyz *)0x0,&local_28,0xff,
                       (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
    dPa_control_c::setNormalStripes
              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0x15,(cXyz *)(param_2 + 0x1f8)
               ,(csXyz *)0x0,&local_28,0xff,0x96);
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x16,
                       (cXyz *)(param_2 + 0x1f8),(csXyz *)0x0,&local_28,0xff,
                       (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
    break;
  case 1:
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x13,
                       (cXyz *)(param_2 + 0x1f8),(csXyz *)0x0,&local_28,0xff,
                       (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x16,
                       (cXyz *)(param_2 + 0x1f8),(csXyz *)0x0,&local_28,0xff,
                       (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
    break;
  case 4:
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x43c,
                       (cXyz *)(param_2 + 0x1f8),(csXyz *)0x0,(cXyz *)0x0,0xff,
                       (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x43d,
                       (cXyz *)(param_2 + 0x1f8),(csXyz *)0x0,(cXyz *)0x0,0xff,
                       (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x43e,
                       (cXyz *)(param_2 + 0x1f8),(csXyz *)0x0,(cXyz *)0x0,0xff,
                       (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* __stdcall daDisappear_Create(fopAc_ac_c *) */

undefined4 daDisappear_Create(fopAc_ac_c *param_1)

{
  float fVar1;
  uint uVar2;
  
  if ((param_1->mCondition & Constructed) == 0) {
    if (param_1 != (fopAc_ac_c *)0x0) {
      fopAc_ac_c::fopAc_ac_c(param_1);
    }
    param_1->mCondition = param_1->mCondition | Constructed;
  }
  param_1->mCurrHp = (sbyte)(param_1->parent).parent.mParameters;
  uVar2 = (param_1->parent).parent.mParameters;
  fVar1 = _4146 * (float)((double)CONCAT44(0x43300000,uVar2 >> 8 & 0xff) - _4148);
  *(uint *)&param_1[1].parent.parent.mProcName = uVar2 >> 0x10 & 0xff;
  if (*(int *)&param_1[1].parent.parent.mProcName == 0xff) {
    *(undefined4 *)&param_1[1].parent.parent.mProcName = 0xffffffff;
  }
  set_disappear((double)fVar1,param_1);
  return 4;
}

