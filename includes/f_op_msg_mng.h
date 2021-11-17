#pragma once
#include <ctypes.h>

#include <STControl.h>


namespace f_op_msg_mng {
//Expected size is 0x000028
extern struct STControl stick;

//Expected size is 0x000001
extern undefined1 pushButton;

//Expected size is 0x000001
extern undefined1 pushButton2;

//Expected size is 0x000001
extern undefined1 demoFlag;

//Expected size is 0x000001
extern undefined1 tactFlag;

//Expected size is 0x000001
extern undefined1 nextMsg;

//Expected size is 0x000004
extern undefined4 name$7641;

//Expected size is 0x000001
extern undefined1 init$7642;

//Expected size is 0x000004
extern undefined4 name$7700;

//Expected size is 0x000001
extern undefined1 init$7701;

}

namespace f_op_msg_mng {
bool fopMsgM_hyrule_language_check(int msg_id);
void fopMsgM_setStageLayer(int param_1);
msg_class * fopMsgM_SearchByID(uint param_1);
void fopMsgM_SearchByName(undefined2 param_1);
void fopMsgM_IsExecuting(void);
fopMsgM_prm_class * fopMsgM_GetAppend(msg_class *param_1);
void fopMsgM_Delete(base_process_class *param_1);
fopMsgM_prm_class *createAppend(fopAc_ac_c *pActor,cXyz *pPos,int *param_3,int *param_4,int param_5);
undefined4 *createMGameTermAppend(undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5);
fopMsgM_prm_class *createTimerAppend(int param_1,int param_2,int param_3,float param_4,float param_5,float param_6,float param_7,int param_8);
undefined4 fopMsgM_create(short param_1,fopAc_ac_c *param_2,cXyz *param_3,int *param_4,int *param_5,undefined *param_6);
undefined4 fop_MGameTerm_create(short param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined *param_6);
undefined4 fop_Timer_create(double param_1,double param_2,double param_3,double param_4,short param_5,uint param_6,int param_7,int param_8,int param_9,undefined *param_10);
undefined4 fopMsgM_messageTypeSelect(fopAc_ac_c *param_1,cXyz *param_2,ulong *param_3,ulong *param_4);
}

namespace f_op_msg_mng {
uint fopMsgM_searchMessageNumber(uint param_1);
uint fopMsgM_messageSet(ulong msgId,fopAc_ac_c *actor);
uint fopMsgM_messageSet(ulong param_1,cXyz *param_2);
uint fopMsgM_messageSet(ulong param_1);
uint fopMsgM_scopeMessageSet(ulong param_1);
uint fopMsgM_tactMessageSet(void);
byte * fopMsgM_messageGet(byte *param_1,ulong param_2);
}

namespace f_op_msg_mng {
byte * fopMsgM_passwordGet(byte *param_1,ulong param_2);
void fopMsgM_selectMessageGet(int param_1,J2DTextBox *param_2,J2DTextBox *param_3,char *param_4,char *param_5,char *param_6,char *param_7,ulong param_8);
void fopMsgM_demoMsgFlagOn(void);
void fopMsgM_demoMsgFlagOff(void);
undefined fopMsgM_demoMsgFlagCheck(void);
void fopMsgM_tactMsgFlagOn(void);
void fopMsgM_tactMsgFlagOff(void);
undefined fopMsgM_tactMsgFlagCheck(void);
void fopMsgM_nextMsgFlagOff(void);
undefined fopMsgM_nextMsgFlagCheck(void);
undefined4 fopMsgM_getScopeMode(void);
undefined4 fopMsgM_forceSendOn(void);
void fopMsgM_forceSendOff(void);
undefined fopMsgM_checkForceSend(void);
void fopMsgM_messageSendOn(void);
void fopMsgM_messageSendOff(void);
undefined fopMsgM_checkMessageSend(void);
undefined4 fopMsgM_releaseScopeMode(void);
undefined * fopMsgM_outFontTex(int param_1);
undefined4 fopMsgM_outFontColorWhite(int param_1);
void fopMsgM_outFontSet(J2DPicture *param_1,J2DPicture *param_2,undefined2 *param_3,undefined4 param_4,byte param_5);
void fopMsgM_outFontSet(J2DPicture *param_1,undefined2 *param_2,undefined4 param_3,byte param_4);
void fopMsgM_outFontStickAnimePiece(J2DPicture *param_1,J2DPicture *param_2,short param_3,short param_4);
void fopMsgM_outFontStickAnimePiece(J2DPicture *param_1,short param_2,short param_3);
}

