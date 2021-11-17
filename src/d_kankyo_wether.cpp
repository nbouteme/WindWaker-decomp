#include <d_kankyo_wether.h>
#include <J3DGraphBase/J3DDrawBuffer.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_drawlist.h>
#include <d_kankyo_rain.h>
#include <JKernel/JKRHeap.h>
#include <d_kankyo_wether.h>
#include <JPABase/JPAEmitter.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <m_Do_mtx.h>
#include <d_stage.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <m_Do_ext.h>
#include <d_resorce.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <JAZelAudio/JAIZelAtmos.h>
#include <d_kankyo.h>
#include <SComponent/c_lib.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <mtx/vec.h>
#include <SComponent/c_math.h>
#include <SComponent/c_xyz.h>
#include <dKankyo_vrkumo_Packet.h>
#include <KAMOME_EFF.h>
#include <cXyz.h>
#include <SNOW_EFF.h>
#include <dKankyo_sun_Packet.h>
#include <RAIN_EFF.h>
#include <HOUSI_EFF.h>
#include <dKankyo_sunlenz_Packet.h>
#include <WAVE_EFF.h>
#include <CLOUD_EFF.h>
#include <dKankyo_snow_Packet.h>
#include <dKankyo_housi_Packet.h>
#include <POISON_EFF.h>
#include <VRKUMO_EFF.h>
#include <dKankyo_star_Packet.h>
#include <dKankyo_rain_Packet.h>
#include <dKankyo_poison_Packet.h>
#include <dKankyo_cloud_Packet.h>
#include <dKankyo_wave_Packet.h>
#include <STAR_EFF.h>
#include <WIND_EFF.h>


