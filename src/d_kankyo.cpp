#include <d_kankyo.h>
#include <d_stage.h>
#include <d_kankyo.h>
#include <mtx/vec.h>
#include <JAZelAudio/JAIZelAtmos.h>
#include <d_kankyo_data.h>
#include <d_a_bomb.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JKernel/JKRHeap.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_save.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <MSL_C.PPCEABI.bare.H/s_sin.h>
#include <MSL_C.PPCEABI.bare.H/s_cos.h>
#include <SComponent/c_math.h>
#include <SComponent/c_lib.h>
#include <SComponent/c_xyz.h>
#include <mtx/mtxvec.h>
#include <d_kankyo_wether.h>
#include <d_kankyo_rain.h>
#include <m_Do_mtx.h>
#include <gx/GXLight.h>
#include <m_Do_printf.h>
#include <gx/GXPixel.h>
#include <gf/GFPixel.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <m_Do_lib.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <d_letter.h>
#include <WIND_INF_ENTITY.h>
#include <LIGHT_INFLUENCE.h>
#include <dScnKy_env_light_c.h>
#include <J3DColorBlock.h>


namespace d_kankyo {
struct dScnKy_env_light_c g_env_light;
struct dKy_setLight__Status lightStatusData[8];
float target$6206;
undefined1 init$6207;
float target$6225;
byte init$6226;

/* __stdcall toon_proc_check(void) */

int toon_proc_check(void)

{
  dStage_roomStatus_c *pdVar1;
  
  if (-1 < (char)::dStage_roomControl_c::mStayNo) {
    pdVar1 = ::dStage_roomControl_c::getStatusRoomDt
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                        (int)(char)::dStage_roomControl_c::mStayNo);
    (*(code *)((pdVar1->parent).parent.vtbl)->getFileListInfo)();
  }
  return 0;
}


/* __stdcall u8_data_ratio_set(unsigned char,
                               unsigned char,
                               float) */

int u8_data_ratio_set(double param_1,uint param_2,uint param_3)

{
  return (int)(short)((short)(param_2 & 0xff) +
                     (short)(int)(param_1 *
                                 (double)(float)((double)CONCAT44(0x43300000,
                                                                  (param_3 & 0xff) -
                                                                  (param_2 & 0xff) ^ 0x80000000) -
                                                _4490)));
}


/* __stdcall s16_data_ratio_set(short,
                                short,
                                float) */

int s16_data_ratio_set(short param_1,short param_2,float param_3)

{
  return (int)(short)(param_1 +
                     (short)(int)(param_3 *
                                 (float)((double)CONCAT44(0x43300000,
                                                          (int)param_2 - (int)param_1 ^ 0x80000000)
                                        - _4490)));
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8018f9c0) */
/* WARNING: Removing unreachable block (ram,0x8018f9b8) */
/* WARNING: Removing unreachable block (ram,0x8018f9c8) */
/* __stdcall kankyo_color_ratio_set(unsigned char,
                                    unsigned char,
                                    float,
                                    unsigned char,
                                    unsigned char,
                                    float,
                                    short,
                                    float) */

int kankyo_color_ratio_set
              (byte b0A,byte b0B,float blendAB,byte b1A,uchar b1B,float blend01,short add,float mul)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)mul;
  dVar5 = (double)blend01;
  dVar4 = (double)blendAB;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  iVar1 = s16_data_ratio_set((ushort)b0A,(ushort)b0B,blendAB);
  iVar2 = s16_data_ratio_set((ushort)b1A,(ushort)b1B,(float)dVar4);
  iVar1 = s16_data_ratio_set((short)iVar1,(short)iVar2,(float)dVar5);
  iVar1 = (int)((float)((double)CONCAT44(0x43300000,(int)(short)((short)iVar1 + add) ^ 0x80000000) -
                       _4490) * (float)((double)g_env_light.mColors.mAllColRatio * dVar6));
  if ((short)iVar1 < 0) {
    iVar1 = 0;
  }
  if (0xff < (short)iVar1) {
    iVar1 = 0xff;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  return iVar1;
}


/* __stdcall fl_data_ratio_set(float,
                               float,
                               float) */

double fl_data_ratio_set(float param_1,float param_2,float param_3)

{
  return (double)(param_1 + param_3 * (param_2 - param_1));
}


/* WARNING: Removing unreachable block (ram,0x8018fac0) */
/* WARNING: Removing unreachable block (ram,0x8018fab0) */
/* WARNING: Removing unreachable block (ram,0x8018faa0) */
/* WARNING: Removing unreachable block (ram,0x8018fa98) */
/* WARNING: Removing unreachable block (ram,0x8018faa8) */
/* WARNING: Removing unreachable block (ram,0x8018fab8) */
/* WARNING: Removing unreachable block (ram,0x8018fac8) */
/* __stdcall float_kankyo_color_ratio_set(float,
                                          float,
                                          float,
                                          float,
                                          float,
                                          float,
                                          float,
                                          float) */

double float_kankyo_color_ratio_set
                 (double param_1,double param_2,double param_3,double param_4,double param_5,
                 double param_6,double param_7,double param_8)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f25;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  dVar2 = (double)fl_data_ratio_set((float)param_1,(float)param_2,(float)param_3);
  dVar3 = (double)fl_data_ratio_set((float)param_4,(float)param_5,(float)param_3);
  dVar2 = (double)fl_data_ratio_set((float)dVar2,(float)dVar3,(float)param_6);
  dVar2 = (double)(float)(dVar2 + (double)(float)(param_8 * (double)(float)(param_7 - dVar2)));
  if (dVar2 < (double)0_0) {
    dVar2 = (double)0_0;
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  __psq_l0(auStack40,uVar1);
  __psq_l1(auStack40,uVar1);
  __psq_l0(auStack56,uVar1);
  __psq_l1(auStack56,uVar1);
  __psq_l0(auStack72,uVar1);
  __psq_l1(auStack72,uVar1);
  __psq_l0(auStack88,uVar1);
  __psq_l1(auStack88,uVar1);
  __psq_l0(auStack104,uVar1);
  __psq_l1(auStack104,uVar1);
  return dVar2;
}


/* __stdcall get_parcent(float,
                         float,
                         float) */

double get_parcent(double param_1,double param_2,double param_3)

{
  double dVar1;
  
  if ((0_0 != (float)(param_1 - param_2)) &&
     (dVar1 = (double)(float)((double)1_0 -
                             (double)((float)(param_1 - param_3) / (float)(param_1 - param_2))),
     dVar1 < (double)1_0)) {
    return dVar1;
  }
  return (double)1_0;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x8018fcdc) */
/* __stdcall dKy_light_influence_id(cXyz,
                                    int) */

int dKy_light_influence_id(cXyz *param_1,int param_2)

