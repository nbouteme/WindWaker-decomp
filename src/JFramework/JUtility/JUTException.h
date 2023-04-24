#pragma once

#include <dolphin/base.h>

#include <cstring>

#include "../JKernel/JKRThread.h"
#include "../JSupport/JSUPtrLink.h"

struct JUTDirectPrint;
struct JUTGamePad;
struct JUTConsole;

struct JUTException : public JKRThread {
	using usercallback = void(void);

	static usercallback *sPreUserCallback;
	static usercallback *sPostUserCallback;
	static void waitTime(u32 time);

	static u32 msr, fpscr;
	static os::OSMessageQueue sMessageQueue;
	static JSUPtrList sMapFileList;
	static os::OSTime c3bcnt[4];
	static JUTException *sErrorManager;
	static void *sConsoleBuffer;
	static int sConsoleBufferSize;
	static JUTConsole *sConsole;

	JUTGamePad *padidx;
	int padidx2;
	JUTDirectPrint *field2_0x6c;
	int field5_0x78;
	int field6_0x7c;
	int field7_0x80;
	int field8_0x84;
	int field9_0x88;

	static usercallback *setPreUserCallback(usercallback *param_1);
	static usercallback *setPostUserCallback(usercallback *param_1);
	static void errorHandler(os::OSError param_1, os::OSContext *param_2, ulong param_3, ulong param_4);
	static void setFPException(ulong param_1);
	static void appendMapFile(const char *param_1);
	static JUTException *create(JUTDirectPrint *param_1);
	static void createConsole(void *buffer, ulong objectSize);

	JUTException(JUTDirectPrint *param_1);
};