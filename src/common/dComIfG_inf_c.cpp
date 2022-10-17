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

	void dComIfGp_setNextStage(char *pStageName, short startCode, byte roomIdx, byte layerNo, float param_5, uint mode,
							   int param_7, byte wipeType)

	{
		uint uVar1;
		double dVar2;

		dVar2 = (double)param_5;
		d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.set(pStageName, roomIdx, startCode, layerNo, wipeType);

		//// remove link control?
		//if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor != (daPy_lk_c *)0x0) {
		//	uVar1 = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).field9_0x2a0;
		//	if ((uVar1 & 1) != 0) {
		//		mode = mode | 0x8000;
		//	}
		//	mode = mode | (int)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->field680_0x354e << 0x10;
		//	if ((uVar1 & 0x8000) != 0) {
		//		mode = mode | 0x4000;
		//	}
		//}
		if (param_7 != 0) {	 // if is restarting?
			d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mStartCode = startCode;
		}
		d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.field89_0x1150 = (float)dVar2;
		d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMode = mode;
		return;
	}

	int dComIfG_changeOpeningScene(scene_class *pScene, int procName) {
		g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext = 0;
		dComIfGp_setNextStage("sea_T", 0, 0x2c, 0, 0.0, 0, 1, 0);
		m_Do_audio::mDoAud_setSceneName(g_dComIfG_gameInfo.mPlay.mNextStage.mStageName,
										g_dComIfG_gameInfo.mPlay.mNextStage.mStartCode,
										g_dComIfG_gameInfo.mPlay.mNextStage.mLayerNo);
		g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartParameters = 0;
		f_op_scene_mng::fopScnM_ChangeReq(pScene, procName, 0, 0x1e);
		f_op_scene_mng::fopScnM_ReRequest(procName, 0);
		return 1;
	}
}

void dStage_startStage_c::set(char *param_1, char spawnID, short param_3, char param_4) {
	strcpy(this->mStageName, param_1);
	this->mStartCode = spawnID;
	this->mRoomNo = param_3;
	this->mLayerNo = param_4;
}

void dStage_nextStage_c::set(char *param_1, char startCode, short roomIdx, char layerNo,
							 char wipeType) {
	if (this->mbHasNext == 0) {
		this->mbHasNext = 1;
		this->mWipeType = wipeType;
		dStage_startStage_c::set(param_1, startCode, roomIdx, layerNo);
	}
}

void dComIfG_play_c::createParticle() {
	this->mParticleCtrl = new dPa_control_c();
	if (!this->mParticleCtrl) {
		auto uVar1 = JUTAssertion::getSDevice();
		JUTAssertion::showAssert(uVar1, "d_com_inf_game.cpp", 0x168, "mParticle != 0");
		m_Do_printf::OSPanic("d_com_inf_game.cpp", 0x168, "Halt");
	}
}