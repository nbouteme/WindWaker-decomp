#pragma once

#include <dolphin/card.h>
#include <dolphin/os.h>
#include <doltypes.h>

#include <cstdio>
#include <cstring>

#include "./rst.h"
#include <JFramework/JKernel/JKRMemArchive.h>

#define copy_bytes memcpy

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
};

namespace m_Do_MemCardRWmng {
	extern int sSaveCount;
	extern char CardSerialNo[8];

	int mDoMemCdRWm_Store(card::CARDFileInfo *pInf, byte *data, int size);
	uint mDoMemCdRWm_TestCheckSumPictData(byte *param_1) ;
	void mDoMemCdRWm_SetCardStat(card::CARDFileInfo *param_1) ;
	uint m_Do_MemCardRWmng::mDoMemCdRWm_CalcCheckSum(ushort *pBuf, uint size);
	void mDoMemCdRWm_BuildHeader(card_savebuffer *param_1) ;
	undefined4 m_Do_MemCardRWmng::mDoMemCdRWm_CheckCardStat(card::CARDFileInfo *file) ;
	undefined8 mDoMemCdRWm_CalcCheckSumGameData(byte *pData, int size);
	card_savebuffer sTmpBuf, sTmpBuf2;


	uint mDoMemCdRWm_TestCheckSumGameData(card_savedata *pData);
	int mDoMemCdRWm_Restore(card::CARDFileInfo *file, byte *dest, int data_length) ;
	int mDoMemCdRWm_CalcCheckSumPictData(byte *param_1, int param_2);
}

namespace m_Do_MemCard {
	extern os::OSThread MemCardThread;
	extern byte MemCardWorkArea0[CARD_WORKAREA_SIZE];
	extern mDoMemCd_Ctrl_c g_mDoMemCd_control;
	void *mDoMemCd_main(void *) ;
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
	void detach() {
		card::CARDUnmount((uint)this->mCardSlot[0]);
		this->mStatus = STANDBY;
		return;
	}

	void format() {
		card_errors cVar1;

		cVar1 = (card_errors)card::CARDFormat((uint)this->mCardSlot[0]);
		if (cVar1 == CARD_ERROR_READY) {
			this->mStatus = DETACH;
		} else {
			setCardState(cVar1);
		}
		return;
	}

	void command_format() {
		int iVar1;

		iVar1 = os::OSTryLockMutex(&this->mOSMutex);
		if (iVar1 != 0) {
			this->mNextAction = FORMAT;
			os::OSUnlockMutex(&this->mOSMutex);
			os::OSSignalCond(&cond);
		}
		return;
	}

	void load() {
		int iVar1;

		iVar1 = os::OSTryLockMutex(&this->mOSMutex);
		if (iVar1 != 0) {
			this->mNextAction = RESTORE;
			os::OSUnlockMutex(&this->mOSMutex);
			os::OSSignalCond(&cond);
		}
		return;
	}

	bool loadfile() {
		card_errors cVar1;
		card::CARDFileInfo CStack40;

		cVar1 = (card_errors)card::CARDOpen((uint)this->mCardSlot[0], "gczelda", &CStack40);
		if (cVar1 != CARD_ERROR_READY) {
			setCardState(cVar1);
		} else {
			card::CARDClose(&CStack40);
		}
		return cVar1 == CARD_ERROR_READY;
	}

	undefined4 FormatSync() {
		int iVar1;
		undefined4 uVar2;

		uVar2 = 0;
		iVar1 = os::OSTryLockMutex(&this->mOSMutex);
		if (iVar1 != 0) {
			if (this->mStatus == DETACH) {
				this->mStatus = CREATE;
				uVar2 = 1;
			} else {
				uVar2 = 2;
			}
			os::OSUnlockMutex(&this->mOSMutex);
		}
		return uVar2;
	}

	void save(void *data, uint len, uint offset) {
		int iVar1;

		iVar1 = os::OSTryLockMutex(&this->mOSMutex);
		if (iVar1 != 0) {
			//copy_bytes(&(this->mMemCardData).field_0x0 + offset, (byte *)data, len);
			memcpy(((byte *)&mMemCardData) + offset, (byte *)data, len);
			this->mNextAction = CREATE;
			os::OSUnlockMutex(&this->mOSMutex);
			os::OSSignalCond(&cond);
		}
		return;
	}

