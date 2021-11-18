#pragma once
#include <ctypes.h>



namespace m_Do_printf {
//[Data] Expected size is 0x000001
extern undefined1 print_callerPCLevel;

//[BSS] Expected size is 0x000001
extern undefined1 __OSReport_disable;
//[BSS] Expected size is 0x000001
extern undefined1 __OSReport_Error_disable;
//[BSS] Expected size is 0x000001
extern undefined1 __OSReport_Warning_disable;
//[BSS] Expected size is 0x000001
extern undefined1 __OSReport_enable;
//[BSS] Expected size is 0x000004
extern undefined4 __OSReport_MonopolyThread;
//[BSS] Expected size is 0x000001
extern undefined1 print_threadID;
//[BSS] Expected size is 0x000001
extern undefined1 print_callerPC;
//[BSS] Expected size is 0x000004
extern undefined4 print_counts;
//[BSS] Expected size is 0x000004
extern undefined4 print_errors;
//[BSS] Expected size is 0x000004
extern undefined4 print_warings;
//[BSS] Expected size is 0x000001
extern undefined1 print_initialized;
undefined4 OSGetCallerPC(int param_1);
int OSGetActiveThreadID(int param_1);
undefined4 search_partial_address(uint param_1,undefined4 *param_2,int *param_3,int *param_4,undefined4 *param_5);
int convert_partial_address(int param_1);
void OSReportDisable(void);
void OSReportEnable(void);
void OSReportForceEnableOn(void);
void OSReportForceEnableOff(void);
void OSReportInit(void);
void OSVReport(char *param_1,__gnuc_va_list param_2);
void OSReport(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16);
void OSReport_FatalError(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16);
void OSReport_Error(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16);
void OSReport_Warning(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16);
void OSPanic(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined4 param_9,undefined4 param_10,char *param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16);
}
