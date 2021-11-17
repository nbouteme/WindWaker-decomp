#pragma once
#include <ctypes.h>

#include <dScnKy_env_light_c.h>


namespace d_kankyo {
//Expected size is 0x000c9c
extern struct dScnKy_env_light_c g_env_light;

//Expected size is 0x000740
extern struct dKy_setLight__Status lightStatusData[8];

//Expected size is 0x000004
extern float target$6206;

//Expected size is 0x000001
extern undefined1 init$6207;

//Expected size is 0x000004
extern float target$6225;

//Expected size is 0x000001
extern byte init$6226;

int toon_proc_check(void);
int u8_data_ratio_set(double param_1,uint param_2,uint param_3);
int s16_data_ratio_set(short param_1,short param_2,float param_3);
int kankyo_color_ratio_set(byte b0A,byte b0B,float blendAB,byte b1A,uchar b1B,float blend01,short add,float mul);
double fl_data_ratio_set(float param_1,float param_2,float param_3);
double float_kankyo_color_ratio_set(double param_1,double param_2,double param_3,double param_4,double param_5,double param_6,double param_7,double param_8);
double get_parcent(double param_1,double param_2,double param_3);
int dKy_light_influence_id(cXyz *param_1,int param_2);
int dKy_eflight_influence_id(cXyz *param_1,int param_2);
void dKy_eflight_influence_pos(float *param_1,int param_2);
_GXColorS10 dKy_light_influence_col(uint param_1);
double dKy_light_influence_power(uint param_1);
double dKy_light_influence_yuragi(uint param_1);
float dKy_light_influence_distance(cXyz *param_1,uint param_2);
_GXColorS10 dKy_eflight_influence_col(uint param_1);
double dKy_eflight_influence_power(uint param_1);
double dKy_eflight_influence_yuragi(uint param_1);
double dKy_eflight_influence_distance(cXyz *param_1,uint param_2);
void plight_init(void);
void plight_set(void);
void envcolor_init(void);
}

namespace dStage_roomControl_c {
uint GetTimePass(void);
}

namespace d_kankyo {
int dKy_getdaytime_hour(void);
int dKy_getdaytime_minute(void);
bool dKy_daynight_check(void);
}

namespace d_kankyo {
void setLightTevColorType_sub(J3DMaterial *pMaterial,dKy_tevstr_c *pTevStr);
}

namespace d_kankyo {
void dKy_event_init(void);
void dice_wether_init(byte param_1,float param_2,float param_3);
void dice_wether_execute(byte param_1,float param_2,float curTime);
void dice_rain_minus(void);
undefined4 phantomship_wether(void);
void dKy_event_proc(void);
}

