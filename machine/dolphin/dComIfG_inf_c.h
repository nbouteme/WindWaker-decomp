#pragma once

#include <JFramework/J2DGraph/J2DOrthoGraph.h>
#include <dDlst.h>
#include <d_resorce.h>

struct cXyz {
	float x, y, z;
};

struct dComIfG_play_c {
	void *mpCurPlayerActor[1];
	byte mCurCamera;
	struct J2DOrthoGraph *mp2DOrthoGraph;

	void init();

	void *mParticleCtrl;
	void *mpDemoMgr;
	void *mpMagmaPacket;
	void *mpGrassPacket;
	void *mpTreePacket;
	void *mpWoodPacket;
	void *mpFlowerPacket;

	int field69_0x4841;
	byte field455_0x4a64, field456_0x4a65, mLastSeaRoom, field458_0x4a67;

	cXyz mIkadaLinkPos;

	byte mLkDArcIdx;

	void ct();
};

struct dComIfG_inf_c {
	byte field135_0x1d1c1 = 0xff;
	dRes_control_c mResCtrl;
	dComIfG_play_c mPlay;
	dDlst_list_c mDlstList;
	int maybeCurrentSelectedFile;
	byte pictureStatus;

	void ct();
};

namespace d_com_inf_game {
	extern dComIfG_inf_c g_dComIfG_gameInfo;
	extern gx::GXColor g_clearColor;
}