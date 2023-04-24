#pragma once

#include <dolphin/card.h>
#include <dolphin/os.h>
#include <doltypes.h>

enum card_errors {
	CARD_ERROR_READY = 0x0,
	CARD_ERROR_UNLOCKED = 0x1,
	CARD_ERROR_FATAL_ERROR = 0xffffff80,
	CARD_ERROR_CANCELED = 0xfffffff2,
	CARD_ERROR_ENCODING = 0xfffffff3,
	CARD_ERROR_NAMETOOLONG = 0xfffffff4,
	CARD_ERROR_LIMIT = 0xfffffff5,
	CARD_ERROR_NOPERM = 0xfffffff6,
	CARD_ERROR_INSSPACE = 0xfffffff7,
	CARD_ERROR_NOENT = 0xfffffff8,
	CARD_ERROR_EXIST = 0xfffffff9,
	CARD_ERROR_BROKEN = 0xfffffffa,
	CARD_ERROR_IOERROR = 0xfffffffb,
	CARD_ERROR_NOFILE = 0xfffffffc,
	CARD_ERROR_NOCARD = 0xfffffffd,
	CARD_ERROR_WRONGDEVICE = 0xfffffffe,
	CARD_ERROR_BUSY = 0xffffffff,
};

enum mDoMemCd_Ctrl_status {
	STANDBY,
	RESTORE,
	CREATE,
	FORMAT,
	READY,
	DETACH,
	ENCODING,
	ERROR,
	// missing some here
	WRONG_DEVICE = 0xa,
	IOERROR = 0xc,
};

struct card_savedata {
	byte mData[0x760];
	s32 possum, negsum;
};

struct card_savebuffer {
	uint mSaveCount;
	uint field1_0x4;
	card_savedata mSaveData[3];
	char mHeaderGameName[32];
	char mSaveInfoStr[20];
	byte unk2[968];
	uint mCheckSum;
	byte padding[0x2000 - 4 - 968 - 20 - 32 - 8 - sizeof(card_savedata) * 3];
};

namespace m_Do_MemCardRWmng {
	extern int sSaveCount;
	extern char CardSerialNo[8];
	extern card_savebuffer sTmpBuf, sTmpBuf2;

	int mDoMemCdRWm_Store(card::CARDFileInfo *pInf, byte *data, int size);
	uint mDoMemCdRWm_TestCheckSumPictData(byte *param_1);
	void mDoMemCdRWm_SetCardStat(card::CARDFileInfo *param_1);
	uint mDoMemCdRWm_CalcCheckSum(ushort *pBuf, uint size);
	void mDoMemCdRWm_BuildHeader(card_savebuffer *param_1);
	undefined4 mDoMemCdRWm_CheckCardStat(card::CARDFileInfo *file);
	undefined8 mDoMemCdRWm_CalcCheckSumGameData(byte *pData, int size);

	uint mDoMemCdRWm_TestCheckSumGameData(card_savedata *pData);
	int mDoMemCdRWm_Restore(card::CARDFileInfo *file, byte *dest, int data_length);
	int mDoMemCdRWm_CalcCheckSumPictData(byte *param_1, int param_2);
}

struct mDoMemCd_Ctrl_data {
	byte data[0x1650];
};

struct mDoMemCd_Ctrl_c {
	mDoMemCd_Ctrl_data mMemCardData;
	byte mCardSlot[4];

	int mStatus;
	mDoMemCd_Ctrl_status mNextAction;

	os::OSMutex mOSMutex;
	os::OSCond cond;

	intptr_t field1_0x1650;
	intptr_t field2_0x1654;

	void detach();
	void format();
	void command_format();
	void load();
	bool loadfile();
	undefined4 FormatSync();
	void save(void *data, uint len, uint offset);
	undefined4 SaveSync();
	mDoMemCd_Ctrl_status checkspace();
	void restore();
	undefined4 LoadSync(void *param_1, ulong param_2, ulong param_3);
	void ThdInit();
	void setCardState(card_errors param_1);
	void main();
	void attach();
	int mount();
	mDoMemCd_Ctrl_status getStatus(ulong param_1);
	void store();
	void update();
};

namespace m_Do_MemCard {
	extern os::OSThread MemCardThread;
	extern byte MemCardWorkArea0[CARD_WORKAREA_SIZE];
	extern mDoMemCd_Ctrl_c g_mDoMemCd_control;
	void *mDoMemCd_main(void *);
}
