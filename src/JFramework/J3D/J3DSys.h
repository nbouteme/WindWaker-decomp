#pragma once

#include <dolphin/gx.h>
#include <dolphin/mtx.h>
#include <doltypes.h>

struct J3DSys {
	mtx::Mtx mCurViewMtx;
	int mCurDrawMode; // write only?
	void reinitTexture();
	void drawInit();
	void setTexCacheRegion(gx::GXTexCacheSize param_1);

	void reinitGenMode();
	void reinitLighting();
	void reinitTransform();
	void reinitTevStages();
	void reinitIndStages();
	void reinitPixelProc();

	void reinitGX();
};

namespace J3DGraphBase {
	using MTX34 = float[3][4];
	extern J3DSys j3dSys;
	extern MTX34 j3dIdentityMtx;
	extern void *NullTexData;
	extern byte j3dDefaultTexCoordInfo[];
}