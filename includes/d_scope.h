#pragma once
#include <ctypes.h>



namespace d_scope {
//Expected size is 0x000020
extern struct J2DPicture * sbutton_icon[8];

//Expected size is 0x000020
extern struct J2DPicture * sbutton_kage[8];

//Expected size is 0x000010
extern undefined2 sbuttonTimer;

//Expected size is 0x000004
extern undefined4 dScp_ScpScreen;

//Expected size is 0x000004
extern undefined4 dScp_MsgScreen;

//Expected size is 0x000004
extern undefined4 font0;

//Expected size is 0x000004
extern undefined4 font1;

//Expected size is 0x000008
extern undefined4 scope;

}

namespace d_scope {
void dScp_ScreenDataSet(sub_scp_class *param_1);
void dScp_valueInit(int param_1);
void dScp_setAlpha(int param_1);
void dScp_wipeAngleCalc(sub_scp_class *param_1);
void dScp_ArrowAnime(sub_scp_class *param_1);
void dScp_wipeMove(double param_1,int param_2);
void dScp_wipeMove2(double param_1,int param_2);
void dScp_wipeMoveDemo(double param_1,int param_2,char param_3);
void dScp_mesgPaneShow(int param_1);
void dScp_mesgPaneHide(int param_1);
void dScp_scopeAlpha(double param_1,int param_2);
void dScp_scopeInitAlpha(sub_scp_class *param_1);
void dScp_scopeAlphaZero(int param_1);
void dScp_stringInit(int param_1);
void dScp_stringSet(int param_1,undefined4 param_2,... param_3);
void dScp_yose_select(sub_scp_class *param_1);
void dScp_textPosition(int param_1);
void dScp_arrowInit(sub_scp_class *param_1);
void dScp_arrowMove(sub_scp_class *param_1);
void dScp_dotMove(int param_1);
void dScp_talkBeforeProc(sub_scp_class *param_1);
undefined4 dScp_outnowProc(int param_1);
undefined4 dScp_continueProc(sub_scp_class *param_1);
undefined4 dScp_forceContinueProc(int param_1);
undefined4 dScp_closewaitProc(int param_1);
undefined4 dScp_finishProc(int param_1);
void dScp_openProc(sub_scp_class *param_1);
void dScp_openProc1(sub_scp_class *param_1);
void dScp_openProc2(int param_1);
void dScp_moveProc(int param_1);
void dScp_demoProc(int param_1);
void dScp_talkNowProc(int param_1);
void dScp_closeProc(int param_1);
void dScp_closeDemoProc(int param_1);
undefined4 dScp_Draw(void);
undefined4 dScp_Execute(sub_scp_class *param_1);
undefined4 dScp_IsDelete(void);
undefined4 dScp_Delete(int param_1);
undefined4 dScp_Create(sub_scp_class *param_1);
}

namespace d_scope {
void __sinit_d_scope_cpp(void);
}
