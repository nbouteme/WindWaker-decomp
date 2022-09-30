#pragma once

#include <dolphin/gx.h>
#include <doltypes.h>

struct J3DSys {
	void reinitTexture();
	void drawInit();
	void setTexCacheRegion(gx::GXTexCacheSize param_1);
};

namespace J3DGraphBase {
	using MTX34 = float[3][4];
	extern J3DSys j3dSys;
	extern MTX34 j3dIdentityMtx;
	extern void *NullTexData;
	extern byte j3dDefaultTexCoordInfo[];
}