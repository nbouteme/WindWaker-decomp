#pragma once

#include <dDlst.h>
#include <d_resorce.h>
#include <J2DGraph/J2DOrthoGraph.h>

struct cXyz {
	float x, y, z;
};

struct dComIfG_play_c {
	void *mpCurPlayerActor[1];
	byte mCurCamera;
	struct J2DOrthoGraph *mp2DOrthoGraph;

	void init() {
		int iVar1;
		int iVar2;

		this->mpCurPlayerActor[0] = nullptr;
		this->mCurCamera = 0xff;
		iVar1 = 0;
		iVar2 = 3;
		do {
			this->mpCurPlayerActor[iVar1 + 2] = nullptr;
			iVar1++;
			iVar2--;
		} while (iVar2 != 0);
	}

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

	void ct() {
		this->field69_0x4841 = 0;
		this->mParticleCtrl = nullptr;
		this->mpDemoMgr = nullptr;
		this->mpMagmaPacket = nullptr;
		this->mpGrassPacket = nullptr;
		this->mpTreePacket = nullptr;
		this->mpWoodPacket = nullptr;
		this->mpFlowerPacket = nullptr;
		this->field455_0x4a64 = 0xff;
		this->field456_0x4a65 = 0xff;
		this->mLastSeaRoom = 0xff;
		this->field458_0x4a67 = 0xff;
		(this->mIkadaLinkPos).x = 0.0;
		(this->mIkadaLinkPos).y = 0.0;
		(this->mIkadaLinkPos).z = 0.0;
		this->mLkDArcIdx = 0xff;
		init();
	}
};

struct dComIfG_inf_c {
	byte field135_0x1d1c1 = 0xff;
	dRes_control_c mResCtrl;
	dComIfG_play_c mPlay;
	dDlst_list_c mDlstList;
	int maybeCurrentSelectedFile;
	byte pictureStatus;
	

	void ct() {
		mPlay.ct();
	}
};

namespace d_com_inf_game {
	dComIfG_inf_c g_dComIfG_gameInfo;
	gx::GXColor g_clearColor;
}