#pragma once
#include <ctypes.h>



namespace TRK_MINNOW_DOLPHIN {
//[BSS] Expected size is 0x0019b0
extern undefined gTRKMsgBufs;
void TRKReadBuffer_ui32(int param_1,undefined *param_2,int param_3);
void TRKReadBuffer_ui8(int param_1,int param_2,int param_3);
int TRKReadBuffer1_ui64(int param_1,undefined *param_2);
int TRKReadBuffer1_ui32(int param_1,undefined *param_2);
int TRKReadBuffer1_ui16(int param_1,undefined *param_2);
undefined4 TRKReadBuffer1_ui8(int param_1,undefined4 param_2);
void TRKAppendBuffer_ui32(undefined4 param_1,undefined4 *param_2,int param_3);
int TRKAppendBuffer_ui8(int param_1,undefined *param_2,int param_3);
void TRKAppendBuffer1_ui64(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4);
void TRKAppendBuffer1_ui32(undefined4 param_1,undefined4 param_2);
void TRKAppendBuffer1_ui16(undefined4 param_1,undefined2 param_2);
undefined4 TRKReadBuffer(int param_1,undefined4 param_2,uint param_3);
undefined4 TRKAppendBuffer(int param_1,undefined *param_2,uint param_3);
undefined4 TRKSetBufferPosition(int param_1,uint param_2);
void TRKResetBuffer(int param_1,char param_2);
void TRKReleaseBuffer(int param_1);
undefined * TRKGetBuffer(int param_1);
int TRKGetFreeBuffer(int *param_1,undefined4 *param_2);
undefined4 TRKInitializeMessageBuffers(void);
}
