#pragma once
#include <ctypes.h>

#include <dDlst_2Dm_c.h>
#include <mapCtrlDisp_c.h>


namespace d_meter {
//Expected size is 0x000038
extern undefined item_parts;

//Expected size is 0x000020
extern undefined g_meter_mapHIO;

//Expected size is 0x000158
extern undefined g_meterHIO;

//Expected size is 0x0000cc
extern undefined g_menuHIO;

//Expected size is 0x00008c
extern undefined g_msgHIO;

//Expected size is 0x000084
extern undefined g_messageHIO;

//Expected size is 0x000084
extern struct dDlst_2Dm_c tekari;

//Expected size is 0x00018c
extern undefined clock;

//Expected size is 0x000002
extern undefined1 dMeter_Info;

//Expected size is 0x000004
extern struct dMetronome_c * dMn_c;

//Expected size is 0x000004
extern undefined4 sMainParts1;

//Expected size is 0x000004
extern undefined4 sMainParts2;

//Expected size is 0x000004
extern undefined4 sMainParts3;

//Expected size is 0x000004
extern struct J2DScreen * sScrTimer1;

//Expected size is 0x000004
extern struct J2DScreen * sScrTimer2;

//Expected size is 0x000004
extern undefined4 sChoiceRoad;

//Expected size is 0x000004
extern undefined4 moveItemPane;

//Expected size is 0x000001
extern undefined1 mapAlpha;

//Expected size is 0x000001
extern undefined1 menu_status;

//Expected size is 0x000001
extern undefined1 menu_status_old;

//Expected size is 0x000001
extern byte dMenu_pause;

//Expected size is 0x000004
extern undefined4 dMenu_frame_timer;

//Expected size is 0x000001
extern undefined1 dMenu_menuButton;

//Expected size is 0x000001
extern undefined1 subWinFlag;

//Expected size is 0x000001
extern undefined1 dMeter_auctionFlag;

//Expected size is 0x000001
extern undefined1 dMeter_itemMoveFlag;

//Expected size is 0x000001
extern undefined1 dMeter_btn_chk;

//Expected size is 0x000001
extern undefined1 dMeter_itemNum;

//Expected size is 0x000002
extern undefined2 dMeter_itemTimer;

//Expected size is 0x000004
extern float texRateX;

//Expected size is 0x000004
extern float texRateY;

//Expected size is 0x000004
extern float texScaleX;

//Expected size is 0x000004
extern float texScaleY;

//Expected size is 0x000001
extern undefined1 dMenu_menuFlag;

//Expected size is 0x000008
extern undefined dMenu_baitNum;

//Expected size is 0x000001
extern undefined1 dMeter_place_name;

//Expected size is 0x000001
extern undefined1 dMeter_itemMode;

//Expected size is 0x000001
extern undefined1 dMeter_collectMode;

//Expected size is 0x000001
extern undefined1 dMeter_windStatus;

//Expected size is 0x000001
extern undefined1 rupy_soundSetFlag;

//Expected size is 0x000001
extern undefined1 rupy_soundOnFlag;

//Expected size is 0x000006
extern struct mapCtrlDisp_c dMeter_mMapCtrlDisp;

//Expected size is 0x000004
extern undefined4 meter1;

//Expected size is 0x000004
extern undefined4 meter2;

//Expected size is 0x000001
extern bool soundOnFlag$5563;

//Expected size is 0x000001
extern undefined1 init$5564;

//Expected size is 0x000001
extern undefined1 point$5650;

//Expected size is 0x000001
extern undefined1 init$5651;

//Expected size is 0x000001
extern undefined1 flag$5797;

//Expected size is 0x000001
extern undefined1 init$5798;

//Expected size is 0x000002
extern undefined2 moveNowFrame$6064;

//Expected size is 0x000001
extern undefined1 init$6065;

//Expected size is 0x000002
extern undefined2 moveFlag$6067;

//Expected size is 0x000001
extern undefined1 init$6068;

//Expected size is 0x000002
extern undefined2 moveStatus$6070;

//Expected size is 0x000001
extern undefined1 init$6071;

//Expected size is 0x000004
extern float nowX$6073;

//Expected size is 0x000001
extern undefined1 init$6074;

//Expected size is 0x000004
extern float nowY$6076;

//Expected size is 0x000001
extern undefined1 init$6077;

//Expected size is 0x000004
extern float expX$6079;

//Expected size is 0x000001
extern undefined1 init$6080;

//Expected size is 0x000004
extern float expY$6082;

//Expected size is 0x000001
extern undefined1 init$6083;

//Expected size is 0x000002
extern undefined2 alphaNowFrame$6279;

//Expected size is 0x000001
extern undefined1 init$6280;

//Expected size is 0x000002
extern undefined2 moveNowFrame$6602;

//Expected size is 0x000001
extern undefined1 init$6603;

//Expected size is 0x000002
extern undefined2 moveFlag$6605;

//Expected size is 0x000001
extern undefined1 init$6606;

//Expected size is 0x000002
extern undefined2 moveStatus$6608;

//Expected size is 0x000001
extern undefined1 init$6609;

//Expected size is 0x000004
extern float nowX$6611;

//Expected size is 0x000001
extern undefined1 init$6612;

//Expected size is 0x000004
extern float nowY$6614;

//Expected size is 0x000001
extern undefined1 init$6615;

//Expected size is 0x000004
extern float expX$6617;

//Expected size is 0x000001
extern undefined1 init$6618;

//Expected size is 0x000004
extern float expY$6620;

//Expected size is 0x000001
extern undefined1 init$6621;

//Expected size is 0x000002
extern undefined2 alphaNowFrame$6814;

//Expected size is 0x000001
extern undefined1 init$6815;

//Expected size is 0x000001
extern undefined1 arrowMax$7632;

//Expected size is 0x000001
extern undefined1 init$7633;

//Expected size is 0x000001
extern undefined1 bombMax$7635;

//Expected size is 0x000001
extern undefined1 init$7636;

//Expected size is 0x000002
extern undefined2 moveNowFrame$8368;

//Expected size is 0x000001
extern undefined1 init$8369;

//Expected size is 0x000002
extern undefined2 moveFlag$8371;

//Expected size is 0x000001
extern undefined1 init$8372;

//Expected size is 0x000002
extern undefined2 moveStatus$8374;

//Expected size is 0x000001
extern undefined1 init$8375;

//Expected size is 0x000004
extern float nowX$8377;

//Expected size is 0x000001
extern undefined1 init$8378;

//Expected size is 0x000004
extern float nowY$8380;

//Expected size is 0x000001
extern undefined1 init$8381;

//Expected size is 0x000002
extern undefined2 alphaNowFrame$8563;

//Expected size is 0x000001
extern undefined1 init$8564;

//Expected size is 0x000002
extern undefined2 moveNowFrame$8633;

//Expected size is 0x000001
extern undefined1 init$8634;

//Expected size is 0x000002
extern undefined2 moveFlag$8636;

//Expected size is 0x000001
extern undefined1 init$8637;

//Expected size is 0x000002
extern undefined2 moveStatus$8639;

//Expected size is 0x000001
extern undefined1 init$8640;

//Expected size is 0x000004
extern float nowX$8642;

//Expected size is 0x000001
extern undefined1 init$8643;

//Expected size is 0x000004
extern float nowY$8645;

//Expected size is 0x000001
extern undefined1 init$8646;

//Expected size is 0x000001
extern undefined1 bossEyeFlag$9082;

//Expected size is 0x000001
extern undefined1 init$9083;

//Expected size is 0x000001
extern undefined1 soundOnFlag$9201;

//Expected size is 0x000001
extern undefined1 init$9202;

//Expected size is 0x000001
extern undefined1 frame$9916;

//Expected size is 0x000001
extern undefined1 init$9917;

//Expected size is 0x000002
extern undefined2 moveFlag$9962;

//Expected size is 0x000001
extern undefined1 init$9963;

//Expected size is 0x000002
extern undefined2 moveStatus$9965;

//Expected size is 0x000001
extern undefined1 init$9966;

//Expected size is 0x000002
extern undefined2 mapTimer$11802;

//Expected size is 0x000001
extern undefined1 init$11803;

//Expected size is 0x000001
extern undefined1 stageFlag$11805;

//Expected size is 0x000001
extern undefined1 init$11806;

//Expected size is 0x000004
extern undefined4 stayNo$11808;

//Expected size is 0x000001
extern undefined1 init$11809;

//Expected size is 0x000001
extern undefined1 arrowType$11959;

//Expected size is 0x000001
extern undefined1 init$11960;

//Expected size is 0x000001
extern undefined1 oldType$11962;

//Expected size is 0x000001
extern undefined1 init$11963;

//Expected size is 0x000004
extern float dist_buf$12565;

//Expected size is 0x000001
extern undefined1 init$12566;

}

