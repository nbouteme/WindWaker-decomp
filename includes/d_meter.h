#pragma once
#include <ctypes.h>

#include <dDlst_2Dm_c.h>
#include <mapCtrlDisp_c.h>
#include <f_pc_profile__Profile_Base.h>


namespace d_meter {
//[Data] Expected size is 0x000010
extern undefined * arrowTexImage;

//[Data] Expected size is 0x000010
extern pointer wepon$5133;

//[Data] Expected size is 0x000014
extern undefined * ht$5160;

//[Data] Expected size is 0x000028
extern undefined * number$6906;

//[Data] Expected size is 0x00000c
extern undefined4 scaleX$11729;

//[Data] Expected size is 0x00000c
extern undefined4 scaleY$11730;

//[Data] Expected size is 0x00000c
extern undefined4 scaleX$11753;

//[Data] Expected size is 0x00000c
extern undefined4 scaleY$11754;

//[Data] Expected size is 0x000014
extern undefined * l_dMeter_Method;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Base g_profile_METER;

}
//[Data] Expected size is 0x000010
extern pointer dMetronome_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_2DMETER2_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_2DMETER1_c;

//[Data] Expected size is 0x00000c
extern undefined1 dMeter_message_HIO_c;

//[Data] Expected size is 0x00000c
extern undefined1 dMeter_msg_HIO_c;

//[Data] Expected size is 0x00000c
extern undefined1 dMeter_menuHIO_c;

//[Data] Expected size is 0x00000c
extern undefined1 dMeter_HIO_c;

//[Data] Expected size is 0x00000c
extern undefined1 dMeter_map_HIO_c;


