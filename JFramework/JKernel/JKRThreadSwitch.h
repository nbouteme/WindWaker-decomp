#pragma once

#include "../../dolphin/os.h"
#include "../../machine/dolphin/printf.h"
#include "../JUtility/JUTAssert.h"
#include "JKRHeap.h"
#include "JKRThread.h"
#include "JKernel.h"

struct JKRThreadSwitch {
	JKRHeap *heap;
	int state;

	static void (*mUserPreCallback)(os::OSThread *param_1, os::OSThread *param_2);
	static void (*mUserPostCallback)(os::OSThread *param_1, os::OSThread *param_2);

	static void callback(os::OSThread *param_1, os::OSThread *param_2);

	JKRThreadSwitch(JKRHeap *param_1) ;

	static JKRThreadSwitch *sManager;
	static JKRThreadSwitch *createManager(JKRHeap *param_1) ;
};