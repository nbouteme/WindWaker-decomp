#pragma once
#include <ctypes.h>



namespace TRK_MINNOW_DOLPHIN {
int HandlePositionFileSupportRequest(undefined4 param_1,undefined4 *param_2,undefined param_3,undefined *param_4);
int HandleCloseFileSupportRequest(undefined4 param_1,undefined *param_2);
int HandleOpenFileSupportRequest(char *param_1,undefined param_2,undefined4 *param_3,undefined *param_4);
int TRKRequestSend(undefined4 param_1,int *param_2,uint param_3,int param_4,int param_5);
int TRKSuppAccessFile(int param_1,int param_2,uint *param_3,char *param_4,int param_5,int param_6);
}