namespace d_meter {
//[Data] Expected size is 0x000004
extern undefined4 dMeter_windID;

//[Data] Expected size is 0x000006
extern undefined2 alphaNowFrame$8034;

//[Data] Expected size is 0x000006
extern undefined initPosX$11639;

//[Data] Expected size is 0x000006
extern undefined initPosY$11640;

//[BSS] Expected size is 0x000038
extern undefined item_parts;
//[BSS] Expected size is 0x000020
extern undefined g_meter_mapHIO;
//[BSS] Expected size is 0x000158
extern undefined g_meterHIO;
//[BSS] Expected size is 0x0000cc
extern undefined g_menuHIO;
//[BSS] Expected size is 0x00008c
extern undefined g_msgHIO;
//[BSS] Expected size is 0x000084
extern undefined g_messageHIO;
//[BSS] Expected size is 0x000084
extern struct dDlst_2Dm_c tekari;
//[BSS] Expected size is 0x00018c
extern undefined clock;
//[BSS] Expected size is 0x000002
extern undefined1 dMeter_Info;
//[BSS] Expected size is 0x000004
extern struct dMetronome_c * dMn_c;
//[BSS] Expected size is 0x000004
extern undefined4 sMainParts1;
//[BSS] Expected size is 0x000004
extern undefined4 sMainParts2;
//[BSS] Expected size is 0x000004
extern undefined4 sMainParts3;
//[BSS] Expected size is 0x000004
extern struct J2DScreen * sScrTimer1;
//[BSS] Expected size is 0x000004
extern struct J2DScreen * sScrTimer2;
//[BSS] Expected size is 0x000004
extern undefined4 sChoiceRoad;
//[BSS] Expected size is 0x000004
extern undefined4 moveItemPane;
//[BSS] Expected size is 0x000001
extern undefined1 mapAlpha;
//[BSS] Expected size is 0x000001
extern undefined1 menu_status;
//[BSS] Expected size is 0x000001
extern undefined1 menu_status_old;
//[BSS] Expected size is 0x000001
extern byte dMenu_pause;
//[BSS] Expected size is 0x000004
extern undefined4 dMenu_frame_timer;
//[BSS] Expected size is 0x000001
extern undefined1 dMenu_menuButton;
//[BSS] Expected size is 0x000001
extern undefined1 subWinFlag;
//[BSS] Expected size is 0x000001
extern undefined1 dMeter_auctionFlag;
//[BSS] Expected size is 0x000001
extern undefined1 dMeter_itemMoveFlag;
//[BSS] Expected size is 0x000001
extern undefined1 dMeter_btn_chk;
//[BSS] Expected size is 0x000001
extern undefined1 dMeter_itemNum;
//[BSS] Expected size is 0x000002
extern undefined2 dMeter_itemTimer;
//[BSS] Expected size is 0x000004
extern float texRateX;
//[BSS] Expected size is 0x000004
extern float texRateY;
//[BSS] Expected size is 0x000004
extern float texScaleX;
//[BSS] Expected size is 0x000004
extern float texScaleY;
//[BSS] Expected size is 0x000001
extern undefined1 dMenu_menuFlag;
//[BSS] Expected size is 0x000008
extern undefined dMenu_baitNum;
//[BSS] Expected size is 0x000001
extern undefined1 dMeter_place_name;
//[BSS] Expected size is 0x000001
extern undefined1 dMeter_itemMode;
//[BSS] Expected size is 0x000001
extern undefined1 dMeter_collectMode;
//[BSS] Expected size is 0x000001
extern undefined1 dMeter_windStatus;
//[BSS] Expected size is 0x000001
extern undefined1 rupy_soundSetFlag;
//[BSS] Expected size is 0x000001
extern undefined1 rupy_soundOnFlag;
//[BSS] Expected size is 0x000006
extern struct mapCtrlDisp_c dMeter_mMapCtrlDisp;
//[BSS] Expected size is 0x000004
extern undefined4 meter1;
//[BSS] Expected size is 0x000004
extern undefined4 meter2;
//[BSS] Expected size is 0x000001
extern bool soundOnFlag$5563;
//[BSS] Expected size is 0x000001
extern undefined1 init$5564;
//[BSS] Expected size is 0x000001
extern undefined1 point$5650;
//[BSS] Expected size is 0x000001
extern undefined1 init$5651;
//[BSS] Expected size is 0x000001
extern undefined1 flag$5797;
//[BSS] Expected size is 0x000001
extern undefined1 init$5798;
//[BSS] Expected size is 0x000002
extern undefined2 moveNowFrame$6064;
//[BSS] Expected size is 0x000001
extern undefined1 init$6065;
//[BSS] Expected size is 0x000002
extern undefined2 moveFlag$6067;
//[BSS] Expected size is 0x000001
extern undefined1 init$6068;
//[BSS] Expected size is 0x000002
extern undefined2 moveStatus$6070;
//[BSS] Expected size is 0x000001
extern undefined1 init$6071;
//[BSS] Expected size is 0x000004
extern float nowX$6073;
//[BSS] Expected size is 0x000001
extern undefined1 init$6074;
//[BSS] Expected size is 0x000004
extern float nowY$6076;
//[BSS] Expected size is 0x000001
extern undefined1 init$6077;
//[BSS] Expected size is 0x000004
extern float expX$6079;
//[BSS] Expected size is 0x000001
extern undefined1 init$6080;
//[BSS] Expected size is 0x000004
extern float expY$6082;
//[BSS] Expected size is 0x000001
extern undefined1 init$6083;
//[BSS] Expected size is 0x000002
extern undefined2 alphaNowFrame$6279;
//[BSS] Expected size is 0x000001
extern undefined1 init$6280;
//[BSS] Expected size is 0x000002
extern undefined2 moveNowFrame$6602;
//[BSS] Expected size is 0x000001
extern undefined1 init$6603;
//[BSS] Expected size is 0x000002
extern undefined2 moveFlag$6605;
//[BSS] Expected size is 0x000001
extern undefined1 init$6606;
//[BSS] Expected size is 0x000002
extern undefined2 moveStatus$6608;
//[BSS] Expected size is 0x000001
extern undefined1 init$6609;
//[BSS] Expected size is 0x000004
extern float nowX$6611;
//[BSS] Expected size is 0x000001
extern undefined1 init$6612;
//[BSS] Expected size is 0x000004
extern float nowY$6614;
//[BSS] Expected size is 0x000001
extern undefined1 init$6615;
//[BSS] Expected size is 0x000004
extern float expX$6617;
//[BSS] Expected size is 0x000001
extern undefined1 init$6618;
//[BSS] Expected size is 0x000004
extern float expY$6620;
//[BSS] Expected size is 0x000001
extern undefined1 init$6621;
//[BSS] Expected size is 0x000002
extern undefined2 alphaNowFrame$6814;
//[BSS] Expected size is 0x000001
extern undefined1 init$6815;
//[BSS] Expected size is 0x000001
extern undefined1 arrowMax$7632;
//[BSS] Expected size is 0x000001
extern undefined1 init$7633;
//[BSS] Expected size is 0x000001
extern undefined1 bombMax$7635;
//[BSS] Expected size is 0x000001
extern undefined1 init$7636;
//[BSS] Expected size is 0x000002
extern undefined2 moveNowFrame$8368;
//[BSS] Expected size is 0x000001
extern undefined1 init$8369;
//[BSS] Expected size is 0x000002
extern undefined2 moveFlag$8371;
//[BSS] Expected size is 0x000001
extern undefined1 init$8372;
//[BSS] Expected size is 0x000002
extern undefined2 moveStatus$8374;
//[BSS] Expected size is 0x000001
extern undefined1 init$8375;
//[BSS] Expected size is 0x000004
extern float nowX$8377;
//[BSS] Expected size is 0x000001
extern undefined1 init$8378;
//[BSS] Expected size is 0x000004
extern float nowY$8380;
//[BSS] Expected size is 0x000001
extern undefined1 init$8381;
//[BSS] Expected size is 0x000002
extern undefined2 alphaNowFrame$8563;
//[BSS] Expected size is 0x000001
extern undefined1 init$8564;
//[BSS] Expected size is 0x000002
extern undefined2 moveNowFrame$8633;
//[BSS] Expected size is 0x000001
extern undefined1 init$8634;
//[BSS] Expected size is 0x000002
extern undefined2 moveFlag$8636;
//[BSS] Expected size is 0x000001
extern undefined1 init$8637;
//[BSS] Expected size is 0x000002
extern undefined2 moveStatus$8639;
//[BSS] Expected size is 0x000001
extern undefined1 init$8640;
//[BSS] Expected size is 0x000004
extern float nowX$8642;
//[BSS] Expected size is 0x000001
extern undefined1 init$8643;
//[BSS] Expected size is 0x000004
extern float nowY$8645;
//[BSS] Expected size is 0x000001
extern undefined1 init$8646;
//[BSS] Expected size is 0x000001
extern undefined1 bossEyeFlag$9082;
//[BSS] Expected size is 0x000001
extern undefined1 init$9083;
//[BSS] Expected size is 0x000001
extern undefined1 soundOnFlag$9201;
//[BSS] Expected size is 0x000001
extern undefined1 init$9202;
//[BSS] Expected size is 0x000001
extern undefined1 frame$9916;
//[BSS] Expected size is 0x000001
extern undefined1 init$9917;
//[BSS] Expected size is 0x000002
extern undefined2 moveFlag$9962;
//[BSS] Expected size is 0x000001
extern undefined1 init$9963;
//[BSS] Expected size is 0x000002
extern undefined2 moveStatus$9965;
//[BSS] Expected size is 0x000001
extern undefined1 init$9966;
//[BSS] Expected size is 0x000002
extern undefined2 mapTimer$11802;
//[BSS] Expected size is 0x000001
extern undefined1 init$11803;
//[BSS] Expected size is 0x000001
extern undefined1 stageFlag$11805;
//[BSS] Expected size is 0x000001
extern undefined1 init$11806;
//[BSS] Expected size is 0x000004
extern undefined4 stayNo$11808;
//[BSS] Expected size is 0x000001
extern undefined1 init$11809;
//[BSS] Expected size is 0x000001
extern undefined1 arrowType$11959;
//[BSS] Expected size is 0x000001
extern undefined1 init$11960;
//[BSS] Expected size is 0x000001
extern undefined1 oldType$11962;
//[BSS] Expected size is 0x000001
extern undefined1 init$11963;
//[BSS] Expected size is 0x000004
extern float dist_buf$12565;
//[BSS] Expected size is 0x000001
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
