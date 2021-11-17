#pragma once
#include <ctypes.h>



namespace dvd {
//Expected size is 0x000020
extern undefined4 WaitingQueue;

void __DVDClearWaitingQueue(void);
undefined4 __DVDPushWaitingQueue(int param_1,undefined4 *param_2);
int ** __DVDPopWaitingQueue(void);
undefined4 __DVDCheckWaitingQueue(void);
undefined4 __DVDDequeueWaitingQueue(int *param_1);
}
