#pragma once

#include "../../dolphin/os.h"
#include "./JKRDisposer.h"
#include "./JKRHeap.h"

struct JKRThread : public JKRDisposer {
	static JSUPtrList sThreadList;
	JSUPtrLink threadlink;
	JKRHeap *heap;
	os::OSThread *thread;
	os::OSMessageQueue msgqueue;
	os::OSMessage *msgarray;
	int msgcount;
	void *stackbase;
	int stacksize;
	JKRHeap *newheap;
	uint field10_0x64;
	int padd[2];

	JKRThread(os::OSThread *thread, int mode);
	virtual ~JKRThread();

	JKRThread(ulong param_1, int msgcount, int priority);

	static void *start(void *up);

	virtual void *run();
};