	undefined4 SaveSync() {
		int iVar1;
		undefined4 uVar2;

		uVar2 = 0;
		iVar1 = os::OSTryLockMutex(&this->mOSMutex);
		if (iVar1 != 0) {
			if (this->mStatus == READY) {
				this->mStatus = RESTORE;
				uVar2 = 1;
			} else if (this->mStatus == RESTORE) {
				uVar2 = 0;
			} else {
				uVar2 = 2;
			}
			os::OSUnlockMutex(&this->mOSMutex);
		}
		return uVar2;
	}

	mDoMemCd_Ctrl_status checkspace() {
		int cVar1;
		int mVar2;
		int block_count;
		int block_size;

		cVar1 = (card_errors)card::CARDFreeBlocks((uint)this->mCardSlot[0], (s32 *)&block_size, &block_count);
		if (cVar1 == CARD_ERROR_READY) {
			if (block_size < 0x18000) {
				mVar2 = RESTORE;
			} else {
				mVar2 = -((uint)(block_count == 0) - (block_count >> 0x1f)) & 2;
			}
		} else {
			setCardState((card_errors)cVar1);
			mVar2 = FORMAT;
		}
		return (mDoMemCd_Ctrl_status)mVar2;
	}

	void restore() {
		int cVar1;
		int iVar2;
		card::CARDFileInfo CStack40;

		cVar1 = card::CARDOpen((uint)this->mCardSlot[0], "gczelda", &CStack40);
		if (cVar1 == CARD_ERROR_READY) {
			iVar2 = m_Do_MemCardRWmng::mDoMemCdRWm_Restore(&CStack40, (byte *)&this->mMemCardData, 0x1650);
			if (iVar2 == 0) {
				this->mStatus = FORMAT;
			} else {
				setCardState(CARD_ERROR_READY);
			}
			card::CARDClose(&CStack40);
		} else {
			setCardState((card_errors)cVar1);
		}
		return;
	}

	undefined4 LoadSync(void *param_1, ulong param_2, ulong param_3) {
		int iVar1;
		undefined4 uVar2;

		uVar2 = 0;
		iVar1 = os::OSTryLockMutex(&this->mOSMutex);
		if (iVar1 != 0) {
			if (this->mStatus == FORMAT) {
				//copy_bytes((byte *)param_1, &(this->mMemCardData).field_0x0 + param_3, param_2);
				memcpy((byte *)param_1, ((byte *)&mMemCardData) + param_3, param_2);
				this->mStatus = RESTORE;
				uVar2 = 1;
			} else {
				this->mStatus = CREATE;
				uVar2 = 2;
			}
			os::OSUnlockMutex(&this->mOSMutex);
		}
		return uVar2;
	}

	void ThdInit() {
		os::OSThread *pOVar1;
		int iVar2;

		card::CARDInit();
		//this->field1_0x1650 = 0;
		//this->field2_0x1654 = 0;
		this->mCardSlot[1] = 0;
		this->mCardSlot[2] = 2;
		this->mStatus = STANDBY;
		this->mNextAction = STANDBY;
		this->mCardSlot[0] = 0;
		os::OSInitMutex(&this->mOSMutex);
		os::OSInitCond(&cond);
		pOVar1 = os::OSGetCurrentThread();
		iVar2 = os::OSGetThreadPriority(pOVar1);
		os::OSCreateThread(&m_Do_MemCard::MemCardThread, m_Do_MemCard::mDoMemCd_main, 0,
						   &m_Do_MemCard::MemCardThread, 0x1000, iVar2 + 1, 1);
		os::OSResumeThread(&m_Do_MemCard::MemCardThread);
	}

