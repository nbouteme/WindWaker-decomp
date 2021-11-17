#pragma once
#include <ctypes.h>

#include <cXyz.h>


namespace d_kankyo_wether {
//Expected size is 0x00000c
extern struct cXyz r09o$5110;

//Expected size is 0x000001
extern undefined1 init$5112;

J3DPacket * dKyw_setDrawPacketList(J3DPacket *param_1,int param_2);
void dKyw_setDrawPacketListSky(J3DPacket *param_1,int param_2);
J3DPacket * dKyw_setDrawPacketListXluBg(J3DPacket *param_1,int param_2);
J3DPacket * dKyw_setDrawPacketListXluZPos(J3DPacket *param_1,cXyz *param_2);
}

namespace d_kankyo_wether {
void dKyw_drawSun(int param_1);
void dKyw_Sun_Draw(void);
void dKyw_drawSunlenz(int param_1);
void dKyw_Sunlenz_Draw(void);
void dKyw_drawRain(int param_1);
void dKyw_Rain_Draw(void);
void dKyw_drawSnow(int param_1);
void dKyw_Snow_Draw(void);
void dKyw_drawStar(int param_1);
void dKyw_Star_Draw(void);
void dKyw_drawPoison(void);
void dKyw_Poison_Draw(void);
void dKyw_drawHousi(int param_1);
void dKyw_Housi_Draw(void);
void dKyw_drawCloud(int param_1);
void dKyw_Cloud_Draw(void);
void dKyw_drawVrkumo(int param_1);
void dKyw_Vrkumo_Draw(void);
void dKyw_drawWave(undefined4 param_1);
void dKyw_Wave_Draw(void);
void dKyw_wether_init(void);
void dKyw_wether_init2(void);
void dKyw_wether_delete(void);
}

namespace d_kankyo_wether {
void dKyw_wether_delete2(void);
}

namespace d_kankyo_wether {
void wether_move_windline(void);
}

namespace d_kankyo_wether {
void wether_move_thunder(void);
void dKyw_wether_move(void);
void wether_move_sun(void);
void wether_move_rain(void);
void wether_move_snow(void);
void wether_move_star(void);
void wether_move_poison(void);
void wether_move_housi(void);
void wether_move_moya(void);
void wether_move_vrkumo(void);
void wether_move_wave(void);
void dKyw_wether_move_draw(void);
void dKyw_wether_move_draw2(void);
void dKyw_wether_draw(void);
void dKyw_wether_draw2(void);
void dKyw_wether_proc(void);
void dKyw_wind_init(void);
void dKyw_wind_set(void);
cXyz * dKyw_get_wind_vec(void);
double dKyw_get_wind_pow(void);
float * dKyw_get_wind_power(void);
cXyz * dKyw_get_wind_vecpow(cXyz *param_1);
void dKyw_squal_set(cXyz *pPos,uint rx,uint ry,float radius,float param_5,float strength,float param_7,float param_8);
void squal_proc(void);
void dKyw_pntwind_init(void);
void pntwind_set(WIND_INFLUENCE *param_1);
void dKyw_pntwind_set(WIND_INFLUENCE *param_1);
void dKyw_pwind_cylinder_set(WIND_INFLUENCE *param_1);
void dKyw_pntwind_cut(int param_1);
void dKyw_pntwind_get_info(cXyz *param_1,cXyz *pDir,float *pPow);
cXyz * dKyw_pntwind_get_vecpow(cXyz *__return_storage_ptr__,cXyz *param_1);
void dKyw_get_AllWind_vec(cXyz *param_1,cXyz *param_2,float *param_3);
void dKyw_get_AllWind_vecpow(float *param_1,cXyz *param_2);
void dKyw_tact_wind_set(short param_1,short param_2);
void dKyw_tact_wind_set_go(void);
undefined4 dKyw_get_tactwind_dir(void);
void dKyw_custom_windpower(double param_1);
undefined4 dKyw_get_windsdir(void);
void dKyw_evt_wind_set(short param_1,short param_2);
void dKyw_evt_wind_set_go(void);
undefined4 dKyw_gbwind_use_check(void);
void dKyw_tornado_Notice(undefined4 *param_1);
void dKyw_rain_set(int param_1);
}
