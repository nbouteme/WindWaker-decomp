#pragma once
#include <ctypes.h>



namespace d_message {
//[Data] Expected size is 0x0000f0
extern undefined dMsg2_tex_i4_color;

//[Data] Expected size is 0x000014
extern undefined * l_dMsg2_Method;

//[Data] Expected size is 0x000028
extern undefined g_profile_MSG2;

}
//[Data] Expected size is 0x000010
extern undefined1 dDlst_2DCopy_c;

//[Data] Expected size is 0x000010
extern undefined1 dDlst_2DMSG2_c;


namespace d_message {
//[BSS] Expected size is 0x00000c
extern undefined4 sScreen2;
//[BSS] Expected size is 0x000060
extern undefined4 bbutton_icon;
//[BSS] Expected size is 0x000060
extern undefined4 bbutton_kage;
//[BSS] Expected size is 0x000030
extern undefined2 bbuttonTimer;
//[BSS] Expected size is 0x000084
extern undefined4 board;
//[BSS] Expected size is 0x00000c
extern undefined4 capture;
//[BSS] Expected size is 0x000004
extern undefined4 dMsg2_popSpeed;
//[BSS] Expected size is 0x000008
extern undefined4 message;
void dMsg2_value_init(int param_1,uint param_2);
void dMsg2_setString(int param_1,uint param_2,... param_3);
void dMsg2_messagePaneShow(int param_1,uint param_2);
void dMsg2_messagePaneHide(int param_1,uint param_2);
void dMsg2_outFontHide(int param_1,uint param_2);
void dMsg2_arrowUpShow(int param_1);
void dMsg2_arrowUpHide(int param_1);
void dMsg2_arrowDownShow(int param_1);
void dMsg2_arrowDownHide(int param_1);
void dMsg2_dotShow(int param_1);
void dMsg2_dotHide(int param_1);
void dMsg2_multiTexInit(int param_1);
void dMsg2_fontdataInit(int param_1);
void dMsg2_screenDataSet(undefined4 param_1,undefined4 param_2);
void dMsg2_screenDataInit(int param_1,byte param_2);
void dMsg2_ScreenDataValueInit(int param_1);
void dMsg2_stickInfoInit(int param_1);
void dMsg2_stickInfoCheck(int param_1);
void dMsg2_multiTexDraw(int param_1,short param_2,short param_3,short param_4,short param_5);
void dMsg2_messageOut(int param_1,uint param_2,undefined4 param_3);
void dMsg2_yose_select(int param_1,uint param_2);
void dMsg2_textPosition(int param_1,uint param_2);
void dMsg2_rubySet(int param_1);
void dMsg2_arrowMove(int param_1);
void dMsg2_aimAlphaSqare(int param_1,uint param_2,uint param_3);
void dMsg2_aimAlphaSqrt(int param_1,uint param_2,uint param_3);
int dMsg2_kankyoBrightness(void);
char dMsg2_aimBrightness(void);
void dMsg2_setCharAlpha(int param_1,uint param_2);
void dMsg2_messageShow(int param_1);
void dMsg2_messageDataInit(int param_1,int param_2);
undefined4 dMsg2_stopProc(int param_1);
undefined4 dMsg2_closewaitProc(int param_1);
undefined4 dMsg2_openProc(int param_1);
undefined4 dMsg2_closeProc(int param_1);
undefined4 dMsg2_outwaitProc(int param_1);
}

namespace d_message {
undefined4 dMsg2_Draw(int param_1);
undefined4 dMsg2_Execute(int param_1);
undefined4 dMsg2_IsDelete(void);
undefined4 dMsg2_Delete(int param_1);
undefined4 dMsg2_Create(int param_1);
}

namespace d_message {
void __sinit_d_message_cpp(void);
}