	void setCardState(card_errors param_1) {
		int cVar1;

		if (param_1 == CARD_ERROR_IOERROR) {
		LAB_80019874:
			this->mStatus = IOERROR;
		} else {
			if ((int)param_1 < -5) {
				if (param_1 == CARD_ERROR_ENCODING) {
					this->mStatus = ENCODING;
					return;
				}
				if ((int)param_1 < -0xd) {
					if (param_1 != CARD_ERROR_FATAL_ERROR) {
						return;
					}
					goto LAB_80019874;
				}
				if ((int)param_1 < -6) {
					return;
				}
			} else if (param_1 != CARD_ERROR_READY) {
				if (-1 < (int)param_1) {
					return;
				}
				if (param_1 != CARD_ERROR_NOCARD) {
					return;
				}
				this->mStatus = STANDBY;
				return;
			}
			cVar1 = card::CARDCheck((uint)this->mCardSlot[0]);
			if (cVar1 != CARD_ERROR_READY) {
				this->mStatus = ERROR;
			}
		}
		return;
	}

	void main() {
		mDoMemCd_Ctrl_status mVar1;
		char *in_r6;
		ulong in_r7;
		void *in_r8;

		do {
			os::OSLockMutex(&this->mOSMutex);
			while (mVar1 = this->mNextAction, mVar1 == STANDBY) {
				os::OSWaitCond(&cond, &this->mOSMutex);
			}
			if (mVar1 == FORMAT) {
				format();
			} else if ((int)mVar1 < 3) {
				if (mVar1 == RESTORE) {
					restore();
				} else if (0 < (int)mVar1) {
					store();
				}
			} else if (mVar1 == DETACH) {
				detach();
			} else if ((int)mVar1 < 5) {
				attach();
			}
			this->mNextAction = STANDBY;
			os::OSUnlockMutex(&this->mOSMutex);
		} while (true);
	}

	void attach() {
		int cVar1;
		int iVar2;
		mDoMemCd_Ctrl_status mVar3;
		int local_18;
		int auStack20[4];

		cVar1 = card::CARDProbeEx((uint)this->mCardSlot[0], auStack20, &local_18);
		if (cVar1 == CARD_ERROR_WRONGDEVICE) {
			this->mStatus = WRONG_DEVICE;
		} else if (local_18 == 0x2000) {
			iVar2 = mount();
			if (iVar2 != 0) {
				iVar2 = loadfile();
				if (iVar2 == 0) {
					mVar3 = checkspace();
					if (mVar3 == CREATE) {
						this->mStatus = 9;
					} else if ((int)mVar3 < 2) {
						if (mVar3 == STANDBY) {
							this->mStatus = CREATE;
						} else if (-1 < (int)mVar3) {
							this->mStatus = 8;
						}
					}
				} else {
					this->mStatus = RESTORE;
				}
			}
		} else {
			this->mStatus = 0xb;
		}
		return;
	}

	int mount() {
		int cVar1;

		cVar1 = card::CARDMount((uint)this->mCardSlot[0], m_Do_MemCard::MemCardWorkArea0, 0);
		if (cVar1 == CARD_ERROR_IOERROR) {
		LAB_800196bc:
			this->mStatus = IOERROR;
			return 0;
		}
		if ((int)cVar1 < -5) {
			if (cVar1 == CARD_ERROR_ENCODING) {
				this->mStatus = ENCODING;
				return 0;
			}
			if ((int)cVar1 < -0xd) {
				if (cVar1 != CARD_ERROR_FATAL_ERROR) {
					return 0;
				}
				goto LAB_800196bc;
			}
			if ((int)cVar1 < -6) {
				return 0;
			}
		} else if (cVar1 != CARD_ERROR_READY) {
			if (-1 < (int)cVar1) {
				return 0;
			}
			if (cVar1 != CARD_ERROR_NOCARD) {
				return 0;
			}
			this->mStatus = STANDBY;
			return 0;
		}
		cVar1 = card::CARDCheck((uint)this->mCardSlot[0]);
		if (cVar1 == CARD_ERROR_READY) {
			return 1;
		}
		this->mStatus = ERROR;
		return 0;
	}

