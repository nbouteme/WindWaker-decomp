#pragma once

#include <machine/dolphin/dvd.h>

#include <cstdio>

struct dRes_info_c {
	char mName[14];
	short mRefCount;
	mDoDvdThd_mountArchive_c *mpDvdThdCommand;
	JKRArchive *mpArchive;
	JKRHeap *mpParentHeap, *mpDataHeap;
	void *mpRes;

	void loadResource() {
		// TODO: pretty big, and pretty important
	}

	int setRes() {
		undefined4 uVar1;
		mDoDvdThd_mountArchive_c *pmVar2;
		JKRSolidHeap *pJVar3;
		ulong uVar4;
		JKRExpHeap *pJVar5;
		int iVar6;
		uint uVar7;
		int iVar8;

		if (this->mpArchive == (JKRArchive *)0x0) {
			pmVar2 = this->mpDvdThdCommand;
			if (pmVar2 == (mDoDvdThd_mountArchive_c *)0x0) {
				return -1;
			}
			if (pmVar2->mStatus == 0) {
				return 1;
			}
			this->mpArchive = pmVar2->mpResult;
			this->mpParentHeap = this->mpDvdThdCommand->mpHeap;
			pmVar2 = this->mpDvdThdCommand;
			if (pmVar2 != (mDoDvdThd_mountArchive_c *)0x0) {
				delete pmVar2;
			}
			this->mpDvdThdCommand = (mDoDvdThd_mountArchive_c *)0x0;
			if (this->mpArchive == (JKRArchive *)0x0) {
				m_Do_printf::OSReport_Error("<%s.arc> setRes: archive mount error !!\n", this);
				return -1;
			}
			if (this->mpParentHeap == (JKRHeap *)0x0) {
				this->mpDataHeap = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(0, 0);
				if (this->mpDataHeap == (JKRHeap *)0x0) {
					m_Do_printf::OSReport_Error("<%s.arc> mDMCommandsetRes: can\'t alloc memory\n", this);
					return -1;
				}
				loadResource();
				static int mode = 1;
				static int allocMode = 1;
				m_Do_ext::mDoExt_restoreCurrentHeap();

				uVar1 = allocMode;
				pJVar5 = m_Do_ext::mDoExt_getGameHeap();
				pJVar5->field1_0x6c = (byte)uVar1;
				mode = 2;
				if (true) {
					if (true) {
						m_Do_ext::mDoExt_adjustSolidHeap((JKRSolidHeap *)this->mpDataHeap);
					} else {  // dead code
						uVar7 = m_Do_ext::mDoExt_adjustSolidHeap((JKRSolidHeap *)this->mpDataHeap);
						pJVar3 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(uVar7 + 0x10, 0);
						if (pJVar3 != (JKRSolidHeap *)0x0) {
							if (pJVar3 < (JKRSolidHeap *)this->mpDataHeap) {
								this->mpRes = (undefined *)0x0;
								m_Do_ext::mDoExt_destroySolidHeap((JKRSolidHeap *)this->mpDataHeap);
								loadResource();
								m_Do_ext::mDoExt_adjustSolidHeap(pJVar3);
								this->mpDataHeap = pJVar3;
							} else {
								m_Do_ext::mDoExt_destroySolidHeap(pJVar3);
							}
							m_Do_ext::mDoExt_restoreCurrentHeap();
						}
					}
				} else {  // dead code
					iVar8 = this->mpDataHeap->mSize;
					iVar6 = this->mpParentHeap->getFreeSize();
					pJVar3 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent((iVar8 - iVar6) + 0x8c, 0);
					if (pJVar3 == (JKRSolidHeap *)0x0) {
						m_Do_ext::mDoExt_adjustSolidHeap((JKRSolidHeap *)this->mpDataHeap);
					} else {
						m_Do_ext::mDoExt_adjustSolidHeap((JKRSolidHeap *)this->mpDataHeap);
						this->mpRes = (undefined *)0x0;
						m_Do_ext::mDoExt_destroySolidHeap((JKRSolidHeap *)this->mpDataHeap);
						loadResource();
						m_Do_ext::mDoExt_restoreCurrentHeap();
						m_Do_ext::mDoExt_adjustSolidHeap(pJVar3);
						this->mpDataHeap = pJVar3;
					}
				}
				pJVar5 = m_Do_ext::mDoExt_getGameHeap();
				pJVar5->field1_0x6c = 0;
			} else {
				pJVar3 = m_Do_ext::mDoExt_createSolidHeapToCurrent(0, this->mpParentHeap, 0x20);
				this->mpDataHeap = pJVar3;
				if (this->mpDataHeap == (JKRHeap *)0x0) {
					JUTAssertion::getSDevice()->showAssert("d_resorce.cpp", 0x3f5, "mDataHeap != 0");
					m_Do_printf::OSPanic("d_resorce.cpp", 0x3f5, "Halt");
				}
				loadResource();
				m_Do_ext::mDoExt_restoreCurrentHeap();
				m_Do_ext::mDoExt_adjustSolidHeap((JKRSolidHeap *)this->mpDataHeap);
			}
			os::DCStoreRangeNoSync(this->mpDataHeap->mpDataBegin, this->mpDataHeap->mSize);
		}
		return 0;
	}

