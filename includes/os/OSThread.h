#pragma once
#include <ctypes.h>



namespace os {
//Expected size is 0x000100
extern undefined4 RunQueue;

//Expected size is 0x000318
extern undefined IdleThread;

//Expected size is 0x000318
extern undefined DefaultThread;

//Expected size is 0x0002c8
extern undefined IdleContext;

//Expected size is 0x000004
extern undefined4 RunQueueBits;

//Expected size is 0x000004
extern undefined4 RunQueueHint;

//Expected size is 0x000004
extern undefined4 Reschedule;

void DefaultSwitchThreadCallback(void);
code * OSSetSwitchThreadCallback(code *param_1);
void __OSThreadInit(void);
void OSInitThreadQueue(undefined4 *param_1);
undefined4 OSGetCurrentThread(void);
undefined4 OSIsThreadTerminated(int param_1);
int OSDisableScheduler(void);
int OSEnableScheduler(void);
void UnsetRun(int param_1);
int __OSGetEffectivePriority(int param_1);
undefined4 SetEffectivePriority(int param_1,undefined4 param_2);
void __OSPromoteThread(int param_1,int param_2);
int SelectThread(int param_1);
void __OSReschedule(void);
void OSYieldThread(void);
undefined4 OSCreateThread(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,int param_6,ushort param_7);
void OSExitThread(undefined4 param_1);
void OSCancelThread(int param_1);
undefined4 OSJoinThread(int param_1,undefined4 *param_2);
void OSDetachThread(int param_1);
int OSResumeThread(OSThread *param_1);
int OSSuspendThread(int param_1);
void OSSleepThread(int *param_1);
void OSWakeupThread(int *param_1);
undefined4 OSSetThreadPriority(int param_1,int param_2);
undefined4 OSGetThreadPriority(int param_1);
undefined4 CheckThreadQueue(int *param_1);
int OSCheckActiveThreads(void);
void OSClearStack(uint param_1);
}
