#pragma once
#include <ctypes.h>



namespace d_message_paper {
//[Data] Expected size is 0x0000f0
extern undefined dMsg3_tex_i4_color;

//[Data] Expected size is 0x000014
extern undefined * l_dMsg3_Method;

//[Data] Expected size is 0x000028
extern undefined g_profile_MSG3;

}
//[Data] Expected size is 0x000010
extern undefined1 dDlst_2DMSG3_c;

//[Data] Expected size is 0x00000c
extern undefined1 dmsg3_3d_c;


namespace d_message_paper {
//[BSS] Expected size is 0x00000c
extern undefined4 sScreen3;
//[BSS] Expected size is 0x000060
extern undefined4 bbutton_icon3;
//[BSS] Expected size is 0x000060
extern undefined4 bbutton_kage3;
//[BSS] Expected size is 0x000030
extern undefined2 bbuttonTimer3;
//[BSS] Expected size is 0x000084
extern undefined4 board;
//[BSS] Expected size is 0x000004
extern undefined4 msg3d;
//[BSS] Expected size is 0x000004
extern undefined4 dMsg3_popSpeed;
//[BSS] Expected size is 0x000008
extern undefined4 message;
}

namespace d_message_paper {
void loadModelData(void *param_1);
void loadAnmTransformData(void *param_1);
}

namespace d_message_paper {
void dMsg3_value_init(int param_1,uint param_2);
void dMsg3_setString(int param_1,uint param_2,... param_3);
void dMsg3_messagePaneShow(int param_1,uint param_2);
void dMsg3_messagePaneHide(int param_1,uint param_2);
void dMsg3_outFontHide(uint param_1);
void dMsg3_arrowUpShow(int param_1);
void dMsg3_arrowUpHide(int param_1);
void dMsg3_arrowDownShow(int param_1);
void dMsg3_arrowDownHide(int param_1);
void dMsg3_dotShow(int param_1);
void dMsg3_dotHide(int param_1);
void dMsg3_multiTexInit(int param_1);
void dMsg3_fontdataInit(int param_1);
void dMsg3_screenDataSet(undefined4 param_1,undefined4 param_2);
void dMsg3_screenDataInit(int param_1,byte param_2);
void dMsg3_ScreenDataValueInit(int param_1);
void dMsg3_stickInfoInit(int param_1);
void dMsg3_stickInfoCheck(int param_1);
void dMsg3_messageOut(int param_1,uint param_2,undefined4 param_3);
void dMsg3_yose_select(int param_1,uint param_2);
void dMsg3_textPosition(int param_1,uint param_2);
void dMsg3_rubySet(int param_1);
void dMsg3_arrowMove(int param_1);
void dMsg3_aimAlphaSqare(int param_1,uint param_2,uint param_3);
void dMsg3_aimAlphaSqrt(int param_1,uint param_2,uint param_3);
int dMsg3_kankyoBrightness(void);
char dMsg3_aimBrightness(void);
void dMsg3_setCharAlpha(int param_1,uint param_2);
void dMsg3_messageShow(int param_1);
void dMsg3_messageDataInit(int param_1,int param_2);
undefined4 dMsg3_stopProc(int param_1);
undefined4 dMsg3_closewaitProc(int param_1);
undefined4 dMsg3_openProc(int param_1);
undefined4 dMsg3_closeProc(int param_1);
undefined4 dMsg3_outwaitProc(int param_1);
}

namespace d_message_paper {
undefined4 dMsg3_Draw(int param_1);
undefined4 dMsg3_Execute(int param_1);
undefined4 dMsg3_IsDelete(void);
undefined4 dMsg3_Delete(int param_1);
undefined4 dMsg3_Create(int param_1);
}

namespace d_message_paper {
void __sinit_d_message_paper_cpp(void);
}
