#include "d_resorce.h"

#include <JFramework/J3D/J3DCluster.h>
#include <JFramework/JKernel/JKRMemArchive.h>
#include <JFramework/JUtility/JUTNameTab.h>

void dRes_control_c::dump() {
}

dRes_info_c *dRes_control_c::getResInfoLoaded(char *arcName, dRes_info_c *resInfosList, int totalResInfos) {
	dRes_info_c *pdVar1;

	pdVar1 = getResInfo(arcName, resInfosList, totalResInfos);
	if (pdVar1 == nullptr) {
		m_Do_printf::OSReport_Error("<%s.arc> getRes: res nothing !!\n", arcName);
		pdVar1 = nullptr;
	} else if (pdVar1->mpArchive == nullptr) {
		m_Do_printf::OSReport_Error("<%s.arc> getRes: res during reading !!\n", arcName);
		pdVar1 = nullptr;
	}
	return pdVar1;
}

int dRes_control_c::deleteRes(char *pName, dRes_info_c *pResInfoList, int count) {
	short sVar1;
	dRes_info_c *self;
	undefined4 uVar2;

	self = dRes_control_c::getResInfo(pName, pResInfoList, count);
	if (!self) {
		m_Do_printf::OSReport_Error("<%s.arc> deleteRes: res nothing !!\n(未登録のリソースを削除してるのを発見しました！修正して ください。)\n", pName);
		uVar2 = 0;
	} else {
		sVar1 = self->mRefCount + -1;
		self->mRefCount = sVar1;
		if (sVar1 == 0) {
			self->~dRes_info_c();
		}
		uVar2 = 1;
	}
	return uVar2;
}

uint dRes_control_c::syncRes(char *param_1, dRes_info_c *param_2, int param_3) {
	dRes_info_c *pInf;
	undefined4 uVar1;

	pInf = dRes_control_c::getResInfo(param_1, param_2, param_3);
	if (pInf == nullptr) {
		m_Do_printf::OSReport_Error("<%s.arc> syncRes: リソース未登録!!\n", param_1);
		uVar1 = 1;
	} else {
		uVar1 = pInf->setRes();
	}
	return uVar1;
}

void *dRes_control_c::getRes(char *arcName, long fileIndex, dRes_info_c *resInfosList, int totalResInfos) {
	dRes_info_c *pRes;

	pRes = getResInfoLoaded(arcName, resInfosList, totalResInfos);
	if (pRes) {
		if (fileIndex < pRes->mpArchive->mpDataHeader->mFileEntryCount) {
			pRes = (dRes_info_c *)((void **)pRes->mpRes)[fileIndex];
		} else {
			m_Do_printf::OSReport_Error("<%s.arc> getRes: res index over !! index=%d count=%d\n", arcName, fileIndex);
			pRes = nullptr;
		}
	}
	return pRes;
}

void *dRes_control_c::getRes(char *param_1, char *param_2, dRes_info_c *param_3, int param_4) {
	dRes_info_c *pdVar1;
	int iVar2;
	ulong uVar3;
	int iVar4;
	int iVar5;
	SDirEntry aSStack40[2];

	pdVar1 = getResInfoLoaded(param_1, param_3, param_4);
	if (pdVar1 != nullptr) {
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
		pdVar1 = nullptr;
	}
	return pdVar1;
}

int dRes_control_c::syncAllRes(dRes_info_c *param_1, int param_2) {
	int iVar1;
	int iVar2;

	iVar2 = 0;
	while (true) {
		if (param_2 <= iVar2) {
			return 0;
		}
		if ((param_1->mpDvdThdCommand != nullptr) &&
			(iVar1 = param_1->setRes(), 0 < iVar1))
			break;
		param_1 = param_1 + 1;
		iVar2 = iVar2 + 1;
	}
	return 1;
}

dRes_info_c *dRes_control_c::getResInfo(char *pArcName, dRes_info_c *pResInfoList, int count) {
	int iVar1;
	int iVar2;

	iVar2 = 0;
	while (true) {
		if (count <= iVar2) {
			return nullptr;
		}
		if ((pResInfoList->mRefCount != 0) &&
			(iVar1 = strcmp(pArcName, pResInfoList->mName), iVar1 == 0))
			break;
		pResInfoList = pResInfoList + 1;
		iVar2 = iVar2 + 1;
	}
	return pResInfoList;
}

dRes_info_c *dRes_control_c::newResInfo(dRes_info_c *param_1, int param_2) {
	if (0 < param_2) {
		do {
			if (param_1->mRefCount == 0) {
				return param_1;
			}
			param_1 = param_1 + 1;
			param_2 = param_2 + -1;
		} while (param_2 != 0);
	}
	return nullptr;
}