	bool set(char *param_1, char *param_2, uchar param_3, JKRHeap *param_4) {
		bool bVar1;
		mDoDvdThd_mountArchive_c *pmVar2;
		char name[40];

		snprintf(name, 0x28, "%s%s.arc", param_2, param_1);
		pmVar2 = mDoDvdThd_mountArchive_c::create(name, param_3, param_4);
		this->mpDvdThdCommand = pmVar2;
		bVar1 = this->mpDvdThdCommand != (mDoDvdThd_mountArchive_c *)0x0;
		if (bVar1) {
			strncpy(this->mName, param_1, 0xe);
		}
		return bVar1;
	}
};

struct dRes_control_c {
	dRes_info_c mObjectInfo[64];

	void dump();

	static dRes_info_c *getResInfoLoaded(char *arcName, dRes_info_c *resInfosList, int totalResInfos) {
		dRes_info_c *pdVar1;

		pdVar1 = getResInfo(arcName, resInfosList, totalResInfos);
		if (pdVar1 == (dRes_info_c *)0x0) {
			m_Do_printf::OSReport_Error("<%s.arc> getRes: res nothing !!\n", arcName);
			pdVar1 = (dRes_info_c *)0x0;
		} else if (pdVar1->mpArchive == (JKRArchive *)0x0) {
			m_Do_printf::OSReport_Error("<%s.arc> getRes: res during reading !!\n", arcName);
			pdVar1 = (dRes_info_c *)0x0;
		}
		return pdVar1;
	}

	static void *getRes(char *arcName, long fileIndex, dRes_info_c *resInfosList, int totalResInfos) {
		dRes_info_c *pRes;

		pRes = getResInfoLoaded(arcName, resInfosList, totalResInfos);
		if (pRes != (dRes_info_c *)0x0) {
			if (fileIndex < pRes->mpArchive->mpDataHeader->mFileEntryCount) {
				pRes = *(dRes_info_c **)(pRes->mpRes + fileIndex * 4);
			} else {
				m_Do_printf::OSReport_Error("<%s.arc> getRes: res index over !! index=%d count=%d\n", arcName, fileIndex);
				pRes = (dRes_info_c *)0x0;
			}
		}
		return pRes;
	}

	static void *getRes(char *param_1, char *param_2, dRes_info_c *param_3, int param_4) {
		dRes_info_c *pdVar1;
		int iVar2;
		ulong uVar3;
		int iVar4;
		int iVar5;
		SDirEntry aSStack40[2];

		pdVar1 = getResInfoLoaded(param_1, param_3, param_4);
		if (pdVar1 != (dRes_info_c *)0x0) {
			iVar4 = pdVar1->mpArchive->mpDataHeader->mFileEntryCount;
			iVar5 = 0;
			for (uVar3 = 0; (int)uVar3 < iVar4; uVar3 = uVar3 + 1) {
				if (*(int *)(pdVar1->mpRes + iVar5) != 0) {
					pdVar1->mpArchive->getDirEntry(aSStack40, uVar3);
					iVar2 = strcmp(param_2, aSStack40[0].data);
					if (iVar2 == 0) {
						return *(void **)(pdVar1->mpRes + iVar5);
					}
				}
				iVar5 = iVar5 + sizeof(void *);
			}
			pdVar1 = (dRes_info_c *)0x0;
		}
		return pdVar1;
	}

	static int syncAllRes(dRes_info_c *param_1, int param_2) {
		int iVar1;
		int iVar2;

		iVar2 = 0;
		while (true) {
			if (param_2 <= iVar2) {
				return 0;
			}
			if ((param_1->mpDvdThdCommand != (mDoDvdThd_mountArchive_c *)0x0) &&
				(iVar1 = param_1->setRes(), 0 < iVar1))
				break;
			param_1 = param_1 + 1;
			iVar2 = iVar2 + 1;
		}
		return 1;
	}

	static dRes_info_c *getResInfo(char *pArcName, dRes_info_c *pResInfoList, int count) {
		int iVar1;
		int iVar2;

		iVar2 = 0;
		while (true) {
			if (count <= iVar2) {
				return (dRes_info_c *)0x0;
			}
			if ((pResInfoList->mRefCount != 0) &&
				(iVar1 = strcmp(pArcName, pResInfoList->mName), iVar1 == 0))
				break;
			pResInfoList = pResInfoList + 1;
			iVar2 = iVar2 + 1;
		}
		return pResInfoList;
	}

	static dRes_info_c *newResInfo(dRes_info_c *param_1, int param_2) {
		if (0 < param_2) {
			do {
				if (param_1->mRefCount == 0) {
					return param_1;
				}
				param_1 = param_1 + 1;
				param_2 = param_2 + -1;
			} while (param_2 != 0);
		}
		return (dRes_info_c *)0x0;
	}

	static int setRes(char *param_1, dRes_info_c *param_2, int param_3, char *param_4, byte param_5, JKRHeap *param_6) {
		dRes_info_c *info;
		int iVar1;

		info = dRes_control_c::getResInfo(param_1, param_2, param_3);
		if (info == (dRes_info_c *)0x0) {
			info = dRes_control_c::newResInfo(param_2, param_3);
			if (info == (dRes_info_c *)0x0) {
				m_Do_printf::OSReport_Error("<%s.arc> dRes_control_c::setRes: 空きリソース情報ポインタがありません\n", param_1);
				delete info;
				return 0;
			}
			iVar1 = info->set(param_1, param_4, param_5, param_6);
			if (iVar1 == 0) {
				m_Do_printf::OSReport_Error("<%s.arc> dRes_control_c::setRes: res info set error !!\n", param_1);
				delete info;
				return 0;
			}
		}
		info->mRefCount = info->mRefCount + 1;
		return 1;
	}
};