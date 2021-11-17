#include <d_kankyo_rain.h>
#include <d_kankyo_rain.h>
#include <gx/GXTexture.h>
#include <d_kankyo_wether.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <SComponent/c_math.h>
#include <d_particle.h>
#include <SComponent/c_lib.h>
#include <JPABase/JPAMath.h>
#include <JPABase/JPAEmitter.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s.h>
#include <mtx/vec.h>
#include <SComponent/c_xyz.h>
#include <SComponent/c_bg_s_chk.h>
#include <JKernel/JKRHeap.h>
#include <m_Do_lib.h>
#include <d_drawlist.h>
#include <d_kankyo.h>
#include <d_resorce.h>
#include <d_bg_s.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <d_stage.h>
#include <mtx/mtx.h>
#include <MSL_C.PPCEABI.bare.H/s_sin.h>
#include <d_cc_mass_s.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <d_snap.h>
#include <gx/GXLight.h>
#include <gx/GXTev.h>
#include <gx/GXAttr.h>
#include <gx/GXPixel.h>
#include <gx/GXBump.h>
#include <gx/GXGeometry.h>
#include <MSL_C.PPCEABI.bare.H/w_atan2.h>
#include <gx/GXTransform.h>
#include <mtx/mtxvec.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <J3DGraphBase/J3DSys.h>
#include <SComponent/c_sxyz.h>
#include <c_damagereaction.h>
#include <MSL_C.PPCEABI.bare.H/s_cos.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <f_op_kankyo_mng.h>
#include <dBgS_ObjGndChk_All.h>
#include <dBgS_RoofChk.h>
#include <dSnap_Obj.h>


namespace d_kankyo_rain {
struct cXyz add_table$9024[4];
undefined4 add_table$9810;
struct cXyz add_table$10284[4];
struct csXyz hokuto_position$10494[16];
struct cXyz add_table$10878[4];
int rot$8999;
undefined1 init$9000;
undefined1 init$9026;
float rot$9395;
undefined1 init$9396;
undefined4 rot$9557;
undefined1 init$9558;
float rot$9747;
undefined1 init$9748;
undefined1 init$9812;
float rot$10261;
undefined1 init$10262;
undefined1 init$10286;
undefined4 rot$10491;
undefined1 init$10492;
undefined1 init$10496;
undefined1 init$10880;
float rot$11076;
undefined1 init$11077;
float howa_loop_cnt$11254;
undefined1 init$11255;

/* __stdcall vectle_calc(DOUBLE_POS *,
                         cXyz *) */

float vectle_calc(DOUBLE_POS *param_1,cXyz *param_2)

{
  float fVar1;
  double dVar2;
  double dVar3;
  
  fVar1 = 0_0;
  dVar3 = param_1->z * param_1->z + param_1->x * param_1->x + param_1->y * param_1->y;
  if (dVar3 <= 0_0) {
    dVar2 = 0_0;
    if (0_0 != dVar3) {
      if (dVar3 == 0_0) {
        dVar2 = (double)MSL_C.PPCEABI.bare.H::__float_huge;
      }
      else {
        dVar2 = (double)MSL_C.PPCEABI.bare.H::__float_nan;
      }
    }
  }
  else {
    dVar2 = 1.0 / SQRT(dVar3);
    dVar2 = 0_5 * dVar2 * (3_0 - dVar3 * dVar2 * dVar2);
    dVar2 = 0_5 * dVar2 * (3_0 - dVar3 * dVar2 * dVar2);
    dVar2 = 0_5 * dVar2 * (3_0 - dVar3 * dVar2 * dVar2);
    dVar2 = dVar3 * 0_5 * dVar2 * (3_0 - dVar3 * dVar2 * dVar2);
  }
  if (0_0 == dVar2) {
    param_2->x = 0_0;
    param_2->y = fVar1;
    param_2->z = fVar1;
    return (float)dVar2;
  }
  param_2->x = (float)(param_1->x / dVar2);
  param_2->y = (float)(param_1->y / dVar2);
  param_2->z = (float)(param_1->z / dVar2);
  return (float)dVar2;
}


/* __stdcall get_vectle_calc(cXyz *,
                             cXyz *,
                             cXyz *) */

float get_vectle_calc(cXyz *param_1,cXyz *param_2,cXyz *param_3)

{
  float fVar1;
  DOUBLE_POS local_18;
  
  local_18.x = (double)(param_2->x - param_1->x);
  local_18.y = (double)(param_2->y - param_1->y);
  local_18.z = (double)(param_2->z - param_1->z);
  fVar1 = vectle_calc(&local_18,param_3);
  return fVar1;
}


/* __stdcall dKyr_get_vectle_calc(cXyz *,
                                  cXyz *,
                                  cXyz *) */

float dKyr_get_vectle_calc(cXyz *param_1,cXyz *param_2,cXyz *param_3)

{
  float fVar1;
  
  fVar1 = get_vectle_calc(param_1,param_2,param_3);
  return fVar1;
}


/* WARNING: Removing unreachable block (ram,0x8008ac3c) */
/* WARNING: Removing unreachable block (ram,0x8008ac44) */
/* __stdcall dKy_set_eyevect_calc(camera_class *,
                                  Vec *,
                                  float,
                                  float) */

void dKy_set_eyevect_calc
               (camera_class *param_1,cXyz *param_2,double scaleXZ,double scaleY)

{
  undefined4 uVar1;
  undefined8 in_f30;
  undefined8 in_f31;
  cXyz local_38;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  get_vectle_calc(&param_1->mEyePos,&param_1->mCenterPos,&local_38);
  param_2->x = (param_1->mEyePos).x + (float)((double)local_38.x * scaleXZ);
  param_2->y = ((param_1->mEyePos).y + (float)((double)local_38.y * scaleY)) - 200_0;
  param_2->z = (param_1->mEyePos).z + (float)((double)local_38.z * scaleXZ);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8008ad38) */
/* WARNING: Removing unreachable block (ram,0x8008ad40) */
/* __stdcall dKy_set_eyevect_calc2(camera_class *,
                                   Vec *,
                                   float,
                                   float) */

void dKy_set_eyevect_calc2
               (camera_class *param_1,cXyz *param_2,float scaleXZ,float scaleY)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f30;
  undefined8 in_f31;
  cXyz local_58;
  DOUBLE_POS local_48;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar3 = (double)scaleY;
  dVar2 = (double)scaleXZ;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_48.x = (double)((param_1->mCenterPos).x - (param_1->mEyePos).x);
  if ((double)0_0 == dVar3) {
    local_48.y = 0_0;
  }
  else {
    local_48.y = (double)((param_1->mCenterPos).y - (param_1->mEyePos).y);
  }
  local_48.z = (double)((param_1->mCenterPos).z - (param_1->mEyePos).z);
  vectle_calc(&local_48,&local_58);
  param_2->x = (param_1->mEyePos).x + (float)((double)local_58.x * dVar2);
  param_2->y = (param_1->mEyePos).y + (float)((double)local_58.y * dVar3);
  param_2->z = (param_1->mEyePos).z + (float)((double)local_58.z * dVar2);
  if ((double)0_0 == dVar3) {
    param_2->y = 0_0;
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* __stdcall dKyr_set_btitex(_GXTexObj *,
                             ResTIMG *) */

void dKyr_set_btitex(GXTexObj *param_1,_GXTexFmt *param_2)

{
  gx::GXInitTexObj(param_1,param_2 + *(int *)(param_2 + 0x1c),(uint)*(ushort *)(param_2 + 2),
                   (uint)*(ushort *)(param_2 + 4),*param_2,param_2[6],param_2[7],
                   SUB41(1 - (uint)param_2[0x18] >> 0x1f,0));
  gx::GXInitTexObjLOD((double)(_4172 * (float)((double)CONCAT44(0x43300000,
                                                                (int)(char)param_2[0x16] ^
                                                                0x80000000) - _4175)),
                      (double)(_4172 * (float)((double)CONCAT44(0x43300000,
                                                                (int)(char)param_2[0x17] ^
                                                                0x80000000) - _4175)),
                      (double)(0_01 * (float)((double)CONCAT44(0x43300000,
                                                               (int)*(short *)(param_2 + 0x1a) ^
                                                               0x80000000) - _4175)),param_1,
                      param_2[0x14],param_2[0x15],param_2[0x12],param_2[0x11],param_2[0x13]);
  gx::GXLoadTexObj(param_1,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x8008af70) */
/* __stdcall dKyr_kamome_move(void) */

void dKyr_kamome_move(void)

{
  byte bVar1;
  float fVar2;
  short sVar3;
  bool bVar4;
  uint uVar5;
  camera_class *pcVar6;
  dKyr__wind_Packet *pdVar7;
  s16 sVar8;
  s16 sVar9;
  int iVar10;
  int iVar11;
  JPABaseEmitter *pJVar12;
  uint uVar13;
  int iVar14;
  float *pSrc;
  dKyr__wind_Packet *pKam;
  float fVar15;
  cXyz local_78;
  cXyz local_6c;
  cXyz local_60;
  float local_54;
  float local_50;
  float local_4c;
  longlong local_48;
  longlong local_40;
  double local_38;
  
  pdVar7 = d_kankyo::g_env_light.mpWind;
  pcVar6 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  d_kankyo_wether::dKyw_get_wind_vec();
  bVar4 = false;
  iVar10 = MSL_C.PPCEABI.bare.H::strcmp
                     (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea");
  if (iVar10 == 0) {
    if (((((d_kankyo::g_env_light.mColpatCurr == 1) && (0_0 < d_kankyo::g_env_light.mColPatBlend))
         || ((d_kankyo::g_env_light.mColpatPrev == 1 && (d_kankyo::g_env_light.mColPatBlend < 1_0)))
         ) || ((d_kankyo::g_env_light.mColpatCurr == 2 && (0_0 < d_kankyo::g_env_light.mColPatBlend)
               ))) ||
       ((d_kankyo::g_env_light.mColpatPrev == 2 && (d_kankyo::g_env_light.mColPatBlend < 1_0)))) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
  }
  iVar14 = 0;
  iVar10 = 0;
  do {
    pKam = (dKyr__wind_Packet *)((int)&pdVar7->mWindEff[0].mpEmitter + iVar10);
    bVar1 = pKam->mKamomeEff[0].field_0x1e;
    if (bVar1 == 1) {
      if (pKam->mKamomeEff[0].mpBaseEmitter != (JPABaseEmitter *)0x0) {
        if (pKam->mKamomeEff[0].field_0x14 < 0_0) {
          fVar15 = SComponent::cM_rndFX(1_0);
          pKam->mKamomeEff[0].field_0x14 = pKam->mKamomeEff[0].field_0x14 + fVar15;
          if (pKam->mKamomeEff[0].field_0x14 < _4438) {
            pKam->mKamomeEff[0].field_0x14 = _4438;
          }
          if (_4439 < pKam->mKamomeEff[0].field_0x14) {
            pKam->mKamomeEff[0].field_0x14 = _4439;
          }
        }
        else {
          fVar15 = SComponent::cM_rndFX(1_0);
          pKam->mKamomeEff[0].field_0x14 = pKam->mKamomeEff[0].field_0x14 + fVar15;
          if (100_0 < pKam->mKamomeEff[0].field_0x14) {
            pKam->mKamomeEff[0].field_0x14 = 100_0;
          }
          if (pKam->mKamomeEff[0].field_0x14 < 80_0) {
            pKam->mKamomeEff[0].field_0x14 = 80_0;
          }
        }
        fVar15 = _4440;
        local_6c.z = 7000_0;
        uVar13 = SEXT24(pKam->mKamomeEff[0].field_0x10);
        uVar5 = uVar13 & 0xffff;
        local_78.x = 7000_0 * JKernel::JMath::jmaSinTable
                              [(int)uVar5 >> (JKernel::JMath::jmaSinShift & 0x3f)];
        local_78.y = ABS(_4440 * JKernel::JMath::jmaSinTable
                                 [(int)((int)pKam->mKamomeEff[0].field_0x12 & 0xffffU) >>
                                  (JKernel::JMath::jmaSinShift & 0x3f)]);
        local_78.z = 7000_0 * JKernel::JMath::jmaCosTable
                              [(int)uVar5 >> (JKernel::JMath::jmaSinShift & 0x3f)];
        local_38 = (double)CONCAT44(0x43300000,uVar13 ^ 0x80000000);
        pSrc = (float *)&pKam->mKamomeEff[0].field_0x18;
        iVar11 = (int)((float)(local_38 - _4175) +
                      pKam->mKamomeEff[0].field_0x14 * *(float *)&pKam->mKamomeEff[0].field_0x18);
        local_40 = (longlong)iVar11;
        pKam->mKamomeEff[0].field_0x10 = (short)iVar11;
        pKam->mKamomeEff[0].field_0x12 = pKam->mKamomeEff[0].field_0x12 + 0xf;
        uVar5 = (int)pKam->mKamomeEff[0].field_0x10 & 0xffff;
        local_6c.x = local_6c.z *
                     JKernel::JMath::jmaSinTable[(int)uVar5 >> (JKernel::JMath::jmaSinShift & 0x3f)]
        ;
        local_6c.y = ABS(fVar15 * JKernel::JMath::jmaSinTable
                                  [(int)((int)pKam->mKamomeEff[0].field_0x12 & 0xffffU) >>
                                   (JKernel::JMath::jmaSinShift & 0x3f)]);
        local_6c.z = local_6c.z *
                     JKernel::JMath::jmaCosTable[(int)uVar5 >> (JKernel::JMath::jmaSinShift & 0x3f)]
        ;
        local_54 = (pcVar6->mEyePos).x + local_6c.x;
        local_50 = _4441 + local_6c.y;
        local_4c = (pcVar6->mEyePos).z + local_6c.z;
        pKam->mKamomeEff[0].mPos.x = local_54;
        pKam->mKamomeEff[0].mPos.y = local_50;
        pKam->mKamomeEff[0].mPos.z = local_4c;
        fVar15 = pKam->mKamomeEff[0].mPos.y;
        fVar2 = pKam->mKamomeEff[0].mPos.z;
        pJVar12 = pKam->mKamomeEff[0].mpBaseEmitter;
        (pJVar12->mGlobalTranslation).x = pKam->mKamomeEff[0].mPos.x;
        (pJVar12->mGlobalTranslation).y = fVar15;
        (pJVar12->mGlobalTranslation).z = fVar2;
        if ((*(short *)&pKam->mKamomeEff[0].field_0x1c == 0) || (!bVar4)) {
          SComponent::cLib_addCalc((float *)&pKam->mKamomeEff[0].field_0x18,0_0,0_1,_4443,1_0E_6);
          if (*pSrc < 0_001) {
            pKam->mKamomeEff[0].field_0x1e = pKam->mKamomeEff[0].field_0x1e + 1;
          }
        }
        else {
          SComponent::cLib_addCalc(pSrc,1_0,0_1,_4443,1_0E_6);
          *(short *)&pKam->mKamomeEff[0].field_0x1c = *(short *)&pKam->mKamomeEff[0].field_0x1c + -1
          ;
        }
        dKyr_get_vectle_calc(&local_78,&local_6c,&local_60);
        iVar11 = SComponent::cM_atan2s(local_60.x,local_60.z);
        JPABase::JPAGetXYZRotateMtx
                  (0,(int)(short)iVar11,0,&(pKam->mKamomeEff[0].mpBaseEmitter)->mGlobalRotation);
      }
    }
    else {
      if (bVar1 == 0) {
        if (bVar4) {
          sVar3 = *(short *)&pKam->mKamomeEff[0].field_0x1c;
          if (sVar3 == 0) {
            fVar15 = SComponent::cM_rndFX(65535_0);
            local_48 = (longlong)(int)fVar15;
            pKam->mKamomeEff[0].field_0x10 = (short)(int)fVar15;
            fVar15 = SComponent::cM_rndFX(65535_0);
            local_40 = (longlong)(int)fVar15;
            pKam->mKamomeEff[0].field_0x12 = (short)(int)fVar15;
            fVar15 = _4433;
            uVar5 = (int)pKam->mKamomeEff[0].field_0x10 & 0xffff;
            local_54 = (pcVar6->mEyePos).x +
                       7000_0 * JKernel::JMath::jmaSinTable
                                [(int)uVar5 >> (JKernel::JMath::jmaSinShift & 0x3f)];
            local_50 = _4433;
            local_4c = (pcVar6->mEyePos).z +
                       7000_0 * JKernel::JMath::jmaCosTable
                                [(int)uVar5 >> (JKernel::JMath::jmaSinShift & 0x3f)];
            pKam->mKamomeEff[0].mPos.x = local_54;
            pKam->mKamomeEff[0].mPos.y = fVar15;
            pKam->mKamomeEff[0].mPos.z = local_4c;
            fVar15 = SComponent::cM_rndFX(1_0);
            pKam->mKamomeEff[0].field_0x14 = fVar15;
            *(float *)&pKam->mKamomeEff[0].field_0x18 = 0_0;
            fVar15 = SComponent::cM_rndF(180_0);
            local_38 = (double)(longlong)(int)(300_0 + fVar15);
            *(short *)&pKam->mKamomeEff[0].field_0x1c = (short)(int)(300_0 + fVar15);
            pJVar12 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,
                                         0x429,&pKam->mKamomeEff[0].mPos,(csXyz *)0x0,(cXyz *)0x0,
                                         0xff,(dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,
                                         (_GXColor *)0x0,(cXyz *)0x0);
            pKam->mKamomeEff[0].mpBaseEmitter = pJVar12;
            pKam->mKamomeEff[0].field_0x1e = pKam->mKamomeEff[0].field_0x1e + 1;
          }
          else {
            *(short *)&pKam->mKamomeEff[0].field_0x1c = sVar3 + -1;
          }
        }
      }
      else {
        if (bVar1 < 3) {
          JPABaseEmitter::deleteAllParticle(pKam->mKamomeEff[0].mpBaseEmitter);
          pJVar12 = pKam->mKamomeEff[0].mpBaseEmitter;
          pJVar12->mMaxFrame = -1;
          pJVar12->mFlags = pJVar12->mFlags | 1;
          pKam->mKamomeEff[0].mpBaseEmitter = (JPABaseEmitter *)0x0;
          pKam->mKamomeEff[0].field_0x1e = 0;
          fVar15 = SComponent::cM_rndF(600_0);
          local_38 = (double)(longlong)(int)(_4446 + fVar15);
          *(short *)&pKam->mKamomeEff[0].field_0x1c = (short)(int)(_4446 + fVar15);
        }
      }
    }
    pJVar12 = pKam->mKamomeEff[0].mpBaseEmitter;
    if (pJVar12 != (JPABaseEmitter *)0x0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
        fVar15 = (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mFovY / _4448;
        if (1_0 <= fVar15) {
          fVar15 = 1_0;
        }
        fVar15 = 1_6 * *(float *)&pKam->mKamomeEff[0].field_0x18 * fVar15;
        (pJVar12->mGlobalScale).x = fVar15;
        (pJVar12->mGlobalScale).y = fVar15;
        (pJVar12->mGlobalScale).z = fVar15;
        (pJVar12->mGlobalScale2D).x = fVar15;
        (pJVar12->mGlobalScale2D).y = fVar15;
        (pJVar12->mGlobalScale2D).z = fVar15;
      }
      sVar9 = d_kankyo::g_env_light.mBG0_K0.b;
      sVar8 = d_kankyo::g_env_light.mBG0_K0.g;
      pJVar12 = pKam->mKamomeEff[0].mpBaseEmitter;
      (pJVar12->mGlobalPrmColor).r = (u8)d_kankyo::g_env_light.mBG0_K0.r;
      (pJVar12->mGlobalPrmColor).g = (u8)sVar8;
      (pJVar12->mGlobalPrmColor).b = (u8)sVar9;
    }
    iVar14 = iVar14 + 1;
    iVar10 = iVar10 + 0x20;
  } while (iVar14 < 2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8008b4e4) */
/* __stdcall dKyr_wind_init(void) */

void dKyr_wind_init(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  float fVar5;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  (d_kankyo::g_env_light.mpWind)->mbHasCustomWindPower = 0;
  (d_kankyo::g_env_light.mpWind)->field_0x759 = 0;
  iVar1 = 0;
  iVar2 = 0;
  dVar4 = (double)0_0;
  do {
    (&(d_kankyo::g_env_light.mpWind)->mKamomeEff[0].field_0x1e)[iVar2] = 0;
    *(float *)(&(d_kankyo::g_env_light.mpWind)->mKamomeEff[0].field_0x18 + iVar2) = (float)dVar4;
    fVar5 = SComponent::cM_rndF(1800_0);
    *(short *)(&(d_kankyo::g_env_light.mpWind)->mKamomeEff[0].field_0x1c + iVar2) =
         (short)(int)fVar5;
    *(undefined4 *)((int)&(d_kankyo::g_env_light.mpWind)->mKamomeEff[0].mpBaseEmitter + iVar2) = 0;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x20;
  } while (iVar1 < 2);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Removing unreachable block (ram,0x8008c494) */
/* WARNING: Removing unreachable block (ram,0x8008c484) */
/* WARNING: Removing unreachable block (ram,0x8008c474) */
/* WARNING: Removing unreachable block (ram,0x8008c464) */
/* WARNING: Removing unreachable block (ram,0x8008c454) */
/* WARNING: Removing unreachable block (ram,0x8008c444) */
/* WARNING: Removing unreachable block (ram,0x8008c434) */
/* WARNING: Removing unreachable block (ram,0x8008c424) */
/* WARNING: Removing unreachable block (ram,0x8008c41c) */
/* WARNING: Removing unreachable block (ram,0x8008c42c) */
/* WARNING: Removing unreachable block (ram,0x8008c43c) */
/* WARNING: Removing unreachable block (ram,0x8008c44c) */
/* WARNING: Removing unreachable block (ram,0x8008c45c) */
/* WARNING: Removing unreachable block (ram,0x8008c46c) */
/* WARNING: Removing unreachable block (ram,0x8008c47c) */
/* WARNING: Removing unreachable block (ram,0x8008c48c) */
/* WARNING: Removing unreachable block (ram,0x8008c49c) */
/* __stdcall dKyr_wind_move(void) */

void dKyr_wind_move(void)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  int state;
  cXyz *pWindVec;
  JPABaseEmitter *pJVar6;
  WIND_EFF *pWindEff1;
  WIND_EFF *pEff;
  cBgS_PolyPassChk *pcVar7;
  WIND_EFF *pWindEff0;
  int idx1;
  int iVar8;
  uint idx0;
  int count;
  undefined4 uVar9;
  double dVar10;
  double dVar11;
  double windPow;
  double dVar12;
  undefined8 in_f15;
  double dVar13;
  undefined8 in_f16;
  undefined8 in_f17;
  double dVar14;
  undefined8 in_f18;
  double dVar15;
  undefined8 in_f19;
  double dVar16;
  undefined8 in_f20;
  double dVar17;
  undefined8 in_f21;
  double dVar18;
  undefined8 in_f22;
  double dVar19;
  undefined8 in_f23;
  double dVar20;
  undefined8 in_f24;
  double dVar21;
  undefined8 in_f25;
  undefined8 in_f26;
  double dVar22;
  undefined8 in_f27;
  double dVar23;
  undefined8 in_f28;
  double dVar24;
  undefined8 in_f29;
  double dVar25;
  undefined8 in_f30;
  double dVar26;
  undefined8 in_f31;
  float fVar27;
  cXyz local_24c;
  cXyz cStack576;
  float local_234;
  float local_230;
  float local_22c;
  cXyz local_228;
  cXyz local_21c;
  cXyz local_210;
  cXyz local_204;
  cXyz windVec_;
  cBgS_GndChk local_1ec;
  cBgS_PolyPassChk local_1ac;
  undefined local_1a0 [8];
  double local_198;
  double local_190;
  double local_188;
  double local_180;
  short local_178;
  camera_class *local_174;
  cBgS_GrpPassChk__vtbl *local_170;
  cBgS_PolyPassChk__vtbl *local_16c;
  cBgS_PolyInfo__vtbl *local_168;
  uint local_164;
  undefined auStack264 [16];
  undefined auStack248 [16];
  undefined auStack232 [16];
  undefined auStack216 [16];
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  dKyr__wind_Packet *pPkt;
  daPy_lk_c *pPlayer;
  
  pPkt = d_kankyo::g_env_light.mpWind;
  uVar9 = 0;
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
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  __psq_st0(auStack216,(int)((ulonglong)in_f18 >> 0x20),0);
  __psq_st1(auStack216,(int)in_f18,0);
  __psq_st0(auStack232,(int)((ulonglong)in_f17 >> 0x20),0);
  __psq_st1(auStack232,(int)in_f17,0);
  __psq_st0(auStack248,(int)((ulonglong)in_f16 >> 0x20),0);
  __psq_st1(auStack248,(int)in_f16,0);
  __psq_st0(auStack264,(int)((ulonglong)in_f15 >> 0x20),0);
  __psq_st1(auStack264,(int)in_f15,0);
  local_174 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  pWindVec = d_kankyo_wether::dKyw_get_wind_vec();
  windPow = d_kankyo_wether::dKyw_get_wind_pow();
  pPlayer = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  ::cBgS_GndChk::cBgS_GndChk(&local_1ec);
  fVar2 = 255_0;
  fVar27 = 0_18;
  pcVar7 = &local_1ac;
  local_1ac.mbCamThrough = 0;
  local_1ac.mbLinkThrough = 0;
  local_1ac.mbArrowsAndLightThrough = 0;
  local_1ac.mbBombThrough = 0;
  local_1ac.mbBoomerangThrough = 0;
  local_1ac.mbHookshotThrough = 0;
  local_1ec.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar7;
  if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
    local_1ec.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_1a0;
  }
  local_1ac.mbObjThrough = 1;
  local_1ec.parent.vtbl = &::dBgS_ObjGndChk_All::__vt;
  local_168 = &cBgS_PolyInfo__vtbl_8037d43c;
  local_1ec.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_8037d43c;
  local_16c = &cBgS_PolyPassChk__vtbl_8037d448;
  local_1ac.vtbl = &cBgS_PolyPassChk__vtbl_8037d448;
  local_170 = &cBgS_GrpPassChk__vtbl_8037d454;
  local_1a0._0_4_ = &cBgS_GrpPassChk__vtbl_8037d454;
  local_1a0._4_4_ = 0xf;
  windVec_.x = pWindVec->x;
  windVec_.y = pWindVec->y;
  windVec_.z = pWindVec->z;
  local_164 = dPa_control_c::mEmitterMng->field_0x24 -
              (dPa_control_c::mEmitterMng->field_0x0).mCount;
  dVar13 = (double)4000_0;
  dVar26 = (double)2000_0;
  dVar25 = (double)80_0;
  dVar23 = (double)2500_0;
  dVar22 = (double)250_0;
  dVar14 = (double)800_0;
  dVar21 = (double)1_0;
  dVar20 = (double)1000_0;
  dVar19 = (double)0_2;
  count = d_kankyo::g_env_light.mWindlineCount;
  if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc & 0x20U) != 0) {
    count = 10;
  }
  bVar5 = false;
  dVar10 = (double)0_0;
  if ((double)d_kankyo::g_env_light.mCustomWindPower <= dVar10) {
    if (pPkt->mbHasCustomWindPower != 0) {
      bVar5 = true;
      pPkt->mbHasCustomWindPower = 0;
    }
  }
  else {
    count = 9;
    dVar13 = (double)50_0;
    dVar23 = (double)160_0;
    dVar25 = (double)8_0;
    dVar14 = (double)150_0;
    dVar20 = (double)200_0;
    dVar21 = (double)0_14;
    dVar19 = dVar10;
    dVar22 = dVar20;
    dVar26 = dVar23;
    if (pPkt->mbHasCustomWindPower == 0) {
      pPkt->mbHasCustomWindPower = 1;
      bVar5 = true;
    }
  }
  dVar24 = (double)fVar27;
  dVar10 = (double)fVar2;
  local_1ec.parent.mpPolyPassChk = pcVar7;
  if (bVar5) {
    iVar8 = 0;
    idx1 = 0;
    do {
      pWindEff0 = (WIND_EFF *)((int)&pPkt->mWindEff[0].mpEmitter + idx1);
      if (pWindEff0->mpEmitter != (JPABaseEmitter *)0x0) {
        JPABaseEmitter::deleteAllParticle(pWindEff0->mpEmitter);
        pJVar6 = pWindEff0->mpEmitter;
        pJVar6->mMaxFrame = -1;
        pJVar6->mFlags = pJVar6->mFlags | 1;
        pWindEff0->mpEmitter = (JPABaseEmitter *)0x0;
      }
      pWindEff0->mState = 0;
      iVar8 = iVar8 + 1;
      idx1 = idx1 + 0x34;
    } while (iVar8 < 0x1e);
  }
  dKy_set_eyevect_calc2(local_174,&local_210,(float)dVar13,(float)dVar13);
  idx0 = 0;
  iVar8 = 0;
  idx1 = 0;
  dVar18 = (double)(float)((double)1_0 - windPow);
  dVar13 = (double)(float)((double)0_2 * dVar22);
  dVar14 = (double)(float)(dVar14 * windPow);
  dVar16 = (double)(float)((double)0_2 * dVar25);
  dVar17 = (double)(float)((double)0_1 * dVar24);
  do {
    dVar12 = _4175;
    fVar27 = 0_0;
    if (((int)idx0 < count) ||
       (pWindEff1 = (WIND_EFF *)((int)&pPkt->mWindEff[0].mpEmitter + idx1), pWindEff1->mState != 0))
    {
      pEff = (WIND_EFF *)((int)&pPkt->mWindEff[0].mpEmitter + idx1);
      state = pEff->mState;
      if (state == 3) {
        if (pPkt->mbHasCustomWindPower == 0) {
          pEff->mState = 0;
        }
      }
      else {
        if (state < 3) {
          if (state == 0) {
            if ((((double)0_3 <= windPow) && (local_164 < 0x5dd)) &&
               (((SComponent::g_Counter >> 4 & 7) != (idx0 & 3) || (pPkt->mbHasCustomWindPower != 0)
                ))) {
              pEff->mStateTimer = 0_0;
              pEff->mAlpha = fVar27;
              pEff->field_0x2c = 0;
              if (pPkt->mbHasCustomWindPower == 1) {
                (pEff->mBasePos).x = (pPlayer->parent).parent.mCurrent.mPos.x;
                (pEff->mBasePos).y = (pPlayer->parent).parent.mCurrent.mPos.y;
                (pEff->mBasePos).z = (pPlayer->parent).parent.mCurrent.mPos.z;
              }
              else {
                (pEff->mBasePos).x = local_210.x;
                (pEff->mBasePos).y = local_210.y;
                (pEff->mBasePos).z = local_210.z;
              }
              (pEff->mBasePos).y = (float)((double)(pEff->mBasePos).y + dVar20);
              fVar27 = SComponent::cM_rndFX((float)dVar26);
              (pEff->mRandomPos).x = fVar27;
              fVar27 = SComponent::cM_rndFX((float)dVar26);
              (pEff->mRandomPos).y = fVar27;
              fVar27 = SComponent::cM_rndFX((float)dVar26);
              (pEff->mRandomPos).z = fVar27;
              fVar27 = SComponent::cM_rndF(1_0);
              fVar27 = (float)(dVar23 + (double)(float)(dVar23 * (double)fVar27));
              (pEff->mRandomPos).x = (pEff->mRandomPos).x - windVec_.x * fVar27;
              (pEff->mRandomPos).y = (pEff->mRandomPos).y - windVec_.y * fVar27;
              (pEff->mRandomPos).z = (pEff->mRandomPos).z - windVec_.z * fVar27;
              fVar27 = SComponent::cM_rndF(65535_0);
              local_198 = (double)(longlong)(int)fVar27;
              pEff->field_0x2c = (short)(int)fVar27;
              local_21c.x = (pEff->mBasePos).x + (pEff->mRandomPos).x;
              local_21c.y = (pEff->mBasePos).y + (pEff->mRandomPos).y;
              local_21c.z = (pEff->mBasePos).z + (pEff->mRandomPos).z;
              if (pPkt->mbHasCustomWindPower != 1) {
                local_228.y = local_21c.y + 10000_0;
                local_228.x = local_21c.x;
                local_228.z = local_21c.z;
                local_1ec.mPos.x = local_21c.x;
                local_1ec.mPos.y = local_228.y;
                local_1ec.mPos.z = local_21c.z;
                dVar12 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay
                                                   ,&local_1ec);
                if ((double)local_21c.y < dVar12) {
                  fVar27 = SComponent::cM_rndF((float)dVar20);
                  (pEff->mRandomPos).y = ((float)(dVar12 + dVar20) + fVar27) - (pEff->mBasePos).y;
                }
              }
              local_21c.x = (pEff->mBasePos).x + (pEff->mRandomPos).x;
              local_21c.y = (pEff->mBasePos).y + (pEff->mRandomPos).y;
              local_21c.z = (pEff->mBasePos).z + (pEff->mRandomPos).z;
              pJVar6 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,
                                          0x31,&local_21c,(csXyz *)0x0,(cXyz *)0x0,0xff,
                                          (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,
                                          (_GXColor *)0x0,(cXyz *)0x0);
              pEff->mpEmitter = pJVar6;
              if (pEff->mpEmitter != (JPABaseEmitter *)0x0) {
                (pEff->mpEmitter->mGlobalPrmColor).a = 0;
                pJVar6 = pEff->mpEmitter;
                (pJVar6->mGlobalScale).x = (float)dVar21;
                (pJVar6->mGlobalScale).y = (float)dVar21;
                (pJVar6->mGlobalScale).z = (float)dVar21;
                (pJVar6->mGlobalScale2D).x = (float)dVar21;
                (pJVar6->mGlobalScale2D).y = (float)dVar21;
                (pJVar6->mGlobalScale2D).z = (float)dVar21;
                pEff->mState = 1;
              }
              dVar12 = (double)(windVec_.x * windVec_.x + windVec_.z * windVec_.z);
              if ((double)0_0 < dVar12) {
                dVar15 = 1.0 / SQRT(dVar12);
                dVar15 = 0_5 * dVar15 * (3_0 - dVar12 * dVar15 * dVar15);
                dVar15 = 0_5 * dVar15 * (3_0 - dVar12 * dVar15 * dVar15);
                dVar12 = (double)(float)(dVar12 * 0_5 * dVar15 * (3_0 - dVar12 * dVar15 * dVar15));
              }
              state = SComponent::cM_atan2s(windVec_.x,windVec_.z);
              pEff->mAngleXZ = (short)state;
              state = SComponent::cM_atan2s(windVec_.y,(float)dVar12);
              pEff->mAngleY = (short)state;
              pEff->field_0x28 = 0;
              fVar27 = SComponent::cM_rndF(1_0);
              if (dVar19 < (double)fVar27) {
                pEff->field_0x32 = 0;
              }
              else {
                pEff->field_0x32 = 1;
              }
            }
          }
          else {
            if (-1 < state) {
              fVar27 = (float)(dVar22 - (double)(float)(dVar13 * dVar18));
              local_198 = (double)CONCAT44(0x43300000,(int)pEff->field_0x2c ^ 0x80000000);
              pEff->field_0x2c = (short)(int)((double)(float)(local_198 - _4175) + dVar14);
              if ((idx0 & 1) == 0) {
                local_180 = (double)CONCAT44(0x43300000,(int)pEff->mAngleY ^ 0x80000000);
                state = (int)((float)(local_180 - dVar12) +
                             fVar27 * JKernel::JMath::jmaSinTable
                                      [(int)((int)pEff->field_0x2c & 0xffffU) >>
                                       (JKernel::JMath::jmaSinShift & 0x3f)]);
                local_188 = (double)(longlong)state;
                pEff->mAngleY = (short)state;
                local_190 = (double)CONCAT44(0x43300000,(int)pEff->mAngleXZ ^ 0x80000000);
                state = (int)((float)(local_190 - dVar12) -
                             fVar27 * JKernel::JMath::jmaSinTable
                                      [(int)((int)pEff->field_0x2c & 0xffffU) >>
                                       (JKernel::JMath::jmaSinShift & 0x3f)]);
                pEff->mAngleXZ = (short)state;
              }
              else {
                local_190 = (double)CONCAT44(0x43300000,(int)pEff->mAngleY ^ 0x80000000);
                state = (int)((float)(local_190 - dVar12) +
                             fVar27 * JKernel::JMath::jmaSinTable
                                      [(int)((int)pEff->field_0x2c & 0xffffU) >>
                                       (JKernel::JMath::jmaSinShift & 0x3f)]);
                pEff->mAngleY = (short)state;
                local_188 = (double)CONCAT44(0x43300000,(int)pEff->mAngleXZ ^ 0x80000000);
                iVar1 = (int)((float)(local_188 - dVar12) +
                             fVar27 * JKernel::JMath::jmaSinTable
                                      [(int)((int)pEff->field_0x2c & 0xffffU) >>
                                       (JKernel::JMath::jmaSinShift & 0x3f)]);
                local_180 = (double)(longlong)iVar1;
                pEff->mAngleXZ = (short)iVar1;
              }
              local_198 = (double)(longlong)state;
              if ((pEff->mStateTimer <= 0_4) || (pEff->field_0x32 != 1)) {
                dVar12 = (double)(windVec_.x * windVec_.x + windVec_.z * windVec_.z);
                if ((double)0_0 < dVar12) {
                  dVar15 = 1.0 / SQRT(dVar12);
                  dVar15 = 0_5 * dVar15 * (3_0 - dVar12 * dVar15 * dVar15);
                  dVar15 = 0_5 * dVar15 * (3_0 - dVar12 * dVar15 * dVar15);
                  dVar12 = (double)(float)(dVar12 * 0_5 * dVar15 * (3_0 - dVar12 * dVar15 * dVar15))
                  ;
                }
                state = SComponent::cM_atan2s(windVec_.x,windVec_.z);
                local_178 = (short)state;
                state = SComponent::cM_atan2s(windVec_.y,(float)dVar12);
                SComponent::cLib_addCalcAngleS(&pEff->mAngleY,(short)state,10,1000,1);
                SComponent::cLib_addCalcAngleS(&pEff->mAngleXZ,local_178,10,1000,1);
              }
              else {
                pEff->field_0x28 = pEff->field_0x28 + iVar8 + 0xe10;
                pEff->mAngleY = pEff->mAngleY + (short)(iVar8 + 0xe10);
                if (0xec77 < pEff->field_0x28) {
                  pEff->field_0x32 = 0;
                }
              }
              uVar3 = (int)pEff->mAngleXZ & 0xffff;
              uVar4 = (int)pEff->mAngleY & 0xffff;
              local_204.x = JKernel::JMath::jmaCosTable
                            [(int)uVar4 >> (JKernel::JMath::jmaSinShift & 0x3f)] *
                            JKernel::JMath::jmaSinTable
                            [(int)uVar3 >> (JKernel::JMath::jmaSinShift & 0x3f)];
              local_204.y = JKernel::JMath::jmaSinTable
                            [(int)uVar4 >> (JKernel::JMath::jmaSinShift & 0x3f)];
              local_204.z = JKernel::JMath::jmaCosTable
                            [(int)uVar4 >> (JKernel::JMath::jmaSinShift & 0x3f)] *
                            JKernel::JMath::jmaCosTable
                            [(int)uVar3 >> (JKernel::JMath::jmaSinShift & 0x3f)];
              fVar27 = (float)(dVar25 - (double)(float)(dVar16 * dVar18));
              local_180 = (double)CONCAT44(0x43300000,(int)pEff->field_0x2c ^ 0x80000000);
              fVar2 = (float)(local_180 - _4175) / 65535_0;
              if (1_0 < fVar2) {
                fVar2 = 1_0;
              }
              if (fVar2 < 0_0) {
                fVar2 = 0_0;
              }
              fVar27 = fVar27 + 0_3 * fVar27 * fVar2;
              (pEff->mRandomPos).x = (pEff->mRandomPos).x + local_204.x * fVar27;
              (pEff->mRandomPos).y = (pEff->mRandomPos).y + local_204.y * fVar27;
              (pEff->mRandomPos).z = (pEff->mRandomPos).z + local_204.z * fVar27;
              local_21c.x = (pEff->mBasePos).x + (pEff->mRandomPos).x;
              local_21c.y = (pEff->mBasePos).y + (pEff->mRandomPos).y;
              local_21c.z = (pEff->mBasePos).z + (pEff->mRandomPos).z;
              pJVar6 = pEff->mpEmitter;
              (pJVar6->mGlobalTranslation).x = local_21c.x;
              (pJVar6->mGlobalTranslation).y = local_21c.y;
              (pJVar6->mGlobalTranslation).z = local_21c.z;
              local_188 = (double)CONCAT44(0x43300000,(int)idx0 / 0x1e ^ 0x80000000);
              dVar15 = (double)(float)(dVar24 + (double)(float)(dVar17 * (double)(float)(local_188 -
                                                                                        _4175)));
              fVar27 = mtx::PSVECSquareDistance(&local_21c,&local_174->mEyePos);
              dVar12 = (double)fVar27;
              if ((double)0_0 < dVar12) {
                dVar11 = 1.0 / SQRT(dVar12);
                dVar11 = 0_5 * dVar11 * (3_0 - dVar12 * dVar11 * dVar11);
                dVar11 = 0_5 * dVar11 * (3_0 - dVar12 * dVar11 * dVar11);
                dVar12 = (double)(float)(dVar12 * 0_5 * dVar11 * (3_0 - dVar12 * dVar11 * dVar11));
              }
              fVar27 = (float)(dVar12 / (double)200_0);
              if (1_0 < (float)(dVar12 / (double)200_0)) {
                fVar27 = 1_0;
              }
              local_180 = (double)CONCAT44(0x43300000,
                                           (int)d_kankyo::g_env_light.mBG0_K0.r +
                                           (int)d_kankyo::g_env_light.mBG0_K0.g +
                                           (int)d_kankyo::g_env_light.mBG0_K0.b ^ 0x80000000);
              fVar2 = (_4858 * (float)(local_180 - _4175)) / 255_0;
              dVar12 = (double)(float)(windPow * (double)(fVar27 * fVar2 * fVar2));
              if (dVar12 < (double)0_5) {
                dVar12 = (double)0_5;
              }
              ::cXyz::operator_(&cStack576,&local_204,250_0);
              ::cXyz::operator__(&local_24c,&local_21c,&cStack576);
              local_234 = local_24c.x;
              local_22c = local_24c.z;
              local_230 = local_24c.y + 10000_0;
              local_1ec.mPos.x = local_24c.x;
              local_1ec.mPos.z = local_24c.z;
              local_1ec.mPos.y = local_230;
              dVar11 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                                 &local_1ec);
              if ((double)local_21c.y < dVar11) {
                local_180 = (double)CONCAT44(0x43300000,idx0 ^ 0x80000000);
                dVar15 = (double)(0_2 + 0_01 * (float)(local_180 - _4175));
                pEff->mState = 2;
              }
              state = (int)(dVar12 * (double)(float)(dVar10 * (double)pEff->mAlpha));
              local_180 = (double)(longlong)state;
              (pEff->mpEmitter->mGlobalPrmColor).a = (u8)state;
              if (pEff->mState == 1) {
                SComponent::cLib_addCalc
                          (&pEff->mStateTimer,1_0,0_3,(float)((double)0_1 * dVar15),0_01);
                if (1_0 <= pEff->mStateTimer) {
                  pEff->mState = 2;
                }
                if (0_5 < pEff->mStateTimer) {
                  SComponent::cLib_addCalc(&pEff->mAlpha,1_0,0_5,0_05,0_001);
                }
              }
              else {
                local_180 = (double)CONCAT44(0x43300000,idx0 ^ 0x80000000);
                SComponent::cLib_addCalc
                          (&pEff->mStateTimer,0_0,0_4,
                           (float)(dVar15 * (double)(0_1 + 0_01 * (float)(local_180 - _4175))),0_01)
                ;
                if (pEff->mStateTimer <= 0_0) {
                  JPABaseEmitter::deleteAllParticle(pEff->mpEmitter);
                  pJVar6 = pEff->mpEmitter;
                  pJVar6->mMaxFrame = -1;
                  pJVar6->mFlags = pJVar6->mFlags | 1;
                  pEff->mpEmitter = (JPABaseEmitter *)0x0;
                  pEff->mState = 0;
                  if (pPkt->mbHasCustomWindPower == 1) {
                    pEff->mState = 4;
                  }
                }
                if (pEff->mStateTimer < 0_5) {
                  SComponent::cLib_addCalc(&pEff->mAlpha,0_0,0_5,0_05,0_001);
                }
              }
            }
          }
        }
      }
    }
    else {
      if (pWindEff1->mpEmitter != (JPABaseEmitter *)0x0) {
        JPABaseEmitter::deleteAllParticle(pWindEff1->mpEmitter);
        pJVar6 = pWindEff1->mpEmitter;
        pJVar6->mMaxFrame = -1;
        pJVar6->mFlags = pJVar6->mFlags | 1;
        pWindEff1->mpEmitter = (JPABaseEmitter *)0x0;
      }
    }
    idx0 = idx0 + 1;
    iVar8 = iVar8 + 200;
    idx1 = idx1 + 0x34;
  } while ((int)idx0 < 0x1e);
  dKyr_kamome_move();
  local_1ac.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_1a0._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
  if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
    local_1ac.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_1a0._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x1a0) &&
       (local_1a0._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x1a0)) {
      local_1a0._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar7 != (cBgS_PolyPassChk *)0x0) &&
       (local_1ac.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar7 != (cBgS_PolyPassChk *)0x0)) {
      local_1ac.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_1ec.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_1ec.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_1ec.parent);
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  __psq_l0(auStack40,uVar9);
  __psq_l1(auStack40,uVar9);
  __psq_l0(auStack56,uVar9);
  __psq_l1(auStack56,uVar9);
  __psq_l0(auStack72,uVar9);
  __psq_l1(auStack72,uVar9);
  __psq_l0(auStack88,uVar9);
  __psq_l1(auStack88,uVar9);
  __psq_l0(auStack104,uVar9);
  __psq_l1(auStack104,uVar9);
  __psq_l0(auStack120,uVar9);
  __psq_l1(auStack120,uVar9);
  __psq_l0(auStack136,uVar9);
  __psq_l1(auStack136,uVar9);
  __psq_l0(auStack152,uVar9);
  __psq_l1(auStack152,uVar9);
  __psq_l0(auStack168,uVar9);
  __psq_l1(auStack168,uVar9);
  __psq_l0(auStack184,uVar9);
  __psq_l1(auStack184,uVar9);
  __psq_l0(auStack200,uVar9);
  __psq_l1(auStack200,uVar9);
  __psq_l0(auStack216,uVar9);
  __psq_l1(auStack216,uVar9);
  __psq_l0(auStack232,uVar9);
  __psq_l1(auStack232,uVar9);
  __psq_l0(auStack248,uVar9);
  __psq_l1(auStack248,uVar9);
  __psq_l0(auStack264,uVar9);
  __psq_l1(auStack264,uVar9);
  return;
}

}

/* __thiscall dBgS_ObjGndChk_All::~dBgS_ObjGndChk_All(void) */

void __thiscall dBgS_ObjGndChk_All::_dBgS_ObjGndChk_All(dBgS_ObjGndChk_All *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dBgS_ObjGndChk_All *)0x0;
  if (bVar1) {
    *(cBgS_Chk__vtbl **)(this + 0x10) = &__vt;
    *(cBgS_PolyInfo__vtbl **)(this + 0x20) = &cBgS_PolyInfo__vtbl_8037d43c;
    *(cBgS_PolyPassChk__vtbl **)(this + 0x40) = &cBgS_PolyPassChk__vtbl_8037d448;
    *(cBgS_GrpPassChk__vtbl **)(this + 0x4c) = &cBgS_GrpPassChk__vtbl_8037d454;
    if (bVar1) {
      *(cBgS_Chk__vtbl **)(this + 0x10) = &::dBgS_ObjGndChk::__vt;
      *(cBgS_PolyInfo__vtbl **)(this + 0x20) = &cBgS_PolyInfo__vtbl_80371ed8;
      *(cBgS_PolyPassChk__vtbl **)(this + 0x40) = &cBgS_PolyPassChk__vtbl_80371ee4;
      *(cBgS_GrpPassChk__vtbl **)(this + 0x4c) = &cBgS_GrpPassChk__vtbl_80371ef0;
      if (bVar1) {
        *(cBgS_Chk__vtbl **)(this + 0x10) = &::dBgS_GndChk::__vt;
        *(cBgS_PolyInfo__vtbl **)(this + 0x20) = &cBgS_PolyInfo__vtbl_80371f08;
        *(undefined ***)(this + 0x40) = &PTR_80371f14;
        *(undefined ***)(this + 0x4c) = &PTR_80371f20;
        if (this != (dBgS_ObjGndChk_All *)0xffffffc0) {
          *(undefined ***)(this + 0x40) = &::dBgS_Chk::__vt;
          *(undefined ***)(this + 0x4c) = &PTR_80371f68;
          if (this != (dBgS_ObjGndChk_All *)0xffffffb4) {
            *(undefined ***)(this + 0x4c) = &::dBgS_GrpPassChk::__vt;
            if (this != (dBgS_ObjGndChk_All *)0xffffffb4) {
              *(undefined ***)(this + 0x4c) = &::cBgS_GrpPassChk::__vt;
            }
          }
          if ((this != (dBgS_ObjGndChk_All *)0xffffffc0) &&
             (*(undefined ***)(this + 0x40) = &::dBgS_PolyPassChk::__vt,
             this != (dBgS_ObjGndChk_All *)0xffffffc0)) {
            *(undefined ***)(this + 0x40) = &::cBgS_PolyPassChk::__vt;
          }
        }
        if (this != (dBgS_ObjGndChk_All *)0x0) {
          *(undefined1 **)(this + 0x10) = &::cBgS_GndChk::__vt;
          *(undefined ***)(this + 0x20) = &PTR_80371e90;
          if (this != (dBgS_ObjGndChk_All *)0xffffffec) {
            *(undefined ***)(this + 0x20) = &::cBgS_PolyInfo::__vt;
          }
          cBgS_Chk::_cBgS_Chk((cBgS_Chk *)this);
        }
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_kankyo_rain {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dKyr_lenzflare_move(void) */

void dKyr_lenzflare_move(void)

{
  double dVar1;
  uint uVar2;
  int angle;
  dKankyo_sunlenz_Packet *local_r5_488;
  uint uVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  float fVar7;
  cXyz center;
  TVec3_float_ projected;
  cXyz vectle;
  cXyz camFwd;
  TVec3_float_ sunDirSmth;
  cXyz eyeVect;
  undefined4 uStack40;
  uint angleNeg;
  camera_class *pCam;
  dKankyo_sunlenz_Packet *pPkt;
  dKankyo_sun_Packet *pSun;
  
  pPkt = d_kankyo::g_env_light.mpSunlenzPacket;
  pSun = d_kankyo::g_env_light.mpSunPacket;
  pCam = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  if (0_0001 <= (d_kankyo::g_env_light.mpSunPacket)->mVisibility) {
    dKy_set_eyevect_calc
              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera,&eyeVect,
               (double)7200_0005,(double)7200_0005);
    dKyr_get_vectle_calc(&eyeVect,pSun->mPos,(cXyz *)&sunDirSmth);
    pPkt->mPositions[0].x = pSun->mPos[0].x;
    pPkt->mPositions[0].y = pSun->mPos[0].y;
    pPkt->mPositions[0].z = pSun->mPos[0].z;
    pPkt->mPositions[1].x = pSun->mPos[0].x;
    pPkt->mPositions[1].y = pSun->mPos[0].y;
    pPkt->mPositions[1].z = pSun->mPos[0].z;
    m_Do_lib::mDoLib_project(pPkt->mPositions,(cXyz *)&projected);
    center.x = 320_0;
    center.y = 240_0;
    center.z = 0_0;
    dKyr_get_vectle_calc(&center,(cXyz *)&projected,&vectle);
    angle = SComponent::cM_atan2s(vectle.x,vectle.y);
    angleNeg = (int)(short)angle ^ 0x80000000;
    uStack40 = 0x43300000;
    pPkt->mAngleDeg = (float)((double)CONCAT44(0x43300000,angleNeg) - _4175);
    pPkt->mAngleDeg = pPkt->mAngleDeg * _5017;
    pPkt->mAngleDeg = pPkt->mAngleDeg + 180_0;
    dKyr_get_vectle_calc(&pCam->mEyePos,&pCam->mCenterPos,&camFwd);
    fVar7 = mtx::PSVECSquareDistance((cXyz *)&sunDirSmth,&camFwd);
    dVar1 = _4175;
    dVar6 = (double)fVar7;
    if ((double)0_0 < dVar6) {
      dVar5 = 1.0 / SQRT(dVar6);
      dVar5 = 0_5 * dVar5 * (3_0 - dVar6 * dVar5 * dVar5);
      dVar5 = 0_5 * dVar5 * (3_0 - dVar6 * dVar5 * dVar5);
      dVar6 = (double)(float)(dVar6 * 0_5 * dVar5 * (3_0 - dVar6 * dVar5 * dVar5));
    }
    fVar7 = 250_0 + (float)((double)350_0 * dVar6);
    uVar3 = 2;
    angle = 0x18;
    iVar4 = 6;
    do {
      uVar2 = uVar3 ^ 0x80000000;
      local_r5_488 = (dKankyo_sunlenz_Packet *)((int)pPkt->mPositions + angle + -0x20);
      local_r5_488->mPositions[0].x =
           pSun->mPos[0].x -
           (float)((double)CONCAT44(0x43300000,uVar2) - dVar1) * sunDirSmth.x * fVar7;
      local_r5_488->mPositions[0].y =
           pSun->mPos[0].y -
           (float)((double)CONCAT44(0x43300000,uVar2) - dVar1) * sunDirSmth.y * fVar7;
      local_r5_488->mPositions[0].z =
           pSun->mPos[0].z -
           (float)((double)CONCAT44(0x43300000,uVar2) - dVar1) * sunDirSmth.z * fVar7;
      uVar3 = uVar3 + 1;
      angle = angle + 0xc;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}


/* __stdcall dKyr_moon_arrival_check(void) */

undefined4 dKyr_moon_arrival_check(void)

{
  if ((d_kankyo::g_env_light.mCurTime <= 277_5) && (112_5 <= d_kankyo::g_env_light.mCurTime)) {
    return 0;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f14 */
/* WARNING: Inlined function: FUN_80328f60 */
/* WARNING: Removing unreachable block (ram,0x8008cf40) */
/* WARNING: Removing unreachable block (ram,0x8008cf30) */
/* WARNING: Removing unreachable block (ram,0x8008cf38) */
/* WARNING: Removing unreachable block (ram,0x8008cf48) */
/* __stdcall dKyr_sun_move(void) */

void dKyr_sun_move(void)

{
  int iVar1;
  int iVar2;
  float fVar3;
  stage_stag_info_class *pStag;
  dKankyo_sun_Packet *pPkt;
  int iVar4;
  int iVar5;
  int iVar6;
  int culledCount;
  byte numCenterPointsVisible;
  byte numPointsVisible;
  uint uVar7;
  undefined4 uVar8;
  double dVar9;
  double py;
  double px;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar10;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  float fVar13;
  cXyz local_c4;
  cXyz local_ac;
  cXyz local_a0;
  longlong local_90;
  longlong local_88;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  camera_class *pCamera;
  dKankyo_sunlenz_Packet *pLenz;
  dKankyo_sun_Packet *pSun;
  
  pLenz = d_kankyo::g_env_light.mpSunlenzPacket;
  pSun = d_kankyo::g_env_light.mpSunPacket;
  pCamera = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  dVar10 = (double)0_0;
  numPointsVisible = 0;
  numCenterPointsVisible = 0;
  pStag = (stage_stag_info_class *)
          (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  uVar7 = pStag->mStageTypeAndSchbit >> 0x10 & 7;
  if ((d_kankyo::g_env_light.mBaseLightInfluence.mColor.r == 0) && (uVar7 != 2)) {
    dKyr_get_vectle_calc
              (&pCamera->mEyePos,&d_kankyo::g_env_light.mBaseLightInfluence.mPos,&local_a0);
  }
  else {
    dKyr_get_vectle_calc(&pCamera->mEyePos,(cXyz *)&d_kankyo::g_env_light.mSunPos2,&local_a0);
  }
  fVar13 = 8000_0;
  pSun->mPos[0].x = (pCamera->mEyePos).x + 8000_0 * local_a0.x;
  pSun->mPos[0].y = (pCamera->mEyePos).y + fVar13 * local_a0.y;
  pSun->mPos[0].z = (pCamera->mEyePos).z + fVar13 * local_a0.z;
  dVar9 = (double)((pSun->mPos[0].y - (pCamera->mEyePos).y) / fVar13);
  if (dVar9 < (double)0_0) {
    dVar9 = (double)0_0;
  }
  if ((double)1_0 <= dVar9) {
    dVar9 = (double)1_0;
  }
  fVar13 = (float)((double)1_0 - dVar9);
  dVar9 = (double)(fVar13 * fVar13);
  dVar12 = (double)(float)((double)1_0 - dVar9);
  culledCount = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                          (dVar9,0x803c9d58);
  if (culledCount != 0) {
    (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)(0x803c9d58)
    ;
  }
  if (pSun->field_0x3c != 0) {
    pSun->field_0x3c = pSun->field_0x3c - 1;
  }
  pSun->field_0x3d = false;
  if ((d_kankyo::g_env_light.mCurTime <= 97_5) || (292_5 <= d_kankyo::g_env_light.mCurTime)) {
    SComponent::cLib_addCalc(&pSun->mSunAlpha,0_0,0_5,0_1,0_01);
    numPointsVisible = 0;
    pSun->field_0x3c = 0;
    pSun->field_0x3d = false;
  }
  else {
    dVar10 = (double)0_0;
    culledCount = 0;
    SComponent::cLib_addCalc(&pSun->mSunAlpha,1_0,0_5,0_1,0_01);
    if (pCamera != (camera_class *)0x0) {
      dVar10 = (double)(pCamera->mBody).field_0x5f8;
    }
    m_Do_lib::mDoLib_project(pSun->mPos,&local_ac);
    iVar6 = 0;
    iVar5 = 0;
    iVar4 = 0;
    dVar9 = (double)(float)((double)490_0 - dVar10);
    dVar11 = (double)0_0;
    do {
      fVar13 = local_ac.x - *(float *)((int)&sun_chkpnt_5053[0].x + iVar4);
      px = (double)fVar13;
      fVar3 = local_ac.y - *(float *)((int)&sun_chkpnt_5053[0].y + iVar4);
      py = (double)fVar3;
      if ((((px <= dVar11) || (640_0 <= px)) || (py <= dVar10)) || (dVar9 <= py)) {
        culledCount = culledCount + 1;
      }
      else {
        pPkt = (dKankyo_sun_Packet *)((int)pSun->mPos + iVar5 + -0x10);
        if ((0xfffffe < pPkt->mVizChkData[0]) &&
           (numPointsVisible = numPointsVisible + 1, iVar6 == 0)) {
          numCenterPointsVisible = numCenterPointsVisible + 1;
        }
        iVar1 = (int)fVar13;
        local_90 = (longlong)iVar1;
        iVar2 = (int)fVar3;
        local_88 = (longlong)iVar2;
        dDlst_peekZ_c::newData
                  (&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mPeekZ,(short)iVar1,(short)iVar2,
                   pPkt->mVizChkData);
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 4;
      iVar4 = iVar4 + 8;
    } while (iVar6 < 5);
    if (((culledCount != 0) && (numPointsVisible != 0)) && (numCenterPointsVisible != 0)) {
      numCenterPointsVisible = 1;
      numPointsVisible = 5;
    }
    if (numPointsVisible != 0) {
      if (pSun->field_0x3c < 5) {
        pSun->field_0x3c = pSun->field_0x3c + 2;
      }
      pSun->field_0x3d = true;
    }
    pLenz->field_0x80 = pLenz->field_0x88;
    pLenz->field_0x84 = pLenz->field_0x8c;
    pLenz->field_0x88 = 1_0E9;
    local_c4.z = 0_0;
    pLenz->field_0x8c = 0_0;
    local_c4.x = 320_0;
    local_c4.y = 240_0;
    fVar13 = mtx::PSVECSquareDistance(&local_c4,&local_ac);
    dVar10 = (double)fVar13;
    if ((double)0_0 < dVar10) {
      dVar9 = 1.0 / SQRT(dVar10);
      dVar9 = 0_5 * dVar9 * (3_0 - dVar10 * dVar9 * dVar9);
      dVar9 = 0_5 * dVar9 * (3_0 - dVar10 * dVar9 * dVar9);
      dVar10 = (double)(float)(dVar10 * 0_5 * dVar9 * (3_0 - dVar10 * dVar9 * dVar9));
    }
    pLenz->mDistFalloff = (float)dVar10;
    pLenz->mDistFalloff = pLenz->mDistFalloff / 450_0;
    if (1_0 < pLenz->mDistFalloff) {
      pLenz->mDistFalloff = 1_0;
    }
    fVar3 = 1_0;
    pLenz->mDistFalloff = 1_0 - pLenz->mDistFalloff;
    fVar13 = pLenz->mDistFalloff * pLenz->mDistFalloff;
    pLenz->mDistFalloff = fVar3 - fVar13;
    dVar10 = (double)(fVar13 * fVar13);
  }
  if ((d_kankyo::g_env_light.mColpatWeather != 0) ||
     ((d_kankyo::g_env_light.mColpatCurr != 0 && (0_5 < d_kankyo::g_env_light.mColPatBlend)))) {
    numCenterPointsVisible = 0;
    numPointsVisible = 0;
  }
  if (uVar7 == 2) {
    numCenterPointsVisible = 0;
    numPointsVisible = 0;
  }
  if ((d_kankyo::g_env_light.mCurTime < 120_0) || (270_0 < d_kankyo::g_env_light.mCurTime)) {
    numCenterPointsVisible = 0;
    numPointsVisible = 0;
  }
  if (numCenterPointsVisible == 0) {
    if (numPointsVisible < 3) {
      SComponent::cLib_addCalc(&pSun->mVisibility,0_0,0_5,0_2,0_001);
    }
    else {
      SComponent::cLib_addCalc(&pSun->mVisibility,1_0,0_1,0_1,0_001);
    }
  }
  else {
    if (numPointsVisible == 4) {
      SComponent::cLib_addCalc(&pSun->mVisibility,1_0,0_1,0_1,0_001);
    }
    if (numPointsVisible < 4) {
      SComponent::cLib_addCalc(&pSun->mVisibility,0_0,0_1,0_2,0_001);
    }
    else {
      SComponent::cLib_addCalc(&pSun->mVisibility,1_0,0_5,0_2,0_01);
    }
  }
  if (numPointsVisible < 2) {
    (d_kankyo::g_env_light.mpSunlenzPacket)->mbDrawLenzInSky = true;
  }
  else {
    (d_kankyo::g_env_light.mpSunlenzPacket)->mbDrawLenzInSky = false;
  }
  if ((0_0 < pSun->mPos[0].y) && ((d_kankyo::g_env_light.mpSunlenzPacket)->mbDrawLenzInSky == false)
     ) {
    d_kankyo::dKy_set_actcol_ratio((double)(1_0 - (float)(dVar10 * (double)pSun->mVisibility)));
    d_kankyo::dKy_set_bgcol_ratio((double)(1_0 - (float)(dVar10 * (double)pSun->mVisibility)));
    d_kankyo::dKy_set_fogcol_ratio
              ((double)(1_0 + 0_5 * (float)(dVar12 * (double)(float)(dVar10 * (double)pSun->
                                                  mVisibility))));
    d_kankyo::dKy_set_vrboxcol_ratio
              ((double)(1_0 + 0_5 * (float)(dVar12 * (double)(float)(dVar10 * (double)pSun->
                                                  mVisibility))));
  }
  culledCount = dKyr_moon_arrival_check();
  if (culledCount == 0) {
    SComponent::cLib_addCalc(&pSun->mMoonAlpha,0_0,0_2,0_01,0_001);
  }
  else {
    fVar13 = (pSun->mPos[0].y - (pCamera->mEyePos).y) / _5183;
    fVar13 = fVar13 * fVar13 * _5184;
    if (1_0 < fVar13) {
      fVar13 = 1_0;
    }
    SComponent::cLib_addCalc(&pSun->mMoonAlpha,fVar13,0_2,0_01,0_001);
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  __psq_l0(auStack40,uVar8);
  __psq_l1(auStack40,uVar8);
  __psq_l0(auStack56,uVar8);
  __psq_l1(auStack56,uVar8);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dKyr_rain_init(void) */

void dKyr_rain_init(void)

{
  dKankyo_rain_Packet *pdVar1;
  float fVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  camera_class *pCamera;
  
  pCamera = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  puVar3 = (undefined *)
           dRes_control_c::getRes
                     ("Always",0x81,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  (d_kankyo::g_env_light.mpRainPacket)->mpTxSnow01 = puVar3;
  puVar3 = (undefined *)
           dRes_control_c::getRes
                     ("Always",0x85,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  (d_kankyo::g_env_light.mpRainPacket)->mpTxRingAHalf = puVar3;
  pdVar1 = d_kankyo::g_env_light.mpRainPacket;
  ((d_kankyo::g_env_light.mpRainPacket)->mCamEyePos).x = (pCamera->mEyePos).x;
  (pdVar1->mCamEyePos).y = (pCamera->mEyePos).y;
  (pdVar1->mCamEyePos).z = (pCamera->mEyePos).z;
  pdVar1 = d_kankyo::g_env_light.mpRainPacket;
  ((d_kankyo::g_env_light.mpRainPacket)->mCamCenterPos).x = (pCamera->mCenterPos).x;
  (pdVar1->mCamCenterPos).y = (pCamera->mCenterPos).y;
  (pdVar1->mCamCenterPos).z = (pCamera->mCenterPos).z;
  fVar2 = 0_0;
  (d_kankyo::g_env_light.mpRainPacket)->mCenterDeltaMul = 0_0;
  (d_kankyo::g_env_light.mpRainPacket)->field_0x3700 = fVar2;
  (d_kankyo::g_env_light.mpRainPacket)->mSibukiAlpha = fVar2;
  (d_kankyo::g_env_light.mpRainPacket)->mOverheadFade = fVar2;
  (d_kankyo::g_env_light.mpRainPacket)->mFwd1Fade = fVar2;
  (d_kankyo::g_env_light.mpRainPacket)->mFwdFade2 = fVar2;
  (d_kankyo::g_env_light.mpRainPacket)->mStatus = 0;
  ((d_kankyo::g_env_light.mpRainPacket)->mCenterDelta).x = fVar2;
  ((d_kankyo::g_env_light.mpRainPacket)->mCenterDelta).y = fVar2;
  ((d_kankyo::g_env_light.mpRainPacket)->mCenterDelta).z = fVar2;
  iVar4 = 0;
  iVar5 = 0xfa;
  do {
    (&(d_kankyo::g_env_light.mpRainPacket)->mRainEff[0].mStatus)[iVar4] = 0;
    iVar4 = iVar4 + 0x38;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  (d_kankyo::g_env_light.mpRainPacket)->mRainCount = 0;
  return;
}


/* __stdcall rain_bg_chk(dKankyo_rain_Packet *,
                         int) */

void rain_bg_chk(dKankyo_rain_Packet *param_1,int param_2)

{
  param_1->mRainEff[param_2].field_0x30 =
       _800_0 + ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mCenterPos).y;
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* __stdcall overhead_bg_chk(void) */

bool overhead_bg_chk(void)

{
  float fVar1;
  camera_class *pcVar2;
  dBgS_Chk *pdVar3;
  cBgS_PolyPassChk *pcVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  dBgS_RoofChk roofChk;
  cBgS_GndChk gndChk;
  cBgS_PolyPassChk local_60;
  undefined local_54 [12];
  
  pcVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  ::cBgS_GndChk::cBgS_GndChk(&gndChk);
  pcVar4 = &local_60;
  local_60.mbCamThrough = 0;
  local_60.mbLinkThrough = 0;
  local_60.mbArrowsAndLightThrough = 0;
  local_60.mbBombThrough = 0;
  local_60.mbBoomerangThrough = 0;
  local_60.mbHookshotThrough = 0;
  gndChk.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar4;
  if (pcVar4 != (cBgS_PolyPassChk *)0x0) {
    gndChk.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_54;
  }
  local_60.mbObjThrough = 1;
  gndChk.parent.vtbl = &::dBgS_ObjGndChk_All::__vt;
  gndChk.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_8037d43c;
  local_60.vtbl = &cBgS_PolyPassChk__vtbl_8037d448;
  local_54._0_4_ = &cBgS_GrpPassChk__vtbl_8037d454;
  local_54._4_4_ = 0xf;
  roofChk.mPolyInfo.mTriIdx = -1;
  roofChk.mPolyInfo.mBgIndex = 0x100;
  roofChk.mPolyInfo.mpBgW = (cBgW *)0x0;
  roofChk.mPolyInfo.mProcID = -1;
  roofChk.mChk.mbExcludeSameProcID = true;
  pdVar3 = &roofChk.mDChk;
  roofChk.mDChk.mPolyPassChk.parent.mbObjThrough = 0;
  roofChk.mDChk.mPolyPassChk.parent.mbCamThrough = 0;
  roofChk.mDChk.mPolyPassChk.parent.mbLinkThrough = 0;
  roofChk.mDChk.mPolyPassChk.parent.mbArrowsAndLightThrough = 0;
  roofChk.mDChk.mPolyPassChk.parent.mbBombThrough = 0;
  roofChk.mDChk.mPolyPassChk.parent.mbBoomerangThrough = 0;
  roofChk.mDChk.mPolyPassChk.parent.mbHookshotThrough = 0;
  roofChk.mDChk.mGrpPassChk.parent.mAttr = 1;
  roofChk.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::dBgS_RoofChk::__vt;
  roofChk.mChk.vtbl = (cBgS_Chk__vtbl *)&PTR_8037d40c;
  roofChk.mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_8037d418;
  roofChk.mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_8037d424;
  roofChk.mChk.mpGrpPassChk = (cBgS_GrpPassChk *)pdVar3;
  if (pdVar3 != (dBgS_Chk *)0x0) {
    roofChk.mChk.mpGrpPassChk = (cBgS_GrpPassChk *)&roofChk.mDChk.mGrpPassChk;
  }
  roofChk.mChk.mProcID = -1;
  gndChk.mPos.x = (pcVar2->mEyePos).x;
  gndChk.mPos.z = (pcVar2->mEyePos).z;
  gndChk.mPos.y = (pcVar2->mEyePos).y + 50_0;
  roofChk.mChk.mpPolyPassChk = (cBgS_PolyPassChk *)pdVar3;
  roofChk.mPos.x = gndChk.mPos.x;
  roofChk.mPos.y = gndChk.mPos.y;
  roofChk.mPos.z = gndChk.mPos.z;
  gndChk.parent.mpPolyPassChk = pcVar4;
  dVar6 = (double)dBgS::RoofChk(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&roofChk);
  dVar5 = (double)1_0E9;
  gndChk.mPos.y = gndChk.mPos.y + 10000_0;
  dVar7 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&gndChk);
  fVar1 = 50_0 + (pcVar2->mEyePos).y;
  roofChk.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::dBgS_RoofChk::__vt;
  roofChk.mChk.vtbl = (cBgS_Chk__vtbl *)&PTR_8037d40c;
  roofChk.mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_8037d418;
  roofChk.mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_8037d424;
  if (pdVar3 != (dBgS_Chk *)0x0) {
    roofChk.mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    roofChk.mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0xbc) &&
       (roofChk.mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0xbc)) {
      roofChk.mDChk.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
    }
    if ((pdVar3 != (dBgS_Chk *)0x0) &&
       (roofChk.mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt
       , pdVar3 != (dBgS_Chk *)0x0)) {
      roofChk.mDChk.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  cBgS_Chk::_cBgS_Chk(&roofChk.mChk);
  roofChk.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  local_60.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_54._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
  if (pcVar4 != (cBgS_PolyPassChk *)0x0) {
    local_60.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_54._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x54) &&
       (local_54._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x54)) {
      local_54._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar4 != (cBgS_PolyPassChk *)0x0) &&
       (local_60.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar4 != (cBgS_PolyPassChk *)0x0)) {
      local_60.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  gndChk.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  gndChk.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&gndChk.parent);
  return (double)fVar1 < dVar7 || dVar5 != dVar6;
}

}

/* __thiscall dBgS_RoofChk::~dBgS_RoofChk(void) */

void __thiscall dBgS_RoofChk::_dBgS_RoofChk(dBgS_RoofChk *this)

{
  short in_r4;
  
  if (this != (dBgS_RoofChk *)0x0) {
    (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&__vt;
    (this->mChk).vtbl = (cBgS_Chk__vtbl *)&PTR_8037d40c;
    (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_8037d418;
    (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_8037d424;
    if (this != (dBgS_RoofChk *)0xffffffdc) {
      (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (this != (dBgS_RoofChk *)0xffffffd0) {
        (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
        if (this != (dBgS_RoofChk *)0xffffffd0) {
          (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
        }
      }
      if ((this != (dBgS_RoofChk *)0xffffffdc) &&
         ((this->mDChk).mPolyPassChk.parent.vtbl =
               (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         this != (dBgS_RoofChk *)0xffffffdc)) {
        (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt
        ;
      }
    }
    cBgS_Chk::_cBgS_Chk(&this->mChk);
    if (this != (dBgS_RoofChk *)0x0) {
      (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_kankyo_rain {

/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Removing unreachable block (ram,0x8008dad0) */
/* __stdcall forward_overhead_bg_chk(cXyz *,
                                     float) */

bool forward_overhead_bg_chk(cXyz *param_1,float param_2)

{
  float fVar1;
  camera_class *pcVar2;
  cBgS_PolyPassChk *pcVar3;
  cBgS_PolyPassChk *pcVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f31;
  cXyz local_118;
  float local_10c;
  float local_108;
  float local_104;
  undefined local_100 [52];
  uint local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  undefined4 local_bc;
  cBgS_GndChk local_b4;
  cBgS_PolyPassChk local_74;
  undefined local_68 [16];
  undefined auStack8 [8];
  
  pcVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  dVar6 = (double)param_2;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::cBgS_GndChk::cBgS_GndChk(&local_b4);
  pcVar4 = &local_74;
  local_74.mbCamThrough = 0;
  local_74.mbLinkThrough = 0;
  local_74.mbArrowsAndLightThrough = 0;
  local_74.mbBombThrough = 0;
  local_74.mbBoomerangThrough = 0;
  local_74.mbHookshotThrough = 0;
  local_b4.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar4;
  if (pcVar4 != (cBgS_PolyPassChk *)0x0) {
    local_b4.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_68;
  }
  local_74.mbObjThrough = 1;
  local_b4.parent.vtbl = &::dBgS_ObjGndChk_All::__vt;
  local_b4.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_8037d43c;
  local_74.vtbl = &cBgS_PolyPassChk__vtbl_8037d448;
  local_68._0_4_ = &cBgS_GrpPassChk__vtbl_8037d454;
  local_68._4_4_ = 0xf;
  local_100._0_2_ = -1;
  local_100._2_2_ = 0x100;
  local_100._4_4_ = (cBgW *)0x0;
  local_100._8_4_ = -1;
  local_100[28] = true;
  pcVar3 = (cBgS_PolyPassChk *)(local_100 + 0x24);
  local_100[40] = 0;
  local_100[41] = 0;
  local_100[42] = 0;
  local_100[43] = 0;
  local_100[44] = 0;
  local_100[45] = 0;
  local_100[46] = 0;
  local_cc = 1;
  local_100._12_4_ = &::dBgS_RoofChk::__vt;
  local_100._32_4_ = &PTR_8037d40c;
  local_100._36_4_ = &PTR_8037d418;
  local_100._48_4_ = &PTR_8037d424;
  local_100._20_4_ = pcVar3;
  if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
    local_100._20_4_ = (cBgS_PolyPassChk *)(local_100 + 0x30);
  }
  local_c8 = 0_0;
  local_c4 = 0_0;
  local_c0 = 0_0;
  local_100._24_4_ = -1;
  local_bc = 0;
  local_100._16_4_ = pcVar3;
  local_b4.parent.mpPolyPassChk = pcVar4;
  dKyr_get_vectle_calc(&pcVar2->mEyePos,&pcVar2->mCenterPos,&local_118);
  local_10c = (pcVar2->mEyePos).x + (float)((double)local_118.x * dVar6);
  local_104 = (pcVar2->mEyePos).z + (float)((double)local_118.z * dVar6);
  local_108 = 50_0 + (pcVar2->mEyePos).y;
  param_1->x = local_10c;
  param_1->y = local_108;
  param_1->z = local_104;
  local_c8 = local_10c;
  local_c4 = local_108;
  local_c0 = local_104;
  dVar7 = (double)dBgS::RoofChk(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                (dBgS_RoofChk *)local_100);
  dVar6 = (double)1_0E9;
  local_108 = local_108 + 10000_0;
  local_b4.mPos.x = local_10c;
  local_b4.mPos.z = local_104;
  local_b4.mPos.y = local_108;
  dVar8 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_b4);
  fVar1 = 50_0 + (pcVar2->mEyePos).y;
  local_100._12_4_ = &::dBgS_RoofChk::__vt;
  local_100._32_4_ = &PTR_8037d40c;
  local_100._36_4_ = &PTR_8037d418;
  local_100._48_4_ = &PTR_8037d424;
  if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
    local_100._36_4_ = &::dBgS_Chk::__vt;
    local_100._48_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0xd0) &&
       (local_100._48_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0xd0)) {
      local_100._48_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar3 != (cBgS_PolyPassChk *)0x0) &&
       (local_100._36_4_ = &::dBgS_PolyPassChk::__vt, pcVar3 != (cBgS_PolyPassChk *)0x0)) {
      local_100._36_4_ = &::cBgS_PolyPassChk::__vt;
    }
  }
  cBgS_Chk::_cBgS_Chk((cBgS_Chk *)(local_100 + 0x10));
  local_100._12_4_ = &::cBgS_PolyInfo::__vt;
  local_74.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_68._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
  if (pcVar4 != (cBgS_PolyPassChk *)0x0) {
    local_74.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_68._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x68) &&
       (local_68._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x68)) {
      local_68._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar4 != (cBgS_PolyPassChk *)0x0) &&
       (local_74.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar4 != (cBgS_PolyPassChk *)0x0)) {
      local_74.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_b4.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_b4.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_b4.parent);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return (double)fVar1 < dVar8 || dVar6 != dVar7;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x8008e774) */
/* WARNING: Removing unreachable block (ram,0x8008e77c) */
/* __stdcall dKyr_rain_move(void) */

void dKyr_rain_move(void)

{
  short sVar1;
  float fVar2;
  uint uVar3;
  stage_stag_info_class *pStag;
  int iVar4;
  char cVar5;
  char cVar6;
  uint idx;
  int indoorMode;
  int iVar7;
  float *pSrc;
  dKankyo_rain_Packet *pRain;
  undefined4 uVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  undefined8 in_f30;
  double in_f31;
  cXyz local_108;
  cXyz local_fc;
  cXyz local_f0;
  cXyz local_e4;
  cXyz local_d8;
  cXyz cStack204;
  cXyz cStack192;
  cXyz local_b4;
  cXyz centerDeltaDir;
  cXyz local_9c;
  cXyz windVec;
  cXyz eyeVectOut;
  undefined auStack24 [16];
  undefined auStack8 [8];
  byte status;
  float 10_0;
  float 20_0;
  bool indoor;
  camera_class *pCam;
  dKankyo_rain_Packet *pPkt;
  
  pPkt = d_kankyo::g_env_light.mpRainPacket;
  pCam = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  d_kankyo_wether::dKyw_get_wind_vecpow(&local_108);
  windVec.x = local_108.x;
  windVec.y = local_108.y;
  windVec.z = local_108.z;
  indoorMode = 0;
  indoor = false;
  pStag = (stage_stag_info_class *)
          (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  idx = pStag->mStageTypeAndSchbit;
  local_b4.x = 0_0;
  local_b4.y = _2_0;
  local_b4.z = 0_0;
  if (pPkt->mRainCount <= d_kankyo::g_env_light.mRainCount) {
    pPkt->mRainCount = (short)d_kankyo::g_env_light.mRainCount;
  }
  if (pPkt->mRainCount != 0) {
    dKyr_get_vectle_calc(&pCam->mCenterPos,&pPkt->mCamCenterPos,&centerDeltaDir);
    10_0 = mtx::PSVECSquareDistance(&pPkt->mCamEyePos,&pCam->mEyePos);
    dVar11 = (double)10_0;
    if ((double)0_0 < dVar11) {
      dVar9 = 1.0 / SQRT(dVar11);
      dVar9 = 0_5 * dVar9 * (3_0 - dVar11 * dVar9 * dVar9);
      dVar9 = 0_5 * dVar9 * (3_0 - dVar11 * dVar9 * dVar9);
      dVar11 = (double)(float)(dVar11 * 0_5 * dVar9 * (3_0 - dVar11 * dVar9 * dVar9));
    }
    if (dVar11 <= (double)10_0) {
      dVar11 = (double)0_0;
    }
    else {
      dVar11 = (double)((float)(dVar11 - (double)10_0) / 50_0);
      if ((double)1_0 < dVar11) {
        dVar11 = (double)1_0;
      }
    }
    (pPkt->mCamEyePos).x = (pCam->mEyePos).x;
    (pPkt->mCamEyePos).y = (pCam->mEyePos).y;
    (pPkt->mCamEyePos).z = (pCam->mEyePos).z;
    10_0 = mtx::PSVECSquareDistance(&pPkt->mCamCenterPos,&pCam->mCenterPos);
    dVar9 = (double)10_0;
    if ((double)0_0 < dVar9) {
      dVar10 = 1.0 / SQRT(dVar9);
      dVar10 = 0_5 * dVar10 * (3_0 - dVar9 * dVar10 * dVar10);
      dVar10 = 0_5 * dVar10 * (3_0 - dVar9 * dVar10 * dVar10);
      dVar9 = (double)(float)(dVar9 * 0_5 * dVar10 * (3_0 - dVar9 * dVar10 * dVar10));
    }
    if (dVar9 <= (double)10_0) {
      dVar9 = (double)0_0;
    }
    else {
      dVar9 = (double)((float)(dVar9 - (double)10_0) / 50_0);
      if ((double)1_0 < dVar9) {
        dVar9 = (double)1_0;
      }
    }
    SComponent::cLib_addCalc(&pPkt->mCenterDeltaMul,(float)(dVar11 * dVar9),0_2,0_1,0_01);
    if (0_3 < pPkt->mCenterDeltaMul) {
      pPkt->mCenterDeltaMul = 0_3;
    }
    SComponent::cLib_addCalc(&(pPkt->mCenterDelta).x,centerDeltaDir.x,0_2,0_1,0_01);
    SComponent::cLib_addCalc(&(pPkt->mCenterDelta).y,centerDeltaDir.y,0_2,0_1,0_01);
    SComponent::cLib_addCalc(&(pPkt->mCenterDelta).z,centerDeltaDir.z,0_2,0_1,0_01);
    (pPkt->mCamCenterPos).x = (pCam->mCenterPos).x;
    (pPkt->mCamCenterPos).y = (pCam->mCenterPos).y;
    (pPkt->mCamCenterPos).z = (pCam->mCenterPos).z;
    dKy_set_eyevect_calc2(pCam,&eyeVectOut,700_0,600_0);
    d_kankyo_wether::dKyw_get_wind_vec();
    d_kankyo_wether::dKyw_get_wind_pow();
    10_0 = 0_0;
    pPkt->field_0x36cc = 0_0;
    pPkt->field_0x36c8 = 10_0;
    pPkt->mStatus = 0;
    iVar7 = 0;
    cVar5 = '\0';
    cVar6 = '\0';
    if ((((idx >> 0x10 & 7) == 2) &&
        (iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                           (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Ocrogh"),
        iVar4 != 0)) &&
       (iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Omori"),
       iVar4 != 0)) {
      indoor = true;
    }
    if (indoor) {
      indoorMode = 1;
      pPkt->mStatus = pPkt->mStatus | 1;
      iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Orichh");
      10_0 = 1200_0;
      if (iVar4 == 0) {
        10_0 = 2300_0;
      }
      in_f31 = (double)10_0;
      iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Atorizk");
      if (iVar4 == 0) {
        indoorMode = 2;
      }
    }
    else {
      iVar7 = overhead_bg_chk();
      cVar5 = forward_overhead_bg_chk(&cStack192,700_0);
      cVar6 = forward_overhead_bg_chk(&cStack204,1400_0);
      if (iVar7 == 0) {
        if ((bool)cVar5 != false) {
          pPkt->mStatus = pPkt->mStatus | 2;
        }
      }
      else {
        pPkt->mStatus = pPkt->mStatus | 1;
      }
      iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Ocrogh");
      if (iVar4 == 0) {
        pPkt->mStatus = 0;
        iVar7 = 0;
        cVar5 = '\0';
        cVar6 = '\0';
      }
    }
    if (iVar7 == 0) {
      SComponent::cLib_addCalc(&pPkt->mOverheadFade,1_0,0_1,0_1,0_001);
    }
    else {
      SComponent::cLib_addCalc(&pPkt->mOverheadFade,0_0,0_5,0_2,0_01);
    }
    if (cVar5 == '\0') {
      SComponent::cLib_addCalc(&pPkt->mFwd1Fade,1_0,0_1,0_1,0_001);
    }
    else {
      SComponent::cLib_addCalc(&pPkt->mFwd1Fade,0_0,0_5,0_2,0_01);
    }
    if (cVar6 == '\0') {
      SComponent::cLib_addCalc(&pPkt->mFwdFade2,1_0,0_1,0_1,0_001);
    }
    else {
      SComponent::cLib_addCalc(&pPkt->mFwdFade2,0_0,0_5,0_2,0_01);
    }
    idx = (int)pPkt->mRainCount - 1;
    iVar4 = idx * 0x38;
    for (; -1 < (int)idx; idx = idx - 1) {
                    /* RAIN_EFF */
      pRain = (dKankyo_rain_Packet *)((int)pPkt->mRainEff + iVar4 + -0x18);
      pRain->mRainEff[0].mBasePos.y = eyeVectOut.y;
      status = pRain->mRainEff[0].mStatus;
      if (status == 0) {
        10_0 = SComponent::cM_rndF(10_0);
        pRain->mRainEff[0].field_0x24 = -(35_5 + 10_0);
        pRain->mRainEff[0].mTimer = 0;
        pRain->mRainEff[0].mBasePos.x = eyeVectOut.x;
        pRain->mRainEff[0].mBasePos.y = eyeVectOut.y;
        pRain->mRainEff[0].mBasePos.z = eyeVectOut.z;
        10_0 = SComponent::cM_rndFX(800_0);
        pRain->mRainEff[0].mPos.x = 10_0;
        10_0 = SComponent::cM_rndF(600_0);
        pRain->mRainEff[0].mPos.y = 10_0;
        10_0 = SComponent::cM_rndFX(800_0);
        pRain->mRainEff[0].mPos.z = 10_0;
        pRain->mRainEff[0].mAlpha = 1_0;
        10_0 = SComponent::cM_rndF(360_0);
        pRain->mRainEff[0].field_0x1c = 10_0;
        10_0 = SComponent::cM_rndF(360_0);
        pRain->mRainEff[0].field_0x20 = 10_0;
        rain_bg_chk(pPkt,idx);
        pRain->mRainEff[0].mStatus = pRain->mRainEff[0].mStatus + 1;
      }
      else {
        if ((-1 < (char)status) && ((char)status < '\x04')) {
          10_0 = SComponent::cM_rndFX(0_1);
          pSrc = &pRain->mRainEff[0].field_0x24;
          SComponent::cLib_addCalc(pSrc,pRain->mRainEff[0].field_0x24 - 10_0,0_5,0_1,0_01);
          fVar2 = 0_08;
          20_0 = 20_0;
          10_0 = 10_0;
          dVar11 = _4175;
          pRain->mRainEff[0].mPos.x =
               pRain->mRainEff[0].mPos.x +
               20_0 *
               (windVec.x + 10_0 * (pPkt->mCenterDelta).x * pPkt->mCenterDeltaMul +
               local_b4.x +
               0_08 * (float)((double)CONCAT44(0x43300000,idx & 7 ^ 0x80000000) - _4175));
          pRain->mRainEff[0].mPos.y =
               pRain->mRainEff[0].mPos.y +
               20_0 * (local_b4.y +
                      windVec.y + 10_0 * (pPkt->mCenterDelta).y * pPkt->mCenterDeltaMul);
          pRain->mRainEff[0].mPos.z =
               pRain->mRainEff[0].mPos.z +
               20_0 * (windVec.z + 10_0 * (pPkt->mCenterDelta).z * pPkt->mCenterDeltaMul +
                      local_b4.z +
                      fVar2 * (float)((double)CONCAT44(0x43300000,idx & 3 ^ 0x80000000) - dVar11));
          local_9c.x = pRain->mRainEff[0].mBasePos.x + pRain->mRainEff[0].mPos.x;
          local_9c.y = eyeVectOut.y;
          local_9c.z = pRain->mRainEff[0].mBasePos.z + pRain->mRainEff[0].mPos.z;
          10_0 = mtx::PSVECSquareDistance(&local_9c,&eyeVectOut);
          dVar11 = (double)10_0;
          if ((double)0_0 < dVar11) {
            dVar9 = 1.0 / SQRT(dVar11);
            dVar9 = 0_5 * dVar9 * (3_0 - dVar11 * dVar9 * dVar9);
            dVar9 = 0_5 * dVar9 * (3_0 - dVar11 * dVar9 * dVar9);
            dVar11 = (double)(float)(dVar11 * 0_5 * dVar9 * (3_0 - dVar11 * dVar9 * dVar9));
          }
          sVar1 = pRain->mRainEff[0].mTimer;
          if (sVar1 == 0) {
            if ((double)800_0 < dVar11) {
              pRain->mRainEff[0].mTimer = 10;
              10_0 = SComponent::cM_rndF(10_0);
              *pSrc = -(35_5 + 10_0);
              pRain->mRainEff[0].mBasePos.x = eyeVectOut.x;
              pRain->mRainEff[0].mBasePos.y = eyeVectOut.y;
              pRain->mRainEff[0].mBasePos.z = eyeVectOut.z;
              10_0 = mtx::PSVECSquareDistance(&local_9c,&eyeVectOut);
              dVar11 = (double)10_0;
              if ((double)0_0 < dVar11) {
                dVar9 = 1.0 / SQRT(dVar11);
                dVar9 = 0_5 * dVar9 * (3_0 - dVar11 * dVar9 * dVar9);
                dVar9 = 0_5 * dVar9 * (3_0 - dVar11 * dVar9 * dVar9);
                dVar11 = (double)(float)(dVar11 * 0_5 * dVar9 * (3_0 - dVar11 * dVar9 * dVar9));
              }
              if (dVar11 <= (double)850_0) {
                10_0 = SComponent::cM_rndFX(40_0);
                dVar11 = (double)10_0;
                get_vectle_calc(&local_9c,&eyeVectOut,&centerDeltaDir);
                10_0 = (float)((double)800_0 + dVar11);
                pRain->mRainEff[0].mPos.x = centerDeltaDir.x * 10_0;
                pRain->mRainEff[0].mPos.y = centerDeltaDir.y * 10_0;
                pRain->mRainEff[0].mPos.z = centerDeltaDir.z * 10_0;
              }
              else {
                10_0 = SComponent::cM_rndFX(800_0);
                pRain->mRainEff[0].mPos.x = 10_0;
                10_0 = SComponent::cM_rndFX(800_0);
                pRain->mRainEff[0].mPos.y = 10_0;
                10_0 = SComponent::cM_rndFX(800_0);
                pRain->mRainEff[0].mPos.z = 10_0;
              }
              pRain->mRainEff[0].mStatus = 1;
              rain_bg_chk(pPkt,idx);
            }
            local_9c.y = pRain->mRainEff[0].mBasePos.y + pRain->mRainEff[0].mPos.y;
            if (local_9c.y < 20_0 + pRain->mRainEff[0].field_0x30) {
              pRain->mRainEff[0].mBasePos.x = eyeVectOut.x;
              pRain->mRainEff[0].mBasePos.y = eyeVectOut.y;
              pRain->mRainEff[0].mBasePos.z = eyeVectOut.z;
              10_0 = SComponent::cM_rndFX(800_0);
              pRain->mRainEff[0].mPos.x = 10_0;
              pRain->mRainEff[0].mPos.y = 200_0;
              10_0 = SComponent::cM_rndFX(800_0);
              pRain->mRainEff[0].mPos.z = 10_0;
              rain_bg_chk(pPkt,idx);
              pRain->mRainEff[0].mTimer = 10;
            }
          }
          else {
            pRain->mRainEff[0].mTimer = sVar1 + -1;
          }
        }
      }
      local_9c.x = pRain->mRainEff[0].mBasePos.x + pRain->mRainEff[0].mPos.x;
      local_9c.y = pRain->mRainEff[0].mBasePos.y + pRain->mRainEff[0].mPos.y;
      local_9c.z = pRain->mRainEff[0].mBasePos.z + pRain->mRainEff[0].mPos.z;
      if ((d_kankyo::g_env_light.mRainCount + -1 < (int)idx) &&
         (uVar3 = (int)pPkt->mRainCount - 1, idx == uVar3)) {
        pPkt->mRainCount = (short)uVar3;
      }
      dVar11 = (double)1_0;
      if ((iVar7 != 0) || ((double)pPkt->mOverheadFade < dVar11)) {
        local_d8.y = (pCam->mEyePos).y;
        local_d8.x = local_9c.x;
        local_d8.z = local_9c.z;
        10_0 = mtx::PSVECSquareDistance(&pCam->mEyePos,&local_d8);
        dVar9 = (double)10_0;
        if ((double)0_0 < dVar9) {
          dVar10 = 1.0 / SQRT(dVar9);
          dVar10 = 0_5 * dVar10 * (3_0 - dVar9 * dVar10 * dVar10);
          dVar10 = 0_5 * dVar10 * (3_0 - dVar9 * dVar10 * dVar10);
          dVar9 = (double)(float)(dVar9 * 0_5 * dVar10 * (3_0 - dVar9 * dVar10 * dVar10));
        }
        if (dVar9 < (double)800_0) {
          dVar11 = (double)(float)(dVar11 * (double)pPkt->mOverheadFade);
        }
      }
      if ((cVar5 != '\0') || (pPkt->mFwd1Fade < 1_0)) {
        local_e4.x = local_9c.x;
        local_e4.z = local_9c.z;
        local_e4.y = cStack192.y;
        10_0 = mtx::PSVECSquareDistance(&cStack192,&local_e4);
        dVar9 = (double)10_0;
        if ((double)0_0 < dVar9) {
          dVar10 = 1.0 / SQRT(dVar9);
          dVar10 = 0_5 * dVar10 * (3_0 - dVar9 * dVar10 * dVar10);
          dVar10 = 0_5 * dVar10 * (3_0 - dVar9 * dVar10 * dVar10);
          dVar9 = (double)(float)(dVar9 * 0_5 * dVar10 * (3_0 - dVar9 * dVar10 * dVar10));
        }
        if (dVar9 < (double)550_0) {
          dVar11 = (double)(float)(dVar11 * (double)pPkt->mFwd1Fade);
        }
      }
      if ((cVar6 != '\0') || (pPkt->mFwdFade2 < 1_0)) {
        local_f0.x = local_9c.x;
        local_f0.z = local_9c.z;
        local_f0.y = cStack204.y;
        10_0 = mtx::PSVECSquareDistance(&cStack204,&local_f0);
        dVar9 = (double)10_0;
        if ((double)0_0 < dVar9) {
          dVar10 = 1.0 / SQRT(dVar9);
          dVar10 = 0_5 * dVar10 * (3_0 - dVar9 * dVar10 * dVar10);
          dVar10 = 0_5 * dVar10 * (3_0 - dVar9 * dVar10 * dVar10);
          dVar9 = (double)(float)(dVar9 * 0_5 * dVar10 * (3_0 - dVar9 * dVar10 * dVar10));
        }
        if (dVar9 < (double)550_0) {
          dVar11 = (double)(float)(dVar11 * (double)pPkt->mFwdFade2);
        }
      }
      if (indoorMode != 0) {
        local_fc.x = local_9c.x;
        local_fc.z = local_9c.z;
        local_fc.y = 0_0;
        10_0 = mtx::PSVECSquareMag(&local_fc);
        dVar9 = (double)10_0;
        if ((double)0_0 < dVar9) {
          dVar10 = 1.0 / SQRT(dVar9);
          dVar10 = 0_5 * dVar10 * (3_0 - dVar9 * dVar10 * dVar10);
          dVar10 = 0_5 * dVar10 * (3_0 - dVar9 * dVar10 * dVar10);
          dVar9 = (double)(float)(dVar9 * 0_5 * dVar10 * (3_0 - dVar9 * dVar10 * dVar10));
        }
        if (dVar9 < in_f31) {
          dVar11 = (double)0_0;
        }
        if ((indoorMode == 2) && (local_9c.y < 1300_0)) {
          dVar11 = (double)0_0;
        }
      }
      pRain->mRainEff[0].mAlpha = (float)dVar11;
      iVar4 = iVar4 + -0x38;
    }
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x8008f094) */
/* WARNING: Removing unreachable block (ram,0x8008f09c) */
/* __stdcall dKyr_housi_move(void) */

void dKyr_housi_move(void)

{
  byte bVar1;
  short sVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  dKankyo_housi_Packet *pEff;
  cBgS_PolyPassChk *pcVar7;
  undefined4 uVar8;
  double dVar9;
  double dVar10;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar11;
  float fVar12;
  cXyz pntwind;
  cXyz local_e4;
  cXyz local_d8;
  cXyz pos;
  cXyz windVecPow;
  cXyz eyeVect;
  cBgS_GndChk local_a8;
  cBgS_PolyPassChk local_68;
  undefined local_5c [12];
  longlong local_50;
  undefined auStack24 [16];
  undefined auStack8 [8];
  camera_class *pCam;
  dKankyo_housi_Packet *pPkt;
  
  pPkt = d_kankyo::g_env_light.mpHousiPacket;
  pCam = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  d_kankyo_wether::dKyw_get_wind_vecpow(&local_e4);
  ::cBgS_GndChk::cBgS_GndChk(&local_a8);
  pcVar7 = &local_68;
  local_68.mbObjThrough = 0;
  local_68.mbCamThrough = 0;
  local_68.mbLinkThrough = 0;
  local_68.mbArrowsAndLightThrough = 0;
  local_68.mbBombThrough = 0;
  local_68.mbBoomerangThrough = 0;
  local_68.mbHookshotThrough = 0;
  local_5c._4_4_ = 1;
  local_a8.parent.vtbl = &::dBgS_GndChk::__vt;
  local_a8.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_5c._0_4_ = &PTR_80371f20;
  local_a8.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar7;
  if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
    local_a8.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_5c;
  }
  if ((d_kankyo::g_env_light.mHousiCount != 0) ||
     ((d_kankyo::g_env_light.mHousiCount == 0 && (pPkt->field_0x5ddc <= 0_0)))) {
    pPkt->mCount = (short)d_kankyo::g_env_light.mHousiCount;
  }
  local_a8.parent.mpPolyPassChk = pcVar7;
  if (d_kankyo::g_env_light.mHousiCount == 0) {
    SComponent::cLib_addCalc(&pPkt->field_0x5ddc,0_0,0_2,0_05,0_01);
  }
  else {
    SComponent::cLib_addCalc(&pPkt->field_0x5ddc,1_0,0_2,0_05,0_01);
  }
  if (pPkt->mCount == 0) {
    local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_5c._0_4_ = &PTR_80371f20;
    if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
      local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_5c._0_4_ = &PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0x5c) &&
         (local_5c._0_4_ = &::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0x5c)) {
        local_5c._0_4_ = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar7 != (cBgS_PolyPassChk *)0x0) &&
         (local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar7 != (cBgS_PolyPassChk *)0x0)) {
        local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_a8.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    local_a8.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk(&local_a8.parent);
  }
  else {
    dKy_set_eyevect_calc2(pCam,&eyeVect,800_0,800_0);
    d_kankyo_wether::dKyw_get_wind_pow();
    iVar6 = pPkt->mCount + -1;
    iVar5 = iVar6 * 0x50;
    for (; -1 < iVar6; iVar6 = iVar6 + -1) {
      dVar11 = (double)pPkt->field_0x5ddc;
      pEff = (dKankyo_housi_Packet *)((int)pPkt->mEff + iVar5 + -0x14);
      bVar1 = pEff->mEff[0].mState;
      if (bVar1 == 0) {
        fVar12 = SComponent::cM_rndF(1_5);
        pEff->mEff[0].field_0x34 = 0_2 + fVar12;
        pEff->mEff[0].field_0x3c = 0;
        fVar12 = SComponent::cM_rndFX(65536_0);
        local_50 = (longlong)(int)fVar12;
        pEff->mEff[0].field_0x4c = (short)(int)fVar12;
        pEff->mEff[0].mBasePos.x = eyeVect.x;
        pEff->mEff[0].mBasePos.y = eyeVect.y;
        pEff->mEff[0].mBasePos.z = eyeVect.z;
        fVar12 = SComponent::cM_rndFX(1000_0);
        pEff->mEff[0].mPos.x = fVar12;
        fVar12 = 1000_0;
        pEff->mEff[0].mPos.y = 1000_0;
        fVar12 = SComponent::cM_rndFX(fVar12);
        pEff->mEff[0].mPos.z = fVar12;
        fVar12 = 0_0;
        pEff->mEff[0].mAlpha = 0_0;
        pEff->mEff[0].field_0x48 = fVar12;
        fVar12 = SComponent::cM_rndF(360_0);
        pEff->mEff[0].mScale.x = fVar12;
        fVar12 = SComponent::cM_rndF(360_0);
        pEff->mEff[0].mScale.y = fVar12;
        fVar12 = SComponent::cM_rndF(360_0);
        pEff->mEff[0].mScale.z = fVar12;
        fVar12 = 0_0;
        pEff->mEff[0].mVel.x = 0_0;
        pEff->mEff[0].mVel.y = fVar12;
        pEff->mEff[0].mVel.z = fVar12;
        fVar12 = pEff->mEff[0].mBasePos.y;
        if (fVar12 + pEff->mEff[0].mPos.y < _6079) {
          pEff->mEff[0].mPos.y = 10_0 + (_6080 - fVar12);
        }
        pEff->mEff[0].mState = pEff->mEff[0].mState + 1;
      }
      else {
        if ((-1 < (char)bVar1) && ((char)bVar1 < '\x04')) {
          if (bVar1 == 1) {
            uVar4 = SComponent::cM_rad2s((double)pEff->mEff[0].mScale.x);
            fVar3 = 5_0;
            fVar12 = JKernel::JMath::jmaSinTable
                     [(int)(uVar4 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
            pEff->mEff[0].mPos.x =
                 pEff->mEff[0].mPos.x + 5_0 * local_e4.x * pEff->mEff[0].field_0x34;
            pEff->mEff[0].mPos.y =
                 pEff->mEff[0].mPos.y + fVar3 * local_e4.y * pEff->mEff[0].field_0x34;
            pEff->mEff[0].mPos.z =
                 pEff->mEff[0].mPos.z + fVar3 * local_e4.z * pEff->mEff[0].field_0x34;
            pEff->mEff[0].mPos.y = pEff->mEff[0].mPos.y - 0_6 * pEff->mEff[0].field_0x34;
            pEff->mEff[0].mPos.x = pEff->mEff[0].mPos.x + fVar12 * pEff->mEff[0].field_0x34;
            uVar4 = SComponent::cM_rad2s((double)pEff->mEff[0].mScale.y);
            pEff->mEff[0].mPos.y =
                 pEff->mEff[0].mPos.y +
                 0_5 * pEff->mEff[0].field_0x34 *
                 JKernel::JMath::jmaSinTable
                 [(int)(uVar4 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
            uVar4 = SComponent::cM_rad2s((double)pEff->mEff[0].mScale.z);
            pEff->mEff[0].mPos.z =
                 pEff->mEff[0].mPos.z +
                 pEff->mEff[0].field_0x34 *
                 JKernel::JMath::jmaSinTable
                 [(int)(uVar4 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
            pEff->mEff[0].mScale.x = pEff->mEff[0].mScale.x + 0_03;
            pEff->mEff[0].mScale.y = pEff->mEff[0].mScale.y + 0_02;
            pEff->mEff[0].mScale.z = pEff->mEff[0].mScale.z + 0_01;
          }
          pos.x = pEff->mEff[0].mBasePos.x + pEff->mEff[0].mPos.x;
          pos.y = pEff->mEff[0].mBasePos.y + pEff->mEff[0].mPos.y;
          pos.z = pEff->mEff[0].mBasePos.z + pEff->mEff[0].mPos.z;
          d_kankyo_wether::dKyw_pntwind_get_vecpow(&pntwind,&pos);
          local_d8.x = pntwind.x;
          local_d8.y = pntwind.y;
          local_d8.z = pntwind.z;
          fVar12 = pEff->mEff[0].mVel.x;
          if (fVar12 < 30_0) {
            pEff->mEff[0].mVel.x = fVar12 + 9_0 * pntwind.x;
          }
          fVar12 = pEff->mEff[0].mVel.y;
          if (fVar12 < 30_0) {
            pEff->mEff[0].mVel.y = fVar12 + 9_0 * pntwind.y;
          }
          fVar12 = pEff->mEff[0].mVel.z;
          if (fVar12 < 30_0) {
            pEff->mEff[0].mVel.z = fVar12 + 9_0 * pntwind.z;
          }
          SComponent::cLib_addCalc(&pEff->mEff[0].mVel.x,0_0,0_2,0_1,1_0E_5);
          SComponent::cLib_addCalc(&pEff->mEff[0].mVel.y,0_0,0_2,0_1,1_0E_5);
          SComponent::cLib_addCalc(&pEff->mEff[0].mVel.z,0_0,0_2,0_1,1_0E_5);
          pEff->mEff[0].mPos.x = pEff->mEff[0].mPos.x + pEff->mEff[0].mVel.x;
          pEff->mEff[0].mPos.y = pEff->mEff[0].mPos.y + pEff->mEff[0].mVel.y;
          pEff->mEff[0].mPos.z = pEff->mEff[0].mPos.z + pEff->mEff[0].mVel.z;
          pos.x = pEff->mEff[0].mBasePos.x + pEff->mEff[0].mPos.x;
          pos.y = pEff->mEff[0].mBasePos.y + pEff->mEff[0].mPos.y;
          pos.z = pEff->mEff[0].mBasePos.z + pEff->mEff[0].mPos.z;
          fVar12 = mtx::PSVECSquareDistance(&pos,&eyeVect);
          dVar10 = (double)fVar12;
          if ((double)0_0 < dVar10) {
            dVar9 = 1.0 / SQRT(dVar10);
            dVar9 = 0_5 * dVar9 * (3_0 - dVar10 * dVar9 * dVar9);
            dVar9 = 0_5 * dVar9 * (3_0 - dVar10 * dVar9 * dVar9);
            dVar10 = (double)(float)(dVar10 * 0_5 * dVar9 * (3_0 - dVar10 * dVar9 * dVar9));
          }
          sVar2 = pEff->mEff[0].field_0x3c;
          if (sVar2 == 0) {
            if (((double)1000_0 < dVar10) || (pos.y < _6088)) {
              pEff->mEff[0].field_0x3c = 10;
              pEff->mEff[0].mBasePos.x = eyeVect.x;
              pEff->mEff[0].mBasePos.y = eyeVect.y;
              pEff->mEff[0].mBasePos.z = eyeVect.z;
              fVar12 = mtx::PSVECSquareDistance(&pos,&eyeVect);
              dVar10 = (double)fVar12;
              if ((double)0_0 < dVar10) {
                dVar9 = 1.0 / SQRT(dVar10);
                dVar9 = 0_5 * dVar9 * (3_0 - dVar10 * dVar9 * dVar9);
                dVar9 = 0_5 * dVar9 * (3_0 - dVar10 * dVar9 * dVar9);
                dVar10 = (double)(float)(dVar10 * 0_5 * dVar9 * (3_0 - dVar10 * dVar9 * dVar9));
              }
              if (dVar10 <= (double)_6089) {
                fVar12 = SComponent::cM_rndFX(50_0);
                dVar10 = (double)fVar12;
                get_vectle_calc(&pos,&eyeVect,&local_d8);
                fVar12 = (float)((double)1000_0 + dVar10);
                pEff->mEff[0].mPos.x = local_d8.x * fVar12;
                pEff->mEff[0].mPos.y = local_d8.y * fVar12;
                pEff->mEff[0].mPos.z = local_d8.z * fVar12;
              }
              else {
                fVar12 = SComponent::cM_rndFX(1000_0);
                pEff->mEff[0].mPos.x = fVar12;
                fVar12 = SComponent::cM_rndFX(1000_0);
                pEff->mEff[0].mPos.y = fVar12;
                fVar12 = SComponent::cM_rndFX(1000_0);
                pEff->mEff[0].mPos.z = fVar12;
              }
              fVar12 = 0_0;
              pEff->mEff[0].mVel.x = 0_0;
              pEff->mEff[0].mVel.y = fVar12;
              pEff->mEff[0].mVel.z = fVar12;
              pEff->mEff[0].mState = 1;
            }
          }
          else {
            pEff->mEff[0].field_0x3c = sVar2 + -1;
          }
        }
      }
      pos.x = pEff->mEff[0].mBasePos.x + pEff->mEff[0].mPos.x;
      pos.y = pEff->mEff[0].mBasePos.y + pEff->mEff[0].mPos.y;
      pos.z = pEff->mEff[0].mBasePos.z + pEff->mEff[0].mPos.z;
      pEff->mEff[0].field_0x4c = pEff->mEff[0].field_0x4c + 600;
      if (30000 < (ushort)pEff->mEff[0].field_0x4c) {
        dVar11 = (double)0_0;
      }
      SComponent::cLib_addCalc(&pEff->mEff[0].mAlpha,(float)dVar11,0_5,0_02,1_0E_5);
      iVar5 = iVar5 + -0x50;
    }
    local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_5c._0_4_ = &PTR_80371f20;
    if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
      local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_5c._0_4_ = &PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0x5c) &&
         (local_5c._0_4_ = &::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0x5c)) {
        local_5c._0_4_ = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar7 != (cBgS_PolyPassChk *)0x0) &&
         (local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar7 != (cBgS_PolyPassChk *)0x0)) {
        local_68.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_a8.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    local_a8.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk(&local_a8.parent);
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dKyr_snow_init(void) */

void dKyr_snow_init(void)

{
  camera_class *pcVar1;
  dKankyo_snow_Packet *pdVar2;
  dKankyo_snow_Packet *pPkt;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  pcVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  pPkt = (dKankyo_snow_Packet *)JKernel::operator_new(0x36e0,0x20);
  pdVar2 = pPkt;
  if (pPkt != (dKankyo_snow_Packet *)0x0) {
    (pPkt->parent).vtbl = (undefined *)&J3DPacket::__vt;
    (pPkt->parent).mpNextSibling = (J3DPacket *)0x0;
    (pPkt->parent).mpFirstChild = (J3DPacket *)0x0;
    (pPkt->parent).field_0xc = (undefined *)0x0;
    (pPkt->parent).vtbl = &dKankyo_snow_Packet::__vt;
    Runtime.PPCEABI.H::__construct_array
              (pPkt->mEff,SNOW_EFF::SNOW_EFF,SNOW_EFF::_SNOW_EFF,0x38,0xfa);
    d_kankyo::g_env_light.mpSnowPacket = pPkt;
    iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Adanmae");
    if (iVar3 == 0) {
      pcVar4 = (char *)dRes_control_c::getRes
                                 ("Stage","ak_kazanbai00.bti",
                                  d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
      (d_kankyo::g_env_light.mpSnowPacket)->mpTexture = pcVar4;
    }
    else {
      pcVar4 = (char *)dRes_control_c::getRes
                                 ("Always",0x81,
                                  d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      (d_kankyo::g_env_light.mpSnowPacket)->mpTexture = pcVar4;
    }
    iVar3 = 0;
    iVar5 = 0xfa;
    do {
      (&(d_kankyo::g_env_light.mpSnowPacket)->mEff[0].mStatus)[iVar3] = 0;
      iVar3 = iVar3 + 0x38;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    (d_kankyo::g_env_light.mpSnowPacket)->mEffCount = 0;
    pdVar2 = d_kankyo::g_env_light.mpSnowPacket;
    ((d_kankyo::g_env_light.mpSnowPacket)->mOldEyePos).x = (pcVar1->mEyePos).x;
    (pdVar2->mOldEyePos).y = (pcVar1->mEyePos).y;
    (pdVar2->mOldEyePos).z = (pcVar1->mEyePos).z;
    pdVar2 = d_kankyo::g_env_light.mpSnowPacket;
  }
  d_kankyo::g_env_light.mpSnowPacket = pdVar2;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x8008f9d4) */
/* WARNING: Removing unreachable block (ram,0x8008f9c4) */
/* WARNING: Removing unreachable block (ram,0x8008f9bc) */
/* WARNING: Removing unreachable block (ram,0x8008f9cc) */
/* WARNING: Removing unreachable block (ram,0x8008f9dc) */
/* __stdcall dKyr_snow_move(void) */

void dKyr_snow_move(void)

{
  byte bVar1;
  short sVar2;
  dKankyo_snow_Packet *pdVar3;
  cXyz *pWindvec;
  uint uVar4;
  int iVar5;
  uint uVar6;
  float *pWindSpeed;
  dKankyo_snow_Packet *pEff;
  undefined4 uVar7;
  double dVar8;
  double dVar9;
  double windpow;
  double dVar10;
  undefined8 in_f27;
  double dVar11;
  undefined8 in_f28;
  double dVar12;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar13;
  undefined8 in_f31;
  cXyz local_e8;
  cXyz local_dc;
  cXyz local_d0;
  cXyz pos;
  cXyz windvec;
  cXyz eyevect;
  DOUBLE_POS local_90;
  undefined4 local_78;
  uint uStack116;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  camera_class *pCam;
  float scaleTarget;
  
  pdVar3 = d_kankyo::g_env_light.mpSnowPacket;
  pCam = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar7 = 0;
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
  d_kankyo_wether::dKyw_get_wind_vecpow(&local_e8);
  if (pdVar3->mEffCount <= d_kankyo::g_env_light.mSnowCount) {
    pdVar3->mEffCount = (short)d_kankyo::g_env_light.mSnowCount;
  }
  if (pdVar3->mEffCount != 0) {
    dKy_set_eyevect_calc2(pCam,&eyevect,500_0,500_0);
    scaleTarget = mtx::PSVECSquareDistance(&pdVar3->mOldEyePos,&pCam->mEyePos);
    windpow = (double)scaleTarget;
    if ((double)0_0 < windpow) {
      dVar8 = 1.0 / SQRT(windpow);
      dVar8 = 0_5 * dVar8 * (3_0 - windpow * dVar8 * dVar8);
      dVar8 = 0_5 * dVar8 * (3_0 - windpow * dVar8 * dVar8);
      windpow = (double)(float)(windpow * 0_5 * dVar8 * (3_0 - windpow * dVar8 * dVar8));
    }
    if ((double)1500_0 < windpow) {
      pdVar3->mEffCount = 0;
    }
    (pdVar3->mOldEyePos).x = (pCam->mEyePos).x;
    (pdVar3->mOldEyePos).y = (pCam->mEyePos).y;
    (pdVar3->mOldEyePos).z = (pCam->mEyePos).z;
    pWindvec = d_kankyo_wether::dKyw_get_wind_vec();
    windpow = d_kankyo_wether::dKyw_get_wind_pow();
    local_90.x = (double)((pCam->mCenterPos).x - (pCam->mEyePos).x);
    local_90.y = 0_0;
    local_90.z = (double)((pCam->mCenterPos).z - (pCam->mEyePos).z);
    vectle_calc(&local_90,&local_dc);
    pdVar3->field_0x36d4 =
         (-pWindvec->x - 0_0) * (local_dc.z - 0_0) - (-pWindvec->z - 0_0) * (local_dc.x - 0_0);
    pdVar3->field_0x36d0 =
         (float)((double)(1_0 - ABS(pWindvec->x * local_dc.x + pWindvec->z * local_dc.z)) * windpow)
         * (1_0 - ABS(pWindvec->y));
    pdVar3->field_0x36d0 = pdVar3->field_0x36d0 * ABS(pdVar3->field_0x36d4);
    uVar6 = (int)pdVar3->mEffCount - 1;
    dVar8 = (double)1_5;
    dVar13 = (double)5_0;
    iVar5 = uVar6 * 0x38;
    windpow = _4175;
    for (; -1 < (int)uVar6; uVar6 = uVar6 - 1) {
      scaleTarget = SComponent::cM_rndF(8_5);
      dVar12 = -(double)(float)(dVar8 + (double)scaleTarget);
      uStack116 = uVar6 & 0xf ^ 0x80000000;
      local_78 = 0x43300000;
      scaleTarget = (float)(dVar13 + (double)(float)((double)CONCAT44(0x43300000,uStack116) -
                                                    windpow));
      dVar11 = (double)scaleTarget;
      pEff = (dKankyo_snow_Packet *)((int)pdVar3->mEff + iVar5 + -0x14);
      bVar1 = pEff->mEff[0].mStatus;
      if (bVar1 == 0) {
        pEff->mEff[0].mWindSpeed = scaleTarget;
        pEff->mEff[0].mGravity = (float)dVar12;
        pEff->mEff[0].mTimer = 0;
        pEff->mEff[0].mBasePos.x = eyevect.x;
        pEff->mEff[0].mBasePos.y = eyevect.y;
        pEff->mEff[0].mBasePos.z = eyevect.z;
        scaleTarget = SComponent::cM_rndFX(550_0);
        pEff->mEff[0].mPos.x = scaleTarget;
        scaleTarget = 550_0;
        pEff->mEff[0].mPos.y = 550_0;
        scaleTarget = SComponent::cM_rndFX(scaleTarget);
        pEff->mEff[0].mPos.z = scaleTarget;
        pEff->mEff[0].mScale = 0_0;
        scaleTarget = SComponent::cM_rndF(360_0);
        pEff->mEff[0].mPosWaveX = scaleTarget;
        scaleTarget = SComponent::cM_rndF(360_0);
        pEff->mEff[0].mPosWaveZ = scaleTarget;
        pEff->mEff[0].mStatus = pEff->mEff[0].mStatus + 1;
      }
      else {
        if ((-1 < (char)bVar1) && ((char)bVar1 < '\x04')) {
          scaleTarget = SComponent::cM_rndFX(0_1);
          pWindSpeed = &pEff->mEff[0].mWindSpeed;
          SComponent::cLib_addCalc(pWindSpeed,pEff->mEff[0].mWindSpeed - scaleTarget,0_5,0_1,0_01);
          if ((pEff->mEff[0].mStatus != 3) || (pEff->mEff[0].mScale < 0_01)) {
            pEff->mEff[0].mPos.x = pEff->mEff[0].mPos.x + local_e8.x * *pWindSpeed;
            pEff->mEff[0].mPos.z = pEff->mEff[0].mPos.z + local_e8.z * *pWindSpeed;
            pEff->mEff[0].mPos.y =
                 pEff->mEff[0].mPos.y + pEff->mEff[0].mGravity + local_e8.y * *pWindSpeed;
            uVar4 = SComponent::cM_rad2s((double)pEff->mEff[0].mPosWaveX);
            pEff->mEff[0].mPos.x =
                 pEff->mEff[0].mPos.x +
                 1_5 * JKernel::JMath::jmaSinTable
                       [(int)(uVar4 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
            uVar4 = SComponent::cM_rad2s((double)pEff->mEff[0].mPosWaveZ);
            pEff->mEff[0].mPos.z =
                 pEff->mEff[0].mPos.z +
                 1_5 * JKernel::JMath::jmaSinTable
                       [(int)(uVar4 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
            scaleTarget = 0_02;
            pEff->mEff[0].mPosWaveX = pEff->mEff[0].mPosWaveX + 0_02;
            pEff->mEff[0].mPosWaveZ = pEff->mEff[0].mPosWaveZ + scaleTarget;
          }
          pos.x = pEff->mEff[0].mBasePos.x + pEff->mEff[0].mPos.x;
          pos.y = pEff->mEff[0].mBasePos.y + pEff->mEff[0].mPos.y;
          pos.z = pEff->mEff[0].mBasePos.z + pEff->mEff[0].mPos.z;
          scaleTarget = mtx::PSVECSquareDistance(&pos,&eyevect);
          dVar10 = (double)scaleTarget;
          if ((double)0_0 < dVar10) {
            dVar9 = 1.0 / SQRT(dVar10);
            dVar9 = 0_5 * dVar9 * (3_0 - dVar10 * dVar9 * dVar9);
            dVar9 = 0_5 * dVar9 * (3_0 - dVar10 * dVar9 * dVar9);
            dVar10 = (double)(float)(dVar10 * 0_5 * dVar9 * (3_0 - dVar10 * dVar9 * dVar9));
          }
          sVar2 = pEff->mEff[0].mTimer;
          if (sVar2 == 0) {
            if ((double)550_0 < dVar10) {
              pEff->mEff[0].mTimer = 10;
              *pWindSpeed = (float)dVar11;
              pEff->mEff[0].mGravity = (float)dVar12;
              pEff->mEff[0].mBasePos.x = eyevect.x;
              pEff->mEff[0].mBasePos.y = eyevect.y;
              pEff->mEff[0].mBasePos.z = eyevect.z;
              scaleTarget = mtx::PSVECSquareDistance(&pos,&eyevect);
              dVar11 = (double)scaleTarget;
              if ((double)0_0 < dVar11) {
                dVar12 = 1.0 / SQRT(dVar11);
                dVar12 = 0_5 * dVar12 * (3_0 - dVar11 * dVar12 * dVar12);
                dVar12 = 0_5 * dVar12 * (3_0 - dVar11 * dVar12 * dVar12);
                dVar11 = (double)(float)(dVar11 * 0_5 * dVar12 * (3_0 - dVar11 * dVar12 * dVar12));
              }
              if (dVar11 <= (double)600_0) {
                scaleTarget = SComponent::cM_rndFX(27_5);
                dVar11 = (double)scaleTarget;
                get_vectle_calc(&pos,&eyevect,&local_d0);
                scaleTarget = (float)((double)550_0 + dVar11);
                pEff->mEff[0].mPos.x = local_d0.x * scaleTarget;
                pEff->mEff[0].mPos.y = local_d0.y * scaleTarget;
                pEff->mEff[0].mPos.z = local_d0.z * scaleTarget;
              }
              else {
                scaleTarget = SComponent::cM_rndFX(550_0);
                pEff->mEff[0].mPos.x = scaleTarget;
                scaleTarget = SComponent::cM_rndFX(550_0);
                pEff->mEff[0].mPos.y = scaleTarget;
                scaleTarget = SComponent::cM_rndFX(550_0);
                pEff->mEff[0].mPos.z = scaleTarget;
              }
              pEff->mEff[0].mStatus = 1;
            }
          }
          else {
            pEff->mEff[0].mTimer = sVar2 + -1;
          }
        }
      }
      pos.x = pEff->mEff[0].mBasePos.x + pEff->mEff[0].mPos.x;
      pos.y = pEff->mEff[0].mBasePos.y + pEff->mEff[0].mPos.y;
      pos.z = pEff->mEff[0].mBasePos.z + pEff->mEff[0].mPos.z;
      scaleTarget = 0_0;
      if (pEff->mEff[0].mStatus != 3) {
        scaleTarget = mtx::PSVECSquareDistance(&pos,&pCam->mEyePos);
        dVar11 = (double)scaleTarget;
        if ((double)0_0 < dVar11) {
          dVar12 = 1.0 / SQRT(dVar11);
          dVar12 = 0_5 * dVar12 * (3_0 - dVar11 * dVar12 * dVar12);
          dVar12 = 0_5 * dVar12 * (3_0 - dVar11 * dVar12 * dVar12);
          dVar11 = (double)(float)(dVar11 * 0_5 * dVar12 * (3_0 - dVar11 * dVar12 * dVar12));
        }
        scaleTarget = (float)((double)62_5 + dVar11);
        if ((float)((double)62_5 + dVar11) < 0_0) {
          scaleTarget = 0_0;
        }
        scaleTarget = 1_0 - scaleTarget / 1125_0;
        if (1_0 < scaleTarget) {
          scaleTarget = 1_0;
        }
        if (scaleTarget < 0_0) {
          scaleTarget = 0_0;
        }
      }
      if (d_kankyo::g_env_light.mSnowCount + -1 < (int)uVar6) {
        SComponent::cLib_addCalc(&pEff->mEff[0].mScale,0_0,0_2,0_1,0_01);
      }
      else {
        pEff->mEff[0].mScale = scaleTarget;
      }
      if (((d_kankyo::g_env_light.mSnowCount + -1 < (int)uVar6) && (pEff->mEff[0].mScale < 0_01)) &&
         (uVar4 = (int)pdVar3->mEffCount - 1, uVar6 == uVar4)) {
        pdVar3->mEffCount = (short)uVar4;
      }
      iVar5 = iVar5 + -0x38;
    }
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  __psq_l0(auStack56,uVar7);
  __psq_l1(auStack56,uVar7);
  __psq_l0(auStack72,uVar7);
  __psq_l1(auStack72,uVar7);
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Removing unreachable block (ram,0x80090634) */
/* WARNING: Removing unreachable block (ram,0x80090624) */
/* WARNING: Removing unreachable block (ram,0x80090614) */
/* WARNING: Removing unreachable block (ram,0x80090604) */
/* WARNING: Removing unreachable block (ram,0x800905f4) */
/* WARNING: Removing unreachable block (ram,0x800905fc) */
/* WARNING: Removing unreachable block (ram,0x8009060c) */
/* WARNING: Removing unreachable block (ram,0x8009061c) */
/* WARNING: Removing unreachable block (ram,0x8009062c) */
/* WARNING: Removing unreachable block (ram,0x8009063c) */
/* __stdcall dKyr_kazanbai_move(void) */

void dKyr_kazanbai_move(void)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  cXyz *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  float *pSrc;
  dKankyo_snow_Packet *pPktEff;
  cBgS_PolyPassChk *pcVar8;
  undefined4 uVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  undefined8 in_f22;
  double asdf;
  undefined8 in_f23;
  double dVar15;
  undefined8 in_f24;
  undefined8 in_f25;
  double dVar16;
  undefined8 in_f26;
  double dVar17;
  undefined8 in_f27;
  double dVar18;
  undefined8 in_f28;
  double dVar19;
  undefined8 in_f29;
  double dVar20;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar21;
  float fVar22;
  cXyz local_1b8;
  cXyz local_1ac;
  float local_1a0;
  float local_19c;
  float local_198;
  cXyz local_194;
  cXyz local_188;
  cXyz local_164;
  DOUBLE_POS local_158;
  cBgS_GndChk local_140;
  cBgS_PolyPassChk local_100;
  undefined local_f4 [12];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  camera_class *pCam;
  dKankyo_snow_Packet *pPkt;
  
  pPkt = d_kankyo::g_env_light.mpSnowPacket;
  pCam = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar9 = 0;
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
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  d_kankyo_wether::dKyw_get_wind_vecpow(&local_1b8);
  ::cBgS_GndChk::cBgS_GndChk(&local_140);
  pcVar8 = &local_100;
  local_100.mbCamThrough = 0;
  local_100.mbLinkThrough = 0;
  local_100.mbArrowsAndLightThrough = 0;
  local_100.mbBombThrough = 0;
  local_100.mbBoomerangThrough = 0;
  local_100.mbHookshotThrough = 0;
  local_140.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar8;
  if (pcVar8 != (cBgS_PolyPassChk *)0x0) {
    local_140.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_f4;
  }
  local_100.mbObjThrough = 1;
  local_140.parent.vtbl = &::dBgS_ObjGndChk_All::__vt;
  local_140.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_8037d43c;
  local_100.vtbl = &cBgS_PolyPassChk__vtbl_8037d448;
  local_f4._0_4_ = &cBgS_GrpPassChk__vtbl_8037d454;
  local_f4._4_4_ = 0xf;
  iVar7 = 0;
  if (pPkt->mEffCount <= d_kankyo::g_env_light.mSnowCount) {
    pPkt->mEffCount = (short)d_kankyo::g_env_light.mSnowCount;
  }
  local_140.parent.mpPolyPassChk = pcVar8;
  if (pPkt->mEffCount == 0) {
    local_100.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_f4._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
    if (pcVar8 != (cBgS_PolyPassChk *)0x0) {
      local_100.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_f4._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0xf4) &&
         (local_f4._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0xf4)) {
        local_f4._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar8 != (cBgS_PolyPassChk *)0x0) &&
         (local_100.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar8 != (cBgS_PolyPassChk *)0x0)) {
        local_100.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_140.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    local_140.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk(&local_140.parent);
  }
  else {
    local_1a0 = 734_0;
    local_19c = 3000_0;
    local_198 = 491_0;
    local_140.mPos.x = 734_0;
    local_140.mPos.y = 3000_0;
    local_140.mPos.z = 491_0;
    dVar12 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_140)
    ;
    dKy_set_eyevect_calc2(pCam,&local_164,800_0,800_0);
    fVar21 = mtx::PSVECSquareDistance(&pPkt->mOldEyePos,&pCam->mEyePos);
    dVar13 = (double)fVar21;
    if ((double)0_0 < dVar13) {
      dVar10 = 1.0 / SQRT(dVar13);
      dVar10 = 0_5 * dVar10 * (3_0 - dVar13 * dVar10 * dVar10);
      dVar10 = 0_5 * dVar10 * (3_0 - dVar13 * dVar10 * dVar10);
      dVar13 = (double)(float)(dVar13 * 0_5 * dVar10 * (3_0 - dVar13 * dVar10 * dVar10));
    }
    if ((double)1500_0 < dVar13) {
      pPkt->mEffCount = 0;
    }
    (pPkt->mOldEyePos).x = (pCam->mEyePos).x;
    (pPkt->mOldEyePos).y = (pCam->mEyePos).y;
    (pPkt->mOldEyePos).z = (pCam->mEyePos).z;
    pcVar4 = d_kankyo_wether::dKyw_get_wind_vec();
    dVar13 = d_kankyo_wether::dKyw_get_wind_pow();
    local_158.x = (double)((pCam->mCenterPos).x - (pCam->mEyePos).x);
    local_158.y = 0_0;
    local_158.z = (double)((pCam->mCenterPos).z - (pCam->mEyePos).z);
    vectle_calc(&local_158,&local_1ac);
    dVar17 = (double)0_0;
    pPkt->field_0x36d4 =
         (float)(-(double)pcVar4->x - dVar17) * (float)((double)local_1ac.z - dVar17) -
         (float)(-(double)pcVar4->z - dVar17) * (float)((double)local_1ac.x - dVar17);
    dVar18 = (double)1_0;
    pPkt->field_0x36d0 =
         (float)((double)(float)(dVar18 - (double)ABS(pcVar4->x * local_1ac.x +
                                                      pcVar4->z * local_1ac.z)) * dVar13) *
         (float)(dVar18 - (double)ABS(pcVar4->y));
    pPkt->field_0x36d0 = pPkt->field_0x36d0 * ABS(pPkt->field_0x36d4);
    uVar6 = (int)pPkt->mEffCount - 1;
    dVar19 = (double)2_5;
    dVar20 = (double)9_0;
    dVar16 = (double)30_0;
    dVar10 = (double)800_0;
    iVar5 = uVar6 * 0x38;
    dVar13 = dVar17;
    for (; -1 < (int)uVar6; uVar6 = uVar6 - 1) {
      fVar21 = SComponent::cM_rndFX(2_0);
      dVar15 = -(double)(float)(dVar19 + (double)fVar21);
      fVar22 = SComponent::cM_rndF(60_0);
      fVar21 = 0_028;
      asdf = (double)(float)(dVar20 + (double)fVar22);
      pPktEff = (dKankyo_snow_Packet *)((int)pPkt->mEff + iVar5 + -0x14);
      bVar1 = pPktEff->mEff[0].mStatus;
      if (bVar1 == 1) {
        fVar21 = SComponent::cM_rndFX(0_1);
        pSrc = &pPktEff->mEff[0].mWindSpeed;
        SComponent::cLib_addCalc(pSrc,pPktEff->mEff[0].mWindSpeed - fVar21,0_5,0_1,0_01);
        pPktEff->mEff[0].mPos.x = pPktEff->mEff[0].mPos.x + local_1b8.x * *pSrc;
        pPktEff->mEff[0].mPos.z = pPktEff->mEff[0].mPos.z + local_1b8.z * *pSrc;
        pPktEff->mEff[0].mPos.y =
             pPktEff->mEff[0].mPos.y + pPktEff->mEff[0].mGravity + local_1b8.y * *pSrc;
        uVar3 = SComponent::cM_rad2s((double)pPktEff->mEff[0].mPosWaveX);
        pPktEff->mEff[0].mPos.x =
             pPktEff->mEff[0].mPos.x +
             2_5 * JKernel::JMath::jmaSinTable
                   [(int)(uVar3 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
        uVar3 = SComponent::cM_rad2s((double)pPktEff->mEff[0].mPosWaveZ);
        pPktEff->mEff[0].mPos.z =
             pPktEff->mEff[0].mPos.z +
             3_0 * JKernel::JMath::jmaSinTable
                   [(int)(uVar3 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
        uVar3 = SComponent::cM_rad2s((double)pPktEff->mEff[0].mPosWaveZ);
        pPktEff->mEff[0].mPos.y =
             pPktEff->mEff[0].mPos.y +
             JKernel::JMath::jmaSinTable
             [(int)(uVar3 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
        fVar21 = 0_03;
        pPktEff->mEff[0].mPosWaveX = pPktEff->mEff[0].mPosWaveX + 0_03;
        pPktEff->mEff[0].mPosWaveZ = pPktEff->mEff[0].mPosWaveZ + fVar21;
        local_188.x = pPktEff->mEff[0].mBasePos.x + pPktEff->mEff[0].mPos.x;
        local_188.y = pPktEff->mEff[0].mBasePos.y + pPktEff->mEff[0].mPos.y;
        local_188.z = pPktEff->mEff[0].mBasePos.z + pPktEff->mEff[0].mPos.z;
        fVar21 = mtx::PSVECSquareDistance(&local_188,&local_164);
        dVar14 = (double)fVar21;
        if ((double)0_0 < dVar14) {
          dVar11 = 1.0 / SQRT(dVar14);
          dVar11 = 0_5 * dVar11 * (3_0 - dVar14 * dVar11 * dVar11);
          dVar11 = 0_5 * dVar11 * (3_0 - dVar14 * dVar11 * dVar11);
          dVar14 = (double)(float)(dVar14 * 0_5 * dVar11 * (3_0 - dVar14 * dVar11 * dVar11));
        }
        sVar2 = pPktEff->mEff[0].mTimer;
        if (sVar2 == 0) {
          if ((double)800_0 < dVar14) {
            pPktEff->mEff[0].mTimer = 10;
            *pSrc = (float)asdf;
            pPktEff->mEff[0].mGravity = (float)dVar15;
            pPktEff->mEff[0].mBasePos.x = local_164.x;
            pPktEff->mEff[0].mBasePos.y = local_164.y;
            pPktEff->mEff[0].mBasePos.z = local_164.z;
            fVar21 = mtx::PSVECSquareDistance(&local_188,&local_164);
            asdf = (double)fVar21;
            if ((double)0_0 < asdf) {
              dVar15 = 1.0 / SQRT(asdf);
              dVar15 = 0_5 * dVar15 * (3_0 - asdf * dVar15 * dVar15);
              dVar15 = 0_5 * dVar15 * (3_0 - asdf * dVar15 * dVar15);
              asdf = (double)(float)(asdf * 0_5 * dVar15 * (3_0 - asdf * dVar15 * dVar15));
            }
            if (asdf <= (double)_6658) {
              fVar21 = SComponent::cM_rndFX(40_0);
              asdf = (double)fVar21;
              get_vectle_calc(&local_188,&local_164,&local_194);
              fVar21 = (float)((double)800_0 + asdf);
              pPktEff->mEff[0].mPos.x = local_194.x * fVar21;
              pPktEff->mEff[0].mPos.y = local_194.y * fVar21;
              pPktEff->mEff[0].mPos.z = local_194.z * fVar21;
            }
            else {
              fVar21 = SComponent::cM_rndFX(800_0);
              pPktEff->mEff[0].mPos.x = fVar21;
              fVar21 = SComponent::cM_rndFX(800_0);
              pPktEff->mEff[0].mPos.y = fVar21;
              fVar21 = SComponent::cM_rndFX(800_0);
              pPktEff->mEff[0].mPos.z = fVar21;
            }
            pPktEff->mEff[0].mStatus = 1;
          }
        }
        else {
          pPktEff->mEff[0].mTimer = sVar2 + -1;
        }
        if (((double)0_0 < dVar12) && ((double)local_188.y < dVar12)) {
          if ((dVar12 <= (double)0_0) ||
             ((99 < iVar7 || ((SComponent::g_Counter & 7) != (uVar6 & 7))))) {
            pPktEff->mEff[0].mStatus = 0;
          }
          else {
            pPktEff->mEff[0].mScale = 0_01;
            pPktEff->mEff[0].mTimer = ((ushort)uVar6 & 0xf) + 0x14;
            pPktEff->mEff[0].mStatus = 2;
            iVar7 = iVar7 + 1;
          }
        }
      }
      else {
        if ((char)bVar1 < '\x01') {
          if (-1 < (char)bVar1) {
            pPktEff->mEff[0].mWindSpeed = (float)(dVar20 + (double)fVar22);
            pPktEff->mEff[0].mGravity = (float)dVar15;
            pPktEff->mEff[0].mTimer = 0;
            pPktEff->mEff[0].mBasePos.x = local_164.x;
            pPktEff->mEff[0].mBasePos.y = local_164.y;
            pPktEff->mEff[0].mBasePos.z = local_164.z;
            fVar21 = SComponent::cM_rndFX(800_0);
            pPktEff->mEff[0].mPos.x = fVar21;
            fVar21 = 800_0;
            pPktEff->mEff[0].mPos.y = 800_0;
            fVar21 = SComponent::cM_rndFX(fVar21);
            pPktEff->mEff[0].mPos.z = fVar21;
            pPktEff->mEff[0].mScale = 0_0;
            fVar21 = SComponent::cM_rndF(360_0);
            pPktEff->mEff[0].mPosWaveX = fVar21;
            fVar21 = SComponent::cM_rndF(360_0);
            pPktEff->mEff[0].mPosWaveZ = fVar21;
            pPktEff->mEff[0].mStatus = pPktEff->mEff[0].mStatus + 1;
          }
        }
        else {
          if ((char)bVar1 < '\x03') {
            pPktEff->mEff[0].mPos.x =
                 pPktEff->mEff[0].mPos.x + local_1b8.x * 0_028 * pPktEff->mEff[0].mWindSpeed;
            pPktEff->mEff[0].mPos.z =
                 pPktEff->mEff[0].mPos.z + local_1b8.z * fVar21 * pPktEff->mEff[0].mWindSpeed;
            pPktEff->mEff[0].mPos.y =
                 (float)(dVar12 - (double)pPktEff->mEff[0].mBasePos.y) -
                 7_0 * (1_0 - pPktEff->mEff[0].mScale);
            sVar2 = pPktEff->mEff[0].mTimer;
            if (sVar2 != 0) {
              pPktEff->mEff[0].mTimer = sVar2 + -1;
            }
            if (pPktEff->mEff[0].mScale <= 0_001) {
              pPktEff->mEff[0].mStatus = 0;
            }
            iVar7 = iVar7 + 1;
          }
        }
      }
      local_188.x = pPktEff->mEff[0].mBasePos.x + pPktEff->mEff[0].mPos.x;
      local_188.y = pPktEff->mEff[0].mBasePos.y + pPktEff->mEff[0].mPos.y;
      local_188.z = pPktEff->mEff[0].mBasePos.z + pPktEff->mEff[0].mPos.z;
      fVar21 = mtx::PSVECSquareDistance(&local_188,&local_164);
      asdf = (double)fVar21;
      if (dVar17 < asdf) {
        dVar15 = 1.0 / SQRT(asdf);
        dVar15 = 0_5 * dVar15 * (3_0 - asdf * dVar15 * dVar15);
        dVar15 = 0_5 * dVar15 * (3_0 - asdf * dVar15 * dVar15);
        asdf = (double)(float)(asdf * 0_5 * dVar15 * (3_0 - asdf * dVar15 * dVar15));
      }
      dVar15 = (double)(float)(dVar16 + asdf);
      if ((double)(float)(dVar16 + asdf) < dVar17) {
        dVar15 = dVar17;
      }
      asdf = (double)(float)(dVar18 - (double)(float)(dVar15 / dVar10));
      if (dVar18 < asdf) {
        asdf = dVar18;
      }
      if (asdf < dVar13) {
        asdf = dVar13;
      }
      if (((int)uVar6 < d_kankyo::g_env_light.mSnowCount + -1) && (pPktEff->mEff[0].mStatus != 2)) {
        pPktEff->mEff[0].mScale = (float)asdf;
      }
      else {
        if (pPktEff->mEff[0].mStatus == 2) {
          if (pPktEff->mEff[0].mTimer == 0) {
            SComponent::cLib_addCalc(&pPktEff->mEff[0].mScale,0_0,0_1,0_03,1_0E_5);
          }
          else {
            SComponent::cLib_addCalc(&pPktEff->mEff[0].mScale,1_0,0_5,0_1,1_0E_5);
          }
        }
        else {
          SComponent::cLib_addCalc(&pPktEff->mEff[0].mScale,0_0,0_2,0_1,0_01);
        }
      }
      if (((d_kankyo::g_env_light.mSnowCount + -1 <= (int)uVar6) && (pPktEff->mEff[0].mScale < 0_01)
          ) && (uVar3 = (int)pPkt->mEffCount - 1, uVar6 == uVar3)) {
        pPkt->mEffCount = (short)uVar3;
      }
      iVar5 = iVar5 + -0x38;
    }
    dKyr_kazanbai_tamari_move();
    local_100.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_f4._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
    if (pcVar8 != (cBgS_PolyPassChk *)0x0) {
      local_100.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_f4._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0xf4) &&
         (local_f4._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0xf4)) {
        local_f4._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar8 != (cBgS_PolyPassChk *)0x0) &&
         (local_100.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar8 != (cBgS_PolyPassChk *)0x0)) {
        local_100.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_140.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    local_140.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk(&local_140.parent);
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  __psq_l0(auStack40,uVar9);
  __psq_l1(auStack40,uVar9);
  __psq_l0(auStack56,uVar9);
  __psq_l1(auStack56,uVar9);
  __psq_l0(auStack72,uVar9);
  __psq_l1(auStack72,uVar9);
  __psq_l0(auStack88,uVar9);
  __psq_l1(auStack88,uVar9);
  __psq_l0(auStack104,uVar9);
  __psq_l1(auStack104,uVar9);
  __psq_l0(auStack120,uVar9);
  __psq_l1(auStack120,uVar9);
  __psq_l0(auStack136,uVar9);
  __psq_l1(auStack136,uVar9);
  __psq_l0(auStack152,uVar9);
  __psq_l1(auStack152,uVar9);
  return;
}


/* WARNING: Inlined function: FUN_80328f0c */
/* WARNING: Inlined function: FUN_80328f58 */
/* WARNING: Removing unreachable block (ram,0x80090c40) */
/* WARNING: Removing unreachable block (ram,0x80090c30) */
/* WARNING: Removing unreachable block (ram,0x80090c28) */
/* WARNING: Removing unreachable block (ram,0x80090c38) */
/* WARNING: Removing unreachable block (ram,0x80090c48) */
/* __stdcall dKyr_kazanbai_tamari_move(void) */

void dKyr_kazanbai_tamari_move(void)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  dKankyo_snow_Packet *pEff;
  cBgS_PolyPassChk *pcVar5;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f27;
  double dVar8;
  undefined8 in_f28;
  double dVar9;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  float fVar12;
  cXyz windvecpow;
  cXyz local_11c;
  float local_f8;
  float local_f0;
  cBgS_GndChk local_ec;
  cBgS_PolyPassChk local_ac;
  undefined local_a0 [8];
  longlong local_98;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  dKankyo_snow_Packet *pPkt;
  
  pPkt = d_kankyo::g_env_light.mpSnowPacket;
  uVar6 = 0;
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
  d_kankyo_wether::dKyw_get_wind_vecpow(&windvecpow);
  ::cBgS_GndChk::cBgS_GndChk(&local_ec);
  pcVar5 = &local_ac;
  local_ac.mbCamThrough = 0;
  local_ac.mbLinkThrough = 0;
  local_ac.mbArrowsAndLightThrough = 0;
  local_ac.mbBombThrough = 0;
  local_ac.mbBoomerangThrough = 0;
  local_ac.mbHookshotThrough = 0;
  local_ec.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar5;
  if (pcVar5 != (cBgS_PolyPassChk *)0x0) {
    local_ec.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_a0;
  }
  local_ac.mbObjThrough = 1;
  local_ec.parent.vtbl = &::dBgS_ObjGndChk_All::__vt;
  local_ec.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_8037d43c;
  local_ac.vtbl = &cBgS_PolyPassChk__vtbl_8037d448;
  local_a0._0_4_ = &cBgS_GrpPassChk__vtbl_8037d454;
  local_a0._4_4_ = 0xf;
  local_ec.parent.mpPolyPassChk = pcVar5;
  if (d_kankyo::g_env_light.mSnowCount == 0) {
    local_ac.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_a0._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
    if (pcVar5 != (cBgS_PolyPassChk *)0x0) {
      local_ac.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_a0._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0xa0) &&
         (local_a0._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0xa0)) {
        local_a0._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar5 != (cBgS_PolyPassChk *)0x0) &&
         (local_ac.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar5 != (cBgS_PolyPassChk *)0x0)) {
        local_ac.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_ec.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    local_ec.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk(&local_ec.parent);
  }
  else {
    pPkt->mTamariStart = 0x32;
    local_ec.mPos.x = 734_0;
    local_ec.mPos.y = 3000_0;
    local_ec.mPos.z = 491_0;
    dVar7 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_ec);
    if (dVar7 <= (double)0_0) {
      local_f8 = 109_0;
      local_f0 = 402_0;
      fVar12 = 450_0;
    }
    else {
      local_f8 = _367_0;
      local_f0 = 368_0;
      fVar12 = 1000_0;
    }
    dVar9 = (double)fVar12;
    d_kankyo_wether::dKyw_get_wind_vec();
    d_kankyo_wether::dKyw_get_wind_pow();
    iVar4 = pPkt->mTamariStart + 200;
    dVar10 = (double)1_5;
    dVar11 = (double)9_0;
    iVar3 = iVar4 * 0x38;
    for (; 199 < iVar4; iVar4 = iVar4 + -1) {
      fVar12 = SComponent::cM_rndFX(3_0);
      dVar8 = -(double)(float)(dVar10 + (double)fVar12);
      fVar12 = SComponent::cM_rndF(60_0);
      pEff = (dKankyo_snow_Packet *)((int)pPkt->mEff + iVar3 + -0x14);
      bVar1 = pEff->mEff[0].mStatus;
      if (bVar1 == 1) {
        sVar2 = pEff->mEff[0].mTimer;
        if (sVar2 != 0) {
          pEff->mEff[0].mTimer = sVar2 + -1;
        }
        fVar12 = 0_02;
        pEff->mEff[0].mPos.x =
             pEff->mEff[0].mPos.x +
             windvecpow.x * 0_02 * pEff->mEff[0].mWindSpeed * pEff->mEff[0].mScale;
        pEff->mEff[0].mPos.z =
             pEff->mEff[0].mPos.z +
             windvecpow.z * fVar12 * pEff->mEff[0].mWindSpeed * pEff->mEff[0].mScale;
        pEff->mEff[0].mPos.y = (float)(dVar7 - (double)4_0) - 5_0 * (1_0 - pEff->mEff[0].mScale);
        if ((pEff->mEff[0].mTimer < 1) && (pEff->mEff[0].mScale < 0_0001)) {
          pEff->mEff[0].mStatus = 0;
        }
        if (pEff->mEff[0].mTimer == 0) {
          SComponent::cLib_addCalc(&pEff->mEff[0].mScale,0_0,0_1,0_02,0_0001);
        }
        else {
          SComponent::cLib_addCalc(&pEff->mEff[0].mScale,1_0,0_5,0_1,0_0001);
        }
      }
      else {
        if (((char)bVar1 < '\x01') && (-1 < (char)bVar1)) {
          pEff->mEff[0].mWindSpeed = (float)(dVar11 + (double)fVar12);
          pEff->mEff[0].mGravity = (float)dVar8;
          pEff->mEff[0].mBasePos.x = local_f8;
          pEff->mEff[0].mBasePos.y = 0_0;
          pEff->mEff[0].mBasePos.z = local_f0;
          fVar12 = SComponent::cM_rndFX((float)dVar9);
          pEff->mEff[0].mPos.x = fVar12;
          pEff->mEff[0].mPos.y = (float)dVar7;
          fVar12 = SComponent::cM_rndFX((float)dVar9);
          pEff->mEff[0].mPos.z = fVar12;
          pEff->mEff[0].mScale = 0_0;
          fVar12 = SComponent::cM_rndF(360_0);
          pEff->mEff[0].mPosWaveX = fVar12;
          fVar12 = SComponent::cM_rndF(360_0);
          pEff->mEff[0].mPosWaveZ = fVar12;
          fVar12 = SComponent::cM_rndF(20_0);
          local_98 = (longlong)(int)(20_0 + fVar12);
          pEff->mEff[0].mTimer = (short)(int)(20_0 + fVar12);
          pEff->mEff[0].mStatus = pEff->mEff[0].mStatus + 1;
        }
      }
      iVar3 = iVar3 + -0x38;
    }
    local_ac.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_a0._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
    if (pcVar5 != (cBgS_PolyPassChk *)0x0) {
      local_ac.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_a0._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0xa0) &&
         (local_a0._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0xa0)) {
        local_a0._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar5 != (cBgS_PolyPassChk *)0x0) &&
         (local_ac.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar5 != (cBgS_PolyPassChk *)0x0)) {
        local_ac.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_ec.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    local_ec.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk(&local_ec.parent);
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  __psq_l0(auStack56,uVar6);
  __psq_l1(auStack56,uVar6);
  __psq_l0(auStack72,uVar6);
  __psq_l1(auStack72,uVar6);
  return;
}


/* __stdcall dKyr_star_init(void) */

void dKyr_star_init(void)

{
  dKankyo_star_Packet *pdVar1;
  dKankyo_star_Packet *pPkt;
  char *pcVar2;
  
  pPkt = (dKankyo_star_Packet *)JKernel::operator_new(0x4c,0x20);
  pdVar1 = pPkt;
  if (pPkt != (dKankyo_star_Packet *)0x0) {
    (pPkt->parent).vtbl = (undefined *)&J3DPacket::__vt;
    (pPkt->parent).mpNextSibling = (J3DPacket *)0x0;
    (pPkt->parent).mpFirstChild = (J3DPacket *)0x0;
    (pPkt->parent).field_0xc = (undefined *)0x0;
    (pPkt->parent).vtbl = &dKankyo_star_Packet::__vt;
    Runtime.PPCEABI.H::__construct_array
              (pPkt->mStarEff,STAR_EFF::STAR_EFF,STAR_EFF::_STAR_EFF,0x34,1);
    d_kankyo::g_env_light.mpStarPacket = pPkt;
    pcVar2 = (char *)dRes_control_c::getRes
                               ("Always",0x81,
                                d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    (d_kankyo::g_env_light.mpStarPacket)->field_0x10 = pcVar2;
    (d_kankyo::g_env_light.mpStarPacket)->mStarEff[0].mSin = 1_0;
    (d_kankyo::g_env_light.mpStarPacket)->mCount = 0;
    pdVar1 = d_kankyo::g_env_light.mpStarPacket;
  }
  d_kankyo::g_env_light.mpStarPacket = pdVar1;
  return;
}


/* __stdcall dKyr_star_move(void) */

void dKyr_star_move(void)

{
  float fVar1;
  float minVel;
  uint uVar2;
  dKankyo_star_Packet *pPkt;
  
  pPkt = d_kankyo::g_env_light.mpStarPacket;
  (d_kankyo::g_env_light.mpStarPacket)->mCount = (short)d_kankyo::g_env_light.mStarCount;
  if (pPkt->mCount != 0) {
    uVar2 = SComponent::cM_rad2s((double)pPkt->mStarEff[0].mAnimCounter);
    minVel = 0_01;
    fVar1 = JKernel::JMath::jmaSinTable
            [(int)(uVar2 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
    pPkt->mStarEff[0].mAnimCounter = pPkt->mStarEff[0].mAnimCounter + 0_01;
    pPkt->mStarEff[0].mSin = ABS(fVar1);
    SComponent::cLib_addCalc(&pPkt->mStarEff[0].mSin,ABS(fVar1),0_5,0_1,minVel);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x8009193c) */
/* WARNING: Removing unreachable block (ram,0x8009192c) */
/* WARNING: Removing unreachable block (ram,0x8009191c) */
/* WARNING: Removing unreachable block (ram,0x80091914) */
/* WARNING: Removing unreachable block (ram,0x80091924) */
/* WARNING: Removing unreachable block (ram,0x80091934) */
/* WARNING: Removing unreachable block (ram,0x80091944) */
/* __stdcall wave_move(void) */

void wave_move(void)

{
  float fVar1;
  float fVar2;
  short sVar4;
  int iVar3;
  dStage_FileList_dt_c *pFili;
  dStage_roomStatus_c *pRoom;
  cXyz *pcVar5;
  int iVar6;
  cXyz *pPos;
  dKankyo_wave__INFLUENCE *pInfl;
  uint uVar7;
  int iVar8;
  int iVar9;
  short sVar10;
  dKankyo_wave_Packet *pPktW;
  undefined4 uVar11;
  double windPow;
  double dist;
  double inner;
  undefined8 in_f25;
  double dVar12;
  undefined8 in_f26;
  double 1_03;
  undefined8 in_f27;
  double 2_0;
  double yOffs;
  undefined8 in_f29;
  undefined8 in_f30;
  double 1_0;
  undefined8 in_f31;
  double 0_0;
  cXyz local_180;
  cXyz local_174;
  cXyz pos;
  cXyz vectleXZ;
  cXyz windPowVec;
  cXyz windNrmVec;
  cXyz local_12c;
  float local_120;
  float local_11c;
  float local_118;
  cXyz eyeVect;
  TVec3_float_ pos0;
  DOUBLE_POS local_f8;
  undefined auStack224 [48];
  longlong local_b0;
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  float fadeDist;
  camera_class *pCamera;
  dKankyo_wave_Packet *pPkt;
  daPy_lk_c *pPlayer;
  byte state;
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)yOffs >> 0x20),0);
  __psq_st1(auStack56,SUB84(yOffs,0),0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  d_kankyo_wether::dKyw_get_wind_vecpow(&local_180);
  pPkt = d_kankyo::g_env_light.mpWavePacket;
  pPlayer = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  pCamera = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  windPowVec.x = local_180.x;
  windPowVec.z = local_180.z;
  pFili = (dStage_FileList_dt_c *)0x0;
  if (-1 < (char)dStage_roomControl_c::mStayNo) {
    pRoom = dStage_roomControl_c::getStatusRoomDt
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                       (int)(char)dStage_roomControl_c::mStayNo);
    pFili = (dStage_FileList_dt_c *)(*(code *)((pRoom->parent).parent.vtbl)->getFileListInfo)();
  }
  if (pFili != (dStage_FileList_dt_c *)0x0) {
    yOffs = (double)pFili->mSkyboxY;
  }
  if ((d_kankyo::g_env_light.mWaveFlatInter < 1_0) &&
     (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0)) {
    mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                      auStack224);
    dKy_set_eyevect_calc2(pCamera,&eyeVect,d_kankyo::g_env_light.mWaveSpawnDist,0_0);
    local_118 = 0_0;
    local_11c = 0_0;
    local_120 = 0_0;
    pcVar5 = d_kankyo_wether::dKyw_get_wind_vec();
    windPow = d_kankyo_wether::dKyw_get_wind_pow();
    windNrmVec.x = pcVar5->x;
    windNrmVec.y = pcVar5->y;
    windNrmVec.z = pcVar5->z;
    iVar6 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                      (0x803c9d58);
    if ((*(uint *)(iVar6 + 0xc) >> 0x10 & 7) == 2) {
      sVar10 = 0;
      iVar6 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"LinkRM");
      if (iVar6 == 0) {
        sVar10 = 0x4000;
      }
      else {
        iVar6 = MSL_C.PPCEABI.bare.H::strcmp
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Orichh");
        if (iVar6 == 0) {
          sVar10 = -0x4000;
        }
        else {
          iVar6 = MSL_C.PPCEABI.bare.H::strcmp
                            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Ojhous2"
                            );
          if (iVar6 == 0) {
            sVar10 = 0x7fff;
          }
          else {
            iVar6 = MSL_C.PPCEABI.bare.H::strcmp
                              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                               "Omasao");
            if (iVar6 == 0) {
              sVar10 = -0x4000;
            }
            else {
              iVar6 = MSL_C.PPCEABI.bare.H::strcmp
                                (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                 "Onobuta");
              if (iVar6 == 0) {
                sVar10 = 0x4000;
              }
            }
          }
        }
      }
      if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mTactWindAngleX == -1)
         && (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mTactWindAngleY == -1
            )) {
        uVar7 = 0;
        sVar4 = 0;
      }
      else {
        uVar7 = SEXT24(d_kankyo::g_env_light.mTactWindAngleX);
        sVar4 = d_kankyo::g_env_light.mTactWindAngleY;
      }
      iVar6 = (int)(uVar7 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
      iVar3 = (int)((int)(short)(sVar4 + sVar10) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
      windNrmVec.x = JKernel::JMath::jmaCosTable[iVar6] * JKernel::JMath::jmaCosTable[iVar3];
      windNrmVec.y = JKernel::JMath::jmaSinTable[iVar6];
      windNrmVec.z = JKernel::JMath::jmaCosTable[iVar6] * JKernel::JMath::jmaSinTable[iVar3];
      windPow = (double)0_6;
      windPowVec.x = (float)(windPow * (double)windNrmVec.x);
      windPowVec.z = (float)(windPow * (double)windNrmVec.z);
    }
    local_118 = 0_0;
    local_11c = 0_0;
    local_120 = 0_0;
    local_f8.x = (double)((pCamera->mCenterPos).x - (pCamera->mEyePos).x);
    local_f8.y = 0_0;
    local_f8.z = (double)((pCamera->mCenterPos).z - (pCamera->mEyePos).z);
    vectle_calc(&local_f8,&vectleXZ);
    0_0 = (double)0_0;
    pPkt->mSkewDir =
         (float)(-(double)windNrmVec.x - 0_0) * (float)((double)vectleXZ.z - 0_0) -
         (float)(-(double)windNrmVec.z - 0_0) * (float)((double)vectleXZ.x - 0_0);
    1_0 = (double)1_0;
    pPkt->mSkewWidth =
         (float)((double)(float)(1_0 - (double)ABS((float)((double)windNrmVec.x * (double)vectleXZ.x
                                                          ) +
                                                   (float)((double)windNrmVec.z * (double)vectleXZ.z
                                                          ))) * windPow) *
         (float)(1_0 - (double)ABS(windNrmVec.y));
    pPkt->mSkewWidth = pPkt->mSkewWidth * 0_6 * ABS(pPkt->mSkewDir);
    iVar6 = 0;
    2_0 = (double)2_0;
    1_03 = (double)1_03;
    windPow = 0_0;
    for (iVar3 = 0; iVar3 < d_kankyo::g_env_light.mWaveCount; iVar3 = iVar3 + 1) {
      if (d_kankyo::g_env_light.mWaveReset != 0) {
        (&pPkt->mpWaveEff[0].mState)[iVar6] = 0;
      }
      pPktW = (dKankyo_wave_Packet *)((int)pPkt->mpWaveEff + iVar6 + -0x18);
      state = pPktW->mpWaveEff[0].mState;
      if (state == 3) {
        pPktW->mpWaveEff[0].mState = 0;
      }
      else {
        if ((char)state < '\x03') {
          if (state == 0) {
            pPktW->mpWaveEff[0].mBasePos.x = eyeVect.x;
            pPktW->mpWaveEff[0].mBasePos.y = (float)yOffs;
            pPktW->mpWaveEff[0].mBasePos.z = eyeVect.z;
            fadeDist = SComponent::cM_rndFX(d_kankyo::g_env_light.mWaveSpawnRadius);
            pPktW->mpWaveEff[0].mPos.x = fadeDist;
            pPktW->mpWaveEff[0].mPos.y = 0_0;
            fadeDist = SComponent::cM_rndFX(d_kankyo::g_env_light.mWaveSpawnRadius);
            pPktW->mpWaveEff[0].mPos.z = fadeDist;
            fadeDist = SComponent::cM_rndF(65536_0);
            pPktW->mpWaveEff[0].mCounter = fadeDist;
            pPktW->mpWaveEff[0].mStrengthWind = 0_0;
            fadeDist = SComponent::cM_rndF(65535_0);
            local_b0 = (longlong)(int)fadeDist;
            pPktW->mpWaveEff[0].field_0x32 = (short)(int)fadeDist;
            fadeDist = 1_0;
            pPktW->mpWaveEff[0].mStrengthEnv = 1_0;
            fadeDist = SComponent::cM_rndF(fadeDist - d_kankyo::g_env_light.mWaveScaleRand);
            pPktW->mpWaveEff[0].mScale = d_kankyo::g_env_light.mWaveScaleRand + fadeDist;
            pPktW->mpWaveEff[0].mSpeed = pPktW->mpWaveEff[0].mScale;
            pPktW->mpWaveEff[0].mCounterSpeed =
                 (0_02 + 0_05 * (1_0 - pPktW->mpWaveEff[0].mScale)) *
                 d_kankyo::g_env_light.mWaveCounterSpeedScale;
            pPktW->mpWaveEff[0].field_0x30 = 0;
            pPktW->mpWaveEff[0].mState = pPktW->mpWaveEff[0].mState + 1;
          }
          else {
            if ((char)state < '\0') goto LAB_80091800;
          }
          fVar2 = 0_8;
          fVar1 = 0_5;
          fadeDist = 0_2;
          pPktW->mpWaveEff[0].mPos.x =
               pPktW->mpWaveEff[0].mPos.x +
               (0_2 + 0_8 * pPktW->mpWaveEff[0].mStrengthWind) *
               (0_5 + 0_5 * pPktW->mpWaveEff[0].mStrengthEnv) *
               pPktW->mpWaveEff[0].mSpeed * windPowVec.x * d_kankyo::g_env_light.mWaveSpeed;
          pPktW->mpWaveEff[0].mPos.z =
               pPktW->mpWaveEff[0].mPos.z +
               (fadeDist + fVar2 * pPktW->mpWaveEff[0].mStrengthWind) *
               (fVar1 + fVar1 * pPktW->mpWaveEff[0].mStrengthEnv) *
               pPktW->mpWaveEff[0].mSpeed * windPowVec.z * d_kankyo::g_env_light.mWaveSpeed;
          pPktW->mpWaveEff[0].mCounter =
               pPktW->mpWaveEff[0].mCounter + pPktW->mpWaveEff[0].mCounterSpeed;
          pos.x = pPktW->mpWaveEff[0].mBasePos.x + pPktW->mpWaveEff[0].mPos.x;
          pos.y = pPktW->mpWaveEff[0].mBasePos.y + pPktW->mpWaveEff[0].mPos.y;
          pos.z = pPktW->mpWaveEff[0].mBasePos.z + pPktW->mpWaveEff[0].mPos.z;
          fadeDist = mtx::PSVECSquareDistance(&pos,&eyeVect);
          dist = (double)fadeDist;
          if ((double)0_0 < dist) {
            inner = 1.0 / SQRT(dist);
            inner = 0_5 * inner * (3_0 - dist * inner * inner);
            inner = 0_5 * inner * (3_0 - dist * inner * inner);
            dist = (double)(float)(dist * 0_5 * inner * (3_0 - dist * inner * inner));
          }
          if ((double)d_kankyo::g_env_light.mWaveSpawnRadius < dist) {
            pPktW->mpWaveEff[0].mBasePos.x = eyeVect.x;
            pPktW->mpWaveEff[0].mBasePos.z = eyeVect.z;
            fadeDist = mtx::PSVECSquareDistance(&pos,&eyeVect);
            dist = (double)fadeDist;
            if ((double)0_0 < dist) {
              inner = 1.0 / SQRT(dist);
              inner = 0_5 * inner * (3_0 - dist * inner * inner);
              inner = 0_5 * inner * (3_0 - dist * inner * inner);
              dist = (double)(float)(dist * 0_5 * inner * (3_0 - dist * inner * inner));
            }
            if (dist <= (double)(350_0 + d_kankyo::g_env_light.mWaveSpawnRadius)) {
              get_vectle_calc(&pos,&eyeVect,&local_174);
              pPktW->mpWaveEff[0].mPos.x = local_174.x * d_kankyo::g_env_light.mWaveSpawnRadius;
              pPktW->mpWaveEff[0].mPos.z = local_174.z * d_kankyo::g_env_light.mWaveSpawnRadius;
            }
            else {
              fadeDist = SComponent::cM_rndFX(d_kankyo::g_env_light.mWaveSpawnRadius);
              pPktW->mpWaveEff[0].mPos.x = fadeDist;
              fadeDist = SComponent::cM_rndFX(d_kankyo::g_env_light.mWaveSpawnRadius);
              pPktW->mpWaveEff[0].mPos.z = fadeDist;
            }
            pPktW->mpWaveEff[0].mStrengthWind = 0_0;
          }
          pos.x = pPktW->mpWaveEff[0].mBasePos.x + pPktW->mpWaveEff[0].mPos.x;
          pos.y = pPktW->mpWaveEff[0].mBasePos.y + pPktW->mpWaveEff[0].mPos.y;
          pos.z = pPktW->mpWaveEff[0].mBasePos.z + pPktW->mpWaveEff[0].mPos.z;
          pPktW->mpWaveEff[0].mStrengthEnv = 1_0;
          iVar8 = 0;
          iVar9 = 0;
          do {
            pPos = *(cXyz **)((int)&d_kankyo::g_env_light.mpWaveInfl + iVar9);
            if (pPos != (cXyz *)0x0) {
              pPos->y = pos.y;
              fadeDist = mtx::PSVECSquareDistance
                                   (&pos,*(cXyz **)((int)&d_kankyo::g_env_light.mpWaveInfl + iVar9))
              ;
              dist = (double)fadeDist;
              if ((double)0_0 < dist) {
                inner = 1.0 / SQRT(dist);
                inner = 0_5 * inner * (3_0 - dist * inner * inner);
                inner = 0_5 * inner * (3_0 - dist * inner * inner);
                dist = (double)(float)(dist * 0_5 * inner * (3_0 - dist * inner * inner));
              }
              pInfl = *(dKankyo_wave__INFLUENCE **)((int)&d_kankyo::g_env_light.mpWaveInfl + iVar9);
              inner = (double)pInfl->mInnerRadius;
              if (dist < (double)pInfl->mOuterRadius) {
                if (dist < inner) {
                  pPktW->mpWaveEff[0].mStrengthEnv = 0_0;
                  break;
                }
                fadeDist = (float)((double)pInfl->mOuterRadius - inner);
                if (fadeDist <= 0_0) {
                  pPktW->mpWaveEff[0].mStrengthEnv = 0_0;
                }
                else {
                  fadeDist = (float)(dist - inner) / fadeDist;
                  if (fadeDist < pPktW->mpWaveEff[0].mStrengthEnv) {
                    pPktW->mpWaveEff[0].mStrengthEnv = fadeDist;
                  }
                }
              }
            }
            iVar8 = iVar8 + 1;
            iVar9 = iVar9 + 4;
          } while (iVar8 < 10);
          if (0_0 < d_kankyo::g_env_light.mWaveFlatInter) {
            local_12c.x = (pCamera->mEyePos).x;
            local_12c.z = (pCamera->mEyePos).z;
            local_12c.y = pos.y;
            fadeDist = mtx::PSVECSquareDistance(&pos,&local_12c);
            dist = (double)fadeDist;
            if ((double)0_0 < dist) {
              inner = 1.0 / SQRT(dist);
              inner = 0_5 * inner * (3_0 - dist * inner * inner);
              inner = 0_5 * inner * (3_0 - dist * inner * inner);
              dist = (double)(float)(dist * 0_5 * inner * (3_0 - dist * inner * inner));
            }
            inner = (double)(d_kankyo::g_env_light.mWaveFlatInter *
                            1_5 * d_kankyo::g_env_light.mWaveSpawnRadius);
            fadeDist = (float)((double)(float)((double)1000_0 + inner) - inner);
            if (fadeDist <= 0_0) {
              pPktW->mpWaveEff[0].mStrengthEnv = 0_0;
            }
            else {
              fadeDist = (float)(dist - inner) / fadeDist;
              if (fadeDist < pPktW->mpWaveEff[0].mStrengthEnv) {
                pPktW->mpWaveEff[0].mStrengthEnv = fadeDist;
              }
            }
          }
          local_12c.x = (pPlayer->parent).parent.mCurrent.mPos.x;
          local_12c.z = (pPlayer->parent).parent.mCurrent.mPos.z;
          local_12c.y = pos.y;
          fadeDist = mtx::PSVECSquareDistance(&pos,&local_12c);
          dist = (double)fadeDist;
          if ((double)0_0 < dist) {
            inner = 1.0 / SQRT(dist);
            inner = 0_5 * inner * (3_0 - dist * inner * inner);
            inner = 0_5 * inner * (3_0 - dist * inner * inner);
            dist = (double)(float)(dist * 0_5 * inner * (3_0 - dist * inner * inner));
          }
          if (dist < (double)2000_0) {
            if ((double)200_0 <= dist) {
              pPktW->mpWaveEff[0].mStrengthEnv =
                   pPktW->mpWaveEff[0].mStrengthEnv * ((float)(dist - (double)200_0) / 1800_0);
            }
            else {
              pPktW->mpWaveEff[0].mStrengthEnv = 0_0;
            }
          }
        }
      }
LAB_80091800:
      pos0.x = pPktW->mpWaveEff[0].mBasePos.x + pPktW->mpWaveEff[0].mPos.x;
      pos0.y = pPktW->mpWaveEff[0].mBasePos.y + pPktW->mpWaveEff[0].mPos.y;
      pos0.z = pPktW->mpWaveEff[0].mBasePos.z + pPktW->mpWaveEff[0].mPos.z;
      fadeDist = mtx::PSVECSquareDistance((cXyz *)&pos0,&pCamera->mEyePos);
      dist = (double)fadeDist;
      if (windPow < dist) {
        inner = 1.0 / SQRT(dist);
        inner = 0_5 * inner * (3_0 - dist * inner * inner);
        inner = 0_5 * inner * (3_0 - dist * inner * inner);
        dist = (double)(float)(dist * 0_5 * inner * (3_0 - dist * inner * inner));
      }
      if (dist < windPow) {
        dist = windPow;
      }
      dVar12 = (double)(float)((double)(float)(1_0 - (double)(float)(dist / (double)(float)(2_0 * (
                                                  double)d_kankyo::g_env_light.mWaveSpawnDist))) *
                              1_03);
      inner = MSL_C.PPCEABI.bare.H::sin((double)pPktW->mpWaveEff[0].mCounter);
      dist = (double)(float)(dVar12 * (double)(float)inner);
      if (1_0 < (double)(float)(dVar12 * (double)(float)inner)) {
        dist = 1_0;
      }
      if (dist < 0_0) {
        dist = 0_0;
      }
      SComponent::cLib_addCalc(&pPktW->mpWaveEff[0].mStrengthWind,(float)dist,0_5,0_5,0_001);
      pPktW->mpWaveEff[0].mBasePos.y = (float)yOffs;
      iVar6 = iVar6 + 0x38;
    }
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  __psq_l0(auStack40,uVar11);
  __psq_l1(auStack40,uVar11);
  __psq_l0(auStack56,uVar11);
  __psq_l1(auStack56,uVar11);
  __psq_l0(auStack72,uVar11);
  __psq_l1(auStack72,uVar11);
  __psq_l0(auStack88,uVar11);
  __psq_l1(auStack88,uVar11);
  __psq_l0(auStack104,uVar11);
  __psq_l1(auStack104,uVar11);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x8009226c) */
/* WARNING: Removing unreachable block (ram,0x8009225c) */
/* WARNING: Removing unreachable block (ram,0x8009224c) */
/* WARNING: Removing unreachable block (ram,0x80092244) */
/* WARNING: Removing unreachable block (ram,0x80092254) */
/* WARNING: Removing unreachable block (ram,0x80092264) */
/* WARNING: Removing unreachable block (ram,0x80092274) */
/* __stdcall cloud_shadow_move(void) */

void cloud_shadow_move(void)

{
  byte bVar1;
  float fVar2;
  camera_class *pcVar3;
  int iVar4;
  int iVar5;
  int i;
  dKankyo_cloud_Packet *pEff;
  undefined4 uVar6;
  double dist;
  double alpha;
  undefined8 in_f25;
  double 1_2;
  undefined8 in_f26;
  double 1_0;
  undefined8 in_f27;
  double 0_0;
  undefined8 in_f28;
  double 1000_0;
  undefined8 in_f29;
  double 2000_0;
  undefined8 in_f30;
  double 1_5;
  undefined8 in_f31;
  double 40_0;
  float fVar7;
  cXyz pntwind_;
  cXyz windVecPow_;
  cXyz vel;
  cXyz pntwind;
  TVec3_float_ pos;
  TVec3_float_ eyeVect;
  cXyz windVecPow;
  undefined auStack212 [52];
  longlong local_a0;
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  dKankyo_cloud_Packet *pPkt;
  float speed;
  
  pPkt = d_kankyo::g_env_light.mpMoyaPacket;
  pcVar3 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar6 = 0;
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
  d_kankyo_wether::dKyw_get_wind_vecpow(&windVecPow_);
  if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
    mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                      auStack212);
    if (pPkt->mCount <= d_kankyo::g_env_light.mMoyaCount) {
      pPkt->mCount = (int)(short)d_kankyo::g_env_light.mMoyaCount;
    }
    if (pPkt->mCount != 0) {
      dKy_set_eyevect_calc2(pcVar3,(cXyz *)&eyeVect,1500_0,1500_0);
      iVar5 = 0;
      0_0 = (double)0_0;
      1000_0 = (double)1000_0;
      2000_0 = (double)2000_0;
      1_5 = (double)1_5;
      40_0 = (double)40_0;
      1_0 = (double)1_0;
      1_2 = (double)1_2;
      for (i = 0; i < pPkt->mCount; i = i + 1) {
        pEff = (dKankyo_cloud_Packet *)((int)pPkt->mEff + iVar5 + -0x18);
        bVar1 = pEff->mEff[0].mStatus;
        if (bVar1 == 3) {
          pEff->mEff[0].mStatus = 0;
        }
        else {
          if ((char)bVar1 < '\x03') {
            if (bVar1 == 0) {
              speed = SComponent::cM_rndFX(80_0);
              pEff->mEff[0].mInitialSize = 400_0 + speed;
              pEff->mEff[0].mSize = pEff->mEff[0].mInitialSize;
              pEff->mEff[0].mBasePos.x = eyeVect.x;
              pEff->mEff[0].mBasePos.y = eyeVect.y;
              pEff->mEff[0].mBasePos.z = eyeVect.z;
              speed = SComponent::cM_rndFX(2000_0);
              pEff->mEff[0].mPos.x = speed;
              speed = SComponent::cM_rndFX(2000_0);
              pEff->mEff[0].mPos.y = speed;
              speed = SComponent::cM_rndFX(2000_0);
              pEff->mEff[0].mPos.z = speed;
              speed = SComponent::cM_rndF(0_3);
              pEff->mEff[0].mWindSpeed = 0_7 + speed;
              pEff->mEff[0].mAlpha = 0_0;
              speed = SComponent::cM_rndF(65535_0);
              local_a0 = (longlong)(int)speed;
              pEff->mEff[0].mAnimCounter = (short)(int)speed;
              speed = SComponent::cM_rndF(360_0);
              pEff->mEff[0].mVelRndm.x = speed;
              speed = SComponent::cM_rndF(360_0);
              pEff->mEff[0].mVelRndm.y = speed;
              speed = SComponent::cM_rndF(360_0);
              pEff->mEff[0].mVelRndm.z = speed;
              speed = 0_0;
              pEff->mEff[0].mPntWindVel.x = 0_0;
              pEff->mEff[0].mPntWindVel.y = speed;
              pEff->mEff[0].mPntWindVel.z = speed;
              pEff->mEff[0].mStatus = pEff->mEff[0].mStatus + 1;
            }
            else {
              if (-1 < (char)bVar1) {
                pos.x = pEff->mEff[0].mBasePos.x + pEff->mEff[0].mPos.x;
                pos.y = pEff->mEff[0].mBasePos.y + pEff->mEff[0].mPos.y;
                pos.z = pEff->mEff[0].mBasePos.z + pEff->mEff[0].mPos.z;
                pEff->mEff[0].mAnimCounter = pEff->mEff[0].mAnimCounter + 0x78;
                SComponent::cLib_chaseF(&pEff->mEff[0].field_0x34,pEff->mEff[0].mWindSpeed,7_0);
                if ((d_kankyo::g_env_light.mMoyaMode & 1) != 0) {
                  iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                     "M_DragB");
                  if ((iVar4 == 0) && (d_kankyo::g_env_light.mbVrboxInvisible == 0)) {
                    pEff->mEff[0].mPos.y = pEff->mEff[0].mPos.y + 5_0;
                  }
                  else {
                    if (d_kankyo::g_env_light.mMoyaMode == 1) {
                      pEff->mEff[0].mPos.y = pEff->mEff[0].mPos.y + 20_0;
                    }
                  }
                }
                speed = 40_0;
                if (d_kankyo::g_env_light.mMoyaMode == 1) {
                  speed = 10_0;
                }
                pEff->mEff[0].mPos.x =
                     pEff->mEff[0].mPos.x + pEff->mEff[0].mWindSpeed * windVecPow_.x * speed;
                pEff->mEff[0].mPos.y =
                     pEff->mEff[0].mPos.y + pEff->mEff[0].mWindSpeed * windVecPow_.y * speed;
                pEff->mEff[0].mPos.z =
                     pEff->mEff[0].mPos.z + pEff->mEff[0].mWindSpeed * windVecPow_.z * speed;
                d_kankyo_wether::dKyw_pntwind_get_vecpow(&pntwind_,(cXyz *)&pos);
                pntwind.x = pntwind_.x;
                pntwind.y = pntwind_.y;
                pntwind.z = pntwind_.z;
                speed = pEff->mEff[0].mPntWindVel.x;
                if (speed < 30_0) {
                  pEff->mEff[0].mPntWindVel.x = speed + 9_0 * pntwind_.x;
                }
                speed = pEff->mEff[0].mPntWindVel.y;
                if (speed < 30_0) {
                  pEff->mEff[0].mPntWindVel.y = speed + 9_0 * pntwind_.y;
                }
                speed = pEff->mEff[0].mPntWindVel.z;
                if (speed < 30_0) {
                  pEff->mEff[0].mPntWindVel.z = speed + 9_0 * pntwind_.z;
                }
                SComponent::cLib_addCalc
                          (&pEff->mEff[0].mPntWindVel.x,0_0,0_2,0_1,1_0E_5);
                SComponent::cLib_addCalc
                          (&pEff->mEff[0].mPntWindVel.y,0_0,0_2,0_1,1_0E_5);
                SComponent::cLib_addCalc
                          (&pEff->mEff[0].mPntWindVel.z,0_0,0_2,0_1,1_0E_5);
                pEff->mEff[0].mPos.x = pEff->mEff[0].mPos.x + pEff->mEff[0].mPntWindVel.x;
                pEff->mEff[0].mPos.y = pEff->mEff[0].mPos.y + pEff->mEff[0].mPntWindVel.y;
                pEff->mEff[0].mPos.z = pEff->mEff[0].mPos.z + pEff->mEff[0].mPntWindVel.z;
                MSL_C.PPCEABI.bare.H::strcmp
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"kaze");
                iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                                  (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                   "Adanmae");
                speed = 8_0;
                if (iVar4 == 0) {
                  speed = 20_0;
                }
                fVar7 = pEff->mEff[0].mVelRndm.y / 360_0 - 0_5;
                fVar2 = pEff->mEff[0].mVelRndm.z / 360_0 - 0_5;
                pEff->mEff[0].mPos.x =
                     pEff->mEff[0].mPos.x + (pEff->mEff[0].mVelRndm.x / 360_0 - 0_5) * speed;
                pEff->mEff[0].mPos.y = pEff->mEff[0].mPos.y + fVar7 * speed;
                pEff->mEff[0].mPos.z = pEff->mEff[0].mPos.z + fVar2 * speed;
                pos.x = pEff->mEff[0].mBasePos.x + pEff->mEff[0].mPos.x;
                pos.y = pEff->mEff[0].mBasePos.y + pEff->mEff[0].mPos.y;
                pos.z = pEff->mEff[0].mBasePos.z + pEff->mEff[0].mPos.z;
                speed = mtx::PSVECSquareDistance((cXyz *)&pos,(cXyz *)&eyeVect);
                dist = (double)speed;
                if ((double)0_0 < dist) {
                  alpha = 1.0 / SQRT(dist);
                  alpha = 0_5 * alpha * (3_0 - dist * alpha * alpha);
                  alpha = 0_5 * alpha * (3_0 - dist * alpha * alpha);
                  dist = (double)(float)(dist * 0_5 * alpha * (3_0 - dist * alpha * alpha));
                }
                if ((double)2000_0 < dist) {
                  pEff->mEff[0].mBasePos.x = eyeVect.x;
                  pEff->mEff[0].mBasePos.y = eyeVect.y;
                  pEff->mEff[0].mBasePos.z = eyeVect.z;
                  speed = mtx::PSVECSquareDistance((cXyz *)&pos,(cXyz *)&eyeVect);
                  dist = (double)speed;
                  if ((double)0_0 < dist) {
                    alpha = 1.0 / SQRT(dist);
                    alpha = 0_5 * alpha * (3_0 - dist * alpha * alpha);
                    alpha = 0_5 * alpha * (3_0 - dist * alpha * alpha);
                    dist = (double)(float)(dist * 0_5 * alpha * (3_0 - dist * alpha * alpha));
                  }
                  if (dist <= (double)2200_0) {
                    SComponent::cLib_addCalc
                              (&pEff->mEff[0].mAlpha,0_0,0_1,0_01,0_001);
                    if (pEff->mEff[0].mAlpha < 0_001) {
                      get_vectle_calc((cXyz *)&pos,(cXyz *)&eyeVect,&pntwind);
                      speed = SComponent::cM_rndF(0_5);
                      pntwind.x = pntwind.x + speed;
                      speed = SComponent::cM_rndF(0_5);
                      pntwind.y = pntwind.y + speed;
                      fVar7 = SComponent::cM_rndF(0_5);
                      speed = 2000_0;
                      pntwind.z = pntwind.z + fVar7;
                      pEff->mEff[0].mPos.x = pntwind.x * 2000_0;
                      pEff->mEff[0].mPos.y = pntwind.y * speed;
                      pEff->mEff[0].mPos.z = pntwind.z * speed;
                    }
                  }
                  else {
                    speed = SComponent::cM_rndFX(2000_0);
                    pEff->mEff[0].mPos.x = speed;
                    speed = SComponent::cM_rndFX(2000_0);
                    pEff->mEff[0].mPos.y = speed;
                    speed = SComponent::cM_rndFX(2000_0);
                    pEff->mEff[0].mPos.z = speed;
                  }
                  pEff->mEff[0].mAlpha = 0_0;
                }
              }
            }
          }
        }
        pos.x = pEff->mEff[0].mBasePos.x + pEff->mEff[0].mPos.x;
        pos.y = pEff->mEff[0].mBasePos.y + pEff->mEff[0].mPos.y;
        pos.z = pEff->mEff[0].mBasePos.z + pEff->mEff[0].mPos.z;
        speed = mtx::PSVECSquareDistance((cXyz *)&pos,&pcVar3->mEyePos);
        dist = (double)speed;
        if (0_0 < dist) {
          alpha = 1.0 / SQRT(dist);
          alpha = 0_5 * alpha * (3_0 - dist * alpha * alpha);
          alpha = 0_5 * alpha * (3_0 - dist * alpha * alpha);
          dist = (double)(float)(dist * 0_5 * alpha * (3_0 - dist * alpha * alpha));
        }
        speed = pEff->mEff[0].mInitialSize;
        pEff->mEff[0].mSize =
             (float)(40_0 * (double)JKernel::JMath::jmaSinTable
                                    [(int)(uint)(ushort)pEff->mEff[0].mAnimCounter >>
                                     (JKernel::JMath::jmaSinShift & 0x3f)]) +
             speed + speed * (float)(1_5 * (double)(float)((double)(float)(dist - 1000_0) / 2000_0))
        ;
        fVar7 = mtx::PSVECSquareDistance((cXyz *)&pos,(cXyz *)&eyeVect);
        speed = 0_0;
        dist = (double)fVar7;
        if (0_0 < dist) {
          alpha = 1.0 / SQRT(dist);
          alpha = 0_5 * alpha * (3_0 - dist * alpha * alpha);
          alpha = 0_5 * alpha * (3_0 - dist * alpha * alpha);
          dist = (double)(float)(dist * 0_5 * alpha * (3_0 - dist * alpha * alpha));
        }
        if (dist < 0_0) {
          dist = 0_0;
        }
        alpha = (double)0_035;
        if (d_kankyo::g_env_light.mMoyaMode == 3) {
          alpha = (double)0_06;
        }
        else {
          if (d_kankyo::g_env_light.mMoyaMode == 4) {
            alpha = (double)0_05;
          }
        }
        fVar7 = (float)(1_0 - (double)(float)(dist / 2000_0));
        if (((d_kankyo::g_env_light.mMoyaCount + -1 < i) &&
            (fVar7 = speed, pEff->mEff[0].mAlpha < 0_001)) &&
           (iVar4 = pPkt->mCount + -1, i == iVar4)) {
          pPkt->mCount = iVar4;
        }
        SComponent::cLib_addCalc(&pEff->mEff[0].mAlpha,fVar7 * (float)(alpha * 1_2),0_1,0_1,1_0E_9);
        iVar5 = iVar5 + 0x4c;
      }
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  __psq_l0(auStack56,uVar6);
  __psq_l1(auStack56,uVar6);
  __psq_l0(auStack72,uVar6);
  __psq_l1(auStack72,uVar6);
  __psq_l0(auStack88,uVar6);
  __psq_l1(auStack88,uVar6);
  __psq_l0(auStack104,uVar6);
  __psq_l1(auStack104,uVar6);
  return;
}


/* __stdcall light_at_hit_check(cXyz *) */

undefined4 light_at_hit_check(cXyz *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  fopAc_ac_c *pfStack40;
  dCcMassS_HitInf dStack36;
  
  dStack36.vtbl = (undefined *)&dCcMassS_HitInf::__vt;
  uVar2 = 0;
  uVar1 = dCcMassS_Mng::Chk(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,param_1,
                            &pfStack40,&dStack36);
  if (((uVar1 & 1) != 0) && ((((dStack36.mpAtObj)->parent).mObjAt.mDamageTypes & 0x800000) != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}


/* __stdcall dKyr_poison_live_check(void) */

undefined4 dKyr_poison_live_check(void)

{
  if (d_kankyo::g_env_light._2536_4_ == 0) {
    return 0;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80092428) */
/* __stdcall dKyr_poison_light_colision(void) */

void dKyr_poison_light_colision(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_f31;
  double dVar7;
  cXyz local_48;
  float local_3c;
  float local_38;
  float local_34;
  undefined auStack8 [8];
  
  iVar1 = d_kankyo::g_env_light._2540_4_;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar2 = dKyr_poison_live_check();
  if (iVar2 != 0) {
    ::cM3dGCyl::SetR(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mCylAttr.mCyl,_7565);
    ::cM3dGCyl::SetH(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mCylAttr.mCyl,_7566);
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mChkFlag = 0xb;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mResultCamBit = 3;
    iVar5 = 0;
    dVar7 = (double)70_0;
    for (iVar2 = 0; iVar2 < d_kankyo::g_env_light._2536_4_; iVar2 = iVar2 + 1) {
      iVar4 = iVar1 + iVar5;
      ::cXyz::operator__(&local_48,(cXyz *)(iVar1 + 0xbb90),(cXyz *)(iVar4 + 0x14));
      local_3c = local_48.x;
      local_34 = local_48.z;
      local_38 = (float)((double)local_48.y - dVar7);
      iVar3 = light_at_hit_check(&local_3c);
      if ((iVar3 != 0) && (*(char *)(iVar4 + 0x10) == '\x01')) {
        *(undefined *)(iVar4 + 0x10) = 2;
        *(undefined2 *)(iVar4 + 0x3e) = 0x3c;
      }
      iVar5 = iVar5 + 0x30;
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* __stdcall poison_init(void) */

void poison_init(void)

{
  float fVar1;
  undefined **ppuVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  
  ppuVar2 = (undefined **)JKernel::operator_new(0xbbb0,0x20);
  if (ppuVar2 != (undefined **)0x0) {
    *ppuVar2 = (undefined *)&J3DPacket::__vt;
    ppuVar2[1] = (undefined *)0x0;
    ppuVar2[2] = (undefined *)0x0;
    ppuVar2[3] = (undefined *)0x0;
    *ppuVar2 = &dKankyo_poison_Packet::__vt;
    Runtime.PPCEABI.H::__construct_array
              (ppuVar2 + 4,POISON_EFF::POISON_EFF,POISON_EFF::_POISON_EFF,0x30,1000);
  }
  fVar1 = 0_0;
  d_kankyo::g_env_light._2540_4_ = ppuVar2;
  ppuVar2[0x2ee7] = (undefined *)0_0;
  d_kankyo::g_env_light._2540_4_[0x2ee8] = (undefined *)fVar1;
  d_kankyo::g_env_light._2540_4_[0x2ee9] = (undefined *)fVar1;
  d_kankyo::g_env_light._2540_4_[0x2eea] = (undefined *)0x0;
  if (d_kankyo::g_env_light._2540_4_ != (undefined **)0x0) {
    puVar3 = (undefined *)
             dRes_control_c::getRes
                       ("Always",0x6e,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    d_kankyo::g_env_light._2540_4_[0x2eeb] = puVar3;
    iVar4 = 0;
    iVar5 = 1000;
    do {
      *(undefined *)((int)d_kankyo::g_env_light._2540_4_ + iVar4 + 0x10) = 0;
      iVar4 = iVar4 + 0x30;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    poison_move();
    now_room = (int)(char)dStage_roomControl_c::mStayNo;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f10 */
/* WARNING: Inlined function: FUN_80328f5c */
/* WARNING: Removing unreachable block (ram,0x80093794) */
/* WARNING: Removing unreachable block (ram,0x80093784) */
/* WARNING: Removing unreachable block (ram,0x80093774) */
/* WARNING: Removing unreachable block (ram,0x80093764) */
/* WARNING: Removing unreachable block (ram,0x80093754) */
/* WARNING: Removing unreachable block (ram,0x80093744) */
/* WARNING: Removing unreachable block (ram,0x80093734) */
/* WARNING: Removing unreachable block (ram,0x80093724) */
/* WARNING: Removing unreachable block (ram,0x80093714) */
/* WARNING: Removing unreachable block (ram,0x8009371c) */
/* WARNING: Removing unreachable block (ram,0x8009372c) */
/* WARNING: Removing unreachable block (ram,0x8009373c) */
/* WARNING: Removing unreachable block (ram,0x8009374c) */
/* WARNING: Removing unreachable block (ram,0x8009375c) */
/* WARNING: Removing unreachable block (ram,0x8009376c) */
/* WARNING: Removing unreachable block (ram,0x8009377c) */
/* WARNING: Removing unreachable block (ram,0x8009378c) */
/* WARNING: Removing unreachable block (ram,0x8009379c) */
/* __stdcall poison_move(void) */

void poison_move(void)

{
  float *pfVar1;
  bool bVar2;
  camera_class *pcVar3;
  daPy_lk_c *pdVar4;
  int iVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  char cVar9;
  float *pfVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  undefined8 in_f14;
  undefined8 in_f15;
  double dVar20;
  undefined8 in_f16;
  double dVar21;
  undefined8 in_f17;
  double dVar22;
  undefined8 in_f18;
  double dVar23;
  undefined8 in_f19;
  double dVar24;
  undefined8 in_f20;
  double dVar25;
  undefined8 in_f21;
  double dVar26;
  undefined8 in_f22;
  double dVar27;
  undefined8 in_f23;
  double dVar28;
  undefined8 in_f24;
  double dVar29;
  undefined8 in_f25;
  double dVar30;
  undefined8 in_f26;
  double dVar31;
  undefined8 in_f27;
  double dVar32;
  undefined8 in_f28;
  double dVar33;
  undefined8 in_f29;
  double dVar34;
  undefined8 in_f30;
  double dVar35;
  undefined8 in_f31;
  double dVar36;
  float fVar37;
  cXyz local_344;
  cXyz local_338;
  cXyz local_32c;
  cXyz local_320;
  cXyz local_314;
  cXyz local_308;
  float local_2fc;
  float local_2f8;
  float local_2f4;
  float local_2f0;
  float local_2ec;
  float local_2e8;
  cXyz local_2e4;
  float local_2d8;
  float local_2d4;
  float local_2d0;
  cXyz local_2cc;
  float local_2c0;
  float local_2bc;
  float local_2b8;
  float local_2b4;
  float local_2b0;
  float local_2ac;
  float local_2a8;
  float local_2a4;
  float local_2a0;
  float local_29c;
  float local_298;
  float local_294;
  float local_290;
  float local_28c;
  float local_288;
  float local_284 [8];
  int iStack612;
  float afStack608 [4];
  float local_250;
  float local_24c;
  float local_248;
  float local_244;
  float local_240;
  float local_23c;
  float local_238;
  short local_230;
  short local_22e;
  float local_22c;
  longlong local_190;
  longlong local_188;
  double local_180;
  double local_178;
  double local_170;
  double local_168;
  undefined auStack280 [16];
  undefined auStack264 [16];
  undefined auStack248 [16];
  undefined auStack232 [16];
  undefined auStack216 [16];
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  iVar5 = d_kankyo::g_env_light._2540_4_;
  pdVar4 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  pcVar3 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar16 = 0;
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
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  __psq_st0(auStack216,(int)((ulonglong)in_f18 >> 0x20),0);
  __psq_st1(auStack216,(int)in_f18,0);
  __psq_st0(auStack232,(int)((ulonglong)in_f17 >> 0x20),0);
  __psq_st1(auStack232,(int)in_f17,0);
  __psq_st0(auStack248,(int)((ulonglong)in_f16 >> 0x20),0);
  __psq_st1(auStack248,(int)in_f16,0);
  __psq_st0(auStack264,(int)((ulonglong)in_f15 >> 0x20),0);
  __psq_st1(auStack264,(int)in_f15,0);
  __psq_st0(auStack280,(int)((ulonglong)in_f14 >> 0x20),0);
  __psq_st1(auStack280,(int)in_f14,0);
  d_kankyo_wether::dKyw_get_wind_vecpow(&local_32c);
  local_2a8 = local_32c.x;
  local_2a4 = local_32c.y;
  local_2a0 = local_32c.z;
  pfVar11 = &local_288;
  pfVar10 = &sun_chkpnt_5053[4].y;
  iVar14 = 0x1e;
  do {
    pfVar1 = pfVar10 + 1;
    pfVar10 = pfVar10 + 2;
    fVar6 = *pfVar10;
    pfVar11[1] = *pfVar1;
    pfVar11 = pfVar11 + 2;
    *pfVar11 = fVar6;
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  if (now_room != (char)dStage_roomControl_c::mStayNo) {
    iVar14 = 0;
    iVar15 = 1000;
    now_room = (int)(char)dStage_roomControl_c::mStayNo;
    do {
      *(undefined *)(iVar5 + iVar14 + 0x10) = 0;
      iVar14 = iVar14 + 0x30;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
  }
  if ((char)dStage_roomControl_c::mStayNo < 0x10) {
    iVar14 = *(int *)(&room_pat_tbl_7606 + (char)dStage_roomControl_c::mStayNo * 4);
  }
  else {
    iVar14 = -1;
  }
  if (iVar14 < 0) {
    dVar22 = (double)local_23c;
    local_290 = afStack608[3];
    local_28c = local_250;
    local_288 = local_24c;
    dVar20 = (double)local_248 - dVar22;
    local_2bc = local_244;
    dVar36 = (double)local_240 - dVar22;
    d_kankyo::g_env_light._2536_4_ = 0;
  }
  else {
    dVar22 = (double)local_284[iVar14 * 0xc + 6];
    local_290 = local_284[iVar14 * 0xc];
    local_28c = local_284[iVar14 * 0xc + 1];
    local_288 = local_284[iVar14 * 0xc + 2];
    dVar20 = (double)local_284[iVar14 * 0xc + 3] - dVar22;
    local_2bc = local_284[iVar14 * 0xc + 4];
    dVar36 = (double)local_284[iVar14 * 0xc + 5] - dVar22;
    local_238 = local_284[iVar14 * 0xc + 7];
    d_kankyo::g_env_light._2536_4_ = (&iStack612)[iVar14 * 0xc];
    local_230 = *(short *)(afStack608 + iVar14 * 0xc);
    local_22e = *(short *)((int)afStack608 + (iVar14 * 0x18 + 1) * 2);
    local_22c = afStack608[iVar14 * 0xc + 1];
  }
  local_2b8 = (float)dVar36;
  local_2c0 = (float)dVar20;
  dVar21 = (double)local_238;
  dVar20 = (double)local_22c;
  *(float *)(iVar5 + 0xbb90) = local_290;
  *(float *)(iVar5 + 0xbb94) = local_28c;
  *(float *)(iVar5 + 0xbb98) = local_288;
  *(float *)(iVar5 + 0xbb94) = (float)((double)*(float *)(iVar5 + 0xbb94) + dVar22);
  dVar36 = (double)1_0E9;
  iVar15 = 0;
  dVar31 = (double)(float)((double)2300_0 + dVar22);
  dVar30 = (double)(float)((double)_4440 - dVar22);
  dVar29 = (double)(float)((double)_8058 + dVar22);
  dVar28 = (double)(float)((double)_8059 + dVar22);
  dVar27 = (double)(float)((double)_8060 - dVar22);
  dVar26 = (double)(float)((double)_8061 + dVar22);
  dVar25 = (double)(float)((double)_8062 - dVar22);
  dVar32 = (double)0_2;
  dVar24 = (double)(float)(dVar32 * dVar22);
  dVar33 = (double)local_2c0;
  local_180 = (double)local_2bc;
  local_178 = (double)local_2b8;
  dVar34 = (double)0_0;
  dVar35 = (double)1_0;
  local_170 = (double)0_05;
  local_168 = (double)0_5;
  for (iVar12 = 0; iVar12 < d_kankyo::g_env_light._2536_4_; iVar12 = iVar12 + 1) {
    local_2b4 = (float)dVar33;
    local_2b0 = (float)local_180;
    local_2ac = (float)local_178;
    iVar13 = iVar5 + iVar15;
    cVar9 = *(char *)(iVar13 + 0x10);
    if (cVar9 == '\0') {
      *(float *)(iVar13 + 0x38) = 0_0;
      if (iVar14 == 2) {
        fVar6 = SComponent::cM_rndFX(_8063);
        local_190 = (longlong)(int)fVar6;
        fVar37 = SComponent::cM_rndFX(_8063);
        local_188 = (longlong)(int)fVar37;
        *(float *)(iVar13 + 0x14) =
             (float)dVar33 *
             JKernel::JMath::jmaSinTable
             [(int)((int)fVar6 & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f)];
        *(float *)(iVar13 + 0x1c) =
             (float)dVar33 *
             JKernel::JMath::jmaCosTable
             [(int)((int)fVar37 & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f)];
        fVar6 = SComponent::cM_rndF(local_2b0);
        *(float *)(iVar13 + 0x18) = fVar6;
      }
      else {
        fVar6 = SComponent::cM_rndFX((float)dVar33);
        *(float *)(iVar13 + 0x14) = fVar6;
        fVar6 = SComponent::cM_rndF(local_2b0);
        *(float *)(iVar13 + 0x18) = fVar6;
        fVar6 = SComponent::cM_rndFX(local_2ac);
        *(float *)(iVar13 + 0x1c) = fVar6;
      }
      fVar6 = 0_0;
      *(float *)(iVar13 + 0x20) = 0_0;
      *(float *)(iVar13 + 0x24) = fVar6;
      *(float *)(iVar13 + 0x28) = fVar6;
      fVar6 = SComponent::cM_rndF(360_0);
      *(float *)(iVar13 + 0x2c) = fVar6;
      fVar6 = SComponent::cM_rndF(1_0);
      *(float *)(iVar13 + 0x30) = fVar6;
      fVar6 = SComponent::cM_rndF(65536_0);
      local_188 = (longlong)(int)fVar6;
      *(short *)(iVar13 + 0x3c) = (short)(int)fVar6;
      *(float *)(iVar13 + 0x34) = 0_0;
      *(undefined2 *)(iVar13 + 0x3e) = 0;
      *(char *)(iVar13 + 0x10) = *(char *)(iVar13 + 0x10) + '\x01';
    }
    else {
      if ((-1 < cVar9) && (cVar9 < '\x03')) {
        dVar18 = dVar21;
        fVar6 = 1_5;
        if (cVar9 != '\x01') {
          dVar18 = (double)5_0;
          fVar6 = 10_0;
        }
        dVar23 = (double)fVar6;
        local_2b0 = local_2bc * (1_0 + 0_8 * *(float *)(iVar13 + 0x30));
        *(short *)(iVar13 + 0x3c) = *(short *)(iVar13 + 0x3c) + 400;
        fVar6 = *(float *)(iVar13 + 0x30);
        local_29c = 10_0 * local_2a8 + 0_5 * 10_0 * local_2a8 * fVar6;
        local_298 = (float)(dVar18 * (double)(0_5 + fVar6));
        local_298 = local_298 + 0_5 * local_298 * fVar6;
        local_294 = 10_0 * local_2a0 + 0_5 * 10_0 * local_2a0 * fVar6;
        ::cXyz::operator__(&local_338,(cXyz *)(iVar5 + 0xbb90),(cXyz *)(iVar13 + 0x14));
        local_2cc.x = local_338.x;
        local_2cc.z = local_338.z;
        local_2cc.y = local_338.y + 200_0;
        d_kankyo_wether::dKyw_pntwind_get_vecpow(&local_344,&local_2cc);
        fVar6 = _8064;
        local_2d8 = local_344.x;
        local_2d4 = local_344.y;
        local_2d0 = local_344.z;
        *(float *)(iVar13 + 0x20) = *(float *)(iVar13 + 0x20) + _8064 * local_344.x;
        *(float *)(iVar13 + 0x24) = *(float *)(iVar13 + 0x24) + fVar6 * local_344.y;
        if (*(float *)(iVar13 + 0x24) < 0_0) {
          *(float *)(iVar13 + 0x24) = 0_0;
        }
        *(float *)(iVar13 + 0x28) = *(float *)(iVar13 + 0x28) + _8064 * local_344.z;
        if (((_8065 < *(float *)(iVar13 + 0x20)) || (_8065 < *(float *)(iVar13 + 0x24))) ||
           (_8065 < *(float *)(iVar13 + 0x28))) {
          *(undefined2 *)(iVar13 + 0x3e) = 0xb4;
        }
        SComponent::cLib_addCalc((float *)(iVar13 + 0x20),0_0,0_2,0_6,0_001);
        SComponent::cLib_addCalc((float *)(iVar13 + 0x24),0_0,0_2,0_6,0_001);
        SComponent::cLib_addCalc((float *)(iVar13 + 0x28),0_0,0_2,0_6,0_001);
        *(float *)(iVar13 + 0x14) =
             *(float *)(iVar13 + 0x14) + local_29c + *(float *)(iVar13 + 0x20);
        *(float *)(iVar13 + 0x18) =
             *(float *)(iVar13 + 0x18) + local_298 + *(float *)(iVar13 + 0x24);
        *(float *)(iVar13 + 0x1c) =
             *(float *)(iVar13 + 0x1c) + local_294 + *(float *)(iVar13 + 0x28);
        iVar7 = (int)((int)local_230 & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
        local_298 = 5_0 * (float)(dVar20 * (double)JKernel::JMath::jmaSinTable[iVar7]);
        fVar6 = 5_0 * (float)(dVar20 * (double)(JKernel::JMath::jmaCosTable
                                                [(int)((int)local_230 & 0xffffU) >>
                                                 (JKernel::JMath::jmaSinShift & 0x3f)] *
                                               JKernel::JMath::jmaCosTable
                                               [(int)((int)local_22e & 0xffffU) >>
                                                (JKernel::JMath::jmaSinShift & 0x3f)]));
        *(float *)(iVar13 + 0x14) =
             *(float *)(iVar13 + 0x14) +
             5_0 * (float)(dVar20 * (double)(JKernel::JMath::jmaCosTable[iVar7] *
                                            JKernel::JMath::jmaSinTable
                                            [(int)((int)local_22e & 0xffffU) >>
                                             (JKernel::JMath::jmaSinShift & 0x3f)]));
        *(float *)(iVar13 + 0x18) = *(float *)(iVar13 + 0x18) + local_298;
        *(float *)(iVar13 + 0x1c) = *(float *)(iVar13 + 0x1c) + fVar6;
        uVar8 = (uint)((double)65535_0 * (double)*(float *)(iVar13 + 0x30));
        local_190 = (longlong)(int)uVar8;
        local_294 = (float)((double)*(float *)(iVar13 + 0x30) * dVar23);
        local_29c = local_294 *
                    JKernel::JMath::jmaSinTable
                    [(int)(uVar8 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
        local_294 = local_294 *
                    JKernel::JMath::jmaCosTable
                    [(int)(uVar8 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
        *(float *)(iVar13 + 0x14) = *(float *)(iVar13 + 0x14) + local_29c;
        *(float *)(iVar13 + 0x1c) = *(float *)(iVar13 + 0x1c) + local_294;
        local_188 = local_190;
        if (*(short *)(iVar13 + 0x3e) == 0) {
          bVar2 = false;
          if (iVar14 == 2) {
            local_2e4.x = *(float *)(iVar5 + 0xbb90) + *(float *)(iVar13 + 0x14);
            local_2e4.y = *(float *)(iVar5 + 0xbb94);
            local_2e4.z = *(float *)(iVar5 + 0xbb98) + *(float *)(iVar13 + 0x1c);
            fVar37 = mtx::PSVECSquareDistance(&local_2e4,(cXyz *)(iVar5 + 0xbb90));
            fVar6 = _8066;
            dVar18 = (double)fVar37;
            if ((double)0_0 < dVar18) {
              dVar23 = 1.0 / SQRT(dVar18);
              dVar23 = 0_5 * dVar23 * (3_0 - dVar18 * dVar23 * dVar23);
              dVar23 = 0_5 * dVar23 * (3_0 - dVar18 * dVar23 * dVar23);
              dVar18 = (double)(float)(dVar18 * 0_5 * dVar23 * (3_0 - dVar18 * dVar23 * dVar23));
            }
            if ((double)local_2b4 <= dVar18) {
              bVar2 = true;
              *(float *)(iVar13 + 0x14) = _8066 * -*(float *)(iVar13 + 0x14);
              *(float *)(iVar13 + 0x1c) = fVar6 * -*(float *)(iVar13 + 0x1c);
            }
          }
          else {
            if (iVar14 == 4) {
              fVar6 = *(float *)(iVar13 + 0x14);
              local_2f0 = *(float *)(iVar5 + 0xbb90) + fVar6;
              local_2ec = *(float *)(iVar5 + 0xbb94) + *(float *)(iVar13 + 0x18);
              local_2e8 = *(float *)(iVar5 + 0xbb98) + *(float *)(iVar13 + 0x1c);
              if (fVar6 <= local_2b4) {
                if (fVar6 < -local_2b4) {
                  bVar2 = true;
                  *(float *)(iVar13 + 0x14) = local_2b4;
                }
              }
              else {
                bVar2 = true;
                *(float *)(iVar13 + 0x14) = -local_2b4;
              }
              if (local_2f0 <= _8067) {
                if (local_2f0 <= _8068) {
                  if ((_8069 <= local_2f0) || (local_2f0 <= _8070)) {
                    if (*(float *)(iVar13 + 0x1c) <= local_2ac) {
                      if (*(float *)(iVar13 + 0x1c) < -local_2ac) {
                        *(float *)(iVar13 + 0x1c) = -local_2ac;
                        bVar2 = true;
                      }
                    }
                    else {
                      *(float *)(iVar13 + 0x1c) = local_2ac;
                      bVar2 = true;
                    }
                  }
                  else {
                    if (dVar28 <= (double)local_2e8) {
                      if (dVar27 < (double)local_2e8) {
                        *(float *)(iVar13 + 0x1c) =
                             (float)(dVar27 - (double)*(float *)(iVar5 + 0xbb98));
                        bVar2 = true;
                      }
                    }
                    else {
                      *(float *)(iVar13 + 0x1c) =
                           (float)(dVar28 - (double)*(float *)(iVar5 + 0xbb98));
                      bVar2 = true;
                    }
                  }
                }
                else {
                  if (dVar29 <= (double)local_2e8) {
                    if (dVar30 < (double)local_2e8) {
                      *(float *)(iVar13 + 0x1c) =
                           (float)(dVar30 - (double)*(float *)(iVar5 + 0xbb98));
                      bVar2 = true;
                    }
                  }
                  else {
                    *(float *)(iVar13 + 0x1c) = (float)(dVar29 - (double)*(float *)(iVar5 + 0xbb98))
                    ;
                    bVar2 = true;
                  }
                }
              }
              else {
                if (dVar31 <= (double)local_2e8) {
                  if (dVar30 < (double)local_2e8) {
                    *(float *)(iVar13 + 0x1c) = (float)(dVar30 - (double)*(float *)(iVar5 + 0xbb98))
                    ;
                    bVar2 = true;
                  }
                }
                else {
                  *(float *)(iVar13 + 0x1c) = (float)(dVar31 - (double)*(float *)(iVar5 + 0xbb98));
                  bVar2 = true;
                }
              }
              if (bVar2) {
                fVar6 = SComponent::cM_rndF(1_0);
                *(float *)(iVar13 + 0x30) = fVar6;
              }
            }
            else {
              if (iVar14 == 3) {
                local_2fc = *(float *)(iVar5 + 0xbb90) + *(float *)(iVar13 + 0x14);
                local_2f8 = *(float *)(iVar5 + 0xbb94) + *(float *)(iVar13 + 0x18);
                fVar6 = *(float *)(iVar13 + 0x1c);
                local_2f4 = *(float *)(iVar5 + 0xbb98) + fVar6;
                if (fVar6 <= local_2ac) {
                  if (fVar6 < -local_2ac) {
                    *(float *)(iVar13 + 0x1c) = local_2ac;
                    bVar2 = true;
                  }
                }
                else {
                  *(float *)(iVar13 + 0x1c) = -local_2ac;
                  bVar2 = true;
                }
                if (local_2f4 <= _8071) {
                  if (*(float *)(iVar13 + 0x14) <= local_2b4) {
                    if (*(float *)(iVar13 + 0x14) < -local_2b4) {
                      *(float *)(iVar13 + 0x14) = -local_2b4;
                      bVar2 = true;
                    }
                  }
                  else {
                    *(float *)(iVar13 + 0x14) = local_2b4;
                    bVar2 = true;
                  }
                }
                else {
                  if (dVar26 <= (double)local_2fc) {
                    if (dVar25 < (double)local_2fc) {
                      *(float *)(iVar13 + 0x14) =
                           (float)(dVar25 - (double)*(float *)(iVar5 + 0xbb90));
                      bVar2 = true;
                    }
                  }
                  else {
                    *(float *)(iVar13 + 0x14) = (float)(dVar26 - (double)*(float *)(iVar5 + 0xbb90))
                    ;
                    bVar2 = true;
                  }
                }
                if (bVar2) {
                  fVar6 = SComponent::cM_rndF(1_0);
                  *(float *)(iVar13 + 0x30) = fVar6;
                }
              }
              else {
                if (*(float *)(iVar13 + 0x14) <= local_2b4) {
                  if (*(float *)(iVar13 + 0x14) < -local_2b4) {
                    *(float *)(iVar13 + 0x14) = local_2b4;
                    bVar2 = true;
                  }
                }
                else {
                  *(float *)(iVar13 + 0x14) = -local_2b4;
                  bVar2 = true;
                }
                if (*(float *)(iVar13 + 0x1c) <= local_2ac) {
                  if (*(float *)(iVar13 + 0x1c) < -local_2ac) {
                    *(float *)(iVar13 + 0x1c) = local_2ac;
                    bVar2 = true;
                  }
                }
                else {
                  *(float *)(iVar13 + 0x1c) = -local_2ac;
                  bVar2 = true;
                }
              }
            }
          }
          if ((*(float *)(iVar13 + 0x18) <= local_2b0) || (0_001 < *(float *)(iVar13 + 0x34))) {
            if ((*(float *)(iVar13 + 0x18) < 0_0) && (*(float *)(iVar13 + 0x34) <= 0_001)) {
              *(float *)(iVar13 + 0x18) = local_2b0;
            }
          }
          else {
            *(float *)(iVar13 + 0x18) = 0_0;
          }
          if (bVar2) {
            *(float *)(iVar13 + 0x34) = 0_0;
            *(undefined2 *)(iVar13 + 0x3e) = 0x78;
          }
        }
      }
    }
    local_2cc.x = *(float *)(iVar5 + 0xbb90) + *(float *)(iVar13 + 0x14);
    local_2cc.y = *(float *)(iVar5 + 0xbb94) + *(float *)(iVar13 + 0x18);
    local_2cc.z = *(float *)(iVar5 + 0xbb98) + *(float *)(iVar13 + 0x1c);
    dKyr_get_vectle_calc(&pcVar3->mEyePos,&pcVar3->mCenterPos,&local_308);
    if (iVar14 == 0) {
      local_314.x = (pcVar3->mEyePos).x + 2000_0 * local_308.x;
      local_314.y = (pcVar3->mEyePos).y + 2000_0 * local_308.y;
      local_314.z = (pcVar3->mEyePos).z + 2000_0 * local_308.z;
    }
    else {
      local_314.x = (pcVar3->mEyePos).x;
      local_314.y = (pcVar3->mEyePos).y;
      local_314.z = (pcVar3->mEyePos).z;
    }
    fVar6 = mtx::PSVECSquareDistance(&local_2cc,&local_314);
    dVar18 = (double)fVar6;
    if (dVar34 < dVar18) {
      dVar23 = 1.0 / SQRT(dVar18);
      dVar23 = 0_5 * dVar23 * (3_0 - dVar18 * dVar23 * dVar23);
      dVar23 = 0_5 * dVar23 * (3_0 - dVar18 * dVar23 * dVar23);
      dVar18 = (double)(float)(dVar18 * 0_5 * dVar23 * (3_0 - dVar18 * dVar23 * dVar23));
    }
    if (dVar18 < dVar36) {
      *(float *)(iVar5 + 0xbb9c) = local_2cc.x;
      *(float *)(iVar5 + 0xbba0) = local_2cc.y;
      *(float *)(iVar5 + 0xbba4) = local_2cc.z;
      dVar36 = dVar18;
    }
    dVar18 = (double)(float)(dVar18 / (double)(local_2b4 + local_2ac));
    if (dVar35 < dVar18) {
      dVar18 = dVar35;
    }
    uVar8 = SComponent::cM_rad2s((double)*(float *)(iVar13 + 0x2c));
    fVar6 = JKernel::JMath::jmaSinTable
            [(int)(uVar8 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
    *(float *)(iVar13 + 0x2c) = (float)((double)*(float *)(iVar13 + 0x2c) + local_170);
    *(float *)(iVar13 + 0x38) =
         (float)(dVar22 + (double)(float)(dVar22 * dVar18)) + (float)(dVar24 * (double)fVar6);
    dVar18 = (double)*(float *)(iVar13 + 0x18);
    dVar23 = (double)local_2b0;
    if (dVar18 <= (double)(float)(local_168 * dVar23)) {
      if ((double)(float)((double)0_1 * dVar23) <= dVar18) {
        dVar18 = (double)1_0;
      }
      else {
        dVar18 = (double)(float)(dVar18 / (double)(float)((double)0_1 * dVar23));
      }
    }
    else {
      dVar18 = (double)(float)((double)(float)(dVar23 - dVar18) /
                              (double)(float)(local_168 * dVar23));
    }
    if (iVar14 == 2) {
      local_320.x = local_2cc.x;
      local_320.z = local_2cc.z;
      local_320.y = *(float *)(iVar5 + 0xbb94);
      fVar6 = mtx::PSVECSquareDistance(&local_320,(cXyz *)(iVar5 + 0xbb90));
      dVar23 = (double)fVar6;
      if ((double)0_0 < dVar23) {
        dVar17 = 1.0 / SQRT(dVar23);
        dVar17 = 0_5 * dVar17 * (3_0 - dVar23 * dVar17 * dVar17);
        dVar17 = 0_5 * dVar17 * (3_0 - dVar23 * dVar17 * dVar17);
        dVar23 = (double)(float)(dVar23 * 0_5 * dVar17 * (3_0 - dVar23 * dVar17 * dVar17));
      }
      fVar6 = (float)(dVar23 / (double)local_2b4);
      if (1_0 < (float)(dVar23 / (double)local_2b4)) {
        fVar6 = 1_0;
      }
      dVar17 = (double)(1_0 - fVar6 * fVar6 * fVar6 * fVar6 * fVar6);
    }
    else {
      dVar23 = (double)1_0;
      if (local_2b4 - 100_0 < ABS(*(float *)(iVar13 + 0x14))) {
        dVar17 = (double)(local_2b4 - (local_2b4 - 100_0));
        dVar23 = (double)0_0;
        if (dVar23 < dVar17) {
          dVar23 = (double)(float)((double)(local_2b4 - ABS(*(float *)(iVar13 + 0x14))) / dVar17);
        }
      }
      dVar17 = dVar23;
      if (local_2ac - 100_0 < ABS(*(float *)(iVar13 + 0x1c))) {
        dVar19 = (double)(local_2ac - (local_2ac - 100_0));
        dVar17 = (double)0_0;
        if (dVar17 < dVar19) {
          dVar17 = (double)(float)(dVar23 * (double)(float)((double)(local_2ac -
                                                                    ABS(*(float *)(iVar13 + 0x1c)))
                                                           / dVar19));
        }
      }
    }
    *(float *)(iVar13 + 0x38) = (float)((double)*(float *)(iVar13 + 0x38) * dVar17);
    dVar18 = (double)(float)(dVar35 - (double)((float)(dVar35 - dVar18) * (float)(dVar35 - dVar18)))
    ;
    if (*(short *)(iVar13 + 0x3e) == 0) {
      if (*(char *)(iVar13 + 0x10) == '\x02') {
        *(undefined *)(iVar13 + 0x10) = 0;
      }
    }
    else {
      *(short *)(iVar13 + 0x3e) = *(short *)(iVar13 + 0x3e) + -1;
      dVar18 = (double)0_0;
    }
    cVar9 = d_kankyo::dKy_contrast_flg_get();
    if (cVar9 != '\0') {
      dVar18 = (double)0_0;
    }
    SComponent::cLib_addCalc
              ((float *)(iVar13 + 0x34),(float)(dVar17 * (double)(float)(dVar32 * dVar18)),0_05,0_01
               ,0_001);
    dVar18 = (double)200_0;
    if (iVar14 == 0) {
      local_314.x = (pcVar3->mEyePos).x;
      local_314.y = (pcVar3->mEyePos).y;
      local_314.z = (pcVar3->mEyePos).z;
    }
    else {
      if (iVar14 == 3) {
        dVar18 = (double)450_0;
      }
    }
    fVar6 = mtx::PSVECSquareDistance(&local_2cc,&local_314);
    dVar23 = (double)fVar6;
    if (dVar34 < dVar23) {
      dVar17 = 1.0 / SQRT(dVar23);
      dVar17 = 0_5 * dVar17 * (3_0 - dVar23 * dVar17 * dVar17);
      dVar17 = 0_5 * dVar17 * (3_0 - dVar23 * dVar17 * dVar17);
      dVar23 = (double)(float)(dVar23 * 0_5 * dVar17 * (3_0 - dVar23 * dVar17 * dVar17));
    }
    if (dVar23 < dVar18) {
      fVar6 = (float)(dVar23 / (double)450_0);
      if (1_0 < (float)(dVar23 / (double)450_0)) {
        fVar6 = 1_0;
      }
      *(float *)(iVar13 + 0x34) = *(float *)(iVar13 + 0x34) * fVar6 * fVar6 * fVar6;
    }
    if (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor ==
          d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor) &&
        (0_0001 < *(float *)(iVar13 + 0x34))) && (*(short *)(iVar13 + 0x3e) == 0)) {
      local_2cc.y = local_2cc.y - 50_0;
      fVar6 = mtx::PSVECSquareDistance(&local_2cc,&(pdVar4->parent).parent.mCurrent.mPos);
      dVar18 = (double)fVar6;
      if ((double)0_0 < dVar18) {
        dVar23 = 1.0 / SQRT(dVar18);
        dVar23 = 0_5 * dVar23 * (3_0 - dVar18 * dVar23 * dVar23);
        dVar23 = 0_5 * dVar23 * (3_0 - dVar18 * dVar23 * dVar23);
        dVar18 = (double)(float)(dVar18 * 0_5 * dVar23 * (3_0 - dVar18 * dVar23 * dVar23));
      }
      if (dVar18 < (double)(0_8 * *(float *)(iVar13 + 0x38))) {
        (pdVar4->parent).field_0x2a4 = (pdVar4->parent).field_0x2a4 | 0x100000;
      }
    }
    iVar15 = iVar15 + 0x30;
  }
  *(int *)(d_kankyo::g_env_light._2540_4_ + 0xbba8) =
       *(int *)(d_kankyo::g_env_light._2540_4_ + 0xbba8) + 1;
  __psq_l0(auStack8,uVar16);
  __psq_l1(auStack8,uVar16);
  __psq_l0(auStack24,uVar16);
  __psq_l1(auStack24,uVar16);
  __psq_l0(auStack40,uVar16);
  __psq_l1(auStack40,uVar16);
  __psq_l0(auStack56,uVar16);
  __psq_l1(auStack56,uVar16);
  __psq_l0(auStack72,uVar16);
  __psq_l1(auStack72,uVar16);
  __psq_l0(auStack88,uVar16);
  __psq_l1(auStack88,uVar16);
  __psq_l0(auStack104,uVar16);
  __psq_l1(auStack104,uVar16);
  __psq_l0(auStack120,uVar16);
  __psq_l1(auStack120,uVar16);
  __psq_l0(auStack136,uVar16);
  __psq_l1(auStack136,uVar16);
  __psq_l0(auStack152,uVar16);
  __psq_l1(auStack152,uVar16);
  __psq_l0(auStack168,uVar16);
  __psq_l1(auStack168,uVar16);
  __psq_l0(auStack184,uVar16);
  __psq_l1(auStack184,uVar16);
  __psq_l0(auStack200,uVar16);
  __psq_l1(auStack200,uVar16);
  __psq_l0(auStack216,uVar16);
  __psq_l1(auStack216,uVar16);
  __psq_l0(auStack232,uVar16);
  __psq_l1(auStack232,uVar16);
  __psq_l0(auStack248,uVar16);
  __psq_l1(auStack248,uVar16);
  __psq_l0(auStack264,uVar16);
  __psq_l1(auStack264,uVar16);
  __psq_l0(auStack280,uVar16);
  __psq_l1(auStack280,uVar16);
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x800940ac) */
/* WARNING: Removing unreachable block (ram,0x8009409c) */
/* WARNING: Removing unreachable block (ram,0x8009408c) */
/* WARNING: Removing unreachable block (ram,0x8009407c) */
/* WARNING: Removing unreachable block (ram,0x8009406c) */
/* WARNING: Removing unreachable block (ram,0x8009405c) */
/* WARNING: Removing unreachable block (ram,0x80094054) */
/* WARNING: Removing unreachable block (ram,0x80094064) */
/* WARNING: Removing unreachable block (ram,0x80094074) */
/* WARNING: Removing unreachable block (ram,0x80094084) */
/* WARNING: Removing unreachable block (ram,0x80094094) */
/* WARNING: Removing unreachable block (ram,0x800940a4) */
/* WARNING: Removing unreachable block (ram,0x800940b4) */
/* __stdcall vrkumo_move(void) */

void vrkumo_move(void)

{
  camera_class *pcVar1;
  short local_r0_600;
  int iVar2;
  stage_stag_info_class *pStag;
  dStage_roomStatus_c *pRoomStatus;
  dStage_FileList_dt_c *pFili;
  uint uVar3;
  int iVar4;
  short local_r5_592;
  short sVar6;
  uint uVar5;
  dKankyo_vrkumo_Packet *pKumo;
  undefined4 uVar7;
  double dVar8;
  double dVar9;
  double distNormalized;
  undefined8 in_f19;
  double dVar123;
  undefined8 in_f20;
  double dVar10;
  undefined8 in_f21;
  undefined8 in_f22;
  double dVar11;
  undefined8 in_f23;
  double 15000_0;
  undefined8 in_f24;
  double dVar12;
  undefined8 in_f25;
  double strengthAlpha;
  undefined8 in_f26;
  double 0_0;
  undefined8 in_f27;
  double 1_0;
  double alphaTarget;
  undefined8 in_f29;
  double 0_98;
  undefined8 in_f30;
  double skyboxY_;
  undefined8 in_f31;
  double dVar13;
  float fVar14;
  TVec3_float_ local_14c;
  cXyz local_140;
  cXyz velocity;
  TVec3_float_ windVec;
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  byte status;
  float falloff;
  dKankyo_vrkumo_Packet *pPkt;
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)alphaTarget >> 0x20),0);
  __psq_st1(auStack56,SUB84(alphaTarget,0),0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  d_kankyo_wether::dKyw_get_wind_vecpow((cXyz *)&local_14c);
  pPkt = d_kankyo::g_env_light.mpVrkumoPacket;
  pcVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  windVec.x = local_14c.x;
  windVec.z = local_14c.z;
  dVar13 = (double)(4_0 + d_kankyo::g_env_light.mVrkumoStrength * 4_3);
  skyboxY_ = (double)(1000_0 + d_kankyo::g_env_light.mVrkumoStrength * _500_0);
  dVar12 = (double)(3000_0 + d_kankyo::g_env_light.mVrkumoStrength * _1000_0);
  0_98 = (double)(0_98 + d_kankyo::g_env_light.mVrkumoStrength * 0_0);
  strengthAlpha = (double)(1_0 + d_kankyo::g_env_light.mVrkumoStrength * _0_55);
  iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"M_DragB");
  if (iVar2 == 0) {
    windVec.x = _1_0;
    windVec.z = 0_0;
    skyboxY_ = (double)300_0;
  }
  else {
    pStag = (stage_stag_info_class *)
            (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                      (0x803c9d58);
    if ((pStag->mStageTypeAndSchbit >> 0x10 & 7) == 2) {
      sVar6 = 0;
      iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"LinkRM");
      if (iVar2 == 0) {
        sVar6 = 0x4000;
      }
      else {
        iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Orichh");
        if (iVar2 == 0) {
          sVar6 = -0x4000;
        }
        else {
          iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Ojhous2"
                            );
          if (iVar2 == 0) {
            sVar6 = 0x7fff;
          }
          else {
            iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                               "Omasao");
            if (iVar2 == 0) {
              sVar6 = -0x4000;
            }
            else {
              iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                                (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                 "Onobuta");
              if (iVar2 == 0) {
                sVar6 = 0x4000;
              }
            }
          }
        }
      }
      if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mTactWindAngleX == -1)
         && (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mTactWindAngleY == -1
            )) {
        uVar5 = 0;
        local_r0_600 = 0;
      }
      else {
        uVar5 = SEXT24(d_kankyo::g_env_light.mTactWindAngleX);
        local_r0_600 = d_kankyo::g_env_light.mTactWindAngleY;
      }
      local_r0_600 = local_r0_600 + sVar6;
      iVar2 = (int)((int)local_r0_600 & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
      windVec.x = 0_6 * JKernel::JMath::jmaCosTable
                        [(int)(uVar5 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)] *
                        JKernel::JMath::jmaCosTable[iVar2];
      windVec.z = 0_6 * JKernel::JMath::jmaCosTable
                        [(int)(uVar5 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)] *
                        JKernel::JMath::jmaSinTable[iVar2];
    }
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
    dVar123 = (double)0_0;
    pFili = (dStage_FileList_dt_c *)0x0;
    if (-1 < (char)dStage_roomControl_c::mStayNo) {
      pRoomStatus = dStage_roomControl_c::getStatusRoomDt
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                               (int)(char)dStage_roomControl_c::mStayNo);
      pFili = (dStage_FileList_dt_c *)
              (*(code *)((pRoomStatus->parent).parent.vtbl)->getFileListInfo)();
    }
    if (pFili != (dStage_FileList_dt_c *)0x0) {
      dVar123 = (double)pFili->mSkyboxY;
    }
    iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Siren");
    if ((iVar2 == 0) && (dStage_roomControl_c::mStayNo == 0x11)) {
      dVar123 = (double)_14101_0;
    }
    skyboxY_ = (double)(float)(skyboxY_ -
                              (double)(0_09 * (float)((double)(pcVar1->mEyePos).y - dVar123)));
  }
  uVar5 = 0;
  iVar2 = 0;
  0_0 = (double)0_0;
  1_0 = (double)1_0;
  15000_0 = (double)15000_0;
  dVar11 = (double)500_0;
  dVar10 = (double)100_0;
  dVar123 = _4175;
  do {
    pKumo = (dKankyo_vrkumo_Packet *)((int)pPkt->mInst + iVar2 + -0x20);
    status = pKumo->mInst[0].mStatus;
    if ((status != 2) && ((char)status < '\x02')) {
      if (status == 0) {
        fVar14 = SComponent::cM_rndF(65535_0);
        falloff = SComponent::cM_rndF(18000_0);
        dVar8 = (double)falloff;
        if ((double)15000_0 < dVar8) {
          falloff = SComponent::cM_rndF(1000_0);
          dVar8 = (double)(float)(14000_0 + (double)falloff);
        }
        uVar3 = SComponent::cM_rad2s
                          ((double)(float)((double)CONCAT44(0x43300000,(int)fVar14 & 0xffff) - _8317
                                          ));
        pKumo->mInst[0].mPosition.x =
             (float)(dVar8 * (double)JKernel::JMath::jmaSinTable
                                     [(int)(uVar3 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]
                    );
        pKumo->mInst[0].mPosition.y = 0_0;
        uVar3 = SComponent::cM_rad2s
                          ((double)(float)((double)CONCAT44(0x43300000,(int)fVar14 & 0xffff) - _8317
                                          ));
        pKumo->mInst[0].mPosition.z =
             (float)(dVar8 * (double)JKernel::JMath::jmaCosTable
                                     [(int)(uVar3 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]
                    );
        fVar14 = SComponent::cM_rndFX(0_3);
        pKumo->mInst[0].mHeight = 0_3 * fVar14;
        pKumo->mInst[0].mAlpha = 0_0;
        fVar14 = SComponent::cM_rndF(4_0);
        pKumo->mInst[0].mSpeed = 0_5 + fVar14;
        pKumo->mInst[0].mStatus = pKumo->mInst[0].mStatus + 1;
      }
      else {
        if (-1 < (char)status) {
          velocity.x = pKumo->mInst[0].mPosition.x;
          velocity.z = pKumo->mInst[0].mPosition.z;
          velocity.y = 0_0;
          fVar14 = mtx::PSVECSquareMag(&velocity);
          dVar8 = (double)fVar14;
          if ((double)0_0 < dVar8) {
            distNormalized = 1.0 / SQRT(dVar8);
            distNormalized = 0_5 * distNormalized * (3_0 - dVar8 * distNormalized * distNormalized);
            distNormalized = 0_5 * distNormalized * (3_0 - dVar8 * distNormalized * distNormalized);
            dVar8 = (double)(float)(dVar8 * 0_5 * distNormalized *
                                            (3_0 - dVar8 * distNormalized * distNormalized));
          }
          if ((double)15000_0 < dVar8) {
            fVar14 = mtx::PSVECSquareMag(&velocity);
            dVar8 = (double)fVar14;
            if ((double)0_0 < dVar8) {
              distNormalized = 1.0 / SQRT(dVar8);
              distNormalized =
                   0_5 * distNormalized * (3_0 - dVar8 * distNormalized * distNormalized);
              distNormalized =
                   0_5 * distNormalized * (3_0 - dVar8 * distNormalized * distNormalized);
              dVar8 = (double)(float)(dVar8 * 0_5 * distNormalized *
                                              (3_0 - dVar8 * distNormalized * distNormalized));
            }
            if (dVar8 <= (double)15100_0) {
              pKumo->mInst[0].mPosition.x = -pKumo->mInst[0].mPosition.x;
              pKumo->mInst[0].mPosition.z = -pKumo->mInst[0].mPosition.z;
            }
            else {
              fVar14 = SComponent::cM_rndFX(_8311);
              pKumo->mInst[0].mPosition.x = fVar14;
              fVar14 = SComponent::cM_rndFX(_8311);
              pKumo->mInst[0].mPosition.z = fVar14;
            }
            pKumo->mInst[0].mAlpha = 0_0;
          }
          if (0_0 < pKumo->mInst[0].mAlpha) {
            pKumo->mInst[0].mPosition.x =
                 pKumo->mInst[0].mPosition.x +
                 pKumo->mInst[0].mDistFalloff *
                 windVec.x * (float)(dVar13 * (double)pKumo->mInst[0].mSpeed);
            pKumo->mInst[0].mPosition.z =
                 pKumo->mInst[0].mPosition.z +
                 pKumo->mInst[0].mDistFalloff *
                 windVec.z * (float)(dVar13 * (double)pKumo->mInst[0].mSpeed);
          }
          else {
            fVar14 = (float)(dVar13 + (double)(float)((double)((float)((double)CONCAT44(0x43300000,
                                                                                        uVar5 ^ 
                                                  0x80000000) - _4175) / 100_0) * dVar13));
            pKumo->mInst[0].mPosition.x = pKumo->mInst[0].mPosition.x + windVec.x * fVar14;
            pKumo->mInst[0].mPosition.z = pKumo->mInst[0].mPosition.z + windVec.z * fVar14;
          }
        }
      }
    }
    local_140.x = pKumo->mInst[0].mPosition.x;
    local_140.z = pKumo->mInst[0].mPosition.z;
    local_140.y = (float)0_0;
    fVar14 = mtx::PSVECSquareMag(&local_140);
    dVar8 = (double)fVar14;
    if (0_0 < dVar8) {
      distNormalized = 1.0 / SQRT(dVar8);
      distNormalized = 0_5 * distNormalized * (3_0 - dVar8 * distNormalized * distNormalized);
      distNormalized = 0_5 * distNormalized * (3_0 - dVar8 * distNormalized * distNormalized);
      dVar8 = (double)(float)(dVar8 * 0_5 * distNormalized *
                                      (3_0 - dVar8 * distNormalized * distNormalized));
    }
    distNormalized = (double)(float)(dVar8 / 15000_0);
    dVar8 = (double)(float)(1_0 - distNormalized);
    if ((double)(float)(1_0 - distNormalized) < 0_0) {
      dVar8 = 0_0;
    }
    fVar14 = (float)(1_0 - dVar8);
    dVar8 = (double)(float)(1_0 - (double)(fVar14 * fVar14 * fVar14));
    pKumo->mInst[0].mPosition.y =
         (float)(dVar11 * (double)(float)((double)(float)((double)CONCAT44(0x43300000,
                                                                           uVar5 ^ 0x80000000) -
                                                         dVar123) / dVar10)) +
         (float)(skyboxY_ + (double)(float)(dVar12 * dVar8));
    if (1_0 < distNormalized) {
      distNormalized = 1_0;
    }
    pKumo->mInst[0].mDistFalloff =
         (float)(1_0 - (double)(float)(distNormalized *
                                      (double)(float)(distNormalized *
                                                     (double)(float)(distNormalized *
                                                                    (double)(float)(distNormalized *
                                                                                   (double)(float)(
                                                  distNormalized * distNormalized))))));
    iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"M_DragB");
    fVar14 = 1_0;
    if (iVar4 == 0) {
      pKumo->mInst[0].mAlpha = 1_0;
      distNormalized = alphaTarget;
    }
    else {
      if ((int)uVar5 < d_kankyo::g_env_light.mVrkumoCount) {
        falloff = pKumo->mInst[0].mDistFalloff;
        fVar14 = 0_1;
        if ((falloff < 0_2) ||
           (distNormalized = strengthAlpha, d_kankyo::g_env_light.mVrkumoCount <= (int)uVar5)) {
          if (0_05 <= falloff) {
            distNormalized = (double)((falloff - 0_05) / 0_15);
          }
          else {
            distNormalized = (double)0_0;
          }
        }
      }
      else {
        distNormalized = (double)0_0;
        fVar14 = 0_005;
      }
    }
    if (dVar8 <= 0_98) {
      alphaTarget = distNormalized;
      if ((double)0_88 < dVar8) {
        dVar9 = (double)(float)(0_98 - (double)0_88);
        alphaTarget = (double)0_0;
        if (alphaTarget < dVar9) {
          alphaTarget = (double)(float)(distNormalized *
                                       (double)(float)((double)(float)(0_98 - dVar8) / dVar9));
        }
      }
    }
    else {
      alphaTarget = (double)0_0;
    }
    SComponent::cLib_addCalc(&pKumo->mInst[0].mAlpha,(float)alphaTarget,0_2,fVar14,0_01);
    uVar5 = uVar5 + 1;
    iVar2 = iVar2 + 0x2c;
  } while ((int)uVar5 < 100);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  __psq_l0(auStack56,uVar7);
  __psq_l1(auStack56,uVar7);
  __psq_l0(auStack72,uVar7);
  __psq_l1(auStack72,uVar7);
  __psq_l0(auStack88,uVar7);
  __psq_l1(auStack88,uVar7);
  __psq_l0(auStack104,uVar7);
  __psq_l1(auStack104,uVar7);
  __psq_l0(auStack120,uVar7);
  __psq_l1(auStack120,uVar7);
  __psq_l0(auStack136,uVar7);
  __psq_l1(auStack136,uVar7);
  __psq_l0(auStack152,uVar7);
  __psq_l1(auStack152,uVar7);
  __psq_l0(auStack168,uVar7);
  __psq_l1(auStack168,uVar7);
  __psq_l0(auStack184,uVar7);
  __psq_l1(auStack184,uVar7);
  __psq_l0(auStack200,uVar7);
  __psq_l1(auStack200,uVar7);
  return;
}


/* __stdcall dKy_wave_chan_init(void) */

void dKy_wave_chan_init(void)

{
  d_kankyo::g_env_light.field_0x94c = _1_0;
  d_kankyo::g_env_light.field_0x950 = 0_0;
  d_kankyo::g_env_light.field_0x954 = 0_0;
  d_kankyo::g_env_light.mWaveSpeed = 0_1;
  d_kankyo::g_env_light.mWaveSpawnDist = 3000_0;
  d_kankyo::g_env_light.mWaveSpawnRadius = 3150_0;
  d_kankyo::g_env_light.mWaveScale = 250_0;
  d_kankyo::g_env_light.mWaveScaleRand = 0_217;
  d_kankyo::g_env_light.mWaveCounterSpeedScale = 1_6;
  d_kankyo::g_env_light.mWaveScaleBottom = 5_0;
  d_kankyo::g_env_light.mWaveCount = 0;
  d_kankyo::g_env_light.mWaveReset = 0;
  d_kankyo::g_env_light.field_0x97b = 0;
  return;
}


/* __stdcall snap_sunmoon_proc(cXyz *,
                               int) */

void snap_sunmoon_proc(float *param_1,int param_2)

{
  float local_48;
  float local_44;
  float local_40;
  dSnap_Obj dStack60;
  
  ::dSnap_Obj::dSnap_Obj(&dStack60);
  if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc & 8U) != 0) {
    local_48 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos).x;
    local_44 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos).y;
    local_40 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mEyePos).z;
    local_48 = (*param_1 - local_48) * 10_0 + local_48;
    local_44 = (param_1[1] - local_44) * 10_0 + local_44;
    local_40 = (param_1[2] - local_40) * 10_0 + local_40;
    ::dSnap_Obj::SetGeoSph(&dStack60,(Vec *)&local_48,8000_0);
    if (param_2 == 9) {
      ::dSnap_Obj::SetInf(&dStack60,'\t',(fopAc_ac_c *)0x0,0xff,'\x04',0x7fff);
    }
    else {
      if (param_2 == 0) {
        ::dSnap_Obj::SetInf(&dStack60,'\a',(fopAc_ac_c *)0x0,0xff,'\x04',0x7fff);
      }
      else {
        ::dSnap_Obj::SetInf(&dStack60,'\b',(fopAc_ac_c *)0x0,0xff,'\x04',0x7fff);
      }
    }
    d_snap::dSnap_RegistSnapObj(&dStack60);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x80095124) */
/* WARNING: Removing unreachable block (ram,0x80095114) */
/* WARNING: Removing unreachable block (ram,0x80095104) */
/* WARNING: Removing unreachable block (ram,0x800950fc) */
/* WARNING: Removing unreachable block (ram,0x8009510c) */
/* WARNING: Removing unreachable block (ram,0x8009511c) */
/* WARNING: Removing unreachable block (ram,0x8009512c) */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dKyr_drawSun(float *[][][][],
                          cXyz *,
                          _GXColor &,
                          unsigned char * *) */

void dKyr_drawSun(MTX34 *param_1,cXyz *param_2,_GXColor *param_3,byte **param_4)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float *pfVar4;
  float *pfVar5;
  float fVar6;
  stage_stag_info_class *pStag;
  float *pfVar7;
  float *pfVar8;
  int dayOfWeek;
  int whichTexture;
  bool bDrawSun;
  bool bDrawMoon;
  int iVar9;
  undefined4 uVar10;
  double dVar11;
  undefined8 in_f25;
  undefined8 in_f26;
  double camPitch;
  double size;
  undefined8 in_f27;
  double dVar12;
  undefined8 in_f28;
  double dVar13;
  undefined8 in_f29;
  double dVar14;
  double dVar15;
  undefined8 in_f30;
  double sunPitch;
  undefined8 in_f31;
  _GXColor local_1e8;
  _GXColor local_1e4;
  _GXColor local_1e0;
  _GXColor local_1dc;
  _GXColor local_1d8;
  _GXColor local_1d4;
  _GXColor local_1d0;
  uint local_1cc;
  cXyz cStack456;
  cXyz camFwd1;
  cXyz local_1b0;
  cXyz local_1a4;
  cXyz moonPos;
  cXyz local_18c;
  cXyz sunPos;
  float local_174 [7];
  GXTexObj GStack344;
  MTX34 MStack312;
  MTX34 invViewNoTrans;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  longlong local_a8;
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  camera_class *pCamera;
  dKankyo_sunlenz_Packet *pLenz;
  dKankyo_sun_Packet *pSun;
  
  pLenz = d_kankyo::g_env_light.mpSunlenzPacket;
  pSun = d_kankyo::g_env_light.mpSunPacket;
  pCamera = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar10 = 0;
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
  bDrawSun = 0_0 < (d_kankyo::g_env_light.mpSunPacket)->mSunAlpha;
  bDrawMoon = 0_0 < (d_kankyo::g_env_light.mpSunPacket)->mMoonAlpha;
  if (bDrawSun || bDrawMoon) {
    sunPos.x = param_2->x;
    sunPos.y = param_2->y;
    sunPos.z = param_2->z;
    pStag = (stage_stag_info_class *)
            (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
    if ((d_kankyo::g_env_light.mBaseLightInfluence.mColor.r == 0) &&
       ((pStag->mStageTypeAndSchbit >> 0x10 & 7) != 2)) {
      if ((285_0 < d_kankyo::g_env_light.mCurTime) || (d_kankyo::g_env_light.mCurTime < _8701)) {
        bDrawMoon = false;
      }
      local_18c.x = param_2->x;
      local_18c.y = param_2->y;
      local_18c.z = param_2->z;
    }
    else {
      fVar6 = (pCamera->mEyePos).x;
      moonPos.x = -(param_2->x - fVar6);
      fVar1 = (pCamera->mEyePos).y;
      moonPos.y = -(param_2->y - fVar1);
      fVar2 = (pCamera->mEyePos).z;
      moonPos.z = -(param_2->z - fVar2);
      local_18c.x = moonPos.x + fVar6;
      local_18c.y = moonPos.y + fVar1;
      local_18c.z = moonPos.z + fVar2;
    }
    dayOfWeek = d_kankyo::dKy_get_dayofweek();
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime < 180_0) {
      if (dayOfWeek == 0) {
        dayOfWeek = 6;
      }
      else {
        dayOfWeek = dayOfWeek + -1;
      }
    }
    switch(dayOfWeek) {
    case 0:
      whichTexture = 0;
      dVar12 = (double)1_0;
      break;
    case 1:
      whichTexture = 1;
      dVar12 = (double)1_0;
      break;
    case 2:
      whichTexture = 2;
      dVar12 = (double)1_0;
      break;
    case 3:
      whichTexture = 3;
      dVar12 = (double)1_0;
      break;
    case 4:
      whichTexture = 3;
      dVar12 = (double)_1_0;
      break;
    case 5:
      whichTexture = 2;
      dVar12 = (double)_1_0;
      break;
    default:
      whichTexture = 1;
      dVar12 = (double)_1_0;
    }
    param_3->r = (u8)d_kankyo::g_env_light.mFogColor.r;
    param_3->g = (u8)d_kankyo::g_env_light.mFogColor.g;
    param_3->b = (u8)d_kankyo::g_env_light.mFogColor.b;
    param_3->a = 0xff;
    local_1cc = 0xff;
    if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera == (camera_class *)0x0) {
      if (pSun->field_0x3c < 5) {
        pSun->field_0x3c = pSun->field_0x3c + 2;
      }
      pSun->field_0x3d = true;
    }
    else {
      mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                        &invViewNoTrans);
      dKyr_set_btitex(&GStack344,param_4[whichTexture]);
      gx::GXSetNumChans(0);
      local_1d0 = *param_3;
      gx::GXSetTevColor(GX_TEVREG0,&local_1d0);
      local_1d4 = (_GXColor)local_1cc;
      gx::GXSetTevColor(GX_TEVREG1,&local_1d4);
      gx::GXSetNumTexGens(1);
      gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
      gx::GXSetNumTevStages(1);
      gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
      gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C1,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
      gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
      gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
      gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
      gx::GXSetZMode(true,GX_LEQUAL,false);
      gx::GXSetNumIndStages(0);
      gx::GXSetCullMode(0);
      gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
      gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,8);
      gx::GXClearVtxDesc();
      gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
      gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
      if (bDrawMoon) {
        iVar9 = 3;
        pfVar4 = (float *)&UNK_80352edc;
        pfVar5 = &sunPos.z;
        do {
          pfVar8 = pfVar5;
          pfVar7 = pfVar4;
          fVar6 = pfVar7[2];
          pfVar8[1] = pfVar7[1];
          pfVar8[2] = fVar6;
          iVar9 = iVar9 + -1;
          pfVar4 = pfVar7 + 2;
          pfVar5 = pfVar8 + 2;
        } while (iVar9 != 0);
        pfVar8[3] = pfVar7[3];
        snap_sunmoon_proc(&local_18c,whichTexture);
        dKyr_get_vectle_calc(&pCamera->mEyePos,&pCamera->mCenterPos,&camFwd1);
        size = (double)(camFwd1.x * camFwd1.x + camFwd1.z * camFwd1.z);
        if ((double)0_0 < size) {
          sunPitch = 1.0 / SQRT(size);
          sunPitch = 0_5 * sunPitch * (3_0 - size * sunPitch * sunPitch);
          sunPitch = 0_5 * sunPitch * (3_0 - size * sunPitch * sunPitch);
          size = (double)(float)(size * 0_5 * sunPitch * (3_0 - size * sunPitch * sunPitch));
        }
        sunPitch = MSL_C.PPCEABI.bare.H::atan2((double)camFwd1.x,(double)camFwd1.z);
        sunPitch = (double)(float)sunPitch;
        MSL_C.PPCEABI.bare.H::atan2((double)camFwd1.y,size);
        size = (double)(moonPos.x * moonPos.x + moonPos.z * moonPos.z);
        if ((double)0_0 < size) {
          camPitch = 1.0 / SQRT(size);
          camPitch = 0_5 * camPitch * (3_0 - size * camPitch * camPitch);
          camPitch = 0_5 * camPitch * (3_0 - size * camPitch * camPitch);
          size = (double)(float)(size * 0_5 * camPitch * (3_0 - size * camPitch * camPitch));
        }
        camPitch = MSL_C.PPCEABI.bare.H::atan2((double)moonPos.x,(double)moonPos.z);
        camPitch = (double)(float)camPitch;
        size = MSL_C.PPCEABI.bare.H::atan2((double)moonPos.y,size);
        mtx::PSMTXRotRad(&MStack312,'Z',
                         _8704 * (45_0 + 360_0 * (float)size *
                                                 ((float)(camPitch - sunPitch) / _8703)));
        mtx::PSMTXConcat(&invViewNoTrans,&MStack312,&invViewNoTrans);
        gx::GXLoadPosMtxImm(param_1,0);
        gx::GXSetCurrentMtx(0);
        param_3->r = 0xf3;
        param_3->g = 0xff;
        param_3->b = 0x94;
        size = (double)700_0;
        whichTexture = (int)(255_0 * pSun->mMoonAlpha);
        local_a8 = (longlong)whichTexture;
        param_3->a = (u8)whichTexture;
        local_1d8 = *param_3;
        gx::GXSetTevColor(GX_TEVREG0,&local_1d8);
        whichTexture = 0;
        sunPitch = (double)(float)((double)50_0 * dVar12);
        camPitch = (double)0_0;
        do {
          if (whichTexture == 1) {
            gx::GXInitTexObj(&GStack344,pLenz->mpTexSnow01,0x40,0x40,GX_TF_I8,GX_CLAMP,GX_CLAMP,
                             false);
            dVar11 = (double)0_0;
            gx::GXInitTexObjLOD(dVar11,dVar11,dVar11,&GStack344,1,1,0,0,0);
            gx::GXLoadTexObj(&GStack344,0);
            size = (double)(float)(size * (double)_8705);
            iVar9 = (int)(_8706 * pSun->mMoonAlpha);
            local_a8 = (longlong)iVar9;
            param_3->a = (u8)iVar9;
            param_3->r = 0xff;
            param_3->g = 0xff;
            param_3->b = 0xcf;
            local_1cc._2_2_ = CONCAT11(0x23,(undefined)local_1cc);
            local_1cc = local_1cc._2_2_ | 0xc5690000;
            mtx::PSMTXRotRad(&MStack312,'Z',(float)((double)_8704 * sunPitch));
            mtx::PSMTXConcat(&invViewNoTrans,&MStack312,&invViewNoTrans);
            gx::GXLoadPosMtxImm(param_1,0);
            gx::GXSetCurrentMtx(0);
          }
          local_1dc = *param_3;
          gx::GXSetTevColor(GX_TEVREG0,&local_1dc);
          local_1e0 = (_GXColor)local_1cc;
          gx::GXSetTevColor(GX_TEVREG1,&local_1e0);
          dVar14 = -size;
          local_1a4.x = (float)(dVar14 * dVar12);
          dVar13 = (double)local_1a4.x;
          local_1a4.y = (float)size;
          local_1a4.z = (float)camPitch;
          mtx::PSMTXMultVec(&invViewNoTrans,&local_1a4,&local_1b0);
          local_d8 = local_18c.x + local_1b0.x;
          local_d4 = local_18c.y + local_1b0.y;
          local_d0 = local_18c.z + local_1b0.z;
          local_1a4.x = (float)(size * dVar12);
          dVar11 = (double)local_1a4.x;
          local_1a4.y = (float)size;
          local_1a4.z = (float)camPitch;
          mtx::PSMTXMultVec(&invViewNoTrans,&local_1a4,&local_1b0);
          local_cc = local_18c.x + local_1b0.x;
          local_c8 = local_18c.y + local_1b0.y;
          local_c4 = local_18c.z + local_1b0.z;
          dVar15 = dVar14;
          if (whichTexture != 0) {
            dVar11 = dVar11 * (double)local_174[dayOfWeek];
            dVar15 = dVar14 * (double)local_174[dayOfWeek];
          }
          local_1a4.y = (float)dVar15;
          local_1a4.x = (float)dVar11;
          local_1a4.z = (float)camPitch;
          mtx::PSMTXMultVec(&invViewNoTrans,&local_1a4,&local_1b0);
          local_c0 = local_18c.x + local_1b0.x;
          local_bc = local_18c.y + local_1b0.y;
          local_b8 = local_18c.z + local_1b0.z;
          local_1a4.x = (float)dVar13;
          local_1a4.y = (float)dVar14;
          local_1a4.z = (float)camPitch;
          mtx::PSMTXMultVec(&invViewNoTrans,&local_1a4,&local_1b0);
          local_b4 = local_18c.x + local_1b0.x;
          local_b0 = local_18c.y + local_1b0.y;
          local_ac = local_18c.z + local_1b0.z;
          gx::GXBegin(0x80,0,4);
          write_volatile_4(0xcc008000,local_d8);
          write_volatile_4(0xcc008000,local_d4);
          write_volatile_4(0xcc008000,local_d0);
          write_volatile_2(0xcc008000,0);
          write_volatile_2(0xcc008000,0);
          write_volatile_4(0xcc008000,local_cc);
          write_volatile_4(0xcc008000,local_c8);
          write_volatile_4(0xcc008000,local_c4);
          write_volatile_2(0xcc008000,0xff);
          write_volatile_2(0xcc008000,0);
          write_volatile_4(0xcc008000,local_c0);
          write_volatile_4(0xcc008000,local_bc);
          write_volatile_4(0xcc008000,local_b8);
          write_volatile_2(0xcc008000,0xff);
          write_volatile_2(0xcc008000,0xff);
          write_volatile_4(0xcc008000,local_b4);
          write_volatile_4(0xcc008000,local_b0);
          write_volatile_4(0xcc008000,local_ac);
          write_volatile_2(0xcc008000,0);
          write_volatile_2(0xcc008000,0xff);
          whichTexture = whichTexture + 1;
        } while (whichTexture < 2);
      }
      if (bDrawSun) {
        snap_sunmoon_proc(&sunPos,9);
        size = (double)(sunPos.x * sunPos.x + sunPos.z * sunPos.z);
        if ((double)0_0 < size) {
          sunPitch = 1.0 / SQRT(size);
          sunPitch = 0_5 * sunPitch * (3_0 - size * sunPitch * sunPitch);
          sunPitch = 0_5 * sunPitch * (3_0 - size * sunPitch * sunPitch);
          size = (double)(float)(size * 0_5 * sunPitch * (3_0 - size * sunPitch * sunPitch));
        }
        sunPitch = MSL_C.PPCEABI.bare.H::atan2((double)sunPos.x,(double)sunPos.z);
        sunPitch = (double)(float)sunPitch;
        MSL_C.PPCEABI.bare.H::atan2((double)sunPos.y,size);
        dKyr_get_vectle_calc(&pCamera->mEyePos,&pCamera->mCenterPos,&cStack456);
        size = (double)(cStack456.x * cStack456.x + cStack456.z * cStack456.z);
        if ((double)0_0 < size) {
          camPitch = 1.0 / SQRT(size);
          camPitch = 0_5 * camPitch * (3_0 - size * camPitch * camPitch);
          camPitch = 0_5 * camPitch * (3_0 - size * camPitch * camPitch);
          size = (double)(float)(size * 0_5 * camPitch * (3_0 - size * camPitch * camPitch));
        }
        camPitch = MSL_C.PPCEABI.bare.H::atan2((double)cStack456.x,(double)cStack456.z);
        camPitch = (double)(float)camPitch;
        MSL_C.PPCEABI.bare.H::atan2((double)cStack456.y,size);
        mtx::PSMTXRotRad(&MStack312,'Z',
                         _8704 * (_8707 + 360_0 * ((float)(sunPitch - camPitch) / _8703)));
        mtx::PSMTXConcat(&invViewNoTrans,&MStack312,&invViewNoTrans);
        gx::GXLoadPosMtxImm(param_1,0);
        gx::GXSetCurrentMtx(0);
        param_3->r = 0xff;
        param_3->g = 0xff;
        param_3->b = 0xf1;
        local_1cc._2_2_ = CONCAT11(0x49,(undefined)local_1cc);
        local_1cc = local_1cc._2_2_ | 0xff910000;
        uVar3 = local_1cc;
        fVar6 = 1_0 - pLenz->mDistFalloff;
        size = (double)575_0;
        if (0_0 < pSun->mVisibility) {
          size = (double)(float)(size + (double)(pSun->mVisibility * 500_0 * fVar6 * fVar6));
        }
        dayOfWeek = 0;
        sunPitch = (double)0_0;
        do {
          if (dayOfWeek == 0) {
            dKyr_set_btitex(&GStack344,param_4[4]);
            whichTexture = (int)(255_0 * pSun->mSunAlpha);
            param_3->a = (u8)whichTexture;
          }
          else {
            gx::GXInitTexObj(&GStack344,pLenz->mpTexSnow01,0x40,0x40,GX_TF_I8,GX_CLAMP,GX_CLAMP,
                             false);
            camPitch = (double)0_0;
            gx::GXInitTexObjLOD(camPitch,camPitch,camPitch,&GStack344,1,1,0,0,0);
            gx::GXLoadTexObj(&GStack344,0);
            size = (double)(float)(size * (double)1_6);
            whichTexture = (int)(255_0 * pSun->mSunAlpha);
            param_3->a = (u8)whichTexture;
          }
          local_a8 = (longlong)whichTexture;
          local_1e4 = *param_3;
          gx::GXSetTevColor(GX_TEVREG0,&local_1e4);
          local_1e8 = (_GXColor)uVar3;
          gx::GXSetTevColor(GX_TEVREG1,&local_1e8);
          dVar11 = -size;
          local_1a4.x = (float)(dVar11 * dVar12);
          dVar15 = (double)local_1a4.x;
          local_1a4.y = (float)size;
          local_1a4.z = (float)sunPitch;
          mtx::PSMTXMultVec(&invViewNoTrans,&local_1a4,&local_1b0);
          local_d8 = sunPos.x + local_1b0.x;
          local_d4 = sunPos.y + local_1b0.y;
          local_d0 = sunPos.z + local_1b0.z;
          local_1a4.x = (float)(size * dVar12);
          camPitch = (double)local_1a4.x;
          local_1a4.y = (float)size;
          local_1a4.z = (float)sunPitch;
          mtx::PSMTXMultVec(&invViewNoTrans,&local_1a4,&local_1b0);
          local_cc = sunPos.x + local_1b0.x;
          local_c8 = sunPos.y + local_1b0.y;
          local_c4 = sunPos.z + local_1b0.z;
          local_1a4.x = (float)camPitch;
          local_1a4.y = (float)dVar11;
          local_1a4.z = (float)sunPitch;
          mtx::PSMTXMultVec(&invViewNoTrans,&local_1a4,&local_1b0);
          local_c0 = sunPos.x + local_1b0.x;
          local_bc = sunPos.y + local_1b0.y;
          local_b8 = sunPos.z + local_1b0.z;
          local_1a4.x = (float)dVar15;
          local_1a4.y = (float)dVar11;
          local_1a4.z = (float)sunPitch;
          mtx::PSMTXMultVec(&invViewNoTrans,&local_1a4,&local_1b0);
          local_b4 = sunPos.x + local_1b0.x;
          local_b0 = sunPos.y + local_1b0.y;
          local_ac = sunPos.z + local_1b0.z;
          gx::GXBegin(0x80,0,4);
          write_volatile_4(0xcc008000,local_d8);
          write_volatile_4(0xcc008000,local_d4);
          write_volatile_4(0xcc008000,local_d0);
          write_volatile_2(0xcc008000,0);
          write_volatile_2(0xcc008000,0);
          write_volatile_4(0xcc008000,local_cc);
          write_volatile_4(0xcc008000,local_c8);
          write_volatile_4(0xcc008000,local_c4);
          write_volatile_2(0xcc008000,0xff);
          write_volatile_2(0xcc008000,0);
          write_volatile_4(0xcc008000,local_c0);
          write_volatile_4(0xcc008000,local_bc);
          write_volatile_4(0xcc008000,local_b8);
          write_volatile_2(0xcc008000,0xff);
          write_volatile_2(0xcc008000,0xff);
          write_volatile_4(0xcc008000,local_b4);
          write_volatile_4(0xcc008000,local_b0);
          write_volatile_4(0xcc008000,local_ac);
          write_volatile_2(0xcc008000,0);
          write_volatile_2(0xcc008000,0xff);
          dayOfWeek = dayOfWeek + 1;
        } while (dayOfWeek < 2);
      }
      _sOldVcdVatCmd = 0;
    }
  }
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  __psq_l0(auStack40,uVar10);
  __psq_l1(auStack40,uVar10);
  __psq_l0(auStack56,uVar10);
  __psq_l1(auStack56,uVar10);
  __psq_l0(auStack72,uVar10);
  __psq_l1(auStack72,uVar10);
  __psq_l0(auStack88,uVar10);
  __psq_l1(auStack88,uVar10);
  __psq_l0(auStack104,uVar10);
  __psq_l1(auStack104,uVar10);
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x80095e64) */
/* WARNING: Removing unreachable block (ram,0x80095e54) */
/* WARNING: Removing unreachable block (ram,0x80095e44) */
/* WARNING: Removing unreachable block (ram,0x80095e34) */
/* WARNING: Removing unreachable block (ram,0x80095e24) */
/* WARNING: Removing unreachable block (ram,0x80095e14) */
/* WARNING: Removing unreachable block (ram,0x80095e04) */
/* WARNING: Removing unreachable block (ram,0x80095df4) */
/* WARNING: Removing unreachable block (ram,0x80095de4) */
/* WARNING: Removing unreachable block (ram,0x80095c58) */
/* WARNING: Removing unreachable block (ram,0x80095dec) */
/* WARNING: Removing unreachable block (ram,0x80095dfc) */
/* WARNING: Removing unreachable block (ram,0x80095e0c) */
/* WARNING: Removing unreachable block (ram,0x80095e1c) */
/* WARNING: Removing unreachable block (ram,0x80095e2c) */
/* WARNING: Removing unreachable block (ram,0x80095e3c) */
/* WARNING: Removing unreachable block (ram,0x80095e4c) */
/* WARNING: Removing unreachable block (ram,0x80095e5c) */
/* WARNING: Removing unreachable block (ram,0x80095e6c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dKyr_drawLenzflare(float *[][][][],
                                cXyz *,
                                _GXColor &,
                                unsigned char * *) */

void dKyr_drawLenzflare
               (MTX34 *param_1,cXyz *param_2,_GXColor *param_3,void **param_4)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  dKankyo_sun_Packet *pdVar10;
  dKankyo_sunlenz_Packet *pdVar11;
  _GXTexFmt *p_Var12;
  float *pfVar13;
  undefined2 uVar14;
  int iVar15;
  int iVar16;
  int which;
  short angle1;
  ushort angle0;
  uint index;
  undefined4 uVar17;
  double arcSize;
  double dVar18;
  double base;
  undefined8 in_f14;
  undefined8 in_f15;
  undefined8 in_f16;
  double dVar19;
  double 0_5;
  double scale2;
  undefined8 in_f18;
  double invDistance;
  undefined8 in_f19;
  double vizSq;
  double p2x;
  undefined8 in_f20;
  double dVar20;
  undefined8 in_f21;
  double dVar21;
  undefined8 in_f22;
  double dVar22;
  undefined8 in_f23;
  double dVar23;
  double vizSq_;
  undefined8 in_f25;
  undefined8 in_f26;
  double viz;
  undefined8 in_f27;
  undefined8 in_f28;
  double 0_6;
  undefined8 in_f29;
  double 34_0;
  undefined8 in_f30;
  double 0_0;
  undefined8 in_f31;
  double 1600_0;
  _GXColor local_284;
  _GXColor local_280;
  _GXColor _Stack636;
  _GXColor local_278;
  _GXColor color1;
  _GXColor color0;
  cXyz local_26c;
  cXyz local_260;
  cXyz local_254;
  cXyz local_248;
  GXTexObj GStack572;
  cXyz local_21c;
  cXyz local_210;
  cXyz local_204;
  MTX34 MStack492;
  MTX34 MStack444;
  double local_188;
  undefined4 local_180;
  uint uStack380;
  longlong local_178;
  longlong local_170;
  longlong local_168;
  longlong local_160;
  undefined auStack280 [16];
  undefined auStack264 [16];
  undefined auStack248 [16];
  undefined auStack232 [16];
  undefined auStack216 [16];
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  double base_;
  uint indexMod4;
  float scale;
  
  pdVar11 = d_kankyo::g_env_light.mpSunlenzPacket;
  pdVar10 = d_kankyo::g_env_light.mpSunPacket;
  uVar17 = 0;
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
  __psq_st0(auStack120,(int)((ulonglong)vizSq_ >> 0x20),0);
  __psq_st1(auStack120,SUB84(vizSq_,0),0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  __psq_st0(auStack216,(int)((ulonglong)in_f18 >> 0x20),0);
  __psq_st1(auStack216,(int)in_f18,0);
  __psq_st0(auStack232,(int)((ulonglong)scale2 >> 0x20),0);
  __psq_st1(auStack232,SUB84(scale2,0),0);
  __psq_st0(auStack248,(int)((ulonglong)in_f16 >> 0x20),0);
  __psq_st1(auStack248,(int)in_f16,0);
  __psq_st0(auStack264,(int)((ulonglong)in_f15 >> 0x20),0);
  __psq_st1(auStack264,(int)in_f15,0);
  __psq_st0(auStack280,(int)((ulonglong)in_f14 >> 0x20),0);
  __psq_st1(auStack280,(int)in_f14,0);
  viz = (double)(d_kankyo::g_env_light.mpSunPacket)->mVisibility;
  invDistance = (double)(1_0 - (d_kankyo::g_env_light.mpSunlenzPacket)->mDistFalloff);
  vizSq = (double)(float)(viz * viz);
  if ((double)0_1 <= viz) {
    dKy_set_eyevect_calc2
              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera,&local_248,8000_0,
               8000_0);
    color0 = (_GXColor)0xfffff128;
    color1 = (_GXColor)0xff91491e;
    if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
      mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                        &MStack444);
      gx::GXInitTexObj(&GStack572,*param_4,0x40,0x40,GX_TF_I8,GX_CLAMP,GX_CLAMP,false);
      0_5 = (double)0_0;
      gx::GXInitTexObjLOD(0_5,0_5,0_5,&GStack572,1,1,0,0,0);
      gx::GXLoadTexObj(&GStack572,0);
      gx::GXSetNumChans(0);
      local_278 = color0;
      gx::GXSetTevColor(GX_TEVREG0,&local_278);
      _Stack636 = color1;
      gx::GXSetTevColor(GX_TEVREG1,&_Stack636);
      gx::GXSetNumTexGens(1);
      gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
      gx::GXSetNumTevStages(1);
      gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
      gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C1,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
      gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
      gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
      gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
      gx::GXSetZCompLoc(1);
      gx::GXSetZMode(false,GX_LEQUAL,false);
      gx::GXSetNumIndStages(0);
      gx::GXSetCullMode(0);
      gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
      gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,8);
      gx::GXClearVtxDesc();
      gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
      gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
      mtx::PSMTXRotRad(&MStack492,'Z',_8704 * pdVar11->mAngleDeg);
      mtx::PSMTXConcat(&MStack444,&MStack492,&MStack444);
      gx::GXLoadPosMtxImm(param_1,0);
      gx::GXSetCurrentMtx(0);
      which = 0;
      iVar16 = 0;
      iVar15 = 0;
      0_5 = (double)(0_04 + (float)((double)0_075 * viz));
      dVar19 = (double)(float)(invDistance * invDistance);
      do {
        if (((d_kankyo::g_env_light.mpSunlenzPacket)->mbDrawLenzInSky == false) || (which == 0)) {
          if (which < 2) {
            index = (uint)(vizSq * (double)*(float *)((int)col_dat_8726 + iVar15));
            color0 = (_GXColor)((uint)color0 & 0xffffff00 | index & 0xff);
          }
          else {
            index = (uint)(pdVar11->mDistFalloff *
                          0_8 * (float)(vizSq * (double)*(float *)((int)col_dat_8726 + iVar15)));
            color0 = (_GXColor)((uint)color0 & 0xffffff00 | index & 0xff);
          }
          local_188 = (double)(longlong)(int)index;
          local_280 = color0;
          vizSq_ = vizSq;
          gx::GXSetTevColor(GX_TEVREG0,&local_280);
          if (which < 2) {
            scale = (float)(0_5 * (double)*(float *)((int)&scale_dat_8725 + iVar15)) +
                    (float)((double)(0_2 * (float)(viz * (double)*(float *)((int)&scale_dat_8725 +
                                                                           iVar15))) * dVar19);
          }
          else {
            scale = (1_0 - pdVar11->mDistFalloff) *
                    0_08 * (float)(viz * (double)*(float *)((int)&scale_dat_8725 + iVar15));
          }
          dVar20 = (double)scale;
          if (which == 1) {
            p_Var12 = (_GXTexFmt *)param_4[2];
            gx::GXInitTexObj(&GStack572,p_Var12 + *(int *)(p_Var12 + 0x1c),
                             (uint)*(ushort *)(p_Var12 + 2),(uint)*(ushort *)(p_Var12 + 4),*p_Var12,
                             p_Var12[6],p_Var12[7],SUB41(1 - (uint)p_Var12[0x18] >> 0x1f,0));
            gx::GXLoadTexObj(&GStack572,0);
          }
          else {
            if (which == 2) {
              p_Var12 = (_GXTexFmt *)param_4[1];
              gx::GXInitTexObj(&GStack572,p_Var12 + *(int *)(p_Var12 + 0x1c),
                               (uint)*(ushort *)(p_Var12 + 2),(uint)*(ushort *)(p_Var12 + 4),
                               *p_Var12,p_Var12[6],p_Var12[7],
                               SUB41(1 - (uint)p_Var12[0x18] >> 0x1f,0));
              gx::GXLoadTexObj(&GStack572,0);
            }
          }
          0_6 = -dVar20;
          local_260.x = (float)0_6;
          local_260.y = (float)dVar20;
          local_260.z = 0_0;
          mtx::PSMTXMultVec(&MStack444,&local_260,&local_26c);
          pfVar13 = (float *)((int)&param_2->x + iVar16);
          local_21c.x = local_26c.x + *pfVar13;
          local_21c.y = local_26c.y + pfVar13[1];
          local_21c.z = local_26c.z + pfVar13[2];
          local_260.x = (float)dVar20;
          local_260.y = (float)dVar20;
          local_260.z = 0_0;
          mtx::PSMTXMultVec(&MStack444,&local_260,&local_26c);
          scale = local_26c.x + *pfVar13;
          fVar2 = local_26c.y + pfVar13[1];
          fVar3 = local_26c.z + pfVar13[2];
          local_260.x = (float)dVar20;
          local_260.y = (float)0_6;
          local_260.z = 0_0;
          mtx::PSMTXMultVec(&MStack444,&local_260,&local_26c);
          fVar4 = local_26c.x + *pfVar13;
          fVar5 = local_26c.y + pfVar13[1];
          fVar6 = local_26c.z + pfVar13[2];
          local_260.x = (float)0_6;
          local_260.y = (float)0_6;
          local_260.z = 0_0;
          mtx::PSMTXMultVec(&MStack444,&local_260,&local_26c);
          fVar7 = local_26c.x + *pfVar13;
          fVar8 = local_26c.y + pfVar13[1];
          fVar9 = local_26c.z + pfVar13[2];
          uVar14 = 0x1ff;
          if (which == 0) {
            uVar14 = 0xff;
          }
          gx::GXBegin(0x80,0,4);
          write_volatile_4(0xcc008000,local_21c.x);
          write_volatile_4(0xcc008000,local_21c.y);
          write_volatile_4(0xcc008000,local_21c.z);
          write_volatile_2(0xcc008000,0);
          write_volatile_2(0xcc008000,0);
          write_volatile_4(0xcc008000,scale);
          write_volatile_4(0xcc008000,fVar2);
          write_volatile_4(0xcc008000,fVar3);
          write_volatile_2(0xcc008000,uVar14);
          write_volatile_2(0xcc008000,0);
          write_volatile_4(0xcc008000,fVar4);
          write_volatile_4(0xcc008000,fVar5);
          write_volatile_4(0xcc008000,fVar6);
          write_volatile_2(0xcc008000,uVar14);
          write_volatile_2(0xcc008000,uVar14);
          write_volatile_4(0xcc008000,fVar7);
          write_volatile_4(0xcc008000,fVar8);
          write_volatile_4(0xcc008000,fVar9);
          write_volatile_2(0xcc008000,0);
          write_volatile_2(0xcc008000,uVar14);
        }
        which = which + 1;
        iVar16 = iVar16 + 0xc;
        iVar15 = iVar15 + 4;
      } while (which < 8);
      angle0 = 0xf80a;
      angle1 = 0x416b;
      if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
        mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                          &MStack444);
      }
      mtx::PSMTXRotRad(&MStack492,'Z',0_0);
      mtx::PSMTXConcat(&MStack444,&MStack492,&MStack444);
      gx::GXLoadPosMtxImm(param_1,0);
      gx::GXSetCurrentMtx(0);
      gx::GXSetNumChans(1);
      gx::GXSetChanCtrl(GX_COLOR0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_CLAMP,GX_AF_NONE);
      gx::GXSetNumTexGens(0);
      gx::GXSetNumTevStages(1);
      index = (uint)(80_0 * (float)(vizSq * (double)(float)(vizSq * vizSq)));
      local_188 = (double)(longlong)(int)index;
      color0 = (_GXColor)((uint)color0 & 0xffffff00 | index & 0xff);
      local_284 = color0;
      gx::GXSetTevColor(GX_TEVREG0,&local_284);
      gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
      gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_C0);
      gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A0);
      gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetClipMode(false);
      gx::GXSetNumIndStages(0);
      gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
      gx::GXClearVtxDesc();
      gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
      gx::GXLoadPosMtxImm(param_1,0);
      gx::GXSetCurrentMtx(0);
      index = 0;
      0_6 = (double)0_6;
      scale = (float)(0_6 + (double)(0_8 * (float)(viz * dVar19)));
      dVar20 = (double)(float)((double)1_5 * viz);
      34_0 = (double)34_0;
      0_0 = (double)0_0;
      1600_0 = (double)1600_0;
      0_5 = (double)0_5;
      dVar19 = (double)(300_0 * scale);
      vizSq = (double)0_4;
      invDistance = (double)(960_0 * scale * (float)((double)3_0 + invDistance));
      do {
        if ((index & 1) == 0) {
          uStack380 = (int)angle1 ^ 0x80000000;
          local_180 = 0x43300000;
          base_ = (double)CONCAT44(0x43300000,uStack380);
        }
        else {
          local_188 = (double)CONCAT44(0x43300000,(int)(short)angle0 ^ 0x80000000);
          base_ = local_188;
        }
        base = (double)(float)(base_ - _4175);
        local_178 = (longlong)(int)(34_0 * base);
        arcSize = (double)JKernel::JMath::jmaSinTable
                          [(int)((int)(34_0 * base) & 0xffffU) >>
                           (JKernel::JMath::jmaSinShift & 0x3f)];
        if (arcSize < 0_0) {
          arcSize = -arcSize;
        }
        p2x = (double)(float)(1600_0 * (double)(float)(0_5 + arcSize));
        indexMod4 = (uint)(base + p2x);
        local_170 = (longlong)(int)indexMod4;
        iVar15 = (int)(indexMod4 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
        dVar23 = (double)(float)(dVar19 * (double)JKernel::JMath::jmaSinTable[iVar15]);
        dVar22 = (double)(float)(dVar19 * (double)JKernel::JMath::jmaCosTable[iVar15]);
        indexMod4 = (uint)(base - p2x);
        local_168 = (longlong)(int)indexMod4;
        iVar15 = (int)(indexMod4 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
        p2x = (double)(float)(dVar19 * (double)JKernel::JMath::jmaSinTable[iVar15]);
        base = (double)(float)(dVar19 * (double)JKernel::JMath::jmaCosTable[iVar15]);
                    /* (0.6 + (0.4 * dvar18) * flareScale) * (1.5 * viz) */
        local_260.y = (float)((double)(float)((double)(float)(0_6 + (double)(float)(vizSq * arcSize)
                                                             ) * invDistance) * dVar20);
        indexMod4 = index & 3;
        if (indexMod4 != 0) {
          local_260.y = local_260.y * 0_2;
        }
        uVar1 = (uint)(base_ - _4175);
        local_160 = (longlong)(int)uVar1;
        iVar15 = (int)(uVar1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
        local_260.x = local_260.y * JKernel::JMath::jmaSinTable[iVar15];
        dVar21 = (double)local_260.x;
        local_260.y = local_260.y * JKernel::JMath::jmaCosTable[iVar15];
        arcSize = (double)local_260.y;
        angle0 = angle0 + 0x1000;
        angle1 = angle1 + 0x1c71;
        local_260.z = (float)0_0;
        mtx::PSMTXMultVec(&MStack444,&local_260,&local_26c);
        local_254.x = param_2->x + local_26c.x;
        local_254.y = param_2->y + local_26c.y;
        local_254.z = param_2->z + local_26c.z;
        scale = mtx::PSVECSquareDistance(&local_248,&local_254);
        base_ = (double)scale;
        if (0_0 < base_) {
          dVar18 = 1.0 / SQRT(base_);
          dVar18 = 0_5 * dVar18 * (3_0 - base_ * dVar18 * dVar18);
          dVar18 = 0_5 * dVar18 * (3_0 - base_ * dVar18 * dVar18);
          base_ = (double)(float)(base_ * 0_5 * dVar18 *
                                          (3_0 - base_ * dVar18 * dVar18));
        }
        if ((double)pdVar11->field_0x88 <= base_) {
          if ((double)pdVar11->field_0x8c < base_) {
            pdVar11->field_0x8c = (float)base_;
          }
        }
        else {
          pdVar11->field_0x88 = (float)base_;
        }
        if (indexMod4 == 2) {
          scale2 = (double)0_2;
        }
        else {
          if (indexMod4 < 2) {
            if (indexMod4 == 0) {
              scale2 = (double)0_1;
            }
            else {
              scale2 = (double)1_1;
            }
          }
          else {
            if (indexMod4 < 4) {
              scale2 = (double)0_4;
            }
          }
        }
        base_ = (double)(float)(viz * (double)(float)(vizSq_ + scale2));
        dVar21 = (double)(float)(dVar21 * base_);
        base_ = (double)(float)(arcSize * base_);
        local_260.x = (float)dVar23;
        local_260.y = (float)dVar22;
        local_260.z = (float)0_0;
        mtx::PSMTXMultVec(&MStack444,&local_260,&local_26c);
        local_21c.x = pdVar10->mPos[0].x + local_26c.x;
        local_21c.y = pdVar10->mPos[0].y + local_26c.y;
        local_21c.z = pdVar10->mPos[0].z + local_26c.z;
        local_260.x = (float)dVar21;
        local_260.y = (float)base_;
        local_260.z = (float)0_0;
        mtx::PSMTXMultVec(&MStack444,&local_260,&local_26c);
        scale = pdVar10->mPos[0].x + local_26c.x;
        fVar2 = pdVar10->mPos[0].y + local_26c.y;
        fVar3 = pdVar10->mPos[0].z + local_26c.z;
        local_260.x = (float)p2x;
        local_260.y = (float)base;
        local_260.z = (float)0_0;
        mtx::PSMTXMultVec(&MStack444,&local_260,&local_26c);
        fVar4 = pdVar10->mPos[0].x + local_26c.x;
        fVar5 = pdVar10->mPos[0].y + local_26c.y;
        fVar6 = pdVar10->mPos[0].z + local_26c.z;
        gx::GXBegin(0x80,0,3);
        write_volatile_4(0xcc008000,local_21c.x);
        write_volatile_4(0xcc008000,local_21c.y);
        write_volatile_4(0xcc008000,local_21c.z);
        write_volatile_4(0xcc008000,scale);
        write_volatile_4(0xcc008000,fVar2);
        write_volatile_4(0xcc008000,fVar3);
        write_volatile_4(0xcc008000,fVar4);
        write_volatile_4(0xcc008000,fVar5);
        write_volatile_4(0xcc008000,fVar6);
        index = index + 1;
      } while ((int)index < 0x10);
      _sOldVcdVatCmd = 0;
    }
  }
  __psq_l0(auStack8,uVar17);
  __psq_l1(auStack8,uVar17);
  __psq_l0(auStack24,uVar17);
  __psq_l1(auStack24,uVar17);
  __psq_l0(auStack40,uVar17);
  __psq_l1(auStack40,uVar17);
  __psq_l0(auStack56,uVar17);
  __psq_l1(auStack56,uVar17);
  __psq_l0(auStack72,uVar17);
  __psq_l1(auStack72,uVar17);
  __psq_l0(auStack88,uVar17);
  __psq_l1(auStack88,uVar17);
  __psq_l0(auStack104,uVar17);
  __psq_l1(auStack104,uVar17);
  __psq_l0(auStack120,uVar17);
  __psq_l1(auStack120,uVar17);
  __psq_l0(auStack136,uVar17);
  __psq_l1(auStack136,uVar17);
  __psq_l0(auStack152,uVar17);
  __psq_l1(auStack152,uVar17);
  __psq_l0(auStack168,uVar17);
  __psq_l1(auStack168,uVar17);
  __psq_l0(auStack184,uVar17);
  __psq_l1(auStack184,uVar17);
  __psq_l0(auStack200,uVar17);
  __psq_l1(auStack200,uVar17);
  __psq_l0(auStack216,uVar17);
  __psq_l1(auStack216,uVar17);
  __psq_l0(auStack232,uVar17);
  __psq_l1(auStack232,uVar17);
  __psq_l0(auStack248,uVar17);
  __psq_l1(auStack248,uVar17);
  __psq_l0(auStack264,uVar17);
  __psq_l1(auStack264,uVar17);
  __psq_l0(auStack280,uVar17);
  __psq_l1(auStack280,uVar17);
  return;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* WARNING: Removing unreachable block (ram,0x80096804) */
/* WARNING: Removing unreachable block (ram,0x800967f4) */
/* WARNING: Removing unreachable block (ram,0x800967e4) */
/* WARNING: Removing unreachable block (ram,0x800967d4) */
/* WARNING: Removing unreachable block (ram,0x800967c4) */
/* WARNING: Removing unreachable block (ram,0x800967b4) */
/* WARNING: Removing unreachable block (ram,0x800967ac) */
/* WARNING: Removing unreachable block (ram,0x800967bc) */
/* WARNING: Removing unreachable block (ram,0x800967cc) */
/* WARNING: Removing unreachable block (ram,0x800967dc) */
/* WARNING: Removing unreachable block (ram,0x800967ec) */
/* WARNING: Removing unreachable block (ram,0x800967fc) */
/* WARNING: Removing unreachable block (ram,0x8009680c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dKyr_drawRain(float *[][][][],
                           unsigned char * *) */

void dKyr_drawRain(MTX34 *param_1,void **param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  dKankyo_rain_Packet *pEff;
  int iVar8;
  int iVar9;
  int iVar10;
  uint idx;
  undefined4 uVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  undefined8 in_f19;
  undefined8 in_f20;
  undefined8 in_f21;
  double dVar17;
  undefined8 in_f22;
  double dVar18;
  undefined8 in_f23;
  double dVar19;
  undefined8 in_f24;
  double 0_0;
  undefined8 in_f25;
  double dVar20;
  undefined8 in_f26;
  double dVar21;
  undefined8 in_f27;
  double dVar22;
  undefined8 in_f28;
  double dVar23;
  undefined8 in_f29;
  double dVar24;
  undefined8 in_f30;
  double dVar25;
  undefined8 in_f31;
  double dVar26;
  float fVar27;
  _GXColor local_264;
  _GXColor local_260;
  _GXColor local_25c;
  _GXColor local_258;
  _GXColor local_254;
  float local_250;
  float local_24c;
  float local_248;
  float local_244;
  float local_240;
  float local_23c;
  float local_238;
  float local_234;
  float local_230;
  float local_22c;
  float local_228;
  float local_224;
  cXyz windVec;
  cXyz pos;
  cXyz local_208;
  cXyz basePos;
  TVec3_float_ extents;
  TVec3_float_ worldPos;
  GXTexObj GStack460;
  MTX34 MStack428;
  cXyz p0;
  MTX34 mtx;
  double idxF;
  undefined4 uStack272;
  uint idx7;
  undefined4 local_108;
  uint uStack260;
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  float _2_0;
  float 0_0_;
  uint alpha;
  float baseSpeed;
  camera_class *pCam;
  dKankyo_rain_Packet *pPkt;
  
  pPkt = d_kankyo::g_env_light.mpRainPacket;
  pCam = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar11 = 0;
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
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  d_kankyo_wether::dKyw_get_wind_vecpow(&windVec);
  _2_0 = _2_0;
  0_0_ = 0_0;
  if (init_9000 == '\0') {
    rot_8999 = 0;
    init_9000 = '\x01';
  }
  if ((d_kankyo::g_env_light.mSnowCount == 0) && (pPkt->mRainCount != 0)) {
    local_254 = (_GXColor)0xffffff0a;
    local_258 = (_GXColor)0x8080800a;
    if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
      ::mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                          &mtx);
      gx::GXInitTexObj(&GStack460,*param_2,0x40,0x40,GX_TF_I8,GX_CLAMP,GX_CLAMP,false);
      0_0 = (double)0_0;
      gx::GXInitTexObjLOD(0_0,0_0,0_0,&GStack460,1,1,0,0,0);
      gx::GXLoadTexObj(&GStack460,0);
      gx::GXSetNumChans(0);
      local_25c = local_254;
      gx::GXSetTevColor(GX_TEVREG0,&local_25c);
      local_260 = local_258;
      gx::GXSetTevColor(GX_TEVREG1,&local_260);
      gx::GXSetNumTexGens(1);
      gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
      gx::GXSetNumTevStages(1);
      gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
      gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C1,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
      gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
      gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
      gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
      gx::GXSetZMode(true,GX_LEQUAL,false);
      gx::GXSetCullMode(0);
      gx::GXSetClipMode(true);
      gx::GXSetNumIndStages(0);
      gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
      gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,8);
      gx::GXClearVtxDesc();
      gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
      gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
      idxF = (double)CONCAT44(0x43300000,rot_8999);
      ::mtx::PSMTXRotRad(&MStack428,'Z',_8704 * (float)(idxF - _8317));
      ::mtx::PSMTXConcat(&mtx,&MStack428,&mtx);
      gx::GXLoadPosMtxImm(param_1,0);
      gx::GXSetCurrentMtx(0);
      iVar9 = 0;
      0_0 = (double)0_0;
      for (idx = 0; (int)idx < (int)pPkt->mRainCount; idx = idx + 1) {
        pEff = (dKankyo_rain_Packet *)((int)pPkt->mRainEff + iVar9 + -0x18);
        dVar13 = (double)pEff->mRainEff[0].mAlpha;
        if (0_0 < dVar13) {
          alpha = (uint)((double)14_0 * dVar13);
          idxF = (double)(longlong)(int)alpha;
          local_254 = (_GXColor)((uint)local_254 & 0xffffff00 | alpha & 0xff);
          local_264 = local_254;
          gx::GXSetTevColor(GX_TEVREG0,&local_264);
          basePos.x = pEff->mRainEff[0].mBasePos.x + pEff->mRainEff[0].mPos.x;
          basePos.y = pEff->mRainEff[0].mBasePos.y + pEff->mRainEff[0].mPos.y;
          basePos.z = pEff->mRainEff[0].mBasePos.z + pEff->mRainEff[0].mPos.z;
          fVar27 = ::mtx::PSVECSquareDistance(&basePos,&pCam->mEyePos);
          dVar13 = (double)fVar27;
          if ((double)0_0 < dVar13) {
            dVar12 = 1.0 / SQRT(dVar13);
            dVar12 = 0_5 * dVar12 * (3_0 - dVar13 * dVar12 * dVar12);
            dVar12 = 0_5 * dVar12 * (3_0 - dVar13 * dVar12 * dVar12);
            dVar13 = (double)(float)(dVar13 * 0_5 * dVar12 * (3_0 - dVar13 * dVar12 * dVar12));
          }
          fVar27 = 0_1 + (float)(dVar13 / (double)1500_0);
          if (1_0 < fVar27) {
            fVar27 = 1_0;
          }
          idxF = (double)CONCAT44(0x43300000,idx ^ 0x80000000);
          dVar13 = (double)(2_5 + (float)(idxF - _4175) / 250_0);
          baseSpeed = 5_0 + 70_0 * fVar27;
          fVar27 = pPkt->mCenterDeltaMul;
          idx7 = idx & 7 ^ 0x80000000;
          uStack272 = 0x43300000;
          fVar1 = baseSpeed *
                  (windVec.x + 10_0 * (pPkt->mCenterDelta).x * fVar27 +
                  0_0_ + 0_08 * (float)((double)CONCAT44(0x43300000,idx7) - _4175));
          fVar2 = baseSpeed * (_2_0 + windVec.y + (pPkt->mCenterDelta).y * fVar27);
          uStack260 = idx & 3 ^ 0x80000000;
          local_108 = 0x43300000;
          baseSpeed = baseSpeed *
                      (windVec.z + 10_0 * (pPkt->mCenterDelta).z * fVar27 +
                      0_0_ + 0_08 * (float)((double)CONCAT44(0x43300000,uStack260) - _4175));
          worldPos.x = (float)(-dVar13 * (double)_1_0);
          dVar12 = (double)worldPos.x;
          worldPos.y = 0_0;
          worldPos.z = 0_0;
          ::mtx::PSMTXMultVec(&mtx,(cXyz *)&worldPos,(cXyz *)&extents);
          p0.x = (basePos.x + extents.x) - fVar1;
          p0.y = (basePos.y + extents.y) - fVar2;
          p0.z = (basePos.z + extents.z) - baseSpeed;
          worldPos.x = (float)(dVar13 * (double)_1_0);
          dVar13 = (double)worldPos.x;
          worldPos.y = 0_0;
          worldPos.z = 0_0;
          ::mtx::PSMTXMultVec(&mtx,(cXyz *)&worldPos,(cXyz *)&extents);
          fVar27 = basePos.x + extents.x;
          fVar3 = basePos.y + extents.y;
          fVar4 = basePos.z + extents.z;
          worldPos.x = (float)dVar13;
          worldPos.y = 0_0;
          worldPos.z = 0_0;
          ::mtx::PSMTXMultVec(&mtx,(cXyz *)&worldPos,(cXyz *)&extents);
          fVar5 = basePos.x + extents.x;
          fVar6 = basePos.y + extents.y;
          fVar7 = basePos.z + extents.z;
          worldPos.x = (float)dVar12;
          worldPos.y = 0_0;
          worldPos.z = 0_0;
          ::mtx::PSMTXMultVec(&mtx,(cXyz *)&worldPos,(cXyz *)&extents);
          iVar10 = 0;
          iVar8 = 0;
          dVar20 = (double)p0.x;
          dVar21 = (double)p0.y;
          dVar22 = (double)p0.z;
          dVar23 = (double)(fVar27 - fVar1);
          dVar24 = (double)(fVar3 - fVar2);
          dVar25 = (double)(fVar4 - baseSpeed);
          dVar26 = (double)fVar5;
          dVar13 = (double)fVar6;
          dVar12 = (double)fVar7;
          dVar17 = (double)(basePos.x + extents.x);
          dVar18 = (double)(basePos.y + extents.y);
          dVar19 = (double)(basePos.z + extents.z);
          do {
            if (init_9026 == '\0') {
              local_22c = 150_0;
              local_228 = 0_0;
              local_224 = 0_0;
              add_table_9024[0].x = 150_0;
              add_table_9024[0].y = 0_0;
              add_table_9024[0].z = 0_0;
              Runtime.PPCEABI.H::__register_global_object(add_table_9024,::cXyz::_cXyz,&_9025);
              local_238 = 0_0;
              local_234 = 150_0;
              local_230 = 150_0;
              add_table_9024[1].x = 0_0;
              add_table_9024[1].y = 150_0;
              add_table_9024[1].z = 150_0;
              Runtime.PPCEABI.H::__register_global_object(0x803e23a0,::cXyz::_cXyz,&_9028);
              local_244 = 150_0;
              local_240 = 320_0;
              local_23c = 150_0;
              add_table_9024[2].x = 150_0;
              add_table_9024[2].y = 320_0;
              add_table_9024[2].z = 150_0;
              Runtime.PPCEABI.H::__register_global_object(0x803e23ac,::cXyz::_cXyz,&_9029);
              local_250 = 45_0;
              local_24c = 480_0;
              local_248 = 45_0;
              add_table_9024[3].x = 45_0;
              add_table_9024[3].y = 480_0;
              add_table_9024[3].z = 45_0;
              Runtime.PPCEABI.H::__register_global_object(0x803e23b8,::cXyz::_cXyz,&_9030);
              init_9026 = '\x01';
            }
            gx::GXBegin(0x80,0,4);
            dVar14 = (double)*(float *)((int)&add_table_9024[0].x + iVar8);
            write_volatile_4(0xcc008000,(float)(dVar20 + dVar14));
            dVar15 = (double)*(float *)((int)&add_table_9024[0].y + iVar8);
            write_volatile_4(0xcc008000,(float)(dVar21 + dVar15));
            dVar16 = (double)*(float *)((int)&add_table_9024[0].z + iVar8);
            write_volatile_4(0xcc008000,(float)(dVar22 + dVar16));
            write_volatile_2(0xcc008000,0);
            write_volatile_2(0xcc008000,0);
            write_volatile_4(0xcc008000,(float)(dVar23 + dVar14));
            write_volatile_4(0xcc008000,(float)(dVar24 + dVar15));
            write_volatile_4(0xcc008000,(float)(dVar25 + dVar16));
            write_volatile_2(0xcc008000,0xff);
            write_volatile_2(0xcc008000,0);
            write_volatile_4(0xcc008000,(float)(dVar26 + dVar14));
            write_volatile_4(0xcc008000,(float)(dVar13 + dVar15));
            write_volatile_4(0xcc008000,(float)(dVar12 + dVar16));
            write_volatile_2(0xcc008000,0xff);
            write_volatile_2(0xcc008000,0xff);
            write_volatile_4(0xcc008000,(float)(dVar17 + dVar14));
            write_volatile_4(0xcc008000,(float)(dVar18 + dVar15));
            write_volatile_4(0xcc008000,(float)(dVar19 + dVar16));
            write_volatile_2(0xcc008000,0);
            write_volatile_2(0xcc008000,0xff);
            iVar10 = iVar10 + 1;
            iVar8 = iVar8 + 0xc;
          } while (iVar10 < 4);
        }
        iVar9 = iVar9 + 0x38;
      }
      gx::GXSetClipMode(false);
      _sOldVcdVatCmd = 0;
    }
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  __psq_l0(auStack40,uVar11);
  __psq_l1(auStack40,uVar11);
  __psq_l0(auStack56,uVar11);
  __psq_l1(auStack56,uVar11);
  __psq_l0(auStack72,uVar11);
  __psq_l1(auStack72,uVar11);
  __psq_l0(auStack88,uVar11);
  __psq_l1(auStack88,uVar11);
  __psq_l0(auStack104,uVar11);
  __psq_l1(auStack104,uVar11);
  __psq_l0(auStack120,uVar11);
  __psq_l1(auStack120,uVar11);
  __psq_l0(auStack136,uVar11);
  __psq_l1(auStack136,uVar11);
  __psq_l0(auStack152,uVar11);
  __psq_l1(auStack152,uVar11);
  __psq_l0(auStack168,uVar11);
  __psq_l1(auStack168,uVar11);
  __psq_l0(auStack184,uVar11);
  __psq_l1(auStack184,uVar11);
  __psq_l0(auStack200,uVar11);
  __psq_l1(auStack200,uVar11);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80096cf0) */
/* WARNING: Removing unreachable block (ram,0x80096ce0) */
/* WARNING: Removing unreachable block (ram,0x80096cd8) */
/* WARNING: Removing unreachable block (ram,0x80096ce8) */
/* WARNING: Removing unreachable block (ram,0x80096cf8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dKyr_drawSibuki(float *[][][][],
                             unsigned char * *) */

void dKyr_drawSibuki(MTX34 *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  _GXTexFmt *p_Var6;
  int iVar7;
  undefined4 uVar8;
  double dVar9;
  double dVar10;
  undefined8 in_f27;
  double dVar11;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar12;
  undefined8 in_f31;
  double dVar13;
  float fVar14;
  _GXColor local_128;
  _GXColor local_124;
  _GXColor local_120;
  float local_11c;
  float local_118;
  float local_114;
  cXyz cStack272;
  cXyz local_104;
  GXTexObj GStack248;
  cXyz local_d8;
  undefined auStack168 [48];
  longlong local_78;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  camera_class *pCam;
  dKankyo_rain_Packet *pPkt;
  
  pPkt = d_kankyo::g_env_light.mpRainPacket;
  pCam = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar8 = 0;
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
  if ((d_kankyo::g_env_light.mSnowCount == 0) &&
     (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0)) {
    mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                      auStack168);
    fVar14 = 200_0;
    if ((pPkt->mStatus & 1) != 0) {
      fVar14 = 0_0;
    }
    SComponent::cLib_addCalc(&pPkt->mSibukiAlpha,fVar14,0_2,30_0,0_001);
    dKy_set_eyevect_calc(pCam,&local_104,(double)7000_0,(double)4000_0);
    dKyr_get_vectle_calc(&pCam->mEyePos,&pCam->mCenterPos,&cStack272);
    fVar14 = 1_0;
    if ((0_0 < cStack272.y) && (fVar14 = 0_0, cStack272.y < 0_5)) {
      fVar14 = 1_0 - cStack272.y / 0_5;
    }
    uVar3 = (uint)(pPkt->mSibukiAlpha * fVar14);
    local_78 = (longlong)(int)uVar3;
    local_120 = (_GXColor)(uVar3 & 0xff | 0xb4c8c800);
    p_Var6 = *(_GXTexFmt **)(param_2 + 4);
    gx::GXInitTexObj(&GStack248,p_Var6 + *(int *)(p_Var6 + 0x1c),(uint)*(ushort *)(p_Var6 + 2),
                     (uint)*(ushort *)(p_Var6 + 4),*p_Var6,p_Var6[6],p_Var6[7],
                     SUB41(1 - (uint)p_Var6[0x18] >> 0x1f,0));
    gx::GXLoadTexObj(&GStack248,0);
    gx::GXSetNumChans(0);
    local_124 = local_120;
    gx::GXSetTevColor(GX_TEVREG0,&local_124);
    local_128 = local_120;
    gx::GXSetTevColor(GX_TEVREG1,&local_128);
    gx::GXSetNumTexGens(1);
    gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
    gx::GXSetNumTevStages(1);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C1,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
    gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
    gx::GXSetZMode(true,GX_GEQUAL,false);
    gx::GXSetCullMode(0);
    gx::GXSetClipMode(true);
    gx::GXSetNumIndStages(0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,8);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
    gx::GXLoadPosMtxImm(param_1,0);
    gx::GXSetCurrentMtx(0);
    fVar14 = 0_2;
    if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
      fVar14 = (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mFovY / 20_0;
      if (1_0 <= fVar14) {
        fVar14 = 1_0;
      }
      fVar14 = 1_0 - fVar14;
    }
    dVar12 = (double)fVar14;
    dVar13 = (double)20_0;
    for (iVar7 = 0; iVar7 < d_kankyo::g_env_light.mRainCount >> 1; iVar7 = iVar7 + 1) {
      fVar14 = SComponent::cM_rndF(25_0);
      dVar11 = (double)(float)(dVar13 + (double)(float)(dVar12 * (double)fVar14));
      fVar14 = SComponent::cM_rndFX(3600_0);
      dVar9 = (double)fVar14;
      fVar14 = SComponent::cM_rndFX(1500_0);
      dVar10 = (double)fVar14;
      local_114 = SComponent::cM_rndFX(3600_0);
      local_11c = (float)((double)local_104.x + dVar9);
      fVar14 = (float)((double)local_104.y + dVar10);
      local_114 = local_104.z + local_114;
      fVar4 = (float)((double)local_11c - dVar11);
      fVar5 = (float)((double)local_114 - dVar11);
      fVar1 = (float)((double)local_11c + dVar11);
      fVar2 = (float)((double)local_114 + dVar11);
      local_118 = fVar14;
      local_d8.x = fVar4;
      local_d8.y = fVar14;
      local_d8.z = fVar5;
      gx::GXBegin(0x80,0,4);
      write_volatile_4(0xcc008000,local_d8.x);
      write_volatile_4(0xcc008000,local_d8.y);
      write_volatile_4(0xcc008000,local_d8.z);
      write_volatile_2(0xcc008000,0);
      write_volatile_2(0xcc008000,0);
      write_volatile_4(0xcc008000,fVar1);
      write_volatile_4(0xcc008000,fVar14);
      write_volatile_4(0xcc008000,fVar5);
      write_volatile_2(0xcc008000,0x1ff);
      write_volatile_2(0xcc008000,0);
      write_volatile_4(0xcc008000,fVar1);
      write_volatile_4(0xcc008000,fVar14);
      write_volatile_4(0xcc008000,fVar2);
      write_volatile_2(0xcc008000,0x1ff);
      write_volatile_2(0xcc008000,0x1ff);
      write_volatile_4(0xcc008000,fVar4);
      write_volatile_4(0xcc008000,fVar14);
      write_volatile_4(0xcc008000,fVar2);
      write_volatile_2(0xcc008000,0);
      write_volatile_2(0xcc008000,0x1ff);
    }
    gx::GXSetClipMode(false);
    _sOldVcdVatCmd = 0;
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  __psq_l0(auStack40,uVar8);
  __psq_l1(auStack40,uVar8);
  __psq_l0(auStack56,uVar8);
  __psq_l1(auStack56,uVar8);
  __psq_l0(auStack72,uVar8);
  __psq_l1(auStack72,uVar8);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x800973a4) */
/* WARNING: Removing unreachable block (ram,0x8009739c) */
/* WARNING: Removing unreachable block (ram,0x800973ac) */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall drawPoison(float *[][][][],
                        unsigned char * *) */

void drawPoison(MTX34 *param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined8 in_f29;
  double dVar13;
  undefined8 in_f30;
  double dVar14;
  undefined8 in_f31;
  double dVar15;
  _GXColor local_198;
  _GXColor local_194;
  _GXColor local_190;
  _GXColor local_18c;
  undefined4 local_188;
  undefined4 local_184;
  float local_180;
  float local_17c;
  float local_178;
  cXyz local_174;
  cXyz local_168;
  GXTexObj GStack348;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  MTX34 MStack268;
  MTX34 MStack220;
  undefined4 local_a8;
  uint uStack164;
  undefined4 local_a0;
  uint uStack156;
  longlong local_98;
  longlong local_90;
  longlong local_88;
  longlong local_80;
  longlong local_78;
  longlong local_70;
  longlong local_68;
  longlong local_60;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  iVar7 = d_kankyo::g_env_light._2540_4_;
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if (init_9396 == '\0') {
    rot_9395 = 0_0;
    init_9396 = '\x01';
  }
  J3DSys::reinitGX(&J3DGraphBase::j3dSys);
  if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
    mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                      &MStack220);
    local_184 = (_GXColor)CONCAT13(0x2d,CONCAT12(0x88,local_184._2_2_));
    local_184._2_2_ = CONCAT11(0xaa,(undefined)local_184);
    local_184 = (_GXColor)((uint)local_184 & 0xffff0000 | (uint)local_184._2_2_);
    local_188 = (_GXColor)CONCAT13(0x6d,CONCAT12(0x3c,local_188._2_2_));
    local_188._2_2_ = CONCAT11(0xcd,(undefined)local_188);
    local_188 = (_GXColor)((uint)local_188 & 0xffff0000 | (uint)local_188._2_2_);
    dKyr_set_btitex(&GStack348,*param_2);
    gx::GXSetNumChans(0);
    local_18c = local_184;
    gx::GXSetTevColor(GX_TEVREG0,&local_18c);
    local_190 = local_188;
    gx::GXSetTevColor(GX_TEVREG1,&local_190);
    gx::GXSetNumTexGens(1);
    gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
    gx::GXSetNumTevStages(1);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C1,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    d_kankyo::dKy_GxFog_set();
    gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
    gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
    gx::GXSetZMode(true,GX_LEQUAL,false);
    gx::GXSetCullMode(0);
    gx::GXSetNumIndStages(0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,8);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
    mtx::PSMTXRotRad(&MStack268,'Z',_8704 * rot_9395);
    mtx::PSMTXConcat(&MStack220,&MStack268,&MStack220);
    gx::GXLoadPosMtxImm(param_1,0);
    rot_9395 = rot_9395 + _9534;
    if (rot_9395 < 0_0) {
      rot_9395 = 719_0;
    }
    gx::GXSetCurrentMtx(0);
    uVar9 = 0;
    iVar8 = 0;
    dVar15 = (double)1_0E_6;
    for (iVar10 = 0; iVar10 < d_kankyo::g_env_light._2536_4_; iVar10 = iVar10 + 1) {
      iVar11 = iVar7 + iVar8;
      dVar13 = (double)*(float *)(iVar11 + 0x38);
      if (dVar15 < (double)*(float *)(iVar11 + 0x34)) {
        gx::GXLoadTexObj(&GStack348,0);
        uStack164 = *(uint *)(d_kankyo::g_env_light._2540_4_ + 0xbba8) ^ 0x80000000;
        local_a8 = 0x43300000;
        uStack156 = uVar9 ^ 0x80000000;
        local_a0 = 0x43300000;
        uVar1 = (uint)(500_0 * (float)((double)CONCAT44(0x43300000,uStack164) - _4175) +
                      (float)((double)CONCAT44(0x43300000,uStack156) - _4175));
        local_98 = (longlong)(int)uVar1;
        fVar5 = ABS(JKernel::JMath::jmaCosTable
                    [(int)(uVar1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]) *
                ABS(JKernel::JMath::jmaCosTable
                    [(int)(uVar1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]);
        fVar6 = fVar5 * _8707;
        local_90 = (longlong)(int)(_9536 + fVar6);
        local_88 = (longlong)(int)(_9537 + fVar6);
        iVar2 = (int)(_9538 + fVar5 * _9539);
        local_80 = (longlong)iVar2;
        iVar3 = (int)(_9540 + fVar5 * _9541);
        local_78 = (longlong)iVar3;
        iVar4 = (int)(_9542 + fVar5 * _9543);
        local_70 = (longlong)iVar4;
        local_68 = (longlong)(int)(255_0 + fVar6);
        local_188._2_2_ = SUB42(local_188,0) & 0xff | (ushort)(byte)(int)(255_0 + fVar6) << 8;
        local_188 = (_GXColor)
                    (iVar3 << 0x18 | CONCAT12((char)iVar4,SUB42(local_188,0)) & 0xffff0000 |
                    (uint)local_188._2_2_);
        uVar1 = (uint)(255_0 * *(float *)(iVar11 + 0x34));
        local_60 = (longlong)(int)uVar1;
        local_184 = (_GXColor)
                    (uVar1 & 0xff |
                    (uint)CONCAT21(CONCAT11((char)(int)(_9536 + fVar6),(char)(int)(_9537 + fVar6)),
                                   (char)iVar2) << 8);
        local_194 = local_184;
        gx::GXSetTevColor(GX_TEVREG0,&local_194);
        local_198 = local_188;
        gx::GXSetTevColor(GX_TEVREG1,&local_198);
        local_180 = *(float *)(iVar7 + 0xbb90) + *(float *)(iVar11 + 0x14);
        local_17c = *(float *)(iVar7 + 0xbb94) + *(float *)(iVar11 + 0x18);
        local_178 = *(float *)(iVar7 + 0xbb98) + *(float *)(iVar11 + 0x1c);
        dVar14 = -dVar13;
        local_168.x = (float)dVar14;
        local_168.y = (float)dVar13;
        local_168.z = 0_0;
        mtx::PSMTXMultVec(&MStack220,&local_168,&local_174);
        local_13c = local_180 + local_174.x;
        local_138 = local_17c + local_174.y;
        local_134 = local_178 + local_174.z;
        local_168.x = (float)dVar13;
        local_168.y = (float)dVar13;
        local_168.z = 0_0;
        mtx::PSMTXMultVec(&MStack220,&local_168,&local_174);
        local_130 = local_180 + local_174.x;
        local_12c = local_17c + local_174.y;
        local_128 = local_178 + local_174.z;
        local_168.x = (float)dVar13;
        local_168.y = (float)dVar14;
        local_168.z = 0_0;
        mtx::PSMTXMultVec(&MStack220,&local_168,&local_174);
        local_124 = local_180 + local_174.x;
        local_120 = local_17c + local_174.y;
        local_11c = local_178 + local_174.z;
        local_168.x = (float)dVar14;
        local_168.y = (float)dVar14;
        local_168.z = 0_0;
        mtx::PSMTXMultVec(&MStack220,&local_168,&local_174);
        local_118 = local_180 + local_174.x;
        local_114 = local_17c + local_174.y;
        local_110 = local_178 + local_174.z;
        gx::GXBegin(0x80,0,4);
        write_volatile_4(0xcc008000,local_13c);
        write_volatile_4(0xcc008000,local_138);
        write_volatile_4(0xcc008000,local_134);
        write_volatile_2(0xcc008000,0);
        write_volatile_2(0xcc008000,0);
        write_volatile_4(0xcc008000,local_130);
        write_volatile_4(0xcc008000,local_12c);
        write_volatile_4(0xcc008000,local_128);
        write_volatile_2(0xcc008000,0xff);
        write_volatile_2(0xcc008000,0);
        write_volatile_4(0xcc008000,local_124);
        write_volatile_4(0xcc008000,local_120);
        write_volatile_4(0xcc008000,local_11c);
        write_volatile_2(0xcc008000,0xff);
        write_volatile_2(0xcc008000,0xff);
        write_volatile_4(0xcc008000,local_118);
        write_volatile_4(0xcc008000,local_114);
        write_volatile_4(0xcc008000,local_110);
        write_volatile_2(0xcc008000,0);
        write_volatile_2(0xcc008000,0xff);
      }
      uVar9 = uVar9 + 4000;
      iVar8 = iVar8 + 0x30;
    }
    gx::GXSetClipMode(false);
    _sOldVcdVatCmd = 0;
  }
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  __psq_l0(auStack40,uVar12);
  __psq_l1(auStack40,uVar12);
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x80097aa8) */
/* WARNING: Removing unreachable block (ram,0x80097a98) */
/* WARNING: Removing unreachable block (ram,0x80097a88) */
/* WARNING: Removing unreachable block (ram,0x80097a90) */
/* WARNING: Removing unreachable block (ram,0x80097aa0) */
/* WARNING: Removing unreachable block (ram,0x80097ab0) */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dKyr_drawHousi(float *[][][][],
                            unsigned char * *) */

void dKyr_drawHousi(MTX34 *param_1,char *pTex)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  uint scale;
  int iVar12;
  int i;
  int which;
  dKankyo_housi_Packet *pEff;
  undefined4 uVar13;
  undefined8 in_f26;
  double scaleX;
  undefined8 in_f27;
  double scaleY;
  undefined8 in_f28;
  double dVar14;
  undefined8 in_f29;
  double dVar15;
  undefined8 in_f30;
  double dVar16;
  undefined8 in_f31;
  double dVar17;
  _GXColor reg0;
  _GXColor local_184;
  _GXColor local_180;
  _GXColor local_17c;
  undefined4 local_178;
  undefined4 local_174;
  TVec3_float_ ret;
  TVec3_float_ in;
  cXyz local_158;
  GXTexObj texObj;
  cXyz p0;
  MTX34 rotMtx;
  MTX34 mtx;
  double local_98;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  dKankyo_housi_Packet *pPkt;
  daPy_lk_c *pPlayer;
  float posY;
  
  pPkt = d_kankyo::g_env_light.mpHousiPacket;
  uVar13 = 0;
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
  if (init_9558 == '\0') {
    rot_9557 = 0;
    init_9558 = '\x01';
  }
  if ((d_kankyo::g_env_light.mpHousiPacket)->mCount != 0) {
    local_174 = (_GXColor)((int)255_0 & 0xffU | 0xe5ffc800);
    local_178 = (_GXColor)0x43d2caff;
    if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
      ::mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                          &mtx);
      which = 0;
      dVar15 = -(double)3_0;
      dVar16 = (double)_8704;
      dVar17 = _8317;
      do {
        dKyr_set_btitex(&texObj,*(undefined4 *)pTex);
        gx::GXSetNumChans(0);
        local_17c = local_174;
        gx::GXSetTevColor(GX_TEVREG0,&local_17c);
        local_180 = local_178;
        gx::GXSetTevColor(GX_TEVREG1,&local_180);
        gx::GXSetNumTexGens(1);
        gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
        gx::GXSetNumTevStages(1);
        gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
        gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C1,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
        gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
        gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
        gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
        if (which == 1) {
          gx::GXSetZMode(true,GX_GEQUAL,false);
        }
        else {
          gx::GXSetZMode(true,GX_LEQUAL,false);
        }
        gx::GXSetCullMode(0);
        gx::GXSetClipMode(true);
        gx::GXSetNumIndStages(0);
        gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
        gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,8);
        gx::GXClearVtxDesc();
        gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
        gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
        local_98 = (double)CONCAT44(0x43300000,rot_9557);
        ::mtx::PSMTXRotRad(&rotMtx,'Z',(float)(dVar16 * (double)(float)(local_98 - dVar17)));
        ::mtx::PSMTXConcat(&mtx,&rotMtx,&mtx);
        gx::GXLoadPosMtxImm(param_1,0);
        gx::GXSetCurrentMtx(0);
        iVar12 = 0;
        for (i = 0; pPlayer = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor,
            i < pPkt->mCount; i = i + 1) {
          pEff = (dKankyo_housi_Packet *)((int)pPkt->mEff + iVar12 + -0x14);
          fVar2 = pEff->mEff[0].mBasePos.x + pEff->mEff[0].mPos.x;
          local_158.y = pEff->mEff[0].mBasePos.y + pEff->mEff[0].mPos.y;
          fVar11 = pEff->mEff[0].mBasePos.z + pEff->mEff[0].mPos.z;
          if ((which == 1) && (i == 0)) {
            local_174 = (_GXColor)(uint)(SUB42(local_174,0) & 0xff);
            local_178 = (_GXColor)(uint)(SUB42(local_178,0) & 0xff);
            local_184 = local_178;
            gx::GXSetTevColor(GX_TEVREG1,&local_184);
          }
          if (which == 1) {
            posY = (pPlayer->parent).parent.mCurrent.mPos.y;
            if (((local_158.y <= posY + 100_0) && (posY - 20_0 <= local_158.y)) &&
               (fVar1 = pEff->mEff[0].mAlpha, 0_0 < fVar1)) {
              local_174 = (_GXColor)
                          ((uint)local_174 & 0xffffff00 |
                          (int)(40_0 * fVar1 * (1_0 - (local_158.y - posY) / 100_0)) & 0xffU);
              local_158.y = posY - 20_0;
              goto LAB_800977dc;
            }
          }
          else {
            local_174 = (_GXColor)
                        ((uint)local_174 & 0xffffff00 | (int)(pEff->mEff[0].mAlpha * 255_0) & 0xffU)
            ;
LAB_800977dc:
            gx::GXLoadTexObj(&texObj,0);
            reg0 = local_174;
            gx::GXSetTevColor(GX_TEVREG0,&reg0);
            scale = SComponent::cM_rad2s((double)(10_0 * pEff->mEff[0].mScale.x));
            scaleY = (double)(0_22 * JKernel::JMath::jmaSinTable
                                     [(int)(scale & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]
                             );
            scale = SComponent::cM_rad2s((double)(10_0 * pEff->mEff[0].mScale.y));
            scaleX = (double)(0_22 * JKernel::JMath::jmaSinTable
                                     [(int)(scale & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]
                             );
            in.x = (float)((double)3_0 - scaleX);
            dVar14 = (double)in.x;
            in.y = (float)((double)3_0 - scaleY);
            in.z = 0_0;
            ::mtx::PSMTXMultVec(&mtx,(cXyz *)&in,(cXyz *)&ret);
            posY = fVar2 + ret.x;
            fVar1 = local_158.y + ret.y;
            fVar3 = fVar11 + ret.z;
            in.x = (float)(dVar15 + scaleX);
            scaleX = (double)in.x;
            in.y = (float)((double)3_0 + scaleY);
            in.z = 0_0;
            ::mtx::PSMTXMultVec(&mtx,(cXyz *)&in,(cXyz *)&ret);
            fVar4 = fVar2 + ret.x;
            fVar5 = local_158.y + ret.y;
            fVar6 = fVar11 + ret.z;
            in.x = (float)scaleX;
            in.y = (float)(dVar15 + scaleY);
            in.z = 0_0;
            ::mtx::PSMTXMultVec(&mtx,(cXyz *)&in,(cXyz *)&ret);
            fVar7 = fVar2 + ret.x;
            fVar8 = local_158.y + ret.y;
            fVar9 = fVar11 + ret.z;
            in.x = (float)dVar14;
            in.y = (float)(dVar15 - scaleY);
            in.z = 0_0;
            ::mtx::PSMTXMultVec(&mtx,(cXyz *)&in,(cXyz *)&ret);
            fVar2 = fVar2 + ret.x;
            fVar10 = local_158.y + ret.y;
            fVar11 = fVar11 + ret.z;
            gx::GXBegin(0x80,0,4);
            write_volatile_4(0xcc008000,posY);
            write_volatile_4(0xcc008000,fVar1);
            write_volatile_4(0xcc008000,fVar3);
            write_volatile_2(0xcc008000,0);
            write_volatile_2(0xcc008000,0);
            write_volatile_4(0xcc008000,fVar4);
            write_volatile_4(0xcc008000,fVar5);
            write_volatile_4(0xcc008000,fVar6);
            write_volatile_2(0xcc008000,0x1ff);
            write_volatile_2(0xcc008000,0);
            write_volatile_4(0xcc008000,fVar7);
            write_volatile_4(0xcc008000,fVar8);
            write_volatile_4(0xcc008000,fVar9);
            write_volatile_2(0xcc008000,0x1ff);
            write_volatile_2(0xcc008000,0x1ff);
            write_volatile_4(0xcc008000,fVar2);
            write_volatile_4(0xcc008000,fVar10);
            write_volatile_4(0xcc008000,fVar11);
            write_volatile_2(0xcc008000,0);
            write_volatile_2(0xcc008000,0x1ff);
          }
          iVar12 = iVar12 + 0x50;
        }
        which = which + 1;
      } while (which < 2);
      gx::GXSetClipMode(false);
      _sOldVcdVatCmd = 0;
    }
  }
  __psq_l0(auStack8,uVar13);
  __psq_l1(auStack8,uVar13);
  __psq_l0(auStack24,uVar13);
  __psq_l1(auStack24,uVar13);
  __psq_l0(auStack40,uVar13);
  __psq_l1(auStack40,uVar13);
  __psq_l0(auStack56,uVar13);
  __psq_l1(auStack56,uVar13);
  __psq_l0(auStack72,uVar13);
  __psq_l1(auStack72,uVar13);
  __psq_l0(auStack88,uVar13);
  __psq_l1(auStack88,uVar13);
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Removing unreachable block (ram,0x80098790) */
/* WARNING: Removing unreachable block (ram,0x80098780) */
/* WARNING: Removing unreachable block (ram,0x80098770) */
/* WARNING: Removing unreachable block (ram,0x80098760) */
/* WARNING: Removing unreachable block (ram,0x80098750) */
/* WARNING: Removing unreachable block (ram,0x80098740) */
/* WARNING: Removing unreachable block (ram,0x80098730) */
/* WARNING: Removing unreachable block (ram,0x80098728) */
/* WARNING: Removing unreachable block (ram,0x80098738) */
/* WARNING: Removing unreachable block (ram,0x80098748) */
/* WARNING: Removing unreachable block (ram,0x80098758) */
/* WARNING: Removing unreachable block (ram,0x80098768) */
/* WARNING: Removing unreachable block (ram,0x80098778) */
/* WARNING: Removing unreachable block (ram,0x80098788) */
/* WARNING: Removing unreachable block (ram,0x80098798) */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dKyr_drawKazanbai(float *[][][][],
                               unsigned char * *) */

void dKyr_drawKazanbai(MTX34 *param_1,int *param_2)

{
  uint uVar1;
  float fVar2;
  dKankyo_snow_Packet *pdVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  undefined uVar10;
  undefined uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  undefined4 uVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  undefined8 in_f17;
  undefined8 in_f18;
  undefined8 in_f19;
  undefined8 in_f20;
  double dVar26;
  undefined8 in_f21;
  double dVar27;
  undefined8 in_f22;
  double dVar28;
  undefined8 in_f23;
  double dVar29;
  undefined8 in_f24;
  double dVar30;
  double dVar31;
  undefined8 in_f25;
  double dVar32;
  double dVar33;
  undefined8 in_f26;
  double dVar34;
  undefined8 in_f27;
  double dVar35;
  undefined8 in_f28;
  double dVar36;
  undefined8 in_f29;
  double dVar37;
  undefined8 in_f30;
  double dVar38;
  undefined8 in_f31;
  double dVar39;
  _GXColor local_340;
  _GXColor local_33c;
  _GXColor local_338;
  _GXColor local_334;
  undefined4 local_330;
  _GXColor local_32c;
  float local_328;
  float local_324;
  float local_320;
  float local_31c;
  float local_318;
  float local_314;
  float local_310;
  float local_30c;
  float local_308;
  float local_304;
  float local_300;
  float local_2fc;
  float local_2f8;
  float local_2f4;
  float local_2f0;
  float local_2ec;
  float local_2e8;
  float local_2e4;
  float local_2e0;
  float local_2dc;
  float local_2d8;
  float local_2d4;
  float local_2d0;
  float local_2cc;
  float local_2c8;
  float local_2c4;
  float local_2c0;
  cXyz local_2bc;
  cXyz local_2b0;
  undefined auStack676 [32];
  MTX34 MStack644;
  float local_254;
  float local_250;
  float local_24c;
  float local_248;
  float local_244;
  float local_240;
  float local_23c;
  float local_238;
  float local_234;
  float local_230;
  float local_22c;
  float local_228;
  MTX34 MStack548;
  double local_1f0;
  double local_1e8;
  longlong local_1e0;
  longlong local_1d8;
  longlong local_1d0;
  longlong local_1c8;
  longlong local_1c0;
  longlong local_1b8;
  longlong local_1b0;
  longlong local_1a8;
  double local_1a0;
  double local_198;
  longlong local_190;
  longlong local_188;
  double local_180;
  int local_178;
  float *local_174;
  float *local_170;
  float *local_16c;
  float *local_168;
  float *local_164;
  float *local_160;
  float *local_15c;
  dStage_startStage_c *local_158;
  int local_154;
  uint local_150;
  float *local_14c;
  char *local_148;
  undefined auStack232 [16];
  undefined auStack216 [16];
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pdVar3 = d_kankyo::g_env_light.mpSnowPacket;
  uVar21 = 0;
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
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  __psq_st0(auStack216,(int)((ulonglong)in_f18 >> 0x20),0);
  __psq_st1(auStack216,(int)in_f18,0);
  __psq_st0(auStack232,(int)((ulonglong)in_f17 >> 0x20),0);
  __psq_st1(auStack232,(int)in_f17,0);
  if (init_9748 == '\0') {
    rot_9747 = 0_0;
    init_9748 = '\x01';
  }
  if ((d_kankyo::g_env_light.mpSnowPacket)->mEffCount != 0) {
    dVar26 = (double)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                      mCurrent.mPos.y - 100_0);
    local_32c = (_GXColor)0x453c27ff;
    local_330 = (_GXColor)0x7c7c68ff;
    if ((d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) &&
       (mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                          &MStack548), *param_2 != 0)) {
      iVar20 = 0;
      local_158 = &d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage;
      dVar27 = (double)(float)((double)200_0 + dVar26);
      local_148 = "sea";
      dVar28 = (double)_8704;
      local_15c = (float *)&DAT_803e2430;
      local_160 = (float *)&DAT_803e243c;
      local_164 = (float *)&DAT_803e2448;
      local_168 = (float *)&DAT_803e2454;
      local_16c = (float *)&DAT_803e2460;
      local_170 = (float *)&DAT_803e246c;
      local_174 = (float *)&DAT_803e2478;
      do {
        dKyr_set_btitex(auStack676,*param_2);
        gx::GXSetNumChans(0);
        local_334 = local_32c;
        gx::GXSetTevColor(GX_TEVREG0,&local_334);
        local_338 = local_330;
        gx::GXSetTevColor(GX_TEVREG1,&local_338);
        gx::GXSetNumTexGens(1);
        gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
        gx::GXSetNumTevStages(1);
        gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
        gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C1,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
        gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
        gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
        gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
        if (iVar20 == 1) {
          gx::GXSetZMode(true,GX_GEQUAL,false);
        }
        else {
          gx::GXSetZMode(true,GX_LEQUAL,false);
        }
        gx::GXSetCullMode(0);
        gx::GXSetClipMode(true);
        gx::GXSetNumIndStages(0);
        gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
        gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,8);
        gx::GXClearVtxDesc();
        gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
        gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
        MSL_C.PPCEABI.bare.H::strcmp(local_158->mStageName,local_148 + 0x27);
        mtx::PSMTXRotRad(&MStack644,'Z',(float)(dVar28 * (double)rot_9747));
        mtx::PSMTXConcat(&MStack548,&MStack644,&MStack548);
        gx::GXLoadPosMtxImm(param_1,0);
        gx::GXSetCurrentMtx(0);
        iVar19 = 0;
        do {
          if ((iVar20 != 1) || (iVar19 != 1)) {
            if (iVar19 == 0) {
              uVar12 = 0;
              local_178 = (int)pdVar3->mEffCount;
            }
            else {
              uVar12 = 200;
              local_178 = pdVar3->mTamariStart + 200;
            }
            iVar16 = uVar12 * 0x38;
            uVar17 = uVar12 * 4000;
            for (; (int)uVar12 < local_178; uVar12 = uVar12 + 1) {
              if ((iVar20 != 1) || ((&pdVar3->mEff[0].mStatus)[iVar16] != 2)) {
                iVar14 = 8;
                iVar13 = (int)pdVar3->mEff + iVar16 + -0x14;
                local_2c8 = *(float *)(iVar13 + 0x24) + *(float *)(iVar13 + 0x18);
                local_2c4 = *(float *)(iVar13 + 0x28) + *(float *)(iVar13 + 0x1c);
                dVar24 = (double)local_2c4;
                local_2c0 = *(float *)(iVar13 + 0x2c) + *(float *)(iVar13 + 0x20);
                local_32c = (_GXColor)CONCAT31(local_32c._0_3_,0xff);
                if (iVar20 == 1) {
                  if ((dVar24 <= dVar26) || (dVar27 <= dVar24)) goto LAB_800986e8;
                  local_2c4 = (float)dVar26;
                  uVar1 = (uint)(20_0 * (1_0 - (float)(dVar24 - dVar26) / 200_0));
                  local_1f0 = (double)(longlong)(int)uVar1;
                  local_32c = (_GXColor)(uVar1 & 0xff);
                  local_330._2_2_ = SUB42(local_330,0) & 0xff;
                  local_330 = (_GXColor)(uint)local_330._2_2_;
                }
                else {
                  local_1f0 = (double)CONCAT44(0x43300000,(int)pdVar3->mEffCount ^ 0x80000000);
                  iVar15 = (int)((float)(local_1f0 - _4175) * 0_4);
                  local_1e8 = (double)(longlong)iVar15;
                  if ((int)uVar12 < iVar15) {
                    local_1e8 = (double)CONCAT44(0x43300000,uVar17 ^ 0x80000000);
                    local_1f0 = (double)CONCAT44(0x43300000,SComponent::g_Counter);
                    uVar1 = (uint)((float)(local_1e8 - _4175) + (float)(local_1f0 - _8317) * 500_0);
                    local_1e0 = (longlong)(int)uVar1;
                    fVar2 = ABS(JKernel::JMath::jmaCosTable
                                [(int)(uVar1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]);
                    local_1d8 = (longlong)(int)(_10233 + fVar2 * _9537);
                    local_1d0 = (longlong)(int)(60_0 + fVar2 * _10234);
                    local_1c8 = (longlong)(int)(_8064 + fVar2 * _10235);
                    local_1c0 = (longlong)(int)(_10236 + fVar2 * _10237);
                    local_1b0 = (longlong)(int)(_10238 + fVar2 * _10239);
                    iVar15 = (int)(fVar2 * fVar2 * 255_0);
                    local_1a8 = (longlong)iVar15;
                    uVar10 = (undefined)iVar15;
                    iVar15 = (int)(fVar2 * fVar2 * 0_0);
                    local_1a0 = (double)(longlong)iVar15;
                    uVar11 = (undefined)iVar15;
                    local_32c = (_GXColor)CONCAT22(CONCAT11(uVar10,uVar11),CONCAT11(uVar11,0xff));
                    local_330 = (_GXColor)
                                CONCAT22(CONCAT11(uVar10,uVar10),
                                         CONCAT11(uVar11,(undefined)local_330));
                    local_1b8 = local_1c0;
                    local_198 = local_1a0;
                    local_190 = local_1a8;
                    local_188 = local_1a8;
                    local_180 = local_1a0;
                  }
                  else {
                    local_32c = (_GXColor)0x453c27ff;
                    local_330._2_2_ = CONCAT11(0x68,(undefined)local_330);
                    local_330 = (_GXColor)(local_330._2_2_ | 0x7c7c0000);
                  }
                }
                if ((iVar19 == 1) || (*(char *)(iVar13 + 0x14) == '\x02')) {
                  uVar1 = (uint)(255_0 * *(float *)(iVar13 + 0x40));
                  local_180 = (double)(longlong)(int)uVar1;
                  local_32c = (_GXColor)(uVar1 & 0xff);
                  local_330._2_2_ = SUB42(local_330,0) & 0xff;
                  local_330 = (_GXColor)(uint)local_330._2_2_;
                  if (iVar19 == 1) {
                    iVar14 = 1;
                  }
                }
                local_33c = local_32c;
                gx::GXSetTevColor(GX_TEVREG0,&local_33c);
                local_340 = local_330;
                gx::GXSetTevColor(GX_TEVREG1,&local_340);
                if ((iVar19 == 1) || (*(char *)(iVar13 + 0x14) == '\x02')) {
                  local_180 = (double)CONCAT44(0x43300000,(int)uVar12 / 0xfa ^ 0x80000000);
                  fVar2 = 0_9 * (3_0 + (float)(local_180 - _4175));
                }
                else {
                  local_180 = (double)CONCAT44(0x43300000,(int)uVar12 / 0xfa ^ 0x80000000);
                  fVar2 = 3_0 + (float)(local_180 - _4175);
                }
                dVar32 = (double)fVar2;
                dVar29 = -dVar32;
                local_2b0.x = (float)(dVar29 * (double)_1_0);
                dVar30 = (double)local_2b0.x;
                local_2b0.y = (float)(dVar32 - (double)0_0);
                local_2b0.z = 0_0;
                mtx::PSMTXMultVec(&MStack548,&local_2b0,&local_2bc);
                local_254 = local_2c8 + local_2bc.x;
                local_250 = local_2c4 + local_2bc.y;
                local_24c = local_2c0 + local_2bc.z;
                local_2b0.x = (float)(dVar32 * (double)_1_0);
                dVar24 = (double)local_2b0.x;
                local_2b0.y = (float)dVar32;
                local_2b0.z = 0_0;
                mtx::PSMTXMultVec(&MStack548,&local_2b0,&local_2bc);
                local_248 = local_2c8 + local_2bc.x;
                local_244 = local_2c4 + local_2bc.y;
                local_240 = local_2c0 + local_2bc.z;
                local_2b0.x = (float)dVar24;
                local_2b0.y = (float)dVar29;
                local_2b0.z = 0_0;
                mtx::PSMTXMultVec(&MStack548,&local_2b0,&local_2bc);
                local_23c = local_2c8 + local_2bc.x;
                local_238 = local_2c4 + local_2bc.y;
                local_234 = local_2c0 + local_2bc.z;
                local_2b0.x = (float)dVar30;
                local_2b0.y = (float)(dVar29 - (double)0_0);
                local_2b0.z = 0_0;
                mtx::PSMTXMultVec(&MStack548,&local_2b0,&local_2bc);
                pfVar9 = local_160;
                pfVar8 = local_164;
                pfVar7 = local_168;
                pfVar6 = local_16c;
                pfVar5 = local_170;
                pfVar4 = local_174;
                local_230 = local_2c8 + local_2bc.x;
                local_22c = local_2c4 + local_2bc.y;
                local_228 = local_2c0 + local_2bc.z;
                iVar15 = 0;
                local_14c = local_15c;
                local_150 = uVar12 & 3;
                dVar32 = (double)local_254;
                dVar31 = (double)local_250;
                dVar33 = (double)local_24c;
                dVar34 = (double)local_248;
                dVar35 = (double)local_244;
                dVar36 = (double)local_240;
                dVar37 = (double)local_23c;
                dVar38 = (double)local_238;
                dVar39 = (double)local_234;
                dVar24 = (double)local_230;
                dVar29 = (double)local_22c;
                dVar30 = (double)local_228;
                local_154 = iVar14;
                for (iVar18 = 0; iVar18 < local_154; iVar18 = iVar18 + 1) {
                  if (init_9812 == '\0') {
                    local_2d4 = 0_0;
                    local_2d0 = 0_0;
                    local_2cc = 0_0;
                    add_table_9810 = 0_0;
                    DAT_803e2428 = 0_0;
                    DAT_803e242c = 0_0;
                    Runtime.PPCEABI.H::__register_global_object
                              (&add_table_9810,::cXyz::_cXyz,&_9811);
                    DAT_803e2434 = 50_0;
                    DAT_803e2438 = 0_0;
                    local_2e0 = 300_0;
                    local_2dc = 50_0;
                    local_2d8 = 0_0;
                    *local_14c = 300_0;
                    Runtime.PPCEABI.H::__register_global_object(local_14c,::cXyz::_cXyz,&_9814);
                    DAT_803e2440 = _8707;
                    DAT_803e2444 = 300_0;
                    local_2ec = 0_0;
                    local_2e8 = _8707;
                    local_2e4 = 300_0;
                    *pfVar9 = 0_0;
                    Runtime.PPCEABI.H::__register_global_object(pfVar9,::cXyz::_cXyz,&_9815);
                    DAT_803e244c = 20_0;
                    DAT_803e2450 = 150_0;
                    local_2f8 = 150_0;
                    local_2f4 = 20_0;
                    local_2f0 = 150_0;
                    *pfVar8 = 150_0;
                    Runtime.PPCEABI.H::__register_global_object(pfVar8,::cXyz::_cXyz,&_9816);
                    DAT_803e245c = _10241;
                    DAT_803e2458 = 0_0;
                    local_304 = 0_0;
                    local_300 = 0_0;
                    local_2fc = _10241;
                    *pfVar7 = 0_0;
                    Runtime.PPCEABI.H::__register_global_object(pfVar7,::cXyz::_cXyz,&_9817);
                    DAT_803e2464 = 100_0;
                    DAT_803e2468 = 0_0;
                    local_310 = 0_0;
                    local_30c = 100_0;
                    local_308 = 0_0;
                    *pfVar6 = 0_0;
                    Runtime.PPCEABI.H::__register_global_object(pfVar6,::cXyz::_cXyz,&_9818);
                    DAT_803e2470 = _4438;
                    DAT_803e2474 = 0_0;
                    local_31c = 200_0;
                    local_318 = _4438;
                    local_314 = 0_0;
                    *pfVar5 = 200_0;
                    Runtime.PPCEABI.H::__register_global_object(pfVar5,::cXyz::_cXyz,&_9819);
                    DAT_803e247c = 50_0;
                    local_328 = 200_0;
                    local_324 = 50_0;
                    local_320 = 50_0;
                    *pfVar4 = 200_0;
                    DAT_803e2480 = DAT_803e247c;
                    Runtime.PPCEABI.H::__register_global_object(pfVar4,::cXyz::_cXyz,&_9820);
                    init_9812 = '\x01';
                  }
                  gx::GXBegin(0x80,0,4);
                  if (*(char *)(iVar13 + 0x14) == '\x02') {
                    local_180 = (double)CONCAT44(0x43300000,local_150 ^ 0x80000000);
                    fVar2 = (float)(local_180 - _4175);
                  }
                  else {
                    fVar2 = *(float *)((int)&DAT_803e2428 + iVar15);
                  }
                  dVar25 = (double)fVar2;
                  dVar22 = (double)*(float *)((int)&add_table_9810 + iVar15);
                  write_volatile_4(0xcc008000,(float)(dVar32 + dVar22));
                  write_volatile_4(0xcc008000,(float)(dVar31 + dVar25));
                  dVar23 = (double)*(float *)((int)&DAT_803e242c + iVar15);
                  write_volatile_4(0xcc008000,(float)(dVar33 + dVar23));
                  write_volatile_2(0xcc008000,0);
                  write_volatile_2(0xcc008000,0);
                  write_volatile_4(0xcc008000,(float)(dVar34 + dVar22));
                  write_volatile_4(0xcc008000,(float)(dVar35 + dVar25));
                  write_volatile_4(0xcc008000,(float)(dVar36 + dVar23));
                  write_volatile_2(0xcc008000,0xff);
                  write_volatile_2(0xcc008000,0);
                  write_volatile_4(0xcc008000,(float)(dVar37 + dVar22));
                  write_volatile_4(0xcc008000,(float)(dVar38 + dVar25));
                  write_volatile_4(0xcc008000,(float)(dVar39 + dVar23));
                  write_volatile_2(0xcc008000,0xff);
                  write_volatile_2(0xcc008000,0xff);
                  write_volatile_4(0xcc008000,(float)(dVar24 + dVar22));
                  write_volatile_4(0xcc008000,(float)(dVar29 + dVar25));
                  write_volatile_4(0xcc008000,(float)(dVar30 + dVar23));
                  write_volatile_2(0xcc008000,0);
                  write_volatile_2(0xcc008000,0xff);
                  iVar15 = iVar15 + 0xc;
                }
              }
LAB_800986e8:
              uVar17 = uVar17 + 4000;
              iVar16 = iVar16 + 0x38;
            }
          }
          iVar19 = iVar19 + 1;
        } while (iVar19 < 2);
        iVar20 = iVar20 + 1;
      } while (iVar20 < 2);
      gx::GXSetClipMode(false);
      _sOldVcdVatCmd = 0;
    }
  }
  __psq_l0(auStack8,uVar21);
  __psq_l1(auStack8,uVar21);
  __psq_l0(auStack24,uVar21);
  __psq_l1(auStack24,uVar21);
  __psq_l0(auStack40,uVar21);
  __psq_l1(auStack40,uVar21);
  __psq_l0(auStack56,uVar21);
  __psq_l1(auStack56,uVar21);
  __psq_l0(auStack72,uVar21);
  __psq_l1(auStack72,uVar21);
  __psq_l0(auStack88,uVar21);
  __psq_l1(auStack88,uVar21);
  __psq_l0(auStack104,uVar21);
  __psq_l1(auStack104,uVar21);
  __psq_l0(auStack120,uVar21);
  __psq_l1(auStack120,uVar21);
  __psq_l0(auStack136,uVar21);
  __psq_l1(auStack136,uVar21);
  __psq_l0(auStack152,uVar21);
  __psq_l1(auStack152,uVar21);
  __psq_l0(auStack168,uVar21);
  __psq_l1(auStack168,uVar21);
  __psq_l0(auStack184,uVar21);
  __psq_l1(auStack184,uVar21);
  __psq_l0(auStack200,uVar21);
  __psq_l1(auStack200,uVar21);
  __psq_l0(auStack216,uVar21);
  __psq_l1(auStack216,uVar21);
  __psq_l0(auStack232,uVar21);
  __psq_l1(auStack232,uVar21);
  return;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* WARNING: Removing unreachable block (ram,0x80098fc8) */
/* WARNING: Removing unreachable block (ram,0x80098fb8) */
/* WARNING: Removing unreachable block (ram,0x80098fa8) */
/* WARNING: Removing unreachable block (ram,0x80098f98) */
/* WARNING: Removing unreachable block (ram,0x80098f88) */
/* WARNING: Removing unreachable block (ram,0x80098f78) */
/* WARNING: Removing unreachable block (ram,0x80098f68) */
/* WARNING: Removing unreachable block (ram,0x80098f58) */
/* WARNING: Removing unreachable block (ram,0x80098f48) */
/* WARNING: Removing unreachable block (ram,0x80098f50) */
/* WARNING: Removing unreachable block (ram,0x80098f60) */
/* WARNING: Removing unreachable block (ram,0x80098f70) */
/* WARNING: Removing unreachable block (ram,0x80098f80) */
/* WARNING: Removing unreachable block (ram,0x80098f90) */
/* WARNING: Removing unreachable block (ram,0x80098fa0) */
/* WARNING: Removing unreachable block (ram,0x80098fb0) */
/* WARNING: Removing unreachable block (ram,0x80098fc0) */
/* WARNING: Removing unreachable block (ram,0x80098fd0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dKyr_drawSnow(float *[][][][],
                           unsigned char * *) */

void dKyr_drawSnow(MTX34 *param_1,void **param_2)

{
  float fVar1;
  dKankyo_snow_Packet *pdVar2;
  int iVar3;
  dKankyo_snow_Packet *pEff;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  undefined8 in_f14;
  double dVar12;
  undefined8 in_f15;
  undefined8 in_f16;
  double dVar13;
  undefined8 in_f17;
  double dVar14;
  undefined8 in_f18;
  double dVar15;
  undefined8 in_f19;
  double dVar16;
  undefined8 in_f20;
  double dVar17;
  undefined8 in_f21;
  double dVar18;
  undefined8 in_f22;
  double dVar19;
  undefined8 in_f23;
  double dVar20;
  undefined8 in_f24;
  double dVar21;
  undefined8 in_f25;
  double dVar22;
  undefined8 in_f26;
  double dVar23;
  undefined8 in_f27;
  double dVar24;
  undefined8 in_f28;
  double dVar25;
  undefined8 in_f29;
  double dVar26;
  undefined8 in_f30;
  double dVar27;
  undefined8 in_f31;
  double dVar28;
  _GXColor local_278;
  _GXColor local_274;
  _GXColor local_270;
  _GXColor local_26c;
  float local_268;
  float local_264;
  float local_260;
  float local_25c;
  float local_258;
  float local_254;
  float local_250;
  float local_24c;
  float local_248;
  float local_244;
  float local_240;
  float local_23c;
  cXyz pos;
  cXyz ext2;
  cXyz ext;
  GXTexObj GStack532;
  MTX34 MStack500;
  float local_1c4;
  float local_1c0;
  float local_1bc;
  float local_1b8;
  float local_1b4;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a4;
  float local_1a0;
  float local_19c;
  float local_198;
  MTX34 MStack404;
  undefined4 local_160;
  uint uStack348;
  undefined4 local_158;
  uint uStack340;
  undefined auStack280 [16];
  undefined auStack264 [16];
  undefined auStack248 [16];
  undefined auStack232 [16];
  undefined auStack216 [16];
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pdVar2 = d_kankyo::g_env_light.mpSnowPacket;
  uVar7 = 0;
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
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  __psq_st0(auStack216,(int)((ulonglong)in_f18 >> 0x20),0);
  __psq_st1(auStack216,(int)in_f18,0);
  __psq_st0(auStack232,(int)((ulonglong)in_f17 >> 0x20),0);
  __psq_st1(auStack232,(int)in_f17,0);
  __psq_st0(auStack248,(int)((ulonglong)in_f16 >> 0x20),0);
  __psq_st1(auStack248,(int)in_f16,0);
  __psq_st0(auStack264,(int)((ulonglong)in_f15 >> 0x20),0);
  __psq_st1(auStack264,(int)in_f15,0);
  __psq_st0(auStack280,(int)((ulonglong)in_f14 >> 0x20),0);
  __psq_st1(auStack280,(int)in_f14,0);
  if (init_10262 == '\0') {
    rot_10261 = 0_0;
    init_10262 = '\x01';
  }
  if ((d_kankyo::g_env_light.mpSnowPacket)->mEffCount != 0) {
    iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Adanmae");
    if (iVar3 == 0) {
      dKyr_drawKazanbai(param_1,param_2);
    }
    else {
      local_26c = (_GXColor)0xffffff78;
      local_270 = (_GXColor)0x80808078;
      if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
        mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                          &MStack404);
        if (*param_2 != (void *)0x0) {
          gx::GXInitTexObj(&GStack532,*param_2,0x40,0x40,GX_TF_I8,GX_CLAMP,GX_CLAMP,false);
          dVar8 = (double)0_0;
          gx::GXInitTexObjLOD(dVar8,dVar8,dVar8,&GStack532,1,1,0,0,0);
          gx::GXLoadTexObj(&GStack532,0);
          gx::GXSetNumChans(0);
          local_274 = local_26c;
          gx::GXSetTevColor(GX_TEVREG0,&local_274);
          local_278 = local_270;
          gx::GXSetTevColor(GX_TEVREG1,&local_278);
          gx::GXSetNumTexGens(1);
          gx::GXSetTexCoordGen2
                    (GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
          gx::GXSetNumTevStages(1);
          gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
          gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C1,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
          gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
          gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
          gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
          gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
          gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
          gx::GXSetZMode(true,GX_LEQUAL,false);
          gx::GXSetCullMode(0);
          gx::GXSetClipMode(true);
          gx::GXSetNumIndStages(0);
          gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
          gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,8);
          gx::GXClearVtxDesc();
          gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
          gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
          mtx::PSMTXRotRad(&MStack500,'Z',_8704 * rot_10261);
          mtx::PSMTXConcat(&MStack404,&MStack500,&MStack404);
          gx::GXLoadPosMtxImm(param_1,0);
          gx::GXSetCurrentMtx(0);
          iVar3 = 0;
          dVar12 = (double)2_0;
          dVar13 = (double)250_0;
          dVar14 = (double)8_0;
          dVar15 = (double)_1_0;
          dVar16 = (double)0_0;
          dVar8 = _4175;
          for (uVar6 = 0; (int)uVar6 < (int)pdVar2->mEffCount; uVar6 = uVar6 + 1) {
            pEff = (dKankyo_snow_Packet *)((int)pdVar2->mEff + iVar3 + -0x14);
            pos.x = pEff->mEff[0].mBasePos.x + pEff->mEff[0].mPos.x;
            pos.y = pEff->mEff[0].mBasePos.y + pEff->mEff[0].mPos.y;
            pos.z = pEff->mEff[0].mBasePos.z + pEff->mEff[0].mPos.z;
            uStack348 = uVar6 ^ 0x80000000;
            local_160 = 0x43300000;
            dVar21 = (double)((float)(dVar12 * (double)(float)((double)(float)((double)CONCAT44(
                                                  0x43300000,uStack348) - dVar8) / dVar13)) *
                             pdVar2->field_0x36d0);
            fVar1 = pEff->mEff[0].mScale;
            uStack340 = (int)uVar6 / 0xfa ^ 0x80000000;
            local_158 = 0x43300000;
            dVar20 = (double)((fVar1 + (fVar1 - fVar1 * fVar1)) *
                             (float)(dVar14 + (double)(float)((double)CONCAT44(0x43300000,uStack340)
                                                             - dVar8)));
            dVar18 = -dVar20;
            ext.x = (float)(dVar18 * dVar15);
            dVar19 = (double)ext.x;
            ext.y = (float)(dVar20 - dVar21);
            ext.z = (float)dVar16;
            mtx::PSMTXMultVec(&MStack404,&ext,&ext2);
            local_1c4 = pos.x + ext2.x;
            local_1c0 = pos.y + ext2.y;
            local_1bc = pos.z + ext2.z;
            ext.x = (float)(dVar20 * dVar15);
            dVar17 = (double)ext.x;
            ext.y = (float)dVar20;
            ext.z = (float)dVar16;
            mtx::PSMTXMultVec(&MStack404,&ext,&ext2);
            local_1b8 = pos.x + ext2.x;
            local_1b4 = pos.y + ext2.y;
            local_1b0 = pos.z + ext2.z;
            ext.x = (float)dVar17;
            ext.y = (float)dVar18;
            ext.z = (float)dVar16;
            mtx::PSMTXMultVec(&MStack404,&ext,&ext2);
            local_1ac = pos.x + ext2.x;
            local_1a8 = pos.y + ext2.y;
            local_1a4 = pos.z + ext2.z;
            ext.x = (float)dVar19;
            ext.y = (float)(dVar18 - dVar21);
            ext.z = (float)dVar16;
            mtx::PSMTXMultVec(&MStack404,&ext,&ext2);
            local_1a0 = pos.x + ext2.x;
            local_19c = pos.y + ext2.y;
            local_198 = pos.z + ext2.z;
            iVar5 = 0;
            iVar4 = 0;
            dVar17 = (double)local_1c4;
            dVar18 = (double)local_1c0;
            dVar19 = (double)local_1bc;
            dVar20 = (double)local_1b8;
            dVar21 = (double)local_1b4;
            dVar22 = (double)local_1b0;
            dVar23 = (double)local_1ac;
            dVar24 = (double)local_1a8;
            dVar25 = (double)local_1a4;
            dVar26 = (double)local_1a0;
            dVar27 = (double)local_19c;
            dVar28 = (double)local_198;
            do {
              if (init_10286 == '\0') {
                local_244 = 0_0;
                local_240 = 0_0;
                local_23c = 0_0;
                add_table_10284[0].x = 0_0;
                add_table_10284[0].y = 0_0;
                add_table_10284[0].z = 0_0;
                Runtime.PPCEABI.H::__register_global_object(add_table_10284,::cXyz::_cXyz,&_10285);
                local_250 = 150_0;
                local_24c = 75_0;
                local_248 = 0_0;
                add_table_10284[1].x = 150_0;
                add_table_10284[1].y = 75_0;
                add_table_10284[1].z = 0_0;
                Runtime.PPCEABI.H::__register_global_object(0x803e24c0,::cXyz::_cXyz,&_10288);
                local_25c = 0_0;
                local_258 = _75_0;
                local_254 = 150_0;
                add_table_10284[2].x = 0_0;
                add_table_10284[2].y = _75_0;
                add_table_10284[2].z = 150_0;
                Runtime.PPCEABI.H::__register_global_object(0x803e24cc,::cXyz::_cXyz,&_10289);
                local_268 = 45_0;
                local_264 = 45_0;
                local_260 = 45_0;
                add_table_10284[3].x = 45_0;
                add_table_10284[3].y = 45_0;
                add_table_10284[3].z = 45_0;
                Runtime.PPCEABI.H::__register_global_object(0x803e24d8,::cXyz::_cXyz,&_10290);
                init_10286 = '\x01';
              }
              gx::GXBegin(0x80,0,4);
              dVar9 = (double)*(float *)((int)&add_table_10284[0].x + iVar4);
              write_volatile_4(0xcc008000,(float)(dVar17 + dVar9));
              dVar10 = (double)*(float *)((int)&add_table_10284[0].y + iVar4);
              write_volatile_4(0xcc008000,(float)(dVar18 + dVar10));
              dVar11 = (double)*(float *)((int)&add_table_10284[0].z + iVar4);
              write_volatile_4(0xcc008000,(float)(dVar19 + dVar11));
              write_volatile_2(0xcc008000,0);
              write_volatile_2(0xcc008000,0);
              write_volatile_4(0xcc008000,(float)(dVar20 + dVar9));
              write_volatile_4(0xcc008000,(float)(dVar21 + dVar10));
              write_volatile_4(0xcc008000,(float)(dVar22 + dVar11));
              write_volatile_2(0xcc008000,0xff);
              write_volatile_2(0xcc008000,0);
              write_volatile_4(0xcc008000,(float)(dVar23 + dVar9));
              write_volatile_4(0xcc008000,(float)(dVar24 + dVar10));
              write_volatile_4(0xcc008000,(float)(dVar25 + dVar11));
              write_volatile_2(0xcc008000,0xff);
              write_volatile_2(0xcc008000,0xff);
              write_volatile_4(0xcc008000,(float)(dVar26 + dVar9));
              write_volatile_4(0xcc008000,(float)(dVar27 + dVar10));
              write_volatile_4(0xcc008000,(float)(dVar28 + dVar11));
              write_volatile_2(0xcc008000,0);
              write_volatile_2(0xcc008000,0xff);
              iVar5 = iVar5 + 1;
              iVar4 = iVar4 + 0xc;
            } while (iVar5 < 4);
            iVar3 = iVar3 + 0x38;
          }
          gx::GXSetClipMode(false);
          _sOldVcdVatCmd = 0;
        }
      }
    }
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  __psq_l0(auStack56,uVar7);
  __psq_l1(auStack56,uVar7);
  __psq_l0(auStack72,uVar7);
  __psq_l1(auStack72,uVar7);
  __psq_l0(auStack88,uVar7);
  __psq_l1(auStack88,uVar7);
  __psq_l0(auStack104,uVar7);
  __psq_l1(auStack104,uVar7);
  __psq_l0(auStack120,uVar7);
  __psq_l1(auStack120,uVar7);
  __psq_l0(auStack136,uVar7);
  __psq_l1(auStack136,uVar7);
  __psq_l0(auStack152,uVar7);
  __psq_l1(auStack152,uVar7);
  __psq_l0(auStack168,uVar7);
  __psq_l1(auStack168,uVar7);
  __psq_l0(auStack184,uVar7);
  __psq_l1(auStack184,uVar7);
  __psq_l0(auStack200,uVar7);
  __psq_l1(auStack200,uVar7);
  __psq_l0(auStack216,uVar7);
  __psq_l1(auStack216,uVar7);
  __psq_l0(auStack232,uVar7);
  __psq_l1(auStack232,uVar7);
  __psq_l0(auStack248,uVar7);
  __psq_l1(auStack248,uVar7);
  __psq_l0(auStack264,uVar7);
  __psq_l1(auStack264,uVar7);
  __psq_l0(auStack280,uVar7);
  __psq_l1(auStack280,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x80099d10) */
/* WARNING: Removing unreachable block (ram,0x80099d00) */
/* WARNING: Removing unreachable block (ram,0x80099cf0) */
/* WARNING: Removing unreachable block (ram,0x80099ce0) */
/* WARNING: Removing unreachable block (ram,0x80099ce8) */
/* WARNING: Removing unreachable block (ram,0x80099cf8) */
/* WARNING: Removing unreachable block (ram,0x80099d08) */
/* WARNING: Removing unreachable block (ram,0x80099d18) */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dKyr_drawStar(float *[][][][],
                           unsigned char * *) */

void dKyr_drawStar(MTX34 *param_1,char *pTexData)

{
  double dVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  uint i;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  double dVar9;
  double dist;
  undefined8 in_f24;
  double dVar10;
  double moonSize;
  undefined8 in_f25;
  double dVar11;
  double eyePosX;
  undefined8 in_f26;
  double eyePosY;
  undefined8 in_f27;
  double eyePosZ;
  undefined8 in_f28;
  undefined8 in_f29;
  double scale;
  undefined8 in_f30;
  double dVar12;
  double dVar13;
  undefined8 in_f31;
  double fovYSmth;
  _GXColor local_234;
  _GXColor local_230;
  _GXColor local_22c;
  undefined4 local_228;
  short local_224;
  undefined4 local_220;
  short local_21c;
  undefined4 local_218;
  short local_214;
  undefined4 local_210;
  short local_20c;
  undefined4 local_208;
  short local_204;
  undefined4 local_200;
  short local_1fc;
  undefined4 local_1f8;
  short local_1f4;
  undefined4 local_1f0;
  short local_1ec;
  undefined4 local_1e8;
  short local_1e4;
  undefined4 local_1e0;
  short local_1dc;
  undefined4 local_1d8;
  short local_1d4;
  undefined4 local_1d0;
  short local_1cc;
  undefined4 local_1c8;
  short local_1c4;
  undefined4 local_1c0;
  short local_1bc;
  undefined4 local_1b8;
  short local_1b4;
  csXyz local_1b0;
  TVec3_float_ pos;
  cXyz posBase;
  TVec3_float_ ret;
  TVec3_float_ starPos;
  cXyz proj;
  cXyz moonProj;
  cXyz eyePos;
  MTX34 rotMtx;
  MTX34 viewMtx;
  cXyz p0;
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  uint angle;
  float baseScale;
  camera_class *pCam;
  dKankyo_star_Packet *pPkt;
  
  pPkt = d_kankyo::g_env_light.mpStarPacket;
  pCam = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar8 = 0;
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
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  if (init_10492 == '\0') {
    rot_10491 = 0;
    init_10492 = '\x01';
  }
  if (init_10496 == '\0') {
    ::csXyz::csXyz(&local_1b0,13000,0x2904,-16000);
    hokuto_position_10494[0]._0_4_ = local_1b0._0_4_;
    hokuto_position_10494[0].z = local_1b0.z;
    Runtime.PPCEABI.H::__register_global_object(hokuto_position_10494,::csXyz::_csXyz,&_10495);
    ::csXyz::csXyz((csXyz *)&local_1b8,0x24b8,0x2648,-0x3166);
    hokuto_position_10494[1]._0_4_ = local_1b8;
    hokuto_position_10494[1].z = local_1b4;
    Runtime.PPCEABI.H::__register_global_object(0x803e25aa,::csXyz::_csXyz,&_10498);
    ::csXyz::csXyz((csXyz *)&local_1c0,0x27d8,0x2e18,-0x34d5);
    hokuto_position_10494[2]._0_4_ = local_1c0;
    hokuto_position_10494[2].z = local_1bc;
    Runtime.PPCEABI.H::__register_global_object(0x803e25b0,::csXyz::_csXyz,&_10499);
    ::csXyz::csXyz((csXyz *)&local_1c8,0x283c,0x348a,-0x34d5);
    hokuto_position_10494[3]._0_4_ = local_1c8;
    hokuto_position_10494[3].z = local_1c4;
    Runtime.PPCEABI.H::__register_global_object(0x803e25b6,::csXyz::_csXyz,&_10500);
    ::csXyz::csXyz((csXyz *)&local_1d0,15000,0x47e0,-0x3f22);
    hokuto_position_10494[4]._0_4_ = local_1d0;
    hokuto_position_10494[4].z = local_1cc;
    Runtime.PPCEABI.H::__register_global_object(0x803e25bc,::csXyz::_csXyz,&_10501);
    ::csXyz::csXyz((csXyz *)&local_1d8,0x30d4,0x4d58,-15000);
    hokuto_position_10494[5]._0_4_ = local_1d8;
    hokuto_position_10494[5].z = local_1d4;
    Runtime.PPCEABI.H::__register_global_object(0x803e25c2,::csXyz::_csXyz,&_10502);
    ::csXyz::csXyz((csXyz *)&local_1e0,0x23db,0x4330,-0x3844);
    hokuto_position_10494[6]._0_4_ = local_1e0;
    hokuto_position_10494[6].z = local_1dc;
    Runtime.PPCEABI.H::__register_global_object(0x803e25c8,::csXyz::_csXyz,&_10503);
    ::csXyz::csXyz((csXyz *)&local_1e8,0x251c,0x2648,-0x3166);
    hokuto_position_10494[7]._0_4_ = local_1e8;
    hokuto_position_10494[7].z = local_1e4;
    Runtime.PPCEABI.H::__register_global_object(0x803e25ce,::csXyz::_csXyz,&_10504);
    ::csXyz::csXyz((csXyz *)&local_1f0,-0x1cfd,0x791d,0x496e);
    hokuto_position_10494[8]._0_4_ = local_1f0;
    hokuto_position_10494[8].z = local_1ec;
    Runtime.PPCEABI.H::__register_global_object(0x803e25d4,::csXyz::_csXyz,&_10505);
    ::csXyz::csXyz((csXyz *)&local_1f8,-0x2ab9,28000,15000);
    hokuto_position_10494[9]._0_4_ = local_1f8;
    hokuto_position_10494[9].z = local_1f4;
    Runtime.PPCEABI.H::__register_global_object(0x803e25da,::csXyz::_csXyz,&_10506);
    ::csXyz::csXyz((csXyz *)&local_200,-10000,0x6146,0x47e0);
    hokuto_position_10494[10]._0_4_ = local_200;
    hokuto_position_10494[10].z = local_1fc;
    Runtime.PPCEABI.H::__register_global_object(0x803e25e0,::csXyz::_csXyz,&_10507);
    ::csXyz::csXyz((csXyz *)&local_208,-0x24b8,0x57e4,0x3e1c);
    hokuto_position_10494[11]._0_4_ = local_208;
    hokuto_position_10494[11].z = local_204;
    Runtime.PPCEABI.H::__register_global_object(0x803e25e6,::csXyz::_csXyz,&_10508);
    ::csXyz::csXyz((csXyz *)&local_210,-0x23db,0x5334,0x37dc);
    hokuto_position_10494[12]._0_4_ = local_210;
    hokuto_position_10494[12].z = local_20c;
    Runtime.PPCEABI.H::__register_global_object(0x803e25ec,::csXyz::_csXyz,&_10509);
    ::csXyz::csXyz((csXyz *)&local_218,-0x283c,22000,21000);
    hokuto_position_10494[13]._0_4_ = local_218;
    hokuto_position_10494[13].z = local_214;
    Runtime.PPCEABI.H::__register_global_object(0x803e25f2,::csXyz::_csXyz,&_10510);
    ::csXyz::csXyz((csXyz *)&local_220,-16000,0x639c,20000);
    hokuto_position_10494[14]._0_4_ = local_220;
    hokuto_position_10494[14].z = local_21c;
    Runtime.PPCEABI.H::__register_global_object(0x803e25f8,::csXyz::_csXyz,&_10511);
    ::csXyz::csXyz((csXyz *)&local_228,0,30000,19000);
    hokuto_position_10494[15]._0_4_ = local_228;
    hokuto_position_10494[15].z = local_224;
    Runtime.PPCEABI.H::__register_global_object(0x803e25fe,::csXyz::_csXyz,&_10512);
    init_10496 = '\x01';
  }
  if ((pPkt->mCount != 0) &&
     (local_22c = (_GXColor)0xdce6ffff,
     d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0)) {
    mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                      &viewMtx);
    m_Do_lib::mDoLib_project((cXyz *)&d_kankyo::g_env_light.mMoonPos,&moonProj);
    gx::GXSetNumChans(1);
    gx::GXSetChanCtrl(GX_COLOR0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_CLAMP,GX_AF_NONE);
    gx::GXSetNumTexGens(0);
    gx::GXSetNumTevStages(1);
    local_230 = local_22c;
    gx::GXSetTevColor(GX_TEVREG0,&local_230);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_C0);
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A0);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetZMode(true,GX_LEQUAL,false);
    gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_CLEAR);
    gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
    gx::GXSetNumIndStages(0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    mtx::PSMTXRotRad(&rotMtx,'Z',_8704 * (float)((double)CONCAT44(0x43300000,rot_10491) - _8317));
    mtx::PSMTXConcat(&viewMtx,&rotMtx,&viewMtx);
    gx::GXLoadPosMtxImm(param_1,0);
    gx::GXSetCurrentMtx(0);
    rot_10491 = rot_10491 + 1;
    if (0x2cf < rot_10491) {
      rot_10491 = 0;
    }
    eyePos.x = (pCam->mEyePos).x;
    eyePos.y = (pCam->mEyePos).y;
    eyePos.z = (pCam->mEyePos).z;
    fVar2 = 0_0;
    if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
      fVar2 = (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mFovY / 40_0;
      if (1_0 <= fVar2) {
        fVar2 = 1_0;
      }
      fVar2 = 1_0 - fVar2;
    }
    fovYSmth = (double)fVar2;
    starPos.y = 0_9 - (float)((double)0_6 * fovYSmth);
    dVar10 = (double)starPos.y;
    starPos.x = 0_0;
    starPos.z = 0_0;
    mtx::PSMTXMultVec(&viewMtx,(cXyz *)&starPos,(cXyz *)&ret);
    p0.x = eyePos.x + ret.x;
    p0.y = eyePos.y + ret.y;
    p0.z = eyePos.z + ret.z;
    starPos.x = (float)dVar10;
    dVar11 = -(double)(float)((double)0_5 * dVar10);
    starPos.y = (float)dVar11;
    starPos.z = 0_0;
    mtx::PSMTXMultVec(&viewMtx,(cXyz *)&starPos,(cXyz *)&ret);
    fVar2 = eyePos.x + ret.x;
    fVar3 = eyePos.y + ret.y;
    fVar4 = eyePos.z + ret.z;
    starPos.x = (float)-dVar10;
    starPos.y = (float)dVar11;
    starPos.z = 0_0;
    mtx::PSMTXMultVec(&viewMtx,(cXyz *)&starPos,(cXyz *)&ret);
    eyePosX = (double)eyePos.x;
    dVar10 = eyePosX + (double)ret.x;
    eyePosY = (double)eyePos.y;
    dVar11 = eyePosY + (double)ret.y;
    eyePosZ = (double)eyePos.z;
    dVar1 = eyePosZ + (double)ret.z;
    iVar6 = 0;
    iVar7 = 0;
    dVar12 = (double)0_0;
    iVar5 = 0;
    moonSize = (double)(80_0 + 700_0 * (float)(fovYSmth * fovYSmth));
    dVar13 = dVar12;
    for (i = 0; (int)i < (int)pPkt->mCount; i = i + 1) {
      if ((int)i < 0x10) {
        posBase.x = (float)((double)CONCAT44(0x43300000,
                                             (int)*(short *)((int)&hokuto_position_10494[0].x +
                                                            iVar5) ^ 0x80000000) - _4175);
        posBase.y = (float)((double)CONCAT44(0x43300000,
                                             (int)*(short *)((int)&hokuto_position_10494[0].y +
                                                            iVar5) ^ 0x80000000) - _4175);
        posBase.z = (float)((double)CONCAT44(0x43300000,
                                             (int)*(short *)((int)&hokuto_position_10494[0].z +
                                                            iVar5) ^ 0x80000000) - _4175);
        if ((int)i < 8) {
          baseScale = 190_0 + pPkt->mStarEff[0].mSin;
        }
        else {
          baseScale = 290_0 + pPkt->mStarEff[0].mSin;
        }
        scale = (double)(baseScale - (float)(fovYSmth * (double)(0_5 * baseScale)));
      }
      else {
        scale = (double)(pPkt->mStarEff[0].mSin +
                        0_066 * (float)((double)CONCAT44(0x43300000,i & 0xf ^ 0x80000000) - _4175));
        dist = (double)1_0;
        if (dist < scale) {
          scale = (double)(float)(dist - (double)(float)(scale - dist));
        }
        baseScale = 1_0 - (float)((double)1_202_0 * dVar13);
        angle = iVar6 - 0x8000U & 0xffff;
        posBase.x = baseScale *
                    300_0 * -JKernel::JMath::jmaSinTable
                             [(int)angle >> (JKernel::JMath::jmaSinShift & 0x3f)];
        posBase.y = (float)((double)45_0 + dVar13);
        posBase.z = baseScale *
                    300_0 * JKernel::JMath::jmaCosTable
                            [(int)angle >> (JKernel::JMath::jmaSinShift & 0x3f)];
        iVar6 = iVar6 + iVar7;
        baseScale = (float)(dVar13 / (double)200_0);
        dVar13 = (double)(float)(dVar13 + (double)(1_0 + 3_0 * baseScale * baseScale * baseScale));
        iVar7 = iVar7 + 0x9c4;
        if ((double)200_0 < dVar13) {
          dVar13 = (double)(20_0 * ((float)((double)CONCAT44(0x43300000,i ^ 0x80000000) - _4175) /
                                   1000_0));
        }
      }
      if ((i == 6) || (i == 8)) {
        local_22c = (_GXColor)
                    CONCAT31(CONCAT21(CONCAT11(star_col_10513[1].r,star_col_10513[1].g),
                                      star_col_10513[1].b),star_col_10513[1].a);
      }
      else {
        if ((i & 0x3f) == 0) {
          local_22c = *(_GXColor *)(&star_col_10513[0].r + (i >> 4 & 0xc));
        }
        else {
          local_22c = (_GXColor)
                      CONCAT31(CONCAT21(CONCAT11(star_col_10513[0].r,star_col_10513[0].g),
                                        star_col_10513[0].b),star_col_10513[0].a);
        }
      }
      local_234 = local_22c;
      gx::GXSetTevColor(GX_TEVREG0,&local_234);
      pos.x = (float)(eyePosX + (double)posBase.x);
      pos.y = (float)(eyePosY + (double)posBase.y);
      pos.z = (float)(eyePosZ + (double)posBase.z);
      m_Do_lib::mDoLib_project((cXyz *)&pos,&proj);
      baseScale = mtx::PSVECSquareDistance(&moonProj,&proj);
      dist = (double)baseScale;
      if (dVar12 < dist) {
        dVar9 = 1.0 / SQRT(dist);
        dVar9 = 0_5 * dVar9 * (3_0 - dist * dVar9 * dVar9);
        dVar9 = 0_5 * dVar9 * (3_0 - dist * dVar9 * dVar9);
        dist = (double)(float)(dist * 0_5 * dVar9 * (3_0 - dist * dVar9 * dVar9));
      }
      if (moonSize < dist) {
        gx::GXBegin(0x80,0,3);
        write_volatile_4(0xcc008000,pos.x + (float)(scale * (double)(p0.x - eyePos.x)));
        write_volatile_4(0xcc008000,pos.y + (float)(scale * (double)(p0.y - eyePos.y)));
        write_volatile_4(0xcc008000,pos.z + (float)(scale * (double)(p0.z - eyePos.z)));
        write_volatile_4(0xcc008000,pos.x + (float)(scale * (double)(fVar2 - eyePos.x)));
        write_volatile_4(0xcc008000,pos.y + (float)(scale * (double)(fVar3 - eyePos.y)));
        write_volatile_4(0xcc008000,pos.z + (float)(scale * (double)(fVar4 - eyePos.z)));
        write_volatile_4(0xcc008000,pos.x + (float)(scale * (double)((float)dVar10 - eyePos.x)));
        write_volatile_4(0xcc008000,pos.y + (float)(scale * (double)((float)dVar11 - eyePos.y)));
        write_volatile_4(0xcc008000,pos.z + (float)(scale * (double)((float)dVar1 - eyePos.z)));
        gx::GXBegin(0x80,0,3);
        write_volatile_4(0xcc008000,pos.x - (float)(scale * (double)(p0.x - eyePos.x)));
        write_volatile_4(0xcc008000,pos.y - (float)(scale * (double)(p0.y - eyePos.y)));
        write_volatile_4(0xcc008000,pos.z - (float)(scale * (double)(p0.z - eyePos.z)));
        write_volatile_4(0xcc008000,pos.x - (float)(scale * (double)(fVar2 - eyePos.x)));
        write_volatile_4(0xcc008000,pos.y - (float)(scale * (double)(fVar3 - eyePos.y)));
        write_volatile_4(0xcc008000,pos.z - (float)(scale * (double)(fVar4 - eyePos.z)));
        write_volatile_4(0xcc008000,pos.x - (float)(scale * (double)((float)dVar10 - eyePos.x)));
        write_volatile_4(0xcc008000,pos.y - (float)(scale * (double)((float)dVar11 - eyePos.y)));
        write_volatile_4(0xcc008000,pos.z - (float)(scale * (double)((float)dVar1 - eyePos.z)));
      }
      iVar5 = iVar5 + 6;
    }
    _sOldVcdVatCmd = 0;
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  __psq_l0(auStack40,uVar8);
  __psq_l1(auStack40,uVar8);
  __psq_l0(auStack56,uVar8);
  __psq_l1(auStack56,uVar8);
  __psq_l0(auStack72,uVar8);
  __psq_l1(auStack72,uVar8);
  __psq_l0(auStack88,uVar8);
  __psq_l1(auStack88,uVar8);
  __psq_l0(auStack104,uVar8);
  __psq_l1(auStack104,uVar8);
  __psq_l0(auStack120,uVar8);
  __psq_l1(auStack120,uVar8);
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x8009a5ac) */
/* WARNING: Removing unreachable block (ram,0x8009a59c) */
/* WARNING: Removing unreachable block (ram,0x8009a58c) */
/* WARNING: Removing unreachable block (ram,0x8009a57c) */
/* WARNING: Removing unreachable block (ram,0x8009a56c) */
/* WARNING: Removing unreachable block (ram,0x8009a55c) */
/* WARNING: Removing unreachable block (ram,0x8009a554) */
/* WARNING: Removing unreachable block (ram,0x8009a564) */
/* WARNING: Removing unreachable block (ram,0x8009a574) */
/* WARNING: Removing unreachable block (ram,0x8009a584) */
/* WARNING: Removing unreachable block (ram,0x8009a594) */
/* WARNING: Removing unreachable block (ram,0x8009a5a4) */
/* WARNING: Removing unreachable block (ram,0x8009a5b4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall drawWave(float *[][][][],
                      unsigned char * *) */

void drawWave(MTX34 *param_1,byte *param_2)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  camera_class *pcVar10;
  uint uVar11;
  int iVar12;
  dKankyo_wave_Packet *pPktW;
  int iVar13;
  undefined4 uVar14;
  double sin;
  double scale;
  double dVar15;
  undefined8 in_f19;
  undefined8 in_f20;
  undefined8 in_f21;
  undefined8 in_f22;
  double dVar16;
  undefined8 in_f23;
  double dVar17;
  undefined8 in_f24;
  double dVar18;
  undefined8 in_f25;
  double dVar19;
  undefined8 in_f26;
  double dVar20;
  undefined8 in_f27;
  double dVar21;
  undefined8 in_f28;
  double dVar22;
  undefined8 in_f29;
  double dVar23;
  undefined8 in_f30;
  double y;
  double dVar24;
  undefined8 in_f31;
  double 0_0;
  _GXColor local_228;
  _GXColor local_224;
  _GXColor local_220;
  _GXColor local_21c;
  _GXColor local_218;
  _GXColor local_214;
  float local_210;
  float local_20c;
  float local_208;
  float local_204;
  float local_200;
  float local_1fc;
  float local_1f8;
  float local_1f4;
  float local_1f0;
  float local_1ec;
  float local_1e8;
  float local_1e4;
  TVec3_float_ ret;
  TVec3_float_ in;
  cXyz pos;
  GXTexObj GStack444;
  cXyz local_19c;
  MTX34 MStack364;
  MTX34 mtx;
  double idx_15;
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  dKankyo_wave_Packet *pPkt;
  float strength;
  
  pPkt = d_kankyo::g_env_light.mpWavePacket;
  pcVar10 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar14 = 0;
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
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  if ((d_kankyo::g_env_light.mWaveFlatInter < 1_0) &&
     (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0)) {
    ::mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                        &mtx);
    idx_15 = (double)CONCAT44(0x43300000,(int)pcVar10->mBank ^ 0x80000000);
    0_0 = (double)(_5017 * (float)(idx_15 - _4175));
    J3DSys::reinitGX(&J3DGraphBase::j3dSys);
    gx::GXSetClipMode(false);
    iVar12 = MSL_C.PPCEABI.bare.H::strcmp
                       (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"MajyuE");
    uVar11 = countLeadingZeros(iVar12);
    dKyr_set_btitex(&GStack444,*(undefined4 *)(param_2 + (uVar11 >> 3 & 0x1ffffffc)));
    gx::GXSetNumChans(0);
    gx::GXSetNumTexGens(1);
    gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
    d_kankyo::dKy_get_seacolor(&local_218,&local_214);
    local_21c = local_214;
    gx::GXSetTevColor(GX_TEVREG0,&local_21c);
    gx::GXSetTevKColorSel(0,0xc);
    gx::GXSetTevKAlphaSel(0,0x1f);
    local_220 = local_218;
    gx::GXSetTevKColor(0,&local_220);
    local_224 = local_218;
    gx::GXSetTevKColor(3,&local_224);
    gx::GXSetNumTevStages(1);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C0,GX_CC_KONST,GX_CC_TEXC,GX_CC_ZERO);
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_KONST,GX_CA_TEXA,GX_CA_ZERO);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    d_kankyo::dKy_GxFog_sea_set();
    gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
    gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
    gx::GXSetZCompLoc(0);
    gx::GXSetZMode(true,GX_LEQUAL,true);
    gx::GXSetCullMode(0);
    gx::GXSetNumIndStages(0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,8);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
    ::mtx::PSMTXRotRad(&MStack364,'Z',(float)((double)_8704 * 0_0));
    ::mtx::PSMTXConcat(&mtx,&MStack364,&mtx);
    gx::GXLoadPosMtxImm(param_1,0);
    gx::GXSetCurrentMtx(0);
    uVar11 = 0;
    iVar12 = 0;
    0_0 = (double)0_0;
    for (iVar13 = 0; iVar13 < d_kankyo::g_env_light.mWaveCount; iVar13 = iVar13 + 1) {
      pPktW = (dKankyo_wave_Packet *)((int)pPkt->mpWaveEff + iVar12 + -0x18);
      fVar2 = pPktW->mpWaveEff[0].mBasePos.x + pPktW->mpWaveEff[0].mPos.x;
      fVar3 = pPktW->mpWaveEff[0].mBasePos.y + pPktW->mpWaveEff[0].mPos.y;
      fVar4 = pPktW->mpWaveEff[0].mBasePos.z + pPktW->mpWaveEff[0].mPos.z;
      sin = MSL_C.PPCEABI.bare.H::sin((double)pPktW->mpWaveEff[0].mCounter);
      if (0_0 < (double)(float)sin) {
        scale = (double)(d_kankyo::g_env_light.mWaveScale * pPktW->mpWaveEff[0].mScale);
        strength = pPktW->mpWaveEff[0].mStrengthEnv;
        y = (double)((float)((double)(float)sin * scale) * strength);
        idx_15 = (double)CONCAT44(0x43300000,uVar11 ^ 0x80000000);
        sin = (double)((float)((double)d_kankyo::g_env_light.mWaveScaleBottom * scale) *
                      (strength - (float)(y * (double)(0_00000015 * (float)(idx_15 - _4175)))));
        if (0_0 < y) {
          gx::GXLoadTexObj(&GStack444,0);
          uVar1 = (uint)(255_0 * pPktW->mpWaveEff[0].mStrengthWind);
          idx_15 = (double)(longlong)(int)uVar1;
          local_218 = (_GXColor)((uint)local_218 & 0xffffff00 | uVar1 & 0xff);
          local_228 = local_218;
          gx::GXSetTevKColor(3,&local_228);
          if (0_0 <= pPkt->mSkewDir) {
            scale = -sin - (double)(pPkt->mSkewWidth *
                                   (float)(sin * -(double)(1_2 * pPktW->mpWaveEff[0].mSpeed)));
          }
          else {
            scale = -sin + (double)(pPkt->mSkewWidth *
                                   (float)(sin * -(double)(1_2 * pPktW->mpWaveEff[0].mSpeed)));
          }
          in.x = (float)scale;
          in.y = (float)y;
          in.z = 0_0;
          ::mtx::PSMTXMultVec(&mtx,(cXyz *)&in,(cXyz *)&ret);
          local_19c.x = fVar2 + ret.x;
          local_19c.y = fVar3 + ret.y;
          local_19c.z = fVar4 + ret.z;
          if (0_0 <= pPkt->mSkewDir) {
            scale = sin - (double)(pPkt->mSkewWidth *
                                  (float)(sin * -(double)(1_2 * pPktW->mpWaveEff[0].mSpeed)));
          }
          else {
            scale = sin + (double)(pPkt->mSkewWidth *
                                  (float)(sin * -(double)(1_2 * pPktW->mpWaveEff[0].mSpeed)));
          }
          in.x = (float)scale;
          in.y = (float)y;
          in.z = 0_0;
          ::mtx::PSMTXMultVec(&mtx,(cXyz *)&in,(cXyz *)&ret);
          strength = fVar2 + ret.x;
          fVar5 = fVar3 + ret.y;
          fVar6 = fVar4 + ret.z;
          in.x = (float)sin;
          in.y = 0_0;
          in.z = 0_0;
          ::mtx::PSMTXMultVec(&mtx,(cXyz *)&in,(cXyz *)&ret);
          fVar7 = fVar2 + ret.x;
          fVar8 = fVar3 + ret.y;
          fVar9 = fVar4 + ret.z;
          in.x = (float)-sin;
          in.y = 0_0;
          in.z = 0_0;
          ::mtx::PSMTXMultVec(&mtx,(cXyz *)&in,(cXyz *)&ret);
          sin = (double)local_19c.x;
          scale = (double)local_19c.y;
          y = (double)local_19c.z;
          dVar16 = (double)strength;
          dVar17 = (double)fVar5;
          dVar18 = (double)fVar6;
          dVar19 = (double)fVar7;
          dVar20 = (double)fVar8;
          dVar21 = (double)fVar9;
          dVar22 = (double)(fVar2 + ret.x);
          dVar24 = (double)(fVar3 + ret.y);
          dVar23 = (double)(fVar4 + ret.z);
          if (init_10880 == '\0') {
            local_1ec = 0_0;
            local_1e8 = 0_0;
            local_1e4 = 0_0;
            add_table_10878[0].x = 0_0;
            add_table_10878[0].y = 0_0;
            add_table_10878[0].z = 0_0;
            Runtime.PPCEABI.H::__register_global_object(add_table_10878,::cXyz::_cXyz,&_10879);
            local_1f8 = 800_0;
            local_1f4 = 0_0;
            local_1f0 = 400_0;
            add_table_10878[1].x = 800_0;
            add_table_10878[1].y = 0_0;
            add_table_10878[1].z = 400_0;
            Runtime.PPCEABI.H::__register_global_object(0x803e2640,::cXyz::_cXyz,&_10882);
            local_204 = 600_0;
            local_200 = 0_0;
            local_1fc = 200_0;
            add_table_10878[2].x = 600_0;
            add_table_10878[2].y = 0_0;
            add_table_10878[2].z = 200_0;
            Runtime.PPCEABI.H::__register_global_object(0x803e264c,::cXyz::_cXyz,&_10883);
            local_210 = 200_0;
            local_20c = 0_0;
            local_208 = 800_0;
            add_table_10878[3].x = 200_0;
            add_table_10878[3].y = 0_0;
            add_table_10878[3].z = 800_0;
            Runtime.PPCEABI.H::__register_global_object(0x803e2658,::cXyz::_cXyz,&_10884);
            init_10880 = '\x01';
          }
          gx::GXBegin(0x80,0,4);
          dVar15 = (double)add_table_10878[0].x;
          write_volatile_4(0xcc008000,(float)(sin + dVar15));
          sin = (double)add_table_10878[0].y;
          write_volatile_4(0xcc008000,(float)(scale + sin));
          scale = (double)add_table_10878[0].z;
          write_volatile_4(0xcc008000,(float)(y + scale));
          write_volatile_2(0xcc008000,0);
          write_volatile_2(0xcc008000,0);
          write_volatile_4(0xcc008000,(float)(dVar16 + dVar15));
          write_volatile_4(0xcc008000,(float)(dVar17 + sin));
          write_volatile_4(0xcc008000,(float)(dVar18 + scale));
          write_volatile_2(0xcc008000,0xfa);
          write_volatile_2(0xcc008000,0);
          write_volatile_4(0xcc008000,(float)(dVar19 + dVar15));
          write_volatile_4(0xcc008000,(float)(dVar20 + sin));
          write_volatile_4(0xcc008000,(float)(dVar21 + scale));
          write_volatile_2(0xcc008000,0xfa);
          write_volatile_2(0xcc008000,0xfa);
          write_volatile_4(0xcc008000,(float)(dVar22 + dVar15));
          write_volatile_4(0xcc008000,(float)(dVar24 + sin));
          write_volatile_4(0xcc008000,(float)(dVar23 + scale));
          write_volatile_2(0xcc008000,0);
          write_volatile_2(0xcc008000,0xfa);
        }
      }
      uVar11 = uVar11 + 0x1f;
      iVar12 = iVar12 + 0x38;
    }
    _sOldVcdVatCmd = 0;
  }
  __psq_l0(auStack8,uVar14);
  __psq_l1(auStack8,uVar14);
  __psq_l0(auStack24,uVar14);
  __psq_l1(auStack24,uVar14);
  __psq_l0(auStack40,uVar14);
  __psq_l1(auStack40,uVar14);
  __psq_l0(auStack56,uVar14);
  __psq_l1(auStack56,uVar14);
  __psq_l0(auStack72,uVar14);
  __psq_l1(auStack72,uVar14);
  __psq_l0(auStack88,uVar14);
  __psq_l1(auStack88,uVar14);
  __psq_l0(auStack104,uVar14);
  __psq_l1(auStack104,uVar14);
  __psq_l0(auStack120,uVar14);
  __psq_l1(auStack120,uVar14);
  __psq_l0(auStack136,uVar14);
  __psq_l1(auStack136,uVar14);
  __psq_l0(auStack152,uVar14);
  __psq_l1(auStack152,uVar14);
  __psq_l0(auStack168,uVar14);
  __psq_l1(auStack168,uVar14);
  __psq_l0(auStack184,uVar14);
  __psq_l1(auStack184,uVar14);
  __psq_l0(auStack200,uVar14);
  __psq_l1(auStack200,uVar14);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8009ab60) */
/* WARNING: Removing unreachable block (ram,0x8009ab58) */
/* WARNING: Removing unreachable block (ram,0x8009ab68) */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall drawCloudShadow(float *[][][][],
                             unsigned char * *) */

void drawCloudShadow(MTX34 *param_1,char *param_2)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint3 uVar5;
  dKankyo_cloud_Packet *pdVar6;
  int iVar7;
  dKankyo_cloud_Packet *pEff;
  int iVar8;
  undefined4 uVar9;
  undefined8 in_f29;
  double dVar10;
  undefined8 in_f30;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  _GXColor local_138;
  _GXColor local_134;
  _GXColor local_130;
  undefined4 local_12c;
  _GXColor local_128;
  cXyz local_118;
  cXyz local_10c;
  GXTexObj GStack256;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  MTX34 MStack176;
  MTX34 MStack128;
  longlong local_50;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pdVar6 = d_kankyo::g_env_light.mpMoyaPacket;
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if (init_11077 == '\0') {
    rot_11076 = 0_0;
    init_11077 = '\x01';
  }
  if ((0 < (d_kankyo::g_env_light.mpMoyaPacket)->mCount) &&
     (J3DSys::reinitGX(&J3DGraphBase::j3dSys),
     d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0)) {
    mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                      &MStack128);
    gx::GXSetClipMode(true);
    if ((d_kankyo::g_env_light.mMoyaMode == 3) || (d_kankyo::g_env_light.mMoyaMode == 4)) {
      uVar5 = CONCAT12((char)d_kankyo::g_env_light.mBG3_K0.g,local_128._2_2_);
      local_128._2_2_ = local_128._2_2_ & 0xff | d_kankyo::g_env_light.mBG3_K0.b << 8;
      local_128 = (_GXColor)
                  ((uint)(byte)d_kankyo::g_env_light.mBG3_K0.r << 0x18 | uVar5 & 0xffff0000 |
                  (uint)local_128._2_2_);
      uVar5 = CONCAT12((char)d_kankyo::g_env_light.mBG3_K0.g,local_12c._2_2_);
      local_12c._2_2_ = local_12c._2_2_ & 0xff | d_kankyo::g_env_light.mBG3_K0.b << 8;
      local_12c = (_GXColor)
                  ((uint)(byte)d_kankyo::g_env_light.mBG3_K0.r << 0x18 | uVar5 & 0xffff0000 |
                  (uint)local_12c._2_2_);
    }
    else {
      uVar5 = CONCAT12((char)d_kankyo::g_env_light.mBG0_K0.g,local_128._2_2_);
      local_128._2_2_ = local_128._2_2_ & 0xff | d_kankyo::g_env_light.mBG0_K0.b << 8;
      local_128 = (_GXColor)
                  ((uint)(byte)d_kankyo::g_env_light.mBG0_K0.r << 0x18 | uVar5 & 0xffff0000 |
                  (uint)local_128._2_2_);
      uVar5 = CONCAT12((char)d_kankyo::g_env_light.mBG0_K0.g,local_12c._2_2_);
      local_12c._2_2_ = local_12c._2_2_ & 0xff | d_kankyo::g_env_light.mBG0_K0.b << 8;
      local_12c = (_GXColor)
                  ((uint)(byte)d_kankyo::g_env_light.mBG0_K0.r << 0x18 | uVar5 & 0xffff0000 |
                  (uint)local_12c._2_2_);
    }
    dKyr_set_btitex(&GStack256,*(undefined4 *)param_2);
    gx::GXSetNumChans(0);
    local_130 = local_128;
    gx::GXSetTevColor(GX_TEVREG0,&local_130);
    local_134 = local_12c;
    gx::GXSetTevColor(GX_TEVREG1,&local_134);
    gx::GXSetNumTexGens(1);
    gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
    gx::GXSetNumTevStages(1);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C1,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    d_kankyo::dKy_GxFog_set();
    gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
    gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
    gx::GXSetZMode(false,GX_LEQUAL,false);
    gx::GXSetCullMode(0);
    gx::GXSetNumIndStages(0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,8);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
    mtx::PSMTXRotRad(&MStack176,'Z',_8704 * rot_11076);
    mtx::PSMTXConcat(&MStack128,&MStack176,&MStack128);
    gx::GXLoadPosMtxImm(param_1,0);
    rot_11076 = rot_11076 - 1_5;
    if (rot_11076 < 0_0) {
      rot_11076 = 719_0;
    }
    gx::GXSetCurrentMtx(0);
    iVar7 = 0;
    dVar12 = (double)1_0E_6;
    for (iVar8 = 0; iVar8 < pdVar6->mCount; iVar8 = iVar8 + 1) {
      pEff = (dKankyo_cloud_Packet *)((int)pdVar6->mEff + iVar7 + -0x18);
      dVar10 = (double)pEff->mEff[0].mSize;
      if (dVar12 < (double)pEff->mEff[0].mAlpha) {
        gx::GXLoadTexObj(&GStack256,0);
        uVar1 = (uint)(255_0 * pEff->mEff[0].mAlpha);
        local_50 = (longlong)(int)uVar1;
        local_128 = (_GXColor)((uint)local_128 & 0xffffff00 | uVar1 & 0xff);
        local_138 = local_128;
        gx::GXSetTevColor(GX_TEVREG0,&local_138);
        fVar2 = pEff->mEff[0].mBasePos.x + pEff->mEff[0].mPos.x;
        fVar3 = pEff->mEff[0].mBasePos.y + pEff->mEff[0].mPos.y;
        fVar4 = pEff->mEff[0].mBasePos.z + pEff->mEff[0].mPos.z;
        dVar11 = -dVar10;
        local_10c.x = (float)dVar11;
        local_10c.y = (float)dVar10;
        local_10c.z = 0_0;
        mtx::PSMTXMultVec(&MStack128,&local_10c,&local_118);
        local_e0 = fVar2 + local_118.x;
        local_dc = fVar3 + local_118.y;
        local_d8 = fVar4 + local_118.z;
        local_10c.x = (float)dVar10;
        local_10c.y = (float)dVar10;
        local_10c.z = 0_0;
        mtx::PSMTXMultVec(&MStack128,&local_10c,&local_118);
        local_d4 = fVar2 + local_118.x;
        local_d0 = fVar3 + local_118.y;
        local_cc = fVar4 + local_118.z;
        local_10c.x = (float)dVar10;
        local_10c.y = (float)dVar11;
        local_10c.z = 0_0;
        mtx::PSMTXMultVec(&MStack128,&local_10c,&local_118);
        local_c8 = fVar2 + local_118.x;
        local_c4 = fVar3 + local_118.y;
        local_c0 = fVar4 + local_118.z;
        local_10c.x = (float)dVar11;
        local_10c.y = (float)dVar11;
        local_10c.z = 0_0;
        mtx::PSMTXMultVec(&MStack128,&local_10c,&local_118);
        local_bc = fVar2 + local_118.x;
        local_b8 = fVar3 + local_118.y;
        local_b4 = fVar4 + local_118.z;
        gx::GXBegin(0x80,0,4);
        write_volatile_4(0xcc008000,local_e0);
        write_volatile_4(0xcc008000,local_dc);
        write_volatile_4(0xcc008000,local_d8);
        write_volatile_2(0xcc008000,0);
        write_volatile_2(0xcc008000,0);
        write_volatile_4(0xcc008000,local_d4);
        write_volatile_4(0xcc008000,local_d0);
        write_volatile_4(0xcc008000,local_cc);
        write_volatile_2(0xcc008000,0xff);
        write_volatile_2(0xcc008000,0);
        write_volatile_4(0xcc008000,local_c8);
        write_volatile_4(0xcc008000,local_c4);
        write_volatile_4(0xcc008000,local_c0);
        write_volatile_2(0xcc008000,0xff);
        write_volatile_2(0xcc008000,0xff);
        write_volatile_4(0xcc008000,local_bc);
        write_volatile_4(0xcc008000,local_b8);
        write_volatile_4(0xcc008000,local_b4);
        write_volatile_2(0xcc008000,0);
        write_volatile_2(0xcc008000,0xff);
      }
      iVar7 = iVar7 + 0x4c;
    }
    gx::GXSetClipMode(false);
    _sOldVcdVatCmd = 0;
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  __psq_l0(auStack40,uVar9);
  __psq_l1(auStack40,uVar9);
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Removing unreachable block (ram,0x8009b99c) */
/* WARNING: Removing unreachable block (ram,0x8009b98c) */
/* WARNING: Removing unreachable block (ram,0x8009b97c) */
/* WARNING: Removing unreachable block (ram,0x8009b96c) */
/* WARNING: Removing unreachable block (ram,0x8009b95c) */
/* WARNING: Removing unreachable block (ram,0x8009b94c) */
/* WARNING: Removing unreachable block (ram,0x8009b93c) */
/* WARNING: Removing unreachable block (ram,0x8009b92c) */
/* WARNING: Removing unreachable block (ram,0x8009b3f0) */
/* WARNING: Removing unreachable block (ram,0x8009b934) */
/* WARNING: Removing unreachable block (ram,0x8009b944) */
/* WARNING: Removing unreachable block (ram,0x8009b954) */
/* WARNING: Removing unreachable block (ram,0x8009b964) */
/* WARNING: Removing unreachable block (ram,0x8009b974) */
/* WARNING: Removing unreachable block (ram,0x8009b984) */
/* WARNING: Removing unreachable block (ram,0x8009b994) */
/* WARNING: Removing unreachable block (ram,0x8009b9a4) */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall drawVrkumo(float *[][][][],
                        _GXColor &,
                        unsigned char * *) */

void drawVrkumo(MTX34 *param_1,_GXColor *param_2,uchar *param_3)

{
  uint uVar1;
  int iVar5;
  int iVar2;
  stage_stag_info_class *pStag;
  uint uVar6;
  int iVar7;
  uint kumoIdx;
  uint textureIdx;
  int pass;
  dKankyo_vrkumo_Packet *pKumo;
  undefined4 uVar11;
  double dVar3;
  double alpha;
  double m0;
  double dVar12;
  double x00;
  double y0;
  double z01_;
  double dVar14;
  double x10;
  double y1;
  double z10;
  double y2;
  double m1;
  undefined8 in_f16;
  double dVar17;
  double x01;
  double z01;
  double x11;
  double z11;
  double dVar21;
  double dVar22;
  double dVar4;
  double dVar23;
  undefined8 in_f17;
  double dVar24;
  double size;
  double offs0;
  undefined8 in_f18;
  double dVar5;
  double theta_02;
  double dVar6;
  double theta_03;
  undefined8 in_f19;
  double theta_04;
  undefined8 in_f20;
  double dVar7;
  double theta_05;
  undefined8 in_f21;
  double dVar8;
  undefined8 in_f22;
  double dVar25;
  undefined8 in_f23;
  double rotZ;
  undefined8 in_f24;
  double dVar27;
  undefined8 in_f25;
  double 0_05;
  undefined8 in_f26;
  double dVar9;
  undefined8 in_f27;
  double dVar29;
  undefined8 in_f28;
  double offs1;
  undefined8 in_f29;
  double dist;
  double rot;
  undefined8 in_f30;
  double pitch;
  undefined8 in_f31;
  double farPlane;
  _GXColor local_2e4;
  _GXColor local_2e0;
  _GXColor local_2dc;
  _GXColor local_2d8;
  _GXColor local_2d4;
  cXyz local_2d0;
  cXyz local_2c4;
  cXyz local_2b8;
  cXyz local_2ac;
  cXyz local_2a0;
  cXyz local_294;
  cXyz local_288;
  TVec3_float_ local_270;
  GXTexObj texData;
  TVec3_float_ p0;
  TVec3_float_ p1;
  TVec3_float_ p2;
  TVec3_float_ p3;
  MTX34 MStack532;
  MTX34 MStack484;
  float local_1b0;
  undefined auStack248 [16];
  undefined auStack232 [16];
  undefined auStack216 [16];
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  dKankyo_vrkumo_Packet *pPkt;
  bool bVar4;
  float fVar1;
  float py;
  float pz;
  camera_class *pCamera;
  dKankyo_sun_Packet *pSun;
  float px;
  
  pPkt = d_kankyo::g_env_light.mpVrkumoPacket;
  pSun = d_kankyo::g_env_light.mpSunPacket;
  pCamera = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  uVar11 = 0;
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
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  __psq_st0(auStack216,(int)((ulonglong)in_f18 >> 0x20),0);
  __psq_st1(auStack216,(int)in_f18,0);
  __psq_st0(auStack232,(int)((ulonglong)in_f17 >> 0x20),0);
  __psq_st1(auStack232,(int)in_f17,0);
  __psq_st0(auStack248,(int)((ulonglong)in_f16 >> 0x20),0);
  __psq_st1(auStack248,(int)in_f16,0);
  pass = 1;
  bVar4 = false;
  fVar1 = 0_0;
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera != (camera_class *)0x0) {
    fVar1 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mBody).field_0x5f8;
  }
  dVar17 = (double)fVar1;
  if (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera != (camera_class *)0x0) {
    mtx::PSMTXInverse(&(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mViewMtxNoTrans,
                      &MStack484);
    dVar24 = (double)(_5017 * (float)((double)CONCAT44(0x43300000,(int)pCamera->mBank ^ 0x80000000)
                                     - _4175));
    iVar5 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Name");
    px = 100000_0;
    if ((iVar5 != 0) &&
       (iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                          (0x803c9d58), px = 100000_0, iVar2 != 0)) {
      pStag = (stage_stag_info_class *)
              (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                        (0x803c9d58);
      px = pStag->mFarPlane - 10000_0;
    }
    farPlane = (double)px;
    if ((((pSun != (dKankyo_sun_Packet *)0x0) && (0_0 < pSun->mSunAlpha)) &&
        (m_Do_lib::mDoLib_project(pSun->mPos,(cXyz *)&local_270), 0_0 < local_270.x)) &&
       (((local_270.x < _11659 && (dVar17 < (double)local_270.y)) &&
        ((double)local_270.y < (double)(float)((double)490_0 - dVar17))))) {
      pass = 0;
    }
    if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc & 8U) != 0) {
      pass = 0;
    }
    rotZ = (double)(float)((double)_8704 * dVar24);
    dVar25 = -(double)700_0;
    dVar8 = -(double)400_0;
    dVar29 = (double)_11660;
    0_05 = (double)0_05;
    dVar9 = _4175;
    for (; pass < 2; pass = pass + 1) {
      if (pass == 0) {
        gx::GXSetColorUpdate(false);
        gx::GXSetClipMode(true);
      }
      else {
        gx::GXSetClipMode(false);
      }
      textureIdx = 0;
      iVar2 = 0;
      do {
        param_2->r = (u8)d_kankyo::g_env_light.mVrkumoColor.r;
        param_2->g = (u8)d_kankyo::g_env_light.mVrkumoColor.g;
        param_2->b = (u8)d_kankyo::g_env_light.mVrkumoColor.b;
        local_2d4 = (_GXColor)(uint)(SUB42(local_2d4,0) & 0xff);
        dKyr_set_btitex(&texData,*(undefined4 *)(param_3 + iVar2));
        gx::GXSetNumChans(0);
        local_2d8 = *param_2;
        gx::GXSetTevColor(GX_TEVREG0,&local_2d8);
        local_2dc = local_2d4;
        gx::GXSetTevColor(GX_TEVREG1,&local_2dc);
        gx::GXSetNumTexGens(1);
        gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
        gx::GXSetNumTevStages(1);
        gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
        gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C1,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
        gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
        gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        local_2e0 = *param_2;
        gx::GXSetFog(GX_FOG_NONE,0_0,1_0,0_1,1_0,&local_2e0);
        gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
        gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
        if (pass == 0) {
          gx::GXSetZCompLoc(0);
          gx::GXSetZMode(true,GX_LEQUAL,true);
        }
        else {
          gx::GXSetZCompLoc(1);
          gx::GXSetZMode(false,GX_LEQUAL,false);
        }
        gx::GXSetNumIndStages(0);
        gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
        gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGBA4,8);
        gx::GXClearVtxDesc();
        gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
        gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
        if ((pass == 1) && (textureIdx == 0)) {
          mtx::PSMTXRotRad(&MStack532,'Z',(float)rotZ);
          mtx::PSMTXConcat(&MStack484,&MStack532,&MStack484);
        }
        gx::GXLoadPosMtxImm(param_1,0);
        gx::GXSetCurrentMtx(0);
        kumoIdx = 0;
        iVar7 = 0;
        dVar27 = (double)(float)(0_05 * (double)(float)((double)CONCAT44(0x43300000,
                                                                         textureIdx ^ 0x80000000) -
                                                       dVar9));
        do {
          pKumo = (dKankyo_vrkumo_Packet *)((int)pPkt->mInst + iVar7 + -0x20);
          alpha = (double)pKumo->mInst[0].mAlpha;
          if ((dVar29 < alpha) && ((pass != 0 || ((double)0_2 <= alpha)))) {
            if ((-6000 < pCamera->field_0x230) &&
               (40_0 < (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera)->mFovY)) {
              ::cXyz::operator__(&local_2d0,&pCamera->mEyePos,(cXyz *)&pKumo->mInst[0].mPosition);
              local_2c4.x = local_2d0.x;
              local_2c4.y = local_2d0.y;
              local_2c4.z = local_2d0.z;
              m_Do_lib::mDoLib_project(&local_2c4,(cXyz *)&local_270);
              if (((((double)local_270.x <= dVar25) || ((double)_11661 <= (double)local_270.x)) ||
                  ((double)local_270.y <= dVar8)) || ((double)_11662 <= (double)local_270.y))
              goto LAB_8009b8dc;
            }
            dVar5 = (double)((float)((double)CONCAT44(0x43300000,
                                                      textureIdx + kumoIdx & 0xf ^ 0x80000000) -
                                    _4175) * 0_0625);
            if (init_11255 == '\0') {
              howa_loop_cnt_11254 = 0_0;
              init_11255 = '\x01';
            }
            size = (double)(pKumo->mInst[0].mDistFalloff *
                           (1_0 - (float)(dVar5 * (double)(float)(dVar5 * dVar5))) *
                           (0_45 + d_kankyo::g_env_light.mVrkumoStrength * 0_55));
            uVar6 = SComponent::cM_rad2s
                              ((double)((float)((double)CONCAT44(0x43300000,textureIdx ^ 0x80000000)
                                               - _4175) + 0_0001 * howa_loop_cnt_11254));
            dVar7 = _4175;
            if (!bVar4) {
              howa_loop_cnt_11254 = howa_loop_cnt_11254 + 200_0 + (float)((double)0_8 * dVar5);
              bVar4 = true;
            }
            dVar5 = (double)(float)(size + (double)((float)((double)0_06 * size) *
                                                   JKernel::JMath::jmaSinTable
                                                   [(int)(uVar6 & 0xffff) >>
                                                    (JKernel::JMath::jmaSinShift & 0x3f)] *
                                                   pKumo->mInst[0].mDistFalloff));
            x00 = (double)(float)(dVar5 + (double)(float)(dVar5 * (double)pKumo->mInst[0].mHeight));
            if (pass == 0) {
              param_2->a = 1;
            }
            else {
              dVar6 = (double)(1_0 - pKumo->mInst[0].mDistFalloff);
              if ((double)0_1 < dVar6) {
                dVar6 = (double)(float)(dVar6 - dVar27);
              }
              param_2->r = (u8)(int)((float)((double)CONCAT44(0x43300000,
                                                              (int)d_kankyo::g_env_light.
                                                                   mVrkumoCenterColor.r ^
                                                              0x80000000U) - _4175) +
                                    (float)(dVar6 * (double)((float)((double)CONCAT44(0x43300000,
                                                                                      (int)d_kankyo
                                                  ::g_env_light.mVrkumoColor.r ^ 0x80000000) - _4175
                                                  ) - (float)((double)CONCAT44(0x43300000,
                                                                               (int)d_kankyo::
                                                                                    g_env_light.
                                                                                                                                                                        
                                                  mVrkumoCenterColor.r ^ 0x80000000U) - _4175))));
              param_2->g = (u8)(int)((float)((double)CONCAT44(0x43300000,
                                                              (int)d_kankyo::g_env_light.
                                                                   mVrkumoCenterColor.g ^
                                                              0x80000000U) - dVar7) +
                                    (float)(dVar6 * (double)((float)((double)CONCAT44(0x43300000,
                                                                                      (int)d_kankyo
                                                  ::g_env_light.mVrkumoColor.g ^ 0x80000000) - dVar7
                                                  ) - (float)((double)CONCAT44(0x43300000,
                                                                               (int)d_kankyo::
                                                                                    g_env_light.
                                                                                                                                                                        
                                                  mVrkumoCenterColor.g ^ 0x80000000U) - dVar7))));
              param_2->b = (u8)(int)((float)((double)CONCAT44(0x43300000,
                                                              (int)d_kankyo::g_env_light.
                                                                   mVrkumoCenterColor.b ^
                                                              0x80000000U) - dVar7) +
                                    (float)(dVar6 * (double)((float)((double)CONCAT44(0x43300000,
                                                                                      (int)d_kankyo
                                                  ::g_env_light.mVrkumoColor.b ^ 0x80000000) - dVar7
                                                  ) - (float)((double)CONCAT44(0x43300000,
                                                                               (int)d_kankyo::
                                                                                    g_env_light.
                                                                                                                                                                        
                                                  mVrkumoCenterColor.b ^ 0x80000000U) - dVar7))));
              param_2->a = (u8)(int)(255_0 * pKumo->mInst[0].mAlpha);
            }
            if (1_0E_6 < pKumo->mInst[0].mAlpha) {
              gx::GXLoadTexObj(&texData,0);
              local_2e4 = *param_2;
              gx::GXSetTevColor(GX_TEVREG0,&local_2e4);
              m0 = (double)(float)((double)0_15 * dVar5);
              m1 = (double)(float)((double)0_25 * dVar5);
              px = pKumo->mInst[0].mPosition.x;
              py = pKumo->mInst[0].mPosition.y;
              pz = pKumo->mInst[0].mPosition.z;
              theta_02 = (double)0_0;
              dVar7 = theta_02;
              dVar6 = theta_02;
              if (textureIdx != 0) {
                uVar1 = kumoIdx & 3;
                if (uVar1 == 1) {
                  if (textureIdx == 1) {
                    dVar7 = -m0;
                    dVar6 = m0;
                  }
                  else {
                    if (textureIdx == 2) {
                      dVar7 = -m1;
                      dVar6 = m1;
                    }
                  }
                }
                else {
                  if (uVar1 == 0) {
                    dVar7 = m0;
                    dVar6 = m1;
                    if ((textureIdx != 1) && (dVar7 = theta_02, dVar6 = theta_02, textureIdx == 2))
                    {
                      dVar7 = m1;
                      dVar6 = m0;
                    }
                  }
                  else {
                    if (uVar1 < 3) {
                      if (textureIdx == 1) {
                        dVar7 = m1;
                        dVar6 = -m0;
                      }
                      else {
                        if (textureIdx == 2) {
                          dVar7 = m0;
                          dVar6 = -m1;
                        }
                      }
                    }
                    else {
                      if (textureIdx == 1) {
                        dVar7 = -m1;
                        dVar6 = m1;
                      }
                      else {
                        if (textureIdx == 2) {
                          dVar7 = -m0;
                          dVar6 = m0;
                        }
                      }
                    }
                  }
                }
              }
              dist = (double)(px * px + pz * pz);
              if ((double)0_0 < dist) {
                dVar3 = 1.0 / SQRT(dist);
                dVar3 = 0_5 * dVar3 * (3_0 - dist * dVar3 * dVar3);
                dVar3 = 0_5 * dVar3 * (3_0 - dist * dVar3 * dVar3);
                dist = (double)(float)(dist * 0_5 * dVar3 * (3_0 - dist * dVar3 * dVar3));
              }
              dVar3 = MSL_C.PPCEABI.bare.H::atan2((double)px,(double)pz);
              dVar3 = (double)(float)dVar3;
              dist = MSL_C.PPCEABI.bare.H::atan2((double)py,dist);
              rot = (double)(float)(dVar3 + dVar6);
              pitch = (double)(float)((double)(float)dist + dVar7);
              px = (float)(pitch / (double)1_9);
              if (1_0 < (float)(pitch / (double)1_9)) {
                px = 1_0;
              }
              px = px * px * px;
              offs0 = (double)((float)((double)0_6 * dVar5) * (1_0 + 16_0 * px));
              offs1 = (double)((float)((double)0_6 * dVar5) * (1_0 + 2_0 * px));
              dVar6 = (double)(float)(rot + offs0);
              dVar5 = (double)(float)(pitch + (double)((float)((double)0_9 * x00) *
                                                      (1_0 + _4_0 * px)));
              dVar7 = dVar5;
              if ((double)1_21 < dVar5) {
                dVar7 = (double)1_21;
              }
              dVar12 = MSL_C.PPCEABI.bare.H::sin(dVar6);
              x01 = (double)(float)dVar12;
              x00 = MSL_C.PPCEABI.bare.H::cos(dVar7);
              y0 = MSL_C.PPCEABI.bare.H::sin(dVar7);
              dVar6 = MSL_C.PPCEABI.bare.H::cos(dVar6);
              z01 = (double)(float)dVar6;
              z01_ = MSL_C.PPCEABI.bare.H::cos(dVar7);
              dVar7 = (double)(float)(rot - offs0);
              if ((double)1_21 < dVar5) {
                dVar5 = (double)1_21;
              }
              dVar14 = MSL_C.PPCEABI.bare.H::sin(dVar7);
              x11 = (double)(float)dVar14;
              x10 = MSL_C.PPCEABI.bare.H::cos(dVar5);
              y1 = MSL_C.PPCEABI.bare.H::sin(dVar5);
              dVar7 = MSL_C.PPCEABI.bare.H::cos(dVar7);
              z11 = (double)(float)dVar7;
              z10 = MSL_C.PPCEABI.bare.H::cos(dVar5);
              theta_05 = (double)(float)(rot - offs1);
              theta_04 = (double)(float)(pitch - (double)0_0);
              dVar5 = MSL_C.PPCEABI.bare.H::sin(theta_05);
              dVar21 = (double)(float)dVar5;
              dVar5 = MSL_C.PPCEABI.bare.H::cos(theta_04);
              y2 = MSL_C.PPCEABI.bare.H::sin(theta_04);
              dVar7 = MSL_C.PPCEABI.bare.H::cos(theta_05);
              dVar22 = (double)(float)dVar7;
              dVar7 = MSL_C.PPCEABI.bare.H::cos(theta_04);
              dVar3 = (double)(float)(rot + offs1);
              theta_03 = (double)(float)(pitch - (double)0_0);
              dVar6 = MSL_C.PPCEABI.bare.H::sin(dVar3);
              dVar4 = (double)(float)dVar6;
              dVar6 = MSL_C.PPCEABI.bare.H::cos(theta_03);
              dist = MSL_C.PPCEABI.bare.H::sin(theta_03);
              dVar3 = MSL_C.PPCEABI.bare.H::cos(dVar3);
              dVar23 = (double)(float)dVar3;
              dVar3 = MSL_C.PPCEABI.bare.H::cos(theta_03);
              p0.x = (float)((double)(float)((double)(float)x00 * x01) * farPlane);
              p0.y = (float)((double)(float)y0 * farPlane);
              p0.z = (float)((double)(float)((double)(float)z01_ * z01) * farPlane);
              p1.x = (float)((double)(float)((double)(float)x10 * x11) * farPlane);
              p1.y = (float)((double)(float)y1 * farPlane);
              p1.z = (float)((double)(float)((double)(float)z10 * z11) * farPlane);
              p2.x = (float)((double)(float)((double)(float)dVar5 * dVar21) * farPlane);
              p2.y = (float)((double)(float)y2 * farPlane);
              p2.z = (float)((double)(float)((double)(float)dVar7 * dVar22) * farPlane);
              p3.x = (float)((double)(float)((double)(float)dVar6 * dVar4) * farPlane);
              p3.y = (float)((double)(float)dist * farPlane);
              p3.z = (float)((double)(float)((double)(float)dVar3 * dVar23) * farPlane);
              mtx::PSVECAdd((cXyz *)&p0,&pCamera->mEyePos,(cXyz *)&p0);
              mtx::PSVECAdd((cXyz *)&p1,&pCamera->mEyePos,(cXyz *)&p1);
              mtx::PSVECAdd((cXyz *)&p2,&pCamera->mEyePos,(cXyz *)&p2);
              mtx::PSVECAdd((cXyz *)&p3,&pCamera->mEyePos,(cXyz *)&p3);
              gx::GXBegin(0x80,0,4);
              write_volatile_4(0xcc008000,p0.x);
              write_volatile_4(0xcc008000,p0.y);
              write_volatile_4(0xcc008000,p0.z);
              write_volatile_2(0xcc008000,0);
              write_volatile_2(0xcc008000,0);
              write_volatile_4(0xcc008000,p1.x);
              write_volatile_4(0xcc008000,p1.y);
              write_volatile_4(0xcc008000,p1.z);
              write_volatile_2(0xcc008000,0xff);
              write_volatile_2(0xcc008000,0);
              write_volatile_4(0xcc008000,p2.x);
              write_volatile_4(0xcc008000,p2.y);
              write_volatile_4(0xcc008000,p2.z);
              write_volatile_2(0xcc008000,0xff);
              write_volatile_2(0xcc008000,0xff);
              write_volatile_4(0xcc008000,p3.x);
              write_volatile_4(0xcc008000,p3.y);
              write_volatile_4(0xcc008000,p3.z);
              write_volatile_2(0xcc008000,0);
              write_volatile_2(0xcc008000,0xff);
            }
          }
LAB_8009b8dc:
          kumoIdx = kumoIdx + 1;
          iVar7 = iVar7 + 0x2c;
        } while ((int)kumoIdx < 100);
        textureIdx = textureIdx + 1;
        iVar2 = iVar2 + 4;
      } while ((int)textureIdx < 3);
      if (pass == 0) {
        gx::GXSetColorUpdate(true);
      }
    }
    gx::GXSetClipMode(false);
    d_kankyo::dKy_GxFog_set();
    _sOldVcdVatCmd = 0;
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  __psq_l0(auStack40,uVar11);
  __psq_l1(auStack40,uVar11);
  __psq_l0(auStack56,uVar11);
  __psq_l1(auStack56,uVar11);
  __psq_l0(auStack72,uVar11);
  __psq_l1(auStack72,uVar11);
  __psq_l0(auStack88,uVar11);
  __psq_l1(auStack88,uVar11);
  __psq_l0(auStack104,uVar11);
  __psq_l1(auStack104,uVar11);
  __psq_l0(auStack120,uVar11);
  __psq_l1(auStack120,uVar11);
  __psq_l0(auStack136,uVar11);
  __psq_l1(auStack136,uVar11);
  __psq_l0(auStack152,uVar11);
  __psq_l1(auStack152,uVar11);
  __psq_l0(auStack168,uVar11);
  __psq_l1(auStack168,uVar11);
  __psq_l0(auStack184,uVar11);
  __psq_l1(auStack184,uVar11);
  __psq_l0(auStack200,uVar11);
  __psq_l1(auStack200,uVar11);
  __psq_l0(auStack216,uVar11);
  __psq_l1(auStack216,uVar11);
  __psq_l0(auStack232,uVar11);
  __psq_l1(auStack232,uVar11);
  __psq_l0(auStack248,uVar11);
  __psq_l1(auStack248,uVar11);
  return;
}


/* __stdcall dKyr_thunder_init(void) */

void dKyr_thunder_init(void)

{
  d_kankyo::g_env_light.mThunderStateTimer = 0;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8009ba1c) */
/* __stdcall dKyr_thunder_move(void) */

void dKyr_thunder_move(void)

{
  float fVar1;
  camera_class *pCamera;
  
  pCamera = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  if (d_kankyo::g_env_light.mThunderStateTimer == 2) {
LAB_8009bb7c:
    SComponent::cLib_addCalc(&d_kankyo::g_env_light.mThunderFlashTimer,0_0,0_1,0_05,0_001);
    if (d_kankyo::g_env_light.mThunderFlashTimer <= 0_0) {
      if (d_kankyo::g_env_light.mThunderStateTimer < 10) {
        d_kankyo::dKy_efplight_cut(&d_kankyo::g_env_light.mThunderLightInfluence);
      }
      d_kankyo::g_env_light.mThunderStateTimer = 0;
      if (d_kankyo::g_env_light.mThunderMode == 0) {
        d_kankyo::g_env_light.mbThunderActive = false;
      }
    }
  }
  else {
    if (d_kankyo::g_env_light.mThunderStateTimer < 2) {
      if (d_kankyo::g_env_light.mThunderStateTimer == 0) {
        d_kankyo::g_env_light.mThunderFlashTimer = 0_0;
        d_kankyo::g_env_light.field_0xa3c = 0_0;
        d_kankyo::g_env_light.field_0xa40 = 0_0;
        fVar1 = SComponent::cM_rndF(1_0);
        if (0_007 <= fVar1) {
          fVar1 = SComponent::cM_rndF(1_0);
          if ((fVar1 < 0_005) && ((int)d_kankyo::g_env_light.mThunderMode < 10)) {
            d_kankyo::g_env_light.mThunderLightInfluence.mPos.x = (pCamera->mEyePos).x;
            d_kankyo::g_env_light.mThunderLightInfluence.mPos.y = (pCamera->mEyePos).y;
            d_kankyo::g_env_light.mThunderLightInfluence.mPos.z = (pCamera->mEyePos).z;
            d_kankyo::g_env_light.mThunderLightInfluence.mColor.r = 0;
            d_kankyo::g_env_light.mThunderLightInfluence.mColor.g = 0;
            d_kankyo::g_env_light.mThunderLightInfluence.mColor.b = 0;
            d_kankyo::g_env_light.mThunderLightInfluence.mPower = 90000_0;
            d_kankyo::g_env_light.mThunderLightInfluence.mFluctuation = 150_0;
            d_kankyo::dKy_efplight_set(&d_kankyo::g_env_light.mThunderLightInfluence);
            d_kankyo::g_env_light.mThunderStateTimer = d_kankyo::g_env_light.mThunderStateTimer + 1;
          }
        }
        else {
          d_kankyo::g_env_light.mThunderStateTimer = 0xb;
        }
        goto LAB_8009bbdc;
      }
    }
    else {
      if (d_kankyo::g_env_light.mThunderStateTimer == 0xc) goto LAB_8009bb7c;
      if ((0xb < d_kankyo::g_env_light.mThunderStateTimer) ||
         (d_kankyo::g_env_light.mThunderStateTimer < 0xb)) goto LAB_8009bbdc;
    }
    SComponent::cLib_addCalc(&d_kankyo::g_env_light.mThunderFlashTimer,1_0,0_3,0_2,0_001);
    if (1_0 <= d_kankyo::g_env_light.mThunderFlashTimer) {
      if (d_kankyo::g_env_light.mThunderStateTimer < 10) {
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x69f7,(cXyz *)0x0,0,0,1_0,1_0,_1_0,_1_0,0);
      }
      d_kankyo::g_env_light.mThunderStateTimer = d_kankyo::g_env_light.mThunderStateTimer + 1;
    }
    fVar1 = SComponent::cM_rndF(1_0);
    if (fVar1 < 0_18) {
      f_op_kankyo_mng::fopKyM_create(0x1b9,0xffffffff,0,0,0);
    }
  }
LAB_8009bbdc:
  if (d_kankyo::g_env_light.mThunderStateTimer != 0) {
    if (d_kankyo::g_env_light.mThunderStateTimer < 10) {
      d_kankyo::g_env_light.mThunderLightInfluence.mPos.x = (pCamera->mEyePos).x;
      d_kankyo::g_env_light.mThunderLightInfluence.mPos.y = 150_0 + (pCamera->mEyePos).y;
      d_kankyo::g_env_light.mThunderLightInfluence.mPos.z = (pCamera->mEyePos).z;
      fVar1 = 0_2 * d_kankyo::g_env_light.mThunderFlashTimer;
      d_kankyo::g_env_light.mThunderLightInfluence.mColor.r = (ushort)(int)(180_0 * fVar1) & 0xff;
      d_kankyo::g_env_light.mThunderLightInfluence.mColor.g = (ushort)(int)(235_0 * fVar1) & 0xff;
      d_kankyo::g_env_light.mThunderLightInfluence.mColor.b = (ushort)(int)(255_0 * fVar1) & 0xff;
      if (d_kankyo::g_env_light.field_0xc98 == 0) {
        d_kankyo::dKy_actor_addcol_amb_set
                  ((double)(0_5 * d_kankyo::g_env_light.mThunderFlashTimer),0x5a,0xa0,0xf5);
        d_kankyo::dKy_actor_addcol_dif_set
                  ((double)(0_5 * d_kankyo::g_env_light.mThunderFlashTimer),0x5a,0xa0,0xf5);
        d_kankyo::dKy_bg_addcol_amb_set
                  ((double)(0_7 * d_kankyo::g_env_light.mThunderFlashTimer),0x32,0x78,0xff);
        d_kankyo::dKy_bg_addcol_dif_set
                  ((double)(0_7 * d_kankyo::g_env_light.mThunderFlashTimer),0x32,0x78,0xff);
        d_kankyo::dKy_bg1_addcol_amb_set
                  ((double)(0_35 * d_kankyo::g_env_light.mThunderFlashTimer),0x5a,0xa0,0xf5);
        d_kankyo::dKy_bg1_addcol_dif_set
                  ((double)(0_35 * d_kankyo::g_env_light.mThunderFlashTimer),0x5a,0xa0,0xf5);
        d_kankyo::dKy_vrbox_addcol_sky0_set
                  (0x5a,0xa0,0xf5,(double)(0_4 * d_kankyo::g_env_light.mThunderFlashTimer));
        d_kankyo::dKy_vrbox_addcol_kasumi_set
                  (0x5a,0xa0,0xf5,(double)(0_5 * d_kankyo::g_env_light.mThunderFlashTimer));
        d_kankyo::dKy_addcol_fog_set
                  ((double)(0_3 * d_kankyo::g_env_light.mThunderFlashTimer),0x5a,0xa0,0xf5);
      }
    }
    else {
      d_kankyo::dKy_vrbox_addcol_sky0_set
                (0x5a,0xa0,0xf5,(double)(0_15 * d_kankyo::g_env_light.mThunderFlashTimer));
      d_kankyo::dKy_vrbox_addcol_kasumi_set
                (0x5a,0xa0,0xf5,(double)(0_35 * d_kankyo::g_env_light.mThunderFlashTimer));
      d_kankyo::dKy_addcol_fog_set
                ((double)(_11887 * d_kankyo::g_env_light.mThunderFlashTimer),0x5a,0xa0,0xf5);
    }
  }
  return;
}

}

/* [thunk]:__thiscall dBgS_ObjGndChk_All::~dBgS_ObjGndChk_All(void) */

void __thiscall dBgS_ObjGndChk_All::_dBgS_ObjGndChk_All(dBgS_ObjGndChk_All *this)

{
  _dBgS_ObjGndChk_All(this + -0x14);
  return;
}


/* [thunk]:__thiscall dBgS_ObjGndChk_All::~dBgS_ObjGndChk_All(void) */

void __thiscall dBgS_ObjGndChk_All::_dBgS_ObjGndChk_All(dBgS_ObjGndChk_All *this)

{
  _dBgS_ObjGndChk_All(this + -0x4c);
  return;
}


/* [thunk]:__thiscall dBgS_ObjGndChk_All::~dBgS_ObjGndChk_All(void) */

void __thiscall dBgS_ObjGndChk_All::_dBgS_ObjGndChk_All(dBgS_ObjGndChk_All *this)

{
  _dBgS_ObjGndChk_All(this + -0x40);
  return;
}


/* [thunk]:__thiscall dBgS_RoofChk::~dBgS_RoofChk(void) */

void __thiscall dBgS_RoofChk::_dBgS_RoofChk(dBgS_RoofChk *this)

{
  _dBgS_RoofChk((dBgS_RoofChk *)&this[-1].mDChk.mGrpPassChk.parent.mAttr);
  return;
}


/* [thunk]:__thiscall dBgS_RoofChk::~dBgS_RoofChk(void) */

void __thiscall dBgS_RoofChk::_dBgS_RoofChk(dBgS_RoofChk *this)

{
  _dBgS_RoofChk((dBgS_RoofChk *)&this[-1].mChk.mpGrpPassChk);
  return;
}


/* [thunk]:__thiscall dBgS_RoofChk::~dBgS_RoofChk(void) */

void __thiscall dBgS_RoofChk::_dBgS_RoofChk(dBgS_RoofChk *this)

{
  _dBgS_RoofChk((dBgS_RoofChk *)&this[-1].mChk.vtbl);
  return;
}


/* __thiscall dSnap_Obj::~dSnap_Obj(void) */

void __thiscall dSnap_Obj::_dSnap_Obj(dSnap_Obj *this)

{
  short in_r4;
  
  if ((this != (dSnap_Obj *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

