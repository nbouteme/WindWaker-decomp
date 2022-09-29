#pragma once

#include <dolphin/os/OSThread.h>

struct OSMutex {
	os::OSThreadQueue queue;
	os::OSThread* thread;  // the current owner
	s32 count;			   // lock count
	os::OSMutexLink link;  // for OSThread.queueMutex
};

struct OSCond {
	os::OSThreadQueue queue;
};

void OSInitMutex(OSMutex* mutex);
void OSLockMutex(OSMutex* mutex);
void OSUnlockMutex(OSMutex* mutex);
BOOL OSTryLockMutex(OSMutex* mutex);
void OSInitCond(OSCond* cond);
void OSWaitCond(OSCond* cond, OSMutex* mutex);
void OSSignalCond(OSCond* cond);
