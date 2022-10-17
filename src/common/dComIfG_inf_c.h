#pragma once

#include <JFramework/J2DGraph/J2DOrthoGraph.h>
#include <common/dDlst.h>
#include <d_resorce.h>
#include <machine/dolphin/mDoAud.h>

struct cXyz {
	float x, y, z;
};

struct JPABaseEmitter;

struct dPa_simpleData_c {
	TVec3<float> mPos;
	gx::GXColor mPrmColor;
	byte mEnvColor[3];
	byte mbAffectedByWind;
};

struct dPa_simpleEcallBack {
	JPABaseEmitter *mpBaseEmitter;
	ushort mResID;
	uchar mGrpID;
	byte mbIsSmoke;
	short mCount;
	dPa_simpleData_c mSimpleData[32];

	virtual ~dPa_simpleEcallBack() {}
};

struct JPADynamicsBlockArc;	 // TODO
struct JPABaseShapeArc;		 // TODO
struct JPAExtraShapeArc;	 // TODO
struct JPASweepShapeArc;	 // TODO
struct JPAExTexShapeArc;	 // TODO
struct JPAKeyBlockArc;		 // TODO
struct JPAFieldBlockArc;	 // TODO

struct JPADataBlockLinkInfo {
	JPADynamicsBlockArc *mpDynamicsBlock;
	JPABaseShapeArc *mpBaseShapeBlock;
	JPAExtraShapeArc *mpExtraShapeBlock;
	JPASweepShapeArc *mpSweepShapeBlock;
	JPAExTexShapeArc *mpExTexShapeBlock;
	JPAKeyBlockArc **mpKeyBlocks;
	JPAFieldBlockArc **mpFldBlocks;
	int *mpTDB1;
	byte mFldNum;
	byte mTextureNum;
	byte mKeyNum;
};

struct JPAEmitterData {
	JPADataBlockLinkInfo *mpLinkInfoArray;
	short mLinkInfoCount;
	short mUserIndex;
};

struct JPAEmitterResource {
	int mpEmitterNum;
	int mpEmitterCapacity;
	JPAEmitterData **mpEmitterDataArray;
};

struct JPATextureResource;	// TODO

struct JPAResourceManager {
	JKRHeap *mpHeap;
	JPAEmitterResource *mpEmitterResource;
	JPATextureResource *mpTextureResource;
};

struct dPa_modelControl_c {
	node_list_class list;
};

struct dPa_control_c {
	JKRHeap *mpHeap;
	JPAResourceManager *mpCommonResMgr;
	dPa_modelControl_c *mModelCtrl;
	JKRHeap *mpSceneHeap;
	void *mpData;
	JPAResourceManager *mpSceneResMgr;
	uchar mSceneNo;
	byte mCount;
	byte mNumSimple;
	byte mNumSimpleCommon;
	dPa_simpleEcallBack mSimpleCallbacks[25];

	void createCommon(JKRArchive__Header *param_1) {
		// TODO
	}
};

struct FmapChkPnt {
	char mSectorX;
	char mSectorY;
	char __unk[6];
};

struct FmapData {
	int mNumSectors;
	FmapChkPnt mSectors[49];
};

struct dStage_startStage_c {
	char mStageName[8];
	short mRoomNo;
	char mStartCode;
	byte mLayerNo;

	void set(char *param_1, char spawnID, short param_3, char param_4);
};

struct dStage_nextStage_c : dStage_startStage_c {
	byte mbHasNext;
	byte mWipeType;

	void set(char *param_1, char startCode, short roomIdx, char layerNo,
			 char wipeType);
};

struct dComIfG_play_c {
	void *mpCurPlayerActor[1];
	byte mCurCamera;
	struct J2DOrthoGraph *mp2DOrthoGraph;
	JKRAramBlock *bigAramRegion[3];
	JKRAramBlock *smallAramRegion[4];
	dStage_nextStage_c mNextStage;
	int pictureStatus;

	JKRArchive *mpAnmArchive;
	JKRArchive *mpFMapArchive;
	JKRArchive *mpItemResArchive;
	JKRArchive *mpFMapResArchive;
	JKRArchive *mpDMapResArchive;
	JKRArchive *mpClctResArchive;
	JKRArchive *mpOptResArchive;
	JKRArchive *mpSaveResArchive;
	JKRArchive *mpClothResArchive;
	JKRArchive *mpItemIconArchive;
	JKRArchive *mpActionIconArchive;
	JKRArchive *mpScopeResArchive;
	JKRArchive *mpCamResArchive;
	JKRArchive *mpSwimResArchive;
	JKRArchive *mpWindResArchive;
	JKRArchive *mpNameResArchive;
	JKRArchive *mpTmsgArchive;
	JKRArchive *mpDmsgArchive;
	JKRArchive *mpErrorResArchive;
	JKRArchive *mpEnglishTextArchive;
	JKRArchive *mpHyruleTextArchive;
	JKRArchive *mpMsgArchive;
	JKRArchive *mpMenuArchive;
	JKRArchive *mpFontArchive;

	void init();

	dPa_control_c *mParticleCtrl;
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

	void createParticle();

	void ct();
};

struct dSv_event_c {
	byte mBits[256];
};

struct dSv_save_c {
	dSv_event_c mEvent;
};

struct dSv_restart_c {
	int mStartCode;
	int mLinkRestartParameters;
};

struct dSv_info_c {
	dSv_save_c mSave;
	dSv_restart_c mRestart;
	uint mMode;
	float field89_0x1150;
};

struct dComIfG_inf_c {
	dSv_info_c mSvInfo;
	byte field135_0x1d1c1 = 0xff;
	dRes_control_c mResCtrl;
	dComIfG_play_c mPlay;
	dDlst_list_c mDlstList;
	int maybeCurrentSelectedFile;
	byte pictureStatus;

	void ct();
};

#include <f_op/scene.h>

namespace d_com_inf_game {
	extern dComIfG_inf_c g_dComIfG_gameInfo;
	extern gx::GXColor g_clearColor;

	void dComIfGp_setNextStage(char *pStageName, short startCode, byte roomIdx, byte layerNo, float param_5, uint mode,
							   int param_7, byte wipeType);

	int dComIfG_changeOpeningScene(scene_class *pScene, int procName);
}