{
  LIGHT_INFLUENCE *pInf;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  LIGHT_INFLUENCE **ppInf;
  int iVar6;
  undefined4 uVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  float fVar11;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar5 = -1;
  iVar3 = -1;
  iVar1 = 0;
  do {
    dVar10 = (double)_4589;
    if (param_2 < iVar1) {
      if (param_2 == 0) {
        iVar3 = iVar5;
      }
      __psq_l0(auStack8,uVar7);
      __psq_l1(auStack8,uVar7);
      return iVar3;
    }
    iVar2 = 0;
    iVar6 = 0;
    iVar4 = iVar3;
    do {
      ppInf = (LIGHT_INFLUENCE **)((int)g_env_light.mpPLights + iVar6);
      pInf = *(LIGHT_INFLUENCE **)((int)g_env_light.mpPLights + iVar6);
      iVar3 = iVar4;
      if ((pInf != (LIGHT_INFLUENCE *)0x0) &&
         (((iVar1 == 0 || (iVar2 != iVar5)) && (_4590 < pInf->mPower)))) {
        fVar11 = mtx::PSVECSquareDistance(param_1,&pInf->mPos);
        dVar9 = (double)fVar11;
        if ((double)0_0 < dVar9) {
          dVar8 = 1.0 / SQRT(dVar9);
          dVar8 = _4591 * dVar8 * (_4592 - dVar9 * dVar8 * dVar8);
          dVar8 = _4591 * dVar8 * (_4592 - dVar9 * dVar8 * dVar8);
          dVar9 = (double)(float)(dVar9 * _4591 * dVar8 * (_4592 - dVar9 * dVar8 * dVar8));
        }
        if (dVar9 < dVar10) {
          fVar11 = mtx::PSVECSquareDistance(param_1,&(*ppInf)->mPos);
          dVar10 = (double)fVar11;
          if ((double)0_0 < dVar10) {
            dVar9 = 1.0 / SQRT(dVar10);
            dVar9 = _4591 * dVar9 * (_4592 - dVar10 * dVar9 * dVar9);
            dVar9 = _4591 * dVar9 * (_4592 - dVar10 * dVar9 * dVar9);
            dVar10 = (double)(float)(dVar10 * _4591 * dVar9 * (_4592 - dVar10 * dVar9 * dVar9));
          }
          iVar3 = iVar2;
          if (iVar1 == 0) {
            iVar3 = iVar4;
            iVar5 = iVar2;
          }
        }
        if ((*ppInf)->mIdx < 0) {
          if (iVar1 == 0) {
            iVar5 = iVar2;
          }
          break;
        }
      }
      iVar2 = iVar2 + 1;
      iVar6 = iVar6 + 4;
      iVar4 = iVar3;
    } while (iVar2 < 200);
    iVar1 = iVar1 + 1;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x8018fea4) */
/* __stdcall dKy_eflight_influence_id(cXyz,
                                      int) */

int dKy_eflight_influence_id(cXyz *param_1,int param_2)

{
  cXyz *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  double dVar9;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  float fVar12;
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar6 = -1;
  iVar4 = -1;
  for (iVar2 = 0; dVar11 = (double)_4589, iVar2 <= param_2; iVar2 = iVar2 + 1) {
    iVar3 = 0;
    iVar7 = 0;
    iVar5 = iVar4;
    do {
      pcVar1 = *(cXyz **)((int)g_env_light.mpEfLights + iVar7);
      iVar4 = iVar5;
      if ((pcVar1 != (cXyz *)0x0) && ((iVar2 == 0 || (iVar3 != iVar6)))) {
        fVar12 = mtx::PSVECSquareDistance(param_1,pcVar1);
        dVar10 = (double)fVar12;
        if ((double)0_0 < dVar10) {
          dVar9 = 1.0 / SQRT(dVar10);
          dVar9 = _4591 * dVar9 * (_4592 - dVar10 * dVar9 * dVar9);
          dVar9 = _4591 * dVar9 * (_4592 - dVar10 * dVar9 * dVar9);
          dVar10 = (double)(float)(dVar10 * _4591 * dVar9 * (_4592 - dVar10 * dVar9 * dVar9));
        }
        if ((dVar10 < dVar11) &&
           (pcVar1 = *(cXyz **)((int)g_env_light.mpEfLights + iVar7), _4590 < pcVar1[1].z)) {
          fVar12 = mtx::PSVECSquareDistance(param_1,pcVar1);
          dVar11 = (double)fVar12;
          if ((double)0_0 < dVar11) {
            dVar10 = 1.0 / SQRT(dVar11);
            dVar10 = _4591 * dVar10 * (_4592 - dVar11 * dVar10 * dVar10);
            dVar10 = _4591 * dVar10 * (_4592 - dVar11 * dVar10 * dVar10);
            dVar11 = (double)(float)(dVar11 * _4591 * dVar10 * (_4592 - dVar11 * dVar10 * dVar10));
          }
          iVar4 = iVar3;
          if (iVar2 == 0) {
            iVar4 = iVar5;
            iVar6 = iVar3;
          }
        }
      }
      iVar3 = iVar3 + 1;
      iVar7 = iVar7 + 4;
      iVar5 = iVar4;
    } while (iVar3 < 10);
  }
  if (param_2 == 0) {
    iVar4 = iVar6;
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return iVar4;
}


/* __stdcall dKy_eflight_influence_pos(int) */

void dKy_eflight_influence_pos(float *param_1,int param_2)

{
  LIGHT_INFLUENCE *pLVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  pLVar1 = g_env_light.mpEfLights[param_2];
  *param_1 = (pLVar1->mPos).x;
  param_1[1] = (pLVar1->mPos).y;
  param_1[2] = (pLVar1->mPos).z;
  return;
}


/* __stdcall dKy_light_influence_col(int) */

_GXColorS10 dKy_light_influence_col(uint param_1)

{
  return g_env_light.mpPLights[param_1 & 0xffffffffU - ((int)param_1 >> 0x1f)]->mColor;
}


/* __stdcall dKy_light_influence_power(int) */

double dKy_light_influence_power(uint param_1)

{
  return (double)g_env_light.mpPLights[param_1 & 0xffffffffU - ((int)param_1 >> 0x1f)]->mPower;
}


/* __stdcall dKy_light_influence_yuragi(int) */

double dKy_light_influence_yuragi(uint param_1)

{
  return (double)g_env_light.mpPLights[param_1 & 0xffffffffU - ((int)param_1 >> 0x1f)]->mFluctuation
  ;
}


/* __stdcall dKy_light_influence_distance(cXyz,
                                          int) */

float dKy_light_influence_distance(cXyz *param_1,uint param_2)

{
  double dVar1;
  double dVar2;
  float fVar3;
  
  fVar3 = mtx::PSVECSquareDistance
                    (param_1,&g_env_light.mpPLights[param_2 & 0xffffffffU - ((int)param_2 >> 0x1f)]
                              ->mPos);
  dVar2 = (double)fVar3;
  if ((double)0_0 < dVar2) {
    dVar1 = 1.0 / SQRT(dVar2);
    dVar1 = _4591 * dVar1 * (_4592 - dVar2 * dVar1 * dVar1);
    dVar1 = _4591 * dVar1 * (_4592 - dVar2 * dVar1 * dVar1);
    dVar2 = (double)(float)(dVar2 * _4591 * dVar1 * (_4592 - dVar2 * dVar1 * dVar1));
  }
  return (float)dVar2;
}


/* __stdcall dKy_eflight_influence_col(int) */

_GXColorS10 dKy_eflight_influence_col(uint param_1)

{
  return g_env_light.mpEfLights[param_1 & 0xffffffffU - ((int)param_1 >> 0x1f)]->mColor;
}


/* __stdcall dKy_eflight_influence_power(int) */

double dKy_eflight_influence_power(uint param_1)

{
  return (double)g_env_light.mpEfLights[param_1 & 0xffffffffU - ((int)param_1 >> 0x1f)]->mPower;
}


/* __stdcall dKy_eflight_influence_yuragi(int) */

double dKy_eflight_influence_yuragi(uint param_1)

{
  return (double)g_env_light.mpEfLights[param_1 & 0xffffffffU - ((int)param_1 >> 0x1f)]->
                 mFluctuation;
}


/* __stdcall dKy_eflight_influence_distance(cXyz,
                                            int) */

double dKy_eflight_influence_distance(cXyz *param_1,uint param_2)

{
  double dVar1;
  double dVar2;
  float fVar3;
  
  fVar3 = mtx::PSVECSquareDistance
                    (param_1,&g_env_light.mpEfLights[param_2 & 0xffffffffU - ((int)param_2 >> 0x1f)]
                              ->mPos);
  dVar2 = (double)fVar3;
  if ((double)0_0 < dVar2) {
    dVar1 = 1.0 / SQRT(dVar2);
    dVar1 = _4591 * dVar1 * (_4592 - dVar2 * dVar1 * dVar1);
    dVar1 = _4591 * dVar1 * (_4592 - dVar2 * dVar1 * dVar1);
    dVar2 = (double)(float)(dVar2 * _4591 * dVar1 * (_4592 - dVar2 * dVar1 * dVar1));
  }
  return dVar2;
}


/* __stdcall plight_init(void) */

void plight_init(void)

{
  int iVar1;
  int iVar2;
  
  g_env_light.mLightInfluence[0].mPower = _4758;
  iVar1 = 0;
  iVar2 = 200;
  do {
    *(undefined4 *)((int)g_env_light.mpPLights + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = 0;
  iVar2 = 10;
  do {
    *(undefined4 *)((int)g_env_light.mpEfLights + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = 0;
  iVar2 = 10;
  do {
    *(undefined4 *)((int)&g_env_light.mpWaveInfl + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  g_env_light.mPlayerPLightIdx = -1;
  g_env_light.mPlayerEflightIdx = -1;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall plight_set(void) */

void plight_set(void)

{
  stage_plight_info_class *pPlight;
  int iVar1;
  stage_plight_info_class__Light *pLght;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar4 = 0;
  pPlight = (stage_plight_info_class *)
            (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getPlightInfo)
                      (0x803c9d58);
  if (pPlight != (stage_plight_info_class *)0x0) {
    iVar3 = 0;
    g_env_light.mpPlightInfo = pPlight;
    for (iVar2 = 0;
        iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                          getPlightNumInfo)(0x803c9d58), iVar2 < iVar1; iVar2 = iVar2 + 1) {
      if (iVar5 < 0x1e) {
        pLght = (stage_plight_info_class__Light *)((int)&pPlight->pLight + iVar3);
        *(float *)((int)&g_env_light.mLightInfluence[0].mPos.x + iVar4) = (pLght->mPos).x;
        *(float *)((int)&g_env_light.mLightInfluence[0].mPos.y + iVar4) = (pLght->mPos).y;
        *(float *)((int)&g_env_light.mLightInfluence[0].mPos.z + iVar4) = (pLght->mPos).z;
        *(ushort *)((int)&g_env_light.mLightInfluence[0].mColor.r + iVar4) = (ushort)pLght->mColorR;
        *(ushort *)((int)&g_env_light.mLightInfluence[0].mColor.g + iVar4) = (ushort)pLght->mColorG;
        *(ushort *)((int)&g_env_light.mLightInfluence[0].mColor.b + iVar4) = (ushort)pLght->mColorB;
        *(float *)((int)&g_env_light.mLightInfluence[0].mPower + iVar4) = 200_0 * pLght->mRadius;
        *(float *)((int)&g_env_light.mLightInfluence[0].mFluctuation + iVar4) =
             (float)((double)CONCAT44(0x43300000,(uint)pLght->mFluctuation) - _4781);
        dKy_plight_set((LIGHT_INFLUENCE *)((int)&g_env_light.mLightInfluence[0].mPos.x + iVar4));
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x20;
      }
      iVar3 = iVar3 + 0x1c;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall envcolor_init(void) */

void envcolor_init(void)

{
  float fVar1;
  uint uVar2;
  stage_palet_info_class *pPalet;
  stage_pselect_info_class *pPselect;
  stage_envr_info_class *pEnvr;
  stage_vrbox_info_class *pVrbox;
  int iVar3;
  stage_stag_info_class *pStag;
  stage_envr_info_class *psVar4;
  stage_palet_info_class *psVar5;
  stage_pselect_info_class *psVar6;
  stage_vrbox_info_class *psVar7;
  int iVar8;
  
  pPalet = (stage_palet_info_class *)
           (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getPaletInfo)
                     (0x803c9d58);
  pPselect = (stage_pselect_info_class *)
             (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getPselectInfo)
                       (0x803c9d58);
  pEnvr = (stage_envr_info_class *)
          (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getEnvrInfo)
                    (0x803c9d58);
  pVrbox = (stage_vrbox_info_class *)
           (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getVrboxInfo)
                     (0x803c9d58);
  fVar1 = 0_0;
  iVar3 = 0;
  iVar8 = 0x14;
  do {
    *(float *)((int)d_s_play::g_regHIO.mChild[3].mFloats + iVar3) = fVar1;
    iVar3 = iVar3 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar3 = 0;
  iVar8 = 10;
  do {
    *(undefined2 *)((int)d_s_play::g_regHIO.mChild[3].mShorts + iVar3) = 0;
    iVar3 = iVar3 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  JAIZelBasic::initWindowPos(JAIZelBasic::zel_basic);
  JAIZelBasic::initSeaEnvPos(JAIZelBasic::zel_basic);
  JAIZelBasic::initRiverPos(JAIZelBasic::zel_basic);
  dKy_actor_addcol_set(0,0,0,0_0);
  dKy_fog_startendz_set(0_0,0_0,0_0);
  dKy_vrbox_addcol_set(0,0,0,0_0);
  g_env_light.field_0xc48 = (undefined *)0x0;
  g_env_light.mInitAnimTimer = 1;
  g_env_light.mSchbit = 0;
  g_env_light.mSchbitTimer = 0;
  g_env_light.mbVrboxInvisible = 0;
  g_env_light.mbContrastFlag = 0;
  g_env_light.mFogAdjEnable = 1;
  g_env_light.mFogAdjTableType = 0;
  g_env_light.mFogAdjCenter = 0x140;
  d_kankyo_data::dKyd_xfog_table_set(0);
  g_env_light.mColors.mAllColRatio = 1_0;
  g_env_light.mColors.mActColRatio = 1_0;
  g_env_light.mColors.mBgColRatio = 1_0;
  g_env_light.mColors.mFogColRatio = 1_0;
  g_env_light.mColors.mVrboxSoraColRatio = 1_0;
  g_env_light.mColors.mVrboxKumoColRatio = 1_0;
  g_env_light.mColorsGather.mAllColRatio = 1_0;
  g_env_light.mColorsGather.mActColRatio = 1_0;
  g_env_light.mColorsGather.mBgColRatio = 1_0;
  g_env_light.mColorsGather.mFogColRatio = 1_0;
  g_env_light.mColorsGather.mVrboxSoraColRatio = 1_0;
  g_env_light.mColorsGather.mVrboxKumoColRatio = 1_0;
  g_env_light.field_0xc93 = 0;
  g_env_light.field_0xc34 = 0_0;
  g_env_light.field_0xc2c = 0_0;
  g_env_light.field_0xc30 = 0_0;
  g_env_light.field_0xc98 = 0;
  g_env_light.mbDayNightTactStop = 0;
  pStag = (stage_stag_info_class *)
          (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  if ((pStag->mStageTypeAndSchbit >> 0x10 & 7) == 3) {
    g_env_light.mpSchejule = (dScnKy__Schedule *)d_kankyo_data::dKyd_schejule_boss_getp();
  }
  else {
    g_env_light.mpSchejule = (dScnKy__Schedule *)d_kankyo_data::dKyd_schejule_getp();
  }
  g_env_light.mEnvrIdxPrev = 0;
  g_env_light.mEnvrIdxCurr = 0;
  g_env_light.mColPatBlend = 1_0;
  g_env_light.field_0xc78 = (undefined *)0x0;
  iVar3 = dKy_checkEventNightStop();
  if (iVar3 == 0) {
    g_env_light.mVrkumoStrength = 0_0;
  }
  else {
    g_env_light.mVrkumoStrength = 1_0;
  }
  g_env_light.mColpatWeather = iVar3 != 0;
  g_env_light.mRainCountOrig = 0;
  g_env_light.field_0xc68 = (undefined *)0x0;
  g_env_light.mDiceWeatherMode = 0;
  g_env_light.mDiceWeatherChangeTime =
       _4875 + d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime;
  if (360_0 <= g_env_light.mDiceWeatherChangeTime) {
    g_env_light.mDiceWeatherChangeTime = g_env_light.mDiceWeatherChangeTime - 360_0;
  }
  g_env_light.mDiceWeatherState = 0;
  g_env_light.mDiceWeatherCurrPattern = 0;
  g_env_light.mDiceWeatherCounter = 0;
  g_env_light.mDiceWeatherTime = 0_0;
  g_env_light.field_0xc8e = 0;
  g_env_light.mColpatPrev = g_env_light.mColpatWeather;
  g_env_light.mColpatCurr = g_env_light.mColpatWeather;
  g_env_light.mColpatPrevGather = 0xff;
  g_env_light.mColpatCurrGather = 0xff;
  g_env_light.mColPatBlendGather = _1_0;
  g_env_light.mColPatMode = 0;
  g_env_light.mColPatModeGather = 0;
  psVar4 = pEnvr;
  if (pEnvr == (stage_envr_info_class *)0x0) {
    psVar4 = d_kankyo_data::dKyd_dmenvr_getp();
  }
  g_env_light.mpEnvrInfo = psVar4;
  psVar5 = pPalet;
  if (pPalet == (stage_palet_info_class *)0x0) {
    psVar5 = d_kankyo_data::dKyd_dmpalet_getp();
  }
  g_env_light.mpPaletInfo = psVar5;
  psVar6 = pPselect;
  if (pPselect == (stage_pselect_info_class *)0x0) {
    psVar6 = d_kankyo_data::dKyd_dmpselect_getp();
  }
  g_env_light.mpPselectInfo = psVar6;
  psVar7 = pVrbox;
  if (pVrbox == (stage_vrbox_info_class *)0x0) {
    psVar7 = d_kankyo_data::dKyd_dmvrbox_getp();
  }
  g_env_light.mpVrboxInfo = psVar7;
  plight_init();
  plight_set();
  if (_1_0 != g_env_light.mNextTime) {
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime =
         g_env_light.mNextTime;
    g_env_light.mNextTime = _1_0;
  }
  iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  uVar2 = SEXT14((char)((uint)*(undefined4 *)(iVar3 + 0xc) >> 8));
  if (-1 < (int)uVar2) {
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime =
         15_0 * (float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - _4490);
  }
  g_env_light.mTimeAdv = 0_02;
  iVar3 = dKy_checkEventNightStop();
  if (iVar3 != 0) {
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime = 0_0;
  }
  FUN_800033a8(-0x7fc1a8fc,0,0x10);
  return;
}

}

/* __thiscall dScnKy_env_light_c::dScnKy_env_light_c(void) */

void __thiscall dScnKy_env_light_c::dScnKy_env_light_c(dScnKy_env_light_c *this)

{
  float fVar1;
  float fVar2;
  
  this->mRoomCtrl = (dStage_roomControl_c)&__vt;
  Runtime.PPCEABI.H::__construct_array
            (this->mLightInfluence,LIGHT_INFLUENCE::LIGHT_INFLUENCE,
             LIGHT_INFLUENCE::_LIGHT_INFLUENCE,0x20,0x1e);
  Runtime.PPCEABI.H::__construct_array
            (this->mWindInfluenceEntity,WIND_INF_ENTITY::WIND_INF_ENTITY,
             WIND_INF_ENTITY::_WIND_INF_ENTITY,0x3c,5);
  d_kankyo::dKy_actor_addcol_set(0,0,0,d_kankyo::0_0);
  (this->mSunPos).x = d_kankyo::1_0;
  fVar1 = d_kankyo::0_0;
  (this->mSunPos).y = d_kankyo::0_0;
  (this->mSunPos).z = fVar1;
  fVar2 = d_kankyo::_1_0;
  (this->mMoonPos).x = d_kankyo::_1_0;
  (this->mMoonPos).y = fVar1;
  (this->mMoonPos).z = fVar1;
  this->mNextTime = fVar2;
  return;
}


/* __thiscall WIND_INF_ENTITY::~WIND_INF_ENTITY(void) */

void __thiscall WIND_INF_ENTITY::_WIND_INF_ENTITY(WIND_INF_ENTITY *this)

{
  short in_r4;
  
  if ((this != (WIND_INF_ENTITY *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall WIND_INF_ENTITY::WIND_INF_ENTITY(void) */

void __thiscall WIND_INF_ENTITY::WIND_INF_ENTITY(WIND_INF_ENTITY *this)

{
  return;
}


/* __thiscall LIGHT_INFLUENCE::LIGHT_INFLUENCE(void) */

void __thiscall LIGHT_INFLUENCE::LIGHT_INFLUENCE(LIGHT_INFLUENCE *this)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dScnKy_env_light_c::setDaytime(void) */

void __thiscall dScnKy_env_light_c::setDaytime(dScnKy_env_light_c *this)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  bool bVar5;
  byte bVar6;
  
  bVar5 = false;
  this->mCurTime = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime;
  this->mDayOfWeek = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mDayOfWeek;
  iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea");
  if ((iVar2 == 0) && (dStage_roomControl_c::mStayNo == 0xe)) {
    if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mLayerNo == 2) ||
       (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mLayerNo == 3)) {
      bVar5 = true;
    }
  }
  iVar2 = d_kankyo::dKy_checkEventNightStop();
  if ((((iVar2 == 0) &&
       (uVar3 = dSv_player_get_item_c::isItem
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,2,0),
       uVar3 != 0)) && (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0)) && (!bVar5))
  {
    uVar3 = dStage_roomControl_c::GetTimePass();
    if (uVar3 == 0) {
      bVar5 = d_kankyo::dKy_daynight_check();
      if (bVar5 == false) {
        if (this->mCurTime < d_kankyo::165_0) {
          this->mCurTime = this->mCurTime + this->mTimeAdv;
        }
      }
      else {
        fVar1 = this->mCurTime;
        if ((d_kankyo::270_0 <= fVar1) && (fVar1 < d_kankyo::345_0)) {
          this->mCurTime = fVar1 + this->mTimeAdv;
        }
      }
    }
    else {
      this->mCurTime = this->mCurTime + this->mTimeAdv;
      uVar4 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)this->mCurTime);
      if (d_kankyo::360_0 <= (float)((double)CONCAT44(0x43300000,uVar4) - d_kankyo::_4781)) {
        this->mCurTime = d_kankyo::0_0;
        this->mDayOfWeek = this->mDayOfWeek + 1;
        d_kankyo::dKankyo_DayProc();
      }
    }
  }
  bVar6 = d_kankyo::dKy_getdaytime_hour();
  JAIZelBasic::zel_basic->field_0x2c = bVar6;
  bVar6 = d_kankyo::dKy_getdaytime_minute();
  JAIZelBasic::zel_basic->field_0x2d = bVar6;
  bVar6 = d_kankyo::dKy_get_dayofweek();
  JAIZelBasic::zel_basic->field_0x2e = bVar6;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime = this->mCurTime;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mDayOfWeek = this->mDayOfWeek;
  return;
}


namespace dStage_roomControl_c {

/* __thiscall GetTimePass(void) */

uint GetTimePass(void)

{
  return (uint)m_time_pass;
}

}

/* __thiscall dScnKy_env_light_c::SetSchbit(void) */

void __thiscall dScnKy_env_light_c::SetSchbit(dScnKy_env_light_c *this)

{
  uint uVar1;
  stage_stag_info_class *pStag;
  
                    /* Parameterized scheduling system. Every frame, mSchbitTimer ticks, and if it's
                       over some threshold, as defined by STAG +0x0C & 0x00, then the schedule bit
                       advances one to the right. It resets once it has made eight ticks.
                       
                       This system can be disabled with another field in STAG. */
  pStag = (stage_stag_info_class *)
          (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  uVar1 = pStag->mStageTypeAndSchbit;
  if ((pStag->mSchbitEnableAndFarPlane >> 0x10 & 0xff) != 0) {
    if (this->mSchbit == 0) {
      this->mSchbit = 0x80;
    }
    this->mSchbitTimer = this->mSchbitTimer + 1;
    if ((int)((uVar1 & 0xff) * 0x1e) <= this->mSchbitTimer) {
      this->mSchbitTimer = 0;
      this->mSchbit = (byte)((int)(uint)this->mSchbit >> 1);
      if (this->mSchbit == 0) {
        this->mSchbit = 0x80;
      }
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x80190bec) */
/* __thiscall dScnKy_env_light_c::setSunpos(void) */

void __thiscall dScnKy_env_light_c::setSunpos(dScnKy_env_light_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  camera_class *pcVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f31;
  double theta;
  undefined auStack8 [8];
  
  pcVar4 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_kankyo::g_env_light.mCurTime <= d_kankyo::15_0) {
    fVar1 = d_kankyo::345_0 + d_kankyo::g_env_light.mCurTime;
  }
  else {
    fVar1 = d_kankyo::g_env_light.mCurTime - d_kankyo::15_0;
  }
  theta = (double)(d_kankyo::_5099 * fVar1);
  dVar6 = MSL_C.PPCEABI.bare.H::sin(theta);
  fVar1 = d_kankyo::80000_0 * (float)dVar6;
  dVar6 = MSL_C.PPCEABI.bare.H::cos(theta);
  fVar2 = d_kankyo::80000_0 * (float)dVar6;
  dVar6 = MSL_C.PPCEABI.bare.H::cos(theta);
  fVar3 = d_kankyo::_48000_0 * (float)dVar6;
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) ||
     (d_kankyo::g_env_light.mInitAnimTimer != 0)) {
    (this->mSunPos).x = (pcVar4->mEyePos).x + fVar1;
    (this->mSunPos).y = (pcVar4->mEyePos).y - fVar2;
    (this->mSunPos).z = (pcVar4->mEyePos).z + fVar3;
    (this->mMoonPos).x = (pcVar4->mEyePos).x - fVar1;
    (this->mMoonPos).y = (pcVar4->mEyePos).y + fVar2;
    (this->mMoonPos).z = (pcVar4->mEyePos).z - fVar3;
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* __thiscall dScnKy_env_light_c::getDaytime(void) */

double __thiscall dScnKy_env_light_c::getDaytime(dScnKy_env_light_c *this)

{
  return (double)this->mCurTime;
}


namespace d_kankyo {

/* __stdcall dKy_getdaytime_hour(void) */

int dKy_getdaytime_hour(void)

{
  return (int)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime / 15_0);
}


/* __stdcall dKy_getdaytime_minute(void) */

int dKy_getdaytime_minute(void)

{
  return (int)(_5131 * (((float)((double)CONCAT44(0x43300000,
                                                  (int)(_4589 * d_com_inf_game::g_dComIfG_gameInfo.
                                                                mSvInfo.mSave.mPlayer.mStatusB.
                                                                mCurTime) % 15000000 ^ 0x80000000) -
                                _4490) / _4589) / 15_0));
}


/* __stdcall dKy_daynight_check(void) */

bool dKy_daynight_check(void)

{
  int currTime;
  bool isNight;
  
  currTime = dKy_getdaytime_hour();
  if ((currTime < 6) || (0x11 < currTime)) {
    isNight = true;
  }
  else {
    isNight = false;
  }
  return isNight;
}

}

/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* __thiscall dScnKy_env_light_c::setLight_palno_get(unsigned char *,
                                                     unsigned char *,
                                                     unsigned char *,
                                                     unsigned char *,
                                                     unsigned char *,
                                                     unsigned char *,
                                                     unsigned char *,
                                                     unsigned char *,
                                                     float *,
                                                     int *,
                                                     int *,
                                                     float *,
                                                     unsigned char *) */

void __thiscall
dScnKy_env_light_c::setLight_palno_get
          (dScnKy_env_light_c *this,byte *pEnvrSel0,byte *pEnvrSel1,byte *pPselIdx0,byte *pPselIdx1,
          byte *pPalIdx0A,byte *pPalIdx0B,byte *pPalIdx1A,byte *pPalIdx1B,float *pBlendPalAB,
          int *pPselPalIdx0,int *pPselPalIdx1,float *pBlendPal01,byte *pInitTimer)

{
  float fVar1;
  int iVar2;
  dScnKy__Schedule *pSchejule;
  stage_envr_info_class *pEnvr;
  stage_pselect_info_class *pPsel;
  int iVar3;
  double dVar4;
  
                    /* This appears to be some animation timer? I don't exactly know what's going on
                       here... */
  if (*pInitTimer != 0) {
    *pInitTimer = *pInitTimer + 1;
    if (0x14 < *pInitTimer) {
      *pInitTimer = 0;
    }
    if (((d_kankyo::g_env_light.mColPatMode == 0) && (d_kankyo::g_env_light.mColPatModeGather == 0))
       && (*pBlendPal01 = d_kankyo::g_env_light.mColPatBlend, d_kankyo::1_0 <= *pBlendPal01)) {
      *pEnvrSel0 = *pEnvrSel1;
      *pPselIdx0 = *pPselIdx1;
    }
  }
  iVar2 = 0;
  iVar3 = 0xb;
  while( true ) {
    pSchejule = (dScnKy__Schedule *)((int)&this->mpSchejule->mTimeEnd + iVar2);
    if ((pSchejule->mTimeEnd <= this->mCurTime) && (this->mCurTime <= pSchejule->mTimeBegin)) break;
    iVar2 = iVar2 + 0xc;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return;
    }
  }
                    /* Which of the psel pal entries to use */
  *pPselPalIdx0 = (uint)pSchejule->mPalIdx0;
  *pPselPalIdx1 = (uint)(&this->mpSchejule->mPalIdx1)[iVar2];
  dVar4 = (double)d_kankyo::get_parcent
                            ((double)*(float *)((int)&this->mpSchejule->mTimeBegin + iVar2),
                             (double)*(float *)((int)&this->mpSchejule->mTimeEnd + iVar2),
                             (double)this->mCurTime);
                    /* Blend between the two palettes */
  *pBlendPalAB = (float)dVar4;
                    /* pEnvrSel is RoomNo, likely */
  pEnvr = d_kankyo::g_env_light.mpEnvrInfo + *pEnvrSel0;
                    /* pPselIdx is weather state, likely? */
  switch(*pPselIdx0) {
  case 0:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[0];
    break;
  case 1:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[1];
    break;
  case 2:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[2];
    break;
  case 3:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[3];
    break;
  case 4:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[4];
    break;
  case 5:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[5];
    break;
  case 6:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[6];
    break;
  case 7:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[7];
  }
  iVar2 = *pPselPalIdx0;
  if (iVar2 == 3) {
    *pPalIdx0A = pPsel->mPalIdx[3];
  }
  else {
    if (iVar2 < 3) {
      if (iVar2 == 1) {
        *pPalIdx0A = pPsel->mPalIdx[1];
      }
      else {
        if (iVar2 < 1) {
          if (-1 < iVar2) {
            *pPalIdx0A = pPsel->mPalIdx[0];
          }
        }
        else {
          *pPalIdx0A = pPsel->mPalIdx[2];
        }
      }
    }
    else {
      if (iVar2 == 5) {
        *pPalIdx0A = pPsel->mPalIdx[5];
      }
      else {
        if (iVar2 < 5) {
          *pPalIdx0A = pPsel->mPalIdx[4];
        }
      }
    }
  }
  iVar2 = *pPselPalIdx1;
  if (iVar2 == 3) {
    *pPalIdx0B = pPsel->mPalIdx[3];
  }
  else {
    if (iVar2 < 3) {
      if (iVar2 == 1) {
        *pPalIdx0B = pPsel->mPalIdx[1];
      }
      else {
        if (iVar2 < 1) {
          if (-1 < iVar2) {
            *pPalIdx0B = pPsel->mPalIdx[0];
          }
        }
        else {
          *pPalIdx0B = pPsel->mPalIdx[2];
        }
      }
    }
    else {
      if (iVar2 == 5) {
        *pPalIdx0B = pPsel->mPalIdx[5];
      }
      else {
        if (iVar2 < 5) {
          *pPalIdx0B = pPsel->mPalIdx[4];
        }
      }
    }
  }
  pEnvr = d_kankyo::g_env_light.mpEnvrInfo + *pEnvrSel1;
  switch(*pPselIdx1) {
  case 0:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[0];
    break;
  case 1:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[1];
    break;
  case 2:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[2];
    break;
  case 3:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[3];
    break;
  case 4:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[4];
    break;
  case 5:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[5];
    break;
  case 6:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[6];
    break;
  case 7:
    pPsel = d_kankyo::g_env_light.mpPselectInfo + pEnvr->mPselIdx[7];
  }
  if (((uint)*pEnvrSel0 != (uint)*pEnvrSel1) || (*pPselIdx0 != *pPselIdx1)) {
    if (pPsel->mChangeRate < d_kankyo::_5241) {
      pPsel->mChangeRate = d_kankyo::_5241;
    }
    if (d_kankyo::g_env_light.mColPatMode == 0) {
      iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea");
      if ((iVar2 == 0) && (*pPselIdx0 != *pPselIdx1)) {
        *pBlendPal01 = *pBlendPal01 + d_kankyo::_5242;
      }
      else {
        if (d_kankyo::0_0 < pPsel->mChangeRate) {
          *pBlendPal01 = *pBlendPal01 + d_kankyo::_5241 / pPsel->mChangeRate;
        }
      }
      fVar1 = d_kankyo::1_0;
      if (d_kankyo::1_0 <= *pBlendPal01) {
        *pEnvrSel0 = *pEnvrSel1;
        *pPselIdx0 = *pPselIdx1;
        *pBlendPal01 = fVar1;
      }
    }
  }
  iVar2 = *pPselPalIdx0;
  if (iVar2 == 3) {
    *pPalIdx1A = pPsel->mPalIdx[3];
  }
  else {
    if (iVar2 < 3) {
      if (iVar2 == 1) {
        *pPalIdx1A = pPsel->mPalIdx[1];
      }
      else {
        if (iVar2 < 1) {
          if (-1 < iVar2) {
            *pPalIdx1A = pPsel->mPalIdx[0];
          }
        }
        else {
          *pPalIdx1A = pPsel->mPalIdx[2];
        }
      }
    }
    else {
      if (iVar2 == 5) {
        *pPalIdx1A = pPsel->mPalIdx[5];
      }
      else {
        if (iVar2 < 5) {
          *pPalIdx1A = pPsel->mPalIdx[4];
        }
      }
    }
  }
  iVar2 = *pPselPalIdx1;
  if (iVar2 == 3) {
    *pPalIdx1B = pPsel->mPalIdx[3];
    return;
  }
  if (2 < iVar2) {
    if (iVar2 == 5) {
      *pPalIdx1B = pPsel->mPalIdx[5];
      return;
    }
    if (4 < iVar2) {
      return;
    }
    *pPalIdx1B = pPsel->mPalIdx[4];
    return;
  }
  if (iVar2 == 1) {
    *pPalIdx1B = pPsel->mPalIdx[1];
    return;
  }
  if (iVar2 < 1) {
    if (iVar2 < 0) {
      return;
    }
    *pPalIdx1B = pPsel->mPalIdx[0];
    return;
  }
  *pPalIdx1B = pPsel->mPalIdx[2];
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dScnKy_env_light_c::setLight(void) */

void __thiscall dScnKy_env_light_c::setLight(dScnKy_env_light_c *this)

{
  int iVar1;
  stage_vrbox_info_class *psVar2;
  stage_palet_info_class *pPale3;
  stage_palet_info_class *pPale2;
  stage_vrbox_info_class *psVar3;
  stage_palet_info_class *pPale1;
  stage_vrbox_info_class *psVar4;
  stage_palet_info_class *pPale0;
  stage_vrbox_info_class *psVar5;
  double dVar6;
  byte pale3;
  byte pale1;
  byte pale2;
  byte pale0;
  int iStack44;
  int iStack40;
  float local_24;
  
  setLight_palno_get(this,&d_kankyo::g_env_light.mEnvrIdxPrev,&d_kankyo::g_env_light.mEnvrIdxCurr,
                     &d_kankyo::g_env_light.mColpatPrev,&d_kankyo::g_env_light.mColpatCurr,&pale0,
                     &pale1,&pale2,&pale3,&local_24,&iStack40,&iStack44,
                     &d_kankyo::g_env_light.mColPatBlend,&d_kankyo::g_env_light.mInitAnimTimer);
  pPale0 = d_kankyo::g_env_light.mpPaletInfo + pale0;
  pPale1 = d_kankyo::g_env_light.mpPaletInfo + pale1;
  pPale2 = d_kankyo::g_env_light.mpPaletInfo + pale2;
  pPale3 = d_kankyo::g_env_light.mpPaletInfo + pale3;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mActor_C0[0],pPale1->mActor_C0[0],local_24,pPale2->mActor_C0[0],
                     pPale3->mActor_C0[0],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mActColRatio *
                     d_kankyo::g_env_light.mColors.mActColRatio);
  (this->mActorC0).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mActor_C0[1],pPale1->mActor_C0[1],local_24,pPale2->mActor_C0[1],
                     pPale3->mActor_C0[1],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mActColRatio *
                     d_kankyo::g_env_light.mColors.mActColRatio);
  (this->mActorC0).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mActor_C0[2],pPale1->mActor_C0[2],local_24,pPale2->mActor_C0[2],
                     pPale3->mActor_C0[2],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mActColRatio *
                     d_kankyo::g_env_light.mColors.mActColRatio);
  (this->mActorC0).b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mActor_K0[0],pPale1->mActor_K0[0],local_24,pPale2->mActor_K0[0],
                     pPale3->mActor_K0[0],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mActColRatio);
  (this->mActorK0).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mActor_K0[1],pPale1->mActor_K0[1],local_24,pPale2->mActor_K0[1],
                     pPale3->mActor_K0[1],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mActColRatio);
  (this->mActorK0).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mActor_K0[2],pPale1->mActor_K0[2],local_24,pPale2->mActor_K0[2],
                     pPale3->mActor_K0[2],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mActColRatio);
  (this->mActorK0).b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG0_C0[0],pPale1->mBG0_C0[0],local_24,pPale2->mBG0_C0[0],
                     pPale3->mBG0_C0[0],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG0_C0).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG0_C0[1],pPale1->mBG0_C0[1],local_24,pPale2->mBG0_C0[1],
                     pPale3->mBG0_C0[1],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG0_C0).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG0_C0[2],pPale1->mBG0_C0[2],local_24,pPale2->mBG0_C0[2],
                     pPale3->mBG0_C0[2],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG0_C0).b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG0_K0[0],pPale1->mBG0_K0[0],local_24,pPale2->mBG0_K0[0],
                     pPale3->mBG0_K0[0],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG0_K0).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG0_K0[1],pPale1->mBG0_K0[1],local_24,pPale2->mBG0_K0[1],
                     pPale3->mBG0_K0[1],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG0_K0).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG0_K0[2],pPale1->mBG0_K0[2],local_24,pPale2->mBG0_K0[2],
                     pPale3->mBG0_K0[2],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG0_K0).b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG1_C0[0],pPale1->mBG1_C0[0],local_24,pPale2->mBG1_C0[0],
                     pPale3->mBG1_C0[0],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG1_C0).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG1_C0[1],pPale1->mBG1_C0[1],local_24,pPale2->mBG1_C0[1],
                     pPale3->mBG1_C0[1],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG1_C0).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG1_C0[2],pPale1->mBG1_C0[2],local_24,pPale2->mBG1_C0[2],
                     pPale3->mBG1_C0[2],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG1_C0).b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG1_K0[0],pPale1->mBG1_K0[0],local_24,pPale2->mBG1_K0[0],
                     pPale3->mBG1_K0[0],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG1_K0).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG1_K0[1],pPale1->mBG1_K0[1],local_24,pPale2->mBG1_K0[1],
                     pPale3->mBG1_K0[1],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG1_K0).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG1_K0[2],pPale1->mBG1_K0[2],local_24,pPale2->mBG1_K0[2],
                     pPale3->mBG1_K0[2],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG1_K0).b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG2_C0[0],pPale1->mBG2_C0[0],local_24,pPale2->mBG2_C0[0],
                     pPale3->mBG2_C0[0],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG2_C0).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG2_C0[1],pPale1->mBG2_C0[1],local_24,pPale2->mBG2_C0[1],
                     pPale3->mBG2_C0[1],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG2_C0).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG2_C0[2],pPale1->mBG2_C0[2],local_24,pPale2->mBG2_C0[2],
                     pPale3->mBG2_C0[2],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG2_C0).b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG2_K0[0],pPale1->mBG2_K0[0],local_24,pPale2->mBG2_K0[0],
                     pPale3->mBG2_K0[0],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG2_K0).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG2_K0[1],pPale1->mBG2_K0[1],local_24,pPale2->mBG2_K0[1],
                     pPale3->mBG2_K0[1],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG2_K0).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG2_K0[2],pPale1->mBG2_K0[2],local_24,pPale2->mBG2_K0[2],
                     pPale3->mBG2_K0[2],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG2_K0).b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG3_C0[0],pPale1->mBG3_C0[0],local_24,pPale2->mBG3_C0[0],
                     pPale3->mBG3_C0[0],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG3_C0).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG3_C0[1],pPale1->mBG3_C0[1],local_24,pPale2->mBG3_C0[1],
                     pPale3->mBG3_C0[1],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG3_C0).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG3_C0[2],pPale1->mBG3_C0[2],local_24,pPale2->mBG3_C0[2],
                     pPale3->mBG3_C0[2],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG3_C0).b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG3_K0[0],pPale1->mBG3_K0[0],local_24,pPale2->mBG3_K0[0],
                     pPale3->mBG3_K0[0],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG3_K0).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG3_K0[1],pPale1->mBG3_K0[1],local_24,pPale2->mBG3_K0[1],
                     pPale3->mBG3_K0[1],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG3_K0).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mBG3_K0[2],pPale1->mBG3_K0[2],local_24,pPale2->mBG3_K0[2],
                     pPale3->mBG3_K0[2],d_kankyo::g_env_light.mColPatBlend,0,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  (this->mBG3_K0).b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mFog[0],pPale1->mFog[0],local_24,pPale2->mFog[0],pPale3->mFog[0],
                     d_kankyo::g_env_light.mColPatBlend,(this->mAddColFog).r,
                     d_kankyo::g_env_light.mColors.mFogColRatio);
  (this->mFogColor).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mFog[1],pPale1->mFog[1],local_24,pPale2->mFog[1],pPale3->mFog[1],
                     d_kankyo::g_env_light.mColPatBlend,(this->mAddColFog).g,
                     d_kankyo::g_env_light.mColors.mFogColRatio);
  (this->mFogColor).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPale0->mFog[2],pPale1->mFog[2],local_24,pPale2->mFog[2],pPale3->mFog[2],
                     d_kankyo::g_env_light.mColPatBlend,(this->mAddColFog).b,
                     d_kankyo::g_env_light.mColors.mFogColRatio);
  (this->mFogColor).b = (s16)iVar1;
  dVar6 = (double)d_kankyo::float_kankyo_color_ratio_set
                            ((double)pPale0->mFogStartZ,(double)pPale1->mFogStartZ,(double)local_24,
                             (double)pPale2->mFogStartZ,(double)pPale3->mFogStartZ,
                             (double)d_kankyo::g_env_light.mColPatBlend,
                             (double)d_kankyo::g_env_light.mFogStartZ,
                             (double)d_kankyo::g_env_light.mFogRatio);
  this->mFogStartZ__setLight = (float)dVar6;
  dVar6 = (double)d_kankyo::float_kankyo_color_ratio_set
                            ((double)pPale0->mFogEndZ,(double)pPale1->mFogEndZ,(double)local_24,
                             (double)pPale2->mFogEndZ,(double)pPale3->mFogEndZ,
                             (double)d_kankyo::g_env_light.mColPatBlend,
                             (double)d_kankyo::g_env_light.mFogEndZ,
                             (double)d_kankyo::g_env_light.mFogRatio);
  this->mFogEndZ__setLight = (float)dVar6;
  if (this->mFogEndZ__setLight < this->mFogStartZ__setLight) {
    this->mFogStartZ__setLight = this->mFogEndZ__setLight;
  }
  psVar5 = d_kankyo::g_env_light.mpVrboxInfo + pPale0->mVirtIdx;
  psVar4 = d_kankyo::g_env_light.mpVrboxInfo + pPale1->mVirtIdx;
  psVar3 = d_kankyo::g_env_light.mpVrboxInfo + pPale2->mVirtIdx;
  psVar2 = d_kankyo::g_env_light.mpVrboxInfo + pPale3->mVirtIdx;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mSkyColor[0],psVar4->mSkyColor[0],local_24,psVar3->mSkyColor[0],
                     psVar2->mSkyColor[0],d_kankyo::g_env_light.mColPatBlend,
                     (this->mVrboxAddColSky0).r,d_kankyo::g_env_light.mColors.mVrboxSoraColRatio);
  (this->mVrSkyColor).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mSkyColor[1],psVar4->mSkyColor[1],local_24,psVar3->mSkyColor[1],
                     psVar2->mSkyColor[1],d_kankyo::g_env_light.mColPatBlend,
                     (this->mVrboxAddColSky0).g,d_kankyo::g_env_light.mColors.mVrboxSoraColRatio);
  (this->mVrSkyColor).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mSkyColor[2],psVar4->mSkyColor[2],local_24,psVar3->mSkyColor[2],
                     psVar2->mSkyColor[2],d_kankyo::g_env_light.mColPatBlend,
                     (this->mVrboxAddColSky0).b,d_kankyo::g_env_light.mColors.mVrboxSoraColRatio);
  (this->mVrSkyColor).b = (s16)iVar1;
  (this->mVrSkyColor).a = 0xff;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mUsoUmiColor[0],psVar4->mUsoUmiColor[0],local_24,
                     psVar3->mUsoUmiColor[0],psVar2->mUsoUmiColor[0],
                     d_kankyo::g_env_light.mColPatBlend,(this->mVrboxAddColSky0).r,
                     d_kankyo::g_env_light.mColors.mVrboxSoraColRatio);
  (this->mVrUsoUmiColor).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mUsoUmiColor[1],psVar4->mUsoUmiColor[1],local_24,
                     psVar3->mUsoUmiColor[1],psVar2->mUsoUmiColor[1],
                     d_kankyo::g_env_light.mColPatBlend,(this->mVrboxAddColSky0).g,
                     d_kankyo::g_env_light.mColors.mVrboxSoraColRatio);
  (this->mVrUsoUmiColor).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mUsoUmiColor[2],psVar4->mUsoUmiColor[2],local_24,
                     psVar3->mUsoUmiColor[2],psVar2->mUsoUmiColor[2],
                     d_kankyo::g_env_light.mColPatBlend,(this->mVrboxAddColSky0).b,
                     d_kankyo::g_env_light.mColors.mVrboxSoraColRatio);
  (this->mVrUsoUmiColor).b = (s16)iVar1;
  (this->mVrUsoUmiColor).a = 0xff;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mKumoColor[0],psVar4->mKumoColor[0],local_24,psVar3->mKumoColor[0],
                     psVar2->mKumoColor[0],d_kankyo::g_env_light.mColPatBlend,
                     (this->mVrboxAddColSky0).r,d_kankyo::g_env_light.mColors.mVrboxKumoColRatio);
  (this->mVrkumoColor).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mKumoColor[1],psVar4->mKumoColor[1],local_24,psVar3->mKumoColor[1],
                     psVar2->mKumoColor[1],d_kankyo::g_env_light.mColPatBlend,
                     (this->mVrboxAddColSky0).g,d_kankyo::g_env_light.mColors.mVrboxKumoColRatio);
  (this->mVrkumoColor).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mKumoColor[2],psVar4->mKumoColor[2],local_24,psVar3->mKumoColor[2],
                     psVar2->mKumoColor[2],d_kankyo::g_env_light.mColPatBlend,
                     (this->mVrboxAddColSky0).b,d_kankyo::g_env_light.mColors.mVrboxKumoColRatio);
  (this->mVrkumoColor).b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mKumoColor[3],psVar4->mKumoColor[3],local_24,psVar3->mKumoColor[3],
                     psVar2->mKumoColor[3],d_kankyo::g_env_light.mColPatBlend,0,d_kankyo::1_0);
  (this->mVrkumoColor).a = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mKumoCenterColor[0],psVar4->mKumoCenterColor[0],local_24,
                     psVar3->mKumoCenterColor[0],psVar2->mKumoCenterColor[0],
                     d_kankyo::g_env_light.mColPatBlend,(this->mVrboxAddColSky0).r,
                     d_kankyo::g_env_light.mColors.mVrboxKumoColRatio);
  (this->mVrkumoCenterColor).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mKumoCenterColor[1],psVar4->mKumoCenterColor[1],local_24,
                     psVar3->mKumoCenterColor[1],psVar2->mKumoCenterColor[1],
                     d_kankyo::g_env_light.mColPatBlend,(this->mVrboxAddColSky0).g,
                     d_kankyo::g_env_light.mColors.mVrboxKumoColRatio);
  (this->mVrkumoCenterColor).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mKumoCenterColor[2],psVar4->mKumoCenterColor[2],local_24,
                     psVar3->mKumoCenterColor[2],psVar2->mKumoCenterColor[2],
                     d_kankyo::g_env_light.mColPatBlend,(this->mVrboxAddColSky0).b,
                     d_kankyo::g_env_light.mColors.mVrboxKumoColRatio);
  (this->mVrkumoCenterColor).b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mKasumiMaeColor[0],psVar4->mKasumiMaeColor[0],local_24,
                     psVar3->mKasumiMaeColor[0],psVar2->mKasumiMaeColor[0],
                     d_kankyo::g_env_light.mColPatBlend,(this->mVrboxAddColKasumi).r,
                     d_kankyo::g_env_light.mColors.mVrboxSoraColRatio);
  (this->mVrKasumiMaeColor).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mKasumiMaeColor[1],psVar4->mKasumiMaeColor[1],local_24,
                     psVar3->mKasumiMaeColor[1],psVar2->mKasumiMaeColor[1],
                     d_kankyo::g_env_light.mColPatBlend,(this->mVrboxAddColKasumi).g,
                     d_kankyo::g_env_light.mColors.mVrboxSoraColRatio);
  (this->mVrKasumiMaeColor).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mKasumiMaeColor[2],psVar4->mKasumiMaeColor[2],local_24,
                     psVar3->mKasumiMaeColor[2],psVar2->mKasumiMaeColor[2],
                     d_kankyo::g_env_light.mColPatBlend,(this->mVrboxAddColKasumi).b,
                     d_kankyo::g_env_light.mColors.mVrboxSoraColRatio);
  (this->mVrKasumiMaeColor).b = (s16)iVar1;
  (this->mVrKasumiMaeColor).a = 0xff;
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* __thiscall dScnKy_env_light_c::setLight_bg(dKy_tevstr_c *,
                                              _GXColorS10 *,
                                              _GXColorS10 *,
                                              _GXColorS10 *,
                                              _GXColorS10 *,
                                              _GXColorS10 *,
                                              _GXColorS10 *,
                                              _GXColorS10 *,
                                              _GXColorS10 *,
                                              _GXColorS10 *,
                                              float *,
                                              float *) */

