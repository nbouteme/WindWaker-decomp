#pragma once

#include <dolphin/os/OSThread.h>

typedef struct OSSemaphore {
	s32 count;
	os::OSThreadQueue queue;
} OSSemaphore;

void OSInitSemaphore(OSSemaphore* sem, s32 count);
s32 OSWaitSemaphore(OSSemaphore* sem);
s32 OSTryWaitSemaphore(OSSemaphore* sem);
s32 OSSignalSemaphore(OSSemaphore* sem);
s32 OSGetSemaphoreCount(OSSemaphore* sem);
