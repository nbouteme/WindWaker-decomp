#include <d_kyeff.h>
#include <d_kankyo_wether.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_kankyo_data.h>
#include <d_kyeff.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <os/OSTime.h>
#include <d_kankyo.h>
#include <dKyeff_c.h>


namespace d_kyeff {

/* __stdcall dKyeff_Draw(dKyeff_c *) */

undefined4 dKyeff_Draw(void)

{
  d_kankyo_wether::dKyw_wether_draw();
  return 1;
}


/* __stdcall get_parcent(float,
                         float,
                         float) */

double get_parcent(double param_1,double param_2,double param_3)

{
  double dVar1;
  
  if ((_4102 != (float)(param_1 - param_2)) &&
     (dVar1 = (double)(float)((double)_4103 -
                             (double)((float)(param_1 - param_3) / (float)(param_1 - param_2))),
     dVar1 < (double)_4103)) {
    return dVar1;
  }
  return (double)_4103;
}


/* __stdcall s16_data_ratio_set(short,
                                short,
                                float) */

int s16_data_ratio_set(double param_1,short param_2,short param_3)

{
  return (int)(short)(param_2 +
                     (short)(int)(param_1 *
                                 (double)(float)((double)CONCAT44(0x43300000,
                                                                  (int)param_3 - (int)param_2 ^
                                                                  0x80000000) - _4110)));
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80198454) */
/* WARNING: Removing unreachable block (ram,0x8019845c) */
/* __stdcall menu_vrbox_set(void) */

void menu_vrbox_set(void)

{
  camera_class *pcVar1;
  undefined4 uVar2;
  float *pfVar3;
  int iVar4;
  uint unaff_r29;
  stage_vrbox_info_class *psVar5;
  int iVar6;
  stage_vrbox_info_class *psVar7;
  uint unaff_r31;
  undefined4 uVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double local_98;
  double local_90;
  double local_88;
  double local_80;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pcVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos).x = _4150;
  (pcVar1->mEyePos).y = _4102;
  (pcVar1->mEyePos).z = _4151;
  (pcVar1->mCenterPos).x = _4152;
  (pcVar1->mCenterPos).y = _4153;
  (pcVar1->mCenterPos).z = _4154;
  d_kankyo::g_env_light.mWindPower = _4155;
  dVar9 = (double)d_kankyo::g_env_light.mCurTime;
  d_kankyo::g_env_light.mCurTime = (float)(dVar9 + (double)_4156);
  uVar2 = Runtime.PPCEABI.H::__cvt_fp2unsigned();
  local_98 = (double)CONCAT44(0x43300000,uVar2);
  if (_4157 <= (float)(local_98 - _4162)) {
    d_kankyo::g_env_light.mCurTime = _4102;
  }
  JAIZelBasic::zel_basic->field_0x2c = (byte)(int)(dVar9 / (double)_4158);
  local_88 = (double)CONCAT44(0x43300000,(int)((double)_4159 * dVar9) % 15000000 ^ 0x80000000);
  JAIZelBasic::zel_basic->field_0x2d =
       (byte)(int)((double)(float)(local_88 - _4110) / (double)_4159);
  d_kankyo::g_env_light.mpSchejule =
       (dScnKy__Schedule *)d_kankyo::d_kankyo_data::dKyd_schejule_menu_getp();
  iVar4 = 0;
  iVar6 = 0;
  do {
    pfVar3 = (float *)((int)&(d_kankyo::g_env_light.mpSchejule)->mTimeEnd + iVar6);
    if (((double)*pfVar3 <= dVar9) && (dVar9 <= (double)pfVar3[1])) {
      unaff_r29 = (uint)*(byte *)(pfVar3 + 2);
      unaff_r31 = (uint)*(byte *)((int)pfVar3 + 9);
      in_f31 = get_parcent((double)pfVar3[1],(double)*pfVar3,dVar9);
    }
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 0xc;
  } while (iVar4 < 0xb);
  d_kankyo::g_env_light.mpVrboxInfo = d_kankyo::d_kankyo_data::dKyd_dmvrbox_getp();
  psVar7 = d_kankyo::g_env_light.mpVrboxInfo + unaff_r29;
  psVar5 = d_kankyo::g_env_light.mpVrboxInfo + unaff_r31;
  d_kankyo::g_env_light.mVrSkyColor.r =
       s16_data_ratio_set(in_f31,psVar7->mSkyColor[0],psVar5->mSkyColor[0]);
  d_kankyo::g_env_light.mVrSkyColor.g =
       s16_data_ratio_set(in_f31,psVar7->mSkyColor[1],psVar5->mSkyColor[1]);
  d_kankyo::g_env_light.mVrSkyColor.b =
       s16_data_ratio_set(in_f31,psVar7->mSkyColor[2],psVar5->mSkyColor[2]);
  d_kankyo::g_env_light.mVrkumoColor.r =
       s16_data_ratio_set(in_f31,psVar7->mKumoColor[0],psVar5->mKumoColor[0]);
  d_kankyo::g_env_light.mVrkumoColor.g =
       s16_data_ratio_set(in_f31,psVar7->mKumoColor[1],psVar5->mKumoColor[1]);
  d_kankyo::g_env_light.mVrkumoColor.b =
       s16_data_ratio_set(in_f31,psVar7->mKumoColor[2],psVar5->mKumoColor[2]);
  d_kankyo::g_env_light.mVrkumoCenterColor.r =
       s16_data_ratio_set(in_f31,psVar7->mKumoCenterColor[0],psVar5->mKumoCenterColor[0]);
  d_kankyo::g_env_light.mVrkumoCenterColor.g =
       s16_data_ratio_set(in_f31,psVar7->mKumoCenterColor[1],psVar5->mKumoCenterColor[1]);
  d_kankyo::g_env_light.mVrkumoCenterColor.b =
       s16_data_ratio_set(in_f31,psVar7->mKumoCenterColor[2],psVar5->mKumoCenterColor[2]);
  local_80 = (double)CONCAT44(0x43300000,(int)d_kankyo::g_env_light.mVrkumoColor.r ^ 0x80000000U);
  local_90 = (double)CONCAT44(0x43300000,(int)d_kankyo::g_env_light.mVrkumoColor.g ^ 0x80000000U);
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  d_kankyo::g_env_light.mVrUsoUmiColor.r =
       (ushort)(int)(_4160 * (float)((double)CONCAT44(0x43300000,
                                                      (int)d_kankyo::g_env_light.mVrkumoColor.r ^
                                                      0x80000000U) - _4110)) & 0xff;
  d_kankyo::g_env_light.mVrUsoUmiColor.g =
       (ushort)(int)(_4160 * (float)((double)CONCAT44(0x43300000,
                                                      (int)d_kankyo::g_env_light.mVrkumoColor.g ^
                                                      0x80000000U) - _4110)) & 0xff;
  d_kankyo::g_env_light.mVrUsoUmiColor.b =
       (ushort)(int)(_4160 * (float)((double)CONCAT44(0x43300000,
                                                      (int)d_kankyo::g_env_light.mVrkumoColor.b ^
                                                      0x80000000U) - _4110)) & 0xff;
  d_kankyo::g_env_light.mVrkumoColor.a = 0xff;
  d_kankyo::g_env_light.mVrKasumiMaeColor.r =
       (ushort)(int)(_4160 * (float)(local_80 - _4110)) & 0xff;
  d_kankyo::g_env_light.mVrKasumiMaeColor.g =
       (ushort)(int)(_4160 * (float)(local_90 - _4110)) & 0xff;
  d_kankyo::g_env_light.mVrKasumiMaeColor.b =
       (ushort)(int)(_4160 * (float)((double)CONCAT44(0x43300000,
                                                      (int)d_kankyo::g_env_light.mVrkumoColor.b ^
                                                      0x80000000U) - _4110)) & 0xff;
  return;
}

}