void __thiscall
dScnKy_env_light_c::setLight_bg
          (dScnKy_env_light_c *this,dKy_tevstr_c *pTevStr,_GXColorS10 *pBG0_C0,_GXColorS10 *pBG0_K0,
          _GXColorS10 *pBG1_C0,_GXColorS10 *pBG1_K0,_GXColorS10 *pBG2_C0,_GXColorS10 *pBG2_K0,
          _GXColorS10 *pBG3_C0,_GXColorS10 *pBG3_K0,_GXColorS10 *pFog,float *pFogStartZ,
          float *pFogEndZ)

{
  int iVar1;
  stage_palet_info_class *pPalCurrB;
  stage_palet_info_class *pPalCurrA;
  stage_palet_info_class *pPalPrevB;
  stage_palet_info_class *pPalPrevA;
  double dVar2;
  float blendPalAB;
  byte palIdx1B;
  byte palIdx0B;
  byte palIdx1A;
  byte palIdx0A;
  int iStack92;
  int iStack88;
  
  pTevStr->mColpatPrev = d_kankyo::g_env_light.mColpatPrev;
  pTevStr->mColpatCurr = d_kankyo::g_env_light.mColpatCurr;
  if (pTevStr->mColpatPrev != pTevStr->mColpatCurr) {
    pTevStr->mColpatBlend = d_kankyo::g_env_light.mColPatBlend;
  }
  setLight_palno_get(this,&pTevStr->mEnvrIdxPrev,&pTevStr->mEnvrIdxCurr,&pTevStr->mColpatPrev,
                     &pTevStr->mColpatCurr,&palIdx0A,&palIdx0B,&palIdx1A,&palIdx1B,&blendPalAB,
                     &iStack88,&iStack92,&pTevStr->mColpatBlend,&pTevStr->mInitTimer);
  pPalPrevA = d_kankyo::g_env_light.mpPaletInfo + palIdx0A;
  pPalPrevB = d_kankyo::g_env_light.mpPaletInfo + palIdx0B;
  pPalCurrA = d_kankyo::g_env_light.mpPaletInfo + palIdx1A;
  pPalCurrB = d_kankyo::g_env_light.mpPaletInfo + palIdx1B;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG0_C0[0],pPalPrevB->mBG0_C0[0],blendPalAB,pPalCurrA->mBG0_C0[0],
                     pPalCurrB->mBG0_C0[0],pTevStr->mColpatBlend,(this->mBgAddColAmb).r,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG0_C0->r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG0_C0[1],pPalPrevB->mBG0_C0[1],blendPalAB,pPalCurrA->mBG0_C0[1],
                     pPalCurrB->mBG0_C0[1],pTevStr->mColpatBlend,(this->mBgAddColAmb).g,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG0_C0->g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG0_C0[2],pPalPrevB->mBG0_C0[2],blendPalAB,pPalCurrA->mBG0_C0[2],
                     pPalCurrB->mBG0_C0[2],pTevStr->mColpatBlend,(this->mBgAddColAmb).b,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG0_C0->b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG0_K0[0],pPalPrevB->mBG0_K0[0],blendPalAB,pPalCurrA->mBG0_K0[0],
                     pPalCurrB->mBG0_K0[0],pTevStr->mColpatBlend,(this->mBgAddColDif).r,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG0_K0->r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG0_K0[1],pPalPrevB->mBG0_K0[1],blendPalAB,pPalCurrA->mBG0_K0[1],
                     pPalCurrB->mBG0_K0[1],pTevStr->mColpatBlend,(this->mBgAddColDif).g,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG0_K0->g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG0_K0[2],pPalPrevB->mBG0_K0[2],blendPalAB,pPalCurrA->mBG0_K0[2],
                     pPalCurrB->mBG0_K0[2],pTevStr->mColpatBlend,(this->mBgAddColDif).b,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG0_K0->b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG1_C0[0],pPalPrevB->mBG1_C0[0],blendPalAB,pPalCurrA->mBG1_C0[0],
                     pPalCurrB->mBG1_C0[0],pTevStr->mColpatBlend,(this->mBg1AddColAmb).r,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG1_C0->r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG1_C0[1],pPalPrevB->mBG1_C0[1],blendPalAB,pPalCurrA->mBG1_C0[1],
                     pPalCurrB->mBG1_C0[1],pTevStr->mColpatBlend,(this->mBg1AddColAmb).g,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG1_C0->g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG1_C0[2],pPalPrevB->mBG1_C0[2],blendPalAB,pPalCurrA->mBG1_C0[2],
                     pPalCurrB->mBG1_C0[2],pTevStr->mColpatBlend,(this->mBg1AddColAmb).b,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG1_C0->b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG1_K0[0],pPalPrevB->mBG1_K0[0],blendPalAB,pPalCurrA->mBG1_K0[0],
                     pPalCurrB->mBG1_K0[0],pTevStr->mColpatBlend,(this->mBg1AddColDif).r,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG1_K0->r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG1_K0[1],pPalPrevB->mBG1_K0[1],blendPalAB,pPalCurrA->mBG1_K0[1],
                     pPalCurrB->mBG1_K0[1],pTevStr->mColpatBlend,(this->mBg1AddColDif).g,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG1_K0->g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG1_K0[2],pPalPrevB->mBG1_K0[2],blendPalAB,pPalCurrA->mBG1_K0[2],
                     pPalCurrB->mBG1_K0[2],pTevStr->mColpatBlend,(this->mBg1AddColDif).b,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG1_K0->b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG2_C0[0],pPalPrevB->mBG2_C0[0],blendPalAB,pPalCurrA->mBG2_C0[0],
                     pPalCurrB->mBG2_C0[0],pTevStr->mColpatBlend,(this->mBg2AddColAmb).r,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG2_C0->r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG2_C0[1],pPalPrevB->mBG2_C0[1],blendPalAB,pPalCurrA->mBG2_C0[1],
                     pPalCurrB->mBG2_C0[1],pTevStr->mColpatBlend,(this->mBg2AddColAmb).g,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG2_C0->g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG2_C0[2],pPalPrevB->mBG2_C0[2],blendPalAB,pPalCurrA->mBG2_C0[2],
                     pPalCurrB->mBG2_C0[2],pTevStr->mColpatBlend,(this->mBg2AddColAmb).b,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG2_C0->b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG2_K0[0],pPalPrevB->mBG2_K0[0],blendPalAB,pPalCurrA->mBG2_K0[0],
                     pPalCurrB->mBG2_K0[0],pTevStr->mColpatBlend,(this->mBg2AddColDif).r,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG2_K0->r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG2_K0[1],pPalPrevB->mBG2_K0[1],blendPalAB,pPalCurrA->mBG2_K0[1],
                     pPalCurrB->mBG2_K0[1],pTevStr->mColpatBlend,(this->mBg2AddColDif).g,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG2_K0->g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG2_K0[2],pPalPrevB->mBG2_K0[2],blendPalAB,pPalCurrA->mBG2_K0[2],
                     pPalCurrB->mBG2_K0[2],pTevStr->mColpatBlend,(this->mBg2AddColDif).b,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG2_K0->b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG3_C0[0],pPalPrevB->mBG3_C0[0],blendPalAB,pPalCurrA->mBG3_C0[0],
                     pPalCurrB->mBG3_C0[0],pTevStr->mColpatBlend,(this->mBg3AddColAmb).r,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG3_C0->r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG3_C0[1],pPalPrevB->mBG3_C0[1],blendPalAB,pPalCurrA->mBG3_C0[1],
                     pPalCurrB->mBG3_C0[1],pTevStr->mColpatBlend,(this->mBg3AddColAmb).g,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG3_C0->g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG3_C0[2],pPalPrevB->mBG3_C0[2],blendPalAB,pPalCurrA->mBG3_C0[2],
                     pPalCurrB->mBG3_C0[2],pTevStr->mColpatBlend,(this->mBg3AddColAmb).b,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG3_C0->b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG3_K0[0],pPalPrevB->mBG3_K0[0],blendPalAB,pPalCurrA->mBG3_K0[0],
                     pPalCurrB->mBG3_K0[0],pTevStr->mColpatBlend,(this->mBg3AddColDif).r,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG3_K0->r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG3_K0[1],pPalPrevB->mBG3_K0[1],blendPalAB,pPalCurrA->mBG3_K0[1],
                     pPalCurrB->mBG3_K0[1],pTevStr->mColpatBlend,(this->mBg3AddColDif).g,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG3_K0->g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mBG3_K0[2],pPalPrevB->mBG3_K0[2],blendPalAB,pPalCurrA->mBG3_K0[2],
                     pPalCurrB->mBG3_K0[2],pTevStr->mColpatBlend,(this->mBg3AddColDif).b,
                     d_kankyo::g_env_light.mColors.mBgColRatio);
  pBG3_K0->b = (s16)iVar1;
  pBG3_K0->a = 0xff;
  pBG3_C0->a = 0xff;
  pBG2_K0->a = 0xff;
  pBG2_C0->a = 0xff;
  pBG1_K0->a = 0xff;
  pBG1_C0->a = 0xff;
  pBG0_K0->a = 0xff;
  pBG0_C0->a = 0xff;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mFog[0],pPalPrevB->mFog[0],blendPalAB,pPalCurrA->mFog[0],
                     pPalCurrB->mFog[0],pTevStr->mColpatBlend,(this->mAddColFog).r,
                     d_kankyo::g_env_light.mColors.mFogColRatio);
  pFog->r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mFog[1],pPalPrevB->mFog[1],blendPalAB,pPalCurrA->mFog[1],
                     pPalCurrB->mFog[1],pTevStr->mColpatBlend,(this->mAddColFog).g,
                     d_kankyo::g_env_light.mColors.mFogColRatio);
  pFog->g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (pPalPrevA->mFog[2],pPalPrevB->mFog[2],blendPalAB,pPalCurrA->mFog[2],
                     pPalCurrB->mFog[2],pTevStr->mColpatBlend,(this->mAddColFog).b,
                     d_kankyo::g_env_light.mColors.mFogColRatio);
  pFog->b = (s16)iVar1;
  dVar2 = (double)d_kankyo::float_kankyo_color_ratio_set
                            ((double)pPalPrevA->mFogStartZ,(double)pPalPrevB->mFogStartZ,
                             (double)blendPalAB,(double)pPalCurrA->mFogStartZ,
                             (double)pPalCurrB->mFogStartZ,(double)pTevStr->mColpatBlend,
                             (double)d_kankyo::g_env_light.mFogStartZ,
                             (double)d_kankyo::g_env_light.mFogRatio);
  *pFogStartZ = (float)dVar2;
  dVar2 = (double)d_kankyo::float_kankyo_color_ratio_set
                            ((double)pPalPrevA->mFogEndZ,(double)pPalPrevB->mFogEndZ,
                             (double)blendPalAB,(double)pPalCurrA->mFogEndZ,
                             (double)pPalCurrB->mFogEndZ,(double)pTevStr->mColpatBlend,
                             (double)d_kankyo::g_env_light.mFogEndZ,
                             (double)d_kankyo::g_env_light.mFogRatio);
  *pFogEndZ = (float)dVar2;
  if (*pFogEndZ < *pFogStartZ) {
    *pFogStartZ = *pFogEndZ;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall dScnKy_env_light_c::setLight_actor(dKy_tevstr_c *,
                                                 _GXColorS10 *,
                                                 float *,
                                                 float *) */

void __thiscall
dScnKy_env_light_c::setLight_actor
          (dScnKy_env_light_c *this,dKy_tevstr_c *pTevStr,_GXColorS10 *pFogColor,float *pFogStartZ,
          float *pFogEndZ)

{
  int iVar1;
  stage_palet_info_class *psVar2;
  stage_palet_info_class *psVar3;
  stage_palet_info_class *psVar4;
  stage_palet_info_class *psVar5;
  double dVar6;
  byte local_40;
  byte local_3f;
  byte local_3e;
  byte local_3d;
  int iStack60;
  int iStack56;
  float local_34 [3];
  
  pTevStr->mColpatPrev = d_kankyo::g_env_light.mColpatPrev;
  pTevStr->mColpatCurr = d_kankyo::g_env_light.mColpatCurr;
  if (pTevStr->mColpatPrev != pTevStr->mColpatCurr) {
    pTevStr->mColpatBlend = d_kankyo::g_env_light.mColPatBlend;
  }
  setLight_palno_get(this,&pTevStr->mEnvrIdxPrev,&pTevStr->mEnvrIdxCurr,&pTevStr->mColpatPrev,
                     &pTevStr->mColpatCurr,&local_3d,&local_3f,&local_3e,&local_40,local_34,
                     &iStack56,&iStack60,&pTevStr->mColpatBlend,&pTevStr->mInitTimer);
  psVar5 = d_kankyo::g_env_light.mpPaletInfo + local_3d;
  psVar4 = d_kankyo::g_env_light.mpPaletInfo + local_3f;
  psVar3 = d_kankyo::g_env_light.mpPaletInfo + local_3e;
  psVar2 = d_kankyo::g_env_light.mpPaletInfo + local_40;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mActor_C0[0],psVar4->mActor_C0[0],local_34[0],psVar3->mActor_C0[0],
                     psVar2->mActor_C0[0],pTevStr->mColpatBlend,(this->mActorAddColAmb).r,
                     d_kankyo::g_env_light.mColors.mActColRatio *
                     d_kankyo::g_env_light.mColors.mActColRatio);
  (pTevStr->mColorC0).r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mActor_C0[1],psVar4->mActor_C0[1],local_34[0],psVar3->mActor_C0[1],
                     psVar2->mActor_C0[1],pTevStr->mColpatBlend,(this->mActorAddColAmb).g,
                     d_kankyo::g_env_light.mColors.mActColRatio *
                     d_kankyo::g_env_light.mColors.mActColRatio);
  (pTevStr->mColorC0).g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mActor_C0[2],psVar4->mActor_C0[2],local_34[0],psVar3->mActor_C0[2],
                     psVar2->mActor_C0[2],pTevStr->mColpatBlend,(this->mActorAddColAmb).b,
                     d_kankyo::g_env_light.mColors.mActColRatio *
                     d_kankyo::g_env_light.mColors.mActColRatio);
  (pTevStr->mColorC0).b = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mActor_K0[0],psVar4->mActor_K0[0],local_34[0],psVar3->mActor_K0[0],
                     psVar2->mActor_K0[0],pTevStr->mColpatBlend,(this->mActorAddColDif).r,
                     d_kankyo::g_env_light.mColors.mActColRatio);
  (pTevStr->mColorK0).r = (u8)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mActor_K0[1],psVar4->mActor_K0[1],local_34[0],psVar3->mActor_K0[1],
                     psVar2->mActor_K0[1],pTevStr->mColpatBlend,(this->mActorAddColDif).g,
                     d_kankyo::g_env_light.mColors.mActColRatio);
  (pTevStr->mColorK0).g = (u8)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mActor_K0[2],psVar4->mActor_K0[2],local_34[0],psVar3->mActor_K0[2],
                     psVar2->mActor_K0[2],pTevStr->mColpatBlend,(this->mActorAddColDif).b,
                     d_kankyo::g_env_light.mColors.mActColRatio);
  (pTevStr->mColorK0).b = (u8)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mFog[0],psVar4->mFog[0],local_34[0],psVar3->mFog[0],psVar2->mFog[0],
                     pTevStr->mColpatBlend,(this->mAddColFog).r,
                     d_kankyo::g_env_light.mColors.mFogColRatio);
  pFogColor->r = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mFog[1],psVar4->mFog[1],local_34[0],psVar3->mFog[1],psVar2->mFog[1],
                     pTevStr->mColpatBlend,(this->mAddColFog).g,
                     d_kankyo::g_env_light.mColors.mFogColRatio);
  pFogColor->g = (s16)iVar1;
  iVar1 = d_kankyo::kankyo_color_ratio_set
                    (psVar5->mFog[2],psVar4->mFog[2],local_34[0],psVar3->mFog[2],psVar2->mFog[2],
                     pTevStr->mColpatBlend,(this->mAddColFog).b,
                     d_kankyo::g_env_light.mColors.mFogColRatio);
  pFogColor->b = (s16)iVar1;
  dVar6 = (double)d_kankyo::float_kankyo_color_ratio_set
                            ((double)psVar5->mFogStartZ,(double)psVar4->mFogStartZ,
                             (double)local_34[0],(double)psVar3->mFogStartZ,
                             (double)psVar2->mFogStartZ,(double)pTevStr->mColpatBlend,
                             (double)d_kankyo::g_env_light.mFogStartZ,
                             (double)d_kankyo::g_env_light.mFogRatio);
  *pFogStartZ = (float)dVar6;
  dVar6 = (double)d_kankyo::float_kankyo_color_ratio_set
                            ((double)psVar5->mFogEndZ,(double)psVar4->mFogEndZ,(double)local_34[0],
                             (double)psVar3->mFogEndZ,(double)psVar2->mFogEndZ,
                             (double)pTevStr->mColpatBlend,(double)d_kankyo::g_env_light.mFogEndZ,
                             (double)d_kankyo::g_env_light.mFogRatio);
  *pFogEndZ = (float)dVar6;
  if (*pFogEndZ < *pFogStartZ) {
    *pFogStartZ = *pFogEndZ;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dScnKy_env_light_c::settingTevStruct_colget_actor(cXyz *,
                                                                dKy_tevstr_c *,
                                                                _GXColorS10 *,
                                                                _GXColorS10 *,
                                                                _GXColorS10 *,
                                                                float *,
                                                                float *) */

void __thiscall
dScnKy_env_light_c::settingTevStruct_colget_actor
          (dScnKy_env_light_c *this,cXyz *param_1,dKy_tevstr_c *param_2,_GXColorS10 *param_3,
          _GXColorS10 *param_4,_GXColorS10 *param_5,float *param_6,float *param_7)

{
  if (param_2->mEnvrIdxOverride == 0xff) {
    if (param_2->mRoomNo < '\0') {
      param_2->mEnvrIdxCurr = 0;
    }
    else {
      param_2->mEnvrIdxCurr = param_2->mRoomNo;
    }
  }
  else {
    param_2->mEnvrIdxCurr = param_2->mEnvrIdxOverride;
  }
  if ((param_2->mEnvrIdxPrev != param_2->mEnvrIdxCurr) &&
     ((d_kankyo::1_0 <= param_2->mColpatBlend || (param_2->mColpatBlend <= d_kankyo::0_0)))) {
    param_2->mColpatBlend = d_kankyo::0_0;
  }
  setLight_actor(this,param_2,param_5,param_6,param_7);
  param_3->r = (param_2->mColorC0).r;
  param_3->g = (param_2->mColorC0).g;
  param_3->b = (param_2->mColorC0).b;
  param_3->a = (param_2->mColorC0).a;
  param_4->r = (ushort)(param_2->mColorK0).r;
  param_4->g = (ushort)(param_2->mColorK0).g;
  param_4->b = (ushort)(param_2->mColorK0).b;
  return;
}


/* __thiscall dScnKy_env_light_c::settingTevStruct_colget_player(dKy_tevstr_c *) */

void __thiscall
dScnKy_env_light_c::settingTevStruct_colget_player(dScnKy_env_light_c *this,dKy_tevstr_c *param_1)

{
  byte bVar1;
  
  if (param_1->mEnvrIdxOverride == 0xff) {
    if (-1 < param_1->mRoomNo) {
      param_1->mEnvrIdxCurr = param_1->mRoomNo;
    }
  }
  else {
    param_1->mEnvrIdxCurr = param_1->mEnvrIdxOverride;
  }
  bVar1 = param_1->mEnvrIdxCurr;
  if (d_kankyo::g_env_light.mEnvrIdxCurr == bVar1) {
    return;
  }
  if (bVar1 == d_kankyo::g_env_light.mEnvrIdxPrev) {
    d_kankyo::g_env_light.mEnvrIdxPrev = d_kankyo::g_env_light.mEnvrIdxCurr;
    d_kankyo::g_env_light.mColPatBlend = d_kankyo::1_0 - d_kankyo::g_env_light.mColPatBlend;
    d_kankyo::g_env_light.mEnvrIdxCurr = bVar1;
    param_1->mColpatBlend = d_kankyo::1_0 - d_kankyo::g_env_light.mColPatBlend;
    return;
  }
  if ((d_kankyo::g_env_light.mColPatBlend < d_kankyo::1_0) &&
     (d_kankyo::0_0 < d_kankyo::g_env_light.mColPatBlend)) {
    return;
  }
  d_kankyo::g_env_light.mColPatBlend = d_kankyo::0_0;
  d_kankyo::g_env_light.mEnvrIdxCurr = bVar1;
  param_1->mColpatBlend = d_kankyo::0_0;
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x80192ddc) */
/* WARNING: Removing unreachable block (ram,0x80192de4) */
/* __thiscall dScnKy_env_light_c::settingTevStruct_plightcol_plus(cXyz *,
                                                                  dKy_tevstr_c *,
                                                                  _GXColorS10,
                                                                  _GXColorS10,
                                                                  unsigned char) */

void __thiscall
dScnKy_env_light_c::settingTevStruct_plightcol_plus
          (dScnKy_env_light_c *this,cXyz *param_1,dKy_tevstr_c *param_2,_GXColorS10 *param_3,
          _GXColorS10 *param_4,byte param_5)

{
  bool bVar1;
  bool bVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double in_f30;
  double in_f31;
  double dVar8;
  undefined8 uVar9;
  s16 local_fc;
  s16 sStack250;
  s16 local_f8;
  s16 sStack246;
  cXyz local_f4;
  cXyz local_e8;
  cXyz local_dc;
  cXyz local_d0;
  cXyz local_c4;
  cXyz local_b8;
  cXyz local_ac;
  cXyz local_a0;
  cXyz local_94;
  double local_88;
  double local_80;
  double local_78;
  double local_70;
  double local_68;
  double local_60;
  undefined auStack24 [16];
  undefined auStack8 [8];
  float atten;
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,SUB84(in_f30,0),0);
  bVar2 = false;
  local_c4.x = param_1->x;
  local_c4.y = param_1->y;
  local_c4.z = param_1->z;
  iVar4 = d_kankyo::dKy_light_influence_id(&local_c4,0);
  bVar1 = false;
  if (-1 < iVar4) {
    local_d0.x = param_1->x;
    local_d0.y = param_1->y;
    local_d0.z = param_1->z;
    atten = d_kankyo::dKy_light_influence_distance(&local_d0,iVar4);
    in_f30 = (double)atten;
    in_f31 = (double)d_kankyo::dKy_light_influence_power(iVar4);
    if (in_f31 < (double)d_kankyo::0_001) {
      in_f31 = (double)d_kankyo::0_001;
    }
    if (in_f30 < (double)(float)((double)d_kankyo::1000_0 + in_f31)) {
      bVar1 = true;
    }
  }
  if (bVar1) {
    d_kankyo::dKy_light_influence_pos(&local_dc,iVar4);
    local_94.x = local_dc.x;
    local_94.y = local_dc.y;
    local_94.z = local_dc.z;
    uVar9 = d_kankyo::dKy_light_influence_col(iVar4);
    local_fc = (s16)((ulonglong)uVar9 >> 0x30);
    (this->mK0).r = local_fc;
    sStack250 = (s16)((ulonglong)uVar9 >> 0x20);
    (this->mK0).g = sStack250;
    local_f8 = (s16)((ulonglong)uVar9 >> 0x10);
    (this->mK0).b = local_f8;
    sStack246 = (s16)uVar9;
    (this->mK0).a = sStack246;
    dVar6 = (double)d_kankyo::dKy_light_influence_yuragi(iVar4);
    if (d_kankyo::g_env_light.mpPLights[iVar4]->mIdx < 0) {
      bVar2 = true;
    }
  }
  else {
    local_94.x = d_kankyo::g_env_light.mBaseLightInfluence.mPos.x;
    local_94.y = d_kankyo::g_env_light.mBaseLightInfluence.mPos.y;
    local_94.z = d_kankyo::g_env_light.mBaseLightInfluence.mPos.z;
    atten = mtx::PSVECSquareDistance(&d_kankyo::g_env_light.mBaseLightInfluence.mPos,param_1);
    in_f30 = (double)atten;
    if ((double)d_kankyo::0_0 < in_f30) {
      dVar6 = 1.0 / SQRT(in_f30);
      dVar6 = d_kankyo::_4591 * dVar6 * (d_kankyo::_4592 - in_f30 * dVar6 * dVar6);
      dVar6 = d_kankyo::_4591 * dVar6 * (d_kankyo::_4592 - in_f30 * dVar6 * dVar6);
      in_f30 = (double)(float)(in_f30 * d_kankyo::_4591 * dVar6 *
                                        (d_kankyo::_4592 - in_f30 * dVar6 * dVar6));
    }
    in_f31 = (double)d_kankyo::g_env_light.mBaseLightInfluence.mPower;
    dVar6 = (double)d_kankyo::g_env_light.mBaseLightInfluence.mFluctuation;
    (this->mK0).r = 0;
    (this->mK0).g = 0;
    (this->mK0).b = 0;
  }
  atten = d_kankyo::1_0;
  if (((double)d_kankyo::0_0 < in_f31) && (param_5 == 0)) {
    atten = (float)(in_f30 / in_f31);
  }
  if (d_kankyo::1_0 < atten) {
    atten = d_kankyo::1_0;
  }
  dVar8 = (double)(d_kankyo::1_0 - atten * atten);
  if ((double)d_kankyo::1000_0 <= dVar6) {
    (param_2->mLightObj).mColor.r = (u8)(int)(dVar6 - (double)d_kankyo::1000_0);
  }
  else {
    dVar6 = (double)(d_kankyo::_5472 -
                    (float)((double)(float)(dVar6 / (double)d_kankyo::_5473) * dVar8));
    atten = SComponent::cM_rndF(d_kankyo::1_0);
    (param_2->mLightObj).mColor.r =
         (u8)(int)(dVar6 + (double)((float)((double)d_kankyo::_5472 - dVar6) * atten));
  }
  dVar6 = d_kankyo::_4490;
  local_88 = (double)CONCAT44(0x43300000,(int)(this->mK0).r ^ 0x80000000);
  atten = (float)((double)d_kankyo::_5474 * dVar8);
  (this->mC0).r = param_3->r + (short)(int)((float)(local_88 - d_kankyo::_4490) * atten);
  local_78 = (double)CONCAT44(0x43300000,(int)(this->mK0).g ^ 0x80000000);
  (this->mC0).g = param_3->g + (short)(int)((float)(local_78 - dVar6) * atten);
  local_68 = (double)CONCAT44(0x43300000,(int)(this->mK0).b ^ 0x80000000);
  (this->mC0).b = param_3->b + (short)(int)((float)(local_68 - dVar6) * atten);
  if (0xff < (this->mC0).r) {
    (this->mC0).r = 0xff;
  }
  if (0xff < (this->mC0).g) {
    (this->mC0).g = 0xff;
  }
  if (0xff < (this->mC0).b) {
    (this->mC0).b = 0xff;
  }
  dVar6 = d_kankyo::_4490;
  local_60 = (double)CONCAT44(0x43300000,(int)(this->mK0).r ^ 0x80000000);
  (this->mK0).r = param_4->r + (short)(int)((double)(float)(local_60 - d_kankyo::_4490) * dVar8);
  local_70 = (double)CONCAT44(0x43300000,(int)(this->mK0).g ^ 0x80000000);
  (this->mK0).g = param_4->g + (short)(int)((double)(float)(local_70 - dVar6) * dVar8);
  local_80 = (double)CONCAT44(0x43300000,(int)(this->mK0).b ^ 0x80000000);
  (this->mK0).b = param_4->b + (short)(int)((double)(float)(local_80 - dVar6) * dVar8);
  if (0xff < (this->mK0).r) {
    (this->mK0).r = 0xff;
  }
  if (0xff < (this->mK0).g) {
    (this->mK0).g = 0xff;
  }
  if (0xff < (this->mK0).b) {
    (this->mK0).b = 0xff;
  }
  if ((param_5 != 0) || (bVar2)) {
    (param_2->mLightPosWorld).x = local_94.x;
    (param_2->mLightPosWorld).y = local_94.y;
    (param_2->mLightPosWorld).z = local_94.z;
  }
  else {
    atten = mtx::PSVECSquareDistance(param_1,(cXyz *)&param_2->mLightPosWorld);
    dVar6 = (double)atten;
    if ((double)d_kankyo::0_0 < dVar6) {
      dVar8 = 1.0 / SQRT(dVar6);
      dVar8 = d_kankyo::_4591 * dVar8 * (d_kankyo::_4592 - dVar6 * dVar8 * dVar8);
      dVar8 = d_kankyo::_4591 * dVar8 * (d_kankyo::_4592 - dVar6 * dVar8 * dVar8);
      dVar6 = (double)(float)(dVar6 * d_kankyo::_4591 * dVar8 *
                                      (d_kankyo::_4592 - dVar6 * dVar8 * dVar8));
    }
    atten = (float)(dVar6 / (double)d_kankyo::_5475);
    if (d_kankyo::1_0 < (float)(dVar6 / (double)d_kankyo::_5475)) {
      atten = d_kankyo::1_0;
    }
    dVar8 = (double)(atten * atten);
    atten = mtx::PSVECSquareDistance(param_1,&local_94);
    dVar6 = (double)atten;
    if ((double)d_kankyo::0_0 < dVar6) {
      dVar7 = 1.0 / SQRT(dVar6);
      dVar7 = d_kankyo::_4591 * dVar7 * (d_kankyo::_4592 - dVar6 * dVar7 * dVar7);
      dVar7 = d_kankyo::_4591 * dVar7 * (d_kankyo::_4592 - dVar6 * dVar7 * dVar7);
      dVar6 = (double)(float)(dVar6 * d_kankyo::_4591 * dVar7 *
                                      (d_kankyo::_4592 - dVar6 * dVar7 * dVar7));
    }
    atten = (float)(dVar6 / (double)d_kankyo::_5476);
    if (d_kankyo::1_0 < (float)(dVar6 / (double)d_kankyo::_5476)) {
      atten = d_kankyo::1_0;
    }
    atten = d_kankyo::1_0 - atten;
    atten = d_kankyo::_5477 + (float)((double)d_kankyo::_5475 * dVar8) +
            d_kankyo::100_0 * atten * atten * atten;
    dVar6 = (double)atten;
    SComponent::cLib_addCalc
              (&(param_2->mLightPosWorld).x,local_94.x,d_kankyo::_5479,atten,d_kankyo::0_001);
    SComponent::cLib_addCalc
              (&(param_2->mLightPosWorld).y,local_94.y,d_kankyo::_5479,(float)dVar6,d_kankyo::0_001)
    ;
    SComponent::cLib_addCalc
              (&(param_2->mLightPosWorld).z,local_94.z,d_kankyo::_5479,(float)dVar6,d_kankyo::0_001)
    ;
  }
  iVar4 = d_kankyo::toon_proc_check();
  if (iVar4 == 0) {
    local_b8.x = (param_2->mLightPosWorld).x;
    local_b8.y = (param_2->mLightPosWorld).y;
    local_b8.z = (param_2->mLightPosWorld).z;
  }
  else {
    ::cXyz::operator__(&local_e8,(cXyz *)&param_2->mLightPosWorld,param_1);
    local_ac.x = local_e8.x;
    local_ac.y = local_e8.y;
    local_ac.z = local_e8.z;
    ::cXyz::operator__(&local_f4,param_1,&local_ac);
    local_b8.x = local_f4.x;
    local_b8.y = local_f4.y;
    local_b8.z = local_f4.z;
  }
  mtx::PSMTXMultVec(&J3DGraphBase::j3dSys.mCurViewMtx,&local_b8,&local_a0);
  (param_2->mLightObj).mPos.x = local_a0.x;
  (param_2->mLightObj).mPos.y = local_a0.y;
  (param_2->mLightObj).mPos.z = local_a0.z;
  (param_2->mLightObj).mDir.x = d_kankyo::g_env_light.mLightDir.x;
  (param_2->mLightObj).mDir.y = d_kankyo::g_env_light.mLightDir.y;
  (param_2->mLightObj).mDir.z = d_kankyo::g_env_light.mLightDir.z;
  (param_2->mLightObj).mColor.g = 0;
  (param_2->mLightObj).mColor.b = 0;
  (param_2->mLightObj).mColor.a = 0xff;
  fVar3 = d_kankyo::1_0;
  (param_2->mLightObj).mCosAtten.x = d_kankyo::1_0;
  atten = d_kankyo::0_0;
  (param_2->mLightObj).mCosAtten.y = d_kankyo::0_0;
  (param_2->mLightObj).mCosAtten.z = atten;
  (param_2->mLightObj).mDistAtten.x = fVar3;
  (param_2->mLightObj).mDistAtten.y = atten;
  (param_2->mLightObj).mDistAtten.z = atten;
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80193008) */
/* __thiscall dScnKy_env_light_c::settingTevStruct_eflightcol_plus(cXyz *,
                                                                   dKy_tevstr_c *) */