namespace f_op_msg_mng {
void fopMsgM_outFontStickAnime(int *param_1,int *param_2,int *param_3,int *param_4,int param_5,short *param_6);
void fopMsgM_outFontStickAnime(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,short *param_6);
void fopMsgM_outFontStickAnime2(int *param_1,int *param_2,int *param_3,int *param_4,int param_5,short *param_6,char param_7);
void fopMsgM_outFontStickAnime2(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,short *param_6,char param_7);
void fopMsgM_outFontStickAnime(int *param_1,int *param_2,int *param_3,int *param_4,int param_5,short *param_6,byte param_7);
void fopMsgM_outFontStickAnime(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,short *param_6,byte param_7);
void fopMsgM_outFontArrow(int *param_1,int *param_2,int *param_3,int *param_4,int param_5,char param_6);
void fopMsgM_outFontArrow(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,char param_6);
void fopMsgM_outFontDraw(J2DPicture *param_1,J2DPicture *param_2,uint param_3,int param_4,uint param_5,undefined4 param_6,byte param_7,uint param_8);
void fopMsgM_outFontDraw2(int *param_1,int *param_2,uint param_3,uint param_4,uint param_5,uint param_6,undefined4 param_7,undefined param_8,undefined param_9);
void fopMsgM_Create(short param_1,undefined *param_2,void *param_3);
}

namespace f_op_msg_mng {
byte dComIfGs_getClearCount(void);
int dComIfGs_getEventReg(ushort param_1);
int dComIfGp_getItemNameMessageID(void);
int dComIfGp_getNpcNameMessageID(void);
byte dComIfGs_getPalLanguage(void);
char * dComIfGs_getPlayerName(void);
}

namespace f_op_msg_mng {
void fopMsgM_arrowAnime(int param_1,short *param_2);
}

namespace f_op_msg_mng {
void dComIfGp_setMesgAnimeTagInfo(byte param_1);
void dComIfGp_setMesgCameraTagInfo(int param_1);
}

namespace f_op_msg_mng {
void mDoAud_messageSePlay(ushort param_1,Vec *param_2,char param_3);
int dComIfGp_roomControl_getStayNo(void);
undefined fopMsgM_itemNumIdx(uint param_1);
uint fopMsgM_itemNum(char param_1);
undefined4 fopMsgM_getColorTable(uint param_1);
void fopMsgM_int_to_char(char *param_1,int param_2,char param_3);
void fopMsgM_int_to_char2(char *param_1,int param_2);
}

namespace f_op_msg_mng {
undefined8 fopMsgM_centerPosCalc(cXy *param_1,cXy *param_2);
void fopMsgM_pane_parts_set(fopMsgM_pane_class *this);
void fopMsgM_pane_parts_set(int *param_1);
void fopMsgM_setPaneData(fopMsgM_pane_class *param_1,J2DScreen *param_2);
void fopMsgM_setPaneData(fopMsgM_pane_class *pPane,J2DScreen *pScreen,int fourcc);
void fopMsgM_setPaneData(fopMsgM_pane_class *this,J2DScreen *pData);
void fopMsgM_setPaneData(int *param_1,int *param_2,undefined4 param_3);
void fopMsgM_paneTrans(fopMsgM_pane_class *param_1,double x,double y);
void fopMsgM_paneScaleX(double param_1,fopMsgM_pane_class *param_2);
void fopMsgM_paneScaleY(double param_1,fopMsgM_pane_class *param_2);
void fopMsgM_paneScale(double param_1,double param_2,fopMsgM_pane_class *param_3);
void fopMsgM_paneScaleXY(fopMsgM_pane_class *param_1,float param_2);
void fopMsgM_cposMove(fopMsgM_pane_class *this);
void fopMsgM_setAlpha(fopMsgM_pane_class *param_1);
void fopMsgM_setInitAlpha(int param_1);
void fopMsgM_setNowAlpha(fopMsgM_pane_class *this,float alpha);
void fopMsgM_setNowAlphaZero(fopMsgM_pane_class *param_1);
void fopMsgM_setAlpha(int *param_1);
void fopMsgM_setNowAlpha(double param_1,int param_2);
double fopMsgM_valueIncrease(uint param_1,uint param_2,byte param_3);
void fopMsgM_blendInit(fopMsgM_pane_class *param_1,char *param_2);
void fopMsgM_blendInit(J2DPicture *param_1,char *param_2);
void fopMsgM_blendDraw(J2DPicture **param_1,char *param_2);
void fopMsgM_blendDraw(J2DPicture *pPic,char *param_2);
void fopMsgM_setFontsizeCenter(char *param_1,char *param_2,char *param_3,char *param_4,int param_5,int param_6);
void fopMsgM_setFontsizeCenter2(char *param_1,char *param_2,char *param_3,char *param_4,undefined4 param_5,undefined4 param_6);
JKRHeap * fopMsgM_createExpHeap(ulong param_1);
void fopMsgM_destroyExpHeap(JKRHeap *param_1);
}

namespace f_op_msg_mng {
void __sinit_f_op_msg_mng_cpp(void);
}