	mDoMemCd_Ctrl_status getStatus(ulong param_1) {
		int iVar1;
		mDoMemCd_Ctrl_status unaff_r31;

		iVar1 = os::OSTryLockMutex(&this->mOSMutex);
		if (iVar1 == 0) {
			unaff_r31 = (mDoMemCd_Ctrl_status)0xe;
		} else {
			switch (this->mStatus) {
			case STANDBY:
				unaff_r31 = STANDBY;
				break;
			case RESTORE:
				unaff_r31 = CREATE;
				break;
			case CREATE:
				unaff_r31 = RESTORE;
				break;
			case FORMAT:
				unaff_r31 = FORMAT;
				break;
			case READY:
				unaff_r31 = READY;
				break;
			case DETACH:
				unaff_r31 = DETACH;
				break;
			case ENCODING:
				unaff_r31 = ERROR;
				break;
			case ERROR:
				unaff_r31 = ENCODING;
				break;
			case 8:
				unaff_r31 = (mDoMemCd_Ctrl_status)0xb;
				break;
			case 9:
				unaff_r31 = IOERROR;
				break;
			case WRONG_DEVICE:
				unaff_r31 = (mDoMemCd_Ctrl_status)9;
				break;
			case 0xb:
				unaff_r31 = WRONG_DEVICE;
				break;
			case IOERROR:
				unaff_r31 = (mDoMemCd_Ctrl_status)8;
				break;
			case 0xd:
				unaff_r31 = (mDoMemCd_Ctrl_status)0xe;
			}
			os::OSUnlockMutex(&this->mOSMutex);
		}
		return unaff_r31;
	}

	void store() {
		int cVar1;
		int unaff_r31;
		card::CARDFileInfo CStack40;

		if (this->mStatus == CREATE) {
			unaff_r31 = card::CARDCreate((uint)this->mCardSlot[0], "gczelda", 0x18000, &CStack40);
			if (unaff_r31 == CARD_ERROR_READY) {
				this->mStatus = RESTORE;
			} else if (unaff_r31 == CARD_ERROR_EXIST) {
				this->mStatus = RESTORE;
			} else {
				setCardState((card_errors)unaff_r31);
			}
		}
		if (this->mStatus == RESTORE) {
			cVar1 = card::CARDOpen((uint)this->mCardSlot[0], "gczelda", &CStack40);
			if (cVar1 == CARD_ERROR_READY) {
				cVar1 = m_Do_MemCardRWmng::mDoMemCdRWm_Store(&CStack40, this->mMemCardData.data, 0x1650);
				if (cVar1 == CARD_ERROR_READY) {
					this->mStatus = READY;
				} else {
					setCardState((card_errors)cVar1);
				}
				card::CARDClose(&CStack40);
			} else {
				setCardState((card_errors)cVar1);
			}
		} else {
			setCardState((card_errors)unaff_r31);
		}
		return;
	}

	void update() {
		int mVar1;
		int cVar2;

		if (*mDoRst::mResetData == 0) {
			mVar1 = getStatus(0);
			if (mVar1 != 0xe) {
				cVar2 = card::CARDProbe(0);
				if ((cVar2 == CARD_ERROR_READY) ||
					(mVar1 = getStatus(0), mVar1 != STANDBY)) {
					cVar2 = card::CARDProbe(0);
					if ((cVar2 == CARD_ERROR_READY) &&
						(mVar1 = getStatus(0), mVar1 != STANDBY)) {
						os::OSLockMutex(&this->mOSMutex);
						this->mCardSlot[2] = 1;
						this->mNextAction = DETACH;
						os::OSUnlockMutex(&this->mOSMutex);
						os::OSSignalCond(&cond);
					}
				} else {
					os::OSLockMutex(&this->mOSMutex);
					this->mCardSlot[2] = 0;
					this->mNextAction = READY;
					os::OSUnlockMutex(&this->mOSMutex);
					os::OSSignalCond(&cond);
				}
			}
		} else {
			os::OSLockMutex(&this->mOSMutex);
			this->mNextAction = DETACH;
			this->mCardSlot[2] = 3;
			os::OSUnlockMutex(&this->mOSMutex);
			os::OSSignalCond(&cond);
		}
		return;
	}
};