void __thiscall
dScnKy_env_light_c::settingTevStruct_eflightcol_plus
          (dScnKy_env_light_c *this,cXyz *param_1,dKy_tevstr_c *param_2)

{
  float fVar1;
  undefined4 uVar2;
  short extraout_var;
  bool bVar4;
  short sVar3;
  short sVar5;
  short sVar6;
  int iVar7;
  undefined4 uVar8;
  double dVar9;
  double dVar10;
  undefined8 in_f31;
  short local_98;
  short sStack150;
  float local_90;
  float local_8c;
  float local_88;
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  bVar4 = false;
  iVar7 = this->mPlayerEflightIdx;
  if ((-1 < iVar7) && (d_kankyo::g_env_light.mpEfLights[iVar7] != (LIGHT_INFLUENCE *)0x0)) {
    bVar4 = true;
  }
  if ((bVar4) &&
     (dVar9 = (double)d_kankyo::dKy_eflight_influence_power(iVar7), (double)d_kankyo::0_0 < dVar9))
  {
    local_90 = param_1->x;
    local_8c = param_1->y;
    local_88 = param_1->z;
    dVar10 = (double)d_kankyo::dKy_eflight_influence_distance(&local_90,iVar7);
    dVar9 = (double)(float)(dVar10 / dVar9);
    if (dVar9 < (double)d_kankyo::1_0) {
      (param_2->mColorK1).a = 1;
      uVar2 = d_kankyo::dKy_eflight_influence_col(iVar7);
      dVar10 = d_kankyo::_4490;
      fVar1 = (float)((double)d_kankyo::1_0 - dVar9);
      local_98 = (short)((uint)uVar2 >> 0x10);
      sStack150 = (short)uVar2;
      sVar5 = (short)(int)((float)((double)CONCAT44(0x43300000,(int)sStack150 ^ 0x80000000) -
                                  d_kankyo::_4490) * fVar1);
      sVar6 = (short)(int)((float)((double)CONCAT44(0x43300000,(int)extraout_var ^ 0x80000000) -
                                  d_kankyo::_4490) * fVar1);
      sVar3 = (short)(int)((float)((double)CONCAT44(0x43300000,(int)local_98 ^ 0x80000000) -
                                  d_kankyo::_4490) * fVar1);
      if (0xff < sVar3) {
        sVar3 = 0xff;
      }
      if (0xff < sVar5) {
        sVar5 = 0xff;
      }
      if (0xff < sVar6) {
        sVar6 = 0xff;
      }
      (param_2->mColorK1).r =
           (u8)(int)((float)((double)CONCAT44(0x43300000,(int)sVar3 ^ 0x80000000) - d_kankyo::_4490)
                    * fVar1);
      (param_2->mColorK1).g =
           (u8)(int)((float)((double)CONCAT44(0x43300000,(int)sVar5 ^ 0x80000000) - dVar10) * fVar1)
      ;
      (param_2->mColorK1).b =
           (u8)(int)((float)((double)CONCAT44(0x43300000,(int)sVar6 ^ 0x80000000) - dVar10) * fVar1)
      ;
    }
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall dScnKy_env_light_c::settingTevStruct(int,
                                                   cXyz *,
                                                   dKy_tevstr_c *) */

void __thiscall
dScnKy_env_light_c::settingTevStruct
          (dScnKy_env_light_c *this,settingTevStruct__LightType lightType,cXyz *param_3,
          dKy_tevstr_c *pTevStr)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  undefined3 in_register_00000010;
  int iVar4;
  byte bVar5;
  int iVar6;
  float fogEndZ;
  float fogStartZ;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  _GXColorS10 local_98;
  _GXColorS10 local_90;
  _GXColorS10 bg3_K0;
  _GXColorS10 bg3_C0;
  _GXColorS10 bg2_K0;
  _GXColorS10 bg2_C0;
  _GXColorS10 bg1_K0;
  _GXColorS10 bg1_C0;
  _GXColorS10 bg0_K0;
  _GXColorS10 bg0_C0;
  _GXColorS10 fogColor;
  _GXColorS10 local_40;
  _GXColorS10 local_38;
  cXyz local_30;
  bool bFullLight;
  
  iVar4 = CONCAT31(in_register_00000010,lightType);
                    /* Some words on Light Types:
                       
                        0 = Actor, 9 = Player, 99 = Actor (No PLight+, EFLight+)
                        1 = BG0, 2 = BG1, 3 = BG2, 4 = BG3 (Toon Lighting)
                        5 = BG0, 6 = BG1, 7 = BG2, 8 = BG3 (Full Lighting)
                        91 = BG0, 92 = BG1, 93 = BG2 (PLight+) */
  iVar6 = -1;
  bVar5 = pTevStr->mInitTimer;
  bFullLight = false;
  if ((pTevStr->mInitType != 0x7b) && (pTevStr->mInitType != 0x7c)) {
    d_kankyo::dKy_tevstr_init(pTevStr,dStage_roomControl_c::mStayNo,0xff);
  }
  pTevStr->mInitType = 0x7c;
  (pTevStr->mColorK1).a = 0;
  (this->mActorC0).a = 0xff;
  (this->mActorK0).a = 0xff;
  if (((iVar4 == 0) || (iVar4 == 9)) || (iVar4 == 99)) {
    pTevStr->mLightMode = 1;
    bVar1 = d_kankyo::g_env_light.mInitAnimTimer;
    local_38.r = (this->mActorC0).r;
    local_38.g = (this->mActorC0).g;
    local_38.b = (this->mActorC0).b;
    local_38.a = (this->mActorC0).a;
    local_40.r = (this->mActorK0).r;
    local_40.g = (this->mActorK0).g;
    local_40.b = (this->mActorK0).b;
    local_40.a = (this->mActorK0).a;
    fogColor.r = (this->mFogColor).r;
    fogColor.g = (this->mFogColor).g;
    fogColor.b = (this->mFogColor).b;
    fogColor.a = (this->mFogColor).a;
    fogStartZ = this->mFogStartZ__setLight;
    fogEndZ = this->mFogEndZ__setLight;
    if ((iVar4 == 0) || (iVar4 == 99)) {
      settingTevStruct_colget_actor
                (this,param_3,pTevStr,&local_38,&local_40,&fogColor,&fogStartZ,&fogEndZ);
    }
    else {
      if (iVar4 == 9) {
        settingTevStruct_colget_player(this,pTevStr);
        settingTevStruct_colget_actor
                  (this,param_3,pTevStr,&local_38,&local_40,&fogColor,&fogStartZ,&fogEndZ);
        bVar5 = bVar1;
      }
    }
    (this->mC0).r = local_38.r;
    (this->mC0).g = local_38.g;
    (this->mC0).b = local_38.b;
    (this->mC0).a = 0xff;
    (this->mK0).r = local_40.r;
    (this->mK0).g = local_40.g;
    (this->mK0).b = local_40.b;
    (this->mK0).a = 0xff;
    if (iVar4 != 99) {
      local_98.g = local_40.g;
      local_98.r = local_40.r;
      local_98.a = local_40.a;
      local_98.b = local_40.b;
      local_90.g = local_38.g;
      local_90.r = local_38.r;
      local_90.a = local_38.a;
      local_90.b = local_38.b;
      settingTevStruct_plightcol_plus(this,param_3,pTevStr,&local_90,&local_98,bVar5);
      settingTevStruct_eflightcol_plus(this,param_3,pTevStr);
    }
    if (iVar4 == 9) {
      d_kankyo::g_env_light.mPLightNearPlayer.x = (pTevStr->mLightPosWorld).x;
      d_kankyo::g_env_light.mPLightNearPlayer.y = (pTevStr->mLightPosWorld).y;
      d_kankyo::g_env_light.mPLightNearPlayer.z = (pTevStr->mLightPosWorld).z;
    }
    goto LAB_80193594;
  }
                    /* BG lighting */
  pTevStr->mLightMode = 0;
  if (pTevStr->mRoomNo < 0x80) {
    pTevStr->mEnvrIdxCurr = pTevStr->mRoomNo;
  }
  else {
    pTevStr->mEnvrIdxCurr = 0;
  }
  setLight_bg(this,pTevStr,&bg0_C0,&bg0_K0,&bg1_C0,&bg1_K0,&bg2_C0,&bg2_K0,&bg3_C0,&bg3_K0,&fogColor
              ,&fogStartZ,&fogEndZ);
  if ((4 < iVar4) && (iVar4 < 9)) {
    bFullLight = true;
    iVar4 = iVar4 + -4;
  }
  if ((iVar4 < 0x5b) || (0x5e < iVar4)) {
    iVar6 = iVar4 + -1;
  }
  else {
    iVar6 = iVar4 + -0x5b;
  }
  if (iVar6 == 2) {
    (this->mC0).r = bg2_C0.r;
    (this->mC0).g = bg2_C0.g;
    (this->mC0).b = bg2_C0.b;
    (this->mC0).a = bg2_C0.a;
    (this->mK0).r = bg2_K0.r;
    (this->mK0).g = bg2_K0.g;
    (this->mK0).b = bg2_K0.b;
    (this->mK0).a = bg2_K0.a;
  }
  else {
    if (iVar6 < 2) {
      if (iVar6 == 0) {
        (this->mC0).r = bg0_C0.r;
        (this->mC0).g = bg0_C0.g;
        (this->mC0).b = bg0_C0.b;
        (this->mC0).a = bg0_C0.a;
        (this->mK0).r = bg0_K0.r;
        (this->mK0).g = bg0_K0.g;
        (this->mK0).b = bg0_K0.b;
        (this->mK0).a = bg0_K0.a;
      }
      else {
        if (iVar6 < 0) goto LAB_801933f0;
        (this->mC0).r = bg1_C0.r;
        (this->mC0).g = bg1_C0.g;
        (this->mC0).b = bg1_C0.b;
        (this->mC0).a = bg1_C0.a;
        (this->mK0).r = bg1_K0.r;
        (this->mK0).g = bg1_K0.g;
        (this->mK0).b = bg1_K0.b;
        (this->mK0).a = bg1_K0.a;
      }
    }
    else {
LAB_801933f0:
      (this->mC0).r = bg3_C0.r;
      (this->mC0).g = bg3_C0.g;
      (this->mC0).b = bg3_C0.b;
      (this->mC0).a = bg3_C0.a;
      (this->mK0).r = bg3_K0.r;
      (this->mK0).g = bg3_K0.g;
      (this->mK0).b = bg3_K0.b;
      (this->mK0).a = bg3_K0.a;
    }
  }
  if ((iVar4 < 0x5b) || (0x5d < iVar4)) {
    mtx::PSMTXMultVec(&J3DGraphBase::j3dSys.mCurViewMtx,(cXyz *)d_kankyo::lightStatusData,&local_30)
    ;
    (pTevStr->mLightObj).mPos.x = local_30.x;
    (pTevStr->mLightObj).mPos.y = local_30.y;
    (pTevStr->mLightObj).mPos.z = local_30.z;
    (pTevStr->mLightPosWorld).x = d_kankyo::lightStatusData[0].mPos.x;
    (pTevStr->mLightPosWorld).y = d_kankyo::lightStatusData[0].mPos.y;
    (pTevStr->mLightPosWorld).z = d_kankyo::lightStatusData[0].mPos.z;
    (pTevStr->mLightObj).mDir.x = d_kankyo::g_env_light.mLightDir.x;
    (pTevStr->mLightObj).mDir.y = d_kankyo::g_env_light.mLightDir.y;
    (pTevStr->mLightObj).mDir.z = d_kankyo::g_env_light.mLightDir.z;
    if (bFullLight) {
      (pTevStr->mLightObj).mColor.r = 0xff;
      (pTevStr->mLightObj).mColor.g = 0xff;
      (pTevStr->mLightObj).mColor.b = 0xff;
    }
    else {
      (pTevStr->mLightObj).mColor.r = 0xff;
      (pTevStr->mLightObj).mColor.g = 0;
      (pTevStr->mLightObj).mColor.b = 0;
    }
    (pTevStr->mLightObj).mColor.a = 0xff;
    fVar3 = d_kankyo::1_0;
    (pTevStr->mLightObj).mCosAtten.x = d_kankyo::1_0;
    fVar2 = d_kankyo::0_0;
    (pTevStr->mLightObj).mCosAtten.y = d_kankyo::0_0;
    (pTevStr->mLightObj).mCosAtten.z = fVar2;
    (pTevStr->mLightObj).mDistAtten.x = fVar3;
    (pTevStr->mLightObj).mDistAtten.y = fVar2;
    (pTevStr->mLightObj).mDistAtten.z = fVar2;
  }
  else {
    local_38._0_4_ = *(uint *)&this->mC0 & 0xff00ff;
    local_38._4_4_ = CONCAT22((this->mC0).b,local_38.a) & 0xffffff;
    local_40._0_4_ = *(uint *)&this->mK0 & 0xff00ff;
    local_40._4_4_ = CONCAT22((this->mK0).b,local_40.a) & 0xffffff;
    pTevStr->mLightMode = 2;
    local_a8 = local_40._0_4_;
    local_a4 = local_40._4_4_;
    local_a0 = local_38._0_4_;
    local_9c = local_38._4_4_;
    settingTevStruct_plightcol_plus
              (this,param_3,pTevStr,(_GXColorS10 *)&local_a0,(_GXColorS10 *)&local_a8,bVar5);
  }
LAB_80193594:
  (this->mC0).a = 0xff;
  (pTevStr->mColorC0).r = (this->mC0).r;
  (pTevStr->mColorC0).g = (this->mC0).g;
  (pTevStr->mColorC0).b = (this->mC0).b;
  (pTevStr->mColorC0).a = (this->mC0).a;
  (pTevStr->mColorK0).r = (u8)(this->mK0).r;
  (pTevStr->mColorK0).g = (u8)(this->mK0).g;
  (pTevStr->mColorK0).b = (u8)(this->mK0).b;
  if (iVar6 == 1) {
                    /* BG1 (Sea) gets different fog */
    (pTevStr->mFogColor).r = d_kankyo::g_env_light.mVrUsoUmiColor.r;
    (pTevStr->mFogColor).g = d_kankyo::g_env_light.mVrUsoUmiColor.g;
    (pTevStr->mFogColor).b = d_kankyo::g_env_light.mVrUsoUmiColor.b;
    (pTevStr->mFogColor).a = d_kankyo::g_env_light.mVrUsoUmiColor.a;
  }
  else {
    (pTevStr->mFogColor).r = fogColor.r;
    (pTevStr->mFogColor).g = fogColor.g;
    (pTevStr->mFogColor).b = fogColor.b;
    (pTevStr->mFogColor).a = fogColor.a;
  }
  pTevStr->mFogStartZ = fogStartZ;
  pTevStr->mFogEndZ = fogEndZ;
  return;
}


namespace d_kankyo {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall setLightTevColorType_sub(J3DMaterial *,
                                      dKy_tevstr_c *) */

void setLightTevColorType_sub(J3DMaterial *pMaterial,dKy_tevstr_c *pTevStr)

{
  J3DColorChan *pColorChan;
  _GXColorS10 *pRegPrev;
  char cVar1;
  _GXColor pK1;
  _GXColor pK0_;
  _GXColor pC0_;
  _GXColorS10 *pC0;
  _GXColor *pK0;
  J3DFog *pFog0;
  J3DFog *pFog;
  int iVar2;
  uint uVar3;
  _GXColor k0;
  _GXColorS10 c0;
  TVec3_float_ local_2c;
  
  if (pTevStr->mLightMode != 0) {
    pColorChan = (J3DColorChan *)
                 (*(code *)pMaterial->mpColorBlock->vtbl->getColorChan)(pMaterial->mpColorBlock,0);
                    /* Set lit mask to 0x01 */
    pColorChan->mChan = pColorChan->mChan & 0xffc3U | 4;
    pColorChan->mChan = pColorChan->mChan & 0x87ff;
    pRegPrev = (_GXColorS10 *)
               (*(code *)pMaterial->mpTevBlock->vtbl->getTevColor)(pMaterial->mpTevBlock,3);
    iVar2 = (int)pRegPrev->a;
    uVar3 = 0xff;
    if ((0 < iVar2) &&
       (cVar1 = (*(code *)pMaterial->mpTevBlock->vtbl->getTevKColorSel)
                          (pMaterial->mpTevBlock,iVar2 + -1), cVar1 == '\r')) {
      uVar3 = iVar2 - 1;
    }
    if (uVar3 != 0xff) {
      if ((pTevStr->mColorK1).a == 0) {
        (*(code *)pMaterial->mpTevBlock->vtbl->setTevStageNum_1)(pMaterial->mpTevBlock,uVar3 & 0xff)
        ;
      }
      else {
        (*(code *)pMaterial->mpTevBlock->vtbl->setTevStageNum_1)
                  (pMaterial->mpTevBlock,uVar3 + 1 & 0xff);
        pK1 = (*(code *)pMaterial->mpTevBlock->vtbl->getTevKColor)(pMaterial->mpTevBlock,1);
        if (pK1 != 0) {
          (*(code *)pMaterial->mpTevBlock->vtbl->setTevKColor_0)
                    (pMaterial->mpTevBlock,1,&pTevStr->mColorK1);
                    /* Set lit mask to 0x03 (eflight) */
          pColorChan->mChan = pColorChan->mChan & 0xffc3U | 0xc;
          pColorChan->mChan = pColorChan->mChan & 0x87ff;
        }
      }
    }
  }
  mtx::PSMTXMultVec(&J3DGraphBase::j3dSys.mCurViewMtx,(cXyz *)&pTevStr->mLightPosWorld,
                    (cXyz *)&local_2c);
  (pTevStr->mLightObj).mPos.x = local_2c.x;
  (pTevStr->mLightObj).mPos.y = local_2c.y;
  (pTevStr->mLightObj).mPos.z = local_2c.z;
  (*(code *)pMaterial->mpColorBlock->vtbl->setLight)(pMaterial->mpColorBlock,0,pTevStr);
  iVar2 = toon_proc_check();
  if ((iVar2 == 0) || (pTevStr->mLightMode == 0)) {
    pC0 = (_GXColorS10 *)
          (*(code *)pMaterial->mpTevBlock->vtbl->getTevColor)(pMaterial->mpTevBlock,0);
    if (pC0 != (_GXColorS10 *)0x0) {
      (pTevStr->mColorC0).a = pC0->a;
      (*(code *)pMaterial->mpTevBlock->vtbl->setTevColor_0)
                (pMaterial->mpTevBlock,0,&pTevStr->mColorC0);
    }
    pK0 = (_GXColor *)(*(code *)pMaterial->mpTevBlock->vtbl->getTevKColor)(pMaterial->mpTevBlock,0);
    if (pK0 != (_GXColor *)0x0) {
      (pTevStr->mColorK0).a = pK0->a;
      (*(code *)pMaterial->mpTevBlock->vtbl->setTevKColor_0)
                (pMaterial->mpTevBlock,0,&pTevStr->mColorK0);
    }
  }
  else {
    pK0_ = (*(code *)pMaterial->mpTevBlock->vtbl->getTevKColor)(pMaterial->mpTevBlock,0);
    if (pK0_ != 0) {
      k0.a = *(u8 *)(pK0_ + 3);
      k0.r = (u8)(pTevStr->mColorC0).r;
      k0.g = (u8)(pTevStr->mColorC0).g;
      k0.b = (u8)(pTevStr->mColorC0).b;
      (*(code *)pMaterial->mpTevBlock->vtbl->setTevKColor_0)(pMaterial->mpTevBlock,0,&k0);
    }
    pC0_ = (*(code *)pMaterial->mpTevBlock->vtbl->getTevColor)(pMaterial->mpTevBlock,0);
    if (pC0_ != 0) {
      c0.a = *(s16 *)(pC0_ + 6);
      c0.r = ZEXT12((pTevStr->mColorK0).r);
      c0.g = ZEXT12((pTevStr->mColorK0).g);
      c0.b = ZEXT12((pTevStr->mColorK0).b);
      (*(code *)pMaterial->mpTevBlock->vtbl->setTevColor_0)(pMaterial->mpTevBlock,0,&c0);
    }
  }
  pFog0 = (J3DFog *)(**(code **)(pMaterial->mpPEBlock->vtbl + 0x2c))();
  if ((pFog0 != (J3DFog *)0x0) &&
     (pFog = (J3DFog *)(**(code **)(pMaterial->mpPEBlock->vtbl + 0x2c))(), pFog->mType != 0)) {
    pFog->mStartZ = pTevStr->mFogStartZ;
    pFog->mEndZ = pTevStr->mFogEndZ;
    if (pFog->mEndZ < pFog->mStartZ) {
      pFog->mStartZ = pFog->mEndZ;
    }
    pFog->mNearZ = (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mNearPlane;
    pFog->mFarZ = (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mFarPlane;
    (pFog->mColor).r = (u8)(pTevStr->mFogColor).r;
    (pFog->mColor).g = (u8)(pTevStr->mFogColor).g;
    (pFog->mColor).b = (u8)(pTevStr->mFogColor).b;
    pFog->mAdjEnable = g_env_light.mFogAdjEnable;
    if (pFog->mAdjEnable == 1) {
      pFog->mCenter = g_env_light.mFogAdjCenter;
      copy_bytes((byte *)pFog->mFogAdjTable,(byte *)&g_env_light.mFogAdjTable,0x14);
    }
  }
  return;
}

}

/* __thiscall J3DColorBlock::setLight(unsigned long,
                                      J3DLightObj *) */

void __thiscall J3DColorBlock::setLight(J3DColorBlock *this,ulong param_1,J3DLightObj *param_2)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dScnKy_env_light_c::setLightTevColorType(J3DModel *,
                                                       dKy_tevstr_c *) */

void __thiscall
dScnKy_env_light_c::setLightTevColorType
          (dScnKy_env_light_c *this,J3DModel *param_1,dKy_tevstr_c *param_2)

{
  uint uVar1;
  
  if (param_2->mInitType != 0x7c) {
    if (param_2->mInitType != 0x7b) {
      d_kankyo::dKy_tevstr_init(param_2,dStage_roomControl_c::mStayNo,0xff);
    }
    settingTevStruct(this,Actor_NoLight,(cXyz *)0x0,param_2);
  }
  uVar1 = (uint)(param_1->mpModelData->mMaterialTable).mMaterialCount;
  while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {
    d_kankyo::setLightTevColorType_sub
              (*(J3DMaterial **)
                ((int)(param_1->mpModelData->mMaterialTable).mpMaterials + (uVar1 * 4 & 0x3fffc)),
               param_2);
  }
  return;
}


/* __thiscall dScnKy_env_light_c::CalcTevColor(void) */

void __thiscall dScnKy_env_light_c::CalcTevColor(dScnKy_env_light_c *this)

{
  daPy_lk_c *pdVar1;
  int iVar2;
  cXyz local_28;
  cXyz local_1c;
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  local_1c.x = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent
               .mPos.x;
  local_1c.y = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent
               .mPos.y;
  local_1c.z = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent
               .mPos.z;
  iVar2 = d_kankyo::dKy_eflight_influence_id(&local_1c,0);
  this->mPlayerEflightIdx = iVar2;
  local_28.x = (pdVar1->parent).parent.mCurrent.mPos.x;
  local_28.y = (pdVar1->parent).parent.mCurrent.mPos.y;
  local_28.z = (pdVar1->parent).parent.mCurrent.mPos.z;
  iVar2 = d_kankyo::dKy_light_influence_id(&local_28,0);
  this->mPlayerPLightIdx = iVar2;
  return;
}


/* __thiscall dScnKy_env_light_c::Sndpos(void) */

void __thiscall dScnKy_env_light_c::Sndpos(dScnKy_env_light_c *this)

{
  if ((*(int *)&this->field_0x944 != 0) &&
     (*(int *)&this->field_0x944 = *(int *)&this->field_0x944 + -1, *(int *)&this->field_0x944 == 0)
     ) {
    d_kankyo::dKy_Sound_init();
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80193c14) */
/* WARNING: Removing unreachable block (ram,0x80193d7c) */
/* __thiscall dScnKy_env_light_c::Eflight_flush_proc(void) */

void __thiscall dScnKy_env_light_c::Eflight_flush_proc(dScnKy_env_light_c *this)

{
  float fVar1;
  _GXColor *pColorTbl;
  uint uVar2;
  s16 sVar3;
  uint uVar4;
  _GXColor *pColor_;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 in_f31;
  double dVar8;
  undefined auStack8 [8];
  byte state;
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (this->mSwordLightType == 0) {
    pColorTbl = d_kankyo::flush_col_5775;
    fVar1 = d_kankyo::100_0;
  }
  else {
    pColorTbl = d_kankyo::flush_col2_5776;
    fVar1 = d_kankyo::0_0;
  }
  state = this->mSwordState;
  if (state == 2) {
    iVar5 = 0;
    iVar6 = 3;
    do {
      uVar2 = (uint)this->mSwordFrame;
      pColor_ = (_GXColor *)(&pColorTbl->r + iVar5);
      if ((pColor_->r <= uVar2) && (uVar4 = (uint)pColor_[1].r, uVar2 <= uVar4)) {
        dVar8 = (double)(d_kankyo::1_0 -
                        (float)((double)CONCAT44(0x43300000,uVar4 - uVar2 ^ 0x80000000) -
                               d_kankyo::_4490) /
                        (float)((double)CONCAT44(0x43300000,uVar4 - pColor_->r ^ 0x80000000) -
                               d_kankyo::_4490));
        sVar3 = d_kankyo::u8_data_ratio_set(dVar8,pColor_->g,pColor_[1].g);
        (this->mSwordLight).mColor.r = sVar3;
        sVar3 = d_kankyo::u8_data_ratio_set
                          (dVar8,(&pColorTbl->r + iVar5)[2],(&pColorTbl->r + iVar5)[6]);
        (this->mSwordLight).mColor.g = sVar3;
        sVar3 = d_kankyo::u8_data_ratio_set
                          (dVar8,(&pColorTbl->r + iVar5)[3],(&pColorTbl->r + iVar5)[7]);
        (this->mSwordLight).mColor.b = sVar3;
        break;
      }
      iVar5 = iVar5 + 4;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    if (pColorTbl[3].r < this->mSwordFrame) {
      this->mSwordState = this->mSwordState + 1;
    }
    this->mSwordFrame = this->mSwordFrame + 1;
  }
  else {
    if (state < 2) {
      if (state != 0) {
        this->mSwordFrame = 0;
        (this->mSwordLight).mColor.r = (ushort)pColorTbl->g;
        (this->mSwordLight).mColor.g = (ushort)pColorTbl->b;
        (this->mSwordLight).mColor.b = (ushort)pColorTbl->a;
        (this->mSwordLight).mPower = d_kankyo::1000_0;
        (this->mSwordLight).mFluctuation = fVar1;
        d_kankyo::dKy_efplight_set(&this->mSwordLight);
        this->mSwordState = this->mSwordState + 1;
      }
    }
    else {
      if (state == 4) {
        d_kankyo::dKy_efplight_cut(&this->mSwordLight);
        this->mSwordState = 1;
      }
      else {
        if (state < 4) {
          d_kankyo::dKy_efplight_cut(&this->mSwordLight);
          this->mSwordState = 0;
        }
      }
    }
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* __thiscall dScnKy_env_light_c::SetBaseLight(void) */

void __thiscall dScnKy_env_light_c::SetBaseLight(dScnKy_env_light_c *this)

{
  float fVar1;
  stage_lightvec_info_class *pLght;
  dStage_roomStatus_c *pdVar2;
  
  pLght = (stage_lightvec_info_class *)0x0;
  if (-1 < (char)dStage_roomControl_c::mStayNo) {
    pdVar2 = dStage_roomControl_c::getStatusRoomDt
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                        (int)(char)dStage_roomControl_c::mStayNo);
    pLght = (stage_lightvec_info_class *)
            (*(code *)((pdVar2->parent).parent.vtbl)->getLightVecInfo)();
  }
  if (pLght == (stage_lightvec_info_class *)0x0) {
    if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime <=
         d_kankyo::97_5) ||
       (d_kankyo::292_5 <=
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime)) {
      (this->mBaseLightInfluence).mPos.x = d_kankyo::g_env_light.mMoonPos.x;
      (this->mBaseLightInfluence).mPos.y = d_kankyo::g_env_light.mMoonPos.y;
      (this->mBaseLightInfluence).mPos.z = d_kankyo::g_env_light.mMoonPos.z;
    }
    else {
      (this->mBaseLightInfluence).mPos.x = d_kankyo::g_env_light.mSunPos2.x;
      (this->mBaseLightInfluence).mPos.y = d_kankyo::g_env_light.mSunPos2.y;
      (this->mBaseLightInfluence).mPos.z = d_kankyo::g_env_light.mSunPos2.z;
    }
    (this->mBaseLightInfluence).mColor.r = 0xff;
    (this->mBaseLightInfluence).mColor.g = 0xff;
    (this->mBaseLightInfluence).mColor.b = 0xff;
    (this->mBaseLightInfluence).mColor.a = 0xff;
    fVar1 = d_kankyo::0_0;
    (this->mBaseLightInfluence).mPower = d_kankyo::0_0;
    (this->mBaseLightInfluence).mFluctuation = fVar1;
  }
  else {
    (this->mBaseLightInfluence).mPos.x = (pLght->mPos).x;
    (this->mBaseLightInfluence).mPos.y = (pLght->mPos).y;
    (this->mBaseLightInfluence).mPos.z = (pLght->mPos).z;
    (this->mBaseLightInfluence).mColor.r = 0;
    (this->mBaseLightInfluence).mColor.g = 0;
    (this->mBaseLightInfluence).mColor.b = 0;
    (this->mBaseLightInfluence).mColor.a = 0;
    (this->mBaseLightInfluence).mPower = d_kankyo::200_0 * pLght->mRadius;
    (this->mBaseLightInfluence).mFluctuation =
         (float)((double)CONCAT44(0x43300000,(uint)pLght->mFluctuation) - d_kankyo::_4781);
  }
  return;
}


/* __thiscall dScnKy_env_light_c::exeKankyo(void) */

void __thiscall dScnKy_env_light_c::exeKankyo(dScnKy_env_light_c *this)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = d_kankyo::g_env_light.mColPatModeGather;
  bVar1 = d_kankyo::g_env_light.mColpatCurrGather;
  d_kankyo::g_env_light.mColPatMode = d_kankyo::g_env_light.mColPatModeGather;
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) &&
     (d_kankyo::g_env_light.mColPatModeGather != 0)) {
    if (d_kankyo::g_env_light.mColPatModeGather < 3) {
      d_kankyo::g_env_light.mColPatModeGather = d_kankyo::g_env_light.mColPatModeGather + 1;
    }
    else {
      d_kankyo::g_env_light.mColPatModeGather = 0;
    }
  }
  if (bVar2 == 0) {
    if (d_kankyo::g_env_light.mColpatPrev == d_kankyo::g_env_light.mColpatCurr) {
      if (d_kankyo::g_env_light.mColpatPrevGather != 0xff) {
        d_kankyo::g_env_light.mColpatPrev = d_kankyo::g_env_light.mColpatPrevGather;
        d_kankyo::g_env_light.mColpatPrevGather = 0xff;
      }
      if (d_kankyo::g_env_light.mColpatCurrGather != 0xff) {
        d_kankyo::g_env_light.mColpatCurr = d_kankyo::g_env_light.mColpatCurrGather;
        d_kankyo::g_env_light.mColpatCurrGather = 0xff;
        d_kankyo::g_env_light.mColpatWeather = bVar1;
      }
      if (d_kankyo::0_0 <= d_kankyo::g_env_light.mColPatBlendGather) {
        d_kankyo::g_env_light.mColPatBlend = d_kankyo::g_env_light.mColPatBlendGather;
        d_kankyo::g_env_light.mColPatBlendGather = d_kankyo::_1_0;
      }
    }
  }
  else {
    if ((d_kankyo::g_env_light.mColpatPrevGather != 0xff) &&
       (d_kankyo::g_env_light.mColpatPrev = d_kankyo::g_env_light.mColpatPrevGather,
       d_kankyo::g_env_light.mColPatModeGather == 0)) {
      d_kankyo::g_env_light.mColpatPrevGather = 0xff;
    }
    if ((d_kankyo::g_env_light.mColpatCurrGather != 0xff) &&
       (d_kankyo::g_env_light.mColpatCurr = d_kankyo::g_env_light.mColpatCurrGather,
       d_kankyo::g_env_light.mColPatModeGather == 0)) {
      d_kankyo::g_env_light.mColpatCurrGather = 0xff;
    }
    if ((d_kankyo::0_0 <= d_kankyo::g_env_light.mColPatBlendGather) &&
       (d_kankyo::g_env_light.mColPatBlend = d_kankyo::g_env_light.mColPatBlendGather,
       d_kankyo::g_env_light.mColPatModeGather == 0)) {
      d_kankyo::g_env_light.mColPatBlendGather = d_kankyo::_1_0;
    }
  }
  d_kankyo::g_env_light.mColors.mAllColRatio = d_kankyo::g_env_light.mColorsGather.mAllColRatio;
  d_kankyo::g_env_light.mColors.mActColRatio = d_kankyo::g_env_light.mColorsGather.mActColRatio;
  d_kankyo::g_env_light.mColors.mBgColRatio = d_kankyo::g_env_light.mColorsGather.mBgColRatio;
  d_kankyo::g_env_light.mColors.mFogColRatio = d_kankyo::g_env_light.mColorsGather.mFogColRatio;
  d_kankyo::g_env_light.mColors.mVrboxSoraColRatio =
       d_kankyo::g_env_light.mColorsGather.mVrboxSoraColRatio;
  d_kankyo::g_env_light.mColors.mVrboxKumoColRatio =
       d_kankyo::g_env_light.mColorsGather.mVrboxKumoColRatio;
  d_kankyo::g_env_light.mColorsGather.mAllColRatio = d_kankyo::1_0;
  d_kankyo::g_env_light.mColorsGather.mActColRatio = d_kankyo::1_0;
  d_kankyo::g_env_light.mColorsGather.mBgColRatio = d_kankyo::1_0;
  d_kankyo::g_env_light.mColorsGather.mFogColRatio = d_kankyo::1_0;
  d_kankyo::g_env_light.mColorsGather.mVrboxSoraColRatio = d_kankyo::1_0;
  d_kankyo::g_env_light.mColorsGather.mVrboxKumoColRatio = d_kankyo::1_0;
  setDaytime(this);
  d_kankyo_wether::dKyw_wether_proc();
  CalcTevColor(this);
  Sndpos(this);
  Eflight_flush_proc(this);
  SetSchbit(this);
  return;
}


namespace d_kankyo {

/* __stdcall dKy_event_init(void) */

void dKy_event_init(void)

{
  return;
}


/* __stdcall dice_wether_init(unsigned char,
                              float,
                              float) */

void dice_wether_init(byte param_1,float param_2,float param_3)

{
  g_env_light.mDiceWeatherTime = param_3 + param_2;
  if (g_env_light.mDiceWeatherTime < 360_0) {
    g_env_light.mDiceWeatherMode = param_1;
    return;
  }
  g_env_light.mDiceWeatherTime = g_env_light.mDiceWeatherTime - 360_0;
  g_env_light.mDiceWeatherMode = param_1;
  return;
}


/* __stdcall dice_wether_execute(unsigned char,
                                 float,
                                 float) */

void dice_wether_execute(byte param_1,float param_2,float curTime)

{
  if (param_1 != 0xff) {
    g_env_light.mDiceWeatherTime = curTime + param_2;
    if (360_0 <= g_env_light.mDiceWeatherTime) {
      g_env_light.mDiceWeatherTime = g_env_light.mDiceWeatherTime - 360_0;
    }
    g_env_light.mDiceWeatherCounter = g_env_light.mDiceWeatherCounter + 1;
    g_env_light.mDiceWeatherMode = param_1;
    return;
  }
  g_env_light.mDiceWeatherMode = 0;
  g_env_light.mDiceWeatherState = g_env_light.mDiceWeatherState + 1;
  return;
}


/* __stdcall dice_rain_minus(void) */

void dice_rain_minus(void)

{
  if (g_env_light.mRainCount < 0x29) {
    if (g_env_light.mRainCount != 0) {
      g_env_light.mRainCount = g_env_light.mRainCount + -1;
    }
  }
  else {
    g_env_light.mRainCount = g_env_light.mRainCount + -3;
  }
  d_kankyo_wether::dKyw_rain_set(g_env_light.mRainCount);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801942c0) */
/* __stdcall phantomship_wether(void) */

undefined4 phantomship_wether(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar2 = 0;
  dVar4 = (double)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime;
  iVar1 = dKy_get_dayofweek();
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime < 180_0) {
    if (iVar1 == 0) {
      iVar1 = 6;
    }
    else {
      iVar1 = iVar1 + -1;
    }
  }
  if ((((double)_5984 < dVar4) || (dVar4 < (double)_5985)) &&
     ((((((::dStage_roomControl_c::mStayNo == 5 && (iVar1 == 0)) ||
         ((::dStage_roomControl_c::mStayNo == 0x24 && (iVar1 == 1)))) ||
        ((::dStage_roomControl_c::mStayNo == 0x22 && (iVar1 == 2)))) ||
       ((((::dStage_roomControl_c::mStayNo == 10 && (iVar1 == 3)) ||
         ((::dStage_roomControl_c::mStayNo == 0x31 && (iVar1 == 4)))) ||
        ((::dStage_roomControl_c::mStayNo == 0x15 && (iVar1 == 5)))))) ||
      ((::dStage_roomControl_c::mStayNo == 0x17 && (iVar1 == 6)))))) {
    uVar2 = 1;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80194698) */
/* WARNING: Removing unreachable block (ram,0x80194448) */
/* WARNING: Removing unreachable block (ram,0x8019449c) */
/* WARNING: Removing unreachable block (ram,0x8019456c) */
/* WARNING: Removing unreachable block (ram,0x80194824) */
/* __stdcall dKy_event_proc(void) */

void dKy_event_proc(void)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  byte pselIdx;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  float fVar6;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea");
  if (iVar1 != 0) goto LAB_80194824;
  iVar1 = dKy_checkEventNightStop();
  if (iVar1 == 0) {
    if (g_env_light.mInitAnimTimer == 0) {
      uVar2 = ::dStage_roomControl_c::GetTimePass();
      if ((uVar2 == 0) ||
         (uVar2 = dSv_player_get_item_c::isItem
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,2,0)
         , uVar2 == 0)) {
                    /* Time stopped weather code */
        cVar3 = dKy_pship_existense_chk();
        if (cVar3 == '\0') {
          if (g_env_light.mColpatWeather != 0) {
            g_env_light.mColpatWeather = 0;
            g_env_light.mColpatCurrGather = 0;
          }
          if (g_env_light.mThunderMode == 1) {
            g_env_light.mThunderMode = 0;
          }
          dice_rain_minus();
        }
        else {
          if (g_env_light.mColpatWeather != 1) {
            g_env_light.mColpatWeather = 1;
            g_env_light.mColpatCurrGather = 1;
          }
          g_env_light.mThunderMode = 1;
        }
      }
      else {
                    /* Main weather code */
        cVar3 = dKy_pship_existense_chk();
        if (cVar3 == '\0') {
          dVar5 = (double)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime
          ;
          if ((((double)g_env_light.mDiceWeatherChangeTime < dVar5) &&
              ((float)(dVar5 - (double)g_env_light.mDiceWeatherChangeTime) < 180_0)) &&
             (g_env_light.mDiceWeatherState == 0)) {
            g_env_light.mDiceWeatherState = 1;
          }
          if (g_env_light.mDiceWeatherState == 2) {
            if (((double)g_env_light.mDiceWeatherTime < dVar5) &&
               ((float)(dVar5 - (double)g_env_light.mDiceWeatherTime) < 180_0)) {
              if (g_env_light.mDiceWeatherCurrPattern == 2) {
                dice_wether_execute((&S_wether_mode_pat03_5995)[g_env_light.mDiceWeatherCounter],
                                    (&S_wether_time_pat03_5996)[g_env_light.mDiceWeatherCounter],
                                    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                    mStatusB.mCurTime);
              }
              else {
                if (g_env_light.mDiceWeatherCurrPattern < 2) {
                  if (g_env_light.mDiceWeatherCurrPattern == 0) {
                    dice_wether_execute((&S_wether_mode_pat01_5991)[g_env_light.mDiceWeatherCounter]
                                        ,(&S_wether_time_pat01_5992)
                                         [g_env_light.mDiceWeatherCounter],
                                        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                        mStatusB.mCurTime);
                  }
                  else {
                    dice_wether_execute((&S_wether_mode_pat02_5993)[g_env_light.mDiceWeatherCounter]
                                        ,(&S_wether_time_pat02_5994)
                                         [g_env_light.mDiceWeatherCounter],
                                        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                        mStatusB.mCurTime);
                  }
                }
                else {
                  if (g_env_light.mDiceWeatherCurrPattern < 4) {
                    dice_wether_execute((&S_wether_mode_pat04_5997)[g_env_light.mDiceWeatherCounter]
                                        ,(&S_wether_time_pat04_5998)
                                         [g_env_light.mDiceWeatherCounter],
                                        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                        mStatusB.mCurTime);
                  }
                }
              }
            }
          }
          else {
            if (g_env_light.mDiceWeatherState < 2) {
              if (g_env_light.mDiceWeatherState != 0) {
                fVar6 = SComponent::cM_rndF(7_99);
                g_env_light.mDiceWeatherCurrPattern = (&S_wether_table_5990)[(int)fVar6 & 0xff];
                g_env_light.mDiceWeatherCounter = 0;
                if (g_env_light.mDiceWeatherCurrPattern == 2) {
                  dice_wether_init(S_wether_mode_pat03_5995,S_wether_time_pat03_5996,(float)dVar5);
                }
                else {
                  if (g_env_light.mDiceWeatherCurrPattern < 2) {
                    if (g_env_light.mDiceWeatherCurrPattern == 0) {
                      dice_wether_init(S_wether_mode_pat01_5991,S_wether_time_pat01_5992,
                                       (float)dVar5);
                    }
                    else {
                      dice_wether_init(S_wether_mode_pat02_5993,S_wether_time_pat02_5994,
                                       (float)dVar5);
                    }
                  }
                  else {
                    if (g_env_light.mDiceWeatherCurrPattern < 4) {
                      dice_wether_init(S_wether_mode_pat04_5997,S_wether_time_pat04_5998,
                                       (float)dVar5);
                    }
                  }
                }
                g_env_light.mDiceWeatherCounter = g_env_light.mDiceWeatherCounter + 1;
                g_env_light.mDiceWeatherState = g_env_light.mDiceWeatherState + 1;
              }
            }
            else {
              if (g_env_light.mDiceWeatherState < 4) {
                fVar6 = SComponent::cM_rndF(7_99);
                g_env_light.mDiceWeatherChangeTime =
                     (float)(dVar5 + (double)(&S_time_table_5989)[(int)fVar6 & 0xff]);
                if (360_0 <= g_env_light.mDiceWeatherChangeTime) {
                  g_env_light.mDiceWeatherChangeTime = g_env_light.mDiceWeatherChangeTime - 360_0;
                }
                g_env_light.mDiceWeatherState = 0;
              }
            }
          }
          if ((g_env_light.mColPatMode == 0) && (g_env_light.mColPatModeGather == 0)) {
            if (g_env_light.mDiceWeatherMode == 3) {
LAB_80194710:
              pselIdx = 1;
              if (g_env_light.mRainCount < 0xfa) {
                g_env_light.mRainCount = g_env_light.mRainCount + 1;
                d_kankyo_wether::dKyw_rain_set(g_env_light.mRainCount);
              }
            }
            else {
              if (g_env_light.mDiceWeatherMode < 3) {
                if (g_env_light.mDiceWeatherMode == 1) {
                  pselIdx = 1;
                  dice_rain_minus();
                }
                else {
                  if (g_env_light.mDiceWeatherMode == 0) {
                    pselIdx = 0;
                    if (g_env_light.mThunderMode == 1) {
                      g_env_light.mThunderMode = 0;
                    }
                    dice_rain_minus();
                  }
                  else {
                    /* mDiceWeatherMode == 2 */
                    pselIdx = 1;
                    if (g_env_light.mRainCount < 0x28) {
                      g_env_light.mRainCount = g_env_light.mRainCount + 1;
                      d_kankyo_wether::dKyw_rain_set(g_env_light.mRainCount);
                    }
                    else {
                      g_env_light.mRainCount = g_env_light.mRainCount + -1;
                      d_kankyo_wether::dKyw_rain_set(g_env_light.mRainCount);
                    }
                  }
                }
              }
              else {
                if (g_env_light.mDiceWeatherMode == 5) {
                  g_env_light.mThunderMode = 1;
                  goto LAB_80194710;
                }
                if (g_env_light.mDiceWeatherMode < 5) {
                  pselIdx = 1;
                  g_env_light.mThunderMode = 1;
                  dice_rain_minus();
                }
              }
            }
            if (g_env_light.mColpatWeather != pselIdx) {
              g_env_light.mColpatCurrGather = pselIdx;
              g_env_light.mColpatWeather = pselIdx;
            }
          }
        }
        else {
          g_env_light.mThunderMode = 1;
          dice_rain_minus();
          if (g_env_light.mColpatWeather != 1) {
            g_env_light.mColpatWeather = 1;
            g_env_light.mColpatCurrGather = 1;
          }
        }
      }
    }
  }
  else {
    if (g_env_light.mColpatWeather != 1) {
      g_env_light.mColpatWeather = 1;
      g_env_light.mColpatCurrGather = 1;
    }
    if (g_env_light.mRainCount < 0xfa) {
      g_env_light.mRainCount = g_env_light.mRainCount + 1;
      d_kankyo_wether::dKyw_rain_set(g_env_light.mRainCount);
    }
  }
  if ((((g_env_light.mColPatMode == 0) && (g_env_light.mColPatModeGather == 0)) &&
      (g_env_light.mColpatCurrGather != 0xff)) &&
     (g_env_light.mColpatCurr != g_env_light.mColpatCurrGather)) {
    g_env_light.mColPatBlendGather = 0_0;
  }
LAB_80194824:
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}

}