int dRes_control_c::setRes(char *param_1, dRes_info_c *param_2, int param_3, char *param_4, byte param_5, JKRHeap *param_6) {
	dRes_info_c *info;
	int iVar1;

	info = dRes_control_c::getResInfo(param_1, param_2, param_3);
	if (info == nullptr) {
		info = dRes_control_c::newResInfo(param_2, param_3);
		if (info == nullptr) {
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

namespace d_resorce {

	char l_readResType$4166[] = {
		"BMD "
		"BMDM"
		"BMDC"
		"BMDS"

		"BSMD"
		"BMT "
		"MLS "
		"BCK "
		"BPK "
		"BRK "
		"BLK "
		"BTP "
		"BTK "
		"BAS "

		"BDL "
		"BDLM"
		"BDLC"
		"BDLI"

		"DZB "
		"DZR "
		"DZS "

		"TIM "
		"MSG "
		"TEX "
		"STB "
		"BCKS"
		"DAT "
		"BVA "
		"BMTM"};

	void setToonTex(J3DModelData *pModel) {
		uint uVar1;
		char *pcVar2;
		ResTIMG *pTexRes;
		ResTIMG *pRVar3;
		int iVar4;
		ushort uVar5;
		bool bVar6;
		ushort uVar8;
		J3DDisplayListObj *pJVar7;
		JUTNameTab *nametab;
		J3DMaterial *pJVar9;
		J3DTexture *pJVar10;
		J3DTevBlock *pJVar11;
		/*
		pJVar10 = (pModel->mMaterialTable).mpTexture;
		if ((pJVar10 != nullptr) &&
			(nametab = (pModel->mMaterialTable).mpTexNameTab, nametab != nullptr)) {
			for (uVar8 = 0; uVar8 < (ushort)pJVar10->mCount; uVar8 = uVar8 + 1) {
				pcVar2 = JUTNameTab::getName(nametab, uVar8);
				pTexRes = dDlst_list_c::mToonExImage;
				pRVar3 = dDlst_list_c::mToonImage;
				if (*pcVar2 == 'Z') {
					if (pcVar2[1] == 'A') {
						pTexRes = pJVar10->mpTexData + uVar8;
						*pTexRes = *dDlst_list_c::mToonImage;

						pTexRes = pJVar10->mpTexData + uVar8;
						pTexRes->mTexDataOffs = (int)pRVar3 + (pTexRes->mTexDataOffs - (int)pTexRes);
						pTexRes = pJVar10->mpTexData + uVar8;
						pTexRes->mTlutDataOffs = (int)pRVar3 + (pTexRes->mTlutDataOffs - (int)pTexRes);
					} else if (pcVar2[1] == 'B') {
						pRVar3 = pJVar10->mpTexData + uVar8;
						pRVar3->mTexFmt = dDlst_list_c::mToonExImage->mTexFmt;
						*pRVar3 = *dDlst_list_c::mToonExImage;

						pRVar3 = pJVar10->mpTexData + uVar8;
						pRVar3->mTexDataOffs = (int)pTexRes + (pRVar3->mTexDataOffs - (int)pRVar3);

						pRVar3->mTlutDataOffs = (int)pTexRes + (pRVar3->mTlutDataOffs - (int)pRVar3);
					}
				}
			}
			J3DGraphBase::j3dSys.mpCurTex = pJVar10;
			for (uVar8 = 0; uVar8 < (pModel->mMaterialTable).mMaterialCount; uVar8 = uVar8 + 1) {
				pJVar9 = (pModel->mMaterialTable).mpMaterials[uVar8];
				pJVar11 = pJVar9->mpTevBlock;
				if (pJVar11 != nullptr) {
					iVar4 = pJVar11->getTevColor(3);
					if (iVar4 != 0) {
						uVar5 = pJVar11->getTevStageNum();
						*(ushort *)(iVar4 + 6) = uVar5 & 0xff;
					}
					if ((pModel->mJointTree).mbIsBDL) {
						pJVar7 = pJVar9->mpDLObj;
						bVar6 = (bool)os::OSDisableInterrupts();
						gd::GDInitGDLObj(&J3DDisplayListObj::sGDLObj, pJVar7->mpData[0], pJVar7->mSize);
						gd::__GDCurrentDL = &J3DDisplayListObj::sGDLObj;
						pJVar11->patchTexNoAndTexCoordScale();
						os::OSRestoreInterrupts(bVar6);
						gd::__GDCurrentDL = nullptr;
					}
				}
			}
		}*/
	}
}

int dRes_info_c::loadResource() {
	char *pcVar1;
	ulong uVar2;
	undefined *puVar3;
	int iVar4;
	JKRArcFinder *pJVar5;
	J3DMaterialAnm *pJVar6;
	cBgD__Tree_t *pcVar7;
	mDoExt_transAnmBas *pAnm;
	void *pRes;
	void *pvVar8;
	ulong pWhich;
	ushort uVar10;
	int *piVar9;
	int iVar11;
	J3DMaterial *pJVar12;
	uint uVar13;

	if (this->mpRes != nullptr) {
		JUTAssertion::getSDevice()->showAssert("d_resorce.cpp", 0x25f, "mRes == 0");
		m_Do_printf::OSPanic("d_resorce.cpp", 0x25f, "Halt");
	}

	auto iVar10 = this->mpArchive->mpDataHeader->mFileEntryCount;
	this->mpRes = new void *[(int)iVar10];

	if (this->mpRes == NULL) {
		m_Do_printf::OSReport_Error("<%s.arc> setRes: res pointer buffer nothing !!\n", this);
		iVar10 = -1;
	} else {
		iVar4 = 0;
		if (0 < iVar10) {
			int cnt = iVar10;
			do {
				((void **)this->mpRes)[iVar4] = 0;
				iVar4 = iVar4 + 1;
				cnt--;
			} while (cnt);
		}
		pcVar1 = d_resorce::l_readResType$4166;
		uVar13 = 0;
		do {
			// loads every ressource in l_readResType in that order

			pJVar5 = this->mpArchive->getFirstResource(*(uint *)pcVar1);
			while (pJVar5->attribute != '\0') {
				pRes = (void *)JKRArchive::getGlbResource(*(uint *)pcVar1, pJVar5->name, this->mpArchive);
				printf("Got %p for %s\n", pRes, pJVar5->name);
				if (!pRes) {
					m_Do_printf::OSReport_Error("<%s> res == NULL !!\n", pJVar5->name);
				} else {
					uVar2 = *(uint *)pcVar1;
					// - 0x424d0000
					pWhich = uVar2 + 0xbdb30000;  // basically checks if signatures starts with BM
					if (pWhich == 0x4420) {		  // "BMD "
												  //
					} else if (pWhich == 0x444d) {
						//
					} else if (pWhich == 0x4443) {
						//
					} else if (pWhich == 0x4453) {
						//
					} else if (uVar2 == 0x42534d44) {
						//
					} else if (uVar2 == 0x42444c20) {
						//
					} else if (uVar2 == 0x42444c4c) {
						//
					} else if (uVar2 == 0x42444c4d) {
						//
					} else if (uVar2 == 0x42444c49) {
						//
					} else if (uVar2 == 0x42444c43) {
						//
					} else {
						pvVar8 = (void *)(uVar2 + 0xbdb40000);
						if (pvVar8 == (void *)0x5320) {
							//
						} else if ((uVar2 == 0x42434b53) || (uVar2 == 0x42434b20)) {
							//
						} else if ((((uVar2 == 0x42545020) || (uVar2 == 0x42544b20)) || (uVar2 == 0x42504b20)) ||
								   (((uVar2 == 0x42524b20 || (pvVar8 == (void *)0x4b20)) || (uVar2 == 0x42564120)))) {
							//
						} else if (pWhich == 0x5420) {
							//
						} else if (pWhich == 0x544d) {
							//
						} else if (uVar2 == 0x445a4220) {
							//
						}
					}
				}
				((void **)this->mpRes)[pJVar5->entryNum] = pRes;
				pJVar5->findNextFile();
			}
			delete pJVar5;
			uVar13 = uVar13 + 1;
			pcVar1 += 4;
		} while (uVar13 < (sizeof(d_resorce::l_readResType$4166) / 4));
	}
	return -1;
}

int dRes_info_c::setRes() {
	undefined4 uVar1;
	mDoDvdThd_mountArchive_c *pmVar2;
	JKRSolidHeap *pJVar3;
	ulong uVar4;
	JKRExpHeap *pJVar5;
	int iVar6;
	uint uVar7;
	int iVar8;

	if (this->mpArchive == nullptr) {
		pmVar2 = this->mpDvdThdCommand;
		if (pmVar2 == nullptr) {
			return -1;
		}
		if (pmVar2->mStatus == 0) {
			return 1;
		}
		this->mpArchive = pmVar2->mpResult;
		this->mpParentHeap = this->mpDvdThdCommand->mpHeap;
		pmVar2 = this->mpDvdThdCommand;
		if (pmVar2 != nullptr) {
			delete pmVar2;
		}
		this->mpDvdThdCommand = nullptr;
		if (this->mpArchive == nullptr) {
			m_Do_printf::OSReport_Error("<%s.arc> setRes: archive mount error !!\n", this);
			return -1;
		}
		if (this->mpParentHeap == nullptr) {
			this->mpDataHeap = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(0, 0);
			if (this->mpDataHeap == nullptr) {
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
					if (pJVar3 != nullptr) {
						if (pJVar3 < (JKRSolidHeap *)this->mpDataHeap) {
							this->mpRes = nullptr;
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
				if (pJVar3 == nullptr) {
					m_Do_ext::mDoExt_adjustSolidHeap((JKRSolidHeap *)this->mpDataHeap);
				} else {
					m_Do_ext::mDoExt_adjustSolidHeap((JKRSolidHeap *)this->mpDataHeap);
					this->mpRes = nullptr;
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
			if (this->mpDataHeap == nullptr) {
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

bool dRes_info_c::set(char *param_1, char *param_2, uchar param_3, JKRHeap *param_4) {
	bool bVar1;
	mDoDvdThd_mountArchive_c *pmVar2;
	char name[40];

	snprintf(name, 0x28, "%s%s.arc", param_2, param_1);
	pmVar2 = mDoDvdThd_mountArchive_c::create(name, param_3, param_4);
	this->mpDvdThdCommand = pmVar2;
	bVar1 = this->mpDvdThdCommand != nullptr;
	if (bVar1) {
		strncpy(this->mName, param_1, 0xe);
	}
	return bVar1;
}
