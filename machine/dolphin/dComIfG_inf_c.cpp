#include "dComIfG_inf_c.h"

void dComIfG_play_c::init() {
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

void dComIfG_play_c::ct() {
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

void dComIfG_inf_c::ct() {
	mPlay.ct();
}

namespace d_com_inf_game {
	dComIfG_inf_c g_dComIfG_gameInfo;
	gx::GXColor g_clearColor;
}