/* __thiscall dScnKy_env_light_c::drawKankyo(void) */

void __thiscall dScnKy_env_light_c::drawKankyo(dScnKy_env_light_c *this)

{
  setSunpos(this);
  SetBaseLight(this);
  setLight(this);
  d_kankyo::dKy_Itemgetcol_chg_move();
  d_kankyo::dKy_arrowcol_chg_move();
  return;
}


namespace d_kankyo {

/* __stdcall dKy_Draw(sub_kankyo__class *) */

undefined4 dKy_Draw(void)

{
  ::dScnKy_env_light_c::drawKankyo(&g_env_light);
  return 1;
}


/* __stdcall dKy_Execute(sub_kankyo__class *) */

undefined4 dKy_Execute(void)

{
  dKy_event_proc();
  ::dScnKy_env_light_c::exeKankyo(&g_env_light);
  d_kankyo_wether::dKyw_wind_set();
  return 1;
}


/* __stdcall dKy_IsDelete(sub_kankyo__class *) */

undefined4 dKy_IsDelete(void)

{
  return 1;
}


/* __stdcall dKy_Delete(sub_kankyo__class *) */

undefined4 dKy_Delete(void)

{
  plight_init();
  return 1;
}


/* __stdcall dKy_Create(void *) */

undefined4 dKy_Create(void)

{
  envcolor_init();
  g_env_light.field_0xc78 = (undefined *)0x0;
  g_env_light.field_0xc44 = (undefined *)1_0;
  g_env_light.mPLightNearPlayer.x = 0_0;
  g_env_light.mPLightNearPlayer.y = 0_0;
  g_env_light.mPLightNearPlayer.z = 0_0;
  dKy_setLight_init();
  d_kankyo_rain::dKy_wave_chan_init();
  dKy_event_init();
  dKy_Sound_init();
  d_kankyo_wether::dKyw_wind_set();
  return 4;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x80194bb4) */
/* WARNING: Removing unreachable block (ram,0x80194bac) */
/* WARNING: Removing unreachable block (ram,0x80194bbc) */
/* __stdcall dKy_setLight_init(void) */

void dKy_setLight_init(void)

{
  _GXDistAttnFn *p_Var1;
  undefined4 *puVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  undefined4 uVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  GXSpotFn GVar21;
  float fVar22;
  float fVar23;
  _GXDistAttnFn _Var24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  int iVar33;
  int iVar34;
  _GXDistAttnFn _Var35;
  undefined4 uVar36;
  _GXDistAttnFn *p_Var37;
  undefined4 *puVar38;
  _GXDistAttnFn *p_Var39;
  undefined4 *puVar40;
  int iVar41;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined4 local_d4;
  undefined4 local_d0 [15];
  _GXDistAttnFn _Stack148;
  _GXDistAttnFn local_90 [14];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar32 = lightStatusBase._228_4_;
  uVar31 = lightStatusBase._224_4_;
  uVar30 = lightStatusBase._220_4_;
  uVar29 = lightStatusBase._216_4_;
  uVar28 = lightStatusBase._148_4_;
  uVar27 = lightStatusBase._144_4_;
  uVar26 = lightStatusBase._140_4_;
  uVar25 = lightStatusBase._136_4_;
  _Var24 = lightStatusBase.mDistAttnFn;
  fVar23 = lightStatusBase.mRefBrightness;
  fVar22 = lightStatusBase.mRefDistance;
  GVar21 = lightStatusBase.mSpotFn;
  fVar20 = lightStatusBase.mSpotCutoff;
  fVar19 = lightStatusBase.mLightDir.z;
  fVar18 = lightStatusBase.mLightDir.y;
  fVar17 = lightStatusBase.mLightDir.x;
  fVar16 = lightStatusBase.mLightK[2];
  fVar15 = lightStatusBase.mLightK[1];
  fVar14 = lightStatusBase.mLightK[0];
  fVar13 = lightStatusBase.mLightA[2];
  fVar12 = lightStatusBase.mLightA[1];
  fVar11 = lightStatusBase.mLightA[0];
  iVar10 = lightStatusBase.mAttnType;
  uVar9 = lightStatusBase.mColor;
  fVar8 = lightStatusBase.mPos2.z;
  fVar7 = lightStatusBase.mPos2.y;
  fVar6 = lightStatusBase.mPos2.x;
  fVar5 = lightStatusBase.mPos.z;
  fVar4 = lightStatusBase.mPos.y;
  fVar3 = lightStatusBase.mPos.x;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  iVar33 = 0;
  iVar34 = 0;
  p_Var39 = &_Stack148;
  p_Var37 = &lightStatusBase.mDistAttnFn;
  iVar41 = 6;
  do {
    p_Var1 = p_Var37 + 1;
    p_Var37 = p_Var37 + 2;
    _Var35 = *p_Var37;
    p_Var39[1] = *p_Var1;
    p_Var39 = p_Var39 + 2;
    *p_Var39 = _Var35;
    iVar41 = iVar41 + -1;
  } while (iVar41 != 0);
  puVar40 = &local_d4;
  puVar38 = (undefined4 *)&lightStatusBase.field_0x94;
  iVar41 = 8;
  do {
    puVar2 = puVar38 + 1;
    puVar38 = puVar38 + 2;
    uVar36 = *puVar38;
    puVar40[1] = *puVar2;
    puVar40 = puVar40 + 2;
    *puVar40 = uVar36;
    iVar41 = iVar41 + -1;
  } while (iVar41 != 0);
  do {
    *(float *)((int)lightStatusData[0].mLightA + iVar34 + -0x20) = fVar3;
    *(float *)((int)lightStatusData[0].mLightA + iVar34 + -0x1c) = fVar4;
    *(float *)((int)lightStatusData[0].mLightA + iVar34 + -0x18) = fVar5;
    *(float *)((int)lightStatusData[0].mLightA + iVar34 + -0x14) = fVar6;
    *(float *)((int)lightStatusData[0].mLightA + iVar34 + -0x10) = fVar7;
    *(float *)((int)lightStatusData[0].mLightA + iVar34 + -0xc) = fVar8;
    *(undefined4 *)((int)lightStatusData[0].mLightA + iVar34 + -8) = uVar9;
    *(int *)((int)lightStatusData[0].mLightA + iVar34 + -4) = iVar10;
    *(float *)((int)lightStatusData[0].mLightA + iVar34) = fVar11;
    *(float *)((int)lightStatusData[0].mLightA + iVar34 + 4) = fVar12;
    *(float *)((int)lightStatusData[0].mLightA + iVar34 + 8) = fVar13;
    *(float *)((int)lightStatusData[0].mLightK + iVar34) = fVar14;
    *(float *)((int)lightStatusData[0].mLightK + iVar34 + 4) = fVar15;
    *(float *)((int)lightStatusData[0].mLightK + iVar34 + 8) = fVar16;
    *(float *)((int)lightStatusData[0].mLightK + iVar34 + 0xc) = fVar17;
    *(float *)((int)lightStatusData[0].mLightK + iVar34 + 0x10) = fVar18;
    *(float *)((int)lightStatusData[0].mLightK + iVar34 + 0x14) = fVar19;
    *(float *)((int)lightStatusData[0].mLightK + iVar34 + 0x18) = fVar20;
    *(GXSpotFn *)((int)lightStatusData[0].mLightK + iVar34 + 0x1c) = GVar21;
    *(float *)((int)lightStatusData[0].mLightK + iVar34 + 0x20) = fVar22;
    *(float *)((int)lightStatusData[0].mLightK + iVar34 + 0x24) = fVar23;
    *(_GXDistAttnFn *)((int)lightStatusData[0].mLightK + iVar34 + 0x28) = _Var24;
    p_Var39 = (_GXDistAttnFn *)((int)lightStatusData[0].mLightK + iVar34 + 0x28);
    p_Var37 = &_Stack148;
    iVar41 = 6;
    do {
      p_Var1 = p_Var37 + 1;
      p_Var37 = p_Var37 + 2;
      _Var35 = *p_Var37;
      p_Var39[1] = *p_Var1;
      p_Var39 = p_Var39 + 2;
      *p_Var39 = _Var35;
      iVar41 = iVar41 + -1;
    } while (iVar41 != 0);
    *(undefined4 *)((int)lightStatusData[0].mLightK + iVar34 + 0x5c) = uVar25;
    *(undefined4 *)((int)lightStatusData[0].mLightK + iVar34 + 0x60) = uVar26;
    *(undefined4 *)((int)lightStatusData[0].mLightK + iVar34 + 100) = uVar27;
    *(undefined4 *)((int)lightStatusData[0].mLightK + iVar34 + 0x68) = uVar28;
    puVar40 = (undefined4 *)((int)lightStatusData[0].mLightK + iVar34 + 0x68);
    puVar38 = &local_d4;
    iVar41 = 8;
    do {
      puVar2 = puVar38 + 1;
      puVar38 = puVar38 + 2;
      uVar36 = *puVar38;
      puVar40[1] = *puVar2;
      puVar40 = puVar40 + 2;
      *puVar40 = uVar36;
      iVar41 = iVar41 + -1;
    } while (iVar41 != 0);
    *(undefined4 *)(&lightStatusData[0].field_0xd8 + iVar34) = uVar29;
    *(undefined4 *)(&lightStatusData[0].field_0xdc + iVar34) = uVar30;
    *(undefined4 *)(&lightStatusData[0].field_0xe0 + iVar34) = uVar31;
    *(undefined4 *)(&lightStatusData[0].field_0xe4 + iVar34) = uVar32;
    iVar33 = iVar33 + 1;
    iVar34 = iVar34 + 0xe8;
  } while (iVar33 < 8);
  __psq_l0(auStack8,0);
  __psq_l1(auStack8,0);
  __psq_l0(auStack24,0);
  __psq_l1(auStack24,0);
  __psq_l0(auStack40,0);
  __psq_l1(auStack40,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x8019512c) */
/* __stdcall dKy_setLight(void) */

void dKy_setLight(void)

{
  camera_class *pcVar1;
  daPy_lk_c *pdVar2;
  float target;
  dKy_setLight__Status *pdVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  undefined8 in_f31;
  float fVar11;
  _GXColor local_104;
  cXyz local_100;
  cXyz local_f4;
  cXyz local_e8;
  cXyz local_dc;
  TVec3_float_ local_d0;
  cXyz vectle;
  _GXLightObj light;
  MTX34 invTxpose;
  longlong local_38;
  undefined auStack8 [8];
  dKy_setLight__Status *pLightStatus;
  
  pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  pcVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  d_kankyo_rain::dKyr_get_vectle_calc
            (&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos,
             &(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mCenterPos,&vectle
            );
  pLightStatus = lightStatusPt;
  (lightStatusPt->mPos2).x = (pcVar1->mEyePos).x;
  (pLightStatus->mPos2).y = (pcVar1->mEyePos).y;
  (pLightStatus->mPos2).z = (pcVar1->mEyePos).z;
  if (pdVar2 != (daPy_lk_c *)0x0) {
    local_dc.x = (pdVar2->parent).parent.mCurrent.mPos.x;
    local_dc.y = (pdVar2->parent).parent.mCurrent.mPos.y;
    local_dc.z = (pdVar2->parent).parent.mCurrent.mPos.z;
    dKy_light_influence_id(&local_dc,0);
  }
  target = g_env_light.mBaseLightInfluence.mPos.z;
  fVar11 = g_env_light.mBaseLightInfluence.mPos.y;
  g_env_light.mSunPos2.x = g_env_light.mSunPos.x;
  g_env_light.mSunPos2.y = g_env_light.mSunPos.y;
  g_env_light.mSunPos2.z = g_env_light.mSunPos.z;
  SComponent::cLib_addCalc
            ((float *)lightStatusPt,g_env_light.mBaseLightInfluence.mPos.x,_5474,_6332,_6333);
  SComponent::cLib_addCalc(&(lightStatusPt->mPos).y,fVar11,_5474,_6332,_6333);
  SComponent::cLib_addCalc(&(lightStatusPt->mPos).z,target,_5474,_6332,_6333);
  if (init_6207 == '\0') {
    target_6206 = _5472;
    init_6207 = '\x01';
  }
  fVar11 = 1_0;
  if ((pdVar2 != (daPy_lk_c *)0x0) && (fVar11 = 0_0, 0_0 < g_env_light.mBaseLightInfluence.mPower))
  {
    fVar11 = mtx::PSVECSquareDistance
                       (&g_env_light.mBaseLightInfluence.mPos,&(pdVar2->parent).parent.mCurrent.mPos
                       );
    dVar9 = (double)fVar11;
    if ((double)0_0 < dVar9) {
      dVar8 = 1.0 / SQRT(dVar9);
      dVar8 = _4591 * dVar8 * (_4592 - dVar9 * dVar8 * dVar8);
      dVar8 = _4591 * dVar8 * (_4592 - dVar9 * dVar8 * dVar8);
      dVar9 = (double)(float)(dVar9 * _4591 * dVar8 * (_4592 - dVar9 * dVar8 * dVar8));
    }
    fVar11 = (float)(dVar9 / (double)g_env_light.mBaseLightInfluence.mPower);
  }
  if (1000_0 <= g_env_light.mBaseLightInfluence.mFluctuation) {
    target_6206 = g_env_light.mBaseLightInfluence.mFluctuation - 1000_0;
  }
  else {
    if (1_0 < fVar11) {
      fVar11 = 1_0;
    }
    fVar11 = _6334 * (1_0 - fVar11);
    if (1_0 < fVar11) {
      fVar11 = 1_0;
    }
    dVar9 = (double)(_5472 - (g_env_light.mBaseLightInfluence.mFluctuation / _5473) * fVar11);
    fVar11 = SComponent::cM_rndF(1_0);
    SComponent::cLib_addCalc2
              (&target_6206,(float)(dVar9 + (double)((float)((double)_5472 - dVar9) * fVar11)),_6335
               ,_6334);
  }
  local_38 = (longlong)(int)target_6206;
  (lightStatusPt->mColor).r = (u8)(int)target_6206;
  g_env_light.mPLightNearPlayer.x = (lightStatusPt->mPos).x;
  g_env_light.mPLightNearPlayer.y = (lightStatusPt->mPos).y;
  g_env_light.mPLightNearPlayer.z = (lightStatusPt->mPos).z;
  if (pdVar2 == (daPy_lk_c *)0x0) {
    iVar4 = -1;
  }
  else {
    local_e8.x = (pdVar2->parent).parent.mCurrent.mPos.x;
    local_e8.y = (pdVar2->parent).parent.mCurrent.mPos.y;
    local_e8.z = (pdVar2->parent).parent.mCurrent.mPos.z;
    iVar4 = dKy_eflight_influence_id(&local_e8,0);
  }
  if (iVar4 < 0) {
    lightMask = 1;
  }
  else {
    if (init_6226 == 0) {
      target_6225 = _5472;
      init_6226 = 1;
    }
    lightMask = 3;
    dKy_eflight_influence_pos(&local_f4,iVar4);
    pdVar3 = lightStatusPt;
    lightStatusPt[1].mPos.x = local_f4.x;
    pdVar3[1].mPos.y = local_f4.y;
    pdVar3[1].mPos.z = local_f4.z;
    dVar9 = (double)dKy_eflight_influence_power(iVar4);
    fVar11 = 1_0;
    if ((double)0_0 < dVar9) {
      local_100.x = (pcVar1->mEyePos).x;
      local_100.y = (pcVar1->mEyePos).y;
      local_100.z = (pcVar1->mEyePos).z;
      dVar8 = (double)dKy_eflight_influence_distance(&local_100,iVar4);
      fVar11 = (float)(dVar8 / dVar9);
    }
    dVar9 = (double)fVar11;
    dVar8 = (double)dKy_eflight_influence_yuragi(iVar4);
    if ((double)1000_0 <= dVar8) {
      target_6225 = (float)(dVar8 - (double)1000_0);
    }
    else {
      if ((double)1_0 < dVar9) {
        dVar9 = (double)1_0;
      }
      dVar10 = (double)1_0;
      dVar9 = (double)(_6334 * (float)(dVar10 - dVar9));
      if (dVar10 < dVar9) {
        dVar9 = dVar10;
      }
      dVar9 = (double)(_5472 - (float)(dVar8 * dVar9));
      fVar11 = SComponent::cM_rndF(1_0);
      SComponent::cLib_addCalc2
                (&target_6225,(float)(dVar9 + (double)((float)((double)_5472 - dVar9) * fVar11)),
                 _5479,_6334);
    }
    local_38 = (longlong)(int)target_6225;
    lightStatusPt[1].mColor.g = (u8)(int)target_6225;
    lightStatusPt[1].mColor.r = 0;
    lightStatusPt[1].mColor.b = 0;
  }
  m_Do_mtx::mDoMtx_inverseTranspose(&J3DGraphBase::j3dSys.mCurViewMtx,&invTxpose);
  iVar4 = 0;
  iVar6 = 0;
  iVar5 = 0;
  do {
    if ((lightMask & *(ushort *)((int)&lightMaskData + iVar5)) != 0) {
      mtx::PSMTXMultVec(&J3DGraphBase::j3dSys.mCurViewMtx,
                        (cXyz *)((int)lightStatusData[0].mLightA + iVar6 + -0x20),(cXyz *)&local_d0)
      ;
      gx::GXInitLightPos((double)local_d0.x,(double)local_d0.y,(double)local_d0.z,&light);
      if (iVar4 == 0) {
        mtx::PSMTXMultVec(&invTxpose,(cXyz *)((int)lightStatusData[0].mLightK + iVar6 + 0xc),
                          (cXyz *)&g_env_light.mLightDir);
        gx::GXInitLightDir((double)g_env_light.mLightDir.x,(double)g_env_light.mLightDir.y,
                           (double)g_env_light.mLightDir.z,&light);
      }
      else {
        mtx::PSMTXMultVec(&invTxpose,(cXyz *)((int)lightStatusData[0].mLightK + iVar6 + 0xc),
                          (cXyz *)&local_d0);
        gx::GXInitLightDir((double)local_d0.x,(double)local_d0.y,(double)local_d0.z,&light);
      }
      local_104 = *(_GXColor *)((int)lightStatusData[0].mLightA + iVar6 + -8);
      gx::GXInitLightColor(&light,&local_104);
      if (*(int *)((int)lightStatusData[0].mLightA + iVar6 + -4) == 0) {
        gx::GXInitLightAttn(&light,(double)*(float *)((int)lightStatusData[0].mLightA + iVar6),
                            (double)*(float *)((int)lightStatusData[0].mLightA + iVar6 + 4),
                            (double)*(float *)((int)lightStatusData[0].mLightA + iVar6 + 8),
                            (double)*(float *)((int)lightStatusData[0].mLightK + iVar6),
                            (double)*(float *)((int)lightStatusData[0].mLightK + iVar6 + 4),
                            (double)*(float *)((int)lightStatusData[0].mLightK + iVar6 + 8));
      }
      else {
        gx::GXInitLightDistAttn
                  (&light,*(float *)((int)lightStatusData[0].mLightK + iVar6 + 0x20),
                   *(float *)((int)lightStatusData[0].mLightK + iVar6 + 0x24),
                   *(GXDistAttnFn *)((int)lightStatusData[0].mLightK + iVar6 + 0x28));
        gx::GXInitLightSpot(&light,*(float *)((int)lightStatusData[0].mLightK + iVar6 + 0x18),
                            *(GXSpotFn *)((int)lightStatusData[0].mLightK + iVar6 + 0x1c));
      }
      gx::GXLoadLightObjImm(&light,(uint)*(ushort *)((int)&lightMaskData + iVar5));
    }
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 0xe8;
    iVar5 = iVar5 + 2;
  } while (iVar4 < 8);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* __stdcall dKy_setLight_again(void) */

void dKy_setLight_again(void)

{
  _GXColor local_88;
  cXyz local_84;
  _GXLightObj _Stack120;
  MTX34 MStack56;
  
  m_Do_mtx::mDoMtx_inverseTranspose(&J3DGraphBase::j3dSys.mCurViewMtx,&MStack56);
  mtx::PSMTXMultVec(&J3DGraphBase::j3dSys.mCurViewMtx,(cXyz *)lightStatusData,&local_84);
  gx::GXInitLightPos((double)local_84.x,(double)local_84.y,(double)local_84.z,&_Stack120);
  mtx::PSMTXMultVec(&MStack56,(cXyz *)&lightStatusData[0].mLightDir,&local_84);
  gx::GXInitLightDir((double)local_84.x,(double)local_84.y,(double)local_84.z,&_Stack120);
  local_88 = lightStatusData[0].mColor;
  gx::GXInitLightColor(&_Stack120,&local_88);
  if (lightStatusData[0].mAttnType == 0) {
    gx::GXInitLightAttn(&_Stack120,(double)lightStatusData[0].mLightA[0],
                        (double)lightStatusData[0].mLightA[1],(double)lightStatusData[0].mLightA[2],
                        (double)lightStatusData[0].mLightK[0],(double)lightStatusData[0].mLightK[1],
                        (double)lightStatusData[0].mLightK[2]);
  }
  else {
    gx::GXInitLightDistAttn
              (&_Stack120,lightStatusData[0].mRefDistance,lightStatusData[0].mRefBrightness,
               lightStatusData[0].mDistAttnFn);
    gx::GXInitLightSpot(&_Stack120,lightStatusData[0].mSpotCutoff,lightStatusData[0].mSpotFn);
  }
  gx::GXLoadLightObjImm(&_Stack120,(uint)lightMaskData);
  return;
}


/* __stdcall dKy_Get_DifCol(void) */

undefined4 dKy_Get_DifCol(void)

{
  return 0x803e55d4;
}


/* __stdcall dKy_light_influence_pos(int) */

void dKy_light_influence_pos(cXyz *param_1,int param_2)

{
  LIGHT_INFLUENCE *pLVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  pLVar1 = g_env_light.mpPLights[param_2];
  param_1->x = (pLVar1->mPos).x;
  param_1->y = (pLVar1->mPos).y;
  param_1->z = (pLVar1->mPos).z;
  return;
}


/* __stdcall dKy_plight_near_pos(void) */

void dKy_plight_near_pos(TVec3_float_ *param_1)

{
  param_1->x = g_env_light.mPLightNearPlayer.x;
  param_1->y = g_env_light.mPLightNearPlayer.y;
  param_1->z = g_env_light.mPLightNearPlayer.z;
  return;
}


/* __stdcall dKy_plight_set(LIGHT_INFLUENCE *) */

void dKy_plight_set(LIGHT_INFLUENCE *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar2 = 200;
  do {
    if (*(LIGHT_INFLUENCE **)((int)g_env_light.mpPLights + iVar1) == param_1) {
      return;
    }
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 0;
  iVar1 = 0;
  iVar3 = 200;
  do {
    if (*(int *)((int)g_env_light.mpPLights + iVar1) == 0) {
      *(LIGHT_INFLUENCE **)((int)g_env_light.mpPLights + iVar1) = param_1;
      *(int *)(*(int *)((int)g_env_light.mpPLights + iVar1) + 0x1c) = iVar2 + 1;
      return;
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* __stdcall dKy_yuragi_ratio_set(float) */

double dKy_yuragi_ratio_set(double param_1)

{
  return (double)(1000_0 + (float)((double)_5472 * param_1));
}


/* __stdcall dKy_plight_priority_set(LIGHT_INFLUENCE *) */

void dKy_plight_priority_set(LIGHT_INFLUENCE *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar1 = 0;
  iVar3 = 200;
  do {
    if (*(int *)((int)g_env_light.mpPLights + iVar1) == 0) {
      *(LIGHT_INFLUENCE **)((int)g_env_light.mpPLights + iVar1) = param_1;
      *(int *)(*(int *)((int)g_env_light.mpPLights + iVar1) + 0x1c) = -(iVar2 + 1);
      break;
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (199 < iVar2) {
    m_Do_printf::OSReport_Warning("\nPOINTLIGHT COUNT OVER!!!\n");
  }
  return;
}


/* __stdcall dKy_plight_cut(LIGHT_INFLUENCE *) */

void dKy_plight_cut(LIGHT_INFLUENCE *param_1)

{
  int iVar1;
  
  if (param_1 == (LIGHT_INFLUENCE *)0x0) {
    return;
  }
  iVar1 = param_1->mIdx;
  if (iVar1 == 0) {
    return;
  }
  if (iVar1 < 0) {
    param_1->mIdx = -iVar1;
  }
  if (199 < param_1->mIdx + -1) {
    return;
  }
  g_env_light.mpPLights[param_1->mIdx + -1] = (LIGHT_INFLUENCE *)0x0;
  return;
}


/* __stdcall dKy_efplight_set(LIGHT_INFLUENCE *) */

void dKy_efplight_set(LIGHT_INFLUENCE *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar2 = 10;
  do {
    if (*(LIGHT_INFLUENCE **)((int)g_env_light.mpEfLights + iVar1) == param_1) {
      return;
    }
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 0;
  iVar1 = 0;
  iVar3 = 10;
  do {
    if (*(int *)((int)g_env_light.mpEfLights + iVar1) == 0) {
      *(LIGHT_INFLUENCE **)((int)g_env_light.mpEfLights + iVar1) = param_1;
      *(int *)(*(int *)((int)g_env_light.mpEfLights + iVar1) + 0x1c) = iVar2 + 1;
      return;
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* __stdcall dKy_efplight_cut(LIGHT_INFLUENCE *) */

void dKy_efplight_cut(LIGHT_INFLUENCE *param_1)

{
  int iVar1;
  
  if (param_1 == (LIGHT_INFLUENCE *)0x0) {
    return;
  }
  iVar1 = param_1->mIdx;
  if (iVar1 == 0) {
    return;
  }
  if (iVar1 + -1 < 0) {
    return;
  }
  if (9 < iVar1 + -1) {
    return;
  }
  g_env_light.mpEfLights[iVar1 + -1] = (LIGHT_INFLUENCE *)0x0;
  return;
}


/* __stdcall dKy_actor_addcol_amb_set(short,
                                      short,
                                      short,
                                      float) */

void dKy_actor_addcol_amb_set(double param_1,short param_2,short param_3,short param_4)

{
  g_env_light.mActorAddColAmb.r =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mActorAddColAmb.g =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mActorAddColAmb.b =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_4 ^ 0x80000000) - _4490) *
                 param_1);
  return;
}


/* __stdcall dKy_actor_addcol_dif_set(short,
                                      short,
                                      short,
                                      float) */

void dKy_actor_addcol_dif_set(double param_1,short param_2,short param_3,short param_4)

{
  g_env_light.mActorAddColDif.r =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mActorAddColDif.g =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mActorAddColDif.b =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_4 ^ 0x80000000) - _4490) *
                 param_1);
  return;
}


/* __stdcall dKy_bg_addcol_amb_set(short,
                                   short,
                                   short,
                                   float) */

void dKy_bg_addcol_amb_set(double param_1,short param_2,short param_3,short param_4)

{
  g_env_light.mBgAddColAmb.r =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBgAddColAmb.g =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBgAddColAmb.b =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_4 ^ 0x80000000) - _4490) *
                 param_1);
  return;
}


/* __stdcall dKy_bg_addcol_dif_set(short,
                                   short,
                                   short,
                                   float) */

void dKy_bg_addcol_dif_set(double param_1,short param_2,short param_3,short param_4)

{
  g_env_light.mBgAddColDif.r =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBgAddColDif.g =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBgAddColDif.b =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_4 ^ 0x80000000) - _4490) *
                 param_1);
  return;
}


/* __stdcall dKy_bg1_addcol_amb_set(short,
                                    short,
                                    short,
                                    float) */

void dKy_bg1_addcol_amb_set(double param_1,short param_2,short param_3,short param_4)

{
  g_env_light.mBg1AddColAmb.r =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBg1AddColAmb.g =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBg1AddColAmb.b =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_4 ^ 0x80000000) - _4490) *
                 param_1);
  return;
}


