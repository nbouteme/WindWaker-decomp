#pragma once

#include <dolphin/gx.h>
#include <doltypes.h>

struct JUTGraphFifo {
	static char sInitiated;
	static JUTGraphFifo *sCurrentFifo;

	int fifosize;
	void *fifobuffer;
	gx::GXFifoObj *gxFifoObj;

	struct {
		gx::GXBool overhi, underlow, readIdle, cmdIdle, brkpt;

	} mGpStatus;

	JUTGraphFifo(ulong param_1);

	~JUTGraphFifo();
};
