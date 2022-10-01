#include "mDoMemCd_Ctrl_c.h"

#include <JFramework/JKernel/JKRMemArchive.h>

#include <cstdio>
#include <cstring>

#include "dvd.h"
#include "./rst.h"

#define copy_bytes memcpy


void mDoMemCd_Ctrl_c::detach() {
	card::CARDUnmount((uint)this->mCardSlot[0]);
	this->mStatus = STANDBY;
	return;
}

void mDoMemCd_Ctrl_c::format() {
	card_errors cVar1;

	cVar1 = (card_errors)card::CARDFormat((uint)this->mCardSlot[0]);
	if (cVar1 == CARD_ERROR_READY) {
		this->mStatus = DETACH;
	} else {
		setCardState(cVar1);
	}
	return;
}

void mDoMemCd_Ctrl_c::command_format() {
	int iVar1;

	iVar1 = os::OSTryLockMutex(&this->mOSMutex);
	if (iVar1 != 0) {
		this->mNextAction = FORMAT;
		os::OSUnlockMutex(&this->mOSMutex);
		os::OSSignalCond(&cond);
	}
	return;
}

void mDoMemCd_Ctrl_c::load() {
	int iVar1;

	iVar1 = os::OSTryLockMutex(&this->mOSMutex);
	if (iVar1 != 0) {
		this->mNextAction = RESTORE;
		os::OSUnlockMutex(&this->mOSMutex);
		os::OSSignalCond(&cond);
	}
	return;
}