/* __stdcall dKy_bg1_addcol_dif_set(short,
                                    short,
                                    short,
                                    float) */

void dKy_bg1_addcol_dif_set(double param_1,short param_2,short param_3,short param_4)

{
  g_env_light.mBg1AddColDif.r =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBg1AddColDif.g =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBg1AddColDif.b =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_4 ^ 0x80000000) - _4490) *
                 param_1);
  return;
}


/* __stdcall dKy_bg2_addcol_amb_set(short,
                                    short,
                                    short,
                                    float) */

void dKy_bg2_addcol_amb_set(double param_1,short param_2,short param_3,short param_4)

{
  g_env_light.mBg2AddColAmb.r =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBg2AddColAmb.g =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBg2AddColAmb.b =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_4 ^ 0x80000000) - _4490) *
                 param_1);
  return;
}


/* __stdcall dKy_bg2_addcol_dif_set(short,
                                    short,
                                    short,
                                    float) */

void dKy_bg2_addcol_dif_set(double param_1,short param_2,short param_3,short param_4)

{
  g_env_light.mBg2AddColDif.r =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBg2AddColDif.g =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBg2AddColDif.b =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_4 ^ 0x80000000) - _4490) *
                 param_1);
  return;
}


/* __stdcall dKy_bg3_addcol_amb_set(short,
                                    short,
                                    short,
                                    float) */

