#include <dolphin/gx.h>
#include <dolphin/vi.h>

#include <cstdio>

namespace vi {
	void VIConfigure(gx::GXRenderModeObj const*mode) {
        //
	}

	void VIInit() {
        puts("Initing VI");
	}

	void VISetNextFrameBuffer(void*) {
        //
	}

	VIRetraceCallback VISetPostRetraceCallback(VIRetraceCallback cb) {
        //
        return cb;
	}

	VIRetraceCallback VISetPreRetraceCallback(VIRetraceCallback cb) {
        //
        return cb;
	}

	uint VIGetRetraceCount() {
        //
        return 0;
	}

	void VISetBlack(bool) {
        //
	}

	void VIFlush() {
        //
	}

	void VIWaitForRetrace() {
        //
	}
}