bool mDoMemCd_Ctrl_c::loadfile() {
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

undefined4 mDoMemCd_Ctrl_c::FormatSync() {
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

void mDoMemCd_Ctrl_c::save(void *data, uint len, uint offset) {
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

undefined4 mDoMemCd_Ctrl_c::SaveSync() {
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

mDoMemCd_Ctrl_status mDoMemCd_Ctrl_c::checkspace() {
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

void mDoMemCd_Ctrl_c::restore() {
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

undefined4 mDoMemCd_Ctrl_c::LoadSync(void *param_1, ulong param_2, ulong param_3) {
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

void mDoMemCd_Ctrl_c::ThdInit() {
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

void mDoMemCd_Ctrl_c::setCardState(card_errors param_1) {
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

void mDoMemCd_Ctrl_c::main() {
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

void mDoMemCd_Ctrl_c::attach() {
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

int mDoMemCd_Ctrl_c::mount() {
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

mDoMemCd_Ctrl_status mDoMemCd_Ctrl_c::getStatus(ulong param_1) {
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

void mDoMemCd_Ctrl_c::store() {
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

void mDoMemCd_Ctrl_c::update() {
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

namespace m_Do_MemCardRWmng {

	int sSaveCount;

	int mDoMemCdRWm_Store(card::CARDFileInfo *pInf, byte *data, int size) {
		uint offset;
		int cVar1;
		int iVar1;
		int cVar2;
		uint uVar3;
		uint uVar4;
		int iVar5;
		int iVar6;

		m_Do_MemCardRWmng::mDoMemCdRWm_BuildHeader(&m_Do_MemCardRWmng::sTmpBuf);
		cVar1 = card::CARDWrite(pInf, &m_Do_MemCardRWmng::sTmpBuf, 0x2000, 0);
		if (cVar1 == 0) {
			iVar1 = m_Do_MemCardRWmng::mDoMemCdRWm_CheckCardStat(pInf);
			if (iVar1 == 0) {
				memset(&m_Do_MemCardRWmng::sTmpBuf, 0, 0x2000);
				cVar2 = card::CARDWrite(pInf, &m_Do_MemCardRWmng::sTmpBuf, 0x2000, 0x2000);
				if (cVar2 != CARD_ERROR_READY) {
					return cVar2;
				}
				cVar2 = card::CARDWrite(pInf, &m_Do_MemCardRWmng::sTmpBuf, 0x2000, 0x4000);
				if (cVar2 != CARD_ERROR_READY) {
					return cVar2;
				}
				m_Do_MemCardRWmng::sSaveCount = 0;
			}
			memset(&m_Do_MemCardRWmng::sTmpBuf, 0, 0x2000);
			m_Do_MemCardRWmng::sTmpBuf.field1_0x4 = 0;
			copy_bytes(m_Do_MemCardRWmng::sTmpBuf.mSaveData[0].mData, data, size);
			m_Do_MemCardRWmng::sTmpBuf.mSaveCount = m_Do_MemCardRWmng::sSaveCount + 1;
			m_Do_MemCardRWmng::sSaveCount = m_Do_MemCardRWmng::sTmpBuf.mSaveCount;
			uVar3 = m_Do_MemCardRWmng::mDoMemCdRWm_CalcCheckSum((ushort *)&m_Do_MemCardRWmng::sTmpBuf, 0x1ffc);
			m_Do_MemCardRWmng::sTmpBuf.mCheckSum = uVar3;
			cVar1 = card::CARDWrite(pInf, &m_Do_MemCardRWmng::sTmpBuf, 0x2000, 0x2000);
			if ((((cVar1 == CARD_ERROR_READY) &&
				  (cVar1 = card::CARDRead(pInf, &m_Do_MemCardRWmng::sTmpBuf, 0x2000, 0x2000),
				   cVar1 == CARD_ERROR_READY)) &&
				 (uVar4 = m_Do_MemCardRWmng::mDoMemCdRWm_CalcCheckSum((ushort *)&m_Do_MemCardRWmng::sTmpBuf, 0x1ffc),
				  uVar3 == uVar4)) &&
				(((cVar1 = card::CARDWrite(pInf, &m_Do_MemCardRWmng::sTmpBuf, 0x2000, 0x4000),
				   cVar1 == CARD_ERROR_READY &&
					   (cVar1 = card::CARDRead(pInf, &m_Do_MemCardRWmng::sTmpBuf, 0x2000, 0x4000),
						cVar1 == CARD_ERROR_READY)) &&
				  (uVar4 = m_Do_MemCardRWmng::mDoMemCdRWm_CalcCheckSum((ushort *)&m_Do_MemCardRWmng::sTmpBuf, 0x1ffc),
				   uVar3 == uVar4)))) {
				if (m_Do_MemCard::g_mDoMemCd_control.field2_0x1654 == 0) {
					uVar3 = (uint)d_com_inf_game::g_dComIfG_gameInfo.maybeCurrentSelectedFile;
					uVar4 = 0;
					iVar1 = 0;
					do {
						if ((1 << (uVar4 & 0xff) & 0xffU & (uint)d_com_inf_game::g_dComIfG_gameInfo.pictureStatus) !=
							0) {
							memset(&m_Do_MemCardRWmng::sTmpBuf, 0, 0x2000);
							//JKRAram::aramToMainRam(d_com_inf_game::g_dComIfG_gameInfo.mPlay.bigAramRegion[uVar4],
							//					   (uchar *)&m_Do_MemCardRWmng::sTmpBuf, 0x2000, 0, 0, 0, (JKRHeap *)0x0, -1,
							//					   (ulong *)0x0);
							offset = (uVar3 * 3 + 3 + uVar4) * 0x2000;
							cVar2 = card::CARDWrite(pInf, &m_Do_MemCardRWmng::sTmpBuf, 0x2000, offset);
							if (cVar2 != CARD_ERROR_READY) {
								return cVar2;
							}
							cVar1 = card::CARDRead(pInf, &m_Do_MemCardRWmng::sTmpBuf, 0x2000, offset);
							if (cVar1 != CARD_ERROR_READY) {
								return cVar1;
							}
						}
						uVar4 = uVar4 + 1;
						iVar1 = iVar1 + 4;
					} while ((int)uVar4 < 3);
				} else {
					uVar3 = (uint)m_Do_MemCard::g_mDoMemCd_control.mCardSlot[1];
					if (uVar3 < 3) {
						iVar6 = 0;
						iVar1 = m_Do_MemCard::g_mDoMemCd_control.field2_0x1654;
						do {
							uVar4 = (uVar3 * 3 + 3 + iVar6) * 0x2000;
							cVar2 = card::CARDWrite(pInf, (void *)iVar1, 0x2000, uVar4);
							if (cVar2 != CARD_ERROR_READY) {
								return cVar2;
							}
							cVar1 = card::CARDRead(pInf, &m_Do_MemCardRWmng::sTmpBuf, 0x2000, uVar4);
							if (cVar1 != CARD_ERROR_READY) {
								return cVar1;
							}
							iVar5 = m_Do_MemCardRWmng::mDoMemCdRWm_TestCheckSumPictData((byte *)iVar1);
							if (iVar5 == 0) {
								return 0;
							}
							iVar6 = iVar6 + 1;
							iVar1 = iVar1 + 0x2000;
						} while (iVar6 < 3);
					}
				}
				m_Do_MemCardRWmng::mDoMemCdRWm_SetCardStat(pInf);
			}
		}
		return cVar1;
	}

	uint mDoMemCdRWm_TestCheckSumPictData(byte *param_1) {
		uint uVar1;

		uVar1 = m_Do_MemCardRWmng::mDoMemCdRWm_CalcCheckSumPictData(param_1, 0x1ffe);
		// no idea what's going on with the decomp here
		uVar1 = __builtin_clz((uint) * (ushort *)(param_1 + 0x1ffe) - (uVar1 & 0xffff));
		return uVar1 >> 5 & 0xff;
	}

	void mDoMemCdRWm_SetCardStat(card::CARDFileInfo *param_1) {
		card::CARDStat stat;

		card::CARDGetStatus((uint)m_Do_MemCard::g_mDoMemCd_control.mCardSlot[0],
							param_1->fileNo, &stat);
		stat.iconAddr = 0;
		stat.commentAddr = 0x1c00;
		stat.bannerFormat = (stat.bannerFormat & 0xf8) | 1;
		stat.iconFormat = 1;
		stat.iconSpeed = 3;
		card::CARDSetStatus((uint)m_Do_MemCard::g_mDoMemCd_control.mCardSlot[0], param_1->fileNo, &stat);
	}

	uint mDoMemCdRWm_CalcCheckSum(ushort *pBuf, uint size)

	{
		int iVar1;
		uint uVar2;

		uVar2 = 0;
		iVar1 = 0;
		for (size = size >> 1; size != 0; size = size - 1) {
			iVar1 = iVar1 + (uint)*pBuf;
			uVar2 = uVar2 + ~(uint)*pBuf & 0xffff;
			pBuf = pBuf + 1;
		}
		return iVar1 << 0x10 | uVar2;
	}

	void mDoMemCdRWm_BuildHeader(card_savebuffer *param_1) {
		mDoDvdThd_mountArchive_c *pmVar1;
		void *iVar2;
		void *iVar3;
		JKRMemArchive *pnVar4;
		long long lVar5;
		os::OSCalendarTime OStack72;

		snprintf(param_1->mHeaderGameName, 0x20, "Zelda: The Wind Waker");
		os::OSTicksToCalendarTime(os::OSGetTime(), &OStack72);
		snprintf(param_1->mSaveInfoStr, 0x20, "%d/%d Save Data", OStack72.mon + 1, OStack72.mday);
		pmVar1 = mDoDvdThd_mountArchive_c::create("/res/CardIcon/cardicon.arc", '\0', nullptr);
		do {
		} while (pmVar1->mStatus == 0);	 // changed by hardware interrupt

		pnVar4 = pmVar1->mpResult;

		//802b8380  JKRArchive::getResource
		iVar2 = pnVar4->getResource("ipl_banner.bti");
		iVar3 = pnVar4->getResource("ipl_icon1.bti");
		copy_bytes((byte *)param_1, (byte *)(iVar2 + *(int *)(iVar2 + 0x1c)),
				   (uint) * (ushort *)(iVar2 + 10) * 2 + 0xc00);
		copy_bytes(param_1->mSaveData[1].mData + 0x688, (byte *)(iVar3 + *(int *)(iVar3 + 0x1c)),
				   (uint) * (ushort *)(iVar3 + 10) * 2 + 0x400);

		//802b6854 JKRFileLoader::unmount
		pnVar4->unmount();
		pmVar1->~mDoDvdThd_mountArchive_c();
		// TODO: need to free pmVar1
	}

	undefined4 mDoMemCdRWm_CheckCardStat(card::CARDFileInfo *file) {
		card::CARDStat lcl;
		card::CARDGetStatus((uint)m_Do_MemCard::g_mDoMemCd_control.mCardSlot[0], file->fileNo, &lcl);
		return 1;
	}

	undefined8 mDoMemCdRWm_CalcCheckSumGameData(byte *pData, int size)

	{
		int iVar1;
		int iVar2;

		iVar2 = 0;
		iVar1 = 0;
		if (size != 0) {
			do {
				iVar1 = iVar1 + (uint)*pData;
				iVar2 = iVar2 + ~(uint)*pData;
				pData = pData + 1;
				size = size + -1;
			} while (size != 0);
		}
		return ((undefined8)iVar1) << 32 | iVar2;
	}

	card_savebuffer sTmpBuf, sTmpBuf2;

	char CardSerialNo[8];

	uint mDoMemCdRWm_TestCheckSumGameData(card_savedata *pData)

	{
		uint ret;
		undefined8 csum;

		csum = mDoMemCdRWm_CalcCheckSumGameData((byte *)pData, 0x768);
		return (ret >> 32) == pData->possum && (ret & 0xFFFFFFFF) == pData->negsum;
	}

	int mDoMemCdRWm_Restore(card::CARDFileInfo *file, byte *dest, int data_length) {
		bool bVar1;
		bool bVar2;
		int cVar3;
		int iVar3;
		int iVar4;
		int iVar5;
		int iVar6;
		int iVar7;
		int iVar8;
		uint local_38;
		undefined4 local_34;

		bVar1 = false;
		cVar3 = card::CARDRead(file, &m_Do_MemCardRWmng::sTmpBuf, 0x2000, 0x2000);
		if (cVar3 == 0) {
			iVar3 = m_Do_MemCardRWmng::mDoMemCdRWm_TestCheckSumGameData(m_Do_MemCardRWmng::sTmpBuf.mSaveData);
			iVar4 = m_Do_MemCardRWmng::mDoMemCdRWm_TestCheckSumGameData(m_Do_MemCardRWmng::sTmpBuf.mSaveData + 1);
			iVar5 = m_Do_MemCardRWmng::mDoMemCdRWm_TestCheckSumGameData(m_Do_MemCardRWmng::sTmpBuf.mSaveData + 2);
			cVar3 = card::CARDRead(file, &m_Do_MemCardRWmng::sTmpBuf2, 0x2000, 0x4000);
			if (cVar3 == CARD_ERROR_READY) {
				iVar6 = m_Do_MemCardRWmng::mDoMemCdRWm_TestCheckSumGameData(m_Do_MemCardRWmng::sTmpBuf2.mSaveData);
				iVar7 = m_Do_MemCardRWmng::mDoMemCdRWm_TestCheckSumGameData(m_Do_MemCardRWmng::sTmpBuf2.mSaveData + 1);
				iVar8 = m_Do_MemCardRWmng::mDoMemCdRWm_TestCheckSumGameData(m_Do_MemCardRWmng::sTmpBuf2.mSaveData + 2);
				if ((iVar3 == 0) && (iVar6 != 0)) {
					copy_bytes(m_Do_MemCardRWmng::sTmpBuf.mSaveData[0].mData,
							   m_Do_MemCardRWmng::sTmpBuf2.mSaveData[0].mData, 0x770);
					bVar1 = true;
				}
				if ((iVar4 == 0) && (iVar8 != 0)) {
					copy_bytes(m_Do_MemCardRWmng::sTmpBuf.mSaveData[1].mData,
							   m_Do_MemCardRWmng::sTmpBuf2.mSaveData[1].mData, 0x770);
					bVar1 = true;
				}
				if ((iVar5 == 0) && (iVar8 != 0)) {
					copy_bytes(m_Do_MemCardRWmng::sTmpBuf.mSaveData[2].mData,
							   m_Do_MemCardRWmng::sTmpBuf2.mSaveData[2].mData, 0x770);
					bVar1 = true;
				}
				bVar2 = false;
				if (((((iVar3 == 0) && (iVar6 == 0)) && (iVar4 == 0)) && ((iVar7 == 0 && (iVar5 == 0)))) &&
					(iVar8 == 0)) {
					bVar2 = true;
				}
				iVar3 = m_Do_MemCardRWmng::mDoMemCdRWm_CheckCardStat(file);
				if (iVar3 == 0) {
					cVar3 = CARD_ERROR_FATAL_ERROR;
				} else if ((!bVar1) ||
						   ((cVar3 = card::CARDWrite(file, &m_Do_MemCardRWmng::sTmpBuf, 0x2000, 0x2000),
							 cVar3 == CARD_ERROR_READY &&
								 (cVar3 = card::CARDWrite(file, &m_Do_MemCardRWmng::sTmpBuf, 0x2000, 0x4000),
								  cVar3 == CARD_ERROR_READY)))) {
					copy_bytes(dest, m_Do_MemCardRWmng::sTmpBuf.mSaveData[0].mData, data_length);
					m_Do_MemCardRWmng::sSaveCount = m_Do_MemCardRWmng::sTmpBuf.mSaveCount;
					//DAT_803b5030 = m_Do_MemCardRWmng::sTmpBuf.field1_0x4;
					if ((bVar2) ||
						((m_Do_MemCard::g_mDoMemCd_control.field1_0x1650 == 0 ||
						  (cVar3 = card::CARDRead(file, (void *)m_Do_MemCard::g_mDoMemCd_control.field1_0x1650,
												  0x12000, 0x6000),
						   cVar3 == CARD_ERROR_READY)))) {
						card::CARDGetSerialNo((uint)m_Do_MemCard::g_mDoMemCd_control.mCardSlot[0], (u64 *)CardSerialNo);
						cVar3 = CARD_ERROR_READY;
					}
				}
			}
		}
		return cVar3;
	}

	int mDoMemCdRWm_CalcCheckSumPictData(byte *param_1, int param_2)

	{
		int iVar1;

		iVar1 = 0;
		if (param_2 != 0) {
			do {
				iVar1 = iVar1 + (uint)*param_1;	 // cheeky
				param_1 = param_1 + 1;
				param_2 = param_2 + -1;
			} while (param_2 != 0);
		}
		return iVar1;
	}
}

namespace m_Do_MemCard {
	os::OSThread MemCardThread;
	byte MemCardWorkArea0[CARD_WORKAREA_SIZE];
	mDoMemCd_Ctrl_c g_mDoMemCd_control;

	void *mDoMemCd_main(void *) {
		//TODO
	}

}