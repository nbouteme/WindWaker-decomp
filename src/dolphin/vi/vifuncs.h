#pragma once

#include <dolphin/gx/GXStruct.h>  // for GXRenderModeObj structure
#include <dolphin/types.h>
#include <dolphin/vi/vitypes.h>

namespace vi {

#define VIPadFrameBufferWidth(width) ((u16)(((u16)(width) + 15) & ~15))

	void VIInit(void);
	void VIFlush(void);
	void VIWaitForRetrace(void);

	void VIConfigure(const gx::GXRenderModeObj *rm);
	void VIConfigurePan(u16 PanPosX, u16 PanPosY,
						u16 PanSizeX, u16 PanSizeY);
	void VISetNextFrameBuffer(void *fb);

	void *VIGetNextFrameBuffer(void);
	void *VIGetCurrentFrameBuffer(void);

	VIRetraceCallback VISetPreRetraceCallback(VIRetraceCallback callback);
	VIRetraceCallback VISetPostRetraceCallback(VIRetraceCallback callback);

	void VISetBlack(BOOL black);
	u32 VIGetRetraceCount(void);
	u32 VIGetNextField(void);
	u32 VIGetCurrentLine(void);
	u32 VIGetTvFormat(void);
	u32 VIGetScanMode(void);

	u32 VIGetDTVStatus(void);
}