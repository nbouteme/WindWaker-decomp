#pragma once
#include <ctypes.h>

#include <cBgS_Chk__vtbl.h>

//[Data] Expected size is 0x00000c
extern pointer dSnap_Obj;

//[Data] Expected size is 0x000030
extern pointer dBgS_RoofChk;

//[Data] Expected size is 0x000030
extern struct cBgS_Chk__vtbl dBgS_ObjGndChk_All;


namespace d_kankyo_rain {
//[Data] Expected size is 0x000004
extern undefined4 now_room;

//[BSS] Expected size is 0x000030
extern struct cXyz add_table$9024[4];
//[BSS] Expected size is 0x000060
extern undefined4 add_table$9810;
//[BSS] Expected size is 0x000030
extern struct cXyz add_table$10284[4];
//[BSS] Expected size is 0x000060
extern struct csXyz hokuto_position$10494[16];
//[BSS] Expected size is 0x000030
extern struct cXyz add_table$10878[4];
//[BSS] Expected size is 0x000004
extern int rot$8999;
//[BSS] Expected size is 0x000001
extern undefined1 init$9000;
//[BSS] Expected size is 0x000001
extern undefined1 init$9026;
//[BSS] Expected size is 0x000004
extern float rot$9395;
//[BSS] Expected size is 0x000001
extern undefined1 init$9396;
//[BSS] Expected size is 0x000004
extern undefined4 rot$9557;
//[BSS] Expected size is 0x000001
extern undefined1 init$9558;
//[BSS] Expected size is 0x000004
extern float rot$9747;
//[BSS] Expected size is 0x000001
extern undefined1 init$9748;
//[BSS] Expected size is 0x000001
extern undefined1 init$9812;
//[BSS] Expected size is 0x000004
extern float rot$10261;
//[BSS] Expected size is 0x000001
extern undefined1 init$10262;
//[BSS] Expected size is 0x000001
extern undefined1 init$10286;
//[BSS] Expected size is 0x000004
extern undefined4 rot$10491;
//[BSS] Expected size is 0x000001
extern undefined1 init$10492;
//[BSS] Expected size is 0x000001
extern undefined1 init$10496;
//[BSS] Expected size is 0x000001
extern undefined1 init$10880;
//[BSS] Expected size is 0x000004
extern float rot$11076;
//[BSS] Expected size is 0x000001
extern undefined1 init$11077;
//[BSS] Expected size is 0x000004
extern float howa_loop_cnt$11254;
//[BSS] Expected size is 0x000001
extern undefined1 init$11255;
float vectle_calc(DOUBLE_POS *param_1,cXyz *param_2);
float get_vectle_calc(cXyz *param_1,cXyz *param_2,cXyz *param_3);
float dKyr_get_vectle_calc(cXyz *param_1,cXyz *param_2,cXyz *param_3);
void dKy_set_eyevect_calc(camera_class *param_1,cXyz *param_2,double scaleXZ,double scaleY);
void dKy_set_eyevect_calc2(camera_class *param_1,cXyz *param_2,float scaleXZ,float scaleY);
void dKyr_set_btitex(GXTexObj *param_1,_GXTexFmt *param_2);
void dKyr_kamome_move(void);
void dKyr_wind_init(void);
void dKyr_wind_move(void);
}

namespace d_kankyo_rain {
void dKyr_lenzflare_move(void);
undefined4 dKyr_moon_arrival_check(void);
void dKyr_sun_move(void);
void dKyr_rain_init(void);
void rain_bg_chk(dKankyo_rain_Packet *param_1,int param_2);
bool overhead_bg_chk(void);
}

namespace d_kankyo_rain {
bool forward_overhead_bg_chk(cXyz *param_1,float param_2);
void dKyr_rain_move(void);
void dKyr_housi_move(void);
void dKyr_snow_init(void);
void dKyr_snow_move(void);
void dKyr_kazanbai_move(void);
void dKyr_kazanbai_tamari_move(void);
void dKyr_star_init(void);
void dKyr_star_move(void);
void wave_move(void);
void cloud_shadow_move(void);
undefined4 light_at_hit_check(cXyz *param_1);
undefined4 dKyr_poison_live_check(void);
void dKyr_poison_light_colision(void);
void poison_init(void);
void poison_move(void);
void vrkumo_move(void);
void dKy_wave_chan_init(void);
void snap_sunmoon_proc(float *param_1,int param_2);
void dKyr_drawSun(MTX34 *param_1,cXyz *param_2,_GXColor *param_3,byte **param_4);
void dKyr_drawLenzflare(MTX34 *param_1,cXyz *param_2,_GXColor *param_3,void **param_4);
void dKyr_drawRain(MTX34 *param_1,void **param_2);
void dKyr_drawSibuki(MTX34 *param_1,int param_2);
void drawPoison(MTX34 *param_1,undefined4 *param_2);
void dKyr_drawHousi(MTX34 *param_1,char *pTex);
void dKyr_drawKazanbai(MTX34 *param_1,int *param_2);
void dKyr_drawSnow(MTX34 *param_1,void **param_2);
void dKyr_drawStar(MTX34 *param_1,char *pTexData);
void drawWave(MTX34 *param_1,byte *param_2);
void drawCloudShadow(MTX34 *param_1,char *param_2);
void drawVrkumo(MTX34 *param_1,_GXColor *param_2,uchar *param_3);
void dKyr_thunder_init(void);
void dKyr_thunder_move(void);
}