namespace d_kankyo_wether {
struct cXyz r09o$5110;
undefined1 init$5112;

/* __stdcall dKyw_setDrawPacketList(J3DPacket *,
                                    int) */

J3DPacket * dKyw_setDrawPacketList(J3DPacket *param_1,int param_2)

{
  if (param_1 == (J3DPacket *)0x0) {
    param_1 = (J3DPacket *)0x0;
  }
  else {
    J3DDrawBuffer::entryImm(d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpWetherFxBuffer,param_1,0)
    ;
  }
  return param_1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dKyw_setDrawPacketListSky(J3DPacket *,
                                       int) */

void dKyw_setDrawPacketListSky(J3DPacket *param_1,int param_2)

{
  if (param_1 != (J3DPacket *)0x0) {
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufSkyOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufSkyXlu;
    J3DDrawBuffer::entryImm(J3DGraphBase::j3dSys.mpCurDrawBuffers[param_2],param_1,0);
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dKyw_setDrawPacketListXluBg(J3DPacket *,
                                         int) */

J3DPacket * dKyw_setDrawPacketListXluBg(J3DPacket *param_1,int param_2)

{
  if (param_1 == (J3DPacket *)0x0) {
    param_1 = (J3DPacket *)0x0;
  }
  else {
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufWorldXlu;
    J3DDrawBuffer::entryImm(J3DGraphBase::j3dSys.mpCurDrawBuffers[param_2],param_1,0);
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  }
  return param_1;
}


/* __stdcall dKyw_setDrawPacketListXluZPos(J3DPacket *,
                                           cXyz *) */

J3DPacket * dKyw_setDrawPacketListXluZPos(J3DPacket *param_1,cXyz *param_2)

{
  if (param_1 == (J3DPacket *)0x0) {
    param_1 = (J3DPacket *)0x0;
  }
  else {
    dDlst_list_c::entryZSortXluDrawList
              (&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
               d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu,param_1,param_2);
  }
  return param_1;
}

}

/* __thiscall dKankyo_sun_Packet::draw(void) */

void __thiscall dKankyo_sun_Packet::draw(dKankyo_sun_Packet *this)

{
  d_kankyo_rain::dKyr_drawSun
            (&J3DGraphBase::j3dSys,this->mPos,&this->mColor,(byte **)this->mpTextureData);
  return;
}


/* __thiscall dKankyo_sunlenz_Packet::draw(void) */

void __thiscall dKankyo_sunlenz_Packet::draw(dKankyo_sunlenz_Packet *this)

{
  d_kankyo_rain::dKyr_drawLenzflare
            (&J3DGraphBase::j3dSys,this->mPositions,&this->mColorTmp,&this->mpTexSnow01);
  return;
}


/* __thiscall RAIN_EFF::~RAIN_EFF(void) */

void __thiscall RAIN_EFF::_RAIN_EFF(RAIN_EFF *this)

{
  short in_r4;
  
  if ((this != (RAIN_EFF *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall RAIN_EFF::RAIN_EFF(void) */

void __thiscall RAIN_EFF::RAIN_EFF(RAIN_EFF *this)

{
  return;
}


/* __thiscall dKankyo_rain_Packet::draw(void) */

void __thiscall dKankyo_rain_Packet::draw(dKankyo_rain_Packet *this)

{
  d_kankyo_rain::dKyr_drawSibuki(&J3DGraphBase::j3dSys,&this->mpTxSnow01);
  d_kankyo_rain::dKyr_drawRain(&J3DGraphBase::j3dSys,&this->mpTxSnow01);
  return;
}


/* __thiscall SNOW_EFF::~SNOW_EFF(void) */

void __thiscall SNOW_EFF::_SNOW_EFF(SNOW_EFF *this)

{
  short in_r4;
  
  if ((this != (SNOW_EFF *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall SNOW_EFF::SNOW_EFF(void) */

void __thiscall SNOW_EFF::SNOW_EFF(SNOW_EFF *this)

{
  return;
}


/* __thiscall dKankyo_snow_Packet::draw(void) */

void __thiscall dKankyo_snow_Packet::draw(dKankyo_snow_Packet *this)

{
  d_kankyo_rain::dKyr_drawSnow(&J3DGraphBase::j3dSys,&this->mpTexture);
  return;
}


/* __thiscall STAR_EFF::~STAR_EFF(void) */

void __thiscall STAR_EFF::_STAR_EFF(STAR_EFF *this)

{
  short in_r4;
  
  if ((this != (STAR_EFF *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall STAR_EFF::STAR_EFF(void) */

void __thiscall STAR_EFF::STAR_EFF(STAR_EFF *this)

{
  return;
}


/* __thiscall dKankyo_star_Packet::draw(void) */

void __thiscall dKankyo_star_Packet::draw(dKankyo_star_Packet *this)

{
  d_kankyo_rain::dKyr_drawStar(&J3DGraphBase::j3dSys.mCurViewMtx,(char *)&this->field_0x10);
  return;
}


/* __thiscall POISON_EFF::~POISON_EFF(void) */

void __thiscall POISON_EFF::_POISON_EFF(POISON_EFF *this)

{
  short in_r4;
  
  if ((this != (POISON_EFF *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall POISON_EFF::POISON_EFF(void) */

void __thiscall POISON_EFF::POISON_EFF(POISON_EFF *this)

{
  return;
}


/* __thiscall dKankyo_poison_Packet::draw(void) */

void __thiscall dKankyo_poison_Packet::draw(dKankyo_poison_Packet *this)

{
  d_kankyo_rain::drawPoison(&J3DGraphBase::j3dSys,this + 0xbbac);
  return;
}


/* __thiscall CLOUD_EFF::~CLOUD_EFF(void) */

void __thiscall CLOUD_EFF::_CLOUD_EFF(CLOUD_EFF *this)

{
  short in_r4;
  
  if ((this != (CLOUD_EFF *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall CLOUD_EFF::CLOUD_EFF(void) */

void __thiscall CLOUD_EFF::CLOUD_EFF(CLOUD_EFF *this)

{
  return;
}


/* __thiscall dKankyo_cloud_Packet::draw(void) */

void __thiscall dKankyo_cloud_Packet::draw(dKankyo_cloud_Packet *this)

{
  d_kankyo_rain::drawCloudShadow(&J3DGraphBase::j3dSys,(char *)&this->mpTexture);
  return;
}


/* __thiscall HOUSI_EFF::~HOUSI_EFF(void) */

void __thiscall HOUSI_EFF::_HOUSI_EFF(HOUSI_EFF *this)

{
  short in_r4;
  
  if ((this != (HOUSI_EFF *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall HOUSI_EFF::HOUSI_EFF(void) */

void __thiscall HOUSI_EFF::HOUSI_EFF(HOUSI_EFF *this)

{
  return;
}


/* __thiscall dKankyo_housi_Packet::draw(void) */

void __thiscall dKankyo_housi_Packet::draw(dKankyo_housi_Packet *this)

{
  d_kankyo_rain::dKyr_drawHousi(&J3DGraphBase::j3dSys.mCurViewMtx,(char *)&this->mpTex);
  return;
}


/* __thiscall VRKUMO_EFF::~VRKUMO_EFF(void) */

void __thiscall VRKUMO_EFF::_VRKUMO_EFF(VRKUMO_EFF *this)

{
  short in_r4;
  
  if ((this != (VRKUMO_EFF *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall VRKUMO_EFF::VRKUMO_EFF(void) */

void __thiscall VRKUMO_EFF::VRKUMO_EFF(VRKUMO_EFF *this)

{
  return;
}


/* __thiscall dKankyo_vrkumo_Packet::draw(void) */

void __thiscall dKankyo_vrkumo_Packet::draw(dKankyo_vrkumo_Packet *this)

{
  d_kankyo_rain::drawVrkumo
            (&J3DGraphBase::j3dSys.mCurViewMtx,&this->mColorTmp,(uchar *)&this->mpCloudTx1);
  return;
}


/* __thiscall WAVE_EFF::~WAVE_EFF(void) */

void __thiscall WAVE_EFF::_WAVE_EFF(WAVE_EFF *this)

{
  short in_r4;
  
  if ((this != (WAVE_EFF *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall WAVE_EFF::WAVE_EFF(void) */

void __thiscall WAVE_EFF::WAVE_EFF(WAVE_EFF *this)

{
  return;
}


/* __thiscall dKankyo_wave_Packet::draw(void) */

void __thiscall dKankyo_wave_Packet::draw(dKankyo_wave_Packet *this)

{
  d_kankyo_rain::drawWave(&J3DGraphBase::j3dSys,(byte *)&this->mpTexUsonami);
  return;
}


namespace d_kankyo_wether {

/* __stdcall dKyw_drawSun(int) */

void dKyw_drawSun(int param_1)

{
  dKyw_setDrawPacketListSky(&(d_kankyo::g_env_light.mpSunPacket)->parent,param_1);
  return;
}


/* __stdcall dKyw_Sun_Draw(void) */

void dKyw_Sun_Draw(void)

{
  dKyw_drawSun(1);
  return;
}


/* __stdcall dKyw_drawSunlenz(int) */

void dKyw_drawSunlenz(int param_1)

{
  if ((d_kankyo::g_env_light.mpSunlenzPacket)->mbDrawLenzInSky == false) {
    dKyw_setDrawPacketList(&(d_kankyo::g_env_light.mpSunlenzPacket)->parent,param_1);
  }
  else {
    dKyw_setDrawPacketListSky(&(d_kankyo::g_env_light.mpSunlenzPacket)->parent,param_1);
  }
  return;
}


/* __stdcall dKyw_Sunlenz_Draw(void) */

void dKyw_Sunlenz_Draw(void)

{
  dKyw_drawSunlenz(1);
  return;
}


/* __stdcall dKyw_drawRain(int) */

void dKyw_drawRain(int param_1)

{
  dKyw_setDrawPacketList((J3DPacket *)d_kankyo::g_env_light.mpRainPacket,param_1);
  return;
}


/* __stdcall dKyw_Rain_Draw(void) */

void dKyw_Rain_Draw(void)

{
  dKyw_drawRain(1);
  return;
}


/* __stdcall dKyw_drawSnow(int) */

void dKyw_drawSnow(int param_1)

{
  dKyw_setDrawPacketList(&(d_kankyo::g_env_light.mpSnowPacket)->parent,param_1);
  return;
}


/* __stdcall dKyw_Snow_Draw(void) */

void dKyw_Snow_Draw(void)

{
  dKyw_drawSnow(1);
  return;
}


/* __stdcall dKyw_drawStar(int) */

void dKyw_drawStar(int param_1)

{
  dKyw_setDrawPacketListSky(&(d_kankyo::g_env_light.mpStarPacket)->parent,param_1);
  return;
}


/* __stdcall dKyw_Star_Draw(void) */

void dKyw_Star_Draw(void)

{
  dKyw_drawStar(1);
  return;
}


/* __stdcall dKyw_drawPoison(int) */

void dKyw_drawPoison(void)

{
  dKyw_setDrawPacketListXluZPos
            (d_kankyo::g_env_light._2540_4_,d_kankyo::g_env_light._2540_4_ + 0xbb9c);
  return;
}


/* __stdcall dKyw_Poison_Draw(void) */

void dKyw_Poison_Draw(void)

{
  dKyw_drawPoison(1);
  return;
}


/* __stdcall dKyw_drawHousi(int) */

void dKyw_drawHousi(int param_1)

{
  dKyw_setDrawPacketList(&(d_kankyo::g_env_light.mpHousiPacket)->parent,param_1);
  return;
}


/* __stdcall dKyw_Housi_Draw(void) */

void dKyw_Housi_Draw(void)

{
  dKyw_drawHousi(1);
  return;
}


/* __stdcall dKyw_drawCloud(int) */

void dKyw_drawCloud(int param_1)

{
  dKyw_setDrawPacketList(&(d_kankyo::g_env_light.mpMoyaPacket)->parent,param_1);
  return;
}


/* __stdcall dKyw_Cloud_Draw(void) */

void dKyw_Cloud_Draw(void)

{
  dKyw_drawCloud(1);
  return;
}


/* __stdcall dKyw_drawVrkumo(int) */

void dKyw_drawVrkumo(int param_1)

{
  dKyw_setDrawPacketListSky(&(d_kankyo::g_env_light.mpVrkumoPacket)->parent,param_1);
  return;
}


/* __stdcall dKyw_Vrkumo_Draw(void) */

void dKyw_Vrkumo_Draw(void)

{
  dKyw_drawVrkumo(1);
  return;
}


/* __stdcall dKyw_drawWave(int) */

void dKyw_drawWave(undefined4 param_1)

{
  dKyw_setDrawPacketListXluBg(d_kankyo::g_env_light.mpWavePacket,param_1);
  return;
}


/* __stdcall dKyw_Wave_Draw(void) */

void dKyw_Wave_Draw(void)

{
  dKyw_drawWave(1);
  return;
}


/* __stdcall dKyw_wether_init(void) */

void dKyw_wether_init(void)

{
  d_kankyo::g_env_light.mbSunInitialized = 0;
  d_kankyo::g_env_light.mbThunderActive = false;
  d_kankyo::g_env_light.mThunderMode = 0;
  d_kankyo::g_env_light.mbRainInitialized = 0;
  d_kankyo::g_env_light.mRainCount = 0;
  d_kankyo::g_env_light.mbSnowInitialized = 0;
  d_kankyo::g_env_light.mSnowCount = 0;
  d_kankyo::g_env_light.mbStarInitialized = 0;
  d_kankyo::g_env_light.mStarCount = 0;
  d_kankyo::g_env_light.mStarCountTarget = 0_0;
  d_kankyo::g_env_light.mMoyaInitialized = 0;
  d_kankyo::g_env_light.mMoyaCount = 0;
  d_kankyo::g_env_light.mMoyaMode = 0;
  d_kankyo::g_env_light.mbHouseInitialized = 0;
  d_kankyo::g_env_light.mHousiCount = 0;
  d_kankyo::g_env_light._2532_1_ = 0;
  d_kankyo::g_env_light._2536_4_ = 0;
  d_kankyo::g_env_light.mCustomWindPower = 0_0;
  d_kankyo::g_env_light.mWaveInitialized = 0;
  d_kankyo::g_env_light._2588_4_ = 0;
  d_kankyo::g_env_light.mbWindlineInitialized = 0;
  d_kankyo::g_env_light.mWindlineCount = 0;
  dKyw_wind_init();
  dKyw_pntwind_init();
  return;
}


/* __stdcall dKyw_wether_init2(void) */

void dKyw_wether_init2(void)

{
  d_kankyo::g_env_light.mVrkumoStatus = 0;
  d_kankyo::g_env_light.mVrkumoCount = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall dKyw_wether_delete(void) */

void dKyw_wether_delete(void)

{
  dKyr__wind_Packet *pdVar1;
  dKyr__wind_Packet *pdVar2;
  JPABaseEmitter *pJVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (d_kankyo::g_env_light.mbSunInitialized != 0) {
    if (d_kankyo::g_env_light.mpSunPacket != (dKankyo_sun_Packet *)0x0) {
      (**(code **)(((d_kankyo::g_env_light.mpSunPacket)->parent).vtbl + 0x14))
                (d_kankyo::g_env_light.mpSunPacket,1);
    }
    if (d_kankyo::g_env_light.mpSunlenzPacket != (dKankyo_sunlenz_Packet *)0x0) {
      (**(code **)(((d_kankyo::g_env_light.mpSunlenzPacket)->parent).vtbl + 0x14))
                (d_kankyo::g_env_light.mpSunlenzPacket,1);
    }
  }
  if ((d_kankyo::g_env_light.mbRainInitialized != 0) &&
     (d_kankyo::g_env_light.mpRainPacket != (dKankyo_rain_Packet *)0x0)) {
    (**(code **)((d_kankyo::g_env_light.mpRainPacket)->vtbl + 0x14))
              (d_kankyo::g_env_light.mpRainPacket,1);
  }
  if ((d_kankyo::g_env_light.mbSnowInitialized != 0) &&
     (d_kankyo::g_env_light.mpSnowPacket != (dKankyo_snow_Packet *)0x0)) {
    (**(code **)(((d_kankyo::g_env_light.mpSnowPacket)->parent).vtbl + 0x14))
              (d_kankyo::g_env_light.mpSnowPacket,1);
  }
  if ((d_kankyo::g_env_light.mbStarInitialized != 0) &&
     (d_kankyo::g_env_light.mpStarPacket != (dKankyo_star_Packet *)0x0)) {
    (**(code **)(((d_kankyo::g_env_light.mpStarPacket)->parent).vtbl + 0x14))
              (d_kankyo::g_env_light.mpStarPacket,1);
  }
  if ((d_kankyo::g_env_light._2532_1_ != '\0') && (d_kankyo::g_env_light._2540_4_ != (int *)0x0)) {
    (**(code **)(*d_kankyo::g_env_light._2540_4_ + 0x14))(d_kankyo::g_env_light._2540_4_,1);
  }
  if ((d_kankyo::g_env_light.mbHouseInitialized != 0) &&
     (d_kankyo::g_env_light.mpHousiPacket != (dKankyo_housi_Packet *)0x0)) {
    (**(code **)(((d_kankyo::g_env_light.mpHousiPacket)->parent).vtbl + 0x14))
              (d_kankyo::g_env_light.mpHousiPacket,1);
  }
  if ((d_kankyo::g_env_light.mMoyaInitialized != 0) &&
     (d_kankyo::g_env_light.mpMoyaPacket != (dKankyo_cloud_Packet *)0x0)) {
    (**(code **)(((d_kankyo::g_env_light.mpMoyaPacket)->parent).vtbl + 0x14))
              (d_kankyo::g_env_light.mpMoyaPacket,1);
  }
  if ((d_kankyo::g_env_light.mWaveInitialized != 0) &&
     (d_kankyo::g_env_light.mpWavePacket != (dKankyo_wave_Packet *)0x0)) {
    (**(code **)(((d_kankyo::g_env_light.mpWavePacket)->parent).vtbl + 0x14))
              (d_kankyo::g_env_light.mpWavePacket,1);
  }
  pdVar1 = d_kankyo::g_env_light.mpWind;
  if (d_kankyo::g_env_light.mbWindlineInitialized != 0) {
    iVar5 = 0;
    iVar6 = 0;
    do {
      pJVar3 = *(JPABaseEmitter **)((int)&pdVar1->mWindEff[0].mpEmitter + iVar6);
      if (pJVar3 != (JPABaseEmitter *)0x0) {
        JPABaseEmitter::deleteAllParticle(pJVar3);
        iVar4 = *(int *)((int)&pdVar1->mWindEff[0].mpEmitter + iVar6);
        *(undefined4 *)(iVar4 + 0x60) = 0xffffffff;
        *(uint *)(iVar4 + 0x20c) = *(uint *)(iVar4 + 0x20c) | 1;
        *(undefined4 *)((int)&pdVar1->mWindEff[0].mpEmitter + iVar6) = 0;
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x34;
    } while (iVar5 < 0x1e);
    iVar5 = 0;
    iVar6 = 0;
    do {
      pJVar3 = *(JPABaseEmitter **)((int)&pdVar1->mKamomeEff[0].mpBaseEmitter + iVar6);
      if (pJVar3 != (JPABaseEmitter *)0x0) {
        JPABaseEmitter::deleteAllParticle(pJVar3);
        iVar4 = *(int *)((int)&pdVar1->mKamomeEff[0].mpBaseEmitter + iVar6);
        *(undefined4 *)(iVar4 + 0x60) = 0xffffffff;
        *(uint *)(iVar4 + 0x20c) = *(uint *)(iVar4 + 0x20c) | 1;
        *(undefined4 *)((int)&pdVar1->mKamomeEff[0].mpBaseEmitter + iVar6) = 0;
      }
      pdVar2 = d_kankyo::g_env_light.mpWind;
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x20;
    } while (iVar5 < 2);
    if (d_kankyo::g_env_light.mpWind != (dKyr__wind_Packet *)0x0) {
      Runtime.PPCEABI.H::__destroy_arr
                ((d_kankyo::g_env_light.mpWind)->mKamomeEff,::KAMOME_EFF::_KAMOME_EFF,0x20,10);
      Runtime.PPCEABI.H::__destroy_arr(pdVar2,::WIND_EFF::_WIND_EFF,0x34,0x1e);
      JKernel::operator_delete((JKRHeap *)pdVar2);
    }
  }
  return;
}

}

/* __thiscall WIND_EFF::~WIND_EFF(void) */

void __thiscall WIND_EFF::_WIND_EFF(WIND_EFF *this)

{
  short in_r4;
  
  if ((this != (WIND_EFF *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall KAMOME_EFF::~KAMOME_EFF(void) */

void __thiscall KAMOME_EFF::_KAMOME_EFF(KAMOME_EFF *this)

{
  short in_r4;
  
  if ((this != (KAMOME_EFF *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dKankyo_wave_Packet::~dKankyo_wave_Packet(void) */

void __thiscall dKankyo_wave_Packet::_dKankyo_wave_Packet(dKankyo_wave_Packet *this)

{
  short in_r4;
  
  if (this != (dKankyo_wave_Packet *)0x0) {
    (this->parent).vtbl = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this->mpWaveEff,WAVE_EFF::_WAVE_EFF,0x38,300);
    if (this != (dKankyo_wave_Packet *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dKankyo_cloud_Packet::~dKankyo_cloud_Packet(void) */

void __thiscall dKankyo_cloud_Packet::_dKankyo_cloud_Packet(dKankyo_cloud_Packet *this)

{
  short in_r4;
  
  if (this != (dKankyo_cloud_Packet *)0x0) {
    (this->parent).vtbl = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this->mEff,CLOUD_EFF::_CLOUD_EFF,0x4c,100);
    if (this != (dKankyo_cloud_Packet *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dKankyo_housi_Packet::~dKankyo_housi_Packet(void) */

void __thiscall dKankyo_housi_Packet::_dKankyo_housi_Packet(dKankyo_housi_Packet *this)

{
  short in_r4;
  
  if (this != (dKankyo_housi_Packet *)0x0) {
    (this->parent).vtbl = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this->mEff,HOUSI_EFF::_HOUSI_EFF,0x50,300);
    if (this != (dKankyo_housi_Packet *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dKankyo_poison_Packet::~dKankyo_poison_Packet(void) */

void __thiscall dKankyo_poison_Packet::_dKankyo_poison_Packet(dKankyo_poison_Packet *this)

{
  short in_r4;
  
  if (this != (dKankyo_poison_Packet *)0x0) {
    *(undefined1 **)this = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this + 0x10,POISON_EFF::_POISON_EFF,0x30,1000);
    if (this != (dKankyo_poison_Packet *)0x0) {
      *(undefined ***)this = &J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dKankyo_star_Packet::~dKankyo_star_Packet(void) */

void __thiscall dKankyo_star_Packet::_dKankyo_star_Packet(dKankyo_star_Packet *this)

{
  short in_r4;
  
  if (this != (dKankyo_star_Packet *)0x0) {
    (this->parent).vtbl = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this->mStarEff,STAR_EFF::_STAR_EFF,0x34,1);
    if (this != (dKankyo_star_Packet *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dKankyo_snow_Packet::~dKankyo_snow_Packet(void) */

void __thiscall dKankyo_snow_Packet::_dKankyo_snow_Packet(dKankyo_snow_Packet *this)

{
  short in_r4;
  
  if (this != (dKankyo_snow_Packet *)0x0) {
    (this->parent).vtbl = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this->mEff,SNOW_EFF::_SNOW_EFF,0x38,0xfa);
    if (this != (dKankyo_snow_Packet *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dKankyo_rain_Packet::~dKankyo_rain_Packet(void) */

void __thiscall dKankyo_rain_Packet::_dKankyo_rain_Packet(dKankyo_rain_Packet *this)

{
  short in_r4;
  
  if (this != (dKankyo_rain_Packet *)0x0) {
    this->vtbl = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this->mRainEff,RAIN_EFF::_RAIN_EFF,0x38,0xfa);
    if (this != (dKankyo_rain_Packet *)0x0) {
      this->vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dKankyo_sunlenz_Packet::~dKankyo_sunlenz_Packet(void) */

void __thiscall dKankyo_sunlenz_Packet::_dKankyo_sunlenz_Packet(dKankyo_sunlenz_Packet *this)

{
  short in_r4;
  
  if (this != (dKankyo_sunlenz_Packet *)0x0) {
    (this->parent).vtbl = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this->mPositions,::cXyz::_cXyz,0xc,8);
    if (this != (dKankyo_sunlenz_Packet *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dKankyo_sun_Packet::~dKankyo_sun_Packet(void) */

void __thiscall dKankyo_sun_Packet::_dKankyo_sun_Packet(dKankyo_sun_Packet *this)

{
  short in_r4;
  
  if (this != (dKankyo_sun_Packet *)0x0) {
    (this->parent).vtbl = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this->mPos,::cXyz::_cXyz,0xc,2);
    if (this != (dKankyo_sun_Packet *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_kankyo_wether {

/* __stdcall dKyw_wether_delete2(void) */

void dKyw_wether_delete2(void)

{
  if ((d_kankyo::g_env_light.mVrkumoStatus != 0) &&
     (d_kankyo::g_env_light.mpVrkumoPacket != (dKankyo_vrkumo_Packet *)0x0)) {
    (**(code **)(((d_kankyo::g_env_light.mpVrkumoPacket)->parent).vtbl + 0x14))
              (d_kankyo::g_env_light.mpVrkumoPacket,1);
  }
  return;
}

}

/* __thiscall dKankyo_vrkumo_Packet::~dKankyo_vrkumo_Packet(void) */

void __thiscall dKankyo_vrkumo_Packet::_dKankyo_vrkumo_Packet(dKankyo_vrkumo_Packet *this)

{
  short in_r4;
  
  if (this != (dKankyo_vrkumo_Packet *)0x0) {
    (this->parent).vtbl = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this->mInst,VRKUMO_EFF::_VRKUMO_EFF,0x2c,100);
    if (this != (dKankyo_vrkumo_Packet *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_kankyo_wether {

/* WARNING: Removing unreachable block (ram,0x80088300) */
/* __stdcall wether_move_windline(void) */

void wether_move_windline(void)

{
  dStage_FileList_dt_c *pFili;
  dStage_roomStatus_c *pdVar1;
  int iVar2;
  dKyr__wind_Packet *pdVar3;
  int iVar4;
  double dVar5;
  
  pFili = (dStage_FileList_dt_c *)0x0;
  if (-1 < (char)dStage_roomControl_c::mStayNo) {
    pdVar1 = dStage_roomControl_c::getStatusRoomDt
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                        (int)(char)dStage_roomControl_c::mStayNo);
    pFili = (dStage_FileList_dt_c *)(*(code *)((pdVar1->parent).parent.vtbl)->getFileListInfo)();
  }
  d_kankyo::g_env_light.mWindlineCount = 0;
  if (((pFili != (dStage_FileList_dt_c *)0x0) && ((pFili->mParam & 0x100000U) != 0)) &&
     (iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"GTower"),
     iVar2 != 0)) {
    dVar5 = dKyw_get_wind_pow();
    d_kankyo::g_env_light.mWindlineCount = (int)((double)10_0 * dVar5);
  }
  if (d_kankyo::g_env_light.field_0x990 < 1000000) {
    d_kankyo::g_env_light.mWindlineCount = 0;
    d_kankyo::g_env_light.field_0x990 = 1000000;
  }
  if (d_kankyo::g_env_light.mbWindlineInitialized == 1) {
    d_kankyo_rain::dKyr_wind_move();
    pdVar3 = d_kankyo::g_env_light.mpWind;
  }
  else {
    pdVar3 = d_kankyo::g_env_light.mpWind;
    if (((d_kankyo::g_env_light.mbWindlineInitialized == 0) &&
        (d_kankyo::g_env_light.mWindlineCount != 0)) &&
       (pdVar3 = (dKyr__wind_Packet *)JKernel::operator_new(0x75c,0x20),
       pdVar3 != (dKyr__wind_Packet *)0x0)) {
      Runtime.PPCEABI.H::__construct_array
                (pdVar3,::WIND_EFF::WIND_EFF,::WIND_EFF::_WIND_EFF,0x34,0x1e);
      Runtime.PPCEABI.H::__construct_array
                (pdVar3->mKamomeEff,::KAMOME_EFF::KAMOME_EFF,::KAMOME_EFF::_KAMOME_EFF,0x20,10);
      iVar2 = 0;
      iVar4 = 0x1e;
      d_kankyo::g_env_light.mpWind = pdVar3;
      do {
        *(undefined4 *)((int)&(d_kankyo::g_env_light.mpWind)->mWindEff[0].mState + iVar2) = 0;
        *(undefined4 *)((int)&(d_kankyo::g_env_light.mpWind)->mWindEff[0].mpEmitter + iVar2) = 0;
        iVar2 = iVar2 + 0x34;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      d_kankyo_rain::dKyr_wind_init();
      d_kankyo_rain::dKyr_wind_move();
      d_kankyo::g_env_light.mbWindlineInitialized = 1;
      pdVar3 = d_kankyo::g_env_light.mpWind;
    }
  }
  d_kankyo::g_env_light.mpWind = pdVar3;
  return;
}

}

/* __thiscall KAMOME_EFF::KAMOME_EFF(void) */

void __thiscall KAMOME_EFF::KAMOME_EFF(KAMOME_EFF *this)

{
  return;
}


/* __thiscall WIND_EFF::WIND_EFF(void) */

void __thiscall WIND_EFF::WIND_EFF(WIND_EFF *this)

{
  return;
}


namespace d_kankyo_wether {

/* WARNING: Removing unreachable block (ram,0x8008840c) */
/* __stdcall wether_move_thunder(void) */

void wether_move_thunder(void)

{
  if (d_kankyo::g_env_light.mbThunderActive == true) {
    d_kankyo_rain::dKyr_thunder_move();
  }
  else {
    if ((d_kankyo::g_env_light.mbThunderActive == false) &&
       (d_kankyo::g_env_light.mThunderMode != 0)) {
      d_kankyo_rain::dKyr_thunder_init();
      d_kankyo::g_env_light.mbThunderActive = true;
    }
  }
  return;
}


/* __stdcall dKyw_wether_move(void) */

void dKyw_wether_move(void)

{
  wether_move_thunder();
  wether_move_windline();
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800884bc) */
/* __stdcall wether_move_sun(void) */

void wether_move_sun(void)

{
  float fVar1;
  dKankyo_sun_Packet *pdVar2;
  dKankyo_sunlenz_Packet *pdVar3;
  void *pvVar4;
  
  if (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVrboxFlags & 1U) != 0) &&
     (d_kankyo::g_env_light.mbVrboxInvisible == 0)) {
    if (d_kankyo::g_env_light.mbSunInitialized == 1) {
      d_kankyo_rain::dKyr_sun_move();
      d_kankyo_rain::dKyr_lenzflare_move();
    }
    else {
      if (d_kankyo::g_env_light.mbSunInitialized == 0) {
        pdVar2 = (dKankyo_sun_Packet *)JKernel::operator_new(100,0x20);
        if (pdVar2 != (dKankyo_sun_Packet *)0x0) {
          (pdVar2->parent).vtbl = (undefined *)&J3DPacket::__vt;
          (pdVar2->parent).mpNextSibling = (J3DPacket *)0x0;
          (pdVar2->parent).mpFirstChild = (J3DPacket *)0x0;
          (pdVar2->parent).field_0xc = (undefined *)0x0;
          (pdVar2->parent).vtbl = &::dKankyo_sun_Packet::__vt;
          Runtime.PPCEABI.H::__construct_array(pdVar2->mPos,::cXyz::cXyz,::cXyz::_cXyz,0xc,2);
        }
        d_kankyo::g_env_light.mpSunPacket = pdVar2;
        pdVar3 = (dKankyo_sunlenz_Packet *)JKernel::operator_new(0x9c,0x20);
        if (pdVar3 != (dKankyo_sunlenz_Packet *)0x0) {
          (pdVar3->parent).vtbl = (undefined *)&J3DPacket::__vt;
          (pdVar3->parent).mpNextSibling = (J3DPacket *)0x0;
          (pdVar3->parent).mpFirstChild = (J3DPacket *)0x0;
          (pdVar3->parent).field_0xc = (undefined *)0x0;
          (pdVar3->parent).vtbl = &::dKankyo_sunlenz_Packet::__vt;
          Runtime.PPCEABI.H::__construct_array(pdVar3->mPositions,::cXyz::cXyz,::cXyz::_cXyz,0xc,8);
        }
        d_kankyo::g_env_light.mpSunlenzPacket = pdVar3;
        if ((d_kankyo::g_env_light.mpSunPacket != (dKankyo_sun_Packet *)0x0) &&
           (pdVar3 != (dKankyo_sunlenz_Packet *)0x0)) {
          pvVar4 = dRes_control_c::getRes
                             ("Always",0x87,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                              0x40);
          (d_kankyo::g_env_light.mpSunPacket)->mpTextureData[0] = pvVar4;
          pvVar4 = dRes_control_c::getRes
                             ("Always",0x88,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                              0x40);
          (d_kankyo::g_env_light.mpSunPacket)->mpTextureData[1] = pvVar4;
          pvVar4 = dRes_control_c::getRes
                             ("Always",0x89,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                              0x40);
          (d_kankyo::g_env_light.mpSunPacket)->mpTextureData[2] = pvVar4;
          pvVar4 = dRes_control_c::getRes
                             ("Always",0x8a,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                              0x40);
          (d_kankyo::g_env_light.mpSunPacket)->mpTextureData[3] = pvVar4;
          pvVar4 = dRes_control_c::getRes
                             ("Always",0x86,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                              0x40);
          (d_kankyo::g_env_light.mpSunPacket)->mpTextureData[4] = pvVar4;
          (d_kankyo::g_env_light.mpSunPacket)->field_0x3c = 0;
          (d_kankyo::g_env_light.mpSunPacket)->field_0x3d = false;
          fVar1 = 0_0;
          (d_kankyo::g_env_light.mpSunPacket)->mVisibility = 0_0;
          (d_kankyo::g_env_light.mpSunPacket)->mSunAlpha = fVar1;
          (d_kankyo::g_env_light.mpSunPacket)->mMoonAlpha = fVar1;
          (d_kankyo::g_env_light.mpSunPacket)->mVizChkData[0] = 0;
          (d_kankyo::g_env_light.mpSunPacket)->mVizChkData[1] = 0;
          (d_kankyo::g_env_light.mpSunPacket)->mVizChkData[2] = 0;
          (d_kankyo::g_env_light.mpSunPacket)->mVizChkData[3] = 0;
          pvVar4 = dRes_control_c::getRes
                             ("Always",0x81,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                              0x40);
          (d_kankyo::g_env_light.mpSunlenzPacket)->mpTexSnow01 = pvVar4;
          pvVar4 = dRes_control_c::getRes
                             ("Always",0x82,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                              0x40);
          (d_kankyo::g_env_light.mpSunlenzPacket)->mpTexLensHalf = pvVar4;
          pvVar4 = dRes_control_c::getRes
                             ("Always",0x85,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                              0x40);
          (d_kankyo::g_env_light.mpSunlenzPacket)->mpTexRingHalf = pvVar4;
          (d_kankyo::g_env_light.mpSunlenzPacket)->field_0x88 = _4854;
          fVar1 = 0_0;
          (d_kankyo::g_env_light.mpSunlenzPacket)->field_0x8c = 0_0;
          (d_kankyo::g_env_light.mpSunlenzPacket)->mDistFalloff = fVar1;
          (d_kankyo::g_env_light.mpSunlenzPacket)->mbDrawLenzInSky = false;
          d_kankyo_rain::dKyr_sun_move();
          d_kankyo_rain::dKyr_lenzflare_move();
          d_kankyo::g_env_light.mbSunInitialized = 1;
        }
      }
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x800887c0) */
/* __stdcall wether_move_rain(void) */

void wether_move_rain(void)

{
  dKankyo_rain_Packet *pdVar1;
  
  if (d_kankyo::g_env_light.mbRainInitialized == 1) {
    d_kankyo_rain::dKyr_rain_move();
    if (d_kankyo::g_env_light.mSnowCount == 0) {
      if (125_0 <= (float)((double)CONCAT44(0x43300000,d_kankyo::g_env_light.mRainCount ^ 0x80000000
                                           ) - _4904)) {
        JAIZelBasic::rainPlay(JAIZelBasic::zel_basic,1);
      }
      else {
        JAIZelBasic::rainPlay(JAIZelBasic::zel_basic,0);
      }
    }
    pdVar1 = d_kankyo::g_env_light.mpRainPacket;
    if (d_kankyo::g_env_light.mRainCount == 0) {
      d_kankyo::g_env_light.mbRainInitialized = 0;
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x185d,(cXyz *)0x0,0,0,1_0,1_0,_1_0,_1_0,0);
      pdVar1 = d_kankyo::g_env_light.mpRainPacket;
      if (d_kankyo::g_env_light.mpRainPacket != (dKankyo_rain_Packet *)0x0) {
        (**(code **)((d_kankyo::g_env_light.mpRainPacket)->vtbl + 0x14))
                  (d_kankyo::g_env_light.mpRainPacket,1);
        pdVar1 = d_kankyo::g_env_light.mpRainPacket;
      }
    }
  }
  else {
    pdVar1 = d_kankyo::g_env_light.mpRainPacket;
    if (((d_kankyo::g_env_light.mbRainInitialized == 0) && (d_kankyo::g_env_light.mRainCount != 0))
       && (pdVar1 = (dKankyo_rain_Packet *)JKernel::operator_new(0x3718,0x20),
          pdVar1 != (dKankyo_rain_Packet *)0x0)) {
      pdVar1->vtbl = (undefined *)&J3DPacket::__vt;
      (pdVar1->field_0x4).x = 0.0;
      (pdVar1->field_0x4).y = 0.0;
      (pdVar1->field_0x4).z = 0.0;
      pdVar1->vtbl = &::dKankyo_rain_Packet::__vt;
      Runtime.PPCEABI.H::__construct_array
                (pdVar1->mRainEff,::RAIN_EFF::RAIN_EFF,::RAIN_EFF::_RAIN_EFF,0x38,0xfa);
      d_kankyo::g_env_light.mpRainPacket = pdVar1;
      d_kankyo_rain::dKyr_rain_init();
      d_kankyo_rain::dKyr_rain_move();
      d_kankyo::g_env_light.mbRainInitialized = 1;
      pdVar1 = d_kankyo::g_env_light.mpRainPacket;
      if (d_kankyo::g_env_light.mRainCount != 0xfa) {
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x185c,(cXyz *)0x0,0,0,1_0,1_0,_1_0,_1_0,0);
        pdVar1 = d_kankyo::g_env_light.mpRainPacket;
      }
    }
  }
  d_kankyo::g_env_light.mpRainPacket = pdVar1;
  return;
}


/* WARNING: Removing unreachable block (ram,0x800889a8) */
/* __stdcall wether_move_snow(void) */

void wether_move_snow(void)

{
  int iVar1;
  
  if (d_kankyo::g_env_light.mbSnowInitialized == 1) {
    iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Adanmae");
    if (iVar1 == 0) {
      d_kankyo_rain::dKyr_kazanbai_move();
    }
    else {
      d_kankyo_rain::dKyr_snow_move();
    }
  }
  else {
    if (((d_kankyo::g_env_light.mbSnowInitialized == 0) && (d_kankyo::g_env_light.mSnowCount != 0))
       && (d_kankyo_rain::dKyr_snow_init(),
          d_kankyo::g_env_light.mpSnowPacket != (dKankyo_snow_Packet *)0x0)) {
      iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Adanmae");
      if (iVar1 == 0) {
        d_kankyo_rain::dKyr_kazanbai_move();
      }
      else {
        d_kankyo_rain::dKyr_snow_move();
      }
      d_kankyo::g_env_light.mbSnowInitialized = 1;
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x80088c78) */
/* WARNING: Removing unreachable block (ram,0x80088cec) */
/* __stdcall wether_move_star(void) */

void wether_move_star(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dayTime;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVrboxFlags & 1U) != 0) &&
       (d_kankyo::g_env_light.mbVrboxInvisible == 0)) &&
      (iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"M_DragB"),
      iVar2 != 0)) ||
     (iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Name"),
     iVar2 == 0)) {
    dayTime = (double)dScnKy_env_light_c::getDaytime(&d_kankyo::g_env_light);
    iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Name");
    fVar1 = 1_0;
    if (iVar2 == 0) {
      if ((dayTime < (double)315_0) && ((double)60_0 <= dayTime)) {
        if (dayTime <= (double)270_0) {
          fVar1 = 0_0;
          if (dayTime < (double)75_0) {
            fVar1 = 1_15_0 * (float)((double)75_0 - dayTime);
          }
        }
        else {
          fVar1 = 1_0 - 1_45_0 * (float)((double)315_0 - dayTime);
        }
      }
    }
    else {
      if ((dayTime < (double)330_0) && ((double)90_0 <= dayTime)) {
        if (dayTime <= (double)300_0) {
          fVar1 = 0_0;
          if (dayTime < (double)105_0) {
            fVar1 = 1_15_0 * (float)((double)105_0 - dayTime);
          }
        }
        else {
          fVar1 = 1_0 - 1_30_0 * (float)((double)330_0 - dayTime);
        }
      }
    }
    if (d_kankyo::g_env_light.mColpatWeather != 0) {
      fVar1 = 0_0;
    }
    if ((d_kankyo::g_env_light.mColpatCurr != 0) && (0_5 < d_kankyo::g_env_light.mColPatBlend)) {
      fVar1 = 0_0;
    }
    SComponent::cLib_addCalc(&d_kankyo::g_env_light.mStarCountTarget,fVar1,0_1,0_01,0_000001);
    d_kankyo::g_env_light.mStarCount =
         (int)(short)(int)(1000_0 * d_kankyo::g_env_light.mStarCountTarget);
    if (d_kankyo::g_env_light.mbStarInitialized == 1) {
      d_kankyo_rain::dKyr_star_move();
      if ((d_kankyo::g_env_light.mStarCount == 0) &&
         (d_kankyo::g_env_light.mbStarInitialized = 0,
         d_kankyo::g_env_light.mpStarPacket != (dKankyo_star_Packet *)0x0)) {
        (**(code **)(((d_kankyo::g_env_light.mpStarPacket)->parent).vtbl + 0x14))
                  (d_kankyo::g_env_light.mpStarPacket,1);
      }
    }
    else {
      if (((d_kankyo::g_env_light.mbStarInitialized == 0) && (d_kankyo::g_env_light.mStarCount != 0)
          ) && (d_kankyo_rain::dKyr_star_init(),
               d_kankyo::g_env_light.mpStarPacket != (dKankyo_star_Packet *)0x0)) {
        d_kankyo_rain::dKyr_star_move();
        d_kankyo::g_env_light.mbStarInitialized = 1;
      }
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80088d6c) */
/* __stdcall wether_move_poison(void) */

void wether_move_poison(void)

{
  int iVar1;
  
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"M_Dai");
  if (iVar1 == 0) {
    d_kankyo::g_env_light._2536_4_ = 500;
  }
  if (d_kankyo::g_env_light._2532_1_ == '\x01') {
    d_kankyo_rain::poison_move();
  }
  else {
    if ((d_kankyo::g_env_light._2532_1_ == '\0') && (d_kankyo::g_env_light._2536_4_ != 0)) {
      d_kankyo_rain::poison_init();
      d_kankyo::g_env_light._2532_1_ = '\x01';
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80088dd8) */
/* __stdcall wether_move_housi(void) */

void wether_move_housi(void)

{
  dKankyo_housi_Packet *pdVar1;
  dKankyo_housi_Packet *pPkt;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  pdVar1 = d_kankyo::g_env_light.mpHousiPacket;
  if (d_kankyo::g_env_light.mbHouseInitialized == 1) {
    if ((d_kankyo::g_env_light.mHousiCount != 0) ||
       (0_0 < (d_kankyo::g_env_light.mpHousiPacket)->field_0x5ddc)) {
      d_kankyo_rain::dKyr_housi_move();
      d_kankyo::g_env_light.mHousiCount = 0;
      pdVar1 = d_kankyo::g_env_light.mpHousiPacket;
    }
    else {
      d_kankyo::g_env_light.mbHouseInitialized = 0;
      if (d_kankyo::g_env_light.mpHousiPacket != (dKankyo_housi_Packet *)0x0) {
        (**(code **)(((d_kankyo::g_env_light.mpHousiPacket)->parent).vtbl + 0x14))
                  (d_kankyo::g_env_light.mpHousiPacket,1);
        pdVar1 = d_kankyo::g_env_light.mpHousiPacket;
      }
    }
  }
  else {
    if (((d_kankyo::g_env_light.mbHouseInitialized == 0) && (d_kankyo::g_env_light.mHousiCount != 0)
        ) && (pPkt = (dKankyo_housi_Packet *)JKernel::operator_new(0x5de8,0x20), pdVar1 = pPkt,
             pPkt != (dKankyo_housi_Packet *)0x0)) {
      (pPkt->parent).vtbl = (undefined *)&J3DPacket::__vt;
      (pPkt->parent).mpNextSibling = (J3DPacket *)0x0;
      (pPkt->parent).mpFirstChild = (J3DPacket *)0x0;
      (pPkt->parent).field_0xc = (undefined *)0x0;
      (pPkt->parent).vtbl = &::dKankyo_housi_Packet::__vt;
      Runtime.PPCEABI.H::__construct_array
                (pPkt->mEff,::HOUSI_EFF::HOUSI_EFF,::HOUSI_EFF::_HOUSI_EFF,0x50,300);
      d_kankyo::g_env_light.mpHousiPacket = pPkt;
      pcVar2 = (char *)dRes_control_c::getRes
                                 ("Always",0x6d,
                                  d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      (d_kankyo::g_env_light.mpHousiPacket)->mpTex = pcVar2;
      (d_kankyo::g_env_light.mpHousiPacket)->field_0x5ddc = 0_0;
      iVar3 = 0;
      iVar4 = 300;
      do {
        (&(d_kankyo::g_env_light.mpHousiPacket)->mEff[0].mState)[iVar3] = 0;
        iVar3 = iVar3 + 0x50;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      d_kankyo_rain::dKyr_housi_move();
      d_kankyo::g_env_light.mbHouseInitialized = 1;
      pdVar1 = d_kankyo::g_env_light.mpHousiPacket;
    }
  }
  d_kankyo::g_env_light.mpHousiPacket = pdVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80088f70) */
/* __stdcall wether_move_moya(void) */

void wether_move_moya(void)

{
  dKankyo_cloud_Packet *pdVar1;
  dKankyo_cloud_Packet *pPkt;
  char *pcVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  
  if (d_kankyo::g_env_light.mMoyaInitialized == 1) {
    if (((d_kankyo::g_env_light.mMoyaMode != 0) ||
        (dVar5 = dKyw_get_wind_pow(), dVar5 <= (double)0_2)) ||
       (d_kankyo::g_env_light.mMoyaCount == 0)) {
      if (d_kankyo::g_env_light.mMoyaMode == 1) {
        d_kankyo::g_env_light.mMoyaSE = 0x1061;
      }
      else {
        if ((d_kankyo::g_env_light.mMoyaMode == 2) &&
           (iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                               "A_mori"), iVar3 == 0)) {
          d_kankyo::g_env_light.mMoyaSE = 0x1062;
        }
      }
    }
    else {
      iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"M_NewD2");
      if (iVar3 == 0) {
        if (d_kankyo::g_env_light.mbVrboxInvisible == 0) {
          d_kankyo::g_env_light.mMoyaSE = 0x105a;
        }
        else {
          d_kankyo::g_env_light.mMoyaSE = 0x1061;
        }
      }
    }
    d_kankyo_rain::cloud_shadow_move();
    pdVar1 = d_kankyo::g_env_light.mpMoyaPacket;
    if (((d_kankyo::g_env_light.mMoyaCount == 0) &&
        ((d_kankyo::g_env_light.mpMoyaPacket)->mCount == 0)) &&
       (d_kankyo::g_env_light.mMoyaInitialized = 0,
       d_kankyo::g_env_light.mpMoyaPacket != (dKankyo_cloud_Packet *)0x0)) {
      (**(code **)(((d_kankyo::g_env_light.mpMoyaPacket)->parent).vtbl + 0x14))
                (d_kankyo::g_env_light.mpMoyaPacket,1);
      pdVar1 = d_kankyo::g_env_light.mpMoyaPacket;
    }
  }
  else {
    pdVar1 = d_kankyo::g_env_light.mpMoyaPacket;
    if (((d_kankyo::g_env_light.mMoyaInitialized == 0) && (d_kankyo::g_env_light.mMoyaCount != 0))
       && (pPkt = (dKankyo_cloud_Packet *)JKernel::operator_new(0x1dc8,0x20), pdVar1 = pPkt,
          pPkt != (dKankyo_cloud_Packet *)0x0)) {
      (pPkt->parent).vtbl = (undefined *)&J3DPacket::__vt;
      (pPkt->parent).mpNextSibling = (J3DPacket *)0x0;
      (pPkt->parent).mpFirstChild = (J3DPacket *)0x0;
      (pPkt->parent).field_0xc = (undefined *)0x0;
      (pPkt->parent).vtbl = &::dKankyo_cloud_Packet::__vt;
      Runtime.PPCEABI.H::__construct_array
                (pPkt->mEff,::CLOUD_EFF::CLOUD_EFF,::CLOUD_EFF::_CLOUD_EFF,0x4c,100);
      d_kankyo::g_env_light.mpMoyaPacket = pPkt;
      pcVar2 = (char *)dRes_control_c::getRes
                                 ("Always",0x84,
                                  d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      (d_kankyo::g_env_light.mpMoyaPacket)->mpTexture = pcVar2;
      iVar3 = 0;
      iVar4 = 100;
      do {
        (&(d_kankyo::g_env_light.mpMoyaPacket)->mEff[0].mStatus)[iVar3] = 0;
        iVar3 = iVar3 + 0x4c;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      (d_kankyo::g_env_light.mpMoyaPacket)->mCount = 0;
      d_kankyo_rain::cloud_shadow_move();
      d_kankyo::g_env_light.mMoyaInitialized = d_kankyo::g_env_light.mMoyaInitialized + 1;
      pdVar1 = d_kankyo::g_env_light.mpMoyaPacket;
    }
  }
  d_kankyo::g_env_light.mpMoyaPacket = pdVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80089474) */
/* __stdcall wether_move_vrkumo(void) */

void wether_move_vrkumo(void)

{
  camera_class *pcVar1;
  int iVar2;
  dKankyo_vrkumo_Packet *pPkt;
  void *pvVar3;
  JUTTexture *pJVar4;
  int iVar5;
  double dVar6;
  double dVar7;
  float fVar8;
  
  pcVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  if (init_5112 == '\0') {
    r09o_5110.x = _5199;
    r09o_5110.y = _5200;
    r09o_5110.z = _5201;
    Runtime.PPCEABI.H::__register_global_object(&r09o_5110,::cXyz::_cXyz,&_5111);
    init_5112 = '\x01';
  }
  iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Name");
  if (iVar2 == 0) {
    d_kankyo::g_env_light.mVrkumoCount = 0x46;
  }
  else {
    if (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVrboxFlags & 1U) == 0) ||
       (d_kankyo::g_env_light.mbVrboxInvisible != 0)) {
      d_kankyo::g_env_light.mVrkumoCount = 0;
    }
    else {
      d_kankyo::g_env_light.mVrkumoCount = 0x32;
      if (((((d_kankyo::g_env_light.mColpatCurr == 1) && (0_0 < d_kankyo::g_env_light.mColPatBlend))
           || ((d_kankyo::g_env_light.mColpatPrev == 1 && (d_kankyo::g_env_light.mColPatBlend < 1_0)
               ))) ||
          ((d_kankyo::g_env_light.mColpatCurr == 2 && (0_0 < d_kankyo::g_env_light.mColPatBlend))))
         || ((d_kankyo::g_env_light.mColpatPrev == 2 && (d_kankyo::g_env_light.mColPatBlend < 1_0)))
         ) {
        SComponent::cLib_addCalc(&d_kankyo::g_env_light.mVrkumoStrength,1_0,0_1,0_003,0_0000007);
      }
      else {
        SComponent::cLib_addCalc(&d_kankyo::g_env_light.mVrkumoStrength,0_0,0_08,0_002,0_00000007);
      }
      iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea");
      if ((iVar2 == 0) && (dStage_roomControl_c::mStayNo == 9)) {
        fVar8 = mtx::PSVECSquareDistance(&pcVar1->mEyePos,&r09o_5110);
        dVar7 = (double)fVar8;
        if ((double)0_0 < dVar7) {
          dVar6 = 1.0 / SQRT(dVar7);
          dVar6 = _5207 * dVar6 * (_5208 - dVar7 * dVar6 * dVar6);
          dVar6 = _5207 * dVar6 * (_5208 - dVar7 * dVar6 * dVar6);
          dVar7 = (double)(float)(dVar7 * _5207 * dVar6 * (_5208 - dVar7 * dVar6 * dVar6));
        }
        if (dVar7 < (double)2500_0) {
          d_kankyo::g_env_light.mVrkumoStrength = 1_0;
        }
      }
      d_kankyo::g_env_light.mVrkumoCount =
           (int)(short)(int)(50_0 + 50_0 * d_kankyo::g_env_light.mVrkumoStrength);
      iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"GTower");
      if (iVar2 == 0) {
        d_kankyo::g_env_light.mVrkumoCount = 0;
      }
    }
  }
  if (d_kankyo::g_env_light.mVrkumoStatus == 1) {
    d_kankyo_rain::vrkumo_move();
    pPkt = d_kankyo::g_env_light.mpVrkumoPacket;
  }
  else {
    pPkt = d_kankyo::g_env_light.mpVrkumoPacket;
    if (((d_kankyo::g_env_light.mVrkumoStatus == 0) && (d_kankyo::g_env_light.mVrkumoCount != 0)) &&
       (pPkt = (dKankyo_vrkumo_Packet *)JKernel::operator_new(0x1150,0x20),
       pPkt != (dKankyo_vrkumo_Packet *)0x0)) {
      (pPkt->parent).vtbl = (undefined *)&J3DPacket::__vt;
      (pPkt->parent).mpNextSibling = (J3DPacket *)0x0;
      (pPkt->parent).mpFirstChild = (J3DPacket *)0x0;
      (pPkt->parent).field_0xc = (undefined *)0x0;
      (pPkt->parent).vtbl = &::dKankyo_vrkumo_Packet::__vt;
      Runtime.PPCEABI.H::__construct_array
                (pPkt->mInst,::VRKUMO_EFF::VRKUMO_EFF,::VRKUMO_EFF::_VRKUMO_EFF,0x2c,100);
      d_kankyo::g_env_light.mpVrkumoPacket = pPkt;
      pvVar3 = dRes_control_c::getRes
                         ("Stage","vr_box.bmd",
                          d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
      if ((pvVar3 == (void *)0x0) &&
         (pvVar3 = dRes_control_c::getRes
                             ("Stage","vr_box.bdl",
                              d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40),
         pvVar3 == (void *)0x0)) {
        pJVar4 = (JUTTexture *)
                 dRes_control_c::getRes
                           ("Stage","cloudtx_01.bti",
                            d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
        (d_kankyo::g_env_light.mpVrkumoPacket)->mpCloudTx1 = pJVar4;
        pJVar4 = (JUTTexture *)
                 dRes_control_c::getRes
                           ("Stage","cloudtx_02.bti",
                            d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
        (d_kankyo::g_env_light.mpVrkumoPacket)->mpCloudTx2 = pJVar4;
        pJVar4 = (JUTTexture *)
                 dRes_control_c::getRes
                           ("Stage","cloudtx_03.bti",
                            d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
        (d_kankyo::g_env_light.mpVrkumoPacket)->mpCloudTx3 = pJVar4;
      }
      else {
        pJVar4 = (JUTTexture *)
                 dRes_control_c::getRes
                           ("Stage","cloud_01.bti",
                            d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
        (d_kankyo::g_env_light.mpVrkumoPacket)->mpCloudTx1 = pJVar4;
        pJVar4 = (JUTTexture *)
                 dRes_control_c::getRes
                           ("Stage","cloud_02.bti",
                            d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
        (d_kankyo::g_env_light.mpVrkumoPacket)->mpCloudTx2 = pJVar4;
        pJVar4 = (JUTTexture *)
                 dRes_control_c::getRes
                           ("Stage","cloud_03.bti",
                            d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
        (d_kankyo::g_env_light.mpVrkumoPacket)->mpCloudTx3 = pJVar4;
      }
      if ((d_kankyo::g_env_light.mpVrkumoPacket)->mpCloudTx1 == (JUTTexture *)0x0) {
        d_kankyo::g_env_light.mVrkumoStatus = 99;
      }
      iVar2 = 0;
      iVar5 = 100;
      do {
        (&(d_kankyo::g_env_light.mpVrkumoPacket)->mInst[0].mStatus)[iVar2] = 0;
        iVar2 = iVar2 + 0x2c;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      d_kankyo_rain::vrkumo_move();
      d_kankyo::g_env_light.mVrkumoStatus = d_kankyo::g_env_light.mVrkumoStatus + 1;
      pPkt = d_kankyo::g_env_light.mpVrkumoPacket;
    }
  }
  d_kankyo::g_env_light.mpVrkumoPacket = pPkt;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x800896cc) */
/* __stdcall wether_move_wave(void) */

void wether_move_wave(void)

{
  dKankyo_wave_Packet *pdVar1;
  dKankyo_wave_Packet *pPkt;
  JUTTexture *pJVar2;
  int iVar3;
  int iVar4;
  
  if (d_kankyo::g_env_light.mWaveInitialized == 1) {
    if ((d_kankyo::g_env_light.mWaveCount == 0) &&
       (d_kankyo::g_env_light.mWaveInitialized = 0,
       d_kankyo::g_env_light.mpWavePacket != (dKankyo_wave_Packet *)0x0)) {
      (**(code **)(((d_kankyo::g_env_light.mpWavePacket)->parent).vtbl + 0x14))
                (d_kankyo::g_env_light.mpWavePacket,1);
    }
    d_kankyo_rain::wave_move();
    pdVar1 = d_kankyo::g_env_light.mpWavePacket;
  }
  else {
    pdVar1 = d_kankyo::g_env_light.mpWavePacket;
    if (((d_kankyo::g_env_light.mWaveInitialized == 0) && (d_kankyo::g_env_light.mWaveCount != 0))
       && (pPkt = (dKankyo_wave_Packet *)JKernel::operator_new(0x41c0,0x20), pdVar1 = pPkt,
          pPkt != (dKankyo_wave_Packet *)0x0)) {
      (pPkt->parent).vtbl = (undefined *)&J3DPacket::__vt;
      (pPkt->parent).mpNextSibling = (J3DPacket *)0x0;
      (pPkt->parent).mpFirstChild = (J3DPacket *)0x0;
      (pPkt->parent).field_0xc = (undefined *)0x0;
      (pPkt->parent).vtbl = &::dKankyo_wave_Packet::__vt;
      Runtime.PPCEABI.H::__construct_array
                (pPkt->mpWaveEff,::WAVE_EFF::WAVE_EFF,::WAVE_EFF::_WAVE_EFF,0x38,300);
      d_kankyo::g_env_light.mpWavePacket = pPkt;
      pJVar2 = (JUTTexture *)
               dRes_control_c::getRes
                         ("Always",0x8b,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40
                         );
      (d_kankyo::g_env_light.mpWavePacket)->mpTexUsonami = pJVar2;
      pJVar2 = (JUTTexture *)
               dRes_control_c::getRes
                         ("Always",0x8c,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40
                         );
      (d_kankyo::g_env_light.mpWavePacket)->mpTexUsonamiM = pJVar2;
      iVar3 = 0;
      iVar4 = 300;
      do {
        (&(d_kankyo::g_env_light.mpWavePacket)->mpWaveEff[0].mState)[iVar3] = 0;
        iVar3 = iVar3 + 0x38;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      d_kankyo_rain::wave_move();
      d_kankyo::g_env_light.mWaveInitialized = 1;
      pdVar1 = d_kankyo::g_env_light.mpWavePacket;
    }
  }
  d_kankyo::g_env_light.mpWavePacket = pdVar1;
  return;
}


/* __stdcall dKyw_wether_move_draw(void) */

void dKyw_wether_move_draw(void)

{
  int iVar1;
  
  d_kankyo::g_env_light.mMoyaSE = 0;
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Name");
  if (iVar1 != 0) {
    wether_move_sun();
    wether_move_rain();
    wether_move_snow();
  }
  wether_move_star();
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Name");
  if (iVar1 != 0) {
    wether_move_poison();
    wether_move_housi();
    wether_move_moya();
  }
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Name");
  if (iVar1 != 0) {
    wether_move_wave();
  }
  return;
}


/* __stdcall dKyw_wether_move_draw2(void) */

void dKyw_wether_move_draw2(void)

{
  wether_move_vrkumo();
  return;
}


/* __stdcall dKyw_wether_draw(void) */

void dKyw_wether_draw(void)

{
  int iVar1;
  
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Name");
  if (iVar1 != 0) {
    if (d_kankyo::g_env_light._2532_1_ != '\0') {
      dKyw_Poison_Draw();
    }
    if (d_kankyo::g_env_light.mWaveInitialized != 0) {
      dKyw_Wave_Draw();
    }
    if (d_kankyo::g_env_light.mMoyaInitialized != 0) {
      dKyw_Cloud_Draw();
    }
  }
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Name");
  if ((iVar1 != 0) && (d_kankyo::g_env_light.mbSunInitialized != 0)) {
    dKyw_Sun_Draw();
    dKyw_Sunlenz_Draw();
  }
  if (d_kankyo::g_env_light.mbStarInitialized != 0) {
    dKyw_Star_Draw();
  }
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Name");
  if (iVar1 != 0) {
    if (d_kankyo::g_env_light.mbRainInitialized != 0) {
      dKyw_Rain_Draw();
    }
    if (d_kankyo::g_env_light.mbSnowInitialized != 0) {
      dKyw_Snow_Draw();
    }
    if (d_kankyo::g_env_light.mbHouseInitialized != 0) {
      dKyw_Housi_Draw();
    }
  }
  return;
}


/* __stdcall dKyw_wether_draw2(void) */

void dKyw_wether_draw2(void)

{
  if ((d_kankyo::g_env_light.mVrkumoStatus != 0) && (d_kankyo::g_env_light.mVrkumoStatus < 99)) {
    dKyw_Vrkumo_Draw();
  }
  return;
}


/* __stdcall dKyw_wether_proc(void) */

void dKyw_wether_proc(void)

{
  squal_proc();
  return;
}


/* __stdcall dKyw_wind_init(void) */

void dKyw_wind_init(void)

{
  if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mTactWindAngleX == -1) &&
     (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mTactWindAngleY == -1)) {
    d_kankyo::g_env_light.mTactWindAngleFlags = 0;
    d_kankyo::g_env_light.mTactWindAngleX = 0;
    d_kankyo::g_env_light.mTactWindAngleY = 0;
  }
  else {
    d_kankyo::g_env_light.mTactWindAngleFlags = 1;
    d_kankyo::g_env_light.mTactWindAngleX =
         d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mTactWindAngleX;
    d_kankyo::g_env_light.mTactWindAngleY =
         d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mTactWindAngleY;
  }
  d_kankyo::g_env_light.mWindVec.x = _1_0;
  d_kankyo::g_env_light.mWindVec.y = 0_0;
  d_kankyo::g_env_light.mWindVec.z = 0_0;
  d_kankyo::g_env_light.mpWindVecOverride = (cXyz *)0x0;
  d_kankyo::g_env_light._2444_4_ = 1000000;
  d_kankyo::g_env_light.field_0x990 = 1000000;
  d_kankyo::g_env_light._2452_4_ = 1000000;
  d_kankyo::g_env_light.mWindPower = 0_0;
  d_kankyo::g_env_light.mWindStrengthOverride = 0_0;
  d_kankyo::g_env_light.mEvtWindSet = 0;
  return;
}


/* WARNING: Removing unreachable block (ram,0x80089d14) */
/* WARNING: Removing unreachable block (ram,0x80089e34) */
/* __stdcall dKyw_wind_set(void) */

void dKyw_wind_set(void)

{
  uint tactWindX;
  int windAngleX;
  int windAngleY;
  dStage_FileList_dt_c *pFili;
  dStage_roomStatus_c *pRoomStatus;
  uint tactWindY;
  uint windStrengthFlag;
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f31;
  double windStrength;
  float fVar4;
  cXyz local_34;
  TVec3_float_ windVec;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_kankyo::g_env_light.mpWindVecOverride == (cXyz *)0x0) {
    pFili = (dStage_FileList_dt_c *)0x0;
    windStrengthFlag = 0;
    if (-1 < (char)dStage_roomControl_c::mStayNo) {
      pRoomStatus = dStage_roomControl_c::getStatusRoomDt
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                               (int)(char)dStage_roomControl_c::mStayNo);
      pFili = (dStage_FileList_dt_c *)
              (*(code *)((pRoomStatus->parent).parent.vtbl)->getFileListInfo)();
    }
    if ((d_kankyo::g_env_light.mEvtWindSet == 0) || (d_kankyo::g_env_light.mEvtWindSet == 0xff)) {
      if (d_kankyo::g_env_light.mTactWindAngleFlags == 0) {
        tactWindX = 0;
        tactWindY = 0;
      }
      else {
        tactWindX = SEXT24(d_kankyo::g_env_light.mTactWindAngleX);
        tactWindY = SEXT24(d_kankyo::g_env_light.mTactWindAngleY);
      }
    }
    else {
      tactWindX = SEXT24(d_kankyo::g_env_light.mEvtWindAngleX);
      tactWindY = SEXT24(d_kankyo::g_env_light.mEvtWindAngleY);
    }
    windAngleX = (int)(tactWindX & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
    windAngleY = (int)(tactWindY & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
    windVec.x = JKernel::JMath::jmaCosTable[windAngleX] * JKernel::JMath::jmaCosTable[windAngleY];
    windVec.y = JKernel::JMath::jmaSinTable[windAngleX];
    windVec.z = JKernel::JMath::jmaCosTable[windAngleX] * JKernel::JMath::jmaSinTable[windAngleY];
    if (pFili != (dStage_FileList_dt_c *)0x0) {
      windStrengthFlag = (uint)pFili->mParam >> 0x12 & 3;
    }
    if (windStrengthFlag == 1) {
      windStrength = (double)0_6;
    }
    else {
      if (windStrengthFlag == 0) {
        windStrength = (double)0_3;
      }
      else {
        if (windStrengthFlag < 3) {
          windStrength = (double)0_9;
        }
        else {
          windStrength = (double)0_0;
        }
      }
    }
  }
  else {
    windVec.x = (d_kankyo::g_env_light.mpWindVecOverride)->x;
    windVec.y = (d_kankyo::g_env_light.mpWindVecOverride)->y;
    windVec.z = (d_kankyo::g_env_light.mpWindVecOverride)->z;
    windStrength = (double)d_kankyo::g_env_light.mWindStrengthOverride;
    SComponent::cM_atan2s(windVec.x,windVec.z);
    local_34.x = windVec.x;
    local_34.y = 0_0;
    local_34.z = windVec.z;
    fVar4 = mtx::PSVECSquareMag(&local_34);
    dVar3 = (double)fVar4;
    if ((double)0_0 < dVar3) {
      dVar2 = 1.0 / SQRT(dVar3);
      dVar2 = _5207 * dVar2 * (_5208 - dVar3 * dVar2 * dVar2);
      dVar2 = _5207 * dVar2 * (_5208 - dVar3 * dVar2 * dVar2);
      dVar3 = (double)(float)(dVar3 * _5207 * dVar2 * (_5208 - dVar3 * dVar2 * dVar2));
    }
    SComponent::cM_atan2s((float)dVar3,windVec.y);
  }
  if ((double)0_0 < (double)d_kankyo::g_env_light.mCustomWindPower) {
    d_kankyo::g_env_light.mWindPower = d_kankyo::g_env_light.mCustomWindPower;
    windStrength = (double)d_kankyo::g_env_light.mCustomWindPower;
  }
  if (d_kankyo::g_env_light.mEvtWindSet == 2) {
    windStrength = (double)0_0;
  }
  if ((double)1_0 < windStrength) {
    windStrength = (double)1_0;
  }
  if (d_kankyo::g_env_light.mInitAnimTimer == 0) {
    SComponent::cLib_addCalc(&d_kankyo::g_env_light.mWindVec.x,windVec.x,0_1,2_0,0_001);
    SComponent::cLib_addCalc(&d_kankyo::g_env_light.mWindVec.y,windVec.y,0_1,2_0,0_001);
    SComponent::cLib_addCalc(&d_kankyo::g_env_light.mWindVec.z,windVec.z,0_1,2_0,0_001);
    SComponent::cLib_addCalc(&d_kankyo::g_env_light.mWindPower,(float)windStrength,0_1,1_0,0_005);
  }
  else {
    d_kankyo::g_env_light.mWindVec.x = windVec.x;
    d_kankyo::g_env_light.mWindVec.y = windVec.y;
    d_kankyo::g_env_light.mWindVec.z = windVec.z;
    d_kankyo::g_env_light.mWindPower = (float)windStrength;
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* __stdcall dKyw_get_wind_vec(void) */

cXyz * dKyw_get_wind_vec(void)

{
  return (cXyz *)&d_kankyo::g_env_light.mWindVec;
}


/* __stdcall dKyw_get_wind_pow(void) */

double dKyw_get_wind_pow(void)

{
  return (double)d_kankyo::g_env_light.mWindPower;
}


/* WARNING: Unknown calling convention yet parameter storage is locked */
/* __stdcall dKyw_get_wind_power(void) */

float * dKyw_get_wind_power(void)

{
  return &d_kankyo::g_env_light.mWindPower;
}


/* __stdcall dKyw_get_wind_vecpow(void) */

cXyz * dKyw_get_wind_vecpow(cXyz *param_1)

{
  cXyz *pcVar1;
  cXyz local_28;
  
  pcVar1 = ::cXyz::operator_(&local_28,(cXyz *)&d_kankyo::g_env_light.mWindVec,
                             d_kankyo::g_env_light.mWindPower);
  param_1->x = local_28.x;
  param_1->y = local_28.y;
  param_1->z = local_28.z;
  return pcVar1;
}


/* __stdcall dKyw_squal_set(cXyz *,
                            short,
                            short,
                            float,
                            float,
                            float,
                            float,
                            float) */

void dKyw_squal_set
               (cXyz *pPos,uint rx,uint ry,float radius,float param_5,float strength,float param_7,
               float param_8)

{
  uint uVar1;
  uint uVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  iVar6 = 5;
  do {
    if ((&d_kankyo::g_env_light.mWindInfluenceEntity[0].mbInUse)[iVar5] == 0) {
      (&d_kankyo::g_env_light.mWindInfluenceEntity[0].mbInUse)[iVar5] = 1;
      *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mMinRadius + iVar5) = param_5;
      *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mSpeed + iVar5) = param_7;
      *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mStrengthMaxVel + iVar5) =
           param_8;
      *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mPos.x + iVar5) =
           pPos->x;
      *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mPos.y + iVar5) =
           pPos->y;
      *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mPos.z + iVar5) =
           pPos->z;
      pfVar4 = JKernel::JMath::jmaCosTable;
      pfVar3 = JKernel::JMath::jmaSinTable;
      uVar2 = JKernel::JMath::jmaSinShift;
      uVar1 = rx & 0xffff;
      *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mDir.x + iVar5) =
           JKernel::JMath::jmaCosTable[(int)uVar1 >> (JKernel::JMath::jmaSinShift & 0x3f)] *
           JKernel::JMath::jmaSinTable[(int)(ry & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
      *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mDir.y + iVar5) =
           pfVar3[(int)uVar1 >> (uVar2 & 0x3f)];
      *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mDir.z + iVar5) =
           pfVar4[(int)uVar1 >> (uVar2 & 0x3f)] * pfVar4[(int)(ry & 0xffff) >> (uVar2 & 0x3f)];
      *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mRadius + iVar5) =
           radius;
      *(undefined4 *)
       ((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.field_0x20 + iVar5) =
           *(undefined4 *)
            ((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mRadius + iVar5);
      *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mStrength + iVar5) =
           strength;
      dKyw_pntwind_set((WIND_INFLUENCE *)
                       ((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mPos.x +
                       iVar5));
      return;
    }
    iVar5 = iVar5 + 0x3c;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall squal_proc(void) */

void squal_proc(void)

{
  float target;
  float speed;
  int iVar1;
  float *pfVar2;
  int i;
  
  iVar1 = 0;
  i = 0;
  do {
    pfVar2 = (float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mPos.x + i);
    if ((&d_kankyo::g_env_light.mWindInfluenceEntity[0].mbInUse)[i] == 1) {
      *pfVar2 = *pfVar2 + *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.
                                           mDir.x + i) *
                          *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mSpeed + i)
      ;
      *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mPos.y + i) =
           *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mPos.y + i) +
           *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mDir.y + i) *
           *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mSpeed + i);
      *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mPos.z + i) =
           *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mPos.z + i) +
           *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mDir.z + i) *
           *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mSpeed + i);
      SComponent::cLib_addCalc
                ((float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mStrength
                          + i),0_0,0_2,
                 *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mStrengthMaxVel + i)
                 ,0_001);
      speed = 1_0 - *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.
                                     mStrength + i);
      target = *(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mMinRadius + i);
      SComponent::cLib_addCalc
                ((float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mRadius +
                          i),target,speed,_5508 * speed * target,0_01);
      if (*(float *)((int)&d_kankyo::g_env_light.mWindInfluenceEntity[0].mInfluence.mStrength + i) <
          0_01) {
        dKyw_pntwind_cut(pfVar2);
        (&d_kankyo::g_env_light.mWindInfluenceEntity[0].mbInUse)[i] = 0;
      }
    }
    iVar1 = iVar1 + 1;
    i = i + 0x3c;
  } while (iVar1 < 5);
  return;
}


/* __stdcall dKyw_pntwind_init(void) */

void dKyw_pntwind_init(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0x1e;
  do {
    *(undefined4 *)((int)d_kankyo::g_env_light.mpWindInfluence + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = 0;
  iVar2 = 5;
  do {
    (&d_kankyo::g_env_light.mWindInfluenceEntity[0].mbInUse)[iVar1] = 0;
    iVar1 = iVar1 + 0x3c;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


/* __stdcall pntwind_set(WIND_INFLUENCE *) */

void pntwind_set(WIND_INFLUENCE *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar1 = 0;
  iVar3 = 0x1e;
  do {
    if (*(int *)((int)d_kankyo::g_env_light.mpWindInfluence + iVar1) == 0) {
      *(WIND_INFLUENCE **)((int)d_kankyo::g_env_light.mpWindInfluence + iVar1) = param_1;
      *(int *)(*(int *)((int)d_kankyo::g_env_light.mpWindInfluence + iVar1) + 0x24) = iVar2;
      break;
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (iVar2 < 0x1e) {
    return;
  }
  param_1->field_0x24 = 9999;
  return;
}


/* __stdcall dKyw_pntwind_set(WIND_INFLUENCE *) */

void dKyw_pntwind_set(WIND_INFLUENCE *param_1)

{
  param_1->mbConstant = 0;
  pntwind_set(param_1);
  return;
}


/* __stdcall dKyw_pwind_cylinder_set(WIND_INFLUENCE *) */

void dKyw_pwind_cylinder_set(WIND_INFLUENCE *param_1)

{
  param_1->mbConstant = 0;
  pntwind_set(param_1);
  return;
}


/* __stdcall dKyw_pntwind_cut(WIND_INFLUENCE *) */

void dKyw_pntwind_cut(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return;
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 < 0) {
    return;
  }
  if (0x1d < iVar1) {
    return;
  }
  d_kankyo::g_env_light.mpWindInfluence[iVar1] = (WIND_INFLUENCE *)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall dKyw_pntwind_get_info(cXyz *,
                                   cXyz *,
                                   float *) */

void dKyw_pntwind_get_info(cXyz *param_1,cXyz *pDir,float *pPow)

{
  int iVar1;
  WIND_INFLUENCE *pWindInf;
  int iVar2;
  double dVar3;
  double dVar4;
  double dist;
  float fVar5;
  float fVar6;
  cXyz local_30;
  
  fVar5 = 0_0;
  pDir->x = 0_0;
  pDir->y = fVar5;
  pDir->z = fVar5;
  *pPow = fVar5;
  iVar1 = 0;
  iVar2 = 0;
  do {
    pWindInf = *(WIND_INFLUENCE **)((int)d_kankyo::g_env_light.mpWindInfluence + iVar2);
    if (pWindInf != (WIND_INFLUENCE *)0x0) {
      fVar5 = mtx::PSVECSquareDistance(param_1,&pWindInf->mPos);
      dist = (double)fVar5;
      if ((double)0_0 < dist) {
        dVar3 = 1.0 / SQRT(dist);
        dVar3 = _5207 * dVar3 * (_5208 - dist * dVar3 * dVar3);
        dVar3 = _5207 * dVar3 * (_5208 - dist * dVar3 * dVar3);
        dist = (double)(float)(dist * _5207 * dVar3 * (_5208 - dist * dVar3 * dVar3));
      }
      if (pWindInf->mbConstant == 0) {
        dVar3 = (double)pWindInf->mRadius;
        if (dist < dVar3) {
          dVar4 = (double)0_0;
          if ((dVar4 < (double)pWindInf->mStrength) && (dVar4 != dist)) {
            fVar5 = 1_0;
            if (dVar4 < dVar3) {
              fVar5 = 1_0 - (float)(dist / dVar3) * (float)(dist / dVar3);
            }
            *pPow = (float)((double)pWindInf->mStrength * (double)fVar5);
            fVar5 = pWindInf->mRadius;
            local_30.x = (pWindInf->mPos).x + -(pWindInf->mDir).x * fVar5;
            local_30.y = (pWindInf->mPos).y + -(pWindInf->mDir).y * fVar5;
            local_30.z = (pWindInf->mPos).z + -(pWindInf->mDir).z * fVar5;
            d_kankyo_rain::dKyr_get_vectle_calc(&local_30,param_1,pDir);
            fVar6 = mtx::PSVECSquareDistance(param_1,&local_30);
            fVar5 = 0_0;
            dist = (double)fVar6;
            if ((double)0_0 < dist) {
              dVar3 = 1.0 / SQRT(dist);
              dVar3 = _5207 * dVar3 * (_5208 - dist * dVar3 * dVar3);
              dVar3 = _5207 * dVar3 * (_5208 - dist * dVar3 * dVar3);
              dist = (double)(float)(dist * _5207 * dVar3 * (_5208 - dist * dVar3 * dVar3));
            }
            if ((double)pWindInf->mRadius <= dist) {
              return;
            }
            pDir->x = 0_0;
            pDir->y = fVar5;
            pDir->z = fVar5;
            return;
          }
        }
      }
      else {
        dVar3 = (double)pWindInf->mRadius;
        if (((dist < dVar3) && (dVar4 = (double)0_0, dVar4 < (double)pWindInf->mStrength)) &&
           (dVar4 != dist)) {
          fVar5 = 1_0;
          if (dVar4 < dVar3) {
            fVar5 = 1_0 - (float)(dist / dVar3);
          }
          pDir->x = (pWindInf->mDir).x;
          pDir->y = (pWindInf->mDir).y;
          pDir->z = (pWindInf->mDir).z;
          *pPow = pWindInf->mStrength * fVar5;
          return;
        }
      }
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 4;
    if (0x1d < iVar1) {
      return;
    }
  } while( true );
}


/* __stdcall dKyw_pntwind_get_vecpow(cXyz *) */

cXyz * dKyw_pntwind_get_vecpow(cXyz *__return_storage_ptr__,cXyz *param_1)

{
  cXyz *pcVar1;
  float local_28;
  cXyz local_24;
  cXyz local_18;
  
  dKyw_pntwind_get_info(param_1,&local_18,&local_28);
  pcVar1 = ::cXyz::operator_(&local_24,&local_18,local_28);
  __return_storage_ptr__->x = local_24.x;
  __return_storage_ptr__->y = local_24.y;
  __return_storage_ptr__->z = local_24.z;
  return pcVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dKyw_get_AllWind_vec(cXyz *,
                                  cXyz *,
                                  float *) */

void dKyw_get_AllWind_vec(cXyz *param_1,cXyz *param_2,float *param_3)

{
  char cVar1;
  double dVar2;
  double dVar3;
  float fVar4;
  cXyz local_64;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  cXyz local_34;
  cXyz local_28;
  cXyz local_1c;
  
  dKyw_pntwind_get_info(param_1,param_2,param_3);
  ::cXyz::operator_(&local_40,(cXyz *)&d_kankyo::g_env_light.mWindVec,
                    d_kankyo::g_env_light.mWindPower * (1_0 - *param_3));
  local_28.x = local_40.x;
  local_28.y = local_40.y;
  local_28.z = local_40.z;
  ::cXyz::operator_(&local_4c,param_2,_5686 * *param_3);
  local_34.x = local_4c.x;
  local_34.y = local_4c.y;
  local_34.z = local_4c.z;
  ::cXyz::operator__(&local_58,&local_28,&local_34);
  local_1c.x = local_58.x;
  local_1c.y = local_58.y;
  local_1c.z = local_58.z;
  fVar4 = mtx::PSVECSquareMag(&local_1c);
  dVar3 = (double)fVar4;
  if ((double)0_0 < dVar3) {
    dVar2 = 1.0 / SQRT(dVar3);
    dVar2 = _5207 * dVar2 * (_5208 - dVar3 * dVar2 * dVar2);
    dVar2 = _5207 * dVar2 * (_5208 - dVar3 * dVar2 * dVar2);
    dVar3 = (double)(float)(dVar3 * _5207 * dVar2 * (_5208 - dVar3 * dVar2 * dVar2));
  }
  *param_3 = (float)dVar3;
  ::cXyz::normZP(&local_64,&local_1c);
  local_1c.x = local_64.x;
  local_1c.y = local_64.y;
  local_1c.z = local_64.z;
  cVar1 = ::cXyz::operator___(&local_1c,&::cXyz::Zero);
  if (cVar1 == '\0') {
    param_2->x = d_kankyo::g_env_light.mWindVec.x;
    param_2->y = d_kankyo::g_env_light.mWindVec.y;
    param_2->z = d_kankyo::g_env_light.mWindVec.z;
  }
  else {
    param_2->x = local_1c.x;
    param_2->y = local_1c.y;
    param_2->z = local_1c.z;
  }
  return;
}


/* __stdcall dKyw_get_AllWind_vecpow(cXyz *) */

void dKyw_get_AllWind_vecpow(float *param_1,cXyz *param_2)

{
  float local_68;
  cXyz local_64;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  cXyz local_34;
  cXyz local_28;
  
  dKyw_pntwind_get_info(param_2,&local_40,&local_68);
  ::cXyz::operator_(&local_4c,(cXyz *)&d_kankyo::g_env_light.mWindVec,
                    d_kankyo::g_env_light.mWindPower * (1_0 - local_68));
  local_28.x = local_4c.x;
  local_28.y = local_4c.y;
  local_28.z = local_4c.z;
  ::cXyz::operator_(&local_58,&local_40,_5686 * local_68);
  local_34.x = local_58.x;
  local_34.y = local_58.y;
  local_34.z = local_58.z;
  ::cXyz::operator__(&local_64,&local_28,&local_34);
  *param_1 = local_64.x;
  param_1[1] = local_64.y;
  param_1[2] = local_64.z;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dKyw_tact_wind_set(short,
                                short) */

void dKyw_tact_wind_set(short param_1,short param_2)

{
  cXyz *pcVar1;
  int iVar2;
  
  pcVar1 = dKyw_get_wind_vec();
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mTactWindAngleX = param_1;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mTactWindAngleY = param_2;
  d_kankyo::g_env_light.mTactWindAngleX = param_1;
  d_kankyo::g_env_light.mTactWindAngleY = param_2;
  iVar2 = SComponent::cM_atan2s(pcVar1->x,pcVar1->z);
  d_kankyo::g_env_light.mTactWindAngleFlags = 1;
  if ((short)(-d_kankyo::g_env_light.mTactWindAngleY - ((short)iVar2 + 0x4000)) < 0) {
    d_kankyo::g_env_light.mTactWindAngleFlags = 0x81;
  }
  return;
}


/* __stdcall dKyw_tact_wind_set_go(void) */

void dKyw_tact_wind_set_go(void)

{
  d_kankyo::g_env_light.mTactWindAngleFlags = d_kankyo::g_env_light.mTactWindAngleFlags | 1;
  d_kankyo::g_env_light.mEvtWindSet = 0xff;
  return;
}


/* __stdcall dKyw_get_tactwind_dir(void) */

undefined4 dKyw_get_tactwind_dir(void)

{
  if ((d_kankyo::g_env_light.mTactWindAngleFlags & 0x80) == 0) {
    return 0;
  }
  return 1;
}


/* __stdcall dKyw_custom_windpower(float) */

void dKyw_custom_windpower(double param_1)

{
  d_kankyo::g_env_light.mCustomWindPower = (float)param_1;
  return;
}


/* __stdcall dKyw_get_windsdir(void) */

undefined4 dKyw_get_windsdir(void)

{
  uint uVar1;
  cXyz *pcVar2;
  int iVar3;
  undefined4 unaff_r31;
  int iVar4;
  
  pcVar2 = dKyw_get_wind_vec();
  iVar3 = SComponent::cM_atan2s(pcVar2->x,pcVar2->z);
  uVar1 = -(iVar3 + 0x4000) & 0xffff;
  iVar3 = 0;
  iVar4 = 9;
  do {
    if ((*(ushort *)((int)&wind_table_5764 + iVar3) <= uVar1) &&
       (uVar1 < *(ushort *)((int)&DAT_80352c92 + iVar3))) {
      unaff_r31 = *(undefined4 *)((int)&DAT_80352c94 + iVar3);
    }
    iVar3 = iVar3 + 8;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return unaff_r31;
}


/* __stdcall dKyw_evt_wind_set(short,
                               short) */

void dKyw_evt_wind_set(short param_1,short param_2)

{
  d_kankyo::g_env_light.mEvtWindAngleX = param_1;
  d_kankyo::g_env_light.mEvtWindAngleY = param_2;
  return;
}


/* __stdcall dKyw_evt_wind_set_go(void) */

void dKyw_evt_wind_set_go(void)

{
  d_kankyo::g_env_light.mEvtWindSet = 1;
  return;
}


/* __stdcall dKyw_gbwind_use_check(void) */

undefined4 dKyw_gbwind_use_check(void)

{
  uint *puVar1;
  dStage_roomStatus_c *pdVar2;
  undefined4 uVar3;
  
  puVar1 = (uint *)0x0;
  uVar3 = 0;
  if (d_kankyo::g_env_light.mpWindVecOverride == (cXyz *)0x0) {
    if (-1 < (char)dStage_roomControl_c::mStayNo) {
      pdVar2 = dStage_roomControl_c::getStatusRoomDt
                         (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                          (int)(char)dStage_roomControl_c::mStayNo);
      puVar1 = (uint *)(*(code *)((pdVar2->parent).parent.vtbl)->getFileListInfo)();
    }
    if ((puVar1 != (uint *)0x0) && ((*puVar1 >> 0x12 & 3) < 3)) {
      uVar3 = 1;
    }
  }
  return uVar3;
}


/* __stdcall dKyw_tornado_Notice(cXyz *) */

void dKyw_tornado_Notice(undefined4 *param_1)

{
  d_kankyo::g_env_light._2444_4_ = *param_1;
  d_kankyo::g_env_light.field_0x990 = (float)param_1[1];
  d_kankyo::g_env_light._2452_4_ = param_1[2];
  return;
}


/* __stdcall dKyw_rain_set(int) */

void dKyw_rain_set(int param_1)

{
  d_kankyo::g_env_light.mRainCount = param_1;
  d_kankyo::g_env_light.mRainCountOrig = param_1;
  return;
}

