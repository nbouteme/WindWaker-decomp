#pragma once
#include <ctypes.h>



namespace os {
void OSInitMutex(OSMutex *param_1);
void OSLockMutex(OSMutex *param_1);
void OSUnlockMutex(int param_1);
void __OSUnlockAllMutex(int param_1);
undefined4 OSTryLockMutex(int param_1);
void OSInitCond(void);
void OSWaitCond(undefined4 param_1,OSMutex *param_2);
void OSSignalCond(void);
undefined4 __OSCheckMutex(int *param_1);
undefined4 __OSCheckDeadLock(int param_1);
undefined4 __OSCheckMutexes(int param_1);
}
