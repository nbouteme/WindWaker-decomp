#pragma once
#include <ctypes.h>

#include <MTX34.h>

//Expected size is 0x000020
extern GXTexObj mDoGph_gInf_c;

//Expected size is 0x000020
extern GXTexObj mDoGph_gInf_c;

//Expected size is 0x000030
extern struct MTX34 mDoGph_gInf_c;


namespace m_Do_graphic {
//Expected size is 0x000318
extern undefined mCaptureThread;

//Expected size is 0x000028
extern undefined mCaptureTimeOutAlarm;

}
//Expected size is 0x000004
extern struct JUTFader * mDoGph_gInf_c;

//Expected size is 0x000004
extern struct ResTIMG * mDoGph_gInf_c;

//Expected size is 0x000004
extern struct ResTIMG * mDoGph_gInf_c;

//Expected size is 0x000004
extern void * mDoGph_gInf_c;

//Expected size is 0x000001
extern undefined1 mDoGph_gInf_c;

//Expected size is 0x000001
extern undefined1 mDoGph_gInf_c;

//Expected size is 0x000001
extern undefined1 mDoGph_gInf_c;

//Expected size is 0x000001
extern byte mDoGph_gInf_c;

//Expected size is 0x000004
extern float mDoGph_gInf_c;

//Expected size is 0x000004
extern float mDoGph_gInf_c;

//Expected size is 0x000001
extern byte mDoGph_gInf_c;

//Expected size is 0x000001
extern byte mDoGph_gInf_c;

//Expected size is 0x000002
extern short mDoGph_gInf_c;

//Expected size is 0x000002
extern short mDoGph_gInf_c;


namespace m_Do_graphic {
//Expected size is 0x000001
extern undefined g_mDoGph_graphicInfo;

//Expected size is 0x000002
extern short mCaptureStep;

//Expected size is 0x000001
extern undefined1 mCaptureCansel;

//Expected size is 0x000001
extern undefined1 mCaptureEnableGXSetCopyFilter;

//Expected size is 0x000004
extern undefined4 mCaptureThreadStackHead;

//Expected size is 0x000004
extern undefined4 mCaptureCaptureBuffer;

//Expected size is 0x000004
extern undefined4 mCaptureTextureBuffer;

//Expected size is 0x000004
extern undefined4 mCaptureTextureSize;

//Expected size is 0x000004
extern undefined4 mCaptureCaptureSize;

//Expected size is 0x000004
extern undefined4 mCaptureOldCB;

//Expected size is 0x000008
extern undefined mCaptureThreadQueue;

//Expected size is 0x000008
extern undefined4 mCaptureTimeOutTicks;

}

namespace mDoGph_gInf_c {
void * alloc(ulong param_1,int param_2);
void free(void);
void fadeOut(float param_1,_GXColor *param_2);
void onBlure(void);
void onBlure(MTX34 *param_1);
void fadeOut(float param_1);
}

namespace mDoGph_gInf_c {
void onMonotone(void);
void offMonotone(void);
}

namespace m_Do_graphic {
void mDoGph_BlankingON(void);
void mDoGph_BlankingOFF(void);
void dScnPly_BeforeOfPaint(void);
undefined4 mDoGph_BeforeOfDraw(void);
undefined4 mDoGph_AfterOfDraw(void);
void clearAlphaBuffer(int param_1,byte param_2);
void drawAlphaBuffer(int param_1,_GXColor *param_2);
void drawSpot(int param_1);
void drawDepth(camera_class *pView,dDlst_window_c *pViewPort,uint param_3);
}

namespace m_Do_graphic {
void motionBlure(view_class *pView);
void mCaptureAlarmHandler(void);
void mDoGph_setCaptureStep(short param_1);
int mDoGph_getCaptureStep(void);
undefined4 mDoGph_getCaptureTextureBuffer(void);
void mDoGph_setCaptureTextureFormat(undefined param_1);
void mDoGph_setCaptureCaptureFormat(undefined param_1);
void mDoGph_CaptureCansel(void);
void blockenc(int param_1);
int encode_s3tc(int param_1,int param_2,int param_3,int param_4,int param_5);
void setUpRectangle(void);
void drawRectangle(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4);
void * mDoGph_allocFromAny(ulong param_1,int param_2);
void mDoGph_screenCaptureDraw(void);
undefined4 mCaptureProc(void);
void mCaptureGXDrawSyncCallback(void);
void mCaptureGXDrawSyncTimeOut(void);
undefined4 mDoGph_screenCapture(void);
void setLight(void);
undefined4 mDoGph_Painter(void);
}

namespace m_Do_graphic {
undefined4 mDoGph_Create(void);
void __sinit_m_Do_graphic_cpp(void);
}