void dKy_bg3_addcol_amb_set(double param_1,short param_2,short param_3,short param_4)

{
  g_env_light.mBg3AddColAmb.r =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBg3AddColAmb.g =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBg3AddColAmb.b =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_4 ^ 0x80000000) - _4490) *
                 param_1);
  return;
}


/* __stdcall dKy_bg3_addcol_dif_set(short,
                                    short,
                                    short,
                                    float) */

void dKy_bg3_addcol_dif_set(double param_1,short param_2,short param_3,short param_4)

{
  g_env_light.mBg3AddColDif.r =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBg3AddColDif.g =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mBg3AddColDif.b =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_4 ^ 0x80000000) - _4490) *
                 param_1);
  return;
}


/* __stdcall dKy_addcol_fog_set(short,
                                short,
                                short,
                                float) */

void dKy_addcol_fog_set(double param_1,short param_2,short param_3,short param_4)

{
  g_env_light.mAddColFog.r =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mAddColFog.g =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - _4490) *
                 param_1);
  g_env_light.mAddColFog.b =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_4 ^ 0x80000000) - _4490) *
                 param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dKy_actor_addcol_set(short,
                                  short,
                                  short,
                                  float) */

void dKy_actor_addcol_set(short param_1,short param_2,short param_3,float param_4)

{
  undefined2 in_register_0000000c;
  undefined4 uVar1;
  undefined2 in_register_00000010;
  undefined4 uVar2;
  undefined2 in_register_00000014;
  undefined4 uVar3;
  double dVar4;
  
  uVar3 = CONCAT22(in_register_00000014,param_3);
  uVar2 = CONCAT22(in_register_00000010,param_2);
  uVar1 = CONCAT22(in_register_0000000c,param_1);
  dVar4 = (double)param_4;
  dKy_actor_addcol_amb_set(dVar4);
  dKy_actor_addcol_dif_set(dVar4,uVar1,uVar2,uVar3);
  dKy_bg_addcol_amb_set(dVar4,uVar1,uVar2,uVar3);
  dKy_bg_addcol_dif_set(dVar4,uVar1,uVar2,uVar3);
  dKy_bg1_addcol_amb_set(dVar4,uVar1,uVar2,uVar3);
  dKy_bg1_addcol_dif_set(dVar4,uVar1,uVar2,uVar3);
  dKy_bg2_addcol_amb_set(dVar4,uVar1,uVar2,uVar3);
  dKy_bg2_addcol_dif_set(dVar4,uVar1,uVar2,uVar3);
  dKy_bg3_addcol_amb_set(dVar4,uVar1,uVar2,uVar3);
  dKy_bg3_addcol_dif_set(dVar4,uVar1,uVar2,uVar3);
  return;
}


/* __stdcall dKy_vrbox_addcol_sky0_set(short,
                                       short,
                                       short,
                                       float) */

void dKy_vrbox_addcol_sky0_set(short param_1,short param_2,short param_3,double param_4)

{
  g_env_light.mVrboxAddColSky0.r =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_1 ^ 0x80000000) - _4490) *
                 param_4);
  g_env_light.mVrboxAddColSky0.g =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - _4490) *
                 param_4);
  g_env_light.mVrboxAddColSky0.b =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - _4490) *
                 param_4);
  return;
}


/* __stdcall dKy_vrbox_addcol_kasumi_set(short,
                                         short,
                                         short,
                                         float) */

void dKy_vrbox_addcol_kasumi_set(short param_1,short param_2,short param_3,double param_4)

{
  g_env_light.mVrboxAddColKasumi.r =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_1 ^ 0x80000000) - _4490) *
                 param_4);
  g_env_light.mVrboxAddColKasumi.g =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - _4490) *
                 param_4);
  g_env_light.mVrboxAddColKasumi.b =
       (s16)(int)((double)(float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - _4490) *
                 param_4);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dKy_vrbox_addcol_set(short,
                                  short,
                                  short,
                                  float) */

void dKy_vrbox_addcol_set(short param_1,short param_2,short param_3,float param_4)

{
  undefined2 in_register_0000000c;
  undefined2 in_register_00000010;
  undefined2 in_register_00000014;
  double dVar1;
  
  dVar1 = (double)param_4;
  dKy_vrbox_addcol_sky0_set(param_1,param_2,param_3,dVar1);
  dKy_vrbox_addcol_kasumi_set(param_1,param_2,param_3,dVar1);
  dKy_addcol_fog_set(dVar1,CONCAT22(in_register_0000000c,param_1),
                     CONCAT22(in_register_00000010,param_2),CONCAT22(in_register_00000014,param_3));
  return;
}


/* WARNING: Removing unreachable block (ram,0x80195f1c) */
/* WARNING: Removing unreachable block (ram,0x80195f24) */
/* __stdcall dKy_fog_startendz_set(float,
                                   float,
                                   float) */

void dKy_fog_startendz_set(float param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar3 = (double)param_2;
  dVar2 = (double)param_1;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if ((param_3 < 0_0) || (1_0 < param_3)) {
    m_Do_printf::OSReport_Warning("\ndKy_fog_startendz_set ratio error!\n");
    param_3 = 0_0;
  }
  if (param_3 < _6621) {
    param_3 = 0_0;
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  g_env_light.mFogStartZ = (float)dVar2;
  g_env_light.mFogEndZ = (float)dVar3;
  g_env_light.mFogRatio = param_3;
  return;
}


/* __stdcall dKy_Itemgetcol_chg_on(void) */

void dKy_Itemgetcol_chg_on(void)

{
  if ((g_env_light.field_0xc93 != 0) && (g_env_light.field_0xc93 != 6)) {
    return;
  }
  g_env_light.field_0xc93 = 1;
  return;
}


/* __stdcall dKy_Itemgetcol_chg_off(void) */

void dKy_Itemgetcol_chg_off(void)

{
  if (g_env_light.field_0xc93 != 4) {
    return;
  }
  g_env_light.field_0xc93 = 5;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dKy_Itemgetcol_chg_move(void) */

void dKy_Itemgetcol_chg_move(void)

{
  camera_class *pcVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  cXyz local_34;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_18;
  uint uStack20;
  
  pcVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  switch(g_env_light.field_0xc93) {
  case 1:
    g_env_light._1868_2_ = 0;
    g_env_light.field_0xc93 = 2;
    break;
  case 2:
    local_28 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent
               .mPos.x;
    local_24 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent
               .mPos.y;
    local_20 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent
               .mPos.z;
    iVar2 = toon_proc_check();
    if (iVar2 == 0) {
      iVar2 = 23000;
      sVar4 = 0x118;
    }
    else {
      iVar2 = 13000;
      sVar4 = -0x46;
    }
    d_kankyo_rain::dKyr_get_vectle_calc(&pcVar1->mEyePos,&pcVar1->mCenterPos,&local_34);
    iVar3 = SComponent::cM_atan2s(local_34.x,local_34.z);
    iVar2 = (int)(iVar3 - iVar2 & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
    local_34.x = *JKernel::JMath::jmaCosTable * JKernel::JMath::jmaSinTable[iVar2];
    local_34.y = *JKernel::JMath::jmaSinTable;
    local_34.z = *JKernel::JMath::jmaCosTable * JKernel::JMath::jmaCosTable[iVar2];
    g_env_light._1856_4_ = local_28 + _6694 * local_34.x;
    g_env_light._1864_4_ = local_20 + _6694 * local_34.z;
    uStack20 = (int)sVar4 ^ 0x80000000;
    local_18 = 0x43300000;
    g_env_light._1860_4_ = local_24 + (float)((double)CONCAT44(0x43300000,uStack20) - _4490);
    g_env_light._1868_2_ = 0;
    g_env_light._1870_2_ = 0;
    g_env_light._1872_2_ = 0;
    g_env_light._1876_4_ = 1000_0;
    g_env_light._1880_4_ = 0_0;
    local_28 = g_env_light._1856_4_;
    local_24 = g_env_light._1860_4_;
    local_20 = g_env_light._1864_4_;
    dKy_plight_priority_set((LIGHT_INFLUENCE *)&g_env_light.field_0x740);
    g_env_light.field_0xc93 = 3;
    break;
  case 3:
    g_env_light._1868_2_ = g_env_light._1868_2_ + 1;
    if (0x19 < g_env_light._1868_2_) {
      g_env_light.field_0xc93 = 4;
    }
    break;
  case 4:
    SComponent::cLib_addCalc(&g_env_light.field_0xc34,1_0,_5479,_6695,0_001);
    break;
  case 5:
    dKy_plight_cut((LIGHT_INFLUENCE *)&g_env_light.field_0x740);
    g_env_light.field_0xc93 = 6;
    break;
  case 6:
    SComponent::cLib_addCalc(&g_env_light.field_0xc34,0_0,_5479,_6695,0_001);
    if (g_env_light.field_0xc34 < _6696) {
      g_env_light.field_0xc34 = 0_0;
      g_env_light.field_0xc93 = 0;
    }
  }
  g_env_light.field_0xc98 = 0;
  if ((g_env_light.field_0xc93 & 7) != 0) {
    g_env_light.field_0xc98 = 1;
    dKy_actor_addcol_amb_set
              ((double)g_env_light.field_0xc34,(int)(short)(0xb4 - g_env_light.mActorC0.r),
               (int)(short)(0xb4 - g_env_light.mActorC0.g),
               (int)(short)(0xb4 - g_env_light.mActorC0.b));
    dKy_actor_addcol_dif_set((double)g_env_light.field_0xc34,0xff,0xff,0xff);
  }
  return;
}


/* __stdcall dKy_arrowcol_chg_on(cXyz *,
                                 int) */

void dKy_arrowcol_chg_on(undefined4 param_1,int param_2)

{
  if (g_env_light.field_0xc93 != 0) {
    return;
  }
  if (param_2 == 0) {
    g_env_light.field_0xc93 = 0x10;
    return;
  }
  if (param_2 == 1) {
    g_env_light.field_0xc93 = 0x20;
    return;
  }
  if (param_2 == 2) {
    g_env_light.field_0xc93 = 0x30;
    return;
  }
  g_env_light.field_0xc93 = 0x10;
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __stdcall dKy_arrowcol_chg_move(void) */

void dKy_arrowcol_chg_move(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  short unaff_r23;
  short unaff_r24;
  short unaff_r25;
  short unaff_r26;
  short unaff_r29;
  short unaff_r30;
  
  if (g_env_light.field_0xc93 == 0x40) {
LAB_80196348:
    unaff_r24 = 0xbe;
    unaff_r26 = 0x78;
    unaff_r23 = 0x78;
    unaff_r30 = 0x3c;
    unaff_r29 = 0;
    unaff_r25 = 0;
  }
  else {
    if (g_env_light.field_0xc93 < 0x40) {
      if (g_env_light.field_0xc93 == 0x20) {
LAB_80196364:
        unaff_r24 = 0x3c;
        unaff_r26 = 0x96;
        unaff_r23 = 0xe6;
        unaff_r30 = 0x32;
        unaff_r29 = 0x41;
        unaff_r25 = 0x50;
      }
      else {
        if (g_env_light.field_0xc93 < 0x20) {
          if (g_env_light.field_0xc93 == 0x10) goto LAB_80196348;
        }
        else {
          if (g_env_light.field_0xc93 == 0x30) goto LAB_80196380;
        }
      }
    }
    else {
      if (g_env_light.field_0xc93 != 0x60) {
        if ((0x5f < g_env_light.field_0xc93) || (g_env_light.field_0xc93 != 0x50))
        goto LAB_801963d4;
        goto LAB_80196364;
      }
LAB_80196380:
      unaff_r24 = 0x50;
      unaff_r26 = 0x50;
      unaff_r23 = 0x14;
      unaff_r30 = 0x1e;
      unaff_r29 = 0x1e;
      unaff_r25 = 10;
      iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"GTower");
      if (iVar4 == 0) {
        unaff_r24 = 0x45;
        unaff_r26 = 0x1b;
        unaff_r23 = 0;
        unaff_r30 = 0x74;
        unaff_r29 = 0x65;
        unaff_r25 = 0x10;
      }
    }
  }
LAB_801963d4:
  if (g_env_light.field_0xc93 != 0x40) {
    if (g_env_light.field_0xc93 < 0x40) {
      if (g_env_light.field_0xc93 != 0x20) {
        if (g_env_light.field_0xc93 < 0x20) {
          if (g_env_light.field_0xc93 != 0x10) goto LAB_80196494;
        }
        else {
          if (g_env_light.field_0xc93 != 0x30) goto LAB_80196494;
        }
      }
      SComponent::cLib_addCalc(&g_env_light.field_0xc34,1_0,_5479,_6695,0_001);
      if (1_0 <= g_env_light.field_0xc34) {
        g_env_light.field_0xc93 = g_env_light.field_0xc93 + 0x30;
      }
      goto LAB_80196494;
    }
    if ((g_env_light.field_0xc93 != 0x60) &&
       ((0x5f < g_env_light.field_0xc93 || (g_env_light.field_0xc93 != 0x50)))) goto LAB_80196494;
  }
  SComponent::cLib_addCalc(&g_env_light.field_0xc34,0_0,_5479,_6798,0_001);
  if (g_env_light.field_0xc34 < _6696) {
    g_env_light.field_0xc34 = 0_0;
    g_env_light.field_0xc93 = 0;
  }
LAB_80196494:
  if ((g_env_light.field_0xc93 & 0xf0) != 0) {
    dKy_actor_addcol_amb_set
              ((double)g_env_light.field_0xc34,(int)(short)(unaff_r24 - g_env_light.mActorC0.r),
               (int)(short)(unaff_r26 - g_env_light.mActorC0.g),
               (int)(short)(unaff_r23 - g_env_light.mActorC0.b));
    dKy_bg_addcol_amb_set
              ((double)g_env_light.field_0xc34,(int)(short)(unaff_r24 - g_env_light.mBG0_C0.r),
               (int)(short)(unaff_r26 - g_env_light.mBG0_C0.g),
               (int)(short)(unaff_r23 - g_env_light.mBG0_C0.b));
    iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"GTower");
    if (iVar4 != 0) {
      dKy_bg1_addcol_amb_set
                ((double)g_env_light.field_0xc34,(int)(short)(unaff_r24 - g_env_light.mBG1_C0.r),
                 (int)(short)(unaff_r26 - g_env_light.mBG1_C0.g),
                 (int)(short)(unaff_r23 - g_env_light.mBG1_C0.b));
    }
    dKy_bg2_addcol_amb_set
              ((double)g_env_light.field_0xc34,(int)(short)(unaff_r24 - g_env_light.mBG2_C0.r),
               (int)(short)(unaff_r26 - g_env_light.mBG2_C0.g),
               (int)(short)(unaff_r23 - g_env_light.mBG2_C0.b));
    sVar1 = unaff_r24 - g_env_light.mBG3_C0.r;
    sVar2 = unaff_r26 - g_env_light.mBG3_C0.g;
    sVar3 = unaff_r23 - g_env_light.mBG3_C0.b;
    iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"GTower");
    if (iVar4 == 0) {
      sVar1 = 0xb7 - g_env_light.mBG3_C0.r;
      sVar2 = 0xb0 - g_env_light.mBG3_C0.g;
      sVar3 = 0x88 - g_env_light.mBG3_C0.b;
    }
    dKy_bg3_addcol_amb_set((double)g_env_light.field_0xc34,(int)sVar1,(int)sVar2,(int)sVar3);
    dKy_actor_addcol_dif_set
              ((double)g_env_light.field_0xc34,(int)(short)(unaff_r30 - g_env_light.mActorK0.r),
               (int)(short)(unaff_r29 - g_env_light.mActorK0.g),
               (int)(short)(unaff_r25 - g_env_light.mActorK0.b));
    dKy_bg_addcol_dif_set
              ((double)g_env_light.field_0xc34,(int)(short)(unaff_r30 - g_env_light.mBG0_K0.r),
               (int)(short)(unaff_r29 - g_env_light.mBG0_K0.g),
               (int)(short)(unaff_r25 - g_env_light.mBG0_K0.b));
    iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"GTower");
    if (iVar4 != 0) {
      dKy_bg1_addcol_dif_set
                ((double)g_env_light.field_0xc34,(int)(short)(unaff_r30 - g_env_light.mBG1_K0.r),
                 (int)(short)(unaff_r29 - g_env_light.mBG1_K0.g),
                 (int)(short)(unaff_r25 - g_env_light.mBG1_K0.b));
    }
    dKy_bg2_addcol_dif_set
              ((double)g_env_light.field_0xc34,(int)(short)(unaff_r30 - g_env_light.mBG2_K0.r),
               (int)(short)(unaff_r29 - g_env_light.mBG2_K0.g),
               (int)(short)(unaff_r25 - g_env_light.mBG2_K0.b));
    sVar1 = unaff_r30 - g_env_light.mBG3_K0.r;
    sVar2 = unaff_r29 - g_env_light.mBG3_K0.g;
    sVar3 = unaff_r25 - g_env_light.mBG3_K0.b;
    iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"GTower");
    if (iVar4 == 0) {
      sVar1 = 0x8a - g_env_light.mBG3_C0.r;
      sVar2 = 0x8a - g_env_light.mBG3_C0.g;
      sVar3 = 0x44 - g_env_light.mBG3_C0.b;
    }
    dKy_bg3_addcol_dif_set((double)g_env_light.field_0xc34,(int)sVar1,(int)sVar2,(int)sVar3);
  }
  return;
}


/* __stdcall dKy_checkEventNightStop(void) */

