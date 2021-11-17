#pragma once
#include <ctypes.h>



namespace d_msg {
//Expected size is 0x000020
extern undefined4 button_icon;

//Expected size is 0x000020
extern undefined4 button_kage;

//Expected size is 0x000010
extern undefined2 buttonTimer;

//Expected size is 0x00000c
extern undefined4 numberPane;

//Expected size is 0x00000c
extern undefined4 capture;

//Expected size is 0x000038
extern undefined4 multiTex;

//Expected size is 0x000004
extern undefined4 sScreen;

//Expected size is 0x000004
extern undefined4 sScreen2;

//Expected size is 0x000004
extern undefined4 textFont;

//Expected size is 0x000004
extern undefined4 rubyFont;

//Expected size is 0x000004
extern undefined4 arrowPane;

//Expected size is 0x000004
extern undefined4 maskPane;

//Expected size is 0x000004
extern float talkPosX;

//Expected size is 0x000004
extern float talkPosY;

//Expected size is 0x000002
extern undefined2 textOffsetY;

//Expected size is 0x000001
extern undefined1 dMsg_font_flag;

//Expected size is 0x000004
extern undefined4 agb_work_area;

//Expected size is 0x000008
extern undefined4 message;

//Expected size is 0x000001
extern undefined1 flag$7049;

//Expected size is 0x000001
extern undefined1 init$7050;

//Expected size is 0x000002
extern undefined2 cnt$7052;

//Expected size is 0x000001
extern undefined1 init$7053;

//Expected size is 0x000004
extern undefined4 posY0$7922;

//Expected size is 0x000001
extern undefined1 init$7923;

//Expected size is 0x000004
extern undefined4 posY1$7925;

//Expected size is 0x000001
extern undefined1 init$7926;

//Expected size is 0x000004
extern undefined4 posY2$7928;

//Expected size is 0x000001
extern undefined1 init$7929;

//Expected size is 0x000004
extern undefined4 posY3$7931;

//Expected size is 0x000001
extern undefined1 init$7932;

undefined4 dMsg_getAgbWorkArea(void);
}

namespace d_msg {
void dMsg_msg_pane_parts_set(int param_1,byte param_2);
void dMsg_arw_pane_parts_set(fopMsgM_pane_class *param_1,int param_2);
void dMsg_screenDataSetTalk(int param_1);
void dMsg_screenDataSetItem(int param_1);
void dMsg_screenDataSetDemo(int param_1);
void dMsg_screenDataSetTact(int param_1);
void dMsg_screenDataSet(int param_1);
void dMsg_messagePaneShow(int param_1);
void dMsg_messagePaneHide(int param_1);
void dMsg_outFontHide(void);
void dMsg_ScreenDataValueInitTalk(int param_1);
void dMsg_ScreenDataValueInitItem(int param_1);
void dMsg_ScreenDataValueInitTact(int param_1);
void dMsg_ScreenDataValueInitDemo(int param_1);
void dMsg_value_init(int param_1);
void dMsg_setString(int param_1,undefined4 param_2,... param_3);
void dMsg_yose_select(int param_1);
void dMsg_frame_openTalk(int param_1);
void dMsg_frame_openItem(int param_1);
void dMsg_frame_close(int param_1);
void dMsg_textPosition(int param_1);
void dMsg_rubySet(int param_1);
void dMsg_mesgOutPos(int param_1);
void dMsg_arrowInit(int param_1);
void dMsg_arrowMove(int param_1);
void dMsg_dotMove(int param_1);
void dMsg_ringMove(int param_1);
void dMsg_lightMove(int param_1);
void dMsg_cornerMove(int param_1);
void dMsg_tactGuideShow(int param_1,uint param_2);
void dMsg_numberInput(int param_1,undefined4 param_2,... param_3);
void dMsg_tactInput(int param_1);
void dMsg_tactInput2(void);
void dMsg_subTextScale(double param_1,int param_2);
void dMsg_subTextSizeSet(int param_1);
void dMsg_subTextOpen(int param_1);
void dMsg_subTextClose(int param_1);
void dMsg_setCloseSound(undefined4 param_1,char param_2);
void dMsg_setCancelMode(int param_1);
void dMsg_messageShow(int param_1);
undefined4 dMsg_stopProc(int param_1);
undefined4 dMsg_selectProc(int param_1);
undefined4 dMsg_inputProc(int param_1);
undefined4 dMsg_demoProc(int param_1);
undefined4 dMsg_continueProc(int param_1);
undefined4 dMsg_closewaitProc(int param_1);
undefined4 dMsg_finishProc(int param_1);
undefined4 dMsg_openTalkProc(int param_1);
undefined4 dMsg_openItemProc(int param_1);
undefined4 dMsg_openTactProc(int param_1);
undefined4 dMsg_openDemoProc(int param_1);
undefined4 dMsg_closeProc(void);
undefined4 dMsg_closeProc2(int param_1);
undefined4 dMsg_initProc(int param_1);
undefined4 dMsg_tactProc(int param_1);
undefined4 dMsg_outnowProc(int param_1);
undefined4 dMsg_Draw(int param_1);
undefined4 dMsg_Execute(int param_1);
undefined4 dMsg_IsDelete(void);
undefined4 dMsg_Delete(int param_1);
undefined4 dMsg_Create(int param_1);
}

namespace d_msg {
void __sinit_d_msg_cpp(void);
}
