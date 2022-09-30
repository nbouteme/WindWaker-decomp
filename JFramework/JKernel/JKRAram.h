#pragma once

#include <dolphin/ar.h>
#include <dolphin/os.h>

#include "../JSupport/JSUIosBase.h"
#include "JKRAramHeap.h"
#include "JKRDecomp.h"

struct JKRAramStreamCommand {
	uint direction;
	uint dest;
	uint remaining;
	uint bepis;
	JSURandomInputStream *inputstream;
	uint currentOffset;
	void *buffadr;
	uint size;
	JKRHeap *heap;
	byte fullfilled;
	uint stat;
	os::OSMessageQueue mqueue;
	os::OSMessage msgs[1];
	uint bepis2, bepis3;

	JKRAramStreamCommand();
};

struct JKRAramStream : public JKRThread {
	static JKRAramStream *sAramStreamObject;
	static void *transBuffer;
	static uint transSize;
	static JKRHeap *transHeap;
	static os::OSMessageQueue sMessageQueue;
	static os::OSMessage sMessageBuffer[4];

	static JKRAramStreamCommand *JKRAramStream::write_StreamToAram_Async(JSUFileInputStream *param_1, ulong param_2, ulong param_3, ulong param_4);
	static void setTransBuffer(byte *param_1, ulong param_2, JKRHeap *param_3);
	static int readFromAram();
	static int JKRAramStream::writeToAram(JKRAramStreamCommand *param_1);
	static void sync(JKRAramStreamCommand *param_1, int param_2);
	static JKRAramStream *create(int param_1);

	virtual void *run(void *);

	JKRAramStream(uint p);
};

struct JKRAram : public JKRThread {
	static JKRAram *sAramObject;
	static JSUPtrList sAramCommandList;
	static os::OSMessageQueue sMessageQueue;

	u32 audioAreaSize, graphAreaSize, userAreaSize;
	undefined4 audioArea, graphArea, userArea;

	JKRAramHeap *mpHeap;  // shadows JKRThread's
	uint stackbase;		  // shadows JKRThread's

	static int sSzpBufferSize;

	static JKRAram *create(ulong param_1, ulong param_2, long param_3, long param_4, long param_5);
	static undefined4 checkOkAddress(byte *param_1, ulong param_2, JKRAramBlock *param_3, ulong param_4);
	static void changeGroupIdIfNeed(byte *param_1, int param_2);

	virtual ~JKRAram();
	JKRAram(unsigned param_1, unsigned param_2, unsigned param_3);
};