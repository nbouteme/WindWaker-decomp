#pragma once
#include <ctypes.h>

#include <overlap_request_class.h>


namespace f_op_overlap_mng {
//[Data] Expected size is 0x000004
extern struct overlap_request_class * l_fopOvlpM_overlap;

//[BSS] Expected size is 0x000028
extern struct overlap_request_class l_fopOvlpM_Request;
undefined4 fopOvlpM_SceneIsStop(void);
undefined4 fopOvlpM_SceneIsStart(void);
uint fopOvlpM_IsOutReq(int param_1);
void fopOvlpM_Done(int param_1);
void fopOvlpM_ToldAboutID(undefined4 param_1);
undefined * fopOvlpM_IsPeek(void);
undefined4 fopOvlpM_IsDone(void);
int fopOvlpM_IsDoingReq(void);
undefined4 fopOvlpM_ClearOfReq(void);
void fopOvlpM_Request(short param_1,ushort param_2);
void fopOvlpM_Management(void);
undefined4 fopOvlpM_Cancel(void);
void fopOvlpM_Init(void);
}