undefined4 dKy_checkEventNightStop(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xa02);
  if ((iVar1 == 0) ||
     (iVar1 = dSv_player_collect_c::isSymbol
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0'),
     iVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


/* __stdcall dKy_Sound_init(void) */

void dKy_Sound_init(void)

{
  g_env_light._2356_4_ = _6815;
  g_env_light._2360_4_ = _6815;
  g_env_light._2364_4_ = _6815;
  g_env_light._2368_4_ = 0;
  g_env_light._2372_4_ = 0;
  g_env_light._2376_4_ = 0xffffffff;
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x80196988) */
/* __stdcall dKy_Sound_set(cXyz,
                           int,
                           unsigned int,
                           int) */

void dKy_Sound_set(cXyz *param_1,int param_2,uint param_3,int param_4)

{
  bool bVar1;
  camera_class *pcVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  float fVar7;
  undefined auStack8 [8];
  
  pcVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  bVar1 = false;
  fVar7 = mtx::PSVECSquareDistance
                    (param_1,&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->
                              mEyePos);
  dVar6 = (double)fVar7;
  if ((double)0_0 < dVar6) {
    dVar4 = 1.0 / SQRT(dVar6);
    dVar4 = _4591 * dVar4 * (_4592 - dVar6 * dVar4 * dVar4);
    dVar4 = _4591 * dVar4 * (_4592 - dVar6 * dVar4 * dVar4);
    dVar6 = (double)(float)(dVar6 * _4591 * dVar4 * (_4592 - dVar6 * dVar4 * dVar4));
  }
  fVar7 = mtx::PSVECSquareDistance((cXyz *)&g_env_light.field_0x934,&pcVar2->mEyePos);
  dVar4 = (double)fVar7;
  if ((double)0_0 < dVar4) {
    dVar5 = 1.0 / SQRT(dVar4);
    dVar5 = _4591 * dVar5 * (_4592 - dVar4 * dVar5 * dVar5);
    dVar5 = _4591 * dVar5 * (_4592 - dVar4 * dVar5 * dVar5);
    dVar4 = (double)(float)(dVar4 * _4591 * dVar5 * (_4592 - dVar4 * dVar5 * dVar5));
  }
  if (dVar6 < dVar4) {
    if ((double)_6855 <= dVar4) {
      if (g_env_light._2368_4_ < param_2) {
        bVar1 = true;
      }
    }
    else {
      bVar1 = true;
    }
  }
  if (bVar1) {
    g_env_light._2356_4_ = param_1->x;
    g_env_light._2360_4_ = param_1->y;
    g_env_light._2364_4_ = param_1->z;
    g_env_light._2368_4_ = param_2;
    g_env_light._2372_4_ = param_4;
    g_env_light._2376_4_ = param_3;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __stdcall dKy_Sound_get(void) */

undefined4 dKy_Sound_get(void)

{
  return 0x803e53e8;
}


/* __stdcall dKy_SordFlush_set(cXyz,
                               int) */

void dKy_SordFlush_set(cXyz *pPos,int param_2)

{
  if (g_env_light.mSwordState == 0) {
    g_env_light.mSwordState = 1;
    g_env_light.mSwordLightType = param_2;
    g_env_light.mSwordLight.mPos.x = pPos->x;
    g_env_light.mSwordLight.mPos.y = pPos->y;
    g_env_light.mSwordLight.mPos.z = pPos->z;
    return;
  }
  if (g_env_light.mSwordState != 2) {
    return;
  }
  g_env_light.mSwordState = 4;
  return;
}


/* __stdcall dKy_FirstlightVec_get(cXyz *) */

void dKy_FirstlightVec_get(float *param_1,float *param_2)

{
  float fVar1;
  
  fVar1 = 0_0;
  *param_2 = 0_0;
  param_2[1] = fVar1;
  param_2[2] = fVar1;
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  return;
}


/* __stdcall GxFogSet_Sub(_GXColor *) */

void GxFogSet_Sub(_GXColor *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  _GXColor local_8;
  _GXColor local_4;
  
  local_8 = *param_1;
  fVar3 = 1_0;
  fVar4 = _6906;
  if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
    fVar1 = (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mNearPlane;
    if (((0_0 <= fVar1) &&
        (fVar2 = (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mFarPlane, 0_0 <= fVar2))
       && (fVar1 < fVar2)) {
      fVar3 = fVar1;
      fVar4 = fVar2;
    }
  }
  local_4 = local_8;
  gx::GXSetFog(GX_FOG_PERSP_LIN,g_env_light.mFogStartZ__setLight,g_env_light.mFogEndZ__setLight,
               fVar3,fVar4,&local_8);
  return;
}


/* __stdcall GxFog_set(void) */

void GxFog_set(void)

{
  undefined local_8;
  undefined local_7;
  undefined local_6;
  
  local_8 = (undefined)g_env_light.mFogColor.r;
  local_7 = (undefined)g_env_light.mFogColor.g;
  local_6 = (undefined)g_env_light.mFogColor.b;
  GxFogSet_Sub(&local_8);
  return;
}


/* __stdcall GxFog_sea_set(void) */

void GxFog_sea_set(void)

{
  undefined local_8;
  undefined local_7;
  undefined local_6;
  
  local_8 = (undefined)g_env_light.mVrUsoUmiColor.r;
  local_7 = (undefined)g_env_light.mVrUsoUmiColor.g;
  local_6 = (undefined)g_env_light.mVrUsoUmiColor.b;
  GxFogSet_Sub(&local_8);
  return;
}


/* __stdcall dKy_GxFog_set(void) */

void dKy_GxFog_set(void)

{
  GxFog_set();
  GxXFog_set();
  return;
}


/* __stdcall dKy_GxFog_sea_set(void) */

void dKy_GxFog_sea_set(void)

{
  GxFog_sea_set();
  GxXFog_set();
  return;
}


/* __stdcall dKy_GxFog_tevstr_set(dKy_tevstr_c *) */

void dKy_GxFog_tevstr_set(dKy_tevstr_c *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  _GXColor local_8;
  _GXColor local_4;
  
  local_8 = (_GXColor)
            CONCAT22((param_1->mFogColor).g & 0xffU | (param_1->mFogColor).r << 8,
                     CONCAT11((char)(param_1->mFogColor).b,local_4.a));
  fVar3 = 1_0;
  fVar4 = _6906;
  if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
    fVar1 = (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mNearPlane;
    if (((0_0 <= fVar1) &&
        (fVar2 = (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mFarPlane, 0_0 <= fVar2))
       && (fVar1 < fVar2)) {
      fVar3 = fVar1;
      fVar4 = fVar2;
    }
  }
  local_4 = local_8;
  gx::GXSetFog(GX_FOG_PERSP_LIN,param_1->mFogStartZ,param_1->mFogEndZ,fVar3,fVar4,&local_8);
  GxXFog_set();
  return;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __stdcall dKy_GfFog_tevstr_set(dKy_tevstr_c *) */

void dKy_GfFog_tevstr_set(dKy_tevstr_c *param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined4 local_8;
  undefined4 local_4;
  
  dVar3 = (double)1_0;
  dVar4 = (double)_6906;
  local_8 = CONCAT22((param_1->mFogColor).g & 0xffU | (param_1->mFogColor).r << 8,
                     CONCAT11((char)(param_1->mFogColor).b,(undefined)local_4));
  if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
    dVar2 = (double)(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mNearPlane;
    if ((((double)0_0 <= dVar2) &&
        (dVar1 = (double)(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mFarPlane,
        (double)0_0 <= dVar1)) && (dVar2 < dVar1)) {
      dVar3 = dVar2;
      dVar4 = dVar1;
    }
  }
  local_4 = local_8;
  gf::GFSetFog((double)param_1->mFogStartZ,(double)param_1->mFogEndZ,dVar3,dVar4,2,&local_8);
  GxXFog_set();
  return;
}


/* __stdcall GxXFog_set(void) */

void GxXFog_set(void)

{
  d_kankyo_data::dKyd_xfog_table_set(g_env_light.mFogAdjTableType);
  gx::GXSetFogRangeAdj
            ((bool)g_env_light.mFogAdjEnable,g_env_light.mFogAdjCenter,&g_env_light.mFogAdjTable);
  return;
}


/* __stdcall dKy_change_colset(unsigned char,
                               unsigned char,
                               float) */

void dKy_change_colset(byte param_1,byte param_2,float param_3)

{
  if (g_env_light.mColpatCurr == param_2) {
    g_env_light.mColpatCurrGather = param_2;
    return;
  }
  g_env_light.mColPatBlendGather = 0_0;
  g_env_light.mColpatCurrGather = param_2;
  return;
}


/* __stdcall dKy_change_colpat(unsigned char) */

void dKy_change_colpat(byte param_1)

{
  if (g_env_light.mColpatCurr == param_1) {
    g_env_light.mColpatCurrGather = param_1;
    return;
  }
  g_env_light.mColPatBlendGather = 0_0;
  g_env_light.mColpatCurrGather = param_1;
  return;
}


/* __stdcall dKy_custom_colset(unsigned char,
                               unsigned char,
                               float) */

void dKy_custom_colset(byte param_1,byte param_2,float blend)

{
  g_env_light.mColpatPrevGather = param_2;
  if (blend < 1_0) {
    g_env_light.mColpatPrevGather = param_1;
  }
  g_env_light.mColPatBlendGather = blend;
  g_env_light.mColpatCurrGather = param_2;
  g_env_light.mColPatModeGather = 1;
  return;
}


/* __stdcall dKy_custom_timeset(float) */

void dKy_custom_timeset(float param_1)

{
  g_env_light.mTimeAdv = param_1;
  return;
}


/* __stdcall dKy_setLight_mine(dKy_tevstr_c *) */

void dKy_setLight_mine(dKy_tevstr_c *param_1)

{
  int iVar1;
  _GXColor local_58;
  _GXLightObj _Stack84;
  
  iVar1 = toon_proc_check();
  if (iVar1 == 0) {
    gx::GXInitLightPos((double)(param_1->mLightObj).mPos.x,(double)(param_1->mLightObj).mPos.y,
                       (double)(param_1->mLightObj).mPos.z,&_Stack84);
  }
  else {
    gx::GXInitLightPos(-(double)(param_1->mLightObj).mPos.x,-(double)(param_1->mLightObj).mPos.y,
                       -(double)(param_1->mLightObj).mPos.z,&_Stack84);
  }
  gx::GXInitLightDir((double)(param_1->mLightObj).mDir.x,(double)(param_1->mLightObj).mDir.y,
                     (double)(param_1->mLightObj).mDir.z,&_Stack84);
  local_58 = (param_1->mLightObj).mColor;
  gx::GXInitLightColor(&_Stack84,&local_58);
  gx::GXInitLightAttn(&_Stack84,(double)(param_1->mLightObj).mCosAtten.x,
                      (double)(param_1->mLightObj).mCosAtten.y,
                      (double)(param_1->mLightObj).mCosAtten.z,
                      (double)(param_1->mLightObj).mDistAtten.x,
                      (double)(param_1->mLightObj).mDistAtten.y,
                      (double)(param_1->mLightObj).mDistAtten.z);
  gx::GXLoadLightObjImm(&_Stack84,(uint)lightMaskData);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dKy_tevstr_init(dKy_tevstr_c *,
                             signed char,
                             unsigned char) */

void dKy_tevstr_init(dKy_tevstr_c *this,char roomNo,uchar param_3)

{
  float fVar1;
  float fVar2;
  
  FUN_800033a8((int)this,0,0xb0);
  if (roomNo == -1) {
    this->mRoomNo = ::dStage_roomControl_c::mStayNo;
  }
  else {
    this->mRoomNo = roomNo;
  }
  this->mEnvrIdxCurr = this->mRoomNo;
  this->mEnvrIdxPrev = this->mRoomNo;
  this->mEnvrIdxOverride = param_3;
  this->mInitTimer = 1;
  this->mInitType = 0x7b;
  (this->mColorC0).a = 0xff;
  (this->mColorK0).a = 0xff;
  (this->mFogColor).a = 0xff;
  (this->mLightObj).mColor.g = 0;
  (this->mLightObj).mColor.b = 0;
  (this->mLightObj).mColor.a = 0xff;
  fVar2 = 1_0;
  (this->mLightObj).mCosAtten.x = 1_0;
  fVar1 = 0_0;
  (this->mLightObj).mCosAtten.y = 0_0;
  (this->mLightObj).mCosAtten.z = fVar1;
  (this->mLightObj).mDistAtten.x = fVar2;
  (this->mLightObj).mDistAtten.y = fVar1;
  (this->mLightObj).mDistAtten.z = fVar1;
  return;
}


/* __stdcall dKy_rain_check(void) */

int dKy_rain_check(void)

{
  return g_env_light.mRainCount;
}


/* __stdcall dKy_usonami_set(float) */

void dKy_usonami_set(double param_1)

{
  if (g_env_light.mWaveCount < 200) {
    g_env_light.mWaveSpawnDist = 20000_0;
    g_env_light.mWaveSpawnRadius = 22000_0;
    g_env_light.mWaveReset = 0;
    g_env_light.mWaveScale = 300_0;
    g_env_light.mWaveScaleRand = 0_001;
    g_env_light.mWaveCounterSpeedScale = 1_2;
    g_env_light.field_0x97b = 0;
    g_env_light.mWaveScaleBottom = 6_0;
    g_env_light.mWaveCount = 300;
    g_env_light.mWaveSpeed = 30_0;
  }
  g_env_light.mWaveFlatInter = (float)param_1;
  return;
}


/* __stdcall dKy_get_schbit(void) */

byte dKy_get_schbit(void)

{
  return g_env_light.mSchbit;
}


/* __stdcall dKy_get_schbit_timer(void) */

int dKy_get_schbit_timer(void)

{
  return g_env_light.mSchbitTimer;
}


/* __stdcall dKy_get_seacolor(_GXColor *,
                              _GXColor *) */

void dKy_get_seacolor(_GXColor *param_1,_GXColor *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  
  sVar1 = g_env_light.mBG1_C0.r + g_env_light.mBg1AddColAmb.r;
  sVar2 = g_env_light.mBG1_C0.g + g_env_light.mBg1AddColAmb.g;
  sVar3 = g_env_light.mBG1_C0.b + g_env_light.mBg1AddColAmb.b;
  if (sVar1 < 0) {
    sVar1 = 0;
  }
  if (sVar2 < 0) {
    sVar2 = 0;
  }
  if (sVar3 < 0) {
    sVar3 = 0;
  }
  if (0xff < sVar1) {
    sVar1 = 0xff;
  }
  if (0xff < sVar2) {
    sVar2 = 0xff;
  }
  if (0xff < sVar3) {
    sVar3 = 0xff;
  }
  param_1->r = (u8)sVar1;
  param_1->g = (u8)sVar2;
  param_1->b = (u8)sVar3;
  sVar1 = g_env_light.mBG1_K0.r + g_env_light.mBg1AddColDif.r;
  sVar2 = g_env_light.mBG1_K0.g + g_env_light.mBg1AddColDif.g;
  sVar3 = g_env_light.mBG1_K0.b + g_env_light.mBg1AddColDif.b;
  if (sVar1 < 0) {
    sVar1 = 0;
  }
  if (sVar2 < 0) {
    sVar2 = 0;
  }
  if (sVar3 < 0) {
    sVar3 = 0;
  }
  if (0xff < sVar1) {
    sVar1 = 0xff;
  }
  if (0xff < sVar2) {
    sVar2 = 0xff;
  }
  if (0xff < sVar3) {
    sVar3 = 0xff;
  }
  param_2->r = (u8)sVar1;
  param_2->g = (u8)sVar2;
  param_2->b = (u8)sVar3;
  return;
}


/* __stdcall dKy_set_allcol_ratio(float) */

void dKy_set_allcol_ratio(double param_1)

{
  g_env_light.mColorsGather.mAllColRatio = (float)param_1;
  return;
}


/* __stdcall dKy_set_actcol_ratio(float) */

void dKy_set_actcol_ratio(double param_1)

{
  g_env_light.mColorsGather.mActColRatio = (float)param_1;
  return;
}


/* __stdcall dKy_set_bgcol_ratio(float) */

void dKy_set_bgcol_ratio(double param_1)

{
  g_env_light.mColorsGather.mBgColRatio = (float)param_1;
  return;
}


/* __stdcall dKy_set_fogcol_ratio(float) */

void dKy_set_fogcol_ratio(double param_1)

{
  g_env_light.mColorsGather.mFogColRatio = (float)param_1;
  return;
}


/* __stdcall dKy_set_vrboxcol_ratio(float) */

void dKy_set_vrboxcol_ratio(double param_1)

{
  dKy_set_vrboxsoracol_ratio((float)param_1);
  dKy_set_vrboxkumocol_ratio((float)param_1);
  return;
}


/* __stdcall dKy_set_vrboxsoracol_ratio(float) */

void dKy_set_vrboxsoracol_ratio(float param_1)

{
  g_env_light.mColorsGather.mVrboxSoraColRatio = param_1;
  return;
}


/* __stdcall dKy_set_vrboxkumocol_ratio(float) */

void dKy_set_vrboxkumocol_ratio(float param_1)

{
  g_env_light.mColorsGather.mVrboxKumoColRatio = param_1;
  return;
}


/* __stdcall dKy_itudemo_se(void) */

void dKy_itudemo_se(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = ::dStage_roomControl_c::mStayNo;
  if (g_env_light.mMoyaSE != 0) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,g_env_light.mMoyaSE,(cXyz *)0x0,0,0,1_0,1_0,_1_0,_1_0,0);
  }
  iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"M_NewD2");
  if ((iVar2 == 0) && (bVar1 == 3)) {
    JAIZelBasic::bgmMuteMtDragon(JAIZelBasic::zel_basic);
  }
  iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Siren");
  if ((iVar2 == 0) && (bVar1 == 0x12)) {
    JAIZelBasic::stSkyCloisters(JAIZelBasic::zel_basic);
  }
  return;
}


/* __stdcall dKy_contrast_flg_set(unsigned char) */

void dKy_contrast_flg_set(byte param_1)

{
  g_env_light.mbContrastFlag = param_1;
  return;
}


/* __stdcall dKy_contrast_flg_get(void) */

byte dKy_contrast_flg_get(void)

{
  return g_env_light.mbContrastFlag;
}


/* __stdcall dKy_get_dayofweek(void) */

uint dKy_get_dayofweek(void)

{
  return (uint)(ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mDayOfWeek
         % 7;
}


/* __stdcall dKy_set_nexttime(float) */

void dKy_set_nexttime(double param_1)

{
  g_env_light.mNextTime = (float)param_1;
  return;
}


/* __stdcall dKy_DayProc(void) */

void dKy_DayProc(void)

{
  dKankyo_DayProc();
  return;
}


/* WARNING: Removing unreachable block (ram,0x80197360) */
/* __stdcall dKy_instant_timechg(float) */

void dKy_instant_timechg(double param_1)

{
  undefined4 uVar1;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (param_1 < (double)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime)
  {
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mDayOfWeek =
         d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mDayOfWeek + 1;
    dKankyo_DayProc();
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime = (float)param_1;
  return;
}


/* __stdcall dKy_instant_rainchg(void) */

void dKy_instant_rainchg(void)

{
  d_kankyo_wether::dKyw_rain_set(0xfa);
  g_env_light.mColpatPrev = 1;
  g_env_light.mColpatCurr = 1;
  g_env_light.mColpatWeather = 1;
  return;
}


/* __stdcall dKy_moon_type_chk(void) */

int dKy_moon_type_chk(void)

{
  int iVar1;
  
  iVar1 = dKy_get_dayofweek();
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime < 180_0) {
    if (iVar1 == 0) {
      iVar1 = 6;
    }
    else {
      iVar1 = iVar1 + -1;
    }
  }
  return iVar1;
}


/* WARNING: Removing unreachable block (ram,0x801974e8) */
/* __stdcall dKy_telescope_lookin_chk(cXyz *,
                                      float,
                                      float) */

bool dKy_telescope_lookin_chk(cXyz *param_1,float param_2,float param_3)

{
  bool bVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  float fVar6;
  cXyz local_34;
  TVec3_float_ local_28;
  undefined auStack8 [8];
  
  dVar4 = (double)param_2;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  bVar1 = false;
  if ((d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane != 0) &&
     (param_3 < (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mFovY)) {
    m_Do_lib::mDoLib_project(param_1,(cXyz *)&local_28);
    local_34.x = 320_0;
    local_34.y = 240_0;
    local_34.z = 0_0;
    fVar6 = mtx::PSVECSquareDistance(&local_34,(cXyz *)&local_28);
    dVar5 = (double)fVar6;
    if ((double)0_0 < dVar5) {
      dVar3 = 1.0 / SQRT(dVar5);
      dVar3 = _4591 * dVar3 * (_4592 - dVar5 * dVar3 * dVar3);
      dVar3 = _4591 * dVar3 * (_4592 - dVar5 * dVar3 * dVar3);
      dVar5 = (double)(float)(dVar5 * _4591 * dVar3 * (_4592 - dVar5 * dVar3 * dVar3));
    }
    if (dVar5 < dVar4) {
      bVar1 = true;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return bVar1;
}


/* __stdcall dKy_moon_look_chk(void) */

undefined dKy_moon_look_chk(void)

{
  int iVar1;
  undefined uVar2;
  
  uVar2 = 0;
  iVar1 = d_kankyo_rain::dKyr_moon_arrival_check();
  if (iVar1 != 0) {
    uVar2 = dKy_telescope_lookin_chk((cXyz *)&g_env_light.mMoonPos,100_0,_6334);
  }
  return uVar2;
}


/* __stdcall dKy_orion_look_chk(void) */

undefined dKy_orion_look_chk(void)

{
  bool bVar1;
  TVec3_float_ local_18;
  cXyz local_c;
  
  dKy_get_orion_pos(&local_18);
  local_c.x = local_18.x;
  local_c.y = local_18.y;
  local_c.z = local_18.z;
  bVar1 = dKy_telescope_lookin_chk(&local_c,100_0,_6334);
  return bVar1;
}


/* __stdcall dKy_hokuto_look_chk(void) */

undefined dKy_hokuto_look_chk(void)

{
  bool bVar1;
  float local_18;
  float local_14;
  float local_10;
  cXyz local_c;
  
  dKy_get_hokuto_pos(&local_18);
  local_c.x = local_18;
  local_c.y = local_14;
  local_c.z = local_10;
  bVar1 = dKy_telescope_lookin_chk(&local_c,100_0,_6334);
  return bVar1;
}


/* __stdcall dKy_get_moon_pos(void) */

void dKy_get_moon_pos(TVec3_float_ *param_1)

{
  param_1->x = g_env_light.mMoonPos.x;
  param_1->y = g_env_light.mMoonPos.y;
  param_1->z = g_env_light.mMoonPos.z;
  return;
}


/* __stdcall dKy_get_hokuto_pos(void) */

void dKy_get_hokuto_pos(float *param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = _7301 + ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos).y;
  fVar2 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos).z - _7302;
  *param_1 = _7300 + ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos).x
  ;
  param_1[1] = fVar1;
  param_1[2] = fVar2;
  return;
}


/* __stdcall dKy_get_orion_pos(void) */

void dKy_get_orion_pos(TVec3_float_ *param_1)

{
  float fVar1;
  float fVar2;
  
  fVar1 = _7315 + ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos).y;
  fVar2 = _7316 + ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos).z;
  param_1->x = _7314 + ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos)
                       .x;
  param_1->y = fVar1;
  param_1->z = fVar2;
  return;
}


/* __stdcall dKy_pship_existense_set(void) */

void dKy_pship_existense_set(void)

{
  g_env_light.field_0xc8e = 1;
  return;
}


/* __stdcall dKy_pship_existense_cut(void) */

void dKy_pship_existense_cut(void)

{
  g_env_light.field_0xc8e = 0;
  return;
}


/* __stdcall dKy_pship_existense_chk(void) */

undefined dKy_pship_existense_chk(void)

{
  undefined uVar1;
  
  uVar1 = phantomship_wether();
  return uVar1;
}


/* __stdcall dKy_daynighttact_stop_chk(void) */

undefined4 dKy_daynighttact_stop_chk(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = dKy_checkEventNightStop();
  if (iVar1 == 0) {
    if (g_env_light.mbDayNightTactStop != 0) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f14 */
/* WARNING: Inlined function: FUN_80328f60 */
/* __stdcall dKyr_player_overhead_bg_chk(void) */

undefined4 dKyr_player_overhead_bg_chk(void)

{
  daPy_lk_c *pdVar1;
  int iVar2;
  undefined4 uVar3;
  cBgS_PolyPassChk *pcVar4;
  double dVar5;
  cBgS_GndChk local_8c;
  cBgS_PolyPassChk local_4c;
  cBgS_GrpPassChk__vtbl *local_40;
  undefined4 local_3c;
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  uVar3 = 0;
  ::cBgS_GndChk::cBgS_GndChk(&local_8c);
  pcVar4 = &local_4c;
  local_4c.mbCamThrough = 0;
  local_4c.mbLinkThrough = 0;
  local_4c.mbArrowsAndLightThrough = 0;
  local_4c.mbBombThrough = 0;
  local_4c.mbBoomerangThrough = 0;
  local_4c.mbHookshotThrough = 0;
  local_8c.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar4;
  if (pcVar4 != (cBgS_PolyPassChk *)0x0) {
    local_8c.parent.mpGrpPassChk = (cBgS_GrpPassChk *)&local_40;
  }
  local_4c.mbObjThrough = 1;
  local_8c.parent.vtbl = &dBgS_ObjGndChk_All::__vt;
  local_8c.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_8037d43c;
  local_4c.vtbl = &cBgS_PolyPassChk__vtbl_8037d448;
  local_40 = &cBgS_GrpPassChk__vtbl_8037d454;
  local_3c = 0xf;
  local_8c.parent.mpPolyPassChk = pcVar4;
  iVar2 = dKy_rain_check();
  if (200 < iVar2) {
    local_8c.mPos.x = (pdVar1->parent).parent.mCurrent.mPos.x;
    local_8c.mPos.z = (pdVar1->parent).parent.mCurrent.mPos.z;
    local_8c.mPos.y = (pdVar1->parent).parent.mCurrent.mPos.y + _5475;
    dVar5 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_8c);
    if (dVar5 < (double)(_7419 + (pdVar1->parent).parent.mCurrent.mPos.y)) {
      uVar3 = 1;
    }
  }
  local_4c.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_40 = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
  if (pcVar4 != (cBgS_PolyPassChk *)0x0) {
    local_4c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_40 = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
    if (((undefined *)register0x00000004 != &DAT_00000040) &&
       (local_40 = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != &DAT_00000040)) {
      local_40 = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar4 != (cBgS_PolyPassChk *)0x0) &&
       (local_4c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar4 != (cBgS_PolyPassChk *)0x0)) {
      local_4c.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_8c.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_8c.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_8c.parent);
  return uVar3;
}

}

/* __thiscall dScnKy_env_light_c::~dScnKy_env_light_c(void) */

void __thiscall dScnKy_env_light_c::_dScnKy_env_light_c(dScnKy_env_light_c *this)

{
  short in_r4;
  
  if (this != (dScnKy_env_light_c *)0x0) {
    this->mRoomCtrl = (dStage_roomControl_c)&__vt;
    Runtime.PPCEABI.H::__destroy_arr
              (this->mWindInfluenceEntity,WIND_INF_ENTITY::_WIND_INF_ENTITY,0x3c,5);
    Runtime.PPCEABI.H::__destroy_arr
              (this->mLightInfluence,LIGHT_INFLUENCE::_LIGHT_INFLUENCE,0x20,0x1e);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_kankyo {

void __sinit_d_kankyo_cpp(void)

{
  ::dScnKy_env_light_c::dScnKy_env_light_c(&g_env_light);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}


/* __stdcall dKankyo_DayProc(void) */

void dKankyo_DayProc(void)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  char cVar4;
  
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1820);
  if (iVar1 != 0) {
    d_letter::dLetter_autoStock(0x8b03);
  }
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1820);
  if ((iVar1 != 0) &&
     (iVar1 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xb80), iVar1 != 0
     )) {
    d_letter::dLetter_autoStock(0xb203);
  }
  d_letter::dLetter_delivery(0xac03);
  d_letter::dLetter_delivery(0xae03);
  d_letter::dLetter_delivery(0xb003);
  d_letter::dLetter_delivery(0xaf03);
  d_letter::dLetter_delivery(0x9d03);
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xcf03);
  uVar3 = (uVar2 & 0xff) + 1;
  uVar2 = 3;
  if (uVar3 < 4) {
    uVar2 = uVar3;
  }
  dSv_event_c::setEventReg
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xcf03,(byte)uVar2);
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xab03);
  uVar3 = (uVar2 & 0xff) + 1;
  uVar2 = 3;
  if (uVar3 < 4) {
    uVar2 = uVar3;
  }
  dSv_event_c::setEventReg
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xab03,(byte)uVar2);
  iVar1 = dSv_player_get_bag_item_c::isReserve
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x0f');
  if ((iVar1 != 0) &&
     (cVar4 = dSv_player_bag_item_c::checkReserveItem
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x9b),
     cVar4 == '\0')) {
    uVar2 = dSv_event_c::getEventReg
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xccff);
    uVar3 = (uVar2 & 0xff) + 1;
    uVar2 = 2;
    if (uVar3 < 3) {
      uVar2 = uVar3;
    }
    dSv_event_c::setEventReg
              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xccff,(byte)uVar2);
  }
  dSv_event_c::setEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xbcff,0);
  dSv_event_c::setEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xcb03,0);
  dSv_event_c::setEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xca03,0);
  dSv_event_c::setEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xc903,0);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1304);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1302);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1301);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x120);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x40);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x20);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x10);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,8);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,4);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,2);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,1);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x180);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x140);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x580);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x104);
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xc103);
  if ((uVar2 & 0xff) == 1) {
    dSv_event_c::setEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xc103,2);
  }
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1f10);
  if (iVar1 != 0) {
    uVar2 = dSv_event_c::getEventReg
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xbb07);
    if ((uVar2 & 0xff) == 7) {
      dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1f08);
    }
    else {
      uVar3 = (uVar2 & 0xff) + 1;
      uVar2 = 7;
      if (uVar3 < 8) {
        uVar2 = uVar3;
      }
      dSv_event_c::setEventReg
                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xbb07,(byte)uVar2);
    }
  }
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xc407);
  if ((uVar2 & 0xff) == 6) {
    dSv_event_c::setEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xc407,7);
  }
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xb907);
  if ((uVar2 & 1) != 0) {
    dSv_event_c::setEventReg
              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xb907,(char)uVar2 + 1);
  }
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2680);
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2a20);
  if (iVar1 != 0) {
    uVar2 = dSv_event_c::getEventReg
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xa60f);
    uVar3 = (uVar2 & 0xff) + 1;
    uVar2 = 3;
    if (uVar3 < 4) {
      uVar2 = uVar3;
    }
    dSv_event_c::setEventReg
              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xa60f,(byte)uVar2);
  }
  iVar1 = dKy_get_dayofweek();
  if (iVar1 == 5) {
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2080);
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2004);
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2002);
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2804);
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2802);
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2801);
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2980);
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2940);
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3b01);
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3c80);
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3c40);
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3c20);
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3c10);
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3c08);
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3c04);
    dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3c02);
  }
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x208);
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2f01);
  if (iVar1 != 0) {
    dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3080);
  }
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x302);
  dSv_event_c::offEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x301);
  return;
}