namespace d_meter {
void dMeter_mtrShow(void);
void dMeter_mtrHide(void);
void dMenu_setMenuStatus(undefined param_1);
void dMenu_setMenuStatusOld(char param_1);
byte dMenu_getMenuStatus(void);
undefined dMenu_getCollectMode(void);
void dMenu_setCollectMode(undefined param_1);
undefined dMenu_getItemMode(void);
void dMenu_setItemMode(undefined param_1);
undefined dMeter_subWinFlag(void);
void dMeter_subWinFlagOn(void);
void dMeter_subWinFlagOff(void);
undefined dMeter_isAuctionFlag(void);
void dMeter_onAuctionFlag(void);
void dMeter_offAuctionFlag(void);
void dMeter_itemMoveSet(int param_1,undefined param_2,undefined param_3);
undefined dMeter_itemMoveFlagCheck(void);
byte dMenu_flag(void);
void dMenu_flagSet(byte param_1);
undefined4 dMenu_timer(void);
undefined dMenu_getPushMenuButton(void);
void dMenu_setPushMenuButton(undefined param_1);
void dMeter_PaneHide(int *param_1);
bool dMeter_isBit8(byte *param_1,byte param_2);
void dMeter_onBit8(byte *param_1,byte param_2);
void dMeter_offBit8(byte *param_1,byte param_2);
void dMeter_PaneShow(int *param_1);
void dMeter_alphaControl(sub_meter_class *this);
void dMeter_statusCheck(int param_1);
double dMeter_alphaClose(short *param_1,short *param_2);
double dMeter_alphaOpen(short *param_1,short *param_2);
void dMeter_rupy_num(char *pDst,short num);
char * dMeter_actionTex(ushort param_1);
undefined * dMeter_weponTex(void);
undefined * dMeter_heartTex(short param_1);
void dMeter_recollect_boss_data(void);
}

