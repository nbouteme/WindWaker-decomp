#include <d_meter.h>
#include <f_op_msg_mng.h>
#include <d_meter.h>
#include <d_camera.h>
#include <d_save.h>
#include <d_event_manager.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <d_com_inf_game.h>
#include <J2DGraph/J2DScreen.h>
#include <J2DGraph/J2DPicture.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <JKernel/JKRArchivePub.h>
#include <os/OSCache.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <d_particle.h>
#include <SComponent/c_math.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_attention.h>
#include <m_Do_lib.h>
#include <d_a_npc_cb1_static.h>
#include <d_com_static.h>
#include <f_op_overlap_mng.h>
#include <d_a_player_main.h>
#include <d_map.h>
#include <d_kankyo_wether.h>
#include <d_metronome.h>
#include <JKernel/JKRHeap.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <d_kankyo.h>
#include <d_drawlist.h>
#include <MSL_C.PPCEABI.bare.H/s_sin.h>
#include <J2DGraph/J2DPane.h>
#include <m_Do_ext.h>
#include <m_Do_hostIO.h>
#include <d_timer.h>
#include <SComponent/c_lib.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <dMeter_message_HIO_c.h>
#include <dMeter_info_c.h>
#include <dDlst_2DMETER1_c.h>
#include <dMeter_HIO_c.h>
#include <dMeter_msg_HIO_c.h>
#include <dDlst_2DMETER2_c.h>
#include <dDlst_2Dm_c.h>
#include <mapCtrlDisp_c.h>
#include <dMeter_menuHIO_c.h>
#include <dMetronome_c.h>
#include <dMeter_map_HIO_c.h>


namespace d_meter {
undefined item_parts;
undefined g_meter_mapHIO;
undefined g_meterHIO;
undefined g_menuHIO;
undefined g_msgHIO;
undefined g_messageHIO;
struct dDlst_2Dm_c tekari;
undefined clock;
undefined1 dMeter_Info;
struct dMetronome_c * dMn_c;
undefined4 sMainParts1;
undefined4 sMainParts2;
undefined4 sMainParts3;
struct J2DScreen * sScrTimer1;
struct J2DScreen * sScrTimer2;
undefined4 sChoiceRoad;
undefined4 moveItemPane;
undefined1 mapAlpha;
undefined1 menu_status;
undefined1 menu_status_old;
byte dMenu_pause;
undefined4 dMenu_frame_timer;
undefined1 dMenu_menuButton;
undefined1 subWinFlag;
undefined1 dMeter_auctionFlag;
undefined1 dMeter_itemMoveFlag;
undefined1 dMeter_btn_chk;
undefined1 dMeter_itemNum;
undefined2 dMeter_itemTimer;
float texRateX;
float texRateY;
float texScaleX;
float texScaleY;
undefined1 dMenu_menuFlag;
undefined dMenu_baitNum;
undefined1 dMeter_place_name;
undefined1 dMeter_itemMode;
undefined1 dMeter_collectMode;
undefined1 dMeter_windStatus;
undefined1 rupy_soundSetFlag;
undefined1 rupy_soundOnFlag;
struct mapCtrlDisp_c dMeter_mMapCtrlDisp;
undefined4 meter1;
undefined4 meter2;
bool soundOnFlag$5563;
undefined1 init$5564;
undefined1 point$5650;
undefined1 init$5651;
undefined1 flag$5797;
undefined1 init$5798;
undefined2 moveNowFrame$6064;
undefined1 init$6065;
undefined2 moveFlag$6067;
undefined1 init$6068;
undefined2 moveStatus$6070;
undefined1 init$6071;
float nowX$6073;
undefined1 init$6074;
float nowY$6076;
undefined1 init$6077;
float expX$6079;
undefined1 init$6080;
float expY$6082;
undefined1 init$6083;
undefined2 alphaNowFrame$6279;
undefined1 init$6280;
undefined2 moveNowFrame$6602;
undefined1 init$6603;
undefined2 moveFlag$6605;
undefined1 init$6606;
undefined2 moveStatus$6608;
undefined1 init$6609;
float nowX$6611;
undefined1 init$6612;
float nowY$6614;
undefined1 init$6615;
float expX$6617;
undefined1 init$6618;
float expY$6620;
undefined1 init$6621;
undefined2 alphaNowFrame$6814;
undefined1 init$6815;
undefined1 arrowMax$7632;
undefined1 init$7633;
undefined1 bombMax$7635;
undefined1 init$7636;
undefined2 moveNowFrame$8368;
undefined1 init$8369;
undefined2 moveFlag$8371;
undefined1 init$8372;
undefined2 moveStatus$8374;
undefined1 init$8375;
float nowX$8377;
undefined1 init$8378;
float nowY$8380;
undefined1 init$8381;
undefined2 alphaNowFrame$8563;
undefined1 init$8564;
undefined2 moveNowFrame$8633;
undefined1 init$8634;
undefined2 moveFlag$8636;
undefined1 init$8637;
undefined2 moveStatus$8639;
undefined1 init$8640;
float nowX$8642;
undefined1 init$8643;
float nowY$8645;
undefined1 init$8646;
undefined1 bossEyeFlag$9082;
undefined1 init$9083;
undefined1 soundOnFlag$9201;
undefined1 init$9202;
undefined1 frame$9916;
undefined1 init$9917;
undefined2 moveFlag$9962;
undefined1 init$9963;
undefined2 moveStatus$9965;
undefined1 init$9966;
undefined2 mapTimer$11802;
undefined1 init$11803;
undefined1 stageFlag$11805;
undefined1 init$11806;
undefined4 stayNo$11808;
undefined1 init$11809;
undefined1 arrowType$11959;
undefined1 init$11960;
undefined1 oldType$11962;
undefined1 init$11963;
float dist_buf$12565;
undefined1 init$12566;
}

/* __thiscall dMeter_HIO_c::dMeter_HIO_c(void) */

void __thiscall dMeter_HIO_c::dMeter_HIO_c(dMeter_HIO_c *this)

{
  float fVar1;
  
  *(undefined1 **)this = &__vt;
  *(undefined2 *)(this + 6) = 10;
  this[0x62] = (dMeter_HIO_c)0x0;
  this[99] = (dMeter_HIO_c)0x0;
  fVar1 = d_meter::1_0;
  *(float *)(this + 0xc) = d_meter::1_0;
  *(float *)(this + 0x10) = d_meter::_4637;
  *(float *)(this + 0x14) = d_meter::0_0;
  *(float *)(this + 0x18) = d_meter::_4638;
  *(float *)(this + 0x1c) = fVar1;
  *(undefined2 *)(this + 0x36) = 0x16;
  *(float *)(this + 0x3c) = d_meter::_4639;
  *(undefined2 *)(this + 0x38) = 0;
  *(undefined2 *)(this + 0x2e) = 0;
  *(undefined2 *)(this + 0x30) = 0;
  *(undefined2 *)(this + 0x32) = 0;
  *(undefined2 *)(this + 0x34) = 0;
  this[0x2c] = (dMeter_HIO_c)0xff;
  *(float *)(this + 0x20) = d_meter::_4640;
  *(float *)(this + 0x24) = d_meter::_4641;
  this[0x2d] = (dMeter_HIO_c)0x8c;
  *(undefined2 *)(this + 0x40) = 0x5a;
  *(undefined2 *)(this + 0x42) = 100;
  *(undefined2 *)(this + 0x44) = 100;
  *(undefined2 *)(this + 0x46) = 0x5a;
  *(undefined2 *)(this + 0x50) = 7;
  *(undefined2 *)(this + 0x52) = 0xfff4;
  *(float *)(this + 0x48) = d_meter::_4642;
  fVar1 = d_meter::_4643;
  *(float *)(this + 0x4c) = d_meter::_4643;
  *(undefined2 *)(this + 0x54) = 0;
  *(undefined2 *)(this + 0x56) = 0xffa8;
  *(float *)(this + 0x58) = d_meter::_4644;
  *(float *)(this + 0x5c) = fVar1;
  this[0x60] = (dMeter_HIO_c)0x96;
  this[0x61] = (dMeter_HIO_c)0x64;
  *(undefined2 *)(this + 100) = 0;
  *(undefined2 *)(this + 0x66) = 0;
  *(undefined2 *)(this + 0x68) = 0;
  *(undefined2 *)(this + 0x6a) = 0;
  *(undefined2 *)(this + 0x88) = 0xf;
  *(undefined2 *)(this + 0x8a) = 5;
  *(undefined2 *)(this + 0x8c) = 5;
  *(undefined2 *)(this + 0x8e) = 5;
  *(undefined2 *)(this + 0x90) = 0x14;
  *(undefined2 *)(this + 0x92) = 0xc;
  *(undefined2 *)(this + 0x94) = 3;
  *(undefined2 *)(this + 0x96) = 3;
  *(undefined2 *)(this + 0x98) = 3;
  *(undefined2 *)(this + 0x9a) = 0;
  this[0x120] = (dMeter_HIO_c)0x8c;
  this[0x121] = (dMeter_HIO_c)0xc8;
  this[0x122] = (dMeter_HIO_c)0x96;
  *(undefined2 *)(this + 0x126) = 10;
  *(undefined2 *)(this + 0x128) = 6;
  *(undefined2 *)(this + 0x12a) = 3;
  *(undefined2 *)(this + 300) = 3;
  *(undefined2 *)(this + 0x12e) = 2;
  *(undefined2 *)(this + 0x130) = 0x14;
  *(undefined2 *)(this + 0x132) = 0x27;
  *(undefined2 *)(this + 0x7e) = 0x14;
  *(undefined2 *)(this + 0x136) = 4;
  *(undefined2 *)(this + 0x138) = 10;
  *(undefined2 *)(this + 0x13a) = 0;
  *(undefined2 *)(this + 0x13c) = 10;
  this[0x142] = (dMeter_HIO_c)0xb4;
  this[0x143] = (dMeter_HIO_c)0x0;
  this[0x144] = (dMeter_HIO_c)0x0;
  this[0x145] = (dMeter_HIO_c)0xff;
  this[0x146] = (dMeter_HIO_c)0x0;
  this[0x147] = (dMeter_HIO_c)0x0;
  this[0x148] = (dMeter_HIO_c)0x0;
  this[0x149] = (dMeter_HIO_c)0x0;
  this[0x123] = (dMeter_HIO_c)0x1;
  *(undefined2 *)(this + 0x134) = 3;
  *(undefined2 *)(this + 0x13e) = 0;
  this[0x14a] = (dMeter_HIO_c)0xff;
  this[0x14b] = (dMeter_HIO_c)0x32;
  this[0x14c] = (dMeter_HIO_c)0x32;
  *(undefined2 *)(this + 0x14e) = 10;
  *(undefined2 *)(this + 0x150) = 0x14;
  *(undefined2 *)(this + 0x152) = 4;
  *(undefined2 *)(this + 0x154) = 0x32;
  *(float *)(this + 0x28) = d_meter::_4645;
  *(undefined2 *)(this + 0x124) = 5;
  *(undefined2 *)(this + 0x140) = 0;
  *(undefined2 *)(this + 0xa0) = 0;
  *(undefined2 *)(this + 0xa8) = 0;
  *(undefined2 *)(this + 0xa2) = 0x3c;
  *(undefined2 *)(this + 0xaa) = 0xffc4;
  *(undefined2 *)(this + 0xa4) = 0;
  *(undefined2 *)(this + 0xac) = 0;
  *(undefined2 *)(this + 0xa6) = 0;
  *(undefined2 *)(this + 0xae) = 0;
  *(undefined2 *)(this + 0xb0) = 0x19;
  *(undefined2 *)(this + 0xb8) = 0xffe2;
  *(undefined2 *)(this + 0xb2) = 0x23;
  *(undefined2 *)(this + 0xba) = 0xffea;
  *(undefined2 *)(this + 0xb4) = 0xffdf;
  *(undefined2 *)(this + 0xbc) = 0xfffb;
  *(undefined2 *)(this + 0xb6) = 0xfffa;
  *(undefined2 *)(this + 0xbe) = 0;
  *(undefined2 *)(this + 0xc0) = 0;
  *(undefined2 *)(this + 200) = 0xffec;
  *(undefined2 *)(this + 0xc2) = 0;
  *(undefined2 *)(this + 0xca) = 0xffec;
  *(undefined2 *)(this + 0xc4) = 0;
  *(undefined2 *)(this + 0xcc) = 0xffec;
  *(undefined2 *)(this + 0xc6) = 0;
  *(undefined2 *)(this + 0xce) = 0;
  *(undefined2 *)(this + 0xd0) = 0x28;
  *(undefined2 *)(this + 0xd8) = 0xffc4;
  *(undefined2 *)(this + 0xd2) = 0x28;
  *(undefined2 *)(this + 0xda) = 0xffc4;
  *(undefined2 *)(this + 0xd4) = 0;
  *(undefined2 *)(this + 0xdc) = 0;
  *(undefined2 *)(this + 0xd6) = 0;
  *(undefined2 *)(this + 0xde) = 0;
  *(undefined2 *)(this + 0xe0) = 0x19;
  *(undefined2 *)(this + 0xe8) = 0xffe2;
  *(undefined2 *)(this + 0xe2) = 0x23;
  *(undefined2 *)(this + 0xea) = 0xffea;
  *(undefined2 *)(this + 0xe4) = 0;
  *(undefined2 *)(this + 0xec) = 0xffc4;
  *(undefined2 *)(this + 0xe6) = 0xfffa;
  *(undefined2 *)(this + 0xee) = 0;
  *(undefined2 *)(this + 0xf0) = 0;
  *(undefined2 *)(this + 0xf8) = 0;
  *(undefined2 *)(this + 0xf2) = 0;
  *(undefined2 *)(this + 0xfa) = 0;
  *(undefined2 *)(this + 0xf4) = 0;
  *(undefined2 *)(this + 0xfc) = 0;
  *(undefined2 *)(this + 0xf6) = 0;
  *(undefined2 *)(this + 0xfe) = 0;
  *(undefined2 *)(this + 0x100) = 0;
  *(undefined2 *)(this + 0x108) = 0xffc4;
  *(undefined2 *)(this + 0x102) = 0;
  *(undefined2 *)(this + 0x10a) = 0xffc4;
  *(undefined2 *)(this + 0x104) = 0x32;
  *(undefined2 *)(this + 0x10c) = 0xffb8;
  *(undefined2 *)(this + 0x106) = 0x32;
  *(undefined2 *)(this + 0x10e) = 0xffaf;
  *(undefined2 *)(this + 0x110) = 0;
  *(undefined2 *)(this + 0x118) = 0xffeb;
  *(undefined2 *)(this + 0x112) = 0x11;
  *(undefined2 *)(this + 0x11a) = 0xfff4;
  *(undefined2 *)(this + 0x114) = 0xffe2;
  *(undefined2 *)(this + 0x11c) = 0xfff5;
  *(undefined2 *)(this + 0x116) = 0xff9e;
  *(undefined2 *)(this + 0x11e) = 7;
  *(undefined2 *)(this + 0x9c) = 0;
  *(undefined2 *)(this + 0x9e) = 0;
  *(undefined2 *)(this + 0x6c) = 0xffea;
  *(undefined2 *)(this + 0x72) = 0xffd5;
  *(undefined2 *)(this + 0x78) = 0x8c;
  *(undefined2 *)(this + 0x6e) = 0xffdd;
  *(undefined2 *)(this + 0x74) = 0xfffd;
  *(undefined2 *)(this + 0x7a) = 0x82;
  *(undefined2 *)(this + 0x70) = 0xfffa;
  *(undefined2 *)(this + 0x76) = 0xfff3;
  *(undefined2 *)(this + 0x7c) = 0x8c;
  return;
}


/* __thiscall dMeter_menuHIO_c::dMeter_menuHIO_c(void) */

void __thiscall dMeter_menuHIO_c::dMeter_menuHIO_c(dMeter_menuHIO_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  *(undefined1 **)this = &__vt;
  fVar3 = d_meter::_4637;
  *(float *)(this + 8) = d_meter::_4637;
  this[0xbe] = (dMeter_menuHIO_c)0x0;
  *(float *)(this + 0xc) = d_meter::_4654;
  *(float *)(this + 0x10) = d_meter::_4655;
  *(undefined2 *)(this + 0x7e) = 3;
  *(undefined2 *)(this + 0x80) = 3;
  this[0xc0] = (dMeter_menuHIO_c)0x1;
  *(undefined2 *)(this + 0x7c) = 0;
  this[0xc1] = (dMeter_menuHIO_c)0x0;
  this[0xc2] = (dMeter_menuHIO_c)0xa;
  this[0xc3] = (dMeter_menuHIO_c)0x4;
  this[0xc4] = (dMeter_menuHIO_c)0x0;
  fVar1 = d_meter::0_0;
  *(float *)(this + 0x3c) = d_meter::0_0;
  *(float *)(this + 0x40) = d_meter::_4656;
  *(float *)(this + 0x44) = d_meter::_4657;
  this[0x70] = (dMeter_menuHIO_c)0xff;
  this[0x71] = (dMeter_menuHIO_c)0xff;
  this[0x72] = (dMeter_menuHIO_c)0xff;
  this[0x73] = (dMeter_menuHIO_c)0xff;
  this[0x6c] = (dMeter_menuHIO_c)0x32;
  this[0x6d] = (dMeter_menuHIO_c)0x32;
  this[0x6e] = (dMeter_menuHIO_c)0x32;
  this[0x6f] = (dMeter_menuHIO_c)0xff;
  *(float *)(this + 0x48) = fVar1;
  *(float *)(this + 0x4c) = fVar1;
  *(float *)(this + 0x50) = d_meter::_4658;
  this[0x74] = (dMeter_menuHIO_c)0xff;
  this[0x75] = (dMeter_menuHIO_c)0xff;
  this[0x76] = (dMeter_menuHIO_c)0xff;
  this[0x77] = (dMeter_menuHIO_c)0xff;
  *(float *)(this + 0x54) = d_meter::_4659;
  *(float *)(this + 0x58) = d_meter::_4660;
  *(float *)(this + 0x5c) = d_meter::_4661;
  fVar1 = d_meter::1_0;
  *(float *)(this + 0x60) = d_meter::1_0;
  fVar2 = d_meter::_4617;
  *(float *)(this + 100) = d_meter::_4617;
  *(float *)(this + 0x68) = fVar2;
  this[0x78] = (dMeter_menuHIO_c)0xc8;
  this[0x79] = (dMeter_menuHIO_c)0xc8;
  this[0x7a] = (dMeter_menuHIO_c)0xc8;
  this[0x7b] = (dMeter_menuHIO_c)0xff;
  *(float *)(this + 0x18) = d_meter::_4662;
  this[0xbf] = (dMeter_menuHIO_c)0x0;
  *(float *)(this + 0x1c) = d_meter::_4663;
  this[0xc5] = (dMeter_menuHIO_c)0x2;
  *(undefined2 *)(this + 0x82) = 8;
  *(undefined2 *)(this + 0x84) = 5;
  this[0xc6] = (dMeter_menuHIO_c)0x0;
  this[199] = (dMeter_menuHIO_c)0x1;
  *(float *)(this + 0x20) = d_meter::_4664;
  this[200] = (dMeter_menuHIO_c)0x9;
  this[0xc9] = (dMeter_menuHIO_c)0x0;
  this[0xca] = (dMeter_menuHIO_c)0x0;
  *(undefined2 *)(this + 0x28) = 0xffec;
  *(undefined2 *)(this + 0x36) = 7;
  *(undefined2 *)(this + 0x32) = 8;
  *(undefined2 *)(this + 0x34) = 5;
  *(undefined2 *)(this + 0x38) = 0x1a;
  *(undefined2 *)(this + 0x3a) = 0xfffd;
  *(undefined2 *)(this + 0x88) = 3;
  *(undefined2 *)(this + 0x8a) = 0;
  *(float *)(this + 0x14) = d_meter::_4665;
  *(undefined2 *)(this + 0x8c) = 0xff38;
  *(undefined2 *)(this + 0xb4) = 6;
  *(undefined2 *)(this + 0x90) = 3;
  *(undefined2 *)(this + 0x92) = 7;
  *(float *)(this + 0x94) = fVar1;
  this[0x98] = (dMeter_menuHIO_c)0xff;
  this[0x99] = (dMeter_menuHIO_c)0xff;
  *(undefined2 *)(this + 0x9a) = 0;
  *(undefined2 *)(this + 0x9a) = 0;
  *(float *)(this + 0xa0) = fVar1;
  *(undefined2 *)(this + 0xb6) = 0x46;
  *(undefined2 *)(this + 0xba) = 5;
  *(undefined2 *)(this + 0xbc) = 3;
  *(float *)(this + 0x24) = fVar3;
  *(undefined2 *)(this + 0xa4) = 6;
  *(undefined2 *)(this + 0xa6) = 2;
  *(undefined2 *)(this + 0xa8) = 2;
  *(undefined2 *)(this + 0xaa) = 2;
  *(undefined2 *)(this + 0xac) = 2;
  *(undefined2 *)(this + 0xae) = 0x1e;
  *(undefined2 *)(this + 0xb0) = 0x3c;
  *(undefined2 *)(this + 0xb2) = 0;
  *(undefined2 *)(this + 0x8e) = 0x15e;
  this[0xb8] = (dMeter_menuHIO_c)0x96;
  *(undefined2 *)(this + 0x2a) = 0x10;
  *(undefined2 *)(this + 0x2c) = 0x18;
  *(undefined2 *)(this + 0x2e) = 0x17;
  *(undefined2 *)(this + 0x30) = 0;
  return;
}


/* __thiscall dMeter_msg_HIO_c::dMeter_msg_HIO_c(void) */

void __thiscall dMeter_msg_HIO_c::dMeter_msg_HIO_c(dMeter_msg_HIO_c *this)

{
  *(undefined1 **)this = &__vt;
  this[5] = (dMeter_msg_HIO_c)0x1e;
  this[6] = (dMeter_msg_HIO_c)0x1e;
  this[7] = (dMeter_msg_HIO_c)0x1e;
  this[8] = (dMeter_msg_HIO_c)0xd7;
  this[9] = (dMeter_msg_HIO_c)0x1e;
  this[10] = (dMeter_msg_HIO_c)0x1e;
  this[0xb] = (dMeter_msg_HIO_c)0x4b;
  this[0xc] = (dMeter_msg_HIO_c)0x0;
  *(undefined2 *)(this + 0x5a) = 0;
  *(undefined2 *)(this + 0x5c) = 0;
  *(undefined2 *)(this + 0x5e) = 0x1e;
  *(undefined2 *)(this + 0x66) = 0;
  *(undefined2 *)(this + 0x68) = 0xf;
  this[0xd] = (dMeter_msg_HIO_c)0x1e;
  this[0xe] = (dMeter_msg_HIO_c)0x1e;
  this[0xf] = (dMeter_msg_HIO_c)0x1e;
  this[0x10] = (dMeter_msg_HIO_c)0xdc;
  this[0x11] = (dMeter_msg_HIO_c)0x1e;
  this[0x12] = (dMeter_msg_HIO_c)0x1e;
  this[0x13] = (dMeter_msg_HIO_c)0xb4;
  this[0x14] = (dMeter_msg_HIO_c)0x0;
  this[0x15] = (dMeter_msg_HIO_c)0x0;
  this[0x16] = (dMeter_msg_HIO_c)0xff;
  this[0x17] = (dMeter_msg_HIO_c)0x0;
  this[0x18] = (dMeter_msg_HIO_c)0xff;
  this[0x19] = (dMeter_msg_HIO_c)0x78;
  this[0x1a] = (dMeter_msg_HIO_c)0x78;
  this[0x1b] = (dMeter_msg_HIO_c)0xff;
  this[0x1c] = (dMeter_msg_HIO_c)0xff;
  this[0x1d] = (dMeter_msg_HIO_c)0xff;
  this[0x1e] = (dMeter_msg_HIO_c)0xff;
  this[0x1f] = (dMeter_msg_HIO_c)0x3c;
  this[0x20] = (dMeter_msg_HIO_c)0xff;
  this[0x21] = (dMeter_msg_HIO_c)0x0;
  this[0x22] = (dMeter_msg_HIO_c)0xff;
  this[0x23] = (dMeter_msg_HIO_c)0xff;
  this[0x24] = (dMeter_msg_HIO_c)0xff;
  this[0x25] = (dMeter_msg_HIO_c)0xff;
  this[0x26] = (dMeter_msg_HIO_c)0x0;
  this[0x27] = (dMeter_msg_HIO_c)0xff;
  this[0x28] = (dMeter_msg_HIO_c)0xff;
  *(undefined2 *)(this + 0x6a) = 0;
  this[0x72] = (dMeter_msg_HIO_c)0x0;
  *(undefined2 *)(this + 0x6c) = 0;
  this[0x83] = (dMeter_msg_HIO_c)0x0;
  this[0x84] = (dMeter_msg_HIO_c)0x1;
  this[0x85] = (dMeter_msg_HIO_c)0x0;
  this[0x86] = (dMeter_msg_HIO_c)0x0;
  this[0x87] = (dMeter_msg_HIO_c)0xa;
  this[0x88] = (dMeter_msg_HIO_c)0x0;
  this[0x89] = (dMeter_msg_HIO_c)0x0;
  this[0x8a] = (dMeter_msg_HIO_c)0x0;
  this[100] = (dMeter_msg_HIO_c)0x0;
  this[0x82] = (dMeter_msg_HIO_c)0x2;
  this[0x58] = (dMeter_msg_HIO_c)0x1d;
  *(undefined2 *)(this + 0x70) = 0x17;
  *(undefined2 *)(this + 0x62) = 0;
  *(undefined2 *)(this + 0x60) = 0xd;
  *(undefined2 *)(this + 0x6e) = 0xf0;
  *(float *)(this + 0x50) = d_meter::_4672;
  *(float *)(this + 0x54) = d_meter::1_1;
  *(undefined2 *)(this + 0x4a) = 2;
  *(undefined2 *)(this + 0x4c) = 4;
  this[0x7e] = (dMeter_msg_HIO_c)0xa;
  this[0x80] = (dMeter_msg_HIO_c)0xb4;
  *(undefined2 *)(this + 0x74) = 0x80;
  this[0x7f] = (dMeter_msg_HIO_c)0xaa;
  this[0x81] = (dMeter_msg_HIO_c)0x46;
  *(undefined2 *)(this + 0x76) = 10;
  *(undefined2 *)(this + 0x78) = 0;
  *(undefined2 *)(this + 0x7a) = 0;
  *(undefined2 *)(this + 0x7c) = 0x46;
  *(undefined2 *)(this + 0x44) = 5;
  *(undefined2 *)(this + 0x46) = 3;
  *(undefined2 *)(this + 0x48) = 4;
  *(float *)(this + 0x38) = d_meter::_4673;
  *(float *)(this + 0x3c) = d_meter::_4674;
  *(float *)(this + 0x40) = d_meter::_4664;
  this[0x29] = (dMeter_msg_HIO_c)0xff;
  this[0x2a] = (dMeter_msg_HIO_c)0x50;
  this[0x2b] = (dMeter_msg_HIO_c)0x50;
  this[0x2c] = (dMeter_msg_HIO_c)0x96;
  this[0x2d] = (dMeter_msg_HIO_c)0xff;
  this[0x2e] = (dMeter_msg_HIO_c)0x96;
  this[0x2f] = (dMeter_msg_HIO_c)0x96;
  this[0x30] = (dMeter_msg_HIO_c)0xff;
  return;
}


/* __thiscall dMeter_message_HIO_c::dMeter_message_HIO_c(void) */

void __thiscall dMeter_message_HIO_c::dMeter_message_HIO_c(dMeter_message_HIO_c *this)

{
  *(undefined1 **)this = &__vt;
  this[5] = (dMeter_message_HIO_c)0x0;
  this[6] = (dMeter_message_HIO_c)0x0;
  this[7] = (dMeter_message_HIO_c)0x0;
  this[8] = (dMeter_message_HIO_c)0xff;
  this[9] = (dMeter_message_HIO_c)0xff;
  this[10] = (dMeter_message_HIO_c)0xff;
  this[0xb] = (dMeter_message_HIO_c)0xff;
  this[0xc] = (dMeter_message_HIO_c)0xff;
  this[0xd] = (dMeter_message_HIO_c)0xff;
  this[0xe] = (dMeter_message_HIO_c)0xff;
  this[0xf] = (dMeter_message_HIO_c)0xff;
  this[0x10] = (dMeter_message_HIO_c)0x0;
  this[0x11] = (dMeter_message_HIO_c)0xff;
  this[0x12] = (dMeter_message_HIO_c)0xff;
  this[0x13] = (dMeter_message_HIO_c)0xff;
  this[0x14] = (dMeter_message_HIO_c)0xff;
  this[0x15] = (dMeter_message_HIO_c)0xff;
  this[0x16] = (dMeter_message_HIO_c)0xff;
  this[0x17] = (dMeter_message_HIO_c)0xff;
  this[0x18] = (dMeter_message_HIO_c)0xff;
  this[0x19] = (dMeter_message_HIO_c)0xff;
  this[0x1a] = (dMeter_message_HIO_c)0xff;
  this[0x1b] = (dMeter_message_HIO_c)0xff;
  this[0x1c] = (dMeter_message_HIO_c)0x0;
  this[0x1d] = (dMeter_message_HIO_c)0x0;
  this[0x1e] = (dMeter_message_HIO_c)0x0;
  this[0x1f] = (dMeter_message_HIO_c)0x0;
  this[0x20] = (dMeter_message_HIO_c)0xff;
  this[0x21] = (dMeter_message_HIO_c)0xff;
  this[0x22] = (dMeter_message_HIO_c)0xff;
  this[0x23] = (dMeter_message_HIO_c)0xff;
  this[0x24] = (dMeter_message_HIO_c)0xff;
  this[0x25] = (dMeter_message_HIO_c)0xff;
  this[0x26] = (dMeter_message_HIO_c)0xff;
  this[0x27] = (dMeter_message_HIO_c)0xff;
  this[0x28] = (dMeter_message_HIO_c)0x0;
  this[0x29] = (dMeter_message_HIO_c)0x80;
  this[0x2a] = (dMeter_message_HIO_c)0xff;
  this[0x2b] = (dMeter_message_HIO_c)0xff;
  this[0x2c] = (dMeter_message_HIO_c)0xff;
  this[0x2d] = (dMeter_message_HIO_c)0xff;
  this[0x2e] = (dMeter_message_HIO_c)0xb4;
  this[0x2f] = (dMeter_message_HIO_c)0xa0;
  this[0x30] = (dMeter_message_HIO_c)0x4b;
  this[0x31] = (dMeter_message_HIO_c)0x0;
  this[0x32] = (dMeter_message_HIO_c)0x1b;
  *(undefined2 *)(this + 0x34) = 0xfffe;
  *(undefined2 *)(this + 0x36) = 0x2a;
  *(undefined2 *)(this + 0x38) = 0xf;
  this[0x3a] = (dMeter_message_HIO_c)0x1;
  this[0x3b] = (dMeter_message_HIO_c)0xa;
  *(undefined2 *)(this + 0x3c) = 0x16;
  *(float *)(this + 0x40) = d_meter::_4686;
  this[0x44] = (dMeter_message_HIO_c)0x0;
  *(undefined2 *)(this + 0x46) = 1;
  *(undefined2 *)(this + 0x48) = 0;
  this[0x4a] = (dMeter_message_HIO_c)0x0;
  this[0x4b] = (dMeter_message_HIO_c)0x1;
  this[0x4c] = (dMeter_message_HIO_c)0xff;
  this[0x4d] = (dMeter_message_HIO_c)0xff;
  this[0x4e] = (dMeter_message_HIO_c)0xff;
  this[0x4f] = (dMeter_message_HIO_c)0xff;
  this[0x50] = (dMeter_message_HIO_c)0x0;
  this[0x51] = (dMeter_message_HIO_c)0x0;
  this[0x52] = (dMeter_message_HIO_c)0x0;
  this[0x53] = (dMeter_message_HIO_c)0x0;
  *(undefined2 *)(this + 0x54) = 0;
  *(undefined2 *)(this + 0x56) = 0;
  *(undefined2 *)(this + 0x58) = 0;
  this[0x5a] = (dMeter_message_HIO_c)0x0;
  this[0x5b] = (dMeter_message_HIO_c)0xff;
  this[0x5c] = (dMeter_message_HIO_c)0x0;
  *(undefined2 *)(this + 0x60) = 0;
  *(undefined2 *)(this + 0x66) = 0;
  *(undefined2 *)(this + 0x6c) = 1;
  *(undefined2 *)(this + 0x72) = 1;
  this[0x5d] = (dMeter_message_HIO_c)0x0;
  *(undefined2 *)(this + 0x62) = 0;
  *(undefined2 *)(this + 0x68) = 0;
  *(undefined2 *)(this + 0x6e) = 1;
  *(undefined2 *)(this + 0x74) = 1;
  this[0x5e] = (dMeter_message_HIO_c)0x0;
  *(undefined2 *)(this + 100) = 0;
  *(undefined2 *)(this + 0x6a) = 0;
  *(undefined2 *)(this + 0x70) = 1;
  *(undefined2 *)(this + 0x76) = 1;
  this[0x78] = (dMeter_message_HIO_c)0x0;
  *(undefined2 *)(this + 0x7a) = 4;
  *(undefined2 *)(this + 0x7c) = 4;
  *(undefined2 *)(this + 0x7e) = 2;
  *(undefined2 *)(this + 0x80) = 600;
  *(undefined2 *)(this + 0x82) = 0x18c;
  return;
}


namespace d_meter {

/* __stdcall dMeter_mtrShow(void) */

void dMeter_mtrShow(void)

{
  d_com_inf_game::g_dComIfG_gameInfo._23577_1_ = 1;
  return;
}


/* __stdcall dMeter_mtrHide(void) */

void dMeter_mtrHide(void)

{
  d_com_inf_game::g_dComIfG_gameInfo._23577_1_ = 0;
  return;
}


/* __stdcall dMenu_setMenuStatus(unsigned char) */

void dMenu_setMenuStatus(undefined param_1)

{
  menu_status = param_1;
  return;
}


/* __stdcall dMenu_setMenuStatusOld(unsigned char) */

void dMenu_setMenuStatusOld(char param_1)

{
  menu_status_old = param_1;
  return;
}


/* WARNING: Unknown calling convention yet parameter storage is locked */
/* __stdcall dMenu_getMenuStatus(void) */

byte dMenu_getMenuStatus(void)

{
  return menu_status;
}


/* __stdcall dMenu_getCollectMode(void) */

undefined dMenu_getCollectMode(void)

{
  return dMeter_collectMode;
}


/* __stdcall dMenu_setCollectMode(unsigned char) */

void dMenu_setCollectMode(undefined param_1)

{
  dMeter_collectMode = param_1;
  return;
}


/* __stdcall dMenu_getItemMode(void) */

undefined dMenu_getItemMode(void)

{
  return dMeter_itemMode;
}


/* __stdcall dMenu_setItemMode(unsigned char) */

void dMenu_setItemMode(undefined param_1)

{
  dMeter_itemMode = param_1;
  return;
}


/* __stdcall dMeter_subWinFlag(void) */

undefined dMeter_subWinFlag(void)

{
  return subWinFlag;
}


/* __stdcall dMeter_subWinFlagOn(void) */

void dMeter_subWinFlagOn(void)

{
  subWinFlag = 1;
  return;
}


/* __stdcall dMeter_subWinFlagOff(void) */

void dMeter_subWinFlagOff(void)

{
  subWinFlag = 0;
  return;
}


/* __stdcall dMeter_isAuctionFlag(void) */

undefined dMeter_isAuctionFlag(void)

{
  return dMeter_auctionFlag;
}


/* __stdcall dMeter_onAuctionFlag(void) */

void dMeter_onAuctionFlag(void)

{
  dMeter_auctionFlag = 1;
  return;
}


/* __stdcall dMeter_offAuctionFlag(void) */

void dMeter_offAuctionFlag(void)

{
  dMeter_auctionFlag = 0;
  return;
}


/* __stdcall dMeter_itemMoveSet(fopMsgM_pane_class *,
                                unsigned char,
                                unsigned char) */

void dMeter_itemMoveSet(int param_1,undefined param_2,undefined param_3)

{
  DAT_803e689c = *(undefined4 *)(param_1 + 0xc);
  DAT_803e68a0 = *(undefined4 *)(param_1 + 0x10);
  DAT_803e68a4 = *(undefined4 *)(param_1 + 0xc);
  DAT_803e68a8 = *(undefined4 *)(param_1 + 0x10);
  DAT_803e68ac = *(undefined4 *)(param_1 + 0x1c);
  DAT_803e68b0 = *(undefined4 *)(param_1 + 0x20);
  DAT_803e68b4 = *(undefined4 *)(param_1 + 0x1c);
  DAT_803e68b8 = *(undefined4 *)(param_1 + 0x20);
  DAT_803e68bc = *(undefined4 *)(param_1 + 0x24);
  DAT_803e68c0 = *(undefined4 *)(param_1 + 0x28);
  DAT_803e68c4 = *(undefined4 *)(param_1 + 0x2c);
  DAT_803e68c8 = *(undefined4 *)(param_1 + 0x30);
  dMeter_itemMoveFlag = 1;
  dMeter_btn_chk = param_2;
  dMeter_itemNum = param_3;
  dMeter_itemTimer = 0;
  return;
}


/* __stdcall dMeter_itemMoveFlagCheck(void) */

undefined dMeter_itemMoveFlagCheck(void)

{
  return dMeter_itemMoveFlag;
}


/* __stdcall dMenu_flag(void) */

byte dMenu_flag(void)

{
  return dMenu_pause;
}


/* __stdcall dMenu_flagSet(unsigned char) */

void dMenu_flagSet(byte param_1)

{
  dMenu_pause = param_1;
  return;
}


/* __stdcall dMenu_timer(void) */

undefined4 dMenu_timer(void)

{
  return dMenu_frame_timer;
}


/* __stdcall dMenu_getPushMenuButton(void) */

undefined dMenu_getPushMenuButton(void)

{
  return dMenu_menuButton;
}


/* __stdcall dMenu_setPushMenuButton(unsigned char) */

void dMenu_setPushMenuButton(undefined param_1)

{
  dMenu_menuButton = param_1;
  return;
}


/* __stdcall dMeter_PaneHide(fopMsgM_pane_class *) */

void dMeter_PaneHide(int *param_1)

{
  *(undefined *)(*param_1 + 0xaa) = 0;
  return;
}


/* __stdcall dMeter_isBit8(unsigned char *,
                           unsigned char) */

bool dMeter_isBit8(byte *param_1,byte param_2)

{
  return (param_2 & *param_1) != 0;
}


/* __stdcall dMeter_onBit8(unsigned char *,
                           unsigned char) */

void dMeter_onBit8(byte *param_1,byte param_2)

{
  *param_1 = *param_1 | param_2;
  return;
}


/* __stdcall dMeter_offBit8(unsigned char *,
                            unsigned char) */

void dMeter_offBit8(byte *param_1,byte param_2)

{
  *param_1 = *param_1 & ~param_2;
  return;
}


/* __stdcall dMeter_PaneShow(fopMsgM_pane_class *) */

void dMeter_PaneShow(int *param_1)

{
  *(undefined *)(*param_1 + 0xaa) = 1;
  return;
}


/* WARNING: Removing unreachable block (ram,0x801efc24) */
/* __stdcall dMeter_alphaControl(sub_meter_class *) */

void dMeter_alphaControl(sub_meter_class *this)

{
  byte bVar3;
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_com_inf_game::g_dComIfG_gameInfo._23577_1_ == '\0') {
    if (this->field_0x2f6c <= 0_0) {
      this->field_0x2f6c = 0_0;
      this->field_0x2fd8 = 0;
    }
    else {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((int)DAT_803e690e,(int)this->field_0x2fd8,0);
      this->field_0x2f6c = (float)dVar5;
      this->field_0x2fd8 = this->field_0x2fd8 + -1;
    }
  }
  else {
    bVar3 = dMenu_flag();
    if (bVar3 == 0) {
      if (1_0 <= this->field_0x2f6c) {
        this->field_0x2f6c = 1_0;
        this->field_0x2fd8 = DAT_803e690e;
      }
      else {
        dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                  ((int)DAT_803e690e,(int)this->field_0x2fd8,0);
        this->field_0x2f6c = (float)dVar5;
        this->field_0x2fd8 = this->field_0x2fd8 + 1;
      }
    }
    else {
      iVar1 = dMenu_timer();
      if (iVar1 < 6) {
        uVar2 = dMenu_timer();
        dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,uVar2,0);
        bVar3 = dMenu_getMenuStatus();
        if (bVar3 != 3) {
          dVar5 = (double)(_4664 + _4664 * (float)((double)1_0 - dVar5));
        }
        if (dVar5 < (double)this->field_0x2f6c) {
          this->field_0x2f6c = (float)dVar5;
        }
      }
      else {
        bVar3 = dMenu_getMenuStatus();
        if (bVar3 == 3) {
          this->field_0x2f6c = 0_0;
        }
        else {
          this->field_0x2f6c = _4664;
        }
      }
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMeter_statusCheck(sub_meter_class *) */

void dMeter_statusCheck(int param_1)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  
  *(undefined4 *)(param_1 + 0x3004) = 0;
  if (d_com_inf_game::g_dComIfG_gameInfo._23577_1_ == '\0') {
LAB_801efc84:
    *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x4000;
  }
  else {
    iVar1 = d_camera::dCam_getBody();
    if ((*(uint *)(iVar1 + 0x50c) & 0x2000000) != 0) goto LAB_801efc84;
    cVar2 = dMeter_isAuctionFlag();
    if (((cVar2 == '\0') || (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca != 0)) &&
       ((iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mEvent,0x408),
        iVar1 == 0 || (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca != 0)))) {
      iVar1 = dEvent_manager_c::startCheckOld
                        (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"PUZZLE_GAME");
      if (iVar1 != 0) goto LAB_801efd28;
      iVar1 = dEvent_manager_c::startCheckOld
                        (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"PUZZLE_RUPEE");
      if (iVar1 != 0) goto LAB_801efd28;
      if (d_com_inf_game::g_dComIfG_gameInfo._23526_1_ == '\x02') {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x17;
        *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x400000;
      }
      else {
        if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda == 8) &&
           ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x10U) == 0)) {
          d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x3d;
          d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0x3e;
          *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x80000;
        }
        else {
          if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc & 1U) != 0) {
            if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 7) {
              *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x200000;
              goto LAB_801efe80;
            }
          }
          if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode != 0) {
            bVar3 = dMenu_getMenuStatus();
            if (bVar3 != 4) {
              if ((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mState == 1) ||
                  (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca == 0)) ||
                 (d_com_inf_game::g_dComIfG_gameInfo.field_0x5be7 != 0)) {
                if (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mState == 1) ||
                   (d_com_inf_game::g_dComIfG_gameInfo.field_0x5be7 == 0)) {
                  *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x40;
                }
                else {
                  *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x200000;
                  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0x3e;
                }
              }
              else {
                *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x100;
              }
            }
          }
        }
      }
    }
    else {
LAB_801efd28:
      *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x80000;
      d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction = 0;
      d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
    }
  }
LAB_801efe80:
  bVar3 = dMenu_flag();
  if (bVar3 != 0) {
    if ((((d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc & 8U) == 0) &&
        (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe != 2)) &&
       ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe != 3 &&
        (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 != 6)))) {
      bVar3 = dMenu_getMenuStatus();
      if (bVar3 == 1) {
        *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 8;
      }
      else {
        bVar3 = dMenu_getMenuStatus();
        if (bVar3 == 2) {
          *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x10;
        }
        else {
          bVar3 = dMenu_getMenuStatus();
          if (bVar3 == 4) {
            *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x800000;
          }
          else {
            *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x20;
          }
        }
      }
    }
    else {
      *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x20000;
      d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction = 0;
      d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd = 0;
    }
    goto LAB_801f0128;
  }
  if ((daPy_lk_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpPlayerPartnerActor ==
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor) {
LAB_801eff7c:
    *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x40000;
    if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x35) {
      d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction = 0;
    }
  }
  else {
    if (daNpc_kam_c::m_hyoi_kamome != 0) goto LAB_801eff7c;
    if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x2000U) == 0) {
      if ((d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mShadowControl.mShadowSimple[117].mVolumeMtx
           .m[1][2] != 0.0) && ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x8000000U) != 0)
         ) goto LAB_801effcc;
    }
    else {
LAB_801effcc:
      *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x100000;
    }
  }
  if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x10U) == 0) {
    if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x200000U) == 0) {
      if ((((d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc & 8U) == 0) &&
          (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe != 2)) &&
         (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe != 3)) {
        if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 != 6) {
          if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x10000U) == 0) {
            if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x8000000U) == 0) {
              if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x800000U) == 0) {
                if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x100000U) == 0) {
                  if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x2000100U) == 0) {
                    if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x4000000U) != 0) {
                      *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x10000;
                    }
                  }
                  else {
                    *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x8000;
                  }
                }
                else {
                  *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x2000;
                }
              }
              else {
                iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->vtbl
                                  ->checkRopeTag)();
                if (iVar1 == 0) {
                  *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x1000;
                }
                else {
                  *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x800;
                }
              }
            }
            else {
              *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x200;
            }
          }
          else {
            *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x400;
          }
          goto LAB_801f0128;
        }
      }
      *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x20000;
      d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction = 0;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd = 0;
      d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
    }
    else {
      *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x80;
    }
  }
  else {
    *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 0x100;
  }
LAB_801f0128:
  iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  if ((*(uint *)(iVar1 + 0xc) >> 0x10 & 7) == 1) {
    *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 4;
  }
  else {
    iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                      (0x803c9d58);
    if ((*(uint *)(iVar1 + 0xc) >> 0x10 & 7) == 2) {
      *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 2;
    }
    else {
      *(uint *)(param_1 + 0x3004) = *(uint *)(param_1 + 0x3004) | 1;
    }
  }
  return;
}


/* __stdcall dMeter_alphaClose(short *,
                               short *) */

double dMeter_alphaClose(short *param_1,short *param_2)

{
  double dVar1;
  
  if (*param_1 == 8) {
    *param_1 = 9;
    dVar1 = (double)1_0;
    *param_2 = 1;
  }
  else {
    if (*param_1 == 9) {
      if (*param_2 < 6) {
        dVar1 = (double)f_op_msg_mng::fopMsgM_valueIncrease(6,(int)*param_2,1);
        dVar1 = (double)(float)((double)1_0 - dVar1);
        *param_2 = *param_2 + 1;
      }
      else {
        dVar1 = (double)0_0;
        *param_1 = 0;
      }
    }
    else {
      dVar1 = (double)0_0;
    }
  }
  return dVar1;
}


/* __stdcall dMeter_alphaOpen(short *,
                              short *) */

double dMeter_alphaOpen(short *param_1,short *param_2)

{
  double dVar1;
  
  if (*param_1 == 0) {
    *param_1 = 7;
    dVar1 = (double)0_0;
    *param_2 = 0;
  }
  else {
    if (*param_1 == 7) {
      if (*param_2 < 6) {
        dVar1 = (double)f_op_msg_mng::fopMsgM_valueIncrease(6,(int)*param_2,1);
        *param_2 = *param_2 + 1;
      }
      else {
        dVar1 = (double)1_0;
        *param_1 = 8;
      }
    }
    else {
      dVar1 = (double)1_0;
    }
  }
  return dVar1;
}


/* __stdcall dMeter_rupy_num(char *,
                             short) */

void dMeter_rupy_num(char *pDst,short num)

{
  MSL_C.PPCEABI.bare.H::sprintf(pDst,"rupy_num_%02d.bti",(int)num);
  return;
}


/* __stdcall dMeter_actionTex(short) */

char * dMeter_actionTex(ushort param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = 0;
  iVar4 = 0x3f;
  iVar3 = 0;
  do {
    iVar2 = iVar3;
    if (param_1 == (&act_5120[0].mAction)[iVar1]) break;
    iVar3 = iVar2 + 1;
    iVar1 = iVar1 + 8;
    iVar4 = iVar4 + -1;
    iVar2 = 0;
  } while (iVar4 != 0);
  return act_5120[iVar2].mpTexName;
}


/* __stdcall dMeter_weponTex(void) */

undefined * dMeter_weponTex(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = dSv_player_collect_c::isCollect
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,3);
  if (uVar2 == 0) {
    uVar2 = dSv_player_collect_c::isCollect
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,2);
    if (uVar2 == 0) {
      uVar2 = dSv_player_collect_c::isCollect
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,1);
      if (uVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
      }
    }
    else {
      iVar1 = 2;
    }
  }
  else {
    iVar1 = 3;
  }
  return (&wepon_5133)[iVar1];
}


/* __stdcall dMeter_heartTex(short) */

undefined * dMeter_heartTex(short param_1)

{
  return (&ht_5160)[param_1];
}


/* __stdcall dMeter_recollect_boss_data(void) */

void dMeter_recollect_boss_data(void)

{
  int iVar1;
  
  iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  if (((*(uint *)(iVar1 + 0xc) >> 0x10 & 7) == 3) &&
     (iVar1 = dSv_memBit_c::isDungeonItem
                        ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,3),
     iVar1 != 0)) {
    iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                      (0x803c9d58);
    if ((*(byte *)(iVar1 + 9) >> 1 == 3) &&
       (iVar1 = dSv_event_c::isEventBit
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3d80),
       iVar1 == 0)) {
      d_com_inf_game::dComIfGs_copyPlayerRecollectionData();
      dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3d80);
    }
    else {
      iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                        (0x803c9d58);
      if ((*(byte *)(iVar1 + 9) >> 1 == 4) &&
         (iVar1 = dSv_event_c::isEventBit
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3d40),
         iVar1 == 0)) {
        d_com_inf_game::dComIfGs_copyPlayerRecollectionData();
        dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3d40);
      }
      else {
        iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                          (0x803c9d58);
        if ((*(byte *)(iVar1 + 9) >> 1 == 6) &&
           (iVar1 = dSv_event_c::isEventBit
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3d20),
           iVar1 == 0)) {
          d_com_inf_game::dComIfGs_copyPlayerRecollectionData();
          dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3d20);
        }
        else {
          iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                            getStagInfo)(0x803c9d58);
          if ((*(byte *)(iVar1 + 9) >> 1 == 7) &&
             (iVar1 = dSv_event_c::isEventBit
                                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3d10),
             iVar1 == 0)) {
            d_com_inf_game::dComIfGs_copyPlayerRecollectionData();
            dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3d10)
            ;
          }
        }
      }
    }
  }
  return;
}

}

/* __thiscall dDlst_2DMETER1_c::draw(void) */

void __thiscall dDlst_2DMETER1_c::draw(dDlst_2DMETER1_c *this)

{
  J2DOrthoGraph *pCtx;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(d_meter::sMainParts3,d_meter::0_0,d_meter::0_0,&pCtx->parent);
  J2DScreen::draw(d_meter::sMainParts1,d_meter::0_0,d_meter::0_0,&pCtx->parent);
  if (d_meter::sScrTimer1 != (J2DScreen *)0x0) {
    d_meter::sScrTimer1->mbClipToParent = 1;
    J2DScreen::draw(d_meter::sScrTimer1,d_meter::0_0,d_meter::0_0,&pCtx->parent);
  }
  if (d_meter::sScrTimer2 != (J2DScreen *)0x0) {
    J2DScreen::draw(d_meter::sScrTimer2,d_meter::0_0,d_meter::0_0,&pCtx->parent);
  }
  J2DScreen::draw(d_meter::sChoiceRoad,d_meter::0_0,d_meter::0_0,&pCtx->parent);
  return;
}


/* __thiscall dDlst_2DMETER2_c::draw(void) */

void __thiscall dDlst_2DMETER2_c::draw(dDlst_2DMETER2_c *this)

{
  J2DOrthoGraph *pCtx;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(d_meter::sMainParts2,d_meter::0_0,d_meter::0_0,&pCtx->parent);
  return;
}


namespace d_meter {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMeter_heart_data_set(fopMsgM_pane_class *,
                                   fopMsgM_pane_class *,
                                   fopMsgM_pane_class *) */

void dMeter_heart_data_set
               (fopMsgM_pane_class *param_1,fopMsgM_pane_class *param_2,fopMsgM_pane_class *param_3)

{
  dMeter_setNowHeartScaleXY(param_2);
  dMeter_setNowHeartScaleXY(param_3);
  (param_1->mPosTopLeft).x = (param_2->mPosTopLeft).x;
  (param_1->mPosTopLeft).y = (param_2->mPosTopLeft).y;
  (param_1->mSize).x = (param_2->mSize).x;
  (param_1->mSize).y = (param_2->mSize).y;
  (param_1->mPosCenter).x = (param_2->mPosCenter).x;
  (param_1->mPosCenter).y = (param_2->mPosCenter).y;
  (*(code *)((param_1->mpPane->parent).vtbl)->move)
            ((double)(param_1->mPosTopLeft).x,(double)(param_1->mPosTopLeft).y);
  (*(code *)((param_1->mpPane->parent).vtbl)->resize)
            ((double)(param_1->mSize).x,(double)(param_1->mSize).y);
  return;
}


/* __stdcall dMeter_paneBottomScaleY(fopMsgM_pane_class *,
                                     float) */

void dMeter_paneBottomScaleY(double param_1,fopMsgM_pane_class *param_2)

{
  float fVar1;
  
  fVar1 = (param_2->mSize).y;
  (param_2->mSize).y = (float)((double)(param_2->mSizeOrig).y * param_1);
  (param_2->mPosCenter).y = ((param_2->mPosTopLeft).y + fVar1) - (param_2->mSize).y * _4664;
  f_op_msg_mng::fopMsgM_cposMove(param_2);
  return;
}


/* __stdcall dMeter_parentPaneTrans(fopMsgM_pane_class *,
                                    float) */

void dMeter_parentPaneTrans(double param_1,fopMsgM_pane_class *param_2)

{
  float fVar1;
  double dVar2;
  J2DScreen *pJVar3;
  
  dVar2 = _4622;
  (param_2->mPosCenter).x =
       (param_2->mPosCenter).x +
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6958 ^ 0x80000000) - _4622);
  (param_2->mPosCenter).y =
       (param_2->mPosCenter).y +
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e695a ^ 0x80000000) - dVar2);
  f_op_msg_mng::fopMsgM_paneScaleXY(param_2,(float)param_1);
  pJVar3 = param_2->mpPane;
  fVar1 = (param_2->mSize).y * _4664;
  (pJVar3->parent).mBasePosition.x = (param_2->mSize).x * _4664;
  (pJVar3->parent).mBasePosition.y = fVar1;
  (pJVar3->parent).mRotationAxis = 'z';
  (*(code *)((pJVar3->parent).vtbl)->calcMtx)();
  return;
}


/* __stdcall dMeter_childPaneTrans(fopMsgM_pane_class *,
                                   fopMsgM_pane_class *,
                                   float) */

void dMeter_childPaneTrans(double param_1,fopMsgM_pane_class *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  J2DScreen *pJVar3;
  double dVar4;
  
  fVar1 = (param_2->mPosCenterOrig).y;
  fVar2 = *(float *)(param_3 + 0x18);
  dVar4 = (double)1_0;
  (param_2->mPosCenter).x =
       (param_2->mPosCenter).x +
       ((param_2->mPosCenterOrig).x - *(float *)(param_3 + 0x14)) * (float)(param_1 - dVar4);
  (param_2->mPosCenter).y = (param_2->mPosCenter).y + (fVar1 - fVar2) * (float)(param_1 - dVar4);
  dVar4 = _4622;
  (param_2->mPosCenter).x =
       (param_2->mPosCenter).x +
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6958 ^ 0x80000000) - _4622);
  (param_2->mPosCenter).y =
       (param_2->mPosCenter).y +
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e695a ^ 0x80000000) - dVar4);
  f_op_msg_mng::fopMsgM_paneScaleXY(param_2,(float)param_1);
  pJVar3 = param_2->mpPane;
  fVar1 = (param_2->mSize).y * _4664;
  (pJVar3->parent).mBasePosition.x = (param_2->mSize).x * _4664;
  (pJVar3->parent).mBasePosition.y = fVar1;
  (pJVar3->parent).mRotationAxis = 'z';
  (*(code *)((pJVar3->parent).vtbl)->calcMtx)();
  return;
}


/* __stdcall dMeter_childPaneTransOnly(fopMsgM_pane_class *,
                                       fopMsgM_pane_class *,
                                       float,
                                       float) */

void dMeter_childPaneTransOnly
               (double param_1,double param_2,fopMsgM_pane_class *param_3,int param_4)

{
  float fVar1;
  float fVar2;
  J2DScreen *pJVar3;
  double dVar4;
  
  fVar1 = (param_3->mPosCenterOrig).y;
  fVar2 = *(float *)(param_4 + 0x18);
  dVar4 = (double)1_0;
  (param_3->mPosCenter).x =
       (param_3->mPosCenter).x +
       ((param_3->mPosCenterOrig).x - *(float *)(param_4 + 0x14)) * (float)(param_1 - dVar4);
  (param_3->mPosCenter).y = (param_3->mPosCenter).y + (fVar1 - fVar2) * (float)(param_1 - dVar4);
  dVar4 = _4622;
  (param_3->mPosCenter).x =
       (param_3->mPosCenter).x +
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6958 ^ 0x80000000) - _4622);
  (param_3->mPosCenter).y =
       (param_3->mPosCenter).y +
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e695a ^ 0x80000000) - dVar4);
  f_op_msg_mng::fopMsgM_paneScaleXY(param_3,(float)param_2);
  pJVar3 = param_3->mpPane;
  fVar1 = (param_3->mSize).y * _4664;
  (pJVar3->parent).mBasePosition.x = (param_3->mSize).x * _4664;
  (pJVar3->parent).mBasePosition.y = fVar1;
  (pJVar3->parent).mRotationAxis = 'z';
  (*(code *)((pJVar3->parent).vtbl)->calcMtx)();
  return;
}


/* __stdcall dMeter_childPaneTransChildTrans(fopMsgM_pane_class *,
                                             fopMsgM_pane_class *,
                                             fopMsgM_pane_class *,
                                             float,
                                             float) */

void dMeter_childPaneTransChildTrans
               (double param_1,double param_2,fopMsgM_pane_class *param_3,int param_4,int param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  J2DScreen *pJVar4;
  double dVar5;
  
  fVar2 = (param_3->mPosCenterOrig).y;
  fVar3 = *(float *)(param_4 + 0x18);
  dVar5 = (double)1_0;
  fVar1 = (float)(param_1 - dVar5);
  (param_3->mPosCenter).x =
       (param_3->mPosCenter).x + ((param_3->mPosCenterOrig).x - *(float *)(param_4 + 0x14)) * fVar1;
  (param_3->mPosCenter).y = (param_3->mPosCenter).y + (fVar2 - fVar3) * fVar1;
  fVar2 = *(float *)(param_5 + 0x20);
  fVar3 = (param_3->mPosCenter).x;
  fVar1 = (float)(param_2 - dVar5);
  (param_3->mPosCenter).x = fVar3 + (fVar3 - *(float *)(param_5 + 0x1c)) * fVar1;
  (param_3->mPosCenter).y = (param_3->mPosCenter).y + ((param_3->mPosCenter).y - fVar2) * fVar1;
  dVar5 = _4622;
  (param_3->mPosCenter).x =
       (param_3->mPosCenter).x +
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6958 ^ 0x80000000) - _4622);
  (param_3->mPosCenter).y =
       (param_3->mPosCenter).y +
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e695a ^ 0x80000000) - dVar5);
  f_op_msg_mng::fopMsgM_paneScaleXY(param_3,(float)param_2);
  pJVar4 = param_3->mpPane;
  fVar1 = (param_3->mSize).y * _4664;
  (pJVar4->parent).mBasePosition.x = (param_3->mSize).x * _4664;
  (pJVar4->parent).mBasePosition.y = fVar1;
  (pJVar4->parent).mRotationAxis = 'z';
  (*(code *)((pJVar4->parent).vtbl)->calcMtx)();
  return;
}


/* __stdcall dMeter_childPaneTransChildTransOnly(fopMsgM_pane_class *,
                                                 fopMsgM_pane_class *,
                                                 fopMsgM_pane_class *,
                                                 float,
                                                 float) */

void dMeter_childPaneTransChildTransOnly
               (double param_1,fopMsgM_pane_class *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  J2DScreen *pJVar3;
  double dVar4;
  
  fVar1 = (param_2->mPosCenterOrig).y;
  fVar2 = *(float *)(param_3 + 0x18);
  dVar4 = (double)1_0;
  (param_2->mPosCenter).x =
       (param_2->mPosCenter).x +
       ((param_2->mPosCenterOrig).x - *(float *)(param_3 + 0x14)) * (float)(param_1 - dVar4);
  (param_2->mPosCenter).y = (param_2->mPosCenter).y + (fVar1 - fVar2) * (float)(param_1 - dVar4);
  dVar4 = _4622;
  (param_2->mPosCenter).x =
       (param_2->mPosCenter).x +
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6958 ^ 0x80000000) - _4622);
  (param_2->mPosCenter).y =
       (param_2->mPosCenter).y +
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e695a ^ 0x80000000) - dVar4);
  f_op_msg_mng::fopMsgM_cposMove(param_2);
  pJVar3 = param_2->mpPane;
  fVar1 = (param_2->mSize).y * _4664;
  (pJVar3->parent).mBasePosition.x = (param_2->mSize).x * _4664;
  (pJVar3->parent).mBasePosition.y = fVar1;
  (pJVar3->parent).mRotationAxis = 'z';
  (*(code *)((pJVar3->parent).vtbl)->calcMtx)();
  return;
}


/* __stdcall dMeter_setHeartScaleXY(fopMsgM_pane_class *,
                                    short) */

void dMeter_setHeartScaleXY(fopMsgM_pane_class *this,short scale)

{
  float fVar1;
  float fVar2;
  
  fVar1 = texRateX;
  fVar2 = texRateY;
  if (scale != 4) {
    fVar1 = 1_0;
    fVar2 = 1_0;
  }
  (this->mSize).x = (this->mSizeOrig).x * fVar1;
  (this->mSize).y = (this->mSizeOrig).y * fVar2;
  f_op_msg_mng::fopMsgM_cposMove(this);
  return;
}


/* __stdcall dMeter_setHeartScaleXY2(fopMsgM_pane_class *,
                                     short) */

void dMeter_setHeartScaleXY2(fopMsgM_pane_class *this,short scale)

{
  float fVar1;
  float fVar2;
  
  fVar1 = texRateX;
  fVar2 = texRateY;
  if (scale != 4) {
    fVar1 = 1_0;
    fVar2 = 1_0;
  }
  (this->mSize).x = DAT_803e6950 * (this->mSizeOrig).x * fVar1;
  (this->mSize).y = DAT_803e6950 * (this->mSizeOrig).y * fVar2;
  f_op_msg_mng::fopMsgM_cposMove(this);
  return;
}


/* __stdcall dMeter_setNowHeartScaleXY(fopMsgM_pane_class *) */

void dMeter_setNowHeartScaleXY(fopMsgM_pane_class *param_1)

{
  (param_1->mSize).x = (param_1->mSizeOrig).x * DAT_803e6918;
  (param_1->mSize).y = (param_1->mSizeOrig).y * DAT_803e6918;
  f_op_msg_mng::fopMsgM_cposMove(param_1);
  return;
}


/* __stdcall dMeter_setNowHeartScaleXY2(fopMsgM_pane_class *) */

void dMeter_setNowHeartScaleXY2(fopMsgM_pane_class *param_1)

{
  (param_1->mSize).x = DAT_803e6950 * (param_1->mSizeOrig).x * DAT_803e6918;
  (param_1->mSize).y = DAT_803e6950 * (param_1->mSizeOrig).y * DAT_803e6918;
  f_op_msg_mng::fopMsgM_cposMove(param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMeter_heartChangeTexture(sub_meter_class *,
                                       char const *,
                                       int) */

void dMeter_heartChangeTexture(int param_1,char *param_2,int param_3)

{
  param_3 = param_3 * 0x38;
  J2DPicture::changeTexture(*(J2DPicture **)(param_1 + param_3 + 0x640),param_2,0);
  J2DPicture::changeTexture(*(J2DPicture **)(param_1 + param_3 + 0xaa0),param_2,0);
  dMeter_PaneShow(param_1 + param_3 + 0x640);
  dMeter_PaneShow(param_1 + param_3 + 0xaa0);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __stdcall dMeter_heartScaleInit(sub_meter_class *) */

void dMeter_heartScaleInit(sub_meter_class *this)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  char *pcVar4;
  fopMsgM_pane_class *pfVar5;
  fopMsgM_pane_class *pfVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  uVar1 = (uint)(this->mMaxHP >> 2);
  uVar2 = this->mCurrHP - 1;
  iVar10 = ((int)uVar2 >> 2) + (uint)((int)uVar2 < 0 && (uVar2 & 3) != 0);
  iVar9 = 0;
  iVar8 = 0;
  do {
    if (uVar1 == 0) {
      *(undefined2 *)((int)&this->field_0x640[0].mUserData + iVar8) = 5;
    }
    else {
      if (this->mCurrHP == 0) {
        if (iVar9 < (int)uVar1) {
          *(undefined2 *)((int)&this->field_0x640[0].mUserData + iVar8) = 4;
        }
        else {
          *(undefined2 *)((int)&this->field_0x640[0].mUserData + iVar8) = 5;
        }
      }
      else {
        if (iVar9 == iVar10) {
          *(ushort *)((int)&this->field_0x640[0].mUserData + iVar8) = this->mCurrHP & 3;
        }
        else {
          if (iVar9 < iVar10) {
            *(undefined2 *)((int)&this->field_0x640[0].mUserData + iVar8) = 0;
          }
          else {
            if (iVar9 < (int)uVar1) {
              *(undefined2 *)((int)&this->field_0x640[0].mUserData + iVar8) = 4;
            }
            else {
              *(undefined2 *)((int)&this->field_0x640[0].mUserData + iVar8) = 5;
            }
          }
        }
      }
    }
    iVar7 = &this->field_0x0 + iVar8;
    pfVar6 = (fopMsgM_pane_class *)(iVar7 + 0x640);
    dMeter_setHeartScaleXY(pfVar6,(int)*(short *)(iVar7 + 0x676));
    pfVar5 = (fopMsgM_pane_class *)(iVar7 + 0xaa0);
    dMeter_setHeartScaleXY(pfVar5,(int)*(short *)(iVar7 + 0x676));
    if (*(short *)(iVar7 + 0x676) == 5) {
      dMeter_PaneHide(pfVar6);
      dMeter_PaneHide(pfVar5);
    }
    else {
      uVar3 = dMeter_heartTex();
      dMeter_heartChangeTexture(this,uVar3,iVar9);
    }
    f_op_msg_mng::fopMsgM_paneTrans(pfVar6,(double)0_0,(double)0_0);
    f_op_msg_mng::fopMsgM_paneTrans(pfVar5,(double)0_0,(double)0_0);
    uVar2 = this->mCurrHP - 1;
    if ((iVar9 == ((int)uVar2 >> 2) + (uint)((int)uVar2 < 0 && (uVar2 & 3) != 0)) &&
       (this->mCurrHP != 0)) {
      pcVar4 = (char *)dMeter_heartTex((int)*(short *)(iVar7 + 0x676));
      J2DPicture::changeTexture((J2DPicture *)(this->field_0xf00).mpPane,pcVar4,0);
      dMeter_heart_data_set(&this->field_0xf00,pfVar6,pfVar5);
    }
    iVar9 = iVar9 + 1;
    iVar8 = iVar8 + 0x38;
  } while (iVar9 < 0x14);
  return;
}


/* __stdcall dMeter_maxLifeChange(sub_meter_class *) */

void dMeter_maxLifeChange(int param_1)

{
  if (0 < *(short *)(param_1 + 0x300c)) {
    *(char *)(param_1 + 0x301e) = *(char *)(param_1 + 0x301e) + '\x01';
    *(short *)(param_1 + 0x300c) = *(short *)(param_1 + 0x300c) + -1;
    return;
  }
  if (-1 < *(short *)(param_1 + 0x300c)) {
    return;
  }
  *(char *)(param_1 + 0x301e) = *(char *)(param_1 + 0x301e) + -1;
  *(short *)(param_1 + 0x300c) = *(short *)(param_1 + 0x300c) + 1;
  return;
}


/* __stdcall dMeter_lifeChange(sub_meter_class *,
                               bool *) */

void dMeter_lifeChange(sub_meter_class *this,bool *param_2)

{
  if (this->mAdjustHp < 1) {
    if (this->mAdjustHp < 0) {
      this->mCurrHP = this->mCurrHP - 1;
      this->mAdjustHp = this->mAdjustHp + 1;
    }
  }
  else {
    this->mCurrHP = this->mCurrHP + 1;
    this->mAdjustHp = this->mAdjustHp + -1;
    if (*param_2 != false) {
      if ((this->mCurrHP & 3) == 0) {
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x87c,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
      }
      if (this->mAdjustHp == 0) {
        *param_2 = false;
      }
    }
  }
  (this->field_0xf00).mUserData = 0;
  d_com_inf_game::g_dComIfG_gameInfo.mCurrHP = (ushort)this->mCurrHP;
  return;
}


/* WARNING: Removing unreachable block (ram,0x801f137c) */
/* WARNING: Removing unreachable block (ram,0x801f1384) */
/* __stdcall dMeter_heartLightMove(sub_meter_class *) */

void dMeter_heartLightMove(sub_meter_class *this)

{
  undefined uVar1;
  uint hp;
  int iVar2;
  J2DScreen *pJVar3;
  undefined uVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  hp = (ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrHp - 1;
  iVar2 = 0xc;
  if (((int)hp >> 2) + (uint)((int)hp < 0 && (hp & 3) != 0) != 0) {
    iVar2 = 0x16;
  }
  (this->field_0xf00).mUserData = (this->field_0xf00).mUserData + 1;
  if (iVar2 < (this->field_0xf00).mUserData) {
    (this->field_0xf00).mUserData = 0;
  }
  dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar2,(int)(this->field_0xf00).mUserData,0);
  dVar6 = (double)_4616;
  dVar8 = (double)(float)((double)1_0 + (double)(float)((double)DAT_803e6944 * dVar7));
  f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0xf00,(float)((double)1_0 - dVar7));
  uVar4 = (undefined)(int)(dVar6 * dVar7);
  uVar1 = (undefined)_5451;
  pJVar3 = (this->field_0xf00).mpPane;
  *(undefined *)&pJVar3[1].parent.mBox.mBR.x = uVar4;
  *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 1) = uVar4;
  *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 2) = uVar4;
  *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 3) = uVar1;
  dVar9 = (double)(float)((double)(this->field_0xf00).mSize.x * dVar8);
  dVar7 = (double)(float)((double)(this->field_0xf00).mSize.y * dVar8);
  dVar6 = (double)_4664;
  (this->field_0xf00).mPosTopLeft.x = (this->field_0xf00).mPosCenter.x - (float)(dVar9 * dVar6);
  (this->field_0xf00).mPosTopLeft.y = (this->field_0xf00).mPosCenter.y - (float)(dVar7 * dVar6);
  (*(code *)((((this->field_0xf00).mpPane)->parent).vtbl)->move)
            ((double)(this->field_0xf00).mPosTopLeft.x,(double)(this->field_0xf00).mPosTopLeft.y);
  (*(code *)((((this->field_0xf00).mpPane)->parent).vtbl)->resize)(dVar9,dVar7);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* __stdcall dMeter_heartAlpha(sub_meter_class *) */

void dMeter_heartAlpha(sub_meter_class *this)

{
  short sVar1;
  ushort uVar2;
  char cVar4;
  uint uVar3;
  double dVar5;
  
  if ((this->field_0x3004 & 0x4000) == 0) {
    if ((this->field_0x3004 & 0x40) != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.field_0xd6 & 0x10;
      }
      if ((uVar2 != 0) && ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc & 0x2000U) == 0))
      goto LAB_801f1470;
    }
    cVar4 = dMenu_getCollectMode();
    if (cVar4 != '\x04') {
      uVar3 = this->field_0x3004;
      if ((uVar3 & 0x200000) == 0) {
        if ((uVar3 & 0x80) == 0) {
          if ((uVar3 & 0x100000) == 0) {
            if ((uVar3 & 0x20000) == 0) {
              if (((uVar3 & 0x20) == 0) && ((uVar3 & 0x80000) == 0)) {
                cVar4 = dMeter_isAuctionFlag();
                if (cVar4 == '\0') {
                  uVar3 = this->field_0x3004;
                  if ((uVar3 & 0x400000) == 0) {
                    if ((uVar3 & 0x800000) == 0) {
                      if (((uVar3 & 8) == 0) && ((uVar3 & 0x10) == 0)) {
                        if (this->field_0x3014 < 5) {
                          this->field_0x3014 = this->field_0x3014 + 1;
                        }
                        else {
                          this->field_0x3014 = 5;
                        }
                        if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda != 6) {
                          JAIZelBasic::heartGaugeOn(JAIZelBasic::zel_basic);
                        }
                      }
                      else {
                        sVar1 = this->field_0x3014;
                        if (sVar1 < 3) {
                          this->field_0x3014 = sVar1 + 1;
                        }
                        else {
                          if (sVar1 < 4) {
                            this->field_0x3014 = 3;
                          }
                          else {
                            this->field_0x3014 = sVar1 + -1;
                          }
                        }
                      }
                      goto LAB_801f1514;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_801f1470:
  if (this->field_0x3014 < 1) {
    this->field_0x3014 = 0;
  }
  else {
    this->field_0x3014 = this->field_0x3014 + -1;
  }
LAB_801f1514:
  dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)this->field_0x3014,0);
  this->field_0x2fbc = (float)dVar5;
  return;
}


/* __stdcall dMeter_heartInit(sub_meter_class *) */

void dMeter_heartInit(sub_meter_class *this)

{
  texScaleX = this->field_0x640[0].mSizeOrig.x / 40_0;
  texScaleY = this->field_0x640[0].mSizeOrig.y * _5558;
  texRateX = _5559;
  texRateY = _4664;
  this->field_0x2f70 = 1_0;
  this->field_0x2fbc = 0_0;
  this->mMaxHP = (byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp;
  this->mCurrHP = (byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrHp;
  this->field_0x3014 = 5;
  (this->field_0xf00).mUserData = 0;
  (this->field_0xf00).mUserData = 0;
  f_op_msg_mng::fopMsgM_setNowAlphaZero(&this->field_0xf00);
  dMeter_heartScaleInit(this);
  d_com_inf_game::g_dComIfG_gameInfo.mCurrHP = (ushort)this->mCurrHP;
  return;
}


/* __stdcall dMeter_LifeMove(sub_meter_class *,
                             bool) */

void dMeter_LifeMove(sub_meter_class *this,bool bForce)

{
  int iVar1;
  bool bVar2;
  ushort maxHP;
  ushort newHP;
  uint uVar3;
  
  if (init_5564 == '\0') {
    soundOnFlag_5563 = false;
    init_5564 = '\x01';
  }
  bVar2 = false;
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCollectHeartPieceCount == 0) {
    if (((short)(int)(float)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustHp == 0) &&
       (bForce == false)) goto LAB_801f175c;
  }
  maxHP = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp +
          d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCollectHeartPieceCount;
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCollectHeartPieceCount < 1) {
    newHP = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrHp +
            (short)(int)(float)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustHp;
  }
  else {
    newHP = (((short)maxHP >> 2) + (ushort)((short)maxHP < 0 && (maxHP & 3) != 0)) * 4;
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCollectHeartPieceCount != 0) {
    if ((short)maxHP < 0x51) {
      if ((short)maxHP < 0) {
        maxHP = 0;
      }
    }
    else {
      maxHP = 0x50;
    }
    this->field_0x300c = maxHP - this->mMaxHP;
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp = maxHP & 0xff;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCollectHeartPieceCount = 0;
    (this->field_0x1050).mUserData = 1;
  }
  uVar3 = SEXT24((short)maxHP);
  iVar1 = (((int)uVar3 >> 2) + (uint)((int)uVar3 < 0 && (uVar3 & 3) != 0)) * 4;
  if (iVar1 < (short)newHP) {
    newHP = (ushort)iVar1;
  }
  else {
    if ((short)newHP < 0) {
      newHP = 0;
    }
  }
  this->mAdjustHp = newHP - this->mCurrHP;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrHp = newHP & 0xff;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustHp = (int)0_0;
  if (3 < this->mAdjustHp) {
    soundOnFlag_5563 = true;
  }
LAB_801f175c:
  if ((this->field_0x300c != 0) || (bForce != false)) {
    dMeter_maxLifeChange(this);
    bVar2 = true;
  }
  if ((this->mAdjustHp != 0) || (bForce != false)) {
    dMeter_lifeChange(this,&soundOnFlag_5563);
    bVar2 = true;
  }
  if (bVar2) {
    dMeter_heartScaleInit(this);
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrHp == 0) {
    f_op_msg_mng::fopMsgM_setNowAlphaZero(&this->field_0xf00);
  }
  else {
    dMeter_heartLightMove(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801f1a28) */
/* __stdcall dMeter_BattleLifeMove(sub_meter_class *,
                                   bool) */

void dMeter_BattleLifeMove(int param_1,char param_2)

{
  double dVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (init_5651 == '\0') {
    point_5650 = 0;
    init_5651 = '\x01';
  }
  dVar7 = (double)(*(float *)(param_1 + 0x68c) - *(float *)(param_1 + 0x654));
  if ((point_5650 != daNpc_Ji1_c::game_life_point) || (param_2 == '\0')) {
    uVar5 = 0;
    iVar4 = 0;
    do {
      dVar1 = _4622;
      point_5650 = daNpc_Ji1_c::game_life_point;
      if ((uVar5 == 1) || (uVar5 == 2)) {
        iVar3 = param_1 + iVar4;
        *(float *)(iVar3 + 0x65c) =
             DAT_803e6954 +
             *(float *)(param_1 + 0x654) +
             (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - _4622) *
             (float)((double)DAT_803e6960 * dVar7);
        *(float *)(iVar3 + 0xabc) =
             DAT_803e6954 +
             *(float *)(param_1 + 0xab4) +
             (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - dVar1) *
             (float)((double)DAT_803e6960 * dVar7);
        *(float *)(iVar3 + 0x660) = *(float *)(param_1 + 0x658) + DAT_803e6964;
        *(float *)(iVar3 + 0xac0) = *(float *)(param_1 + 0xab8) + DAT_803e6964;
      }
      else {
        if (uVar5 == 0) {
          iVar3 = param_1 + iVar4;
          *(float *)(iVar3 + 0x65c) = *(float *)(param_1 + 0x654) + DAT_803e6954;
          *(float *)(iVar3 + 0xabc) = *(float *)(param_1 + 0xab4) + DAT_803e6954;
          *(float *)(iVar3 + 0x660) = *(float *)(param_1 + 0x658) + DAT_803e6964;
          *(float *)(iVar3 + 0xac0) = *(float *)(param_1 + 0xab8) + DAT_803e6964;
        }
      }
      if ((int)uVar5 < (int)(uint)point_5650) {
        uVar2 = dMeter_heartTex(0);
        dMeter_heartChangeTexture(param_1,uVar2,uVar5);
        if (uVar5 == point_5650 - 1) {
          dMeter_setNowHeartScaleXY2(param_1 + iVar4 + 0x640);
          dMeter_setNowHeartScaleXY2(param_1 + iVar4 + 0xaa0);
        }
        else {
          dMeter_setHeartScaleXY2(param_1 + iVar4 + 0x640,0);
          dMeter_setHeartScaleXY2(param_1 + iVar4 + 0xaa0,0);
        }
      }
      else {
        if ((int)uVar5 < 3) {
          uVar2 = dMeter_heartTex(4);
          dMeter_heartChangeTexture(param_1,uVar2,uVar5);
          dMeter_setHeartScaleXY2(param_1 + iVar4 + 0x640,4);
          dMeter_setHeartScaleXY2(param_1 + iVar4 + 0xaa0,4);
        }
        else {
          dMeter_PaneHide(param_1 + iVar4 + 0x640);
          dMeter_PaneHide(param_1 + iVar4 + 0xaa0);
        }
      }
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x38;
    } while ((int)uVar5 < 0x14);
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* __stdcall dMeter_heartColor(sub_meter_class *) */

void dMeter_heartColor(int param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  double dVar16;
  
  if (((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x2a0 & 0x8000)
       == 0) || (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda == 6)) {
    if (*(short *)(param_1 + 0xad6) == 1) {
      iVar13 = 0;
      iVar15 = 0x14;
      do {
        iVar14 = *(int *)(param_1 + iVar13 + 0x640);
        *(undefined *)(iVar14 + 0x104) = 0xff;
        *(undefined *)(iVar14 + 0x105) = 0xff;
        *(undefined *)(iVar14 + 0x106) = 0xff;
        *(undefined *)(iVar14 + 0x107) = 0xff;
        iVar14 = *(int *)(param_1 + iVar13 + 0x640);
        *(undefined *)(iVar14 + 0x108) = 0;
        *(undefined *)(iVar14 + 0x109) = 0;
        *(undefined *)(iVar14 + 0x10a) = 0;
        *(undefined *)(iVar14 + 0x10b) = 0;
        iVar13 = iVar13 + 0x38;
        iVar15 = iVar15 + -1;
      } while (iVar15 != 0);
      *(undefined2 *)(param_1 + 0xad6) = 0;
    }
  }
  else {
    if (*(short *)(param_1 + 0xad6) == 0) {
      *(undefined2 *)(param_1 + 0xad6) = 1;
    }
    if (*(short *)(param_1 + 0xb0e) < 0x1d) {
      *(short *)(param_1 + 0xb0e) = *(short *)(param_1 + 0xb0e) + 1;
    }
    else {
      *(undefined2 *)(param_1 + 0xb0e) = 0;
    }
    iVar13 = (int)*(short *)(param_1 + 0xb0e);
    if (iVar13 < 0xf) {
      dVar16 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0xf,iVar13,0);
    }
    else {
      dVar16 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0xf,0x1e - iVar13,0);
    }
    dVar1 = 4503599627370751.0 - _4620;
    fVar7 = (float)(4503599627370751.0 - _4620) - _4616;
    dVar2 = 4503599627370751.0 - _4620;
    fVar8 = (float)(4503599627370751.0 - _4620) - _4616;
    dVar3 = 4503599627370751.0 - _4620;
    fVar9 = (float)(4503599627370751.0 - _4620) - _4616;
    dVar4 = 4503599627370496.0 - _4620;
    fVar10 = (float)(4503599627370496.0 - _4620) - _4616;
    dVar5 = 4503599627370496.0 - _4620;
    fVar11 = (float)(4503599627370496.0 - _4620) - _4616;
    dVar6 = 4503599627370496.0 - _4620;
    fVar12 = (float)(4503599627370496.0 - _4620) - _4616;
    iVar13 = 0;
    iVar15 = 0x14;
    do {
      iVar14 = *(int *)(param_1 + iVar13 + 0x640);
      *(char *)(iVar14 + 0x104) = (char)(int)((float)dVar1 - (float)((double)fVar7 * dVar16));
      *(char *)(iVar14 + 0x105) = (char)(int)((float)dVar2 - (float)((double)fVar8 * dVar16));
      *(char *)(iVar14 + 0x106) = (char)(int)((float)dVar3 - (float)((double)fVar9 * dVar16));
      *(undefined *)(iVar14 + 0x107) = 0xff;
      iVar14 = *(int *)(param_1 + iVar13 + 0x640);
      *(char *)(iVar14 + 0x108) = (char)(int)((float)dVar4 - (float)((double)fVar10 * dVar16));
      *(char *)(iVar14 + 0x109) = (char)(int)((float)dVar5 - (float)((double)fVar11 * dVar16));
      *(char *)(iVar14 + 0x10a) = (char)(int)((float)dVar6 - (float)((double)fVar12 * dVar16));
      *(undefined *)(iVar14 + 0x10b) = 0;
      iVar13 = iVar13 + 0x38;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
  }
  return;
}


/* __stdcall dMeter_heartMove(sub_meter_class *) */

void dMeter_heartMove(sub_meter_class *param_1)

{
  if (init_5798 == '\0') {
    flag_5797 = '\0';
    init_5798 = '\x01';
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda == 6) {
    dMeter_BattleLifeMove(param_1,flag_5797);
    flag_5797 = '\x01';
  }
  else {
    if (flag_5797 == '\0') {
      dMeter_LifeMove(param_1,false);
    }
    else {
      dMeter_heartInit(param_1);
      flag_5797 = '\0';
    }
  }
  dMeter_heartColor(param_1);
  dMeter_heartAlpha(param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dMeter_heartDraw(sub_meter_class *) */

void dMeter_heartDraw(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + iVar2 + 0x640));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + iVar2 + 0xaa0));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 0x14);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801f1ef8) */
/* __stdcall dMeter_weponInit(sub_meter_class *) */

void dMeter_weponInit(sub_meter_class *this)

{
  JKRArchive *pArc;
  char *pFilename;
  
  (this->field_0x28d0).mUserData = 0;
  this->field_0x301a = 0;
  pArc = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpActionIconArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction = 0;
  pFilename = dMeter_actionTex(0);
  JKRArchive::readTypeResource(this->mActionTex,0xc00,0x54494d47,pFilename,pArc);
  os::DCStoreRangeNoSync(this->mActionTex,0xc00);
  J2DPicture::changeTexture((J2DPicture *)(this->field_0x2828).mpPane,this->mActionTex,'\0');
  J2DPicture::changeTexture((J2DPicture *)(this->field_0x2860).mpPane,this->mActionTex,'\0');
  J2DPicture::changeTexture((J2DPicture *)(this->field_0x1d00).mpPane,this->mActionTex,'\0');
  (this->field_0x2828).mUserData = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall dMeter_weponMove(sub_meter_class *) */

void dMeter_weponMove(sub_meter_class *this)

{
  short sVar1;
  undefined uVar2;
  J2DScreen *pJVar3;
  int iVar4;
  uint uVar5;
  double dVar6;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 != 0) {
    d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction =
         d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1;
  }
  dMeter_weponChange(this);
  if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0x25) {
    (this->field_0x1d38).mUserData = (this->field_0x1d38).mUserData + 1;
    if (0x13 < (this->field_0x1d38).mUserData) {
      (this->field_0x1d38).mUserData = 0;
    }
    iVar4 = (int)(this->field_0x1d38).mUserData;
    if (iVar4 < 10) {
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar4,0);
    }
    else {
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,0x14 - iVar4,0);
    }
    uVar2 = (undefined)(int)-(float)((double)_5958 * dVar6);
    pJVar3 = (this->field_0x1d38).mpPane;
    *(undefined *)&pJVar3[1].parent.mBox.mTL.y = 0xff;
    *(undefined *)((int)&pJVar3[1].parent.mBox.mTL.y + 1) = 0xff;
    *(undefined *)((int)&pJVar3[1].parent.mBox.mTL.y + 2) = 0xff;
    *(undefined *)((int)&pJVar3[1].parent.mBox.mTL.y + 3) = 0xff;
    pJVar3 = (this->field_0x1d38).mpPane;
    *(undefined *)&pJVar3[1].parent.mBox.mBR.x = uVar2;
    *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 1) = uVar2;
    *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 2) = 0xff;
    *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 3) = 0;
    uVar5 = (uint)(this->field_0x1d00).mAlphaOrig;
    (this->field_0x1d38).mAlpha =
         (byte)(int)((float)((double)CONCAT44(0x43300000,uVar5) - _4620) -
                    (float)((double)(float)((double)CONCAT44(0x43300000,uVar5 - 0x78 ^ 0x80000000) -
                                           _4622) * dVar6));
  }
  else {
    if ((this->field_0x1d38).mUserData != 0) {
      pJVar3 = (this->field_0x1d38).mpPane;
      *(undefined *)&pJVar3[1].parent.mBox.mTL.y = 0xff;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mTL.y + 1) = 0xff;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mTL.y + 2) = 0xff;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mTL.y + 3) = 0xff;
      pJVar3 = (this->field_0x1d38).mpPane;
      *(undefined *)&pJVar3[1].parent.mBox.mBR.x = 0;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 1) = 0;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 2) = 0xff;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 3) = 0;
      (this->field_0x1d38).mAlpha = (this->field_0x1d00).mAlphaOrig;
      (this->field_0x1d38).mUserData = 0;
    }
  }
  if (((d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0x31) ||
      (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0x2d)) ||
     (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0x2e)) {
    (this->field_0x1e50).mUserData = (this->field_0x1e50).mUserData + 1;
    if (0x13 < (this->field_0x1e50).mUserData) {
      (this->field_0x1e50).mUserData = 0;
      if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0x2d) {
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x8f8,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
      }
      else {
        if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0x2e) {
          JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x90a,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
        }
        else {
          JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x852,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
        }
      }
    }
    iVar4 = (int)(this->field_0x1e50).mUserData;
    if (iVar4 < 10) {
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar4,0);
    }
    else {
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,0x14 - iVar4,0);
    }
    uVar2 = (undefined)(int)((double)_4616 * dVar6);
    pJVar3 = (this->field_0x1e50).mpPane;
    *(undefined *)&pJVar3[1].parent.mBox.mBR.x = uVar2;
    *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 1) = uVar2;
    *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 2) = uVar2;
    *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 3) = 0;
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0x1a) {
      pJVar3 = (this->field_0x1e50).mpPane;
      *(undefined *)&pJVar3[1].parent.mBox.mBR.x = 0;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 1) = 0;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 2) = 0;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 3) = 0;
    }
  }
  sVar1 = (this->field_0x28d0).mUserData;
  if ((sVar1 != 0) && (sVar1 < 0xd)) {
    dMeter_weponAnime(this);
    (this->field_0x28d0).mUserData = (this->field_0x28d0).mUserData + 1;
    if (0xc < (this->field_0x28d0).mUserData) {
      (this->field_0x28d0).mUserData = 0;
    }
  }
  dMeter_weponTrans(this);
  dMeter_weponAlpha(this);
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0;
  return;
}


/* __stdcall dMeter_weponDraw(sub_meter_class *) */

void dMeter_weponDraw(int param_1)

{
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x1d00));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x2828));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x2860));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x2898));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x28d0));
  return;
}


/* __stdcall dMeter_weponChange(sub_meter_class *) */

void dMeter_weponChange(int param_1)

{
  int iVar1;
  char *pcVar2;
  JKRArchive *pJVar3;
  
  if (*(short *)(param_1 + 0x285e) != 0) {
    if (*(char *)(param_1 + 0x301a) == '%') {
      *(undefined2 *)(param_1 + 0x1d36) = 0;
      iVar1 = *(int *)(param_1 + 0x1d00);
      *(undefined *)(iVar1 + 0x104) = 0xff;
      *(undefined *)(iVar1 + 0x105) = 0xff;
      *(undefined *)(iVar1 + 0x106) = 0xff;
      *(undefined *)(iVar1 + 0x107) = 0xff;
      iVar1 = *(int *)(param_1 + 0x1d00);
      *(undefined *)(iVar1 + 0x108) = 0;
      *(undefined *)(iVar1 + 0x109) = 0;
      *(undefined *)(iVar1 + 0x10a) = 0xff;
      *(undefined *)(iVar1 + 0x10b) = 0;
    }
    pJVar3 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive;
    if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x35) {
        pcVar2 = (char *)dMeter_weponTex();
        JKRArchive::readTypeResource(*(void **)(param_1 + 0x2f3c),0xc00,0x54494d47,pcVar2,pJVar3);
        os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0x2f3c),0xc00);
        J2DPicture::changeTexture
                  (*(J2DPicture **)(param_1 + 0x2828),*(ResTIMG **)(param_1 + 0x2f3c),'\0');
        J2DPicture::changeTexture
                  (*(J2DPicture **)(param_1 + 0x2860),*(ResTIMG **)(param_1 + 0x2f3c),'\0');
        J2DPicture::changeTexture
                  (*(J2DPicture **)(param_1 + 0x1d00),*(ResTIMG **)(param_1 + 0x2f3c),'\0');
      }
      else {
        if (((((d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x37) ||
              (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x38)) ||
             (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x39)) ||
            ((d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x3a ||
             (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x3b)))) ||
           (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x3c)) {
          pcVar2 = dMeter_actionTex((ushort)d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction);
          JKRArchive::readTypeResource(*(void **)(param_1 + 0x2f3c),0xc00,0x54494d47,pcVar2,pJVar3);
          os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0x2f3c),0xc00);
          J2DPicture::changeTexture
                    (*(J2DPicture **)(param_1 + 0x2828),*(ResTIMG **)(param_1 + 0x2f3c),'\0');
          J2DPicture::changeTexture
                    (*(J2DPicture **)(param_1 + 0x2860),*(ResTIMG **)(param_1 + 0x2f3c),'\0');
          J2DPicture::changeTexture
                    (*(J2DPicture **)(param_1 + 0x1d00),*(ResTIMG **)(param_1 + 0x2f3c),'\0');
        }
        else {
          if ((d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 7) ||
             (pJVar3 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpActionIconArchive,
             d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 7)) {
            pJVar3 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMenuArchive;
          }
          pcVar2 = dMeter_actionTex((ushort)d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction);
          JKRArchive::readTypeResource(*(void **)(param_1 + 0x2f3c),0xc00,0x54494d47,pcVar2,pJVar3);
          os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0x2f3c),0xc00);
          J2DPicture::changeTexture
                    (*(J2DPicture **)(param_1 + 0x2828),*(ResTIMG **)(param_1 + 0x2f3c),'\0');
          J2DPicture::changeTexture
                    (*(J2DPicture **)(param_1 + 0x2860),*(ResTIMG **)(param_1 + 0x2f3c),'\0');
          J2DPicture::changeTexture
                    (*(J2DPicture **)(param_1 + 0x1d00),*(ResTIMG **)(param_1 + 0x2f3c),'\0');
        }
      }
    }
    *(undefined2 *)(param_1 + 0x285e) = 0;
  }
  if (*(byte *)(param_1 + 0x301a) != d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction) {
    *(undefined2 *)(param_1 + 0x285e) = 1;
    *(undefined2 *)(param_1 + 0x2906) = 1;
    *(byte *)(param_1 + 0x301a) = d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x801f27fc) */
/* __stdcall dMeter_weponAnime(sub_meter_class *) */

void dMeter_weponAnime(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 in_f31;
  double dVar3;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar1 = SEXT24(*(short *)(param_1 + 0x2906));
  if ((int)uVar1 < 8) {
    dVar3 = (double)((_6052 * (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - _4622)) /
                    _6053);
  }
  else {
    if ((int)uVar1 < 0xb) {
      dVar3 = (double)(_6052 - (_6054 * (float)((double)CONCAT44(0x43300000,uVar1 - 7 ^ 0x80000000)
                                               - _4622)) / _6055);
    }
    else {
      dVar3 = (double)(_6056 + _6057 * (float)((double)CONCAT44(0x43300000,uVar1 - 10 ^ 0x80000000)
                                              - _4622) * _4664);
    }
  }
  (**(code **)(**(int **)(param_1 + 0x1d00) + 0x10))
            ((double)*(float *)(param_1 + 0x1d0c),
             (double)(float)((double)*(float *)(param_1 + 0x1d10) + dVar3));
  (**(code **)(**(int **)(param_1 + 0x2828) + 0x10))
            ((double)*(float *)(param_1 + 0x2834),
             (double)(float)((double)*(float *)(param_1 + 0x2838) + dVar3));
  (**(code **)(**(int **)(param_1 + 0x2860) + 0x10))
            ((double)*(float *)(param_1 + 0x286c),
             (double)(float)((double)*(float *)(param_1 + 0x2870) + dVar3));
  (**(code **)(**(int **)(param_1 + 0x2898) + 0x10))
            ((double)*(float *)(param_1 + 0x28a4),
             (double)(float)((double)*(float *)(param_1 + 0x28a8) + dVar3));
  (**(code **)(**(int **)(param_1 + 0x28d0) + 0x10))
            ((double)*(float *)(param_1 + 0x28dc),
             (double)(float)((double)*(float *)(param_1 + 0x28e0) + dVar3));
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801f3354) */
/* WARNING: Removing unreachable block (ram,0x801f335c) */
/* __stdcall dMeter_weponTrans(sub_meter_class *) */

void dMeter_weponTrans(int param_1)

{
  ushort uVar1;
  byte bVar3;
  char cVar4;
  int iVar2;
  uint uVar5;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f30;
  undefined8 in_f31;
  double x;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (init_6065 == '\0') {
    moveNowFrame_6064 = 0;
    init_6065 = '\x01';
  }
  if (init_6068 == '\0') {
    moveFlag_6067 = 0;
    init_6068 = '\x01';
  }
  if (init_6071 == '\0') {
    moveStatus_6070 = 0;
    init_6071 = '\x01';
  }
  if (init_6074 == '\0') {
    nowX_6073 = 0_0;
    init_6074 = '\x01';
  }
  if (init_6077 == '\0') {
    nowY_6076 = 0_0;
    init_6077 = '\x01';
  }
  if (init_6080 == '\0') {
    expX_6079 = 0_0;
    init_6080 = '\x01';
  }
  if (init_6083 == '\0') {
    expY_6082 = 0_0;
    init_6083 = '\x01';
  }
  uVar5 = *(uint *)(param_1 + 0x3004);
  if ((uVar5 & 0x4000) == 0) {
    if ((uVar5 & 0x40) != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.field_0xd6 & 4;
      }
      if ((uVar1 != 0) && ((uVar5 & 0x20) == 0)) goto LAB_801f2998;
    }
    if ((((uVar5 & 0x80) == 0) || (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 0xb))
       && ((((uVar5 & 0x100) == 0 || (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x27)
            ) && (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction != 0x3e)))) {
      if ((uVar5 & 0x80000) == 0) {
        if ((uVar5 & 0x20) == 0) {
          if ((((uVar5 & 0x80) == 0) && ((uVar5 & 0x100000) == 0)) &&
             (((uVar5 & 0x200000) == 0 || ((uVar5 & 0x10) != 0)))) {
            if ((uVar5 & 0x20000) == 0) {
              bVar3 = dMenu_flag();
              if ((bVar3 == 0) ||
                 ((cVar4 = dMenu_getPushMenuButton(), cVar4 != '\x01' &&
                  ((bVar3 = dMenu_getMenuStatus(), bVar3 != 1 ||
                   (cVar4 = dMenu_getPushMenuButton(), cVar4 != '\0')))))) {
                bVar3 = dMenu_flag();
                if ((bVar3 == 0) ||
                   ((cVar4 = dMenu_getPushMenuButton(), cVar4 != '\x02' &&
                    ((bVar3 = dMenu_getMenuStatus(), bVar3 != 2 ||
                     (cVar4 = dMenu_getPushMenuButton(), cVar4 != '\0')))))) {
                  uVar5 = *(uint *)(param_1 + 0x3004);
                  if ((uVar5 & 0x800000) == 0) {
                    if ((uVar5 & 0x40000) == 0) {
                      if ((uVar5 & 0x400000) == 0) {
                        if (((uVar5 & 0x100) == 0) ||
                           (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction != 0x27)) {
                          if (moveStatus_6070 != 0) {
                            moveFlag_6067 = 1;
                            dMeter_offBit8(param_1 + 0x3026,2);
                          }
                          moveStatus_6070 = 0;
                        }
                        else {
                          if (moveStatus_6070 != 7) {
                            moveFlag_6067 = 1;
                            dMeter_offBit8(param_1 + 0x3026,2);
                          }
                          moveStatus_6070 = 7;
                        }
                      }
                      else {
                        if (moveStatus_6070 != 5) {
                          moveFlag_6067 = 1;
                          dMeter_offBit8(param_1 + 0x3026,2);
                        }
                        moveStatus_6070 = 5;
                      }
                    }
                    else {
                      if (moveStatus_6070 != 6) {
                        moveFlag_6067 = 1;
                        dMeter_offBit8(param_1 + 0x3026,2);
                      }
                      moveStatus_6070 = 6;
                    }
                  }
                  else {
                    if (moveStatus_6070 != 5) {
                      moveFlag_6067 = 1;
                      dMeter_offBit8(param_1 + 0x3026,2);
                    }
                    moveStatus_6070 = 5;
                  }
                }
                else {
                  if (moveStatus_6070 != 5) {
                    moveFlag_6067 = 1;
                    dMeter_offBit8(param_1 + 0x3026,2);
                  }
                  moveStatus_6070 = 5;
                }
              }
              else {
                cVar4 = dMenu_getItemMode();
                if (cVar4 == '\0') {
                  if (moveStatus_6070 != 4) {
                    moveFlag_6067 = 1;
                    dMeter_offBit8(param_1 + 0x3026,2);
                  }
                  moveStatus_6070 = 4;
                }
                else {
                  if (moveStatus_6070 != 5) {
                    moveFlag_6067 = 1;
                    dMeter_offBit8(param_1 + 0x3026,2);
                  }
                  moveStatus_6070 = 5;
                }
              }
            }
            else {
              if (moveStatus_6070 != 3) {
                moveFlag_6067 = 1;
                dMeter_offBit8(param_1 + 0x3026,2);
              }
              moveStatus_6070 = 3;
            }
          }
          else {
            if (moveStatus_6070 != 2) {
              moveFlag_6067 = 1;
              dMeter_offBit8(param_1 + 0x3026,2);
            }
            moveStatus_6070 = 2;
          }
        }
        else {
          iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                            getStagInfo)(0x803c9d58);
          if ((*(ushort *)(iVar2 + 10) & 3) == 1) {
            if (moveStatus_6070 != 9) {
              moveFlag_6067 = 1;
              dMeter_offBit8(param_1 + 0x3026,2);
            }
            moveStatus_6070 = 9;
          }
          else {
            iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                              getStagInfo)(0x803c9d58);
            if ((*(ushort *)(iVar2 + 10) & 3) == 0) {
              if ((((cRam803f7071 == '\0') || (cRam803f7071 == '\x01')) || (cRam803f7071 == '\x02'))
                 || (cRam803f7071 == '\x03')) {
                if (moveStatus_6070 != 8) {
                  moveFlag_6067 = 1;
                  dMeter_offBit8(param_1 + 0x3026,2);
                }
                moveStatus_6070 = 8;
              }
              else {
                if (((cRam803f7071 == '\a') || (cRam803f7071 == '\b')) ||
                   ((cRam803f7071 == '\t' || (cRam803f7071 == '\n')))) {
                  if (moveStatus_6070 != 10) {
                    moveFlag_6067 = 1;
                    dMeter_offBit8(param_1 + 0x3026,2);
                  }
                  moveStatus_6070 = 10;
                }
                else {
                  if (cRam803f7071 == '\x06') {
                    if (moveStatus_6070 != 1) {
                      moveFlag_6067 = 1;
                      dMeter_offBit8(param_1 + 0x3026,2);
                    }
                    moveStatus_6070 = 1;
                  }
                  else {
                    if (moveStatus_6070 != 9) {
                      moveFlag_6067 = 1;
                      dMeter_offBit8(param_1 + 0x3026,2);
                    }
                    moveStatus_6070 = 9;
                  }
                }
              }
            }
          }
        }
      }
      else {
        if (moveStatus_6070 != 0xb) {
          moveFlag_6067 = 1;
          dMeter_offBit8(param_1 + 0x3026,2);
        }
        moveStatus_6070 = 0xb;
      }
      goto LAB_801f2dfc;
    }
  }
LAB_801f2998:
  if (moveStatus_6070 != 1) {
    moveFlag_6067 = 1;
    dMeter_offBit8(param_1 + 0x3026,2);
  }
  moveStatus_6070 = 1;
LAB_801f2dfc:
  if (*(char *)(param_1 + 0x3026) == '\x0f') {
    if (moveNowFrame_6064 < 1) {
      moveNowFrame_6064 = 0;
    }
    else {
      moveNowFrame_6064 = moveNowFrame_6064 + -1;
    }
  }
  else {
    iVar2 = dMeter_isBit8(param_1 + 0x3026,2);
    if (iVar2 == 0) {
      if (moveNowFrame_6064 < 5) {
        moveNowFrame_6064 = moveNowFrame_6064 + 1;
      }
      else {
        moveNowFrame_6064 = 5;
        moveFlag_6067 = 0;
        dMeter_onBit8(param_1 + 0x3026,2);
        switch(moveStatus_6070) {
        default:
          nowX_6073 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69fa ^ 0x80000000) - _4622);
          nowY_6076 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a02 ^ 0x80000000) - _4622);
          break;
        case 1:
          nowX_6073 = 0_0;
          nowY_6076 = _6268;
          break;
        case 2:
          nowX_6073 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69aa ^ 0x80000000) - _4622);
          nowY_6076 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69b2 ^ 0x80000000) - _4622);
          break;
        case 3:
          nowX_6073 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69ba ^ 0x80000000) - _4622);
          nowY_6076 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69c2 ^ 0x80000000) - _4622);
          break;
        case 4:
          nowX_6073 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69ca ^ 0x80000000) - _4622);
          nowY_6076 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69d2 ^ 0x80000000) - _4622);
          break;
        case 5:
          nowX_6073 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69da ^ 0x80000000) - _4622);
          nowY_6076 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69e2 ^ 0x80000000) - _4622);
          break;
        case 6:
          nowX_6073 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69ea ^ 0x80000000) - _4622);
          nowY_6076 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69f2 ^ 0x80000000) - _4622);
          break;
        case 7:
          nowX_6073 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a0a ^ 0x80000000) - _4622);
          nowY_6076 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a12 ^ 0x80000000) - _4622);
          break;
        case 8:
          nowX_6073 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a1a ^ 0x80000000) - _4622);
          nowY_6076 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a22 ^ 0x80000000) - _4622);
          break;
        case 9:
          iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                            getStagInfo)(0x803c9d58);
          if ((*(ushort *)(iVar2 + 10) & 3) == 1) {
            nowX_6073 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a0e ^ 0x80000000) - _4622)
            ;
            nowY_6076 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a16 ^ 0x80000000) - _4622)
            ;
          }
          else {
            iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                              getStagInfo)(0x803c9d58);
            if ((*(ushort *)(iVar2 + 10) & 3) == 0) {
              nowX_6073 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a0e - 0x21U ^ 0x80000000
                                                  ) - _4622);
              nowY_6076 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a16 - 4U ^ 0x80000000) -
                                 _4622);
            }
          }
          break;
        case 10:
          nowX_6073 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a1a + 0x12U ^ 0x80000000) -
                             _4622);
          nowY_6076 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a22 + 3U ^ 0x80000000) -
                             _4622);
          break;
        case 0xb:
          nowX_6073 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69fa ^ 0x80000000) - _4622);
          nowY_6076 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a02 - 0x3cU ^ 0x80000000) -
                             _4622);
        }
      }
    }
  }
  dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)moveNowFrame_6064,0);
  x = (double)nowX_6073;
  dVar7 = (double)(nowY_6076 + (float)(dVar7 * (double)(_6268 - nowY_6076)));
  if (moveStatus_6070 == 10) {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(param_1 + 0x1d00),
               (double)(_6269 + (float)(x + (double)expX_6079)),
               (double)(_6270 + (float)(dVar7 + (double)expY_6082)));
  }
  else {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(param_1 + 0x1d00),(double)(float)(x + (double)expX_6079),
               (double)(float)(dVar7 + (double)expY_6082));
  }
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x2828),x,dVar7);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x2860),x,dVar7);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x2898),x,dVar7);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x28d0),x,dVar7);
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return;
}


/* __stdcall dMeter_weponAlpha(sub_meter_class *) */

void dMeter_weponAlpha(int param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  double dVar4;
  
  if (init_6280 == '\0') {
    alphaNowFrame_6279 = 0;
    init_6280 = '\x01';
  }
  uVar3 = *(uint *)(param_1 + 0x3004);
  if ((uVar3 & 0x400) == 0) {
LAB_801f33d4:
    if ((uVar3 & 0x2000) != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction != 2) goto LAB_801f345c;
    }
    if ((uVar3 & 2) != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x35) {
        iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Ojhous");
        if (iVar1 != 0) {
          iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Orichh")
          ;
          if (iVar1 != 0) goto LAB_801f345c;
        }
      }
    }
    uVar3 = *(uint *)(param_1 + 0x3004);
    if ((uVar3 & 0x8000) == 0) {
      if ((uVar3 & 0x10000) == 0) {
        if ((((uVar3 & 2) == 0) ||
            (((d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction != 0x35 &&
              (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction != 0)) &&
             (bVar2 = dMenu_flag(), bVar2 == 0)))) ||
           ((iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                               (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                "Ojhous"), iVar1 == 0 ||
            (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                               (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,
                                "Orichh"), iVar1 == 0)))) {
          *(byte *)(param_1 + 0x3024) = *(byte *)(param_1 + 0x3024) | 2;
        }
        if (alphaNowFrame_6279 < 5) {
          alphaNowFrame_6279 = alphaNowFrame_6279 + 1;
        }
        else {
          alphaNowFrame_6279 = 5;
        }
        goto LAB_801f3530;
      }
    }
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction != 0x35) goto LAB_801f33d4;
  }
LAB_801f345c:
  if (alphaNowFrame_6279 < 4) {
    if (alphaNowFrame_6279 < 3) {
      alphaNowFrame_6279 = alphaNowFrame_6279 + 1;
    }
    else {
      alphaNowFrame_6279 = 3;
    }
  }
  else {
    alphaNowFrame_6279 = alphaNowFrame_6279 + -1;
  }
LAB_801f3530:
  dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)alphaNowFrame_6279,0);
  if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0) {
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1d00));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2828));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2860));
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2898),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x28d0),(float)dVar4);
  }
  else {
    if (((d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x35) ||
        (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x37)) ||
       ((d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x38 ||
        ((((d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x39 ||
           (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x3a)) ||
          (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x3b)) ||
         (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction == 0x3c)))))) {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1d00));
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2828),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2860),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2898),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x28d0),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2908),(float)dVar4);
    }
    else {
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1d00),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2828));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2860));
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2898),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x28d0),(float)dVar4);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2908),(float)dVar4);
    }
  }
  iVar1 = dMeter_isBit8(param_1 + 0x3026,2);
  if ((iVar1 == 0) || (*(short *)(param_1 + 0x285e) != 0)) {
    *(undefined *)(*(int *)(param_1 + 0x1d00) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x2828) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x2860) + 0xaa) = 0;
  }
  else {
    *(undefined *)(*(int *)(param_1 + 0x1d00) + 0xaa) = 1;
    *(undefined *)(*(int *)(param_1 + 0x2828) + 0xaa) = 1;
    *(undefined *)(*(int *)(param_1 + 0x2860) + 0xaa) = 1;
  }
  return;
}


/* __stdcall dMeter_actionInit(sub_meter_class *) */

void dMeter_actionInit(int param_1)

{
  JKRArchive *pArc;
  char *pFilename;
  
  *(undefined2 *)(param_1 + 0x1e4e) = 0;
  *(undefined2 *)(param_1 + 0x27ee) = 0;
  *(undefined *)(param_1 + 0x301b) = 0;
  pArc = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpActionIconArchive;
  d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
  pFilename = dMeter_actionTex(0);
  JKRArchive::readTypeResource(*(void **)(param_1 + 0x2f40),0xc00,0x54494d47,pFilename,pArc);
  os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0x2f40),0xc00);
  J2DPicture::changeTexture(*(J2DPicture **)(param_1 + 0x27b8),*(ResTIMG **)(param_1 + 0x2f40),'\0')
  ;
  J2DPicture::changeTexture(*(J2DPicture **)(param_1 + 0x27f0),*(ResTIMG **)(param_1 + 0x2f40),'\0')
  ;
  J2DPicture::changeTexture(*(J2DPicture **)(param_1 + 0x1d38),*(ResTIMG **)(param_1 + 0x2f40),'\0')
  ;
  return;
}


/* __stdcall dMeter_actionMove(sub_meter_class *) */

void dMeter_actionMove(sub_meter_class *param_1)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 == 0) {
    dMeter_actionForce();
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction =
         d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2;
  }
  dMeter_actionChange(param_1);
  dMeter_actionTrans(param_1);
  dMeter_actionAlpha(param_1);
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dMeter_actionDraw(sub_meter_class *) */

void dMeter_actionDraw(int param_1)

{
  int iVar1;
  int iVar2;
  
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x1d38));
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + iVar2 + 0x1e18));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + iVar2 + 0x1da8));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 2);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x2748));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x2780));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x27b8));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x27f0));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x2908));
  return;
}


/* __stdcall dMeter_actionForce(sub_meter_class *) */

void dMeter_actionForce(int param_1)

{
  ushort uVar1;
  char cVar3;
  int iVar2;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x3004);
  if ((uVar4 & 0x4000) == 0) {
    if ((uVar4 & 0x40) != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.field_0xd6 & 4;
      }
      if ((uVar1 != 0) && ((uVar4 & 0x20) == 0)) goto LAB_801f38c8;
    }
    if (((((uVar4 & 8) == 0) && ((uVar4 & 0x10) == 0)) && ((uVar4 & 0x800000) == 0)) &&
       ((uVar4 & 0x20) == 0)) {
      if ((uVar4 & 0x100) == 0) {
        return;
      }
      if (dMeter_Info == '\x01') {
        d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0x19;
      }
      else {
        if (dMeter_Info == '\x03') {
          d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0x17;
        }
        else {
          if (dMeter_Info == '\x04') {
            d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 7;
          }
          else {
            d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
          }
        }
      }
      if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 != 0) {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
      }
      if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 == 0) {
        return;
      }
      d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction =
           d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0;
      return;
    }
    cVar3 = dMenu_getCollectMode();
    if (cVar3 != '\x05') {
      d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonBAction = 7;
    }
    if (((*(uint *)(param_1 + 0x3004) & 0x20) != 0) &&
       (iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                          (), (*(ushort *)(iVar2 + 10) & 3) == 0)) {
      if (((cRam803f7071 != '\0') && ((cRam803f7071 != '\x01' && (cRam803f7071 != '\x02')))) &&
         (cRam803f7071 != '\x03')) {
        if ((((cRam803f7071 != '\a') && (cRam803f7071 != '\b')) && (cRam803f7071 != '\t')) &&
           (cRam803f7071 != '\n')) {
          if (cRam803f7071 == '\x04') {
            d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd = 0;
            d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0x17;
            return;
          }
          d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd = 0;
          d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
          return;
        }
        if (cRam803f7071 == '\n') {
          d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = Open;
        }
        else {
          d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
        }
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd = 0x30;
        return;
      }
      if (cRam803f7071 == '\0') {
        d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0x2a;
      }
      else {
        if (cRam803f7071 == '\x01') {
          d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0x2b;
        }
        else {
          if ((cRam803f7071 == '\x02') || (cRam803f7071 == '\x03')) {
            d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
          }
        }
      }
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd = 3;
      return;
    }
    if ((*(uint *)(param_1 + 0x3004) & 0x800000) != 0) {
      d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0x17;
    }
  }
  else {
LAB_801f38c8:
    d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMeter_actionChange(sub_meter_class *) */

void dMeter_actionChange(sub_meter_class *pMeter)

{
  char *pcVar1;
  JKRArchive *pJVar2;
  
  pJVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive;
  if ((pMeter->field_0x27b8).mUserData != 0) {
    if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0) {
      (pMeter->field_0x1e18).mUserData = 1;
    }
    else {
      if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0x1a) {
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x85f,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
      }
      else {
        if (((d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction != 0x31) &&
            (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction != 0x2d)) &&
           (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction != 0x2e)) {
          if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0x3d) {
            pcVar1 = dMeter_actionTex((ushort)d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction)
            ;
            JKRArchive::readTypeResource(pMeter->mpActionTexData,0xc00,0x54494d47,pcVar1,pJVar2);
            os::DCStoreRangeNoSync(pMeter->mpActionTexData,0xc00);
            J2DPicture::changeTexture
                      ((J2DPicture *)(pMeter->field_0x27b8).mpPane,pMeter->mpActionTexData,'\0');
            J2DPicture::changeTexture
                      ((J2DPicture *)(pMeter->field_0x27f0).mpPane,pMeter->mpActionTexData,'\0');
          }
          else {
            if ((d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 7) ||
               (pJVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpActionIconArchive,
               d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 7)) {
              pJVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMenuArchive;
            }
            pcVar1 = dMeter_actionTex((ushort)d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction)
            ;
            JKRArchive::readTypeResource(pMeter->mpActionTexData,0xc00,0x54494d47,pcVar1,pJVar2);
            os::DCStoreRangeNoSync(pMeter->mpActionTexData,0xc00);
            J2DPicture::changeTexture
                      ((J2DPicture *)(pMeter->field_0x1d38).mpPane,pMeter->mpActionTexData,'\0');
            (pMeter->field_0x1e18).mUserData = 1;
          }
        }
      }
    }
    pMeter->field_0x301b = d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction;
    (pMeter->field_0x27b8).mUserData = 0;
  }
  if (pMeter->field_0x301b != d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction) {
    (pMeter->field_0x27b8).mUserData = 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801f4874) */
/* WARNING: Removing unreachable block (ram,0x801f487c) */
/* __stdcall dMeter_actionTrans(sub_meter_class *) */

void dMeter_actionTrans(int param_1)

{
  ushort uVar1;
  byte bVar3;
  char cVar4;
  int iVar2;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f30;
  undefined8 in_f31;
  double x;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (init_6603 == '\0') {
    moveNowFrame_6602 = 0;
    init_6603 = '\x01';
  }
  if (init_6606 == '\0') {
    moveFlag_6605 = 0;
    init_6606 = '\x01';
  }
  if (init_6609 == '\0') {
    moveStatus_6608 = 0;
    init_6609 = '\x01';
  }
  if (init_6612 == '\0') {
    nowX_6611 = 0_0;
    init_6612 = '\x01';
  }
  if (init_6615 == '\0') {
    nowY_6614 = 0_0;
    init_6615 = '\x01';
  }
  if (init_6618 == '\0') {
    expX_6617 = 0_0;
    init_6618 = '\x01';
  }
  if (init_6621 == '\0') {
    expY_6620 = 0_0;
    init_6621 = '\x01';
  }
  uVar5 = *(uint *)(param_1 + 0x3004);
  if ((uVar5 & 0x4000) == 0) {
    if ((uVar5 & 0x40) != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.field_0xd6 & 2;
      }
      if ((uVar1 != 0) && ((uVar5 & 0x20) == 0)) goto LAB_801f3e6c;
    }
    if ((((uVar5 & 0x80) == 0) && ((uVar5 & 0x100000) == 0)) &&
       (((((uVar5 & 0x200000) == 0 || ((uVar5 & 0x20) != 0)) || ((uVar5 & 0x10) != 0)) &&
        (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction != 0x3e)))) {
      if ((uVar5 & 0x20) == 0) {
        if ((uVar5 & 0x20000) == 0) {
          bVar3 = dMenu_flag();
          if ((bVar3 == 0) ||
             ((cVar4 = dMenu_getPushMenuButton(), cVar4 != '\x01' &&
              ((bVar3 = dMenu_getMenuStatus(), bVar3 != 1 ||
               (cVar4 = dMenu_getPushMenuButton(), cVar4 != '\0')))))) {
            bVar3 = dMenu_flag();
            if ((bVar3 == 0) ||
               ((cVar4 = dMenu_getPushMenuButton(), cVar4 != '\x02' &&
                ((bVar3 = dMenu_getMenuStatus(), bVar3 != 2 ||
                 (cVar4 = dMenu_getPushMenuButton(), cVar4 != '\0')))))) {
              uVar5 = *(uint *)(param_1 + 0x3004);
              if ((uVar5 & 0x800000) == 0) {
                if ((uVar5 & 0x40000) == 0) {
                  if ((uVar5 & 0x100) == 0) {
                    if ((uVar5 & 0x80000) == 0) {
                      if ((uVar5 & 0x400000) == 0) {
                        if (moveStatus_6608 != 0) {
                          moveFlag_6605 = 1;
                          dMeter_offBit8(param_1 + 0x3026,1);
                        }
                        moveStatus_6608 = 0;
                      }
                      else {
                        if (moveStatus_6608 != 4) {
                          moveFlag_6605 = 1;
                          dMeter_offBit8(param_1 + 0x3026,1);
                        }
                        moveStatus_6608 = 4;
                      }
                    }
                    else {
                      if (moveStatus_6608 != 6) {
                        moveFlag_6605 = 1;
                        dMeter_offBit8(param_1 + 0x3026,1);
                      }
                      moveStatus_6608 = 6;
                    }
                  }
                  else {
                    if (moveStatus_6608 != 7) {
                      moveFlag_6605 = 1;
                      dMeter_offBit8(param_1 + 0x3026,1);
                    }
                    moveStatus_6608 = 7;
                  }
                }
                else {
                  if (moveStatus_6608 != 5) {
                    moveFlag_6605 = 1;
                    dMeter_offBit8(param_1 + 0x3026,1);
                  }
                  moveStatus_6608 = 5;
                }
              }
              else {
                if (moveStatus_6608 != 4) {
                  moveFlag_6605 = 1;
                  dMeter_offBit8(param_1 + 0x3026,1);
                }
                moveStatus_6608 = 4;
              }
            }
            else {
              if (moveStatus_6608 != 4) {
                moveFlag_6605 = 1;
                dMeter_offBit8(param_1 + 0x3026,1);
              }
              moveStatus_6608 = 4;
            }
          }
          else {
            cVar4 = dMenu_getItemMode();
            if (cVar4 == '\0') {
              if (moveStatus_6608 != 3) {
                moveFlag_6605 = 1;
                dMeter_offBit8(param_1 + 0x3026,1);
              }
              moveStatus_6608 = 3;
            }
            else {
              if (moveStatus_6608 != 4) {
                moveFlag_6605 = 1;
                dMeter_offBit8(param_1 + 0x3026,1);
              }
              moveStatus_6608 = 4;
            }
          }
        }
        else {
          if (moveStatus_6608 != 2) {
            moveFlag_6605 = 1;
            dMeter_offBit8(param_1 + 0x3026,1);
          }
          moveStatus_6608 = 2;
        }
      }
      else {
        iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                          (0x803c9d58);
        if ((*(ushort *)(iVar2 + 10) & 3) == 1) {
          if (moveStatus_6608 != 9) {
            moveFlag_6605 = 1;
            dMeter_offBit8(param_1 + 0x3026,1);
          }
          moveStatus_6608 = 9;
        }
        else {
          iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                            getStagInfo)(0x803c9d58);
          if ((*(ushort *)(iVar2 + 10) & 3) == 0) {
            if ((((cRam803f7071 == '\0') || (cRam803f7071 == '\x01')) || (cRam803f7071 == '\x02'))
               || (cRam803f7071 == '\x03')) {
              if (moveStatus_6608 != 8) {
                moveFlag_6605 = 1;
                dMeter_offBit8(param_1 + 0x3026,1);
              }
              moveStatus_6608 = 8;
            }
            else {
              if (((cRam803f7071 == '\a') || (cRam803f7071 == '\b')) ||
                 ((cRam803f7071 == '\t' || (cRam803f7071 == '\n')))) {
                if (moveStatus_6608 != 0xb) {
                  moveFlag_6605 = 1;
                  dMeter_offBit8(param_1 + 0x3026,1);
                }
                moveStatus_6608 = 0xb;
              }
              else {
                if ((cRam803f7071 == '\v') || (cRam803f7071 == '\x06')) {
                  if (moveStatus_6608 != 1) {
                    moveFlag_6605 = 1;
                    dMeter_offBit8(param_1 + 0x3026,1);
                  }
                  moveStatus_6608 = 1;
                }
                else {
                  if (moveStatus_6608 != 9) {
                    moveFlag_6605 = 1;
                    dMeter_offBit8(param_1 + 0x3026,1);
                  }
                  moveStatus_6608 = 9;
                }
              }
            }
          }
        }
      }
      goto LAB_801f4280;
    }
  }
LAB_801f3e6c:
  if (moveStatus_6608 != 1) {
    moveFlag_6605 = 1;
    dMeter_offBit8(param_1 + 0x3026,1);
  }
  moveStatus_6608 = 1;
LAB_801f4280:
  if (*(char *)(param_1 + 0x3026) == '\x0f') {
    if (moveNowFrame_6602 < 1) {
      moveNowFrame_6602 = 0;
    }
    else {
      moveNowFrame_6602 = moveNowFrame_6602 + -1;
    }
  }
  else {
    iVar2 = dMeter_isBit8(param_1 + 0x3026,1);
    if (iVar2 == 0) {
      if (moveNowFrame_6602 < 5) {
        moveNowFrame_6602 = moveNowFrame_6602 + 1;
      }
      else {
        moveNowFrame_6602 = 5;
        moveFlag_6605 = 0;
        dMeter_onBit8(param_1 + 0x3026,1);
        switch(moveStatus_6608) {
        default:
          nowX_6611 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69f8 ^ 0x80000000) - _4622);
          nowY_6614 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a00 ^ 0x80000000) - _4622);
          break;
        case 1:
          nowX_6611 = 0_0;
          nowY_6614 = _6268;
          break;
        case 2:
          nowX_6611 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69b8 ^ 0x80000000) - _4622);
          nowY_6614 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69c0 ^ 0x80000000) - _4622);
          break;
        case 3:
          nowX_6611 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69c8 ^ 0x80000000) - _4622);
          nowY_6614 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69d0 ^ 0x80000000) - _4622);
          break;
        case 4:
          nowX_6611 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69d8 ^ 0x80000000) - _4622);
          nowY_6614 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69e0 ^ 0x80000000) - _4622);
          break;
        case 5:
          nowX_6611 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69e8 ^ 0x80000000) - _4622);
          nowY_6614 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69f0 ^ 0x80000000) - _4622);
          break;
        case 6:
          nowX_6611 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69ec ^ 0x80000000) - _4622);
          nowY_6614 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69f4 ^ 0x80000000) - _4622);
          break;
        case 7:
          nowX_6611 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a08 ^ 0x80000000) - _4622);
          nowY_6614 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a10 ^ 0x80000000) - _4622);
          break;
        case 8:
          nowX_6611 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a18 ^ 0x80000000) - _4622);
          nowY_6614 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a20 ^ 0x80000000) - _4622);
          break;
        case 9:
          iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                            getStagInfo)(0x803c9d58);
          if ((*(ushort *)(iVar2 + 10) & 3) == 1) {
            nowX_6611 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a0c ^ 0x80000000) - _4622)
            ;
            nowY_6614 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a14 ^ 0x80000000) - _4622)
            ;
          }
          else {
            iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                              getStagInfo)(0x803c9d58);
            if ((*(ushort *)(iVar2 + 10) & 3) == 0) {
              nowX_6611 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a0c - 10U ^ 0x80000000)
                                 - _4622);
              nowY_6614 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a14 - 3U ^ 0x80000000) -
                                 _4622);
            }
          }
          break;
        case 10:
          nowX_6611 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a18 + 0x2eU ^ 0x80000000) -
                             _4622);
          nowY_6614 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a20 - 0x17U ^ 0x80000000) -
                             _4622);
          break;
        case 0xb:
          nowX_6611 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a18 + 0x2aU ^ 0x80000000) -
                             _4622);
          nowY_6614 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a20 - 3U ^ 0x80000000) -
                             _4622);
        }
        if (moveStatus_6608 == 2) {
          expX_6617 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69bc ^ 0x80000000) - _4622);
          expY_6620 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69c4 ^ 0x80000000) - _4622);
        }
        else {
          expX_6617 = 0_0;
          expY_6620 = 0_0;
        }
      }
    }
  }
  dVar8 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)moveNowFrame_6602,0);
  x = (double)nowX_6611;
  dVar8 = (double)(nowY_6614 + (float)(dVar8 * (double)(_6268 - nowY_6614)));
  if (moveStatus_6608 == 10) {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(param_1 + 0x1d38),(double)(float)((double)_6804 + x),
               (double)(float)((double)_6805 + dVar8));
  }
  else {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x1d38),x,dVar8);
  }
  iVar2 = 0;
  iVar6 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + iVar6 + 0x1e18),x,dVar8);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + iVar6 + 0x1da8),x,dVar8);
    iVar2 = iVar2 + 1;
    iVar6 = iVar6 + 0x38;
  } while (iVar2 < 2);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x2748),x,dVar8);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x2780),x,dVar8);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x27b8),x,dVar8);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x27f0),x,dVar8);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x2908),x,dVar8);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  return;
}


/* __stdcall dMeter_actionAlpha(sub_meter_class *) */

void dMeter_actionAlpha(int param_1)

{
  int iVar1;
  fopAc_ac_c *pfVar2;
  double dVar3;
  undefined2 local_18 [4];
  
  if (init_6815 == '\0') {
    alphaNowFrame_6814 = 0;
    init_6815 = '\x01';
  }
  if ((((*(uint *)(param_1 + 0x3004) & 0x20) == 0) ||
      (iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                         (), (*(ushort *)(iVar1 + 10) & 3) != 0)) ||
     ((cRam803f7071 != '\x02' &&
      ((((cRam803f7071 != '\x03' && (cRam803f7071 != '\a')) && (cRam803f7071 != '\b')) &&
       (cRam803f7071 != '\t')))))) {
    *(byte *)(param_1 + 0x3024) = *(byte *)(param_1 + 0x3024) | 1;
    if (alphaNowFrame_6814 < 5) {
      alphaNowFrame_6814 = alphaNowFrame_6814 + 1;
    }
    else {
      alphaNowFrame_6814 = 5;
    }
  }
  else {
    if (alphaNowFrame_6814 < 4) {
      if (alphaNowFrame_6814 < 3) {
        alphaNowFrame_6814 = alphaNowFrame_6814 + 1;
      }
      else {
        alphaNowFrame_6814 = 3;
      }
    }
    else {
      alphaNowFrame_6814 = alphaNowFrame_6814 + -1;
    }
  }
  dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)alphaNowFrame_6814,0);
  if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda == 8) {
    local_18[0] = 0x78;
    pfVar2 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_18);
    if (pfVar2 != (fopAc_ac_c *)0x0) {
      iVar1 = 10 - (int)pfVar2[4].mTevStr.mLightObj.mDistAtten.y;
      if (iVar1 < 10) {
        dMeter_PaneHide(param_1 + 0x2748);
      }
      else {
        dMeter_PaneShow(param_1 + 0x2748);
        dMeter_numberSet(*(undefined4 *)(param_1 + 0x2748),iVar1 / 10 & 0xff);
      }
      dMeter_PaneShow(param_1 + 0x2780);
      dMeter_numberSet(*(undefined4 *)(param_1 + 0x2780),iVar1 % 10 & 0xff);
    }
  }
  else {
    *(undefined *)(*(int *)(param_1 + 0x2748) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x2780) + 0xaa) = 0;
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0) {
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1d38));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1e50));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1de0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2748));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2780));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x27b8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x27f0));
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1e18),(float)dVar3);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1da8),(float)dVar3);
  }
  else {
    if (((d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0x1a) ||
        (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0x31)) ||
       ((d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0x2d ||
        (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0x2e)))) {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1d38));
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1e50),(float)dVar3);
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1de0),(float)dVar3);
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1e18));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1da8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2748));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2780));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x27b8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x27f0));
    }
    else {
      if (d_com_inf_game::g_dComIfG_gameInfo.mCurrButtonAAction == 0x3d) {
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1d38));
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1e50));
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1de0));
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1e18),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1da8),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2748),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2780),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x27b8),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x27f0),(float)dVar3);
      }
      else {
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1d38),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1e50));
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x1de0));
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1e18),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1da8),(float)dVar3);
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2748));
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2780));
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x27b8));
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x27f0));
      }
    }
  }
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2908),(float)dVar3);
  iVar1 = dMeter_isBit8(param_1 + 0x3026,1);
  if ((iVar1 == 0) || (*(short *)(param_1 + 0x27ee) != 0)) {
    *(undefined *)(*(int *)(param_1 + 0x1d38) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x2748) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x2780) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x27b8) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x27f0) + 0xaa) = 0;
  }
  else {
    *(undefined *)(*(int *)(param_1 + 0x1d38) + 0xaa) = 1;
    *(undefined *)(*(int *)(param_1 + 0x27b8) + 0xaa) = 1;
    *(undefined *)(*(int *)(param_1 + 0x27f0) + 0xaa) = 1;
  }
  return;
}


/* __stdcall dMeter_numberSet(J2DPane *,
                              unsigned char) */

void dMeter_numberSet(J2DPicture *param_1,byte param_2)

{
  if (9 < param_2) {
    param_2 = 0;
  }
  J2DPicture::changeTexture(param_1,(&number_6906)[param_2],0);
  return;
}


/* __stdcall dMeter_numberColor(J2DPane *,
                                unsigned char,
                                unsigned char) */

void dMeter_numberColor(int param_1,char param_2,char param_3)

{
  if (param_2 == '\0') {
    *(undefined *)(param_1 + 0x104) = 0xb4;
    *(undefined *)(param_1 + 0x105) = 0xb4;
    *(undefined *)(param_1 + 0x106) = 0xb4;
    *(undefined *)(param_1 + 0x107) = 0xff;
    *(undefined *)(param_1 + 0x108) = 0x1e;
    *(undefined *)(param_1 + 0x109) = 0x1e;
    *(undefined *)(param_1 + 0x10a) = 0x1e;
    *(undefined *)(param_1 + 0x10b) = 0;
  }
  else {
    if (param_2 == param_3) {
      *(undefined *)(param_1 + 0x104) = 0xff;
      *(undefined *)(param_1 + 0x105) = 200;
      *(undefined *)(param_1 + 0x106) = 0x32;
      *(undefined *)(param_1 + 0x107) = 0xff;
      *(undefined *)(param_1 + 0x108) = 0x1e;
      *(undefined *)(param_1 + 0x109) = 0x1e;
      *(undefined *)(param_1 + 0x10a) = 0x1e;
      *(undefined *)(param_1 + 0x10b) = 0;
    }
    else {
      *(undefined *)(param_1 + 0x104) = 0xff;
      *(undefined *)(param_1 + 0x105) = 0xff;
      *(undefined *)(param_1 + 0x106) = 0xff;
      *(undefined *)(param_1 + 0x107) = 0xff;
      *(undefined *)(param_1 + 0x108) = 0;
      *(undefined *)(param_1 + 0x109) = 0;
      *(undefined *)(param_1 + 0x10a) = 0;
      *(undefined *)(param_1 + 0x10b) = 0;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall dMeter_xyInit(sub_meter_class *) */

void dMeter_xyInit(int param_1)

{
  dItem_data__ItemNo dVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  *(undefined2 *)(param_1 + 0x2586) = 0;
  *(undefined4 *)(param_1 + 0x2f2c) = 0;
  *(undefined4 *)(param_1 + 0x2f30) = 0;
  iVar5 = 0;
  pbVar3 = &dMenu_baitNum;
  iVar6 = 8;
  do {
    *pbVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem)[1].field_0x0
              [iVar5 + 0x16];
    iVar5 = iVar5 + 1;
    pbVar3 = pbVar3 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar5 = 0;
  do {
    pbVar3 = (byte *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                      mInventorySlotIndexOnButton + iVar5);
    uVar4 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                        mInventorySlotIndexOnButton[iVar5];
    if (uVar4 == 0xff) {
      d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar5] = InvalidItem;
    }
    else {
      if (uVar4 < 0x15) {
        dVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar4];
      }
      else {
        if (uVar4 < 0x18) {
          dVar1 = InvalidItem;
        }
        else {
          if (uVar4 < 0x20) {
            dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar4 + 0xd];
          }
          else {
            if (uVar4 < 0x24) {
              dVar1 = InvalidItem;
            }
            else {
              if (uVar4 < 0x2c) {
                dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar4 + 9];
              }
              else {
                if (uVar4 < 0x30) {
                  dVar1 = InvalidItem;
                }
                else {
                  if (uVar4 < 0x38) {
                    dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar4 + 5];
                  }
                  else {
                    dVar1 = InvalidItem;
                  }
                }
              }
            }
          }
        }
      }
      d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar5] = dVar1;
      uVar4 = (uint)*pbVar3;
      if (uVar4 < 0x15) {
        bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar4];
      }
      else {
        if (uVar4 < 0x18) {
          bVar2 = 0xff;
        }
        else {
          if (uVar4 < 0x20) {
            bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar4 + 0xd];
          }
          else {
            if (uVar4 < 0x24) {
              bVar2 = 0xff;
            }
            else {
              if (uVar4 < 0x2c) {
                bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar4 + 9];
              }
              else {
                if (uVar4 < 0x30) {
                  bVar2 = 0xff;
                }
                else {
                  if (uVar4 < 0x38) {
                    bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar4 + 5];
                  }
                  else {
                    bVar2 = 0xff;
                  }
                }
              }
            }
          }
        }
      }
      if (bVar2 == 0xff) {
        *pbVar3 = 0xff;
      }
    }
    *(dItem_data__ItemNo *)(param_1 + iVar5 + 0x3021) =
         d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar5];
    dMeter_xyItemChange(param_1,iVar5);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __stdcall dMeter_xyMove(sub_meter_class *) */

void dMeter_xyMove(int param_1)

{
  dItem_data__ItemNo dVar1;
  bool bVar2;
  int iVar3;
  JPABaseEmitter *pJVar4;
  int iVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  cXyz local_38;
  
  bVar6 = true;
  bVar2 = false;
  iVar11 = 0;
  iVar9 = 0;
  do {
    if (*(dItem_data__ItemNo *)(param_1 + iVar11 + 0x3021) !=
        d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar11]) {
      dMeter_xyItemChange(param_1,iVar11);
      bVar6 = false;
      dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar11];
      if ((dVar1 != FireAndIceArrows) && (dVar1 != LightArrow)) {
        iVar5 = param_1 + iVar9;
        *(undefined *)(*(int *)(iVar5 + 0x2320) + 0xaa) = 0;
        *(undefined *)(*(int *)(iVar5 + 0x23c8) + 0xaa) = 0;
        *(undefined *)(*(int *)(iVar5 + 0x2470) + 0xaa) = 0;
        *(undefined2 *)(iVar5 + 0x2356) = 0;
      }
      *(dItem_data__ItemNo *)(param_1 + iVar11 + 0x3021) =
           d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar11];
    }
    iVar11 = iVar11 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar11 < 3);
  if (bVar6) {
    dMeter_xyItemCountUp(param_1);
  }
  dMeter_xyTrans(param_1);
  iVar11 = 0;
  iVar9 = 0;
  do {
    dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar11];
    if ((dVar1 == FireAndIceArrows) || (dVar1 == LightArrow)) {
      dMeter_xyBowLightAnime(param_1,iVar11);
    }
    else {
      if (dVar1 == ForestWater) {
        bVar2 = true;
        iVar5 = param_1 + iVar9;
        local_38.y = *(float *)(iVar5 + 0x20a0) - _7213;
        local_38.x = *(float *)(iVar5 + 0x209c) - _7214;
        local_38.z = 0_0;
        iVar10 = 0;
        iVar7 = 0;
        do {
          iVar8 = iVar7 + 0x2f2c;
          iVar3 = *(int *)(param_1 + iVar8);
          if (iVar3 == 0) {
            pJVar4 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,9,
                                        0x2d,&local_38,(csXyz *)0x0,(cXyz *)0x0,0xff,
                                        (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0
                                        ,(cXyz *)0x0);
            *(JPABaseEmitter **)(param_1 + iVar8) = pJVar4;
          }
          else {
            *(float *)(iVar3 + 0x1e4) = local_38.x;
            *(float *)(iVar3 + 0x1e8) = local_38.y;
            *(float *)(iVar3 + 0x1ec) = local_38.z;
            *(uint *)(*(int *)(param_1 + iVar8) + 0x20c) =
                 *(uint *)(*(int *)(param_1 + iVar8) + 0x20c) & 0xfffffffb;
            *(undefined *)(*(int *)(param_1 + iVar8) + 0x1ff) = *(undefined *)(iVar5 + 0x20b5);
          }
          iVar10 = iVar10 + 1;
          iVar7 = iVar7 + 4;
        } while (iVar10 < 2);
      }
    }
    iVar11 = iVar11 + 1;
    iVar9 = iVar9 + 0x38;
  } while (iVar11 < 3);
  if (!bVar2) {
    iVar9 = 0;
    iVar11 = 2;
    do {
      iVar7 = iVar9 + 0x2f2c;
      iVar5 = *(int *)(param_1 + iVar7);
      if (iVar5 != 0) {
        *(undefined4 *)(iVar5 + 0x60) = 0xffffffff;
        *(uint *)(iVar5 + 0x20c) = *(uint *)(iVar5 + 0x20c) | 1;
        *(uint *)(*(int *)(param_1 + iVar7) + 0x20c) =
             *(uint *)(*(int *)(param_1 + iVar7) + 0x20c) & 0xffffffbf;
        *(undefined4 *)(param_1 + iVar7) = 0;
      }
      iVar9 = iVar9 + 4;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
  }
  dMeter_xyAlpha(param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dMeter_xyDraw(sub_meter_class *) */

void dMeter_xyDraw(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 0;
  do {
    iVar2 = param_1 + iVar3;
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x1fd8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x1f30));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x2080));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x2128));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x2320));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x23c8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x2470));
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 3);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x2518));
  iVar1 = 0;
  iVar3 = 0;
  do {
    iVar2 = param_1 + iVar3;
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x2550));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x25c0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x2630));
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 2);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __stdcall dMeter_xyEquipItem(int) */

undefined4 dMeter_xyEquipItem(int param_1)

{
  uint uVar1;
  byte bVar2;
  undefined4 uVar3;
  
  uVar1 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                      mInventorySlotIndexOnButton[param_1];
  if (uVar1 < 0x15) {
    bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
            [uVar1];
  }
  else {
    if (uVar1 < 0x18) {
      bVar2 = 0xff;
    }
    else {
      if (uVar1 < 0x20) {
        bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar1 + 0xd]
        ;
      }
      else {
        if (uVar1 < 0x24) {
          bVar2 = 0xff;
        }
        else {
          if (uVar1 < 0x2c) {
            bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar1 + 9];
          }
          else {
            if (uVar1 < 0x30) {
              bVar2 = 0xff;
            }
            else {
              if (uVar1 < 0x38) {
                bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar1 + 5];
              }
              else {
                bVar2 = 0xff;
              }
            }
          }
        }
      }
    }
  }
  uVar3 = 0;
  if (bVar2 == 0x47) {
    uVar3 = 2;
  }
  else {
    if (bVar2 < 0x47) {
      if (bVar2 == 0x45) {
        uVar3 = 0;
      }
      else {
        if (bVar2 < 0x45) {
          if (bVar2 == 0x1f) {
            uVar3 = 7;
          }
        }
        else {
          uVar3 = 1;
        }
      }
    }
    else {
      if (bVar2 == 0x4a) {
        uVar3 = 5;
      }
      else {
        if (bVar2 < 0x4a) {
          if (bVar2 < 0x49) {
            uVar3 = 3;
          }
          else {
            uVar3 = 4;
          }
        }
        else {
          if (bVar2 < 0x4c) {
            uVar3 = 6;
          }
        }
      }
    }
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall dMeter_xyItemNumberSet(sub_meter_class *,
                                    int) */

void dMeter_xyItemNumberSet(int param_1,int param_2)

{
  dItem_data__ItemNo dVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[param_2];
  if ((dVar1 == PictoBox) || (dVar1 == DeluxePictoBox)) {
    iVar7 = param_1 + param_2 * 0x38;
    dMeter_PaneHide(iVar7 + 0x1f30);
    dMeter_PaneShow(iVar7 + 0x1fd8);
    param_1 = param_1 + param_2 * 0x38;
    dMeter_numberSet(*(undefined4 *)(param_1 + 0x1fd8),
                     d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_);
    dMeter_numberColor(*(undefined4 *)(param_1 + 0x1fd8),
                       d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_,3)
    ;
  }
  else {
    if ((dVar1 == HerosBow) || ((dVar1 == FireAndIceArrows || (dVar1 == LightArrow)))) {
      iVar7 = param_1 + param_2 * 0x38;
      dMeter_PaneShow(iVar7 + 0x1f30);
      dMeter_PaneShow(iVar7 + 0x1fd8);
      if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ < 10) {
        dMeter_PaneHide(iVar7 + 0x1f30);
      }
      else {
        dMeter_numberSet(*(undefined4 *)(iVar7 + 0x1f30),
                         d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_
                         / 10);
        dMeter_numberColor(*(undefined4 *)(iVar7 + 0x1f30),
                           d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.
                           _3_1_,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.
                                 field_0x1);
      }
      param_1 = param_1 + param_2 * 0x38;
      dMeter_numberSet(*(undefined4 *)(param_1 + 0x1fd8),
                       (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.
                             _3_1_ % 10);
      dMeter_numberColor(*(undefined4 *)(param_1 + 0x1fd8),
                         d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_,
                         d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1
                        );
    }
    else {
      if (dVar1 == Bombs) {
        iVar7 = param_1 + param_2 * 0x38;
        dMeter_PaneShow(iVar7 + 0x1f30);
        dMeter_PaneShow(iVar7 + 0x1fd8);
        if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ < 10) {
          dMeter_PaneHide(iVar7 + 0x1f30);
        }
        else {
          dMeter_numberSet(*(undefined4 *)(iVar7 + 0x1f30),
                           d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.
                           _4_1_ / 10);
          dMeter_numberColor(*(undefined4 *)(iVar7 + 0x1f30),
                             d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.
                             _4_1_,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax
                                   .field_0x2);
        }
        param_1 = param_1 + param_2 * 0x38;
        dMeter_numberSet(*(undefined4 *)(param_1 + 0x1fd8),
                         (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.
                               _4_1_ % 10);
        dMeter_numberColor(*(undefined4 *)(param_1 + 0x1fd8),
                           d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.
                           _4_1_,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.
                                 field_0x2);
      }
      else {
        bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                mInventorySlotIndexOnButton[param_2];
        pbVar4 = (byte *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                          mInventorySlotIndexOnButton + param_2);
        if ((bVar2 < 0x18) || (0x1f < bVar2)) {
          if ((bVar2 < 0x24) || (0x2b < bVar2)) {
            param_1 = param_1 + param_2 * 0x38;
            dMeter_PaneHide(param_1 + 0x1f30);
            dMeter_PaneHide(param_1 + 0x1fd8);
          }
          else {
            if (dVar1 == HyoiPear) {
              param_1 = param_1 + param_2 * 0x38;
              dMeter_PaneHide(param_1 + 0x1f30);
              dMeter_PaneHide(param_1 + 0x1fd8);
            }
            else {
              iVar7 = param_1 + param_2 * 0x38;
              dMeter_PaneHide(iVar7 + 0x1f30);
              dMeter_PaneShow(iVar7 + 0x1fd8);
              param_1 = param_1 + param_2 * 0x38;
              dMeter_numberSet(*(undefined4 *)(param_1 + 0x1fd8),
                               d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.
                               field_0x0[*pbVar4 + 10]);
              dMeter_numberColor(*(undefined4 *)(param_1 + 0x1fd8),
                                 d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.
                                 field_0x0[*pbVar4 + 10],3);
            }
          }
        }
        else {
          iVar6 = param_2 * 0x38;
          iVar5 = param_1 + iVar6 + 0x1f30;
          dMeter_PaneShow(iVar5);
          dMeter_PaneShow(param_1 + iVar6 + 0x1fd8);
          iVar7 = dMeter_xyEquipItem(param_2);
          uVar3 = (uint)(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem)[1].
                        field_0x0[iVar7 + 0xe];
          if (uVar3 < 10) {
            dMeter_PaneHide(iVar5);
          }
          else {
            dMeter_numberSet(*(undefined4 *)(param_1 + iVar6 + 0x1f30),uVar3 / 10);
            dMeter_numberColor(*(undefined4 *)(param_1 + iVar6 + 0x1f30),
                               (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem)
                               [1].field_0x0[iVar7 + 0xe],99);
          }
          dMeter_numberSet(*(undefined4 *)(param_1 + iVar6 + 0x1fd8),
                           (uint)(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem
                                 )[1].field_0x0[iVar7 + 0xe] % 10);
          dMeter_numberColor(*(undefined4 *)(param_1 + iVar6 + 0x1fd8),
                             (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem)[1]
                             .field_0x0[iVar7 + 0xe],99);
        }
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801f58bc) */
/* WARNING: Removing unreachable block (ram,0x801f58c4) */
/* __stdcall dMeter_xyBowLightAnime(sub_meter_class *,
                                    int) */

void dMeter_xyBowLightAnime(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  longlong lVar6;
  double local_40;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  *(short *)(param_1 + 0x2356) = *(short *)(param_1 + 0x2356) + 1;
  param_2 = param_2 * 0x38;
  iVar1 = param_1 + param_2;
  if (0x77 < *(short *)(iVar1 + 0x2356)) {
    *(undefined2 *)(iVar1 + 0x2356) = 0;
  }
  iVar1 = (int)*(short *)(iVar1 + 0x2356);
  if (iVar1 < 0x3c) {
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x3c,iVar1,0);
  }
  else {
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x3c,0x78 - iVar1,0);
  }
  dVar5 = (double)(1_0 - (float)((double)_7625 * dVar4));
  local_40 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2354));
  iVar1 = 0;
  iVar2 = 0;
  lVar6 = (longlong)
          (int)((float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2354)) - _4620) -
               (float)((double)((float)(local_40 - _4620) - _7626) * dVar4));
  do {
    f_op_msg_mng::fopMsgM_paneScaleXY
              ((fopMsgM_pane_class *)(param_1 + iVar2 + param_2 + 0x2320),(float)dVar5);
    *(char *)(param_1 + param_2 + iVar2 + 0x2355) = (char)lVar6;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0xa8;
  } while (iVar1 < 3);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall dMeter_xyItemCountUp(sub_meter_class *) */

void dMeter_xyItemCountUp(int param_1)

{
  dItem_data__ItemNo dVar1;
  byte bVar2;
  bool bVar3;
  short sVar4;
  ushort uVar5;
  bool bVar6;
  dItem_data__ItemNo dVar7;
  uchar uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  dSv_player_bag_item_record_c *pdVar13;
  int iVar14;
  
  bVar3 = false;
  if (init_7633 == '\0') {
    arrowMax_7632 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1;
    init_7633 = '\x01';
  }
  if (init_7636 == '\0') {
    bombMax_7635 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2;
    init_7636 = '\x01';
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay._18654_2_ != 0) {
    sVar4 = (ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ +
            d_com_inf_game::g_dComIfG_gameInfo.mPlay._18654_2_;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay._18654_2_ = 0;
    if (sVar4 < 0) {
      sVar4 = 0;
    }
    if (3 < sVar4) {
      sVar4 = 3;
    }
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ = (byte)sVar4;
    bVar3 = true;
  }
  bVar6 = d_com_inf_game::dComIfGs_checkGetItem(HerosBow);
  if (bVar6 == false) {
    bVar6 = d_com_inf_game::dComIfGs_checkGetItem(FireAndIceArrows);
    if ((bVar6 != false) ||
       (bVar6 = d_com_inf_game::dComIfGs_checkGetItem(LightArrow), bVar6 != false))
    goto LAB_801f59c0;
LAB_801f59d4:
    if (arrowMax_7632 != d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1
       ) goto LAB_801f59ec;
  }
  else {
LAB_801f59c0:
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48e0 == 0) goto LAB_801f59d4;
LAB_801f59ec:
    if (DAT_803e696a != '\0') {
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48e0 = 0;
    }
    uVar5 = (ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ +
            d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48e0;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48e0 = 0;
    if ((short)uVar5 < 0) {
      uVar5 = 0;
    }
    if ((short)(ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1 <
        (short)uVar5) {
      uVar5 = (ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1;
    }
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ = (byte)uVar5;
    arrowMax_7632 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1;
    bVar3 = true;
  }
  bVar6 = d_com_inf_game::dComIfGs_checkGetItem(Bombs);
  if ((bVar6 == false) || (d_com_inf_game::g_dComIfG_gameInfo.mPlay._18660_2_ == 0)) {
    if (bombMax_7635 == d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2)
    goto LAB_801f5b18;
  }
  if (DAT_803e696b != '\0') {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay._18660_2_ = 0;
  }
  uVar5 = (ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ +
          d_com_inf_game::g_dComIfG_gameInfo.mPlay._18660_2_;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18660_2_ = 0;
  if ((short)uVar5 < 0) {
    uVar5 = 0;
  }
  if ((short)(ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2 <
      (short)uVar5) {
    uVar5 = (ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2;
  }
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ = (byte)uVar5;
  bombMax_7635 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2;
  bVar3 = true;
LAB_801f5b18:
  iVar14 = 0;
  iVar12 = 0;
  pdVar13 = &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord;
  do {
    if (*(short *)(d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems + iVar12 + -0x4b) != 0) {
      sVar4 = (ushort)*(byte *)pdVar13 +
              *(short *)(d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems + iVar12 + -0x4b);
      iVar11 = 0;
      *(undefined2 *)(d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems + iVar12 + -0x4b) = 0;
      if (sVar4 < 1) {
        *(byte *)pdVar13 = 0;
        iVar9 = 0;
        do {
          dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar9];
          dVar7 = f_op_msg_mng::fopMsgM_itemNumIdx(iVar14 + 0x18U & 0xff);
          if (dVar1 == dVar7) {
            iVar10 = param_1 + iVar11;
            dMeter_PaneHide(iVar10 + 0x2080);
            dMeter_PaneHide(iVar10 + 0x2128);
            dMeter_PaneHide(iVar10 + 0x1f30);
            dMeter_PaneHide(iVar10 + 0x1fd8);
          }
          iVar9 = iVar9 + 1;
          iVar11 = iVar11 + 0x38;
        } while (iVar9 < 3);
        uVar8 = f_op_msg_mng::fopMsgM_itemNumIdx(iVar14 + 0x18U & 0xff);
        dSv_player_bag_item_c::setBeastItemEmpty
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,uVar8);
        bVar3 = true;
      }
      else {
        if (99 < sVar4) {
          sVar4 = 99;
        }
        *(byte *)pdVar13 = (byte)sVar4;
        bVar3 = true;
      }
    }
    bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem)[1].field_0x0
            [iVar14 + 0x16];
    if ((&dMenu_baitNum)[iVar14] != bVar2) {
      (&dMenu_baitNum)[iVar14] = bVar2;
      bVar3 = true;
    }
    iVar14 = iVar14 + 1;
    pdVar13 = (dSv_player_bag_item_record_c *)&pdVar13->field_0x1;
    iVar12 = iVar12 + 2;
  } while (iVar14 < 8);
  iVar12 = 0;
  iVar14 = 3;
  do {
    if (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar12] == AllPurposeBait) {
      bVar3 = true;
    }
    iVar12 = iVar12 + 1;
    iVar14 = iVar14 + -1;
  } while (iVar14 != 0);
  if (bVar3) {
    iVar12 = 0;
    do {
      dMeter_xyItemNumberSet(param_1,iVar12);
      iVar12 = iVar12 + 1;
    } while (iVar12 < 3);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall dMeter_xyItemChange(sub_meter_class *,
                                 int) */

void dMeter_xyItemChange(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  dItem_data__ItemNo *pdVar3;
  int iVar4;
  int iVar5;
  
  pdVar3 = d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems + param_2;
  if (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[param_2] == InvalidItem) {
    iVar4 = param_1 + param_2 * 0x38;
    dMeter_PaneHide(iVar4 + 0x2080);
    dMeter_PaneHide(iVar4 + 0x2128);
  }
  else {
    bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
            mInventorySlotIndexOnButton[param_2];
    if (bVar1 < 0x30) {
      if (bVar1 < 0x24) {
        if (bVar1 < 0x18) {
          iVar5 = param_2 * 0x38;
          iVar4 = param_1 + iVar5;
          dMeter_PaneShow(iVar4 + 0x2080);
          dMeter_PaneShow(iVar4 + 0x2128);
          uVar2 = (uint)*pdVar3;
          if (uVar2 == 0x35) {
            *(undefined *)(*(int *)(iVar4 + 0x2320) + 0xaa) = 1;
            *(undefined *)(*(int *)(iVar4 + 0x23c8) + 0xaa) = 1;
            *(undefined *)(*(int *)(iVar4 + 0x2470) + 0xaa) = 0;
            uVar2 = 0x27;
          }
          else {
            if (uVar2 == 0x36) {
              *(undefined *)(*(int *)(iVar4 + 0x2320) + 0xaa) = 1;
              *(undefined *)(*(int *)(iVar4 + 0x23c8) + 0xaa) = 1;
              *(undefined *)(*(int *)(iVar4 + 0x2470) + 0xaa) = 1;
              uVar2 = 0x27;
            }
          }
          if ((uVar2 == 0x35) || (uVar2 == 0x36)) {
            uVar2 = 0x27;
          }
          iVar4 = param_1 + param_2 * 4;
          JKRArchive::readTypeResource
                    (*(void **)(iVar4 + 0x2f48),0xc00,0x54494d47,
                     dItem_data::item_resource[uVar2].mIconFilename,
                     d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
          os::DCStoreRangeNoSync(*(undefined4 *)(iVar4 + 0x2f48),0xc00);
          J2DPicture::changeTexture
                    (*(J2DPicture **)(param_1 + iVar5 + 0x2080),*(ResTIMG **)(iVar4 + 0x2f48),'\0');
          J2DPicture::changeTexture
                    (*(J2DPicture **)(param_1 + iVar5 + 0x2128),*(ResTIMG **)(iVar4 + 0x2f48),'\0');
        }
        else {
          iVar5 = param_2 * 0x38;
          dMeter_PaneShow(param_1 + iVar5 + 0x2080);
          dMeter_PaneShow(param_1 + iVar5 + 0x2128);
          iVar4 = param_1 + param_2 * 4;
          JKRArchive::readTypeResource
                    (*(void **)(iVar4 + 0x2f48),0xc00,0x54494d47,
                     dItem_data::item_resource[*pdVar3].mIconFilename,
                     d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
          os::DCStoreRangeNoSync(*(undefined4 *)(iVar4 + 0x2f48),0xc00);
          J2DPicture::changeTexture
                    (*(J2DPicture **)(param_1 + iVar5 + 0x2080),*(ResTIMG **)(iVar4 + 0x2f48),'\0');
          J2DPicture::changeTexture
                    (*(J2DPicture **)(param_1 + iVar5 + 0x2128),*(ResTIMG **)(iVar4 + 0x2f48),'\0');
        }
      }
      else {
        iVar5 = param_2 * 0x38;
        dMeter_PaneShow(param_1 + iVar5 + 0x2080);
        dMeter_PaneShow(param_1 + iVar5 + 0x2128);
        iVar4 = param_1 + param_2 * 4;
        JKRArchive::readTypeResource
                  (*(void **)(iVar4 + 0x2f48),0xc00,0x54494d47,
                   dItem_data::item_resource[*pdVar3].mIconFilename,
                   d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
        os::DCStoreRangeNoSync(*(undefined4 *)(iVar4 + 0x2f48),0xc00);
        J2DPicture::changeTexture
                  (*(J2DPicture **)(param_1 + iVar5 + 0x2080),*(ResTIMG **)(iVar4 + 0x2f48),'\0');
        J2DPicture::changeTexture
                  (*(J2DPicture **)(param_1 + iVar5 + 0x2128),*(ResTIMG **)(iVar4 + 0x2f48),'\0');
      }
    }
    else {
      iVar5 = param_1 + param_2 * 0x38;
      dMeter_PaneShow(iVar5 + 0x2080);
      dMeter_PaneShow(iVar5 + 0x2128);
      iVar4 = param_1 + param_2 * 4;
      JKRArchive::readTypeResource
                (*(void **)(iVar4 + 0x2f48),0xc00,0x54494d47,
                 dItem_data::item_resource[*pdVar3].mIconFilename,
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
      os::DCStoreRangeNoSync(*(undefined4 *)(iVar4 + 0x2f48),0xc00);
      J2DPicture::changeTexture(*(J2DPicture **)(iVar5 + 0x2080),*(ResTIMG **)(iVar4 + 0x2f48),'\0')
      ;
      J2DPicture::changeTexture(*(J2DPicture **)(iVar5 + 0x2128),*(ResTIMG **)(iVar4 + 0x2f48),'\0')
      ;
    }
  }
  dMeter_xyItemNumberSet(param_1,param_2);
  return;
}


/* __stdcall dMeter_xyRotateZ(fopMsgM_pane_class *,
                              float,
                              float) */

void dMeter_xyRotateZ(double param_1,double param_2,int **param_3)

{
  float fVar1;
  double dVar2;
  int *piVar3;
  
  dVar2 = _4622;
  fVar1 = _4664 * (float)param_3[0xc];
  piVar3 = *param_3;
  piVar3[0x27] = (int)(float)((double)CONCAT44(0x43300000,
                                               (int)(_4664 * (float)param_3[0xb]) ^ 0x80000000) -
                             _4622);
  piVar3[0x28] = (int)(float)((double)CONCAT44(0x43300000,(int)fVar1 ^ 0x80000000) - dVar2);
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)(param_1 + param_2);
  (**(code **)(*piVar3 + 0x20))(piVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328ea8 */
/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328ef4 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall dMeter_xyAlpha(sub_meter_class *) */

void dMeter_xyAlpha(int param_1)

{
  bool bVar1;
  dItem_data__ItemNo dVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  
  uVar6 = *(uint *)(param_1 + 0x3004);
  if ((uVar6 & 0x4000) == 0) {
    if ((uVar6 & 0x40) != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.field_0xd6 & 1;
      }
      if (uVar4 != 0) goto LAB_801f67c0;
    }
    if (((((((uVar6 & 0x100) == 0) && ((uVar6 & 0x10) == 0)) && ((uVar6 & 0x800000) == 0)) &&
         (((uVar6 & 0x20) == 0 ||
          (iVar5 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                             getStagInfo)(), (*(ushort *)(iVar5 + 10) & 3) != 1)))) &&
        ((uVar6 = *(uint *)(param_1 + 0x3004), (uVar6 & 0x80) == 0 &&
         (((uVar6 & 0x100000) == 0 && ((uVar6 & 0x200000) == 0)))))) &&
       (((uVar6 & 0x20000) == 0 &&
        ((((uVar6 & 0x40000) == 0 && ((uVar6 & 0x80000) == 0)) && ((uVar6 & 0x400000) == 0)))))) {
      bVar1 = (uVar6 & 8) != 0;
      if (bVar1) {
        iVar5 = 0;
        iVar8 = 3;
        do {
          if (*(short *)((int)&alphaNowFrame_8034 + iVar5) < 5) {
            *(short *)((int)&alphaNowFrame_8034 + iVar5) =
                 *(short *)((int)&alphaNowFrame_8034 + iVar5) + 1;
          }
          else {
            *(undefined2 *)((int)&alphaNowFrame_8034 + iVar5) = 5;
          }
          iVar5 = iVar5 + 2;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      else {
        if ((bVar1) ||
           ((((uVar6 & 0x800) == 0 && ((uVar6 & 0x2000) == 0)) &&
            (((uVar6 & 0x8000) == 0 && (((uVar6 & 0x200) == 0 && ((uVar6 & 0x10000) == 0)))))))) {
          if (((uVar6 & 0x20) == 0) ||
             (iVar5 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                                getStagInfo)(), (*(ushort *)(iVar5 + 10) & 3) != 0)) {
            iVar8 = 0;
            iVar5 = 0;
            do {
              uVar6 = *(uint *)(param_1 + 0x3004);
              if ((((((uVar6 & 0x1000) == 0) ||
                    (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar8] == GrapplingHook)) &&
                   ((((uVar6 & 0x80) == 0 ||
                     (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar8] == Telescope)) &&
                    ((uVar6 & 0x20000) == 0)))) &&
                  ((((((((uVar6 & 0x400) == 0 ||
                        (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda == 1)) ||
                       (dVar2 = d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar8],
                       dVar2 == normal_sail)) ||
                      (((dVar2 == Telescope || (dVar2 == WindWaker)) ||
                       ((dVar2 == GrapplingHook || ((dVar2 == Boomerang || (dVar2 == TingleTuner))))
                       )))) || (dVar2 == PictoBox)) ||
                    ((((((dVar2 == DeluxePictoBox || (dVar2 == MagicArmor)) || (dVar2 == BaitBag))
                       || ((dVar2 == HyoiPear || (dVar2 == AllPurposeBait)))) || (dVar2 == HerosBow)
                      ) || ((dVar2 == FireAndIceArrows || (dVar2 == LightArrow)))))) ||
                   (((dVar2 == Bombs ||
                     (((dVar2 == Hookshot || (dVar2 == EmptyBottle)) || (dVar2 == RedPotion)))) ||
                    (((dVar2 == GreenPotion || (dVar2 == BluePotion)) ||
                     ((dVar2 == HalfSoup ||
                      (((dVar2 == Soup || (dVar2 == BottledWater)) ||
                       ((dVar2 == BottledFairy ||
                        ((dVar2 == BottledFirefly || (dVar2 == ForestWater)))))))))))))))) &&
                 (((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda != 1 ||
                   ((d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar8] == normal_sail ||
                    (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar8] == Telescope)))) &&
                  ((iVar7 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                                      getStagInfo)(0x803c9d58),
                   (*(uint *)(iVar7 + 0xc) >> 0x10 & 7) != 3 ||
                   (((((iVar7 = MSL_C.PPCEABI.bare.H::strcmp
                                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.
                                           mStageName,"Xboss0"), iVar7 != 0 &&
                       (iVar7 = MSL_C.PPCEABI.bare.H::strcmp
                                          (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.
                                           mStageName,"Xboss1"), iVar7 != 0)) &&
                      (iVar7 = MSL_C.PPCEABI.bare.H::strcmp
                                         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.
                                          mStageName,"Xboss2"), iVar7 != 0)) &&
                     (iVar7 = MSL_C.PPCEABI.bare.H::strcmp
                                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.
                                         mStageName,"Xboss3"), iVar7 != 0)) ||
                    (((dVar2 = d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar8],
                      dVar2 != BottledWater && (dVar2 != BottledFirefly)) && (dVar2 != ForestWater))
                    )))))))) {
                if ((*(uint *)(param_1 + 0x3004) & 2) != 0) {
                  if ((((((d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar8] != TingleTuner)
                         && ((d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar8] != WindWaker
                             || (iVar7 = MSL_C.PPCEABI.bare.H::strcmp
                                                   (d_com_inf_game::g_dComIfG_gameInfo.mPlay.
                                                    mCurStage.mStageName,"Otkura"), iVar7 != 0))))
                        && ((d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar8] !=
                             GrapplingHook ||
                            (iVar7 = MSL_C.PPCEABI.bare.H::strcmp
                                               (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.
                                                mStageName,"Abesso"), iVar7 != 0)))) &&
                       (((((dVar2 = d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar8],
                           dVar2 != PictoBox && (dVar2 != DeluxePictoBox)) && (dVar2 != SpoilsBag))
                         && ((dVar2 != SkullNecklace && (dVar2 != BokoBabaSeed)))) &&
                        (((dVar2 != GoldenFeather &&
                          ((dVar2 != KnightsCrest && (dVar2 != RedChuJelly)))) &&
                         (dVar2 != GreenChuJelly)))))) &&
                      (((((((dVar2 != BlueChuJelly && (dVar2 != JoyPendant)) && (dVar2 != BaitBag))
                          && ((dVar2 != AllPurposeBait && (dVar2 != HyoiPear)))) &&
                         ((dVar2 != EmptyBottle && ((dVar2 != RedPotion && (dVar2 != GreenPotion))))
                         )) && (dVar2 != BluePotion)) &&
                       (((dVar2 != HalfSoup && (dVar2 != Soup)) && (dVar2 != BottledWater)))))) &&
                     (((((dVar2 != BottledFairy && (dVar2 != BottledFirefly)) &&
                        ((dVar2 != ForestWater && ((dVar2 != DeliveryBag && (dVar2 != flower_1))))))
                       && (((dVar2 != flower_2 &&
                            ((((((dVar2 != flower_3 && (dVar2 != heros_flag)) &&
                                (dVar2 != tairyo_flag)) &&
                               ((dVar2 != sales_flag && (dVar2 != wind_flag)))) &&
                              ((dVar2 != red_flag &&
                               ((dVar2 != fossil_head && (dVar2 != water_statue)))))) &&
                             (dVar2 != postman_statue)))) &&
                           (((dVar2 != president_statue && (dVar2 != letter00)) &&
                            (dVar2 != magic_seed)))))) &&
                      (((dVar2 != maggies_letter && (dVar2 != mo_letter)) &&
                       ((dVar2 != cabana_deed &&
                        ((dVar2 != kaisen_present1 && (dVar2 != kaisen_present2))))))))))
                  goto LAB_801f6704;
                }
                if (*(short *)((int)&alphaNowFrame_8034 + iVar5) < 5) {
                  *(short *)((int)&alphaNowFrame_8034 + iVar5) =
                       *(short *)((int)&alphaNowFrame_8034 + iVar5) + 1;
                }
                else {
                  *(undefined2 *)((int)&alphaNowFrame_8034 + iVar5) = 5;
                }
                if (iVar8 == 1) {
                  *(byte *)(param_1 + 0x3024) = *(byte *)(param_1 + 0x3024) | 8;
                }
                else {
                  if (iVar8 < 1) {
                    if (-1 < iVar8) {
                      *(byte *)(param_1 + 0x3024) = *(byte *)(param_1 + 0x3024) | 4;
                    }
                  }
                  else {
                    if (iVar8 < 3) {
                      *(byte *)(param_1 + 0x3024) = *(byte *)(param_1 + 0x3024) | 0x20;
                    }
                  }
                }
              }
              else {
LAB_801f6704:
                sVar3 = *(short *)((int)&alphaNowFrame_8034 + iVar5);
                if (sVar3 < 4) {
                  if (sVar3 < 3) {
                    *(short *)((int)&alphaNowFrame_8034 + iVar5) = sVar3 + 1;
                  }
                  else {
                    *(undefined2 *)((int)&alphaNowFrame_8034 + iVar5) = 3;
                  }
                }
                else {
                  *(short *)((int)&alphaNowFrame_8034 + iVar5) = sVar3 + -1;
                }
              }
              iVar8 = iVar8 + 1;
              iVar5 = iVar5 + 2;
            } while (iVar8 < 3);
          }
          else {
            iVar8 = 0;
            iVar5 = 0;
            iVar7 = 3;
            do {
              if (iVar8 == 1) {
                if (*(short *)((int)&alphaNowFrame_8034 + iVar5) < 5) {
                  *(short *)((int)&alphaNowFrame_8034 + iVar5) =
                       *(short *)((int)&alphaNowFrame_8034 + iVar5) + 1;
                }
                else {
                  *(undefined2 *)((int)&alphaNowFrame_8034 + iVar5) = 5;
                }
              }
              else {
                if (*(short *)((int)&alphaNowFrame_8034 + iVar5) < 1) {
                  *(undefined2 *)((int)&alphaNowFrame_8034 + iVar5) = 0;
                }
                else {
                  *(short *)((int)&alphaNowFrame_8034 + iVar5) =
                       *(short *)((int)&alphaNowFrame_8034 + iVar5) + -1;
                }
              }
              iVar8 = iVar8 + 1;
              iVar5 = iVar5 + 2;
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
        }
        else {
          iVar5 = 0;
          iVar8 = 3;
          do {
            sVar3 = *(short *)((int)&alphaNowFrame_8034 + iVar5);
            if (sVar3 < 4) {
              if (sVar3 < 3) {
                *(short *)((int)&alphaNowFrame_8034 + iVar5) = sVar3 + 1;
              }
              else {
                *(undefined2 *)((int)&alphaNowFrame_8034 + iVar5) = 3;
              }
            }
            else {
              *(short *)((int)&alphaNowFrame_8034 + iVar5) = sVar3 + -1;
            }
            iVar5 = iVar5 + 2;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
      }
    }
  }
LAB_801f67c0:
  dVar9 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)alphaNowFrame_8034,0);
  dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)sRam803f633e,0);
  dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)sRam803f6340,0);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1fd8),(float)dVar9);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1f30),(float)dVar9);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2080),(float)dVar9);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2128),(float)dVar9);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2550),(float)dVar9);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x25c0),(float)dVar9);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2630),(float)dVar9);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2588),(float)dVar10);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x25f8),(float)dVar10);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2668),(float)dVar10);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2048),(float)dVar11);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1fa0),(float)dVar11);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x20f0),(float)dVar11);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2198),(float)dVar11);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2518),(float)dVar11);
  if (((*(uint *)(param_1 + 0x3004) & 0x20) == 0) ||
     (iVar5 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)()
     , (*(ushort *)(iVar5 + 10) & 3) != 0)) {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2010),(float)dVar10);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1f68),(float)dVar10);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x20b8),(float)dVar10);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2160),(float)dVar10);
  }
  else {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2010),(float)dVar9);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1f68),(float)dVar9);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x20b8),(float)dVar9);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2160),(float)dVar9);
    iVar5 = 0;
    iVar8 = 0;
    do {
      iVar7 = param_1 + iVar8;
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar7 + 0x2320));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar7 + 0x23c8));
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar7 + 0x2470));
      iVar5 = iVar5 + 1;
      iVar8 = iVar8 + 0x38;
    } while (iVar5 < 3);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801f700c) */
/* WARNING: Removing unreachable block (ram,0x801f7014) */
/* __stdcall dMeter_xyTrans(sub_meter_class *) */

void dMeter_xyTrans(int param_1)

{
  ushort uVar1;
  byte bVar3;
  char cVar4;
  int iVar2;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  double dVar9;
  undefined8 in_f30;
  undefined8 in_f31;
  double x;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (init_8369 == '\0') {
    moveNowFrame_8368 = 0;
    init_8369 = '\x01';
  }
  if (init_8372 == '\0') {
    moveFlag_8371 = 0;
    init_8372 = '\x01';
  }
  if (init_8375 == '\0') {
    moveStatus_8374 = 0;
    init_8375 = '\x01';
  }
  if (init_8378 == '\0') {
    nowX_8377 = 0_0;
    init_8378 = '\x01';
  }
  if (init_8381 == '\0') {
    nowY_8380 = 0_0;
    init_8381 = '\x01';
  }
  uVar5 = *(uint *)(param_1 + 0x3004);
  if ((uVar5 & 0x4000) == 0) {
    if ((uVar5 & 0x40) != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.field_0xd6 & 1;
      }
      if (uVar1 != 0) goto LAB_801f6b4c;
    }
    if (((uVar5 & 0x100) != 0) ||
       ((((bVar3 = dMenu_flag(), bVar3 != 0 &&
          ((cVar4 = dMenu_getPushMenuButton(), cVar4 == '\x02' ||
           ((bVar3 = dMenu_getMenuStatus(), bVar3 == 2 &&
            (cVar4 = dMenu_getPushMenuButton(), cVar4 == '\0')))))) ||
         ((*(uint *)(param_1 + 0x3004) & 0x800000) != 0)) ||
        ((((((*(uint *)(param_1 + 0x3004) & 0x20) != 0 &&
            (iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                               getStagInfo)(), (*(ushort *)(iVar2 + 10) & 3) == 1)) ||
           (uVar5 = *(uint *)(param_1 + 0x3004), (uVar5 & 0x80) != 0)) ||
          ((((uVar5 & 0x100000) != 0 || ((uVar5 & 0x200000) != 0)) ||
           (((uVar5 & 0x20000) != 0 || (((uVar5 & 0x40000) != 0 || ((uVar5 & 0x80000) != 0))))))))
         || ((uVar5 & 0x400000) != 0)))))) goto LAB_801f6b4c;
    bVar3 = dMenu_flag();
    if ((bVar3 == 0) ||
       ((cVar4 = dMenu_getPushMenuButton(), cVar4 != '\x01' &&
        ((bVar3 = dMenu_getMenuStatus(), bVar3 != 1 ||
         (cVar4 = dMenu_getPushMenuButton(), cVar4 != '\0')))))) {
      if ((*(uint *)(param_1 + 0x3004) & 0x20) == 0) {
        if (moveStatus_8374 != 0) {
          moveFlag_8371 = 1;
          dMeter_offBit8(param_1 + 0x3026,4);
        }
        moveStatus_8374 = 0;
      }
      else {
        if ((((cRam803f7071 == '\0') || (cRam803f7071 == '\x01')) || (cRam803f7071 == '\x02')) ||
           (cRam803f7071 == '\x03')) {
          if (moveStatus_8374 != 3) {
            moveFlag_8371 = 1;
            dMeter_offBit8(param_1 + 0x3026,4);
          }
          moveStatus_8374 = 3;
        }
        else {
          if (((cRam803f7071 == '\a') || (cRam803f7071 == '\b')) ||
             ((cRam803f7071 == '\t' || (cRam803f7071 == '\n')))) {
            if (moveStatus_8374 != 4) {
              moveFlag_8371 = 1;
              dMeter_offBit8(param_1 + 0x3026,4);
            }
            moveStatus_8374 = 4;
          }
          else {
            if (moveStatus_8374 != 1) {
              moveFlag_8371 = 1;
              dMeter_offBit8(param_1 + 0x3026,4);
            }
            moveStatus_8374 = 1;
          }
        }
      }
    }
    else {
      cVar4 = dMenu_getItemMode();
      if (cVar4 == '\0') {
        if (moveStatus_8374 != 2) {
          moveFlag_8371 = 1;
          dMeter_offBit8(param_1 + 0x3026,4);
        }
        moveStatus_8374 = 2;
      }
      else {
        if (moveStatus_8374 != 1) {
          moveFlag_8371 = 1;
          dMeter_offBit8(param_1 + 0x3026,4);
        }
        moveStatus_8374 = 1;
      }
    }
  }
  else {
LAB_801f6b4c:
    if (moveStatus_8374 != 1) {
      moveFlag_8371 = 1;
      dMeter_offBit8(param_1 + 0x3026,4);
    }
    moveStatus_8374 = 1;
  }
  if (*(char *)(param_1 + 0x3026) == '\x0f') {
    if (moveNowFrame_8368 < 1) {
      moveNowFrame_8368 = 0;
    }
    else {
      moveNowFrame_8368 = moveNowFrame_8368 + -1;
    }
  }
  else {
    iVar2 = dMeter_isBit8(param_1 + 0x3026,4);
    if (iVar2 == 0) {
      if (moveNowFrame_8368 < 5) {
        moveNowFrame_8368 = moveNowFrame_8368 + 1;
      }
      else {
        moveNowFrame_8368 = 5;
        moveFlag_8371 = 0;
        dMeter_onBit8(param_1 + 0x3026,4);
        if (moveStatus_8374 == 3) {
          nowX_8377 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a1c ^ 0x80000000) - _4622);
          nowY_8380 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a24 ^ 0x80000000) - _4622);
        }
        else {
          if (moveStatus_8374 < 3) {
            if (moveStatus_8374 == 1) {
              nowX_8377 = 0_0;
              nowY_8380 = _6268;
              goto LAB_801f6efc;
            }
            if (0 < moveStatus_8374) {
              nowX_8377 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69cc ^ 0x80000000) -
                                 _4622);
              nowY_8380 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69d4 ^ 0x80000000) -
                                 _4622);
              goto LAB_801f6efc;
            }
          }
          else {
            if (moveStatus_8374 < 5) {
              nowX_8377 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a1c + 0x28U ^ 0x80000000
                                                  ) - _4622);
              nowY_8380 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a24 ^ 0x80000000) -
                                 _4622);
              goto LAB_801f6efc;
            }
          }
          nowX_8377 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69fc ^ 0x80000000) - _4622);
          nowY_8380 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a04 ^ 0x80000000) - _4622);
        }
      }
    }
  }
LAB_801f6efc:
  dVar9 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)moveNowFrame_8368,0);
  x = (double)nowX_8377;
  dVar9 = (double)(nowY_8380 + (float)(dVar9 * (double)(_6268 - nowY_8380)));
  iVar2 = 0;
  iVar7 = 0;
  do {
    iVar6 = param_1 + iVar7;
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(iVar6 + 0x1fd8),x,dVar9);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(iVar6 + 0x1f30),x,dVar9);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(iVar6 + 0x2080),x,dVar9);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(iVar6 + 0x2128),x,dVar9);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(iVar6 + 0x2320),x,dVar9);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(iVar6 + 0x23c8),x,dVar9);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(iVar6 + 0x2470),x,dVar9);
    iVar2 = iVar2 + 1;
    iVar7 = iVar7 + 0x38;
  } while (iVar2 < 3);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x2518),x,dVar9);
  iVar2 = 0;
  iVar7 = 0;
  do {
    iVar6 = param_1 + iVar7;
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(iVar6 + 0x2550),x,dVar9);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(iVar6 + 0x25c0),x,dVar9);
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(iVar6 + 0x2630),x,dVar9);
    iVar2 = iVar2 + 1;
    iVar7 = iVar7 + 0x38;
  } while (iVar2 < 2);
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801f7074) */
/* __stdcall dMeter_rInit(sub_meter_class *) */

void dMeter_rInit(int param_1)

{
  JKRArchive *pArc;
  char *pFilename;
  
  *(undefined2 *)(param_1 + 0x270e) = 0;
  *(undefined2 *)(param_1 + 0x1cfe) = 0;
  *(undefined *)(param_1 + 0x301c) = 0;
  pArc = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpActionIconArchive;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd = 0;
  pFilename = dMeter_actionTex(0);
  JKRArchive::readTypeResource(*(void **)(param_1 + 0x2f44),0xc00,0x54494d47,pFilename,pArc);
  os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0x2f44),0xc00);
  J2DPicture::changeTexture(*(J2DPicture **)(param_1 + 0x1cc8),*(ResTIMG **)(param_1 + 0x2f44),'\0')
  ;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dMeter_rMove(sub_meter_class *) */

void dMeter_rMove(sub_meter_class *param_1)

{
  char *pFilename;
  JKRArchive *pArc;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd0 != 0) {
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd =
         d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd0;
  }
  if ((param_1->field_0x1cc8).mUserData != 0) {
    if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd != 0) {
      if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd == 7) ||
         (pArc = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpActionIconArchive,
         d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd == 7)) {
        pArc = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMenuArchive;
      }
      pFilename = dMeter_actionTex((ushort)d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd);
      JKRArchive::readTypeResource(*(void **)&param_1->field_0x2f44,0xc00,0x54494d47,pFilename,pArc)
      ;
      os::DCStoreRangeNoSync(*(undefined4 *)&param_1->field_0x2f44,0xc00);
      J2DPicture::changeTexture
                ((J2DPicture *)(param_1->field_0x1cc8).mpPane,*(ResTIMG **)&param_1->field_0x2f44,
                 '\0');
    }
    *(byte *)&param_1->field_0x301c = d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd;
    (param_1->field_0x26d8).mUserData = 1;
    (param_1->field_0x1cc8).mUserData = 0;
  }
  if (*(byte *)&param_1->field_0x301c != d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd) {
    (param_1->field_0x1cc8).mUserData = 1;
  }
  dMeter_rTrans(param_1);
  dMeter_rAlpha(param_1);
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd0 = 0;
  return;
}


/* __stdcall dMeter_rDraw(sub_meter_class *) */

void dMeter_rDraw(int param_1)

{
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x1cc8));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x26a0));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0x26d8));
  return;
}


/* WARNING: Removing unreachable block (ram,0x801f7480) */
/* __stdcall dMeter_rAlpha(sub_meter_class *) */

void dMeter_rAlpha(sub_meter_class *this)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (init_8564 == '\0') {
    alphaNowFrame_8563 = 0;
    init_8564 = '\x01';
  }
  uVar4 = this->field_0x3004;
  if ((uVar4 & 0x4000) == 0) {
    if ((uVar4 & 0x40) != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.field_0xd6 & 8;
      }
      if (uVar1 != 0) goto LAB_801f730c;
    }
    if (((((((uVar4 & 0x100) == 0) && ((uVar4 & 0x200) == 0)) && ((uVar4 & 8) == 0)) &&
         (((uVar4 & 0x10) == 0 && ((uVar4 & 0x800000) == 0)))) &&
        (((uVar4 & 0x20) == 0 && (((uVar4 & 0x80) == 0 && ((uVar4 & 0x100000) == 0)))))) &&
       (((uVar4 & 0x200000) == 0 &&
        ((((uVar4 & 0x40000) == 0 && ((uVar4 & 0x80000) == 0)) && ((uVar4 & 0x400000) == 0)))))) {
      if (((uVar4 & 0x2000) == 0) && ((uVar4 & 0x8000) == 0)) {
        sVar2 = 5;
        if (alphaNowFrame_8563 < 5) {
          sVar2 = alphaNowFrame_8563 + 1;
        }
        alphaNowFrame_8563 = sVar2;
        *(byte *)&this->field_0x3024 = *(byte *)&this->field_0x3024 | 0x10;
      }
      else {
        if (alphaNowFrame_8563 < 4) {
          if (alphaNowFrame_8563 < 3) {
            alphaNowFrame_8563 = alphaNowFrame_8563 + 1;
          }
          else {
            alphaNowFrame_8563 = 3;
          }
        }
        else {
          alphaNowFrame_8563 = alphaNowFrame_8563 + -1;
        }
      }
      goto LAB_801f739c;
    }
  }
LAB_801f730c:
  if (alphaNowFrame_8563 < 5) {
    alphaNowFrame_8563 = alphaNowFrame_8563 + 1;
  }
  else {
    alphaNowFrame_8563 = 5;
  }
LAB_801f739c:
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)alphaNowFrame_8563,0);
  if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd == 0) {
    f_op_msg_mng::fopMsgM_setNowAlphaZero(&this->field_0x1cc8);
  }
  else {
    f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x1cc8,(float)dVar6);
  }
  if (((this->field_0x3004 & 0x20) == 0) ||
     (iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)()
     , (*(ushort *)(iVar3 + 10) & 3) != 0)) {
    f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x26a0,(float)dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x26d8,(float)dVar6);
  }
  else {
    dVar7 = (double)(float)((double)1_0 - dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x26a0,(float)((double)1_0 - dVar6));
    f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x26d8,(float)dVar7);
  }
  iVar3 = dMeter_isBit8(&this->field_0x3026,8);
  if ((iVar3 == 0) || ((this->field_0x1cc8).mUserData != 0)) {
    (((this->field_0x1cc8).mpPane)->parent).mbDraw = 0;
  }
  else {
    (((this->field_0x1cc8).mpPane)->parent).mbDraw = 1;
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801f7ae8) */
/* WARNING: Removing unreachable block (ram,0x801f7af0) */
/* __stdcall dMeter_rTrans(sub_meter_class *) */

void dMeter_rTrans(int param_1)

{
  ushort uVar1;
  byte bVar3;
  char cVar4;
  int iVar2;
  uint uVar5;
  undefined4 uVar6;
  double dVar7;
  double x;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (init_8634 == '\0') {
    moveNowFrame_8633 = 0;
    init_8634 = '\x01';
  }
  if (init_8637 == '\0') {
    moveFlag_8636 = 0;
    init_8637 = '\x01';
  }
  if (init_8640 == '\0') {
    moveStatus_8639 = 0;
    init_8640 = '\x01';
  }
  if (init_8643 == '\0') {
    nowX_8642 = 0_0;
    init_8643 = '\x01';
  }
  if (init_8646 == '\0') {
    nowY_8645 = 0_0;
    init_8646 = '\x01';
  }
  uVar5 = *(uint *)(param_1 + 0x3004);
  if ((uVar5 & 0x4000) == 0) {
    if ((uVar5 & 0x40) != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.field_0xd6 & 8;
      }
      if (uVar1 != 0) goto LAB_801f75a8;
    }
    if (((uVar5 & 0x100) != 0) || (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd == 0x3e))
    goto LAB_801f75a8;
    if ((uVar5 & 0x20000) == 0) {
      if ((uVar5 & 0x40000) == 0) {
        bVar3 = dMenu_flag();
        if ((((((bVar3 == 0) || (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe == 2)) ||
              ((cVar4 = dMenu_getPushMenuButton(), cVar4 != '\x01' &&
               ((bVar3 = dMenu_getMenuStatus(), bVar3 != 1 ||
                (cVar4 = dMenu_getPushMenuButton(), cVar4 != '\0')))))) &&
             ((bVar3 = dMenu_flag(), bVar3 == 0 ||
              ((cVar4 = dMenu_getPushMenuButton(), cVar4 != '\x02' &&
               ((bVar3 = dMenu_getMenuStatus(), bVar3 != 2 ||
                (cVar4 = dMenu_getPushMenuButton(), cVar4 != '\0')))))))) &&
            ((*(uint *)(param_1 + 0x3004) & 0x800000) == 0)) &&
           (((((*(uint *)(param_1 + 0x3004) & 0x20) == 0 ||
              (iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                                 getStagInfo)(), (*(ushort *)(iVar2 + 10) & 3) != 1)) &&
             (uVar5 = *(uint *)(param_1 + 0x3004), (uVar5 & 0x80) == 0)) &&
            ((((uVar5 & 0x100000) == 0 && ((uVar5 & 0x200000) == 0)) &&
             (((uVar5 & 0x80000) == 0 && ((uVar5 & 0x400000) == 0)))))))) {
          if ((uVar5 & 0x20) == 0) {
            if (moveStatus_8639 != 0) {
              moveFlag_8636 = 1;
              dMeter_offBit8(param_1 + 0x3026,8);
            }
            moveStatus_8639 = 0;
          }
          else {
            if (((cRam803f7071 == '\0') || (cRam803f7071 == '\x01')) ||
               ((cRam803f7071 == '\x02' || (cRam803f7071 == '\x03')))) {
              if (moveStatus_8639 != 3) {
                moveFlag_8636 = 1;
                dMeter_offBit8(param_1 + 0x3026,8);
              }
              moveStatus_8639 = 3;
            }
            else {
              if ((((cRam803f7071 == '\a') || (cRam803f7071 == '\b')) || (cRam803f7071 == '\t')) ||
                 (cRam803f7071 == '\n')) {
                if (moveStatus_8639 != 5) {
                  moveFlag_8636 = 1;
                  dMeter_offBit8(param_1 + 0x3026,8);
                }
                moveStatus_8639 = 5;
              }
              else {
                if (moveStatus_8639 != 1) {
                  moveFlag_8636 = 1;
                  dMeter_offBit8(param_1 + 0x3026,8);
                }
                moveStatus_8639 = 1;
              }
            }
          }
        }
        else {
          if (moveStatus_8639 != 1) {
            moveFlag_8636 = 1;
            dMeter_offBit8(param_1 + 0x3026,8);
          }
          moveStatus_8639 = 1;
        }
      }
      else {
        if (moveStatus_8639 != 4) {
          moveFlag_8636 = 1;
          dMeter_offBit8(param_1 + 0x3026,8);
        }
        moveStatus_8639 = 4;
      }
    }
    else {
      if (moveStatus_8639 != 2) {
        moveFlag_8636 = 1;
        dMeter_offBit8(param_1 + 0x3026,8);
      }
      moveStatus_8639 = 2;
    }
  }
  else {
LAB_801f75a8:
    if (moveStatus_8639 != 1) {
      moveFlag_8636 = 1;
      dMeter_offBit8(param_1 + 0x3026,8);
    }
    moveStatus_8639 = 1;
  }
  if (*(char *)(param_1 + 0x3026) == '\x0f') {
    if (moveNowFrame_8633 < 1) {
      moveNowFrame_8633 = 0;
    }
    else {
      moveNowFrame_8633 = moveNowFrame_8633 + -1;
    }
  }
  else {
    iVar2 = dMeter_isBit8(param_1 + 0x3026,8);
    if (iVar2 == 0) {
      if (moveNowFrame_8633 < 5) {
        moveNowFrame_8633 = moveNowFrame_8633 + 1;
      }
      else {
        moveNowFrame_8633 = 5;
        moveFlag_8636 = 0;
        dMeter_onBit8(param_1 + 0x3026,8);
        if (moveStatus_8639 == 3) {
          nowX_8642 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a1e ^ 0x80000000) - _4622);
          nowY_8645 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a26 ^ 0x80000000) - _4622);
        }
        else {
          if (moveStatus_8639 < 3) {
            if (moveStatus_8639 == 1) {
              nowX_8642 = 0_0;
              nowY_8645 = _6268;
              goto LAB_801f7a8c;
            }
            if (0 < moveStatus_8639) {
              nowX_8642 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69be ^ 0x80000000) -
                                 _4622);
              nowY_8645 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69c6 ^ 0x80000000) -
                                 _4622);
              goto LAB_801f7a8c;
            }
          }
          else {
            if (moveStatus_8639 == 5) {
              nowX_8642 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a1e + 0x21U ^ 0x80000000
                                                  ) - _4622);
              nowY_8645 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a26 - 5U ^ 0x80000000) -
                                 _4622);
              goto LAB_801f7a8c;
            }
            if (moveStatus_8639 < 5) {
              nowX_8642 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69ee ^ 0x80000000) -
                                 _4622);
              nowY_8645 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69f6 ^ 0x80000000) -
                                 _4622);
              goto LAB_801f7a8c;
            }
          }
          nowX_8642 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e69fe ^ 0x80000000) - _4622);
          nowY_8645 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a06 ^ 0x80000000) - _4622);
        }
      }
    }
  }
LAB_801f7a8c:
  dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)moveNowFrame_8633,0);
  x = (double)nowX_8642;
  dVar7 = (double)(nowY_8645 + (float)(dVar7 * (double)(_6268 - nowY_8645)));
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x1cc8),x,dVar7);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x26a0),x,dVar7);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x26d8),x,dVar7);
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return;
}


/* __stdcall dMeter_enemyInit(sub_meter_class *) */

void dMeter_enemyInit(int param_1)

{
  float fVar1;
  
  *(undefined2 *)(param_1 + 0x4b6) = 0;
  *(undefined2 *)(param_1 + 0x596) = 0;
  *(undefined2 *)(param_1 + 0x40e) = 0;
  fVar1 = SComponent::cM_rndF(_8762);
  *(short *)(param_1 + 0x446) = (short)(int)(_8761 + fVar1);
  *(undefined2 *)(param_1 + 0x39e) = 0;
  fVar1 = SComponent::cM_rndF(_4654);
  *(short *)(param_1 + 0x3d6) = (short)((int)(40_0 + fVar1) << 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dMeter_enemyMove(sub_meter_class *) */

void dMeter_enemyMove(int param_1)

{
  int iVar1;
  ulong uVar2;
  byte bVar5;
  fopAc_ac_c *pfVar3;
  uint uVar4;
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_34;
  undefined2 local_32;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20 [4];
  undefined4 local_18;
  uint uStack20;
  
  iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  if (iVar1 == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_meter.cpp",0x1c08,"stage_info != 0");
    m_Do_printf::OSPanic("d_meter.cpp",0x1c08,&DAT_80361783);
  }
  bVar5 = dMenu_flag();
  if (((bVar5 == 0) && (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0)) &&
     (pfVar3 = dAttention_c::LockonTarget(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0),
     pfVar3 != (fopAc_ac_c *)0x0)) {
    pfVar3 = dAttention_c::LockonTarget(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0);
    uStack20 = (int)(char)pfVar3->mMaxHp ^ 0x80000000;
    local_18 = 0x43300000;
    if (((((((float)((double)CONCAT44(0x43300000,uStack20) - _4622) <= 0_0) ||
           (uVar4 = dSv_player_collect_c::isCollect
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,4,
                               1), uVar4 == 0)) ||
          ((uVar4 = dAttention_c::LockonTruth(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention),
           (uVar4 & 0xff) == 0 ||
           ((pfVar3 = dAttention_c::LockonTarget
                                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0),
            pfVar3->mActorType != Enemy ||
            (pfVar3 = dAttention_c::LockonTarget
                                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0),
            (pfVar3->parent).parent.mProcName == 0xeb)))))) ||
         (pfVar3 = dAttention_c::LockonTarget
                             (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0),
         (pfVar3->parent).parent.mProcName == 0xec)) ||
        ((((pfVar3 = dAttention_c::LockonTarget
                               (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0),
           (pfVar3->parent).parent.mProcName == 0xf0 ||
           (pfVar3 = dAttention_c::LockonTarget
                               (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0),
           (pfVar3->parent).parent.mProcName == 0xd4)) ||
          (pfVar3 = dAttention_c::LockonTarget
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0),
          (pfVar3->parent).parent.mProcName == 0xf5)) ||
         ((pfVar3 = dAttention_c::LockonTarget
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0),
          (pfVar3->parent).parent.mProcName == 0xf6 ||
          (pfVar3 = dAttention_c::LockonTarget
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0),
          (pfVar3->parent).parent.mProcName == 0xf7)))))) ||
       (((pfVar3 = dAttention_c::LockonTarget
                             (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0),
         (pfVar3->parent).parent.mProcName == 0xf8 ||
         ((pfVar3 = dAttention_c::LockonTarget
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0),
          (pfVar3->parent).parent.mProcName == 0xf2 &&
          (pfVar3 = dAttention_c::LockonTarget
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0),
          ((pfVar3->parent).parent.mParameters & 0xfU) == 0)))) ||
        (pfVar3 = dAttention_c::LockonTarget(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0)
        , (pfVar3->parent).parent.mProcName == 0xda)))) goto LAB_801f7dd4;
    dMeter_zakoEnemyMove(param_1);
  }
  else {
LAB_801f7dd4:
    dMeter_zakoEnemyHide(param_1);
  }
  bVar5 = dMenu_flag();
  if ((((bVar5 == 0) &&
       (uVar4 = dSv_player_collect_c::isCollect
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,4,1),
       uVar4 != 0)) && (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0)) &&
     (((*(uint *)(param_1 + 0x3004) & 0x80) == 0 && ((*(uint *)(param_1 + 0x3004) & 0x20000) == 0)))
     ) {
    if ((*(uint *)(iVar1 + 0xc) >> 0x10 & 7) != 3) {
      local_20[0] = 0xf0;
      pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_20);
      if (pfVar3 == (fopAc_ac_c *)0x0) goto LAB_801f80a4;
    }
    iVar1 = dSv_memBit_c::isDungeonItem
                      ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,5);
    if (((iVar1 != 0) &&
        (iVar1 = dSv_memBit_c::isDungeonItem
                           ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,3),
        iVar1 == 0)) ||
       ((iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                           (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss0"),
        iVar1 == 0 ||
        (((iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                             (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss1"
                             ), iVar1 == 0 ||
          (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                             (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss2"
                             ), iVar1 == 0)) ||
         (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss3")
         , iVar1 == 0)))))) {
      local_22 = 0xeb;
      pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_22);
      if (pfVar3 == (fopAc_ac_c *)0x0) {
        local_26 = 0xec;
        pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_26);
        if (pfVar3 == (fopAc_ac_c *)0x0) {
          local_2a = 0xf0;
          pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_2a);
          if (pfVar3 == (fopAc_ac_c *)0x0) {
            local_2e = 0xf2;
            pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_2e);
            if (pfVar3 == (fopAc_ac_c *)0x0) {
              local_32 = 0xda;
              pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_32)
              ;
              if (pfVar3 == (fopAc_ac_c *)0x0) {
                local_36 = 0xd4;
                pfVar3 = f_op_actor_iter::fopAcIt_Judge
                                   (f_pc_searcher::fpcSch_JudgeForPName,&local_36);
                if (pfVar3 == (fopAc_ac_c *)0x0) {
                  pfVar3 = (fopAc_ac_c *)0x0;
                }
                else {
                  local_38 = 0xd4;
                  pfVar3 = f_op_actor_iter::fopAcIt_Judge
                                     (f_pc_searcher::fpcSch_JudgeForPName,&local_38);
                }
              }
              else {
                local_34 = 0xda;
                pfVar3 = f_op_actor_iter::fopAcIt_Judge
                                   (f_pc_searcher::fpcSch_JudgeForPName,&local_34);
              }
            }
            else {
              local_30 = 0xf2;
              pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_30)
              ;
            }
          }
          else {
            local_2c = 0xf0;
            pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_2c);
          }
        }
        else {
          local_28 = 0xec;
          pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_28);
        }
      }
      else {
        local_24 = 0xeb;
        pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_24);
      }
      if (pfVar3 != (fopAc_ac_c *)0x0) {
        dMeter_bossEnemyMove(param_1);
        return;
      }
      dMeter_bossEnemyHide(param_1);
      return;
    }
  }
LAB_801f80a4:
  dMeter_bossEnemyHide(param_1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801f840c) */
/* __stdcall dMeter_zakoEnemyMove(sub_meter_class *) */

void dMeter_zakoEnemyMove(int param_1)

{
  fopAc_ac_c *pfVar1;
  undefined4 uVar2;
  undefined8 in_f31;
  double dVar3;
  cXyz local_38;
  undefined4 local_28;
  uint uStack36;
  undefined4 local_20;
  uint uStack28;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pfVar1 = dAttention_c::LockonTarget(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0);
  m_Do_lib::mDoLib_project(&pfVar1->mAttentionPos,&local_38);
  if (local_38.x <= _7214) {
    *(float *)(param_1 + 0x56c) = _7626 + local_38.x;
  }
  else {
    *(float *)(param_1 + 0x56c) = (local_38.x - *(float *)(param_1 + 0x584)) - _7626;
  }
  *(float *)(param_1 + 0x570) = local_38.y;
  uStack36 = (int)pfVar1->mCurrHp ^ 0x80000000;
  local_28 = 0x43300000;
  uStack28 = (int)(char)pfVar1->mMaxHp ^ 0x80000000;
  local_20 = 0x43300000;
  dVar3 = (double)((float)((double)CONCAT44(0x43300000,uStack36) - _4622) /
                  (float)((double)CONCAT44(0x43300000,uStack28) - _4622));
  *(float *)(param_1 + 0x534) =
       *(float *)(param_1 + 0x56c) + (*(float *)(param_1 + 0x52c) - *(float *)(param_1 + 0x564));
  *(float *)(param_1 + 0x538) =
       *(float *)(param_1 + 0x570) + (*(float *)(param_1 + 0x530) - *(float *)(param_1 + 0x568));
  *(undefined4 *)(param_1 + 0x554) = *(undefined4 *)(param_1 + 0x54c);
  *(undefined4 *)(param_1 + 0x558) = *(undefined4 *)(param_1 + 0x550);
  (**(code **)(**(int **)(param_1 + 0x528) + 0x10))
            ((double)*(float *)(param_1 + 0x534),(double)*(float *)(param_1 + 0x538));
  (**(code **)(**(int **)(param_1 + 0x528) + 0x18))
            ((double)*(float *)(param_1 + 0x554),(double)*(float *)(param_1 + 0x558));
  *(float *)(param_1 + 0x5a4) =
       *(float *)(param_1 + 0x56c) + (*(float *)(param_1 + 0x59c) - *(float *)(param_1 + 0x564));
  *(float *)(param_1 + 0x5a8) =
       *(float *)(param_1 + 0x570) + (*(float *)(param_1 + 0x5a0) - *(float *)(param_1 + 0x568));
  *(undefined4 *)(param_1 + 0x5c4) = *(undefined4 *)(param_1 + 0x5bc);
  *(undefined4 *)(param_1 + 0x5c8) = *(undefined4 *)(param_1 + 0x5c0);
  (**(code **)(**(int **)(param_1 + 0x598) + 0x10))
            ((double)*(float *)(param_1 + 0x5a4),(double)*(float *)(param_1 + 0x5a8));
  (**(code **)(**(int **)(param_1 + 0x598) + 0x18))
            ((double)*(float *)(param_1 + 0x5c4),(double)*(float *)(param_1 + 0x5c8));
  *(float *)(param_1 + 0x614) =
       *(float *)(param_1 + 0x56c) + (*(float *)(param_1 + 0x60c) - *(float *)(param_1 + 0x564));
  *(float *)(param_1 + 0x618) =
       *(float *)(param_1 + 0x570) + (*(float *)(param_1 + 0x610) - *(float *)(param_1 + 0x568));
  *(undefined4 *)(param_1 + 0x634) = *(undefined4 *)(param_1 + 0x62c);
  *(undefined4 *)(param_1 + 0x638) = *(undefined4 *)(param_1 + 0x630);
  (**(code **)(**(int **)(param_1 + 0x608) + 0x10))
            ((double)*(float *)(param_1 + 0x614),(double)*(float *)(param_1 + 0x618));
  (**(code **)(**(int **)(param_1 + 0x608) + 0x18))
            ((double)*(float *)(param_1 + 0x634),(double)*(float *)(param_1 + 0x638));
  *(undefined4 *)(param_1 + 0x5dc) = *(undefined4 *)(param_1 + 0x5d4);
  *(undefined4 *)(param_1 + 0x5e0) = *(undefined4 *)(param_1 + 0x5d8);
  *(undefined4 *)(param_1 + 0x5fc) = *(undefined4 *)(param_1 + 0x5f4);
  *(undefined4 *)(param_1 + 0x600) = *(undefined4 *)(param_1 + 0x5f8);
  (**(code **)(**(int **)(param_1 + 0x5d0) + 0x10))
            ((double)*(float *)(param_1 + 0x5dc),(double)*(float *)(param_1 + 0x5e0));
  (**(code **)(**(int **)(param_1 + 0x5d0) + 0x18))
            ((double)*(float *)(param_1 + 0x5fc),(double)*(float *)(param_1 + 0x600));
  *(float *)(param_1 + 0x58c) = (float)((double)*(float *)(param_1 + 0x584) * dVar3);
  *(undefined4 *)(param_1 + 0x590) = *(undefined4 *)(param_1 + 0x588);
  (**(code **)(**(int **)(param_1 + 0x560) + 0x10))
            ((double)*(float *)(param_1 + 0x56c),(double)*(float *)(param_1 + 0x570));
  (**(code **)(**(int **)(param_1 + 0x560) + 0x18))
            ((double)*(float *)(param_1 + 0x58c),(double)*(float *)(param_1 + 0x590));
  if (*(short *)(param_1 + 0x596) < 10) {
    *(short *)(param_1 + 0x596) = *(short *)(param_1 + 0x596) + 1;
    dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(param_1 + 0x596),0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x528),(float)dVar3);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x560),(float)dVar3);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x598),(float)dVar3);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x608),(float)dVar3);
  }
  else {
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x528);
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x560);
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x598);
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x608);
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801f86c4) */
/* __stdcall dMeter_bossEnemyMove(sub_meter_class *,
                                  fopAc_ac_c *) */

void dMeter_bossEnemyMove(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar1 = DAT_803e6914;
  if (*(char *)(param_2 + 0x284) != '\0') {
    fVar1 = (float)((double)CONCAT44(0x43300000,(int)*(char *)(param_2 + 0x285) ^ 0x80000000) -
                   _4622) /
            (float)((double)CONCAT44(0x43300000,(int)*(char *)(param_2 + 0x284) ^ 0x80000000) -
                   _4622);
  }
  dVar6 = (double)fVar1;
  if (*(short *)(param_1 + 0x47e) < 0x1e) {
    *(short *)(param_1 + 0x47e) = *(short *)(param_1 + 0x47e) + 1;
    iVar2 = (int)*(short *)(param_1 + 0x47e);
    if (iVar2 < 0xb) {
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,10 - iVar2,0);
      dVar6 = (double)(float)((double)_8977 * dVar6);
      f_op_msg_mng::fopMsgM_paneScaleX((double)0_0,param_1 + 0x4b8);
      f_op_msg_mng::fopMsgM_paneScaleX((double)0_0,param_1 + 0x4f0);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x368),(double)0_0,dVar6);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x3a0),(double)0_0,dVar6);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x3d8),(double)0_0,dVar6);
      f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x410),(double)0_0,dVar6);
      iVar2 = 0;
      iVar3 = 0;
      do {
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(param_1 + iVar3 + 0x448),(double)0_0,dVar6);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x38;
      } while (iVar2 < 4);
    }
    else {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x14,iVar2 + -10,2);
      dVar6 = (double)(float)(dVar6 * dVar5);
      f_op_msg_mng::fopMsgM_paneScaleX(dVar6,param_1 + 0x4b8);
      f_op_msg_mng::fopMsgM_paneScaleX(dVar6,param_1 + 0x4f0);
    }
  }
  else {
    f_op_msg_mng::fopMsgM_paneScaleX(dVar6,param_1 + 0x4b8);
    f_op_msg_mng::fopMsgM_paneScaleX(dVar6,param_1 + 0x4f0);
  }
  (**(code **)(**(int **)(param_1 + 0x4b8) + 0x10))
            ((double)((*(float *)(param_1 + 0x4bc) + *(float *)(param_1 + 0x4dc)) -
                     *(float *)(param_1 + 0x4e4)),(double)*(float *)(param_1 + 0x4c0));
  (**(code **)(**(int **)(param_1 + 0x4f0) + 0x10))
            ((double)((*(float *)(param_1 + 0x4f4) + *(float *)(param_1 + 0x514)) -
                     *(float *)(param_1 + 0x51c)),(double)*(float *)(param_1 + 0x4f8));
  if (*(short *)(param_1 + 0x4b6) < 10) {
    *(short *)(param_1 + 0x4b6) = *(short *)(param_1 + 0x4b6) + 1;
    dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(param_1 + 0x4b6),0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x368),(float)dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x3a0),(float)dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x3d8),(float)dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x410),(float)dVar6);
    iVar2 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)(param_1 + iVar3 + 0x448),(float)dVar6);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar2 < 4);
  }
  else {
    dMeter_bossAnime(param_1);
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x3d8);
    f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x410);
    iVar2 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + iVar3 + 0x448);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar2 < 4);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* __stdcall dMeter_zakoEnemyHide(sub_meter_class *) */

void dMeter_zakoEnemyHide(int param_1)

{
  double dVar1;
  
  if (*(short *)(param_1 + 0x596) < 1) {
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x528));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x560));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x598));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x608));
  }
  else {
    *(short *)(param_1 + 0x596) = *(short *)(param_1 + 0x596) + -1;
    dVar1 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(param_1 + 0x596),0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x528),(float)dVar1);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x560),(float)dVar1);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x598),(float)dVar1);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x608),(float)dVar1);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMeter_bossEnemyHide(sub_meter_class *) */

void dMeter_bossEnemyHide(int param_1)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  if (*(short *)(param_1 + 0x4b6) < 1) {
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x368));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x3a0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x3d8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x410));
    iVar1 = 0;
    iVar2 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + iVar2 + 0x448));
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x38;
    } while (iVar1 < 4);
  }
  else {
    *(short *)(param_1 + 0x4b6) = *(short *)(param_1 + 0x4b6) + -1;
    dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(param_1 + 0x4b6),0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x368),(float)dVar3);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x3a0),(float)dVar3);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x3d8),(float)dVar3);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x410),(float)dVar3);
    iVar1 = 0;
    iVar2 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)(param_1 + iVar2 + 0x448),(float)dVar3);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x38;
    } while (iVar1 < 4);
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x801f8b84) */
/* WARNING: Removing unreachable block (ram,0x801f8b8c) */
/* __stdcall dMeter_bossAnime(sub_meter_class *) */

void dMeter_bossAnime(int param_1)

{
  short sVar1;
  char **ppcVar2;
  char **ppcVar3;
  char *pcVar4;
  char **ppcVar5;
  char **ppcVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  double y;
  float fVar11;
  short asStack122 [6];
  short local_6e;
  short local_6c;
  short local_6a;
  short local_68;
  short local_66;
  short local_64;
  short local_62;
  short local_60;
  short local_5e;
  short local_5c;
  undefined4 local_58;
  short local_54;
  short local_50;
  short local_4c [4];
  short local_44;
  short local_40;
  short local_3c;
  longlong local_38;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar10 = (double)0_0;
  iVar7 = 3;
  ppcVar2 = &act_5120[0x3e].mpTexName;
  ppcVar3 = (char **)&local_5c;
  do {
    ppcVar6 = ppcVar3;
    ppcVar5 = ppcVar2;
    pcVar4 = ppcVar5[2];
    ppcVar6[1] = ppcVar5[1];
    sVar1 = local_58._0_2_;
    ppcVar6[2] = pcVar4;
    iVar7 = iVar7 + -1;
    ppcVar2 = ppcVar5 + 2;
    ppcVar3 = ppcVar6 + 2;
  } while (iVar7 != 0);
  ppcVar6[3] = ppcVar5[3];
  *(undefined2 *)(ppcVar6 + 4) = *(undefined2 *)(ppcVar5 + 4);
  asStack122[1] = local_58._0_2_;
  iVar7 = 2;
  iVar8 = 0xe;
  do {
    *(short *)((int)asStack122 + iVar7 + 2) =
         *(short *)((int)asStack122 + iVar7) + *(short *)((int)&local_58 + iVar7);
    iVar7 = iVar7 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  *(short *)(param_1 + 0x40e) = *(short *)(param_1 + 0x40e) + 1;
  iVar7 = (int)*(short *)(param_1 + 0x40e);
  if (iVar7 < *(short *)(param_1 + 0x446)) {
    iVar8 = (int)local_64;
    if (iVar7 < iVar8) {
      if (iVar7 < sVar1) {
        dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease((int)local_58._0_2_,iVar7,0);
        dVar10 = (double)(float)((double)2_0 * dVar10);
      }
      else {
        if (iVar7 < asStack122[2]) {
          dVar10 = (double)2_0;
        }
        else {
          if (iVar7 < asStack122[3]) {
            dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                       ((int)local_54,asStack122[3] - iVar7,0);
            dVar10 = (double)(float)((double)2_0 * dVar10);
          }
          else {
            if (iVar7 < asStack122[4]) {
              dVar10 = (double)0_0;
            }
            else {
              if (iVar7 < asStack122[5]) {
                dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                           ((int)local_50,asStack122[5] - iVar7,0);
                dVar10 = (double)(float)((double)2_0 * dVar10);
              }
              else {
                if (iVar7 < local_6e) {
                  dVar10 = (double)2_0;
                }
                else {
                  if (iVar7 < local_6c) {
                    dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                               ((int)local_4c[0],local_6c - iVar7,0);
                    dVar10 = (double)(float)((double)2_0 * dVar10);
                  }
                  else {
                    if (iVar7 < local_6a) {
                      dVar10 = (double)0_0;
                    }
                    else {
                      if (iVar7 < local_68) {
                        dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                                   ((int)local_4c[2],local_68 - iVar7,0);
                        dVar10 = (double)(float)((double)2_0 * dVar10);
                      }
                      else {
                        if (iVar7 < local_66) {
                          dVar10 = (double)2_0;
                        }
                        else {
                          if (iVar7 < iVar8) {
                            dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                                       ((int)local_44,iVar8 - iVar7,0);
                            dVar10 = (double)(float)((double)2_0 * dVar10);
                          }
                          else {
                            if (iVar7 < local_62) {
                              dVar10 = (double)0_0;
                            }
                            else {
                              if (iVar7 < local_60) {
                                dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                                           ((int)local_40,local_60 - iVar7,0);
                                dVar10 = (double)(float)((double)2_0 * dVar10);
                              }
                              else {
                                if (iVar7 < local_5e) {
                                  dVar10 = (double)2_0;
                                }
                                else {
                                  if (iVar7 < local_5c) {
                                    dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                                               ((int)local_3c,local_5c - iVar7,0);
                                    dVar10 = (double)(float)((double)2_0 * dVar10);
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x40e) = 0;
    fVar11 = SComponent::cM_rndF(_8762);
    local_38 = (longlong)(int)(_8761 + fVar11);
    *(short *)(param_1 + 0x446) = (short)(int)(_8761 + fVar11);
  }
  y = -dVar10;
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x3d8),(double)0_0,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x368),(double)0_0,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x3a0),(double)0_0,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x410),(double)0_0,dVar10);
  dMeter_bossEyeAnime(param_1);
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801f8cb4) */
/* __stdcall dMeter_bossEyeAnime(sub_meter_class *) */

void dMeter_bossEyeAnime(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  float fVar6;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (init_9083 == '\0') {
    bossEyeFlag_9082 = '\0';
    init_9083 = '\x01';
  }
  uVar1 = *(ushort *)(param_1 + 0x3d6);
  iVar2 = (int)(short)(((short)uVar1 >> 1) + (ushort)((short)uVar1 < 0 && (uVar1 & 1) != 0));
  *(short *)(param_1 + 0x39e) = *(short *)(param_1 + 0x39e) + 1;
  if (bossEyeFlag_9082 == '\0') {
    dVar5 = (double)0_0;
  }
  else {
    iVar3 = (int)*(short *)(param_1 + 0x39e);
    if (iVar3 < iVar2) {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar2,iVar3,2);
    }
    else {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                (iVar2,*(short *)(param_1 + 0x3d6) - iVar3,2);
    }
  }
  if (*(short *)(param_1 + 0x39e) == *(short *)(param_1 + 0x3d6)) {
    *(undefined2 *)(param_1 + 0x39e) = 0;
    fVar6 = SComponent::cM_rndF(_4654);
    *(short *)(param_1 + 0x3d6) = (short)((int)(40_0 + fVar6) << 1);
    if (bossEyeFlag_9082 == '\0') {
      bossEyeFlag_9082 = '\x01';
    }
    else {
      bossEyeFlag_9082 = '\0';
    }
  }
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x368),(float)dVar5);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x3a0),(float)dVar5);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* __stdcall dMeter_magicInit(sub_meter_class *) */

void dMeter_magicInit(int param_1)

{
  undefined4 uVar1;
  undefined local_38;
  undefined uStack55;
  undefined uStack54;
  undefined uStack53;
  undefined local_34;
  undefined uStack51;
  undefined uStack50;
  undefined uStack49;
  undefined local_30;
  undefined uStack47;
  undefined uStack46;
  undefined uStack45;
  undefined local_2c;
  undefined uStack43;
  undefined uStack42;
  undefined uStack41;
  undefined local_28;
  undefined uStack39;
  undefined uStack38;
  undefined uStack37;
  undefined local_24;
  undefined uStack35;
  undefined uStack34;
  undefined uStack33;
  double local_18;
  
  if ((d_com_inf_game::g_dComIfG_gameInfo._23557_1_ >> 1 & 1) == 0) {
    *(undefined *)(param_1 + 0x3018) = 0;
    *(undefined2 *)(param_1 + 0x3016) = 0;
    d_com_inf_game::g_dComIfG_gameInfo._23557_1_ = d_com_inf_game::g_dComIfG_gameInfo._23557_1_ | 2;
  }
  else {
    *(byte *)(param_1 + 0x3018) =
         d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic;
    *(short *)(param_1 + 0x3016) =
         (short)(int)(_9164 * *(float *)(param_1 + 0xf5c) *
                              (float)((double)CONCAT44(0x43300000,
                                                       (uint)d_com_inf_game::g_dComIfG_gameInfo.
                                                             mSvInfo.mSave.mPlayer.mStatusA.
                                                             mCurrMagic) - _4620));
  }
  *(undefined *)(param_1 + 0x3019) = 0;
  *(undefined2 *)(param_1 + 0xf6e) = 0;
  *(undefined2 *)(param_1 + 0xfa6) = 0;
  *(undefined2 *)(param_1 + 0xfde) = 0;
  *(undefined2 *)(param_1 + 0x1016) = 0;
  *(undefined2 *)(param_1 + 0x104e) = 0;
  *(undefined2 *)(param_1 + 0x1086) = 1;
  *(undefined2 *)(param_1 + 0x112e) = 0;
  *(undefined2 *)(param_1 + 0x11d6) = 0;
  *(undefined2 *)(param_1 + 0x1166) = 0;
  *(undefined2 *)(param_1 + 0x120e) = 0;
  *(float *)(param_1 + 0x2fc0) = 0_0;
  local_18 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x3018));
  dMeter_magicLength((double)((float)(local_18 - _4620) * _5558),param_1);
  dMeter_magicChange((double)((float)((double)CONCAT44(0x43300000,
                                                       (uint)*(ushort *)(param_1 + 0x3016)) - _4620)
                             / _9165),param_1);
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x11a0) + 0x104);
  local_24 = (undefined)((uint)uVar1 >> 0x18);
  *(undefined *)(param_1 + 0x2f08) = local_24;
  uStack35 = (undefined)((uint)uVar1 >> 0x10);
  *(undefined *)(param_1 + 0x2f09) = uStack35;
  uStack34 = (undefined)((uint)uVar1 >> 8);
  *(undefined *)(param_1 + 0x2f0a) = uStack34;
  uStack33 = (undefined)uVar1;
  *(undefined *)(param_1 + 0x2f0b) = uStack33;
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x11a0) + 0x108);
  local_28 = (undefined)((uint)uVar1 >> 0x18);
  *(undefined *)(param_1 + 0x2f0c) = local_28;
  uStack39 = (undefined)((uint)uVar1 >> 0x10);
  *(undefined *)(param_1 + 0x2f0d) = uStack39;
  uStack38 = (undefined)((uint)uVar1 >> 8);
  *(undefined *)(param_1 + 0x2f0e) = uStack38;
  uStack37 = (undefined)uVar1;
  *(undefined *)(param_1 + 0x2f0f) = uStack37;
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xf38) + 0x104);
  local_2c = (undefined)((uint)uVar1 >> 0x18);
  *(undefined *)(param_1 + 0x2f10) = local_2c;
  uStack43 = (undefined)((uint)uVar1 >> 0x10);
  *(undefined *)(param_1 + 0x2f11) = uStack43;
  uStack42 = (undefined)((uint)uVar1 >> 8);
  *(undefined *)(param_1 + 0x2f12) = uStack42;
  uStack41 = (undefined)uVar1;
  *(undefined *)(param_1 + 0x2f13) = uStack41;
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xf38) + 0x108);
  local_30 = (undefined)((uint)uVar1 >> 0x18);
  *(undefined *)(param_1 + 0x2f14) = local_30;
  uStack47 = (undefined)((uint)uVar1 >> 0x10);
  *(undefined *)(param_1 + 0x2f15) = uStack47;
  uStack46 = (undefined)((uint)uVar1 >> 8);
  *(undefined *)(param_1 + 0x2f16) = uStack46;
  uStack45 = (undefined)uVar1;
  *(undefined *)(param_1 + 0x2f17) = uStack45;
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xf70) + 0x104);
  local_34 = (undefined)((uint)uVar1 >> 0x18);
  *(undefined *)(param_1 + 0x2f18) = local_34;
  uStack51 = (undefined)((uint)uVar1 >> 0x10);
  *(undefined *)(param_1 + 0x2f19) = uStack51;
  uStack50 = (undefined)((uint)uVar1 >> 8);
  *(undefined *)(param_1 + 0x2f1a) = uStack50;
  uStack49 = (undefined)uVar1;
  *(undefined *)(param_1 + 0x2f1b) = uStack49;
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xf70) + 0x108);
  local_38 = (undefined)((uint)uVar1 >> 0x18);
  *(undefined *)(param_1 + 0x2f1c) = local_38;
  uStack55 = (undefined)((uint)uVar1 >> 0x10);
  *(undefined *)(param_1 + 0x2f1d) = uStack55;
  uStack54 = (undefined)((uint)uVar1 >> 8);
  *(undefined *)(param_1 + 0x2f1e) = uStack54;
  uStack53 = (undefined)uVar1;
  *(undefined *)(param_1 + 0x2f1f) = uStack53;
  dMeter_magicTransNowInit(param_1);
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x10f8);
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x11a0);
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x11d8);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dMeter_magicMove(sub_meter_class *) */

void dMeter_magicMove(int param_1)

{
  undefined uVar1;
  daNpc_Cb1_c *this;
  undefined4 uVar2;
  daNpc_Md_c *this_00;
  int iVar3;
  undefined2 local_18;
  undefined2 local_16 [5];
  
  if ((*(uint *)(param_1 + 0x3004) & 0x40000) == 0) {
    dMeter_magicGaugeMove();
    if (*(short *)(param_1 + 0x120e) != 0) {
      *(undefined2 *)(param_1 + 0x120e) = 0;
    }
  }
  else {
    local_16[0] = 0x150;
    this = (daNpc_Cb1_c *)
           f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_16);
    uVar1 = daNpc_Cb1_c::m_flying;
    if ((daNpc_Cb1_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpPlayerPartnerActor == this) {
      iVar3 = (int)_m_flyingTimer;
      uVar2 = daNpc_Cb1_c::getMaxFlyingTimer(this);
      dMeter_flyGaugeMove(param_1,uVar1,uVar2,iVar3);
    }
    else {
      local_18 = 0x171;
      this_00 = (daNpc_Md_c *)
                f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_18);
      uVar1 = daNpc_Md_c::m_flying;
      if ((daNpc_Md_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpPlayerPartnerActor == this_00) {
        iVar3 = (int)_m_flyingTimer;
        uVar2 = daNpc_Md_c::getMaxFlyingTimer(this_00);
        dMeter_flyGaugeMove(param_1,uVar1,uVar2,iVar3);
      }
      else {
        dMeter_flyGaugeMove(param_1,0,1,1);
      }
    }
    if (*(short *)(param_1 + 0xfde) == 1) {
      *(undefined2 *)(param_1 + 0xfde) = 0;
    }
    *(undefined2 *)(param_1 + 0x1086) = 1;
  }
  return;
}


/* __stdcall dMeter_magicGaugeMove(sub_meter_class *) */

void dMeter_magicGaugeMove(int param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  short sVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined local_38;
  undefined uStack55;
  undefined uStack54;
  undefined uStack53;
  undefined local_34;
  undefined uStack51;
  undefined uStack50;
  undefined uStack49;
  undefined local_30;
  undefined uStack47;
  undefined uStack46;
  undefined uStack45;
  undefined local_2c;
  undefined uStack43;
  undefined uStack42;
  undefined uStack41;
  undefined local_28;
  undefined uStack39;
  undefined uStack38;
  undefined uStack37;
  undefined local_24;
  undefined uStack35;
  undefined uStack34;
  undefined uStack33;
  undefined local_20;
  undefined uStack31;
  undefined uStack30;
  undefined uStack29;
  undefined local_1c;
  undefined uStack27;
  undefined uStack26;
  undefined uStack25;
  double local_10;
  
  if (init_9202 == '\0') {
    soundOnFlag_9201 = 0;
    init_9202 = '\x01';
  }
  if (*(short *)(param_1 + 0xf6e) == 1) {
    uVar3 = *(undefined4 *)(param_1 + 0x2f08);
    iVar6 = *(int *)(param_1 + 0x11a0);
    local_1c = (undefined)((uint)uVar3 >> 0x18);
    *(undefined *)(iVar6 + 0x104) = local_1c;
    uStack27 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar6 + 0x105) = uStack27;
    uStack26 = (undefined)((uint)uVar3 >> 8);
    *(undefined *)(iVar6 + 0x106) = uStack26;
    uStack25 = (undefined)uVar3;
    *(undefined *)(iVar6 + 0x107) = uStack25;
    uVar3 = *(undefined4 *)(param_1 + 0x2f0c);
    iVar6 = *(int *)(param_1 + 0x11a0);
    local_20 = (undefined)((uint)uVar3 >> 0x18);
    *(undefined *)(iVar6 + 0x108) = local_20;
    uStack31 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar6 + 0x109) = uStack31;
    uStack30 = (undefined)((uint)uVar3 >> 8);
    *(undefined *)(iVar6 + 0x10a) = uStack30;
    uStack29 = (undefined)uVar3;
    *(undefined *)(iVar6 + 0x10b) = uStack29;
    uVar3 = *(undefined4 *)(param_1 + 0x2f08);
    iVar6 = *(int *)(param_1 + 0x1130);
    local_24 = (undefined)((uint)uVar3 >> 0x18);
    *(undefined *)(iVar6 + 0x104) = local_24;
    uStack35 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar6 + 0x105) = uStack35;
    uStack34 = (undefined)((uint)uVar3 >> 8);
    *(undefined *)(iVar6 + 0x106) = uStack34;
    uStack33 = (undefined)uVar3;
    *(undefined *)(iVar6 + 0x107) = uStack33;
    uVar3 = *(undefined4 *)(param_1 + 0x2f0c);
    iVar6 = *(int *)(param_1 + 0x1130);
    local_28 = (undefined)((uint)uVar3 >> 0x18);
    *(undefined *)(iVar6 + 0x108) = local_28;
    uStack39 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar6 + 0x109) = uStack39;
    uStack38 = (undefined)((uint)uVar3 >> 8);
    *(undefined *)(iVar6 + 0x10a) = uStack38;
    uStack37 = (undefined)uVar3;
    *(undefined *)(iVar6 + 0x10b) = uStack37;
    iVar6 = 0;
    iVar11 = 4;
    do {
      uVar3 = *(undefined4 *)(param_1 + 0x2f10);
      iVar8 = param_1 + iVar6;
      iVar7 = *(int *)(iVar8 + 0xf38);
      local_2c = (undefined)((uint)uVar3 >> 0x18);
      *(undefined *)(iVar7 + 0x104) = local_2c;
      uStack43 = (undefined)((uint)uVar3 >> 0x10);
      *(undefined *)(iVar7 + 0x105) = uStack43;
      uStack42 = (undefined)((uint)uVar3 >> 8);
      *(undefined *)(iVar7 + 0x106) = uStack42;
      uStack41 = (undefined)uVar3;
      *(undefined *)(iVar7 + 0x107) = uStack41;
      uVar3 = *(undefined4 *)(param_1 + 0x2f14);
      iVar7 = *(int *)(iVar8 + 0xf38);
      local_30 = (undefined)((uint)uVar3 >> 0x18);
      *(undefined *)(iVar7 + 0x108) = local_30;
      uStack47 = (undefined)((uint)uVar3 >> 0x10);
      *(undefined *)(iVar7 + 0x109) = uStack47;
      uStack46 = (undefined)((uint)uVar3 >> 8);
      *(undefined *)(iVar7 + 0x10a) = uStack46;
      uStack45 = (undefined)uVar3;
      *(undefined *)(iVar7 + 0x10b) = uStack45;
      uVar3 = *(undefined4 *)(param_1 + 0x2f18);
      iVar7 = *(int *)(iVar8 + 0xf70);
      local_34 = (undefined)((uint)uVar3 >> 0x18);
      *(undefined *)(iVar7 + 0x104) = local_34;
      uStack51 = (undefined)((uint)uVar3 >> 0x10);
      *(undefined *)(iVar7 + 0x105) = uStack51;
      uStack50 = (undefined)((uint)uVar3 >> 8);
      *(undefined *)(iVar7 + 0x106) = uStack50;
      uStack49 = (undefined)uVar3;
      *(undefined *)(iVar7 + 0x107) = uStack49;
      uVar3 = *(undefined4 *)(param_1 + 0x2f1c);
      iVar7 = *(int *)(iVar8 + 0xf70);
      local_38 = (undefined)((uint)uVar3 >> 0x18);
      *(undefined *)(iVar7 + 0x108) = local_38;
      uStack55 = (undefined)((uint)uVar3 >> 0x10);
      *(undefined *)(iVar7 + 0x109) = uStack55;
      uStack54 = (undefined)((uint)uVar3 >> 8);
      *(undefined *)(iVar7 + 0x10a) = uStack54;
      uStack53 = (undefined)uVar3;
      *(undefined *)(iVar7 + 0x10b) = uStack53;
      iVar6 = iVar6 + 0x70;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    *(undefined2 *)(param_1 + 0xf6e) = 0;
    dMeter_magicTransScale((double)0_0,(double)0_0,(double)1_0,param_1);
    dMeter_magicInitTrans(param_1);
    dMeter_magicChange((double)((float)((double)CONCAT44(0x43300000,
                                                         (uint)*(ushort *)(param_1 + 0x3016)) -
                                       _4620) / _9165),param_1);
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay._18652_2_ != 0) {
    sVar4 = (ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic +
            d_com_inf_game::g_dComIfG_gameInfo.mPlay._18652_2_;
    if (0x20 < sVar4) {
      sVar4 = 0x20;
    }
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic = (byte)sVar4;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay._18652_2_ = 0;
  }
  bVar1 = *(byte *)(param_1 + 0x3018);
  if ((bVar1 != d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic) ||
     (*(short *)(param_1 + 0xfde) == 0)) {
    if (bVar1 < d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic) {
      *(char *)(param_1 + 0x3018) = *(char *)(param_1 + 0x3018) + '\x01';
    }
    else {
      if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic < bVar1) {
        *(char *)(param_1 + 0x3018) = *(char *)(param_1 + 0x3018) + -1;
      }
    }
    dMeter_magicLength((double)((float)((double)CONCAT44(0x43300000,
                                                         (uint)*(byte *)(param_1 + 0x3018)) - _4620)
                               * _5558),param_1);
    if (*(byte *)(param_1 + 0x3018) ==
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic < 0x11) {
        dMeter_magicLength((double)_4664,param_1);
      }
      else {
        dMeter_magicLength((double)1_0,param_1);
      }
      *(undefined2 *)(param_1 + 0xfde) = 1;
    }
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic != 0) {
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay._18648_2_ != 0) {
      sVar4 = (ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic +
              d_com_inf_game::g_dComIfG_gameInfo.mPlay._18648_2_;
      if (sVar4 < 0) {
        sVar4 = 0;
      }
      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic = (byte)sVar4;
      d_com_inf_game::g_dComIfG_gameInfo.mPlay._18648_2_ = 0;
    }
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic <
      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic) {
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic =
         d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic;
  }
  iVar6 = f_op_overlap_mng::fopOvlpM_IsDoingReq();
  if (iVar6 == 0) {
    if ((*(uint *)(param_1 + 0x3004) & 0x40) != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.field_0xd6 & 0x20;
      }
      if (uVar5 != 0) {
        iVar6 = dEvent_manager_c::checkStartDemo
                          (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr);
        if ((iVar6 != 0) && ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc & 0x2000U) == 0))
        goto LAB_801f95ec;
      }
    }
    uVar10 = (uint)(_9164 * *(float *)(param_1 + 0xf5c) *
                            (float)((double)CONCAT44(0x43300000,
                                                     (uint)d_com_inf_game::g_dComIfG_gameInfo.
                                                           mSvInfo.mSave.mPlayer.mStatusA.mCurrMagic
                                                    ) - _4620));
    uVar5 = *(ushort *)(param_1 + 0x3016);
    uVar9 = (uint)uVar5;
    uVar2 = uVar10 & 0xffff;
    if (uVar9 < uVar2) {
      if ((int)(uVar2 - uVar9) < 0x271) {
        *(short *)(param_1 + 0x3016) = (short)uVar10;
      }
      else {
        *(ushort *)(param_1 + 0x3016) = uVar5 + 0x271;
      }
      uVar10 = *(ushort *)(param_1 + 0x3016) / 0x4e2;
      if ((uint)*(ushort *)(param_1 + 0x3016) == uVar10 * 0x4e2) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x87d,(cXyz *)0x0,uVar10,0,1_0,1_0,_4617,_4617,0);
      }
      local_10 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(param_1 + 0x3016));
      dMeter_magicChange((double)((float)(local_10 - _4620) / _9165),param_1);
      *(undefined2 *)(param_1 + 0x1086) = 1;
    }
    else {
      if (uVar2 < uVar9) {
        if ((int)(uVar9 - uVar2) < 0x271) {
          *(undefined2 *)(param_1 + 0x3016) = 0;
        }
        else {
          *(ushort *)(param_1 + 0x3016) = uVar5 - 0x271;
        }
        if ((uint)*(ushort *)(param_1 + 0x3016) == (*(ushort *)(param_1 + 0x3016) / 0x4e2) * 0x4e2)
        {
          JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x87e,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
        }
        if (*(short *)(param_1 + 0x3016) == 0) {
          JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x881,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
        }
        local_10 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(param_1 + 0x3016));
        dMeter_magicChange((double)((float)(local_10 - _4620) / _9165),param_1);
        *(undefined2 *)(param_1 + 0x1086) = 1;
      }
      else {
        if (*(short *)(param_1 + 0x1086) != 0) {
          local_10 = (double)CONCAT44(0x43300000,uVar9);
          dMeter_magicChange((double)((float)(local_10 - _4620) / _9165),param_1);
          *(undefined2 *)(param_1 + 0x1086) = 0;
        }
      }
    }
  }
  else {
LAB_801f95ec:
    *(undefined2 *)(param_1 + 0x1086) = 1;
  }
  dMeter_magicColor(param_1);
  dMeter_magicAlpha(param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801f99fc) */
/* WARNING: Removing unreachable block (ram,0x801f9a04) */
/* __stdcall dMeter_flyGaugeMove(sub_meter_class *,
                                 unsigned char,
                                 short,
                                 short) */

void dMeter_flyGaugeMove(int param_1,char param_2,short param_3,short param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f30;
  undefined8 in_f31;
  cXyz local_50;
  undefined4 local_40;
  uint uStack60;
  undefined4 local_38;
  uint uStack52;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (param_2 == '\0') {
    if (*(short *)(param_1 + 0x11d6) < 1) {
      dVar6 = (double)0_0;
      *(undefined2 *)(param_1 + 0x11d6) = 0;
      dMeter_magicTransNowInit();
    }
    else {
      *(short *)(param_1 + 0x11d6) = *(short *)(param_1 + 0x11d6) + -1;
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)*(short *)(param_1 + 0x11d6),0);
    }
    if (*(short *)(param_1 + 0x1166) != 0) {
      *(undefined2 *)(param_1 + 0x1166) = 0;
    }
  }
  else {
    dMeter_magicInitTrans();
    uStack60 = (int)param_4 ^ 0x80000000;
    local_40 = 0x43300000;
    uStack52 = (int)param_3 ^ 0x80000000;
    local_38 = 0x43300000;
    dMeter_magicChange((double)(_6057 * _9164 * ((float)((double)CONCAT44(0x43300000,uStack60) -
                                                        _4622) /
                                                (float)((double)CONCAT44(0x43300000,uStack52) -
                                                       _4622))),param_1);
    if (*(short *)(param_1 + 0xf6e) == 0) {
      iVar1 = *(int *)(param_1 + 0x11a0);
      *(undefined *)(iVar1 + 0x104) = 100;
      *(undefined *)(iVar1 + 0x105) = 100;
      *(undefined *)(iVar1 + 0x106) = 0xff;
      *(undefined *)(iVar1 + 0x107) = 0xff;
      iVar1 = *(int *)(param_1 + 0x11a0);
      *(undefined *)(iVar1 + 0x108) = 100;
      *(undefined *)(iVar1 + 0x109) = 100;
      *(undefined *)(iVar1 + 0x10a) = 0xff;
      *(undefined *)(iVar1 + 0x10b) = 0;
      iVar1 = *(int *)(param_1 + 0x1130);
      *(undefined *)(iVar1 + 0x104) = 100;
      *(undefined *)(iVar1 + 0x105) = 100;
      *(undefined *)(iVar1 + 0x106) = 0xff;
      *(undefined *)(iVar1 + 0x107) = 0xff;
      iVar1 = *(int *)(param_1 + 0x1130);
      *(undefined *)(iVar1 + 0x108) = 100;
      *(undefined *)(iVar1 + 0x109) = 100;
      *(undefined *)(iVar1 + 0x10a) = 0xff;
      *(undefined *)(iVar1 + 0x10b) = 0;
      iVar1 = 0;
      iVar4 = 4;
      do {
        iVar3 = param_1 + iVar1;
        iVar2 = *(int *)(iVar3 + 0xf38);
        *(undefined *)(iVar2 + 0x104) = 0x96;
        *(undefined *)(iVar2 + 0x105) = 0x96;
        *(undefined *)(iVar2 + 0x106) = 0xe6;
        *(undefined *)(iVar2 + 0x107) = 0xff;
        iVar2 = *(int *)(iVar3 + 0xf38);
        *(undefined *)(iVar2 + 0x108) = 0x96;
        *(undefined *)(iVar2 + 0x109) = 0x96;
        *(undefined *)(iVar2 + 0x10a) = 0xe6;
        *(undefined *)(iVar2 + 0x10b) = 0;
        iVar2 = *(int *)(iVar3 + 0xf70);
        *(undefined *)(iVar2 + 0x104) = 0xb4;
        *(undefined *)(iVar2 + 0x105) = 0xb4;
        *(undefined *)(iVar2 + 0x106) = 0xff;
        *(undefined *)(iVar2 + 0x107) = 0xff;
        iVar2 = *(int *)(iVar3 + 0xf70);
        *(undefined *)(iVar2 + 0x108) = 0xb4;
        *(undefined *)(iVar2 + 0x109) = 0xb4;
        *(undefined *)(iVar2 + 0x10a) = 0xff;
        *(undefined *)(iVar2 + 0x10b) = 0;
        iVar1 = iVar1 + 0x70;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      *(undefined2 *)(param_1 + 0xf6e) = 1;
      *(undefined2 *)(param_1 + 0xfa6) = 0x14;
      *(undefined2 *)(param_1 + 0x1166) = 0;
    }
    if (*(short *)(param_1 + 0x11d6) < 5) {
      *(short *)(param_1 + 0x11d6) = *(short *)(param_1 + 0x11d6) + 1;
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)*(short *)(param_1 + 0x11d6),0);
    }
    else {
      dVar6 = (double)1_0;
    }
    if (*(short *)(param_1 + 0x1166) < 0x32) {
      *(short *)(param_1 + 0x1166) = *(short *)(param_1 + 0x1166) + 1;
      m_Do_lib::mDoLib_project
                (&((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpPlayerPartnerActor)->parent).parent.
                  mEyePos,&local_50);
      if (*(short *)(param_1 + 0x1166) < 0x1f) {
        dMeter_magicTransScale
                  ((double)(local_50.x - *(float *)(param_1 + 0x11bc)),
                   (double)(local_50.y - *(float *)(param_1 + 0x11c0)),(double)_4664,param_1);
      }
      else {
        dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                  (0x14,0x32 - *(short *)(param_1 + 0x1166),0);
        dVar8 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                  (0x14,*(short *)(param_1 + 0x1166) + -0x1e,0);
        dMeter_magicTransScale
                  ((double)(float)(dVar7 * (double)(local_50.x - *(float *)(param_1 + 0x11bc))),
                   (double)(float)(dVar7 * (double)(local_50.y - *(float *)(param_1 + 0x11c0))),
                   (double)(float)((double)_4664 + (double)(float)((double)_4664 * dVar8)),param_1);
      }
    }
  }
  *(float *)(param_1 + 0x2fc0) = (float)dVar6;
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801f9b1c) */
/* __stdcall dMeter_magicChange(sub_meter_class *,
                                float) */

void dMeter_magicChange(double param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18650_2_ =
       (undefined2)(int)(_9619 * (float)(param_1 / (double)*(float *)(param_2 + 0xf5c)));
  dMeter_magicTransNowInit();
  iVar1 = 0;
  iVar3 = 0;
  do {
    iVar2 = param_2 + iVar3;
    if (param_1 < (double)*(float *)(iVar2 + 0xf5c)) {
      if ((double)0_0 < param_1) {
        (**(code **)(**(int **)(iVar2 + 0xf38) + 0x18))(param_1,(double)*(float *)(iVar2 + 0xf60));
        *(undefined *)(*(int *)(iVar2 + 0xf38) + 0xaa) = 1;
        param_1 = (double)0_0;
      }
      else {
        f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(iVar2 + 0xf38),1_0);
        *(undefined *)(*(int *)(iVar2 + 0xf38) + 0xaa) = 0;
      }
    }
    else {
      f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(iVar2 + 0xf38),1_0);
      *(undefined *)(*(int *)(iVar2 + 0xf38) + 0xaa) = 1;
      param_1 = (double)(float)(param_1 - (double)*(float *)(iVar2 + 0xf5c));
    }
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 8);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801f9bf4) */
/* __stdcall dMeter_magicTransNowInit(sub_meter_class *) */

void dMeter_magicTransNowInit(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double y;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar1 = 0_0;
  if ((ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp < 0x2c) {
    fVar1 = _9645;
  }
  y = (double)fVar1;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_1 + 0x10f8),
             (double)(*(float *)(param_1 + 0x1114) - *(float *)(param_1 + 0x110c)),y);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_1 + 0x11a0),
             (double)(*(float *)(param_1 + 0x11bc) - *(float *)(param_1 + 0x11b4)),y);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_1 + 0x11d8),
             (double)(*(float *)(param_1 + 0x11f4) - *(float *)(param_1 + 0x11ec)),y);
  iVar3 = 0;
  iVar4 = 0;
  do {
    iVar2 = param_1 + iVar4;
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(iVar2 + 0xf38),
               (double)(*(float *)(iVar2 + 0xf54) - *(float *)(iVar2 + 0xf4c)),y);
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar3 < 8);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801f9cac) */
/* __stdcall dMeter_magicInitTrans(sub_meter_class *) */

void dMeter_magicInitTrans(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f31;
  double y;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar1 = 0_0;
  if ((ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp < 0x2c) {
    fVar1 = _9645;
  }
  y = (double)fVar1;
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x10f8),(double)0_0,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x11a0),(double)0_0,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x11d8),(double)0_0,y);
  iVar2 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + iVar3 + 0xf38),(double)0_0,y);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 8);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801f9ef0) */
/* WARNING: Removing unreachable block (ram,0x801f9ee0) */
/* WARNING: Removing unreachable block (ram,0x801f9ee8) */
/* WARNING: Removing unreachable block (ram,0x801f9ef8) */
/* __stdcall dMeter_magicTransScale(sub_meter_class *,
                                    float,
                                    float,
                                    float) */

void dMeter_magicTransScale(double param_1,double param_2,double param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f28;
  double dVar5;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  if ((ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp < 0x2c) {
    param_2 = (double)(float)(param_2 + (double)_9645);
  }
  f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(param_4 + 0x11a0),(float)param_3);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_4 + 0x11a0),param_1,param_2);
  *(float *)(param_4 + 0x114c) = (float)((double)*(float *)(param_4 + 0x1144) * param_3);
  *(float *)(param_4 + 0x1150) = (float)((double)*(float *)(param_4 + 0x1148) * param_3);
  f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(param_4 + 0x1130),(float)param_3);
  *(float *)(param_4 + 0x1114) =
       (float)(param_1 +
              (double)(*(float *)(param_4 + 0x11b4) +
                      (float)(param_3 *
                             (double)(*(float *)(param_4 + 0x110c) - *(float *)(param_4 + 0x11b4))))
              );
  *(float *)(param_4 + 0x1118) =
       (float)(param_2 +
              (double)(*(float *)(param_4 + 0x11b8) +
                      (float)(param_3 *
                             (double)(*(float *)(param_4 + 0x1110) - *(float *)(param_4 + 0x11b8))))
              );
  f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(param_4 + 0x10f8),(float)param_3);
  *(float *)(param_4 + 0x11f4) =
       (float)(param_1 +
              (double)(*(float *)(param_4 + 0x11b4) +
                      (float)(param_3 *
                             (double)(*(float *)(param_4 + 0x11ec) - *(float *)(param_4 + 0x11b4))))
              );
  *(float *)(param_4 + 0x11f8) =
       (float)(param_2 +
              (double)(*(float *)(param_4 + 0x11b8) +
                      (float)(param_3 *
                             (double)(*(float *)(param_4 + 0x11f0) - *(float *)(param_4 + 0x11b8))))
              );
  f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(param_4 + 0x11d8),(float)param_3);
  *(float *)(param_4 + 0x1184) = (float)((double)*(float *)(param_4 + 0x117c) * param_3);
  *(float *)(param_4 + 0x1188) = (float)((double)*(float *)(param_4 + 0x1180) * param_3);
  f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(param_4 + 0x1168),(float)param_3);
  iVar1 = 0;
  iVar3 = 0;
  dVar5 = (double)_4664;
  do {
    iVar2 = param_4 + iVar3;
    *(float *)(iVar2 + 0xf54) =
         (float)(param_1 +
                (double)(*(float *)(param_4 + 0x11b4) +
                        (float)(param_3 *
                               (double)(*(float *)(iVar2 + 0xf4c) - *(float *)(param_4 + 0x11b4)))))
    ;
    *(float *)(iVar2 + 0xf58) =
         (float)(param_2 +
                (double)(*(float *)(param_4 + 0x11b8) +
                        (float)(param_3 *
                               (double)(*(float *)(iVar2 + 0xf50) - *(float *)(param_4 + 0x11b8)))))
    ;
    *(float *)(iVar2 + 0xf54) =
         *(float *)(iVar2 + 0xf54) -
         (float)((double)(float)((double)*(float *)(iVar2 + 0xf5c) * param_3) * dVar5);
    *(float *)(iVar2 + 0xf64) =
         (float)(param_3 *
                (double)(*(float *)(*(int *)(iVar2 + 0xf38) + 0x14) -
                        *(float *)(*(int *)(iVar2 + 0xf38) + 0xc)));
    *(float *)(iVar2 + 0xf68) =
         (float)(param_3 *
                (double)(*(float *)(*(int *)(iVar2 + 0xf38) + 0x18) -
                        *(float *)(*(int *)(iVar2 + 0xf38) + 0x10)));
    *(float *)(iVar2 + 0xf54) =
         *(float *)(iVar2 + 0xf54) + (float)((double)*(float *)(iVar2 + 0xf64) * dVar5);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar2 + 0xf38));
    *(undefined4 *)(iVar2 + 0xf64) = *(undefined4 *)(iVar2 + 0xf5c);
    *(undefined4 *)(iVar2 + 0xf68) = *(undefined4 *)(iVar2 + 0xf60);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 8);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  return;
}


/* __stdcall dMeter_magicColor(sub_meter_class *) */

void dMeter_magicColor(int param_1)

{
  undefined uVar1;
  undefined uVar2;
  undefined uVar4;
  undefined uVar5;
  undefined uVar6;
  undefined uVar7;
  undefined4 uVar3;
  uint uVar8;
  int iVar9;
  char cVar10;
  double dVar11;
  undefined local_c8;
  undefined uStack199;
  undefined uStack198;
  undefined uStack197;
  undefined local_c4;
  undefined uStack195;
  undefined uStack194;
  undefined uStack193;
  undefined local_c0;
  undefined uStack191;
  undefined uStack190;
  undefined uStack189;
  undefined local_bc;
  undefined uStack187;
  undefined uStack186;
  undefined uStack185;
  
  uVar8 = *(uint *)(param_1 + 0x3004);
  if ((((((uVar8 & 8) == 0) && ((uVar8 & 0x10) == 0)) && ((uVar8 & 0x800000) == 0)) &&
      ((uVar8 & 0x100) == 0)) &&
     (((((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x2a0 & 1) !=
         0 || ((d_com_inf_game::g_dComIfG_gameInfo._23557_1_ & 1) != 0)) ||
       ((iVar9 = daPy_lk_c::checkCutRollChange(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)
        , iVar9 != 0 || ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc & 0x20U) != 0)))) ||
      ((((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x1000U) != 0 &&
        (cVar10 = daArrow_c::getKeepType((daArrow_c *)&d_com_inf_game::g_dComIfG_gameInfo),
        cVar10 != '\0')) &&
       (iVar9 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->vtbl->
                          getItemID)(), iVar9 != -1)))))) {
    if (*(short *)(param_1 + 0x104e) == 0) {
      *(undefined2 *)(param_1 + 0x104e) = 1;
    }
    if (*(short *)(param_1 + 0x1016) < 0x1d) {
      *(short *)(param_1 + 0x1016) = *(short *)(param_1 + 0x1016) + 1;
    }
    else {
      *(undefined2 *)(param_1 + 0x1016) = 0;
    }
    iVar9 = (int)*(short *)(param_1 + 0x1016);
    if (iVar9 < 0xf) {
      dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0xf,iVar9,0);
    }
    else {
      dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0xf,0x1e - iVar9,0);
    }
    uVar1 = (undefined)
            (int)((float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2f08)) - _4620) -
                 (float)((double)((float)((double)CONCAT44(0x43300000,
                                                           (uint)*(byte *)(param_1 + 0x2f08)) -
                                         _4620) - _4616) * dVar11));
    uVar4 = (undefined)
            (int)((float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2f09)) - _4620) -
                 (float)((double)((float)((double)CONCAT44(0x43300000,
                                                           (uint)*(byte *)(param_1 + 0x2f09)) -
                                         _4620) - _4616) * dVar11));
    uVar5 = (undefined)
            (int)((float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2f0a)) - _4620) -
                 (float)((double)((float)((double)CONCAT44(0x43300000,
                                                           (uint)*(byte *)(param_1 + 0x2f0a)) -
                                         _4620) - _4616) * dVar11));
    uVar2 = (undefined)
            (int)((float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2f0c)) - _4620) -
                 (float)((double)((float)((double)CONCAT44(0x43300000,
                                                           (uint)*(byte *)(param_1 + 0x2f0c)) -
                                         _4620) - _4616) * dVar11));
    uVar6 = (undefined)
            (int)((float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2f0d)) - _4620) -
                 (float)((double)((float)((double)CONCAT44(0x43300000,
                                                           (uint)*(byte *)(param_1 + 0x2f0d)) -
                                         _4620) - _4616) * dVar11));
    uVar7 = (undefined)
            (int)((float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2f0e)) - _4620) -
                 (float)((double)((float)((double)CONCAT44(0x43300000,
                                                           (uint)*(byte *)(param_1 + 0x2f0e)) -
                                         _4620) - _4616) * dVar11));
    iVar9 = *(int *)(param_1 + 0x11a0);
    *(undefined *)(iVar9 + 0x104) = uVar1;
    *(undefined *)(iVar9 + 0x105) = uVar4;
    *(undefined *)(iVar9 + 0x106) = uVar5;
    *(undefined *)(iVar9 + 0x107) = 0xff;
    iVar9 = *(int *)(param_1 + 0x11a0);
    *(undefined *)(iVar9 + 0x108) = uVar2;
    *(undefined *)(iVar9 + 0x109) = uVar6;
    *(undefined *)(iVar9 + 0x10a) = uVar7;
    *(undefined *)(iVar9 + 0x10b) = 0;
    iVar9 = *(int *)(param_1 + 0x1130);
    *(undefined *)(iVar9 + 0x104) = uVar1;
    *(undefined *)(iVar9 + 0x105) = uVar4;
    *(undefined *)(iVar9 + 0x106) = uVar5;
    *(undefined *)(iVar9 + 0x107) = 0xff;
    iVar9 = *(int *)(param_1 + 0x1130);
    *(undefined *)(iVar9 + 0x108) = uVar2;
    *(undefined *)(iVar9 + 0x109) = uVar6;
    *(undefined *)(iVar9 + 0x10a) = uVar7;
    *(undefined *)(iVar9 + 0x10b) = 0;
    d_com_inf_game::g_dComIfG_gameInfo._23557_1_ =
         d_com_inf_game::g_dComIfG_gameInfo._23557_1_ & 0xfe;
    return;
  }
  if (*(short *)(param_1 + 0x104e) == 1) {
    uVar3 = *(undefined4 *)(param_1 + 0x2f08);
    iVar9 = *(int *)(param_1 + 0x11a0);
    local_bc = (undefined)((uint)uVar3 >> 0x18);
    *(undefined *)(iVar9 + 0x104) = local_bc;
    uStack187 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar9 + 0x105) = uStack187;
    uStack186 = (undefined)((uint)uVar3 >> 8);
    *(undefined *)(iVar9 + 0x106) = uStack186;
    uStack185 = (undefined)uVar3;
    *(undefined *)(iVar9 + 0x107) = uStack185;
    uVar3 = *(undefined4 *)(param_1 + 0x2f0c);
    iVar9 = *(int *)(param_1 + 0x11a0);
    local_c0 = (undefined)((uint)uVar3 >> 0x18);
    *(undefined *)(iVar9 + 0x108) = local_c0;
    uStack191 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar9 + 0x109) = uStack191;
    uStack190 = (undefined)((uint)uVar3 >> 8);
    *(undefined *)(iVar9 + 0x10a) = uStack190;
    uStack189 = (undefined)uVar3;
    *(undefined *)(iVar9 + 0x10b) = uStack189;
    uVar3 = *(undefined4 *)(param_1 + 0x2f08);
    iVar9 = *(int *)(param_1 + 0x1130);
    local_c4 = (undefined)((uint)uVar3 >> 0x18);
    *(undefined *)(iVar9 + 0x104) = local_c4;
    uStack195 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar9 + 0x105) = uStack195;
    uStack194 = (undefined)((uint)uVar3 >> 8);
    *(undefined *)(iVar9 + 0x106) = uStack194;
    uStack193 = (undefined)uVar3;
    *(undefined *)(iVar9 + 0x107) = uStack193;
    uVar3 = *(undefined4 *)(param_1 + 0x2f0c);
    iVar9 = *(int *)(param_1 + 0x1130);
    local_c8 = (undefined)((uint)uVar3 >> 0x18);
    *(undefined *)(iVar9 + 0x108) = local_c8;
    uStack199 = (undefined)((uint)uVar3 >> 0x10);
    *(undefined *)(iVar9 + 0x109) = uStack199;
    uStack198 = (undefined)((uint)uVar3 >> 8);
    *(undefined *)(iVar9 + 0x10a) = uStack198;
    uStack197 = (undefined)uVar3;
    *(undefined *)(iVar9 + 0x10b) = uStack197;
    *(undefined2 *)(param_1 + 0x104e) = 0;
  }
  return;
}


/* __stdcall dMeter_magicAlpha(sub_meter_class *) */

void dMeter_magicAlpha(int param_1)

{
  short sVar1;
  ushort uVar2;
  char cVar5;
  uint uVar3;
  int iVar4;
  double dVar6;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic != 0) {
    if ((*(uint *)(param_1 + 0x3004) & 0x4000) == 0) {
      if ((*(uint *)(param_1 + 0x3004) & 0x40) != 0) {
        if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.field_0xd6 & 0x20;
        }
        if ((uVar2 != 0) && ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc & 0x2000U) == 0))
        goto LAB_801fa488;
      }
      cVar5 = dMenu_getCollectMode();
      if (cVar5 != '\x04') {
        uVar3 = *(uint *)(param_1 + 0x3004);
        if ((uVar3 & 0x200000) == 0) {
          if ((uVar3 & 0x80) == 0) {
            if ((uVar3 & 0x100000) == 0) {
              if ((uVar3 & 0x20000) == 0) {
                if (((uVar3 & 0x20) == 0) && ((uVar3 & 0x80000) == 0)) {
                  cVar5 = dMeter_isAuctionFlag();
                  if (cVar5 == '\0') {
                    if (((*(uint *)(param_1 + 0x3004) & 0x400000) == 0) &&
                       ((*(uint *)(param_1 + 0x3004) & 0x800000) == 0)) {
                      iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.
                                         mStageName,"Ojhous");
                      if (iVar4 == 0) {
                        if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda == 6) goto LAB_801fa488;
                      }
                      if (((*(uint *)(param_1 + 0x3004) & 8) == 0) &&
                         ((*(uint *)(param_1 + 0x3004) & 0x10) == 0)) {
                        if (*(short *)(param_1 + 0x112e) < 5) {
                          *(short *)(param_1 + 0x112e) = *(short *)(param_1 + 0x112e) + 1;
                        }
                        else {
                          *(undefined2 *)(param_1 + 0x112e) = 5;
                        }
                      }
                      else {
                        sVar1 = *(short *)(param_1 + 0x112e);
                        if (sVar1 < 3) {
                          *(short *)(param_1 + 0x112e) = sVar1 + 1;
                        }
                        else {
                          if (sVar1 < 4) {
                            *(undefined2 *)(param_1 + 0x112e) = 3;
                          }
                          else {
                            *(short *)(param_1 + 0x112e) = sVar1 + -1;
                          }
                        }
                      }
                      goto LAB_801fa514;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_801fa488:
  if (*(short *)(param_1 + 0x112e) < 1) {
    *(undefined2 *)(param_1 + 0x112e) = 0;
  }
  else {
    *(short *)(param_1 + 0x112e) = *(short *)(param_1 + 0x112e) + -1;
  }
LAB_801fa514:
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,(int)*(short *)(param_1 + 0x112e),0);
  *(float *)(param_1 + 0x2fc0) = (float)dVar6;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801fa648) */
/* WARNING: Removing unreachable block (ram,0x801fa650) */
/* __stdcall dMeter_gaugeAlpha(sub_meter_class *) */

void dMeter_gaugeAlpha(int param_1)

{
  double dVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar6 = (double)*(float *)(param_1 + 0x2fbc);
  dVar5 = (double)*(float *)(param_1 + 0x2fc0);
  iVar2 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + iVar3 + 0x640),(float)dVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + iVar3 + 0xaa0),(float)dVar6);
    dVar1 = _4620;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 0x14);
  *(char *)(param_1 + 0xf35) =
       (char)(int)((double)(float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0xf35)) -
                                  _4620) * dVar6);
  *(char *)(*(int *)(param_1 + 0xf00) + 0xac) =
       (char)(int)((double)(float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0xf35)) -
                                  dVar1) * dVar6);
  iVar2 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + iVar3 + 0xf38),(float)dVar5);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar2 < 8);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x10f8),(float)dVar5);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x11a0),(float)dVar5);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x11d8),(float)dVar5);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return;
}


/* __stdcall dMeter_menuInit(sub_meter_class *) */

void dMeter_menuInit(int param_1)

{
  undefined2 uVar1;
  
  *(undefined2 *)(param_1 + 0x286) = 10;
  *(undefined2 *)(param_1 + 0x2be) = 0;
  *(undefined2 *)(param_1 + 0x2f6) = 0;
  uVar1 = dSv_memBit_c::isDungeonItem
                    ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1);
  *(undefined2 *)(param_1 + 0x136) = uVar1;
  return;
}


/* __stdcall dMeter_menuMove(sub_meter_class *) */

void dMeter_menuMove(undefined4 param_1)

{
  dMeter_menuLRMove();
  dMeter_menuPlusMove(param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801fa8f0) */
/* WARNING: Removing unreachable block (ram,0x801fa8f8) */
/* __stdcall dMeter_menuLRMove(sub_meter_class *) */

void dMeter_menuLRMove(int param_1)

{
  short sVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (init_9917 == '\0') {
    frame_9916 = dMenu_getPushMenuButton();
    init_9917 = '\x01';
  }
  if (((*(uint *)(param_1 + 0x3004) & 0x200000) == 0) &&
     (cVar2 = dMenu_getCollectMode(), cVar2 != '\x05')) {
    sVar5 = 0x14;
    cVar2 = dMenu_getPushMenuButton();
    if (frame_9916 != cVar2) {
      if ((frame_9916 == '\0') || (cVar2 = dMenu_getPushMenuButton(), cVar2 == '\0')) {
        *(undefined2 *)(param_1 + 0x2be) = 0;
      }
      else {
        sVar5 = (short)((int)DAT_803e6afe << 1);
        *(short *)(param_1 + 0x286) = sVar5;
        *(undefined2 *)(param_1 + 0x2be) = 1;
      }
      frame_9916 = dMenu_getPushMenuButton();
    }
    iVar4 = (int)(short)((int)sVar5 >> 1);
    cVar2 = dMenu_getPushMenuButton();
    if (cVar2 == '\0') {
      sVar1 = *(short *)(param_1 + 0x286);
      if (sVar1 < iVar4) {
        *(short *)(param_1 + 0x286) = sVar1 + 1;
      }
      else {
        if (iVar4 < sVar1) {
          *(short *)(param_1 + 0x286) = sVar1 + -1;
        }
      }
    }
    else {
      if (*(short *)(param_1 + 0x286) != 0) {
        *(short *)(param_1 + 0x286) = *(short *)(param_1 + 0x286) + -1;
      }
    }
    iVar3 = (int)*(short *)(param_1 + 0x286);
    if (iVar4 < iVar3) {
      dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar4,sVar5 - iVar3,0);
      if (*(short *)(param_1 + 0x2be) == 0) {
        dVar8 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                  (iVar4,*(short *)(param_1 + 0x286) - iVar4,0);
      }
      else {
        dVar8 = (double)1_0;
      }
    }
    else {
      dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar4,iVar3,0);
      if (*(short *)(param_1 + 0x2be) == 0) {
        dVar8 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                  (iVar4,iVar4 - *(short *)(param_1 + 0x286),0);
      }
      else {
        dVar8 = (double)1_0;
      }
    }
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(param_1 + 0x250),(double)(float)((double)_9956 * dVar7),
               (double)0_0);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(param_1 + 0x288),(double)(float)((double)_9957 * dVar7),
               (double)0_0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x250),(float)dVar8);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x288),(float)dVar8);
  }
  else {
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x250));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x288));
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x801fbb00) */
/* WARNING: Removing unreachable block (ram,0x801fbaf0) */
/* WARNING: Removing unreachable block (ram,0x801fbaf8) */
/* WARNING: Removing unreachable block (ram,0x801fbb08) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dMeter_menuPlusMove(sub_meter_class *) */

void dMeter_menuPlusMove(int param_1)

{
  float fVar1;
  ushort uVar2;
  dMap_c *this;
  char cVar7;
  undefined2 uVar6;
  int iVar3;
  dComIfG_inf_c *this_00;
  cXyz *pcVar4;
  int *piVar5;
  byte bVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined8 in_f28;
  double dVar13;
  undefined8 in_f29;
  double dVar14;
  undefined8 in_f30;
  double dVar15;
  undefined8 in_f31;
  double x;
  float local_98 [7];
  uint uStack124;
  undefined4 local_78;
  uint uStack116;
  undefined4 local_70;
  uint uStack108;
  undefined4 local_68;
  uint uStack100;
  double local_60;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  if (init_9963 == '\0') {
    moveFlag_9962 = 0;
    init_9963 = '\x01';
  }
  if (init_9966 == '\0') {
    moveStatus_9965 = 0;
    init_9966 = '\x01';
  }
  local_98[3] = (float)_9968;
  local_98[4] = (float)DAT_80361154;
  local_98[5] = (float)DAT_80361158;
  local_98[0] = _9969;
  local_98[1] = (float)DAT_80361160;
  local_98[2] = (float)DAT_80361164;
  this = (dMap_c *)
         dSv_memBit_c::isDungeonItem
                   ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1);
  if (*(short *)(param_1 + 0x136) != (short)this) {
    if (dMeter_mMapCtrlDisp == (mapCtrlDisp_c)0x0) {
      cVar7 = dMap_c::isEnableDispMap(this);
      if (cVar7 != '\0') {
        dMeter_mMapCtrlDisp = (mapCtrlDisp_c)0x1;
        uRam803f70c9 = 0;
      }
      *(undefined *)(param_1 + 0x3029) = 1;
    }
    *(undefined *)(param_1 + 0x3027) = 0;
    uVar6 = dSv_memBit_c::isDungeonItem
                      ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1);
    *(undefined2 *)(param_1 + 0x136) = uVar6;
  }
  if (((*(uint *)(param_1 + 0x3004) & 0x4000) == 0) &&
     (iVar3 = f_op_overlap_mng::fopOvlpM_IsDoingReq(), iVar3 == 0)) {
    uVar9 = *(uint *)(param_1 + 0x3004);
    if ((uVar9 & 0x40) != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.field_0xd6 & 0x100;
      }
      if (uVar2 != 0) goto LAB_801fabbc;
    }
    if ((((((((((uVar9 & 0x200000) != 0) || ((uVar9 & 0x100) != 0)) || ((uVar9 & 0x80) != 0)) ||
            (((uVar9 & 0x100000) != 0 || ((uVar9 & 0x20000) != 0)))) || ((uVar9 & 8) != 0)) ||
          ((((uVar9 & 0x10) != 0 || ((uVar9 & 0x800000) != 0)) ||
           (((uVar9 & 0x20) != 0 ||
            ((((uVar9 & 0x80000) != 0 || ((uVar9 & 0x800) != 0)) || ((uVar9 & 0x1000) != 0))))))))
         || ((((uVar9 & 0x400) == 0 &&
              (iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                                 ((char *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage,
                                  "MajyuE"), iVar3 == 0)) &&
             (iVar3 = dSv_event_c::isEventBit
                                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x801),
             iVar3 == 0)))) ||
        (((*(uint *)(param_1 + 0x3004) & 0x400) == 0 &&
         (((iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                              ((char *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage,"Hyrule"
                              ), iVar3 == 0 ||
           (iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                              ((char *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage,"Hyroom"
                              ), iVar3 == 0)) ||
          (iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                             ((char *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage,"kenroom"
                             ), iVar3 == 0)))))) ||
       ((this_00 = &d_com_inf_game::g_dComIfG_gameInfo,
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda == 1 ||
        (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda == 6)))) goto LAB_801fabbc;
    cVar7 = *(char *)(param_1 + 0x3020);
    if ((cVar7 == '\x01') || (cVar7 == '\x02')) {
      if ((dMeter_mMapCtrlDisp == (mapCtrlDisp_c)0x0) ||
         (this_00 = (dComIfG_inf_c *)
                    dMap_c::isEnableDispMap((dMap_c *)&d_com_inf_game::g_dComIfG_gameInfo),
         ((uint)this_00 & 0xff) == 0)) {
        cVar7 = dMap_c::isEnableDispMap((dMap_c *)this_00);
        if (cVar7 == '\0') {
          if (((*(uint *)(param_1 + 0x3004) & 0x400) == 0) ||
             (iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                                getStagInfo)(), *(byte *)(iVar3 + 9) >> 1 == 5)) {
            if (moveStatus_9965 != 6) {
              moveFlag_9962 = 1;
            }
            moveStatus_9965 = 6;
          }
          else {
            if (moveStatus_9965 != 7) {
              moveFlag_9962 = 1;
            }
            moveStatus_9965 = 7;
          }
        }
        else {
          if (moveStatus_9965 != 3) {
            moveFlag_9962 = 1;
          }
          moveStatus_9965 = 3;
        }
      }
      else {
        if (moveStatus_9965 != 2) {
          moveFlag_9962 = 1;
        }
        moveStatus_9965 = 2;
      }
    }
    else {
      if (((cVar7 == '\x05') || (cVar7 == '\t')) || (cVar7 == '\x03')) {
        if (moveStatus_9965 != 4) {
          moveFlag_9962 = 1;
        }
        moveStatus_9965 = 4;
      }
      else {
        if (moveStatus_9965 != 5) {
          moveFlag_9962 = 1;
        }
        moveStatus_9965 = 5;
      }
    }
  }
  else {
LAB_801fabbc:
    if (moveStatus_9965 != 1) {
      moveFlag_9962 = 1;
    }
    moveStatus_9965 = 1;
  }
  if (moveFlag_9962 != 0) {
    if (*(short *)(param_1 + 0x2f6) < 5) {
      *(short *)(param_1 + 0x2f6) = *(short *)(param_1 + 0x2f6) + 1;
    }
    else {
      *(undefined2 *)(param_1 + 0x2f6) = 5;
    }
    if (moveStatus_9965 == 5) {
      uStack116 = (int)DAT_803e69a4 ^ 0x80000000;
      local_78 = 0x43300000;
      x = (double)(float)((double)CONCAT44(0x43300000,uStack116) - _4622);
      uStack124 = (int)DAT_803e69a6 ^ 0x80000000;
      local_98[6] = 176.0;
      dVar15 = (double)(float)((double)CONCAT44(0x43300000,uStack124) - _4622);
      *(undefined *)(*(int *)(param_1 + 0x2c0) + 0xaa) = 0;
      iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727931);
      *(undefined *)(iVar3 + 0xaa) = 0;
      iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727933);
      *(undefined *)(iVar3 + 0xaa) = 0;
      *(undefined *)(*(int *)(param_1 + 0x100) + 0xaa) = 0;
      iVar3 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x908);
      if (((iVar3 == 0) ||
          (iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                             getStagInfo)(), (*(ushort *)(iVar3 + 10) & 3) != 0)) &&
         ((iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                             getStagInfo)(), (*(ushort *)(iVar3 + 10) & 3) != 1 ||
          ((*(uint *)(param_1 + 0x3004) & 0x400000) != 0)))) {
        *(undefined *)(*(int *)(param_1 + 0x138) + 0xaa) = 0;
      }
      else {
        *(undefined *)(*(int *)(param_1 + 0x138) + 0xaa) = 1;
      }
      *(undefined *)(*(int *)(param_1 + 0x170) + 0xaa) = 1;
      moveFlag_9962 = 0;
      goto LAB_801fb774;
    }
    if (moveStatus_9965 < 5) {
      if (moveStatus_9965 == 3) {
        uStack116 = (int)DAT_803e69a4 ^ 0x80000000;
        local_78 = 0x43300000;
        x = (double)(float)((double)CONCAT44(0x43300000,uStack116) - _4622);
        uStack124 = (int)DAT_803e69a6 ^ 0x80000000;
        local_98[6] = 176.0;
        dVar15 = (double)(float)((double)CONCAT44(0x43300000,uStack124) - _4622);
        *(undefined *)(*(int *)(param_1 + 0x2c0) + 0xaa) = 1;
        iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727931);
        *(undefined *)(iVar3 + 0xaa) = 1;
        *(undefined *)(*(int *)(param_1 + 0x100) + 0xaa) = 0;
        iVar3 = dSv_event_c::isEventBit
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x908);
        if (((iVar3 == 0) ||
            (iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                               getStagInfo)(), (*(ushort *)(iVar3 + 10) & 3) != 0)) &&
           ((iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                               getStagInfo)(), (*(ushort *)(iVar3 + 10) & 3) != 1 ||
            ((*(uint *)(param_1 + 0x3004) & 0x400000) != 0)))) {
          *(undefined *)(*(int *)(param_1 + 0x138) + 0xaa) = 0;
          iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727933);
          *(undefined *)(iVar3 + 0xaa) = 0;
        }
        else {
          *(undefined *)(*(int *)(param_1 + 0x138) + 0xaa) = 1;
          iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727933);
          *(undefined *)(iVar3 + 0xaa) = 1;
        }
        *(undefined *)(*(int *)(param_1 + 0x170) + 0xaa) = 0;
        moveFlag_9962 = 0;
        goto LAB_801fb774;
      }
      if (2 < moveStatus_9965) {
        uStack116 = (int)DAT_803e69a4 + 0x52U ^ 0x80000000;
        local_78 = 0x43300000;
        x = (double)(float)((double)CONCAT44(0x43300000,uStack116) - _4622);
        uStack124 = (int)DAT_803e69a6 ^ 0x80000000;
        local_98[6] = 176.0;
        dVar15 = (double)(float)((double)CONCAT44(0x43300000,uStack124) - _4622);
        *(undefined *)(*(int *)(param_1 + 0x2c0) + 0xaa) = 1;
        iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727931);
        *(undefined *)(iVar3 + 0xaa) = 1;
        iVar3 = dSv_event_c::isEventBit
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x908);
        if (((iVar3 == 0) ||
            (iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                               getStagInfo)(), (*(ushort *)(iVar3 + 10) & 3) != 0)) &&
           ((iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                               getStagInfo)(), (*(ushort *)(iVar3 + 10) & 3) != 1 ||
            ((*(uint *)(param_1 + 0x3004) & 0x400000) != 0)))) {
          iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727933);
          *(undefined *)(iVar3 + 0xaa) = 0;
        }
        else {
          iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727933);
          *(undefined *)(iVar3 + 0xaa) = 1;
        }
        *(undefined *)(*(int *)(param_1 + 0x100) + 0xaa) = 0;
        *(undefined *)(*(int *)(param_1 + 0x138) + 0xaa) = 0;
        *(undefined *)(*(int *)(param_1 + 0x170) + 0xaa) = 0;
        moveFlag_9962 = 0;
        goto LAB_801fb774;
      }
      if (1 < moveStatus_9965) {
        uStack124 = (int)DAT_803e69a4 ^ 0x80000000;
        local_98[6] = 176.0;
        x = (double)(float)((double)CONCAT44(0x43300000,uStack124) - _4622);
        uStack116 = (int)DAT_803e69a6 ^ 0x80000000;
        local_78 = 0x43300000;
        dVar15 = (double)(float)((double)CONCAT44(0x43300000,uStack116) - _4622);
        *(undefined *)(*(int *)(param_1 + 0x2c0) + 0xaa) = 0;
        iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727931);
        *(undefined *)(iVar3 + 0xaa) = 0;
        iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727933);
        *(undefined *)(iVar3 + 0xaa) = 0;
        *(undefined *)(*(int *)(param_1 + 0x100) + 0xaa) = 1;
        iVar3 = dSv_event_c::isEventBit
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x908);
        if (((iVar3 == 0) ||
            (iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                               getStagInfo)(), (*(ushort *)(iVar3 + 10) & 3) != 0)) &&
           ((iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                               getStagInfo)(), (*(ushort *)(iVar3 + 10) & 3) != 1 ||
            ((*(uint *)(param_1 + 0x3004) & 0x400000) != 0)))) {
          *(undefined *)(*(int *)(param_1 + 0x138) + 0xaa) = 0;
        }
        else {
          *(undefined *)(*(int *)(param_1 + 0x138) + 0xaa) = 1;
        }
        *(undefined *)(*(int *)(param_1 + 0x170) + 0xaa) = 1;
        moveFlag_9962 = 0;
        goto LAB_801fb774;
      }
    }
    else {
      if (moveStatus_9965 == 7) {
        uStack116 = (int)DAT_803e69a4 ^ 0x80000000;
        local_78 = 0x43300000;
        x = (double)(float)((double)CONCAT44(0x43300000,uStack116) - _4622);
        uStack124 = (int)DAT_803e69a6 ^ 0x80000000;
        local_98[6] = 176.0;
        dVar15 = (double)(float)((double)CONCAT44(0x43300000,uStack124) - _4622);
        iVar3 = dSv_event_c::isEventBit
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x908);
        if (((iVar3 == 0) ||
            (iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                               getStagInfo)(), (*(ushort *)(iVar3 + 10) & 3) != 0)) &&
           ((iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                               getStagInfo)(), (*(ushort *)(iVar3 + 10) & 3) != 1 ||
            ((*(uint *)(param_1 + 0x3004) & 0x400000) != 0)))) {
          *(undefined *)(*(int *)(param_1 + 0x2c0) + 0xaa) = 0;
          iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727931);
          *(undefined *)(iVar3 + 0xaa) = 1;
          iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727933);
          *(undefined *)(iVar3 + 0xaa) = 0;
        }
        else {
          *(undefined *)(*(int *)(param_1 + 0x2c0) + 0xaa) = 1;
          iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727931);
          *(undefined *)(iVar3 + 0xaa) = 1;
          iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727933);
          *(undefined *)(iVar3 + 0xaa) = 1;
        }
        *(undefined *)(*(int *)(param_1 + 0x100) + 0xaa) = 0;
        *(undefined *)(*(int *)(param_1 + 0x138) + 0xaa) = 0;
        *(undefined *)(*(int *)(param_1 + 0x170) + 0xaa) = 0;
        moveFlag_9962 = 0;
        goto LAB_801fb774;
      }
      if (moveStatus_9965 < 7) {
        uStack116 = (int)DAT_803e69a4 ^ 0x80000000;
        local_78 = 0x43300000;
        x = (double)(float)((double)CONCAT44(0x43300000,uStack116) - _4622);
        uStack124 = (int)DAT_803e69a6 ^ 0x80000000;
        local_98[6] = 176.0;
        dVar15 = (double)(float)((double)CONCAT44(0x43300000,uStack124) - _4622);
        iVar3 = dSv_event_c::isEventBit
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x908);
        if (((iVar3 == 0) ||
            (iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                               getStagInfo)(), (*(ushort *)(iVar3 + 10) & 3) != 0)) &&
           ((iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                               getStagInfo)(), (*(ushort *)(iVar3 + 10) & 3) != 1 ||
            ((*(uint *)(param_1 + 0x3004) & 0x400000) != 0)))) {
          *(undefined *)(*(int *)(param_1 + 0x2c0) + 0xaa) = 0;
          iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727931);
          *(undefined *)(iVar3 + 0xaa) = 0;
          iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727933);
          *(undefined *)(iVar3 + 0xaa) = 0;
        }
        else {
          *(undefined *)(*(int *)(param_1 + 0x2c0) + 0xaa) = 1;
          iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727931);
          *(undefined *)(iVar3 + 0xaa) = 0;
          iVar3 = (**(code **)(*sMainParts1 + 0x30))(sMainParts1,0x63727933);
          *(undefined *)(iVar3 + 0xaa) = 1;
        }
        *(undefined *)(*(int *)(param_1 + 0x100) + 0xaa) = 0;
        *(undefined *)(*(int *)(param_1 + 0x138) + 0xaa) = 0;
        *(undefined *)(*(int *)(param_1 + 0x170) + 0xaa) = 0;
        moveFlag_9962 = 0;
        goto LAB_801fb774;
      }
    }
    uStack116 = (int)DAT_803e69a4 ^ 0x80000000;
    local_78 = 0x43300000;
    x = (double)(float)((double)CONCAT44(0x43300000,uStack116) - _4622);
    uStack124 = (int)DAT_803e69a6 ^ 0x80000000;
    local_98[6] = 176.0;
    dVar15 = (double)(float)((double)CONCAT44(0x43300000,uStack124) - _4622);
    goto LAB_801fb774;
  }
  if (*(short *)(param_1 + 0x2f6) < 1) {
    *(undefined2 *)(param_1 + 0x2f6) = 0;
  }
  else {
    *(short *)(param_1 + 0x2f6) = *(short *)(param_1 + 0x2f6) + -1;
  }
  if (moveStatus_9965 == 5) {
    uStack116 = (int)DAT_803e69a4 ^ 0x80000000;
    local_78 = 0x43300000;
    x = (double)(float)((double)CONCAT44(0x43300000,uStack116) - _4622);
    uStack124 = (int)DAT_803e69a6 ^ 0x80000000;
    local_98[6] = 176.0;
    dVar15 = (double)(float)((double)CONCAT44(0x43300000,uStack124) - _4622);
    goto LAB_801fb774;
  }
  if (moveStatus_9965 < 5) {
    if (3 < moveStatus_9965) {
      uStack116 = (int)DAT_803e69a4 + 0x52U ^ 0x80000000;
      local_78 = 0x43300000;
      x = (double)(float)((double)CONCAT44(0x43300000,uStack116) - _4622);
      uStack124 = (int)DAT_803e69a6 ^ 0x80000000;
      local_98[6] = 176.0;
      dVar15 = (double)(float)((double)CONCAT44(0x43300000,uStack124) - _4622);
      goto LAB_801fb774;
    }
    if (1 < moveStatus_9965) goto LAB_801fb664;
  }
  else {
    if (moveStatus_9965 < 8) {
LAB_801fb664:
      uStack116 = (int)DAT_803e69a4 ^ 0x80000000;
      local_78 = 0x43300000;
      x = (double)(float)((double)CONCAT44(0x43300000,uStack116) - _4622);
      uStack124 = (int)DAT_803e69a6 ^ 0x80000000;
      local_98[6] = 176.0;
      dVar15 = (double)(float)((double)CONCAT44(0x43300000,uStack124) - _4622);
      goto LAB_801fb774;
    }
  }
  uStack116 = (int)DAT_803e69a4 ^ 0x80000000;
  local_78 = 0x43300000;
  x = (double)(float)((double)CONCAT44(0x43300000,uStack116) - _4622);
  uStack124 = (int)DAT_803e69a6 ^ 0x80000000;
  local_98[6] = 176.0;
  dVar15 = (double)(float)((double)CONCAT44(0x43300000,uStack124) - _4622);
LAB_801fb774:
  if ((moveStatus_9965 == 4) || (moveStatus_9965 == 5)) {
    local_98[3] = ((*(float *)(param_1 + 0x130c) + *(float *)(param_1 + 0x131c) * _4664) -
                  *(float *)(param_1 + 0x114)) - *(float *)(param_1 + 0x124) * _4664;
    local_98[0] = *(float *)(param_1 + 0x1310) - *(float *)(param_1 + 0x118);
    local_98[4] = *(float *)(param_1 + 0x130c) - *(float *)(param_1 + 0x14c);
    local_98[1] = ((*(float *)(param_1 + 0x1310) - *(float *)(param_1 + 0x1320) * _4664) -
                  *(float *)(param_1 + 0x150)) - *(float *)(param_1 + 0x160) * _4664;
    local_98[5] = *(float *)(param_1 + 0x194) * _4664 +
                  ((*(float *)(param_1 + 0x1964) + *(float *)(param_1 + 0x170c) * _4664) -
                  *(float *)(param_1 + 0x184));
    local_98[2] = *(float *)(param_1 + 0x1968) - *(float *)(param_1 + 0x188);
  }
  else {
    uStack116 = (int)_mDispPosLeftUpX ^ 0x80000000;
    local_78 = 0x43300000;
    uStack124 = (int)_mDispSizeX ^ 0x80000000;
    local_98[6] = 176.0;
    local_98[3] = ((float)((double)CONCAT44(0x43300000,uStack116) - _4622) +
                  (float)((double)CONCAT44(0x43300000,uStack124) - _4622) * _4664) -
                  *(float *)(param_1 + 0x14c);
    local_98[0] = ((float)((double)CONCAT44(0x43300000,(int)_mDispPosLeftUpY ^ 0x80000000) - _4622)
                  + (float)((double)CONCAT44(0x43300000,(int)_mDispSizeY ^ 0x80000000) - _4622) *
                    _4664) - *(float *)(param_1 + 0x118);
    local_98[1] = local_98[0];
    local_98[2] = local_98[0];
    local_98[4] = local_98[3];
    local_98[5] = local_98[3];
  }
  uStack100 = (int)_mDispPosLeftUpX - 0x19U ^ 0x80000000;
  local_68 = 0x43300000;
  dVar14 = (double)(float)((double)CONCAT44(0x43300000,uStack100) - _4622);
  uStack108 = (int)_mDispPosLeftUpY - 0x152U ^ 0x80000000;
  local_70 = 0x43300000;
  dVar13 = (double)(float)((double)CONCAT44(0x43300000,uStack108) - _4622);
  pcVar4 = d_kankyo_wether::dKyw_get_wind_vec();
  iVar3 = SComponent::cM_atan2s(pcVar4->x,pcVar4->z);
  fVar1 = *(float *)(param_1 + 800) * _4664;
  piVar5 = *(int **)(param_1 + 0x2f8);
  piVar5[0x27] = *(int *)(param_1 + 0x31c);
  piVar5[0x28] = (int)fVar1;
  *(undefined *)(piVar5 + 0x2a) = 0x7a;
  uStack116 = (int)(short)iVar3 ^ 0x80000000;
  local_78 = 0x43300000;
  piVar5[0x29] = (int)((_10310 * (float)((double)CONCAT44(0x43300000,uStack116) - _4622)) / _10311 -
                      _10310);
  (**(code **)(*piVar5 + 0x20))();
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x2c0),x,dVar15);
  uStack124 = (int)DAT_803e696c ^ 0x80000000;
  local_98[6] = 176.0;
  local_60 = (double)CONCAT44(0x43300000,(int)DAT_803e696e ^ 0x80000000);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_1 + 0x2f8),
             (double)((float)(dVar14 - (double)_6053) +
                     (float)((double)CONCAT44(0x43300000,uStack124) - _4622)),
             (double)((float)((double)_6270 + dVar13) + (float)(local_60 - _4622)));
  iVar3 = 0;
  iVar11 = 0;
  iVar10 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(param_1 + iVar11 + 0x100),
               (double)(float)(x + (double)*(float *)((int)local_98 + iVar10 + 0xc)),
               (double)(float)(dVar15 + (double)*(float *)((int)local_98 + iVar10)));
    iVar3 = iVar3 + 1;
    iVar11 = iVar11 + 0x38;
    iVar10 = iVar10 + 4;
  } while (iVar3 < 3);
  dVar15 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,5 - *(short *)(param_1 + 0x2f6),0);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2c0),(float)dVar15);
  local_60 = (double)(longlong)(int)((double)_4616 * dVar15);
  dMap_c::mAlpha = (undefined)(int)((double)_4616 * dVar15);
  iVar3 = d_kankyo_wether::dKyw_gbwind_use_check();
  if ((iVar3 == 0) || (bVar8 = dMenu_flag(), bVar8 != 0)) {
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2f8));
  }
  else {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2f8),(float)dVar15);
  }
  iVar3 = 0;
  iVar10 = 0;
  do {
    bVar8 = dMenu_flag();
    if (bVar8 == 0) {
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)(param_1 + iVar10 + 0x100),(float)dVar15);
    }
    else {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + iVar10 + 0x100));
    }
    iVar3 = iVar3 + 1;
    iVar10 = iVar10 + 0x38;
  } while (iVar3 < 3);
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  __psq_l0(auStack40,uVar12);
  __psq_l1(auStack40,uVar12);
  __psq_l0(auStack56,uVar12);
  __psq_l1(auStack56,uVar12);
  return;
}


/* __stdcall dMeter_magicLength(sub_meter_class *,
                                float) */

void dMeter_magicLength(double param_1,int param_2)

{
  float fVar1;
  double dVar2;
  
  dVar2 = (double)(_6057 * *(float *)(param_2 + 0xf5c));
  *(float *)(param_2 + 0x1124) =
       (float)(dVar2 * param_1) + (float)((double)*(float *)(param_2 + 0x111c) - dVar2);
  *(float *)(param_2 + 0x1114) = *(float *)(param_2 + 0x10fc) + *(float *)(param_2 + 0x1124) * _4664
  ;
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_2 + 0x10f8));
  *(undefined *)(*(int *)(param_2 + 0x11a0) + 0x134) = 1;
  fVar1 = 0_0;
  *(float *)(*(int *)(param_2 + 0x11a0) + 0x124) = 0_0;
  *(float *)(*(int *)(param_2 + 0x11a0) + 0x128) = fVar1;
  *(float *)(*(int *)(param_2 + 0x11a0) + 300) = _10325;
  *(float *)(*(int *)(param_2 + 0x11a0) + 0x130) = _10326;
  *(float *)(param_2 + 0x11cc) =
       *(float *)(param_2 + 0x1124) + (*(float *)(param_2 + 0x11c4) - *(float *)(param_2 + 0x111c));
  *(float *)(param_2 + 0x11bc) = *(float *)(param_2 + 0x11a4) + *(float *)(param_2 + 0x11cc) * _4664
  ;
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_2 + 0x11a0));
  *(undefined *)(*(int *)(param_2 + 0x1130) + 0x134) = 1;
  fVar1 = 0_0;
  *(float *)(*(int *)(param_2 + 0x1130) + 0x124) = 0_0;
  *(float *)(*(int *)(param_2 + 0x1130) + 0x128) = fVar1;
  *(float *)(*(int *)(param_2 + 0x1130) + 300) = _10325;
  *(float *)(*(int *)(param_2 + 0x1130) + 0x130) = _10326;
  *(float *)(param_2 + 0x115c) =
       *(float *)(param_2 + 0x1124) + (*(float *)(param_2 + 0x1154) - *(float *)(param_2 + 0x111c));
  *(float *)(param_2 + 0x114c) = *(float *)(param_2 + 0x1134) + *(float *)(param_2 + 0x115c) * _4664
  ;
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_2 + 0x1130));
  return;
}


/* __stdcall dMeter_windInit(sub_meter_class *) */

void dMeter_windInit(void)

{
  d_com_inf_game::g_dComIfG_gameInfo._23526_1_ = 0;
  dMeter_windID = 0xffffffff;
  dMeter_windStatus = 0;
  return;
}


/* __stdcall dMeter_metronomeInit(sub_meter_class *) */

void dMeter_metronomeInit(int param_1)

{
  *(undefined *)(param_1 + 0x3028) = 0;
  if (dMn_c != (dMetronome_c *)0x0) {
    ::dMetronome_c::_delete(dMn_c);
    if (dMn_c != (dMetronome_c *)0x0) {
      (**(code **)(dMn_c->vtbl + 8))(dMn_c,1);
    }
    dMn_c = (dMetronome_c *)0x0;
  }
  return;
}


/* __stdcall dMeter_windMove(sub_meter_class *) */

void dMeter_windMove(void)

{
  msg_class *pmVar1;
  
  if (dMeter_windStatus == d_com_inf_game::g_dComIfG_gameInfo._23526_1_) {
    if (((d_com_inf_game::g_dComIfG_gameInfo._23526_1_ != '\x02') && (dMeter_windID != 0xffffffff))
       && (pmVar1 = f_op_msg_mng::fopMsgM_SearchByID(dMeter_windID), pmVar1 == (msg_class *)0x0)) {
      dMeter_windID = 0xffffffff;
    }
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo._23526_1_ == '\x02') {
      dMeter_windID = f_op_msg_mng::fopMsgM_Create(0x1f2,0,0);
    }
    dMeter_windStatus = d_com_inf_game::g_dComIfG_gameInfo._23526_1_;
  }
  return;
}


/* __stdcall dMeter_metronomeMove(sub_meter_class *) */

void dMeter_metronomeMove(int param_1)

{
  uint uVar1;
  ulong uVar2;
  char cVar3;
  
  if ((((d_com_inf_game::g_dComIfG_gameInfo.field_0x5be7 == 0) ||
       (uVar1 = *(uint *)(param_1 + 0x3004), (uVar1 & 8) != 0)) || ((uVar1 & 0x10) != 0)) ||
     (((uVar1 & 0x800000) != 0 || ((uVar1 & 0x20) != 0)))) {
    if (*(char *)(param_1 + 0x3028) == '\x01') {
      if (dMn_c != (dMetronome_c *)0x0) {
        cVar3 = ::dMetronome_c::_close(dMn_c);
        if (cVar3 == '\0') {
          ::dMetronome_c::_move(dMn_c);
        }
        else {
          *(undefined *)(param_1 + 0x3028) = 2;
        }
      }
    }
    else {
      if ((*(char *)(param_1 + 0x3028) == '\x02') && (dMn_c != (dMetronome_c *)0x0)) {
        *(undefined *)(param_1 + 0x3028) = 0;
        ::dMetronome_c::_delete(dMn_c);
        if (dMn_c != (dMetronome_c *)0x0) {
          (**(code **)(dMn_c->vtbl + 8))(dMn_c,1);
        }
        dMn_c = (dMetronome_c *)0x0;
      }
    }
  }
  else {
    if ((*(char *)(param_1 + 0x3028) == '\0') && (dMn_c == (dMetronome_c *)0x0)) {
      dMn_c = (dMetronome_c *)JKernel::operator_new(0xe3c);
      if (dMn_c == (dMetronome_c *)0x0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_meter.cpp",0x2330,"dMn_c != 0");
        m_Do_printf::OSPanic("d_meter.cpp",0x2330,&DAT_80361783);
      }
      else {
        dMn_c->vtbl = (undefined *)&dDlst_base_c::__vt;
        dMn_c->vtbl = (undefined *)&::dMetronome_c::__vt;
      }
      ::dMetronome_c::_create(dMn_c);
      ::dMetronome_c::initialize(dMn_c);
    }
    if ((dMn_c != (dMetronome_c *)0x0) && (cVar3 = ::dMetronome_c::_open(dMn_c), cVar3 != '\0')) {
      ::dMetronome_c::_move(dMn_c);
    }
    *(undefined *)(param_1 + 0x3028) = 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801fc170) */
/* __stdcall dMeter_rupyAlpha(sub_meter_class *) */

void dMeter_rupyAlpha(sub_meter_class *param_1)

{
  ushort uVar1;
  JPABaseEmitter *pJVar2;
  uint uVar3;
  int iVar4;
  sub_meter_class *iVar5;
  int iVar6;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f31;
  cXyz local_38;
  cXyz local_2c;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar3 = param_1->field_0x3004;
  if ((uVar3 & 0x4000) == 0) {
    if ((uVar3 & 0x40) != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.field_0xd6 & 0x80;
      }
      if (uVar1 != 0) goto LAB_801fbfe8;
    }
    if (((((((uVar3 & 0x200000) == 0) && ((uVar3 & 0x80) == 0)) && ((uVar3 & 0x100000) == 0)) &&
         (((uVar3 & 0x400000) == 0 && ((uVar3 & 0x20000) == 0)))) &&
        (((uVar3 & 8) == 0 && (((uVar3 & 0x10) == 0 && ((uVar3 & 0x800000) == 0)))))) &&
       (((uVar3 & 0x20) == 0 &&
        ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda != 1 &&
         (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda != 6)))))) {
      dVar8 = (double)dMeter_alphaOpen(&(param_1->field_0x2a20).mUserData,
                                       &param_1->field_0x19f0[0].mUserData);
      pJVar2 = param_1->mpRupyParticle;
      if (pJVar2 == (JPABaseEmitter *)0x0) {
        local_38.y = (param_1->field_0x2a20).mPosCenter.y - _7213;
        local_38.x = (param_1->field_0x2a20).mPosCenter.x - _7214;
        local_38.z = 0_0;
        pJVar2 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,7,0x2d,
                                    &local_38,(csXyz *)0x0,(cXyz *)0x0,0xff,
                                    (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                                    (cXyz *)0x0);
        param_1->mpRupyParticle = pJVar2;
      }
      else {
        pJVar2->mFlags = pJVar2->mFlags & 0xfffffffb;
      }
      goto LAB_801fc124;
    }
  }
LAB_801fbfe8:
  dVar8 = (double)dMeter_alphaClose(&(param_1->field_0x2a20).mUserData,
                                    &param_1->field_0x19f0[0].mUserData);
  pJVar2 = param_1->mpRupyParticle;
  if (pJVar2 == (JPABaseEmitter *)0x0) {
    local_2c.y = (param_1->field_0x2a20).mPosCenter.y - _7213;
    local_2c.x = (param_1->field_0x2a20).mPosCenter.x - _7214;
    local_2c.z = 0_0;
    pJVar2 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,7,0x2d,
                                &local_2c,(csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1
                                ,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
    param_1->mpRupyParticle = pJVar2;
  }
  else {
    pJVar2->mFlags = pJVar2->mFlags | 4;
  }
LAB_801fc124:
  iVar4 = 0;
  iVar6 = 0;
  do {
    iVar5 = (sub_meter_class *)(&param_1->field_0x0 + iVar6);
    f_op_msg_mng::fopMsgM_setNowAlpha(iVar5->field_0x19f0,(float)dVar8);
    f_op_msg_mng::fopMsgM_setNowAlpha(iVar5->field_0x1b40,(float)dVar8);
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 0x38;
  } while (iVar4 < 4);
  f_op_msg_mng::fopMsgM_setNowAlpha(&param_1->field_0x2a20,(float)dVar8);
  f_op_msg_mng::fopMsgM_setNowAlpha(&param_1->field_0x2a58,(float)dVar8);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dMeter_rupyInit(sub_meter_class *) */

void dMeter_rupyInit(sub_meter_class *this)

{
  JPABaseEmitter *pJVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  cXyz local_48;
  char acStack60 [16];
  uint local_2c [5];
  
  iVar6 = 0;
  (this->field_0x2a20).mUserData = 0;
  this->field_0x19f0[0].mUserData = 0;
  this->field_0x19f0[0].mUserData = 1;
  this->mRupyCount = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrRupees;
  uVar2 = (uint)(ushort)this->mRupyCount;
  local_2c[0] = uVar2 / 1000;
  local_2c[1] = (uVar2 % 1000) / 100;
  local_2c[2] = (uVar2 % 100) / 10;
  local_2c[3] = uVar2 % 10;
  iVar3 = 0;
  iVar5 = 0;
  do {
    dMeter_rupy_num(acStack60,(int)(short)*(undefined4 *)((int)local_2c + iVar6));
    iVar4 = &this->field_0x0 + iVar5;
    J2DPicture::changeTexture(*(J2DPicture **)(iVar4 + 0x19f0),acStack60,0);
    J2DPicture::changeTexture(*(J2DPicture **)(iVar4 + 0x1b40),acStack60,0);
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 0x38;
    iVar6 = iVar6 + 4;
  } while (iVar3 < 4);
  d_com_inf_game::g_dComIfG_gameInfo.mRupyCountDisplay = this->mRupyCount;
  local_48.y = (this->field_0x2a20).mPosCenter.y - _7213;
  local_48.x = (this->field_0x2a20).mPosCenter.x - _7214;
  local_48.z = 0_0;
  pJVar1 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,7,0x2d,
                              &local_48,(csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                              (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
  this->mpRupyParticle = pJVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dMeter_rupyMove(sub_meter_class *) */

void dMeter_rupyMove(sub_meter_class *this)

{
  int iVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  sub_meter_class *pSubMeter;
  int iVar5;
  char acStack56 [16];
  uint local_28 [4];
  
  if (this->field_0x19f0[1].mUserData !=
      (ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrentWalletIndex)
  {
    dMeter_walletChange(this);
    this->field_0x19f0[1].mUserData =
         (ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                 mCurrentWalletIndex;
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees != 0) {
    iVar3 = (uint)(ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                          mCurrRupees + d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees;
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrentWalletIndex == 0)
    {
      iVar1 = 200;
    }
    else {
      if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrentWalletIndex == 1
         ) {
        iVar1 = 1000;
      }
      else {
        iVar1 = 5000;
      }
    }
    if ((iVar3 <= iVar1) && (iVar1 = iVar3, iVar3 < 0)) {
      iVar1 = 0;
    }
    this->mAdjustRupy = iVar1 - (uint)(ushort)this->mRupyCount;
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrRupees = (short)iVar1;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees = 0;
    lVar2 = MSL_C.PPCEABI.bare.H::labs(this->mAdjustRupy);
    if (4 < lVar2) {
      rupy_soundOnFlag = '\x01';
    }
  }
  iVar3 = this->mAdjustRupy;
  if (iVar3 != 0) {
    if (iVar3 < 1) {
      if (iVar3 < 0) {
        this->mRupyCount = this->mRupyCount + -1;
        this->mAdjustRupy = this->mAdjustRupy + 1;
        if (rupy_soundOnFlag != '\0') {
          if (this->mAdjustRupy == 0) {
            JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x83c,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0)
            ;
            rupy_soundSetFlag = '\0';
            rupy_soundOnFlag = '\0';
          }
          else {
            if (rupy_soundSetFlag == '\0') {
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x83b,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
              rupy_soundSetFlag = '\x01';
            }
            else {
              rupy_soundSetFlag = '\0';
            }
          }
        }
      }
    }
    else {
      this->mRupyCount = this->mRupyCount + 1;
      this->mAdjustRupy = this->mAdjustRupy + -1;
      if (rupy_soundOnFlag != '\0') {
        if (this->mAdjustRupy == 0) {
          JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x83a,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
          rupy_soundSetFlag = '\0';
          rupy_soundOnFlag = '\0';
        }
        else {
          if (rupy_soundSetFlag == '\0') {
            JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x839,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0)
            ;
            rupy_soundSetFlag = '\x01';
          }
          else {
            rupy_soundSetFlag = '\0';
          }
        }
      }
    }
    uVar4 = (uint)(ushort)this->mRupyCount;
    local_28[0] = uVar4 / 1000;
    local_28[1] = (uVar4 % 1000) / 100;
    local_28[2] = (uVar4 % 100) / 10;
    local_28[3] = uVar4 % 10;
    iVar3 = 0;
    iVar5 = 0;
    iVar1 = 0;
    do {
      dMeter_rupy_num(acStack56,(int)(short)*(undefined4 *)((int)local_28 + iVar1));
      pSubMeter = (sub_meter_class *)(&this->field_0x0 + iVar5);
      J2DPicture::changeTexture((J2DPicture *)pSubMeter->field_0x19f0[0].mpPane,acStack56,0);
      J2DPicture::changeTexture((J2DPicture *)pSubMeter->field_0x1b40[0].mpPane,acStack56,0);
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 0x38;
      iVar1 = iVar1 + 4;
    } while (iVar3 < 4);
    d_com_inf_game::g_dComIfG_gameInfo.mRupyCountDisplay = this->mRupyCount;
  }
  dMeter_rupyAlpha(this);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801fc840) */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall dMeter_walletChange(sub_meter_class *) */

void dMeter_walletChange(sub_meter_class *this)

{
  MyPicture *pJVar1;
  MyPicture *pJVar2;
  J2DScreen *pJVar3;
  undefined4 uVar4;
  undefined8 in_f31;
  double x;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrentWalletIndex == 0) {
    x = (double)(this->field_0x19f0[1].mPosTopLeftOrig.x - this->field_0x19f0[0].mPosTopLeftOrig.x);
    ((this->field_0x19f0[0].mpPane)->parent).mbDraw = 0;
    ((this->field_0x1b40[0].mpPane)->parent).mbDraw = 0;
    pJVar1 = (MyPicture *)(this->field_0x2a20).mpPane;
    (pJVar1->parent).mBgColor.r = 10;
    (pJVar1->parent).mBgColor.g = 0x28;
    (pJVar1->parent).mBgColor.b = 10;
    (pJVar1->parent).mBgColor.a = 0;
    pJVar2 = (MyPicture *)(this->field_0x2a20).mpPane;
    (pJVar2->parent).mColorBase.r = 0x28;
    (pJVar2->parent).mColorBase.g = 0xff;
    (pJVar2->parent).mColorBase.b = 0x28;
    (pJVar2->parent).mColorBase.a = 0xff;
    f_op_msg_mng::fopMsgM_paneTrans(&this->field_0x2a20,x,(double)0_0);
    f_op_msg_mng::fopMsgM_paneTrans(&this->field_0x2a58,x,(double)0_0);
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrentWalletIndex == 1)
    {
      ((this->field_0x19f0[0].mpPane)->parent).mbDraw = 1;
      ((this->field_0x1b40[0].mpPane)->parent).mbDraw = 1;
      pJVar3 = (this->field_0x2a20).mpPane;
      *(undefined *)&pJVar3[1].parent.mBox.mBR.x = 0x14;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 1) = 0x14;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 2) = 0xa0;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 3) = 0;
      pJVar3 = (this->field_0x2a20).mpPane;
      *(undefined *)&pJVar3[1].parent.mBox.mTL.y = 0x32;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mTL.y + 1) = 200;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mTL.y + 2) = 0xff;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mTL.y + 3) = 0xff;
      f_op_msg_mng::fopMsgM_paneTrans(&this->field_0x2a20,(double)0_0,(double)0_0);
      f_op_msg_mng::fopMsgM_paneTrans(&this->field_0x2a58,(double)0_0,(double)0_0);
    }
    else {
      ((this->field_0x19f0[0].mpPane)->parent).mbDraw = 1;
      ((this->field_0x1b40[0].mpPane)->parent).mbDraw = 1;
      pJVar3 = (this->field_0x2a20).mpPane;
      *(undefined *)&pJVar3[1].parent.mBox.mBR.x = 0x50;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 1) = 0x28;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 2) = 0;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 3) = 0;
      pJVar3 = (this->field_0x2a20).mpPane;
      *(undefined *)&pJVar3[1].parent.mBox.mTL.y = 0xff;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mTL.y + 1) = 0x8c;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mTL.y + 2) = 0;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mTL.y + 3) = 0xff;
      f_op_msg_mng::fopMsgM_paneTrans(&this->field_0x2a20,(double)0_0,(double)0_0);
      f_op_msg_mng::fopMsgM_paneTrans(&this->field_0x2a58,(double)0_0,(double)0_0);
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801fca70) */
/* WARNING: Removing unreachable block (ram,0x801fca60) */
/* WARNING: Removing unreachable block (ram,0x801fca68) */
/* WARNING: Removing unreachable block (ram,0x801fca78) */
/* __stdcall dMeter_keyLight(fopMsgM_pane_class *,
                             short *,
                             float) */

void dMeter_keyLight(double param_1,int **param_2,short *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f28;
  double dVar8;
  undefined8 in_f29;
  double dVar9;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  iVar3 = (int)*(short *)((int)param_2 + 0x36);
  iVar1 = (int)*param_3;
  if (iVar3 < iVar1) {
    dVar7 = (double)0_0;
    dVar6 = dVar7;
  }
  else {
    iVar4 = (int)param_3[1];
    if (iVar3 < iVar4) {
      dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar4 - iVar1,iVar3 - iVar1,0);
      dVar7 = (double)(_10769 + (float)((double)_4488 * dVar6));
      dVar6 = (double)(float)((double)_10770 * dVar6);
    }
    else {
      iVar1 = (int)param_3[2];
      if (iVar3 < iVar1) {
        dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar1 - iVar4,iVar3 - iVar4,0);
        dVar7 = (double)(1_0 - (float)((double)_10769 * dVar6));
        dVar6 = (double)(_10770 - (float)((double)_10771 * dVar6));
      }
      else {
        iVar4 = (int)param_3[3];
        if (iVar3 < iVar4) {
          dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar4 - iVar1,iVar3 - iVar1,0);
          dVar7 = (double)(_4488 + (float)((double)_10769 * dVar6));
          dVar6 = (double)(_8977 + (float)((double)_10771 * dVar6));
        }
        else {
          dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(param_3[4] - iVar4,iVar3 - iVar4,0);
          dVar7 = (double)1_0;
          dVar6 = (double)(float)((double)_10770 - (double)(float)((double)_10770 * dVar6));
        }
      }
    }
  }
  if (*(short *)((int)param_2 + 0x36) < param_3[4]) {
    *(short *)((int)param_2 + 0x36) = *(short *)((int)param_2 + 0x36) + 1;
  }
  else {
    *(undefined2 *)((int)param_2 + 0x36) = 1;
  }
  dVar9 = (double)(float)((double)(float)param_2[9] * dVar7);
  dVar8 = (double)(float)((double)(float)param_2[10] * dVar7);
  (**(code **)(**param_2 + 0x10))
            ((double)((float)param_2[1] - (float)(dVar9 - (double)(float)param_2[9]) * _4664),
             (double)((float)param_2[2] - (float)(dVar8 - (double)(float)param_2[10]) * _4664));
  (**(code **)(**param_2 + 0x18))(dVar9,dVar8);
  piVar2 = *param_2;
  dVar7 = (double)_4664;
  piVar2[0x27] = (int)(float)(dVar9 * dVar7);
  piVar2[0x28] = (int)(float)(dVar8 * dVar7);
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  (**(code **)(*piVar2 + 0x20))();
  *(char *)((int)param_2 + 0x35) = (char)(int)(dVar6 * param_1);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  __psq_l0(auStack56,uVar5);
  __psq_l1(auStack56,uVar5);
  return;
}


/* __stdcall dMeter_keyRndLightFrame(short *) */

void dMeter_keyRndLightFrame(short *param_1)

{
  double dVar1;
  float fVar2;
  
  fVar2 = SComponent::cM_rndFX
                    ((float)((double)CONCAT44(0x43300000,(int)DAT_803e69a2 ^ 0x80000000) - _4622));
  dVar1 = _4622;
  *param_1 = (short)(int)((float)((double)CONCAT44(0x43300000,(int)DAT_803e6998 ^ 0x80000000) -
                                 _4622) + fVar2);
  fVar2 = SComponent::cM_rndFX
                    ((float)((double)CONCAT44(0x43300000,(int)DAT_803e699a ^ 0x80000000) - dVar1));
  dVar1 = _4622;
  param_1[1] = (short)(int)((float)((double)CONCAT44(0x43300000,
                                                     (int)*param_1 + (int)DAT_803e6990 ^ 0x80000000)
                                   - _4622) + fVar2);
  fVar2 = SComponent::cM_rndFX
                    ((float)((double)CONCAT44(0x43300000,(int)DAT_803e699c ^ 0x80000000) - dVar1));
  dVar1 = _4622;
  param_1[2] = (short)(int)((float)((double)CONCAT44(0x43300000,
                                                     (int)param_1[1] + (int)DAT_803e6992 ^
                                                     0x80000000) - _4622) + fVar2);
  fVar2 = SComponent::cM_rndFX
                    ((float)((double)CONCAT44(0x43300000,(int)DAT_803e699e ^ 0x80000000) - dVar1));
  dVar1 = _4622;
  param_1[3] = (short)(int)((float)((double)CONCAT44(0x43300000,
                                                     (int)param_1[2] + (int)DAT_803e6994 ^
                                                     0x80000000) - _4622) + fVar2);
  fVar2 = SComponent::cM_rndFX
                    ((float)((double)CONCAT44(0x43300000,(int)DAT_803e69a0 ^ 0x80000000) - dVar1));
  param_1[4] = (short)(int)((float)((double)CONCAT44(0x43300000,
                                                     (int)param_1[3] + (int)DAT_803e6996 ^
                                                     0x80000000) - _4622) + fVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dMeter_keyAlpha(sub_meter_class *) */

void dMeter_keyAlpha(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  
  local_28 = 0x1e;
  local_26 = 0x28;
  local_24 = 0x2d;
  local_22 = 0x32;
  local_20 = 0x3a;
  uVar2 = *(uint *)(param_1 + 0x3004);
  if ((uVar2 & 0x4000) == 0) {
    if ((uVar2 & 0x40) != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.field_0xd6 & 0x40;
      }
      if (uVar1 != 0) goto LAB_801fcd7c;
    }
    if ((uVar2 & 0x200000) == 0) {
      if ((uVar2 & 0x80) == 0) {
        if ((uVar2 & 0x100000) == 0) {
          if ((uVar2 & 0x400000) == 0) {
            if ((uVar2 & 0x20000) == 0) {
              if ((uVar2 & 0x400) == 0) {
                if ((uVar2 & 8) == 0) {
                  if ((uVar2 & 0x10) == 0) {
                    if (((uVar2 & 0x800000) == 0) && ((uVar2 & 0x20) == 0)) {
                      iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)
                                        ->getStagInfo)();
                      if ((*(byte *)(iVar3 + 9) & 1) == 0) {
                        dVar5 = (double)dMeter_alphaClose(param_1 + 0x1cc6,param_1 + 0x1b06);
                      }
                      else {
                        dVar5 = (double)dMeter_alphaOpen(param_1 + 0x1cc6,param_1 + 0x1b06);
                      }
                      goto LAB_801fcdd8;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_801fcd7c:
  dVar5 = (double)dMeter_alphaClose(param_1 + 0x1cc6,param_1 + 0x1b06);
LAB_801fcdd8:
  iVar3 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + iVar4 + 0x1ad0),(float)dVar5)
    ;
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + iVar4 + 0x1c20),(float)dVar5)
    ;
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar3 < 2);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1c90),(float)dVar5);
  if (*(short *)(param_1 + 0x19ee) == 1) {
    dMeter_keyRndLightFrame(param_1 + 0x2fda);
  }
  dMeter_keyLight(dVar5,param_1 + 0x1980,&local_28);
  dMeter_keyLight(dVar5,param_1 + 0x19b8,param_1 + 0x2fda);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dMeter_keyInit(sub_meter_class *) */

void dMeter_keyInit(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_38 [2];
  undefined auStack48 [24];
  
  *(undefined2 *)(param_1 + 0x19ee) = 1;
  *(undefined2 *)(param_1 + 0x19b6) = 1;
  iVar2 = 0;
  *(undefined2 *)(param_1 + 0x1cc6) = 0;
  *(undefined2 *)(param_1 + 0x1b06) = 0;
  *(byte *)(param_1 + 0x301d) = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory.mBits.field_0x20;
  local_38[0] = *(byte *)(param_1 + 0x301d) / 10;
  local_38[1] = (uint)*(byte *)(param_1 + 0x301d) % 10;
  iVar1 = 0;
  iVar3 = 0;
  do {
    dMeter_rupy_num(auStack48,(int)(short)*(undefined4 *)((int)local_38 + iVar2));
    f_op_msg_mng::fopMsgM_blendInit((fopMsgM_pane_class *)(param_1 + iVar3 + 0x1ad0),auStack48);
    f_op_msg_mng::fopMsgM_blendInit((fopMsgM_pane_class *)(param_1 + iVar3 + 0x1c20),auStack48);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
    iVar2 = iVar2 + 4;
  } while (iVar1 < 2);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dMeter_keyMove(sub_meter_class *) */

void dMeter_keyMove(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_38 [2];
  undefined auStack48 [24];
  
  iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  if ((*(byte *)(iVar2 + 9) & 1) != 0) {
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48d4 != 0) {
      sVar1 = (ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory.mBits.field_0x20 +
              d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48d4;
      if (sVar1 < 100) {
        if (sVar1 < 0) {
          sVar1 = 0;
        }
      }
      else {
        sVar1 = 99;
      }
      *(ushort *)(param_1 + 0x300e) = sVar1 - (ushort)*(byte *)(param_1 + 0x301d);
      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory.mBits.field_0x20 = (byte)sVar1;
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48d4 = 0;
    }
    sVar1 = *(short *)(param_1 + 0x300e);
    if (sVar1 != 0) {
      if (sVar1 < 1) {
        if (sVar1 < 0) {
          *(char *)(param_1 + 0x301d) = *(char *)(param_1 + 0x301d) + -1;
          *(short *)(param_1 + 0x300e) = *(short *)(param_1 + 0x300e) + 1;
        }
      }
      else {
        *(char *)(param_1 + 0x301d) = *(char *)(param_1 + 0x301d) + '\x01';
        *(short *)(param_1 + 0x300e) = *(short *)(param_1 + 0x300e) + -1;
      }
      local_38[0] = *(byte *)(param_1 + 0x301d) / 10;
      local_38[1] = (uint)*(byte *)(param_1 + 0x301d) % 10;
      iVar2 = 0;
      iVar4 = 0;
      iVar3 = 0;
      do {
        dMeter_rupy_num(auStack48,(int)(short)*(undefined4 *)((int)local_38 + iVar3));
        f_op_msg_mng::fopMsgM_blendDraw(param_1 + iVar4 + 0x1ad0,auStack48);
        f_op_msg_mng::fopMsgM_blendDraw(param_1 + iVar4 + 0x1c20,auStack48);
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x38;
        iVar3 = iVar3 + 4;
      } while (iVar2 < 2);
    }
  }
  dMeter_keyAlpha(param_1);
  return;
}


/* __stdcall dMeter_compassRotate(fopMsgM_pane_class *,
                                  fopMsgM_pane_class *,
                                  float) */

void dMeter_compassRotate(double param_1,int **param_2)

{
  float fVar1;
  int *piVar2;
  
  piVar2 = *param_2;
  fVar1 = ((float)piVar2[6] - (float)piVar2[4]) * _4664;
  piVar2[0x27] = (int)(((float)piVar2[5] - (float)piVar2[3]) * _4664);
  piVar2[0x28] = (int)fVar1;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)(float)param_1;
  (**(code **)(*piVar2 + 0x20))();
  return;
}


/* WARNING: Removing unreachable block (ram,0x801fd3f4) */
/* __stdcall dMeter_compassGetOnProc(sub_meter_class *) */

void dMeter_compassGetOnProc(int param_1)

{
  int iVar1;
  fopAc_ac_c *pfVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined2 local_28 [4];
  undefined4 local_20;
  uint uStack28;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  switch(*(undefined *)(param_1 + 0x3020)) {
  case 1:
    if ((dMeter_mMapCtrlDisp == (mapCtrlDisp_c)0x0) ||
       (((*(uint *)(param_1 + 0x3004) & 0x400) != 0 &&
        (iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo
                 )(), *(byte *)(iVar1 + 9) >> 1 != 5)))) {
      *(undefined *)(param_1 + 0x3020) = 5;
      *(undefined *)(*(int *)(param_1 + 0x12f0) + 0xaa) = 1;
      dMeter_clockShow(param_1);
      dMeter_compassDirOpen(param_1);
      *(undefined *)(param_1 + 0x3029) = 0;
    }
    else {
      *(undefined *)(param_1 + 0x3020) = 2;
      *(undefined *)(param_1 + 0x3029) = 1;
    }
    break;
  case 2:
    if (dMeter_mMapCtrlDisp == (mapCtrlDisp_c)0x0) {
      *(undefined *)(*(int *)(param_1 + 0x12f0) + 0xaa) = 1;
      dMeter_clockShow();
      *(undefined *)(param_1 + 0x3020) = 5;
      dMeter_compassDirOpen(param_1);
      *(undefined *)(param_1 + 0x302a) = 1;
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x818,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
    }
    break;
  case 3:
    if (((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 6 & 1) != 0) &&
         ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 4 & 1) == 0)) &&
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 5 & 1) == 0)) ||
       (*(short *)(param_1 + 0x197e) != 0)) {
      *(undefined *)(param_1 + 0x3020) = 6;
      *(undefined2 *)(param_1 + 0x197e) = 1;
      dMeter_compassWindOpen(param_1);
      *(undefined *)(param_1 + 0x302a) = 1;
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x818,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
    }
    break;
  case 5:
    dMeter_compassDirOpen();
    break;
  case 6:
    if ((((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 < '\0') &&
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 4 & 1) == 0)) &&
       ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 5 & 1) == 0)) {
      *(undefined *)(param_1 + 0x3020) = 8;
      *(undefined2 *)(param_1 + 0x197e) = 0;
      dMeter_compassWindClose();
    }
    else {
      dMeter_compassWindOpen(param_1);
    }
    break;
  case 7:
    dMeter_compassAnimeMove();
    break;
  case 8:
    if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 6 & 1) == 0) ||
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 4 & 1) != 0)) ||
       ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 5 & 1) != 0)) {
      dMeter_compassWindClose(param_1);
    }
    else {
      *(undefined *)(param_1 + 0x3020) = 6;
      *(undefined2 *)(param_1 + 0x197e) = 1;
      dMeter_compassWindOpen();
    }
    break;
  case 9:
    dMeter_compassDirClose();
  }
  local_28[0] = 0xa7;
  pfVar2 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_28);
  uStack28 = -(int)(short)((pfVar2->mCollisionRot).y + -0x8000) ^ 0x80000000;
  local_20 = 0x43300000;
  dVar4 = (double)((float)((double)_10310 *
                          (double)(float)((double)CONCAT44(0x43300000,uStack28) - _4622)) / _10311);
  dMeter_compassRotate
            ((double)(-d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime -
                     _10771),(double)_10310,param_1 + 0x1670,param_1 + 0x16a8);
  dMeter_compassRotate(dVar4,param_1 + 0x1248,param_1 + 0x12f0);
  dMeter_compassRotate(dVar4,param_1 + 0x1280,param_1 + 0x12f0);
  dMeter_clockMove(param_1);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __stdcall dMeter_compassGetOffProc(sub_meter_class *) */

void dMeter_compassGetOffProc(int param_1)

{
  byte bVar1;
  
  bVar1 = *(byte *)(param_1 + 0x3020);
  if (bVar1 == 5) {
LAB_801fd450:
    *(undefined *)(param_1 + 0x3020) = 9;
LAB_801fd458:
    dMeter_compassDirClose();
  }
  else {
    if (bVar1 < 5) {
      if (bVar1 == 3) goto LAB_801fd450;
    }
    else {
      if (bVar1 == 9) goto LAB_801fd458;
      if (bVar1 < 9) {
        if (bVar1 < 8) {
          *(undefined *)(param_1 + 0x3020) = 8;
          *(undefined2 *)(param_1 + 0x197e) = 0;
        }
        dMeter_compassWindClose();
        return;
      }
    }
    dMeter_compassValueInit();
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x801fd6a4) */
/* WARNING: Removing unreachable block (ram,0x801fd694) */
/* WARNING: Removing unreachable block (ram,0x801fd68c) */
/* WARNING: Removing unreachable block (ram,0x801fd69c) */
/* WARNING: Removing unreachable block (ram,0x801fd6ac) */
/* __stdcall dMeter_compassDirOpen(sub_meter_class *) */

void dMeter_compassDirOpen(int param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined8 in_f27;
  double dVar5;
  undefined8 in_f28;
  double dVar6;
  undefined8 in_f29;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
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
  iVar2 = *(int *)(param_1 + 0x1948);
  fVar1 = (*(float *)(*(int *)(param_1 + 0x13d0) + 0x14) -
          *(float *)(*(int *)(param_1 + 0x13d0) + 0xc)) * _4664;
  dVar9 = (double)((*(float *)(iVar2 + 0x14) - *(float *)(iVar2 + 0xc)) * _4664 - fVar1);
  dVar8 = (double)((*(float *)(iVar2 + 0x18) - *(float *)(iVar2 + 0x10)) * _4664);
  iVar2 = *(int *)(param_1 + 0x16a8);
  dVar7 = (double)((*(float *)(iVar2 + 0x14) - *(float *)(iVar2 + 0xc)) * _4664 - fVar1);
  dVar6 = (double)((*(float *)(iVar2 + 0x18) - *(float *)(iVar2 + 0x10)) * _4664);
  *(short *)(param_1 + 0x1326) = *(short *)(param_1 + 0x1326) + 1;
  if (*(short *)(param_1 + 0x1326) < 5) {
    dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,5 - *(short *)(param_1 + 0x1326),0);
    dVar5 = (double)(float)(dVar5 * -(double)(*(float *)(param_1 + 0x194c) +
                                             *(float *)(param_1 + 0x196c)));
    if (*(char *)(param_1 + 0x302a) == '\0') {
      *(undefined *)(param_1 + 0x302a) = 1;
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x81f,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x1326) = 5;
    *(undefined *)(param_1 + 0x3020) = 3;
    dVar5 = (double)0_0;
    if (*(char *)(param_1 + 0x302a) != '\0') {
      *(undefined *)(param_1 + 0x302a) = 0;
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x819,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
    }
  }
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x12f0),dVar5,(double)0_0);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x16a8),dVar5,(double)0_0);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x1948),dVar5,(double)0_0);
  piVar3 = *(int **)(param_1 + 0x16a8);
  piVar3[0x27] = (int)(float)dVar7;
  piVar3[0x28] = (int)(float)dVar6;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)_10310;
  (**(code **)(*piVar3 + 0x20))();
  piVar3 = *(int **)(param_1 + 0x1948);
  piVar3[0x27] = (int)(float)dVar9;
  piVar3[0x28] = (int)(float)dVar8;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)_10310;
  (**(code **)(*piVar3 + 0x20))();
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  __psq_l0(auStack72,uVar4);
  __psq_l1(auStack72,uVar4);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801fd89c) */
/* WARNING: Removing unreachable block (ram,0x801fd88c) */
/* WARNING: Removing unreachable block (ram,0x801fd884) */
/* WARNING: Removing unreachable block (ram,0x801fd894) */
/* WARNING: Removing unreachable block (ram,0x801fd8a4) */
/* __stdcall dMeter_compassWindOpen(sub_meter_class *) */

void dMeter_compassWindOpen(int param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined8 in_f27;
  double dVar5;
  undefined8 in_f28;
  double dVar6;
  undefined8 in_f29;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
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
  iVar2 = *(int *)(param_1 + 0x1948);
  fVar1 = (*(float *)(*(int *)(param_1 + 0x13d0) + 0x14) -
          *(float *)(*(int *)(param_1 + 0x13d0) + 0xc)) * _4664;
  dVar9 = (double)((*(float *)(iVar2 + 0x14) - *(float *)(iVar2 + 0xc)) * _4664 - fVar1);
  dVar8 = (double)((*(float *)(iVar2 + 0x18) - *(float *)(iVar2 + 0x10)) * _4664);
  iVar2 = *(int *)(param_1 + 0x16a8);
  dVar7 = (double)((*(float *)(iVar2 + 0x14) - *(float *)(iVar2 + 0xc)) * _4664 - fVar1);
  dVar6 = (double)((*(float *)(iVar2 + 0x18) - *(float *)(iVar2 + 0x10)) * _4664);
  *(short *)(param_1 + 0x1326) = *(short *)(param_1 + 0x1326) + 1;
  if (*(short *)(param_1 + 0x1326) < 10) {
    dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,10 - *(short *)(param_1 + 0x1326),0);
    dVar5 = (double)(float)((double)_11066 * dVar5);
    if (*(char *)(param_1 + 0x302a) == '\0') {
      *(undefined *)(param_1 + 0x302a) = 1;
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x81f,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x1326) = 10;
    *(undefined *)(param_1 + 0x3020) = 7;
    dVar5 = (double)0_0;
    if (*(char *)(param_1 + 0x302a) != '\0') {
      *(undefined *)(param_1 + 0x302a) = 0;
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x819,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
    }
  }
  piVar3 = *(int **)(param_1 + 0x16a8);
  piVar3[0x27] = (int)(float)dVar7;
  piVar3[0x28] = (int)(float)dVar6;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)dVar5;
  (**(code **)(*piVar3 + 0x20))();
  piVar3 = *(int **)(param_1 + 0x1948);
  piVar3[0x27] = (int)(float)dVar9;
  piVar3[0x28] = (int)(float)dVar8;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)dVar5;
  (**(code **)(*piVar3 + 0x20))();
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  __psq_l0(auStack72,uVar4);
  __psq_l1(auStack72,uVar4);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801fdb3c) */
/* WARNING: Removing unreachable block (ram,0x801fdb2c) */
/* WARNING: Removing unreachable block (ram,0x801fdb24) */
/* WARNING: Removing unreachable block (ram,0x801fdb34) */
/* WARNING: Removing unreachable block (ram,0x801fdb44) */
/* __stdcall dMeter_compassWindClose(sub_meter_class *) */

void dMeter_compassWindClose(int param_1)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  short sVar5;
  undefined4 uVar6;
  undefined8 in_f27;
  double dVar7;
  undefined8 in_f28;
  double dVar8;
  undefined8 in_f29;
  double dVar9;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
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
  iVar2 = *(int *)(param_1 + 0x1948);
  fVar1 = (*(float *)(*(int *)(param_1 + 0x13d0) + 0x14) -
          *(float *)(*(int *)(param_1 + 0x13d0) + 0xc)) * _4664;
  dVar11 = (double)((*(float *)(iVar2 + 0x14) - *(float *)(iVar2 + 0xc)) * _4664 - fVar1);
  dVar10 = (double)((*(float *)(iVar2 + 0x18) - *(float *)(iVar2 + 0x10)) * _4664);
  iVar2 = *(int *)(param_1 + 0x16a8);
  dVar9 = (double)((*(float *)(iVar2 + 0x14) - *(float *)(iVar2 + 0xc)) * _4664 - fVar1);
  dVar8 = (double)((*(float *)(iVar2 + 0x18) - *(float *)(iVar2 + 0x10)) * _4664);
  *(short *)(param_1 + 0x1326) = *(short *)(param_1 + 0x1326) + -1;
  if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime < _10771) ||
     (_11140 <= d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime)) {
    sVar5 = 1;
  }
  else {
    sVar5 = 0;
  }
  if (*(short *)(param_1 + 0x1326) < 6) {
    *(undefined2 *)(param_1 + 0x1326) = 5;
    uVar3 = dStage_roomControl_c::GetTimePass();
    if ((((uVar3 == 0) || (*(float *)(param_1 + 0x2f68) != 0_0)) &&
        ((uVar3 = dStage_roomControl_c::GetTimePass(), uVar3 != 0 ||
         (*(float *)(param_1 + 0x2f68) == 0_0)))) &&
       ((uVar3 = dStage_roomControl_c::GetTimePass(), uVar3 != 0 ||
        (*(short *)(param_1 + 0x3012) == sVar5)))) {
      *(undefined *)(param_1 + 0x3020) = 3;
    }
    else {
      dMeter_clockShow(param_1);
      *(undefined *)(param_1 + 0x3020) = 6;
      *(undefined2 *)(param_1 + 0x197e) = 1;
    }
    dVar7 = (double)_11066;
    if (*(char *)(param_1 + 0x302a) != '\0') {
      *(undefined *)(param_1 + 0x302a) = 0;
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x819,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
    }
  }
  else {
    dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,10 - *(short *)(param_1 + 0x1326),0);
    dVar7 = (double)(float)((double)_11066 * dVar7);
    if (*(char *)(param_1 + 0x302a) == '\0') {
      *(undefined *)(param_1 + 0x302a) = 1;
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x81f,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
    }
  }
  piVar4 = *(int **)(param_1 + 0x16a8);
  piVar4[0x27] = (int)(float)dVar9;
  piVar4[0x28] = (int)(float)dVar8;
  *(undefined *)(piVar4 + 0x2a) = 0x7a;
  piVar4[0x29] = (int)(float)dVar7;
  (**(code **)(*piVar4 + 0x20))();
  piVar4 = *(int **)(param_1 + 0x1948);
  piVar4[0x27] = (int)(float)dVar11;
  piVar4[0x28] = (int)(float)dVar10;
  *(undefined *)(piVar4 + 0x2a) = 0x7a;
  piVar4[0x29] = (int)(float)dVar7;
  (**(code **)(*piVar4 + 0x20))();
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


/* WARNING: Removing unreachable block (ram,0x801fdd80) */
/* WARNING: Removing unreachable block (ram,0x801fdd70) */
/* WARNING: Removing unreachable block (ram,0x801fdd68) */
/* WARNING: Removing unreachable block (ram,0x801fdd78) */
/* WARNING: Removing unreachable block (ram,0x801fdd88) */
/* __stdcall dMeter_compassDirClose(sub_meter_class *) */

void dMeter_compassDirClose(int param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f27;
  double dVar5;
  undefined8 in_f28;
  double dVar6;
  undefined8 in_f29;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
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
  iVar3 = *(int *)(param_1 + 0x1948);
  fVar1 = (*(float *)(*(int *)(param_1 + 0x13d0) + 0x14) -
          *(float *)(*(int *)(param_1 + 0x13d0) + 0xc)) * _4664;
  dVar9 = (double)((*(float *)(iVar3 + 0x14) - *(float *)(iVar3 + 0xc)) * _4664 - fVar1);
  dVar8 = (double)((*(float *)(iVar3 + 0x18) - *(float *)(iVar3 + 0x10)) * _4664);
  iVar3 = *(int *)(param_1 + 0x16a8);
  dVar7 = (double)((*(float *)(iVar3 + 0x14) - *(float *)(iVar3 + 0xc)) * _4664 - fVar1);
  dVar6 = (double)((*(float *)(iVar3 + 0x18) - *(float *)(iVar3 + 0x10)) * _4664);
  *(short *)(param_1 + 0x1326) = *(short *)(param_1 + 0x1326) + -1;
  if (*(short *)(param_1 + 0x1326) < 1) {
    dMeter_compassValueInit();
    *(undefined2 *)(param_1 + 0x1326) = 0;
    dVar5 = -(double)(*(float *)(param_1 + 0x194c) + *(float *)(param_1 + 0x196c));
    if (*(char *)(param_1 + 0x302a) != '\0') {
      *(undefined *)(param_1 + 0x302a) = 0;
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x819,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
    }
  }
  else {
    dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,5 - *(short *)(param_1 + 0x1326),0);
    dVar5 = (double)(float)(dVar5 * -(double)(*(float *)(param_1 + 0x194c) +
                                             *(float *)(param_1 + 0x196c)));
    if (*(char *)(param_1 + 0x302a) == '\0') {
      *(undefined *)(param_1 + 0x302a) = 1;
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x81f,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
    }
  }
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x12f0),dVar5,(double)0_0);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x16a8),dVar5,(double)0_0);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x1948),dVar5,(double)0_0);
  piVar2 = *(int **)(param_1 + 0x16a8);
  piVar2[0x27] = (int)(float)dVar7;
  piVar2[0x28] = (int)(float)dVar6;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)_10310;
  (**(code **)(*piVar2 + 0x20))();
  piVar2 = *(int **)(param_1 + 0x1948);
  piVar2[0x27] = (int)(float)dVar9;
  piVar2[0x28] = (int)(float)dVar8;
  *(undefined *)(piVar2 + 0x2a) = 0x7a;
  piVar2[0x29] = (int)_10310;
  (**(code **)(*piVar2 + 0x20))();
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  __psq_l0(auStack72,uVar4);
  __psq_l1(auStack72,uVar4);
  return;
}


/* __stdcall dMeter_compassAnimeMove(sub_meter_class *) */

void dMeter_compassAnimeMove(int param_1)

{
  uint uVar1;
  short sVar2;
  
  if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime < _10771) ||
     (_11140 <= d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime)) {
    sVar2 = 1;
  }
  else {
    sVar2 = 0;
  }
  if ((((-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2) ||
       ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 4 & 1) != 0)) ||
      ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 5 & 1) != 0)) &&
     (((uVar1 = dStage_roomControl_c::GetTimePass(), uVar1 == 0 ||
       (*(float *)(param_1 + 0x2f68) != 0_0)) &&
      ((uVar1 = dStage_roomControl_c::GetTimePass(), uVar1 != 0 ||
       (*(float *)(param_1 + 0x2f68) == 0_0)))))) {
    uVar1 = dStage_roomControl_c::GetTimePass();
    if (uVar1 != 0) {
      return;
    }
    if (*(short *)(param_1 + 0x3012) == sVar2) {
      return;
    }
  }
  *(undefined *)(param_1 + 0x3020) = 8;
  *(undefined2 *)(param_1 + 0x197e) = 0;
  *(undefined *)(param_1 + 0x302a) = 1;
  JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x81a,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x801fe0ac) */
/* WARNING: Removing unreachable block (ram,0x801fe09c) */
/* WARNING: Removing unreachable block (ram,0x801fe08c) */
/* WARNING: Removing unreachable block (ram,0x801fe094) */
/* WARNING: Removing unreachable block (ram,0x801fe0a4) */
/* WARNING: Removing unreachable block (ram,0x801fe0b4) */
/* __stdcall dMeter_compassValueInit(sub_meter_class *) */

void dMeter_compassValueInit(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined8 in_f26;
  double dVar5;
  undefined8 in_f27;
  double dVar6;
  undefined8 in_f28;
  double dVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
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
  uVar1 = dStage_roomControl_c::GetTimePass();
  if (uVar1 == 0) {
    *(float *)(param_1 + 0x2f68) = 0_0;
  }
  else {
    *(float *)(param_1 + 0x2f68) = 1_0;
  }
  if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime < _10771) ||
     (_11140 <= d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime)) {
    *(undefined2 *)(param_1 + 0x3012) = 1;
  }
  else {
    *(undefined2 *)(param_1 + 0x3012) = 0;
  }
  *(undefined2 *)(param_1 + 0x1326) = 0;
  *(undefined *)(param_1 + 0x302a) = 0;
  dVar10 = (double)(*(float *)(*(int *)(param_1 + 0x13d0) + 0x14) -
                   *(float *)(*(int *)(param_1 + 0x13d0) + 0xc));
  iVar2 = *(int *)(param_1 + 0x1948);
  dVar9 = (double)(*(float *)(iVar2 + 0x14) - *(float *)(iVar2 + 0xc));
  dVar8 = (double)(*(float *)(iVar2 + 0x18) - *(float *)(iVar2 + 0x10));
  iVar2 = *(int *)(param_1 + 0x16a8);
  dVar7 = (double)(*(float *)(iVar2 + 0x14) - *(float *)(iVar2 + 0xc));
  dVar6 = (double)(*(float *)(iVar2 + 0x18) - *(float *)(iVar2 + 0x10));
  dVar5 = -(double)(*(float *)(param_1 + 0x194c) + *(float *)(param_1 + 0x196c));
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x12f0),dVar5,(double)0_0);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_1 + 0x1948),dVar5,(double)0_0);
  piVar3 = *(int **)(param_1 + 0x16a8);
  dVar5 = (double)_4664;
  piVar3[0x27] = (int)((float)(dVar7 * dVar5) - (float)(dVar10 * dVar5));
  piVar3[0x28] = (int)(float)(dVar6 * dVar5);
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)_10310;
  (**(code **)(*piVar3 + 0x20))();
  piVar3 = *(int **)(param_1 + 0x1948);
  dVar5 = (double)_4664;
  piVar3[0x27] = (int)((float)(dVar9 * dVar5) - (float)(dVar10 * dVar5));
  piVar3[0x28] = (int)(float)(dVar8 * dVar5);
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)_10310;
  (**(code **)(*piVar3 + 0x20))();
  *(undefined *)(*(int *)(param_1 + 0x1210) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x12f0) + 0xaa) = 0;
  dMeter_clockHide(param_1);
  *(undefined *)(param_1 + 0x3020) = 1;
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  __psq_l0(auStack72,uVar4);
  __psq_l1(auStack72,uVar4);
  __psq_l0(auStack88,uVar4);
  __psq_l1(auStack88,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801fe210) */
/* __stdcall dMeter_compassAlpha(sub_meter_class *) */

void dMeter_compassAlpha(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar4 = (double)*(float *)(param_1 + 0x2f6c);
  f_op_msg_mng::fopMsgM_setNowAlpha
            ((fopMsgM_pane_class *)(param_1 + 0x1210),*(float *)(param_1 + 0x2f6c));
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x12f0),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1398),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x13d0),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1408),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1440),(float)dVar4);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + iVar2 + 0x1478),(float)dVar4)
    ;
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1868),(float)dVar4);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1520),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1558),(float)dVar4);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + iVar2 + 0x1590),(float)dVar4)
    ;
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1718),(float)dVar4);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1670),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x16a8),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x16e0),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x17f8),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1830),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1910),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x1948),(float)dVar4);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __stdcall dMeter_compassInit(sub_meter_class *) */

void dMeter_compassInit(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  *(undefined *)(*(int *)(param_1 + 0x1248) + 0x134) = 1;
  fVar3 = _4617;
  *(float *)(*(int *)(param_1 + 0x1248) + 0x124) = _4617;
  fVar1 = 0_0;
  *(float *)(*(int *)(param_1 + 0x1248) + 0x128) = 0_0;
  fVar2 = 1_0;
  *(float *)(*(int *)(param_1 + 0x1248) + 300) = 1_0;
  *(float *)(*(int *)(param_1 + 0x1248) + 0x130) = fVar2;
  *(undefined *)(*(int *)(param_1 + 0x1280) + 0x134) = 1;
  *(float *)(*(int *)(param_1 + 0x1280) + 0x124) = fVar3;
  *(float *)(*(int *)(param_1 + 0x1280) + 0x128) = fVar1;
  *(float *)(*(int *)(param_1 + 0x1280) + 300) = fVar2;
  *(float *)(*(int *)(param_1 + 0x1280) + 0x130) = fVar2;
  if (dMeter_mMapCtrlDisp == (mapCtrlDisp_c)0x0) {
    *(undefined *)(param_1 + 0x3029) = 0;
  }
  else {
    *(undefined *)(param_1 + 0x3029) = 1;
  }
  *(undefined2 *)(param_1 + 0x197e) = 0;
  dMeter_compassValueInit(param_1);
  dMeter_clockMultiInit(param_1);
  return;
}


/* __stdcall dMeter_compassMove(sub_meter_class *) */

void dMeter_compassMove(sub_meter_class *param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1->field_0x3004;
  if ((uVar3 & 0x4000) == 0) {
    if ((uVar3 & 0x40) != 0) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.field_0xd6 & 0x100;
      }
      if (uVar1 != 0) goto LAB_801fe348;
    }
    if ((uVar3 & 0x200000) == 0) {
      if ((uVar3 & 0x100) == 0) {
        if ((uVar3 & 0x80) == 0) {
          if ((uVar3 & 0x100000) == 0) {
            if ((uVar3 & 0x20000) == 0) {
              if ((uVar3 & 8) == 0) {
                if ((uVar3 & 0x10) == 0) {
                  if ((((uVar3 & 0x800000) == 0) && ((uVar3 & 0x20) == 0)) &&
                     (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda != 1)) {
                    if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda != 8) {
                      if (((uVar3 & 0x400) == 0) ||
                         (iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.
                                            parent)->getStagInfo)(), *(byte *)(iVar2 + 9) >> 1 == 5)
                         ) {
                        dMeter_compassGetOffProc(param_1);
                        dMeter_compassAlpha(param_1);
                      }
                      else {
                        dMeter_compassGetOnProc(param_1);
                        dMeter_compassAlpha(param_1);
                        if (*(char *)&param_1->field_0x3027 == '\0') {
                          dMap_c::mMapDispMode = 1;
                        }
                        else {
                          dMap_c::mMapDispMode = 0;
                        }
                      }
                      goto LAB_801fe428;
                    }
                  }
                }
              }
            }
          }
        }
      }
      dMeter_compassValueInit(param_1);
      goto LAB_801fe428;
    }
  }
LAB_801fe348:
  dMeter_compassValueInit(param_1);
LAB_801fe428:
  dMeter_clockMultiMove(param_1);
  return;
}


/* __stdcall dMeter_clockShow(sub_meter_class *) */

void dMeter_clockShow(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = dStage_roomControl_c::GetTimePass();
  if (uVar1 == 0) {
    *(float *)(param_1 + 0x2f68) = 0_0;
  }
  else {
    *(float *)(param_1 + 0x2f68) = 1_0;
  }
  if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime < _10771) ||
     (_11140 <= d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime)) {
    *(undefined2 *)(param_1 + 0x3012) = 1;
  }
  else {
    *(undefined2 *)(param_1 + 0x3012) = 0;
  }
  dMeter_clockInit(param_1);
  uVar1 = dStage_roomControl_c::GetTimePass();
  if (uVar1 == 0) {
    *(undefined *)(*(int *)(param_1 + 0x1398) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x13d0) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x1408) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x1440) + 0xaa) = 0;
    iVar2 = 0;
    iVar3 = 3;
    do {
      *(undefined *)(*(int *)(param_1 + iVar2 + 0x1478) + 0xaa) = 0;
      iVar2 = iVar2 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined *)(*(int *)(param_1 + 0x1520) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x1558) + 0xaa) = 0;
    iVar2 = 0;
    iVar3 = 4;
    do {
      *(undefined *)(*(int *)(param_1 + iVar2 + 0x1590) + 0xaa) = 0;
      iVar2 = iVar2 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined *)(*(int *)(param_1 + 0x1670) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x16a8) + 0xaa) = 0;
    if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime < _10771) ||
       (_11140 <= d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime)) {
      *(undefined *)(*(int *)(param_1 + 0x16e0) + 0xaa) = 1;
      *(undefined *)(*(int *)(param_1 + 0x17f8) + 0xaa) = 1;
      *(undefined *)(*(int *)(param_1 + 0x1830) + 0xaa) = 0;
      *(undefined *)(*(int *)(param_1 + 0x1910) + 0xaa) = 0;
      *(undefined *)(*(int *)(param_1 + 0x1948) + 0xaa) = 1;
      iVar2 = 0;
      iVar3 = 3;
      do {
        *(undefined *)(*(int *)(param_1 + iVar2 + 0x1868) + 0xaa) = 0;
        iVar2 = iVar2 + 0x38;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar2 = 0;
      iVar3 = 4;
      do {
        *(undefined *)(*(int *)(param_1 + iVar2 + 0x1718) + 0xaa) = 1;
        iVar2 = iVar2 + 0x38;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar2 = *(int *)(param_1 + 0x1948);
      *(undefined *)(iVar2 + 0x10c) = 0;
      *(undefined *)(iVar2 + 0x10d) = 0;
      *(undefined *)(iVar2 + 0x10e) = 0xff;
      *(undefined *)(iVar2 + 0x10f) = 0xff;
      *(undefined *)(iVar2 + 0x110) = 0;
      *(undefined *)(iVar2 + 0x111) = 0;
      *(undefined *)(iVar2 + 0x112) = 0;
      *(undefined *)(iVar2 + 0x113) = 0xff;
      *(undefined *)(iVar2 + 0x114) = 0;
      *(undefined *)(iVar2 + 0x115) = 0;
      *(undefined *)(iVar2 + 0x116) = 0;
      *(undefined *)(iVar2 + 0x117) = 0xff;
      *(undefined *)(iVar2 + 0x118) = 0;
      *(undefined *)(iVar2 + 0x119) = 0;
      *(undefined *)(iVar2 + 0x11a) = 0;
      *(undefined *)(iVar2 + 0x11b) = 0xff;
    }
    else {
      *(undefined *)(*(int *)(param_1 + 0x16e0) + 0xaa) = 1;
      *(undefined *)(*(int *)(param_1 + 0x17f8) + 0xaa) = 0;
      *(undefined *)(*(int *)(param_1 + 0x1830) + 0xaa) = 1;
      *(undefined *)(*(int *)(param_1 + 0x1910) + 0xaa) = 1;
      *(undefined *)(*(int *)(param_1 + 0x1948) + 0xaa) = 1;
      iVar2 = 0;
      iVar3 = 3;
      do {
        *(undefined *)(*(int *)(param_1 + iVar2 + 0x1868) + 0xaa) = 0;
        iVar2 = iVar2 + 0x38;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar2 = 0;
      iVar3 = 4;
      do {
        *(undefined *)(*(int *)(param_1 + iVar2 + 0x1718) + 0xaa) = 0;
        iVar2 = iVar2 + 0x38;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar2 = *(int *)(param_1 + 0x1948);
      *(undefined *)(iVar2 + 0x10c) = 0xff;
      *(undefined *)(iVar2 + 0x10d) = 0xff;
      *(undefined *)(iVar2 + 0x10e) = 0;
      *(undefined *)(iVar2 + 0x10f) = 0xff;
      *(undefined *)(iVar2 + 0x110) = 0xff;
      *(undefined *)(iVar2 + 0x111) = 0xff;
      *(undefined *)(iVar2 + 0x112) = 0;
      *(undefined *)(iVar2 + 0x113) = 0xff;
      *(undefined *)(iVar2 + 0x114) = 0xff;
      *(undefined *)(iVar2 + 0x115) = 0xff;
      *(undefined *)(iVar2 + 0x116) = 0;
      *(undefined *)(iVar2 + 0x117) = 0xff;
      *(undefined *)(iVar2 + 0x118) = 0;
      *(undefined *)(iVar2 + 0x119) = 0;
      *(undefined *)(iVar2 + 0x11a) = 0xff;
      *(undefined *)(iVar2 + 0x11b) = 0xff;
    }
  }
  else {
    *(undefined *)(*(int *)(param_1 + 0x1398) + 0xaa) = 1;
    *(undefined *)(*(int *)(param_1 + 0x13d0) + 0xaa) = 1;
    *(undefined *)(*(int *)(param_1 + 0x1408) + 0xaa) = 1;
    *(undefined *)(*(int *)(param_1 + 0x1440) + 0xaa) = 1;
    iVar2 = 0;
    iVar3 = 3;
    do {
      *(undefined *)(*(int *)(param_1 + iVar2 + 0x1478) + 0xaa) = 1;
      iVar2 = iVar2 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined *)(*(int *)(param_1 + 0x1520) + 0xaa) = 1;
    *(undefined *)(*(int *)(param_1 + 0x1558) + 0xaa) = 1;
    iVar2 = 0;
    iVar3 = 4;
    do {
      *(undefined *)(*(int *)(param_1 + iVar2 + 0x1590) + 0xaa) = 1;
      iVar2 = iVar2 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined *)(*(int *)(param_1 + 0x1670) + 0xaa) = 1;
    *(undefined *)(*(int *)(param_1 + 0x16a8) + 0xaa) = 1;
    *(undefined *)(*(int *)(param_1 + 0x16e0) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x17f8) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x1830) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x1910) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + 0x1948) + 0xaa) = 0;
    iVar2 = 0;
    iVar3 = 3;
    do {
      *(undefined *)(*(int *)(param_1 + iVar2 + 0x1868) + 0xaa) = 0;
      iVar2 = iVar2 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar2 = 0;
    iVar3 = 4;
    do {
      *(undefined *)(*(int *)(param_1 + iVar2 + 0x1718) + 0xaa) = 0;
      iVar2 = iVar2 + 0x38;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}


/* __stdcall dMeter_clockHide(sub_meter_class *) */

void dMeter_clockHide(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined *)(*(int *)(param_1 + 0x1398) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x13d0) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x1408) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x1440) + 0xaa) = 0;
  iVar1 = 0;
  iVar2 = 3;
  do {
    *(undefined *)(*(int *)(param_1 + iVar1 + 0x1478) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + iVar1 + 0x1868) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined *)(*(int *)(param_1 + 0x1520) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x1558) + 0xaa) = 0;
  iVar1 = 0;
  iVar2 = 4;
  do {
    *(undefined *)(*(int *)(param_1 + iVar1 + 0x1590) + 0xaa) = 0;
    *(undefined *)(*(int *)(param_1 + iVar1 + 0x1718) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined *)(*(int *)(param_1 + 0x1670) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x16a8) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x16e0) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x17f8) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x1830) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x1910) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0x1948) + 0xaa) = 0;
  return;
}


/* __stdcall dMeter_clockInit(sub_meter_class *) */

void dMeter_clockInit(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  dVar5 = _4622;
  fVar1 = *(float *)(param_1 + 0x194c);
  fVar2 = *(float *)(param_1 + 0x1834);
  fVar3 = *(float *)(param_1 + 0x1950);
  fVar4 = *(float *)(param_1 + 0x1838);
  iVar6 = 0;
  iVar7 = 0;
  iVar9 = 3;
  do {
    iVar8 = param_1 + iVar7;
    *(undefined2 *)(iVar8 + 0x174e) = 1;
    *(undefined2 *)(iVar8 + 0x14ae) = 1;
    *(float *)(iVar8 + 0x1884) =
         (fVar1 + fVar2) -
         (float)((double)CONCAT44(0x43300000,(int)*(short *)(&initPosX_11639 + iVar6) ^ 0x80000000)
                - dVar5);
    *(float *)(iVar8 + 0x1888) =
         (fVar3 + fVar4) -
         (float)((double)CONCAT44(0x43300000,(int)*(short *)(&initPosY_11640 + iVar6) ^ 0x80000000)
                - dVar5);
    iVar6 = iVar6 + 2;
    iVar7 = iVar7 + 0x38;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  *(undefined2 *)(param_1 + 0x17f6) = 1;
  *(undefined2 *)(param_1 + 0x1946) = 0;
  return;
}


/* __stdcall dMeter_clockMove(sub_meter_class *) */

void dMeter_clockMove(int param_1)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = (int)*(short *)(param_1 + 0x1946);
  if (iVar3 < 0x3d) {
    f_op_msg_mng::fopMsgM_valueIncrease(0x3c,iVar3,0);
  }
  else {
    f_op_msg_mng::fopMsgM_valueIncrease(0x3c,0x78 - iVar3,0);
  }
  if (*(short *)(param_1 + 0x1946) < 0x78) {
    *(short *)(param_1 + 0x1946) = *(short *)(param_1 + 0x1946) + 1;
  }
  else {
    *(undefined2 *)(param_1 + 0x1946) = 0;
  }
  dVar1 = _4622;
  iVar3 = 0;
  iVar4 = 0;
  iVar5 = 3;
  do {
    *(float *)(param_1 + iVar3 + 0x1884) =
         (float)((double)CONCAT44(0x43300000,
                                  (int)*(short *)((int)&DAT_803e6974 + iVar4) ^ 0x80000000) - dVar1)
    ;
    *(float *)(param_1 + iVar3 + 0x1888) =
         (float)((double)CONCAT44(0x43300000,
                                  (int)*(short *)((int)&DAT_803e697a + iVar4) ^ 0x80000000) - dVar1)
    ;
    iVar3 = iVar3 + 0x38;
    iVar4 = iVar4 + 2;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  uVar2 = dStage_roomControl_c::GetTimePass();
  if (uVar2 == 0) {
    if (*(short *)(param_1 + 0x174e) == 1) {
      dMeter_starLightFrame(param_1 + 0x2fe4);
    }
    if (*(short *)(param_1 + 0x1786) == 1) {
      dMeter_starLightFrame(param_1 + 0x2fe8);
    }
    if (*(short *)(param_1 + 0x17be) == 1) {
      dMeter_starLightFrame(param_1 + 0x2fec);
    }
    if (*(short *)(param_1 + 0x17f6) == 1) {
      dMeter_starLightFrame(param_1 + 0x2ff0);
    }
    dMeter_clockStarLight(param_1 + 0x1718,param_1 + 0x2fe4);
    dMeter_clockStarLight(param_1 + 0x1750,param_1 + 0x2fe8);
    dMeter_clockStarLight(param_1 + 0x1788,param_1 + 0x2fec);
    dMeter_clockStarLight(param_1 + 0x17c0,param_1 + 0x2ff0);
  }
  else {
    if (*(short *)(param_1 + 0x14ae) == 1) {
      dMeter_starLightFrame(param_1 + 0x2fe4);
    }
    if (*(short *)(param_1 + 0x14e6) == 1) {
      dMeter_starLightFrame(param_1 + 0x2fe8);
    }
    if (*(short *)(param_1 + 0x151e) == 1) {
      dMeter_starLightFrame(param_1 + 0x2fec);
    }
    dMeter_clockStarLight(param_1 + 0x1478,param_1 + 0x2fe4);
    dMeter_clockStarLight(param_1 + 0x14b0,param_1 + 0x2fe8);
    dMeter_clockStarLight(param_1 + 0x14e8,param_1 + 0x2fec);
  }
  return;
}


/* __stdcall dMeter_clockStarLight(fopMsgM_pane_class *,
                                   short *) */

void dMeter_clockStarLight(int *param_1,short *param_2)

{
  undefined uVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  
  iVar3 = (int)*(short *)((int)param_1 + 0x36);
  iVar2 = (int)*param_2;
  if (iVar3 < iVar2) {
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar2,iVar3,0);
  }
  else {
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(param_2[1] - iVar2,param_2[1] - iVar3,0);
  }
  uVar1 = (undefined)(int)((double)_4616 * dVar4);
  iVar2 = *param_1;
  *(undefined *)(iVar2 + 0x108) = uVar1;
  *(undefined *)(iVar2 + 0x109) = uVar1;
  *(undefined *)(iVar2 + 0x10a) = uVar1;
  *(undefined *)(iVar2 + 0x10b) = 0;
  if (*(short *)((int)param_1 + 0x36) < param_2[1]) {
    *(short *)((int)param_1 + 0x36) = *(short *)((int)param_1 + 0x36) + 1;
  }
  else {
    *(undefined2 *)((int)param_1 + 0x36) = 1;
  }
  return;
}


/* __stdcall dMeter_starLightFrame(short *) */

void dMeter_starLightFrame(short *param_1)

{
  double dVar1;
  float fVar2;
  
  fVar2 = SComponent::cM_rndFX
                    ((float)((double)CONCAT44(0x43300000,(int)DAT_803e69a2 ^ 0x80000000) - _4622));
  dVar1 = _4622;
  *param_1 = (short)(int)((float)((double)CONCAT44(0x43300000,(int)DAT_803e6998 ^ 0x80000000) -
                                 _4622) + fVar2);
  fVar2 = SComponent::cM_rndFX
                    ((float)((double)CONCAT44(0x43300000,(int)DAT_803e699a ^ 0x80000000) - dVar1));
  param_1[1] = (short)(int)((float)((double)CONCAT44(0x43300000,
                                                     (int)*param_1 + (int)DAT_803e6990 ^ 0x80000000)
                                   - _4622) + fVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x801fef20) */
/* __stdcall dMeter_clockMultiInit(sub_meter_class *) */

void dMeter_clockMultiInit(void)

{
  bool bVar1;
  ResTIMG *ctx;
  ResTIMG *pRVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 in_f31;
  double dVar8;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ctx = (ResTIMG *)
        JKRArchive::getGlbResource
                  (0x54494d47,"swimtime_meter_mask.bti",
                   d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpSwimResArchive);
  pRVar2 = (ResTIMG *)
           JKRArchive::getGlbResource
                     (0x54494d47,"screw_01.bti",
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMenuArchive);
  bVar1 = false;
  if ((ctx != (ResTIMG *)0x0) && (pRVar2 != (ResTIMG *)0x0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_meter.cpp",0x2982,"texture1 != 0 && texture2 != 0");
    m_Do_printf::OSPanic("d_meter.cpp",0x2982,&DAT_80361783);
  }
  iVar4 = 0;
  iVar6 = 0;
  iVar5 = 0;
  dVar8 = (double)1_0;
  do {
    ::dDlst_2Dm_c::init((dDlst_2Dm_c *)(&clock + iVar6),ctx,pRVar2,
                        (float)(dVar8 / (double)*(float *)((int)&scaleX_11729 + iVar5)),
                        (float)(dVar8 / (double)*(float *)((int)&scaleY_11730 + iVar5)));
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 0x84;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 3);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f14 */
/* WARNING: Inlined function: FUN_80328f60 */
/* WARNING: Removing unreachable block (ram,0x801ff15c) */
/* WARNING: Removing unreachable block (ram,0x801ff154) */
/* WARNING: Removing unreachable block (ram,0x801ff164) */
/* __stdcall dMeter_clockMultiMove(sub_meter_class *) */

void dMeter_clockMultiMove(sub_meter_class *this)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  uint uVar4;
  sub_meter_class *iVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  dDlst_2Dm_c *pDlst;
  undefined4 uVar12;
  undefined8 in_f29;
  double dVar13;
  undefined8 in_f30;
  double dVar14;
  undefined8 in_f31;
  double dVar15;
  undefined local_c8;
  undefined uStack199;
  undefined uStack198;
  undefined uStack197;
  undefined local_c4;
  undefined uStack195;
  undefined uStack194;
  undefined uStack193;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  iVar11 = 0;
  iVar10 = 0;
  iVar9 = 0;
  iVar8 = 0;
  iVar7 = 0;
  dVar13 = (double)_9165;
  dVar14 = (double)1_0;
  dVar15 = _4622;
  do {
    iVar4 = (sub_meter_class *)(&this->field_0x0 + iVar7);
    fVar1 = (iVar4->field_0x1868).mPosCenter.x;
    fVar2 = (iVar4->field_0x1868).mPosCenter.y;
    pDlst = (dDlst_2Dm_c *)(&clock + iVar8);
    sVar5 = (short)(int)((this->field_0x1948).mPosTopLeftOrig.x +
                        (this->field_0x1830).mPosTopLeftOrig.x);
    sVar6 = (short)(int)((this->field_0x1948).mPosTopLeftOrig.y +
                        (this->field_0x1830).mPosTopLeftOrig.y);
    ::dDlst_2Dm_c::setPos
              (pDlst,sVar5,sVar6,
               (short)(int)((float)((double)CONCAT44(0x43300000,(int)sVar5 ^ 0x80000000) - dVar15) +
                           (this->field_0x1830).mSizeOrig.x),
               (short)(int)((float)((double)CONCAT44(0x43300000,(int)sVar6 ^ 0x80000000) - dVar15) +
                           (this->field_0x1830).mSizeOrig.y));
    uVar3 = _11760;
    local_c4 = (undefined)((uint)_11760 >> 0x18);
    (&DAT_803e6d28)[iVar8] = local_c4;
    uStack195 = (undefined)((uint)uVar3 >> 0x10);
    (&DAT_803e6d29)[iVar8] = uStack195;
    uStack194 = (undefined)((uint)uVar3 >> 8);
    (&DAT_803e6d2a)[iVar8] = uStack194;
    uStack193 = (undefined)uVar3;
    (&DAT_803e6d2b)[iVar8] = uStack193;
    uVar3 = _11762;
    local_c8 = (undefined)((uint)_11762 >> 0x18);
    (&DAT_803e6d2c)[iVar8] = local_c8;
    uStack199 = (undefined)((uint)uVar3 >> 0x10);
    (&DAT_803e6d2d)[iVar8] = uStack199;
    uStack198 = (undefined)((uint)uVar3 >> 8);
    (&DAT_803e6d2e)[iVar8] = uStack198;
    uStack197 = (undefined)uVar3;
    (&DAT_803e6d2f)[iVar8] = uStack197;
    ::dDlst_2Dm_c::setScroll(pDlst,0,0,0);
    ::dDlst_2Dm_c::setScroll(pDlst,1,(short)(int)fVar1,(short)(int)fVar2);
    uVar4 = (int)*(short *)((int)&DAT_803e6980 + iVar10) ^ 0x80000000;
    ::dDlst_2Dm_c::setScale
              (pDlst,(float)(dVar13 * (double)(float)(dVar14 / (double)*(float *)((int)&scaleX_11753
                                                                                 + iVar9))) /
                     (float)((double)CONCAT44(0x43300000,uVar4) - dVar15),
               (float)(dVar13 * (double)(float)(dVar14 / (double)*(float *)((int)&scaleY_11754 +
                                                                           iVar9))) /
               (float)((double)CONCAT44(0x43300000,uVar4) - dVar15));
    iVar11 = iVar11 + 1;
    iVar10 = iVar10 + 2;
    iVar9 = iVar9 + 4;
    iVar8 = iVar8 + 0x84;
    iVar7 = iVar7 + 0x38;
  } while (iVar11 < 3);
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  __psq_l0(auStack40,uVar12);
  __psq_l1(auStack40,uVar12);
  return;
}


/* __stdcall dMeter_mapInit(sub_meter_class *) */

void dMeter_mapInit(int param_1)

{
  undefined2 uVar1;
  
  *(undefined *)(param_1 + 0x3027) = 0xff;
  uVar1 = dSv_memBit_c::isDungeonItem
                    ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1);
  *(undefined2 *)(param_1 + 0x136) = uVar1;
  dMeter_mMapCtrlDisp = (mapCtrlDisp_c)0x0;
  sRam803f70cc = DAT_803e68e8 - DAT_803e68e4;
  ::mapCtrlDisp_c::initMapCtrlDisp(&dMeter_mMapCtrlDisp);
  return;
}


/* __stdcall dMeter_mapMove(sub_meter_class *) */

void dMeter_mapMove(int param_1)

{
  ushort uVar1;
  dComIfG_inf_c *this;
  char cVar3;
  int iVar2;
  dMap_c *this_00;
  mapCtrlDisp_c *this_01;
  uint uVar4;
  
  if (init_11803 == '\0') {
    mapTimer_11802 = 0;
    init_11803 = '\x01';
  }
  if (init_11806 == '\0') {
    stageFlag_11805 = '\0';
    init_11806 = '\x01';
  }
  if (init_11809 == '\0') {
    stayNo_11808 = (dComIfG_inf_c *)(int)(char)dStage_roomControl_c::mStayNo;
    init_11809 = '\x01';
  }
  this = (dComIfG_inf_c *)f_op_overlap_mng::fopOvlpM_IsDoingReq();
  if (this == (dComIfG_inf_c *)0x0) {
    if (*(char *)(param_1 + 0x3027) == -1) {
      stageFlag_11805 = '\x01';
    }
    else {
      this = (dComIfG_inf_c *)(int)(char)dStage_roomControl_c::mStayNo;
      if (stayNo_11808 != this) {
        stageFlag_11805 = '\x02';
        stayNo_11808 = this;
      }
    }
  }
  uVar4 = *(uint *)(param_1 + 0x3004);
  if ((uVar4 & 0x4000) != 0) goto LAB_801ff660;
  if ((uVar4 & 0x40) != 0) {
    this = &d_com_inf_game::g_dComIfG_gameInfo;
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.field_0xd6 & 0x100;
    }
    if (uVar1 != 0) goto LAB_801ff660;
  }
  if ((uVar4 & 0x200000) != 0) goto LAB_801ff660;
  if ((uVar4 & 0x100) != 0) goto LAB_801ff660;
  if ((uVar4 & 0x80) != 0) goto LAB_801ff660;
  if ((uVar4 & 0x100000) != 0) goto LAB_801ff660;
  if ((uVar4 & 0x20000) != 0) goto LAB_801ff660;
  if ((uVar4 & 8) != 0) goto LAB_801ff660;
  if ((((uVar4 & 0x10) != 0) || ((uVar4 & 0x20) != 0)) ||
     (cVar3 = dMap_c::isEnableDispMap((dMap_c *)this), cVar3 == '\0')) goto LAB_801ff660;
  iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                    ((char *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage,"MajyuE");
  if (iVar2 == 0) {
    iVar2 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x801);
    if (iVar2 == 0) goto LAB_801ff660;
  }
  if ((*(uint *)(param_1 + 0x3004) & 0x400) != 0) {
    this_00 = (dMap_c *)
              (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                        (0x803c9d58);
    if ((byte)this_00[9] >> 1 != 5) {
      if ((dMeter_mMapCtrlDisp != (mapCtrlDisp_c)0x0) &&
         (cVar3 = dMap_c::isEnableDispMap(this_00), cVar3 != '\0')) {
        dMeter_mMapCtrlDisp = (mapCtrlDisp_c)0x0;
        uRam803f70c9 = 7;
      }
      goto LAB_801ff660;
    }
  }
  this_01 = (mapCtrlDisp_c *)(os::_838 + 4);
  if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 4 & 1) == 0) &&
     ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 5 & 1) == 0)) {
    this_01 = (mapCtrlDisp_c *)&d_com_inf_game::g_dComIfG_gameInfo;
    if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda == 1) goto LAB_801ff584;
    this_01 = (mapCtrlDisp_c *)(uint)(m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 7);
    if (((dComIfG_inf_c *)this_01 == (dComIfG_inf_c *)0x0) &&
       ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 6 & 1) == 0)) goto LAB_801ff584;
    if ((dComIfG_inf_c *)this_01 == (dComIfG_inf_c *)0x0) {
      if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 6 & 1) != 0) &&
         (dMap_c::mAlpha != '\0')) {
        if (dMeter_mMapCtrlDisp == (mapCtrlDisp_c)0x0) {
          cVar3 = dMap_c::isEnableDispMap((dMap_c *)0x0);
          if (cVar3 != '\0') {
            dMeter_mMapCtrlDisp = (mapCtrlDisp_c)0x1;
            uRam803f70c9 = 0;
          }
          *(undefined *)(param_1 + 0x3029) = 1;
          this_01 = (mapCtrlDisp_c *)
                    JAIZelBasic::seStart
                              (JAIZelBasic::zel_basic,0x818,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
        }
        else {
          if (*(char *)(param_1 + 0x3027) == '\0') {
            *(undefined *)(param_1 + 0x3027) = 1;
            this_01 = (mapCtrlDisp_c *)
                      JAIZelBasic::seStart
                                (JAIZelBasic::zel_basic,0x8c2,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0)
            ;
          }
          else {
            *(undefined *)(param_1 + 0x3027) = 0;
            this_01 = (mapCtrlDisp_c *)
                      JAIZelBasic::seStart
                                (JAIZelBasic::zel_basic,0x8c2,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0)
            ;
          }
        }
      }
    }
    else {
      if ((dMap_c::mAlpha != '\0') && (dMeter_mMapCtrlDisp != (mapCtrlDisp_c)0x0)) {
        cVar3 = dMap_c::isEnableDispMap((dMap_c *)this_01);
        if (cVar3 != '\0') {
          dMeter_mMapCtrlDisp = (mapCtrlDisp_c)0x0;
          uRam803f70c9 = 0;
        }
        *(undefined *)(param_1 + 0x3029) = 0;
        this_01 = (mapCtrlDisp_c *)
                  JAIZelBasic::seStart
                            (JAIZelBasic::zel_basic,0x81a,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
      }
    }
  }
  else {
LAB_801ff584:
    if ((*(char *)(param_1 + 0x3029) != '\0') &&
       (((*(char *)(param_1 + 0x3020) == '\x01' && (dMeter_mMapCtrlDisp == (mapCtrlDisp_c)0x0)) &&
        (this_01 = (mapCtrlDisp_c *)dMap_c::isEnableDispMap((dMap_c *)this_01),
        ((uint)this_01 & 0xff) != 0)))) {
      dMeter_mMapCtrlDisp = (mapCtrlDisp_c)0x1;
      this_01 = &dMeter_mMapCtrlDisp;
      uRam803f70c9 = 7;
    }
  }
  if (stageFlag_11805 == '\x01') {
    stageFlag_11805 = '\0';
    if (dMeter_mMapCtrlDisp == (mapCtrlDisp_c)0x0) {
      cVar3 = dMap_c::isEnableDispMap((dMap_c *)this_01);
      if (cVar3 != '\0') {
        dMeter_mMapCtrlDisp = (mapCtrlDisp_c)0x1;
        uRam803f70c9 = 0;
      }
      *(undefined *)(param_1 + 0x3029) = 1;
      *(undefined *)(param_1 + 0x3027) = 0;
    }
  }
  else {
    if (stageFlag_11805 == '\x02') {
      stageFlag_11805 = '\0';
      *(undefined *)(param_1 + 0x3027) = 0;
    }
  }
  uVar4 = countLeadingZeros((uint)*(byte *)(param_1 + 0x3027));
  dMap_c::mMapDispMode = (undefined)(uVar4 >> 5);
  if ((dMeter_mMapCtrlDisp != (mapCtrlDisp_c)0x0) && (mapTimer_11802 != 6)) {
    mapTimer_11802 = 6;
  }
LAB_801ff660:
  ::mapCtrlDisp_c::moveMapCtrlDisp(&dMeter_mMapCtrlDisp);
  dMeter_recollect_boss_data();
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* __stdcall dMeter_arwInit(sub_meter_class *) */

void dMeter_arwInit(daArrow_c *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  bVar1 = daArrow_c::getKeepType(param_1);
  if (3 < bVar1) {
    bVar1 = 0;
  }
  iVar2 = 0;
  iVar6 = 0;
  iVar5 = 0;
  do {
    iVar3 = (int)&(param_1->parent).parent.parent.mBsType + iVar5;
    JKRArchive::readTypeResource
              (*(void **)(iVar3 + 0x2f34),0xc00,0x54494d47,(&arrowTexImage)[bVar1],
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
    os::DCStoreRangeNoSync(*(undefined4 *)(iVar3 + 0x2f34),0xc00);
    iVar4 = (int)&(param_1->parent).parent.parent.mBsType + iVar6;
    J2DPicture::changeTexture(*(J2DPicture **)(iVar4 + 0x2940),*(ResTIMG **)(iVar3 + 0x2f34),'\0');
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar4 + 0x2940));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(iVar4 + 0x29b0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar4 + 0x2940));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar4 + 0x29b0));
    *(undefined4 *)(iVar3 + 0x2f24) = 0;
    iVar2 = iVar2 + 1;
    iVar6 = iVar6 + 0x38;
    iVar5 = iVar5 + 4;
  } while (iVar2 < 2);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x801ffe88) */
/* WARNING: Removing unreachable block (ram,0x801ffe90) */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall dMeter_arwMove(sub_meter_class *) */

void dMeter_arwMove(daArrow_c *param_1)

{
  short sVar1;
  float fVar2;
  daArrow_c *this;
  int iVar3;
  JPABaseEmitter *pJVar4;
  undefined *puVar5;
  cCcD_GObjInf__vtbl *pcVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  fopMsgM_pane_class *pfVar10;
  fopMsgM_pane_class *pfVar11;
  int iVar12;
  undefined4 uVar13;
  double dVar14;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar15;
  cXyz local_78;
  cXyz local_6c [4];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar13 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (init_11960 == '\0') {
    arrowType_11959 = daArrow_c::getKeepType(param_1);
    init_11960 = '\x01';
  }
  if (init_11963 == '\0') {
    oldType_11962 = arrowType_11959;
    init_11963 = '\x01';
  }
  dVar15 = (double)(*(float *)&param_1[5].field_0x6b0 - *(float *)&param_1[5].field_0x6e6.y);
  if ((((((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x1000U) == 0) ||
        (uVar7 = *(uint *)&param_1[6].field_0x5ec, (uVar7 & 0x4000) != 0)) || ((uVar7 & 0x40) != 0))
      || ((((uVar7 & 0x200000) != 0 || ((uVar7 & 0x80) != 0)) ||
          (((uVar7 & 0x100000) != 0 || (((uVar7 & 0x20000) != 0 || ((uVar7 & 8) != 0)))))))) ||
     (((uVar7 & 0x10) != 0 ||
      (((((uVar7 & 0x800000) != 0 || ((uVar7 & 0x20) != 0)) || ((uVar7 & 0x100) != 0)) ||
       (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda == 8)))))) {
    if (*(short *)((int)&param_1[6].parent.parent.parent.mBsPcId + 2) != 0) {
      *(undefined2 *)((int)&param_1[6].parent.parent.parent.mBsPcId + 2) = 0;
    }
    if (0 < *(short *)&param_1[5].field_0x6d2) {
      *(short *)&param_1[5].field_0x6d2 = *(short *)&param_1[5].field_0x6d2 + -1;
      if (*(short *)&param_1[5].field_0x6d2 == 0) {
        iVar8 = 0;
        iVar12 = 0;
        iVar3 = 0;
        do {
          iVar9 = (int)&(param_1->parent).parent.parent.mBsType + iVar3;
          pfVar10 = (fopMsgM_pane_class *)(iVar9 + 0x2940);
          f_op_msg_mng::fopMsgM_setNowAlphaZero(pfVar10);
          pfVar11 = (fopMsgM_pane_class *)(iVar9 + 0x29b0);
          f_op_msg_mng::fopMsgM_setNowAlphaZero(pfVar11);
          f_op_msg_mng::fopMsgM_setAlpha(pfVar10);
          f_op_msg_mng::fopMsgM_setAlpha(pfVar11);
          iVar9 = *(int *)((int)&param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl +
                          iVar12);
          if (iVar9 != 0) {
            *(undefined4 *)(iVar9 + 0x60) = 0xffffffff;
            *(uint *)(iVar9 + 0x20c) = *(uint *)(iVar9 + 0x20c) | 1;
            iVar9 = *(int *)((int)&param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl +
                            iVar12);
            *(uint *)(iVar9 + 0x20c) = *(uint *)(iVar9 + 0x20c) | 4;
            iVar9 = *(int *)((int)&param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl +
                            iVar12);
            *(uint *)(iVar9 + 0x20c) = *(uint *)(iVar9 + 0x20c) & 0xffffffbf;
            *(undefined4 *)
             ((int)&param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl + iVar12) = 0;
          }
          iVar8 = iVar8 + 1;
          iVar12 = iVar12 + 4;
          iVar3 = iVar3 + 0x38;
        } while (iVar8 < 2);
      }
      else {
        dVar14 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                   (10,(int)*(short *)&param_1[5].field_0x6d2,0);
        dVar15 = _4620;
        iVar3 = 0;
        iVar12 = 2;
        do {
          iVar8 = (int)&(param_1->parent).parent.parent.mBsType + iVar3;
          *(char *)(*(int *)(iVar8 + 0x2940) + 0xac) =
               (char)(int)((double)(float)((double)CONCAT44(0x43300000,
                                                            (uint)*(byte *)(iVar8 + 0x2975)) -
                                          dVar15) * dVar14);
          *(char *)(*(int *)(iVar8 + 0x29b0) + 0xac) =
               (char)(int)((double)(float)((double)CONCAT44(0x43300000,
                                                            (uint)*(byte *)(iVar8 + 0x29e5)) -
                                          dVar15) * dVar14);
          iVar3 = iVar3 + 0x38;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
    }
  }
  else {
    uVar7 = daArrow_c::getKeepType((daArrow_c *)&d_com_inf_game::g_dComIfG_gameInfo);
    if ((uint)arrowType_11959 != (uVar7 & 0xff)) {
      JKRArchive::readTypeResource
                ((void *)param_1[6].field_0x4d4.parent.parent.mDivideInfo.mRangeBits,0xc00,
                 0x54494d47,(&arrowTexImage)[arrowType_11959],
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
      os::DCStoreRangeNoSync(param_1[6].field_0x4d4.parent.parent.mDivideInfo.mRangeBits,0xc00);
      this = (daArrow_c *)
             J2DPicture::changeTexture
                       (*(J2DPicture **)&param_1[5].field_0x62c,
                        (ResTIMG *)param_1[6].field_0x4d4.parent.parent.mDivideInfo.mRangeBits,'\0')
      ;
      oldType_11962 = arrowType_11959;
      arrowType_11959 = daArrow_c::getKeepType(this);
      JKRArchive::readTypeResource
                (param_1[6].field_0x4d4.parent.parent.mDivideInfo.vtbl,0xc00,0x54494d47,
                 (&arrowTexImage)[arrowType_11959],
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
      os::DCStoreRangeNoSync(param_1[6].field_0x4d4.parent.parent.mDivideInfo.vtbl,0xc00);
      J2DPicture::changeTexture
                (*(J2DPicture **)&param_1[5].field_0x664,
                 (ResTIMG *)param_1[6].field_0x4d4.parent.parent.mDivideInfo.vtbl,'\0');
      *(undefined2 *)&param_1[5].field_0x6d2 = 0;
      sVar1 = *(short *)((int)&param_1[6].parent.parent.parent.mBsPcId + 2);
      if (sVar1 < 2) {
        *(short *)((int)&param_1[6].parent.parent.parent.mBsPcId + 2) = sVar1 + 1;
      }
      iVar3 = 0;
      iVar12 = 2;
      do {
        iVar8 = *(int *)((int)&param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl +
                        iVar3);
        if (iVar8 != 0) {
          *(undefined4 *)(iVar8 + 0x60) = 0xffffffff;
          *(uint *)(iVar8 + 0x20c) = *(uint *)(iVar8 + 0x20c) | 1;
          iVar8 = *(int *)((int)&param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl +
                          iVar3);
          *(uint *)(iVar8 + 0x20c) = *(uint *)(iVar8 + 0x20c) | 4;
          iVar8 = *(int *)((int)&param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl +
                          iVar3);
          *(uint *)(iVar8 + 0x20c) = *(uint *)(iVar8 + 0x20c) & 0xffffffbf;
          *(undefined4 *)
           ((int)&param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl + iVar3) = 0;
        }
        iVar3 = iVar3 + 4;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
    }
    if (oldType_11962 == 0) {
      puVar5 = param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl;
      if (puVar5 != (undefined *)0x0) {
        *(undefined4 *)(puVar5 + 0x60) = 0xffffffff;
        *(uint *)(puVar5 + 0x20c) = *(uint *)(puVar5 + 0x20c) | 1;
        puVar5 = param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl;
        *(uint *)(puVar5 + 0x20c) = *(uint *)(puVar5 + 0x20c) | 4;
        puVar5 = param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl;
        *(uint *)(puVar5 + 0x20c) = *(uint *)(puVar5 + 0x20c) & 0xffffffbf;
        param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl = (undefined *)0x0;
      }
    }
    else {
      if (param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl == (undefined *)0x0) {
        local_6c[0].y = *(float *)&param_1[5].field_0x6bc - _7213;
        local_6c[0].x = *(float *)&param_1[5].field_0x6b8 - _7214;
        local_6c[0].z = 0_0;
        pJVar4 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,7,
                                    *(ushort *)((int)&_11762 + (uint)oldType_11962 * 2 + 2),local_6c
                                    ,(csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                                    (_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
        param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl = (undefined *)pJVar4;
      }
    }
    if (arrowType_11959 == 0) {
      pcVar6 = param_1[6].field_0x4d4.parent.parent.parent.vtbl;
      if (pcVar6 != (cCcD_GObjInf__vtbl *)0x0) {
        pcVar6[2].GetGObjInf_1 = &DAT_ffffffff;
        pcVar6[0xd].field_0x4 = (undefined *)((uint)pcVar6[0xd].field_0x4 | 1);
        pcVar6 = param_1[6].field_0x4d4.parent.parent.parent.vtbl;
        pcVar6[0xd].field_0x4 = (undefined *)((uint)pcVar6[0xd].field_0x4 | 4);
        pcVar6 = param_1[6].field_0x4d4.parent.parent.parent.vtbl;
        pcVar6[0xd].field_0x4 = (undefined *)((uint)pcVar6[0xd].field_0x4 & 0xffffffbf);
        param_1[6].field_0x4d4.parent.parent.parent.vtbl = (cCcD_GObjInf__vtbl *)0x0;
      }
    }
    else {
      if (param_1[6].field_0x4d4.parent.parent.parent.vtbl == (cCcD_GObjInf__vtbl *)0x0) {
        local_78.y = *(float *)&param_1[5].field_0x6f4 - _7213;
        local_78.x = *(float *)&param_1[5].field_0x6b8 - _7214;
        local_78.z = 0_0;
        pJVar4 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,7,
                                    *(ushort *)((int)&_11762 + (uint)arrowType_11959 * 2 + 2),
                                    &local_78,(csXyz *)0x0,(cXyz *)0x0,0xff,
                                    (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                                    (cXyz *)0x0);
        param_1[6].field_0x4d4.parent.parent.parent.vtbl = (cCcD_GObjInf__vtbl *)pJVar4;
      }
    }
    if (*(short *)((int)&param_1[6].parent.parent.parent.mBsPcId + 2) == 0) {
      *(undefined2 *)((int)&param_1[6].parent.parent.parent.mBsPcId + 2) = 1;
    }
    if (*(short *)&param_1[5].field_0x6d2 < 10) {
      *(short *)&param_1[5].field_0x6d2 = *(short *)&param_1[5].field_0x6d2 + 1;
      if (*(short *)&param_1[5].field_0x6d2 == 10) {
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)&param_1[5].field_0x62c);
        f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)&param_1[5].field_0x69c);
        f_op_msg_mng::fopMsgM_setInitAlpha(&param_1[5].field_0x664);
        f_op_msg_mng::fopMsgM_setInitAlpha(&param_1[5].field_0x6d4);
        iVar3 = 0;
        iVar12 = 0;
        do {
          iVar8 = (int)&(param_1->parent).parent.parent.mBsType + iVar12;
          f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(iVar8 + 0x2940),dVar15,(double)0_0)
          ;
          f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(iVar8 + 0x29b0),dVar15,(double)0_0)
          ;
          iVar3 = iVar3 + 1;
          iVar12 = iVar12 + 0x38;
        } while (iVar3 < 2);
      }
      else {
        dVar14 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                   (10,(int)*(short *)&param_1[5].field_0x6d2,0);
        dVar15 = (double)(float)(dVar15 * dVar14);
        iVar3 = 0;
        iVar12 = 0;
        do {
          iVar8 = (int)&(param_1->parent).parent.parent.mBsType + iVar12;
          f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(iVar8 + 0x2940),dVar15,(double)0_0)
          ;
          f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(iVar8 + 0x29b0),dVar15,(double)0_0)
          ;
          iVar3 = iVar3 + 1;
          iVar12 = iVar12 + 0x38;
        } while (iVar3 < 2);
        f_op_msg_mng::fopMsgM_setNowAlpha
                  ((fopMsgM_pane_class *)&param_1[5].field_0x664,(float)dVar14);
        f_op_msg_mng::fopMsgM_setNowAlpha
                  ((fopMsgM_pane_class *)&param_1[5].field_0x6d4,(float)dVar14);
        if (*(short *)((int)&param_1[6].parent.parent.parent.mBsPcId + 2) == 2) {
          dVar15 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                     (10,10 - *(short *)&param_1[5].field_0x6d2,0);
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)&param_1[5].field_0x62c,(float)dVar15);
          f_op_msg_mng::fopMsgM_setNowAlpha
                    ((fopMsgM_pane_class *)&param_1[5].field_0x69c,(float)dVar15);
        }
        else {
          f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)&param_1[5].field_0x62c);
          f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)&param_1[5].field_0x69c);
        }
      }
    }
    iVar3 = 0;
    iVar12 = 0;
    do {
      iVar8 = (int)&(param_1->parent).parent.parent.mBsType + iVar12;
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar8 + 0x2940));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar8 + 0x29b0));
      iVar3 = iVar3 + 1;
      iVar12 = iVar12 + 0x38;
    } while (iVar3 < 2);
  }
  iVar3 = 0;
  iVar12 = 0;
  iVar8 = 2;
  do {
    iVar9 = *(int *)((int)&param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl + iVar12);
    if (iVar9 != 0) {
      *(uint *)(iVar9 + 0x20c) = *(uint *)(iVar9 + 0x20c) & 0xfffffffb;
      fVar2 = *(float *)&param_1[5].field_0x6f4 - _7213;
      iVar9 = *(int *)((int)&param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl + iVar12
                      );
      *(float *)(iVar9 + 0x1e4) = *(float *)&param_1[5].field_0x6f0 - _7214;
      *(float *)(iVar9 + 0x1e8) = fVar2;
      *(float *)(iVar9 + 0x1ec) = 0_0;
      *(undefined *)
       (*(int *)((int)&param_1[6].field_0x4d4.parent.parent.parent.mObjCo.parent.vtbl + iVar12) +
       0x1ff) = *(undefined *)(&param_1[5].field_0x661 + iVar3);
    }
    iVar3 = iVar3 + 0x38;
    iVar12 = iVar12 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  __psq_l0(auStack8,uVar13);
  __psq_l1(auStack8,uVar13);
  __psq_l0(auStack24,uVar13);
  __psq_l1(auStack24,uVar13);
  return;
}


/* __stdcall dMeter_moveItemInit(sub_meter_class *) */

void dMeter_moveItemInit(int param_1)

{
  J2DPicture *this;
  
  JKRArchive::readTypeResource
            (*(void **)(param_1 + 0x2f60),0xc00,0x54494d47,
             dItem_data::item_resource[39].mIconFilename,
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
  os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0x2f60),0xc00);
  this = (J2DPicture *)JKernel::operator_new(0x124);
  if (this != (J2DPicture *)0x0) {
    J2DPicture::J2DPicture(this,*(ResTIMG **)(param_1 + 0x2f60));
  }
  moveItemPane = this;
  return;
}


/* WARNING: Removing unreachable block (ram,0x80200370) */
/* WARNING: Removing unreachable block (ram,0x80200378) */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall dMeter_moveItemMove(sub_meter_class *) */

void dMeter_moveItemMove(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double in_f30;
  double in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  bVar1 = DAT_803e6b34;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,SUB84(in_f30,0),0);
  if (dMeter_itemTimer == 0) {
    uVar2 = (uint)dMeter_itemNum;
    if (uVar2 < 0x30) {
      if (uVar2 < 0x24) {
        if (uVar2 < 0x18) {
          if (uVar2 < 0x15) {
            uVar2 = (uint)(byte)(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                  mReturnPlace)[1].mStageName[uVar2];
          }
          else {
            if (uVar2 < 0x18) {
              uVar2 = 0xff;
            }
            else {
              if (uVar2 < 0x20) {
                uVar2 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar2 + 0xd];
              }
              else {
                if (uVar2 < 0x24) {
                  uVar2 = 0xff;
                }
                else {
                  if (uVar2 < 0x2c) {
                    uVar2 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                  mBits[uVar2 + 9];
                  }
                  else {
                    if (uVar2 < 0x30) {
                      uVar2 = 0xff;
                    }
                    else {
                      if (uVar2 < 0x38) {
                        uVar2 = (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                      mGetItem.mBits[uVar2 + 5];
                      }
                      else {
                        uVar2 = 0xff;
                      }
                    }
                  }
                }
              }
            }
          }
          if ((uVar2 == 0x35) || (uVar2 == 0x36)) {
            uVar2 = 0x27;
          }
          JKRArchive::readTypeResource
                    (*(void **)(param_1 + 0x2f60),0xc00,0x54494d47,
                     dItem_data::item_resource[uVar2].mIconFilename,
                     d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
          os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0x2f60),0xc00);
          J2DPicture::changeTexture(moveItemPane,*(ResTIMG **)(param_1 + 0x2f60),'\0');
        }
        else {
          JKRArchive::readTypeResource
                    (*(void **)(param_1 + 0x2f60),0xc00,0x54494d47,
                     dItem_data::item_resource
                     [d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar2 + 0xd]].mIconFilename,
                     d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
          os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0x2f60),0xc00);
          J2DPicture::changeTexture(moveItemPane,*(ResTIMG **)(param_1 + 0x2f60),'\0');
        }
      }
      else {
        JKRArchive::readTypeResource
                  (*(void **)(param_1 + 0x2f60),0xc00,0x54494d47,
                   dItem_data::item_resource
                   [d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar2 + 9]].mIconFilename,
                   d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
        os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0x2f60),0xc00);
        J2DPicture::changeTexture(moveItemPane,*(ResTIMG **)(param_1 + 0x2f60),'\0');
      }
    }
    else {
      JKRArchive::readTypeResource
                (*(void **)(param_1 + 0x2f60),0xc00,0x54494d47,
                 dItem_data::item_resource
                 [d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar2 + 5]
                 ].mIconFilename,d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
      os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0x2f60),0xc00);
      J2DPicture::changeTexture(moveItemPane,*(ResTIMG **)(param_1 + 0x2f60),'\0');
    }
  }
  if (dMeter_btn_chk == '\0') {
    in_f31 = (double)(*(float *)(param_1 + 0x209c) - DAT_803e68ac);
    in_f30 = (double)(*(float *)(param_1 + 0x20a0) - DAT_803e68b0);
  }
  else {
    if (dMeter_btn_chk == '\x01') {
      in_f31 = (double)(*(float *)(param_1 + 0x20d4) - DAT_803e68ac);
      in_f30 = (double)(*(float *)(param_1 + 0x20d8) - DAT_803e68b0);
    }
    else {
      if (dMeter_btn_chk == '\x02') {
        in_f31 = (double)(*(float *)(param_1 + 0x210c) - DAT_803e68ac);
        in_f30 = (double)(*(float *)(param_1 + 0x2110) - DAT_803e68b0);
      }
    }
  }
  dMeter_itemTimer = dMeter_itemTimer + 1;
  iVar3 = (int)(short)(ushort)bVar1;
  if (dMeter_itemTimer <= iVar3) {
    dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar3,(int)dMeter_itemTimer,2);
    DAT_803e68b4 = DAT_803e68ac + (float)(in_f31 * dVar5);
    DAT_803e68b8 = DAT_803e68b0 + (float)(in_f30 * dVar5);
    DAT_803e68c4 = DAT_803e68bc * DAT_803e6a74;
    DAT_803e68c8 = DAT_803e68c0 * DAT_803e6a74;
    if (DAT_803e6b35 == 2) {
      DAT_803e68c4 = DAT_803e68c4 -
                     (float)((double)(DAT_803e68c4 - *(float *)(param_1 + 0x20a4)) * dVar5);
      DAT_803e68c8 = DAT_803e68c8 -
                     (float)((double)(DAT_803e68c8 - *(float *)(param_1 + 0x20a8)) * dVar5);
    }
    else {
      if ((1 < DAT_803e6b35) || (DAT_803e6b35 == 0)) {
        DAT_803e68c4 = DAT_803e68bc;
        DAT_803e68c8 = DAT_803e68c0;
      }
    }
    DAT_803e68a4 = DAT_803e68b4 - DAT_803e68c4 * _4664;
    DAT_803e68a8 = DAT_803e68b8 - DAT_803e68c8 * _4664;
    if ((int)dMeter_itemTimer == iVar3 + -1) {
      dMeter_itemMoveFlag = 2;
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return;
}


/* __stdcall dMeter_moveItemDraw(sub_meter_class *) */

void dMeter_moveItemDraw(void)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = DAT_803e6b34;
  cVar2 = dMeter_itemMoveFlagCheck();
  if ((((cVar2 != '\0') && (dMeter_itemTimer != 0)) && (moveItemPane != (J2DPicture *)0x0)) &&
     (J2DPicture::draw(moveItemPane,DAT_803e68a4,DAT_803e68a8,DAT_803e68c4,DAT_803e68c8,false,false,
                       false), (short)(ushort)bVar1 <= dMeter_itemTimer)) {
    dMeter_itemMoveFlag = 0;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x80200530) */
/* __stdcall dMeter_swimTransY(sub_meter_class *,
                               float) */

void dMeter_swimTransY(sub_meter_class *param_1,double param_2)

{
  float fVar1;
  int iVar2;
  sub_meter_class *local_r4_48;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  fVar1 = _4664;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar2 = 0;
  iVar3 = 9;
  do {
    local_r4_48 = (sub_meter_class *)(&param_1->field_0x0 + iVar2);
    local_r4_48->field_0x2a90[0].mPosCenterOrig.y =
         (float)(param_2 +
                (double)(local_r4_48->field_0x2a90[0].mPosTopLeftOrig.y +
                        local_r4_48->field_0x2a90[0].mSizeOrig.y * fVar1));
    iVar2 = iVar2 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  (param_1->field_0x2c88).mPosCenterOrig.y =
       (float)(param_2 +
              (double)((param_1->field_0x2c88).mPosTopLeftOrig.y +
                      (param_1->field_0x2c88).mSizeOrig.y * _4664));
  f_op_msg_mng::fopMsgM_paneTrans(&param_1->field_0x2c88,(double)0_0,(double)0_0);
  (param_1->field_0x2cc0).mPosCenterOrig.y =
       (float)(param_2 +
              (double)((param_1->field_0x2cc0).mPosTopLeftOrig.y +
                      (param_1->field_0x2cc0).mSizeOrig.y * _4664));
  f_op_msg_mng::fopMsgM_paneTrans(&param_1->field_0x2cc0,(double)0_0,(double)0_0);
  (param_1->field_0x2d30).mPosCenterOrig.y =
       (float)(param_2 +
              (double)((param_1->field_0x2d30).mPosTopLeftOrig.y +
                      (param_1->field_0x2d30).mSizeOrig.y * _4664));
  f_op_msg_mng::fopMsgM_paneTrans(&param_1->field_0x2d30,(double)0_0,(double)0_0);
  (param_1->field_0x2dd8).mPosCenterOrig.y =
       (float)(param_2 +
              (double)((param_1->field_0x2dd8).mPosTopLeftOrig.y +
                      (param_1->field_0x2dd8).mSizeOrig.y * _4664));
  f_op_msg_mng::fopMsgM_paneTrans(&param_1->field_0x2dd8,(double)0_0,(double)0_0);
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* __stdcall dMeter_swimPaneShow(sub_meter_class *) */

void dMeter_swimPaneShow(int param_1)

{
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x2cf8);
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x2da0);
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x2d30);
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x2c88);
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0x2dd8);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMeter_swimPaneHide(sub_meter_class *) */

void dMeter_swimPaneHide(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + iVar2 + 0x2a90));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 9);
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2c88));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2cc0));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2cf8));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2d30));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2da0));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2dd8));
  DAT_803e6c9b = 0;
  return;
}


/* WARNING: Removing unreachable block (ram,0x80200690) */
/* __stdcall dMeter_swimPaneTransY(sub_meter_class *,
                                   float) */

void dMeter_swimPaneTransY(double param_1,int param_2)

{
  undefined4 uVar1;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_2 + 0x2d30),(double)0_0,param_1);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_2 + 0x2c88),(double)0_0,param_1);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_2 + 0x2cf8),(double)0_0,(double)0_0);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(param_2 + 0x2da0),(double)0_0,(double)0_0);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* __stdcall dMeter_swimPaneAlpha(sub_meter_class *,
                                  float) */

void dMeter_swimPaneAlpha(double param_1,int param_2)

{
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x2cf8),(float)param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x2da0),(float)param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x2d30),(float)param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_2 + 0x2c88),(float)param_1);
  return;
}


/* __stdcall dMeter_swimInit(sub_meter_class *) */

void dMeter_swimInit(sub_meter_class *this)

{
  bool bVar1;
  float fVar2;
  int iVar3;
  ResTIMG *ctx;
  ResTIMG *pRVar4;
  ulong uVar5;
  undefined local_28;
  undefined uStack39;
  undefined uStack38;
  undefined uStack37;
  undefined local_24;
  undefined uStack35;
  undefined uStack34;
  undefined uStack33;
  undefined local_20;
  undefined uStack31;
  undefined uStack30;
  undefined uStack29;
  
  dMeter_screenDataTimeSet(this);
  dMeter_swimPaneHide(this);
  iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  if ((*(byte *)(iVar3 + 9) & 1) == 0) {
    dMeter_swimTransY(this,(double)(_12424 + (float)((double)CONCAT44(0x43300000,
                                                                      (int)DAT_803e6a42 ^ 0x80000000
                                                                     ) - _4622)));
  }
  fVar2 = (this->field_0x2c88).mpPane[1].parent.mBox.mBR.x;
  local_20 = (undefined)((uint)fVar2 >> 0x18);
  *(undefined *)&this->field_0x2ef0 = local_20;
  uStack31 = (undefined)((uint)fVar2 >> 0x10);
  *(undefined *)&this->field_0x2ef1 = uStack31;
  uStack30 = (undefined)((uint)fVar2 >> 8);
  *(undefined *)&this->field_0x2ef2 = uStack30;
  uStack29 = SUB41(fVar2,0);
  *(undefined *)&this->field_0x2ef3 = uStack29;
  fVar2 = (this->field_0x2c88).mpPane[1].parent.mBox.mTL.y;
  local_24 = (undefined)((uint)fVar2 >> 0x18);
  *(undefined *)&this->field_0x2ef4 = local_24;
  uStack35 = (undefined)((uint)fVar2 >> 0x10);
  *(undefined *)&this->field_0x2ef5 = uStack35;
  uStack34 = (undefined)((uint)fVar2 >> 8);
  *(undefined *)&this->field_0x2ef6 = uStack34;
  uStack33 = SUB41(fVar2,0);
  *(undefined *)&this->field_0x2ef7 = uStack33;
  fVar2 = (this->field_0x2da0).mpPane[1].parent.mBox.mBR.x;
  local_28 = (undefined)((uint)fVar2 >> 0x18);
  *(undefined *)&this->field_0x2f00 = local_28;
  uStack39 = (undefined)((uint)fVar2 >> 0x10);
  *(undefined *)&this->field_0x2f01 = uStack39;
  uStack38 = (undefined)((uint)fVar2 >> 8);
  *(undefined *)&this->field_0x2f02 = uStack38;
  uStack37 = SUB41(fVar2,0);
  *(undefined *)&this->field_0x2f03 = uStack37;
  (this->field_0x2da0).mUserData = 0;
  (this->field_0x2c88).mUserData = 0;
  (this->field_0x2dd8).mUserData = 0;
  ctx = (ResTIMG *)
        JKRArchive::getGlbResource
                  (0x54494d47,"swimtime_meter_mask.bti",
                   d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpSwimResArchive);
  pRVar4 = (ResTIMG *)
           JKRArchive::getGlbResource
                     (0x54494d47,"tekari.bti",
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpSwimResArchive);
  bVar1 = false;
  if ((ctx != (ResTIMG *)0x0) && (pRVar4 != (ResTIMG *)0x0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_meter.cpp",0x2cea,"texture1 != 0 && texture2 != 0");
    m_Do_printf::OSPanic("d_meter.cpp",0x2cea,&DAT_80361783);
  }
  ::dDlst_2Dm_c::init(&tekari,ctx,pRVar4,1_0,1_0);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __stdcall dMeter_swimMove(sub_meter_class *) */

void dMeter_swimMove(sub_meter_class *param_1)

{
  short sVar1;
  undefined4 uVar2;
  J2DScreen *pJVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  undefined local_18;
  undefined uStack23;
  undefined uStack22;
  undefined uStack21;
  undefined local_14;
  undefined uStack19;
  undefined uStack18;
  undefined uStack17;
  undefined local_10;
  undefined uStack15;
  undefined uStack14;
  undefined uStack13;
  undefined local_c;
  undefined uStack11;
  undefined uStack10;
  undefined uStack9;
  
  if ((int)((d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48c8 >> 1) +
           (uint)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48c8 < 0 &&
                 (d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48c8 & 1U) != 0)) <=
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAirMeter) {
    *(undefined *)&param_1->field_0x2f04 = 200;
    *(undefined *)&param_1->field_0x2f05 = 200;
    *(undefined *)&param_1->field_0x2f06 = 0xff;
    *(undefined *)&param_1->field_0x2ef8 = *(undefined *)&param_1->field_0x2ef0;
    *(undefined *)&param_1->field_0x2ef9 = *(undefined *)&param_1->field_0x2ef1;
    *(undefined *)&param_1->field_0x2efa = *(undefined *)&param_1->field_0x2ef2;
    *(undefined *)&param_1->field_0x2efb = *(undefined *)&param_1->field_0x2ef3;
    *(undefined *)&param_1->field_0x2efc = *(undefined *)&param_1->field_0x2ef4;
    *(undefined *)&param_1->field_0x2efd = *(undefined *)&param_1->field_0x2ef5;
    *(undefined *)&param_1->field_0x2efe = *(undefined *)&param_1->field_0x2ef6;
    *(undefined *)&param_1->field_0x2eff = *(undefined *)&param_1->field_0x2ef7;
    *(int *)&param_1->field_0x3000 = (int)DAT_803e6a38;
  }
  sVar1 = (param_1->field_0x2da0).mUserData;
  if (sVar1 == 0) {
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAirMeter != 0) {
      if ((sScrTimer1 == (J2DScreen *)0x0) && (sScrTimer2 == (J2DScreen *)0x0)) {
        dMeter_swimInit(param_1);
      }
      (param_1->field_0x2da0).mUserData = 1;
      *(undefined2 *)&param_1->field_0x3010 = 0;
      (param_1->field_0x2c88).mUserData = 0;
      (param_1->field_0x2dd8).mUserData = 0;
      (param_1->field_0x2cf8).mUserData = 0;
      (param_1->field_0x2d30).mUserData = (short)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAirMeter;
      dMeter_xyRotateZ((double)0_0,(double)0_0,&param_1->field_0x2cf8);
      uVar2 = *(undefined4 *)&param_1->field_0x2ef0;
      pJVar3 = (param_1->field_0x2c88).mpPane;
      local_c = (undefined)((uint)uVar2 >> 0x18);
      *(undefined *)&pJVar3[1].parent.mBox.mBR.x = local_c;
      uStack11 = (undefined)((uint)uVar2 >> 0x10);
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 1) = uStack11;
      uStack10 = (undefined)((uint)uVar2 >> 8);
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 2) = uStack10;
      uStack9 = (undefined)uVar2;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 3) = uStack9;
      uVar2 = *(undefined4 *)&param_1->field_0x2ef4;
      pJVar3 = (param_1->field_0x2c88).mpPane;
      local_10 = (undefined)((uint)uVar2 >> 0x18);
      *(undefined *)&pJVar3[1].parent.mBox.mTL.y = local_10;
      uStack15 = (undefined)((uint)uVar2 >> 0x10);
      *(undefined *)((int)&pJVar3[1].parent.mBox.mTL.y + 1) = uStack15;
      uStack14 = (undefined)((uint)uVar2 >> 8);
      *(undefined *)((int)&pJVar3[1].parent.mBox.mTL.y + 2) = uStack14;
      uStack13 = (undefined)uVar2;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mTL.y + 3) = uStack13;
      uVar2 = *(undefined4 *)&param_1->field_0x2f00;
      pJVar3 = (param_1->field_0x2cf8).mpPane;
      local_14 = (undefined)((uint)uVar2 >> 0x18);
      *(undefined *)&pJVar3[1].parent.mBox.mBR.x = local_14;
      uStack19 = (undefined)((uint)uVar2 >> 0x10);
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 1) = uStack19;
      uStack18 = (undefined)((uint)uVar2 >> 8);
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 2) = uStack18;
      uStack17 = (undefined)uVar2;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 3) = uStack17;
      uVar2 = *(undefined4 *)&param_1->field_0x2f00;
      pJVar3 = (param_1->field_0x2da0).mpPane;
      local_18 = (undefined)((uint)uVar2 >> 0x18);
      *(undefined *)&pJVar3[1].parent.mBox.mBR.x = local_18;
      uStack23 = (undefined)((uint)uVar2 >> 0x10);
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 1) = uStack23;
      uStack22 = (undefined)((uint)uVar2 >> 8);
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 2) = uStack22;
      uStack21 = (undefined)uVar2;
      *(undefined *)((int)&pJVar3[1].parent.mBox.mBR.x + 3) = uStack21;
      *(undefined2 *)&param_1->field_0x2fc4 = 0;
      *(undefined *)&param_1->field_0x2f04 = 200;
      *(undefined *)&param_1->field_0x2f05 = 200;
      *(undefined *)&param_1->field_0x2f06 = 0xff;
      *(undefined *)&param_1->field_0x2ef8 = *(undefined *)&param_1->field_0x2ef0;
      *(undefined *)&param_1->field_0x2ef9 = *(undefined *)&param_1->field_0x2ef1;
      *(undefined *)&param_1->field_0x2efa = *(undefined *)&param_1->field_0x2ef2;
      *(undefined *)&param_1->field_0x2efb = *(undefined *)&param_1->field_0x2ef3;
      *(undefined *)&param_1->field_0x2efc = *(undefined *)&param_1->field_0x2ef4;
      *(undefined *)&param_1->field_0x2efd = *(undefined *)&param_1->field_0x2ef5;
      *(undefined *)&param_1->field_0x2efe = *(undefined *)&param_1->field_0x2ef6;
      *(undefined *)&param_1->field_0x2eff = *(undefined *)&param_1->field_0x2ef7;
      *(int *)&param_1->field_0x3000 = (int)DAT_803e6a38;
      iVar4 = 0;
      iVar6 = 9;
      do {
        *(undefined2 *)((int)&param_1->field_0x2a90[0].mUserData + iVar4) = 0;
        iVar4 = iVar4 + 0x38;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x83f,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
    }
  }
  else {
    if (sVar1 == 1) {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAirMeter == 0) {
        dMeter_swimPaneHide(param_1);
        (param_1->field_0x2da0).mUserData = 0;
        if ((sScrTimer1 != (J2DScreen *)0x0) && (sScrTimer2 != (J2DScreen *)0x0)) {
          (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpSwimResArchive)->parent).parent.
                    vtbl)->removeResourceAll)();
          if (sScrTimer1 != (J2DScreen *)0x0) {
            (*(code *)((sScrTimer1->parent).vtbl)->_J2DPane)(sScrTimer1,1);
          }
          if (sScrTimer2 != (J2DScreen *)0x0) {
            (*(code *)((sScrTimer2->parent).vtbl)->_J2DPane)(sScrTimer2,1);
          }
          sScrTimer1 = (J2DScreen *)0x0;
          sScrTimer2 = (J2DScreen *)0x0;
        }
      }
      else {
        bVar5 = dMenu_flag();
        if (((bVar5 == 0) && (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0)) &&
           (d_com_inf_game::g_dComIfG_gameInfo._23496_1_ != '\0')) {
          dMeter_swimOpenProc(param_1);
        }
        else {
          dMeter_swimPaneHide(param_1);
        }
      }
    }
    else {
      if (sVar1 == 2) {
        if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAirMeter == 0) {
          dMeter_swimPaneHide(param_1);
          (param_1->field_0x2da0).mUserData = 0;
          if ((sScrTimer1 != (J2DScreen *)0x0) && (sScrTimer2 != (J2DScreen *)0x0)) {
            (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpSwimResArchive)->parent).parent.
                      vtbl)->removeResourceAll)();
            if (sScrTimer1 != (J2DScreen *)0x0) {
              (*(code *)((sScrTimer1->parent).vtbl)->_J2DPane)(sScrTimer1,1);
            }
            if (sScrTimer2 != (J2DScreen *)0x0) {
              (*(code *)((sScrTimer2->parent).vtbl)->_J2DPane)(sScrTimer2,1);
            }
            sScrTimer1 = (J2DScreen *)0x0;
            sScrTimer2 = (J2DScreen *)0x0;
          }
        }
        else {
          bVar5 = dMenu_flag();
          if (((bVar5 == 0) && (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0)) &&
             (d_com_inf_game::g_dComIfG_gameInfo._23496_1_ != '\0')) {
            dMeter_swimMoveProc(param_1);
          }
          else {
            dMeter_swimPaneHide(param_1);
          }
        }
      }
      else {
        if (sVar1 == 3) {
          bVar5 = dMenu_flag();
          if (bVar5 == 0) {
            dMeter_swimMoveProc(param_1);
          }
          else {
            dMeter_swimPaneHide(param_1);
          }
        }
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMeter_swimDraw(sub_meter_class *) */

void dMeter_swimDraw(sub_meter_class *this)

{
  int iVar1;
  int iVar2;
  
  if (sScrTimer2 != (J2DScreen *)0x0) {
    iVar1 = 0;
    iVar2 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha
                ((fopMsgM_pane_class *)((int)&this->field_0x2a90[0].mpPane + iVar2));
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x38;
    } while (iVar1 < 9);
    f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x2c88);
    f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x2cc0);
  }
  if (sScrTimer1 != (J2DScreen *)0x0) {
    f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x2cf8);
    f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x2da0);
    f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x2d30);
    f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x2dd8);
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x802011b0) */
/* __stdcall dMeter_swimOpenProc(sub_meter_class *) */

void dMeter_swimOpenProc(int param_1)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  sVar1 = *(short *)(param_1 + 0x2cbe) + 1;
  *(short *)(param_1 + 0x2cbe) = sVar1;
  iVar2 = (int)sVar1;
  if (init_12566 == '\0') {
    dist_buf_12565 = 0_0;
    init_12566 = '\x01';
  }
  if (iVar2 == 1) {
    f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(param_1 + 0x2dd8),0_1);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2dd8));
  }
  else {
    if (iVar2 < 5) {
      dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(4,iVar2 + -1,0);
      f_op_msg_mng::fopMsgM_paneScaleXY
                ((fopMsgM_pane_class *)(param_1 + 0x2dd8),0_1 + (float)((double)_12626 * dVar4));
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(param_1 + 0x2dd8),(float)dVar4);
    }
    else {
      if (iVar2 < 8) {
        dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(3,iVar2 + -5,0);
        f_op_msg_mng::fopMsgM_paneScaleXY
                  ((fopMsgM_pane_class *)(param_1 + 0x2dd8),1_0 - (float)((double)_12627 * dVar4));
      }
      else {
        if (iVar2 < 10) {
          dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(2,iVar2 + -8,0);
          f_op_msg_mng::fopMsgM_paneScaleXY
                    ((fopMsgM_pane_class *)(param_1 + 0x2dd8),
                     _4686 + (float)((double)_12627 * dVar4));
        }
        else {
          if (iVar2 < 0xc) {
            dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(2,iVar2 + -10,0);
            f_op_msg_mng::fopMsgM_paneScaleXY
                      ((fopMsgM_pane_class *)(param_1 + 0x2dd8),
                       1_0 - (float)((double)_12628 * dVar4));
          }
          else {
            if (iVar2 < 0xe) {
              dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(2,iVar2 + -0xc,0);
              f_op_msg_mng::fopMsgM_paneScaleXY
                        ((fopMsgM_pane_class *)(param_1 + 0x2dd8),
                         _12626 + (float)((double)_12628 * dVar4));
            }
            else {
              if (iVar2 == 0xe) {
                f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(param_1 + 0x2dd8),1_0);
              }
            }
          }
        }
      }
    }
  }
  if (iVar2 == 1) {
    dMeter_swimPaneTransY((double)_12629,param_1);
    f_op_msg_mng::fopMsgM_paneScaleY((double)1_0,param_1 + 0x2cf8);
    f_op_msg_mng::fopMsgM_paneScaleY((double)1_0,param_1 + 0x2da0);
    f_op_msg_mng::fopMsgM_paneScaleY((double)1_0,param_1 + 0x2d30);
    f_op_msg_mng::fopMsgM_paneScaleY((double)1_0,param_1 + 0x2c88);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2cf8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2da0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2d30));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0x2c88));
  }
  else {
    if (iVar2 < 6) {
      dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(4,iVar2 + -1,0);
      dMeter_swimPaneTransY(-(double)(_12630 * (float)((double)1_0 - dVar4)),param_1);
      dMeter_swimPaneAlpha(dVar4,param_1);
    }
    else {
      if (iVar2 < 9) {
        dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(3,iVar2 + -5,0);
        dMeter_swimPaneTransY((double)(_12631 - _12631 * (float)((double)1_0 - dVar4)),param_1);
        dMeter_swimPaneShow(param_1);
      }
      else {
        if (iVar2 < 0xb) {
          dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(2,iVar2 + -8,0);
          dMeter_swimPaneTransY(-(double)(_9164 * (float)((double)1_0 - dVar4)),param_1);
          dMeter_swimPaneShow(param_1);
        }
        else {
          if (iVar2 < 0xd) {
            dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(2,iVar2 + -10,0);
            dMeter_swimPaneTransY((double)(_12632 - _12632 * (float)((double)1_0 - dVar4)),param_1);
            dMeter_swimPaneShow(param_1);
          }
          else {
            if (iVar2 < 0xe) {
              dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(2,iVar2 + -0xc,0);
              dMeter_swimPaneTransY(-(double)(_12633 * (float)((double)1_0 - dVar4)),param_1);
              dMeter_swimPaneShow(param_1);
            }
            else {
              if (iVar2 == 0xe) {
                dMeter_swimPaneTransY((double)0_0,param_1);
                f_op_msg_mng::fopMsgM_paneScaleY((double)1_0,param_1 + 0x2cf8);
                f_op_msg_mng::fopMsgM_paneScaleY((double)1_0,param_1 + 0x2da0);
                f_op_msg_mng::fopMsgM_paneScaleY((double)1_0,param_1 + 0x2d30);
                f_op_msg_mng::fopMsgM_paneScaleY((double)1_0,param_1 + 0x2c88);
                dMeter_swimPaneShow(param_1);
                *(undefined2 *)(param_1 + 0x2cbe) = 0;
                *(undefined2 *)(param_1 + 0x2dd6) = 2;
              }
            }
          }
        }
      }
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __stdcall dMeter_swimMoveProc(sub_meter_class *) */

void dMeter_swimMoveProc(undefined4 param_1)

{
  dMeter_swimMainRotate();
  dMeter_swimMainBlink(param_1);
  dMeter_swimMainDown(param_1);
  dMeter_swimTekariScroll(param_1);
  dMeter_swimLightMove(param_1);
  dMeter_swimPaneShow(param_1);
  return;
}


/* __stdcall dMeter_swimMainRotate(sub_meter_class *) */

void dMeter_swimMainRotate(double param_1,int param_2)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  
  sVar1 = DAT_803e6a3a;
  iVar4 = (int)DAT_803e6a3a;
  sVar2 = *(short *)(param_2 + 0x2cbe) + 1;
  *(short *)(param_2 + 0x2cbe) = sVar2;
  uVar3 = SEXT24(sVar2);
  if ((int)uVar3 < iVar4) {
    param_1 = (double)((_12647 * (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - _4622)) /
                      (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - _4622));
  }
  else {
    if (uVar3 == (int)sVar1) {
      *(undefined2 *)(param_2 + 0x2cbe) = 0;
      param_1 = (double)0_0;
    }
  }
  dMeter_xyRotateZ(param_1,(double)0_0,param_2 + 0x2cf8);
  return;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __stdcall dMeter_swimMainBlink(sub_meter_class *) */

void dMeter_swimMainBlink(int param_1)

{
  bool bVar1;
  float fVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  short sVar7;
  undefined4 uVar6;
  uint uVar8;
  int iVar9;
  uint uVar10;
  double dVar11;
  undefined local_128;
  undefined uStack295;
  undefined uStack294;
  undefined uStack293;
  undefined local_124;
  undefined uStack291;
  undefined uStack290;
  undefined uStack289;
  undefined local_120;
  undefined uStack287;
  undefined uStack286;
  undefined uStack285;
  undefined local_11c;
  undefined uStack283;
  undefined uStack282;
  undefined uStack281;
  undefined local_114;
  undefined uStack275;
  undefined uStack274;
  undefined uStack273;
  undefined local_110;
  undefined uStack271;
  undefined uStack270;
  undefined uStack269;
  undefined local_10c;
  undefined uStack267;
  undefined uStack266;
  undefined uStack265;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  double local_e8;
  double local_e0;
  double local_c0;
  double local_b8;
  double local_a8;
  double local_a0;
  double local_90;
  double local_88;
  double local_78;
  double local_70;
  double local_60;
  double local_58;
  double local_48;
  double local_30;
  double local_20;
  double local_10;
  
  local_100 = *(uint *)(param_1 + 0x2f00);
  local_104 = *(uint *)(param_1 + 0x2ef0);
  local_108 = *(uint *)(param_1 + 0x2ef4);
  sVar7 = *(short *)(param_1 + 0x2e0e) + 1;
  *(short *)(param_1 + 0x2e0e) = sVar7;
  uVar10 = SEXT24(sVar7);
  uVar8 = *(uint *)(param_1 + 0x3000);
  uVar3 = (ushort)local_100;
  uVar4 = (ushort)local_104;
  uVar5 = (ushort)local_108;
  if ((int)uVar10 < (int)uVar8) {
    fVar2 = (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - _4622) /
            (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - _4622);
    local_e8 = (double)CONCAT44(0x43300000,*(byte *)(param_1 + 0x2f04) - 0x4b ^ 0x80000000);
    local_100._2_2_ =
         uVar3 & 0xff |
         (ushort)(byte)(int)(_4616 + fVar2 * (float)((double)CONCAT44(0x43300000,
                                                                      *(byte *)(param_1 + 0x2f06) -
                                                                      0xff ^ 0x80000000) - _4622))
         << 8;
    local_100 = (int)(_12773 + fVar2 * (float)(local_e8 - _4622)) << 0x18 |
                CONCAT12((char)(int)(_12773 + fVar2 * (float)((double)CONCAT44(0x43300000,
                                                                               *(byte *)(param_1 +
                                                                                        0x2f05) -
                                                                               0x4b ^ 0x80000000) -
                                                             _4622)),uVar3) & 0xffff0000 |
                (uint)local_100._2_2_;
    local_b8 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2ef0));
    local_a0 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2ef1));
    local_88 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2ef2));
    local_104._2_2_ =
         uVar4 & 0xff |
         (ushort)(byte)(int)((float)(local_88 - _4620) +
                            fVar2 * (float)((double)CONCAT44(0x43300000,
                                                             (uint)*(byte *)(param_1 + 0x2efa) -
                                                             (uint)*(byte *)(param_1 + 0x2ef2) ^
                                                             0x80000000) - _4622)) << 8;
    local_104 = (int)((float)(local_b8 - _4620) +
                     fVar2 * (float)((double)CONCAT44(0x43300000,
                                                      (uint)*(byte *)(param_1 + 0x2ef8) -
                                                      (uint)*(byte *)(param_1 + 0x2ef0) ^ 0x80000000
                                                     ) - _4622)) << 0x18 |
                CONCAT12((char)(int)((float)(local_a0 - _4620) +
                                    fVar2 * (float)((double)CONCAT44(0x43300000,
                                                                     (uint)*(byte *)(param_1 +
                                                                                    0x2ef9) -
                                                                     (uint)*(byte *)(param_1 +
                                                                                    0x2ef1) ^
                                                                     0x80000000) - _4622)),uVar4) &
                0xffff0000 | (uint)local_104._2_2_;
    local_70 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2ef4));
    local_58 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2ef5));
    local_108._2_2_ =
         uVar5 & 0xff |
         (ushort)(byte)(int)((float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2ef6))
                                    - _4620) +
                            fVar2 * (float)((double)CONCAT44(0x43300000,
                                                             (uint)*(byte *)(param_1 + 0x2efe) -
                                                             (uint)*(byte *)(param_1 + 0x2ef6) ^
                                                             0x80000000) - _4622)) << 8;
    local_108 = (int)((float)(local_70 - _4620) +
                     fVar2 * (float)((double)CONCAT44(0x43300000,
                                                      (uint)*(byte *)(param_1 + 0x2efc) -
                                                      (uint)*(byte *)(param_1 + 0x2ef4) ^ 0x80000000
                                                     ) - _4622)) << 0x18 |
                CONCAT12((char)(int)((float)(local_58 - _4620) +
                                    fVar2 * (float)((double)CONCAT44(0x43300000,
                                                                     (uint)*(byte *)(param_1 +
                                                                                    0x2efd) -
                                                                     (uint)*(byte *)(param_1 +
                                                                                    0x2ef5) ^
                                                                     0x80000000) - _4622)),uVar5) &
                0xffff0000 | (uint)local_108._2_2_;
  }
  else {
    bVar1 = (int)(short)(uVar8 << 1) <= (int)uVar10;
    if (bVar1) {
      if (bVar1) {
        *(undefined2 *)(param_1 + 0x2e0e) = 0;
        local_100._2_2_ = CONCAT11(0xff,(undefined)local_100);
        local_100 = local_100._2_2_ | 0x4b4b0000;
        local_104 = *(uint *)(param_1 + 0x2ef0);
        local_108 = *(uint *)(param_1 + 0x2ef4);
        if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAirMeter < 1) {
          *(undefined4 *)(param_1 + 0x3000) = 0;
        }
        else {
          iVar9 = (d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48c8 >> 1) +
                  (uint)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48c8 < 0 &&
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48c8 & 1U) != 0);
          if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAirMeter < iVar9) {
            dVar11 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                       (iVar9,iVar9 - d_com_inf_game::g_dComIfG_gameInfo.mPlay.
                                                      mAirMeter,1);
            local_10 = (double)CONCAT44(0x43300000,(int)DAT_803e6a38 ^ 0x80000000);
            *(int *)(param_1 + 0x3000) =
                 (int)(short)(int)((float)(local_10 - _4622) +
                                  (float)(dVar11 * (double)(float)((double)CONCAT44(0x43300000,
                                                                                    (int)
                                                  DAT_803e6a3c - (int)DAT_803e6a38 ^ 0x80000000) -
                                                  _4622)));
            *(undefined *)(param_1 + 0x2f04) = DAT_803e6a52;
            *(undefined *)(param_1 + 0x2f05) = DAT_803e6a53;
            *(undefined *)(param_1 + 0x2f06) = DAT_803e6a54;
            *(undefined *)(param_1 + 0x2ef8) = DAT_803e6a52;
            *(undefined *)(param_1 + 0x2ef9) = DAT_803e6a53;
            *(undefined *)(param_1 + 0x2efa) = DAT_803e6a54;
            *(undefined *)(param_1 + 0x2efc) = DAT_803e6a52;
            *(undefined *)(param_1 + 0x2efd) = DAT_803e6a53;
            *(undefined *)(param_1 + 0x2efe) = DAT_803e6a54;
            if (*(short *)(param_1 + 0x2d2e) < 1) {
              *(undefined2 *)(param_1 + 0x2d2e) = 2;
              if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) {
                JAIZelBasic::seStart
                          (JAIZelBasic::zel_basic,0x840,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
              }
            }
            else {
              *(short *)(param_1 + 0x2d2e) = *(short *)(param_1 + 0x2d2e) + -1;
            }
          }
          else {
            if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAirMeter < 0) {
              *(int *)(param_1 + 0x3000) = (int)DAT_803e6a3c;
              *(undefined *)(param_1 + 0x2f04) = DAT_803e6a52;
              *(undefined *)(param_1 + 0x2f05) = DAT_803e6a53;
              *(undefined *)(param_1 + 0x2f06) = DAT_803e6a54;
              *(undefined *)(param_1 + 0x2ef8) = DAT_803e6a52;
              *(undefined *)(param_1 + 0x2ef9) = DAT_803e6a53;
              *(undefined *)(param_1 + 0x2efa) = DAT_803e6a54;
              *(undefined *)(param_1 + 0x2efc) = DAT_803e6a52;
              *(undefined *)(param_1 + 0x2efd) = DAT_803e6a53;
              *(undefined *)(param_1 + 0x2efe) = DAT_803e6a54;
            }
          }
        }
      }
    }
    else {
      local_30 = (double)CONCAT44(0x43300000,uVar10 ^ 0x80000000);
      fVar2 = ((float)(local_30 - _4622) -
              (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - _4622)) /
              (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - _4622);
      local_48 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2f04));
      local_60 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2f05));
      local_78 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2f06));
      local_100._2_2_ =
           uVar3 & 0xff |
           (ushort)(byte)(int)((float)(local_78 - _4620) +
                              fVar2 * (float)((double)CONCAT44(0x43300000,
                                                               0xff - *(byte *)(param_1 + 0x2f06) ^
                                                               0x80000000) - _4622)) << 8;
      local_100 = (int)((float)(local_48 - _4620) +
                       fVar2 * (float)((double)CONCAT44(0x43300000,
                                                        0x4b - *(byte *)(param_1 + 0x2f04) ^
                                                        0x80000000) - _4622)) << 0x18 |
                  CONCAT12((char)(int)((float)(local_60 - _4620) +
                                      fVar2 * (float)((double)CONCAT44(0x43300000,
                                                                       0x4b - *(byte *)(param_1 +
                                                                                       0x2f05) ^
                                                                       0x80000000) - _4622)),uVar3)
                  & 0xffff0000 | (uint)local_100._2_2_;
      local_90 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2ef8));
      local_a8 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2ef9));
      local_c0 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2efa));
      local_104._2_2_ =
           uVar4 & 0xff |
           (ushort)(byte)(int)((float)(local_c0 - _4620) +
                              fVar2 * (float)((double)CONCAT44(0x43300000,
                                                               (uint)*(byte *)(param_1 + 0x2ef2) -
                                                               (uint)*(byte *)(param_1 + 0x2efa) ^
                                                               0x80000000) - _4622)) << 8;
      local_104 = (int)((float)(local_90 - _4620) +
                       fVar2 * (float)((double)CONCAT44(0x43300000,
                                                        (uint)*(byte *)(param_1 + 0x2ef0) -
                                                        (uint)*(byte *)(param_1 + 0x2ef8) ^
                                                        0x80000000) - _4622)) << 0x18 |
                  CONCAT12((char)(int)((float)(local_a8 - _4620) +
                                      fVar2 * (float)((double)CONCAT44(0x43300000,
                                                                       (uint)*(byte *)(param_1 +
                                                                                      0x2ef1) -
                                                                       (uint)*(byte *)(param_1 +
                                                                                      0x2ef9) ^
                                                                       0x80000000) - _4622)),uVar4)
                  & 0xffff0000 | (uint)local_104._2_2_;
      local_e0 = (double)CONCAT44(0x43300000,
                                  (uint)*(byte *)(param_1 + 0x2ef4) -
                                  (uint)*(byte *)(param_1 + 0x2efc) ^ 0x80000000);
      local_20 = (double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2efe));
      local_108._2_2_ =
           uVar5 & 0xff |
           (ushort)(byte)(int)((float)(local_20 - _4620) +
                              fVar2 * (float)((double)CONCAT44(0x43300000,
                                                               (uint)*(byte *)(param_1 + 0x2ef6) -
                                                               (uint)*(byte *)(param_1 + 0x2efe) ^
                                                               0x80000000) - _4622)) << 8;
      local_108 = (int)((float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param_1 + 0x2efc)) -
                               _4620) + fVar2 * (float)(local_e0 - _4622)) << 0x18 |
                  CONCAT12((char)(int)((float)((double)CONCAT44(0x43300000,
                                                                (uint)*(byte *)(param_1 + 0x2efd)) -
                                              _4620) +
                                      fVar2 * (float)((double)CONCAT44(0x43300000,
                                                                       (uint)*(byte *)(param_1 +
                                                                                      0x2ef5) -
                                                                       (uint)*(byte *)(param_1 +
                                                                                      0x2efd) ^
                                                                       0x80000000) - _4622)),uVar5)
                  & 0xffff0000 | (uint)local_108._2_2_;
    }
  }
  if (*(int *)(param_1 + 0x3000) == 0) {
    uVar6 = *(undefined4 *)(param_1 + 0x2ef8);
    iVar9 = *(int *)(param_1 + 0x2c88);
    local_11c = (undefined)((uint)uVar6 >> 0x18);
    *(undefined *)(iVar9 + 0x108) = local_11c;
    uStack283 = (undefined)((uint)uVar6 >> 0x10);
    *(undefined *)(iVar9 + 0x109) = uStack283;
    uStack282 = (undefined)((uint)uVar6 >> 8);
    *(undefined *)(iVar9 + 0x10a) = uStack282;
    uStack281 = (undefined)uVar6;
    *(undefined *)(iVar9 + 0x10b) = uStack281;
    uVar6 = *(undefined4 *)(param_1 + 0x2efc);
    iVar9 = *(int *)(param_1 + 0x2c88);
    local_120 = (undefined)((uint)uVar6 >> 0x18);
    *(undefined *)(iVar9 + 0x104) = local_120;
    uStack287 = (undefined)((uint)uVar6 >> 0x10);
    *(undefined *)(iVar9 + 0x105) = uStack287;
    uStack286 = (undefined)((uint)uVar6 >> 8);
    *(undefined *)(iVar9 + 0x106) = uStack286;
    uStack285 = (undefined)uVar6;
    *(undefined *)(iVar9 + 0x107) = uStack285;
    uVar6 = *(undefined4 *)(param_1 + 0x2f04);
    iVar9 = *(int *)(param_1 + 0x2cf8);
    local_124 = (undefined)((uint)uVar6 >> 0x18);
    *(undefined *)(iVar9 + 0x108) = local_124;
    uStack291 = (undefined)((uint)uVar6 >> 0x10);
    *(undefined *)(iVar9 + 0x109) = uStack291;
    uStack290 = (undefined)((uint)uVar6 >> 8);
    *(undefined *)(iVar9 + 0x10a) = uStack290;
    uStack289 = (undefined)uVar6;
    *(undefined *)(iVar9 + 0x10b) = uStack289;
    uVar6 = *(undefined4 *)(param_1 + 0x2f04);
    iVar9 = *(int *)(param_1 + 0x2da0);
    local_128 = (undefined)((uint)uVar6 >> 0x18);
    *(undefined *)(iVar9 + 0x108) = local_128;
    uStack295 = (undefined)((uint)uVar6 >> 0x10);
    *(undefined *)(iVar9 + 0x109) = uStack295;
    uStack294 = (undefined)((uint)uVar6 >> 8);
    *(undefined *)(iVar9 + 0x10a) = uStack294;
    uStack293 = (undefined)uVar6;
    *(undefined *)(iVar9 + 0x10b) = uStack293;
  }
  else {
    iVar9 = *(int *)(param_1 + 0x2c88);
    local_10c = (undefined)(local_104 >> 0x18);
    *(undefined *)(iVar9 + 0x108) = local_10c;
    uStack267 = (undefined)(local_104 >> 0x10);
    *(undefined *)(iVar9 + 0x109) = uStack267;
    uStack266 = (undefined)(local_104 >> 8);
    *(undefined *)(iVar9 + 0x10a) = uStack266;
    uStack265 = (undefined)local_104;
    *(undefined *)(iVar9 + 0x10b) = uStack265;
    iVar9 = *(int *)(param_1 + 0x2c88);
    local_110 = (undefined)(local_108 >> 0x18);
    *(undefined *)(iVar9 + 0x104) = local_110;
    uStack271 = (undefined)(local_108 >> 0x10);
    *(undefined *)(iVar9 + 0x105) = uStack271;
    uStack270 = (undefined)(local_108 >> 8);
    *(undefined *)(iVar9 + 0x106) = uStack270;
    uStack269 = (undefined)local_108;
    *(undefined *)(iVar9 + 0x107) = uStack269;
    iVar9 = *(int *)(param_1 + 0x2cf8);
    local_114 = (undefined)(local_100 >> 0x18);
    *(undefined *)(iVar9 + 0x108) = local_114;
    uStack275 = (undefined)(local_100 >> 0x10);
    *(undefined *)(iVar9 + 0x109) = uStack275;
    uStack274 = (undefined)(local_100 >> 8);
    *(undefined *)(iVar9 + 0x10a) = uStack274;
    uStack273 = (undefined)local_100;
    *(undefined *)(iVar9 + 0x10b) = uStack273;
    iVar9 = *(int *)(param_1 + 0x2da0);
    *(undefined *)(iVar9 + 0x108) = local_114;
    *(undefined *)(iVar9 + 0x109) = uStack275;
    *(undefined *)(iVar9 + 0x10a) = uStack274;
    *(undefined *)(iVar9 + 0x10b) = uStack273;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMeter_swimMainDown(sub_meter_class *) */

void dMeter_swimMainDown(int param_1)

{
  float fVar1;
  short sVar2;
  
  sVar2 = (short)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAirMeter;
  dMeter_paneBottomScaleY
            ((double)((float)((double)CONCAT44(0x43300000,(int)sVar2 ^ 0x80000000) - _4622) /
                     (float)((double)CONCAT44(0x43300000,
                                              (int)*(short *)(param_1 + 0x2d66) ^ 0x80000000) -
                            _4622)),param_1 + 0x2d30);
  fVar1 = _4664;
  *(float *)(param_1 + 0x2db0) =
       (*(float *)(param_1 + 0x2d48) - *(float *)(param_1 + 0x2d58) * _4664) -
       *(float *)(param_1 + 0x2d40);
  *(float *)(param_1 + 0x2dc0) = *(float *)(param_1 + 0x2db0) + *(float *)(param_1 + 0x2dd0) * fVar1
  ;
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_1 + 0x2da0));
  *(undefined4 *)(param_1 + 0x2d18) = *(undefined4 *)(param_1 + 0x2dc0);
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_1 + 0x2cf8));
  if (0 < sVar2) {
    if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) &&
       (d_com_inf_game::g_dComIfG_gameInfo._23496_1_ != '\0')) {
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAirMeter =
           d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAirMeter + -1;
    }
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAirMeter == 0) {
      *(undefined2 *)(param_1 + 0x2dd6) = 3;
      d_com_inf_game::g_dComIfG_gameInfo._23496_1_ = '\0';
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall dMeter_swimTekariScroll(sub_meter_class *) */

void dMeter_swimTekariScroll(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  short unaff_r30;
  int iVar9;
  double dVar10;
  undefined local_48;
  undefined uStack71;
  undefined uStack70;
  undefined uStack69;
  undefined local_44;
  undefined uStack67;
  undefined uStack66;
  undefined uStack65;
  short sStack34;
  
  iVar7 = (int)DAT_803e6a56;
  sVar5 = DAT_803e6a56 + DAT_803e6a58;
  sVar6 = sVar5 + DAT_803e6a56 + DAT_803e6a5a;
  iVar9 = (int)(short)(sVar6 + DAT_803e6a56 + DAT_803e6a5c);
  fVar1 = *(float *)(param_1 + 0x2cac) * _4664;
  fVar3 = d_s_play::g_regHIO.mChild[6].mFloats[0] + (*(float *)(param_1 + 0x2c9c) - fVar1);
  fVar2 = *(float *)(param_1 + 0x2cb0) * _4664;
  fVar4 = d_s_play::g_regHIO.mChild[6].mFloats[1] + (*(float *)(param_1 + 0x2ca0) - fVar2);
  fVar1 = d_s_play::g_regHIO.mChild[6].mFloats[0] + *(float *)(param_1 + 0x2c9c) + fVar1;
  fVar2 = d_s_play::g_regHIO.mChild[6].mFloats[1] + *(float *)(param_1 + 0x2ca0) + fVar2;
  iVar8 = (int)*(short *)(param_1 + 0x2fc4);
  if (iVar8 < iVar7) {
    dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar7,iVar8,0);
    sStack34 = (short)(int)(_4664 + (_4655 - (float)((double)_12876 * dVar10)));
  }
  else {
    if (iVar8 < sVar5) {
      sStack34 = -0x24;
    }
    else {
      if (iVar8 < (short)(sVar5 + DAT_803e6a56)) {
        dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar7,iVar8 - sVar5,0);
        sStack34 = (short)(int)(_4664 + (_4655 - (float)((double)_12876 * dVar10)));
      }
      else {
        if (iVar8 < sVar6) {
          sStack34 = -0x24;
        }
        else {
          if (iVar8 < (short)(sVar6 + DAT_803e6a56)) {
            dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar7,iVar8 - sVar6,0);
            sStack34 = (short)(int)(_4664 + (_4655 - (float)((double)_12876 * dVar10)));
          }
          else {
            sStack34 = unaff_r30;
            if (iVar8 < iVar9) {
              sStack34 = -0x24;
            }
          }
        }
      }
    }
  }
  *(short *)(param_1 + 0x2fc4) = *(short *)(param_1 + 0x2fc4) + 1;
  if (iVar9 <= *(short *)(param_1 + 0x2fc4)) {
    *(undefined2 *)(param_1 + 0x2fc4) = 0;
  }
  ::dDlst_2Dm_c::setPos
            (&tekari,(short)(int)fVar3,(short)(int)fVar4,(short)(int)fVar1,(short)(int)fVar2);
  local_44 = (undefined)((uint)_12851 >> 0x18);
  DAT_803e6c98 = local_44;
  uStack67 = (undefined)((uint)_12851 >> 0x10);
  DAT_803e6c99 = uStack67;
  uStack66 = (undefined)((uint)_12851 >> 8);
  DAT_803e6c9a = uStack66;
  uStack65 = (undefined)_12851;
  DAT_803e6c9b = uStack65;
  local_48 = (undefined)((uint)_12853 >> 0x18);
  DAT_803e6c9c = local_48;
  uStack71 = (undefined)((uint)_12853 >> 0x10);
  DAT_803e6c9d = uStack71;
  uStack70 = (undefined)((uint)_12853 >> 8);
  DAT_803e6c9e = uStack70;
  uStack69 = (undefined)_12853;
  DAT_803e6c9f = uStack69;
  ::dDlst_2Dm_c::setScroll(&tekari,0,0,0);
  DAT_803e6c9b = 0xff;
  ::dDlst_2Dm_c::setScroll(&tekari,1,sStack34,sStack34);
  return;
}


/* __stdcall dMeter_swimLightMove(sub_meter_class *) */

void dMeter_swimLightMove(int param_1)

{
  int iVar1;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAirMeter != 0) {
    if (*(short *)(param_1 + 0x3010) == 0) {
      dMeter_swimLightBirth();
    }
    else {
      *(short *)(param_1 + 0x3010) = *(short *)(param_1 + 0x3010) + -1;
    }
  }
  for (iVar1 = 0; (short)iVar1 < 9; iVar1 = iVar1 + 1) {
    if (*(short *)(param_1 + (short)iVar1 * 0x38 + 0x2ac6) != 0) {
      dMeter_swimLightAnime(param_1,iVar1);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMeter_swimLightBirth(sub_meter_class *) */

void dMeter_swimLightBirth(int param_1)

{
  short sVar1;
  int iVar2;
  short sVar4;
  int iVar3;
  float fVar5;
  float fVar6;
  float fVar7;
  
  sVar1 = 0;
  for (sVar4 = 0; sVar4 < 9; sVar4 = sVar4 + 1) {
    if (*(short *)(param_1 + sVar4 * 0x38 + 0x2ac6) == 0) {
      sVar1 = sVar1 + 1;
    }
  }
  fVar5 = SComponent::cM_rndF((float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000) - _4622))
  ;
  fVar6 = SComponent::cM_rndF(_6055);
  fVar7 = _6052;
  iVar2 = (short)(int)fVar5 * 4;
  *(float *)(param_1 + iVar2 + 0x2f74) = _6052 + fVar6;
  fVar7 = SComponent::cM_rndFX(fVar7);
  *(float *)(param_1 + iVar2 + 0x2f98) = fVar7;
  iVar3 = (short)(int)fVar5 * 0x38;
  iVar2 = param_1 + iVar3;
  *(undefined2 *)(iVar2 + 0x2ac6) = 1;
  *(float *)(iVar2 + 0x2ab0) =
       *(float *)(param_1 + 0x2d40) +
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6a44 ^ 0x80000000) - _4622);
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(param_1 + iVar3 + 0x2a90));
  fVar7 = SComponent::cM_rndF((float)((double)CONCAT44(0x43300000,(int)DAT_803e6a40 ^ 0x80000000) -
                                     _4622));
  *(short *)(param_1 + 0x3010) = (short)(int)fVar7;
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall dMeter_swimLightAnime(sub_meter_class *,
                                   short) */

void dMeter_swimLightAnime(int param_1,short param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  fopMsgM_pane_class *this;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  double dVar8;
  float fVar9;
  
  sVar2 = DAT_803e6a3e;
  iVar7 = (int)DAT_803e6a3e;
  iVar5 = (int)(short)(DAT_803e6a3e + DAT_803e6a40);
  iVar3 = param_2 * 0x38;
  iVar6 = param_1 + iVar3;
  sVar1 = *(short *)(iVar6 + 0x2ac6);
  dVar8 = MSL_C.PPCEABI.bare.H::sin
                    ((double)(_12946 * (float)((double)CONCAT44(0x43300000,(int)sVar1 ^ 0x80000000)
                                              - _4622)));
  iVar4 = param_1 + param_2 * 4;
  *(float *)(iVar6 + 0x2aac) =
       *(float *)(iVar6 + 0x2aa4) + *(float *)(iVar4 + 0x2f98) * (float)dVar8;
  *(float *)(iVar6 + 0x2ab0) = *(float *)(iVar6 + 0x2ab0) - *(float *)(iVar4 + 0x2f74);
  dVar8 = _4622;
  *(float *)(iVar6 + 0x2abc) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6986 ^ 0x80000000) - _4622);
  *(float *)(iVar6 + 0x2ac0) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6986 ^ 0x80000000) - dVar8);
  this = (fopMsgM_pane_class *)(param_1 + iVar3 + 0x2a90);
  f_op_msg_mng::fopMsgM_cposMove(this);
  fVar9 = SComponent::cM_rndF(_10769);
  *(float *)(iVar4 + 0x2f74) = *(float *)(iVar4 + 0x2f74) * (_4488 + fVar9);
  fVar9 = SComponent::cM_rndF(0_1);
  *(float *)(iVar4 + 0x2f98) = *(float *)(iVar4 + 0x2f98) * (_12626 + fVar9);
  iVar3 = (int)sVar1;
  if (iVar3 == 1) {
    f_op_msg_mng::fopMsgM_setNowAlphaZero(this);
  }
  else {
    if (iVar3 < sVar2) {
      dVar8 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar7 + -1,iVar3 + -1,1);
      f_op_msg_mng::fopMsgM_setNowAlpha(this,(float)dVar8);
    }
    else {
      if (iVar3 < iVar5) {
        dVar8 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar5 - iVar7,iVar3 - iVar7,0);
        f_op_msg_mng::fopMsgM_setNowAlpha(this,(float)((double)1_0 - dVar8));
      }
      else {
        if (iVar3 == iVar5) {
          f_op_msg_mng::fopMsgM_setNowAlphaZero(this);
        }
      }
    }
  }
  *(short *)(iVar6 + 0x2ac6) = *(short *)(iVar6 + 0x2ac6) + 1;
  if (iVar5 < *(short *)(iVar6 + 0x2ac6)) {
    *(undefined2 *)(iVar6 + 0x2ac6) = 0;
  }
  return;
}


/* __stdcall dMeter_placeNameMove(void) */

void dMeter_placeNameMove(void)

{
  if (dMeter_place_name == '\0') {
    if (d_com_inf_game::g_dComIfG_gameInfo._23544_1_ == '\x02') {
      f_op_msg_mng::fopMsgM_create
                (0x1ee,(fopAc_ac_c *)0x0,(cXyz *)0x0,(int *)0x0,(int *)0x0,(undefined *)0x0);
      dMeter_place_name = '\x01';
    }
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo._23544_1_ == '\0') {
      dMeter_place_name = '\0';
    }
  }
  return;
}


/* __stdcall dMeter_arrowInit(sub_meter_class *) */

void dMeter_arrowInit(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 4;
  do {
    *(undefined2 *)(param_1 + iVar1 + 0x2e46) = 0;
    iVar1 = iVar1 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined *)(param_1 + 0x3025) = 0;
  return;
}


/* __stdcall dMeter_arrowCheckStatus(sub_meter_class *) */

void dMeter_arrowCheckStatus(int param_1)

{
  if ((d_com_inf_game::g_dComIfG_gameInfo._23521_1_ & 1) == 0) {
    dMeter_arrowErase(param_1 + 0x2e10);
  }
  else {
    if (*(short *)(param_1 + 0x2e46) == 0) {
      if ((*(char *)(param_1 + 0x3025) == '\0') || (*(char *)(param_1 + 0x3025) == '\x14')) {
        *(undefined2 *)(param_1 + 0x2e46) = 1;
      }
    }
  }
  if ((d_com_inf_game::g_dComIfG_gameInfo._23521_1_ & 2) == 0) {
    dMeter_arrowErase(param_1 + 0x2e48);
  }
  else {
    if (*(short *)(param_1 + 0x2e7e) == 0) {
      if ((*(char *)(param_1 + 0x3025) == '\0') || (*(char *)(param_1 + 0x3025) == '\x14')) {
        *(undefined2 *)(param_1 + 0x2e7e) = 1;
      }
    }
  }
  if ((d_com_inf_game::g_dComIfG_gameInfo._23521_1_ & 4) == 0) {
    dMeter_arrowErase(param_1 + 0x2e80);
  }
  else {
    if (*(short *)(param_1 + 0x2eb6) == 0) {
      if ((*(char *)(param_1 + 0x3025) == '\0') || (*(char *)(param_1 + 0x3025) == '\x14')) {
        *(undefined2 *)(param_1 + 0x2eb6) = 1;
      }
    }
  }
  if ((d_com_inf_game::g_dComIfG_gameInfo._23521_1_ & 8) == 0) {
    dMeter_arrowErase(param_1 + 0x2eb8);
  }
  else {
    if ((*(short *)(param_1 + 0x2eee) == 0) &&
       ((*(char *)(param_1 + 0x3025) == '\0' || (*(char *)(param_1 + 0x3025) == '\x14')))) {
      *(undefined2 *)(param_1 + 0x2eee) = 1;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMeter_arrowTransScale(sub_meter_class *,
                                    float,
                                    float,
                                    int) */

void dMeter_arrowTransScale(double param_1,double param_2,int param_3,int param_4)

{
  if (param_4 == 2) {
    *(float *)(param_3 + 0x2eac) = (float)((double)*(float *)(param_3 + 0x2ea4) * param_2);
    *(undefined4 *)(param_3 + 0x2eb0) = *(undefined4 *)(param_3 + 0x2ea8);
    *(float *)(param_3 + 0x2e8c) = (float)((double)*(float *)(param_3 + 0x2e84) + param_1);
    *(undefined4 *)(param_3 + 0x2e90) = *(undefined4 *)(param_3 + 0x2e88);
  }
  else {
    if (param_4 < 2) {
      if (param_4 == 0) {
        *(float *)(param_3 + 0x2e3c) = (float)((double)*(float *)(param_3 + 0x2e34) * param_2);
        *(undefined4 *)(param_3 + 0x2e40) = *(undefined4 *)(param_3 + 0x2e38);
        *(float *)(param_3 + 0x2e1c) =
             (float)((double)(float)((double)*(float *)(param_3 + 0x2e14) +
                                    (double)*(float *)(param_3 + 0x2e34)) - param_1) -
             *(float *)(param_3 + 0x2e3c);
        *(undefined4 *)(param_3 + 0x2e20) = *(undefined4 *)(param_3 + 0x2e18);
      }
      else {
        if (-1 < param_4) {
          *(undefined4 *)(param_3 + 0x2e74) = *(undefined4 *)(param_3 + 0x2e6c);
          *(float *)(param_3 + 0x2e78) = (float)((double)*(float *)(param_3 + 0x2e70) * param_2);
          *(undefined4 *)(param_3 + 0x2e54) = *(undefined4 *)(param_3 + 0x2e4c);
          *(float *)(param_3 + 0x2e58) = (float)((double)*(float *)(param_3 + 0x2e50) + param_1);
        }
      }
    }
    else {
      if (param_4 < 4) {
        *(undefined4 *)(param_3 + 0x2ee4) = *(undefined4 *)(param_3 + 0x2edc);
        *(float *)(param_3 + 0x2ee8) = (float)((double)*(float *)(param_3 + 12000) * param_2);
        *(undefined4 *)(param_3 + 0x2ec4) = *(undefined4 *)(param_3 + 0x2ebc);
        *(float *)(param_3 + 0x2ec8) =
             (float)((double)(*(float *)(param_3 + 0x2ec0) + *(float *)(param_3 + 12000)) - param_1)
             - *(float *)(param_3 + 0x2ee8);
      }
    }
  }
  param_3 = param_3 + param_4 * 0x38;
  (**(code **)(**(int **)(param_3 + 0x2e10) + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,
                                              (int)*(float *)(param_3 + 0x2e1c) ^ 0x80000000) -
                            _4622),
             (double)(float)((double)CONCAT44(0x43300000,
                                              (int)*(float *)(param_3 + 0x2e20) ^ 0x80000000) -
                            _4622));
  (**(code **)(**(int **)(param_3 + 0x2e10) + 0x18))
            ((double)(float)((double)CONCAT44(0x43300000,
                                              (int)*(float *)(param_3 + 0x2e3c) ^ 0x80000000) -
                            _4622),
             (double)(float)((double)CONCAT44(0x43300000,
                                              (int)*(float *)(param_3 + 0x2e40) ^ 0x80000000) -
                            _4622));
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x80203278) */
/* __stdcall dMeter_arrowAnime(sub_meter_class *) */

void dMeter_arrowAnime(int param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  double dVar16;
  undefined8 in_f31;
  double local_108;
  double local_f0;
  double local_e8;
  double local_d8;
  double local_d0;
  double local_c0;
  double local_b8;
  double local_a8;
  double local_a0;
  double local_90;
  double local_88;
  double local_78;
  double local_70;
  double local_60;
  double local_58;
  double local_40;
  undefined auStack8 [8];
  
  uVar15 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar12 = 0;
  iVar11 = 0;
  do {
    iVar13 = param_1 + iVar11;
    if (*(short *)(iVar13 + 0x2e46) == 1) {
      iVar14 = (int)*(char *)(param_1 + 0x3025);
      if (0x14 < iVar14) {
        iVar14 = (int)(short)(*(char *)(param_1 + 0x3025) + -0x14);
      }
      dVar16 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)(short)iVar14,0);
      local_108 = (double)CONCAT44(0x43300000,trans_13043 ^ 0x80000000);
      dMeter_arrowTransScale
                ((double)((float)(local_108 - _4622) +
                         (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,
                                                                           DAT_8036117c -
                                                                           trans_13043 ^ 0x80000000)
                                                         - _4622))),
                 (double)(scale_13042 + (float)(dVar16 * (double)(DAT_8036116c - scale_13042))),
                 param_1,iVar12);
      f_op_msg_mng::fopMsgM_setNowAlpha
                ((fopMsgM_pane_class *)(iVar13 + 0x2e10),(float)((double)_13283 * dVar16));
      local_f0 = (double)CONCAT44(0x43300000,(uint)DAT_8036119c - (uint)black_13045 ^ 0x80000000);
      dVar1 = (double)CONCAT44(0x43300000,(uint)DAT_80361199) - _4620;
      local_d8 = (double)CONCAT44(0x43300000,(uint)DAT_8036119d - (uint)DAT_80361199 ^ 0x80000000);
      local_d8 = local_d8 - _4622;
      dVar2 = (double)CONCAT44(0x43300000,(uint)DAT_8036119a) - _4620;
      local_c0 = (double)CONCAT44(0x43300000,(uint)DAT_8036119e - (uint)DAT_8036119a ^ 0x80000000);
      local_c0 = local_c0 - _4622;
      dVar3 = (double)CONCAT44(0x43300000,(uint)DAT_8036119b) - _4620;
      local_a8 = (double)CONCAT44(0x43300000,(uint)DAT_8036119f - (uint)DAT_8036119b ^ 0x80000000);
      local_a8 = local_a8 - _4622;
      dVar4 = (double)CONCAT44(0x43300000,(uint)white_13044) - _4620;
      local_90 = (double)CONCAT44(0x43300000,(uint)DAT_8036118c - (uint)white_13044 ^ 0x80000000);
      local_90 = local_90 - _4622;
      dVar5 = (double)CONCAT44(0x43300000,(uint)DAT_80361189) - _4620;
      local_78 = (double)CONCAT44(0x43300000,(uint)DAT_8036118d - (uint)DAT_80361189 ^ 0x80000000);
      local_78 = local_78 - _4622;
      dVar6 = (double)CONCAT44(0x43300000,(uint)DAT_8036118a) - _4620;
      local_60 = (double)CONCAT44(0x43300000,(uint)DAT_8036118e - (uint)DAT_8036118a ^ 0x80000000);
      local_60 = local_60 - _4622;
      dVar7 = (double)CONCAT44(0x43300000,(uint)DAT_8036118b) - _4620;
      dVar8 = (double)CONCAT44(0x43300000,(uint)DAT_8036118f - (uint)DAT_8036118b ^ 0x80000000) -
              _4622;
      iVar10 = *(int *)(iVar13 + 0x2e10);
      *(char *)(iVar10 + 0x108) =
           (char)(int)((float)((double)CONCAT44(0x43300000,(uint)black_13045) - _4620) +
                      (float)(dVar16 * (double)(float)(local_f0 - _4622)));
      *(char *)(iVar10 + 0x109) =
           (char)(int)((float)dVar1 + (float)(dVar16 * (double)(float)local_d8));
      *(char *)(iVar10 + 0x10a) =
           (char)(int)((float)dVar2 + (float)(dVar16 * (double)(float)local_c0));
      *(char *)(iVar10 + 0x10b) =
           (char)(int)((float)dVar3 + (float)(dVar16 * (double)(float)local_a8));
      iVar10 = *(int *)(iVar13 + 0x2e10);
      *(char *)(iVar10 + 0x104) =
           (char)(int)((float)dVar4 + (float)(dVar16 * (double)(float)local_90));
      *(char *)(iVar10 + 0x105) =
           (char)(int)((float)dVar5 + (float)(dVar16 * (double)(float)local_78));
      *(char *)(iVar10 + 0x106) =
           (char)(int)((float)dVar6 + (float)(dVar16 * (double)(float)local_60));
      *(char *)(iVar10 + 0x107) = (char)(int)((float)dVar7 + (float)(dVar16 * (double)(float)dVar8))
      ;
      if ((short)iVar14 == 10) {
        *(undefined2 *)(iVar13 + 0x2e46) = 2;
      }
    }
    else {
      if (*(short *)(iVar13 + 0x2e46) == 2) {
        cVar9 = *(char *)(param_1 + 0x3025);
        if (cVar9 < '\x15') {
          dVar16 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)(short)(cVar9 + -10),0);
          local_40 = (double)CONCAT44(0x43300000,DAT_8036117c ^ 0x80000000);
          dMeter_arrowTransScale
                    ((double)((float)(local_40 - _4622) +
                             (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,
                                                                               DAT_80361180 -
                                                                               DAT_8036117c ^
                                                                               0x80000000) - _4622))
                             ),
                     (double)(DAT_8036116c + (float)(dVar16 * (double)(DAT_80361170 - DAT_8036116c))
                             ),param_1,iVar12);
          local_58 = (double)CONCAT44(0x43300000,
                                      (uint)DAT_803611a0 - (uint)DAT_8036119c ^ 0x80000000);
          dVar1 = (double)CONCAT44(0x43300000,(uint)DAT_8036119d) - _4620;
          local_70 = (double)CONCAT44(0x43300000,
                                      (uint)DAT_803611a1 - (uint)DAT_8036119d ^ 0x80000000);
          local_70 = local_70 - _4622;
          dVar2 = (double)CONCAT44(0x43300000,(uint)DAT_8036119e) - _4620;
          local_88 = (double)CONCAT44(0x43300000,
                                      (uint)DAT_803611a2 - (uint)DAT_8036119e ^ 0x80000000);
          local_88 = local_88 - _4622;
          dVar3 = (double)CONCAT44(0x43300000,(uint)DAT_8036119f) - _4620;
          local_a0 = (double)CONCAT44(0x43300000,
                                      (uint)DAT_803611a3 - (uint)DAT_8036119f ^ 0x80000000);
          local_a0 = local_a0 - _4622;
          dVar4 = (double)CONCAT44(0x43300000,(uint)DAT_8036118c) - _4620;
          local_b8 = (double)CONCAT44(0x43300000,
                                      (uint)DAT_80361190 - (uint)DAT_8036118c ^ 0x80000000);
          local_b8 = local_b8 - _4622;
          dVar5 = (double)CONCAT44(0x43300000,(uint)DAT_8036118d) - _4620;
          local_d0 = (double)CONCAT44(0x43300000,
                                      (uint)DAT_80361191 - (uint)DAT_8036118d ^ 0x80000000);
          local_d0 = local_d0 - _4622;
          dVar6 = (double)CONCAT44(0x43300000,(uint)DAT_8036118e) - _4620;
          local_e8 = (double)CONCAT44(0x43300000,
                                      (uint)DAT_80361192 - (uint)DAT_8036118e ^ 0x80000000);
          local_e8 = local_e8 - _4622;
          dVar7 = (double)CONCAT44(0x43300000,(uint)DAT_8036118f) - _4620;
          dVar8 = (double)CONCAT44(0x43300000,(uint)DAT_80361193 - (uint)DAT_8036118f ^ 0x80000000)
                  - _4622;
          iVar14 = *(int *)(iVar13 + 0x2e10);
          *(char *)(iVar14 + 0x108) =
               (char)(int)((float)((double)CONCAT44(0x43300000,(uint)DAT_8036119c) - _4620) +
                          (float)(dVar16 * (double)(float)(local_58 - _4622)));
          *(char *)(iVar14 + 0x109) =
               (char)(int)((float)dVar1 + (float)(dVar16 * (double)(float)local_70));
          *(char *)(iVar14 + 0x10a) =
               (char)(int)((float)dVar2 + (float)(dVar16 * (double)(float)local_88));
          *(char *)(iVar14 + 0x10b) =
               (char)(int)((float)dVar3 + (float)(dVar16 * (double)(float)local_a0));
          iVar13 = *(int *)(iVar13 + 0x2e10);
          *(char *)(iVar13 + 0x104) =
               (char)(int)((float)dVar4 + (float)(dVar16 * (double)(float)local_b8));
          *(char *)(iVar13 + 0x105) =
               (char)(int)((float)dVar5 + (float)(dVar16 * (double)(float)local_d0));
          *(char *)(iVar13 + 0x106) =
               (char)(int)((float)dVar6 + (float)(dVar16 * (double)(float)local_e8));
          *(char *)(iVar13 + 0x107) =
               (char)(int)((float)dVar7 + (float)(dVar16 * (double)(float)dVar8));
        }
        else {
          dVar16 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)(short)(cVar9 + -0x14),0);
          local_40 = (double)CONCAT44(0x43300000,DAT_80361180 ^ 0x80000000);
          dMeter_arrowTransScale
                    ((double)((float)(local_40 - _4622) +
                             (float)(dVar16 * (double)(float)((double)CONCAT44(0x43300000,
                                                                               DAT_80361184 -
                                                                               DAT_80361180 ^
                                                                               0x80000000) - _4622))
                             ),
                     (double)(DAT_80361170 + (float)(dVar16 * (double)(DAT_80361174 - DAT_80361170))
                             ),param_1,iVar12);
          local_58 = (double)CONCAT44(0x43300000,
                                      (uint)DAT_803611a4 - (uint)DAT_803611a0 ^ 0x80000000);
          dVar1 = (double)CONCAT44(0x43300000,(uint)DAT_803611a1) - _4620;
          local_70 = (double)CONCAT44(0x43300000,
                                      (uint)DAT_803611a5 - (uint)DAT_803611a1 ^ 0x80000000);
          local_70 = local_70 - _4622;
          dVar2 = (double)CONCAT44(0x43300000,(uint)DAT_803611a2) - _4620;
          local_88 = (double)CONCAT44(0x43300000,
                                      (uint)DAT_803611a6 - (uint)DAT_803611a2 ^ 0x80000000);
          local_88 = local_88 - _4622;
          dVar3 = (double)CONCAT44(0x43300000,(uint)DAT_803611a3) - _4620;
          local_a0 = (double)CONCAT44(0x43300000,
                                      (uint)DAT_803611a7 - (uint)DAT_803611a3 ^ 0x80000000);
          local_a0 = local_a0 - _4622;
          dVar4 = (double)CONCAT44(0x43300000,(uint)DAT_80361190) - _4620;
          local_b8 = (double)CONCAT44(0x43300000,
                                      (uint)DAT_80361194 - (uint)DAT_80361190 ^ 0x80000000);
          local_b8 = local_b8 - _4622;
          dVar5 = (double)CONCAT44(0x43300000,(uint)DAT_80361191) - _4620;
          local_d0 = (double)CONCAT44(0x43300000,
                                      (uint)DAT_80361195 - (uint)DAT_80361191 ^ 0x80000000);
          local_d0 = local_d0 - _4622;
          dVar6 = (double)CONCAT44(0x43300000,(uint)DAT_80361192) - _4620;
          local_e8 = (double)CONCAT44(0x43300000,
                                      (uint)DAT_80361196 - (uint)DAT_80361192 ^ 0x80000000);
          local_e8 = local_e8 - _4622;
          dVar7 = (double)CONCAT44(0x43300000,(uint)DAT_80361193) - _4620;
          dVar8 = (double)CONCAT44(0x43300000,(uint)DAT_80361197 - (uint)DAT_80361193 ^ 0x80000000)
                  - _4622;
          iVar14 = *(int *)(iVar13 + 0x2e10);
          *(char *)(iVar14 + 0x108) =
               (char)(int)((float)((double)CONCAT44(0x43300000,(uint)DAT_803611a0) - _4620) +
                          (float)(dVar16 * (double)(float)(local_58 - _4622)));
          *(char *)(iVar14 + 0x109) =
               (char)(int)((float)dVar1 + (float)(dVar16 * (double)(float)local_70));
          *(char *)(iVar14 + 0x10a) =
               (char)(int)((float)dVar2 + (float)(dVar16 * (double)(float)local_88));
          *(char *)(iVar14 + 0x10b) =
               (char)(int)((float)dVar3 + (float)(dVar16 * (double)(float)local_a0));
          iVar13 = *(int *)(iVar13 + 0x2e10);
          *(char *)(iVar13 + 0x104) =
               (char)(int)((float)dVar4 + (float)(dVar16 * (double)(float)local_b8));
          *(char *)(iVar13 + 0x105) =
               (char)(int)((float)dVar5 + (float)(dVar16 * (double)(float)local_d0));
          *(char *)(iVar13 + 0x106) =
               (char)(int)((float)dVar6 + (float)(dVar16 * (double)(float)local_e8));
          *(char *)(iVar13 + 0x107) =
               (char)(int)((float)dVar7 + (float)(dVar16 * (double)(float)dVar8));
        }
      }
    }
    iVar12 = iVar12 + 1;
    iVar11 = iVar11 + 0x38;
  } while (iVar12 < 4);
  __psq_l0(auStack8,uVar15);
  __psq_l1(auStack8,uVar15);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __stdcall dMeter_arrowErase(fopMsgM_pane_class *) */

void dMeter_arrowErase(fopMsgM_pane_class *param_1)

{
  J2DScreen *pJVar1;
  
  if (param_1->mUserData != 0) {
    f_op_msg_mng::fopMsgM_setNowAlphaZero(param_1);
    f_op_msg_mng::fopMsgM_paneTrans(param_1,(double)0_0,(double)0_0);
    f_op_msg_mng::fopMsgM_paneScaleXY(param_1,1_0);
    pJVar1 = param_1->mpPane;
    *(undefined *)&pJVar1[1].parent.mBox.mBR.x = 0xff;
    *(undefined *)((int)&pJVar1[1].parent.mBox.mBR.x + 1) = 0;
    *(undefined *)((int)&pJVar1[1].parent.mBox.mBR.x + 2) = 0;
    *(undefined *)((int)&pJVar1[1].parent.mBox.mBR.x + 3) = 0;
    pJVar1 = param_1->mpPane;
    *(undefined *)&pJVar1[1].parent.mBox.mTL.y = 0xff;
    *(undefined *)((int)&pJVar1[1].parent.mBox.mTL.y + 1) = 0;
    *(undefined *)((int)&pJVar1[1].parent.mBox.mTL.y + 2) = 0;
    *(undefined *)((int)&pJVar1[1].parent.mBox.mTL.y + 3) = 0xff;
    param_1->mUserData = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMeter_arrowMove(sub_meter_class *) */

void dMeter_arrowMove(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  if ((d_com_inf_game::g_dComIfG_gameInfo._23521_1_ != '\0') && (bVar1 = dMenu_flag(), bVar1 == 0))
  {
    dMeter_arrowCheckStatus(param_1);
    *(char *)(param_1 + 0x3025) = *(char *)(param_1 + 0x3025) + '\x01';
    dMeter_arrowAnime(param_1);
    if (*(char *)(param_1 + 0x3025) < '\x1e') {
      return;
    }
    *(undefined *)(param_1 + 0x3025) = 10;
    return;
  }
  if (*(char *)(param_1 + 0x3025) != '\0') {
    iVar3 = 0;
    *(undefined *)(param_1 + 0x3025) = 0;
    iVar2 = 0;
    do {
      dMeter_arrowErase(param_1 + iVar3 + 0x2e10);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar2 < 4);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMeter_arrowDraw(sub_meter_class *) */

void dMeter_arrowDraw(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + iVar2 + 0x2e10));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 4);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall dMeter_screenDataSet(sub_meter_class *) */

void dMeter_screenDataSet(sub_meter_class *this)

{
  undefined4 *puVar1;
  float fVar2;
  undefined4 uVar3;
  J2DScreen *pJVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  sub_meter_class *local_r26_568;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 local_cc;
  int local_c8 [19];
  undefined4 uStack124;
  int local_78 [23];
  
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2f8,sMainParts1,0x77697931);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x100,sMainParts1,0x79726967);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x138,sMainParts1,0x797570);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x170,sMainParts1,0x796c6566);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x250,sMainParts1,0x72);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x288,sMainParts1,0x6c);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2c0,sMainParts1,0x63727331);
  fVar2 = 2_0;
  (this->field_0x100).mPosCenterOrig.x = (this->field_0x100).mPosCenterOrig.x - 2_0;
  (this->field_0x138).mPosCenterOrig.y = (this->field_0x138).mPosCenterOrig.y - fVar2;
  (this->field_0x170).mPosCenterOrig.x = (this->field_0x170).mPosCenterOrig.x - 1_0;
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x368,sMainParts1,0x62657931);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x3a0,sMainParts1,0x62657932);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x3d8,sMainParts1,0x656e656d);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x410,sMainParts1,0x656e6d32);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x448,sMainParts1,0x62656e31);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x480,sMainParts1,0x62656e32);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x4b8,sMainParts1,0x62656e33);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x4f0,sMainParts1,0x62656e34);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x528,sMainParts1,0x656e6533);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x560,sMainParts1,0x656e6532);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x598,sMainParts1,0x656e6531);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x5d0,sMainParts1,0x656e6b32);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x608,sMainParts1,0x656e656b);
  puVar6 = &uStack124;
  puVar5 = (undefined4 *)&DAT_803611a4;
  iVar9 = 10;
  do {
    puVar1 = puVar5 + 1;
    puVar5 = puVar5 + 2;
    uVar3 = *puVar5;
    puVar6[1] = *puVar1;
    puVar6 = puVar6 + 2;
    *puVar6 = uVar3;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  puVar6 = &local_cc;
  puVar5 = (undefined4 *)&UNK_803611f4;
  iVar9 = 10;
  do {
    puVar1 = puVar5 + 1;
    puVar5 = puVar5 + 2;
    uVar3 = *puVar5;
    puVar6[1] = *puVar1;
    puVar6 = puVar6 + 2;
    *puVar6 = uVar3;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  iVar9 = 0;
  iVar8 = 0;
  iVar7 = 0;
  do {
    local_r26_568 = (sub_meter_class *)(&this->field_0x0 + iVar7);
    f_op_msg_mng::fopMsgM_setPaneData
              (local_r26_568->field_0x640,sMainParts1,*(int *)((int)local_78 + iVar8));
    f_op_msg_mng::fopMsgM_setPaneData
              (local_r26_568->field_0xaa0,sMainParts1,*(int *)((int)local_c8 + iVar8));
    iVar9 = iVar9 + 1;
    iVar8 = iVar8 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar9 < 0x14);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0xf00,sMainParts1,0x6874666c);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0xf38,sMainParts1,0x6d627231);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0xf70,sMainParts1,0x6d627232);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0xfa8,sMainParts1,0x6d627233);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0xfe0,sMainParts1,0x6d627234);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1018,sMainParts1,0x6d627235);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1050,sMainParts1,0x6d627236);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1088,sMainParts1,0x6d627237);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x10c0,sMainParts1,0x6d627238);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x10f8,sMainParts1,0x6d626233);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1130,sMainParts1,0x6d626232);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x11a0,sMainParts1,0x6d626231);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1168,sMainParts1,0x6d626b32);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x11d8,sMainParts1,0x6d626b31);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1210,sMainParts1,0x636d6376);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1248,sMainParts1,0x636d6d67);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1280,sMainParts1,0x636d6d6b);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x12b8,sMainParts1,0x636d7267);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x12f0,sMainParts1,0x636d6231);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1398,sMainParts3,0x626172);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x13d0,sMainParts3,0x726e6732);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1408,sMainParts3,0x68727a31);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1440,sMainParts3,0x68727a32);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1478,sMainParts3,0x73747235);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x14b0,sMainParts3,0x73747236);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x14e8,sMainParts3,0x73747237);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1520,sMainParts3,0x6d6f6e32);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1558,sMainParts3,0x73756e32);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1590,sMainParts3,0x63697231);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x15c8,sMainParts3,0x63697232);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1600,sMainParts3,0x63697233);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1638,sMainParts3,0x63697234);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1670,sMainParts3,0x636e7432);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x16a8,sMainParts3,0x636e7431);
  local_cc = 0;
  pJVar4 = (this->field_0x16a8).mpPane;
  *(undefined *)&pJVar4[1].parent.mBox.mTL.y = 0;
  *(undefined *)((int)&pJVar4[1].parent.mBox.mTL.y + 1) = 0;
  *(undefined *)((int)&pJVar4[1].parent.mBox.mTL.y + 2) = 0;
  *(undefined *)((int)&pJVar4[1].parent.mBox.mTL.y + 3) = 0;
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x16e0,sMainParts3,0x726e6731);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1718,sMainParts3,0x73747231);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1750,sMainParts3,0x73747232);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1788,sMainParts3,0x73747233);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x17c0,sMainParts3,0x73747234);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x17f8,sMainParts3,0x6d6f6e31);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1830,sMainParts3,0x636c70);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1868,sMainParts3,0x636c6431);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x18a0,sMainParts3,0x636c6432);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x18d8,sMainParts3,0x636c6433);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1910,sMainParts3,0x73756e31);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1948,sMainParts3,0x636d746d);
  pJVar4 = (this->field_0x1830).mpPane;
  *(undefined *)&pJVar4[1].parent.mBox.mTL.y = 0;
  *(undefined *)((int)&pJVar4[1].parent.mBox.mTL.y + 1) = 0;
  *(undefined *)((int)&pJVar4[1].parent.mBox.mTL.y + 2) = 0;
  *(undefined *)((int)&pJVar4[1].parent.mBox.mTL.y + 3) = 0;
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1980,sMainParts1,0x6b796c31);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x19b8,sMainParts1,0x6b796c32);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1ad0,sMainParts1,0x6e6d3033);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1b08,sMainParts1,0x6e6d3034);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1c20,sMainParts1,0x6e6d3038);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1c58,sMainParts1,0x6e6d3039);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1c90,sMainParts1,0x6b657930);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1cc8,sMainParts1,0x62617376);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1d00,sMainParts1,0x62617764);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1d38,sMainParts1,0x62617770);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1de0,sMainParts1,0x62616132);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1e50,sMainParts1,0x62617432);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2010,sMainParts1,0x793031);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1f68,sMainParts1,0x793130);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x20b8,sMainParts1,0x7969746d);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2160,sMainParts1,0x7969746b);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2358,sMainParts1,0x626c7931);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2400,sMainParts1,0x626c7932);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x24a8,sMainParts1,0x626c7933);
  (((this->field_0x2358).mpPane)->parent).mbDraw = 0;
  (((this->field_0x2400).mpPane)->parent).mbDraw = 0;
  (((this->field_0x24a8).mpPane)->parent).mbDraw = 0;
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1fd8,sMainParts1,0x783031);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1f30,sMainParts1,0x783130);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2080,sMainParts1,0x7869746d);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2128,sMainParts1,0x7869746b);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2320,sMainParts1,0x626c7831);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x23c8,sMainParts1,0x626c7832);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2470,sMainParts1,0x626c7833);
  (((this->field_0x2320).mpPane)->parent).mbDraw = 0;
  (((this->field_0x23c8).mpPane)->parent).mbDraw = 0;
  (((this->field_0x2470).mpPane)->parent).mbDraw = 0;
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2048,sMainParts1,0x7a3031);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1fa0,sMainParts1,0x7a3130);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x20f0,sMainParts1,0x7a69746d);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2198,sMainParts1,0x7a69746b);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2390,sMainParts1,0x626c7a31);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2438,sMainParts1,0x626c7a32);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x24e0,sMainParts1,0x626c7a33);
  (((this->field_0x2390).mpPane)->parent).mbDraw = 0;
  (((this->field_0x2438).mpPane)->parent).mbDraw = 0;
  (((this->field_0x24e0).mpPane)->parent).mbDraw = 0;
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2518,sMainParts1,0x62617a);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2588,sMainParts1,0x626179);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x25f8,sMainParts1,0x62303032);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2668,sMainParts1,0x62613032);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2550,sMainParts1,0x62617831);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x25c0,sMainParts1,0x62303031);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2630,sMainParts1,0x62613031);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1da8,sMainParts1,0x626161);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1e18,sMainParts1,0x62617765);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x26a0,sMainParts1,0x62617231);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x26d8,sMainParts1,0x62613072);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2748,sMainParts1,0x613130);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2780,sMainParts1,0x613031);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x27b8,sMainParts1,0x79756d);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x27f0,sMainParts1,0x79756d6b);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2828,sMainParts1,0x77656974);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2860,sMainParts1,0x7769746b);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2898,sMainParts1,0x626162);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x28d0,sMainParts1,0x62616174);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2908,sMainParts1,0x63656e74);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2940,sMainParts1,0x61727731);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x29b0,sMainParts1,0x69703030);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2978,sMainParts1,0x61727732);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x29e8,sMainParts1,0x69703032);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2a20,sMainParts2,0x72757031);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x2a58,sMainParts2,0x72757032);
  f_op_msg_mng::fopMsgM_setPaneData(this->field_0x19f0,sMainParts2,0x6e6d3030);
  f_op_msg_mng::fopMsgM_setPaneData(this->field_0x19f0 + 1,sMainParts2,0x6e6d3031);
  f_op_msg_mng::fopMsgM_setPaneData(this->field_0x19f0 + 2,sMainParts2,0x6e6d3032);
  f_op_msg_mng::fopMsgM_setPaneData(this->field_0x19f0 + 3,sMainParts2,0x6e6d3033);
  f_op_msg_mng::fopMsgM_setPaneData(this->field_0x1b40,sMainParts2,0x6e6d3034);
  f_op_msg_mng::fopMsgM_setPaneData(this->field_0x1b40 + 1,sMainParts2,0x6e6d3035);
  f_op_msg_mng::fopMsgM_setPaneData(this->field_0x1b40 + 2,sMainParts2,0x6e6d3036);
  f_op_msg_mng::fopMsgM_setPaneData(this->field_0x1b40 + 3,sMainParts2,0x6e6d3037);
  this->field_0x19f0[1].mUserData =
       (ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrentWalletIndex
  ;
  dMeter_walletChange(this);
  return;
}


/* __stdcall dMeter_screenDataTimeSet(sub_meter_class *) */

void dMeter_screenDataTimeSet(sub_meter_class *param_1)

{
  J2DScreen *pJVar1;
  ulong uVar2;
  int iVar3;
  TBox2_float_ local_28;
  TBox2_float_ local_18;
  
  pJVar1 = (J2DScreen *)JKernel::operator_new(0xd4);
  if (pJVar1 == (J2DScreen *)0x0) {
    sScrTimer1 = pJVar1;
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_meter.cpp",0x323f,"sScrTimer1 != 0");
    m_Do_printf::OSPanic("d_meter.cpp",0x323f,&DAT_80361783);
  }
  else {
    local_18.mTL.x = 0_0;
    local_18.mTL.y = 0_0;
    local_18.mBR.x = 640_0;
    local_18.mBR.y = 480_0;
    J2DPane::J2DPane((J2DPane *)pJVar1,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    (pJVar1->parent).vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    pJVar1->field_0xd0 = (_GXColor)0xffffffff;
    pJVar1->mbClipToParent = 0;
    sScrTimer1 = pJVar1;
  }
  pJVar1 = (J2DScreen *)JKernel::operator_new(0xd4);
  if (pJVar1 == (J2DScreen *)0x0) {
    sScrTimer2 = pJVar1;
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_meter.cpp",0x3241,"sScrTimer2 != 0");
    m_Do_printf::OSPanic("d_meter.cpp",0x3241,&DAT_80361783);
  }
  else {
    local_28.mTL.x = 0_0;
    local_28.mTL.y = 0_0;
    local_28.mBR.x = 640_0;
    local_28.mBR.y = 480_0;
    J2DPane::J2DPane((J2DPane *)pJVar1,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    (pJVar1->parent).vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    pJVar1->field_0xd0 = (_GXColor)0xffffffff;
    pJVar1->mbClipToParent = 0;
    sScrTimer2 = pJVar1;
  }
  J2DScreen::set(sScrTimer1,"time_swim_1.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpSwimResArchive);
  J2DScreen::set(sScrTimer2,"time_swim_2.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpSwimResArchive);
  f_op_msg_mng::fopMsgM_setPaneData(param_1->field_0x2a90 + 8,sScrTimer2,0x686b3333);
  f_op_msg_mng::fopMsgM_setPaneData(param_1->field_0x2a90 + 7,sScrTimer2,0x686b3332);
  f_op_msg_mng::fopMsgM_setPaneData(param_1->field_0x2a90 + 6,sScrTimer2,0x686b3331);
  f_op_msg_mng::fopMsgM_setPaneData(param_1->field_0x2a90 + 5,sScrTimer2,0x686b3233);
  f_op_msg_mng::fopMsgM_setPaneData(param_1->field_0x2a90 + 4,sScrTimer2,0x686b3232);
  f_op_msg_mng::fopMsgM_setPaneData(param_1->field_0x2a90 + 3,sScrTimer2,0x686b3231);
  f_op_msg_mng::fopMsgM_setPaneData(param_1->field_0x2a90 + 2,sScrTimer2,0x686b3133);
  f_op_msg_mng::fopMsgM_setPaneData(param_1->field_0x2a90 + 1,sScrTimer2,0x686b3132);
  f_op_msg_mng::fopMsgM_setPaneData(param_1->field_0x2a90,sScrTimer2,0x686b3131);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x2c88,sScrTimer2,0x776b3030);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x2cc0,sScrTimer2,0x6d736b32);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x2d30,sScrTimer1,0x6d736b31);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x2cf8,sScrTimer1,0x736f756c);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x2da0,sScrTimer1,0x6d61696e);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x2dd8,sScrTimer1,0x6b673030);
  iVar3 = (*(code *)((sScrTimer2->parent).vtbl)->search)(sScrTimer2,0x6b7261);
  *(undefined *)(iVar3 + 0xaa) = 0;
  return;
}


/* __stdcall dMeter_screenDataArrowSet(sub_meter_class *) */

void dMeter_screenDataArrowSet(sub_meter_class *param_1)

{
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x2e10,sChoiceRoad,0x79617a34);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x2e48,sChoiceRoad,0x79617a33);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x2e80,sChoiceRoad,0x79617a32);
  f_op_msg_mng::fopMsgM_setPaneData(&param_1->field_0x2eb8,sChoiceRoad,0x79617a31);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall dMeter_Draw(sub_meter_class *) */

undefined4 dMeter_Draw(sub_meter_class *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x2f8);
  iVar2 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)((int)&(this->field_0x100).mpPane + iVar4))
    ;
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 3);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x250);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x288);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x2c0);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x368);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x3a0);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x3d8);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x410);
  iVar2 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)((int)&(this->field_0x448).mpPane + iVar4))
    ;
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 4);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x528);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x560);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x598);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x608);
  dMeter_heartDraw(this);
  iVar2 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)((int)&(this->field_0xf38).mpPane + iVar4))
    ;
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 8);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x10f8);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x11a0);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x11d8);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x1210);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x12f0);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x1398);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x13d0);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x1408);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x1440);
  iVar2 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha
              ((fopMsgM_pane_class *)((int)&(this->field_0x1478).mpPane + iVar4));
    f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x1868);
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 3);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x1520);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x1558);
  iVar2 = 0;
  iVar4 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha
              ((fopMsgM_pane_class *)((int)&(this->field_0x1590).mpPane + iVar4));
    f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x1718);
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x38;
  } while (iVar2 < 4);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x1670);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x16a8);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x16e0);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x17f8);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x1830);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x1910);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x1948);
  if (((((this->field_0x1830).mpPane)->parent).mbDraw == 0) ||
     (*(char *)&this->field_0x3020 != '\a')) {
    iVar2 = 0;
    iVar4 = 3;
    do {
      (&DAT_803e6d2b)[iVar2] = 0;
      iVar2 = iVar2 + 0x84;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  else {
    iVar2 = 0;
    iVar4 = 3;
    do {
      (&DAT_803e6d2b)[iVar2] = (this->field_0x1830).mAlpha;
      iVar2 = iVar2 + 0x84;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x1980);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x19b8);
  iVar4 = 0;
  iVar2 = 0;
  do {
    iVar3 = &this->field_0x0 + iVar2;
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar3 + 0x1ad0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar3 + 0x1c20));
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar4 < 2);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x1c90);
  dMeter_weponDraw(this);
  dMeter_actionDraw(this);
  dMeter_xyDraw(this);
  dMeter_rDraw(this);
  iVar4 = 0;
  iVar2 = 0;
  do {
    iVar3 = &this->field_0x0 + iVar2;
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar3 + 0x19f0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar3 + 0x1b40));
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar4 < 4);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x2a20);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x2a58);
  dMeter_swimDraw(this);
  dMeter_arrowDraw(this);
  iVar2 = f_op_overlap_mng::fopOvlpM_IsDoingReq();
  if (iVar2 == 0) {
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      (dDlst_base_c *)&meter1);
    iVar2 = 0;
    iVar4 = 0;
    do {
      dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                        (dDlst_base_c *)(&clock + iVar4));
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0x84;
    } while (iVar2 < 3);
    if ((sScrTimer1 != (J2DScreen *)0x0) && (sScrTimer2 != (J2DScreen *)0x0)) {
      dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,&tekari.parent);
    }
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x94,
                      (dDlst_base_c ****)&d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x98,
                      (dDlst_base_c *)&meter2);
    dMeter_moveItemDraw(this);
    if ((((*(char *)&this->field_0x3028 == '\x01') &&
         (d_com_inf_game::g_dComIfG_gameInfo.field_0x5be7 != 0)) &&
        (uVar1 = this->field_0x3004, (uVar1 & 8) == 0)) &&
       ((((uVar1 & 0x10) == 0 && ((uVar1 & 0x800000) == 0)) && ((uVar1 & 0x20) == 0)))) {
      dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                        (dDlst_base_c *)dMn_c);
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x80204bf8) */
/* WARNING: Removing unreachable block (ram,0x80204bf0) */
/* WARNING: Removing unreachable block (ram,0x80204c00) */
/* __stdcall dMeter_Execute(sub_meter_class *) */

undefined4 dMeter_Execute(sub_meter_class *param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(param_1->mpHeap);
  *(undefined *)&param_1->field_0x3024 = 0;
  dMeter_statusCheck(param_1);
  dMeter_alphaControl(param_1);
  dMeter_heartMove(param_1);
  dMeter_actionMove(param_1);
  dMeter_weponMove(param_1);
  dMeter_xyMove(param_1);
  dMeter_rMove(param_1);
  dVar10 = (double)((float)((double)CONCAT44(0x43300000,(int)DAT_803e6948 ^ 0x80000000) - _4622) /
                   _9165);
  dVar9 = (double)((float)((double)CONCAT44(0x43300000,(int)DAT_803e694c ^ 0x80000000) - _4622) /
                  _9165);
  dVar8 = (double)((float)((double)CONCAT44(0x43300000,(int)DAT_803e694e ^ 0x80000000) - _4622) /
                  _9165);
  dMeter_parentPaneTrans(dVar10,&param_1->field_0x2908);
  dMeter_childPaneTrans(dVar10,&param_1->field_0x2898,&param_1->field_0x2908);
  dMeter_childPaneTrans(dVar10,&param_1->field_0x28d0,&param_1->field_0x2908);
  dMeter_childPaneTransOnly(dVar10,dVar9,&param_1->field_0x1d00,&param_1->field_0x2908);
  dMeter_childPaneTransOnly(dVar10,dVar8,&param_1->field_0x2828,&param_1->field_0x2908);
  dMeter_childPaneTransChildTrans
            (dVar10,dVar8,&param_1->field_0x2860,&param_1->field_0x2908,&param_1->field_0x2828);
  dMeter_childPaneTransOnly(dVar10,dVar9,&param_1->field_0x1d38,&param_1->field_0x2908);
  iVar3 = 0;
  iVar6 = 0;
  do {
    iVar4 = &param_1->field_0x0 + iVar6;
    dMeter_childPaneTrans(dVar10,iVar4 + 0x1e18,&param_1->field_0x2908);
    dMeter_childPaneTrans(dVar10,iVar4 + 0x1da8,&param_1->field_0x2908);
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 0x38;
  } while (iVar3 < 2);
  dMeter_childPaneTrans(dVar10,&param_1->field_0x2748,&param_1->field_0x2908);
  dMeter_childPaneTrans(dVar10,&param_1->field_0x2780,&param_1->field_0x2908);
  dMeter_childPaneTrans(dVar10,&param_1->field_0x27b8,&param_1->field_0x2908);
  dMeter_childPaneTrans(dVar10,&param_1->field_0x27f0,&param_1->field_0x2908);
  iVar3 = 0;
  iVar6 = 0;
  do {
    iVar4 = &param_1->field_0x0 + iVar6;
    iVar5 = iVar4 + 0x2080;
    dMeter_childPaneTransOnly(dVar10,dVar8,iVar5,&param_1->field_0x2908);
    dMeter_childPaneTransChildTransOnly(dVar10,dVar8,iVar4 + 0x1fd8,&param_1->field_0x2908,iVar5);
    dMeter_childPaneTransChildTransOnly(dVar10,dVar8,iVar4 + 0x1f30,&param_1->field_0x2908,iVar5);
    dMeter_childPaneTransChildTrans(dVar10,dVar8,iVar4 + 0x2128,&param_1->field_0x2908,iVar5);
    dMeter_childPaneTransChildTrans(dVar10,dVar8,iVar4 + 0x2320,&param_1->field_0x2908,iVar5);
    dMeter_childPaneTransChildTrans(dVar10,dVar8,iVar4 + 0x23c8,&param_1->field_0x2908,iVar5);
    dMeter_childPaneTransChildTrans(dVar10,dVar8,iVar4 + 0x2470,&param_1->field_0x2908,iVar5);
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 0x38;
  } while (iVar3 < 3);
  dMeter_childPaneTrans(dVar10,&param_1->field_0x2518,&param_1->field_0x2908);
  iVar3 = 0;
  iVar6 = 0;
  do {
    iVar4 = &param_1->field_0x0 + iVar6;
    dMeter_childPaneTrans(dVar10,iVar4 + 0x2550,&param_1->field_0x2908);
    dMeter_childPaneTrans(dVar10,iVar4 + 0x25c0,&param_1->field_0x2908);
    dMeter_childPaneTrans(dVar10,iVar4 + 0x2630,&param_1->field_0x2908);
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 0x38;
  } while (iVar3 < 2);
  dMeter_childPaneTransOnly(dVar10,dVar9,&param_1->field_0x1cc8,&param_1->field_0x2908);
  dMeter_childPaneTrans(dVar10,&param_1->field_0x26d8,&param_1->field_0x2908);
  dMeter_childPaneTrans(dVar10,&param_1->field_0x26a0,&param_1->field_0x2908);
  dMeter_enemyMove(param_1);
  dMeter_magicMove(param_1);
  dMeter_windMove(param_1);
  dMeter_metronomeMove(param_1);
  dMeter_rupyMove(param_1);
  dMeter_keyMove(param_1);
  dMeter_compassMove(param_1);
  dMeter_mapMove(param_1);
  dMeter_swimMove(param_1);
  dMeter_arrowMove(param_1);
  cVar2 = dMeter_itemMoveFlagCheck();
  if (cVar2 != '\0') {
    dMeter_moveItemMove(param_1);
  }
  dMeter_arwMove(param_1);
  dMeter_placeNameMove();
  dMeter_menuMove(param_1);
  dMeter_gaugeAlpha(param_1);
  d_com_inf_game::g_dComIfG_gameInfo._23522_1_ = *(undefined *)&param_1->field_0x3024;
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  return 1;
}


/* __stdcall dMeter_IsDelete(sub_meter_class *) */

undefined4 dMeter_IsDelete(void)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dMeter_Delete(sub_meter_class *) */

undefined4 dMeter_Delete(int param_1)

{
  undefined4 uVar1;
  msg_class *pmVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  d_com_inf_game::g_dComIfG_gameInfo._23578_1_ = dMeter_mMapCtrlDisp == (mapCtrlDisp_c)0x0;
  if (rupy_soundOnFlag != '\0') {
    JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x83a,(cXyz *)0x0,0,0,1_0,1_0,_4617,_4617,0);
    rupy_soundSetFlag = 0;
    rupy_soundOnFlag = '\0';
  }
  if (dMeter_windID != 0xffffffff) {
    pmVar2 = f_op_msg_mng::fopMsgM_SearchByID(dMeter_windID);
    if (pmVar2 == (msg_class *)0x0) {
      dMeter_windID = 0xffffffff;
      dMeter_windStatus = 0;
    }
    else {
      f_op_msg_mng::fopMsgM_SearchByID(dMeter_windID);
      f_op_msg_mng::fopMsgM_Delete();
      dMeter_windID = 0xffffffff;
      dMeter_windStatus = 0;
    }
  }
  iVar3 = *(int *)(param_1 + 0x2f20);
  if (iVar3 != 0) {
    *(undefined4 *)(iVar3 + 0x60) = 0xffffffff;
    *(uint *)(iVar3 + 0x20c) = *(uint *)(iVar3 + 0x20c) | 1;
    *(uint *)(*(int *)(param_1 + 0x2f20) + 0x20c) =
         *(uint *)(*(int *)(param_1 + 0x2f20) + 0x20c) & 0xffffffbf;
  }
  iVar3 = 0;
  iVar5 = 2;
  do {
    iVar4 = *(int *)(param_1 + iVar3 + 0x2f24);
    if (iVar4 != 0) {
      *(undefined4 *)(iVar4 + 0x60) = 0xffffffff;
      *(uint *)(iVar4 + 0x20c) = *(uint *)(iVar4 + 0x20c) | 1;
      iVar4 = *(int *)(param_1 + iVar3 + 0x2f24);
      *(uint *)(iVar4 + 0x20c) = *(uint *)(iVar4 + 0x20c) & 0xffffffbf;
    }
    iVar3 = iVar3 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar3 = 0;
  iVar5 = 2;
  do {
    iVar4 = *(int *)(param_1 + iVar3 + 0x2f2c);
    if (iVar4 != 0) {
      *(undefined4 *)(iVar4 + 0x60) = 0xffffffff;
      *(uint *)(iVar4 + 0x20c) = *(uint *)(iVar4 + 0x20c) | 1;
      iVar4 = *(int *)(param_1 + iVar3 + 0x2f2c);
      *(uint *)(iVar4 + 0x20c) = *(uint *)(iVar4 + 0x20c) & 0xffffffbf;
    }
    iVar3 = iVar3 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (dMn_c != (dMetronome_c *)0x0) {
    ::dMetronome_c::_delete(dMn_c);
    if (dMn_c != (dMetronome_c *)0x0) {
      (**(code **)(dMn_c->vtbl + 8))(dMn_c,1);
    }
    dMn_c = (dMetronome_c *)0x0;
  }
  iVar3 = 0;
  iVar5 = 0;
  do {
    JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + iVar5 + 0x2f3c));
    JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + iVar5 + 0x2f48));
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar3 < 3);
  iVar3 = 0;
  iVar5 = 0;
  do {
    JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + iVar5 + 0x2f34));
    if (iVar3 == 0) {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + iVar5 + 0x2f60));
    }
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar3 < 2);
  if (sMainParts1 != (int *)0x0) {
    (**(code **)(*sMainParts1 + 8))(sMainParts1,1);
  }
  if (sMainParts2 != (int *)0x0) {
    (**(code **)(*sMainParts2 + 8))(sMainParts2,1);
  }
  if (sMainParts3 != (int *)0x0) {
    (**(code **)(*sMainParts3 + 8))(sMainParts3,1);
  }
  if ((sScrTimer1 != (J2DScreen *)0x0) && (sScrTimer2 != (J2DScreen *)0x0)) {
    (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpSwimResArchive)->parent).parent.vtbl)->
              removeResourceAll)();
    if (sScrTimer1 != (J2DScreen *)0x0) {
      (*(code *)((sScrTimer1->parent).vtbl)->_J2DPane)(sScrTimer1,1);
    }
    if (sScrTimer2 != (J2DScreen *)0x0) {
      (*(code *)((sScrTimer2->parent).vtbl)->_J2DPane)(sScrTimer2,1);
    }
    sScrTimer1 = (J2DScreen *)0x0;
    sScrTimer2 = (J2DScreen *)0x0;
  }
  if (sChoiceRoad != (int *)0x0) {
    (**(code **)(*sChoiceRoad + 8))(sChoiceRoad,1);
  }
  sChoiceRoad = (int *)0x0;
  if (moveItemPane != (int *)0x0) {
    (**(code **)(*moveItemPane + 8))(moveItemPane,1);
  }
  moveItemPane = (int *)0x0;
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  f_op_msg_mng::fopMsgM_destroyExpHeap(*(undefined4 *)(param_1 + 0xfc));
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e690c);
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e6a70);
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e6b48);
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e6be0);
  mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e68e0);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dMeter_Create(msg_class *) */

undefined4 dMeter_Create(sub_meter_class *this)

{
  JKRHeap *pJVar1;
  ulong uVar2;
  undefined4 uVar3;
  J2DScreen *pJVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  TBox2_float_ local_58;
  TBox2_float_ local_48;
  TBox2_float_ local_38;
  TBox2_float_ local_28;
  
  mapAlpha = 0;
  menu_status = 0;
  menu_status_old = 0;
  dMenu_pause = 0;
  dMenu_frame_timer = 0;
  dMenu_menuButton = 0;
  subWinFlag = 0;
  dMeter_auctionFlag = 0;
  dMeter_itemMoveFlag = 0;
  dMeter_btn_chk = 0;
  dMeter_itemNum = 0;
  dMeter_itemTimer = 0;
  texRateX = 0_0;
  texRateY = 0_0;
  texScaleX = 0_0;
  texScaleY = 0_0;
  dMenu_menuFlag = 0;
  dMeter_place_name = 0;
  dMeter_itemMode = 0;
  dMeter_collectMode = 0;
  rupy_soundSetFlag = 0;
  rupy_soundOnFlag = 0;
  pJVar1 = f_op_msg_mng::fopMsgM_createExpHeap(0x2a819);
  this->mpHeap = pJVar1;
  if (this->mpHeap == (JKRHeap *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_meter.cpp",0x34a3,"i_Meter->heap != 0");
    m_Do_printf::OSPanic("d_meter.cpp",0x34a3,&DAT_80361783);
  }
  uVar3 = m_Do_ext::mDoExt_setCurrentHeap(this->mpHeap);
  pJVar4 = (J2DScreen *)JKernel::operator_new(0xd4);
  if (pJVar4 == (J2DScreen *)0x0) {
    sMainParts1 = pJVar4;
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_meter.cpp",0x34a8,"sMainParts1 != 0");
    m_Do_printf::OSPanic("d_meter.cpp",0x34a8,&DAT_80361783);
  }
  else {
    local_58.mTL.x = 0_0;
    local_58.mTL.y = 0_0;
    local_58.mBR.x = 640_0;
    local_58.mBR.y = 480_0;
    J2DPane::J2DPane((J2DPane *)pJVar4,(J2DPane *)0x0,true,0x726f6f74,&local_58);
    (pJVar4->parent).vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    pJVar4->field_0xd0 = (_GXColor)0xffffffff;
    pJVar4->mbClipToParent = 0;
    (pJVar4->parent).vtbl = (J2DPane__vtable *)&MyScreen::__vt;
    sMainParts1 = pJVar4;
  }
  J2DScreen::set(sMainParts1,"main_parts1.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMenuArchive);
  pJVar4 = (J2DScreen *)JKernel::operator_new(0xd4);
  if (pJVar4 == (J2DScreen *)0x0) {
    sMainParts2 = pJVar4;
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_meter.cpp",0x34ac,"sMainParts2 != 0");
    m_Do_printf::OSPanic("d_meter.cpp",0x34ac,&DAT_80361783);
  }
  else {
    local_28.mTL.x = 0_0;
    local_28.mTL.y = 0_0;
    local_28.mBR.x = 640_0;
    local_28.mBR.y = 480_0;
    J2DPane::J2DPane((J2DPane *)pJVar4,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    (pJVar4->parent).vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    pJVar4->field_0xd0 = (_GXColor)0xffffffff;
    pJVar4->mbClipToParent = 0;
    sMainParts2 = pJVar4;
  }
  J2DScreen::set(sMainParts2,"main_parts2.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMenuArchive);
  pJVar4 = (J2DScreen *)JKernel::operator_new(0xd4);
  if (pJVar4 == (J2DScreen *)0x0) {
    sMainParts3 = pJVar4;
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_meter.cpp",0x34b0,"sMainParts3 != 0");
    m_Do_printf::OSPanic("d_meter.cpp",0x34b0,&DAT_80361783);
  }
  else {
    local_38.mTL.x = 0_0;
    local_38.mTL.y = 0_0;
    local_38.mBR.x = 640_0;
    local_38.mBR.y = 480_0;
    J2DPane::J2DPane((J2DPane *)pJVar4,(J2DPane *)0x0,true,0x726f6f74,&local_38);
    (pJVar4->parent).vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    pJVar4->field_0xd0 = (_GXColor)0xffffffff;
    pJVar4->mbClipToParent = 0;
    sMainParts3 = pJVar4;
  }
  J2DScreen::set(sMainParts3,"main_parts3.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMenuArchive);
  pJVar4 = (J2DScreen *)JKernel::operator_new(0xd4);
  if (pJVar4 == (J2DScreen *)0x0) {
    sChoiceRoad = pJVar4;
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_meter.cpp",0x34b4,"sChoiceRoad != 0");
    m_Do_printf::OSPanic("d_meter.cpp",0x34b4,&DAT_80361783);
  }
  else {
    local_48.mTL.x = 0_0;
    local_48.mTL.y = 0_0;
    local_48.mBR.x = 640_0;
    local_48.mBR.y = 480_0;
    J2DPane::J2DPane((J2DPane *)pJVar4,(J2DPane *)0x0,true,0x726f6f74,&local_48);
    (pJVar4->parent).vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    pJVar4->field_0xd0 = (_GXColor)0xffffffff;
    pJVar4->mbClipToParent = 0;
    sChoiceRoad = pJVar4;
  }
  J2DScreen::set(sChoiceRoad,"choice_road.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMenuArchive);
  iVar6 = 0;
  iVar8 = 0;
  do {
    pvVar5 = JKRHeap::alloc(this->mpHeap,0xc00,0x20);
    iVar7 = &this->field_0x0 + iVar8;
    *(void **)(iVar7 + 0x2f3c) = pvVar5;
    if (*(int *)(iVar7 + 0x2f3c) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_meter.cpp",0x34b9,"i_Meter->actionTex[i] != 0");
      m_Do_printf::OSPanic("d_meter.cpp",0x34b9,&DAT_80361783);
    }
    pvVar5 = JKRHeap::alloc(this->mpHeap,0xc00,0x20);
    *(void **)(iVar7 + 0x2f48) = pvVar5;
    if (*(int *)(iVar7 + 0x2f48) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_meter.cpp",0x34bb,"i_Meter->xyIconTex[i] != 0");
      m_Do_printf::OSPanic("d_meter.cpp",0x34bb,&DAT_80361783);
    }
    iVar6 = iVar6 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar6 < 3);
  iVar6 = 0;
  iVar8 = 0;
  do {
    if (iVar6 == 0) {
      pvVar5 = JKRHeap::alloc(this->mpHeap,0xc00,0x20);
      *(void **)(&this->field_0x2f60 + iVar8) = pvVar5;
      if (*(int *)(&this->field_0x2f60 + iVar8) == 0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_meter.cpp",0x34c2,"i_Meter->moveIconTex[i] != 0");
        m_Do_printf::OSPanic("d_meter.cpp",0x34c2,&DAT_80361783);
      }
    }
    pvVar5 = JKRHeap::alloc(this->mpHeap,0xc00,0x20);
    *(void **)(&this->field_0x2f34 + iVar8) = pvVar5;
    if (*(int *)(&this->field_0x2f34 + iVar8) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_meter.cpp",0x34c5,"i_Meter->arrowTex[i] != 0");
      m_Do_printf::OSPanic("d_meter.cpp",0x34c5,&DAT_80361783);
    }
    iVar6 = iVar6 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar6 < 2);
  iVar6 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea_T");
  if (iVar6 != 0) {
    f_op_msg_mng::fopMsgM_Create(0x1ea,0,0);
  }
  f_op_msg_mng::fopMsgM_Create(0x1e6,0,0);
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd0 = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0;
  DAT_803e690c = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"通常画面表示",
                            (JORReflexible *)&g_meterHIO);
  DAT_803e6a70 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"メニュー画面",
                            (JORReflexible *)&g_menuHIO);
  DAT_803e6b48 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"Message（会話）",
                            (JORReflexible *)&g_msgHIO);
  DAT_803e6be0 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"Message（看板）",
                            (JORReflexible *)&g_messageHIO);
  DAT_803e68e0 = mDoHIO_subRoot_c::createChild
                           (&mDoHIO_subRoot_c_803a5778,"マップ２",
                            (JORReflexible *)&g_meter_mapHIO);
  dMeter_screenDataSet(this);
  dMeter_screenDataArrowSet(this);
  d_com_inf_game::g_dComIfG_gameInfo._23577_1_ = 1;
  this->field_0x2f6c = 1_0;
  this->field_0x2fd8 = DAT_803e690e;
  dMeter_mapInit(this);
  dMeter_compassInit(this);
  dMeter_arrowInit(this);
  m_Do_ext::mDoExt_setCurrentHeap(this->mpHeap);
  dMeter_heartInit(this);
  dMeter_weponInit(this);
  dMeter_actionInit(this);
  dMeter_xyInit(this);
  dMeter_rInit(this);
  dMeter_enemyInit(this);
  dMeter_magicInit(this);
  dMeter_menuInit(this);
  dMeter_windInit(this);
  dMeter_metronomeInit(this);
  dMeter_rupyInit(this);
  dMeter_keyInit(this);
  dMeter_moveItemInit(this);
  dMeter_arwInit(this);
  d_timer::dTimer_createStockTimer();
  m_Do_ext::mDoExt_setCurrentHeap(uVar3);
  f_op_msg_mng::fopMsgM_setStageLayer(this);
  return 4;
}

}

/* __thiscall dDlst_2DMETER2_c::~dDlst_2DMETER2_c(void) */

void __thiscall dDlst_2DMETER2_c::_dDlst_2DMETER2_c(dDlst_2DMETER2_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DMETER2_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2DMETER2_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_2DMETER1_c::~dDlst_2DMETER1_c(void) */

void __thiscall dDlst_2DMETER1_c::_dDlst_2DMETER1_c(dDlst_2DMETER1_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DMETER1_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2DMETER1_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMeter_message_HIO_c::~dMeter_message_HIO_c(void) */

void __thiscall dMeter_message_HIO_c::_dMeter_message_HIO_c(dMeter_message_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dMeter_message_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dMeter_msg_HIO_c::~dMeter_msg_HIO_c(void) */

void __thiscall dMeter_msg_HIO_c::_dMeter_msg_HIO_c(dMeter_msg_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dMeter_msg_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dMeter_menuHIO_c::~dMeter_menuHIO_c(void) */

void __thiscall dMeter_menuHIO_c::_dMeter_menuHIO_c(dMeter_menuHIO_c *this)

{
  short in_r4;
  
  if ((this != (dMeter_menuHIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dMeter_HIO_c::~dMeter_HIO_c(void) */

void __thiscall dMeter_HIO_c::_dMeter_HIO_c(dMeter_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dMeter_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dMeter_map_HIO_c::dMeter_map_HIO_c(void) */

void __thiscall dMeter_map_HIO_c::dMeter_map_HIO_c(dMeter_map_HIO_c *this)

{
  *(undefined1 **)this = &__vt;
  *(undefined2 *)(this + 8) = 0x23;
  *(undefined2 *)(this + 10) = 0x152;
  *(undefined2 *)(this + 0xc) = 0xff4c;
  *(undefined2 *)(this + 0x14) = 0x24e;
  *(undefined2 *)(this + 0x16) = 0x96;
  this[6] = (dMeter_map_HIO_c)0xc8;
  this[7] = (dMeter_map_HIO_c)0x1;
  *(float *)(this + 0x10) = d_meter::_4488;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mapCtrlDisp_c::initMapCtrlDisp(void) */

void __thiscall mapCtrlDisp_c::initMapCtrlDisp(mapCtrlDisp_c *this)

{
  dMap_c::mAlpha = 0;
  dMap_c::mIconFreeAlpha = 0;
  dMap_c::mMapDispMode = 1;
  _mDispPosLeftUpX = DAT_803e68e4;
  _mDispPosLeftUpY = DAT_803e68e6;
  _mIconFreePosX = DAT_803e68f0;
  _mIconFreePosY = DAT_803e68f2;
  dMap_c::mIconFreeScale = d_meter::0_0;
  dMap_c::mIconSelfAlpha = 0;
  _mIconSelfScale = d_meter::0_0;
  dMap_c::mIconDispMode = 0;
  *this = (mapCtrlDisp_c)0x0;
  this[1] = (mapCtrlDisp_c)0x0;
  this[2] = (mapCtrlDisp_c)0x0;
  *(undefined2 *)(this + 4) = 0;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mapCtrlDisp_c::moveMapCtrlDisp(void) */

void __thiscall mapCtrlDisp_c::moveMapCtrlDisp(mapCtrlDisp_c *this)

{
  float fVar1;
  char cVar4;
  bool bVar5;
  int iVar2;
  short sVar3;
  uint uVar6;
  double dVar7;
  double dVar8;
  
  cVar4 = d_camera::dCam_isManual
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
                     [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera].mpCamera);
  if (cVar4 == '\0') {
    if (5 < (byte)this[2]) {
      this[2] = (mapCtrlDisp_c)0x5;
    }
    if (this[2] != (mapCtrlDisp_c)0x0) {
      this[2] = (mapCtrlDisp_c)((char)this[2] + -1);
    }
    dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,this[2],2);
    fVar1 = d_meter::1_1;
  }
  else {
    if ((byte)this[2] < 9) {
      this[2] = (mapCtrlDisp_c)((char)this[2] + 1);
      uVar6 = (uint)(byte)this[2];
      if (uVar6 < 6) {
        dVar7 = (double)f_op_msg_mng::fopMsgM_valueIncrease(6,uVar6,0);
        fVar1 = (float)((double)d_meter::1_2 * dVar7);
      }
      else {
        dVar8 = (double)f_op_msg_mng::fopMsgM_valueIncrease(3,uVar6 - 6,2);
        dVar7 = (double)d_meter::1_0;
        fVar1 = d_meter::1_2 - (float)((double)d_meter::0_1 * dVar8);
      }
    }
    else {
      dVar7 = (double)d_meter::1_0;
      fVar1 = d_meter::1_1;
    }
  }
  uVar6 = (uint)((float)((double)d_meter::_4616 * dVar7) *
                (float)((double)(float)((double)CONCAT44(0x43300000,(uint)DAT_803e68e2) -
                                       d_meter::_4620) / (double)d_meter::_4616));
  dMap_c::mIconDispMode = (uVar6 & 0xff) != 0;
  dMap_c::mIconFreeAlpha = (undefined)uVar6;
  dMap_c::mIconFreeScale = fVar1 * DAT_803e68ec;
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0x8 & 0x400) != 0) {
    bVar5 = false;
    if (((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x2a4 &
         0x4000000) != 0) && (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0)) {
      bVar5 = true;
    }
    if (bVar5) {
      dMap_c::mIconSelfAlpha = 0xcc;
      dMap_c::mIconDispMode = 2;
    }
  }
  iVar2 = d_camera::dCam_getBody();
  if (*(int *)(iVar2 + 0x13c) == 4) {
    dMap_c::mIconDispMode = 0;
  }
  if (*this == (mapCtrlDisp_c)0x0) {
    SComponent::cLib_addCalcAngleS((short *)(this + 4),DAT_803e68e8 - DAT_803e68e4,2,0x3c,10);
  }
  else {
    if (((*(short *)(this + 4) != 0) &&
        (sVar3 = SComponent::cLib_addCalcAngleS((short *)(this + 4),0,2,0x3c,10), sVar3 == 0)) &&
       (((byte)this[1] & 4) == 0)) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x819,(cXyz *)0x0,0,0,d_meter::1_0,d_meter::1_0,
                 d_meter::_4617,d_meter::_4617,0);
    }
  }
  uVar6 = (uint)((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mScissorYOrig +
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mScissorHeight) -
                d_meter::_4618);
  _mDispPosLeftUpY = DAT_803e68e6;
  if ((float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) - d_meter::_4622) < d_meter::0_0) {
    _mDispPosLeftUpY = (short)uVar6 + DAT_803e68e6;
  }
  _mDispPosLeftUpX = DAT_803e68e4 + *(short *)(this + 4);
  return;
}


/* __thiscall dMeter_map_HIO_c::~dMeter_map_HIO_c(void) */

void __thiscall dMeter_map_HIO_c::_dMeter_map_HIO_c(dMeter_map_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dMeter_map_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_meter {

void __sinit_d_meter_cpp(void)

{
  Runtime.PPCEABI.H::__register_global_object(&dMeter_Info,::dMeter_info_c::_dMeter_info_c,&_4480);
  ::dMeter_map_HIO_c::dMeter_map_HIO_c((dMeter_map_HIO_c *)&g_meter_mapHIO);
  Runtime.PPCEABI.H::__register_global_object();
  ::dMeter_HIO_c::dMeter_HIO_c((dMeter_HIO_c *)&g_meterHIO);
  Runtime.PPCEABI.H::__register_global_object();
  ::dMeter_menuHIO_c::dMeter_menuHIO_c((dMeter_menuHIO_c *)&g_menuHIO);
  Runtime.PPCEABI.H::__register_global_object();
  ::dMeter_msg_HIO_c::dMeter_msg_HIO_c((dMeter_msg_HIO_c *)&g_msgHIO);
  Runtime.PPCEABI.H::__register_global_object();
  ::dMeter_message_HIO_c::dMeter_message_HIO_c((dMeter_message_HIO_c *)&g_messageHIO);
  Runtime.PPCEABI.H::__register_global_object();
  meter1 = &::dDlst_2DMETER1_c::__vt;
  Runtime.PPCEABI.H::__register_global_object(&meter1,::dDlst_2DMETER1_c::_dDlst_2DMETER1_c,&_4707);
  meter2 = &::dDlst_2DMETER2_c::__vt;
  Runtime.PPCEABI.H::__register_global_object(&meter2,::dDlst_2DMETER2_c::_dDlst_2DMETER2_c,&_4708);
  tekari.parent = (undefined *)&::dDlst_2Dm_c::__vt;
  Runtime.PPCEABI.H::__register_global_object(&tekari,::dDlst_2Dm_c::_dDlst_2Dm_c,&_4709);
  Runtime.PPCEABI.H::__construct_array
            (&clock,::dDlst_2Dm_c::dDlst_2Dm_c,::dDlst_2Dm_c::_dDlst_2Dm_c,0x84,3);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4710,&_4711);
  return;
}


void __arraydtor_4710(void)

{
  Runtime.PPCEABI.H::__destroy_arr(&clock,::dDlst_2Dm_c::_dDlst_2Dm_c,0x84,3);
  return;
}

}

/* __thiscall dDlst_2Dm_c::dDlst_2Dm_c(void) */

void __thiscall dDlst_2Dm_c::dDlst_2Dm_c(dDlst_2Dm_c *this)

{
  (this->parent).vtbl = (undefined *)&dDlst_base_c::__vt;
  (this->parent).vtbl = (undefined *)&__vt;
  return;
}


/* __thiscall dMeter_info_c::~dMeter_info_c(void) */

void __thiscall dMeter_info_c::_dMeter_info_c(dMeter_info_c *this)

{
  short in_r4;
  
  if ((this != (dMeter_info_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dMetronome_c::~dMetronome_c(void) */

void __thiscall dMetronome_c::_dMetronome_c(dMetronome_c *this)

{
  short in_r4;
  
  if (this != (dMetronome_c *)0x0) {
    this->vtbl = (undefined *)&__vt;
    if (this != (dMetronome_c *)0x0) {
      this->vtbl = (undefined *)&dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMetronome_c::draw(void) */

void __thiscall dMetronome_c::draw(dMetronome_c *this)

{
  _draw(this);
  return;
}