/* __thiscall dKyeff_c::execute(void) */

undefined4 __thiscall dKyeff_c::execute(dKyeff_c *this)

{
  int iVar1;
  
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Name");
  if (iVar1 == 0) {
    d_kyeff::menu_vrbox_set();
  }
  else {
    d_kankyo_wether::dKyw_wether_move();
  }
  d_kankyo_wether::dKyw_wether_move_draw();
  return 1;
}


namespace d_kyeff {

/* __stdcall dKyeff_Execute(dKyeff_c *) */

void dKyeff_Execute(dKyeff_c *param_1)

{
  ::dKyeff_c::execute(param_1);
  return;
}


/* __stdcall dKyeff_IsDelete(dKyeff_c *) */

undefined4 dKyeff_IsDelete(void)

{
  return 1;
}


/* __stdcall dKyeff_Delete(dKyeff_c *) */

undefined4 dKyeff_Delete(void)

{
  d_kankyo_wether::dKyw_wether_delete();
  return 1;
}


/* __stdcall dKyeff_Create(kankyo_class *) */

undefined4 dKyeff_Create(void)

{
  int iVar1;
  char *pcVar2;
  OSCalendarTime OStack56;
  uint roomType;
  
  d_kankyo_wether::dKyw_wether_init();
  pcVar2 = "Name";
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Name");
  if (iVar1 == 0) {
    iVar1 = os::OSGetTime();
    os::OSTicksToCalendarTime(iVar1,(int32_t)pcVar2,&OStack56);
    d_kankyo::g_env_light.mWindVec.x = _4103;
    d_kankyo::g_env_light.mWindVec.y = _4102;
    d_kankyo::g_env_light.mWindVec.z = _4102;
    d_kankyo::g_env_light.mWindPower = _4155;
    d_kankyo::g_env_light.mCurTime =
         _4158 * (float)((double)CONCAT44(0x43300000,OStack56.hour ^ 0x80000000) - _4110);
  }
  else {
    iVar1 = d_kankyo::dKy_checkEventNightStop();
    if (iVar1 != 0) {
      iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                        (0x803c9d58);
      roomType = *(uint *)(iVar1 + 0xc) >> 0x10 & 7;
      if ((roomType == 0) || (roomType == 7)) {
        d_kankyo_wether::dKyw_rain_set(0xfa);
        d_kankyo::g_env_light.mThunderMode = 1;
      }
      else {
        if ((roomType == 2) &&
           ((((((iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                                   (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                    "Ocrogh"), iVar1 == 0 ||
                (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                                   (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                    "Omori"), iVar1 == 0)) ||
               (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                                  (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                   "Orichh"), iVar1 == 0)) ||
              ((iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                                  (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                   "Atorizk"), iVar1 == 0 ||
               (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                                  (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                   "LinkRM"), iVar1 == 0)))) ||
             ((iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                                 (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                  "Ojhous2"), iVar1 == 0 ||
              ((iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                                  (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                   "Onobuta"), iVar1 == 0 ||
               (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                                  (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                   "Omasao"), iVar1 == 0)))))) ||
            ((iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                                (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                 "Obombh"), iVar1 == 0 ||
             (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                                (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                 "Opub"), iVar1 == 0)))))) {
          d_kankyo_wether::dKyw_rain_set(0xfa);
          d_kankyo::g_env_light.mThunderMode = 10;
        }
      }
    }
  }
  return 4;
}