namespace d_meter {
void dMeter_heart_data_set(fopMsgM_pane_class *param_1,fopMsgM_pane_class *param_2,fopMsgM_pane_class *param_3);
void dMeter_paneBottomScaleY(double param_1,fopMsgM_pane_class *param_2);
void dMeter_parentPaneTrans(double param_1,fopMsgM_pane_class *param_2);
void dMeter_childPaneTrans(double param_1,fopMsgM_pane_class *param_2,int param_3);
void dMeter_childPaneTransOnly(double param_1,double param_2,fopMsgM_pane_class *param_3,int param_4);
void dMeter_childPaneTransChildTrans(double param_1,double param_2,fopMsgM_pane_class *param_3,int param_4,int param_5);
void dMeter_childPaneTransChildTransOnly(double param_1,fopMsgM_pane_class *param_2,int param_3);
void dMeter_setHeartScaleXY(fopMsgM_pane_class *this,short scale);
void dMeter_setHeartScaleXY2(fopMsgM_pane_class *this,short scale);
void dMeter_setNowHeartScaleXY(fopMsgM_pane_class *param_1);
void dMeter_setNowHeartScaleXY2(fopMsgM_pane_class *param_1);
void dMeter_heartChangeTexture(int param_1,char *param_2,int param_3);
void dMeter_heartScaleInit(sub_meter_class *this);
void dMeter_maxLifeChange(int param_1);
void dMeter_lifeChange(sub_meter_class *this,bool *param_2);
void dMeter_heartLightMove(sub_meter_class *this);
void dMeter_heartAlpha(sub_meter_class *this);
void dMeter_heartInit(sub_meter_class *this);
void dMeter_LifeMove(sub_meter_class *this,bool bForce);
void dMeter_BattleLifeMove(int param_1,char param_2);
void dMeter_heartColor(int param_1);
void dMeter_heartMove(sub_meter_class *param_1);
void dMeter_heartDraw(int param_1);
void dMeter_weponInit(sub_meter_class *this);
void dMeter_weponMove(sub_meter_class *this);
void dMeter_weponDraw(int param_1);
void dMeter_weponChange(int param_1);
void dMeter_weponAnime(int param_1);
void dMeter_weponTrans(int param_1);
void dMeter_weponAlpha(int param_1);
void dMeter_actionInit(int param_1);
void dMeter_actionMove(sub_meter_class *param_1);
void dMeter_actionDraw(int param_1);
void dMeter_actionForce(int param_1);
void dMeter_actionChange(sub_meter_class *pMeter);
void dMeter_actionTrans(int param_1);
void dMeter_actionAlpha(int param_1);
void dMeter_numberSet(J2DPicture *param_1,byte param_2);
void dMeter_numberColor(int param_1,char param_2,char param_3);
void dMeter_xyInit(int param_1);
void dMeter_xyMove(int param_1);
void dMeter_xyDraw(int param_1);
undefined4 dMeter_xyEquipItem(int param_1);
void dMeter_xyItemNumberSet(int param_1,int param_2);
void dMeter_xyBowLightAnime(int param_1,int param_2);
void dMeter_xyItemCountUp(int param_1);
void dMeter_xyItemChange(int param_1,int param_2);
void dMeter_xyRotateZ(double param_1,double param_2,int **param_3);
void dMeter_xyAlpha(int param_1);
void dMeter_xyTrans(int param_1);
void dMeter_rInit(int param_1);
void dMeter_rMove(sub_meter_class *param_1);
void dMeter_rDraw(int param_1);
void dMeter_rAlpha(sub_meter_class *this);
void dMeter_rTrans(int param_1);
void dMeter_enemyInit(int param_1);
void dMeter_enemyMove(int param_1);
void dMeter_zakoEnemyMove(int param_1);
void dMeter_bossEnemyMove(int param_1,int param_2);
void dMeter_zakoEnemyHide(int param_1);
void dMeter_bossEnemyHide(int param_1);
void dMeter_bossAnime(int param_1);
void dMeter_bossEyeAnime(int param_1);
void dMeter_magicInit(int param_1);
void dMeter_magicMove(int param_1);
void dMeter_magicGaugeMove(int param_1);
void dMeter_flyGaugeMove(int param_1,char param_2,short param_3,short param_4);
void dMeter_magicChange(double param_1,int param_2);
void dMeter_magicTransNowInit(int param_1);
void dMeter_magicInitTrans(int param_1);
void dMeter_magicTransScale(double param_1,double param_2,double param_3,int param_4);
void dMeter_magicColor(int param_1);
void dMeter_magicAlpha(int param_1);
void dMeter_gaugeAlpha(int param_1);
void dMeter_menuInit(int param_1);
void dMeter_menuMove(undefined4 param_1);
void dMeter_menuLRMove(int param_1);
void dMeter_menuPlusMove(int param_1);
void dMeter_magicLength(double param_1,int param_2);
void dMeter_windInit(void);
void dMeter_metronomeInit(int param_1);
void dMeter_windMove(void);
void dMeter_metronomeMove(int param_1);
void dMeter_rupyAlpha(sub_meter_class *param_1);
void dMeter_rupyInit(sub_meter_class *this);
void dMeter_rupyMove(sub_meter_class *this);
void dMeter_walletChange(sub_meter_class *this);
void dMeter_keyLight(double param_1,int **param_2,short *param_3);
void dMeter_keyRndLightFrame(short *param_1);
void dMeter_keyAlpha(int param_1);
void dMeter_keyInit(int param_1);
void dMeter_keyMove(int param_1);
void dMeter_compassRotate(double param_1,int **param_2);
void dMeter_compassGetOnProc(int param_1);
void dMeter_compassGetOffProc(int param_1);
void dMeter_compassDirOpen(int param_1);
void dMeter_compassWindOpen(int param_1);
void dMeter_compassWindClose(int param_1);
void dMeter_compassDirClose(int param_1);
void dMeter_compassAnimeMove(int param_1);
void dMeter_compassValueInit(int param_1);
void dMeter_compassAlpha(int param_1);
void dMeter_compassInit(int param_1);
void dMeter_compassMove(sub_meter_class *param_1);
void dMeter_clockShow(int param_1);
void dMeter_clockHide(int param_1);
void dMeter_clockInit(int param_1);
void dMeter_clockMove(int param_1);
void dMeter_clockStarLight(int *param_1,short *param_2);
void dMeter_starLightFrame(short *param_1);
void dMeter_clockMultiInit(void);
void dMeter_clockMultiMove(sub_meter_class *this);
void dMeter_mapInit(int param_1);
void dMeter_mapMove(int param_1);
void dMeter_arwInit(daArrow_c *param_1);
void dMeter_arwMove(daArrow_c *param_1);
void dMeter_moveItemInit(int param_1);
void dMeter_moveItemMove(int param_1);
void dMeter_moveItemDraw(void);
void dMeter_swimTransY(sub_meter_class *param_1,double param_2);
void dMeter_swimPaneShow(int param_1);
void dMeter_swimPaneHide(int param_1);
void dMeter_swimPaneTransY(double param_1,int param_2);
void dMeter_swimPaneAlpha(double param_1,int param_2);
void dMeter_swimInit(sub_meter_class *this);
void dMeter_swimMove(sub_meter_class *param_1);
void dMeter_swimDraw(sub_meter_class *this);
void dMeter_swimOpenProc(int param_1);
void dMeter_swimMoveProc(undefined4 param_1);
void dMeter_swimMainRotate(double param_1,int param_2);
void dMeter_swimMainBlink(int param_1);
void dMeter_swimMainDown(int param_1);
void dMeter_swimTekariScroll(int param_1);
void dMeter_swimLightMove(int param_1);
void dMeter_swimLightBirth(int param_1);
void dMeter_swimLightAnime(int param_1,short param_2);
void dMeter_placeNameMove(void);
void dMeter_arrowInit(int param_1);
void dMeter_arrowCheckStatus(int param_1);
void dMeter_arrowTransScale(double param_1,double param_2,int param_3,int param_4);
void dMeter_arrowAnime(int param_1);
void dMeter_arrowErase(fopMsgM_pane_class *param_1);
void dMeter_arrowMove(int param_1);
void dMeter_arrowDraw(int param_1);
void dMeter_screenDataSet(sub_meter_class *this);
void dMeter_screenDataTimeSet(sub_meter_class *param_1);
void dMeter_screenDataArrowSet(sub_meter_class *param_1);
undefined4 dMeter_Draw(sub_meter_class *this);
undefined4 dMeter_Execute(sub_meter_class *param_1);
undefined4 dMeter_IsDelete(void);
undefined4 dMeter_Delete(int param_1);
undefined4 dMeter_Create(sub_meter_class *this);
}

namespace d_meter {
void __sinit_d_meter_cpp(void);
void __arraydtor$4710(void);
}
