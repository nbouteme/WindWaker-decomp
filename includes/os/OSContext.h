#pragma once
#include <ctypes.h>



namespace os {
undefined8 __OSLoadFPUContext(undefined8 param_1,undefined4 param_2,int param_3);
void __OSSaveFPUContext(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,undefined4 param_14,undefined4 param_15,int param_16);
void OSSaveFPUContext(undefined4 param_1,undefined4 param_2);
void OSSetCurrentContext(uint param_1);
undefined4 OSGetCurrentContext(void);
undefined4 OSSaveContext(int param_1);
undefined8 OSLoadContext(int param_1);
undefined * OSGetStackPointer(void);
void OSClearContext(int param_1);
void OSInitContext(int param_1,undefined4 param_2,undefined4 param_3);
void OSDumpContext(undefined4 *param_1);
undefined8 OSSwitchFPUContext(undefined4 param_1,int param_2);
void __OSContextInit(void);
void OSFillFPUContext(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined8 param_9,undefined8 param_10,undefined8 param_11,undefined8 param_12,undefined8 param_13,int param_14);
}