namespace d_kankyo {
undefined4 dKy_Draw(void);
undefined4 dKy_Execute(void);
undefined4 dKy_IsDelete(void);
undefined4 dKy_Delete(void);
undefined4 dKy_Create(void);
void dKy_setLight_init(void);
void dKy_setLight(void);
void dKy_setLight_again(void);
undefined4 dKy_Get_DifCol(void);
void dKy_light_influence_pos(cXyz *param_1,int param_2);
void dKy_plight_near_pos(TVec3<float> *param_1);
void dKy_plight_set(LIGHT_INFLUENCE *param_1);
double dKy_yuragi_ratio_set(double param_1);
void dKy_plight_priority_set(LIGHT_INFLUENCE *param_1);
void dKy_plight_cut(LIGHT_INFLUENCE *param_1);
void dKy_efplight_set(LIGHT_INFLUENCE *param_1);
void dKy_efplight_cut(LIGHT_INFLUENCE *param_1);
void dKy_actor_addcol_amb_set(double param_1,short param_2,short param_3,short param_4);
void dKy_actor_addcol_dif_set(double param_1,short param_2,short param_3,short param_4);
void dKy_bg_addcol_amb_set(double param_1,short param_2,short param_3,short param_4);
void dKy_bg_addcol_dif_set(double param_1,short param_2,short param_3,short param_4);
void dKy_bg1_addcol_amb_set(double param_1,short param_2,short param_3,short param_4);
void dKy_bg1_addcol_dif_set(double param_1,short param_2,short param_3,short param_4);
void dKy_bg2_addcol_amb_set(double param_1,short param_2,short param_3,short param_4);
void dKy_bg2_addcol_dif_set(double param_1,short param_2,short param_3,short param_4);
void dKy_bg3_addcol_amb_set(double param_1,short param_2,short param_3,short param_4);
void dKy_bg3_addcol_dif_set(double param_1,short param_2,short param_3,short param_4);
void dKy_addcol_fog_set(double param_1,short param_2,short param_3,short param_4);
void dKy_actor_addcol_set(short param_1,short param_2,short param_3,float param_4);
void dKy_vrbox_addcol_sky0_set(short param_1,short param_2,short param_3,double param_4);
void dKy_vrbox_addcol_kasumi_set(short param_1,short param_2,short param_3,double param_4);
void dKy_vrbox_addcol_set(short param_1,short param_2,short param_3,float param_4);
void dKy_fog_startendz_set(float param_1,float param_2,float param_3);
void dKy_Itemgetcol_chg_on(void);
void dKy_Itemgetcol_chg_off(void);
void dKy_Itemgetcol_chg_move(void);
void dKy_arrowcol_chg_on(undefined4 param_1,int param_2);
void dKy_arrowcol_chg_move(void);
undefined4 dKy_checkEventNightStop(void);
void dKy_Sound_init(void);
void dKy_Sound_set(cXyz *param_1,int param_2,uint param_3,int param_4);
undefined4 dKy_Sound_get(void);
void dKy_SordFlush_set(cXyz *pPos,int param_2);
void dKy_FirstlightVec_get(float *param_1,float *param_2);
void GxFogSet_Sub(_GXColor *param_1);
void GxFog_set(void);
void GxFog_sea_set(void);
void dKy_GxFog_set(void);
void dKy_GxFog_sea_set(void);
void dKy_GxFog_tevstr_set(dKy_tevstr_c *param_1);
void dKy_GfFog_tevstr_set(dKy_tevstr_c *param_1);
void GxXFog_set(void);
void dKy_change_colset(byte param_1,byte param_2,float param_3);
void dKy_change_colpat(byte param_1);
void dKy_custom_colset(byte param_1,byte param_2,float blend);
void dKy_custom_timeset(float param_1);
void dKy_setLight_mine(dKy_tevstr_c *param_1);
void dKy_tevstr_init(dKy_tevstr_c *this,char roomNo,uchar param_3);
int dKy_rain_check(void);
void dKy_usonami_set(double param_1);
byte dKy_get_schbit(void);
int dKy_get_schbit_timer(void);
void dKy_get_seacolor(_GXColor *param_1,_GXColor *param_2);
void dKy_set_allcol_ratio(double param_1);
void dKy_set_actcol_ratio(double param_1);
void dKy_set_bgcol_ratio(double param_1);
void dKy_set_fogcol_ratio(double param_1);
void dKy_set_vrboxcol_ratio(double param_1);
void dKy_set_vrboxsoracol_ratio(float param_1);
void dKy_set_vrboxkumocol_ratio(float param_1);
void dKy_itudemo_se(void);
void dKy_contrast_flg_set(byte param_1);
byte dKy_contrast_flg_get(void);
uint dKy_get_dayofweek(void);
void dKy_set_nexttime(double param_1);
void dKy_DayProc(void);
void dKy_instant_timechg(double param_1);
void dKy_instant_rainchg(void);
int dKy_moon_type_chk(void);
bool dKy_telescope_lookin_chk(cXyz *param_1,float param_2,float param_3);
undefined dKy_moon_look_chk(void);
undefined dKy_orion_look_chk(void);
undefined dKy_hokuto_look_chk(void);
void dKy_get_moon_pos(TVec3<float> *param_1);
void dKy_get_hokuto_pos(float *param_1);
void dKy_get_orion_pos(TVec3<float> *param_1);
void dKy_pship_existense_set(void);
void dKy_pship_existense_cut(void);
undefined dKy_pship_existense_chk(void);
undefined4 dKy_daynighttact_stop_chk(void);
undefined4 dKyr_player_overhead_bg_chk(void);
}

namespace d_kankyo {
void __sinit_d_kankyo_cpp(void);
void dKankyo_DayProc(void);
}
