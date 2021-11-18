#pragma once
#include <ctypes.h>


//[BSS] Expected size is 0x000004
extern struct JUTDbPrint * JUTDbPrint;

namespace JUTDbPrint {
JUTDbPrint * start(JUTFont *param_1,JKRHeap *param_2);
}

namespace JUtility {
void JUTReport(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,int param_9,int param_10,char *param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16);
void JUTReport(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,int param_9,int param_10,int param_11,char *param_12,undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16);
}
