#pragma once

#include <machine/dolphin/dvd.h>
#include <cstdio>

struct J3DModelData;
struct J3DMaterialAnm;
struct cBgD__Tree_t;
struct mDoExt_transAnmBas;
struct J3DMaterial;
struct J3DMaterialTable;
struct J3DDisplayListObj;

// Note: Res* objects are usually loaded from files directly into these structures
// so their member integer types are expected to be in big endian

struct ResNTABEntry {
	be_u16 hash, stroffset;
};

struct ResNTAB {
	be_s16 mCount;
	ResNTABEntry mEntries[1];  // Flexible Array Meme
};

struct ResTIMG {
	gx::GXTexFmt mTexFmt;
	byte mTranslucency;
	be_u16 mWidth;
	be_u16 mHeight;
	gx::GXTexWrapMode mWrapS;
	gx::GXTexWrapMode mWrapT;
	byte mbHasTlut;
	gx::GXTlutFmt mTlutFmt;
	be_s16 mTlutCount;
	be_s32 mTlutDataOffs;
	byte mbMipmapEnabled;
	byte mbDoEdgeLOD;
	byte mbBiasClamp;
	gx::GXAnisotropy mMaxAniso;
	gx::GXTexFilter mMinFilter;
	gx::GXTexFilter mMagFilter;
	byte mbMinLOD;
	byte mbMaxLOD;
	byte mbMipmapCount;
	byte unk1;
	be_s16 mLODBias;
	be_s32 mTexDataOffs;
};

struct J3DTexture;
struct J3DTevBlock;

namespace d_resorce {
	extern char l_readResType$4166[];
	void setToonTex(J3DModelData *pModel);
}

struct dRes_info_c {
	char mName[14];
	short mRefCount;
	mDoDvdThd_mountArchive_c *mpDvdThdCommand;
	JKRArchive *mpArchive;
	JKRHeap *mpParentHeap, *mpDataHeap;
	void *mpRes;

	int loadResource();

	int setRes();

	bool set(char *param_1, char *param_2, uchar param_3, JKRHeap *param_4);
};

// should be a namespace?
struct dRes_control_c {
	dRes_info_c mObjectInfo[64];

	void dump();

	static dRes_info_c *getResInfoLoaded(char *arcName, dRes_info_c *resInfosList, int totalResInfos);
	static int deleteRes(char *pName, dRes_info_c *pResInfoList, int count);
	static uint syncRes(char *param_1, dRes_info_c *param_2, int param_3);
	static void *getRes(char *arcName, long fileIndex, dRes_info_c *resInfosList, int totalResInfos);
	static void *getRes(char *param_1, char *param_2, dRes_info_c *param_3, int param_4);
	static int syncAllRes(dRes_info_c *param_1, int param_2);
	static dRes_info_c *getResInfo(char *pArcName, dRes_info_c *pResInfoList, int count);
	static dRes_info_c *newResInfo(dRes_info_c *param_1, int param_2);
	static int setRes(char *param_1, dRes_info_c *param_2, int param_3, char *param_4, byte param_5, JKRHeap *param_6);
};